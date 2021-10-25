#pragma once

#include "common.h"

enum
{
    FACTION_BLUE   = 0x00,
    FACTION_RED    = 0x80,
    FACTION_GREEN  = 0x40,
    FACTION_PURPLE = 0xC0,
};

enum
{
    FACTION_ID_BLUE = 0,
    FACTION_ID_GREEN = 1,
    FACTION_ID_RED = 2,
    FACTION_ID_PURPLE = 3,
};

int CountFactionMoveableUnits(int faction);
int CountFactionUnitsWithoutState(int faction, int prohibited_state);
bool AreUnitIdsAllied(int uidA, int uidB);
bool AreUnitIdsSameFaction(int uidA, int uidB);
int GetActiveFactionAlliance(void);
int GetActiveFactionOpposingAlliance(void);
