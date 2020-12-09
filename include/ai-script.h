

#pragma once

#include "common.h"

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
    /* 08 */ void* unk_08;
    /* 0C */ void* unk_0C;
};

typedef Bool(*AiScrFunc)(void* arg);

Bool AiTryExecScriptA(void);
Bool AiExecFallbackScriptA(void);
Bool AiTryExecScriptB(void);
Bool AiExecFallbackScriptB(void);

Bool AiIsUnitEnemy(struct Unit* unit);
Bool AiIsUnitNonActive(struct Unit* unit);
Bool AiIsUnitEnemyAndNotInScrList(struct Unit* unit);
Bool AiIsUnitEnemyOrInScrList(struct Unit* unit);
Bool AiIsUnitEnemyAndScrPid(struct Unit* unit);
Bool AiIsUnitEnemyAndScrJid(struct Unit* unit);

void AiDoBerserkAction(void);
void AiDoBerserkMove(void);

extern struct AiScr const* const* gAiScriptLutA[];
extern struct AiScr const* const* gAiScriptLutB[];

#define AI_ACTION(chance) { AI_CMD_ACTION, (chance), -1, 0, 0, NULL, NULL }
#define AI_MOVE_TO_ENEMY  { AI_CMD_MOVE_TO_ENEMY, 0, -1, 0, 0, NULL, NULL }
