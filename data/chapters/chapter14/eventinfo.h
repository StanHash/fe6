#pragma once

// EventListScr @ 086688CC
EventListScr CONST_DATA EventListScr_Unk_086688CC[] =
{
    EvtListTurn(0, EventScr_Unk_0866FC0C, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_0866FCD0, 7, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_0867E50C, 8, 10, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_0866FD28, 26, 0, FACTION_BLUE)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867E55C, 13, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867E55C, 15, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867E55C, 17, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867E5AC, 14, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867E5AC, 16, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867E5AC, 18, 0, FACTION_RED)
    EvtListEnd
};

// EventListScr @ 08668948
EventListScr CONST_DATA EventListScr_Unk_08668948[] =
{
    EvtListEnd
};

// EventListScr @ 0866894C
EventListScr CONST_DATA EventListScr_Unk_0866894C[] =
{
    EvtListShop(0, ShopItems_Unk_0866A8F8, 26, 4, TILE_COMMAND_ARMORY)
    EvtListShop(0, ShopItems_Unk_0866A904, 29, 4, TILE_COMMAND_VENDOR)
    EvtListTile(0, EventScr_Unk_0866FDA4, 26, 6, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Unk_0866FDE0, 25, 6, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 27, 3, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 0866898C
EventListScr CONST_DATA EventListScr_Unk_0866898C[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListArea(FLAG_CHAPTER14_9, EventScr_Unk_0866FE1C, 12, 13, 18, 18)
    EvtListArea(FLAG_CHAPTER14_10, EventScr_Unk_0866FE5C, 0, 10, 4, 15)
    EvtListArea(FLAG_CHAPTER14_11, EventScr_Unk_0866FE9C, 10, 8, 14, 10)
    EvtListArea(FLAG_CHAPTER14_12, EventScr_Unk_0866FEDC, 25, 13, 31, 16)
    EvtListArea(FLAG_CHAPTER14_13, EventScr_Unk_0866FF1C, 1, 19, 3, 21)
    EvtListArea(FLAG_CHAPTER14_14, EventScr_Unk_0866FF5C, 1, 1, 5, 5)
    EvtListArea(FLAG_CHAPTER14_15, EventScr_Unk_0866FF9C, 23, 19, 31, 21)
    EvtListArea(FLAG_CHAPTER14_16, EventScr_Unk_0866FFDC, 26, 7, 28, 10)
    EvtListEnd
};

// ChapterEventInfo @ 086689FC
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_086689FC =
{
    .event_list_turn = EventListScr_Unk_086688CC,
    .event_list_talk = EventListScr_Unk_08668948,
    .event_list_tile = EventListScr_Unk_0866894C,
    .event_list_move = EventListScr_Unk_0866898C,
    .units_red = UnitInfo_Unk_0867E22C,
    .units_blue = UnitInfo_Unk_0867E13C,
    .event_script_victory = EventScr_Unk_08670030,
};
