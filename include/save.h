#pragma once

#include "common.h"
#include "unit.h"
#include "bm.h"
#include "trap.h"
#include "supply.h"
#include "action.h"
#include "eventinfo.h"

enum
{
    SAVE_ID_GAME0,
    SAVE_ID_GAME1,
    SAVE_ID_GAME2,
    SAVE_ID_SUSPEND0,
    SAVE_ID_SUSPEND1,
    SAVE_ID_5,
    SAVE_ID_6,
    SAVE_ID_MAX
};

enum
{
    BLOCK_INFO_KIND_SAV,
    BLOCK_INFO_KIND_SUS,
    BLOCK_INFO_KIND_2,
    BLOCK_INFO_KIND_3,
    BLOCK_INFO_KIND_INVALID = -1
};

enum
{
    SAVE_MAGICA_COMM = 0x11217,
    SAVE_MAGICA_5    = 0x20112,
    SAVE_MAGICA_6    = 0x20223,

    SAVE_MAGICB_COMM = 0x200A,
};

#define MAX_SAVED_GAME_CLEARS 12


/**
 * SRAM image header
 */
struct GlobalSaveInfo
{
    /* 00 */ char name[0x8];
    /* 08 */ u32 magic_a;
    /* 0C */ u16 magic_b;

    /* 0E */ u32 playedThrough : 1;
             u32 unk_0E_1 : 1;
             u32 unk_0E_2 : 1;
             u32 unk_0E_3 : 1;
             u32 unk_0E_4 : 12;

    /* 10 */ u8 playThrough[MAX_SAVED_GAME_CLEARS];
    /* 1C */ u16 cksum16;
    /* 1E */ u8 slot_sa;
    /* 1F */ u8 slot_su;
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

struct SramHeader
{
    struct GlobalSaveInfo meta;
    struct SaveBlockInfo chunks[SAVE_ID_MAX];
};

extern CONST_DATA u8 * gpSramEntry;
extern const char gGlobalSaveInfoName[];


/**
 * BWL(Battle-Win-Lose) Table
 */
struct PidStats
{
    u32 lossAmt     : 8;
    u32 actAmt      : 8;
    u32 statViewAmt : 8;
    u32 deathCh     : 6;
    u32 deathTurn   : 10;
    u32 deployAmt   : 6;
    u32 moveAmt     : 10;
    u32 deathCause  : 4;
    u32 expGained   : 12;
    u32 winAmt      : 10;
    u32 battleAmt   : 12;
    u32 killerPid   : 9;
    u32 _pad_       : 15;
};

#define BWL_ARRAY_SIZE 0x46
extern struct PidStats gPidStatsData[BWL_ARRAY_SIZE];
#define gPidStats (&gPidStatsData[-1])
extern u8 * gPidStatsSaveLoc;

void PidStatsAddBattleAmt(struct Unit * unit);
void PidStatsAddWinAmt(u8 pid);
void PidStatsRecordLoseData(u8 pid);
void PidStatsRecordDeathData(u8 pid, u8 killerPid, int deathCause);
void PidStatsAddActAmt(u8 pid);
void PidStatsAddStatViewAmt(u8 pid);
void PidStatsAddDeployAmt(u8 pid);
void PidStatsAddSquaresMoved(u8 pid, int amount);
void PidStatsAddExpGained(u8 pid, int amount);
int PidStatsGetTotalBattleAmt();
int PidStatsGetTotalWinAmt();
int PidStatsGetTotalLossAmt();
int PidStatsGetTotalLevel();
void PidStatsRecordBattleRes(void);
struct PidStats * GetPidStats(u8 pid);


/**
 * Chapter Win Data
 */
struct ChWinData
{
    u16 chapter_index : 0x06;
    u16 chapter_turn  : 0x0A;
    u16 chapter_time  : 0x10;
};

#define WIN_ARRAY_SIZE 0x20
extern struct ChWinData gChWinData[WIN_ARRAY_SIZE];

struct ChWinData *GetChWinData(int index);
bool IsWinDataValid(struct ChWinData * winData);
int GetFreeChWinDataIndex();
void RegisterChWinData(struct PlaySt * playSt);


/**
 * Packed unit struct in save & suspand data
 */
struct SavePackedUnit
{
    u32 pid    : 7;
    u32 jid    : 7;
    u32 level  : 5;
    u32 flags  : 6;
    u32 exp    : 7;
    u32 x      : 6;
    u32 y      : 6;
    u32 max_hp : 6;

    u32 pow : 5;
    u32 skl : 5;
    u32 spd : 5;
    u32 def : 5;
    u32 res : 5;
    u32 lck : 5;
    u32 con : 5;
    u32 mov : 5;

    u32 item0 : 14;
    u32 item1 : 14;
    u32 item2 : 14;
    u32 item3 : 14;
    u32 item4 : 14;

    u8 _pad_14[2];

    u8 wexp[UNIT_WEAPON_EXP_COUNT];
    u8 supports[UNIT_SUPPORT_COUNT];
};

enum packed_unit_state_bits
{
    PACKED_US_DEAD       = 1 << 0,
    PACKED_US_UNDEPLOYED = 1 << 1,
    PACKED_US_SOLO_ANIM1 = 1 << 2,
    PACKED_US_SOLO_ANIM2 = 1 << 3,
    PACKED_US_METIS_TOME = 1 << 4,
    PACKED_US_B4         = 1 << 5,
    PACKED_US_B5         = 1 << 6,
    PACKED_US_NEW_FRIEND = 1 << 7,
};

struct SuspendPackedUnit
{
    /* 00 */ u8 pid;
    /* 01 */ u8 jid;
    /* 02 */ u8 ai_a;
    /* 03 */ u8 rescue;
    /* 04 */ u16 flags;
    /* 06 */ u16 item_a;
    /* 08 */ u16 item_b;
    /* 0A */ u16 item_c;
    /* 0C */ u8 max_hp;
    /* 0D */ u8 hp;
    /* 0E */ u8 exp;
    /* 0F */ u8 ai_flags;
    /* 10 */ u8 wexp[UNIT_WEAPON_EXP_COUNT];
    /* 18 */ u8 supports[UNIT_SUPPORT_COUNT];
    /* 22 */ u8 ai_a_pc;
    /* 23 */ u8 ai_b;
    /* 24 */ u16 ai_config;
    /* 26 */ u8 ai_b_pc;
    /* 27 */ u8 unit_unk_46;
    /* 28 */ u32 level           : 5;
    /*    */ u32 x               : 6;
    /*    */ u32 y               : 6;
    /*    */ u32 pow             : 5;
    /*    */ u32 skl             : 5;
    /*    */ u32 spd             : 5;
    /* 2C */ u32 def             : 5;
    /*    */ u32 res             : 5;
    /*    */ u32 lck             : 5;
    /*    */ u32 bonus_con       : 5;
    /*    */ u32 status          : 3;
    /*    */ u32 status_duration : 3;
    /*    */ u32 torch           : 3;
    /*    */ u32 barrier         : 3;
    /* 30 */ u32 bonus_mov       : 4;
    /*    */ u32 item_d          : 14;
    /*    */ u16 item_e          : 14;
};

enum unit_amount_in_savedata
{
    UNIT_SAVE_AMOUNT_BLUE = 52,
    UNIT_SAVE_AMOUNT_RED = 50,
    UNIT_SAVE_AMOUNT_GREEN = 10,
};


/**
 * Save data memory maps
 */
enum SaveDataSizes
{
    SAV_SIZE_PLAYST     = sizeof(struct PlaySt),
    SAV_SIZE_UNIT       = UNIT_SAVE_AMOUNT_BLUE * sizeof(struct SavePackedUnit),
    SAV_SIZE_SUPPLY     = SUPPLY_ITEM_COUNT * sizeof(u16),
    SAV_SIZE_PIDSTATS   = sizeof(gPidStatsData),
    SAV_SIZE_CHWIN      = sizeof(gChWinData),
    SAV_SIZE_PERMFLAG   = sizeof(gPermanentFlagBits) + 3 /* align 2 */,
};

enum SaveDataMemoryMap
{
    SAV_MEMMAP_START    = 0,
    SAV_MEMMAP_PLAYST   = SAV_MEMMAP_START,
    SAV_MEMMAP_UNIT     = SAV_MEMMAP_PLAYST   + SAV_SIZE_PLAYST,
    SAV_MEMMAP_SUPPLY   = SAV_MEMMAP_UNIT     + SAV_SIZE_UNIT,
    SAV_MEMMAP_PIDSTATS = SAV_MEMMAP_SUPPLY   + SAV_SIZE_SUPPLY,
    SAV_MEMMAP_CHWIN    = SAV_MEMMAP_PIDSTATS + SAV_SIZE_PIDSTATS,
    SAV_MEMMAP_PERMFLAG = SAV_MEMMAP_CHWIN    + SAV_SIZE_CHWIN,
    
    SAV_MEMMAP_RSV      = SAV_MEMMAP_PERMFLAG + SAV_SIZE_PERMFLAG,
    SAV_MEMMAP_MAX      = SAV_MEMMAP_RSV
};

enum SuspandDataSizes
{
    SUS_SIZE_PLAYST     = sizeof(struct PlaySt),
    SUS_SIZE_ACTION     = sizeof(struct Action),
    SUS_SIZE_UNIT_B     = (UNIT_SAVE_AMOUNT_BLUE) * sizeof(struct SuspendPackedUnit),
    SUS_SIZE_UNIT_R     = (UNIT_SAVE_AMOUNT_RED) * sizeof(struct SuspendPackedUnit),
    SUS_SIZE_UNIT_G     = (UNIT_SAVE_AMOUNT_GREEN) * sizeof(struct SuspendPackedUnit),
    SUS_SIZE_TRAP       = TRAP_MAX_COUNT * sizeof(struct Trap),
    SUS_SIZE_SUPPLY     = SUPPLY_ITEM_COUNT * sizeof(u16),
    SUS_SIZE_PIDSTATS   = sizeof(gPidStatsData),
    SUS_SIZE_CHWIN      = sizeof(gChWinData),
    SUS_SIZE_PERMFLAG   = sizeof(gPermanentFlagBits),
    SUS_SIZE_TEMPFLAG   = sizeof(gChapterFlagBits) + 3 /* align 2 */,
};

enum SuspandDataMemoryMap
{
    SUS_MEMMAP_START    = 0,
    SUS_MEMMAP_PLAYST   = SUS_MEMMAP_START,
    SUS_MEMMAP_ACTION   = SUS_MEMMAP_PLAYST   + SUS_SIZE_PLAYST,
    SUS_MEMMAP_UNIT_B   = SUS_MEMMAP_ACTION   + SUS_SIZE_ACTION,
    SUS_MEMMAP_UNIT_R   = SUS_MEMMAP_UNIT_B   + SUS_SIZE_UNIT_B,
    SUS_MEMMAP_UNIT_G   = SUS_MEMMAP_UNIT_R   + SUS_SIZE_UNIT_R,
    SUS_MEMMAP_TRAP     = SUS_MEMMAP_UNIT_G   + SUS_SIZE_UNIT_G,
    SUS_MEMMAP_SUPPLY   = SUS_MEMMAP_TRAP     + SUS_SIZE_TRAP,
    SUS_MEMMAP_PIDSTATS = SUS_MEMMAP_SUPPLY   + SUS_SIZE_SUPPLY,
    SUS_MEMMAP_CHWIN    = SUS_MEMMAP_PIDSTATS + SUS_SIZE_PIDSTATS,
    SUS_MEMMAP_PERMFLAG = SUS_MEMMAP_CHWIN    + SUS_SIZE_CHWIN,
    SUS_MEMMAP_TEMPFLAG = SUS_MEMMAP_PERMFLAG + SUS_SIZE_PERMFLAG,

    SUS_MEMMAP_RSV      = SUS_MEMMAP_TEMPFLAG + SUS_SIZE_TEMPFLAG,
    SUS_MEMMAP_MAX      = SUS_MEMMAP_RSV
};

enum SramDataSizes
{
    SRAM_SIZE_HEADER = sizeof(struct SramHeader),
    SRAM_SIZE_SUS0   = SUS_MEMMAP_MAX,
    SRAM_SIZE_SUS1   = SUS_MEMMAP_MAX,
    SRAM_SIZE_SAV0   = SAV_MEMMAP_MAX,
    SRAM_SIZE_SAV1   = SAV_MEMMAP_MAX,
    SRAM_SIZE_SAV2   = SAV_MEMMAP_MAX,
};

enum SramMemoryMap
{
    SRAM_MEMMAP_START  = 0,
    SRAM_MEMMAP_HEADER = SRAM_MEMMAP_START,
    SRAM_MEMMAP_SUS0   = SRAM_MEMMAP_HEADER + SRAM_SIZE_HEADER,
    SRAM_MEMMAP_SUS1   = SRAM_MEMMAP_SUS0   + SRAM_SIZE_SUS0,
    SRAM_MEMMAP_SAV0   = SRAM_MEMMAP_SUS1   + SRAM_SIZE_SUS1,
    SRAM_MEMMAP_SAV1   = SRAM_MEMMAP_SAV0   + SRAM_SIZE_SAV0,
    SRAM_MEMMAP_SAV2   = SRAM_MEMMAP_SAV1   + SRAM_SIZE_SAV1,
    SRAM_MEMMAP_5      = SRAM_MEMMAP_SAV2   + SRAM_SIZE_SAV2,
};


/**
 * Misc
 */
extern u8 gUnk_0203D524[0xA];
extern i8 gBoolSramWorking;
extern u8 gSuspendSlotIndex;

void SramInit();
bool IsSramWorking(void);
void EraseSaveData();
u16 ComputeChecksum16(const u16 * data, int size);
bool LoadGlobalSaveInfo(struct GlobalSaveInfo * saveInfo);
void SaveGlobalSaveInfo(struct GlobalSaveInfo * saveInfo);
void SaveGlobalSaveInfoNoChecksum(struct GlobalSaveInfo * saveInfo);
void InitGlobalSaveInfo();
u8 * SramOffsetToPointer(u16 off);
u16 SramPointerToOffset(u8 * addr);
bool LoadAndVerifySaveBlockInfo(struct SaveBlockInfo * blockInfo, int id);
void WriteSaveBlockInfo(struct SaveBlockInfo * chunk, int index);
u8 * GetSaveTargetAddress(int index);
u8 * GetSaveSourceAddress(int index);
void SaveChapterFlagBits(u8 * sram_dst);
void SavePermanentFlagBits(u8 * sram_dst);
void LoadChapterFlagBits(u8 * sram_src);
void LoadPermanentFlagBits(u8 * sram_src);
void SaveSupplyItems(u8 * sram_dst);
void LoadSupplyItems(u8 * sram_src);
bool IsGamePlayThroughed(void);
bool func_fe6_08084714();
bool func_fe6_08084718();
bool IsGamePlayThroughed_();
bool CheckHasCompletedSave();
void ClearPidChStatsSaveData(u8 * sram_dst);
void ClearPidStats(void);
void LoadPidStats(u8 * sram_src);
void LoadChWinData(u8 * sram_src);
void SavePidStats(u8 * sram_dst);
void SaveChWinData(u8 * sram_dst);
bool IsPlaythroughIdUnique(int index);
int GetNewPlaythroughId();
int GetGlobalCompletedPlaythroughCount(void);
bool RegisterCompletedPlaythrough(struct GlobalSaveInfo * saveInfo, int id);
void SavePlayThroughData(void);
// func_fe6_08084F48
void UpdateLastUsedGameSaveSlot(int slot_sa);
int GetLastUsedGameSaveSlot(void);
// func_fe6_08084FB8
void CopyGameSave(int index_src, int index_dst);
void SaveNewGame(int saveId, int isHard);
void SaveGame(int slot);
void LoadGame(int slot);
bool VerifySaveBlockInfoByIndex(int saveId);
void LoadPlaySt(int saveId, struct PlaySt * out);
bool CheckSaveChunkChapterValid(int index);
void SaveUnit(struct Unit * unit, void * sram_dst);
void LoadUnit(u8 * sram_src, struct Unit * unit);
void ResetSaveBlockInfo(int saveId);
void SaveSuspendedGame(int saveId);
void LoadSuspendedGame(int saveId);
bool AdvanceSuspendSaveDataSlotId(int saveId);
void LoadPlayStByGlobalSusIndex(int saveId, struct PlaySt * playSt);
void PackUnitForSuspend(struct Unit * unit, u8 * buf);
void LoadUnitFormSuspend(u8 * sram_src, struct Unit * unit);
void SaveTraps(u8 * sram_dest);
void LoadTraps(u8 * sram_dest);
int GetLastSuspendSaveId();
int GetNextSuspendSaveId();
void ChangeSuspendSaveId();
int GetCkSum32ViaGenericBuf(void * sram_src, int size);
bool CkSum32SaveBlockInfo(struct SaveBlockInfo * chunk);
void GenerateSaveBlockInfoCkSum32(struct SaveBlockInfo * chunk);
u16 ComputeSaveDataCkSum32();
