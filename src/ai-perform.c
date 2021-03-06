
#include "ai-perform.h"

#include "hardware.h"
#include "sound.h"
#include "event.h"
#include "item.h"
#include "unit.h"
#include "map.h"
#include "mapwork.h"
#include "player-phase.h"
#include "bmfx.h"
#include "faction.h"
#include "action.h"
#include "unitsprite.h"
#include "battle.h"
#include "item-action.h"
#include "ai-decide.h"
#include "mu.h"

#include "constants/chapters.h"
#include "constants/terrains.h"

struct AiPerformProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ bool(*func)(struct AiPerformProc* proc);
    /* 30 */ u8 unk_30;
    /* 31 */ u8 isUnitVisible;
};

static void AiStartCombatAction(struct AiPerformProc* proc);
static void AiStartEscapeAction(struct AiPerformProc* proc);
static void AiStartStealAction(struct AiPerformProc* proc);
static bool AiPillageAction(struct AiPerformProc* proc);
static bool AiStaffAction(struct AiPerformProc* proc);
static bool AiUseItemAction(struct AiPerformProc* proc);
static bool AiRefreshAction(struct AiPerformProc* proc);
static bool AiTalkAction(struct AiPerformProc* proc);
static bool AiDummyAction(struct AiPerformProc* proc);
static bool AiEscapeAction(struct AiPerformProc* proc);
static bool AiWaitAndClearScreenAction(struct AiPerformProc* proc);

static void AiActionCursor_Idle(struct GenericProc* proc);

struct ProcScr CONST_DATA ProcScr_AiActionCursor[] =
{
    PROC_SLEEP(0),

    PROC_WHILE_EXISTS(ProcScr_CamMove),

    PROC_REPEAT(AiActionCursor_Idle),
    PROC_END,
};

static void AiPerform_WatchUnit(struct AiPerformProc* proc);
static void AiPerform_StartMovement(struct AiPerformProc* proc);
static void AiPerform_WatchTarget(struct AiPerformProc* proc);
static void AiPerform_StartAction(struct AiPerformProc* proc);
static void AiPerform_WaitAction(struct AiPerformProc* proc);
static void AiPerform_0802F20C(struct AiPerformProc* proc);
static void AiPerform_0802F29C(struct AiPerformProc* proc);

struct ProcScr CONST_DATA ProcScr_AiPerform[] =
{
    PROC_19,

    PROC_CALL(AiPerform_WatchUnit),
    PROC_SLEEP(0),

    PROC_CALL(AiPerform_StartMovement),
    PROC_WHILE(MuExistsActive),

    PROC_CALL(AiPerform_WatchTarget),
    PROC_SLEEP(0),

    PROC_CALL(AiPerform_StartAction),
    PROC_REPEAT(AiPerform_WaitAction),

    PROC_CALL_2(PlayerPhase_0801B9B0),

    PROC_CALL(AiPerform_0802F20C),
    PROC_CALL(AiPerform_0802F29C),

PROC_LABEL(1),
    PROC_END,
};

void AiActionCursor_Idle(struct GenericProc* proc)
{
    PutMapCursor(proc->x, proc->y, proc->unk58);

    if ((gKeySt->held & (KEY_BUTTON_A | KEY_BUTTON_START)) || proc->unk64 > 45)
        Proc_Break(proc);

    proc->unk64++;
}

void AiStartActionCursor(int x, int y, int kind, ProcPtr parent)
{
    struct GenericProc* proc;

    proc = SpawnProcLocking(ProcScr_AiActionCursor, parent);

    proc->x = x;
    proc->y = y;
    proc->unk58 = kind;
    proc->unk64 = 0;
}

void AiPerform_WatchUnit(struct AiPerformProc* proc)
{
    proc->isUnitVisible = TRUE;

    if (gPlaySt.vision != 0 && gPlaySt.faction == FACTION_RED)
    {
        if (gMapFog[gActiveUnit->y][gActiveUnit->x] != 0 || gMapFog[gAiDecision.yMove][gAiDecision.xMove] != 0)
        {
            CameraMoveWatchPosition(proc, gActiveUnit->x, gActiveUnit->y);
        }
        else
        {
            proc->isUnitVisible = FALSE;

            if (gAiDecision.actionId == AI_ACTION_PILLAGE)
            {
                CameraMoveWatchPosition(proc, gAiDecision.xMove, gAiDecision.yMove);
            }
        }
    }
    else
    {
        CameraMoveWatchPosition(proc, gActiveUnit->x, gActiveUnit->y);
    }
}

void AiPerform_StartMovement(struct AiPerformProc* proc)
{
    UnitBeginAction(gActiveUnit);

    HideUnitSprite(gActiveUnit);

    MapFlood_08019344(gActiveUnit);
    SetWorkingMap(gMapMovement);

    BuildBestMoveScript(gAiDecision.xMove, gAiDecision.yMove, gWorkingMoveScr);

    if (proc->isUnitVisible)
    {
        StartMu(gActiveUnit);
        SetAutoMuDefaultFacing();
        SetAutoMuMoveScript(gWorkingMoveScr);
    }
}

void AiEndMuAndRefreshUnits(void)
{
    SetMapCursorPosition(gAiDecision.xMove, gAiDecision.yMove);

    if (gPlaySt.vision != 0 && gPlaySt.faction != FACTION_RED)
    {
        RenderMapForFade();

        sub_8017EDC(gAiDecision.xMove, gAiDecision.yMove);

        RefreshEntityMaps();
        RenderMap();

        StartMapFade(TRUE);
    }
    else
    {
        sub_8017EDC(gAiDecision.xMove, gAiDecision.yMove);

        RenderMap();
        RefreshEntityMaps();
    }

    if (gPlaySt.chapter == CHAPTER_UNK_19 && sub_806B404())
        sub_806B414();

    EndAllMus();

    RefreshEntityMaps();

    ShowUnitSprite(gActiveUnit);
    RefreshUnitSprites();
}

void AiStartCombatAction(struct AiPerformProc* proc)
{
    gAction.id = ACTION_COMBAT;
    gAction.target = gAiDecision.targetId;

    gActiveUnit->x = gAiDecision.xMove;
    gActiveUnit->y = gAiDecision.yMove;

    if ((s8) gAiDecision.itemSlot != -1)
    {
        UnitEquipItemSlot(gActiveUnit, gAiDecision.itemSlot);
        BattleGenerateReal(gActiveUnit, GetUnit(gAiDecision.targetId));
    }
    else
    {
        BattleGenerateBallistaReal(gActiveUnit, GetUnit(gAiDecision.targetId));
    }

    if (gKeySt->held & KEY_BUTTON_R)
        EndAllMus();

    SpawnProcLocking(ProcScr_CombatAction, proc);
}

void AiStartEscapeAction(struct AiPerformProc* proc)
{
    u8 scripts[4][3] =
    {
        { MOVE_CMD_MOVE_LEFT,  MOVE_CMD_MOVE_LEFT,  MOVE_CMD_HALT },
        { MOVE_CMD_MOVE_RIGHT, MOVE_CMD_MOVE_RIGHT, MOVE_CMD_HALT },
        { MOVE_CMD_MOVE_DOWN,  MOVE_CMD_MOVE_DOWN,  MOVE_CMD_HALT },
        { MOVE_CMD_MOVE_UP,    MOVE_CMD_MOVE_UP,    MOVE_CMD_HALT },
    };

    if (gAiDecision.xTarget != 5 && proc->isUnitVisible)
        SetAutoMuMoveScript(scripts[gAiDecision.xTarget]);
}

void AiStartStealAction(struct AiPerformProc* proc)
{
    struct Unit* target = GetUnit(gAiDecision.targetId);

    u16 item = target->items[gAiDecision.itemSlot];

    UnitAddItem(gActiveUnit, item);
    UnitRemoveItem(target, gAiDecision.itemSlot);

    StartPopup_08012178(item, proc);
}

bool AiPillageAction(struct AiPerformProc* proc)
{
    static struct PopupInfo CONST_DATA Popup_085C85D0[] =
    {
        POPUP_SONG(0x5C), // TODO: song ids
        POPUP_MSG(0x6E6), // TODO: msg ids
        POPUP_END,
    };

    int x = gAiDecision.xMove;
    int register y asm("r4") = gAiDecision.yMove;

    if (gMapTerrain[y][x] == TERRAIN_CHEST)
    {
        gActiveUnit->x = gAiDecision.xMove;
        gActiveUnit->y = gAiDecision.yMove;

        gAction.id = ACTION_USEITEM;
        gAction.itemSlot = gAiDecision.itemSlot;

        DoItemAction(proc);
    }
    else
    {
        int const y2 = y-1;
        sub_806B06C(x, y2);

        PlaySe(0xAB); // TODO: song ids
        StartPopup(Popup_085C85D0, 0x60, 0, proc);
    }

    return TRUE;
}

bool AiStaffAction(struct AiPerformProc* proc)
{
    gActiveUnit->x = gAiDecision.xMove;
    gActiveUnit->y = gAiDecision.yMove;

    gAction.id = ACTION_STAFF;
    gAction.target = gAiDecision.targetId;
    gAction.itemSlot = gAiDecision.itemSlot;

    DoItemAction(proc);

    return TRUE;
}

bool AiUseItemAction(struct AiPerformProc* proc)
{
    gActiveUnit->x = gAiDecision.xMove;
    gActiveUnit->y = gAiDecision.yMove;

    gAction.id = ACTION_USEITEM;
    gAction.itemSlot = gAiDecision.itemSlot;

    DoItemAction(proc);

    return TRUE;
}

bool AiRefreshAction(struct AiPerformProc* proc)
{
    return TRUE;
}

bool AiTalkAction(struct AiPerformProc* proc)
{
    gActiveUnit->x = gAiDecision.xMove;
    gActiveUnit->y = gAiDecision.yMove;

    if (gAiDecision.targetId == 0)
    {
        sub_806AF90(
            GetUnit(gAiDecision.itemSlot)->person->id,
            GetUnit(gAiDecision.xTarget)->person->id);
    }

    return TRUE;
}

void AiPerform_WatchTarget(struct AiPerformProc* proc)
{
    struct Unit* target;

    int x = 0;
    int y = 0;

    switch (gAiDecision.actionId)
    {

    case AI_ACTION_NONE:
        return;

    case AI_ACTION_COMBAT:
        target = GetUnit(gAiDecision.targetId);

        x = target->x;
        y = target->y;

        break;

    case AI_ACTION_ESCAPE:
        return;

    case AI_ACTION_STEAL:
        target = GetUnit(gAiDecision.targetId);

        x = target->x;
        y = target->y;

        break;

    case AI_ACTION_PILLAGE:
        return;

    case AI_ACTION_USEITEM:
        return;

    case AI_ACTION_REFRESH:
        target = GetUnit(gAiDecision.targetId);

        x = target->x;
        y = target->y;

        break;

    case AI_ACTION_TALK:
        target = GetUnit(gAiDecision.yTarget);

        x = target->x;
        y = target->y;

        break;

    case AI_ACTION_STAFF:
        if (gAiDecision.targetId == 0)
            return;

        target = GetUnit(gAiDecision.targetId);

        x = target->x;
        y = target->y;

        break;

    }

    CameraMoveWatchPosition(proc, x, y);
    AiStartActionCursor(x*16, y*16, MAP_CURSOR_RED_MOVING, proc);
}

void AiPerform_StartAction(struct AiPerformProc* proc)
{
    proc->unk_30 = 0;

    switch (gAiDecision.actionId)
    {

    case AI_ACTION_NONE:
        proc->func = AiDummyAction;
        break;

    case AI_ACTION_COMBAT:
        proc->func = AiDummyAction;
        AiStartCombatAction(proc);
        break;

    case AI_ACTION_ESCAPE:
        AiStartEscapeAction(proc);
        proc->func = AiEscapeAction;
        break;

    case AI_ACTION_STEAL:
        AiStartStealAction(proc);
        proc->func = AiWaitAndClearScreenAction;
        break;

    case AI_ACTION_PILLAGE:
        proc->func = AiPillageAction;
        break;

    case AI_ACTION_STAFF:
        proc->func = AiStaffAction;
        break;

    case AI_ACTION_USEITEM:
        proc->func = AiUseItemAction;
        break;

    case AI_ACTION_REFRESH:
        proc->func = AiRefreshAction;
        break;

    case AI_ACTION_TALK:
        proc->func = AiTalkAction;
        break;

    }
}

void AiPerform_WaitAction(struct AiPerformProc* proc)
{
    proc->unk_30++;

    if (proc->func(proc) == TRUE)
        Proc_Break(proc);
}

void AiPerform_0802F20C(struct AiPerformProc* proc)
{
    sub_8032A08();
    AiEndMuAndRefreshUnits();

    if (!gActiveUnit->person || gActiveUnit->state & (US_HIDDEN | US_DEAD))
        Proc_Goto(proc, 1);
}

bool AiDummyAction(struct AiPerformProc* proc)
{
    return TRUE;
}

bool AiEscapeAction(struct AiPerformProc* proc)
{
    if (!MuExistsActive())
    {
        gActiveUnit->person = NULL;
        return TRUE;
    }

    return FALSE;
}

bool AiWaitAndClearScreenAction(struct AiPerformProc* proc)
{
    if (proc->unk_30 > 4)
    {
        TmFill(gBg0Tm, 0);
        TmFill(gBg1Tm, 0);
        EnableBgSync(BG0_SYNC_BIT + BG1_SYNC_BIT);

        return TRUE;
    }

    return FALSE;
}

void AiPerform_0802F29C(struct AiPerformProc* proc)
{
    u16 var_04[6];

    if (sub_8032CB4() && sub_8032CE8(var_04))
    {
        u16 var_10, var_12, var_14;

        sub_8032DF4(gAiDecision.xMove, gAiDecision.yMove, &var_10, &var_12, &var_14);
        sub_8032F94(var_10, var_12, var_14, var_04);
    }
}
