
#include "common.h"
#include "game-controller.h"

#include "hardware.h"
#include "util.h"
#include "bm.h"

struct GameController
{
    /* 00 */ PROC_HEADER;

    /* 29 */ u8 nextAction;
    /* 2A */ u8 nextChapter;
    /* 2B */ u8 demoCnt;
    /* 2C */ u8 previousDemoClassSet;
    /* 2E */ short clock;
};

enum
{
    L_GAMECTRL_OPENINGSEQ,
    L_GAMECTRL_CLASSDEMO,
    L_GAMECTRL_SCENEDEMO,
    L_GAMECTRL_TITLE,
    L_GAMECTRL_MAINMENU,
    L_GAMECTRL_CHAPTER,
    L_GAMECTRL_LOADSUSPEND,
    L_GAMECTRL_POSTCHAPTER,
    L_GAMECTRL_POSTTRIAL,
    L_GAMECTRL_TUTORIAL,
    L_GAMECTRL_LINK,
    L_GAMECTRL_TRIAL,
    L_GAMECTRL_PREENDING,
    L_GAMECTRL_ENDING,
    L_GAMECTRL_SRAMRESET,
};

static Bool GC_StartClassDemo(struct GameController* proc);
static void GC_CheckSramResetKeyCombo(struct GameController* proc);
static void GC_InitSramResetScreen(struct GameController* proc);
static void GC_InitFastStartCheck(struct GameController* proc);
static void GC_FastStartCheck(struct GameController* proc);
static void GC_PostIntro(struct GameController* proc);
static void GC_PostDemo(struct GameController* proc);
static void GC_PostMainMenu(struct GameController* proc);
static void GC_InitTutorial(struct GameController* proc);
static void GC_InitTrialMap(struct GameController* proc);
static void GC_ClearSuspend(struct GameController* proc);
static void GC_PostChapter(struct GameController* proc);
static void GC_CheckForGameEnded(struct GameController* proc);
static void GC_PostLoadSuspend(struct GameController* proc);
static void GC_InitNextChapter(struct GameController* proc);
static void GC_InitDemo(struct GameController* proc);
static void GC_DarkenScreen(struct GameController* proc);

struct ProcScr CONST_DATA ProcScr_Unused_GameController_085C4A1C[] =
{
    PROC_CALL(GC_InitFastStartCheck),
    PROC_REPEAT(GC_FastStartCheck),

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_GameController[] =
{
    PROC_19,
    PROC_MARK(PROC_MARK_GAMECTRL),

    PROC_19,

    PROC_CALL(GC_CheckSramResetKeyCombo),

    PROC_CALL(GC_InitFastStartCheck),
    PROC_REPEAT(GC_FastStartCheck),

PROC_LABEL(L_GAMECTRL_OPENINGSEQ),
    PROC_CALL(ForceEnableSounds),

    PROC_START_CHILD_LOCKING(ProcScr_OpeningSequence),

    PROC_CALL(GC_PostIntro),
    PROC_SLEEP(0),

    PROC_GOTO(L_GAMECTRL_TITLE),

PROC_LABEL(L_GAMECTRL_CLASSDEMO),
    PROC_CALL(GC_InitDemo),

    PROC_CALL_2(GC_StartClassDemo),

    PROC_CALL(GC_PostDemo),
    PROC_SLEEP(0),

    PROC_GOTO(L_GAMECTRL_OPENINGSEQ),

PROC_LABEL(L_GAMECTRL_SCENEDEMO),
    PROC_CALL(GC_InitDemo),

    PROC_CALL_ARG(sub_806DB00, 0),
    PROC_SLEEP(0),

    PROC_CALL(CleanupGame),

    PROC_CALL(GC_PostDemo),
    PROC_SLEEP(0),

    PROC_GOTO(L_GAMECTRL_OPENINGSEQ),

PROC_LABEL(L_GAMECTRL_TITLE),
    PROC_CALL(ForceEnableSounds),

    PROC_START_CHILD_LOCKING(ProcScr_Unk_08691480),

    PROC_CALL(GC_PostIntro),
    PROC_SLEEP(0),

    PROC_GOTO(L_GAMECTRL_OPENINGSEQ),

PROC_LABEL(L_GAMECTRL_MAINMENU),
    PROC_CALL(ForceEnableSounds),

    PROC_CALL(sub_8089200),
    PROC_SLEEP(0),

    PROC_CALL(GC_PostMainMenu),
    PROC_SLEEP(0),

    // fallthrough?

PROC_LABEL(L_GAMECTRL_CHAPTER),
    PROC_CALL(GC_CheckForGameEnded),

    PROC_START_CHILD_LOCKING(ProcScr_Unk_0868C304),

    PROC_CALL(GC_DarkenScreen),
    PROC_SLEEP(0),

    PROC_CALL(StartChapter),

    // fallthrough

PROC_LABEL(L_GAMECTRL_POSTCHAPTER),
    PROC_SLEEP(0),

    PROC_CALL(GC_PostChapter),
    PROC_SLEEP(0),

    PROC_CALL(GC_InitNextChapter),

    PROC_CALL(sub_8089234),
    PROC_SLEEP(0),

    PROC_GOTO(L_GAMECTRL_CHAPTER),

PROC_LABEL(L_GAMECTRL_LOADSUSPEND),
    PROC_CALL(GC_DarkenScreen),
    PROC_SLEEP(0),

    PROC_CALL(sub_8029128),

    PROC_CALL(GC_PostLoadSuspend),

    PROC_GOTO(L_GAMECTRL_POSTCHAPTER),

PROC_LABEL(L_GAMECTRL_TRIAL),
    PROC_CALL(GC_InitTrialMap),

    PROC_CALL(StartChapter),

    // fallthrough

PROC_LABEL(L_GAMECTRL_POSTTRIAL),
    PROC_SLEEP(0),

    PROC_CALL(GC_PostChapter),
    PROC_SLEEP(0),

    PROC_CALL(GC_ClearSuspend),

    PROC_CALL(sub_808FD6C),
    PROC_SLEEP(0),

    PROC_GOTO(L_GAMECTRL_TITLE),

PROC_LABEL(L_GAMECTRL_TUTORIAL),
    PROC_CALL(GC_InitTutorial),

    PROC_START_CHILD_LOCKING(ProcScr_Unk_0868C304),

    PROC_CALL(StartChapter),
    PROC_SLEEP(0),

    PROC_GOTO(L_GAMECTRL_MAINMENU),

PROC_LABEL(L_GAMECTRL_LINK),
    PROC_CALL(sub_803BA64),
    PROC_SLEEP(0),

    PROC_GOTO(L_GAMECTRL_MAINMENU),

PROC_LABEL(L_GAMECTRL_PREENDING),
    PROC_CALL(sub_8029654),

    PROC_CALL(sub_8089234),
    PROC_SLEEP(0),

    // fallthrough

PROC_LABEL(L_GAMECTRL_ENDING),
    PROC_CALL(StartGameEndingScene),
    PROC_SLEEP(0),

    PROC_GOTO(L_GAMECTRL_TITLE),

PROC_LABEL(L_GAMECTRL_SRAMRESET),
    PROC_CALL(GC_InitSramResetScreen),

    PROC_CALL(StartMidFadeFromBlack),
    PROC_REPEAT(WhileFadeExists),

    PROC_CALL(sub_803C080),
    PROC_SLEEP(0),

    PROC_CALL(StartMidFadeToBlack),
    PROC_REPEAT(WhileFadeExists),

    PROC_CALL(sub_806EABC),

    PROC_GOTO(L_GAMECTRL_OPENINGSEQ),

    PROC_END,
};

static int GetFurthestSaveChapter(void)
{
    struct PlaySt playSt;
    int i, chapter, number;

    chapter = 0;
    number = 0;

    for (i = SAVE_ID_GAME0; i < SAVE_ID_GAME2 + 1; ++i)
    {
        if (!sub_808525C(i))
            continue;

        sub_8085270(i, &playSt);

        if (number < GetChapterInfo(playSt.chapter)->numberId)
        {
            number = GetChapterInfo(playSt.chapter)->numberId;
            chapter = playSt.chapter;
        }
    }

    return chapter;
}

static Bool GC_StartClassDemo(struct GameController* proc)
{
    int classSet, chapter;

    chapter = GetFurthestSaveChapter();
    classSet = GetChapterInfo(chapter)->classRollSet;

    if (classSet == 6)
    {
        if (proc->previousDemoClassSet == 6)
            classSet = 7;
        else
            classSet = 6;
    }

    if (chapter == 0)
        classSet = 0;

    proc->previousDemoClassSet = classSet;
    sub_80947F0(classSet, proc);

    return FALSE;
}

static void GC_CheckSramResetKeyCombo(struct GameController* proc)
{
    if (gKeySt->held == (SELECT_BUTTON | DPAD_RIGHT | L_BUTTON))
        Proc_Goto(proc, L_GAMECTRL_SRAMRESET);
}

static void GC_InitSramResetScreen(struct GameController* proc)
{
    InitBgs(NULL);
    ApplySystemGraphics();

    gPlaySt.cfgTextSpeed = 1;

    sub_806EA24(PROC_TREE_3, NULL, -1);
}

static void GC_InitFastStartCheck(struct GameController* proc)
{
    proc->clock = 20;
}

static void GC_FastStartCheck(struct GameController* proc)
{
    if (!(gKeySt->held & START_BUTTON))
    {
        Proc_Break(proc);
        return;
    }

    proc->clock--;

    if (proc->clock < 0)
        Proc_Goto(proc, L_GAMECTRL_MAINMENU);
}

static void EndIfNotGameController(ProcPtr proc)
{
    if (((struct GenericProc*) proc)->proc_mark == PROC_MARK_GAMECTRL)
        return;

    Proc_End(proc);
}

void CleanupGame(ProcPtr proc)
{
    CpuFastFill16(RGB_BLACK, gPal, sizeof(gPal));
    EnablePalSync();

    Proc_ForAll(EndIfNotGameController);

    SetMainFunc(OnMain);
}

static void GC_PostIntro(struct GameController* proc)
{
    switch (proc->nextAction)
    {

    case GAME_ACTION_2:
        Proc_Goto(proc, L_GAMECTRL_TITLE);
        break;

    case GAME_ACTION_0:
        Proc_Goto(proc, L_GAMECTRL_MAINMENU);
        break;

    case GAME_ACTION_1:
        switch (proc->demoCnt & 1)
        {

        case 0:
            Proc_Goto(proc, L_GAMECTRL_CLASSDEMO);
            break;

        case 1:
            Proc_Goto(proc, L_GAMECTRL_SCENEDEMO);
            break;

        }

        break;

    }
}

static void GC_PostDemo(struct GameController* proc)
{
    switch (proc->nextAction)
    {

    case GAME_ACTION_0:
        Proc_Goto(proc, L_GAMECTRL_TITLE);
        break;

    case GAME_ACTION_1:
        Proc_Goto(proc, L_GAMECTRL_OPENINGSEQ);
        break;

    }
}

static void GC_PostMainMenu(struct GameController* proc)
{
    switch (proc->nextAction)
    {

    case GAME_ACTION_0:
    case GAME_ACTION_1:
    case GAME_ACTION_2:
        Proc_Goto(proc, L_GAMECTRL_CHAPTER);
        break;

    case GAME_ACTION_3:
        Proc_Goto(proc, L_GAMECTRL_LOADSUSPEND);
        break;

    case GAME_ACTION_4:
        Proc_Goto(proc, L_GAMECTRL_TITLE);
        break;

    case GAME_ACTION_5:
        Proc_Goto(proc, L_GAMECTRL_LINK);
        break;

    case GAME_ACTION_8:
        Proc_Goto(proc, L_GAMECTRL_TUTORIAL);
        break;

    case GAME_ACTION_6:
        Proc_Goto(proc, L_GAMECTRL_TRIAL);
        break;

    }
}

static void GC_InitTutorial(struct GameController* proc)
{
    sub_8028EF0(FALSE);

    gPlaySt.flags |= PLAY_FLAG_3;

    sub_806BA34();
    sub_806B970();

    sub_8017364();

    gPlaySt.chapter = 0;
}

static void GC_InitTrialMap(struct GameController* proc)
{
    LoadTrialMapBonusUnits();
    sub_8084818();
    sub_8029370();
}

static void GC_ClearSuspend(struct GameController* proc)
{
    sub_8085788(SAVE_ID_SUSPEND0);
}

static void GC_PostChapter(struct GameController* proc)
{
    switch (proc->nextAction)
    {

    case GAME_ACTION_0:
        Proc_Goto(proc, L_GAMECTRL_TITLE);
        break;

    case GAME_ACTION_2:
        Proc_Goto(proc, L_GAMECTRL_PREENDING);
        break;

    case GAME_ACTION_1:
        break;

    }
}

static void GC_CheckForGameEnded(struct GameController* proc)
{
    if (!(gPlaySt.flags & PLAY_FLAG_5))
        return;

    Proc_Goto(proc, L_GAMECTRL_ENDING);
}

static void GC_PostLoadSuspend(struct GameController* proc)
{
    if (gPlaySt.flags & PLAY_FLAG_5)
        Proc_Goto(proc, L_GAMECTRL_POSTTRIAL);
    else
        Proc_Goto(proc, L_GAMECTRL_POSTCHAPTER);
}

static void GC_InitNextChapter(struct GameController* proc)
{
    sub_8084908(&gPlaySt);
    gPlaySt.chapter = proc->nextChapter;

    sub_8029370();
}

static void GC_InitDemo(struct GameController* proc)
{
    proc->demoCnt++;
}

static void GC_DarkenScreen(struct GameController* proc)
{
    SetBlendDarken(0x10);

    SetBlendTargetA(1, 1, 1, 1, 1);
    SetBlendBackdropA(1);
}

void StartGame(void)
{
    struct GameController* proc;

    SetMainFunc(OnMain);
    SetOnVBlank(OnVBlank);

    proc = SpawnProc(ProcScr_GameController, PROC_TREE_3);

    proc->nextAction = GAME_ACTION_0;
    proc->nextChapter = 0;

    proc->demoCnt = 0;
}

static struct GameController* GetGameController(void)
{
    return Proc_Find(ProcScr_GameController);
}

void SetNextGameAction(int action)
{
    struct GameController* proc = GetGameController();
    proc->nextAction = action;
}

void SetNextChapter(int chapter)
{
    struct GameController* proc = GetGameController();
    proc->nextChapter = chapter;
}

Bool HasNextChapter(void)
{
    struct GameController* proc = GetGameController();
    return proc->nextChapter == 0 ? FALSE : TRUE;
}

void RestartGameAndChapter(void)
{
    struct GameController* proc;

    Proc_EndEach(ProcScr_GameController);
    proc = SpawnProc(ProcScr_GameController, PROC_TREE_3);

    Proc_Goto(proc, L_GAMECTRL_CHAPTER);
}

void RestartGameAndLoadSuspend(void)
{
    struct GameController* proc;

    Proc_EndEach(ProcScr_GameController);
    proc = SpawnProc(ProcScr_GameController, PROC_TREE_3);

    Proc_Goto(proc, L_GAMECTRL_LOADSUSPEND);
}

void ForceEnableSounds(void)
{
    gPlaySt.cfgBgmDisable = FALSE;
    gPlaySt.cfgSeDisable = FALSE;
}

void sub_8013A64(void)
{
    gPlaySt.unk1E_1 = 0;
    gPlaySt.cfgTextSpeed = 1;
    gPlaySt.unk1C_8 = 0;
    gPlaySt.cfgBgmDisable = FALSE;
    gPlaySt.cfgSeDisable = TRUE;
    gPlaySt.cfgWindowColor = 0;
    gPlaySt.unk1C_1 = 0;
}
