#pragma once

#include "common.h"

void StartUnitInventoryPanel(ProcPtr parent);
void RefreshUnitInventoryPanel(struct Unit * unit);
void RefreshUnitStealInventoryPanel(struct Unit * unit);
void RefreshUnitRepairInventoryPanel(struct Unit * unit);
void StartUnitHpPanel(ProcPtr parent);
void RefreshUnitHpPanel(struct Unit * unit);
void StartUnitHpStatusPanel(ProcPtr proc);
void RefreshUnitHpStatusPanel(struct Unit * unit);
void StartUnitResChangePanel(ProcPtr proc);
void RefreshUnitResChangePanel(struct Unit * unit);
void StartUnitStaffOffensePanel(ProcPtr proc);
void RefreshUnitStaffOffensePanel(struct Unit * unit, int accuracy);
void RefreshUnitTakeRescuePanels(ProcPtr proc);
void RefreshUnitRescuePanels(struct Unit * unit);
void RefreshUnitTakePanels(struct Unit * unit);
void StartUnitGiveRescuePanels(ProcPtr parent);
void RefreshUnitGivePanels(struct Unit * unit);
