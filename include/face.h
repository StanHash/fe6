
#pragma once

#include "gba/gba.h"

#include "proc.h"

struct FaceInfo
{
    /* 00 */ u8 const* img;
    /* 04 */ u8 const* imgChibi;
    /* 08 */ u16 const* pal;
    /* 0C */ u8 xMouth, yMouth;
    /* 0E */ u8 unk0E;
};

struct FaceVramEnt
{
    /* 00 */ u32 chrOff;
    /* 04 */ u16 palid;
};

struct FaceProc
{
    /* 00 */ PROC_HEADER;

    /* 29 */ // pad
    /* 2A */ u16 disp;
    /* 2C */ s8 slot;
    /* 2D */ s8 sprLayer;
    /* 2E */ short xDisp;
    /* 30 */ short yDisp;
    /* 32 */ short xOffMouth;
    /* 34 */ short yOffMouth;
    /* 36 */ s8 talkFrame;
    /* 37 */ s8 talkFrameClock;
    /* 38 */ u16 oam2;
    /* 3A */ // pad
    /* 3C */ u16 const* sprite;
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

extern struct FaceProc* gFaces[FACE_SLOT_COUNT]; // COMMON

extern struct ProcScr CONST_DATA ProcScr_Face[];

struct FaceInfo const* GetFaceInfo(int fid);
int GetFace_Unk(int fid);
void InitFaces(void);
void SetFaceConfig(struct FaceVramEnt const* config);
int GetFreeFaceSlot(void);
struct FaceProc* StartFaceAuto(int fid, int x, int y, int disp);
struct FaceProc* StartFace(int slot, int fid, int x, int y, int disp);
void EndFace(struct FaceProc* proc);
void EndFaceById(int slot);
int SetFaceDisp(struct FaceProc* proc, int disp);
int SetFaceDispById(int slot, int disp);
int GetFaceDisp(struct FaceProc* proc);
int GetFaceDispById(int slot);
void FaceRefreshSprite(struct FaceProc* proc);
void UnpackFaceGraphics(int fid, int chr, int pal);
void PutFullFaceTm(u16* tm, int unused_1, int unused_2, int tileref, s8 isFlipped);
void sub_8008874(u16* tm, int tileref);
void UnpackFaceChibiGraphics(int fid, int chr, int pal);
void PutFaceChibi(int fid, u16* tm, int chr, int pal, s8 isFlipped);
void UnpackFaceChibiSprGraphics(int fid, int chr, int pal);
void StartFaceChibiStr(int x, int y, int fid, int chr, int pal, s8 isFlipped, ProcPtr parent);
void EndFaceChibiStr(void);
void PutFace80x72(u16* tm, int fid, int chr, int pal);
void StartFaceFadeIn(struct FaceProc* proc);
void StartFaceFadeOut(struct FaceProc* proc);
