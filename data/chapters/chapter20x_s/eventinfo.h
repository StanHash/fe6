#pragma once

// EventListScr @ 0866A1F0
EventListScr CONST_DATA EventListScr_Unk_0866A1F0[] =
{
    EvtListTurn(0, EventScr_Unk_08675768, 1, 0, FACTION_BLUE)
    EvtListEnd
};

// EventListScr @ 0866A200
EventListScr CONST_DATA EventListScr_Unk_0866A200[] =
{
    EvtListEnd
};

// EventListScr @ 0866A204
EventListScr CONST_DATA EventListScr_Unk_0866A204[] =
{
    EvtListTile(FLAG_CHAPTER20XS_4, EventScr_Unk_086758D4, 3, 10, TILE_COMMAND_SEIZE)
    EvtListTile(FLAG_CHAPTER20XS_5, EventScr_Unk_0867592C, 8, 14, TILE_COMMAND_SEIZE)
    EvtListTile(FLAG_CHAPTER20XS_6, EventScr_Unk_08675984, 3, 24, TILE_COMMAND_SEIZE)
    EvtListTile(FLAG_CHAPTER20XS_7, EventScr_Unk_086759DC, 12, 26, TILE_COMMAND_SEIZE)
    EvtListTile(FLAG_CHAPTER20XS_8, EventScr_Unk_08675A34, 17, 8, TILE_COMMAND_SEIZE)
    EvtListTile(FLAG_CHAPTER20XS_9, EventScr_Unk_08675A8C, 21, 15, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 0866A250
EventListScr CONST_DATA EventListScr_Unk_0866A250[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 0866A260
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_0866A260 =
{
    .event_list_turn = EventListScr_Unk_0866A1F0,
    .event_list_talk = EventListScr_Unk_0866A200,
    .event_list_tile = EventListScr_Unk_0866A204,
    .event_list_move = EventListScr_Unk_0866A250,
    .units_red = UnitInfo_Unk_08685590,
    .units_blue = UnitInfo_Unk_086854A0,
    .event_script_victory = EventScr_Unk_08675AE4,
};
