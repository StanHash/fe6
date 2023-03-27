#pragma once

u8 CONST_DATA MoveScr_Unk_0866B9C4[] =
{
    MOVE_CMD_SET_SPEED, 18,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_HALT,
};

u8 CONST_DATA MoveScr_Unk_0866B9CA[] =
{
    MOVE_CMD_SET_SPEED, 22,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_HALT,
};

// EventScr @ 0866B9D0
EventScr CONST_DATA EventScr_Unk_0866B9D0[] =
{
    EvtCamera(18, 0)
    EvtUnitCameraOff
    EvtLoadUnits(UnitInfo_Unk_0867A06C)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0867A04C)
    EvtMoveWait
    EvtTalk(MSG_04D)
    EvtClearTalk
    EvtMoveUnit(PID_UNKNOWN_4B, 17, 4)
    EvtMoveWait
    EvtMoveUnit(PID_MELADY, 13, -1)
    EvtMoveWait
    EvtRemoveUnit(PID_MELADY)
    EvtSleep(16)
    EvtMoveUnit(PID_UNKNOWN_4B, 16, 4)
    EvtMoveWait
    EvtSleep(16)
    EvtLoadUnits(UnitInfo_Unk_0867A08C)
    EvtSetBgm(SONG_02)
    EvtTalk(MSG_04E)
    EvtClearTalk
    EvtSleep(16)
    EvtMove(16, 3, 17, 11)
    EvtMoveWait
    EvtMoveUnit(PID_UNKNOWN_4B, 16, 3)
    EvtMoveWait
    EvtUnitCameraOff
    EvtLoadUnits(UnitInfo_Unk_08679E8C)
    EvtMoveWait
    EvtFadeBgmOut(1)
    EvtSleep(16)
    EvtSetBgm(SONG_24)
    EvtLoadUnitsParty(UnitInfo_Unk_08679DEC)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_08679E5C)
    EvtMoveWait
    EvtSleep(16)
    EvtCameraUnit(PID_ROY)
    EvtSleep(16)
    EvtMoveUnit(PID_MERLINUS, 2, 9)
    EvtMoveWait
    EvtTalk(MSG_04F)
    EvtClearTalk
    EvtLoadUnits(UnitInfo_Unk_0867A0AC)
    EvtMoveWait
    EvtMoveUnitScript(PID_ELEN, MoveScr_Unk_0866B9C4)
    EvtMoveWait
    EvtSleep(16)
    EvtMoveUnitScript(PID_ELEN, MoveScr_Unk_0866B9CA)
    EvtMoveWait
    EvtTalk(MSG_050)
    EvtSetBgm(SONG_23)
    EvtTalkContinue
    EvtClearTalk
    EvtLoadUnits(UnitInfo_Unk_08679F5C)
    EvtSleep(16)
    EvtCamera(0, 14)
    EvtUnitCameraOff
    EvtMoveWait
    EvtTalk(MSG_051)
    EvtClearTalk
    EvtLoadUnits(UnitInfo_Unk_08679F7C)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_08679FAC)
    EvtMoveWait
    EvtCameraUnit(PID_ROY)
    EvtTalk(MSG_052)
    EvtClearTalk
    EvtMoveUnit(PID_MERLINUS, 1, 9)
    EvtMoveUnit(PID_ELEN, 4, 10)
    EvtMoveWait
    EvtFunc(ApplyAllHardModeBonusLevels)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866BBD0
EventScr CONST_DATA EventScr_Unk_0866BBD0[] =
{
    EvtSleep(32)
    EvtOverrideBgm(SONG_33)
    EvtCamera(20, 18)
    EvtSleep(32)
    EvtLoadUnits(UnitInfo_Unk_08679FEC)
    EvtLoadUnits(UnitInfo_Unk_0867A01C)
    EvtMoveWait
    EvtTalk(MSG_053)
    EvtClearTalk
    EvtUnitCameraOff
    EvtMoveUnit(PID_SHANNA, 0, 13)
    EvtMoveWait
    EvtMoveUnit(PID_WARD, 13, 16)
    EvtMoveWait
    EvtMoveUnit(PID_LOT, 13, 18)
    EvtMoveWait
    EvtTalk(MSG_054)
    EvtClearTalk
    EvtMoveUnit(PID_SHANNA, 12, 17)
    EvtMoveWait
    EvtTalk(MSG_055)
    EvtClearTalk
    EvtMoveUnit(PID_WARD, 12, 16)
    EvtMoveUnit(PID_LOT, 12, 18)
    EvtMoveUnit(PID_SHANNA, 14, 17)
    EvtMoveWait
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866BCA0
EventScr CONST_DATA EventScr_Unk_0866BCA0[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_056)
    EvtClearTalk
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866BCC0
EventScr CONST_DATA EventScr_Unk_0866BCC0[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_057)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveMoney(3000)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866BD08
EventScr CONST_DATA EventScr_Unk_0866BD08[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_058)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_ARMORSLAYER)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866BD50
EventScr CONST_DATA EventScr_Unk_0866BD50[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_059)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866BD8C
EventScr CONST_DATA EventScr_Unk_0866BD8C[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_05A)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866BDC8
EventScr CONST_DATA EventScr_Unk_0866BDC8[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_05B)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866BE04
EventScr CONST_DATA EventScr_Unk_0866BE04[] =
{
    EvtSetBgm(SONG_27)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_05E)
    EvtGotoIfNotFunc(1, IsElenBlue)

    EvtTalkMore(MSG_05F)

EvtLabel(1)
    EvtTalkMore(MSG_060)
    EvtGotoIfNotFunc(2, IsElenBlue)

    EvtTalkMore(MSG_061)

EvtLabel(2)
    EvtSetBgm(SONG_2B)
    EvtTalkMore(MSG_062)
    EvtTalkContinue
    EvtClearTalk
    EvtSleep(64)
    EvtNextChapter(CHAPTER_3)
    EvtSleep(1)
    EvtKill
    EvtClearSkip
    EvtEnd
};
