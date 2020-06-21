
#include "common.h"

#include "hardware.h"
#include "game-controller.h"
#include "bm.h"
#include "map.h"
#include "faction.h"
#include "battle.h"
#include "trap.h"
#include "unitsprite.h"
#include "bmio.h"
#include "mu.h"

#include "constants/chapters.h"

void sub_80294E0(ProcPtr mapmain);
void sub_80294A4(ProcPtr mapmain);
void sub_8029560(ProcPtr mapmain);
void sub_802959C(ProcPtr mapmain);
void sub_8029618(ProcPtr mapmain);

struct ProcScr CONST_DATA ProcScr_DelayedUnlockBmDisplay[] =
{
    PROC_SLEEP(0),

    PROC_CALL(UnlockBmDisplay),
    PROC_END,
};

int GetTextPrintDelay(void)
{
    u8 lut[4] = { 8, 4, 1, 0 };

    return lut[gPlaySt.configTextSpeed];
}

Bool IsFirstPlaythrough(void)
{
    if (!sub_80846F0())
        return TRUE;

    if (gPlaySt.flags & PLAY_FLAG_5)
        return FALSE;

    return gPlaySt.unk_1D_5;
}

void InitPlayConfig(int isHardMode)
{
    CpuFill16(0, &gPlaySt, sizeof(gPlaySt));

    gPlaySt.chapter = CHAPTER_CH01;

    if (isHardMode)
        gPlaySt.flags |= PLAY_FLAG_HARD;

    gPlaySt.configBattleAnim = 0; // TODO: battle anim type constants
    gPlaySt.unk_1C_2 = 0;
    gPlaySt.unk_1C_3 = 0;
    gPlaySt.configNoAutoCursor = FALSE;
    gPlaySt.configTextSpeed = 1;
    gPlaySt.unk_1C_8 = 0;
    gPlaySt.configBgmDisable = FALSE;
    gPlaySt.configSeDisable = FALSE;
    gPlaySt.configWindowColor = 0;
    gPlaySt.configNoAutoEndTurn = FALSE;
    gPlaySt.unk_1D_8 = 0;
    gPlaySt.unk_1E_3 = 0;
    gPlaySt.debugRedControl = 0;
    gPlaySt.debugGreenControl = 0;
    gPlaySt.unk_1C_1 = 0;
    gPlaySt.unk_1D_5 = 0;
}

void ResetBmSt(void)
{
    int lock = gBmSt.lock;

    CpuFill16(0, &gBmSt, sizeof(gBmSt));

    gBmSt.lock = lock;
}

void StartChapter(struct GenericProc* parent)
{
    InitBgs(NULL);

    SetMainFunc(OnMain);
    SetOnVBlank(OnVBlank);

    ResetBmSt();

    ApplySystemGraphics();
    ApplyUnitSpritePalettes();
    sub_806B970();
    ResetUnitSprites();
    InitTraps();

    gPlaySt.faction = FACTION_GREEN;
    gPlaySt.turn = 0;
    gPlaySt.vision = GetChapterInfo(gPlaySt.chapter)->fog;
    gPlaySt.weather = GetChapterInfo(gPlaySt.chapter)->weather;

    InitBmBgLayers();

    InitMapForChapter(gPlaySt.chapter);
    InitMapTraps();

    gPlaySt.unk_04 = GetGameTime();
    gPlaySt.supportGain = 0;

    sub_806B604();

    StartMapMain(parent);

    gPal[0] = 0;
    EnablePalSync();

    SetBlendTargetA(1, 1, 1, 1, 1); SetBlendBackdropA(1);
    SetBlendDarken(0x10);
}

void sub_8029084(void)
{
    InitBgs(NULL);

    SetMainFunc(OnMain);
    SetOnVBlank(OnVBlank);

    ApplySystemGraphics();
    ApplyUnitSpritePalettes();
    ResetUnitSprites();

    gBmSt.flags |= BM_FLAG_5;

    InitTraps();

    gPlaySt.weather = GetChapterInfo(gPlaySt.chapter)->weather;

    InitBmBgLayers();

    InitMapForChapter(gPlaySt.chapter);
    InitMapTraps();

    EndBmVSync();
    StartBmVSync();
    SpawnProc(ProcScr_MapTask, PROC_TREE_4);

    gPal[0] = 0;
    EnablePalSync();

    SetDispEnable(1, 1, 1, 0, 0);
}

void ResumeChapterFromSuspend(struct GenericProc* parent)
{
    ProcPtr mapmain;

    if (gPlaySt.chapter < 0)
        sub_80866EC();

    InitBgs(NULL);

    SetMainFunc(OnMain);
    SetOnVBlank(OnVBlank);

    ResetBmSt();

    SetMapCursorPosition(gPlaySt.xCursor, gPlaySt.yCursor);

    ApplySystemGraphics();
    ApplyUnitSpritePalettes();
    ResetUnitSprites();

    InitMapForChapter(gPlaySt.chapter);

    gBmSt.unk_3C = TRUE;

    mapmain = StartMapMain(parent);

    gBmSt.camera.x = GetCameraCenteredX(16*gBmSt.cursor.x);
    gBmSt.camera.y = GetCameraCenteredY(16*gBmSt.cursor.y);

    switch (gAction.suspendPoint)
    {

    case SUSPEND_POINT_DURING_ACTION:
        sub_80294E0(mapmain);
        break;

    case SUSPEND_POINT_PLAYER_PHASE:
    case SUSPEND_POINT_AI_PHASE:
        sub_80294A4(mapmain);
        break;

    case SUSPEND_POINT_BERSERK_PHASE:
        sub_8029560(mapmain);
        break;

    case SUSPEND_POINT_DURING_ARENA:
        sub_802959C(mapmain);
        break;

    case SUSPEND_POINT_CHANGE_PHASE:
        sub_8029618(mapmain);
        break;

    }

    SetBlendTargetA(1, 1, 1, 1, 1); SetBlendBackdropA(1);
    SetBlendDarken(0x10);
}

void sub_8029240(void)
{
    SetMainFunc(OnMain);
    SetOnVBlank(OnVBlank);

    ApplySystemGraphics();
    ApplyUnitSpritePalettes();
    ClearBg0Bg1();
    SetWinEnable(0, 0, 0);
    SetBlendNone();

    SetBlankChr(0);

    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);
}

void sub_80292B8(void)
{
    ApplySystemObjectsGraphics();

    MU_Start(&gBattleUnitA.unit);
    MU_SetDefaultFacing_Auto();

    SpawnProc(ProcScr_DelayedUnlockBmDisplay, PROC_TREE_3);
}

void sub_80292DC(void)
{
    InitBgs(NULL);
    ApplySystemGraphics();
    ApplyChapterMapGraphics(gPlaySt.chapter);
    AllocWeatherParticles(gPlaySt.weather);
    RenderMap();
    RefreshUnitSprites();
    ApplyUnitSpritePalettes();
    ForceSyncUnitSpriteSheet();
    InitSystemTextFont();
}

ProcPtr StartMapMain(struct GenericProc* parent)
{
    struct GenericProc* proc = SpawnProc(ProcScr_BmMain, PROC_TREE_2);
    proc->ptr = parent;

    parent->proc_lockCnt++;

    StartBmVSync();
    SpawnProc(ProcScr_MapTask, PROC_TREE_4);

    return proc;
}

void EndMapMain(void)
{
    struct GenericProc* mapmain;
    struct GenericProc* parent;

    Proc_EndEachMarked(PROC_MARK_1);

    mapmain = Proc_Find(ProcScr_BmMain);
    parent = mapmain->ptr;

    parent->proc_lockCnt--;

    Proc_End(mapmain);
}
