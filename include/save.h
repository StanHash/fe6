#pragma once

#include "common.h"
#include "unit.h"

#define BWL_ARRAY_SIZE 0x46
#define WIN_ARRAY_SIZE 0x20

enum unit_amount_in_savedata {
    UNIT_SAVE_AMOUNT_BLUE = 52,
    UNIT_SAVE_AMOUNT_RED = 50,
    UNIT_SAVE_AMOUNT_GREEN = 10,
};

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

struct SavePackedUnit {       /* Save Data */
    /* 000 */ u32 pid    : 7;
    /* 007 */ u32 jid    : 7;
    /* 014 */ u32 level  : 5;
    /* 019 */ u32 flags  : 6;
    /* 025 */ u32 exp    : 7;
    /* 032 */ u32 x      : 6;
    /* 038 */ u32 y      : 6;
    /* 044 */ u32 max_hp : 6;

    /* 049 */ u32 pow : 5;
    /* 054 */ u32 skl : 5;
    /* 059 */ u32 spd : 5;
    /* 065 */ u32 def : 5;
    /* 070 */ u32 res : 5;
    /* 075 */ u32 lck : 5;
    /* 080 */ u32 con : 5;
    /* 085 */ u32 mov : 5;

    /* 090 */ u32 item0 : 14;
    /* 104 */ u32 item1 : 14;
    /* 118 */ u32 item2 : 14;
    /* 132 */ u32 item3 : 14;
    /* 146 */ u32 item4 : 14;

    /* x14 */ u8 _pad_14[2];

    /* x16 */ u8 wexp[UNIT_WEAPON_EXP_COUNT];
    /* x1E */ u8 supports[UNIT_SUPPORT_COUNT];
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
    /*    */ u32 item_e          : 14;
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
