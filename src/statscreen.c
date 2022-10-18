#include "common.h"

#include <stdlib.h>

#include "armfunc.h"
#include "hardware.h"
#include "oam.h"
#include "sound.h"
#include "proc.h"
#include "icon.h"
#include "sprite.h"
#include "text.h"
#include "msg.h"
#include "util.h"
#include "item.h"
#include "unit.h"
#include "bm.h"
#include "battle.h"
#include "support.h"
#include "mu.h"
#include "helpbox.h"

#include "constants/videoalloc_global.h"
#include "constants/songs.h"

extern u16 const Pal_LinkArenaMuralBackground[];
extern u16 const Pal_MuralBackground[];
extern u8 const Img_MuralBackground[];
extern u16 const Pal_Unk_083087C8[][0x20];

extern u8 const gUnk_08307D58[]; // tsa (compressed): statscreen page A frame
extern u8 const gUnk_08307DD4[]; // tsa (compressed): statscreen page B frame
extern u8 const gUnk_08307E50[]; // tsa (compressed): statscreen page C frame
extern u8 const gUnk_08308070[]; // tsa (compressed): statscreen page B battle stat box
extern u8 const gUnk_083080AC[]; // tsa: statscreen page B equipped weapon background

extern struct ProcScr CONST_DATA ProcScr_BackgroundSlide[];

extern struct StatScreenTextInfo const gUnk_083193EC[]; // statscreen page A text
extern struct StatScreenTextInfo const gUnk_083194AC[]; // statscreen page B text
extern struct StatScreenTextInfo const gUnk_0831950C[]; // statscreen page C text (physical unit)
extern struct StatScreenTextInfo const gUnk_0831955C[]; // statscreen page C text (magical unit)

extern char const gUnk_083195AC[]; // magic label string literal
extern char const gUnk_083195B4[]; // strength label string literal

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
    /* 02 */ u16 excluded_unit_flags;
};

struct StatScreenSt
{
    /* 00 */ u8 page;
    /* 01 */ u8 page_count;
    /* 02 */ u16 page_slide_key_bit;
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

struct StatScreenPageSlideProc
{
    /* 00 */ PROC_HEADER;

    /* 29 */ u8 pad_29[0x4A - 0x29];
    /* 4A */ i16 new_page;
    /* 4C */ i16 clock;
    /* 4E */ u8 pad_4E[0x52 - 0x4E];
    /* 52 */ u16 key_bit;
};

struct StatScreenUnitSlideProc
{
    /* 00 */ PROC_HEADER;

    /* 29 */ u8 pad_29[0x38 - 0x29];
    /* 38 */ i32 direction;
    /* 3C */ i32 y_disp_init;
    /* 40 */ i32 y_disp_fini;
    /* 44 */ u8 pad_44[0x4A - 0x44];
    /* 4A */ i16 new_unit_id;
    /* 4C */ i16 clock;
};

struct StatScreenPageNameProc
{
    /* 00 */ PROC_HEADER;

    // number sprite proc only
    /* 2A */ i16 x_left;
    /* 2C */ i16 x_right;
    /* 2E */ u16 clock_left;
    /* 30 */ u16 clock_right;
    /* 32 */ i16 anim_speed_left;
    /* 34 */ i16 anim_speed_right;

    // name sprite proc only
    /* 36 */ u8 page_id;
    /* 38 */ i16 vertical_scale; // int 6 == 1:1 (1.0) scale
};

struct StatScreenInfo EWRAM_DATA gStatScreenInfo = { 0 };
extern struct StatScreenSt gStatScreenSt; // TODO: ewram overlay

void DrawUiGaugeBitmapEdgeColumn(u8 * bitmap, int pixels_per_line, int column)
{
    bitmap[1 * pixels_per_line + column] = 4;
    bitmap[2 * pixels_per_line + column] = 14;
    bitmap[3 * pixels_per_line + column] = 3;
}

void DrawUiGaugeBitmapBaseColumn(u8 * bitmap, int pixels_per_line, int column)
{
    bitmap[0 * pixels_per_line + column] = 4;
    bitmap[1 * pixels_per_line + column] = 14;
    bitmap[2 * pixels_per_line + column] = 14;
    bitmap[3 * pixels_per_line + column] = 14;
    bitmap[4 * pixels_per_line + column] = 3;
}

void DrawUiGaugeBitmapFilledColumn(u8 * bitmap, int pixels_per_line, int column)
{
    bitmap[1 * pixels_per_line + column] = 1;
    bitmap[2 * pixels_per_line + column] = 5;
}

void DrawUiGaugeBitmapBonusColumn(u8 * bitmap, int pixels_per_line, int column)
{
    bitmap[1 * pixels_per_line + column] = 13;
    bitmap[2 * pixels_per_line + column] = 12;
}

void DrawUiGauge(int chr, int dot_x, int chr_count, int dot_width, int dot_plain, int dot_bonus)
{
    int i;

    u8 * bitmap = gBuf;

    CpuFastFill(0, bitmap, chr_count * 8 * 8);

    DrawUiGaugeBitmapEdgeColumn(bitmap, chr_count * 8, dot_x);
    DrawUiGaugeBitmapEdgeColumn(bitmap, chr_count * 8, dot_x + dot_width + 3);

    for (i = 0; i < dot_width + 2; i++)
    {
        DrawUiGaugeBitmapBaseColumn(bitmap, chr_count * 8, i + 1 + dot_x);
    }

    for (i = 0; i < dot_plain; i++)
    {
        DrawUiGaugeBitmapFilledColumn(bitmap, chr_count * 8, i + 2 + dot_x);
    }

    for (i = 0; i < dot_bonus; i++)
    {
        DrawUiGaugeBitmapBonusColumn(bitmap, chr_count * 8, dot_plain + i + 2 + dot_x);
    }

    ApplyBitmap(bitmap, ((void *) VRAM) + chr * CHR_SIZE, chr_count, 1);
}

void PutDrawUiGauge(int chr, int width, u16 * tm, int tileref, int dot_width, int dot_plain, int dot_bonus)
{
    DrawUiGauge(chr, 2, width, dot_width, dot_plain, dot_bonus);

    tileref += chr & 0x3FF; // TODO: macro?
    PutAppliedBitmap(tm, tileref, width, 1);
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
    gStatScreenInfo.excluded_unit_flags = flags;
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

void func_fe6_0806EB48(void)
{
    char const * pname_str = DecodeMsg(gStatScreenSt.unit->pinfo->msg_name);
    int pname_text_x = GetStringTextCenteredPos(8 * 7, pname_str);

    TmFill(gBg0Tm, 0);

    BattleGenerateDisplayStats(gStatScreenSt.unit, GetUnitEquippedWeaponSlot(gStatScreenSt.unit));

    // display pname & jname

    PutDrawText(gStatScreenSt.text + STATSCREEN_TEXT_PNAME,
        gBg0Tm + TM_OFFSET(4, 10), TEXT_COLOR_SYSTEM_WHITE, pname_text_x, 0, pname_str);

    PutDrawText(gStatScreenSt.text + STATSCREEN_TEXT_JNAME,
        gBg0Tm + TM_OFFSET(1, 13), TEXT_COLOR_SYSTEM_WHITE, 0, 0, DecodeMsg(gStatScreenSt.unit->jinfo->msg_name));

    // display level, exp, hp

    PutTwoSpecialChar(gBg0Tm + TM_OFFSET(1, 15), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_LV_A, TEXT_SPECIAL_LV_B);
    PutSpecialChar(gBg0Tm + TM_OFFSET(5, 15), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_K);

    PutTwoSpecialChar(gBg0Tm + TM_OFFSET(1, 17), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_HP_A, TEXT_SPECIAL_HP_B);
    PutSpecialChar(gBg0Tm + TM_OFFSET(5, 17), TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_SLASH);

    PutNumberOrBlank(gBg0Tm + TM_OFFSET(4, 15), TEXT_COLOR_SYSTEM_BLUE, gStatScreenSt.unit->level);
    PutNumberOrBlank(gBg0Tm + TM_OFFSET(7, 15), TEXT_COLOR_SYSTEM_BLUE, gStatScreenSt.unit->exp);

    PutNumberOrBlank(gBg0Tm + TM_OFFSET(4, 17), TEXT_COLOR_SYSTEM_BLUE, GetUnitCurrentHp(gStatScreenSt.unit));
    PutNumberOrBlank(gBg0Tm + TM_OFFSET(7, 17), TEXT_COLOR_SYSTEM_BLUE, GetUnitMaxHp(gStatScreenSt.unit));
}

void PutStatScreenStatWithBar(int num, int x, int y, int base, int total, int max)
{
    int bonus = total - base;

    PutNumberOrBlank(gUnk_Tm_02003238 + TM_OFFSET(x, y),
        (base == max) ? TEXT_COLOR_SYSTEM_GREEN : TEXT_COLOR_SYSTEM_BLUE, base);

    PutNumberBonus(bonus, gUnk_Tm_02003238 + TM_OFFSET(x + 1, y));

    if (total > 30)
    {
        total = 30;
        bonus = total - base;
    }

    PutDrawUiGauge(0x401 + num*6, 6,
        gUnk_Tm_02003C38 + TM_OFFSET(x - 2, y + 1),
        TILEREF(0, BGPAL_STATSCREEN_6), max * 41 / 30, base * 41 / 30, bonus * 41 / 30);
}

void func_fe6_0806ED34(void)
{
    Decompress(gUnk_08307D58, gBuf);
    TmApplyTsa_t(gUnk_Tm_02003738, gBuf, TILEREF(BGCHR_WINDOW_FRAME, BGPAL_WINDOW_FRAME));

    func_fe6_0806EB00(gUnk_083193EC);

    // display strength/magic labels

    if (UnitKnowsMagic(gStatScreenSt.unit))
    {
        // magic
        PutDrawText(gStatScreenSt.text + STATSCREEN_TEXT_3,
            gUnk_Tm_02003238 + TM_OFFSET(1, 1),
            TEXT_COLOR_SYSTEM_GOLD, 0, 0,
            gUnk_083195AC); // TODO: string literal
    }
    else
    {
        // strength
        PutDrawText(gStatScreenSt.text + STATSCREEN_TEXT_3,
            gUnk_Tm_02003238 + TM_OFFSET(1, 1),
            TEXT_COLOR_SYSTEM_GOLD, 4, 0,
            gUnk_083195B4); // TODO: string literal
    }

    // display strength/magic stat value
    PutStatScreenStatWithBar(0, 5, 1,
        gStatScreenSt.unit->pow,
        GetUnitPower(gStatScreenSt.unit),
        UNIT_POW_CAP(gStatScreenSt.unit));

    // display skill stat value
    PutStatScreenStatWithBar(1, 5, 3,
        gStatScreenSt.unit->flags & UNIT_FLAG_RESCUING
            ? gStatScreenSt.unit->skl / 2 : gStatScreenSt.unit->skl,
        GetUnitSkill(gStatScreenSt.unit),
        gStatScreenSt.unit->flags & UNIT_FLAG_RESCUING
            ? UNIT_SKL_CAP(gStatScreenSt.unit) / 2 : UNIT_SKL_CAP(gStatScreenSt.unit));

    // display speed stat value
    PutStatScreenStatWithBar(2, 5, 5,
        gStatScreenSt.unit->flags & UNIT_FLAG_RESCUING
            ? gStatScreenSt.unit->spd/2 : gStatScreenSt.unit->spd,
        GetUnitSpeed(gStatScreenSt.unit),
        gStatScreenSt.unit->flags & UNIT_FLAG_RESCUING
            ? UNIT_SPD_CAP(gStatScreenSt.unit) / 2 : UNIT_SPD_CAP(gStatScreenSt.unit));

    // display luck stat value
    PutStatScreenStatWithBar(3, 5, 7,
        gStatScreenSt.unit->lck,
        GetUnitLuck(gStatScreenSt.unit),
        UNIT_LCK_CAP(gStatScreenSt.unit));

    // display defense stat value
    PutStatScreenStatWithBar(4, 5, 9,
        gStatScreenSt.unit->def,
        GetUnitDefense(gStatScreenSt.unit),
        UNIT_DEF_CAP(gStatScreenSt.unit));

    // display resistance stat value
    PutStatScreenStatWithBar(5, 5, 11,
        gStatScreenSt.unit->res,
        GetUnitResistance(gStatScreenSt.unit),
        UNIT_RES_CAP(gStatScreenSt.unit));

    // display movement stat value
    PutStatScreenStatWithBar(6, 13, 1,
        UNIT_MOV_BASE(gStatScreenSt.unit),
        UNIT_MOV(gStatScreenSt.unit),
        UNIT_MOV_CAP(gStatScreenSt.unit));

    // display constitution stat value
    PutStatScreenStatWithBar(7, 13, 3,
        UNIT_CON_BASE(gStatScreenSt.unit),
        UNIT_CON(gStatScreenSt.unit),
        UNIT_CON_CAP(gStatScreenSt.unit));

    // display unit aid
    PutNumber(gUnk_Tm_02003238 + TM_OFFSET(13, 5), TEXT_COLOR_SYSTEM_BLUE,
        GetUnitAid(gStatScreenSt.unit));

    // display unit aid icon
    PutIcon(gUnk_Tm_02003238 + TM_OFFSET(14, 5),
        GetAidIconFromAttributes(UNIT_ATTRIBUTES(gStatScreenSt.unit)),
        TILEREF(0, BGPAL_ICONS + 1));

    // display unit rescue name
    Text_InsertDrawString(gStatScreenSt.text + STATSCREEN_TEXT_12,
        24, TEXT_COLOR_SYSTEM_BLUE,
        GetUnitRescueName(gStatScreenSt.unit));

    // display status name
    Text_InsertDrawString(gStatScreenSt.text + STATSCREEN_TEXT_14,
        24, TEXT_COLOR_SYSTEM_BLUE,
        GetUnitStatusName(gStatScreenSt.unit));

    // display status turns

    if (gStatScreenSt.unit->status != UNIT_STATUS_NONE)
    {
        PutNumberSmall(gUnk_Tm_02003238 + TM_OFFSET(16, 11),
            TEXT_COLOR_SYSTEM_WHITE,
            gStatScreenSt.unit->status_duration);
    }

    // display affininity icon and name

    PutIcon(gUnk_Tm_02003238 + TM_OFFSET(12, 9),
        GetUnitAffinityIcon(gStatScreenSt.unit),
        TILEREF(0, BGPAL_ICONS + 1));

    Text_InsertDrawString(gStatScreenSt.text + STATSCREEN_TEXT_13,
        40, TEXT_COLOR_SYSTEM_BLUE, GetAffinityName(gStatScreenSt.unit->pinfo->affinity));
}

void func_fe6_0806EFE0(void)
{
    int i, item;

    Decompress(gUnk_08307DD4, gBuf);
    TmApplyTsa_t(gUnk_Tm_02003738, gBuf, TILEREF(BGCHR_WINDOW_FRAME, BGPAL_WINDOW_FRAME));

    Decompress(gUnk_08308070, gBuf);
    TmApplyTsa_t(gUnk_Tm_02003C38 + TM_OFFSET(1, 11), gBuf, TILEREF(BGCHR_STATSCREEN_60, BGPAL_STATSCREEN_7));

    func_fe6_0806EB00(gUnk_083194AC);

    for (i = 0; (i < ITEMSLOT_INV_COUNT) && (item = gStatScreenSt.unit->items[i]); i++)
    {
        func_fe6_08016860(gStatScreenSt.text + STATSCREEN_TEXT_15 + i,
            item, IsItemDisplayUseable(gStatScreenSt.unit, item),
            gUnk_Tm_02003238 + TM_OFFSET(1, 1 + i * 2));
    }

    i = GetUnitEquippedWeaponSlot(gStatScreenSt.unit);
    item = 0;

    if (i >= 0)
    {
        PutSpecialChar(
            gUnk_Tm_02003238 + TM_OFFSET(16, 1 + i * 2),
            0, TEXT_SPECIAL_K);

        TmApplyTsa_t(
            gUnk_Tm_02003C38 + TM_OFFSET(1, 2 + i * 2),
            gUnk_083080AC, TILEREF(BGCHR_STATSCREEN_60, BGPAL_STATSCREEN_7));

        item = gStatScreenSt.unit->items[i];
    }

    PutNumberOrBlank(gUnk_Tm_02003238 + TM_OFFSET(8,  13),
        TEXT_COLOR_SYSTEM_BLUE, gBattleUnitA.battle_attack);

    PutNumberOrBlank(gUnk_Tm_02003238 + TM_OFFSET(8,  15),
        TEXT_COLOR_SYSTEM_BLUE, gBattleUnitA.battle_hit);

    PutNumberOrBlank(gUnk_Tm_02003238 + TM_OFFSET(15, 13),
        TEXT_COLOR_SYSTEM_BLUE, gBattleUnitA.battle_crit);

    PutNumberOrBlank(gUnk_Tm_02003238 + TM_OFFSET(15, 15),
        TEXT_COLOR_SYSTEM_BLUE, gBattleUnitA.battle_avoid);

    Text_InsertDrawString(gStatScreenSt.text + STATSCREEN_TEXT_20,
        16, TEXT_COLOR_SYSTEM_BLUE, GetItemRangeString(item));

    for (i = 0; i < 8; ++i)
    {
        gUnk_Tm_02003238[TM_OFFSET(2 + i, 11)] = TILEREF(0x278 + i, BGPAL_ICONS + 1);
        gUnk_Tm_02003238[TM_OFFSET(2 + i, 12)] = TILEREF(0x270 + i, BGPAL_ICONS + 1);
    }
}

void PutStatScreenSupportList(void)
{
    int count, i;

    int y_tm = 6;
    int line = 0;

    int text_color = GetUnitTotalSupportLevel(gStatScreenSt.unit) == MAX_SIMULTANEOUS_SUPPORT_COUNT_PER_UNIT
        ? TEXT_COLOR_SYSTEM_GREEN : TEXT_COLOR_SYSTEM_WHITE;

    for (count = GetUnitSupportCount(gStatScreenSt.unit), i = 0; i < count; i++)
    {
        int support_level = GetUnitSupportLevel(gStatScreenSt.unit, i);

        if (support_level != 0)
        {
            int rank_color;

            u8 pid = GetUnitSupportPid(gStatScreenSt.unit, i);

            PutIcon(gUnk_Tm_02003238 + TM_OFFSET(4, y_tm),
                GetAffinityIconByPid(pid),
                TILEREF(0, BGPAL_ICONS + 1));

            PutDrawText(gStatScreenSt.text + STATSCREEN_TEXT_29 + line,
                gUnk_Tm_02003238 + TM_OFFSET(7, y_tm),
                text_color, 0, 0, DecodeMsg(GetPInfo(pid)->msg_name));

            rank_color = TEXT_COLOR_SYSTEM_BLUE;

            if (support_level == SUPPORT_LEVEL_A)
                rank_color = TEXT_COLOR_SYSTEM_GREEN;

            if (text_color == TEXT_COLOR_SYSTEM_GREEN)
                rank_color = TEXT_COLOR_SYSTEM_GREEN;

            PutSpecialChar(gUnk_Tm_02003238 + TM_OFFSET(13, y_tm),
                rank_color, GetSupportLevelSpecialChar(support_level));

            y_tm += 2;
            line++;
        }
    }
}

void PutStatScreenWeaponExpBar(int num, int x, int y, int item_kind)
{
    int color;
    int wexp = gStatScreenSt.unit->wexp[item_kind];

    PutIcon(gUnk_Tm_02003238 + TM_OFFSET(x, y),
        0x70 + item_kind, // TODO: icon id definitions
        TILEREF(0, BGPAL_ICONS + 1));

    color = (wexp >= WPN_EXP_S)
        ? TEXT_COLOR_SYSTEM_GREEN : TEXT_COLOR_SYSTEM_BLUE;

    // display rank letter
    PutSpecialChar(gUnk_Tm_02003238 + TM_OFFSET(x + 5, y),
        color, GetWeaponLevelSpecialCharFromExp(wexp));

    // this code makes the following assumptions
    STATIC_ASSERT(WPN_EXP_C - WPN_EXP_D == (WPN_EXP_D - WPN_EXP_E));
    STATIC_ASSERT(WPN_EXP_B - WPN_EXP_C == (WPN_EXP_D - WPN_EXP_E));
    STATIC_ASSERT(WPN_EXP_A - WPN_EXP_B == (WPN_EXP_D - WPN_EXP_E));
    STATIC_ASSERT(WPN_EXP_S - WPN_EXP_A == (WPN_EXP_D - WPN_EXP_E));

    if (wexp != WPN_EXP_0)
        wexp -= WPN_EXP_E;

    PutDrawUiGauge(0x401 + num * 6, 5,
        gUnk_Tm_02003C38 + TM_OFFSET(x + 3, y + 1), TILEREF(0, BGPAL_STATSCREEN_6),
        34, ((wexp % (WPN_EXP_D - WPN_EXP_E)) * 33) / 48, 0); // math look weird but gets something that ranges from 0 to 33. I would do "((wexp % 50) * 34) / 50"
}

void func_fe6_0806F324(void)
{
    Decompress(gUnk_08307E50, gBuf);
    TmApplyTsa_t(gUnk_Tm_02003738, gBuf, TILEREF(BGCHR_WINDOW_FRAME, BGPAL_WINDOW_FRAME));

    if (UnitKnowsMagic(gStatScreenSt.unit))
    {
        func_fe6_0806EB00(gUnk_0831955C);

        PutStatScreenWeaponExpBar(0, 1, 1, ITEM_KIND_ANIMA);
        PutStatScreenWeaponExpBar(1, 1, 3, ITEM_KIND_LIGHT);
        PutStatScreenWeaponExpBar(2, 9, 1, ITEM_KIND_ELDER);
        PutStatScreenWeaponExpBar(3, 9, 3, ITEM_KIND_STAFF);
    }
    else
    {
        func_fe6_0806EB00(gUnk_0831950C);

        PutStatScreenWeaponExpBar(0, 1, 1, ITEM_KIND_SWORD);
        PutStatScreenWeaponExpBar(1, 1, 3, ITEM_KIND_LANCE);
        PutStatScreenWeaponExpBar(2, 9, 1, ITEM_KIND_AXE);
        PutStatScreenWeaponExpBar(3, 9, 3, ITEM_KIND_BOW);
    }

    PutStatScreenSupportList();
}

void func_fe6_0806F3DC(int page_id)
{
    typedef void (* Func)(void);

    Func func_table[4] =
    {
        func_fe6_0806ED34,
        func_fe6_0806EFE0,
        func_fe6_0806F324,
        func_fe6_0806ED34,
    };

    CpuFastFill(0, gUnk_Tm_02003238, sizeof(u16) * 0x20 * 20);
    CpuFastFill(0, gUnk_Tm_02003C38, sizeof(u16) * 0x20 * 18);

    func_table[page_id]();
}

struct Unit * func_fe6_0806F430(struct Unit * current_unit, int iter_step)
{
    int faction = UNIT_FACTION(current_unit);
    int i = current_unit->id;

    struct Unit * unit;

    while (TRUE)
    {
        i = (i + iter_step) & 0x3F;

        unit = GetUnit(faction + i);

        if (unit == NULL)
            continue;

        if (unit->pinfo == NULL)
            continue;

        if ((unit->flags & gStatScreenInfo.excluded_unit_flags) != 0)
            continue;

        return unit;
    }
}

i8 CONST_DATA gStatScreenPageSlideOffsetLut[] =
{
    // transition page out
    -4, -7, -10, -12, -14,

    INT8_MAX, // draw new page

    // transition page in
    13, 9, 7, 5, 3, 2, 1, 0,

    INT8_MIN, // end
};

void StatScreenPageSlide_Loop(struct StatScreenPageSlideProc * proc)
{
    enum { PAGE_FRAME_SCREEN_X = 12, PAGE_FRAME_SCREEN_Y = 2 };

    int off;
    int len, dst_offset, src_offset;

    // clear page frame on bg0, bg1, bg2
    TmFillRect_t(gBg0Tm + TM_OFFSET(PAGE_FRAME_SCREEN_X, PAGE_FRAME_SCREEN_Y), 18, 18, 0);
    TmFillRect_t(gBg1Tm + TM_OFFSET(PAGE_FRAME_SCREEN_X, PAGE_FRAME_SCREEN_Y), 18, 18, 0);
    TmFillRect_t(gBg2Tm + TM_OFFSET(PAGE_FRAME_SCREEN_X, PAGE_FRAME_SCREEN_Y), 18, 18, 0);

    off = gStatScreenPageSlideOffsetLut[proc->clock];

    if (off == INT8_MAX)
    {
        // INT8_MAX offset means switch to displaying next page

        func_fe6_0806F3DC(proc->new_page);

        proc->clock++;
        off = gStatScreenPageSlideOffsetLut[proc->clock];
    }

    // compute len, dst_offset and src_offset
    // len is the length of the display bit of the page
    // dst_offset is the x offset to which to copy the page to
    // src_offset is the x offset from which to copy the page from

    if (proc->key_bit & KEY_DPAD_LEFT)
        off = -off;

    len = 18 - abs(off);

    if (off < 0)
    {
        dst_offset = 0;
        src_offset = -off;
    }
    else
    {
        dst_offset = off;
        src_offset = 0;
    }

    TmCopyRect_t(gUnk_Tm_02003238 + src_offset,
        gBg0Tm + dst_offset + TM_OFFSET(PAGE_FRAME_SCREEN_X, PAGE_FRAME_SCREEN_Y),
        len, 18);

    TmCopyRect_t(gUnk_Tm_02003738 + src_offset,
        gBg1Tm + dst_offset + TM_OFFSET(PAGE_FRAME_SCREEN_X, PAGE_FRAME_SCREEN_Y),
        len, 18);

    TmCopyRect_t(gUnk_Tm_02003C38 + src_offset,
        gBg2Tm + dst_offset + TM_OFFSET(PAGE_FRAME_SCREEN_X, PAGE_FRAME_SCREEN_Y),
        len, 18);

    EnableBgSync(BG0_SYNC_BIT + BG1_SYNC_BIT + BG2_SYNC_BIT);

    proc->clock++;
    off = gStatScreenPageSlideOffsetLut[proc->clock];

    if (off == INT8_MIN)
        Proc_Break(proc);
}

void StatScreenPageSlide_End(struct StatScreenPageSlideProc * proc)
{
    gStatScreenSt.is_transitioning = FALSE;
}

struct ProcScr CONST_DATA ProcScr_StatScreenPageSlide[] =
{
    PROC_REPEAT(StatScreenPageSlide_Loop),
    PROC_CALL(StatScreenPageSlide_End),
    PROC_END,
};

void StartStatScreenPageSlide(u16 key_bit, int new_page, ProcPtr parent)
{
    struct StatScreenPageSlideProc * proc;

    if (Proc_Find(ProcScr_StatScreenPageSlide) != NULL)
        return;

    PlaySe(SONG_6F);

    proc = SpawnProcLocking(ProcScr_StatScreenPageSlide, parent);

    proc->clock = 0;
    proc->new_page = new_page;
    proc->key_bit = key_bit;

    gStatScreenSt.page_slide_key_bit = key_bit;
    gStatScreenSt.help = NULL;
    gStatScreenSt.is_transitioning = TRUE;
}

void StatScreenUnitSlide_FadeOutInit(struct StatScreenUnitSlideProc * proc)
{
    gStatScreenSt.is_transitioning = TRUE;

    proc->clock = 4;

    // TODO: macro?
    gDispIo.bg0_ct.priority = 1;
    gDispIo.bg1_ct.priority = 3;
    gDispIo.bg2_ct.priority = 2;
    gDispIo.bg3_ct.priority = 0;

    SetBlendTargetA(0, 0, 0, 1, 0);
    SetBlendTargetB(1, 1, 1, 0, 1); SetBlendBackdropB(0);

    if (proc->direction > 0)
    {
        proc->y_disp_init = 0;
        proc->y_disp_fini = -60;
    }
    else
    {
        proc->y_disp_init = 0;
        proc->y_disp_fini = +60;
    }
}

void StatScreenUnitSlide_FadeOutLoop(struct StatScreenUnitSlideProc * proc)
{
    enum { CLOCK_STEP = 3, CLOCK_END = 0x10 };

    SetBlendAlpha(proc->clock * 0x10 / CLOCK_END, (CLOCK_END - proc->clock) * 0x10 / CLOCK_END);

    SetMuScreenPosition(gStatScreenSt.mu, 80, 138 + gStatScreenSt.y_disp_off);

    gStatScreenSt.y_disp_off = Interpolate(INTERPOLATE_CUBIC, proc->y_disp_init, proc->y_disp_fini, proc->clock, CLOCK_END);

    proc->clock += CLOCK_STEP;

    if (proc->clock > CLOCK_END)
        Proc_Break(proc);
}

void StatScreenUnitSlide_FadeInInit(struct StatScreenUnitSlideProc * proc)
{
    proc->clock = 1;

    // TODO: macro?
    gDispIo.bg0_ct.priority = 1;
    gDispIo.bg1_ct.priority = 3;
    gDispIo.bg2_ct.priority = 2;
    gDispIo.bg3_ct.priority = 0;

    SetBlendTargetA(0, 0, 0, 1, 0);
    SetBlendTargetB(1, 1, 1, 0, 1);

    if (proc->direction > 0)
    {
        proc->y_disp_init = +60;
        proc->y_disp_fini = 0;
    }
    else
    {
        proc->y_disp_init = -60;
        proc->y_disp_fini = 0;
    }
}

void StatScreenUnitSlide_FadeInLoop(struct StatScreenUnitSlideProc * proc)
{
    enum { CLOCK_STEP = 3, CLOCK_END = 0x10 };

    SetBlendAlpha((CLOCK_END - proc->clock) * 0x10 / CLOCK_END, proc->clock * 0x10 / CLOCK_END);

    SetMuScreenPosition(gStatScreenSt.mu, 80, 138 + gStatScreenSt.y_disp_off);

    gStatScreenSt.y_disp_off = Interpolate(INTERPOLATE_RCUBIC, proc->y_disp_init, proc->y_disp_fini, proc->clock, CLOCK_END);

    proc->clock += CLOCK_STEP;

    if (proc->clock >= CLOCK_END)
        Proc_Break(proc);
}

void StatScreenUnitSlide_ChangeUnit(struct StatScreenUnitSlideProc * proc)
{
    gStatScreenSt.unit = GetUnit(proc->new_unit_id);
    func_fe6_0806FFDC(NULL);
    Proc_Break(proc);
}

void StatScreenUnitSlide_End(struct StatScreenUnitSlideProc * proc)
{
    if (gStatScreenSt.mu != NULL)
    {
        SetMuScreenPosition(gStatScreenSt.mu, 80, 138);
    }

    // TODO: macro?
    gDispIo.bg0_ct.priority = 1;
    gDispIo.bg1_ct.priority = 3;
    gDispIo.bg2_ct.priority = 2;
    gDispIo.bg3_ct.priority = 3;

    SetBlendTargetA(0, 0, 1, 0, 0);
    SetBlendTargetB(0, 0, 0, 1, 0);
    SetBlendAlpha(6, 8);

    gStatScreenSt.is_transitioning = FALSE;
}

struct ProcScr CONST_DATA ProcScr_StatScreenUnitSlide[] =
{
    PROC_SLEEP(0),
    PROC_CALL(StatScreenUnitSlide_FadeOutInit),
    PROC_REPEAT(StatScreenUnitSlide_FadeOutLoop),
    PROC_CALL(StatScreenUnitSlide_ChangeUnit),
    PROC_CALL(StatScreenUnitSlide_FadeInInit),
    PROC_REPEAT(StatScreenUnitSlide_FadeInLoop),
    PROC_CALL(StatScreenUnitSlide_End),
    PROC_END,
};

void StartStatScreenUnitSlide(struct Unit * unit, int direction, ProcPtr parent)
{
    struct StatScreenUnitSlideProc * proc;

    proc = SpawnProcLocking(ProcScr_StatScreenUnitSlide, parent);

    proc->new_unit_id = unit->id;
    proc->direction = direction;

    PlaySe(SONG_C8);
}

u16 CONST_DATA Sprite_08677578[] =
{
    3,
    OAM0_SHAPE_32x16 + OAM0_AFFINE_ENABLE, OAM1_SIZE_32x16 + OAM1_X(0)  + OAM1_AFFINE_ID(8), OAM2_CHR(0),
    OAM0_SHAPE_32x16 + OAM0_AFFINE_ENABLE, OAM1_SIZE_32x16 + OAM1_X(32) + OAM1_AFFINE_ID(8), OAM2_CHR(4),
    OAM0_SHAPE_32x16 + OAM0_AFFINE_ENABLE, OAM1_SIZE_32x16 + OAM1_X(64) + OAM1_AFFINE_ID(8), OAM2_CHR(8),
};

u16 CONST_DATA gUnk_0867758C[] =
{
    OAM2_CHR(0x14),
    OAM2_CHR(0x08),
    OAM2_CHR(0x54),
};

void func_fe6_0806F8F0(int page_id)
{
    int color_num;

    PutSprite(4, 105 + gStatScreenSt.x_disp_off, 5 + gStatScreenSt.y_disp_off, Sprite_08677578, 0x3E40 + gUnk_0867758C[page_id]);

    color_num = (GetGameTime() / 4) % 16;

    CpuCopy16(
        Pal_Unk_083087C8[page_id] + color_num,
        gPal + 0x134,
        sizeof(u16) * 11);

    EnablePalSync();
}

enum { STATSCREEN_PAGE_NAME_SCALE_STEPS = 6 };

void func_fe6_0806F95C(struct StatScreenPageNameProc * proc)
{
    SetObjAffineAuto(8, 0, 0x100, 0x100);
    proc->page_id = gStatScreenSt.page;
}

void func_fe6_0806F9F4(struct StatScreenPageNameProc * proc)
{
    func_fe6_0806F8F0(proc->page_id);

    if (gStatScreenSt.page_slide_key_bit != 0)
    {
        proc->vertical_scale = STATSCREEN_PAGE_NAME_SCALE_STEPS - 1;
        Proc_Break(proc);
        return;
    }

    proc->page_id = gStatScreenSt.page;
}

void func_fe6_0806FA28(struct StatScreenPageNameProc * proc)
{
    SetObjAffineAuto(8, 0, 0x100, proc->vertical_scale * 0x100 / STATSCREEN_PAGE_NAME_SCALE_STEPS);
    func_fe6_0806F8F0(proc->page_id);

    proc->vertical_scale--;

    if (proc->vertical_scale == 0)
    {
        proc->vertical_scale = 1;
        Proc_Break(proc);
    }
}

void func_fe6_0806FAF0(struct StatScreenPageNameProc * proc)
{
    SetObjAffineAuto(8, 0, 0x100, proc->vertical_scale * 0x100 / STATSCREEN_PAGE_NAME_SCALE_STEPS);
    func_fe6_0806F8F0(gStatScreenSt.page);

    proc->vertical_scale++;

    if (proc->vertical_scale > STATSCREEN_PAGE_NAME_SCALE_STEPS)
    {
        proc->page_id = gStatScreenSt.page;
        Proc_Break(proc);
    }
}

void func_fe6_0806FBC0(struct StatScreenPageNameProc * proc)
{
    proc->x_left = 101;
    proc->x_right = 198;
    proc->clock_right = 0;
    proc->clock_left = 0;
    proc->anim_speed_right = 4;
    proc->anim_speed_left = 4;
}

void func_fe6_0806FBD8(struct StatScreenPageNameProc * proc)
{
    if (gStatScreenSt.page_slide_key_bit & KEY_DPAD_LEFT)
    {
        proc->anim_speed_left = 31;
        proc->x_left = 101 - 6;
    }

    if (gStatScreenSt.page_slide_key_bit & KEY_DPAD_RIGHT)
    {
        proc->anim_speed_right = 31;
        proc->x_right = 198 + 6;
    }

    gStatScreenSt.page_slide_key_bit = 0;
}

/*

*/
