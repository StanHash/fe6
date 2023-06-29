#pragma once

#include "common.h"

void InitMapForChapter(int chapter);
void InitMapForMinimap(int chapter);
void func_fe6_080187EC(void);
void func_fe6_080188F4(void);
void MapFill(u8 ** map, int value);
void MapSetEdges(u8 ** map, u8 value);
void ApplyChapterMapGraphics(int chapter);
void ApplyChapterMapPalettes(void);
void RefreshTerrainMap(void);
void PutMapMetatile(u16 * tm, int x_tm, int y_tm, int x, int y);
void func_fe6_08018CDC(void);
void PutLimitViewSquare(u16 * tm, int x, int y, int x_tm, int y_tm);
void RenderMap(void);
void RenderMapForFade(void);
void UpdateRenderMap(void);
void RefreshEntityMaps(void);
char const * GetTerrainName(int terrain);
int GetTerrainHealAmount(int terrain);
bool DoesTerrainHealStatus(int terrain);
void func_fe6_080192E4(void);

extern struct Vec2i gMapSize;

extern u8 ** gMapUnit;
extern u8 ** gMapTerrain;
extern u8 ** gMapMovement;
extern u8 ** gMapRange;
extern u8 ** gMapFog;
extern u8 ** gMapHidden;
extern u8 ** gMapOther;

extern u8 * CONST_DATA gMetatilesTerrainLut;
extern u16 ** CONST_DATA gMapMetatiles;

#define gMapRangeSigned ((i8 **) gMapRange)
#define gMapMovementSigned ((i8 **) gMapMovement)
