#pragma once

// EventListScr @ 08669C9C
EventListScr CONST_DATA EventListScr_Unk_08669C9C[] =
{
    EvtListTurn(0, EventScr_Unk_08674358, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_086743E4, 1, 0, FACTION_GREEN)
    EvtListTurn(0, EventScr_Unk_08674430, 15, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_08674458, 7, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_086744C0, 8, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_086744F4, 12, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_08674564, 13, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08683C10, 10, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08683C10, 15, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08683C10, 20, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08683C40, 8, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08683C40, 13, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08683C40, 18, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08683C40, 23, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_08683BC0, 17, 19, FACTION_RED)
    EvtListEnd
};

// EventListScr @ 08669D54
EventListScr CONST_DATA EventListScr_Unk_08669D54[] =
{
    EvtListTalk(FLAG_CHAPTER19S_5, EventScr_Unk_086745CC, PID_SHANNA, PID_THEA)
    EvtListEnd
};

// EventListScr @ 08669D64
EventListScr CONST_DATA EventListScr_Unk_08669D64[] =
{
    EvtListTileMapChange(0, EventScr_Unk_08674604, 6, 5, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 6, 4, TILE_COMMAND_1D)
    EvtListTileMapChange(0, EventScr_Unk_0867464C, 10, 10, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 10, 9, TILE_COMMAND_1D)
    EvtListTileMapChange(0, EventScr_Unk_08674694, 15, 12, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 15, 11, TILE_COMMAND_1D)
    EvtListTileMapChange(0, EventScr_Unk_086746DC, 17, 10, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 17, 9, TILE_COMMAND_1D)
    EvtListTileMapChange(0, EventScr_Unk_08674724, 26, 3, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 26, 2, TILE_COMMAND_1D)
    EvtListShop(0, ShopItems_Unk_0866AAC4, 8, 1, TILE_COMMAND_ARMORY)
    EvtListShop(0, ShopItems_Unk_0866AAE4, 27, 0, TILE_COMMAND_VENDOR)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 16, 1, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 08669E04
EventListScr CONST_DATA EventListScr_Unk_08669E04[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 08669E14
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_08669E14 =
{
    .event_list_turn = EventListScr_Unk_08669C9C,
    .event_list_talk = EventListScr_Unk_08669D54,
    .event_list_tile = EventListScr_Unk_08669D64,
    .event_list_move = EventListScr_Unk_08669E04,
    .units_red = UnitInfo_Unk_086838F0,
    .units_blue = UnitInfo_Unk_086837F0,
    .event_script_victory = EventScr_Unk_0867476C,
};
