
#pragma once

#include "common.h"

#include "proc.h"
#include "ai.h"

enum
{
    AI_ACTION_NONE = 0, // move only
};

struct AiDecision
{
    /* 00 */ u8 actionId;

    /* 01 */ u8 unitId;
    /* 02 */ u8 xMove;
    /* 03 */ u8 yMove;
    /* 04 */ u8 unk04;
    /* 05 */ u8 unk05;
    /* 06 */ u8 targetId;
    /* 07 */ u8 itemSlot;
    /* 08 */ u8 xTarget;
    /* 09 */ u8 yTarget;

    /* 0A */ Bool actionPerformed;
};

extern struct AiDecision EWRAM_DATA gAiDecision;

extern Func AiDecideFunc;

extern struct ProcScr CONST_DATA ProcScr_AiDecide[];
