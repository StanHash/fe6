#pragma once

// EventListScr @ 08668DA8
EventListScr CONST_DATA EventListScr_Unk_08668DA8[] =
{
    EvtListTurn(0, EventScr_Unk_08670ECC, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_08670F64, 7, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_0867F95C, 10, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_0867F95C, 12, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_0867F95C, 14, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_0867F95C, 16, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_0867F98C, 11, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_0867F98C, 13, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_0867F98C, 15, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_0867F98C, 17, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_0867F9BC, 5, 9, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867F95C, 11, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867F95C, 13, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867F95C, 15, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867F95C, 17, 20, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867F98C, 12, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867F98C, 14, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867F98C, 16, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867F98C, 18, 20, FACTION_RED)
    EvtListEnd
};

// EventListScr @ 08668E90
EventListScr CONST_DATA EventListScr_Unk_08668E90[] =
{
    EvtListEnd
};

// EventListScr @ 08668E94
EventListScr CONST_DATA EventListScr_Unk_08668E94[] =
{
    EvtListTileMapChange(0, EventScr_Unk_08671114, 2, 4, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 2, 3, TILE_COMMAND_PILLAGE)
    EvtListTileMapChange(0, EventScr_Unk_0867115C, 20, 9, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 20, 8, TILE_COMMAND_PILLAGE)
    EvtListTileMapChange(0, EventScr_Unk_086711A4, 18, 24, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 18, 23, TILE_COMMAND_PILLAGE)
    EvtListTile(0, EventScr_Unk_086711EC, 3, 22, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Unk_08671228, 8, 23, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Unk_08671264, 4, 20, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Unk_086712A0, 7, 17, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 19, 3, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 08668F1C
EventListScr CONST_DATA EventListScr_Unk_08668F1C[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 08668F2C
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_08668F2C =
{
    .event_list_turn = EventListScr_Unk_08668DA8,
    .event_list_talk = EventListScr_Unk_08668E90,
    .event_list_tile = EventListScr_Unk_08668E94,
    .event_list_move = EventListScr_Unk_08668F1C,
    .units_red = UnitInfo_Unk_0867F74C,
    .units_blue = UnitInfo_Unk_0867F64C,
    .event_script_victory = EventScr_Unk_086712DC,
};
