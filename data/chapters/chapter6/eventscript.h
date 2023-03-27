#pragma once

// EventScr @ 0866CB34
EventScr CONST_DATA EventScr_Unk_0866CB34[] =
{
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_08D)
    EvtSetBgm(SONG_02)
    EvtTalkContinue
    EvtClearTalk
    EvtSetBgm(SONG_23)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_8)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_08E)
    EvtClearTalk
    EvtLoadUnitsParty(UnitInfo_Unk_0867AFA0)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0867B050)
    EvtMoveWait
    EvtCameraUnit(PID_ROY)
    EvtUnitCameraOff
    EvtMoveUnit(PID_UNKNOWN_4F, 13, 10)
    EvtMoveUnit(PID_ROY, 13, 18)
    EvtMoveWait
    EvtMoveUnit(PID_UNKNOWN_4F, 13, 17)
    EvtMove(12, 9, 12, 16)
    EvtMove(13, 9, 13, 16)
    EvtMoveWait
    EvtTalk(MSG_08F)
    EvtClearTalk
    EvtMoveUnit(PID_UNKNOWN_4F, 12, 1)
    EvtMove(12, 16, 12, 9)
    EvtMove(13, 16, 13, 9)
    EvtMoveWait
    EvtMoveUnit(PID_ROY, 12, 20)
    EvtMoveWait
    EvtCameraUnit(PID_ROY)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866CC5C
EventScr CONST_DATA EventScr_Unk_0866CC5C[] =
{
    EvtGotoIfFunc(7, func_fe6_0806CEF0)

    EvtClearFlag(FLAG_CHAPTER6_7)
    EvtGoto(9)

EvtLabel(7)
    EvtLoadUnits(UnitInfo_Unk_0867B260)
    EvtMoveWait

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866CC9C
EventScr CONST_DATA EventScr_Unk_0866CC9C[] =
{
    EvtGotoIfFunc(7, func_fe6_0806CF3C)

    EvtClearFlag(FLAG_CHAPTER6_11)
    EvtGoto(9)

EvtLabel(7)
    EvtLoadUnits(UnitInfo_Unk_0867B2B0)
    EvtMoveWait

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866CCDC
EventScr CONST_DATA EventScr_Unk_0866CCDC[] =
{
    EvtOverrideBgm(SONG_32)
    EvtLoadUnits(UnitInfo_Unk_0867B3D0)
    EvtMoveWait
    EvtTalk(MSG_090)
    EvtClearTalk
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866CD08
EventScr CONST_DATA EventScr_Unk_0866CD08[] =
{
    EvtCamera(2, 8)
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_2)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_091)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866CD4C
EventScr CONST_DATA EventScr_Unk_0866CD4C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867B4E0)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0867B520)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866CD6C
EventScr CONST_DATA EventScr_Unk_0866CD6C[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_092)
    EvtClearTalk
    EvtChangeFaction(PID_SUE, FACTION_BLUE)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866CD98
EventScr CONST_DATA EventScr_Unk_0866CD98[] =
{
    EvtMapChangePosition(6, 4)
    EvtMapChangePosition(6, 6)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866CDB0
EventScr CONST_DATA EventScr_Unk_0866CDB0[] =
{
    EvtMapChangePosition(19, 4)
    EvtMapChangePosition(19, 6)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866CDC8
EventScr CONST_DATA EventScr_Unk_0866CDC8[] =
{
    EvtSetBgm(SONG_28)
    EvtGotoIfNotFunc(3, func_fe6_0806C1E4)

    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_8)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_095)
    EvtClearTalk

EvtLabel(3)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_8)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_096)
    EvtClearTalk
    EvtSleep(64)
    EvtNextChapter(CHAPTER_7)
    EvtSleep(1)
    EvtKill
    EvtClearSkip
    EvtEnd
};
