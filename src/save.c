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

enum SaveSaDataSizes {
    SAVESA_SIZE_PLAYST = sizeof(struct PlaySt),
    SAVESA_SIZE_UNIT = 52 * sizeof(struct UnitSavePack),
    SAVESA_SIZE_SUPPLY = SUPPLY_ITEM_COUNT * sizeof(u16),
    SAVESA_SIZE_PIDSTATS = sizeof(gPidStatsData),
    SAVESA_SIZE_CHWIN = sizeof(gChWinData),
};

enum SaveSaDataOffsets {
    SAVESA_OFF_START = 0,
    SAVESA_OFF_PLAYST = SAVESA_OFF_START,
    SAVESA_OFF_UNIT = SAVESA_OFF_PLAYST + SAVESA_SIZE_PLAYST,
    SAVESA_OFF_SUPPLY = SAVESA_OFF_UNIT + SAVESA_SIZE_UNIT,
    SAVESA_OFF_PIDSTATS = SAVESA_OFF_SUPPLY + SAVESA_SIZE_SUPPLY,
    SAVESA_OFF_CHWIN = SAVESA_OFF_PIDSTATS + SAVESA_SIZE_PIDSTATS,
    SAVESA_OFF_PERMFLAG = SAVESA_OFF_CHWIN + SAVESA_SIZE_CHWIN,
};

EWRAM_DATA u8 gUnk_0203D524[0xA] = {0};
EWRAM_DATA bool gBoolSramWorking = 0;
EWRAM_DATA u8 *gPidStatsSaveLoc = NULL;
EWRAM_DATA struct PidStats gPidStatsData[BWL_ARRAY_SIZE] = {0};
EWRAM_DATA struct ChWinData gChWinData[WIN_ARRAY_SIZE] = {0};
EWRAM_DATA u32 gBonusContentClaimFlags = 0;

void SramInit()
{
    u32 buf[2];
    buf[0] = 0x12345678;
    buf[1] = 0x87654321;

    SetSramFastFunc();
    REG_IE |= 0x2000;
    WriteSramFast((u8*)(&buf[0]), gpSramEntry + 0x6EF4, 4);
    (*ReadSramFast)(gpSramEntry + 0x6EF4,(u8*)(&buf[1]), 4);

    gBoolSramWorking = (buf[1] == buf[0])
                     ? 1
                     : 0;
}

bool IsSramWorking(void)
{
    return gBoolSramWorking;
}

void EraseSaveData()
{
    int buf[0x10];
    int i;

    for (i = 0; i < 0x10; i++)
        buf[i] = -1;

    for (i = 0; i < 0x200; i++)
        WriteAndVerifySramFast((u8*)buf, gpSramEntry + i * 0x40, 0x40);
}

u16 ComputeChecksum16(const u16* data, int size)
{
    int i;
    u32 addAcc = 0;
    u32 xorAcc = 0;
    
    for (i = 0; i < size/2; ++i) {
        addAcc += data[i];
        xorAcc ^= data[i];
    }
    
    return addAcc + xorAcc;
}

bool LoadGlobalSaveInfo(struct GlobalSaveInfo *saveInfo)
{
    struct GlobalSaveInfo info_;
    struct GlobalSaveInfo *info = saveInfo;

    if (!IsSramWorking())
        return 0;

    if (NULL == saveInfo)
        info = &info_;

    (*ReadSramFast)((u8*)gpSramEntry, (u8*)info, sizeof(struct GlobalSaveInfo));

    if ((0 != StringEquals(info->name, gGlobalSaveInfoName)) &&
        (0x11217 == info->magic_a) &&
        (0x200A == info->magic_b) &&
        (info->cksum16 == ComputeChecksum16((u16*)info, sizeof(struct GlobalSaveInfo) - 4)))
        return 1;

    return 0;
}

void SaveGlobalSaveInfo(struct GlobalSaveInfo *saveInfo)
{
    saveInfo->cksum16 = ComputeChecksum16((u16*)saveInfo, sizeof(struct GlobalSaveInfo) - 4);
    WriteAndVerifySramFast((u8*)saveInfo, gpSramEntry, sizeof(struct GlobalSaveInfo));
}

void SaveGlobalSaveInfoNoChecksum(struct GlobalSaveInfo *saveInfo)
{
    WriteAndVerifySramFast((u8*)saveInfo, gpSramEntry, sizeof(struct GlobalSaveInfo));
}

void InitGlobalSaveInfo()
{
    int i;
    struct GlobalSaveInfo info;

    EraseSaveData();
    StringCopy(info.name, gGlobalSaveInfoName);

    info.magic_a = 0x11217;
    info.magic_b = 0x200A;

    info.unk_0E_0 = 0;
    info.unk_0E_2 = 0;
    info.unk_0E_1 = 0;
    info.unk_0E_3 = 0;
    info.unk_0E_4 = 0;
    
    info.slot_su = 0;
    info.slot_sa = 0;

    for (i = 0; i < MAX_SAVED_GAME_CLEARS; i++)
        info.playThrough[i] = 0;

    SaveGlobalSaveInfo(&info);
}

u8 *SramOffsetToPointer(u16 off)
{
    return gpSramEntry + off;
}

u16 SramPointerToOffset(u8 *addr)
{
    return addr - gpSramEntry;
}

bool LoadAndVerifySaveBlockInfo(struct SaveBlockInfo *chunk, int id)
{
    u32 magic_a;
    struct SaveBlockInfo tmp;

    if (NULL == chunk)
        chunk = &tmp;

    (*ReadSramFast)((u8*)&((struct SramHeader*)gpSramEntry)->chunks[id], (u8*)chunk, sizeof(struct SaveBlockInfo));

    if (0x200A != chunk->magic_b)
        return FALSE;

    switch (id) {
    case SAVE_ID_GAME0:
    case SAVE_ID_GAME1:
    case SAVE_ID_GAME2:
    case SAVE_ID_SUSPEND0:
        magic_a = 0x11217;
        break;

    case SAVE_ID_SUSPEND1:
        magic_a = 0x11217;
        break;
    
    case SAVE_ID_5:
        magic_a = 0x20112;
        break;

    case SAVE_ID_6:
        magic_a = 0x20223;
        break;

    default:
        return FALSE;
    } /* switch */

    if (chunk->magic_a != magic_a)
        return FALSE;

    return CkSum32SaveBlockInfo(chunk);
}

void WriteAndCkSum32SaveBlockInfo(struct SaveBlockInfo *chunk, int index)
{
    chunk->magic_b = 0x200A;
    chunk->offset  = (uintptr_t)GetSaveTargetAddress(index);

    if (!(index < SAVE_ID_MAX))
        return;
    
    switch (chunk->kind) {
    case SAVE_ID_GAME0:
        chunk->size = 0xDF0;
        break;

    case SAVE_ID_GAME1:
        chunk->size = 0x1DAC;
        break;

    case SAVE_ID_GAME2:
        chunk->size = 0x93C;
        break;

    case SAVE_ID_SUSPEND0:
        chunk->size = 0x1000;
        break;

    case 0xFF:
        chunk->size = 0;
        chunk->offset = 0;
        chunk->magic_b = 0;
        break;

    default:
        return;
    }; /* switch */

    GenerateSaveBlockInfoCkSum32(chunk);
    WriteAndVerifySramFast((u8*)chunk, (u8*)&((struct SramHeader*)gpSramEntry)->chunks[index], sizeof(struct SaveBlockInfo));
}

u8 *GetSaveTargetAddress(int index)
{
    switch (index) {
        case SAVE_ID_GAME0:
            return 0x3BE8 + gpSramEntry;

        case SAVE_ID_GAME1:
            return 0x49D8 + gpSramEntry;

        case SAVE_ID_GAME2:
            return 0x57C8 + gpSramEntry;

        case SAVE_ID_SUSPEND0:
            return 0x0090 + gpSramEntry;

        case SAVE_ID_SUSPEND1:
            return 0x1E3C + gpSramEntry;

        case SAVE_ID_5:
            return 0x65B8 + gpSramEntry;

        case SAVE_ID_6:
            return (u8*)0x0E007000;

        default:
            return NULL;
    } /* switch */
}

u8 *GetSaveSourceAddress(int index)
{
    struct SaveBlockInfo chunk;
    LoadAndVerifySaveBlockInfo(&chunk, index);
    return SramOffsetToPointer(chunk.offset);
}

void SaveChapterFlagBits(u8 *sram_dst)
{
    WriteAndVerifySramFast(
        GetChapterFlagBits(),
        sram_dst,
        GetChapterFlagBitsSize()
    );
}

void SavePermanentFlagBits(u8 *sram_dst)
{
    WriteAndVerifySramFast(
        GetPermanentFlagBits(),
        sram_dst,
        GetPermanentFlagBitsSize()
    );
}

void LoadChapterFlagBits(u8 *sram_src)
{
    (*ReadSramFast)(
        sram_src,
        GetChapterFlagBits(),
        GetChapterFlagBitsSize()
    );
}

void LoadPermanentFlagBits(u8 *sram_src)
{
    (*ReadSramFast)(
        sram_src,
        GetPermanentFlagBits(),
        GetPermanentFlagBitsSize()
    );
}

void SaveSupplyItems(u8 *sram_dst)
{
    WriteAndVerifySramFast(
        (u8*)GetSupplyItems(),
        sram_dst,
        SUPPLY_ITEM_COUNT * sizeof(u16)
    );
}

void LoadSupplyItems(u8 *sram_src)
{
    (*ReadSramFast)(
        sram_src,
        (u8*)GetSupplyItems(),
        SUPPLY_ITEM_COUNT * sizeof(u16)
    );
}

bool GetGlobalSaveInfo_unk0Eb0()
{
    int ret;
    struct GlobalSaveInfo info;

    ret = LoadGlobalSaveInfo(&info);
    if (ret)
        return info.unk_0E_0;
    else
        return FALSE;
}

bool func_fe6_08084714()
{
    return TRUE;
}

bool func_fe6_08084718()
{
    int i;

    if (IsSramWorking()) {
        for (i = 0; i < 3; i++)
            if (CheckSaveChunkChapterValid(i))
                return TRUE;
        
        return func_fe6_08086558();
    }

    /** 
     * This is a bug, but the compiler 
     * solved this problem accidentally LOL.
     */

    /* return FLASE; */
}

bool GetGlobalSaveInfo_unk0Eb0_()
{
    return GetGlobalSaveInfo_unk0Eb0();
}

bool CheckHasCompletedSave()
{
    int i;
    struct PlaySt playSt;

    for (i = 0; i < 3; i++) {
        if (VerifySaveBlockInfoByIndex(i)) {
            LoadPlaySt(i, &playSt);

            if (PLAY_FLAG_COMPLETE & playSt.flags)
                return TRUE;
        }
    }

    return FALSE;
}

void ClearPidChStatsSaveData(u8 *sram_dst)
{
    int i;

    CpuFill16(0, gPidStatsData, sizeof(gPidStatsData));
    CpuFill16(0, gChWinData, sizeof(gChWinData));

    for (i = 0; i < BWL_ARRAY_SIZE; i++) {
        WriteAndVerifySramFast((u8*)gPidStatsData,
                               sram_dst + 0x908 + i * sizeof(struct PidStats),
                               sizeof(struct PidStats)
        );
    }

    for (i = 0; i < WIN_ARRAY_SIZE; i++) {
        WriteAndVerifySramFast((u8*)gChWinData,
                               sram_dst + 0xD68 + i * sizeof(struct ChWinData),
                               sizeof(struct ChWinData)
        );
    }

    gPidStatsSaveLoc = sram_dst + 0x908;
}

void ClearPidStats()
{
    CpuFill16(0, gPidStatsData, sizeof(gPidStatsData));
}

void LoadPidStats(u8 *sram_src)
{
    (*ReadSramFast)(
        sram_src,
        (u8*)gPidStatsData,
        sizeof(gPidStatsData)
    );

    gPidStatsSaveLoc = sram_src;
}

void LoadChWinData(u8 *sram_src)
{
    (*ReadSramFast)(
        sram_src,
        (u8*)gChWinData,
        sizeof(gChWinData)
    );
}

void SavePidStats(u8 *sram_dst)
{
    WriteAndVerifySramFast(
        (u8*)gPidStatsData,
        sram_dst,
        sizeof(gPidStatsData)
    );

    gPidStatsSaveLoc = sram_dst;
}

void SaveChWinData(u8 *sram_dst)
{
    WriteAndVerifySramFast(
        (u8*)gChWinData,
        sram_dst,
        sizeof(gChWinData)
    );
}

struct ChWinData *GetChWinData(int index)
{
    return &gChWinData[index];
}

bool IsWinDataValid(struct ChWinData *winData)
{
    return winData->chapter_turn > 0;
}

int GetFreeChWinDataIndex()
{
    struct ChWinData *cur = GetChWinData(0);
    int ret = 0;

    while (cur->chapter_turn) {
        ++ret;
        ++cur;
    }

    return ret;
}

void RegisterChWinData(struct PlaySt *playSt)
{
    int time, turn;
    struct ChWinData *winData = GetChWinData(GetFreeChWinDataIndex());

    time = (GetGameTime() - playSt->unk_04) / 180;
    if (time > 60000)
        time = 60000;

    winData->chapter_index = playSt->chapter;
    winData->chapter_turn = playSt->turn;
    winData->chapter_time = time;
}

void PidStatsAddBattleAmt(struct Unit *unit)
{
    struct PidStats *bwl;
    
    if (FACTION_BLUE != UNIT_FACTION(unit))
        return;
    
    bwl = GetPidStats_(UNIT_PID(unit));
    if (!bwl)
        return;
    
    if (bwl->battleAmt < 4000)
        bwl->battleAmt++;
}

void PidStatsAddWinAmt(u8 pid)
{
    struct PidStats *bwl = GetPidStats_(pid);
    if (!bwl)
        return;
    
    if (bwl->winAmt < 1000)
        bwl->winAmt++;
}

void PidStatsRecordLoseData(u8 pid)
{
    int index;
    struct SaveBlockInfo chunk;
    struct PidStats *bwl;

    if (IsSramWorking()) {
        bwl = GetPidStats_(pid);
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

        if (bwl->lossAmt < 200) {
            bwl->lossAmt++;

            index = GetLastSuspendSlotIndex() + 3;
            WriteAndVerifySramFast((u8*)bwl,
                                   GetSaveTargetAddress(index) + 0x18B0 + pid * sizeof(struct PidStats),
                                   1);

            LoadAndVerifySaveBlockInfo(&chunk, index);
            WriteAndCkSum32SaveBlockInfo(&chunk, index);

            WriteAndVerifySramFast((u8*)bwl,
                                   GetSaveTargetAddress(gPlaySt.save_slot) + 0x8F8 + pid * sizeof(struct PidStats),
                                   1);

            LoadAndVerifySaveBlockInfo(&chunk, gPlaySt.save_slot);
            WriteAndCkSum32SaveBlockInfo(&chunk, gPlaySt.save_slot);
        }
    }
}

void PidStatsRecordDeathData(u8 pid, u8 killerPid, int deathCause)
{
    struct PidStats *bwl = GetPidStats_(pid);
    if (NULL ==bwl)
        return;

    bwl->deathCh = gPlaySt.chapter;
    bwl->deathTurn = gPlaySt.turn;
    bwl->killerPid = killerPid;
    bwl->deathCause = deathCause;
}

void PidStatsAddActAmt(u8 pid)
{
    struct PidStats *bwl = GetPidStats_(pid);
    if (NULL ==bwl)
        return;

    if (bwl->actAmt < 200)
        bwl->actAmt++;
}

void PidStatsAddStatViewAmt(u8 pid)
{
    struct PidStats *bwl = GetPidStats_(pid);
    if (NULL ==bwl)
        return;

    if (bwl->statViewAmt < 200)
        bwl->statViewAmt++;
}

void PidStatsAddDeployAmt(u8 pid)
{
    struct PidStats *bwl = GetPidStats_(pid);
    if (NULL ==bwl)
        return;

    if (bwl->deployAmt < 50)
        bwl->deployAmt++;
}

void PidStatsAddSquaresMoved(u8 pid, int amount)
{
    int moveAmt;
    struct PidStats *bwl = GetPidStats_(pid);
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
    struct PidStats *bwl = GetPidStats_(pid);
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
    struct BattleUnit *buA = NULL, *buB = NULL;

    if (0 == GetUnitCurrentHp(&gBattleUnitA.unit)) {
        buA = &gBattleUnitA;
        buB = &gBattleUnitB;
    }

    if (0 == GetUnitCurrentHp(&gBattleUnitB.unit)) {
        buA = &gBattleUnitB;
        buB = &gBattleUnitA;
    }

    if (buA) {
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

    for (i = 0; i < 3; i++) {
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

bool RegisterCompletedPlaythrough(struct GlobalSaveInfo *info, int index)
{
    int i;
    for (i = 0; i < MAX_SAVED_GAME_CLEARS; i++)
        if (info->playThrough[i] == index)
            return FALSE;

    for(i = 0; i < MAX_SAVED_GAME_CLEARS; i++)
        if (0 == info->playThrough[i]) {
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
    if (!ret) {
        InitGlobalSaveInfo();
        LoadGlobalSaveInfo(&info);
    }

    RegisterCompletedPlaythrough(&info, gPlaySt.playthrough_id);
    info.unk_0E_0 = TRUE;

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

void func_fe6_08084F48()
{

}

struct PidStats *GetPidStats(u8 pid)
{
    if (pid >= BWL_ARRAY_SIZE)
        return NULL;
    else if (0 == GetPInfo(pid)->affinity)
        return NULL;
    else
        return &gPidStats[pid];
}

void UpdateLastUsedGameSaveSlot(int slot_sa)
{
    struct GlobalSaveInfo info;

    LoadGlobalSaveInfo(&info);
    info.slot_sa = slot_sa;
    SaveGlobalSaveInfoNoChecksum(&info);
}

int GetLastUsedGameSaveSlot()
{
    int ret;
    struct GlobalSaveInfo info;

    if (!LoadGlobalSaveInfo(&info))
        return 0;
    
    ret = info.slot_sa;
    if (ret > 2)
        return 0;
    else if (ret < 0)
        return 0;
    else
        return ret;
}

void func_fe6_08084FB8(int slot)
{
    struct SaveBlockInfo chunk;
    struct PlaySt playSt;

    if (func_fe6_080859E0(SAVE_ID_SUSPEND0)) {
        func_fe6_08085A34(SAVE_ID_SUSPEND0, &playSt);

        if (playSt.save_slot == slot)
            ResetSaveBlockInfo(SAVE_ID_SUSPEND0);
    }

    chunk.kind = -1;
    WriteAndCkSum32SaveBlockInfo(&chunk, slot);
}

void CopyGameSave(int index_src, int index_dst)
{
    struct SaveBlockInfo chunk;
    u8 *src = GetSaveSourceAddress(index_src);
    u8 *dst = GetSaveTargetAddress(index_dst);

    (*ReadSramFast)(src, gBuf, 0xDF0);
    WriteAndVerifySramFast(gBuf, dst, 0xDF0);

    chunk.magic_a = 0x11217;
    chunk.kind = 0;
    WriteAndCkSum32SaveBlockInfo(&chunk, index_dst);
}

void SaveNewGame(int slot, int isHard)
{
    int i;
    struct SaveBlockInfo chunk;
    u8 buf[0x28];
    u8 *dst = GetSaveTargetAddress(slot);

    InitPlayConfig(isHard);
    InitUnits();
    ClearSupplyItems();
    ResetPermanentFlags();
    ResetSaveBlockInfo(SAVE_ID_SUSPEND0);

    gPlaySt.playthrough_id = GetNewPlaythroughId();
    gPlaySt.save_slot = slot;

    WriteAndVerifySramFast((u8*)&gPlaySt, dst, sizeof(gPlaySt));

    CpuFill16(0, buf, sizeof(buf));
    for (i = 0; i < 0x34; i++)
        WriteAndVerifySramFast(buf, dst + sizeof(gPlaySt) + sizeof(buf) * i, sizeof(buf));

    SaveSupplyItems(dst + 0x840);
    ClearPidChStatsSaveData(dst);
    SavePermanentFlagBits(dst + 0xDE8);

    chunk.magic_a = 0x11217;
    chunk.kind = 0;
    WriteAndCkSum32SaveBlockInfo(&chunk, slot);
    UpdateLastUsedGameSaveSlot(slot);
}

void SaveGame(int slot)
{
    int i;
    struct SaveBlockInfo chunk;
    u8 *dst = GetSaveTargetAddress(slot);

    ResetSaveBlockInfo(SAVE_ID_SUSPEND0);

    gPlaySt.save_slot = slot;
    gPlaySt.unk_00 = GetGameTime();
    WriteAndVerifySramFast((u8*)&gPlaySt, dst + SAVESA_OFF_PLAYST, sizeof(gPlaySt));

    for (i = 0; i < 52; i++)
        SaveUnit(&gUnitArrayBlue[i], dst + SAVESA_OFF_UNIT + i * sizeof(struct UnitSavePack));

    SaveSupplyItems(dst + SAVESA_OFF_SUPPLY);
    SavePidStats(dst + SAVESA_OFF_PIDSTATS);
    SaveChWinData(dst + SAVESA_OFF_CHWIN);
    SavePermanentFlagBits(dst + SAVESA_OFF_PERMFLAG);

    chunk.magic_a = 0x11217;
    chunk.kind = 0;
    WriteAndCkSum32SaveBlockInfo(&chunk, slot);
    UpdateLastUsedGameSaveSlot(slot);
}

void LoadGame(int slot)
{
    int i;
    u8 *src = GetSaveSourceAddress(slot);

    if (!(BM_FLAG_LINKARENA & gBmSt.flags))
        ResetSaveBlockInfo(SAVE_ID_SUSPEND0);

    (*ReadSramFast)(src + SAVESA_OFF_PLAYST, (u8*)&gPlaySt, sizeof(gPlaySt));
    SetGameTime(gPlaySt.unk_00);
    gPlaySt.save_slot = slot;

    InitUnits();
    for (i = 0; i < 52; i++)
        LoadUnit(src + SAVESA_OFF_UNIT + i * sizeof(struct UnitSavePack), &gUnitArrayBlue[i]);

    LoadSupplyItems(src + SAVESA_OFF_SUPPLY);
    LoadPermanentFlagBits(src + SAVESA_OFF_PERMFLAG);
    LoadPidStats(src + SAVESA_OFF_PIDSTATS);
    LoadChWinData(src + SAVESA_OFF_CHWIN);

    UpdateLastUsedGameSaveSlot(slot);
}

bool VerifySaveBlockInfoByIndex(int slot)
{
    return LoadAndVerifySaveBlockInfo(NULL, slot);
}

void LoadPlaySt(int slot, struct PlaySt *playSt)
{
    u8 *src = GetSaveSourceAddress(slot);
    (*ReadSramFast)(src + SAVESA_OFF_PLAYST, (u8*)playSt, sizeof(struct PlaySt));
}

bool CheckSaveChunkChapterValid(int slot)
{
    struct PlaySt playSt;

    if (!VerifySaveBlockInfoByIndex(slot))
        return FALSE;

    LoadPlaySt(slot, &playSt);

    if (playSt.chapter <= 1)
        return FALSE;
    else
        return TRUE;
}

void SaveUnit(struct Unit *unit, void *sram_dst)
{
    int i;
    struct UnitSavePack unitp;

    unitp.pid = unit->pinfo->id;
    unitp.jid = unit->jinfo->id;

    if (!unit->pinfo) {
        struct Unit _unit;
        unit = &_unit;

        ClearUnit(unit);
        unitp.pid = 0;
        unitp.jid = 0;
    }

    unitp.level = *(u8*)&unit->level;
    unitp.exp = unit->exp;
    unitp.x = unit->x;
    unitp.y = unit->y;
    unitp.max_hp = *(i8*)&unit->max_hp;
    unitp.pow = unit->pow;
    unitp.skl = unit->skl;
    unitp.spd = unit->spd;
    unitp.def = unit->def;
    unitp.res = unit->res;
    unitp.lck = unit->lck;
    unitp.con = unit->bonus_con;
    unitp.mov = unit->bonus_mov;

    unitp.item0 = unit->items[0];
    unitp.item1 = unit->items[1];
    unitp.item2 = unit->items[2];
    unitp.item3 = unit->items[3];
    unitp.item4 = unit->items[4];

    unitp.flags = 0;

    if (UNIT_FLAG_DEAD & unit->flags)
        unitp.flags |= PACKED_US_DEAD;

    if (UNIT_FLAG_NOT_DEPLOYED & unit->flags)
        unitp.flags |= PACKED_US_UNDEPLOYED;

    if (UNIT_FLAG_SOLOANIM_1 & unit->flags)
        unitp.flags |= PACKED_US_SOLO_ANIM1;

    if (UNIT_FLAG_SOLOANIM_2 & unit->flags)
        unitp.flags |= PACKED_US_SOLO_ANIM2;

    for (i = 0; i < UNIT_WEAPON_EXP_COUNT; i++)
        unitp.wexp[i] = unit->wexp[i];

    for (i = 0; i < UNIT_SUPPORT_COUNT; i++)
        unitp.supports[i] = unit->supports[i];

    WriteAndVerifySramFast((u8*)&unitp, sram_dst, sizeof(struct UnitSavePack));
}

void LoadUnit(u8 *sram_src, struct Unit *unit)
{
    int i;
    struct UnitSavePack unitp;

    (*ReadSramFast)(sram_src, (u8*)&unitp, sizeof(struct UnitSavePack));

    unit->pinfo = GetPInfo(unitp.pid);
    unit->jinfo = GetJInfo(unitp.jid);

    unit->level = unitp.level;
    unit->exp = unitp.exp;
    unit->x = unitp.x;
    unit->y = unitp.y;
    unit->max_hp = unitp.max_hp;
    unit->pow = unitp.pow;
    unit->skl = unitp.skl;
    unit->spd = unitp.spd;
    unit->def = unitp.def;
    unit->res = unitp.res;
    unit->lck = unitp.lck;
    unit->bonus_con = unitp.con;
    unit->bonus_mov = unitp.mov;

    unit->items[0] = unitp.item0;
    unit->items[1] = unitp.item1;
    unit->items[2] = unitp.item2;
    unit->items[3] = unitp.item3;
    unit->items[4] = unitp.item4;

    if (unit->exp > 99)
        unit->exp = -1;

    unit->flags = 0;

    if (unitp.flags & PACKED_US_DEAD)
        unit->flags |= UNIT_FLAG_DEAD | UNIT_FLAG_HIDDEN;

    if (unitp.flags & PACKED_US_UNDEPLOYED)
        unit->flags |= UNIT_FLAG_NOT_DEPLOYED | UNIT_FLAG_HIDDEN;

    if (unitp.flags & PACKED_US_SOLO_ANIM1)
        unit->flags |= UNIT_FLAG_SOLOANIM_1;

    if (unitp.flags & PACKED_US_SOLO_ANIM2)
        unit->flags |= UNIT_FLAG_SOLOANIM_2;

    for (i = 0; i < UNIT_WEAPON_EXP_COUNT; i++)
        unit->wexp[i] = unitp.wexp[i];

    for (i = 0; i < UNIT_SUPPORT_COUNT; i++)
        unit->supports[i] = unitp.supports[i];

    SetUnitHp(unit, GetUnitMaxHp(unit));

    if (0x7F == unit->exp)
        unit->exp = -1;

    if (0x3F == unit->x)
        unit->x = -1;

    if (0x3F == unit->y)
        unit->y = -1;
}
