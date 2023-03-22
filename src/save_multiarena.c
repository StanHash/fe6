#include "save_multiarena.h"

#include "save_core.h"
#include "save_game.h"

#include "gbasram.h"

struct MultiArenaSaveTeam EWRAM_DATA gMultiArenaSaveTeamBufA = { 0 };
struct MultiArenaSaveTeam EWRAM_DATA gMultiArenaSaveTeamBufB = { 0 };

struct MultiArenaRankingEnt const gInitialMultiArenaRankings[MULTIARENA_MAX_RANKINGS] =
{
    {
        .ranking = 0,
        .player_count = 1,
        .mode = 0,
        .points = 100,
        .name = JTEXT("ロード"),
    },
    {
        .ranking = 0,
        .player_count = 1,
        .mode = 1,
        .points = 90,
        .name = JTEXT("スナイパー"),
    },
    {
        .ranking = 0,
        .player_count = 1,
        .mode = 0,
        .points = 80,
        .name = JTEXT("シャーマン"),
    },
    {
        .ranking = 0,
        .player_count = 2,
        .mode = 1,
        .points = 70,
        .name = JTEXT("\x83\x5Cシアルナイト"), // NOTE: \x83\x5C = ソ. \x5C happens to be ascii for '\' which breaks agbcc
    },
    {
        .ranking = 0,
        .player_count = 2,
        .mode = 0,
        .points = 60,
        .name = JTEXT("\x83\x5Cードマスター"), // NOTE: \x83\x5C = ソ. \x5C happens to be ascii for '\' which breaks agbcc
    },
    {
        .ranking = 1,
        .player_count = 2,
        .mode = 1,
        .points = 50,
        .name = JTEXT("ウォーリア"),
    },
    {
        .ranking = 1,
        .player_count = 3,
        .mode = 0,
        .points = 40,
        .name = JTEXT("アーマーナイト"),
    },
    {
        .ranking = 1,
        .player_count = 3,
        .mode = 1,
        .points = 30,
        .name = JTEXT("ジェネラル"),
    },
    {
        .ranking = 1,
        .player_count = 3,
        .mode = 0,
        .points = 20,
        .name = JTEXT("アーチャー"),
    },
    {
        .ranking = 1,
        .player_count = 3,
        .mode = 1,
        .points = 10,
        .name = JTEXT("パラディン"),
    },
};

bool IsMultiArenaSaveValid(int save_id)
{
    return ReadSaveBlockInfo(NULL, save_id);
}

void WriteNewMultiArenaSave(void)
{
    struct SaveBlockInfo block_info;
    struct GameSavePackedUnit save_unit;
    char team_name[MULTIARENA_TEAMNAME_SIZE + 2];
    struct MultiArenaRankingEnt ranking_ent;
    u16 config;

    int i, j;

    struct MultiArenaSaveBlock * dst = GetSaveWriteAddr(SAVE_MULTIARENA);

    CpuFill16(0, &save_unit, sizeof(save_unit));

#if BUGFIX
    CpuFill16(0, team_name, sizeof(team_name));
#else
    // because MULTIARENA_TEAMNAME_SIZE + 1 is odd, this will not clear the last byte
    CpuFill16(0, team_name, MULTIARENA_TEAMNAME_SIZE + 1);
#endif

    for (i = 0; i < MULTIARENA_MAX_TEAMS; i++)
    {
        for (j = 0; j < MULTIARENA_UNITS_PER_TEAM; j++)
            WriteAndVerifySramFast(&save_unit, &dst->teams[i].units[j], sizeof(save_unit));

        WriteAndVerifySramFast(team_name, dst->teams[i].name, sizeof(dst->teams[i].name));
    }

    config = MULTIARENA_CONFIG_SHOWUNITS | MULTIARENA_CONFIG_SURVIVALMODE | MULTIARENA_CONFIG_AUTOEQUIPOFF;
    WriteAndVerifySramFast(&config, &dst->config, sizeof(config));

    for (i = 0; i < MULTIARENA_MAX_RANKINGS; i++)
    {
        ranking_ent.ranking = gInitialMultiArenaRankings[i].ranking;
        ranking_ent.player_count = gInitialMultiArenaRankings[i].player_count;
        ranking_ent.mode = gInitialMultiArenaRankings[i].mode;
        ranking_ent.points = gInitialMultiArenaRankings[i].points;
        func_fe6_080368DC(gInitialMultiArenaRankings[i].name, ranking_ent.name);

        WriteAndVerifySramFast(&ranking_ent, &dst->rankings[i], sizeof(ranking_ent));
    }

    block_info.magic32 = SAVE_MAGIC32_MULTIARENA;
    block_info.kind = SAVE_KIND_MULTIARENA;
    WriteSaveBlockInfo(&block_info, SAVE_MULTIARENA);
}

bool ReadMultiArenaSaveTeamRaw(int team, struct MultiArenaSaveTeam * dst)
{
    struct MultiArenaSaveBlock const * src_sram = GetSaveReadAddr(SAVE_MULTIARENA);

    ReadSramFast(&src_sram->teams[team], dst, sizeof(struct MultiArenaSaveTeam));

    if (dst->name[0] == 0)
        return FALSE;

    return TRUE;
}

bool ReadMultiArenaSaveTeamName(int team, char * dst)
{
    struct MultiArenaSaveBlock const * src_sram = GetSaveReadAddr(SAVE_MULTIARENA);

    ReadSramFast(&src_sram->teams[team], &gMultiArenaSaveTeamBufA, sizeof(struct MultiArenaSaveTeam));

    if (gMultiArenaSaveTeamBufA.name[0] == 0)
        return FALSE;

    func_fe6_080368DC(gMultiArenaSaveTeamBufA.name, dst);

    return TRUE;
}

void WipeMultiArenaSaveTeam(int team)
{
    struct SaveBlockInfo block_info;

    struct MultiArenaSaveBlock * dst_sram = GetSaveWriteAddr(SAVE_MULTIARENA);

    CpuFill16(0, &gMultiArenaSaveTeamBufA, sizeof(struct MultiArenaSaveTeam));
    WriteAndVerifySramFast(&gMultiArenaSaveTeamBufA, &dst_sram->teams[team], sizeof(struct MultiArenaSaveTeam));

    block_info.magic32 = SAVE_MAGIC32_MULTIARENA;
    block_info.kind = SAVE_KIND_MULTIARENA;
    WriteSaveBlockInfo(&block_info, SAVE_MULTIARENA);
}

void CopyMultiArenaSaveTeam(int team_src, int team_dst)
{
    struct SaveBlockInfo block_info;

    struct MultiArenaSaveBlock const * src_sram = GetSaveReadAddr(SAVE_MULTIARENA);
    struct MultiArenaSaveBlock * dst_sram = GetSaveWriteAddr(SAVE_MULTIARENA);

    ReadSramFast(&src_sram->teams[team_src], &gMultiArenaSaveTeamBufA, sizeof(struct MultiArenaSaveTeam));
    WriteAndVerifySramFast(&gMultiArenaSaveTeamBufA, &dst_sram->teams[team_dst], sizeof(struct MultiArenaSaveTeam));

    block_info.magic32 = SAVE_MAGIC32_MULTIARENA;
    block_info.kind = SAVE_KIND_MULTIARENA;
    WriteSaveBlockInfo(&block_info, SAVE_MULTIARENA);
}

void SwapMultiArenaSaveTeams(int team_a, int team_b)
{
    struct SaveBlockInfo block_info;

    struct MultiArenaSaveBlock const * src_sram = GetSaveReadAddr(SAVE_MULTIARENA);
    struct MultiArenaSaveBlock * dst_sram = GetSaveWriteAddr(SAVE_MULTIARENA);

    ReadSramFast(&src_sram->teams[team_a], &gMultiArenaSaveTeamBufA, sizeof(struct MultiArenaSaveTeam));
    ReadSramFast(&src_sram->teams[team_b], &gMultiArenaSaveTeamBufB, sizeof(struct MultiArenaSaveTeam));

    WriteAndVerifySramFast(&gMultiArenaSaveTeamBufA, &dst_sram->teams[team_b], sizeof(struct MultiArenaSaveTeam));
    WriteAndVerifySramFast(&gMultiArenaSaveTeamBufB, &dst_sram->teams[team_a], sizeof(struct MultiArenaSaveTeam));

    block_info.magic32 = SAVE_MAGIC32_MULTIARENA;
    block_info.kind = SAVE_KIND_MULTIARENA;
    WriteSaveBlockInfo(&block_info, SAVE_MULTIARENA);
}

void WriteMultiArenaSaveTeam(int team, struct Unit * units_src, char const * name_src)
{
    struct SaveBlockInfo block_info;
    int i;

    struct MultiArenaSaveBlock * dst_sram = GetSaveWriteAddr(SAVE_MULTIARENA);

    WriteAndVerifySramFast(name_src, dst_sram->teams[team].name, sizeof(dst_sram->teams[team].name));

    for (i = 0; i < MULTIARENA_UNITS_PER_TEAM; i++)
        WriteGameSavePackedUnit(&units_src[i], &dst_sram->teams[team].units[i]);

    block_info.magic32 = SAVE_MAGIC32_MULTIARENA;
    block_info.kind = SAVE_KIND_MULTIARENA;
    WriteSaveBlockInfo(&block_info, SAVE_MULTIARENA);
}

bool ReadMultiArenaSaveTeam(int team, struct Unit * units_dst, char * name_dst)
{
    int i;

    struct MultiArenaSaveBlock const * src_sram = GetSaveReadAddr(SAVE_MULTIARENA);

    ReadSramFast(src_sram->teams[team].name, name_dst, sizeof(src_sram->teams[team].name));

    for (i = 0; i < MULTIARENA_UNITS_PER_TEAM; i++)
        ReadGameSavePackedUnit(&src_sram->teams[team].units[i], &units_dst[i]);

    // I've been told that reading from sram directly is bad and that one shouldn't do it

#if BUGFIX
    if (name_dst[0] == 0)
        return FALSE;
#else
    if (src_sram->teams[team].name[0] == 0)
        return FALSE;
#endif

    return TRUE;
}

void WriteMultiArenaSaveRankings(struct MultiArenaRankingEnt const * src)
{
    struct SaveBlockInfo block_info;

    struct MultiArenaSaveBlock * dst_sram = GetSaveWriteAddr(SAVE_MULTIARENA);

    WriteAndVerifySramFast(src, dst_sram->rankings, sizeof(dst_sram->rankings));

    block_info.magic32 = SAVE_MAGIC32_MULTIARENA;
    block_info.kind = SAVE_KIND_MULTIARENA;
    WriteSaveBlockInfo(&block_info, SAVE_MULTIARENA);
}

void ReadMultiArenaSaveRankings(struct MultiArenaRankingEnt * dst)
{
    struct MultiArenaSaveBlock * src_sram = GetSaveReadAddr(SAVE_MULTIARENA);
    ReadSramFast(src_sram->rankings, dst, sizeof(src_sram->rankings));
}

void WriteMultiArenaSaveConfig(u16 const * config_src)
{
    struct SaveBlockInfo block_info;

    struct MultiArenaSaveBlock * dst_sram = GetSaveWriteAddr(SAVE_MULTIARENA);

    WriteAndVerifySramFast(config_src, &dst_sram->config, sizeof(u16));

    block_info.magic32 = SAVE_MAGIC32_MULTIARENA;
    block_info.kind = SAVE_KIND_MULTIARENA;
    WriteSaveBlockInfo(&block_info, SAVE_MULTIARENA);
}

void ReadMultiArenaSaveConfig(u16 * config_dst)
{
    struct MultiArenaSaveBlock * src_sram = GetSaveReadAddr(SAVE_MULTIARENA);
    ReadSramFast(&src_sram->config, config_dst, sizeof(u16));
}

bool IsMultiArenaSaveReady(void)
{
    char buf[MULTIARENA_TEAMNAME_SIZE + 1];
    int i;

    if (!IsMultiArenaSaveValid(SAVE_MULTIARENA))
        return FALSE;

    for (i = 0; i < MULTIARENA_MAX_TEAMS; i++)
    {
        if (ReadMultiArenaSaveTeamName(i, buf) == TRUE)
            return TRUE;
    }

    return FALSE;
}
