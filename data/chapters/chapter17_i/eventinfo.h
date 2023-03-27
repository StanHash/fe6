#pragma once

// EventListScr @ 08668CB0
EventListScr CONST_DATA EventListScr_Unk_08668CB0[] =
{
    EvtListTurn(0, EventScr_Unk_08670BF0, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_08670D34, 1, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_08670D3C, 2, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_08670D44, 6, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_LoadUnits_Unk_0867F3A4, 8, 11, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_0867F3D4, 10, 15, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_0867F404, 8, 11, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867F3A4, 12, 15, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867F3D4, 8, 9, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867F404, 12, 15, FACTION_RED)
    EvtListEnd
};

// EventListScr @ 08668D2C
EventListScr CONST_DATA EventListScr_Unk_08668D2C[] =
{
    EvtListEnd
};

// EventListScr @ 08668D30
EventListScr CONST_DATA EventListScr_Unk_08668D30[] =
{
    EvtListTileMapChange(0, EventScr_Unk_08670DB4, 2, 12, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 2, 11, TILE_COMMAND_PILLAGE)
    EvtListShop(0, ShopItems_Unk_0866A93A, 6, 8, TILE_COMMAND_ARMORY)
    EvtListTile(0, EventScr_Unk_08670DFC, 8, 13, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Unk_08670E38, 8, 14, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 29, 3, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 08668D7C
EventListScr CONST_DATA EventListScr_Unk_08668D7C[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 08668D8C
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_08668D8C =
{
    .event_list_turn = EventListScr_Unk_08668CB0,
    .event_list_talk = EventListScr_Unk_08668D2C,
    .event_list_tile = EventListScr_Unk_08668D30,
    .event_list_move = EventListScr_Unk_08668D7C,
    .units_red = UnitInfo_Unk_0867F1D4,
    .units_blue = UnitInfo_Unk_0867F0E4,
    .event_script_victory = EventScr_Unk_08670E74,
};
