
#pragma once

#include "common.h"

enum
{
    TRAP_NONE,

    TRAP_BALLISTA = 1,
    TRAP_LONGBALLISTA = 2,
    TRAP_KILLERBALLISTA = 3,
    TRAP_OBSTACLE = 4,
    TRAP_MAPCHANGE = 5,
    TRAP_FIRE = 6,
    TRAP_GAS = 7,
    TRAP_8 = 8,
    TRAP_LIGHTARROW = 9,
    TRAP_STEP_FIRE = 10,
    TRAP_STEP_PIKE = 11,
    TRAP_STEP_DISARMED = 12,
};

enum
{
    TRAPDATA_TRAP_INITCNT = 0,
    TRAPDATA_TRAP_INTERVAL = 1,
    TRAPDATA_TRAP_COUNTER = 2,
    TRAPDATA_TRAP_DAMAGE = 3,
};

struct Trap
{
    /* 00 */ u8 x, y;
    /* 02 */ u8 kind;
    /* 03 */ u8 extra;
    /* 04 */ s8 data[4];
};

void InitTraps(void);
struct Trap* GetTrap(int id);
struct Trap* GetTrapAt(int x, int y);
struct Trap* AddTrap(int x, int y, int kind, int extra);
struct Trap* AddDamagingTrap(int x, int y, int kind, int extra, int turnCountdown, int turnInterval, int damage);
void AddFireTrap(int x, int y, int turnCountdown, int turnInterval);
void AddGasTrap(int x, int y, int facing, int turnCountdown, int turnInterval);
void AddArrowTrap(int x, int turnCountdown, int turnInterval);
void sub_8026BA4(int x, int y, int turnCountdown, int turnInterval);
void sub_8026BC0(int x, int y);
void sub_8026BD0(int x, int y, int extra);
void InitMapTraps(void);
void ApplyEnabledMapChanges(void);
struct Trap* GetBallistaTrapAt(int x, int y);
int GetBallistaItemAt(int x, int y);
int GetDummyBallistaItemAt(int x, int y);
int GetObstacleHpAt(int x, int y);
struct MapChangeInfo const* GetMapChange(int id);
int GetMapChangeIdAt(int x, int y);
void ApplyMapChange(int id);
void AddMapChangeTrap(int id);
void UnitHideIfUnderRoof(struct Unit* unit);
void UpdateRoofedUnits(void);
void EnlistFireTrapTargets(int x, int y, int damage);
void EnlistArrowTrapTargets(int x, int y, int damage);
void EnlistGasTrapTargets(int x, int y, int damage, int facing);
void ListDamagingTrapTargets(void);
void ListDamagingTrapTargetsForDisplay(void);
Bool DoHandleStepTraps(ProcPtr proc);

extern struct ProcScr CONST_DATA ProcScr_UpdateTraps[];

#define TRAP_ID(trap) ((trap) - GetTrap(0))
