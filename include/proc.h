#pragma once

#include "types.h"
#include "attributes.h"

typedef void * ProcPtr;
typedef void (* ProcFunc)(ProcPtr proc);

struct ProcScr
{
    i16 cmd;
    i16 imm;
    void const * ptr;
};

enum
{
    PROC_CMD_END,
    PROC_CMD_NAME,
    PROC_CMD_CALL,
    PROC_CMD_REPEAT,
    PROC_CMD_ONEND,
    PROC_CMD_START_CHILD,
    PROC_CMD_START_CHILD_BLOCKING,
    PROC_CMD_START_BUGGED,
    PROC_CMD_WHILE_EXISTS,
    PROC_CMD_END_EACH,
    PROC_CMD_BREAK_EACH,
    PROC_CMD_LABEL,
    PROC_CMD_GOTO,
    PROC_CMD_GOTO_SCR,
    PROC_CMD_SLEEP,
    PROC_CMD_MARK,
    PROC_CMD_BLOCK,
    PROC_CMD_END_IF_DUP,
    PROC_CMD_SET_FLAG2,
    PROC_CMD_13,
    PROC_CMD_WHILE,
    PROC_CMD_15,
    PROC_CMD_CALL_2,
    PROC_CMD_END_DUPS,
    PROC_CMD_CALL_ARG,
    PROC_CMD_19,
};

#define PROC_END                          { PROC_CMD_END, 0, 0 }
#define PROC_NAME(nameStr)                { PROC_CMD_NAME, 0, (nameStr) }
#define PROC_CALL(func)                   { PROC_CMD_CALL, 0, (func) }
#define PROC_REPEAT(func)                 { PROC_CMD_REPEAT, 0, (func) }
#define PROC_ONEND(func)                  { PROC_CMD_ONEND, 0, (func) }
#define PROC_START_CHILD(procscr)         { PROC_CMD_START_CHILD, 0, (procscr) }
#define PROC_START_CHILD_LOCKING(procscr) { PROC_CMD_START_CHILD_BLOCKING, 1, (procscr) }
#define PROC_START_BUGGED(procscr)        { PROC_CMD_START_BUGGED, 0, (procscr) }
#define PROC_WHILE_EXISTS(procscr)        { PROC_CMD_WHILE_EXISTS, 0, (procscr) }
#define PROC_END_EACH(procscr)            { PROC_CMD_END_EACH, 0, (procscr) }
#define PROC_BREAK_EACH(procscr)          { PROC_CMD_BREAK_EACH, 0, (procscr) }
#define PROC_LABEL(label)                 { PROC_CMD_LABEL, (label), 0 }
#define PROC_GOTO(label)                  { PROC_CMD_GOTO, (label), 0 }
#define PROC_GOTO_SCR(procscr)            { PROC_CMD_GOTO_SCR, 0, (procscr) }
#define PROC_SLEEP(duration)              { PROC_CMD_SLEEP, (duration), 0 }
#define PROC_MARK(mark)                   { PROC_CMD_MARK, (mark), 0 }
#define PROC_BLOCK                        { PROC_CMD_BLOCK, 0, 0 }
#define PROC_END_IF_DUP                   { PROC_CMD_END_IF_DUP, 0, 0 }
#define PROC_SET_FLAG2                    { PROC_CMD_SET_FLAG2, 0, 0 }
#define PROC_13                           { PROC_CMD_13, 0, 0 }
#define PROC_WHILE(func)                  { PROC_CMD_WHILE, 0, (func) }
#define PROC_15                           { PROC_CMD_15, 0, 0 }
#define PROC_CALL_2(func)                 { PROC_CMD_CALL_2, 0, (func) }
#define PROC_END_DUPS                     { PROC_CMD_END_DUPS, 0, 0 }
#define PROC_CALL_ARG(func, arg)          { PROC_CMD_CALL_ARG, (arg), (func) }
#define PROC_19                           { PROC_CMD_19, 0, 0 }

#define PROC_HEADER_EXT(parent_type)                                                                    \
    /* 00 */ struct ProcScr const * proc_script; /* pointer to proc script */                           \
    /* 04 */ struct ProcScr const * proc_script_pc; /* pointer to currently executing script command */ \
    /* 08 */ ProcFunc proc_end_func; /* callback to run upon delegint the process */                    \
    /* 0C */ ProcFunc proc_repeat_func; /* callback to run once each frame. */                          \
                                        /* disables script execution when not null */                   \
    /* 10 */ char const * proc_name;                                                                    \
    /* 14 */ parent_type * proc_parent; /* pointer to parent proc. If this proc is a root proc, */      \
                                  /* this member is an integer which is the root index. */              \
    /* 18 */ ProcPtr proc_child; /* pointer to most recently added child */                             \
    /* 1C */ ProcPtr proc_next; /* next sibling */                                                      \
    /* 20 */ ProcPtr proc_prev; /* previous sibling */                                                  \
    /* 24 */ i16 proc_sleep_clock;                                                                      \
    /* 26 */ u8 proc_mark;                                                                              \
    /* 27 */ u8 proc_flags;                                                                             \
    /* 28 */ u8 proc_lock_cnt; /* wait semaphore. Process execution */                                  \
                               /* is blocked when this is nonzero. */                                   \

#define PROC_HEADER PROC_HEADER_EXT(void)

// TODO: stop using this
// this is just lazy bad
struct GenericProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ int x, y;
    /* 34 */ int unk34;
    /* 38 */ int unk38;
    /* 3C */ int unk3C;
    /* 40 */ int unk40;

    /* 44 */ u8 pad_38[0x4A - 0x44];

    /* 4A */ short unk4A;

    // Is this part of that?
    /* 4C */ short unk4C; 
    /* 4E */ short unk4E;
    /* 50 */ short unk50;

    /* 52 */ u16 unk52;

    /* 54 */ void * ptr;
    /* 58 */ int unk58;
    /* 5C */ int unk5C;
    /* 60 */ int unk60;
    /* 64 */ short unk64;
    /* 66 */ short unk66;
    /* 68 */ short unk68;
    /* 6A */ short unk6A;
};

#define PROC_TREE_VSYNC ((ProcPtr) 0)
#define PROC_TREE_1     ((ProcPtr) 1)
#define PROC_TREE_2     ((ProcPtr) 2)
#define PROC_TREE_3     ((ProcPtr) 3)
#define PROC_TREE_4     ((ProcPtr) 4)
#define PROC_TREE_5     ((ProcPtr) 5)
#define PROC_TREE_6     ((ProcPtr) 6)
#define PROC_TREE_7     ((ProcPtr) 7)

enum
{
    PROC_MARK_1 = 1,
    PROC_MARK_2 = 2,
    PROC_MARK_MU = 4,
    PROC_MARK_5 = 5,
    PROC_MARK_6 = 6,
    PROC_MARK_7 = 7,
    PROC_MARK_8 = 8,
    PROC_MARK_10 = 10,
    PROC_MARK_GAMECTRL = 11,
};

extern ProcPtr gProcTreeRootArray[8];

void InitProcs(void);
ProcPtr SpawnProc(struct ProcScr const * scr, ProcPtr parent);
ProcPtr SpawnProcLocking(struct ProcScr const * scr, ProcPtr parent);
void Proc_End(ProcPtr proc);
void Proc_Run(ProcPtr proc);
void Proc_Break(ProcPtr proc);
ProcPtr FindProc(struct ProcScr const * script);
ProcPtr FindActiveProc(struct ProcScr const * script);
ProcPtr FindMarkedProc(int mark);
void Proc_Goto(ProcPtr proc, int label);
void Proc_GotoScript(ProcPtr proc, struct ProcScr const * script);
void Proc_Mark(ProcPtr proc, int mark);
void Proc_SetEndFunc(ProcPtr proc, ProcFunc func);
void Proc_ForAll(ProcFunc func);
void Proc_ForEach(struct ProcScr const * script, ProcFunc func);
void Proc_ForEachMarked(int mark, ProcFunc func);
void Proc_LockEachMarked(int mark);
void Proc_ReleaseEachMarked(int mark);
void Proc_EndEachMarked(int mark);
void Proc_EndEach(struct ProcScr const * script);
void Proc_BreakEach(struct ProcScr const * script);
void Proc_ForSubtree(ProcPtr proc, ProcFunc func);
void Proc_PrintSubtreeInfo(ProcPtr proc);
void Proc_SetRepeatFunc(ProcPtr proc, ProcFunc func);
void Proc_Lock(ProcPtr proc);
void Proc_Release(ProcPtr proc);

#define Proc_Exists(script) (FindProc((script)) ? TRUE : FALSE)
