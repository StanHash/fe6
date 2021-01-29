
#pragma once

#include "common.h"

int GetTextPrintDelay(void);
int IsFirstPlaythrough(void);
void InitPlayConfig(int isHardMode);
void ResetBmSt(void);
void StartChapter(struct GenericProc* parent);
void sub_8029084(void);
void ResumeChapterFromSuspend(struct GenericProc* parent);
void sub_8029240(void);
void sub_80292B8(void);
void InitBmDisplay(void);
ProcPtr StartMapMain(struct GenericProc* parent);
void EndMapMain(void);
void CleanupUnitsBeforeChapter(void);
void sub_8029654(void);
