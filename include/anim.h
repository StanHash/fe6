
#pragma once

#include "common.h"

#include "proc.h"

struct Anim
{
    /* 00 */ u16 const* info;      // Pointer to Definition Root
    /* 04 */ u16 const* sprites;       // Pointer to Frame Data Array
    /* 08 */ u16 const* animScriptStart;   // Pointer to Current Anim Data (Start, where we go back on loop)
    /* 0C */ u16 const* animScript; // Pointer to Current Anim Data (Cursor, where we are now)
    /* 10 */ u16 const* activeSprite;  // Pointer to Current Obj Data
    /* 14 */ u16 const* activeAffine; // Pointer to Current Rot/Scale Data
    /* 18 */ short clock;              // Cycle Timer
    /* 1A */ u16 q8_clockStep;           // Cycle Time Step (0x100 is one frame)
    /* 1C */ u16 q8_clockOverflow;           // Sub frame time offset or something
    /* 1E */ u16 layer;                // HiObj layer
    /* 20 */ u8 vramNeedsUpdate;          // bool defining whether gfx needs update
    /* 21 */ u8 affineId;           // Rotation/Scale OAM Index
    /* 22 */ u16 oam2;                // OAM Extra Data (Tile Index Root & OAM2 Stuff)
    /* 24 */ u8 const* img;       // Pointer to graphics (if any)
};

void InitAnims(void);

struct Anim* StartAnim(u16 const* info, u16 layer);

void Anim_End(struct Anim* anim);
bool Anim_Display(struct Anim* anim, int x, int y);
void Anim_SetAnimId(struct Anim* anim, int id);
void Anim_SetInfo(struct Anim* anim, u16 const* info);

struct Anim* FindAnim(u16 const* info);

ProcPtr StartAnimProc(u16 const* info, int x, int y, int oam2, int animid, int layer);
void SetAnimProcParams(ProcPtr proc, int x, int y, int oam2);
void EndAnimProc(ProcPtr proc);
void EndEachAnimProc(void);
bool AnimProcExists(void);

#define Anim_ResetClock(anim) \
    (anim)->clock = 0; \
    (anim)->q8_clockStep = 0x100

#define Anim_Freeze(anim) \
    (anim)->clock = 0; \
    (anim)->q8_clockStep = 0
