#pragma once

// EventListScr @ 08668F48
EventListScr CONST_DATA EventListScr_Unk_08668F48[] =
{
    EvtListTurn(0, EventScr_Unk_08671340, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_086713D4, 13, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_0867FDB8, 11, 15, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_08671434, 16, 20, FACTION_RED)
    EvtListEnd
};

// EventListScr @ 08668F7C
EventListScr CONST_DATA EventListScr_Unk_08668F7C[] =
{
    EvtListEnd
};

// EventListScr @ 08668F80
EventListScr CONST_DATA EventListScr_Unk_08668F80[] =
{
    EvtListTileMapChange(0, EventScr_Unk_08671460, 10, 14, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 10, 13, TILE_COMMAND_PILLAGE)
    EvtListTileMapChange(0, EventScr_Unk_086714A8, 29, 14, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 29, 13, TILE_COMMAND_PILLAGE)
    EvtListShop(0, ShopItems_Unk_0866A956, 4, 18, TILE_COMMAND_VENDOR)
    EvtListTile(0, EventScr_Unk_086715A4, 1, 19, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Unk_08671568, 3, 17, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Unk_0867152C, 1, 14, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Unk_086714F0, 3, 11, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 28, 3, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 08668FFC
EventListScr CONST_DATA EventListScr_Unk_08668FFC[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 0866900C
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_0866900C =
{
    .event_list_turn = EventListScr_Unk_08668F48,
    .event_list_talk = EventListScr_Unk_08668F7C,
    .event_list_tile = EventListScr_Unk_08668F80,
    .event_list_move = EventListScr_Unk_08668FFC,
    .units_red = UnitInfo_Unk_0867FB58,
    .units_blue = UnitInfo_Unk_0867FA58,
    .event_script_victory = EventScr_Unk_086715E0,
};
