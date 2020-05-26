
#pragma once

#include "common.h"

void InitMapForChapter(int chapter);
void sub_8018784(int chapter);
void sub_80187EC(void);
void sub_80188F4(void);
void MapFill(u8** map, int value);
void MapSetEdges(u8** map, u8 value);
void ApplyChapterMapGraphics(int chapter);
void ApplyChapterMapPalettes(void);
void RefreshTerrainMap(void);
void PutMapMetatile(u16* tm, int xTm, int yTm, int x, int y);
void nullsub_2(void);
void PutLimitViewSquare(u16* tm, int x, int y, int xTm, int yTm);
void RenderMap(void);
void RenderMapForFade(void);
void UpdateRenderMap(void);
void RefreshEntityMaps(void);
char const* GetTerrainName(int terrain);
int GetTerrainHealAmount(int terrain);
Bool DoesTerrainHealStatus(int terrain);
void sub_80192E4(void);

extern struct Vec2 gMapSize;

extern u8** gMapUnit;
extern u8** gMapTerrain;
extern u8** gMapMovement;
extern u8** gMapRange;
extern u8** gMapFog;
extern u8** gMapHidden;
extern u8** gMapOther;

extern u8* CONST_DATA gMetatilesTerrainLut;
extern u16** CONST_DATA gMapMetatiles;

#define gMapRangeSigned ((s8**) gMapRange)
#define gMapMovementSigned ((s8**) gMapMovement)
