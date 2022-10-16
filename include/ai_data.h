#pragma once

#include "common.h"

#include "ai.h"

struct AiCombatScoreCoefficients
{
    /* 00 */ u8 coef_damage_dealt;
    /* 01 */ u8 coef_low_hp_opponent;
    /* 02 */ u8 coef_friend_zone;
    /* 03 */ u8 coef_job_rank_bonus;
    /* 04 */ u8 coef_turn_number;
    /* 05 */ u8 coef_damage_taken;
    /* 06 */ u8 coef_danger;
    /* 07 */ u8 coef_low_hp_self;
    /* 08 */ u8 job_rank_bonuses[9];
};

struct AiEscapePt
{
    /* 00 */ u8 x, y;
    /* 02 */ u8 facing;
};

struct AiHealThreshold
{
    u8 exit_threshold;
    u8 enter_threshold;
};

extern u8 CONST_DATA gUnk_085C864C[];
extern u8 CONST_DATA gUnk_085C864F[];
extern struct AiScr CONST_DATA AiScr_FallbackA[];
extern struct AiScr CONST_DATA AiScr_FallbackB[];
extern u8 const * CONST_DATA gAiJobRankLists[];
extern struct AiCombatScoreCoefficients const gAiCombatScoreCoefficientTable[];
extern struct AiEscapePt const * CONST_DATA gUnk_085C86B8[];
extern struct AiEscapePt const * CONST_DATA gUnk_085C876C[];
extern struct AiHealThreshold CONST_DATA gUnk_085C8820[];
extern u16 CONST_DATA gUnk_085C8834[];
extern u32 const AiItemConfigTable[];
extern struct AiScr const * const * CONST_DATA gAiScriptLutB[];
extern struct AiScr const * const * CONST_DATA gAiScriptLutA[];
