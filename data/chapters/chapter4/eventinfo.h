#pragma once

// EventListScr @ 0866797C
EventListScr CONST_DATA EventListScr_Unk_0866797C[] =
{
    EvtListTurn(0, EventScr_Unk_0866C308, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_0866C400, 4, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_0867A93C, 6, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_0867A93C, 8, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_0866C438, 2, 0, FACTION_GREEN)
    EvtListTurn(0, EventScr_Unk_0866C484, 3, 0, FACTION_GREEN)
    EvtListTurn(0, EventScr_Unk_0866C538, 5, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_0866C4E8, 6, 0, FACTION_RED)
    EvtListFlag(FLAG_CHAPTER4_7, EventScr_Unk_0866C614, FLAG_CHAPTER4_5)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867A93C, 4, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867A93C, 6, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867A93C, 8, 10, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867A96C, 11, 0, FACTION_RED)
    EvtListEnd
};

// EventListScr @ 08667A1C
EventListScr CONST_DATA EventListScr_Unk_08667A1C[] =
{
    EvtListTalk(FLAG_CHAPTER4_5, EventScr_Unk_0866C5C8, PID_CLARINE, PID_ROY)
    EvtListTalk(FLAG_CHAPTER4_6, EventScr_Unk_0866C624, PID_CLARINE, PID_RUTGER)
    EvtListEnd
};

// EventListScr @ 08667A38
EventListScr CONST_DATA EventListScr_Unk_08667A38[] =
{
    EvtListShop(0, ShopItems_Unk_0866A82A, 13, 15, TILE_COMMAND_VENDOR)
    EvtListShop(0, ShopItems_Unk_0866A832, 11, 14, TILE_COMMAND_ARMORY)
    EvtListTileMapChange(FLAG_CHAPTER4_10, EventScr_Unk_0866C650, 27, 2, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER4_10, EVENT_NOSCRIPT, 27, 1, TILE_COMMAND_1D)
    EvtListTileMapChange(FLAG_CHAPTER4_9, EventScr_Unk_0866C698, 11, 4, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER4_9, EVENT_NOSCRIPT, 11, 3, TILE_COMMAND_1D)
    EvtListTileMapChange(FLAG_CHAPTER4_8, EventScr_Unk_0866C6E0, 8, 15, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER4_8, EVENT_NOSCRIPT, 8, 14, TILE_COMMAND_1D)
    EvtListTile(0, EventScr_Unk_0866C728, 24, 1, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Unk_0866C764, 13, 3, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Unk_0866C7A0, 9, 5, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 3, 8, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 08667ACC
EventListScr CONST_DATA EventListScr_Unk_08667ACC[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 08667ADC
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_08667ADC =
{
    .event_list_turn = EventListScr_Unk_0866797C,
    .event_list_talk = EventListScr_Unk_08667A1C,
    .event_list_tile = EventListScr_Unk_08667A38,
    .event_list_move = EventListScr_Unk_08667ACC,
    .units_red = UnitInfo_Unk_0867A7FC,
    .units_blue = UnitInfo_Unk_0867A70C,
    .event_script_victory = EventScr_Unk_0866C7DC,
};
