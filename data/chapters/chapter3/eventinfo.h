#pragma once

// EventListScr @ 08667884
EventListScr CONST_DATA EventListScr_Unk_08667884[] =
{
    EvtListTurn(0, EventScr_Unk_0866BEB0, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_0866C044, 3, 0, FACTION_RED)
    EvtListFlag(FLAG_CHAPTER3_12, EventScr_LoadUnits_Unk_0867A58C, FLAG_CHAPTER3_8)
    EvtListTurn(FLAG_CHAPTER3_4, EventScr_Unk_0866BF78, 2, 0, FACTION_BLUE)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867A58C, 5, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867A58C, 10, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867A58C, 15, 0, FACTION_RED)
    EvtListEnd
};

// EventListScr @ 086678DC
EventListScr CONST_DATA EventListScr_Unk_086678DC[] =
{
    EvtListTalk(FLAG_CHAPTER3_5, EventScr_Unk_0866C1B4, PID_CHAD, PID_LUGH)
    EvtListTalk(FLAG_CHAPTER3_5, EventScr_Unk_0866C1B4, PID_LUGH, PID_CHAD)
    EvtListEnd
};

// EventListScr @ 086678F8
EventListScr CONST_DATA EventListScr_Unk_086678F8[] =
{
    EvtListTileMapChange(FLAG_CHAPTER3_8, EventScr_Unk_0866C1E8, 3, 3, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER3_8, EVENT_NOSCRIPT, 3, 2, TILE_COMMAND_1D)
    EvtListTileMapChange(0, EventScr_Unk_0866C268, 19, 19, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 19, 18, TILE_COMMAND_1D)
    EvtListChest(0, IID_HALBERD, 0, 20, 11, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_GOLD, 3000, 22, 12, TILE_COMMAND_CHEST)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 19, 4, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 08667950
EventListScr CONST_DATA EventListScr_Unk_08667950[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 08667960
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_08667960 =
{
    .event_list_turn = EventListScr_Unk_08667884,
    .event_list_talk = EventListScr_Unk_086678DC,
    .event_list_tile = EventListScr_Unk_086678F8,
    .event_list_move = EventListScr_Unk_08667950,
    .units_red = UnitInfo_Unk_0867A39C,
    .units_blue = UnitInfo_Unk_0867A2AC,
    .event_script_victory = EventScr_Unk_0866C2B0,
};
