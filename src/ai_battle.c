#include "ai_battle.h"

#include "item.h"
#include "unit.h"
#include "map.h"
#include "mapwork.h"
#include "battle.h"
#include "faction.h"
#include "trap.h"
#include "ai_decide.h"
#include "ai_utility.h"
#include "ai_data.h"

#include "constants/iids.h"
#include "constants/terrains.h"

static int AiGetDamageDealtCombatScoreComponent(void);
static int AiGetOpponentLowHpScoreComponent(void);
static int AiGetFriendZoneCombatScoreComponent(void);
static int AiGetTargetJobCombatScoreComponent(void);
static int AiGetTurnCombatScoreComponent(void);
static int AiGetDamageTakenScoreComponent(void);
static int AiGetDangerScoreComponent(void);
static int AiGetLowHpScoreComponent(void);

static struct AiCombatScoreCoefficients const * sCombatScoreCoefficients;

bool AiAttemptOffensiveAction(bool (* is_enemy)(struct Unit * unit))
{
    struct AiCombatSimulationSt tmpResult;
    struct AiCombatSimulationSt finResult;

    int i;

    if (UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_STEAL)
    {
        if (GetUnitItemCount(gActiveUnit) < 5)
        {
            MapFlood_UpToMove(gActiveUnit);
            MapMovementMarkFloodEdges();

            if (AiAttemptStealActionWithinMovement() == TRUE)
                return FALSE;
        }
    }

    finResult.target_id = 0;
    finResult.score = 0;

#if BUGFIX
    finResult.x_move = 0;
    finResult.y_move = 0;
    finResult.item_slot = 0;
#endif

    if (gAiSt.flags & AI_FLAG_STAY)
    {
        MapFill(gMapMovement, -1);
        gMapMovement[gActiveUnit->y][gActiveUnit->x] = 0;
    }
    else
    {
        MapFlood_UpToMove(gActiveUnit);
    }

    SetWorkingMap(gMapRange);

    for (i = 0; i < ITEMSLOT_INV_COUNT; ++i)
    {
        u16 item = gActiveUnit->items[i];

        if (item == 0)
            break;

        if (!CanUnitUseWeapon(gActiveUnit, item))
            continue;

        tmpResult.item_slot = i;

        FOR_UNITS(1, 0xC0, unit,
        {
            if (unit->flags & (UNIT_FLAG_HIDDEN | UNIT_FLAG_DEAD | UNIT_FLAG_RESCUED))
                continue;

            if (!is_enemy(unit))
                continue;

            if (!AiReachesByBirdsEyeDistance(gActiveUnit, unit, item))
                continue;

            AiFillReversedAttackRangeMap(unit, item);

            tmpResult.target_id = unit->id;

            if (!AiSimulateBestBattleAgainstTarget(&tmpResult))
                continue;

            if (tmpResult.score >= finResult.score)
            {
                finResult = tmpResult;
                finResult.item_slot = i;
            }
        })
    }

    if (UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_BALLISTA)
    {
        if (AiAttemptBallistaCombat(is_enemy, &tmpResult) == TRUE)
        {
            if (tmpResult.score >= finResult.score)
            {
                finResult = tmpResult;
            }
        }
    }

    if (finResult.score != 0 || finResult.target_id != 0)
    {
        AiSetDecision(finResult.x_move, finResult.y_move,
            AI_ACTION_COMBAT, finResult.target_id, finResult.item_slot, 0, 0);
    }

#if BUGFIX
    return TRUE;
#endif
}

bool AiAttemptCombatWithinMovement(bool (* is_enemy)(struct Unit * unit))
{
    struct AiCombatSimulationSt tmpResult;
    struct AiCombatSimulationSt finResult;

    int i;

    finResult.target_id = 0;
    finResult.score = 0;

#if BUGFIX
    finResult.x_move = 0;
    finResult.y_move = 0;
    finResult.item_slot = 0;
#endif

    SetWorkingMap(gMapRange);

    for (i = 0; i < ITEMSLOT_INV_COUNT; ++i)
    {
        u16 item = gActiveUnit->items[i];

        if (item == 0)
            break;

        if (!CanUnitUseWeapon(gActiveUnit, item))
            continue;

        tmpResult.item_slot = i;

        FOR_UNITS(1, 0xC0, unit,
        {
            if (unit->flags & (UNIT_FLAG_HIDDEN | UNIT_FLAG_DEAD | UNIT_FLAG_RESCUED))
                continue;

            if (!is_enemy(unit))
                continue;

            if (!AiReachesByBirdsEyeDistance(gActiveUnit, unit, item))
                continue;

            AiFillReversedAttackRangeMap(unit, item);

            tmpResult.target_id = unit->id;

            if (!AiSimulateBestBattleAgainstTarget(&tmpResult))
                continue;

            if (tmpResult.score >= finResult.score)
            {
                finResult = tmpResult;
                finResult.item_slot = i;
            }
        })
    }

    if (UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_BALLISTA)
    {
        if (AiAttemptBallistaCombat(is_enemy, &tmpResult) == TRUE)
        {
            if (tmpResult.score >= finResult.score)
            {
                finResult = tmpResult;
            }
        }
    }

    if (finResult.score != 0 || finResult.target_id != 0)
    {
        AiSetDecision(finResult.x_move, finResult.y_move,
            AI_ACTION_COMBAT, finResult.target_id, finResult.item_slot, 0, 0);
    }

#if BUGFIX
    return TRUE;
#endif
}

void AiFillReversedAttackRangeMap(struct Unit * unit, u16 item)
{
    // reverse as in "this is the range this unit can be attacked *from*"

    MapFill(gMapRange, 0);
    MapIncInBoundedRange(unit->x, unit->y, GetItemMinRange(item), GetItemMaxRange(item));
}

void AiFloodMovementAndRange(struct Unit * unit, u16 move, u16 item)
{
    int ix, iy;

    SetWorkingMovTable(unit->jinfo->mov_table);

    SetWorkingMap(gMapMovement);
    BeginMapFlood(unit->x, unit->y, move, unit->id);

    MapFill(gMapRange, 0);

    for (iy = gMapSize.y-1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x-1; ix >= 0; --ix)
        {
            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            MapIncInBoundedRange(ix, iy, GetItemMinRange(item), GetItemMaxRange(item));
        }
    }
}

bool AiAttemptBallistaCombat(bool (* is_enemy)(struct Unit * unit), struct AiCombatSimulationSt * st)
{
    struct AiCombatSimulationSt tmpResult;

    int ix, iy;
    int i;

    u16 item;

    int ballistaCount = 0;

    SHOULD_BE_STATIC u8 SHOULD_BE_CONST ballista_iid_table[] =
    {
        IID_BALLISTA,
        IID_LONGBALLISTA,
        IID_KILLERBALLISTA,
    };

    for (iy = gMapSize.y-1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x-1; ix >= 0; --ix)
        {
            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if (gMapTerrain[iy][ix] == TERRAIN_BALLISTA || gMapTerrain[iy][ix] == TERRAIN_LONGBALLISTA || gMapTerrain[iy][ix] == TERRAIN_KILLERBALLISTA)
            {
                item = GetBallistaItemAt(ix, iy);

                if (item != 0)
                {
                    ballistaCount++;
                    gMapMovementSigned[iy][ix] = item;
                }
                else
                {
                    gMapMovementSigned[iy][ix] = -1;
                }
            }
            else
            {
                gMapMovementSigned[iy][ix] = -1;
            }
        }
    }

    if (ballistaCount == 0)
        return FALSE;

    st->target_id = 0;
    st->score = 0;

    for (i = 0; i < 3; ++i)
    {
        item = ballista_iid_table[i];
        st->item_slot = -1;

        FOR_UNITS_ALL(unit,
        {
            if (unit->flags & (UNIT_FLAG_HIDDEN | UNIT_FLAG_DEAD | UNIT_FLAG_RESCUED))
                continue;

            if (!is_enemy(unit))
                continue;

            if (!AiReachesByBirdsEyeDistance(gActiveUnit, unit, item))
                continue;

            AiFillReversedAttackRangeMap(unit, item);

            tmpResult.target_id = unit->id;

            if (!AiSimulateBestBallistaBattleAgainstTarget(&tmpResult, item))
                continue;

            if (tmpResult.score >= st->score)
            {
                st->x_move = tmpResult.x_move;
                st->y_move = tmpResult.y_move;
                st->target_id = tmpResult.target_id;
                st->score = tmpResult.score;
            }
        })
    }

    if (st->score != 0 || st->target_id != 0)
        return TRUE;

    return FALSE;
}

static u8 AiAttemptStealAction_GetMovementAt(int x, int y)
{
    if (gMapMovementSigned[y][x] >= MAP_MOVEMENT_MAX)
        return -1;

    if (gMapUnit[y][x] != 0 && gMapUnit[y][x] != gActiveUnitId)
        return -1;

    return gMapMovement[y][x];
}

bool AiAttemptStealActionWithinMovement(void)
{
    int ix, iy;

    struct Vec2i pos;

    u8 item_slot = 0;
    u8 rank = UINT8_MAX;
    u8 target = 0;

    for (iy = gMapSize.y-1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x-1; ix >= 0; --ix)
        {
            struct Vec2i posTmp;
            struct Unit * unit;
            i8 slotTmp;
            u8 rankTmp;

            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if (gMapUnit[iy][ix] == 0)
                continue;

            if (AreUnitIdsAllied(gActiveUnitId, gMapUnit[iy][ix]) == TRUE)
                continue;

            if (!AiFindBestAdjacentPositionByFunc(ix, iy, AiAttemptStealAction_GetMovementAt, &posTmp))
                continue;

            unit = GetUnit(gMapUnit[iy][ix]);
            slotTmp = AiGetUnitStealItemSlot(unit);

            if (slotTmp < 0)
                continue;

            // NOTE: this isn't using the item getter!
            rankTmp = AiGetItemStealRank(ITEM_IID(unit->items[slotTmp]));

            if (rank < rankTmp)
                continue;

            rank = rankTmp;
            pos.x = posTmp.x;
            pos.y = posTmp.y;
            target = gMapUnit[iy][ix];
            item_slot = slotTmp;
        }
    }

    if (rank != UINT8_MAX)
    {
        gActiveUnit->ai_counter++;
        AiSetDecision(pos.x, pos.y, AI_ACTION_STEAL, target, item_slot, 0, 0);

        return TRUE;
    }

    return FALSE;
}

bool AiSimulateBestBattleAgainstTarget(struct AiCombatSimulationSt * st)
{
    int ix, iy;

    u32 score = 0;

    for (iy = gMapSize.y-1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x-1; ix >= 0; --ix)
        {
            u32 scoreTmp;

            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if (gMapRangeSigned[iy][ix] == 0)
                continue;

            if (gMapUnit[iy][ix] != 0 && gMapUnit[iy][ix] != gActiveUnitId)
                continue;

            scoreTmp = AiGetCombatPositionScore(ix, iy, st);

            if (scoreTmp <= score)
                continue;

            st->x_move = ix;
            st->y_move = iy;
            score = scoreTmp;
        }
    }

    if (score == 0)
        return FALSE;

    return AiSimulateBattleAgainstTargetAtPosition(st);
}

bool AiSimulateBestBallistaBattleAgainstTarget(struct AiCombatSimulationSt * st, u16 item)
{
    int ix, iy;

    u32 score = 0;

    for (iy = gMapSize.y-1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x-1; ix >= 0; --ix)
        {
            u32 scoreTmp;

            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if (gMapMovementSigned[iy][ix] != (u8) item)
                continue;

            if (gMapRangeSigned[iy][ix] == 0)
                continue;

            if (gMapUnit[iy][ix] != 0 && gMapUnit[iy][ix] != gActiveUnitId)
                continue;

            scoreTmp = AiGetCombatPositionScore(ix, iy, st);

            if (scoreTmp <= score)
                continue;

            st->x_move = ix;
            st->y_move = iy;
            score = scoreTmp;
        }
    }

    if (score == 0)
        return FALSE;

    return AiSimulateBattleAgainstTargetAtPosition(st);
}

u32 AiGetCombatPositionScore(int x, int y, struct AiCombatSimulationSt * st)
{
    int score;

    score  = AiGetInRangeCombatPositionScoreComponent(x, y, GetUnit(st->target_id));
    score += AiGetTerrainCombatPositionScoreComponent(x, y);
    score += AiGetFriendZoneCombatPositionScoreComponent(x, y);
    score -= gMapMovementSigned[y][x];
    score -= gMapOther[y][x]/8;

    score += INT32_MAX;

    return score;
}

bool AiIsBadFight(struct AiCombatSimulationSt * st)
{
    u16 item = gActiveUnit->items[st->item_slot];
    struct Unit * unit = GetUnit(st->target_id);

    if (GetItemIid(item) == IID_ECLIPSE)
    {
        if (GetUnitCurrentHp(unit) <= 5)
        {
            st->score = 0;
            return TRUE;
        }
    }

    return FALSE;
}

bool AiSimulateBattleAgainstTargetAtPosition(struct AiCombatSimulationSt * st)
{
    if (st->item_slot != UINT16_MAX)
    {
        BattleGenerateSimulation(
            gActiveUnit, GetUnit(st->target_id),
            st->x_move, st->y_move, st->item_slot);
    }
    else
    {
        BattleGenerateBallistaSimulation(
            gActiveUnit, GetUnit(st->target_id),
            st->x_move, st->y_move);
    }

    if (!AiIsBadFight(st))
    {
        AiComputeCombatScore(st);
        return TRUE;
    }

    return FALSE;
}

int AiGetDamageDealtCombatScoreComponent(void)
{
    int score;

    if (gBattleUnitB.unit.hp == 0)
        return 50;

    score = gBattleUnitA.battle_attack - gBattleUnitB.battle_defense;
    score = gBattleUnitA.battle_effective_hit * score;

    if (score < 0)
        score = 0;

    score = Div(score, 100);
    score = sCombatScoreCoefficients->coef_damage_dealt * score;

    if (score > 40)
        score = 40;

    return score;
}

int AiGetOpponentLowHpScoreComponent(void)
{
    int score;

    score = 20 - gBattleUnitB.unit.hp;
    score = sCombatScoreCoefficients->coef_low_hp_opponent * score;

    if (score < 0)
        score = 0;

    return score;
}

int AiGetFriendZoneCombatScoreComponent(void)
{
    struct RangeScore
    {
        /* 00 */ i8 x;
        /* 01 */ i8 y;
        /* 02 */ i8 score;
    };

    static struct RangeScore CONST_DATA list[] =
    {
        // one of these entries is bugged!

        #define ent(x, y) { (x), (y), 4-(((x)>0?(x):-(x)) + ((y)>0?(y):-(y))) }

                                               ent( 0, -3),
        ent(-3, +1), /* BUG! */                ent( 0, -2), ent(+1, -2),
                     ent(-2, -1), ent(-1, -1), ent( 0, -1), ent(+1, -1), ent(+2, -1),
        ent(-3,  0), ent(-2,  0), ent(-1,  0),              ent(+1,  0), ent(+2,  0), ent(+3,  0),
                     ent(-2, +1), ent(-1, +1), ent( 0, +1), ent(+1, +1), ent(+2, +1),
                                  ent(-1, +2), ent( 0, +2), ent(+1, +2),
                                               ent( 0, +3),

        #undef ent

        { INT8_MAX },
    };

    struct RangeScore const * it;

    int score = 0;

    for (it = list; it->x != INT8_MAX; ++it)
    {
        u8 x = gBattleUnitA.unit.x + it->x;
        u8 y = gBattleUnitA.unit.y + it->y;

        u8 u = gMapUnit[y][x];

        if (x >= gMapSize.x)
            continue;

        if (y >= gMapSize.y)
            continue;

        if (u == 0)
            continue;

        if (AreUnitIdsAllied(gBattleUnitA.unit.id, u) == TRUE)
            score += it->score;
    }

    score = sCombatScoreCoefficients->coef_friend_zone * score;

    if (score > 10)
        score = 10;

    return score;
}

int AiGetTargetJobCombatScoreComponent(void)
{
    u8 rank = AiGetJobRank(gBattleUnitB.unit.jinfo->id);

    int score;

    score = sCombatScoreCoefficients->job_rank_bonuses[rank];
    score = sCombatScoreCoefficients->coef_job_rank_bonus * score;

    if (score > 20)
        score = 20;

    return score;
}

int AiGetTurnCombatScoreComponent(void)
{
    return gPlaySt.turn * sCombatScoreCoefficients->coef_turn_number;
}

int AiGetDamageTakenScoreComponent(void)
{
    int score;

    if (gBattleUnitB.weapon == 0)
        return -10;

    score = gBattleUnitB.battle_attack - gBattleUnitA.battle_defense;
    score = gBattleUnitB.battle_effective_hit * score;

    if (score < 0)
        score = 0;

    score = Div(score, 100);
    score = sCombatScoreCoefficients->coef_damage_taken * score;

    if (score > 40)
        score = 40;

    return score;
}

int AiGetDangerScoreComponent(void)
{
    int score;

    score = gMapOther[gBattleUnitA.unit.y][gBattleUnitA.unit.x]/8;
    score = sCombatScoreCoefficients->coef_danger * score;

    if (score > 20)
        score = 20;

    return score;
}

int AiGetLowHpScoreComponent(void)
{
    int score;

    score = 20 - gBattleUnitA.unit.hp;
    score = sCombatScoreCoefficients->coef_low_hp_self * score;

    if (score < 0)
        score = 0;

    return score;
}

void AiComputeCombatScore(struct AiCombatSimulationSt * st)
{
    int score;
    int backup;

    sCombatScoreCoefficients = gAiCombatScoreCoefficientTable + gAiSt.combat_wgt_table_id;

    score = AiGetDamageDealtCombatScoreComponent();
    backup = score;

    score += AiGetOpponentLowHpScoreComponent();
    score += AiGetFriendZoneCombatScoreComponent();
    score += AiGetTargetJobCombatScoreComponent();
    score += AiGetTurnCombatScoreComponent();
    score -= AiGetDamageTakenScoreComponent();
    score -= AiGetDangerScoreComponent();
    score -= AiGetLowHpScoreComponent();

    if (score < 0)
        score = 0;

    if (score != 0)
        score = score*40;
    else
        score = backup;

    st->score = score;
}

int AiGetInRangeCombatPositionScoreComponent(int x, int y, struct Unit * unit)
{
    int dist = RECT_DISTANCE(unit->x, unit->y, x, y);
    int item = GetUnitEquippedWeapon(unit);

    if (item == 0)
        return 0;

    if (dist > GetItemMaxRange(item) || dist < GetItemMinRange(item))
        return 50;

    return 0;
}

int AiGetTerrainCombatPositionScoreComponent(int x, int y)
{
    int terrain = gMapTerrain[y][x];

    return gActiveUnit->jinfo->avo_terrain_table[terrain]
         + gActiveUnit->jinfo->def_terrain_table[terrain]
         + gActiveUnit->jinfo->res_terrain_table[terrain];
}

int AiGetFriendZoneCombatPositionScoreComponent(int x, int y)
{
    static struct Vec2i CONST_DATA range3offsets[] =
    {
                                            {  0, -3 },
                                { -1, -2 }, {  0, -2 }, { +1, -2 },
                    { -2, -1 }, { -1, -1 }, {  0, -1 }, { +1, -1 }, { +2, -1 },
        { -3,  0 }, { -2,  0 }, { -1,  0 },             { +1,  0 }, { +2,  0 }, { +3,  0 },
                    { -2, +1 }, { -1, +1 }, {  0, +1 }, { +1, +1 }, { +2, +1 },
                                { -1, +2 }, {  0, +2 }, { +1, +2 },
                                            {  0, +3 },

        { 9999, 9999 },
    };

    struct Vec2i const * it;

    int result = 0;

    for (it = range3offsets; it->x != 9999; ++it)
    {
        if (gMapUnit[y + it->y][x + it->x] == 0)
            continue;

        if (AreUnitIdsAllied(gActiveUnitId, gMapUnit[y + it->y][x + it->x]) == TRUE)
            result += 5;
        else
            result -= 5;
    }

    return result;
}
