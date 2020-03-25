
#pragma once

#include "gba/gba.h"
#include "types.h"

typedef void* ProcPtr;
typedef void(*ProcFunc)(ProcPtr proc);

struct ProcScr
{
    short cmdid;
    short imm;
    void const* ptr;
};

enum
{
    PROC_CMDID_END,
    PROC_CMDID_NAME,
    PROC_CMDID_CALL,
    PROC_CMDID_REPEAT,
    PROC_CMDID_SET_END_FUNC,
    PROC_CMDID_START_CHILD,
    PROC_CMDID_START_CHILD_BLOCKING,
    PROC_CMDID_START_BUGGED,
    PROC_CMDID_WHILE_EXISTS,
    PROC_CMDID_END_EACH,
    PROC_CMDID_BREAK_EACH,
    PROC_CMDID_LABEL,
    PROC_CMDID_GOTO,
    PROC_CMDID_GOTO_SCR,
    PROC_CMDID_SLEEP,
    PROC_CMDID_MARK,
    PROC_CMDID_BLOCK,
    PROC_CMDID_END_IF_DUP,
    PROC_CMDID_SET_FLAG2,
    PROC_CMDID_13,
    PROC_CMDID_WHILE,
    PROC_CMDID_15,
    PROC_CMDID_CALL_2,
    PROC_CMDID_END_DUPS,
    PROC_CMDID_CALL_ARG,
    PROC_CMDID_19,
};

#define PROC_END                          { PROC_CMDID_END, 0, 0 }
#define PROC_NAME(nameStr)                { PROC_CMDID_NAME, 0, (nameStr) }
#define PROC_CALL(func)                   { PROC_CMDID_CALL, 0, (func) }
#define PROC_REPEAT(func)                 { PROC_CMDID_REPEAT, 0, (func) }
#define PROC_SET_END_FUNC(func)           { PROC_CMDID_SET_END_FUNC, 0, (func) }
#define PROC_START_CHILD(procScr)         { PROC_CMDID_START_CHILD, 0, (procScr) }
#define PROC_START_CHILD_LOCKING(procScr) { PROC_CMDID_START_CHILD_BLOCKING, 1, (procScr) }
#define PROC_START_BUGGED(procScr)        { PROC_CMDID_START_BUGGED, 0, (procScr) }
#define PROC_WHILE_EXISTS(procScr)        { PROC_CMDID_WHILE_EXISTS, 0, (procScr) }
#define PROC_END_EACH(procScr)            { PROC_CMDID_END_EACH, 0, (procScr) }
#define PROC_BREAK_EACH(procScr)          { PROC_CMDID_BREAK_EACH, 0, (procScr) }
#define PROC_LABEL(label)                 { PROC_CMDID_LABEL, (label), 0 }
#define PROC_GOTO(label)                  { PROC_CMDID_GOTO, (label), 0 }
#define PROC_GOTO_SCR(procScr)            { PROC_CMDID_GOTO_SCR, 0, (procScr) }
#define PROC_SLEEP(duration)              { PROC_CMDID_SLEEP, (duration), 0 }
#define PROC_MARK(mark)                   { PROC_CMDID_MARK, (mark), 0 }
#define PROC_BLOCK                        { PROC_CMDID_BLOCK, 0, 0 }
#define PROC_END_IF_DUP                   { PROC_CMDID_END_IF_DUP, 0, 0 }
#define PROC_SET_FLAG2                    { PROC_CMDID_SET_FLAG2, 0, 0 }
#define PROC_13                           { PROC_CMDID_13, 0, 0 }
#define PROC_WHILE(func)                  { PROC_CMDID_WHILE, 0, (func) }
#define PROC_15                           { PROC_CMDID_15, 0, 0 }
#define PROC_CALL_2(func)                 { PROC_CMDID_CALL_2, 0, (func) }
#define PROC_END_DUPS                     { PROC_CMDID_END_DUPS, 0, 0 }
#define PROC_CALL_ARG(func, arg)          { PROC_CMDID_CALL_ARG, (arg), (func) }
#define PROC_19                           { PROC_CMDID_19, 0, 0 }

#define PROC_HEADER                                                                        \
    struct ProcScr const* proc_script; /* pointer to proc script */                        \
    struct ProcScr const* proc_scrCur; /* pointer to currently executing script command */ \
    ProcFunc proc_endFunc; /* callback to run upon delegint the process */                 \
    ProcFunc proc_repeatFunc; /* callback to run once each frame. */                       \
                          /* disables script execution when not null */                    \
    char const* proc_name;                                                                 \
    ProcPtr proc_parent; /* pointer to parent proc. If this proc is a root proc, */        \
                         /* this member is an integer which is the root index. */          \
    ProcPtr proc_child; /* pointer to most recently added child */                         \
    ProcPtr proc_next; /* next sibling */                                                  \
    ProcPtr proc_prev; /* previous sibling */                                              \
    s16 proc_sleepTime;                                                                    \
    u8 proc_mark;                                                                          \
    u8 proc_flags;                                                                         \
    u8 proc_lockCnt; /* wait semaphore. Process execution */                               \
                     /* is blocked when this is nonzero. */                                \

struct GenericProc
{
    /* 00 */ PROC_HEADER;

    /* 29 */ u8 pad29[0x54 - 0x29];

    /* 54 */ void* ptr;
};

#define PROC_TREE_VSYNC ((ProcPtr) 0)
#define PROC_TREE_1     ((ProcPtr) 1)
#define PROC_TREE_2     ((ProcPtr) 2)
#define PROC_TREE_3     ((ProcPtr) 3)
#define PROC_TREE_4     ((ProcPtr) 4)
#define PROC_TREE_5     ((ProcPtr) 5)
#define PROC_TREE_6     ((ProcPtr) 6)
#define PROC_TREE_7     ((ProcPtr) 7)

extern ProcPtr gProcTreeRootArray[8];

void InitProcs(void);
ProcPtr SpawnProc(struct ProcScr const* scr, ProcPtr parent);
ProcPtr SpawnProcLocking(struct ProcScr const* scr, ProcPtr parent);
void Proc_End(ProcPtr proc);
void Proc_Run(ProcPtr proc);
void Proc_Break(ProcPtr proc);
ProcPtr Proc_Find(struct ProcScr const* script);
ProcPtr Proc_FindActive(struct ProcScr const* script);
ProcPtr Proc_FindMarked(int mark);
void Proc_Goto(ProcPtr proc, int label);
void Proc_GotoScript(ProcPtr proc, struct ProcScr const* script);
void Proc_Mark(ProcPtr proc, int mark);
void Proc_SetEndFunc(ProcPtr proc, ProcFunc func);
void Proc_ForAll(ProcFunc func);
void Proc_ForEach(struct ProcScr const* script, ProcFunc func);
void Proc_ForEachMarked(int mark, ProcFunc func);
void Proc_LockEachMarked(int mark);
void Proc_ReleaseEachMarked(int mark);
void Proc_EndEachMarked(int mark);
void Proc_EndEach(struct ProcScr const* script);
void Proc_BreakEach(struct ProcScr const* script);
void Proc_ForSubtree(ProcPtr proc, ProcFunc func);
void Proc_PrintSubtreeInfo(ProcPtr proc);
void Proc_SetRepeatFunc(ProcPtr proc, ProcFunc func);
void Proc_Lock(ProcPtr proc);
void Proc_Release(ProcPtr proc);

#define Proc_Exists(script) (Proc_Find(script) ? TRUE : FALSE)
