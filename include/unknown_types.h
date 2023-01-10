#pragma once

#include "types.h"

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

struct ChapterInfo
{
    /* 00 */ char const * debug_name;

    /* 04 */ u8 asset_img_a;
    /* 05 */ u8 asset_img_b;
    /* 06 */ u8 asset_pal;
    /* 07 */ u8 asset_tileset;
    /* 08 */ u8 asset_map;
    /* 09 */ u8 asset_img_anims;
    /* 0A */ u8 asset_pal_anims;
    /* 0B */ u8 asset_map_changes;

    /* 0C */ u8 fog;
    /* 0D */ u8 has_prep;
    /* 0E */ u8 title_id;
    /* 0F */ u8 unk_0F;
    /* 10 */ u8 unk_10;
    /* 11 */ u8 weather;
    /* 12 */ u8 banim_terrain_id;
    /* 13 */ u8 hard_bonus_levels;

    /* 14 */ u8 song_blue_bgm;
    /* 15 */ u8 song_red_bgm;
    /* 16 */ u8 song_green_bgm;
    /* 17 */ u8 song_intro_bgm;
    /* 18 */ u8 song_opening_bgm;

    /* 19 */ u8 wall_hp;
    /* 1A */ u8 class_roll_set;

    /* 1B */ u8 pad_1B[0x38 - 0x1B];

    /* 38 */ u16 msg_38;
    /* 3A */ u8 asset_event_info;

    /* 3B */ u8 pad_3B[0x3E - 0x3B];

    /* 3E */ u8 numberId;

    /* 3F */ u8 pad_3F[0x43 - 0x3F];

    /* 43 */ i8 victory_bgm_enemy_threshold;
};

struct MapChangeInfo
{
    /* 00 */ i8 id;
    /* 01 */ u8 x, y, width, height;
    /* 05 */ // pad
    /* 08 */ u16 const * metatiles;
};

struct BattleHit;
struct BattleUnit;

struct MapAnimActor
{
    /* 00 */ struct Unit * unit;
    /* 04 */ struct BattleUnit * bu;
    /* 08 */ struct MuProc * mu;
    /* 0C */ u8 hp_max;
    /* 0D */ u8 hp_cur;
    /* 0E */ u16 unk_0E;
    /* 10 */ u8 unk_10;
    /* 11 */ u8 unk_11;
    /* 12 */ u8 unk_12;
    /* 13 */ u8 unk_13;
};

struct MapAnimSt
{
    /* 00 */ struct MapAnimActor actor[4];
    /* 50 */ struct BattleHit * hit_it;
    /* 54 */ struct ProcScr const * special_proc_scr;
    /* 58 */ u8 attacker_actor;
    /* 59 */ u8 defender_actor;
    /* 5A */ u16 hit_attributes;
    /* 5C */ u8 hit_info;
    /* 5D */ i8 hit_damage;
    /* 5E */ u8 main_actor_count;
    /* 5F */ u8 unk_5F;
    /* 60 */ u8 unk_60;
    /* 61 */ u8 unk_61;
    /* 62 */ u8 unk_62;
};

struct ChapterEventInfo
{
    /* 00 */ void const * event_list_turn;
    /* 04 */ void const * event_list_talk;
    /* 08 */ void const * event_list_tile;
    /* 0C */ void const * event_list_move;
    /* 10 */ void const * units_red;
    /* 14 */ void const * units_blue;
    /* 18 */ void const * script_18;
};

struct TrialLoadInfo
{
    /* 00 */ struct ChapterInfo const * chapter_info;
    /* 04 */ struct MapChangeInfo const * map_change_info;
    /* 08 */ struct ChapterEventInfo const * event_info;
    /* 0C */ char const * msg_0C;
    /* 10 */ // ...
};

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

enum { MAX_SAVED_GAME_CLEARS = 12 };

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
