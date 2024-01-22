#pragma once

#include "prelude.h"

void ApplyHazardHealing(ProcPtr proc, struct Unit * unit, int arg_2, int arg_3);
void BeginUnitHealAnim(struct Unit * unit, int hp);
void BeginPoisonDamageAnim(struct Unit * unit, int damage);
void BeginUnitTrapDamageAnim(struct Unit * unit, int damage);
void StartStatusHealEffect(struct Unit * unit, ProcPtr parent);
void FinishDamageDisplay(ProcPtr proc);

extern struct ProcScr CONST_DATA ProcScr_Unused_KillAllRedUnits[];
extern struct ProcScr CONST_DATA ProcScr_TerrainHealDisplay[];
extern struct ProcScr CONST_DATA ProcScr_PoisonDamageDisplay[];
extern struct ProcScr CONST_DATA ProcScr_StatusDecayDisplay[];
extern struct ProcScr CONST_DATA ProcScr_TrapDamageDisplay[];
