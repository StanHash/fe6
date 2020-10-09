
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
#include "menu.h"

#include "constants/video-global.h"
#include "constants/terrains.h"
#include "constants/pids.h"
#include "constants/items.h"

#include "event-script.h"

static void sub_801EAF8(ProcPtr proc);

EventScr CONST_DATA EventScr_085C5DE8[] =
{
    EvtNoSkipNoTextSkip

    EvtTalk(0x30A) // TODO: msgids
    EvtFunc(sub_801EAF8)

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

static void sub_801F35C(ProcPtr proc);
static void sub_801F378(ProcPtr proc);

struct ProcScr CONST_DATA ProcScr_Unk_085C5E58[] =
{
    PROC_CALL(LockGame),

    PROC_CALL(sub_801F35C),

    PROC_WHILE_EXISTS(ProcScr_BattlePreview),
    PROC_WHILE_EXISTS(ProcScr_CamMove),

    PROC_CALL(sub_801F378),

    PROC_CALL(UnlockGame),

    PROC_END,
};

u8 sub_801EA40(struct MenuProc* menu, struct MenuEntProc* ent)
{
    SpawnProc(ProcScr_Unk_0868B010, PROC_TREE_3);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

int sub_801EA54(struct MenuEntInfo const* info, int id)
{
    if (gPlaySt.flags & PLAY_FLAG_3)
        return MENU_DISABLED;

    return MENU_ENABLED;
}

u8 sub_801EA6C(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (ent->availability == MENU_DISABLED)
    {
        MenuFrozenHelpBox(menu, 0xC46); // TODO: msgids
        return MENU_ACT_SE_6B;
    }

    sub_809874C();

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

u8 sub_801EA90(struct MenuProc* menu, struct MenuEntProc* ent)
{
    Proc_EndEach(ProcScr_PlayerPhase);
    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

u8 sub_801EAA4(struct MenuProc* menu, struct MenuEntProc* ent)
{
    Proc_Goto(Proc_Find(ProcScr_PlayerPhase), L_PLAYERPHASE_10);
    sub_8076238();

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

u8 sub_801EAC0(struct MenuProc* menu, struct MenuEntProc* ent)
{
    SpawnProc(ProcScr_Unk_0868AE04, PROC_TREE_3);
    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

u8 sub_801EAD4(struct MenuProc* menu, struct MenuEntProc* ent)
{
    sub_80741C8(NULL);
    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

u8 sub_801EAE4(struct MenuProc* menu, struct MenuEntProc* ent)
{
    sub_8089234(PROC_TREE_3);
    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

u8 sub_801EAF4(struct MenuProc* menu, struct MenuEntProc* ent)
{
    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

static void sub_801EAF8(ProcPtr proc)
{
    if (GetTalkChoiceResult() != 1)
        EventGotoLabel(proc, 99);
}

u8 sub_801EB14(struct MenuProc* menu, struct MenuEntProc* ent)
{
    StartEvent(EventScr_085C5DE8);
    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

u8 sub_801EB28(struct MenuProc* menu, struct MenuEntProc* ent)
{
    gAction.id = ACTION_WAIT;
    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

u8 sub_801EB38(struct MapSelectProc* proc, struct SelectTarget* target)
{
    EndMapSelect(proc);

    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);

    ResetTextFont();

    EndLimitView();

    CameraMoveWatchPosition(
        sub_8042018(&MenuInfo_UnitMenu, gBmSt.cursorSprTarget.x - gBmSt.camera.x, 1, 22),
        gActiveUnit->x, gActiveUnit->y);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_SE_6B | MENU_ACT_CLEAR;
}

static void BackToUnitMenu_CamWatch(ProcPtr proc)
{
    if (IsCameraNotWatchingPosition(gActiveUnit->x, gActiveUnit->y))
    {
        int y = gActiveUnit->y;

        Proc_EndEach(ProcScr_CamMove);

        if (GetCameraAdjustedY(y<<4) > gBmSt.cameraMax.y)
            y = (gBmSt.cameraMax.y>>4) + 2;

        CameraMoveWatchPosition(proc, gActiveUnit->x, y);
    }
}

static void BackToUnitMenu_RestartMenu(ProcPtr proc)
{
    sub_8042018(&MenuInfo_UnitMenu, gBmSt.cursorSprTarget.x - gBmSt.camera.x, 1, 22);
}

u8 sub_801EC1C(struct MapSelectProc* proc, struct SelectTarget* target)
{
    EndMapSelect(proc);

    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);

    EndLimitView();

    ResetTextFont();

    SpawnProc(ProcScr_BackToUnitMenu, PROC_TREE_3);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_SE_6B | MENU_ACT_CLEAR;
}

u8 sub_801EC50(struct MenuProc* menu, struct MenuEntProc* ent)
{
    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);

    ResetTextFont();

    sub_8042018(&MenuInfo_UnitMenu, gBmSt.cursorSprTarget.x - gBmSt.camera.x, 1, 22);

    EndLimitView();

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6B | MENU_ACT_CLEAR | MENU_ACT_ENDFACE;
}

int sub_801EC90(void)
{
    return 0;
}

int sub_801EC94(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_NOTSHOWN;

    if (gActiveUnit->state & US_RESCUING)
        return MENU_NOTSHOWN;

    ListRescueTargets(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_NOTSHOWN;

    return MENU_ENABLED;
}

u8 sub_801ECCC(struct MenuProc* menu, struct MenuEntProc* ent)
{
    ListRescueTargets(gActiveUnit);
    StartMapSelect(&MapSelectInfo_085C786C);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A;
}

u8 sub_801ECEC(struct MapSelectProc* proc, struct SelectTarget* target)
{
    gAction.target = target->uid;
    gAction.id = ACTION_RESCUE;

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

int sub_801ED00(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_NOTSHOWN;

    if (!(gActiveUnit->state & US_RESCUING))
        return MENU_NOTSHOWN;

    ListRescueDropTargets(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_NOTSHOWN;

    return MENU_ENABLED;
}

u8 sub_801ED38(struct MenuProc* menu, struct MenuEntProc* ent)
{
    ListRescueDropTargets(gActiveUnit);
    StartMapSelect(&MapSelectInfo_085C784C);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

u8 sub_801ED58(struct MapSelectProc* proc, struct SelectTarget* target)
{
    gAction.id = ACTION_DROP;

    gAction.target = gActiveUnit->rescue;
    gAction.xTarget = target->x;
    gAction.yTarget = target->y;

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

int sub_801ED7C(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_NOTSHOWN;

    if (gBmSt.partialActionsTaken & PARTIAL_ACTION_RESCUE_TRANSFER)
        return MENU_NOTSHOWN;

    if (gActiveUnit->state & US_RESCUING)
        return MENU_NOTSHOWN;

    ListRescueTakeTargets(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_NOTSHOWN;

    return MENU_ENABLED;
}

u8 sub_801EDC4(struct MenuProc* menu, struct MenuEntProc* ent)
{
    ListRescueTakeTargets(gActiveUnit);
    StartMapSelect(&MapSelectInfo_085C782C);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A;
}

int sub_801EDE4(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_NOTSHOWN;

    if (gBmSt.partialActionsTaken & PARTIAL_ACTION_RESCUE_TRANSFER)
        return MENU_NOTSHOWN;

    if (!(gActiveUnit->state & US_RESCUING))
        return MENU_NOTSHOWN;

    ListRescueGiveTargets(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_NOTSHOWN;

    return MENU_ENABLED;
}

u8 sub_801EE2C(struct MenuProc* menu, struct MenuEntProc* ent)
{
    ListRescueGiveTargets(gActiveUnit);
    StartMapSelect(&MapSelectInfo_085C780C);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A;
}

void sub_801EE4C(struct Unit* from, struct Unit* to)
{
    struct Unit* rescue = GetUnit(from->rescue);

    EndSubtitleHelp();
    StartRescueTransferAnimParentless(rescue, sub_801C160(to->x, to->y, from->x, from->y));
}

u8 sub_801EE80(struct MapSelectProc* proc, struct SelectTarget* target)
{
    gAction.id = ACTION_TAKE;
    gAction.target = target->uid;

    UnitSyncMovement(GetUnit(gAction.target));

    sub_801EE4C(GetUnit(gAction.target), GetUnit(gAction.instigator));
    UnitGiveRescue(GetUnit(gAction.target), GetUnit(gAction.instigator));

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

u8 sub_801EED0(struct MapSelectProc* proc, struct SelectTarget* target)
{
    gAction.id = ACTION_GIVE;
    gAction.target = target->uid;

    UnitSyncMovement(GetUnit(gAction.instigator));

    sub_801EE4C(GetUnit(gAction.instigator), GetUnit(gAction.target));
    UnitGiveRescue(GetUnit(gAction.instigator), GetUnit(gAction.target));

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

int sub_801EF20(struct MenuEntInfo const* info, int id)
{
    int i, item;

    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_NOTSHOWN;

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
        sub_8021278(gActiveUnit);

        if (CountTargets() != 0)
        {
            gBmSt.unk_31 = TRUE;

            if (GetObstacleHpAt(gActiveUnit->x, gActiveUnit->y) == 0)
                return MENU_DISABLED;
        }
    }

    if (gBmSt.unk_30 || gBmSt.unk_31)
        return MENU_ENABLED;

    return MENU_NOTSHOWN;
}

u8 sub_801F004(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (ent->availability == MENU_DISABLED)
    {
        MenuFrozenHelpBox(menu, 0xC3B); // TODO: msg ids
        return MENU_ACT_SE_6B;
    }

    ClearIcons();
    ApplyIconPalettes(BGPAL_ICONS);

    if (gBmSt.unk_30 == TRUE && gBmSt.unk_31 == TRUE)
    {
        StartSubtitleHelp(
            sub_80417E8(&MenuInfo_085C7504, gBmSt.cursorSprTarget.x - gBmSt.camera.x, 1, 20),
            DecodeMsg(0xC27)); // TODO: msg ids

        return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
    }

    if (gBmSt.unk_30)
        return sub_801F0F0(menu, ent);

    if (gBmSt.unk_31)
        return sub_801F0AC(menu, ent);

    return 0;
}

u8 sub_801F0AC(struct MenuProc* menu, struct MenuEntProc* ent)
{
    ProcPtr proc = sub_8041834(&MenuInfo_085C75B8);

    StartFace(0, GetUnitFid(gActiveUnit), 176, 12, FACE_DISP_KIND(FACE_96x80));
    StartEquipInfoWindow(proc, gActiveUnit, 15, 11);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

u8 sub_801F0F0(struct MenuProc* menu, struct MenuEntProc* ent)
{
    ProcPtr proc = sub_8041834(&MenuInfo_085C75DC);

    StartFace(0, GetUnitFid(gActiveUnit), 176, 12, FACE_DISP_KIND(FACE_96x80));
    StartEquipInfoWindow(proc, gActiveUnit, 15, 11);

    sub_806B4AC();

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

u8 sub_801F138(struct MenuProc* menu, struct MenuEntProc* ent)
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

u8 sub_801F1D0(struct MenuProc* menu, struct MenuEntProc* ent)
{
    EndLimitView();
    return 0;
}

int sub_801F1DC(struct MenuEntInfo const* info, int id)
{
    int item = gActiveUnit->items[id];

    if (!(GetItemAttributes(item) & ITEM_ATTR_WEAPON))
        return MENU_NOTSHOWN;

    if (!CanUnitUseWeapon(gActiveUnit, item))
        return MENU_NOTSHOWN;

    ListAttackTargetsForWeapon(gActiveUnit, item);

    if (CountTargets() == 0)
        return MENU_NOTSHOWN;

    return MENU_ENABLED;
}

u8 sub_801F228(struct MenuProc* menu, struct MenuEntProc* ent)
{
    UnitEquipItemSlot(gActiveUnit, ent->id);
    gAction.itemSlot = ITEMSLOT_INV0;

    ClearBg0Bg1();

    ListAttackTargetsForWeapon(gActiveUnit, gActiveUnit->items[0]);
    StartMapSelect(&MapSelectInfo_085C77EC);

    sub_806B4C8();

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_ENDFACE;
}

u8 sub_801F26C(struct MenuProc* menu, struct MenuEntProc* ent)
{
    int item = gActiveUnit->items[ent->id];
    Bool isUseable = CanUnitUseWeapon(gActiveUnit, item);

    sub_8016694(&ent->text, item, isUseable, gBg0Tm + TM_OFFSET(ent->x, ent->y));

    return 0;
}

u8 sub_801F2BC(struct MenuProc* menu, struct MenuEntProc* ent)
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

u8 sub_801F310(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (!(menu->flags & MENU_FLAG_2))
        EndLimitView();

    return 0;
}

u8 sub_801F328(struct MapSelectProc* proc, struct SelectTarget* target)
{
    gAction.id = ACTION_COMBAT;
    gAction.target = target->uid;

    if (target->uid == 0)
    {
        gAction.xTarget = target->x;
        gAction.yTarget = target->y;
        gAction.extra = target->extra;
    }

    Proc_EndEach(ProcScr_BattlePreview);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

static void sub_801F35C(ProcPtr proc)
{
    CameraMoveWatchPosition(NULL, gActiveUnit->x, gActiveUnit->y);
}

static void sub_801F378(ProcPtr proc)
{
    sub_801F004(NULL, NULL);
}

u8 sub_801F388(struct MapSelectProc* proc, struct SelectTarget* target)
{
    SpawnProc(ProcScr_Unk_085C5E58, PROC_TREE_3);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6B;
}

u8 sub_801F39C(struct MapSelectProc* proc, struct SelectTarget* target)
{
    struct Unit* unit = GetUnit(target->uid);

    sub_801D680(target->x, target->y);

    if (target->uid == 0)
    {
        gAction.xTarget = target->x;
        gAction.yTarget = target->y;
        gAction.extra = target->extra;

        InitObstacleBattleUnit();
    }

    if (gAction.itemSlot == ITEMSLOT_BALLISTA)
        BattleGenerateBallistaSimulation(gActiveUnit, unit, gActiveUnit->x, gActiveUnit->y);
    else
        BattleGenerateSimulation(gActiveUnit, unit, -1, -1, gAction.itemSlot);

    UpdateBattlePreviewContents();

    return 0;
}

u8 sub_801F420(struct MapSelectProc* proc)
{
    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);

    EndLimitView();
    CloseBattlePreview();

    return 0;
}

int sub_801F444(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_NOTSHOWN;

    if (gBmSt.partialActionsTaken & PARTIAL_ACTION_TRADED)
        return MENU_NOTSHOWN;

    ListTradeTargets(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_NOTSHOWN;

    return MENU_ENABLED;
}

u8 sub_801F484(struct MenuProc* menu, struct MenuEntProc* ent)
{
    ClearBg0Bg1();

    ListTradeTargets(gActiveUnit);
    StartMapSelect(&MapSelectInfo_085C77CC);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A;
}

u8 sub_801F4A8(struct MapSelectProc* proc, struct SelectTarget* target)
{
    gAction.id = ACTION_TRADED_NOCHANGES;
    StartTradeMenu(gActiveUnit, GetUnit(target->uid), 0);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

int sub_801F4D8(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_NOTSHOWN;

    if (!(UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_13))
        return MENU_NOTSHOWN;

    return sub_806B028(gActiveUnit->x, gActiveUnit->y) == LOCATION_COMMAND_0F
        ? MENU_ENABLED : MENU_NOTSHOWN;
}

u8 sub_801F524(struct MenuProc* menu, struct MenuEntProc* ent)
{
    gAction.id = ACTION_0F;
    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

int sub_801F534(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_NOTSHOWN;

    if (gMapTerrain[gActiveUnit->y][gActiveUnit->x] != TERRAIN_VILLAGE_03 && gMapTerrain[gActiveUnit->y][gActiveUnit->x] != TERRAIN_HOUSE)
        return MENU_NOTSHOWN;

    if (sub_806B028(gActiveUnit->x, gActiveUnit->y) != LOCATION_COMMAND_VISIT)
        return MENU_NOTSHOWN;

    if (gActiveUnit->status == UNIT_STATUS_SILENCED)
        return MENU_DISABLED;

    return MENU_ENABLED;
}

u8 sub_801F5A0(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (ent->availability == MENU_DISABLED)
    {
        MenuFrozenHelpBox(menu, 0xC30); // TODO: msg ids
        return MENU_ACT_SE_6B;
    }

    gAction.id = ACTION_0E;
    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

int sub_801F5C8(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_NOTSHOWN;

    if (!(UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_PLAY))
        return MENU_NOTSHOWN;

    ListRefreshTargets(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_NOTSHOWN;

    return MENU_ENABLED;
}

int sub_801F608(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_NOTSHOWN;

    if (!(UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_DANCE))
        return MENU_NOTSHOWN;

    ListRefreshTargets(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_NOTSHOWN;

    return MENU_ENABLED;
}

u8 sub_801F648(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (ent->availability == MENU_DISABLED)
        return MENU_ACT_SE_6B;

    ListRefreshTargets(gActiveUnit);
    StartMapSelect(&MapSelectInfo_085C76EC);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A;
}

u8 sub_801F674(struct MapSelectProc* proc, struct SelectTarget* target)
{
    gAction.id = ACTION_REFRESH;
    gAction.target = target->uid;

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

int sub_801F688(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_NOTSHOWN;

    if (gActiveUnit->items[0] == 0)
        return MENU_NOTSHOWN;

    return MENU_ENABLED;
}

u8 sub_801F6A8(struct MenuProc* menu, struct MenuEntProc* ent)
{
    ProcPtr proc;

    if (ent->availability != MENU_ENABLED)
        return 0;

    ClearIcons();
    ApplyIconPalettes(BGPAL_ICONS);

    ResetTextFont();

    proc = sub_8041834(&MenuInfo_085C7594);

    StartFace(0, GetUnitFid(gActiveUnit), 176, 12, FACE_DISP_KIND(FACE_96x80));
    StartEquipInfoWindow(proc, gActiveUnit, 15, 11);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

int sub_801F708(struct MenuProc* menu, struct MenuEntProc* ent)
{
    int item = gActiveUnit->items[ent->id];
    Bool isUseable;

    if (GetItemAttributes(item) & ITEM_ATTR_WEAPON)
    {
        sub_801F26C(menu, ent);
        return 0;
    }

    isUseable = CanUnitUseItem(gActiveUnit, item);

    sub_8016694(&ent->text, item, isUseable, gBg0Tm + TM_OFFSET(ent->x, ent->y));
    EnableBgSync(BG0_SYNC_BIT);
}

int sub_801F780(struct MenuEntInfo const* info, int id)
{
    int item = gActiveUnit->items[id];

    if (item == 0)
        return MENU_NOTSHOWN;

    if (GetItemAttributes(item) & ITEM_ATTR_WEAPON)
        sub_801F1DC(info, id); // BUG?

    return CanUnitUseItem(gActiveUnit, item)
        ? MENU_ENABLED : MENU_DISABLED;
}

u8 sub_801F7D0(struct MenuProc* menu, struct MenuEntProc* ent)
{
    struct MenuRect rect;

    gAction.itemSlot = ent->id;

    rect.x = ent->x + 9;
    rect.y = ent->y - 1;
    rect.w = 5;
    rect.h = 0;

    sub_801F854(rect.x, rect.y);
    sub_8041844(&MenuInfo_085C754C, rect, menu);

    return MENU_ACT_SE_6A;
}

int sub_801F840(struct MenuProc* menu, struct MenuEntProc* ent)
{
    UpdateEquipInfoWindow(ent->id);
}

int nullsub_8(struct MenuProc* menu, struct MenuEntProc* ent)
{
}

void sub_801F854(int x, int y)
{
    InitTextFont(&gFont_Unk_02002770, (u8*) VRAM + CHR_SIZE*0x200, 0x200, 0);

    TmCopyRect_t(gBg0Tm + TM_OFFSET(11, 1), gUnk_Tm_02003238, 9, 19);
    TmCopyRect_t(gBg1Tm + TM_OFFSET(11, 1), gUnk_Tm_02003738, 9, 19);
}

void sub_801F898(struct MenuProc* menu)
{
    SetTextFont(NULL);
}

u8 sub_801F8A4(struct MenuProc* menu)
{
    SetTextFont(NULL);

    TmCopyRect_t(gUnk_Tm_02003238, gBg0Tm + TM_OFFSET(11, 1), 9, 19);
    TmCopyRect_t(gUnk_Tm_02003738, gBg1Tm + TM_OFFSET(11, 1), 9, 19);

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6B;
}

u8 sub_801F8E0(struct MenuProc* menu)
{
    SetTextFont(NULL);
    ResetTextFont();

    sub_8041A38();

    return MENU_ACT_SKIPCURSOR | MENU_ACT_CLEAR | MENU_ACT_ENDFACE;
}

u8 sub_801F8F8(struct MenuProc* menu)
{
    ProcPtr proc;

    sub_801F8E0(menu);
    sub_801F8A4(menu);

    proc = sub_8041834(&MenuInfo_085C7594);

    StartFace(0, GetUnitFid(gActiveUnit), 176, 12, FACE_DISP_KIND(FACE_96x80));
    StartEquipInfoWindow(proc, gActiveUnit, 15, 11);

    return MENU_ACT_SKIPCURSOR;
}

u8 sub_801F948(struct MenuProc* menu)
{
    ProcPtr proc;

    sub_801F8E0(menu);

    if (GetUnitItemCount(gActiveUnit) == 0)
    {
        ClearBg0Bg1();
        EndFaceById(0);

        sub_8042018(&MenuInfo_UnitMenu, gBmSt.cursorSprTarget.x - gBmSt.camera.x, 1, 22);

        return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6B | MENU_ACT_CLEAR;
    }

    TmCopyRect_t(gUnk_Tm_02003238, gBg0Tm + TM_OFFSET(11, 1), 9, 19);
    TmCopyRect_t(gUnk_Tm_02003738, gBg1Tm + TM_OFFSET(11, 1), 9, 19);

    TmFillRect_t(gBg0Tm + TM_OFFSET(1, 1), 13, 12, 0);
    TmFillRect_t(gBg1Tm + TM_OFFSET(1, 1), 13, 12, 0);

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);

    proc = sub_8041834(&MenuInfo_085C7594);

    StartFace(0, GetUnitFid(gActiveUnit), 176, 12, FACE_DISP_KIND(FACE_96x80));
    StartEquipInfoWindow(proc, gActiveUnit, 15, 11);

    return MENU_ACT_SKIPCURSOR;
}

int sub_801FA14(struct MenuEntInfo const* info, int id)
{
    int item = gActiveUnit->items[gAction.itemSlot];

    if (GetItemEffect(item) == 0)
        return MENU_NOTSHOWN;

    if (GetItemKind(item) == ITEM_KIND_STAFF)
        return MENU_NOTSHOWN;

    if ((GetItemAttributes(item) & ITEM_ATTR_WEAPON) && !CanUnitUseWeapon(gActiveUnit, item))
        return MENU_NOTSHOWN;

    return CanUnitUseItem(gActiveUnit, item)
        ? MENU_ENABLED : MENU_DISABLED;
}

int sub_801FA84(struct MenuEntInfo const* info, int id)
{
    int item = gActiveUnit->items[gAction.itemSlot];

    if (!(GetItemAttributes(item) & ITEM_ATTR_WEAPON))
        return MENU_NOTSHOWN;

    return CanUnitUseWeapon(gActiveUnit, item)
        ? MENU_ENABLED : MENU_DISABLED;
}

int sub_801FACC(struct MenuEntInfo const* info, int id)
{
    int item = gActiveUnit->items[gAction.itemSlot];

    if (GetItemAttributes(item) & ITEM_ATTR_IMPORTANT)
        return MENU_DISABLED;

    return MENU_ENABLED;
}

u8 sub_801FB00(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (ent->availability == MENU_DISABLED)
    {
        MenuFrozenHelpBox(menu, GetUnitItemCantUseMsg(gActiveUnit, gActiveUnit->items[gAction.itemSlot]));
        return MENU_ACT_SE_6B;
    }

    gAction.id = ACTION_USEITEM;

    PlaySe(0x6A); // TODO: song ids
    return sub_801F8E0(menu);
}

u8 sub_801FB68(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (ent->availability == MENU_DISABLED)
    {
        MenuFrozenHelpBox(menu, 0xC31); // TODO: msg ids
        return MENU_ACT_SE_6B;
    }

    UnitEquipItemSlot(gActiveUnit, gAction.itemSlot);

    return sub_801F8F8(menu);
}

u8 sub_801FBA8(struct MenuProc* menu, struct MenuEntProc* ent)
{
    gBmSt.unk_3F = gAction.itemSlot;

    sub_801F8E0(menu);
    EndFaceById(0);

    sub_801F484(menu, ent);

    return MENU_ACT_SKIPCURSOR;
}

u8 sub_801FBDC(struct MenuProc* menu, struct MenuEntProc* ent)
{
    struct MenuRect rect;

    if (ent->availability == MENU_DISABLED)
    {
        MenuFrozenHelpBox(menu, 0xC33); // TODO: msg ids
        return MENU_ACT_SE_6B;
    }

    rect.x = ent->x + 3;
    rect.y = ent->y;
    rect.w = 5;
    rect.h = 0;

    sub_8041844(&MenuInfo_085C7528, rect, menu)->activeEntry = 1;

    return MENU_ACT_SE_6A | MENU_ACT_DOOM;
}

u8 sub_801FC50(struct MenuProc* menu, struct MenuEntProc* ent)
{
    UnitRemoveItem(gActiveUnit, gAction.itemSlot);

    sub_801F948(menu);
    return MENU_ACT_SKIPCURSOR;
}

int sub_801FC78(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_NOTSHOWN;

    if ((GetBallistaItemAt(gActiveUnit->x, gActiveUnit->y) & 0xFF00) != 0)
        return MENU_ENABLED;

    return MENU_DISABLED;
}

int sub_801FCB4(struct MenuProc* menu, struct MenuEntProc* ent)
{
    Bool isUseable = (ent->availability == MENU_ENABLED) ? TRUE : FALSE;
    int item = GetBallistaItemAt(gActiveUnit->x, gActiveUnit->y);

    sub_8016694(&ent->text, item, isUseable, gBg0Tm + TM_OFFSET(ent->x, ent->y));
}

u8 sub_801FD04(struct MenuProc* menu, struct MenuEntProc* ent)
{
    ClearBg0Bg1();

    gAction.itemSlot = ITEMSLOT_BALLISTA;

    sub_8021278(gActiveUnit);
    StartMapSelect(&MapSelectInfo_085C77EC);

    return MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_ENDFACE;
}

int sub_801FD30(struct MenuProc* menu, struct MenuEntProc* ent)
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

int sub_801FDB8(struct MenuEntInfo const* info, int id)
{
    int i, item;

    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_NOTSHOWN;

    for (i = 0; i < ITEMSLOT_INV_COUNT && (item = gActiveUnit->items[i]) != 0; ++i)
    {
        if (GetItemKind(item) == ITEM_KIND_STAFF && CanUnitUseItem(gActiveUnit, item))
        {
            if (gActiveUnit->status == UNIT_STATUS_SILENCED)
                return MENU_DISABLED;

            return MENU_ENABLED;
        }
    }

    return MENU_NOTSHOWN;
}

u8 sub_801FE30(struct MenuProc* menu, struct MenuEntProc* ent)
{
    ProcPtr proc;

    if (ent->availability == MENU_DISABLED)
    {
        MenuFrozenHelpBox(menu, 0xC34); // TODO: msg ids
        return MENU_ACT_SE_6B;
    }

    ClearIcons();
    ApplyIconPalettes(BGPAL_ICONS);

    proc = sub_8041834(&MenuInfo_085C7570);

    StartFace(0, GetUnitFid(gActiveUnit), 176, 12, FACE_DISP_KIND(FACE_96x80));
    StartEquipInfoWindow(proc, gActiveUnit, 15, 11);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

int sub_801FE94(struct MenuProc* menu, struct MenuEntProc* ent)
{
    int reach = GetUnitItemUseReach(gActiveUnit, -1);

    MapFill(gMapMovement, -1);
    MapFill(gMapRange, 0);

    BuildUnitStandingRangeForReach(gActiveUnit, reach);
    StartLimitView(LIMITVIEW_BLUE | LIMITVIEW_GREEN);

    return 0;
}

int sub_801FEDC(struct MenuProc* menu, struct MenuEntProc* ent)
{
    EndLimitView();
    return 0;
}

int sub_801FEE8(struct MenuEntInfo const* info, int id)
{
    int item = gActiveUnit->items[id];

    if (GetItemKind(item) != ITEM_KIND_STAFF)
        return MENU_NOTSHOWN;

    if (!CanUnitUseItem(gActiveUnit, item))
        return MENU_NOTSHOWN;

    return MENU_ENABLED;
}

u8 sub_801FF20(struct MenuProc* menu, struct MenuEntProc* ent)
{
    UnitEquipItemSlot(gActiveUnit, ent->id);
    gAction.itemSlot = ITEMSLOT_INV0;

    ClearBg0Bg1();

    DoUseUnitItem(gActiveUnit, gActiveUnit->items[gAction.itemSlot]);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A;
}

int sub_801FF60(struct MenuProc* menu, struct MenuEntProc* ent)
{
    return sub_801F708(menu, ent);
}

int sub_801FF6C(struct MenuProc* menu, struct MenuEntProc* ent)
{
    int reach = GetUnitItemUseReach(gActiveUnit, ent->id);

    UpdateEquipInfoWindow(ent->id);

    MapFill(gMapMovement, -1);
    MapFill(gMapRange, 0);

    BuildUnitStandingRangeForReach(gActiveUnit, reach);
    StartLimitView(LIMITVIEW_GREEN);

    return 0;
}

int sub_801FFC0(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (!(menu->flags & MENU_FLAG_2))
        EndLimitView();

    return 0;
}

int sub_801FFD8(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_NOTSHOWN;

    ListTalkTargets(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_NOTSHOWN;

    if (gActiveUnit->status == UNIT_STATUS_SILENCED)
        return MENU_DISABLED;

    return MENU_ENABLED;
}

u8 sub_802001C(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (ent->availability == MENU_DISABLED)
    {
        MenuFrozenHelpBox(menu, 0xC35); // TODO: msg ids
        return MENU_ACT_SE_6B;
    }

    ListTalkTargets(gActiveUnit);
    StartMapSelect(&MapSelectInfo_085C778C);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A;
}

u8 sub_8020050(struct MapSelectProc* proc, struct SelectTarget* target)
{
    gAction.id = ACTION_TALK;
    gAction.target = target->uid;

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

int sub_8020064(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_NOTSHOWN;

    ListSupportTargets(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_NOTSHOWN;

    ListTalkTargets(gActiveUnit);

    if (CountTargets() != 0)
        return MENU_NOTSHOWN;

    if (gActiveUnit->status == UNIT_STATUS_SILENCED)
        return MENU_DISABLED;

    return MENU_ENABLED;
}

u8 sub_80200B4(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (ent->availability == MENU_DISABLED)
    {
        MenuFrozenHelpBox(menu, 0xC35); // TODO: msg ids
        return MENU_ACT_SE_6B;
    }

    ListSupportTargets(gActiveUnit);
    StartMapSelect(&MapSelectInfo_085C776C);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A;
}

u8 sub_80200E8(struct MapSelectProc* proc, struct SelectTarget* target)
{
    gAction.id = ACTION_SUPPORT;
    gAction.target = target->uid;

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

int sub_80200FC(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_NOTSHOWN;

    if (GetUnitKeyItemSlotForTerrain(gActiveUnit, TERRAIN_DOOR) < 0)
        return MENU_NOTSHOWN;

    ListOpenTerrainTargets(gActiveUnit, TERRAIN_DOOR);

    return (CountTargets() == 0)
        ? MENU_NOTSHOWN : MENU_ENABLED;
}

u8 sub_802013C(struct MenuProc* menu, struct MenuEntProc* ent)
{
    gAction.id = ACTION_DOOR;
    gAction.instigator = gActiveUnit->id;
    gAction.itemSlot = GetUnitKeyItemSlotForTerrain(gActiveUnit, TERRAIN_DOOR);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

int sub_8020164(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_NOTSHOWN;

    if (GetUnitKeyItemSlotForTerrain(gActiveUnit, TERRAIN_CHEST_21) < 0)
        return MENU_NOTSHOWN;

    return CanUnitUseChestKeyItem(gActiveUnit)
        ? MENU_ENABLED : MENU_NOTSHOWN;
}

u8 sub_80201A0(struct MenuProc* menu, struct MenuEntProc* ent)
{
    gAction.id = ACTION_CHEST;
    gAction.itemSlot = GetUnitKeyItemSlotForTerrain(gActiveUnit, TERRAIN_CHEST_21);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

int sub_80201C4(struct MenuEntInfo const* info, int id)
{
    struct Unit* merlinus;

    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_NOTSHOWN;

    if (gBmSt.partialActionsTaken & PARTIAL_ACTION_SUPPLY)
        return MENU_NOTSHOWN;

    if (GetUnitItemCount(gActiveUnit) == 0 && CountSupplyItems() == 0)
        return MENU_NOTSHOWN;

    if (UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_SUPPLY)
        return MENU_ENABLED;

    merlinus = GetUnitByPid(PID_MERLINUS);

    if (merlinus == NULL)
        return MENU_NOTSHOWN;

    if (merlinus->state & US_HIDDEN)
        return MENU_NOTSHOWN;

    if (RECT_DISTANCE(gActiveUnit->x, gActiveUnit->y, merlinus->x, merlinus->y) == 1)
        return MENU_ENABLED;

    return MENU_NOTSHOWN;
}

u8 sub_8020268(struct MenuProc* menu, struct MenuEntProc* ent)
{
    gAction.id = ACTION_TRADED_NOCHANGES;

    sub_80815E4(gActiveUnit, NULL);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

int sub_8020288(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_NOTSHOWN;

    return sub_806B028(gActiveUnit->x, gActiveUnit->y) == LOCATION_COMMAND_13
        ? MENU_ENABLED : MENU_NOTSHOWN;
}

u8 sub_80202C4(struct MenuProc* menu, struct MenuEntProc* ent)
{
    sub_806B06C(gActiveUnit->x, gActiveUnit->y);
    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

int sub_80202E4(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_NOTSHOWN;

    return sub_806B028(gActiveUnit->x, gActiveUnit->y) == LOCATION_COMMAND_14
        ? MENU_ENABLED : MENU_NOTSHOWN;
}

u8 sub_8020320(struct MenuProc* menu, struct MenuEntProc* ent)
{
    sub_806B06C(gActiveUnit->x, gActiveUnit->y);
    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

int sub_8020340(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_NOTSHOWN;

    return sub_806B028(gActiveUnit->x, gActiveUnit->y) == LOCATION_COMMAND_15
        ? MENU_ENABLED : MENU_NOTSHOWN;
}

u8 sub_802037C(struct MenuProc* menu, struct MenuEntProc* ent)
{
    sub_806B06C(gActiveUnit->x, gActiveUnit->y);
    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

int sub_802039C(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_NOTSHOWN;

    if (gMapTerrain[gActiveUnit->y][gActiveUnit->x] != TERRAIN_ARENA_08)
        return MENU_NOTSHOWN;

    return ArenaIsUnitAllowed(gActiveUnit)
        ? MENU_ENABLED : MENU_DISABLED;
}

u8 sub_80203EC(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (ent->availability == MENU_DISABLED)
    {
        if (gActiveUnit->status == UNIT_STATUS_SILENCED)
            MenuFrozenHelpBox(menu, 0xC36); // TODO: msg ids
        else
            MenuFrozenHelpBox(menu, 0xC37); // TODO: msg ids

        return MENU_ACT_SE_6B;
    }

    sub_8097E84();
    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

int sub_8020438(struct MenuEntInfo const* info, int id)
{
    if (!(UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_STEAL))
        return MENU_NOTSHOWN;

    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_NOTSHOWN;

    ListStealTargets(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_NOTSHOWN;

    if (GetUnitItemCount(gActiveUnit) == ITEMSLOT_INV_COUNT)
        return MENU_DISABLED;

    return MENU_ENABLED;
}

u8 sub_8020488(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (ent->availability == MENU_DISABLED)
    {
        MenuFrozenHelpBox(menu, 0xC44); // TODO: msg ids
        return MENU_ACT_SE_6B;
    }

    ClearBg0Bg1();

    ListStealTargets(gActiveUnit);
    StartMapSelect(&MapSelectInfo_Steal);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A;
}

void sub_80204C0(struct MapSelectProc* proc)
{
    StartUnitInventoryPanel(proc);
    StartSubtitleHelp(proc, DecodeMsg(0xC20)); // TODO: msg ids
}

int sub_80204E0(struct MapSelectProc* proc, struct SelectTarget* target)
{
    sub_801D680(target->x, target->y);
    RefreshUnitStealInventoryPanel(GetUnit(target->uid));
}

int sub_8020504(struct MapSelectProc* proc, struct SelectTarget* target)
{
    int x;

    gAction.target = target->uid;

    ClearIcons();
    ApplyIconPalettes(BGPAL_ICONS);

    sub_8041834(&MenuInfo_085C74BC);

    EndMapSelect(proc);

    TmApplyTsa_t(gBg1Tm + TM_OFFSET(2, 2), Tsa_Unk_081022FC, TILEREF(BGCHR_WINDOW_FRAME, BGPAL_1));

    x = (56 - GetStringTextLen(DecodeMsg(GetUnit(gAction.target)->person->msgName))) / 2;
    PutDrawText(NULL, gBg0Tm + TM_OFFSET(3, 3), TEXT_COLOR_SYSTEM_WHITE, x, 7,
        DecodeMsg(GetUnit(gAction.target)->person->msgName));

    PutFace80x72(gBg0Tm + TM_OFFSET(3, 5), GetUnitFid(GetUnit(gAction.target)),
        BGCHR_STEALSELECT_FACE, BGPAL_STEALSELECT_FACE);

    return 0;
}

int sub_80205A8(struct MenuEntInfo const* info, int id)
{
    if (GetUnit(gAction.target)->items[id] == 0)
        return MENU_NOTSHOWN;

    if (!IsItemStealable(GetUnit(gAction.target)->items[id]))
        return MENU_DISABLED;

    return MENU_ENABLED;
}

int sub_80205EC(struct MenuProc* menu, struct MenuEntProc* ent)
{
    int item = GetUnit(gAction.target)->items[ent->id];
    Bool isUseable = IsItemStealable(item);

    sub_8016694(&ent->text, item, isUseable, gBg0Tm + TM_OFFSET(ent->x, ent->y));
}

u8 sub_8020640(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (ent->availability == MENU_DISABLED)
    {
        MenuFrozenHelpBox(menu, 0xC38); // TODO: msg ids
        return MENU_ACT_SE_6B;
    }

    gAction.itemSlot = ent->id;
    gAction.id = ACTION_STEAL;

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

int sub_8020678(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (ent->id >= ITEMSLOT_INV_COUNT)
    {
        sub_80706FC(ent->x*8, ent->y*8, gBmSt.inventoryItemOverflow);
        return 0;
    }

    sub_80706FC(ent->x*8, ent->y*8, gActiveUnit->items[ent->id]);
}

int sub_80206D0(struct MenuProc* menu, struct MenuEntProc* ent)
{
    struct Unit* unit = GetUnit(gAction.target);
    sub_80706FC(ent->x*8, ent->y*8, unit->items[ent->id]);
}

int sub_8020708(struct MenuProc* menu, struct MenuEntProc* ent)
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

    sub_80706FC(ent->x*8, ent->y*8, iid);
}

void sub_8020764(struct MapSelectProc* proc)
{
    StartUnitHpPanel(proc);
}

int sub_8020770(struct MapSelectProc* proc, struct SelectTarget* target)
{
    sub_801D680(target->x, target->y);
    RefreshUnitHpPanel(GetUnit(target->uid));
}

void sub_8020794(struct MapSelectProc* proc)
{
    RefreshUnitTakeRescuePanels(proc);
    StartSubtitleHelp(proc, DecodeMsg(0xC1B)); // TODO: msg ids
}

int sub_80207B4(struct MapSelectProc* proc, struct SelectTarget* target)
{
    sub_801D680(target->x, target->y);
    RefreshUnitRescuePanels(GetUnit(target->uid));
}

void sub_80207D8(struct MapSelectProc* proc)
{
    StartSubtitleHelp(proc, DecodeMsg(0xC1C)); // TODO: msg ids
}

int sub_80207F4(struct MapSelectProc* proc, struct SelectTarget* target)
{
}

void sub_80207F8(struct MapSelectProc* proc)
{
    StartUnitGiveRescuePanels(proc);
    StartSubtitleHelp(proc, DecodeMsg(0xC1E)); // TODO: msg ids
}

int sub_8020818(struct MapSelectProc* proc, struct SelectTarget* target)
{
    sub_801D680(target->x, target->y);
    RefreshUnitGivePanels(GetUnit(target->uid));
}

void sub_802083C(struct MapSelectProc* proc)
{
    RefreshUnitTakeRescuePanels(proc);
    StartSubtitleHelp(proc, DecodeMsg(0xC1D)); // TODO: msg ids
}

int sub_802085C(struct MapSelectProc* proc, struct SelectTarget* target)
{
    sub_801D680(target->x, target->y);
    RefreshUnitTakePanels(GetUnit(target->uid));
}

void sub_8020880(struct MapSelectProc* proc)
{
    StartUnitInventoryPanel(proc);
    StartSubtitleHelp(proc, DecodeMsg(0xC1F)); // TODO: msg ids
}

int sub_80208A0(struct MapSelectProc* proc, struct SelectTarget* target)
{
    sub_801D680(target->x, target->y);
    RefreshUnitInventoryPanel(GetUnit(target->uid));
}

void sub_80208C4(struct MapSelectProc* proc)
{
    StartUnitHpPanel(proc);
    StartSubtitleHelp(proc, DecodeMsg(0xC22)); // TODO: msg ids
}

int sub_80208E4(struct MapSelectProc* proc, struct SelectTarget* target)
{
    sub_801D680(target->x, target->y);
    RefreshUnitHpPanel(GetUnit(target->uid));
}

void sub_8020908(struct MapSelectProc* proc)
{
    StartUnitHpPanel(proc);
    StartSubtitleHelp(proc, DecodeMsg(0xC23)); // TODO: msg ids
}

int sub_8020928(struct MapSelectProc* proc, struct SelectTarget* target)
{
    sub_801D680(target->x, target->y);
    RefreshUnitHpPanel(GetUnit(target->uid));
}

void sub_802094C(struct MapSelectProc* proc)
{
    StartUnitHpPanel(proc);
}

int sub_8020958(struct MapSelectProc* proc, struct SelectTarget* target)
{
    sub_801D680(target->x, target->y);
    RefreshUnitHpPanel(GetUnit(target->uid));
}
