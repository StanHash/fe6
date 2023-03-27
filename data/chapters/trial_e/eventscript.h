#pragma once

// EventScr @ 0867614C
EventScr CONST_DATA EventScr_TrialE_Opening[] =
{
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08676154
EventScr CONST_DATA EventScr_TrialE_Victory[] =
{
    EvtSleep(64)
    EvtNextChapter(CHAPTER_TRIAL_E)
    EvtSleep(1)
    EvtKill
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08676178
EventScr CONST_DATA EventScr_TrialE_Failure[] =
{
    EvtSleep(64)
    EvtNextChapter(0)
    EvtSleep(1)
    EvtKill
    EvtClearSkip
    EvtEnd
};
