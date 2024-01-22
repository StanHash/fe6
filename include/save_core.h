#pragma once

#include "prelude.h"

#define MAX_CLEARED_PLAYTHROUGHS 12

struct GlobalSaveInfo
{
    /* 00 */ char name[8];
    /* 08 */ u32 magic32;
    /* 0C */ u16 magic16;
    /* 0E */ u16 completed : 1;
    /*    */ u16 completed_hard : 1;
    /*    */ u16 completed_true : 1;
    /*    */ u16 completed_true_hard : 1;
    /*    */ u16 unk_0E_4 : 12;
    /* 10 */ u8 cleared_playthroughs[MAX_CLEARED_PLAYTHROUGHS];
    /* 1C */ u16 checksum;
    /* 1E */ u8 last_game_save_id;
    /* 1F */ u8 last_suspend_slot;
};

// up to checksum offset, aligned to 2 (nearest down)
#define GLOBALSIZEINFO_SIZE_FOR_CHECKSUM (offsetof(struct GlobalSaveInfo, checksum) & ~1)

struct SaveBlockInfo
{
    /* 00 */ u32 magic32;
    /* 04 */ u16 magic16;
    /* 06 */ u8 kind;
    /* 08 */ u16 offset;
    /* 0A */ u16 size;
    /* 0C */ u32 checksum32;
};

void SramInit(void);
bool IsSramWorking(void);
void WipeSram(void);
u16 Checksum16(void const * data, int size);
bool ReadGlobalSaveInfo(struct GlobalSaveInfo * info);
void WriteGlobalSaveInfo(struct GlobalSaveInfo * info);
void WriteGlobalSaveInfoNoChecksum(struct GlobalSaveInfo * info);
void InitGlobalSaveInfo(void);
void * SramOffsetToAddr(u16 off);
u16 SramAddrToOffset(void * addr);
bool ReadSaveBlockInfo(struct SaveBlockInfo * block_info, int save_id);
void WriteSaveBlockInfo(struct SaveBlockInfo * block_info, int save_id);
void * GetSaveWriteAddr(int save_id);
void * GetSaveReadAddr(int save_id);
void WriteChapterFlags(void * sram_dst);
void WritePermanentFlags(void * sram_dst);
void ReadChapterFlags(void const * sram_src);
void ReadPermanentFlags(void const * sram_src);
void WriteSupplyItems(void * sram_dst);
void ReadSupplyItems(void const * sram_src);
bool IsNotFirstPlaythrough(void);
bool func_fe6_08084714(void);
bool IsMultiArenaAvailable(void);
bool IsNotFirstPlaythrough_2(void);
bool CheckHasCompletedSave(void);
