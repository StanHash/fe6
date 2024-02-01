#include "ai_phase.h"

#include "bm.h"
#include "ai_order.h"
#include "ai_utility.h"
#include "ai_data.h"
#include "ai_unk.h"

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
    gAiSt.danger_threshold = -1;

    gAiSt.order_state = 0;

    for (i = 0; i < 8; ++i)
        gAiSt.cmd_result[i] = 0;

    gAiSt.special_item_flags = AiItemConfigTable[gPlaySt.chapter];
    gAiSt.unk_84 = 0;

    AiUpdateUnitsSeekHealing();
    func_fe6_080308B0();

    SpawnProcLocking(ProcScr_AiOrder, proc);
}

static void AiPhase_Berserk_Begin(ProcPtr proc)
{
    int i;

    gAiSt.flags = AI_FLAG_BERSERKED;
    gAiSt.danger_threshold = -1;

    for (i = 0; i < 8; ++i)
        gAiSt.cmd_result[i] = 0;

    gAiSt.special_item_flags = AiItemConfigTable[gPlaySt.chapter];

    AiUpdateUnitsSeekHealing();
    func_fe6_080308B0();

    SpawnProcLocking(ProcScr_AiOrder_Berserk, proc);
}

static void AiPhase_Finish(ProcPtr proc)
{
    gAiSt.flags = AI_FLAGS_NONE;
}
