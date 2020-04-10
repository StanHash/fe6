
#pragma once

#include "gba/gba.h"

typedef s8 Bool;
typedef void(*Func)(void);

struct Vec2
{
    short x, y;
};

struct Vec2u
{
    u16 x, y;
};

// TODO: move

enum
{
    ITEM_KIND_SWORD,
    ITEM_KIND_LANCE,
    ITEM_KIND_AXE,
    ITEM_KIND_BOW,
    ITEM_KIND_STAFF,
    ITEM_KIND_ANIMA,
    ITEM_KIND_LIGHT,
    ITEM_KIND_ELDER,

    // TODO: more
};

enum
{
    GAME_ACTION_1 = 1,
    GAME_ACTION_2,
};

enum
{
    BM_FLAG_0 = (1 << 0),
    BM_FLAG_1 = (1 << 1),
    BM_FLAG_2 = (1 << 2),
    BM_FLAG_3 = (1 << 3),
};

struct BmSt
{
    /* 00 */ s8 mainLoopEnded;
    /* 01 */ u8 lock;
    /* 02 */ u8 lockDisplay;
    /* 03 */ u8 pad03;
    /* 04 */ u8 flags;
    /* 05 */ // pad
    /* 06 */ u16 unk06;
    /* 08 */ int pad08;
    /* 0C */ struct Vec2 camera;
    /* 10 */ struct Vec2 cameraPrevious;
    /* 14 */ struct Vec2 cursor;
    /* 18 */ struct Vec2 unk18;
    /* 1C */ struct Vec2 unk1C;
    /* 20 */ struct Vec2 cursorSpr;
    /* 24 */ struct Vec2u unk24;
    /* 28 */ struct Vec2 unk28; 
};

enum
{
    PLAY_FLAG_0    = (1 << 0),
    PLAY_FLAG_1    = (1 << 1),
    PLAY_FLAG_2    = (1 << 2),
    PLAY_FLAG_3    = (1 << 3),
    PLAY_FLAG_4    = (1 << 4),
    PLAY_FLAG_5    = (1 << 5),
    PLAY_FLAG_HARD = (1 << 6),
    PLAY_FLAG_7    = (1 << 7),
};

enum
{
    FACTION_BLUE   = 0x00,
    FACTION_RED    = 0x80,
    FACTION_GREEN  = 0x40,
    FACTION_PURPLE = 0xC0,
};

enum
{
    FACTION_ID_BLUE = 0,
    FACTION_ID_GREEN = 1,
    FACTION_ID_RED = 2,
    FACTION_ID_PURPLE = 3,
};

enum
{
    WEATHER_NONE,
};

struct PlaySt
{
    /* 00 */ u32 unk00; // a time value
    /* 04 */ u32 unk04; // a time value

    /* 08 */ u32 gold;
    /* 0C */ u8 saveSlot;
    /* 0D */ u8 vision; // 0 means no fog
    /* 0E */ s8 chapter;
    /* 0F */ u8 faction;
    /* 10 */ u16 turn;
    /* 12 */ u8 xCursor, yCursor; // map cursor position
    /* 14 */ u8 flags; // +0x04 = postgame, +0x10 = in prep screen, +0x40 = difficult mode, +0x80 = link arena?
    /* 15 */ u8 weather;
    /* 16 */ u16 supportGain;
    /* 18 */ u8 playId;
    /* 19 */ u8 unk19;
    /* 1A */ u8 lastSortId;
    /* 1B */ u8 unk1B;

    // option bits
    u32 unk1C_1:1; // 1
    u32 unk1C_2:1; // 1
    u32 unk1C_3:2; // 2
    u32 unk1C_5:1; // 1
    u32 cfgTextSpeed:2;
    u32 unk1C_8:1; // 1
    u32 cfgBgmDisable:1; // 1
    u32 cfgSeDisable:1; // 1
    u32 cfgWindowColor:2;
    u32 unk1D_5:1; // 1
    u32 unk1D_6:1; // unk
    u32 unk1D_7:1; // 1
    u32 unk1D_8:1; // 1
    u32 unk1E_1:1; // unk
    u32 unk1E_2:2; // 2
    u32 unk1E_4:2; // 2
    u32 unk1E_6:1; // 1
    u32 unk1E_7:1; // unk
    u32 unk1E_8:2; // 2 (!)
    u32 unk1F_2:2; // 2
    u32 unk1F_4:5; // unk
};

struct PersonInfo
{
    /* 00 */ u16 msgName;
    /* 02 */ u16 msgDesc;
    /* 04 */ u8 id;
    /* 05 */ u8 jidDefault;
    /* 06 */ u16 fid;
    /* 08 */ u8 chibiId;
    /* 09 */ u8 affinity;
    /* 0A */ u8 unk0A;

    /* 0B */ s8 levelBase;
    /* 0C */ s8 hpBase;
    /* 0D */ s8 powBase;
    /* 0E */ s8 sklBase;
    /* 0F */ s8 spdBase;
    /* 10 */ s8 defBase;
    /* 11 */ s8 resBase;
    /* 12 */ s8 lckBase;
    /* 13 */ s8 conBonus;

    /* 14 */ u8 weaponExp[8];

    /* 1C */ u8 hpGrowth;
    /* 1D */ u8 powGrowth;
    /* 1E */ u8 sklGrowth;
    /* 1F */ u8 spdGrowth;
    /* 20 */ u8 defGrowth;
    /* 21 */ u8 resGrowth;
    /* 22 */ u8 lckGrowth;

    /* 23 */ u8 banimPalA;
    /* 24 */ u8 banimPalB;
    /* 25 */ // pad

    /* 28 */ u32 attributes;

    /* 2C */ void const* supportInfo;
};

struct JobInfo
{
    /* 00 */ u16 msgName;
    /* 02 */ u16 msgDesc;
    /* 04 */ u8 id;
    /* 05 */ u8 jidPromote;
    /* 06 */ u8 sms;
    /* 07 */ u8 walkSpeed;
    /* 08 */ u16 fid;
    /* 0A */ u8 unk0A;

    /* 0B */ s8 hpBase;
    /* 0C */ s8 powBase;
    /* 0D */ s8 sklBase;
    /* 0E */ s8 spdBase;
    /* 0F */ s8 defBase;
    /* 10 */ s8 resBase;
    /* 11 */ s8 conBase;
    /* 12 */ s8 movBase;

    /* 13 */ s8 hpMax;
    /* 14 */ s8 powMax;
    /* 15 */ s8 sklMax;
    /* 16 */ s8 spdMax;
    /* 17 */ s8 defMax;
    /* 18 */ s8 resMax;
    /* 19 */ s8 conMax;

    /* 1A */ s8 powerLevel;

    /* 1B */ s8 growthHP;
    /* 1C */ s8 growthPow;
    /* 1D */ s8 growthSkl;
    /* 1E */ s8 growthSpd;
    /* 1F */ s8 growthDef;
    /* 20 */ s8 growthRes;
    /* 21 */ s8 growthLck;
    /* 22 */ // pad

    /* 24 */ u32 attributes;

    /* 28 */ u8 weaponExp[8];

    /* 30 */ void const* banimInfo;

    /* 34 */ s8 const* movTerrainTable;
    /* 38 */ s8 const* avoTerrainTable;
    /* 3C */ s8 const* defTerrainTable;
    /* 40 */ s8 const* resTerrainTable;

    /* 44 */ void const* unk44;
};

enum
{
    US_HIDDEN       = (1 << 0),
    US_UNSELECTABLE = (1 << 1),
    US_DEAD         = (1 << 2),
    US_NOT_DEPLOYED = (1 << 3),
    US_RESCUING     = (1 << 4),
    US_RESCUED      = (1 << 5),
    US_HAS_MOVED    = (1 << 6), // Bad name?
    US_UNDER_A_ROOF = (1 << 7),
    US_BIT8         = (1 << 8), // has been seen?
    US_BIT9         = (1 << 9), // hidden by fog?
    US_HAS_MOVED_AI = (1 << 10),
};

struct Unit
{
    /* 00 */ struct PersonInfo const* person;
    /* 04 */ struct JobInfo const* job;

    /* 08 */ s8 level;
    /* 09 */ u8 exp;
    /* 0A */ u8 aiFlags;
    /* 0B */ s8 id;

    /* 0C */ u16 state;

    /* 0E */ s8 x;
    /* 0F */ s8 y;

    /* 10 */ s8 hpMax;
    /* 11 */ s8 hpCur;
    /* 12 */ s8 pow;
    /* 13 */ s8 skl;
    /* 14 */ s8 spd;
    /* 15 */ s8 def;
    /* 16 */ s8 res;
    /* 17 */ s8 lck;

    /* 18 */ // TODO: more
    /* -- */ u8 pad18[0x1C - 0x18];

    /* 1C */ u16 items[5];

    /* 26 */ u8 pad26[0x42 - 0x26];

    /* 42 */ u8 aiA;
    /* 43 */ u8 aiApc;
    /* 44 */ u8 aiB;
    /* 45 */ u8 aiBpc;
    /* 46 */ // pad?

    /* 48 */ // end
};

struct ChapterInfo
{
    /* 00 */ char const* debugName;

    /* 04 */ u8 assetImgA;
    /* 05 */ u8 assetImgB;
    /* 06 */ u8 assetPal;
    /* 07 */ u8 assetTileset;
    /* 08 */ u8 assetMap;
    /* 09 */ u8 assetImgAnims;
    /* 0A */ u8 assetPalAnims;
    /* 0B */ u8 assetMapChanges;

    /* 0C */ u8 fog;
    /* 0D */ u8 bool_previewMap;
    /* 0E */ u8 unkName;
    /* 0F */ u8 unk0F;
    /* 10 */ u8 unk10;
    /* 11 */ u8 weather;
    /* 12 */ u8 banimGroundId;
    /* 13 */ u8 hardBonusLevels;
};

struct UnitInfo
{
    /* 00 */ u8 pid;
    /* 01 */ u8 jid;
    /* 02 */ u8 pidLead;
    /* 03 */ u8 autolevel : 1;
    /* 03 */ u8 factionId : 2;
    /* 03 */ u8 level : 5;
    /* 04 */ u8 xLoad, yLoad;
    /* 06 */ u8 xMove, yMove;
    /* 08 */ u8 item[4];
    /* 0C */ u8 ai[4];
};

struct BattleUnit
{
    /* 00 */ struct Unit unit;

    // this may not be accurate yet

    /* 48 */ u16 weapon;
    /* 4A */ u16 weaponBefore;
    /* 4C */ u32 weaponAttributes;
    /* 50 */ u8 weaponType;
    /* 51 */ u8 weaponSlotIndex;

    /* 52 */ s8 canCounter;

    /* 53 */ s8 wTriangleHitBonus;
    /* 54 */ s8 wTriangleDmgBonus;

    /* 55 */ u8 pad55[0x6A - 0x55];
 
    /* 6A */ s8 expGain;
    /* 6B */ s8 statusOut;
    /* 6C */ u8 levelPrevious;
    /* 6D */ u8 expPrevious;

    /* 6E */ u8 hpInitial;

    /* 6F */ s8 changeHP;
    /* 70 */ s8 changePow;
    /* 71 */ s8 changeSkl;
    /* 72 */ s8 changeSpd;
    /* 73 */ s8 changeDef;
    /* 74 */ s8 changeRes;
    /* 75 */ s8 changeLck;
    /* 76 */ s8 changeCon;

    /* 77 */ s8 wexpMultiplier;
    /* 78 */ s8 nonZeroDamage;
    /* 79 */ s8 weaponBroke;

    /* 7A */ s8 hasItemEffectTarget;
    /* 7B */ /* pad */
};

enum
{
    BATTLE_HIT_ATTR_CRIT      = (1 << 0),
    BATTLE_HIT_ATTR_MISS      = (1 << 1),
    BATTLE_HIT_ATTR_FOLLOWUP  = (1 << 2),
    BATTLE_HIT_ATTR_RETALIATE = (1 << 3),
    BATTLE_HIT_ATTR_BRAVE     = (1 << 4),
    BATTLE_HIT_ATTR_5         = (1 << 5), // unused?
    BATTLE_HIT_ATTR_POISON    = (1 << 6),
    BATTLE_HIT_ATTR_DEVIL     = (1 << 7),
    BATTLE_HIT_ATTR_HPSTEAL   = (1 << 8),
    BATTLE_HIT_ATTR_HPHALVE   = (1 << 9),
    BATTLE_HIT_ATTR_TATTACK   = (1 << 10), // triangle attack!
};

enum
{
    // BATTLE_HIT_INFO_BEGIN        = (1 << 0),
    // BATTLE_HIT_INFO_FINISHES     = (1 << 1),
    // BATTLE_HIT_INFO_KILLS_TARGET = (1 << 2),
    // BATTLE_HIT_INFO_RETALIATION  = (1 << 3),
    BATTLE_HIT_INFO_END          = (1 << 7),
};

struct BattleHit
{
    unsigned attributes : 16;
    unsigned info : 8;
    signed damage : 8;
};

struct AiDecision
{
    /* 00 */ u8 actionId;

    /* 01 */ u8 unitId;
    /* 02 */ u8 xMove;
    /* 03 */ u8 yMove;
    /* 04 */ u8 unk04;
    /* 05 */ u8 unk05;
    /* 06 */ u8 targetId;
    /* 07 */ u8 itemSlot;
    /* 08 */ u8 xTarget;
    /* 09 */ u8 yTarget;

    /* 0A */ Bool actionPerformed;
};
