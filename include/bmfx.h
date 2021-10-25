#pragma once

#include "common.h"

#include "proc.h"
#include "unit.h"
#include "menu.h"

int sub_801C160(int xa, int ya, int xb, int yb);
void StartRescueTransferAnim(struct Unit* unit, int facing, bool arg_2, ProcPtr parent);
void StartRescueTransferAnimParentless(struct Unit* unit, int facing);
void StartMapFade(bool locksGame);
bool IsMapFadeActive(void);
void HandleGiveUnitItem(struct Unit* unit, int item, ProcPtr parent);
int sub_801C620(struct MenuProc* menu, struct MenuEntProc* ent);
int sub_801C62C(struct MenuProc* menu, struct MenuEntProc* ent);
int sub_801C670(struct MenuProc* menu, struct MenuEntProc* ent);
int sub_801C6B0(struct MenuProc* menu, struct MenuEntProc* ent);
void SetFogVision(int vision);
void sub_801C700(struct Unit* actor, struct Unit* target);
void StartEquipInfoWindow(ProcPtr parent, struct Unit* unit, int x, int y);
void UpdateEquipInfoWindow(int item_slot);
void EndEquipInfoWindow(void);
void sub_801CF10(ProcPtr parent, struct Unit* unit, int x, int y);
void sub_801D680(int x, int y);
void StartGasTrapAnim(ProcPtr parent, int x, int y, int facing);
void StartFireTrapAnim(ProcPtr parent, int x, int y);
void StartArrowTrapAnim(ProcPtr parent, int x);
void sub_801D920(ProcPtr parent, int unused, int trapid);
void StartPikeTrapAnim(ProcPtr parent, int x, int y, int facing);
void sub_801DA54(ProcPtr parent, int icon, char const* str);
void StartGameOverScreen(ProcPtr parent);

extern struct ProcScr CONST_DATA ProcScr_InitPhaseCursor[];
extern struct ProcScr CONST_DATA ProcScr_Unk_085C5988[];
extern struct ProcScr CONST_DATA ProcScr_PhaseIntro[];
extern struct ProcScr CONST_DATA ProcScr_ChapterIntro[];
