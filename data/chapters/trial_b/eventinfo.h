#pragma once

// EventListScr @ 0866A3A0
EventListScr CONST_DATA EventListScr_Unk_0866A3A0[] =
{
    EvtListTurn(0, EventScr_Unk_08676030, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086866A8, 3, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686888, 3, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686868, 3, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086866C8, 4, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686848, 4, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086867E8, 4, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086866E8, 5, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686828, 5, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686808, 5, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686708, 7, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686808, 7, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686828, 7, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686728, 8, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086867E8, 8, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686848, 8, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686748, 9, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086867C8, 9, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686868, 9, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686768, 11, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086867A8, 11, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686888, 11, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686788, 12, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686768, 12, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086866A8, 12, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086867A8, 13, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086868A8, 13, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086866C8, 13, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086867C8, 15, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686748, 15, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086866E8, 15, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086867E8, 16, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686728, 16, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686708, 16, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686808, 17, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686708, 17, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686728, 17, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08686828, 18, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086866E8, 18, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086868A8, 18, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_08676038, 21, 0, FACTION_BLUE)
    EvtListEnd
};

// EventListScr @ 0866A590
EventListScr CONST_DATA EventListScr_Unk_0866A590[] =
{
    EvtListEnd
};

// EventListScr @ 0866A594
EventListScr CONST_DATA EventListScr_Unk_0866A594[] =
{
    EvtListEnd
};

// EventListScr @ 0866A598
EventListScr CONST_DATA EventListScr_Unk_0866A598[] =
{
    EvtListFlag(FLAG_3, EventScr_Unk_0867605C, FLAG_101)
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 0866A5B4
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_0866A5B4 =
{
    .event_list_turn = EventListScr_Unk_0866A3A0,
    .event_list_talk = EventListScr_Unk_0866A590,
    .event_list_tile = EventListScr_Unk_0866A594,
    .event_list_move = EventListScr_Unk_0866A598,
    .units_red = UnitInfo_Unk_08686548,
    .units_blue = UnitInfo_Unk_08686498,
    .event_script_victory = EventScr_Unk_08676038,
};
