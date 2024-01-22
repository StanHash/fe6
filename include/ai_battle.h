#ifndef AI_BATTLE_H
#define AI_BATTLE_H

#include "prelude.h"

#include "ai.h"

struct AiCombatSimulationSt
{
    /* 00 */ u8 x_move, y_move;
    /* 02 */ u8 target_id;
    /* 04 */ u16 item_slot;
    /* 08 */ u32 score;
};

bool AiAttemptOffensiveAction(bool (* is_enemy)(struct Unit * unit));
bool AiAttemptCombatWithinMovement(bool (* is_enemy)(struct Unit * unit));
void AiFillReversedAttackRangeMap(struct Unit * unit, u16 item);
void AiFloodMovementAndRange(struct Unit * unit, u16 move, u16 item);
bool AiAttemptBallistaCombat(bool (* is_enemy)(struct Unit * unit), struct AiCombatSimulationSt * st);
bool AiAttemptStealActionWithinMovement(void);
bool AiSimulateBestBattleAgainstTarget(struct AiCombatSimulationSt * st);
bool AiSimulateBestBallistaBattleAgainstTarget(struct AiCombatSimulationSt * st, u16 item);
u32 AiGetCombatPositionScore(int x, int y, struct AiCombatSimulationSt * st);
bool AiIsBadFight(struct AiCombatSimulationSt * st);
bool AiSimulateBattleAgainstTargetAtPosition(struct AiCombatSimulationSt * st);
void AiComputeCombatScore(struct AiCombatSimulationSt * st);
int AiGetInRangeCombatPositionScoreComponent(int x, int y, struct Unit * unit);
int AiGetTerrainCombatPositionScoreComponent(int x, int y);
int AiGetFriendZoneCombatPositionScoreComponent(int x, int y);

#endif // AI_BATTLE_H
