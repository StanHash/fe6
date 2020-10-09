
#include "ai-order.h"

#include "hardware.h"

u8* CONST_DATA gUnk_085C8494 = gBuf;

void sub_802E59C(ProcPtr proc);

struct ProcScr CONST_DATA ProcScr_AiOrder[] =
{
    PROC_19,
    PROC_REPEAT(sub_802E59C),
    PROC_END,
};

void sub_802E5C4(ProcPtr proc);
void sub_802E8D4(ProcPtr proc);

struct ProcScr CONST_DATA ProcScr_AiOrder_Berserk[] =
{
    PROC_19,
    PROC_CALL(sub_802E5C4),
    PROC_REPEAT(sub_802E8D4),
    PROC_END,
};
