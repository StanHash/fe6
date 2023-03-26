#pragma once

u8 CONST_DATA MoveScr_Unk_0866D4FC[] =
{
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_HALT,
};

u8 CONST_DATA MoveScr_Unk_0866D50D[] =
{
    MOVE_CMD_SET_SPEED, 72,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_HALT,
};

// EventScr @ 0866D528
EventScr CONST_DATA EventScr_Unk_0866D528[] =
{
    EvtFunc(func_fe6_0806CF88)
    EvtUnitCameraOff
    EvtMove(6, 19, 6, 18)
    EvtMoveWait
    EvtTalk(MSG_0B2)
    EvtClearTalk
    EvtLoadUnitsParty(UnitInfo_Unk_0867BB5C)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0867BC2C)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0867BF7C)
    EvtMoveWait
    EvtMove(6, 18, 6, 19)
    EvtCameraUnit(PID_LILINA)
    EvtMoveWait
    EvtSleep(32)
    EvtSetBgm(SONG_23)
    EvtCameraUnit(PID_ROY)
    EvtMoveWait
    EvtSleep(16)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_6)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0B3)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D5E4
EventScr CONST_DATA EventScr_Unk_0866D5E4[] =
{
    EvtGotoIfFlag(9, FLAG_112)

    EvtOverrideBgm(SONG_32)
    EvtLoadUnits(UnitInfo_Unk_0867BE2C)
    EvtMoveWait
    EvtCameraUnit(PID_CATH)
    EvtTalk(MSG_0B6)
    EvtClearTalk
    EvtRestoreBgm

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D62C
EventScr CONST_DATA EventScr_Unk_0866D62C[] =
{
    EvtLowerBgmVolume
    EvtCameraUnit(PID_LILINA)
    EvtFlashCursorUnit(PID_LILINA)
    EvtTalk(MSG_0B4)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D658
EventScr CONST_DATA EventScr_Unk_0866D658[] =
{
    EvtOverrideBgm(SONG_33)
    EvtLoadUnits(UnitInfo_Unk_0867BF9C)
    EvtMoveWait
    EvtSleep(32)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_2)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0B5)
    EvtClearTalk
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D6AC
EventScr CONST_DATA EventScr_Unk_0866D6AC[] =
{
    EvtSetAi(PID_UNKNOWN_78, AI_A_06, AI_B_0C, 0)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D6C0
EventScr CONST_DATA EventScr_Unk_0866D6C0[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_0B7)
    EvtClearTalk
    EvtNoSkip
    EvtGiveItem(IID_THUNDER)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D6EC
EventScr CONST_DATA EventScr_Unk_0866D6EC[] =
{
    EvtTalk(MSG_0B8)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D700
EventScr CONST_DATA EventScr_Unk_0866D700[] =
{
    EvtTalk(MSG_0B9)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D714
EventScr CONST_DATA EventScr_Unk_0866D714[] =
{
    EvtTalk(MSG_0BA)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D728
EventScr CONST_DATA EventScr_Unk_0866D728[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_00A)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D764
EventScr CONST_DATA EventScr_Unk_0866D764[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_00B)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D7A0
EventScr CONST_DATA EventScr_Unk_0866D7A0[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_00C)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D7DC
EventScr CONST_DATA EventScr_Unk_0866D7DC[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_00D)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866D818
EventScr CONST_DATA EventScr_Unk_0866D818[] =
{
    EvtGotoIfNotFunc(3, func_fe6_0806C1B4)

    EvtSetBgm(SONG_28)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_6)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0BD)
    EvtSetBgm(SONG_31)
    EvtTalkContinue
    EvtClearTalk
    EvtSleep(64)
    EvtNextChapter(CHAPTER_8X)
    EvtSleep(1)
    EvtKill
    EvtGoto(9)

EvtLabel(3)
    EvtFadeBgmOut(1)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_6)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0BE)
    EvtClearTalk
    EvtUnitCameraOff
    EvtMoveUnitScript(PID_ROY, MoveScr_Unk_0866D4FC)
    EvtFadeToBlack(4)
    EvtExitMap
    EvtMoveWait
    EvtSetMap(CHAPTER_7, 8, 13)
    EvtMoveUnitScript(PID_ROY, MoveScr_Unk_0866D50D)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0867BFFC)
    EvtMoveWait
    EvtMoveUnit(PID_ROY, 6, 17)
    EvtFadeFromBlack(4)
    EvtEnterMap
    EvtMoveWait
    EvtSleep(16)
    EvtCameraUnit(PID_NARCIAN)
    EvtSetBgm(SONG_2C)
    EvtMove(1, 19, 3, 17)
    EvtMove(11, 19, 9, 17)
    EvtMoveWait
    EvtSleep(32)
    EvtMoveUnit(PID_NARCIAN, 6, 19)
    EvtMoveWait
    EvtSleep(32)
    EvtTalk(MSG_0BF)
    EvtClearTalk
    EvtUnitCameraOff
    EvtClearTalk
    EvtSetBgm(SONG_27)
    EvtLoadUnits(UnitInfo_Unk_0867C07C)
    EvtMoveWait
    EvtCameraUnit(PID_PERCEVAL)
    EvtUnitCameraOff
    EvtSleep(16)
    EvtLoadUnits(UnitInfo_Unk_0867C09C)
    EvtMoveWait
    EvtSleep(16)
    EvtLoadUnits(UnitInfo_Unk_0867C0BC)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0867C10C)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0867C15C)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0867C1AC)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0867C1EC)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0867C1FC)
    EvtMoveWait
    EvtTalk(MSG_0C0)
    EvtClearTalk
    EvtMoveUnit(PID_NARCIAN, 20, 12)
    EvtMoveWait
    EvtMove(3, 17, 19, 11)
    EvtMove(9, 17, 18, 11)
    EvtMoveWait
    EvtMove(3, 19, 18, 15)
    EvtMove(5, 19, 17, 15)
    EvtMoveWait
    EvtMove(7, 19, 16, 14)
    EvtMove(9, 19, 15, 14)
    EvtMoveWait
    EvtSleep(16)
    EvtMoveUnit(PID_PERCEVAL, 6, 19)
    EvtMoveUnit(PID_CECILIA, 7, 18)
    EvtMoveWait
    EvtTalk(MSG_0C1)
    EvtClearTalk
    EvtMoveUnit(PID_PERCEVAL, 6, 27)
    EvtMoveWait
    EvtSleep(16)
    EvtMoveUnit(PID_CECILIA, 6, 18)
    EvtMoveWait
    EvtTalk(MSG_0C2)
    EvtClearTalk
    EvtMoveUnit(PID_ROY, 6, 10)
    EvtMoveWait
    EvtTalk(MSG_0C3)
    EvtClearTalk
    EvtMoveUnit(PID_CECILIA, 5, 10)
    EvtFadeToBlack(4)
    EvtExitMap
    EvtMoveWait
    EvtSetMap(CHAPTER_8, 8, 13)
    EvtSleep(64)
    EvtNextChapter(CHAPTER_9)
    EvtSleep(1)
    EvtKill

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};
