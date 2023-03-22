#include "save_core.h"
#include "savelayout.h"

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

static char const sSaveMarker[] = "AGB-FE6";

struct SramMain * CONST_DATA gSramMain = CART_SRAM;

// TODO: this doesn't belong here
u8 EWRAM_DATA gUnk_0203D524[0xA] = { 0 };

bool EWRAM_DATA gIsSramWorking = FALSE;

void SramInit(void)
{
    u32 buf[2];

    buf[0] = 0x12345678;
    buf[1] = 0x87654321;

    SetSramFastFunc();

    REG_IE |= INTR_FLAG_GAMEPAK;

    WriteSramFast((u8 const *) &buf[0], ((void *) gSramMain) + sizeof(*gSramMain), sizeof(u32));
    ReadSramFast(((void *) gSramMain) + sizeof(*gSramMain), &buf[1], sizeof(u32));

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

    for (i = 0; i < (int) ARRAY_COUNT(buf); i++)
        buf[i] = 0xFFFFFFFF;

    for (i = 0; i < CART_SRAM_SIZE / (int) sizeof(buf); i++)
        WriteAndVerifySramFast(buf, ((void *) gSramMain) + i * sizeof(buf), sizeof(buf));

    STATIC_ASSERT(CART_SRAM_SIZE % sizeof(buf) == 0);
}

u16 Checksum16(void const * data, int size)
{
    u16 const * data_u16 = data;

    int i;

    u32 add_acc = 0;
    u32 xor_acc = 0;

    for (i = 0; i < size / 2; ++i)
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

    ReadSramFast(&gSramMain->head, info, sizeof(struct GlobalSaveInfo));

    if (!StringEquals(info->name, sSaveMarker))
        return FALSE;

    if (info->magic32 == SAVE_MAGIC32 && info->magic16 == SAVE_MAGIC16 && info->checksum == Checksum16(info, GLOBALSIZEINFO_SIZE_FOR_CHECKSUM))
        return TRUE;

    return FALSE;
}

void WriteGlobalSaveInfo(struct GlobalSaveInfo * info)
{
    info->checksum = Checksum16(info, GLOBALSIZEINFO_SIZE_FOR_CHECKSUM);
    WriteAndVerifySramFast(info, &gSramMain->head, sizeof(struct GlobalSaveInfo));
}

void WriteGlobalSaveInfoNoChecksum(struct GlobalSaveInfo * info)
{
    WriteAndVerifySramFast(info, &gSramMain->head, sizeof(struct GlobalSaveInfo));
}

void InitGlobalSaveInfo(void)
{
    struct GlobalSaveInfo info;

    int i;

    WipeSram();

    StringCopy(info.name, sSaveMarker);
    info.magic32 = SAVE_MAGIC32;
    info.magic16 = SAVE_MAGIC16;
    info.completed = FALSE;
    info.completed_true = FALSE;
    info.completed_hard = FALSE;
    info.completed_true_hard = FALSE;
    info.unk_0E_4 = 0;
    info.last_suspend_slot = 0;
    info.last_game_save_id = 0;

    for (i = 0; i < MAX_CLEARED_PLAYTHROUGHS; i++)
        info.cleared_playthroughs[i] = 0;

    WriteGlobalSaveInfo(&info);
}

void * SramOffsetToAddr(u16 off)
{
    return ((void *) gSramMain) + off;
}

u16 SramAddrToOffset(void * addr)
{
    return ((u8 *) addr) - ((u8 *) (void *) gSramMain);
}

bool ReadSaveBlockInfo(struct SaveBlockInfo * block_info, int save_id)
{
    struct SaveBlockInfo local_block_info;
    u32 magic32;

    if (block_info == NULL)
        block_info = &local_block_info;

    ReadSramFast(&gSramMain->block_info[save_id], block_info, sizeof(struct SaveBlockInfo));

    if (block_info->magic16 != SAVE_MAGIC16)
        return FALSE;

    switch (save_id)
    {
        case SAVE_GAME0:
        case SAVE_GAME1:
        case SAVE_GAME2:
            magic32 = SAVE_MAGIC32;
            break;

        case SAVE_SUSPEND:
        case SAVE_SUSPEND_ALT:
            magic32 = SAVE_MAGIC32;
            break;

        case SAVE_MULTIARENA:
            magic32 = SAVE_MAGIC32_MULTIARENA;
            break;

        case SAVE_XMAP:
            magic32 = SAVE_MAGIC32_XMAP;
            break;

        default:
            return FALSE;
    }

    if (block_info->magic32 != magic32)
        return FALSE;

    return VerifySaveBlockChecksum(block_info);
}

void WriteSaveBlockInfo(struct SaveBlockInfo * block_info, int save_id)
{
    block_info->magic16 = SAVE_MAGIC16;

#if BUGFIX
    chuck->offset = SramAddrToOffset(GetSaveWriteAddr(save_id));
#else
    block_info->offset = (uintptr_t)GetSaveWriteAddr(save_id);
#endif

    if (save_id >= SAVE_COUNT)
        return;

    switch (block_info->kind)
    {
        case SAVE_KIND_GAME:
            block_info->size = sizeof(struct GameSaveBlock);
            break;

        case SAVE_KIND_SUSPEND:
            block_info->size = sizeof(struct SuspendSaveBlock);
            break;

        case SAVE_KIND_MULTIARENA:
            block_info->size = sizeof(struct MultiArenaSaveBlock);
            break;

        case SAVE_KIND_XMAP:
            block_info->size = SRAM_XMAP_SIZE;
            break;

        case SAVE_KIND_INVALID:
            block_info->size = 0;
            block_info->offset = 0;
            block_info->magic16 = 0;
            break;

        default:
            return;
    }

    PopulateSaveBlockChecksum(block_info);
    WriteAndVerifySramFast(block_info, &gSramMain->block_info[save_id], sizeof(struct SaveBlockInfo));
}

void * GetSaveWriteAddr(int save_id)
{
    switch (save_id)
    {
        case SAVE_GAME0:
            return &gSramMain->game_0;

        case SAVE_GAME1:
            return &gSramMain->game_1;

        case SAVE_GAME2:
            return &gSramMain->game_2;

        case SAVE_SUSPEND:
            return &gSramMain->suspend;

        case SAVE_SUSPEND_ALT:
            return &gSramMain->suspend_alt;

        case SAVE_MULTIARENA:
            return &gSramMain->multi_arena;

        case SAVE_XMAP:
            return SRAM_XMAP_ADDR;

        default:
            return NULL;
    }
}

void * GetSaveReadAddr(int save_id)
{
    struct SaveBlockInfo block_info;
    ReadSaveBlockInfo(&block_info, save_id);
    return SramOffsetToAddr(block_info.offset);
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

bool IsMultiArenaAvailable(void)
{
    int i;

    if (IsSramWorking())
    {
        for (i = 0; i < 3; i++)
        {
            if (IsGameSavePastFirstChapter(i))
                return TRUE;
        }

        return IsMultiArenaSaveReady();
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
