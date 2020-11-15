

#pragma once

#include "common.h"

#include "ai.h"

enum
{
    AI_CMD_CONDITIONAL,
    AI_CMD_FUNC,
    AI_CMD_CHANGEAI,
    AI_CMD_GOTO,
    AI_CMD_ACTION_ON,
    AI_CMD_ACTION,

    AI_CMD_MOVETOENEMY = 18,
};

struct AiScr
{
    /* 00 */ u8 cmd;
    /* 01 */ u8 unk_01;
    /* 02 */ u8 unk_02;
    /* 03 */ u8 unk_03;
    /* 04 */ u32 unk_04;
    /* 08 */ u32 unk_08;
    /* 0C */ u32 unk_0C;
};

#define AI_ACTION(chance) { AI_CMD_ACTION, (chance), -1, 0, 0, 0, 0 }
#define AI_MOVE_TO_ENEMY  { AI_CMD_MOVETOENEMY, 0, -1, 0, 0, 0, 0 }
