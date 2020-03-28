
#include "gba/gba.h"

#include "proc.h"

#include "unks.h"

void sub_800CAA0(struct GenericProc* proc);
void sub_800CAB8(struct GenericProc* proc);
void sub_800CAD4(struct GenericProc* proc);

struct ProcScr CONST_DATA ProcScr_Unk_085C3F98[] =
{
    PROC_CALL(LockGame),
    PROC_SLEEP(1),

    PROC_CALL(sub_800CAA0),
    PROC_SLEEP(1),

    PROC_CALL(sub_800CAB8),
    PROC_REPEAT(sub_800CAD4),

    PROC_CALL(UnlockGame),
    PROC_END,
};

s8 sub_800CA4C(void)
{
    return Proc_Exists(ProcScr_Unk_085C3F98);
}

void sub_800CA70(void)
{
    SpawnProc(ProcScr_Unk_085C3F98, PROC_TREE_3);
}

void sub_800CA88(struct GenericProc* proc)
{
    proc->unk34 = 1;
}
