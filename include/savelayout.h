#pragma once

#include "common.h"
#include "save.h"

#include "save_core.h"
#include "save_stats.h"
#include "save_game.h"
#include "save_multiarena.h"
#include "save_xmap.h"

#include "gbasram.h"

struct SramMain
{
    struct GlobalSaveInfo head;
    struct SaveBlockInfo block_info[SAVE_COUNT];
    struct SuspendSaveBlock suspend;
    struct SuspendSaveBlock suspend_alt;
    struct GameSaveBlock game_0;
    struct GameSaveBlock game_1;
    struct GameSaveBlock game_2;
    struct MultiArenaSaveBlock multi_arena;
};

STATIC_ASSERT(CART_SRAM_SIZE - SRAM_XMAP_SIZE >= sizeof(struct SramMain));
