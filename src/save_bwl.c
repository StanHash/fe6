#include "save.h"

#include "gbasram.h"
#include "gbaio.h"
#include "util.h"
#include "eventinfo.h"
#include "supply.h"
#include "bm.h"
#include "hardware.h"
#include "faction.h"
#include "battle.h"
#include "chapter.h"
#include "unit.h"
#include "action.h"
#include "trap.h"
#include "savelayout.h"

#include "constants/chapters.h"

void ClearPidChStatsSaveData(void * sram_dst)
{
    int i;

    CpuFill16(0, gPidStatsData, sizeof(gPidStatsData));
    CpuFill16(0, gChapterStats, sizeof(gChapterStats));

    for (i = 0; i < BWL_ARRAY_SIZE; i++)
    {
        WriteAndVerifySramFast(
            gPidStatsData, sram_dst + GAMESAVE_OFFSET_PIDSTATS + i * sizeof(struct PidStats), sizeof(struct PidStats));
    }

    for (i = 0; i < WIN_ARRAY_SIZE; i++)
    {
        WriteAndVerifySramFast(
            gChapterStats, sram_dst + GAMESAVE_OFFSET_CHAPTERSTATS + i * sizeof(struct ChapterStats), sizeof(struct ChapterStats));
    }

    gPidStatsSaveLoc = sram_dst + GAMESAVE_OFFSET_PIDSTATS;
}

void ClearPidStats(void)
{
    CpuFill16(0, gPidStatsData, sizeof(gPidStatsData));
}

void ReadPidStats(void * sram_src)
{
    ReadSramFast(sram_src, (u8 *)gPidStatsData, sizeof(gPidStatsData));
    gPidStatsSaveLoc = sram_src;
}

void ReadChapterStats(void const * sram_src)
{
    ReadSramFast(sram_src, (u8 *)gChapterStats, sizeof(gChapterStats));
}

void WritePidStats(void * sram_dst)
{
    WriteAndVerifySramFast(
        (u8 *)gPidStatsData,
        sram_dst,
        sizeof(gPidStatsData)
    );

    gPidStatsSaveLoc = sram_dst;
}

void WriteChapterStats(void * sram_dst)
{
    WriteAndVerifySramFast(gChapterStats, sram_dst, sizeof(gChapterStats));
}

struct ChapterStats * GetChapterStats(int num)
{
    return gChapterStats + num;
}

bool IsWinDataValid(struct ChapterStats * chapter_stats)
{
    return chapter_stats->chapter_turn > 0;
}

int GetNextChapterStatsSlot(void)
{
    struct ChapterStats * cur = GetChapterStats(0);

    int result = 0;

    while (cur->chapter_turn != 0)
    {
        result++;
        cur++;
    }

    return result;
}

void RegisterChapterStats(struct PlaySt * play_st)
{
    struct ChapterStats * chapter_stats = GetChapterStats(GetNextChapterStatsSlot());

    int time_3s = (GetGameTime() - play_st->time_chapter_started) / (FRAMES_PER_SECOND * 3);

    // 50 hours = 50 * 60 * 20
    if (time_3s > 50 * 60 * 20)
        time_3s = 50 * 60 * 20;

    chapter_stats->chapter_id = play_st->chapter;
    chapter_stats->chapter_turn = play_st->turn;
    chapter_stats->chapter_time = time_3s;
}

inline struct PidStats * GetPidStats(fu8 pid)
{
    if (pid >= BWL_ARRAY_SIZE)
        return NULL;

    if (GetPInfo(pid)->affinity == 0)
        return NULL;

    return gPidStatsData + pid - 1;
}

void PidStatsAddBattleAmt(struct Unit * unit)
{
    struct PidStats * stats;

    if (UNIT_FACTION(unit) != FACTION_BLUE)
        return;

    stats = GetPidStats(UNIT_PID(unit));

    if (stats == NULL)
        return;

    if (stats->battle_count < 4000)
        stats->battle_count++;
}

void PidStatsAddWinAmt(fu8 pid)
{
    struct PidStats * stats = GetPidStats(pid);

    if (stats == NULL)
        return;

    if (stats->win_count < 1000)
        stats->win_count++;
}

void PidStatsRecordLoseData(fu8 pid)
{
    struct SaveBlockInfo chunk;
    int suspend_id;

    if (IsSramWorking())
    {
        struct PidStats * stats = GetPidStats(pid);

        if (stats == NULL)
            return;

        if (gBmSt.just_resumed == TRUE)
            return;

        if (gPlaySt.flags & PLAY_FLAG_TUTORIAL)
            return;

        if (gBmSt.flags & BM_FLAG_LINKARENA)
            return;

        if (gBmSt.flags & BM_FLAG_5)
            return;

        if (gPlaySt.flags & PLAY_FLAG_COMPLETE)
            return;

        if (stats->loss_count < 200)
        {
            stats->loss_count++;

            suspend_id = GetLastSuspendSaveId() + 3;

            WriteAndVerifySramFast(
                stats, GetSaveWriteAddr(suspend_id) + SUSPENDSAVE_OFFSET_PIDSTATS - sizeof(struct PidStats) + pid * sizeof(struct PidStats), 1);

            ReadSaveBlockInfo(&chunk, suspend_id);
            WriteSaveBlockInfo(&chunk, suspend_id);

            WriteAndVerifySramFast(
                stats, GetSaveWriteAddr(gPlaySt.save_id) + GAMESAVE_OFFSET_PIDSTATS - sizeof(struct PidStats) + pid * sizeof(struct PidStats), 1);

            ReadSaveBlockInfo(&chunk, gPlaySt.save_id);
            WriteSaveBlockInfo(&chunk, gPlaySt.save_id);
        }
    }
}

void PidStatsRecordDefeatInfo(fu8 pid, fu8 killer_pid, int defeat_cause)
{
    struct PidStats * stats = GetPidStats(pid);

    if (stats == NULL)
        return;

    stats->defeat_chapter = gPlaySt.chapter;
    stats->defeat_turn = gPlaySt.turn;
    stats->killer_pid = killer_pid;
    stats->defeat_cause = defeat_cause;
}

void PidStatsAddActAmt(fu8 pid)
{
    struct PidStats * stats = GetPidStats(pid);

    if (stats == NULL)
        return;

    if (stats->act_count < 200)
        stats->act_count++;
}

void PidStatsAddStatViewAmt(fu8 pid)
{
    struct PidStats * stats = GetPidStats(pid);

    if (stats == NULL)
        return;

    if (stats->stat_view_count < 200)
        stats->stat_view_count++;
}

void PidStatsAddDeployAmt(fu8 pid)
{
    struct PidStats * stats = GetPidStats(pid);

    if (stats == NULL)
        return;

    if (stats->deploy_count < 50)
        stats->deploy_count++;
}

void PidStatsAddSquaresMoved(fu8 pid, int amount)
{
    int move_count;

    struct PidStats * stats = GetPidStats(pid);

    if (stats == NULL)
        return;

    move_count = stats->move_count + amount;

    if (move_count > 1000)
        move_count = 1000;

    stats->move_count = move_count;
}

void PidStatsAddExpGained(fu8 pid, int amount)
{
    int exp;

    struct PidStats * stats = GetPidStats(pid);

    if (stats == NULL)
        return;

    exp = stats->exp_gained + amount;

    if (exp > 4000)
        exp = 4000;

    stats->exp_gained = exp;
}

int PidStatsGetTotalBattleAmt(void)
{
    int i, result = 0;

    for (i = 0; i < BWL_ARRAY_SIZE; i++)
        result += gPidStatsData[i].battle_count;

    return result;
}

int PidStatsGetTotalWinAmt(void)
{
    int i, result = 0;

    for (i = 0; i < BWL_ARRAY_SIZE; i++)
        result += gPidStatsData[i].win_count;

    return result;
}

int PidStatsGetTotalLossAmt()
{
    int i, result = 0;
    for (i = 0; i < BWL_ARRAY_SIZE; i++)
        result += gPidStatsData[i].loss_count;

    return result;
}

int PidStatsGetTotalLevel()
{
    int i, result = 0;
    for (i = 0; i < BWL_ARRAY_SIZE; i++)
        result += gPidStatsData[i].exp_gained / 100;

    return result;
}

void PidStatsRecordBattleRes(void)
{
    struct BattleUnit * buA = NULL, * buB = NULL;

    if (0 == GetUnitCurrentHp(&gBattleUnitA.unit))
    {
        buA = &gBattleUnitA;
        buB = &gBattleUnitB;
    }

    if (0 == GetUnitCurrentHp(&gBattleUnitB.unit))
    {
        buA = &gBattleUnitB;
        buB = &gBattleUnitA;
    }

    if (buA)
    {
        if (buB && FACTION_BLUE == UNIT_FACTION(&buB->unit))
            PidStatsAddWinAmt(UNIT_PID(&buB->unit));

        if (buA && FACTION_BLUE == UNIT_FACTION(&buA->unit))
            PidStatsRecordLoseData(UNIT_PID(&buA->unit));
    }
}

bool IsPlaythroughIdUnique(int index)
{
    struct GlobalSaveInfo info;
    struct PlaySt play_st;
    int i, result;

    ReadGlobalSaveInfo(&info);

    for (i = 0; i < MAX_SAVED_GAME_CLEARS; i++)
    {
        if (info.cleared_playthroughs[i] == index)
            return FALSE;
    }

    for (i = 0; i < 3; i++)
    {
        result = IsSaveValid(i);

        if (!result)
            continue;

        ReadGameSavePlaySt(i, &play_st);

        if (play_st.playthrough_id == index)
            return FALSE;
    }

    return TRUE;
}

int GetNewPlaythroughId(void)
{
    int i;

    for (i = 1; i < 0x100; i++)
    {
        if (IsPlaythroughIdUnique(i))
            return i;
    }
}

int GetGlobalCompletedPlaythroughCount(void)
{
    struct GlobalSaveInfo info;
    int i, result = 0;

    if (!ReadGlobalSaveInfo(&info))
        return 0;

    for (i = 0; i < MAX_SAVED_GAME_CLEARS; i++)
    {
        if (info.cleared_playthroughs[i] != 0)
            result++;
    }

    return result;
}

bool RegisterCompletedPlaythrough(struct GlobalSaveInfo * info, int index)
{
    int i;

    for (i = 0; i < MAX_SAVED_GAME_CLEARS; i++)
    {
        if (info->cleared_playthroughs[i] == index)
            return FALSE;
    }

    for(i = 0; i < MAX_SAVED_GAME_CLEARS; i++)
    {
        if (info->cleared_playthroughs[i] == 0)
        {
            info->cleared_playthroughs[i] = index;
            return TRUE;
        }
    }

    return FALSE;  
}

void SavePlayThroughData(void)
{
    struct GlobalSaveInfo info;
    int mode_math;

    if (!ReadGlobalSaveInfo(&info))
    {
        InitGlobalSaveInfo();
        ReadGlobalSaveInfo(&info);
    }

    RegisterCompletedPlaythrough(&info, gPlaySt.playthrough_id);

    info.completed = TRUE;

    mode_math = ((gPlaySt.flags & PLAY_FLAG_HARD) != 0) * 2;

    if (gPlaySt.chapter == CHAPTER_FINAL)
        mode_math++;

    switch (mode_math)
    {
        case 1:
            info.completed_true = TRUE;
            break;

        case 2:
            info.completed_hard = TRUE;
            break;

        case 3:
            info.completed_true_hard = TRUE;
            info.completed_hard = TRUE;
            info.completed_true = TRUE;
            break;

        default:
            break;
    }

    WriteGlobalSaveInfo(&info);

    gPlaySt.flags |= PLAY_FLAG_COMPLETE;
}

void func_fe6_08084F48() {}
