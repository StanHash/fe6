#pragma once

#include "common.h"

#include "proc.h"
#include "text.h"

enum { MENU_MAX_ENTRIES = 11 };

enum
{
    MENU_ENTRY_ENABLED,
    MENU_ENTRY_DISABLED,
    MENU_ENTRY_HIDDEN,
};

enum
{
    MENU_ACTION_SKIPCURSOR = (1 << 0),
    MENU_ACTION_END        = (1 << 1),
    MENU_ACTION_SE_6A      = (1 << 2), // TODO: name song
    MENU_ACTION_SE_6B      = (1 << 3), // TODO: name song
    MENU_ACTION_CLEAR      = (1 << 4),
    MENU_ACTION_ENDFACE    = (1 << 5),
    MENU_ACTION_UNUSED6    = (1 << 6),
    MENU_ACTION_DOOM       = (1 << 7),
};

enum
{
    // MenuProc::flags

    MENU_FLAG_GAMELOCK = 1 << 0,
    MENU_FLAG_1        = 1 << 1, // unused
    MENU_FLAG_ENDING   = 1 << 2,
    MENU_FLAG_HIDDEN   = 1 << 3,
    MENU_FLAG_FLAT     = 1 << 4,
    MENU_FLAG_NOCURSOR = 1 << 5,
    MENU_FLAG_FROZEN   = 1 << 6,
    MENU_FLAG_DOOMED   = 1 << 7,
};

struct MenuRect { i8 x, y, w, h; };

struct MenuProc;
struct MenuEntProc;

struct MenuEntInfo
{
    /* 00 */ char const * label;

    /* 04 */ u16 msg_label; // NOTE: unused
    /* 06 */ u16 msg_help;
    /* 08 */ u8 text_color;

    /* 0C */ fu8 (* available)(struct MenuEntInfo const * info, int id);

    /* 10 */ int (* on_draw)(struct MenuProc * menu, struct MenuEntProc * ent);

    /* 14 */ fu8 (* on_select)(struct MenuProc *, struct MenuEntProc * ent);
    /* 18 */ fu8 (* on_idle)(struct MenuProc *, struct MenuEntProc * ent);

    /* 1C */ int (* on_switch_in)(struct MenuProc * menu, struct MenuEntProc * ent);
    /* 20 */ int (* on_switch_out)(struct MenuProc * menu, struct MenuEntProc * ent);
};

struct MenuInfo
{
    /* 00 */ struct MenuRect rect;
    /* 04 */ u8 window_kind;
    /* 08 */ struct MenuEntInfo const * entries;

    /* 0C */ void (* on_init)(struct MenuProc * menu);
    /* 10 */ void (* on_end)(struct MenuProc * menu);
    /* 14 */ void (* unk_14)(struct MenuProc * menu);
    /* 18 */ fu8 (* on_b_press)(struct MenuProc *, struct MenuEntProc * ent);
    /* 1C */ fu8 (* on_r_press)(struct MenuProc * menu);
    /* 20 */ void (* on_help_box)(struct MenuProc * menu, struct MenuEntProc * ent);
};

struct MenuProc
{
    /* 00 */ PROC_HEADER;
    /* 2C */ struct MenuRect rect;
    /* 30 */ struct MenuInfo const * info;
    /* 34 */ struct MenuEntProc * entries[MENU_MAX_ENTRIES];
    /* 60 */ u8 entry_count;
    /* 61 */ u8 active_entry;
    /* 62 */ u8 previous_entry;
    /* 63 */ u8 flags;
};

struct MenuEntProc
{
    /* 00 */ PROC_HEADER;
    /* 2A */ i16 x;
    /* 2C */ i16 y;
    /* 30 */ struct MenuEntInfo const * info;
    /* 34 */ struct Text text;
    /* 3C */ i8 id;
    /* 3D */ u8 availability;
};

struct MenuProc * StartAdjustedMenu(struct MenuInfo const * info, int x, int left, int right);
struct MenuProc * StartLockingMenu(struct MenuInfo const * info, ProcPtr parent);
struct MenuProc * StartMenuExt(struct MenuInfo const * info, struct MenuRect rect);
struct MenuProc * StartMenu(struct MenuInfo const * info);
struct MenuProc * StartLockingMenuExt(struct MenuInfo const * info, struct MenuRect rect, ProcPtr parent);
ProcPtr EndMenu(struct MenuProc * proc);
void EndMenus(void);
fu8 MenuEntryEnabled(struct MenuEntInfo const * info, int id);
fu8 MenuEntryDisabled(struct MenuEntInfo const * info, int id);
fu8 MenuActionClose(struct MenuProc * proc, struct MenuEntProc * ent);
fu8 func_fe6_08041E78(struct MenuProc * proc, struct MenuEntProc * ent);
fu8 MenuHelpBox(struct MenuProc * proc);
fu8 MenuFrozenHelpBox(struct MenuProc * proc, int msg);
void FreezeMenu(void);
void ResumeMenu(void);
struct MenuProc * StartCenteredMenu(struct MenuInfo const * info, int x, int left, int right);

SHOULD_BE_STATIC bool HasMenuChangedItem(struct MenuProc * proc);
SHOULD_BE_STATIC void Menu_Init(struct MenuProc * proc);
SHOULD_BE_STATIC void Menu_Draw(struct MenuProc * proc);
SHOULD_BE_STATIC void PutMenuEntryHover(struct MenuProc * proc, int entry_id, bool shown);
SHOULD_BE_STATIC void Menu_Main(struct MenuProc * proc);
SHOULD_BE_STATIC void HandleMenuSwitching(struct MenuProc * proc);
SHOULD_BE_STATIC u32 HandleMenuActions(struct MenuProc * proc);
SHOULD_BE_STATIC void GetMenuCursorPosition(struct MenuProc * proc, int * x_out, int * y_out);
SHOULD_BE_STATIC void Menu_HelpBoxInit(struct MenuProc * proc);
SHOULD_BE_STATIC void Menu_HelpBoxMain(struct MenuProc * proc);
SHOULD_BE_STATIC void Menu_FrozenHelpBoxMain(struct MenuProc * proc);
SHOULD_BE_STATIC void ApplyMenuCursorScroll(struct MenuProc * proc, int * x_ref, int * y_ref);

extern struct ProcScr CONST_DATA ProcScr_MenuMain[];
extern struct ProcScr CONST_DATA ProcScr_Menu[];
extern struct ProcScr CONST_DATA ProcScr_MenuItem[];
extern struct ProcScr CONST_DATA ProcScr_MenuHelpBox[];
extern struct ProcScr CONST_DATA ProcScr_MenuFrozenHelpBox[];
