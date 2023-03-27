#pragma once

// EventListScr @ 08669028
EventListScr CONST_DATA EventListScr_Unk_08669028[] =
{
    EvtListTurn(0, EventScr_Unk_08671690, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_086717A0, 10, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_08671800, 26, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086801E4, 15, 18, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08680214, 11, 14, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_086801E4, 11, 14, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_08680214, 15, 18, FACTION_RED)
    EvtListEnd
};

// EventListScr @ 08669080
EventListScr CONST_DATA EventListScr_Unk_08669080[] =
{
    EvtListTalk(FLAG_CHAPTER20I_6, EventScr_Unk_086718B0, PID_SHANNA, PID_JUNO)
    EvtListTalk(FLAG_CHAPTER20I_6, EventScr_Unk_086718EC, PID_THEA, PID_JUNO)
    EvtListTalk(FLAG_CHAPTER20I_6, EventScr_Unk_08671928, PID_ZELOT, PID_JUNO)
    EvtListTalk(FLAG_CHAPTER20I_10, EventScr_CathTalk, PID_ROY, PID_CATH)
    EvtListTalk(FLAG_CHAPTER20I_7, EventScr_Unk_08671964, PID_SHANNA, PID_JUNO)
    EvtListTalk(FLAG_CHAPTER20I_7, EventScr_Unk_08671964, PID_JUNO, PID_SHANNA)
    EvtListTalk(FLAG_CHAPTER20I_8, EventScr_Unk_08671980, PID_THEA, PID_JUNO)
    EvtListTalk(FLAG_CHAPTER20I_8, EventScr_Unk_08671980, PID_JUNO, PID_THEA)
    EvtListTalk(FLAG_CHAPTER20I_9, EventScr_Unk_0867199C, PID_ZELOT, PID_JUNO)
    EvtListTalk(FLAG_CHAPTER20I_9, EventScr_Unk_0867199C, PID_JUNO, PID_ZELOT)
    EvtListEnd
};

// EventListScr @ 086690FC
EventListScr CONST_DATA EventListScr_Unk_086690FC[] =
{
    EvtListShop(0, ShopItems_Unk_0866A96A, 8, 0, TILE_COMMAND_ARMORY)
    EvtListShop(0, ShopItems_Unk_0866A98A, 5, 1, TILE_COMMAND_VENDOR)
    EvtListChest(0, IID_SPEEDWING, 0, 2, 10, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_AXEREAVER, 0, 3, 11, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_LONGBOW, 0, 4, 11, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_WODAO, 0, 5, 10, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_PURGE, 0, 16, 18, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_SLEEPSTAFF, 0, 17, 16, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_NOSFERATU, 0, 15, 16, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_WYRMSLAYER, 0, 12, 16, TILE_COMMAND_CHEST)
    EvtListDoor(0, EVENT_NOSCRIPT, 7, 11, TILE_COMMAND_DOOR)
    EvtListDoor(0, EVENT_NOSCRIPT, 7, 17, TILE_COMMAND_DOOR)
    EvtListDoor(0, EVENT_NOSCRIPT, 9, 8, TILE_COMMAND_DOOR)
    EvtListDoor(0, EVENT_NOSCRIPT, 18, 20, TILE_COMMAND_DOOR)
    EvtListDoor(0, EVENT_NOSCRIPT, 22, 18, TILE_COMMAND_DOOR)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 3, 19, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 086691C0
EventListScr CONST_DATA EventListScr_Unk_086691C0[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListArea(FLAG_CHAPTER20I_5, EventScr_Unk_08671834, 8, 10, 18, 14)
    EvtListEnd
};

// ChapterEventInfo @ 086691DC
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_086691DC =
{
    .event_list_turn = EventListScr_Unk_08669028,
    .event_list_talk = EventListScr_Unk_08669080,
    .event_list_tile = EventListScr_Unk_086690FC,
    .event_list_move = EventListScr_Unk_086691C0,
    .units_red = UnitInfo_Unk_0867FF74,
    .units_blue = UnitInfo_Unk_0867FE94,
    .event_script_victory = EventScr_Unk_086719B8,
};
