
#include "hardware.h"

#include "irq.h"

void sub_8015AD0(void);
void sub_8002CB8(int arg0);

enum
{
    FRAMES_PER_SECOND = 60,
    FRAMES_PER_MINUTE = 60 * FRAMES_PER_SECOND,
    FRAMES_PER_HOUR   = 60 * FRAMES_PER_MINUTE,
};

static struct BgCnt* GetBgCt(u16 bgid);
static void RefreshKeyStFromKeys(struct KeySt* keySt, short keys);
static void OnHBlankBoth(void);
static void RefreshOnHBlank(void);

static u8 sBgSyncBits;
static s8 sPalSyncFlag;

static unsigned sGameTime;

static u8 sUnk_03000014;
static u8 sUnk_03000015;

s8 EWRAM_DATA gUnk_020210E8[0x20] = {};
s8 EWRAM_DATA gUnk_02021108[0x600] = {};

u16 EWRAM_DATA gPal[0x200] = {};

u16 EWRAM_DATA gBg0Tm[0x400] = {};
u16 EWRAM_DATA gBg1Tm[0x400] = {};
u16 EWRAM_DATA gBg2Tm[0x400] = {};
u16 EWRAM_DATA gBg3Tm[0x400] = {};

void* EWRAM_DATA gBgMapVramTable[4] = {};

static Func EWRAM_DATA MainFunc = NULL;

int EWRAM_DATA pad_02023B1C = 0;

static struct KeySt EWRAM_DATA gKeyStObj = {};
struct KeySt* CONST_DATA gKeySt = &gKeyStObj;

extern struct DispIo gDispIo; // COMMON

extern Func gOnHBlankA; // COMMON
extern Func gOnHBlankB; // COMMON

unsigned GetGameTime(void)
{
    return sGameTime;
}

void SetGameTime(unsigned time)
{
    sGameTime = time;
}

void IncGameTime(void)
{
    sGameTime++;

    if (sGameTime >= 1000 * FRAMES_PER_HOUR)
    {
        sGameTime = 990 * FRAMES_PER_HOUR;
        return;
    }
}

s8 FormatTime(unsigned time, u16* hours, u16* minutes, u16* seconds)
{
    *seconds = (time / FRAMES_PER_SECOND) % 60;
    *minutes = (time / FRAMES_PER_MINUTE) % 60;
    *hours   = (time / FRAMES_PER_HOUR);

    return (time / 30) & 1; // clock `:` on/off boolean
}

inline void EnableBgSync(int bits)
{
    sBgSyncBits |= bits;
}

inline void EnableBgSyncById(int bgid)
{
    sBgSyncBits |= (1 << bgid);
}

inline void DisableBgSync(int bits)
{
    sBgSyncBits &= ~bits;
}

inline void EnablePalSync(void)
{
    sPalSyncFlag = TRUE;
}

inline void DisablePalSync(void)
{
    sPalSyncFlag = FALSE;
}

void ApplyPalette(const void* data, int startOffset, int size)
{
    if (size & 0x1F) // size is not a multiple of 32
        CpuCopy16(data, gPal + (startOffset >> 1), size);
    else
        CpuFastCopy(data, gPal + (startOffset >> 1), size);

    EnablePalSync();
}

void SyncDispIo(void)
{
    #define SET_REG(type, reg, src) *((type*) REG_ADDR_##reg) = *((type*) &(src))

    SET_REG(u16, DISPCNT,  gDispIo.dispCt);
    SET_REG(u16, DISPSTAT, gDispIo.dispStat);

    SET_REG(u16, BG0CNT,   gDispIo.bg0Ct);
    SET_REG(u16, BG1CNT,   gDispIo.bg1Ct);
    SET_REG(u16, BG2CNT,   gDispIo.bg2Ct);
    SET_REG(u16, BG3CNT,   gDispIo.bg3Ct);

    // set both HOFS and VOFS with a single 32-bit copy
    SET_REG(u32, BG0HOFS,  gDispIo.bgOff[0]);
    SET_REG(u32, BG1HOFS,  gDispIo.bgOff[1]);
    SET_REG(u32, BG2HOFS,  gDispIo.bgOff[2]);
    SET_REG(u32, BG3HOFS,  gDispIo.bgOff[3]);

    // set both WIN0H and WIN1H with a single 32-bit copy
    SET_REG(u32, WIN0H,    gDispIo.win0_right);
    // set both WIN0V and WIN1V with a single 32-bit copy
    SET_REG(u32, WIN0V,    gDispIo.win0_bottom);
    // set both WININ and WINOUT with a single 32-bit copy
    SET_REG(u32, WININ,    gDispIo.winCt);

    SET_REG(u16, MOSAIC,   gDispIo.mosaic);
    SET_REG(u16, BLDCNT,   gDispIo.blendCt);
    SET_REG(u16, BLDALPHA, gDispIo.blendCoeffA);
    SET_REG(u8,  BLDY,     gDispIo.blendY);

    // set both BG2PA and BG2PB with a single 32-bit copy
    SET_REG(u32, BG2PA,    gDispIo.bg2pa);
    // set both BG2PC and BG2PD with a single 32-bit copy
    SET_REG(u32, BG2PC,    gDispIo.bg2pc);
    SET_REG(u32, BG2X,     gDispIo.bg2x);
    SET_REG(u32, BG2Y,     gDispIo.bg2y);

    // set both BG3PA and BG3PB with a single 32-bit copy
    SET_REG(u32, BG3PA,    gDispIo.bg3pa);
    // set both BG3PC and BG3PD with a single 32-bit copy
    SET_REG(u32, BG3PC,    gDispIo.bg3pc);
    SET_REG(u32, BG3X,     gDispIo.bg3x);
    SET_REG(u32, BG3Y,     gDispIo.bg3y);

    #undef SET_REG
}

struct BgCnt* GetBgCt(u16 bgid)
{
    switch (bgid)
    {

    case 0: return &gDispIo.bg0Ct;
    case 1: return &gDispIo.bg1Ct;
    case 2: return &gDispIo.bg2Ct;
    case 3: return &gDispIo.bg3Ct;

    }
}

int GetBgChrOffset(int bg)
{
    struct BgCnt* bgCt = GetBgCt(bg);
    return bgCt->charBaseBlock * 0x4000;
}

int GetBgChrId(int bg, int offset)
{
    offset &= 0xFFFF;

    return (offset - GetBgChrOffset(bg)) / 0x20;
}

int GetBgTilemapOffset(int bg)
{
    struct BgCnt* bgCt = GetBgCt(bg);
    return bgCt->screenBaseBlock * 0x800;
}

void SetBgChrOffset(int bg, int offset)
{
    struct BgCnt* bgCt = GetBgCt(bg);
    bgCt->charBaseBlock = offset >> 14;
}

void SetBgTilemapOffset(int bg, int offset)
{
    struct BgCnt* bgCt = GetBgCt(bg);

    if ((offset & 0x7FF) != 0)  // must be aligned
        return;

    bgCt->screenBaseBlock = offset >> 11;
    gBgMapVramTable[bg] = (void*) (VRAM | offset);
}

void SetBgScreenSize(int bg, int size)
{
    struct BgCnt* bgCt = GetBgCt(bg);
    bgCt->screenSize = size;
}

void SetBgBpp(int bg, int bpp)
{
    struct BgCnt* bgCt = GetBgCt(bg);
    bgCt->colorMode = (bpp == 8) ? 1 : 0;
}

void SyncBgsAndPal(void)
{
    if (sBgSyncBits & BG0_SYNC_BIT)
        CpuFastCopy(gBg0Tm, gBgMapVramTable[0], sizeof gBg0Tm);

    if (sBgSyncBits & BG1_SYNC_BIT)
        CpuFastCopy(gBg1Tm, gBgMapVramTable[1], sizeof gBg1Tm);

    if (sBgSyncBits & BG2_SYNC_BIT)
        CpuFastCopy(gBg2Tm, gBgMapVramTable[2], sizeof gBg2Tm);

    if (sBgSyncBits & BG3_SYNC_BIT)
        CpuFastCopy(gBg3Tm, gBgMapVramTable[3], sizeof gBg3Tm);

    sBgSyncBits = 0;

    if (sPalSyncFlag == TRUE)
    {
        CpuFastCopy(gPal, (void*) PLTT, sizeof gPal);
        sPalSyncFlag = FALSE;
    }
}

void FillTm(u16* dest, int tileref)
{
    tileref = tileref + (tileref << 16);
    CpuFastFill(tileref, dest, sizeof(u16) * 0x400);
}

void RegisterDataMove(void const* src, void* dst, int size);

void SetBlankChr(int chr)
{
    RegisterDataMove(NULL, (void *)(VRAM + 0x20 * chr), 0x20);
}

void SetOnVBlank(IrqFunc func)
{
    if (func != NULL)
    {
        gDispIo.dispStat.vblankIrqEnable = TRUE;

        SetIrqFunc(IRQ_VBLANK, func);
        REG_IE |= INTR_FLAG_VBLANK;
    }
    else
    {
        gDispIo.dispStat.vblankIrqEnable = FALSE;
        REG_IE &= ~INTR_FLAG_VBLANK;
    }
}

void SetOnVMatch(IrqFunc func)
{
    if (func != NULL)
    {
        gDispIo.dispStat.vcountIrqEnable = TRUE;

        SetIrqFunc(IRQ_VCOUNT, func);
        REG_IE |= INTR_FLAG_VCOUNT;
    }
    else
    {
        gDispIo.dispStat.vcountIrqEnable = FALSE;
        REG_IE &= ~INTR_FLAG_VCOUNT;

        gDispIo.dispStat.vcountCompare = 0;
    }
}

void SetNextVCount(int vcount)
{
    u16 dispStat;

    dispStat = REG_DISPSTAT;
    dispStat = dispStat & 0xFF;
    dispStat = dispStat | (vcount << 8);

    REG_DISPSTAT = dispStat;
}

void SetVCount(int vcount)
{
    gDispIo.dispStat.vcountCompare = vcount;
}

void SetMainFunc(Func func)
{
    MainFunc = func;
}

void RunMainFunc(void)
{
    if (MainFunc)
        MainFunc();
}

void RefreshKeyStFromKeys(struct KeySt* keySt, short keys)
{
    keySt->previous = keySt->held;
    keySt->held = keys;

    // keys that are pressed now, but weren't pressed before
    keySt->pressed =
        (keySt->repeated = (keySt->held ^ keySt->previous) & keySt->held) &~ 0;

    if (keySt->pressed)
        keySt->last = keySt->held;

    keySt->ABLRPressed = 0;

    if (keySt->held == 0)
    {
        if (keySt->last && keySt->last == (keySt->previous & (L_BUTTON | R_BUTTON | B_BUTTON | A_BUTTON)))
            keySt->ABLRPressed = keySt->previous;
    }

    if (keySt->held && keySt->held == keySt->previous) // keys are being held
    {
        keySt->repeatTimer--;

        if (keySt->repeatTimer == 0)
        {
            keySt->repeated = keySt->held;
            keySt->repeatTimer = keySt->repeatInterval; // reset repeat timer
        }
    }
    else
    {
        // held key combination has changed. reset timer
        keySt->repeatTimer = keySt->repeatDelay;
    }

    keySt->pressed2 = (keySt->held ^ keySt->pressed2) & keySt->held;

    if (keys & (A_BUTTON | B_BUTTON | DPAD_ANY | R_BUTTON | L_BUTTON)) // any button other than start and select
        keySt->timeSinceStartSelect = 0;
    else if (keySt->timeSinceStartSelect < UINT16_MAX)
        keySt->timeSinceStartSelect++;
}

void RefreshKeySt(struct KeySt* keySt)
{
    RefreshKeyStFromKeys(keySt, (~REG_KEYINPUT) & KEYS_MASK);
}

void ClearKeySt(struct KeySt* keySt)
{
    keySt->pressed = 0;
    keySt->repeated = 0;
    keySt->held = 0;
}

void InitKeySt(struct KeySt* keySt)
{
    keySt->repeatDelay = 12;
    keySt->repeatInterval = 4;

    keySt->previous = 0;
    keySt->held = 0;
    keySt->pressed = 0;

    keySt->repeatTimer = 0;
    keySt->timeSinceStartSelect = 0;
}

void SetBgOffset(u16 bgid, u16 xOffset, u16 yOffset)
{
    switch (bgid)
    {

    case 0:
        gDispIo.bgOff[0].x = xOffset;
        gDispIo.bgOff[0].y = yOffset;
        break;

    case 1:
        gDispIo.bgOff[1].x = xOffset;
        gDispIo.bgOff[1].y = yOffset;
        break;

    case 2:
        gDispIo.bgOff[2].x = xOffset;
        gDispIo.bgOff[2].y = yOffset;
        break;

    case 3:
        gDispIo.bgOff[3].x = xOffset;
        gDispIo.bgOff[3].y = yOffset;
        break;

    }
}

void sub_8001AE4(void)
{
    sUnk_03000014 = sUnk_03000015 = 0;

    FillTm(gBg0Tm, 0);
    EnableBgSync(BG0_SYNC_BIT);
}

void sub_8001B18(u8 a, u8 b)
{
    sUnk_03000014 = a;
    sUnk_03000015 = b;
}

void sub_8001B4C(u16* a, u16* b)
{
    int i;

    for (i = 0x27F; i >= 0; i--)
        *a++ = *b++;
}

void sub_8001B8C(void* outTm, void const* inData, u8 base, u8 linebits)
{
    u8 const* it = (u8 const*) inData + 2;
    u8* out;

    u8 xSize = (*(u32 const*) inData);
    u8 ySize = (*(u32 const*) inData) >> 8;

    s8 ix, iy;

    for (iy = ySize; iy >= 0; iy--)
    {
        out = (u8*) outTm + (iy << linebits);

        for (ix = xSize; ix >= 0; ix--)
            *out++ = *it++ + base;
    }
}

void sub_8001C68(u16* outTm, short const* inData, int unused)
{
    int xSize = (inData[0]) & 0xFF;
    int ySize = (inData[0] >> 8) & 0xFF;

    int ix, iy;

    int acc = 0;

    inData = inData + 1;

    for (iy = 0; iy < ySize; ++iy)
    {
        u16* out = outTm + (iy << 5);

        for (ix = 0; ix < xSize; ++ix)
        {
            acc += *inData++;
            *out++ = acc;
        }
    }
}

void sub_8001D0C(void)
{
    int i;

    for (i = 31; i >= 0; i--)
        gUnk_020210E8[i] = 0;
}

void sub_8001D44(u16 const* inPal, int bank, int count, int unk)
{
    int iBank, iColor;

    int add = (unk < 0) ? 0x20 : 0;
    int color = bank * 0x30;

    for (iBank = 0; iBank < count; ++iBank)
    {
        gUnk_020210E8[bank + iBank] = unk;

        for (iColor = 0; iColor < 0x10; ++iColor)
        {
            gUnk_02021108[color++] = RGB_GET_RED(*inPal)   + add;
            gUnk_02021108[color++] = RGB_GET_GREEN(*inPal) + add;
            gUnk_02021108[color++] = RGB_GET_BLUE(*inPal)  + add;

            inPal++;
        }
    }
}

void sub_8001E68(int a, int b, int c, int d)
{
    int iBank;
    int iColor;
    int destOffset = a * 16;

    u16 const* src = gPal + destOffset;

    for (iBank = 0; iBank < b; ++iBank)
    {
        gUnk_020210E8[a + iBank] = d;

        for (iColor = 0; iColor < 16; ++iColor)
        {
            gUnk_02021108[destOffset++] = RGB_GET_RED(*src) + c;
            gUnk_02021108[destOffset++] = RGB_GET_GREEN(*src) + c;
            gUnk_02021108[destOffset++] = RGB_GET_BLUE(*src) + c;

            src++;
        }
    }
}

void sub_8001F88(int a, int b, int c)
{
    int i;

    for (i = a; i < a + b; i++)
        gUnk_020210E8[i] = c;
}

void sub_8001FD4(u8 a)
{
    int i, j;

    for (i = 0x1F; i >= 0; i--)
    {
        gUnk_020210E8[i] = a;

        for (j = 0; j < 0x10; j++)
        {
            gUnk_02021108[(i * 0x10 + j) * 3 + 0] = RGB_GET_RED(gPal[i * 0x10 + j]) + 0x20;
            gUnk_02021108[(i * 0x10 + j) * 3 + 1] = RGB_GET_GREEN(gPal[i * 0x10 + j]) + 0x20;
            gUnk_02021108[(i * 0x10 + j) * 3 + 2] = RGB_GET_BLUE(gPal[i * 0x10 + j]) + 0x20;
        }
    }
}

void sub_800210C(u8 a)
{
    int i, j;

    for (i = 0x1F; i >= 0; i--)
    {
        gUnk_020210E8[i] = a;

        for (j = 0; j < 0x10; j++)
        {
            gUnk_02021108[(i * 0x10 + j) * 3 + 0] = RGB_GET_RED(gPal[i * 0x10 + j]);
            gUnk_02021108[(i * 0x10 + j) * 3 + 1] = RGB_GET_GREEN(gPal[i * 0x10 + j]);
            gUnk_02021108[(i * 0x10 + j) * 3 + 2] = RGB_GET_BLUE(gPal[i * 0x10 + j]);
        }
    }
}

void sub_8002234(u8 a)
{
    int i, j;

    for (i = 0x1F; i >= 0; i--)
    {
        gUnk_020210E8[i] = a;

        for (j = 0; j < 0x10; j++)
        {
            gUnk_02021108[(i * 0x10 + j) * 3 + 0] = RGB_GET_RED(gPal[i * 0x10 + j]) + 0x20;
            gUnk_02021108[(i * 0x10 + j) * 3 + 1] = RGB_GET_GREEN(gPal[i * 0x10 + j]) + 0x20;
            gUnk_02021108[(i * 0x10 + j) * 3 + 2] = RGB_GET_BLUE(gPal[i * 0x10 + j]) + 0x20;
        }
    }
}

void sub_80019E8(u8 a)
{
    int i, j;

    for (i = 0x1F; i >= 0; i--)
    {
        gUnk_020210E8[i] = a;

        for (j = 0; j < 0x10; j++)
        {
            gUnk_02021108[(i * 0x10 + j) * 3 + 0] = RGB_GET_RED(gPal[i * 0x10 + j]) + 0x40;
            gUnk_02021108[(i * 0x10 + j) * 3 + 1] = RGB_GET_GREEN(gPal[i * 0x10 + j]) + 0x40;
            gUnk_02021108[(i * 0x10 + j) * 3 + 2] = RGB_GET_BLUE(gPal[i * 0x10 + j]) + 0x40;
        }
    }
}

void sub_80024A4(void)
{
    int i, j;
    short red, green, blue;

    for (i = 0x1F; i >= 0; i--)
    {
        if (gUnk_020210E8[i] == 0)
            continue;

        for (j = 15; j >= 0; j--)
        {
            int num = i * 0x10 + j;

            gUnk_02021108[num*3 + 0] += gUnk_020210E8[i];
            gUnk_02021108[num*3 + 1] += gUnk_020210E8[i];
            gUnk_02021108[num*3 + 2] += gUnk_020210E8[i];

            red = gUnk_02021108[num*3 + 0] - 32;

            if (red > 31)
                red = 31;

            if (red < 0)
                red = 0;

            green = gUnk_02021108[num*3 + 1] - 32;

            if (green > 31)
                green = 31;

            if (green < 0)
                green = 0;

            blue = gUnk_02021108[num*3 + 2] - 32;

            if (blue > 31)
                blue = 31;

            if (blue < 0)
                blue = 0;

            gPal[num] = (blue << 10) + (green << 5) + red;
        }
    }

    EnablePalSync();
}

void InitBgs(u16 const* config)
{
    u16 defaultConfig[] =
    {
        // tile offset  map offset  screen size
        0x0000,         0x6000,     0,          // BG 0
        0x0000,         0x6800,     0,          // BG 1
        0x0000,         0x7000,     0,          // BG 2
        0x8000,         0x7800,     0,          // BG 3
    };

    int i;

#if NONMATCHING

    if (config == NULL)
        config = defaultConfig;

#else
    asm("\n\
        ldr r0, [r7]\n\
        cmp r0, #0\n\
        bne _080026DE\n\
        add r0, r7, #4\n\
        str r0, [r7]\n\
    _080026DE:\n\
    ");
#endif

    *(u16*) &gDispIo.bg0Ct = 0;
    *(u16*) &gDispIo.bg1Ct = 0;
    *(u16*) &gDispIo.bg2Ct = 0;
    *(u16*) &gDispIo.bg3Ct = 0;

    gDispIo.dispCt.forcedBlank = 0;
    gDispIo.dispCt.mode = 0;

    gDispIo.dispCt.bg0_on = 1;
    gDispIo.dispCt.bg1_on = 1;
    gDispIo.dispCt.bg2_on = 1;
    gDispIo.dispCt.bg3_on = 1;
    gDispIo.dispCt.obj_on = 1;

    gDispIo.dispCt.win0_on = 0;
    gDispIo.dispCt.win1_on = 0;
    gDispIo.dispCt.objWin_on = 0;

    for (i = 0; i < 4; i++)
    {
        SetBgChrOffset(i, *config++);
        SetBgTilemapOffset(i, *config++);
        SetBgScreenSize(i, *config++);

        SetBgOffset(i, 0, 0);
        FillTm(GetBgTilemap(i), 0);
    }

    sub_8015AD0();

    EnableBgSync(BG0_SYNC_BIT + BG1_SYNC_BIT + BG2_SYNC_BIT + BG3_SYNC_BIT);

    sub_8002CB8(0);

    gPal[0] = 0;
    EnablePalSync();
}

u16* GetBgTilemap(int bg)
{
    static u16* lut[] =
    {
        gBg0Tm,
        gBg1Tm,
        gBg2Tm,
        gBg3Tm,
    };

    return lut[bg];
}

void SoftResetIfKeyCombo(void)
{
    if (gKeySt->held == (A_BUTTON + B_BUTTON + SELECT_BUTTON + START_BUTTON))
        SoftReset(0xFF);
}

void sub_800285C(int unk)
{
    u16 ie = REG_IE;

    REG_KEYCNT = unk - 0x4000;
    REG_IE &= ~(INTR_FLAG_SERIAL | INTR_FLAG_GAMEPAK);
    REG_IE |= INTR_FLAG_KEYPAD;
    REG_DISPCNT |= DISPCNT_FORCED_BLANK;

    SoundBiasReset();
    asm("swi 3");  // enter sleep mode
    SoundBiasSet();

    REG_IE = ie;
}

void OnHBlankBoth(void)
{
    if (gOnHBlankA)
        gOnHBlankA();

    if (gOnHBlankB)
        gOnHBlankB();
}

void RefreshOnHBlank(void)
{
    int st = 0;

    if (gOnHBlankA != NULL)
        st += 1;

    if (gOnHBlankB != NULL)
        st += 2;

    switch (st)
    {

    case 0:
        // no funcs

        gDispIo.dispStat.hblankIrqEnable = 0;
        REG_IE &= ~INTR_FLAG_HBLANK;

        break;

    case 1:
        // only func A

        gDispIo.dispStat.hblankIrqEnable = 1;

        SetIrqFunc(IRQ_HBLANK, gOnHBlankA);
        REG_IE |= INTR_FLAG_HBLANK;

        break;

    case 2:
        // only func B

        gDispIo.dispStat.hblankIrqEnable = 1;

        SetIrqFunc(IRQ_HBLANK, gOnHBlankB);
        REG_IE |= INTR_FLAG_HBLANK;

        break;

    case 3:
        // both funcs

        gDispIo.dispStat.hblankIrqEnable = 1;

        SetIrqFunc(IRQ_HBLANK, OnHBlankBoth);
        REG_IE |= INTR_FLAG_HBLANK;

        break;

    }
}

void SetOnHBlankA(Func func)
{
    gOnHBlankA = func;
    RefreshOnHBlank();
}

void SetOnHBlankB(Func func)
{
    gOnHBlankB = func;
    RefreshOnHBlank();
}
