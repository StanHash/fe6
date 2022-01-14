#pragma once

#include "common.h"

#include "proc.h"

void StartBattlePreview(void);
void UpdateBattlePreviewContents(void);
void CloseBattlePreview(void);
int StartBattlePreviewHelpBox(ProcPtr parent);

void func_fe6_0802E460(struct GenericProc* proc);
void func_fe6_0802E490(struct GenericProc* proc);

extern struct ProcScr CONST_DATA ProcScr_BattlePreview[];
