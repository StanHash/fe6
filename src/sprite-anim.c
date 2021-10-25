
#include "sprite-anim.h"

#include "hardware.h"
#include "oam.h"
#include "sprite.h"
#include "util.h"

enum { ANIM_COUNT = 20 };

struct AnimProc
{
    /* 00 */ PROC_HEADER;

    /* 29 */ u8 pad29[0x50 - 0x29];

    /* 50 */ struct SpriteAnim* anim;
    /* 54 */ int x, y;
};

static void PutAnim(struct SpriteAnim* anim, int x, int y);
static bool ExecAnim(struct SpriteAnim* anim);
static void PutAnimAffine(struct SpriteAnim* anim);
static void SyncAnimImg(struct SpriteAnim* anim);
static void SetAnimInfo(struct SpriteAnim* anim, u16 const* info);
static void AnimRunFirstFrame(struct SpriteAnim* anim);
static void InitAnim(struct SpriteAnim* anim, u16 const* info, u16 layer);

static void AnimProc_Update(struct AnimProc* proc);
static void AnimProc_OnEnd(struct AnimProc* proc);

#define RESOLVE_REFTABLE(table, id) ((table) + ((table)[id] >> 1))

static struct SpriteAnim sAnims[ANIM_COUNT];

struct ProcScr CONST_DATA ProcScr_AnimProc[] =
{
    PROC_ONEND(AnimProc_OnEnd),

    PROC_REPEAT(AnimProc_Update),
    PROC_END,
};

void InitSpriteAnims(void)
{
    int i;

    for (i = 0; i < ANIM_COUNT; ++i)
        sAnims[i].info = NULL;
}

struct SpriteAnim* StartSpriteAnim(u16 const* info, u16 layer)
{
    struct SpriteAnim* anim;

    anim = FindSpriteAnim(NULL);

    if (!anim)
        return NULL;

    InitAnim(anim, info, layer);

    return anim;
}

void EndSpriteAnim(struct SpriteAnim* anim)
{
    if (!anim || !anim->info)
        return;

    anim->info = NULL;
}

bool DisplaySpriteAnim(struct SpriteAnim* anim, int x, int y)
{
    if (!anim || !anim->info)
        return FALSE;

    PutAnim(anim, x, y);
    return ExecAnim(anim);
}

static void PutAnim(struct SpriteAnim* anim, int x, int y)
{
    int affineOam1 = 0;

    if (!anim || !anim->info)
        return;

    if (anim->current_affine)
    {
        PutAnimAffine(anim);
        affineOam1 = anim->affine_slot << 9;
    }

    PutSpriteExt(anim->layer, x | affineOam1, y, anim->current_sprite, anim->oam2);

    if (anim->img && anim->need_sync_img_b)
        SyncAnimImg(anim);
}

static bool ExecAnim(struct SpriteAnim* anim)
{
    int tmp;

    if (!anim || !anim->info)
        return FALSE;
    
    if (anim->clock_interval_q8 == 0)
        return TRUE;
    
    // timer going down
    if (anim->clock != 0)
    {
        if (--anim->clock > 0)
            return TRUE;

        anim->clock = 0;
        anim->script_pc += 2;
    }

    switch (anim->script_pc[0])
    {

    case 0:
        // anim animation end

        switch (anim->script_pc[1])
        {

        case UINT16_MAX: // loop back to start
            anim->script_pc = anim->script;
            return ExecAnim(anim);

        case 0: // end anim
            return FALSE;

        case 1: // delete anim
            EndSpriteAnim(anim);
            return FALSE;

        }

        // fallthrough

    default:
        // Increasing the subframe clock
        tmp = (anim->script_pc[0] * anim->clock_interval_q8);
        anim->clock_decimal_q8 += tmp;

        // Check if next frame wasn't reached yet
        if (anim->clock_decimal_q8 >= 0x100)
        {
            // Setting clock values depending on subframe clock
            anim->clock = (anim->clock_decimal_q8 >> 8);
            anim->clock_decimal_q8 = (anim->clock_decimal_q8 & 0xFF);
        }
        else
        {
            anim->clock = 1;
            return ExecAnim(anim);
        }

        // Setting new frame
        anim->current_sprite = RESOLVE_REFTABLE(anim->sprites, anim->script_pc[1]);

        // Handling affine data (if any)
        if (anim->current_sprite[0] & 0x8000)
        {
            anim->current_affine = anim->current_sprite;
            anim->current_sprite += (anim->current_affine[0] & 0x7FFF)*3 + 1;
        }
        else
        {
            anim->current_affine = NULL;
        }

        // Gfx needs update
        anim->need_sync_img_b = TRUE;

        return TRUE;

    }
}

static void PutAnimAffine(struct SpriteAnim* anim)
{
    int i, count;
    u16 const* it;

    if (!anim || !anim->info)
        return;

    if (!anim->current_affine)
        return;

    count = anim->current_affine[0] & 0x7FFF;
    it = anim->current_affine + 1;

    for (i = 0; i < count; it += 3, i++)
        SetObjAffineAuto(anim->affine_slot + i, it[0], it[1], it[2]);
}

void SetSpriteAnimId(struct SpriteAnim* anim, int id)
{
    if (!anim || !anim->info)
        return;

    anim->script = RESOLVE_REFTABLE(RESOLVE_REFTABLE(anim->info, 1), id);
    anim->script_pc = RESOLVE_REFTABLE(RESOLVE_REFTABLE(anim->info, 1), id);

    AnimRunFirstFrame(anim);
}

void SetSpriteAnimInfo(struct SpriteAnim* anim, u16 const* info)
{
    if (!anim || !anim->info)
        return;
    
    SetAnimInfo(anim, info);
    AnimRunFirstFrame(anim);
}

static void SyncAnimImg(struct SpriteAnim* anim)
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
    
    i = anim->current_sprite[0];

    itOam = anim->current_sprite + 1;
    itChr = anim->current_sprite + 1 + i*3;

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

        if (!gDispIo.disp_ct.obj1dMap)
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

    anim->need_sync_img_b = FALSE;
}

static void SetAnimInfo(struct SpriteAnim* anim, u16 const* info)
{
    anim->info = info;

    anim->sprites = RESOLVE_REFTABLE(anim->info, 0);

    anim->script = RESOLVE_REFTABLE(RESOLVE_REFTABLE(anim->info, 1), 0);
    anim->script_pc = RESOLVE_REFTABLE(RESOLVE_REFTABLE(anim->info, 1), 0);
}

static void AnimRunFirstFrame(struct SpriteAnim* anim)
{
    int tmp;

    anim->clock = 0;

    tmp = anim->clock_interval_q8;

    ResetSpriteAnimClock(anim);
    ExecAnim(anim);

    anim->clock_interval_q8 = tmp;
}

static void InitAnim(struct SpriteAnim* anim, u16 const* info, u16 layer)
{
    SetAnimInfo(anim, info);

    anim->img = NULL;
    anim->oam2 = 0;
    anim->clock = 0;

    anim->layer = layer;

    anim->current_affine = NULL;
    anim->affine_slot = 0;

    ResetSpriteAnimClock(anim);

    anim->clock_decimal_q8 = 0;

    ExecAnim(anim);
}

struct SpriteAnim* FindSpriteAnim(u16 const* info)
{
    int i;

    for (i = 0; i < ANIM_COUNT; ++i)
    {
        if (sAnims[i].info == info)
            return &sAnims[i];
    }

    return NULL;
}

ProcPtr StartSpriteAnimProc(u16 const* info, int x, int y, int oam2, int animid, int layer)
{
    struct AnimProc* proc;
    struct SpriteAnim* anim;

    anim = StartSpriteAnim(info, layer);

    SetSpriteAnimId(anim, animid);
    anim->oam2 = oam2;

    proc = SpawnProc(ProcScr_AnimProc, PROC_TREE_3);

    proc->anim = anim;
    proc->x = x;
    proc->y = y;

    return proc;
}

static void AnimProc_Update(struct AnimProc* proc)
{
    if (!DisplaySpriteAnim(proc->anim, proc->x, proc->y))
        if (!proc->anim || !proc->anim->info)
            Proc_End(proc);
}

static void AnimProc_OnEnd(struct AnimProc* proc)
{
    EndSpriteAnim(proc->anim);
}

void SetSpriteAnimProcParameters(ProcPtr proc, int x, int y, int oam2)
{
    struct AnimProc* aproc = proc;

    aproc->x = x;
    aproc->y = y;

    aproc->anim->oam2 = oam2;
}

void EndSpriteAnimProc(ProcPtr proc)
{
    Proc_End(proc);
}

void EndEachSpriteAnimProc(void)
{
    Proc_EndEach(ProcScr_AnimProc);
}

bool SpriteAnimProcExists(void)
{
    return Proc_Exists(ProcScr_AnimProc);
}
