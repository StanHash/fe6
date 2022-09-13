
#include "item-use.h"
#include "common.h"

#include "hardware.h"
#include "oam.h"
#include "sound.h"
#include "face.h"
#include "sprite-anim.h"
#include "msg.h"
#include "item.h"
#include "unit.h"
#include "map.h"
#include "player-phase.h"
#include "bmfx.h"
#include "target-list.h"
#include "battle.h"
#include "action.h"
#include "map-select.h"
#include "unit-panel.h"
#include "subtitle-help.h"
#include "menu-info.h"
#include "ui.h"
#include "eventinfo.h"

#include "constants/items.h"
#include "constants/terrains.h"
#include "constants/songs.h"
#include "constants/msg.h"

// TODO: map-menu.h
extern struct ProcScr CONST_DATA ProcScr_BackToUnitMenu[];

extern struct Unit gStatGainSimUnit;

static bool HasSelectTarget(struct Unit * unit, void (* list_targets)(struct Unit * unit));

static void SetStaffUseAction(struct Unit * unit);
static void SetItemUseAction(struct Unit * unit);

static void WarpSelect_Init(struct GenericProc * proc);
static void WarpSelect_Loop(struct GenericProc * proc);
static void WarpSelect_HandleConfirm(struct GenericProc * proc);
static void WarpSelect_HandleCancel(struct GenericProc * proc);
static void WarpSelect_End(struct GenericProc * proc);

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

bool CanUnitUseItem(struct Unit * unit, int item)
{
    if ((GetItemAttributes(item) & ITEM_ATTR_STAFF) && !CanUnitUseStaff(unit, item))
        return FALSE;

    switch (GetItemIid(item))
    {

    case IID_HEALSTAFF:
    case IID_MENDSTAFF:
    case IID_RECOVERSTAFF:
    case IID_TINASSTAFF:
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

    case IID_HAMMERNESTAFF:
        return HasSelectTarget(unit, ListRepairTargets);

    case IID_UNLOCKSTAFF:
        return HasSelectTarget(unit, ListUnlockTargets);

    case IID_SECRETBOOK:
    case IID_GODDESSICON:
    case IID_SERAPHROBE:
    case IID_DRACOSHIELD:
    case IID_ENERGYRING:
    case IID_SPEEDWING:
    case IID_TALISMAN:
    case IID_BOOTS:
    case IID_BODYRING:
        return CanUnitUseStatGainItem(unit, item);

    case IID_HEROCREST:
    case IID_KNIGHTCREST:
    case IID_ORIONSBOLT:
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

    case IID_SAINTSSTAFF:
        return HasSelectTarget(unit, ListSaintsStaffTargets);

    default:
        return FALSE;

    }
}

int GetUnitItemCantUseMsg(struct Unit * unit, int item)
{
    switch (GetItemIid(item))
    {

    case IID_BINDINGBLADE:
    case IID_TORCHSTAFF:
    case IID_SECRETBOOK:
    case IID_GODDESSICON:
    case IID_SERAPHROBE:
    case IID_DRACOSHIELD:
    case IID_ENERGYRING:
    case IID_SPEEDWING:
    case IID_TALISMAN:
    case IID_BOOTS:
    case IID_BODYRING:
    case IID_VULNERARY:
    case IID_ELIXIR:
    case IID_PUREWATER:
    case IID_TORCH:
    case IID_ANTITOXIN:
        return MSG_C3C;

    case IID_CHESTKEY:
        return MSG_C40;

    case IID_DOORKEY:
    case IID_BRIDGEKEY:
        return MSG_C3F;

    case IID_LOCKPICK:
        if (UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_STEAL)
            return MSG_C43;

        return MSG_C41;

    case IID_HEROCREST:
    case IID_KNIGHTCREST:
    case IID_ORIONSBOLT:
    case IID_ELYSIANWHIP:
    case IID_GUIDINGRING:
    {
        bool boolval;

        int level = gActiveUnit->level;

        gActiveUnit->level = 10;
        boolval = CanUnitUsePromotionItem(gActiveUnit, item);
        gActiveUnit->level = level;

        if (boolval)
            return MSG_C3E;

        return MSG_C3D;
    }

    default:
        return MSG_C3D;

    }
}

void DoUseUnitItem(struct Unit * unit, int item)
{
    ClearUi();
    EndFaceById(0);

    switch (GetItemIid(item))
    {

    case IID_HEALSTAFF:
    case IID_MENDSTAFF:
    case IID_RECOVERSTAFF:
    case IID_TINASSTAFF:
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

    case IID_HAMMERNESTAFF:
        DoUseRepairStaff(unit);
        break;

    case IID_FORTIFYSTAFF:
    case IID_TORCHSTAFF:
    case IID_SAINTSSTAFF:
        SetStaffUseAction(unit);
        break;

    default:
        SetItemUseAction(unit);
        break;

    }
}

static bool HasSelectTarget(struct Unit * unit, void (* list_targets)(struct Unit *))
{
    list_targets(unit);
    return CountTargets() != 0;
}

bool CanUnitUseHealItem(struct Unit * unit)
{
    if (GetUnitCurrentHp(unit) == GetUnitMaxHp(unit))
        return FALSE;

    return TRUE;
}

bool CanUnitUseBindingBladeToHeal(struct Unit * unit)
{
    if (!CanUnitUseWeapon(unit, IID_BINDINGBLADE))
        return FALSE;

    return CanUnitUseHealItem(unit);
}

bool CanUnitUsePureWaterItem(struct Unit * unit)
{
    if (unit->barrier == 7)
        return FALSE;

    return TRUE;
}

bool CanUnitUseTorchItem(struct Unit * unit)
{
    if (gPlaySt.vision != 0 && unit->torch != 4)
        return TRUE;

    return FALSE;
}

bool CanUnitUseAntitoxinItem(struct Unit * unit)
{
    if (unit->status != UNIT_STATUS_POISON)
        return FALSE;

    return TRUE;
}

bool CanUnitUseChestKeyItem(struct Unit * unit)
{
    if (gMapTerrain[unit->y][unit->x] != TERRAIN_CHEST)
        return FALSE;

    if (!CheckAvailableChestTileEvent(unit->x, unit->y))
        return FALSE;

    return TRUE;
}

bool CanUnitUseDoorKeyItem(struct Unit * unit)
{
    ListOpenTerrainTargets(unit, TERRAIN_DOOR);
    return CountTargets();
}

bool CanUnitUseBridgeKeyItem(struct Unit * unit)
{
    ListOpenTerrainTargets(unit, TERRAIN_DRAWBRIDGE);
    return CountTargets();
}

bool CanUnitUseLockpickItem(struct Unit * unit)
{
    if (!(UNIT_ATTRIBUTES(unit) & UNIT_ATTR_STEAL))
        return FALSE;

    if (!CanUnitUseChestKeyItem(unit) && !CanUnitUseDoorKeyItem(unit) && !CanUnitUseBridgeKeyItem(unit))
        return FALSE;

    return TRUE;
}

bool CanUnitUsePromotionItem(struct Unit * unit, int item)
{
    u8 const * jlist = NULL;

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

    case IID_ORIONSBOLT:
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
        if (unit->jinfo->id == *jlist)
            return TRUE;

        jlist++;
    }

    return FALSE;
}

bool CanUnitUseStatGainItem(struct Unit * unit, int item)
{
    bool result;

    struct ItemBonuses const * bonuses = GetItemBonuses(item);

    ClearUnit(&gStatGainSimUnit);

    gStatGainSimUnit.pinfo = unit->pinfo;
    gStatGainSimUnit.jinfo = unit->jinfo;

    gStatGainSimUnit.max_hp = unit->max_hp + bonuses->hp;
    gStatGainSimUnit.pow = unit->pow + bonuses->pow;
    gStatGainSimUnit.skl = unit->skl + bonuses->skl;
    gStatGainSimUnit.spd = unit->spd + bonuses->spd;
    gStatGainSimUnit.def = unit->def + bonuses->def;
    gStatGainSimUnit.res = unit->res + bonuses->res;
    gStatGainSimUnit.lck = unit->lck + bonuses->lck;
    gStatGainSimUnit.bonus_mov = unit->bonus_mov + bonuses->mov;
    gStatGainSimUnit.bonus_con = unit->bonus_con + bonuses->con;

    UnitCheckStatOverflow(&gStatGainSimUnit);

    result = gStatGainSimUnit.max_hp != unit->max_hp;

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

    if (gStatGainSimUnit.bonus_mov != unit->bonus_mov)
        result = TRUE;

    if (gStatGainSimUnit.bonus_con != unit->bonus_con)
        result = TRUE;

    return result;
}

static void SetStaffUseAction(struct Unit * unit)
{
    EndLimitView();

    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);

    gAction.id = ACTION_STAFF;
}

static void SetItemUseAction(struct Unit * unit)
{
    gAction.id = ACTION_USEITEM;
}

fu8 StaffMapSelect_Select(struct MapSelectProc * proc, struct SelectTarget * target)
{
    gAction.target = target->uid;
    SetStaffUseAction(NULL);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

void DoUseRescueStaff(struct Unit * unit, void (* list_targets)(struct Unit * unit))
{
    list_targets(unit);

    MapFill(gMapMovement, -1);

    StartSubtitleHelp(
        StartMapSelectExt(&MapSelectInfo_WarpUnit, StaffMapSelect_Select),
        DecodeMsg(MSG_C2A));
}

static void WarpSelect_Init(struct GenericProc * proc)
{
    struct SpriteAnim * anim;

    StartSubtitleHelp(proc, DecodeMsg(MSG_C24));

    CameraMoveWatchPosition(proc,
        GetUnit(gAction.target)->x,
        GetUnit(gAction.target)->y);

    EndLimitView();

    func_fe6_0801C700(gActiveUnit, GetUnit(gAction.target));

    gBmSt.flags &= ~BM_FLAG_1;

    StartLimitView(1);

    SetMapCursorPosition(
        GetUnit(gAction.target)->x,
        GetUnit(gAction.target)->y);

    anim = StartSpriteAnim(SpriteAnim_08102450, 0);

    anim->oam2 = OAM2_CHR(0) + OAM2_PAL(0);
    SetSpriteAnimId(anim, 0);

    proc->ptr = anim;
    proc->unk4A = 2; // neither TRUE nor FALSE
}

static void WarpSelect_Loop(struct GenericProc * proc)
{
    bool warpAllowed = gMapMovementSigned[gBmSt.cursor.y][gBmSt.cursor.x] != -1;

    HandlePlayerMapCursor();

    if (gKeySt->pressed & KEY_BUTTON_A)
    {
        if (warpAllowed)
        {
            Proc_Break(proc);

            gAction.x_target = gBmSt.cursor.x;
            gAction.y_target = gBmSt.cursor.y;

            SetStaffUseAction(gActiveUnit);

            TmFill(gBg2Tm, 0);
            EnableBgSync(BG2_SYNC_BIT);

            PlaySe(SONG_6A);

            return;
        }
        else
        {
            PlaySe(SONG_6C);
        }
    }

    if (gKeySt->pressed & KEY_BUTTON_B)
    {
        Proc_Goto(proc, 99);

        TmFill(gBg2Tm, 0);
        EnableBgSync(BG2_SYNC_BIT);

        PlaySe(SONG_6B);
    }

    if (warpAllowed != proc->unk4A)
    {
        SetSpriteAnimId(proc->ptr, warpAllowed ? 0 : 1);
    }

    DisplaySpriteAnim(proc->ptr,
        gBmSt.cursor_sprite.x - gBmSt.camera.x,
        gBmSt.cursor_sprite.y - gBmSt.camera.y);

    proc->unk4A = warpAllowed;
}

static void WarpSelect_HandleConfirm(struct GenericProc * proc)
{
    ResetTextFont();
    EndLimitView();
    EndSubtitleHelp();

    SetMapCursorPosition(
        gActiveUnit->x,
        gActiveUnit->y);

    CameraMoveWatchPosition(proc,
        gActiveUnit->x,
        gActiveUnit->y);
}

static void WarpSelect_HandleCancel(struct GenericProc * proc)
{
    ResetTextFont();
    EndLimitView();
    EndSubtitleHelp();

    SetMapCursorPosition(
        gActiveUnit->x,
        gActiveUnit->y);

    SpawnProc(ProcScr_BackToUnitMenu, PROC_TREE_3);
}

static void WarpSelect_End(struct GenericProc * proc)
{
    EndLimitView();
    EndSpriteAnim(proc->ptr);
}

fu8 WarpMapSelect_Select(struct MapSelectProc * proc, struct SelectTarget * target)
{
    EndMapSelect(proc);

    gAction.target = target->uid;

    SpawnProc(ProcScr_SquareSelectWarp, PROC_TREE_3);

    return MENU_ACTION_SE_6A;
}

void DoUseWarpStaff(struct Unit * unit)
{
    ListWarpTargets(unit);

    MapFill(gMapMovement, -1);

    StartSubtitleHelp(
        StartMapSelectExt(&MapSelectInfo_WarpUnit, WarpMapSelect_Select),
        DecodeMsg(MSG_C29));

    PlaySe(SONG_6A);
}

fu8 UnlockMapSelect_Select(struct MapSelectProc * proc, struct SelectTarget * target)
{
    gAction.x_target = target->x;
    gAction.y_target = target->y;

    SetStaffUseAction(NULL);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

void DoUseUnlockStaff(struct Unit * unit, void (* list_targets)(struct Unit * unit))
{
    list_targets(unit);

    MapFill(gMapMovement, -1);

    StartSubtitleHelp(
        StartMapSelectExt(&MapSelectInfo_Unlock, UnlockMapSelect_Select),
        DecodeMsg(MSG_C2E));

    PlaySe(SONG_6A);
}

fu8 RepairMapSelect_Select(struct MapSelectProc * proc, struct SelectTarget * target)
{
    ResetTextFont();

    gAction.target = target->uid;

    StartEquipInfoWindow(
        StartMenu(&MenuInfo_RepairItem),
        GetUnit(gAction.target),
        16, 11);

    StartFace(0, GetUnitFid(GetUnit(gAction.target)), 184, 12, 2);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

void DoUseRepairStaff(struct Unit * unit)
{
    ListRepairTargets(unit);

    MapFill(gMapMovement, -1);

    StartSubtitleHelp(
        StartMapSelect(&MapSelectInfo_Repair),
        DecodeMsg(MSG_C2C));

    PlaySe(SONG_6A);
}

fu8 RepairMapSelect_SwitchIn(struct MapSelectProc * proc, struct SelectTarget * target)
{
    MakeActiveMuWatchPosition(target->x, target->y);
    RefreshUnitRepairInventoryPanel(GetUnit(target->uid));
}

void RepairMapSelect_Init(struct MapSelectProc * proc)
{
    StartUnitInventoryPanel(proc);
}

fu8 RepairItemMenu_Entry_SwitchIn(struct MenuProc * menu, struct MenuEntProc * ent)
{
    UpdateEquipInfoWindow(ent->id);
}

fu8 RepairItemMenu_Entry_SwitchOut(struct MenuProc * menu, struct MenuEntProc * ent)
{
}

fu8 RepairItemMenu_Entry_Available(struct MenuEntInfo const * info, int id)
{
    int item = GetUnit(gAction.target)->items[id];

    if (!item)
        return MENU_ENTRY_HIDDEN;

    if (!IsItemRepairable(item))
        return MENU_ENTRY_DISABLED;

    return MENU_ENTRY_ENABLED;
}

u32 RepairItemMenu_Entry_Display(struct MenuProc * menu, struct MenuEntProc * ent)
{
    int item = GetUnit(gAction.target)->items[ent->id];
    int isRepairable = IsItemRepairable(item);

    func_fe6_08016720(&ent->text, item, isRepairable, gBg0Tm + TM_OFFSET(ent->x, ent->y));
    EnableBgSync(BG0_SYNC_BIT);

    return 0;
}

fu8 RepairItemMenu_Entry_Select(struct MenuProc * menu, struct MenuEntProc * ent)
{
    if (ent->availability == MENU_ENTRY_DISABLED)
    {
        int msg, item = GetUnit(gAction.target)->items[ent->id];

        if (GetItemAttributes(item) & (ITEM_ATTR_UNBREAKABLE | ITEM_ATTR_UNREPAIRABLE | ITEM_ATTR_LOCK_DRAGON))
            msg = MSG_C45;
        else if (!(GetItemAttributes(item) & (ITEM_ATTR_WEAPON | ITEM_ATTR_STAFF)))
            msg = MSG_C3A;
        else if (GetItemUses(item) == GetItemMaxUses(item))
            msg = MSG_C39;

        if (msg != 0)
            MenuFrozenHelpBox(menu, msg);

        return MENU_ACTION_SE_6B;
    }

    gAction.extra = ent->id;
    SetStaffUseAction(gActiveUnit);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR | MENU_ACTION_ENDFACE;
}

void DoUseHealStaff(struct Unit * unit, void (* list_targets)(struct Unit * unit))
{
    list_targets(unit);

    MapFill(gMapMovement, -1);

    StartSubtitleHelp(
        StartMapSelect(&MapSelectInfo_Heal),
        DecodeMsg(MSG_C28));
}

void DoUseRestoreStaff(struct Unit * unit, void (* list_targets)(struct Unit * unit))
{
    list_targets(unit);

    MapFill(gMapMovement, -1);

    StartSubtitleHelp(
        StartMapSelect(&MapSelectInfo_Restore),
        DecodeMsg(MSG_C2B));
}

int RestoreMapSelect_Init(struct MapSelectProc * proc)
{
    StartUnitHpStatusPanel(proc);
}

fu8 RestoreMapSelect_SwitchIn(struct MapSelectProc * proc, struct SelectTarget * target)
{
    MakeActiveMuWatchPosition(target->x, target->y);
    RefreshUnitHpStatusPanel(GetUnit(target->uid));
}

void DoUseBarrierStaff(struct Unit * unit)
{
    ListBarrierTargets(unit);

    MapFill(gMapMovement, -1);

    StartSubtitleHelp(
        StartMapSelect(&MapSelectInfo_Barrier),
        DecodeMsg(MSG_C2D));
}

int BarrierMapSelect_Init(struct MapSelectProc * proc)
{
    StartUnitResChangePanel(proc);
}

fu8 BarrierMapSelect_SwitchIn(struct MapSelectProc * proc, struct SelectTarget * target)
{
    MakeActiveMuWatchPosition(target->x, target->y);
    RefreshUnitResChangePanel(GetUnit(target->uid));
}

void DoUseAttackStaff(struct Unit * unit, void (* list_targets)(struct Unit * unit))
{
    list_targets(unit);

    MapFill(gMapMovement, -1);

    StartSubtitleHelp(
        StartMapSelect(&MapSelectInfo_AttackStaff),
        DecodeMsg(MSG_C2F));
}

int AttackStaffMapSelect_Init(struct MapSelectProc * proc, struct SelectTarget * target)
{
    StartUnitStaffOffensePanel(proc);
}

fu8 AttackStaffMapSelect_SwitchIn(struct MapSelectProc * proc, struct SelectTarget * target)
{
    MakeActiveMuWatchPosition(target->x, target->y);

    RefreshUnitStaffOffensePanel(
        GetUnit(target->uid),
        GetOffensiveStaffAccuracy(gActiveUnit, GetUnit(target->uid)));
}

void SubtitleMapSelect_End(struct MapSelectProc * proc)
{
    EndSubtitleHelp();
    ClearUi();
}
