
#include "battle.h"
#include "common.h"

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
#include "mu.h"

#include "constants/pids.h"
#include "constants/jids.h"

enum { BATTLE_HIT_MAX = 7 };
enum { BATTLE_MAX_DAMAGE = 99 };

struct WeaponTriangleRule
{
    s8 attackerKind;
    s8 defenderKind;
    s8 hitBonus;
    s8 damageBonus;
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
struct BattleHit* EWRAM_DATA gBattleHitIt = NULL;

#define CanBattleUnitGainExp(bu) ((bu)->unit.exp != 0xFF)

void BattleGenerateSimulationInternal(struct Unit* instigator, struct Unit* target, int x, int y, int itemSlot)
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
        SetBattleUnitWeapon(&gBattleUnitA, itemSlot);

    SetBattleUnitWeapon(&gBattleUnitB, -1);

    BattleInitTargetCanCounter();
    BattleApplyWeaponTriangleEffect(&gBattleUnitA, &gBattleUnitB);

    SetBattleUnitTerrainBonusesAuto(&gBattleUnitA);
    SetBattleUnitTerrainBonusesAuto(&gBattleUnitB);

    BattleGenerate(instigator, target);
}

void BattleGenerateRealInternal(struct Unit* instigator, struct Unit* target)
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
        sub_8084D64();

        sub_808495C(instigator);
        sub_808495C(target);
    }
}

void BattleApplyGameStateUpdates(void)
{
    BattleApplyUnitUpdates();
    BattleApplyBallistaUpdates();

    BattlePrintDebugUnitInfo(&gBattleUnitA, &gBattleUnitB);
    BattlePrintDebugHitInfo();
}

void BattleGenerateSimulation(struct Unit* instigator, struct Unit* target, int x, int y, int itemSlot)
{
    if (x < 0 && y < 0)
    {
        x = instigator->x;
        y = instigator->y;
    }

    gBattleSt.flags = BATTLE_FLAG_SIMULATE;
    BattleGenerateSimulationInternal(instigator, target, x, y, itemSlot);
}

void BattleGenerateReal(struct Unit* instigator, struct Unit* target)
{
    gBattleSt.flags = BATTLE_FLAG_REAL;
    BattleGenerateRealInternal(instigator, target);
}

void BattleGenerateBallistaSimulation(struct Unit* instigator, struct Unit* target, int x, int y)
{
    gBattleSt.flags = BATTLE_FLAG_SIMULATE | BATTLE_FLAG_BALLISTA;
    BattleGenerateSimulationInternal(instigator, target, x, y, 0);
}

void BattleGenerateBallistaReal(struct Unit* instigator, struct Unit* target)
{
    gBattleSt.flags = BATTLE_FLAG_REAL | BATTLE_FLAG_BALLISTA;
    BattleGenerateRealInternal(instigator, target);
}

void BattleGenerate(struct Unit* instigator, struct Unit* target)
{
    ComputeBattleUnitStats(&gBattleUnitA, &gBattleUnitB);
    ComputeBattleUnitStats(&gBattleUnitB, &gBattleUnitA);

    ComputeBattleUnitEffectiveStats(&gBattleUnitA, &gBattleUnitB);
    ComputeBattleUnitEffectiveStats(&gBattleUnitB, &gBattleUnitA);

    if (target == NULL)
        ComputeBattleObstacleStats();

    BattleUnwind();
}

void BattleGenerateDisplayStats(struct Unit* unit, s8 itemSlot)
{
    gBattleSt.flags = BATTLE_FLAG_BIT2;

    gBattleUnitB.weapon = 0;
    gBattleUnitB.weaponAttributes = 0;
    gBattleUnitB.weaponKind = ITEM_KIND_INVALID;

    gBattleUnitB.unit.job = NULL;

    gBattleUnitA.wtHitBonus = 0;
    gBattleUnitA.wtDamageBonus = 0;

    InitBattleUnit(&gBattleUnitA, unit);

    SetBattleUnitTerrainBonusesAuto(&gBattleUnitA);

    SetBattleUnitWeapon(&gBattleUnitA, itemSlot);
    ComputeBattleUnitStats(&gBattleUnitA, &gBattleUnitB);

    if (!gBattleUnitA.weapon)
    {
        gBattleUnitA.battleAttack = 0xFF;
        gBattleUnitA.battleHit = 0xFF;
        gBattleUnitA.battleCrit = 0xFF;
    }

    if (GetItemWeaponEffect(gBattleUnitA.weapon) == WEAPON_EFFECT_ECLIPSE)
        gBattleUnitA.battleAttack = 0xFF;
}

Bool BattleRandRoll(u16 threshold, Bool simulationResult)
{
    if (gBattleSt.flags & BATTLE_FLAG_SIMULATE)
        return simulationResult;

    return RandRoll(threshold);
}

Bool BattleRandRoll2Rn(u16 threshold, Bool simulationResult)
{
    if (gBattleSt.flags & BATTLE_FLAG_SIMULATE)
        return simulationResult;

    return RandRoll2Rn(threshold);
}

void InitBattleUnit(struct BattleUnit* bu, struct Unit* unit)
{
    if (!unit)
        return;

    bu->unit = *unit;

    bu->unit.hpMax = GetUnitMaxHp(unit);
    bu->unit.pow = GetUnitPower(unit);
    bu->unit.skl = GetUnitSkill(unit);
    bu->unit.spd = GetUnitSpeed(unit);
    bu->unit.def = GetUnitDefense(unit);
    bu->unit.lck = GetUnitLuck(unit);
    bu->unit.res = GetUnitResistance(unit);
    bu->unit.conBonus = UNIT_CON(unit);
    bu->unit.movBonus = UNIT_MOV(unit);

    bu->levelPrevious = bu->unit.level;
    bu->expPrevious = bu->unit.exp;
    bu->hpPrevious = bu->unit.hpCur;

    bu->statusOut = 0xFF;

    bu->hpChange = 0;
    bu->powChange = 0;
    bu->sklChange = 0;
    bu->spdChange = 0;
    bu->defChange = 0;
    bu->resChange = 0;
    bu->lckChange = 0;
    bu->conChange = 0;

    gBattleUnitA.wexpGain = 0;
    gBattleUnitB.wexpGain = 0;

    bu->wtHitBonus = 0;
    bu->wtDamageBonus = 0;

    bu->nonZeroDamage = FALSE;

    gBattleUnitA.weaponBroke = FALSE;
    gBattleUnitB.weaponBroke = FALSE;

    gBattleUnitA.expGain = 0;
    gBattleUnitB.expGain = 0;
}

void InitBattleUnitWithoutBonuses(struct BattleUnit* bu, struct Unit* unit)
{
    InitBattleUnit(bu, unit);

    bu->unit.hpMax = unit->hpMax;
    bu->unit.pow = unit->pow;
    bu->unit.skl = unit->skl;
    bu->unit.spd = unit->spd;
    bu->unit.def = unit->def;
    bu->unit.lck = unit->lck;
    bu->unit.res = unit->res;
    bu->unit.conBonus = UNIT_CON_BASE(unit);
}

void SetBattleUnitTerrainBonuses(struct BattleUnit* bu, int terrain)
{
    bu->terrain = terrain;

    bu->terrainAvoid = bu->unit.job->avoTerrainTable[bu->terrain];
    bu->terrainDefense = bu->unit.job->defTerrainTable[bu->terrain];
    bu->terrainResistance = bu->unit.job->resTerrainTable[bu->terrain];
}

void SetBattleUnitTerrainBonusesAuto(struct BattleUnit* bu)
{
    bu->terrain = gMapTerrain[bu->unit.y][bu->unit.x];

    bu->terrainAvoid = bu->unit.job->avoTerrainTable[bu->terrain];
    bu->terrainDefense = bu->unit.job->defTerrainTable[bu->terrain];
    bu->terrainResistance = bu->unit.job->resTerrainTable[bu->terrain];
}

void SetBattleUnitWeapon(struct BattleUnit* bu, int itemSlot)
{
    if (itemSlot == -1)
        itemSlot = GetUnitEquippedWeaponSlot(&bu->unit);

    bu->canCounter = TRUE;

    switch (itemSlot)
    {

    case ITEMSLOT_INV0 ... ITEMSLOT_INV_COUNT-1:
        bu->weaponItemSlot = itemSlot;
        bu->weapon = bu->unit.items[bu->weaponItemSlot];

        break;

    case ITEMSLOT_OVERFLOW:
        bu->weaponItemSlot = -1;
        bu->weapon = gBmSt.inventoryItemOverflow;

        break;

    case ITEMSLOT_ARENA_PLAYER:
        bu->weaponItemSlot = 0;

        bu->weapon = gArenaSt.playerWeapon;
        bu->canCounter = FALSE;

        break;

    case ITEMSLOT_ARENA_OPPONENT:
        bu->weaponItemSlot = 0;

        bu->weapon = gArenaSt.opponentWeapon;
        bu->canCounter = FALSE;

        break;

    case ITEMSLOT_BALLISTA:
        bu->weaponItemSlot = -1;

        bu->weapon = GetBallistaItemAt(bu->unit.x, bu->unit.y);
        bu->canCounter = FALSE;

        break;

    default:
        bu->weaponItemSlot = -1;

        bu->weapon = 0;
        bu->canCounter = FALSE;

        break;

    }

    bu->weaponBefore = bu->weapon;
    bu->weaponAttributes = GetItemAttributes(bu->weapon);
    bu->weaponKind = GetItemKind(bu->weapon);

    if (!(gBattleSt.flags & BATTLE_FLAG_BIT2))
    {
        if (bu->weaponAttributes & ITEM_ATTR_LIGHTBRAND)
        {
            if (gBattleSt.range == 2)
                bu->weaponKind = ITEM_KIND_LIGHT;
            else
                bu->weaponAttributes = bu->weaponAttributes &~ ITEM_ATTR_LIGHTBRAND;
        }

        if (!CanItemReachDistance(bu->weapon, gBattleSt.range) || bu->weaponItemSlot == 0xFF)
        {
            bu->weapon = 0;
            bu->canCounter = FALSE;
        }

        if (bu->unit.status == UNIT_STATUS_SLEEP)
        {
            bu->weapon = 0;
            bu->canCounter = FALSE;
        }
    }
}

void SetBattleUnitWeaponBallista(struct BattleUnit* bu)
{
    bu->weapon = GetBallistaItemAt(bu->unit.x, bu->unit.y);

    bu->weaponBefore = bu->weapon;
    bu->weaponAttributes = GetItemAttributes(bu->weapon);
    bu->weaponKind = GetItemKind(bu->weapon);

    bu->canCounter = FALSE;
}

void sub_802478C(void)
{
}

void ComputeBattleUnitStats(struct BattleUnit* attacker, struct BattleUnit* defender)
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

void ComputeBattleUnitEffectiveStats(struct BattleUnit* attacker, struct BattleUnit* defender)
{
    ComputeBattleUnitEffectiveHitRate(attacker, defender);
    ComputeBattleUnitEffectiveCritRate(attacker, defender);
    ComputeBattleUnitSpecialWeaponStats(attacker, defender);
}

void ComputeBattleUnitSupportBonuses(struct BattleUnit* attacker, struct BattleUnit* defender)
{
    struct SupportBonuses bonuses;

    GetUnitSupportBonuses(&attacker->unit, &bonuses);

    attacker->battleAttack += bonuses.bonusAttack;
    attacker->battleDefense += bonuses.bonusDefense;
    attacker->battleHit += bonuses.bonusHit;
    attacker->battleAvoid += bonuses.bonusAvoid;
    attacker->battleCrit += bonuses.bonusCrit;
    attacker->battleDodge += bonuses.bonusDodge;
}

void ComputeBattleUnitDefense(struct BattleUnit* attacker, struct BattleUnit* defender)
{
    if (GetItemAttributes(defender->weapon) & ITEM_ATTR_MAGIC)
        attacker->battleDefense = attacker->terrainResistance + attacker->unit.res;
    else
        attacker->battleDefense = attacker->terrainDefense + attacker->unit.def;
}

void ComputeBattleUnitBaseDefense(struct BattleUnit* bu)
{
    bu->battleDefense = bu->terrainDefense + bu->unit.def;
}

void ComputeBattleUnitAttack(struct BattleUnit* attacker, struct BattleUnit* defender)
{
    attacker->battleAttack = GetItemMight(attacker->weapon) + attacker->wtDamageBonus;

    if (IsItemEffectiveAgainst(attacker->weapon, &defender->unit) == TRUE)
        attacker->battleAttack = attacker->battleAttack * 3;

    attacker->battleAttack += attacker->unit.pow;
}

void ComputeBattleUnitSpeed(struct BattleUnit* attacker)
{
    int weight = GetItemWeight(attacker->weaponBefore);

    weight -= attacker->unit.conBonus;

    if (weight < 0)
        weight = 0;

    attacker->battleSpeed = attacker->unit.spd - weight;

    if (attacker->battleSpeed < 0)
        attacker->battleSpeed = 0;
}

void ComputeBattleUnitHitRate(struct BattleUnit* attacker)
{
    attacker->battleHit = attacker->unit.skl*2 + GetItemHit(attacker->weapon) + attacker->unit.lck/2 + attacker->wtHitBonus;
}

void ComputeBattleUnitAvoidRate(struct BattleUnit* attacker)
{
    attacker->battleAvoid = attacker->battleSpeed*2 + attacker->terrainAvoid + attacker->unit.lck;

    if (attacker->battleAvoid < 0)
        attacker->battleAvoid = 0;
}

void ComputeBattleUnitCritRate(struct BattleUnit* attacker)
{
    attacker->battleCrit = GetItemCrit(attacker->weapon) + attacker->unit.skl/2;

    if (UNIT_ATTRIBUTES(&attacker->unit) & UNIT_ATTR_CRITBONUS)
        attacker->battleCrit += 30;
}

void ComputeBattleUnitDodgeRate(struct BattleUnit* attacker)
{
    attacker->battleDodge = attacker->unit.lck;
}

void ComputeBattleUnitEffectiveHitRate(struct BattleUnit* attacker, struct BattleUnit* defender)
{
    attacker->battleEffectiveHit = attacker->battleHit - defender->battleAvoid;

    if (attacker->battleEffectiveHit > 100)
        attacker->battleEffectiveHit = 100;

    if (attacker->battleEffectiveHit < 0)
        attacker->battleEffectiveHit = 0;
}

void ComputeBattleUnitEffectiveCritRate(struct BattleUnit* attacker, struct BattleUnit* defender)
{
    attacker->battleEffectiveCrit = attacker->battleCrit - defender->battleDodge;

    if (attacker->battleEffectiveCrit < 0)
        attacker->battleEffectiveCrit = 0;
}

void ComputeBattleUnitSpecialWeaponStats(struct BattleUnit* attacker, struct BattleUnit* defender)
{
    if (attacker->weaponAttributes & ITEM_ATTR_LIGHTBRAND)
    {
        attacker->battleAttack = 10;
        defender->battleDefense = 0;

        attacker->battleCrit = 0;
        attacker->battleEffectiveCrit = 0;

        return;
    }

    if (GetItemWeaponEffect(attacker->weaponBefore) == WEAPON_EFFECT_ECLIPSE)
    {
        attacker->battleAttack = defender->unit.hpCur - 1;

        if (attacker->battleAttack == 0)
            attacker->battleAttack = 1;

        defender->battleDefense = 0;

        attacker->battleCrit = 0;
        attacker->battleEffectiveCrit = 0;
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
        struct BattleUnit* attacker;
        struct BattleUnit* defender;

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

void BattleGetBattleUnitOrder(struct BattleUnit** attacker, struct BattleUnit** defender)
{
    *attacker = &gBattleUnitA;
    *defender = &gBattleUnitB;
}

Bool BattleGetFollowUpOrder(struct BattleUnit** attacker, struct BattleUnit** defender)
{
    if (gBattleUnitB.battleSpeed > 250)
        return FALSE;

    if (ABS(gBattleUnitA.battleSpeed - gBattleUnitB.battleSpeed) < 4)
        return FALSE;

    if (gBattleUnitA.battleSpeed > gBattleUnitB.battleSpeed)
    {
        *attacker = &gBattleUnitA;
        *defender = &gBattleUnitB;
    }
    else
    {
        *attacker = &gBattleUnitB;
        *defender = &gBattleUnitA;
    }

    if (GetItemWeaponEffect((*attacker)->weaponBefore) == WEAPON_EFFECT_ECLIPSE)
        return FALSE;

    return TRUE;
}

Bool BattleGenerateRoundHits(struct BattleUnit* attacker, struct BattleUnit* defender)
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

int GetBattleUnitHitCount(struct BattleUnit* attacker)
{
    int result = 1;

    result <<= BattleCheckBraveEffect(attacker);

    return result;
}

int BattleCheckBraveEffect(struct BattleUnit* attacker)
{
    if (!(attacker->weaponAttributes & ITEM_ATTR_BRAVE))
        return FALSE;

    gBattleHitIt->attributes |= BATTLE_HIT_ATTR_BRAVE;
    return TRUE;
}

Bool BattleCheckTriangleAttack(struct BattleUnit* attacker, struct BattleUnit* defender)
{
    s8 adjacentLut[] =
    {
        -1,  0,
         0, -1,
        +1,  0,
         0, +1,
    };

    int i, count = 0;

    int triangleAttackAttr = UNIT_ATTRIBUTES(&attacker->unit) & UNIT_ATTR_TATTACK_ANY;

    int x = defender->unit.x;
    int y = defender->unit.y;

    int faction = UNIT_FACTION(&attacker->unit);

    gBattleSt.taUnitA = NULL;
    gBattleSt.taUnitB = NULL;

    for (i = 0; i < 4; ++i)
    {
        struct Unit* unit;

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

            if (!gBattleSt.taUnitA)
                gBattleSt.taUnitA = unit;
            else if (!gBattleSt.taUnitB)
                gBattleSt.taUnitB = unit;
        }
    }

    return count >= 2 ? TRUE : FALSE;
}

void BattleUpdateBattleStats(struct BattleUnit* attacker, struct BattleUnit* defender)
{
    gBattleSt.attack = attacker->battleAttack;
    gBattleSt.defense = defender->battleDefense;
    gBattleSt.hit = attacker->battleEffectiveHit;
    gBattleSt.crit = attacker->battleEffectiveCrit;
}

void BattleGenerateHitAttributes(struct BattleUnit* attacker)
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
        attacker->nonZeroDamage = TRUE;
}

void BattleGenerateHitTriangleAttack(struct BattleUnit* attacker, struct BattleUnit* defender)
{
    if (!(UNIT_ATTRIBUTES(&attacker->unit) & UNIT_ATTR_TATTACK_ANY))
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

    gBattleHitIt->attributes |= BATTLE_HIT_ATTR_TATTACK;

    gBattleSt.crit = 100;
    gBattleSt.hit  = 100;
}

void BattleGenerateHitEffects(struct BattleUnit* attacker, struct BattleUnit* defender)
{
    attacker->wexpGain++;

    if (!(gBattleHitIt->attributes & BATTLE_HIT_ATTR_MISS))
    {
        switch (GetItemWeaponEffect(attacker->weapon))
        {

        case WEAPON_EFFECT_POISON:
            defender->statusOut = UNIT_STATUS_POISON;
            gBattleHitIt->attributes |= BATTLE_HIT_ATTR_POISON;

            break;

        case WEAPON_EFFECT_ECLIPSE:
            gBattleHitIt->attributes |= BATTLE_HIT_ATTR_ECLIPSE;
            break;

        }

        if (GetItemWeaponEffect(attacker->weapon) == WEAPON_EFFECT_DEVIL && (BattleRandRoll(21 - attacker->unit.level, FALSE)))
        {
            gBattleHitIt->attributes |= BATTLE_HIT_ATTR_DEVIL;

            attacker->unit.hpCur -= gBattleSt.damage;

            if (attacker->unit.hpCur < 0)
                attacker->unit.hpCur = 0;
        }
        else
        {
            if (gBattleSt.damage > defender->unit.hpCur)
                gBattleSt.damage = defender->unit.hpCur;

            defender->unit.hpCur -= gBattleSt.damage;

            if (defender->unit.hpCur < 0)
                defender->unit.hpCur = 0;
        }

        if (GetItemWeaponEffect(attacker->weapon) == WEAPON_EFFECT_NOSFERATU)
        {
            attacker->unit.hpCur += gBattleSt.damage;

            if (attacker->unit.hpCur > attacker->unit.hpMax)
                attacker->unit.hpCur = attacker->unit.hpMax;

            gBattleHitIt->attributes |= BATTLE_HIT_ATTR_HPSTEAL;
        }
    }

    gBattleHitIt->damage = gBattleSt.damage;

    if (!(gBattleHitIt->attributes & BATTLE_HIT_ATTR_MISS) || attacker->weaponAttributes & (ITEM_ATTR_MAGIC | ITEM_ATTR_7))
    {
        attacker->weapon = GetItemAfterUse(attacker->weapon);

        if (!attacker->weapon)
            attacker->weaponBroke = TRUE;
    }
}

Bool BattleGenerateHit(struct BattleUnit* attacker, struct BattleUnit* defender)
{
    if (attacker == &gBattleUnitB)
        gBattleHitIt->info |= BATTLE_HIT_INFO_RETALIATION;

    BattleUpdateBattleStats(attacker, defender);

    BattleGenerateHitTriangleAttack(attacker, defender);
    BattleGenerateHitAttributes(attacker);
    BattleGenerateHitEffects(attacker, defender);

    if (attacker->unit.hpCur == 0 || defender->unit.hpCur == 0)
    {
        attacker->wexpGain++;

        gBattleHitIt->info |= BATTLE_HIT_INFO_FINISHES;

        if (gBattleUnitB.unit.hpCur == 0)
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
        if (!(gPlaySt.flags & PLAY_FLAG_5))
        {
            gBattleUnitA.expGain = GetBattleUnitExpGain(&gBattleUnitA, &gBattleUnitB);
            gBattleUnitB.expGain = GetBattleUnitExpGain(&gBattleUnitB, &gBattleUnitA);

            gBattleUnitA.unit.exp += gBattleUnitA.expGain;
            gBattleUnitB.unit.exp += gBattleUnitB.expGain;

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

void CheckBattleUnitLevelUp(struct BattleUnit* bu)
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
            bu->expGain -= bu->unit.exp;
            bu->unit.exp = 0xFF;
        }

        statGainTotal = 0;

        bu->hpChange  = GetStatIncrease(bu->unit.person->hpGrowth);
        statGainTotal += bu->hpChange;

        bu->powChange = GetStatIncrease(bu->unit.person->powGrowth);
        statGainTotal += bu->powChange;

        bu->sklChange = GetStatIncrease(bu->unit.person->sklGrowth);
        statGainTotal += bu->sklChange;

        bu->spdChange = GetStatIncrease(bu->unit.person->spdGrowth);
        statGainTotal += bu->spdChange;

        bu->defChange = GetStatIncrease(bu->unit.person->defGrowth);
        statGainTotal += bu->defChange;

        bu->resChange = GetStatIncrease(bu->unit.person->resGrowth);
        statGainTotal += bu->resChange;

        bu->lckChange = GetStatIncrease(bu->unit.person->lckGrowth);
        statGainTotal += bu->lckChange;

        if (statGainTotal == 0)
        {
            for (statGainTotal = 0; statGainTotal < 2; ++statGainTotal)
            {
                bu->hpChange = GetStatIncrease(bu->unit.person->hpGrowth);

                if (bu->hpChange)
                    break;

                bu->powChange = GetStatIncrease(bu->unit.person->powGrowth);

                if (bu->powChange)
                    break;

                bu->sklChange = GetStatIncrease(bu->unit.person->sklGrowth);

                if (bu->sklChange)
                    break;

                bu->spdChange = GetStatIncrease(bu->unit.person->spdGrowth);

                if (bu->spdChange)
                    break;

                bu->defChange = GetStatIncrease(bu->unit.person->defGrowth);

                if (bu->defChange)
                    break;

                bu->resChange = GetStatIncrease(bu->unit.person->resGrowth);

                if (bu->resChange)
                    break;

                bu->lckChange = GetStatIncrease(bu->unit.person->lckGrowth);

                if (bu->lckChange)
                    break;
            }
        }

        CheckBattleUnitStatCaps(GetUnit(bu->unit.id), bu);
    }
}

void UnitPromote(struct Unit* unit)
{
    int i;

    // substract to stats the bases of the previous job

    unit->hpMax -= unit->job->hpBase;
    unit->pow -= unit->job->powBase;
    unit->skl -= unit->job->sklBase;
    unit->spd -= unit->job->spdBase;
    unit->def -= unit->job->defBase;
    unit->res -= unit->job->resBase;

    for (i = 0; i < UNIT_WEAPON_EXP_COUNT; ++i)
        unit->weaponExp[i] -= unit->job->weaponExp[i];

    // promote!

    unit->job = GetJobInfo(unit->job->jidPromote);

    // add to stats the base of the new job

    unit->hpMax += unit->job->hpBase;
    unit->pow += unit->job->powBase;
    unit->skl += unit->job->sklBase;
    unit->spd += unit->job->spdBase;
    unit->def += unit->job->defBase;
    unit->res += unit->job->resBase;

    for (i = 0; i < UNIT_WEAPON_EXP_COUNT; ++i)
    {
        int wexp = unit->weaponExp[i];

        wexp += unit->job->weaponExp[i];

        if (wexp > WPN_EXP_S)
            wexp = WPN_EXP_S;

        unit->weaponExp[i] = wexp;
    }

    UnitCheckStatOverflow(unit);

    unit->level = 1;
    unit->exp = 0;
}

void GenerateBattleUnitStatGainsComparatively(struct BattleUnit* bu, struct Unit* unit)
{
    bu->hpChange = bu->unit.hpMax - unit->hpMax;
    bu->powChange = bu->unit.pow - unit->pow;
    bu->sklChange = bu->unit.skl - unit->skl;
    bu->spdChange = bu->unit.spd - unit->spd;
    bu->defChange = bu->unit.def - unit->def;
    bu->resChange = bu->unit.res - unit->res;
    bu->lckChange = bu->unit.lck - unit->lck;
    bu->conChange = bu->unit.conBonus - unit->conBonus;
}

void CheckBattleUnitStatCaps(struct Unit* unit, struct BattleUnit* bu)
{
    if ((unit->hpMax + bu->hpChange) > UNIT_HP_CAP(unit))
        bu->hpChange = UNIT_HP_CAP(unit) - unit->hpMax;

    if ((unit->pow + bu->powChange) > UNIT_POW_CAP(unit))
        bu->powChange = UNIT_POW_CAP(unit) - unit->pow;

    if ((unit->skl + bu->sklChange) > UNIT_SKL_CAP(unit))
        bu->sklChange = UNIT_SKL_CAP(unit) - unit->skl;

    if ((unit->spd + bu->spdChange) > UNIT_SPD_CAP(unit))
        bu->spdChange = UNIT_SPD_CAP(unit) - unit->spd;

    if ((unit->def + bu->defChange) > UNIT_DEF_CAP(unit))
        bu->defChange = UNIT_DEF_CAP(unit) - unit->def;

    if ((unit->res + bu->resChange) > UNIT_RES_CAP(unit))
        bu->resChange = UNIT_RES_CAP(unit) - unit->res;

    if ((unit->lck + bu->lckChange) > UNIT_LCK_CAP(unit))
        bu->lckChange = UNIT_LCK_CAP(unit) - unit->lck;
}

void BattleApplyUnitUpdates(void)
{
    struct Unit* instigator = GetUnit(gBattleUnitA.unit.id);
    struct Unit* target = GetUnit(gBattleUnitB.unit.id);

    if (gBattleUnitA.canCounter)
        gBattleUnitA.unit.items[gBattleUnitA.weaponItemSlot] = gBattleUnitA.weapon;

    if (gBattleUnitB.canCounter)
        gBattleUnitB.unit.items[gBattleUnitB.weaponItemSlot] = gBattleUnitB.weapon;

    UpdateUnitFromBattle(instigator, &gBattleUnitA);

    if (target)
        UpdateUnitFromBattle(target, &gBattleUnitB);
    else
        UpdateObstacleFromBattle(&gBattleUnitB);
}

int GetBattleUnitUpdatedWeaponExp(struct BattleUnit* bu)
{
    int result;

    if (UNIT_FACTION(&bu->unit) != FACTION_BLUE)
        return -1;

    if (bu->unit.hpCur == 0)
        return -1;

    if (gPlaySt.flags & PLAY_FLAG_5)
        return -1;

    if (gBmSt.flags & BM_FLAG_LINKARENA)
        return -1;

    if (!(gBattleSt.flags & BATTLE_FLAG_ARENA))
    {
        if (!bu->canCounter)
            return -1;

        if (!(bu->weaponAttributes & ITEM_ATTR_REQUIRES_EXP))
            return -1;

        if (bu->weaponAttributes & (ITEM_ATTR_LIGHTBRAND | ITEM_ATTR_LOCK_DRAGON))
            return -1;
    }

    result = bu->unit.weaponExp[bu->weaponKind] + bu->wexpGain;

    if (UNIT_ATTRIBUTES(&bu->unit) & UNIT_ATTR_PROMOTED)
    {
        if (result > WPN_EXP_S)
            result = WPN_EXP_S;
    }
    else
    {
        if (result > WPN_EXP_A)
            result = WPN_EXP_A;
    }

    return result;
}

Bool HasBattleUnitGainedWeaponLevel(struct BattleUnit* bu)
{
    int oldExp = bu->unit.weaponExp[bu->weaponKind];
    int newExp = GetBattleUnitUpdatedWeaponExp(bu);

    if (newExp < 0)
        return FALSE;

    return GetWeaponLevelFromExp(oldExp) != GetWeaponLevelFromExp(newExp);
}

void UpdateUnitFromBattle(struct Unit* unit, struct BattleUnit* bu)
{
    int tmp;

    unit->level = bu->unit.level;
    unit->exp   = bu->unit.exp;
    unit->hpCur = bu->unit.hpCur;
    unit->state = bu->unit.state;

    if (bu->statusOut >= 0)
        SetUnitStatus(unit, bu->statusOut);

    unit->hpMax += bu->hpChange;
    unit->pow += bu->powChange;
    unit->skl += bu->sklChange;
    unit->spd += bu->spdChange;
    unit->def += bu->defChange;
    unit->res += bu->resChange;
    unit->lck += bu->lckChange;

    UnitCheckStatOverflow(unit);

    tmp = GetBattleUnitUpdatedWeaponExp(bu);

    if (tmp > 0)
        unit->weaponExp[bu->weaponKind] = tmp;

    for (tmp = 0; tmp < ITEMSLOT_INV_COUNT; ++tmp)
        unit->items[tmp] = bu->unit.items[tmp];

    UnitRemoveInvalidItems(unit);

    if (bu->expGain)
        PidStatsAddExpGained(unit->person->id, bu->expGain);
}

void UpdateUnitDuringBattle(struct Unit* unit, struct BattleUnit* bu)
{
    int wexp;

    unit->hpCur = bu->unit.hpCur;

    wexp = GetBattleUnitUpdatedWeaponExp(bu);

    if (wexp > 0)
        unit->weaponExp[bu->weaponKind] = wexp;
}

void BattleApplyBallistaUpdates(void)
{
    if (gBattleSt.flags & BATTLE_FLAG_BALLISTA)
    {
        int uses = GetItemUses(gBattleUnitA.weapon);
        GetBallistaTrapAt(gBattleUnitA.unit.x, gBattleUnitA.unit.y)->extra = uses;
    }
}

void sub_8025780(void)
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

int GetUnitExpLevel(struct Unit* unit)
{
    int result = unit->level;

    if (UNIT_ATTRIBUTES(unit) & UNIT_ATTR_PROMOTED)
        result += 20;

    return result;
}

int GetUnitRoundExp(struct Unit* unit, struct Unit* other)
{
    int expLevel;

    expLevel = GetUnitExpLevel(unit);
    expLevel = expLevel - GetUnitExpLevel(other);
    expLevel = 31 - expLevel;

    if (expLevel < 0)
        expLevel = 0;

    return expLevel / unit->job->powerLevel;
}

int GetUnitPowerLevel(struct Unit* unit)
{
    int result = unit->level * unit->job->powerLevel;

    if (UNIT_ATTRIBUTES(unit) & UNIT_ATTR_PROMOTED)
        result += 20 * GetJobInfo(unit->job->jidPromote)->powerLevel;

    return result;
}

int GetUnitClassKillExpBonus(struct Unit* unit, struct Unit* defeated)
{
    int result = 0;

    if (UNIT_ATTRIBUTES(defeated) & UNIT_ATTR_STEAL)
        result += 20;

    if (UNIT_ATTRIBUTES(defeated) & UNIT_ATTR_BOSS)
        result += 40;

    return result;
}

int GetUnitKillExpBonus(struct Unit* unit, struct Unit* other)
{
    int result;

    if (other->hpCur != 0)
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

int GetBattleUnitExpGain(struct BattleUnit* bu, struct BattleUnit* other)
{
    int result;

    if (!CanBattleUnitGainExp(bu) || bu->unit.hpCur == 0 || UNIT_ATTRIBUTES(&other->unit) & UNIT_ATTR_BIT24)
        return 0;

    if (!bu->nonZeroDamage)
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
    if ((gBattleUnitA.weaponAttributes & ITEM_ATTR_STAFF) && !(gPlaySt.flags & PLAY_FLAG_5))
    {
        if (UNIT_FACTION(&gBattleUnitA.unit) == FACTION_BLUE)
            gBattleUnitA.wexpGain++;

        gBattleUnitA.expGain = GetBattleUnitStaffExp(&gBattleUnitA);
        gBattleUnitA.unit.exp += gBattleUnitA.expGain;

        CheckBattleUnitLevelUp(&gBattleUnitA);
    }
}

int GetBattleUnitStaffExp(struct BattleUnit* bu)
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

    if (gPlaySt.flags & PLAY_FLAG_5)
        return;

    gBattleUnitA.expGain = 10;
    gBattleUnitA.unit.exp += 10;

    CheckBattleUnitLevelUp(&gBattleUnitA);
}

void BattleUnitTargetSetEquippedWeapon(struct BattleUnit* bu)
{
    int i;

    if (bu->weaponBefore)
        return;

    bu->weaponBefore = GetUnitEquippedWeapon(&bu->unit);

    if (bu->weaponBefore)
        return;

    if (!UnitKnowsMagic(&bu->unit))
        return;

    for (i = 0; i < ITEMSLOT_INV_COUNT; ++i)
    {
        if (CanUnitUseStaff(&bu->unit, bu->unit.items[i]) == TRUE)
        {
            bu->weaponBefore = bu->unit.items[i];
            break;
        }
    }
}

void BattleUnitTargetCheckCanCounter(struct BattleUnit* bu)
{
    if (!bu->canCounter)
    {
        bu->battleAttack = 0xFF;
        bu->battleHit = 0xFF;
        bu->battleEffectiveHit = 0xFF;
        bu->battleCrit = 0xFF;
        bu->battleEffectiveCrit = 0xFF;
    }
}

void BattleApplyReaverEffect(struct BattleUnit* attacker, struct BattleUnit* defender)
{
    // those <<1>>1 are useless but without them it doesn't match :/

    attacker->wtHitBonus = -attacker->wtHitBonus <<1>>1;
    attacker->wtDamageBonus = -attacker->wtDamageBonus <<1>>1;
    defender->wtHitBonus = -defender->wtHitBonus <<1>>1;
    defender->wtDamageBonus = -defender->wtDamageBonus <<1>>1;
}

void BattleApplyWeaponTriangleEffect(struct BattleUnit* attacker, struct BattleUnit* defender)
{
    struct WeaponTriangleRule const* it;

    for (it = sWeaponTriangleRules; it->attackerKind >= 0; ++it)
    {
        if ((attacker->weaponKind == it->attackerKind) && (defender->weaponKind == it->defenderKind))
        {
            attacker->wtHitBonus = it->hitBonus;
            attacker->wtDamageBonus = it->damageBonus;

            defender->wtHitBonus = -it->hitBonus;
            defender->wtDamageBonus = -it->damageBonus;

            break;
        }
    }

    if (attacker->weaponAttributes & ITEM_ATTR_REVERTS_TRIANGLE)
        BattleApplyReaverEffect(attacker, defender);

    if (defender->weaponAttributes & ITEM_ATTR_REVERTS_TRIANGLE)
        BattleApplyReaverEffect(attacker, defender);
}

void BattleInitTargetCanCounter(void)
{
    // Target cannot counter if either units are using "uncounterable" weapons

    if ((gBattleUnitA.weaponAttributes | gBattleUnitB.weaponAttributes) & ITEM_ATTR_7)
    {
        gBattleUnitB.weapon = 0;
        gBattleUnitB.canCounter = FALSE;
    }

    // Target cannot counter if a berserked player unit is attacking another player unit

    if (gBattleUnitA.unit.status == UNIT_STATUS_BERSERK)
    {
        if ((UNIT_FACTION(&gBattleUnitA.unit) == FACTION_BLUE) && (UNIT_FACTION(&gBattleUnitB.unit) == FACTION_BLUE))
        {
            gBattleUnitB.weapon = 0;
            gBattleUnitB.canCounter = FALSE;
        }
    }
}

void InitObstacleBattleUnit(void)
{
    ClearUnit(&gBattleUnitB.unit);

    gBattleUnitB.unit.id = 0;

    gBattleUnitB.unit.person = GetPersonInfo(PID_WALL);
    gBattleUnitB.unit.job = GetJobInfo(JID_OBSTACLE);

    gBattleUnitB.unit.hpMax = GetChapterInfo(gPlaySt.chapter)->wallHp;
    gBattleUnitB.unit.hpCur = gAction.extra;

    gBattleUnitB.unit.x = gAction.xTarget;
    gBattleUnitB.unit.y = gAction.yTarget;
}

void ComputeBattleObstacleStats(void)
{
    gBattleUnitA.battleEffectiveHit = 100;
    gBattleUnitA.battleEffectiveCrit = 0;

    gBattleUnitB.battleSpeed = 0xFF;
    gBattleUnitB.hpPrevious = gBattleUnitB.unit.hpCur;

    gBattleUnitB.wtHitBonus = 0;
    gBattleUnitB.wtDamageBonus = 0;
}

void UpdateObstacleFromBattle(struct BattleUnit* bu)
{
    struct Trap* trap = GetTrapAt(bu->unit.x, bu->unit.y);

    if (!trap)
        trap = GetTrapAt(bu->unit.x, bu->unit.y-1);

    trap->extra = bu->unit.hpCur;

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

    gPal[0] = 0;
    EnablePalSync();

    RenderMap();

    if (sub_8047CB8())
    {
        sub_804256C(0);
        sub_8047CC8();
    }
    else
    {
        MU_EndAll();
        RenderMap();

        sub_80627D0();

        gBattleSt.flags |= BATTLE_FLAG_MAPANIMS;
    }
}

int GetUnitSoloBattleAnimType(struct Unit* unit)
{
    // TODO: battle anim type constants

    if (unit->state & US_SOLOANIM_1)
        return 0;

    if (unit->state & US_SOLOANIM_2)
        return 3;

    return 1;
}

int GetBattleAnimType(void)
{
    // TODO: battle anim type constants

    // If not solo anim, return global type

    if (gPlaySt.configBattleAnim != 2)
        return gPlaySt.configBattleAnim;

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

void BattlePrintDebugUnitInfo(struct BattleUnit* actor, struct BattleUnit* target)
{
    // prints battle unit information to debug output
}

void BattlePrintDebugHitInfo(void)
{
    struct BattleHit* it;

    for (it = gBattleHits; !(it->info & BATTLE_HIT_INFO_END); ++it)
    {
        // prints battle rounds information to debug output
    }
}

void BattleInitItemEffect(struct Unit* unit, int itemSlot)
{
    int item = unit->items[itemSlot];

    if (itemSlot < 0)
        item = 0;

    gBattleSt.flags = 0;

    InitBattleUnit(&gBattleUnitA, unit);

    SetBattleUnitTerrainBonusesAuto(&gBattleUnitA);
    ComputeBattleUnitBaseDefense(&gBattleUnitA);
    ComputeBattleUnitSupportBonuses(&gBattleUnitA, NULL);

    gBattleUnitA.battleAttack = 0xFF;
    gBattleUnitA.battleEffectiveHit = 100;
    gBattleUnitA.battleEffectiveCrit = 0xFF;

    gBattleUnitA.weapon = item;
    gBattleUnitA.weaponBefore = item;
    gBattleUnitA.weaponItemSlot = itemSlot;
    gBattleUnitA.weaponKind = GetItemKind(item);
    gBattleUnitA.weaponAttributes = GetItemAttributes(item);

    gBattleUnitA.canCounter = TRUE;
    gBattleUnitA.hasItemEffectTarget = FALSE;

    gBattleUnitA.statusOut = -1;
    gBattleUnitB.statusOut = -1;

    ClearBattleHits();
}

void BattleInitItemEffectTarget(struct Unit* unit)
{
    InitBattleUnit(&gBattleUnitB, unit);

    SetBattleUnitTerrainBonusesAuto(&gBattleUnitB);
    ComputeBattleUnitBaseDefense(&gBattleUnitB);
    ComputeBattleUnitSupportBonuses(&gBattleUnitB, NULL);

    gBattleUnitB.battleAttack = 0xFF;
    gBattleUnitB.battleEffectiveHit = 0xFF;
    gBattleUnitB.battleEffectiveCrit = 0xFF;

    gBattleUnitB.weaponBefore = 0;

    BattleUnitTargetSetEquippedWeapon(&gBattleUnitB);

    gBattleUnitA.hasItemEffectTarget = TRUE;

    if (GetItemAttributes(gBattleUnitB.weaponBefore) & ITEM_ATTR_LOCK_DRAGON)
        if (gBattleUnitB.unit.job->id != JID_DEMONDRAGON)
            gBattleUnitB.weaponBefore = 0;
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

    if (gBattleUnitA.canCounter)
    {
        if (GetItemAttributes(gBattleUnitA.weapon) & ITEM_ATTR_STAFF)
            gBattleUnitA.weaponBroke = TRUE;

        gBattleUnitA.weapon = GetItemAfterUse(gBattleUnitA.weapon);
        gBattleUnitA.unit.items[gBattleUnitA.weaponItemSlot] = gBattleUnitA.weapon;

        if (gBattleUnitA.weapon)
            gBattleUnitA.weaponBroke = FALSE;
    }

    SpawnProcLocking(ProcScr_DummyBattleAnimLock, proc);
}

int GetOffensiveStaffAccuracy(struct Unit* unit, struct Unit* target)
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

void BattleGenerateArena(struct Unit* unit)
{
    struct Unit* target = gArenaSt.opponent;

    int something = gBmSt.unk_3C;

    gBattleSt.flags = BATTLE_FLAG_REAL | BATTLE_FLAG_ARENA;

    InitBattleUnit(&gBattleUnitA, unit);
    InitBattleUnit(&gBattleUnitB, target);

    if (gAction.extra != 0)
    {
        gBattleUnitB.unit.hpCur = gAction.extra;
        gBattleUnitB.hpPrevious = gAction.extra;
    }

    gBattleSt.range = gArenaSt.range;

    gBattleUnitB.unit.x = gBattleUnitA.unit.x + gArenaSt.range;
    gBattleUnitB.unit.y = gBattleUnitA.unit.y;

    SetBattleUnitWeapon(&gBattleUnitA, ITEMSLOT_ARENA_PLAYER);
    SetBattleUnitWeapon(&gBattleUnitB, ITEMSLOT_ARENA_OPPONENT);

    BattleApplyWeaponTriangleEffect(&gBattleUnitA, &gBattleUnitB);

    gAction.suspendPoint = SUSPEND_POINT_DURING_ARENA;
    sub_80857B0(SAVE_ID_SUSPEND0);

    SetBattleUnitTerrainBonusesAuto(&gBattleUnitA);
    SetBattleUnitTerrainBonuses(&gBattleUnitB, 8); // TODO: terrain id constants

    BattleGenerate(unit, target);

    if (gBattleUnitB.unit.hpCur == 0)
        BattleApplyExpGains();

    UpdateUnitDuringBattle(unit, &gBattleUnitA);

    if (!something || (gBattleUnitB.unit.hpCur == 0))
        sub_8084D64();

    BattlePrintDebugUnitInfo(&gBattleUnitA, &gBattleUnitB);
}

Bool BattleIsTriangleAttack(void)
{
    return (gBattleHits[0].attributes & BATTLE_HIT_ATTR_TATTACK) != 0;
}

Bool DidBattleUnitBreakWeapon(struct BattleUnit* bu)
{
    if (bu->unit.hpCur == 0)
        return FALSE;

    return bu->weaponBroke;
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
