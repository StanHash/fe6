#pragma once

// EventScr @ 08672BE4
EventScr CONST_DATA EventScr_Unk_08672BE4[] =
{
    EvtFunc(InitPlayerDeployUnits)
    EvtFunc(InitPlayerDeployUnitPositions)
    EvtFunc(RefreshEntityMaps)
    EvtFunc(RefreshUnitSprites)
    EvtUnitCameraOff
    EvtSleep(16)
    EvtMoveUnit(PID_ROY, 8, 9)
    EvtMoveWait
    EvtSleep(16)
    EvtCameraUnit(PID_IDUNN)
    EvtSetBgm(SONG_29)
    EvtTalk(MSG_201)
    EvtClearTalk
    EvtFunc(func_fe6_0806DE00)
    EvtFadeToWhite(4)
    EvtExitMap
    EvtSleep(30)
    EvtRemoveUnit(PID_IDUNN)
    EvtLoadUnits(UnitInfo_Unk_08681DF4)
    EvtMoveWait
    EvtSleep(32)
    EvtFadeFromWhite(4)
    EvtEnterMap
    EvtSleep(16)
    EvtCamera(8, 15)
    EvtSleep(16)
    EvtFunc(func_fe6_0806D1D4)
    EvtFuncWhile(func_fe6_0806D1FC)
    EvtClearTalk
    EvtCameraUnit(PID_ROY)
    EvtUnitCameraOn
    EvtGotoIfFlag(5, FLAG_108)

    EvtTalk(MSG_236)
    EvtGoto(6)

EvtLabel(5)
    EvtTalk(MSG_237)

EvtLabel(6)
    EvtClearTalk
    EvtMoveUnit(PID_ROY, 8, 16)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08672D10
EventScr CONST_DATA EventScr_Unk_08672D10[] =
{
    EvtGotoIfFunc(0, func_fe6_0806D35C)

EvtLabel(1)
    EvtGotoIfNotFunc(2, func_fe6_0806D398)

    EvtLoadUnits(UnitInfo_Unk_08681E14)
    EvtGoto(9)

EvtLabel(2)
    EvtGotoIfNotFunc(3, func_fe6_0806D398)

    EvtLoadUnits(UnitInfo_Unk_08681E34)
    EvtGoto(9)

EvtLabel(3)
    EvtGotoIfNotFunc(4, func_fe6_0806D398)

    EvtLoadUnits(UnitInfo_Unk_08681E54)
    EvtGoto(9)

EvtLabel(4)
    EvtLoadUnits(UnitInfo_Unk_08681E74)

EvtLabel(9)
    EvtMoveWait

EvtLabel(0)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08672DB4
EventScr CONST_DATA EventScr_Unk_08672DB4[] =
{
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08672DE0
EventScr CONST_DATA EventScr_Unk_08672DE0[] =
{
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08672E0C
EventScr CONST_DATA EventScr_Unk_08672E0C[] =
{
    EvtFunc(func_fe6_0806E278)
    EvtFunc(UpdateEndingId)
    EvtFadeBgmOut(4)
    EvtFadeToBlack(4)
    EvtExitMap
    EvtGameEnd
    EvtKill
    EvtClearSkip
    EvtEnd
};
