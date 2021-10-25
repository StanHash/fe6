
#include "unit-rearrange.h"

#include "unit.h"

static struct Unit* EWRAM_DATA sUnitBuf = NULL;
static struct Unit* EWRAM_DATA sUnitBufIt = NULL;
static u8 EWRAM_DATA sNextId = 0;

void UnitRearrangeInit(struct Unit* buf)
{
    sUnitBuf = sUnitBufIt = buf;
    sNextId = 1;
}

void UnitRearrangeAdd(struct Unit* unit)
{
    sUnitBufIt->pinfo = NULL;
    CopyUnit(unit, sUnitBufIt);
    sUnitBufIt->id = sNextId;

    unit->max_hp = 0;

    sNextId++;
    sUnitBufIt++;
}

void UnitRearrangeApply(void)
{
    int i;

    for (i = 0; i < UNIT_AMOUNT_BLUE; ++i)
        ClearUnit(gUnitArrayBlue + i);

    CpuCopy16(sUnitBuf, gUnitArrayBlue, ((int) sUnitBufIt) - ((int) sUnitBuf));
}

void UnitRearrangeApply2(void)
{
    int i;

    for (i = 0; i < UNIT_AMOUNT_BLUE; ++i)
        ClearUnit(gUnitArrayBlue + i);

    CpuCopy16(sUnitBuf, gUnitArrayBlue, ((int) sUnitBufIt) - ((int) sUnitBuf));
}
