#pragma once

#include "common.h"

#include "proc.h"

struct SpriteAnim
{
    /* 00 */ u16 const* info;             // address of info
    /* 04 */ u16 const* sprites;          // address of sprite array
    /* 08 */ u16 const* script;           // address of script start (where we go back on loop)
    /* 0C */ u16 const* script_pc;        // address of script pc (where we are now)
    /* 10 */ u16 const* current_sprite;   // address of current sprite
    /* 14 */ u16 const* current_affine;   // address of current affine
    /* 18 */ i16 clock;                   // Cycle Timer
    /* 1A */ u16 clock_interval_q8;       // Cycle Time Step
    /* 1C */ u16 clock_decimal_q8;        // Sub frame time offset or something
    /* 1E */ u16 layer;                   // sprite layer
    /* 20 */ u8 need_sync_img_b;          // bool defining whether gfx needs update
    /* 21 */ u8 affine_slot;              // Rotation/Scale OAM Index
    /* 22 */ u16 oam2;                    // OAM Extra Data (Tile Index Root & OAM2 Stuff)
    /* 24 */ u8 const* img;               // address of graphics (if any)
};

void InitSpriteAnims(void);
struct SpriteAnim* StartSpriteAnim(u16 const* info, u16 layer);
void EndSpriteAnim(struct SpriteAnim* anim);
bool DisplaySpriteAnim(struct SpriteAnim* anim, int x, int y);
void SetSpriteAnimId(struct SpriteAnim* anim, int id);
void SetSpriteAnimInfo(struct SpriteAnim* anim, u16 const* info);
struct SpriteAnim* FindSpriteAnim(u16 const* info);
ProcPtr StartSpriteAnimProc(u16 const* info, int x, int y, int oam2, int animid, int layer);
void SetSpriteAnimProcParameters(ProcPtr proc, int x, int y, int oam2);
void EndSpriteAnimProc(ProcPtr proc);
void EndEachSpriteAnimProc(void);
bool SpriteAnimProcExists(void);

#define ResetSpriteAnimClock(anim) \
    (anim)->clock = 0; \
    (anim)->clock_interval_q8 = 0x100

#define FreezeSpriteAnim(anim) \
    (anim)->clock = 0; \
    (anim)->clock_interval_q8 = 0
