#pragma once

// EventListScr @ 0866A1A0
EventListScr CONST_DATA EventListScr_Unk_0866A1A0[] =
{
    EvtListTurn(0, EventScr_Unk_0867557C, 1, 0, FACTION_BLUE)
    EvtListEnd
};

// EventListScr @ 0866A1B0
EventListScr CONST_DATA EventListScr_Unk_0866A1B0[] =
{
    EvtListEnd
};

// EventListScr @ 0866A1B4
EventListScr CONST_DATA EventListScr_Unk_0866A1B4[] =
{
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 16, 1, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 0866A1C4
EventListScr CONST_DATA EventListScr_Unk_0866A1C4[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 0866A1D4
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_0866A1D4 =
{
    .event_list_turn = EventListScr_Unk_0866A1A0,
    .event_list_talk = EventListScr_Unk_0866A1B0,
    .event_list_tile = EventListScr_Unk_0866A1B4,
    .event_list_move = EventListScr_Unk_0866A1C4,
    .units_red = UnitInfo_Unk_086851E0,
    .units_blue = UnitInfo_Unk_08685100,
    .event_script_victory = EventScr_Unk_086756A8,
};
