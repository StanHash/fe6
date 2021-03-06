
#include "target-list.h"
#include "common.h"

#include "random.h"
#include "item.h"
#include "unit.h"
#include "map.h"
#include "mapwork.h"
#include "faction.h"
#include "map-select.h"
#include "support.h"
#include "trap.h"

#include "constants/terrains.h"

struct Unit* EWRAM_DATA gSubjectUnit = NULL;

void ForEachUnitInMovement(void(*func)(struct Unit* unit))
{
    int ix, iy;

    for (iy = gMapSize.y-1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x-1; ix >= 0; --ix)
        {
            if (gMapMovementSigned[iy][ix] == 0)
                continue;

            if (gMapUnit[iy][ix] == 0)
                continue;

            func(GetUnit(gMapUnit[iy][ix]));
        }
    }
}

void ForEachUnitInRange(void(*func)(struct Unit* unit))
{
    int ix, iy;

    for (iy = gMapSize.y-1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x-1; ix >= 0; --ix)
        {
            if (gMapRangeSigned[iy][ix] == 0)
                continue;

            if (gMapUnit[iy][ix] == 0)
                continue;

            func(GetUnit(gMapUnit[iy][ix]));
        }
    }
}

void ForEachPositionInRange(void(*func)(int x, int y))
{
    int ix, iy;

    for (iy = gMapSize.y-1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x-1; ix >= 0; --ix)
        {
            if (gMapRangeSigned[iy][ix] == 0)
                continue;

            func(ix, iy);
        }
    }
}

static void ListAdjacentTargetUnits(int x, int y, void(*tryEnlistTarget)(struct Unit* unit))
{
    BeginTargetList(x, y);

    MapAddInRange(x, y, 1, +1);
    MapAddInRange(x, y, 0, -1);

    ForEachUnitInRange(tryEnlistTarget);
}

static void ListAdjacentTargetPositions(int x, int y, void(*tryEnlistTarget)(int x, int y))
{
    BeginTargetList(x, y);

    MapAddInRange(x, y, 1, +1);
    MapAddInRange(x, y, 0, -1);

    ForEachPositionInRange(tryEnlistTarget);
}

static void ListTargetPositionsWithinTwoSquares(int x, int y, void(*tryEnlistTarget)(int x, int y))
{
    BeginTargetList(x, y);

    MapAddInRange(x, y, 2, +1);
    MapAddInRange(x, y, 0, -1);

    ForEachPositionInRange(tryEnlistTarget);
}

static void ListTargetUnitsWithinSubjectMagRange(void(*tryEnlistTarget)(struct Unit* unit))
{
    int x = gSubjectUnit->x;
    int y = gSubjectUnit->y;

    BeginTargetList(x, y);

    MapAddInRange(x, y, GetUnitMagRange(gSubjectUnit), +1);
    MapAddInRange(x, y, 0, -1);

    ForEachUnitInRange(tryEnlistTarget);
}

void EnlistAttackObstacleTargets(void)
{
    struct Trap* trap;

    for (trap = GetTrap(0); trap->kind != TRAP_NONE; ++trap)
    {
        if (trap->kind != TRAP_OBSTACLE)
            continue;

        if (gMapTerrain[trap->y][trap->x] == TERRAIN_WALL_1B && gMapRangeSigned[trap->y][trap->x] != 0)
            EnlistTarget(trap->x, trap->y, 0, trap->extra);

        if (gMapTerrain[trap->y+1][trap->x] == TERRAIN_WALL_1B && gMapRangeSigned[trap->y+1][trap->x] != 0)
            EnlistTarget(trap->x, trap->y+1, 0, trap->extra);
    }
}

void TryEnlistAttackUnitTarget(struct Unit* unit)
{
    if (!AreUnitIdsAllied(gSubjectUnit->id, unit->id))
        EnlistTarget(unit->x, unit->y, unit->id, 0);
}

void ListAttackTargetsForWeapon(struct Unit* unit, int item)
{
    int x = unit->x;
    int y = unit->y;

    gSubjectUnit = unit;

    BeginTargetList(x, y);

    MapFill(gMapRange, 0);
    MapIncInBoundedRange(x, y, GetItemMinRange(item), GetItemMaxRange(item));

    ForEachUnitInRange(TryEnlistAttackUnitTarget);
    EnlistAttackObstacleTargets();
}

void TryEnlistTradeUnitTarget(struct Unit* unit)
{
    if (!AreUnitIdsSameFaction(gSubjectUnit->id, unit->id))
        return;

    if (unit->status == UNIT_STATUS_BERSERK)
        return;

    if (gSubjectUnit->items[0] == 0 && unit->items[0] == 0)
        return;

    EnlistTarget(unit->x, unit->y, unit->id, 0);

    if (unit->state & US_RESCUING)
    {
        int rescue = unit->rescue;

        if ((rescue & 0xC0) == FACTION_BLUE)
            EnlistTarget(unit->x, unit->y, unit->rescue, 0);
    }
}

void ListTradeTargets(struct Unit* unit)
{
    int x = unit->x;
    int y = unit->y;

    gSubjectUnit = unit;

    MapFill(gMapRange, 0);
    ListAdjacentTargetUnits(x, y, TryEnlistTradeUnitTarget);

    if (gSubjectUnit->state & US_RESCUING)
    {
        int count = CountTargets();

        TryEnlistTradeUnitTarget(GetUnit(gSubjectUnit->rescue));

        if (count != CountTargets())
        {
            GetTarget(count)->x = gSubjectUnit->x;
            GetTarget(count)->y = gSubjectUnit->y;
        }
    }
}

void TryEnlistRescueUnitTarget(struct Unit* unit)
{
    if (!AreUnitIdsAllied(gSubjectUnit->id, unit->id))
        return;

    if (unit->status == UNIT_STATUS_BERSERK)
        return;

    if (unit->state & (US_RESCUING | US_RESCUED))
        return;

    if (!CanUnitCarry(gSubjectUnit, unit))
        return;

    EnlistTarget(unit->x, unit->y, unit->id, 0);
}

void ListRescueTargets(struct Unit* unit)
{
    int x = unit->x;
    int y = unit->y;

    gSubjectUnit = unit;

    MapFill(gMapRange, 0);
    ListAdjacentTargetUnits(x, y, TryEnlistRescueUnitTarget);
}

void TryEnlistRescueDropPositionTarget(int x, int y)
{
    if (gMapUnit[y][x] != 0)
        return;

    if (!CanUnitCrossTerrain(GetUnit(gSubjectUnit->rescue), gMapTerrain[y][x]))
        return;

    EnlistTarget(x, y, 0, 0);
}

void ListRescueDropTargets(struct Unit* unit)
{
    int x = unit->x;
    int y = unit->y;

    gSubjectUnit = unit;

    MapFill(gMapRange, 0);
    ListAdjacentTargetPositions(x, y, TryEnlistRescueDropPositionTarget);
}

void TryEnlistRescueTakeUnitTarget(struct Unit* unit)
{
    if (!AreUnitIdsSameFaction(gSubjectUnit->id, unit->id))
        return;

    if (!(unit->state & US_RESCUING))
        return;

    if (!CanUnitCarry(gSubjectUnit, GetUnit(unit->rescue)))
        return;

    EnlistTarget(unit->x, unit->y, unit->id, 0);
}

void ListRescueTakeTargets(struct Unit* unit)
{
    int x = unit->x;
    int y = unit->y;

    gSubjectUnit = unit;

    MapFill(gMapRange, 0);
    ListAdjacentTargetUnits(x, y, TryEnlistRescueTakeUnitTarget);
}

void TryEnlistRescueGiveUnitTarget(struct Unit* unit)
{
    if (!AreUnitIdsSameFaction(gSubjectUnit->id, unit->id))
        return;

    if (unit->state & US_RESCUING)
        return;

    if (unit->status == UNIT_STATUS_BERSERK || unit->status == UNIT_STATUS_SLEEP)
        return;

    if (!CanUnitCarry(unit, GetUnit(gSubjectUnit->rescue)))
        return;

    EnlistTarget(unit->x, unit->y, unit->id, 0);
}

void ListRescueGiveTargets(struct Unit* unit)
{
    int x = unit->x;
    int y = unit->y;

    gSubjectUnit = unit;

    MapFill(gMapRange, 0);
    ListAdjacentTargetUnits(x, y, TryEnlistRescueGiveUnitTarget);
}

void TryEnlistTalkUnitTarget(struct Unit* unit)
{
    if (unit->status == UNIT_STATUS_BERSERK || unit->status == UNIT_STATUS_SLEEP)
        return;

    if (!sub_806AF4C(gSubjectUnit->person->id, unit->person->id))
        return;

    EnlistTarget(unit->x, unit->y, unit->id, unit->person->id);
}

void ListTalkTargets(struct Unit* unit)
{
    int x = unit->x;
    int y = unit->y;

    gSubjectUnit = unit;

    MapFill(gMapRange, 0);
    ListAdjacentTargetUnits(x, y, TryEnlistTalkUnitTarget);
}

void ListSupportTargets(struct Unit* unit)
{
    int i, count;

    gSubjectUnit = unit;

    BeginTargetList(unit->x, unit->y);

    count = GetUnitSupportCount(gSubjectUnit);

    for (i = 0; i < count; ++i)
    {
        struct Unit* other = GetUnitSupportUnit(gSubjectUnit, i);

        if (!other)
            continue;

        if (RECT_DISTANCE(gSubjectUnit->x, gSubjectUnit->y, other->x, other->y) != 1)
            continue;

        if (!CanUnitSupportNow(gSubjectUnit, i))
            continue;

        if (other->state & (US_UNAVAILABLE | US_RESCUED))
            continue;

        if (other->status == UNIT_STATUS_BERSERK || other->status == UNIT_STATUS_SLEEP)
            continue;

        EnlistTarget(other->x, other->y, other->id, i);
    }
}

void sub_8021240(struct Unit* unit)
{
    if (AreUnitIdsAllied(gSubjectUnit->id, unit->id))
        return;

    EnlistTarget(unit->x, unit->y, unit->id, 1);
}

void sub_8021278(struct Unit* unit)
{
    int item;

    int x = unit->x;
    int y = unit->y;

    gSubjectUnit = unit;

    BeginTargetList(x, y);

    item = GetDummyBallistaItemAt(x, y);

    if (item != 0)
    {
        MapFill(gMapRange, 0);
        MapIncInBoundedRange(x, y, GetItemMinRange(item), GetItemMaxRange(item));

        ForEachUnitInRange(sub_8021240);
    }
}

void TryEnlistDoorPositionTarget(int x, int y)
{
    if (gMapTerrain[y][x] != TERRAIN_DOOR)
        return;

    if (!sub_806B37C(x, y))
        return;

    EnlistTarget(x, y, TERRAIN_DOOR, 0);
}

void TryEnlistBridgePositionTarget(int x, int y)
{
    if (gMapTerrain[y][x] != TERRAIN_BRIDGE_14)
        return;

    if (!sub_806B37C(x, y))
        return;

    EnlistTarget(x, y, TERRAIN_BRIDGE_14, 0);
}

void ListOpenTerrainTargets(struct Unit* unit, int terrain)
{
    int x = unit->x;
    int y = unit->y;

    gSubjectUnit = unit;

    MapFill(gMapRange, 0);

    switch (terrain)
    {

    case TERRAIN_DOOR:
        ListAdjacentTargetPositions(x, y, TryEnlistDoorPositionTarget);
        break;

    case TERRAIN_BRIDGE_14:
        ListAdjacentTargetPositions(x, y, TryEnlistBridgePositionTarget);
        break;

    }
}

void ListTerrainHealingTargets(int faction)
{
    int i;

    BeginTargetList(0, 0);

    for (i = faction + 1; i < faction + 0x40; ++i)
    {
        struct Unit* unit = GetUnit(i);

        int terrain;

        if (!unit)
            continue;

        if (!unit->person)
            continue;

        if (unit->state & (US_UNAVAILABLE | US_RESCUED))
            continue;

        terrain = gMapTerrain[unit->y][unit->x];

        if ((GetTerrainHealAmount(terrain) != 0) && (GetUnitCurrentHp(unit) != GetUnitMaxHp(unit)))
        {
            int heal = GetTerrainHealAmount(terrain) * GetUnitMaxHp(unit) / 100;
            EnlistTarget(unit->x, unit->y, unit->id, heal);
        }

        if (DoesTerrainHealStatus(terrain) && unit->status != UNIT_STATUS_NONE)
            EnlistTarget(unit->x, unit->y, unit->id, -1);
    }
}

void ListPoisonDamageTargets(int faction)
{
    int i;

    BeginTargetList(0, 0);

    for (i = faction + 1; i < faction + 0x40; ++i)
    {
        struct Unit* unit = GetUnit(i);

        int terrain;

        if (!unit)
            continue;

        if (!unit->person)
            continue;

        if (unit->state & (US_UNAVAILABLE | US_RESCUED))
            continue;

        if (unit->status != UNIT_STATUS_POISON)
            continue;

        EnlistTarget(unit->x, unit->y, unit->id, 1 + RandNext(3));
    }
}

void TryEnlistRefreshUnitTarget(struct Unit* unit)
{
    if (!AreUnitIdsSameFaction(gSubjectUnit->id, unit->id))
        return;

    if (!(unit->state & US_TURN_ENDED))
        return;

    EnlistTarget(unit->x, unit->y, unit->id, 0);
}

void ListRefreshTargets(struct Unit* unit)
{
    int x = unit->x;
    int y = unit->y;

    gSubjectUnit = unit;

    MapFill(gMapRange, 0);
    ListAdjacentTargetUnits(x, y, TryEnlistRefreshUnitTarget);
}

void TryEnlistStealUnitTarget(struct Unit* unit)
{
    int i;

    if (UNIT_FACTION(unit) != FACTION_RED)
        return;

    for (i = 0; i < ITEMSLOT_INV_COUNT; ++i)
    {
        if (IsItemStealable(unit->items[i]))
        {
            EnlistTarget(unit->x, unit->y, unit->id, 0);
            return;
        }
    }
}

void ListStealTargets(struct Unit* unit)
{
    int x = unit->x;
    int y = unit->y;

    gSubjectUnit = unit;

    MapFill(gMapRange, 0);
    ListAdjacentTargetUnits(x, y, TryEnlistStealUnitTarget);
}

void TryEnlistHealUnitTarget(struct Unit* unit)
{
    if (!AreUnitIdsAllied(gSubjectUnit->id, unit->id))
        return;

    if (unit->state & US_RESCUED)
        return;

    if (GetUnitCurrentHp(unit) == GetUnitMaxHp(unit))
        return;

    EnlistTarget(unit->x, unit->y, unit->id, 0);
}

void ListAdjacentHealTargets(struct Unit* unit)
{
    int x = unit->x;
    int y = unit->y;

    gSubjectUnit = unit;

    MapFill(gMapRange, 0);
    ListAdjacentTargetUnits(x, y, TryEnlistHealUnitTarget);
}

void ListRangedHealTargets(struct Unit* unit)
{
    int x = unit->x;
    int y = unit->y;

    gSubjectUnit = unit;

    BeginTargetList(x, y);

    MapFill(gMapRange, 0);
    MapAddInRange(x, y, GetUnitMagRange(gSubjectUnit), +1);

    ForEachUnitInRange(TryEnlistHealUnitTarget);
}

void TryEnlistRestoreUnitTarget(struct Unit* unit)
{
    if (!AreUnitIdsAllied(gSubjectUnit->id, unit->id))
        return;

    if (unit->state & US_RESCUED)
        return;

    if (unit->status == UNIT_STATUS_NONE)
        return;

    EnlistTarget(unit->x, unit->y, unit->id, 0);
}

void ListRestoreTargets(struct Unit* unit)
{
    int x = unit->x;
    int y = unit->y;

    gSubjectUnit = unit;

    MapFill(gMapRange, 0);
    ListAdjacentTargetUnits(x, y, TryEnlistRestoreUnitTarget);
}

void TryEnlistBarrierUnitTarget(struct Unit* unit)
{
    if (!AreUnitIdsAllied(gSubjectUnit->id, unit->id))
        return;

    if (unit->state & US_RESCUED)
        return;

    if (unit->barrier >= 7) // TODO: barrier max amount constant
        return;

    EnlistTarget(unit->x, unit->y, unit->id, 0);
}

void ListBarrierTargets(struct Unit* unit)
{
    int x = unit->x;
    int y = unit->y;

    gSubjectUnit = unit;

    MapFill(gMapRange, 0);
    ListAdjacentTargetUnits(x, y, TryEnlistBarrierUnitTarget);
}

void TryEnlistRescueStaffUnitTarget(struct Unit* unit)
{
    if (!AreUnitIdsAllied(gSubjectUnit->id, unit->id))
        return;

    EnlistTarget(unit->x, unit->y, unit->id, 0);
}

void ListRescueStaffTargets(struct Unit* unit)
{
    gSubjectUnit = unit;

    MapFill(gMapRange, 0);
    ListTargetUnitsWithinSubjectMagRange(TryEnlistRescueStaffUnitTarget);
}

void TryEnlistSilenceUnitTarget(struct Unit* unit)
{
    if (AreUnitIdsAllied(gSubjectUnit->id, unit->id))
        return;

    if (unit->status != UNIT_STATUS_NONE && unit->status != UNIT_STATUS_SILENCED)
        return;

    EnlistTarget(unit->x, unit->y, unit->id, 0);
}

void TryEnlistSleepUnitTarget(struct Unit* unit)
{
    if (AreUnitIdsAllied(gSubjectUnit->id, unit->id))
        return;

    if (unit->status != UNIT_STATUS_NONE && unit->status != UNIT_STATUS_SLEEP)
        return;

    EnlistTarget(unit->x, unit->y, unit->id, 0);
}

void TryEnlistBerserkUnitTarget(struct Unit* unit)
{
    if (AreUnitIdsAllied(gSubjectUnit->id, unit->id))
        return;

    if (unit->status != UNIT_STATUS_NONE && unit->status != UNIT_STATUS_BERSERK)
        return;

    EnlistTarget(unit->x, unit->y, unit->id, 0);
}

void ListSilenceTargets(struct Unit* unit)
{
    gSubjectUnit = unit;

    MapFill(gMapRange, 0);
    ListTargetUnitsWithinSubjectMagRange(TryEnlistSilenceUnitTarget);
}

void ListSleepTargets(struct Unit* unit)
{
    gSubjectUnit = unit;

    MapFill(gMapRange, 0);
    ListTargetUnitsWithinSubjectMagRange(TryEnlistSleepUnitTarget);
}

void ListBerserkTargets(struct Unit* unit)
{
    gSubjectUnit = unit;

    MapFill(gMapRange, 0);
    ListTargetUnitsWithinSubjectMagRange(TryEnlistBerserkUnitTarget);
}

void TryEnlistWarpUnitTarget(struct Unit* unit)
{
    if (!AreUnitIdsAllied(gSubjectUnit->id, unit->id))
        return;

    EnlistTarget(unit->x, unit->y, unit->id, 0);
}

void ListWarpTargets(struct Unit* unit)
{
    int x = unit->x;
    int y = unit->y;

    gSubjectUnit = unit;

    MapFill(gMapRange, 0);
    ListAdjacentTargetUnits(x, y, TryEnlistWarpUnitTarget);
}

void ListUnlockTargets(struct Unit* unit)
{
    int x = unit->x;
    int y = unit->y;

    gSubjectUnit = unit;

    MapFill(gMapRange, 0);
    ListTargetPositionsWithinTwoSquares(x, y, TryEnlistDoorPositionTarget);
}

void TryEnlistRepairUnitTarget(struct Unit* unit)
{
    int i;

    if (!AreUnitIdsSameFaction(gSubjectUnit->id, unit->id))
        return;

    for (i = 0; i < ITEMSLOT_INV_COUNT; ++i)
    {
        if (IsItemRepairable(unit->items[i]))
        {
            EnlistTarget(unit->x, unit->y, unit->id, 0);
            break;
        }
    }
}

void ListRepairTargets(struct Unit* unit)
{
    int x = unit->x;
    int y = unit->y;

    gSubjectUnit = unit;

    MapFill(gMapRange, 0);
    ListAdjacentTargetUnits(x, y, TryEnlistRepairUnitTarget);
}

void ListSaintsStaffTargets(struct Unit* unit)
{
    int i, alliance;

    BeginTargetList(unit->x, unit->y);

    alliance = GetActiveFactionAlliance();

    for (i = alliance + 1; i < alliance + 0x80; ++i)
    {
        struct Unit* other = GetUnit(i);

        if (!other)
            continue;

        if (!other->person)
            continue;

        if (other->state & US_UNAVAILABLE)
            continue;

        if (GetUnitCurrentHp(other) != GetUnitMaxHp(other) || other->status != UNIT_STATUS_NONE)
        {
            if (other == unit)
                continue;

            EnlistTarget(other->x, other->y, other->id, 0);
        }
    }
}

void sub_8021B30(int arg_0)
{
    int i, count = CountTargets();

    for (i = 0; i < count; ++i)
    {
        struct SelectTarget* target = GetTarget(i);
        struct Unit* other = GetUnit(target->uid);

        if (GetUnitCurrentHp(other) <= target->extra)
        {
            sub_8084AEC(other->person->id, 0, arg_0);
            sub_8084A10(other->person->id);
        }
    }
}
