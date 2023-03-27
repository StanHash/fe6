#pragma once

// EventScr @ 0866C308
EventScr CONST_DATA EventScr_Unk_0866C308[] =
{
    EvtSleep(16)
    EvtCamera(3, 8)
    EvtSleep(16)
    EvtUnitCameraOff
    EvtMoveUnit(PID_NARCIAN, 3, 8)
    EvtMoveWait
    EvtSleep(16)
    EvtRemoveUnit(PID_NARCIAN)
    EvtSleep(16)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_06F)
    EvtClearTalk
    EvtLoadUnits(UnitInfo_Unk_0867A81C)
    EvtMoveWait
    EvtSleep(16)
    EvtUnitCameraOn
    EvtMoveUnit(PID_NARCIAN, 13, -1)
    EvtMoveWait
    EvtRemoveUnit(PID_NARCIAN)
    EvtSleep(16)
    EvtCamera(0, 8)
    EvtSleep(16)
    EvtUnitCameraOff
    EvtMoveUnit(PID_UNKNOWN_4D, 3, 8)
    EvtMoveWait
    EvtLoadUnitsParty(UnitInfo_Unk_0867A70C)
    EvtMoveWait
    EvtSleep(16)
    EvtCameraUnit(PID_ROY)
    EvtFunc(ApplyAllHardModeBonusLevels)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866C400
EventScr CONST_DATA EventScr_Unk_0866C400[] =
{
    EvtSetBgm(SONG_02)
    EvtSleep(16)
    EvtLowerBgmVolume
    EvtLoadUnits(UnitInfo_Unk_0867A93C)
    EvtMoveWait
    EvtTalk(MSG_070)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866C438
EventScr CONST_DATA EventScr_Unk_0866C438[] =
{
    EvtCamera(4, 8)
    EvtLowerBgmVolume
    EvtSleep(16)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_2)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_071)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866C484
EventScr CONST_DATA EventScr_Unk_0866C484[] =
{
    EvtCamera(4, 8)
    EvtLowerBgmVolume
    EvtSleep(16)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_072)
    EvtClearTalk
    EvtLoadUnits(UnitInfo_Unk_0867A9BC)
    EvtMoveWait
    EvtTalk(MSG_074)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866C4E8
EventScr CONST_DATA EventScr_Unk_0866C4E8[] =
{
    EvtGotoIfFlag(9, FLAG_2)

    EvtCamera(4, 9)
    EvtSleep(16)
    EvtSetBgm(SONG_02)
    EvtUnitCameraOff
    EvtLoadUnits(UnitInfo_Unk_0867A9DC)
    EvtMoveWait
    EvtTalk(MSG_073)
    EvtClearTalk

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866C538
EventScr CONST_DATA EventScr_Unk_0866C538[] =
{
    EvtGotoIfFlag(9, FLAG_2)

    EvtCamera(3, 8)
    EvtFlashCursor(3, 8)
    EvtSetBgm(SONG_02)
    EvtSleep(16)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_075)
    EvtClearTalk

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866C5A0
EventScr CONST_DATA EventScr_Unk_0866C5A0[] =
{
    EvtGotoIfFlag(9, FLAG_2)

    EvtLoadUnits(UnitInfo_Unk_0867A96C)
    EvtMoveWait

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866C5C8
EventScr CONST_DATA EventScr_Unk_0866C5C8[] =
{
    EvtOverrideBgm(SONG_33)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_076)
    EvtClearTalk
    EvtChangeFaction(PID_CLARINE, FACTION_BLUE)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866C614
EventScr CONST_DATA EventScr_Unk_0866C614[] =
{
    EvtFunc(func_fe6_0806CED8)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866C624
EventScr CONST_DATA EventScr_Unk_0866C624[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_077)
    EvtClearTalk
    EvtChangeFaction(PID_RUTGER, FACTION_BLUE)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866C650
EventScr CONST_DATA EventScr_Unk_0866C650[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_078)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_DOORKEY)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866C698
EventScr CONST_DATA EventScr_Unk_0866C698[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_079)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_STEELBLADE)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866C6E0
EventScr CONST_DATA EventScr_Unk_0866C6E0[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_07A)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_SERAPHROBE)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866C728
EventScr CONST_DATA EventScr_Unk_0866C728[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_07B)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866C764
EventScr CONST_DATA EventScr_Unk_0866C764[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_07C)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866C7A0
EventScr CONST_DATA EventScr_Unk_0866C7A0[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_07D)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866C7DC
EventScr CONST_DATA EventScr_Unk_0866C7DC[] =
{
    EvtSetBgm(SONG_27)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_080)
    EvtSetBgm(SONG_2B)
    EvtTalkContinue
    EvtClearTalk
    EvtSleep(64)
    EvtNextChapter(CHAPTER_5)
    EvtSleep(1)
    EvtKill
    EvtClearSkip
    EvtEnd
};
