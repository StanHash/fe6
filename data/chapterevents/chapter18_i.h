#pragma once

// EventScr @ 08670ECC
EventScr CONST_DATA EventScr_Unk_08670ECC[] =
{
    EvtFlashCursor(19, 3)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_184)
    EvtClearTalk
    EvtLoadUnitsParty(UnitInfo_Unk_0867F64C)
    EvtMoveWait
    EvtCameraUnit(PID_ROY)
    EvtSetBgm(SONG_2B)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_11)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_185)
    EvtSetBgm(SONG_11)
    EvtTalkContinue
    EvtClearTalk
    EvtCameraUnit(PID_ROY)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08670F64
EventScr CONST_DATA EventScr_Unk_08670F64[] =
{
    EvtGotoIfFlag(9, FLAG_CHAPTER18I_2)

    EvtOverrideBgm(SONG_04)
    EvtCamera(19, 3)
    EvtFlashCursor(19, 3)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_186)
    EvtClearTalk
    EvtCameraUnit(PID_ROY)
    EvtFlashCursorUnit(PID_ROY)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_11)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_187)
    EvtClearTalk
    EvtPlaySe(SONG_C6)
    EvtMapChange(6)
    EvtMapChange(7)
    EvtMapChange(8)
    EvtMapChange(9)
    EvtMapChange(10)
    EvtMapChange(11)
    EvtMapChange(12)
    EvtMapChange(13)
    EvtMapChange(14)
    EvtMapChange(15)
    EvtMapChange(16)
    EvtMapChange(17)
    EvtMapChange(18)
    EvtMapChange(19)
    EvtCamera(19, 28)
    EvtCamera(3, 28)
    EvtCamera(3, 3)
    EvtCamera(19, 3)
    EvtFlashCursor(19, 3)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_188)
    EvtClearTalk
    EvtSetBgm(SONG_24)
    EvtCameraUnit(PID_ROY)
    EvtFlashCursorUnit(PID_ROY)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_11)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_189)
    EvtClearTalk
    EvtRestoreBgm

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08671114
EventScr CONST_DATA EventScr_Unk_08671114[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_10)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_18A)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_GODDESSICON)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867115C
EventScr CONST_DATA EventScr_Unk_0867115C[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_10)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_18B)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_GUIDINGRING)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086711A4
EventScr CONST_DATA EventScr_Unk_086711A4[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_10)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_18C)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_SECRETBOOK)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086711EC
EventScr CONST_DATA EventScr_Unk_086711EC[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_9)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_18D)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08671228
EventScr CONST_DATA EventScr_Unk_08671228[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_9)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_18E)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08671264
EventScr CONST_DATA EventScr_Unk_08671264[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_9)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_18F)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086712A0
EventScr CONST_DATA EventScr_Unk_086712A0[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_9)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_190)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086712DC
EventScr CONST_DATA EventScr_Unk_086712DC[] =
{
    EvtSetBgm(SONG_27)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_193)
    EvtSetBgm(SONG_25)
    EvtTalkContinue
    EvtClearTalk
    EvtSleep(64)
    EvtNextChapter(CHAPTER_19_I)
    EvtSleep(1)
    EvtKill
    EvtClearSkip
    EvtEnd
};
