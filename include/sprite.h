
#pragma once

#include "gba/gba.h"

#include "proc.h"

extern u16 CONST_DATA Sprite_8x8[];
extern u16 CONST_DATA Sprite_16x16[];
extern u16 CONST_DATA Sprite_32x32[];
extern u16 CONST_DATA Sprite_64x64[];
extern u16 CONST_DATA Sprite_8x16[];
extern u16 CONST_DATA Sprite_16x32[];
extern u16 CONST_DATA Sprite_32x64[];
extern u16 CONST_DATA Sprite_16x8[];
extern u16 CONST_DATA Sprite_32x16[];
extern u16 CONST_DATA Sprite_64x32[];
extern u16 CONST_DATA Sprite_32x8[];
extern u16 CONST_DATA Sprite_8x32[];
extern u16 CONST_DATA Sprite_32x8_VFlipped[];
extern u16 CONST_DATA Sprite_8x16_HFlipped[];
extern u16 CONST_DATA Sprite_8x8_HFlipped[];
extern u16 CONST_DATA Sprite_8x8_VFlipped[];
extern u16 CONST_DATA Sprite_8x8_HFlipped_VFlipped[];
extern u16 CONST_DATA Sprite_16x16_VFlipped[];

void PutObjectAffine(int id, int pa, int pb, int pc, int pd);
void ClearSprites(void);
void PutSprite(int layer, int x, int y, const u16* object, int oam2);
void PutSpriteExt(int layer, int xOam1, int yOam0, const u16* object, int oam2);
void PushSpriteLayerObjects(int layer);

// struct SpriteProc* StartSpriteRefresher(ProcPtr parent, int layer, int x, int y, u16 const* object, int tileref);
// void MoveSpriteRefresher(struct SpriteProc* proc, int x, int y);
