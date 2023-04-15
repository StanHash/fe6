#include "playerphase.h"

#include "hardware.h"
#include "move.h"
#include "sound.h"
#include "text.h"
#include "bm.h"
#include "unit.h"
#include "map.h"
#include "mapwork.h"
#include "bmfx.h"
#include "faction.h"
#include "unitsprite.h"
#include "trap.h"
#include "chapter.h"
#include "action.h"
#include "movepath.h"
#include "prepphase.h"
#include "menuinfo.h"
#include "mu.h"
#include "eventinfo.h"
#include "statscreen.h"
#include "mapui.h"
#include "save_stats.h"
#include "save_game.h"

#include "constants/videoalloc_global.h"
#include "constants/chapters.h"
#include "constants/pids.h"
#include "constants/songs.h"

static bool CanSelectMoveTo(int x, int y);
static void PlayerPhase_ContinueAction(ProcPtr proc);
static void PlayerPhase_CancelAction(ProcPtr proc);
static bool PlayerPhase_AttemptReMove(ProcPtr proc);

static bool TrySetCursorOn(int uid);

static void PlayerPhase_Suspend(ProcPtr proc);
static void PlayerPhase_IdleLoop(ProcPtr proc);
static void PlayerPhase_BeginMoveSelect(ProcPtr proc);
static void PlayerPhase_BeginMove(ProcPtr proc);
static void PlayerPhase_WaitForMove(ProcPtr proc);
static void PlayerPhase_BeginActionSelect(ProcPtr proc);
static bool PlayerPhase_BeginAction(ProcPtr proc);
static bool PlayerPhase_WatchActiveUnit(ProcPtr proc);
static void PlayerPhase_FinishAction(ProcPtr proc);
static void PlayerPhase_0801BD08(ProcPtr proc);
static void PlayerPhase_HandleAutoEnd(ProcPtr proc);

struct ProcScr CONST_DATA ProcScr_PlayerPhase[] =
{
    PROC_19,
    PROC_MARK(PROC_MARK_2),
    PROC_SLEEP(0),

PROC_LABEL(L_PLAYERPHASE_BEGIN),
    PROC_CALL(PlayerPhase_Suspend),

    PROC_CALL(RefreshEntityMaps),
    PROC_CALL(RenderMap),
    PROC_CALL(RefreshUnitSprites),

    PROC_CALL(PlayerPhase_HandleAutoEnd),

    PROC_CALL(StartMapSongBgm),

    // fallthrough

PROC_LABEL(L_PLAYERPHASE_IDLE),
    PROC_CALL(StartMapUi),
    PROC_CALL(ResetUnitSpritHover),

    PROC_REPEAT(PlayerPhase_IdleLoop),

    // fallthrough

PROC_LABEL(L_PLAYERPHASE_MOVE),
    PROC_CALL(EndMapUi),

    PROC_WHILE(IsMapFadeActive),

    PROC_CALL(func_fe6_0801809C),
    PROC_CALL(RefreshUnitSprites),

    PROC_CALL(PlayerPhase_BeginMoveSelect),
    PROC_REPEAT(PlayerPhase_MoveSelectLoop),

    PROC_CALL(PlayerPhase_BeginMove),
    PROC_REPEAT(PlayerPhase_WaitForMove),

    // fallthrough

PROC_LABEL(L_PLAYERPHASE_ACTION_SELECT),
    PROC_REPEAT(PlayerPhase_BeginActionSelect),

    // fallthrough

PROC_LABEL(L_PLAYERPHASE_ACTION),
    PROC_WHILE_EXISTS(ProcScr_CamMove),

    PROC_CALL_2(PlayerPhase_BeginAction),

    PROC_CALL_2(DoAction),
    PROC_CALL_2(DoHandleStepTraps),

    PROC_CALL_2(PlayerPhase_0801B9B0),
    PROC_CALL_2(PlayerPhase_WatchActiveUnit),

    PROC_CALL(PlayerPhase_FinishAction),

    PROC_GOTO(L_PLAYERPHASE_BEGIN),

PROC_LABEL(L_PLAYERPHASE_MAPFADE_MOVE),
    PROC_WHILE(IsMapFadeActive),

    PROC_GOTO(L_PLAYERPHASE_MOVE),

PROC_LABEL(L_PLAYERPHASE_5),
    PROC_CALL(PlayerPhase_0801BD08),

    // fallthrough

PROC_LABEL(L_PLAYERPHASE_10),
    PROC_START_CHILD_LOCKING(ProcScr_Unk_085C5988),

    PROC_GOTO(L_PLAYERPHASE_IDLE),

PROC_LABEL(L_PLAYERPHASE_6),
    PROC_CALL(PlayerPhase_0801BC84),

    PROC_GOTO(L_PLAYERPHASE_MOVE),

PROC_LABEL(L_PLAYERPHASE_8),
    PROC_SLEEP(0),

    PROC_CALL(EndAllMus),

    PROC_GOTO(L_PLAYERPHASE_BEGIN),

PROC_LABEL(L_PLAYERPHASE_SEE_RANGE),
    PROC_CALL(EndMapUi),

    PROC_WHILE(IsMapFadeActive),

    PROC_CALL(PlayerPhase_BeginSeeActionRange),
    PROC_REPEAT(PlayerPhase_MoveSelectLoop),

    PROC_GOTO(L_PLAYERPHASE_IDLE),

PROC_LABEL(L_PLAYERPHASE_END),
    PROC_WHILE(IsMapFadeActive),

    PROC_END,
};

u8 const * CONST_DATA gOpenLimitViewImgLut[] =
{
    NULL,
    NULL,
    Img_LimitViewSquares + 0 * 4*CHR_SIZE,
    Img_LimitViewSquares + 1 * 4*CHR_SIZE,
    Img_LimitViewSquares + 2 * 4*CHR_SIZE,
    Img_LimitViewSquares + 3 * 4*CHR_SIZE,
    Img_LimitViewSquares + 4 * 4*CHR_SIZE,
    Img_LimitViewSquares + 5 * 4*CHR_SIZE,
};

static void OpenLimitView_Init(struct GenericProc * proc);
static void OpenLimitView_Loop(struct GenericProc * proc);

struct ProcScr CONST_DATA ProcScr_OpenLimitView[] =
{
    PROC_19,
    PROC_MARK(PROC_MARK_1),

    PROC_CALL(OpenLimitView_Init),
    PROC_REPEAT(OpenLimitView_Loop),

    PROC_END,
};

static void LimitView_Init(struct GenericProc * proc);
static void LimitView_Loop(struct GenericProc * proc);
static void LimitView_Deinit(struct GenericProc * proc);

struct ProcScr CONST_DATA ProcScr_LimitView[] =
{
    PROC_19,
    PROC_MARK(PROC_MARK_1),

    PROC_ONEND(LimitView_Deinit),

    PROC_START_CHILD(ProcScr_OpenLimitView),

    PROC_CALL(LimitView_Init),
    PROC_REPEAT(LimitView_Loop),

    PROC_END,
};

static void PlayerPhase_Suspend(ProcPtr proc)
{
    gAction.suspend_point = SUSPEND_POINT_PLAYER_PHASE;
    WriteSuspendSave(SAVE_SUSPEND);
}

void HandlePlayerMapCursor(void)
{
    if ((gKeySt->held & KEY_BUTTON_B) && !(gBmSt.cursor_sprite.x & 7) && !(gBmSt.cursor_sprite.y & 7))
    {
        HandleMapCursorInput(gKeySt->pressed2);

        HandleMoveMapCursor(8);
        HandleMoveCameraWithMapCursor(8);
    }
    else
    {
        HandleMapCursorInput(gKeySt->repeated);

        HandleMoveMapCursor(4);
        HandleMoveCameraWithMapCursor(4);
    }

    if ((gBmSt.cursor_sprite.x | gBmSt.cursor_sprite.y) & 0xF)
        gKeySt->pressed &= ~(KEY_BUTTON_A | KEY_BUTTON_B | KEY_BUTTON_START | KEY_BUTTON_R | KEY_BUTTON_L);
}

static void PlayerPhase_IdleLoop(ProcPtr proc)
{
    HandlePlayerMapCursor();

    if (gKeySt->pressed & KEY_BUTTON_L)
    {
        TrySwitchViewedUnit(gBmSt.cursor.x, gBmSt.cursor.y);
        PlaySe(SONG_6B);
    }
    else if (!IsMapFadeActive())
    {
        if ((gKeySt->pressed & KEY_BUTTON_R) && gMapUnit[gBmSt.cursor.y][gBmSt.cursor.x] != 0)
        {
            EndAllMus();
            EndMapUi();
            SetStatScreenExcludedUnitFlags(UNIT_FLAG_DEAD | UNIT_FLAG_NOT_DEPLOYED | UNIT_FLAG_UNDER_ROOF | UNIT_FLAG_CONCEALED);

            StartStatScreen(GetUnit(gMapUnit[gBmSt.cursor.y][gBmSt.cursor.x]), proc);
            Proc_Goto(proc, L_PLAYERPHASE_5);

            return;
        }

        if (gKeySt->pressed & KEY_BUTTON_A)
        {
            struct Unit * unit = GetUnit(gMapUnit[gBmSt.cursor.y][gBmSt.cursor.x]);

            switch (GetPlayerSelectKind(unit))
            {

            case PLAYER_SELECT_NOUNIT:
            case PLAYER_SELECT_TURNENDED:
                EndMapUi();

                gPlaySt.x_cursor = gBmSt.cursor.x;
                gPlaySt.y_cursor = gBmSt.cursor.y;

                StartAdjustedMenu(&MenuInfo_Map, gBmSt.cursor_sprite_target.x - gBmSt.camera.x, 1, 23);
                StartAvailableMapMenuEvent();

                Proc_Goto(proc, L_PLAYERPHASE_IDLE);

                return;

            case PLAYER_SELECT_CONTROL:
                UnitBeginAction(unit);
                PidStatsAddAct(gActiveUnit->pinfo->id);

                Proc_Break(proc);

                goto put_cursor;

            case PLAYER_SELECT_NOCONTROL:
                UnitBeginAction(unit);
                gBmSt.swap_action_range_count = 0;

                Proc_Goto(proc, L_PLAYERPHASE_SEE_RANGE);

                goto put_cursor;

            }
        }

        if (gKeySt->pressed & KEY_BUTTON_SELECT)
        {
            struct Unit * unit = GetUnit(gMapUnit[gBmSt.cursor.y][gBmSt.cursor.x]);

            if (unit)
            {
                EndAllMus();
                ShowUnitSprite(unit);
            }

            EndMapUi();

            gPlaySt.x_cursor = gBmSt.cursor.x;
            gPlaySt.y_cursor = gBmSt.cursor.y;

            if (gPlaySt.chapter == CHAPTER_TUTORIAL)
            {
                StartMenu(&MenuInfo_TutorialInterruptMenu);
            }
            else
            {
                StartAdjustedMenu(&MenuInfo_Map, gBmSt.cursor_sprite_target.x - gBmSt.camera.x, 1, 23);
                StartAvailableMapMenuEvent();
            }

            Proc_Goto(proc, L_PLAYERPHASE_IDLE);

            return;
        }

        if ((gKeySt->pressed & KEY_BUTTON_START) && !(gKeySt->held & KEY_BUTTON_SELECT))
        {
            struct Unit * unit = GetUnit(gMapUnit[gBmSt.cursor.y][gBmSt.cursor.x]);

            if (unit)
            {
                EndAllMus();
                ShowUnitSprite(unit);
            }

            EndMapUi();
            func_fe6_08087BC4();

            Proc_Goto(proc, L_PLAYERPHASE_IDLE);

            return;
        }
    }

put_cursor:
    UnitSpriteHoverUpdate();

    PutMapCursor(gBmSt.cursor_sprite.x, gBmSt.cursor_sprite.y,
        IsUnitSpriteHoverEnabledAt(gBmSt.cursor.x, gBmSt.cursor.y) ? MAP_CURSOR_STRETCHED : MAP_CURSOR_DEFAULT);
}

void DisplayUnitActionRange(struct Unit * unit)
{
    int flags = LIMITVIEW_BLUE;

    MapFlood_UpTo(gActiveUnit, UNIT_MOV(gActiveUnit) - gAction.move_count);

    if (!(gActiveUnit->flags & UNIT_FLAG_HAD_ACTION))
    {
        switch (func_fe6_08018258(gActiveUnit))
        {

        case 0:
            MapFill(gMapRange, 0);
            break;

        case UNIT_USEBIT_WEAPON | UNIT_USEBIT_STAFF:
            if (gBmSt.swap_action_range_count & 1)
            {
                BuildUnitCompleteStaffRange(gActiveUnit);
                flags = LIMITVIEW_GREEN | LIMITVIEW_BLUE;
            }
            else
            {
                BuildUnitCompleteAttackRange(gActiveUnit);
                flags = LIMITVIEW_RED | LIMITVIEW_BLUE;
            }

            break;

        case UNIT_USEBIT_STAFF:
            BuildUnitCompleteStaffRange(gActiveUnit);
            flags = LIMITVIEW_GREEN | LIMITVIEW_BLUE;

            break;

        case UNIT_USEBIT_WEAPON:
            BuildUnitCompleteAttackRange(gActiveUnit);
            flags = LIMITVIEW_RED | LIMITVIEW_BLUE;

            break;

        }
    }

    StartLimitView(flags);
}

static void PlayerPhase_BeginMoveSelect(ProcPtr proc)
{
    if (!MuExists() && UNIT_FACTION(gActiveUnit) == gPlaySt.faction)
    {
        if (gActiveUnit->status != UNIT_STATUS_SLEEP && gActiveUnit->status != UNIT_STATUS_BERSERK)
        {
            StartMu(gActiveUnit);
            HideUnitSprite(gActiveUnit);
        }
    }

    SetAutoMuDefaultFacing();

    StartAvailableMoveSelectEvent();

    gBmSt.flags |= BM_FLAG_1;

    DisplayUnitActionRange(gActiveUnit);

    if (gActiveUnit->x == gBmSt.cursor.x && gActiveUnit->y == gBmSt.cursor.y)
    {
        InitMovePath(FALSE);
        PlaySe(SONG_69);
    }
    else
    {
        InitMovePath(TRUE);
    }
}

void PlayerPhase_BeginSeeActionRange(ProcPtr proc)
{
    PlaySe(SONG_68);

    gBmSt.flags &= ~BM_FLAG_1;
    DisplayUnitActionRange(gActiveUnit);
}

void PlayerPhase_MoveSelectLoop(ProcPtr proc)
{
    enum
    {
        ACT_FAIL,
        ACT_MOVE,
        ACT_CANCEL,
        ACT_INFOSCREEN,
        ACT_RESET_CURSOR,
        ACT_EVENT,
        ACT_SWAP_RANGES,
    };

    u8 act = -1;

    HandlePlayerMapCursor();

    if (gKeySt->pressed & KEY_BUTTON_A)
    {
        if (CheckAvailableMoveSelectConfirmEvent())
        {
            act = ACT_EVENT;
            goto do_act;
        }
        else
        {
            if (GetPlayerSelectKind(gActiveUnit) != PLAYER_SELECT_CONTROL && !(gActiveUnit->flags & UNIT_FLAG_HAD_ACTION))
            {
                if (func_fe6_08018258(gActiveUnit) == (UNIT_USEBIT_WEAPON | UNIT_USEBIT_STAFF))
                    act = ACT_SWAP_RANGES;
                else
                    act = ACT_CANCEL;

                goto do_act;
            }
            else
            {
                if (!CanSelectMoveTo(gBmSt.cursor.x, gBmSt.cursor.y))
                {
                    act = ACT_FAIL;
                    goto do_act;
                }

                act = ACT_MOVE;
            }
        }
    }

    if (gKeySt->pressed & KEY_BUTTON_B)
    {
        if (gActiveUnit->flags & UNIT_FLAG_HAD_ACTION)
            act = ACT_FAIL;
        else
            act = ACT_CANCEL;
    }
    else if (gKeySt->pressed & KEY_BUTTON_R)
    {
        act = ACT_INFOSCREEN;
    }
    else if (gKeySt->pressed & KEY_BUTTON_L)
    {
        act = ACT_RESET_CURSOR;
    }

do_act:
    switch (act)
    {

    case ACT_FAIL:
        PlaySe(SONG_6C);
        break;

    case ACT_MOVE:
        CameraMoveWatchPosition(proc, gActiveUnitMoveOrigin.x, gActiveUnitMoveOrigin.y);
        EndLimitView();

        Proc_Break(proc);
        return;

    case ACT_CANCEL:
        EndAllMus();

        gActiveUnit->flags &= ~UNIT_FLAG_HIDDEN;

        if (UNIT_FACTION(gActiveUnit) == FACTION_BLUE)
        {
            CameraMoveWatchPosition(proc, gActiveUnitMoveOrigin.x, gActiveUnitMoveOrigin.y);
            SetMapCursorPosition(gActiveUnitMoveOrigin.x, gActiveUnitMoveOrigin.y);
        }

        EndLimitView();

        RefreshEntityMaps();
        RefreshUnitSprites();

        PlaySe(SONG_6B);

        Proc_Goto(proc, L_PLAYERPHASE_IDLE);
        return;

    case ACT_INFOSCREEN:
    {
        u8 uid = gMapUnit[gBmSt.cursor.y][gBmSt.cursor.x];

        if (gActiveUnitMoveOrigin.x == gBmSt.cursor.x && gActiveUnitMoveOrigin.y == gBmSt.cursor.y)
            uid = gActiveUnit->id;

        if (uid == 0)
            break;

        EndAllMus();
        SetStatScreenExcludedUnitFlags(UNIT_FLAG_DEAD | UNIT_FLAG_NOT_DEPLOYED | UNIT_FLAG_UNDER_ROOF | UNIT_FLAG_CONCEALED);

        StartStatScreen(GetUnit(uid), proc);
        Proc_Goto(proc, L_PLAYERPHASE_6);
        return;
    }

    case ACT_RESET_CURSOR:
        CameraMoveWatchPosition(proc, gActiveUnitMoveOrigin.x, gActiveUnitMoveOrigin.y);
        SetMapCursorPosition(gActiveUnitMoveOrigin.x, gActiveUnitMoveOrigin.y);

        PlaySe(SONG_6B);

        break;

    case ACT_EVENT:
        // StartAvailableMoveSelectConfirmEvent();
        break;

    case ACT_SWAP_RANGES:
        gBmSt.swap_action_range_count++;
        EndLimitView();

        Proc_Goto(proc, L_PLAYERPHASE_SEE_RANGE);
        break;

    }

    if (GetPlayerSelectKind(gActiveUnit) == PLAYER_SELECT_CONTROL)
        RefreshMovePath();

    PutMapCursor(gBmSt.cursor_sprite.x, gBmSt.cursor_sprite.y, MAP_CURSOR_REGULAR);
}

static void PlayerPhase_ContinueAction(ProcPtr proc)
{
    gAction.id = ACTION_NONE;
    Proc_Goto(proc, L_PLAYERPHASE_ACTION_SELECT);
}

static void PlayerPhase_CancelAction(ProcPtr proc)
{
    gActiveUnit->x = gActiveUnitMoveOrigin.x;
    gActiveUnit->y = gActiveUnitMoveOrigin.y;

    UnitSyncMovement(gActiveUnit);

    gActiveUnit->flags &= ~UNIT_FLAG_HIDDEN;

    RefreshEntityMaps();
    RenderMap();
    RefreshUnitSprites();

    if (!(gActiveUnit->flags & UNIT_FLAG_HAD_ACTION))
        UnitBeginAction(gActiveUnit);
    else
        UnitBeginReMoveAction(gActiveUnit);

    HideUnitSprite(gActiveUnit);
    EndAllMus();
    StartMu(gActiveUnit);

    Proc_Goto(proc, L_PLAYERPHASE_MOVE);
}

static bool PlayerPhase_BeginAction(ProcPtr proc)
{
    bool camret;

    camret = CameraMoveWatchPosition(proc, GetUnit(gAction.instigator)->x, GetUnit(gAction.instigator)->y);
    camret = camret ^ 1;

    switch (gAction.id)
    {

    case ACTION_NONE:
        if (gBmSt.partial_actions_taken != 0)
        {
            gAction.id = ACTION_1C;
            break;
        }

        PlayerPhase_CancelAction(proc);
        return TRUE;

    case ACTION_TRADED:
        gBmSt.partial_actions_taken |= PARTIAL_ACTION_TRADED;

        PlayerPhase_ContinueAction(proc);
        return TRUE;

    case ACTION_TRADED_SUPPLY:
        gBmSt.partial_actions_taken |= PARTIAL_ACTION_SUPPLY;

        PlayerPhase_ContinueAction(proc);
        return TRUE;

    case ACTION_TRADED_NOCHANGES:
        PlayerPhase_ContinueAction(proc);
        return TRUE;

    case ACTION_GIVE:
    case ACTION_TAKE:
        gBmSt.partial_actions_taken |= PARTIAL_ACTION_RESCUE_TRANSFER;

        PlayerPhase_ContinueAction(proc);
        return TRUE;

    }

    if ((gAction.id != ACTION_WAIT) && !gBmSt.just_resumed)
    {
        gAction.suspend_point = SUSPEND_POINT_DURING_ACTION;
        WriteSuspendSave(SAVE_SUSPEND);
    }

    return camret;
}

static bool PlayerPhase_AttemptReMove(ProcPtr proc)
{
    if (!(UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_RE_MOVE))
        return FALSE;

    if (gActiveUnit->flags & (UNIT_FLAG_HAD_ACTION | UNIT_FLAG_DEAD))
        return FALSE;

    if (gAction.id == ACTION_COMBAT || gAction.id == ACTION_STAFF)
        return FALSE;

    if (UNIT_MOV(gActiveUnit) <= gAction.move_count)
        return FALSE;

    if (!CanActiveUnitStillMove())
        return FALSE;

    MapFill(gMapRange, 0);

    UnitBeginReMoveAction(gActiveUnit);

    gActiveUnit->flags |= UNIT_FLAG_HAD_ACTION;
    gActiveUnit->flags &= ~UNIT_FLAG_TURN_ENDED;

    if (gPlaySt.vision != 0)
        Proc_Goto(proc, L_PLAYERPHASE_MAPFADE_MOVE);
    else
        Proc_Goto(proc, L_PLAYERPHASE_MOVE);

    return TRUE;
}

bool PlayerPhase_0801B9B0(ProcPtr proc)
{
    if (CheckAvailableMoveEvent())
    {
        StartAvailableMoveEvent();
        return FALSE;
    }

    return TRUE;
}

static bool PlayerPhase_WatchActiveUnit(ProcPtr proc)
{
    return !CameraMoveWatchPosition(proc, gActiveUnit->x, gActiveUnit->y);
}

static void PlayerPhase_FinishAction(ProcPtr proc)
{
    if (gPlaySt.vision != 0)
    {
        RenderMapForFade();

        func_fe6_08017EDC(gAction.x_move, gAction.y_move);

        RefreshEntityMaps();
        RenderMap();

        StartMapFade(FALSE);

        RefreshUnitSprites();
    }
    else
    {
        func_fe6_08017EDC(gAction.x_move, gAction.y_move);

        RefreshEntityMaps();
        RenderMap();
    }

    SetMapCursorPosition(gActiveUnit->x, gActiveUnit->y);

    gPlaySt.x_cursor = gBmSt.cursor.x;
    gPlaySt.y_cursor = gBmSt.cursor.y;

    if (PlayerPhase_AttemptReMove(proc))
    {
        HideUnitSprite(gActiveUnit);
        return;
    }

    if (CheckAvailableVictoryEvent())
    {
        EndAllMus();

        RefreshEntityMaps();
        RenderMap();
        RefreshUnitSprites();

        StartAvailableVictoryEvent();

        Proc_Goto(proc, L_PLAYERPHASE_8);
        return;
    }

    EndAllMus();
}

static void func_fe6_0801BAB4(ProcPtr proc)
{
    if (gAction.id != ACTION_TRAPPED)
        StartCenteredMenu(&MenuInfo_UnitAction, gBmSt.cursor_sprite_target.x - gBmSt.camera.x, 1, 22);

    Proc_Break(proc);
}

static void PlayerPhase_BeginActionSelect(ProcPtr proc)
{
    gActiveUnit->x = gAction.x_move;
    gActiveUnit->y = gAction.y_move;

    UnitSyncMovement(gActiveUnit);

    if (!(gActiveUnit->flags & UNIT_FLAG_HAD_ACTION) && gAction.id == ACTION_NONE && gBmSt.partial_actions_taken == 0)
        gAction.move_count = gMapMovement[gAction.y_move][gAction.x_move];

    ResetTextFont();

    if (StartAvailableActionSelectEvent() == TRUE)
    {
        Proc_SetRepeatFunc(proc, func_fe6_0801BAB4);
        return;
    }

    if (gAction.id != ACTION_TRAPPED)
        StartCenteredMenu(&MenuInfo_UnitAction, gBmSt.cursor_sprite_target.x - gBmSt.camera.x, 1, 22);

    Proc_Break(proc);
}

int GetPlayerSelectKind(struct Unit * unit)
{
    int faction = gPlaySt.faction;

    if (!unit)
        return PLAYER_SELECT_NOUNIT;

    if (gBmSt.flags & BM_FLAG_4)
    {
        if (unit->pinfo->id == PID_ROY)
            return PLAYER_SELECT_4;

        faction = FACTION_BLUE;
    }

    if (!unit)
        return PLAYER_SELECT_NOUNIT;

    if (UNIT_FACTION(unit) != faction)
        return PLAYER_SELECT_NOCONTROL;

    if (unit->flags & UNIT_FLAG_TURN_ENDED)
        return PLAYER_SELECT_TURNENDED;

    if (unit->status != UNIT_STATUS_SLEEP && unit->status != UNIT_STATUS_BERSERK)
        return PLAYER_SELECT_CONTROL;

    return PLAYER_SELECT_NOCONTROL;
}

static bool CanSelectMoveTo(int x, int y)
{
    if (gMapUnit[y][x] == 0 && gMapMovement[y][x] < MAP_MOVEMENT_MAX)
        return TRUE;

    return FALSE;
}

static void PlayerPhase_BeginMove(ProcPtr proc)
{
    GenMoveScriptFromMovePath();
    ApplyWorkingMovScriptToAction(gActiveUnit->x, gActiveUnit->y);
    SetAutoMuMoveScript(gWorkingMoveScr);
}

static void PlayerPhase_WaitForMove(ProcPtr proc)
{
    if (!MuExistsActive())
        Proc_Break(proc);
}

void PlayerPhase_0801BC84(ProcPtr proc)
{
    gMapUnit[gActiveUnit->y][gActiveUnit->x] = gActiveUnit->id;
    gActiveUnit->flags &= ~UNIT_FLAG_HIDDEN;

    InitBmDisplay();

    gMapUnit[gActiveUnit->y][gActiveUnit->x] = 0;
    gActiveUnit->flags |= UNIT_FLAG_HIDDEN;

    switch (GetPlayerSelectKind(gActiveUnit))
    {

    case PLAYER_SELECT_CONTROL:
        HideUnitSprite(gActiveUnit);
        break;

    case PLAYER_SELECT_NOCONTROL:
        Proc_Goto(proc, L_PLAYERPHASE_SEE_RANGE);
        break;

    }
}

static void PlayerPhase_0801BD08(ProcPtr proc)
{
    InitBmDisplay();
    SetBlendNone();
}

static void OpenLimitView_Init(struct GenericProc * proc)
{
    RegisterVramMove(Img_LimitViewSquares + 5 * 4 * CHR_SIZE, CHR_SIZE * (BGCHR_LIMITVIEW + 4), CHR_SIZE * 4);

    if (!(gBmSt.flags & BM_FLAG_0))
    {
        proc->unk4C = 2;
    }
    else
    {
        RegisterVramMove(Img_LimitViewSquares + 5 * 4 * CHR_SIZE, CHR_SIZE * BGCHR_LIMITVIEW, CHR_SIZE * 4);
        Proc_End(proc);
    }
}

static void OpenLimitView_Loop(struct GenericProc * proc)
{
    RegisterVramMove(gOpenLimitViewImgLut[proc->unk4C], CHR_SIZE * BGCHR_LIMITVIEW, 4 * CHR_SIZE);

    proc->unk4C++;

    if (proc->unk4C == 8)
        Proc_Break(proc);
}

static void LimitView_Init(struct GenericProc * proc)
{
    int ix, iy;

    SetWinEnable(0, 0, 0);

    gBmSt.flags |= BM_FLAG_0;

    RenderMap();

    for (iy = 9; iy >= 0; --iy)
        for (ix = 14; ix >= 0; --ix)
            PutLimitViewSquare(gBg2Tm, gBmSt.map_render_anchor.x + ix, gBmSt.map_render_anchor.y + iy, ix, iy);

    EnableBgSync(BG2_SYNC_BIT);
    SetBgOffset(2, 0, 0);

    switch (gPlaySt.chapter)
    {

    case CHAPTER_8:
    case CHAPTER_8X:
    case CHAPTER_14X:
    case CHAPTER_16:
    case CHAPTER_20X_I:
    case CHAPTER_24:
    case CHAPTER_FINAL:
        SetBlendAlpha(12, 7);
        break;

    default:
        SetBlendAlpha(10, 6);
        break;

    }

    SetBlendTargetA(0, 0, 1, 0, 0); SetBlendBackdropA(0);
    SetBlendTargetB(0, 0, 0, 1, 1); SetBlendBackdropB(1);

    InitBmBgLayers();
}

void LimitView_Loop(struct GenericProc * proc)
{
    int frame = (GetGameTime() / 2) & 0x1F;

    if (proc->unk4A & LIMITVIEW_BLUE)
        ApplyPaletteExt(Pal_LimitViewBlue + frame, 0x20*BGPAL_LIMITVIEW + 2, 0x20);

    if (proc->unk4A & LIMITVIEW_RED)
        ApplyPaletteExt(Pal_LimitViewRed + frame, 0x20*(BGPAL_LIMITVIEW+1) + 2, 0x20);

    if (proc->unk4A & LIMITVIEW_GREEN)
        ApplyPaletteExt(Pal_LimitViewGreen + frame, 0x20*(BGPAL_LIMITVIEW+1) + 2, 0x20);
}

void LimitView_Deinit(struct GenericProc * proc)
{
    if (proc->unk4A & LIMITVIEW_BLUE)
    {
        TmFill(gBg2Tm, 0);
        EnableBgSync(BG2_SYNC_BIT);
    }

    SetBlendConfig(0, 0, 0, 0);

    gBmSt.flags &= ~(BM_FLAG_1 | BM_FLAG_0);

    InitBmBgLayers();
}

void StartLimitView(int flags)
{
    struct GenericProc * proc;

    if ((proc = FindProc(ProcScr_LimitView)))
    {
        LimitView_Init(proc);
        OpenLimitView_Init(NULL);

        return;
    }

    proc = SpawnProc(ProcScr_LimitView, PROC_TREE_4);
    proc->unk4A = flags;
}

void EndLimitView(void)
{
    Proc_EndEach(ProcScr_LimitView);
}

static bool TrySetCursorOn(int uid)
{
    struct Unit * unit = GetUnit(uid);

    if (!unit)
        return FALSE;

    if (!unit->pinfo)
        return FALSE;

    if (unit->flags & (UNIT_FLAG_HIDDEN | UNIT_FLAG_TURN_ENDED | UNIT_FLAG_DEAD))
        return FALSE;

    if (unit->status == UNIT_STATUS_BERSERK || unit->status == UNIT_STATUS_SLEEP)
        return FALSE;

    CameraMoveWatchPosition(FindProc(ProcScr_PlayerPhase) ?: FindProc(ProcScr_PrepPhase), unit->x, unit->y);
    SetMapCursorPosition(unit->x, unit->y);

    return TRUE;
}

void TrySwitchViewedUnit(int x, int y)
{
    int i;

    int uid = gMapUnit[y][x];

    if ((0xC0 & uid) != FACTION_BLUE)
        uid = 0;

    uid = uid + 1;

    for (i = uid; i < 0x3F; ++i)
    {
        if (TrySetCursorOn(i))
            return;
    }

    for (i = 1; i <= uid; ++i)
    {
        if (TrySetCursorOn(i))
            return;
    }
}

static void PlayerPhase_HandleAutoEnd(ProcPtr proc)
{
    if (!gPlaySt.config_no_auto_end_turn && CountFactionMoveableUnits(gPlaySt.faction) == 0)
        Proc_Goto(proc, L_PLAYERPHASE_END);
}
