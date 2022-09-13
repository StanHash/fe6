#pragma once

#include "gba/gba.h"

enum
{
    // TODO: INT constants

    INT_VBLANK = 0,
    INT_HBLANK = 1,
    INT_VCOUNT = 2,

    INT_COUNT = 14,
};

typedef void (* IrqFunc)(void);

void IrqMain(void);

void IrqInit(void);
void SetIrqFunc(int num, IrqFunc func);
