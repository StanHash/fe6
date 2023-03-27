#pragma once

// EventListScr @ 08669314
EventListScr CONST_DATA EventListScr_Unk_08669314[] =
{
    EvtListTurn(0, EventScr_Unk_086720EC, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086810A0, 10, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086810A0, 15, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086810A0, 20, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086810A0, 25, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086810A0, 30, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086810A0, 35, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086810A0, 40, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_08672430, 9, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_08672430, 12, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_08672430, 15, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_08672430, 18, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_08672430, 21, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_08672430, 24, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_08672430, 27, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_08672430, 30, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_08672430, 33, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_08672430, 36, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_08672430, 39, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_08672430, 42, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_08672430, 45, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_086721F4, 15, 0, FACTION_GREEN)
    EvtListEnd
};

// EventListScr @ 08669420
EventListScr CONST_DATA EventListScr_Unk_08669420[] =
{
    EvtListTalk(FLAG_CHAPTER22_10, EventScr_CathTalk, PID_ROY, PID_CATH)
    EvtListEnd
};

// EventListScr @ 08669430
EventListScr CONST_DATA EventListScr_Unk_08669430[] =
{
    EvtListChest(0, IID_SLEEPSTAFF, 0, 1, 8, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_WHITEGEM, 0, 1, 10, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_NOSFERATU, 0, 1, 12, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_WYRMSLAYER, 0, 29, 8, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_DRACOSHIELD, 0, 29, 11, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_SWORDREAVER, 0, 29, 14, TILE_COMMAND_CHEST)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 15, 8, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 08669488
EventListScr CONST_DATA EventListScr_Unk_08669488[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListArea(FLAG_CHAPTER22_5, EventScr_Unk_08672260, 1, 0, 1, 0)
    EvtListArea(FLAG_CHAPTER22_6, EventScr_Unk_086722EC, 30, 0, 30, 0)
    EvtListArea(FLAG_CHAPTER22_8, EventScr_Unk_08672378, 14, 20, 16, 20)
    EvtListEnd
};

// ChapterEventInfo @ 086694BC
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_086694BC =
{
    .event_list_turn = EventListScr_Unk_08669314,
    .event_list_talk = EventListScr_Unk_08669420,
    .event_list_tile = EventListScr_Unk_08669430,
    .event_list_move = EventListScr_Unk_08669488,
    .units_red = UnitInfo_Unk_08680D70,
    .units_blue = UnitInfo_Unk_08680C60,
    .event_script_victory = EventScr_Unk_08672464,
};
