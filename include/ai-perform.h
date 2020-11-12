
#pragma once

#include "common.h"

#include "proc.h"
#include "ai.h"

void AiStartActionCursor(int x, int y, int kind, ProcPtr parent);
void AiEndMuAndRefreshUnits(void);

extern struct ProcScr CONST_DATA ProcScr_AiPerform[];
