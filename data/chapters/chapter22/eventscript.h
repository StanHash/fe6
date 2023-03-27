#pragma once

// EventScr @ 086720EC
EventScr CONST_DATA EventScr_Unk_086720EC[] =
{
    EvtGotoIfNotFlag(0, FLAG_105)

    EvtSetFlag(FLAG_CHAPTER22_10)

EvtLabel(0)
    EvtGotoIfNotFunc(1, IsHard)

    EvtLoadUnits(UnitInfo_Unk_08680FF0)
    EvtMoveWait

EvtLabel(1)
    EvtCamera(18, 19)
    EvtSleep(16)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_6)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_1C3)
    EvtClearTalk
    EvtCamera(1, 0)
    EvtFlashCursor(1, 0)
    EvtTalk(MSG_1C4)
    EvtClearTalk
    EvtCamera(30, 0)
    EvtFlashCursor(30, 0)
    EvtTalk(MSG_1C5)
    EvtClearTalk
    EvtLoadUnitsParty(UnitInfo_Unk_08680C60)
    EvtMoveWait
    EvtSetBgm(SONG_3E)
    EvtCameraUnit(PID_ROY)
    EvtFlashCursorUnit(PID_ROY)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_6)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_1C6)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086721F4
EventScr CONST_DATA EventScr_Unk_086721F4[] =
{
    EvtGotoIfFlag(3, FLAG_105)

    EvtGotoIfFlag(3, FLAG_112)

    EvtLoadUnits(UnitInfo_Unk_086811C0)
    EvtMoveWait
    EvtGotoIfNotFunc(3, IsCathNonBlue)

    EvtOverrideBgm(SONG_32)
    EvtTalk(MSG_1C7)
    EvtClearTalk
    EvtRestoreBgm

EvtLabel(3)
    EvtLoadUnits(UnitInfo_Unk_086811E0)
    EvtMoveWait

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08672260
EventScr CONST_DATA EventScr_Unk_08672260[] =
{
    EvtGotoIfFunc(1, IsBluePhase)

    EvtClearFlag(FLAG_CHAPTER22_5)
    EvtGoto(9)

EvtLabel(1)
    EvtLowerBgmVolume
    EvtGotoIfNotFunc(3, IsActiveUnitMale)

    EvtTalk(MSG_1C8)
    EvtClearTalk
    EvtGoto(7)

EvtLabel(3)
    EvtTalk(MSG_1C9)
    EvtClearTalk

EvtLabel(7)
    EvtRaiseBgmVolume
    EvtGotoIfNotFlag(9, FLAG_CHAPTER22_6)

    EvtSetFlag(FLAG_CHAPTER22_7)

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086722EC
EventScr CONST_DATA EventScr_Unk_086722EC[] =
{
    EvtGotoIfFunc(1, IsBluePhase)

    EvtClearFlag(FLAG_CHAPTER22_6)
    EvtGoto(9)

EvtLabel(1)
    EvtLowerBgmVolume
    EvtGotoIfNotFunc(3, IsActiveUnitMale)

    EvtTalk(MSG_1C8)
    EvtClearTalk
    EvtGoto(7)

EvtLabel(3)
    EvtTalk(MSG_1C9)
    EvtClearTalk

EvtLabel(7)
    EvtRaiseBgmVolume
    EvtGotoIfNotFlag(9, FLAG_CHAPTER22_5)

    EvtSetFlag(FLAG_CHAPTER22_7)

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08672378
EventScr CONST_DATA EventScr_Unk_08672378[] =
{
    EvtGotoIfNotFunc(1, IsBluePhase)

    EvtGotoIfNotFlag(1, FLAG_CHAPTER22_5)

    EvtGotoIfNotFlag(1, FLAG_CHAPTER22_6)

    EvtGotoIfActive(3, PID_ROY)

EvtLabel(1)
    EvtClearFlag(FLAG_CHAPTER22_8)
    EvtGoto(9)

EvtLabel(3)
    EvtOverrideBgm(SONG_2A)
    EvtMapChangePosition(15, 10)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_6)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_1CA)
    EvtClearTalk
    EvtLoadUnits(UnitInfo_Unk_08681120)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_08681170)
    EvtMoveWait
    EvtRestoreBgm

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08672430
EventScr CONST_DATA EventScr_Unk_08672430[] =
{
    EvtGotoIfNotFlag(9, FLAG_CHAPTER22_8)

    EvtLoadUnits(UnitInfo_Unk_086810D0)
    EvtMoveWait

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

u8 CONST_DATA gUnk_08672458[] =
{
    IID_BINDINGBLADE,
    IID_DURANDAL,
    IID_MALTET,
    IID_ARMADS,
    IID_MULAGIR,
    IID_FORBLAZE,
    IID_AUREOLA,
    IID_APOCALYPSE,
    0,
};

// EventScr @ 08672464
EventScr CONST_DATA EventScr_Unk_08672464[] =
{
    EvtFadeBgmOut(1)
    EvtGotoIfNotFunc(7, func_fe6_0806D150)

    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_6)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_1CD)
    EvtFunc(func_fe6_0806DE00)
    EvtFadeFromWhite(16)
    EvtEnterMap
    EvtTalkMore(MSG_1CE)
    EvtFunc(func_fe6_0806DE00)
    EvtFadeFromWhite(16)
    EvtEnterMap
    EvtSetBgm(SONG_0E)
    EvtTalkMore(MSG_1CF)
    EvtTalkMore(MSG_1D0)
    EvtFunc(func_fe6_0806DE20)
    EvtFadeToWhite(4)
    EvtExitMap
    EvtBackgroundMore(BACKGROUND_6)
    EvtFadeFromWhite(4)
    EvtEnterMap
    EvtTalkContinue
    EvtSleep(64)
    EvtNextChapter(CHAPTER_23)
    EvtSleep(1)
    EvtKill
    EvtGoto(9)

EvtLabel(7)
    EvtFunc(UpdateEndingId)
    EvtGameEnd
    EvtKill

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};
