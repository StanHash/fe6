
#pragma once

#include "common.h"

enum
{
    AI_FLAGS_NONE = 0,

    AI_FLAG_0 = (1 << 0),
    AI_FLAG_1 = (1 << 1),
    AI_FLAG_BERSERKED = (1 << 2),
};

enum
{
    AI_UNIT_FLAG_0 = (1 << 0),
    AI_UNIT_FLAG_1 = (1 << 1),
    AI_UNIT_FLAG_2 = (1 << 2),
    AI_UNIT_FLAG_3 = (1 << 3),
};

struct AiSt
{
    /* 00 */ u8 units[116]; // TODO: constant for max number of units?
    /* 74 */ u8* unitIt;
    /* 78 */ u8 orderState;
    /* 79 */ u8 decideState;
    /* 7A */ Bool dangerMapFilled;
    /* 7B */ u8 flags;
    /* 7C */ u8 unk_7C;
    /* 7D */ u8 combatWeightTableId;
    /* 7E */ u8 unk_7E;
    /* 7F */ u8 unk_7F;
    /* 80 */ u32 specialItemFlags;
    /* 84 */ u8 unk_84;
    /* 85 */ u8 bestBlueMov;
    /* 86 */ u8 unk_86[8];
};

extern struct AiSt EWRAM_DATA gAiSt;
