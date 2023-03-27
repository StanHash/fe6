#pragma once

// EventScr @ 0866E00C
EventScr CONST_DATA EventScr_Unk_0866E00C[] =
{
    EvtSetFlag(FLAG_106)
    EvtCamera(18, 29)
    EvtFlashCursor(18, 29)
    EvtUnitCameraOff
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0DD)
    EvtClearTalk
    EvtSetBgm(SONG_24)
    EvtLoadUnitsParty(UnitInfo_Unk_0867C898)
    EvtMoveWait
    EvtCameraUnit(PID_ROY)
    EvtSleep(32)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0DE)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866E0AC
EventScr CONST_DATA EventScr_Unk_0866E0AC[] =
{
    EvtCamera(18, 29)
    EvtFlashCursor(18, 29)
    EvtUnitCameraOff
    EvtGotoIfFlag(3, FLAG_2)

    EvtSetBgm(SONG_03)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0DF)
    EvtClearTalk

EvtLabel(3)
    EvtLoadUnits(UnitInfo_Unk_0867CBB8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866E11C
EventScr CONST_DATA EventScr_Unk_0866E11C[] =
{
    EvtCamera(18, 17)
    EvtFlashCursor(18, 17)
    EvtOverrideBgm(SONG_12)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0E1)
    EvtClearTalk
    EvtLoadUnits(UnitInfo_Unk_0867CBD8)
    EvtMoveWait
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866E178
EventScr CONST_DATA EventScr_Unk_0866E178[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_0E2)
    EvtClearTalk
    EvtChangeFaction(PID_BARTRE, FACTION_BLUE)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866E1A4
EventScr CONST_DATA EventScr_Unk_0866E1A4[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_0E3)
    EvtClearTalk
    EvtChangeFaction(PID_BARTRE, FACTION_BLUE)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866E1D0
EventScr CONST_DATA EventScr_Unk_0866E1D0[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_0E4)
    EvtClearTalk
    EvtChangeFaction(PID_GONZALEZ, FACTION_BLUE)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866E1FC
EventScr CONST_DATA EventScr_Unk_0866E1FC[] =
{
    EvtOverrideBgm(SONG_33)
    EvtTalk(MSG_0E5)
    EvtClearTalk
    EvtChangeFaction(PID_GEESE, FACTION_BLUE)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866E228
EventScr CONST_DATA EventScr_Unk_0866E228[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0E6)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_SWORDREAVER)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866E270
EventScr CONST_DATA EventScr_Unk_0866E270[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0E7)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866E2AC
EventScr CONST_DATA EventScr_Unk_0866E2AC[] =
{
    EvtSetBgm(SONG_28)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_0EA)
    EvtClearTalk
    EvtNoSkip
    EvtGiveItemTo(IID_WYRMSLAYER, PID_ROY)
    EvtSleep(64)
    EvtNextChapter(CHAPTER_11_A)
    EvtSleep(1)
    EvtKill
    EvtClearSkip
    EvtEnd
};
