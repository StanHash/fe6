#pragma once

// EventScr @ 08672560
EventScr CONST_DATA EventScr_Unk_08672560[] =
{
    EvtSetFlag(FLAG_CHAPTER23_5)
    EvtSetFlag(FLAG_CHAPTER23_6)
    EvtSetFlag(FLAG_CHAPTER23_7)
    EvtFlashCursorUnit(PID_BRUNNYA)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_3)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_1E8)
    EvtClearTalk
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_1E9)
    EvtClearTalk

EvtLabel(5)
    EvtSetBgm(SONG_3E)
    EvtLoadUnitsParty(UnitInfo_Unk_086814B0)
    EvtMoveWait
    EvtCameraUnit(PID_ROY)
    EvtFlashCursorUnit(PID_ROY)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_1EB)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08672638
EventScr CONST_DATA EventScr_Unk_08672638[] =
{
    EvtCamera(22, 23)
    EvtFlashCursor(22, 23)
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_1EF)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08672684
EventScr CONST_DATA EventScr_Unk_08672684[] =
{
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtGotoIfActive(2, PID_FIR)

    EvtGotoIfActive(3, PID_BARTRE)

    EvtLowerBgmVolume
    EvtTalk(MSG_1F2)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtGoto(9)

EvtLabel(2)
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_1F0)
    EvtClearFlag(FLAG_CHAPTER23_6)
    EvtClearFlag(FLAG_CHAPTER23_7)
    EvtGoto(7)

EvtLabel(3)
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_1F1)
    EvtClearFlag(FLAG_CHAPTER23_5)
    EvtClearFlag(FLAG_CHAPTER23_7)

EvtLabel(7)
    EvtClearTalk
    EvtLoadUnits(UnitInfo_Unk_08681880)
    EvtMoveWait
    EvtFunc(func_fe6_0806D17C)
    EvtSetFlag(FLAG_CHAPTER23_4)
    EvtRestoreBgm

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867276C
EventScr CONST_DATA EventScr_Unk_0867276C[] =
{
    EvtLowerBgmVolume
    EvtTalk(MSG_1EC)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08672788
EventScr CONST_DATA EventScr_Unk_08672788[] =
{
    EvtLowerBgmVolume
    EvtTalk(MSG_1ED)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086727A4
EventScr CONST_DATA EventScr_Unk_086727A4[] =
{
    EvtLowerBgmVolume
    EvtTalk(MSG_1EE)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086727C0
EventScr CONST_DATA EventScr_Unk_086727C0[] =
{
    EvtSetBgm(SONG_27)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_3)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_1F5)
    EvtClearTalk
    EvtSleep(64)
    EvtNextChapter(CHAPTER_24)
    EvtSleep(1)
    EvtKill
    EvtClearSkip
    EvtEnd
};
