
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
