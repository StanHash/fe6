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

    AI_UNIT_FLAG_6 = (1 << 6),
};

enum
{
    AI_A_00 = 0x00,
    AI_A_06 = 0x06,
};

enum
{
    AI_B_00 = 0x00,
    AI_B_01 = 0x01,
    AI_B_0C = 0x0C,
};

enum
{
    AI_COMPARE_GT,
    AI_COMPARE_GE,
    AI_COMPARE_EQ,
    AI_COMPARE_LE,
    AI_COMPARE_LT,
    AI_COMPARE_NE,
};

enum
{
    // Corresponds to entries in gAiJobRankLists

    AI_JOBRANK_ROY,
    AI_JOBRANK_SUPPORTERS,
    AI_JOBRANK_HEALERS,
    AI_JOBRANK_CIVILIANS,
    AI_JOBRANK_MAGES,
    AI_JOBRANK_FLYERS,
    AI_JOBRANK_ARMORS,
    AI_JOBRANK_CAVALIERS,
    AI_JOBRANK_ARCHERS,
};

struct AiSt
{
    /* 00 */ u8 units[116]; // TODO: constant for max number of units?
    /* 74 */ u8* unit_it;
    /* 78 */ u8 order_state;
    /* 79 */ u8 decide_state;
    /* 7A */ u8 danger_map_filled;
    /* 7B */ u8 flags;
    /* 7C */ u8 unk_7C;
    /* 7D */ u8 combat_wgt_table_id;
    /* 7E */ u8 unk_7E;
    /* 7F */ u8 unk_7F;
    /* 80 */ u32 special_item_flags;
    /* 84 */ u8 unk_84;
    /* 85 */ u8 best_blue_mov;
    /* 86 */ u8 cmd_result[8];
};

extern struct AiSt EWRAM_DATA gAiSt;
