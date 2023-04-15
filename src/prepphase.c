#include "prepphase.h"

#include "hardware.h"
#include "oam.h"
#include "sound.h"
#include "sprite.h"
#include "spriteanim.h"
#include "event.h"
#include "msg.h"
#include "util.h"
#include "unit.h"
#include "map.h"
#include "bmfx.h"
#include "playerphase.h"
#include "unitsprite.h"
#include "chapter.h"
#include "unitrearrange.h"
#include "chapterinfo.h"
#include "subtitlehelp.h"
#include "menuinfo.h"
#include "mu.h"
#include "eventinfo.h"
#include "statscreen.h"
#include "mapui.h"

#include "constants/videoalloc_global.h"
#include "constants/pids.h"
#include "constants/songs.h"
#include "constants/msg.h"

enum
{
    // L_PLAYERPHASE_... labels are also valid

    L_PREPPHASE_BEGINMAP = 0x32,
};

static void PrepPhase_RightInitCamera(struct GenericProc * proc);
static void PrepPhase_DownInitCamera(struct GenericProc * proc);
static void PrepPhase_LeftInitCamera(struct GenericProc * proc);
static void PrepPhase_UpInitCamera(struct GenericProc * proc);
static void PrepPhase_InitCameraLoop(struct GenericProc * proc);
static void PrepPhase_Init(struct GenericProc * proc);
static void PrepPhase_WatchRoy(struct GenericProc * proc);
static void PrepPhase_MapIdle(struct GenericProc * proc);
static void PrepPhase_MapSwapSelectBegin(struct GenericProc * proc);
static void PrepPhase_MapSwapSelectIdle(struct GenericProc * proc);
static void PrepPhase_MapSwapSelectCancel(struct GenericProc * proc);
static void PrepPhase_MapSwapSelectApply(struct GenericProc * proc);
static void PrepPhase_MapSwapSelectFogFadeA(struct GenericProc * proc);
static void PrepPhase_MapSwapSelectFogFadeB(struct GenericProc * proc);

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
    PROC_CALL(func_fe6_0807B6BC),
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
    PROC_WHILE(IsSubtitleHelpActive),

    PROC_CALL(RefreshEntityMaps),
    PROC_CALL(StartMapUi),

    PROC_REPEAT(PrepPhase_MapIdle),

    // fallthrough

PROC_LABEL(L_PLAYERPHASE_MOVE),
    PROC_CALL(EndMapUi),

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
    PROC_CALL(EndMapUi),
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

static void PrepPhase_RightInitCamera(struct GenericProc * proc)
{
    StartBgm(SONG_22, NULL);

    proc->unk4A = FALSE;

    proc->x = 0;
    proc->y = 0;

    proc->unk34 = 2;
    proc->unk38 = 0;

    proc->unk4C = (gMapSize.x*16 - DISPLAY_WIDTH)/2;
}

static void PrepPhase_DownInitCamera(struct GenericProc * proc)
{
    proc->unk34 = 0;
    proc->unk38 = 2;

    proc->unk4C = (gMapSize.y*16 - DISPLAY_HEIGHT)/2;
}

static void PrepPhase_LeftInitCamera(struct GenericProc * proc)
{
    proc->unk34 = -2;
    proc->unk38 = 0;

    proc->unk4C = (gMapSize.x*16 - DISPLAY_WIDTH)/2;
}

static void PrepPhase_UpInitCamera(struct GenericProc * proc)
{
    proc->unk34 = 0;
    proc->unk38 = -2;

    proc->unk4C = (gMapSize.y*16 - DISPLAY_HEIGHT)/2;
}

static void PrepPhase_InitCameraLoop(struct GenericProc * proc)
{
    if (gKeySt->pressed & (KEY_BUTTON_A | KEY_BUTTON_B | KEY_BUTTON_START))
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

static void PrepPhase_Init(struct GenericProc * proc)
{
    if (!GetChapterInfo(gPlaySt.chapter)->has_prep)
    {
        Proc_End(proc);
        return;
    }

    if (!(gPlaySt.flags & PLAY_FLAG_4))
    {
        func_fe6_0807A07C();
        InitPlayerDeployUnits();

        gPlaySt.flags |= PLAY_FLAG_4;
    }

    gBmSt.flags |= BM_FLAG_4;

    gPlaySt.vision = GetChapterInfo(gPlaySt.chapter)->fog;

    RefreshEntityMaps();
    RenderMap();
}

static void PrepPhase_WatchRoy(struct GenericProc * proc)
{
    struct Unit * roy = GetUnitByPid(PID_ROY);

    SetMapCursorPosition(roy->x, roy->y);

    gBmSt.camera.x = GetCameraCenteredX(gBmSt.cursor.x*16);
    gBmSt.camera.y = GetCameraCenteredY(gBmSt.cursor.y*16);
}

static void PrepPhase_MapIdle(struct GenericProc * proc)
{
    HandlePlayerMapCursor();

    if (!IsMapFadeActive())
    {
        if (gKeySt->pressed & KEY_BUTTON_L)
        {
            TrySwitchViewedUnit(gBmSt.cursor.x, gBmSt.cursor.y);
            PlaySe(SONG_6B);

            goto put_map_cursor;
        }

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

                StartMenu(&MenuInfo_PrepMap);

                Proc_Goto(proc, L_PLAYERPHASE_BEGIN);

                return;

            case PLAYER_SELECT_CONTROL:
                UnitBeginAction(unit);
                gActiveUnit->flags &= ~UNIT_FLAG_HIDDEN;

                Proc_Goto(proc, L_PLAYERPHASE_END);

                return;

            case PLAYER_SELECT_NOCONTROL:
                UnitBeginAction(unit);
                gActiveUnit->flags &= ~UNIT_FLAG_HIDDEN;

                Proc_Goto(proc, L_PLAYERPHASE_MOVE);

                return;

            case PLAYER_SELECT_4:
                PlaySe(SONG_6C);

                return;

            }
        }

        if (gKeySt->pressed & KEY_BUTTON_SELECT)
        {
            EndMapUi();
            ResetTextFont();

            gPlaySt.x_cursor = gBmSt.cursor.x;
            gPlaySt.y_cursor = gBmSt.cursor.y;

            StartMenu(&MenuInfo_PrepMap);

            Proc_Goto(proc, L_PLAYERPHASE_BEGIN);

            return;
        }

        if (gKeySt->pressed & KEY_BUTTON_START)
        {
            EndMapUi();
            func_fe6_08087BC4();

            Proc_Goto(proc, L_PLAYERPHASE_BEGIN);

            return;
        }
    }

put_map_cursor:
    PutMapCursor(gBmSt.cursor_sprite.x, gBmSt.cursor_sprite.y, MAP_CURSOR_DEFAULT);
}

fu8 PrepMapMenuConfirm(struct MenuProc * menu, struct MenuEntProc * ent)
{
    ProcPtr proc = FindProc(ProcScr_PrepPhase);

    func_fe6_0807B6BC();
    Proc_Goto(proc, L_PREPPHASE_BEGINMAP);

    return MENU_ACTION_NOCURSOR | MENU_ACTION_END | MENU_ACTION_SE_6A | MENU_ACTION_CLEAR;
}

static void PrepPhase_MapSwapSelectBegin(struct GenericProc * proc)
{
    struct UnitInfo const * info;
    struct SpriteAnim * anim;

    info = GetDeployUnitInfoList();
    info++;

    MapFill(gMapRange, 0);
    MapFill(gMapMovement, -1);

    while (info->pid != 0)
    {
        gMapMovement[info->y_move][info->x_move] = 0;
        info++;
    }

    StartLimitView(LIMITVIEW_BLUE);

    anim = StartSpriteAnim(SpriteAnim_08102450, 0);
    anim->oam2 = OAM2_CHR(OBJCHR_SYSTEM_OBJECTS) + OAM2_PAL(OBJPAL_SYSTEM_OBJECTS);
    SetSpriteAnimId(anim, 0);
    proc->ptr = anim;

    proc->unk4A = 2;

    proc->unk3C = gBmSt.cursor.x;
    proc->unk40 = gBmSt.cursor.y;

    StartSubtitleHelp(proc, DecodeMsg(MSG_C25));
    CameraMoveWatchPosition(proc, gActiveUnit->x, gActiveUnit->y);
    PlaySe(SONG_69);
}

static void PrepPhase_MapSwapSelectIdle(struct GenericProc * proc)
{
    int x, y;

    bool isValid = ~gMapMovementSigned[gBmSt.cursor.y][gBmSt.cursor.x] ? TRUE : FALSE;

    HandlePlayerMapCursor();

    x = proc->unk3C*16 - gBmSt.camera.x;
    y = proc->unk40*16 - gBmSt.camera.y;

    if ((x + 0x10 >= 0) && (x <= DISPLAY_WIDTH))
        if ((y + 0x20 >= 0) && (y <= DISPLAY_HEIGHT))
            PutSprite(4, x, y-12, Sprite_16x16, OAM2_CHR(OBJCHR_SYSTEM_OBJECTS + 6) + OAM2_PAL(OBJPAL_SYSTEM_OBJECTS));

    if (gKeySt->pressed & KEY_BUTTON_A)
    {
        if (isValid)
        {
            EndSpriteAnim(proc->ptr);
            Proc_Break(proc);

            EndSubtitleHelp();

            return;
        }
        else
        {
            PlaySe(0x6C);

            return;
        }
    }

    if (gKeySt->pressed & KEY_BUTTON_B)
    {
        EndSpriteAnim(proc->ptr);
        Proc_Goto(proc, L_PLAYERPHASE_MAPFADE_MOVE);

        EndSubtitleHelp();

        PlaySe(0x6B);

        return;
    }

    if (isValid != proc->unk4A)
        SetSpriteAnimId(proc->ptr, isValid ? 0 : 1);

    DisplaySpriteAnim(proc->ptr, gBmSt.cursor_sprite.x-gBmSt.camera.x, gBmSt.cursor_sprite.y-gBmSt.camera.y);

    proc->unk4A = isValid;
}

static void PrepPhase_MapSwapSelectCancel(struct GenericProc * proc)
{
    SetMapCursorPosition(gActiveUnit->x, gActiveUnit->y);
    CameraMoveWatchPosition(proc, gActiveUnit->x, gActiveUnit->y);
}

static void PrepPhase_MapSwapSelectApply(struct GenericProc * proc)
{
    struct Unit * unitA = gActiveUnit;
    struct Unit * unitB = GetUnit(gMapUnit[gBmSt.cursor.y][gBmSt.cursor.x]);

    if (unitB == NULL)
    {
        func_fe6_0801CF10(proc, unitA, gBmSt.cursor.x, gBmSt.cursor.y);
    }
    else
    {
        func_fe6_0801CF10(proc, unitA, unitB->x, unitB->y);
        func_fe6_0801CF10(proc, unitB, unitA->x, unitA->y);
    }

    PlaySe(SONG_61);
}

static void PrepPhase_MapSwapSelectFogFadeA(struct GenericProc * proc)
{
    if (gPlaySt.vision != 0)
        RenderMapForFade();
}

static void PrepPhase_MapSwapSelectFogFadeB(struct GenericProc * proc)
{
    if (gPlaySt.vision != 0)
    {
        RenderMap();
        StartMapFade(FALSE);
    }
}

void func_fe6_0802B784(void)
{
    if (gPlaySt.flags & PLAY_FLAG_COMPLETE && !(gBmSt.flags & BM_FLAG_LINKARENA))
    {
        UnitRearrangeInit((struct Unit *) gBuf);

        FOR_UNITS(1, 0x40, unit,
        {
            if (!(unit->flags & UNIT_FLAG_UNAVAILABLE))
                UnitRearrangeAdd(unit);
        })

        UnitRearrangeApply2();
    }
}

void func_fe6_0802B7E4(void)
{
    func_fe6_0802B784();

    Proc_EndEach(ProcScr_PrepPhase);

    gBmSt.flags &= ~BM_FLAG_4;
    gPlaySt.flags &= ~PLAY_FLAG_4;
}
