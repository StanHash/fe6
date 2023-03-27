#pragma once

// EventListScr @ 0866A0C4
EventListScr CONST_DATA EventListScr_Unk_0866A0C4[] =
{
    EvtListTurn(0, EventScr_Unk_0867514C, 1, 0, FACTION_BLUE)
    EvtListEnd
};

// EventListScr @ 0866A0D4
EventListScr CONST_DATA EventListScr_Unk_0866A0D4[] =
{
    EvtListEnd
};

// EventListScr @ 0866A0D8
EventListScr CONST_DATA EventListScr_Unk_0866A0D8[] =
{
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 13, 12, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 0866A0E8
EventListScr CONST_DATA EventListScr_Unk_0866A0E8[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 0866A0F8
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_0866A0F8 =
{
    .event_list_turn = EventListScr_Unk_0866A0C4,
    .event_list_talk = EventListScr_Unk_0866A0D4,
    .event_list_tile = EventListScr_Unk_0866A0D8,
    .event_list_move = EventListScr_Unk_0866A0E8,
    .units_red = UnitInfo_Unk_08684B44,
    .units_blue = UnitInfo_Unk_08684A94,
    .event_script_victory = EventScr_Unk_086751E8,
};
