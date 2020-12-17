
#include "ai.h"

#include "item.h"
#include "unit.h"
#include "map.h"
#include "mapwork.h"
#include "faction.h"
#include "ai-utility.h"

static void AiFillDangerMap(void);

void AiRefreshDangerMap(void)
{
    if (!gAiSt.dangerMapFilled)
    {
        gAiSt.dangerMapFilled = TRUE;

        MapFill(gMapOther, 0);
        AiFillDangerMap();
    }
}

static void AiFillDangerMap(void)
{
    int i, j, ix, iy;

    u16 item = 0;
    u8 might = 0;

    for (i = 1; i < 0xC0; ++i)
    {
        u16 itemTmp;

        struct Unit* unit = GetUnit(i);

        if (unit == NULL)
            continue;

        if (unit->person == NULL)
            continue;

        if (unit->state & (US_HIDDEN | US_DEAD | US_NOT_DEPLOYED))
            continue;

        if (AreUnitIdsAllied(gActiveUnitId, unit->id))
            continue;

        // BUG: item needs to be set back to 0 here

        for (j = 0; (j < ITEMSLOT_INV_COUNT) && (itemTmp = unit->items[j]); ++j)
        {
            if (!CanUnitUseWeapon(unit, itemTmp))
                continue;

            if (GetItemMight(itemTmp) > might)
            {
                item = itemTmp;
                might = GetItemMight(item);
            }
        }

        if (item == 0)
            continue;

        if (!AiCouldReachByBirdsEyeDistance(gActiveUnit, unit, item))
            continue;

        AiMakeMoveRangeMapsForUnitAndWeapon(unit, item);

        for (iy = gMapSize.y-1; iy >= 0; --iy)
        {
            for (ix = gMapSize.x-1; ix >= 0; --ix)
            {
                if (gMapRangeSigned[iy][ix] == 0)
                    continue;

                gMapOther[iy][ix] += (GetUnitPower(unit) + might) >> 1;
            }
        }
    }
}

Bool AiCheckDangerAt(int x, int y, u8 threshold)
{
    if (gMapOther[y][x] > threshold)
        return FALSE;

    return TRUE;
}
