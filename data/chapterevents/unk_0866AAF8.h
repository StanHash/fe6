#pragma once

// EventScr @ 0866AAF8
EventScr CONST_DATA EventScr_RoyDefeated[] =
{
    EvtNoSkip
    EvtTalk(MSG_26B)
    EvtClearTalk
    EvtGotoIfNotFunc(1, IsLilinaBlueDeployed)

    EvtTalk(MSG_2A1)
    EvtClearTalk
    EvtGoto(9)

EvtLabel(1)
    EvtGotoIfNotFunc(2, IsGuinivereAround)

    EvtTalk(MSG_2A4)
    EvtClearTalk
    EvtGoto(9)

EvtLabel(2)
    EvtGotoIfNotFunc(3, IsMarcusBlueDeployed)

    EvtTalk(MSG_2A2)
    EvtClearTalk
    EvtGoto(9)

EvtLabel(3)
    EvtGotoIfNotFunc(9, IsMerlinusBlueDeployed)

    EvtTalk(MSG_2A3)
    EvtClearTalk

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866ABA8
EventScr CONST_DATA EventScr_CathTalk[] =
{
    EvtGotoIfFlag(2, FLAG_103)

    EvtOverrideBgm(SONG_32)
    EvtTalk(MSG_097)
    EvtClearTalk
    EvtSetAi(PID_CATH, AI_A_06, AI_B_0C, 0)
    EvtSetFlag(FLAG_103)
    EvtGoto(9)

EvtLabel(2)
    EvtGotoIfFlag(3, FLAG_104)

    EvtOverrideBgm(SONG_32)
    EvtTalk(MSG_098)
    EvtClearTalk
    EvtSetAi(PID_CATH, AI_A_06, AI_B_0C, 0)
    EvtSetFlag(FLAG_104)
    EvtGoto(9)

EvtLabel(3)
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_099)
    EvtClearTalk
    EvtChangeFaction(PID_CATH, FACTION_BLUE)
    EvtSetFlag(FLAG_105)

EvtLabel(9)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866AC6C
EventScr CONST_DATA EventScr_GameOver[] =
{
    EvtNoSkipNoTextSkip
    EvtSleep(30)
    EvtFunc(func_fe6_0806C608)
    EvtSleep(10)
    EvtFunc(StartSlowFadeToBlack)
    EvtSleep(80)
    EvtFunc(EndAllMus)
    EvtGotoIfFunc(1, func_fe6_0806C62C)

    EvtFunc(StartGameOverScreen)

EvtLabel(1)
    EvtFunc(func_fe6_080987B8)
    EvtClearSkip
    EvtEnd
};

u16 CONST_DATA Sprite_0866ACCC[] =
{
    4,
    OAM0_SHAPE_8x8 + OAM0_Y(-1), OAM1_SIZE_8x8 + OAM1_X(-2), 0,
    OAM0_SHAPE_8x8 + OAM0_Y(-1), OAM1_SIZE_8x8 + OAM1_X(9) + OAM1_HFLIP, 0,
    OAM0_SHAPE_8x8 + OAM0_Y(10), OAM1_SIZE_8x8 + OAM1_X(-2) + OAM1_VFLIP, 0,
    OAM0_SHAPE_8x8 + OAM0_Y(10), OAM1_SIZE_8x8 + OAM1_X(9) + OAM1_HFLIP + OAM1_VFLIP, 0,
};

struct ProcScr CONST_DATA ProcScr_Unk_0866ACE8[] =
{
    PROC_CALL(func_fe6_0806C7BC),
    PROC_REPEAT(func_fe6_0806C7E0),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_0866AD00[] =
{
    PROC_CALL(func_fe6_0806C948),
    PROC_REPEAT(func_fe6_0806C950),
    PROC_END,
};
