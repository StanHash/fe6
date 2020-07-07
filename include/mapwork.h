
#pragma once

#include "common.h"

struct MapFloodSquareEnt
{
    /* 00 */ s8 x;
    /* 01 */ s8 y;
    /* 02 */ u8 connect;
    /* 03 */ u8 leastMov;
};

struct MapFloodSt
{
    /* 00 */ struct MapFloodSquareEnt* activeQueue;
    /* 04 */ struct MapFloodSquareEnt* waitingQueue;
    /* 08 */ Bool hasUnit;
    /* 09 */ u8 move;
    /* 0A */ u8 uid;
    /* 0B */ u8 edgeMove;
};

void SetWorkingMap(u8** map);
void MapFlood_08019344(struct Unit* unit);
void MapFlood_08019384(struct Unit* unit, s8 move);
void MapFlood_080193C0(struct Unit* unit);
void MapFlood_080193F4(int x, int y, s8 const* movTable);
void MapFlood_08019424(int x, int y, s8 const* movTable);
void MapFlood_08019454(struct Unit* unit, int x, int y, int move);
void SetWorkingMovTable(s8 const* movTable);
void BeginMapFlood(int x, int y, int move, int uid);
void BuildBestMoveScript(int x, int y, u8* output);
void ApplyWorkingMovScriptToAction(int x, int y);
void MapMovementMarkFloodEdges(void);
void MapMarkFloodEdges(void);
void MapAddInRange(int x, int y, int range, int value);
void MapIncInBoundedRange(short x, short y, short minRange, short maxRange);
void BuildUnitCompleteAttackRange(struct Unit* unit);
void BuildUnitStandingRangeForReach(struct Unit* unit, int reach);
void BuildUnitCompleteStaffRange(struct Unit* unit);
s8 const* GetWorkingMovTable(void);

extern struct MapFloodSt gMapFloodSt;
extern struct MapFloodSquareEnt gMapFloodSquareBufA[];
extern struct MapFloodSquareEnt gMapFloodSquareBufB[];

extern u8** gWorkingMap;
extern s8 gWorkingMovTable[];

extern u8 gWorkingMoveScr[MOVE_SCRIPT_MAX_LENGTH];

#define gWorkingMapSigned ((s8**) gWorkingMap)
