#include "common.h"

#include "armfunc.h"
#include "hardware.h"
#include "proc.h"
#include "icon.h"
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

extern u16 const Pal_LinkArenaMuralBackground[];
extern u16 const Pal_MuralBackground[];
extern u8 const Img_MuralBackground[];

extern struct StatScreenTextInfo const gUnk_083193EC[]; // statscreen page A text
extern struct StatScreenTextInfo const gUnk_083194AC[]; // statscreen page B text

extern char const gUnk_083195AC[]; // magic label string literal
extern char const gUnk_083195B4[]; // strength label string literal

extern u8 const gUnk_08307D58[]; // tsa (compressed): statscreen page A frame
extern u8 const gUnk_08307DD4[]; // tsa (compressed): statscreen page B frame
extern u8 const gUnk_08308070[]; // tsa (compressed): statscreen page B battle stat box
extern u8 const gUnk_083080AC[]; // tsa: statscreen page B equipped weapon background

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

void func_fe6_0806EB48(void)
{
    char const * pname_str = DecodeMsg(gStatScreenSt.unit->pinfo->msg_name);
    int pname_text_x = GetStringTextCenteredPos(8 * 7, pname_str);

    TmFill(gBg0Tm, 0);

    BattleGenerateDisplayStats(gStatScreenSt.unit, GetUnitEquippedWeaponSlot(gStatScreenSt.unit));

    // displaying 

    PutDrawText(gStatScreenSt.text + STATSCREEN_TEXT_PNAME,
        gBg0Tm + TM_OFFSET(4, 10), TEXT_COLOR_SYSTEM_WHITE, pname_text_x, 0, pname_str);

    PutDrawText(gStatScreenSt.text + STATSCREEN_TEXT_JNAME,
        gBg0Tm + TM_OFFSET(1, 13), TEXT_COLOR_SYSTEM_WHITE, 0, 0, DecodeMsg(gStatScreenSt.unit->jinfo->msg_name));

    // displaying level, exp, hp

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

    // Displaying strength/magic labels

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

    // displaying strength/magic stat value
    PutStatScreenStatWithBar(0, 5, 1,
        gStatScreenSt.unit->pow,
        GetUnitPower(gStatScreenSt.unit),
        UNIT_POW_CAP(gStatScreenSt.unit));

    // displaying skill stat value
    PutStatScreenStatWithBar(1, 5, 3,
        gStatScreenSt.unit->flags & UNIT_FLAG_RESCUING
            ? gStatScreenSt.unit->skl / 2 : gStatScreenSt.unit->skl,
        GetUnitSkill(gStatScreenSt.unit),
        gStatScreenSt.unit->flags & UNIT_FLAG_RESCUING
            ? UNIT_SKL_CAP(gStatScreenSt.unit) / 2 : UNIT_SKL_CAP(gStatScreenSt.unit));

    // displaying speed stat value
    PutStatScreenStatWithBar(2, 5, 5,
        gStatScreenSt.unit->flags & UNIT_FLAG_RESCUING
            ? gStatScreenSt.unit->spd/2 : gStatScreenSt.unit->spd,
        GetUnitSpeed(gStatScreenSt.unit),
        gStatScreenSt.unit->flags & UNIT_FLAG_RESCUING
            ? UNIT_SPD_CAP(gStatScreenSt.unit) / 2 : UNIT_SPD_CAP(gStatScreenSt.unit));

    // displaying luck stat value
    PutStatScreenStatWithBar(3, 5, 7,
        gStatScreenSt.unit->lck,
        GetUnitLuck(gStatScreenSt.unit),
        UNIT_LCK_CAP(gStatScreenSt.unit));

    // displaying defense stat value
    PutStatScreenStatWithBar(4, 5, 9,
        gStatScreenSt.unit->def,
        GetUnitDefense(gStatScreenSt.unit),
        UNIT_DEF_CAP(gStatScreenSt.unit));

    // displaying resistance stat value
    PutStatScreenStatWithBar(5, 5, 11,
        gStatScreenSt.unit->res,
        GetUnitResistance(gStatScreenSt.unit),
        UNIT_RES_CAP(gStatScreenSt.unit));

    // displaying movement stat value
    PutStatScreenStatWithBar(6, 13, 1,
        UNIT_MOV_BASE(gStatScreenSt.unit),
        UNIT_MOV(gStatScreenSt.unit),
        UNIT_MOV_CAP(gStatScreenSt.unit));

    // displaying constitution stat value
    PutStatScreenStatWithBar(7, 13, 3,
        UNIT_CON_BASE(gStatScreenSt.unit),
        UNIT_CON(gStatScreenSt.unit),
        UNIT_CON_CAP(gStatScreenSt.unit));

    // displaying unit aid
    PutNumber(gUnk_Tm_02003238 + TM_OFFSET(13, 5), TEXT_COLOR_SYSTEM_BLUE,
        GetUnitAid(gStatScreenSt.unit));

    // displaying unit aid icon
    PutIcon(gUnk_Tm_02003238 + TM_OFFSET(14, 5),
        GetAidIconFromAttributes(UNIT_ATTRIBUTES(gStatScreenSt.unit)),
        TILEREF(0, BGPAL_ICONS + 1));

    // displaying unit rescue name
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

    PutNumberOrBlank(
        gUnk_Tm_02003238 + TM_OFFSET(8,  13),
        TEXT_COLOR_SYSTEM_BLUE, gBattleUnitA.battle_attack);

    PutNumberOrBlank(
        gUnk_Tm_02003238 + TM_OFFSET(8,  15),
        TEXT_COLOR_SYSTEM_BLUE, gBattleUnitA.battle_hit);

    PutNumberOrBlank(
        gUnk_Tm_02003238 + TM_OFFSET(15, 13),
        TEXT_COLOR_SYSTEM_BLUE, gBattleUnitA.battle_crit);

    PutNumberOrBlank(
        gUnk_Tm_02003238 + TM_OFFSET(15, 15),
        TEXT_COLOR_SYSTEM_BLUE, gBattleUnitA.battle_avoid);

    Text_InsertDrawString(gStatScreenSt.text + STATSCREEN_TEXT_20,
        16, TEXT_COLOR_SYSTEM_BLUE, GetItemRangeString(item));

    for (i = 0; i < 8; ++i)
    {
        gUnk_Tm_02003238[TM_OFFSET(2 + i, 11)] = TILEREF(0x278 + i, BGPAL_ICONS + 1);
        gUnk_Tm_02003238[TM_OFFSET(2 + i, 12)] = TILEREF(0x270 + i, BGPAL_ICONS + 1);
    }
}

/*

*/
