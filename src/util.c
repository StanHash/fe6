#include "util.h"

#include "hardware.h"
#include "move.h"
#include "armfunc.h"
#include "sound.h"
#include "text.h"
#include "bm.h"

#include "constants/videoalloc_global.h"
#include "constants/songs.h"

int Interpolate(int method, int lo, int hi, int x, int end)
{
    int denom, left, result;
    register int _deno asm("r0");

    if (end == 0)
        return hi;

    switch (method)
    {

    case INTERPOLATE_LINEAR:
        denom = (hi - lo) * x;
        result = lo + Div(denom, end);
        break;

    case INTERPOLATE_SQUARE:
        _deno = x * x;
        denom = _deno * (hi - lo);
        result = lo + Div(denom, end * end);
        break;

    case INTERPOLATE_CUBIC:
        denom = x * x * x * (hi - lo);
        result = lo + Div(denom,  end * end * end);
        break;

    case INTERPOLATE_POW4:
        denom = x * x * x * x * (hi - lo);
        result = lo + Div(denom, end * end * end * end);
        break;

    case INTERPOLATE_RSQUARE:
        left = end - x;
        denom = left * left * (hi - lo);
        result = lo + (hi - lo) - Div(denom, end * end);
        break;

    case INTERPOLATE_RCUBIC:
        left = end - x;
        denom = left * left * left * (hi - lo);
        result = lo + (hi - lo) - Div(denom, end * end * end);
        break;

    default:
        result = 0;

    }

    return result;
}

void func_fe6_08013BEC(void)
{
}

bool StringEquals(char const * strA, char const * strB)
{
    while (*strA | *strB)
    {
        if (*strA++ != *strB++)
            return FALSE;
    }

    return TRUE;
}

void StringCopy(char * dst, char const * src)
{
    while (*src)
    {
        *dst++ = *src++;
    }

    *dst = *src;
}

static void UnpackRaw(void const * src, void * dst)
{
    int size = GetDataSize(src) - 4;

    if (size % 0x20 != 0)
        CpuCopy16(src + 4, dst, size);
    else
        CpuFastCopy(src + 4, dst, size);
}

void Decompress_Unused_08013C74(void const * src, void * dst)
{
    LZ77UnCompWram(src, gBuf);
    CpuFastCopy(gBuf, dst, GetDataSize(src));
}

void Decompress(void const * src, void * dst)
{
    typedef void (* DecompressFunc)(void const *, void *);

    static DecompressFunc CONST_DATA func_lut[] =
    {
        UnpackRaw,      // 00, vram
        UnpackRaw,      // 00, wram
        LZ77UnCompVram, // 10, vram
        LZ77UnCompWram, // 10, wram
        HuffUnComp,     // 20, vram
        HuffUnComp,     // 20, wram
        RLUnCompVram,   // 30, vram
        RLUnCompWram,   // 30, wram
    };

    int is_wram;

    if ((((u32) dst) - VRAM) < VRAM_SIZE)
        is_wram = FALSE; // is vram
    else
        is_wram = TRUE;

    func_lut[is_wram + ((((u8 const *) src)[0] & 0xF0) >> 3)](src, dst);
}

int GetDataSize(void const * data)
{
    return *((u32 const *) data) >> 8;
}

struct Unk_08013CEC
{
    u8 * dst;
    int unk_04;
};

struct Unk * Unused_08013CEC(struct Unk_08013CEC * unk, int arg_1, int arg_2)
{
    unk->dst = (u8 *) arg_2;

    arg_1 = (arg_1 & 0xFFE0) >> 5;
    arg_2 = (arg_2 & 0xFFE0) >> 5;

    unk->unk_04 = arg_2 - arg_1;
}

int Unused_08013D04(struct Unk_08013CEC * unk, u8 const * src)
{
    int size, old;

    Decompress(src, unk->dst);

    size = GetDataSize(src);

    unk->dst += size;

    old = unk->unk_04;
    unk->unk_04 += size / 0x20;

    return old;
}

int Unused_08013D34(struct Unk_08013CEC * unk, int arg_1)
{
    int old;

    unk->dst += arg_1 << 5;

    old = unk->unk_04;
    unk->unk_04 += arg_1;

    return old;
}

void Register2dChrMove(u8 const * src, u8 * dst, int width, int height)
{
    int i, line_size = width * CHR_SIZE;

    if (height <= 0)
        return;

    for (i = height; i != 0; --i)
    {
        RegisterDataMove(src, dst, line_size);

        src += line_size;
        dst += CHR_SIZE * 0x20;
    }
}

void Copy2dChr(void const * src, u8 * dst, int width, int height)
{
    int i, line_size = width * CHR_SIZE;

    if (height <= 0)
        return;

    for (i = height; i != 0; --i)
    {
        CpuFastCopy(src, dst, line_size);

        src += line_size;
        dst += CHR_SIZE * 0x20;
    }
}

static void ApplyBitmapLine(u8 const * src, void * dst, int width);

void ApplyBitmap(u8 const * src, void * dst, int width, int height)
{
    int i, line_size;

    if (height <= 0)
        return;

    line_size = 8 * 8 * width;

    for (i = height; i != 0; --i)
    {
        ApplyBitmapLine(src, dst, width);

        src += line_size;
        dst += CHR_SIZE * width;
    }
}

static void ApplyBitmapTile(u8 const * src, u32 * dst, int width);

static void ApplyBitmapLine(u8 const * src, void * dst, int width)
{
    int i;

    if (width <= 0)
        return;

    for (i = width; i != 0; i--)
    {
        ApplyBitmapTile(src, dst, width);

        src += 8;
        dst += CHR_SIZE;
    }
}

static void ApplyBitmapTile(u8 const * src, u32 * dst, int width)
{
    int i;

    for (i = 0; i < 8; ++i)
    {
        u32 value = 0;

        value |= src[7];

        value <<= 4;
        value |= src[6];

        value <<= 4;
        value |= src[5];

        value <<= 4;
        value |= src[4];

        value <<= 4;
        value |= src[3];

        value <<= 4;
        value |= src[2];

        value <<= 4;
        value |= src[1];

        value <<= 4;
        value |= src[0];

        *dst++ = value;
        src += width * 8;
    }
}

void PutAppliedBitmap(u16 * tm, int tileref, int width, int height)
{
    int ix, iy;

    for (iy = 0; iy < height; ++iy)
        for (ix = 0; ix < width; ++ix)
            tm[TM_OFFSET(ix, iy)] = tileref++;
}

void PutDigits(u16 * tm, u8 const * src, int tileref, int len)
{
    int i;

    for (i = 0; i < len; ++i)
        tm[-i] = 0;

    while (*src != ' ')
    {
        *tm-- = tileref + *src - '0';
        src--;
    }
}

struct Unk_08013EBC
{
    /* 00 */ u8 pad_00[0x4C - 0x00];
    /* 4C */ u16 unk_4C;
};

void func_fe6_08013EBC(struct Unk_08013EBC * unk, int value)
{
    unk->unk_4C = value;
}

void func_fe6_08013EC4(struct Unk_08013EBC * unk)
{
    unk->unk_4C++;
    unk->unk_4C &= 0x7FFF;
}

void func_fe6_08013ED8(struct Unk_08013EBC * unk)
{
    unk->unk_4C--;
}

void func_fe6_08013EE4(i16 * array)
{
    int i;

    for (i = DISPLAY_HEIGHT-1; i >= 0; --i)
    {
        *array++ = DISPLAY_WIDTH;
        *array++ = -1;
    }
}

void func_fe6_08013F04(i16 * array, int x_a, int y_a, int x_b, int y_b)
{
    int q16_slope, q16_x, i;

    if (y_a > y_b)
    {
        int tmp;

        tmp = x_b;
        x_b = x_a;
        x_a = tmp;

        tmp = y_b;
        y_b = y_a;
        y_a = tmp;
    }

    q16_slope = ((x_b - x_a) << 16) / (y_b - y_a);
    q16_x = x_a << 16;

    if (y_b > DISPLAY_HEIGHT)
        y_b = DISPLAY_HEIGHT;

    if (y_a < 0)
    {
        q16_x += -y_a * q16_slope;
        y_a = 0;
    }

    for (i = y_a; i < y_b; ++i)
    {
        int x = q16_x >> 16;

        if (array[i*2 + 0] > x)
            array[i*2 + 0] = x;

        if (array[i*2 + 1] < x)
            array[i*2 + 1] = x;

        q16_x += q16_slope;
    }
}

struct Unk
{
    short a, b;
};

struct Unk * func_fe6_08013F7C(int arg_0)
{
    #define BUF ((struct Unk *) gBuf)

    int r2;
    int sb;
    int sp_00;

    sp_00 = arg_0;

    if (sp_00 > 80)
        sp_00 = 80;

    r2 = arg_0;

    for (sb = 0; r2 >= sb; ++sb)
    {
        u16 sp_18, r4, r3, r1;

        sp_18 = sp_00 + sb;

        if (sp_18 < DISPLAY_HEIGHT)
            BUF[sp_00 + sb].b = r2;

        r4 = sp_00 - sb;

        if (r4 < DISPLAY_HEIGHT)
            BUF[sp_00 - sb].b = r2;

        r3 = sp_00 + r2;

        if (r3 < DISPLAY_HEIGHT)
            BUF[sp_00 + r2].b = sb;

        r1 = sp_00 - r2;

        if (r1 < DISPLAY_HEIGHT)
            BUF[sp_00 - r2].b = sb;

        if (sp_18 < DISPLAY_HEIGHT)
            BUF[sp_00 + sb].a = -r2;

        if (r4 < DISPLAY_HEIGHT)
            BUF[sp_00 - sb].a = -r2;

        if (r3 < DISPLAY_HEIGHT)
            BUF[sp_00 + r2].a = -sb;

        if (r1 < DISPLAY_HEIGHT)
            BUF[sp_00 - r2].a = -sb;

        arg_0 = arg_0 - (sb*2 - 1);

        if (arg_0 < 0)
        {
            arg_0 = arg_0 + (r2 - 1)*2;
            r2--;
        }
    }

    return BUF;

    #undef BUF
}

void DarkenPals(int reduction)
{
    u16 * buf = (u16 *) gBuf;

    int i;

    for (i = 0; i < 0x200; ++i)
    {
        int color = gPal[i];

        if ((color & 0x001F) >= (reduction))
            color -= (reduction);
        else
            color = color & 0xFFE0;

        if ((color & 0x03E0) >= (reduction << 5))
            color -= (reduction << 5);
        else
            color = color & 0xFC1F;

        if ((color & 0x7C00) >= (reduction << 10))
            color -= (reduction << 10);
        else
            color = color & 0x03FF;

        buf[i] = color;
    }

    DisablePalSync();
    RegisterDataMove(buf, (u16 *) PLTT, sizeof(gPal));
}

void func_fe6_0801412C(void)
{
}

void func_fe6_08014130(char const * arg_0)
{
    SHOULD_BE_STATIC char SHOULD_BE_CONST unk[] = "@@LWFOVDBK@@";
    func_fe6_08014130(unk);
}

static void SpacialSeTest_OnInit(struct GenericProc * proc)
{
    proc->unk64 = 0;
    proc->unk66 = 90;
}

static void SpacialSeTest_OnLoop(struct GenericProc * proc)
{
    int location = 0;

    if (gKeySt->pressed & KEY_BUTTON_A)
        proc->unk66++;

    if (((proc->unk64++) & 0x0F) == 0)
    {
        if (gKeySt->held & KEY_DPAD_LEFT)
            location = -proc->unk66;

        if (gKeySt->held & KEY_DPAD_RIGHT)
            location = +proc->unk66;

        PlaySeSpacial(SONG_9A, location);
    }
}

struct ProcScr CONST_DATA ProcScr_SpacialSeTest[] =
{
    PROC_CALL(LockGame),

    PROC_CALL(SpacialSeTest_OnInit),
    PROC_REPEAT(SpacialSeTest_OnLoop),
};

void StartSpacialSeTest(void)
{
    SpawnProc(ProcScr_SpacialSeTest, PROC_TREE_3);
}

void func_fe6_080141DC(void)
{
}

void StartPalFadeToBlack(int palid, int duration, ProcPtr parent)
{
    StartPalFade(Pal_AllBlack, palid, duration, parent);
}

void StartPalFadeToWhite(int palid, int duration, ProcPtr parent)
{
    StartPalFade(Pal_AllWhite, palid, duration, parent);
}

static struct PalFadeSt EWRAM_DATA sPalFadeSt[0x20] = {};

struct PalFadeProc
{
    /* 00 */ PROC_HEADER;
    /* 2C */ struct PalFadeSt * st;
};

static void PalFade_OnLoop(struct PalFadeProc * proc);

struct ProcScr CONST_DATA ProcScr_PalFade[] =
{
    PROC_MARK(PROC_MARK_10),
    PROC_REPEAT(PalFade_OnLoop),

    PROC_END,
};

struct PalFadeSt * StartPalFade(u16 const * colors, int pal, int duration, ProcPtr parent)
{
    struct PalFadeSt * st = sPalFadeSt + pal;

    struct PalFadeProc * proc = SpawnProc(ProcScr_PalFade, parent);

    CpuCopy16(gPal + pal * 0x10, st->from_colors, sizeof(st->from_colors));

    st->pal = gPal + pal * 0x10;
    st->to_colors = colors;
    st->clock = 0;
    st->clock_end = duration;
    st->clock_stop = duration + 1;

    proc->st = st;

    return st;
}

void EndPalFade(void)
{
    Proc_EndEach(ProcScr_PalFade);
}

void SetPalFadeStop(struct PalFadeSt * st, int val)
{
    st->clock_stop = val;
}

static void PalFade_OnLoop(struct PalFadeProc * proc)
{
    int i;

    u16 const * from_colors = proc->st->from_colors;
    u16 const * to_colors = proc->st->to_colors;

    u16 * pal = proc->st->pal;

    if (proc->st->clock == proc->st->clock_stop || proc->st->clock > proc->st->clock_end)
    {
        Proc_End(proc);
        return;
    }

    for (i = 0; i < 0x10; ++i)
    {
        int red_a   = from_colors[i] & 0x001F;
        int green_a = from_colors[i] & 0x03E0;
        int blue_a  = from_colors[i] & 0x7C00;

        int red_b   = to_colors[i] & 0x001F;
        int green_b = to_colors[i] & 0x03E0;
        int blue_b  = to_colors[i] & 0x7C00;

        int red   = Interpolate(INTERPOLATE_LINEAR, red_a,   red_b,   proc->st->clock, proc->st->clock_end);
        int green = Interpolate(INTERPOLATE_LINEAR, green_a, green_b, proc->st->clock, proc->st->clock_end);
        int blue  = Interpolate(INTERPOLATE_LINEAR, blue_a,  blue_b,  proc->st->clock, proc->st->clock_end);

        pal[i] = (blue & 0x7C00) | (green & 0x03E0) | (red & 0x001F);
    }

    EnablePalSync();
    proc->st->clock++;
}

void SetBlackPal(int palid)
{
    CpuCopy16(Pal_AllBlack, gPal + palid * 0x10, 0x20);
}

void SetWhitePal(int palid)
{
    CpuCopy16(Pal_AllWhite, gPal + palid * 0x10, 0x20);
}

void SetAllBlackPals(void)
{
    int i;

    for (i = 0; i < 0x20; ++i)
        SetBlackPal(i);
}

void SetAllWhitePals(void)
{
    int i;

    for (i = 0; i < 0x20; ++i)
        SetBlackPal(i);
}

static void FadeToBlack_OnInit(struct GenericProc * proc)
{
    gDispIo.win_ct.win0_enable_blend = 1;
    gDispIo.win_ct.win1_enable_blend = 1;
    gDispIo.win_ct.wobj_enable_blend = 1;
    gDispIo.win_ct.wout_enable_blend = 1;

    SetBlendDarken(0);

    SetBlendTargetA(1, 1, 1, 1, 1);
    SetBlendBackdropA(1);

    proc->unk64 = 0x10;
    proc->unk66 = 0;
}

static void FadeToCommon_OnLoop(struct GenericProc * proc)
{
    if (gDispIo.blend_y == 0x10)
    {
        Proc_End(proc);
        return;
    }

    proc->unk66 += proc->unk64;

    if (proc->unk66 >= 0x100)
        proc->unk66 = 0x100;

    gDispIo.blend_y = proc->unk66 >> 4;
}

static void FadeFromBlack_OnInit(struct GenericProc * proc)
{
    gDispIo.win_ct.win0_enable_blend = 1;
    gDispIo.win_ct.win1_enable_blend = 1;
    gDispIo.win_ct.wobj_enable_blend = 1;
    gDispIo.win_ct.wout_enable_blend = 1;

    SetBlendDarken(0x10);

    SetBlendTargetA(1, 1, 1, 1, 1);
    SetBlendTargetB(1, 1, 1, 1, 1);
    SetBlendBackdropA(1);

    proc->unk64 = 0x10;
    proc->unk66 = 0x100;
}

static void FadeFromCommon_OnLoop(struct GenericProc * proc)
{
    if (gDispIo.blend_y == 0)
    {
        Proc_End(proc);
        return;
    }

    proc->unk66 -= proc->unk64;

    if (proc->unk66 <= 0)
        proc->unk66 = 0;

    gDispIo.blend_y = proc->unk66 >> 4;
}

static void FadeToWhite_OnInit(struct GenericProc * proc)
{
    FadeToBlack_OnInit(proc);
    SetBlendBrighten(0);
}

static void FadeFromWhite_OnInit(struct GenericProc * proc)
{
    FadeFromBlack_OnInit(proc);
    SetBlendBrighten(0x10);
}

struct ProcScr CONST_DATA ProcScr_FadeToBlack[] =
{
    PROC_CALL(FadeToBlack_OnInit),
    PROC_SLEEP(0),

    PROC_REPEAT(FadeToCommon_OnLoop),
    PROC_BLOCK,
};

struct ProcScr CONST_DATA ProcScr_FadeFromBlack[] =
{
    PROC_CALL(FadeFromBlack_OnInit),
    PROC_SLEEP(0),

    PROC_REPEAT(FadeFromCommon_OnLoop),
    PROC_BLOCK,
};

struct ProcScr CONST_DATA ProcScr_FadeToWhite[] =
{
    PROC_CALL(FadeToWhite_OnInit),
    PROC_SLEEP(0),

    PROC_REPEAT(FadeToCommon_OnLoop),
    PROC_BLOCK,
};

struct ProcScr CONST_DATA ProcScr_FadeFromWhite[] =
{
    PROC_CALL(FadeFromWhite_OnInit),
    PROC_SLEEP(0),

    PROC_REPEAT(FadeFromCommon_OnLoop),
    PROC_BLOCK,
};

bool FadeExists(void)
{
    if (!FindProc(ProcScr_FadeFromBlack) &&
        !FindProc(ProcScr_FadeToBlack) &&
        !FindProc(ProcScr_FadeFromWhite) &&
        !FindProc(ProcScr_FadeToWhite))
    {
        return FALSE;
    }

    return TRUE;
}

void StartFadeToBlack(int q4_speed)
{
    struct GenericProc * proc = SpawnProc(ProcScr_FadeToBlack, PROC_TREE_3);
    proc->unk64 = q4_speed;
}

void StartFadeFromBlack(int q4_speed)
{
    struct GenericProc * proc = SpawnProc(ProcScr_FadeFromBlack, PROC_TREE_3);
    proc->unk64 = q4_speed;
}

void StartLockingFadeToBlack(int q4_speed, ProcPtr parent)
{
    struct GenericProc * proc = SpawnProcLocking(ProcScr_FadeToBlack, parent);
    proc->unk64 = q4_speed;
}

void StartLockingFadeFromBlack(int q4_speed, ProcPtr parent)
{
    struct GenericProc * proc = SpawnProcLocking(ProcScr_FadeFromBlack, parent);
    proc->unk64 = q4_speed;
}

void StartLockingFadeToWhite(int q4_speed, ProcPtr parent)
{
    struct GenericProc * proc = SpawnProcLocking(ProcScr_FadeToWhite, parent);
    proc->unk64 = q4_speed;
}

void StartLockingFadeFromWhite(int q4_speed, ProcPtr parent)
{
    struct GenericProc * proc = SpawnProcLocking(ProcScr_FadeFromWhite, parent);
    proc->unk64 = q4_speed;
}

void StartMidFadeToBlack(void)
{
    StartFadeToBlack(0x10);
}

void StartSlowFadeToBlack(void)
{
    StartFadeToBlack(0x04);
}

void StartFastFadeToBlack(void)
{
    StartFadeToBlack(0x40);
}

void StartMidFadeFromBlack(void)
{
    StartFadeFromBlack(0x10);
}

void StartSlowFadeFromBlack(void)
{
    StartFadeFromBlack(0x04);
}

void StartFastFadeFromBlack(void)
{
    StartFadeFromBlack(0x40);
}

void StartMidLockingFadeToBlack(ProcPtr parent)
{
    StartLockingFadeToBlack(0x10, parent);
}

void StartSlowLockingFadeToBlack(ProcPtr parent)
{
    StartLockingFadeToBlack(0x04, parent);
}

void StartFastLockingFadeToBlack(ProcPtr parent)
{
    StartLockingFadeToBlack(0x40, parent);
}

void StartMidLockingFadeFromBlack(ProcPtr parent)
{
    StartLockingFadeFromBlack(0x10, parent);
}

void StartSlowLockingFadeFromBlack(ProcPtr parent)
{
    StartLockingFadeFromBlack(0x04, parent);
}

void StartFastLockingFadeFromBlack(ProcPtr parent)
{
    StartLockingFadeFromBlack(0x40, parent);
}

void StartSlowLockingFadeToWhite(ProcPtr parent)
{
    StartLockingFadeToWhite(0x04, parent);
}

void StartSlowLockingFadeFromWhite(ProcPtr parent)
{
    StartLockingFadeFromWhite(0x04, parent);
}

void func_fe6_08014778(ProcPtr parent)
{
    StartFadeCore(1, 0x04, parent, func_fe6_08014AF8);
}

void func_fe6_08014790(ProcPtr parent)
{
    StartFadeCore(1, 0x08, parent, func_fe6_08014AF8);
}

void func_fe6_080147A8(ProcPtr parent)
{
    StartFadeCore(1, 0x10, parent, func_fe6_08014AF8);
}

void func_fe6_080147C0(ProcPtr parent)
{
    StartFadeCore(1, 0x20, parent, func_fe6_08014AF8);
}

void func_fe6_080147D8(ProcPtr parent)
{
    StartFadeCore(1, 0x40, parent, func_fe6_08014AF8);
}

void func_fe6_080147F0(ProcPtr parent)
{
    StartFadeCore(0, 0x08, parent, NULL);
}

void func_fe6_08014804(ProcPtr parent)
{
    StartFadeCore(0, 0x10, parent, NULL);
}

void func_fe6_08014818(ProcPtr parent)
{
    StartFadeCore(0, 0x20, parent, NULL);
}

void func_fe6_0801482C(ProcPtr parent)
{
    StartFadeCore(0, 0x40, parent, NULL);
}

void func_fe6_08014840(ProcPtr parent)
{
    StartFadeCore(3, 0x04, parent, func_fe6_08014AF8);
}

void func_fe6_08014858(ProcPtr parent)
{
    StartFadeCore(3, 0x08, parent, func_fe6_08014AF8);
}

void func_fe6_08014870(ProcPtr parent)
{
    StartFadeCore(3, 0x10, parent, func_fe6_08014AF8);
}

void func_fe6_08014888(ProcPtr parent)
{
    StartFadeCore(3, 0x20, parent, func_fe6_08014AF8);
}

void func_fe6_080148A0(ProcPtr parent)
{
    StartFadeCore(3, 0x40, parent, func_fe6_08014AF8);
}

void func_fe6_080148B8(ProcPtr parent)
{
    StartFadeCore(2, 0x04, parent, NULL);
}

void func_fe6_080148CC(ProcPtr parent)
{
    StartFadeCore(2, 0x08, parent, NULL);
}

void func_fe6_080148E0(ProcPtr parent)
{
    StartFadeCore(2, 0x08, parent, NULL);
    func_fe6_08014AB8();
}

void func_fe6_080148F8(ProcPtr parent)
{
    StartFadeCore(2, 0x10, parent, NULL);
}

void func_fe6_0801490C(ProcPtr parent)
{
    StartFadeCore(2, 0x20, parent, NULL);
}

void func_fe6_08014920(ProcPtr parent)
{
    StartFadeCore(2, 0x40, parent, NULL);
}

void func_fe6_08014934(ProcPtr parent)
{
    StartFadeCore(6, 0x10, parent, NULL);
}

void func_fe6_08014948(ProcPtr parent)
{
    StartFadeCore(7, 0x10, parent, NULL);
}

void func_fe6_0801495C(ProcPtr parent)
{
    StartFadeCore(6, 0x08, parent, NULL);
}

void func_fe6_08014970(ProcPtr parent)
{
    StartFadeCore(4, 0x04, parent, NULL);
}

void func_fe6_08014984(ProcPtr parent)
{
    StartFadeCore(4, 0x08, parent, NULL);
}

void func_fe6_08014998(ProcPtr parent)
{
    StartFadeCore(7, 0x08, parent, func_fe6_08014B68);
}

void WhileFadeExists(ProcPtr proc)
{
    if (!FadeExists())
        Proc_Break(proc);
}

void func_fe6_080149CC(ProcPtr parent, Func func)
{
    StartFadeCore(3, 0x40, parent, func);
}

struct FadeCoreProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x4C);
    /* 4C */ Func on_end;
    /* 50 */ STRUCT_PAD(0x50, 0x54);
    /* 54 */ int unk_54;
    /* 58 */ int unk_58;
    /* 5C */ int unk_5C;
};

void func_fe6_08014A38(struct FadeCoreProc * proc);
i8 func_fe6_08014A68(struct FadeCoreProc * proc);
void func_fe6_08014A44(struct FadeCoreProc * proc);

struct ProcScr CONST_DATA ProcScr_FadeCore[] =
{
    PROC_MARK(PROC_MARK_10),

    PROC_CALL(func_fe6_08014A38),
    PROC_SLEEP(0),

    PROC_CALL(func_fe6_08014A68),
    PROC_REPEAT(func_fe6_08014A44),

    PROC_END,
};

void StartFadeCore(int kind, int speed, ProcPtr parent, Func end_callback)
{
    struct FadeKindEnt
    {
        ProcPtr (* spawn_proc)(struct ProcScr const * scr, ProcPtr parent);
        void (* setup_color_fade)(fi8 component_step);
        int unit;
    };

    static struct FadeKindEnt const table[] =
    {
        { SpawnProc,        ColorFadeSetupFromBlack,        +1 }, // from black
        { SpawnProc,        ColorFadeSetupFromColorToBlack, -1 }, // to black
        { SpawnProcLocking, ColorFadeSetupFromBlack,        +1 }, // from black locking
        { SpawnProcLocking, ColorFadeSetupFromColorToBlack, -1 }, // to black locking
        { SpawnProc,        ColorFadeSetupFromWhite,        -1 }, // from white
        { SpawnProc,        ColorFadeSetupFromColorToWhite, +1 }, // to white
        { SpawnProcLocking, ColorFadeSetupFromWhite,        -1 }, // from white locking
        { SpawnProcLocking, ColorFadeSetupFromColorToWhite, +1 }, // to white locking
    };

    ProcPtr (* spawn_proc)(struct ProcScr const * scr, ProcPtr parent);
    void (* setup_color_fade)(int component_step);

    struct FadeCoreProc * proc;
    int component_step;

    spawn_proc = table[kind].spawn_proc;
    proc = spawn_proc(ProcScr_FadeCore, parent);

    proc->unk_54 = speed;
    proc->on_end = end_callback;

    component_step = proc->unk_54 >> 4;

    if (component_step == 0)
        component_step = 1;

    // need to cast because parameter types don't match (int vs. i8)
    setup_color_fade = (void *) table[kind].setup_color_fade;
    setup_color_fade(component_step * table[kind].unit);
}

void func_fe6_08014A28(void)
{
    Proc_EndEach(ProcScr_FadeCore);
}

void func_fe6_08014A38(struct FadeCoreProc * proc)
{
    proc->unk_58 = 0;
    proc->unk_5C = 0;
    proc->on_end = NULL;
}

void func_fe6_08014A44(struct FadeCoreProc * proc)
{
    if (!func_fe6_08014A68(proc))
    {
        if (proc->on_end)
            proc->on_end();

        Proc_Break(proc);
    }
}

bool func_fe6_08014A68(struct FadeCoreProc * proc)
{
    proc->unk_58 += proc->unk_54;
    proc->unk_5C += proc->unk_54;

    if (proc->unk_58 < 0x10)
    { 
        if (proc->unk_5C != proc->unk_54)
            return TRUE;
    }
    else
    {
        proc->unk_58 = proc->unk_58 - 0x10;
    }

    if (proc->unk_5C >= 0x200)
        return FALSE;

    ColorFadeTick();
    SetBackdropColor(0);

    return TRUE;
}

void func_fe6_08014AB8(void)
{
    func_fe6_08001F88(0x10, 0x10, 0);
    func_fe6_08014ADC();
}

void func_fe6_08014ACC(int a, int b)
{
    func_fe6_08001F88(a, b, 0);
    func_fe6_08014ADC();
}

void func_fe6_08014ADC(void)
{
    struct FadeCoreProc * proc = FindProc(ProcScr_FadeCore);

    if (proc)
        proc->on_end = NULL;
}

void func_fe6_08014AF8(void)
{
    SetBlendDarken(0x10);
    SetBlendTargetA(1, 1, 1, 1, 1);
    SetBlendBackdropA(1);
    SetBackdropColor(0);
    SetDispEnable(0, 0, 0, 0, 0);
}

void func_fe6_08014B68(void)
{
    SetBlendBrighten(0x10);

    SetBlendTargetA(1, 1, 1, 1, 1);
    SetBlendBackdropA(1);
}

static void TemporaryLock_OnLoop(struct GenericProc * proc);

struct ProcScr CONST_DATA ProcScr_TemporaryLock[] =
{
    PROC_SLEEP(0),

    PROC_REPEAT(TemporaryLock_OnLoop),
    PROC_END,
};

void StartTemporaryLock(ProcPtr proc, int duration)
{
    struct GenericProc * gproc;

    gproc = SpawnProcLocking(ProcScr_TemporaryLock, proc);
    gproc->unk58 = duration;
}

static void TemporaryLock_OnLoop(struct GenericProc * proc)
{
    if (proc->unk58 == 0)
    {
        Proc_Break(proc);
        return;
    }

    proc->unk58--;
}

static char CONST_DATA sStrZero[] = JTEXT("０");
static char CONST_DATA sStrDash[] = JTEXT("ー");

int NumberToString(int number, char * buf)
{
    int numOff, numStart;

    numOff = 0;

    if (number == 0)
    {
        *buf++ = sStrZero[0];
        *buf++ = sStrZero[1];
        *buf++ = '\0';

        return 1;
    }

    if (number < 0)
    {
        buf[0] = sStrDash[0];
        buf[1] = sStrDash[1];

        number = -number;
        numOff = 2;
    }

    if (number > 99999)
        numOff += 10;
    else if (number > 9999)
        numOff += 8;
    else if (number > 999)
        numOff += 6;
    else if (number > 99)
        numOff += 4;
    else if (number > 9)
        numOff += 2;

    numStart = numOff;

    while (number > 0)
    {
        int rem = DivRem(number, 10);

        buf[numOff]   = sStrZero[0];
        buf[numOff+1] = sStrZero[1] + rem;

        number = Div(number, 10);
        numOff -= 2;
    }

    *(buf + numStart + 2) = '\0';
    return (numStart >> 1) + 1;
}

static struct Text sText_03000420;

struct Text * PutStringCentered(u16 * tm, int color, int width, char const * str)
{
    struct Text * const text = &sText_03000420;

    InitText(text, width);

    Text_SetCursor(text, (width*8 - GetStringTextLen(str) - 1) / 2);
    Text_SetColor(text, color);
    Text_DrawString(text, str);

    PutText(text, tm);

    EnableBgSync(BG0_SYNC_BIT);

    return text;
}

struct Text * PutString(u16 * tm, int color, char const * str)
{
    struct Text * const text = &sText_03000420;

    InitText(text, (GetStringTextLen(str)+7) / 8);

    Text_SetColor(text, color);
    Text_DrawString(text, str);

    PutText(text, tm);

    return text;
}

struct UnkProc_085C4E64
{
    /* 00 */ PROC_HEADER;

    /* 2C */ u16 const * colors;
    /* 30 */ u16 palOffset;
    /* 32 */ u16 colorCount;
    /* 34 */ u16 clock_end;
    /* 36 */ u16 clock;
    /* 38 */ u16 counter;
    /* 3A */ u16 reverseOrder;
};

void func_fe6_08014DCC(struct UnkProc_085C4E64 * proc);

struct ProcScr CONST_DATA ProcScr_085C4E64[] =
{
    PROC_REPEAT(func_fe6_08014DCC),
};

void func_fe6_08014D50(void)
{
    Proc_EndEach(ProcScr_085C4E64);
}

struct UnkProc_085C4E64 * func_fe6_08014D60(u16 const * colors, int pal_offset, int pal_size, int interval, ProcPtr parent)
{
    struct UnkProc_085C4E64 * proc;

    proc = SpawnProc(ProcScr_085C4E64, parent);

    proc->colors = colors;
    proc->palOffset = pal_offset;
    proc->colorCount = pal_size / 2;
    proc->clock = interval;
    proc->clock_end = interval;
    proc->counter = 0;
    proc->reverseOrder = 0;

    return proc;
}

void func_fe6_08014D9C(u16 const * colors, int pal_offset, int pal_size, int interval, ProcPtr parent)
{
    func_fe6_08014D60(colors, pal_offset, pal_size, interval, parent)->reverseOrder = FALSE;
}

void func_fe6_08014DB4(u16 const * colors, int pal_offset, int pal_size, int interval, ProcPtr parent)
{
    func_fe6_08014D60(colors, pal_offset, pal_size, interval, parent)->reverseOrder = TRUE;
}

void func_fe6_08014DCC(struct UnkProc_085C4E64 * proc)
{
    int colornum;

    proc->clock++;

    if (proc->clock < proc->clock_end)
        return;

    proc->clock = 0;

    colornum = DivRem(proc->counter, proc->colorCount);

    if (proc->reverseOrder)
        colornum = proc->colorCount - colornum - 1;

    ApplyPaletteExt(proc->colors + colornum, proc->palOffset, 2*proc->colorCount - 2*colornum);

    if (colornum > 0)
        ApplyPaletteExt(proc->colors, proc->palOffset + 2*proc->colorCount - 2*colornum, 2*colornum);

    proc->counter++;
}

void func_fe6_08014E30(u16 * tm, int x, int y, u16 tileref, int width, int height)
{
    int ix, iy;

    for (iy = y; iy < y + height; ++iy)
    {
        for (ix = x; ix < x + width; ++ix, ++tileref)
        {
            if ((ix >= 0 && ix < 0x20) && (iy >= 0 && iy < 0x20))
                tm[TM_OFFSET(ix, iy)] = tileref;
        }
    }
}

void func_fe6_08014E98(u16 * tm, int x, int y, u16 tileref, int width, int height, u16 const * src, bool hflip)
{
    int ix, iy;

    u16 const * src_1 = src;

    if (hflip)
    {
        for (iy = 0; iy < height; ++iy)
        {
            for (ix = 0; ix < width; ++ix)
            {
                if ((x+ix >= 0 && x+ix < 0x20) && (y+iy >= 0 && y+iy < 0x20))
                {
                    *(tm + (x + ix) + ((y + iy) * 0x20)) = (*(src_1 + (width - 1 - ix) + (iy * 0x20)) + tileref) ^ TILE_HFLIP;
                }
            }
        }
    }
    else
    {
        for (iy = 0; iy < height; ++iy)
        {
            for (ix = 0; ix < width; ++ix)
            {
                if ((x+ix >= 0 && x+ix < 0x20) && (y+iy >= 0 && y+iy < 0x20))
                {
                    *(tm + (x + ix) + ((y + iy) * 0x20)) = *(src_1 + ix + (iy * 0x20)) + tileref;
                }
            }
        }
    }
}

void func_fe6_08014F70(u16 * tm, int x, int y, u16 tileref, int width, int height, u16 const * src, int arg_7)
{
    int ix, iy;

    u16 const * src_1 = src;

    int r4 = Div(0x20, width);
    int r6 = Div(arg_7, r4);
    int r0 = DivRem(arg_7, r4);

    src_1 = src_1 + (width * r0) + (r6 * height) * 32;

    for (iy = 0; iy < height; ++iy)
    {
        for (ix = 0; ix < width; ++ix)
        {
            if ((x+ix >= 0 && x+ix < 0x20) && (y+iy >= 0 && y+iy < 0x20))
            {
                *(tm + (x + ix) + ((y + iy) * 32)) = *(src_1 + ix + (iy * 32)) + tileref;
            }
        }
    }
}

void func_fe6_0801501C(u16 * tm, int x, int y, u16 tileref, int width, int height, u8 const * src, int arg_7)
{
    int ix, iy;
    int r0, r5;

    u16 const * src_1 = (u16 const *) src;

    u16 r9 = *src + 1;

    src_1 = src_1 + 1;

    r5 = Div(r9, width);
    r0 = Div(arg_7, r5);

    src_1 = src_1 + width * (arg_7 - r5 * r0) + ((r0 * height) * 0x20);

    for (iy = 0; iy < height; ++iy)
    {
        for (ix = 0; ix < width; ++ix)
        {
            if ((x+ix >= 0 && x+ix < 0x20) && (y+iy >= 0 && y+iy < 0x20))
            {
                *(tm + (x + ix) + ((y + iy) * 32)) = *(src_1 + ix + (r9 * (height - iy - 1))) + tileref;
            }
        }
    }
}

void func_fe6_080150DC(u16 * tm, int x, int y, u32 const * arg_3, u16 tileref)
{
    i16 iy, ix;

    u16 const * r2 = ((u16 const *) arg_3) + 1;

    i16 r9 = 0xFF & (((u32 const *) arg_3)[0] >> 0);
    i16 r3 = 0xFF & (((u32 const *) arg_3)[0] >> 8);

    for (iy = r3; iy >= 0; --iy)
    {
        if ((y + iy >= 0 && y + iy < 0x20))
        {
            u16 * r1 = x + (y + iy) * 32 + tm;

            for (ix = r9; ix >= 0; --ix, r2++, r1++)
            {
                if (x+ix >= 0 && x+ix < 0x20)
                    *(r1) = *r2 + tileref;
            }
        }
    }
}

struct CallDelayedProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ void (* func)();
    /* 30 */ int arg;
    /* 34 */ int clock;
};

static void CallDelayed_OnLoop(struct CallDelayedProc * proc)
{
    proc->clock--;

    if (proc->clock == -1)
    {
        void (* func)(void) = (void(*)(void)) proc->func;

        func();
        Proc_Break(proc);
    }
}

static void CallDelayedArg_OnLoop(struct CallDelayedProc * proc)
{
    proc->clock--;

    if (proc->clock == -1)
    {
        void (* func)(int) = (void(*)(int)) proc->func;

        func(proc->arg);
        Proc_Break(proc);
    }
}

struct ProcScr CONST_DATA ProcScr_CallDelayed[] =
{
    PROC_REPEAT(CallDelayed_OnLoop),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_CallDelayedArg[] =
{
    PROC_REPEAT(CallDelayedArg_OnLoop),
    PROC_END,
};

void CallDelayed(void (* func)(void), int delay)
{
    struct CallDelayedProc * proc = SpawnProc(ProcScr_CallDelayed, PROC_TREE_3);

    proc->func = func;
    proc->clock = delay;
}

void CallDelayedArg(void (* func)(int), int arg, int delay)
{
    struct CallDelayedProc * proc = SpawnProc(ProcScr_CallDelayedArg, PROC_TREE_3);

    proc->func = func;
    proc->arg = arg;
    proc->clock = delay;
}

void func_fe6_080151E4(u8 * out, int size)
{
    while (size > 0)
    {
        *out++ = 0;
        size--;
    }
}

void func_fe6_080151F8(u8 * out, int size, int value)
{
    while (size > 0)
    {
        *out++ = value;
        size--;
    }
}

void func_fe6_08015208(u16 * out, int size, int value)
{
    while (size > 0)
    {
        *out++ = value;
        size--;
    }
}

#define RGB_16TIMES(r, g, b) \
    RGB(r, g, b), \
    RGB(r, g, b), \
    RGB(r, g, b), \
    RGB(r, g, b), \
    RGB(r, g, b), \
    RGB(r, g, b), \
    RGB(r, g, b), \
    RGB(r, g, b), \
    RGB(r, g, b), \
    RGB(r, g, b), \
    RGB(r, g, b), \
    RGB(r, g, b), \
    RGB(r, g, b), \
    RGB(r, g, b), \
    RGB(r, g, b), \
    RGB(r, g, b), \

u16 CONST_DATA Pal_AllBlack[] = { RGB_16TIMES(0,  0,  0)  };
u16 CONST_DATA Pal_AllWhite[] = { RGB_16TIMES(31, 31, 31) };
u16 CONST_DATA Pal_AllRed[]   = { RGB_16TIMES(31, 0,  0)  };
u16 CONST_DATA Pal_AllGreen[] = { RGB_16TIMES(0,  31, 0)  };
u16 CONST_DATA Pal_AllBlue[]  = { RGB_16TIMES(0,  0,  31) };
u16 CONST_DATA Pal_085C4F2C[] = { RGB_16TIMES(30, 31, 1)  };

#undef RGB_16TIMES

static void PartialGameLock_OnLoop(struct GenericProc * proc);

struct ProcScr CONST_DATA ProcScr_PartialGameLock[] =
{
    PROC_REPEAT(PartialGameLock_OnLoop),
    PROC_END,
};

void StartPartialGameLock(ProcPtr proc)
{
    struct GenericProc * gproc;

    gproc = SpawnProcLocking(ProcScr_PartialGameLock, proc);
    gproc->unk64 = GetGameLock();
}

static void PartialGameLock_OnLoop(struct GenericProc * proc)
{
    if (GetGameLock() == proc->unk64)
        Proc_Break(proc);
}

void VramCopy(u8 const * src, u8 * dst, int size)
{
    if ((size & 0x1F) != 0)
        CpuCopy16(src, dst, size);
    else
        CpuFastCopy(src, dst, size);
}

void func_fe6_08015298(u8 const * src, u8 * dst, int width, int height)
{
    int i, line_size = width * CHR_SIZE;

    for (i = 0; i < height; ++i)
    {
        VramCopy(src, dst, line_size);

        src += line_size;
        dst += 0x20 * CHR_SIZE;
    }
}

void PutTmLinear(u16 const * src, u16 * dst, int size, u16 tileref)
{
    while (size > 0)
    {
        *dst++ = *src++ + tileref;
        size -= 2;
    }
}

u16 * GetTmOffsetById(int bgid, int x, int y)
{
    switch (bgid)
    {

    case 0:
        return gBg0Tm + TM_OFFSET(x, y);

    case 1:
        return gBg1Tm + TM_OFFSET(x, y);

    case 2:
        return gBg2Tm + TM_OFFSET(x, y);

    case 3:
        return gBg3Tm + TM_OFFSET(x, y);

    default:
        return NULL;

    }
}

void func_fe6_08015344(void)
{
    if (gDispIo.bg0_ct.color_depth == BG_COLORDEPTH_4BPP)
        func_fe6_08015208((u16 *) (VRAM + GetBgChrOffset(0)), 0x10, 0);

    if (gDispIo.bg1_ct.color_depth == BG_COLORDEPTH_4BPP)
        func_fe6_08015208((u16 *) (VRAM + GetBgChrOffset(1)), 0x10, 0);

    if (gDispIo.bg2_ct.color_depth == BG_COLORDEPTH_4BPP)
        func_fe6_08015208((u16 *) (VRAM + GetBgChrOffset(2)), 0x10, 0);

    if (gDispIo.bg3_ct.color_depth == BG_COLORDEPTH_4BPP)
        func_fe6_08015208((u16 *) (VRAM + GetBgChrOffset(3)), 0x10, 0);
}

int Screen2Pan(int x)
{
    if (x < 0)
        return -0x60;

    if (x >= DISPLAY_WIDTH)
        return +0x5F;

    return Div(0xC0 * x, DISPLAY_WIDTH) - 0x60;
}

void PlaySeSpacial(int song, int x)
{
    struct MusicPlayer * music_player;

    PlaySe(song);

    music_player = gMusicPlayerTable[gSongTable[song].ms].music_player;

    m4aMPlayImmInit(music_player);
    m4aMPlayPanpotControl(music_player, 0xFFFF, Screen2Pan(x));
}

static void PlaySeFunc(int song);

void PlaySeDelayed(int song, int delay)
{
    CallDelayedArg(PlaySeFunc, song, delay);
}

static void PlaySeFunc(int song)
{
    PlaySe(song);
}

void func_fe6_0801548C(short song)
{
    StartBgm(song, NULL);
}

void func_fe6_0801549C(short speed)
{
    FadeBgmOut(speed);
}

void func_fe6_080154AC(int palid)
{
    int i;

    u16 * pal = gPal + palid * 0x10;

    for (i = 0; i < 0x10; ++i)
    {
        int red   = ((pal[i] & (0x1F))       / 4) * 3;
        int green = ((pal[i] & (0x1F << 5))  / 4) * 3;
        int blue  = ((pal[i] & (0x1F << 10)) / 4) * 3;

        pal[i] = (red & (0x1F)) | (green & (0x1F << 5)) | (blue & (0x1F << 10));
    }
}

void func_fe6_08015504(u8 const * src, u8 * dst, int size)
{
    while (size != 0)
    {
        *dst = *src;

        dst++;
        src++;

        size--;
    }
}

void PutDrawTextCentered(struct Text * text, int x, int y, char const * str, int width)
{
    int off;

    off = GetStringTextLen(str);
    off = (width*8 - off) >> 1;

    Text_SetCursor(text, off);
    Text_DrawString(text, str);

    PutText(text, gBg0Tm + TM_OFFSET(x, y));
}

void VecMulMat(int const * vec, int const * mat, int * ovec)
{
    ovec[0] = ((vec[0] * mat[0]) + (vec[1] * mat[3]) + (vec[2] * mat[6])) >> 12;
    ovec[1] = ((vec[0] * mat[1]) + (vec[1] * mat[4]) + (vec[2] * mat[7])) >> 12;
    ovec[2] = ((vec[0] * mat[2]) + (vec[1] * mat[5]) + (vec[2] * mat[8])) >> 12;
}

void MatMulMat(int const * lmat, int const * rmat, int * omat)
{
    int tmpmat[12];
    int * mat;

    if (lmat == omat || rmat == omat)
        mat = tmpmat;
    else
        mat = omat;

    mat[0] = ((lmat[0] * rmat[0]) + (lmat[1] * rmat[3]) + (lmat[2] * rmat[6])) >> 12;
    mat[1] = ((lmat[0] * rmat[1]) + (lmat[1] * rmat[4]) + (lmat[2] * rmat[7])) >> 12;
    mat[2] = ((lmat[0] * rmat[2]) + (lmat[1] * rmat[5]) + (lmat[2] * rmat[8])) >> 12;

    mat[3] = ((lmat[3] * rmat[0]) + (lmat[4] * rmat[3]) + (lmat[5] * rmat[6])) >> 12;
    mat[4] = ((lmat[3] * rmat[1]) + (lmat[4] * rmat[4]) + (lmat[5] * rmat[7])) >> 12;
    mat[5] = ((lmat[3] * rmat[2]) + (lmat[4] * rmat[5]) + (lmat[5] * rmat[8])) >> 12;

    mat[6] = ((lmat[6] * rmat[0]) + (lmat[7] * rmat[3]) + (lmat[8] * rmat[6])) >> 12;
    mat[7] = ((lmat[6] * rmat[1]) + (lmat[7] * rmat[4]) + (lmat[8] * rmat[7])) >> 12;
    mat[8] = ((lmat[6] * rmat[2]) + (lmat[7] * rmat[5]) + (lmat[8] * rmat[8])) >> 12;

    mat[9]  = (((lmat[0] * rmat[9]) + (lmat[3] * rmat[10]) + (lmat[6] * rmat[11])) >> 12) + lmat[9];
    mat[10] = (((lmat[1] * rmat[9]) + (lmat[4] * rmat[10]) + (lmat[7] * rmat[11])) >> 12) + lmat[10];
    mat[11] = (((lmat[2] * rmat[9]) + (lmat[5] * rmat[10]) + (lmat[8] * rmat[11])) >> 12) + lmat[11];

    if (mat == tmpmat)
        MatCopy(tmpmat, omat);
}

void MatIdent(int * mat)
{
    mat[0] = 1 << 12;
    mat[1] = 0;
    mat[2] = 0;

    mat[3] = 0;
    mat[4] = 1 << 12;
    mat[5] = 0;

    mat[6] = 0;
    mat[7] = 0;
    mat[8] = 1 << 12;

    mat[9]  = 0;
    mat[10] = 0;
    mat[11] = 0;
}

void MatCopy(int const * src, int * dst)
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];

    dst[3] = src[3];
    dst[4] = src[4];
    dst[5] = src[5];

    dst[6] = src[6];
    dst[7] = src[7];
    dst[8] = src[8];

    dst[9]  = src[9];
    dst[10] = src[10];
    dst[11] = src[11];
}

void MatRotA(int * mat, short angle)
{
    short cos = COS_Q12(angle);
    short sin = SIN_Q12(angle);

    mat[0] = 1 << 12;
    mat[1] = 0;
    mat[2] = 0;

    mat[3] = 0;
    mat[4] = +cos;
    mat[5] = -sin;

    mat[6] = 0;
    mat[7] = +sin;
    mat[8] = +cos;
}

void MatRotB(int * mat, short angle)
{
    short cos = COS_Q12(angle);
    short sin = SIN_Q12(angle);

    mat[0] = +cos;
    mat[1] = 0;
    mat[2] = -sin;

    mat[3] = 0;
    mat[4] = 1 << 12;
    mat[5] = 0;

    mat[6] = +sin;
    mat[7] = 0;
    mat[8] = +cos;
}

void MatRotC(int * mat, short angle)
{
    short cos = COS_Q12(angle);
    short sin = SIN_Q12(angle);

    mat[0] = +cos;
    mat[1] = -sin;
    mat[2] = 0;

    mat[3] = +sin;
    mat[4] = +cos;
    mat[5] = 0;

    mat[6] = 0;
    mat[7] = 0;
    mat[8] = 1 << 12;
}

void func_fe6_08015858(void)
{
}

int VecDotVec(int const * lvec, int const * rvec)
{
    return ((lvec[0] * rvec[0]) + (lvec[1] * rvec[1]) + (lvec[2] * rvec[2])) >> 12;
}

void VecCrossVec(int const * lvec, int const * rvec, int * ovec)
{
    ovec[0] = (lvec[1] * rvec[2] - lvec[2] * rvec[1]) >> 12;
    ovec[1] = (lvec[2] * rvec[0] - lvec[0] * rvec[2]) >> 12;
    ovec[2] = (lvec[0] * rvec[1] - lvec[1] * rvec[0]) >> 12;
}

int func_fe6_080158B8(int arg_0, int arg_1, int arg_2, int arg_3)
{
    return arg_3 * arg_0 - arg_2 * arg_1;
}
