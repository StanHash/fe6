
#include "item-action.h"
#include "common.h"

#include "random.h"
#include "sound.h"
#include "msg.h"
#include "item.h"
#include "unit.h"
#include "map.h"
#include "mapwork.h"
#include "bmfx.h"
#include "target-list.h"
#include "battle.h"
#include "action.h"

#include "constants/items.h"
#include "constants/songs.h"

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

    BattleInitItemEffect(GetUnit(gAction.instigator), gAction.itemSlot);
    BattleInitItemEffectTarget(GetUnit(gAction.target));

    healed = GetUnitItemHealAmount(GetUnit(gAction.instigator), GetUnit(gAction.instigator)->items[gAction.itemSlot]);
    AddUnitHp(GetUnit(gAction.target), healed);

    gBattleHitIt->damage = gBattleUnitB.unit.hpCur - GetUnitCurrentHp(GetUnit(gAction.target));
    gBattleUnitB.unit.hpCur = GetUnitCurrentHp(GetUnit(gAction.target));;

    BattleApplyItemEffect(proc);
    BeginBattleAnimations();
}

void DoItemRestoreStaffAction(ProcPtr proc)
{
    BattleInitItemEffect(GetUnit(gAction.instigator), gAction.itemSlot);
    BattleInitItemEffectTarget(GetUnit(gAction.target));

    SetUnitStatus(GetUnit(gAction.target), UNIT_STATUS_NONE);

    BattleApplyItemEffect(proc);
    BeginBattleAnimations();
}

void DoItemBarrierStaffAction(ProcPtr proc)
{
    BattleInitItemEffect(GetUnit(gAction.instigator), gAction.itemSlot);
    BattleInitItemEffectTarget(GetUnit(gAction.target));

    GetUnit(gAction.target)->barrier = 7;

    BattleApplyItemEffect(proc);
    BeginBattleAnimations();
}

static void GetRescueStaffTargetPosition(struct Unit* unit, struct Unit* target, int* xOut, int* yOut)
{
    int foundDist, dist;
    int ix, iy;

    *xOut = -1;
    *yOut = -1;

    foundDist = 9999;

    MapFlood_080193C0(unit);

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
                *xOut = ix;
                *yOut = iy;
            }
        }
    }

    if (*xOut >= 0 && *yOut >= 0)
        return;

    foundDist = 9999;

    MapFlood_08019424(unit->x, unit->y, MoveTable_Unk_0860C912);

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
                *xOut = ix;
                *yOut = iy;
            }
        }
    }

    if (*xOut >= 0 && *yOut >= 0)
        return;

    *xOut = target->x;
    *yOut = target->y;
}

void DoItemRescueStaffAction(ProcPtr proc)
{
    int x, y;

    BattleInitItemEffect(GetUnit(gAction.instigator), gAction.itemSlot);
    BattleInitItemEffectTarget(GetUnit(gAction.target));

    GetRescueStaffTargetPosition(GetUnit(gAction.instigator), GetUnit(gAction.target), &x, &y);

    GetUnit(gAction.target)->x = x;
    GetUnit(gAction.target)->y = y;

    // huh
    gBattleUnitB.hpChange = x;
    gBattleUnitB.powChange = y;

    BattleApplyItemEffect(proc);
    BeginBattleAnimations();
}

void DoItemWarpStaffAction(ProcPtr proc)
{
    BattleInitItemEffect(GetUnit(gAction.instigator), gAction.itemSlot);
    BattleInitItemEffectTarget(GetUnit(gAction.target));

    GetUnit(gAction.target)->x = gAction.xTarget;
    GetUnit(gAction.target)->y = gAction.yTarget;

    // huh again
    gBattleUnitB.hpChange = gAction.xTarget;
    gBattleUnitB.powChange = gAction.yTarget;

    BattleApplyItemEffect(proc);
    BeginBattleAnimations();
}

void DoItemAttackStaffAction(ProcPtr proc)
{
    int accuracy;

    BattleInitItemEffect(GetUnit(gAction.instigator), gAction.itemSlot);
    BattleInitItemEffectTarget(GetUnit(gAction.target));

    accuracy = GetOffensiveStaffAccuracy(GetUnit(gAction.instigator), GetUnit(gAction.target));
    gBattleUnitA.battleEffectiveHit = accuracy;

    if (!RandRoll(accuracy))
    {
        gBattleHitIt->attributes |= BATTLE_HIT_ATTR_MISS;
    }
    else
    {
        switch (GetItemIid(gBattleUnitA.weaponBefore))
        {

        case IID_BERSERKSTAFF:
            gBattleUnitB.statusOut = UNIT_STATUS_BERSERK;
            break;

        case IID_SILENCESTAFF:
            gBattleUnitB.statusOut = UNIT_STATUS_SILENCED;
            break;

        case IID_SLEEPSTAFF:
            gBattleUnitB.statusOut = UNIT_STATUS_SLEEP;
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

    BattleInitItemEffect(GetUnit(gAction.instigator), gAction.itemSlot);

    ListRangedHealTargets(GetUnit(gAction.instigator));

    healed = GetUnitItemHealAmount(GetUnit(gAction.instigator), GetUnit(gAction.instigator)->items[gAction.itemSlot]);

    for (count = CountTargets(), i = 0; i < count; ++i)
        AddUnitHp(GetUnit(GetTarget(i)->uid), healed);

    BattleApplyItemEffect(proc);
    BeginBattleAnimations();
}

void DoItemUnlockStaffAction(ProcPtr proc)
{
    BattleInitItemEffect(GetUnit(gAction.instigator), gAction.itemSlot);

    gBattleUnitB.unit.x = gAction.xTarget;
    gBattleUnitB.unit.y = gAction.yTarget;

    // huh again again
    gBattleUnitB.hpChange = gAction.xTarget;
    gBattleUnitB.powChange = gAction.yTarget;

    BattleApplyItemEffect(proc);
    BeginBattleAnimations();
}

void DoItemRepairStaffAction(ProcPtr proc)
{
    BattleInitItemEffect(GetUnit(gAction.instigator), gAction.itemSlot);
    BattleInitItemEffectTarget(GetUnit(gAction.target));

    GetUnit(gAction.target)->items[gAction.extra] = CreateItem(GetUnit(gAction.target)->items[gAction.extra]);

    BattleApplyItemEffect(proc);
    BeginBattleAnimations();
}

void DoItemSaintStaffAction(ProcPtr proc)
{
    int i, count;

    BattleInitItemEffect(GetUnit(gAction.instigator), gAction.itemSlot);

    ListSaintsStaffTargets(GetUnit(gAction.instigator));

    for (count = CountTargets(), i = 0; i < count; ++i)
    {
        struct Unit* unit = GetUnit(GetTarget(i)->uid);

        SetUnitHp(unit, GetUnitMaxHp(unit));
        SetUnitStatus(unit, UNIT_STATUS_NONE);
    }

    BattleApplyItemEffect(proc);
    BeginBattleAnimations();
}

void DoItemHealSelfAction(ProcPtr proc, int amount)
{
    BattleInitItemEffect(GetUnit(gAction.instigator), gAction.itemSlot);

    AddUnitHp(GetUnit(gAction.instigator), amount);

    gBattleHitIt->damage = gBattleUnitA.unit.hpCur - GetUnitCurrentHp(GetUnit(gAction.instigator));
    gBattleUnitA.unit.hpCur = GetUnitCurrentHp(GetUnit(gAction.instigator));

    gBattleUnitA.weaponBefore = IID_VULNERARY;

    BattleApplyItemEffect(proc);
    BeginBattleAnimations();
}

void DoItemElixirAction(ProcPtr proc)
{
    BattleInitItemEffect(GetUnit(gAction.instigator), gAction.itemSlot);

    SetUnitHp(GetUnit(gAction.instigator), GetUnitMaxHp(GetUnit(gAction.instigator)));

    gBattleHitIt->damage = gBattleUnitA.unit.hpCur - GetUnitCurrentHp(GetUnit(gAction.instigator));
    gBattleUnitA.unit.hpCur = GetUnitCurrentHp(GetUnit(gAction.instigator));

    BattleApplyItemEffect(proc);
    BeginBattleAnimations();
}

void DoItemPureWaterAction(ProcPtr proc)
{
    BattleInitItemEffect(GetUnit(gAction.instigator), gAction.itemSlot);

    GetUnit(gAction.instigator)->barrier = 7;

    BattleApplyItemEffect(proc);
    BeginBattleAnimations();
}

void DoItemTorchAction(ProcPtr proc)
{
    BattleInitItemEffect(GetUnit(gAction.instigator), gAction.itemSlot);

    GetUnit(gAction.instigator)->torch = 4;

    BattleApplyItemEffect(proc);
    BeginBattleAnimations();
}

void DoItemAntitoxinAction(ProcPtr proc)
{
    BattleInitItemEffect(GetUnit(gAction.instigator), gAction.itemSlot);

    SetUnitStatus(GetUnit(gAction.instigator), UNIT_STATUS_NONE);
    SetUnitStatus(&gBattleUnitA.unit, UNIT_STATUS_NONE);

    BattleApplyItemEffect(proc);
    BeginBattleAnimations();
}

void DoItemKeyAction(void)
{
    int x, y;

    UnitUpdateUsedItem(GetUnit(gAction.instigator), gAction.itemSlot);

    x = GetUnit(gAction.instigator)->x;
    y = GetUnit(gAction.instigator)->y;

    sub_806B398(x-1, y);
    sub_806B398(x+1, y);
    sub_806B398(x, y-1);
    sub_806B398(x, y+1);

    sub_806B354(x, y);

    PlaySe(SONG_B1);
}

void DoItemPromoteAction(void)
{
    gBattleUnitA.weaponBefore = gBattleUnitB.weaponBefore = GetUnit(gAction.instigator)->items[gAction.itemSlot];
    gBattleUnitA.weapon = gBattleUnitB.weapon = GetUnitEquippedWeapon(GetUnit(gAction.instigator));

    // pre-promote battle unit
    InitBattleUnitWithoutBonuses(&gBattleUnitB, GetUnit(gAction.instigator));

    UnitPromote(GetUnit(gAction.instigator));

    // post-promote battle unit
    InitBattleUnitWithoutBonuses(&gBattleUnitA, GetUnit(gAction.instigator));

    GenerateBattleUnitStatGainsComparatively(&gBattleUnitA, &gBattleUnitB.unit);

    SetBattleUnitTerrainBonusesAuto(&gBattleUnitA);
    SetBattleUnitTerrainBonusesAuto(&gBattleUnitB);

    GetUnit(gAction.instigator)->state |= US_HAS_MOVED;

    UnitUpdateUsedItem(GetUnit(gAction.instigator), gAction.itemSlot);

    gBattleHits[0].attributes = 0;
    gBattleHits[0].info = BATTLE_HIT_INFO_END;
    gBattleHits[0].damage = 0;

    gBattleSt.flags = BATTLE_FLAG_BIT4;

    BeginBattleAnimations();
}

void sub_8027DB4(struct Unit* unit, int item)
{
    gBattleUnitA.weaponBefore = gBattleUnitB.weaponBefore = item;
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

    struct Unit* unit = GetUnit(gAction.instigator);
    int item = GetUnit(gAction.instigator)->items[gAction.itemSlot];

    struct ItemBonuses const* bonuses = GetItemBonuses(item);

    unit->hpMax += bonuses->hp;
    unit->pow += bonuses->pow;
    unit->skl += bonuses->skl;
    unit->spd += bonuses->spd;
    unit->def += bonuses->def;
    unit->res += bonuses->res;
    unit->lck += bonuses->lck;
    unit->movBonus += bonuses->mov;
    unit->conBonus += bonuses->con;

    UnitCheckStatOverflow(unit);

    UnitUpdateUsedItem(unit, gAction.itemSlot);

    switch (GetItemIid(item))
    {

    case IID_SKILLBOOSTER:
        msg = 0xC12; // TODO: msg ids
        break;

    case IID_LUCKBOOSTER:
        msg = 0xC14; // TODO: msg ids
        break;

    case IID_HPBOOSTER:
        msg = 0xC19; // TODO: msg ids
        break;

    case IID_DEFBOOSTER:
        msg = 0xC15; // TODO: msg ids
        break;

    case IID_SPEEDBOOSTER:
        msg = 0xC13; // TODO: msg ids
        break;

    case IID_RESBOOSTER:
        msg = 0xC16; // TODO: msg ids
        break;

    case IID_MOVBOOSTER:
        msg = 0xC17; // TODO: msg ids
        break;

    case IID_CONBOOSTER:
        msg = 0xC18; // TODO: msg ids
        break;

    case IID_POWBOOSTER:
        msg = UnitKnowsMagic(unit) ? 0xC11 : 0xC10; // TODO: msg ids
        break;

    }

    PlaySe(SONG_5A);

    sub_801DA54(proc, GetItemIcon(item), DecodeMsg(msg));
}

void DoItemAction(ProcPtr proc)
{
    int iid = GetItemIid(GetUnit(gAction.instigator)->items[gAction.itemSlot]);

    gBattleUnitA.hasItemEffectTarget = FALSE;

    switch (iid)
    {

    case IID_HEALSTAFF:
    case IID_MENDSTAFF:
    case IID_RECOVERSTAFF:
    case IID_PHYSICSTAFF:
    case IID_TINASTAFF:
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

    case IID_REPAIRSTAFF:
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
    case IID_ORIONBOLT:
    case IID_ELYSIANWHIP:
    case IID_GUIDINGRING:
        DoItemPromoteAction();
        break;

    case IID_SKILLBOOSTER:
    case IID_LUCKBOOSTER:
    case IID_HPBOOSTER:
    case IID_DEFBOOSTER:
    case IID_POWBOOSTER:
    case IID_SPEEDBOOSTER:
    case IID_RESBOOSTER:
    case IID_MOVBOOSTER:
    case IID_CONBOOSTER:
        DoItemStatBoostAction(proc);
        break;

    case IID_SAINTSTAFF:
        DoItemSaintStaffAction(proc);
        break;

    }

    if (gBattleUnitB.statusOut >= 0)
        SpawnProcLocking(ProcScr_ApplyStatusChange, proc);
}

static void ApplyStatusChange(ProcPtr proc)
{
    if (gBattleUnitB.statusOut >= 0)
    {
        SetUnitStatus(GetUnit(gAction.target), gBattleUnitB.statusOut);
        gBattleUnitB.statusOut = -1;
    }
}
