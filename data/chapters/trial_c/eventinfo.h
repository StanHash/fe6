#pragma once

// EventListScr @ 0866A5D0
EventListScr CONST_DATA EventListScr_Unk_0866A5D0[] =
{
    EvtListTurn(0, EventScr_Unk_08676080, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686C9C, 4, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686CEC, 8, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686D3C, 12, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686D8C, 12, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686DDC, 16, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686E2C, 18, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_08676088, 21, 0, FACTION_BLUE)
    EvtListEnd
};

// EventListScr @ 0866A634
EventListScr CONST_DATA EventListScr_Unk_0866A634[] =
{
    EvtListEnd
};

// EventListScr @ 0866A638
EventListScr CONST_DATA EventListScr_Unk_0866A638[] =
{
    EvtListEnd
};

// EventListScr @ 0866A63C
EventListScr CONST_DATA EventListScr_Unk_0866A63C[] =
{
    EvtListFunc(FLAG_3, EventScr_Unk_086760AC, func_fe6_0806BEEC)
    EvtListFlag(FLAG_3, EventScr_Unk_086760AC, FLAG_101)
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 0866A664
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_0866A664 =
{
    .event_list_turn = EventListScr_Unk_0866A5D0,
    .event_list_talk = EventListScr_Unk_0866A634,
    .event_list_tile = EventListScr_Unk_0866A638,
    .event_list_move = EventListScr_Unk_0866A63C,
    .units_red = UnitInfo_Unk_08686AFC,
    .units_blue = UnitInfo_Unk_08686A4C,
    .event_script_victory = EventScr_Unk_08676088,
};
