
#pragma once

#include "gba/gba.h"
#include "types.h"

typedef void* ProcPtr;
typedef void(*ProcFunc)(ProcPtr proc);

struct ProcScr
{
    short opcode;
    short dataImm;
    void const* dataPtr;
};

#define PROC_END                                     { 0x00, 0x0000, 0 }
#define PROC_NAME(aName)                             { 0x01, 0x0000, (aName) }
#define PROC_CALL(apRoutine)                         { 0x02, 0x0000, (apRoutine) }
#define PROC_REPEAT(apRoutine)                       { 0x03, 0x0000, (apRoutine) }
#define PROC_SET_END_FUNC(apRoutine)                 { 0x04, 0x0000, (apRoutine) }
#define PROC_START_CHILD(ap6CChild)                  { 0x05, 0x0000, (ap6CChild) }
#define PROC_START_CHILD_BLOCKING(ap6CChild)         { 0x06, 0x0001, (ap6CChild) }
#define PROC_START_MAIN_BUGGED(ap6CMain)             { 0x07, 0x0000, (ap6CMain) }
#define PROC_WHILE_EXISTS(ap6CToCheck)               { 0x08, 0x0000, (ap6CToCheck) }
#define PROC_END_EACH(ap6CToCheck)                   { 0x09, 0x0000, (ap6CToCheck) }
#define PROC_BREAK_EACH(ap6CToCheck)                 { 0x0A, 0x0000, (ap6CToCheck) }
#define PROC_LABEL(aLabelId)                         { 0x0B, (aLabelId), 0 }
#define PROC_GOTO(aLabelId)                          { 0x0C, (aLabelId), 0 }
#define PROC_JUMP(ap6CCode)                          { 0x0D, 0x0000, (ap6CCode) }
#define PROC_SLEEP(aTime)                            { 0x0E, (aTime), 0 }
#define PROC_MARK(aMark)                             { 0x0F, (aMark), 0 }
#define PROC_BLOCK                                   { 0x10, 0x0000, 0 }
#define PROC_END_IF_DUPLICATE                        { 0x11, 0x0000, 0 }
#define PROC_SET_BIT4                                { 0x12, 0x0000, 0 }
#define PROC_13                                      { 0x13, 0x0000, 0 }
#define PROC_WHILE(aprRoutine)                       { 0x14, 0x0000, (aprRoutine) }
#define PROC_15                                      { 0x15, 0x0000, 0 }
#define PROC_CALL_2(aprRoutine)                      { 0x16, 0x0000, (aprRoutine) }
#define PROC_END_DUPLICATES                          { 0x17, 0x0000, 0 }
#define PROC_CALL_ARG(aprRoutine, aArgument)         { 0x18, (aArgument), (aprRoutine) }
#define PROC_19                                      { 0x19, 0x0000, 0 }

#define PROC_HEADER                                                                        \
    const struct ProcCmd* proc_script; /* pointer to proc script */                        \
    const struct ProcCmd* proc_scrCur; /* pointer to currently executing script command */ \
    ProcFunc proc_endFunc; /* callback to run upon delegint the process */                 \
    ProcFunc proc_idleFunc; /* callback to run once each frame. */                         \
                          /* disables script execution when not null */                    \
    const char* proc_name;                                                                 \
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

#define PROC_TREE_VSYNC ((ProcPtr) 0)
#define PROC_TREE_1     ((ProcPtr) 1)
#define PROC_TREE_2     ((ProcPtr) 2)
#define PROC_TREE_3     ((ProcPtr) 3)
#define PROC_TREE_4     ((ProcPtr) 4)
#define PROC_TREE_5     ((ProcPtr) 5)
#define PROC_TREE_6     ((ProcPtr) 6)
#define PROC_TREE_7     ((ProcPtr) 7)

ProcPtr Proc_Create(struct ProcScr const* scr, ProcPtr parent);
ProcPtr Proc_CreateBlockingChild(struct ProcScr const* scr, ProcPtr parent);
void Proc_Delete(ProcPtr proc);
void Proc_Break(ProcPtr proc);
