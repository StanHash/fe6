
#include "common.h"

#include "hardware.h"
#include "item.h"
#include "unit.h"
#include "map.h"
#include "mapwork.h"
#include "target-list.h"
#include "faction.h"
#include "action.h"
#include "eventinfo.h"

#include "constants/terrains.h"

bool func_fe6_0802B814(void)
{
    int ix, iy;

    if (gActiveUnit->flags & UNIT_FLAG_HAD_ACTION)
        return FALSE;

    for (iy = gMapSize.y-1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x-1; ix >= 0; --ix)
        {
            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if (gMapTerrain[iy][ix] != TERRAIN_VILLAGE && gMapTerrain[iy][ix] != TERRAIN_HOUSE)
                continue;

            if (GetAvailableTileEventCommand(ix, iy) == 0x0E)
                return TRUE;
        }
    }

    return FALSE;
}

bool func_fe6_0802B8A0(void)
{
    int ix, iy;

    if (gActiveUnit->flags & UNIT_FLAG_HAD_ACTION)
        return FALSE;

    if (!(UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_LORD))
        return FALSE;

    for (iy = gMapSize.y-1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x-1; ix >= 0; --ix)
        {
            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if (GetAvailableTileEventCommand(ix, iy) == 0x0F)
                return TRUE;
        }
    }

    return FALSE;
}

bool func_fe6_0802B928(void)
{
    BeginTargetList(0, 0);

    BuildUnitCompleteAttackRange(gActiveUnit);

    gSubjectUnit = gActiveUnit;
    ForEachUnitInRange(TryEnlistAttackUnitTarget);

    return CountTargets() != 0 ? TRUE : FALSE;
}

bool func_fe6_0802B964(void)
{
    ListRescueTargets(gActiveUnit);

    return CountTargets() != 0 ? TRUE : FALSE;
}

bool func_fe6_0802B980(void)
{
    ListTradeTargets(gActiveUnit);

    return CountTargets() != 0 ? TRUE : FALSE;
}

int func_fe6_0802B99C(void)
{
    int result = 0;

    GetGameTime(); // ?

    result |= func_fe6_0802B814() << 15;
    result |= func_fe6_0802B8A0() << 16;
    result |= func_fe6_0802B928() << 1;
    result |= func_fe6_0802B964() << 8;
    result |= func_fe6_0802B980() << 23;

    return result;
}

int func_fe6_0802B9DC(void)
{
    MapFlood_08019384(gActiveUnit, UNIT_MOV(gActiveUnit) - gAction.move_count);
    return func_fe6_0802B99C();
}

int func_fe6_0802BA08(void)
{
    MapFill(gMapMovement, -1);
    gMapMovement[gActiveUnit->y][gActiveUnit->x] = 0;

    return func_fe6_0802B99C();
}

void func_fe6_0802BA44(struct Unit * unit)
{
    int ix, iy;

    int reach = GetUnitWeaponReach(unit, -1);

    MapFill(gMapOther, 0);

    FOR_UNITS(FACTION_RED + 1, FACTION_RED + 0x40, unit,
    {
        BuildUnitStandingRangeForReach(unit, reach);

        gAction.x_target = unit->x;
        gAction.y_target = unit->y;
    })

    BeginTargetList(0, 0);

    for (iy = gMapSize.y-1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x-1; ix >= 0; --ix)
        {
            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if (gMapUnit[iy][ix] != 0)
                continue;

            if (gMapOther[iy][ix] == 0)
                continue;

            EnlistTarget(ix, iy, 1, 1);
        }
    }
}
