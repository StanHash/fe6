
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

// Forward decls for common types
// TODO: move

struct BmSt;
struct PlaySt;

struct Unit;
struct UnitInfo;

// Type decls for types that don't have a home yet :/
// TODO: move

enum { CONVOY_ITEM_COUNT = 100 };

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
    ACTION_NONE,

    ACTION_WAIT = 0x01,
    ACTION_COMBAT = 0x02,
    ACTION_STAFF = 0x03,
    // ACTION_DANCE,
    // ACTION_STEAL,
    // ACTION_RESCUE,
    // ACTION_DROP,
    ACTION_TAKE = 0x09,
    ACTION_GIVE = 0x0A,
    // ACTION_TALK,
    // ACTION_SUPPORT,
    // ACTION_VISIT,
    // ACTION_SEIZE,
    // ACTION_DOOR,
    // ACTION_CHEST,
    // ACTION_SHOPPED,
    // ACTION_ARENA,
    // ACTION_USE_ITEM,
    ACTION_TRADED = 0x18,
    ACTION_TRADED_SUPPLY = 0x19,
    ACTION_TRADED_NOCHANGES = 0x1A,
    ACTION_TRAPPED = 0x1B,
    ACTION_1C = 0x1C,
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

    MOVE_CMD_WAIT,
    MOVE_CMD_BUMP,
    MOVE_CMD_UNK11,
    MOVE_CMD_SET_SPEED,

    MOVE_CMD_CAMERA_ON,
    MOVE_CMD_CAMERA_OFF,

    MOVE_SCRIPT_MAX_LENGTH = 0x40,
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

    /* 14 */ u8 songBlueBgm;
    /* 15 */ u8 songRedBgm;
    /* 16 */ u8 songGreenBgm;
    /* 17 */ u8 songIntroBgm;
    /* 18 */ u8 songOpeningBgm;

    /* 19 */ u8 wallHp;
    /* 1A */ u8 classRollSet;

    /* 1B */ u8 pad_1B[0x3E - 0x1B];

    /* 3E */ u8 numberId;

    /* 3F */ u8 pad_3F[0x43 - 0x3F];

    /* 43 */ s8 victoryBgmEnemyThreshold;
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

enum
{
    SUSPEND_POINT_PLAYER_PHASE,
    SUSPEND_POINT_DURING_ACTION,
    SUSPEND_POINT_AI_PHASE,
    SUSPEND_POINT_BERSERK_PHASE,
    SUSPEND_POINT_DURING_ARENA,
    SUSPEND_POINT_5,
    SUSPEND_POINT_6,
    SUSPEND_POINT_7,
    SUSPEND_POINT_8,
    SUSPEND_POINT_CHANGE_PHASE,
};

struct Action
{
    /* 00 */ u16 unk_00[3];
    /* 06 */ u16 unk_06;
    /* 08 */ u16 unk_08[2];

    /* 0C */ u8 actor;
    /* 0D */ u8 target;

    /* 0E */ u8 xMove;
    /* 0F */ u8 yMove;

    /* 10 */ u8 moveCount;

    /* 11 */ u8 id;

    // maybe from this onwards it's an union?

    /* 12 */ u8 itemSlot;

    /* 13 */ u8 xTarget;
    /* 14 */ u8 yTarget;

    /* 15 */ u8 unk_15;

    /* 16 */ u8 suspendPoint;

    /* 18 */ struct BattleHit* scriptedBattleHits;

    /* 1C+ TODO (sizeof(struct ActionData) == 0x38) */
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
