#include "hardware.h"

#include "irq.h"
#include "move.h"
#include "oam.h"
#include "bm.h"

static struct BgCnt * GetBgCt(u16 bgid);
static void RefreshKeyStFromKeys(struct KeySt * keySt, short keys);
static void OnHBlankBoth(void);
static void RefreshOnHBlank(void);

static u8 sBgSyncBits;
static bool sPalSyncFlag;

static unsigned sGameTime;

static u8 sUnk_03000014;
static u8 sUnk_03000015;

u8 EWRAM_DATA gBuf[0x2000] = { 0 };

i8 EWRAM_DATA gUnk_020210E8[0x20] = { 0 };
i8 EWRAM_DATA gUnk_02021108[0x600] = { 0 };

u16 EWRAM_DATA gPal[0x200] = { 0 };

u16 EWRAM_DATA gBg0Tm[0x400] = { 0 };
u16 EWRAM_DATA gBg1Tm[0x400] = { 0 };
u16 EWRAM_DATA gBg2Tm[0x400] = { 0 };
u16 EWRAM_DATA gBg3Tm[0x400] = { 0 };

void * EWRAM_DATA gBgMapVramTable[4] = { 0 };

static Func EWRAM_DATA MainFunc = NULL;

int EWRAM_DATA pad_02023B1C = 0;

static struct KeySt EWRAM_DATA gKeyStObj = { 0 };
struct KeySt * CONST_DATA gKeySt = &gKeyStObj;

struct DispIo COMMON_DATA(gDispIo) gDispIo = { 0 };

Func COMMON_DATA(gOnHBlankA) gOnHBlankA = NULL;
Func COMMON_DATA(gOnHBlankB) gOnHBlankB = NULL;

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

bool FormatTime(unsigned time, u16 * hours, u16 * minutes, u16 * seconds)
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

void ApplyPaletteExt(void const * data, int startOffset, int size)
{
    if (size & 0x1F) // size is not a multiple of 32
        CpuCopy16(data, gPal + (startOffset >> 1), size);
    else
        CpuFastCopy(data, gPal + (startOffset >> 1), size);

    EnablePalSync();
}

void SyncDispIo(void)
{
    // TODO: rewrite the MODERN version of this function
    // this is a bit of a mess

    #if MODERN
    #  define SET_REG(type, reg, src) *((typeof((src)) volatile *) &REG_##reg) = (src)
    #else
    #  define SET_REG(type, reg, src) *((type*) &REG_##reg) = *((type*) &(src))
    #endif

    SET_REG(u16, DISPCNT,  gDispIo.disp_ct);
    SET_REG(u16, DISPSTAT, gDispIo.disp_stat);

    SET_REG(u16, BG0CNT,   gDispIo.bg0_ct);
    SET_REG(u16, BG1CNT,   gDispIo.bg1_ct);
    SET_REG(u16, BG2CNT,   gDispIo.bg2_ct);
    SET_REG(u16, BG3CNT,   gDispIo.bg3_ct);

    // set both HOFS and VOFS with a single 32-bit copy
    SET_REG(u32, BG0HOFS,  gDispIo.bg_off[0]);
    SET_REG(u32, BG1HOFS,  gDispIo.bg_off[1]);
    SET_REG(u32, BG2HOFS,  gDispIo.bg_off[2]);
    SET_REG(u32, BG3HOFS,  gDispIo.bg_off[3]);

#if MODERN
    REG_WIN0H = gDispIo.win0_right + (gDispIo.win0_left << 8);
    REG_WIN1H = gDispIo.win1_right + (gDispIo.win1_left << 8);
    REG_WIN0V = gDispIo.win0_bottom + (gDispIo.win0_top << 8);
    REG_WIN1V = gDispIo.win1_bottom + (gDispIo.win1_top << 8);
#else
    // set both WIN0H and WIN1H with a single 32-bit copy
    SET_REG(u32, WIN0H,    gDispIo.win0_right);
    // set both WIN0V and WIN1V with a single 32-bit copy
    SET_REG(u32, WIN0V,    gDispIo.win0_bottom);
#endif

    // set both WININ and WINOUT with a single 32-bit copy
    SET_REG(u32, WININ,    gDispIo.win_ct);

    SET_REG(u16, MOSAIC,   gDispIo.mosaic);
    SET_REG(u16, BLDCNT,   gDispIo.blend_ct);
#if MODERN
    REG_BLDALPHA = gDispIo.blend_coef_a + (gDispIo.blend_coef_b << 8);
#else
    SET_REG(u16, BLDALPHA, gDispIo.blend_coef_a);
#endif
    SET_REG(u8,  BLDY,     gDispIo.blend_y);

#if MODERN
    REG_BG2PA = gDispIo.bg2pa;
    REG_BG2PB = gDispIo.bg2pb;
    REG_BG2PC = gDispIo.bg2pc;
    REG_BG2PD = gDispIo.bg2pd;
#else
    // set both BG2PA and BG2PB with a single 32-bit copy
    SET_REG(u32, BG2PA,    gDispIo.bg2pa);
    // set both BG2PC and BG2PD with a single 32-bit copy
    SET_REG(u32, BG2PC,    gDispIo.bg2pc);
#endif

    SET_REG(u32, BG2X,     gDispIo.bg2x);
    SET_REG(u32, BG2Y,     gDispIo.bg2y);

#if MODERN
    REG_BG3PA = gDispIo.bg3pa;
    REG_BG3PB = gDispIo.bg3pb;
    REG_BG3PC = gDispIo.bg3pc;
    REG_BG3PD = gDispIo.bg3pd;
#else
    // set both BG3PA and BG3PB with a single 32-bit copy
    SET_REG(u32, BG3PA,    gDispIo.bg3pa);
    // set both BG3PC and BG3PD with a single 32-bit copy
    SET_REG(u32, BG3PC,    gDispIo.bg3pc);
#endif

    SET_REG(u32, BG3X,     gDispIo.bg3x);
    SET_REG(u32, BG3Y,     gDispIo.bg3y);

    #undef SET_REG
}

struct BgCnt * GetBgCt(u16 bgid)
{
    switch (bgid)
    {

    case 0: return &gDispIo.bg0_ct;
    case 1: return &gDispIo.bg1_ct;
    case 2: return &gDispIo.bg2_ct;
    case 3: return &gDispIo.bg3_ct;

    }

#if BUGFIX
    return NULL;
#endif
}

int GetBgChrOffset(int bg)
{
    struct BgCnt * bgCt = GetBgCt(bg);
    return bgCt->chr_block * 0x4000;
}

int GetBgChrId(int bg, int offset)
{
    offset &= 0xFFFF;

    return (offset - GetBgChrOffset(bg)) / 0x20;
}

int GetBgTilemapOffset(int bg)
{
    struct BgCnt * bgCt = GetBgCt(bg);
    return bgCt->tm_block * 0x800;
}

void SetBgChrOffset(int bg, int offset)
{
    struct BgCnt * bgCt = GetBgCt(bg);
    bgCt->chr_block = offset >> 14;
}

void SetBgTilemapOffset(int bg, int offset)
{
    struct BgCnt * bgCt = GetBgCt(bg);

    if ((offset & 0x7FF) != 0)  // must be aligned
        return;

    bgCt->tm_block = offset >> 11;
    gBgMapVramTable[bg] = (void *) (VRAM | offset);
}

void SetBgScreenSize(int bg, int size)
{
    struct BgCnt * bgCt = GetBgCt(bg);
    bgCt->size = size;
}

void SetBgBpp(int bg, int bpp)
{
    struct BgCnt * bgCt = GetBgCt(bg);
    bgCt->color_depth = (bpp == 8) ? BG_COLORDEPTH_8BPP : BG_COLORDEPTH_4BPP;
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
        CpuFastCopy(gPal, (void *) PLTT, sizeof gPal);
        sPalSyncFlag = FALSE;
    }
}

void TmFill(u16 * dest, int tileref)
{
    tileref = tileref + (tileref << 16);
    CpuFastFill(tileref, dest, sizeof gBg0Tm);
}

void SetBlankChr(int chr)
{
    RegisterDataFill(0, (void *)(VRAM + 0x20 * chr), 0x20);
}

void SetOnVBlank(IrqFunc func)
{
    if (func != NULL)
    {
        gDispIo.disp_stat.vblank_int_enable = TRUE;

        SetIrqFunc(INT_VBLANK, func);
        REG_IE |= INTR_FLAG_VBLANK;
    }
    else
    {
        gDispIo.disp_stat.vblank_int_enable = FALSE;
        REG_IE &= ~INTR_FLAG_VBLANK;
    }
}

void SetOnVMatch(IrqFunc func)
{
    if (func != NULL)
    {
        gDispIo.disp_stat.vcount_int_enable = TRUE;

        SetIrqFunc(INT_VCOUNT, func);
        REG_IE |= INTR_FLAG_VCOUNT;
    }
    else
    {
        gDispIo.disp_stat.vcount_int_enable = FALSE;
        REG_IE &= ~INTR_FLAG_VCOUNT;

        gDispIo.disp_stat.vcount_compare = 0;
    }
}

void SetNextVCount(int vcount)
{
    u16 disp_stat;

    disp_stat = REG_DISPSTAT;
    disp_stat = disp_stat & 0xFF;
    disp_stat = disp_stat | (vcount << 8);

    REG_DISPSTAT = disp_stat;
}

void SetVCount(int vcount)
{
    gDispIo.disp_stat.vcount_compare = vcount;
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

void RefreshKeyStFromKeys(struct KeySt * keySt, short keys)
{
    keySt->previous = keySt->held;
    keySt->held = keys;

    // keys that are pressed now, but weren't pressed before
    keySt->pressed =
        (keySt->repeated = (keySt->held ^ keySt->previous) & keySt->held) &~ 0;

    if (keySt->pressed)
        keySt->last = keySt->held;

    keySt->ablr_pressed = 0;

    if (keySt->held == 0)
    {
        if (keySt->last && keySt->last == (keySt->previous & (KEY_BUTTON_L | KEY_BUTTON_R | KEY_BUTTON_B | KEY_BUTTON_A)))
            keySt->ablr_pressed = keySt->previous;
    }

    if (keySt->held && keySt->held == keySt->previous) // keys are being held
    {
        keySt->repeat_clock--;

        if (keySt->repeat_clock == 0)
        {
            keySt->repeated = keySt->held;
            keySt->repeat_clock = keySt->repeat_interval; // reset repeat timer
        }
    }
    else
    {
        // held key combination has changed. reset timer
        keySt->repeat_clock = keySt->repeat_delay;
    }

    keySt->pressed2 = (keySt->held ^ keySt->pressed2) & keySt->held;

    if (keys & (KEY_BUTTON_A | KEY_BUTTON_B | KEY_DPAD_ANY | KEY_BUTTON_R | KEY_BUTTON_L)) // any button other than start and select
        keySt->time_since_start_select = 0;
    else if (keySt->time_since_start_select < UINT16_MAX)
        keySt->time_since_start_select++;
}

void RefreshKeySt(struct KeySt * keySt)
{
    RefreshKeyStFromKeys(keySt, (~REG_KEYINPUT) & KEY_ANY);
}

void ClearKeySt(struct KeySt * keySt)
{
    keySt->pressed = 0;
    keySt->repeated = 0;
    keySt->held = 0;
}

void InitKeySt(struct KeySt * keySt)
{
    keySt->repeat_delay = 12;
    keySt->repeat_interval = 4;

    keySt->previous = 0;
    keySt->held = 0;
    keySt->pressed = 0;

    keySt->repeat_clock = 0;
    keySt->time_since_start_select = 0;
}

void SetBgOffset(u16 bgid, u16 x_offset, u16 y_offset)
{
    switch (bgid)
    {

    case 0:
        gDispIo.bg_off[0].x = x_offset;
        gDispIo.bg_off[0].y = y_offset;
        break;

    case 1:
        gDispIo.bg_off[1].x = x_offset;
        gDispIo.bg_off[1].y = y_offset;
        break;

    case 2:
        gDispIo.bg_off[2].x = x_offset;
        gDispIo.bg_off[2].y = y_offset;
        break;

    case 3:
        gDispIo.bg_off[3].x = x_offset;
        gDispIo.bg_off[3].y = y_offset;
        break;

    }
}

void func_fe6_08001AE4(void)
{
    sUnk_03000014 = sUnk_03000015 = 0;

    TmFill(gBg0Tm, 0);
    EnableBgSync(BG0_SYNC_BIT);
}

void func_fe6_08001B18(u8 a, u8 b)
{
    sUnk_03000014 = a;
    sUnk_03000015 = b;
}

void func_fe6_08001B4C(u16 * a, u16 * b)
{
    int i;

    for (i = 0x27F; i >= 0; i--)
        *a++ = *b++;
}

void func_fe6_08001B8C(void * tm, void const * in_data, u8 base, u8 linebits)
{
    u8 const * it = (u8 const *) in_data + 2;
    u8 * out;

    u8 x_size = (*(u32 const *) in_data);
    u8 y_size = (*(u32 const *) in_data) >> 8;

    i8 ix, iy;

    for (iy = y_size; iy >= 0; iy--)
    {
        out = (u8 *) tm + (iy << linebits);

        for (ix = x_size; ix >= 0; ix--)
            *out++ = *it++ + base;
    }
}

void func_fe6_08001C68(u16 * tm, short const * in_data, int unused)
{
    int x_size = (in_data[0]) & 0xFF;
    int y_size = (in_data[0] >> 8) & 0xFF;

    int ix, iy;

    int acc = 0;

    in_data = in_data + 1;

    for (iy = 0; iy < y_size; ++iy)
    {
        u16 * out = tm + (iy << 5);

        for (ix = 0; ix < x_size; ++ix)
        {
            acc += *in_data++;
            *out++ = acc;
        }
    }
}

void func_fe6_08001D0C(void)
{
    int i;

    for (i = 31; i >= 0; i--)
        gUnk_020210E8[i] = 0;
}

void func_fe6_08001D44(u16 const * in_pal, int bank, int count, int unk)
{
    int ibank, icolor;

    int add = (unk < 0) ? 0x20 : 0;
    int color = bank * 0x30;

    for (ibank = 0; ibank < count; ++ibank)
    {
        gUnk_020210E8[bank + ibank] = unk;

        for (icolor = 0; icolor < 0x10; ++icolor)
        {
            gUnk_02021108[color++] = RGB_GET_RED(*in_pal)   + add;
            gUnk_02021108[color++] = RGB_GET_GREEN(*in_pal) + add;
            gUnk_02021108[color++] = RGB_GET_BLUE(*in_pal)  + add;

            in_pal++;
        }
    }
}

void func_fe6_08001E68(int a, int b, int c, int d)
{
    int ibank;
    int icolor;
    int dst_offset = a * 16;

    u16 const * src = gPal + dst_offset;

    for (ibank = 0; ibank < b; ++ibank)
    {
        gUnk_020210E8[a + ibank] = d;

        for (icolor = 0; icolor < 16; ++icolor)
        {
            gUnk_02021108[dst_offset++] = RGB_GET_RED(*src) + c;
            gUnk_02021108[dst_offset++] = RGB_GET_GREEN(*src) + c;
            gUnk_02021108[dst_offset++] = RGB_GET_BLUE(*src) + c;

            src++;
        }
    }
}

void func_fe6_08001F88(int a, int b, int c)
{
    int i;

    for (i = a; i < a + b; i++)
        gUnk_020210E8[i] = c;
}

void func_fe6_08001FD4(i8 a)
{
    int i, j;

    for (i = 0x1F; i >= 0; i--)
    {
        gUnk_020210E8[i] = a;

        for (j = 0; j < 0x10; j++)
        {
            gUnk_02021108[(i * 0x10 + j) * 3 + 0] = RGB_GET_RED(PAL_COLOR(i, j)) + 0x20;
            gUnk_02021108[(i * 0x10 + j) * 3 + 1] = RGB_GET_GREEN(PAL_COLOR(i, j)) + 0x20;
            gUnk_02021108[(i * 0x10 + j) * 3 + 2] = RGB_GET_BLUE(PAL_COLOR(i, j)) + 0x20;
        }
    }
}

void func_fe6_0800210C(i8 a)
{
    int i, j;

    for (i = 0x1F; i >= 0; i--)
    {
        gUnk_020210E8[i] = a;

        for (j = 0; j < 0x10; j++)
        {
            gUnk_02021108[(i * 0x10 + j) * 3 + 0] = RGB_GET_RED(PAL_COLOR(i, j));
            gUnk_02021108[(i * 0x10 + j) * 3 + 1] = RGB_GET_GREEN(PAL_COLOR(i, j));
            gUnk_02021108[(i * 0x10 + j) * 3 + 2] = RGB_GET_BLUE(PAL_COLOR(i, j));
        }
    }
}

void func_fe6_08002234(i8 a)
{
    int i, j;

    for (i = 0x1F; i >= 0; i--)
    {
        gUnk_020210E8[i] = a;

        for (j = 0; j < 0x10; j++)
        {
            gUnk_02021108[(i * 0x10 + j) * 3 + 0] = RGB_GET_RED(PAL_COLOR(i, j)) + 0x20;
            gUnk_02021108[(i * 0x10 + j) * 3 + 1] = RGB_GET_GREEN(PAL_COLOR(i, j)) + 0x20;
            gUnk_02021108[(i * 0x10 + j) * 3 + 2] = RGB_GET_BLUE(PAL_COLOR(i, j)) + 0x20;
        }
    }
}

void func_fe6_0800236C(i8 a)
{
    int i, j;

    for (i = 0x1F; i >= 0; i--)
    {
        gUnk_020210E8[i] = a;

        for (j = 0; j < 0x10; j++)
        {
            gUnk_02021108[(i * 0x10 + j) * 3 + 0] = RGB_GET_RED(PAL_COLOR(i, j)) + 0x40;
            gUnk_02021108[(i * 0x10 + j) * 3 + 1] = RGB_GET_GREEN(PAL_COLOR(i, j)) + 0x40;
            gUnk_02021108[(i * 0x10 + j) * 3 + 2] = RGB_GET_BLUE(PAL_COLOR(i, j)) + 0x40;
        }
    }
}

void func_fe6_080024A4(void)
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

void InitBgs(u16 const * config)
{
    SHOULD_BE_STATIC u16 SHOULD_BE_CONST default_config[] =
    {
        // tile offset  map offset  size id
        0x0000,         0x6000,     BG_SIZE_256x256, // BG 0
        0x0000,         0x6800,     BG_SIZE_256x256, // BG 1
        0x0000,         0x7000,     BG_SIZE_256x256, // BG 2
        0x8000,         0x7800,     BG_SIZE_256x256, // BG 3
    };

    int i;

    if (config == NULL)
        config = default_config;

#if MODERN
    gDispIo.bg0_ct = (struct BgCnt){ 0 };
    gDispIo.bg1_ct = (struct BgCnt){ 0 };
    gDispIo.bg2_ct = (struct BgCnt){ 0 };
    gDispIo.bg3_ct = (struct BgCnt){ 0 };
#else
    *(u16 *) &gDispIo.bg0_ct = 0;
    *(u16 *) &gDispIo.bg1_ct = 0;
    *(u16 *) &gDispIo.bg2_ct = 0;
    *(u16 *) &gDispIo.bg3_ct = 0;
#endif

    gDispIo.disp_ct.forced_blank = FALSE;
    gDispIo.disp_ct.mode = 0;

    SetDispEnable(1, 1, 1, 1, 1);
    SetWinEnable(0, 0, 0);

    for (i = 0; i < 4; i++)
    {
        SetBgChrOffset(i, *config++);
        SetBgTilemapOffset(i, *config++);
        SetBgScreenSize(i, *config++);

        SetBgOffset(i, 0, 0);
        TmFill(GetBgTilemap(i), 0);
    }

    InitBmBgLayers();

    EnableBgSync(BG0_SYNC_BIT + BG1_SYNC_BIT + BG2_SYNC_BIT + BG3_SYNC_BIT);

    InitOam(0);

    PAL_COLOR(0, 0) = 0;
    EnablePalSync();
}

u16 * GetBgTilemap(int bg)
{
    static u16 * SHOULD_BE_CONST lut[] =
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
    if (gKeySt->held == (KEY_BUTTON_A + KEY_BUTTON_B + KEY_BUTTON_SELECT + KEY_BUTTON_START))
        SoftReset(GBA_RESET_ALL);
}

void func_fe6_0800285C(int unk)
{
    u16 ie = REG_IE;

    REG_KEYCNT = unk - 0x4000;
    REG_IE &= ~(INTR_FLAG_SERIAL | INTR_FLAG_GAMEPAK);
    REG_IE |= INTR_FLAG_KEYPAD;
    REG_DISPCNT |= DISPCNT_FORCE_BLANK;

    SoundBiasReset();
    asm("swi 3"); // enter sleep mode
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

        gDispIo.disp_stat.hblank_int_enable = 0;
        REG_IE &= ~INTR_FLAG_HBLANK;

        break;

    case 1:
        // only func A

        gDispIo.disp_stat.hblank_int_enable = 1;

        SetIrqFunc(INT_HBLANK, gOnHBlankA);
        REG_IE |= INTR_FLAG_HBLANK;

        break;

    case 2:
        // only func B

        gDispIo.disp_stat.hblank_int_enable = 1;

        SetIrqFunc(INT_HBLANK, gOnHBlankB);
        REG_IE |= INTR_FLAG_HBLANK;

        break;

    case 3:
        // both funcs

        gDispIo.disp_stat.hblank_int_enable = 1;

        SetIrqFunc(INT_HBLANK, OnHBlankBoth);
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
