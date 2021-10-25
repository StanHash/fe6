#pragma once

#include "common.h"

#include "unit.h"
#include "map-select.h"

bool CanUnitUseItem(struct Unit* unit, int item);
int GetUnitItemCantUseMsg(struct Unit* unit, int item);
void DoUseUnitItem(struct Unit* unit, int item);

bool CanUnitUseHealItem(struct Unit* unit);
bool CanUnitUseBindingBladeToHeal(struct Unit* unit);
bool CanUnitUsePureWaterItem(struct Unit* unit);
bool CanUnitUseTorchItem(struct Unit* unit);
bool CanUnitUseAntitoxinItem(struct Unit* unit);
bool CanUnitUseChestKeyItem(struct Unit* unit);
bool CanUnitUseDoorKeyItem(struct Unit* unit);
bool CanUnitUseBridgeKeyItem(struct Unit* unit);
bool CanUnitUseLockpickItem(struct Unit* unit);
bool CanUnitUsePromotionItem(struct Unit* unit, int item);
bool CanUnitUseStatGainItem(struct Unit* unit, int item);

void DoUseRescueStaff(struct Unit* unit, void(*list_targets)(struct Unit* unit));
void DoUseWarpStaff(struct Unit* unit);
void DoUseUnlockStaff(struct Unit* unit, void(*list_targets)(struct Unit* unit));
void DoUseRepairStaff(struct Unit* unit);
void DoUseHealStaff(struct Unit* unit, void(*list_targets)(struct Unit* unit));
void DoUseRestoreStaff(struct Unit* unit, void(*list_targets)(struct Unit* unit));
void DoUseBarrierStaff(struct Unit* unit);
void DoUseAttackStaff(struct Unit* unit, void(*list_targets)(struct Unit* unit));

// StaffSelectOnSelect
// WarpOnSelectTarget
// UnlockOnSelectTarget
// sub_8023CA4
// RepairSelectOnChange
// RepairSelectOnInit
// RepairMenuEntOnChange
// RepairMenuEntOnChangeOut
// RepairMenuItemIsAvailable
// RepairMenuItemDraw
// RepairMenuItemSelect
// BarrierSelectOnInit
// BarrierSelectOnChange
// AttackStaffSelectOnInit
// AttackStaffSelectOnChange
// sub_8024020
// sub_802402C
// sub_802406C
