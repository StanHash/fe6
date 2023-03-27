#pragma once

u32 CONST_DATA gUnk_08675B90[] =
{
    FLAG_CHAPTER21X_8,
    FLAG_CHAPTER21X_9,
    FLAG_CHAPTER21X_10,
    FLAG_CHAPTER21X_11,
    FLAG_CHAPTER21X_12,
    FLAG_CHAPTER21X_13,
};

// EventScr @ 08675B90
EventScr CONST_DATA EventScr_Unk_08675BA8[] =
{
    EvtFunc(func_fe6_0806D6D8)
    EvtFunc(func_fe6_0806D77C)
    EvtCamera(15, 1)
    EvtFlashCursor(15, 1)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_13)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_C00)
    EvtClearTalk
    EvtSetBgm(SONG_0F)
    EvtLoadUnitsParty(UnitInfo_Unk_08685BC0)
    EvtMoveWait
    EvtCameraUnit(PID_ROY)
    EvtFlashCursorUnit(PID_ROY)
    EvtGotoIfFunc(5, IsMeladyBlueDeployed)

    EvtGotoIfFunc(7, IsZeissBlueDeployed)

    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_13)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_C03)
    EvtClearTalk
    EvtGoto(9)

EvtLabel(5)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_13)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_C01)
    EvtClearTalk
    EvtGoto(9)

EvtLabel(7)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_13)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_C02)
    EvtClearTalk
    EvtGoto(9)

EvtLabel(9)
    EvtCameraUnit(PID_ROY)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08675CF4
EventScr CONST_DATA EventScr_Unk_08675CF4[] =
{
    EvtGotoIfFlag(3, FLAG_CHAPTER21X_8)

    EvtNoSkip
    EvtGiveItem(IID_ELIXIR)
    EvtGoto(9)

EvtLabel(3)
    EvtLoadUnits(UnitInfo_Unk_08685F50)
    EvtMoveWait

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08675D38
EventScr CONST_DATA EventScr_Unk_08675D38[] =
{
    EvtGotoIfFlag(3, FLAG_CHAPTER21X_9)

    EvtNoSkip
    EvtGiveItem(IID_ELIXIR)
    EvtGoto(9)

EvtLabel(3)
    EvtLoadUnits(UnitInfo_Unk_08685F70)
    EvtMoveWait

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08675D7C
EventScr CONST_DATA EventScr_Unk_08675D7C[] =
{
    EvtGotoIfFlag(3, FLAG_CHAPTER21X_10)

    EvtNoSkip
    EvtGiveItem(IID_ELIXIR)
    EvtGoto(9)

EvtLabel(3)
    EvtLoadUnits(UnitInfo_Unk_08685F90)
    EvtMoveWait

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08675DC0
EventScr CONST_DATA EventScr_Unk_08675DC0[] =
{
    EvtGotoIfFlag(3, FLAG_CHAPTER21X_11)

    EvtNoSkip
    EvtGiveItem(IID_ELIXIR)
    EvtGoto(9)

EvtLabel(3)
    EvtLoadUnits(UnitInfo_Unk_08685FB0)
    EvtMoveWait

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08675E04
EventScr CONST_DATA EventScr_Unk_08675E04[] =
{
    EvtGotoIfFlag(3, FLAG_CHAPTER21X_12)

    EvtNoSkip
    EvtGiveItem(IID_ELIXIR)
    EvtGoto(9)

EvtLabel(3)
    EvtLoadUnits(UnitInfo_Unk_08685FD0)
    EvtMoveWait

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08675E48
EventScr CONST_DATA EventScr_Unk_08675E48[] =
{
    EvtGotoIfFlag(3, FLAG_CHAPTER21X_13)

    EvtNoSkip
    EvtGiveItem(IID_ELIXIR)
    EvtGoto(9)

EvtLabel(3)
    EvtLoadUnits(UnitInfo_Unk_08685FF0)
    EvtMoveWait

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08675E8C
EventScr CONST_DATA EventScr_Unk_08675E8C[] =
{
    EvtNoSkipNoTextSkip
    EvtSetBgm(SONG_27)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_13)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_C06)
    EvtClearTalk
    EvtNoSkip
    EvtGiveItemTo(IID_APOCALYPSE, PID_ROY)
    EvtSleep(64)
    EvtFadeBgmOut(4)
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
    EvtClearSkip
    EvtEnd
};
