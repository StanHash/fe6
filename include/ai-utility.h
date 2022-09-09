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

bool AiCompare(u8 const* left, u8 cond, u32 right);
bool AiFindTargetInReachByPid(int pid, struct Vec2i* out);
bool AiFindTargetInReachByJid(int jid, struct Vec2i* out);
bool AiFindTargetInReachByFunc(bool(*func)(struct Unit* unit), struct Vec2i* out);
void AiRandomMove(void);
bool AiReachesByBirdsEyeDistance(struct Unit* unit, struct Unit* other, u16 item);
bool AiCouldReachByBirdsEyeDistance(struct Unit* unit, struct Unit* other, u16 item);
bool AiIsInShortList(u16 const* list, u16 item);
bool AiIsInByteList(u8 const* list, u8 item);
bool AiFindClosestTerrainPosition(u8 const* terrainList, int flags, struct Vec2i* out);
u8 AiGetPositionRange(int x, int y);
bool AiFindClosestTerrainAdjacentPosition(u8 const* terrainList, int flags, struct Vec2i* out);
bool AiFindClosestUnlockPosition(int flags, struct Vec2i* out);
int AiCountUnitsInRange(void);
int AiCountEnemyUnitsInRange(void);
int AiCountAlliedUnitsInRange(void);
int AiCountNearbyUnits(short x, short y);
int AiCountNearbyEnemyUnits(short x, short y);
int AiCountNearbyAlliedUnits(short x, short y);
void AiMakeMoveRangeMapsForUnitAndWeapon(struct Unit* unit, u16 item);
void AiMakeMoveRangeUnitPowerMaps(struct Unit* unit);
void AiMakeMoveRangeMapsForUnitAndWeapon2(struct Unit* unit, u16 item);
bool AiFindBestAdjacentPositionByFunc(int x, int y, u8(*func)(int x, int y), struct Vec2i* out);
int AiGetItemStealRank(u16 item);
i8 AiGetUnitStealItemSlot(struct Unit* unit);
bool AiFindSafestReachableLocation(struct Unit* unit, struct Vec2i* out);
bool AiFindPillageLocation(struct Vec2i* out, u8* outItemSlot);
bool AiGetChestUnlockItemSlot(u8* out);
void AiTryMoveTowards(short x, short y, u8 action, u8 maxDanger, u8 arg_4);
bool AiGetUnitClosestValidPosition(struct Unit* unit, short x, short y, struct Vec2i* out);
u8 AiGetJobRank(u8 jid);
bool AiUnitWithPidExists(u16 pid);
bool AiIsWithinRectDistance(short x, short y, u8 x2, u8 y2, u8 maxDistance);
bool AiLocationIsPillageTarget(u8 x, u8 y);
void func_fe6_080308B0(void);
void func_fe6_08030968(struct Unit* unit, u16 item);
void func_fe6_08030994(struct Unit* unit, u16 item);
void func_fe6_080309E0(struct Unit* unit);
void UnitInitAiFromInfo(struct Unit* unit, struct UnitInfo const* info);
bool func_fe6_08030AB4(struct Vec2i* out);
int func_fe6_08030B94(void);
int func_fe6_08030BDC(void);
bool AiUnitHasAnyStaff(struct Unit* unit);
void func_fe6_08030CBC(struct Unit* unit);
