
#pragma once

#include "gba/gba.h"

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
    u32 unk1D_1:1; // 1
    u32 unk1D_2:1; // 1
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
    /* 05 */ u8 defaultJid;
};

struct JobInfo
{
    /* 00 */ u16 msgName;
    /* 02 */ u16 msgDesc;
    /* 04 */ u8 id;
    /* 05 */ u8 promoteJid;
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
};

struct ChapterInfo
{
    /* 00 */ u8 pad00[0x13 - 0x00];
    /* 13 */ u8 hardBonusLevels;
};

struct UnitInfo
{
    /* 00 */ u8 pid;
    /* 01 */ u8 jid;
    /* 02 */ u8 leadPid;
    /* 03 */ u8 autolevel : 1;
    /* 03 */ u8 factionId : 2;
    /* 03 */ u8 level : 5;
    /* 04 */ u8 xLoad, yLoad;
    /* 06 */ u8 xMove, yMove;
    /* 08 */ // TODO: more
};
