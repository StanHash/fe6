#pragma once

// EventListScr @ 08669F94
EventListScr CONST_DATA EventListScr_Unk_08669F94[] =
{
    EvtListTurn(0, EventScr_Unk_08674B2C, 1, 0, FACTION_BLUE)
    EvtListEnd
};

// EventListScr @ 08669FA4
EventListScr CONST_DATA EventListScr_Unk_08669FA4[] =
{
    EvtListEnd
};

// EventListScr @ 08669FA8
EventListScr CONST_DATA EventListScr_Unk_08669FA8[] =
{
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 3, 2, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 08669FB8
EventListScr CONST_DATA EventListScr_Unk_08669FB8[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 08669FC8
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_08669FC8 =
{
    .event_list_turn = EventListScr_Unk_08669F94,
    .event_list_talk = EventListScr_Unk_08669FA4,
    .event_list_tile = EventListScr_Unk_08669FA8,
    .event_list_move = EventListScr_Unk_08669FB8,
    .units_red = UnitInfo_Unk_086842FC,
    .units_blue = UnitInfo_Unk_0868424C,
    .event_script_victory = EventScr_Unk_08674BB0,
};
