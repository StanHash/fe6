#pragma once

#include "common.h"

int GetTextPrintDelay(void);
int IsFirstPlaythrough(void);
void InitPlayConfig(int is_hard);
void ResetBmSt(void);
void StartChapter(struct GenericProc* parent);
void func_fe6_08029084(void);
void ResumeChapterFromSuspend(struct GenericProc* parent);
void func_fe6_08029240(void);
void func_fe6_080292B8(void);
void InitBmDisplay(void);
ProcPtr StartMapMain(struct GenericProc* parent);
void EndMapMain(void);
void CleanupUnitsBeforeChapter(void);
void func_fe6_08029654(void);
