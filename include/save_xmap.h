#pragma once

#include "prelude.h"
#include "save.h"

#include "gbasram.h"

struct ExtraMapSaveHead
{
    /* 00 */ u32 xmap_magic;
    /* 04 */ u16 xmap_size;
    /* 06 */ u16 xmap_checksum;
    /* 08 */ u32 save_magic32;
    /* 0C */ u32 unused_0C;
    /* 10 */ void const * map_sram;
    /* 14 */ i16 map_size;
    /* 16 */ i16 info_size;
    /* 18 */ void const * info_sram;
};

struct ExtraMapInfo
{
    /* 00 */ struct ChapterInfo const * chapter_info;
    /* 04 */ struct MapChangeInfo const * map_change_info;
    /* 08 */ struct ChapterEventInfo const * event_info;
    /* 0C */ char const * msg_0C;
    /* 10 */ char const * msg_10;
    /* 14 */ char const * msg_14;
    /* 18 */ struct PlaySt * play_st;
    /* 1C */ struct BmSt * bm_st;
    /* 20 */ struct Unit ** active_unit;
    /* 24 */ struct Unit * const * unit_lut;
    /* 28 */ struct BattleUnit * bu_a;
    /* 2C */ struct BattleUnit * bu_b;
    /* 30 */ struct BattleHit * battle_hits;
    /* 34 */ struct Trap * traps;
    /* 38 */ u8 * permanent_flags;
    /* 3C */ u8 * chapter_frags;
};

bool ReadExtraMapSaveHead(void);
void const * GetExtraMapMapReadAddr(void);
u32 GetExtraMapMapSize(void);
void const * GetExtraMapInfoReadAddr(void);
u32 GetExtraMapInfoSize(void);
u16 ExtraMapChecksum(void const * data, int size);
bool IsExtraMapAvailable(void);
void ReadExtraMapInfo(void);
bool ListAvailableTrialChapters(i8 * list_out);
char const * func_fe6_080867F0(int chapter);
char const * func_fe6_080867FC(int chapter);
char const * func_fe6_08086910(int chapter);
void CreateTrialChapterBonusUnits(void);
struct ChapterStats * func_fe6_08086AAC(void);

extern struct ExtraMapInfo * CONST_DATA gExtraMapInfo;

#define XMAP_MAGIC 0x50414D58 // 'XMAP'

#define SRAM_XMAP_SIZE 0x1000u
#define SRAM_XMAP_ADDR (CART_SRAM + CART_SRAM_SIZE - SRAM_XMAP_SIZE)
