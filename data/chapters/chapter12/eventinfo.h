#pragma once

// EventListScr @ 086685A4
EventListScr CONST_DATA EventListScr_Unk_086685A4[] =
{
    EvtListTurn(0, EventScr_Unk_0866EDE8, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_0866EF30, 1, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_0866EFF8, 7, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_0866F078, 10, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_0866F044, 12, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_0867D8E8, 17, 22, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_0866F0DC, 20, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867D828, 12, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867D7E8, 15, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867D878, 15, 0, FACTION_RED)
    EvtListEnd
};

// EventListScr @ 08668620
EventListScr CONST_DATA EventListScr_Unk_08668620[] =
{
    EvtListTalk(FLAG_CHAPTER12_5, EventScr_Unk_0866F114, PID_LUGH, PID_RAIGH)
    EvtListTalk(FLAG_CHAPTER12_5, EventScr_Unk_0866F148, PID_CHAD, PID_RAIGH)
    EvtListTalk(FLAG_CHAPTER12_9, EventScr_CathTalk, PID_ROY, PID_CATH)
    EvtListTalk(FLAG_CHAPTER12_7, EventScr_Unk_0866F17C, PID_LUGH, PID_RAIGH)
    EvtListTalk(FLAG_CHAPTER12_7, EventScr_Unk_0866F17C, PID_RAIGH, PID_LUGH)
    EvtListTalk(FLAG_CHAPTER12_8, EventScr_Unk_0866F198, PID_CHAD, PID_RAIGH)
    EvtListTalk(FLAG_CHAPTER12_8, EventScr_Unk_0866F198, PID_RAIGH, PID_CHAD)
    EvtListEnd
};

// EventListScr @ 08668678
EventListScr CONST_DATA EventListScr_Unk_08668678[] =
{
    EvtListChest(0, IID_FLUX, 0, 5, 20, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_AIRCALIBUR, 0, 5, 23, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_BLUEGEM, 0, 27, 4, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_ELYSIANWHIP, 0, 26, 6, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_BRAVEBOW, 0, 27, 8, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_LANCEREAVER, 0, 26, 12, TILE_COMMAND_CHEST)
    EvtListDoor(0, EVENT_NOSCRIPT, 7, 20, TILE_COMMAND_DOOR)
    EvtListDoor(0, EVENT_NOSCRIPT, 8, 7, TILE_COMMAND_DOOR)
    EvtListDoor(0, EVENT_NOSCRIPT, 9, 7, TILE_COMMAND_DOOR)
    EvtListDoor(0, EVENT_NOSCRIPT, 24, 5, TILE_COMMAND_DOOR)
    EvtListDoor(0, EVENT_NOSCRIPT, 26, 10, TILE_COMMAND_DOOR)
    EvtListDoor(0, EVENT_NOSCRIPT, 27, 14, TILE_COMMAND_DOOR)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 9, 1, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 08668718
EventListScr CONST_DATA EventListScr_Unk_08668718[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 08668728
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_08668728 =
{
    .event_list_turn = EventListScr_Unk_086685A4,
    .event_list_talk = EventListScr_Unk_08668620,
    .event_list_tile = EventListScr_Unk_08668678,
    .event_list_move = EventListScr_Unk_08668718,
    .units_red = UnitInfo_Unk_0867D618,
    .units_blue = UnitInfo_Unk_0867D538,
    .event_script_victory = EventScr_Unk_0866F1B4,
};
