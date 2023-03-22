#pragma once

#include "common.h"
#include "save.h"

#include "unit.h"
#include "bm.h"

enum
{
    DEFEAT_CAUSE_0,
    DEFEAT_CAUSE_1,
    DEFEAT_CAUSE_COMBAT,
    DEFEAT_CAUSE_TRAP,
    DEFEAT_CAUSE_POISON,
    DEFEAT_CAUSE_5,
    DEFEAT_CAUSE_6, // I think this is arena death but needs confirm
};

struct PidStats
{
    u32 loss_count      : 8;
    u32 act_count       : 8;
    u32 stat_view_count : 8;
    u32 defeat_chapter  : 6;
    u32 defeat_turn     : 10;
    u32 deploy_count    : 6;
    u32 move_count      : 10;
    u32 defeat_cause    : 4;
    u32 exp_gained      : 12;
    u32 win_count       : 10;
    u32 battle_count    : 12;
    u32 killer_pid      : 9;
    u32 : 0; // unused/padding (15 bits)
};

struct ChapterStats
{
    u16 chapter_id   : 6;
    u16 chapter_turn : 10;
    u16 chapter_time : 16; // in increments of 3 seconds
};

#define PID_STATS_COUNT 70
#define CHAPTER_STATS_COUNT 32

void WriteGameSaveFreshStats(struct GameSaveBlock * gamesave_sram);
void ClearPidStats(void);
void ReadPidStats(void const * sram_src);
void ReadChapterStats(void const * sram_src);
void WritePidStats(void * sram_dst);
void WriteChapterStats(void * sram_dst);
struct ChapterStats * GetChapterStats(int num);
bool IsValidChapterStats(struct ChapterStats * chapter_stats);
int GetNextChapterStatsSlot(void);
void RegisterChapterStats(struct PlaySt * play_st);
struct PidStats * GetPidStats(fu8 pid);
void PidStatsAddBattle(struct Unit * unit);
void PidStatsAddWin(fu8 pid);
void PidStatsAddLoss(fu8 pid);
void PidStatsSetDefeatInfo(fu8 pid, fu8 killer_pid, int defeat_cause);
void PidStatsAddAct(fu8 pid);
void PidStatsAddStatView(fu8 pid);
void PidStatsAddDeploy(fu8 pid);
void PidStatsAddMove(fu8 pid, int amount);
void PidStatsAddExpGained(fu8 pid, int amount);
int PidStatsCountTotalBattles(void);
int PidStatsCountTotalWins(void);
int PidStatsCountTotalLosses(void);
int PidStatsCountTotalLevelsGained(void);
void PidStatsUpdateFromBattleOutcome(void);
bool IsPlaythroughIdUnique(int playthrough_id);
int GetNewPlaythroughId(void);
int GetGlobalCompletedPlaythroughCount(void);
bool RegisterCompletedPlaythrough(struct GlobalSaveInfo * info, int index);
void WriteCompletedPlaythroughSaveData(void);
void func_fe6_08084F48(void);
