
#include "common.h"

#include "battle.h"

int sub_802D638(void)
{
    int x = gBattleUnitB.unit.x*16 - gBmSt.camera.x;

    if (x < 0x70)
        return +1;

    if (x > 0x70)
        return -1;

    return 0;
}
