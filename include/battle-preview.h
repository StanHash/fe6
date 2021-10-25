#pragma once

#include "common.h"

#include "proc.h"

void StartBattlePreview(void);
void UpdateBattlePreviewContents(void);
void CloseBattlePreview(void);
int StartBattlePreviewHelpBox(ProcPtr parent);

void sub_802E460(struct GenericProc* proc);
void sub_802E490(struct GenericProc* proc);

extern struct ProcScr CONST_DATA ProcScr_BattlePreview[];
