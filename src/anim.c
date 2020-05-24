
#include "common.h"
#include "anim.h"

#include "hardware.h"
#include "oam.h"
#include "sprite.h"
#include "util.h"

enum { ANIM_COUNT = 20 };

struct AnimProc
{
    /* 00 */ PROC_HEADER;

    /* 29 */ u8 pad29[0x50 - 0x29];

    /* 50 */ struct Anim* anim;
    /* 54 */ int x, y;
};

static void PutAnim(struct Anim* anim, int x, int y);
static Bool ExecAnim(struct Anim* anim);
static void PutAnimAffine(struct Anim* anim);
static void SyncAnimImg(struct Anim* anim);
static void SetAnimInfo(struct Anim* anim, u16 const* info);
static void AnimRunFirstFrame(struct Anim* anim);
static void InitAnim(struct Anim* anim, u16 const* info, u16 layer);

static void AnimProc_Update(struct AnimProc* proc);
static void AnimProc_OnEnd(struct AnimProc* proc);

#define RESOLVE_REFTABLE(table, id) ((table) + ((table)[id] >> 1))

#define ResetClock(anim) \
    (anim)->clock = 0; \
    (anim)->q8_clockStep = 0x100

static struct Anim sAnims[ANIM_COUNT];

struct ProcScr CONST_DATA ProcScr_AnimProc[] =
{
    PROC_ONEND(AnimProc_OnEnd),

    PROC_REPEAT(AnimProc_Update),
    PROC_END,
};

void InitAnims(void)
{
    int i;

    for (i = 0; i < ANIM_COUNT; ++i)
        sAnims[i].info = NULL;
}

struct Anim* StartAnim(u16 const* info, u16 layer)
{
    struct Anim* anim;

    anim = FindAnim(NULL);

    if (!anim)
        return NULL;

    InitAnim(anim, info, layer);

    return anim;
}

void Anim_End(struct Anim* anim)
{
    if (!anim || !anim->info)
        return;

    anim->info = NULL;
}

Bool Anim_Display(struct Anim* anim, int x, int y)
{
    if (!anim || !anim->info)
        return FALSE;

    PutAnim(anim, x, y);
    return ExecAnim(anim);
}

static void PutAnim(struct Anim* anim, int x, int y)
{
    int affineOam1 = 0;

    if (!anim || !anim->info)
        return;

    if (anim->activeAffine)
    {
        PutAnimAffine(anim);
        affineOam1 = anim->affineId << 9;
    }

    PutSpriteExt(anim->layer, x | affineOam1, y, anim->activeSprite, anim->oam2);

    if (anim->img && anim->vramNeedsUpdate)
        SyncAnimImg(anim);
}

static Bool ExecAnim(struct Anim* anim)
{
    int tmp;

    if (!anim || !anim->info)
        return FALSE;
    
    if (anim->q8_clockStep == 0)
        return TRUE;
    
    // timer going down
    if (anim->clock != 0)
    {
        if (--anim->clock > 0)
            return TRUE;

        anim->clock = 0;
        anim->animScript += 2;
    }

    switch (anim->animScript[0])
    {

    case 0:
        // anim animation end

        switch (anim->animScript[1])
        {

        case UINT16_MAX: // loop back to start
            anim->animScript = anim->animScriptStart;
            return ExecAnim(anim);

        case 0: // end anim
            return FALSE;

        case 1: // delete anim
            Anim_End(anim);
            return FALSE;

        }

        // fallthrough

    default:
        // Increasing the subframe clock
        tmp = (anim->animScript[0] * anim->q8_clockStep);
        anim->q8_clockOverflow += tmp;

        // Check if next frame wasn't reached yet
        if (anim->q8_clockOverflow >= 0x100)
        {
            // Setting clock values depending on subframe clock
            anim->clock = (anim->q8_clockOverflow >> 8);
            anim->q8_clockOverflow = (anim->q8_clockOverflow & 0xFF);
        }
        else
        {
            anim->clock = 1;
            return ExecAnim(anim);
        }

        // Setting new frame
        anim->activeSprite = RESOLVE_REFTABLE(anim->sprites, anim->animScript[1]);

        // Handling affine data (if any)
        if (anim->activeSprite[0] & 0x8000)
        {
            anim->activeAffine = anim->activeSprite;
            anim->activeSprite += (anim->activeAffine[0] & 0x7FFF)*3 + 1;
        }
        else
        {
            anim->activeAffine = NULL;
        }

        // Gfx needs update
        anim->vramNeedsUpdate = TRUE;

        return TRUE;

    }
}

static void PutAnimAffine(struct Anim* anim)
{
    int i, count;
    u16 const* it;

    if (!anim || !anim->info)
        return;

    if (!anim->activeAffine)
        return;

    count = anim->activeAffine[0] & 0x7FFF;
    it = anim->activeAffine + 1;

    for (i = 0; i < count; it += 3, i++)
        SetObjAffineAuto(anim->affineId + i, it[0], it[1], it[2]);
}

void Anim_SetAnimId(struct Anim* anim, int id)
{
    if (!anim || !anim->info)
        return;

    anim->animScriptStart = RESOLVE_REFTABLE(RESOLVE_REFTABLE(anim->info, 1), id);
    anim->animScript = RESOLVE_REFTABLE(RESOLVE_REFTABLE(anim->info, 1), id);

    AnimRunFirstFrame(anim);
}

void Anim_SetInfo(struct Anim* anim, u16 const* info)
{
    if (!anim || !anim->info)
        return;
    
    SetAnimInfo(anim, info);
    AnimRunFirstFrame(anim);
}

static void SyncAnimImg(struct Anim* anim)
{
    static u8 CONST_DATA oamSizeLut[] =
    {
        1, 1,
        2, 2,
        4, 4,
        8, 8,

        2, 1,
        4, 1,
        4, 2,
        8, 4,

        1, 2,
        1, 4,
        2, 4,
        4, 8,
    };

    int chrOffset, i;

    u16 const* itOam;
    u16 const* itChr;

    if (!anim || !anim->info)
        return;
    
    i = anim->activeSprite[0];

    itOam = anim->activeSprite + 1;
    itChr = anim->activeSprite + 1 + i*3;

    chrOffset = 0;

    // These expressions are used a bunch here, so using helper macros for readability
    #define SIZE_LUT_ID(oam) ((((oam[0] & 0xC000)>>12)+((oam[1] & 0xC000)>>14))*2)
    #define WIDTHOF(oam) (oamSizeLut[SIZE_LUT_ID(oam)+0])
    #define HEIGHTOF(oam) (oamSizeLut[SIZE_LUT_ID(oam)+1])

    while ((i--) > 0)
    {
        Register2dChrMove(
            anim->img + ((*itChr & 0x3FF) << 5),
            OBJ_VRAM0 + ((anim->oam2 & 0x3FF) << 5) + chrOffset,
            WIDTHOF(itOam), HEIGHTOF(itOam));

        if (!gDispIo.dispCt.obj1dMap)
            // Adding (width * sizeof(Tile4bpp))
            chrOffset += WIDTHOF(itOam) << 5;
        else
            // Using the square of the width here?
            // Maybe it's bugged, since I don't think the obj1dMap flag is ever set
            chrOffset += ((WIDTHOF(itOam) * WIDTHOF(itOam)) & 0x3FF) << 5;

        itOam += 3;
        itChr += 1;
    }

    #undef SIZE_LUT_ID
    #undef WIDTHOF
    #undef HEIGHTOF

    anim->vramNeedsUpdate = FALSE;
}

static void SetAnimInfo(struct Anim* anim, u16 const* info)
{
    anim->info = info;

    anim->sprites = RESOLVE_REFTABLE(anim->info, 0);

    anim->animScriptStart = RESOLVE_REFTABLE(RESOLVE_REFTABLE(anim->info, 1), 0);
    anim->animScript = RESOLVE_REFTABLE(RESOLVE_REFTABLE(anim->info, 1), 0);
}

static void AnimRunFirstFrame(struct Anim* anim)
{
    int tmp;

    anim->clock = 0;

    tmp = anim->q8_clockStep;

    ResetClock(anim);
    ExecAnim(anim);

    anim->q8_clockStep = tmp;
}

static void InitAnim(struct Anim* anim, u16 const* info, u16 layer)
{
    SetAnimInfo(anim, info);

    anim->img = NULL;
    anim->oam2 = 0;
    anim->clock = 0;

    anim->layer = layer;

    anim->activeAffine = NULL;
    anim->affineId = 0;

    ResetClock(anim);

    anim->q8_clockOverflow = 0;

    ExecAnim(anim);
}

struct Anim* FindAnim(u16 const* info)
{
    int i;

    for (i = 0; i < ANIM_COUNT; ++i)
    {
        if (sAnims[i].info == info)
            return &sAnims[i];
    }

    return NULL;
}

ProcPtr StartAnimProc(u16 const* info, int x, int y, int oam2, int animid, int layer)
{
    struct AnimProc* proc;
    struct Anim* anim;

    anim = StartAnim(info, layer);

    Anim_SetAnimId(anim, animid);
    anim->oam2 = oam2;

    proc = SpawnProc(ProcScr_AnimProc, PROC_TREE_3);

    proc->anim = anim;
    proc->x = x;
    proc->y = y;

    return proc;
}

static void AnimProc_Update(struct AnimProc* proc)
{
    if (!Anim_Display(proc->anim, proc->x, proc->y))
        if (!proc->anim || !proc->anim->info)
            Proc_End(proc);
}

static void AnimProc_OnEnd(struct AnimProc* proc)
{
    Anim_End(proc->anim);
}

void SetAnimProcParams(ProcPtr proc, int x, int y, int oam2)
{
    struct AnimProc* aproc = proc;

    aproc->x = x;
    aproc->y = y;

    aproc->anim->oam2 = oam2;
}

void EndAnimProc(ProcPtr proc)
{
    Proc_End(proc);
}

void EndEachAnimProc(void)
{
    Proc_EndEach(ProcScr_AnimProc);
}

Bool AnimProcExists(void)
{
    return Proc_Exists(ProcScr_AnimProc);
}
