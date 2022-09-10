#pragma once

#include "common.h"

#include "proc.h"
#include "unit.h"
#include "menu.h"

int func_fe6_0801C160(int xa, int ya, int xb, int yb);
void StartRescueTransferAnim(struct Unit* unit, int facing, bool arg_2, ProcPtr parent);
void StartRescueTransferAnimParentless(struct Unit* unit, int facing);
void StartMapFade(bool locksGame);
bool IsMapFadeActive(void);
void HandleGiveUnitItem(struct Unit* unit, int item, ProcPtr parent);
u32 DiscardItemMenu_InventoryEntry_Display(struct MenuProc * menu, struct MenuEntProc * ent);
u32 DiscardItemMenu_ExtraEntry_Display(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 DiscardItemMenu_InventoryEntry_Select(struct MenuProc * menu, struct MenuEntProc * ent);
fu8 DiscardItemMenu_ExtraEntry_Select(struct MenuProc * menu, struct MenuEntProc * ent);
void SetFogVision(int vision);
void func_fe6_0801C700(struct Unit* actor, struct Unit* target);
void StartEquipInfoWindow(ProcPtr parent, struct Unit* unit, int x, int y);
void UpdateEquipInfoWindow(int item_slot);
void EndEquipInfoWindow(void);
void func_fe6_0801CF10(ProcPtr parent, struct Unit* unit, int x, int y);
void MakeActiveMuWatchPosition(int x, int y);
void StartGasTrapAnim(ProcPtr parent, int x, int y, int facing);
void StartFireTrapAnim(ProcPtr parent, int x, int y);
void StartArrowTrapAnim(ProcPtr parent, int x);
void func_fe6_0801D920(ProcPtr parent, int unused, int trapid);
void StartPikeTrapAnim(ProcPtr parent, int x, int y, int facing);
void func_fe6_0801DA54(ProcPtr parent, int icon, char const* str);
void StartGameOverScreen(ProcPtr parent);

extern struct ProcScr CONST_DATA ProcScr_InitPhaseCursor[];
extern struct ProcScr CONST_DATA ProcScr_Unk_085C5988[];
extern struct ProcScr CONST_DATA ProcScr_PhaseIntro[];
extern struct ProcScr CONST_DATA ProcScr_ChapterIntro[];
