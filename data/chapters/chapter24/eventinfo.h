#pragma once

// EventListScr @ 086695B8
EventListScr CONST_DATA EventListScr_Unk_086695B8[] =
{
    EvtListTurn(0, EventScr_Unk_08672818, 1, 0, FACTION_BLUE)
    EvtListFunc(0, EventScr_Unk_08672874, func_fe6_0806BC5C)
    EvtListFunc(0, EventScr_Unk_08672890, func_fe6_0806BCA4)
    EvtListFunc(0, EventScr_Unk_086728AC, func_fe6_0806BCEC)
    EvtListFunc(0, EventScr_Unk_086728C8, func_fe6_0806BD34)
    EvtListFunc(0, EventScr_Unk_086728E4, func_fe6_0806BD7C)
    EvtListFunc(0, EventScr_Unk_08672900, func_fe6_0806BDC4)
    EvtListEnd
};

// EventListScr @ 08669610
EventListScr CONST_DATA EventListScr_Unk_08669610[] =
{
    EvtListEnd
};

// EventListScr @ 08669614
EventListScr CONST_DATA EventListScr_Unk_08669614[] =
{
    EvtListTile(FLAG_CHAPTER24_4, EventScr_Unk_0867291C, 18, 36, TILE_COMMAND_SEIZE)
    EvtListTile(FLAG_CHAPTER24_5, EventScr_Unk_0867296C, 7, 35, TILE_COMMAND_SEIZE)
    EvtListTile(FLAG_CHAPTER24_6, EventScr_Unk_086729BC, 5, 23, TILE_COMMAND_SEIZE)
    EvtListTile(FLAG_CHAPTER24_7, EventScr_Unk_08672A0C, 16, 21, TILE_COMMAND_SEIZE)
    EvtListTile(FLAG_CHAPTER24_8, EventScr_Unk_08672A5C, 27, 14, TILE_COMMAND_SEIZE)
    EvtListTile(FLAG_CHAPTER24_9, EventScr_Unk_08672AAC, 18, 6, TILE_COMMAND_SEIZE)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 6, 3, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 0866966C
EventListScr CONST_DATA EventListScr_Unk_0866966C[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 0866967C
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_0866967C =
{
    .event_list_turn = EventListScr_Unk_086695B8,
    .event_list_talk = EventListScr_Unk_08669610,
    .event_list_tile = EventListScr_Unk_08669614,
    .event_list_move = EventListScr_Unk_0866966C,
    .units_red = UnitInfo_Unk_086819A8,
    .units_blue = UnitInfo_Unk_086818F8,
    .event_script_victory = EventScr_Unk_08672B28,
};
