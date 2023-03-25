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
    AI_UNIT_FLAG_SEEK_HEALING = (1 << 0),
    AI_UNIT_FLAG_1 = (1 << 1),
    AI_UNIT_FLAG_2 = (1 << 2),
    AI_UNIT_FLAG_3 = (1 << 3),

    AI_UNIT_FLAG_6 = (1 << 6),
};

enum
{
    // "ai3"

    // 0~2 healing ai theshold select
    AI_UNIT_CONFIG_HEALTHRESHOLD_SHIFT = 0,
    AI_UNIT_CONFIG_HEALTHRESHOLD_BITS = 3,
    AI_UNIT_CONFIG_HEALTHRESHOLD_MASK = ((1 << AI_UNIT_CONFIG_HEALTHRESHOLD_BITS) - 1) << AI_UNIT_CONFIG_HEALTHRESHOLD_SHIFT,

    // 3~7 combat target decide weight set select
    AI_UNIT_CONFIG_COMBATWEIGHT_SHIFT = 3,
    AI_UNIT_CONFIG_COMBATWEIGHT_BITS = 5,
    AI_UNIT_CONFIG_COMBATWEIGHT_MASK = ((1 << AI_UNIT_CONFIG_COMBATWEIGHT_BITS) - 1) << AI_UNIT_CONFIG_COMBATWEIGHT_SHIFT,

    // "ai4"

    // 8+

    // 13
    AI_UNIT_CONFIG_FLAG_UNK13 = 1 << 13,
};

enum
{
    AI_A_00 = 0x00,
    AI_A_01 = 0x01,
    AI_A_02 = 0x02,
    AI_A_03 = 0x03,
    AI_A_04 = 0x04,
    AI_A_05 = 0x05,
    AI_A_06 = 0x06,
    AI_A_07 = 0x07,
    AI_A_08 = 0x08,
    AI_A_09 = 0x09,
    AI_A_0A = 0x0A,
    AI_A_0B = 0x0B,
    AI_A_0C = 0x0C,
    AI_A_0D = 0x0D,
    AI_A_0E = 0x0E,
    AI_A_0F = 0x0F,
};

enum
{
    AI_B_00 = 0x00,
    AI_B_01 = 0x01,
    AI_B_02 = 0x02,
    AI_B_03 = 0x03,
    AI_B_04 = 0x04,
    AI_B_05 = 0x05,
    AI_B_06 = 0x06,
    AI_B_07 = 0x07,
    AI_B_08 = 0x08,
    AI_B_09 = 0x09,
    AI_B_0A = 0x0A,
    AI_B_0B = 0x0B,
    AI_B_0C = 0x0C,
    AI_B_0D = 0x0D,
    AI_B_0E = 0x0E,
    AI_B_0F = 0x0F,
    AI_B_10 = 0x10,
    AI_B_11 = 0x11,
    AI_B_12 = 0x12,
    AI_B_13 = 0x13,
    AI_B_14 = 0x14,
    AI_B_15 = 0x15,
    AI_B_16 = 0x16,
    AI_B_17 = 0x17,
    AI_B_18 = 0x18,
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
    /* 74 */ u8 * unit_it;
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
