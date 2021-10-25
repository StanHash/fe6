#pragma once

#include "gba/gba.h"

enum
{
    // TODO: IRQ constants

    IRQ_VBLANK = 0,
    IRQ_HBLANK = 1,
    IRQ_VCOUNT = 2,

    IRQ_COUNT = 14,
};

typedef void(*IrqFunc)(void);

void IrqMain(void);

void IrqInit(void);
void SetIrqFunc(int num, IrqFunc func);
