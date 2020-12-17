
#pragma once

#include "common.h"

#include "ai.h"

struct AiCombatSimulationSt
{
    /* 00 */ u8 xMove, yMove;
    /* 02 */ u8 targetId;
    /* 04 */ u16 itemSlot;
    /* 08 */ u32 score;
};

Bool AiAttemptOffensiveAction(Bool(*isEnemy)(struct Unit* unit));
Bool AiAttemptCombatWithinMovement(Bool(*isEnemy)(struct Unit* unit));
void AiFillReversedAttackRangeMap(struct Unit* unit, u16 item);
void AiFloodMovementAndRange(struct Unit* unit, u16 move, u16 item);
Bool AiAttemptBallistaCombat(Bool(*isEnemy)(struct Unit* unit), struct AiCombatSimulationSt* st);
Bool AiAttemptStealActionWithinMovement(void);
Bool AiSimulateBestBattleAgainstTarget(struct AiCombatSimulationSt* st);
Bool AiSimulateBestBallistaBattleAgainstTarget(struct AiCombatSimulationSt* st, u16 item);
u32 AiGetCombatPositionScore(int x, int y, struct AiCombatSimulationSt* st);
Bool AiIsBadFight(struct AiCombatSimulationSt* st);
Bool AiSimulateBattleAgainstTargetAtPosition(struct AiCombatSimulationSt* st);
void AiComputeCombatScore(struct AiCombatSimulationSt* st);
int AiGetInRangeCombatPositionScoreComponent(int x, int y, struct Unit* unit);
int AiGetTerrainCombatPositionScoreComponent(int x, int y);
int AiGetFriendZoneCombatPositionScoreComponent(int x, int y);
