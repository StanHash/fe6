
#include "battle-preview.h"

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
#include "help-box.h"

#include "constants/video-global.h"

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

    /* 2C */ int unk_2C;
    /* 30 */ s8 x, y;
    /* 32 */ u8 frameKind;
    /* 33 */ bool ready;
    /* 34 */ bool needContentUpdate;
    /* 35 */ s8 side; // -1 is left, +1 is right
    /* 36 */ s8 unk_36;
    /* 38 */ struct Text unitNameTextA;
    /* 40 */ struct Text unitNameTextB; // unused, presumably by mistake
    /* 48 */ struct Text itemNameText;
    /* 50 */ s8 hitCountA;
    /* 51 */ s8 hitCountB;
    /* 52 */ bool isEffectiveA;
    /* 53 */ bool isEffectiveB;
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
    static char const* gUnk_085C8388[BATTLEPREVIEW_LABEL_COUNT] =
    {
        [BATTLEPREVIEW_LABEL_DAMAGE]  = TEXT("\x88\xD0\x97\xCD"), // "威力"
        [BATTLEPREVIEW_LABEL_HIT]     = TEXT("\x96\xBD\x92\x86"), // "命中"
        [BATTLEPREVIEW_LABEL_CRIT]    = TEXT("\x95\x4B\x8E\x45"), // "必殺"
        [BATTLEPREVIEW_LABEL_ATTACK]  = TEXT("\x8D\x55\x8C\x82"), // "攻撃"
        [BATTLEPREVIEW_LABEL_DEFENSE] = TEXT("\x8E\xE7\x94\xF5"), // "守備"
        [BATTLEPREVIEW_LABEL_SPEED]   = TEXT("\x8D\x55\x91\xAC"), // "攻速"
    };

    int i;

    for (i = 0; i < BATTLEPREVIEW_LABEL_COUNT; ++i)
    {
        InitText(gBattlePreviewLabels+i, 4);

        Text_InsertDrawString(gBattlePreviewLabels+i,
            GetStringTextCenteredPos(4*8, gUnk_085C8388[i]),
            TEXT_COLOR_SYSTEM_GOLD, gUnk_085C8388[i]);
    }
}

static void PutBattlePreviewUnitName(u16* tm, struct Text* text, struct Unit* unit)
{
    char const* str = DecodeMsg(unit->person->msgName);
    int pos = GetStringTextCenteredPos(6*8, str);

    ClearText(text);
    PutDrawText(text, tm, TEXT_COLOR_SYSTEM_WHITE, pos, 0, str);
}

static void PutBattlePreviewItemName(u16* tm, struct Text* text, int item)
{
    char const* str = GetItemName(item);
    int pos = GetStringTextCenteredPos(7*8, str);

    ClearText(text);
    PutDrawText(text, tm, TEXT_COLOR_SYSTEM_WHITE, pos, 0, str);
}

static void BattlePreviewHitCountUpdate(struct BattleUnit* bu, u8* hitCounter, int* usesCounter)
{
    if (*usesCounter > 0)
    {
        *hitCounter = *hitCounter + 1;
        *usesCounter = *usesCounter - 1;

        if (bu->weaponAttributes & ITEM_ATTR_BRAVE)
        {
            *hitCounter = *hitCounter + 1;
            *usesCounter = *usesCounter - 1;
        }
    }
}

static void InitBattlePreviewBattleStats(struct BattlePreviewProc* proc)
{
    int usesA = GetItemUses(gBattleUnitA.weaponBefore);
    int usesB = GetItemUses(gBattleUnitB.weaponBefore);

    struct BattleUnit* buFirst;
    struct BattleUnit* buSecond;

    bool followUp = BattleGetFollowUpOrder(&buFirst, &buSecond);

    proc->hitCountA = 0;
    proc->isEffectiveA = FALSE;

    if (gBattleUnitA.weapon || gBattleUnitA.weaponBroke)
    {
        BattlePreviewHitCountUpdate(&gBattleUnitA, &proc->hitCountA, &usesA);

        if (followUp && buFirst == &gBattleUnitA)
            BattlePreviewHitCountUpdate(&gBattleUnitA, &proc->hitCountA, &usesA);

        if (IsItemEffectiveAgainst(gBattleUnitA.weaponBefore, &gBattleUnitB.unit))
            proc->isEffectiveA = TRUE;
    }

    proc->hitCountB = 0;
    proc->isEffectiveB = FALSE;

    if (gBattleUnitB.weapon || gBattleUnitB.weaponBroke)
    {
        BattlePreviewHitCountUpdate(&gBattleUnitB, &proc->hitCountB, &usesB);

        if (followUp && buFirst == &gBattleUnitB)
            BattlePreviewHitCountUpdate(&gBattleUnitB, &proc->hitCountB, &usesB);

        if (IsItemEffectiveAgainst(gBattleUnitB.weaponBefore, &gBattleUnitA.unit))
            proc->isEffectiveB = TRUE;
    }
}

static void DrawBattlePreviewContentsShort(struct BattlePreviewProc* proc)
{
    int damage;

    TmApplyTsa_t(gUnk_Tm_02003738, Tsa_BattlePreviewFrame_Short, TILEREF(BGCHR_BATTLEPREVIEW_FRAME, BGPAL_BATTLEPREVIEW_FRAME));
    TmFillRect_t(gUnk_Tm_02003238, 10, 15, 0);

    PutBattlePreviewUnitName(gUnk_Tm_02003238 + TM_OFFSET(3, 1), &proc->unitNameTextA, &gBattleUnitA.unit);
    PutBattlePreviewUnitName(gUnk_Tm_02003238 + TM_OFFSET(1, 11), &proc->unitNameTextA, &gBattleUnitB.unit);
    PutBattlePreviewItemName(gUnk_Tm_02003238 + TM_OFFSET(1, 13), &proc->itemNameText, gBattleUnitB.weaponBefore);

    if (gBattleUnitB.weapon == 0 && !gBattleUnitB.weaponBroke)
    {
        damage = -1;

        gBattleUnitB.battleEffectiveHit = 0xFF;
        gBattleUnitB.battleEffectiveCrit = 0xFF;
    }
    else
    {
        damage = gBattleUnitB.battleAttack - gBattleUnitA.battleDefense;

        if (damage < 0)
            damage = 0;
    }

    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(2, 3), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitB.hpPrevious);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(2, 5), TEXT_COLOR_SYSTEM_BLUE, damage);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(2, 7), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitB.battleEffectiveHit);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(2, 9), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitB.battleEffectiveCrit);

    damage = gBattleUnitA.battleAttack - gBattleUnitB.battleDefense;

    if (damage < 0)
        damage = 0;

    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(8, 3), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitA.hpPrevious);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(8, 5), TEXT_COLOR_SYSTEM_BLUE, damage);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(8, 7), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitA.battleEffectiveHit);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(8, 9), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitA.battleEffectiveCrit);

    PutTwoSpecialChar(gUnk_Tm_02003238 + TM_OFFSET(4, 3),
        TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_HP_A, TEXT_SPECIAL_HP_B);

    PutText(gBattlePreviewLabels+BATTLEPREVIEW_LABEL_DAMAGE, gUnk_Tm_02003238 + TM_OFFSET(3, 5));
    PutText(gBattlePreviewLabels+BATTLEPREVIEW_LABEL_HIT, gUnk_Tm_02003238 + TM_OFFSET(3, 7));
    PutText(gBattlePreviewLabels+BATTLEPREVIEW_LABEL_CRIT, gUnk_Tm_02003238 + TM_OFFSET(3, 9));

    PutIcon(gUnk_Tm_02003238 + TM_OFFSET(7, 11), GetItemIcon(gBattleUnitB.weaponBefore), TILEREF(0, BGPAL_ICONS+0));
    PutIcon(gUnk_Tm_02003238 + TM_OFFSET(1, 1), GetItemIcon(gBattleUnitA.weaponBefore), TILEREF(0, BGPAL_BATTLEPREVIEW_ICONALT));
}

static void DrawBattlePreviewContentsLong(struct BattlePreviewProc* proc)
{
    TmApplyTsa_t(gUnk_Tm_02003738, Tsa_BattlePreviewFrame_Long, TILEREF(BGCHR_BATTLEPREVIEW_FRAME, BGPAL_1));
    TmFillRect_t(gUnk_Tm_02003238, 10, 19, 0);

    PutBattlePreviewUnitName(gUnk_Tm_02003238 + TM_OFFSET(3, 1), &proc->unitNameTextA, &gBattleUnitA.unit);
    PutBattlePreviewUnitName(gUnk_Tm_02003238 + TM_OFFSET(1, 15), &proc->unitNameTextA, &gBattleUnitB.unit);
    PutBattlePreviewItemName(gUnk_Tm_02003238 + TM_OFFSET(1, 17), &proc->itemNameText, gBattleUnitB.weaponBefore);

    if (gBattleUnitB.weapon == 0)
    {
        gBattleUnitB.battleAttack = 0xFF;
        gBattleUnitB.battleEffectiveHit = 0xFF;
        gBattleUnitB.battleEffectiveCrit = 0xFF;
    }

    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(2, 3), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitB.hpPrevious);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(2, 5), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitB.battleAttack);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(2, 7), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitB.battleDefense);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(2, 9), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitB.battleEffectiveHit);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(2, 11), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitB.battleEffectiveCrit);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(2, 13), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitB.battleSpeed);

    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(8, 3), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitA.hpPrevious);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(8, 5), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitA.battleAttack);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(8, 7), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitA.battleDefense);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(8, 9), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitA.battleEffectiveHit);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(8, 11), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitA.battleEffectiveCrit);
    PutNumberTwoChr(gUnk_Tm_02003238 + TM_OFFSET(8, 13), TEXT_COLOR_SYSTEM_BLUE, gBattleUnitA.battleSpeed);

    PutTwoSpecialChar(gUnk_Tm_02003238 + TM_OFFSET(4, 3),
        TEXT_COLOR_SYSTEM_GOLD, TEXT_SPECIAL_HP_A, TEXT_SPECIAL_HP_B);

    PutText(gBattlePreviewLabels+BATTLEPREVIEW_LABEL_ATTACK, gUnk_Tm_02003238 + TM_OFFSET(3, 5));
    PutText(gBattlePreviewLabels+BATTLEPREVIEW_LABEL_DEFENSE, gUnk_Tm_02003238 + TM_OFFSET(3, 7));
    PutText(gBattlePreviewLabels+BATTLEPREVIEW_LABEL_HIT, gUnk_Tm_02003238 + TM_OFFSET(3, 9));
    PutText(gBattlePreviewLabels+BATTLEPREVIEW_LABEL_CRIT, gUnk_Tm_02003238 + TM_OFFSET(3, 11));
    PutText(gBattlePreviewLabels+BATTLEPREVIEW_LABEL_SPEED, gUnk_Tm_02003238 + TM_OFFSET(3, 13));

    PutIcon(gUnk_Tm_02003238 + TM_OFFSET(7, 15), GetItemIcon(gBattleUnitB.weaponBefore), TILEREF(0, BGPAL_ICONS+0));
    PutIcon(gUnk_Tm_02003238 + TM_OFFSET(1, 1), GetItemIcon(gBattleUnitA.weaponBefore), TILEREF(0, BGPAL_BATTLEPREVIEW_ICONALT));
}

static void DrawBattlePreviewContents(struct BattlePreviewProc* proc)
{
    proc->unk_2C = 0;
    proc->needContentUpdate = FALSE;

    switch (proc->frameKind)
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

static u16 const* GetFactionBattlePreviewFramePalette(int faction)
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

static void BattlePreview_Init(struct BattlePreviewProc* proc)
{
    Decompress(Img_BattlePreviewFrame, (void*) VRAM + BGCHR_BATTLEPREVIEW_FRAME*CHR_SIZE);

    Decompress(Img_BattlePreviewMultipliers, gBuf);
    Copy2dChr(gBuf, OBJ_VRAM0 + OBJCHR_BATTLEPREVIEW_MULTIPLIERS*CHR_SIZE, 4, 2);

    ApplyPalette(Pal_BattlePreviewMultipliers, 0x10+OBJPAL_BATTLEPREVIEW_MULTIPLIERS);

    ResetTextFont();
    InitIcons();
    InitBattlePreviewIconPalBuf();
    InitBattlePreviewLabels();

    InitTextDb(&proc->unitNameTextA, 6);
    InitTextDb(&proc->unitNameTextB, 6);
    InitTextDb(&proc->itemNameText, 7);

    SetBgOffset(1, 0, -1);

    proc->ready = TRUE;
}

static void BattlePreview_OnEnd(void)
{
    sub_8041308(-1);
}

static void PutBattlePreviewTilemaps(struct BattlePreviewProc* proc)
{
    int height = proc->frameKind == BATTLEPREVIEW_FRAME_SHORT ? 16 : 20;

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

static void PutBattlePreviewWtArrows(struct BattlePreviewProc* proc)
{
    enum { WT_ARROW_NONE, WT_ARROW_UP, WT_ARROW_DOWN };

    int wtArrowA = WT_ARROW_NONE;
    int wtArrowB = WT_ARROW_NONE;

    if (gBattleUnitA.wtHitBonus > 0)
        wtArrowA = WT_ARROW_UP;

    if (gBattleUnitA.wtHitBonus < 0)
        wtArrowA = WT_ARROW_DOWN;

    if (gBattleUnitB.wtHitBonus > 0)
        wtArrowB = WT_ARROW_UP;

    if (gBattleUnitB.wtHitBonus < 0)
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

static void PutBattlePreviewMultipliers(struct BattlePreviewProc* proc)
{
    int angle = (proc->unk_2C*4) & 0xFF;

    int x = SIN_Q12(angle)*4 >> 12;
    int y = COS_Q12(angle)*2 >> 12;

    x += proc->x*8-3;
    y += proc->y*8;

    if (proc->hitCountA > 1)
    {
        PutSprite(4, x+72, y+40, Sprite_16x16,
            OAM2_CHR(OBJCHR_BATTLEPREVIEW_MULTIPLIERS)
                + OAM2_PAL(OBJPAL_BATTLEPREVIEW_MULTIPLIERS)
                + proc->hitCountA-2);
    }

    if (proc->hitCountB > 1)
    {
        PutSprite(4, x+24, y+40, Sprite_16x16,
            OAM2_CHR(OBJCHR_BATTLEPREVIEW_MULTIPLIERS)
                + OAM2_PAL(OBJPAL_BATTLEPREVIEW_MULTIPLIERS)
                + proc->hitCountB-2);
    }
}

static void UpdateBattlePreviewEffectivenessPalettes(struct BattlePreviewProc* proc)
{
    static u8 palAnimLut[] =
    {
        0, 1, 1, 2, 3, 4, 5, 5,
        4, 4, 4, 3, 3, 3, 2, 2,
        2, 2, 1, 1, 1, 1, 1, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
    };

    int palAnim;

    if (proc->isEffectiveA)
        palAnim = palAnimLut[proc->unk_2C % sizeof(palAnimLut)];
    else
        palAnim = 0;

    ApplyPalette(gBattlePreviewIconPalBuf[palAnim], BGPAL_BATTLEPREVIEW_ICONALT);

    if (proc->isEffectiveB)
        palAnim = palAnimLut[proc->unk_2C % sizeof(palAnimLut)];
    else
        palAnim = 0;

    ApplyPalette(gBattlePreviewIconPalBuf[palAnim], BGPAL_ICONS+0);
}

static void BattlePreview_LoopDisplay(struct BattlePreviewProc* proc)
{
    proc->unk_2C++;

    if (proc->needContentUpdate)
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

    if (proc->frameKind == BATTLEPREVIEW_FRAME_SHORT)
    {
        PutBattlePreviewWtArrows(proc);
        PutBattlePreviewMultipliers(proc);
        UpdateBattlePreviewEffectivenessPalettes(proc);
    }
}

static void BattlePreview_OnNewBattle(struct BattlePreviewProc* proc)
{
    DrawBattlePreviewContents(proc);

    proc->side = GetBattlePreviewPanelSide();
    proc->unk_36 = 0;

    if (proc->side < 0)
        // left
        proc->x = 0;
    else
        // right
        proc->x = 20;

    proc->y = 0;

    InitBattlePreviewFramePalettes();
}

static void BattlePreview_LoopSlideIn(struct BattlePreviewProc* proc)
{
    static s8 offsetLut[] = { 6, 8, 9, 10 };
    int offset;

    int height = proc->frameKind == BATTLEPREVIEW_FRAME_SHORT ? 16 : 20;

    TmFill(gBg0Tm, 0);
    TmFill(gBg1Tm, 0);

    EnableBgSync(BG0_SYNC_BIT + BG1_SYNC_BIT);

    offset = offsetLut[proc->unk_36];

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

    proc->unk_36++;

    if ((u8) proc->unk_36 == 4)
    {
        proc->unk_36 = 0;
        Proc_Break(proc);
    }
}

static void BattlePreview_LoopSlideOut(struct BattlePreviewProc* proc)
{
    static s8 offsetLut[] = { 9, 8, 6, 0 };
    int offset;

    int height = proc->frameKind == BATTLEPREVIEW_FRAME_SHORT ? 16 : 20;

    TmFill(gBg0Tm, 0);
    TmFill(gBg1Tm, 0);

    EnableBgSync(BG0_SYNC_BIT + BG1_SYNC_BIT);

    offset = offsetLut[proc->unk_36];

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

    proc->unk_36++;

    if ((u8) proc->unk_36 == 4)
    {
        proc->unk_36 = 0;
        Proc_Break(proc);
    }
}

struct ProcScr CONST_DATA ProcScr_BattlePreview[] =
{
    PROC_19,

    PROC_ONEND(BattlePreview_OnEnd),

    PROC_CALL(ClearBg0Bg1),
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

void StartBattlePreview(void)
{
    struct BattlePreviewProc* proc;

    if (gPlaySt.configBattlePreviewKind == 2)
    {
        ResetTextFont();
        return;
    }

    proc = SpawnProc(ProcScr_BattlePreview, PROC_TREE_3);
    proc->ready = FALSE;

    switch (gPlaySt.configBattlePreviewKind)
    {

    case 0:
        proc->frameKind = BATTLEPREVIEW_FRAME_SHORT;
        break;

    case 1:
        proc->frameKind = BATTLEPREVIEW_FRAME_LARGE;
        break;

    }

    MapFill(gMapMovement, -1);
}

void UpdateBattlePreviewContents(void)
{
    struct BattlePreviewProc* proc = Proc_Find(ProcScr_BattlePreview);

    if (proc == NULL)
        return;

    if (proc->ready)
        proc->needContentUpdate = TRUE;
}

void CloseBattlePreview(void)
{
    struct BattlePreviewProc* proc = Proc_Find(ProcScr_BattlePreview);

    if (proc == NULL)
        return;

    if (!proc->ready)
    {
        ClearBg0Bg1();

        Proc_End(proc);
        return;
    }

    Proc_Goto(proc, 1);
}

int StartBattlePreviewHelpBox(ProcPtr parent)
{
    int x;

    struct BattlePreviewProc* proc = Proc_Find(ProcScr_BattlePreview);

    if (proc == NULL)
        return 0;

    if (proc->side < 0)
        // left
        x = 0;
    else
        // right
        x = 20;

    sub_8070E70(NULL, -1);

    switch (proc->frameKind)
    {

    case BATTLEPREVIEW_FRAME_SHORT:
        StartMovingHelpBoxExt(&HelpInfo_BpShort_Hp, parent, x, 0);
        break;

    case BATTLEPREVIEW_FRAME_LARGE:
        StartMovingHelpBoxExt(&HelpInfo_BpLarge_Hp, parent, x, 0);
        break;

    }

    return 0;
}

static int sub_802E43C(int wt, bool isEffective)
{
    static u16 lut[] =
    {
        0x6A4,
        0x6A6,
        0x6A8,
        0x6A5,
        0x6A7,
        0x6A9,
    };

    int idx = isEffective ? 3 : 0;

    if (wt < 0)
        idx += 2;

    if (wt > 0)
        idx += 1;

    return lut[idx];
}

void sub_802E460(struct GenericProc* proc)
{
    struct BattlePreviewProc* bp = Proc_Find(ProcScr_BattlePreview);
    proc->unk4C = sub_802E43C(gBattleUnitA.wtHitBonus, bp->isEffectiveA);
}

void sub_802E490(struct GenericProc* proc)
{
    struct BattlePreviewProc* bp = Proc_Find(ProcScr_BattlePreview);
    proc->unk4C = sub_802E43C(gBattleUnitB.wtHitBonus, bp->isEffectiveB);
}
