#ifndef AI_SCRIPT_H
#define AI_SCRIPT_H

#include "prelude.h"

#include "ai.h"

enum
{
    AI_CMD_CONDITIONAL,
    AI_CMD_CALL_FUNC,
    AI_CMD_SET_AI,
    AI_CMD_GOTO,
    AI_CMD_ACTION_ON_PID,
    AI_CMD_ACTION,
    AI_CMD_NOP,
    AI_CMD_ACTION_IN_PLACE,
    AI_CMD_ACTION_ON_JID,
    AI_CMD_STAFF_ACTION,
    AI_CMD_STAFF_ACTION_2,
    AI_CMD_STAFF_ACTION_3,
    AI_CMD_MOVE_TOWARDS,
    AI_CMD_MOVE_TOWARDS_PID,
    AI_CMD_NOP_0E,
    AI_CMD_MOVE_TOWARDS_JID,
    AI_CMD_PILLAGE,
    AI_CMD_MOVE_TO_SAFETY,
    AI_CMD_MOVE_TO_ENEMY,
    AI_CMD_MOVE_TO_ENEMY_2,
    AI_CMD_NOP_14,
    AI_CMD_NOP_15,
    AI_CMD_MOVE_RANDOM,
    AI_CMD_ESCAPE,
    AI_CMD_NOP_18,
    AI_CMD_MOVE_TO_TERRAIN,
    AI_CMD_MOVE_TO_LISTED_TERRAIN,
    AI_CMD_LABEL,

    AI_CMD_COUNT,
};

struct AiScr
{
    /* 00 */ u8 cmd;
    /* 01 */ u8 unk_01;
    /* 02 */ u8 unk_02;
    /* 03 */ u8 unk_03;
    /* 04 */ u32 unk_04;
    /* 08 */ void const * unk_08;
    /* 0C */ void const * unk_0C;
};

typedef bool (* AiScrFunc)(void const * arg);

bool AiTryExecScriptA(void);
bool AiExecFallbackScriptA(void);
bool AiTryExecScriptB(void);
bool AiExecFallbackScriptB(void);

bool AiIsUnitEnemy(struct Unit * unit);
bool AiIsUnitNonActive(struct Unit * unit);
bool AiIsUnitEnemyAndNotInScrList(struct Unit * unit);
bool AiIsUnitEnemyOrInScrList(struct Unit * unit);
bool AiIsUnitEnemyAndScrPid(struct Unit * unit);
bool AiIsUnitEnemyAndScrJid(struct Unit * unit);

void AiDoBerserkAction(void);
void AiDoBerserkMove(void);

#define AI_CONDITIONAL(target, cond, left, right) { AI_CMD_CONDITIONAL, (cond), -1, (target), (right), (left), NULL }
#define AI_CALL_FUNC(func, argptr)       { AI_CMD_CALL_FUNC, 0, -1, 0, 0, (func), (argptr) }
#define AI_SET_AI(ai_a, ai_b)              { AI_CMD_SET_AI, (ai_a), (ai_b), 0, 0, NULL, NULL }
#define AI_GOTO(target)                  { AI_CMD_GOTO, 0, -1, (target), 0, NULL, NULL }
#define AI_ACTION_ON_PID(chance, pid)    { AI_CMD_ACTION_ON_PID, (chance), -1, 0, (pid), NULL, NULL }
#define AI_ACTION_IGNORING(chance, list) { AI_CMD_ACTION, (chance), -1, 0, 0, (list), NULL }
#define AI_NOP                           { AI_CMD_NOP, 0, -1, 0, 0, NULL, NULL }
#define AI_ACTION_IN_PLACE(chance)       { AI_CMD_ACTION_IN_PLACE, (chance), -1, 0, 0, NULL, NULL }
#define AI_BAD_LABEL(id) /* bugged! */   { AI_CMD_STAFF_ACTION_3, (id), 0, 0, 0, NULL, NULL }
#define AI_MOVE_TOWARDS(x, y)            { AI_CMD_MOVE_TOWARDS, (x), -1, (y), 0, NULL, NULL }
#define AI_MOVE_TOWARDS_PID(pid)         { AI_CMD_MOVE_TOWARDS_PID, 0, -1, 0, (pid), NULL, NULL }
#define AI_NOP_0E                        { AI_CMD_NOP_0E, 0, -1, 0, 0, NULL, NULL }
#define AI_PILLAGE                       { AI_CMD_PILLAGE, 0, -1, 0, 0, NULL, NULL }
#define AI_MOVE_TO_ENEMY_IGNORING(list)  { AI_CMD_MOVE_TO_ENEMY, 0, -1, 0, 0, (list), NULL }
#define AI_MOVE_RANDOM                   { AI_CMD_MOVE_RANDOM, 0, -1, 0, 0, NULL, NULL }
#define AI_ESCAPE                        { AI_CMD_ESCAPE, 0, -1, 0, 0, NULL, NULL }
#define AI_MOVE_TO_LISTED_TERRAIN(list)  { AI_CMD_MOVE_TO_LISTED_TERRAIN, 0, -1, 0, 0, (list), NULL }
#define AI_LABEL(id)                     { AI_CMD_LABEL, 0, -1, (id), 0, NULL, NULL }

#define AI_GOTO_IFGT(target, left, right) AI_CONDITIONAL(target, AI_COMPARE_GT, left, right)
#define AI_GOTO_IFGE(target, left, right) AI_CONDITIONAL(target, AI_COMPARE_GE, left, right)
#define AI_GOTO_IFEQ(target, left, right) AI_CONDITIONAL(target, AI_COMPARE_EQ, left, right)
#define AI_GOTO_IFLE(target, left, right) AI_CONDITIONAL(target, AI_COMPARE_LE, left, right)
#define AI_GOTO_IFLT(target, left, right) AI_CONDITIONAL(target, AI_COMPARE_LT, left, right)
#define AI_GOTO_IFNE(target, left, right) AI_CONDITIONAL(target, AI_COMPARE_NE, left, right)
#define AI_SET_AI_A(ai_a) AI_SET_AI(ai_a, -1)
#define AI_SET_AI_B(ai_b) AI_SET_AI(-1, ai_b)
#define AI_GOTO_START AI_GOTO(0)
#define AI_ACTION(chance) AI_ACTION_IGNORING(chance, NULL)
#define AI_MOVE_TO_ENEMY  AI_MOVE_TO_ENEMY_IGNORING(NULL)

#endif // AI_SCRIPT_H
