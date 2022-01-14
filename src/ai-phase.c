
#include "ai-phase.h"

#include "bm.h"
#include "ai-order.h"
#include "ai-utility.h"
#include "ai-data.h"

struct AiSt EWRAM_DATA gAiSt = {};

static void AiPhase_Begin(ProcPtr proc);
static void AiPhase_Finish(ProcPtr proc);

struct ProcScr CONST_DATA ProcScr_AiPhase[] =
{
    PROC_19,

    PROC_CALL(AiPhase_Begin),
    PROC_SLEEP(0),

    PROC_CALL(AiPhase_Finish),

    PROC_END,
};

static void AiPhase_Berserk_Begin(ProcPtr proc);

struct ProcScr CONST_DATA ProcScr_AiPhase_Berserk[] =
{
    PROC_19,

    PROC_CALL(AiPhase_Berserk_Begin),
    PROC_SLEEP(0),

    PROC_CALL(AiPhase_Finish),

    PROC_END,
};

static void AiPhase_Begin(ProcPtr proc)
{
    int i;

    gAiSt.flags = AI_FLAG_0;
    gAiSt.unk_7E = -1;

    gAiSt.order_state = 0;

    for (i = 0; i < 8; ++i)
        gAiSt.cmd_result[i] = 0;

    gAiSt.special_item_flags = AiItemConfigTable[gPlaySt.chapter];
    gAiSt.unk_84 = 0;

    func_fe6_08032A08();
    func_fe6_080308B0();

    SpawnProcLocking(ProcScr_AiOrder, proc);
}

static void AiPhase_Berserk_Begin(ProcPtr proc)
{
    int i;

    gAiSt.flags = AI_FLAG_BERSERKED;
    gAiSt.unk_7E = -1;

    for (i = 0; i < 8; ++i)
        gAiSt.cmd_result[i] = 0;

    gAiSt.special_item_flags = AiItemConfigTable[gPlaySt.chapter];

    func_fe6_08032A08();
    func_fe6_080308B0();

    SpawnProcLocking(ProcScr_AiOrder_Berserk, proc);
}

static void AiPhase_Finish(ProcPtr proc)
{
    gAiSt.flags = AI_FLAGS_NONE;
}
