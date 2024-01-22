#pragma once

#include "prelude.h"
#include "save.h"

#include "unit.h"
#include "bm.h"
#include "trap.h"
#include "supply.h"
#include "action.h"
#include "eventinfo.h"
#include "save_stats.h"

enum
{
    UNIT_SAVE_AMOUNT_BLUE = 52,
    UNIT_SAVE_AMOUNT_RED = 50,
    UNIT_SAVE_AMOUNT_GREEN = 10,
};

enum
{
    // flags for GameSavePackedUnit::flags

    SAVEUNIT_FLAG_DEAD       = 1 << 0,
    SAVEUNIT_FLAG_UNDEPLOYED = 1 << 1,
    SAVEUNIT_FLAG_SOLOANIM1  = 1 << 2,
    SAVEUNIT_FLAG_SOLOANIM2  = 1 << 3,
};

struct GameSavePackedUnit
{
    /* 00 */ u32 pid    : 7;
    /*    */ u32 jid    : 7;
    /*    */ u32 level  : 5;
    /*    */ u32 flags  : 6;
    /*    */ u32 exp    : 7;
    /* 04 */ u32 x      : 6;
    /*    */ u32 y      : 6;
    /*    */ u32 max_hp : 6;
    /*    */ u32 pow    : 5;
    /*    */ u32 skl    : 5;
    /*    */ u32 spd    : 5;
    /*    */ u32 def    : 5;
    /*    */ u32 res    : 5;
    /*    */ u32 lck    : 5;
    /*    */ u32 con    : 5;
    /*    */ u32 mov    : 5;
    /*    */ u32 item_a : 14;
    /*    */ u32 item_b : 14;
    /*    */ u32 item_c : 14;
    /*    */ u32 item_d : 14;
    /*    */ u32 item_e : 14;
    /* 14 */ u8 unused_14[2];
    /* 16 */ u8 wexp[UNIT_WEAPON_EXP_COUNT];
    /* 1E */ u8 supports[UNIT_SUPPORT_COUNT];
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
    /* 27 */ u8 ai_counter;
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
    /*    */ u16 item_d          : 14;
    /*    */ u16 item_e          : 14;
};

struct GameSaveBlock
{
    struct PlaySt play_st;
    struct GameSavePackedUnit units[UNIT_SAVE_AMOUNT_BLUE];
    u16 supply_items[SUPPLY_ITEM_COUNT];
    struct PidStats pid_stats[PID_STATS_COUNT];
    struct ChapterStats chapter_stats[CHAPTER_STATS_COUNT];
    u8 permanent_flags[sizeof(gPermanentFlagBits)];
};

struct SuspendSaveBlock
{
    struct PlaySt play_st;
    struct Action action;
    struct SuspendSavePackedUnit units[UNIT_SAVE_AMOUNT_BLUE + UNIT_SAVE_AMOUNT_RED + UNIT_SAVE_AMOUNT_GREEN];
    struct Trap traps[TRAP_MAX_COUNT];
    u16 supply_items[SUPPLY_ITEM_COUNT];
    struct PidStats pid_stats[PID_STATS_COUNT];
    struct ChapterStats chapter_stats[CHAPTER_STATS_COUNT];
    u8 permanent_flags[sizeof(gPermanentFlagBits)];
    u8 chapter_flags[sizeof(gChapterFlagBits)];
};

void WriteLastGameSaveId(int save_id);
int ReadLastGameSaveId(void);
void InvalidateGameSave(int save_id);
void CopyGameSave(int src_save_id, int dst_save_id);
void WriteNewGameSave(int save_id, int is_hard);
void WriteGameSave(int save_id);
void ReadGameSave(int save_id);
bool IsSaveValid(int save_id);
void ReadGameSavePlaySt(int save_id, struct PlaySt * play_st);
bool IsGameSavePastFirstChapter(int save_id);
void WriteGameSavePackedUnit(struct Unit * unit, void * sram_dst);
void ReadGameSavePackedUnit(void const * sram_src, struct Unit * unit);
void InvalidateSuspendSave(int save_id);
void WriteSuspendSave(int save_id);
void ReadSuspendSave(int save_id);
bool IsValidSuspendSave(int save_id);
void ReadSuspendSavePlaySt(int save_id, struct PlaySt * buf);
void EncodeSuspendSavePackedUnit(struct Unit * unit, void * buf);
void ReadSuspendSavePackedUnit(void const * sram_src, struct Unit * unit);
void WriteTraps(void * sram_dst);
void ReadTraps(void const * sram_src);
int GetLastSuspendSaveId(void);
int GetNextSuspendSaveId(void);
void WriteSwappedSuspendSaveId(void);
int SramChecksum32(void const * sram_src, int size);
bool VerifySaveBlockChecksum(struct SaveBlockInfo * block_info);
void PopulateSaveBlockChecksum(struct SaveBlockInfo * block_info);
u16 GetGameStateChecksum_Unused(void);
void func_fe6_08086088(void);
