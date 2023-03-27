#pragma once

struct UnkTrapEnt CONST_DATA gUnk_0867507C[26] =
{
    {  1,  6 },
    {  5,  6 },
    {  2,  6 },
    {  3,  6 },
    {  6,  6 },
    {  4,  5 },
    {  4,  5 },
    {  6,  5 },
    {  7,  5 },
    {  5,  5 },
    {  8,  5 },
    {  6, 20 },
    {  7, 20 },
    {  8, 20 },
    {  9, 20 },
    { 10, 20 },
    {  3,  3 },
    {  4,  3 },
    {  5,  3 },
    {  8,  4 },
    {  9,  4 },
    { 10,  4 },
    { 11,  4 },
    { 10,  4 },
    { 11,  4 },
    { 12,  4 },
};

// EventScr @ 0867514C
EventScr CONST_DATA EventScr_Unk_0867514C[] =
{
    EvtFunc(func_fe6_0806D620)
    EvtCameraUnit(PID_UNKNOWN_B9)
    EvtFlashCursorUnit(PID_UNKNOWN_B9)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_13)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_BDF)
    EvtClearTalk
    EvtSetBgm(SONG_26)
    EvtLoadUnitsParty(UnitInfo_Unk_08684A94)
    EvtMoveWait
    EvtCameraUnit(PID_ROY)
    EvtFlashCursorUnit(PID_ROY)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_13)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_BE0)
    EvtClearTalk
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086751E8
EventScr CONST_DATA EventScr_Unk_086751E8[] =
{
    EvtSetBgm(SONG_26)
    EvtGotoIfNotFunc(5, func_fe6_0806C224)

    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_3)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_BE3)
    EvtClearTalk
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_8)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_143)
    EvtClearTalk
    EvtGoto(9)

EvtLabel(5)
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_3)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_BE4)
    EvtClearTalk
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_7)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_BE5)
    EvtClearTalk
    EvtFadeToBlack(16)
    EvtExitMap
    EvtBackground(BACKGROUND_8)
    EvtFadeFromBlack(16)
    EvtEnterMap
    EvtTalk(MSG_143)
    EvtClearTalk

EvtLabel(9)
    EvtNoSkip
    EvtGiveItemTo(IID_FORBLAZE, PID_ROY)
    EvtSleep(64)
    EvtNextChapter(CHAPTER_15)
    EvtSleep(1)
    EvtKill
    EvtClearSkip
    EvtEnd
};
