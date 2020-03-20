
#pragma once

#include "gba/gba.h"

enum
{
    // TODO: IRQ constants

    IRQ_COUNT = 14,
};

typedef void(*IrqFunc)(void);

void IrqMain(void);

void IrqInit(void);
void SetIrqFunc(int num, IrqFunc func);
