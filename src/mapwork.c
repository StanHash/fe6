
#include "mapwork.h"
#include "common.h"

#include "ramfunc.h"
#include "random.h"
#include "item.h"
#include "unit.h"
#include "map.h"
#include "mu.h"

#include "constants/terrains.h"

static void RevertAndCvtToMoveScr(u8* begin, u8* end);

u8 EWRAM_DATA gWorkingMoveScr[MOVE_SCRIPT_MAX_LENGTH] = {};

inline void SetWorkingMap(u8** map)
{
    gWorkingMap = map;
}

void MapFlood_08019344(struct Unit* unit)
{
    SetWorkingMovTable(unit->job->movTerrainTable);
    SetWorkingMap(gMapMovement);

    BeginMapFlood(unit->x, unit->y, UNIT_MOV(unit), unit->id);
}

void MapFlood_08019384(struct Unit* unit, s8 move)
{
    SetWorkingMovTable(unit->job->movTerrainTable);
    SetWorkingMap(gMapMovement);

    BeginMapFlood(unit->x, unit->y, move, unit->id);
}

void MapFlood_080193C0(struct Unit* unit)
{
    SetWorkingMovTable(unit->job->movTerrainTable);
    SetWorkingMap(gMapMovement);

    BeginMapFlood(unit->x, unit->y, MAP_MOVEMENT_EXTENDED, 0);
}

void MapFlood_080193F4(int x, int y, s8 const* movTable)
{
    SetWorkingMovTable(movTable);
    SetWorkingMap(gMapRange);

    BeginMapFlood(x, y, MAP_MOVEMENT_EXTENDED, 0);
}

void MapFlood_08019424(int x, int y, s8 const* movTable)
{
    SetWorkingMovTable(movTable);
    SetWorkingMap(gMapMovement);

    BeginMapFlood(x, y, MAP_MOVEMENT_EXTENDED, 0);
}

void MapFlood_08019454(struct Unit* unit, int x, int y, int move)
{
    SetWorkingMovTable(unit->job->movTerrainTable);

    BeginMapFlood(x, y, move, unit->id);
}

void SetWorkingMovTable(s8 const* movTable)
{
    int i;

    for (i = 0; i < TERRAIN_COUNT; ++i)
        gWorkingMovTable[i] = movTable[i];
}

void BeginMapFlood(int x, int y, int move, int uid)
{
    gMapFloodSt.waitingQueue = gMapFloodSquareBufB;
    gMapFloodSt.activeQueue = gMapFloodSquareBufA;

    gMapFloodSt.move = move;

    if (uid == 0)
    {
        gMapFloodSt.hasUnit = FALSE;
    }
    else
    {
        gMapFloodSt.hasUnit = TRUE;
        gMapFloodSt.uid = uid;
    }

    gMapFloodSt.edgeMove = MAP_MOVEMENT_MAX;

    MapFill(gWorkingMap, -1);

    gMapFloodSt.waitingQueue->x = x;
    gMapFloodSt.waitingQueue->y = y;
    gMapFloodSt.waitingQueue->connect = 5;
    gMapFloodSt.waitingQueue->leastMov = 0;

    gWorkingMap[y][x] = 0;

    gMapFloodSt.waitingQueue++;
    gMapFloodSt.waitingQueue->connect = 4;

    MapFloodCoreRam();
}

void sub_8019528(int connect, int x, int y)
{
    // This is a C implementation of the ARM (asm) function MapFloodCoreStep
    // Probably used during development before switching to the a more optimized version.

    short squareMove;

    x += gMapFloodSt.activeQueue->x;
    y += gMapFloodSt.activeQueue->y;

    squareMove = (u8) gWorkingMovTable[gMapTerrain[y][x]]
        + (s8) gWorkingMap[(u8) gMapFloodSt.activeQueue->y][(u8) gMapFloodSt.activeQueue->x];

    if (squareMove >= gWorkingMap[y][x])
        return;

    if (gMapFloodSt.hasUnit && gMapUnit[y][x])
        if ((gMapUnit[y][x] ^ gMapFloodSt.uid) & 0x80)
            return;

    if (squareMove > gMapFloodSt.move)
        return;

    gMapFloodSt.waitingQueue->x = x;
    gMapFloodSt.waitingQueue->y = y;
    gMapFloodSt.waitingQueue->connect = connect;
    gMapFloodSt.waitingQueue->leastMov = squareMove;

    gMapFloodSt.waitingQueue++;

    gWorkingMap[y][x] = squareMove;
}

void BuildBestMoveScript(int x, int y, u8* output)
{
    u8* outputStart = output;

    short bestCost;
    short bestDirectionCount;

    u8 neighbourCosts[4];
    u8 bestDirections[4];

    short nextDirection;

    int i;

    // The basic algorithm here is:
    // 1. start from the end point
    // 2. get on the point that's closest to the origin (lowest mov cost)
    // 3. write direction to output
    // 4. repeat 2-4 until we reached origin (cost = 0)
    // 5. reverse and terminate output

    // As we build the list *in reverse*, the directions are also "reversed" as we traverse the path.

    while (((s8**) gWorkingMap)[y][x] != 0)
    {
        // Build neighbor cost list

        if (x == (gMapSize.x - 1))
            neighbourCosts[FACING_LEFT] |= 0xFF;
        else
            neighbourCosts[FACING_LEFT] = gWorkingMap[y][x+1];

        if (x == 0)
            neighbourCosts[FACING_RIGHT] |= 0xFF;
        else
            neighbourCosts[FACING_RIGHT] = gWorkingMap[y][x-1];

        if (y == (gMapSize.y - 1))
            neighbourCosts[FACING_UP] |= 0xFF;
        else
            neighbourCosts[FACING_UP] = gWorkingMap[y+1][x];

        if (y == 0)
            neighbourCosts[FACING_DOWN] |= 0xFF;
        else
            neighbourCosts[FACING_DOWN] = gWorkingMap[y-1][x];

        // find best cost

        bestCost = 0x100;
        bestDirectionCount = 0;

        for (i = 0; i < 4; ++i)
            if (bestCost > neighbourCosts[i])
                bestCost = neighbourCosts[i];

        // list all directions that have best cost

        for (i = 0; i < 4; ++i)
            if (bestCost == neighbourCosts[i])
                bestDirections[bestDirectionCount++] = i;

        // get next direction (choose randomly if necessary)

        switch (bestDirectionCount)
        {

        case 1:
            nextDirection = bestDirections[0];
            break;

        case 2:
            nextDirection = bestDirections[RandNext(2)];
            break;

        case 3:
            nextDirection = bestDirections[RandNext(3)];
            break;

        case 4:
            nextDirection = bestDirections[RandNext(4)];
            break;

        }

        // write next direction

        *output++ = nextDirection;

        // update position given direction
        // reminder: directions are reversed

        switch (nextDirection)
        {

        case FACING_LEFT:
            x++;
            break;

        case FACING_RIGHT:
            x--;
            break;

        case FACING_UP:
            y++;
            break;

        case FACING_DOWN:
            y--;
            break;

        }
    }

    RevertAndCvtToMoveScr(outputStart, output);
}

static void RevertAndCvtToMoveScr(u8* begin, u8* end)
{
    u8 buf[MOVE_SCRIPT_MAX_LENGTH];

    u8* it = buf;

    while (end > begin)
        *it++ = MOVE_CMD_MOVE_BASE + *--end;

    *it = MOVE_CMD_HALT;

    for (it = buf; *it != MOVE_CMD_HALT;)
        *begin++ = *it++;

    *begin = MOVE_CMD_HALT;
}

void ApplyWorkingMovScriptToAction(int x, int y)
{
    u8* it = gWorkingMoveScr;

    for (;;)
    {
        gAction.xMove = x;
        gAction.yMove = y;

        switch (*it)
        {

        case MOVE_CMD_MOVE_UP:
            y--;
            break;

        case MOVE_CMD_MOVE_DOWN:
            y++;
            break;

        case MOVE_CMD_MOVE_LEFT:
            x--;
            break;

        case MOVE_CMD_MOVE_RIGHT:
            x++;
            break;

        }

        if (gMapHidden[y][x] != 0)
        {
            *it++ = MOVE_CMD_BUMP;
            *it++ = MOVE_CMD_HALT;

            gAction.actionId = ACTION_TRAPPED;

            return;
        }

        if (*it == MOVE_CMD_HALT)
            break;

        it++;
    }
}

void MapMovementMarkFloodEdges(void)
{
    int ix, iy;

    for (iy = gMapSize.y - 1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x - 1; ix >= 0; --ix)
        {
            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if (gMapMovementSigned[iy][ix] == gMapFloodSt.edgeMove)
                continue;

            if (gMapMovementSigned[iy][ix - 1] < 0 && (ix != 0))
                gMapMovementSigned[iy][ix - 1] = gMapFloodSt.edgeMove;

            if (gMapMovementSigned[iy][ix + 1] < 0 && (ix != (gMapSize.x - 1)))
                gMapMovementSigned[iy][ix + 1] = gMapFloodSt.edgeMove;

            if (gMapMovementSigned[iy - 1][ix] < 0 && (iy != 0))
                gMapMovementSigned[iy - 1][ix] = gMapFloodSt.edgeMove;

            if (gMapMovementSigned[iy + 1][ix] < 0 && (iy != (gMapSize.y - 1)))
                gMapMovementSigned[iy + 1][ix] = gMapFloodSt.edgeMove;
        }
    }

    gMapFloodSt.edgeMove++;
}

void MapMarkFloodEdges(void)
{
    int ix, iy;

    for (iy = gMapSize.y - 1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x - 1; ix >= 0; --ix)
        {
            if (gWorkingMap[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if ((s8) gWorkingMap[iy][ix] == gMapFloodSt.edgeMove)
                continue;

            if ((s8) gWorkingMap[iy][ix - 1] < 0 && (ix != 0))
                gWorkingMap[iy][ix - 1] = gMapFloodSt.edgeMove;

            if ((s8) gWorkingMap[iy][ix + 1] < 0 && (ix != (gMapSize.x - 1)))
                gWorkingMap[iy][ix + 1] = gMapFloodSt.edgeMove;

            if ((s8) gWorkingMap[iy - 1][ix] < 0 && (iy != 0))
                gWorkingMap[iy - 1][ix] = gMapFloodSt.edgeMove;

            if ((s8) gWorkingMap[iy + 1][ix] < 0 && (iy != (gMapSize.y - 1)))
                gWorkingMap[iy + 1][ix] = gMapFloodSt.edgeMove;
        }
    }

    gMapFloodSt.edgeMove++;
}

void MapAddInRange(int x, int y, int range, int value)
{
    int ix, iy, iRange;

    // Handles rows [y, y+range]
    // For each row, decrement range
    for (iRange = range, iy = y; (iy <= y + range) && (iy <= gMapSize.y); --iRange, ++iy)
    {
        int xMin, xMax, xRange;

        xMin = x - iRange;
        xRange = 2 * iRange + 1;

        if (xMin < 0)
        {
            xRange += xMin;
            xMin = 0;
        }

        xMax = xMin + xRange;

        if (xMax > gMapSize.x)
        {
            xMax -= (xMax - gMapSize.x);
            xMax = gMapSize.x;
        }

        for (ix = xMin; ix < xMax; ++ix)
        {
            gWorkingMap[iy][ix] += value;
        }
    }

    // Handle rows [y-range, y-1], starting from the bottom most row
    // For each row, decrement range
    for (iRange = (range - 1), iy = (y - 1); (iy >= y - range) && (iy >= 0); --iRange, --iy)
    {
        int xMin, xMax, xRange;

        xMin = x - iRange;
        xRange = 2 * iRange + 1;

        if (xMin < 0)
        {
            xRange += xMin;
            xMin = 0;
        }

        xMax = xMin + xRange;

        if (xMax > gMapSize.x)
        {
            xMax -= (xMax - gMapSize.x);
            xMax = gMapSize.x;
        }

        for (ix = xMin; ix < xMax; ++ix)
        {
            gWorkingMap[iy][ix] += value;
        }
    }
}

inline void MapIncInBoundedRange(short x, short y, short minRange, short maxRange)
{
    MapAddInRange(x, y, maxRange,     +1);
    MapAddInRange(x, y, minRange - 1, -1);
}

void BuildUnitCompleteAttackRange(struct Unit* unit)
{
    int ix, iy;
    int item;

    MapFill(gMapRange, 0);

    #define FOR_EACH_IN_MOVEMENT_RANGE(block) \
        for (iy = gMapSize.y - 1; iy >= 0; --iy) \
        { \
            for (ix = gMapSize.x - 1; ix >= 0; --ix) \
            { \
                if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX) \
                    continue; \
                if (gMapUnit[iy][ix]) \
                    continue; \
                block \
            } \
        }

    switch (GetUnitWeaponReach(unit, -1))
    {

    case REACH_RANGE1:
        FOR_EACH_IN_MOVEMENT_RANGE(
        {
            MapIncInBoundedRange(ix, iy, 1, 1);
        })

        break;

    case REACH_RANGE1 | REACH_RANGE2:
        FOR_EACH_IN_MOVEMENT_RANGE(
        {
            MapIncInBoundedRange(ix, iy, 1, 2);
        })

        break;

    case REACH_RANGE1 | REACH_RANGE2 | REACH_RANGE3:
        FOR_EACH_IN_MOVEMENT_RANGE(
        {
            MapIncInBoundedRange(ix, iy, 1, 3);
        })

        break;

    case REACH_RANGE2:
        FOR_EACH_IN_MOVEMENT_RANGE(
        {
            MapIncInBoundedRange(ix, iy, 2, 2);
        })

        break;

    case REACH_RANGE2 | REACH_RANGE3:
        FOR_EACH_IN_MOVEMENT_RANGE(
        {
            MapIncInBoundedRange(ix, iy, 2, 3);
        })

        break;

    case REACH_RANGE3:
        FOR_EACH_IN_MOVEMENT_RANGE(
        {
            MapIncInBoundedRange(ix, iy, 3, 3);
        })

        break;

    case REACH_RANGE3 | REACH_TO10:
        FOR_EACH_IN_MOVEMENT_RANGE(
        {
            MapIncInBoundedRange(ix, iy, 3, 10);
        })

        break;

    case REACH_RANGE1 | REACH_RANGE3:
        FOR_EACH_IN_MOVEMENT_RANGE(
        {
            MapIncInBoundedRange(ix, iy, 1, 1);
            MapIncInBoundedRange(ix, iy, 3, 3);
        })

        break;

    case REACH_RANGE1 | REACH_RANGE3 | REACH_TO10:
        FOR_EACH_IN_MOVEMENT_RANGE(
        {
            MapIncInBoundedRange(ix, iy, 1, 1);
            MapIncInBoundedRange(ix, iy, 3, 10);
        })

        break;

    case REACH_RANGE1 | REACH_RANGE2 | REACH_RANGE3 | REACH_TO10:
        FOR_EACH_IN_MOVEMENT_RANGE(
        {
            MapIncInBoundedRange(ix, iy, 1, 10);
        })

        break;

    }

    // BUG: this should be unit not gActiveUnit
    if (UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_BALLISTA)
    {
        FOR_EACH_IN_MOVEMENT_RANGE(
        {
            item = sub_8026D20(ix, iy);

            if (item)
                MapIncInBoundedRange(ix, iy, GetItemMinRange(item), GetItemMaxRange(item));
        })
    }

    #undef FOR_EACH_IN_MOVEMENT_RANGE

    SetWorkingMap(gMapMovement);
}

void BuildUnitStandingRangeForReach(struct Unit* unit, int reach)
{
    int x = unit->x;
    int y = unit->y;

    switch (reach)
    {

    case REACH_RANGE1:
        MapIncInBoundedRange(x, y, 1, 1);
        break;

    case REACH_RANGE1 | REACH_RANGE2:
        MapIncInBoundedRange(x, y, 1, 2);
        break;

    case REACH_RANGE1 | REACH_RANGE2 | REACH_RANGE3:
        MapIncInBoundedRange(x, y, 1, 3);
        break;

    case REACH_RANGE2:
        MapIncInBoundedRange(x, y, 2, 2);
        break;

    case REACH_RANGE2 | REACH_RANGE3:
        MapIncInBoundedRange(x, y, 2, 3);
        break;

    case REACH_RANGE3:
        MapIncInBoundedRange(x, y, 3, 3);
        break;

    case REACH_RANGE3 | REACH_TO10:
        MapIncInBoundedRange(x, y, 3, 10);
        break;

    case REACH_RANGE1 | REACH_RANGE3:
        MapIncInBoundedRange(x, y, 1, 1);
        MapIncInBoundedRange(x, y, 3, 3);
        break;

    case REACH_RANGE1 | REACH_RANGE3 | REACH_TO10:
        MapIncInBoundedRange(x, y, 1, 1);
        MapIncInBoundedRange(x, y, 3, 10);
        break;

    case REACH_RANGE1 | REACH_RANGE2 | REACH_RANGE3 | REACH_TO10:
        MapIncInBoundedRange(x, y, 1, 10);
        break;

    case REACH_TOMAG:
        MapIncInBoundedRange(x, y, 1, GetUnitMagRange(unit));
        break;

    }
}

void BuildUnitCompleteStaffRange(struct Unit* unit)
{
    int ix, iy;

    int magRange, reach = GetUnitStaffReach(gActiveUnit);

    MapFill(gMapRange, 0);

    magRange = GetUnitMagRange(unit);

    #define FOR_EACH_IN_MOVEMENT_RANGE(block) \
        for (iy = gMapSize.y - 1; iy >= 0; --iy) \
        { \
            for (ix = gMapSize.x - 1; ix >= 0; --ix) \
            { \
                if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX) \
                    continue; \
                block \
            } \
        }

    switch (reach)
    {

    case REACH_RANGE1:
        FOR_EACH_IN_MOVEMENT_RANGE(
        {
            MapIncInBoundedRange(ix, iy, 1, 1);
        })

        break;

    case REACH_RANGE1 | REACH_RANGE2:
        FOR_EACH_IN_MOVEMENT_RANGE(
        {
            MapIncInBoundedRange(ix, iy, 1, 2);
        })

        break;

    case REACH_TOMAG:
        FOR_EACH_IN_MOVEMENT_RANGE(
        {
            MapIncInBoundedRange(ix, iy, 1, magRange);
        })

        break;

    }

    #undef FOR_EACH_IN_MOVEMENT_RANGE
}

inline s8 const* GetWorkingMovTable(void)
{
    return gWorkingMovTable;
}

/*

	thumb_func_start GetWorkingMovTable
GetWorkingMovTable: @ 0x0801A5A4
	ldr r0, _0801A5A8 @ =gWorkingMovTable
	bx lr
	.align 2, 0
_0801A5A8: .4byte gWorkingMovTable

*/
