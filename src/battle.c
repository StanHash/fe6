#include "battle.h"

#include "random.h"
#include "hardware.h"
#include "proc.h"
#include "item.h"
#include "unit.h"
#include "map.h"
#include "bmfx.h"
#include "faction.h"
#include "support.h"
#include "trap.h"
#include "arena.h"
#include "action.h"
#include "chapterinfo.h"
#include "mu.h"
#include "manim.h"
#include "banim.h"
#include "banim_ekrbattle.h"
#include "save_stats.h"
#include "save_game.h"

#include "constants/pids.h"
#include "constants/jids.h"

enum { BATTLE_HIT_MAX = 7 };
enum { BATTLE_MAX_DAMAGE = 99 };

struct WeaponTriangleRule
{
    i8 attackerKind;
    i8 defenderKind;
    i8 hitBonus;
    i8 damageBonus;
};

static struct WeaponTriangleRule CONST_DATA sWeaponTriangleRules[] =
{
    { ITEM_KIND_SWORD, ITEM_KIND_LANCE, -10, -1 },
    { ITEM_KIND_SWORD, ITEM_KIND_AXE,   +10, +1 },

    { ITEM_KIND_LANCE, ITEM_KIND_AXE,   -10, -1 },
    { ITEM_KIND_LANCE, ITEM_KIND_SWORD, +10, +1 },

    { ITEM_KIND_AXE,   ITEM_KIND_SWORD, -10, -1 },
    { ITEM_KIND_AXE,   ITEM_KIND_LANCE, +10, +1 },

    { ITEM_KIND_ANIMA, ITEM_KIND_ELDER, -10, -1 },
    { ITEM_KIND_ANIMA, ITEM_KIND_LIGHT, +10, +1 },

    { ITEM_KIND_LIGHT, ITEM_KIND_ANIMA, -10, -1 },
    { ITEM_KIND_LIGHT, ITEM_KIND_ELDER, +10, +1 },

    { ITEM_KIND_ELDER, ITEM_KIND_LIGHT, -10, -1 },
    { ITEM_KIND_ELDER, ITEM_KIND_ANIMA, +10, +1 },

    { -1 },
};

static void DummyBattleAnimLock_UpdateInstigator(ProcPtr proc);

struct ProcScr ProcScr_DummyBattleAnimLock[] =
{
    PROC_SLEEP(1),
    PROC_CALL(DummyBattleAnimLock_UpdateInstigator),

    PROC_END,
};

struct BattleSt EWRAM_DATA gBattleSt = {};

struct BattleUnit EWRAM_DATA gBattleUnitA = {};
struct BattleUnit EWRAM_DATA gBattleUnitB = {};

struct BattleHit EWRAM_DATA gBattleHits[BATTLE_HIT_MAX] = {};
struct BattleHit * EWRAM_DATA gBattleHitIt = NULL;

void BattleGenerateSimulationInternal(struct Unit * instigator, struct Unit * target, int x, int y, int item_slot)
{
    InitBattleUnit(&gBattleUnitA, instigator);
    InitBattleUnit(&gBattleUnitB, target);

    gBattleUnitA.unit.x = x;
    gBattleUnitA.unit.y = y;

    gBattleSt.range = RECT_DISTANCE(
        gBattleUnitA.unit.x, gBattleUnitA.unit.y,
        gBattleUnitB.unit.x, gBattleUnitB.unit.y);

    if (gBattleSt.flags & BATTLE_FLAG_BALLISTA)
        SetBattleUnitWeaponBallista(&gBattleUnitA);
    else
        SetBattleUnitWeapon(&gBattleUnitA, item_slot);

    SetBattleUnitWeapon(&gBattleUnitB, -1);

    BattleInitTargetCanCounter();
    BattleApplyWeaponTriangleEffect(&gBattleUnitA, &gBattleUnitB);

    SetBattleUnitTerrainBonusesAuto(&gBattleUnitA);
    SetBattleUnitTerrainBonusesAuto(&gBattleUnitB);

    BattleGenerate(instigator, target);
}

void BattleGenerateRealInternal(struct Unit * instigator, struct Unit * target)
{
    InitBattleUnit(&gBattleUnitA, instigator);
    InitBattleUnit(&gBattleUnitB, target);

    gBattleSt.range = RECT_DISTANCE(
        gBattleUnitA.unit.x, gBattleUnitA.unit.y,
        gBattleUnitB.unit.x, gBattleUnitB.unit.y);

    if (gBattleSt.flags & BATTLE_FLAG_BALLISTA)
        SetBattleUnitWeaponBallista(&gBattleUnitA);
    else
        SetBattleUnitWeapon(&gBattleUnitA, -1);

    SetBattleUnitWeapon(&gBattleUnitB, -1);

    BattleInitTargetCanCounter();
    BattleApplyWeaponTriangleEffect(&gBattleUnitA, &gBattleUnitB);

    SetBattleUnitTerrainBonusesAuto(&gBattleUnitA);
    SetBattleUnitTerrainBonusesAuto(&gBattleUnitB);

    BattleGenerate(instigator, target);

    BattleUnitTargetCheckCanCounter(&gBattleUnitB);
    BattleUnitTargetSetEquippedWeapon(&gBattleUnitB);

    if (gBattleUnitB.unit.id != 0)
    {
        BattleApplyExpGains();
        PidStatsUpdateFromBattleOutcome();
        PidStatsAddBattle(instigator);
        PidStatsAddBattle(target);
    }
}

void BattleApplyGameStateUpdates(void)
{
    BattleApplyUnitUpdates();
    BattleApplyBallistaUpdates();

    BattlePrintDebugUnitInfo(&gBattleUnitA, &gBattleUnitB);
    BattlePrintDebugHitInfo();
}

void BattleGenerateSimulation(struct Unit * instigator, struct Unit * target, int x, int y, int item_slot)
{
    if (x < 0 && y < 0)
    {
        x = instigator->x;
        y = instigator->y;
    }

    gBattleSt.flags = BATTLE_FLAG_SIMULATE;
    BattleGenerateSimulationInternal(instigator, target, x, y, item_slot);
}

void BattleGenerateReal(struct Unit * instigator, struct Unit * target)
{
    gBattleSt.flags = BATTLE_FLAG_REAL;
    BattleGenerateRealInternal(instigator, target);
}

void BattleGenerateBallistaSimulation(struct Unit * instigator, struct Unit * target, int x, int y)
{
    gBattleSt.flags = BATTLE_FLAG_SIMULATE | BATTLE_FLAG_BALLISTA;
    BattleGenerateSimulationInternal(instigator, target, x, y, 0);
}

void BattleGenerateBallistaReal(struct Unit * instigator, struct Unit * target)
{
    gBattleSt.flags = BATTLE_FLAG_REAL | BATTLE_FLAG_BALLISTA;
    BattleGenerateRealInternal(instigator, target);
}

void BattleGenerate(struct Unit * instigator, struct Unit * target)
{
    ComputeBattleUnitStats(&gBattleUnitA, &gBattleUnitB);
    ComputeBattleUnitStats(&gBattleUnitB, &gBattleUnitA);

    ComputeBattleUnitEffectiveStats(&gBattleUnitA, &gBattleUnitB);
    ComputeBattleUnitEffectiveStats(&gBattleUnitB, &gBattleUnitA);

    if (target == NULL)
        ComputeBattleObstacleStats();

    BattleUnwind();
}

void BattleGenerateDisplayStats(struct Unit * unit, i8 item_slot)
{
    gBattleSt.flags = BATTLE_FLAG_STATSONLY;

    gBattleUnitB.weapon = 0;
    gBattleUnitB.weapon_attributes = 0;
    gBattleUnitB.weapon_kind = ITEM_KIND_INVALID;

    gBattleUnitB.unit.jinfo = NULL;

    gBattleUnitA.advantage_bonus_hit = 0;
    gBattleUnitA.advantage_bonus_damage = 0;

    InitBattleUnit(&gBattleUnitA, unit);

    SetBattleUnitTerrainBonusesAuto(&gBattleUnitA);

    SetBattleUnitWeapon(&gBattleUnitA, item_slot);
    ComputeBattleUnitStats(&gBattleUnitA, &gBattleUnitB);

    if (!gBattleUnitA.weapon)
    {
        gBattleUnitA.battle_attack = 0xFF;
        gBattleUnitA.battle_hit = 0xFF;
        gBattleUnitA.battle_crit = 0xFF;
    }

    if (GetItemWeaponEffect(gBattleUnitA.weapon) == WEAPON_EFFECT_ECLIPSE)
        gBattleUnitA.battle_attack = 0xFF;
}

bool BattleRandRoll(u16 threshold, bool simulationResult)
{
    if (gBattleSt.flags & BATTLE_FLAG_SIMULATE)
        return simulationResult;

    return RandRoll(threshold);
}

bool BattleRandRoll2Rn(u16 threshold, bool simulationResult)
{
    if (gBattleSt.flags & BATTLE_FLAG_SIMULATE)
        return simulationResult;

    return RandRoll2Rn(threshold);
}

void InitBattleUnit(struct BattleUnit * bu, struct Unit * unit)
{
    if (!unit)
        return;

    bu->unit = *unit;

    bu->unit.max_hp = GetUnitMaxHp(unit);
    bu->unit.pow = GetUnitPower(unit);
    bu->unit.skl = GetUnitSkill(unit);
    bu->unit.spd = GetUnitSpeed(unit);
    bu->unit.def = GetUnitDefense(unit);
    bu->unit.lck = GetUnitLuck(unit);
    bu->unit.res = GetUnitResistance(unit);
    bu->unit.bonus_con = UNIT_CON(unit);
    bu->unit.bonus_mov = UNIT_MOV(unit);

    bu->previous_level = bu->unit.level;
    bu->previous_exp = bu->unit.exp;
    bu->previous_hp = bu->unit.hp;

    bu->output_status = 0xFF;

    bu->change_hp = 0;
    bu->change_pow = 0;
    bu->change_skl = 0;
    bu->change_spd = 0;
    bu->change_def = 0;
    bu->change_res = 0;
    bu->change_lck = 0;
    bu->change_con = 0;

    gBattleUnitA.wexp_gain = 0;
    gBattleUnitB.wexp_gain = 0;

    bu->advantage_bonus_hit = 0;
    bu->advantage_bonus_damage = 0;

    bu->dealt_damage = FALSE;

    gBattleUnitA.weapon_broke = FALSE;
    gBattleUnitB.weapon_broke = FALSE;

    gBattleUnitA.exp_gain = 0;
    gBattleUnitB.exp_gain = 0;
}

void InitBattleUnitWithoutBonuses(struct BattleUnit * bu, struct Unit * unit)
{
    InitBattleUnit(bu, unit);

    bu->unit.max_hp = unit->max_hp;
    bu->unit.pow = unit->pow;
    bu->unit.skl = unit->skl;
    bu->unit.spd = unit->spd;
    bu->unit.def = unit->def;
    bu->unit.lck = unit->lck;
    bu->unit.res = unit->res;
    bu->unit.bonus_con = UNIT_CON_BASE(unit);
}

void SetBattleUnitTerrainBonuses(struct BattleUnit * bu, int terrain)
{
    bu->terrain = terrain;

    bu->terrain_avoid = bu->unit.jinfo->avo_terrain_table[bu->terrain];
    bu->terrain_defense = bu->unit.jinfo->def_terrain_table[bu->terrain];
    bu->terrain_resistance = bu->unit.jinfo->res_terrain_table[bu->terrain];
}

void SetBattleUnitTerrainBonusesAuto(struct BattleUnit * bu)
{
    bu->terrain = gMapTerrain[bu->unit.y][bu->unit.x];

    bu->terrain_avoid = bu->unit.jinfo->avo_terrain_table[bu->terrain];
    bu->terrain_defense = bu->unit.jinfo->def_terrain_table[bu->terrain];
    bu->terrain_resistance = bu->unit.jinfo->res_terrain_table[bu->terrain];
}

void SetBattleUnitWeapon(struct BattleUnit * bu, int item_slot)
{
    if (item_slot == -1)
        item_slot = GetUnitEquippedWeaponSlot(&bu->unit);

    bu->has_inventory_weapon = TRUE;

    switch (item_slot)
    {

    case ITEMSLOT_INV0 ... ITEMSLOT_INV_COUNT-1:
        bu->weapon_inventory_slot = item_slot;
        bu->weapon = bu->unit.items[bu->weapon_inventory_slot];

        break;

    case ITEMSLOT_OVERFLOW:
        bu->weapon_inventory_slot = -1;
        bu->weapon = gBmSt.inventory_item_overflow;

        break;

    case ITEMSLOT_ARENA_PLAYER:
        bu->weapon_inventory_slot = 0;

        bu->weapon = gArenaSt.player_weapon;
        bu->has_inventory_weapon = FALSE;

        break;

    case ITEMSLOT_ARENA_OPPONENT:
        bu->weapon_inventory_slot = 0;

        bu->weapon = gArenaSt.opponent_weapon;
        bu->has_inventory_weapon = FALSE;

        break;

    case ITEMSLOT_BALLISTA:
        bu->weapon_inventory_slot = -1;

        bu->weapon = GetBallistaItemAt(bu->unit.x, bu->unit.y);
        bu->has_inventory_weapon = FALSE;

        break;

    default:
        bu->weapon_inventory_slot = -1;

        bu->weapon = 0;
        bu->has_inventory_weapon = FALSE;

        break;

    }

    bu->weapon_before = bu->weapon;
    bu->weapon_attributes = GetItemAttributes(bu->weapon);
    bu->weapon_kind = GetItemKind(bu->weapon);

    if (!(gBattleSt.flags & BATTLE_FLAG_STATSONLY))
    {
        if (bu->weapon_attributes & ITEM_ATTR_LIGHTBRAND)
        {
            if (gBattleSt.range == 2)
                bu->weapon_kind = ITEM_KIND_LIGHT;
            else
                bu->weapon_attributes = bu->weapon_attributes &~ ITEM_ATTR_LIGHTBRAND;
        }

        if (!CanItemReachDistance(bu->weapon, gBattleSt.range) || bu->weapon_inventory_slot == 0xFF)
        {
            bu->weapon = 0;
            bu->has_inventory_weapon = FALSE;
        }

        if (bu->unit.status == UNIT_STATUS_SLEEP)
        {
            bu->weapon = 0;
            bu->has_inventory_weapon = FALSE;
        }
    }
}

void SetBattleUnitWeaponBallista(struct BattleUnit * bu)
{
    bu->weapon = GetBallistaItemAt(bu->unit.x, bu->unit.y);

    bu->weapon_before = bu->weapon;
    bu->weapon_attributes = GetItemAttributes(bu->weapon);
    bu->weapon_kind = GetItemKind(bu->weapon);

    bu->has_inventory_weapon = FALSE;
}

void func_fe6_0802478C(void)
{
}

void ComputeBattleUnitStats(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    ComputeBattleUnitDefense(attacker, defender);
    ComputeBattleUnitAttack(attacker, defender);
    ComputeBattleUnitSpeed(attacker);
    ComputeBattleUnitHitRate(attacker);
    ComputeBattleUnitAvoidRate(attacker);
    ComputeBattleUnitCritRate(attacker);
    ComputeBattleUnitDodgeRate(attacker);
    ComputeBattleUnitSupportBonuses(attacker, defender);
}

void ComputeBattleUnitEffectiveStats(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    ComputeBattleUnitEffectiveHitRate(attacker, defender);
    ComputeBattleUnitEffectiveCritRate(attacker, defender);
    ComputeBattleUnitSpecialWeaponStats(attacker, defender);
}

void ComputeBattleUnitSupportBonuses(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    struct SupportBonuses bonuses;

    GetUnitSupportBonuses(&attacker->unit, &bonuses);

    attacker->battle_attack += bonuses.bonus_attack;
    attacker->battle_defense += bonuses.bonus_defense;
    attacker->battle_hit += bonuses.bonus_hit;
    attacker->battle_avoid += bonuses.bonus_avoid;
    attacker->battle_crit += bonuses.bonus_crit;
    attacker->battle_dodge += bonuses.bonus_dodge;
}

void ComputeBattleUnitDefense(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    if (GetItemAttributes(defender->weapon) & ITEM_ATTR_MAGIC)
        attacker->battle_defense = attacker->terrain_resistance + attacker->unit.res;
    else
        attacker->battle_defense = attacker->terrain_defense + attacker->unit.def;
}

void ComputeBattleUnitBaseDefense(struct BattleUnit * bu)
{
    bu->battle_defense = bu->terrain_defense + bu->unit.def;
}

void ComputeBattleUnitAttack(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    attacker->battle_attack = GetItemMight(attacker->weapon) + attacker->advantage_bonus_damage;

    if (IsItemEffectiveAgainst(attacker->weapon, &defender->unit) == TRUE)
        attacker->battle_attack = attacker->battle_attack * 3;

    attacker->battle_attack += attacker->unit.pow;
}

void ComputeBattleUnitSpeed(struct BattleUnit * attacker)
{
    int weight = GetItemWeight(attacker->weapon_before);

    weight -= attacker->unit.bonus_con;

    if (weight < 0)
        weight = 0;

    attacker->battle_speed = attacker->unit.spd - weight;

    if (attacker->battle_speed < 0)
        attacker->battle_speed = 0;
}

void ComputeBattleUnitHitRate(struct BattleUnit * attacker)
{
    attacker->battle_hit = attacker->unit.skl*2 + GetItemHit(attacker->weapon) + attacker->unit.lck/2 + attacker->advantage_bonus_hit;
}

void ComputeBattleUnitAvoidRate(struct BattleUnit * attacker)
{
    attacker->battle_avoid = attacker->battle_speed*2 + attacker->terrain_avoid + attacker->unit.lck;

    if (attacker->battle_avoid < 0)
        attacker->battle_avoid = 0;
}

void ComputeBattleUnitCritRate(struct BattleUnit * attacker)
{
    attacker->battle_crit = GetItemCrit(attacker->weapon) + attacker->unit.skl/2;

    if (UNIT_ATTRIBUTES(&attacker->unit) & UNIT_ATTR_CRITBONUS)
        attacker->battle_crit += 30;
}

void ComputeBattleUnitDodgeRate(struct BattleUnit * attacker)
{
    attacker->battle_dodge = attacker->unit.lck;
}

void ComputeBattleUnitEffectiveHitRate(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    attacker->battle_effective_hit = attacker->battle_hit - defender->battle_avoid;

    if (attacker->battle_effective_hit > 100)
        attacker->battle_effective_hit = 100;

    if (attacker->battle_effective_hit < 0)
        attacker->battle_effective_hit = 0;
}

void ComputeBattleUnitEffectiveCritRate(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    attacker->battle_effective_crit = attacker->battle_crit - defender->battle_dodge;

    if (attacker->battle_effective_crit < 0)
        attacker->battle_effective_crit = 0;
}

void ComputeBattleUnitSpecialWeaponStats(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    if (attacker->weapon_attributes & ITEM_ATTR_LIGHTBRAND)
    {
        attacker->battle_attack = 10;
        defender->battle_defense = 0;

        attacker->battle_crit = 0;
        attacker->battle_effective_crit = 0;

        return;
    }

    if (GetItemWeaponEffect(attacker->weapon_before) == WEAPON_EFFECT_ECLIPSE)
    {
        attacker->battle_attack = defender->unit.hp - 1;

        if (attacker->battle_attack == 0)
            attacker->battle_attack = 1;

        defender->battle_defense = 0;

        attacker->battle_crit = 0;
        attacker->battle_effective_crit = 0;
    }
}

void ClearBattleHits(void)
{
    int i;

    for (i = 0; i < BATTLE_HIT_MAX; ++i)
    {
        gBattleHits[i].attributes = 0;
        gBattleHits[i].info = 0;
        gBattleHits[i].damage = 0;
    }

    gBattleHitIt = gBattleHits;
}

void BattleUnwind(void)
{
    ClearBattleHits();

    // this do { ... } while (0); is required for match
    // which is kind of neat because it implies scrapped plans for supporting some accost kind of thing

    do
    {
        struct BattleUnit * attacker;
        struct BattleUnit * defender;

        BattleGetBattleUnitOrder(&attacker, &defender);

        gBattleHitIt->info |= BATTLE_HIT_INFO_BEGIN;

        if (!BattleGenerateRoundHits(attacker, defender))
        {
            gBattleHitIt->attributes |= BATTLE_HIT_ATTR_RETALIATE;

            if (!BattleGenerateRoundHits(defender, attacker) && BattleGetFollowUpOrder(&attacker, &defender))
            {
                gBattleHitIt->attributes = BATTLE_HIT_ATTR_FOLLOWUP;

                BattleGenerateRoundHits(attacker, defender);
            }
        }
    }
    while (FALSE);

    gBattleHitIt->info |= BATTLE_HIT_INFO_END;
}

void BattleGetBattleUnitOrder(struct BattleUnit ** attacker, struct BattleUnit ** defender)
{
    *attacker = &gBattleUnitA;
    *defender = &gBattleUnitB;
}

bool BattleGetFollowUpOrder(struct BattleUnit ** attacker, struct BattleUnit ** defender)
{
    if (gBattleUnitB.battle_speed > 250)
        return FALSE;

    if (ABS(gBattleUnitA.battle_speed - gBattleUnitB.battle_speed) < 4)
        return FALSE;

    if (gBattleUnitA.battle_speed > gBattleUnitB.battle_speed)
    {
        *attacker = &gBattleUnitA;
        *defender = &gBattleUnitB;
    }
    else
    {
        *attacker = &gBattleUnitB;
        *defender = &gBattleUnitA;
    }

    if (GetItemWeaponEffect((*attacker)->weapon_before) == WEAPON_EFFECT_ECLIPSE)
        return FALSE;

    return TRUE;
}

bool BattleGenerateRoundHits(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    int i, count;
    u16 attrs;

    if (!attacker->weapon)
        return FALSE;

    attrs = gBattleHitIt->attributes;
    count = GetBattleUnitHitCount(attacker);

    for (i = 0; i < count; ++i)
    {
        gBattleHitIt->attributes |= attrs;

        if (BattleGenerateHit(attacker, defender))
            return TRUE;
    }

    return FALSE;
}

int GetBattleUnitHitCount(struct BattleUnit * attacker)
{
    int result = 1;

    result <<= BattleCheckBraveEffect(attacker);

    return result;
}

int BattleCheckBraveEffect(struct BattleUnit * attacker)
{
    if (!(attacker->weapon_attributes & ITEM_ATTR_BRAVE))
        return FALSE;

    gBattleHitIt->attributes |= BATTLE_HIT_ATTR_BRAVE;
    return TRUE;
}

bool BattleCheckTriangleAttack(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    SHOULD_BE_STATIC i8 SHOULD_BE_CONST adjacentLut[] =
    {
        -1,  0,
         0, -1,
        +1,  0,
         0, +1,
    };

    int i, count = 0;

    int triangleAttackAttr = UNIT_ATTRIBUTES(&attacker->unit) & UNIT_ATTR_TRIANGLE_ATTACK_ANY;

    int x = defender->unit.x;
    int y = defender->unit.y;

    int faction = UNIT_FACTION(&attacker->unit);

    gBattleSt.extra_unit_a = NULL;
    gBattleSt.extra_unit_b = NULL;

    for (i = 0; i < 4; ++i)
    {
        struct Unit * unit;

        int uid = gMapUnit[adjacentLut[i*2+1] + y][adjacentLut[i*2+0] + x];

        if (!uid)
            continue;

        unit = GetUnit(uid);

        if ((uid & 0xC0) != faction)
            continue;

        if (unit->status == UNIT_STATUS_SLEEP)
            continue;

        if (UNIT_ATTRIBUTES(unit) & triangleAttackAttr)
        {
            ++count;

            if (!gBattleSt.extra_unit_a)
                gBattleSt.extra_unit_a = unit;
            else if (!gBattleSt.extra_unit_b)
                gBattleSt.extra_unit_b = unit;
        }
    }

    return count >= 2 ? TRUE : FALSE;
}

void BattleUpdateBattleStats(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    gBattleSt.attack = attacker->battle_attack;
    gBattleSt.defense = defender->battle_defense;
    gBattleSt.hit = attacker->battle_effective_hit;
    gBattleSt.crit = attacker->battle_effective_crit;
}

void BattleGenerateHitAttributes(struct BattleUnit * attacker)
{
    gBattleSt.damage = 0;

    if (BattleRandRoll2Rn(gBattleSt.hit, TRUE) == FALSE)
    {
        gBattleHitIt->attributes |= BATTLE_HIT_ATTR_MISS;
        return;
    }

    gBattleSt.damage = gBattleSt.attack - gBattleSt.defense;

    if (BattleRandRoll(gBattleSt.crit, FALSE) == TRUE)
    {
        gBattleHitIt->attributes |= BATTLE_HIT_ATTR_CRIT;
        gBattleSt.damage = gBattleSt.damage * 3;
    }

    if (gBattleSt.damage > BATTLE_MAX_DAMAGE)
        gBattleSt.damage = BATTLE_MAX_DAMAGE;

    if (gBattleSt.damage < 0)
        gBattleSt.damage = 0;

    if (gBattleSt.damage != 0)
        attacker->dealt_damage = TRUE;
}

void BattleGenerateHitTriangleAttack(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    if (!(UNIT_ATTRIBUTES(&attacker->unit) & UNIT_ATTR_TRIANGLE_ATTACK_ANY))
        return;

    if (gBattleSt.range != 1)
        return;

    if (!(gBattleHitIt->info & BATTLE_HIT_INFO_BEGIN))
        return;

    if (attacker->unit.status == UNIT_STATUS_BERSERK)
        return;

    if (gBattleSt.flags & BATTLE_FLAG_ARENA)
        return;

    if (!BattleCheckTriangleAttack(attacker, defender))
        return;

    gBattleHitIt->attributes |= BATTLE_HIT_ATTR_TRIANGLE_ATTACK;

    gBattleSt.crit = 100;
    gBattleSt.hit  = 100;
}

void BattleGenerateHitEffects(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    attacker->wexp_gain++;

    if (!(gBattleHitIt->attributes & BATTLE_HIT_ATTR_MISS))
    {
        switch (GetItemWeaponEffect(attacker->weapon))
        {

        case WEAPON_EFFECT_POISON:
            defender->output_status = UNIT_STATUS_POISON;
            gBattleHitIt->attributes |= BATTLE_HIT_ATTR_POISON;

            break;

        case WEAPON_EFFECT_ECLIPSE:
            gBattleHitIt->attributes |= BATTLE_HIT_ATTR_ECLIPSE;
            break;

        }

        if (GetItemWeaponEffect(attacker->weapon) == WEAPON_EFFECT_DEVIL && (BattleRandRoll(21 - attacker->unit.level, FALSE)))
        {
            gBattleHitIt->attributes |= BATTLE_HIT_ATTR_DEVIL;

            attacker->unit.hp -= gBattleSt.damage;

            if (attacker->unit.hp < 0)
                attacker->unit.hp = 0;
        }
        else
        {
            if (gBattleSt.damage > defender->unit.hp)
                gBattleSt.damage = defender->unit.hp;

            defender->unit.hp -= gBattleSt.damage;

            if (defender->unit.hp < 0)
                defender->unit.hp = 0;
        }

        if (GetItemWeaponEffect(attacker->weapon) == WEAPON_EFFECT_NOSFERATU)
        {
            attacker->unit.hp += gBattleSt.damage;

            if (attacker->unit.hp > attacker->unit.max_hp)
                attacker->unit.hp = attacker->unit.max_hp;

            gBattleHitIt->attributes |= BATTLE_HIT_ATTR_HPSTEAL;
        }
    }

    gBattleHitIt->damage = gBattleSt.damage;

    if (!(gBattleHitIt->attributes & BATTLE_HIT_ATTR_MISS) || attacker->weapon_attributes & (ITEM_ATTR_MAGIC | ITEM_ATTR_UNCOUNTERABLE))
    {
        attacker->weapon = GetItemAfterUse(attacker->weapon);

        if (!attacker->weapon)
            attacker->weapon_broke = TRUE;
    }
}

bool BattleGenerateHit(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    if (attacker == &gBattleUnitB)
        gBattleHitIt->info |= BATTLE_HIT_INFO_ACTORB;

    BattleUpdateBattleStats(attacker, defender);

    BattleGenerateHitTriangleAttack(attacker, defender);
    BattleGenerateHitAttributes(attacker);
    BattleGenerateHitEffects(attacker, defender);

    if (attacker->unit.hp == 0 || defender->unit.hp == 0)
    {
        attacker->wexp_gain++;

        gBattleHitIt->info |= BATTLE_HIT_INFO_FINISHES;

        if (gBattleUnitB.unit.hp == 0)
            gBattleHitIt->info |= BATTLE_HIT_INFO_KILLS_TARGET;

        gBattleHitIt++;
        return TRUE;
    }

    gBattleHitIt++;
    return FALSE;
}

void BattleApplyExpGains(void)
{
    if ((UNIT_FACTION(&gBattleUnitA.unit) != FACTION_BLUE) || (UNIT_FACTION(&gBattleUnitB.unit) != FACTION_BLUE))
    {
        if (!(gPlaySt.flags & PLAY_FLAG_COMPLETE))
        {
            gBattleUnitA.exp_gain = GetBattleUnitExpGain(&gBattleUnitA, &gBattleUnitB);
            gBattleUnitB.exp_gain = GetBattleUnitExpGain(&gBattleUnitB, &gBattleUnitA);

            gBattleUnitA.unit.exp += gBattleUnitA.exp_gain;
            gBattleUnitB.unit.exp += gBattleUnitB.exp_gain;

            CheckBattleUnitLevelUp(&gBattleUnitA);
            CheckBattleUnitLevelUp(&gBattleUnitB);
        }
    }
}

int GetStatIncrease(int growth)
{
    int result = 0;

    while (growth > 100)
    {
        result++;
        growth -= 100;
    }

    if (RandRoll(growth))
        result++;

    return result;
}

int GetAutoleveledStatIncrease(int growth, int levels)
{
    return GetStatIncrease(growth*levels + (RandNext(growth*levels/4) - growth*levels/8));
}

void CheckBattleUnitLevelUp(struct BattleUnit * bu)
{
    if (!CanBattleUnitGainExp(bu))
        return;

    if (bu->unit.exp >= 100)
    {
        int statGainTotal;

        bu->unit.exp -= 100;
        bu->unit.level++;

        if (bu->unit.level == UNIT_LEVEL_MAX)
        {
            bu->exp_gain -= bu->unit.exp;
            bu->unit.exp = 0xFF;
        }

        statGainTotal = 0;

        bu->change_hp  = GetStatIncrease(bu->unit.pinfo->growth_hp);
        statGainTotal += bu->change_hp;

        bu->change_pow = GetStatIncrease(bu->unit.pinfo->growth_pow);
        statGainTotal += bu->change_pow;

        bu->change_skl = GetStatIncrease(bu->unit.pinfo->growth_skl);
        statGainTotal += bu->change_skl;

        bu->change_spd = GetStatIncrease(bu->unit.pinfo->growth_spd);
        statGainTotal += bu->change_spd;

        bu->change_def = GetStatIncrease(bu->unit.pinfo->growth_def);
        statGainTotal += bu->change_def;

        bu->change_res = GetStatIncrease(bu->unit.pinfo->growth_res);
        statGainTotal += bu->change_res;

        bu->change_lck = GetStatIncrease(bu->unit.pinfo->growth_lck);
        statGainTotal += bu->change_lck;

        if (statGainTotal == 0)
        {
            for (statGainTotal = 0; statGainTotal < 2; ++statGainTotal)
            {
                bu->change_hp = GetStatIncrease(bu->unit.pinfo->growth_hp);

                if (bu->change_hp)
                    break;

                bu->change_pow = GetStatIncrease(bu->unit.pinfo->growth_pow);

                if (bu->change_pow)
                    break;

                bu->change_skl = GetStatIncrease(bu->unit.pinfo->growth_skl);

                if (bu->change_skl)
                    break;

                bu->change_spd = GetStatIncrease(bu->unit.pinfo->growth_spd);

                if (bu->change_spd)
                    break;

                bu->change_def = GetStatIncrease(bu->unit.pinfo->growth_def);

                if (bu->change_def)
                    break;

                bu->change_res = GetStatIncrease(bu->unit.pinfo->growth_res);

                if (bu->change_res)
                    break;

                bu->change_lck = GetStatIncrease(bu->unit.pinfo->growth_lck);

                if (bu->change_lck)
                    break;
            }
        }

        CheckBattleUnitStatCaps(GetUnit(bu->unit.id), bu);
    }
}

void UnitPromote(struct Unit * unit)
{
    int i;

    // substract to stats the bases of the previous jinfo

    unit->max_hp -= unit->jinfo->base_hp;
    unit->pow -= unit->jinfo->base_pow;
    unit->skl -= unit->jinfo->base_skl;
    unit->spd -= unit->jinfo->base_spd;
    unit->def -= unit->jinfo->base_def;
    unit->res -= unit->jinfo->base_res;

    for (i = 0; i < UNIT_WEAPON_EXP_COUNT; ++i)
        unit->wexp[i] -= unit->jinfo->wexp[i];

    // promote!

    unit->jinfo = GetJInfo(unit->jinfo->jid_promote);

    // add to stats the base of the new jinfo

    unit->max_hp += unit->jinfo->base_hp;
    unit->pow += unit->jinfo->base_pow;
    unit->skl += unit->jinfo->base_skl;
    unit->spd += unit->jinfo->base_spd;
    unit->def += unit->jinfo->base_def;
    unit->res += unit->jinfo->base_res;

    for (i = 0; i < UNIT_WEAPON_EXP_COUNT; ++i)
    {
        int wexp = unit->wexp[i];

        wexp += unit->jinfo->wexp[i];

        if (wexp > WEXP_S)
            wexp = WEXP_S;

        unit->wexp[i] = wexp;
    }

    UnitCheckStatOverflow(unit);

    unit->level = 1;
    unit->exp = 0;
}

void GenerateBattleUnitStatGainsComparatively(struct BattleUnit * bu, struct Unit * unit)
{
    bu->change_hp = bu->unit.max_hp - unit->max_hp;
    bu->change_pow = bu->unit.pow - unit->pow;
    bu->change_skl = bu->unit.skl - unit->skl;
    bu->change_spd = bu->unit.spd - unit->spd;
    bu->change_def = bu->unit.def - unit->def;
    bu->change_res = bu->unit.res - unit->res;
    bu->change_lck = bu->unit.lck - unit->lck;
    bu->change_con = bu->unit.bonus_con - unit->bonus_con;
}

void CheckBattleUnitStatCaps(struct Unit * unit, struct BattleUnit * bu)
{
    if ((unit->max_hp + bu->change_hp) > UNIT_HP_CAP(unit))
        bu->change_hp = UNIT_HP_CAP(unit) - unit->max_hp;

    if ((unit->pow + bu->change_pow) > UNIT_POW_CAP(unit))
        bu->change_pow = UNIT_POW_CAP(unit) - unit->pow;

    if ((unit->skl + bu->change_skl) > UNIT_SKL_CAP(unit))
        bu->change_skl = UNIT_SKL_CAP(unit) - unit->skl;

    if ((unit->spd + bu->change_spd) > UNIT_SPD_CAP(unit))
        bu->change_spd = UNIT_SPD_CAP(unit) - unit->spd;

    if ((unit->def + bu->change_def) > UNIT_DEF_CAP(unit))
        bu->change_def = UNIT_DEF_CAP(unit) - unit->def;

    if ((unit->res + bu->change_res) > UNIT_RES_CAP(unit))
        bu->change_res = UNIT_RES_CAP(unit) - unit->res;

    if ((unit->lck + bu->change_lck) > UNIT_LCK_CAP(unit))
        bu->change_lck = UNIT_LCK_CAP(unit) - unit->lck;
}

void BattleApplyUnitUpdates(void)
{
    struct Unit * instigator = GetUnit(gBattleUnitA.unit.id);
    struct Unit * target = GetUnit(gBattleUnitB.unit.id);

    if (gBattleUnitA.has_inventory_weapon)
        gBattleUnitA.unit.items[gBattleUnitA.weapon_inventory_slot] = gBattleUnitA.weapon;

    if (gBattleUnitB.has_inventory_weapon)
        gBattleUnitB.unit.items[gBattleUnitB.weapon_inventory_slot] = gBattleUnitB.weapon;

    UpdateUnitFromBattle(instigator, &gBattleUnitA);

    if (target)
        UpdateUnitFromBattle(target, &gBattleUnitB);
    else
        UpdateObstacleFromBattle(&gBattleUnitB);
}

int GetBattleUnitUpdatedWeaponExp(struct BattleUnit * bu)
{
    int result;

    if (UNIT_FACTION(&bu->unit) != FACTION_BLUE)
        return -1;

    if (bu->unit.hp == 0)
        return -1;

    if (gPlaySt.flags & PLAY_FLAG_COMPLETE)
        return -1;

    if (gBmSt.flags & BM_FLAG_LINKARENA)
        return -1;

    if (!(gBattleSt.flags & BATTLE_FLAG_ARENA))
    {
        if (!bu->has_inventory_weapon)
            return -1;

        if (!(bu->weapon_attributes & ITEM_ATTR_REQUIRES_EXP))
            return -1;

        if (bu->weapon_attributes & (ITEM_ATTR_LIGHTBRAND | ITEM_ATTR_LOCK_DRAGON))
            return -1;
    }

    result = bu->unit.wexp[bu->weapon_kind] + bu->wexp_gain;

    if (UNIT_ATTRIBUTES(&bu->unit) & UNIT_ATTR_PROMOTED)
    {
        if (result > WEXP_S)
            result = WEXP_S;
    }
    else
    {
        if (result > WEXP_A)
            result = WEXP_A;
    }

    return result;
}

bool HasBattleUnitGainedWeaponLevel(struct BattleUnit * bu)
{
    int oldExp = bu->unit.wexp[bu->weapon_kind];
    int newExp = GetBattleUnitUpdatedWeaponExp(bu);

    if (newExp < 0)
        return FALSE;

    return GetWeaponLevelFromExp(oldExp) != GetWeaponLevelFromExp(newExp);
}

void UpdateUnitFromBattle(struct Unit * unit, struct BattleUnit * bu)
{
    int tmp;

    unit->level = bu->unit.level;
    unit->exp   = bu->unit.exp;
    unit->hp = bu->unit.hp;
    unit->flags = bu->unit.flags;

    if (bu->output_status >= 0)
        SetUnitStatus(unit, bu->output_status);

    unit->max_hp += bu->change_hp;
    unit->pow += bu->change_pow;
    unit->skl += bu->change_skl;
    unit->spd += bu->change_spd;
    unit->def += bu->change_def;
    unit->res += bu->change_res;
    unit->lck += bu->change_lck;

    UnitCheckStatOverflow(unit);

    tmp = GetBattleUnitUpdatedWeaponExp(bu);

    if (tmp > 0)
        unit->wexp[bu->weapon_kind] = tmp;

    for (tmp = 0; tmp < ITEMSLOT_INV_COUNT; ++tmp)
        unit->items[tmp] = bu->unit.items[tmp];

    UnitRemoveInvalidItems(unit);

    if (bu->exp_gain)
        PidStatsAddExpGained(unit->pinfo->id, bu->exp_gain);
}

void UpdateUnitDuringBattle(struct Unit * unit, struct BattleUnit * bu)
{
    int wexp;

    unit->hp = bu->unit.hp;

    wexp = GetBattleUnitUpdatedWeaponExp(bu);

    if (wexp > 0)
        unit->wexp[bu->weapon_kind] = wexp;
}

void BattleApplyBallistaUpdates(void)
{
    if (gBattleSt.flags & BATTLE_FLAG_BALLISTA)
    {
        int uses = GetItemUses(gBattleUnitA.weapon);
        GetBallistaTrapAt(gBattleUnitA.unit.x, gBattleUnitA.unit.y)->extra = uses;
    }
}

void func_fe6_08025780(void)
{
    struct Unk_0203932C
    {
        /* 00 */ u8 unk_00;
        /* 01 */ u8 unk_01;
        /* 02 */ u8 unk_02;
    };

    static struct Unk_0203932C EWRAM_DATA unk_0203932C = {}; 

    unk_0203932C.unk_00 = 0;
    unk_0203932C.unk_01 = 0;
    unk_0203932C.unk_02 = 0;
}

int GetUnitExpLevel(struct Unit * unit)
{
    int result = unit->level;

    if (UNIT_ATTRIBUTES(unit) & UNIT_ATTR_PROMOTED)
        result += 20;

    return result;
}

int GetUnitRoundExp(struct Unit * unit, struct Unit * other)
{
    int expLevel;

    expLevel = GetUnitExpLevel(unit);
    expLevel = expLevel - GetUnitExpLevel(other);
    expLevel = 31 - expLevel;

    if (expLevel < 0)
        expLevel = 0;

    return expLevel / unit->jinfo->power_level;
}

int GetUnitPowerLevel(struct Unit * unit)
{
    int result = unit->level * unit->jinfo->power_level;

    if (UNIT_ATTRIBUTES(unit) & UNIT_ATTR_PROMOTED)
        result += 20 * GetJInfo(unit->jinfo->jid_promote)->power_level;

    return result;
}

int GetUnitClassKillExpBonus(struct Unit * unit, struct Unit * defeated)
{
    int result = 0;

    if (UNIT_ATTRIBUTES(defeated) & UNIT_ATTR_STEAL)
        result += 20;

    if (UNIT_ATTRIBUTES(defeated) & UNIT_ATTR_BOSS)
        result += 40;

    return result;
}

int GetUnitKillExpBonus(struct Unit * unit, struct Unit * other)
{
    int result;

    if (other->hp != 0)
        return 0;

    result = 0;

    result += GetUnitPowerLevel(other);
    result += 20;
    result -= GetUnitPowerLevel(unit);
    result += GetUnitClassKillExpBonus(unit, other);

    if (result < 0)
        result = 0;

    return result;
}

int GetBattleUnitExpGain(struct BattleUnit * bu, struct BattleUnit * other)
{
    int result;

    if (!CanBattleUnitGainExp(bu) || bu->unit.hp == 0 || UNIT_ATTRIBUTES(&other->unit) & UNIT_ATTR_MAJOR_BOSS)
        return 0;

    if (!bu->dealt_damage)
        return 1;

    result = GetUnitRoundExp(&bu->unit, &other->unit);
    result += GetUnitKillExpBonus(&bu->unit, &other->unit);

    if (result > 100)
        result = 100;

    if (result < 0)
        result = 0;

    return result;
}

void BattleApplyItemExpGains(void)
{
    if ((gBattleUnitA.weapon_attributes & ITEM_ATTR_STAFF) && !(gPlaySt.flags & PLAY_FLAG_COMPLETE))
    {
        if (UNIT_FACTION(&gBattleUnitA.unit) == FACTION_BLUE)
            gBattleUnitA.wexp_gain++;

        gBattleUnitA.exp_gain = GetBattleUnitStaffExp(&gBattleUnitA);
        gBattleUnitA.unit.exp += gBattleUnitA.exp_gain;

        CheckBattleUnitLevelUp(&gBattleUnitA);
    }
}

int GetBattleUnitStaffExp(struct BattleUnit * bu)
{
    int result;

    if (!CanBattleUnitGainExp(bu))
        return 0;

    if (gBattleHits[0].attributes & BATTLE_HIT_ATTR_MISS)
        return 1;

    result = 10 + GetItemCostPerUse(bu->weapon) / 20;

    if (UNIT_ATTRIBUTES(&bu->unit) & UNIT_ATTR_PROMOTED)
        result = result / 2;

    if (result > 100)
        result = 100;

    return result;
}

void BattleApplyMiscActionExpGains(void)
{
    if (UNIT_FACTION(&gBattleUnitA.unit) != FACTION_BLUE)
        return;

    if (!CanBattleUnitGainExp(&gBattleUnitA))
        return;

    if (gPlaySt.flags & PLAY_FLAG_COMPLETE)
        return;

    gBattleUnitA.exp_gain = 10;
    gBattleUnitA.unit.exp += 10;

    CheckBattleUnitLevelUp(&gBattleUnitA);
}

void BattleUnitTargetSetEquippedWeapon(struct BattleUnit * bu)
{
    int i;

    if (bu->weapon_before)
        return;

    bu->weapon_before = GetUnitEquippedWeapon(&bu->unit);

    if (bu->weapon_before)
        return;

    if (!UnitKnowsMagic(&bu->unit))
        return;

    for (i = 0; i < ITEMSLOT_INV_COUNT; ++i)
    {
        if (CanUnitUseStaff(&bu->unit, bu->unit.items[i]) == TRUE)
        {
            bu->weapon_before = bu->unit.items[i];
            break;
        }
    }
}

void BattleUnitTargetCheckCanCounter(struct BattleUnit * bu)
{
    if (!bu->has_inventory_weapon)
    {
        bu->battle_attack = 0xFF;
        bu->battle_hit = 0xFF;
        bu->battle_effective_hit = 0xFF;
        bu->battle_crit = 0xFF;
        bu->battle_effective_crit = 0xFF;
    }
}

void BattleApplyReaverEffect(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    // those <<1>>1 are useless but without them it doesn't match :/

    attacker->advantage_bonus_hit = -attacker->advantage_bonus_hit <<1>>1;
    attacker->advantage_bonus_damage = -attacker->advantage_bonus_damage <<1>>1;
    defender->advantage_bonus_hit = -defender->advantage_bonus_hit <<1>>1;
    defender->advantage_bonus_damage = -defender->advantage_bonus_damage <<1>>1;
}

void BattleApplyWeaponTriangleEffect(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    struct WeaponTriangleRule const * it;

    for (it = sWeaponTriangleRules; it->attackerKind >= 0; ++it)
    {
        if ((attacker->weapon_kind == it->attackerKind) && (defender->weapon_kind == it->defenderKind))
        {
            attacker->advantage_bonus_hit = it->hitBonus;
            attacker->advantage_bonus_damage = it->damageBonus;

            defender->advantage_bonus_hit = -it->hitBonus;
            defender->advantage_bonus_damage = -it->damageBonus;

            break;
        }
    }

    if (attacker->weapon_attributes & ITEM_ATTR_REVERTS_TRIANGLE)
        BattleApplyReaverEffect(attacker, defender);

    if (defender->weapon_attributes & ITEM_ATTR_REVERTS_TRIANGLE)
        BattleApplyReaverEffect(attacker, defender);
}

void BattleInitTargetCanCounter(void)
{
    // Target cannot counter if either units are using "uncounterable" weapons

    if ((gBattleUnitA.weapon_attributes | gBattleUnitB.weapon_attributes) & ITEM_ATTR_UNCOUNTERABLE)
    {
        gBattleUnitB.weapon = 0;
        gBattleUnitB.has_inventory_weapon = FALSE;
    }

    // Target cannot counter if a berserked player unit is attacking another player unit

    if (gBattleUnitA.unit.status == UNIT_STATUS_BERSERK)
    {
        if ((UNIT_FACTION(&gBattleUnitA.unit) == FACTION_BLUE) && (UNIT_FACTION(&gBattleUnitB.unit) == FACTION_BLUE))
        {
            gBattleUnitB.weapon = 0;
            gBattleUnitB.has_inventory_weapon = FALSE;
        }
    }
}

void InitObstacleBattleUnit(void)
{
    ClearUnit(&gBattleUnitB.unit);

    gBattleUnitB.unit.id = 0;

    gBattleUnitB.unit.pinfo = GetPInfo(PID_WALL);
    gBattleUnitB.unit.jinfo = GetJInfo(JID_OBSTACLE);

    gBattleUnitB.unit.max_hp = GetChapterInfo(gPlaySt.chapter)->wall_hp;
    gBattleUnitB.unit.hp = gAction.extra;

    gBattleUnitB.unit.x = gAction.x_target;
    gBattleUnitB.unit.y = gAction.y_target;
}

void ComputeBattleObstacleStats(void)
{
    gBattleUnitA.battle_effective_hit = 100;
    gBattleUnitA.battle_effective_crit = 0;

    gBattleUnitB.battle_speed = 0xFF;
    gBattleUnitB.previous_hp = gBattleUnitB.unit.hp;

    gBattleUnitB.advantage_bonus_hit = 0;
    gBattleUnitB.advantage_bonus_damage = 0;
}

void UpdateObstacleFromBattle(struct BattleUnit * bu)
{
    struct Trap * trap = GetTrapAt(bu->unit.x, bu->unit.y);

    if (!trap)
        trap = GetTrapAt(bu->unit.x, bu->unit.y-1);

    trap->extra = bu->unit.hp;

    if (trap->extra == 0)
    {
        int mapchange = GetMapChangeIdAt(trap->x, trap->y);

        RenderMapForFade();

        ApplyMapChange(mapchange);

        // This is kind of jank: it sets trap type to 0 (TRAP_NONE) which should be the terminating id
        // But then immediately calls the map change trap adding routine, which would effectively replace
        // the 0-id trap with the new map change trap, even if it is not actually the end of the trap array

        trap->kind = TRAP_NONE;
        AddMapChangeTrap(mapchange);

        RefreshTerrainMap();
        RenderMap();

        StartMapFade(FALSE);
    }
}

void BeginBattleAnimations(void)
{
    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);
    SetBackdropColor(0);

    RenderMap();

    if (SetupBanim())
    {
        SetBanimLinkArenaFlag(0);
        BeginAnimsOnBattleAnimations();
    }
    else
    {
        EndAllMus();
        RenderMap();

        StartBattleManim();

        gBattleSt.flags |= BATTLE_FLAG_MAPANIMS;
    }
}

int GetUnitSoloBattleAnimType(struct Unit * unit)
{
    // TODO: battle anim type constants

    if (unit->flags & UNIT_FLAG_SOLOANIM_1)
        return 0;

    if (unit->flags & UNIT_FLAG_SOLOANIM_2)
        return 3;

    return 1;
}

int GetBattleAnimType(void)
{
    // TODO: battle anim type constants

    // If not solo anim, return global type

    if (gPlaySt.config_battle_anim != 2)
        return gPlaySt.config_battle_anim;

    // If both units are players, use actor solo anim type

    if (UNIT_FACTION(&gBattleUnitA.unit) == FACTION_BLUE)
        if (UNIT_FACTION(&gBattleUnitB.unit) == FACTION_BLUE)
            return GetUnitSoloBattleAnimType(&gBattleUnitA.unit);

    // If neither are players, return 1

    if (UNIT_FACTION(&gBattleUnitA.unit) != FACTION_BLUE)
        if (UNIT_FACTION(&gBattleUnitB.unit) != FACTION_BLUE)
            return 1;

    // Return solo anim type for the one that is a player unit

    if (UNIT_FACTION(&gBattleUnitA.unit) == FACTION_BLUE)
        return GetUnitSoloBattleAnimType(&gBattleUnitA.unit);
    else
        return GetUnitSoloBattleAnimType(&gBattleUnitB.unit);
}

void BattlePrintDebugUnitInfo(struct BattleUnit * actor, struct BattleUnit * target)
{
    // prints battle unit information to debug output
}

void BattlePrintDebugHitInfo(void)
{
    struct BattleHit * it;

    for (it = gBattleHits; !(it->info & BATTLE_HIT_INFO_END); ++it)
    {
        // prints battle rounds information to debug output
    }
}

void BattleInitItemEffect(struct Unit * unit, int item_slot)
{
    int item = unit->items[item_slot];

    if (item_slot < 0)
        item = 0;

    gBattleSt.flags = 0;

    InitBattleUnit(&gBattleUnitA, unit);

    SetBattleUnitTerrainBonusesAuto(&gBattleUnitA);
    ComputeBattleUnitBaseDefense(&gBattleUnitA);
    ComputeBattleUnitSupportBonuses(&gBattleUnitA, NULL);

    gBattleUnitA.battle_attack = 0xFF;
    gBattleUnitA.battle_effective_hit = 100;
    gBattleUnitA.battle_effective_crit = 0xFF;

    gBattleUnitA.weapon = item;
    gBattleUnitA.weapon_before = item;
    gBattleUnitA.weapon_inventory_slot = item_slot;
    gBattleUnitA.weapon_kind = GetItemKind(item);
    gBattleUnitA.weapon_attributes = GetItemAttributes(item);

    gBattleUnitA.has_inventory_weapon = TRUE;
    gBattleUnitA.has_item_effect_target = FALSE;

    gBattleUnitA.output_status = -1;
    gBattleUnitB.output_status = -1;

    ClearBattleHits();
}

void BattleInitItemEffectTarget(struct Unit * unit)
{
    InitBattleUnit(&gBattleUnitB, unit);

    SetBattleUnitTerrainBonusesAuto(&gBattleUnitB);
    ComputeBattleUnitBaseDefense(&gBattleUnitB);
    ComputeBattleUnitSupportBonuses(&gBattleUnitB, NULL);

    gBattleUnitB.battle_attack = 0xFF;
    gBattleUnitB.battle_effective_hit = 0xFF;
    gBattleUnitB.battle_effective_crit = 0xFF;

    gBattleUnitB.weapon_before = 0;

    BattleUnitTargetSetEquippedWeapon(&gBattleUnitB);

    gBattleUnitA.has_item_effect_target = TRUE;

    if (GetItemAttributes(gBattleUnitB.weapon_before) & ITEM_ATTR_LOCK_DRAGON)
        if (gBattleUnitB.unit.jinfo->id != JID_DEMONDRAGON)
            gBattleUnitB.weapon_before = 0;
}

static void DummyBattleAnimLock_UpdateInstigator(ProcPtr proc)
{
    UpdateUnitFromBattle(GetUnit(gBattleUnitA.unit.id), &gBattleUnitA);
}

void BattleApplyMiscAction(ProcPtr proc)
{
    BattleApplyMiscActionExpGains();
    SpawnProcLocking(ProcScr_DummyBattleAnimLock, proc);
}

void BattleApplyItemEffect(ProcPtr proc)
{
    (++gBattleHitIt)->info = BATTLE_HIT_INFO_END;

    BattleApplyItemExpGains();

    if (gBattleUnitA.has_inventory_weapon)
    {
        if (GetItemAttributes(gBattleUnitA.weapon) & ITEM_ATTR_STAFF)
            gBattleUnitA.weapon_broke = TRUE;

        gBattleUnitA.weapon = GetItemAfterUse(gBattleUnitA.weapon);
        gBattleUnitA.unit.items[gBattleUnitA.weapon_inventory_slot] = gBattleUnitA.weapon;

        if (gBattleUnitA.weapon)
            gBattleUnitA.weapon_broke = FALSE;
    }

    SpawnProcLocking(ProcScr_DummyBattleAnimLock, proc);
}

int GetOffensiveStaffAccuracy(struct Unit * unit, struct Unit * target)
{
    int baseAccuracy = (GetUnitPower(unit) - GetUnitResistance(target)) * 6;
    int unitSkill = GetUnitSkill(unit);
    int distance = RECT_DISTANCE(unit->x, unit->y, target->x, target->y);

    int result = baseAccuracy + 30 + unitSkill - distance ;

    if (result < 0)
        result = 0;

    if (result > 100)
        result = 100;

    return result;
}

void BattleGenerateArena(struct Unit * unit)
{
    struct Unit * target = gArenaSt.opponent;

    int just_resumed = gBmSt.just_resumed;

    gBattleSt.flags = BATTLE_FLAG_REAL | BATTLE_FLAG_ARENA;

    InitBattleUnit(&gBattleUnitA, unit);
    InitBattleUnit(&gBattleUnitB, target);

    if (gAction.extra != 0)
    {
        gBattleUnitB.unit.hp = gAction.extra;
        gBattleUnitB.previous_hp = gAction.extra;
    }

    gBattleSt.range = gArenaSt.range;

    gBattleUnitB.unit.x = gBattleUnitA.unit.x + gArenaSt.range;
    gBattleUnitB.unit.y = gBattleUnitA.unit.y;

    SetBattleUnitWeapon(&gBattleUnitA, ITEMSLOT_ARENA_PLAYER);
    SetBattleUnitWeapon(&gBattleUnitB, ITEMSLOT_ARENA_OPPONENT);

    BattleApplyWeaponTriangleEffect(&gBattleUnitA, &gBattleUnitB);

    gAction.suspend_point = SUSPEND_POINT_DURING_ARENA;
    WriteSuspendSave(SAVE_SUSPEND);

    SetBattleUnitTerrainBonusesAuto(&gBattleUnitA);
    SetBattleUnitTerrainBonuses(&gBattleUnitB, 8); // TODO: terrain id constants

    BattleGenerate(unit, target);

    if (gBattleUnitB.unit.hp == 0)
        BattleApplyExpGains();

    UpdateUnitDuringBattle(unit, &gBattleUnitA);

    if (!just_resumed || (gBattleUnitB.unit.hp == 0))
        PidStatsUpdateFromBattleOutcome();

    BattlePrintDebugUnitInfo(&gBattleUnitA, &gBattleUnitB);
}

bool BattleIsTriangleAttack(void)
{
    return (gBattleHits[0].attributes & BATTLE_HIT_ATTR_TRIANGLE_ATTACK) != 0;
}

bool DidBattleUnitBreakWeapon(struct BattleUnit * bu)
{
    if (bu->unit.hp == 0)
        return FALSE;

    return bu->weapon_broke;
}

void BattleHitAdvance(void)
{
    gBattleHitIt++;
}

void BattleHitTerminate(void)
{
    gBattleHitIt++;
    gBattleHitIt->info = BATTLE_HIT_INFO_END;
}
