#pragma once

// EventScr @ 086705D8
EventScr CONST_DATA EventScr_Unk_086705D8[] =
{
    EvtGotoIfNotFlag(0, FLAG_105)

    EvtSetFlag(FLAG_CHAPTER16_12)

EvtLabel(0)
    EvtFlashCursorUnit(PID_NARCIAN)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_6)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_156)
    EvtClearTalk
    EvtLoadUnits(UnitInfo_Unk_0867EFF4)
    EvtMoveWait
    EvtUnitCameraOff
    EvtMoveUnit(PID_MURDOCK, 7, 13)
    EvtMoveWait
    EvtRemoveUnit(PID_MURDOCK)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_6)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_157)
    EvtClearTalk
    EvtFadeBgmOut(1)
    EvtOverrideBgm(SONG_02)
    EvtCameraUnit(PID_DOUGLAS)
    EvtTalk(MSG_159)
    EvtClearTalk
    EvtCameraUnit(PID_UNKNOWN_61)
    EvtMoveUnit(PID_UNKNOWN_61, 3, 11)
    EvtMoveWait
    EvtRemoveUnit(PID_UNKNOWN_61)
    EvtCameraUnit(PID_UNKNOWN_5E)
    EvtMoveUnit(PID_UNKNOWN_5E, 3, 11)
    EvtMoveWait
    EvtRemoveUnit(PID_UNKNOWN_5E)
    EvtCameraUnit(PID_DOUGLAS)
    EvtTalk(MSG_15A)
    EvtClearTalk
    EvtLoadUnitsParty(UnitInfo_Unk_0867EBA4)
    EvtMoveWait
    EvtSetBgm(SONG_24)
    EvtCameraUnit(PID_ROY)
    EvtFlashCursorUnit(PID_ROY)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_6)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_158)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867074C
EventScr CONST_DATA EventScr_Unk_0867074C[] =
{
    EvtOverrideBgm(SONG_05)
    EvtCamera(1, 1)
    EvtLoadUnits(UnitInfo_Unk_0867EFA4)
    EvtMoveWait
    EvtTalk(MSG_15B)
    EvtClearTalk
    EvtMoveUnit(PID_ZEISS, 1, 4)
    EvtMoveWait
    EvtSleep(32)
    EvtLoadUnits(UnitInfo_Unk_0867EFC4)
    EvtMoveWait
    EvtTalk(MSG_15C)
    EvtClearTalk
    EvtMoveUnit(PID_ZEISS, 1, 2)
    EvtMoveWait
    EvtTalk(MSG_15D)
    EvtClearTalk
    EvtMoveUnit(PID_GALLE, 1, 0)
    EvtMoveWait
    EvtRemoveUnit(PID_GALLE)
    EvtTalk(MSG_15E)
    EvtClearTalk
    EvtMoveUnit(PID_ZEISS, 1, 0)
    EvtMoveWait
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08670800
EventScr CONST_DATA EventScr_Unk_08670800[] =
{
    EvtGotoIfNotFunc(9, IsHughNonBlue)

    EvtOverrideBgm(SONG_3B)
    EvtCameraUnit(PID_HUGH)
    EvtTalk(MSG_15F)
    EvtClearTalk
    EvtRestoreBgm

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867083C
EventScr CONST_DATA EventScr_Unk_0867083C[] =
{
    EvtGotoIfFlag(9, FLAG_105)

    EvtGotoIfFlag(9, FLAG_112)

    EvtOverrideBgm(SONG_32)
    EvtLoadUnits(UnitInfo_Unk_0867EF74)
    EvtMoveWait
    EvtCameraUnit(PID_CATH)
    EvtTalk(MSG_160)
    EvtClearTalk
    EvtRestoreBgm

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08670890
EventScr CONST_DATA EventScr_Unk_08670890[] =
{
    EvtNoSkipNoTextSkip
    EvtTalk(MSG_161)
    EvtClearTalk
    EvtGotoIfFunc(1, func_fe6_0806C524)

    EvtGotoIfFunc(2, func_fe6_0806C540)

    EvtGotoIfFunc(3, func_fe6_0806C55C)

    EvtGotoIfFunc(4, func_fe6_0806C578)

    EvtTalk(MSG_162)
    EvtClearTalk
    EvtGoto(0)

EvtLabel(1)
    EvtTalk(MSG_163)
    EvtClearTalk
    EvtGotoIfNotFunc(2, func_fe6_0806C594)

    EvtSetFlag(FLAG_CHAPTER16_15)
    EvtGoto(10)

EvtLabel(2)
    EvtTalk(MSG_165)
    EvtClearTalk
    EvtTalk(MSG_163)
    EvtClearTalk
    EvtGotoIfNotFunc(3, func_fe6_0806C594)

    EvtSetFlag(FLAG_CHAPTER16_16)
    EvtGoto(10)

EvtLabel(3)
    EvtTalk(MSG_166)
    EvtClearTalk
    EvtTalk(MSG_163)
    EvtClearTalk
    EvtGotoIfNotFunc(4, func_fe6_0806C594)

    EvtSetFlag(FLAG_CHAPTER16_17)
    EvtGoto(10)

EvtLabel(4)
    EvtTalk(MSG_167)
    EvtClearTalk
    EvtTalk(MSG_163)
    EvtClearTalk
    EvtGotoIfNotFunc(7, func_fe6_0806C594)

    EvtSetFlag(FLAG_CHAPTER16_18)
    EvtGoto(10)

EvtLabel(7)
    EvtTalk(MSG_168)
    EvtClearTalk
    EvtGoto(0)

EvtLabel(10)
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_164)
    EvtClearTalk
    EvtChangeFaction(PID_HUGH, FACTION_BLUE)
    EvtFunc(func_fe6_0806D064)
    EvtRestoreBgm

EvtLabel(0)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08670A28
EventScr CONST_DATA EventScr_Unk_08670A28[] =
{
    EvtOverrideBgm(SONG_25)
    EvtTalk(MSG_169)
    EvtClearTalk
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08670A48
EventScr CONST_DATA EventScr_Unk_08670A48[] =
{
    EvtOverrideBgm(SONG_25)
    EvtTalk(MSG_16A)
    EvtClearTalk
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08670A68
EventScr CONST_DATA EventScr_Unk_08670A68[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_16B)
    EvtClearTalk
    EvtChangeFaction(PID_ZEISS, FACTION_BLUE)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08670A94
EventScr CONST_DATA EventScr_Unk_08670A94[] =
{
    EvtOverrideBgm(SONG_25)
    EvtTalk(MSG_16C)
    EvtClearTalk
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08670AB4
EventScr CONST_DATA EventScr_Unk_08670AB4[] =
{
    EvtOverrideBgm(SONG_25)
    EvtTalk(MSG_16D)
    EvtClearTalk
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08670AD4
EventScr CONST_DATA EventScr_Unk_08670AD4[] =
{
    EvtOverrideBgm(SONG_25)
    EvtTalk(MSG_16E)
    EvtClearTalk
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08670AF4
EventScr CONST_DATA EventScr_Unk_08670AF4[] =
{
    EvtGotoIfFlag(3, FLAG_110)

    EvtSetBgm(SONG_27)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_6)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_171)
    EvtClearTalk
    EvtSleep(64)
    EvtNextChapter(CHAPTER_16X)
    EvtSleep(1)
    EvtKill
    EvtGoto(9)

EvtLabel(3)
    EvtSetBgm(SONG_2B)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_6)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_172)
    EvtClearTalk
    EvtSleep(64)
    EvtGotoIfNotFunc(7, AreWeGoingToSacae)

    EvtNextChapter(CHAPTER_17_S)
    EvtSleep(1)
    EvtKill
    EvtGoto(9)

EvtLabel(7)
    EvtNextChapter(CHAPTER_17_I)
    EvtSleep(1)
    EvtKill

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};
