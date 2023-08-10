#pragma once

#include "common.h"

#include "proc.h"
#include "text.h"

struct SubtitleHelpProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ char const * string;
    /* 30 */ struct Font font;
    /* 48 */ struct Text text[2];
    /* 58 */ i16 text_offset;
    /* 5A */ i16 text_show_clock;
    /* 5C */ i16 text_num;
    /* 5E */ i16 text_count;
};

void PutSubtitleHelpText(struct SubtitleHelpProc * proc, int y);
void InitSubtitleHelpText(struct SubtitleHelpProc * proc);
void SubtitleHelpDarkenerOnHBlank(void);

void SubtitleHelpDarkener_Init(ProcPtr proc);
void SubtitleHelpDarkener_FadeIn(ProcPtr proc);
void SubtitleHelpDarkener_FadeOut(ProcPtr proc);

void SubtitleHelp_Init(struct SubtitleHelpProc * proc);
void SubtitleHelp_OnEnd(struct SubtitleHelpProc * proc);
void SubtitleHelp_Loop(struct SubtitleHelpProc * proc);

void StartSubtitleHelp(ProcPtr parent, char const * str);
void EndSubtitleHelp(void);
bool IsSubtitleHelpActive(void);

extern struct ProcScr CONST_DATA ProcScr_SubtitleHelpDarkener[];
extern struct ProcScr CONST_DATA ProcScr_SubtitleHelp[];
