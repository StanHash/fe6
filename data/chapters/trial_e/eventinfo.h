#pragma once

// EventListScr @ 0866A778
EventListScr CONST_DATA EventListScr_TrialE_Turn[] =
{
    EvtListTurn(0, EventScr_TrialE_Opening, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_LoadUnits_TrialE_Turn10Extra, 10, 22, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_TrialE_Turn12Extra, 12, 24, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_TrialE_Turn14Extra, 14, 26, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_TrialE_Turn16Extra, 16, 28, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_TrialE_Turn18Extra, 18, 30, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_TrialE_Turn20Extra, 20, 32, FACTION_RED)
    EvtListEnd
};

// EventListScr @ 0866A7D0
EventListScr CONST_DATA EventListScr_TrialE_Talk[] =
{
    EvtListEnd
};

// EventListScr @ 0866A7D4
EventListScr CONST_DATA EventListScr_TrialE_Tile[] =
{
    EvtListEnd
};

// EventListScr @ 0866A7D8
EventListScr CONST_DATA EventListScr_TrialE_Move[] =
{
    EvtListFunc(FLAG_3, EventScr_TrialE_Victory, func_fe6_0806C2F8)
    EvtListFlag(FLAG_3, EventScr_TrialE_Failure, FLAG_101)
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 0866A800
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_0866A800 =
{
    .event_list_turn = EventListScr_TrialE_Turn,
    .event_list_talk = EventListScr_TrialE_Talk,
    .event_list_tile = EventListScr_TrialE_Tile,
    .event_list_move = EventListScr_TrialE_Move,
    .units_red = UnitInfo_TrialE_Red,
    .units_blue = UnitInfo_TrialE_Deploy,
    .event_script_victory = EventScr_TrialE_Victory,
};
