#pragma once

EventListScr CONST_DATA EventListScr_Chapter4_Turn[] =
{
    EvtListTurn(0, EventScr_Chapter4_Opening, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Chapter4_IntroducePirates, 4, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Chapter4_Pirates, 6, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Chapter4_Pirates, 8, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Chapter4_ForeshadowClarine, 2, 0, FACTION_GREEN)
    EvtListTurn(0, EventScr_Chapter4_ClarineComes, 3, 0, FACTION_GREEN)
    EvtListTurn(0, EventScr_Chapter4_ForeshadowRutger, 5, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Chapter4_RutgerComes, 6, 0, FACTION_RED)
    EvtListFlag(FLAG_CHAPTER4_REFRESHCLARINE, EventScr_Chapter4_RefreshClarine, FLAG_CHAPTER4_CLARINE)
    EvtListTurnHard(0, EventScr_LoadUnits_Chapter4_Pirates, 4, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Chapter4_Pirates, 6, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Chapter4_Pirates, 8, 10, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Chapter4_CavalierReinforcements, 11, 0, FACTION_RED)
    EvtListEnd
};

EventListScr CONST_DATA EventListScr_Chapter4_Talk[] =
{
    EvtListTalk(FLAG_CHAPTER4_CLARINE, EventScr_Chapter4_RecruitClarine, PID_CLARINE, PID_ROY)
    EvtListTalk(FLAG_CHAPTER4_RUTGER, EventScr_Chapter4_RecruitRutger, PID_CLARINE, PID_RUTGER)
    EvtListEnd
};

EventListScr CONST_DATA EventListScr_Chapter4_Tile[] =
{
    EvtListShop(0, ShopItems_Chapter4_Vendor, 13, 15, TILE_COMMAND_VENDOR)
    EvtListShop(0, ShopItems_Chapter4_Armory, 11, 14, TILE_COMMAND_ARMORY)
    EvtListTileMapChange(FLAG_CHAPTER4_VILLAGEC, EventScr_Chapter4_TopRightVillage, 27, 2, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER4_VILLAGEC, EVENT_NOSCRIPT, 27, 1, TILE_COMMAND_PILLAGE)
    EvtListTileMapChange(FLAG_CHAPTER4_VILLAGEB, EventScr_Chapter4_NorthVillage, 11, 4, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER4_VILLAGEB, EVENT_NOSCRIPT, 11, 3, TILE_COMMAND_PILLAGE)
    EvtListTileMapChange(FLAG_CHAPTER4_VILLAGEA, EventScr_Chapter4_SouthVillage, 8, 15, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER4_VILLAGEA, EVENT_NOSCRIPT, 8, 14, TILE_COMMAND_PILLAGE)
    EvtListTile(0, EventScr_Chapter4_HouseA, 24, 1, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Chapter4_HouseB, 13, 3, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Chapter4_HouseC, 9, 5, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 3, 8, TILE_COMMAND_SEIZE)
    EvtListEnd
};

EventListScr CONST_DATA EventListScr_Chapter4_Move[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

struct ChapterEventInfo CONST_DATA ChapterEventInfo_Chapter4 =
{
    .event_list_turn = EventListScr_Chapter4_Turn,
    .event_list_talk = EventListScr_Chapter4_Talk,
    .event_list_tile = EventListScr_Chapter4_Tile,
    .event_list_move = EventListScr_Chapter4_Move,
    .units_red = UnitInfo_Chapter4_NarcianOnly,
    .units_blue = UnitInfo_Chapter4_Blue,
    .event_script_victory = EventScr_Chapter4_Victory,
};
