
#include "item-use.h"
#include "common.h"

#include "hardware.h"
#include "oam.h"
#include "sound.h"
#include "face.h"
#include "anim.h"
#include "msg.h"
#include "item.h"
#include "unit.h"
#include "map.h"
#include "player-phase.h"
#include "bmfx.h"
#include "target-list.h"
#include "map-select.h"

#include "constants/items.h"
#include "constants/terrains.h"

// TODO: map-menu.h
extern struct ProcScr CONST_DATA ProcScr_BackToUnitMenu[];

extern struct Unit gStatGainSimUnit;

static Bool HasSelectTarget(struct Unit* unit, void(*listTargets)(struct Unit* unit));

static void SetStaffUseAction(struct Unit* unit);
static void SetItemUseAction(struct Unit* unit);

static void WarpSelect_Init(struct GenericProc* proc);
static void WarpSelect_Loop(struct GenericProc* proc);
static void WarpSelect_HandleConfirm(struct GenericProc* proc);
static void WarpSelect_HandleCancel(struct GenericProc* proc);
static void WarpSelect_End(struct GenericProc* proc);

struct ProcScr CONST_DATA ProcScr_SquareSelectWarp[] =
{
    PROC_ONEND(WarpSelect_End),

    PROC_CALL(LockGame),

    PROC_WHILE_EXISTS(ProcScr_CamMove),

    PROC_CALL(WarpSelect_Init),
    PROC_WHILE_EXISTS(ProcScr_CamMove),

    PROC_REPEAT(WarpSelect_Loop),

    PROC_CALL(WarpSelect_HandleConfirm),
    PROC_SLEEP(0),

    PROC_CALL(UnlockGame),

    PROC_GOTO(100),

PROC_LABEL(99),
    PROC_CALL(WarpSelect_HandleCancel),
    PROC_SLEEP(0),

    PROC_CALL(UnlockGame),

PROC_LABEL(100),
    PROC_END,
};

Bool CanUnitUseItem(struct Unit* unit, int item)
{
    if ((GetItemAttributes(item) & ITEM_ATTR_STAFF) && !CanUnitUseStaff(unit, item))
        return FALSE;

    switch (GetItemIid(item))
    {

    case IID_HEALSTAFF:
    case IID_MENDSTAFF:
    case IID_RECOVERSTAFF:
    case IID_TINASTAFF:
        return HasSelectTarget(unit, ListAdjacentHealTargets);

    case IID_PHYSICSTAFF:
        return HasSelectTarget(unit, ListRangedHealTargets);

    case IID_FORTIFYSTAFF:
        return HasSelectTarget(unit, ListRangedHealTargets);

    case IID_RESTORESTAFF:
        return HasSelectTarget(unit, ListRestoreTargets);

    case IID_RESCUESTAFF:
        return HasSelectTarget(unit, ListRescueStaffTargets);

    case IID_BARRIERSTAFF:
        return HasSelectTarget(unit, ListBarrierTargets);

    case IID_SILENCESTAFF:
        return HasSelectTarget(unit, ListSilenceTargets);

    case IID_SLEEPSTAFF:
        return HasSelectTarget(unit, ListSleepTargets);

    case IID_BERSERKSTAFF:
        return HasSelectTarget(unit, ListBerserkTargets);

    case IID_WARPSTAFF:
        return HasSelectTarget(unit, ListWarpTargets);

    case IID_REPAIRSTAFF:
        return HasSelectTarget(unit, ListRepairTargets);

    case IID_UNLOCKSTAFF:
        return HasSelectTarget(unit, ListUnlockTargets);

    case IID_SKILLBOOSTER:
    case IID_LUCKBOOSTER:
    case IID_HPBOOSTER:
    case IID_DEFBOOSTER:
    case IID_POWBOOSTER:
    case IID_SPEEDBOOSTER:
    case IID_RESBOOSTER:
    case IID_MOVBOOSTER:
    case IID_CONBOOSTER:
        return CanUnitUseStatGainItem(unit, item);

    case IID_HEROCREST:
    case IID_KNIGHTCREST:
    case IID_ORIONBOLT:
    case IID_ELYSIANWHIP:
    case IID_GUIDINGRING:
        return CanUnitUsePromotionItem(unit, item);

    case IID_BINDINGBLADE:
        return CanUnitUseBindingBladeToHeal(unit);

    case IID_VULNERARY:
    case IID_ELIXIR:
        return CanUnitUseHealItem(unit);

    case IID_PUREWATER:
        return CanUnitUsePureWaterItem(unit);

    case IID_TORCH:
    case IID_TORCHSTAFF:
        return CanUnitUseTorchItem(unit);

    case IID_ANTITOXIN:
        return CanUnitUseAntitoxinItem(unit);

    case IID_CHESTKEY:
        return CanUnitUseChestKeyItem(unit);

    case IID_DOORKEY:
        return CanUnitUseDoorKeyItem(unit);

    case IID_BRIDGEKEY:
        return CanUnitUseBridgeKeyItem(unit);

    case IID_LOCKPICK:
        return CanUnitUseLockpickItem(unit);

    case IID_SAINTSTAFF:
        return HasSelectTarget(unit, ListSaintsStaffTargets);

    default:
        return FALSE;

    }
}

int GetUnitItemCantUseMsg(struct Unit* unit, int item)
{
    switch (GetItemIid(item))
    {

    case IID_BINDINGBLADE:
    case IID_TORCHSTAFF:
    case IID_SKILLBOOSTER:
    case IID_LUCKBOOSTER:
    case IID_HPBOOSTER:
    case IID_DEFBOOSTER:
    case IID_POWBOOSTER:
    case IID_SPEEDBOOSTER:
    case IID_RESBOOSTER:
    case IID_MOVBOOSTER:
    case IID_CONBOOSTER:
    case IID_VULNERARY:
    case IID_ELIXIR:
    case IID_PUREWATER:
    case IID_TORCH:
    case IID_ANTITOXIN:
        return 0xC3C; // TODO: msg ids

    case IID_CHESTKEY:
        return 0xC40; // TODO: msg ids

    case IID_DOORKEY:
    case IID_BRIDGEKEY:
        return 0xC3F; // TODO: msg ids

    case IID_LOCKPICK:
        if (UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_STEAL)
            return 0xC43; // TODO: msg ids

        return 0xC41; // TODO: msg ids

    case IID_HEROCREST:
    case IID_KNIGHTCREST:
    case IID_ORIONBOLT:
    case IID_ELYSIANWHIP:
    case IID_GUIDINGRING:
    {
        Bool boolval;

        int level = gActiveUnit->level;

        gActiveUnit->level = 10;
        boolval = CanUnitUsePromotionItem(gActiveUnit, item);
        gActiveUnit->level = level;

        if (boolval)
            return 0xC3E; // TODO: msg ids

        return 0xC3D; // TODO: msg ids
    }

    default:
        return 0xC3D; // TODO: msg ids

    }
}

void DoUseUnitItem(struct Unit* unit, int item)
{
    ClearBg0Bg1();
    EndFaceById(0);

    switch (GetItemIid(item))
    {

    case IID_HEALSTAFF:
    case IID_MENDSTAFF:
    case IID_RECOVERSTAFF:
    case IID_TINASTAFF:
        DoUseHealStaff(unit, ListAdjacentHealTargets);
        break;

    case IID_PHYSICSTAFF:
        DoUseHealStaff(unit, ListRangedHealTargets);
        break;

    case IID_RESCUESTAFF:
        DoUseRescueStaff(unit, ListRescueStaffTargets);
        break;

    case IID_RESTORESTAFF:
        DoUseRestoreStaff(unit, ListRestoreTargets);
        break;

    case IID_SILENCESTAFF:
        DoUseAttackStaff(unit, ListSilenceTargets);
        break;

    case IID_SLEEPSTAFF:
        DoUseAttackStaff(unit, ListSleepTargets);
        break;

    case IID_BERSERKSTAFF:
        DoUseAttackStaff(unit, ListBerserkTargets);
        break;

    case IID_BARRIERSTAFF:
        DoUseBarrierStaff(unit);
        break;

    case IID_UNLOCKSTAFF:
        DoUseUnlockStaff(unit, ListUnlockTargets);
        break;

    case IID_WARPSTAFF:
        DoUseWarpStaff(unit);
        break;

    case IID_REPAIRSTAFF:
        DoUseRepairStaff(unit);
        break;

    case IID_FORTIFYSTAFF:
    case IID_TORCHSTAFF:
    case IID_SAINTSTAFF:
        SetStaffUseAction(unit);
        break;

    default:
        SetItemUseAction(unit);
        break;

    }
}

static Bool HasSelectTarget(struct Unit* unit, void(*listTargets)(struct Unit*))
{
    listTargets(unit);
    return CountTargets() != 0;
}

Bool CanUnitUseHealItem(struct Unit* unit)
{
    if (GetUnitCurrentHp(unit) == GetUnitMaxHp(unit))
        return FALSE;

    return TRUE;
}

Bool CanUnitUseBindingBladeToHeal(struct Unit* unit)
{
    if (!CanUnitUseWeapon(unit, IID_BINDINGBLADE))
        return FALSE;

    return CanUnitUseHealItem(unit);
}

Bool CanUnitUsePureWaterItem(struct Unit* unit)
{
    if (unit->barrier == 7)
        return FALSE;

    return TRUE;
}

Bool CanUnitUseTorchItem(struct Unit* unit)
{
    if (gPlaySt.vision != 0 && unit->torch != 4)
        return TRUE;

    return FALSE;
}

Bool CanUnitUseAntitoxinItem(struct Unit* unit)
{
    if (unit->status != UNIT_STATUS_POISON)
        return FALSE;

    return TRUE;
}

Bool CanUnitUseChestKeyItem(struct Unit* unit)
{
    if (gMapTerrain[unit->y][unit->x] != TERRAIN_CHEST_21)
        return FALSE;

    if (!IsThereClosedChestAt(unit->x, unit->y))
        return FALSE;

    return TRUE;
}

Bool CanUnitUseDoorKeyItem(struct Unit* unit)
{
    ListOpenTerrainTargets(unit, TERRAIN_DOOR);
    return CountTargets();
}

Bool CanUnitUseBridgeKeyItem(struct Unit* unit)
{
    ListOpenTerrainTargets(unit, TERRAIN_BRIDGE_14);
    return CountTargets();
}

Bool CanUnitUseLockpickItem(struct Unit* unit)
{
    if (!(UNIT_ATTRIBUTES(unit) & UNIT_ATTR_STEAL))
        return FALSE;

    if (!CanUnitUseChestKeyItem(unit) && !CanUnitUseDoorKeyItem(unit) && !CanUnitUseBridgeKeyItem(unit))
        return FALSE;

    return TRUE;
}

Bool CanUnitUsePromotionItem(struct Unit* unit, int item)
{
    u8 const* jlist = NULL;

    if (unit->level < 10)
        return FALSE;

    switch (GetItemIid(item))
    {

    case IID_HEROCREST:
        jlist = JList_HeroCrestPromotes;
        break;

    case IID_KNIGHTCREST:
        jlist = JList_KnightCrestPromotes;
        break;

    case IID_ORIONBOLT:
        jlist = JList_OrionBoltPromotes;
        break;

    case IID_ELYSIANWHIP:
        jlist = JList_ElysianWhipPromotes;
        break;

    case IID_GUIDINGRING:
        jlist = JList_GuidingRingPromotes;
        break;

    }

    while (*jlist)
    {
        if (unit->job->id == *jlist)
            return TRUE;

        jlist++;
    }

    return FALSE;
}

Bool CanUnitUseStatGainItem(struct Unit* unit, int item)
{
    Bool result;

    struct ItemBonuses const* bonuses = GetItemBonuses(item);

    ClearUnit(&gStatGainSimUnit);

    gStatGainSimUnit.person = unit->person;
    gStatGainSimUnit.job = unit->job;

    gStatGainSimUnit.hpMax = unit->hpMax + bonuses->hp;
    gStatGainSimUnit.pow = unit->pow + bonuses->pow;
    gStatGainSimUnit.skl = unit->skl + bonuses->skl;
    gStatGainSimUnit.spd = unit->spd + bonuses->spd;
    gStatGainSimUnit.def = unit->def + bonuses->def;
    gStatGainSimUnit.res = unit->res + bonuses->res;
    gStatGainSimUnit.lck = unit->lck + bonuses->lck;
    gStatGainSimUnit.movBonus = unit->movBonus + bonuses->mov;
    gStatGainSimUnit.conBonus = unit->conBonus + bonuses->con;

    UnitCheckStatOverflow(&gStatGainSimUnit);

    result = gStatGainSimUnit.hpMax != unit->hpMax;

    if (gStatGainSimUnit.pow != unit->pow)
        result = TRUE;

    if (gStatGainSimUnit.skl != unit->skl)
        result = TRUE;

    if (gStatGainSimUnit.spd != unit->spd)
        result = TRUE;

    if (gStatGainSimUnit.def != unit->def)
        result = TRUE;

    if (gStatGainSimUnit.res != unit->res)
        result = TRUE;

    if (gStatGainSimUnit.lck != unit->lck)
        result = TRUE;

    if (gStatGainSimUnit.movBonus != unit->movBonus)
        result = TRUE;

    if (gStatGainSimUnit.conBonus != unit->conBonus)
        result = TRUE;

    return result;
}

static void SetStaffUseAction(struct Unit* unit)
{
    EndLimitView();

    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);

    gAction.id = ACTION_STAFF;
}

static void SetItemUseAction(struct Unit* unit)
{
    gAction.id = ACTION_USEITEM;
}

int StaffSelectOnSelect(struct MapSelectProc* proc, struct SelectTarget* target)
{
    gAction.target = target->uid;
    SetStaffUseAction(NULL);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

void DoUseRescueStaff(struct Unit* unit, void(*listTargets)(struct Unit* unit))
{
    listTargets(unit);

    MapFill(gMapMovement, -1);

    sub_802CB14(
        StartMapSelectExt(&MapSelectInfo_085C772C, StaffSelectOnSelect),
        DecodeMsg(0xC2A)); // TODO: msg ids
}

static void WarpSelect_Init(struct GenericProc* proc)
{
    struct Anim* anim;

    sub_802CB14(proc, DecodeMsg(0xC24)); // TODO: msg ids

    CameraMoveWatchPosition(proc,
        GetUnit(gAction.target)->x,
        GetUnit(gAction.target)->y);

    EndLimitView();

    sub_801C700(gActiveUnit, GetUnit(gAction.target));

    gBmSt.flags &= ~BM_FLAG_1;

    StartLimitView(1);

    SetMapCursorPosition(
        GetUnit(gAction.target)->x,
        GetUnit(gAction.target)->y);

    anim = StartAnim(Anim_08102450, 0);

    anim->oam2 = OAM2_CHR(0) + OAM2_PAL(0);
    Anim_SetAnimId(anim, 0);

    proc->ptr = anim;
    proc->unk4A = 2; // neither TRUE nor FALSE
}

static void WarpSelect_Loop(struct GenericProc* proc)
{
    Bool warpAllowed = gMapMovementSigned[gBmSt.cursor.y][gBmSt.cursor.x] != -1;

    HandlePlayerMapCursor();

    if (gKeySt->pressed & A_BUTTON)
    {
        if (warpAllowed)
        {
            Proc_Break(proc);

            gAction.xTarget = gBmSt.cursor.x;
            gAction.yTarget = gBmSt.cursor.y;

            SetStaffUseAction(gActiveUnit);

            TmFill(gBg2Tm, 0);
            EnableBgSync(BG2_SYNC_BIT);

            PlaySe(0x6A); // TODO: song ids

            return;
        }
        else
        {
            PlaySe(0x6C); // TODO: song ids
        }
    }

    if (gKeySt->pressed & B_BUTTON)
    {
        Proc_Goto(proc, 99);

        TmFill(gBg2Tm, 0);
        EnableBgSync(BG2_SYNC_BIT);

        PlaySe(0x6B); // TODO: song ids
    }

    if (warpAllowed != proc->unk4A)
    {
        Anim_SetAnimId(proc->ptr, warpAllowed ? 0 : 1);
    }

    Anim_Display(proc->ptr,
        gBmSt.cursorSpr.x - gBmSt.camera.x,
        gBmSt.cursorSpr.y - gBmSt.camera.y);

    proc->unk4A = warpAllowed;
}

static void WarpSelect_HandleConfirm(struct GenericProc* proc)
{
    ResetTextFont();
    EndLimitView();
    sub_802CB50();

    SetMapCursorPosition(
        gActiveUnit->x,
        gActiveUnit->y);

    CameraMoveWatchPosition(proc,
        gActiveUnit->x,
        gActiveUnit->y);
}

static void WarpSelect_HandleCancel(struct GenericProc* proc)
{
    ResetTextFont();
    EndLimitView();
    sub_802CB50();

    SetMapCursorPosition(
        gActiveUnit->x,
        gActiveUnit->y);

    SpawnProc(ProcScr_BackToUnitMenu, PROC_TREE_3);
}

static void WarpSelect_End(struct GenericProc* proc)
{
    EndLimitView();
    Anim_End(proc->ptr);
}

int WarpOnSelectTarget(struct MapSelectProc* proc, struct SelectTarget* target)
{
    EndMapSelect(proc);

    gAction.target = target->uid;

    SpawnProc(ProcScr_SquareSelectWarp, PROC_TREE_3);

    return MENU_ACT_SE_6A;
}

void DoUseWarpStaff(struct Unit* unit)
{
    ListWarpTargets(unit);

    MapFill(gMapMovement, -1);

    sub_802CB14(
        StartMapSelectExt(&MapSelectInfo_085C772C, WarpOnSelectTarget),
        DecodeMsg(0xC29)); // TODO: msg ids

    PlaySe(0x6A); // TODO: song ids
}

int UnlockOnSelectTarget(struct MapSelectProc* proc, struct SelectTarget* target)
{
    gAction.xTarget = target->x;
    gAction.yTarget = target->y;

    SetStaffUseAction(NULL);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

void DoUseUnlockStaff(struct Unit* unit, void(*listTargets)(struct Unit* unit))
{
    listTargets(unit);

    MapFill(gMapMovement, -1);

    sub_802CB14(
        StartMapSelectExt(&MapSelectInfo_085C770C, UnlockOnSelectTarget),
        DecodeMsg(0xC2E)); // TODO: msg ids

    PlaySe(0x6A); // TODO: song ids
}

int RepairSelectOnSelect(struct MapSelectProc* proc, struct SelectTarget* target)
{
    ResetTextFont();

    gAction.target = target->uid;

    StartEquipInfoWindow(
        sub_8041834(&MenuInfo_085C7498),
        GetUnit(gAction.target),
        16, 11);

    StartFace(0, GetUnitFid(GetUnit(gAction.target)), 184, 12, 2);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

void DoUseRepairStaff(struct Unit* unit)
{
    ListRepairTargets(unit);

    MapFill(gMapMovement, -1);

    sub_802CB14(
        StartMapSelect(&MapSelectInfo_Repair),
        DecodeMsg(0xC2C)); // TODO: msg ids

    PlaySe(0x6A); // TODO: song ids
}

int RepairSelectOnChange(struct MapSelectProc* proc, struct SelectTarget* target)
{
    sub_801D680(target->x, target->y);
    sub_802C274(GetUnit(target->uid));
}

void RepairSelectOnInit(struct MapSelectProc* proc)
{
    sub_802C034(proc);
}

int RepairMenuEntOnChange(struct MenuProc* menu, struct MenuEntProc* ent)
{
    UpdateEquipInfoWindow(ent->id);
}

int RepairMenuEntOnChangeOut(struct MenuProc* menu, struct MenuEntProc* ent)
{
}

u8 RepairMenuItemIsAvailable(struct MenuEntInfo const* info, int id)
{
    int item = GetUnit(gAction.target)->items[id];

    if (!item)
        return MENU_NOTSHOWN;

    if (!IsItemRepairable(item))
        return MENU_DISABLED;

    return MENU_ENABLED;
}

int RepairMenuItemDraw(struct MenuProc* menu, struct MenuEntProc* ent)
{
    int item = GetUnit(gAction.target)->items[ent->id];
    int isRepairable = IsItemRepairable(item);

    sub_8016720(&ent->text, item, isRepairable, gBg0Tm + TM_OFFSET(ent->x, ent->y));
    EnableBgSync(BG0_SYNC_BIT);

    return 0;
}

u8 RepairMenuItemSelect(struct MenuProc* menu, struct MenuEntProc* ent)
{
    if (ent->availability == MENU_DISABLED)
    {
        int msg, item = GetUnit(gAction.target)->items[ent->id];

        if (GetItemAttributes(item) & (ITEM_ATTR_UNBREAKABLE | ITEM_ATTR_UNREPAIRABLE | ITEM_ATTR_LOCK_DRAGON))
            msg = 0xC45; // TODO: msg ids
        else if (!(GetItemAttributes(item) & (ITEM_ATTR_WEAPON | ITEM_ATTR_STAFF)))
            msg = 0xC3A; // TODO: msg ids
        else if (GetItemUses(item) == GetItemMaxUses(item))
            msg = 0xC39; // TODO: msg ids

        if (msg != 0)
            MenuFrozenHelpBox(menu, msg);

        return MENU_ACT_SE_6B;
    }

    gAction.extra = ent->id;
    SetStaffUseAction(gActiveUnit);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR | MENU_ACT_ENDFACE;
}

void DoUseHealStaff(struct Unit* unit, void(*listTargets)(struct Unit* unit))
{
    listTargets(unit);

    MapFill(gMapMovement, -1);

    sub_802CB14(
        StartMapSelect(&MapSelectInfo_Heal),
        DecodeMsg(0xC28)); // TODO: msg ids
}

void DoUseRestoreStaff(struct Unit* unit, void(*listTargets)(struct Unit* unit))
{
    listTargets(unit);

    MapFill(gMapMovement, -1);

    sub_802CB14(
        StartMapSelect(&MapSelectInfo_Restore),
        DecodeMsg(0xC2B)); // TODO: msg ids
}

int BarrierSelectOnInit(struct MapSelectProc* proc)
{
    sub_802C414(proc);
}

int BarrierSelectOnChange(struct MapSelectProc* proc, struct SelectTarget* target)
{
    sub_801D680(target->x, target->y);
    sub_802C434(GetUnit(target->uid));
}

void DoUseBarrierStaff(struct Unit* unit)
{
    ListBarrierTargets(unit);

    MapFill(gMapMovement, -1);

    sub_802CB14(
        StartMapSelect(&MapSelectInfo_Barrier),
        DecodeMsg(0xC2D)); // TODO: msg ids
}

int AttackStaffSelectOnInit(struct MapSelectProc* proc)
{
    sub_802C4A8(proc);
}

int AttackStaffSelectOnChange(struct MapSelectProc* proc, struct SelectTarget* target)
{
    sub_801D680(target->x, target->y);
    sub_802C4BC(GetUnit(target->uid));
}

void DoUseAttackStaff(struct Unit* unit, void(*listTargets)(struct Unit* unit))
{
    listTargets(unit);

    MapFill(gMapMovement, -1);

    sub_802CB14(
        StartMapSelect(&MapSelectInfo_AttackStaff),
        DecodeMsg(0xC2F)); // TODO: msg ids
}

int sub_8024020(struct MapSelectProc* proc)
{
    sub_802C514(proc);
}

int sub_802402C(struct MapSelectProc* proc, struct SelectTarget* target)
{
    sub_801D680(target->x, target->y);

    sub_802C534(
        GetUnit(target->uid),
        sub_8025F50(gActiveUnit, GetUnit(target->uid)));
}

void sub_802406C(struct MapSelectProc* proc)
{
    sub_802CB50();
    ClearBg0Bg1();
}
