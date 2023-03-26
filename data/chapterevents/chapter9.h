#pragma once

// EventScr @ 0866DB60
EventScr CONST_DATA EventScr_Unk_0866DB60[] =
{
    EvtCamera(2, 3)
    EvtFlashCursor(2, 3)
    EvtUnitCameraOff
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0C7)
    EvtClearTalk
    EvtSetBgm(SONG_11)
    EvtLoadUnitsParty(UnitInfo_Unk_0867C3A4)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0867C714)
    EvtMoveWait
    EvtUnitCameraOn
    EvtMoveUnit(PID_ROY, 19, 15)
    EvtMoveWait
    EvtUnitCameraOff
    EvtTalk(MSG_0C8)
    EvtClearTalk
    EvtMoveUnit(PID_CECILIA, 18, 22)
    EvtMoveUnit(PID_GUINIVERE, 18, 21)
    EvtMoveWait
    EvtRemoveUnit(PID_CECILIA)
    EvtRemoveUnit(PID_GUINIVERE)
    EvtUnitCameraOn
    EvtMoveUnit(PID_ROY, 19, 13)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866DC2C
EventScr CONST_DATA EventScr_Unk_0866DC2C[] =
{
    EvtCamera(2, 3)
    EvtFlashCursor(2, 3)
    EvtSetBgm(SONG_09)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0CB)
    EvtClearTalk
    EvtLoadUnits(UnitInfo_Unk_0867C6E4)
    EvtFlashCursorUnit(PID_SIN)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0CD)
    EvtClearTalk
    EvtCamera(2, 3)
    EvtFlashCursor(2, 3)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0CC)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866DCF0
EventScr CONST_DATA EventScr_Unk_0866DCF0[] =
{
    EvtSetAi(PID_SIN, AI_A_00, AI_B_00, 0)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866DD04
EventScr CONST_DATA EventScr_Unk_0866DD04[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_0CE)
    EvtClearTalk
    EvtChangeFaction(PID_FIR, FACTION_BLUE)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866DD30
EventScr CONST_DATA EventScr_Unk_0866DD30[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_0CF)
    EvtClearTalk
    EvtChangeFaction(PID_SIN, FACTION_BLUE)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866DD5C
EventScr CONST_DATA EventScr_Unk_0866DD5C[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0D0)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_SILVERSWORD)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866DDA4
EventScr CONST_DATA EventScr_Unk_0866DDA4[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0D1)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_RESTORESTAFF)
    EvtMapChangePosition(18, 2)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866DDF4
EventScr CONST_DATA EventScr_Unk_0866DDF4[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0D2)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_KILLERBOW)
    EvtMapChangePosition(21, 2)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866DE44
EventScr CONST_DATA EventScr_Unk_0866DE44[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0D3)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866DE80
EventScr CONST_DATA EventScr_Unk_0866DE80[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0D4)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866DEBC
EventScr CONST_DATA EventScr_Unk_0866DEBC[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0D5)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866DEF8
EventScr CONST_DATA EventScr_Unk_0866DEF8[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0D6)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866DF34
EventScr CONST_DATA EventScr_Unk_0866DF34[] =
{
    EvtSetBgm(SONG_27)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0D9)
    EvtGotoIfFlag(0, FLAG_CHAPTER9_8)

    EvtGotoIfFlag(5, FLAG_CHAPTER9_7)

    EvtTalkMore(MSG_0DC)
    EvtGoto(2)

EvtLabel(0)
    EvtTalkMore(MSG_0DA)

EvtLabel(2)
    EvtClearTalk
    EvtSleep(64)
    EvtNextChapter(CHAPTER_10_A)
    EvtSleep(1)
    EvtKill
    EvtGoto(9)

EvtLabel(5)
    EvtTalkMore(MSG_0DB)
    EvtClearTalk
    EvtSleep(64)
    EvtNextChapter(CHAPTER_10_B)
    EvtSleep(1)
    EvtKill

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};
