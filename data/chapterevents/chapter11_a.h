#pragma once

// EventScr @ 0866E314
EventScr CONST_DATA EventScr_Unk_0866E314[] =
{
    EvtSetFlag(FLAG_CHAPTER11A_13)
    EvtRemoveUnit(PID_UNKNOWN_56)
    EvtSleep(16)
    EvtFlashCursor(27, 2)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0EB)
    EvtClearTalk
    EvtLoadUnits(UnitInfo_Unk_0867D2EC)
    EvtMoveWait
    EvtMoveUnit(PID_MELADY, 30, 5)
    EvtMoveWait
    EvtRemoveUnit(PID_MELADY)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0EC)
    EvtClearTalk
    EvtLoadUnits(UnitInfo_Unk_0867D00C)
    EvtMoveWait
    EvtLoadUnitsParty(UnitInfo_Unk_0867CDAC)
    EvtMoveWait
    EvtSetBgm(SONG_24)
    EvtCameraUnit(PID_ROY)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0ED)
    EvtClearTalk
    EvtLoadUnits(UnitInfo_Unk_0867CE7C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866E418
EventScr CONST_DATA EventScr_Unk_0866E418[] =
{
    EvtOverrideBgm(SONG_05)
    EvtCamera(28, 12)
    EvtLoadUnits(UnitInfo_Unk_0867D30C)
    EvtMoveWait
    EvtUnitCameraOff
    EvtLoadUnits(UnitInfo_Unk_0867D32C)
    EvtMoveWait
    EvtTalk(MSG_0EE)
    EvtClearTalk
    EvtMoveUnit(PID_GALLE, 30, 18)
    EvtMoveUnit(PID_MELADY, 30, 17)
    EvtMoveWait
    EvtRemoveUnit(PID_GALLE)
    EvtRemoveUnit(PID_MELADY)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866E488
EventScr CONST_DATA EventScr_Unk_0866E488[] =
{
    EvtOverrideBgm(SONG_23)
    EvtCamera(18, 10)
    EvtLoadUnits(UnitInfo_Unk_0867D13C)
    EvtMoveWait
    EvtTalk(MSG_0EF)
    EvtClearTalk
    EvtLoadUnits(UnitInfo_Unk_0867D11C)
    EvtMoveWait
    EvtTalk(MSG_0F0)
    EvtClearTalk
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866E4D4
EventScr CONST_DATA EventScr_Unk_0866E4D4[] =
{
    EvtGotoIfNotFlag(1, FLAG_CHAPTER11A_2)

    EvtClearFlag(FLAG_CHAPTER11A_4)
    EvtGoto(9)

EvtLabel(1)
    EvtCamera(27, 2)
    EvtSetBgm(SONG_03)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0F1)
    EvtClearTalk

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866E544
EventScr CONST_DATA EventScr_Unk_0866E544[] =
{
    EvtGotoIfNotFlag(1, FLAG_CHAPTER11A_2)

    EvtClearFlag(FLAG_CHAPTER11A_5)
    EvtGoto(9)

EvtLabel(1)
    EvtLoadUnits(UnitInfo_Unk_0867D0BC)
    EvtMoveWait
    EvtCamera(18, 10)
    EvtSetBgm(SONG_03)
    EvtTalk(MSG_0F2)
    EvtClearTalk

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866E5A0
EventScr CONST_DATA EventScr_Unk_0866E5A0[] =
{
    EvtGotoIfNotFlag(9, FLAG_CHAPTER11A_5)

    EvtOverrideBgm(SONG_23)
    EvtCameraUnit(PID_ROY)
    EvtTalk(MSG_0F3)
    EvtClearTalk
    EvtRestoreBgm

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866E5DC
EventScr CONST_DATA EventScr_Unk_0866E5DC[] =
{
    EvtSetBgm(SONG_03)
    EvtLoadUnits(UnitInfo_Unk_0867D20C)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0867D24C)
    EvtMoveWait
    EvtSleep(16)
    EvtUnitCameraOff
    EvtLoadUnits(UnitInfo_Unk_0867D34C)
    EvtMoveWait
    EvtTalk(MSG_94E)
    EvtClearTalk
    EvtMoveUnit(PID_THEA, 18, 26)
    EvtMoveWait
    EvtRemoveUnit(PID_THEA)
    EvtTalk(MSG_94F)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866E64C
EventScr CONST_DATA EventScr_Unk_0866E64C[] =
{
    EvtOverrideBgm(SONG_04)
    EvtLoadUnits(UnitInfo_Unk_0867D27C)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0867D2BC)
    EvtMoveWait
    EvtTalk(MSG_950)
    EvtClearTalk
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866E684
EventScr CONST_DATA EventScr_Unk_0866E684[] =
{
    EvtGotoIfFlag(9, FLAG_CHAPTER11A_2)

    EvtCamera(27, 2)
    EvtFlashCursor(27, 2)
    EvtSetBgm(SONG_03)
    EvtSleep(16)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0F4)
    EvtClearTalk

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866E6EC
EventScr CONST_DATA EventScr_Unk_0866E6EC[] =
{
    EvtGotoIfFlag(9, FLAG_CHAPTER11A_2)

    EvtLoadUnits(UnitInfo_Unk_0867D02C)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0867D07C)
    EvtMoveWait

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866E720
EventScr CONST_DATA EventScr_Unk_0866E720[] =
{
    EvtGotoIfFlag(9, FLAG_CHAPTER11A_2)

    EvtSetBgm(SONG_03)
    EvtCamera(27, 2)
    EvtFlashCursor(27, 2)
    EvtSleep(16)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0F5)
    EvtClearTalk

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866E788
EventScr CONST_DATA EventScr_Unk_0866E788[] =
{
    EvtGotoIfFlag(9, FLAG_CHAPTER11A_2)

    EvtLoadUnits(UnitInfo_Unk_0867D17C)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0867D1CC)
    EvtMoveWait

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866E7BC
EventScr CONST_DATA EventScr_Unk_0866E7BC[] =
{
    EvtOverrideBgm(SONG_33)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0F6)
    EvtClearTalk
    EvtChangeFaction(PID_ECHIDNA, FACTION_BLUE)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866E808
EventScr CONST_DATA EventScr_Unk_0866E808[] =
{
    EvtLowerBgmVolume
    EvtTalk(MSG_954)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866E824
EventScr CONST_DATA EventScr_Unk_0866E824[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_957)
    EvtClearTalk
    EvtChangeFaction(PID_KLEIN, FACTION_BLUE)
    EvtChangeFaction(PID_UNKNOWN_D8, FACTION_GREEN)
    EvtSetAi(PID_UNKNOWN_D8, AI_A_06, AI_B_0C, 0)
    EvtClearFlag(FLAG_CHAPTER11A_13)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866E870
EventScr CONST_DATA EventScr_Unk_0866E870[] =
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

// EventScr @ 0866E8B4
EventScr CONST_DATA EventScr_Unk_0866E8B4[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_955)
    EvtClearTalk
    EvtChangeFaction(PID_THEA, FACTION_BLUE)
    EvtSetFlag(FLAG_CHAPTER11A_12)
    EvtChangeFaction(PID_UNKNOWN_D9, FACTION_GREEN)
    EvtSetAi(PID_UNKNOWN_D9, AI_A_06, AI_B_0C, 0)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866E900
EventScr CONST_DATA EventScr_Unk_0866E900[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_959)
    EvtClearTalk
    EvtChangeFaction(PID_THEA, FACTION_BLUE)
    EvtSetFlag(FLAG_CHAPTER11A_12)
    EvtChangeFaction(PID_UNKNOWN_D9, FACTION_GREEN)
    EvtSetAi(PID_UNKNOWN_D9, AI_A_06, AI_B_0C, 0)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866E94C
EventScr CONST_DATA EventScr_Unk_0866E94C[] =
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

// EventScr @ 0866E984
EventScr CONST_DATA EventScr_Unk_0866E984[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0F8)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_DRACOSHIELD)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866E9CC
EventScr CONST_DATA EventScr_Unk_0866E9CC[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0F9)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_SLEEPSTAFF)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866EA14
EventScr CONST_DATA EventScr_Unk_0866EA14[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0FA)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveMoney(5000)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866EA5C
EventScr CONST_DATA EventScr_Unk_0866EA5C[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0FB)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_RESTORESTAFF)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866EAA4
EventScr CONST_DATA EventScr_Unk_0866EAA4[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0FC)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_SPEEDWING)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866EAEC
EventScr CONST_DATA EventScr_Unk_0866EAEC[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0FD)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_SERAPHROBE)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866EB34
EventScr CONST_DATA EventScr_Unk_0866EB34[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0FE)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_ORIONSBOLT)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866EB7C
EventScr CONST_DATA EventScr_Unk_0866EB7C[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0FF)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_AXEREAVER)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866EBC4
EventScr CONST_DATA EventScr_Unk_0866EBC4[] =
{
    EvtSetBgm(SONG_27)
    EvtFadeToBlack(4)
    EvtExitMap
    EvtSetMap(CHAPTER_11_A, 27, 2)
    EvtLoadUnits(UnitInfo_Unk_0867D36C)
    EvtMoveWait
    EvtMoveUnit(PID_ELFFIN, 27, 2)
    EvtFadeFromBlack(4)
    EvtEnterMap
    EvtMoveWait
    EvtRemoveUnit(PID_ELFFIN)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_102)
    EvtSetBgm(SONG_28)
    EvtTalkContinue
    EvtClearTalk
    EvtGotoIfNotFlag(3, FLAG_CHAPTER11A_14)

    EvtGotoIfNotFlag(3, FLAG_CHAPTER11A_15)

    EvtGotoIfNotFlag(3, FLAG_CHAPTER11A_16)

    EvtGotoIfNotFlag(3, FLAG_CHAPTER11A_17)

    EvtGotoIfNotFlag(3, FLAG_CHAPTER11A_18)

    EvtGotoIfNotFlag(3, FLAG_CHAPTER11A_19)

    EvtGotoIfNotFlag(3, FLAG_CHAPTER11A_20)

    EvtGotoIfNotFlag(3, FLAG_CHAPTER11A_21)

    EvtSetBgm(SONG_27)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_103)
    EvtClearTalk
    EvtNoSkip
    EvtGiveItemTo(IID_HEROCREST, PID_ROY)

EvtLabel(3)
    EvtGotoIfNotFunc(5, IsKleinInBlueTeam)

    EvtGotoIfFlag(5, FLAG_CHAPTER11A_22)

    EvtSetBgm(SONG_27)
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

    EvtGotoIfFlag(7, FLAG_CHAPTER11A_23)

    EvtSetBgm(SONG_27)
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
    EvtNextChapter(CHAPTER_12)
    EvtSleep(1)
    EvtKill
    EvtClearSkip
    EvtEnd
};
