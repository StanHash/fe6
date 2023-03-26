#pragma once

u32 CONST_DATA gUnk_08675750[] =
{
    FLAG_CHAPTER20XS_10,
    FLAG_CHAPTER20XS_11,
    FLAG_CHAPTER20XS_12,
    FLAG_CHAPTER20XS_13,
    FLAG_CHAPTER20XS_14,
    FLAG_CHAPTER20XS_15,
};

// EventScr @ 08675768
EventScr CONST_DATA EventScr_Unk_08675768[] =
{
    EvtFunc(func_fe6_0806D6B4)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_BF6)
    EvtClearTalk
    EvtSetBgm(SONG_0F)
    EvtLoadUnitsParty(UnitInfo_Unk_086854A0)
    EvtMoveWait
    EvtCameraUnit(PID_ROY)
    EvtFlashCursorUnit(PID_ROY)
    EvtGotoIfFunc(1, func_fe6_0806C108)

    EvtGotoIfFunc(2, func_fe6_0806C118)

    EvtGotoIfFunc(3, func_fe6_0806C128)

    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_BFA)
    EvtClearTalk
    EvtGoto(9)

EvtLabel(1)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_BF7)
    EvtClearTalk
    EvtGoto(9)

EvtLabel(2)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_BF8)
    EvtClearTalk
    EvtGoto(9)

EvtLabel(3)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_BF9)
    EvtClearTalk

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086758D4
EventScr CONST_DATA EventScr_Unk_086758D4[] =
{
    EvtGotoIfNotFlag(5, FLAG_CHAPTER20XS_10)

    EvtSetFlag(FLAG_CHAPTER20XS_3)
    EvtGoto(9)

EvtLabel(5)
    EvtLoadUnits(UnitInfo_Unk_086857C0)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_08685800)
    EvtMoveWait
    EvtTalk(MSG_BFC)
    EvtClearTalk

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867592C
EventScr CONST_DATA EventScr_Unk_0867592C[] =
{
    EvtGotoIfNotFlag(5, FLAG_CHAPTER20XS_11)

    EvtSetFlag(FLAG_CHAPTER20XS_3)
    EvtGoto(9)

EvtLabel(5)
    EvtLoadUnits(UnitInfo_Unk_08685840)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_08685880)
    EvtMoveWait
    EvtTalk(MSG_BFC)
    EvtClearTalk

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08675984
EventScr CONST_DATA EventScr_Unk_08675984[] =
{
    EvtGotoIfNotFlag(5, FLAG_CHAPTER20XS_12)

    EvtSetFlag(FLAG_CHAPTER20XS_3)
    EvtGoto(9)

EvtLabel(5)
    EvtLoadUnits(UnitInfo_Unk_086858B0)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_086858F0)
    EvtMoveWait
    EvtTalk(MSG_BFC)
    EvtClearTalk

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086759DC
EventScr CONST_DATA EventScr_Unk_086759DC[] =
{
    EvtGotoIfNotFlag(5, FLAG_CHAPTER20XS_13)

    EvtSetFlag(FLAG_CHAPTER20XS_3)
    EvtGoto(9)

EvtLabel(5)
    EvtLoadUnits(UnitInfo_Unk_08685930)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_08685970)
    EvtMoveWait
    EvtTalk(MSG_BFC)
    EvtClearTalk

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08675A34
EventScr CONST_DATA EventScr_Unk_08675A34[] =
{
    EvtGotoIfNotFlag(5, FLAG_CHAPTER20XS_14)

    EvtSetFlag(FLAG_CHAPTER20XS_3)
    EvtGoto(9)

EvtLabel(5)
    EvtLoadUnits(UnitInfo_Unk_086859B0)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_086859F0)
    EvtMoveWait
    EvtTalk(MSG_BFC)
    EvtClearTalk

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08675A8C
EventScr CONST_DATA EventScr_Unk_08675A8C[] =
{
    EvtGotoIfNotFlag(5, FLAG_CHAPTER20XS_15)

    EvtSetFlag(FLAG_CHAPTER20XS_3)
    EvtGoto(9)

EvtLabel(5)
    EvtLoadUnits(UnitInfo_Unk_08685A30)
    EvtMoveWait
    EvtLoadUnits(UnitInfo_Unk_08685A70)
    EvtMoveWait
    EvtTalk(MSG_BFC)
    EvtClearTalk

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08675AE4
EventScr CONST_DATA EventScr_Unk_08675AE4[] =
{
    EvtSetBgm(SONG_27)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_BFF)
    EvtClearTalk
    EvtNoSkip
    EvtGiveItemTo(IID_MULAGIR, PID_ROY)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_9AE)
    EvtSetBgm(SONG_2B)
    EvtTalkContinue
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
