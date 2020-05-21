
#pragma once

#include "common.h"

void InitRamFuncs(void);

void DrawGlyphRam(u16 const* cvtLut, void* chr, u32 const* glyph, int offset);
void DecodeStringRam(char const* src, char* dst);
void PutOamHiRam(int x, int y, u16 const* oamList, int oam2);
void PutOamLoRam(int x, int y, u16 const* oamList, int oam2);
void MapFloodCoreStepRam(int connect, int x, int y);
void MapFloodCoreRam(void);
