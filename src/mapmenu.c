#include "mapmenu.h"

#include "armfunc.h"
#include "hardware.h"
#include "sound.h"
#include "icon.h"
#include "talk.h"
#include "event.h"
#include "msg.h"
#include "bm.h"
#include "item.h"
#include "map.h"
#include "mapwork.h"
#include "playerphase.h"
#include "bmfx.h"
#include "targetlist.h"
#include "itemuse.h"
#include "battle.h"
#include "trademenu.h"
#include "trap.h"
#include "supply.h"
#include "arena.h"
#include "action.h"
#include "unitpanel.h"
#include "subtitlehelp.h"
#include "battlepreview.h"
#include "menuinfo.h"
#include "ui.h"
#include "menu.h"
#include "eventinfo.h"
#include "helpbox.h"

#include "constants/videoalloc_global.h"
#include "constants/terrains.h"
#include "constants/pids.h"
#include "constants/iids.h"
#include "constants/songs.h"
#include "constants/msg.h"

#include "eventscript.h"

static void CheckTutorialInterruptPromptResult(ProcPtr proc);

EventScr CONST_DATA EventScr_TutorialInterruptQuitConfirm[] =
{
    EvtNoSkipNoTextSkip

    EvtTalk(MSG_30A)
    EvtFunc(CheckTutorialInterruptPromptResult)

    EvtTalkMore(MSG_30B)

    EvtNextChapter(0)
    EvtSleep(1)

    EvtKill

EvtLabel(99)
    EvtClearSkip
    EvtEnd
};

static void BackToUnitMenu_CamWatch(ProcPtr proc);
static void BackToUnitMenu_RestartMenu(ProcPtr proc);

struct ProcScr CONST_DATA ProcScr_BackToUnitMenu[] =
{
    PROC_CALL(LockGame),

    PROC_CALL(BackToUnitMenu_CamWatch),
    PROC_WHILE_EXISTS(ProcScr_CamMove),

    PROC_CALL(BackToUnitMenu_RestartMenu),

    PROC_CALL(UnlockGame),

    PROC_END,
};

static void func_fe6_0801F35C(ProcPtr proc);
static void func_fe6_0801F378(ProcPtr proc);

struct ProcScr CONST_DATA ProcScr_Unk_085C5E58[] =
{
    PROC_CALL(LockGame),

    PROC_CALL(func_fe6_0801F35C),

    PROC_WHILE_EXISTS(ProcScr_BattlePreview),
    PROC_WHILE_EXISTS(ProcScr_CamMove),

    PROC_CALL(func_fe6_0801F378),

    PROC_CALL(UnlockGame),

    PROC_END,
};

fu8 func_fe6_0801EA40(struct MenuProc * menu, struct MenuEntProc * ent)
{
    SpawnProc(ProcScr_Unk_0868B010, PROC_TREE_3);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 MapMenu_Suspend_Available(struct MenuEntInfo const * info, int id)
{
    if (gPlaySt.flags & PLAY_FLAG_TUTORIAL)
        return MENU_ENTRY_DISABLED;

    return MENU_ENTRY_ENABLED;
}

fu8 MapMenu_Suspend_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    if (ent->availability == MENU_ENTRY_DISABLED)
    {
        MenuFrozenHelpBox(menu, 0xC46); // TODO: msgids
        return MENU_ACTION_SE_6B;
    }

    func_fe6_0809874C();

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 MapMenu_End_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    Proc_EndEach(ProcScr_PlayerPhase);
    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 MapMenu_Unit_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    Proc_Goto(FindProc(ProcScr_PlayerPhase), L_PLAYERPHASE_10);
    func_fe6_08076238();

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 MapMenu_Options_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    SpawnProc(ProcScr_Unk_0868AE04, PROC_TREE_3);
    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 MapMenu_Status_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    func_fe6_080741C8(NULL);
    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 func_fe6_0801EAE4(struct MenuProc * menu, struct MenuEntProc * ent)
{
    func_fe6_08089234(PROC_TREE_3);
    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

u8 TutorialInterruptMenu_Continue_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

static void CheckTutorialInterruptPromptResult(ProcPtr proc)
{
    if (GetTalkChoiceResult() != 1)
        EventGotoLabel(proc, 99);
}

fu8 TutorialInterruptMenu_Quit_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    StartEvent(EventScr_TutorialInterruptQuitConfirm);
    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 UnitActionMenu_Wait_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    gAction.id = ACTION_WAIT;
    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 MapSelectActionReturnToUnitActionMenuWithCamera(struct MapSelectProc * proc, struct SelectTarget * target)
{
    EndMapSelect(proc);

    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);

    ResetTextFont();

    EndLimitView();

    CameraMoveWatchPosition(
        StartCenteredMenu(&MenuInfo_UnitAction, gBmSt.cursor_sprite_target.x - gBmSt.camera.x, 1, 22),
        gActiveUnit->x, gActiveUnit->y);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_SE_6B | MENU_ACTION_CLEAR;
}

static void BackToUnitMenu_CamWatch(ProcPtr proc)
{
    if (IsCameraNotWatchingPosition(gActiveUnit->x, gActiveUnit->y))
    {
        int y = gActiveUnit->y;

        Proc_EndEach(ProcScr_CamMove);

        if (GetCameraAdjustedY(y<<4) > gBmSt.camera_max.y)
            y = (gBmSt.camera_max.y>>4) + 2;

        CameraMoveWatchPosition(proc, gActiveUnit->x, y);
    }
}

static void BackToUnitMenu_RestartMenu(ProcPtr proc)
{
    StartCenteredMenu(&MenuInfo_UnitAction, gBmSt.cursor_sprite_target.x - gBmSt.camera.x, 1, 22);
}

fu8 MapSelectActionReturnToUnitActionMenu(struct MapSelectProc * proc, struct SelectTarget * target)
{
    EndMapSelect(proc);

    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);

    EndLimitView();

    ResetTextFont();

    SpawnProc(ProcScr_BackToUnitMenu, PROC_TREE_3);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_SE_6B | MENU_ACTION_CLEAR;
}

fu8 MenuActionReturnToUnitActionMenu(struct MenuProc * menu, struct MenuEntProc * ent)
{
    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);

    ResetTextFont();

    StartCenteredMenu(&MenuInfo_UnitAction, gBmSt.cursor_sprite_target.x - gBmSt.camera.x, 1, 22);

    EndLimitView();

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6B | MENU_ACTION_CLEAR | MENU_ACTION_ENDFACE;
}

fu8 RescueMapSelect_Help(struct MapSelectProc * proc, struct SelectTarget * target)
{
    return 0;
}

fu8 UnitActionMenu_Rescue_Available(struct MenuEntInfo const * info, int id)
{
    if (gActiveUnit->flags & UNIT_FLAG_HAD_ACTION)
        return MENU_ENTRY_HIDDEN;

    if (gActiveUnit->flags & UNIT_FLAG_RESCUING)
        return MENU_ENTRY_HIDDEN;

    ListRescueTargets(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_ENTRY_HIDDEN;

    return MENU_ENTRY_ENABLED;
}

fu8 UnitActionMenu_Rescue_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    ListRescueTargets(gActiveUnit);
    StartMapSelect(&MapSelectInfo_Rescue);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A;
}

fu8 RescueMapSelect_Select(struct MapSelectProc * proc, struct SelectTarget * target)
{
    gAction.target = target->uid;
    gAction.id = ACTION_RESCUE;

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 UnitActionMenu_Drop_Available(struct MenuEntInfo const * info, int id)
{
    if (gActiveUnit->flags & UNIT_FLAG_HAD_ACTION)
        return MENU_ENTRY_HIDDEN;

    if (!(gActiveUnit->flags & UNIT_FLAG_RESCUING))
        return MENU_ENTRY_HIDDEN;

    ListRescueDropTargets(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_ENTRY_HIDDEN;

    return MENU_ENTRY_ENABLED;
}

fu8 UnitActionMenu_Drop_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    ListRescueDropTargets(gActiveUnit);
    StartMapSelect(&MapSelectInfo_DropRescue);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 DropRescueMapSelect_Select(struct MapSelectProc * proc, struct SelectTarget * target)
{
    gAction.id = ACTION_DROP;

    gAction.target = gActiveUnit->rescue;
    gAction.x_target = target->x;
    gAction.y_target = target->y;

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 UnitActionMenu_Take_Available(struct MenuEntInfo const * info, int id)
{
    if (gActiveUnit->flags & UNIT_FLAG_HAD_ACTION)
        return MENU_ENTRY_HIDDEN;

    if (gBmSt.partial_actions_taken & PARTIAL_ACTION_RESCUE_TRANSFER)
        return MENU_ENTRY_HIDDEN;

    if (gActiveUnit->flags & UNIT_FLAG_RESCUING)
        return MENU_ENTRY_HIDDEN;

    ListRescueTakeTargets(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_ENTRY_HIDDEN;

    return MENU_ENTRY_ENABLED;
}

fu8 UnitActionMenu_Take_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    ListRescueTakeTargets(gActiveUnit);
    StartMapSelect(&MapSelectInfo_TakeRescue);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A;
}

fu8 UnitActionMenu_Give_Available(struct MenuEntInfo const * info, int id)
{
    if (gActiveUnit->flags & UNIT_FLAG_HAD_ACTION)
        return MENU_ENTRY_HIDDEN;

    if (gBmSt.partial_actions_taken & PARTIAL_ACTION_RESCUE_TRANSFER)
        return MENU_ENTRY_HIDDEN;

    if (!(gActiveUnit->flags & UNIT_FLAG_RESCUING))
        return MENU_ENTRY_HIDDEN;

    ListRescueGiveTargets(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_ENTRY_HIDDEN;

    return MENU_ENTRY_ENABLED;
}

fu8 UnitActionMenu_Give_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    ListRescueGiveTargets(gActiveUnit);
    StartMapSelect(&MapSelectInfo_GiveRescue);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A;
}

void func_fe6_0801EE4C(struct Unit * from, struct Unit * to)
{
    struct Unit * rescue = GetUnit(from->rescue);

    EndSubtitleHelp();
    StartRescueTransferAnimParentless(rescue, func_fe6_0801C160(to->x, to->y, from->x, from->y));
}

fu8 TakeRescueMapSelect_Select(struct MapSelectProc * proc, struct SelectTarget * target)
{
    gAction.id = ACTION_TAKE;
    gAction.target = target->uid;

    UnitSyncMovement(GetUnit(gAction.target));

    func_fe6_0801EE4C(GetUnit(gAction.target), GetUnit(gAction.instigator));
    UnitGiveRescue(GetUnit(gAction.target), GetUnit(gAction.instigator));

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 GiveRescueMapSelect_Select(struct MapSelectProc * proc, struct SelectTarget * target)
{
    gAction.id = ACTION_GIVE;
    gAction.target = target->uid;

    UnitSyncMovement(GetUnit(gAction.instigator));

    func_fe6_0801EE4C(GetUnit(gAction.instigator), GetUnit(gAction.target));
    UnitGiveRescue(GetUnit(gAction.instigator), GetUnit(gAction.target));

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 UnitActionMenu_Attack_Available(struct MenuEntInfo const * info, int id)
{
    int i, item;

    if (gActiveUnit->flags & UNIT_FLAG_HAD_ACTION)
        return MENU_ENTRY_HIDDEN;

    gBmSt.unk_30 = FALSE;
    gBmSt.unk_31 = FALSE;

    for (i = 0; i < ITEMSLOT_INV_COUNT && (item = gActiveUnit->items[i]) != 0; ++i)
    {
        if (!(GetItemAttributes(item) & ITEM_ATTR_WEAPON))
            continue;

        if (!CanUnitUseWeapon(gActiveUnit, item))
            continue;

        ListAttackTargetsForWeapon(gActiveUnit, item);

        if (CountTargets() != 0)
        {
            gBmSt.unk_30 = TRUE;
            break;
        }
    }

    if (UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_BALLISTA)
    {
        func_fe6_08021278(gActiveUnit);

        if (CountTargets() != 0)
        {
            gBmSt.unk_31 = TRUE;

            if (GetObstacleHpAt(gActiveUnit->x, gActiveUnit->y) == 0)
                return MENU_ENTRY_DISABLED;
        }
    }

    if (gBmSt.unk_30 || gBmSt.unk_31)
        return MENU_ENTRY_ENABLED;

    return MENU_ENTRY_HIDDEN;
}

fu8 UnitActionMenu_Attack_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    if (ent->availability == MENU_ENTRY_DISABLED)
    {
        MenuFrozenHelpBox(menu, MSG_C3B);
        return MENU_ACTION_SE_6B;
    }

    ClearIcons();
    ApplyIconPalettes(BGPAL_ICONS);

    if (gBmSt.unk_30 == TRUE && gBmSt.unk_31 == TRUE)
    {
        StartSubtitleHelp(
            StartAdjustedMenu(&MenuInfo_UnitAttackMethodPrompt, gBmSt.cursor_sprite_target.x - gBmSt.camera.x, 1, 20),
            DecodeMsg(MSG_C27));

        return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
    }

    if (gBmSt.unk_30)
        return UnitActionMenu_AttackRegular_Select(menu, ent);

    if (gBmSt.unk_31)
        return UnitActionMenu_AttackBallista_Select(menu, ent);

    return 0;
}

fu8 UnitActionMenu_AttackBallista_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    ProcPtr proc = StartMenu(&MenuInfo_UnitAttackBallista);

    StartFace(0, GetUnitFid(gActiveUnit), 176, 12, FACE_DISP_KIND(FACE_96x80));
    StartEquipInfoWindow(proc, gActiveUnit, 15, 11);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 UnitActionMenu_AttackRegular_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    ProcPtr proc = StartMenu(&MenuInfo_UnitAttackItem);

    StartFace(0, GetUnitFid(gActiveUnit), 176, 12, FACE_DISP_KIND(FACE_96x80));
    StartEquipInfoWindow(proc, gActiveUnit, 15, 11);

    StartAvailableAttackMenuEvent();

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 UnitActionMenu_Attack_SwitchIn(struct MenuProc * menu, struct MenuEntProc * ent)
{
    int reach;

    MapFill(gMapMovement, -1);
    MapFill(gMapRange, 0);

    reach = GetUnitWeaponReach(gActiveUnit, -1);
    BuildUnitStandingRangeForReach(gActiveUnit, reach);

    if (UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_BALLISTA)
    {
        int item = GetBallistaItemAt(gActiveUnit->x, gActiveUnit->y);

        if (item != 0)
            MapIncInBoundedRange(gActiveUnit->x, gActiveUnit->y, GetItemMinRange(item), GetItemMaxRange(item));
    }

    StartLimitView(LIMITVIEW_BLUE | LIMITVIEW_RED);

    return 0;
}

fu8 UnitActionMenu_Attack_SwitchOut(struct MenuProc * menu, struct MenuEntProc * ent)
{
    EndLimitView();
    return 0;
}

fu8 UnitAttackItemMenu_Entry_Available(struct MenuEntInfo const * info, int id)
{
    int item = gActiveUnit->items[id];

    if (!(GetItemAttributes(item) & ITEM_ATTR_WEAPON))
        return MENU_ENTRY_HIDDEN;

    if (!CanUnitUseWeapon(gActiveUnit, item))
        return MENU_ENTRY_HIDDEN;

    ListAttackTargetsForWeapon(gActiveUnit, item);

    if (CountTargets() == 0)
        return MENU_ENTRY_HIDDEN;

    return MENU_ENTRY_ENABLED;
}

fu8 UnitAttackItemMenu_Entry_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    UnitEquipItemSlot(gActiveUnit, ent->id);
    gAction.item_slot = ITEMSLOT_INV0;

    ClearUi();

    ListAttackTargetsForWeapon(gActiveUnit, gActiveUnit->items[0]);
    StartMapSelect(&MapSelectInfo_Attack);

    StartAvailableAttackMenuItemEvent();

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_ENDFACE;
}

u32 UnitAttackItemMenu_Entry_Display(struct MenuProc * menu, struct MenuEntProc * ent)
{
    int item = gActiveUnit->items[ent->id];
    bool is_usable = CanUnitUseWeapon(gActiveUnit, item);

    func_fe6_08016694(&ent->text, item, is_usable, gBg0Tm + TM_OFFSET(ent->x, ent->y));

    return 0;
}

fu8 UnitAttackItemMenu_Entry_SwitchIn(struct MenuProc * menu, struct MenuEntProc * ent)
{
    int reach;

    UpdateEquipInfoWindow(ent->id);

    MapFill(gMapMovement, -1);
    MapFill(gMapRange, 0);

    reach = GetUnitWeaponReach(gActiveUnit, ent->id);
    BuildUnitStandingRangeForReach(gActiveUnit, reach);

    StartLimitView(LIMITVIEW_RED);

    return 0;
}

fu8 UnitAttackItemMenu_Entry_SwitchOut(struct MenuProc * menu, struct MenuEntProc * ent)
{
    if (!(menu->flags & MENU_FLAG_ENDING))
        EndLimitView();

    return 0;
}

fu8 AttackMapSelect_Select(struct MapSelectProc * proc, struct SelectTarget * target)
{
    gAction.id = ACTION_COMBAT;
    gAction.target = target->uid;

    if (target->uid == 0)
    {
        gAction.x_target = target->x;
        gAction.y_target = target->y;
        gAction.extra = target->extra;
    }

    Proc_EndEach(ProcScr_BattlePreview);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

static void func_fe6_0801F35C(ProcPtr proc)
{
    CameraMoveWatchPosition(NULL, gActiveUnit->x, gActiveUnit->y);
}

static void func_fe6_0801F378(ProcPtr proc)
{
    UnitActionMenu_Attack_Select(NULL, NULL);
}

fu8 AttackMapSelect_Cancel(struct MapSelectProc * proc, struct SelectTarget * target)
{
    SpawnProc(ProcScr_Unk_085C5E58, PROC_TREE_3);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6B;
}

fu8 AttackMapSelect_SwitchIn(struct MapSelectProc * proc, struct SelectTarget * target)
{
    struct Unit * unit = GetUnit(target->uid);

    MakeActiveMuWatchPosition(target->x, target->y);

    if (target->uid == 0)
    {
        gAction.x_target = target->x;
        gAction.y_target = target->y;
        gAction.extra = target->extra;

        InitObstacleBattleUnit();
    }

    if (gAction.item_slot == ITEMSLOT_BALLISTA)
        BattleGenerateBallistaSimulation(gActiveUnit, unit, gActiveUnit->x, gActiveUnit->y);
    else
        BattleGenerateSimulation(gActiveUnit, unit, -1, -1, gAction.item_slot);

    UpdateBattlePreviewContents();

    return 0;
}

u32 AttackMapSelect_End(struct MapSelectProc * proc)
{
    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);

    EndLimitView();
    CloseBattlePreview();

    return 0;
}

fu8 AnyMenu_Trade_Available(struct MenuEntInfo const * info, int id)
{
    if (gActiveUnit->flags & UNIT_FLAG_HAD_ACTION)
        return MENU_ENTRY_HIDDEN;

    if (gBmSt.partial_actions_taken & PARTIAL_ACTION_TRADED)
        return MENU_ENTRY_HIDDEN;

    ListTradeTargets(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_ENTRY_HIDDEN;

    return MENU_ENTRY_ENABLED;
}

fu8 UnitActionMenu_Trade_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    ClearUi();

    ListTradeTargets(gActiveUnit);
    StartMapSelect(&MapSelectInfo_Trade);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A;
}

fu8 TradeMapSelect_Select(struct MapSelectProc * proc, struct SelectTarget * target)
{
    gAction.id = ACTION_TRADED_NOCHANGES;
    StartTradeMenu(gActiveUnit, GetUnit(target->uid), 0);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 UnitActionMenu_Seize_Available(struct MenuEntInfo const * info, int id)
{
    if (gActiveUnit->flags & UNIT_FLAG_HAD_ACTION)
        return MENU_ENTRY_HIDDEN;

    if (!(UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_LORD))
        return MENU_ENTRY_HIDDEN;

    return GetAvailableTileEventCommand(gActiveUnit->x, gActiveUnit->y) == TILE_COMMAND_SEIZE
        ? MENU_ENTRY_ENABLED : MENU_ENTRY_HIDDEN;
}

fu8 UnitActionMenu_Seize_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    gAction.id = ACTION_SEIZE;
    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 UnitActionMenu_Visit_Available(struct MenuEntInfo const * info, int id)
{
    if (gActiveUnit->flags & UNIT_FLAG_HAD_ACTION)
        return MENU_ENTRY_HIDDEN;

    if (gMapTerrain[gActiveUnit->y][gActiveUnit->x] != TERRAIN_VILLAGE && gMapTerrain[gActiveUnit->y][gActiveUnit->x] != TERRAIN_HOUSE)
        return MENU_ENTRY_HIDDEN;

    if (GetAvailableTileEventCommand(gActiveUnit->x, gActiveUnit->y) != TILE_COMMAND_VISIT)
        return MENU_ENTRY_HIDDEN;

    if (gActiveUnit->status == UNIT_STATUS_SILENCED)
        return MENU_ENTRY_DISABLED;

    return MENU_ENTRY_ENABLED;
}

fu8 UnitActionMenu_Visit_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    if (ent->availability == MENU_ENTRY_DISABLED)
    {
        MenuFrozenHelpBox(menu, MSG_C30);
        return MENU_ACTION_SE_6B;
    }

    gAction.id = ACTION_VISIT;
    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 UnitActionMenu_Play_Available(struct MenuEntInfo const * info, int id)
{
    if (gActiveUnit->flags & UNIT_FLAG_HAD_ACTION)
        return MENU_ENTRY_HIDDEN;

    if (!(UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_PLAY))
        return MENU_ENTRY_HIDDEN;

    ListRefreshTargets(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_ENTRY_HIDDEN;

    return MENU_ENTRY_ENABLED;
}

fu8 UnitActionMenu_Dance_Available(struct MenuEntInfo const * info, int id)
{
    if (gActiveUnit->flags & UNIT_FLAG_HAD_ACTION)
        return MENU_ENTRY_HIDDEN;

    if (!(UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_DANCE))
        return MENU_ENTRY_HIDDEN;

    ListRefreshTargets(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_ENTRY_HIDDEN;

    return MENU_ENTRY_ENABLED;
}

fu8 UnitActionMenu_Refresh_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    if (ent->availability == MENU_ENTRY_DISABLED)
        return MENU_ACTION_SE_6B;

    ListRefreshTargets(gActiveUnit);
    StartMapSelect(&MapSelectInfo_Refresh);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A;
}

fu8 RefreshMapSelect_Select(struct MapSelectProc * proc, struct SelectTarget * target)
{
    gAction.id = ACTION_REFRESH;
    gAction.target = target->uid;

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 UnitActionMenu_Item_Available(struct MenuEntInfo const * info, int id)
{
    if (gActiveUnit->flags & UNIT_FLAG_HAD_ACTION)
        return MENU_ENTRY_HIDDEN;

    if (gActiveUnit->items[0] == 0)
        return MENU_ENTRY_HIDDEN;

    return MENU_ENTRY_ENABLED;
}

fu8 UnitActionMenu_Item_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    ProcPtr proc;

    if (ent->availability != MENU_ENTRY_ENABLED)
        return 0;

    ClearIcons();
    ApplyIconPalettes(BGPAL_ICONS);

    ResetTextFont();

    proc = StartMenu(&MenuInfo_UnitItem);

    StartFace(0, GetUnitFid(gActiveUnit), 176, 12, FACE_DISP_KIND(FACE_96x80));
    StartEquipInfoWindow(proc, gActiveUnit, 15, 11);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

u32 UnitItemMenu_Entry_Display(struct MenuProc * menu, struct MenuEntProc * ent)
{
    int item = gActiveUnit->items[ent->id];
    bool is_usable;

    if (GetItemAttributes(item) & ITEM_ATTR_WEAPON)
    {
        UnitAttackItemMenu_Entry_Display(menu, ent);
        return 0;
    }

    is_usable = CanUnitUseItem(gActiveUnit, item);

    func_fe6_08016694(&ent->text, item, is_usable, gBg0Tm + TM_OFFSET(ent->x, ent->y));
    EnableBgSync(BG0_SYNC_BIT);
}

fu8 UnitItemMenu_Entry_Available(struct MenuEntInfo const * info, int id)
{
    int item = gActiveUnit->items[id];

    if (item == 0)
        return MENU_ENTRY_HIDDEN;

    if (GetItemAttributes(item) & ITEM_ATTR_WEAPON)
        UnitAttackItemMenu_Entry_Available(info, id); // BUG?

    return CanUnitUseItem(gActiveUnit, item)
        ? MENU_ENTRY_ENABLED : MENU_ENTRY_DISABLED;
}

fu8 UnitItemMenu_Entry_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    struct MenuRect rect;

    gAction.item_slot = ent->id;

    rect.x = ent->x + 9;
    rect.y = ent->y - 1;
    rect.w = 5;
    rect.h = 0;

    func_fe6_0801F854(rect.x, rect.y);
    StartLockingMenuExt(&MenuInfo_UnitItemAction, rect, menu);

    return MENU_ACTION_SE_6A;
}

fu8 SingleItemMenu_Entry_SwitchIn(struct MenuProc * menu, struct MenuEntProc * ent)
{
    UpdateEquipInfoWindow(ent->id);
}

fu8 SingleItemMenu_Entry_SwitchOut(struct MenuProc * menu, struct MenuEntProc * ent)
{
}

void func_fe6_0801F854(int x, int y)
{
    InitTextFont(&gFont_Unk_02002770, (u8 *) VRAM + CHR_SIZE*0x200, 0x200, 0);

    TmCopyRect_t(gBg0Tm + TM_OFFSET(11, 1), gUnk_Tm_02003238, 9, 19);
    TmCopyRect_t(gBg1Tm + TM_OFFSET(11, 1), gUnk_Tm_02003738, 9, 19);
}

void UnitItemActionMenu_End(struct MenuProc * menu)
{
    SetTextFont(NULL);
}

fu8 MenuActionReturnToUnitItemMenu(struct MenuProc * menu)
{
    SetTextFont(NULL);

    TmCopyRect_t(gUnk_Tm_02003238, gBg0Tm + TM_OFFSET(11, 1), 9, 19);
    TmCopyRect_t(gUnk_Tm_02003738, gBg1Tm + TM_OFFSET(11, 1), 9, 19);

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6B;
}

fu8 func_fe6_0801F8E0(struct MenuProc * menu)
{
    SetTextFont(NULL);
    ResetTextFont();

    EndMenus();

    return MENU_ACTION_NOCURSOR | MENU_ACTION_CLEAR | MENU_ACTION_ENDFACE;
}

fu8 func_fe6_0801F8F8(struct MenuProc * menu)
{
    ProcPtr proc;

    func_fe6_0801F8E0(menu);
    MenuActionReturnToUnitItemMenu(menu);

    proc = StartMenu(&MenuInfo_UnitItem);

    StartFace(0, GetUnitFid(gActiveUnit), 176, 12, FACE_DISP_KIND(FACE_96x80));
    StartEquipInfoWindow(proc, gActiveUnit, 15, 11);

    return MENU_ACTION_NOCURSOR;
}

fu8 func_fe6_0801F948(struct MenuProc * menu)
{
    ProcPtr proc;

    func_fe6_0801F8E0(menu);

    if (GetUnitItemCount(gActiveUnit) == 0)
    {
        ClearUi();
        EndFaceById(0);

        StartCenteredMenu(&MenuInfo_UnitAction, gBmSt.cursor_sprite_target.x - gBmSt.camera.x, 1, 22);

        return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6B | MENU_ACTION_CLEAR;
    }

    TmCopyRect_t(gUnk_Tm_02003238, gBg0Tm + TM_OFFSET(11, 1), 9, 19);
    TmCopyRect_t(gUnk_Tm_02003738, gBg1Tm + TM_OFFSET(11, 1), 9, 19);

    TmFillRect_t(gBg0Tm + TM_OFFSET(1, 1), 13, 12, 0);
    TmFillRect_t(gBg1Tm + TM_OFFSET(1, 1), 13, 12, 0);

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);

    proc = StartMenu(&MenuInfo_UnitItem);

    StartFace(0, GetUnitFid(gActiveUnit), 176, 12, FACE_DISP_KIND(FACE_96x80));
    StartEquipInfoWindow(proc, gActiveUnit, 15, 11);

    return MENU_ACTION_NOCURSOR;
}

fu8 UnitItemActionMenu_Use_Available(struct MenuEntInfo const * info, int id)
{
    int item = gActiveUnit->items[gAction.item_slot];

    if (GetItemEffect(item) == 0)
        return MENU_ENTRY_HIDDEN;

    if (GetItemKind(item) == ITEM_KIND_STAFF)
        return MENU_ENTRY_HIDDEN;

    if ((GetItemAttributes(item) & ITEM_ATTR_WEAPON) && !CanUnitUseWeapon(gActiveUnit, item))
        return MENU_ENTRY_HIDDEN;

    return CanUnitUseItem(gActiveUnit, item)
        ? MENU_ENTRY_ENABLED : MENU_ENTRY_DISABLED;
}

fu8 UnitItemActionMenu_Equip_Available(struct MenuEntInfo const * info, int id)
{
    int item = gActiveUnit->items[gAction.item_slot];

    if (!(GetItemAttributes(item) & ITEM_ATTR_WEAPON))
        return MENU_ENTRY_HIDDEN;

    return CanUnitUseWeapon(gActiveUnit, item)
        ? MENU_ENTRY_ENABLED : MENU_ENTRY_DISABLED;
}

fu8 UnitItemActionMenu_Discard_Available(struct MenuEntInfo const * info, int id)
{
    int item = gActiveUnit->items[gAction.item_slot];

    if (GetItemAttributes(item) & ITEM_ATTR_IMPORTANT)
        return MENU_ENTRY_DISABLED;

    return MENU_ENTRY_ENABLED;
}

fu8 UnitItemActionMenu_Use_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    if (ent->availability == MENU_ENTRY_DISABLED)
    {
        MenuFrozenHelpBox(menu, GetUnitItemCantUseMsg(gActiveUnit, gActiveUnit->items[gAction.item_slot]));
        return MENU_ACTION_SE_6B;
    }

    gAction.id = ACTION_USEITEM;

    PlaySe(SONG_6A);
    return func_fe6_0801F8E0(menu);
}

fu8 UnitItemActionMenu_Equip_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    if (ent->availability == MENU_ENTRY_DISABLED)
    {
        MenuFrozenHelpBox(menu, MSG_C31);
        return MENU_ACTION_SE_6B;
    }

    UnitEquipItemSlot(gActiveUnit, gAction.item_slot);

    return func_fe6_0801F8F8(menu);
}

fu8 UnitItemActionMenu_Trade_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    gBmSt.unk_3F = gAction.item_slot;

    func_fe6_0801F8E0(menu);
    EndFaceById(0);

    UnitActionMenu_Trade_Select(menu, ent);

    return MENU_ACTION_NOCURSOR;
}

fu8 UnitItemActionMenu_Discard_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    struct MenuRect rect;

    if (ent->availability == MENU_ENTRY_DISABLED)
    {
        MenuFrozenHelpBox(menu, MSG_C33);
        return MENU_ACTION_SE_6B;
    }

    rect.x = ent->x + 3;
    rect.y = ent->y;
    rect.w = 5;
    rect.h = 0;

    StartLockingMenuExt(&MenuInfo_UnitItemDiscardPrompt, rect, menu)->active_entry = 1;

    return MENU_ACTION_SE_6A | MENU_ACTION_DOOM;
}

fu8 UnitItemDiscardPromptMenu_Yes_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    UnitRemoveItem(gActiveUnit, gAction.item_slot);

    func_fe6_0801F948(menu);
    return MENU_ACTION_NOCURSOR;
}

fu8 UnitAttackBallista_Entry_Available(struct MenuEntInfo const * info, int id)
{
    if (gActiveUnit->flags & UNIT_FLAG_HAD_ACTION)
        return MENU_ENTRY_HIDDEN;

    if ((GetBallistaItemAt(gActiveUnit->x, gActiveUnit->y) & 0xFF00) != 0)
        return MENU_ENTRY_ENABLED;

    return MENU_ENTRY_DISABLED;
}

u32 UnitAttackBallista_Entry_Display(struct MenuProc * menu, struct MenuEntProc * ent)
{
    bool is_usable = (ent->availability == MENU_ENTRY_ENABLED) ? TRUE : FALSE;
    int item = GetBallistaItemAt(gActiveUnit->x, gActiveUnit->y);

    func_fe6_08016694(&ent->text, item, is_usable, gBg0Tm + TM_OFFSET(ent->x, ent->y));
}

fu8 UnitAttackBallista_Entry_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    ClearUi();

    gAction.item_slot = ITEMSLOT_BALLISTA;

    func_fe6_08021278(gActiveUnit);
    StartMapSelect(&MapSelectInfo_Attack);

    return MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_ENDFACE;
}

fu8 UnitAttackBallista_Entry_SwitchIn(struct MenuProc * menu, struct MenuEntProc * ent)
{
    int item;

    MapFill(gMapMovement, -1);
    MapFill(gMapRange, 0);

    SetWorkingMap(gMapRange);

    item = GetBallistaItemAt(gActiveUnit->x, gActiveUnit->y);
    UpdateEquipInfoWindow(item);

    MapIncInBoundedRange(gActiveUnit->x, gActiveUnit->y, GetItemMinRange(item), GetItemMaxRange(item));
    StartLimitView(LIMITVIEW_RED);

    return 0;
}

fu8 UnitActionMenu_Staff_Available(struct MenuEntInfo const * info, int id)
{
    int i, item;

    if (gActiveUnit->flags & UNIT_FLAG_HAD_ACTION)
        return MENU_ENTRY_HIDDEN;

    for (i = 0; i < ITEMSLOT_INV_COUNT && (item = gActiveUnit->items[i]) != 0; ++i)
    {
        if (GetItemKind(item) == ITEM_KIND_STAFF && CanUnitUseItem(gActiveUnit, item))
        {
            if (gActiveUnit->status == UNIT_STATUS_SILENCED)
                return MENU_ENTRY_DISABLED;

            return MENU_ENTRY_ENABLED;
        }
    }

    return MENU_ENTRY_HIDDEN;
}

fu8 UnitActionMenu_Staff_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    ProcPtr proc;

    if (ent->availability == MENU_ENTRY_DISABLED)
    {
        MenuFrozenHelpBox(menu, MSG_C34);
        return MENU_ACTION_SE_6B;
    }

    ClearIcons();
    ApplyIconPalettes(BGPAL_ICONS);

    proc = StartMenu(&MenuInfo_UnitStaffItem);

    StartFace(0, GetUnitFid(gActiveUnit), 176, 12, FACE_DISP_KIND(FACE_96x80));
    StartEquipInfoWindow(proc, gActiveUnit, 15, 11);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 UnitActionMenu_Staff_SwitchIn(struct MenuProc * menu, struct MenuEntProc * ent)
{
    int reach = GetUnitItemUseReach(gActiveUnit, -1);

    MapFill(gMapMovement, -1);
    MapFill(gMapRange, 0);

    BuildUnitStandingRangeForReach(gActiveUnit, reach);
    StartLimitView(LIMITVIEW_BLUE | LIMITVIEW_GREEN);

    return 0;
}

fu8 UnitActionMenu_Staff_SwitchOut(struct MenuProc * menu, struct MenuEntProc * ent)
{
    EndLimitView();
    return 0;
}

fu8 UnitStaffItemMenu_Entry_Available(struct MenuEntInfo const * info, int id)
{
    int item = gActiveUnit->items[id];

    if (GetItemKind(item) != ITEM_KIND_STAFF)
        return MENU_ENTRY_HIDDEN;

    if (!CanUnitUseItem(gActiveUnit, item))
        return MENU_ENTRY_HIDDEN;

    return MENU_ENTRY_ENABLED;
}

fu8 UnitStaffItemMenu_Entry_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    UnitEquipItemSlot(gActiveUnit, ent->id);
    gAction.item_slot = ITEMSLOT_INV0;

    ClearUi();

    DoUseUnitItem(gActiveUnit, gActiveUnit->items[gAction.item_slot]);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A;
}

u32 UnitStaffItemMenu_Entry_Display(struct MenuProc * menu, struct MenuEntProc * ent)
{
    return UnitItemMenu_Entry_Display(menu, ent);
}

fu8 UnitStaffItemMenu_Entry_SwitchIn(struct MenuProc * menu, struct MenuEntProc * ent)
{
    int reach = GetUnitItemUseReach(gActiveUnit, ent->id);

    UpdateEquipInfoWindow(ent->id);

    MapFill(gMapMovement, -1);
    MapFill(gMapRange, 0);

    BuildUnitStandingRangeForReach(gActiveUnit, reach);
    StartLimitView(LIMITVIEW_GREEN);

    return 0;
}

fu8 UnitStaffItemMenu_Entry_SwitchOut(struct MenuProc * menu, struct MenuEntProc * ent)
{
    if (!(menu->flags & MENU_FLAG_ENDING))
        EndLimitView();

    return 0;
}

fu8 UnitActionMenu_Talk_Available(struct MenuEntInfo const * info, int id)
{
    if (gActiveUnit->flags & UNIT_FLAG_HAD_ACTION)
        return MENU_ENTRY_HIDDEN;

    ListTalkTargets(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_ENTRY_HIDDEN;

    if (gActiveUnit->status == UNIT_STATUS_SILENCED)
        return MENU_ENTRY_DISABLED;

    return MENU_ENTRY_ENABLED;
}

fu8 UnitActionMenu_Talk_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    if (ent->availability == MENU_ENTRY_DISABLED)
    {
        MenuFrozenHelpBox(menu, MSG_C35);
        return MENU_ACTION_SE_6B;
    }

    ListTalkTargets(gActiveUnit);
    StartMapSelect(&MapSelectInfo_Talk);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A;
}

fu8 TalkMapSelect_Select(struct MapSelectProc * proc, struct SelectTarget * target)
{
    gAction.id = ACTION_TALK;
    gAction.target = target->uid;

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 UnitActionMenu_Support_Available(struct MenuEntInfo const * info, int id)
{
    if (gActiveUnit->flags & UNIT_FLAG_HAD_ACTION)
        return MENU_ENTRY_HIDDEN;

    ListSupportTargets(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_ENTRY_HIDDEN;

    ListTalkTargets(gActiveUnit);

    if (CountTargets() != 0)
        return MENU_ENTRY_HIDDEN;

    if (gActiveUnit->status == UNIT_STATUS_SILENCED)
        return MENU_ENTRY_DISABLED;

    return MENU_ENTRY_ENABLED;
}

fu8 UnitActionMenu_Support_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    if (ent->availability == MENU_ENTRY_DISABLED)
    {
        MenuFrozenHelpBox(menu, MSG_C35);
        return MENU_ACTION_SE_6B;
    }

    ListSupportTargets(gActiveUnit);
    StartMapSelect(&MapSelectInfo_Support);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A;
}

fu8 SupportMapSelect_Select(struct MapSelectProc * proc, struct SelectTarget * target)
{
    gAction.id = ACTION_SUPPORT;
    gAction.target = target->uid;

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 UnitActionMenu_Door_Available(struct MenuEntInfo const * info, int id)
{
    if (gActiveUnit->flags & UNIT_FLAG_HAD_ACTION)
        return MENU_ENTRY_HIDDEN;

    if (GetUnitKeyItemSlotForTerrain(gActiveUnit, TERRAIN_DOOR) < 0)
        return MENU_ENTRY_HIDDEN;

    ListOpenTerrainTargets(gActiveUnit, TERRAIN_DOOR);

    return (CountTargets() == 0)
        ? MENU_ENTRY_HIDDEN : MENU_ENTRY_ENABLED;
}

fu8 UnitActionMenu_Door_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    gAction.id = ACTION_DOOR;
    gAction.instigator = gActiveUnit->id;
    gAction.item_slot = GetUnitKeyItemSlotForTerrain(gActiveUnit, TERRAIN_DOOR);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 UnitActionMenu_Chest_Available(struct MenuEntInfo const * info, int id)
{
    if (gActiveUnit->flags & UNIT_FLAG_HAD_ACTION)
        return MENU_ENTRY_HIDDEN;

    if (GetUnitKeyItemSlotForTerrain(gActiveUnit, TERRAIN_CHEST) < 0)
        return MENU_ENTRY_HIDDEN;

    return CanUnitUseChestKeyItem(gActiveUnit)
        ? MENU_ENTRY_ENABLED : MENU_ENTRY_HIDDEN;
}

fu8 UnitActionMenu_Chest_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    gAction.id = ACTION_CHEST;
    gAction.item_slot = GetUnitKeyItemSlotForTerrain(gActiveUnit, TERRAIN_CHEST);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 UnitActionMenu_Supply_Available(struct MenuEntInfo const * info, int id)
{
    struct Unit * merlinus;

    if (gActiveUnit->flags & UNIT_FLAG_HAD_ACTION)
        return MENU_ENTRY_HIDDEN;

    if (gBmSt.partial_actions_taken & PARTIAL_ACTION_SUPPLY)
        return MENU_ENTRY_HIDDEN;

    if (GetUnitItemCount(gActiveUnit) == 0 && CountSupplyItems() == 0)
        return MENU_ENTRY_HIDDEN;

    if (UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_SUPPLY)
        return MENU_ENTRY_ENABLED;

    merlinus = GetUnitByPid(PID_MERLINUS);

    if (merlinus == NULL)
        return MENU_ENTRY_HIDDEN;

    if (merlinus->flags & UNIT_FLAG_HIDDEN)
        return MENU_ENTRY_HIDDEN;

    if (RECT_DISTANCE(gActiveUnit->x, gActiveUnit->y, merlinus->x, merlinus->y) == 1)
        return MENU_ENTRY_ENABLED;

    return MENU_ENTRY_HIDDEN;
}

fu8 UnitActionMenu_Supply_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    gAction.id = ACTION_TRADED_NOCHANGES;

    func_fe6_080815E4(gActiveUnit, NULL);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 UnitActionMenu_Armory_Available(struct MenuEntInfo const * info, int id)
{
    if (gActiveUnit->flags & UNIT_FLAG_HAD_ACTION)
        return MENU_ENTRY_HIDDEN;

    return GetAvailableTileEventCommand(gActiveUnit->x, gActiveUnit->y) == TILE_COMMAND_ARMORY
        ? MENU_ENTRY_ENABLED : MENU_ENTRY_HIDDEN;
}

fu8 UnitActionMenu_Armory_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    StartAvailableTileEvent(gActiveUnit->x, gActiveUnit->y);
    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 UnitActionMenu_Vendor_Available(struct MenuEntInfo const * info, int id)
{
    if (gActiveUnit->flags & UNIT_FLAG_HAD_ACTION)
        return MENU_ENTRY_HIDDEN;

    return GetAvailableTileEventCommand(gActiveUnit->x, gActiveUnit->y) == TILE_COMMAND_VENDOR
        ? MENU_ENTRY_ENABLED : MENU_ENTRY_HIDDEN;
}

fu8 UnitActionMenu_Vendor_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    StartAvailableTileEvent(gActiveUnit->x, gActiveUnit->y);
    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 UnitActionMenu_Secret_Available(struct MenuEntInfo const * info, int id)
{
    if (gActiveUnit->flags & UNIT_FLAG_HAD_ACTION)
        return MENU_ENTRY_HIDDEN;

    return GetAvailableTileEventCommand(gActiveUnit->x, gActiveUnit->y) == TILE_COMMAND_SECRET
        ? MENU_ENTRY_ENABLED : MENU_ENTRY_HIDDEN;
}

fu8 UnitActionMenu_Secret_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    StartAvailableTileEvent(gActiveUnit->x, gActiveUnit->y);
    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 UnitActionMenu_Arena_Available(struct MenuEntInfo const * info, int id)
{
    if (gActiveUnit->flags & UNIT_FLAG_HAD_ACTION)
        return MENU_ENTRY_HIDDEN;

    if (gMapTerrain[gActiveUnit->y][gActiveUnit->x] != TERRAIN_ARENA_08)
        return MENU_ENTRY_HIDDEN;

    return ArenaIsUnitAllowed(gActiveUnit)
        ? MENU_ENTRY_ENABLED : MENU_ENTRY_DISABLED;
}

fu8 UnitActionMenu_Arena_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    if (ent->availability == MENU_ENTRY_DISABLED)
    {
        if (gActiveUnit->status == UNIT_STATUS_SILENCED)
            MenuFrozenHelpBox(menu, MSG_C36);
        else
            MenuFrozenHelpBox(menu, MSG_C37);

        return MENU_ACTION_SE_6B;
    }

    func_fe6_08097E84();
    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 UnitActionMenu_Steal_Available(struct MenuEntInfo const * info, int id)
{
    if (!(UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_STEAL))
        return MENU_ENTRY_HIDDEN;

    if (gActiveUnit->flags & UNIT_FLAG_HAD_ACTION)
        return MENU_ENTRY_HIDDEN;

    ListStealTargets(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_ENTRY_HIDDEN;

    if (GetUnitItemCount(gActiveUnit) == ITEMSLOT_INV_COUNT)
        return MENU_ENTRY_DISABLED;

    return MENU_ENTRY_ENABLED;
}

fu8 UnitActionMenu_Steal_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    if (ent->availability == MENU_ENTRY_DISABLED)
    {
        MenuFrozenHelpBox(menu, MSG_C44);
        return MENU_ACTION_SE_6B;
    }

    ClearUi();

    ListStealTargets(gActiveUnit);
    StartMapSelect(&MapSelectInfo_Steal);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A;
}

void StealMapSelect_Init(struct MapSelectProc * proc)
{
    StartUnitInventoryPanel(proc);
    StartSubtitleHelp(proc, DecodeMsg(MSG_C20));
}

fu8 StealMapSelect_SwitchIn(struct MapSelectProc * proc, struct SelectTarget * target)
{
    MakeActiveMuWatchPosition(target->x, target->y);
    RefreshUnitStealInventoryPanel(GetUnit(target->uid));
}

fu8 StealMapSelect_Select(struct MapSelectProc * proc, struct SelectTarget * target)
{
    int x;

    gAction.target = target->uid;

    ClearIcons();
    ApplyIconPalettes(BGPAL_ICONS);

    StartMenu(&MenuInfo_StealItem);

    EndMapSelect(proc);

    TmApplyTsa_t(gBg1Tm + TM_OFFSET(2, 2), Tsa_Unk_081022FC, TILEREF(BGCHR_WINDOWFRAME, BGPAL_WINDOWFRAME));

    x = (56 - GetStringTextLen(DecodeMsg(GetUnit(gAction.target)->pinfo->msg_name))) / 2;
    PutDrawText(NULL, gBg0Tm + TM_OFFSET(3, 3), TEXT_COLOR_SYSTEM_WHITE, x, 7,
        DecodeMsg(GetUnit(gAction.target)->pinfo->msg_name));

    PutFace80x72(gBg0Tm + TM_OFFSET(3, 5), GetUnitFid(GetUnit(gAction.target)),
        BGCHR_STEALSELECT_FACE, BGPAL_STEALSELECT_FACE);

    return 0;
}

fu8 StealItemMenu_Entry_Available(struct MenuEntInfo const * info, int id)
{
    if (GetUnit(gAction.target)->items[id] == 0)
        return MENU_ENTRY_HIDDEN;

    if (!IsItemStealable(GetUnit(gAction.target)->items[id]))
        return MENU_ENTRY_DISABLED;

    return MENU_ENTRY_ENABLED;
}

u32 StealItemMenu_Entry_Display(struct MenuProc * menu, struct MenuEntProc * ent)
{
    int item = GetUnit(gAction.target)->items[ent->id];
    bool is_usable = IsItemStealable(item);

    func_fe6_08016694(&ent->text, item, is_usable, gBg0Tm + TM_OFFSET(ent->x, ent->y));
}

fu8 StealItemMenu_Entry_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    if (ent->availability == MENU_ENTRY_DISABLED)
    {
        MenuFrozenHelpBox(menu, MSG_C38);
        return MENU_ACTION_SE_6B;
    }

    gAction.item_slot = ent->id;
    gAction.id = ACTION_STEAL;

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

fu8 MenuHelpBoxActiveUnitInventory(struct MenuProc * menu, struct MenuEntProc * ent)
{
    if (ent->id >= ITEMSLOT_INV_COUNT)
    {
        StartItemHelpBox(ent->x*8, ent->y*8, gBmSt.inventory_item_overflow);
        return 0;
    }

    StartItemHelpBox(ent->x*8, ent->y*8, gActiveUnit->items[ent->id]);
}

fu8 MenuHelpBoxTargetUnitInventory(struct MenuProc * menu, struct MenuEntProc * ent)
{
    struct Unit * unit = GetUnit(gAction.target);
    StartItemHelpBox(ent->x*8, ent->y*8, unit->items[ent->id]);
}

fu8 MenuHelpBoxActiveUnitBallista(struct MenuProc * menu, struct MenuEntProc * ent)
{
    int iid = gMapTerrain[gActiveUnit->y][gActiveUnit->x];

    switch (iid)
    {

    case TERRAIN_LONGBALLISTA:
        iid = IID_LONGBALLISTA;
        break;

    case TERRAIN_BALLISTA:
        iid = IID_BALLISTA;
        break;

    case TERRAIN_KILLERBALLISTA:
        iid = IID_KILLERBALLISTA;
        break;

    }

    StartItemHelpBox(ent->x*8, ent->y*8, iid);
}

void HealMapSelect_Init(struct MapSelectProc * proc)
{
    StartUnitHpPanel(proc);
}

fu8 HealMapSelect_SwitchIn(struct MapSelectProc * proc, struct SelectTarget * target)
{
    MakeActiveMuWatchPosition(target->x, target->y);
    RefreshUnitHpPanel(GetUnit(target->uid));
}

void RescueMapSelect_Init(struct MapSelectProc * proc)
{
    RefreshUnitTakeRescuePanels(proc);
    StartSubtitleHelp(proc, DecodeMsg(MSG_C1B));
}

fu8 RescueMapSelect_SwitchIn(struct MapSelectProc * proc, struct SelectTarget * target)
{
    MakeActiveMuWatchPosition(target->x, target->y);
    RefreshUnitRescuePanels(GetUnit(target->uid));
}

void DropRescueMapSelect_Init(struct MapSelectProc * proc)
{
    StartSubtitleHelp(proc, DecodeMsg(MSG_C1C));
}

fu8 func_fe6_080207F4(struct MapSelectProc * proc, struct SelectTarget * target)
{
}

void GiveRescueMapSelect_Init(struct MapSelectProc * proc)
{
    StartUnitGiveRescuePanels(proc);
    StartSubtitleHelp(proc, DecodeMsg(MSG_C1E));
}

fu8 GiveRescueMapSelect_SwitchIn(struct MapSelectProc * proc, struct SelectTarget * target)
{
    MakeActiveMuWatchPosition(target->x, target->y);
    RefreshUnitGivePanels(GetUnit(target->uid));
}

void TakeRescueMapSelect_Init(struct MapSelectProc * proc)
{
    RefreshUnitTakeRescuePanels(proc);
    StartSubtitleHelp(proc, DecodeMsg(MSG_C1D));
}

fu8 TakeRescueMapSelect_SwitchIn(struct MapSelectProc * proc, struct SelectTarget * target)
{
    MakeActiveMuWatchPosition(target->x, target->y);
    RefreshUnitTakePanels(GetUnit(target->uid));
}

void TradeMapSelect_Init(struct MapSelectProc * proc)
{
    StartUnitInventoryPanel(proc);
    StartSubtitleHelp(proc, DecodeMsg(MSG_C1F));
}

fu8 TradeMapSelect_SwitchIn(struct MapSelectProc * proc, struct SelectTarget * target)
{
    MakeActiveMuWatchPosition(target->x, target->y);
    RefreshUnitInventoryPanel(GetUnit(target->uid));
}

void TalkMapSelect_Init(struct MapSelectProc * proc)
{
    StartUnitHpPanel(proc);
    StartSubtitleHelp(proc, DecodeMsg(MSG_C22));
}

fu8 TalkMapSelect_SwitchIn(struct MapSelectProc * proc, struct SelectTarget * target)
{
    MakeActiveMuWatchPosition(target->x, target->y);
    RefreshUnitHpPanel(GetUnit(target->uid));
}

void RefreshMapSelect_Init(struct MapSelectProc * proc)
{
    StartUnitHpPanel(proc);
    StartSubtitleHelp(proc, DecodeMsg(MSG_C23));
}

fu8 RefreshMapSelect_SwitchIn(struct MapSelectProc * proc, struct SelectTarget * target)
{
    MakeActiveMuWatchPosition(target->x, target->y);
    RefreshUnitHpPanel(GetUnit(target->uid));
}

void WarpUnitMapSelect_Init(struct MapSelectProc * proc)
{
    StartUnitHpPanel(proc);
}

fu8 WarpUnitMapSelect_SwitchIn(struct MapSelectProc * proc, struct SelectTarget * target)
{
    MakeActiveMuWatchPosition(target->x, target->y);
    RefreshUnitHpPanel(GetUnit(target->uid));
}
