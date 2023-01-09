#pragma once

#include "common.h"

enum
{
    SAVE_ID_GAME0,
    SAVE_ID_GAME1,
    SAVE_ID_GAME2,
    SAVE_ID_SUSPEND0,
    SAVE_ID_SUSPEND1,
};

enum { MAX_SAVED_GAME_CLEARS = 12 };

struct GlobalSaveInfo
{
    /* 00 */ u8 magic[0x8];
    /* 08 */ u32 magic_11217;
    /* 0C */ u16 magic_200A;

    /* 0E */ u8 unk_0E_0 : 1;
    /* 0E */ u8 unk_0E_1 : 1;
    /* 0E */ u8 unk_0E_2 : 1;
    /* 0E */ u8 unk_0E_3 : 1;
    
    /* 0F */ u8 unk0F_0 : 1;
             u8 unk0F_1 : 7;

    /* 10 */ u8 unk_10[MAX_SAVED_GAME_CLEARS];
    /* 1C */ u16 cksum16;
    /* 1E */ u16 unk1E;
};

struct SaveBlockInfo
{
    /* 00 */ u32 magic_a;
    /* 04 */ u16 magic_b;
    /* 06 */ u8 kind;
    /* 08 */ u16 offset;
    /* 0A */ u16 size;
    /* 0C */ u32 checksum32;
};

extern u8 gUnk_0203D524[0xA];
extern i8 gBoolSramWorking;
extern u8 *gUnk_08689DD8; /* gpSaveDataStart */
extern CONST_DATA char gUnk_08327314[]; /* gSaveHeaderKeygen */

void SramInit();
bool IsSramWorking();
u16 ComputeChecksum16(const u16* data, int size);
bool LoadGlobalSaveInfo(struct GlobalSaveInfo * saveInfo);
