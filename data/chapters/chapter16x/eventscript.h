#pragma once

// EventScr @ 08675324
EventScr CONST_DATA EventScr_Unk_08675324[] =
{
    EvtFunc(func_fe6_0806D648)
    EvtCameraUnit(PID_UNKNOWN_C6)
    EvtFlashCursorUnit(PID_UNKNOWN_C6)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_15)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_BE6)
    EvtClearTalk
    EvtLoadUnitsParty(UnitInfo_Unk_08684D84)
    EvtMoveWait
    EvtGotoIfFlag(7, FLAG_110)

    EvtLoadUnits(UnitInfo_Unk_08685074)
    EvtMoveWait

EvtLabel(7)
    EvtSetBgm(SONG_0F)
    EvtCameraUnit(PID_ROY)
    EvtFlashCursorUnit(PID_ROY)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_15)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_BE7)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086753E0
EventScr CONST_DATA EventScr_Unk_086753E0[] =
{
    EvtGotoIfNotFunc(9, func_fe6_0806C3BC)

    EvtCameraUnit(PID_UNKNOWN_C6)
    EvtSetAi(PID_UNKNOWN_C7, AI_A_00, AI_B_00, 0)

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08675410
EventScr CONST_DATA EventScr_Unk_08675410[] =
{
    EvtSetBgm(SONG_27)
    EvtGotoIfNotFunc(1, IsDouglasBlue)

    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_15)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_BEB)
    EvtClearTalk
    EvtGoto(2)

EvtLabel(1)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_15)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_BEC)
    EvtClearTalk

EvtLabel(2)
    EvtSetBgm(SONG_2B)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_6)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_172)
    EvtClearTalk
    EvtGotoIfFunc(3, IsDouglasBlue)

    EvtSetBgm(SONG_27)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_3)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_BED)
    EvtClearTalk

EvtLabel(3)
    EvtNoSkip
    EvtGiveItemTo(IID_AUREOLA, PID_ROY)
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
