#pragma once

#include "common.h"

#include "proc.h"
#include "text.h"

// TODO: "StatScreen" vs. "StatusScreen" may be a bit confusing?
// do we need to rename one or the other?

struct StatusScreenSt
{
    /* 00 */ i32 page;
    /* 04 */ bool8 in_transition;
    /* 05 */ bool8 put_playthrough_number;
    /* 08 */ i32 trial_something_width;
    /* 0C */ i32 trial_something_height;
    /* 10 */ struct Text text[14];
};

// shared layout (not that there's much to it)
struct StatusScreenProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2C);
    /* 2C */ i32 slide_direction;
    /* 30 */ STRUCT_PAD(0x30, 0x4A);
    /* 4A */ i16 slide_target_page;
    /* 4C */ i16 clock;
};

void func_fe6_08073548(struct StatusScreenProc * proc);
void func_fe6_0807355C(struct StatusScreenProc * proc);
void func_fe6_08073570(struct StatusScreenProc * proc);
void func_fe6_08073598(struct StatusScreenProc * proc);
void StatusScreenSprites_Loop(struct StatusScreenProc * proc);
char const * GetRedLeaderName(void);
void func_fe6_080736C8(void);
void func_fe6_0807372C(struct StatusScreenProc * proc);
void func_fe6_08073808(struct StatusScreenProc * proc);
void func_fe6_080738FC(struct StatusScreenProc * proc);
void DrawStatusScreenPageA(int unused);
void func_fe6_08073AC8(struct StatusScreenProc * proc);
void DrawStatusScreenPageB(int unused);
void DrawStatusScreenPage(struct StatusScreenProc * proc, int page);
void StatusScreen_Init(struct StatusScreenProc * proc);
void StatusScreenPageSlide_Loop(struct StatusScreenProc * proc);
void StatusScreenPageSlide_Init(struct StatusScreenProc * proc);
void StatusScreenPageSlide_Fini(struct StatusScreenProc * proc);
void StartStatusScreenPageSlide(struct StatusScreenProc * parent, int direction, int page);
void func_fe6_08073F90(struct StatusScreenProc * proc);
void func_fe6_08073FE0(int is_first_playthrough);
void func_fe6_08074084(struct StatusScreenProc * proc);
void func_fe6_080740D0(void);
void func_fe6_080740E4(void);
void StatusScreen_Loop(struct StatusScreenProc * proc);
void StatusScreen_InitPlaythroughCount(struct StatusScreenProc * proc);
void StartStatusScreen(ProcPtr parent);
