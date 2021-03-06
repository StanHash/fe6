
#include "mu.h"

#include "oam.h"
#include "sound.h"
#include "anim.h"
#include "util.h"
#include "unit.h"
#include "map.h"
#include "unitsprite.h"
#include "faction.h"
#include "chapter.h"
#include "battle.h"

#include "constants/video-global.h"
#include "constants/jids.h"

enum { MU_COUNT = 4 };

// TODO: this is part of GenericProc?
struct MuFogBumpProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ int x, y;
    /* 34 */ u8 pad_34[0x50 - 0x34];
    /* 50 */ struct Anim* anim;
    /* 54 */ u8 pad_54[0x64 - 0x54];
    /* 64 */ short clock;
};

struct MuFadeProc
{
    /* 00 */ PROC_HEADER;
    /* 2C */ struct MuProc* mu;
    /* 30 */ u8 clock;
};

u16 const* CONST_DATA gMuFlashPalLut[] =
{
    [MU_FLASH_WHITE] = Pal_AllWhite,
    [MU_FLASH_BLACK] = Pal_AllBlack,
    [MU_FLASH_RED]   = Pal_AllRed,
    [MU_FLASH_GREEN] = Pal_AllGreen,
    [MU_FLASH_BLUE]  = Pal_AllBlue,
    [MU_FLASH_5]     = Pal_085C4F2C,
};

static void MuStepSe_Init(struct GenericProc* proc);
static void MuStepSe_PlaySeA(struct GenericProc* proc);
static void MuStepSe_PlaySeB(struct GenericProc* proc);

struct ProcScr CONST_DATA ProcScr_MuStepSe[] =
{
    PROC_CALL(MuStepSe_Init),
    PROC_SLEEP(0),

    PROC_CALL(MuStepSe_PlaySeA),
    PROC_SLEEP(0),

    PROC_CALL(MuStepSe_PlaySeB),

    PROC_END,
};

static void MuFogBump_Init(struct MuFogBumpProc* proc);
static void MuFogBump_ScaleLoop(struct MuFogBumpProc* proc);
static void MuFogBump_EndLoop(struct MuFogBumpProc* proc);

struct ProcScr CONST_DATA ProcScr_MuFogBump[] =
{
    PROC_CALL(MuFogBump_Init),

    PROC_REPEAT(MuFogBump_ScaleLoop),
    PROC_REPEAT(MuFogBump_EndLoop),

    PROC_END,
};

static short CONST_DATA sMoveOffsetLut[4*2] =
{
    -1,  0, // left
    +1,  0, // right
     0, +1, // up
     0, -1, // down
};

// TODO: song ids
// TODO: move mu sound scripts to own data file?

u16 CONST_DATA MuSoundScr_Foot[] =
{
    0x10, 2,
    0x96, 0, 0, 0, 0, 0, 0, 0,
    0x97, 0, 0, 0, 0, 0, 0, 0,
};

u16 CONST_DATA MuSoundScr_FootHeavy[] =
{
    0x20, 2,
    0xA4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0xA5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

u16 CONST_DATA MuSoundScr_Mounted[] =
{
    0x15, 3,
    0x9A, 0, 0,
    0x9B, 0, 0, 0, 0, 0, 0,
    0x9C, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

u16 CONST_DATA MuSoundScr_Wyvern[] =
{
    0x14, 1,
    0xA0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

u16 CONST_DATA MuSoundScr_Pegasus[] =
{
    0x14, 1,
    0xA6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

typedef void(*MuStateFunc)(struct MuProc* mu);

static void Mu_OnStateNone(struct MuProc* mu);
static void Mu_OnStateDoNothing(struct MuProc* mu);
static void Mu_OnStateMovement(struct MuProc* mu);
static void Mu_OnStateSleeping(struct MuProc* mu);
static void Mu_OnState_08060460(struct MuProc* mu);
static void Mu_OnStateBump(struct MuProc* mu);

static MuStateFunc CONST_DATA sMuStateFuncs[] =
{
    [MU_STATE_NONE]       = Mu_OnStateNone,
    [MU_STATE_INACTIVE]   = Mu_OnStateDoNothing,
    [MU_STATE_MOVEMENT]   = Mu_OnStateMovement,
    [MU_STATE_SLEEPING]   = Mu_OnStateSleeping,
    [MU_STATE_UNK4]       = Mu_OnState_08060460,
    [MU_STATE_BUMPING]    = Mu_OnStateBump,
    [MU_STATE_DISPLAY_UI] = Mu_OnStateDoNothing,
    [MU_STATE_DEATHFADE]  = Mu_OnStateDoNothing,
};

static void Mu_OnLoop(struct MuProc* mu);
static void Mu_OnEnd(struct MuProc* mu);

struct ProcScr CONST_DATA ProcScr_Mu[] =
{
    PROC_19,
    PROC_MARK(PROC_MARK_MU),
    PROC_ONEND(Mu_OnEnd),

    PROC_REPEAT(Mu_OnLoop),
};

static u16 CONST_DATA sMuChrOffLut[MU_COUNT] =
{
    0x00, 0x10, 0x08, 0x18,
};

static u8 CONST_DATA sMuWalkSpeedLut[] =
{
    2, 1,
};

static u8 CONST_DATA sMuImgBufOffLut[] =
{
    0, // dummy because active ids start at 1
    0, 2, 1, 3,
};

static void MuDeathFade_OnLoop(struct GenericProc* proc);

struct ProcScr CONST_DATA ProcScr_MuDeathFade[] =
{
    PROC_REPEAT(MuDeathFade_OnLoop),
    PROC_SLEEP(15),
    PROC_END,
};

static void MuRestorePalInfo_Apply(struct GenericProc* proc);

struct ProcScr CONST_DATA ProcScr_MuRestorePalInfo[] =
{
    PROC_SLEEP(8),
    PROC_CALL(MuRestorePalInfo_Apply),
    PROC_END,
};

static void sub_8061474(struct MuFadeProc* proc);
static void sub_8061494(struct MuFadeProc* proc);
static void sub_80614C8(struct MuFadeProc* proc);
static void sub_8061518(struct MuFadeProc* proc);
static void sub_8061554(struct MuFadeProc* proc);
static void sub_80615D4(struct MuFadeProc* proc);

struct ProcScr CONST_DATA ProcScr_Unk_08664914[] =
{
    PROC_CALL(sub_8061474),
    PROC_SLEEP(1),

    PROC_CALL(sub_8061494),
    PROC_SLEEP(2),

    PROC_CALL(sub_80614C8),
    PROC_SLEEP(3),

    PROC_CALL(sub_8061494),
    PROC_SLEEP(2),

    PROC_CALL(sub_80614C8),
    PROC_SLEEP(3),

    PROC_CALL(sub_8061494),
    PROC_SLEEP(1),

    PROC_CALL(sub_8061518),
    PROC_REPEAT(sub_8061554),

    PROC_SLEEP(17),

    PROC_CALL(sub_80615D4),

    PROC_END,
};

static void MuFlashFadeFrom_RestorePal(struct MuFadeProc* proc);

struct ProcScr CONST_DATA ProcScr_MuFlashFadeFrom[] =
{
    PROC_SLEEP(17),
    PROC_CALL(MuFlashFadeFrom_RestorePal),

    PROC_END,
};

static struct MuConfig sMuConfig[MU_COUNT];

extern u8 gMuImgBuf[4 * 0x110 * CHR_SIZE]; // OVERLAY

void InitMus(void)
{
    int i;

    for (i = 0; i < MU_COUNT; ++i)
    {
        sMuConfig[i].id = 0;
    }
}

struct MuProc* StartMuExt(int x, int y, int jid, int pal)
{
    struct MuProc* mu;

    mu = StartMuInternal(x, y, jid, pal);
    mu->boolCam = TRUE;

    return mu;
}

struct MuProc* StartMu(struct Unit* unit)
{
    struct MuProc* mu;

    mu = StartMuInternal(unit->x, unit->y, unit->job->id, GetUnitSpritePalette(unit));

    mu->unit = unit;
    mu->boolCam = TRUE;

    return mu;
}

void UpdateMu(struct MuProc* mu)
{
    Mu_OnLoop(mu);
}

void EnableMuCamera(struct MuProc* mu)
{
    mu->boolCam = TRUE;
}

void DisableMuCamera(struct MuProc* mu)
{
    mu->boolCam = FALSE;
}

struct MuProc* StartUiMu(struct Unit* unit, int x, int y)
{
    struct MuProc* mu;

    mu = StartMu(unit);

    if (mu == NULL)
        return NULL;

    mu->q4_x = x << 4;
    mu->q4_y = y << 4;
    mu->state = MU_STATE_DISPLAY_UI;

    return mu;
}

struct MuProc* StartMuInternal(u16 x, u16 y, u16 jid, int pal)
{
    struct MuProc* mu;
    struct Anim* anim;
    struct MuConfig* config;

    u16 soundDelay = 0;

    config = GetNewMuConfig();

    if (config == NULL)
        return NULL;

    if (Proc_Find(ProcScr_Mu))
        soundDelay = 254;

    mu = SpawnProc(ProcScr_Mu, PROC_TREE_5);

    if (mu == NULL)
        return NULL;

    mu->unit = NULL;
    mu->state = MU_STATE_INACTIVE;

    mu->q4_x = (x * 16) << 4;
    mu->q4_y = (y * 16) << 4;

    mu->q4_xOffset = 0;
    mu->q4_yOffset = 0;

    mu->facing = 11;

    mu->q4_moveClock = 0;
    mu->stepSoundClock = soundDelay;

    mu->jid = jid;

    mu->boolHidden = FALSE;

    mu->moveConfig = 0;
    mu->boolFastWalk = FALSE;

    config->pal = pal;

    anim = StartAnim(GetMuAnimForJid(jid), 10);
    Anim_SetAnimId(anim, 4);

    Decompress(GetMuImg(mu), GetMuImgBufById(config->id));

    anim->img = GetMuImgBufById(config->id);
    anim->oam2 = config->chr + OAM2_PAL(config->pal) + OAM2_LAYER(2);

    mu->anim = anim;
    mu->config = config;
    mu->config->mu = mu;

    return mu;
}

void SetMuFacing(struct MuProc* mu, int facing)
{
    mu->facing = facing;
    Anim_SetAnimId(mu->anim, mu->facing);
}

void SetMuDefaultFacing(struct MuProc* mu)
{
    if (GetJobInfo(mu->jid)->attributes & UNIT_ATTR_MOUNTED)
        SetMuFacing(mu, 1);
    else
        SetMuFacing(mu, 2);
}

void SetAutoMuDefaultFacing(void)
{
    struct MuProc* mu = Proc_Find(ProcScr_Mu);

    if (mu == NULL)
        return;

    SetMuDefaultFacing(mu);
}

void SetAutoMuMoveScript(u8 const* movescr)
{
    struct MuProc* mu = Proc_Find(ProcScr_Mu);

    if (mu == NULL)
        return;

    SetMuMoveScript(mu, movescr);
}

bool MuExists(void)
{
    return Proc_Find(ProcScr_Mu) != NULL ? TRUE : FALSE;
}

bool MuExistsActive(void)
{
    struct MuProc* mu;
    int i;

    for (i = 0; i < MU_COUNT; ++i)
    {
        if (sMuConfig[i].id != 0)
        {
            mu = sMuConfig[i].mu;

            switch (mu->state)
            {

            case MU_STATE_INACTIVE:
                continue;

            default:
                return TRUE;

            }
        }
    }

    if (i >= MU_COUNT)
        return FALSE;

    return TRUE;
}

bool IsMuActive(struct MuProc* mu)
{
    if (mu->config->id == 0)
        return FALSE;

    switch (mu->state)
    {

    case MU_STATE_INACTIVE:
        return FALSE;

    default:
        return TRUE;

    }

    return FALSE;
}

void SetMuMoveScript(struct MuProc* mu, u8 const* movescr)
{
    int i;

    for (i = 0; i < 0x40; ++i)
        mu->config->movescr[i] = movescr[i];

    mu->config->pc = 0;
    mu->state = MU_STATE_MOVEMENT;

    PlayMuStepSe(mu);
}

struct MuProc* StartMuScripted(u16 x, u16 y, u16 jid, int pal, u8 const* movescr)
{
    struct MuProc* mu;

    mu = StartMuInternal(x, y, jid, pal);

    if (mu == NULL)
        return NULL;

    SetMuMoveScript(mu, movescr);

    return mu;
}

void MuStepSe_Init(struct GenericProc* proc)
{
    proc->unk58 = 0;
    proc->unk64 = 0;

    proc->unk5C = 0;
    proc->unk66 = 0;
}

void MuStepSe_PlaySeA(struct GenericProc* proc)
{
    PlaySeSpacial(proc->unk58, proc->unk64);
}

void MuStepSe_PlaySeB(struct GenericProc* proc)
{
    if (proc->unk5C != 0)
        PlaySeSpacial(proc->unk5C, proc->unk66);
}

void StartPlayMuStepSe(int song, int altOff, int x)
{
    struct GenericProc* proc;

    proc = Proc_Find(ProcScr_MuStepSe);

    if (proc == NULL)
        proc = SpawnProc(ProcScr_MuStepSe, PROC_TREE_3);

    if (proc->unk58 == 0)
    {
        proc->unk58 = song;
        proc->unk64 = x;
    }
#if BUGFIX
    else if (proc->unk5C == 0)
#else
    else if (proc->unk60 == 0)
#endif
    {
        proc->unk5C = song + altOff;
        proc->unk66 = x;
    }
}

void PlayMuStepSe(struct MuProc* mu)
{
    UpdateMuStepSounds(mu);
}

void EndMuMovement(struct MuProc* mu)
{
}

void RunMuMoveScript(struct MuProc* mu)
{
    while (TRUE)
    {
        short cmd = mu->config->movescr[mu->config->pc++];

        switch (cmd)
        {

        case MOVE_CMD_SLEEP:
            mu->q4_moveClock = mu->config->movescr[mu->config->pc++];
            mu->state = MU_STATE_SLEEPING;

            return;

        case MOVE_CMD_BUMP:
            EndMuMovement(mu);

            mu->state = MU_STATE_BUMPING;

            StartMuFogBump(
                (mu->q4_x >> 4) - gBmSt.camera.x,
                (mu->q4_y >> 4) - gBmSt.camera.y);

            return;

        case MOVE_CMD_HALT:
            HaltMu(mu);

            return;

        case MOVE_CMD_END:
            EndMuMovement(mu);
            EndMu(mu);

            return;

        case MOVE_CMD_MOVE_LEFT:
        case MOVE_CMD_MOVE_RIGHT:
        case MOVE_CMD_MOVE_DOWN:
        case MOVE_CMD_MOVE_UP:
            if ((cmd - MOVE_CMD_MOVE_BASE) != mu->facing)
            {
#if !BUGFIX
                u16 const* _ = GetMuAnimForJid(mu->jid);
#endif
                SetMuFacing(mu, cmd - MOVE_CMD_MOVE_BASE);
                mu->state = MU_STATE_MOVEMENT;
            }

            return;

        case MOVE_CMD_FACE_LEFT:
        case MOVE_CMD_FACE_RIGHT:
        case MOVE_CMD_FACE_DOWN:
        case MOVE_CMD_FACE_UP:
            cmd = cmd - MOVE_CMD_FACE_BASE;

            if (cmd != mu->facing)
            {
#if !BUGFIX
                u16 const* _ = GetMuAnimForJid(mu->jid);
#endif
                SetMuFacing(mu, cmd);
            }

            continue;

        case MOVE_CMD_SET_SPEED:
            mu->moveConfig = mu->config->movescr[mu->config->pc++];
            continue;

        case MOVE_CMD_CAMERA_ON:
            EnableMuCamera(mu);
            continue;

        case MOVE_CMD_CAMERA_OFF:
            DisableMuCamera(mu);
            continue;

        default:
            break;

        }
    }
}

void StartMuFogBump(int x, int y)
{
    struct MuFogBumpProc* proc;
    struct Anim* anim;

    Decompress(Img_MuFogBump, OBJ_VRAM0 + OBJCHR_MU_180 * CHR_SIZE);

    anim = StartAnim(Anim_MuFogBump, 2);
    anim->oam2 = OAM2_CHR(OBJCHR_MU_180) + OAM2_PAL(OBJPAL_1);

    Anim_SetAnimId(anim, 0);

    proc = SpawnProc(ProcScr_MuFogBump, PROC_TREE_3);

    proc->anim = anim;

    proc->x = x + 8;
    proc->y = y - 4;
}

void MuFogBump_Init(struct MuFogBumpProc* proc)
{
    PlaySe(0x77); // TODO: song ids
    proc->clock = 0;
    SetObjAffineAuto(0, 0, 0x200, 0x200);
}

void MuFogBump_ScaleLoop(struct MuFogBumpProc* proc)
{
    int scale;

    if (proc->clock++ >= 8)
        Proc_Break(proc);

    scale = Interpolate(INTERPOLATE_RCUBIC, 0x200, 0x100, proc->clock, 8);
    SetObjAffineAuto(0, 0, scale, scale);

    Anim_Display(proc->anim,
        (proc->x - 8),
        (proc->y - 8) | OAM0_AFFINE_ENABLE | OAM0_DOUBLESIZE);
}

void MuFogBump_EndLoop(struct MuFogBumpProc* proc)
{
    if (proc->clock++ >= 40)
        Proc_Break(proc);

    Anim_Display(proc->anim,
        (proc->x),
        (proc->y) | OAM0_AFFINE_ENABLE);
}

bool IsMuFogBumpActive(void)
{
    return Proc_Find(ProcScr_MuFogBump) ? TRUE : FALSE;
}

void Mu_OnStateBump(struct MuProc* mu)
{
    if (!IsMuFogBumpActive())
        mu->state = MU_STATE_SLEEPING;
}

void Mu_OnState_08060460(struct MuProc* mu)
{
    mu->state = MU_STATE_MOVEMENT;
}

void Mu_OnStateSleeping(struct MuProc* mu)
{
    if (mu->q4_moveClock == 0)
    {
        mu->state = MU_STATE_MOVEMENT;
        return;
    }

    mu->q4_moveClock--;
}

void Mu_OnStateNone(struct MuProc* mu)
{
}

void Mu_OnStateDoNothing(struct MuProc* mu)
{
}

void Mu_OnStateMovement(struct MuProc* mu)
{
    int q4_moveSpeed = GetMuQ4MovementSpeed(mu);

    mu->q4_moveClock += q4_moveSpeed;

    mu->q4_x += q4_moveSpeed * sMoveOffsetLut[mu->facing*2+0];
    mu->q4_y += q4_moveSpeed * sMoveOffsetLut[mu->facing*2+1];

    if ((mu->q4_moveClock >> 4) >= 16)
    {
        mu->q4_moveClock -= 16 << 4;

        mu->q4_x -= mu->q4_moveClock * sMoveOffsetLut[mu->facing*2+0];
        mu->q4_y -= mu->q4_moveClock * sMoveOffsetLut[mu->facing*2+1];

        mu->q4_moveClock = 0;

        mu->q4_x &= ~0xF;
        mu->q4_y &= ~0xF;
    }

    if (mu->boolCam)
    {
        gBmSt.camera.x = GetCameraAdjustedX(mu->q4_x >> 4);
        gBmSt.camera.y = GetCameraAdjustedY(mu->q4_y >> 4);
    }

    UpdateMuStepSounds(mu);
}

void UpdateMuStepSounds(struct MuProc* mu)
{
    struct JobInfo const* jinfo = GetJobInfo(mu->jid);

    u16 const* soundScript;
    int pc;
    struct Vec2 pos;

    if (jinfo->attributes & UNIT_ATTR_MOUNTED)
    {
        // Mounted jobs

        switch (mu->jid)
        {

        case JID_PEGASUSKNIGHT:
        case JID_FALCOKNIGHT:
            soundScript = MuSoundScr_Pegasus;
            break;

        case JID_WYVERNRIDER:
        case JID_WYVERNRIDER_F:
        case JID_WYVERNLORD:
        case JID_WYVERNLORD_F:
            soundScript = MuSoundScr_Wyvern;
            break;

        default:
            soundScript = MuSoundScr_Mounted;
            break;

        }
    }
    else
    {
        // Grounded jobs

        switch (mu->jid)
        {

        case JID_ARMOR:
        case JID_ARMOR_F:
        case JID_GENERAL:
        case JID_GENERAL_F:
        case JID_DEMONDRAGON:
        case JID_KING:
            soundScript = MuSoundScr_FootHeavy;
            break;

        default:
            soundScript = MuSoundScr_Foot;
            break;

        }
    }

    pc = DivRem(mu->stepSoundClock++, soundScript[0]);
    GetMuDisplayPosition(mu, &pos);

    if (soundScript[2 + pc] != 0)
    {
        StartPlayMuStepSe(soundScript[2 + pc], soundScript[1], pos.x);
    }
}

void Mu_OnLoop(struct MuProc* mu)
{
    if (mu->state != MU_STATE_NONE)
    {
        if (mu->q4_moveClock == 0)
        {
            if (mu->state == MU_STATE_SLEEPING || mu->state == MU_STATE_MOVEMENT)
                RunMuMoveScript(mu);
        }

        sMuStateFuncs[mu->state](mu);
    }

    PutMu(mu);
}

void Mu_OnEnd(struct MuProc* mu)
{
    mu->config->id = 0;
    Anim_End(mu->anim);
}

void EndAllMus(void)
{
    Proc_EndEach(ProcScr_Mu);
}

static void sub_8060904(struct MuProc* mu);

void EndMu(struct MuProc* mu)
{
    sub_8060904(mu);
}

static void sub_8060904(struct MuProc* mu)
{
    Proc_End(mu);
}

void HaltMu(struct MuProc* mu)
{
    EndMuMovement(mu);
    mu->state = MU_STATE_INACTIVE;
}

void LockMus(void)
{
    Proc_LockEachMarked(PROC_MARK_MU);
}

void ReleaseMus(void)
{
    Proc_ReleaseEachMarked(PROC_MARK_MU);
}

void ApplyMoveScriptToCoordinates(int* x, int* y, u8 const* movescr)
{
    while (TRUE)
    {
        switch (*movescr++)
        {

        case MOVE_CMD_END:
        case MOVE_CMD_HALT:
            return;

        case MOVE_CMD_MOVE_LEFT:
            (*x)--;
            break;

        case MOVE_CMD_MOVE_RIGHT:
            (*x)++;
            break;

        case MOVE_CMD_MOVE_UP:
            (*y)--;
            break;

        case MOVE_CMD_MOVE_DOWN:
            (*y)++;
            break;

        case MOVE_CMD_SLEEP:
            movescr++;
            break;

        default:
            break;

        }
    }
}

bool CanStartMu(void)
{
    int i;

    for (i = 0; i < MU_COUNT; ++i)
    {
        if (sMuConfig[i].id == 0)
            return TRUE;
    }

    return FALSE;
}

void ResetMuAnims(void)
{
    int i;

    for (i = 0; i < MU_COUNT; ++i)
    {
        if (sMuConfig[i].id != 0)
        {
            Anim_ResetClock(sMuConfig[i].mu->anim);
        }
    }
}

struct MuConfig* GetNewMuConfig(void)
{
    int i;

    for (i = 0; i < MU_COUNT; ++i)
    {
        if (sMuConfig[i].id == 0)
        {
            sMuConfig[i].id = i + 1;
            sMuConfig[i].chr = OBJCHR_MU_BASE + sMuChrOffLut[i];

            return sMuConfig + i;
        }
    }

    return NULL;
}

bool GetMuDisplayPosition(struct MuProc* mu, struct Vec2* out)
{
    short x, y;

    switch (mu->state)
    {

    case MU_STATE_DISPLAY_UI:
        out->x = (mu->q4_x + mu->q4_xOffset) >> 4;
        out->y = (mu->q4_y + mu->q4_yOffset) >> 4;

        return TRUE;

    default:
        x = ((mu->q4_x + mu->q4_xOffset) >> 4) - gBmSt.camera.x + 8;
        y = ((mu->q4_y + mu->q4_yOffset) >> 4) - gBmSt.camera.y + 8;

        out->x = x;
        out->y = y + 8;

        if (x < -0x10 || x > 0x100 || y < -0x10 || y > 0xB0)
            return FALSE;

        return TRUE;

    }
}

void PutMu(struct MuProc* mu)
{
    struct Vec2 pos;

    if (mu->boolHidden)
        return;

    if (!GetMuDisplayPosition(mu, &pos))
        return;

    pos.x = OAM1_X(pos.x);
    pos.y = OAM0_Y(pos.y);

    switch (mu->state)
    {

    case MU_STATE_DISPLAY_UI:
        break;

    default:
        if (mu->unit == NULL || UNIT_FACTION(mu->unit) == FACTION_BLUE)
            break;

        // ew
        if (gMapFog[Div(((mu->q4_y + mu->q4_yOffset) >> 4) + 8, 16)][Div(((mu->q4_x + mu->q4_xOffset) >> 4) + 8, 16)] == 0)
            return;

    }

    if (mu->state == MU_STATE_DEATHFADE)
        pos.y |= OAM0_BLEND;

    Anim_Display(mu->anim, pos.x, pos.y);
}

u16 GetMuQ4MovementSpeed(struct MuProc* mu)
{
    if (mu->moveConfig != 0)
        return mu->moveConfig;

    if (mu->boolFastWalk)
        return 16 << 4;

    if (!IsFirstPlaythrough() && (gKeySt->held & KEY_BUTTON_A))
        return 8 << 4;

    if (gPlaySt.configWalkSpeed == 0)
    {
        return sMuWalkSpeedLut[GetJobInfo(mu->jid)->walkSpeed] << 4;
    }
    else
    {
        return 4 << 4;
    }
}

u8* GetMuImgBufById(int id)
{
    return gMuImgBuf + sMuImgBufOffLut[id] * 0x110 * CHR_SIZE;
}

u8 const* GetMuImg(struct MuProc* mu)
{
    return MuInfoTable[mu->jid - 1].img;
}

u16 const* GetMuAnimForJid(u16 jid)
{
    return MuInfoTable[jid - 1].anim;
}

void StartMuDeathFade(struct MuProc* mu)
{
    struct GenericProc* proc;

    mu->state = MU_STATE_DEATHFADE;

    proc = SpawnProc(ProcScr_MuDeathFade, mu);

    proc->ptr = mu;
    proc->unk64 = 0x20;

    SetBlendConfig(0, proc->unk64 >> 1, 0x10, 0);

    Anim_Freeze(mu->anim);

    StartMuFlashFadeFrom(mu, MU_FLASH_WHITE);

    mu->anim->layer = 13;

    PlaySe(0xD6); // TODO: song ids
}

void MuDeathFade_OnLoop(struct GenericProc* proc)
{
    SetBlendConfig(0, (proc->unk64--) >> 1, 0x10, 0);

    if (proc->unk64 == 0)
    {
        EndMu(proc->ptr);
        Proc_Break(proc);
    }
}

void HideMu(struct MuProc* mu)
{
    mu->boolHidden = TRUE;
}

void ShowMu(struct MuProc* mu)
{
    mu->boolHidden = FALSE;
}

void SetMuScreenPosition(struct MuProc* mu, int x, int y)
{
    mu->q4_x = x << 4;
    mu->q4_y = y << 4;
}

void SetMuScreenOffset(struct MuProc* mu, int xOff, int yOff)
{
    mu->q4_xOffset = xOff << 4;
    mu->q4_yOffset = yOff << 4;
}

void StartMuFadeIntoFlash(struct MuProc* mu, int flash)
{
    mu->anim->oam2 = mu->config->chr + OAM2_PAL(OBJPAL_MU_FADE) + OAM2_LAYER(2);

    ApplyPalette(gPal + ((0x20 * (0x10 + mu->config->pal)) >> 1), 0x10 + OBJPAL_MU_FADE);
    StartPalFade(gMuFlashPalLut[flash], 0x10 + OBJPAL_MU_FADE, 8, mu);
}

void StartMuFadeFromFlash(struct MuProc* mu)
{
    struct GenericProc* proc;

    StartPalFade(gPal + ((0x20 * (0x10 + mu->config->pal)) >> 1), 0x10 + OBJPAL_MU_FADE, 8, mu);

    proc = SpawnProc(ProcScr_MuRestorePalInfo, PROC_TREE_3);
    proc->ptr = mu;
}

void MuRestorePalInfo_Apply(struct GenericProc* proc)
{
    struct MuProc* mu = proc->ptr;
    mu->anim->oam2 = mu->config->chr + OAM2_PAL(mu->config->pal) + OAM2_LAYER(2);
}

static void MuActionAnimFinishFunc(int arg);

void StartMuActionAnim(struct MuProc* mu)
{
    Anim_SetAnimId(mu->anim, 4);
    Anim_ResetClock(mu->anim);

    CallDelayedArg(MuActionAnimFinishFunc, (int) mu->anim, 30);
}

static void MuActionAnimFinishFunc(int arg)
{
    Anim_Freeze((struct Anim*) arg);
}

static void MuDelayedFaceTargetFunc(int arg);

void StartMuDelayedFaceTarget(struct MuProc* mu)
{
    Anim_ResetClock(mu->anim);

    CallDelayedArg(MuDelayedFaceTargetFunc, (int) mu->anim, 30);
}

static void MuDelayedFaceTargetFunc(int arg)
{
    MA_SetActorFacing(gMapAnimSt.attackerActor, 1-gMapAnimSt.attackerActor, GetItemMaFacing(gMapAnimSt.actor[0].bu->weaponBefore));
    Anim_Freeze((struct Anim*) arg);
}

static void MuSlowDownAnimFreezeFunc(int arg);

void StartMuSlowDownAnim(struct MuProc* mu)
{
    mu->anim->clock = 0;
    mu->anim->q8_clockStep = 0x40;

    CallDelayedArg(MuSlowDownAnimFreezeFunc, (int) mu->anim, 20);
}

static void MuSlowDownAnimFreezeFunc(int arg)
{
    Anim_Freeze((struct Anim*) arg);
}

void sub_806142C(struct MuProc* mu, int flash)
{
    struct MuFadeProc* proc;

    ApplyPalette(gMuFlashPalLut[flash], 0x10+OBJPAL_MU_FADE);

    proc = SpawnProc(ProcScr_Unk_08664914, mu);
    proc->mu = mu;
}

void sub_8061474(struct MuFadeProc* proc)
{
    proc->clock = 0;
}

void sub_8061494(struct MuFadeProc* proc)
{
    proc->mu->anim->oam2 = proc->mu->config->chr + OAM2_PAL(OBJPAL_MU_FADE) + OAM2_LAYER(2);
}

void sub_80614C8(struct MuFadeProc* proc)
{
    proc->mu->anim->oam2 = proc->mu->config->chr + OAM2_PAL(proc->mu->config->pal) + OAM2_LAYER(2);
}

void sub_8061518(struct MuFadeProc* proc)
{
    StartPalFade(gPal + ((0x20 * (0x10 + proc->mu->config->pal)) >> 1), 0x10 + OBJPAL_MU_FADE, 20, proc);
}

void sub_8061554(struct MuFadeProc* proc)
{
    proc->clock++;

    SetMuScreenOffset(proc->mu,
        (proc->clock & 1) != 0 ? +2 : -2, 0);

    if (proc->clock > 11)
    {
        SetMuScreenOffset(proc->mu, 0, 0);
        Proc_Break(proc);
    }
}

void sub_80615D4(struct MuFadeProc* proc)
{
    proc->mu->anim->oam2 = proc->mu->config->chr + OAM2_PAL(proc->mu->config->pal) + OAM2_LAYER(2);
}

void StartMuFlashFadeFrom(struct MuProc* mu, int flash)
{
    struct MuFadeProc* proc;

    ApplyPalette(gMuFlashPalLut[flash], 0x10+OBJPAL_MU_FADE);

    mu->anim->oam2 = mu->config->chr + OAM2_PAL(OBJPAL_MU_FADE) + OAM2_LAYER(2);
    StartPalFade(gPal + ((0x20 * (0x10 + mu->config->pal)) >> 1), 0x10 + OBJPAL_MU_FADE, 20, mu);

    proc = SpawnProc(ProcScr_MuFlashFadeFrom, mu);
    proc->mu = mu;
}

void MuFlashFadeFrom_RestorePal(struct MuFadeProc* proc)
{
    proc->mu->anim->oam2 = proc->mu->config->chr + OAM2_PAL(proc->mu->config->pal) + OAM2_LAYER(2);
}

static void MuMaxWalkSpeedFunc(ProcPtr mu);

void SetMuMaxWalkSpeed(void)
{
    Proc_ForEach(ProcScr_Mu, MuMaxWalkSpeedFunc);
}

static void MuMaxWalkSpeedFunc(ProcPtr mu)
{
    ((struct MuProc*) mu)->boolFastWalk = TRUE;
}

void SetMuSpecialSprite(struct MuProc* mu, int jid, u16 const* pal)
{
    Anim_Freeze(mu->anim);

    mu->jid = jid;

    Anim_SetInfo(mu->anim, GetMuAnimForJid(mu->jid));
    Decompress(GetMuImg(mu), GetMuImgBufById(mu->config->id));
    ApplyPalette(pal, 0x10+mu->config->pal);
}

void SetMuPal(struct MuProc* mu, int pal)
{
    mu->config->pal = pal;
    mu->anim->oam2 = mu->config->chr + OAM2_PAL(pal) + OAM2_LAYER(2);
}
