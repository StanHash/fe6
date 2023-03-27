#pragma once

// EventScr @ 0867389C
EventScr CONST_DATA EventScr_Unk_0867389C[] =
{
    EvtSetFlag(FLAG_CHAPTER11B_12)
    EvtRemoveUnit(PID_UNKNOWN_C8)
    EvtLoadUnits(UnitInfo_Unk_08682964)
    EvtMoveWait
    EvtTalk(MSG_96C)
    EvtClearTalk
    EvtCamera(2, 25)
    EvtFlashCursor(2, 25)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_96D)
    EvtClearTalk
    EvtLoadUnits(UnitInfo_Unk_08682AF4)
    EvtMoveWait
    EvtMoveUnit(PID_UNKNOWN_5E, -1, 26)
    EvtMoveWait
    EvtRemoveUnit(PID_UNKNOWN_5E)
    EvtLoadUnits(UnitInfo_Unk_08682824)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_08682AD4)
    EvtMoveWait
    EvtLoadUnitsParty(UnitInfo_Unk_086825C4)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_086826A4)
    EvtMoveWait
    EvtCameraUnit(PID_ROY)
    EvtSleep(16)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_96F)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08673998
EventScr CONST_DATA EventScr_Unk_08673998[] =
{
    EvtSetBgm(SONG_03)
    EvtLoadUnits(UnitInfo_Unk_086828B4)
    EvtMoveWait
    EvtTalk(MSG_970)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086739C0
EventScr CONST_DATA EventScr_Unk_086739C0[] =
{
    EvtCamera(18, 21)
    EvtFlashCursor(18, 21)
    EvtOverrideBgm(SONG_12)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0E1)
    EvtClearTalk
    EvtLoadUnits(UnitInfo_Unk_086829F4)
    EvtMoveWait
    EvtRestoreBgm

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08673A24
EventScr CONST_DATA EventScr_Unk_08673A24[] =
{
    EvtGotoIfFlag(1, FLAG_2)

    EvtOverrideBgm(SONG_03)
    EvtCamera(2, 25)
    EvtFlashCursor(2, 25)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_971)
    EvtClearTalk
    EvtRestoreBgm

EvtLabel(1)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08673A88
EventScr CONST_DATA EventScr_Unk_08673A88[] =
{
    EvtGotoIfFlag(2, FLAG_2)

    EvtLoadUnits(UnitInfo_Unk_08682A44)
    EvtMoveWait

EvtLabel(2)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08673AB0
EventScr CONST_DATA EventScr_Unk_08673AB0[] =
{
    EvtGotoIfFlag(2, FLAG_2)

    EvtLoadUnits(UnitInfo_Unk_08682A74)
    EvtMoveWait

EvtLabel(2)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08673AD8
EventScr CONST_DATA EventScr_Unk_08673AD8[] =
{
    EvtGotoIfFlag(2, FLAG_2)

    EvtLoadUnits(UnitInfo_Unk_08682AA4)
    EvtMoveWait

EvtLabel(2)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08673B00
EventScr CONST_DATA EventScr_Unk_08673B00[] =
{
    EvtSetAi(PID_UNKNOWN_D4, AI_A_00, AI_B_00, 0)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08673B14
EventScr CONST_DATA EventScr_Unk_08673B14[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_0E2)
    EvtClearTalk
    EvtChangeFaction(PID_BARTRE, FACTION_BLUE)
    EvtClearFlag(FLAG_CHAPTER11B_12)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08673B48
EventScr CONST_DATA EventScr_Unk_08673B48[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_973)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08673B84
EventScr CONST_DATA EventScr_Unk_08673B84[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_0E5)
    EvtClearTalk
    EvtChangeFaction(PID_GEESE, FACTION_BLUE)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08673BB0
EventScr CONST_DATA EventScr_Unk_08673BB0[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_975)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_REDGEM)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08673BF8
EventScr CONST_DATA EventScr_Unk_08673BF8[] =
{
    EvtGotoIfNotFlag(3, FLAG_118)

    EvtSetBgm(SONG_14)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_978)
    EvtClearTalk

EvtLabel(3)
    EvtSetBgm(SONG_27)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_979)
    EvtClearTalk
    EvtGotoIfFlag(7, FLAG_CHAPTER11B_14)

    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_97B)
    EvtClearTalk
    EvtNoSkip
    EvtGiveItemTo(IID_ENERGYRING, PID_ROY)

EvtLabel(7)
    EvtSleep(64)
    EvtNextChapter(CHAPTER_12)
    EvtSleep(1)
    EvtKill
    EvtClearSkip
    EvtEnd
};
