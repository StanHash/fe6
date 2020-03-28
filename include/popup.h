
#pragma once

#include "gba/gba.h"
#include "types.h"

#include "proc.h"

enum
{
    POPUP_CMD_END,
    POPUP_CMD_SPACE,
    POPUP_CMD_ITEM_NAME,
    POPUP_CMD_UNIT_NAME,
    POPUP_CMD_MSG,
    POPUP_CMD_STR,
    POPUP_CMD_COLOR,
    POPUP_CMD_ICON_ITEM,
    POPUP_CMD_ICON_IKIND,
    POPUP_CMD_NUMBER,
    POPUP_CMD_SONG,
};

struct PopupInfo
{
    /* 00 */ u8 cmd;
    /* 04 */ int arg;
};

void SetPopupUnit(struct Unit* unit);
void SetPopupItem(u16 item);
void SetPopupNumber(int number);
ProcPtr StartPopup(struct PopupInfo const* info, int duration, int winKind, ProcPtr parent);
ProcPtr StartPopupExt(struct PopupInfo const* info, int duration, int winKind, int iconChr, int iconPal, ProcPtr parent);
void EndPopup(void);

#define POPUP_END { POPUP_CMD_END, 0 }
#define POPUP_SPACE(len) { POPUP_CMD_SPACE, (len) }
#define POPUP_ITEM_NAME { POPUP_CMD_ITEM_NAME, 0 }
#define POPUP_UNIT_NAME { POPUP_CMD_UNIT_NAME, 0 }
#define POPUP_MSG(msg) { POPUP_CMD_MSG, (msg) }
#define POPUP_STR(str) { POPUP_CMD_STR, (int) (char const*) (str) }
#define POPUP_COLOR(color) { POPUP_CMD_COLOR, (color) }
#define POPUP_ICON_ITEM { POPUP_CMD_ICON_ITEM, 0 }
#define POPUP_ICON_IKIND { POPUP_CMD_ICON_IKIND, 0 }
#define POPUP_NUMBER { POPUP_CMD_NUMBER, 0 }
#define POPUP_SONG(song) { POPUP_CMD_SONG, (song) }
