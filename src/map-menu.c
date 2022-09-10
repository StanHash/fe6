
#include "common.h"

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
#include "player-phase.h"
#include "bmfx.h"
#include "target-list.h"
#include "item-use.h"
#include "battle.h"
#include "trademenu.h"
#include "trap.h"
#include "supply.h"
#include "arena.h"
#include "action.h"
#include "unit-panel.h"
#include "subtitle-help.h"
#include "battle-preview.h"
#include "ui.h"
#include "menu.h"

#include "constants/video-global.h"
#include "constants/terrains.h"
#include "constants/pids.h"
#include "constants/items.h"
#include "constants/songs.h"

#include "event-script.h"

static void func_fe6_0801EAF8(ProcPtr proc);

EventScr CONST_DATA EventScr_085C5DE8[] =
{
    EvtNoSkipNoTextSkip

    EvtTalk(0x30A) // TODO: msgids
    EvtFunc(func_fe6_0801EAF8)

    EvtTalkMore(0x30B) // TODO: msgids

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

u8 func_fe6_0801EA40(struct MenuProc* menu, struct MenuEntProc* ent)
{
    SpawnProc(ProcScr_Unk_0868B010, PROC_TREE_3);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

int func_fe6_0801EA54(struct MenuEntInfo const* info, int id)
{
    if (gPlaySt.flags & PLAY_FLAG_3)
        return MENU_ENTRY_DISABLED;

    return MENU_ENTRY_ENABLED;
}

u8 func_fe6_0801EA6C(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (ent->availability == MENU_ENTRY_DISABLED)
    {
        MenuFrozenHelpBox(menu, 0xC46); // TODO: msgids
        return MENU_ACTION_SE_6B;
    }

    func_fe6_0809874C();

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

u8 func_fe6_0801EA90(struct MenuProc* menu, struct MenuEntProc* ent)
{
    Proc_EndEach(ProcScr_PlayerPhase);
    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

u8 func_fe6_0801EAA4(struct MenuProc* menu, struct MenuEntProc* ent)
{
    Proc_Goto(Proc_Find(ProcScr_PlayerPhase), L_PLAYERPHASE_10);
    func_fe6_08076238();

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

u8 func_fe6_0801EAC0(struct MenuProc* menu, struct MenuEntProc* ent)
{
    SpawnProc(ProcScr_Unk_0868AE04, PROC_TREE_3);
    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

u8 func_fe6_0801EAD4(struct MenuProc* menu, struct MenuEntProc* ent)
{
    func_fe6_080741C8(NULL);
    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

u8 func_fe6_0801EAE4(struct MenuProc* menu, struct MenuEntProc* ent)
{
    func_fe6_08089234(PROC_TREE_3);
    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

u8 func_fe6_0801EAF4(struct MenuProc* menu, struct MenuEntProc* ent)
{
    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

static void func_fe6_0801EAF8(ProcPtr proc)
{
    if (GetTalkChoiceResult() != 1)
        EventGotoLabel(proc, 99);
}

u8 func_fe6_0801EB14(struct MenuProc* menu, struct MenuEntProc* ent)
{
    StartEvent(EventScr_085C5DE8);
    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

u8 func_fe6_0801EB28(struct MenuProc* menu, struct MenuEntProc* ent)
{
    gAction.id = ACTION_WAIT;
    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

u8 func_fe6_0801EB38(struct MapSelectProc* proc, struct SelectTarget* target)
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

u8 func_fe6_0801EC1C(struct MapSelectProc* proc, struct SelectTarget* target)
{
    EndMapSelect(proc);

    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);

    EndLimitView();

    ResetTextFont();

    SpawnProc(ProcScr_BackToUnitMenu, PROC_TREE_3);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_SE_6B | MENU_ACTION_CLEAR;
}

u8 func_fe6_0801EC50(struct MenuProc* menu, struct MenuEntProc* ent)
{
    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);

    ResetTextFont();

    StartCenteredMenu(&MenuInfo_UnitAction, gBmSt.cursor_sprite_target.x - gBmSt.camera.x, 1, 22);

    EndLimitView();

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6B | MENU_ACTION_CLEAR | MENU_ACTION_ENDFACE;
}

int func_fe6_0801EC90(void)
{
    return 0;
}

int func_fe6_0801EC94(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_ENTRY_HIDDEN;

    if (gActiveUnit->state & US_RESCUING)
        return MENU_ENTRY_HIDDEN;

    ListRescueTargets(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_ENTRY_HIDDEN;

    return MENU_ENTRY_ENABLED;
}

u8 func_fe6_0801ECCC(struct MenuProc* menu, struct MenuEntProc* ent)
{
    ListRescueTargets(gActiveUnit);
    StartMapSelect(&MapSelectInfo_085C786C);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A;
}

u8 func_fe6_0801ECEC(struct MapSelectProc* proc, struct SelectTarget* target)
{
    gAction.target = target->uid;
    gAction.id = ACTION_RESCUE;

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

int func_fe6_0801ED00(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_ENTRY_HIDDEN;

    if (!(gActiveUnit->state & US_RESCUING))
        return MENU_ENTRY_HIDDEN;

    ListRescueDropTargets(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_ENTRY_HIDDEN;

    return MENU_ENTRY_ENABLED;
}

u8 func_fe6_0801ED38(struct MenuProc* menu, struct MenuEntProc* ent)
{
    ListRescueDropTargets(gActiveUnit);
    StartMapSelect(&MapSelectInfo_085C784C);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

u8 func_fe6_0801ED58(struct MapSelectProc* proc, struct SelectTarget* target)
{
    gAction.id = ACTION_DROP;

    gAction.target = gActiveUnit->rescue;
    gAction.x_target = target->x;
    gAction.y_target = target->y;

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

int func_fe6_0801ED7C(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_ENTRY_HIDDEN;

    if (gBmSt.partial_actions_taken & PARTIAL_ACTION_RESCUE_TRANSFER)
        return MENU_ENTRY_HIDDEN;

    if (gActiveUnit->state & US_RESCUING)
        return MENU_ENTRY_HIDDEN;

    ListRescueTakeTargets(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_ENTRY_HIDDEN;

    return MENU_ENTRY_ENABLED;
}

u8 func_fe6_0801EDC4(struct MenuProc* menu, struct MenuEntProc* ent)
{
    ListRescueTakeTargets(gActiveUnit);
    StartMapSelect(&MapSelectInfo_085C782C);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A;
}

int func_fe6_0801EDE4(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_ENTRY_HIDDEN;

    if (gBmSt.partial_actions_taken & PARTIAL_ACTION_RESCUE_TRANSFER)
        return MENU_ENTRY_HIDDEN;

    if (!(gActiveUnit->state & US_RESCUING))
        return MENU_ENTRY_HIDDEN;

    ListRescueGiveTargets(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_ENTRY_HIDDEN;

    return MENU_ENTRY_ENABLED;
}

u8 func_fe6_0801EE2C(struct MenuProc* menu, struct MenuEntProc* ent)
{
    ListRescueGiveTargets(gActiveUnit);
    StartMapSelect(&MapSelectInfo_085C780C);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A;
}

void func_fe6_0801EE4C(struct Unit* from, struct Unit* to)
{
    struct Unit* rescue = GetUnit(from->rescue);

    EndSubtitleHelp();
    StartRescueTransferAnimParentless(rescue, func_fe6_0801C160(to->x, to->y, from->x, from->y));
}

u8 func_fe6_0801EE80(struct MapSelectProc* proc, struct SelectTarget* target)
{
    gAction.id = ACTION_TAKE;
    gAction.target = target->uid;

    UnitSyncMovement(GetUnit(gAction.target));

    func_fe6_0801EE4C(GetUnit(gAction.target), GetUnit(gAction.instigator));
    UnitGiveRescue(GetUnit(gAction.target), GetUnit(gAction.instigator));

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

u8 func_fe6_0801EED0(struct MapSelectProc* proc, struct SelectTarget* target)
{
    gAction.id = ACTION_GIVE;
    gAction.target = target->uid;

    UnitSyncMovement(GetUnit(gAction.instigator));

    func_fe6_0801EE4C(GetUnit(gAction.instigator), GetUnit(gAction.target));
    UnitGiveRescue(GetUnit(gAction.instigator), GetUnit(gAction.target));

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

int func_fe6_0801EF20(struct MenuEntInfo const* info, int id)
{
    int i, item;

    if (gActiveUnit->state & US_HAS_MOVED)
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

u8 func_fe6_0801F004(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (ent->availability == MENU_ENTRY_DISABLED)
    {
        MenuFrozenHelpBox(menu, 0xC3B); // TODO: msg ids
        return MENU_ACTION_SE_6B;
    }

    ClearIcons();
    ApplyIconPalettes(BGPAL_ICONS);

    if (gBmSt.unk_30 == TRUE && gBmSt.unk_31 == TRUE)
    {
        StartSubtitleHelp(
            StartAdjustedMenu(&MenuInfo_085C7504, gBmSt.cursor_sprite_target.x - gBmSt.camera.x, 1, 20),
            DecodeMsg(0xC27)); // TODO: msg ids

        return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
    }

    if (gBmSt.unk_30)
        return func_fe6_0801F0F0(menu, ent);

    if (gBmSt.unk_31)
        return func_fe6_0801F0AC(menu, ent);

    return 0;
}

u8 func_fe6_0801F0AC(struct MenuProc* menu, struct MenuEntProc* ent)
{
    ProcPtr proc = StartMenu(&MenuInfo_085C75B8);

    StartFace(0, GetUnitFid(gActiveUnit), 176, 12, FACE_DISP_KIND(FACE_96x80));
    StartEquipInfoWindow(proc, gActiveUnit, 15, 11);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

u8 func_fe6_0801F0F0(struct MenuProc* menu, struct MenuEntProc* ent)
{
    ProcPtr proc = StartMenu(&MenuInfo_085C75DC);

    StartFace(0, GetUnitFid(gActiveUnit), 176, 12, FACE_DISP_KIND(FACE_96x80));
    StartEquipInfoWindow(proc, gActiveUnit, 15, 11);

    func_fe6_0806B4AC();

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

u8 func_fe6_0801F138(struct MenuProc* menu, struct MenuEntProc* ent)
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

u8 func_fe6_0801F1D0(struct MenuProc* menu, struct MenuEntProc* ent)
{
    EndLimitView();
    return 0;
}

int func_fe6_0801F1DC(struct MenuEntInfo const* info, int id)
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

u8 func_fe6_0801F228(struct MenuProc* menu, struct MenuEntProc* ent)
{
    UnitEquipItemSlot(gActiveUnit, ent->id);
    gAction.item_slot = ITEMSLOT_INV0;

    ClearUi();

    ListAttackTargetsForWeapon(gActiveUnit, gActiveUnit->items[0]);
    StartMapSelect(&MapSelectInfo_085C77EC);

    func_fe6_0806B4C8();

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_ENDFACE;
}

u8 func_fe6_0801F26C(struct MenuProc* menu, struct MenuEntProc* ent)
{
    int item = gActiveUnit->items[ent->id];
    bool is_usable = CanUnitUseWeapon(gActiveUnit, item);

    func_fe6_08016694(&ent->text, item, is_usable, gBg0Tm + TM_OFFSET(ent->x, ent->y));

    return 0;
}

u8 func_fe6_0801F2BC(struct MenuProc* menu, struct MenuEntProc* ent)
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

u8 func_fe6_0801F310(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (!(menu->flags & MENU_FLAG_ENDING))
        EndLimitView();

    return 0;
}

u8 func_fe6_0801F328(struct MapSelectProc* proc, struct SelectTarget* target)
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
    func_fe6_0801F004(NULL, NULL);
}

u8 func_fe6_0801F388(struct MapSelectProc* proc, struct SelectTarget* target)
{
    SpawnProc(ProcScr_Unk_085C5E58, PROC_TREE_3);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6B;
}

u8 func_fe6_0801F39C(struct MapSelectProc* proc, struct SelectTarget* target)
{
    struct Unit* unit = GetUnit(target->uid);

    func_fe6_0801D680(target->x, target->y);

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

u8 func_fe6_0801F420(struct MapSelectProc* proc)
{
    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);

    EndLimitView();
    CloseBattlePreview();

    return 0;
}

int func_fe6_0801F444(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_ENTRY_HIDDEN;

    if (gBmSt.partial_actions_taken & PARTIAL_ACTION_TRADED)
        return MENU_ENTRY_HIDDEN;

    ListTradeTargets(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_ENTRY_HIDDEN;

    return MENU_ENTRY_ENABLED;
}

u8 func_fe6_0801F484(struct MenuProc* menu, struct MenuEntProc* ent)
{
    ClearUi();

    ListTradeTargets(gActiveUnit);
    StartMapSelect(&MapSelectInfo_085C77CC);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A;
}

u8 func_fe6_0801F4A8(struct MapSelectProc* proc, struct SelectTarget* target)
{
    gAction.id = ACTION_TRADED_NOCHANGES;
    StartTradeMenu(gActiveUnit, GetUnit(target->uid), 0);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

int func_fe6_0801F4D8(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_ENTRY_HIDDEN;

    if (!(UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_13))
        return MENU_ENTRY_HIDDEN;

    return func_fe6_0806B028(gActiveUnit->x, gActiveUnit->y) == LOCATION_COMMAND_0F
        ? MENU_ENTRY_ENABLED : MENU_ENTRY_HIDDEN;
}

u8 func_fe6_0801F524(struct MenuProc* menu, struct MenuEntProc* ent)
{
    gAction.id = ACTION_0F;
    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

int func_fe6_0801F534(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_ENTRY_HIDDEN;

    if (gMapTerrain[gActiveUnit->y][gActiveUnit->x] != TERRAIN_VILLAGE && gMapTerrain[gActiveUnit->y][gActiveUnit->x] != TERRAIN_HOUSE)
        return MENU_ENTRY_HIDDEN;

    if (func_fe6_0806B028(gActiveUnit->x, gActiveUnit->y) != LOCATION_COMMAND_VISIT)
        return MENU_ENTRY_HIDDEN;

    if (gActiveUnit->status == UNIT_STATUS_SILENCED)
        return MENU_ENTRY_DISABLED;

    return MENU_ENTRY_ENABLED;
}

u8 func_fe6_0801F5A0(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (ent->availability == MENU_ENTRY_DISABLED)
    {
        MenuFrozenHelpBox(menu, 0xC30); // TODO: msg ids
        return MENU_ACTION_SE_6B;
    }

    gAction.id = ACTION_0E;
    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

int func_fe6_0801F5C8(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_ENTRY_HIDDEN;

    if (!(UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_PLAY))
        return MENU_ENTRY_HIDDEN;

    ListRefreshTargets(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_ENTRY_HIDDEN;

    return MENU_ENTRY_ENABLED;
}

int func_fe6_0801F608(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_ENTRY_HIDDEN;

    if (!(UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_DANCE))
        return MENU_ENTRY_HIDDEN;

    ListRefreshTargets(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_ENTRY_HIDDEN;

    return MENU_ENTRY_ENABLED;
}

u8 func_fe6_0801F648(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (ent->availability == MENU_ENTRY_DISABLED)
        return MENU_ACTION_SE_6B;

    ListRefreshTargets(gActiveUnit);
    StartMapSelect(&MapSelectInfo_085C76EC);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A;
}

u8 func_fe6_0801F674(struct MapSelectProc* proc, struct SelectTarget* target)
{
    gAction.id = ACTION_REFRESH;
    gAction.target = target->uid;

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

int func_fe6_0801F688(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_ENTRY_HIDDEN;

    if (gActiveUnit->items[0] == 0)
        return MENU_ENTRY_HIDDEN;

    return MENU_ENTRY_ENABLED;
}

u8 func_fe6_0801F6A8(struct MenuProc* menu, struct MenuEntProc* ent)
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

int func_fe6_0801F708(struct MenuProc* menu, struct MenuEntProc* ent)
{
    int item = gActiveUnit->items[ent->id];
    bool is_usable;

    if (GetItemAttributes(item) & ITEM_ATTR_WEAPON)
    {
        func_fe6_0801F26C(menu, ent);
        return 0;
    }

    is_usable = CanUnitUseItem(gActiveUnit, item);

    func_fe6_08016694(&ent->text, item, is_usable, gBg0Tm + TM_OFFSET(ent->x, ent->y));
    EnableBgSync(BG0_SYNC_BIT);
}

int func_fe6_0801F780(struct MenuEntInfo const* info, int id)
{
    int item = gActiveUnit->items[id];

    if (item == 0)
        return MENU_ENTRY_HIDDEN;

    if (GetItemAttributes(item) & ITEM_ATTR_WEAPON)
        func_fe6_0801F1DC(info, id); // BUG?

    return CanUnitUseItem(gActiveUnit, item)
        ? MENU_ENTRY_ENABLED : MENU_ENTRY_DISABLED;
}

u8 func_fe6_0801F7D0(struct MenuProc* menu, struct MenuEntProc* ent)
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

int func_fe6_0801F840(struct MenuProc* menu, struct MenuEntProc* ent)
{
    UpdateEquipInfoWindow(ent->id);
}

int func_fe6_0801F850(struct MenuProc* menu, struct MenuEntProc* ent)
{
}

void func_fe6_0801F854(int x, int y)
{
    InitTextFont(&gFont_Unk_02002770, (u8*) VRAM + CHR_SIZE*0x200, 0x200, 0);

    TmCopyRect_t(gBg0Tm + TM_OFFSET(11, 1), gUnk_Tm_02003238, 9, 19);
    TmCopyRect_t(gBg1Tm + TM_OFFSET(11, 1), gUnk_Tm_02003738, 9, 19);
}

void func_fe6_0801F898(struct MenuProc* menu)
{
    SetTextFont(NULL);
}

u8 func_fe6_0801F8A4(struct MenuProc* menu)
{
    SetTextFont(NULL);

    TmCopyRect_t(gUnk_Tm_02003238, gBg0Tm + TM_OFFSET(11, 1), 9, 19);
    TmCopyRect_t(gUnk_Tm_02003738, gBg1Tm + TM_OFFSET(11, 1), 9, 19);

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6B;
}

u8 func_fe6_0801F8E0(struct MenuProc* menu)
{
    SetTextFont(NULL);
    ResetTextFont();

    EndMenus();

    return MENU_ACTION_NOCURSOR | MENU_ACTION_CLEAR | MENU_ACTION_ENDFACE;
}

u8 func_fe6_0801F8F8(struct MenuProc* menu)
{
    ProcPtr proc;

    func_fe6_0801F8E0(menu);
    func_fe6_0801F8A4(menu);

    proc = StartMenu(&MenuInfo_UnitItem);

    StartFace(0, GetUnitFid(gActiveUnit), 176, 12, FACE_DISP_KIND(FACE_96x80));
    StartEquipInfoWindow(proc, gActiveUnit, 15, 11);

    return MENU_ACTION_NOCURSOR;
}

u8 func_fe6_0801F948(struct MenuProc* menu)
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

int func_fe6_0801FA14(struct MenuEntInfo const* info, int id)
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

int func_fe6_0801FA84(struct MenuEntInfo const* info, int id)
{
    int item = gActiveUnit->items[gAction.item_slot];

    if (!(GetItemAttributes(item) & ITEM_ATTR_WEAPON))
        return MENU_ENTRY_HIDDEN;

    return CanUnitUseWeapon(gActiveUnit, item)
        ? MENU_ENTRY_ENABLED : MENU_ENTRY_DISABLED;
}

int func_fe6_0801FACC(struct MenuEntInfo const* info, int id)
{
    int item = gActiveUnit->items[gAction.item_slot];

    if (GetItemAttributes(item) & ITEM_ATTR_IMPORTANT)
        return MENU_ENTRY_DISABLED;

    return MENU_ENTRY_ENABLED;
}

u8 func_fe6_0801FB00(struct MenuProc* menu, struct MenuEntProc* ent)
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

u8 func_fe6_0801FB68(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (ent->availability == MENU_ENTRY_DISABLED)
    {
        MenuFrozenHelpBox(menu, 0xC31); // TODO: msg ids
        return MENU_ACTION_SE_6B;
    }

    UnitEquipItemSlot(gActiveUnit, gAction.item_slot);

    return func_fe6_0801F8F8(menu);
}

u8 func_fe6_0801FBA8(struct MenuProc* menu, struct MenuEntProc* ent)
{
    gBmSt.unk_3F = gAction.item_slot;

    func_fe6_0801F8E0(menu);
    EndFaceById(0);

    func_fe6_0801F484(menu, ent);

    return MENU_ACTION_NOCURSOR;
}

u8 func_fe6_0801FBDC(struct MenuProc* menu, struct MenuEntProc* ent)
{
    struct MenuRect rect;

    if (ent->availability == MENU_ENTRY_DISABLED)
    {
        MenuFrozenHelpBox(menu, 0xC33); // TODO: msg ids
        return MENU_ACTION_SE_6B;
    }

    rect.x = ent->x + 3;
    rect.y = ent->y;
    rect.w = 5;
    rect.h = 0;

    StartLockingMenuExt(&MenuInfo_UnitItemDiscardPrompt, rect, menu)->active_entry = 1;

    return MENU_ACTION_SE_6A | MENU_ACTION_DOOM;
}

u8 func_fe6_0801FC50(struct MenuProc* menu, struct MenuEntProc* ent)
{
    UnitRemoveItem(gActiveUnit, gAction.item_slot);

    func_fe6_0801F948(menu);
    return MENU_ACTION_NOCURSOR;
}

int func_fe6_0801FC78(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_ENTRY_HIDDEN;

    if ((GetBallistaItemAt(gActiveUnit->x, gActiveUnit->y) & 0xFF00) != 0)
        return MENU_ENTRY_ENABLED;

    return MENU_ENTRY_DISABLED;
}

int func_fe6_0801FCB4(struct MenuProc* menu, struct MenuEntProc* ent)
{
    bool is_usable = (ent->availability == MENU_ENTRY_ENABLED) ? TRUE : FALSE;
    int item = GetBallistaItemAt(gActiveUnit->x, gActiveUnit->y);

    func_fe6_08016694(&ent->text, item, is_usable, gBg0Tm + TM_OFFSET(ent->x, ent->y));
}

u8 func_fe6_0801FD04(struct MenuProc* menu, struct MenuEntProc* ent)
{
    ClearUi();

    gAction.item_slot = ITEMSLOT_BALLISTA;

    func_fe6_08021278(gActiveUnit);
    StartMapSelect(&MapSelectInfo_085C77EC);

    return MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_ENDFACE;
}

int func_fe6_0801FD30(struct MenuProc* menu, struct MenuEntProc* ent)
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

int func_fe6_0801FDB8(struct MenuEntInfo const* info, int id)
{
    int i, item;

    if (gActiveUnit->state & US_HAS_MOVED)
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

u8 func_fe6_0801FE30(struct MenuProc* menu, struct MenuEntProc* ent)
{
    ProcPtr proc;

    if (ent->availability == MENU_ENTRY_DISABLED)
    {
        MenuFrozenHelpBox(menu, 0xC34); // TODO: msg ids
        return MENU_ACTION_SE_6B;
    }

    ClearIcons();
    ApplyIconPalettes(BGPAL_ICONS);

    proc = StartMenu(&MenuInfo_085C7570);

    StartFace(0, GetUnitFid(gActiveUnit), 176, 12, FACE_DISP_KIND(FACE_96x80));
    StartEquipInfoWindow(proc, gActiveUnit, 15, 11);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

int func_fe6_0801FE94(struct MenuProc* menu, struct MenuEntProc* ent)
{
    int reach = GetUnitItemUseReach(gActiveUnit, -1);

    MapFill(gMapMovement, -1);
    MapFill(gMapRange, 0);

    BuildUnitStandingRangeForReach(gActiveUnit, reach);
    StartLimitView(LIMITVIEW_BLUE | LIMITVIEW_GREEN);

    return 0;
}

int func_fe6_0801FEDC(struct MenuProc* menu, struct MenuEntProc* ent)
{
    EndLimitView();
    return 0;
}

int func_fe6_0801FEE8(struct MenuEntInfo const* info, int id)
{
    int item = gActiveUnit->items[id];

    if (GetItemKind(item) != ITEM_KIND_STAFF)
        return MENU_ENTRY_HIDDEN;

    if (!CanUnitUseItem(gActiveUnit, item))
        return MENU_ENTRY_HIDDEN;

    return MENU_ENTRY_ENABLED;
}

u8 func_fe6_0801FF20(struct MenuProc* menu, struct MenuEntProc* ent)
{
    UnitEquipItemSlot(gActiveUnit, ent->id);
    gAction.item_slot = ITEMSLOT_INV0;

    ClearUi();

    DoUseUnitItem(gActiveUnit, gActiveUnit->items[gAction.item_slot]);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A;
}

int func_fe6_0801FF60(struct MenuProc* menu, struct MenuEntProc* ent)
{
    return func_fe6_0801F708(menu, ent);
}

int func_fe6_0801FF6C(struct MenuProc* menu, struct MenuEntProc* ent)
{
    int reach = GetUnitItemUseReach(gActiveUnit, ent->id);

    UpdateEquipInfoWindow(ent->id);

    MapFill(gMapMovement, -1);
    MapFill(gMapRange, 0);

    BuildUnitStandingRangeForReach(gActiveUnit, reach);
    StartLimitView(LIMITVIEW_GREEN);

    return 0;
}

int func_fe6_0801FFC0(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (!(menu->flags & MENU_FLAG_ENDING))
        EndLimitView();

    return 0;
}

int func_fe6_0801FFD8(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_ENTRY_HIDDEN;

    ListTalkTargets(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_ENTRY_HIDDEN;

    if (gActiveUnit->status == UNIT_STATUS_SILENCED)
        return MENU_ENTRY_DISABLED;

    return MENU_ENTRY_ENABLED;
}

u8 func_fe6_0802001C(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (ent->availability == MENU_ENTRY_DISABLED)
    {
        MenuFrozenHelpBox(menu, 0xC35); // TODO: msg ids
        return MENU_ACTION_SE_6B;
    }

    ListTalkTargets(gActiveUnit);
    StartMapSelect(&MapSelectInfo_085C778C);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A;
}

u8 func_fe6_08020050(struct MapSelectProc* proc, struct SelectTarget* target)
{
    gAction.id = ACTION_TALK;
    gAction.target = target->uid;

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

int func_fe6_08020064(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
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

u8 func_fe6_080200B4(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (ent->availability == MENU_ENTRY_DISABLED)
    {
        MenuFrozenHelpBox(menu, 0xC35); // TODO: msg ids
        return MENU_ACTION_SE_6B;
    }

    ListSupportTargets(gActiveUnit);
    StartMapSelect(&MapSelectInfo_085C776C);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A;
}

u8 func_fe6_080200E8(struct MapSelectProc* proc, struct SelectTarget* target)
{
    gAction.id = ACTION_SUPPORT;
    gAction.target = target->uid;

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

int func_fe6_080200FC(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_ENTRY_HIDDEN;

    if (GetUnitKeyItemSlotForTerrain(gActiveUnit, TERRAIN_DOOR) < 0)
        return MENU_ENTRY_HIDDEN;

    ListOpenTerrainTargets(gActiveUnit, TERRAIN_DOOR);

    return (CountTargets() == 0)
        ? MENU_ENTRY_HIDDEN : MENU_ENTRY_ENABLED;
}

u8 func_fe6_0802013C(struct MenuProc* menu, struct MenuEntProc* ent)
{
    gAction.id = ACTION_DOOR;
    gAction.instigator = gActiveUnit->id;
    gAction.item_slot = GetUnitKeyItemSlotForTerrain(gActiveUnit, TERRAIN_DOOR);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

int func_fe6_08020164(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_ENTRY_HIDDEN;

    if (GetUnitKeyItemSlotForTerrain(gActiveUnit, TERRAIN_CHEST) < 0)
        return MENU_ENTRY_HIDDEN;

    return CanUnitUseChestKeyItem(gActiveUnit)
        ? MENU_ENTRY_ENABLED : MENU_ENTRY_HIDDEN;
}

u8 func_fe6_080201A0(struct MenuProc* menu, struct MenuEntProc* ent)
{
    gAction.id = ACTION_CHEST;
    gAction.item_slot = GetUnitKeyItemSlotForTerrain(gActiveUnit, TERRAIN_CHEST);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

int func_fe6_080201C4(struct MenuEntInfo const* info, int id)
{
    struct Unit* merlinus;

    if (gActiveUnit->state & US_HAS_MOVED)
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

    if (merlinus->state & US_HIDDEN)
        return MENU_ENTRY_HIDDEN;

    if (RECT_DISTANCE(gActiveUnit->x, gActiveUnit->y, merlinus->x, merlinus->y) == 1)
        return MENU_ENTRY_ENABLED;

    return MENU_ENTRY_HIDDEN;
}

u8 func_fe6_08020268(struct MenuProc* menu, struct MenuEntProc* ent)
{
    gAction.id = ACTION_TRADED_NOCHANGES;

    func_fe6_080815E4(gActiveUnit, NULL);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

int func_fe6_08020288(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_ENTRY_HIDDEN;

    return func_fe6_0806B028(gActiveUnit->x, gActiveUnit->y) == LOCATION_COMMAND_13
        ? MENU_ENTRY_ENABLED : MENU_ENTRY_HIDDEN;
}

u8 func_fe6_080202C4(struct MenuProc* menu, struct MenuEntProc* ent)
{
    func_fe6_0806B06C(gActiveUnit->x, gActiveUnit->y);
    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

int func_fe6_080202E4(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_ENTRY_HIDDEN;

    return func_fe6_0806B028(gActiveUnit->x, gActiveUnit->y) == LOCATION_COMMAND_14
        ? MENU_ENTRY_ENABLED : MENU_ENTRY_HIDDEN;
}

u8 func_fe6_08020320(struct MenuProc* menu, struct MenuEntProc* ent)
{
    func_fe6_0806B06C(gActiveUnit->x, gActiveUnit->y);
    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

int func_fe6_08020340(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_ENTRY_HIDDEN;

    return func_fe6_0806B028(gActiveUnit->x, gActiveUnit->y) == LOCATION_COMMAND_15
        ? MENU_ENTRY_ENABLED : MENU_ENTRY_HIDDEN;
}

u8 func_fe6_0802037C(struct MenuProc* menu, struct MenuEntProc* ent)
{
    func_fe6_0806B06C(gActiveUnit->x, gActiveUnit->y);
    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

int func_fe6_0802039C(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_ENTRY_HIDDEN;

    if (gMapTerrain[gActiveUnit->y][gActiveUnit->x] != TERRAIN_ARENA_08)
        return MENU_ENTRY_HIDDEN;

    return ArenaIsUnitAllowed(gActiveUnit)
        ? MENU_ENTRY_ENABLED : MENU_ENTRY_DISABLED;
}

u8 func_fe6_080203EC(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (ent->availability == MENU_ENTRY_DISABLED)
    {
        if (gActiveUnit->status == UNIT_STATUS_SILENCED)
            MenuFrozenHelpBox(menu, 0xC36); // TODO: msg ids
        else
            MenuFrozenHelpBox(menu, 0xC37); // TODO: msg ids

        return MENU_ACTION_SE_6B;
    }

    func_fe6_08097E84();
    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

int func_fe6_08020438(struct MenuEntInfo const* info, int id)
{
    if (!(UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_STEAL))
        return MENU_ENTRY_HIDDEN;

    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_ENTRY_HIDDEN;

    ListStealTargets(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_ENTRY_HIDDEN;

    if (GetUnitItemCount(gActiveUnit) == ITEMSLOT_INV_COUNT)
        return MENU_ENTRY_DISABLED;

    return MENU_ENTRY_ENABLED;
}

u8 func_fe6_08020488(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (ent->availability == MENU_ENTRY_DISABLED)
    {
        MenuFrozenHelpBox(menu, 0xC44); // TODO: msg ids
        return MENU_ACTION_SE_6B;
    }

    ClearUi();

    ListStealTargets(gActiveUnit);
    StartMapSelect(&MapSelectInfo_Steal);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A;
}

void func_fe6_080204C0(struct MapSelectProc* proc)
{
    StartUnitInventoryPanel(proc);
    StartSubtitleHelp(proc, DecodeMsg(0xC20)); // TODO: msg ids
}

int func_fe6_080204E0(struct MapSelectProc* proc, struct SelectTarget* target)
{
    func_fe6_0801D680(target->x, target->y);
    RefreshUnitStealInventoryPanel(GetUnit(target->uid));
}

int func_fe6_08020504(struct MapSelectProc* proc, struct SelectTarget* target)
{
    int x;

    gAction.target = target->uid;

    ClearIcons();
    ApplyIconPalettes(BGPAL_ICONS);

    StartMenu(&MenuInfo_085C74BC);

    EndMapSelect(proc);

    TmApplyTsa_t(gBg1Tm + TM_OFFSET(2, 2), Tsa_Unk_081022FC, TILEREF(BGCHR_WINDOW_FRAME, BGPAL_WINDOW_FRAME));

    x = (56 - GetStringTextLen(DecodeMsg(GetUnit(gAction.target)->pinfo->msg_name))) / 2;
    PutDrawText(NULL, gBg0Tm + TM_OFFSET(3, 3), TEXT_COLOR_SYSTEM_WHITE, x, 7,
        DecodeMsg(GetUnit(gAction.target)->pinfo->msg_name));

    PutFace80x72(gBg0Tm + TM_OFFSET(3, 5), GetUnitFid(GetUnit(gAction.target)),
        BGCHR_STEALSELECT_FACE, BGPAL_STEALSELECT_FACE);

    return 0;
}

int func_fe6_080205A8(struct MenuEntInfo const* info, int id)
{
    if (GetUnit(gAction.target)->items[id] == 0)
        return MENU_ENTRY_HIDDEN;

    if (!IsItemStealable(GetUnit(gAction.target)->items[id]))
        return MENU_ENTRY_DISABLED;

    return MENU_ENTRY_ENABLED;
}

int func_fe6_080205EC(struct MenuProc* menu, struct MenuEntProc* ent)
{
    int item = GetUnit(gAction.target)->items[ent->id];
    bool is_usable = IsItemStealable(item);

    func_fe6_08016694(&ent->text, item, is_usable, gBg0Tm + TM_OFFSET(ent->x, ent->y));
}

u8 func_fe6_08020640(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (ent->availability == MENU_ENTRY_DISABLED)
    {
        MenuFrozenHelpBox(menu, 0xC38); // TODO: msg ids
        return MENU_ACTION_SE_6B;
    }

    gAction.item_slot = ent->id;
    gAction.id = ACTION_STEAL;

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

int func_fe6_08020678(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (ent->id >= ITEMSLOT_INV_COUNT)
    {
        StartItemHelpBox(ent->x*8, ent->y*8, gBmSt.inventory_item_overflow);
        return 0;
    }

    StartItemHelpBox(ent->x*8, ent->y*8, gActiveUnit->items[ent->id]);
}

int func_fe6_080206D0(struct MenuProc* menu, struct MenuEntProc* ent)
{
    struct Unit* unit = GetUnit(gAction.target);
    StartItemHelpBox(ent->x*8, ent->y*8, unit->items[ent->id]);
}

int func_fe6_08020708(struct MenuProc* menu, struct MenuEntProc* ent)
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

void func_fe6_08020764(struct MapSelectProc* proc)
{
    StartUnitHpPanel(proc);
}

int func_fe6_08020770(struct MapSelectProc* proc, struct SelectTarget* target)
{
    func_fe6_0801D680(target->x, target->y);
    RefreshUnitHpPanel(GetUnit(target->uid));
}

void func_fe6_08020794(struct MapSelectProc* proc)
{
    RefreshUnitTakeRescuePanels(proc);
    StartSubtitleHelp(proc, DecodeMsg(0xC1B)); // TODO: msg ids
}

int func_fe6_080207B4(struct MapSelectProc* proc, struct SelectTarget* target)
{
    func_fe6_0801D680(target->x, target->y);
    RefreshUnitRescuePanels(GetUnit(target->uid));
}

void func_fe6_080207D8(struct MapSelectProc* proc)
{
    StartSubtitleHelp(proc, DecodeMsg(0xC1C)); // TODO: msg ids
}

int func_fe6_080207F4(struct MapSelectProc* proc, struct SelectTarget* target)
{
}

void func_fe6_080207F8(struct MapSelectProc* proc)
{
    StartUnitGiveRescuePanels(proc);
    StartSubtitleHelp(proc, DecodeMsg(0xC1E)); // TODO: msg ids
}

int func_fe6_08020818(struct MapSelectProc* proc, struct SelectTarget* target)
{
    func_fe6_0801D680(target->x, target->y);
    RefreshUnitGivePanels(GetUnit(target->uid));
}

void func_fe6_0802083C(struct MapSelectProc* proc)
{
    RefreshUnitTakeRescuePanels(proc);
    StartSubtitleHelp(proc, DecodeMsg(0xC1D)); // TODO: msg ids
}

int func_fe6_0802085C(struct MapSelectProc* proc, struct SelectTarget* target)
{
    func_fe6_0801D680(target->x, target->y);
    RefreshUnitTakePanels(GetUnit(target->uid));
}

void func_fe6_08020880(struct MapSelectProc* proc)
{
    StartUnitInventoryPanel(proc);
    StartSubtitleHelp(proc, DecodeMsg(0xC1F)); // TODO: msg ids
}

int func_fe6_080208A0(struct MapSelectProc* proc, struct SelectTarget* target)
{
    func_fe6_0801D680(target->x, target->y);
    RefreshUnitInventoryPanel(GetUnit(target->uid));
}

void func_fe6_080208C4(struct MapSelectProc* proc)
{
    StartUnitHpPanel(proc);
    StartSubtitleHelp(proc, DecodeMsg(0xC22)); // TODO: msg ids
}

int func_fe6_080208E4(struct MapSelectProc* proc, struct SelectTarget* target)
{
    func_fe6_0801D680(target->x, target->y);
    RefreshUnitHpPanel(GetUnit(target->uid));
}

void func_fe6_08020908(struct MapSelectProc* proc)
{
    StartUnitHpPanel(proc);
    StartSubtitleHelp(proc, DecodeMsg(0xC23)); // TODO: msg ids
}

int func_fe6_08020928(struct MapSelectProc* proc, struct SelectTarget* target)
{
    func_fe6_0801D680(target->x, target->y);
    RefreshUnitHpPanel(GetUnit(target->uid));
}

void func_fe6_0802094C(struct MapSelectProc* proc)
{
    StartUnitHpPanel(proc);
}

int func_fe6_08020958(struct MapSelectProc* proc, struct SelectTarget* target)
{
    func_fe6_0801D680(target->x, target->y);
    RefreshUnitHpPanel(GetUnit(target->uid));
}
