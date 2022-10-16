#include "common.h"

#include "hardware.h"
#include "proc.h"
#include "text.h"
#include "util.h"
#include "unit.h"
#include "bm.h"
#include "mu.h"
#include "helpbox.h"

#include "constants/videoalloc_global.h"

extern u16 const Pal_LinkArenaMuralBackground[];
extern u16 const Pal_MuralBackground[];
extern u8 const Img_MuralBackground[];

extern struct ProcScr CONST_DATA ProcScr_BackgroundSlide[];

enum
{
    STATSCREEN_TEXT_PNAME = 0,
    STATSCREEN_TEXT_JNAME = 1,
    STATSCREEN_TEXT_2 = 2,
    STATSCREEN_TEXT_3 = 3,
    STATSCREEN_TEXT_4 = 4,
    STATSCREEN_TEXT_5 = 5,
    STATSCREEN_TEXT_6 = 6,
    STATSCREEN_TEXT_7 = 7,
    STATSCREEN_TEXT_8 = 8,
    STATSCREEN_TEXT_9 = 9,
    STATSCREEN_TEXT_10 = 10,
    STATSCREEN_TEXT_11 = 11,
    STATSCREEN_TEXT_12 = 12,
    STATSCREEN_TEXT_13 = 13,
    STATSCREEN_TEXT_14 = 14,
    STATSCREEN_TEXT_15 = 15,
    STATSCREEN_TEXT_16 = 16,
    STATSCREEN_TEXT_17 = 17,
    STATSCREEN_TEXT_18 = 18,
    STATSCREEN_TEXT_19 = 19,
    STATSCREEN_TEXT_20 = 20,
    STATSCREEN_TEXT_21 = 21,
    STATSCREEN_TEXT_22 = 22,
    STATSCREEN_TEXT_23 = 23,
    STATSCREEN_TEXT_24 = 24,
    STATSCREEN_TEXT_25 = 25,
    STATSCREEN_TEXT_26 = 26,
    STATSCREEN_TEXT_27 = 27,
    STATSCREEN_TEXT_28 = 28,
    STATSCREEN_TEXT_29 = 29,
    STATSCREEN_TEXT_30 = 30,
    STATSCREEN_TEXT_31 = 31,
    STATSCREEN_TEXT_32 = 32,
    STATSCREEN_TEXT_33 = 33,
    STATSCREEN_TEXT_BWL = 34,

    MAX_STATSCREEN_TEXT,
};

// TODO: rename (the use of "Info" in this name doesn't fit convention used elsewhere in the source)
// ("Info" should refer to something const)
struct StatScreenInfo
{
    /* 00 */ u8 unk_00;
    /* 01 */ u8 unit_id;
    /* 02 */ u16 flags;
};

struct StatScreenSt
{
    /* 00 */ u8 page;
    /* 01 */ u8 page_count;
    /* 02 */ u16 page_slide_key;
    /* 04 */ i16 x_disp_off; // Note: Always 0, not properly taked into account by most things
    /* 06 */ i16 y_disp_off;
    /* 08 */ bool is_transitioning;
    /* 0C */ struct Unit * unit;
    /* 10 */ struct MuProc * mu;
    /* 14 */ struct HelpBoxInfo const * help;
    /* 18 */ struct Text text[MAX_STATSCREEN_TEXT];
};

struct StatScreenTextInfo
{
    /* 00 */ struct Text * text;
    /* 04 */ u16 * tm;
    /* 08 */ u8 color;
    /* 09 */ u8 x_offset;
    /* 0C */ char const * const * str_list;
};

struct MuralBackgroundProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ u8 pad_29[0x4C - 0x29];
    /* 4C */ i16 offset;
};

struct StatScreenInfo EWRAM_DATA gStatScreenInfo = { 0 };
extern struct StatScreenSt gStatScreenSt; // TODO: ewram overlay

void func_fe6_0806E83C(u8 * bitmap, int pixels_per_line, int n)
{
    bitmap[1 * pixels_per_line + n] = 4;
    bitmap[2 * pixels_per_line + n] = 14;
    bitmap[3 * pixels_per_line + n] = 3;
}

void func_fe6_0806E860(u8 * bitmap, int pixels_per_line, int n)
{
    bitmap[0 * pixels_per_line + n] = 4;
    bitmap[1 * pixels_per_line + n] = 14;
    bitmap[2 * pixels_per_line + n] = 14;
    bitmap[3 * pixels_per_line + n] = 14;
    bitmap[4 * pixels_per_line + n] = 3;
}

void func_fe6_0806E890(u8 * bitmap, int pixels_per_line, int n)
{
    bitmap[1 * pixels_per_line + n] = 1;
    bitmap[2 * pixels_per_line + n] = 5;
}

void func_fe6_0806E8AC(u8 * bitmap, int pixels_per_line, int n)
{
    bitmap[1 * pixels_per_line + n] = 13;
    bitmap[2 * pixels_per_line + n] = 12;
}

void func_fe6_0806E8C8(int chr, int dot_x, int chr_count, int dot_width, int dot_plain, int dot_bonus)
{
    int i;

    u8 * bitmap = gBuf;

    CpuFastFill(0, bitmap, chr_count * 8 * 8);

    func_fe6_0806E83C(bitmap, chr_count * 8, dot_x);
    func_fe6_0806E83C(bitmap, chr_count * 8, dot_x + dot_width + 3);

    for (i = 0; i < dot_width + 2; i++)
    {
        func_fe6_0806E860(bitmap, chr_count * 8, i + 1 + dot_x);
    }

    for (i = 0; i < dot_plain; i++)
    {
        func_fe6_0806E890(bitmap, chr_count * 8, i + 2 + dot_x);
    }

    for (i = 0; i < dot_bonus; i++)
    {
        func_fe6_0806E8AC(bitmap, chr_count * 8, dot_plain + i + 2 + dot_x);
    }

    Bitmap2Chr(bitmap, ((void *) VRAM) + chr * CHR_SIZE, chr_count, 1);
}

void func_fe6_0806E998(int chr, int width, u16 * tm, int tileref, int dot_width, int dot_plain, int dot_bonus)
{
    func_fe6_0806E8C8(chr, 2, width, dot_width, dot_plain, dot_bonus);

    tileref += chr & 0x3FF; // TODO: macro?
    PutIncrTileref(tm, tileref, width, 1);
}

void BackgroundSlide_Init(struct MuralBackgroundProc * proc)
{
    proc->offset = 0;
}

void BackgroundSlide_Loop(struct MuralBackgroundProc * proc)
{
    proc->offset++;

    SetBgOffset(3, proc->offset / 4, 0);
    REG_BG3HOFS = proc->offset / 4;
}

struct ProcScr CONST_DATA ProcScr_BackgroundSlide[] =
{
    PROC_CALL(BackgroundSlide_Init),
    PROC_REPEAT(BackgroundSlide_Loop),
    PROC_END,
};

ProcPtr StartMuralBackground(ProcPtr parent, void * vram, int pal)
{
    int i, tileref;
    u16 * tm = gBg3Tm;

    if (vram == NULL)
        vram = ((void*) VRAM) + GetBgChrOffset(3);

    if (pal < 0)
        pal = BGPAL_MURALBACKGROUND;

    if (gBmSt.flags & BM_FLAG_LINKARENA)
        ApplyPalettes(Pal_LinkArenaMuralBackground, pal, 2);
    else
        ApplyPalettes(Pal_MuralBackground, pal, 2);

    Decompress(Img_MuralBackground, vram);

    tileref = ((((uptr) (vram - GetBgChrOffset(3))) / CHR_SIZE) & 0xFFF) + TILE_PAL_SAFE(pal);

    // TODO: constant
    for (i = 0; i < 0x280; i++)
        *tm++ = i + tileref;

    return SpawnProc(ProcScr_BackgroundSlide, parent);
}

void EndMuralBackground(void)
{
    Proc_EndEach(ProcScr_BackgroundSlide);
}

int func_fe6_0806EACC(void)
{
    return gStatScreenInfo.unit_id;
}

void func_fe6_0806EAD8(int unit_id)
{
    gStatScreenInfo.unit_id = unit_id;
}

void func_fe6_0806EAE4(int flags)
{
    gStatScreenInfo.flags = flags;
}

struct TextInitInfo CONST_DATA gStatScreenTextList[] =
{
    { gStatScreenSt.text + STATSCREEN_TEXT_PNAME,  7 },
    { gStatScreenSt.text + STATSCREEN_TEXT_JNAME,  7 },
    { gStatScreenSt.text + STATSCREEN_TEXT_2,   3 },
    { gStatScreenSt.text + STATSCREEN_TEXT_3,   3 },
    { gStatScreenSt.text + STATSCREEN_TEXT_4,   3 },
    { gStatScreenSt.text + STATSCREEN_TEXT_5,   3 },
    { gStatScreenSt.text + STATSCREEN_TEXT_6,   3 },
    { gStatScreenSt.text + STATSCREEN_TEXT_7,   3 },
    { gStatScreenSt.text + STATSCREEN_TEXT_8,   3 },
    { gStatScreenSt.text + STATSCREEN_TEXT_9,   3 },
    { gStatScreenSt.text + STATSCREEN_TEXT_10,  3 },
    { gStatScreenSt.text + STATSCREEN_TEXT_11,  3 },
    { gStatScreenSt.text + STATSCREEN_TEXT_12,  9 },
    { gStatScreenSt.text + STATSCREEN_TEXT_13,  7 },
    { gStatScreenSt.text + STATSCREEN_TEXT_14,  9 },
    { gStatScreenSt.text + STATSCREEN_TEXT_15,  7 },
    { gStatScreenSt.text + STATSCREEN_TEXT_16,  7 },
    { gStatScreenSt.text + STATSCREEN_TEXT_17,  7 },
    { gStatScreenSt.text + STATSCREEN_TEXT_18,  7 },
    { gStatScreenSt.text + STATSCREEN_TEXT_19,  7 },
    { gStatScreenSt.text + STATSCREEN_TEXT_20,  6 },
    { gStatScreenSt.text + STATSCREEN_TEXT_21,  3 },
    { gStatScreenSt.text + STATSCREEN_TEXT_22,  3 },
    { gStatScreenSt.text + STATSCREEN_TEXT_23,  3 },
    { gStatScreenSt.text + STATSCREEN_TEXT_24,  3 },
    { gStatScreenSt.text + STATSCREEN_TEXT_25,  2 },
    { gStatScreenSt.text + STATSCREEN_TEXT_26,  2 },
    { gStatScreenSt.text + STATSCREEN_TEXT_27,  2 },
    { gStatScreenSt.text + STATSCREEN_TEXT_28,  2 },
    { gStatScreenSt.text + STATSCREEN_TEXT_29,  7 },
    { gStatScreenSt.text + STATSCREEN_TEXT_30,  7 },
    { gStatScreenSt.text + STATSCREEN_TEXT_31,  7 },
    { gStatScreenSt.text + STATSCREEN_TEXT_32,  7 },
    { gStatScreenSt.text + STATSCREEN_TEXT_33,  7 },
    { gStatScreenSt.text + STATSCREEN_TEXT_BWL, 16 },

    { 0 }, // end!
};

void func_fe6_0806EAF0(void)
{
    InitTextList(gStatScreenTextList);
}

void func_fe6_0806EB00(struct StatScreenTextInfo const * list)
{
    while (list->text != NULL)
    {
        if (list->str_list != NULL)
        {
            PutDrawText(list->text, list->tm, list->color, list->x_offset, 0, list->str_list[GetLang()]);
        }
        else
        {
            PutText(list->text, list->tm);
        }

        list++;
    }
}

/*

*/
