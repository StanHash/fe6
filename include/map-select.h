#pragma once

#include "common.h"
#include "proc.h"

enum
{
    MAPSELECT_MAX_TARGETS = 64,
};

enum
{
    // MapSelectProc::flags

    MAPSELECT_FLAG_GAMELOCK = 1 << 0,
    MAPSELECT_FLAG_FROZEN   = 1 << 6,
};

enum
{
    MAPSELECT_ACTION_NOCURSOR = 1 << 0,
    MAPSELECT_ACTION_END      = 1 << 1,
    MAPSELECT_ACTION_SE_6A    = 1 << 2,
    MAPSELECT_ACTION_SE_6B    = 1 << 3,
    MAPSELECT_ACTION_CLEAR    = 1 << 4,
    MAPSELECT_ACTION_ENDFACE  = 1 << 5,
};

struct SelectTarget
{
    /* 00 */ i8 x, y;
    /* 02 */ i8 uid;
    /* 03 */ i8 extra;
    /* 04 */ struct SelectTarget * next;
    /* 08 */ struct SelectTarget * prev;
};

struct MapSelectProc;

struct MapSelectInfo
{
    /* 00 */ void (* on_init)(struct MapSelectProc * proc);
    /* 04 */ void (* on_end)(struct MapSelectProc * proc);
    /* 08 */ void (* on_init_b)(struct MapSelectProc * proc);
    /* 0C */ fu8 (* on_switch_in)(struct MapSelectProc * proc, struct SelectTarget * target);
    /* 10 */ fu8 (* on_switch_out)(struct MapSelectProc * proc, struct SelectTarget * target);
    /* 14 */ fu8 (* on_a_press)(struct MapSelectProc * proc, struct SelectTarget * target);
    /* 18 */ fu8 (* on_b_press)(struct MapSelectProc * proc, struct SelectTarget * target);
    /* 1C */ fu8 (* on_r_press)(struct MapSelectProc * proc, struct SelectTarget * target);
};

struct MapSelectProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ // pad
    /* 2C */ struct MapSelectInfo const * info;
    /* 30 */ struct SelectTarget * active_target;
    /* 34 */ u8 flags;
    /* 35 */ // pad
    /* 38 */ fu8 (* on_a_press)(struct MapSelectProc * proc, struct SelectTarget * target);
};

void BeginTargetList(int x, int y);
void EnlistTarget(int x, int y, int uid, int extra);
int CountTargets(void);
struct SelectTarget * GetTarget(int id);
void LinkTargets(void);
ProcPtr StartMapSelect(struct MapSelectInfo const * info);
ProcPtr StartMapSelectExt(struct MapSelectInfo const * info, fu8 (* on_a_press)(struct MapSelectProc * proc, struct SelectTarget * target));
ProcPtr EndMapSelect(struct MapSelectProc * proc);
void FreezeMapSelect(void);
void ResumeMapSelect(void);
int GetFurthestTargetDistance(void);
struct SelectTarget * GetLinkedTargets(void);

SHOULD_BE_STATIC void GetMapSelectActivePosition(struct MapSelectProc * proc, int * x_out, int * y_out);
SHOULD_BE_STATIC void MapSelect_Main(struct MapSelectProc * proc);
SHOULD_BE_STATIC void HandleMapSelectSwitching(struct MapSelectProc * proc);
SHOULD_BE_STATIC u32 HandleMapSelectActions(struct MapSelectProc * proc);
SHOULD_BE_STATIC struct SelectTarget * GetLinkedTargetsNear(void);
SHOULD_BE_STATIC struct SelectTarget * GetLinkedTargetsFar(void);

extern struct ProcScr CONST_DATA ProcScr_MapSelect[];
