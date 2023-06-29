#include "minimap.h"

#include <string.h>

#include "armfunc.h"
#include "oam.h"
#include "hardware.h"
#include "sound.h"
#include "proc.h"
#include "util.h"
#include "map.h"
#include "ui.h"

#include "constants/terrains.h"
#include "constants/songs.h"
#include "constants/videoalloc_global.h"

// TODO: those are in this file, part of the ewram overlay
extern i16 gMinimapWinBuf[320 * 2];
extern i16 * gMinimapFrontWinBuf;
extern i16 * gMinimapBackWinBuf;
extern i16 * gMinimapDisplayedWinBuf;
extern u16 * gMinimapObjectFlashPal;

// TODO: those are in this file, rodata
extern u8 const gUnk_083273E4[]; // lz
extern u16 const gUnk_083277BC[]; // pal
extern u16 const gUnk_083277DC[]; // pal

int GetMinimapConnectKindAt(int x, int y)
{
    int result = 0;
    int terrain = gMapTerrain[y][x];

    if (gMapTerrain[y + 1][x] == terrain)
        result += 1;

    result *= 2;

    if (gMapTerrain[y - 1][x] == terrain)
        result += 1;

    result *= 2;

    if (gMapTerrain[y][x + 1] == terrain)
        result += 1;

    result *= 2;

    if (gMapTerrain[y][x - 1] == terrain)
        result += 1;

    return result;
}

int GetMinimapRiverKindAt(int x, int y)
{
    int result = 0;

#   define IS_WATER_TERRAIN(terrain) ( \
        (terrain) == TERRAIN_RIVER || \
        (terrain) == TERRAIN_SEA || \
        (terrain) == TERRAIN_LAKE || \
        (terrain) == TERRAIN_BRIDGE)

    if (IS_WATER_TERRAIN(gMapTerrain[y + 1][x]))
        result += 1;

    result *= 2;

    if (IS_WATER_TERRAIN(gMapTerrain[y - 1][x]))
        result += 1;

    result *= 2;

    if (IS_WATER_TERRAIN(gMapTerrain[y][x + 1]))
        result += 1;

    result *= 2;

    if (IS_WATER_TERRAIN(gMapTerrain[y][x - 1]))
        result += 1;

#   undef IS_WATER_TERRAIN

    return result;
}

int GetMinimapCliffKindAt(int x, int y)
{
    int terrain = gMapTerrain[y][x];

    if ((gMapTerrain[y][x - 1] == terrain) || (gMapTerrain[y][x + 1] == terrain))
    {
        if ((gMapTerrain[y - 1][x] == TERRAIN_SEA) || (gMapTerrain[y - 1][x] == TERRAIN_LAKE))
            return 0x04;

        if ((gMapTerrain[y + 1][x] == TERRAIN_SEA) || (gMapTerrain[y + 1][x] == TERRAIN_LAKE))
            return 0x00;

        if (gMapTerrain[y - 1][x] == TERRAIN_DESERT)
            return 0x0C;

        return 0x08;
    }

    if ((gMapTerrain[y - 1][x] == terrain) || (gMapTerrain[y + 1][x] == terrain))
    {
        if ((gMapTerrain[y][x + 1] == TERRAIN_SEA) || (gMapTerrain[y][x + 1] == TERRAIN_LAKE))
            return 0x02;

        if ((gMapTerrain[y][x - 1] == TERRAIN_SEA) || (gMapTerrain[y][x - 1] == TERRAIN_LAKE))
            return 0x06;

        if (gMapTerrain[y][x + 1] == TERRAIN_DESERT)
            return 0x0D;

        return 0x09;
    }

    if ((gMapTerrain[y + 1][x - 1] == terrain) || (gMapTerrain[y - 1][x + 1] == terrain))
    {
        if ((gMapTerrain[y - 1][x - 1] == TERRAIN_SEA) || (gMapTerrain[y - 1][x - 1] == TERRAIN_LAKE))
            return 0x05;

        if ((gMapTerrain[y + 1][x + 1] == TERRAIN_SEA) || (gMapTerrain[y + 1][x + 1] == TERRAIN_LAKE))
            return 0x01;

        if (gMapTerrain[y - 1][x - 1] == TERRAIN_DESERT)
            return 0x0E;

        return 0x0A;
    }

    if ((gMapTerrain[y + 1][x + 1] == terrain) || (gMapTerrain[y - 1][x - 1] == terrain))
    {
        if ((gMapTerrain[y - 1][x + 1] == TERRAIN_SEA) || (gMapTerrain[y - 1][x + 1] == TERRAIN_LAKE))
            return 0x03;

        if ((gMapTerrain[y + 1][x - 1] == TERRAIN_SEA) || (gMapTerrain[y + 1][x - 1] == TERRAIN_LAKE))
            return 0x07;

        if (gMapTerrain[y - 1][x + 1] == TERRAIN_DESERT)
            return 0x0F;

        return 0x0B;
    }

    return 0x08;
}

int GetMinimapStairTileAt(int x, int y)
{
    if (gMapTerrain[y - 1][x] == TERRAIN_STAIRS ||
        gMapTerrain[y + 1][x] == TERRAIN_STAIRS ||
        gMapTerrain[y][x - 1] == TERRAIN_STAIRS ||
        gMapTerrain[y][x + 1] == TERRAIN_STAIRS)
    {
        return 0x12;
    }

    return 0x11;
}

int GetMinimapDoorTileAt(int x, int y)
{
    if (gMapTerrain[y][x + 1] == TERRAIN_DOOR)
        return 0x16;

    if (gMapTerrain[y][x - 1] == TERRAIN_DOOR)
        return 0x17;

    return 0x07;
}

int GetMinimapBridgeKindAt(int x, int y)
{
    if ((gMapTerrain[y][x + 1] == TERRAIN_BRIDGE) || (gMapTerrain[y][x - 1] == TERRAIN_BRIDGE))
        return 0x10;

    if ((gMapTerrain[y + 1][x] == TERRAIN_BRIDGE) || (gMapTerrain[y - 1][x] == TERRAIN_BRIDGE))
        return 0x18;

    if ((gMapTerrain[y][x + 1] == TERRAIN_RIVER) || (gMapTerrain[y][x - 1] == TERRAIN_RIVER))
        return 0x18;

    if ((gMapTerrain[y + 1][x] == TERRAIN_RIVER) || (gMapTerrain[y - 1][x] == TERRAIN_RIVER))
        return 0x10;

    if ((gMapTerrain[y][x + 1] == TERRAIN_LAKE) || (gMapTerrain[y][x - 1] == TERRAIN_LAKE))
        return 0x18;

    if ((gMapTerrain[y + 1][x] == TERRAIN_LAKE) || (gMapTerrain[y - 1][x] == TERRAIN_LAKE))
        return 0x10;

#if BUGFIX
    return 0x00;
#endif
}

int GetMinimapTileAt(int x, int y)
{
    switch (gMapTerrain[y][x])
    {
        case TERRAIN_TILE_00:
            return 0x00;

        case TERRAIN_PLAINS:
            return 0x01;

        case TERRAIN_ROAD:
            return 0x40 + GetMinimapConnectKindAt(x, y);

        case TERRAIN_VILLAGE:
        case TERRAIN_VILLAGE_CLOSED:
        case TERRAIN_HOUSE:
            return 0x02;

        case TERRAIN_ARMORY:
        case TERRAIN_VENDOR:
            return 0x03;

        case TERRAIN_ARENA_08:
            return 0x04;

        case TERRAIN_FORT:
            return 0x05;

        case TERRAIN_GATE_0B:
            return 0x06;

        case TERRAIN_FOREST:
            return 0x08;

        case TERRAIN_THICKET:
            return 0x09;

        case TERRAIN_SAND:
        case TERRAIN_DESERT:
            return 0x0A;

        case TERRAIN_RIVER:
            return 0x60 + GetMinimapRiverKindAt(x, y);

        case TERRAIN_MOUNTAIN:
            return 0x0B;

        case TERRAIN_PEAK:
            return 0x14;

        case TERRAIN_BRIDGE:
            return GetMinimapBridgeKindAt(x, y);

        case TERRAIN_SEA:
        case TERRAIN_LAKE:
        case TERRAIN_GLACIER:
            return 0x30 + GetMinimapConnectKindAt(x, y);

        case TERRAIN_FLOOR_17:
        case TERRAIN_FLOOR_18:
            return 0x0C;

        case TERRAIN_PILLAR:
            return 0x0D;

        case TERRAIN_DOOR:
            return GetMinimapDoorTileAt(x, y);

        case TERRAIN_THRONE:
            return 0x0E;

        case TERRAIN_CHEST:
        case TERRAIN_CHEST_OPENED:
            return 0x0F;

        case TERRAIN_RUINS:
            return 0x1A;

        case TERRAIN_CLIFF:
            return 0x50 + GetMinimapCliffKindAt(x, y);

        case TERRAIN_BALLISTA:
        case TERRAIN_LONGBALLISTA:
        case TERRAIN_KILLERBALLISTA:
            return 0x13;

        case TERRAIN_SHIP_FLAT:
            return 0x3A;

        case TERRAIN_STAIRS:
            return GetMinimapStairTileAt(x, y);

        case TERRAIN_FENCE_19:
        case TERRAIN_WALL:
        case TERRAIN_WALL_BREAKABLE:
        case TERRAIN_RUBBLE:
        case TERRAIN_ROOF:
        case TERRAIN_SHIP_WRECK:
        case TERRAIN_TILE_2C:
        case TERRAIN_TILE_2E:
            return 0x20 + GetMinimapConnectKindAt(x, y);

        case TERRAIN_VALLEY:
            return 0x19;

        default:
            return 0x00;
    }
}

u16 * GetMinimapTerrainCellAt(int x, int y)
{
    return (u16 *) (gBuf + GetMinimapTileAt(x, y) * 0x20);
}

u16 * GetMinimapObjectCellAt(int x, int y)
{
    int unit_id;

    SHOULD_BE_STATIC u8 SHOULD_BE_CONST unk_0832785C[3] =
    {
        0x1D, 0x1F, 0x1E,
    };

    unit_id = gMapUnit[y][x];

    if (unit_id == 0)
        return (u16 *) (gBuf);
    else
        return (u16 *) (gBuf + (unk_0832785C[unit_id >> 6] * 0x20));
}

void DrawMinimapInternal(u16 * vram, int pal_num)
{
    int iy, ix;
    int chr;

    if (vram == NULL)
        vram = (void *) (VRAM + BGCHR_MINIMAP * 0x20);

    chr = ((u32) vram << 15) >> 20;

    if (pal_num < 0)
        pal_num = BGPAL_MINIMAP_TERRAIN;

    for (iy = 0; iy < gMapSize.y; iy += 2)
    {
        for (ix = 0; ix < gMapSize.x; ix += 2)
        {
            u16 * iter_a = GetMinimapTerrainCellAt(ix, iy);
            u16 * iter_b = GetMinimapTerrainCellAt(ix + 1, iy);

            *vram++ = *iter_a;
            iter_a += 2;

            *vram++ = *iter_b;
            iter_b += 2;

            *vram++ = *iter_a;
            iter_a += 2;

            *vram++ = *iter_b;
            iter_b += 2;

            *vram++ = *iter_a;
            iter_a += 2;

            *vram++ = *iter_b;
            iter_b += 2;

            *vram++ = *iter_a;
            iter_a += 2;

            *vram++ = *iter_b;
            iter_b += 2;

            iter_a = GetMinimapTerrainCellAt(ix, iy + 1);
            iter_b = GetMinimapTerrainCellAt(ix + 1, iy + 1);

            *vram++ = *iter_a;
            iter_a += 2;

            *vram++ = *iter_b;
            iter_b += 2;

            *vram++ = *iter_a;
            iter_a += 2;

            *vram++ = *iter_b;
            iter_b += 2;

            *vram++ = *iter_a;
            iter_a += 2;

            *vram++ = *iter_b;
            iter_b += 2;

            *vram++ = *iter_a;
            iter_a += 2;

            *vram++ = *iter_b;
            iter_b += 2;

            gBg1Tm[TM_OFFSET((ix / 2), (iy / 2))] = TILEREF(chr, pal_num);

            chr++;

            if ((gMapUnit[iy][ix] != 0) || (gMapUnit[iy][ix + 1] != 0) ||
                (gMapUnit[iy + 1][ix] != 0) || (gMapUnit[iy + 1][ix + 1] != 0))
            {
                iter_a = GetMinimapObjectCellAt(ix, iy);
                iter_b = GetMinimapObjectCellAt(ix + 1, iy);

                *vram++ = *iter_a;
                iter_a += 2;

                *vram++ = *iter_b;
                iter_b += 2;

                *vram++ = *iter_a;
                iter_a += 2;

                *vram++ = *iter_b;
                iter_b += 2;

                *vram++ = *iter_a;
                iter_a += 2;

                *vram++ = *iter_b;
                iter_b += 2;

                *vram++ = *iter_a;
                iter_a += 2;

                *vram++ = *iter_b;
                iter_b += 2;

                iter_a = GetMinimapObjectCellAt(ix, iy + 1);
                iter_b = GetMinimapObjectCellAt(ix + 1, iy + 1);

                *vram++ = *iter_a;
                iter_a += 2;

                *vram++ = *iter_b;
                iter_b += 2;

                *vram++ = *iter_a;
                iter_a += 2;

                *vram++ = *iter_b;
                iter_b += 2;

                *vram++ = *iter_a;
                iter_a += 2;

                *vram++ = *iter_b;
                iter_b += 2;

                *vram++ = *iter_a;
                iter_a += 2;

                *vram++ = *iter_b;
                iter_b += 2;

                gBg0Tm[TM_OFFSET((ix / 2), (iy / 2))] = TILEREF(chr, (pal_num + 1));

                chr++;
            }
        }
    }
}

void Minimap_Init(struct MinimapProc * proc)
{
    PlaySe(SONG_78);
    Minimap_InitProcVars(proc);
    ApplyMinimapGraphics(-1);
    DrawMinimapInternal(NULL, -1);
    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);
}

void MinimapOnHBlank(void)
{
    u16 vcount = REG_VCOUNT + 1;

    if (vcount > DISPLAY_HEIGHT)
    {
        gMinimapDisplayedWinBuf = gMinimapFrontWinBuf;
        vcount = 0;
    }

    REG_WIN0H = WIN_RANGE(gMinimapDisplayedWinBuf[vcount * 2], gMinimapDisplayedWinBuf[vcount * 2 + 1]);
}

void InitMinimapWindowBuffers(void)
{
    u16 * tmp = gMinimapFrontWinBuf;
    gMinimapFrontWinBuf = gMinimapBackWinBuf;
    gMinimapBackWinBuf = tmp;
}

void Minimap_InitOpenAnim(struct MinimapProc * proc)
{
    gMinimapFrontWinBuf = gMinimapWinBuf + 320;
    gMinimapBackWinBuf = gMinimapWinBuf;
    gMinimapDisplayedWinBuf = gMinimapWinBuf + 320;

    SetWinEnable(1, 0, 0);
    SetWin0Layers(1, 1, 1, 1, 1);
    SetWOutLayers(0, 0, 1, 1, 1);

    SetWin0Box(DISPLAY_WIDTH, 0, 0, DISPLAY_HEIGHT);

    SetBlendTargetA(0, 0, 1, 1, 0);
    SetBlendTargetB(1, 1, 1, 1, 1);
    SetBlendBackdropB(1);

    SetBlendConfig(BLEND_EFFECT_DARKEN, 0x10, 0, 0);

    gDispIo.win_ct.win0_enable_blend = 1;
    gDispIo.win_ct.win1_enable_blend = 1;
    gDispIo.win_ct.wout_enable_blend = 1;

    proc->anim_clock = 0;

    SetOnHBlankA(MinimapOnHBlank);
}

void Minimap_OpenAnim(struct MinimapProc * proc)
{
    int unk;
    int i;
    int angle;
    struct Vec2i arr[4];

    SetBlendConfig(BLEND_EFFECT_DARKEN, 0x10, 0, proc->anim_clock / 4);

    unk = Interpolate(INTERPOLATE_RCUBIC, 0, 0x100, proc->anim_clock, 0x10);

    angle = unk / 4 - 0x40;

    arr[0].x = -proc->x_region_radius;
    arr[0].y = -proc->y_region_radius;

    arr[1].x = +proc->x_region_radius;
    arr[1].y = -proc->y_region_radius;

    arr[2].x = +proc->x_region_radius;
    arr[2].y = +proc->y_region_radius;

    arr[3].x = -proc->x_region_radius;
    arr[3].y = +proc->y_region_radius;

    for (i = 0; i < 4; i++)
    {
        int a1, a2;

        a1 = (COS_Q12(angle) * arr[i].x) - (SIN_Q12(angle) * arr[i].y);
        a2 = (SIN_Q12(angle) * arr[i].x) + (COS_Q12(angle) * arr[i].y);

        arr[i].x = ((a1 * unk) >> 20) + 120;
        arr[i].y = ((a2 * unk) >> 20) + 80;
    }

    func_fe6_08013EE4(gMinimapBackWinBuf);

    func_fe6_08013F04(gMinimapBackWinBuf, arr[0].x, arr[0].y, arr[1].x, arr[1].y);
    func_fe6_08013F04(gMinimapBackWinBuf, arr[1].x, arr[1].y, arr[2].x, arr[2].y);
    func_fe6_08013F04(gMinimapBackWinBuf, arr[2].x, arr[2].y, arr[3].x, arr[3].y);
    func_fe6_08013F04(gMinimapBackWinBuf, arr[3].x, arr[3].y, arr[0].x, arr[0].y);

    InitMinimapWindowBuffers();

    proc->anim_clock++;

    if (proc->anim_clock > 0x10)
        Proc_Break(proc);
}

void Minimap_InitCloseAnim(struct MinimapProc * proc)
{
    PlaySe(SONG_79);

    SetBlendTargetA(0, 0, 1, 1, 0);
    SetBlendTargetB(1, 1, 1, 1, 1);

    SetBlendConfig(BLEND_EFFECT_DARKEN, 0x10, 0, 4);

    gMinimapFrontWinBuf = gMinimapWinBuf + 320;
    gMinimapBackWinBuf = gMinimapWinBuf;
    gMinimapDisplayedWinBuf = gMinimapWinBuf + 320;

    proc->anim_clock = 0;
}

void Minimap_CloseAnim(struct MinimapProc * proc)
{
    int unk;
    int i;
    int angle;
    struct Vec2i arr[4];

    SetBlendConfig(BLEND_EFFECT_DARKEN, 0x10, 0, 4 - proc->anim_clock / 4);

    unk = Interpolate(INTERPOLATE_CUBIC, 0x100, 0, proc->anim_clock, 0x10);

    angle = 0x40 - unk / 4;

    arr[0].x = -proc->x_region_radius;
    arr[0].y = -proc->y_region_radius;

    arr[1].x = +proc->x_region_radius;
    arr[1].y = -proc->y_region_radius;

    arr[2].x = +proc->x_region_radius;
    arr[2].y = +proc->y_region_radius;

    arr[3].x = -proc->x_region_radius;
    arr[3].y = +proc->y_region_radius;

    for (i = 0; i < 4; i++)
    {
        int a1, a2;

        a1 = (COS_Q12(angle) * arr[i].x) - (SIN_Q12(angle) * arr[i].y);
        a2 = (SIN_Q12(angle) * arr[i].x) + (COS_Q12(angle) * arr[i].y);

        arr[i].x = ((a1 * unk) >> 20) + 120;
        arr[i].y = ((a2 * unk) >> 20) + 80;
    }

    func_fe6_08013EE4(gMinimapBackWinBuf);

    func_fe6_08013F04(gMinimapBackWinBuf, arr[0].x, arr[0].y, arr[1].x, arr[1].y);
    func_fe6_08013F04(gMinimapBackWinBuf, arr[1].x, arr[1].y, arr[2].x, arr[2].y);
    func_fe6_08013F04(gMinimapBackWinBuf, arr[2].x, arr[2].y, arr[3].x, arr[3].y);
    func_fe6_08013F04(gMinimapBackWinBuf, arr[3].x, arr[3].y, arr[0].x, arr[0].y);

    InitMinimapWindowBuffers();

    proc->anim_clock++;

    if (proc->anim_clock > 0x10)
        Proc_Break(proc);
}

void ApplyMinimapGraphics(int pal_num)
{
    if (pal_num < 0)
        pal_num = BGPAL_MINIMAP_TERRAIN;

    Decompress(gUnk_083273E4, gBuf);

    ApplyPalette(gUnk_083277BC, pal_num);
    ApplyPalette(gUnk_083277DC, pal_num + 1);
}

void InitMinimapFlashPalette(void)
{
    int pal_num, color_num;

    gMinimapObjectFlashPal = (u16 *) gBuf;

    for (color_num = 1; color_num < 16; color_num++)
    {
        int color = gPal[BGPAL_MINIMAP_OBJECTS * 0x10 + color_num];

        int r_component = RGB_GET_RED(color);
        int g_component = RGB_GET_GREEN(color);
        int b_component = RGB_GET_BLUE(color);

        for (pal_num = 0; pal_num < 8; pal_num++)
        {
            gMinimapObjectFlashPal[color_num + 0x10 * pal_num] = ((b_component << 10) + (g_component << 5)) + r_component;

            r_component += 3;

            if (r_component > 31)
                r_component = 31;

            g_component += 3;

            if (g_component > 31)
                g_component = 31;

            b_component += 3;

            if (b_component > 31)
                b_component = 31;
        }
    }
}

void Minimap_ApplyFlashPalette(struct MinimapProc * proc)
{
    SHOULD_BE_STATIC u8 SHOULD_BE_CONST unk_0832785F[]=
    {
        0x0, 0x4, 0x7, 0x6,
        0x5, 0x4, 0x3, 0x2,
        0x2, 0x1, 0x1, 0x1,
        0x0, 0x0, 0x0, 0x0,
    };

    u8 idx = unk_0832785F[(GetGameTime() >> 2) % sizeof(unk_0832785F)];

    ApplyPalette(gMinimapObjectFlashPal + idx * 0x10, BGPAL_MINIMAP_OBJECTS);
}

void Minimap_ApplyViewportFlashColor(struct MinimapProc * proc)
{
    u32 r, g, b;
    u32 idx;

#if NONMATCHING
    u32 component;
#else
    u32 register component asm("r3");
#endif

    SHOULD_BE_STATIC u8 SHOULD_BE_CONST unk_0832786F[] =
    {
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
        0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
        0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08,
        0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00,
    };

    idx = unk_0832786F[GetGameTime() % sizeof(unk_0832786F)];
    component = idx + 0x10;

    r = component;
    g = component;
    b = component;

    gPal[(0x10 + OBJPAL_SYSTEM_OBJECTS) * 0x10 + 0x0E] = (b << 10) + (g << 5) + r;

    EnablePalSync();
}

void Minimap_PutViewport(struct MinimapProc * proc)
{
    int x_screen, y_screen;

    SHOULD_BE_STATIC u16 SHOULD_BE_CONST viewport_sprite[] =
    {
        4,
        OAM0_SHAPE_8x8 + OAM0_Y(-1), OAM1_SIZE_8x8 + OAM1_X(-1), OAM2_CHR(0x28),
        OAM0_SHAPE_8x8 + OAM0_Y(-1), OAM1_SIZE_8x8 + OAM1_X(53) + OAM1_HFLIP, OAM2_CHR(0x28),
        OAM0_SHAPE_8x8 + OAM0_Y(33), OAM1_SIZE_8x8 + OAM1_X(-1) + OAM1_VFLIP, OAM2_CHR(0x28),
        OAM0_SHAPE_8x8 + OAM0_Y(33), OAM1_SIZE_8x8 + OAM1_X(53) + OAM1_HFLIP + OAM1_VFLIP, OAM2_CHR(0x28),
    };

    x_screen = proc->x_screen + gBmSt.camera.x / 4;
    y_screen = proc->y_screen + gBmSt.camera.y / 4;

    PutOamHi(x_screen, y_screen, viewport_sprite, 0);
}

void Minimap_AdjustDisplay(struct MinimapProc * proc)
{
    int x, y;

    x = (DISPLAY_WIDTH - (gMapSize.x * 4)) >> 1;
    y = (DISPLAY_HEIGHT - (gMapSize.y * 4)) >> 1;

    if (gMapSize.y * 4 > DISPLAY_HEIGHT - 16)
    {
        y = gMapSize.y * 4 - DISPLAY_HEIGHT + 16;
        y = ((gBmSt.camera.y * 0x10000) / gBmSt.camera_max.y) * y / 0x10000;
        y = 8 - y;
    }

    proc->x_screen = x;
    proc->y_screen = y;

    SetBgOffset(0, -x, -y);
    SetBgOffset(1, -x, -y);
}

void Minimap_HandleMoveInput(struct MinimapProc * proc)
{
    int x, y;

    x = gBmSt.camera.x;
    y = gBmSt.camera.y;

    if (((x % 0x10) == 0) && ((y % 0x10) == 0))
    {
        proc->x_camera_speed = 0;
        proc->y_camera_speed = 0;

        if ((gKeySt->held & KEY_DPAD_LEFT) != 0)
        {
            proc->x_camera_speed = -8;
            proc->camera_moved = 1;
        }

        if ((gKeySt->held & KEY_DPAD_RIGHT) != 0)
        {
            proc->x_camera_speed = +8;
            proc->camera_moved = 1;
        }

        if ((gKeySt->held & KEY_DPAD_UP) != 0)
        {
            proc->y_camera_speed = -8;
            proc->camera_moved = 1;
        }

        if ((gKeySt->held & KEY_DPAD_DOWN) != 0)
        {
            proc->y_camera_speed = +8;
            proc->camera_moved = 1;
        }
    }

    x = x + proc->x_camera_speed;
    y = y + proc->y_camera_speed;

    if (x < 0)
        x = 0;

    if (x > gBmSt.camera_max.x)
        x = gBmSt.camera_max.x;

    if (y < 0)
        y = 0;

    if (y > gBmSt.camera_max.y)
        y = gBmSt.camera_max.y;

    gBmSt.camera.x = x;
    gBmSt.camera.y = y;
}

void Minimap_InitProcVars(struct MinimapProc * proc)
{
    proc->camera_moved = 0;
    proc->x_region_radius = gMapSize.x * 2;
    proc->y_region_radius = gMapSize.y * 2;
}

void Minimap_Fini(struct MinimapProc * proc)
{
    int x, y;

    if (proc->camera_moved != 0)
    {
        x = gBmSt.camera.x / 16 + 7;
        y = gBmSt.camera.y / 16 + 5;

        SetMapCursorPosition(x, y);
    }

    SetOnHBlankA(NULL);
}

void Minimap_Main(struct MinimapProc * proc)
{
    Minimap_ApplyFlashPalette(proc);
    Minimap_ApplyViewportFlashColor(proc);
    Minimap_AdjustDisplay(proc);
    Minimap_PutViewport(proc);
    Minimap_HandleMoveInput(proc);

    if ((gKeySt->held & (KEY_BUTTON_R | KEY_BUTTON_L)) != 0)
    {
        SetBlendTargetA(0, 1, 0, 0, 0);
        SetBlendTargetB(0, 0, 1, 1, 1);
        SetBlendConfig(BLEND_EFFECT_ALPHA, 8, 8, 0);
    }
    else
    {
        SetBlendTargetA(0, 0, 1, 1, 0);
        SetBlendTargetB(1, 1, 1, 1, 1);
        SetBlendConfig(BLEND_EFFECT_DARKEN, 16, 0, 4);
    }

    if (((gBmSt.camera.x & 0x0F) == 0) && ((gBmSt.camera.y & 0x0F) == 0))
    {
        if ((gKeySt->pressed & (KEY_BUTTON_B | KEY_BUTTON_START)) != 0)
            Proc_Break(proc);
    }
}

struct ProcScr CONST_DATA ProcScr_Minimap[] =
{
    PROC_CALL(LockGame),
    PROC_SLEEP(0),
    PROC_CALL(ClearUi),
    PROC_SLEEP(0),

    PROC_CALL(Minimap_Init),
    PROC_CALL(Minimap_AdjustDisplay),
    PROC_CALL(Minimap_InitOpenAnim),
    PROC_REPEAT(Minimap_OpenAnim),
    PROC_CALL(InitMinimapFlashPalette),
    PROC_REPEAT(Minimap_Main),
    PROC_CALL(Minimap_InitCloseAnim),
    PROC_REPEAT(Minimap_CloseAnim),
    PROC_CALL(Minimap_Fini),

    PROC_CALL(ClearUi),
    PROC_SLEEP(0),
    PROC_CALL(UnpackUiWindowFrameGraphics),
    PROC_CALL(ResetText),
    PROC_CALL(ApplySystemObjectsGraphics),
    PROC_CALL(UnlockGame),

    PROC_END,
};

void StartMinimap(void)
{
    SpawnProc(ProcScr_Minimap, PROC_TREE_3);
}

void DrawMinimap(int chapter, void * vram, int pal_num)
{
    TmFill(gBg0Tm, 0);
    TmFill(gBg1Tm, 0);

    InitMapForMinimap(chapter);
    ApplyMinimapGraphics(pal_num);
    DrawMinimapInternal(vram, pal_num);
}
