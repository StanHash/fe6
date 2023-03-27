#pragma once

// EventListScr @ 08669698
EventListScr CONST_DATA EventListScr_Unk_08669698[] =
{
    EvtListTurn(0, EventScr_Unk_08672BE4, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_08672D10, 1, 255, FACTION_RED)
    EvtListEnd
};

// EventListScr @ 086696B4
EventListScr CONST_DATA EventListScr_Unk_086696B4[] =
{
    EvtListEnd
};

// EventListScr @ 086696B8
EventListScr CONST_DATA EventListScr_Unk_086696B8[] =
{
    EvtListEnd
};

// EventListScr @ 086696BC
EventListScr CONST_DATA EventListScr_Unk_086696BC[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 086696CC
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_086696CC =
{
    .event_list_turn = EventListScr_Unk_08669698,
    .event_list_talk = EventListScr_Unk_086696B4,
    .event_list_tile = EventListScr_Unk_086696B8,
    .event_list_move = EventListScr_Unk_086696BC,
    .units_red = UnitInfo_Unk_08681DB4,
    .units_blue = UnitInfo_Unk_08681D04,
    .event_script_victory = EventScr_Unk_08672E0C,
};
