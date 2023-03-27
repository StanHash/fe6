#pragma once

// EventListScr @ 086698F4
EventListScr CONST_DATA EventListScr_Unk_086698F4[] =
{
    EvtListTurn(0, EventScr_Unk_0867389C, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_08673998, 8, 0, FACTION_GREEN)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086828F4, 5, 7, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08682924, 4, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_086739C0, 5, 0, FACTION_GREEN)
    EvtListTurn(0, EventScr_Unk_08673A24, 10, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_08673A88, 11, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_08673AD8, 13, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_08673A88, 14, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_08673AD8, 16, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_08673A88, 17, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_08673AD8, 19, 0, FACTION_RED)
    EvtListFunc(FLAG_CHAPTER11B_5, EventScr_Unk_08673B00, func_fe6_0806AD74)
    EvtListTurnHard(0, EventScr_Unk_08673AB0, 12, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_Unk_08673AB0, 15, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_Unk_08673AB0, 18, 0, FACTION_RED)
    EvtListEnd
};

// EventListScr @ 086699B8
EventListScr CONST_DATA EventListScr_Unk_086699B8[] =
{
    EvtListTalk(FLAG_CHAPTER11B_6, EventScr_Unk_08673B14, PID_ROY, PID_BARTRE)
    EvtListTalk(FLAG_CHAPTER11B_6, EventScr_Unk_0866E1A4, PID_FIR, PID_BARTRE)
    EvtListTalk(FLAG_CHAPTER11B_11, EventScr_Unk_08673B84, PID_ROY, PID_GEESE)
    EvtListTalk(FLAG_CHAPTER11B_12, EventScr_Unk_08673B48, PID_FIR, PID_BARTRE)
    EvtListTalk(FLAG_CHAPTER11B_12, EventScr_Unk_08673B48, PID_BARTRE, PID_FIR)
    EvtListEnd
};

// EventListScr @ 086699F8
EventListScr CONST_DATA EventListScr_Unk_086699F8[] =
{
    EvtListShop(0, ShopItems_Unk_0866AA64, 23, 17, TILE_COMMAND_VENDOR)
    EvtListTileMapChange(0, EventScr_Unk_08673BB0, 18, 21, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 18, 20, TILE_COMMAND_1D)
    EvtListTileMapChange(0, EventScr_Unk_08673BB0, 18, 21, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 18, 20, TILE_COMMAND_1D)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 2, 25, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 08669A44
EventListScr CONST_DATA EventListScr_Unk_08669A44[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 08669A54
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_08669A54 =
{
    .event_list_turn = EventListScr_Unk_086698F4,
    .event_list_talk = EventListScr_Unk_086699B8,
    .event_list_tile = EventListScr_Unk_086699F8,
    .event_list_move = EventListScr_Unk_08669A44,
    .units_red = UnitInfo_Unk_086826C4,
    .units_blue = UnitInfo_Unk_086825C4,
    .event_script_victory = EventScr_Unk_08673BF8,
};
