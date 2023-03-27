#pragma once

// EventListScr @ 086696E8
EventListScr CONST_DATA EventListScr_Unk_086696E8[] =
{
    EvtListTurn(0, EventScr_Unk_08672E40, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_08672ED8, 1, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_08672F64, 1, 0, FACTION_GREEN)
    EvtListTurn(0, EventScr_Unk_08672FB4, 4, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_08673000, 6, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_0867303C, 8, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_086730B4, 10, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086821DC, 9, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086821DC, 11, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086821DC, 13, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_086730F4, 9, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_0867315C, 10, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_Unk_08673190, 14, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_Unk_086731F8, 15, 0, FACTION_RED)
    EvtListEnd
};

// EventListScr @ 08669794
EventListScr CONST_DATA EventListScr_Unk_08669794[] =
{
    EvtListTalk(FLAG_CHAPTER10B_4, EventScr_Unk_0867322C, PID_LILINA, PID_GONZALEZ)
    EvtListFunc(FLAG_CHAPTER10B_5, EventScr_Unk_08673258, func_fe6_0806BE00)
    EvtListTalk(FLAG_CHAPTER10B_6, EventScr_Unk_08673274, PID_ROY, PID_KLEIN)
    EvtListTalk(FLAG_CHAPTER10B_6, EventScr_Unk_086732C0, PID_CLARINE, PID_KLEIN)
    EvtListFunc(FLAG_CHAPTER10B_8, EventScr_Unk_08673304, func_fe6_0806BE60)
    EvtListFunc(FLAG_CHAPTER10B_10, EventScr_Unk_0867339C, func_fe6_0806BE30)
    EvtListTalk(FLAG_CHAPTER10B_8, EventScr_Unk_08673350, PID_KLEIN, PID_THEA)
    EvtListTalk(FLAG_CHAPTER10B_11, EventScr_Unk_086733D4, PID_CLARINE, PID_KLEIN)
    EvtListTalk(FLAG_CHAPTER10B_11, EventScr_Unk_086733D4, PID_KLEIN, PID_CLARINE)
    EvtListEnd
};

// EventListScr @ 08669804
EventListScr CONST_DATA EventListScr_Unk_08669804[] =
{
    EvtListTileMapChange(FLAG_CHAPTER10B_12, EventScr_Unk_086733E8, 18, 11, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER10B_12, EVENT_NOSCRIPT, 18, 10, TILE_COMMAND_1D)
    EvtListTileMapChange(FLAG_CHAPTER10B_13, EventScr_Unk_08673430, 18, 16, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER10B_13, EVENT_NOSCRIPT, 18, 15, TILE_COMMAND_1D)
    EvtListTileMapChange(FLAG_CHAPTER10B_14, EventScr_Unk_08673478, 8, 20, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER10B_14, EVENT_NOSCRIPT, 8, 19, TILE_COMMAND_1D)
    EvtListTileMapChange(FLAG_CHAPTER10B_15, EventScr_Unk_086734C0, 8, 8, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER10B_15, EVENT_NOSCRIPT, 8, 7, TILE_COMMAND_1D)
    EvtListTileMapChange(FLAG_CHAPTER10B_16, EventScr_Unk_08673570, 4, 8, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER10B_16, EVENT_NOSCRIPT, 4, 7, TILE_COMMAND_1D)
    EvtListTileMapChange(0, EventScr_Unk_08673620, 5, 13, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 5, 12, TILE_COMMAND_1D)
    EvtListTileMapChange(0, EventScr_Unk_08673668, 17, 23, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 17, 22, TILE_COMMAND_1D)
    EvtListShop(0, ShopItems_Unk_0866AA4E, 4, 22, TILE_COMMAND_ARMORY)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 20, 2, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 086698C8
EventListScr CONST_DATA EventListScr_Unk_086698C8[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 086698D8
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_086698D8 =
{
    .event_list_turn = EventListScr_Unk_086696E8,
    .event_list_talk = EventListScr_Unk_08669794,
    .event_list_tile = EventListScr_Unk_08669804,
    .event_list_move = EventListScr_Unk_086698C8,
    .units_red = UnitInfo_Unk_0868202C,
    .units_blue = UnitInfo_Unk_08681F5C,
    .event_script_victory = EventScr_Unk_086736B0,
};
