#pragma once

EventScr CONST_DATA EventScr_Chapter4_Opening[] =
{
    EvtSleep(16)
    EvtCamera(3, 8)
    EvtSleep(16)
    EvtUnitCameraOff
    EvtMoveUnit(PID_NARCIAN, 3, 8)
    EvtMoveWait
    EvtSleep(16)
    EvtRemoveUnit(PID_NARCIAN)
    EvtSleep(16)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_06F)
    EvtClearTalk
    EvtLoadUnits(UnitInfo_Chapter4_Red)
    EvtMoveWait
    EvtSleep(16)
    EvtUnitCameraOn
    EvtMoveUnit(PID_NARCIAN, 13, -1)
    EvtMoveWait
    EvtRemoveUnit(PID_NARCIAN)
    EvtSleep(16)
    EvtCamera(0, 8)
    EvtSleep(16)
    EvtUnitCameraOff
    EvtMoveUnit(PID_UNKNOWN_4D, 3, 8)
    EvtMoveWait
    EvtLoadUnitsParty(UnitInfo_Chapter4_Blue)
    EvtMoveWait
    EvtSleep(16)
    EvtCameraUnit(PID_ROY)
    EvtFunc(ApplyAllHardModeBonusLevels)
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter4_IntroducePirates[] =
{
    EvtSetBgm(SONG_02)
    EvtSleep(16)
    EvtLowerBgmVolume
    EvtLoadUnits(UnitInfo_Chapter4_Pirates)
    EvtMoveWait
    EvtTalk(MSG_070)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter4_ForeshadowClarine[] =
{
    EvtCamera(4, 8)
    EvtLowerBgmVolume
    EvtSleep(16)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_2)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_071)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter4_ClarineComes[] =
{
    EvtCamera(4, 8)
    EvtLowerBgmVolume
    EvtSleep(16)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_072)
    EvtClearTalk
    EvtLoadUnits(UnitInfo_Chapter4_Clarine)
    EvtMoveWait
    EvtTalk(MSG_074)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter4_RutgerComes[] =
{
    EvtGotoIfFlag(9, FLAG_2)

    EvtCamera(4, 9)
    EvtSleep(16)
    EvtSetBgm(SONG_02)
    EvtUnitCameraOff
    EvtLoadUnits(UnitInfo_Chapter4_RutgerSquad)
    EvtMoveWait
    EvtTalk(MSG_073)
    EvtClearTalk

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter4_ForeshadowRutger[] =
{
    EvtGotoIfFlag(9, FLAG_2)

    EvtCamera(3, 8)
    EvtFlashCursor(3, 8)
    EvtSetBgm(SONG_02)
    EvtSleep(16)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_075)
    EvtClearTalk

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter4_UnusedCavalierReinforcements[] =
{
    EvtGotoIfFlag(9, FLAG_2)

    EvtLoadUnits(UnitInfo_Chapter4_CavalierReinforcements)
    EvtMoveWait

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter4_RecruitClarine[] =
{
    EvtOverrideBgm(SONG_33)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_076)
    EvtClearTalk
    EvtChangeFaction(PID_CLARINE, FACTION_BLUE)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter4_RefreshClarine[] =
{
    EvtFunc(RefreshClarine)
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter4_RecruitRutger[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_077)
    EvtClearTalk
    EvtChangeFaction(PID_RUTGER, FACTION_BLUE)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter4_TopRightVillage[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_078)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_DOORKEY)
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter4_NorthVillage[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_079)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_STEELBLADE)
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter4_SouthVillage[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_07A)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_SERAPHROBE)
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter4_HouseA[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_07B)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter4_HouseB[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_07C)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter4_HouseC[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_07D)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter4_Victory[] =
{
    EvtSetBgm(SONG_27)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_080)
    EvtSetBgm(SONG_2B)
    EvtTalkContinue
    EvtClearTalk
    EvtSleep(64)
    EvtNextChapter(CHAPTER_5)
    EvtSleep(1)
    EvtKill
    EvtClearSkip
    EvtEnd
};
