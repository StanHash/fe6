#pragma once

#include "common.h"

#include "proc.h"
#include "ai.h"

enum
{
    AI_ACTION_NONE, // move only
    AI_ACTION_COMBAT,
    AI_ACTION_ESCAPE,
    AI_ACTION_STEAL,
    AI_ACTION_PILLAGE,
    AI_ACTION_STAFF,
    AI_ACTION_USEITEM,
    AI_ACTION_REFRESH,
    AI_ACTION_TALK,
};

struct AiDecision
{
    /* 00 */ u8 action_id;

    /* 01 */ u8 unit_id;
    /* 02 */ u8 x_move;
    /* 03 */ u8 y_move;
    /* 04 */ u8 unk_04;
    /* 05 */ u8 unk_05;
    /* 06 */ u8 target_id;
    /* 07 */ u8 item_slot;
    /* 08 */ u8 x_target;
    /* 09 */ u8 y_target;

    /* 0A */ bool action_performed;
};

void AiClearDecision(void);
void AiSetDecision(short x_move, short y_move, u8 action_id, u8 target_id, u8 item_slot, u8 x_target, u8 y_target);
void AiUpdateDecision(u8 action_id, u8 target_id, u8 item_slot, u8 x_target, u8 y_target);

void AiDecideAll(void);
void AiDecideHealOrEscape(void);
void AiDecideSpecialItems(void);
void AiDecideScriptA(void);
void AiDecideScriptB(void);

extern struct AiDecision EWRAM_DATA gAiDecision;

extern Func AiDecideFunc;

extern struct ProcScr CONST_DATA ProcScr_AiDecide[];
