#pragma once

// EventListScr @ 08667BD8
EventListScr CONST_DATA EventListScr_Unk_08667BD8[] =
{
    EvtListTurn(0, EventScr_Unk_0866CB34, 1, 0, FACTION_BLUE)
    EvtListTurn(FLAG_CHAPTER6_13, EventScr_Unk_0866CD08, 1, 0, FACTION_RED)
    EvtListTurn(FLAG_CHAPTER6_12, EventScr_Unk_0866CCDC, 5, 0, FACTION_RED)
    EvtListFlag(FLAG_CHAPTER6_7, EventScr_Unk_0866CC5C, FLAG_CHAPTER6_4)
    EvtListFlag(FLAG_CHAPTER6_11, EventScr_Unk_0866CC9C, FLAG_CHAPTER6_8)
    EvtListFunc(FLAG_CHAPTER6_14, EventScr_Unk_0866CD4C, func_fe6_0806AD48)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867B3F0, 8, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867B440, 12, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867B490, 16, 0, FACTION_RED)
    EvtListEnd
};

// EventListScr @ 08667C48
EventListScr CONST_DATA EventListScr_Unk_08667C48[] =
{
    EvtListTalk(FLAG_CHAPTER6_15, EventScr_Unk_0866CD6C, PID_ROY, PID_SUE)
    EvtListTalk(FLAG_CHAPTER6_16, EventScr_CathTalk, PID_ROY, PID_CATH)
    EvtListEnd
};

// EventListScr @ 08667C64
EventListScr CONST_DATA EventListScr_Unk_08667C64[] =
{
    EvtListChest(0, IID_SHORTBOW, 0, 22, 8, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_GODDESSICON, 0, 23, 9, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_KILLERAXE, 0, 22, 10, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_GOLD, 2000, 23, 13, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_SILVERLANCE, 0, 22, 15, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_UNLOCKSTAFF, 0, 3, 3, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_GOLD, 5000, 2, 13, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_GOLD, 3000, 2, 15, TILE_COMMAND_CHEST)
    EvtListDoor(0, EVENT_NOSCRIPT, 5, 14, TILE_COMMAND_DOOR)
    EvtListDoor(0, EVENT_NOSCRIPT, 5, 9, TILE_COMMAND_DOOR)
    EvtListDoor(0, EVENT_NOSCRIPT, 20, 9, TILE_COMMAND_DOOR)
    EvtListDoor(0, EVENT_NOSCRIPT, 20, 14, TILE_COMMAND_DOOR)
    EvtListDoor(FLAG_CHAPTER6_4, EVENT_NOSCRIPT, 7, 17, TILE_COMMAND_DOOR)
    EvtListTile(0, EventScr_Unk_0866CD98, 8, 4, TILE_COMMAND_DOOR)
    EvtListTile(0, EventScr_Unk_0866CD98, 6, 6, TILE_COMMAND_DOOR)
    EvtListTile(0, EventScr_Unk_0866CDB0, 19, 6, TILE_COMMAND_DOOR)
    EvtListTile(0, EventScr_Unk_0866CDB0, 16, 4, TILE_COMMAND_DOOR)
    EvtListDoor(FLAG_CHAPTER6_8, EVENT_NOSCRIPT, 19, 17, TILE_COMMAND_DOOR)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 12, 1, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 08667D4C
EventListScr CONST_DATA EventListScr_Unk_08667D4C[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 08667D5C
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_08667D5C =
{
    .event_list_turn = EventListScr_Unk_08667BD8,
    .event_list_talk = EventListScr_Unk_08667C48,
    .event_list_tile = EventListScr_Unk_08667C64,
    .event_list_move = EventListScr_Unk_08667D4C,
    .units_red = UnitInfo_Unk_0867B080,
    .units_blue = UnitInfo_Unk_0867AFA0,
    .event_script_victory = EventScr_Unk_0866CDC8,
};
