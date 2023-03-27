#pragma once

// EventScr @ 0866FC0C
EventScr CONST_DATA EventScr_Unk_0866FC0C[] =
{
    EvtFlashCursor(27, 1)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_3)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_135)
    EvtClearTalk
    EvtSetBgm(SONG_09)
    EvtCameraUnit(PID_UNKNOWN_5A)
    EvtFlashCursor(27, 3)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_8)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_136)
    EvtClearTalk
    EvtFadeBgmOut(1)
    EvtFunc(func_fe6_0806D000)
    EvtLoadUnitsParty(UnitInfo_Unk_0867E13C)
    EvtMoveWait
    EvtCameraUnit(PID_ROY)
    EvtTalk(MSG_137)
    EvtClearTalk
    EvtLoadUnits(UnitInfo_Unk_0867E1FC)
    EvtMoveWait
    EvtFunc(func_fe6_0806D01C)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866FCD0
EventScr CONST_DATA EventScr_Unk_0866FCD0[] =
{
    EvtOverrideBgm(SONG_3B)
    EvtLoadUnits(UnitInfo_Unk_0867E42C)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0867E46C)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0867E49C)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0867E4DC)
    EvtMoveWait
    EvtFlashCursorUnit(PID_UNKNOWN_5C)
    EvtTalk(MSG_138)
    EvtClearTalk
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866FD28
EventScr CONST_DATA EventScr_Unk_0866FD28[] =
{
    EvtFunc(func_fe6_0806BFC0)
    EvtFunc(func_fe6_0806DDD4)
    EvtSleep(128)
    EvtCameraUnit(PID_ROY)
    EvtFlashCursorUnit(PID_ROY)
    EvtLowerBgmVolume
    EvtTalk(MSG_139)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtGotoIfFlag(9, FLAG_2)

    EvtCamera(27, 3)
    EvtFlashCursorUnit(PID_ROY)
    EvtLowerBgmVolume
    EvtTalk(MSG_13A)
    EvtClearTalk
    EvtRaiseBgmVolume

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866FDA4
EventScr CONST_DATA EventScr_Unk_0866FDA4[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_13C)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866FDE0
EventScr CONST_DATA EventScr_Unk_0866FDE0[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_13D)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866FE1C
EventScr CONST_DATA EventScr_Unk_0866FE1C[] =
{
    EvtGotoIfFunc(1, func_fe6_0806D028)

    EvtClearFlag(FLAG_CHAPTER14_9)
    EvtGoto(9)

EvtLabel(1)
    EvtNoSkip
    EvtGiveItem(IID_SILENCESTAFF)

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866FE5C
EventScr CONST_DATA EventScr_Unk_0866FE5C[] =
{
    EvtGotoIfFunc(1, func_fe6_0806D028)

    EvtClearFlag(FLAG_CHAPTER14_10)
    EvtGoto(9)

EvtLabel(1)
    EvtNoSkip
    EvtGiveItem(IID_TALISMAN)

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866FE9C
EventScr CONST_DATA EventScr_Unk_0866FE9C[] =
{
    EvtGotoIfFunc(1, func_fe6_0806D028)

    EvtClearFlag(FLAG_CHAPTER14_11)
    EvtGoto(9)

EvtLabel(1)
    EvtNoSkip
    EvtGiveItem(IID_BOOTS)

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866FEDC
EventScr CONST_DATA EventScr_Unk_0866FEDC[] =
{
    EvtGotoIfFunc(1, func_fe6_0806D028)

    EvtClearFlag(FLAG_CHAPTER14_12)
    EvtGoto(9)

EvtLabel(1)
    EvtNoSkip
    EvtGiveItem(IID_SILVERBLADE)

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866FF1C
EventScr CONST_DATA EventScr_Unk_0866FF1C[] =
{
    EvtGotoIfFunc(1, func_fe6_0806D028)

    EvtClearFlag(FLAG_CHAPTER14_13)
    EvtGoto(9)

EvtLabel(1)
    EvtNoSkip
    EvtGiveItem(IID_SPEEDWING)

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866FF5C
EventScr CONST_DATA EventScr_Unk_0866FF5C[] =
{
    EvtGotoIfFunc(1, func_fe6_0806D028)

    EvtClearFlag(FLAG_CHAPTER14_14)
    EvtGoto(9)

EvtLabel(1)
    EvtNoSkip
    EvtGiveItem(IID_SILVERCARD)

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866FF9C
EventScr CONST_DATA EventScr_Unk_0866FF9C[] =
{
    EvtGotoIfFunc(1, func_fe6_0806D028)

    EvtClearFlag(FLAG_CHAPTER14_15)
    EvtGoto(9)

EvtLabel(1)
    EvtNoSkip
    EvtGiveItem(IID_WARPSTAFF)

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866FFDC
EventScr CONST_DATA EventScr_Unk_0866FFDC[] =
{
    EvtGotoIfActive(1, PID_SOPHIA)

    EvtClearFlag(FLAG_CHAPTER14_16)
    EvtGoto(9)

EvtLabel(1)
    EvtLowerBgmVolume
    EvtTalk(MSG_13B)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_GUIDINGRING)

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08670030
EventScr CONST_DATA EventScr_Unk_08670030[] =
{
    EvtGotoIfFunc(7, func_fe6_0806C4B0)

    EvtGotoIfNotFunc(7, func_fe6_0806C224)

    EvtSetBgm(SONG_26)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_8)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_142)
    EvtClearTalk
    EvtSleep(64)
    EvtNextChapter(CHAPTER_14X)
    EvtSleep(1)
    EvtKill
    EvtGoto(9)

EvtLabel(7)
    EvtSetBgm(SONG_26)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_8)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_143)
    EvtClearTalk
    EvtSleep(64)
    EvtNextChapter(CHAPTER_15)
    EvtSleep(1)
    EvtKill

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};
