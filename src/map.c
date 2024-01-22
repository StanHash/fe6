#include "map.h"

#include "hardware.h"
#include "util.h"
#include "bm.h"
#include "unit.h"
#include "mapwork.h"
#include "faction.h"
#include "trap.h"
#include "chapterinfo.h"
#include "gamedata.h"

#include "constants/videoalloc_global.h"
#include "constants/chapters.h"
#include "constants/terrains.h"

enum { MAP_POOL_SIZE = 0x7B8 };
enum { TILESET_METATILES = 0x400 };

static void MapInit(u8 * data, u8 *** rowsOut, int width, int height);
static void UnpackRawMap(void * buf, int chapter);
static void InitMetatilesMap(void);
static void RenderMapColumn(u16 x_offset);
static void RenderMapLine(u16 y_offset);

extern u16 gMapBuf[]; // ??

struct Vec2i EWRAM_DATA gMapSize = {};

u8 ** EWRAM_DATA gMapUnit     = NULL;
u8 ** EWRAM_DATA gMapTerrain  = NULL;
u8 ** EWRAM_DATA gMapMovement = NULL;
u8 ** EWRAM_DATA gMapRange    = NULL;
u8 ** EWRAM_DATA gMapFog      = NULL;
u8 ** EWRAM_DATA gMapHidden   = NULL;
u8 ** EWRAM_DATA gMapOther    = NULL;

static u8 ** sInitializingMap;

static u8 EWRAM_DATA sMapUnitData[MAP_POOL_SIZE] = {};
static u8 EWRAM_DATA sMapTerrainData[MAP_POOL_SIZE] = {};
static u8 sMapMovementData[MAP_POOL_SIZE];
static u8 sMapRangeData[MAP_POOL_SIZE];
static u8 EWRAM_DATA sMapFogData[MAP_POOL_SIZE] = {};
static u8 EWRAM_DATA sMapHiddenData[MAP_POOL_SIZE] = {};
static u8 EWRAM_DATA sMapOtherData[MAP_POOL_SIZE] = {};
static u16 EWRAM_DATA sTilesetInfo[TILESET_METATILES*4 + (TILESET_METATILES+1)/2] = {};
static u16 EWRAM_DATA sMapMetatiles[MAP_POOL_SIZE] = {};

u8 * CONST_DATA gMetatilesTerrainLut = (u8 *) &sTilesetInfo[TILESET_METATILES*4];
u16 ** CONST_DATA gMapMetatiles = (u16 **) sMapMetatiles;

void InitMapForChapter(int chapter)
{
    UnpackRawMap(gMapBuf, chapter);
    ApplyChapterMapGraphics(chapter);

    MapInit(sMapUnitData,     &gMapUnit,     gMapSize.x, gMapSize.y);
    MapInit(sMapTerrainData,  &gMapTerrain,  gMapSize.x, gMapSize.y);
    MapInit(sMapMovementData, &gMapMovement, gMapSize.x, gMapSize.y);
    MapInit(sMapRangeData,    &gMapRange,    gMapSize.x, gMapSize.y);
    MapInit(sMapFogData,      &gMapFog,      gMapSize.x, gMapSize.y);
    MapInit(sMapHiddenData,   &gMapHidden,   gMapSize.x, gMapSize.y);
    MapInit(sMapOtherData,    &gMapOther,    gMapSize.x, gMapSize.y);

    MapFill(gMapUnit, 0);
    MapFill(gMapTerrain, 0);

    InitMetatilesMap();
    ApplyEnabledMapChanges();
    RefreshTerrainMap();

    if (gPlaySt.chapter == CHAPTER_14X)
        func_fe6_080187EC();
}

void InitMapForMinimap(int chapter)
{
    UnpackRawMap(gMapBuf, chapter);

    MapInit(sMapUnitData,    &gMapUnit,    gMapSize.x, gMapSize.y);
    MapInit(sMapTerrainData, &gMapTerrain, gMapSize.x, gMapSize.y);

    MapFill(gMapUnit, 0);
    MapFill(gMapTerrain, 0);

    InitMetatilesMap();
    RefreshTerrainMap();
}

void func_fe6_080187EC(void)
{
    int ix, iy;

    // Automatic water shadows?

    for (iy = 1; iy < gMapSize.y; ++iy)
    {
        for (ix = 1; ix < gMapSize.x; ++ix)
        {
            int connect = 0;

            if (gMapTerrain[iy][ix] != TERRAIN_LAKE)
                continue;

            if (gMapTerrain[iy][ix - 1] == TERRAIN_FLOOR_17)
                connect = 1;

            if (gMapTerrain[iy - 1][ix] == TERRAIN_FLOOR_17)
                connect += 2;

            if ((gMapTerrain[iy]    [ix - 1] == TERRAIN_FLOOR_17) &&
                (gMapTerrain[iy + 1][ix - 1] == TERRAIN_LAKE) &&
                (gMapTerrain[iy - 1][ix]     != TERRAIN_FLOOR_17))
                connect = 4;

            switch (connect)
            {

            case 1: // straight shadow on the left
                gMapMetatiles[iy][ix] = 0x2DC;
                break;

            case 2: // straight shadow on the top
                gMapMetatiles[iy][ix] = 0x2D8;
                break;

            case 3: // shadow on both the left and the top
                gMapMetatiles[iy][ix] = 0x358;
                break;

            case 4: // shadow on the left, but stronger at the top-left than bottom-left
                gMapMetatiles[iy][ix] = 0x35C;
                break;

            }
        }
    }
}

void func_fe6_080188F4(void)
{
    UnpackRawMap(gMapBuf, gPlaySt.chapter);

    InitMetatilesMap();
    ApplyEnabledMapChanges();
    RefreshTerrainMap();

    func_fe6_080187EC();
}

void MapInit(u8 * data, u8 *** rowsOut, int width, int height)
{
    u8 * it;
    int i;

    sInitializingMap = (u8 **) data;

    width += 2; // two squares on each edge (shared)
    height += 4; // two squares on each edge

    // it = start of square area (the first height * sizeof(u8 *) bytes are reserved for row pointers)
    it = data + height * sizeof(u8 *);

    // Setting up the row pointers
    for (i = 0; i < height; ++i)
    {
        sInitializingMap[i] = it;
        it += width;
    }

    // first row is actually the third, ensuring the top two map rows as safety
    *rowsOut = sInitializingMap + 2;
}

void MapFill(u8 ** map, int value)
{
    int size = (gMapSize.y + 4) * (gMapSize.x + 2);

    if (size % 2)
        size = size - 1;

    value = value & 0xFF;
    value += value << 8;

    CpuFill16(value, map[-2], size);

    SetWorkingMap(map);
}

void MapSetEdges(u8 ** map, u8 value)
{
    int ix, iy;

    u8 ** theMap = map;

    // Set tile values for horizontal edges
    for (iy = 0; iy < gMapSize.y; ++iy)
    {
        theMap[iy][0]            = value;
        theMap[iy][gMapSize.x-1] = value;
    }

    // Set tile values for vertical edges
    for (ix = 0; ix < gMapSize.x; ++ix)
    {
        theMap[0]           [ix] = value;
        theMap[gMapSize.y-1][ix] = value;
    }
}

void UnpackRawMap(void * buf, int chapter)
{
    // Decompress map data
    Decompress(GetChapterMap(chapter), buf);

    // Setting map size
    gMapSize.x = ((u8 *) buf)[0];
    gMapSize.y = ((u8 *) buf)[1];

    // Decompress tileset info
    Decompress(ChapterAssets[GetChapterInfo(chapter)->asset_tileset], sTilesetInfo);

    // Setting max camera offsets
    gBmSt.camera_max.x = gMapSize.x*16 - DISPLAY_WIDTH;
    gBmSt.camera_max.y = gMapSize.y*16 - DISPLAY_HEIGHT;
}

void ApplyChapterMapGraphics(int chapter)
{
    // Decompress tileset graphics (part 1)
    Decompress(
        ChapterAssets[GetChapterInfo(chapter)->asset_img_a],
        (void *) BG_VRAM + CHR_SIZE * BGCHR_TILESET_A);

    // Decompress tileset graphics (part 2, if it exists)
    if (ChapterAssets[GetChapterInfo(chapter)->asset_img_b])
        Decompress(
            ChapterAssets[GetChapterInfo(chapter)->asset_img_b],
            (void *) BG_VRAM + CHR_SIZE * BGCHR_TILESET_B);

    // Apply tileset palette
    ApplyPalettes(ChapterAssets[GetChapterInfo(chapter)->asset_pal], BGPAL_TILESET, 10);
}

void ApplyChapterMapPalettes(void)
{
    ApplyPalettes(ChapterAssets[GetChapterInfo(gPlaySt.chapter)->asset_pal], BGPAL_TILESET, 10);
}

void InitMetatilesMap(void)
{
    int ix, iy;

    u16 ** rows;
    u16 * tiles;
    u16 * it;

    rows  = gMapMetatiles;
    tiles = gMapBuf;

    gMapSize.y++; // ?

    // Ignore first short (x, y byte pair)
    tiles++;

    // Tile buffer starts after the rows
    it = (u16 *) (gMapMetatiles + gMapSize.y);

    for (iy = 0; iy < gMapSize.y; ++iy)
    {
        // Set row buffer
        rows[iy] = it;
        it += gMapSize.x;

        // Set tiles
        for (ix = 0; ix < gMapSize.x; ++ix)
            gMapMetatiles[iy][ix] = *tiles++;
    }

    // Fill "bottom" row with empty tiles?
    // "bottom" as the y had been increased too this is just weird

    tiles = gMapMetatiles[iy - 1];

    for (ix = 0; ix < gMapSize.x; ++ix)
        *tiles++ = 0;

    gMapSize.y--; // ?
}

void RefreshTerrainMap(void)
{
    int ix, iy;

    for (iy = 0; iy < gMapSize.y; ++iy)
        for (ix = 0; ix < gMapSize.x; ++ix)
            gMapTerrain[iy][ix] = gMetatilesTerrainLut[gMapMetatiles[iy][ix] >> 2];
}

void PutMapMetatile(u16 * tm, int x_tm, int y_tm, int x, int y)
{
    u16 * out = tm + y_tm * 0x40 + x_tm * 2;
    u16 * tiles = sTilesetInfo + gMapMetatiles[y][x];

    u16 tileref = TILEREF(0, gMapFog[y][x] ? BGPAL_TILESET : BGPAL_TILESET + 5);

    out[TM_OFFSET(0, 0)] = tileref + *tiles++;
    out[TM_OFFSET(1, 0)] = tileref + *tiles++;
    out[TM_OFFSET(0, 1)] = tileref + *tiles++;
    out[TM_OFFSET(1, 1)] = tileref + *tiles++;
}

void func_fe6_08018CDC(void)
{
}

void PutLimitViewSquare(u16 * tm, int x, int y, int x_tm, int y_tm)
{
    tm = tm + 2*TM_OFFSET(x_tm, y_tm);

    if (!tm)
        func_fe6_08018CDC();

    if (gMapMovementSigned[y][x] >= 0)
    {
        tm[TM_OFFSET(0, 0)] = TILEREF(BGCHR_LIMITVIEW + 0, BGPAL_LIMITVIEW);
        tm[TM_OFFSET(1, 0)] = TILEREF(BGCHR_LIMITVIEW + 1, BGPAL_LIMITVIEW);
        tm[TM_OFFSET(0, 1)] = TILEREF(BGCHR_LIMITVIEW + 2, BGPAL_LIMITVIEW);
        tm[TM_OFFSET(1, 1)] = TILEREF(BGCHR_LIMITVIEW + 3, BGPAL_LIMITVIEW);

        return;
    }

    if (gMapRangeSigned[y][x])
    {
        if (tm[0])
        {
            tm[TM_OFFSET(0, 0)] = TILEREF(BGCHR_LIMITVIEW + 4, BGPAL_LIMITVIEW + 1);
            tm[TM_OFFSET(1, 0)] = TILEREF(BGCHR_LIMITVIEW + 5, BGPAL_LIMITVIEW + 1);
            tm[TM_OFFSET(0, 1)] = TILEREF(BGCHR_LIMITVIEW + 6, BGPAL_LIMITVIEW + 1);
            tm[TM_OFFSET(1, 1)] = TILEREF(BGCHR_LIMITVIEW + 7, BGPAL_LIMITVIEW + 1);

            return;
        }
        else
        {
            tm[TM_OFFSET(0, 0)] = TILEREF(BGCHR_LIMITVIEW + 0, BGPAL_LIMITVIEW + 1);
            tm[TM_OFFSET(1, 0)] = TILEREF(BGCHR_LIMITVIEW + 1, BGPAL_LIMITVIEW + 1);
            tm[TM_OFFSET(0, 1)] = TILEREF(BGCHR_LIMITVIEW + 2, BGPAL_LIMITVIEW + 1);
            tm[TM_OFFSET(1, 1)] = TILEREF(BGCHR_LIMITVIEW + 3, BGPAL_LIMITVIEW + 1);

            return;
        }
    }

    tm[TM_OFFSET(0, 0)] = 0;
    tm[TM_OFFSET(1, 0)] = 0;
    tm[TM_OFFSET(0, 1)] = 0;
    tm[TM_OFFSET(1, 1)] = 0;
}

void RenderMap(void)
{
    int ix, iy;

    gBmSt.map_render_anchor.x = gBmSt.camera.x >> 4;
    gBmSt.map_render_anchor.y = gBmSt.camera.y >> 4;

    for (iy = (10 - 1); iy >= 0; --iy)
        for (ix = (15 - 1); ix >= 0; --ix)
            PutMapMetatile(gBg3Tm, ix, iy, gBmSt.map_render_anchor.x + ix, gBmSt.map_render_anchor.y + iy);

    EnableBgSync(BG3_SYNC_BIT);
    SetBgOffset(3, 0, 0);

    SetDispEnable(1, 1, 1, 1, 1);
}

void RenderMapForFade(void)
{
    int ix, iy;

    SetBgChrOffset(2, BGCHR_TILESET_A * CHR_SIZE);

    gBmSt.map_render_anchor.x = gBmSt.camera.x >> 4;
    gBmSt.map_render_anchor.y = gBmSt.camera.y >> 4;

    for (iy = (10 - 1); iy >= 0; --iy)
        for (ix = (15 - 1); ix >= 0; --ix)
            PutMapMetatile(gBg2Tm, ix, iy, gBmSt.map_render_anchor.x + ix, gBmSt.map_render_anchor.y + iy);

    EnableBgSync(BG2_SYNC_BIT);
    SetBgOffset(2, 0, 0);
}

void UpdateRenderMap(void)
{
    if (gBmSt.camera.x != gBmSt.camera_previous.x)
    {
        if (gBmSt.camera.x > gBmSt.camera_previous.x)
        {
            if (((gBmSt.camera.x - 1) ^ (gBmSt.camera_previous.x - 1)) & 0x10)
                RenderMapColumn(15);
        }
        else
        {
            if ((gBmSt.camera.x ^ gBmSt.camera_previous.x) & 0x10)
                RenderMapColumn(0);
        }
    }

    if (gBmSt.camera.y != gBmSt.camera_previous.y)
    {
        if (gBmSt.camera.y > gBmSt.camera_previous.y)
        {
            if (((gBmSt.camera.y - 1) ^ (gBmSt.camera_previous.y - 1)) & 0x10)
                RenderMapLine(10);
        }
        else
        {
            if ((gBmSt.camera.y ^ gBmSt.camera_previous.y) & 0x10)
                RenderMapLine(0);
        }
    }

    gBmSt.camera_previous = gBmSt.camera;

    SetBgOffset(3,
        gBmSt.camera.x - (u16) gBmSt.map_render_anchor.x*16,
        gBmSt.camera.y - (u16) gBmSt.map_render_anchor.y*16);

    if (gBmSt.flags & BM_FLAG_LIMITVIEW)
    {
        SetBgOffset(2,
            gBmSt.camera.x - (u16) gBmSt.map_render_anchor.x*16,
            gBmSt.camera.y - (u16) gBmSt.map_render_anchor.y*16);
    }
}

void RenderMapColumn(u16 x_offset)
{
    u16 x = (gBmSt.camera.x >> 4) + x_offset;
    u16 y = (gBmSt.camera.y >> 4);

    u16 x_tm = ((gBmSt.camera.x >> 4) - (u16) gBmSt.map_render_anchor.x + x_offset) & 0xF;
    u16 y_tm = ((gBmSt.camera.y >> 4) - (u16) gBmSt.map_render_anchor.y);

    int iy;

    if (!(gBmSt.flags & BM_FLAG_LIMITVIEW))
    {
        for (iy = 10; iy >= 0; --iy)
        {
            PutMapMetatile(gBg3Tm,
                x_tm, (y_tm + iy) & 0xF, x, (y + iy));
        }

        EnableBgSync(BG3_SYNC_BIT);
    }
    else
    {
        for (iy = 10; iy >= 0; --iy)
        {
            PutMapMetatile(gBg3Tm,
                x_tm, (y_tm + iy) & 0xF, x, (y + iy));

            PutLimitViewSquare(gBg2Tm,
                x, (y + iy), x_tm, (y_tm + iy) & 0xF);
        }

        EnableBgSync(BG2_SYNC_BIT + BG3_SYNC_BIT);
    }
}

void RenderMapLine(u16 y_offset)
{
    u16 x = (gBmSt.camera.x >> 4);
    u16 y = (gBmSt.camera.y >> 4) + y_offset;

    u16 x_tm = ((gBmSt.camera.x >> 4) - (u16) gBmSt.map_render_anchor.x);
    u16 y_tm = ((gBmSt.camera.y >> 4) - (u16) gBmSt.map_render_anchor.y + y_offset) & 0xF;

    int ix;

    if (!(gBmSt.flags & BM_FLAG_LIMITVIEW))
    {
        for (ix = 15; ix >= 0; --ix)
        {
            PutMapMetatile(gBg3Tm,
                (x_tm + ix) & 0xF, y_tm, (x + ix), y);
        }

        EnableBgSync(BG3_SYNC_BIT);
    }
    else
    {
        for (ix = 15; ix >= 0; --ix)
        {
            PutMapMetatile(gBg3Tm,
                (x_tm + ix) & 0xF, y_tm, (x + ix), y);

            PutLimitViewSquare(gBg2Tm,
                (x + ix), y, (x_tm + ix) & 0xF, y_tm);
        }

        EnableBgSync(BG2_SYNC_BIT + BG3_SYNC_BIT);
    }
}

void RefreshEntityMaps(void)
{
    struct Unit * unit;
    int i;

    MapFill(gMapUnit, 0);
    MapFill(gMapFog, gPlaySt.vision == 0 ? 1 : 0);
    MapFill(gMapHidden, 0);

    SetWorkingMap(gMapFog);

    // 1. Blue & Green units

    for (i = 1; i < FACTION_RED; ++i)
    {
        unit = GetUnit(i);

        if (!unit)
            continue;

        if (!unit->pinfo)
            continue;

        if (unit->flags & UNIT_FLAG_HIDDEN)
            continue;

        // Put unit on unit map
        gMapUnit[unit->y][unit->x] = i;

        // If fog is enabled, apply unit vision to fog map
        if (gPlaySt.vision != 0)
            MapAddInRange(unit->x, unit->y, GetUnitVision(unit), +1);
    }

    // 2. Red (& Purple) units

    if (gPlaySt.faction != FACTION_RED)
    {
        // 2.1. No red phase

        for (i = FACTION_RED + 1; i < FACTION_PURPLE + 6; ++i)
        {
            unit = GetUnit(i);

            if (!unit)
                continue;

            if (!unit->pinfo)
                continue;

            if (unit->flags & UNIT_FLAG_HIDDEN)
                continue;

            if (gPlaySt.vision != 0 && !gMapFog[unit->y][unit->x])
            {
                // If in fog, set unit bit on the hidden map, and set the "hidden in fog" flag

                gMapHidden[unit->y][unit->x] = 1;
                unit->flags |= UNIT_FLAG_CONCEALED;
            }
            else
            {
                // If not in fog, put unit on the map, and update flags accordingly

                gMapUnit[unit->y][unit->x] = i;

                if (unit->flags & UNIT_FLAG_CONCEALED)
                {
                    unit->flags &= ~UNIT_FLAG_CONCEALED;
                    unit->flags |= UNIT_FLAG_MAPFADE;
                }
            }
        }
    }
    else
    {
        // 2.2. Yes red phase

        // This does mostly the same as the "No red phase" loop, except:
        // - It always puts the units on the unit map
        // - It never sets the "spotted" unit flag (even if unit is seen)

        for (i = FACTION_RED + 1; i < FACTION_PURPLE + 6; ++i)
        {
            unit = GetUnit(i);

            if (!unit)
                continue;

            if (!unit->pinfo)
                continue;

            if (unit->flags & UNIT_FLAG_HIDDEN)
                continue;

            if (gPlaySt.vision)
            {
                // Update unit flags according to fog level

                if (!gMapFog[unit->y][unit->x])
                    unit->flags |= UNIT_FLAG_CONCEALED;
                else
                    unit->flags &= ~UNIT_FLAG_CONCEALED;
            }

            // Put on unit map
            gMapUnit[unit->y][unit->x] = i;
        }
    }
}

char const * GetTerrainName(int terrain)
{
    return TerrainNameStringTable[terrain];
}

int GetTerrainHealAmount(int terrain)
{
    return TerrainHealAmountTable[terrain];
}

bool DoesTerrainHealStatus(int terrain)
{
    return TerrainHealsStatusTable[terrain];
}

void func_fe6_080192E4(void)
{
    u16 const * tile = sTilesetInfo;

    SetBlankChr(BGCHR_TILESET_A + (*tile++ & 0x3FF));
    SetBlankChr(BGCHR_TILESET_A + (*tile++ & 0x3FF));
    SetBlankChr(BGCHR_TILESET_A + (*tile++ & 0x3FF));
    SetBlankChr(BGCHR_TILESET_A + (*tile++ & 0x3FF));

    SetBackdropColor(RGB(0, 24, 16));
}
