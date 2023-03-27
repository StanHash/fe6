#pragma once

// EventScr @ 08676080
EventScr CONST_DATA EventScr_Unk_08676080[] =
{
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08676088
EventScr CONST_DATA EventScr_Unk_08676088[] =
{
    EvtSleep(64)
    EvtNextChapter(CHAPTER_TRIAL_C)
    EvtSleep(1)
    EvtKill
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086760AC
EventScr CONST_DATA EventScr_Unk_086760AC[] =
{
    EvtGotoIfFunc(3, func_fe6_0806C4EC)

    EvtClearFlag(FLAG_3)
    EvtGoto(9)

EvtLabel(3)
    EvtSleep(64)
    EvtNextChapter(0)
    EvtSleep(1)
    EvtKill

EvtLabel(9)
    EvtClearSkip
    EvtEnd
};
