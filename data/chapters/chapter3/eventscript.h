#pragma once

EventScr CONST_DATA EventScr_Chapter3_Opening[] =
{
    EvtCamera(19, 2)
    EvtSleep(16)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_063)
    EvtClearTalk
    EvtUnitCameraOff
    EvtLoadUnitsParty(UnitInfo_Chapter3_Blue)
    EvtMoveWait
    EvtSetBgm(SONG_33)
    EvtCameraUnit(PID_ROY)
    EvtSleep(16)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_064)
    EvtSetBgm(SONG_24)
    EvtTalkContinue
    EvtClearTalk
    EvtSleep(64)
    EvtLoadUnits(UnitInfo_Chapter3_Chad)
    EvtMoveWait
    EvtCameraUnit(PID_ROY)
    EvtFunc(ApplyAllHardModeBonusLevels)
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter3_OrphanageCutscene[] =
{
    EvtSetBgm(SONG_0A)
    EvtCamera(0, 0)
    EvtUnitCameraOff
    EvtFlashCursor(3, 3)
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_065)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtLoadUnits(UnitInfo_Chapter3_CutsceneBishop)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Chapter3_CutsceneChildren)
    EvtMoveWait
    EvtMoveUnit(PID_UNKNOWN_56, 5, -1)
    EvtMoveUnit(PID_CATH, 5, -1)
    EvtMoveUnit(PID_RAIGH, 6, -1)
    EvtMoveUnit(PID_LILINA, 4, -1)
    EvtMoveWait
    EvtRemoveUnit(PID_UNKNOWN_56)
    EvtRemoveUnit(PID_CATH)
    EvtRemoveUnit(PID_RAIGH)
    EvtRemoveUnit(PID_LILINA)
    EvtSleep(64)
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter3_ZephielScene[] =
{
    EvtOverrideBgm(SONG_05)
    EvtSleep(16)
    EvtCamera(21, 3)
    EvtUnitCameraOff
    EvtSleep(16)
    EvtMapChangePosition(19, 4)
    EvtLoadUnits(UnitInfo_Chapter3_ZephielSquad)
    EvtSleep(16)
    EvtMoveUnit(PID_NARCIAN, 19, 5)
    EvtMoveWait
    EvtTalk(MSG_066)
    EvtClearTalk
    EvtSleep(16)
    EvtMoveUnit(PID_NARCIAN, 20, 5)
    EvtMoveWait
    EvtMoveUnit(PID_ZEPHIEL, 19, 5)
    EvtMoveWait
    EvtMoveUnit(PID_ZEPHIEL, 25, 8)
    EvtMoveUnit(PID_IDUNN, 25, 8)
    EvtMoveWait
    EvtRemoveUnit(PID_ZEPHIEL)
    EvtRemoveUnit(PID_IDUNN)
    EvtSleep(16)
    EvtMoveUnit(PID_NARCIAN, 19, 4)
    EvtMoveWait
    EvtSleep(16)
    EvtMoveUnit(PID_UNKNOWN_4C, 19, 5)
    EvtMoveWait
    EvtSleep(16)
    EvtTalk(MSG_067)
    EvtClearTalk
    EvtSleep(16)
    EvtMoveUnit(PID_UNKNOWN_4C, 18, 5)
    EvtMoveWait
    EvtMoveUnit(PID_NARCIAN, 25, 9)
    EvtMoveWait
    EvtRemoveUnit(PID_NARCIAN)
    EvtSleep(16)
    EvtMoveUnit(PID_UNKNOWN_4C, 19, 4)
    EvtMove(16, 5, 17, 4)
    EvtMove(22, 5, 21, 4)
    EvtSleep(16)
    EvtLoadUnits(UnitInfo_Chapter3_CavalierReinforcements)
    EvtMoveWait
    EvtMoveWait
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter3_ChadLughTalk[] =
{
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_068)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter3_TopVillage[] =
{
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtOverrideBgm(SONG_33)
    EvtGotoIfActive(1, PID_CHAD)

    EvtTalk(MSG_06A)
    EvtGoto(9)

EvtLabel(1)
    EvtTalk(MSG_069)
    EvtSetFlag(FLAG_CHAPTER3_CHADLUGHTALK)

EvtLabel(9)
    EvtRestoreBgm
    EvtClearTalk
    EvtLoadUnits(UnitInfo_Chapter3_Lugh)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter3_BottomVillage[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_06B)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_MENDSTAFF)
    EvtClearSkip
    EvtEnd
};

EventScr CONST_DATA EventScr_Chapter3_Victory[] =
{
    EvtSetBgm(SONG_28)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_06E)
    EvtClearTalk
    EvtSleep(64)
    EvtNextChapter(CHAPTER_4)
    EvtSleep(1)
    EvtKill
    EvtClearSkip
    EvtEnd
};
