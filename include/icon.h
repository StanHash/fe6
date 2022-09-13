#pragma once

#include "gba/gba.h"

void InitIcons(void);
void ClearIcons(void);
void ApplyIconPalettes(int palid);
void ApplyIconPalette(int num, int palid);
void PutIcon(u16 * tm, int icon, int tileref);
void ClearIcon(int icon);
void PutIconObjImg(int icon, int chr);
