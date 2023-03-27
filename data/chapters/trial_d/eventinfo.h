#pragma once

// EventListScr @ 0866A680
EventListScr CONST_DATA EventListScr_Unk_0866A680[] =
{
    EvtListTurn(0, EventScr_Unk_086760FC, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08687184, 3, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08687184, 6, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08687184, 9, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08687184, 12, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08687204, 4, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08687204, 7, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08687204, 10, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08687204, 13, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08687274, 5, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08687274, 8, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08687274, 11, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08687274, 14, 0, FACTION_RED)
    EvtListEnd
};

// EventListScr @ 0866A720
EventListScr CONST_DATA EventListScr_Unk_0866A720[] =
{
    EvtListEnd
};

// EventListScr @ 0866A724
EventListScr CONST_DATA EventListScr_Unk_0866A724[] =
{
    EvtListEnd
};

// EventListScr @ 0866A728
EventListScr CONST_DATA EventListScr_Unk_0866A728[] =
{
    EvtListFunc(FLAG_FIRST_CHAPTER, EventScr_LoadUnits_Unk_086872E4, func_fe6_0806C2F8)
    EvtListFunc(FLAG_3, EventScr_Unk_08676104, func_fe6_0806BF14)
    EvtListFlag(FLAG_3, EventScr_Unk_08676128, FLAG_101)
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 0866A75C
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_0866A75C =
{
    .event_list_turn = EventListScr_Unk_0866A680,
    .event_list_talk = EventListScr_Unk_0866A720,
    .event_list_tile = EventListScr_Unk_0866A724,
    .event_list_move = EventListScr_Unk_0866A728,
    .units_red = UnitInfo_Unk_08686FD4,
    .units_blue = UnitInfo_Unk_08686F24,
    .event_script_victory = EventScr_Unk_08676104,
};
