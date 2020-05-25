
#pragma once

#include "common.h"

#include "proc.h"
#include "text.h"

enum { MENU_ENTRIES_MAX = 11 };

enum
{
    MENU_ENABLED,
    MENU_DISABLED,
    MENU_NOTSHOWN,
};

enum
{
    MENU_ACT_SKIPCURSOR = (1 << 0),
    MENU_ACT_END = (1 << 1),
    MENU_ACT_SE_6A = (1 << 2), // TODO: name song
    MENU_ACT_SE_6B = (1 << 3), // TODO: name song
    MENU_ACT_CLEAR = (1 << 4),
    MENU_ACT_ENDFACE = (1 << 5),
    MENU_ACT_UNUSED6 = (1 << 6),
    MENU_ACT_DOOM = (1 << 7),
};

enum
{
    MENU_FLAG_0 = (1 << 0),
    MENU_FLAG_1 = (1 << 1),
    MENU_FLAG_2 = (1 << 2),
};

struct MenuRect { s8 x, y, w, h; };

struct MenuProc;
struct MenuEntProc;

struct MenuEntInfo
{
    /* 00 */ char const* name;

    /* 04 */ u8 pad_04[0x0C - 0x04];

    /* 0C */ u8(*available)(struct MenuEntInfo const* info, int id);

    /* 10 */ int(*onDraw)(struct MenuProc* menu, struct MenuEntProc* ent);

    /* 14 */ u8(*onSelected)(struct MenuProc*, struct MenuEntProc* ent);
    /* 18 */ u8(*onIdle)(struct MenuProc*, struct MenuEntProc* ent);

    /* 1C */ int(*onSwitchIn)(struct MenuProc* menu, struct MenuEntProc* ent);
    /* 20 */ int(*onSwitchOut)(struct MenuProc* menu, struct MenuEntProc* ent);
};

struct MenuInfo
{
    /* 00 */ struct MenuRect rect;
    /* 04 */ u8 style;
    /* 08 */ struct MenuEntInfo const* entries;

    /* 0C */ void(*onInit)(struct MenuProc* menu);
    /* 10 */ void(*onEnd)(struct MenuProc* menu);
    /* 14 */ void(*unk_14)(struct MenuProc* menu);
    /* 18 */ u8(*onBPress)(struct MenuProc*, struct MenuEntProc* ent);
    /* 1C */ u8(*onRPress)(struct MenuProc* menu);
    /* 20 */ void(*onHelpBox)(struct MenuProc* menu, struct MenuEntProc* ent);
};

struct MenuProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ struct MenuRect rect;
    /* 30 */ struct MenuInfo const* info;

    /* 34 */ struct MenuEntProc* entries[MENU_ENTRIES_MAX];

    /* 60 */ u8 entryCount;
    /* 61 */ u8 activeEntry;
    /* 62 */ u8 previousEntry;
    /* 63 */ u8 flags;

    /* 64 */ u8 backBg : 2;
    /* 64 */ u8 frontBg : 2;

    /* 66 */ u16 tileref;
    /* 68 */ u16 unk68;
};

struct MenuEntProc
{
    /* 00 */ PROC_HEADER;

    /* 2A */ short x;
    /* 2C */ short y;

    /* 30 */ struct MenuEntInfo const* info;

    /* 34 */ struct Text text;

    /* 3C */ s8 id;
    /* 3D */ u8 availability;
};
