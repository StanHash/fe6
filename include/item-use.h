
#pragma once

#include "common.h"

#include "unit.h"
#include "map-select.h"

Bool CanUnitUseItem(struct Unit* unit, int item);
int GetUnitItemCantUseMsg(struct Unit* unit, int item);
void DoUseUnitItem(struct Unit* unit, int item);

Bool CanUnitUseHealItem(struct Unit* unit);
Bool CanUnitUseBindingBladeToHeal(struct Unit* unit);
Bool CanUnitUsePureWaterItem(struct Unit* unit);
Bool CanUnitUseTorchItem(struct Unit* unit);
Bool CanUnitUseAntitoxinItem(struct Unit* unit);
Bool CanUnitUseChestKeyItem(struct Unit* unit);
Bool CanUnitUseDoorKeyItem(struct Unit* unit);
Bool CanUnitUseBridgeKeyItem(struct Unit* unit);
Bool CanUnitUseLockpickItem(struct Unit* unit);
Bool CanUnitUsePromotionItem(struct Unit* unit, int item);
Bool CanUnitUseStatGainItem(struct Unit* unit, int item);

void DoUseRescueStaff(struct Unit* unit, void(*listTargets)(struct Unit* unit));
void DoUseWarpStaff(struct Unit* unit);
void DoUseUnlockStaff(struct Unit* unit, void(*listTargets)(struct Unit* unit));
void DoUseRepairStaff(struct Unit* unit);
void DoUseHealStaff(struct Unit* unit, void(*listTargets)(struct Unit* unit));
void DoUseRestoreStaff(struct Unit* unit, void(*listTargets)(struct Unit* unit));
void DoUseBarrierStaff(struct Unit* unit);
void DoUseAttackStaff(struct Unit* unit, void(*listTargets)(struct Unit* unit));

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
