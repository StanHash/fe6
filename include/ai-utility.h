
#pragma once

#include "common.h"

#include "unit.h"
#include "ai.h"

enum
{
    AI_FINDPOS_FLAG_CHECK_ENEMY          = (1 << 0),
    AI_FINDPOS_FLAG_CHECK_NEARBY_ENEMIES = (1 << 1),
    AI_FINDPOS_FLAG_NO_CHESTS            = (1 << 2),
    AI_FINDPOS_FLAG_NO_DOORS             = (1 << 3),
};

Bool AiCompare(u8 const* left, u8 cond, u32 right);
Bool AiFindTargetInReachByPid(int pid, struct Vec2* out);
Bool AiFindTargetInReachByJid(int jid, struct Vec2* out);
Bool AiFindTargetInReachByFunc(Bool(*func)(struct Unit* unit), struct Vec2* out);
void AiRandomMove(void);
Bool AiReachesByBirdsEyeDistance(struct Unit* unit, struct Unit* other, u16 item);
Bool AiCouldReachByBirdsEyeDistance(struct Unit* unit, struct Unit* other, u16 item);
Bool AiIsInShortList(u16 const* list, u16 item);
Bool AiIsInByteList(u8 const* list, u8 item);
Bool AiFindClosestTerrainPosition(u8 const* terrainList, int flags, struct Vec2* out);
u8 AiGetPositionRange(int x, int y);
Bool AiFindClosestTerrainAdjacentPosition(u8 const* terrainList, int flags, struct Vec2* out);
Bool AiFindClosestUnlockPosition(int flags, struct Vec2* out);
int AiCountUnitsInRange(void);
int AiCountEnemyUnitsInRange(void);
int AiCountAlliedUnitsInRange(void);
int AiCountNearbyUnits(short x, short y);
int AiCountNearbyEnemyUnits(short x, short y);
int AiCountNearbyAlliedUnits(short x, short y);
void AiMakeMoveRangeMapsForUnitAndWeapon(struct Unit* unit, u16 item);
void AiMakeMoveRangeUnitPowerMaps(struct Unit* unit);
void AiMakeMoveRangeMapsForUnitAndWeapon2(struct Unit* unit, u16 item);
Bool AiFindBestAdjacentPositionByFunc(int x, int y, u8(*func)(int x, int y), struct Vec2* out);
int AiGetItemStealRank(u16 item);
s8 AiGetUnitStealItemSlot(struct Unit* unit);
Bool AiFindSafestReachableLocation(struct Unit* unit, struct Vec2* out);
Bool AiFindPillageLocation(struct Vec2* out, u8* outItemSlot);
Bool AiGetChestUnlockItemSlot(u8* out);
void AiTryMoveTowards(short x, short y, u8 action, u8 maxDanger, u8 arg_4);
Bool AiGetUnitClosestValidPosition(struct Unit* unit, short x, short y, struct Vec2* out);
u8 AiGetJobRank(u8 jid);
Bool AiUnitWithPidExists(u16 pid);
Bool AiIsWithinRectDistance(short x, short y, u8 x2, u8 y2, u8 maxDistance);
Bool AiLocationIsPillageTarget(u8 x, u8 y);
void sub_80308B0(void);
void sub_8030968(struct Unit* unit, u16 item);
void sub_8030994(struct Unit* unit, u16 item);
void sub_80309E0(struct Unit* unit);
void UnitInitAiFromInfo(struct Unit* unit, struct UnitInfo const* info);
Bool sub_8030AB4(struct Vec2* out);
int sub_8030B94(void);
int sub_8030BDC(void);
Bool AiUnitHasAnyStaff(struct Unit* unit);
void sub_8030CBC(struct Unit* unit);
