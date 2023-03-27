#pragma once

// EventScr @ 08671690
EventScr CONST_DATA EventScr_Unk_08671690[] =
{
    EvtGotoIfNotFlag(0, FLAG_105)

    EvtSetFlag(FLAG_CHAPTER20I_10)

EvtLabel(0)
    EvtSetFlag(FLAG_CHAPTER20I_7)
    EvtSetFlag(FLAG_CHAPTER20I_8)
    EvtSetFlag(FLAG_CHAPTER20I_9)
    EvtFlashCursorUnit(PID_UNKNOWN_61)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_1A0)
    EvtClearTalk
    EvtCameraUnit(PID_JUNO)
    EvtFlashCursorUnit(PID_JUNO)
    EvtSetBgm(SONG_31)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_2)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_1A1)
    EvtClearTalk
    EvtLoadUnitsParty(UnitInfo_Unk_0867FE94)
    EvtMoveWait
    EvtCameraUnit(PID_ROY)
    EvtFlashCursorUnit(PID_ROY)
    EvtSetBgm(SONG_2B)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_11)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_1A2)
    EvtSetBgm(SONG_0C)
    EvtTalkContinue
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086717A0
EventScr CONST_DATA EventScr_Unk_086717A0[] =
{
    EvtGotoIfFlag(3, FLAG_105)

    EvtGotoIfFlag(3, FLAG_112)

    EvtOverrideBgm(SONG_32)
    EvtLoadUnits(UnitInfo_Unk_08680254)
    EvtMoveWait
    EvtTalk(MSG_1A3)
    EvtClearTalk
    EvtRestoreBgm

EvtLabel(3)
    EvtLoadUnits(UnitInfo_Unk_08680274)
    EvtMoveWait

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08671800
EventScr CONST_DATA EventScr_Unk_08671800[] =
{
    EvtWeather(WEATHER_SNOWSTORM)
    EvtCameraUnit(PID_ROY)
    EvtFlashCursorUnit(PID_ROY)
    EvtLowerBgmVolume
    EvtTalk(MSG_1A4)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08671834
EventScr CONST_DATA EventScr_Unk_08671834[] =
{
    EvtGotoIfFunc(7, IsBluePhase)

    EvtClearFlag(FLAG_CHAPTER20I_5)
    EvtGoto(9)

EvtLabel(7)
    EvtSetAiPosition(20, 11, AI_A_00, AI_B_00, 0)
    EvtSetAiPosition(23, 11, AI_A_00, AI_B_00, 0)
    EvtSetAiPosition(22, 12, AI_A_00, AI_B_00, 0)
    EvtSetAiPosition(22, 14, AI_A_00, AI_B_00, 0)
    EvtSetAiPosition(21, 15, AI_A_00, AI_B_00, 0)
    EvtSetAiPosition(22, 16, AI_A_00, AI_B_00, 0)

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086718B0
EventScr CONST_DATA EventScr_Unk_086718B0[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_1A5)
    EvtClearTalk
    EvtChangeFaction(PID_JUNO, FACTION_BLUE)
    EvtClearFlag(FLAG_CHAPTER20I_8)
    EvtClearFlag(FLAG_CHAPTER20I_9)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086718EC
EventScr CONST_DATA EventScr_Unk_086718EC[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_1A6)
    EvtClearTalk
    EvtChangeFaction(PID_JUNO, FACTION_BLUE)
    EvtClearFlag(FLAG_CHAPTER20I_7)
    EvtClearFlag(FLAG_CHAPTER20I_9)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08671928
EventScr CONST_DATA EventScr_Unk_08671928[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_1A7)
    EvtClearTalk
    EvtChangeFaction(PID_JUNO, FACTION_BLUE)
    EvtClearFlag(FLAG_CHAPTER20I_7)
    EvtClearFlag(FLAG_CHAPTER20I_8)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08671964
EventScr CONST_DATA EventScr_Unk_08671964[] =
{
    EvtLowerBgmVolume
    EvtTalk(MSG_1A8)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08671980
EventScr CONST_DATA EventScr_Unk_08671980[] =
{
    EvtLowerBgmVolume
    EvtTalk(MSG_1A9)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867199C
EventScr CONST_DATA EventScr_Unk_0867199C[] =
{
    EvtLowerBgmVolume
    EvtTalk(MSG_1AA)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086719B8
EventScr CONST_DATA EventScr_Unk_086719B8[] =
{
    EvtGotoIfNotFunc(5, IsJunoBlue)

    EvtGotoIfNotFunc(5, IsZelotBlue)

    EvtGotoIfFunc(5, IsPastTurn25)

    EvtSetBgm(SONG_27)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_1AD)
    EvtClearTalk
    EvtGotoIfFlag(2, FLAG_CHAPTER20I_13)

    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_1B2)
    EvtClearTalk
    EvtNoSkip
    EvtGiveItemTo(IID_SERAPHROBE, PID_ROY)

EvtLabel(2)
    EvtSleep(64)
    EvtNextChapter(CHAPTER_20X_I)
    EvtSleep(1)
    EvtKill
    EvtGoto(9)

EvtLabel(5)
    EvtSetBgm(SONG_2B)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_1AE)
    EvtSetBgm(SONG_3C)
    EvtTalkContinue
    EvtClearTalk
    EvtGotoIfFlag(7, FLAG_CHAPTER20I_13)

    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_1B2)
    EvtClearTalk
    EvtNoSkip
    EvtGiveItemTo(IID_SERAPHROBE, PID_ROY)

EvtLabel(7)
    EvtSleep(64)
    EvtNextChapter(CHAPTER_21)
    EvtSleep(1)
    EvtKill

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};
