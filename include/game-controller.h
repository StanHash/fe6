
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

enum
{
    L_GAMECTRL_OPENINGSEQ,
    L_GAMECTRL_CLASSDEMO,
    L_GAMECTRL_SCENEDEMO,
    L_GAMECTRL_TITLE,
    L_GAMECTRL_MAINMENU,
    L_GAMECTRL_CHAPTER,
    L_GAMECTRL_LOADSUSPEND,
    L_GAMECTRL_POSTCHAPTER,
    L_GAMECTRL_POSTTRIAL,
    L_GAMECTRL_TUTORIAL,
    L_GAMECTRL_LINK,
    L_GAMECTRL_TRIAL,
    L_GAMECTRL_PREENDING,
    L_GAMECTRL_ENDING,
    L_GAMECTRL_SRAMRESET,
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

extern struct ProcScr CONST_DATA ProcScr_GameController[];
