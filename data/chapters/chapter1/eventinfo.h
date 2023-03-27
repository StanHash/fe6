#pragma once

// EventListScr @ 0866770C
EventListScr CONST_DATA EventListScr_Unk_0866770C[] =
{
    EvtListTurn(0, EventScr_Unk_0866B5F8, 1, 0, FACTION_BLUE)
    EvtListTurn(FLAG_CHAPTER1_4, EventScr_Unk_0866B79C, 1, 0, FACTION_RED)
    EvtListEnd
};

// EventListScr @ 08667728
EventListScr CONST_DATA EventListScr_Unk_08667728[] =
{
    EvtListEnd
};

// EventListScr @ 0866772C
EventListScr CONST_DATA EventListScr_Unk_0866772C[] =
{
    EvtListTileMapChange(FLAG_CHAPTER1_6, EventScr_Unk_0866B7F8, 12, 19, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER1_6, EVENT_NOSCRIPT, 12, 18, TILE_COMMAND_1D)
    EvtListTileMapChange(FLAG_CHAPTER1_7, EventScr_Unk_0866B840, 4, 9, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER1_7, EVENT_NOSCRIPT, 4, 8, TILE_COMMAND_1D)
    EvtListTile(0, EventScr_Unk_0866B854, 12, 15, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Unk_0866B890, 9, 16, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Unk_0866B8CC, 9, 19, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 5, 4, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 08667790
EventListScr CONST_DATA EventListScr_Unk_08667790[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 086677A0
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_086677A0 =
{
    .event_list_turn = EventListScr_Unk_0866770C,
    .event_list_talk = EventListScr_Unk_08667728,
    .event_list_tile = EventListScr_Unk_0866772C,
    .event_list_move = EventListScr_Unk_08667790,
    .units_red = UnitInfo_Unk_08679BD0,
    .units_blue = UnitInfo_Unk_08679B40,
    .event_script_victory = EventScr_Unk_0866B944,
};
