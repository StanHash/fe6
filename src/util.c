
#include "common.h"

#include "hardware.h"
#include "move.h"
#include "armfunc.h"
#include "sound.h"
#include "text.h"

#include "constants/video-global.h"

enum
{
    INTERPOLATE_LINEAR,
    INTERPOLATE_SQUARE,
    INTERPOLATE_CUBIC,
    INTERPOLATE_POW4,
    INTERPOLATE_RSQUARE,
    INTERPOLATE_RCUBIC,
};

#if NONMATCHING

int Interpolate(int method, int lo, int hi, int x, int end)
{
    if (end == 0)
        return hi;

    switch (shape)
    {

    case INTERPOLATE_LINEAR:
        return lo + Div((hi - lo) * x, end);

    case INTERPOLATE_SQUARE:
        return lo + Div((hi - lo) * x * x, end * end);

    case INTERPOLATE_CUBIC:
        return lo + Div((hi - lo) * x * x * x, end * end * end);

    case INTERPOLATE_POW4:
        return lo + Div((hi - lo) * x * x * x * x, end * end * end * end);

    case INTERPOLATE_RSQUARE:
        return hi - Div((hi - lo) * (end - x) * (end - x), end * end);

    case INTERPOLATE_RCUBIC:
        return hi - Div((hi - lo) * (end - x) * (end - x) * (end - x), end * end * end);

    default:
        return 0;

    }
}

#else

NAKEDFUNC int Interpolate(int method, int lo, int hi, int x, int end)
{
    asm("\
        .syntax unified\n\
        push {r4, r5, r6, lr}\n\
        adds r6, r1, #0\n\
        ldr r5, [sp, #0x10]\n\
        cmp r5, #0\n\
        bne _08013B32\n\
        adds r0, r2, #0\n\
        b _08013BE6\n\
    _08013B32:\n\
        cmp r0, #5\n\
        bhi _08013BE4\n\
        lsls r0, r0, #2\n\
        ldr r1, _08013B40 @ =_08013B44\n\
        adds r0, r0, r1\n\
        ldr r0, [r0]\n\
        mov pc, r0\n\
        .align 2, 0\n\
    _08013B40: .4byte _08013B44\n\
    _08013B44: @ jump table\n\
        .4byte _08013B5C @ case 0\n\
        .4byte _08013B68 @ case 1\n\
        .4byte _08013B78 @ case 2\n\
        .4byte _08013B8C @ case 3\n\
        .4byte _08013BB0 @ case 4\n\
        .4byte _08013BC2 @ case 5\n\
    _08013B5C:\n\
        subs r0, r2, r6\n\
        adds r2, r0, #0\n\
        muls r2, r3, r2\n\
        adds r0, r2, #0\n\
        adds r1, r5, #0\n\
        b _08013BA8\n\
    _08013B68:\n\
        adds r0, r3, #0\n\
        muls r0, r3, r0\n\
        subs r1, r2, r6\n\
        adds r2, r0, #0\n\
        muls r2, r1, r2\n\
        adds r1, r5, #0\n\
        muls r1, r5, r1\n\
        b _08013BA6\n\
    _08013B78:\n\
        adds r0, r3, #0\n\
        muls r0, r3, r0\n\
        adds r1, r0, #0\n\
        muls r1, r3, r1\n\
        subs r0, r2, r6\n\
        adds r2, r1, #0\n\
        muls r2, r0, r2\n\
        adds r0, r5, #0\n\
        muls r0, r5, r0\n\
        b _08013BA2\n\
    _08013B8C:\n\
        adds r0, r3, #0\n\
        muls r0, r3, r0\n\
        muls r0, r3, r0\n\
        adds r1, r0, #0\n\
        muls r1, r3, r1\n\
        subs r0, r2, r6\n\
        adds r2, r1, #0\n\
        muls r2, r0, r2\n\
        adds r0, r5, #0\n\
        muls r0, r5, r0\n\
        muls r0, r5, r0\n\
    _08013BA2:\n\
        adds r1, r0, #0\n\
        muls r1, r5, r1\n\
    _08013BA6:\n\
        adds r0, r2, #0\n\
    _08013BA8:\n\
        bl Div\n\
        adds r0, r6, r0\n\
        b _08013BE6\n\
    _08013BB0:\n\
        subs r1, r5, r3\n\
        adds r0, r1, #0\n\
        muls r0, r1, r0\n\
        subs r4, r2, r6\n\
        adds r2, r0, #0\n\
        muls r2, r4, r2\n\
        adds r1, r5, #0\n\
        muls r1, r5, r1\n\
        b _08013BD8\n\
    _08013BC2:\n\
        subs r1, r5, r3\n\
        adds r0, r1, #0\n\
        muls r0, r1, r0\n\
        muls r0, r1, r0\n\
        subs r4, r2, r6\n\
        adds r2, r0, #0\n\
        muls r2, r4, r2\n\
        adds r0, r5, #0\n\
        muls r0, r5, r0\n\
        adds r1, r0, #0\n\
        muls r1, r5, r1\n\
    _08013BD8:\n\
        adds r0, r2, #0\n\
        bl Div\n\
        adds r4, r6, r4\n\
        subs r0, r4, r0\n\
        b _08013BE6\n\
    _08013BE4:\n\
        movs r0, #0\n\
    _08013BE6:\n\
        pop {r4, r5, r6}\n\
        pop {r1}\n\
        bx r1\n\
        .syntax divided\n\
    ");
}

#endif

void nullsub_12(void)
{
}

Bool StringEquals(char const* strA, char const* strB)
{
    while (*strA | *strB)
    {
        if (*strA++ != *strB++)
            return FALSE;
    }

    return TRUE;
}

void StringCopy(char* dst, char const* src)
{
    while (*src)
    {
        *dst++ = *src++;
    }

    *dst = *src;
}

void sub_8013C30(u8 const* src, u8* dst)
{
    int size = sub_8013CE4(src) - 4;

    if (size % 0x20 != 0)
        CpuCopy16(src + 4, dst, size);
    else
        CpuFastCopy(src + 4, dst, size);
}

void sub_8013C74(u8 const* src, u8* dst)
{
    LZ77UnCompWram(src, gBuf);
    CpuFastCopy(gBuf, dst, sub_8013CE4(src));
}

void Decompress(u8 const* src, u8* dst)
{
    typedef void(*DecompressFunc)(u8 const*, u8*);

    static DecompressFunc CONST_DATA funcLut[] =
    {
        sub_8013C30,    // 00, vram
        sub_8013C30,    // 00, wram
        LZ77UnCompVram, // 10, vram
        LZ77UnCompWram, // 10, wram
        HuffUnComp,     // 20, vram
        HuffUnComp,     // 20, wram
        RLUnCompVram,   // 30, vram
        RLUnCompWram,   // 30, wram
    };

    int isWram;

    if ((((u32) dst) - VRAM) < VRAM_SIZE)
        isWram = 0; // is vram
    else
        isWram = 1;

    funcLut[isWram + ((src[0] & 0xF0) >> 3)](src, dst);
}

int sub_8013CE4(u8 const* data)
{
    return *((u32 const*) (void const*) data) >> 8;
}

struct Unk_08013CEC
{
    u8* dst;
    int unk_04;
};

struct Unk* sub_8013CEC(struct Unk_08013CEC* unk, int arg_1, int arg_2)
{
    unk->dst = (u8*) arg_2;

    arg_1 = (arg_1 & 0xFFE0) >> 5;
    arg_2 = (arg_2 & 0xFFE0) >> 5;

    unk->unk_04 = arg_2 - arg_1;
}

int sub_8013D04(struct Unk_08013CEC* unk, u8 const* src)
{
    int size, old;

    Decompress(src, unk->dst);

    size = sub_8013CE4(src);

    unk->dst += size;

    old = unk->unk_04;
    unk->unk_04 += size / 0x20;

    return old;
}

int sub_8013D34(struct Unk_08013CEC* unk, int arg_1)
{
    int old;

    unk->dst += arg_1 << 5;

    old = unk->unk_04;
    unk->unk_04 += arg_1;

    return old;
}

void sub_8013D48(u8 const* src, u8* dst, int width, int height)
{
    int i, lineSize = width * CHR_SIZE;

    if (height <= 0)
        return;

    for (i = height; i != 0; --i)
    {
        RegisterDataMove(src, dst, lineSize);

        src += lineSize;
        dst += CHR_SIZE * 0x20;
    }
}

void sub_8013D74(u8 const* src, u8* dst, int width, int height)
{
    int i, lineSize = width * CHR_SIZE;

    if (height <= 0)
        return;

    for (i = height; i != 0; --i)
    {
        CpuFastCopy(src, dst, lineSize);

        src += lineSize;
        dst += CHR_SIZE * 0x20;
    }
}

static void sub_8013DE8(u8 const* src, u8* dst, int width);

void sub_8013DAC(u8 const* src, u8* dst, int width, int height)
{
    int i, lineSize;

    if (height <= 0)
        return;

    lineSize = 8 * 8 * width;

    for (i = height; i != 0; --i)
    {
        sub_8013DE8(src, dst, width);

        src += lineSize;
        dst += CHR_SIZE * width;
    }
}

static void sub_8013E10(u8 const* src, u32* dst, int width);

static void sub_8013DE8(u8 const* src, u8* dst, int width)
{
    int i;

    if (width <= 0)
        return;

    for (i = width; i != 0; i--)
    {
        sub_8013E10(src, (u32*) dst, width);

        src += 8;
        dst += CHR_SIZE;
    }
}

static void sub_8013E10(u8 const* src, u32* dst, int width)
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
        src += width*8;
    }
}

void sub_8013E58(u16* tm, int tileref, int width, int height)
{
    int ix, iy;

    for (iy = 0; iy < height; ++iy)
        for (ix = 0; ix < width; ++ix)
            tm[TM_OFFSET(ix, iy)] = tileref++;
}

void sub_8013E8C(u16* tm, u8 const* src, int tileref, int len)
{
    int i;

    for (i = 0; i < len; ++i)
        tm[-i] = 0;

    while (*src != 0x20)
    {
        *tm-- = tileref + *src - 0x30;
        src--;
    }
}

struct Unk_08013EBC
{
    /* 00 */ u8 pad_00[0x4C - 0x00];
    /* 4C */ u16 unk_4C;
};

void sub_8013EBC(struct Unk_08013EBC* unk, int value)
{
    unk->unk_4C = value;
}

void sub_8013EC4(struct Unk_08013EBC* unk)
{
    unk->unk_4C++;
    unk->unk_4C &= 0x7FFF;
}

void sub_8013ED8(struct Unk_08013EBC* unk)
{
    unk->unk_4C--;
}

void sub_8013EE4(short* array)
{
    int i;

    for (i = DISPLAY_HEIGHT-1; i >= 0; --i)
    {
        *array++ = DISPLAY_WIDTH;
        *array++ = -1;
    }
}

void sub_8013F04(short* array, int xA, int yA, int xB, int yB)
{
    int q16_slope, q16_x, i;

    if (yA > yB)
    {
        int tmp;

        tmp = xB;
        xB = xA;
        xA = tmp;

        tmp = yB;
        yB = yA;
        yA = tmp;
    }

    q16_slope = ((xB - xA) << 16) / (yB - yA);
    q16_x = xA << 16;

    if (yB > DISPLAY_HEIGHT)
        yB = DISPLAY_HEIGHT;

    if (yA < 0)
    {
        q16_x += -yA * q16_slope;
        yA = 0;
    }

    for (i = yA; i < yB; ++i)
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

struct Unk* sub_8013F7C(int arg_0)
{
    #define BUF ((struct Unk*) gBuf)

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

void sub_80140A4(int reduction)
{
    u16* buf = (u16*) gBuf;

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
    RegisterDataMove(buf, (u16*) PLTT, sizeof(gPal));
}

void nullsub_13(void)
{
}

void sub_8014130(char const* arg_0)
{
    char unk[] = "@@LWFOVDBK@@";
    sub_8014130(unk);
}

void sub_8014150(struct GenericProc* proc)
{
    proc->unk64 = 0;
    proc->unk66 = 90;
}

void sub_8014160(struct GenericProc* proc)
{
    int location = 0;

    if (gKeySt->pressed & A_BUTTON)
        proc->unk66++;

    if (((proc->unk64++) & 0x0F) == 0)
    {
        if (gKeySt->held & DPAD_LEFT)
            location = -proc->unk66;

        if (gKeySt->held & DPAD_RIGHT)
            location = +proc->unk66;

        PlaySeSpacial(0x9A, location); // TODO: song ids
    }
}

struct ProcScr CONST_DATA ProcScr_085C4D64[] =
{
    PROC_CALL(LockGame),

    PROC_CALL(sub_8014150),
    PROC_REPEAT(sub_8014160),
};

void sub_80141C8(void)
{
    SpawnProc(ProcScr_085C4D64, PROC_TREE_3);
}

void nullsub_14(void)
{
}

void sub_80141E0(int palid, int arg_1, ProcPtr parent)
{
    sub_8014218(Pal_085C4E8C, palid, arg_1, parent);
}

void sub_80141FC(int palid, int arg_1, ProcPtr parent)
{
    sub_8014218(Pal_085C4EAC, palid, arg_1, parent);
}

struct Unk_0202A408
{
    /* 00 */ u16 fromColors[0x10];
    /* 20 */ u16 const* toColors;
    /* 24 */ u16* pal;
    /* 28 */ u16 clock;
    /* 2A */ u16 clockEnd;
    /* 2C */ u16 clockStop;
};

struct Unk_0202A408 EWRAM_DATA gUnk_0202A408[0x10] = {};

struct UnkPalProc
{
    /* 00 */ PROC_HEADER;
    /* 2C */ struct Unk_0202A408* st;
};

void sub_801428C(struct UnkPalProc* proc);

struct ProcScr CONST_DATA ProcScr_085C4D7C[] =
{
    PROC_MARK(PROC_MARK_10),
    PROC_REPEAT(sub_801428C),

    PROC_END,
};

void* sub_8014218(u16 const* colors, int palid, int arg_2, ProcPtr parent)
{
    struct Unk_0202A408* st = gUnk_0202A408 + palid;

    struct UnkPalProc* proc = SpawnProc(ProcScr_085C4D7C, parent);

    CpuCopy16(gPal + palid * 0x10, st->fromColors, sizeof(st->fromColors));

    st->pal = gPal + palid * 0x10;
    st->toColors = colors;
    st->clock = 0;
    st->clockEnd = arg_2;
    st->clockStop = arg_2 + 1;

    proc->st = st;

    return st;
}

void sub_8014278(void)
{
    Proc_EndEach(ProcScr_085C4D7C);
}

void sub_8014288(struct Unk_0202A408* st, int val)
{
    st->clockStop = val;
}

void sub_801428C(struct UnkPalProc* proc)
{
    int i;

    u16 const* fromColors = proc->st->fromColors;
    u16 const* toColors = proc->st->toColors;

    u16* pal = proc->st->pal;

    if (proc->st->clock == proc->st->clockStop || proc->st->clock > proc->st->clockEnd)
    {
        Proc_End(proc);
        return;
    }

    for (i = 0; i < 0x10; ++i)
    {
        int redA   = fromColors[i] & 0x001F;
        int greenA = fromColors[i] & 0x03E0;
        int blueA  = fromColors[i] & 0x7C00;

        int redB   = toColors[i] & 0x001F;
        int greenB = toColors[i] & 0x03E0;
        int blueB  = toColors[i] & 0x7C00;

        int red   = Interpolate(INTERPOLATE_LINEAR, redA,   redB,   proc->st->clock, proc->st->clockEnd);
        int green = Interpolate(INTERPOLATE_LINEAR, greenA, greenB, proc->st->clock, proc->st->clockEnd);
        int blue  = Interpolate(INTERPOLATE_LINEAR, blueA,  blueB,  proc->st->clock, proc->st->clockEnd);

        pal[i] = (blue & 0x7C00) | (green & 0x03E0) | (red & 0x001F);
    }

    EnablePalSync();
    proc->st->clock++;
}

void sub_8014374(int palid)
{
    CpuCopy16(Pal_085C4E8C, gPal + palid * 0x10, 0x20);
}

void sub_8014394(int palid)
{
    CpuCopy16(Pal_085C4EAC, gPal + palid * 0x10, 0x20);
}

void sub_80143B4(void)
{
    int i;

    for (i = 0; i < 0x20; ++i)
        sub_8014374(i);
}

void sub_80143CC(void)
{
    int i;

    for (i = 0; i < 0x20; ++i)
        sub_8014374(i);
}

void sub_80143E4(struct GenericProc* proc)
{
    gDispIo.winCt.win0_enableBlend = 1;
    gDispIo.winCt.win1_enableBlend = 1;
    gDispIo.winCt.wobj_enableBlend = 1;
    gDispIo.winCt.wout_enableBlend = 1;

    SetBlendDarken(0);

    SetBlendTargetA(1, 1, 1, 1, 1);
    SetBlendBackdropA(1);

    proc->unk64 = 0x10;
    proc->unk66 = 0;
}

void sub_801445C(struct GenericProc* proc)
{
    if (gDispIo.blendY == 0x10)
    {
        Proc_End(proc);
        return;
    }

    proc->unk66 += proc->unk64;

    if (proc->unk66 >= 0x100)
        proc->unk66 = 0x100;

    gDispIo.blendY = proc->unk66 >> 4;
}

void sub_80144A0(struct GenericProc* proc)
{
    gDispIo.winCt.win0_enableBlend = 1;
    gDispIo.winCt.win1_enableBlend = 1;
    gDispIo.winCt.wobj_enableBlend = 1;
    gDispIo.winCt.wout_enableBlend = 1;

    SetBlendDarken(0x10);

    SetBlendTargetA(1, 1, 1, 1, 1);
    SetBlendTargetB(1, 1, 1, 1, 1);
    SetBlendBackdropA(1);

    proc->unk64 = 0x10;
    proc->unk66 = 0x100;
}

void sub_801452C(struct GenericProc* proc)
{
    if (gDispIo.blendY == 0)
    {
        Proc_End(proc);
        return;
    }

    proc->unk66 -= proc->unk64;

    if (proc->unk66 <= 0)
        proc->unk66 = 0;

    gDispIo.blendY = proc->unk66 >> 4;
}

void sub_801456C(struct GenericProc* proc)
{
    sub_80143E4(proc);
    SetBlendBrighten(0);
}

void sub_801459C(struct GenericProc* proc)
{
    sub_80144A0(proc);
    SetBlendBrighten(0x10);
}

struct ProcScr CONST_DATA ProcScr_FadeToBlack[] =
{
    PROC_CALL(sub_80143E4),
    PROC_SLEEP(0),

    PROC_REPEAT(sub_801445C),
    PROC_BLOCK,
};

struct ProcScr CONST_DATA ProcScr_FadeFromBlack[] =
{
    PROC_CALL(sub_80144A0),
    PROC_SLEEP(0),

    PROC_REPEAT(sub_801452C),
    PROC_BLOCK,
};

struct ProcScr CONST_DATA ProcScr_FadeToWhite[] =
{
    PROC_CALL(sub_801456C),
    PROC_SLEEP(0),

    PROC_REPEAT(sub_801445C),
    PROC_BLOCK,
};

struct ProcScr CONST_DATA ProcScr_FadeFromWhite[] =
{
    PROC_CALL(sub_801459C),
    PROC_SLEEP(0),

    PROC_REPEAT(sub_801452C),
    PROC_BLOCK,
};

Bool sub_80145D0(void)
{
    if (!Proc_Find(ProcScr_FadeFromBlack) &&
        !Proc_Find(ProcScr_FadeToBlack) &&
        !Proc_Find(ProcScr_FadeFromWhite) &&
        !Proc_Find(ProcScr_FadeToWhite))
    {
        return FALSE;
    }

    return TRUE;
}

void sub_8014618(int q4_speed)
{
    struct GenericProc* proc = SpawnProc(ProcScr_FadeToBlack, PROC_TREE_3);
    proc->unk64 = q4_speed;
}

void sub_8014634(int q4_speed)
{
    struct GenericProc* proc = SpawnProc(ProcScr_FadeFromBlack, PROC_TREE_3);
    proc->unk64 = q4_speed;
}

void StartBlockingFadeInBlack(int q4_speed, ProcPtr parent)
{
    struct GenericProc* proc = SpawnProcLocking(ProcScr_FadeToBlack, parent);
    proc->unk64 = q4_speed;
}

void StartBlockingFadeOutBlack(int q4_speed, ProcPtr parent)
{
    struct GenericProc* proc = SpawnProcLocking(ProcScr_FadeFromBlack, parent);
    proc->unk64 = q4_speed;
}

void sub_8014680(int q4_speed, ProcPtr parent)
{
    struct GenericProc* proc = SpawnProcLocking(ProcScr_FadeToWhite, parent);
    proc->unk64 = q4_speed;
}

void sub_8014698(int q4_speed, ProcPtr parent)
{
    struct GenericProc* proc = SpawnProcLocking(ProcScr_FadeFromWhite, parent);
    proc->unk64 = q4_speed;
}

void sub_80146B0(void)
{
    sub_8014618(0x10);
}

void sub_80146BC(void)
{
    sub_8014618(0x04);
}

void sub_80146C8(void)
{
    sub_8014618(0x40);
}

void sub_80146D4(void)
{
    sub_8014634(0x10);
}

void sub_80146E0(void)
{
    sub_8014634(0x04);
}

void sub_80146EC(void)
{
    sub_8014634(0x40);
}

void sub_80146F8(ProcPtr parent)
{
    StartBlockingFadeInBlack(0x10, parent);
}

void sub_8014708(ProcPtr parent)
{
    StartBlockingFadeInBlack(0x04, parent);
}

void sub_8014718(ProcPtr parent)
{
    StartBlockingFadeInBlack(0x40, parent);
}

void StartBlockingFadeOutBlackMedium(ProcPtr parent)
{
    StartBlockingFadeOutBlack(0x10, parent);
}

void sub_8014738(ProcPtr parent)
{
    StartBlockingFadeOutBlack(0x04, parent);
}

void sub_8014748(ProcPtr parent)
{
    StartBlockingFadeOutBlack(0x40, parent);
}

void sub_8014758(ProcPtr parent)
{
    sub_8014680(0x04, parent);
}

void sub_8014768(ProcPtr parent)
{
    sub_8014698(0x04, parent);
}

void sub_8014778(ProcPtr parent)
{
    sub_80149E0(1, 0x04, parent, sub_8014AF8);
}

void sub_8014790(ProcPtr parent)
{
    sub_80149E0(1, 0x08, parent, sub_8014AF8);
}

void sub_80147A8(ProcPtr parent)
{
    sub_80149E0(1, 0x10, parent, sub_8014AF8);
}

void sub_80147C0(ProcPtr parent)
{
    sub_80149E0(1, 0x20, parent, sub_8014AF8);
}

void sub_80147D8(ProcPtr parent)
{
    sub_80149E0(1, 0x40, parent, sub_8014AF8);
}

void sub_80147F0(ProcPtr parent)
{
    sub_80149E0(0, 0x08, parent, NULL);
}

void sub_8014804(ProcPtr parent)
{
    sub_80149E0(0, 0x10, parent, NULL);
}

void sub_8014818(ProcPtr parent)
{
    sub_80149E0(0, 0x20, parent, NULL);
}

void sub_801482C(ProcPtr parent)
{
    sub_80149E0(0, 0x40, parent, NULL);
}

void sub_8014840(ProcPtr parent)
{
    sub_80149E0(3, 0x04, parent, sub_8014AF8);
}

void sub_8014858(ProcPtr parent)
{
    sub_80149E0(3, 0x08, parent, sub_8014AF8);
}

void sub_8014870(ProcPtr parent)
{
    sub_80149E0(3, 0x10, parent, sub_8014AF8);
}

void sub_8014888(ProcPtr parent)
{
    sub_80149E0(3, 0x20, parent, sub_8014AF8);
}

void sub_80148A0(ProcPtr parent)
{
    sub_80149E0(3, 0x40, parent, sub_8014AF8);
}

void sub_80148B8(ProcPtr parent)
{
    sub_80149E0(2, 0x04, parent, NULL);
}

void sub_80148CC(ProcPtr parent)
{
    sub_80149E0(2, 0x08, parent, NULL);
}

void sub_80148E0(ProcPtr parent)
{
    sub_80149E0(2, 0x08, parent, NULL);
    sub_8014AB8();
}

void sub_80148F8(ProcPtr parent)
{
    sub_80149E0(2, 0x10, parent, NULL);
}

void sub_801490C(ProcPtr parent)
{
    sub_80149E0(2, 0x20, parent, NULL);
}

void sub_8014920(ProcPtr parent)
{
    sub_80149E0(2, 0x40, parent, NULL);
}

void sub_8014934(ProcPtr parent)
{
    sub_80149E0(6, 0x10, parent, NULL);
}

void sub_8014948(ProcPtr parent)
{
    sub_80149E0(7, 0x10, parent, NULL);
}

void sub_801495C(ProcPtr parent)
{
    sub_80149E0(6, 0x08, parent, NULL);
}

void sub_8014970(ProcPtr parent)
{
    sub_80149E0(4, 0x04, parent, NULL);
}

void sub_8014984(ProcPtr parent)
{
    sub_80149E0(4, 0x08, parent, NULL);
}

void sub_8014998(ProcPtr parent)
{
    sub_80149E0(7, 0x08, parent, sub_8014B68);
}

void sub_80149B0(ProcPtr proc)
{
    if (!sub_80145D0())
        Proc_Break(proc);
}

void sub_80149CC(ProcPtr parent, Func func)
{
    sub_80149E0(3, 0x40, parent, func);
}

struct FadeUnkProc
{
    /* 00 */ PROC_HEADER;

    /* 29 */ u8 pad_29[0x4C - 0x29];

    /* 4C */ Func onEnd;
    /* 50 */ int pad_50;
    /* 54 */ int unk_54;
    /* 58 */ int unk_58;
    /* 5C */ int unk_5C;
};

void sub_8014A38(struct FadeUnkProc* proc);
s8 sub_8014A68(struct FadeUnkProc* proc);
void sub_8014A44(struct FadeUnkProc* proc);

struct ProcScr CONST_DATA ProcScr_FadeUnk[] =
{
    PROC_MARK(PROC_MARK_10),

    PROC_CALL(sub_8014A38),
    PROC_SLEEP(0),

    PROC_CALL(sub_8014A68),
    PROC_REPEAT(sub_8014A44),

    PROC_END,
};

struct LutItem_80149E0
{
    ProcPtr(*spawnProc)(struct ProcScr const*, ProcPtr);
    void(*unk_04)(s8);
    int unit;
};

static struct LutItem_80149E0 const sLut_80149E0[] =
{
    { SpawnProc,        sub_800210C, +1 },
    { SpawnProc,        sub_8001FD4, -1 },
    { SpawnProcLocking, sub_800210C, +1 },
    { SpawnProcLocking, sub_8001FD4, -1 },
    { SpawnProc,        sub_800236C, -1 },
    { SpawnProc,        sub_8002234, +1 },
    { SpawnProcLocking, sub_800236C, -1 },
    { SpawnProcLocking, sub_8002234, +1 },
};

#if !NONMATCHING
NAKEDFUNC
#endif
void sub_80149E0(int kind, int speed, ProcPtr parent, Func endFunc)
{
#if NONMATCHING

    struct FadeUnkProc* proc = sLut_80149E0[kind].spawnProc(ProcScr_FadeUnk, parent);

    proc->unk_54 = speed;
    proc->onEnd = endFunc;

    speed = speed >> 4;

    if (speed == 0)
        speed = 1;

    sLut_80149E0[kind].unk_04(sLut_80149E0[kind].unit * speed);

#else

    asm("\
        push {r4, r5, r6, r7, lr}\n\
        add r4, r1, #0\n\
        add r1, r2, #0\n\
        add r5, r3, #0\n\
        ldr r7, _08014A20 @ =sLut_80149E0\n\
        lsl r2, r0, #1\n\
        add r2, r2, r0\n\
        lsl r6, r2, #2\n\
        add r0, r6, r7\n\
        ldr r2, [r0]\n\
        ldr r0, _08014A24 @ =ProcScr_FadeUnk\n\
        bl _call_via_r2\n\
        str r4, [r0, #0x54]\n\
        str r5, [r0, #0x4C]\n\
        asr r4, r4, #4\n\
        cmp r4, #0\n\
        bne _08014A06\n\
        mov r4, #1\n\
    _08014A06:\n\
        add r0, r7, #4\n\
        add r0, r6, r0\n\
        ldr r1, [r0]\n\
        add r0, r7, #0\n\
        add r0, #8\n\
        add r0, r6, r0\n\
        ldr r0, [r0]\n\
        mul r0, r4, r0\n\
        bl _call_via_r1\n\
        pop {r4, r5, r6, r7}\n\
        pop {r0}\n\
        bx r0\n\
        .align 2, 0\n\
    _08014A20: .4byte sLut_80149E0\n\
    _08014A24: .4byte ProcScr_FadeUnk\n\
    ");

#endif // NONMATCHING
}

void sub_8014A28(void)
{
    Proc_EndEach(ProcScr_FadeUnk);
}

void sub_8014A38(struct FadeUnkProc* proc)
{
    proc->unk_58 = 0;
    proc->unk_5C = 0;
    proc->onEnd = 0;
}

void sub_8014A44(struct FadeUnkProc* proc)
{
    if (!sub_8014A68(proc))
    {
        if (proc->onEnd)
            proc->onEnd();

        Proc_Break(proc);
    }
}

Bool sub_8014A68(struct FadeUnkProc* proc)
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

    sub_8000234_t();

    gPal[0] = 0;
    EnablePalSync();

    return TRUE;
}

void sub_8014AB8(void)
{
    sub_8001F88(0x10, 0x10, 0);
    sub_8014ADC();
}

void sub_8014ACC(int a, int b)
{
    sub_8001F88(a, b, 0);
    sub_8014ADC();
}

void sub_8014ADC(void)
{
    struct FadeUnkProc* proc = Proc_Find(ProcScr_FadeUnk);

    if (proc)
        proc->onEnd = NULL;
}

void sub_8014AF8(void)
{
    SetBlendDarken(0x10);

    SetBlendTargetA(1, 1, 1, 1, 1);
    SetBlendBackdropA(1);

    gPal[0] = 0;
    EnablePalSync();

    SetDispEnable(0, 0, 0, 0, 0);
}

void sub_8014B68(void)
{
    SetBlendBrighten(0x10);

    SetBlendTargetA(1, 1, 1, 1, 1);
    SetBlendBackdropA(1);
}

void sub_8014BC8(struct GenericProc* proc);

struct ProcScr CONST_DATA ProcScr_TemporaryLock[] =
{
    PROC_SLEEP(0),

    PROC_REPEAT(sub_8014BC8),
    PROC_END,
};

void sub_8014BAC(ProcPtr proc, int duration)
{
    struct GenericProc* gproc;

    gproc = SpawnProcLocking(ProcScr_TemporaryLock, proc);
    gproc->unk58 = duration;
}

void sub_8014BC8(struct GenericProc* proc)
{
    if (proc->unk58 == 0)
    {
        Proc_Break(proc);
        return;
    }

    proc->unk58--;
}

static char CONST_DATA sStrZero[] = "ÇO";
static char CONST_DATA sStrDash[] = "Å[";

int sub_8014BE4(int number, char* buf)
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

struct Text* sub_8014CA8(u16* tm, int color, int width, char const* str)
{
    struct Text* const text = &sText_03000420;

    InitText(text, width);

    Text_SetCursor(text, (width*8 - GetStringTextLen(str) - 1) / 2);
    Text_SetColor(text, color);
    Text_DrawString(text, str);

    PutText(text, tm);

    EnableBgSync(BG0_SYNC_BIT);

    return text;
}

struct Text* sub_8014D0C(u16* tm, int color, char const* str)
{
    struct Text* const text = &sText_03000420;

    InitText(text, (GetStringTextLen(str)+7) / 8);

    Text_SetColor(text, color);
    Text_DrawString(text, str);

    PutText(text, tm);

    return text;
}

struct UnkProc_085C4E64
{
    /* 00 */ PROC_HEADER;

    /* 2C */ u16 const* colors;
    /* 30 */ u16 palOffset;
    /* 32 */ u16 colorCount;
    /* 34 */ u16 clockEnd;
    /* 36 */ u16 clock;
    /* 38 */ u16 counter;
    /* 3A */ u16 reverseOrder;
};

void sub_8014DCC(struct UnkProc_085C4E64* proc);

struct ProcScr CONST_DATA ProcScr_085C4E64[] =
{
    PROC_REPEAT(sub_8014DCC),
};

void sub_8014D50(void)
{
    Proc_EndEach(ProcScr_085C4E64);
}

struct UnkProc_085C4E64* sub_8014D60(u16 const* colors, int palOffset, int palSize, int arg_3, ProcPtr parent)
{
    struct UnkProc_085C4E64* proc;

    proc = SpawnProc(ProcScr_085C4E64, parent);

    proc->colors = colors;
    proc->palOffset = palOffset;
    proc->colorCount = palSize / 2;
    proc->clock = arg_3;
    proc->clockEnd = arg_3;
    proc->counter = 0;
    proc->reverseOrder = 0;

    return proc;
}

void sub_8014D9C(u16 const* colors, int palOffset, int palSize, int arg_3, ProcPtr parent)
{
    sub_8014D60(colors, palOffset, palSize, arg_3, parent)->reverseOrder = 0;
}

void sub_8014DB4(u16 const* colors, int palOffset, int palSize, int arg_3, ProcPtr parent)
{
    sub_8014D60(colors, palOffset, palSize, arg_3, parent)->reverseOrder = 1;
}

void sub_8014DCC(struct UnkProc_085C4E64* proc)
{
    int colornum;

    proc->clock++;

    if (proc->clock < proc->clockEnd)
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

void sub_8014E30(u16* tm, int x, int y, u16 tileref, int width, int height)
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

#if NONMATCHING

void sub_8014E98(u16* tm, int x, int y, u16 tileref, int width, int height, u16 const* src, Bool hflip)
{
    int ix, iy;

    if (hflip)
    {
        for (iy = 0; iy < height; ++iy)
        {
            for (ix = 0; ix < width; ++ix)
            {
                if ((x+ix >= 0 && x+ix < 0x20) && (y+iy >= 0 && y+iy < 0x20))
                {
                    tm[TM_OFFSET(x+ix, y+iy)] = (src[TM_OFFSET(width-1-ix, iy)] + tileref) ^ TILE_HFLIP;
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
                    tm[TM_OFFSET(x+ix, y+iy)] = src[TM_OFFSET(ix, iy)] + tileref;
                }
            }
        }
    }
}

#else

NAKEDFUNC
void sub_8014E98(u16* tm, int x, int y, u16 tileref, int width, int height, u16 const* src, Bool hflip)
{
    asm("\
        .syntax unified\n\
        push {r4, r5, r6, r7, lr}\n\
        mov r7, sl\n\
        mov r6, sb\n\
        mov r5, r8\n\
        push {r5, r6, r7}\n\
        sub sp, #8\n\
        str r0, [sp]\n\
        adds r7, r1, #0\n\
        mov sl, r2\n\
        ldr r0, [sp, #0x28]\n\
        mov ip, r0\n\
        ldr r0, [sp, #0x34]\n\
        lsls r3, r3, #0x10\n\
        lsrs r3, r3, #0x10\n\
        mov sb, r3\n\
        ldr r1, [sp, #0x30]\n\
        str r1, [sp, #4]\n\
        lsls r0, r0, #0x18\n\
        cmp r0, #0\n\
        beq _08014F18\n\
        movs r5, #0\n\
        ldr r2, [sp, #0x2c]\n\
        cmp r5, r2\n\
        bge _08014F60\n\
    _08014EC8:\n\
        movs r2, #0\n\
        adds r6, r5, #1\n\
        cmp r2, ip\n\
        bge _08014F0E\n\
        lsls r3, r5, #6\n\
        movs r0, #0x80\n\
        lsls r0, r0, #3\n\
        mov r8, r0\n\
    _08014ED8:\n\
        adds r0, r7, r2\n\
        adds r4, r2, #1\n\
        cmp r0, #0x1f\n\
        bhi _08014F08\n\
        mov r2, sl\n\
        adds r1, r2, r5\n\
        cmp r1, #0x1f\n\
        bhi _08014F08\n\
        lsls r1, r1, #6\n\
        lsls r0, r0, #1\n\
        ldr r2, [sp]\n\
        adds r0, r0, r2\n\
        adds r1, r1, r0\n\
        mov r2, ip\n\
        subs r0, r2, r4\n\
        lsls r0, r0, #1\n\
        ldr r2, [sp, #4]\n\
        adds r0, r0, r2\n\
        adds r0, r3, r0\n\
        ldrh r0, [r0]\n\
        add r0, sb\n\
        mov r2, r8\n\
        eors r0, r2\n\
        strh r0, [r1]\n\
    _08014F08:\n\
        adds r2, r4, #0\n\
        cmp r2, ip\n\
        blt _08014ED8\n\
    _08014F0E:\n\
        adds r5, r6, #0\n\
        ldr r0, [sp, #0x2c]\n\
        cmp r5, r0\n\
        blt _08014EC8\n\
        b _08014F60\n\
    _08014F18:\n\
        movs r5, #0\n\
        ldr r1, [sp, #0x2c]\n\
        cmp r5, r1\n\
        bge _08014F60\n\
        lsls r2, r7, #1\n\
        mov r8, r2\n\
    _08014F24:\n\
        movs r2, #0\n\
        adds r6, r5, #1\n\
        cmp r2, ip\n\
        bge _08014F58\n\
        lsls r0, r5, #6\n\
        ldr r1, [sp, #4]\n\
        adds r4, r1, r0\n\
        ldr r3, [sp]\n\
        add r3, r8\n\
    _08014F36:\n\
        adds r0, r7, r2\n\
        cmp r0, #0x1f\n\
        bhi _08014F4E\n\
        mov r1, sl\n\
        adds r0, r1, r5\n\
        cmp r0, #0x1f\n\
        bhi _08014F4E\n\
        lsls r0, r0, #6\n\
        adds r0, r0, r3\n\
        ldrh r1, [r4]\n\
        add r1, sb\n\
        strh r1, [r0]\n\
    _08014F4E:\n\
        adds r4, #2\n\
        adds r3, #2\n\
        adds r2, #1\n\
        cmp r2, ip\n\
        blt _08014F36\n\
    _08014F58:\n\
        adds r5, r6, #0\n\
        ldr r2, [sp, #0x2c]\n\
        cmp r5, r2\n\
        blt _08014F24\n\
    _08014F60:\n\
        add sp, #8\n\
        pop {r3, r4, r5}\n\
        mov r8, r3\n\
        mov sb, r4\n\
        mov sl, r5\n\
        pop {r4, r5, r6, r7}\n\
        pop {r0}\n\
        bx r0\n\
        .syntax divided\n\
    ");
}

#endif // NONMATCHING

#if NONMATCHING

void sub_8014F70(u16* tm, int x, int y, u16 tileref, int width, int height, u16 const* src, int arg_7)
{
    int ix, iy;

    int r4 = Div(0x20, width);

    src = src + TM_OFFSET(width * DivRem(arg_7, r4), height * Div(arg_7, r4));

    for (iy = 0; iy < height; ++iy)
    {
        for (ix = 0; ix < width; ++ix)
        {
            if ((x+ix) < 0 || (x+ix) >= 0x20)
                continue;

            if ((y+iy) < 0 || (y+iy) >= 0x20)
                continue;

            tm[TM_OFFSET(x+ix, y+iy)] = src[TM_OFFSET(ix, iy)] + tileref;
        }
    }
}

#else

NAKEDFUNC
void sub_8014F70(u16* tm, int x, int y, u16 tileref, int width, int height, u16 const* src, int arg_7)
{
    asm("\
        .syntax unified\n\
        push {r4, r5, r6, r7, lr}\n\
        mov r7, sl\n\
        mov r6, sb\n\
        mov r5, r8\n\
        push {r5, r6, r7}\n\
        sub sp, #8\n\
        str r0, [sp]\n\
        mov sb, r1\n\
        str r2, [sp, #4]\n\
        ldr r7, [sp, #0x28]\n\
        ldr r5, [sp, #0x34]\n\
        lsls r3, r3, #0x10\n\
        lsrs r3, r3, #0x10\n\
        mov sl, r3\n\
        ldr r0, [sp, #0x30]\n\
        mov r8, r0\n\
        movs r0, #0x20\n\
        adds r1, r7, #0\n\
        bl Div\n\
        adds r4, r0, #0\n\
        adds r0, r5, #0\n\
        adds r1, r4, #0\n\
        bl Div\n\
        adds r6, r0, #0\n\
        adds r0, r5, #0\n\
        adds r1, r4, #0\n\
        bl DivRem\n\
        adds r1, r7, #0\n\
        muls r1, r0, r1\n\
        lsls r1, r1, #1\n\
        add r1, r8\n\
        ldr r2, [sp, #0x2c]\n\
        adds r0, r6, #0\n\
        muls r0, r2, r0\n\
        lsls r0, r0, #6\n\
        adds r1, r1, r0\n\
        mov r8, r1\n\
        movs r5, #0\n\
        cmp r5, r2\n\
        bge _0801500A\n\
        mov r0, sb\n\
        lsls r0, r0, #1\n\
        mov ip, r0\n\
    _08014FCC:\n\
        movs r4, #0\n\
        adds r6, r5, #1\n\
        cmp r4, r7\n\
        bge _08015002\n\
        lsls r0, r5, #6\n\
        mov r1, r8\n\
        adds r3, r1, r0\n\
        ldr r2, [sp]\n\
        add r2, ip\n\
    _08014FDE:\n\
        mov r1, sb\n\
        adds r0, r1, r4\n\
        cmp r0, #0x1f\n\
        bhi _08014FF8\n\
        ldr r1, [sp, #4]\n\
        adds r0, r1, r5\n\
        cmp r0, #0x1f\n\
        bhi _08014FF8\n\
        lsls r0, r0, #6\n\
        adds r0, r0, r2\n\
        ldrh r1, [r3]\n\
        add r1, sl\n\
        strh r1, [r0]\n\
    _08014FF8:\n\
        adds r3, #2\n\
        adds r2, #2\n\
        adds r4, #1\n\
        cmp r4, r7\n\
        blt _08014FDE\n\
    _08015002:\n\
        adds r5, r6, #0\n\
        ldr r2, [sp, #0x2c]\n\
        cmp r5, r2\n\
        blt _08014FCC\n\
    _0801500A:\n\
        add sp, #8\n\
        pop {r3, r4, r5}\n\
        mov r8, r3\n\
        mov sb, r4\n\
        mov sl, r5\n\
        pop {r4, r5, r6, r7}\n\
        pop {r0}\n\
        bx r0\n\
        .align 2, \n\
        .syntax divided\n\
    ");
}

#endif // NONMATCHING

#if NONMATCHING

void sub_801501C(u16* tm, int x, int y, u16 tileref, int width, int height, u16 const* src, int arg_7)
{
    int ix, iy;
    int r9;

    u16 const* srcb;

    int a, b;

    r9 = src[0] + 1;
    srcb = src + 1;

    a = Div(r9, width);
    b = Div(arg_7, a);

    srcb = srcb + width * (arg_7 - a * b) + ((b * height) << 5);

    for (iy = 0; iy < height; ++iy)
    {
        for (ix = 0; ix < width; ++ix)
        {
            if (!(x+ix >= 0 && x+ix < 0x20))
                continue;

            if (!(y+iy >= 0 && y+iy < 0x20))
                continue;

            tm[TM_OFFSET(x, y) + TM_OFFSET(ix, iy)] = srcb[r9 * ((height - 1 - iy)) + ix] + tileref;
        }
    }
}

#else

NAKEDFUNC
void sub_801501C(u16* tm, int x, int y, u16 tileref, int width, int height, u16 const* src, int arg_7)
{
    asm("\
        .syntax unified\n\
        push {r4, r5, r6, r7, lr}\n\
        mov r7, sl\n\
        mov r6, sb\n\
        mov r5, r8\n\
        push {r5, r6, r7}\n\
        sub sp, #0x14\n\
        str r0, [sp]\n\
        mov sl, r1\n\
        str r2, [sp, #4]\n\
        ldr r0, [sp, #0x34]\n\
        mov r8, r0\n\
        ldr r4, [sp, #0x40]\n\
        lsls r3, r3, #0x10\n\
        lsrs r3, r3, #0x10\n\
        str r3, [sp, #8]\n\
        ldr r1, [sp, #0x3c]\n\
        ldrb r2, [r1]\n\
        adds r2, #1\n\
        mov sb, r2\n\
        adds r1, #2\n\
        str r1, [sp, #0xc]\n\
        mov r0, sb\n\
        mov r1, r8\n\
        bl Div\n\
        adds r5, r0, #0\n\
        adds r0, r4, #0\n\
        adds r1, r5, #0\n\
        bl Div\n\
        adds r1, r5, #0\n\
        muls r1, r0, r1\n\
        subs r4, r4, r1\n\
        mov r1, r8\n\
        muls r1, r4, r1\n\
        lsls r1, r1, #1\n\
        ldr r6, [sp, #0xc]\n\
        adds r1, r6, r1\n\
        ldr r7, [sp, #0x38]\n\
        muls r0, r7, r0\n\
        lsls r0, r0, #6\n\
        adds r1, r1, r0\n\
        str r1, [sp, #0xc]\n\
        movs r5, #0\n\
        cmp r5, r7\n\
        bge _080150CC\n\
        mov r0, sl\n\
        lsls r0, r0, #1\n\
        mov ip, r0\n\
    _0801507E:\n\
        movs r4, #0\n\
        adds r1, r5, #1\n\
        str r1, [sp, #0x10]\n\
        cmp r4, r8\n\
        bge _080150C4\n\
        ldr r2, [sp, #0x38]\n\
        subs r0, r2, r5\n\
        subs r0, #1\n\
        mov r6, sb\n\
        muls r6, r0, r6\n\
        adds r0, r6, #0\n\
        lsls r0, r0, #1\n\
        ldr r7, [sp, #0xc]\n\
        adds r3, r7, r0\n\
        ldr r2, [sp]\n\
        add r2, ip\n\
    _0801509E:\n\
        mov r1, sl\n\
        adds r0, r1, r4\n\
        cmp r0, #0x1f\n\
        bhi _080150BA\n\
        ldr r6, [sp, #4]\n\
        adds r0, r6, r5\n\
        cmp r0, #0x1f\n\
        bhi _080150BA\n\
        lsls r0, r0, #6\n\
        adds r0, r0, r2\n\
        ldrh r7, [r3]\n\
        ldr r6, [sp, #8]\n\
        adds r1, r7, r6\n\
        strh r1, [r0]\n\
    _080150BA:\n\
        adds r3, #2\n\
        adds r2, #2\n\
        adds r4, #1\n\
        cmp r4, r8\n\
        blt _0801509E\n\
    _080150C4:\n\
        ldr r5, [sp, #0x10]\n\
        ldr r7, [sp, #0x38]\n\
        cmp r5, r7\n\
        blt _0801507E\n\
    _080150CC:\n\
        add sp, #0x14\n\
        pop {r3, r4, r5}\n\
        mov r8, r3\n\
        mov sb, r4\n\
        mov sl, r5\n\
        pop {r4, r5, r6, r7}\n\
        pop {r0}\n\
        bx r0\n\
        .syntax divided\n\
    ");
}

#endif // NONMATCHING

#if NONMATCHING

void sub_80150DC(u16* tm, int x, int y, u16 const* arg_3, u16 arg_4)
{
    u16 const* r2 = arg_3 + 1;

    int r9 = ((*(int*) arg_3) & 0x00FF);
    int r3 = ((*(int*) arg_3) & 0xFF00) >> 8;

    short i, j;

    for (i = r3; i >= 0; --i)
    {
        u16* r1;

        if (!(y+i >= 0 && y+i < 0x20))
            continue;

        r1 = tm + TM_OFFSET(x, y+i);

        for (j = r9; j >= 0; --j, r2++, r1++)
        {
            if (x+j >= 0 && x+j < 0x20)
                *r1 = *r2 + arg_4;
        }
    }
}

#else

NAKEDFUNC
void sub_80150DC(u16* tm, int x, int y, u16 const* arg_3, u16 arg_4)
{
    asm("\
        .syntax unified\n\
        push {r4, r5, r6, r7, lr}\n\
        mov r7, sb\n\
        mov r6, r8\n\
        push {r6, r7}\n\
        mov r8, r0\n\
        adds r5, r1, #0\n\
        mov ip, r2\n\
        ldr r0, [sp, #0x1c] @ arg_4\n\
        lsls r0, r0, #0x10\n\
        lsrs r6, r0, #0x10\n\
        adds r2, r3, #2\n\
        movs r1, #0xff\n\
        ldr r0, [r3]\n\
        ldrb r3, [r3]\n\
        mov sb, r3\n\
        lsrs r3, r0, #8\n\
        ands r3, r1\n\
        lsls r1, r3, #0x10\n\
        asrs r0, r1, #0x10\n\
        cmp r0, #0\n\
        blt _0801514A\n\
    _08015106:\n\
        asrs r0, r1, #0x10\n\
        add r0, ip\n\
        lsls r4, r3, #0x10\n\
        cmp r0, #0x1f\n\
        bhi _0801513E\n\
        lsls r0, r0, #5\n\
        adds r0, r5, r0\n\
        lsls r0, r0, #1\n\
        mov r3, r8\n\
        adds r1, r3, r0\n\
        mov r7, sb\n\
        lsls r3, r7, #0x10\n\
        asrs r0, r3, #0x10\n\
        cmp r0, #0\n\
        blt _0801513E\n\
    _08015124:\n\
        asrs r3, r3, #0x10\n\
        adds r0, r5, r3\n\
        cmp r0, #0x1f\n\
        bhi _08015132\n\
        ldrh r7, [r2]\n\
        adds r0, r7, r6\n\
        strh r0, [r1]\n\
    _08015132:\n\
        subs r0, r3, #1\n\
        adds r2, #2\n\
        adds r1, #2\n\
        lsls r3, r0, #0x10\n\
        cmp r3, #0\n\
        bge _08015124\n\
    _0801513E:\n\
        ldr r1, _08015158 @ =0xFFFF0000\n\
        adds r0, r4, r1\n\
        lsrs r3, r0, #0x10\n\
        lsls r1, r3, #0x10\n\
        cmp r1, #0\n\
        bge _08015106\n\
    _0801514A:\n\
        pop {r3, r4}\n\
        mov r8, r3\n\
        mov sb, r4\n\
        pop {r4, r5, r6, r7}\n\
        pop {r0}\n\
        bx r0\n\
        .align 2, 0\n\
    _08015158: .4byte 0xFFFF0000\n\
        .syntax divided\n\
    ");
}

#endif // NONMATCHING

struct UnkProc_085C4E6C
{
    /* 00 */ PROC_HEADER;

    /* 2C */ void(*func)();
    /* 30 */ int arg;
    /* 34 */ int clock;
};

void sub_801515C(struct UnkProc_085C4E6C* proc)
{
    proc->clock--;

    if (proc->clock == -1)
    {
        void(*func)(void) = (void(*)(void)) proc->func;

        func();
        Proc_Break(proc);
    }
}

void sub_8015180(struct UnkProc_085C4E6C* proc)
{
    proc->clock--;

    if (proc->clock == -1)
    {
        void(*func)(int) = (void(*)(int)) proc->func;

        func(proc->arg);
        Proc_Break(proc);
    }
}

struct ProcScr CONST_DATA ProcScr_Unk_085C4E6C[] =
{
    PROC_REPEAT(sub_801515C),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_085C4E7C[] =
{
    PROC_REPEAT(sub_8015180),
    PROC_END,
};

void sub_80151A8(void(*func)(void), int duration)
{
    struct UnkProc_085C4E6C* proc = SpawnProc(ProcScr_Unk_085C4E6C, PROC_TREE_3);

    proc->func = func;
    proc->clock = duration;
}

void sub_80151C4(void(*func)(int), int arg, int duration)
{
    struct UnkProc_085C4E6C* proc = SpawnProc(ProcScr_Unk_085C4E7C, PROC_TREE_3);

    proc->func = func;
    proc->arg = arg;
    proc->clock = duration;
}

void sub_80151E4(u8* out, int size)
{
    while (size > 0)
    {
        *out++ = 0;
        size--;
    }
}

void sub_80151F8(u8* out, int size, int value)
{
    while (size > 0)
    {
        *out++ = value;
        size--;
    }
}

void sub_8015208(u16* out, int size, int value)
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

u16 CONST_DATA Pal_085C4E8C[] = { RGB_16TIMES(0,  0,  0)  };
u16 CONST_DATA Pal_085C4EAC[] = { RGB_16TIMES(31, 31, 31) };
u16 CONST_DATA Pal_085C4ECC[] = { RGB_16TIMES(31, 0,  0)  };
u16 CONST_DATA Pal_085C4EEC[] = { RGB_16TIMES(0,  31, 0)  };
u16 CONST_DATA Pal_085C4F0C[] = { RGB_16TIMES(0,  0,  31) };
u16 CONST_DATA Pal_085C4F2C[] = { RGB_16TIMES(30, 31, 1)  };

#undef RGB_16TIMES

void sub_801523C(struct GenericProc* proc);

struct ProcScr CONST_DATA ProcScr_Unk_085C4F4C[] =
{
    PROC_REPEAT(sub_801523C),
    PROC_END,
};

void sub_8015218(ProcPtr proc)
{
    struct GenericProc* gproc;

    gproc = SpawnProcLocking(ProcScr_Unk_085C4F4C, proc);
    gproc->unk64 = GetGameLogicLock();
}

void sub_801523C(struct GenericProc* proc)
{
    if (GetGameLogicLock() == proc->unk64)
        Proc_Break(proc);
}

void sub_8015260(u8 const* src, u8* dst, int size)
{
    if ((size & 0x1F) != 0)
        CpuCopy16(src, dst, size);
    else
        CpuFastCopy(src, dst, size);
}

void sub_8015298(u8 const* src, u8* dst, int width, int height)
{
    int i, lineSize = width * CHR_SIZE;

    for (i = 0; i < height; ++i)
    {
        sub_8015260(src, dst, lineSize);

        src += lineSize;
        dst += 0x20 * CHR_SIZE;
    }
}

void sub_80152C4(u16 const* src, u16* dst, int size, u16 tileref)
{
    while (size > 0)
    {
        *dst++ = *src++ + tileref;
        size -= 2;
    }
}

u16* sub_80152E8(int bgid, int x, int y)
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

void sub_8015344(void)
{
    if (gDispIo.bg0Ct.colorMode == 0)
        sub_8015208((u16*) (VRAM + GetBgChrOffset(0)), 0x10, 0);

    if (gDispIo.bg1Ct.colorMode == 0)
        sub_8015208((u16*) (VRAM + GetBgChrOffset(1)), 0x10, 0);

    if (gDispIo.bg2Ct.colorMode == 0)
        sub_8015208((u16*) (VRAM + GetBgChrOffset(2)), 0x10, 0);

    if (gDispIo.bg3Ct.colorMode == 0)
        sub_8015208((u16*) (VRAM + GetBgChrOffset(3)), 0x10, 0);
}

int sub_80153CC(int arg_0)
{
    if (arg_0 < 0)
        return -0x60;

    if (arg_0 >= DISPLAY_WIDTH)
        return +0x5F;

    return Div(0xC0 * arg_0, DISPLAY_WIDTH) - 0x60;
}

void PlaySeSpacial(int song, int x)
{
    struct MusicPlayerInfo* mpi;

    PlaySE(song);

    mpi = gMPlayTable[gSongTable[song].ms].info;

    m4aMPlayImmInit(mpi);
    m4aMPlayPanpotControl(mpi, 0xFFFF, sub_80153CC(x));
}

static void sub_801546C(int song);

void sub_8015454(int song, int delay)
{
    sub_80151C4(sub_801546C, song, delay);
}

static void sub_801546C(int song)
{
    PlaySE(song);
}

void sub_801548C(short song)
{
    StartBgm(song, NULL);
}

void sub_801549C(short speed)
{
    FadeBgmOut(speed);
}

void sub_80154AC(int palid)
{
    int i;

    u16* pal = gPal + palid * 0x10;

    for (i = 0; i < 0x10; ++i)
    {
        int red   = ((pal[i] & (0x1F))       / 4) * 3;
        int green = ((pal[i] & (0x1F << 5))  / 4) * 3;
        int blue  = ((pal[i] & (0x1F << 10)) / 4) * 3;

        pal[i] = (red & (0x1F)) | (green & (0x1F << 5)) | (blue & (0x1F << 10));
    }
}

void sub_8015504(u8 const* src, u8* dst, int size)
{
    while (size != 0)
    {
        *dst = *src;

        dst++;
        src++;

        size--;
    }
}

void sub_801551C(struct Text* text, int x, int y, char const* str, int width)
{
    int off;

    off = GetStringTextLen(str);
    off = (width*8 - off) >> 1;

    Text_SetCursor(text, off);
    Text_DrawString(text, str);

    PutText(text, gBg0Tm + TM_OFFSET(x, y));
}

void sub_801556C(int const* vec, int const* mat, int* ovec)
{
    ovec[0] = ((vec[0] * mat[0]) + (vec[1] * mat[3]) + (vec[2] * mat[6])) >> 12;
    ovec[1] = ((vec[0] * mat[1]) + (vec[1] * mat[4]) + (vec[2] * mat[7])) >> 12;
    ovec[2] = ((vec[0] * mat[2]) + (vec[1] * mat[5]) + (vec[2] * mat[8])) >> 12;
}

void sub_80155B8(int const* lmat, int const* rmat, int* omat)
{
    int tmpmat[12];
    int* mat;

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
        sub_8015748(tmpmat, omat);
}

void sub_8015728(int* mat)
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

void sub_8015748(int const* src, int* dst)
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

void sub_801577C(int* mat, short angle)
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

void sub_80157C8(int* mat, short angle)
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

void sub_8015810(int* mat, short angle)
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

void nullsub_15(void)
{
}

int sub_801585C(int const* lvec, int const* rvec)
{
    return ((lvec[0] * rvec[0]) + (lvec[1] * rvec[1]) + (lvec[2] * rvec[2])) >> 12;
}

void sub_8015880(int const* lvec, int const* rvec, int* ovec)
{
    ovec[0] = (lvec[1] * rvec[2] - lvec[2] * rvec[1]) >> 12;
    ovec[1] = (lvec[2] * rvec[0] - lvec[0] * rvec[2]) >> 12;
    ovec[2] = (lvec[0] * rvec[1] - lvec[1] * rvec[0]) >> 12;
}

int sub_80158B8(int arg_0, int arg_1, int arg_2, int arg_3)
{
    return arg_3 * arg_0 - arg_2 * arg_1;
}
