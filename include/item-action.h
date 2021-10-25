#pragma once

#include "common.h"

void DoItemHealStaffAction(ProcPtr proc);
void DoItemRestoreStaffAction(ProcPtr proc);
void DoItemBarrierStaffAction(ProcPtr proc);
void DoItemRescueStaffAction(ProcPtr proc);
void DoItemWarpStaffAction(ProcPtr proc);
void DoItemAttackStaffAction(ProcPtr proc);
void DoItemFortifyStaffAction(ProcPtr proc);
void DoItemUnlockStaffAction(ProcPtr proc);
void DoItemRepairStaffAction(ProcPtr proc);
void DoItemSaintStaffAction(ProcPtr proc);
void DoItemHealSelfAction(ProcPtr proc, int amount);
void DoItemElixirAction(ProcPtr proc);
void DoItemPureWaterAction(ProcPtr proc);
void DoItemTorchAction(ProcPtr proc);
void DoItemAntitoxinAction(ProcPtr proc);
void DoItemKeyAction(void);
void DoItemPromoteAction(void);
void sub_8027DB4(struct Unit* unit, int item);
void DoItemStatBoostAction(ProcPtr proc);
void DoItemAction(ProcPtr proc);
