
#include "event-script.h"

#include "armfunc.h"
#include "hardware.h"
#include "sound.h"
#include "proc.h"
#include "talk.h"
#include "popup.h"
#include "mu.h"

#include "constants/terrains.h"
#include "constants/video-wm.h"

#include "unks.h"

enum
{
    EVENT_FLAG_UNITCAM = (1 << 0),
    EVENT_FLAG_TEXTSKIPPED = (1 << 1),
    EVENT_FLAG_SKIPPED = (1 << 2),
    EVENT_FLAG_DISABLESKIP = (1 << 3),
    EVENT_FLAG_DISABLETEXTSKIP = (1 << 4),
    EVENT_FLAG_5 = (1 << 5),
    EVENT_FLAG_6 = (1 << 6),
};

struct EventProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ u32 const* scriptStart;
    /* 30 */ u32 const* script;
    /* 34 */ void(*onSkip)(void);
    /* 38 */ void(*onIdle)(struct EventProc* proc);
    /* 3C */ struct UnitInfo const* unitInfo;
    /* 40 */ int msgParam;
    /* 44 */ s8 background;
    /* 45 */ Bool unk45;
    /* 46 */ u8 flags;
    /* 47 */ // pad
    /* 48 */ u16 sleepDuration;
    /* 4A */ short savedGameLock;

    /* 4C */ u8 unk4C;

    /* 4D */ u8 pad4D[0x50 - 0x4D];

    /* 50 */ int moneyParam;
    /* 54 */ u16 iidParam;
    /* 56 */ u8 pidParam;
    /* 57 */ u8 mapChangeParam;
};

struct EventCmdInfo
{
    int(*func)(struct EventProc* proc);
    int size;
};

struct UnkProc
{
    /* 00 */ PROC_HEADER;

    /* 29 */ u8 pad29[0x4C - 0x29];

    /* 4C */ struct EventProc* eventProc;
    /* 50 */ void(*func)(struct EventProc* proc);

    /* 54 */ u8 pad54[0x64 - 0x54];

    /* 64 */ short q4_darkenStep;
    /* 66 */ short q4_darken;
};

enum
{
    EVENT_CMDRET_CONTINUE,
    EVENT_CMDRET_JUMPED,
    EVENT_CMDRET_YIELD,
    EVENT_CMDRET_REPEAT,
};

void sub_800CCF0(struct UnitInfo const* info, ProcPtr parent);

static void sub_800D87C(struct GenericProc* proc);
static void sub_800D8E0(struct GenericProc* proc);
static void sub_800D8AC(struct GenericProc* proc);

static void sub_800D928(struct GenericProc* proc);

void EventEngine_OnInit(struct EventProc* proc);
void EventEngine_OnEnd(struct EventProc* proc);
void sub_800DB38(struct EventProc* proc);
void sub_800DB70(struct EventProc* proc);
void sub_800DBF4(struct EventProc* proc);
void EventEngine_OnMain(struct EventProc* proc);
void EventEngine_WaitForFaceEnd(struct EventProc* proc);

void sub_800DCD8(struct UnkProc* proc);
void sub_800DD08(struct UnkProc* proc);

void sub_800D808(void);

static void sub_800D824(ProcPtr proc);
ProcPtr StartEventEngineInternal(u32 const* script, ProcPtr parent);

int Evt_End(struct EventProc* proc);
int Evt_NoSkip(struct EventProc* proc);
int Evt_NoSkipNoTextSkip(struct EventProc* proc);

s8 sub_800EFB4(struct EventProc* proc, struct Unit* unit, u8 const* movescr);

void sub_800F260(struct EventProc* proc);
void sub_800F324(struct EventProc* proc);
void sub_800F56C(struct EventProc* proc);

void sub_80121F4(struct Unit* unit, u16 iid, ProcPtr parent);

void sub_8012710(struct EventProc* proc);
void sub_8012738(struct EventProc* proc);

ProcPtr sub_8011FE8(int msg);

void sub_80121D0(ProcPtr proc);

#define EVTCMD_GET_X_RAW(script) (((script) & 0x0000FFFF))
#define EVTCMD_GET_Y_RAW(script) (((script) & 0xFFFF0000) >> 16)

#define EVTCMD_GET_X(script) (EVTCMD_GET_X_RAW(script) & 0x8000 ? -1 : EVTCMD_GET_X_RAW(script))
#define EVTCMD_GET_Y(script) (EVTCMD_GET_Y_RAW(script) & 0x8000 ? -1 : EVTCMD_GET_Y_RAW(script))

extern u32 const* gEventScriptQueue[]; // COMMON
extern u8 gEventScriptQueueIt; // COMMON

struct ProcScr CONST_DATA ProcScr_SceneReturnFromBackgroundTalk[] =
{
    PROC_CALL(sub_800D87C),
    PROC_SLEEP(0),

    PROC_CALL(sub_800D8E0),
    PROC_SLEEP(1),

    PROC_CALL(sub_800D8AC),
    PROC_SLEEP(0),

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_SceneEndFade[] =
{
    PROC_SLEEP(0),

    PROC_CALL(sub_800D928),
    PROC_SLEEP(0),

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Event[] =
{
    PROC_MARK(PROC_MARK_6),
    PROC_SET_END_FUNC(EventEngine_OnEnd),

    PROC_CALL(EventEngine_OnInit),

PROC_LABEL(0),
    PROC_REPEAT(EventEngine_OnMain),
    PROC_REPEAT(EventEngine_WaitForFaceEnd),
    PROC_SLEEP(0),

    PROC_CALL(sub_800DB38),
    PROC_SLEEP(0),

    PROC_CALL(sub_800DB70),

    PROC_CALL(sub_800DBF4),

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Event_Unused_085C4104[] =
{
    PROC_MARK(PROC_MARK_6),

PROC_LABEL(0),
    PROC_REPEAT(EventEngine_OnMain),
    PROC_REPEAT(EventEngine_WaitForFaceEnd),
    PROC_SLEEP(1),

    PROC_SLEEP(1),

    PROC_CALL(sub_800DB70),

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_085C4144[] =
{
    PROC_CALL(sub_800DCD8),
    PROC_SLEEP(0),

    PROC_REPEAT(sub_800DD08),

    PROC_END,
};

static struct EventCmdInfo CONST_DATA sEventCmdInfoTable[];

void sub_800D808(void)
{
    Proc_ForEach(ProcScr_Event, sub_800D824);
}

static void sub_800D824(ProcPtr proc)
{
    Evt_NoSkip(proc);
}

void StartReturnFromBackgroundConvo(struct EventProc* proc)
{
    SpawnProcLocking(ProcScr_SceneReturnFromBackgroundTalk, proc);
}

void sub_800D85C(struct EventProc* proc)
{
    SpawnProcLocking(ProcScr_SceneEndFade, proc);
}

static void sub_800D87C(struct GenericProc* proc)
{
    if (((struct EventProc*) proc->proc_parent)->flags & EVENT_FLAG_SKIPPED)
        return;

    sub_80146F8(proc);
}

static void sub_800D8AC(struct GenericProc* proc)
{
    struct EventProc* evproc = proc->proc_parent;

    if (!(evproc->flags & EVENT_FLAG_SKIPPED))
        StartBlockingFadeOutBlackMedium(proc);
}

static void sub_800D8E0(struct GenericProc* proc)
{
    sub_80292DC();
    UnlockBattleMapDisplay();
    sub_806095C();

    TmFill(gBg0Tm, 0);
    TmFill(gBg1Tm, 0);

    EnableBgSync(BG0_SYNC_BIT);
    EnableBgSync(BG1_SYNC_BIT);

    EndAllFaces();
}

static void sub_800D928(struct GenericProc* proc)
{
    struct EventProc* evproc = proc->proc_parent;

    sub_80292DC();

    if (evproc->flags & EVENT_FLAG_SKIPPED)
    {
        if (evproc->unk45)
            StartBlockingFadeOutBlack(0x20, proc);

        return;
    }

    StartBlockingFadeOutBlackMedium(proc);
}

ProcPtr StartEventEngine(u32 const* script)
{
    return StartEventEngineInternal(script, PROC_TREE_3);
}

ProcPtr StartEventEngineParent(u32 const* script, ProcPtr parent)
{
    return StartEventEngineInternal(script, parent);
}

ProcPtr StartEventEngineInternal(u32 const* script, ProcPtr parent)
{
    struct EventProc* proc = Proc_Find(ProcScr_Event);

    if (proc)
    {
        gEventScriptQueue[gEventScriptQueueIt] = script;
        gEventScriptQueueIt++;

        return proc;
    }

    gEventScriptQueueIt = 0;
    gEventScriptQueue[gEventScriptQueueIt] = NULL;

    if ((int) parent < 8)
        proc = SpawnProc(ProcScr_Event, parent);
    else
        proc = SpawnProcLocking(ProcScr_Event, parent);

    proc->scriptStart = script;
    proc->script = script;

    proc->onIdle = NULL;
    proc->onSkip = NULL;

    proc->msgParam = 0;

    proc->flags = EVENT_FLAG_UNITCAM;

    proc->sleepDuration = 0;
    proc->background = -1;
    proc->unk45 = FALSE;

    FillBmMap(gMapOther, 0);

    switch (proc->script[0])
    {

    case 0x40:
        proc->script++;
        Evt_NoSkip(proc);

        break;

    case 0x41:
        proc->script++;
        Evt_NoSkipNoTextSkip(proc);

        break;

    default:
        break;

    }

    return proc;
}

void EventEngine_OnInit(struct EventProc* proc)
{
    LockGame();
    proc->onIdle = NULL;
}

void EventEngine_OnEnd(struct EventProc* proc)
{
    UnlockGame();
}

void sub_800DB38(struct EventProc* proc)
{
    if (proc->flags & EVENT_FLAG_6)
        return;

    SetTextFont(NULL);
    InitSystemTextFont();

    LoadUiFrameGraphics();
}

void sub_800DB70(struct EventProc* proc)
{
    proc->flags &= ~EVENT_FLAG_SKIPPED;

    if (gEventScriptQueueIt != 0)
    {
        gEventScriptQueueIt--;

        proc->onIdle = NULL;

        proc->scriptStart = gEventScriptQueue[gEventScriptQueueIt];
        proc->script = gEventScriptQueue[gEventScriptQueueIt];

        Proc_Goto(proc, 0);
    }
}

void sub_800DBF4(struct EventProc* proc)
{
    if (proc->flags & EVENT_FLAG_5)
        EndMapMain();
}

void sub_800DC20(struct EventProc* proc)
{
    sub_8014AF8();
    Proc_EndEach(ProcScr_TalkOpen);

    if (proc->background == -1)
        sub_8061704();
}

Bool sub_800DC54(struct EventProc* proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
        return FALSE;

    if (proc->flags & EVENT_FLAG_DISABLESKIP)
        return FALSE;

    if (sub_80425C4())
        return FALSE;

    return TRUE;
}

void sub_800DD48(struct UnkProc* proc);
void sub_800DE3C(struct UnkProc* proc);

void sub_800DCAC(void(*func)(struct EventProc* proc), struct EventProc* eproc)
{
    struct UnkProc* proc = SpawnProcLocking(ProcScr_Unk_085C4144, eproc);

    proc->func = func;
    proc->eventProc = eproc;
}

void sub_800DCD8(struct UnkProc* proc)
{
    sub_800DD48(proc);

    proc->q4_darkenStep = 0x20;
}

void sub_800DD08(struct UnkProc* proc)
{
    void(*func)(struct EventProc* proc) = proc->func;

    sub_800DE3C(proc);

    if (gDispIo.blendY == 0x10)
    {
        func(proc->eventProc);
        Proc_Break(proc);
    }
}

void sub_800DD48(struct UnkProc* proc)
{
    gDispIo.winCt.win0_enableBlend = 1;
    gDispIo.winCt.win1_enableBlend = 1;
    gDispIo.winCt.wobj_enableBlend = 1;
    gDispIo.winCt.wout_enableBlend = 1;

    SetBlendDarken(0);

    SetBlendTargetA(1, 1, 1, 1, 1);
    SetBlendBackdropA(1);

    proc->q4_darkenStep = 0x10;
    proc->q4_darken = 0;
}

void sub_800DE3C(struct UnkProc* proc)
{
    if (gDispIo.blendY == 0x10)
    {
        Proc_End(proc);
        return;
    }

    proc->q4_darken += proc->q4_darkenStep;

    if (proc->q4_darken >= 0x100)
        proc->q4_darken = 0x100;

    gDispIo.blendY = proc->q4_darken >> 4;
}

void EventEngine_OnMain(struct EventProc* proc)
{
    if (Proc_Find(ProcScr_Unk_085C8080) != NULL)
        return;

    if (sub_802CB60())
        return;

    if (BattleMapFadeExists())
        return;

    if (sub_800DC54(proc) && (gKeySt->pressed & START_BUTTON))
    {
        if (proc->onSkip)
            proc->onSkip();

        proc->flags |= EVENT_FLAG_SKIPPED;

        if (!IsTalkDebugActive())
        {
            proc->unk45 = TRUE;

            if (sub_8093444())
                sub_800DC20(proc);
            else
                sub_800DCAC(sub_800DC20, proc);
        }

        Proc_LockEachMarked(PROC_MARK_5);
        return;
    }

    if (proc->sleepDuration != 0)
    {
        proc->sleepDuration--;
        return;
    }

    if (proc->onIdle)
    {
        proc->onIdle(proc);
        return;
    }

    while (TRUE)
    {
        int cmd, result;

        cmd = *proc->script++;
        result = sEventCmdInfoTable[cmd].func(proc);

        if (result == EVENT_CMDRET_JUMPED)
            continue;

        if (result == EVENT_CMDRET_REPEAT)
        {
            proc->script--;
            return;
        }

        proc->script = proc->script - 1 + sEventCmdInfoTable[cmd].size;

        if (result == EVENT_CMDRET_YIELD)
            return;
    }
}

void EventEngine_WaitForFaceEnd(struct EventProc* proc)
{
    if (!(proc->flags & EVENT_FLAG_6) && FaceExists())
        return;

    Proc_Break(proc);
}

// ===============================
// = EVENT SCRIPT COMMANDS BEGIN =
// ===============================

struct BackgroundEnt
{
    u8 const* img;
    u8 const* tsa;
    u16 const* pal;
};

void sub_800E2CC(int background);
void sub_800E380(int background);
void ClearDialogue(struct EventProc* proc);

static struct BackgroundEnt CONST_DATA gBackgroundTable[];

static struct FaceVramEnt CONST_DATA gWmEventFaceConfig[];
static struct FaceVramEnt CONST_DATA gFightEventFaceConfig[];

int Evt_Sleep(struct EventProc* proc)
{
    // script[0]: duration

    int duration = proc->script[0];

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_YIELD;

    if (duration > 0)
        duration--;

    proc->sleepDuration = duration;

    return EVENT_CMDRET_YIELD;
}

int Evt_DisplayBackground(struct EventProc* proc)
{
    // script[0]: background

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    if (proc->background == -1)
    {
        LockBattleMapDisplay();
        BlockAllProcsMarked4();
    }

    sub_800E2CC(proc->script[0]);
    proc->background = proc->script[0];

    return EVENT_CMDRET_YIELD;
}

int Evt_DisplayBackgroundContinued(struct EventProc* proc)
{
    // script[0]: background

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    if (proc->background == -1)
    {
        LockBattleMapDisplay();
        BlockAllProcsMarked4();
    }

    sub_800E380(proc->script[0]);
    proc->background = proc->script[0];

    return EVENT_CMDRET_YIELD;
}

int Evt_ClearDialogue(struct EventProc* proc)
{
    if (proc->background == -1)
    {
        ClearDialogue(proc);
        SetDispEnable(1, 1, 1, 1, 1);

        return EVENT_CMDRET_YIELD;
    }

    StartReturnFromBackgroundConvo(proc);
    proc->background = -1;

    return EVENT_CMDRET_YIELD;
}

int Evt_FadeOutEnd(struct EventProc* proc)
{
    if (!(proc->flags & EVENT_FLAG_SKIPPED))
        return EVENT_CMDRET_CONTINUE;

    sub_800D85C(proc);
    proc->background = -1;

    return EVENT_CMDRET_YIELD;
}

void sub_800E2CC(int background)
{
    EndAllFaces();

    SetBgOffset(0, 0, 0);
    SetBgOffset(1, 0, 0);
    SetBgOffset(2, 0, 0);
    SetBgOffset(3, 0, 0);

    Decompress(gBackgroundTable[background].img, (u8*) VRAM + GetBgChrOffset(3));
    TmApplyTsa_t(gBg3Tm, gBackgroundTable[background].tsa, TILEREF(0, 8));
    ApplyPalettes(gBackgroundTable[background].pal, 8, 4);

    EnableBgSync(BG3_SYNC_BIT);
    gPal[0] = 0;
}

void sub_800E380(int background)
{
    SetBgOffset(0, 0, 0);
    SetBgOffset(1, 0, 0);
    SetBgOffset(2, 0, 0);
    SetBgOffset(3, 0, 0);

    Decompress(gBackgroundTable[background].img, (u8*) VRAM + GetBgChrOffset(3));
    TmApplyTsa_t(gBg3Tm, gBackgroundTable[background].tsa, TILEREF(0, 8));
    ApplyPalettes(gBackgroundTable[background].pal, 8, 4);

    EnableBgSync(BG3_SYNC_BIT);
    gPal[0] = 0;
}

static void EventDialogueWait(struct EventProc* proc);

int Evt_Text(struct EventProc* proc)
{
    // script[0]: msgid

    proc->flags &= ~EVENT_FLAG_TEXTSKIPPED;

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    InitTalk(0x80, 2, TRUE);
    StartTalkMsg(1, 1, proc->script[0]);

    if (proc->flags & EVENT_FLAG_DISABLETEXTSKIP)
        SetTalkFlag(TALK_FLAG_NOSKIP);

    proc->onIdle = EventDialogueWait;

    return EVENT_CMDRET_YIELD;
}

int Evt_TextMore(struct EventProc* proc)
{
    // script[0]: msgid

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    if (proc->flags & EVENT_FLAG_TEXTSKIPPED)
        return EVENT_CMDRET_CONTINUE;

    StartTalkMsg(1, 1, proc->script[0]);

    if (proc->flags & EVENT_FLAG_DISABLETEXTSKIP)
        SetTalkFlag(TALK_FLAG_NOSKIP);

    proc->onIdle = EventDialogueWait;

    return EVENT_CMDRET_YIELD;
}

int Evt_TextUnk(struct EventProc* proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_YIELD;

    InitTalk(0x80, 2, TRUE);
    StartTalkMsg(1, 1, proc->msgParam);

    if (proc->flags & EVENT_FLAG_DISABLETEXTSKIP)
        SetTalkFlag(TALK_FLAG_NOSKIP);

    proc->onIdle = EventDialogueWait;

    return EVENT_CMDRET_YIELD;
}

int Evt_TextContinue(struct EventProc* proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
    {
        EndTalk();
        return EVENT_CMDRET_YIELD;
    }

    ResumeTalk();
    proc->onIdle = EventDialogueWait;

    return EVENT_CMDRET_YIELD;
}

static void EventDialogueWait(struct EventProc* proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
    {
        EndTalk();
        proc->onIdle = NULL;

        return;
    }

    if (!IsTalkActive() || IsTalkLocked())
        proc->onIdle = NULL;
}

int Evt_CameraPosition(struct EventProc* proc)
{
    // script[0]: coords (u16, u16)

    if ((proc->flags & EVENT_FLAG_SKIPPED) || proc->unk45)
    {
        gBmSt.camera.x = sub_8015E44(EVTCMD_GET_X(proc->script[0]) << 4);
        gBmSt.camera.y = sub_8015E88(EVTCMD_GET_Y(proc->script[0]) << 4);

        sub_801600C(
            EVTCMD_GET_X(proc->script[0]),
            EVTCMD_GET_Y(proc->script[0]));

        RedrawBattleMap();

        return EVENT_CMDRET_YIELD;
    }

    EnsureCameraOntoPosition(proc,
        EVTCMD_GET_X(proc->script[0]),
        EVTCMD_GET_Y(proc->script[0]));

    sub_801600C(
        EVTCMD_GET_X(proc->script[0]),
        EVTCMD_GET_Y(proc->script[0]));

    return EVENT_CMDRET_YIELD;
}

int Evt_CameraCharacter(struct EventProc* proc)
{
    // script[0]: pid of unit

    struct Unit* unit = GetUnitByCharId(proc->script[0]);

    if ((proc->flags & EVENT_FLAG_SKIPPED) || proc->unk45)
    {
        gBmSt.camera.x = sub_8015E44(unit->x << 4);
        gBmSt.camera.y = sub_8015E88(unit->y << 4);

        sub_801600C(unit->x, unit->y);

        RedrawBattleMap();

        return EVENT_CMDRET_YIELD;
    }

    EnsureCameraOntoPosition(proc, unit->x, unit->y);
    sub_801600C(unit->x, unit->y);

    return EVENT_CMDRET_YIELD;
}

Bool CanDisplayUnitMovement(struct EventProc* proc, int x, int y)
{
    if (proc->flags & EVENT_FLAG_UNITCAM)
    {
        if (Proc_Find(ProcScr_CamMove) != NULL || EnsureCameraOntoPosition(proc, x, y))
            return FALSE;
    }

    if (!MU_CanStart())
        return FALSE;

    return TRUE;
}

int Evt_MovePosition(struct EventProc* proc)
{
    // script[0]: coords (u16, u16) of unit to move
    // script[1]: coords (u16, u16) to move to

    struct Unit* unit;

    int xUnit = EVTCMD_GET_X(proc->script[0]);
    int yUnit = EVTCMD_GET_Y(proc->script[0]);

    int xTarget = EVTCMD_GET_X(proc->script[1]);
    int yTarget = EVTCMD_GET_Y(proc->script[1]);

    unit = GetUnit(gMapUnit[yUnit][xUnit]);

    if ((proc->flags & EVENT_FLAG_SKIPPED) || proc->unk45)
    {
        TryMoveUnit(unit, xTarget, yTarget, TRUE);
        RefreshSMS();

        return EVENT_CMDRET_CONTINUE;
    }

    if (!CanDisplayUnitMovement(proc, xUnit, yUnit))
        return EVENT_CMDRET_REPEAT;

    sub_800EEA0(proc, unit, xTarget, yTarget);

    return EVENT_CMDRET_CONTINUE;
}

int Evt_MoveCharacter(struct EventProc* proc)
{
    // script[0]: pid of unit to move
    // script[1]: coords (u16, u16) to move to

    struct Unit* unit = GetUnitByCharId(proc->script[0]);

    int xTarget = EVTCMD_GET_X(proc->script[1]);
    int yTarget = EVTCMD_GET_Y(proc->script[1]);

    if ((proc->flags & EVENT_FLAG_SKIPPED) || proc->unk45)
    {
        TryMoveUnit(unit, xTarget, yTarget, TRUE);
        RefreshSMS();

        return EVENT_CMDRET_CONTINUE;
    }

    if (!CanDisplayUnitMovement(proc, unit->x, unit->y))
        return EVENT_CMDRET_REPEAT;

    sub_800EEA0(proc, unit, xTarget, yTarget);

    return EVENT_CMDRET_CONTINUE;
}

int Evt_MoveCharacterManual(struct EventProc* proc)
{
    // script[0]: pid of unit to move
    // script[1]: pointer to move script

    struct Unit* unit = GetUnitByCharId(proc->script[0]);

    int x, y;

    u8 const* movescr = (u8 const*) proc->script[1];

    if ((proc->flags & EVENT_FLAG_SKIPPED) || proc->unk45)
    {
        x = unit->x;
        y = unit->y;

        ApplyMoveScriptToCoordinates(&x, &y, movescr);

        TryMoveUnit(unit, x, y, FALSE);
        RefreshSMS();

        return EVENT_CMDRET_CONTINUE;
    }

    if (!CanDisplayUnitMovement(proc, unit->x, unit->y))
        return EVENT_CMDRET_REPEAT;

    sub_800EFB4(proc, unit, movescr);

    return EVENT_CMDRET_CONTINUE;
}

int Evt_MovePositionManual(struct EventProc* proc)
{
    // script[0]: coords (u16, u16) of unit to move
    // script[1]: pointer to move script

    struct Unit* unit;

    int x = EVTCMD_GET_X(proc->script[0]);
    int y = EVTCMD_GET_Y(proc->script[0]);

    u8 const* movescr = (u8 const*) proc->script[1];

    unit = GetUnit(gMapUnit[y][x]);

    if ((proc->flags & EVENT_FLAG_SKIPPED) || proc->unk45)
    {
        ApplyMoveScriptToCoordinates(&x, &y, movescr);

        TryMoveUnit(unit, x, y, FALSE);
        RefreshSMS();

        return EVENT_CMDRET_CONTINUE;
    }

    if (!CanDisplayUnitMovement(proc, x, y))
        return EVENT_CMDRET_REPEAT;

    sub_800EFB4(proc, unit, movescr);

    return EVENT_CMDRET_CONTINUE;
}

int Evt_MoveCharacterNextTo(struct EventProc* proc)
{
    // script[0]: pid of unit to move
    // script[1]: pid of unit to go next to

    struct Unit* unit = GetUnitByCharId(proc->script[1]);

    int x = unit->x;
    int y = unit->y;

    unit = GetUnitByCharId(proc->script[0]);

    if ((proc->flags & EVENT_FLAG_SKIPPED) || proc->unk45)
    {
        TryMoveUnit(unit, x, y, TRUE);
        RefreshSMS();

        return EVENT_CMDRET_CONTINUE;
    }

    if (!CanDisplayUnitMovement(proc, unit->x, unit->y))
        return EVENT_CMDRET_REPEAT;

    sub_800EEA0(proc, unit, x, y);

    return EVENT_CMDRET_CONTINUE;
}

void TryMoveUnit(struct Unit* unit, int x, int y, s8 moveClosest)
{
    struct Vec2 vec;

    if (x == 0xFF)
        x = -1;

    if (y == 0xFF)
        y = -1;

    vec.x = x;
    vec.y = y;

    // ..?

    if (gMapTerrain[y][x] == TERRAIN_TILE_00)
    {
    }
    else if (moveClosest)
    {
        GetUnitClosestValidPosition(unit, x, y, &vec);
    }

    unit->x = vec.x;
    unit->y = vec.y;

    UnitUpdateRescueePosition(unit);

    if (unit->state & US_UNDER_A_ROOF)
        return;

    unit->state &= ~(US_HIDDEN | US_NOT_DEPLOYED);

    RefreshEntityMaps();
}

Bool sub_800EEA0(ProcPtr proc, struct Unit* unit, int x, int y)
{
    struct Vec2 vec;

    int terrainChanged = FALSE;

    if (x == 0xFF)
        x = -1;

    if (y == 0xFF)
        y = -1;

    vec.x = x;
    vec.y = y;

    if (gMapTerrain[y][x] == TERRAIN_TILE_00)
    {
        terrainChanged = TRUE;
        gMapTerrain[y][x] = TERRAIN_PLAINS;
    }
    else
    {
        GetUnitClosestValidPosition(unit, x, y, &vec);
    }

    sub_80193F4(unit->x, unit->y, unit->job->movTerrainTable);
    sub_8019600(vec.x, vec.y, gMoveScrBuf);

    if (terrainChanged)
        gMapTerrain[y][x] = TERRAIN_TILE_00;

    return sub_800EFB4(proc, unit, gMoveScrBuf);
}

Bool sub_800EFB4(struct EventProc* proc, struct Unit* unit, u8 const* movescr)
{
    struct GenericProc* gproc;

    struct MuProc* mu = MU_Start(unit);

    int x, y;

    if (!(proc->flags & EVENT_FLAG_UNITCAM))
        sub_805F91C(mu);

    gproc = SpawnProc(ProcScr_Unk_085C4580, PROC_TREE_3);
    gproc->ptr = mu;

    HideUnitSMS(unit);
    unit->state |= US_HIDDEN;

    x = unit->x;
    y = unit->y;

    gMapOther[y][x] = 0;

    ApplyMoveScriptToCoordinates(&x, &y, movescr);

    gproc->x = x;
    gproc->y = y;

    sub_805FD78(mu, movescr);

    gMapOther[y][x] = unit->id;

    return TRUE;
}

void sub_800F094(struct GenericProc* proc)
{
}

void sub_800F0A4(struct GenericProc* proc)
{
    struct MuProc* mu = proc->ptr;
    struct Unit* unit;

    if (sub_805FD40(mu))
        return;

    sub_80608EC(mu);

    unit = mu->unit;

    unit->x = proc->x;
    unit->y = proc->y;

    UnitUpdateRescueePosition(unit);

    sub_8022A5C(unit);
    unit->state &= ~US_HIDDEN;

    RefreshEntityMaps();
    RefreshSMS();

    Proc_Break(proc);
}

int Evt_LoadUnits(struct EventProc* proc)
{
    // script[0]: address of unit info list

    FillBmMap(gMapOther, 0);

    proc->unitInfo = (struct UnitInfo const*) proc->script[0];
    proc->onIdle = sub_800F260;

    return EVENT_CMDRET_YIELD;
}

int Evt_LoadUnitsInstant(struct EventProc* proc)
{
    // script[0]: address of unit info list

    FillBmMap(gMapOther, 0);

    proc->unitInfo = (struct UnitInfo const*) proc->script[0];
    sub_800F324(proc);

    return EVENT_CMDRET_YIELD;
}

int sub_800F1B0(int start)
{
    int i;

    for (i = start; i < 0x40; ++i)
    {
        struct Unit* unit = GetUnit(i);

        if (!unit)
            continue;

        if (!unit->person)
            continue;

        if (unit->state & (US_DEAD | US_NOT_DEPLOYED))
            continue;

        return i;
    }

    return 0;
}

Bool sub_800F210(struct UnitInfo const* info)
{
    if (info->xLoad == info->xMove)
        if (info->yLoad == info->yMove)
            if (gMapUnit[info->yLoad][info->xLoad] != 0)
                return TRUE;

    return FALSE;
}

void sub_800F260(struct EventProc* proc)
{
    struct UnitInfo const* info = proc->unitInfo;

    while (TRUE)
    {
        if (info->pid == 0)
        {
            proc->onIdle = sub_800F56C;
            break;
        }

        if ((proc->flags & EVENT_FLAG_SKIPPED) || proc->unk45)
        {
            while (info->pid != 0)
            {
                sub_800CCF0(info, NULL);
                info++;
            }

            proc->onIdle = NULL;
            return;
        }

        if (!sub_800F210(info))
        {
            if (!CanDisplayUnitMovement(proc, info->xLoad, info->yLoad))
                break;

            sub_800CCF0(info, proc);
        }

        info++;
        proc->unitInfo = info;
    }

    sub_8021FE8();
}

void sub_800F324(struct EventProc* proc)
{
    struct UnitInfo const* info = proc->unitInfo;

    int id;
    struct Unit* unit;

    int blueCount = 0;

    FOR_UNITS_FACTION(FACTION_BLUE, unit,
    {
        if (unit->state & US_DEAD)
            continue;

        blueCount++;
    })

    if (blueCount > 0 && GetChapterDefinition(gPlaySt.chapter)->bool_previewMap)
        return;

    if (GetChapterDefinition(gPlaySt.chapter)->bool_previewMap)
    {
        FOR_UNITS_FACTION(FACTION_BLUE, unit,
        {
            if (unit->state & US_DEAD)
                continue;

            unit->state |= US_HIDDEN;
        })
    }
    else
    {
        FOR_UNITS_FACTION(FACTION_BLUE, unit,
        {
            if (unit->state & US_DEAD)
                continue;

            unit->state |= US_HIDDEN;
            unit->state &= ~US_NOT_DEPLOYED;
        })
    }

    id = 0;

    while (info->pid != 0)
    {
        id = sub_800F1B0(id);

        if (id == 0)
            break;

        unit = GetUnit(id);
        id++;

        sub_800CD98(info, unit);

        info++;
    }

    FOR_UNITS_FACTION(FACTION_BLUE, unit,
    {
        if (unit->state & US_DEAD)
            continue;

        if (!(unit->state & US_HIDDEN))
            continue;

        unit->state |= US_NOT_DEPLOYED;
    })

    RefreshEntityMaps();
    RefreshSMS();
}

s8 MU_IsAnyActive(void);

void sub_800F56C(struct EventProc* proc)
{
    if (MU_IsAnyActive())
        return;

    FillBmMap(gMapOther, 0);
    proc->onIdle = NULL;
}

int Evt_WaitForMovement(struct EventProc* proc)
{
    if (MU_IsAnyActive())
        return EVENT_CMDRET_REPEAT;

    FillBmMap(gMapOther, 0);
    return EVENT_CMDRET_YIELD;
}

int Evt_CameraFollowsMovementOn(struct EventProc* proc)
{
    proc->flags |= EVENT_FLAG_UNITCAM;
    return EVENT_CMDRET_CONTINUE;
}

int Evt_CameraFollowsMovementOff(struct EventProc* proc)
{
    proc->flags &= ~EVENT_FLAG_UNITCAM;
    return EVENT_CMDRET_CONTINUE;
}

int Evt_AsmCall(struct EventProc* proc)
{
    // script[0]: address of function

    typedef void(*FuncType)(struct EventProc* proc);
    FuncType func;

    u32 const* script = proc->script;

    func = (FuncType) proc->script[0];
    func(proc);

    if (script != proc->script)
        return EVENT_CMDRET_JUMPED;

    return EVENT_CMDRET_CONTINUE;
}

int Evt_AsmUntil(struct EventProc* proc)
{
    // script[0]: address of function

    s8 result;

    typedef s8(*FuncType)(struct EventProc* proc);
    FuncType func;

    u32 const* script = proc->script;

    func = (FuncType) proc->script[0];
    result = func(proc);

    if (script != proc->script)
        return EVENT_CMDRET_JUMPED;

    if (result)
        return EVENT_CMDRET_CONTINUE;
    else
        return EVENT_CMDRET_REPEAT;
}

int Evt_AsmWhile(struct EventProc* proc)
{
    // script[0]: address of function

    s8 result;

    typedef s8(*FuncType)(struct EventProc* proc);
    FuncType func;

    u32 const* script = proc->script;

    func = (FuncType) proc->script[0];
    result = func(proc);

    if (script != proc->script)
        return EVENT_CMDRET_JUMPED;

    if (result)
        return EVENT_CMDRET_REPEAT;
    else
        return EVENT_CMDRET_CONTINUE;
}

int Evt_Stop(struct EventProc* proc)
{
    return EVENT_CMDRET_REPEAT;
}

int Evt_Label(struct EventProc* proc)
{
    return EVENT_CMDRET_CONTINUE;
}

int EventGotoLabel(struct EventProc* proc, int label)
{
    u32 const* it;

    for (it = proc->scriptStart; it[0] != EVT_CMD_END; it += sEventCmdInfoTable[it[0]].size)
    {
        if (it[0] == EVT_CMD_LABEL && it[1] == label)
        {
            proc->script = it + sEventCmdInfoTable[EVT_CMD_LABEL].size;
            return EVENT_CMDRET_JUMPED;
        }
    }

    return EVENT_CMDRET_YIELD;
}

int Evt_Goto(struct EventProc* proc)
{
    // script[0]: label to go to

    return EventGotoLabel(proc, proc->script[0]);
}

int Evt_GotoIfnCharacterAlive(struct EventProc* proc)
{
    // script[0]: label to go to
    // script[1]: pid of character

    u16 pid = proc->script[1];

    FOR_UNITS_FACTION(FACTION_BLUE, unit,
    {
        if (unit->state & US_DEAD)
            continue;

        if (unit->person->id == pid)
            return EVENT_CMDRET_CONTINUE;
    })

    return EventGotoLabel(proc, proc->script[0]);
}

int Evt_GotoIfnCharacterInTeam(struct EventProc* proc)
{
    // script[0]: label to go to
    // script[1]: pid of character

    u16 pid = proc->script[1];

    FOR_UNITS_FACTION(FACTION_BLUE, unit,
    {
        if (unit->state & (US_DEAD | US_NOT_DEPLOYED))
            continue;

        if (unit->person->id == pid)
            return EVENT_CMDRET_CONTINUE;
    })

    return EventGotoLabel(proc, proc->script[0]);
}

int Evt_GotoIfAsm(struct EventProc* proc)
{
    // script[0]: label to go to
    // script[1]: address of function

    typedef s8(*FuncType)(void);
    FuncType func;

    func = (FuncType) proc->script[1];

    if (func())
        return EventGotoLabel(proc, proc->script[0]);

    return EVENT_CMDRET_CONTINUE;
}

int Evt_GotoIfnAsm(struct EventProc* proc)
{
    // script[0]: label to go to
    // script[1]: address of function

    typedef s8(*FuncType)(void);
    FuncType func;

    func = (FuncType) proc->script[1];

    if (!func())
        return EventGotoLabel(proc, proc->script[0]);

    return EVENT_CMDRET_CONTINUE;
}

int Evt_GotoIfSkipping(struct EventProc* proc)
{
    if (proc->flags & (EVENT_FLAG_SKIPPED | EVENT_FLAG_TEXTSKIPPED))
        return EventGotoLabel(proc, proc->script[0]);

    return EVENT_CMDRET_CONTINUE;
}

int Evt_GotoIfEid(struct EventProc* proc)
{
    // script[0]: label to go to
    // script[1]: flag to check

    u32 const* it = proc->scriptStart;

    int label = proc->script[0];

    if (!CheckFlag(proc->script[1]))
        return EVENT_CMDRET_CONTINUE;

    while (it[0] != EVT_CMD_END)
    {
        if (it[0] == EVT_CMD_LABEL && it[1] == label)
        {
            proc->script = it + sEventCmdInfoTable[EVT_CMD_LABEL].size;
            return EVENT_CMDRET_JUMPED;
        }

        it += sEventCmdInfoTable[it[0]].size;
    }

    return EVENT_CMDRET_YIELD;
}

int Evt_GotoIfnEid(struct EventProc* proc)
{
    // script[0]: label to go to
    // script[1]: flag to check

    u32 const* it = proc->scriptStart;

    int label = proc->script[0];

    if (CheckFlag(proc->script[1]))
        return EVENT_CMDRET_CONTINUE;

    while (it[0] != EVT_CMD_END)
    {
        if (it[0] == EVT_CMD_LABEL && it[1] == label)
        {
            proc->script = it + sEventCmdInfoTable[EVT_CMD_LABEL].size;
            return EVENT_CMDRET_JUMPED;
        }

        it += sEventCmdInfoTable[it[0]].size;
    }

    return EVENT_CMDRET_YIELD;
}

int Evt_GotoIfCharacterActive(struct EventProc* proc)
{
    // script[0]: label to go to
    // script[1]: pid

    u32 const* it = proc->scriptStart;

    int label = proc->script[0];

    if (gActiveUnit->person->id != proc->script[1])
        return EVENT_CMDRET_CONTINUE;

    while (it[0] != EVT_CMD_END)
    {
        if (it[0] == EVT_CMD_LABEL && it[1] == label)
        {
            proc->script = it + sEventCmdInfoTable[EVT_CMD_LABEL].size;
            return EVENT_CMDRET_JUMPED;
        }

        it += sEventCmdInfoTable[it[0]].size;
    }

    return EVENT_CMDRET_YIELD;
}

int Evt_Jump(struct EventProc* proc)
{
    // script[0]: address of new script

    u32 const* newScript = (u32 const*) proc->script[0];

    proc->script = newScript;
    proc->scriptStart = newScript;

    return EVENT_CMDRET_JUMPED;
}

static int EventGiveItem(struct Unit* unit, u16 iid, struct EventProc* proc);

int Evt_GiveItemToActive(struct EventProc* proc)
{
    // script[0]: iid

    u16 iid = proc->script[0];
    return EventGiveItem(gActiveUnit, iid, proc);
}

int Evt_GiveItemTo(struct EventProc* proc)
{
    // script[0]: pid
    // script[1]: iid

    u16 pid = proc->script[0];
    u16 iid = proc->script[1];

    if (pid == 0)
        pid = proc->pidParam;

    return EventGiveItem(GetUnitByCharId(pid), iid, proc);
}

static int EventGiveItem(struct Unit* unit, u16 iid, struct EventProc* proc)
{
    if (iid == 0)
        iid = proc->iidParam;

    sub_80121F4(unit, iid, proc);

    return EVENT_CMDRET_YIELD;
}

int Evt_MapChange(struct EventProc* proc)
{
    // script[0]: map change id

    int id = proc->script[0];

    // Common with Evt_MapChangePosition

    if (id == -1)
        id = proc->mapChangeParam;

    if (!proc->unk45)
    {
        PrepareBattleMapFade();

        ApplyMapChange(id);
        AddMapChangeTrap(id);

        RefreshTerrainMap();
        UpdateRoofedUnits();
        RedrawBattleMap();

        StartBattleMapFade(TRUE);
    }
    else
    {
        ApplyMapChange(id);
        AddMapChangeTrap(id);

        RefreshTerrainMap();
        UpdateRoofedUnits();
    }

    return EVENT_CMDRET_YIELD;
}

int Evt_MapChangePosition(struct EventProc* proc)
{
    // script[0]: (x) | ((y) << 8)

    u32 script = proc->script[0];

    u8 x = (script) % 0x100;
    u8 y = (script >> 8) % 0x100;

    int id = GetMapChangeIdByPosition(x, y);

    // Common with Evt_MapChange

    if (id == -1)
        id = proc->mapChangeParam;

    if (!proc->unk45)
    {
        PrepareBattleMapFade();

        ApplyMapChange(id);
        AddMapChangeTrap(id);

        RefreshTerrainMap();
        UpdateRoofedUnits();
        RedrawBattleMap();

        StartBattleMapFade(TRUE);
    }
    else
    {
        ApplyMapChange(id);
        AddMapChangeTrap(id);

        RefreshTerrainMap();
        UpdateRoofedUnits();
    }

    return EVENT_CMDRET_YIELD;
}

int Evt_ChangeFaction(struct EventProc* proc)
{
    // script[0]: pid
    // script[1]: faction

    u8 pid = proc->script[0], id /* unused */;
    int faction = proc->script[1];

    FOR_UNITS_ALL(unit,
    {
        if (unit->state & US_DEAD)
            continue;

        id = unit->person->id; // unused

        if (unit->person->id == pid)
            UnitChangeFaction(unit, faction);
    })

    RefreshSMS();

    return EVENT_CMDRET_YIELD;
}

static void sub_800FFA8(struct EventProc* proc);

int Evt_FlashCursorPosition(struct EventProc* proc)
{
    // script[0]: position

    struct GenericProc* gproc;
    short x, y;

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    x = EVTCMD_GET_X(proc->script[0]);
    y = EVTCMD_GET_Y(proc->script[0]);

    gproc = SpawnProc(ProcScr_Unk_085C4590, proc);

    gproc->unk64 = x;
    gproc->unk66 = y;

    proc->onIdle = sub_800FFA8;

    return EVENT_CMDRET_YIELD;
}

int Evt_FlashCursorCharacter(struct EventProc* proc)
{
    // script[0]: pid

    struct GenericProc* gproc;

    struct Unit* unit = GetUnitByCharId(proc->script[0]);

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    gproc = SpawnProc(ProcScr_Unk_085C4590, proc);

    gproc->unk64 = unit->x;
    gproc->unk66 = unit->y;

    proc->onIdle = sub_800FFA8;

    return EVENT_CMDRET_YIELD;
}

static void sub_800FFA8(struct EventProc* proc)
{
    if (Proc_Find(ProcScr_Unk_085C4590) != NULL)
        return;

    proc->onIdle = NULL;
}

void sub_800FFD4(struct GenericProc* proc)
{
    proc->unk58 = 60;
}

void sub_800FFEC(struct GenericProc* proc)
{
    if (--proc->unk58 <= 0)
        Proc_Break(proc);

    sub_8015F1C(proc->unk64 << 4, proc->unk66 << 4, 0);
}

int Evt_DisplayCursor(struct EventProc* proc)
{
    // script[0]: position

    struct GenericProc* gproc;
    short x, y;

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    x = EVTCMD_GET_X(proc->script[0]);
    y = EVTCMD_GET_Y(proc->script[0]);

    gproc = SpawnProc(ProcScr_Unk_085C45A8, proc);

    gproc->unk64 = x;
    gproc->unk66 = y;

    return EVENT_CMDRET_YIELD;
}

void sub_8010104(struct GenericProc* proc)
{
    sub_8015F1C(proc->unk64 << 4, proc->unk66 << 4, 0);
}

int Evt_ClearCursor(struct EventProc* proc)
{
    Proc_EndEach(ProcScr_Unk_085C45A8);
    return EVENT_CMDRET_CONTINUE;
}

int Evt_RemoveCharacter(struct EventProc* proc)
{
    // script[0]: pid

    struct Unit* unit = GetUnitByCharId(proc->script[0]);

    ClearUnit(unit);

    RefreshEntityMaps();
    RefreshSMS();

    return EVENT_CMDRET_YIELD;
}

static void sub_8010208(struct EventProc* proc);

int Evt_RemoveCharacterDisplayed(struct EventProc* proc)
{
    // script[0]: pid

    struct MuProc* mu;
    struct Unit* unit;

    proc->pidParam = proc->script[0];
    unit = GetUnitByCharId(proc->pidParam);

    HideUnitSMS(unit);

    mu = MU_Start(unit);

    MU_SetDefaultFacing_Auto();
    MU_StartDeathFade(mu);

    proc->onIdle = sub_8010208;
    proc->sleepDuration = 60;

    return EVENT_CMDRET_YIELD;
}

static void sub_8010208(struct EventProc* proc)
{
    struct Unit* unit = GetUnitByCharId(proc->pidParam);

    MU_EndAll();

    ClearUnit(unit);

    RefreshEntityMaps();
    RefreshSMS();

    proc->onIdle = NULL;
}

void UnitSetAi(struct Unit* unit, u8 aiA, u8 aiB, u8 unused)
{
    if (aiA != 0x10)
    {
        unit->aiA = aiA;
        unit->aiApc = 0;
    }

    if (aiB != 0x19)
    {
        unit->aiB = aiB;
        unit->aiBpc = 0;

        if (aiB == 0x0C)
            unit->aiFlags |= 8;
    }
}

int Evt_ChangeAiCharacter(struct EventProc* proc)
{
    // script[0]: pid
    // script[1]: (aiA) | (aiB << 8) | (aiC << 16)

    u8 pid = proc->script[0];

    u8 aiA = (proc->script[1] & 0x000000FF);
    u8 aiB = (proc->script[1] & 0x0000FF00) >> 8;
    u8 aiC = (proc->script[1] & 0x00FF0000) >> 16;

    FOR_UNITS_ALL(unit,
    {
        if (unit->state & (US_DEAD | US_HIDDEN))
            continue;

        if (unit->person->id != pid)
            continue;

        UnitSetAi(unit, aiA, aiB, aiC);
    })

    return EVENT_CMDRET_CONTINUE;
}

int Evt_ChangeAiPosition(struct EventProc* proc)
{
    // script[0]: position
    // script[1]: (aiA) | (aiB << 8) | (aiC << 16)

    s8 x = EVTCMD_GET_X_RAW(proc->script[0]);
    s8 y = EVTCMD_GET_Y_RAW(proc->script[0]);

    u8 aiA = (proc->script[1] & 0x000000FF);
    u8 aiB = (proc->script[1] & 0x0000FF00) >> 8;
    u8 aiC = (proc->script[1] & 0x00FF0000) >> 16;

    FOR_UNITS(0x41, 0xC0, unit,
    {
        if (unit->state & (US_DEAD | US_HIDDEN))
            continue;

        if (unit->x != x)
            continue;

        if (unit->y != y)
            continue;

        UnitSetAi(unit, aiA, aiB, aiC);
    })

    return EVENT_CMDRET_CONTINUE;
}

int Evt_SetEid(struct EventProc* proc)
{
    // script[0]: flag

    SetEid(proc->script[0]);
    return EVENT_CMDRET_CONTINUE;
}

int Evt_ClearEid(struct EventProc* proc)
{
    // script[0]: flag

    ClearEid(proc->script[0]);
    return EVENT_CMDRET_CONTINUE;
}

int Evt_Music(struct EventProc* proc)
{
    // script[0]: song id

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    sub_800322C(proc->script[0], 1, NULL);

    return EVENT_CMDRET_YIELD;
}

int Evt_MusicOverride(struct EventProc* proc)
{
    // script[0]: song id

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    sub_80033C8(proc->script[0]);
    sub_8014BAC(proc, 33);

    return EVENT_CMDRET_YIELD;
}

int Evt_MusicRestore(struct EventProc* proc)
{
    sub_8003434();

    return EVENT_CMDRET_YIELD;
}

int Evt_MusicFadeOut(struct EventProc* proc)
{
    // script[0]: speed

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    sub_8003064(proc->script[0]);

    return EVENT_CMDRET_YIELD;
}

int Evt_MusicVolumeLower(struct EventProc* proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    StartMusicVolumeChange(0x100, 0x90, 10, proc);

    return EVENT_CMDRET_YIELD;
}

int Evt_MusicVolumeRestore(struct EventProc* proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
    {
        sub_8003028(0x100);

        return EVENT_CMDRET_CONTINUE;
    }

    StartMusicVolumeChange(0x90, 0x100, 10, proc);

    return EVENT_CMDRET_YIELD;
}

int Evt_PlaySound(struct EventProc* proc)
{
    // script[0]: song id

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    PlaySE(proc->script[0]);

    return EVENT_CMDRET_CONTINUE;
}

int sub_80106A0(struct EventProc* proc)
{
    proc->flags |= EVENT_FLAG_5;
    return 0;
}

int Evt_GotoChapter(struct EventProc* proc)
{
    MU_EndAll();

    SetNextChapterId(proc->script[0]);
    SetNextGameAction(GAME_ACTION_1);

    proc->flags |= EVENT_FLAG_5;

    if (!(proc->flags & EVENT_FLAG_SKIPPED))
    {
        sub_8003064(4);
        sub_8014708(proc);
    }
    else
    {
        sub_8003064(4);
    }

    return EVENT_CMDRET_YIELD;
}

int Evt_GameEnd(struct EventProc* proc)
{
    SetNextGameAction(GAME_ACTION_2);
    sub_80106A0(proc);

    return EVENT_CMDRET_YIELD;
}

int Evt_LoadMap(struct EventProc* proc)
{
    // script[0]: chapter
    // script[1]: camera x
    // script[2]: camera y

    gPlaySt.chapter = proc->script[0];

    sub_8029084();
    sub_8029370();

    gBmSt.camera.x = sub_8015ECC(proc->script[1] * 16);
    gBmSt.camera.y = sub_8015EF4(proc->script[2] * 16);

    RefreshEntityMaps();
    RedrawBattleMap();
    RefreshSMS();

    return EVENT_CMDRET_CONTINUE;
}

static void sub_8010888(struct EventProc* proc);

int Evt_NoSkip(struct EventProc* proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
    {
        proc->flags &= ~EVENT_FLAG_SKIPPED;

        InitUiGraphics();
        UnpackChapterMapPalette();
        ApplyMapSpritePalettes();

        proc->onIdle = sub_8010888;
    }

    proc->flags |= EVENT_FLAG_DISABLESKIP;

    return EVENT_CMDRET_YIELD;
}

static void sub_8010888(struct EventProc* proc)
{
    proc->unk45 = FALSE;
    sub_8014748(proc);

    proc->onIdle = NULL;
}

int Evt_NoSkipNoTextSkip(struct EventProc* proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
    {
        proc->flags &= ~EVENT_FLAG_SKIPPED;

        proc->unk45 = FALSE;
        sub_8014748(proc);
    }

    proc->flags |= (EVENT_FLAG_DISABLESKIP | EVENT_FLAG_DISABLETEXTSKIP);

    return EVENT_CMDRET_YIELD;
}

int Evt_YesSkip(struct EventProc* proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    proc->flags &= ~(EVENT_FLAG_DISABLESKIP | EVENT_FLAG_DISABLETEXTSKIP);

    return EVENT_CMDRET_YIELD;
}

int Evt_FadeToDark(struct EventProc* proc)
{
    // script[0]: duration?

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    StartBlockingFadeInBlack(proc->script[0], proc);

    return EVENT_CMDRET_YIELD;
}

int Evt_FadeFromDark(struct EventProc* proc)
{
    // script[0]: duration?

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    StartBlockingFadeOutBlack(proc->script[0], proc);

    return EVENT_CMDRET_YIELD;
}

int Evt_FadeToWhite(struct EventProc* proc)
{
    // script[0]: duration?

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    sub_8014680(proc->script[0], proc);

    return EVENT_CMDRET_YIELD;
}

int Evt_FadeFromWhite(struct EventProc* proc)
{
    // script[0]: duration?

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    sub_8014698(proc->script[0], proc);

    return EVENT_CMDRET_YIELD;
}

int Evt_HideMap(struct EventProc* proc)
{
    sub_8012710(proc);
    return EVENT_CMDRET_CONTINUE;
}

int Evt_ShowMap(struct EventProc* proc)
{
    sub_8012738(proc);
    return EVENT_CMDRET_CONTINUE;
}

int Evt_GiveMoneyActive(struct EventProc* proc)
{
    int money, given;

    given = proc->script[0];

    if (given == 0)
        given = proc->moneyParam;

    if (UNIT_FACTION(gActiveUnit) == FACTION_BLUE)
    {
        money = GetMoney();
        money += given;
        SetMoney(money);
    }

    sub_80120D0(given, proc);

    return EVENT_CMDRET_YIELD;
}

static void EventScriptedBattleWait(struct EventProc* proc);

int Evt_FightScripted(struct EventProc* proc)
{
    // script[0]: instigator pid
    // script[1]: target pid
    // script[2]: battle script address
    // script[3]: is ballista bool?

    struct Unit* unitA;
    struct Unit* unitB;

    struct BattleHit const* battlescr;

    int isBallista;

    proc->savedGameLock = GetGameLogicLock();
    proc->onIdle = EventScriptedBattleWait;

    unitA = GetUnitByCharId(proc->script[0]);
    unitB = GetUnitByCharId(proc->script[1]);

    battlescr = (struct BattleHit const*) proc->script[2];
    isBallista = proc->script[3];

    SetActiveUnit(unitA);

    HideUnitSMS(gActiveUnit);

    MU_Start(gActiveUnit);
    MU_SetDefaultFacing_Auto();

    if (GetItemType(unitA->items[0]) == ITEM_KIND_STAFF)
    {
        BattleInitItemEffect(unitA, 0);
        BattleInitItemEffectTarget(unitB);
    }
    else if (!isBallista)
    {
        BattleGenerateReal(unitA, unitB);
    }
    else
    {
        BattleGenerateBallistaReal(unitA, unitB);
    }

    gBattleUnitA.expGain = 0;
    gBattleUnitB.expGain = 0;

    ClearBattleHits();

    while (TRUE)
    {
        *gBattleHitIt = *battlescr;

        if (battlescr->info & BATTLE_HIT_INFO_END)
            break;

        sub_80260CC();
        battlescr++;
    }

    sub_80260DC();
    sub_8025C7C();

    Proc_Mark(proc, PROC_MARK_7);

    gAiDecision.xMove = unitA->x;
    gAiDecision.yMove = unitA->y;

    return EVENT_CMDRET_YIELD;
}

static void sub_8010CB4(struct EventProc* proc);

static void EventScriptedBattleWait(struct EventProc* proc)
{
    if (proc->savedGameLock == GetGameLogicLock())
        proc->onIdle = sub_8010CB4;
}

static void sub_8010CB4(struct EventProc* proc)
{
    proc->onIdle = NULL;

    Proc_Mark(proc, PROC_MARK_6);
    sub_802EDC4();
}

int sub_8010CD8(struct EventProc* proc)
{
    proc->flags |= EVENT_FLAG_6;
    return EVENT_CMDRET_CONTINUE;
}

int Evt_SetOnSkipAsm(struct EventProc* proc)
{
    // script[0]: function address

    proc->onSkip = (void(*)(void)) proc->script[0];
    return EVENT_CMDRET_CONTINUE;
}

int Evt_SetWeather(struct EventProc* proc)
{
    // script[0]: weather id

    struct GenericProc* gproc;

    gproc = SpawnProcLocking(ProcScr_WeatherChangeFade, proc);
    gproc->unk64 = proc->script[0];

    return EVENT_CMDRET_YIELD;
}

void sub_8010D70(struct GenericProc* proc)
{
    sub_8028E80(proc->unk64);
}

int Evt_WMStart(struct EventProc* proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    sub_80922B0();

    SetFaceConfig(gWmEventFaceConfig);
    proc->background = 0;

    sub_80933F8();

    StartWMIntroRotation(proc);
    PlayWMIntroBGM();

    return EVENT_CMDRET_YIELD;
}

int Evt_WMEnd(struct EventProc* proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_YIELD;

    sub_8014708(proc);
    proc->unk45 = TRUE;

    return EVENT_CMDRET_YIELD;
}

static void sub_8010F14(struct EventProc* proc);

int Evt_WMZoomTo(struct EventProc* proc)
{
    // script[0]: coords relative to center of screen

    int x = 120 + EVTCMD_GET_X(proc->script[0]);
    int y = 80  + EVTCMD_GET_Y(proc->script[0]);

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    sub_80928DC(x, y, proc);
    sub_809347C(x, y);

    proc->onIdle = sub_8010F14;

    return EVENT_CMDRET_YIELD;
}

int Evt_WMZoomBack(struct EventProc* proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    sub_8092CD8(proc);
    sub_80934A0();

    proc->onIdle = sub_8010F14;

    return EVENT_CMDRET_YIELD;
}

static void sub_8010F14(struct EventProc* proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
    {
        sub_8092E94();
        proc->onIdle = NULL;

        return;
    }

    if (sub_8092E68())
        return;

    proc->onIdle = NULL;
}

struct WmEventFaceProc
{
    /* 00 */ PROC_HEADER;

    /* 2A */ short faceSlot;
    /* 2C */ short x;
    /* 2E */ short y;
    /* 30 */ short fid;
    /* 32 */ u16 disp;
    /* 34 */ short xOffStart;
    /* 36 */ short blendVal;
};

int Evt_WMPutFace(struct EventProc* proc)
{
    // script[0]: face slot
    // script[1]: position
    // script[2]: fid

    struct WmEventFaceProc* faceproc;

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    faceproc = SpawnProc(ProcScr_WmEventShowFace, proc);

    faceproc->faceSlot = proc->script[0];

    faceproc->x = EVTCMD_GET_X(proc->script[1]);
    faceproc->y = EVTCMD_GET_Y(proc->script[1]);

    faceproc->fid = proc->script[2];
    faceproc->disp = FACE_DISP_HLAYER(1) | FACE_DISP_KIND(FACE_64x72);

    return EVENT_CMDRET_CONTINUE;
}

void sub_801105C(struct WmEventFaceProc* proc)
{
    int disp;
    struct FaceProc* face;

    if (proc->x > 120)
        proc->xOffStart = -0x20;
    else
        proc->xOffStart = +0x20;

    face = StartFace(proc->faceSlot, proc->fid, proc->x + proc->xOffStart, proc->y, proc->disp);

    proc->blendVal = 0;

    disp = GetFaceDisp(face);
    SetFaceDisp(face, disp | FACE_DISP_BLEND);

    SetBlendConfig(0, proc->blendVal, 0x10 - proc->blendVal, 0);

    SetBlendTargetA(0, 0, 0, 0, 0);
    SetBlendTargetB(0, 0, 1, 0, 0); SetBlendBackdropB(1);
}

void sub_80111A8(struct WmEventFaceProc* proc)
{
    int xOff = sub_8013B24(4, proc->xOffStart, 0, proc->blendVal++, 0x10);
    gFaces[proc->faceSlot]->xDisp = proc->x + xOff;

    SetBlendConfig(0, proc->blendVal, 0x10 - proc->blendVal, 0);

    if (proc->blendVal >= 0x10)
    {
        int disp = GetFaceDisp(gFaces[proc->faceSlot]);
        disp &= ~FACE_DISP_BLEND;
        SetFaceDisp(gFaces[proc->faceSlot], disp);

        Proc_Break(proc);
    }
}

int Evt_WMRemoveFace(struct EventProc* proc)
{
    // script[0]: face slot

    int faceSlot;
    struct WmEventFaceProc* faceproc;

    faceSlot = proc->script[0];

    if (proc->flags & EVENT_FLAG_SKIPPED)
    {
        EndFaceById(faceSlot);
        return EVENT_CMDRET_CONTINUE;
    }

    if (gFaces[faceSlot] == NULL)
        return EVENT_CMDRET_YIELD;

    faceproc = SpawnProc(ProcScr_WmEventHideFace, proc);
    faceproc->faceSlot = faceSlot;

    return EVENT_CMDRET_CONTINUE;
}

void sub_8011330(struct WmEventFaceProc* proc)
{
    int disp;
    struct FaceProc* face;

    face = gFaces[proc->faceSlot];

    proc->x = face->xDisp;

    if (proc->x > 120)
        proc->xOffStart = +0x10;
    else
        proc->xOffStart = -0x10;

    proc->blendVal = 0;

    disp = GetFaceDisp(face);
    SetFaceDisp(face, disp | FACE_DISP_BLEND);

    SetBlendConfig(0, 0x10 - proc->blendVal, proc->blendVal, 0);

    SetBlendTargetA(0, 0, 0, 0, 0);
    SetBlendTargetB(0, 0, 1, 0, 0); SetBlendBackdropB(1);
}

void sub_801147C(struct WmEventFaceProc* proc)
{
    int xOff = sub_8013B24(1, 0, proc->xOffStart, proc->blendVal++, 0x10);
    gFaces[proc->faceSlot]->xDisp = proc->x + xOff;

    SetBlendConfig(0, 0x10 - proc->blendVal, proc->blendVal, 0);

    if (proc->blendVal >= 0x10)
        Proc_Break(proc);
}

void sub_801154C(struct WmEventFaceProc* proc)
{
    EndFaceById(proc->faceSlot);
}

int Evt_WMMoveFace(struct EventProc* proc)
{
    // script[0]: face slot
    // script[1]: target coords (note: y unused)

    struct WmEventFaceProc* faceproc;

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    faceproc = SpawnProc(ProcScr_WmEventMoveFace, proc);

    faceproc->faceSlot = proc->script[0];
    faceproc->x = EVTCMD_GET_X(proc->script[1]);
    faceproc->y = EVTCMD_GET_Y(proc->script[1]);

    return EVENT_CMDRET_CONTINUE;
}

void sub_8011638(struct WmEventFaceProc* proc)
{
    proc->xOffStart = 0;
    proc->blendVal = proc->x - gFaces[proc->faceSlot]->xDisp;
    proc->x = gFaces[proc->faceSlot]->xDisp;
}

void sub_80116A8(struct WmEventFaceProc* proc)
{
    int xOff = sub_8013B24(4, 0, proc->blendVal, proc->xOffStart++, 0x20);
    gFaces[proc->faceSlot]->xDisp = proc->x + xOff;

    if (proc->xOffStart >= 0x20)
        Proc_Break(proc);
}

int Evt_Nop54(struct EventProc* proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    return EVENT_CMDRET_YIELD;
}

int Evt_Nop55(struct EventProc* proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    return EVENT_CMDRET_YIELD;
}

int Evt_WMText(struct EventProc* proc)
{
    // script[0]: msgid

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    InitSpriteTalk(OBJCHR_WM_TEXT + 0x21, 2, OBJPAL_WM_TEXT);
    StartTalkMsg(1, 1 + proc->savedGameLock, proc->script[0]);

    SetTalkPrintDelay(4);
    SetTalkFlag(TALK_FLAG_SPRITE);
    SetTalkFlag(TALK_FLAG_NOSKIP);
    SetTalkFlag(TALK_FLAG_7);

    if (proc->flags & EVENT_FLAG_DISABLETEXTSKIP)
        SetTalkFlag(TALK_FLAG_NOSKIP);

    proc->onIdle = EventDialogueWait;

    return EVENT_CMDRET_YIELD;
}

int Evt_WMTextBoxBottom(struct EventProc* proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    sub_8093518();

    proc->savedGameLock = 14;

    InitSpriteTalk(OBJCHR_WM_TEXT + 0x21, 2, OBJPAL_WM_TEXT);
    StartPutTalkSpriteText(0, proc->savedGameLock*8, OBJCHR_WM_TEXT, OBJPAL_WM_TEXTBOX, proc);

    return EVENT_CMDRET_YIELD;
}

int Evt_WMTextBoxTop(struct EventProc* proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    sub_8093518();

    proc->savedGameLock = 0;

    InitSpriteTalk(OBJCHR_WM_TEXT + 0x21, 2, OBJPAL_WM_TEXT);
    StartPutTalkSpriteText(0, proc->savedGameLock*8, OBJCHR_WM_TEXT, OBJPAL_WM_TEXTBOX, proc);

    return EVENT_CMDRET_YIELD;
}

int Evt_WMTextBoxRemove(struct EventProc* proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    EndPutTalkSpriteText();

    return EVENT_CMDRET_YIELD;
}

int Evt_WMArrow(struct EventProc* proc)
{
    int x = EVTCMD_GET_X(proc->script[0]);
    int y = EVTCMD_GET_Y(proc->script[0]);

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    sub_80934BC(x, y);

    return EVENT_CMDRET_CONTINUE;
}

int Evt_WMDisplayHighlight(struct EventProc* proc)
{
    int id = EVTCMD_GET_X(proc->script[0]);
    int var_08 = EVTCMD_GET_Y(proc->script[0]);

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    StartWMHighlight(var_08, id);

    return EVENT_CMDRET_CONTINUE;
}

static void sub_8011A90(struct EventProc* proc);

int Evt_WMRemoveHighlight(struct EventProc* proc)
{
    int id = proc->script[0];

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    sub_80939A8(id);
    proc->unk4C = id;

    proc->onIdle = sub_8011A90;

    return EVENT_CMDRET_YIELD;
}

static void sub_8011A90(struct EventProc* proc)
{
    if (WMHighlightExists(proc->unk4C))
        return;

    proc->onIdle = NULL;
}

static void sub_8011B04(struct EventProc* proc);

int Evt_WMRemoveHighlights(struct EventProc* proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    sub_80939A8(0);
    sub_80939A8(1);

    proc->onIdle = sub_8011B04;

    return EVENT_CMDRET_YIELD;
}

static void sub_8011B04(struct EventProc* proc)
{
    if (sub_80939D0())
        return;

    proc->onIdle = NULL;
}

int Evt_WMDisplayDot(struct EventProc* proc)
{
    int id = proc->script[0];

    int x = EVTCMD_GET_X(proc->script[1]);
    int y = EVTCMD_GET_Y(proc->script[1]);

    int palid = proc->script[2];

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    sub_80939F0(x, y, palid, id);

    return EVENT_CMDRET_CONTINUE;
}

int Evt_WMRemoveDot(struct EventProc* proc)
{
    int id = proc->script[0];

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    EndWMDot(id);

    return EVENT_CMDRET_CONTINUE;
}

int Evt_WMDisplayFlag(struct EventProc* proc)
{
    int id = proc->script[0];

    int x = EVTCMD_GET_X(proc->script[1]);
    int y = EVTCMD_GET_Y(proc->script[1]);

    int palid = proc->script[2];

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    StartWMFlag(x, y, palid, id);

    return EVENT_CMDRET_CONTINUE;
}

int Evt_WMRemoveFlag(struct EventProc* proc)
{
    int id = proc->script[0];

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    EndWMFlag(id);

    return EVENT_CMDRET_CONTINUE;
}

int Evt_WMDisplayMapText(struct EventProc* proc)
{
    int id = proc->script[0];

    int xA = EVTCMD_GET_X(proc->script[1]);
    int yA = EVTCMD_GET_Y(proc->script[1]);

    int unk = proc->script[2];

    int xB = EVTCMD_GET_X(proc->script[3]);
    int yB = EVTCMD_GET_Y(proc->script[3]);

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    StartWMMapText(xA, yA, unk, xB, yB, id);

    return EVENT_CMDRET_CONTINUE;
}

int Evt_WMRemoveMapText(struct EventProc* proc)
{
    int id = proc->script[0];

    if (proc->flags & EVENT_FLAG_SKIPPED)
        return EVENT_CMDRET_CONTINUE;

    sub_8093BB4(id);

    return EVENT_CMDRET_CONTINUE;
}

int Evt_End(struct EventProc* proc)
{
    Proc_Break(proc);

    if (proc->flags & EVENT_FLAG_SKIPPED)
    {
        if (Proc_Find(ProcScr_Face) != NULL)
            EndAllFaces();

        return EVENT_CMDRET_YIELD;
    }

    if (!(proc->flags & EVENT_FLAG_6))
        ClearDialogue(proc);

    return EVENT_CMDRET_YIELD;
}

int Evt_End2(struct EventProc* proc)
{
    return Evt_End(proc);
}

void ClearDialogue(struct EventProc* proc)
{
    if (proc->unk45)
    {
        EndAllFaces();
        return;
    }

    if (Proc_Find(ProcScr_Face) != NULL)
    {
        ClearTalkBubble();
        Proc_ForEach(ProcScr_Face, (ProcFunc) StartFaceFadeOut);

        proc->sleepDuration = 8;
        sub_8014BAC(proc, 8);
    }
}

void EndAllFaces(void)
{
    ClearTalkBubble();
    Proc_EndEach(ProcScr_Face);

    InitFaces();
}

void sub_8011F4C(void)
{
    sub_8011FE8(0x281); // TODO: msgids
}

void sub_8011F64(void)
{
}

Bool sub_8011F70(void)
{
    return Proc_FindMarked(PROC_MARK_6) != NULL ? TRUE : FALSE;
}

Bool sub_8011F8C(void)
{
    return Proc_FindActive(ProcScr_Event) != NULL ? TRUE : FALSE;
}

void sub_8011FB0(void)
{
    Proc_EndEachMarked(PROC_MARK_6);
    Proc_EndEachMarked(PROC_MARK_7);
    Proc_EndEachMarked(PROC_MARK_5);

    MU_EndAll();
}

void sub_8011FD0(void)
{
    SetFaceConfig(gFightEventFaceConfig);
}

extern u32 CONST_DATA EventScr_AutoTalk[];
extern u32 CONST_DATA EventScr_085C46DC[];

extern struct PopupInfo CONST_DATA Popup_085C46FC[];
extern struct PopupInfo CONST_DATA Popup_085C473C[];
extern struct PopupInfo CONST_DATA Popup_085C477C[];
extern struct PopupInfo CONST_DATA Popup_085C47A4[];
extern struct PopupInfo CONST_DATA Popup_085C47DC[];
extern struct PopupInfo CONST_DATA Popup_085C4814[];
extern struct PopupInfo CONST_DATA Popup_085C4854[];
extern struct PopupInfo CONST_DATA Popup_085C4894[];
extern struct PopupInfo CONST_DATA Popup_085C48D4[];
extern struct PopupInfo CONST_DATA Popup_085C4914[];

extern struct ProcScr CONST_DATA ProcScr_Unk_085C4934[];

ProcPtr sub_8011FE8(int msgid)
{
    struct EventProc* proc = StartEventEngine(EventScr_AutoTalk);
    proc->msgParam = msgid;

    return proc;
}

ProcPtr sub_8012014(int msgid)
{
    struct EventProc* proc = StartEventEngine(EventScr_085C46DC);
    proc->msgParam = msgid;

    return proc;
}

void sub_8012040(u16 item, ProcPtr parent)
{
    SetPopupItem(item);
    StartPopup(Popup_085C46FC, 0x60, 0, parent);
}

void sub_8012070(u16 item, ProcPtr parent)
{
    SetPopupItem(item);
    StartPopup(Popup_085C473C, 0x60, 0, parent);
}

void sub_80120A0(u16 item, ProcPtr parent)
{
    SetPopupItem(item);
    StartPopup(Popup_085C477C, 0x60, 0, parent);
}

void sub_80120D0(int amount, ProcPtr parent)
{
    SetPopupNumber(amount);

    if (UNIT_FACTION(gActiveUnit) == FACTION_BLUE)
        StartPopup(Popup_085C47A4, 0x60, 0, parent);
    else
        StartPopup(Popup_085C47DC, 0x60, 0, parent);
}

void sub_8012120(u16 item, ProcPtr parent)
{
    SetPopupItem(item);

    if (UNIT_FACTION(gActiveUnit) == FACTION_BLUE)
        StartPopup(Popup_085C4814, 0x60, 0, parent);
    else
        StartPopup(Popup_085C4854, 0x60, 0, parent);
}

void sub_8012178(u16 item, ProcPtr parent)
{
    SetPopupItem(item);

    if (UNIT_FACTION(gActiveUnit) == FACTION_BLUE)
        StartPopup(Popup_085C4894, 0x60, 0, parent);
    else
        StartPopup(Popup_085C48D4, 0x60, 0, parent);
}

void sub_80121D0(ProcPtr parent)
{
    StartPopup(Popup_085C4914, 0x60, 0, parent);
}

void sub_80121F4(struct Unit* unit, u16 iid, ProcPtr parent)
{
    struct GenericProc* proc;

    u32 intParent = (u32) parent;

    if (intParent < 8)
        proc = SpawnProc(ProcScr_Unk_085C4934, parent);
    else
        proc = SpawnProcLocking(ProcScr_Unk_085C4934, parent);

    proc->unk58 = iid;
    proc->ptr = unit;
}

void sub_8012244(struct GenericProc* proc)
{
    sub_8012120(proc->unk58, proc);
}

void sub_8012268(struct GenericProc* proc)
{
    sub_801C5B0(proc->ptr, sub_801650C(proc->unk58), proc);
}

static u32 CONST_DATA EventScr_085C4964[];

void sub_8012290(u16 iid)
{
    struct EventProc* proc = StartEventEngine(EventScr_085C4964);
    proc->iidParam = iid;
}

static u32 CONST_DATA EventScr_085C4978[];

void sub_80122CC(u16 pid, u16 iid)
{
    struct EventProc* proc = StartEventEngine(EventScr_085C4978);
    proc->pidParam = pid;
    proc->iidParam = iid;
}

static u32 CONST_DATA EventScr_085C4990[];

void sub_8012328(int amount)
{
    struct EventProc* proc = StartEventEngine(EventScr_085C4990);
    proc->moneyParam = amount;
}

static u32 CONST_DATA EventScr_085C49A4[];

void sub_801234C(u8 id)
{
    struct EventProc* proc = StartEventEngine(EventScr_085C49A4);
    proc->mapChangeParam = id;
}

static u32 CONST_DATA EventScr_085C49B4[];

void sub_8012388(u16 iid, u8 id)
{
    struct EventProc* proc = StartEventEngine(EventScr_085C49B4);
    proc->iidParam = iid;
    proc->mapChangeParam = id;
}

static u32 CONST_DATA EventScr_085C49D0[];

void sub_80123E4(int amount, u8 id)
{
    struct EventProc* proc = StartEventEngine(EventScr_085C49D0);
    proc->moneyParam = amount;
    proc->mapChangeParam = id;
}

void SetDialogueSkipEvbit(void)
{
    struct EventProc* proc = Proc_Find(ProcScr_Event);

    if (proc == NULL)
        return;

    proc->flags |= EVENT_FLAG_TEXTSKIPPED;
}

int sub_8012470(void)
{
    struct UnitInfo const* info = sub_806B638();

    int count = 0;

    while (info->pid != 0)
    {
        count++;
        info++;
    }

    return count;
}

void sub_80124A8(void)
{
    struct UnitInfo const* info = sub_806B638();

    FOR_UNITS_FACTION(FACTION_BLUE, unit,
    {
        if (unit->state & US_DEAD)
            continue;

        if (info->pid == 0)
        {
            unit->x = -1; // hide unit offmap
            continue;
        }

        if (unit->state & US_NOT_DEPLOYED)
            continue;

        unit->x = info->xMove;
        unit->y = info->yMove;

        info++;
    })
}

static void sub_8012628(struct Unit* unit);

void sub_8012564(void)
{
    FOR_UNITS_FACTION(FACTION_BLUE, unit,
    {
        if (unit->state & US_DEAD)
            continue;

        if (unit->state & US_NOT_DEPLOYED)
        {
            unit->x = -1;
            unit->state |= US_HIDDEN;

            continue;
        }

        unit->state &= ~US_HIDDEN;

        if (unit->x == -1)
            sub_8012628(unit);
    })
}

static void sub_8012628(struct Unit* unit)
{
    Bool spotOccupied;

    struct UnitInfo const* info = sub_806B638();

    while (info->pid != 0)
    {
        spotOccupied = FALSE;

        FOR_UNITS_FACTION(FACTION_BLUE, unit,
        {
            if (unit->state & (US_DEAD | US_NOT_DEPLOYED))
                continue;

            if (unit->x == info->xMove && unit->y == info->yMove)
            {
                spotOccupied = TRUE;
                break;
            }
        })

        if (!spotOccupied)
        {
            unit->x = info->xMove;
            unit->y = info->yMove;

            break;
        }

        info++;
    }
}

void sub_80126FC(int a, int b)
{
}

void sub_8012710(struct EventProc* proc)
{
    proc->unk45 = TRUE;
}

void sub_8012738(struct EventProc* proc)
{
    if (proc->flags & EVENT_FLAG_SKIPPED)
        return;

    proc->unk45 = FALSE;
}

void sub_8012770(void)
{
    sub_8028E80(WEATHER_NONE);
}

void sub_8012780(void)
{
    m4aMPlayFadeOut(&gMpi_030064F0, 3);
}

void sub_8012798(void)
{
    m4aMPlayFadeOutTemporarily(&gMpi_030062E0, 3);
}

void sub_80127B0(void)
{
    m4aMPlayFadeIn(&gMpi_030062E0, 2);
}

static struct EventCmdInfo CONST_DATA sEventCmdInfoTable[] =
{
    [EVT_CMD_END] = { Evt_End, 1 },
    [EVT_CMD_KILL] = { Evt_End2, 1 },
    [EVT_CMD_SLEEP] = { Evt_Sleep, 2 },
    [EVT_CMD_BACKGROUND] = { Evt_DisplayBackground, 2 },
    [EVT_CMD_BACKGROUNDMORE] = { Evt_DisplayBackgroundContinued, 2 },
    [EVT_CMD_CLEARTALK] = { Evt_ClearDialogue, 1 },
    [EVT_CMD_CLEARSKIP] = { Evt_FadeOutEnd, 1 },
    [EVT_CMD_TALK] = { Evt_Text, 2 },
    [EVT_CMD_TALKMORE] = { Evt_TextMore, 2 },
    [EVT_CMD_TALKAUTO] = { Evt_TextUnk, 1 },
    [EVT_CMD_TALKCONT] = { Evt_TextContinue, 1 },
    [EVT_CMD_CAMERA_POS] = { Evt_CameraPosition, 2 },
    [EVT_CMD_CAMERA_PID] = { Evt_CameraCharacter, 2 },
    [EVT_CMD_MOVE_POS] = { Evt_MovePosition, 3 },
    [EVT_CMD_MOVE_POS_MANUAL] = { Evt_MovePositionManual, 3 },
    [EVT_CMD_MOVE_PID] = { Evt_MoveCharacter, 3 },
    [EVT_CMD_MOVE_PID_MANUAL] = { Evt_MoveCharacterManual, 3 },
    [EVT_CMD_MOVE_PID_NEXTTO] = { Evt_MoveCharacterNextTo, 3 },
    [EVT_CMD_LOADUNITS] = { Evt_LoadUnits, 2 },
    [EVT_CMD_LOADUNITS_PARTY] = { Evt_LoadUnitsInstant, 2 },
    [EVT_CMD_MOVEWAIT] = { Evt_WaitForMovement, 1 },
    [EVT_CMD_UNITCAM_ON] = { Evt_CameraFollowsMovementOn, 1 },
    [EVT_CMD_UNITCAM_OFF] = { Evt_CameraFollowsMovementOff, 1 },
    [EVT_CMD_FUNC] = { Evt_AsmCall, 2 },
    [EVT_CMD_FUNC_UNTIL] = { Evt_AsmUntil, 2 },
    [EVT_CMD_FUNC_WHILE] = { Evt_AsmWhile, 2 },
    [EVT_CMD_STOP] = { Evt_Stop, 1 },
    [EVT_CMD_LABEL] = { Evt_Label, 2 },
    [EVT_CMD_GOTO] = { Evt_Goto, 2 },
    [EVT_CMD_GOTO_IFN_ALIVE] = { Evt_GotoIfnCharacterAlive, 3 },
    [EVT_CMD_GOTO_IFN_INTEAM] = { Evt_GotoIfnCharacterInTeam, 3 },
    [EVT_CMD_GOTO_IFY_FUNC] = { Evt_GotoIfAsm, 3 },
    [EVT_CMD_GOTO_IFN_FUNC] = { Evt_GotoIfnAsm, 3 },
    [EVT_CMD_GOTO_IFY_SKIPPED] = { Evt_GotoIfSkipping, 2 },
    [EVT_CMD_GOTO_IFY_FLAG] = { Evt_GotoIfEid, 3 },
    [EVT_CMD_GOTO_IFN_FLAG] = { Evt_GotoIfnEid, 3 },
    [EVT_CMD_GOTO_IFY_ACTIVE] = { Evt_GotoIfCharacterActive, 3 },
    [EVT_CMD_JUMP] = { Evt_Jump, 2 },
    [EVT_CMD_ITEM] = { Evt_GiveItemToActive, 2 },
    [EVT_CMD_ITEM_PID] = { Evt_GiveItemTo, 3 },
    [EVT_CMD_MONEY] = { Evt_GiveMoneyActive, 2 },
    [EVT_CMD_MAPCHANGE] = { Evt_MapChange, 2 },
    [EVT_CMD_MAPCHANGE_POS] = { Evt_MapChangePosition, 2 },
    [EVT_CMD_FACTION] = { Evt_ChangeFaction, 3 },
    [EVT_CMD_FLASHCURSOR_POS] = { Evt_FlashCursorPosition, 2 },
    [EVT_CMD_FLASHCURSOR_PID] = { Evt_FlashCursorCharacter, 2 },
    [EVT_CMD_CURSOR] = { Evt_DisplayCursor, 2 },
    [EVT_CMD_CLEARCURSOR] = { Evt_ClearCursor, 1 },
    [EVT_CMD_REMOVEUNIT] = { Evt_RemoveCharacter, 2 },
    [EVT_CMD_REMOVEUNIT_DISPLAYED] = { Evt_RemoveCharacterDisplayed, 2 },
    [EVT_CMD_SETAI_PID] = { Evt_ChangeAiCharacter, 3 },
    [EVT_CMD_SETAI_POS] = { Evt_ChangeAiPosition, 3 },
    [EVT_CMD_SETFLAG] = { Evt_SetEid, 2 },
    [EVT_CMD_CLEARFLAG] = { Evt_ClearEid, 2 },
    [EVT_CMD_BGM] = { Evt_Music, 2 },
    [EVT_CMD_BGM_OVERRIDE] = { Evt_MusicOverride, 2 },
    [EVT_CMD_BGM_RESTORE] = { Evt_MusicRestore, 1 },
    [EVT_CMD_BGM_FADEOUT] = { Evt_MusicFadeOut, 2 },
    [EVT_CMD_BGM_LOWER_ON] = { Evt_MusicVolumeLower, 1 },
    [EVT_CMD_BGM_LOWER_OFF] = { Evt_MusicVolumeRestore, 1 },
    [EVT_CMD_SE] = { Evt_PlaySound, 2 },
    [EVT_CMD_CHAPTER] = { Evt_GotoChapter, 2 },
    [EVT_CMD_GAMEEND] = { Evt_GameEnd, 1 },
    [EVT_CMD_SETMAP] = { Evt_LoadMap, 4 },
    [EVT_CMD_NOSKIP] = { Evt_NoSkip, 1 },
    [EVT_CMD_NOSKIP_NOTEXTSKIP] = { Evt_NoSkipNoTextSkip, 1 },
    [EVT_CMD_YESSKIP] = { Evt_YesSkip, 1 },
    [EVT_CMD_FADE_TOBLACK] = { Evt_FadeToDark, 2 },
    [EVT_CMD_FADE_FROMBLACK] = { Evt_FadeFromDark, 2 },
    [EVT_CMD_FADE_TOWHITE] = { Evt_FadeToWhite, 2 },
    [EVT_CMD_FADE_FROMWHITE] = { Evt_FadeFromWhite, 2 },
    [EVT_CMD_UNK47] = { Evt_HideMap, 1 },
    [EVT_CMD_UNK48] = { Evt_ShowMap, 1 },
    [EVT_CMD_FIGHTSCR] = { Evt_FightScripted, 5 },
    [EVT_CMD_NOCLEARTALK] = { sub_8010CD8, 1 },
    [EVT_CMD_FUNC_ONSKIP] = { Evt_SetOnSkipAsm, 2 },
    [EVT_CMD_WEATHER] = { Evt_SetWeather, 2 },
    [EVT_CMD_WM_START] = { Evt_WMStart, 2 },
    [EVT_CMD_WM_END] = { Evt_WMEnd, 1 },
    [EVT_CMD_WM_ZOOMTO] = { Evt_WMZoomTo, 2 },
    [EVT_CMD_WM_ZOOMBACK] = { Evt_WMZoomBack, 1 },
    [EVT_CMD_WM_PUTFACE] = { Evt_WMPutFace, 4 },
    [EVT_CMD_WM_REMOVEFACE] = { Evt_WMRemoveFace, 2 },
    [EVT_CMD_WM_MOVEFACE] = { Evt_WMMoveFace, 3 },
    [EVT_CMD_WM_NOP54] = { Evt_Nop54, 4 },
    [EVT_CMD_WM_NOP55] = { Evt_Nop55, 2 },
    [EVT_CMD_WM_TALK] = { Evt_WMText, 2 },
    [EVT_CMD_WM_TALKBOX_BOTTOM] = { Evt_WMTextBoxBottom, 1 },
    [EVT_CMD_WM_TALKBOX_TOP] = { Evt_WMTextBoxTop, 1 },
    [EVT_CMD_WM_TALKBOX_REMOVE] = { Evt_WMTextBoxRemove, 1 },
    [EVT_CMD_WM_ARROW] = { Evt_WMArrow, 2 },
    [EVT_CMD_WM_HIGHLIGHT] = { Evt_WMDisplayHighlight, 2 },
    [EVT_CMD_WM_HIGHLIGHT_REMOVE] = { Evt_WMRemoveHighlight, 2 },
    [EVT_CMD_WM_HIGHLIGHT_REMOVEBOTH] = { Evt_WMRemoveHighlights, 1 },
    [EVT_CMD_WM_DOT] = { Evt_WMDisplayDot, 4 },
    [EVT_CMD_WM_DOT_REMOVE] = { Evt_WMRemoveDot, 2 },
    [EVT_CMD_WM_FLAG] = { Evt_WMDisplayFlag, 4 },
    [EVT_CMD_WM_FLAG_REMOVE] = { Evt_WMRemoveFlag, 2 },
    [EVT_CMD_WM_MAPTEXT] = { Evt_WMDisplayMapText, 5 },
    [EVT_CMD_WM_MAPTEXT_REMOVE] = { Evt_WMRemoveMapText, 2 },
};

static struct BackgroundEnt CONST_DATA gBackgroundTable[] =
{
    [BACKGROUND_0] = { Img_Background_082E4650, Tsa_Background_082E6EB4, Pal_Background_082E7368 },
    [BACKGROUND_1] = { Img_Background_082E73E8, Tsa_Background_082EADF0, Pal_Background_082EB2A4 },
    [BACKGROUND_2] = { Img_Background_082EB324, Tsa_Background_082EDB7C, Pal_Background_082EE030 },
    [BACKGROUND_3] = { Img_Background_082EE0B0, Tsa_Background_082EF97C, Pal_Background_082EFE30 },
    [BACKGROUND_4] = { Img_Background_082EE0B0, Tsa_Background_082EF97C, Pal_Background_082EFEB0 },
    [BACKGROUND_5] = { Img_Background_082EFF30, Tsa_Background_082F1490, Pal_Background_082F1944 },
    [BACKGROUND_6] = { Img_Background_082F19C4, Tsa_Background_082F3494, Pal_Background_082F3948 },
    [BACKGROUND_7] = { Img_Background_082F39C8, Tsa_Background_082F62E0, Pal_Background_082F6794 },
    [BACKGROUND_8] = { Img_Background_082F6894, Tsa_Background_082F85E8, Pal_Background_082F8A9C },
    [BACKGROUND_9] = { Img_Background_082E4650, Tsa_Background_082E6EB4, Pal_Background_082E7368 },
    [BACKGROUND_10] = { Img_Background_082F8B1C, Tsa_Background_082FBE6C, Pal_Background_082FC320 },
    [BACKGROUND_11] = { Img_Background_082FC3A0, Tsa_Background_082FECE0, Pal_Background_082FF194 },
    [BACKGROUND_12] = { Img_Background_082F39C8, Tsa_Background_082F62E0, Pal_Background_082F6814 },
    [BACKGROUND_13] = { Img_Background_082FF214, Tsa_Background_08301244, Pal_Background_083016F8 },
    [BACKGROUND_14] = { Img_Background_082FF214, Tsa_Background_08301244, Pal_Background_08301778 },
    [BACKGROUND_15] = { Img_Background_082FF214, Tsa_Background_08301244, Pal_Background_083017F8 },
    [BACKGROUND_16] = { Img_Background_082D80B0, Tsa_Background_082DAC8C, Pal_Background_082DB140 },
    [BACKGROUND_17] = { Img_Background_08301878, Tsa_Background_0830491C, Pal_Background_08304DD0 },
    [BACKGROUND_18] = { Img_Background_08304E50, Tsa_Background_08306F24, Pal_Background_083073D8 },
    [BACKGROUND_19] = { Img_Background_082E28F8, Tsa_Background_082E35DC, Pal_Background_082E3A90 },
    [BACKGROUND_20] = { Img_Background_082E3B10, Tsa_Background_082E3EC0, Pal_Background_082E4374 },
};

struct ProcScr CONST_DATA ProcScr_Unk_085C4580[] =
{
    PROC_REPEAT(sub_800F0A4),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_085C4590[] =
{
    PROC_CALL(sub_800FFD4),
    PROC_REPEAT(sub_800FFEC),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_085C45A8[] =
{
    PROC_REPEAT(sub_8010104),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unused_085C45B8[] =
{
    PROC_CALL(sub_800D87C),
    PROC_REPEAT(sub_80149B0),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_WeatherChangeFade[] =
{
    PROC_SLEEP(0),

    PROC_CALL(sub_8014758),
    PROC_SLEEP(0),

    PROC_CALL(sub_8010D70),
    PROC_SLEEP(30),

    PROC_CALL(sub_8014768),
    PROC_SLEEP(0),

    PROC_END,
};

static struct FaceVramEnt CONST_DATA gWmEventFaceConfig[] =
{
    { CHR_SIZE * 0x200, 14 },
    { CHR_SIZE * 0x288, 15 },
    { CHR_SIZE * 0x200, 14 },
    { CHR_SIZE * 0x288, 15 },
};

struct ProcScr CONST_DATA ProcScr_WmEventShowFace[] =
{
    PROC_MARK(PROC_MARK_8),
    PROC_SLEEP(0),

    PROC_CALL(sub_801105C),
    PROC_REPEAT(sub_80111A8),

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_WmEventHideFace[] =
{
    PROC_MARK(PROC_MARK_8),
    PROC_SET_END_FUNC(sub_801154C),
    PROC_SLEEP(0),

    PROC_CALL(sub_8011330),
    PROC_REPEAT(sub_801147C),

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_WmEventMoveFace[] =
{
    PROC_MARK(PROC_MARK_8),
    PROC_SLEEP(0),

    PROC_CALL(sub_8011638),
    PROC_REPEAT(sub_80116A8),

    PROC_END,
};

static struct FaceVramEnt CONST_DATA gFightEventFaceConfig[] =
{
    { CHR_SIZE * 0x40, 3 },
    { CHR_SIZE * 0x40, 3 },
    { CHR_SIZE * 0x40, 3 },
    { CHR_SIZE * 0x40, 3 },
};

u32 CONST_DATA EventScr_AutoTalk[] =
{
    EvtTalkAuto

    EvtClearSkip
    EvtEnd
};

u32 CONST_DATA EventScr_085C46DC[] =
{
    EvtTalkAuto

    EvtClearTalk

    EvtFunc(sub_80121D0)
    EvtSleep(1)

    EvtClearSkip
    EvtEnd
};

struct PopupInfo CONST_DATA Popup_085C46FC[] =
{
    POPUP_SONG(0x5C), // TODO: song ids

    POPUP_COLOR(TEXT_COLOR_0789),
    POPUP_ICON_ITEM,
    POPUP_ITEM_NAME,
    POPUP_SPACE(3),

    POPUP_COLOR(TEXT_COLOR_0123),
    POPUP_MSG(0xC72), // TODO: msgids

    POPUP_END,
};

struct PopupInfo CONST_DATA Popup_085C473C[] =
{
    POPUP_SONG(0x5C), // TODO: song ids

    POPUP_COLOR(TEXT_COLOR_0789),
    POPUP_ICON_ITEM,
    POPUP_ITEM_NAME,
    POPUP_SPACE(3),

    POPUP_COLOR(TEXT_COLOR_0123),
    POPUP_MSG(0xC73), // TODO: msgids

    POPUP_END,
};

struct PopupInfo CONST_DATA Popup_085C477C[] =
{
    POPUP_SONG(0x5A), // TODO: song ids

    POPUP_MSG(0xC70), // TODO: msgids
    POPUP_ICON_IKIND,
    POPUP_MSG(0xC71), // TODO: msgids

    POPUP_END,
};

struct PopupInfo CONST_DATA Popup_085C47A4[] =
{
    POPUP_SONG(0x5A), // TODO: song ids

    POPUP_COLOR(TEXT_COLOR_0789),
    POPUP_NUMBER,
    POPUP_SPACE(3),

    POPUP_COLOR(TEXT_COLOR_0123),
    POPUP_MSG(0xC74), // TODO: msgids

    POPUP_END,
};

struct PopupInfo CONST_DATA Popup_085C47DC[] =
{
    POPUP_SONG(0x5C), // TODO: song ids

    POPUP_COLOR(TEXT_COLOR_0789),
    POPUP_NUMBER,
    POPUP_SPACE(3),

    POPUP_COLOR(TEXT_COLOR_0123),
    POPUP_MSG(0xC77), // TODO: msgids

    POPUP_END,
};

struct PopupInfo CONST_DATA Popup_085C4814[] =
{
    POPUP_SONG(0x5A), // TODO: song ids

    POPUP_COLOR(TEXT_COLOR_0789),
    POPUP_ICON_ITEM,
    POPUP_ITEM_NAME,
    POPUP_SPACE(3),

    POPUP_COLOR(TEXT_COLOR_0123),
    POPUP_MSG(0xC75), // TODO: msgids

    POPUP_END,
};

struct PopupInfo CONST_DATA Popup_085C4854[] =
{
    POPUP_SONG(0x5C), // TODO: song ids

    POPUP_COLOR(TEXT_COLOR_0789),
    POPUP_ICON_ITEM,
    POPUP_ITEM_NAME,
    POPUP_SPACE(3),

    POPUP_COLOR(TEXT_COLOR_0123),
    POPUP_MSG(0xC78), // TODO: msgids

    POPUP_END,
};

struct PopupInfo CONST_DATA Popup_085C4894[] =
{
    POPUP_SONG(0x5A), // TODO: song ids

    POPUP_COLOR(TEXT_COLOR_0789),
    POPUP_ICON_ITEM,
    POPUP_ITEM_NAME,
    POPUP_SPACE(3),

    POPUP_COLOR(TEXT_COLOR_0123),
    POPUP_MSG(0xC76), // TODO: msgids

    POPUP_END,
};

struct PopupInfo CONST_DATA Popup_085C48D4[] =
{
    POPUP_SONG(0x5C), // TODO: song ids

    POPUP_COLOR(TEXT_COLOR_0789),
    POPUP_ICON_ITEM,
    POPUP_ITEM_NAME,
    POPUP_SPACE(3),

    POPUP_COLOR(TEXT_COLOR_0123),
    POPUP_MSG(0xC79), // TODO: msgids

    POPUP_END,
};

struct PopupInfo CONST_DATA Popup_085C4914[] =
{
    POPUP_SONG(0x5A), // TODO: song ids

    POPUP_COLOR(TEXT_COLOR_0123),
    POPUP_MSG(0xC7A), // TODO: msgids

    POPUP_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_085C4934[] =
{
    PROC_SLEEP(0),

    PROC_CALL(sub_8012244),
    PROC_SLEEP(0),

    PROC_CALL(sub_8012268),
    PROC_SLEEP(0),

    PROC_END,
};

u32 CONST_DATA EventScr_085C4964[] =
{
    EvtNoSkip
    EvtGiveItem(0)

    EvtClearSkip
    EvtEnd
};

u32 CONST_DATA EventScr_085C4978[] =
{
    EvtNoSkip
    EvtGiveItemTo(0, 0)

    EvtClearSkip
    EvtEnd
};

u32 CONST_DATA EventScr_085C4990[] =
{
    EvtNoSkip
    EvtGiveMoney(0)

    EvtClearSkip
    EvtEnd
};

u32 CONST_DATA EventScr_085C49A4[] =
{
    EvtMapChange(-1)

    EvtClearSkip
    EvtEnd
};

u32 CONST_DATA EventScr_085C49B4[] =
{
    EvtMapChange(-1)

    EvtNoSkip
    EvtGiveItem(0)

    EvtClearSkip
    EvtEnd
};

u32 CONST_DATA EventScr_085C49D0[] =
{
    EvtMapChange(-1)

    EvtNoSkip
    EvtGiveMoney(0)

    EvtClearSkip
    EvtEnd
};
