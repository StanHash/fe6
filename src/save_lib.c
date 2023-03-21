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

u8 EWRAM_DATA gUnk_0203D524[0xA] = {0};
bool EWRAM_DATA gIsSramWorking = FALSE;
void * EWRAM_DATA gPidStatsSaveLoc = NULL;
struct PidStats EWRAM_DATA gPidStatsData[BWL_ARRAY_SIZE] = {0};
struct ChapterStats EWRAM_DATA gChapterStats[WIN_ARRAY_SIZE] = {0};
u8 EWRAM_DATA gSuspendSaveIdOffset = 0;

void SramInit(void)
{
    u32 buf[2];

    buf[0] = 0x12345678;
    buf[1] = 0x87654321;

    SetSramFastFunc();

    REG_IE |= INTR_FLAG_GAMEPAK;

    WriteSramFast((u8 const *) &buf[0], gSram + SRAM_OFFSET_END, sizeof(u32));
    ReadSramFast(gSram + SRAM_OFFSET_END, (u8 *) &buf[1], sizeof(u32));

    gIsSramWorking = (buf[1] == buf[0]) ? TRUE : FALSE;
}

bool IsSramWorking(void)
{
    return gIsSramWorking;
}

void WipeSram(void)
{
    u32 buf[0x10];
    int i;

    for (i = 0; i < 0x10; i++)
        buf[i] = 0xFFFFFFFF;

    for (i = 0; i < 0x200; i++)
        WriteAndVerifySramFast((u8 *) buf, gSram + i * 0x40, 0x40);
}

u16 Checksum16(void const * data, int size)
{
    u16 const * data_u16 = data;

    int i;

    u32 add_acc = 0;
    u32 xor_acc = 0;

    for (i = 0; i < size/2; ++i)
    {
        add_acc += data_u16[i];
        xor_acc ^= data_u16[i];
    }

    return add_acc + xor_acc;
}

bool ReadGlobalSaveInfo(struct GlobalSaveInfo * info)
{
    struct GlobalSaveInfo local_info;

    if (!IsSramWorking())
        return FALSE;

    if (info == NULL)
        info = &local_info;

    ReadSramFast(gSram + SRAM_OFFSET_HEADER, info, sizeof(struct GlobalSaveInfo));

    if (!StringEquals(info->name, gGlobalSaveInfoName))
        return FALSE;

    if (info->magic32 == SAVEMAGIC32 && info->magic16 == SAVEMAGIC16 && info->checksum == Checksum16(info, GLOBALSIZEINFO_SIZE_FOR_CHECKSUM))
        return TRUE;

    return FALSE;
}

void WriteGlobalSaveInfo(struct GlobalSaveInfo * info)
{
    info->checksum = Checksum16(info, GLOBALSIZEINFO_SIZE_FOR_CHECKSUM);
    WriteAndVerifySramFast(info, gSram + SRAM_OFFSET_HEADER, sizeof(struct GlobalSaveInfo));
}

void WriteGlobalSaveInfoNoChecksum(struct GlobalSaveInfo * info)
{
    WriteAndVerifySramFast(info, gSram + SRAM_OFFSET_HEADER, sizeof(struct GlobalSaveInfo));
}

void InitGlobalSaveInfo(void)
{
    struct GlobalSaveInfo info;

    int i;

    WipeSram();

    StringCopy(info.name, gGlobalSaveInfoName);
    info.magic32 = SAVEMAGIC32;
    info.magic16 = SAVEMAGIC16;
    info.completed = FALSE;
    info.completed_true = FALSE;
    info.completed_hard = FALSE;
    info.completed_true_hard = FALSE;
    info.unk_0E_4 = 0;
    info.last_suspend_slot = 0;
    info.last_game_save_id = 0;

    for (i = 0; i < MAX_SAVED_GAME_CLEARS; i++)
        info.cleared_playthroughs[i] = 0;

    WriteGlobalSaveInfo(&info);
}

void * SramOffsetToAddr(u16 off)
{
    return gSram + off;
}

u16 SramAddrToOffset(void * addr)
{
    return ((u8 *) addr) - gSram;
}

bool ReadSaveBlockInfo(struct SaveBlockInfo * chunk, int id)
{
    struct SaveBlockInfo local_block_info;
    u32 magic32;

    if (chunk == NULL)
        chunk = &local_block_info;

    ReadSramFast(gSram + SRAM_OFFSET_BLOCKINFO + id * sizeof(struct SaveBlockInfo), chunk, sizeof(struct SaveBlockInfo));

    if (chunk->magic16 != SAVEMAGIC16)
        return FALSE;

    switch (id)
    {
        case SAVE_ID_GAME0:
        case SAVE_ID_GAME1:
        case SAVE_ID_GAME2:
            magic32 = SAVEMAGIC32;
            break;

        case SAVE_ID_SUSPEND:
        case SAVE_ID_SUSPEND_ALT:
            magic32 = SAVEMAGIC32;
            break;

        case SAVE_ID_5:
            magic32 = SAVEMAGIC32_UNK5;
            break;

        case SAVE_ID_6:
            magic32 = SAVEMAGIC32_UNK6;
            break;

        default:
            return FALSE;
    }

    if (chunk->magic32 != magic32)
        return FALSE;

    return VerifySaveBlockChecksum(chunk);
}

void WriteSaveBlockInfo(struct SaveBlockInfo * chunk, int id)
{
    chunk->magic16 = SAVEMAGIC16;

#if BUGFIX
    chuck->offset = SramAddrToOffset(GetSaveWriteAddr(id));
#else
    chunk->offset = (uintptr_t)GetSaveWriteAddr(id);
#endif

    if (id >= SAVE_ID_MAX)
        return;

    switch (chunk->kind)
    {
        case SAVEBLOCK_KIND_GAME:
            chunk->size = SRAM_SIZE_GAMESAVE;
            break;

        case SAVEBLOCK_KIND_SUSPEND:
            chunk->size = SRAM_SIZE_SUSPEND;
            break;

        case SAVEBLOCK_KIND_2:
            chunk->size = SRAM_SIZE_5;
            break;

        case SAVEBLOCK_KIND_3:
            chunk->size = SRAM_SIZE_6;
            break;

        case (u8)SAVEBLOCK_KIND_INVALID:
            chunk->size = 0;
            chunk->offset = 0;
            chunk->magic16 = 0;
            break;

        default:
            return;
    }

    PopulateSaveBlockChecksum(chunk);
    WriteAndVerifySramFast(chunk, gSram + SRAM_OFFSET_BLOCKINFO + id * sizeof(struct SaveBlockInfo), sizeof(struct SaveBlockInfo));
}

void * GetSaveWriteAddr(int id)
{
    switch (id)
    {
        case SAVE_ID_GAME0:
            return gSram + SRAM_OFFSET_SAV0; // 0x3BE8

        case SAVE_ID_GAME1:
            return gSram + SRAM_OFFSET_SAV1; // 0x49D8

        case SAVE_ID_GAME2:
            return gSram + SRAM_OFFSET_SAV2; // 0x57C8

        case SAVE_ID_SUSPEND:
            return gSram + SRAM_OFFSET_SUS0; // 0x0090

        case SAVE_ID_SUSPEND_ALT:
            return gSram + SRAM_OFFSET_SUS1; // 0x1E3C

        case SAVE_ID_5:
            return gSram + SRAM_OFFSET_5;    // 0x65B8

        case SAVE_ID_6:
            return CART_SRAM + SRAM_OFFSET_6; // TODO: nicer

        default:
            return NULL;
    }
}

void * GetSaveReadAddr(int id)
{
    struct SaveBlockInfo chunk;
    ReadSaveBlockInfo(&chunk, id);
    return SramOffsetToAddr(chunk.offset);
}

void WriteChapterFlags(void * sram_dst)
{
    WriteAndVerifySramFast(GetChapterFlagBits(), sram_dst, GetChapterFlagBitsSize());
}

void WritePermanentFlags(void * sram_dst)
{
    WriteAndVerifySramFast(GetPermanentFlagBits(), sram_dst, GetPermanentFlagBitsSize());
}

void ReadChapterFlags(void const * sram_src)
{
    ReadSramFast(sram_src, GetChapterFlagBits(), GetChapterFlagBitsSize());
}

void ReadPermanentFlags(void const * sram_src)
{
    ReadSramFast(sram_src, GetPermanentFlagBits(), GetPermanentFlagBitsSize());
}

void WriteSupplyItems(void * sram_dst)
{
    WriteAndVerifySramFast(GetSupplyItems(), sram_dst, SUPPLY_ITEM_COUNT * sizeof(u16));
}

void ReadSupplyItems(void const * sram_src)
{
    ReadSramFast(sram_src, GetSupplyItems(), SUPPLY_ITEM_COUNT * sizeof(u16));
}

bool IsNotFirstPlaythrough(void)
{
    struct GlobalSaveInfo info;

    if (ReadGlobalSaveInfo(&info))
        return info.completed;

    return FALSE;
}

bool func_fe6_08084714(void)
{
    return TRUE;
}

bool func_fe6_08084718(void)
{
    int i;

    if (IsSramWorking())
    {
        for (i = 0; i < 3; i++)
        {
            if (IsGameSavePastFirstChapter(i))
                return TRUE;
        }

        return func_fe6_08086558();
    }

    /*
    This is a bug, but the compiler
    solved this problem accidentally LOL.
    */

#ifdef BUGFIX
    return FLASE;
#endif
}

bool IsNotFirstPlaythrough_2(void)
{
    return IsNotFirstPlaythrough();
}

bool CheckHasCompletedSave(void)
{
    int i;
    struct PlaySt play_st;

    for (i = 0; i < 3; i++)
    {
        if (IsSaveValid(i))
        {
            ReadGameSavePlaySt(i, &play_st);

            if ((play_st.flags & PLAY_FLAG_COMPLETE) != 0)
                return TRUE;
        }
    }

    return FALSE;
}
