#pragma once

#include "common.h"

enum
{
    AI_EQUIP_FLAG_MELEE = 1 << 0,
    AI_EQUIP_FLAG_RANGE = 1 << 1,
    AI_EQUIP_FLAG_LOW_USES = 1 << 2,
    AI_EQUIP_FLAG_STAFF = 1 << 3,

#   define AI_EQUIP_FLAG_MIGHT(might) ((might) << 8)
#   define AI_EQUIP_FLAG_MIGHT_MASK AI_EQUIP_FLAG_MIGHT(0xFF)
};

void AiRefreshDangerMap(void);
void AiFillDangerMap(void);
bool AiCheckDangerAt(int x, int y, fu8 threshold);
bool AiTryGetNearestHealPoint(struct Vec2i * pos_out);
void AiUpdateUnitsSeekHealing(void);
bool AiUpdateUnitSeeksHealing(struct Unit * unit);
bool AiTryHealSelf(void);
bool AiTryMoveTowardsEscape(void);
struct AiEscapePt const * AiGetNearestEscapePoint(void);
bool AiCanEquip(void);
bool AiEquipGetFlags(u16 * equip_flags_out);
void AiEquipGetDanger(int x, int y, u16 * range_danger_out, u16 * melee_danger_out, u16 * combined_danger_out);
void AiEquipBestMatch(int equip_flag, u16 const * equip_flags);
void AiEquipBestConsideringDanger(fu16 range_danger, fu16 melee_danger, fu16 combined_danger, u16 const * equip_flags);
void AiUpdateUnitFlagsFromStaff(fu16 item);
bool AiIsWithinFlyingDistance(struct Unit * unit, int x, int y);
int AiGetUnitAttackAndWeapon(struct Unit * unit, u16 * item_out);
void AiTryRefreshOrStealAfterMove(void);
void AiTryActionAfterMove(void);
bool AiTryRefreshAt(int x, int y);
bool AiTryStealAt(int x, int y);
bool AiTryCombatAt(int x, int y);

struct AiCountEnemiesInRangeArg
{
    /* 00 */ u8 move_coeff_q4;
    /* 01 */ u8 attack_range; // move range if 0, attack range otherwise
    /* 02 */ u8 result_slot;
};

struct UnkAiFuncArg_080334F4
{
    /* 00 */ u8 const * unk_00;
    /* 04 */ u8 unk_04;
    /* 05 */ u8 unk_05;
};

struct AiIsInAreaArg
{
    /* 00 */ u8 x1;
    /* 01 */ u8 y1;
    /* 02 */ u8 x2;
    /* 03 */ u8 y2;
};

struct AiDecideTalkArg
{
    /* 00 */ u8 pid_a;
    /* 01 */ u8 pid_b;
};

struct UnkAiFuncArg_08033B04
{
    /* 00 */ u8 action_random_threshold;
    /* 01 */ u8 maximum_heal_percent;
};

struct UnkAiFuncArg_08033B50
{
    /* 00 */ u8 do_anything_threshold;
    /* 01 */ u8 do_offensive_threshold;
};

bool AiFunc_CountEnemiesInRange_IsEnemyAt(int x, int y);
bool AiFunc_CountEnemiesInRange(void const * arg);
bool AiFunc_080334F4(void const * arg);
bool AiFunc_GetCounter(void const * no_input);
bool func_fe6_080336CC(void const * no_input);
bool func_fe6_080336FC(void const * no_input);
bool func_fe6_0803372C(struct Vec2i * pos_out);
bool func_fe6_080337B4(void const * no_input);
bool AiFunc_IsInArea(void const * arg);
bool AiFunc_DecideTalk(void const * arg);
bool func_fe6_08033898(void const * arg);
bool func_fe6_0803395C(struct Unit * unit);
bool func_fe6_08033998(void const * arg);
bool AiIsUnitEnemyCmdResult(struct Unit * unit);
bool AiIsUnitEnemyOnTheWayToCmdResult(struct Unit * unit);
bool AiFunc_AttackCmdResult(void const * no_input);
bool AiFunc_08033B04(void const * arg);
bool AiFunc_08033B50(void const * arg);

int AiGetStaffAttemptId(fu16 item);
bool AiAttemptStaffAction(bool (* is_enemy)(struct Unit * unit));
bool AiGetReachableAdjacentPosition(int x_center, int y_center, struct Vec2i * pos_out);
void AiAttemptHealStaff(int slot, bool (* is_enemy)(struct Unit * unit));
void AiAttemptRangedHealStaff(int slot, bool (* is_enemy)(struct Unit * unit));
void AiAttemptFortifyStaff(int slot, bool (* is_enemy)(struct Unit * unit));
void AiAttemptWarpStaff(int slot, bool (* is_enemy)(struct Unit * unit));
void AiAttemptRestoreStaff(int slot, bool (* is_enemy)(struct Unit * unit));
bool AiIsUnitArmed(struct Unit * unit);
int AiGetSilenceStaffTargetScore(struct Unit * unit);
void AiAttemptSilenceStaff(int slot, bool (* is_enemy)(struct Unit * unit));
void AiAttemptOffensiveStaff(int slot, bool (* is_enemy)(struct Unit * unit));
void AiAttemptBarrierStaff(int slot, bool (* is_enemy)(struct Unit * unit));
bool AiGetGoodWarpPosition(struct Vec2i * pos);
int AiGetConsumableAttemptId(fu16);
bool AiAttemptConsumableAction(void);
void AiAttemptDoorKey(int slot);
void AiAttemptLockpick(int slot);
void AiAttemptAntitoxin(int slot);
fu8 AiGetRangeAt(int x, int y);
bool AiFindGoodDoorKeyUsePosition(struct Unit * unit, struct Vec2i * pos_out);
bool AiFindGoodChestKeyUsePosition(struct Unit * unit, struct Vec2i * pos_out);
int AiFindGoodLockpickUsePosition(struct Unit * unit, int findpos_flags, struct Vec2i * pos_out);

void AiSetWorkingMovTableIgnoringWalls(i8 const * mov_table);
void AiSetWorkingMovTableIgnoringTerrain(i8 const * mov_table, int free_terrain);
void AiMapFlood(struct Unit * unit);
void AiMapFloodRange(struct Unit * unit);
void AiMapFlood_NoWall(struct Unit * unit);
void AiMapFlood_NoWall_Pass(struct Unit * unit);
void AiMapFloodRange_NoDoors(struct Unit * unit);
void AiMapFloodRange_NoDoors_Pass(struct Unit * unit);
void AiMapFloodRange_UpToMove(struct Unit * unit);
void AiUpdateStayFlag(struct Unit * unit);
void AiMapFloodRangeFrom(int x, int y, struct Unit * unit);
