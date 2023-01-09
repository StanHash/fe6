#include "save.h"

#include "sram.h"
#include "gbaio.h"
#include "util.h"

u8 EWRAM_DATA gUnk_0203D524[0xA] = {0};
i8 EWRAM_DATA gBoolSramWorking = 0;

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
        info.unk_10[i] = 0;

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
