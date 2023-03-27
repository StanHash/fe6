#pragma once

// EventScr @ 0867557C
EventScr CONST_DATA EventScr_Unk_0867557C[] =
{
    EvtCamera(16, 1)
    EvtFlashCursor(16, 1)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_13)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_BEE)
    EvtClearTalk
    EvtSetBgm(SONG_0F)
    EvtLoadUnitsParty(UnitInfo_Unk_08685100)
    EvtMoveWait
    EvtCameraUnit(PID_ROY)
    EvtFlashCursorUnit(PID_ROY)
    EvtGotoIfFunc(1, IsZelotBlueDeployed)

    EvtGotoIfFunc(2, IsJunoBlueDeployed)

    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_13)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_BF2)
    EvtClearTalk
    EvtGoto(9)

EvtLabel(1)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_13)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_BF0)
    EvtClearTalk
    EvtGoto(9)

EvtLabel(2)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_13)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_BF1)
    EvtClearTalk

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086756A8
EventScr CONST_DATA EventScr_Unk_086756A8[] =
{
    EvtSetBgm(SONG_27)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_13)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_BF5)
    EvtClearTalk
    EvtNoSkip
    EvtGiveItemTo(IID_MALTET, PID_ROY)
    EvtSetBgm(SONG_2B)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_13)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_1AE)
    EvtSetBgm(SONG_3C)
    EvtTalkContinue
    EvtClearTalk
    EvtSleep(64)
    EvtNextChapter(CHAPTER_21)
    EvtSleep(1)
    EvtKill
    EvtClearSkip
    EvtEnd
};
