#pragma once

EventListScr CONST_DATA EventListScr_Chapter2_Turn[] =
{
    EvtListTurn(0, EventScr_Chapter2_Opening, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Chapter2_DieckComes, 2, 0, FACTION_BLUE)
    EvtListEnd
};

EventListScr CONST_DATA EventListScr_Chapter2_Talk[] =
{
    EvtListTalk(FLAG_CHAPTER2_ROYDIECKTALK, EventScr_Chapter2_DieckTalk, PID_ROY, PID_DIECK)
    EvtListTalk(FLAG_CHAPTER2_ROYDIECKTALK, EventScr_Chapter2_DieckTalk, PID_DIECK, PID_ROY)
    EvtListEnd
};

EventListScr CONST_DATA EventListScr_Chapter2_Tile[] =
{
    EvtListShop(0, ShopItems_Chapter2_Vendor, 7, 9, TILE_COMMAND_VENDOR)
    EvtListShop(0, ShopItems_Chapter2_Armory, 6, 1, TILE_COMMAND_ARMORY)
    EvtListTileMapChange(0, EventScr_Chapter2_Village, 3, 4, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 3, 3, TILE_COMMAND_PILLAGE)
    EvtListTile(0, EventScr_Chapter2_HouseA, 6, 7, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Chapter2_HouseB, 0, 4, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Chapter2_HouseC, 5, 7, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 16, 3, TILE_COMMAND_SEIZE)
    EvtListEnd
};

EventListScr CONST_DATA EventListScr_Chapter2_Move[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

struct ChapterEventInfo CONST_DATA ChapterEventInfo_Chapter2 =
{
    .event_list_turn = EventListScr_Chapter2_Turn,
    .event_list_talk = EventListScr_Chapter2_Talk,
    .event_list_tile = EventListScr_Chapter2_Tile,
    .event_list_move = EventListScr_Chapter2_Move,
    .units_red = UnitInfo_Chapter2_RedDummy,
    .units_blue = UnitInfo_Chapter2_Blue,
    .event_script_victory = EventScr_Chapter2_Victory,
};
