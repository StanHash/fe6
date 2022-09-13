
#include "common.h"

#include "hardware.h"
#include "oam.h"
#include "sound.h"
#include "icon.h"
#include "sprite.h"
#include "face.h"
#include "msg.h"
#include "item.h"
#include "unit.h"
#include "action.h"
#include "ui.h"

#include "constants/video-global.h"
#include "constants/songs.h"

extern struct Text gTradeMenuText[2][ITEMSLOT_INV_COUNT];

enum
{
    // MAGIC CONSTANTS

    UNIT_PANEL_WIDTH = 6,

    ITEM_PANEL_WIDTH = 7,

    ITEM_PANEL_LEFT_X = 1,
    ITEM_PANEL_LEFT_Y = 8,

    ITEM_PANEL_RIGHT_X = 15,
    ITEM_PANEL_RIGHT_Y = 8,
};

enum
{
    TRADEMENU_UNIT_UNDEFINED = 0xFF,

    TRADEMENU_UNIT_LEFT  = 0,
    TRADEMENU_UNIT_RIGHT = 1,
};

enum
{
    L_TRADEMENU_UNSELECTED = 0,
    L_TRADEMENU_SELECTED   = 1,
    L_TRADEMENU_END        = 2,
};

struct TradeMenuProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ struct Unit * units[2];

    /* 34 */ bool hasItem[2][ITEMSLOT_INV_COUNT + 1];

    /* 40 */ bool hasTraded;

    /* 41 */ u8 hoverColumn;
    /* 42 */ u8 hoverRow;

    /* 43 */ u8 selectedColumn;
    /* 44 */ u8 selectedRow;

    /* 45 */ bool extraCellEnabled;

    /* 46 */ u8 extraColumn;
    /* 47 */ u8 extraRow;

    /* 48 */ u8 tradeTutorialState;

    /* 49 */ u8 pad[0x4C - 0x49];
    /* 4C */ short timer;
};

struct Vec2i CONST_DATA sItemDisplayTileLocation[2][ITEMSLOT_INV_COUNT] =
{
    [TRADEMENU_UNIT_LEFT] =
    {
        { ITEM_PANEL_LEFT_X + 1, ITEM_PANEL_LEFT_Y + 1 },
        { ITEM_PANEL_LEFT_X + 1, ITEM_PANEL_LEFT_Y + 3 },
        { ITEM_PANEL_LEFT_X + 1, ITEM_PANEL_LEFT_Y + 5 },
        { ITEM_PANEL_LEFT_X + 1, ITEM_PANEL_LEFT_Y + 7 },
        { ITEM_PANEL_LEFT_X + 1, ITEM_PANEL_LEFT_Y + 9 },
    },

    [TRADEMENU_UNIT_RIGHT] =
    {
        { ITEM_PANEL_RIGHT_X + 1, ITEM_PANEL_RIGHT_Y + 1 },
        { ITEM_PANEL_RIGHT_X + 1, ITEM_PANEL_RIGHT_Y + 3 },
        { ITEM_PANEL_RIGHT_X + 1, ITEM_PANEL_RIGHT_Y + 5 },
        { ITEM_PANEL_RIGHT_X + 1, ITEM_PANEL_RIGHT_Y + 7 },
        { ITEM_PANEL_RIGHT_X + 1, ITEM_PANEL_RIGHT_Y + 9 },
    },
};

u16 CONST_DATA Sprite_085C6234[] =
{
    12,
    OAM0_SHAPE_32x8,              OAM1_SIZE_32x8 + OAM1_X(-8) + OAM1_HFLIP, OAM2_CHR(0x12),
    OAM0_SHAPE_32x8 + OAM0_Y(8),  OAM1_SIZE_32x8 + OAM1_X(-8) + OAM1_HFLIP, OAM2_CHR(0x12),
    OAM0_SHAPE_32x8 + OAM0_Y(16), OAM1_SIZE_32x8 + OAM1_X(-8) + OAM1_HFLIP, OAM2_CHR(0x1A),
    OAM0_SHAPE_32x8,              OAM1_SIZE_32x8 + OAM1_X(24) + OAM1_HFLIP, OAM2_CHR(0x0E),
    OAM0_SHAPE_32x8 + OAM0_Y(8),  OAM1_SIZE_32x8 + OAM1_X(24) + OAM1_HFLIP, OAM2_CHR(0x0E),
    OAM0_SHAPE_32x8 + OAM0_Y(16), OAM1_SIZE_32x8 + OAM1_X(24) + OAM1_HFLIP, OAM2_CHR(0x16),
    OAM0_SHAPE_32x8,              OAM1_SIZE_32x8 + OAM1_X(216),             OAM2_CHR(0x12),
    OAM0_SHAPE_32x8 + OAM0_Y(8),  OAM1_SIZE_32x8 + OAM1_X(216),             OAM2_CHR(0x12),
    OAM0_SHAPE_32x8 + OAM0_Y(16), OAM1_SIZE_32x8 + OAM1_X(216),             OAM2_CHR(0x1A),
    OAM0_SHAPE_32x8,              OAM1_SIZE_32x8 + OAM1_X(184),             OAM2_CHR(0x0E),
    OAM0_SHAPE_32x8 + OAM0_Y(8),  OAM1_SIZE_32x8 + OAM1_X(184),             OAM2_CHR(0x0E),
    OAM0_SHAPE_32x8 + OAM0_Y(16), OAM1_SIZE_32x8 + OAM1_X(184),             OAM2_CHR(0x16),
};

static void TradeMenu_HighlightUpdater_Init(struct TradeMenuProc * proc);
static void TradeMenu_HighlightUpdater_Loop(struct TradeMenuProc * proc);

struct ProcScr CONST_DATA ProcScr_TradeMenu_HighlightUpdater[] =
{
    PROC_CALL(TradeMenu_HighlightUpdater_Init),
    PROC_REPEAT(TradeMenu_HighlightUpdater_Loop),

    PROC_END
};

static void TradeMenu_InitItemDisplay(struct TradeMenuProc * proc);
static void TradeMenu_InitUnitNameDisplay(struct TradeMenuProc * proc);
static bool TradeMenu_LoadForcedInitialHover(struct TradeMenuProc * proc);
static void TradeMenu_OnInitUnselected(struct TradeMenuProc * proc);
static void TradeMenu_OnLoopUnselected(struct TradeMenuProc * proc);
static void TradeMenu_OnInitSelected(struct TradeMenuProc * proc);
static void TradeMenu_OnLoopSelected(struct TradeMenuProc * proc);
static void TradeMenu_OnEndSelected(struct TradeMenuProc * proc);
static void TradeMenu_ClearDisplay(struct TradeMenuProc * proc);

struct ProcScr CONST_DATA ProcScr_TradeMenu[] =
{
    PROC_CALL(LockGame),
    PROC_SLEEP(0),

    PROC_WHILE_EXISTS(ProcScr_CamMove),

    PROC_CALL(TradeMenu_InitItemDisplay),
    PROC_CALL(TradeMenu_InitUnitNameDisplay),

    PROC_START_CHILD(ProcScr_TradeMenu_HighlightUpdater),

    PROC_CALL_2(TradeMenu_LoadForcedInitialHover),

PROC_LABEL(L_TRADEMENU_UNSELECTED),
    PROC_CALL(TradeMenu_OnInitUnselected),
    PROC_REPEAT(TradeMenu_OnLoopUnselected),

PROC_LABEL(L_TRADEMENU_SELECTED),
    PROC_CALL(TradeMenu_OnInitSelected),
    PROC_REPEAT(TradeMenu_OnLoopSelected),

    PROC_CALL(TradeMenu_OnEndSelected),

    PROC_GOTO(L_TRADEMENU_UNSELECTED),

PROC_LABEL(L_TRADEMENU_END),
    PROC_CALL(TradeMenu_ClearDisplay),
    PROC_CALL(ClearUi),

    PROC_CALL(UnlockGame),

    PROC_END
};

static void TradeMenu_HelpBox_OnInit(struct GenericProc * proc);
static void TradeMenu_HelpBox_OnLoop(struct GenericProc * proc);
static void TradeMenu_HelpBox_OnEnd(struct GenericProc * proc);

struct ProcScr CONST_DATA ProcScr_TradeMenu_HelpBox[] =
{
    PROC_CALL(TradeMenu_HelpBox_OnInit),
    PROC_REPEAT(TradeMenu_HelpBox_OnLoop),

    PROC_CALL(TradeMenu_HelpBox_OnEnd),

    PROC_END
};

static void TradeMenu_InitUnitNameDisplay(struct TradeMenuProc * proc)
{
    char const * str;
    int x;

    UnpackUiUnitNameFrameGraphics((u8 *) OBJ_VRAM0 + CHR_SIZE*OBJCHR_TRADEMENU_240, 0x10 + OBJPAL_TRADEMENU_8, 1);

    StartSpriteRefresher(proc, 7, 0, -4, Sprite_085C6234, OAM2_PAL(OBJPAL_TRADEMENU_8) + OAM2_CHR(OBJCHR_TRADEMENU_240) + OAM2_LAYER(2));

    str = DecodeMsg(proc->units[TRADEMENU_UNIT_LEFT]->pinfo->msg_name);
    x = (UNIT_PANEL_WIDTH*8 - GetStringTextLen(str))/2;
    PutDrawText(NULL, gBg0Tm + TM_OFFSET(0, 0), TEXT_COLOR_SYSTEM_WHITE, x, UNIT_PANEL_WIDTH, str);

    str = DecodeMsg(proc->units[TRADEMENU_UNIT_RIGHT]->pinfo->msg_name);
    x = (UNIT_PANEL_WIDTH*8 - GetStringTextLen(str))/2;
    PutDrawText(NULL, gBg0Tm + TM_OFFSET(24, 0), TEXT_COLOR_SYSTEM_WHITE, x, UNIT_PANEL_WIDTH, str);

    EnableBgSync(BG0_SYNC_BIT);
}

static void TradeMenu_HighlightUpdater_Init(struct TradeMenuProc * proc)
{
    proc->hoverColumn = TRADEMENU_UNIT_UNDEFINED;
}

static void TradeMenu_HighlightUpdater_Loop(struct TradeMenuProc * proc)
{
    struct TradeMenuProc * tradeMenu = proc->proc_parent;

    if (proc->hoverColumn == tradeMenu->hoverColumn && proc->hoverRow == tradeMenu->hoverRow)
        return;

    if (proc->hoverColumn != TRADEMENU_UNIT_UNDEFINED)
    {
        RemoveUiEntryHover(
            sItemDisplayTileLocation[proc->hoverColumn][proc->hoverRow].x,
            sItemDisplayTileLocation[proc->hoverColumn][proc->hoverRow].y,
            12);
    }

    PutUiEntryHover(
        sItemDisplayTileLocation[tradeMenu->hoverColumn][tradeMenu->hoverRow].x,
        sItemDisplayTileLocation[tradeMenu->hoverColumn][tradeMenu->hoverRow].y,
        12);

    proc->hoverColumn = tradeMenu->hoverColumn;
    proc->hoverRow = tradeMenu->hoverRow;
}

static int TradeMenu_GetAdjustedRow(struct TradeMenuProc * proc, int col, int row)
{
    while (proc->hasItem[col][row] == 0 && row >= 0)
        row--;

    return row;
}

static void TradeMenu_InitItemText(struct TradeMenuProc * proc)
{
    int col, row;

    for (col = 0; col < 2; ++col)
    {
        for (row = 0; row < ITEMSLOT_INV_COUNT; ++row)
        {
            InitTextDb(&gTradeMenuText[col][row], ITEM_PANEL_WIDTH);
        }
    }
}

static void TradeMenu_RefreshItemText(struct TradeMenuProc * proc)
{
    u8 xLookup[] = { ITEM_PANEL_LEFT_X, ITEM_PANEL_RIGHT_X };
    u8 yLookup[] = { ITEM_PANEL_LEFT_Y, ITEM_PANEL_RIGHT_Y };

    int col, row;

    CpuFastFill(0, gBg0Tm + TM_OFFSET(0, 9), 11 * 0x20 * sizeof(u16));

    for (col = 0; col < 2; ++col)
    {
        for (row = 0; row < ITEMSLOT_INV_COUNT; ++row)
        {
            int item = proc->units[col]->items[row];

            ClearText(&gTradeMenuText[col][row]);

            if (item)
            {
                func_fe6_08016694(&gTradeMenuText[col][row], item, IsItemDisplayUseable(proc->units[col], item),
                    gBg0Tm + TM_OFFSET(xLookup[col] + 1, yLookup[col] + row * 2 + 1));
            }
        }
    }

    EnableBgSync(BG0_SYNC_BIT);
}

static void TradeMenu_RefreshSelectableCells(struct TradeMenuProc * proc)
{
    int col, row;

    for (col = 0; col < 2; ++col)
    {
        for (row = 0; row < ITEMSLOT_INV_COUNT; ++row)
        {
            u16 item = proc->units[col]->items[row];
            proc->hasItem[col][row] = (item ? TRUE : FALSE);
        }
    }

    proc->hasItem[0][ITEMSLOT_INV_COUNT] = 0;
    proc->hasItem[1][ITEMSLOT_INV_COUNT] = 0;
}

static bool TradeMenu_UpdateSelection(struct TradeMenuProc * proc)
{
    bool changedSelection = FALSE;
    int newSelectedRow;

    if ((gKeySt->repeated & KEY_DPAD_LEFT) && proc->hoverColumn == TRADEMENU_UNIT_RIGHT)
    {
        newSelectedRow = TradeMenu_GetAdjustedRow(proc, TRADEMENU_UNIT_LEFT, proc->hoverRow);

        if (newSelectedRow < 0)
            goto end;

        proc->hoverColumn = TRADEMENU_UNIT_LEFT;
        proc->hoverRow = newSelectedRow;

        changedSelection = TRUE;

        PlaySe(SONG_67);
    }

    if ((gKeySt->repeated & KEY_DPAD_RIGHT) && proc->hoverColumn == TRADEMENU_UNIT_LEFT)
    {
        newSelectedRow = TradeMenu_GetAdjustedRow(proc, TRADEMENU_UNIT_RIGHT, proc->hoverRow);

        if (newSelectedRow < 0)
            goto end;

        proc->hoverColumn = TRADEMENU_UNIT_RIGHT;
        proc->hoverRow = newSelectedRow;

        changedSelection = TRUE;

        PlaySe(SONG_67);
    }

    if ((gKeySt->repeated & KEY_DPAD_UP))
    {
        if (proc->hoverRow == 0)
        {
            if (gKeySt->repeated != gKeySt->pressed)
                goto end;

            proc->hoverRow = TradeMenu_GetAdjustedRow(proc, proc->hoverColumn, ITEMSLOT_INV_COUNT - 1) + 1;
        }

        proc->hoverRow--;

        changedSelection = TRUE;

        PlaySe(SONG_66);
    }

    if ((gKeySt->repeated & KEY_DPAD_DOWN))
    {
        if (!proc->hasItem[proc->hoverColumn][proc->hoverRow + 1])
        {
            if (gKeySt->repeated != gKeySt->pressed)
                goto end;

            proc->hoverRow = -1;
        }

        proc->hoverRow++;

        changedSelection = TRUE;

        PlaySe(SONG_66);
    }

end:
    return changedSelection;
}

static void TradeMenu_ApplyItemSwap(struct TradeMenuProc * proc)
{
    u16 * itemA = &proc->units[proc->hoverColumn]->items[proc->hoverRow];
    u16 * itemB = &proc->units[proc->selectedColumn]->items[proc->selectedRow];

    u16 swp = *itemA;
    *itemA = *itemB;
    *itemB = swp;

    proc->hasTraded = TRUE;

    gAction.id = ACTION_TRADED;

    UnitRemoveInvalidItems(proc->units[0]);
    UnitRemoveInvalidItems(proc->units[1]);

    TradeMenu_RefreshItemText(proc);
}

static void TradeMenu_InitItemDisplay(struct TradeMenuProc * proc)
{
    PutUiWindowFrame(1,  8, 14, 12, UI_WINDOW_REGULAR);
    PutUiWindowFrame(15, 8, 14, 12, UI_WINDOW_REGULAR);

    ResetTextFont();

    ClearIcons();
    ApplyIconPalettes(BGPAL_ICONS);

    TradeMenu_InitItemText(proc);
    TradeMenu_RefreshItemText(proc);

    StartFace(0, GetUnitFid(proc->units[0]), 64,  -4, FACE_DISP_KIND(FACE_96x80_FLIPPED));
    StartFace(1, GetUnitFid(proc->units[1]), 176, -4, FACE_DISP_KIND(FACE_96x80));

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);
}

static void TradeMenu_OnInitUnselected(struct TradeMenuProc * proc)
{
    TradeMenu_RefreshSelectableCells(proc);
    proc->extraCellEnabled = FALSE;
}

static void TradeMenu_OnLoopUnselected(struct TradeMenuProc * proc)
{
    TradeMenu_UpdateSelection(proc);

    PutUiHand(
        8 * sItemDisplayTileLocation[proc->hoverColumn][proc->hoverRow].x,
        8 * sItemDisplayTileLocation[proc->hoverColumn][proc->hoverRow].y);

    if (gKeySt->pressed & KEY_BUTTON_A)
    {
        Proc_Goto(proc, L_TRADEMENU_SELECTED);
        PlaySe(SONG_6A);
    }
    else if (gKeySt->pressed & KEY_BUTTON_B)
    {
        Proc_Goto(proc, L_TRADEMENU_END);
        PlaySe(SONG_6B);
    }
    else if (gKeySt->pressed & KEY_BUTTON_R)
    {
        SpawnProcLocking(ProcScr_TradeMenu_HelpBox, proc);
    }
}

static void TradeMenu_OnInitSelected(struct TradeMenuProc * proc)
{
    int lastRow;

    proc->selectedColumn = proc->hoverColumn;
    proc->selectedRow = proc->hoverRow;

    proc->hoverColumn = proc->hoverColumn ^ 1;

    lastRow = TradeMenu_GetAdjustedRow(proc, proc->hoverColumn, (ITEMSLOT_INV_COUNT - 1));

    if (lastRow != (ITEMSLOT_INV_COUNT - 1))
    {
        proc->hoverRow = lastRow + 1;
        proc->hasItem[proc->hoverColumn][proc->hoverRow] = TRUE;

        proc->extraCellEnabled = TRUE;

        proc->extraColumn = proc->hoverColumn;
        proc->extraRow = proc->hoverRow;
    }
}

static void TradeMenu_OnLoopSelected(struct TradeMenuProc * proc)
{
    TradeMenu_UpdateSelection(proc);

    PutUiHand(
        8 * sItemDisplayTileLocation[proc->hoverColumn][proc->hoverRow].x,
        8 * sItemDisplayTileLocation[proc->hoverColumn][proc->hoverRow].y);

    PutFrozenUiHand(
        8 * sItemDisplayTileLocation[proc->selectedColumn][proc->selectedRow].x,
        8 * sItemDisplayTileLocation[proc->selectedColumn][proc->selectedRow].y);

    if (gKeySt->pressed & KEY_BUTTON_A)
    {
        TradeMenu_ApplyItemSwap(proc);

        PlaySe(SONG_6A);
        Proc_Break(proc);
    }
    else if (gKeySt->pressed & KEY_BUTTON_B)
    {
        PlaySe(SONG_6B);
        Proc_Break(proc);
    }
    else if (gKeySt->pressed & KEY_BUTTON_R)
    {
        SpawnProcLocking(ProcScr_TradeMenu_HelpBox, proc);
    }
}

static void TradeMenu_OnEndSelected(struct TradeMenuProc * proc)
{
    proc->hoverColumn = proc->selectedColumn;
    proc->hoverRow = proc->selectedRow;

    TradeMenu_RefreshSelectableCells(proc);

    if (!proc->hasItem[proc->hoverColumn][0])
        proc->hoverColumn = proc->hoverColumn ^ 1;

    proc->hoverRow = TradeMenu_GetAdjustedRow(proc, proc->hoverColumn, proc->hoverRow);
}

static bool TradeMenu_LoadForcedInitialHover(struct TradeMenuProc * proc)
{
    if (gBmSt.unk_3F < 0)
        return TRUE;

    proc->hoverColumn = gBmSt.unk_3F / ITEMSLOT_INV_COUNT;
    proc->hoverRow = gBmSt.unk_3F % ITEMSLOT_INV_COUNT;

    TradeMenu_RefreshSelectableCells(proc);
    Proc_Goto(proc, L_TRADEMENU_SELECTED);

    return FALSE;
}

static void TradeMenu_ClearDisplay(struct TradeMenuProc * proc)
{
    EndFaceById(0);
    EndFaceById(1);
}

static void TradeMenu_HelpBox_OnInit(struct GenericProc * proc)
{
    struct TradeMenuProc * tradeMenu = proc->proc_parent;

    int item = tradeMenu->units[tradeMenu->hoverColumn]->items[tradeMenu->hoverRow];

    if (!item)
    {
        Proc_End(proc);
        return;
    }

    if (tradeMenu->extraCellEnabled)
        tradeMenu->hasItem[tradeMenu->extraColumn][tradeMenu->extraRow] = FALSE;

    func_fe6_08070E70(NULL, -1);

    StartItemHelpBox(
        8 * sItemDisplayTileLocation[tradeMenu->hoverColumn][tradeMenu->hoverRow].x,
        8 * sItemDisplayTileLocation[tradeMenu->hoverColumn][tradeMenu->hoverRow].y,
        item);

    gKeySt->pressed = gKeySt->pressed &~ (KEY_BUTTON_B | KEY_BUTTON_R);
}

static void TradeMenu_HelpBox_OnLoop(struct GenericProc * proc)
{
    struct TradeMenuProc * tradeMenu = proc->proc_parent;

    bool changedSelection = TradeMenu_UpdateSelection(tradeMenu);
    int item = tradeMenu->units[tradeMenu->hoverColumn]->items[tradeMenu->hoverRow];

    if (changedSelection)
    {
        StartItemHelpBox(
            8 * sItemDisplayTileLocation[tradeMenu->hoverColumn][tradeMenu->hoverRow].x,
            8 * sItemDisplayTileLocation[tradeMenu->hoverColumn][tradeMenu->hoverRow].y,
            item);
    }

    if (gKeySt->pressed & (KEY_BUTTON_B | KEY_BUTTON_R))
        Proc_Break(proc);

    PutUiHand(
        8 * sItemDisplayTileLocation[tradeMenu->hoverColumn][tradeMenu->hoverRow].x,
        8 * sItemDisplayTileLocation[tradeMenu->hoverColumn][tradeMenu->hoverRow].y);

    if (tradeMenu->extraCellEnabled)
    {
        PutFrozenUiHand(
            8 * sItemDisplayTileLocation[tradeMenu->selectedColumn][tradeMenu->selectedRow].x,
            8 * sItemDisplayTileLocation[tradeMenu->selectedColumn][tradeMenu->selectedRow].y);
    }
}

static void TradeMenu_HelpBox_OnEnd(struct GenericProc * proc)
{
    struct TradeMenuProc * tradeMenu = proc->proc_parent;

    if (tradeMenu->extraCellEnabled)
        tradeMenu->hasItem[tradeMenu->extraColumn][tradeMenu->extraRow] = TRUE;

    CloseHelpBox();

    PutUiHand(
        8 * sItemDisplayTileLocation[tradeMenu->hoverColumn][tradeMenu->hoverRow].x,
        8 * sItemDisplayTileLocation[tradeMenu->hoverColumn][tradeMenu->hoverRow].y);

    if (tradeMenu->extraCellEnabled)
    {
        PutFrozenUiHand(
            8 * sItemDisplayTileLocation[tradeMenu->selectedColumn][tradeMenu->selectedRow].x,
            8 * sItemDisplayTileLocation[tradeMenu->selectedColumn][tradeMenu->selectedRow].y);
    }
}

ProcPtr StartTradeMenu(struct Unit * unitA, struct Unit * unitB, int unused)
{
    struct TradeMenuProc * proc = SpawnProc(ProcScr_TradeMenu, PROC_TREE_3);

    proc->units[0] = unitA;
    proc->units[1] = unitB;

    proc->hasTraded = FALSE;

    proc->hoverColumn = TRADEMENU_UNIT_LEFT;
    proc->hoverRow = 0;

    if (GetUnitItemCount(unitA) == 0)
        proc->hoverColumn = TRADEMENU_UNIT_RIGHT;

#if BUGFIX
    return proc;
#endif
}
