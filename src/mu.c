
#include "mu.h"

#include "oam.h"
#include "anim.h"
#include "util.h"
#include "unit.h"
#include "unitsprite.h"

void MU_OnLoop(struct MuProc* mu);
extern struct ProcScr CONST_DATA ProcScr_Mu[];
struct MuConfig* MU_GenerateConfigDefault(void);
u16 const* MU_GetAnimationByClassId(int jid);
u8 const* MU_GetSheetGfx(struct MuProc* proc);
u8* MU_GetGfxBufferById(int id);
void sub_805FF50(struct MuProc* mu);

enum { MU_COUNT = 4 };

static struct MuConfig sMuConfig[MU_COUNT];

void sub_805F7E4(void)
{
    int i;

    for (i = 0; i < MU_COUNT; ++i)
    {
        sMuConfig[i].id = 0;
    }
}

struct MuProc* sub_805F820(int x, int y, int jid, int pal)
{
    struct MuProc* mu;

    mu = MU_StartExt(x, y, jid, pal);
    mu->boolCam = TRUE;

    return mu;
}

struct MuProc* MU_Start(struct Unit* unit)
{
    struct MuProc* mu;

    mu = MU_StartExt(unit->x, unit->y, unit->job->id, GetUnitSpritePalette(unit));

    mu->unit = unit;
    mu->boolCam = TRUE;

    return mu;
}

void sub_805F8DC(struct MuProc* mu)
{
    MU_OnLoop(mu);
}

void sub_805F8F4(struct MuProc* mu)
{
    mu->boolCam = TRUE;
}

void sub_805F91C(struct MuProc* mu)
{
    mu->boolCam = FALSE;
}

struct MuProc* sub_805F93C(struct Unit* unit, int x, int y)
{
    struct MuProc* mu;

    mu = MU_Start(unit);

    if (mu == NULL)
        return NULL;

    mu->q4_x = x << 4;
    mu->q4_y = y << 4;
    mu->state = MU_STATE_DISPLAY_UI;

    return mu;
}

struct MuProc* MU_StartExt(u16 x, u16 y, u16 jid, int pal)
{
    struct MuProc* mu;
    struct Anim* anim;
    struct MuConfig* config;

    u16 soundDelay = 0;

    config = MU_GenerateConfigDefault();

    if (config == NULL)
        return NULL;

    if (Proc_Find(ProcScr_Mu))
        soundDelay = 254;

    mu = SpawnProc(ProcScr_Mu, PROC_TREE_5);

    if (mu == NULL)
        return NULL;

    mu->unit = NULL;
    mu->state = MU_STATE_NONACTIVE;

    mu->q4_x = (x * 16) << 4;
    mu->q4_y = (y * 16) << 4;

    mu->q4_xOffset = 0;
    mu->q4_yOffset = 0;

    mu->facing = 11;

    mu->moveClock = 0;
    mu->stepSoundClock = soundDelay;

    mu->jid = jid;

    mu->boolHidden = FALSE;

    mu->unk_42 = 0;

    mu->unk_3E = 0;

    config->pal = pal;

    anim = StartAnim(MU_GetAnimationByClassId(jid), 10);
    Anim_SetAnimId(anim, 4);

    Decompress(MU_GetSheetGfx(mu), MU_GetGfxBufferById(config->id));

    anim->img = MU_GetGfxBufferById(config->id);
    anim->oam2 = config->chr + OAM2_PAL(config->pal) + OAM2_LAYER(2);

    mu->anim = anim;
    mu->config = config;
    mu->config->mu = mu;

    return mu;
}

void sub_805FBDC(struct MuProc* mu, int facing)
{
    mu->facing = facing;
    Anim_SetAnimId(mu->anim, mu->facing);
}

void MU_SetDefaultFacing(struct MuProc* mu)
{
    if (GetJobInfo(mu->jid)->attributes & UNIT_ATTR_MOUNTED)
        sub_805FBDC(mu, 1);
    else
        sub_805FBDC(mu, 2);
}

void MU_SetDefaultFacing_Auto(void)
{
    struct MuProc* mu = Proc_Find(ProcScr_Mu);

    if (mu == NULL)
        return;

    MU_SetDefaultFacing(mu);
}

void sub_805FC80(u8 const* movescr)
{
    struct MuProc* mu = Proc_Find(ProcScr_Mu);

    if (mu == NULL)
        return;

    sub_805FD78(mu, movescr);
}

Bool MU_Exists(void)
{
    return Proc_Find(ProcScr_Mu) != NULL ? TRUE : FALSE;
}

Bool MU_IsAnyActive(void)
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

            case MU_STATE_NONACTIVE:
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

Bool sub_805FD40(struct MuProc* mu)
{
    if (mu->config->id == 0)
        return FALSE;

    switch (mu->state)
    {

    case MU_STATE_NONACTIVE:
        return FALSE;

    default:
        return TRUE;

    }

    return FALSE;
}

void sub_805FD78(struct MuProc* mu, u8 const* movescr)
{
    int i;

    for (i = 0; i < 0x40; ++i)
        mu->config->movescr[i] = movescr[i];

    mu->config->pc = 0;
    mu->state = MU_STATE_MOVEMENT;

    sub_805FF50(mu);
}

struct MuProc* sub_805FDEC(u16 x, u16 y, u16 jid, int pal, u8 const* movescr)
{
    struct MuProc* mu;

    mu = MU_StartExt(x, y, jid, pal);

    if (mu == NULL)
        return NULL;

    sub_805FD78(mu, movescr);

    return mu;
}

void sub_805FE3C(struct GenericProc* proc)
{
    proc->unk58 = 0;
    proc->unk64 = 0;

    proc->unk5C = 0;
    proc->unk66 = 0;
}

void sub_805FE78(struct GenericProc* proc)
{
    PlaySeSpacial(proc->unk58, proc->unk64);
}

void sub_805FE9C(struct GenericProc* proc)
{
    if (proc->unk5C != 0)
        PlaySeSpacial(proc->unk5C, proc->unk66);
}
