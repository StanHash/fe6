
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

        if (!unit->person)
            continue;

        if (unit->state & (US_TURN_ENDED | US_DEAD | US_NOT_DEPLOYED | US_RESCUED | US_UNDER_A_ROOF))
            continue;

        if (unit->status == UNIT_STATUS_SLEEP || unit->status == UNIT_STATUS_BERSERK)
            continue;

        count++;
    }

    return count;
}

int CountFactionUnitsWithoutState(int faction, int prohibitedState)
{
    int i, count = 0;

    for (i = faction + 1; i < faction + 0x40; ++i)
    {
        struct Unit* unit = GetUnit(i);

        if (!unit)
            continue;

        if (!unit->person)
            continue;

        if (unit->state & prohibitedState)
            continue;

        count++;
    }

    return count;
}

Bool AreUnitIdsAllied(int uidA, int uidB)
{
    uidA &= 0x80;
    uidB &= 0x80;

    return uidA == uidB;
}

Bool AreUnitIdsSameFaction(int uidA, int uidB)
{
    uidA &= 0xC0;
    uidB &= 0xC0;

    return uidA == uidB;
}

u8 GetActiveFactionAlliance(void)
{
    return gPlaySt.faction & 0x80;
}

u8 GetActiveFactionOpposingAlliance(void)
{
    return (gPlaySt.faction & 0x80) ^ 0x80;
}
