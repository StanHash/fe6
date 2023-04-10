#pragma once

EventScr CONST_DATA EventScr_Chapter5_Opening[] =
{
    EvtCamera(2, 14)
    EvtSleep(16)
    EvtTalk(MSG_081)
    EvtClearTalk
    EvtUnitCameraOff
    EvtLoadUnitsParty(UnitInfo_Chapter5_Blue)
    EvtMoveWait
    EvtSetBgm(SONG_24)
    EvtCameraUnit(PID_ROY)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_082)
    EvtClearTalk
    EvtSleep(64)
    EvtFunc(ApplyAllHardModeBonusLevels)
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter5_SaulDorothyScene[] =
{
    EvtOverrideBgm(SONG_32)
    EvtCamera(10, 0)
    EvtUnitCameraOff
    EvtFlashCursor(10, 2)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_083)
    EvtClearTalk
    EvtLoadUnits(UnitInfo_Chapter5_SaulDorothy)
    EvtMoveUnit(PID_SAUL, 20, 5)
    EvtMoveUnit(PID_DOROTHY, 20, 6)
    EvtMoveWait
    EvtRemoveUnit(PID_SAUL)
    EvtRemoveUnit(PID_DOROTHY)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter5_OpenBarrier[] =
{
    EvtGotoIfFunc(1, IsBluePhase)

    EvtClearFlag(FLAG_CHAPTER5_BARRIER)
    EvtGoto(9)

EvtLabel(1)
    EvtLowerBgmVolume
    EvtTalk(MSG_084)
    EvtClearTalk
    EvtMapChangePosition(6, 16)
    EvtGotoIfFlag(7, FLAG_2)

    EvtSleep(32)
    EvtCamera(2, 14)
    EvtTalk(MSG_085)
    EvtClearTalk
    EvtGotoIfNotFunc(7, IsHard)

    EvtLoadUnits(UnitInfo_Chapter5_OpenBarrierReinforcements)

EvtLabel(7)
    EvtRaiseBgmVolume

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter5_Village[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_086)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_GANTSLANCE)
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter5_HouseA[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_087)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter5_HouseB[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_088)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter5_HouseC[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_089)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter5_Victory[] =
{
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_08C)
    EvtSetBgm(SONG_25)
    EvtTalkContinue
    EvtClearTalk
    EvtSleep(64)
    EvtNextChapter(CHAPTER_6)
    EvtSleep(1)
    EvtKill
    EvtClearSkip
    EvtEnd
};
