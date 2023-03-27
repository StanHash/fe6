#pragma once

// EventScr @ 08670108
EventScr CONST_DATA EventScr_Unk_08670108[] =
{
    EvtCameraUnit(PID_UNKNOWN_5D)
    EvtFlashCursorUnit(PID_UNKNOWN_5D)
    EvtUnitCameraOff
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_144)
    EvtClearTalk
    EvtSetFlag(FLAG_CHAPTER15_5)
    EvtGotoIfFlag(1, FLAG_113)

    EvtGotoIfFlag(1, FLAG_111)

    EvtClearFlag(FLAG_CHAPTER15_5)
    EvtLoadUnits(UnitInfo_Unk_0867E9F0)
    EvtMoveWait
    EvtCameraUnit(PID_PERCEVAL)
    EvtSleep(16)
    EvtMoveUnit(PID_DOUGLAS, 1, 0)
    EvtMoveWait
    EvtTalk(MSG_146)
    EvtClearTalk
    EvtMoveUnit(PID_DOUGLAS, 0, 0)
    EvtMoveWait
    EvtRemoveUnit(PID_DOUGLAS)
    EvtMoveUnit(PID_PERCEVAL, 2, 3)
    EvtMoveWait

EvtLabel(1)
    EvtSetBgm(SONG_25)
    EvtLoadUnitsParty(UnitInfo_Unk_0867E710)
    EvtMoveWait
    EvtCameraUnit(PID_ROY)
    EvtFlashCursorUnit(PID_ROY)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_145)
    EvtClearTalk
    EvtLoadUnits(UnitInfo_Unk_0867E7E0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867023C
EventScr CONST_DATA EventScr_Unk_0867023C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867EAB0)
    EvtMoveWait
    EvtCameraUnit(PID_GARRET)
    EvtSetBgm(SONG_02)
    EvtTalk(MSG_147)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867026C
EventScr CONST_DATA EventScr_Unk_0867026C[] =
{
    EvtGotoIfFlag(9, FLAG_2)

    EvtCameraUnit(PID_UNKNOWN_5D)
    EvtFlashCursorUnit(PID_UNKNOWN_5D)
    EvtSetBgm(SONG_02)
    EvtSleep(16)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_148)
    EvtClearTalk

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086702D4
EventScr CONST_DATA EventScr_Unk_086702D4[] =
{
    EvtGotoIfFlag(9, FLAG_2)

    EvtLoadUnits(UnitInfo_Unk_0867EA60)
    EvtMoveWait

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086702FC
EventScr CONST_DATA EventScr_Unk_086702FC[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_149)
    EvtClearTalk
    EvtChangeFaction(PID_PERCEVAL, FACTION_BLUE)
    EvtSetFlag(FLAG_113)
    EvtChangeFaction(PID_UNKNOWN_D3, FACTION_GREEN)
    EvtSetAi(PID_UNKNOWN_D3, AI_A_06, AI_B_0C, 0)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08670348
EventScr CONST_DATA EventScr_Unk_08670348[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_14A)
    EvtClearTalk
    EvtChangeFaction(PID_PERCEVAL, FACTION_BLUE)
    EvtSetFlag(FLAG_113)
    EvtChangeFaction(PID_UNKNOWN_D3, FACTION_GREEN)
    EvtSetAi(PID_UNKNOWN_D3, AI_A_06, AI_B_0C, 0)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08670394
EventScr CONST_DATA EventScr_Unk_08670394[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_14B)
    EvtClearTalk
    EvtChangeFaction(PID_GARRET, FACTION_BLUE)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086703C0
EventScr CONST_DATA EventScr_Unk_086703C0[] =
{
    EvtLowerBgmVolume
    EvtTalk(MSG_14C)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086703DC
EventScr CONST_DATA EventScr_Unk_086703DC[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_14D)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_DIVINE)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08670424
EventScr CONST_DATA EventScr_Unk_08670424[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_14E)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_HAMMERNESTAFF)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867046C
EventScr CONST_DATA EventScr_Unk_0867046C[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_14F)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086704A8
EventScr CONST_DATA EventScr_Unk_086704A8[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_150)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086704E4
EventScr CONST_DATA EventScr_Unk_086704E4[] =
{
    EvtSetBgm(SONG_27)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_153)
    EvtGotoIfSkipped(22)

    EvtSetBgm(SONG_26)

EvtLabel(22)
    EvtTalkContinue
    EvtClearTalk
    EvtGotoIfNotFunc(5, func_fe6_0806C158)

    EvtGotoIfFlag(5, FLAG_CHAPTER15_11)

    EvtGotoIfFlag(5, FLAG_119)

    EvtSetBgm(SONG_27)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_134)
    EvtClearTalk
    EvtNoSkip
    EvtGiveItemTo(IID_KNIGHTCREST, PID_PERCEVAL)

EvtLabel(5)
    EvtUnitCameraOff
    EvtLoadUnits(UnitInfo_Unk_0867EAF0)
    EvtMoveWait
    EvtSleep(64)
    EvtNextChapter(CHAPTER_16)
    EvtSleep(1)
    EvtKill
    EvtClearSkip
    EvtEnd
};
