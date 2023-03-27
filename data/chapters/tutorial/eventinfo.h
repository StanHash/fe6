#pragma once

// EventListScr @ 08667640
EventListScr CONST_DATA EventListScr_Unk_08667640[] =
{
    EvtListTurn(0, EventScr_Unk_0866AD18, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_0866AE10, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_0866AE60, 2, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_0866AD78, 3, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_0866AE78, 4, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_0866AE90, 7, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_0866ADE4, 5, 0, FACTION_BLUE)
    EvtListEnd
};

// EventListScr @ 08667698
EventListScr CONST_DATA EventListScr_Unk_08667698[] =
{
    EvtListEnd
};

// EventListScr @ 0866769C
EventListScr CONST_DATA EventListScr_Unk_0866769C[] =
{
    EvtListTileMapChange(FLAG_TUTORIAL_13, EventScr_Unk_0866B2FC, 12, 3, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_TUTORIAL_13, EVENT_NOSCRIPT, 12, 2, TILE_COMMAND_1D)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 22, 4, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 086676C4
EventListScr CONST_DATA EventListScr_Unk_086676C4[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListArea(0, EventScr_Unk_0866B350, 0, 0, 26, 9)
    EvtListEnd
};

// EventListScr @ 086676E0
EventListScr CONST_DATA EventListScr_Tutorial_ActionSelect[] =
{
    EvtListFlag(0, EventScr_Unk_0866B14C, FLAG_TUTORIAL_4)
    EvtListEnd
};

// ChapterEventInfo @ 086676F0
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_086676F0 =
{
    .event_list_turn = EventListScr_Unk_08667640,
    .event_list_talk = EventListScr_Unk_08667698,
    .event_list_tile = EventListScr_Unk_0866769C,
    .event_list_move = EventListScr_Unk_086676C4,
    .units_red = UnitInfo_Unk_086799D4,
    .units_blue = UnitInfo_Unk_08679974,
    .event_script_victory = EventScr_Unk_0866B5A0,
};
