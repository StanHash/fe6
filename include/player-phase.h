
#pragma once

#include "common.h"

#include "proc.h"
#include "unit.h"

enum
{
    L_PLAYERPHASE_BEGIN,
    L_PLAYERPHASE_MOVE,
    L_PLAYERPHASE_ACTION_SELECT,
    L_PLAYERPHASE_END,
    L_PLAYERPHASE_MAPFADE_MOVE,
    L_PLAYERPHASE_5,
    L_PLAYERPHASE_6,
    L_PLAYERPHASE_ACTION,
    L_PLAYERPHASE_8,
    L_PLAYERPHASE_IDLE,
    L_PLAYERPHASE_10,
    L_PLAYERPHASE_SEE_RANGE,
};

enum
{
    PLAYER_SELECT_NOUNIT,
    PLAYER_SELECT_TURNENDED,
    PLAYER_SELECT_CONTROL,
    PLAYER_SELECT_NOCONTROL,
    PLAYER_SELECT_4,
};

enum
{
    LIMITVIEW_BLUE = (1 << 0),
    LIMITVIEW_RED = (1 << 1),
    LIMITVIEW_GREEN = (1 << 2),
};

void HandlePlayerMapCursor(void);
void DisplayUnitActionRange(struct Unit* unit);
int GetPlayerSelectKind(struct Unit* unit);
void StartLimitView(int flags);
void EndLimitView(void);
void TrySwitchViewedUnit(int x, int y);

void PlayerPhase_BeginSeeActionRange(ProcPtr proc);
void PlayerPhase_MoveSelectLoop(ProcPtr proc);
Bool PlayerPhase_0801B9B0(ProcPtr proc);
void PlayerPhase_0801BC84(ProcPtr proc);

extern struct ProcScr CONST_DATA ProcScr_PlayerPhase[];
