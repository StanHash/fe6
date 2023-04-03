#pragma once

u8 CONST_DATA MoveScr_Unk_0866F2C0[] =
{
    MOVE_CMD_MOVE_LEFT,
    MOVE_CMD_HALT,
};

u8 CONST_DATA MoveScr_Unk_0866F2C2[] =
{
    MOVE_CMD_MOVE_UP,
    MOVE_CMD_HALT,
};

// EventScr @ 0866F2C4
EventScr CONST_DATA EventScr_Unk_0866F2C4[] =
{
    EvtCameraUnit(PID_UNKNOWN_55)
    EvtSleep(16)
    EvtUnitCameraOff
    EvtLoadUnits(UnitInfo_Unk_0867DFD4)
    EvtMoveWait
    EvtTalk(MSG_116)
    EvtSetBgm(SONG_2A)
    EvtTalkContinue
    EvtClearTalk
    EvtLoadUnits(UnitInfo_Unk_0867DF44)
    EvtMoveWait
    EvtMoveUnit(PID_ZEPHIEL, 45, 13)
    EvtMoveUnit(PID_IDUNN, 45, 14)
    EvtMoveWait
    EvtTalk(MSG_117)
    EvtSetBgm(SONG_2A)
    EvtTalkContinue
    EvtClearTalk
    EvtMoveUnitScript(PID_IDUNN, MoveScr_Unk_0866F2C2)
    EvtMoveWait
    EvtRemoveUnit(PID_IDUNN)
    EvtSetBgm(SONG_24)
    EvtLoadUnitsParty(UnitInfo_Unk_0867DA14)
    EvtMoveWait
    EvtCameraUnit(PID_ROY)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_118)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

struct BattleHit CONST_DATA FightScr_Chapter13_CeciliaVsZephiel[] =
{
    // Cecilia attacks
    {
        .attributes = BATTLE_HIT_ATTR_MISS,
        .info = BATTLE_HIT_INFO_BEGIN,
        .damage = 0,
    },

    // Zephiel retaliates
    {
        .attributes = BATTLE_HIT_ATTR_CRIT,
        .info = BATTLE_HIT_INFO_FINISHES | BATTLE_HIT_INFO_ACTORB,
        .damage = 30,
    },

    // end
    { .info = BATTLE_HIT_INFO_END },
};

// EventScr @ 0866F3B0
EventScr CONST_DATA EventScr_Unk_0866F3B0[] =
{
    EvtNoSkip
    EvtFunc(func_fe6_0806CFD0)
    EvtCamera(43, 9)
    EvtMoveUnit(PID_ZEPHIEL, 43, 10)
    EvtMoveWait
    EvtTalk(MSG_119)
    EvtClearTalk
    EvtFightScript(PID_CECILIA, PID_ZEPHIEL, FightScr_Chapter13_CeciliaVsZephiel, FALSE)
    EvtTalk(MSG_11A)
    EvtClearTalk
    EvtRemoveUnitDisplayed(PID_CECILIA)
    EvtTalk(MSG_11B)
    EvtClearTalk
    EvtMoveUnit(PID_ZEPHIEL, 43, 9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866F428
EventScr CONST_DATA EventScr_Unk_0866F428[] =
{
    EvtLowerBgmVolume
    EvtCameraUnit(PID_PERCEVAL)
    EvtFlashCursorUnit(PID_PERCEVAL)
    EvtTalk(MSG_11C)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866F454
EventScr CONST_DATA EventScr_Unk_0866F454[] =
{
    EvtOverrideBgm(SONG_23)
    EvtCameraUnit(PID_ROY)
    EvtFlashCursorUnit(PID_ROY)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_11D)
    EvtClearTalk
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866F4A4
EventScr CONST_DATA EventScr_Unk_0866F4A4[] =
{
    EvtOverrideBgm(SONG_2A)
    EvtCamera(43, 9)
    EvtMoveUnit(PID_NARCIAN, 43, 10)
    EvtMoveWait
    EvtTalk(MSG_11E)
    EvtClearTalk
    EvtMoveUnit(PID_NARCIAN, 44, 10)
    EvtMoveWait
    EvtSleep(16)
    EvtLoadUnits(UnitInfo_Unk_0867DFB4)
    EvtMoveWait
    EvtTalk(MSG_11F)
    EvtFunc(func_fe6_08012798)
    EvtSleep(30)
    EvtGotoIfSkipped(22)

    EvtFunc(func_fe6_0806CFB8)

EvtLabel(22)
    EvtTalkContinue
    EvtFunc(func_fe6_08012780)
    EvtSleep(30)
    EvtGotoIfSkipped(23)

    EvtFunc(func_fe6_080127B0)

EvtLabel(23)
    EvtTalkContinue
    EvtClearTalk
    EvtMoveWait
    EvtRemoveUnit(PID_ZEPHIEL)
    EvtMoveWait
    EvtMoveUnitScript(PID_NARCIAN, MoveScr_Unk_0866F2C0)
    EvtRemoveUnit(PID_GUINIVERE)
    EvtMoveWait
    EvtMoveUnit(PID_NARCIAN, 43, 9)
    EvtMoveWait
    EvtRemoveUnit(PID_NARCIAN)
    EvtMoveWait
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866F5A8
EventScr CONST_DATA EventScr_Unk_0866F5A8[] =
{
    EvtNoSkip
    EvtOverrideBgm(SONG_2B)
    EvtCamera(43, 9)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_120)
    EvtClearTalk
    EvtLoadUnits(UnitInfo_Unk_0867DEC4)
    EvtMoveWait
    EvtMoveUnitNextTo(PID_MELADY, PID_ROY)
    EvtMoveWait
    EvtTalk(MSG_121)
    EvtClearTalk
    EvtChangeFaction(PID_MELADY, FACTION_BLUE)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866F628
EventScr CONST_DATA EventScr_Unk_0866F628[] =
{
    EvtOverrideBgm(SONG_2A)
    EvtCamera(43, 9)
    EvtFlashCursor(43, 9)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_122)
    EvtClearTalk
    EvtLoadUnits(UnitInfo_Unk_0867DF74)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0867DF94)
    EvtMoveWait
    EvtMoveUnit(PID_ZEPHIEL, 46, 10)
    EvtMoveUnit(PID_IDUNN, 46, 11)
    EvtMoveWait
    EvtRemoveUnit(PID_ZEPHIEL)
    EvtRemoveUnit(PID_IDUNN)
    EvtLoadUnits(UnitInfo_Unk_0867DF24)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866F6C4
EventScr CONST_DATA EventScr_Unk_0866F6C4[] =
{
    EvtCamera(43, 9)
    EvtFlashCursor(43, 9)
    EvtSetBgm(SONG_26)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_2)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_123)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866F710
EventScr CONST_DATA EventScr_Unk_0866F710[] =
{
    EvtGotoIfFunc(1, IsBluePhase)

    EvtClearFlag(FLAG_CHAPTER13_6)
    EvtGoto(9)

EvtLabel(1)
    EvtOverrideBgm(SONG_2C)
    EvtMoveUnit(PID_UNKNOWN_55, 43, 10)
    EvtMoveWait
    EvtTalk(MSG_124)
    EvtClearTalk
    EvtMoveUnit(PID_UNKNOWN_55, 42, 10)
    EvtMoveWait
    EvtMoveUnit(PID_NARCIAN, 46, 9)
    EvtMoveWait
    EvtRemoveUnit(PID_NARCIAN)
    EvtMoveUnit(PID_UNKNOWN_55, 43, 9)
    EvtMoveWait
    EvtSetAi(PID_UNKNOWN_86, AI_A_00, AI_B_00, 0)
    EvtRestoreBgm

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866F7B0
EventScr CONST_DATA EventScr_Unk_0866F7B0[] =
{
    EvtGotoIfNotFunc(9, IsPercevalNonBlue)

    EvtOverrideBgm(SONG_12)
    EvtCameraUnit(PID_PERCEVAL)
    EvtFlashCursorUnit(PID_PERCEVAL)
    EvtTalk(MSG_125)
    EvtClearTalk
    EvtMoveUnit(PID_PERCEVAL, 45, 6)
    EvtMoveWait
    EvtRemoveUnit(PID_PERCEVAL)
    EvtRestoreBgm
    EvtGotoIfNotFunc(1, func_fe6_0806C3EC)

    EvtMoveUnit(PID_UNKNOWN_D5, 45, 6)
    EvtMoveWait
    EvtRemoveUnit(PID_UNKNOWN_D5)

EvtLabel(1)
    EvtGotoIfNotFunc(2, func_fe6_0806C3FC)

    EvtMoveUnit(PID_UNKNOWN_D6, 45, 6)
    EvtMoveWait
    EvtRemoveUnit(PID_UNKNOWN_D6)

EvtLabel(2)
    EvtGotoIfNotFunc(9, func_fe6_0806C40C)

    EvtMoveUnit(PID_UNKNOWN_D7, 45, 6)
    EvtMoveWait
    EvtRemoveUnit(PID_UNKNOWN_D7)

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866F888
EventScr CONST_DATA EventScr_Unk_0866F888[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867DDA4)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0867DDF4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866F8A8
EventScr CONST_DATA EventScr_Unk_0866F8A8[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867DE34)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_0867DE84)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866F8C8
EventScr CONST_DATA EventScr_Unk_0866F8C8[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_149)
    EvtClearTalk
    EvtChangeFaction(PID_PERCEVAL, FACTION_BLUE)
    EvtSetFlag(FLAG_113)
    EvtChangeFaction(PID_UNKNOWN_D5, FACTION_GREEN)
    EvtSetAi(PID_UNKNOWN_D5, AI_A_06, AI_B_0C, 0)
    EvtChangeFaction(PID_UNKNOWN_D6, FACTION_GREEN)
    EvtSetAi(PID_UNKNOWN_D6, AI_A_06, AI_B_0C, 0)
    EvtChangeFaction(PID_UNKNOWN_D7, FACTION_GREEN)
    EvtSetAi(PID_UNKNOWN_D7, AI_A_06, AI_B_0C, 0)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866F944
EventScr CONST_DATA EventScr_Unk_0866F944[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_14A)
    EvtClearTalk
    EvtChangeFaction(PID_PERCEVAL, FACTION_BLUE)
    EvtSetFlag(FLAG_113)
    EvtChangeFaction(PID_UNKNOWN_D5, FACTION_GREEN)
    EvtSetAi(PID_UNKNOWN_D5, AI_A_06, AI_B_0C, 0)
    EvtChangeFaction(PID_UNKNOWN_D6, FACTION_GREEN)
    EvtSetAi(PID_UNKNOWN_D6, AI_A_06, AI_B_0C, 0)
    EvtChangeFaction(PID_UNKNOWN_D7, FACTION_GREEN)
    EvtSetAi(PID_UNKNOWN_D7, AI_A_06, AI_B_0C, 0)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866F9C0
EventScr CONST_DATA EventScr_Unk_0866F9C0[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_126)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_BODYRING)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866FA08
EventScr CONST_DATA EventScr_Unk_0866FA08[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_127)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_ALSSWORD)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866FA50
EventScr CONST_DATA EventScr_Unk_0866FA50[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_12E)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866FA8C
EventScr CONST_DATA EventScr_Unk_0866FA8C[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_12F)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866FAC8
EventScr CONST_DATA EventScr_Unk_0866FAC8[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_130)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866FB04
EventScr CONST_DATA EventScr_Unk_0866FB04[] =
{
    EvtGotoIfFlag(3, FLAG_CHAPTER13_5)

    EvtCamera(43, 15)
    EvtTalk(MSG_121)
    EvtClearTalk

EvtLabel(3)
    EvtSetBgm(SONG_27)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_133)
    EvtGotoIfSkipped(22)

    EvtSetBgm(SONG_26)

EvtLabel(22)
    EvtTalkContinue
    EvtClearTalk
    EvtGotoIfNotFunc(5, IsPercivalBlueDeployed)

    EvtGotoIfFlag(5, FLAG_CHAPTER13_14)

    EvtSetBgm(SONG_27)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_134)
    EvtClearTalk
    EvtNoSkip
    EvtGiveItemTo(IID_KNIGHTCREST, PID_PERCEVAL)
    EvtSetFlag(FLAG_119)

EvtLabel(5)
    EvtSleep(64)
    EvtNextChapter(CHAPTER_14)
    EvtSleep(1)
    EvtKill
    EvtClearSkip
    EvtEnd
};
