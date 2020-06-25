
#pragma once

#include "common.h"

#include "unit.h"

enum
{
    // For use with BattleSt::flags

    BATTLE_FLAG_REAL = (1 << 0),
    BATTLE_FLAG_SIMULATE = (1 << 1),
    BATTLE_FLAG_BIT2 = (1 << 2),
    BATTLE_FLAG_BALLISTA = (1 << 3),
    BATTLE_FLAG_BIT4 = (1 << 4),
    BATTLE_FLAG_ARENA = (1 << 5),
    BATTLE_FLAG_REFRESH = (1 << 6),
    BATTLE_FLAG_MAPANIMS = (1 << 7),
};

enum
{
    BATTLE_HIT_ATTR_CRIT      = (1 << 0),
    BATTLE_HIT_ATTR_MISS      = (1 << 1),
    BATTLE_HIT_ATTR_FOLLOWUP  = (1 << 2),
    BATTLE_HIT_ATTR_RETALIATE = (1 << 3),
    BATTLE_HIT_ATTR_BRAVE     = (1 << 4),
    BATTLE_HIT_ATTR_5         = (1 << 5), // unused?
    BATTLE_HIT_ATTR_POISON    = (1 << 6),
    BATTLE_HIT_ATTR_DEVIL     = (1 << 7),
    BATTLE_HIT_ATTR_HPSTEAL   = (1 << 8),
    BATTLE_HIT_ATTR_ECLIPSE   = (1 << 9),
    BATTLE_HIT_ATTR_TATTACK   = (1 << 10), // triangle attack!
};

enum
{
    BATTLE_HIT_INFO_BEGIN        = (1 << 0),
    BATTLE_HIT_INFO_FINISHES     = (1 << 1),
    BATTLE_HIT_INFO_KILLS_TARGET = (1 << 2),
    BATTLE_HIT_INFO_RETALIATION  = (1 << 3),
    BATTLE_HIT_INFO_END          = (1 << 7),
};

struct BattleSt
{
    /* 00 */ u8 range;
    /* 01 */ u8 flags;
    /* 02 */ short damage;
    /* 04 */ short attack;
    /* 06 */ short defense;
    /* 08 */ short hit;
    /* 0A */ short crit;
    /* 0C */ struct Unit* taUnitA;
    /* 10 */ struct Unit* taUnitB;
};

struct BattleUnit
{
    /* 00 */ struct Unit unit;

    /* 48 */ u16 weapon;
    /* 4A */ u16 weaponBefore;
    /* 4C */ u16 weaponAttributes;
    /* 4E */ u8 weaponKind;
    /* 4F */ u8 weaponItemSlot;

    /* 50 */ Bool canCounter;

    /* 51 */ s8 wtHitBonus;
    /* 52 */ s8 wtDamageBonus;

    /* 53 */ u8 terrain;
    /* 54 */ s8 terrainDefense;
    /* 55 */ s8 terrainAvoid;
    /* 56 */ s8 terrainResistance;
    /* 57 */ // pad?

    /* 58 */ short battleAttack;
    /* 5A */ short battleDefense;
    /* 5C */ short battleSpeed;
    /* 5E */ short battleHit;
    /* 60 */ short battleAvoid;
    /* 62 */ short battleEffectiveHit;
    /* 64 */ short battleCrit;
    /* 66 */ short battleDodge;
    /* 68 */ short battleEffectiveCrit;

    /* 6A */ s8 expGain;
    /* 6B */ s8 statusOut;
    /* 6C */ u8 levelPrevious;
    /* 6D */ u8 expPrevious;
    /* 6E */ u8 hpPrevious;

    /* 6F */ s8 hpChange;
    /* 70 */ s8 powChange;
    /* 71 */ s8 sklChange;
    /* 72 */ s8 spdChange;
    /* 73 */ s8 defChange;
    /* 74 */ s8 resChange;
    /* 75 */ s8 lckChange;
    /* 76 */ s8 conChange;

    /* 77 */ s8 wexpGain;
    /* 78 */ Bool nonZeroDamage;
    /* 79 */ Bool weaponBroke;

    /* 7A */ Bool hasItemEffectTarget;
    /* 7B */ /* pad */
};

struct BattleHit
{
    unsigned attributes : 16;
    unsigned info : 8;
    signed damage : 8;
};

void BattleGenerateSimulationInternal(struct Unit* instigator, struct Unit* target, int x, int y, int itemSlot);
void BattleGenerateRealInternal(struct Unit* instigator, struct Unit* target);
void BattleApplyGameStateUpdates(void);
void BattleGenerateSimulation(struct Unit* unit, struct Unit* target, int x, int y, int itemSlot);
void BattleGenerateReal(struct Unit* instigator, struct Unit* target);
void BattleGenerateBallistaSimulation(struct Unit* unit, struct Unit* target, int x, int y);
void BattleGenerateBallistaReal(struct Unit* instigator, struct Unit* target);
void BattleGenerate(struct Unit* instigator, struct Unit* target);
void BattleGenerateDisplayStats(struct Unit* unit, s8 itemSlot);
Bool BattleRandRoll(u16 threshold, Bool simResult);
Bool BattleRandRoll2Rn(u16 threshold, Bool simResult);
void InitBattleUnit(struct BattleUnit* bu, struct Unit* unit);
void InitBattleUnitWithoutBonuses(struct BattleUnit* bu, struct Unit* unit);
void SetBattleUnitTerrainBonuses(struct BattleUnit* bu, int terrain);
void SetBattleUnitTerrainBonusesAuto(struct BattleUnit* bu);
void SetBattleUnitWeapon(struct BattleUnit* bu, int itemSlot);
void SetBattleUnitWeaponBallista(struct BattleUnit* bu);
void ComputeBattleUnitStats(struct BattleUnit* attacker, struct BattleUnit* defender);
void ComputeBattleUnitEffectiveStats(struct BattleUnit* attacker, struct BattleUnit* defender);
void ComputeBattleUnitSupportBonuses(struct BattleUnit* attacker, struct BattleUnit* defender);
void ComputeBattleUnitDefense(struct BattleUnit* attacker, struct BattleUnit* defender);
void ComputeBattleUnitBaseDefense(struct BattleUnit* bu);
void ComputeBattleUnitAttack(struct BattleUnit* attacker, struct BattleUnit* defender);
void ComputeBattleUnitSpeed(struct BattleUnit* attacker);
void ComputeBattleUnitHitRate(struct BattleUnit* attacker);
void ComputeBattleUnitAvoidRate(struct BattleUnit* attacker);
void ComputeBattleUnitCritRate(struct BattleUnit* attacker);
void ComputeBattleUnitDodgeRate(struct BattleUnit* attacker);
void ComputeBattleUnitEffectiveHitRate(struct BattleUnit* attacker, struct BattleUnit* defender);
void ComputeBattleUnitEffectiveCritRate(struct BattleUnit* attacker, struct BattleUnit* defender);
void ComputeBattleUnitSpecialWeaponStats(struct BattleUnit* attacker, struct BattleUnit* defender);
void ClearBattleHits(void);
void BattleUnwind(void);
void BattleGetBattleUnitOrder(struct BattleUnit** attacker, struct BattleUnit** defender);
Bool BattleGetFollowUpOrder(struct BattleUnit** attacker, struct BattleUnit** defender);
Bool BattleGenerateRoundHits(struct BattleUnit* attacker, struct BattleUnit* defender);
int GetBattleUnitHitCount(struct BattleUnit* attacker);
int BattleCheckBraveEffect(struct BattleUnit* attacker);
Bool BattleCheckTriangleAttack(struct BattleUnit* attacker, struct BattleUnit* defender);
void BattleUpdateBattleStats(struct BattleUnit* attacker, struct BattleUnit* defender);
void BattleGenerateHitAttributes(struct BattleUnit* attacker);
void BattleGenerateHitTriangleAttack(struct BattleUnit* attacker, struct BattleUnit* defender);
void BattleGenerateHitEffects(struct BattleUnit* attacker, struct BattleUnit* defender);
Bool BattleGenerateHit(struct BattleUnit* attacker, struct BattleUnit* defender);
void BattleApplyExpGains(void);
int GetStatIncrease(int growth);
int GetAutoleveledStatIncrease(int growth, int levelCount);
void CheckBattleUnitLevelUp(struct BattleUnit* bu);
void UnitPromote(struct Unit* unit);
void GenerateBattleUnitStatGainsComparatively(struct BattleUnit* bu, struct Unit* unit);
void CheckBattleUnitStatCaps(struct Unit* unit, struct BattleUnit* bu);
void BattleApplyUnitUpdates(void);
int GetBattleUnitUpdatedWeaponExp(struct BattleUnit* bu);
Bool HasBattleUnitGainedWeaponLevel(struct BattleUnit* bu);
void UpdateUnitFromBattle(struct Unit* unit, struct BattleUnit* bu);
void UpdateUnitDuringBattle(struct Unit* unit, struct BattleUnit* bu);
void BattleApplyBallistaUpdates(void);
void sub_8025780(void);
int GetUnitExpLevel(struct Unit* unit);
int GetUnitRoundExp(struct Unit* unit, struct Unit* other);
int GetUnitPowerLevel(struct Unit* unit);
int GetUnitClassKillExpBonus(struct Unit* unit, struct Unit* defeated);
int GetUnitKillExpBonus(struct Unit* unit, struct Unit* other);
int GetBattleUnitExpGain(struct BattleUnit* bu, struct BattleUnit* other);
void BattleApplyItemExpGains(void);
int GetBattleUnitStaffExp(struct BattleUnit* bu);
void BattleApplyMiscActionExpGains(void);
void BattleUnitTargetSetEquippedWeapon(struct BattleUnit* bu);
void BattleUnitTargetCheckCanCounter(struct BattleUnit* bu);
void BattleApplyReaverEffect(struct BattleUnit* attacker, struct BattleUnit* defender);
void BattleApplyWeaponTriangleEffect(struct BattleUnit* instigator, struct BattleUnit* target);
void BattleInitTargetCanCounter(void);
void InitObstacleBattleUnit(void);
void ComputeBattleObstacleStats(void);
void UpdateObstacleFromBattle(struct BattleUnit* bu);
void BeginBattleAnimations(void);
int GetUnitSoloBattleAnimType(struct Unit* unit);
int GetBattleAnimType(void);
void BattlePrintDebugUnitInfo(struct BattleUnit* instigator, struct BattleUnit* target);
void BattlePrintDebugHitInfo(void);
void BattleInitItemEffect(struct Unit* instigator, int itemSlot);
void BattleInitItemEffectTarget(struct Unit* unit);
void BattleApplyMiscAction(ProcPtr proc);
void BattleApplyItemEffect(ProcPtr proc);
int GetOffensiveStaffAccuracy(struct Unit* unit, struct Unit* target);
void BattleGenerateArena(struct Unit* unit);
Bool BattleIsTriangleAttack(void);
Bool DidBattleUnitBreakWeapon(struct BattleUnit* bu);
void BattleHitAdvance(void);
void BattleHitTerminate(void);

extern struct BattleSt gBattleSt;

extern struct BattleUnit gBattleUnitA;
extern struct BattleUnit gBattleUnitB;

extern struct BattleHit gBattleHits[];
extern struct BattleHit* gBattleHitIt;
