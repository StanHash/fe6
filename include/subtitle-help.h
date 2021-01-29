
#pragma once

#include "common.h"
#include "proc.h"

void StartSubtitleHelp(ProcPtr parent, char const* str);
void EndSubtitleHelp(void);
bool IsSubtitleHelpActive(void);

extern struct ProcScr CONST_DATA ProcScr_SubtitleHelpDarkener[];
extern struct ProcScr CONST_DATA ProcScr_SubtitleHelp[];
