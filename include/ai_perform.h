#ifndef AI_PERFORM_H
#define AI_PERFORM_H

#include "prelude.h"

#include "proc.h"
#include "ai.h"

void AiStartActionCursor(int x, int y, int kind, ProcPtr parent);
void AiEndMuAndRefreshUnits(void);

extern struct ProcScr CONST_DATA ProcScr_AiPerform[];

#endif // AI_PERFORM_H
