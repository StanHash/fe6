#pragma once

// EventListScr @ 08668264
EventListScr CONST_DATA EventListScr_Unk_08668264[] =
{
    EvtListTurn(0, EventScr_Unk_0866E00C, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_0866E11C, 4, 0, FACTION_GREEN)
    EvtListTurn(0, EventScr_Unk_0866E0AC, 6, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_0867CAE8, 4, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_0867CB28, 6, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_0867CAE8, 7, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_0867CB28, 9, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_0867CAE8, 10, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_0867CB28, 12, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_0867CB48, 13, 18, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867CB08, 5, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867CB08, 8, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867CB08, 11, 0, FACTION_RED)
    EvtListEnd
};

// EventListScr @ 08668304
EventListScr CONST_DATA EventListScr_Unk_08668304[] =
{
    EvtListTalk(FLAG_CHAPTER10A_6, EventScr_Unk_0866E1D0, PID_LILINA, PID_GONZALEZ)
    EvtListTalk(FLAG_CHAPTER10A_7, EventScr_Unk_0866E1FC, PID_ROY, PID_GEESE)
    EvtListEnd
};

// EventListScr @ 08668320
EventListScr CONST_DATA EventListScr_Unk_08668320[] =
{
    EvtListTileMapChange(FLAG_CHAPTER10A_8, EventScr_Unk_0866E228, 18, 17, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER10A_8, EVENT_NOSCRIPT, 18, 16, TILE_COMMAND_1D)
    EvtListTile(0, EventScr_Unk_0866E270, 17, 19, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 18, 29, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 08668354
EventListScr CONST_DATA EventListScr_Unk_08668354[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 08668364
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_08668364 =
{
    .event_list_turn = EventListScr_Unk_08668264,
    .event_list_talk = EventListScr_Unk_08668304,
    .event_list_tile = EventListScr_Unk_08668320,
    .event_list_move = EventListScr_Unk_08668354,
    .units_red = UnitInfo_Unk_0867C968,
    .units_blue = UnitInfo_Unk_0867C898,
    .event_script_victory = EventScr_Unk_0866E2AC,
};
