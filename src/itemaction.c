#include "itemaction.h"

#include "random.h"
#include "sound.h"
#include "msg.h"
#include "item.h"
#include "unit.h"
#include "map.h"
#include "mapwork.h"
#include "bmfx.h"
#include "targetlist.h"
#include "battle.h"
#include "action.h"
#include "eventinfo.h"

#include "constants/iids.h"
#include "constants/songs.h"
#include "constants/msg.h"

static void ApplyStatusChange(ProcPtr proc);

struct ProcScr CONST_DATA ProcScr_ApplyStatusChange[] =
{
    PROC_SLEEP(1),

    PROC_CALL(ApplyStatusChange),
    PROC_END,
};

void DoItemHealStaffAction(ProcPtr proc)
{
    int healed;

    BattleInitItemEffect(GetUnit(gAction.instigator), gAction.item_slot);
    BattleInitItemEffectTarget(GetUnit(gAction.target));

    healed = GetUnitItemHealAmount(GetUnit(gAction.instigator), GetUnit(gAction.instigator)->items[gAction.item_slot]);
    AddUnitHp(GetUnit(gAction.target), healed);

    gBattleHitIt->damage = gBattleUnitB.unit.hp - GetUnitCurrentHp(GetUnit(gAction.target));
    gBattleUnitB.unit.hp = GetUnitCurrentHp(GetUnit(gAction.target));;

    BattleApplyItemEffect(proc);
    BeginBattleAnimations();
}

void DoItemRestoreStaffAction(ProcPtr proc)
{
    BattleInitItemEffect(GetUnit(gAction.instigator), gAction.item_slot);
    BattleInitItemEffectTarget(GetUnit(gAction.target));

    SetUnitStatus(GetUnit(gAction.target), UNIT_STATUS_NONE);

    BattleApplyItemEffect(proc);
    BeginBattleAnimations();
}

void DoItemBarrierStaffAction(ProcPtr proc)
{
    BattleInitItemEffect(GetUnit(gAction.instigator), gAction.item_slot);
    BattleInitItemEffectTarget(GetUnit(gAction.target));

    GetUnit(gAction.target)->barrier = 7;

    BattleApplyItemEffect(proc);
    BeginBattleAnimations();
}

static void GetRescueStaffTargetPosition(struct Unit * unit, struct Unit * target, int * x_out, int * y_out)
{
    int foundDist, dist;
    int ix, iy;

    *x_out = -1;
    *y_out = -1;

    foundDist = 9999;

    MapFlood_Pass(unit);

    gMapUnit[unit->y][unit->x] = 0xFF;

    for (iy = gMapSize.y-1; iy >= 0; iy--)
    {
        for (ix = gMapSize.x-1; ix >= 0; ix--)
        {
            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if (gMapUnit[iy][ix] != 0)
                continue;

            if (gMapHidden[iy][ix] != 0)
                continue;

            if (!CanUnitCrossTerrain(target, gMapTerrain[iy][ix]))
                continue;

            dist = RECT_DISTANCE(ix, iy, unit->x, unit->y);

            if (foundDist >= dist)
            {
                foundDist = dist;
                *x_out = ix;
                *y_out = iy;
            }
        }
    }

    if (*x_out >= 0 && *y_out >= 0)
        return;

    foundDist = 9999;

    MapFlood_Unitless(unit->x, unit->y, MoveTable_Flying);

    gMapUnit[unit->y][unit->x] = 0xFF;

    for (iy = gMapSize.y-1; iy >= 0; iy--)
    {
        for (ix = gMapSize.x-1; ix >= 0; ix--)
        {
            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if (gMapUnit[iy][ix] != 0)
                continue;

            if (gMapHidden[iy][ix] != 0)
                continue;

            if (!CanUnitCrossTerrain(target, gMapTerrain[iy][ix]))
                continue;

            dist = RECT_DISTANCE(ix, iy, unit->x, unit->y);

            if (foundDist >= dist)
            {
                foundDist = dist;
                *x_out = ix;
                *y_out = iy;
            }
        }
    }

    if (*x_out >= 0 && *y_out >= 0)
        return;

    *x_out = target->x;
    *y_out = target->y;
}

void DoItemRescueStaffAction(ProcPtr proc)
{
    int x, y;

    BattleInitItemEffect(GetUnit(gAction.instigator), gAction.item_slot);
    BattleInitItemEffectTarget(GetUnit(gAction.target));

    GetRescueStaffTargetPosition(GetUnit(gAction.instigator), GetUnit(gAction.target), &x, &y);

    GetUnit(gAction.target)->x = x;
    GetUnit(gAction.target)->y = y;

    // huh
    gBattleUnitB.change_hp = x;
    gBattleUnitB.change_pow = y;

    BattleApplyItemEffect(proc);
    BeginBattleAnimations();
}

void DoItemWarpStaffAction(ProcPtr proc)
{
    BattleInitItemEffect(GetUnit(gAction.instigator), gAction.item_slot);
    BattleInitItemEffectTarget(GetUnit(gAction.target));

    GetUnit(gAction.target)->x = gAction.x_target;
    GetUnit(gAction.target)->y = gAction.y_target;

    // huh again
    gBattleUnitB.change_hp = gAction.x_target;
    gBattleUnitB.change_pow = gAction.y_target;

    BattleApplyItemEffect(proc);
    BeginBattleAnimations();
}

void DoItemAttackStaffAction(ProcPtr proc)
{
    int accuracy;

    BattleInitItemEffect(GetUnit(gAction.instigator), gAction.item_slot);
    BattleInitItemEffectTarget(GetUnit(gAction.target));

    accuracy = GetOffensiveStaffAccuracy(GetUnit(gAction.instigator), GetUnit(gAction.target));
    gBattleUnitA.battle_effective_hit = accuracy;

    if (!RandRoll(accuracy))
    {
        gBattleHitIt->attributes |= BATTLE_HIT_ATTR_MISS;
    }
    else
    {
        switch (GetItemIid(gBattleUnitA.weapon_before))
        {

        case IID_BERSERKSTAFF:
            gBattleUnitB.output_status = UNIT_STATUS_BERSERK;
            break;

        case IID_SILENCESTAFF:
            gBattleUnitB.output_status = UNIT_STATUS_SILENCED;
            break;

        case IID_SLEEPSTAFF:
            gBattleUnitB.output_status = UNIT_STATUS_SLEEP;
            break;

        }
    }

    BattleApplyItemEffect(proc);
    BeginBattleAnimations();
}

void DoItemFortifyStaffAction(ProcPtr proc)
{
    int healed;
    int i, count;

    BattleInitItemEffect(GetUnit(gAction.instigator), gAction.item_slot);

    ListRangedHealTargets(GetUnit(gAction.instigator));

    healed = GetUnitItemHealAmount(GetUnit(gAction.instigator), GetUnit(gAction.instigator)->items[gAction.item_slot]);

    for (count = CountTargets(), i = 0; i < count; ++i)
        AddUnitHp(GetUnit(GetTarget(i)->uid), healed);

    BattleApplyItemEffect(proc);
    BeginBattleAnimations();
}

void DoItemUnlockStaffAction(ProcPtr proc)
{
    BattleInitItemEffect(GetUnit(gAction.instigator), gAction.item_slot);

    gBattleUnitB.unit.x = gAction.x_target;
    gBattleUnitB.unit.y = gAction.y_target;

    // huh again again
    gBattleUnitB.change_hp = gAction.x_target;
    gBattleUnitB.change_pow = gAction.y_target;

    BattleApplyItemEffect(proc);
    BeginBattleAnimations();
}

void DoItemRepairStaffAction(ProcPtr proc)
{
    BattleInitItemEffect(GetUnit(gAction.instigator), gAction.item_slot);
    BattleInitItemEffectTarget(GetUnit(gAction.target));

    GetUnit(gAction.target)->items[gAction.extra] = CreateItem(GetUnit(gAction.target)->items[gAction.extra]);

    BattleApplyItemEffect(proc);
    BeginBattleAnimations();
}

void DoItemSaintStaffAction(ProcPtr proc)
{
    int i, count;

    BattleInitItemEffect(GetUnit(gAction.instigator), gAction.item_slot);

    ListSaintsStaffTargets(GetUnit(gAction.instigator));

    for (count = CountTargets(), i = 0; i < count; ++i)
    {
        struct Unit * unit = GetUnit(GetTarget(i)->uid);

        SetUnitHp(unit, GetUnitMaxHp(unit));
        SetUnitStatus(unit, UNIT_STATUS_NONE);
    }

    BattleApplyItemEffect(proc);
    BeginBattleAnimations();
}

void DoItemHealSelfAction(ProcPtr proc, int amount)
{
    BattleInitItemEffect(GetUnit(gAction.instigator), gAction.item_slot);

    AddUnitHp(GetUnit(gAction.instigator), amount);

    gBattleHitIt->damage = gBattleUnitA.unit.hp - GetUnitCurrentHp(GetUnit(gAction.instigator));
    gBattleUnitA.unit.hp = GetUnitCurrentHp(GetUnit(gAction.instigator));

    gBattleUnitA.weapon_before = IID_VULNERARY;

    BattleApplyItemEffect(proc);
    BeginBattleAnimations();
}

void DoItemElixirAction(ProcPtr proc)
{
    BattleInitItemEffect(GetUnit(gAction.instigator), gAction.item_slot);

    SetUnitHp(GetUnit(gAction.instigator), GetUnitMaxHp(GetUnit(gAction.instigator)));

    gBattleHitIt->damage = gBattleUnitA.unit.hp - GetUnitCurrentHp(GetUnit(gAction.instigator));
    gBattleUnitA.unit.hp = GetUnitCurrentHp(GetUnit(gAction.instigator));

    BattleApplyItemEffect(proc);
    BeginBattleAnimations();
}

void DoItemPureWaterAction(ProcPtr proc)
{
    BattleInitItemEffect(GetUnit(gAction.instigator), gAction.item_slot);

    GetUnit(gAction.instigator)->barrier = 7;

    BattleApplyItemEffect(proc);
    BeginBattleAnimations();
}

void DoItemTorchAction(ProcPtr proc)
{
    BattleInitItemEffect(GetUnit(gAction.instigator), gAction.item_slot);

    GetUnit(gAction.instigator)->torch = 4;

    BattleApplyItemEffect(proc);
    BeginBattleAnimations();
}

void DoItemAntitoxinAction(ProcPtr proc)
{
    BattleInitItemEffect(GetUnit(gAction.instigator), gAction.item_slot);

    SetUnitStatus(GetUnit(gAction.instigator), UNIT_STATUS_NONE);
    SetUnitStatus(&gBattleUnitA.unit, UNIT_STATUS_NONE);

    BattleApplyItemEffect(proc);
    BeginBattleAnimations();
}

void DoItemKeyAction(void)
{
    int x, y;

    UnitUpdateUsedItem(GetUnit(gAction.instigator), gAction.item_slot);

    x = GetUnit(gAction.instigator)->x;
    y = GetUnit(gAction.instigator)->y;

    StartAvailableDoorTileEvent(x-1, y);
    StartAvailableDoorTileEvent(x+1, y);
    StartAvailableDoorTileEvent(x, y-1);
    StartAvailableDoorTileEvent(x, y+1);

    StartAvailableChestTileEvent(x, y);

    PlaySe(SONG_B1);
}

void DoItemPromoteAction(void)
{
    gBattleUnitA.weapon_before = gBattleUnitB.weapon_before = GetUnit(gAction.instigator)->items[gAction.item_slot];
    gBattleUnitA.weapon = gBattleUnitB.weapon = GetUnitEquippedWeapon(GetUnit(gAction.instigator));

    // pre-promote battle unit
    InitBattleUnitWithoutBonuses(&gBattleUnitB, GetUnit(gAction.instigator));

    UnitPromote(GetUnit(gAction.instigator));

    // post-promote battle unit
    InitBattleUnitWithoutBonuses(&gBattleUnitA, GetUnit(gAction.instigator));

    GenerateBattleUnitStatGainsComparatively(&gBattleUnitA, &gBattleUnitB.unit);

    SetBattleUnitTerrainBonusesAuto(&gBattleUnitA);
    SetBattleUnitTerrainBonusesAuto(&gBattleUnitB);

    GetUnit(gAction.instigator)->flags |= UNIT_FLAG_HAD_ACTION;

    UnitUpdateUsedItem(GetUnit(gAction.instigator), gAction.item_slot);

    gBattleHits[0].attributes = 0;
    gBattleHits[0].info = BATTLE_HIT_INFO_END;
    gBattleHits[0].damage = 0;

    gBattleSt.flags = BATTLE_FLAG_BIT4;

    BeginBattleAnimations();
}

void func_fe6_08027DB4(struct Unit * unit, int item)
{
    gBattleUnitA.weapon_before = gBattleUnitB.weapon_before = item;
    gBattleUnitA.weapon = gBattleUnitB.weapon = item;

    InitBattleUnit(&gBattleUnitB, unit);

    UnitPromote(unit);

    InitBattleUnit(&gBattleUnitA, unit);

    GenerateBattleUnitStatGainsComparatively(&gBattleUnitA, &gBattleUnitB.unit);

    SetBattleUnitTerrainBonusesAuto(&gBattleUnitA);
    SetBattleUnitTerrainBonusesAuto(&gBattleUnitB);

    gBattleHits[0].attributes = 0;
    gBattleHits[0].info = BATTLE_HIT_INFO_END;
    gBattleHits[0].damage = 0;

    gBattleSt.flags = BATTLE_FLAG_BIT4;

    BeginBattleAnimations();
}

void DoItemStatBoostAction(ProcPtr proc)
{
    int msg = 0;

    struct Unit * unit = GetUnit(gAction.instigator);
    int item = GetUnit(gAction.instigator)->items[gAction.item_slot];

    struct ItemBonuses const * bonuses = GetItemBonuses(item);

    unit->max_hp += bonuses->hp;
    unit->pow += bonuses->pow;
    unit->skl += bonuses->skl;
    unit->spd += bonuses->spd;
    unit->def += bonuses->def;
    unit->res += bonuses->res;
    unit->lck += bonuses->lck;
    unit->bonus_mov += bonuses->mov;
    unit->bonus_con += bonuses->con;

    UnitCheckStatOverflow(unit);

    UnitUpdateUsedItem(unit, gAction.item_slot);

    switch (GetItemIid(item))
    {

    case IID_SECRETBOOK:
        msg = MSG_C12;
        break;

    case IID_GODDESSICON:
        msg = MSG_C14;
        break;

    case IID_SERAPHROBE:
        msg = MSG_C19;
        break;

    case IID_DRACOSHIELD:
        msg = MSG_C15;
        break;

    case IID_SPEEDWING:
        msg = MSG_C13;
        break;

    case IID_TALISMAN:
        msg = MSG_C16;
        break;

    case IID_BOOTS:
        msg = MSG_C17;
        break;

    case IID_BODYRING:
        msg = MSG_C18;
        break;

    case IID_ENERGYRING:
        msg = UnitKnowsMagic(unit) ? MSG_C11 : MSG_C10;
        break;

    }

    PlaySe(SONG_5A);

    func_fe6_0801DA54(proc, GetItemIcon(item), DecodeMsg(msg));
}

void DoItemAction(ProcPtr proc)
{
    int iid = GetItemIid(GetUnit(gAction.instigator)->items[gAction.item_slot]);

    gBattleUnitA.has_item_effect_target = FALSE;

    switch (iid)
    {

    case IID_HEALSTAFF:
    case IID_MENDSTAFF:
    case IID_RECOVERSTAFF:
    case IID_PHYSICSTAFF:
    case IID_TINASSTAFF:
        DoItemHealStaffAction(proc);
        break;

    case IID_SLEEPSTAFF:
    case IID_SILENCESTAFF:
    case IID_BERSERKSTAFF:
        DoItemAttackStaffAction(proc);
        break;

    case IID_FORTIFYSTAFF:
        DoItemFortifyStaffAction(proc);
        break;

    case IID_RESTORESTAFF:
        DoItemRestoreStaffAction(proc);
        break;

    case IID_RESCUESTAFF:
        DoItemRescueStaffAction(proc);
        break;

    case IID_BARRIERSTAFF:
        DoItemBarrierStaffAction(proc);
        break;

    case IID_WARPSTAFF:
        DoItemWarpStaffAction(proc);
        break;

    case IID_UNLOCKSTAFF:
        DoItemUnlockStaffAction(proc);
        break;

    case IID_HAMMERNESTAFF:
        DoItemRepairStaffAction(proc);
        break;

    case IID_TORCHSTAFF:
    case IID_TORCH:
        DoItemTorchAction(proc);
        break;

    case IID_VULNERARY:
        DoItemHealSelfAction(proc, 10);
        break;

    case IID_ELIXIR:
        DoItemElixirAction(proc);
        break;

    case IID_PUREWATER:
        DoItemPureWaterAction(proc);
        break;

    case IID_ANTITOXIN:
        DoItemAntitoxinAction(proc);
        break;

    case IID_BINDINGBLADE:
        DoItemHealSelfAction(proc, 30);
        break;

    case IID_CHESTKEY:
    case IID_DOORKEY:
    case IID_BRIDGEKEY:
    case IID_LOCKPICK:
        DoItemKeyAction();
        break;

    case IID_HEROCREST:
    case IID_KNIGHTCREST:
    case IID_ORIONSBOLT:
    case IID_ELYSIANWHIP:
    case IID_GUIDINGRING:
        DoItemPromoteAction();
        break;

    case IID_SECRETBOOK:
    case IID_GODDESSICON:
    case IID_SERAPHROBE:
    case IID_DRACOSHIELD:
    case IID_ENERGYRING:
    case IID_SPEEDWING:
    case IID_TALISMAN:
    case IID_BOOTS:
    case IID_BODYRING:
        DoItemStatBoostAction(proc);
        break;

    case IID_SAINTSSTAFF:
        DoItemSaintStaffAction(proc);
        break;

    }

    if (gBattleUnitB.output_status >= 0)
        SpawnProcLocking(ProcScr_ApplyStatusChange, proc);
}

static void ApplyStatusChange(ProcPtr proc)
{
    if (gBattleUnitB.output_status >= 0)
    {
        SetUnitStatus(GetUnit(gAction.target), gBattleUnitB.output_status);
        gBattleUnitB.output_status = -1;
    }
}
