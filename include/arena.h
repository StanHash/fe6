#pragma once

#include "common.h"

#include "unit.h"

enum
{
    ARENA_RESULT_0,
    ARENA_RESULT_1, // player victory?
    ARENA_RESULT_2, // enemy victory?
    ARENA_RESULT_3, // ???
    ARENA_RESULT_4, // backed out?
};

struct ArenaSt
{
    /* 00 */ struct Unit* player;
    /* 04 */ struct Unit* opponent;
    /* 08 */ short matchup_gold_value;
    /* 0A */ u8 result;
    /* 0B */ u8 unk_0B;
    /* 0C */ u8 range;
    /* 0D */ u8 player_weapon_kind;
    /* 0E */ u8 opponent_weapon_kind;
    /* 0F */ u8 player_jid;
    /* 10 */ u8 opponent_jid;
    /* 11 */ u8 player_level;
    /* 12 */ u8 opponent_level;
    /* 13 */ i8 player_is_magic;
    /* 14 */ i8 opponent_is_magic;
    /* 16 */ u16 player_power_ranking;
    /* 18 */ u16 opponent_power_ranking;
    /* 1A */ u16 player_weapon;
    /* 1C */ u16 opponent_weapon;
};

void ArenaBegin(struct Unit* unit);
void ArenaResume(struct Unit* unit);
int ArenaGetMatchupGoldValue(void);
int ArenaGetResult(void);
void ArenaSetResult(int result);
void ArenaContinueBattle(void);
bool ArenaIsUnitAllowed(struct Unit* unit);

extern struct ArenaSt gArenaSt;
