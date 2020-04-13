
#pragma once

#include "common.h"
#include "proc.h"

enum
{
    GAME_ACTION_0,
    GAME_ACTION_1,
    GAME_ACTION_2,
    GAME_ACTION_3,
    GAME_ACTION_4,
    GAME_ACTION_5,
    GAME_ACTION_6,
    GAME_ACTION_7,
    GAME_ACTION_8,
};

void CleanupGame(ProcPtr proc);
void StartGame(void);
void SetNextGameAction(int action);
void SetNextChapter(int chapter);
Bool HasNextChapter(void);
void RestartGameAndChapter(void);
void RestartGameAndLoadSuspend(void);
void ForceEnableSounds(void);
void sub_8013A64(void);
