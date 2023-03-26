#pragma once

// EventScr @ 08671340
EventScr CONST_DATA EventScr_Unk_08671340[] =
{
    EvtFlashCursorUnit(PID_UNKNOWN_60)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_194)
    EvtClearTalk
    EvtSetBgm(SONG_24)
    EvtLoadUnitsParty(UnitInfo_Unk_0867FA58)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0867FB38)
    EvtMoveWait
    EvtCameraUnit(PID_ROY)
    EvtSleep(16)
    EvtMoveUnit(PID_NIIME, 2, 20)
    EvtMoveWait
    EvtTalk(MSG_195)
    EvtSetBgm(SONG_3F)
    EvtTalkContinue
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086713D4
EventScr CONST_DATA EventScr_Unk_086713D4[] =
{
    EvtSetBgm(SONG_04)
    EvtGotoIfFlag(1, FLAG_CHAPTER19I_2)

    EvtCameraUnit(PID_UNKNOWN_60)
    EvtFlashCursorUnit(PID_UNKNOWN_60)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_196)
    EvtClearTalk

EvtLabel(1)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08671434
EventScr CONST_DATA EventScr_Unk_08671434[] =
{
    EvtGotoIfFlag(1, FLAG_CHAPTER19I_2)

    EvtUnitCameraOff
    EvtLoadUnits(UnitInfo_Unk_0867FDE8)
    EvtMoveWait

EvtLabel(1)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08671460
EventScr CONST_DATA EventScr_Unk_08671460[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_10)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_197)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_AIRCALIBUR)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086714A8
EventScr CONST_DATA EventScr_Unk_086714A8[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_10)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_198)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_ENERGYRING)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086714F0
EventScr CONST_DATA EventScr_Unk_086714F0[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_10)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_199)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867152C
EventScr CONST_DATA EventScr_Unk_0867152C[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_10)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_19A)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08671568
EventScr CONST_DATA EventScr_Unk_08671568[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_10)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_19B)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086715A4
EventScr CONST_DATA EventScr_Unk_086715A4[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_10)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_19C)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086715E0
EventScr CONST_DATA EventScr_Unk_086715E0[] =
{
    EvtSetBgm(SONG_27)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_19F)
    EvtFunc(func_fe6_08012798)
    EvtSleep(30)
    EvtGotoIfSkipped(22)

    EvtFunc(func_fe6_0806CFB8)

EvtLabel(22)
    EvtTalkContinue
    EvtFunc(func_fe6_08012780)
    EvtSleep(30)
    EvtGotoIfSkipped(23)

    EvtFunc(func_fe6_080127B0)

EvtLabel(23)
    EvtTalkContinue
    EvtClearTalk
    EvtSleep(64)
    EvtNextChapter(CHAPTER_20_I)
    EvtSleep(1)
    EvtKill
    EvtClearSkip
    EvtEnd
};
