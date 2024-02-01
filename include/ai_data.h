#ifndef AI_DATA_H
#define AI_DATA_H

#include "prelude.h"

#include "ai.h"
#include "ai_script.h"

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

extern u8 CONST_DATA gAiPillageTerrainsNoLoot[];
extern u8 CONST_DATA gAiPillageTerrainsWithLoot[];
extern struct AiScr CONST_DATA AiScr_FallbackA[];
extern struct AiScr CONST_DATA AiScr_FallbackB[];
extern u8 const * CONST_DATA gAiJobRankLists[];
extern struct AiCombatScoreCoefficients const gAiCombatScoreCoefficientTable[];
extern struct AiEscapePt const * CONST_DATA gAiRedEscapePoints[];
extern struct AiEscapePt const * CONST_DATA gAiGreenEscapePoints[];
extern struct AiHealThreshold CONST_DATA gAiHealThresholds[];
extern u16 CONST_DATA gUnk_085C8834[];
extern u32 const AiItemConfigTable[];
extern struct AiScr const * const * CONST_DATA gAiScriptLutB[];
extern struct AiScr const * const * CONST_DATA gAiScriptLutA[];
extern struct Vec2i const * const * CONST_DATA gUnk_085C8878;

#endif // AI_DATA_H
