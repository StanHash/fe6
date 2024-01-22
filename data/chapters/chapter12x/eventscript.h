#pragma once

// EventScr @ 08674F00
EventScr CONST_DATA EventScr_Unk_08674F00[] =
{
    EvtFunc(AddChapter12xGasTraps)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_17)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_BD9)
    EvtClearTalk
    EvtSetBgm(SONG_0F)
    EvtLoadUnitsParty(UnitInfo_Unk_08684824)
    EvtMoveWait
    EvtCameraUnit(PID_ROY)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_17)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_BDA)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08674F84
EventScr CONST_DATA EventScr_Unk_08674F84[] =
{
    EvtSetBgm(SONG_28)
    EvtGotoIfFunc(1, IsElffinBlue)

    EvtGotoIfNotFlag(3, FLAG_106)

EvtLabel(1)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_17)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_BDD)
    EvtClearTalk
    EvtGoto(5)

EvtLabel(3)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_17)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_BDE)
    EvtClearTalk

EvtLabel(5)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_17)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_115)
    EvtClearTalk
    EvtNoSkip
    EvtGiveItemTo(IID_ARMADS, PID_ROY)
    EvtSleep(64)
    EvtNextChapter(CHAPTER_13)
    EvtSleep(1)
    EvtKill
    EvtClearSkip
    EvtEnd
};
