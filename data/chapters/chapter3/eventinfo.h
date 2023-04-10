#pragma once

EventListScr CONST_DATA EventListScr_Chapter3_Turn[] =
{
    EvtListTurn(0, EventScr_Chapter3_Opening, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Chapter3_ZephielScene, 3, 0, FACTION_RED)
    EvtListFlag(FLAG_CHAPTER3_CAVALIERSPOSTLUGH, EventScr_LoadUnits_Chapter3_CavalierReinforcements, FLAG_CHAPTER3_GOTLUGH)
    EvtListTurn(FLAG_CHAPTER3_ORPHANAGECUTSCENE, EventScr_Chapter3_OrphanageCutscene, 2, 0, FACTION_BLUE)
    EvtListTurnHard(0, EventScr_LoadUnits_Chapter3_CavalierReinforcements, 5, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Chapter3_CavalierReinforcements, 10, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Chapter3_CavalierReinforcements, 15, 0, FACTION_RED)
    EvtListEnd
};

EventListScr CONST_DATA EventListScr_Chapter3_Talk[] =
{
    EvtListTalk(FLAG_CHAPTER3_CHADLUGHTALK, EventScr_Chapter3_ChadLughTalk, PID_CHAD, PID_LUGH)
    EvtListTalk(FLAG_CHAPTER3_CHADLUGHTALK, EventScr_Chapter3_ChadLughTalk, PID_LUGH, PID_CHAD)
    EvtListEnd
};

EventListScr CONST_DATA EventListScr_Chapter3_Tile[] =
{
    EvtListTileMapChange(FLAG_CHAPTER3_GOTLUGH, EventScr_Chapter3_TopVillage, 3, 3, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER3_GOTLUGH, EVENT_NOSCRIPT, 3, 2, TILE_COMMAND_PILLAGE)
    EvtListTileMapChange(0, EventScr_Chapter3_BottomVillage, 19, 19, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 19, 18, TILE_COMMAND_PILLAGE)
    EvtListChest(0, IID_HALBERD, 0, 20, 11, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_GOLD, 3000, 22, 12, TILE_COMMAND_CHEST)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 19, 4, TILE_COMMAND_SEIZE)
    EvtListEnd
};

EventListScr CONST_DATA EventListScr_Chapter3_Move[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

struct ChapterEventInfo CONST_DATA ChapterEventInfo_Chapter3 =
{
    .event_list_turn = EventListScr_Chapter3_Turn,
    .event_list_talk = EventListScr_Chapter3_Talk,
    .event_list_tile = EventListScr_Chapter3_Tile,
    .event_list_move = EventListScr_Chapter3_Move,
    .units_red = UnitInfo_Chapter3_Red,
    .units_blue = UnitInfo_Chapter3_Blue,
    .event_script_victory = EventScr_Chapter3_Victory,
};
