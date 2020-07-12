
#include "prep-phase.h"

#include "hardware.h"
#include "oam.h"
#include "sound.h"
#include "sprite.h"
#include "anim.h"
#include "event.h"
#include "msg.h"
#include "util.h"
#include "unit.h"
#include "map.h"
#include "bmfx.h"
#include "player-phase.h"
#include "unitsprite.h"
#include "chapter.h"
#include "unit-rearrange.h"
#include "mu.h"

#include "constants/video-global.h"
#include "constants/pids.h"

enum
{
    // L_PLAYERPHASE_... labels are also valid

    L_PREPPHASE_BEGINMAP = 0x32,
};

static void PrepPhase_RightInitCamera(struct GenericProc* proc);
static void PrepPhase_DownInitCamera(struct GenericProc* proc);
static void PrepPhase_LeftInitCamera(struct GenericProc* proc);
static void PrepPhase_UpInitCamera(struct GenericProc* proc);
static void PrepPhase_InitCameraLoop(struct GenericProc* proc);
static void PrepPhase_Init(struct GenericProc* proc);
static void PrepPhase_WatchRoy(struct GenericProc* proc);
static void PrepPhase_MapIdle(struct GenericProc* proc);
static void PrepPhase_MapSwapSelectBegin(struct GenericProc* proc);
static void PrepPhase_MapSwapSelectIdle(struct GenericProc* proc);
static void PrepPhase_MapSwapSelectCancel(struct GenericProc* proc);
static void PrepPhase_MapSwapSelectApply(struct GenericProc* proc);
static void PrepPhase_MapSwapSelectFogFadeA(struct GenericProc* proc);
static void PrepPhase_MapSwapSelectFogFadeB(struct GenericProc* proc);

struct ProcScr CONST_DATA ProcScr_PrepPhase[] =
{
    PROC_19,

    PROC_CALL(PrepPhase_Init),

    PROC_CALL(StartMidFadeFromBlack),
    PROC_REPEAT(WhileFadeExists),

    PROC_CALL(PrepPhase_RightInitCamera),
    PROC_REPEAT(PrepPhase_InitCameraLoop),
    PROC_CALL(PrepPhase_DownInitCamera),
    PROC_REPEAT(PrepPhase_InitCameraLoop),
    PROC_CALL(PrepPhase_LeftInitCamera),
    PROC_REPEAT(PrepPhase_InitCameraLoop),
    PROC_CALL(PrepPhase_UpInitCamera),
    PROC_REPEAT(PrepPhase_InitCameraLoop),

    // fallthrough

PROC_LABEL(L_PLAYERPHASE_ACTION_SELECT),
    PROC_CALL(sub_807B6BC),
    PROC_SLEEP(0),

    PROC_CALL(PrepPhase_WatchRoy),

    // fallthrough

PROC_LABEL(L_PREPPHASE_BEGINMAP),
    PROC_CALL(InitBmDisplay),
    PROC_CALL(RefreshEntityMaps),
    PROC_CALL(RenderMap),
    PROC_CALL(RefreshUnitSprites),

    PROC_CALL(StartMidFadeFromBlack),
    PROC_REPEAT(WhileFadeExists),

    // fallthrough

PROC_LABEL(L_PLAYERPHASE_BEGIN),
    // fallthrough

PROC_LABEL(L_PLAYERPHASE_IDLE),
    PROC_WHILE(sub_802CB60),

    PROC_CALL(RefreshEntityMaps),
    PROC_CALL(sub_8073310),

    PROC_REPEAT(PrepPhase_MapIdle),

    // fallthrough

PROC_LABEL(L_PLAYERPHASE_MOVE),
    PROC_CALL(sub_8073324),

    PROC_CALL(PlayerPhase_BeginSeeActionRange),
    PROC_REPEAT(PlayerPhase_MoveSelectLoop),

    PROC_GOTO(L_PLAYERPHASE_BEGIN),

PROC_LABEL(L_PLAYERPHASE_5),
    PROC_CALL(InitBmDisplay),

    PROC_START_CHILD_LOCKING(ProcScr_Unk_085C5988),

    PROC_GOTO(L_PLAYERPHASE_BEGIN),

PROC_LABEL(L_PLAYERPHASE_6),
    PROC_CALL(PlayerPhase_0801BC84),

    PROC_GOTO(L_PLAYERPHASE_MOVE),

PROC_LABEL(L_PLAYERPHASE_END),
    PROC_CALL(sub_8073324),
    PROC_CALL(PrepPhase_MapSwapSelectBegin),

    PROC_WHILE_EXISTS(ProcScr_CamMove),

    PROC_REPEAT(PrepPhase_MapSwapSelectIdle),

    PROC_CALL(PrepPhase_MapSwapSelectApply),
    PROC_CALL(EndLimitView),

    PROC_WHILE_EXISTS(ProcScr_CamMove),

    PROC_CALL(PrepPhase_MapSwapSelectFogFadeA),
    PROC_SLEEP(0),
    PROC_CALL(PrepPhase_MapSwapSelectFogFadeB),

    PROC_GOTO(L_PLAYERPHASE_BEGIN),

PROC_LABEL(L_PLAYERPHASE_MAPFADE_MOVE),
    PROC_CALL(EndLimitView),

    PROC_WHILE_EXISTS(ProcScr_CamMove),

    PROC_CALL(PrepPhase_MapSwapSelectCancel),
    PROC_SLEEP(0),

    PROC_GOTO(L_PLAYERPHASE_BEGIN),

PROC_LABEL(L_PLAYERPHASE_SEE_RANGE),
    PROC_GOTO(L_PLAYERPHASE_MOVE),

    PROC_END,
};

static void PrepPhase_RightInitCamera(struct GenericProc* proc)
{
    StartBgm(0x22, NULL); // TODO: song ids

    proc->unk4A = FALSE;

    proc->x = 0;
    proc->y = 0;

    proc->unk34 = 2;
    proc->unk38 = 0;

    proc->unk4C = (gMapSize.x*16 - DISPLAY_WIDTH)/2;
}

static void PrepPhase_DownInitCamera(struct GenericProc* proc)
{
    proc->unk34 = 0;
    proc->unk38 = 2;

    proc->unk4C = (gMapSize.y*16 - DISPLAY_HEIGHT)/2;
}

static void PrepPhase_LeftInitCamera(struct GenericProc* proc)
{
    proc->unk34 = -2;
    proc->unk38 = 0;

    proc->unk4C = (gMapSize.x*16 - DISPLAY_WIDTH)/2;
}

static void PrepPhase_UpInitCamera(struct GenericProc* proc)
{
    proc->unk34 = 0;
    proc->unk38 = -2;

    proc->unk4C = (gMapSize.y*16 - DISPLAY_HEIGHT)/2;
}

static void PrepPhase_InitCameraLoop(struct GenericProc* proc)
{
    if (gKeySt->pressed & (A_BUTTON | B_BUTTON | START_BUTTON))
        proc->unk4A = TRUE;

    if (proc->unk4A && (proc->x & 0x0F) == 0 && (proc->y & 0x0F) == 0)
    {
        Proc_Goto(proc, L_PLAYERPHASE_ACTION_SELECT);
        return;
    }

    proc->x += proc->unk34;
    proc->y += proc->unk38;

    gBmSt.camera.x = proc->x;
    gBmSt.camera.y = proc->y;

    --proc->unk4C;

    if (proc->unk4C <= 0)
        Proc_Break(proc);
}

static void PrepPhase_Init(struct GenericProc* proc)
{
    if (!GetChapterInfo(gPlaySt.chapter)->hasPrep)
    {
        Proc_End(proc);
        return;
    }

    if (!(gPlaySt.flags & PLAY_FLAG_4))
    {
        sub_807A07C();
        InitPlayerDeployUnits();

        gPlaySt.flags |= PLAY_FLAG_4;
    }

    gBmSt.flags |= BM_FLAG_4;

    gPlaySt.vision = GetChapterInfo(gPlaySt.chapter)->fog;

    RefreshEntityMaps();
    RenderMap();
}

static void PrepPhase_WatchRoy(struct GenericProc* proc)
{
    struct Unit* roy = GetUnitByPid(PID_ROY);

    SetMapCursorPosition(roy->x, roy->y);

    gBmSt.camera.x = GetCameraCenteredX(gBmSt.cursor.x*16);
    gBmSt.camera.y = GetCameraCenteredY(gBmSt.cursor.y*16);
}

static void PrepPhase_MapIdle(struct GenericProc* proc)
{
    HandlePlayerMapCursor();

    if (!IsMapFadeActive())
    {
        if (gKeySt->pressed & L_BUTTON)
        {
            TrySwitchViewedUnit(gBmSt.cursor.x, gBmSt.cursor.y);
            PlaySe(0x6B); // TODO: song ids

            goto put_map_cursor;
        }

        if ((gKeySt->pressed & R_BUTTON) && gMapUnit[gBmSt.cursor.y][gBmSt.cursor.x] != 0)
        {
            MU_EndAll();
            sub_8073324();
            sub_806EAE4(0x28C);

            sub_80702BC(GetUnit(gMapUnit[gBmSt.cursor.y][gBmSt.cursor.x]), proc);
            Proc_Goto(proc, L_PLAYERPHASE_5);

            return;
        }

        if (gKeySt->pressed & A_BUTTON)
        {
            struct Unit* unit = GetUnit(gMapUnit[gBmSt.cursor.y][gBmSt.cursor.x]);

            switch (GetPlayerSelectKind(unit))
            {

            case PLAYER_SELECT_NOUNIT:
            case PLAYER_SELECT_TURNENDED:
                sub_8073324();

                gPlaySt.xCursor = gBmSt.cursor.x;
                gPlaySt.yCursor = gBmSt.cursor.y;

                sub_8041834(&MenuInfo_085C7624);

                Proc_Goto(proc, L_PLAYERPHASE_BEGIN);

                return;

            case PLAYER_SELECT_CONTROL:
                UnitBeginAction(unit);
                gActiveUnit->state &= ~US_HIDDEN;

                Proc_Goto(proc, L_PLAYERPHASE_END);

                return;

            case PLAYER_SELECT_NOCONTROL:
                UnitBeginAction(unit);
                gActiveUnit->state &= ~US_HIDDEN;

                Proc_Goto(proc, L_PLAYERPHASE_MOVE);

                return;

            case PLAYER_SELECT_4:
                PlaySe(0x6C); // TODO: song ids

                return;

            }
        }

        if (gKeySt->pressed & SELECT_BUTTON)
        {
            sub_8073324();
            ResetTextFont();

            gPlaySt.xCursor = gBmSt.cursor.x;
            gPlaySt.yCursor = gBmSt.cursor.y;

            sub_8041834(&MenuInfo_085C7624);

            Proc_Goto(proc, L_PLAYERPHASE_BEGIN);

            return;
        }

        if (gKeySt->pressed & START_BUTTON)
        {
            sub_8073324();
            sub_8087BC4();

            Proc_Goto(proc, L_PLAYERPHASE_BEGIN);

            return;
        }
    }

put_map_cursor:
    PutMapCursor(gBmSt.cursorSpr.x, gBmSt.cursorSpr.y, MAP_CURSOR_DEFAULT);
}

u8 sub_802B47C(struct MenuProc* menu, struct MenuEntProc* ent)
{
    ProcPtr proc = Proc_Find(ProcScr_PrepPhase);

    sub_807B6BC();
    Proc_Goto(proc, L_PREPPHASE_BEGINMAP);

    return MENU_ACT_SKIPCURSOR | MENU_ACT_END | MENU_ACT_SE_6A | MENU_ACT_CLEAR;
}

static void PrepPhase_MapSwapSelectBegin(struct GenericProc* proc)
{
    struct UnitInfo const* info;
    struct Anim* anim;

    info = sub_806B638();
    info++;

    MapFill(gMapRange, 0);
    MapFill(gMapMovement, -1);

    while (info->pid != 0)
    {
        gMapMovement[info->yMove][info->xMove] = 0;
        info++;
    }

    StartLimitView(LIMITVIEW_BLUE);

    anim = StartAnim(Anim_08102450, 0);
    anim->oam2 = OAM2_CHR(OBJCHR_SYSTEM_OBJECTS) + OAM2_PAL(OBJPAL_SYSTEM_OBJECTS);
    Anim_SetAnimId(anim, 0);
    proc->ptr = anim;

    proc->unk4A = 2;

    proc->unk3C = gBmSt.cursor.x;
    proc->unk40 = gBmSt.cursor.y;

    sub_802CB14(proc, DecodeMsg(0xC25)); // TODO: msg ids
    CameraMoveWatchPosition(proc, gActiveUnit->x, gActiveUnit->y);
    PlaySe(0x69); // TODO: song ids
}

static void PrepPhase_MapSwapSelectIdle(struct GenericProc* proc)
{
    int x, y;

    Bool isValid = ~gMapMovementSigned[gBmSt.cursor.y][gBmSt.cursor.x] ? TRUE : FALSE;

    HandlePlayerMapCursor();

    x = proc->unk3C*16 - gBmSt.camera.x;
    y = proc->unk40*16 - gBmSt.camera.y;

    if ((x + 0x10 >= 0) && (x <= DISPLAY_WIDTH))
        if ((y + 0x20 >= 0) && (y <= DISPLAY_HEIGHT))
            PutSprite(4, x, y-12, Sprite_16x16, OAM2_CHR(OBJCHR_SYSTEM_OBJECTS + 6) + OAM2_PAL(OBJPAL_SYSTEM_OBJECTS));

    if (gKeySt->pressed & A_BUTTON)
    {
        if (isValid)
        {
            Anim_End(proc->ptr);
            Proc_Break(proc);

            sub_802CB50();

            return;
        }
        else
        {
            PlaySe(0x6C);

            return;
        }
    }

    if (gKeySt->pressed & B_BUTTON)
    {
        Anim_End(proc->ptr);
        Proc_Goto(proc, L_PLAYERPHASE_MAPFADE_MOVE);

        sub_802CB50();

        PlaySe(0x6B);

        return;
    }

    if (isValid != proc->unk4A)
        Anim_SetAnimId(proc->ptr, isValid ? 0 : 1);

    Anim_Display(proc->ptr, gBmSt.cursorSpr.x-gBmSt.camera.x, gBmSt.cursorSpr.y-gBmSt.camera.y);

    proc->unk4A = isValid;
}

static void PrepPhase_MapSwapSelectCancel(struct GenericProc* proc)
{
    SetMapCursorPosition(gActiveUnit->x, gActiveUnit->y);
    CameraMoveWatchPosition(proc, gActiveUnit->x, gActiveUnit->y);
}

static void PrepPhase_MapSwapSelectApply(struct GenericProc* proc)
{
    struct Unit* unitA = gActiveUnit;
    struct Unit* unitB = GetUnit(gMapUnit[gBmSt.cursor.y][gBmSt.cursor.x]);

    if (unitB == NULL)
    {
        sub_801CF10(proc, unitA, gBmSt.cursor.x, gBmSt.cursor.y);
    }
    else
    {
        sub_801CF10(proc, unitA, unitB->x, unitB->y);
        sub_801CF10(proc, unitB, unitA->x, unitA->y);
    }

    PlaySe(0x61); // TODO: song ids
}

static void PrepPhase_MapSwapSelectFogFadeA(struct GenericProc* proc)
{
    if (gPlaySt.vision != 0)
        RenderMapForFade();
}

static void PrepPhase_MapSwapSelectFogFadeB(struct GenericProc* proc)
{
    if (gPlaySt.vision != 0)
    {
        RenderMap();
        StartMapFade(FALSE);
    }
}

void sub_802B784(void)
{
    if (gPlaySt.flags & PLAY_FLAG_5 && !(gBmSt.flags & BM_FLAG_LINKARENA))
    {
        UnitRearrangeInit((struct Unit*) gBuf);

        FOR_UNITS(1, 0x40, unit,
        {
            if (!(unit->state & US_UNAVAILABLE))
                UnitRearrangeAdd(unit);
        })

        UnitRearrangeApply2();
    }
}

void sub_802B7E4(void)
{
    sub_802B784();

    Proc_EndEach(ProcScr_PrepPhase);

    gBmSt.flags &= ~BM_FLAG_4;
    gPlaySt.flags &= ~PLAY_FLAG_4;
}
