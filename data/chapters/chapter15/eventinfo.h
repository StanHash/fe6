#pragma once

// EventListScr @ 08668A18
EventListScr CONST_DATA EventListScr_Unk_08668A18[] =
{
    EvtListTurn(0, EventScr_Unk_08670108, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_0867023C, 3, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_0867026C, 10, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_086702D4, 12, 15, FACTION_RED)
    EvtListEnd
};

// EventListScr @ 08668A4C
EventListScr CONST_DATA EventListScr_Unk_08668A4C[] =
{
    EvtListTalk(FLAG_CHAPTER15_5, EventScr_Unk_086702FC, PID_ELFFIN, PID_PERCEVAL)
    EvtListTalk(FLAG_CHAPTER15_5, EventScr_Unk_08670348, PID_LARUM, PID_PERCEVAL)
    EvtListTalk(FLAG_CHAPTER15_7, EventScr_Unk_08670394, PID_LILINA, PID_GARRET)
    EvtListFunc(FLAG_CHAPTER15_8, EventScr_Unk_086703C0, func_fe6_0806BC20)
    EvtListEnd
};

// EventListScr @ 08668A80
EventListScr CONST_DATA EventListScr_Unk_08668A80[] =
{
    EvtListTileMapChange(0, EventScr_Unk_086703DC, 8, 22, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 8, 21, TILE_COMMAND_PILLAGE)
    EvtListTileMapChange(0, EventScr_Unk_08670424, 25, 15, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 25, 14, TILE_COMMAND_PILLAGE)
    EvtListShop(0, ShopItems_Unk_0866A918, 26, 17, TILE_COMMAND_VENDOR)
    EvtListTile(0, EventScr_Unk_0867046C, 19, 23, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Unk_086704A8, 23, 19, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 16, 9, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 08668AE4
EventListScr CONST_DATA EventListScr_Unk_08668AE4[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 08668AF4
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_08668AF4 =
{
    .event_list_turn = EventListScr_Unk_08668A18,
    .event_list_talk = EventListScr_Unk_08668A4C,
    .event_list_tile = EventListScr_Unk_08668A80,
    .event_list_move = EventListScr_Unk_08668AE4,
    .units_red = UnitInfo_Unk_0867E800,
    .units_blue = UnitInfo_Unk_0867E710,
    .event_script_victory = EventScr_Unk_086704E4,
};
