
#pragma once

#include "gba/gba.h"

void RegisterDataMove(void const* src, void* dst, int size);
void RegisterDataFill(u32 value, void* dst, int size);
void ApplyDataMoves(void);
