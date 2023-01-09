#include "ai_decide.h"

#include "unit.h"
#include "map.h"
#include "faction.h"
#include "unitsprite.h"
#include "action.h"
#include "save.h"
#include "ai_perform.h"
#include "ai_utility.h"
#include "ai_script.h"

struct AiDecision EWRAM_DATA gAiDecision = {};

static Func CONST_DATA sAllDecideFuncs[] =
{
    AiDecideHealOrEscape,
    AiDecideScriptA,
    AiDecideScriptB,
    AiDecideSpecialItems,
    NULL, NULL,
};

static Func CONST_DATA sAllDecideFuncsUnused[] =
{
    AiDecideSpecialItems,
    AiDecideScriptA,
    AiDecideHealOrEscape,
    AiDecideScriptB,
    NULL, NULL,
};

static void AiDecide_NextUnit(ProcPtr proc);
static void AiDecide_Suspend(ProcPtr proc);

struct ProcScr CONST_DATA ProcScr_AiDecide[] =
{
    PROC_19,

PROC_LABEL(0),
    PROC_CALL(AiDecide_NextUnit),
    PROC_SLEEP(0),

    PROC_CALL(AiDecide_Suspend),

    PROC_GOTO(0),

    PROC_END,
};

void AiDecide_Suspend(ProcPtr proc)
{
    if (UNIT_FACTION(gActiveUnit) == FACTION_BLUE)
        gAction.suspendPoint = SUSPEND_POINT_BERSERK_PHASE;
    else
        gAction.suspendPoint = SUSPEND_POINT_AI_PHASE;

    func_fe6_080857B0(SAVE_ID_SUSPEND0);
}

void AiDecide_NextUnit(ProcPtr proc)
{
next_unit:
    gAiSt.decide_state = 0;

    if (*gAiSt.unit_it != 0)
    {
        gAiSt.unk_7C = 0;

        gActiveUnitId = *gAiSt.unit_it;
        gActiveUnit = GetUnit(gActiveUnitId);

        if ((gActiveUnit->flags & (UNIT_FLAG_TURN_ENDED | UNIT_FLAG_DEAD)) || !gActiveUnit->pinfo)
        {
            gAiSt.unit_it++;
            goto next_unit;
        }

        RefreshEntityMaps();
        RenderMap();
        RefreshUnitSprites();

        func_fe6_08035064(gActiveUnit);

        gAiSt.combat_wgt_table_id = (gActiveUnit->ai_config & 0xF8) >> 3;

        gAiSt.danger_map_filled = FALSE;
        AiRefreshDangerMap();

        AiClearDecision();
        AiDecideFunc();

        gActiveUnit->flags |= UNIT_FLAG_AI_PROCESSED;

        if (!gAiDecision.action_performed ||
            (gActiveUnit->x == gAiDecision.x_move && gActiveUnit->y == gAiDecision.y_move && gAiDecision.action_id == AI_ACTION_NONE))
        {
            // Ignoring actions that are just moving to the same square

            gAiSt.unit_it++;
            Proc_Goto(proc, 0);
        }
        else
        {
            gAiSt.unit_it++;
            SpawnProcLocking(ProcScr_AiPerform, proc);
        }
    }
    else
    {
        Proc_End(proc);
    }
}

void AiClearDecision(void)
{
    gAiDecision.action_id = AI_ACTION_NONE;

    gAiDecision.unit_id = 0;
    gAiDecision.x_move = 0;
    gAiDecision.y_move = 0;
    gAiDecision.unk_04 = 0;
    gAiDecision.unk_05 = 0;
    gAiDecision.target_id = 0;
    gAiDecision.item_slot = 0;
    gAiDecision.x_target = 0;
    gAiDecision.y_target = 0;

    gAiDecision.action_performed = FALSE;
}

void AiSetDecision(short x_move, short y_move, u8 action_id, u8 target_id, u8 item_slot, u8 x_target, u8 y_target)
{
    gAiDecision.unit_id = gActiveUnitId;
    gAiDecision.x_move = x_move;
    gAiDecision.y_move = y_move;

    gAiDecision.action_id = action_id;

    gAiDecision.target_id = target_id;
    gAiDecision.item_slot = item_slot;
    gAiDecision.x_target = x_target;
    gAiDecision.y_target = y_target;

    gAiDecision.action_performed = TRUE;
}

void AiUpdateDecision(u8 action_id, u8 target_id, u8 item_slot, u8 x_target, u8 y_target)
{
    if (action_id != 0xFF)
        gAiDecision.action_id = action_id;

    if (target_id != 0xFF)
        gAiDecision.target_id = target_id;

    if (item_slot != 0xFF)
        gAiDecision.item_slot = item_slot;

    if (x_target != 0xFF)
        gAiDecision.x_target = x_target;

    if (y_target != 0xFF)
        gAiDecision.y_target = y_target;

    gAiDecision.action_performed = TRUE;
}

void AiDecideAll(void)
{
    while (sAllDecideFuncs[gAiSt.decide_state] && !gAiDecision.action_performed)
    {
        sAllDecideFuncs[gAiSt.decide_state++]();
    }
}

void AiDecideHealOrEscape(void)
{
    if (gAiSt.flags & AI_FLAG_BERSERKED)
        return;

    if (AiUpdateGetUnitIsHealing(gActiveUnit) == TRUE)
    {
        struct Vec2i position;

        if (AiTryHealSelf() == TRUE)
            return;

        if ((gActiveUnit->ai_flags & AI_UNIT_FLAG_3) && (AiTryMoveTowardsEscape() == TRUE))
        {
            AiTryDanceOrStealAfterMove();
            return;
        }

        if (AiTryGetNearestHealPoint(&position) != TRUE)
            return;

        AiTryMoveTowards(position.x, position.y, 0, 0, 1);

        if (gAiDecision.action_performed == TRUE)
            AiTryActionAfterMove();
    }
    else
    {
        if ((gActiveUnit->ai_flags & AI_UNIT_FLAG_3) && (AiTryMoveTowardsEscape() == TRUE))
            AiTryDanceOrStealAfterMove();
    }
}

void AiDecideSpecialItems(void)
{
    if (gAiSt.flags & AI_FLAG_BERSERKED)
        return;

    AiTryDoSpecialItems();
}

void AiDecideScriptA(void)
{
    int i = 0;

    if (gAiSt.flags & AI_FLAG_BERSERKED)
    {
        AiDoBerserkAction();
        return;
    }

    for (i = 0; i < 0x100; ++i)
    {
        if (AiTryExecScriptA() == TRUE)
            return;
    }

    AiExecFallbackScriptA();
}

void AiDecideScriptB(void)
{
    int i = 0;

    if (gAiSt.flags & AI_FLAG_BERSERKED)
    {
        AiDoBerserkMove();
        return;
    }

    for (i = 0; i < 0x100; ++i)
    {
        if (AiTryExecScriptB() == TRUE)
            return;
    }

    AiExecFallbackScriptB();
}
