#pragma once

// EventListScr @ 08667FC0
EventListScr CONST_DATA EventListScr_Unk_08667FC0[] =
{
    EvtListTurn(0, EventScr_Unk_0866D528, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_0866D62C, 1, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_0866D658, 6, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_0866D5E4, 10, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_0867BE5C, 16, 17, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_0867BEAC, 18, 19, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867BEFC, 15, 16, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867BF3C, 17, 18, FACTION_RED)
    EvtListEnd
};

// EventListScr @ 08668024
EventListScr CONST_DATA EventListScr_Unk_08668024[] =
{
    EvtListTalk(FLAG_CHAPTER8_5, EventScr_Unk_0866D6C0, PID_LILINA, PID_ROY)
    EvtListTalk(FLAG_CHAPTER8_6, EventScr_Unk_0866D6EC, PID_BORS, PID_GWENDOLYN)
    EvtListTalk(FLAG_CHAPTER8_6, EventScr_Unk_0866D6EC, PID_GWENDOLYN, PID_BORS)
    EvtListTalk(FLAG_CHAPTER8_7, EventScr_Unk_0866D700, PID_LILINA, PID_BORS)
    EvtListTalk(FLAG_CHAPTER8_8, EventScr_Unk_0866D714, PID_LILINA, PID_BARTHE)
    EvtListTalk(FLAG_CHAPTER8_9, EventScr_CathTalk, PID_ROY, PID_CATH)
    EvtListEnd
};

// EventListScr @ 08668070
EventListScr CONST_DATA EventListScr_Unk_08668070[] =
{
    EvtListChest(0, IID_ELYSIANWHIP, 0, 0, 9, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_SILVERAXE, 0, 1, 10, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_SECRETBOOK, 0, 0, 11, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_GUIDINGRING, 0, 1, 12, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_LIGHTBRAND, 0, 8, 9, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_KILLERBOW, 0, 9, 10, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_ELFIRE, 0, 10, 9, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_KNIGHTCREST, 0, 11, 10, TILE_COMMAND_CHEST)
    EvtListDoor(0, EVENT_NOSCRIPT, 1, 15, TILE_COMMAND_DOOR)
    EvtListDoor(0, EVENT_NOSCRIPT, 6, 9, TILE_COMMAND_DOOR)
    EvtListDoor(0, EVENT_NOSCRIPT, 13, 10, TILE_COMMAND_DOOR)
    EvtListDoor(0, EVENT_NOSCRIPT, 18, 12, TILE_COMMAND_DOOR)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 6, 17, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 08668110
EventListScr CONST_DATA EventListScr_Unk_08668110[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListFlag(FLAG_CHAPTER8_15, EventScr_Unk_0866D6AC, FLAG_CHAPTER8_14)
    EvtListEnd
};

// ChapterEventInfo @ 0866812C
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_0866812C =
{
    .event_list_turn = EventListScr_Unk_08667FC0,
    .event_list_talk = EventListScr_Unk_08668024,
    .event_list_tile = EventListScr_Unk_08668070,
    .event_list_move = EventListScr_Unk_08668110,
    .units_red = UnitInfo_Unk_0867BC4C,
    .units_blue = UnitInfo_Unk_0867BB5C,
    .event_script_victory = EventScr_Unk_0866D818,
};
