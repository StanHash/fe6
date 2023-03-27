#pragma once

// EventListScr @ 0866A27C
EventListScr CONST_DATA EventListScr_Unk_0866A27C[] =
{
    EvtListTurn(0, EventScr_Unk_08675BA8, 1, 0, FACTION_BLUE)
    EvtListEnd
};

// EventListScr @ 0866A28C
EventListScr CONST_DATA EventListScr_Unk_0866A28C[] =
{
    EvtListEnd
};

// EventListScr @ 0866A290
EventListScr CONST_DATA EventListScr_Unk_0866A290[] =
{
    EvtListTile(0, EventScr_Unk_08675CF4, 3, 1, TILE_COMMAND_CHEST)
    EvtListTile(0, EventScr_Unk_08675D38, 6, 1, TILE_COMMAND_CHEST)
    EvtListTile(0, EventScr_Unk_08675D7C, 14, 12, TILE_COMMAND_CHEST)
    EvtListTile(0, EventScr_Unk_08675DC0, 16, 12, TILE_COMMAND_CHEST)
    EvtListTile(0, EventScr_Unk_08675E04, 25, 1, TILE_COMMAND_CHEST)
    EvtListTile(0, EventScr_Unk_08675E48, 29, 1, TILE_COMMAND_CHEST)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 15, 1, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 0866A2E8
EventListScr CONST_DATA EventListScr_Unk_0866A2E8[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 0866A2F8
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_0866A2F8 =
{
    .event_list_turn = EventListScr_Unk_0866A27C,
    .event_list_talk = EventListScr_Unk_0866A28C,
    .event_list_tile = EventListScr_Unk_0866A290,
    .event_list_move = EventListScr_Unk_0866A2E8,
    .units_red = UnitInfo_Unk_08685C70,
    .units_blue = UnitInfo_Unk_08685BC0,
    .event_script_victory = EventScr_Unk_08675E8C,
};
