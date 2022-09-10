#pragma once

#include "common.h"

enum
{
    // window_theme (including PlaySt::config_window_theme)

    UI_WINDOW_THEME_BLUE,
    UI_WINDOW_THEME_RED,
    UI_WINDOW_THEME_GRAY,
    UI_WINDOW_THEME_GREEN,
};

enum
{
    // PutUiWindowFrame param window_kind

    UI_WINDOW_REGULAR,
    UI_WINDOW_FILL,
    UI_WINDOW_SABLE,
};

void ApplyUiWindowFramePal(int palid);
void UnpackUiWindowFrameImg(void * vram);
void ApplyUiStatBarPal(int palid);
void UnpackUiWindowFrameGraphics2(int window_theme);
void PutUiWindowFrame(int x, int y, int width, int height, int window_kind);
void PutUiHand(int x, int y);
void PutFrozenUiHand(int x, int y);
int GetUiHandPrevX(void);
int GetUiHandPrevY(void);
void ClearUi(void);
void PutUiEntryHover(int x, int y, int width);
void RemoveUiEntryHover(int x, int y, int width);
void UnpackUiUnitNameFrameGraphics(void * vram, int palid, int palcount);
void UnpackUiWindowFrameGraphics(void);
