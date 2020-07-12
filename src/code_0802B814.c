
#include "common.h"

#include "unit.h"
#include "map.h"

#include "constants/terrains.h"

Bool sub_802B814(void)
{
    int ix, iy;

    if (gActiveUnit->state & US_HAS_MOVED)
        return FALSE;

    for (iy = gMapSize.y-1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x-1; ix >= 0; --ix)
        {
            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if (gMapTerrain[iy][ix] != TERRAIN_VILLAGE_03 && gMapTerrain[iy][ix] != TERRAIN_HOUSE)
                continue;

            if (sub_806B028(ix, iy) == 0x0E)
                return TRUE;
        }
    }

    return FALSE;
}
