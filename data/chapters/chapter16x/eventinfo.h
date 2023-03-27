#pragma once

// EventListScr @ 0866A114
EventListScr CONST_DATA EventListScr_Unk_0866A114[] =
{
    EvtListTurn(0, EventScr_Unk_08675324, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08685034, 8, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08685054, 10, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08685034, 18, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08685054, 20, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_086753E0, 25, 0, FACTION_RED)
    EvtListEnd
};

// EventListScr @ 0866A160
EventListScr CONST_DATA EventListScr_Unk_0866A160[] =
{
    EvtListEnd
};

// EventListScr @ 0866A164
EventListScr CONST_DATA EventListScr_Unk_0866A164[] =
{
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 15, 2, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 0866A174
EventListScr CONST_DATA EventListScr_Unk_0866A174[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 0866A184
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_0866A184 =
{
    .event_list_turn = EventListScr_Unk_0866A114,
    .event_list_talk = EventListScr_Unk_0866A160,
    .event_list_tile = EventListScr_Unk_0866A164,
    .event_list_move = EventListScr_Unk_0866A174,
    .units_red = UnitInfo_Unk_08684E34,
    .units_blue = UnitInfo_Unk_08684D84,
    .event_script_victory = EventScr_Unk_08675410,
};
