
#include "ai-script.h"

#include "random.h"
#include "unit.h"
#include "mapwork.h"
#include "faction.h"
#include "ai-decide.h"
#include "ai-utility.h"
#include "ai-data.h"
#include "ai-battle.h"

enum ScriptKind
{
    AI_SCRIPT_A,
    AI_SCRIPT_B,
};

typedef void(*AiScrCmd)(u8* pc);

static void AiDoExecScript(u8* pc);

static void AiCmd_Conditional(u8* pc);
static void AiCmd_CallFunc(u8* pc);
static void AiCmd_SetAi(u8* pc);
static void AiCmd_Goto(u8* pc);
static void AiCmd_ActionOnPid(u8* pc);
static void AiCmd_Action(u8* pc);
static void AiCmd_Nop(u8* pc);
static void AiCmd_ActionInPlace(u8* pc);
static void AiCmd_ActionOnJid(u8* pc);
static void AiCmd_StaffAction(u8* pc);
static void AiCmd_StaffAction2(u8* pc);
static void AiCmd_StaffAction3(u8* pc);
static void AiCmd_MoveTowards(u8* pc);
static void AiCmd_MoveTowardsPid(u8* pc);
static void AiCmd_Nop_080314B8(u8* pc);
static void AiCmd_MoveTowardsJid(u8* pc);
static void AiCmd_Pillage(u8* pc);
static void AiCmd_MoveToSafety(u8* pc);
static void AiCmd_MoveToEnemy(u8* pc);
static void AiCmd_MoveToEnemy2(u8* pc);
static void AiCmd_Nop_08031740(u8* pc);
static void AiCmd_Nop_08031748(u8* pc);
static void AiCmd_MoveRandom(u8* pc);
static void AiCmd_Escape(u8* pc);
static void AiCmd_Nop_08031788(u8* pc);
static void AiCmd_MoveTowardsTerrain(u8* pc);
static void AiCmd_MoveTowardsListedTerrain(u8* pc);
static void AiCmd_Label(u8* pc);

static Bool sScrEnded;
static enum ScriptKind sScrKind;
static struct AiScr const* sScr;
static AiScrFunc sScrFunc;

Bool AiTryExecScriptA(void)
{
    sScr = gAiScriptLutA[0][gActiveUnit->aiA];
    sScr = sScr + gActiveUnit->aiApc;

    sScrEnded = TRUE;
    sScrKind = AI_SCRIPT_A;

    AiDoExecScript(&gActiveUnit->aiApc);

    return sScrEnded;
}

Bool AiExecFallbackScriptA(void)
{
    sScr = AiScr_FallbackA;

    sScrEnded = TRUE;
    sScrKind = AI_SCRIPT_A;

    AiDoExecScript(&gActiveUnit->aiApc);

    return sScrEnded;
}

Bool AiTryExecScriptB(void)
{
    sScr = gAiScriptLutB[0][gActiveUnit->aiB];
    sScr = sScr + gActiveUnit->aiBpc;

    sScrEnded = TRUE;
    sScrKind = AI_SCRIPT_B;

    AiDoExecScript(&gActiveUnit->aiBpc);

    return sScrEnded;
}

Bool AiExecFallbackScriptB(void)
{
    sScr = AiScr_FallbackB;

    sScrEnded = TRUE;
    sScrKind = AI_SCRIPT_B;

    AiDoExecScript(&gActiveUnit->aiBpc);

    return sScrEnded;
}

void AiDoExecScript(u8* pc)
{
    AiScrCmd funcLut[] =
    {
        [AI_CMD_CONDITIONAL]      = AiCmd_Conditional,
        [AI_CMD_CALL_FUNC]        = AiCmd_CallFunc,
        [AI_CMD_SET_AI]           = AiCmd_SetAi,
        [AI_CMD_GOTO]             = AiCmd_Goto,
        [AI_CMD_ACTION_ON_PID]    = AiCmd_ActionOnPid,
        [AI_CMD_ACTION]           = AiCmd_Action,
        [AI_CMD_NOP]              = AiCmd_Nop,
        [AI_CMD_ACTION_IN_PLACE]  = AiCmd_ActionInPlace,
        [AI_CMD_ACTION_ON_JID]    = AiCmd_ActionOnJid,
        [AI_CMD_STAFF_ACTION]     = AiCmd_StaffAction,
        [AI_CMD_STAFF_ACTION_2]   = AiCmd_StaffAction2,
        [AI_CMD_STAFF_ACTION_3]   = AiCmd_StaffAction3,
        [AI_CMD_MOVE_TOWARDS]     = AiCmd_MoveTowards,
        [AI_CMD_MOVE_TOWARDS_PID] = AiCmd_MoveTowardsPid,
        [AI_CMD_NOP_0E]           = AiCmd_Nop_080314B8,
        [AI_CMD_MOVE_TOWARDS_JID] = AiCmd_MoveTowardsJid,
        [AI_CMD_PILLAGE]          = AiCmd_Pillage,
        [AI_CMD_MOVE_TO_SAFETY]   = AiCmd_MoveToSafety,
        [AI_CMD_MOVE_TO_ENEMY]    = AiCmd_MoveToEnemy,
        [AI_CMD_MOVE_TO_ENEMY_2]  = AiCmd_MoveToEnemy2,
        [AI_CMD_NOP_14]           = AiCmd_Nop_08031740,
        [AI_CMD_NOP_15]           = AiCmd_Nop_08031748,
        [AI_CMD_MOVE_RANDOM]      = AiCmd_MoveRandom,
        [AI_CMD_ESCAPE]           = AiCmd_Escape,
        [AI_CMD_NOP_18]           = AiCmd_Nop_08031788,
        [AI_CMD_MOVE_TO_TERRAIN]  = AiCmd_MoveTowardsTerrain,
        [AI_CMD_MOVE_TO_LISTED_TERRAIN] = AiCmd_MoveTowardsListedTerrain,
        [AI_CMD_LABEL]            = AiCmd_Label,
    };

    if (sScr->cmd >= AI_CMD_COUNT)
    {
        // Invalid script, run fallback scripts

        if (sScrKind == AI_SCRIPT_A)
            sScr = AiScr_FallbackA;
        else
            sScr = AiScr_FallbackB;
    }

    gAiSt.unk_7E = sScr->unk_02;
    funcLut[sScr->cmd](pc);
}

void AiCmd_Conditional(u8* pc)
{
    u8 target = sScr->unk_03;
    u8 i = 0;

    if (AiCompare(sScr->unk_08, sScr->unk_01, sScr->unk_04) == TRUE)
    {
        struct AiScr const* scr;

        if (sScrKind == AI_SCRIPT_A)
        {
            scr = gAiScriptLutA[0][gActiveUnit->aiA];
        }
        else
        {
            scr = gAiScriptLutB[0][gActiveUnit->aiB];
        }

        if (target != 0)
        {
            while (scr[i].cmd != AI_CMD_LABEL || scr[i].unk_03 != target)
                ++i;

            *pc = i+1;
        }
        else
        {
            *pc = 0;
        }
    }
    else
    {
        (*pc)++;
    }

    sScrEnded = FALSE;
}

void AiCmd_CallFunc(u8* pc)
{
    sScrFunc = sScr->unk_08;

    sScrEnded = sScrFunc(sScr->unk_0C);
    (*pc)++;
}

void AiCmd_SetAi(u8* pc)
{
    u8 aiA = sScr->unk_01;
    u8 aiB = sScr->unk_02;

    if (aiA != UINT8_MAX)
    {
        gActiveUnit->aiA = aiA;
        gActiveUnit->aiApc = 0;
    }

    if (aiB != UINT8_MAX)
    {
        gActiveUnit->aiB = aiB;
        gActiveUnit->aiBpc = 0;
    }

    if ((sScrKind == AI_SCRIPT_A && aiA == UINT8_MAX) || (sScrKind == AI_SCRIPT_B && aiB == UINT8_MAX))
        (*pc)++;

    gAiSt.decideState = 0;
}

void AiCmd_Goto(u8* pc)
{
    struct AiScr const* scr;

    u8 target = sScr->unk_03;
    u8 i = 0;

    if (sScrKind == AI_SCRIPT_A)
    {
        scr = gAiScriptLutA[0][gActiveUnit->aiA];
    }
    else
    {
        scr = gAiScriptLutB[0][gActiveUnit->aiB];
    }

    if (target != 0)
    {
        while (scr[i].cmd != AI_CMD_LABEL || scr[i].unk_03 != target)
            ++i;

        *pc = i+1;
    }
    else
    {
        *pc = 0;
    }

    sScrEnded = FALSE;
}

Bool AiIsUnitEnemy(struct Unit* unit)
{
    if (AreUnitIdsAllied(gActiveUnit->id, unit->id))
        return FALSE;

    return TRUE;
}

Bool AiIsUnitNonActive(struct Unit* unit)
{
    if (unit == gActiveUnit)
        return FALSE;

    return TRUE;
}

Bool AiIsUnitEnemyAndNotInScrList(struct Unit* unit)
{
    if (AiIsInShortList(sScr->unk_08, unit->person->id) != TRUE && !AreUnitIdsAllied(gActiveUnit->id, unit->id))
        return TRUE;

    return FALSE;
}

Bool AiIsUnitEnemyOrInScrList(struct Unit* unit)
{
    if (AiIsInShortList(sScr->unk_08, unit->person->id) == TRUE || !AreUnitIdsAllied(gActiveUnit->id, unit->id))
        return TRUE;

    return FALSE;
}

Bool AiIsUnitEnemyAndScrPid(struct Unit* unit)
{
    if (unit->person->id == ((u8) sScr->unk_04) && !AreUnitIdsAllied(gActiveUnit->id, unit->id))
        return TRUE;

    return FALSE;
}

Bool AiIsUnitEnemyAndScrJid(struct Unit* unit)
{
    if (unit->job->id == ((u8) sScr->unk_04) && !AreUnitIdsAllied(gActiveUnit->id, unit->id))
        return TRUE;

    return FALSE;
}

void AiCmd_ActionOnPid(u8* pc)
{
    u8 rand = RandNext(100);

    if (rand <= sScr->unk_01)
    {
        if (!sub_8033C04(AiIsUnitEnemy))
        {
            if (AiUnitWithPidExists(sScr->unk_04) == TRUE)
            {
                if (GetUnitByPid(sScr->unk_04)->state & US_RESCUED)
                {
                    gAiSt.unk_86[0] = 3;
                    sScrEnded = FALSE;
                }
                else
                {
                    AiAttemptOffensiveAction(AiIsUnitEnemyAndScrPid);
                }
            }
            else
            {
                gAiSt.unk_86[0] = 1;
                sScrEnded = FALSE;
            }
        }
    }
    else
    {
        gAiSt.decideState = 4;
    }

    (*pc)++;
}

void AiCmd_Action(u8* pc)
{
    u8 rand = RandNext(100);

    if (rand <= sScr->unk_01)
    {
        if (sScr->unk_08 == NULL)
        {
            if (!sub_8033C04(AiIsUnitEnemy))
                AiAttemptOffensiveAction(AiIsUnitEnemy);
        }
        else
        {
            if (!sub_8033C04(AiIsUnitEnemyOrInScrList))
                AiAttemptOffensiveAction(AiIsUnitEnemyAndNotInScrList);
        }
    }
    else
    {
        gAiSt.decideState = 4;
    }

    (*pc)++;
}

void AiCmd_Nop(u8* pc)
{
    (*pc)++;
}

void AiCmd_ActionInPlace(u8* pc)
{
    u8 rand = RandNext(100);

    if (rand <= sScr->unk_01)
    {
        gAiSt.flags |= AI_FLAG_1;

        if (!sub_8033C04(AiIsUnitEnemy))
            AiAttemptOffensiveAction(AiIsUnitEnemy);
    }
    else
    {
        gAiSt.decideState = 4;
    }

    (*pc)++;
}

void AiCmd_ActionOnJid(u8* pc)
{
    u8 rand = RandNext(100);

    if (rand <= sScr->unk_01)
    {
        if (!sub_8033C04(AiIsUnitEnemyAndScrJid))
            AiAttemptOffensiveAction(AiIsUnitEnemyAndScrJid);
    }
    else
    {
        gAiSt.decideState = 4;
    }

    (*pc)++;
}

void AiCmd_StaffAction(u8* pc)
{
    sub_8033C04(AiIsUnitEnemy);
    (*pc)++;
}

void AiCmd_StaffAction2(u8* pc)
{
    sub_8033C04(AiIsUnitEnemy);
    (*pc)++;
}

void AiCmd_StaffAction3(u8* pc)
{
    sub_8033C04(AiIsUnitEnemy);
    (*pc)++;
}

void AiCmd_MoveTowards(u8* pc)
{
    AiTryMoveTowards(
        sScr->unk_01, sScr->unk_03,
        AI_ACTION_NONE, sScr->unk_02, TRUE);

    if (gAiDecision.actionPerformed == TRUE)
        if (gAiDecision.xMove == sScr->unk_01)
            if (gAiDecision.yMove == sScr->unk_03)
                (*pc)++;
}

void AiCmd_MoveTowardsPid(u8* pc)
{
    struct Vec2 pos;

    if (AiFindTargetInReachByPid(sScr->unk_04, &pos) == TRUE)
    {
        AiTryMoveTowards(pos.x, pos.y, AI_ACTION_NONE, sScr->unk_02, TRUE);

        if (AiIsWithinRectDistance(pos.x, pos.y, gAiDecision.xMove, gAiDecision.yMove, 1) == TRUE)
        {
            struct Unit* unit = GetUnitByPid(sScr->unk_04);

            if (unit->state & US_RESCUED)
            {
                gAiSt.unk_86[0] = 3;
            }
            else
            {
                AiUpdateDecision(0, 0, 0, 0, unit->id);

                gAiSt.unk_86[0] = 2;
                gAiDecision.actionPerformed = FALSE;
                sScrEnded = FALSE;
            }
        }
    }
    else
    {
        sScrEnded = FALSE;
    }

    (*pc)++;
}

void AiCmd_Nop_080314B8(u8* pc)
{
    (*pc)++;
}

void AiCmd_MoveTowardsJid(u8* pc)
{
    struct Vec2 pos;

    if (AiFindTargetInReachByJid(sScr->unk_04, &pos) == TRUE)
    {
        AiTryMoveTowards(pos.x, pos.y, AI_ACTION_NONE, sScr->unk_02, TRUE);
    }

    (*pc)++;
}

void AiCmd_Pillage(u8* pc)
{
    if (AiTryDoSpecialItems() == TRUE)
    {
        if (sScr->unk_03 != 0)
        {
            gActiveUnit->unk_46++;

            if (gActiveUnit->unk_46 == sScr->unk_03)
            {
                (*pc)++;
                sScrEnded = FALSE;
            }
        }
    }
    else
    {
        struct Vec2 pos;
        u8 itemSlot;

        if (AiFindPillageLocation(&pos, &itemSlot) == TRUE)
        {
            AiTryMoveTowards(pos.x, pos.y, AI_ACTION_NONE, -1, TRUE);

            if (AiLocationIsPillageTarget(gAiDecision.xMove, gAiDecision.yMove) == TRUE)
            {
                AiSetDecision(gAiDecision.xMove, gAiDecision.yMove, AI_ACTION_PILLAGE, 0, itemSlot, 0, 0);

                if (sScr->unk_03 != 0)
                {
                    gActiveUnit->unk_46++;

                    if (gActiveUnit->unk_46 == sScr->unk_03)
                    {
                        (*pc)++;
                        sScrEnded = FALSE;
                    }
                }
            }
        }
        else
        {
            (*pc)++;
            sScrEnded = FALSE;
        }
    }
}

void AiCmd_MoveToSafety(u8* pc)
{
    struct Vec2 pos;

    if (AiFindSafestReachableLocation(gActiveUnit, &pos) == TRUE)
    {
        AiSetDecision(pos.x, pos.y, AI_ACTION_NONE, 0, 0, 0, 0);
    }

    (*pc)++;
}

void AiCmd_MoveToEnemy(u8* pc)
{
    struct Vec2 pos;

    if (sScr->unk_08 == NULL)
    {
        if (AiFindTargetInReachByFunc(AiIsUnitEnemy, &pos) == TRUE)
        {
            AiTryMoveTowards(pos.x, pos.y, AI_ACTION_NONE, sScr->unk_02, TRUE);
        }
    }
    else
    {
        if (AiFindTargetInReachByFunc(AiIsUnitEnemyAndNotInScrList, &pos) == TRUE)
        {
            AiTryMoveTowards(pos.x, pos.y, AI_ACTION_NONE, sScr->unk_02, TRUE);
        }
    }

    (*pc)++;
}

void AiCmd_MoveToEnemy2(u8* pc)
{
    struct Vec2 pos;

    if (sScr->unk_08 == NULL)
    {
        if (AiFindTargetInReachByFunc(AiIsUnitEnemy, &pos) == TRUE)
        {
            AiTryMoveTowards(pos.x, pos.y, AI_ACTION_NONE, sScr->unk_02, TRUE);
        }
    }
    else
    {
        if (AiFindTargetInReachByFunc(AiIsUnitEnemyAndNotInScrList, &pos) == TRUE)
        {
            AiTryMoveTowards(pos.x, pos.y, AI_ACTION_NONE, sScr->unk_02, TRUE);
        }
    }

    (*pc)++;
}

void AiCmd_Nop_08031740(u8* pc)
{
    (*pc)++;
}

void AiCmd_Nop_08031748(u8* pc)
{
    (*pc)++;
}

void AiCmd_MoveRandom(u8* pc)
{
    AiRandomMove();
    (*pc)++;
}

void AiCmd_Escape(u8* pc)
{
    gActiveUnit->aiFlags |= AI_UNIT_FLAG_3;
    AiTryMoveTowardsEscape();
    (*pc)++;
}

void AiCmd_Nop_08031788(u8* pc)
{
    (*pc)++;
}

void AiCmd_MoveTowardsTerrain(u8* pc)
{
    struct Vec2 pos;

    MapFlood_080193F4(gActiveUnit->x, gActiveUnit->y, gActiveUnit->job->movTerrainTable);

    if (AiFindClosestTerrainPosition(&sScr->unk_03, 0, &pos) == TRUE)
    {
        AiTryMoveTowards(pos.x, pos.y, AI_ACTION_NONE, sScr->unk_02, TRUE);
    }
    else
    {
        gAiSt.unk_86[0] = 4;
        sScrEnded = FALSE;
    }

    (*pc)++;
}

void AiCmd_MoveTowardsListedTerrain(u8* pc)
{
    struct Vec2 pos;

    MapFlood_080193F4(gActiveUnit->x, gActiveUnit->y, gActiveUnit->job->movTerrainTable);

    if (AiFindClosestTerrainPosition(sScr->unk_08, 0, &pos) == TRUE)
    {
        AiTryMoveTowards(pos.x, pos.y, AI_ACTION_NONE, sScr->unk_02, TRUE);
    }
    else
    {
        gAiSt.unk_86[0] = 4;
        sScrEnded = FALSE;
    }

    (*pc)++;
}

void AiCmd_Label(u8* pc)
{
    (*pc)++;
    sScrEnded = FALSE;
}

void AiDoBerserkAction(void)
{
    if (!sub_8033C04(AiIsUnitEnemy))
        AiAttemptOffensiveAction(AiIsUnitNonActive);
}

void AiDoBerserkMove(void)
{
    struct Vec2 pos;

    if (AiFindTargetInReachByFunc(AiIsUnitNonActive, &pos) == TRUE)
    {
        AiTryMoveTowards(pos.x, pos.y, AI_ACTION_NONE, -1, TRUE);
    }
}

// unreferenced
Bool sub_80318EC(void)
{
    return TRUE;
}

// unreferenced
Bool sub_80318F0(u8 const* arg)
{
    return AiGetJobRank(arg[0]), TRUE;
}
