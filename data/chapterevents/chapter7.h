#pragma once

u8 CONST_DATA MoveScr_Unk_0866CE60[] =
{
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_HALT,
};

// EventScr @ 0866CE68
EventScr CONST_DATA EventScr_Unk_0866CE68[] =
{
    EvtSetFlag(FLAG_CHAPTER7_9)
    EvtUnitCameraOff
    EvtMoveUnit(PID_UNKNOWN_50, 4, 2)
    EvtMoveWait
    EvtSleep(16)
    EvtLoadUnits(UnitInfo_Unk_0867BA60)
    EvtMoveWait
    EvtMoveUnit(PID_UNKNOWN_50, 5, 2)
    EvtMoveWait
    EvtTalk(MSG_09A)
    EvtClearTalk
    EvtMoveUnit(PID_UNKNOWN_50, 4, 2)
    EvtMoveWait
    EvtMoveUnit(PID_UNKNOWN_51, 8, 65535)
    EvtMoveWait
    EvtRemoveUnit(PID_UNKNOWN_51)
    EvtMoveUnit(PID_UNKNOWN_50, 5, 1)
    EvtMoveWait
    EvtGotoIfNotFunc(5, EvtCheck_IsHard)

    EvtLoadUnits(UnitInfo_Unk_0867B8D0)
    EvtMoveWait

EvtLabel(5)
    EvtSleep(16)
    EvtSetBgm(SONG_24)
    EvtLoadUnitsParty(UnitInfo_Unk_0867B680)
    EvtMoveWait
    EvtCameraUnit(PID_ROY)
    EvtSleep(32)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_09B)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866CF6C
EventScr CONST_DATA EventScr_Unk_0866CF6C[] =
{
    EvtGotoIfFunc(9, func_fe6_0806C4D8)

    EvtClearFlag(FLAG_CHAPTER7_14)

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866CF90
EventScr CONST_DATA EventScr_Unk_0866CF90[] =
{
    EvtOverrideBgm(SONG_12)
    EvtCamera(15, 15)
    EvtSleep(16)
    EvtLoadUnits(UnitInfo_Unk_0867B930)
    EvtMoveWait
    EvtSleep(16)
    EvtTalk(MSG_09C)
    EvtClearTalk
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866CFD4
EventScr CONST_DATA EventScr_Unk_0866CFD4[] =
{
    EvtOverrideBgm(SONG_12)
    EvtCamera(8, 16)
    EvtUnitCameraOff
    EvtSleep(16)
    EvtFlashCursor(6, 16)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_16)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_09D)
    EvtClearTalk
    EvtLoadUnits(UnitInfo_Unk_0867BA80)
    EvtMoveWait
    EvtSleep(32)
    EvtMoveUnit(PID_FIR, 7, 28)
    EvtMoveWait
    EvtRemoveUnit(PID_FIR)
    EvtLoadUnits(UnitInfo_Unk_0867B960)
    EvtMoveWait
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D068
EventScr CONST_DATA EventScr_Unk_0866D068[] =
{
    EvtGotoIfFlag(9, FLAG_CHAPTER7_2)

    EvtCamera(5, 1)
    EvtFlashCursor(5, 1)
    EvtSleep(16)
    EvtTalk(MSG_09E)
    EvtClearTalk

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D0A8
EventScr CONST_DATA EventScr_Unk_0866D0A8[] =
{
    EvtGotoIfFlag(9, FLAG_CHAPTER7_2)

    EvtLoadUnits(UnitInfo_Unk_0867BA10)
    EvtMoveWait

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D0D0
EventScr CONST_DATA EventScr_Unk_0866D0D0[] =
{
    EvtGotoIfFlag(9, FLAG_CHAPTER7_2)

    EvtLoadUnits(UnitInfo_Unk_0867B980)
    EvtMoveWait

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D0F8
EventScr CONST_DATA EventScr_Unk_0866D0F8[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_09F)
    EvtClearTalk
    EvtChangeFaction(PID_ZELOT, FACTION_BLUE)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D124
EventScr CONST_DATA EventScr_Unk_0866D124[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_0A0)
    EvtClearTalk
    EvtChangeFaction(PID_NOAH, FACTION_BLUE)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D150
EventScr CONST_DATA EventScr_Unk_0866D150[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_0A1)
    EvtClearTalk
    EvtChangeFaction(PID_NOAH, FACTION_BLUE)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D17C
EventScr CONST_DATA EventScr_Unk_0866D17C[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_0A2)
    EvtClearTalk
    EvtChangeFaction(PID_TREC, FACTION_BLUE)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D1A8
EventScr CONST_DATA EventScr_Unk_0866D1A8[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_0A3)
    EvtClearTalk
    EvtChangeFaction(PID_TREC, FACTION_BLUE)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D1D4
EventScr CONST_DATA EventScr_Unk_0866D1D4[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_0A4)
    EvtClearTalk
    EvtChangeFaction(PID_ZELOT, FACTION_BLUE)
    EvtClearFlag(FLAG_CHAPTER7_9)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D208
EventScr CONST_DATA EventScr_Unk_0866D208[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_0A5)
    EvtClearTalk
    EvtChangeFaction(PID_ZELOT, FACTION_BLUE)
    EvtClearFlag(FLAG_CHAPTER7_9)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D23C
EventScr CONST_DATA EventScr_Unk_0866D23C[] =
{
    EvtLowerBgmVolume
    EvtTalk(MSG_0A6)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D258
EventScr CONST_DATA EventScr_Unk_0866D258[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0A7)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_LONGBOW)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D2A0
EventScr CONST_DATA EventScr_Unk_0866D2A0[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0A8)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_TORCHSTAFF)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D2E8
EventScr CONST_DATA EventScr_Unk_0866D2E8[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0A9)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_ELIXIR)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D330
EventScr CONST_DATA EventScr_Unk_0866D330[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0AA)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_REDGEM)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D378
EventScr CONST_DATA EventScr_Unk_0866D378[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0AB)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_PHYSICSTAFF)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D3C0
EventScr CONST_DATA EventScr_Unk_0866D3C0[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0AC)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_KILLINGEDGE)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D408
EventScr CONST_DATA EventScr_Unk_0866D408[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0AD)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_HEROCREST)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D450
EventScr CONST_DATA EventScr_Unk_0866D450[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0AE)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_HORSESLAYER)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D498
EventScr CONST_DATA EventScr_Unk_0866D498[] =
{
    EvtSetBgm(SONG_27)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_6)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0B1)
    EvtSetBgm(SONG_25)
    EvtTalkContinue
    EvtClearTalk
    EvtSleep(64)
    EvtNextChapter(CHAPTER_UNK_08)
    EvtSleep(1)
    EvtKill
    EvtClearSkip
    EvtEnd
};
