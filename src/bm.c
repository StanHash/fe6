
#include "common.h"
#include "bm.h"

#include "hardware.h"
#include "move.h"
#include "oam.h"
#include "sound.h"
#include "proc.h"
#include "sprite.h"
#include "icon.h"
#include "text.h"
#include "face.h"
#include "util.h"
#include "unit.h"
#include "map.h"
#include "playerphase.h"
#include "bmfx.h"
#include "faction.h"
#include "unitsprite.h"
#include "support.h"
#include "trap.h"
#include "action.h"
#include "prepphase.h"
#include "chapterinfo.h"
#include "masseffect.h"
#include "ai_phase.h"
#include "ui.h"
#include "eventinfo.h"
#include "save.h"

#include "constants/videoalloc_global.h"
#include "constants/songs.h"

enum
{
    CAMERA_MARGIN_LEFT   = 16*3,
    CAMERA_MARGIN_RIGHT  = 16*11,
    CAMERA_MARGIN_TOP    = 16*2,
    CAMERA_MARGIN_BOTTOM = 16*7,
};

struct CamMoveProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ struct Vec2i to;
    /* 30 */ struct Vec2i from;
    /* 34 */ struct Vec2i watchedCoord;
    /* 38 */ short calibration;
    /* 3A */ short distance;
    /* 3C */ int frame;
    /* 40 */ bool8 xCalibrated;
};

struct UnkMapCursorProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ struct Vec2i to;
    /* 30 */ struct Vec2i from;
    /* 34 */ int clock;
    /* 38 */ int duration;
};

static void HandleChangePhase(void);

static int BmMain_ChangePhase(ProcPtr proc);
static void BmMain_StartPhase(ProcPtr proc);
static void BmMain_ResumePlayerPhase(ProcPtr proc);
static int BmMain_UpdateTraps(ProcPtr proc);
static void BmMain_SuspendBeforePhase(ProcPtr proc);

static void CamMove_OnInit(struct CamMoveProc * proc);
static void CamMove_OnLoop(struct CamMoveProc * proc);

static void UnkMapCursor_OnLoop(struct UnkMapCursorProc * proc);

struct ProcScr CONST_DATA ProcScr_BmMain[] =
{
    PROC_19,
    PROC_19,
    PROC_MARK(PROC_MARK_2),
    PROC_SLEEP(0),

PROC_LABEL(L_BMMAIN_INIT),
    PROC_START_CHILD_LOCKING(ProcScr_PrepPhase),
    PROC_START_CHILD_LOCKING(ProcScr_ChapterIntro),

    // fallthrough

PROC_LABEL(L_BMMAIN_CHANGEPHASE),
    PROC_CALL_2(BmMain_ChangePhase),
    PROC_CALL(BmMain_SuspendBeforePhase),

    // fallthrough

PROC_LABEL(L_BMMAIN_STARTPHASE),
    PROC_START_CHILD(ProcScr_InitPhaseCursor),
    PROC_START_CHILD_LOCKING(ProcScr_PhaseIntro),
    PROC_WHILE_EXISTS(ProcScr_CamMove),

    PROC_CALL(TickActiveFactionTurnAndListStatusHeals),
    PROC_START_CHILD_LOCKING(ProcScr_StatusDecayDisplay),

    PROC_START_CHILD_LOCKING(ProcScr_TerrainHealDisplay),
    PROC_START_CHILD_LOCKING(ProcScr_PoisonDamageDisplay),

    PROC_START_CHILD_LOCKING(ProcScr_InitPhaseCursor),

    // fallthrough

PROC_LABEL(L_BMMAIN_DURINGPHASE),
    PROC_REPEAT(BmMain_StartPhase),
    PROC_START_CHILD_LOCKING(ProcScr_AiPhase_Berserk),

    PROC_CALL_2(BmMain_UpdateTraps),

    PROC_GOTO(L_BMMAIN_CHANGEPHASE),

PROC_LABEL(L_BMMAIN_2),
    PROC_CALL(RenderMap),
    PROC_CALL(StartMapSongBgm),

    PROC_CALL(StartMidFadeFromBlack),
    PROC_REPEAT(WhileFadeExists),

    PROC_GOTO(L_BMMAIN_DURINGPHASE),

PROC_LABEL(L_BMMAIN_4),
    PROC_CALL(RenderMap),
    PROC_CALL(StartMapSongBgm),

    PROC_CALL(StartMidFadeFromBlack),
    PROC_REPEAT(WhileFadeExists),

    PROC_REPEAT(BmMain_ResumePlayerPhase),
    PROC_START_CHILD_LOCKING(ProcScr_AiPhase_Berserk),

    PROC_GOTO(L_BMMAIN_CHANGEPHASE),

PROC_LABEL(L_BMMAIN_8),
    PROC_SLEEP(0),

    PROC_REPEAT(BmMain_ResumePlayerPhase),
    PROC_START_CHILD_LOCKING(ProcScr_AiPhase_Berserk),

    PROC_GOTO(L_BMMAIN_CHANGEPHASE),

PROC_LABEL(L_BMMAIN_6),
    PROC_CALL(RenderMap),
    PROC_CALL(StartMapSongBgm),

    PROC_CALL(StartMidFadeFromBlack),
    PROC_REPEAT(WhileFadeExists),

    PROC_GOTO(L_BMMAIN_STARTPHASE),

PROC_LABEL(L_BMMAIN_5),
    PROC_CALL(RenderMap),
    PROC_CALL(StartMapSongBgm),

    PROC_CALL(StartMidFadeFromBlack),
    PROC_REPEAT(WhileFadeExists),

    PROC_START_CHILD_LOCKING(ProcScr_AiPhase_Berserk),

    PROC_GOTO(L_BMMAIN_CHANGEPHASE),

    PROC_END,
};

static i8 CONST_DATA sDirKeysToOffsetLut[][2] =
{
    {  0,  0 }, // 0000 none
    { +1,  0 }, // 0001 right
    { -1,  0 }, // 0010 left
    {  0,  0 }, // 0011 right + left
    {  0, -1 }, // 0100 up
    { +1, -1 }, // 0101 up + right
    { -1, -1 }, // 0110 up + left
    {  0,  0 }, // 0111 up + right + left
    {  0, +1 }, // 1000 down
    { +1, +1 }, // 1001 down + right
    { -1, +1 }, // 1010 down + left
    {  0,  0 }, // 1011 down + right + left
    {  0,  0 }, // 1100 down + up
    {  0,  0 }, // 1101 down + up + right
    {  0,  0 }, // 1110 down + up + left
    {  0,  0 }, // 1111 down + up + right + left
};

static u16 CONST_DATA Sprite_MapCursorA[] =
{
    4,
    OAM0_Y(-4) | OAM0_SHAPE_8x8, OAM1_X(-2)  | OAM1_SIZE_8x8,                           0,
    OAM0_Y(-4) | OAM0_SHAPE_8x8, OAM1_X(+10) | OAM1_SIZE_8x8 | OAM1_HFLIP,              0,
    OAM0_Y(+9) | OAM0_SHAPE_8x8, OAM1_X(-2)  | OAM1_SIZE_8x8 | OAM1_VFLIP,              0,
    OAM0_Y(+9) | OAM0_SHAPE_8x8, OAM1_X(+10) | OAM1_SIZE_8x8 | OAM1_HFLIP | OAM1_VFLIP, 0,
};

static u16 CONST_DATA Sprite_MapCursorB[] =
{
    4,
    OAM0_Y(-3) | OAM0_SHAPE_8x8, OAM1_X(-1) | OAM1_SIZE_8x8,                           0,
    OAM0_Y(-3) | OAM0_SHAPE_8x8, OAM1_X(+9) | OAM1_SIZE_8x8 | OAM1_HFLIP,              0,
    OAM0_Y(+8) | OAM0_SHAPE_8x8, OAM1_X(-1) | OAM1_SIZE_8x8 | OAM1_VFLIP,              0,
    OAM0_Y(+8) | OAM0_SHAPE_8x8, OAM1_X(+9) | OAM1_SIZE_8x8 | OAM1_HFLIP | OAM1_VFLIP, 0,
};

static u16 CONST_DATA Sprite_MapCursorC[] =
{
    4,
    OAM0_Y(-2) | OAM0_SHAPE_8x8, OAM1_X(-0) | OAM1_SIZE_8x8,                           0,
    OAM0_Y(-2) | OAM0_SHAPE_8x8, OAM1_X(+8) | OAM1_SIZE_8x8 | OAM1_HFLIP,              0,
    OAM0_Y(+7) | OAM0_SHAPE_8x8, OAM1_X(-0) | OAM1_SIZE_8x8 | OAM1_VFLIP,              0,
    OAM0_Y(+7) | OAM0_SHAPE_8x8, OAM1_X(+8) | OAM1_SIZE_8x8 | OAM1_HFLIP | OAM1_VFLIP, 0,
};

static u16 CONST_DATA Sprite_MapCursorStretched[] =
{
    4,
    OAM0_Y(-8)  | OAM0_SHAPE_8x8, OAM1_X(-4)  | OAM1_SIZE_8x8,                           0,
    OAM0_Y(-8)  | OAM0_SHAPE_8x8, OAM1_X(+12) | OAM1_SIZE_8x8 | OAM1_HFLIP,              0,
    OAM0_Y(+10) | OAM0_SHAPE_8x8, OAM1_X(-4)  | OAM1_SIZE_8x8 | OAM1_VFLIP,              0,
    OAM0_Y(+10) | OAM0_SHAPE_8x8, OAM1_X(+12) | OAM1_SIZE_8x8 | OAM1_HFLIP | OAM1_VFLIP, 0,
};

static u16 const * CONST_DATA sMapCursorSpriteLut[] =
{
    Sprite_MapCursorA,
    Sprite_MapCursorA,
    Sprite_MapCursorA,
    Sprite_MapCursorA,
    Sprite_MapCursorA,
    Sprite_MapCursorA,
    Sprite_MapCursorA,
    Sprite_MapCursorA,
    Sprite_MapCursorA,
    Sprite_MapCursorA,

    Sprite_MapCursorB,

    Sprite_MapCursorC,
    Sprite_MapCursorC,
    Sprite_MapCursorC,
    Sprite_MapCursorC,

    Sprite_MapCursorB,
};

u16 CONST_DATA Sprite_SysUpArrowA[] =
{
    1, OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x4C),
};

u16 CONST_DATA Sprite_SysUpArrowB[] =
{
    1, OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x4D),
};

u16 CONST_DATA Sprite_SysUpArrowC[] =
{
    1, OAM0_SHAPE_8x16 | OAM0_Y(-1), OAM1_SIZE_8x16, OAM2_CHR(0x4D),
};

u16 CONST_DATA Sprite_SysDownArrowA[] =
{
    1, OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x4E),
};

u16 CONST_DATA Sprite_SysDownArrowB[] =
{
    1, OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(0x4F),
};

u16 CONST_DATA Sprite_SysDownArrowC[] =
{
    1, OAM0_SHAPE_8x16 | OAM0_Y(+1), OAM1_SIZE_8x16, OAM2_CHR(0x4F),
};

u16 const * CONST_DATA gSysUpArrowSpriteLut[] =
{
    Sprite_SysUpArrowA,
    Sprite_SysUpArrowB,
    Sprite_SysUpArrowC,
};

u16 const * CONST_DATA gSysDownArrowSpriteLut[] =
{
    Sprite_SysDownArrowA,
    Sprite_SysDownArrowB,
    Sprite_SysDownArrowC,
};

struct ProcScr CONST_DATA ProcScr_CamMove[] =
{
    PROC_19,
    PROC_SLEEP(0),

    PROC_CALL(CamMove_OnInit),
    PROC_REPEAT(CamMove_OnLoop),

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_UnkMapCursor[] =
{
    PROC_REPEAT(UnkMapCursor_OnLoop),
    PROC_END,
};

struct BmSt EWRAM_DATA gBmSt = {};
struct PlaySt EWRAM_DATA gPlaySt = {};

static struct Vec2i EWRAM_DATA sLastCoordMapCursorDrawn = {};
static u32 EWRAM_DATA sLastTimeMapCursorDrawn = 0;

static i8 EWRAM_DATA sCameraAnimTable[0x100] = {};

void OnVBlank(void)
{
    INTR_CHECK = INTR_FLAG_VBLANK;

    IncGameTime();
    m4aSoundVSync();

    Proc_Run(gProcTreeRootArray[0]);

    SyncLoOam();

    if (gBmSt.main_loop_ended)
    {
        gBmSt.main_loop_ended = FALSE;

        SyncDispIo();
        SyncBgsAndPal();
        ApplyDataMoves();
        SyncHiOam();
    }

    m4aSoundMain();
}

void OnMain(void)
{
    RefreshKeySt(gKeySt);

    ClearSprites();

    Proc_Run(gProcTreeRootArray[1]);

    if (GetGameLock() == 0)
        Proc_Run(gProcTreeRootArray[2]);

    Proc_Run(gProcTreeRootArray[3]);

    Proc_Run(gProcTreeRootArray[5]);
    PutSpriteLayerOam(0);

    Proc_Run(gProcTreeRootArray[4]);
    PutSpriteLayerOam(13);

    gBmSt.main_loop_ended = TRUE;
    gBmSt.main_loop_end_scanline = REG_VCOUNT;

    VBlankIntrWait();
}

void LockGame(void)
{
    gBmSt.lock++;
}

void UnlockGame(void)
{
    gBmSt.lock--;
}

u8 GetGameLock(void)
{
    return gBmSt.lock;
}

static void HandleChangePhase(void)
{
    switch (gPlaySt.faction)
    {

    case FACTION_BLUE:
        gPlaySt.faction = FACTION_RED;
        break;

    case FACTION_RED:
        gPlaySt.faction = FACTION_GREEN;
        break;

    case FACTION_GREEN:
        gPlaySt.faction = FACTION_BLUE;

        if (gPlaySt.turn < 999)
            gPlaySt.turn++;

        DoTurnSupportExp();
        break;

    }
}

int BmMain_ChangePhase(ProcPtr proc)
{
    ClearActiveFactionTurnEndedState();
    RefreshUnitSprites();

    HandleChangePhase();

    if (CheckAvailableTurnEvent() == TRUE)
    {
        StartAvailableTurnEvents();
        return FALSE;
    }

    return TRUE;
}

void BmMain_StartPhase(ProcPtr proc)
{
    switch (gPlaySt.faction)
    {

    case FACTION_BLUE:
        SpawnProcLocking(ProcScr_PlayerPhase, proc);
        break;

    case FACTION_RED:
        SpawnProcLocking(ProcScr_AiPhase, proc);
        break;

    case FACTION_GREEN:
        SpawnProcLocking(ProcScr_AiPhase, proc);
        break;

    }

    Proc_Break(proc);
}

void BmMain_ResumePlayerPhase(ProcPtr proc)
{
    Proc_Goto(SpawnProcLocking(ProcScr_PlayerPhase, proc), L_PLAYERPHASE_ACTION);
    Proc_Break(proc);
}

int BmMain_UpdateTraps(ProcPtr proc)
{
    if (gPlaySt.faction != FACTION_GREEN)
        return TRUE;

    SpawnProcLocking(ProcScr_UpdateTraps, proc);
    return FALSE;
}

void BmMain_SuspendBeforePhase(ProcPtr proc)
{
    gAction.suspend_point = SUSPEND_POINT_CHANGE_PHASE;
    WriteSuspendSave(SAVE_ID_SUSPEND);
}

void InitBmBgLayers(void)
{
    if (gPlaySt.weather == WEATHER_CLOUDS)
    {
        gDispIo.bg0_ct.priority = 0;
        gDispIo.bg1_ct.priority = 1;
        gDispIo.bg2_ct.priority = 2;
        gDispIo.bg3_ct.priority = 2;
    }
    else
    {
        gDispIo.bg0_ct.priority = 0;
        gDispIo.bg1_ct.priority = 1;
        gDispIo.bg2_ct.priority = 2;
        gDispIo.bg3_ct.priority = 3;
    }
}

void ApplySystemObjectsGraphics(void)
{
    Decompress(Img_SystemObjects, gBuf);
    Copy2dChr(gBuf, OBJ_VRAM0 + CHR_SIZE * OBJCHR_SYSTEM_OBJECTS, 18, 4);

    ApplyPalettes(Pal_SystemObjects, 0x10 + OBJPAL_SYSTEM_OBJECTS, 2);
}

void ApplySystemGraphics(void)
{
    ResetText();
    UnpackUiWindowFrameGraphics();
    InitFaces();
    InitIcons();
    ApplyIconPalettes(BGPAL_ICONS);
    ApplySystemObjectsGraphics();
}

void HandleMapCursorInput(u16 keys)
{
    int dir = (keys >> 4) & (KEY_DPAD_ANY >> 4);

    struct Vec2i newCursor =
    {
        .x = gBmSt.cursor.x + sDirKeysToOffsetLut[dir][0],
        .y = gBmSt.cursor.y + sDirKeysToOffsetLut[dir][1],
    };

    if (gBmSt.flags & BM_FLAG_1)
    {
        if (gMapMovement[gBmSt.cursor.y][gBmSt.cursor.x] < MAP_MOVEMENT_MAX)
            if (gMapMovement[newCursor.y][newCursor.x] >= MAP_MOVEMENT_MAX)
                if ((keys & KEY_DPAD_ANY) != (gKeySt->pressed & KEY_DPAD_ANY))
                    return;
    }

    if (newCursor.x >= 0 && newCursor.x < gMapSize.x)
    {
        gBmSt.cursor_sprite_target.x += sDirKeysToOffsetLut[dir][0]*16;

        gBmSt.cursor_previous.x = gBmSt.cursor.x;
        gBmSt.cursor.x = newCursor.x;
    }

    if (newCursor.y >= 0 && newCursor.y < gMapSize.y)
    {
        gBmSt.cursor_sprite_target.y += sDirKeysToOffsetLut[dir][1]*16;

        gBmSt.cursor_previous.y = gBmSt.cursor.y;
        gBmSt.cursor.y = newCursor.y;
    }

    if (!(gBmSt.flags & BM_FLAG_2))
    {
        if (gBmSt.cursor.x != gBmSt.cursor_previous.x || gBmSt.cursor.y != gBmSt.cursor_previous.y)
        {
            PlaySe(SONG_65);
            gBmSt.flags |= BM_FLAG_2;
        }
    }
    else
    {
        gBmSt.flags &= ~BM_FLAG_2;
    }
}

void HandleMoveMapCursor(int step)
{
    if (gBmSt.cursor_sprite.x < gBmSt.cursor_sprite_target.x)
        gBmSt.cursor_sprite.x += step;

    if (gBmSt.cursor_sprite.x > gBmSt.cursor_sprite_target.x)
        gBmSt.cursor_sprite.x -= step;

    if (gBmSt.cursor_sprite.y < gBmSt.cursor_sprite_target.y)
        gBmSt.cursor_sprite.y += step;

    if (gBmSt.cursor_sprite.y > gBmSt.cursor_sprite_target.y)
        gBmSt.cursor_sprite.y -= step;
}

void HandleMoveCameraWithMapCursor(int step)
{
    bool updated = FALSE;

    int xCursorSpr = gBmSt.cursor_sprite.x;
    int yCursorSpr = gBmSt.cursor_sprite.y;

    if (gBmSt.camera.x + CAMERA_MARGIN_LEFT > xCursorSpr)
    {
        if (xCursorSpr - CAMERA_MARGIN_LEFT < 0)
        {
            gBmSt.camera.x = 0;
        }
        else
        {
            updated = TRUE;

            gBmSt.camera.x -= step;
            gBmSt.unk_36 = -step;

            gBmSt.unk_32 = gBmSt.camera.x & 0xF;
        }
    }

    if (gBmSt.camera.x + CAMERA_MARGIN_RIGHT < xCursorSpr)
    {
        if (xCursorSpr - CAMERA_MARGIN_RIGHT > gBmSt.camera_max.x)
        {
            gBmSt.camera.x = gBmSt.camera_max.x;
        }
        else
        {
            updated = TRUE;

            gBmSt.camera.x += step;
            gBmSt.unk_36 = +step;

            gBmSt.unk_32 = gBmSt.camera.x & 0xF;
        }
    }

    if (gBmSt.camera.y + CAMERA_MARGIN_TOP > yCursorSpr)
    {
        if (yCursorSpr - CAMERA_MARGIN_TOP < 0)
        {
            gBmSt.camera.y = 0;
        }
        else
        {
            updated = TRUE;

            gBmSt.camera.y -= step;
            gBmSt.unk_37 = -step;

            gBmSt.unk_34 = gBmSt.camera.y & 0xF;
        }
    }

    if (gBmSt.camera.y + CAMERA_MARGIN_BOTTOM < yCursorSpr)
    {
        if (yCursorSpr - CAMERA_MARGIN_BOTTOM > gBmSt.camera_max.y)
        {
            gBmSt.camera.y = gBmSt.camera_max.y;
        }
        else
        {
            updated = TRUE;

            gBmSt.camera.y += step;
            gBmSt.unk_37 = +step;

            gBmSt.unk_34 = gBmSt.camera.y & 0xF;
        }
    }

    if (!updated)
    {
        if (gBmSt.unk_32 != 0)
        {
            gBmSt.unk_32 = (gBmSt.unk_32 + gBmSt.unk_36) & 0xF;
            gBmSt.camera.x += gBmSt.unk_36;
        }

        if (gBmSt.unk_34 != 0)
        {
            gBmSt.unk_34 = (gBmSt.unk_34 + gBmSt.unk_37) & 0xF;
            gBmSt.camera.y += gBmSt.unk_37;
        }
    }
}

u16 GetCameraAdjustedX(int x)
{
    int result = gBmSt.camera.x;

    if (gBmSt.camera.x + CAMERA_MARGIN_LEFT > x)
    {
        result = (x - CAMERA_MARGIN_LEFT) < 0
            ? 0 : (x - CAMERA_MARGIN_LEFT);
    }

    if (gBmSt.camera.x + CAMERA_MARGIN_RIGHT < x)
    {
        result = (x - CAMERA_MARGIN_RIGHT) > gBmSt.camera_max.x
            ? gBmSt.camera_max.x : (x - CAMERA_MARGIN_RIGHT);
    }

    return result;
}

u16 GetCameraAdjustedY(int y)
{
    int result = gBmSt.camera.y;

    if (gBmSt.camera.y + CAMERA_MARGIN_TOP > y)
    {
        result = (y - CAMERA_MARGIN_TOP) < 0
            ? 0 : (y - CAMERA_MARGIN_TOP);
    }

    if (gBmSt.camera.y + CAMERA_MARGIN_BOTTOM < y)
    {
        result = (y - CAMERA_MARGIN_BOTTOM) > gBmSt.camera_max.y
            ? gBmSt.camera_max.y : (y - CAMERA_MARGIN_BOTTOM);
    }

    return result;
}

u16 GetCameraCenteredX(int x)
{
    int result = x - DISPLAY_WIDTH/2;

    if (result < 0)
        result = 0;

    if (result > gBmSt.camera_max.x)
        result = gBmSt.camera_max.x;

    return result &~ 0xF;
}

u16 GetCameraCenteredY(int y)
{
    int result = y - DISPLAY_HEIGHT/2;

    if (result < 0)
        result = 0;

    if (result > gBmSt.camera_max.y)
        result = gBmSt.camera_max.y;

    return result &~ 0xF;
}

void PutMapCursor(int x, int y, int kind)
{
    int oam2 = 0;
    u16 const * sprite = NULL;

    int frame = (GetGameTime() / 2) % ARRAY_COUNT(sMapCursorSpriteLut);

    switch (kind)
    {

    case MAP_CURSOR_DEFAULT:
    case MAP_CURSOR_REGULAR:
        oam2 = OAM2_CHR(OBJCHR_SYSTEM_OBJECTS + 0x02) + OAM2_PAL(OBJPAL_SYSTEM_OBJECTS);
        sprite = sMapCursorSpriteLut[frame];

        break;

    case MAP_CURSOR_RED_MOVING:
        if (GetGameTime()-1 == sLastTimeMapCursorDrawn)
        {
            x = (x + sLastCoordMapCursorDrawn.x) >> 1;
            y = (y + sLastCoordMapCursorDrawn.y) >> 1;
        }

        oam2 = OAM2_CHR(OBJCHR_SYSTEM_OBJECTS + 0x24) + OAM2_PAL(OBJPAL_SYSTEM_OBJECTS);
        sprite = sMapCursorSpriteLut[frame];

        sLastCoordMapCursorDrawn.x = x;
        sLastCoordMapCursorDrawn.y = y;
        sLastTimeMapCursorDrawn = GetGameTime();

        break;

    case MAP_CURSOR_STRETCHED:
        oam2 = OAM2_CHR(OBJCHR_SYSTEM_OBJECTS + 0x02) + OAM2_PAL(OBJPAL_SYSTEM_OBJECTS);
        sprite = Sprite_MapCursorStretched;

        break;

    case MAP_CURSOR_RED_STATIC:
        oam2 = OAM2_CHR(OBJCHR_SYSTEM_OBJECTS + 0x24) + OAM2_PAL(OBJPAL_SYSTEM_OBJECTS);
        sprite = sMapCursorSpriteLut[0];

        break;

    }

    x = x - gBmSt.camera.x;
    y = y - gBmSt.camera.y;

    PutSprite(4, x, y, sprite, oam2);
}

void SetMapCursorPosition(int x, int y)
{
    gBmSt.cursor.x = x;
    gBmSt.cursor.y = y;

    gBmSt.cursor_sprite_target.x = x*16;
    gBmSt.cursor_sprite_target.y = y*16;

    gBmSt.cursor_sprite.x = x*16;
    gBmSt.cursor_sprite.y = y*16;
}

void PutSysArrow(int x, int y, u8 isDown)
{
    int frame = (GetGameTime() / 8) % ARRAY_COUNT(gSysDownArrowSpriteLut);

    PutSprite(4, x, y,
        isDown ? gSysDownArrowSpriteLut[frame] : gSysUpArrowSpriteLut[frame],
        OAM2_CHR(OBJCHR_SYSTEM_OBJECTS) + OAM2_PAL(OBJPAL_SYSTEM_OBJECTS));
}

void PutSysAButton(int x, int y, int palid)
{
    u8 frame = (GetGameTime() % 0x10) & 8;

    PutSprite(4, x, y,
        Sprite_16x16,
        OAM2_CHR(OBJCHR_SYSTEM_OBJECTS + (frame ? 0x50 : 0x10)) + OAM2_PAL(palid));
}

static void CamMove_OnInit(struct CamMoveProc * proc)
{
    i8 speed = 1;

    int xDiff = ABS(proc->to.x - proc->from.x);
    int yDiff = ABS(proc->to.y - proc->from.y);

    int dist, i;

    if (xDiff > yDiff)
    {
        proc->xCalibrated = TRUE;
        proc->calibration = xDiff;
    }
    else
    {
        proc->xCalibrated = FALSE;
        proc->calibration = yDiff;
    }

    dist = proc->calibration;
    i = 0;

    while (TRUE)
    {
        if (dist - (speed >> 1) < 0)
        {
            sCameraAnimTable[i] = dist;
            break;
        }

        dist -= (speed >> 1);
        sCameraAnimTable[i] = (speed >> 1);

        if (speed < 0x10)
            speed++;

        i++;
    }

    proc->frame = i;
    proc->distance = proc->calibration;
}

static void CamMove_OnLoop(struct CamMoveProc * proc)
{
    if (proc->frame == 0)
    {
        proc->to.x = gBmSt.camera.x;
        proc->to.y = gBmSt.camera.y;

        Proc_End(proc);

        return;
    }

    proc->distance -= sCameraAnimTable[proc->frame--];

    gBmSt.camera.x = proc->to.x + (proc->from.x - proc->to.x) * proc->distance / proc->calibration;
    gBmSt.camera.y = proc->to.y + (proc->from.y - proc->to.y) * proc->distance / proc->calibration;
}

bool CameraMoveWatchPosition(ProcPtr proc, int x, int y)
{
    struct CamMoveProc * cam;

    int x_target = GetCameraAdjustedX(x*16);
    int y_target = GetCameraAdjustedY(y*16);

    if ((x_target == gBmSt.camera.x && y_target == gBmSt.camera.y) || FindProc(ProcScr_CamMove) != NULL)
        return FALSE;

    if (proc)
        cam = SpawnProcLocking(ProcScr_CamMove, proc);
    else
        cam = SpawnProc(ProcScr_CamMove, PROC_TREE_3);

    cam->from.x = gBmSt.camera.x;
    cam->from.y = gBmSt.camera.y;

    cam->to.x = x_target;
    cam->to.y = y_target;

    cam->watchedCoord.x = x;
    cam->watchedCoord.y = y;

    return TRUE;
}

bool IsCameraNotWatchingPosition(int x, int y)
{
    int x_target = GetCameraAdjustedX(x*16);
    int y_target = GetCameraAdjustedY(y*16);

    if (x_target == gBmSt.camera.x && y_target == gBmSt.camera.y)
        return FALSE;

    return TRUE;
}

bool CameraMove_08016290(ProcPtr proc)
{
    struct CamMoveProc * cam;

    if ((gBmSt.camera.y <= gBmSt.camera_max.y) || FindProc(ProcScr_CamMove) != NULL)
        return FALSE;

    if (proc)
        cam = SpawnProcLocking(ProcScr_CamMove, proc);
    else
        cam = SpawnProc(ProcScr_CamMove, PROC_TREE_3);

    cam->from.x = gBmSt.camera.x;
    cam->from.y = gBmSt.camera.y;

    cam->to.x = gBmSt.camera.x;
    cam->to.y = gBmSt.camera_max.y;

    return TRUE;
}

static void UnkMapCursor_OnLoop(struct UnkMapCursorProc * proc)
{
    // BUG: should this be proc->from.xy + ...?

    PutMapCursor(
        (proc->to.x - proc->from.x) * proc->clock / proc->duration,
        (proc->to.y - proc->from.y) * proc->clock / proc->duration,
        MAP_CURSOR_DEFAULT);

    proc->clock--;

    if (proc->clock < 0)
        Proc_Break(proc);
}

void Unused_08016344(int x, int y, int duration)
{
    struct UnkMapCursorProc * proc = SpawnProc(ProcScr_UnkMapCursor, PROC_TREE_3);

    proc->to.x = gBmSt.cursor.x*16;
    proc->to.y = gBmSt.cursor.y*16;

    proc->from.x = x*16;
    proc->from.y = y*16;

    proc->duration = duration;
    proc->clock = duration;
}

int GetActiveMapSong(void)
{
    switch (gPlaySt.faction)
    {

    case FACTION_RED:
        return GetChapterInfo(gPlaySt.chapter)->song_red_bgm;

    case FACTION_GREEN:
        return GetChapterInfo(gPlaySt.chapter)->song_green_bgm;

    case FACTION_BLUE:
        if (CountFactionUnitsWithoutState(FACTION_RED, UNIT_FLAG_DEAD | UNIT_FLAG_NOT_DEPLOYED) <= GetChapterInfo(gPlaySt.chapter)->victory_bgm_enemy_threshold)
            return SONG_13;

        return GetChapterInfo(gPlaySt.chapter)->song_blue_bgm;

    }
}

void StartMapSongBgm(void)
{
    StartBgm(GetActiveMapSong(), NULL);
}
