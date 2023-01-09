#pragma once

#include "common.h"

struct SramHeader {
    struct GlobalSaveInfo meta;
    struct SaveBlockInfo chunks[SAVE_ID_MAX];
};

extern u8 gUnk_0203D524[0xA];
extern i8 gBoolSramWorking;
extern u8 *gpSramEntry;
extern CONST_DATA char gGlobalSaveInfoName[];

void SramInit();
bool IsSramWorking();
u16 ComputeChecksum16(const u16* data, int size);
bool LoadGlobalSaveInfo(struct GlobalSaveInfo * saveInfo);
bool CkSum32SaveBlockInfo(struct SaveBlockInfo *chunk);
