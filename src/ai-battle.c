
#include "ai-battle.h"

#include "item.h"
#include "unit.h"
#include "map.h"
#include "mapwork.h"
#include "battle.h"
#include "faction.h"
#include "trap.h"
#include "ai-decide.h"
#include "ai-utility.h"
#include "ai-data.h"

#include "constants/items.h"
#include "constants/terrains.h"

static int AiGetDamageDealtCombatScoreComponent(void);
static int AiGetOpponentLowHpScoreComponent(void);
static int AiGetFriendZoneCombatScoreComponent(void);
static int AiGetTargetJobCombatScoreComponent(void);
static int AiGetTurnCombatScoreComponent(void);
static int AiGetDamageTakenScoreComponent(void);
static int AiGetDangerScoreComponent(void);
static int AiGetLowHpScoreComponent(void);

static struct AiCombatScoreCoefficients const* sCombatScoreCoefficients;

bool AiAttemptOffensiveAction(bool(*isEnemy)(struct Unit* unit))
{
    struct AiCombatSimulationSt tmpResult;
    struct AiCombatSimulationSt finResult;

    int i;

    if (UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_STEAL)
    {
        if (GetUnitItemCount(gActiveUnit) < 5)
        {
            MapFlood_08019344(gActiveUnit);
            MapMovementMarkFloodEdges();

            if (AiAttemptStealActionWithinMovement() == TRUE)
                return FALSE;
        }
    }

    finResult.targetId = 0;
    finResult.score = 0;

    if (gAiSt.flags & AI_FLAG_1)
    {
        MapFill(gMapMovement, -1);
        gMapMovement[gActiveUnit->y][gActiveUnit->x] = 0;
    }
    else
    {
        MapFlood_08019344(gActiveUnit);
    }

    SetWorkingMap(gMapRange);

    for (i = 0; i < ITEMSLOT_INV_COUNT; ++i)
    {
        u16 item = gActiveUnit->items[i];

        if (item == 0)
            break;

        if (!CanUnitUseWeapon(gActiveUnit, item))
            continue;

        tmpResult.itemSlot = i;

        FOR_UNITS(1, 0xC0, unit,
        {
            if (unit->state & (US_HIDDEN | US_DEAD | US_RESCUED))
                continue;

            if (!isEnemy(unit))
                continue;

            if (!AiReachesByBirdsEyeDistance(gActiveUnit, unit, item))
                continue;

            AiFillReversedAttackRangeMap(unit, item);

            tmpResult.targetId = unit->id;

            if (!AiSimulateBestBattleAgainstTarget(&tmpResult))
                continue;

            if (tmpResult.score >= finResult.score)
            {
                finResult = tmpResult;
                finResult.itemSlot = i;
            }
        })
    }

    if (UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_BALLISTA)
    {
        if (AiAttemptBallistaCombat(isEnemy, &tmpResult) == TRUE)
        {
            if (tmpResult.score >= finResult.score)
            {
                finResult = tmpResult;
            }
        }
    }

    if (finResult.score != 0 || finResult.targetId != 0)
    {
        AiSetDecision(finResult.xMove, finResult.yMove,
            AI_ACTION_COMBAT, finResult.targetId, finResult.itemSlot, 0, 0);
    }
}

bool AiAttemptCombatWithinMovement(bool(*isEnemy)(struct Unit* unit))
{
    struct AiCombatSimulationSt tmpResult;
    struct AiCombatSimulationSt finResult;

    int i;

    finResult.targetId = 0;
    finResult.score = 0;

    SetWorkingMap(gMapRange);

    for (i = 0; i < ITEMSLOT_INV_COUNT; ++i)
    {
        u16 item = gActiveUnit->items[i];

        if (item == 0)
            break;

        if (!CanUnitUseWeapon(gActiveUnit, item))
            continue;

        tmpResult.itemSlot = i;

        FOR_UNITS(1, 0xC0, unit,
        {
            if (unit->state & (US_HIDDEN | US_DEAD | US_RESCUED))
                continue;

            if (!isEnemy(unit))
                continue;

            if (!AiReachesByBirdsEyeDistance(gActiveUnit, unit, item))
                continue;

            AiFillReversedAttackRangeMap(unit, item);

            tmpResult.targetId = unit->id;

            if (!AiSimulateBestBattleAgainstTarget(&tmpResult))
                continue;

            if (tmpResult.score >= finResult.score)
            {
                finResult = tmpResult;
                finResult.itemSlot = i;
            }
        })
    }

    if (UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_BALLISTA)
    {
        if (AiAttemptBallistaCombat(isEnemy, &tmpResult) == TRUE)
        {
            if (tmpResult.score >= finResult.score)
            {
                finResult = tmpResult;
            }
        }
    }

    if (finResult.score != 0 || finResult.targetId != 0)
    {
        AiSetDecision(finResult.xMove, finResult.yMove,
            AI_ACTION_COMBAT, finResult.targetId, finResult.itemSlot, 0, 0);
    }
}

void AiFillReversedAttackRangeMap(struct Unit* unit, u16 item)
{
    // reverse as in "this is the range this unit can be attacked *from*"

    MapFill(gMapRange, 0);
    MapIncInBoundedRange(unit->x, unit->y, GetItemMinRange(item), GetItemMaxRange(item));
}

void AiFloodMovementAndRange(struct Unit* unit, u16 move, u16 item)
{
    int ix, iy;

    SetWorkingMovTable(unit->job->movTerrainTable);

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

bool AiAttemptBallistaCombat(bool(*isEnemy)(struct Unit* unit), struct AiCombatSimulationSt* st)
{
    struct AiCombatSimulationSt tmpResult;

    int ix, iy;
    int i;

    u16 item;

    int ballistaCount = 0;
    u8 ballistaIids[] = { IID_BALLISTA, IID_LONGBALLISTA, IID_KILLERBALLISTA };

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

    st->targetId = 0;
    st->score = 0;

    for (i = 0; i < 3; ++i)
    {
        item = ballistaIids[i];
        st->itemSlot = -1;

        FOR_UNITS_ALL(unit,
        {
            if (unit->state & (US_HIDDEN | US_DEAD | US_RESCUED))
                continue;

            if (!isEnemy(unit))
                continue;

            if (!AiReachesByBirdsEyeDistance(gActiveUnit, unit, item))
                continue;

            AiFillReversedAttackRangeMap(unit, item);

            tmpResult.targetId = unit->id;

            if (!AiSimulateBestBallistaBattleAgainstTarget(&tmpResult, item))
                continue;

            if (tmpResult.score >= st->score)
            {
                st->xMove = tmpResult.xMove;
                st->yMove = tmpResult.yMove;
                st->targetId = tmpResult.targetId;
                st->score = tmpResult.score;
            }
        })
    }

    if (st->score != 0 || st->targetId != 0)
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

    struct Vec2 pos;

    u8 itemSlot = 0;
    u8 rank = UINT8_MAX;
    u8 target = 0;

    for (iy = gMapSize.y-1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x-1; ix >= 0; --ix)
        {
            struct Vec2 posTmp;
            struct Unit* unit;
            s8 slotTmp;
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
            itemSlot = slotTmp;
        }
    }

    if (rank != UINT8_MAX)
    {
        gActiveUnit->unk_46++;
        AiSetDecision(pos.x, pos.y, AI_ACTION_STEAL, target, itemSlot, 0, 0);

        return TRUE;
    }

    return FALSE;
}

bool AiSimulateBestBattleAgainstTarget(struct AiCombatSimulationSt* st)
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

            st->xMove = ix;
            st->yMove = iy;
            score = scoreTmp;
        }
    }

    if (score == 0)
        return FALSE;

    return AiSimulateBattleAgainstTargetAtPosition(st);
}

bool AiSimulateBestBallistaBattleAgainstTarget(struct AiCombatSimulationSt* st, u16 item)
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

            st->xMove = ix;
            st->yMove = iy;
            score = scoreTmp;
        }
    }

    if (score == 0)
        return FALSE;

    return AiSimulateBattleAgainstTargetAtPosition(st);
}

u32 AiGetCombatPositionScore(int x, int y, struct AiCombatSimulationSt* st)
{
    int score;

    score  = AiGetInRangeCombatPositionScoreComponent(x, y, GetUnit(st->targetId));
    score += AiGetTerrainCombatPositionScoreComponent(x, y);
    score += AiGetFriendZoneCombatPositionScoreComponent(x, y);
    score -= gMapMovementSigned[y][x];
    score -= gMapOther[y][x]/8;

    score += INT32_MAX;

    return score;
}

bool AiIsBadFight(struct AiCombatSimulationSt* st)
{
    u16 item = gActiveUnit->items[st->itemSlot];
    struct Unit* unit = GetUnit(st->targetId);

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

bool AiSimulateBattleAgainstTargetAtPosition(struct AiCombatSimulationSt* st)
{
    if (st->itemSlot != UINT16_MAX)
    {
        BattleGenerateSimulation(
            gActiveUnit, GetUnit(st->targetId),
            st->xMove, st->yMove, st->itemSlot);
    }
    else
    {
        BattleGenerateBallistaSimulation(
            gActiveUnit, GetUnit(st->targetId),
            st->xMove, st->yMove);
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

    if (gBattleUnitB.unit.hpCur == 0)
        return 50;

    score = gBattleUnitA.battleAttack - gBattleUnitB.battleDefense;
    score = gBattleUnitA.battleEffectiveHit * score;

    if (score < 0)
        score = 0;

    score = Div(score, 100);
    score = sCombatScoreCoefficients->coeffDamageDealt * score;

    if (score > 40)
        score = 40;

    return score;
}

int AiGetOpponentLowHpScoreComponent(void)
{
    int score;

    score = 20 - gBattleUnitB.unit.hpCur;
    score = sCombatScoreCoefficients->coeffLowHpOpponent * score;

    if (score < 0)
        score = 0;

    return score;
}

int AiGetFriendZoneCombatScoreComponent(void)
{
    struct RangeScore
    {
        /* 00 */ s8 x;
        /* 01 */ s8 y;
        /* 02 */ s8 score;
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

    struct RangeScore const* it;

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

    score = sCombatScoreCoefficients->coeffFriendZone * score;

    if (score > 10)
        score = 10;

    return score;
}

int AiGetTargetJobCombatScoreComponent(void)
{
    u8 rank = AiGetJobRank(gBattleUnitB.unit.job->id);

    int score;

    score = sCombatScoreCoefficients->jobRankBonuses[rank];
    score = sCombatScoreCoefficients->coeffJobRankBonus * score;

    if (score > 20)
        score = 20;

    return score;
}

int AiGetTurnCombatScoreComponent(void)
{
    return gPlaySt.turn * sCombatScoreCoefficients->coeffTurnNumber;
}

int AiGetDamageTakenScoreComponent(void)
{
    int score;

    if (gBattleUnitB.weapon == 0)
        return -10;

    score = gBattleUnitB.battleAttack - gBattleUnitA.battleDefense;
    score = gBattleUnitB.battleEffectiveHit * score;

    if (score < 0)
        score = 0;

    score = Div(score, 100);
    score = sCombatScoreCoefficients->coeffDamageTaken * score;

    if (score > 40)
        score = 40;

    return score;
}

int AiGetDangerScoreComponent(void)
{
    int score;

    score = gMapOther[gBattleUnitA.unit.y][gBattleUnitA.unit.x]/8;
    score = sCombatScoreCoefficients->coeffDanger * score;

    if (score > 20)
        score = 20;

    return score;
}

int AiGetLowHpScoreComponent(void)
{
    int score;

    score = 20 - gBattleUnitA.unit.hpCur;
    score = sCombatScoreCoefficients->coeffLowHpSelf * score;

    if (score < 0)
        score = 0;

    return score;
}

void AiComputeCombatScore(struct AiCombatSimulationSt* st)
{
    int score;
    int backup;

    sCombatScoreCoefficients = gAiCombatScoreCoefficientTable + gAiSt.combatWeightTableId;

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

int AiGetInRangeCombatPositionScoreComponent(int x, int y, struct Unit* unit)
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

    return gActiveUnit->job->avoTerrainTable[terrain]
         + gActiveUnit->job->defTerrainTable[terrain]
         + gActiveUnit->job->resTerrainTable[terrain];
}

int AiGetFriendZoneCombatPositionScoreComponent(int x, int y)
{
    static struct Vec2 CONST_DATA range3offsets[] =
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

    struct Vec2 const* it;

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
