#pragma once

// EventListScr @ 08668B10
EventListScr CONST_DATA EventListScr_Unk_08668B10[] =
{
    EvtListTurn(0, EventScr_Unk_086705D8, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_0867074C, 1, 0, FACTION_GREEN)
    EvtListTurn(0, EventScr_Unk_08670800, 2, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_0867083C, 10, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_0867EF54, 12, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_0867EEC4, 11, 15, FACTION_RED)
    EvtListEnd
};

// EventListScr @ 08668B5C
EventListScr CONST_DATA EventListScr_Unk_08668B5C[] =
{
    EvtListTalk(FLAG_CHAPTER16_5, EventScr_Unk_08670890, PID_ROY, PID_HUGH)
    EvtListTalk(FLAG_CHAPTER16_6, EventScr_Unk_08670A28, PID_CECILIA, PID_DOUGLAS)
    EvtListTalk(FLAG_CHAPTER16_7, EventScr_Unk_08670A48, PID_KLEIN, PID_DOUGLAS)
    EvtListTalk(FLAG_CHAPTER16_9, EventScr_Unk_08670A94, PID_LARUM, PID_DOUGLAS)
    EvtListTalk(FLAG_CHAPTER16_10, EventScr_Unk_08670AB4, PID_ELFFIN, PID_DOUGLAS)
    EvtListTalk(FLAG_CHAPTER16_11, EventScr_Unk_08670AD4, PID_PERCEVAL, PID_DOUGLAS)
    EvtListTalk(FLAG_CHAPTER16_8, EventScr_Unk_08670A68, PID_MELADY, PID_ZEISS)
    EvtListTalk(FLAG_CHAPTER16_12, EventScr_CathTalk, PID_ROY, PID_CATH)
    EvtListEnd
};

// EventListScr @ 08668BC0
EventListScr CONST_DATA EventListScr_Unk_08668BC0[] =
{
    EvtListChest(0, IID_RECOVERSTAFF, 0, 30, 11, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_RESTORESTAFF, 0, 30, 9, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_BRAVELANCE, 0, 30, 6, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_BOLTING, 0, 30, 3, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_GOLD, 5000, 28, 2, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_RESCUESTAFF, 0, 3, 23, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_SILVERBOW, 0, 2, 22, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_HEROCREST, 0, 1, 20, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_KNIGHTCREST, 0, 2, 18, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_BERSERKSTAFF, 0, 1, 16, TILE_COMMAND_CHEST)
    EvtListShop(0, ShopItems_Unk_0866A92A, 1, 0, TILE_COMMAND_SECRET)
    EvtListDoor(0, EVENT_NOSCRIPT, 5, 15, TILE_COMMAND_DOOR)
    EvtListDoor(0, EVENT_NOSCRIPT, 11, 15, TILE_COMMAND_DOOR)
    EvtListDoor(0, EVENT_NOSCRIPT, 12, 15, TILE_COMMAND_DOOR)
    EvtListDoor(0, EVENT_NOSCRIPT, 27, 4, TILE_COMMAND_DOOR)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 14, 3, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 08668C84
EventListScr CONST_DATA EventListScr_Unk_08668C84[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 08668C94
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_08668C94 =
{
    .event_list_turn = EventListScr_Unk_08668B10,
    .event_list_talk = EventListScr_Unk_08668B5C,
    .event_list_tile = EventListScr_Unk_08668BC0,
    .event_list_move = EventListScr_Unk_08668C84,
    .units_red = UnitInfo_Unk_0867EC94,
    .units_blue = UnitInfo_Unk_0867EBA4,
    .event_script_victory = EventScr_Unk_08670AF4,
};
