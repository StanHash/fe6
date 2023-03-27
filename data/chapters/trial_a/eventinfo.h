#pragma once

// EventListScr @ 0866A314
EventListScr CONST_DATA EventListScr_Unk_0866A314[] =
{
    EvtListTurn(0, EventScr_Unk_08675FF0, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686318, 5, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686358, 10, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686398, 15, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086863D8, 20, 0, FACTION_RED)
    EvtListEnd
};

// EventListScr @ 0866A354
EventListScr CONST_DATA EventListScr_Unk_0866A354[] =
{
    EvtListEnd
};

// EventListScr @ 0866A358
EventListScr CONST_DATA EventListScr_Unk_0866A358[] =
{
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 2, 3, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 0866A368
EventListScr CONST_DATA EventListScr_Unk_0866A368[] =
{
    EvtListFlag(FLAG_3, EventScr_Unk_08676014, FLAG_101)
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 0866A384
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_0866A384 =
{
    .event_list_turn = EventListScr_Unk_0866A314,
    .event_list_talk = EventListScr_Unk_0866A354,
    .event_list_tile = EventListScr_Unk_0866A358,
    .event_list_move = EventListScr_Unk_0866A368,
    .units_red = UnitInfo_Unk_08686168,
    .units_blue = UnitInfo_Unk_086860B8,
    .event_script_victory = EventScr_Unk_08675FF8,
};
