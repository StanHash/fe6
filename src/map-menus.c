
#include "common.h"

#include "hardware.h"
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
#include "menu.h"

#include "constants/video-global.h"

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

static void sub_801EB94(ProcPtr proc);
static void sub_801EBF8(ProcPtr proc);

struct ProcScr CONST_DATA ProcScr_BackToUnitMenu[] =
{
    PROC_CALL(LockGame),

    PROC_CALL(sub_801EB94),
    PROC_WHILE_EXISTS(ProcScr_CamMove),

    PROC_CALL(sub_801EBF8),

    PROC_CALL(UnlockGame),

    PROC_END,
};

static void sub_801F35C(ProcPtr proc);
static void sub_801F378(ProcPtr proc);

struct ProcScr CONST_DATA ProcScr_Unk_085C5E58[] =
{
    PROC_CALL(LockGame),

    PROC_CALL(sub_801F35C),

    PROC_WHILE_EXISTS(ProcScr_Unk_085C83C8),
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
        sub_8041FA4(menu, 0xC46); // TODO: msgids
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

u8 sub_801EB38(struct MenuProc* menu, struct MenuEntProc* ent)
{
    sub_80422DC(menu);

    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);

    ResetTextFont();

    EndLimitView();

    CameraMoveWatchPosition(
        sub_8042018(&MenuInfo_UnitMenu, gBmSt.cursorSprTarget.x - gBmSt.camera.x, 1, 22),
        gActiveUnit->x, gActiveUnit->y);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_SE_6B | MENU_ACT_CLEAR;
}

static void sub_801EB94(ProcPtr proc)
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

static void sub_801EBF8(ProcPtr proc)
{
    sub_8042018(&MenuInfo_UnitMenu, gBmSt.cursorSprTarget.x - gBmSt.camera.x, 1, 22);
}

u8 sub_801EC1C(struct MenuProc* menu, struct MenuEntProc* ent)
{
    sub_80422DC(menu);

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

    sub_8020F30(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_NOTSHOWN;

    return MENU_ENABLED;
}

u8 sub_801ECCC(struct MenuProc* menu, struct MenuEntProc* ent)
{
    sub_8020F30(gActiveUnit);
    sub_8042264(&MapSelectInfo_085C786C);

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

    sub_8020FBC(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_NOTSHOWN;

    return MENU_ENABLED;
}

u8 sub_801ED38(struct MenuProc* menu, struct MenuEntProc* ent)
{
    sub_8020FBC(gActiveUnit);
    sub_8042264(&MapSelectInfo_085C784C);

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

    sub_8021048(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_NOTSHOWN;

    return MENU_ENABLED;
}

u8 sub_801EDC4(struct MenuProc* menu, struct MenuEntProc* ent)
{
    sub_8021048(gActiveUnit);
    sub_8042264(&MapSelectInfo_085C782C);

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

    sub_80210E8(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_NOTSHOWN;

    return MENU_ENABLED;
}

u8 sub_801EE2C(struct MenuProc* menu, struct MenuEntProc* ent)
{
    sub_80210E8(gActiveUnit);
    sub_8042264(&MapSelectInfo_085C780C);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A;
}

void sub_801EE4C(struct Unit* from, struct Unit* to)
{
    struct Unit* rescue = GetUnit(from->rescue);

    sub_802CB50();
    StartRescueTransferAnimParentless(rescue, sub_801C160(to->x, to->y, from->x, from->y));
}

u8 sub_801EE80(struct MapSelectProc* proc, struct SelectTarget* target)
{
    gAction.id = ACTION_TAKE;
    gAction.target = target->uid;

    UnitSyncMovement(GetUnit(gAction.target));

    sub_801EE4C(GetUnit(gAction.target), GetUnit(gAction.actor));
    UnitGiveRescue(GetUnit(gAction.target), GetUnit(gAction.actor));

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

u8 sub_801EED0(struct MapSelectProc* proc, struct SelectTarget* target)
{
    gAction.id = ACTION_GIVE;
    gAction.target = target->uid;

    UnitSyncMovement(GetUnit(gAction.actor));

    sub_801EE4C(GetUnit(gAction.actor), GetUnit(gAction.target));
    UnitGiveRescue(GetUnit(gAction.actor), GetUnit(gAction.target));

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

int sub_801EF20(struct MenuEntInfo const* info, int id)
{
    int i, item;

    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_NOTSHOWN;

    gBmSt.unk_30 = FALSE;
    gBmSt.unk_31 = FALSE;

    for (i = 0; i < UNIT_ITEM_COUNT && (item = gActiveUnit->items[i]) != 0; ++i)
    {
        if (!(GetItemAttributes(item) & ITEM_ATTR_WEAPON))
            continue;

        if (!CanUnitUseWeapon(gActiveUnit, item))
            continue;

        sub_8020D7C(gActiveUnit, item);

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

            if (sub_8026DC8(gActiveUnit->x, gActiveUnit->y) == 0)
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
        sub_8041FA4(menu, 0xC3B); // TODO: msg ids
        return MENU_ACT_SE_6B;
    }

    ClearIcons();
    ApplyIconPalettes(BGPAL_ICONS);

    if (gBmSt.unk_30 == TRUE && gBmSt.unk_31 == TRUE)
    {
        sub_802CB14(
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
        int item = sub_8026D20(gActiveUnit->x, gActiveUnit->y);

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

    sub_8020D7C(gActiveUnit, item);

    if (CountTargets() == 0)
        return MENU_NOTSHOWN;

    return MENU_ENABLED;
}

u8 sub_801F228(struct MenuProc* menu, struct MenuEntProc* ent)
{
    UnitEquipItemSlot(gActiveUnit, ent->id);
    gAction.itemSlot = 0;

    ClearBg0Bg1();

    sub_8020D7C(gActiveUnit, gActiveUnit->items[0]);

    sub_8042264(&MapSelectInfo_085C77EC);

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
        gAction.unk_15 = target->extra;
    }

    Proc_EndEach(ProcScr_Unk_085C83C8);

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
        gAction.unk_15 = target->extra;

        sub_8025B88();
    }

    if (gAction.itemSlot == 8)
        sub_8024294(gActiveUnit, unit, gActiveUnit->x, gActiveUnit->y);
    else
        sub_8024248(gActiveUnit, unit, -1, -1, gAction.itemSlot);

    sub_802E36C();

    return 0;
}

u8 sub_801F420(struct MapSelectProc* proc)
{
    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);

    EndLimitView();
    sub_802E394();

    return 0;
}

int sub_801F444(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_NOTSHOWN;

    if (gBmSt.partialActionsTaken & PARTIAL_ACTION_TRADED)
        return MENU_NOTSHOWN;

    sub_8020E5C(gActiveUnit);

    if (CountTargets() == 0)
        return MENU_NOTSHOWN;

    return MENU_ENABLED;
}

u8 sub_801F484(struct MenuProc* menu, struct MenuEntProc* ent)
{
    ClearBg0Bg1();

    sub_8020E5C(gActiveUnit);
    sub_8042264(&MapSelectInfo_085C77CC);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A;
}

u8 sub_801F4A8(struct MapSelectProc* proc, struct SelectTarget* target)
{
    gAction.id = ACTION_TRADED_NOCHANGES;
    sub_8026A8C(gActiveUnit, GetUnit(target->uid), 0);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

int sub_801F4D8(struct MenuEntInfo const* info, int id)
{
    if (gActiveUnit->state & US_HAS_MOVED)
        return MENU_NOTSHOWN;

    if (!(UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_13))
        return MENU_NOTSHOWN;

    return (sub_806B028(gActiveUnit->x, gActiveUnit->y) == 15) // TODO: location event constants
        ? MENU_ENABLED : MENU_NOTSHOWN;
}
