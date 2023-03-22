#pragma once

#include "common.h"
#include "save.h"

#include "save_game.h"

enum
{
    MULTIARENA_CONFIG_SHOWUNITS    = 1 << 0,
    MULTIARENA_CONFIG_SURVIVALMODE = 1 << 1,
    MULTIARENA_CONFIG_AUTOEQUIPOFF = 1 << 2,
    MULTIARENA_CONFIG_3            = 1 << 3,
};

// 7 sjis characters
#define MULTIARENA_TEAMNAME_SIZE 14

#define MULTIARENA_UNITS_PER_TEAM 5
#define MULTIARENA_MAX_TEAMS 10
#define MULTIARENA_MAX_RANKINGS 10

struct MultiArenaRankingEnt
{
    /* 00 */ u32 ranking : 2;
    /*    */ u32 player_count : 2;
    /*    */ u32 mode : 1;
    /*    */ u32 points : 27;
    /* 04 */ char name[MULTIARENA_TEAMNAME_SIZE + 1];
};

struct MultiArenaSaveTeam
{
    /* 00 */ char name[MULTIARENA_TEAMNAME_SIZE + 1];
    /* 10 */ struct GameSavePackedUnit units[MULTIARENA_UNITS_PER_TEAM];
};

struct MultiArenaSaveBlock
{
    /* 000 */ struct MultiArenaSaveTeam teams[MULTIARENA_MAX_TEAMS];
    /* 870 */ u16 config;
    /* 874 */ struct MultiArenaRankingEnt rankings[MULTIARENA_MAX_RANKINGS];
};

bool IsMultiArenaSaveValid(int save_id);
void WriteNewMultiArenaSave(void);
bool ReadMultiArenaSaveTeamRaw(int team, struct MultiArenaSaveTeam * dst);
bool ReadMultiArenaSaveTeamName(int team, char * dst);
void WipeMultiArenaSaveTeam(int team);
void CopyMultiArenaSaveTeam(int team_src, int team_dst);
void SwapMultiArenaSaveTeams(int team_a, int team_b);
void WriteMultiArenaSaveTeam(int team, struct Unit * units_src, char const * name_src);
bool ReadMultiArenaSaveTeam(int team, struct Unit * units_dst, char * name_dst);
void WriteMultiArenaSaveRankings(struct MultiArenaRankingEnt const * src);
void ReadMultiArenaSaveRankings(struct MultiArenaRankingEnt * dst);
void WriteMultiArenaSaveConfig(u16 const * config_src);
void ReadMultiArenaSaveConfig(u16 * config_dst);
bool IsMultiArenaSaveReady(void);
