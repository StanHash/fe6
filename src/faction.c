
#include "faction.h"
#include "common.h"

#include "bm.h"
#include "unit.h"

int CountFactionMoveableUnits(int faction)
{
    int i, count = 0;

    for (i = faction + 1; i < faction + 0x40; ++i)
    {
        struct Unit* unit = GetUnit(i);

        if (!unit)
            continue;

        if (!unit->pinfo)
            continue;

        if (unit->flags & (UNIT_FLAG_TURN_ENDED | UNIT_FLAG_DEAD | UNIT_FLAG_NOT_DEPLOYED | UNIT_FLAG_RESCUED | UNIT_FLAG_UNDER_ROOF))
            continue;

        if (unit->status == UNIT_STATUS_SLEEP || unit->status == UNIT_STATUS_BERSERK)
            continue;

        count++;
    }

    return count;
}

int CountFactionUnitsWithoutState(int faction, int prohibited_state)
{
    int i, count = 0;

    for (i = faction + 1; i < faction + 0x40; ++i)
    {
        struct Unit* unit = GetUnit(i);

        if (!unit)
            continue;

        if (!unit->pinfo)
            continue;

        if (unit->flags & prohibited_state)
            continue;

        count++;
    }

    return count;
}

bool AreUnitIdsAllied(int uidA, int uidB)
{
    uidA &= 0x80;
    uidB &= 0x80;

    return uidA == uidB;
}

bool AreUnitIdsSameFaction(int uidA, int uidB)
{
    uidA &= 0xC0;
    uidB &= 0xC0;

    return uidA == uidB;
}

int GetActiveFactionAlliance(void)
{
    return gPlaySt.faction & 0x80;
}

int GetActiveFactionOpposingAlliance(void)
{
    return (gPlaySt.faction & 0x80) ^ 0x80;
}
