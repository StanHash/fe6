#pragma once

// EventScr @ 0866EDE8
EventScr CONST_DATA EventScr_Unk_0866EDE8[] =
{
    EvtGotoIfNotFlag(0, FLAG_105)

    EvtSetFlag(FLAG_CHAPTER12_9)

EvtLabel(0)
    EvtSetFlag(FLAG_CHAPTER12_7)
    EvtSetFlag(FLAG_CHAPTER12_8)
    EvtLoadUnits(UnitInfo_Unk_0867D938)
    EvtMoveWait
    EvtCameraUnit(PID_UNKNOWN_55)
    EvtMoveUnit(PID_UNKNOWN_55, 9, 2)
    EvtMoveWait
    EvtTalk(MSG_104)
    EvtClearTalk
    EvtMoveUnit(PID_UNKNOWN_55, 8, 2)
    EvtMoveWait
    EvtMoveUnit(PID_UNKNOWN_5E, 12, 6)
    EvtMoveWait
    EvtRemoveUnit(PID_UNKNOWN_5E)
    EvtMoveUnit(PID_UNKNOWN_55, 9, 1)
    EvtMoveWait
    EvtTalk(MSG_105)
    EvtClearTalk
    EvtSleep(16)
    EvtSetBgm(SONG_24)
    EvtLoadUnitsParty(UnitInfo_Unk_0867D538)
    EvtMoveWait
    EvtCameraUnit(PID_ROY)
    EvtGotoIfNotFlag(7, FLAG_106)

    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_106)
    EvtClearTalk
    EvtGoto(9)

EvtLabel(7)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_107)
    EvtClearTalk

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866EF30
EventScr CONST_DATA EventScr_Unk_0866EF30[] =
{
    EvtOverrideBgm(SONG_06)
    EvtCameraUnit(PID_UNKNOWN_55)
    EvtUnitCameraOff
    EvtMoveUnit(PID_RAIGH, 9, 8)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0867D918)
    EvtMoveWait
    EvtMoveUnit(PID_UNKNOWN_58, 9, 2)
    EvtMoveWait
    EvtTalk(MSG_108)
    EvtClearTalk
    EvtMoveUnit(PID_UNKNOWN_58, 8, 2)
    EvtMoveWait
    EvtMoveUnit(PID_UNKNOWN_55, 12, 6)
    EvtMoveWait
    EvtRemoveUnit(PID_UNKNOWN_55)
    EvtSleep(16)
    EvtMoveUnit(PID_UNKNOWN_58, 9, 1)
    EvtMoveWait
    EvtCameraUnit(PID_RAIGH)
    EvtTalk(MSG_109)
    EvtClearTalk
    EvtUnitCameraOn
    EvtMoveUnit(PID_RAIGH, 3, 11)
    EvtMoveWait
    EvtSleep(16)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866EFF8
EventScr CONST_DATA EventScr_Unk_0866EFF8[] =
{
    EvtGotoIfFlag(9, FLAG_105)

    EvtGotoIfFlag(9, FLAG_112)

    EvtOverrideBgm(SONG_32)
    EvtLoadUnits(UnitInfo_Unk_0867D8C8)
    EvtMoveWait
    EvtTalk(MSG_10A)
    EvtClearTalk
    EvtRestoreBgm

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866F044
EventScr CONST_DATA EventScr_Unk_0866F044[] =
{
    EvtGotoIfFlag(8, FLAG_CHAPTER12_2)

    EvtLoadUnits(UnitInfo_Unk_0867D7E8)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0867D878)
    EvtMoveWait

EvtLabel(8)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866F078
EventScr CONST_DATA EventScr_Unk_0866F078[] =
{
    EvtGotoIfFlag(9, FLAG_CHAPTER12_2)

    EvtOverrideBgm(SONG_06)
    EvtCamera(9, 1)
    EvtFlashCursor(9, 1)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_10B)
    EvtClearTalk
    EvtRestoreBgm

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866F0DC
EventScr CONST_DATA EventScr_Unk_0866F0DC[] =
{
    EvtSetBgm(SONG_03)
    EvtSleep(16)
    EvtLowerBgmVolume
    EvtLoadUnits(UnitInfo_Unk_0867D828)
    EvtMoveWait
    EvtTalk(MSG_10C)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866F114
EventScr CONST_DATA EventScr_Unk_0866F114[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_10D)
    EvtClearTalk
    EvtChangeFaction(PID_RAIGH, FACTION_BLUE)
    EvtClearFlag(FLAG_CHAPTER12_8)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866F148
EventScr CONST_DATA EventScr_Unk_0866F148[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_10E)
    EvtClearTalk
    EvtChangeFaction(PID_RAIGH, FACTION_BLUE)
    EvtClearFlag(FLAG_CHAPTER12_7)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866F17C
EventScr CONST_DATA EventScr_Unk_0866F17C[] =
{
    EvtLowerBgmVolume
    EvtTalk(MSG_10F)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866F198
EventScr CONST_DATA EventScr_Unk_0866F198[] =
{
    EvtLowerBgmVolume
    EvtTalk(MSG_110)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866F1B4
EventScr CONST_DATA EventScr_Unk_0866F1B4[] =
{
    EvtSetBgm(SONG_28)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_6)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_113)
    EvtClearTalk
    EvtGotoIfFlag(7, FLAG_118)

    EvtGotoIfFunc(7, func_fe6_0806C49C)

    EvtSetBgm(SONG_27)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_6)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_114)
    EvtClearTalk
    EvtSleep(64)
    EvtNextChapter(CHAPTER_12X)
    EvtSleep(1)
    EvtKill
    EvtGoto(9)

EvtLabel(7)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_6)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_115)
    EvtClearTalk

EvtLabel(8)
    EvtSleep(64)
    EvtNextChapter(CHAPTER_13)
    EvtSleep(1)
    EvtKill

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};
