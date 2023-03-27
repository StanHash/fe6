#pragma once

// EventScr @ 08674358
EventScr CONST_DATA EventScr_Unk_08674358[] =
{
    EvtFlashCursor(16, 1)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_8)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_993)
    EvtClearTalk
    EvtSetBgm(SONG_2B)
    EvtLoadUnitsParty(UnitInfo_Unk_086837F0)
    EvtMoveWait
    EvtCameraUnit(PID_ROY)
    EvtFlashCursorUnit(PID_ROY)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_994)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086743E4
EventScr CONST_DATA EventScr_Unk_086743E4[] =
{
    EvtCamera(16, 11)
    EvtFlashCursor(16, 11)
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_995)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08674430
EventScr CONST_DATA EventScr_Unk_08674430[] =
{
    EvtGotoIfFlag(9, FLAG_2)

    EvtLoadUnits(UnitInfo_Unk_08683BC0)
    EvtMoveWait

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08674458
EventScr CONST_DATA EventScr_Unk_08674458[] =
{
    EvtGotoIfFlag(9, FLAG_2)

    EvtCamera(16, 1)
    EvtFlashCursor(16, 1)
    EvtSetBgm(SONG_04)
    EvtSleep(16)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_996)
    EvtClearTalk

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086744C0
EventScr CONST_DATA EventScr_Unk_086744C0[] =
{
    EvtGotoIfFlag(9, FLAG_2)

    EvtLoadUnits(UnitInfo_Unk_08683C70)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_08683CC0)
    EvtMoveWait

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086744F4
EventScr CONST_DATA EventScr_Unk_086744F4[] =
{
    EvtGotoIfFlag(9, FLAG_2)

    EvtCamera(16, 16)
    EvtFlashCursor(16, 16)
    EvtSetBgm(SONG_04)
    EvtSleep(16)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_998)
    EvtClearTalk
    EvtMapChangePosition(16, 16)

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08674564
EventScr CONST_DATA EventScr_Unk_08674564[] =
{
    EvtGotoIfFlag(9, FLAG_2)

    EvtSetBgm(SONG_04)
    EvtCamera(16, 1)
    EvtFlashCursor(16, 1)
    EvtSleep(16)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_997)
    EvtClearTalk

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086745CC
EventScr CONST_DATA EventScr_Unk_086745CC[] =
{
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtClearTalk
    EvtChangeFaction(PID_THEA, FACTION_BLUE)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08674604
EventScr CONST_DATA EventScr_Unk_08674604[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_999)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_WYRMSLAYER)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867464C
EventScr CONST_DATA EventScr_Unk_0867464C[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_99A)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_ENERGYRING)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08674694
EventScr CONST_DATA EventScr_Unk_08674694[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_99B)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_GODDESSICON)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086746DC
EventScr CONST_DATA EventScr_Unk_086746DC[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_99C)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_WODAO)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08674724
EventScr CONST_DATA EventScr_Unk_08674724[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_99D)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_LONGBOW)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867476C
EventScr CONST_DATA EventScr_Unk_0867476C[] =
{
    EvtSetBgm(SONG_27)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_8)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_9A0)
    EvtSetBgm(SONG_3F)
    EvtTalkContinue
    EvtClearTalk
    EvtSleep(64)
    EvtNextChapter(CHAPTER_20_S)
    EvtSleep(1)
    EvtKill
    EvtClearSkip
    EvtEnd
};
