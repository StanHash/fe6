#include "gamecontroller.h"

#include "hardware.h"
#include "util.h"
#include "bm.h"
#include "unit.h"
#include "chapter.h"
#include "chapterinfo.h"
#include "ui.h"
#include "eventinfo.h"
#include "eventfunctions.h"
#include "statscreen.h"
#include "save_stats.h"
#include "save_game.h"
#include "save_xmap.h"
#include "savemenu.h"

#include "constants/chapters.h"

struct GameController
{
    /* 00 */ PROC_HEADER;

    /* 29 */ u8 next_action;
    /* 2A */ u8 next_chapter;
    /* 2B */ u8 demo_counter;
    /* 2C */ u8 previous_demo_class_set;
    /* 2E */ i16 clock;
};

static bool GC_StartClassDemo(struct GameController * proc);
static void GC_CheckSramResetKeyCombo(struct GameController * proc);
static void GC_InitSramResetScreen(struct GameController * proc);
static void GC_InitFastStartCheck(struct GameController * proc);
static void GC_FastStartCheck(struct GameController * proc);
static void GC_PostIntro(struct GameController * proc);
static void GC_PostDemo(struct GameController * proc);
static void GC_PostMainMenu(struct GameController * proc);
static void GC_InitTutorial(struct GameController * proc);
static void GC_InitTrialChapter(struct GameController * proc);
static void GC_ClearSuspend(struct GameController * proc);
static void GC_PostChapter(struct GameController * proc);
static void GC_CheckForGameEnded(struct GameController * proc);
static void GC_PostLoadSuspend(struct GameController * proc);
static void GC_InitNextChapter(struct GameController * proc);
static void GC_InitDemo(struct GameController * proc);
static void GC_DarkenScreen(struct GameController * proc);

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

    PROC_CALL_ARG(func_fe6_0806DB00, 0),
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

    PROC_CALL(StartMainMenu),
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

    PROC_CALL(StartSaveMenu),
    PROC_SLEEP(0),

    PROC_GOTO(L_GAMECTRL_CHAPTER),

PROC_LABEL(L_GAMECTRL_LOADSUSPEND),
    PROC_CALL(GC_DarkenScreen),
    PROC_SLEEP(0),

    PROC_CALL(ResumeChapterFromSuspend),

    PROC_CALL(GC_PostLoadSuspend),

    PROC_GOTO(L_GAMECTRL_POSTCHAPTER),

PROC_LABEL(L_GAMECTRL_TRIAL),
    PROC_CALL(GC_InitTrialChapter),

    PROC_CALL(StartChapter),

    // fallthrough

PROC_LABEL(L_GAMECTRL_POSTTRIAL),
    PROC_SLEEP(0),

    PROC_CALL(GC_PostChapter),
    PROC_SLEEP(0),

    PROC_CALL(GC_ClearSuspend),

    PROC_CALL(func_fe6_0808FD6C),
    PROC_SLEEP(0),

    PROC_GOTO(L_GAMECTRL_TITLE),

PROC_LABEL(L_GAMECTRL_TUTORIAL),
    PROC_CALL(GC_InitTutorial),

    PROC_START_CHILD_LOCKING(ProcScr_Unk_0868C304),

    PROC_CALL(StartChapter),
    PROC_SLEEP(0),

    PROC_GOTO(L_GAMECTRL_MAINMENU),

PROC_LABEL(L_GAMECTRL_LINK),
    PROC_CALL(func_fe6_0803BA64),
    PROC_SLEEP(0),

    PROC_GOTO(L_GAMECTRL_MAINMENU),

PROC_LABEL(L_GAMECTRL_PREENDING),
    PROC_CALL(func_fe6_08029654),

    PROC_CALL(StartSaveMenu),
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

    PROC_CALL(func_fe6_0803C080),
    PROC_SLEEP(0),

    PROC_CALL(StartMidFadeToBlack),
    PROC_REPEAT(WhileFadeExists),

    PROC_CALL(EndMuralBackground),

    PROC_GOTO(L_GAMECTRL_OPENINGSEQ),

    PROC_END,
};

static int GetFurthestSaveChapter(void)
{
    struct PlaySt play_st;
    int i, chapter, number;

    chapter = 0;
    number = 0;

    for (i = SAVE_GAME0; i <= SAVE_GAME2; ++i)
    {
        if (!IsSaveValid(i))
            continue;

        ReadGameSavePlaySt(i, &play_st);

        if (number < GetChapterInfo(play_st.chapter)->number_id)
        {
            number = GetChapterInfo(play_st.chapter)->number_id;
            chapter = play_st.chapter;
        }
    }

    return chapter;
}

static bool GC_StartClassDemo(struct GameController * proc)
{
    int class_set, chapter;

    chapter = GetFurthestSaveChapter();
    class_set = GetChapterInfo(chapter)->class_roll_set;

    if (class_set == 6)
    {
        if (proc->previous_demo_class_set == 6)
            class_set = 7;
        else
            class_set = 6;
    }

    if (chapter == 0)
        class_set = 0;

    proc->previous_demo_class_set = class_set;
    func_fe6_080947F0(class_set, proc);

    return FALSE;
}

static void GC_CheckSramResetKeyCombo(struct GameController * proc)
{
    if (gKeySt->held == (KEY_BUTTON_SELECT | KEY_DPAD_RIGHT | KEY_BUTTON_L))
        Proc_Goto(proc, L_GAMECTRL_SRAMRESET);
}

static void GC_InitSramResetScreen(struct GameController * proc)
{
    InitBgs(NULL);
    ApplySystemGraphics();

    gPlaySt.config_talk_speed = 1;

    StartMuralBackground(PROC_TREE_3, NULL, -1);
}

static void GC_InitFastStartCheck(struct GameController * proc)
{
    proc->clock = 20;
}

static void GC_FastStartCheck(struct GameController * proc)
{
    if (!(gKeySt->held & KEY_BUTTON_START))
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
    if (((struct GenericProc *) proc)->proc_mark == PROC_MARK_GAMECTRL)
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

static void GC_PostIntro(struct GameController * proc)
{
    switch (proc->next_action)
    {

    case GAME_ACTION_2:
        Proc_Goto(proc, L_GAMECTRL_TITLE);
        break;

    case GAME_ACTION_0:
        Proc_Goto(proc, L_GAMECTRL_MAINMENU);
        break;

    case GAME_ACTION_1:
        switch (proc->demo_counter & 1)
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

static void GC_PostDemo(struct GameController * proc)
{
    switch (proc->next_action)
    {
        case GAME_ACTION_0:
            Proc_Goto(proc, L_GAMECTRL_TITLE);
            break;

        case GAME_ACTION_1:
            Proc_Goto(proc, L_GAMECTRL_OPENINGSEQ);
            break;
    }
}

static void GC_PostMainMenu(struct GameController * proc)
{
    switch (proc->next_action)
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

static void GC_InitTutorial(struct GameController * proc)
{
    InitPlayConfig(FALSE);

    gPlaySt.flags |= PLAY_FLAG_TUTORIAL;

    ResetPermanentFlags();
    ResetChapterFlags();

    InitUnits();

    gPlaySt.chapter = CHAPTER_TUTORIAL;
}

static void GC_InitTrialChapter(struct GameController * proc)
{
    CreateTrialChapterBonusUnits();
    ClearPidStats();
    CleanupUnitsBeforeChapter();
}

static void GC_ClearSuspend(struct GameController * proc)
{
    InvalidateSuspendSave(SAVE_SUSPEND);
}

static void GC_PostChapter(struct GameController * proc)
{
    switch (proc->next_action)
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

static void GC_CheckForGameEnded(struct GameController * proc)
{
    if (!(gPlaySt.flags & PLAY_FLAG_COMPLETE))
        return;

    Proc_Goto(proc, L_GAMECTRL_ENDING);
}

static void GC_PostLoadSuspend(struct GameController * proc)
{
    if (gPlaySt.flags & PLAY_FLAG_COMPLETE)
        Proc_Goto(proc, L_GAMECTRL_POSTTRIAL);
    else
        Proc_Goto(proc, L_GAMECTRL_POSTCHAPTER);
}

static void GC_InitNextChapter(struct GameController * proc)
{
    RegisterChapterStats(&gPlaySt);
    gPlaySt.chapter = proc->next_chapter;

    CleanupUnitsBeforeChapter();
}

static void GC_InitDemo(struct GameController * proc)
{
    proc->demo_counter++;
}

static void GC_DarkenScreen(struct GameController * proc)
{
    SetBlendDarken(0x10);

    SetBlendTargetA(1, 1, 1, 1, 1);
    SetBlendBackdropA(1);
}

void StartGame(void)
{
    struct GameController * proc;

    SetMainFunc(OnMain);
    SetOnVBlank(OnVBlank);

    proc = SpawnProc(ProcScr_GameController, PROC_TREE_3);

    proc->next_action = GAME_ACTION_0;
    proc->next_chapter = 0;

    proc->demo_counter = 0;
}

static struct GameController * GetGameController(void)
{
    return FindProc(ProcScr_GameController);
}

void SetNextGameAction(int action)
{
    struct GameController * proc = GetGameController();
    proc->next_action = action;
}

void SetNextChapter(int chapter)
{
    struct GameController * proc = GetGameController();
    proc->next_chapter = chapter;
}

bool HasNextChapter(void)
{
    struct GameController * proc = GetGameController();
    return proc->next_chapter == 0 ? FALSE : TRUE;
}

void RestartGameAndChapter(void)
{
    struct GameController * proc;

    Proc_EndEach(ProcScr_GameController);
    proc = SpawnProc(ProcScr_GameController, PROC_TREE_3);

    Proc_Goto(proc, L_GAMECTRL_CHAPTER);
}

void RestartGameAndLoadSuspend(void)
{
    struct GameController * proc;

    Proc_EndEach(ProcScr_GameController);
    proc = SpawnProc(ProcScr_GameController, PROC_TREE_3);

    Proc_Goto(proc, L_GAMECTRL_LOADSUSPEND);
}

void ForceEnableSounds(void)
{
    gPlaySt.config_bgm_disable = FALSE;
    gPlaySt.config_se_disable = FALSE;
}

void func_fe6_08013A64(void)
{
    gPlaySt.config_battle_anim = 0;
    gPlaySt.config_talk_speed = 1;
    gPlaySt.config_walk_speed = 0;
    gPlaySt.config_bgm_disable = FALSE;
    gPlaySt.config_se_disable = TRUE;
    gPlaySt.config_window_theme = UI_WINDOW_THEME_BLUE;
    gPlaySt.unk_1C_1 = 0;
}
