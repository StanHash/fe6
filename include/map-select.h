
#pragma once

#include "common.h"

#include "proc.h"

struct SelectTarget
{
    /* 00 */ s8 x, y;
    /* 02 */ s8 uid;
    /* 03 */ s8 extra;

    /* 04 */ struct SelectTarget* next;
    /* 08 */ struct SelectTarget* prev;
};

struct MapSelectProc;

struct MapSelectInfo
{
    /* 00 */ void(*onInit)(struct MapSelectProc* proc);
    /* 04 */ void(*onEnd)(struct MapSelectProc* proc);

    /* 08 */ void(*unk_08)(struct MapSelectProc* proc, struct SelectTarget* target);

    /* 0C */ void(*onSwitchIn)(struct MapSelectProc* proc, struct SelectTarget* target);
    /* 10 */ void(*onSwitchOut)(struct MapSelectProc* proc, struct SelectTarget* target);

    /* 14 */ int(*onAPress)(struct MapSelectProc* proc, struct SelectTarget* target);
    /* 18 */ int(*onBPress)(struct MapSelectProc* proc, struct SelectTarget* target);
    /* 1C */ int(*onRPress)(struct MapSelectProc* proc, struct SelectTarget* target);
};

struct MapSelectProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ struct MapSelectInfo const* info;
    /* 30 */ struct SelectTarget* activeTarget;
    /* 34 */ u8 flags;
    /* 38 */ int(*onAPress)(struct MapSelectProc* proc, struct SelectTarget* target);
};
