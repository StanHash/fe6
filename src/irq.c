#include "irq.h"

extern IrqFunc gIrqFuncs[INT_COUNT];
extern u32 IntrMainRam[0x200];

static void DummyFunc(void);

void IrqInit(void)
{
    int i;

    for (i = 0; i < INT_COUNT; ++i)
        gIrqFuncs[i] = DummyFunc;

    CpuFastCopy(IrqMain, IntrMainRam, sizeof IntrMainRam);
    INTR_VECTOR = IntrMainRam;
}

static void DummyFunc(void)
{
}

void SetIrqFunc(int num, IrqFunc func)
{
    gIrqFuncs[num] = func;
}
