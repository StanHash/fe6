#pragma once

// EventScr @ 08670BF0
EventScr CONST_DATA EventScr_Unk_08670BF0[] =
{
    EvtSetFlag(FLAG_107)
    EvtUnitCameraOff
    EvtRemoveUnit(PID_UNKNOWN_5E)
    EvtFlashCursor(29, 3)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_6)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_173)
    EvtClearTalk
    EvtLoadUnits(UnitInfo_Unk_0867F4C4)
    EvtMoveWait
    EvtMoveUnit(PID_UNKNOWN_61, 32, 5)
    EvtMoveWait
    EvtRemoveUnit(PID_UNKNOWN_61)
    EvtSleep(16)
    EvtLoadUnits(UnitInfo_Unk_0867F504)
    EvtMoveWait
    EvtSleep(16)
    EvtTalk(MSG_174)
    EvtClearTalk
    EvtMoveUnit(PID_MURDOCK, 28, 12)
    EvtMoveUnit(PID_GALLE, 28, 11)
    EvtMoveWait
    EvtRemoveUnit(PID_MURDOCK)
    EvtRemoveUnit(PID_GALLE)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0867F534)
    EvtMoveWait
    EvtLoadUnitsParty(UnitInfo_Unk_0867F0E4)
    EvtMoveWait
    EvtSetBgm(SONG_24)
    EvtLoadUnits(UnitInfo_Unk_0867F4E4)
    EvtMoveWait
    EvtCameraUnit(PID_ROY)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_175)
    EvtClearTalk
    EvtMoveUnit(PID_YODER, -1, 19)
    EvtMoveWait
    EvtRemoveUnit(PID_YODER)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08670D34
EventScr CONST_DATA EventScr_Unk_08670D34[] =
{
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08670D3C
EventScr CONST_DATA EventScr_Unk_08670D3C[] =
{
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08670D44
EventScr CONST_DATA EventScr_Unk_08670D44[] =
{
    EvtCamera(10, 8)
    EvtPlaySe(SONG_BE)
    EvtMapChangePosition(11, 8)
    EvtSleep(64)
    EvtGotoIfNotFunc(9, func_fe6_0806C35C)

    EvtCamera(29, 3)
    EvtTalk(MSG_179)
    EvtClearTalk
    EvtSetBgm(SONG_0A)
    EvtCameraUnit(PID_ROY)
    EvtTalk(MSG_17A)
    EvtClearTalk

EvtLabel(9)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08670DB4
EventScr CONST_DATA EventScr_Unk_08670DB4[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_17E)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_TINASSTAFF)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08670DFC
EventScr CONST_DATA EventScr_Unk_08670DFC[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_17F)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08670E38
EventScr CONST_DATA EventScr_Unk_08670E38[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_180)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08670E74
EventScr CONST_DATA EventScr_Unk_08670E74[] =
{
    EvtSetBgm(SONG_28)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_6)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_183)
    EvtClearTalk
    EvtSleep(64)
    EvtNextChapter(CHAPTER_18_I)
    EvtSleep(1)
    EvtKill
    EvtClearSkip
    EvtEnd
};
