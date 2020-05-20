
#include "common.h"
#include "face.h"

#include "armfunc.h"
#include "random.h"
#include "hardware.h"
#include "move.h"
#include "oam.h"
#include "proc.h"
#include "sprite.h"
#include "util.h"

#include "constants/video-global.h"
#include "constants/faces.h"

struct TalkSpriteEnt
{
    short chr;
    u16 const* sprite;
};

static void UpdateFaceTalk(struct FaceProc* proc);
static void Face_OnIdle(struct FaceProc* proc);
static void PutFaceTm(u16* tm, u8 const* data, int tileref, s8 isFlipped);
static void FaceChibiSpr_OnIdle(struct FaceProc* proc);
static void EndFacePtr(struct GenericProc* proc);
static void EndFaceIn8Frames(struct FaceProc* proc);
static u8 const* GetFactionFaceImg(int fid);
static void ApplyFactionFacePal(int fid, int pal);

struct FaceVramEnt CONST_DATA sDefaultFaceConfig[FACE_SLOT_COUNT] =
{
    [0] = { OBJCHR_FACE_DEFAULT0 * CHR_SIZE, OBJPAL_FACE_DEFAULT0 },
    [1] = { OBJCHR_FACE_DEFAULT1 * CHR_SIZE, OBJPAL_FACE_DEFAULT1 },
    [2] = { OBJCHR_FACE_DEFAULT2 * CHR_SIZE, OBJPAL_FACE_DEFAULT2 },
    [3] = { OBJCHR_FACE_DEFAULT3 * CHR_SIZE, OBJPAL_FACE_DEFAULT3 },
};

u16 CONST_DATA Sprite_Face64x80[] =
{
    4,
    OAM0_SHAPE_64x32,              OAM1_SIZE_64x32 + OAM1_X(-32), OAM2_CHR(0x00),
    OAM0_SHAPE_64x32 + OAM0_Y(32), OAM1_SIZE_64x32 + OAM1_X(-32), OAM2_CHR(0x08),
    OAM0_SHAPE_32x16 + OAM0_Y(64), OAM1_SIZE_32x16 + OAM1_X(-32), OAM2_CHR(0x10),
    OAM0_SHAPE_32x16 + OAM0_Y(64), OAM1_SIZE_32x16,               OAM2_CHR(0x50),
};

u16 CONST_DATA Sprite_Face64x80_Flipped[] =
{
    4,
    OAM0_SHAPE_64x32,              OAM1_SIZE_64x32 + OAM1_HFLIP + OAM1_X(-32), OAM2_CHR(0x00),
    OAM0_SHAPE_64x32 + OAM0_Y(32), OAM1_SIZE_64x32 + OAM1_HFLIP + OAM1_X(-32), OAM2_CHR(0x08),
    OAM0_SHAPE_32x16 + OAM0_Y(64), OAM1_SIZE_32x16 + OAM1_HFLIP + OAM1_X(-32), OAM2_CHR(0x50),
    OAM0_SHAPE_32x16 + OAM0_Y(64), OAM1_SIZE_32x16 + OAM1_HFLIP,               OAM2_CHR(0x10),
};

u16 CONST_DATA Sprite_Face96x80[] =
{
    6,
    OAM0_SHAPE_64x32,              OAM1_SIZE_64x32 + OAM1_X(-32), OAM2_CHR(0x00),
    OAM0_SHAPE_64x32 + OAM0_Y(32), OAM1_SIZE_64x32 + OAM1_X(-32), OAM2_CHR(0x08),
    OAM0_SHAPE_32x16 + OAM0_Y(64), OAM1_SIZE_32x16 + OAM1_X(-32), OAM2_CHR(0x10),
    OAM0_SHAPE_32x16 + OAM0_Y(64), OAM1_SIZE_32x16,               OAM2_CHR(0x50),
    OAM0_SHAPE_16x32 + OAM0_Y(48), OAM1_SIZE_16x32 + OAM1_X(-48), OAM2_CHR(0x14),
    OAM0_SHAPE_16x32 + OAM0_Y(48), OAM1_SIZE_16x32 + OAM1_X(+32), OAM2_CHR(0x16),
};

u16 CONST_DATA Sprite_Face96x80_Flipped[] =
{
    6,
    OAM0_SHAPE_64x32,              OAM1_SIZE_64x32 + OAM1_HFLIP + OAM1_X(-32), OAM2_CHR(0x00),
    OAM0_SHAPE_64x32 + OAM0_Y(32), OAM1_SIZE_64x32 + OAM1_HFLIP + OAM1_X(-32), OAM2_CHR(0x08),
    OAM0_SHAPE_32x16 + OAM0_Y(64), OAM1_SIZE_32x16 + OAM1_HFLIP + OAM1_X(-32), OAM2_CHR(0x50),
    OAM0_SHAPE_32x16 + OAM0_Y(64), OAM1_SIZE_32x16 + OAM1_HFLIP,               OAM2_CHR(0x10),
    OAM0_SHAPE_16x32 + OAM0_Y(48), OAM1_SIZE_16x32 + OAM1_HFLIP + OAM1_X(-48), OAM2_CHR(0x16),
    OAM0_SHAPE_16x32 + OAM0_Y(48), OAM1_SIZE_16x32 + OAM1_HFLIP + OAM1_X(+32), OAM2_CHR(0x14),
};

u16 CONST_DATA Sprite_Face64x72[] =
{
    6,
    OAM0_SHAPE_64x32,              OAM1_SIZE_64x32 + OAM1_X(-32), OAM2_CHR(0x00),
    OAM0_SHAPE_64x32 + OAM0_Y(32), OAM1_SIZE_64x32 + OAM1_X(-32), OAM2_CHR(0x08),
    OAM0_SHAPE_16x8  + OAM0_Y(64), OAM1_SIZE_16x8  + OAM1_X(-32), OAM2_CHR(0x10),
    OAM0_SHAPE_16x8  + OAM0_Y(64), OAM1_SIZE_16x8  + OAM1_X(-16), OAM2_CHR(0x12),
    OAM0_SHAPE_16x8  + OAM0_Y(64), OAM1_SIZE_16x8,                OAM2_CHR(0x50),
    OAM0_SHAPE_16x8  + OAM0_Y(64), OAM1_SIZE_16x8  + OAM1_X(+16), OAM2_CHR(0x52),
};

u16 CONST_DATA Sprite_Face64x72_Flipped[] =
{
    6,
    OAM0_SHAPE_64x32,              OAM1_SIZE_64x32 + OAM1_HFLIP + OAM1_X(-32), OAM2_CHR(0x00),
    OAM0_SHAPE_64x32 + OAM0_Y(32), OAM1_SIZE_64x32 + OAM1_HFLIP + OAM1_X(-32), OAM2_CHR(0x08),
    OAM0_SHAPE_16x8  + OAM0_Y(64), OAM1_SIZE_16x8  + OAM1_HFLIP + OAM1_X(-32), OAM2_CHR(0x52),
    OAM0_SHAPE_16x8  + OAM0_Y(64), OAM1_SIZE_16x8  + OAM1_HFLIP + OAM1_X(-16), OAM2_CHR(0x50),
    OAM0_SHAPE_16x8  + OAM0_Y(64), OAM1_SIZE_16x8  + OAM1_HFLIP,               OAM2_CHR(0x12),
    OAM0_SHAPE_16x8  + OAM0_Y(64), OAM1_SIZE_16x8  + OAM1_HFLIP + OAM1_X(+16), OAM2_CHR(0x10),
};

u16 CONST_DATA Sprite_Unk_085C3B2C[] =
{
    1, OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_X(-16), 0,
};

u16 CONST_DATA Sprite_Unk_085C3B34[] =
{
    1, OAM0_SHAPE_32x16, OAM1_SIZE_32x16 + OAM1_HFLIP + OAM1_X(-16), 0,
};

u16 CONST_DATA Sprite_Unk_085C3B3C[] =
{
    4,
    OAM0_SHAPE_16x8,             OAM1_SIZE_16x8 + OAM1_X(-16), OAM2_CHR(0x00),
    OAM0_SHAPE_16x8,             OAM1_SIZE_16x8,               OAM2_CHR(0x02),
    OAM0_SHAPE_16x8 + OAM0_Y(8), OAM1_SIZE_16x8 + OAM1_X(-16), OAM2_CHR(0x04),
    OAM0_SHAPE_16x8 + OAM0_Y(8), OAM1_SIZE_16x8,               OAM2_CHR(0x06),
};

u16 CONST_DATA Sprite_Unk_085C3B56[] =
{
    4,
    OAM0_SHAPE_16x8,             OAM1_SIZE_16x8 + OAM1_HFLIP,               OAM2_CHR(0x00),
    OAM0_SHAPE_16x8,             OAM1_SIZE_16x8 + OAM1_HFLIP + OAM1_X(-16), OAM2_CHR(0x02),
    OAM0_SHAPE_16x8 + OAM0_Y(8), OAM1_SIZE_16x8 + OAM1_HFLIP,               OAM2_CHR(0x04),
    OAM0_SHAPE_16x8 + OAM0_Y(8), OAM1_SIZE_16x8 + OAM1_HFLIP + OAM1_X(-16), OAM2_CHR(0x06),
};

static struct TalkSpriteEnt CONST_DATA sTalkFrameSpriteTable[] =
{
    { 0x80, Sprite_Unk_085C3B3C },
    { 0x58, Sprite_Unk_085C3B2C },
    { 0x18, Sprite_Unk_085C3B2C },
    { 0x58, Sprite_Unk_085C3B2C },

    { 0x80, Sprite_Unk_085C3B56 },
    { 0x58, Sprite_Unk_085C3B34 },
    { 0x18, Sprite_Unk_085C3B34 },
    { 0x58, Sprite_Unk_085C3B34 },

    { 0x80, Sprite_Unk_085C3B3C },
    { 0x5C, Sprite_Unk_085C3B2C },
    { 0x1C, Sprite_Unk_085C3B2C },
    { 0x5C, Sprite_Unk_085C3B2C },

    { 0x80, Sprite_Unk_085C3B56 },
    { 0x5C, Sprite_Unk_085C3B34 },
    { 0x1C, Sprite_Unk_085C3B34 },
    { 0x5C, Sprite_Unk_085C3B34 },
};

struct ProcScr CONST_DATA ProcScr_Face[] =
{
    PROC_19, // TODO: PROC_NAME("E_FACE")

    PROC_WHILE_EXISTS(ProcScr_CamMove),
    PROC_SLEEP(1),

    PROC_REPEAT(Face_OnIdle),

    PROC_END,
};

u8 CONST_DATA FaceTm_Unk_085C3C18[] =
{
    12, 10,
    0xFF, 0xFF, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0xFF, 0xFF,
    0xFF, 0xFF, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0xFF, 0xFF,
    0xFF, 0xFF, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0xFF, 0xFF,
    0xFF, 0xFF, 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0xFF, 0xFF,
    0xFF, 0xFF, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0xFF, 0xFF,
    0xFF, 0xFF, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0xFF, 0xFF,
    0x14, 0x15, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x16, 0x17,
    0x34, 0x35, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, 0x36, 0x37,
    0x54, 0x55, 0x10, 0x11, 0x12, 0x13, 0x50, 0x51, 0x52, 0x53, 0x56, 0x57,
    0x74, 0x75, 0x30, 0x31, 0x32, 0x33, 0x70, 0x71, 0x72, 0x73, 0x76, 0x77,
};

u8 CONST_DATA FaceTm_Unk_085C3C92[] =
{
    4, 4,
    0x00, 0x01, 0x02, 0x03,
    0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0A, 0x0B,
    0x0C, 0x0D, 0x0E, 0x0F,
};

struct ProcScr CONST_DATA ProcScr_FaceChibiSpr[] =
{
    PROC_REPEAT(FaceChibiSpr_OnIdle),
    PROC_END,
};

u16 CONST_DATA Sprite_FaceChibi[] = 
{
    2,
    OAM0_SHAPE_32x16,               OAM1_SIZE_32x16, OAM2_CHR(0),
    OAM0_SHAPE_32x16 + OAM0_Y(+16), OAM1_SIZE_32x16, OAM2_CHR(4),
};

u16 CONST_DATA Sprite_FaceChibi_Flipped[] =
{
    2,
    OAM0_SHAPE_32x16,               OAM1_SIZE_32x16 + OAM1_HFLIP, OAM2_CHR(0),
    OAM0_SHAPE_32x16 + OAM0_Y(+16), OAM1_SIZE_32x16 + OAM1_HFLIP, OAM2_CHR(4),
};

struct ProcScr CONST_DATA ProcScr_FaceEndIn8Frames[] =
{
    PROC_SLEEP(8),

    PROC_CALL(EndFacePtr),
    PROC_END,
};

static struct FaceVramEnt EWRAM_DATA sFaceConfig[4] = {};

struct FaceInfo const* GetFaceInfo(int fid)
{
    return FaceInfoTable + fid;
}

int GetFace_Unk(int fid)
{
    return GetFaceInfo(fid)->unk0E;
}

void InitFaces(void)
{
    int i;

    for (i = 0; i < FACE_SLOT_COUNT; ++i)
        EndFaceById(i);

    SetFaceConfig(NULL);
}

void SetFaceConfig(struct FaceVramEnt const* config)
{
    int i;

    if (config == NULL)
        config = sDefaultFaceConfig;

    for (i = 0; i < FACE_SLOT_COUNT; ++i)
    {
        sFaceConfig[i].chrOff = config[i].chrOff;
        sFaceConfig[i].palid = config[i].palid;
    }
}

int GetFreeFaceSlot(void)
{
    int i;

    for (i = 0; i < FACE_SLOT_COUNT; ++i)
    {
        if (gFaces[i] == NULL)
            return i;
    }

    return -1;
}

static void UpdateFaceTalk(struct FaceProc* proc)
{
    int sprnum;
    int oam0;

    proc->talkFrameClock--;

    if (proc->talkFrameClock < 0)
    {
        proc->talkFrameClock = 1 + ((RandNextB() >> 16) & 7); // 1 + rand(0..6)
        proc->talkFrame = (proc->talkFrame + 1) & 3;
    }

    sprnum = GetFaceDisp(proc) & FACE_DISP_SMILE ? 0 : 8;
    sprnum = GetFaceDisp(proc) & FACE_DISP_FLIPPED ? sprnum + 4 : sprnum;

    if (GetFaceDisp(proc) & (FACE_DISP_TALK_1 | FACE_DISP_TALK_2))
        sprnum += proc->talkFrame;

#if NONMATCHING

    oam0 = GetFaceDisp(proc) & FACE_DISP_BLEND ? OAM0_BLEND : 0;

#else
    asm("\n\
        ldr r0, [r7]\n\
        bl GetFaceDisp\n\
        mov r1, #0x80\n\
        lsl r1, r1, #3\n\
        and r0, r1\n\
        cmp r0, #0\n\
        beq _080081DE\n\
        mov r0, #0x80\n\
        lsl r0, r0, #3\n\
        b _080081E0\n\
    _080081DE:\n\
        mov r0, #0\n\
    _080081E0:\n\
        str r0, [r7, #8]\n\
    ");
#endif

    oam0 += OAM0_Y(proc->yDisp + proc->yOffMouth);

    PutSpriteExt(proc->sprLayer,
        OAM1_X(proc->xDisp + proc->xOffMouth), oam0,
        sTalkFrameSpriteTable[sprnum].sprite,
        proc->oam2 + sTalkFrameSpriteTable[sprnum].chr);
}

static void Face_OnIdle(struct FaceProc* proc)
{
    int oam0;

#if NONMATCHING

    oam0 = GetFaceDisp(proc) & FACE_DISP_BLEND ? OAM0_BLEND : 0;

#else
    asm("\n\
        ldr r0, [r7]\n\
        bl GetFaceDisp\n\
        mov r1, #0x80\n\
        lsl r1, r1, #3\n\
        and r0, r1\n\
        cmp r0, #0\n\
        beq _0800827E\n\
        mov r0, #0x80\n\
        lsl r0, r0, #3\n\
        b _08008280\n\
    _0800827E:\n\
        mov r0, #0\n\
    _08008280:\n\
        str r0, [r7, #4]\n\
    ");
#endif

    oam0 += OAM0_Y(proc->yDisp);

    PutSpriteExt(proc->sprLayer, OAM1_X(proc->xDisp), oam0, proc->sprite, proc->oam2);
    UpdateFaceTalk(proc);
}

struct FaceProc* StartFaceAuto(int fid, int x, int y, int disp)
{
    int slot = GetFreeFaceSlot();

    if (slot < 0)
        return NULL;

    return StartFace(slot, fid, x, y, disp);
}

struct FaceProc* StartFace(int slot, int fid, int x, int y, int disp)
{
    int xMouthRel;
    int oam2Layer;

    struct FaceInfo const* info;
    struct FaceProc* proc;

    if (gFaces[slot] != NULL)
        return NULL;

    info = GetFaceInfo(fid);

    Decompress(info->img, (u8*) VRAM + 0x10000 + sFaceConfig[slot].chrOff);
    ApplyPalette(info->pal, 0x10 + sFaceConfig[slot].palid);

    proc = SpawnProc(ProcScr_Face, PROC_TREE_5);

    if (proc == NULL)
        return NULL;

    gFaces[slot] = proc;

    SetFaceDisp(proc, disp);
    FaceRefreshSprite(proc);

    switch (disp & FACE_DISP_HLAYER_MASK)
    {

    case FACE_DISP_HLAYER(FACE_HLAYER_0): oam2Layer = OAM2_LAYER(0); break;
    case FACE_DISP_HLAYER(FACE_HLAYER_1): oam2Layer = OAM2_LAYER(1); break;
    case FACE_DISP_HLAYER(FACE_HLAYER_3): oam2Layer = OAM2_LAYER(3); break;
    default:                              oam2Layer = OAM2_LAYER(2);

    }

    proc->slot = slot;
    proc->sprLayer = 5;

    proc->xDisp = x;
    proc->yDisp = y;

    xMouthRel = 4 - info->xMouth;

    proc->xOffMouth = GetFaceDisp(proc) & FACE_DISP_FLIPPED ? xMouthRel : -xMouthRel;
    proc->xOffMouth = proc->xOffMouth * 8;

    proc->yOffMouth = info->yMouth * 8;

    proc->talkFrameClock = 0;
    proc->talkFrame = 0;

    proc->oam2 = (sFaceConfig[slot].chrOff / CHR_SIZE) + OAM2_PAL(sFaceConfig[slot].palid) + oam2Layer;

    proc->fid = fid;

    return proc;
}

void EndFace(struct FaceProc* proc)
{
    gFaces[proc->slot] = NULL;
    Proc_End(proc);
}

void EndFaceById(int slot)
{
    EndFace(gFaces[slot]);
}

int SetFaceDisp(struct FaceProc* proc, int disp)
{
    proc->disp = disp;
    return proc->disp;
}

int SetFaceDispById(int slot, int disp)
{
    return SetFaceDisp(gFaces[slot], disp);
}

int GetFaceDisp(struct FaceProc* proc)
{
    return proc->disp;
}

int GetFaceDispById(int slot)
{
    return GetFaceDisp(gFaces[slot]);
}

void FaceRefreshSprite(struct FaceProc* proc)
{
    switch (proc->disp & FACE_DISP_KIND_MASK)
    {

    case FACE_DISP_KIND(FACE_64x80):
        proc->sprite = Sprite_Face64x80;
        break;
    
    case FACE_DISP_KIND(FACE_64x80_FLIPPED):
        proc->sprite = Sprite_Face64x80_Flipped;
        break;

    case FACE_DISP_KIND(FACE_96x80):
        proc->sprite = Sprite_Face96x80;
        break;

    case FACE_DISP_KIND(FACE_96x80_FLIPPED):
        proc->sprite = Sprite_Face96x80_Flipped;
        break;

    case FACE_DISP_KIND(FACE_64x72):
        proc->sprite = Sprite_Face64x72;
        break;

    case FACE_DISP_KIND(FACE_64x72_FLIPPED):
        proc->sprite = Sprite_Face64x72_Flipped;
        break;

    }
}

void UnpackFaceGraphics(int fid, int chr, int pal)
{
    struct FaceInfo const* info = GetFaceInfo(fid);

    Decompress(info->img, (u8*) VRAM + chr * CHR_SIZE);
    ApplyPalette(info->pal, pal);
}

void PutFaceTm(u16* tm, u8 const* data, int tileref, s8 isFlipped)
{
    int width = *data++;
    int height = *data++;

    u8 const* it = data;

    int ix, iy;

    if (!isFlipped)
    {
        for (iy = 0; iy < height; ++iy)
        {
            for (ix = 0; ix < width; ++ix)
            {
                if (*it == 0xFF)
                {
                    it++;
                    continue;
                }

                tm[TM_OFFSET(ix, iy)] = *it++ + tileref;
            }
        }
    }
    else
    {
        for (iy = 0; iy < height; ++iy)
        {
            for (ix = width - 1; ix >= 0; --ix)
            {
                if (*it == 0xFF)
                {
                    it++;
                    continue;
                }

                tm[TM_OFFSET(ix, iy)] = *it++ + tileref + TILE_HFLIP;
            }
        }
    }
}

void PutFullFaceTm(u16* tm, int unused_1, int unused_2, int tileref, s8 isFlipped)
{
    PutFaceTm(tm, FaceTm_Unk_085C3C18, tileref, isFlipped);
}

void sub_8008874(u16* tm, int tileref)
{
    TmApplyTsa_t(tm, Tsa_Unk_08101974, tileref);
}

void UnpackFaceChibiGraphics(int fid, int chr, int pal)
{
    if (fid >= FID_FACTION_CHIBI)
    {
        RegisterVramMove(GetFactionFaceImg(fid), VRAM + chr * CHR_SIZE, 0x10 * CHR_SIZE);
        ApplyFactionFacePal(fid, pal);
    }
    else
    {
        struct FaceInfo const* info = GetFaceInfo(fid);

        RegisterVramMove(info->imgChibi, VRAM + chr * CHR_SIZE, 0x10 * CHR_SIZE);
        ApplyPalette(info->pal, pal);
    }
}

void PutFaceChibi(int fid, u16* tm, int chr, int pal, s8 isFlipped)
{
    UnpackFaceChibiGraphics(fid, chr, pal);

    chr &= 0x3FF;
    PutFaceTm(tm, FaceTm_Unk_085C3C92, TILEREF(chr, pal), isFlipped);
}

void UnpackFaceChibiSprGraphics(int fid, int chr, int pal)
{
    chr += 0x800; // chr relative to obj chr base

    if (fid >= FID_FACTION_CHIBI)
    {
        RegisterVramMove(GetFactionFaceImg(fid) + CHR_SIZE * 0,  (chr + 0x00) * CHR_SIZE, 4 * CHR_SIZE);
        RegisterVramMove(GetFactionFaceImg(fid) + CHR_SIZE * 4,  (chr + 0x20) * CHR_SIZE, 4 * CHR_SIZE);
        RegisterVramMove(GetFactionFaceImg(fid) + CHR_SIZE * 8,  (chr + 0x04) * CHR_SIZE, 4 * CHR_SIZE);
        RegisterVramMove(GetFactionFaceImg(fid) + CHR_SIZE * 12, (chr + 0x24) * CHR_SIZE, 4 * CHR_SIZE);

        ApplyFactionFacePal(fid, 0x10 + pal);
    }
    else
    {
        struct FaceInfo const* info = GetFaceInfo(fid);

        RegisterVramMove(info->imgChibi + CHR_SIZE * 0,  (chr + 0x00) * CHR_SIZE, 4 * CHR_SIZE);
        RegisterVramMove(info->imgChibi + CHR_SIZE * 4,  (chr + 0x20) * CHR_SIZE, 4 * CHR_SIZE);
        RegisterVramMove(info->imgChibi + CHR_SIZE * 8,  (chr + 0x04) * CHR_SIZE, 4 * CHR_SIZE);
        RegisterVramMove(info->imgChibi + CHR_SIZE * 12, (chr + 0x24) * CHR_SIZE, 4 * CHR_SIZE);

        ApplyPalette(info->pal, 0x10 + pal);
    }
}

static void FaceChibiSpr_OnIdle(struct FaceProc* proc)
{
    PutSprite(5,
        proc->xDisp - gDispIo.bgOff[0].x,
        proc->yDisp - gDispIo.bgOff[0].y,
        proc->sprite, proc->oam2);
}

void StartFaceChibiStr(int x, int y, int fid, int chr, int pal, s8 isFlipped, ProcPtr parent)
{
    struct FaceProc* proc;

    UnpackFaceChibiSprGraphics(fid, chr, pal);

    proc = SpawnProc(ProcScr_FaceChibiSpr, parent);

    proc->xDisp = x;
    proc->yDisp = y;

    proc->oam2 = chr + OAM2_PAL(pal);

    proc->sprite = isFlipped
        ? Sprite_FaceChibi_Flipped
        : Sprite_FaceChibi;
}

void EndFaceChibiSpr(void)
{
    Proc_EndEach(ProcScr_FaceChibiSpr);
}

void PutFace80x72(u16* tm, int fid, int chr, int pal)
{
    struct FaceInfo const* info;

    if (fid == 0)
        return;

    info = GetFaceInfo(fid);

    Decompress(info->img, (u8*) VRAM + chr * CHR_SIZE);
    ApplyPalette(info->pal, pal);

    if (info->xMouth != 0 && info->yMouth != 0)
    {
        int i;

        TmApplyTsa_t(tm,
            (fid == FID_FAE) ? Tsa_Unk_08101A2C : Tsa_Unk_08101974,
            (pal << 12) + (chr & 0x3FF));

        for (i = 0; i < 6; ++i)
        {
            tm[i * 0x20 + 0] = 0;
            tm[i * 0x20 + 9] = 0;
        }
    }
    else
    {
        PutIncrTileref(tm, (pal << 12) + (chr & 0x3FF), 10, 9);
    }
}

static void EndFacePtr(struct GenericProc* proc)
{
    EndFace(proc->ptr);
}

void EndFaceIn8Frames(struct FaceProc* proc)
{
    struct GenericProc* gproc;

    gproc = SpawnProc(ProcScr_FaceEndIn8Frames, PROC_TREE_3);
    gproc->ptr = proc;
}

void StartFaceFadeIn(struct FaceProc* proc)
{
    struct FaceInfo const* info = GetFaceInfo(proc->fid);

    SetBlackPal(0x10 + sFaceConfig[proc->slot].palid);
    StartPalFade(info->pal, 0x10 + sFaceConfig[proc->slot].palid, 12, proc);
}

void StartFaceFadeOut(struct FaceProc* proc)
{
    struct FaceInfo const* info = GetFaceInfo(proc->fid);

    StartPalFadeToBlack(0x10 + sFaceConfig[proc->slot].palid, 12, proc);
    EndFaceIn8Frames(proc);
}

static u8 const* GetFactionFaceImg(int fid)
{
    u8 const* imgLut[] =
    {
        Img_FactionMiniCard + 0xC00,
        Img_FactionMiniCard,
        Img_FactionMiniCard + 0x200,
        Img_FactionMiniCard + 0x400,
        Img_FactionMiniCard + 0x600,
        Img_FactionMiniCard + 0x800,
        Img_FactionMiniCard + 0xA00,
    };

    fid = fid - FID_FACTION_CHIBI;

    return imgLut[fid];
}

static void ApplyFactionFacePal(int fid, int pal)
{
    u16 const* palLut[] =
    {
        Pal_FactionMiniCard,
        Pal_FactionMiniCard + 0x10,
        Pal_FactionMiniCard + 0x10,
        Pal_FactionMiniCard + 0x10,
        Pal_FactionMiniCard + 0x10,
        Pal_FactionMiniCard + 0x10,
        Pal_FactionMiniCard + 0x10,
    };

    fid = fid - FID_FACTION_CHIBI;

    ApplyPalette(palLut[fid], pal);
}
