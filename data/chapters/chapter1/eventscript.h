#pragma once

EventScr CONST_DATA EventScr_Chapter1_Opening[] =
{
    EvtUnitCameraOff
    EvtLoadUnits(UnitInfo_Chapter1_RedA)
    EvtMoveWait
    EvtFlashCursorUnit(PID_CHAPTER1_4A)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_001)
    EvtClearTalk
    EvtCamera(7, 9)
    EvtLoadUnits(UnitInfo_Chapter1_Pillager)
    EvtMoveWait
    EvtFlashCursor(7, 7)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_002)
    EvtClearTalk
    EvtMoveUnit(PID_CHAPTER1_PILLAGER, 4, 9)
    EvtMoveWait
    EvtPlaySe(SONG_AB)
    EvtMapChangePosition(4, 8)
    EvtFlashCursor(5, 4)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_003)
    EvtTalkMore(MSG_004)
    EvtClearTalk
    EvtMoveWait
    EvtSleep(16)
    EvtCamera(8, 12)
    EvtUnitCameraOff
    EvtSleep(16)
    EvtLoadUnits(UnitInfo_Chapter1_RedB)
    EvtCamera(8, 17)
    EvtLoadUnits(UnitInfo_Chapter1_RedC)
    EvtMoveWait
    EvtSleep(16)
    EvtLoadUnits(UnitInfo_Chapter1_BlueA)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Chapter1_BlueB)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Chapter1_Lance)
    EvtMoveWait
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_006)
    EvtClearTalk
    EvtMoveUnit(PID_LANCE, 4, 18)
    EvtMoveWait
    EvtFunc(AddFiveThousandGold)
    EvtFunc(ApplyAllHardModeBonusLevels)
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter1_FirstRedTurn[] =
{
    EvtSetBgm(SONG_02)
    EvtCamera(5, 3)
    EvtMoveWait
    EvtMoveUnit(PID_CHAPTER1_4A, 5, 4)
    EvtMoveWait
    EvtSleep(16)
    EvtTalk(MSG_008)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter1_UnusedTalk[] =
{
    EvtSetBgm(SONG_27)
    EvtTalk(MSG_009)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter1_Village[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_00A)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveMoney(5000)
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter1_TopVillageDummy[] =
{
    EvtNoSkip
    EvtGiveMoney(5000)
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter1_HouseA[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_00B)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter1_HouseB[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_00C)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter1_HouseC[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_00D)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter1_HouseUnused[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_6)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_00E)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter1_Victory[] =
{
    EvtSetBgm(SONG_27)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_011)
    EvtGotoIfNotFunc(0, IsBorsBlue)

    EvtTalkMore(MSG_012)

EvtLabel(0)
    EvtTalkMore(MSG_013)
    EvtTalkContinue
    EvtClearTalk
    EvtSleep(64)
    EvtNextChapter(CHAPTER_2)
    EvtSleep(1)
    EvtKill
    EvtClearSkip
    EvtEnd
};
