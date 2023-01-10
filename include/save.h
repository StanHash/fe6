#pragma once

#include "common.h"
#include "unit.h"

#define BWL_ARRAY_SIZE 0x46
#define WIN_ARRAY_SIZE 0x20

struct SramHeader {
    struct GlobalSaveInfo meta;
    struct SaveBlockInfo chunks[SAVE_ID_MAX];
};

/* BWL Table */
struct PidStats {
    /* 000 */ u32 lossAmt     : 8;
    /* 008 */ u32 actAmt      : 8;
    /* 016 */ u32 statViewAmt : 8;
    /* 024 */ u32 deathCh     : 6;
    /* 030 */ u32 deathTurn   : 10;
    /* 040 */ u32 deployAmt   : 6;
    /* 046 */ u32 moveAmt     : 10;
	/* 056 */ u32 deathCause  : 4;
	/* 060 */ u32 expGained   : 12;
	/* 072 */ u32 winAmt      : 10;
	/* 082 */ u32 battleAmt   : 12;
	/* 094 */ u32 killerPid   : 9;
    /* 113 */ u32 _pad_       : 15;
};

struct ChWinData {
    /* 00 */ u16 chapter_index : 0x06;
             u16 chapter_turn  : 0x0A;
             u16 chapter_time  : 0x10;
};

extern u8 gUnk_0203D524[0xA];
extern i8 gBoolSramWorking;
extern u8 *gPidStatsSaveLoc;
extern struct PidStats gPidStatsData[BWL_ARRAY_SIZE];
#define gPidStats (&gPidStatsData[-1])

extern struct ChWinData gChWinData[WIN_ARRAY_SIZE];
extern u8 *gpSramEntry;
extern CONST_DATA char gGlobalSaveInfoName[];

void SramInit();
bool IsSramWorking();
u16 ComputeChecksum16(const u16* data, int size);
bool LoadGlobalSaveInfo(struct GlobalSaveInfo * saveInfo);
bool CkSum32SaveBlockInfo(struct SaveBlockInfo *chunk);
u8 *SramOffsetToPointer(u16 off);
u16 SramPointerToOffset(u8 *addr);
bool LoadAndVerifySaveBlockInfo(struct SaveBlockInfo *chunk, int index);
void WriteAndCkSum32SaveBlockInfo(struct SaveBlockInfo *chunk, int index);
u8 *GetSaveTargetAddress(int index);
u8 *GetSaveSourceAddress(int index);
void GenerateSaveBlockInfoCkSum32(struct SaveBlockInfo *chunk);
bool CheckSaveChunkChapterValid();
bool func_fe6_08086558();
bool CheckSaveChunkChapterValid(int index);
int GetLastSuspendSlotIndex();
bool VerifySaveBlockInfoByIndex(int saveId);
void LoadPlaySt(int saveId, struct PlaySt *out);

struct ChWinData *GetChWinData(int index);
void RegisterChWinData(struct PlaySt *playSt);

void PidStatsAddBattleAmt(struct Unit *unit);
void PidStatsAddWinAmt(u8 pid);

static inline struct PidStats *GetPidStats_(u8 pid)
{
    if (pid >= BWL_ARRAY_SIZE)
        return NULL;
    else if (0 == GetPInfo(pid)->affinity)
        return NULL;
    else
        return &gPidStats[pid];
}