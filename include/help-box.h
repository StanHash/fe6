#pragma once

#include "common.h"

#include "proc.h"

struct HelpBoxProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ struct HelpBoxInfo const* info;

    /* 30 */ short xBox;
    /* 32 */ short yBox;
    /* 34 */ short wBox;
    /* 36 */ short hBox;
    /* 38 */ short xBoxInit;
    /* 3A */ short yBoxInit;
    /* 3C */ short xBoxFinal;
    /* 3E */ short yBoxFinal;
    /* 40 */ short wBoxInit;
    /* 42 */ short hBoxInit;
    /* 44 */ short wBoxFinal;
    /* 46 */ short hBoxFinal;
    /* 48 */ short timer;
    /* 4A */ short timerMax;

    /* 4C */ u16 msg;
    /* 4E */ u16 item;

    /* 50 */ u16 moveKey; // move ctrl proc only

    /* 52 */ u8 unk_52;

    // NOTE: there's likely more, need to decompile more files
};

struct HelpBoxInfo
{
    /* 00 */ struct HelpBoxInfo const* adjUp;
    /* 04 */ struct HelpBoxInfo const* adjDown;
    /* 08 */ struct HelpBoxInfo const* adjLeft;
    /* 0C */ struct HelpBoxInfo const* adjRight;
    /* 10 */ u8 x, y;
    /* 12 */ u16 msg;
    /* 14 */ void(*redirect)(struct HelpBoxProc* proc);
    /* 18 */ void(*populate)(struct HelpBoxProc* proc);
};

extern struct HelpBoxInfo const HelpInfo_BpShort_Hp;
extern struct HelpBoxInfo const HelpInfo_BpLarge_Hp;
