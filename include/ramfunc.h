
#pragma once

#include "gba/gba.h"
#include "types.h"

void InitRamFuncs(void);

void DrawGlyphRam(u32 const* cvtLut, void* chr, u32 const* glyph, int offset);
void DecodeStringRam(char const* src, char* dst);
void PutOamHiRam(int x, int y, u16 const* oamList, int oam2);
void PutOamLoRam(int x, int y, u16 const* oamList, int oam2);
void MoveFillStepRam(int arg0, int arg1, int arg2);
void MoveFillRam(void);
