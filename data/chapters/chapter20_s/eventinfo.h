#pragma once

// EventListScr @ 08669E30
EventListScr CONST_DATA EventListScr_Unk_08669E30[] =
{
    EvtListTurn(0, EventScr_Unk_086747D0, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_08674880, 2, 0, FACTION_GREEN)
    EvtListTurn(0, EventScr_Unk_086748E8, 10, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08684134, 12, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_086748C8, 26, 0, FACTION_BLUE)
    EvtListEnd
};

// EventListScr @ 08669E70
EventListScr CONST_DATA EventListScr_Unk_08669E70[] =
{
    EvtListTalk(FLAG_CHAPTER20S_5, EventScr_Unk_08674934, PID_ROY, PID_DAYAN)
    EvtListTalk(FLAG_CHAPTER20S_5, EventScr_Unk_08674970, PID_SUE, PID_DAYAN)
    EvtListTalk(FLAG_CHAPTER20S_5, EventScr_Unk_086749A4, PID_SIN, PID_DAYAN)
    EvtListTalk(FLAG_CHAPTER20S_10, EventScr_CathTalk, PID_ROY, PID_CATH)
    EvtListTalk(FLAG_CHAPTER20S_8, EventScr_Unk_086749D8, PID_SUE, PID_DAYAN)
    EvtListTalk(FLAG_CHAPTER20S_8, EventScr_Unk_086749D8, PID_DAYAN, PID_SUE)
    EvtListTalk(FLAG_CHAPTER20S_9, EventScr_Unk_086749F4, PID_SIN, PID_DAYAN)
    EvtListTalk(FLAG_CHAPTER20S_9, EventScr_Unk_086749F4, PID_DAYAN, PID_SIN)
    EvtListEnd
};

// EventListScr @ 08669ED4
EventListScr CONST_DATA EventListScr_Unk_08669ED4[] =
{
    EvtListChest(0, IID_SLEEPSTAFF, 0, 24, 5, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_AXEREAVER, 0, 24, 8, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_GUIDINGRING, 0, 26, 6, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_BLUEGEM, 0, 26, 9, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_NOSFERATU, 0, 22, 6, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_DRACOSHIELD, 0, 26, 4, TILE_COMMAND_CHEST)
    EvtListDoor(0, EVENT_NOSCRIPT, 10, 4, TILE_COMMAND_DOOR)
    EvtListDoor(0, EVENT_NOSCRIPT, 20, 5, TILE_COMMAND_DOOR)
    EvtListDoor(0, EVENT_NOSCRIPT, 25, 11, TILE_COMMAND_DOOR)
    EvtListDoor(0, EVENT_NOSCRIPT, 23, 15, TILE_COMMAND_DOOR)
    EvtListDoor(0, EVENT_NOSCRIPT, 19, 15, TILE_COMMAND_DOOR)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 15, 2, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 08669F68
EventListScr CONST_DATA EventListScr_Unk_08669F68[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 08669F78
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_08669F78 =
{
    .event_list_turn = EventListScr_Unk_08669E30,
    .event_list_talk = EventListScr_Unk_08669E70,
    .event_list_tile = EventListScr_Unk_08669ED4,
    .event_list_move = EventListScr_Unk_08669F68,
    .units_red = UnitInfo_Unk_08683EF4,
    .units_blue = UnitInfo_Unk_08683DA4,
    .event_script_victory = EventScr_Unk_08674A10,
};
