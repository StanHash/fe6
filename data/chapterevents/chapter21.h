#pragma once

// EventScr @ 08671B48
EventScr CONST_DATA EventScr_Unk_08671B48[] =
{
    EvtGotoIfNotFunc(1, EvtCheck_IsHard)

    EvtLoadUnits(UnitInfo_Unk_08680694)
    EvtMoveWait

EvtLabel(1)
    EvtCameraUnit(PID_MURDOCK)
    EvtFlashCursorUnit(PID_MURDOCK)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_3)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_1B3)
    EvtClearTalk
    EvtSetBgm(SONG_24)
    EvtLoadUnitsParty(UnitInfo_Unk_08680324)
    EvtMoveWait
    EvtCameraUnit(PID_ROY)
    EvtFlashCursorUnit(PID_ROY)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_1B4)
    EvtSetBgm(SONG_3E)
    EvtTalkContinue
    EvtClearTalk
    EvtGotoIfNotFlag(5, FLAG_107)

EvtLabel(3)
    EvtLoadUnits(UnitInfo_Unk_08680764)
    EvtMoveWait
    EvtGoto(9)

EvtLabel(5)
    EvtLoadUnits(UnitInfo_Unk_08680744)
    EvtMoveWait

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08671C4C
EventScr CONST_DATA EventScr_Unk_08671C4C[] =
{
    EvtLoadUnits(UnitInfo_Unk_08680784)
    EvtMoveWait
    EvtGotoIfNotFunc(9, func_fe6_0806C39C)

    EvtOverrideBgm(SONG_05)
    EvtLoadUnits(UnitInfo_Unk_086807A4)
    EvtMoveWait
    EvtCameraUnit(PID_GALLE)
    EvtFlashCursorUnit(PID_GALLE)
    EvtTalk(MSG_1B5)
    EvtClearTalk
    EvtRestoreBgm

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08671CA8
EventScr CONST_DATA EventScr_Unk_08671CA8[] =
{
    EvtGotoIfFlag(2, FLAG_CHAPTER21_5)

    EvtSetFlag(FLAG_CHAPTER21_5)
    EvtGoto(7)

EvtLabel(2)
    EvtGotoIfFlag(3, FLAG_CHAPTER21_6)

    EvtSetFlag(FLAG_CHAPTER21_6)
    EvtGoto(7)

EvtLabel(3)
    EvtGotoIfFlag(9, FLAG_CHAPTER21_7)

    EvtSetFlag(FLAG_CHAPTER21_7)

EvtLabel(7)
    EvtLoadUnits(UnitInfo_Unk_086807F4)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_08680844)
    EvtMoveWait

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08671D34
EventScr CONST_DATA EventScr_Unk_08671D34[] =
{
    EvtGotoIfFlag(2, FLAG_CHAPTER21_8)

    EvtSetFlag(FLAG_CHAPTER21_8)
    EvtGoto(7)

EvtLabel(2)
    EvtGotoIfFlag(3, FLAG_CHAPTER21_9)

    EvtSetFlag(FLAG_CHAPTER21_9)
    EvtGoto(7)

EvtLabel(3)
    EvtGotoIfFlag(9, FLAG_CHAPTER21_10)

    EvtSetFlag(FLAG_CHAPTER21_10)

EvtLabel(7)
    EvtLoadUnits(UnitInfo_Unk_086808E4)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_08680934)
    EvtMoveWait

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08671DC0
EventScr CONST_DATA EventScr_Unk_08671DC0[] =
{
    EvtLoadUnits(UnitInfo_Unk_08680894)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08671DD4
EventScr CONST_DATA EventScr_Unk_08671DD4[] =
{
    EvtGotoIfFlag(2, FLAG_CHAPTER21_12)

    EvtSetFlag(FLAG_CHAPTER21_12)
    EvtGoto(7)

EvtLabel(2)
    EvtGotoIfFlag(3, FLAG_CHAPTER21_13)

    EvtSetFlag(FLAG_CHAPTER21_13)
    EvtGoto(7)

EvtLabel(3)
    EvtGotoIfFlag(9, FLAG_CHAPTER21_14)

    EvtSetFlag(FLAG_CHAPTER21_14)

EvtLabel(7)
    EvtLoadUnits(UnitInfo_Unk_086809D4)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_08680A24)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_08680A74)
    EvtMoveWait

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08671E6C
EventScr CONST_DATA EventScr_Unk_08671E6C[] =
{
    EvtLoadUnits(UnitInfo_Unk_08680AC4)
    EvtMoveWait
    EvtGotoIfNotFunc(9, func_fe6_0806C3AC)

    EvtTalk(MSG_1B6)
    EvtClearTalk

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08671EA0
EventScr CONST_DATA EventScr_Unk_08671EA0[] =
{
    EvtOverrideBgm(SONG_25)
    EvtTalk(MSG_1B7)
    EvtClearTalk
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08671EC0
EventScr CONST_DATA EventScr_Unk_08671EC0[] =
{
    EvtOverrideBgm(SONG_25)
    EvtTalk(MSG_1B8)
    EvtClearTalk
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08671EE0
EventScr CONST_DATA EventScr_Unk_08671EE0[] =
{
    EvtTalk(MSG_1B9)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08671EF4
EventScr CONST_DATA EventScr_Unk_08671EF4[] =
{
    EvtTalk(MSG_1BA)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08671F08
EventScr CONST_DATA EventScr_Unk_08671F08[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_1BC)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_KNIGHTCREST)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08671F50
EventScr CONST_DATA EventScr_Unk_08671F50[] =
{
    EvtNoSkipNoTextSkip
    EvtFadeBgmOut(4)
    EvtGotoIfNotFunc(3, func_fe6_0806C204)

    EvtGotoIfNotFunc(3, func_fe6_0806C214)

    EvtGotoIfFunc(3, func_fe6_0806C4C4)

    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_13)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_1BF)
    EvtClearTalk
    EvtSleep(64)
    EvtNextChapter(CHAPTER_21X)
    EvtSleep(1)
    EvtKill
    EvtGoto(9)

EvtLabel(3)
    EvtSleep(64)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_6)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_1C0)
    EvtFunc(func_fe6_0806DE00)
    EvtFadeFromWhite(16)
    EvtEnterMap
    EvtTalkContinue
    EvtFunc(func_fe6_0806DE20)
    EvtFadeToWhite(4)
    EvtExitMap
    EvtBackground(BACKGROUND_4)
    EvtFadeFromWhite(4)
    EvtEnterMap
    EvtSetBgm(SONG_29)
    EvtTalk(MSG_1C1)
    EvtFunc(func_fe6_0806DE00)
    EvtFadeFromWhite(16)
    EvtEnterMap
    EvtFadeToWhite(4)
    EvtExitMap
    EvtBackground(BACKGROUND_6)
    EvtFadeFromWhite(4)
    EvtEnterMap
    EvtSetBgm(SONG_3C)
    EvtTalk(MSG_1C2)
    EvtClearTalk
    EvtNoSkip
    EvtGiveItemTo(IID_BINDINGBLADE, PID_ROY)
    EvtSleep(64)
    EvtFunc(func_fe6_0806D0E4)
    EvtSleep(1280)
    EvtNextChapter(CHAPTER_22)
    EvtSleep(1)
    EvtKill

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};
