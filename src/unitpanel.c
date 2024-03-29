#include "unitpanel.h"

#include "armfunc.h"
#include "proc.h"
#include "oam.h"
#include "icon.h"
#include "sprite.h"
#include "text.h"
#include "msg.h"
#include "item.h"
#include "unit.h"
#include "unitsprite.h"
#include "faction.h"
#include "ui.h"

#include "constants/videoalloc_global.h"

enum { LINES_MAX = 5 };

struct UnitPanelProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ struct Unit * unit;

    /* 30 */ struct Text name;
    /* 38 */ struct Text lines[LINES_MAX];

    /* 60 */ u8 x;
    /* 61 */ u8 y;
    /* 62 */ u8 xUnitSprite;
    /* 63 */ u8 xNameText;
};

static void UnitPanel_OnLoop(struct UnitPanelProc * proc);

struct ProcScr CONST_DATA ProcScr_UnitPanel[] =
{
    PROC_REPEAT(UnitPanel_OnLoop),
    PROC_END,
};

static struct UnitPanelProc * EWRAM_DATA sRescueUnitPanels[2] = {};

static void UnitPanel_OnLoop(struct UnitPanelProc * proc)
{
    SHOULD_BE_STATIC u16 SHOULD_BE_CONST factionPalLut[] =
    {
        [FACTION_ID_BLUE] = OBPAL_UNITSPRITE_BLUE,
        [FACTION_ID_GREEN] = OBPAL_UNITSPRITE_GREEN,
        [FACTION_ID_RED] = OBPAL_UNITSPRITE_RED,
    };

    int x = 8*proc->x + proc->xUnitSprite;
    int y = 8*(proc->y+1);

    if (proc->unit->flags & UNIT_FLAG_RESCUED)
    {
        if (GetGameTime() % 32 >= 20)
            return;

        PutSprite(2,
            x+9, y+7, Sprite_8x8,
            OAM2_CHR(OBCHR_SYSTEM_OBJECTS + 3) + OAM2_PAL(factionPalLut[proc->unit->rescue >> 6]));
    }
    else
    {
        PutUnitSpriteExt(2, x, y, 0, proc->unit);
    }
}

static struct UnitPanelProc * StartUnitPanel(ProcPtr parent)
{
    struct UnitPanelProc * proc = SpawnProc(ProcScr_UnitPanel, parent);

    InitTextDb(&proc->name, 6);

    ClearIcons();
    ApplyIconPalettes(BGPAL_ICONS);

    return proc;
}

static void InitUnitPanelSpriteTextPositions(struct UnitPanelProc * proc)
{
    if (GetStringTextLen(DecodeMsg(proc->unit->pinfo->msg_name)) < 40)
    {
        proc->xUnitSprite = 4;
        proc->xNameText = 24;
    }
    else
    {
        proc->xUnitSprite = 0;
        proc->xNameText = 16;
    }

    proc->xUnitSprite += 8;
    proc->xNameText -= 16;
}

static struct UnitPanelProc * InitUnitPanel(struct UnitPanelProc * proc, struct Unit * unit, int x, int y, int width, int lines)
{
    if (proc == NULL)
    {
        proc = FindProc(ProcScr_UnitPanel);
        ClearUi();
    }

    proc->unit = unit;
    proc->x = x;
    proc->y = y;

    PutUiWindowFrame(x, y+2, width, 2 + lines*2, UI_WINDOW_REGULAR);
    TmApplyTsa(gBg1Tm + TM_OFFSET(x, y), Tsa_UnitPanelHeader, TILEREF(BGCHR_WINDOWFRAME, BGPAL_WINDOWFRAME));

    if (width > 10)
    {
        int ix;

        for (ix = x+10; ix < x+width-1; ++ix)
            gBg1Tm[TM_OFFSET(ix, y+2)] = TILEREF(BGCHR_WINDOWFRAME+0x0B, BGPAL_WINDOWFRAME);

        gBg1Tm[TM_OFFSET(x+9,       y+2)] = TILEREF(BGCHR_WINDOWFRAME+0x26, BGPAL_WINDOWFRAME);
        gBg1Tm[TM_OFFSET(x+width-1, y+2)] = TILEREF(BGCHR_WINDOWFRAME+0x0C, BGPAL_WINDOWFRAME);
    }

    ClearText(&proc->name);

    InitUnitPanelSpriteTextPositions(proc);

    Text_SetCursor(&proc->name, proc->xNameText);
    Text_DrawString(&proc->name, DecodeMsg(unit->pinfo->msg_name));

    PutText(&proc->name, gBg0Tm + TM_OFFSET(x+3, y+1));

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);

    return proc;
}

static int GetUnitPanelXForUnit(struct Unit * unit, int width)
{
    if (unit->x*16 - gBmSt.camera.x < DISPLAY_WIDTH/2)
        return 30 - width;

    return 0;
}

static void DrawUnitHpText(struct Text * text, struct Unit * unit)
{
    ClearText(text);

    Text_InsertDrawString(text, 0,  TEXT_COLOR_SYSTEM_GOLD, JTEXT("ＨＰ"));
    Text_InsertDrawString(text, 40, TEXT_COLOR_SYSTEM_GOLD, JTEXT("／"));

    Text_InsertDrawNumberOrBlank(text, 32, TEXT_COLOR_SYSTEM_BLUE, GetUnitCurrentHp(unit));
    Text_InsertDrawNumberOrBlank(text, 56, TEXT_COLOR_SYSTEM_BLUE, GetUnitMaxHp(unit));
}

static void DrawUnitConText(struct Text * text, struct Unit * unit)
{
    ClearText(text);

    Text_InsertDrawString(text, 0, TEXT_COLOR_SYSTEM_GOLD, TEXT("体格", "Con"));
    Text_InsertDrawNumberOrBlank(text, 56, TEXT_COLOR_SYSTEM_BLUE, UNIT_CON(unit));
}

static void DrawUnitAidText(struct Text * text, struct Unit * unit)
{
    ClearText(text);

    Text_InsertDrawString(text, 0, TEXT_COLOR_SYSTEM_GOLD, TEXT("救出", "Aid"));
    Text_InsertDrawNumberOrBlank(text, 56, TEXT_COLOR_SYSTEM_BLUE, GetUnitAid(unit));
}

static void PutUnitAidIconForTextAt(struct Unit * unit, int x, int y)
{
    PutIcon(gBg0Tm + TM_OFFSET(x+4, y),
        GetAidIconFromAttributes(UNIT_ATTRIBUTES(unit)),
        TILEREF(0, BGPAL_ICONS+1));
}

static void DrawUnitStatusText(struct Text * text, struct Unit * unit)
{
    ClearText(text);

    Text_InsertDrawString(text, 0,  TEXT_COLOR_SYSTEM_GOLD, TEXT("状態", "Status"));
    Text_InsertDrawString(text, 32, TEXT_COLOR_SYSTEM_BLUE, GetUnitStatusName(unit));
}

static void DrawUnitResChangeText(struct Text * text, struct Unit * unit, int bonus)
{
    ClearText(text);

    Text_InsertDrawString(text, 0,  TEXT_COLOR_SYSTEM_GOLD, TEXT("魔防", "Res"));
    Text_InsertDrawString(text, 40, TEXT_COLOR_SYSTEM_GOLD, JTEXT("→"));

    Text_InsertDrawNumberOrBlank(text, 56, TEXT_COLOR_SYSTEM_BLUE, GetUnitResistance(unit) + bonus);
    Text_InsertDrawNumberOrBlank(text, 32, TEXT_COLOR_SYSTEM_BLUE, GetUnitResistance(unit));
}

static void DrawUnitResUnkText(struct Text * text, struct Unit * unit, int unused)
{
    ClearText(text);

    Text_InsertDrawString(text, 0, TEXT_COLOR_SYSTEM_GOLD, TEXT("魔防", "Res"));
    Text_InsertDrawNumberOrBlank(text, 56, TEXT_COLOR_SYSTEM_BLUE, GetUnitResistance(unit));
}

static void DrawAccuracyText(struct Text * text, int accuracy)
{
    ClearText(text);

    Text_InsertDrawString(text, 0, TEXT_COLOR_SYSTEM_GOLD, TEXT("命中", "Hit"));
    Text_InsertDrawNumberOrBlank(text, 56, TEXT_COLOR_SYSTEM_BLUE, accuracy);
}

void StartUnitInventoryPanel(ProcPtr parent)
{
    int i;

    struct UnitPanelProc * proc = StartUnitPanel(parent);

    for (i = 0; i < LINES_MAX; ++i)
        InitTextDb(proc->lines + i, 7);
}

void RefreshUnitInventoryPanel(struct Unit * unit)
{
    enum { YPOSITION = 0 };
    enum { WIDTH = 13 };

    int i, itemCount, xPosition;
    struct UnitPanelProc * proc;

    itemCount = GetUnitItemCount(unit);

    xPosition = GetUnitPanelXForUnit(unit, WIDTH);

    proc = InitUnitPanel(NULL, unit, xPosition, YPOSITION, WIDTH, itemCount != 0 ? itemCount : 1);

    if (itemCount == 0)
    {
        int offset;

        ClearText(proc->lines+0);
        Text_InsertDrawString(proc->lines+0, 0, TEXT_COLOR_SYSTEM_GRAY, TEXT("何もありません", "Nothing"));

        offset = TM_OFFSET(xPosition+3, YPOSITION+3);
        PutText(proc->lines+0, gBg0Tm + offset);

        return;
    }

    for (i = 0; i < itemCount; ++i)
    {
        int yPosition = YPOSITION + i*2 + 3;

        int item = unit->items[i];

        ClearText(proc->lines+i);
        Text_DrawString(proc->lines+i, GetItemName(item));

        PutText(proc->lines+i, gBg0Tm + TM_OFFSET(xPosition+3, yPosition));
        PutNumberOrBlank(gBg0Tm + TM_OFFSET(xPosition+11, yPosition), TEXT_COLOR_SYSTEM_BLUE, GetItemUses(item));
        PutIcon(gBg0Tm + TM_OFFSET(xPosition+1, yPosition), GetItemIcon(item), TILEREF(0, BGPAL_ICONS));
    }
}

void RefreshUnitStealInventoryPanel(struct Unit * unit)
{
    enum { YPOSITION = 0 };
    enum { WIDTH = 13 };

    int i, itemCount, xPosition;
    struct UnitPanelProc * proc;

    itemCount = GetUnitItemCount(unit);

    xPosition = GetUnitPanelXForUnit(unit, WIDTH);

    proc = InitUnitPanel(NULL, unit, xPosition, YPOSITION, WIDTH, itemCount);

    for (i = 0; i < itemCount; ++i)
    {
        int yPosition = YPOSITION + i*2 + 3;

        int item = unit->items[i];
        bool stealable = IsItemStealable(item);

        ClearText(proc->lines+i);

        Text_SetColor(proc->lines+i, stealable ? TEXT_COLOR_SYSTEM_WHITE : TEXT_COLOR_SYSTEM_GRAY);
        Text_DrawString(proc->lines+i, GetItemName(item));

        PutText(proc->lines+i, gBg0Tm + TM_OFFSET(xPosition+3, yPosition));

        PutNumberOrBlank(gBg0Tm + TM_OFFSET(xPosition+11, yPosition), stealable ? TEXT_COLOR_SYSTEM_BLUE : TEXT_COLOR_SYSTEM_GRAY, GetItemUses(item));
        PutIcon(gBg0Tm + TM_OFFSET(xPosition+1, yPosition), GetItemIcon(item), TILEREF(0, BGPAL_ICONS));
    }
}

void RefreshUnitRepairInventoryPanel(struct Unit * unit)
{
    enum { YPOSITION = 0 };
    enum { WIDTH = 16 };

    int i, color, itemCount, xPosition;
    struct UnitPanelProc * proc;

    itemCount = GetUnitItemCount(unit);

    xPosition = GetUnitPanelXForUnit(unit, WIDTH);

    proc = InitUnitPanel(NULL, unit, xPosition, YPOSITION, WIDTH, itemCount);

    for (i = 0; i < itemCount; ++i)
    {
        int yPosition = YPOSITION + i*2 + 3;

        int item = unit->items[i];

        color = IsItemRepairable(item) ? TEXT_COLOR_SYSTEM_WHITE : TEXT_COLOR_SYSTEM_GRAY;

        ClearText(proc->lines+i);

        Text_SetColor(proc->lines+i, color);
        Text_DrawString(proc->lines+i, GetItemName(item));

        PutText(proc->lines+i, gBg0Tm + TM_OFFSET(xPosition+3, yPosition));
        PutSpecialChar(gBg0Tm + TM_OFFSET(xPosition+12, yPosition), color, TEXT_SPECIAL_SLASH);

        color = IsItemRepairable(item) ? TEXT_COLOR_SYSTEM_BLUE : TEXT_COLOR_SYSTEM_GRAY;

        PutNumberOrBlank(gBg0Tm + TM_OFFSET(xPosition+11, yPosition), color, GetItemUses(item));
        PutNumberOrBlank(gBg0Tm + TM_OFFSET(xPosition+14, yPosition), color, GetItemMaxUses(item));

        PutIcon(gBg0Tm + TM_OFFSET(xPosition+1, yPosition), GetItemIcon(item), TILEREF(0, BGPAL_ICONS));
    }

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);
}

void StartUnitHpPanel(ProcPtr parent)
{
    struct UnitPanelProc * proc = StartUnitPanel(parent);

    InitTextDb(proc->lines+0, 8);
}

void RefreshUnitHpPanel(struct Unit * unit)
{
    enum { WIDTH = 10 };

    int y = 0;
    int x = GetUnitPanelXForUnit(unit, WIDTH);

    struct UnitPanelProc * proc = InitUnitPanel(NULL, unit, x, y, WIDTH, 1);

    DrawUnitHpText(proc->lines+0, unit);
    PutText(proc->lines+0, gBg0Tm + TM_OFFSET(x+1, y+3));
}

void StartUnitHpStatusPanel(ProcPtr parent)
{
    struct UnitPanelProc * proc = StartUnitPanel(parent);

    InitTextDb(proc->lines+0, 8);
    InitTextDb(proc->lines+1, 8);
}

void RefreshUnitHpStatusPanel(struct Unit * unit)
{
    enum { WIDTH = 10 };

    int y = 0;
    int x = GetUnitPanelXForUnit(unit, WIDTH);

    struct UnitPanelProc * proc = InitUnitPanel(NULL, unit, x, y, WIDTH, 2);

    DrawUnitHpText(proc->lines+0, unit);
    PutText(proc->lines+0, gBg0Tm + TM_OFFSET(x+1, y+3));

    DrawUnitStatusText(proc->lines+1, unit);
    PutText(proc->lines+1, gBg0Tm + TM_OFFSET(x+1, y+5));
}

void StartUnitResChangePanel(ProcPtr parent)
{
    struct UnitPanelProc * proc = StartUnitPanel(parent);

    InitTextDb(proc->lines+0, 8);
}

void RefreshUnitResChangePanel(struct Unit * unit)
{
    enum { WIDTH = 10 };

    int y = 0;
    int x = GetUnitPanelXForUnit(unit, WIDTH);

    struct UnitPanelProc * proc = InitUnitPanel(NULL, unit, x, y, WIDTH, 1);

    // TODO: named constant for barrier duration?
    DrawUnitResChangeText(proc->lines+0, unit, 7 - unit->barrier);
    PutText(proc->lines+0, gBg0Tm + TM_OFFSET(x+1, y+3));
}

void StartUnitStaffOffensePanel(ProcPtr parent)
{
    struct UnitPanelProc * proc = StartUnitPanel(parent);

    InitTextDb(proc->lines+0, 8);
    InitTextDb(proc->lines+1, 8);
}

void RefreshUnitStaffOffensePanel(struct Unit * unit, int hit)
{
    enum { WIDTH = 10 };

    int y = 0;
    int x = GetUnitPanelXForUnit(unit, WIDTH);

    struct UnitPanelProc * proc = InitUnitPanel(NULL, unit, x, y, WIDTH, 2);

    // TODO: named constant for barrier duration?
    DrawUnitResUnkText(proc->lines+0, unit, 7 - unit->barrier);
    PutText(proc->lines+0, gBg0Tm + TM_OFFSET(x+1, y+3));

    DrawAccuracyText(proc->lines+1, hit);
    PutText(proc->lines+1, gBg0Tm + TM_OFFSET(x+1, y+5));
}

static void StartUnitRescuePanelsCore(ProcPtr parent)
{
    sRescueUnitPanels[0] = StartUnitPanel(parent);
    InitTextDb(sRescueUnitPanels[0]->lines+0, 8);

    sRescueUnitPanels[1] = StartUnitPanel(parent);
    InitTextDb(sRescueUnitPanels[1]->lines+0, 8);
}

void RefreshUnitTakeRescuePanels(ProcPtr parent)
{
    InitIcons();
    ApplyIconPalettes(BGPAL_ICONS);

    StartUnitRescuePanelsCore(parent);

    StartSpriteRefresher(parent, 2, 0, 0,
        Sprite_16x16_VFlipped, OAM2_CHR(OBCHR_SYSTEM_OBJECTS+6));
}

void RefreshUnitRescuePanels(struct Unit * unit)
{
    enum { WIDTH = 10 };

    int y = 0;
    int x = GetUnitPanelXForUnit(unit, WIDTH);

    ClearUi();

    InitUnitPanel(sRescueUnitPanels[0], gActiveUnit, x, y, WIDTH, 1);

    DrawUnitAidText(sRescueUnitPanels[0]->lines+0, gActiveUnit);
    PutText(sRescueUnitPanels[0]->lines+0, gBg0Tm + TM_OFFSET(x+1, y+3));

    PutUnitAidIconForTextAt(gActiveUnit, x+1, y+3);

    InitUnitPanel(sRescueUnitPanels[1], unit, x, y+6, WIDTH, 1);

    DrawUnitConText(sRescueUnitPanels[1]->lines+0, unit);
    PutText(sRescueUnitPanels[1]->lines+0, gBg0Tm + TM_OFFSET(x+1, y+6+3));

    MoveSpriteRefresher(NULL, (x+4)*8, (y+4)*8+7);
}

void RefreshUnitTakePanels(struct Unit * unit)
{
    enum { WIDTH = 10 };

    struct Unit * rescue;

    int y = 0;
    int x = GetUnitPanelXForUnit(unit, WIDTH);

    ClearUi();

    rescue = GetUnit(unit->rescue);

    InitUnitPanel(sRescueUnitPanels[0], gActiveUnit, x, y, WIDTH, 1);

    DrawUnitAidText(sRescueUnitPanels[0]->lines+0, gActiveUnit);
    PutText(sRescueUnitPanels[0]->lines+0, gBg0Tm + TM_OFFSET(x+1, y+3));

    PutUnitAidIconForTextAt(gActiveUnit, x+1, y+3);

    InitUnitPanel(sRescueUnitPanels[1], rescue, x, y+6, WIDTH, 1);

    DrawUnitConText(sRescueUnitPanels[1]->lines+0, rescue);
    PutText(sRescueUnitPanels[1]->lines+0, gBg0Tm + TM_OFFSET(x+1, y+6+3));

    MoveSpriteRefresher(NULL, (x+4)*8, (y+4)*8+7);
}

void StartUnitGiveRescuePanels(ProcPtr parent)
{
    InitIcons();
    ApplyIconPalettes(BGPAL_ICONS);

    StartUnitRescuePanelsCore(parent);

    StartSpriteRefresher(parent, 2, 0, 0,
        Sprite_16x16, OAM2_CHR(OBCHR_SYSTEM_OBJECTS+6));
}

void RefreshUnitGivePanels(struct Unit * unit)
{
    enum { WIDTH = 10 };

    int y = 0;
    int x = GetUnitPanelXForUnit(unit, WIDTH);

    struct Unit * rescue = GetUnit(gActiveUnit->rescue);

    ClearUi();

    InitUnitPanel(sRescueUnitPanels[0], rescue, x, y, WIDTH, 1);

    DrawUnitConText(sRescueUnitPanels[0]->lines+0, rescue);
    PutText(sRescueUnitPanels[0]->lines+0, gBg0Tm + TM_OFFSET(x+1, y+3));

    InitUnitPanel(sRescueUnitPanels[1], unit, x, y+6, WIDTH, 1);

    DrawUnitAidText(sRescueUnitPanels[1]->lines+0, unit);
    PutText(sRescueUnitPanels[1]->lines+0, gBg0Tm + TM_OFFSET(x+1, y+6+3));

    PutUnitAidIconForTextAt(unit, x+1, y+6+3);

    MoveSpriteRefresher(NULL, (x+4)*8, (y+4)*8+7);
}
