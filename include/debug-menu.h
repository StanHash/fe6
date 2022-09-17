#pragma once

#include "common.h"
#include "proc.h"
#include "menu.h"

void func_fe6_0801A5AC(void);
void PutDebugTextFrame(int x, int y, int width, char const * str);
fu8 func_fe6_0801A674(struct MenuProc * menu);
fu8 func_fe6_0801A698(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 func_fe6_0801A724(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 func_fe6_0801A748(struct MenuProc * menu, struct MenuEntProc * ent);
u32 func_fe6_0801A760(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 func_fe6_0801A7D4(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 func_fe6_0801A81C(struct MenuProc * menu, struct MenuEntProc * ent);
u32 func_fe6_0801A820(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 func_fe6_0801A89C(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 func_fe6_0801A940(struct MenuProc * menu, struct MenuEntProc * ent);
u32 func_fe6_0801A944(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 func_fe6_0801A9A8(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 func_fe6_0801AA70(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 func_fe6_0801AA74(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 func_fe6_0801AA8C(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 func_fe6_0801AABC(struct MenuProc * menu);
void func_fe6_0801AAE0(void);
fu8 func_fe6_0801AB64(struct MenuProc * menu);
fu8 func_fe6_0801ABE8(struct MenuProc * menu);
fu8 func_fe6_0801AC2C(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 func_fe6_0801ACD8(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 func_fe6_0801AD14(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 func_fe6_0801AD28(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 func_fe6_0801AD3C(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 func_fe6_0801AD4C(struct MenuEntInfo const * info, int id);
fu8 func_fe6_0801AD50(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 func_fe6_0801AD6C(struct MenuEntInfo const * info, int id);
fu8 func_fe6_0801AD84(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 func_fe6_0801ADB4(struct MenuEntInfo const * info, int id);
fu8 func_fe6_0801ADCC(struct MenuProc * menu, struct MenuEntProc * ent);
u32 func_fe6_0801ADEC(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 func_fe6_0801AE60(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 func_fe6_0801AEB8(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 func_fe6_0801AEBC(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 func_fe6_0801AEC8(struct MenuProc * menu, struct MenuEntProc * ent);
u32 DebugCpControlMenu_Entry_Display(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 DebugCpControlMenu_Entry_Idle(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 func_fe6_0801B018(struct MenuProc * menu, struct MenuEntProc * ent);

extern struct ProcScr CONST_DATA ProcScr_DebugMonitor[];
