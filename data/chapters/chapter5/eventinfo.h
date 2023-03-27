#pragma once

// EventListScr @ 08667AF8
EventListScr CONST_DATA EventListScr_Unk_08667AF8[] =
{
    EvtListTurn(0, EventScr_Unk_0866C840, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_LoadUnits_Unk_0867ADE8, 12, 15, FACTION_RED)
    EvtListTurn(FLAG_CHAPTER5_4, EventScr_Unk_0866C8C0, 1, 0, FACTION_GREEN)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867ADE8, 16, 18, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867AE68, 15, 20, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867AE68, 15, 20, FACTION_RED)
    EvtListEnd
};

// EventListScr @ 08667B44
EventListScr CONST_DATA EventListScr_Unk_08667B44[] =
{
    EvtListEnd
};

// EventListScr @ 08667B48
EventListScr CONST_DATA EventListScr_Unk_08667B48[] =
{
    EvtListShop(0, ShopItems_Unk_0866A844, 7, 2, TILE_COMMAND_VENDOR)
    EvtListTileMapChange(FLAG_CHAPTER5_7, EventScr_Unk_0866C9DC, 10, 2, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER5_7, EVENT_NOSCRIPT, 10, 1, TILE_COMMAND_1D)
    EvtListTile(0, EventScr_Unk_0866CA24, 11, 20, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Unk_0866CA60, 12, 20, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Unk_0866CA9C, 8, 19, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 2, 14, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 08667BA0
EventListScr CONST_DATA EventListScr_Unk_08667BA0[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListArea(FLAG_CHAPTER5_5, EventScr_Unk_0866C948, 7, 16, 7, 17)
    EvtListEnd
};

// ChapterEventInfo @ 08667BBC
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_08667BBC =
{
    .event_list_turn = EventListScr_Unk_08667AF8,
    .event_list_talk = EventListScr_Unk_08667B44,
    .event_list_tile = EventListScr_Unk_08667B48,
    .event_list_move = EventListScr_Unk_08667BA0,
    .units_red = UnitInfo_Unk_0867AC58,
    .units_blue = UnitInfo_Unk_0867AB48,
    .event_script_victory = EventScr_Unk_0866CAD8,
};
