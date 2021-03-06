
#pragma once

#include "gba/gba.h"

#if !defined(__cpluscplus) && !defined(bool)

typedef s8 bool;

#endif

typedef void(*Func)(void);

struct Vec2
{
    short x, y;
};

struct Vec2u
{
    u16 x, y;
};

// Forward decls for common types
// TODO: move

struct BmSt;
struct PlaySt;

struct Unit;
struct UnitInfo;
struct UnitSprite;
struct SupportInfo;

struct HelpBoxInfo;

// Type decls for types that don't have a home yet :/
// TODO: move

enum
{
    MAP_MOVEMENT_MAX = 120,
    MAP_MOVEMENT_EXTENDED = 124,
};

enum
{
    FACING_LEFT,
    FACING_RIGHT,
    FACING_DOWN,
    FACING_UP,
};

enum
{
    MOVE_CMD_END = -1, // end

    MOVE_CMD_MOVE_BASE,

    MOVE_CMD_MOVE_LEFT  = MOVE_CMD_MOVE_BASE + FACING_LEFT,
    MOVE_CMD_MOVE_RIGHT = MOVE_CMD_MOVE_BASE + FACING_RIGHT,
    MOVE_CMD_MOVE_DOWN  = MOVE_CMD_MOVE_BASE + FACING_DOWN,
    MOVE_CMD_MOVE_UP    = MOVE_CMD_MOVE_BASE + FACING_UP,

    MOVE_CMD_HALT,

    MOVE_CMD_FACE_BASE,

    MOVE_CMD_FACE_LEFT  = MOVE_CMD_FACE_BASE + FACING_LEFT,
    MOVE_CMD_FACE_RIGHT = MOVE_CMD_FACE_BASE + FACING_RIGHT,
    MOVE_CMD_FACE_DOWN  = MOVE_CMD_FACE_BASE + FACING_DOWN,
    MOVE_CMD_FACE_UP    = MOVE_CMD_FACE_BASE + FACING_UP,

    MOVE_CMD_SLEEP,
    MOVE_CMD_BUMP,
    MOVE_CMD_UNK11,
    MOVE_CMD_SET_SPEED,

    MOVE_CMD_CAMERA_ON,
    MOVE_CMD_CAMERA_OFF,

    MOVE_SCRIPT_MAX_LENGTH = 0x40,
};

enum
{
    LOCATION_COMMAND_0F = 0x0F,
    LOCATION_COMMAND_VISIT = 0x0E,
    LOCATION_COMMAND_13 = 0x13,
    LOCATION_COMMAND_14 = 0x14,
    LOCATION_COMMAND_15 = 0x15,
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
    /* 0D */ u8 hasPrep;
    /* 0E */ u8 unkName;
    /* 0F */ u8 unk0F;
    /* 10 */ u8 unk10;
    /* 11 */ u8 weather;
    /* 12 */ u8 banimGroundId;
    /* 13 */ u8 hardBonusLevels;

    /* 14 */ u8 songBlueBgm;
    /* 15 */ u8 songRedBgm;
    /* 16 */ u8 songGreenBgm;
    /* 17 */ u8 songIntroBgm;
    /* 18 */ u8 songOpeningBgm;

    /* 19 */ u8 wallHp;
    /* 1A */ u8 classRollSet;

    /* 1B */ u8 pad_1B[0x38 - 0x1B];

    /* 38 */ u16 msg_38;
    /* 3A */ u8 assetEventInfo;

    /* 3B */ u8 pad_3B[0x3E - 0x3B];

    /* 3E */ u8 numberId;

    /* 3F */ u8 pad_3F[0x43 - 0x3F];

    /* 43 */ s8 victoryBgmEnemyThreshold;
};

struct MapChangeInfo
{
    /* 00 */ s8 id;
    /* 01 */ u8 x, y, width, height;
    /* 05 */ // pad
    /* 08 */ u16 const* metatiles;
};

struct BattleHit;
struct BattleUnit;

struct MapAnimActor
{
    /* 00 */ struct Unit* unit;
    /* 04 */ struct BattleUnit* bu;
    /* 08 */ struct MuProc* mu;
    /* 0C */ u8 unk_0C;
    /* 0D */ u8 unk_0D;
    /* 0E */ u16 unk_0E;
    /* 10 */ u8 unk_10;
    /* 11 */ u8 unk_11;
    /* 12 */ u8 unk_12;
    /* 13 */ u8 unk_13;
};

struct MapAnimSt
{
    /* 00 */ struct MapAnimActor actor[4];
    /* 50 */ struct BattleHit* hitIt;
    /* 54 */ struct ProcScr const* specialProcScr;
    /* 58 */ u8 attackerActor;
    /* 59 */ u8 defenderActor;
    /* 5A */ u16 hitAttributes;
    /* 5C */ u8 hitInfo;
    /* 5D */ s8 hitDamage;
    /* 5E */ u8 unk_5E;
    /* 5F */ u8 unk_5F;
    /* 60 */ u8 unk_60;
    /* 61 */ u8 unk_61;
    /* 62 */ u8 unk_62;
};

struct ChapterEventInfo
{
    /* 00 */ void const* pad_00;
    /* 04 */ // ...
};

struct TrialLoadInfo
{
    /* 00 */ struct ChapterInfo const* chapterInfo;
    /* 04 */ struct MapChangeInfo const* mapChangeInfo;
    /* 08 */ struct ChapterEventInfo const* eventInfo;
    /* 0C */ char const* msg_0C;
    /* 10 */ // ...
};

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
    /* 00 */ u8 pad_00[0x0E - 0x00];
    /* 0E */ u8 unk_0E_0 : 1;
    /* 0E */ u8 unk_0E_1 : 1;
    /* 0E */ u8 unk_0E_2 : 1;
    /* 0E */ u8 unk_0E_3 : 1;
    /* 0F */ u8 pad_0F[0x10 - 0x0F];
    /* 10 */ u8 unk_10[0x10];
};

struct SaveBlockInfo
{
    /* 00 */ u32 magicA;
    /* 04 */ u16 magicB;
    /* 06 */ u8 kind;
    /* 08 */ u16 offset;
    /* 0A */ u16 size;
    /* 0C */ u32 checksum32;
};
