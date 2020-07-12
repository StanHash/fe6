
#pragma once

#include "common.h"

void ForEachUnitInMovement(void(*func)(struct Unit* unit));
void ForEachUnitInRange(void(*func)(struct Unit* unit));
void ForEachPositionInRange(void(*func)(int x, int y));

void EnlistAttackObstacleTargets(void);
void TryEnlistAttackUnitTarget(struct Unit* unit);
void ListAttackTargetsForWeapon(struct Unit* unit, int item);
void TryEnlistTradeUnitTarget(struct Unit* unit);
void ListTradeTargets(struct Unit* unit);
void TryEnlistRescueUnitTarget(struct Unit* unit);
void ListRescueTargets(struct Unit* unit);
void TryEnlistRescueDropPositionTarget(int x, int y);
void ListRescueDropTargets(struct Unit* unit);
void TryEnlistRescueTakeUnitTarget(struct Unit* unit);
void ListRescueTakeTargets(struct Unit* unit);
void TryEnlistRescueGiveUnitTarget(struct Unit* unit);
void ListRescueGiveTargets(struct Unit* unit);
void TryEnlistTalkUnitTarget(struct Unit* unit);
void ListTalkTargets(struct Unit* unit);
void ListSupportTargets(struct Unit* unit);
void sub_8021240(struct Unit* unit);
void sub_8021278(struct Unit* unit);
void TryEnlistDoorPositionTarget(int x, int y);
void TryEnlistBridgePositionTarget(int x, int y);
void ListOpenTerrainTargets(struct Unit* unit, int terrain);
void ListTerrainHealingTargets(int faction);
void ListPoisonDamageTargets(int faction);
void TryEnlistRefreshUnitTarget(struct Unit* unit);
void ListRefreshTargets(struct Unit* unit);
void TryEnlistStealUnitTarget(struct Unit* unit);
void ListStealTargets(struct Unit* unit);
void TryEnlistHealUnitTarget(struct Unit* unit);
void ListAdjacentHealTargets(struct Unit* unit);
void ListRangedHealTargets(struct Unit* unit);
void TryEnlistRestoreUnitTarget(struct Unit* unit);
void ListRestoreTargets(struct Unit* unit);
void TryEnlistBarrierUnitTarget(struct Unit* unit);
void ListBarrierTargets(struct Unit* unit);
void TryEnlistRescueStaffUnitTarget(struct Unit* unit);
void ListRescueStaffTargets(struct Unit* unit);
void TryEnlistSilenceUnitTarget(struct Unit* unit);
void TryEnlistSleepUnitTarget(struct Unit* unit);
void TryEnlistBerserkUnitTarget(struct Unit* unit);
void ListSilenceTargets(struct Unit* unit);
void ListSleepTargets(struct Unit* unit);
void ListBerserkTargets(struct Unit* unit);
void TryEnlistWarpUnitTarget(struct Unit* unit);
void ListWarpTargets(struct Unit* unit);
void ListUnlockTargets(struct Unit* unit);
void TryEnlistRepairUnitTarget(struct Unit* unit);
void ListRepairTargets(struct Unit* unit);
void ListSaintsStaffTargets(struct Unit* unit);
void sub_8021B30(int arg_0);

extern struct Unit* gSubjectUnit;
