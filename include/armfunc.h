
#pragma once

#include "gba/gba.h"

extern u8 const ArmCodeStart[];
extern u8 const ArmCodeEnd[];

void ClearOam(void* oam, int count);
void TmApplyTsa(u16* tm, u8 const* tsa, u16 tileref);
void TmFillRect(u16* tm, int width, int height, u16 tileref);

void DrawGlyph(u16 const* cvtLut, void* chr, u32 const* glyph, int offset);
void DecodeString(char const* src, char* dst);
void PutOamHi(int x, int y, u16 const* oamList, int oam2);
void PutOamLo(int x, int y, u16 const* oamList, int oam2);
void MoveFillStep(); // TODO: args
void MoveFill(void);

void ClearOam_t(void* oam, int count);
void TmApplyTsa_t(u16* tm, u8 const* tsa, u16 tileref);
void TmFillRect_t(u16* tm, int width, int height, u16 tileref);
