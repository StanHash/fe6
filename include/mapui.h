#pragma once

#include "common.h"

#include "proc.h"

// this proc layout is shared between all MapUi procs
// one could separate them to make room in each one if necessary
struct MapUiProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ struct Text text;
    /* 34 */ i8 x_burst;
    /* 35 */ i8 y_burst;
    /* 36 */ i8 w_burst;
    /* 37 */ i8 h_burst;
    /* 38 */ u16 * status_tm;
    /* 3C */ u16 unit_clock;
    /* 3E */ i16 hp_x;
    /* 40 */ i16 hp_y;
    /* 42 */ u8 burst_unit_id_prev;
    /* 43 */ u8 burst_unit_id;
    /* 44 */ i8 x_cursor_prev;
    /* 45 */ i8 y_cursor_prev;
    /* 46 */ i8 x_cursor;
    /* 47 */ i8 y_cursor;
    /* 48 */ i8 screen_side;
    /* 49 */ u8 hp_cur_hi;
    /* 4A */ u8 hp_cur_lo;
    /* 4B */ u8 hp_max_hi;
    /* 4C */ u8 hp_max_lo;
    /* 4D */ bool8 hide_contents;
    /* 4E */ // implicit pad
    /* 50 */ i32 show_hide_clock;
};

void PutMapUiHpBarLeft(u16 * tm, fi16 fill, int tile);
void PutMapUiHpBarMid(u16 * tm, fi16 fill, int tile);
void PutMapUiHpBarRight(u16 * tm, fi16 fill, int tile);
void PutMapUiHpBar(u16 * tm, struct Unit * unit, int tile);
void UnitMapUi_ShowLoop(struct MapUiProc * proc);
void UnitMapUi_HideLoop(struct MapUiProc * proc);
void TerrainMapUi_ShowLoop(struct MapUiProc * proc);
void TerrainMapUi_HideLoop(struct MapUiProc * proc);
void PutUnitMapUi(struct MapUiProc * proc);
void PutTerrainMapUi(struct MapUiProc * proc);
void ApplyUnitMapUiFramePal(int faction, int pal_id);
int GetUnitMapUiScreenSide(void);
int GetTerrainMapUiScreenSide(void);
void ClearUnitMapUiStatus(u16 * tm, struct Unit * unit);
void PutUnitMapUiStatus(u16 * tm, struct Unit * unit);
void UnitMapUiUpdate(struct MapUiProc * proc, struct Unit * unit);
void DrawUnitMapUi(struct MapUiProc * proc, struct Unit * unit);
int GetUnitBurstMapUiOrientationAt(int x, int y);
void DrawUnitBurstMapUi(struct MapUiProc * proc, struct Unit * unit);
void ClearUnitBurstMapUi(struct MapUiProc * proc);
void DrawTerrainMapUi(struct MapUiProc * proc);
void TerrainMapUi_Init(struct MapUiProc * proc);
void TerrainMapUi_TerrainChange(struct MapUiProc * proc);
void TerrainMapUi_Loop(struct MapUiProc * proc);
void UnitMapUi_Init(struct MapUiProc * proc);
void UnitMapUi_HiddenLoop(struct MapUiProc * proc);
void UnitMapUi_Loop(struct MapUiProc * proc);
void UnitMapUi_UnitChange(struct MapUiProc * proc);
void UnitBurstMapUi_Init(struct MapUiProc * proc);
void UnitBurstMapUi_Loop(struct MapUiProc * proc);
void DoStartMapUi(void);
void StartMapUi(void);
void EndMapUi(void);
