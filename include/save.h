#pragma once

#include "common.h"
#include "unit.h"

enum {
    SAVE_ID_GAME0,
    SAVE_ID_GAME1,
    SAVE_ID_GAME2,
    SAVE_ID_SUSPEND0,
    SAVE_ID_SUSPEND1,
    SAVE_ID_5,
    SAVE_ID_6,
    SAVE_ID_MAX
};

#define MAX_SAVED_GAME_CLEARS 12


/**
 * SRAM image header
 */
struct GlobalSaveInfo {
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

struct SaveBlockInfo {
    /* 00 */ u32 magic_a;
    /* 04 */ u16 magic_b;
    /* 06 */ u8 kind;
    /* 08 */ u16 offset;
    /* 0A */ u16 size;
    /* 0C */ u32 checksum32;
};

struct SramHeader {
    struct GlobalSaveInfo meta;
    struct SaveBlockInfo chunks[SAVE_ID_MAX];
};

extern CONST_DATA u8 *gpSramEntry;
extern const char gGlobalSaveInfoName[];


/**
 * Battle-Win-Lose Table
 */
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

#define BWL_ARRAY_SIZE 0x46
extern struct PidStats gPidStatsData[BWL_ARRAY_SIZE];
#define gPidStats (&gPidStatsData[-1])
extern u8 *gPidStatsSaveLoc;

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


/**
 * Chapter Win Data
 */
struct ChWinData {
    u16 chapter_index : 0x06;
    u16 chapter_turn  : 0x0A;
    u16 chapter_time  : 0x10;
};

#define WIN_ARRAY_SIZE 0x20
extern struct ChWinData gChWinData[WIN_ARRAY_SIZE];
struct ChWinData *GetChWinData(int index);
void RegisterChWinData(struct PlaySt *playSt);


/**
 * Packed unit struct in save & suspand data
 */
struct SavePackedUnit {
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

enum packed_unit_state_bits {
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

enum unit_amount_in_savedata {
    UNIT_SAVE_AMOUNT_BLUE = 52,
    UNIT_SAVE_AMOUNT_RED = 50,
    UNIT_SAVE_AMOUNT_GREEN = 10,
};


extern u8 gUnk_0203D524[0xA];
extern i8 gBoolSramWorking;
extern u8 gSuspendSlotIndex;

void SramInit();
bool IsSramWorking();
u16 ComputeChecksum16(const u16* data, int size);
bool LoadGlobalSaveInfo(struct GlobalSaveInfo * saveInfo);
bool CkSum32SaveBlockInfo(struct SaveBlockInfo *chunk);
u8 *SramOffsetToPointer(u16 off);
u16 SramPointerToOffset(u8 *addr);
bool LoadSaveBlockInfo(struct SaveBlockInfo *chunk, int index);
void WriteSaveBlockInfo(struct SaveBlockInfo *chunk, int index);
u8 *GetSaveTargetAddress(int index);
u8 *GetSaveSourceAddress(int index);
void GenerateSaveBlockInfoCkSum32(struct SaveBlockInfo *chunk);
bool func_fe6_08086558();
bool CheckSaveChunkChapterValid(int index);
int GetLastSuspendSlotId();
bool VerifySaveBlockInfoByIndex(int saveId);
void LoadPlaySt(int saveId, struct PlaySt *out);
