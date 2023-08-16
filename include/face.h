#ifndef FACE_H
#define FACE_H

#include "common.h"

#include "proc.h"

struct FaceInfo
{
    /* 00 */ void const * img;
    /* 04 */ void const * img_chibi;
    /* 08 */ u16 const * pal;
    /* 0C */ u8 x_mouth, y_mouth;
    /* 0E */ u8 unk_0E;
};

struct FaceVramEnt
{
    /* 00 */ u32 chr_off;
    /* 04 */ u16 palid;
};

struct FaceTalkSpriteEnt
{
    i16 chr;
    u16 const * sprite;
};

struct FaceProc
{
    /* 00 */ PROC_HEADER;

    /* 29 */ STRUCT_PAD(0x29, 0x2A);
    /* 2A */ u16 disp;
    /* 2C */ i8 slot;
    /* 2D */ i8 sprite_layer;
    /* 2E */ i16 x_disp;
    /* 30 */ i16 y_disp;
    /* 32 */ i16 x_offset_mouth;
    /* 34 */ i16 y_offset_mouth;
    /* 36 */ i8 talk_frame;
    /* 37 */ i8 talk_frame_clock;
    /* 38 */ u16 oam2;
    /* 3A */ STRUCT_PAD(0x3A, 0x3C);
    /* 3C */ u16 const * sprite;
    /* 40 */ u8 fid;
};

enum
{
    FACE_64x80,
    FACE_64x80_FLIPPED,
    FACE_96x80,
    FACE_96x80_FLIPPED,
    FACE_64x72,
    FACE_64x72_FLIPPED,
};

enum
{
    FACE_HLAYER_DEFAULT,

    // why shifts?
    FACE_HLAYER_0 = 1 << 0,
    FACE_HLAYER_1 = 1 << 1,
    FACE_HLAYER_2 = 1 << 2,
    FACE_HLAYER_3 = 1 << 3,
};

#define FACE_DISP_FLIPPED (1 << 0)
#define FACE_DISP_KIND(kind) ((kind) & 7)
#define FACE_DISP_KIND_MASK FACE_DISP_KIND(-1)
#define FACE_DISP_SMILE (1 << 3)
#define FACE_DISP_TALK_1 (1 << 4)
#define FACE_DISP_TALK_2 (1 << 5)
#define FACE_DISP_HLAYER(layer) (((layer) & 0xF) << 6)
#define FACE_DISP_HLAYER_MASK FACE_DISP_HLAYER(-1)
#define FACE_DISP_BLEND (1 << 10)

enum { FACE_SLOT_COUNT = 4 };

extern struct FaceVramEnt CONST_DATA DefaultFaceConfig[FACE_SLOT_COUNT];

extern u16 CONST_DATA Sprite_Face64x80[];
extern u16 CONST_DATA Sprite_Face64x80_Flipped[];
extern u16 CONST_DATA Sprite_Face96x80[];
extern u16 CONST_DATA Sprite_Face96x80_Flipped[];
extern u16 CONST_DATA Sprite_Face64x72[];
extern u16 CONST_DATA Sprite_Face64x72_Flipped[];

extern u16 CONST_DATA Sprite_FaceTalkFrameB[];
extern u16 CONST_DATA Sprite_FaceTalkFrameB_Flipped[];
extern u16 CONST_DATA Sprite_FaceTalkFrameA[];
extern u16 CONST_DATA Sprite_FaceTalkFrameA_Flipped[];

extern struct FaceTalkSpriteEnt CONST_DATA FaceTalkFrameSpriteTable[16];

extern struct ProcScr CONST_DATA ProcScr_Face[];

extern u8 CONST_DATA FaceTm_Unk_085C3C18[];
extern u8 CONST_DATA FaceTm_Unk_085C3C92[];

extern struct ProcScr CONST_DATA ProcScr_FaceChibiSpr[];

extern u16 CONST_DATA Sprite_FaceChibi[];
extern u16 CONST_DATA Sprite_FaceChibi_Flipped[];

extern struct ProcScr CONST_DATA ProcScr_FaceEndIn8Frames[];

extern struct FaceProc * gFaces[FACE_SLOT_COUNT];

extern struct FaceVramEnt gFaceConfig[FACE_SLOT_COUNT];

struct FaceInfo const * GetFaceInfo(int fid);
int GetFace_Unk(int fid);
void InitFaces(void);
void SetFaceConfig(struct FaceVramEnt const * config);
int GetFreeFaceSlot(void);
void UpdateFaceTalk(struct FaceProc * proc);
void Face_OnIdle(struct FaceProc * proc);
struct FaceProc * StartFaceAuto(int fid, int x, int y, int disp);
struct FaceProc * StartFace(int slot, int fid, int x, int y, int disp);
void EndFace(struct FaceProc * proc);
void EndFaceById(int slot);
u32 SetFaceDisp(struct FaceProc * proc, u32 disp);
u32 SetFaceDispById(int slot, u32 disp);
u32 GetFaceDisp(struct FaceProc * proc);
u32 GetFaceDispById(int slot);
void FaceRefreshSprite(struct FaceProc * proc);
void UnpackFaceGraphics(int fid, int chr, int pal);
void PutFaceTm(u16 * tm, u8 const * data, int tileref, bool is_flipped);
void PutFullFaceTm(u16 * tm, int unused_1, int unused_2, int tileref, bool is_flipped);
void func_fe6_08008874(u16 * tm, int tileref);
void UnpackFaceChibiGraphics(int fid, int chr, int pal);
void PutFaceChibi(int fid, u16 * tm, int chr, int pal, bool is_flipped);
void UnpackFaceChibiSprGraphics(int fid, int chr, int pal);
void FaceChibiSpr_OnIdle(struct FaceProc * proc);
void StartFaceChibiStr(int x, int y, int fid, int chr, int pal, bool is_flipped, ProcPtr parent);
void EndFaceChibiSpr(void);
void PutFace80x72(u16 * tm, int fid, int chr, int pal);
void EndFacePtr(struct GenericProc * proc);
void EndFaceIn8Frames(struct FaceProc * proc);
void StartFaceFadeIn(struct FaceProc * proc);
void StartFaceFadeOut(struct FaceProc * proc);
u8 const * GetFactionFaceImg(int fid);
void ApplyFactionFacePal(int fid, int pal);

#endif // FACE_H
