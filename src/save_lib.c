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

EWRAM_DATA u8 gUnk_0203D524[0xA] = {0};
EWRAM_DATA bool gBoolSramWorking = 0;
EWRAM_DATA u8 * gPidStatsSaveLoc = NULL;
EWRAM_DATA struct PidStats gPidStatsData[BWL_ARRAY_SIZE] = {0};
EWRAM_DATA struct ChWinData gChWinData[WIN_ARRAY_SIZE] = {0};
EWRAM_DATA u8 gSuspendSlotIndex = 0;

void SramInit()
{
    u32 buf[2];
    buf[0] = 0x12345678;
    buf[1] = 0x87654321;

    SetSramFastFunc();
    REG_IE |= 0x2000;
    WriteSramFast((u8 *)(&buf[0]), gpSramEntry + 0x6EF4, 4);
    (*ReadSramFast)(gpSramEntry + 0x6EF4,(u8 *)(&buf[1]), 4);

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
        WriteAndVerifySramFast((u8 *)buf, gpSramEntry + i * 0x40, 0x40);
}

u16 ComputeChecksum16(const u16 * data, int size)
{
    int i;
    u32 addAcc = 0;
    u32 xorAcc = 0;
    
    for (i = 0; i < size/2; ++i)
    {
        addAcc += data[i];
        xorAcc ^= data[i];
    }
    
    return addAcc + xorAcc;
}

bool LoadGlobalSaveInfo(struct GlobalSaveInfo * saveInfo)
{
    struct GlobalSaveInfo info_;
    struct GlobalSaveInfo * info = saveInfo;

    if (!IsSramWorking())
        return 0;

    if (NULL == saveInfo)
        info = &info_;

    (*ReadSramFast)((u8 *)gpSramEntry, (u8 *)info, sizeof(struct GlobalSaveInfo));

    if ((0 != StringEquals(info->name, gGlobalSaveInfoName)) &&
        (SAVE_MAGICA_COMM == info->magic_a) &&
        (SAVE_MAGICB_COMM == info->magic_b) &&
        (info->cksum16 == ComputeChecksum16((u16 *)info, sizeof(struct GlobalSaveInfo) - 4)))
        return 1;

    return 0;
}

void SaveGlobalSaveInfo(struct GlobalSaveInfo * saveInfo)
{
    saveInfo->cksum16 = ComputeChecksum16((u16 *)saveInfo, sizeof(struct GlobalSaveInfo) - 4);
    WriteAndVerifySramFast((u8 *)saveInfo, gpSramEntry, sizeof(struct GlobalSaveInfo));
}

void SaveGlobalSaveInfoNoChecksum(struct GlobalSaveInfo * saveInfo)
{
    WriteAndVerifySramFast((u8 *)saveInfo, gpSramEntry, sizeof(struct GlobalSaveInfo));
}

void InitGlobalSaveInfo()
{
    int i;
    struct GlobalSaveInfo info;

    EraseSaveData();
    StringCopy(info.name, gGlobalSaveInfoName);

    info.magic_a = SAVE_MAGICA_COMM;
    info.magic_b = SAVE_MAGICB_COMM;

    info.playedThrough = 0;
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

u8 * SramOffsetToPointer(u16 off)
{
    return gpSramEntry + off;
}

u16 SramPointerToOffset(u8 * addr)
{
    return addr - gpSramEntry;
}

bool LoadAndVerifySaveBlockInfo(struct SaveBlockInfo * chunk, int id)
{
    u32 magic_a;
    struct SaveBlockInfo tmp;

    if (NULL == chunk)
        chunk = &tmp;

    (*ReadSramFast)((u8 *)&((struct SramHeader *)gpSramEntry)->chunks[id], (u8 *)chunk, sizeof(struct SaveBlockInfo));

    if (SAVE_MAGICB_COMM != chunk->magic_b)
        return FALSE;

    switch (id) {
    case SAVE_ID_GAME0:
    case SAVE_ID_GAME1:
    case SAVE_ID_GAME2:
        magic_a = SAVE_MAGICA_COMM;
        break;

    case SAVE_ID_SUSPEND0:
    case SAVE_ID_SUSPEND1:
        magic_a = SAVE_MAGICA_COMM;
        break;
    
    case SAVE_ID_5:
        magic_a = SAVE_MAGICA_5;
        break;

    case SAVE_ID_6:
        magic_a = SAVE_MAGICA_6;
        break;

    default:
        return FALSE;
    } /* switch */

    if (chunk->magic_a != magic_a)
        return FALSE;

    return CkSum32SaveBlockInfo(chunk);
}

void WriteSaveBlockInfo(struct SaveBlockInfo * chunk, int index)
{
    chunk->magic_b = SAVE_MAGICB_COMM;
    chunk->offset  = (uintptr_t)GetSaveTargetAddress(index);

    if (!(index < SAVE_ID_MAX))
        return;
    
    switch (chunk->kind) {
    
    /**
     * I have no idea how to get such sizes below.
     * maybe just pick a random value which is smaller than each part? 
     */

    case BLOCK_INFO_KIND_SAV:
        chunk->size = 0xDF0;
        break;

    case BLOCK_INFO_KIND_SUS:
        chunk->size = 0x1DAC;
        break;

    case BLOCK_INFO_KIND_2:
        chunk->size = 0x93C;
        break;

    case BLOCK_INFO_KIND_3:
        chunk->size = 0x1000;
        break;

    case (u8)BLOCK_INFO_KIND_INVALID:
        chunk->size = 0;
        chunk->offset = 0;
        chunk->magic_b = 0;
        break;

    default:
        return;
    }; /* switch */

    GenerateSaveBlockInfoCkSum32(chunk);
    WriteAndVerifySramFast((u8 *)chunk, (u8 *)&((struct SramHeader *)gpSramEntry)->chunks[index], sizeof(struct SaveBlockInfo));
}

u8 * GetSaveTargetAddress(int index)
{
    switch (index) {
        case SAVE_ID_GAME0:
            return gpSramEntry + SRAM_MEMMAP_SAV0; // 0x3BE8

        case SAVE_ID_GAME1:
            return gpSramEntry + SRAM_MEMMAP_SAV1; // 0x49D8

        case SAVE_ID_GAME2:
            return gpSramEntry + SRAM_MEMMAP_SAV2; // 0x57C8

        case SAVE_ID_SUSPEND0:
            return gpSramEntry + SRAM_MEMMAP_SUS0; // 0x0090

        case SAVE_ID_SUSPEND1:
            return gpSramEntry + SRAM_MEMMAP_SUS1; // 0x1E3C

        case SAVE_ID_5:
            return gpSramEntry + SRAM_MEMMAP_5;    // 0x65B8

        case SAVE_ID_6:
            return (u8 *)0x0E007000;

        default:
            return NULL;
    } /* switch */
}

u8 * GetSaveSourceAddress(int index)
{
    struct SaveBlockInfo chunk;
    LoadAndVerifySaveBlockInfo(&chunk, index);
    return SramOffsetToPointer(chunk.offset);
}

void SaveChapterFlagBits(u8 * sram_dst)
{
    WriteAndVerifySramFast(
        GetChapterFlagBits(),
        sram_dst,
        GetChapterFlagBitsSize()
    );
}

void SavePermanentFlagBits(u8 * sram_dst)
{
    WriteAndVerifySramFast(
        GetPermanentFlagBits(),
        sram_dst,
        GetPermanentFlagBitsSize()
    );
}

void LoadChapterFlagBits(u8 * sram_src)
{
    (*ReadSramFast)(
        sram_src,
        GetChapterFlagBits(),
        GetChapterFlagBitsSize()
    );
}

void LoadPermanentFlagBits(u8 * sram_src)
{
    (*ReadSramFast)(
        sram_src,
        GetPermanentFlagBits(),
        GetPermanentFlagBitsSize()
    );
}

void SaveSupplyItems(u8 * sram_dst)
{
    WriteAndVerifySramFast(
        (u8*)GetSupplyItems(),
        sram_dst,
        SUPPLY_ITEM_COUNT * sizeof(u16)
    );
}

void LoadSupplyItems(u8 * sram_src)
{
    (*ReadSramFast)(
        sram_src,
        (u8 *)GetSupplyItems(),
        SUPPLY_ITEM_COUNT * sizeof(u16)
    );
}

bool IsGamePlayThroughed()
{
    int ret;
    struct GlobalSaveInfo info;

    ret = LoadGlobalSaveInfo(&info);
    if (ret)
        return info.playedThrough;
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

    if (IsSramWorking())
    {
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

bool IsGamePlayThroughed_()
{
    return IsGamePlayThroughed();
}

bool CheckHasCompletedSave()
{
    int i;
    struct PlaySt playSt;

    for (i = 0; i < 3; i++)
    {
        if (VerifySaveBlockInfoByIndex(i))
        {
            LoadPlaySt(i, &playSt);

            if (PLAY_FLAG_COMPLETE & playSt.flags)
                return TRUE;
        }
    }

    return FALSE;
}

void ClearPidChStatsSaveData(u8 * sram_dst)
{
    int i;

    CpuFill16(0, gPidStatsData, sizeof(gPidStatsData));
    CpuFill16(0, gChWinData, sizeof(gChWinData));

    for (i = 0; i < BWL_ARRAY_SIZE; i++)
    {
        WriteAndVerifySramFast((u8 *)gPidStatsData,
                               sram_dst + SAV_MEMMAP_PIDSTATS + i * sizeof(struct PidStats),
                               sizeof(struct PidStats)
        );
    }

    for (i = 0; i < WIN_ARRAY_SIZE; i++)
    {
        WriteAndVerifySramFast((u8 *)gChWinData,
                               sram_dst + SAV_MEMMAP_CHWIN + i * sizeof(struct ChWinData),
                               sizeof(struct ChWinData)
        );
    }

    gPidStatsSaveLoc = sram_dst + SAV_MEMMAP_PIDSTATS;
}

void ClearPidStats()
{
    CpuFill16(0, gPidStatsData, sizeof(gPidStatsData));
}

void LoadPidStats(u8 * sram_src)
{
    (*ReadSramFast)(
        sram_src,
        (u8 *)gPidStatsData,
        sizeof(gPidStatsData)
    );

    gPidStatsSaveLoc = sram_src;
}

void LoadChWinData(u8 * sram_src)
{
    (*ReadSramFast)(
        sram_src,
        (u8 *)gChWinData,
        sizeof(gChWinData)
    );
}

void SavePidStats(u8 * sram_dst)
{
    WriteAndVerifySramFast(
        (u8 *)gPidStatsData,
        sram_dst,
        sizeof(gPidStatsData)
    );

    gPidStatsSaveLoc = sram_dst;
}

void SaveChWinData(u8 * sram_dst)
{
    WriteAndVerifySramFast(
        (u8 *)gChWinData,
        sram_dst,
        sizeof(gChWinData)
    );
}

struct ChWinData * GetChWinData(int index)
{
    return &gChWinData[index];
}

bool IsWinDataValid(struct ChWinData * winData)
{
    return winData->chapter_turn > 0;
}

int GetFreeChWinDataIndex()
{
    struct ChWinData * cur = GetChWinData(0);
    int ret = 0;

    while (cur->chapter_turn)
    {
        ++ret;
        ++cur;
    }

    return ret;
}

void RegisterChWinData(struct PlaySt * playSt)
{
    int time, turn;
    struct ChWinData * winData = GetChWinData(GetFreeChWinDataIndex());

    time = (GetGameTime() - playSt->unk_04) / 180;
    if (time > 60000)
        time = 60000;

    winData->chapter_index = playSt->chapter;
    winData->chapter_turn = playSt->turn;
    winData->chapter_time = time;
}
