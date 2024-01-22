#ifndef BATTLE_PREVIEW_H
#define BATTLE_PREVIEW_H

#include "prelude.h"

#include "proc.h"
#include "helpbox.h"

void StartBattlePreview(struct MapSelectProc * proc);
void UpdateBattlePreviewContents(void);
void CloseBattlePreview(void);
fu8 StartBattlePreviewHelpBox(struct MapSelectProc * proc, struct SelectTarget * target);

void HelpBoxPopulateBattlePreviewAdvantageA(struct HelpBoxProc * proc);
void HelpBoxPopulateBattlePreviewAdvantageB(struct HelpBoxProc * proc);

extern struct ProcScr CONST_DATA ProcScr_BattlePreview[];

#endif // BATTLE_PREVIEW_H
