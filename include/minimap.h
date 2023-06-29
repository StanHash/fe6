#pragma once

#include "common.h"

#include "proc.h"

struct MinimapProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2C);
    /* 2C */ i32 x_camera_speed;
    /* 30 */ i32 y_camera_speed;
    /* 34 */ i32 x_region_radius;
    /* 38 */ i32 y_region_radius;
    /* 3C */ i32 x_screen;
    /* 40 */ i32 y_screen;
    /* 3C */ STRUCT_PAD(0x44, 0x4A);
    /* 4A */ i16 camera_moved;
    /* 4C */ i16 anim_clock;
};

int GetMinimapConnectKindAt(int x, int y);
int GetMinimapRiverKindAt(int x, int y);
int GetMinimapCliffKindAt(int x, int y);
int GetMinimapStairTileAt(int x, int y);
int GetMinimapDoorTileAt(int x, int y);
int GetMinimapBridgeKindAt(int x, int y);
int GetMinimapTileAt(int x, int y);
u16 * GetMinimapTerrainCellAt(int x, int y);
u16 * GetMinimapObjectCellAt(int x, int y);
void DrawMinimapInternal(u16 * vram, int pal_num);
void Minimap_Init(struct MinimapProc * proc);
void MinimapOnHBlank(void);
void InitMinimapWindowBuffers(void);
void Minimap_InitOpenAnim(struct MinimapProc * proc);
void Minimap_OpenAnim(struct MinimapProc * proc);
void Minimap_InitCloseAnim(struct MinimapProc * proc);
void Minimap_CloseAnim(struct MinimapProc * proc);
void ApplyMinimapGraphics(int pal_num);
void InitMinimapFlashPalette(void);
void Minimap_ApplyFlashPalette(struct MinimapProc * proc);
void Minimap_ApplyViewportFlashColor(struct MinimapProc * proc);
void Minimap_PutViewport(struct MinimapProc * proc);
void Minimap_AdjustDisplay(struct MinimapProc * proc);
void Minimap_HandleMoveInput(struct MinimapProc * proc);
void Minimap_InitProcVars(struct MinimapProc * proc);
void Minimap_Fini(struct MinimapProc * proc);
void Minimap_Main(struct MinimapProc * proc);

void StartMinimap(void);
void DrawMinimap(int chapter, void * vram, int pal_num);

extern i16 gMinimapWinBuf[320 * 2];
extern i16 * gMinimapFrontWinBuf;
extern i16 * gMinimapBackWinBuf;
extern i16 * gMinimapDisplayedWinBuf;
extern u16 * gMinimapObjectFlashPal;

extern u8 const gUnk_083273E4[];
extern u16 const gUnk_083277BC[];
extern u16 const gUnk_083277DC[];

extern struct ProcScr CONST_DATA ProcScr_Minimap[];
