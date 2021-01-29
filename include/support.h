
#pragma once

#include "common.h"

#include "unit.h"

enum
{
    SUPPORT_LEVEL_NONE,
    SUPPORT_LEVEL_C,
    SUPPORT_LEVEL_B,
    SUPPORT_LEVEL_A,
};

enum
{
    SUPPORT_EXP_C = 61,
    SUPPORT_EXP_B = 121,
    SUPPORT_EXP_A = 201,
};

struct SupportInfo
{
    /* 00 */ u8 pids[UNIT_SUPPORT_COUNT];
    /* 0A */ u8 expBase[UNIT_SUPPORT_COUNT];
    /* 14 */ u8 expGrowth[UNIT_SUPPORT_COUNT];
    /* 1E */ u8 count;
};

struct SupportBonuses
{
    /* 00 */ u8 affinity;

    /* 01 */ u8 bonusAttack;
    /* 02 */ u8 bonusDefense;
    /* 03 */ u8 bonusHit;
    /* 04 */ u8 bonusAvoid;
    /* 05 */ u8 bonusCrit;
    /* 06 */ u8 bonusDodge;
};

int GetUnitSupportCount(struct Unit* unit);
u8 GetUnitSupportPid(struct Unit* unit, int num);
struct Unit* GetUnitSupportUnit(struct Unit* unit, int num);
int GetUnitSupportLevel(struct Unit* unit, int num);
int GetUnitTotalSupportLevel(struct Unit* unit);
void UnitGainSupportExp(struct Unit* unit, int num);
void UnitGainSupportLevel(struct Unit* unit, int num);
bool CanUnitSupportNow(struct Unit* unit, int num);
int GetUnitInitialSupportExp(struct Unit* unit, int num);
int GetUnitSupportNumByPid(struct Unit* unit, u8 pid);
void ClearUnitSupports(struct Unit* unit);
void DoTurnSupportExp(void);
int GetUnitSupportBonuses(struct Unit* unit, struct SupportBonuses* bonuses);
int GetUnitAffinityIcon(struct Unit* unit);
int GetAffinityIconByPid(int pid);
int GetSupportLevelSpecialChar(int level);
char const* GetAffinityName(int affinity);
