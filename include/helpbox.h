#pragma once

#include "common.h"

#include "proc.h"

struct HelpBoxProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ struct HelpBoxInfo const * info;

    /* 30 */ i16 x_box;
    /* 32 */ i16 y_box;
    /* 34 */ i16 w_box;
    /* 36 */ i16 h_box;
    /* 38 */ i16 x_box_init;
    /* 3A */ i16 y_box_init;
    /* 3C */ i16 x_box_fini;
    /* 3E */ i16 y_box_fini;
    /* 40 */ i16 w_box_init;
    /* 42 */ i16 h_box_init;
    /* 44 */ i16 w_box_fini;
    /* 46 */ i16 h_box_fini;
    /* 48 */ i16 timer;
    /* 4A */ i16 timer_end;

    /* 4C */ u16 msg;
    /* 4E */ u16 item;

    /* 50 */ u16 move_key_bit; // move ctrl proc only

    /* 52 */ u8 unk_52;

    // NOTE: there's likely more, need to decompile more files
};

struct HelpBoxInfo
{
    /* 00 */ struct HelpBoxInfo const * adjUp;
    /* 04 */ struct HelpBoxInfo const * adjDown;
    /* 08 */ struct HelpBoxInfo const * adjLeft;
    /* 0C */ struct HelpBoxInfo const * adjRight;
    /* 10 */ u8 x, y;
    /* 12 */ u16 msg;
    /* 14 */ void (* redirect)(struct HelpBoxProc * proc);
    /* 18 */ void (* populate)(struct HelpBoxProc * proc);
};

extern struct HelpBoxInfo const HelpInfo_BpShort_Hp;
extern struct HelpBoxInfo const HelpInfo_BpLarge_Hp;
