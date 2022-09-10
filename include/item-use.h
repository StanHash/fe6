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

fu8 StaffMapSelect_Select(struct MapSelectProc * proc, struct SelectTarget * target);
fu8 WarpMapSelect_Select(struct MapSelectProc * proc, struct SelectTarget * target);
fu8 UnlockMapSelect_Select(struct MapSelectProc * proc, struct SelectTarget * target);
fu8 RepairMapSelect_Select(struct MapSelectProc * proc, struct SelectTarget * target);
fu8 RepairMapSelect_SwitchIn(struct MapSelectProc * proc, struct SelectTarget * target);
void RepairMapSelect_Init(struct MapSelectProc * proc);
fu8 RepairItemMenu_Entry_SwitchIn(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 RepairItemMenu_Entry_SwitchOut(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 RepairItemMenu_Entry_Available(struct MenuEntInfo const * info, int id);
u32 RepairItemMenu_Entry_Display(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 RepairItemMenu_Entry_Select(struct MenuProc * menu, struct MenuEntProc * ent);
int RestoreMapSelect_Init(struct MapSelectProc * proc);
fu8 RestoreMapSelect_SwitchIn(struct MapSelectProc * proc, struct SelectTarget * target);
int BarrierMapSelect_Init(struct MapSelectProc * proc);
fu8 BarrierMapSelect_SwitchIn(struct MapSelectProc * proc, struct SelectTarget * target);
int AttackStaffMapSelect_Init(struct MapSelectProc * proc, struct SelectTarget * target);
fu8 AttackStaffMapSelect_SwitchIn(struct MapSelectProc * proc, struct SelectTarget * target);
void SubtitleMapSelect_End(struct MapSelectProc * proc);
