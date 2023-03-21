#include "ai_utility.h"

#include "random.h"
#include "item.h"
#include "unit.h"
#include "map.h"
#include "mapwork.h"
#include "faction.h"
#include "ai_decide.h"
#include "ai_data.h"
#include "ai_battle.h"

#include "constants/iids.h"
#include "constants/terrains.h"

static struct Vec2i CONST_DATA sRange3OffsetLut[] =
{
                                        {  0, -3 },
                            { -1, -2 }, {  0, -2 }, { +1, -2 },
                { -2, -1 }, { -1, -1 }, {  0, -1 }, { +1, -1 }, { +2, -1 },
    { -3,  0 }, { -2,  0 }, { -1,  0 }, /* unit */  { +1,  0 }, { +2,  0 }, { +3,  0 },
                { -2, +1 }, { -1, +1 }, {  0, +1 }, { +1, +1 }, { +2, +1 },
                            { -1, +2 }, {  0, +2 }, { +1, +2 },
                                        {  0, +3 },

    { 9999, 9999 },
};

bool AiCompare(u8 const * left, u8 cond, u32 right)
{
    switch (cond)
    {

    case AI_COMPARE_GT:
        if (*left > right)
            return TRUE;

        break;

    case AI_COMPARE_GE:
        if (*left >= right)
            return TRUE;

        break;

    case AI_COMPARE_EQ:
        if (*left == right)
            return TRUE;

        break;

    case AI_COMPARE_LE:
        if (*left <= right)
            return TRUE;

        break;

    case AI_COMPARE_LT:
        if (*left < right)
            return TRUE;

        break;

    case AI_COMPARE_NE:
        if (*left != right)
            return TRUE;

        break;

    }

    return FALSE;
}

bool AiFindTargetInReachByPid(int pid, struct Vec2i * out)
{
    int i;

    MapFlood_080193F4(gActiveUnit->x, gActiveUnit->y, gActiveUnit->jinfo->mov_table);
    MapMarkFloodEdges();

    out->x = -1;

    for (i = 1; i < 0xC0; ++i)
    {
        struct Unit * unit = GetUnit(i);

        if (unit == NULL)
            continue;

        if (unit->pinfo == NULL)
            continue;

        if (gMapRange[unit->y][unit->x] > MAP_MOVEMENT_MAX)
            continue;

        if (unit->pinfo->id != pid)
            continue;

        if (unit->flags & UNIT_FLAG_DEAD)
            goto target_dead;

        if (unit->flags & UNIT_FLAG_RESCUED)
            gAiSt.cmd_result[0] = 3;

        out->x = unit->x;
        out->y = unit->y;
    }

    if (out->x >= 0)
        return TRUE;

    if (GetUnitByPid(pid)->flags & (UNIT_FLAG_DEAD | UNIT_FLAG_NOT_DEPLOYED))
    {
        gAiSt.cmd_result[0] = 1;
        return FALSE;
    }

    goto target_not_found;

target_dead:
    gAiSt.cmd_result[0] = 1;
    return FALSE;

target_not_found:
    gAiSt.cmd_result[0] = 4;
    return FALSE;
}

bool AiFindTargetInReachByJid(int jid, struct Vec2i * out)
{
    int i;

    u8 bestDistance = UINT8_MAX;

    MapFlood_080193F4(gActiveUnit->x, gActiveUnit->y, gActiveUnit->jinfo->mov_table);

    out->x = -1;

    for (i = 1; i < 0xC0; ++i)
    {
        struct Unit * unit = GetUnit(i);

        if (unit == NULL)
            continue;

        if (unit->pinfo == NULL)
            continue;

        if (unit->flags & (UNIT_FLAG_HIDDEN | UNIT_FLAG_DEAD | UNIT_FLAG_RESCUED))
            continue;

        if (gMapRange[unit->y][unit->x] > MAP_MOVEMENT_MAX)
            continue;

        if (unit->jinfo->id != jid)
            continue;

        if (bestDistance < gMapRangeSigned[unit->y][unit->x])
            continue;

        bestDistance = gMapRange[unit->y][unit->x];
        out->x = unit->x;
        out->y = unit->y;
    }

    if (out->x >= 0)
        return TRUE;

    return FALSE;
}

bool AiFindTargetInReachByFunc(bool (* func)(struct Unit * unit), struct Vec2i * out)
{
    short ix, iy;

    u8 bestDistance = UINT8_MAX;

    short x = 0;
    short y = 0;

    MapFlood_080193F4(gActiveUnit->x, gActiveUnit->y, gActiveUnit->jinfo->mov_table);

    x = -1;

    for (iy = gMapSize.y-1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x-1; ix >= 0; --ix)
        {
            if (gMapRange[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if (gMapUnit[iy][ix] == 0)
                continue;

            if (gMapUnit[iy][ix] == gActiveUnitId)
                continue;

            if (!func(GetUnit(gMapUnit[iy][ix])))
                continue;

            if (gMapRange[iy][ix] > bestDistance)
                continue;

            bestDistance = gMapRange[iy][ix];
            x = ix;
            y = iy;
        }
    }

    if (x >= 0)
    {
        out->x = x;
        out->y = y;

        return TRUE;
    }

    return FALSE;
}

void AiRandomMove(void)
{
    short ix, iy;

    u8 lastRand = 0;

    short x = 0;
    short y = 0;

    MapFlood_08019344(gActiveUnit);

    x = -1;

    for (iy = gMapSize.y-1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x-1; ix >= 0; --ix)
        {
            u8 rand;

            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if (gMapUnit[iy][ix] != 0)
                continue;

            rand = RandNext(UINT8_MAX+1);

            if (rand < lastRand)
                continue;

            lastRand = rand;
            x = ix;
            y = iy;
        }
    }

    if (x >= 0)
        AiSetDecision(x, y, AI_ACTION_NONE, 0, 0, 0, 0);
}

bool AiReachesByBirdsEyeDistance(struct Unit * unit, struct Unit * other, u16 item)
{
    int maxDistance = RECT_DISTANCE(unit->x, unit->y, other->x, other->y);

    if (maxDistance <= UNIT_MOV(unit) + GetItemMaxRange(item))
        return TRUE;

    return FALSE;
}

bool AiCouldReachByBirdsEyeDistance(struct Unit * unit, struct Unit * other, u16 item)
{
    int maxDistance = RECT_DISTANCE(unit->x, unit->y, other->x, other->y);

    if (maxDistance <= UNIT_MOV(unit) + UNIT_MOV(other) + GetItemMaxRange(item))
        return TRUE;

    return FALSE;
}

bool AiIsInShortList(u16 const * list, u16 item)
{
    while (*list)
    {
        if (*list == item)
            return TRUE;

        list++;
    }

    return FALSE;
}

bool AiIsInByteList(u8 const * list, u8 item)
{
    while (*list)
    {
        if (*list == item)
            return TRUE;

        list++;
    }

    return FALSE;
}

bool AiFindClosestTerrainPosition(u8 const * terrainList, int flags, struct Vec2i * out)
{
    int ix, iy;

    u8 bestDistance = UINT8_MAX;

    for (iy = gMapSize.y-1; iy >= 0; iy--)
    {
        for (ix = gMapSize.x-1; ix >= 0; ix--)
        {
            if (gMapRange[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if (!AiIsInByteList(terrainList, gMapTerrain[iy][ix]))
                continue;

            if (flags & AI_FINDPOS_FLAG_CHECK_ENEMY)
            {
                if (gMapUnit[iy][ix] != 0 && !AreUnitIdsAllied(gActiveUnit->id, gMapUnit[iy][ix]))
                    continue;
            }

            if (flags & AI_FINDPOS_FLAG_CHECK_NEARBY_ENEMIES)
            {
                if (AiCountNearbyEnemyUnits(ix, iy) != 0)
                    continue;
            }

            if (bestDistance <= gMapRangeSigned[iy][ix])
                continue;

            out->x = ix;
            out->y = iy;

            bestDistance = gMapRange[iy][ix];
        }
    }

    if (bestDistance != UINT8_MAX)
        return TRUE;

    return FALSE;
}

u8 AiGetPositionRange(int x, int y)
{
    if (gMapRangeSigned[y][x] >= MAP_MOVEMENT_MAX)
        return UINT8_MAX;

    if (gMapUnit[y][x] != 0 && gMapUnit[y][x] != gActiveUnitId)
        return UINT8_MAX;

    return gMapRange[y][x];
}

bool AiFindClosestTerrainAdjacentPosition(u8 const * terrainList, int flags, struct Vec2i * out)
{
    struct Vec2i tmp;
    int ix, iy;

    u8 bestDistance = UINT8_MAX;

    for (iy = gMapSize.y-1; iy >= 0; iy--)
    {
        for (ix = gMapSize.x-1; ix >= 0; ix--)
        {
            if (gMapRange[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if (!AiIsInByteList(terrainList, gMapTerrain[iy][ix]))
                continue;

            if (flags & AI_FINDPOS_FLAG_CHECK_ENEMY)
            {
                if (gMapUnit[iy][ix] != 0 && !AreUnitIdsAllied(gActiveUnit->id, gMapUnit[iy][ix]))
                    continue;
            }

            if (flags & AI_FINDPOS_FLAG_CHECK_NEARBY_ENEMIES)
            {
                if (AiCountNearbyEnemyUnits(ix, iy) != 0)
                    continue;
            }

            if (!AiFindBestAdjacentPositionByFunc(ix, iy, AiGetPositionRange, &tmp))
                continue;

            if (bestDistance <= gMapRangeSigned[tmp.y][tmp.x])
                continue;

            out->x = tmp.x;
            out->y = tmp.y;
            bestDistance = gMapRange[tmp.y][tmp.x];
        }
    }

    if (bestDistance != UINT8_MAX)
        return TRUE;

    return FALSE;
}

bool AiFindClosestUnlockPosition(int flags, struct Vec2i * out)
{
    struct Vec2i tmp;
    int ix, iy;

    u16 unk = 0;

    u8 bestDistance = UINT8_MAX;
    u8 count = 0;

    for (iy = gMapSize.y-1; iy >= 0; iy--)
    {
        for (ix = gMapSize.x-1; ix >= 0; ix--)
        {
            if (gMapRange[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            switch (gMapTerrain[iy][ix])
            {

            case TERRAIN_DOOR:
                count++;

                if (flags & AI_FINDPOS_FLAG_NO_DOORS)
                    continue;

                if (!AiFindBestAdjacentPositionByFunc(ix, iy, AiGetPositionRange, &tmp))
                    continue;

                break;

            case TERRAIN_CHEST:
                count++;

                if (flags & AI_FINDPOS_FLAG_NO_CHESTS)
                    continue;

                tmp.x = ix;
                tmp.y = iy;

                if (gMapMovement[iy][ix] <= UNIT_MOV(gActiveUnit))
                {
                    if (flags & AI_FINDPOS_FLAG_CHECK_ENEMY)
                    {
                        if (gMapUnit[tmp.y][tmp.x] != 0 && !AreUnitIdsAllied(gActiveUnit->id, gMapUnit[tmp.y][tmp.x]))
                            continue;
                    }

                    if (flags & AI_FINDPOS_FLAG_CHECK_NEARBY_ENEMIES)
                    {
                        if (AiCountNearbyEnemyUnits(tmp.x, tmp.y) != 0)
                            continue;
                    }

                    out->x = tmp.x;
                    out->y = tmp.y;

                    return TRUE;
                }

                break;

            default:
                continue;

            }

            if (flags & AI_FINDPOS_FLAG_CHECK_ENEMY)
            {
                if (gMapUnit[tmp.y][tmp.x] != 0 && !AreUnitIdsAllied(gActiveUnit->id, gMapUnit[tmp.y][tmp.x]))
                    continue;
            }

            if (flags & AI_FINDPOS_FLAG_CHECK_NEARBY_ENEMIES)
            {
                if (AiCountNearbyEnemyUnits(tmp.x, tmp.y) != 0)
                    continue;
            }

            if (bestDistance <= gMapRangeSigned[tmp.y][tmp.x])
                continue;

            out->x = tmp.x;
            out->y = tmp.y;
            bestDistance = gMapRange[tmp.y][tmp.x];
        }
    }

    if ((unk & 0x10000) == 0) // if (1); required to match
        gAiSt.cmd_result[1] = 1;

    if (count == 0)
        gAiSt.cmd_result[0] = 5;

    if (bestDistance != UINT8_MAX)
        return TRUE;

    return FALSE;
}

int AiCountUnitsInRange(void)
{
    int ix, iy;

    int count = 0;

    for (iy = gMapSize.y-1; iy >= 0; iy--)
    {
        for (ix = gMapSize.x-1; ix >= 0; ix--)
        {
            if (gMapRangeSigned[iy][ix] == 0)
                continue;

            if (gMapUnit[iy][ix] == 0)
                continue;

            count++;
        }
    }

    return count;
}

int AiCountEnemyUnitsInRange(void)
{
    int ix, iy;

    int count = 0;

    for (iy = gMapSize.y-1; iy >= 0; iy--)
    {
        for (ix = gMapSize.x-1; ix >= 0; ix--)
        {
            if (gMapRangeSigned[iy][ix] == 0)
                continue;

            if (gMapUnit[iy][ix] == 0)
                continue;

            if (AreUnitIdsAllied(gActiveUnitId, gMapUnit[iy][ix]))
                continue;

            count++;
        }
    }

    return count;
}

int AiCountAlliedUnitsInRange(void)
{
    int ix, iy;

    int count = 0;

    for (iy = gMapSize.y-1; iy >= 0; iy--)
    {
        for (ix = gMapSize.x-1; ix >= 0; ix--)
        {
            if (gMapRangeSigned[iy][ix] == 0)
                continue;

            if (gMapUnit[iy][ix] == 0)
                continue;

            if (AreUnitIdsAllied(gActiveUnitId, gMapUnit[iy][ix]) != TRUE)
                continue;

            count++;
        }
    }

    return count;
}

int AiCountNearbyUnits(short x, short y)
{
    int count = 0;

    struct Vec2i const * it = sRange3OffsetLut;

    it--;

    while (it->x != 9999)
    {
        it++;

        if (x + it->x >= gMapSize.x)
            continue;

        if (y + it->y >= gMapSize.y)
            continue;

        if (gMapUnit[y + it->y][x + it->x] == 0)
            continue;

        count++;
    }

    return count;
}

int AiCountNearbyEnemyUnits(short x, short y)
{
    int count = 0;

    struct Vec2i const * it = sRange3OffsetLut;

    it--;

    while (it->x != 9999)
    {
        it++;

        if (x + it->x >= gMapSize.x)
            continue;

        if (y + it->y >= gMapSize.y)
            continue;

        if (gMapUnit[y + it->y][x + it->x] == 0)
            continue;

        if (AreUnitIdsAllied(gActiveUnitId, gMapUnit[y + it->y][x + it->x]))
            continue;

        count++;
    }

    return count;
}

int AiCountNearbyAlliedUnits(short x, short y)
{
    int count = 0;

    struct Vec2i const * it = sRange3OffsetLut;

    it--;

    while (it->x != 9999)
    {
        it++;

        if (x + it->x >= gMapSize.x)
            continue;

        if (y + it->y >= gMapSize.y)
            continue;

        if (gMapUnit[y + it->y][x + it->x] == 0)
            continue;

        if (AreUnitIdsAllied(gActiveUnitId, gMapUnit[y + it->y][x + it->x]) != TRUE)
            continue;

        count++;
    }

    return count;
}

void AiMakeMoveRangeMapsForUnitAndWeapon(struct Unit * unit, u16 item)
{
    int ix, iy;

    MapFlood_08019344(unit);
    MapFill(gMapRange, 0);

    for (iy = gMapSize.y-1; iy >= 0; iy--)
    {
        for (ix = gMapSize.x-1; ix >= 0; ix--)
        {
            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            MapIncInBoundedRange(ix, iy, GetItemMinRange(item), GetItemMaxRange(item));
        }
    }
}

void AiMakeMoveRangeUnitPowerMaps(struct Unit * unit)
{
    int ix, iy;

    int range = GetUnitPower(unit) > 20 ? 20 : GetUnitPower(unit);

    MapFlood_08019344(unit);
    MapFill(gMapRange, 0);

    for (iy = gMapSize.y-1; iy >= 0; iy--)
    {
        for (ix = gMapSize.x-1; ix >= 0; ix--)
        {
            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            MapAddInRange(ix, iy, range, 1);
        }
    }
}

void AiMakeMoveRangeMapsForUnitAndWeapon2(struct Unit * unit, u16 item)
{
    int ix, iy;

    MapFlood_08019344(unit);
    MapFill(gMapRange, 0);

    for (iy = gMapSize.y-1; iy >= 0; iy--)
    {
        for (ix = gMapSize.x-1; ix >= 0; ix--)
        {
            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            MapIncInBoundedRange(ix, iy, GetItemMinRange(item), GetItemMaxRange(item));
        }
    }
}

bool AiFindBestAdjacentPositionByFunc(int x, int y, u8 (* funcArg)(int x, int y), struct Vec2i * out)
{
    u8 (* func)(int x, int y) = funcArg;

    u8 best = UINT8_MAX;

    i8 adjacencyLut[4*2] =
    {
        +1,  0,
        -1,  0,
         0, +1,
         0, -1,
    };

    int i;

    for (i = 0; i < 4; ++i)
    {
        u8 val = func(x + adjacencyLut[i*2+0], y + adjacencyLut[i*2+1]);

        if (val == UINT8_MAX)
            continue;

        if (best <= val)
            continue;

        best = val;
        out->x = x + adjacencyLut[i*2+0];
        out->y = y + adjacencyLut[i*2+1];
    }

    if (best != UINT8_MAX)
        return TRUE;

    return FALSE;
}

int AiGetItemStealRank(u16 item)
{
    int result = 0;

    u16 const * it = gUnk_085C8834;

    while (*it != UINT16_MAX)
    {
        if (*it == item)
            return result;

        ++it;
        ++result;
    }

    return -1;
}

i8 AiGetUnitStealItemSlot(struct Unit * unit)
{
    u16 item;
    int i;

    u8 rank = UINT8_MAX;
    u8 slot = -1;

    for (i = 0; i < ITEMSLOT_INV_COUNT; ++i)
    {
        u8 rankNew;

        item = unit->items[i];

        if (item == 0)
            return slot;

        rankNew = AiGetItemStealRank(ITEM_IID(item));

        if (rank < rankNew)
            continue;

        rank = rankNew;
        slot = i;
    }

    return slot;
}

bool AiFindSafestReachableLocation(struct Unit * unit, struct Vec2i * out)
{
    int ix, iy;

    u8 bestDanger = UINT8_MAX;

    if (gAiSt.flags & AI_FLAG_1)
    {
        MapFill(gMapMovement, -1);
        gMapMovement[unit->y][unit->x] = 0;
    }
    else
    {
        MapFlood_08019344(unit);
    }

    for (iy = gMapSize.y-1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x-1; ix >= 0; --ix)
        {
            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if (gMapUnit[iy][ix] != 0 && gMapUnit[iy][ix] != gActiveUnitId)
                continue;

            if (bestDanger < gMapOther[iy][ix])
                continue;

            out->x = ix;
            out->y = iy;

            bestDanger = gMapOther[iy][ix];
        }
    }

    if (bestDanger != UINT8_MAX)
        return TRUE;

    return FALSE;
}

bool AiFindPillageLocation(struct Vec2i * out, u8 * outItemSlot)
{
    u8 const * terrains;

    SetWorkingMovTable(gActiveUnit->jinfo->mov_table);
    SetWorkingMap(gMapRange);

    BeginMapFlood(gActiveUnit->x, gActiveUnit->y, 124, gActiveUnit->id);

    terrains = AiGetChestUnlockItemSlot(outItemSlot) == TRUE
        ? gUnk_085C864F
        : gUnk_085C864C;

    if (AiFindClosestTerrainPosition(terrains, AI_FINDPOS_FLAG_CHECK_ENEMY, out) == TRUE)
        return TRUE;

    MapFlood_080193F4(gActiveUnit->x, gActiveUnit->y, gActiveUnit->jinfo->mov_table);

    if (AiFindClosestTerrainPosition(terrains, 0, out) == TRUE)
        return TRUE;

    return FALSE;
}

bool AiGetChestUnlockItemSlot(u8 * out)
{
    int i;

    *out = 0;

    if (GetUnitItemCount(gActiveUnit) == ITEMSLOT_INV_COUNT)
    {
        gActiveUnit->ai_flags |= AI_UNIT_FLAG_3;
        return FALSE;
    }

    for (i = 0; i < ITEMSLOT_INV_COUNT; ++i)
    {
        u16 item = gActiveUnit->items[i];

        if (item == 0)
            return FALSE;

        *out = i;

        if (GetItemIid(item) == IID_CHESTKEY)
            return TRUE;

        if (GetItemIid(item) == IID_LOCKPICK)
        {
            if (UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_STEAL)
                return TRUE;
        }
    }

    return FALSE;
}

void AiTryMoveTowards(short x, short y, u8 action, u8 maxDanger, u8 arg_4)
{
    short ix, iy;

    u8 bestRange;

    short xOut = 0;
    short yOut = 0;

    if (gActiveUnit->x == x && gActiveUnit->y == y)
    {
        AiSetDecision(gActiveUnit->x, gActiveUnit->y, action, 0, 0, 0, 0);
        return;
    }

    if (arg_4)
    {
        MapFlood_080193F4(x, y, gActiveUnit->jinfo->mov_table);
    }
    else
    {
        func_fe6_08035098(x, y, gActiveUnit);
    }

    MapFlood_08019344(gActiveUnit);

    bestRange = gMapRange[gActiveUnit->y][gActiveUnit->x];
    xOut = -1;

    for (iy = gMapSize.y-1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x-1; ix >= 0; --ix)
        {
            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if (gMapUnit[iy][ix] != 0 && gMapUnit[iy][ix] != gActiveUnitId)
                continue;

            if (maxDanger == 0)
            {
                if (UNIT_MOV(gActiveUnit) < gAiSt.best_blue_mov && gMapOther[iy][ix] != 0)
                    continue;
            }

            if (!AiCheckDangerAt(ix, iy, maxDanger))
                continue;

            if (gMapRange[iy][ix] > bestRange)
                continue;

            bestRange = gMapRange[iy][ix];
            xOut = ix;
            yOut = iy;
        }
    }

    if (xOut >= 0)
    {
        AiSetDecision(xOut, yOut, action, 0, 0, 0, 0);
    }
}

bool AiGetUnitClosestValidPosition(struct Unit * unit, short x, short y, struct Vec2i * out)
{
    short ix, iy;
    u8 bestRange;

    if ((gMapUnit[y][x] | gMapOther[y][x]) == 0)
    {
        out->x = x;
        out->y = y;

        return TRUE;
    }

    MapFlood_080193F4(x, y, unit->jinfo->mov_table);
    MapFlood_080193C0(unit);

    bestRange = 124;
    out->x = -1;

    for (iy = gMapSize.y-1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x-1; ix >= 0; --ix)
        {
            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if ((gMapUnit[iy][ix] | gMapOther[iy][ix]) != 0)
                continue;

            if (gMapRange[iy][ix] > bestRange)
                continue;

            bestRange = gMapRange[iy][ix];
            out->x = ix;
            out->y = iy;
        }
    }

    if (out->x != -1)
        return TRUE;

    return FALSE;
}

u8 AiGetJobRank(u8 jid)
{
    u8 num = 0;
    u8 const * const * it = gAiJobRankLists;

    while (*it != NULL)
    {
        u8 const * itJob = *it;

        while (*itJob != 0)
        {
            if (*itJob == jid)
                return num;

            itJob++;
        }

        ++num;
        ++it;
    }

    return num;
}

bool AiUnitWithPidExists(u16 pid)
{
    int i;

    for (i = 1; i < 0xC0; ++i)
    {
        struct Unit * unit = GetUnit(i);

        if (!unit)
            continue;

        if (!unit->pinfo)
            continue;

        if (unit->pinfo->id != pid)
            continue;

        if (unit->flags & UNIT_FLAG_RESCUED)
            return TRUE;

        if (unit->flags & (UNIT_FLAG_HIDDEN | UNIT_FLAG_DEAD))
            return FALSE;

        return TRUE;
    }

    return FALSE;
}

bool AiIsWithinRectDistance(short x, short y, u8 x2, u8 y2, u8 maxDistance)
{
    u16 distance = RECT_DISTANCE(x, y, x2, y2);

    if (distance <= maxDistance)
        return TRUE;

    return FALSE;
}

bool AiLocationIsPillageTarget(u8 x, u8 y)
{
    u8 tmp;

    switch (gMapTerrain[y][x])
    {

    case TERRAIN_VILLAGE:
        return TRUE;

    case TERRAIN_HOUSE:
        return TRUE;

    case TERRAIN_CHURCH:
        return TRUE;

    case TERRAIN_CHEST:
        if (AiGetChestUnlockItemSlot(&tmp) == TRUE)
            return TRUE;

        return FALSE;

    }

    return FALSE;
}

void func_fe6_080308B0(void)
{
    int i, j, item;

    gAiSt.best_blue_mov = 0;

    for (i = FACTION_BLUE + 1; i < FACTION_BLUE + 0x40; ++i)
    {
        u8 mov;

        struct Unit * unit = GetUnit(i);

        if (!unit)
            continue;

        if (!unit->pinfo)
            continue;

        if (unit->flags & (UNIT_FLAG_HIDDEN | UNIT_FLAG_DEAD))
            continue;

        mov = UNIT_MOV(unit);

        if (mov > gAiSt.best_blue_mov)
            gAiSt.best_blue_mov = mov;

        for (j = 0; (j < ITEMSLOT_INV_COUNT) && (item = unit->items[j]); ++j)
        {
            if (!CanUnitUseWeapon(unit, item) && !CanUnitUseStaff(unit, item))
                continue;

            if (GetItemAttributes(item) & ITEM_ATTR_MAGIC)
                unit->ai_flags |= AI_UNIT_FLAG_SEEK_HEALING;

            func_fe6_08030968(unit, item);
            func_fe6_08030994(unit, item);
        }

        func_fe6_080309E0(unit);
    }
}

void func_fe6_08030968(struct Unit * unit, u16 item)
{
    if (GetItemAttributes(item) & ITEM_ATTR_STAFF)
    {
        int register flag asm("r4") = AI_UNIT_FLAG_1;

        switch (GetItemIid(item))
        {
        }

        flag |= unit->ai_flags;
        unit->ai_flags = flag;
    }
}

void func_fe6_08030994(struct Unit * unit, u16 item)
{
    int flag = 0;

    if ((GetItemAttributes(item) & ITEM_ATTR_WEAPON) && GetItemMaxRange(item) > 1)
        flag = AI_UNIT_FLAG_6;

    switch (GetItemEffect(item))
    {

    case ITEM_EFFECT_02:
    case ITEM_EFFECT_03:
    case ITEM_EFFECT_04:
    case ITEM_EFFECT_05:
    case ITEM_EFFECT_06:
    case ITEM_EFFECT_24:
    case ITEM_EFFECT_25:
        flag |= AI_UNIT_FLAG_2;
        break;

    }

    unit->ai_flags |= flag;
}

void func_fe6_080309E0(struct Unit * unit)
{
    int ix, iy;

    int count = 0;

    MapFill(gMapMovement, 0);
    MapIncInBoundedRange(unit->x, unit->y, 1, 8);

    for (iy = gMapSize.y-1; iy >= 0; iy--)
    {
        for (ix = gMapSize.x-1; ix >= 0; ix--)
        {
            if (gMapMovementSigned[iy][ix] == 0)
                continue;

            if (gMapUnit[iy][ix] == 0)
                continue;

            if (!AreUnitIdsAllied(unit->id, gMapUnit[iy][ix]))
                continue;

            count++;
        }
    }

    unit->unk_46 = count;
}

void UnitInitAiFromInfo(struct Unit * unit, struct UnitInfo const * info)
{
    unit->ai_a = info->ai[0];
    unit->ai_b = info->ai[1];
    unit->ai_config = (0xFFF8 & unit->ai_config) | info->ai[2] | (info->ai[3] << 8);
}

bool func_fe6_08030AB4(struct Vec2i * out)
{
    int ix, iy;

    u32 maxVal = 0;

    for (iy = gMapSize.y-1; iy >= 0; iy--)
    {
        for (ix = gMapSize.x-1; ix >= 0; ix--)
        {
            u32 val;

            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if (gMapRangeSigned[iy][ix] == 0)
                continue;

            if (gMapUnit[iy][ix] != 0 && gMapUnit[iy][ix] != gActiveUnitId)
                continue;

            val = ((AiGetTerrainCombatPositionScoreComponent(ix, iy) + AiGetFriendZoneCombatPositionScoreComponent(ix, iy)) - gMapOther[iy][ix]/8) + INT32_MAX;

            if (maxVal >= val)
                continue;

            out->x = ix;
            out->y = iy;
            maxVal = val;
        }
    }

    if (maxVal != 0)
        return TRUE;

    return FALSE;
}

int func_fe6_08030B94(void)
{
    int count = 0;

    int i, alliance = GetActiveFactionAlliance();

    for (i = alliance + 1; i < alliance + 0x80; ++i)
    {
        struct Unit * unit = GetUnit(i);

        if (!unit)
            continue;

        if (!unit->pinfo)
            continue;

        if (unit->flags & (UNIT_FLAG_HIDDEN | UNIT_FLAG_DEAD))
            continue;

        if (unit->ai_flags & AI_UNIT_FLAG_SEEK_HEALING)
            count++;
    }

    return count;
}

int func_fe6_08030BDC(void)
{
    int ix, iy;

    int count = 0;

    for (iy = gMapSize.y-1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x-1; ix >= 0; --ix)
        {
            if (gMapRangeSigned[iy][ix] == 0)
                continue;

            if (gMapUnit[iy][ix] == 0)
                continue;

            if (!AreUnitIdsAllied(gActiveUnitId, gMapUnit[iy][ix]))
                continue;

            if (GetUnit(gMapUnit[iy][ix])->ai_flags & AI_UNIT_FLAG_SEEK_HEALING)
                count++;
        }
    }

    return count;
}

bool AiUnitHasAnyStaff(struct Unit * unit)
{
    int i;

    for (i = 0; i < ITEMSLOT_INV_COUNT; ++i)
    {
        u16 item = unit->items[i];

        if (item == 0)
            return FALSE;

        if (GetItemAttributes(item) & (ITEM_ATTR_MAGIC | ITEM_ATTR_STAFF))
            if (CanUnitUseStaff(unit, item))
                return TRUE;
    }

    return FALSE;
}

void func_fe6_08030CBC(struct Unit * unit)
{
    if (gAiSt.flags & AI_FLAG_1)
    {
        MapFlood_08019384(unit, 0);
    }
    else
    {
        MapFlood_08019344(unit);
    }
}
