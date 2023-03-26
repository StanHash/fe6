#pragma once

// EventScr @ 08672E40
EventScr CONST_DATA EventScr_Unk_08672E40[] =
{
    EvtSetFlag(FLAG_CHAPTER10B_11)
    EvtCamera(20, 2)
    EvtFlashCursor(20, 2)
    EvtUnitCameraOff
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_948)
    EvtClearTalk
    EvtSetBgm(SONG_24)
    EvtLoadUnitsParty(UnitInfo_Unk_08681F5C)
    EvtMoveWait
    EvtCameraUnit(PID_ROY)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_949)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08672ED8
EventScr CONST_DATA EventScr_Unk_08672ED8[] =
{
    EvtOverrideBgm(SONG_05)
    EvtCamera(20, 2)
    EvtUnitCameraOff
    EvtLoadUnits(UnitInfo_Unk_0868241C)
    EvtMoveWait
    EvtUnitCameraOn
    EvtLoadUnits(UnitInfo_Unk_086823FC)
    EvtMoveWait
    EvtSleep(16)
    EvtTalk(MSG_94A)
    EvtClearTalk
    EvtMoveUnit(PID_GALLE, 7, 1)
    EvtMoveWait
    EvtMoveUnit(PID_GALLE, 13, -1)
    EvtMoveUnit(PID_MELADY, 12, -1)
    EvtMoveWait
    EvtRemoveUnit(PID_GALLE)
    EvtRemoveUnit(PID_MELADY)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08672F64
EventScr CONST_DATA EventScr_Unk_08672F64[] =
{
    EvtOverrideBgm(SONG_14)
    EvtCamera(8, 8)
    EvtFlashCursor(8, 8)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_94B)
    EvtClearTalk
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08672FB4
EventScr CONST_DATA EventScr_Unk_08672FB4[] =
{
    EvtCamera(20, 2)
    EvtFlashCursor(20, 2)
    EvtSetBgm(SONG_03)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_94C)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08673000
EventScr CONST_DATA EventScr_Unk_08673000[] =
{
    EvtLoadUnits(UnitInfo_Unk_0868220C)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_086821DC)
    EvtMoveWait
    EvtCameraUnit(PID_UNKNOWN_B6)
    EvtSetBgm(SONG_03)
    EvtTalk(MSG_94D)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867303C
EventScr CONST_DATA EventScr_Unk_0867303C[] =
{
    EvtOverrideBgm(SONG_02)
    EvtLoadUnits(UnitInfo_Unk_086822AC)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_086822EC)
    EvtMoveWait
    EvtSleep(16)
    EvtLoadUnits(UnitInfo_Unk_0868243C)
    EvtMoveWait
    EvtTalk(MSG_94E)
    EvtClearTalk
    EvtMoveUnit(PID_THEA, 17, 32)
    EvtMoveWait
    EvtRemoveUnit(PID_THEA)
    EvtSleep(16)
    EvtTalk(MSG_94F)
    EvtClearTalk
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086730B4
EventScr CONST_DATA EventScr_Unk_086730B4[] =
{
    EvtOverrideBgm(SONG_04)
    EvtLoadUnits(UnitInfo_Unk_0868231C)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0868235C)
    EvtMoveWait
    EvtSleep(16)
    EvtTalk(MSG_950)
    EvtClearTalk
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086730F4
EventScr CONST_DATA EventScr_Unk_086730F4[] =
{
    EvtGotoIfFlag(9, FLAG_CHAPTER10B_2)

    EvtCamera(20, 2)
    EvtFlashCursor(20, 2)
    EvtSetBgm(SONG_03)
    EvtSleep(16)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_951)
    EvtClearTalk

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867315C
EventScr CONST_DATA EventScr_Unk_0867315C[] =
{
    EvtGotoIfFlag(9, FLAG_CHAPTER10B_2)

    EvtLoadUnits(UnitInfo_Unk_0868238C)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_086823CC)
    EvtMoveWait

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08673190
EventScr CONST_DATA EventScr_Unk_08673190[] =
{
    EvtGotoIfFlag(9, FLAG_CHAPTER10B_2)

    EvtCamera(20, 2)
    EvtFlashCursor(20, 2)
    EvtSetBgm(SONG_03)
    EvtSleep(16)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_952)
    EvtClearTalk

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086731F8
EventScr CONST_DATA EventScr_Unk_086731F8[] =
{
    EvtGotoIfFlag(9, FLAG_CHAPTER10B_2)

    EvtLoadUnits(UnitInfo_Unk_0868223C)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0868227C)
    EvtMoveWait

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867322C
EventScr CONST_DATA EventScr_Unk_0867322C[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_953)
    EvtClearTalk
    EvtChangeFaction(PID_GONZALEZ, FACTION_BLUE)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08673258
EventScr CONST_DATA EventScr_Unk_08673258[] =
{
    EvtLowerBgmVolume
    EvtTalk(MSG_954)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08673274
EventScr CONST_DATA EventScr_Unk_08673274[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_957)
    EvtClearTalk
    EvtChangeFaction(PID_KLEIN, FACTION_BLUE)
    EvtChangeFaction(PID_UNKNOWN_D8, FACTION_GREEN)
    EvtSetAi(PID_UNKNOWN_D8, AI_A_06, AI_B_0C, 0)
    EvtClearFlag(FLAG_CHAPTER10B_11)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086732C0
EventScr CONST_DATA EventScr_Unk_086732C0[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_958)
    EvtClearTalk
    EvtChangeFaction(PID_KLEIN, FACTION_BLUE)
    EvtChangeFaction(PID_UNKNOWN_D8, FACTION_GREEN)
    EvtSetAi(PID_UNKNOWN_D8, AI_A_06, AI_B_0C, 0)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08673304
EventScr CONST_DATA EventScr_Unk_08673304[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_955)
    EvtClearTalk
    EvtChangeFaction(PID_THEA, FACTION_BLUE)
    EvtSetFlag(FLAG_CHAPTER10B_10)
    EvtChangeFaction(PID_UNKNOWN_D9, FACTION_GREEN)
    EvtSetAi(PID_UNKNOWN_D9, AI_A_06, AI_B_0C, 0)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08673350
EventScr CONST_DATA EventScr_Unk_08673350[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_959)
    EvtClearTalk
    EvtChangeFaction(PID_THEA, FACTION_BLUE)
    EvtSetFlag(FLAG_CHAPTER10B_10)
    EvtChangeFaction(PID_UNKNOWN_D9, FACTION_GREEN)
    EvtSetAi(PID_UNKNOWN_D9, AI_A_06, AI_B_0C, 0)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867339C
EventScr CONST_DATA EventScr_Unk_0867339C[] =
{
    EvtOverrideBgm(SONG_12)
    EvtTalk(MSG_956)
    EvtClearTalk
    EvtChangeFaction(PID_THEA, FACTION_GREEN)
    EvtChangeFaction(PID_UNKNOWN_D9, FACTION_GREEN)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086733D4
EventScr CONST_DATA EventScr_Unk_086733D4[] =
{
    EvtTalk(MSG_95A)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086733E8
EventScr CONST_DATA EventScr_Unk_086733E8[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_95B)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_SLEEPSTAFF)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08673430
EventScr CONST_DATA EventScr_Unk_08673430[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_95C)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_ORIONSBOLT)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08673478
EventScr CONST_DATA EventScr_Unk_08673478[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_95D)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_BARRIERSTAFF)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086734C0
EventScr CONST_DATA EventScr_Unk_086734C0[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtGotoIfActive(5, PID_WARD)

    EvtGotoIfActive(7, PID_LOT)

    EvtTalk(MSG_960)
    EvtClearTalk
    EvtNoSkip
    EvtGiveItem(IID_DOORKEY)
    EvtGoto(9)

EvtLabel(5)
    EvtTalk(MSG_95E)
    EvtGoto(8)

EvtLabel(7)
    EvtTalk(MSG_95F)

EvtLabel(8)
    EvtClearTalk
    EvtNoSkip
    EvtGiveItem(IID_SWORDREAVER)

EvtLabel(9)
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08673570
EventScr CONST_DATA EventScr_Unk_08673570[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtGotoIfActive(5, PID_WARD)

    EvtGotoIfActive(7, PID_LOT)

    EvtTalk(MSG_963)
    EvtClearTalk
    EvtNoSkip
    EvtGiveItem(IID_ELIXIR)
    EvtGoto(9)

EvtLabel(5)
    EvtTalk(MSG_961)
    EvtGoto(8)

EvtLabel(7)
    EvtTalk(MSG_962)

EvtLabel(8)
    EvtClearTalk
    EvtNoSkip
    EvtGiveItem(IID_SPEEDWING)

EvtLabel(9)
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08673620
EventScr CONST_DATA EventScr_Unk_08673620[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_964)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_DRACOSHIELD)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08673668
EventScr CONST_DATA EventScr_Unk_08673668[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_965)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_SWORDREAVER)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086736B0
EventScr CONST_DATA EventScr_Unk_086736B0[] =
{
    EvtSetBgm(SONG_27)
    EvtFadeToBlack(4)
    EvtExitMap
    EvtSetMap(CHAPTER_10_B, 20, 2)
    EvtLoadUnits(UnitInfo_Unk_0868245C)
    EvtMoveWait
    EvtMoveUnit(PID_ELFFIN, 20, 2)
    EvtFadeFromBlack(4)
    EvtEnterMap
    EvtMoveWait
    EvtRemoveUnit(PID_ELFFIN)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_968)
    EvtClearTalk
    EvtNoSkip
    EvtGiveItemTo(IID_WYRMSLAYER, PID_ROY)
    EvtGotoIfNotFlag(3, FLAG_CHAPTER10B_12)

    EvtGotoIfNotFlag(3, FLAG_CHAPTER10B_13)

    EvtGotoIfNotFlag(3, FLAG_CHAPTER10B_14)

    EvtGotoIfNotFlag(3, FLAG_CHAPTER10B_15)

    EvtGotoIfNotFlag(3, FLAG_CHAPTER10B_16)

    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_969)
    EvtClearTalk
    EvtNoSkip
    EvtGiveItemTo(IID_HEROCREST, PID_ROY)

EvtLabel(3)
    EvtGotoIfNotFunc(5, IsKleinInBlueTeam)

    EvtGotoIfFlag(5, FLAG_CHAPTER10B_17)

    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_96A)
    EvtClearTalk
    EvtNoSkip
    EvtGiveItemTo(IID_ORIONSBOLT, PID_KLEIN)

EvtLabel(5)
    EvtGotoIfNotFunc(7, func_fe6_0806C2A4)

    EvtGotoIfFlag(7, FLAG_CHAPTER10B_18)

    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_96B)
    EvtClearTalk
    EvtNoSkip
    EvtGiveItemTo(IID_ELYSIANWHIP, PID_THEA)

EvtLabel(7)
    EvtSleep(64)
    EvtNextChapter(CHAPTER_11_B)
    EvtSleep(1)
    EvtKill
    EvtClearSkip
    EvtEnd
};
