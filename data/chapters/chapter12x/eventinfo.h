#pragma once

// EventListScr @ 08669FE4
EventListScr CONST_DATA EventListScr_Unk_08669FE4[] =
{
    EvtListChest(0, IID_ELIXIR, 0, 12, 24, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_ANTITOXIN, 0, 3, 17, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_TORCH, 0, 7, 8, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_ANTITOXIN, 0, 18, 16, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_ELIXIR, 0, 19, 9, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_LOCKPICK, 0, 11, 4, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_REDGEM, 0, 25, 12, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_ANTITOXIN, 0, 25, 20, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_ANTITOXIN, 0, 26, 24, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_CHESTKEY, 0, 1, 3, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_ELIXIR, 0, 13, 15, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_WHITEGEM, 0, 13, 0, TILE_COMMAND_CHEST)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 25, 1, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 0866A084
EventListScr CONST_DATA EventListScr_Unk_0866A084[] =
{
    EvtListTurn(0, EventScr_Unk_08674F00, 1, 0, FACTION_BLUE)
    EvtListEnd
};

// EventListScr @ 0866A094
EventListScr CONST_DATA EventListScr_Unk_0866A094[] =
{
    EvtListEnd
};

// EventListScr @ 0866A098
EventListScr CONST_DATA EventListScr_Unk_0866A098[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 0866A0A8
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_0866A0A8 =
{
    .event_list_turn = EventListScr_Unk_0866A084,
    .event_list_talk = EventListScr_Unk_0866A094,
    .event_list_tile = EventListScr_Unk_08669FE4,
    .event_list_move = EventListScr_Unk_0866A098,
    .units_red = UnitInfo_Unk_086848B4,
    .units_blue = UnitInfo_Unk_08684824,
    .event_script_victory = EventScr_Unk_08674F84,
};
