#pragma once

// EventScr @ 086747D0
EventScr CONST_DATA EventScr_Unk_086747D0[] =
{
    EvtGotoIfNotFlag(0, FLAG_105)

    EvtSetFlag(FLAG_CHAPTER20S_10)

EvtLabel(0)
    EvtSetFlag(FLAG_CHAPTER20S_8)
    EvtSetFlag(FLAG_CHAPTER20S_9)
    EvtFlashCursor(15, 2)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_9A1)
    EvtClearTalk
    EvtLoadUnitsParty(UnitInfo_Unk_08683DA4)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_08683E84)
    EvtMoveWait
    EvtCameraUnit(PID_ROY)
    EvtFlashCursorUnit(PID_ROY)
    EvtSetBgm(SONG_24)
    EvtTalk(MSG_9A2)
    EvtSetBgm(SONG_3F)
    EvtTalkContinue
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08674880
EventScr CONST_DATA EventScr_Unk_08674880[] =
{
    EvtSetBgm(SONG_12)
    EvtLoadUnits(UnitInfo_Unk_08683ED4)
    EvtMoveWait
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_8)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_9A4)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086748C8
EventScr CONST_DATA EventScr_Unk_086748C8[] =
{
    EvtLoadUnits(UnitInfo_Unk_08684154)
    EvtMoveWait
    EvtTalk(MSG_9A3)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086748E8
EventScr CONST_DATA EventScr_Unk_086748E8[] =
{
    EvtGotoIfFlag(9, FLAG_105)

    EvtGotoIfFlag(9, FLAG_112)

    EvtOverrideBgm(SONG_32)
    EvtLoadUnits(UnitInfo_Unk_08684114)
    EvtMoveWait
    EvtTalk(MSG_9A5)
    EvtClearTalk
    EvtRestoreBgm

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08674934
EventScr CONST_DATA EventScr_Unk_08674934[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_9A6)
    EvtClearTalk
    EvtChangeFaction(PID_DAYAN, FACTION_BLUE)
    EvtClearFlag(FLAG_CHAPTER20S_8)
    EvtClearFlag(FLAG_CHAPTER20S_9)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08674970
EventScr CONST_DATA EventScr_Unk_08674970[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_9A7)
    EvtClearTalk
    EvtChangeFaction(PID_DAYAN, FACTION_BLUE)
    EvtClearFlag(FLAG_CHAPTER20S_9)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086749A4
EventScr CONST_DATA EventScr_Unk_086749A4[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_9A8)
    EvtClearTalk
    EvtChangeFaction(PID_DAYAN, FACTION_BLUE)
    EvtClearFlag(FLAG_CHAPTER20S_8)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086749D8
EventScr CONST_DATA EventScr_Unk_086749D8[] =
{
    EvtLowerBgmVolume
    EvtTalk(MSG_9A9)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086749F4
EventScr CONST_DATA EventScr_Unk_086749F4[] =
{
    EvtLowerBgmVolume
    EvtTalk(MSG_9AA)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08674A10
EventScr CONST_DATA EventScr_Unk_08674A10[] =
{
    EvtSetBgm(SONG_27)
    EvtGotoIfNotFunc(5, IsSueBlue)

    EvtGotoIfNotFunc(5, IsSinBlue)

    EvtGotoIfNotFunc(5, IsDayanBlue)

    EvtGotoIfFunc(5, IsPastTurn25)

    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_8)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_9AD)
    EvtClearTalk
    EvtSleep(64)
    EvtNextChapter(CHAPTER_20X_S)
    EvtSleep(1)
    EvtKill
    EvtGoto(9)

EvtLabel(5)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_8)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_9AE)
    EvtSetBgm(SONG_2B)
    EvtTalkContinue
    EvtSetBgm(SONG_3C)
    EvtTalkContinue
    EvtClearTalk
    EvtSleep(64)
    EvtNextChapter(CHAPTER_21)
    EvtSleep(1)
    EvtKill

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};
