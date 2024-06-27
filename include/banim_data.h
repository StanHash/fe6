#pragma once

#include "prelude.h"

struct BattleAnim {
    char abbr[12];
    int * modes;
    char * script;
    char * oam_r;
    char * oam_l;
    char * pal;
};

extern struct BattleAnim banim_data[];

struct BattleAnimCharaPal {
    char abbr[12];
    char * pal;
};

struct BattleAnimTerrain {
    char abbr[12];
    char * tileset;
    short * palette;
    int null_1; // useless, always 00
};

struct BanimModeData {
    const u32 * unk0;
    const u32 * img;
    u32 unk2;
};
