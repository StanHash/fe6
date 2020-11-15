
#include "ai-decide.h"

#include "unit.h"
#include "map.h"
#include "faction.h"
#include "unitsprite.h"
#include "action.h"
#include "ai-perform.h"
#include "ai-utility.h"

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

    sub_80857B0(SAVE_ID_SUSPEND0);
}

void AiDecide_NextUnit(ProcPtr proc)
{
next_unit:
    gAiSt.decideState = 0;

    if (*gAiSt.unitIt != 0)
    {
        gAiSt.unk_7C = 0;

        gActiveUnitId = *gAiSt.unitIt;
        gActiveUnit = GetUnit(gActiveUnitId);

        if ((gActiveUnit->state & (US_TURN_ENDED | US_DEAD)) || !gActiveUnit->person)
        {
            gAiSt.unitIt++;
            goto next_unit;
        }

        RefreshEntityMaps();
        RenderMap();
        RefreshUnitSprites();

        sub_8035064(gActiveUnit);

        gAiSt.combatWeightTableId = (gActiveUnit->aiConfig & 0xF8) >> 3;

        gAiSt.dangerMapFilled = FALSE;
        sub_80326C4();

        AiClearDecision();
        AiDecideFunc();

        gActiveUnit->state |= US_HAS_MOVED_AI;

        if (!gAiDecision.actionPerformed ||
            (gActiveUnit->x == gAiDecision.xMove && gActiveUnit->y == gAiDecision.yMove && gAiDecision.actionId == AI_ACTION_NONE))
        {
            // Ignoring actions that are just moving to the same square

            gAiSt.unitIt++;
            Proc_Goto(proc, 0);
        }
        else
        {
            gAiSt.unitIt++;
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
    gAiDecision.actionId = AI_ACTION_NONE;

    gAiDecision.unitId = 0;
    gAiDecision.xMove = 0;
    gAiDecision.yMove = 0;
    gAiDecision.unk04 = 0;
    gAiDecision.unk05 = 0;
    gAiDecision.targetId = 0;
    gAiDecision.itemSlot = 0;
    gAiDecision.xTarget = 0;
    gAiDecision.yTarget = 0;

    gAiDecision.actionPerformed = FALSE;
}

void AiSetDecision(short xMove, short yMove, u8 actionId, u8 targetId, u8 itemSlot, u8 xTarget, u8 yTarget)
{
    gAiDecision.unitId = gActiveUnitId;
    gAiDecision.xMove = xMove;
    gAiDecision.yMove = yMove;

    gAiDecision.actionId = actionId;

    gAiDecision.targetId = targetId;
    gAiDecision.itemSlot = itemSlot;
    gAiDecision.xTarget = xTarget;
    gAiDecision.yTarget = yTarget;

    gAiDecision.actionPerformed = TRUE;
}

void AiUpdateDecision(u8 actionId, u8 targetId, u8 itemSlot, u8 xTarget, u8 yTarget)
{
    if (actionId != 0xFF)
        gAiDecision.actionId = actionId;

    if (targetId != 0xFF)
        gAiDecision.targetId = targetId;

    if (itemSlot != 0xFF)
        gAiDecision.itemSlot = itemSlot;

    if (xTarget != 0xFF)
        gAiDecision.xTarget = xTarget;

    if (yTarget != 0xFF)
        gAiDecision.yTarget = yTarget;

    gAiDecision.actionPerformed = TRUE;
}

void AiDecideAll(void)
{
    while (sAllDecideFuncs[gAiSt.decideState] && !gAiDecision.actionPerformed)
    {
        sAllDecideFuncs[gAiSt.decideState++]();
    }
}

void AiDecideHealOrEscape(void)
{
    if (gAiSt.flags & AI_FLAG_BERSERKED)
        return;

    if (AiUpdateGetUnitIsHealing(gActiveUnit) == TRUE)
    {
        struct Vec2 position;

        if (AiTryHealSelf() == TRUE)
            return;

        if ((gActiveUnit->aiFlags & AI_UNIT_FLAG_3) && (AiTryMoveTowardsEscape() == TRUE))
        {
            AiTryDanceOrStealAfterMove();
            return;
        }

        if (AiTryGetNearestHealPoint(&position) != TRUE)
            return;

        AiTryMoveTowards(position.x, position.y, 0, 0, 1);

        if (gAiDecision.actionPerformed == TRUE)
            AiTryActionAfterMove();
    }
    else
    {
        if ((gActiveUnit->aiFlags & AI_UNIT_FLAG_3) && (AiTryMoveTowardsEscape() == TRUE))
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
