
#pragma once

#include "gba/gba.h"

extern u8 const ArmCodeStart[];
extern u8 const ArmCodeEnd[];

void DrawGlyph(u32 const* cvtLut, void* chr, u32 const* glyph, int offset);
void DecodeString(char const* src, char* dst);
void PutOamHi(int x, int y, u16 const* oamList, int oam2);
void PutOamLo(int x, int y, u16 const* oamList, int oam2);
void MoveFillStep(); // TODO: args
void MoveFill(void);
