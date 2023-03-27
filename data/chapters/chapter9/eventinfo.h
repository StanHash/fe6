#pragma once

// EventListScr @ 08668148
EventListScr CONST_DATA EventListScr_Unk_08668148[] =
{
    EvtListTurn(0, EventScr_Unk_0866DB60, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_LoadUnits_Unk_0867C664, 12, 20, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_0866DC2C, 2, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_0866DCF0, 5, 0, FACTION_RED)
    EvtListEnd
};

// EventListScr @ 0866817C
EventListScr CONST_DATA EventListScr_Unk_0866817C[] =
{
    EvtListTalk(FLAG_CHAPTER9_5, EventScr_Unk_0866DD04, PID_NOAH, PID_FIR)
    EvtListTalk(FLAG_CHAPTER9_6, EventScr_Unk_0866DD30, PID_SUE, PID_SIN)
    EvtListEnd
};

// EventListScr @ 08668198
EventListScr CONST_DATA EventListScr_Unk_08668198[] =
{
    EvtListTileMapChange(FLAG_CHAPTER9_8, EventScr_Unk_0866DDF4, 18, 2, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER9_8, EVENT_NOSCRIPT, 18, 1, TILE_COMMAND_1D)
    EvtListTileMapChange(FLAG_CHAPTER9_7, EventScr_Unk_0866DDA4, 21, 2, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER9_7, EVENT_NOSCRIPT, 21, 1, TILE_COMMAND_1D)
    EvtListTileMapChange(0, EventScr_Unk_0866DD5C, 2, 24, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 2, 23, TILE_COMMAND_1D)
    EvtListShop(0, ShopItems_Unk_0866A87C, 23, 4, TILE_COMMAND_ARMORY)
    EvtListShop(0, ShopItems_Unk_0866A890, 21, 6, TILE_COMMAND_VENDOR)
    EvtListTile(0, EventScr_Unk_0866DE44, 1, 20, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Unk_0866DE80, 19, 22, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Unk_0866DEBC, 18, 13, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Unk_0866DEF8, 16, 1, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 2, 3, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 08668238
EventListScr CONST_DATA EventListScr_Unk_08668238[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 08668248
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_08668248 =
{
    .event_list_turn = EventListScr_Unk_08668148,
    .event_list_talk = EventListScr_Unk_0866817C,
    .event_list_tile = EventListScr_Unk_08668198,
    .event_list_move = EventListScr_Unk_08668238,
    .units_red = UnitInfo_Unk_0867C484,
    .units_blue = UnitInfo_Unk_0867C3A4,
    .event_script_victory = EventScr_Unk_0866DF34,
};
