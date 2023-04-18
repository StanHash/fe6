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
    #define BATTLE_HIT_INFO_ACTOR(n) ((n) << 3)

    BATTLE_HIT_INFO_BEGIN        = (1 << 0),
    BATTLE_HIT_INFO_FINISHES     = (1 << 1),
    BATTLE_HIT_INFO_KILLS_TARGET = (1 << 2),
    BATTLE_HIT_INFO_ACTORB       = (1 << 3),
    BATTLE_HIT_INFO_END          = (1 << 7),
};

struct BattleSt
{
    /* 00 */ u8 range;
    /* 01 */ u8 flags;
    /* 02 */ i16 damage;
    /* 04 */ i16 attack;
    /* 06 */ i16 defense;
    /* 08 */ i16 hit;
    /* 0A */ i16 crit;
    /* 0C */ struct Unit * ta_unit_a;
    /* 10 */ struct Unit * ta_unit_b;
};

struct BattleUnit
{
    /* 00 */ struct Unit unit;

    /* 48 */ u16 weapon;
    /* 4A */ u16 weapon_before;
    /* 4C */ u16 weapon_attributes;
    /* 4E */ u8 weapon_kind;
    /* 4F */ u8 weapon_inventory_slot;
    /* 50 */ bool8 has_inventory_weapon;

    /* 51 */ i8 advantage_bonus_hit;
    /* 52 */ i8 advantage_bonus_damage;

    /* 53 */ u8 terrain;
    /* 54 */ i8 terrain_defense;
    /* 55 */ i8 terrain_avoid;
    /* 56 */ i8 terrain_resistance;
    /* 57 */ // pad?

    /* 58 */ i16 battle_attack;
    /* 5A */ i16 battle_defense;
    /* 5C */ i16 battle_speed;
    /* 5E */ i16 battle_hit;
    /* 60 */ i16 battle_avoid;
    /* 62 */ i16 battle_effective_hit;
    /* 64 */ i16 battle_crit;
    /* 66 */ i16 battle_dodge;
    /* 68 */ i16 battle_effective_crit;

    /* 6A */ i8 exp_gain;
    /* 6B */ i8 output_status;
    /* 6C */ i8 previous_level;
    /* 6D */ i8 previous_exp;
    /* 6E */ i8 previous_hp;

    /* 6F */ i8 change_hp;
    /* 70 */ i8 change_pow;
    /* 71 */ i8 change_skl;
    /* 72 */ i8 change_spd;
    /* 73 */ i8 change_def;
    /* 74 */ i8 change_res;
    /* 75 */ i8 change_lck;
    /* 76 */ i8 change_con;

    /* 77 */ i8 wexp_gain;
    /* 78 */ bool8 dealt_damage;
    /* 79 */ bool8 weapon_broke;

    /* 7A */ bool8 has_item_effect_target;
    /* 7B */ /* pad */
};

struct BattleHit
{
    u16 attributes;
    u8 info;
    i8 damage;
};

void BattleGenerateSimulationInternal(struct Unit * instigator, struct Unit * target, int x, int y, int item_slot);
void BattleGenerateRealInternal(struct Unit * instigator, struct Unit * target);
void BattleApplyGameStateUpdates(void);
void BattleGenerateSimulation(struct Unit * unit, struct Unit * target, int x, int y, int item_slot);
void BattleGenerateReal(struct Unit * instigator, struct Unit * target);
void BattleGenerateBallistaSimulation(struct Unit * unit, struct Unit * target, int x, int y);
void BattleGenerateBallistaReal(struct Unit * instigator, struct Unit * target);
void BattleGenerate(struct Unit * instigator, struct Unit * target);
void BattleGenerateDisplayStats(struct Unit * unit, i8 item_slot);
bool BattleRandRoll(u16 threshold, bool simResult);
bool BattleRandRoll2Rn(u16 threshold, bool simResult);
void InitBattleUnit(struct BattleUnit * bu, struct Unit * unit);
void InitBattleUnitWithoutBonuses(struct BattleUnit * bu, struct Unit * unit);
void SetBattleUnitTerrainBonuses(struct BattleUnit * bu, int terrain);
void SetBattleUnitTerrainBonusesAuto(struct BattleUnit * bu);
void SetBattleUnitWeapon(struct BattleUnit * bu, int item_slot);
void SetBattleUnitWeaponBallista(struct BattleUnit * bu);
void ComputeBattleUnitStats(struct BattleUnit * attacker, struct BattleUnit * defender);
void ComputeBattleUnitEffectiveStats(struct BattleUnit * attacker, struct BattleUnit * defender);
void ComputeBattleUnitSupportBonuses(struct BattleUnit * attacker, struct BattleUnit * defender);
void ComputeBattleUnitDefense(struct BattleUnit * attacker, struct BattleUnit * defender);
void ComputeBattleUnitBaseDefense(struct BattleUnit * bu);
void ComputeBattleUnitAttack(struct BattleUnit * attacker, struct BattleUnit * defender);
void ComputeBattleUnitSpeed(struct BattleUnit * attacker);
void ComputeBattleUnitHitRate(struct BattleUnit * attacker);
void ComputeBattleUnitAvoidRate(struct BattleUnit * attacker);
void ComputeBattleUnitCritRate(struct BattleUnit * attacker);
void ComputeBattleUnitDodgeRate(struct BattleUnit * attacker);
void ComputeBattleUnitEffectiveHitRate(struct BattleUnit * attacker, struct BattleUnit * defender);
void ComputeBattleUnitEffectiveCritRate(struct BattleUnit * attacker, struct BattleUnit * defender);
void ComputeBattleUnitSpecialWeaponStats(struct BattleUnit * attacker, struct BattleUnit * defender);
void ClearBattleHits(void);
void BattleUnwind(void);
void BattleGetBattleUnitOrder(struct BattleUnit ** attacker, struct BattleUnit ** defender);
bool BattleGetFollowUpOrder(struct BattleUnit ** attacker, struct BattleUnit ** defender);
bool BattleGenerateRoundHits(struct BattleUnit * attacker, struct BattleUnit * defender);
int GetBattleUnitHitCount(struct BattleUnit * attacker);
int BattleCheckBraveEffect(struct BattleUnit * attacker);
bool BattleCheckTriangleAttack(struct BattleUnit * attacker, struct BattleUnit * defender);
void BattleUpdateBattleStats(struct BattleUnit * attacker, struct BattleUnit * defender);
void BattleGenerateHitAttributes(struct BattleUnit * attacker);
void BattleGenerateHitTriangleAttack(struct BattleUnit * attacker, struct BattleUnit * defender);
void BattleGenerateHitEffects(struct BattleUnit * attacker, struct BattleUnit * defender);
bool BattleGenerateHit(struct BattleUnit * attacker, struct BattleUnit * defender);
void BattleApplyExpGains(void);
int GetStatIncrease(int growth);
int GetAutoleveledStatIncrease(int growth, int levelCount);
void CheckBattleUnitLevelUp(struct BattleUnit * bu);
void UnitPromote(struct Unit * unit);
void GenerateBattleUnitStatGainsComparatively(struct BattleUnit * bu, struct Unit * unit);
void CheckBattleUnitStatCaps(struct Unit * unit, struct BattleUnit * bu);
void BattleApplyUnitUpdates(void);
int GetBattleUnitUpdatedWeaponExp(struct BattleUnit * bu);
bool HasBattleUnitGainedWeaponLevel(struct BattleUnit * bu);
void UpdateUnitFromBattle(struct Unit * unit, struct BattleUnit * bu);
void UpdateUnitDuringBattle(struct Unit * unit, struct BattleUnit * bu);
void BattleApplyBallistaUpdates(void);
void func_fe6_08025780(void);
int GetUnitExpLevel(struct Unit * unit);
int GetUnitRoundExp(struct Unit * unit, struct Unit * other);
int GetUnitPowerLevel(struct Unit * unit);
int GetUnitClassKillExpBonus(struct Unit * unit, struct Unit * defeated);
int GetUnitKillExpBonus(struct Unit * unit, struct Unit * other);
int GetBattleUnitExpGain(struct BattleUnit * bu, struct BattleUnit * other);
void BattleApplyItemExpGains(void);
int GetBattleUnitStaffExp(struct BattleUnit * bu);
void BattleApplyMiscActionExpGains(void);
void BattleUnitTargetSetEquippedWeapon(struct BattleUnit * bu);
void BattleUnitTargetCheckCanCounter(struct BattleUnit * bu);
void BattleApplyReaverEffect(struct BattleUnit * attacker, struct BattleUnit * defender);
void BattleApplyWeaponTriangleEffect(struct BattleUnit * instigator, struct BattleUnit * target);
void BattleInitTargetCanCounter(void);
void InitObstacleBattleUnit(void);
void ComputeBattleObstacleStats(void);
void UpdateObstacleFromBattle(struct BattleUnit * bu);
void BeginBattleAnimations(void);
int GetUnitSoloBattleAnimType(struct Unit * unit);
int GetBattleAnimType(void);
void BattlePrintDebugUnitInfo(struct BattleUnit * instigator, struct BattleUnit * target);
void BattlePrintDebugHitInfo(void);
void BattleInitItemEffect(struct Unit * instigator, int item_slot);
void BattleInitItemEffectTarget(struct Unit * unit);
void BattleApplyMiscAction(ProcPtr proc);
void BattleApplyItemEffect(ProcPtr proc);
int GetOffensiveStaffAccuracy(struct Unit * unit, struct Unit * target);
void BattleGenerateArena(struct Unit * unit);
bool BattleIsTriangleAttack(void);
bool DidBattleUnitBreakWeapon(struct BattleUnit * bu);
void BattleHitAdvance(void);
void BattleHitTerminate(void);

extern struct BattleSt gBattleSt;

extern struct BattleUnit gBattleUnitA;
extern struct BattleUnit gBattleUnitB;

extern struct BattleHit gBattleHits[];
extern struct BattleHit * gBattleHitIt;

#define CanBattleUnitGainExp(bu) ((bu)->unit.exp != 0xFF)
