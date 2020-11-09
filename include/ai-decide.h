
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

void AiClearDecision(void);
void AiSetDecision(u8 xMove, u8 yMove, u8 actionId, u8 targetId, u8 itemSlot, u8 xTarget, u8 yTarget);
void AiUpdateDecision(u8 actionId, u8 targetId, u8 itemSlot, u8 xTarget, u8 yTarget);

void AiDecideAll(void);
void AiDecideHealOrEscape(void);
void AiDecideSpecialItems(void);
void AiDecideScriptA(void);
void AiDecideScriptB(void);

extern struct AiDecision EWRAM_DATA gAiDecision;

extern Func AiDecideFunc;

extern struct ProcScr CONST_DATA ProcScr_AiDecide[];
