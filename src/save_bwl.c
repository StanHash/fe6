#include "save.h"

#include "sram.h"
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

inline struct PidStats * GetPidStats(u8 pid)
{
    if (pid >= BWL_ARRAY_SIZE)
        return NULL;
    else if (0 == GetPInfo(pid)->affinity)
        return NULL;
    else
        return &gPidStats[pid];
}

void PidStatsAddBattleAmt(struct Unit * unit)
{
    struct PidStats * bwl;
    
    if (FACTION_BLUE != UNIT_FACTION(unit))
        return;
    
    bwl = GetPidStats(UNIT_PID(unit));
    if (!bwl)
        return;
    
    if (bwl->battleAmt < 4000)
        bwl->battleAmt++;
}

void PidStatsAddWinAmt(u8 pid)
{
    struct PidStats * bwl = GetPidStats(pid);
    if (!bwl)
        return;
    
    if (bwl->winAmt < 1000)
        bwl->winAmt++;
}

void PidStatsRecordLoseData(u8 pid)
{
    int index;
    struct SaveBlockInfo chunk;
    struct PidStats * bwl;

    if (IsSramWorking())
    {
        bwl = GetPidStats(pid);
        if (!bwl)
            return;

        if (1 == gBmSt.unk_3C)
            return;

        if (PLAY_FLAG_3 & gPlaySt.flags)
            return;

        if (BM_FLAG_LINKARENA & gBmSt.flags)
            return;

        if (BM_FLAG_5 & gBmSt.flags)
            return;

        if (PLAY_FLAG_COMPLETE & gPlaySt.flags)
            return;

        if (bwl->lossAmt < 200)
        {
            bwl->lossAmt++;

            index = GetLastSuspendSaveId() + 3;
            WriteAndVerifySramFast((u8 *)bwl, GetSaveTargetAddress(index) + 0x18B0 + pid * sizeof(struct PidStats), 1);

            LoadAndVerifySaveBlockInfo(&chunk, index);
            WriteSaveBlockInfo(&chunk, index);

            WriteAndVerifySramFast((u8 *)bwl, GetSaveTargetAddress(gPlaySt.save_slot) + 0x8F8 + pid * sizeof(struct PidStats), 1);

            LoadAndVerifySaveBlockInfo(&chunk, gPlaySt.save_slot);
            WriteSaveBlockInfo(&chunk, gPlaySt.save_slot);
        }
    }
}

void PidStatsRecordDeathData(u8 pid, u8 killerPid, int deathCause)
{
    struct PidStats * bwl = GetPidStats(pid);
    if (NULL ==bwl)
        return;

    bwl->deathCh = gPlaySt.chapter;
    bwl->deathTurn = gPlaySt.turn;
    bwl->killerPid = killerPid;
    bwl->deathCause = deathCause;
}

void PidStatsAddActAmt(u8 pid)
{
    struct PidStats * bwl = GetPidStats(pid);
    if (NULL ==bwl)
        return;

    if (bwl->actAmt < 200)
        bwl->actAmt++;
}

void PidStatsAddStatViewAmt(u8 pid)
{
    struct PidStats * bwl = GetPidStats(pid);
    if (NULL ==bwl)
        return;

    if (bwl->statViewAmt < 200)
        bwl->statViewAmt++;
}

void PidStatsAddDeployAmt(u8 pid)
{
    struct PidStats * bwl = GetPidStats(pid);
    if (NULL ==bwl)
        return;

    if (bwl->deployAmt < 50)
        bwl->deployAmt++;
}

void PidStatsAddSquaresMoved(u8 pid, int amount)
{
    int moveAmt;
    struct PidStats * bwl = GetPidStats(pid);
    if (NULL ==bwl)
        return;

    moveAmt = bwl->moveAmt + amount;
    if (moveAmt > 1000)
        moveAmt = 1000;
    
    bwl->moveAmt = moveAmt;
}

void PidStatsAddExpGained(u8 pid, int amount)
{
    int exp;
    struct PidStats * bwl = GetPidStats(pid);
    if (NULL ==bwl)
        return;

    exp = bwl->expGained + amount;
    if (exp > 4000)
        exp = 4000;
    
    bwl->expGained = exp;
}

int PidStatsGetTotalBattleAmt()
{
    int i, ret = 0;
    for (i = 0; i < BWL_ARRAY_SIZE; i++)
        ret += gPidStatsData[i].battleAmt;

    return ret;
}

int PidStatsGetTotalWinAmt()
{
    int i, ret = 0;
    for (i = 0; i < BWL_ARRAY_SIZE; i++)
        ret += gPidStatsData[i].winAmt;

    return ret;
}

int PidStatsGetTotalLossAmt()
{
    int i, ret = 0;
    for (i = 0; i < BWL_ARRAY_SIZE; i++)
        ret += gPidStatsData[i].lossAmt;

    return ret;
}

int PidStatsGetTotalLevel()
{
    int i, ret = 0;
    for (i = 0; i < BWL_ARRAY_SIZE; i++)
        ret += gPidStatsData[i].expGained / 100;

    return ret;
}

void PidStatsRecordBattleRes()
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
    int i, ret;
    struct GlobalSaveInfo info;
    struct PlaySt playSt;

    LoadGlobalSaveInfo(&info);

    for (i = 0; i < MAX_SAVED_GAME_CLEARS; i++)
        if (info.playThrough[i] == index)
            return FALSE;

    for (i = 0; i < 3; i++)
    {
        ret = VerifySaveBlockInfoByIndex(i);
        if (!ret)
            continue;

        LoadPlaySt(i, &playSt);

        if (playSt.playthrough_id == index)
            return FALSE;
    }

    return TRUE;
}

int GetNewPlaythroughId()
{
    int i;
    for (i = 1; i < 0x100; i++)
        if (IsPlaythroughIdUnique(i))
            return i;
}

int GetGlobalCompletedPlaythroughCount(void)
{
    int i, ret = 0;
    struct GlobalSaveInfo info;

    if (!LoadGlobalSaveInfo(&info))
        return 0;

    for (i = 0; i < MAX_SAVED_GAME_CLEARS; i++)
        if (0 != info.playThrough[i])
            ret++;
    
    return ret;
}

bool RegisterCompletedPlaythrough(struct GlobalSaveInfo * info, int index)
{
    int i;
    for (i = 0; i < MAX_SAVED_GAME_CLEARS; i++)
        if (info->playThrough[i] == index)
            return FALSE;

    for(i = 0; i < MAX_SAVED_GAME_CLEARS; i++)
        if (0 == info->playThrough[i])
        {
            info->playThrough[i] = index;
            return TRUE;
        }

    return FALSE;  
}

void SavePlayThroughData()
{
    int ret, difficult;
    int mode;
    struct GlobalSaveInfo info;

    ret = LoadGlobalSaveInfo(&info);
    if (!ret)
    {
        InitGlobalSaveInfo();
        LoadGlobalSaveInfo(&info);
    }

    RegisterCompletedPlaythrough(&info, gPlaySt.playthrough_id);
    info.playedThrough = TRUE;

    difficult = PLAY_FLAG_HARD & gPlaySt.flags;
    mode = (0 != difficult) * 2;

    if (25 == gPlaySt.chapter)
        mode++;

    switch (mode) {
    case 1:
        info.unk_0E_2 = TRUE;
        break;

    case 2:
        info.unk_0E_1 = TRUE;
        break;

    case 3:
        info.unk_0E_3 = TRUE;
        info.unk_0E_1 = TRUE;
        info.unk_0E_2 = TRUE;
        break;

    default:
        break;
    }

    SaveGlobalSaveInfo(&info);
    gPlaySt.flags |= PLAY_FLAG_COMPLETE;
}

void func_fe6_08084F48() {}
