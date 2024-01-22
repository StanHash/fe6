#pragma once

u8 CONST_DATA MoveScr_Unk_08674B10[] =
{
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_DOWN,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_MOVE_RIGHT,
    MOVE_CMD_HALT,
};

u8 CONST_DATA MoveScr_Unk_08674B22[] =
{
    MOVE_CMD_SET_SPEED, 0x48,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_HALT,
};

// EventScr @ 08674B2C
EventScr CONST_DATA EventScr_Unk_08674B2C[] =
{
    EvtFunc(AddChapter8xFireTraps)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_18)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_BD3)
    EvtClearTalk
    EvtSetBgm(SONG_0F)
    EvtLoadUnitsParty(UnitInfo_Unk_0868424C)
    EvtMoveWait
    EvtCameraUnit(PID_ROY)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_18)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_BD4)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08674BB0
EventScr CONST_DATA EventScr_Unk_08674BB0[] =
{
    EvtSetBgm(SONG_27)
    EvtGotoIfNotFunc(3, IsLilinaBlue)

    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_18)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_BD7)
    EvtClearTalk
    EvtGoto(5)

EvtLabel(3)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_18)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_BD8)
    EvtClearTalk

EvtLabel(5)
    EvtNoSkip
    EvtGiveItemTo(IID_DURANDAL, PID_ROY)
    EvtSleep(64)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_18)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0BE)
    EvtClearTalk
    EvtUnitCameraOff
    EvtMoveUnitScript(PID_ROY, MoveScr_Unk_08674B10)
    EvtFadeToBlack(4)
    EvtExitMap
    EvtMoveWait
    EvtFunc(DisableTilesetPalAnim)
    EvtSleep(1)
    EvtSetMap(CHAPTER_7, 8, 13)
    EvtMoveUnitScript(PID_ROY, MoveScr_Unk_08674B22)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0868451C)
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
    EvtLoadUnits(UnitInfo_Unk_0868459C)
    EvtMoveWait
    EvtCameraUnit(PID_PERCEVAL)
    EvtUnitCameraOff
    EvtSleep(16)
    EvtLoadUnits(UnitInfo_Unk_086845BC)
    EvtMoveWait
    EvtSleep(16)
    EvtLoadUnits(UnitInfo_Unk_086845DC)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0868462C)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0868467C)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_086846CC)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0868470C)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0868471C)
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
    EvtMoveWait
    EvtFunc(func_fe6_0806D55C)
    EvtNextChapter(CHAPTER_9)
    EvtSleep(1)
    EvtKill
    EvtClearSkip
    EvtEnd
};
