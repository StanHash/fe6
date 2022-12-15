#include "battlepreview.h"

#include "armfunc.h"
#include "hardware.h"
#include "oam.h"
#include "icon.h"
#include "text.h"
#include "sprite.h"
#include "msg.h"
#include "util.h"
#include "item.h"
#include "unit.h"
#include "map.h"
#include "battle.h"
#include "bm.h"
#include "faction.h"
#include "ui.h"
#include "helpbox.h"

#include "constants/videoalloc_global.h"
#include "constants/msg.h"

enum
{
    BATTLEPREVIEW_FRAME_SHORT = 1,
    BATTLEPREVIEW_FRAME_LARGE = 2,
};

enum
{
    BATTLEPREVIEW_LABEL_DAMAGE,
    BATTLEPREVIEW_LABEL_HIT,
    BATTLEPREVIEW_LABEL_CRIT,
    BATTLEPREVIEW_LABEL_ATTACK,
    BATTLEPREVIEW_LABEL_DEFENSE,
    BATTLEPREVIEW_LABEL_SPEED,

    BATTLEPREVIEW_LABEL_COUNT,
};

struct BattlePreviewProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ i32 clock;
    /* 30 */ i8 x, y;
    /* 32 */ u8 frame_kind;
    /* 33 */ bool8 ready;
    /* 34 */ bool8 needs_content_update;
    /* 35 */ i8 side; // -1 is left, +1 is right
    /* 36 */ i8 slide_clock;
    /* 38 */ struct Text unit_name_text_a;
    /* 40 */ struct Text unit_name_text_b; // unused, presumably by mistake
    /* 48 */ struct Text item_name_text;
    /* 50 */ i8 hit_count_a;
    /* 51 */ i8 hit_count_b;
    /* 52 */ bool8 is_effective_a;
    /* 53 */ bool8 is_effective_b;
};

extern struct Text gBattlePreviewLabels[BATTLEPREVIEW_LABEL_COUNT];
extern u16 gBattlePreviewIconPalBuf[8][0x10];

static int GetBattlePreviewPanelSide(void)
{
    int x = gBattleUnitB.unit.x*16 - gBmSt.camera.x;

    if (x < 0x70)
        return +1;

    if (x > 0x70)
        return -1;

    return 0;
}

static void InitBattlePreviewIconPalBuf(void)
{
    int i, j;

    ApplyIconPalette(0, BGPAL_BATTLEPREVIEW_ICONALT);

    for (i = 1; i < 0x10; ++i)
    {
        int color = PAL_COLOR(BGPAL_BATTLEPREVIEW_ICONALT, i);

        int r = RGB_GET_RED(color);
        int g = RGB_GET_GREEN(color);
        int b = RGB_GET_BLUE(color);

        for (j = 0; j < 8; ++j)
        {
            gBattlePreviewIconPalBuf[j][i] = RGB(r, g, b);

            r += 3;
            if (r > 31) r = 31;

            g += 3;
            if (g > 31) g = 31;

            b += 3;
            if (b > 31) b = 31;
        }
    }
}

static void InitBattlePreviewLabels(void)
{
    static char const * label_strings[BATTLEPREVIEW_LABEL_COUNT] =
    {
        [BATTLEPREVIEW_LABEL_DAMAGE]  = TEXT("威力", "Mt"),
        [BATTLEPREVIEW_LABEL_HIT]     = TEXT("命中", "Hit"),
        [BATTLEPREVIEW_LABEL_CRIT]    = TEXT("必殺", "Crit"),
        [BATTLEPREVIEW_LABEL_ATTACK]  = TEXT("攻撃", "Atk"),
        [BATTLEPREVIEW_LABEL_DEFENSE] = TEXT("守備", "Def"),
        [BATTLEPREVIEW_LABEL_SPEED]   = TEXT("攻速", "AS"),
    };

    int i;

    for (i = 0; i < BATTLEPREVIEW_LABEL_COUNT; ++i)
    {
        InitText(gBattlePreviewLabels+i, 4);

        Text_InsertDrawString(gBattlePreviewLabels+i,
            GetStringTextCenteredPos(4*8, label_strings[i]),
            TEXT_COLOR_SYSTEM_GOLD, label_strings[i]);
    }
}

static void PutBattlePreviewUnitName(u16 * tm, struct Text * text, struct Unit * unit)
{
    char const * str = DecodeMsg(unit->pinfo->msg_name);
    int pos = GetStringTextCenteredPos(6*8, str);

    ClearText(text);
    PutDrawText(text, tm, TEXT_COLOR_SYSTEM_WHITE, pos, 0, str);
}

static void PutBattlePreviewItemName(u16 * tm, struct Text * text, int item)
{
    char const * str = GetItemName(item);
    int pos = GetStringTextCenteredPos(7*8, str);

    ClearText(text);
    PutDrawText(text, tm, TEXT_COLOR_SYSTEM_WHITE, pos, 0, str);
}

static void BattlePreviewHitCountUpdate(struct BattleUnit * bu, u8 * hitCounter, int* usesCounter)
{
    if (*usesCounter > 0)
    {
        *hitCounter = *hitCounter + 1;
        *usesCounter = *usesCounter - 1;

        if (bu->weapon_attributes & ITEM_ATTR_BRAVE)
        {
            *hitCounter = *hitCounter + 1;
            *usesCounter = *usesCounter - 1;
        }
    }
}

static void InitBattlePreviewBattleStats(struct BattlePreviewProc * proc)
{
    int usesA = GetItemUses(gBattleUnitA.weapon_before);
    int usesB = GetItemUses(gBattleUnitB.weapon_before);

    struct BattleUnit * buFirst;
    struct BattleUnit * buSecond;

    bool followUp = BattleGetFollowUpOrder(&buFirst, &buSecond);

    proc->hit_count_a = 0;
    proc->is_effective_a = FALSE;

    if (gBattleUnitA.weapon || gBattleUnitA.weapon_broke)
    {
        BattlePreviewHitCountUpdate(&gBattleUnitA, &proc->hit_count_a, &usesA);

        if (followUp && buFirst == &gBattleUnitA)
            BattlePreviewHitCountUpdate(&gBattleUnitA, &proc->hit_count_a, &usesA);

        if (IsItemEffectiveAgainst(gBattleUnitA.weapon_before, &gBattleUnitB.unit))
            proc->is_effective_a = TRUE;
    }

    proc->hit_count_b = 0;
    proc->is_effective_b = FALSE;

    if (gBattleUnitB.weapon || gBattleUnitB.weapon_broke)
    {
        BattlePreviewHitCountUpdate(&gBattleUnitB, &proc->hit_count_b, &usesB);

        if (followUp && buFirst == &gBattleUnitB)
            BattlePreviewHitCountUpdate(&gBattleUnitB, &proc->hit_count_b, &usesB);

        if (IsItemEffectiveAgainst(gBattleUnitB.weapon_before, &gBattleUnitA.unit))
            proc->is_effective_b = TRUE;
    }
}

static void DrawBattlePreviewContentsShort(struct BattlePreviewProc * proc)
{
    int damage;

    TmApplyTsa_t(gUnk_Tm_02003738, Tsa_BattlePreviewFrame_Short, TILEREF(BGCHR_BATTLEPREVIEW_FRAME, BGPAL_BATTLEPREVIEW_FRAME));
    TmFillRect_t(gUnk_Tm_02003238, 10, 15, 0);

    PutBattlePreviewUnitName(gUnk_Tm_02003238 + TM_OFFSET(3, 1), &proc->unit_name_text_a, &gBattleUnitA.unit);
    PutBattlePreviewUnitName(gUnk_Tm_02003238 + TM_OFFSET(1, 11), &proc->unit_name_text_a, &gBattleUnitB.unit);
    PutBattlePreviewItemName(gUnk_Tm_02003238 + TM_OFFSET(1, 13), &proc->item_name_text, gBattleUnitB.weapon_before);

    if (gBattleUnitB.weapon == 0 && !gBattleUnitB.weapon_broke)
    {
        damage = -1;

        gBattleUnitB.battle_effective_hit = 0xFF;
        gBattleUnitB.battle_effective_crit = 0xFF;
    }
    else
    {
        damage = gBattleUnitB.battle_attack - gBattleUnitA.battle_defense;

        if (damage < 0)
            damage = 0;
    }

    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(2, 3), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitB.previous_hp);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(2, 5), TEXT_COLOR_SYSTEM_BLUE, damage);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(2, 7), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitB.battle_effective_hit);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(2, 9), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitB.battle_effective_crit);

    damage = gBattleUnitA.battle_attack - gBattleUnitB.battle_defense;

    if (damage < 0)
        damage = 0;

    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(8, 3), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitA.previous_hp);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(8, 5), TEXT_COLOR_SYSTEM_BLUE, damage);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(8, 7), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitA.battle_effective_hit);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(8, 9), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitA.battle_effective_crit);

    PutTwoSpecialChar(gUnk_Tm_02003238 + TM_OFFSET(4, 3),
        TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_HP_A, TEXT_SPECIAL_HP_B);

    PutText(gBattlePreviewLabels+BATTLEPREVIEW_LABEL_DAMAGE, gUnk_Tm_02003238 + TM_OFFSET(3, 5));
    PutText(gBattlePreviewLabels+BATTLEPREVIEW_LABEL_HIT, gUnk_Tm_02003238 + TM_OFFSET(3, 7));
    PutText(gBattlePreviewLabels+BATTLEPREVIEW_LABEL_CRIT, gUnk_Tm_02003238 + TM_OFFSET(3, 9));

    PutIcon(gUnk_Tm_02003238 + TM_OFFSET(7, 11), GetItemIcon(gBattleUnitB.weapon_before), TILEREF(0, BGPAL_ICONS+0));
    PutIcon(gUnk_Tm_02003238 + TM_OFFSET(1, 1), GetItemIcon(gBattleUnitA.weapon_before), TILEREF(0, BGPAL_BATTLEPREVIEW_ICONALT));
}

static void DrawBattlePreviewContentsLong(struct BattlePreviewProc * proc)
{
    TmApplyTsa_t(gUnk_Tm_02003738, Tsa_BattlePreviewFrame_Long, TILEREF(BGCHR_BATTLEPREVIEW_FRAME, BGPAL_WINDOWFRAME));
    TmFillRect_t(gUnk_Tm_02003238, 10, 19, 0);

    PutBattlePreviewUnitName(gUnk_Tm_02003238 + TM_OFFSET(3, 1), &proc->unit_name_text_a, &gBattleUnitA.unit);
    PutBattlePreviewUnitName(gUnk_Tm_02003238 + TM_OFFSET(1, 15), &proc->unit_name_text_a, &gBattleUnitB.unit);
    PutBattlePreviewItemName(gUnk_Tm_02003238 + TM_OFFSET(1, 17), &proc->item_name_text, gBattleUnitB.weapon_before);

    if (gBattleUnitB.weapon == 0)
    {
        gBattleUnitB.battle_attack = 0xFF;
        gBattleUnitB.battle_effective_hit = 0xFF;
        gBattleUnitB.battle_effective_crit = 0xFF;
    }

    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(2, 3), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitB.previous_hp);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(2, 5), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitB.battle_attack);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(2, 7), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitB.battle_defense);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(2, 9), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitB.battle_effective_hit);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(2, 11), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitB.battle_effective_crit);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(2, 13), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitB.battle_speed);

    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(8, 3), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitA.previous_hp);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(8, 5), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitA.battle_attack);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(8, 7), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitA.battle_defense);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(8, 9), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitA.battle_effective_hit);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(8, 11), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitA.battle_effective_crit);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(8, 13), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitA.battle_speed);

    PutTwoSpecialChar(gUnk_Tm_02003238 + TM_OFFSET(4, 3),
        TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_HP_A, TEXT_SPECIAL_HP_B);

    PutText(gBattlePreviewLabels+BATTLEPREVIEW_LABEL_ATTACK, gUnk_Tm_02003238 + TM_OFFSET(3, 5));
    PutText(gBattlePreviewLabels+BATTLEPREVIEW_LABEL_DEFENSE, gUnk_Tm_02003238 + TM_OFFSET(3, 7));
    PutText(gBattlePreviewLabels+BATTLEPREVIEW_LABEL_HIT, gUnk_Tm_02003238 + TM_OFFSET(3, 9));
    PutText(gBattlePreviewLabels+BATTLEPREVIEW_LABEL_CRIT, gUnk_Tm_02003238 + TM_OFFSET(3, 11));
    PutText(gBattlePreviewLabels+BATTLEPREVIEW_LABEL_SPEED, gUnk_Tm_02003238 + TM_OFFSET(3, 13));

    PutIcon(gUnk_Tm_02003238 + TM_OFFSET(7, 15), GetItemIcon(gBattleUnitB.weapon_before), TILEREF(0, BGPAL_ICONS+0));
    PutIcon(gUnk_Tm_02003238 + TM_OFFSET(1, 1), GetItemIcon(gBattleUnitA.weapon_before), TILEREF(0, BGPAL_BATTLEPREVIEW_ICONALT));
}

static void DrawBattlePreviewContents(struct BattlePreviewProc * proc)
{
    proc->clock = 0;
    proc->needs_content_update = FALSE;

    switch (proc->frame_kind)
    {

    case BATTLEPREVIEW_FRAME_SHORT:
        InitBattlePreviewBattleStats(proc);
        DrawBattlePreviewContentsShort(proc);
        break;

    case BATTLEPREVIEW_FRAME_LARGE:
        InitBattlePreviewBattleStats(proc);
        DrawBattlePreviewContentsLong(proc);
        break;

    }
}

static u16 const * GetFactionBattlePreviewFramePalette(int faction)
{
    switch (faction)
    {

    case FACTION_BLUE:   return Pal_BattlePreviewFrame_Blue;
    case FACTION_RED:    return Pal_BattlePreviewFrame_Red;
    case FACTION_GREEN:  return Pal_BattlePreviewFrame_Green;
    case FACTION_PURPLE: return Pal_BattlePreviewFrame_Purple;

    }
}

static void InitBattlePreviewFramePalettes(void)
{
    ApplyPalette(GetFactionBattlePreviewFramePalette(UNIT_FACTION(&gBattleUnitA.unit)), BGPAL_BATTLEPREVIEW_FRAME+0);

    if (gBattleUnitB.unit.id != 0)
        ApplyPalette(GetFactionBattlePreviewFramePalette(UNIT_FACTION(&gBattleUnitB.unit)), BGPAL_BATTLEPREVIEW_FRAME+1);
    else
        ApplyPalette(GetFactionBattlePreviewFramePalette(FACTION_PURPLE), BGPAL_BATTLEPREVIEW_FRAME+1);
}

static void BattlePreview_Init(struct BattlePreviewProc * proc)
{
    Decompress(Img_BattlePreviewFrame, (void *) VRAM + BGCHR_BATTLEPREVIEW_FRAME*CHR_SIZE);

    Decompress(Img_BattlePreviewMultipliers, gBuf);
    Copy2dChr(gBuf, OBJ_VRAM0 + OBJCHR_BATTLEPREVIEW_MULTIPLIERS*CHR_SIZE, 4, 2);

    ApplyPalette(Pal_BattlePreviewMultipliers, 0x10+OBJPAL_BATTLEPREVIEW_MULTIPLIERS);

    ResetTextFont();
    InitIcons();
    InitBattlePreviewIconPalBuf();
    InitBattlePreviewLabels();

    InitTextDb(&proc->unit_name_text_a, 6);
    InitTextDb(&proc->unit_name_text_b, 6);
    InitTextDb(&proc->item_name_text, 7);

    SetBgOffset(1, 0, -1);

    proc->ready = TRUE;
}

static void BattlePreview_OnEnd(void)
{
    UnpackUiWindowFrameGraphics2(-1);
}

static void PutBattlePreviewTilemaps(struct BattlePreviewProc * proc)
{
    int height = proc->frame_kind == BATTLEPREVIEW_FRAME_SHORT ? 16 : 20;

    if (proc->side < 0)
    {
        // left
        TmCopyRect_t(gUnk_Tm_02003238, gBg0Tm + TM_OFFSET(0, 0), 10, height);
        TmCopyRect_t(gUnk_Tm_02003738, gBg1Tm + TM_OFFSET(0, 0), 10, height);
    }
    else
    {
        // right
        TmCopyRect_t(gUnk_Tm_02003238, gBg0Tm + TM_OFFSET(20, 0), 10, height);
        TmCopyRect_t(gUnk_Tm_02003738, gBg1Tm + TM_OFFSET(20, 0), 10, height);
    }

    EnableBgSync(BG0_SYNC_BIT + BG1_SYNC_BIT);
}

static void PutBattlePreviewWtArrows(struct BattlePreviewProc * proc)
{
    enum { WT_ARROW_NONE, WT_ARROW_UP, WT_ARROW_DOWN };

    int wtArrowA = WT_ARROW_NONE;
    int wtArrowB = WT_ARROW_NONE;

    if (gBattleUnitA.advantage_bonus_hit > 0)
        wtArrowA = WT_ARROW_UP;

    if (gBattleUnitA.advantage_bonus_hit < 0)
        wtArrowA = WT_ARROW_DOWN;

    if (gBattleUnitB.advantage_bonus_hit > 0)
        wtArrowB = WT_ARROW_UP;

    if (gBattleUnitB.advantage_bonus_hit < 0)
        wtArrowB = WT_ARROW_DOWN;

    if (wtArrowB != WT_ARROW_NONE)
    {
        PutSysArrow((proc->x+8)*8+3, (proc->y+11)*8,
            wtArrowB == WT_ARROW_DOWN ? TRUE : FALSE);
    }

    if (wtArrowA != WT_ARROW_NONE)
    {
        PutSysArrow((proc->x+2)*8+3, (proc->y+1)*8,
            wtArrowA == WT_ARROW_DOWN ? TRUE : FALSE);
    }
}

static void PutBattlePreviewMultipliers(struct BattlePreviewProc * proc)
{
    int angle = (proc->clock*4) & 0xFF;

    int x = SIN_Q12(angle)*4 >> 12;
    int y = COS_Q12(angle)*2 >> 12;

    x += proc->x*8-3;
    y += proc->y*8;

    if (proc->hit_count_a > 1)
    {
        PutSprite(4, x+72, y+40, Sprite_16x16,
            OAM2_CHR(OBJCHR_BATTLEPREVIEW_MULTIPLIERS)
                + OAM2_PAL(OBJPAL_BATTLEPREVIEW_MULTIPLIERS)
                + proc->hit_count_a-2);
    }

    if (proc->hit_count_b > 1)
    {
        PutSprite(4, x+24, y+40, Sprite_16x16,
            OAM2_CHR(OBJCHR_BATTLEPREVIEW_MULTIPLIERS)
                + OAM2_PAL(OBJPAL_BATTLEPREVIEW_MULTIPLIERS)
                + proc->hit_count_b-2);
    }
}

static void UpdateBattlePreviewEffectivenessPalettes(struct BattlePreviewProc * proc)
{
    static u8 palAnimLut[] =
    {
        0, 1, 1, 2, 3, 4, 5, 5,
        4, 4, 4, 3, 3, 3, 2, 2,
        2, 2, 1, 1, 1, 1, 1, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
    };

    int palAnim;

    if (proc->is_effective_a)
        palAnim = palAnimLut[proc->clock % sizeof(palAnimLut)];
    else
        palAnim = 0;

    ApplyPalette(gBattlePreviewIconPalBuf[palAnim], BGPAL_BATTLEPREVIEW_ICONALT);

    if (proc->is_effective_b)
        palAnim = palAnimLut[proc->clock % sizeof(palAnimLut)];
    else
        palAnim = 0;

    ApplyPalette(gBattlePreviewIconPalBuf[palAnim], BGPAL_ICONS+0);
}

static void BattlePreview_LoopDisplay(struct BattlePreviewProc * proc)
{
    proc->clock++;

    if (proc->needs_content_update)
    {
        int side = GetBattlePreviewPanelSide();

        if (side != 0 && side != proc->side)
        {
            Proc_Break(proc);
            return;
        }

        DrawBattlePreviewContents(proc);
        PutBattlePreviewTilemaps(proc);
        InitBattlePreviewFramePalettes();
    }

    if (proc->frame_kind == BATTLEPREVIEW_FRAME_SHORT)
    {
        PutBattlePreviewWtArrows(proc);
        PutBattlePreviewMultipliers(proc);
        UpdateBattlePreviewEffectivenessPalettes(proc);
    }
}

static void BattlePreview_OnNewBattle(struct BattlePreviewProc * proc)
{
    DrawBattlePreviewContents(proc);

    proc->side = GetBattlePreviewPanelSide();
    proc->slide_clock = 0;

    if (proc->side < 0)
        // left
        proc->x = 0;
    else
        // right
        proc->x = 20;

    proc->y = 0;

    InitBattlePreviewFramePalettes();
}

static void BattlePreview_LoopSlideIn(struct BattlePreviewProc * proc)
{
    static i8 offsetLut[] = { 6, 8, 9, 10 };
    int offset;

    int height = proc->frame_kind == BATTLEPREVIEW_FRAME_SHORT ? 16 : 20;

    TmFill(gBg0Tm, 0);
    TmFill(gBg1Tm, 0);

    EnableBgSync(BG0_SYNC_BIT + BG1_SYNC_BIT);

    offset = offsetLut[proc->slide_clock];

    if (proc->side < 0)
    {
        // left
        TmCopyRect_t(gUnk_Tm_02003238 + TM_OFFSET(10 - offset, 0), gBg0Tm, offset, height);
        TmCopyRect_t(gUnk_Tm_02003738 + TM_OFFSET(10 - offset, 0), gBg1Tm, offset, height);
    }
    else
    {
        // right
        TmCopyRect_t(gUnk_Tm_02003238, gBg0Tm + TM_OFFSET(30 - offset, 0), offset, height);
        TmCopyRect_t(gUnk_Tm_02003738, gBg1Tm + TM_OFFSET(30 - offset, 0), offset, height);
    }

    proc->slide_clock++;

    if ((u8) proc->slide_clock == 4)
    {
        proc->slide_clock = 0;
        Proc_Break(proc);
    }
}

static void BattlePreview_LoopSlideOut(struct BattlePreviewProc * proc)
{
    static i8 offsetLut[] = { 9, 8, 6, 0 };
    int offset;

    int height = proc->frame_kind == BATTLEPREVIEW_FRAME_SHORT ? 16 : 20;

    TmFill(gBg0Tm, 0);
    TmFill(gBg1Tm, 0);

    EnableBgSync(BG0_SYNC_BIT + BG1_SYNC_BIT);

    offset = offsetLut[proc->slide_clock];

    if (proc->side < 0)
    {
        // left
        TmCopyRect_t(gUnk_Tm_02003238 + TM_OFFSET(10 - offset, 0), gBg0Tm, offset, height);
        TmCopyRect_t(gUnk_Tm_02003738 + TM_OFFSET(10 - offset, 0), gBg1Tm, offset, height);
    }
    else
    {
        // right
        TmCopyRect_t(gUnk_Tm_02003238, gBg0Tm + TM_OFFSET(30 - offset, 0), offset, height);
        TmCopyRect_t(gUnk_Tm_02003738, gBg1Tm + TM_OFFSET(30 - offset, 0), offset, height);
    }

    proc->slide_clock++;

    if ((u8) proc->slide_clock == 4)
    {
        proc->slide_clock = 0;
        Proc_Break(proc);
    }
}

struct ProcScr CONST_DATA ProcScr_BattlePreview[] =
{
    PROC_19,

    PROC_ONEND(BattlePreview_OnEnd),

    PROC_CALL(ClearUi),
    PROC_SLEEP(0),

    PROC_CALL(BattlePreview_Init),

PROC_LABEL(0),
    PROC_CALL(BattlePreview_OnNewBattle),

    PROC_REPEAT(BattlePreview_LoopSlideIn),
    PROC_REPEAT(BattlePreview_LoopDisplay),
    PROC_REPEAT(BattlePreview_LoopSlideOut),

    PROC_GOTO(0),

PROC_LABEL(1),
    PROC_REPEAT(BattlePreview_LoopSlideOut),

    PROC_END,
};

void StartBattlePreview(struct MapSelectProc * mapselect_proc)
{
    struct BattlePreviewProc * proc;

    if (gPlaySt.config_battle_preview_kind == 2)
    {
        ResetTextFont();
        return;
    }

    proc = SpawnProc(ProcScr_BattlePreview, PROC_TREE_3);
    proc->ready = FALSE;

    switch (gPlaySt.config_battle_preview_kind)
    {

    case 0:
        proc->frame_kind = BATTLEPREVIEW_FRAME_SHORT;
        break;

    case 1:
        proc->frame_kind = BATTLEPREVIEW_FRAME_LARGE;
        break;

    }

    MapFill(gMapMovement, -1);
}

void UpdateBattlePreviewContents(void)
{
    struct BattlePreviewProc * proc = Proc_Find(ProcScr_BattlePreview);

    if (proc == NULL)
        return;

    if (proc->ready)
        proc->needs_content_update = TRUE;
}

void CloseBattlePreview(void)
{
    struct BattlePreviewProc * proc = Proc_Find(ProcScr_BattlePreview);

    if (proc == NULL)
        return;

    if (!proc->ready)
    {
        ClearUi();

        Proc_End(proc);
        return;
    }

    Proc_Goto(proc, 1);
}

fu8 StartBattlePreviewHelpBox(struct MapSelectProc * mapselect_proc, struct SelectTarget * target)
{
    int x;

    struct BattlePreviewProc * proc = Proc_Find(ProcScr_BattlePreview);

    if (proc == NULL)
        return 0;

    if (proc->side < 0)
        // left
        x = 0;
    else
        // right
        x = 20;

    func_fe6_08070E70(NULL, -1);

    switch (proc->frame_kind)
    {

    case BATTLEPREVIEW_FRAME_SHORT:
        StartMovingHelpBoxExt(&HelpInfo_BpShort_Hp, mapselect_proc, x, 0);
        break;

    case BATTLEPREVIEW_FRAME_LARGE:
        StartMovingHelpBoxExt(&HelpInfo_BpLarge_Hp, mapselect_proc, x, 0);
        break;

    }

    return 0;
}

static int func_fe6_0802E43C(int wt, bool is_effective)
{
    static u16 lut[] =
    {
        MSG_6A4,
        MSG_6A6,
        MSG_6A8,
        MSG_6A5,
        MSG_6A7,
        MSG_6A9,
    };

    int idx = is_effective ? 3 : 0;

    if (wt < 0)
        idx += 2;

    if (wt > 0)
        idx += 1;

    return lut[idx];
}

void HelpBoxPopulateBattlePreviewAdvantageA(struct HelpBoxProc * proc)
{
    struct BattlePreviewProc * bp = Proc_Find(ProcScr_BattlePreview);
    proc->msg = func_fe6_0802E43C(gBattleUnitA.advantage_bonus_hit, bp->is_effective_a);
}

void HelpBoxPopulateBattlePreviewAdvantageB(struct HelpBoxProc * proc)
{
    struct BattlePreviewProc * bp = Proc_Find(ProcScr_BattlePreview);
    proc->msg = func_fe6_0802E43C(gBattleUnitB.advantage_bonus_hit, bp->is_effective_b);
}
