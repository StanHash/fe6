#pragma once

// EventScr @ 0866C840
EventScr CONST_DATA EventScr_Unk_0866C840[] =
{
    EvtCamera(2, 14)
    EvtSleep(16)
    EvtTalk(MSG_081)
    EvtClearTalk
    EvtUnitCameraOff
    EvtLoadUnitsParty(UnitInfo_Unk_0867AB48)
    EvtMoveWait
    EvtSetBgm(SONG_24)
    EvtCameraUnit(PID_ROY)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_082)
    EvtClearTalk
    EvtSleep(64)
    EvtFunc(ApplyAllHardModeBonusLevels)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866C8C0
EventScr CONST_DATA EventScr_Unk_0866C8C0[] =
{
    EvtOverrideBgm(SONG_32)
    EvtCamera(10, 0)
    EvtUnitCameraOff
    EvtFlashCursor(10, 2)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_083)
    EvtClearTalk
    EvtLoadUnits(UnitInfo_Unk_0867AE98)
    EvtMoveUnit(PID_SAUL, 20, 5)
    EvtMoveUnit(PID_DOROTHY, 20, 6)
    EvtMoveWait
    EvtRemoveUnit(PID_SAUL)
    EvtRemoveUnit(PID_DOROTHY)
    EvtRestoreBgm
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866C948
EventScr CONST_DATA EventScr_Unk_0866C948[] =
{
    EvtGotoIfFunc(1, IsBluePhase)

    EvtClearFlag(FLAG_CHAPTER5_5)
    EvtGoto(9)

EvtLabel(1)
    EvtLowerBgmVolume
    EvtTalk(MSG_084)
    EvtClearTalk
    EvtMapChangePosition(6, 16)
    EvtGotoIfFlag(7, FLAG_2)

    EvtSleep(32)
    EvtCamera(2, 14)
    EvtTalk(MSG_085)
    EvtClearTalk
    EvtGotoIfNotFunc(7, IsHard)

    EvtLoadUnits(UnitInfo_Unk_0867AE18)

EvtLabel(7)
    EvtRaiseBgmVolume

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866C9DC
EventScr CONST_DATA EventScr_Unk_0866C9DC[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_1)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_086)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtNoSkip
    EvtGiveItem(IID_GANTSLANCE)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866CA24
EventScr CONST_DATA EventScr_Unk_0866CA24[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_087)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866CA60
EventScr CONST_DATA EventScr_Unk_0866CA60[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_088)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866CA9C
EventScr CONST_DATA EventScr_Unk_0866CA9C[] =
{
    EvtLowerBgmVolume
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_0)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_089)
    EvtClearTalk
    EvtRaiseBgmVolume
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0866CAD8
EventScr CONST_DATA EventScr_Unk_0866CAD8[] =
{
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_5)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_08C)
    EvtSetBgm(SONG_25)
    EvtTalkContinue
    EvtClearTalk
    EvtSleep(64)
    EvtNextChapter(CHAPTER_6)
    EvtSleep(1)
    EvtKill
    EvtClearSkip
    EvtEnd
};
