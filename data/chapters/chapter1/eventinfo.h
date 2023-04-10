#pragma once

EventListScr CONST_DATA EventListScr_Chapter1_Turn[] =
{
    EvtListTurn(0, EventScr_Chapter1_Opening, 1, 0, FACTION_BLUE)
    EvtListTurn(FLAG_CHAPTER1_TURN1, EventScr_Chapter1_FirstRedTurn, 1, 0, FACTION_RED)
    EvtListEnd
};

EventListScr CONST_DATA EventListScr_Chapter1_Talk[] =
{
    EvtListEnd
};

EventListScr CONST_DATA EventListScr_Chapter1_Tile[] =
{
    EvtListTileMapChange(FLAG_CHAPTER1_VILLAGE, EventScr_Chapter1_Village, 12, 19, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER1_VILLAGE, EVENT_NOSCRIPT, 12, 18, TILE_COMMAND_PILLAGE)
    EvtListTileMapChange(FLAG_CHAPTER1_TOPVILLAGE, EventScr_Chapter1_TopVillageDummy, 4, 9, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER1_TOPVILLAGE, EVENT_NOSCRIPT, 4, 8, TILE_COMMAND_PILLAGE)
    EvtListTile(0, EventScr_Chapter1_HouseA, 12, 15, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Chapter1_HouseB, 9, 16, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Chapter1_HouseC, 9, 19, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 5, 4, TILE_COMMAND_SEIZE)
    EvtListEnd
};

EventListScr CONST_DATA EventListScr_Chapter1_Move[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

struct ChapterEventInfo CONST_DATA ChapterEventInfo_Chapter1 =
{
    .event_list_turn = EventListScr_Chapter1_Turn,
    .event_list_talk = EventListScr_Chapter1_Talk,
    .event_list_tile = EventListScr_Chapter1_Tile,
    .event_list_move = EventListScr_Chapter1_Move,
    .units_red = UnitInfo_Chapter1_RedDummy,
    .units_blue = UnitInfo_Chapter1_BlueA,
    .event_script_victory = EventScr_Chapter1_Victory,
};
