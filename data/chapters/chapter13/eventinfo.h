#pragma once

// EventListScr @ 08668744
EventListScr CONST_DATA EventListScr_Unk_08668744[] =
{
    EvtListTurn(0, EventScr_Unk_0866F2C4, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_0866F3B0, 1, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_0866F428, 1, 0, FACTION_GREEN)
    EvtListTurn(0, EventScr_Unk_0866F454, 2, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_0866F4A4, 2, 0, FACTION_RED)
    EvtListTurn(FLAG_CHAPTER13_5, EventScr_Unk_0866F5A8, 2, 0, FACTION_GREEN)
    EvtListTurn(0, EventScr_Unk_0866F628, 3, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_0866F6C4, 3, 0, FACTION_GREEN)
    EvtListTurn(0, EventScr_Unk_0866F888, 8, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_0866F7B0, 8, 0, FACTION_GREEN)
    EvtListTurn(0, EventScr_Unk_0866F8A8, 12, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867DDA4, 15, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867DDF4, 15, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867DE34, 18, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867DE84, 18, 0, FACTION_RED)
    EvtListEnd
};

// EventListScr @ 086687FC
EventListScr CONST_DATA EventListScr_Unk_086687FC[] =
{
    EvtListTalk(FLAG_CHAPTER13_10, EventScr_Unk_0866F8C8, PID_ELFFIN, PID_PERCEVAL)
    EvtListTalk(FLAG_CHAPTER13_10, EventScr_Unk_0866F944, PID_LARUM, PID_PERCEVAL)
    EvtListEnd
};

// EventListScr @ 08668818
EventListScr CONST_DATA EventListScr_Unk_08668818[] =
{
    EvtListShop(0, ShopItems_Unk_0866A8CA, 41, 5, TILE_COMMAND_ARMORY)
    EvtListShop(0, ShopItems_Unk_0866A8E0, 43, 4, TILE_COMMAND_VENDOR)
    EvtListTileMapChange(0, EventScr_Unk_0866F9C0, 7, 6, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 7, 5, TILE_COMMAND_1D)
    EvtListTileMapChange(0, EventScr_Unk_0866FA08, 38, 18, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 38, 17, TILE_COMMAND_1D)
    EvtListTile(0, EventScr_Unk_0866FA50, 10, 6, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Unk_0866FA8C, 38, 6, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Unk_0866FAC8, 41, 19, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 43, 9, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 08668894
EventListScr CONST_DATA EventListScr_Unk_08668894[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListFunc(FLAG_CHAPTER13_6, EventScr_Unk_0866F710, func_fe6_0806BBD0)
    EvtListEnd
};

// ChapterEventInfo @ 086688B0
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_086688B0 =
{
    .event_list_turn = EventListScr_Unk_08668744,
    .event_list_talk = EventListScr_Unk_086687FC,
    .event_list_tile = EventListScr_Unk_08668818,
    .event_list_move = EventListScr_Unk_08668894,
    .units_red = UnitInfo_Unk_0867DB04,
    .units_blue = UnitInfo_Unk_0867DA14,
    .event_script_victory = EventScr_Unk_0866FB04,
};
