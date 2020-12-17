
#pragma once

#include "common.h"

#include "ai.h"

struct AiCombatScoreCoefficients
{
    /* 00 */ u8 coeffDamageDealt;
    /* 01 */ u8 coeffLowHpOpponent;
    /* 02 */ u8 coeffFriendZone;
    /* 03 */ u8 coeffJobRankBonus;
    /* 04 */ u8 coeffTurnNumber;
    /* 05 */ u8 coeffDamageTaken;
    /* 06 */ u8 coeffDanger;
    /* 07 */ u8 coeffLowHpSelf;
    /* 08 */ u8 jobRankBonuses[9];
};

struct AiEscapePt
{
    /* 00 */ u8 x, y;
    /* 02 */ u8 facing;
};

struct AiHealThreshold
{
    u8 exitThreshold;
    u8 enterThreshold;
};

extern u8 CONST_DATA gUnk_085C864C[];
extern u8 CONST_DATA gUnk_085C864F[];
extern struct AiScr CONST_DATA AiScr_FallbackA[];
extern struct AiScr CONST_DATA AiScr_FallbackB[];
extern u8 const* CONST_DATA gAiJobRankLists[];
extern struct AiCombatScoreCoefficients const gAiCombatScoreCoefficientTable[];
extern struct AiEscapePt const* CONST_DATA gUnk_085C86B8[];
extern struct AiEscapePt const* CONST_DATA gUnk_085C876C[];
extern struct AiHealThreshold CONST_DATA gUnk_085C8820[];
extern u16 CONST_DATA gUnk_085C8834[];
extern u32 const AiItemConfigTable[];
extern struct AiScr const* const* CONST_DATA gAiScriptLutB[];
extern struct AiScr const* const* CONST_DATA gAiScriptLutA[];
