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
    SAVE_ID_SUSPEND,
    SAVE_ID_SUSPEND_ALT,
    SAVE_ID_5,
    SAVE_ID_6,
    SAVE_ID_MAX,
};

enum
{
    SAVEBLOCK_KIND_GAME,
    SAVEBLOCK_KIND_SUSPEND,
    SAVEBLOCK_KIND_2,
    SAVEBLOCK_KIND_3,
    SAVEBLOCK_KIND_INVALID = -1
};

enum
{
    SAVEMAGIC32      = 0x11217,
    SAVEMAGIC32_UNK5 = 0x20112,
    SAVEMAGIC32_UNK6 = 0x20223,

    SAVEMAGIC16 = 0x200A,
};

#define MAX_SAVED_GAME_CLEARS 12

/**
 * SRAM image header
 */
struct GlobalSaveInfo
{
    /* 00 */ char name[8];
    /* 08 */ u32 magic32;
    /* 0C */ u16 magic16;
    /* 0E */ u32 completed : 1;
    /*    */ u32 completed_hard : 1;
    /*    */ u32 completed_true : 1;
    /*    */ u32 completed_true_hard : 1;
    /*    */ u32 unk_0E_4 : 12;
    /* 10 */ u8 cleared_playthroughs[MAX_SAVED_GAME_CLEARS];
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

extern CONST_DATA u8 * gSram;
extern const char gGlobalSaveInfoName[];

enum
{
    DEFEAT_CAUSE_0,
    DEFEAT_CAUSE_1,
    DEFEAT_CAUSE_COMBAT,
    DEFEAT_CAUSE_TRAP,
    DEFEAT_CAUSE_POISON,
    DEFEAT_CAUSE_5,
    DEFEAT_CAUSE_6, // I think this is arena death but needs confirm
};

/**
 * BWL(Battle-Win-Lose) Table
 */
struct PidStats
{
    u32 loss_count      : 8;
    u32 act_count       : 8;
    u32 stat_view_count : 8;
    u32 defeat_chapter  : 6;
    u32 defeat_turn     : 10;
    u32 deploy_count    : 6;
    u32 move_count      : 10;
    u32 defeat_cause    : 4;
    u32 exp_gained      : 12;
    u32 win_count       : 10;
    u32 battle_count    : 12;
    u32 killer_pid      : 9;
    u32 _pad_       : 15; // unused
};

#define BWL_ARRAY_SIZE 0x46
extern struct PidStats gPidStatsData[BWL_ARRAY_SIZE];
extern void * gPidStatsSaveLoc;

void PidStatsAddBattleAmt(struct Unit * unit);
void PidStatsAddWinAmt(fu8 pid);
void PidStatsRecordLoseData(fu8 pid);
void PidStatsRecordDefeatInfo(fu8 pid, fu8 killer_pid, int defeat_cause);
void PidStatsAddActAmt(fu8 pid);
void PidStatsAddStatViewAmt(fu8 pid);
void PidStatsAddDeployAmt(fu8 pid);
void PidStatsAddSquaresMoved(fu8 pid, int amount);
void PidStatsAddExpGained(fu8 pid, int amount);
int PidStatsGetTotalBattleAmt(void);
int PidStatsGetTotalWinAmt(void);
int PidStatsGetTotalLossAmt(void);
int PidStatsGetTotalLevel(void);
void PidStatsRecordBattleRes(void);
struct PidStats * GetPidStats(fu8 pid);

/**
 * Chapter Win Data
 */
struct ChapterStats
{
    u16 chapter_id   : 6;
    u16 chapter_turn : 10;
    u16 chapter_time : 16; // in increments of 3 seconds
};

#define WIN_ARRAY_SIZE 0x20
extern struct ChapterStats gChapterStats[WIN_ARRAY_SIZE];

struct ChapterStats * GetChapterStats(int index);
bool IsWinDataValid(struct ChapterStats * chapter_stats);
int GetNextChapterStatsSlot(void);
void RegisterChapterStats(struct PlaySt * play_st);


/**
 * Packed unit struct in save & suspand data
 */
struct GameSavePackedUnit
{
    /* 00 */ u32 pid    : 7;
    /*    */ u32 jid    : 7;
    u32 level  : 5;
    u32 flags  : 6;
    u32 exp    : 7;
    u32 x      : 6;
    u32 y      : 6;
    u32 max_hp : 6;
    u32 pow    : 5;
    u32 skl    : 5;
    u32 spd    : 5;
    u32 def    : 5;
    u32 res    : 5;
    u32 lck    : 5;
    u32 con    : 5;
    u32 mov    : 5;
    u32 item_a : 14;
    u32 item_b : 14;
    u32 item_c : 14;
    u32 item_d : 14;
    u32 item_e : 14;
    u8 pad_14[2];
    u8 wexp[UNIT_WEAPON_EXP_COUNT];
    u8 supports[UNIT_SUPPORT_COUNT];
};

enum
{
    // flags for GameSavePackedUnit::flags

    SAVEUNIT_FLAG_DEAD       = 1 << 0,
    SAVEUNIT_FLAG_UNDEPLOYED = 1 << 1,
    SAVEUNIT_FLAG_SOLOANIM1  = 1 << 2,
    SAVEUNIT_FLAG_SOLOANIM2  = 1 << 3,
};

struct SuspendSavePackedUnit
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

// TODO: this probably doesn't belong here
extern u8 gUnk_0203D524[0xA];

extern i8 gIsSramWorking;
extern u8 gSuspendSaveIdOffset;

void SramInit(void);
bool IsSramWorking(void);
void WipeSram(void);
u16 Checksum16(void const * data, int size);
bool ReadGlobalSaveInfo(struct GlobalSaveInfo * saveInfo);
void WriteGlobalSaveInfo(struct GlobalSaveInfo * saveInfo);
void WriteGlobalSaveInfoNoChecksum(struct GlobalSaveInfo * saveInfo);
void InitGlobalSaveInfo(void);
void * SramOffsetToAddr(u16 off);
u16 SramAddrToOffset(void * addr);
bool ReadSaveBlockInfo(struct SaveBlockInfo * blockInfo, int id);
void WriteSaveBlockInfo(struct SaveBlockInfo * chunk, int index);
void * GetSaveWriteAddr(int index);
void * GetSaveReadAddr(int index);
void WriteChapterFlags(void * sram_dst);
void WritePermanentFlags(void * sram_dst);
void ReadChapterFlags(void const * sram_src);
void ReadPermanentFlags(void const * sram_src);
void WriteSupplyItems(void * sram_dst);
void ReadSupplyItems(void const * sram_src);
bool IsNotFirstPlaythrough(void);
bool func_fe6_08084714(void);
bool func_fe6_08084718(void);
bool IsNotFirstPlaythrough_2(void);
bool CheckHasCompletedSave(void);
void ClearPidChStatsSaveData(void * sram_dst);
void ClearPidStats(void);
void ReadPidStats(void * sram_src);
void ReadChapterStats(void const * sram_src);
void WritePidStats(void * sram_dst);
void WriteChapterStats(void * sram_dst);
bool IsPlaythroughIdUnique(int index);
int GetNewPlaythroughId(void);
int GetGlobalCompletedPlaythroughCount(void);
bool RegisterCompletedPlaythrough(struct GlobalSaveInfo * saveInfo, int id);
void SavePlayThroughData(void);
// func_fe6_08084F48
void WriteLastGameSaveId(int save_id);
int ReadLastGameSaveId(void);
// InvalidateGameSave
void CopyGameSave(int index_src, int index_dst);
void WriteNewGameSave(int save_id, int is_hard);
void WriteGameSave(int save_id);
void ReadGameSave(int save_id);
bool IsSaveValid(int save_id);
void ReadGameSavePlaySt(int save_id, struct PlaySt * out);
bool IsGameSavePastFirstChapter(int index);
void WriteGameSavePackedUnit(struct Unit * unit, void * sram_dst);
void ReadGameSavePackedUnit(void const * sram_src, struct Unit * unit);
void InvalidateSuspendSave(int save_id);
void WriteSuspendSave(int save_id);
void ReadSuspendSave(int save_id);
bool IsValidSuspendSave(int save_id);
void ReadSuspendSavePlaySt(int save_id, struct PlaySt * play_st);
void EncodeSuspendSavePackedUnit(struct Unit * unit, void * buf);
void ReadSuspendSavePackedUnit(void const * sram_src, struct Unit * unit);
void WriteTraps(void * sram_dst);
void ReadTraps(void const * sram_src);
int GetLastSuspendSaveId(void);
int GetNextSuspendSaveId(void);
void WriteSwappedSuspendSaveId(void);
int SramChecksum32(void const * sram_src, int size);
bool VerifySaveBlockChecksum(struct SaveBlockInfo * chunk);
void PopulateSaveBlockChecksum(struct SaveBlockInfo * chunk);
u16 GetGameStateChecksum_Unused(void);
