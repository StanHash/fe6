#pragma once

EventListScr CONST_DATA EventListScr_Chapter5_Turn[] =
{
    EvtListTurn(0, EventScr_Chapter5_Opening, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_LoadUnits_Chapter5_BackFortBrigands, 12, 15, FACTION_RED)
    EvtListTurn(FLAG_CHAPTER5_4, EventScr_Chapter5_SaulDorothyScene, 1, 0, FACTION_GREEN)
    EvtListTurnHard(0, EventScr_LoadUnits_Chapter5_BackFortBrigands, 16, 18, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Chapter5_FrontFortBrigands, 15, 20, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Chapter5_FrontFortBrigands, 15, 20, FACTION_RED)
    EvtListEnd
};

EventListScr CONST_DATA EventListScr_Chapter5_Talk[] =
{
    EvtListEnd
};

EventListScr CONST_DATA EventListScr_Chapter5_Tile[] =
{
    EvtListShop(0, ShopItems_Chapter5_Vendor, 7, 2, TILE_COMMAND_VENDOR)
    EvtListTileMapChange(FLAG_CHAPTER5_VILLAGE, EventScr_Chapter5_Village, 10, 2, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER5_VILLAGE, EVENT_NOSCRIPT, 10, 1, TILE_COMMAND_PILLAGE)
    EvtListTile(0, EventScr_Chapter5_HouseA, 11, 20, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Chapter5_HouseB, 12, 20, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Chapter5_HouseC, 8, 19, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 2, 14, TILE_COMMAND_SEIZE)
    EvtListEnd
};

EventListScr CONST_DATA EventListScr_Chapter5_Move[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListArea(FLAG_CHAPTER5_BARRIER, EventScr_Chapter5_OpenBarrier, 7, 16, 7, 17)
    EvtListEnd
};

struct ChapterEventInfo CONST_DATA ChapterEventInfo_Chapter5 =
{
    .event_list_turn = EventListScr_Chapter5_Turn,
    .event_list_talk = EventListScr_Chapter5_Talk,
    .event_list_tile = EventListScr_Chapter5_Tile,
    .event_list_move = EventListScr_Chapter5_Move,
    .units_red = UnitInfo_Chapter5_Red,
    .units_blue = UnitInfo_Chapter5_Blue,
    .event_script_victory = EventScr_Chapter5_Victory,
};
