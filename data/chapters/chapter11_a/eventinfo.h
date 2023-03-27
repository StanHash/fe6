#pragma once

// EventListScr @ 08668380
EventListScr CONST_DATA EventListScr_Unk_08668380[] =
{
    EvtListTurn(0, EventScr_Unk_0866E314, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_0866E418, 1, 0, FACTION_RED)
    EvtListTurn(FLAG_CHAPTER11A_4, EventScr_Unk_0866E4D4, 5, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_0866E5DC, 5, 0, FACTION_RED)
    EvtListTurn(FLAG_CHAPTER11A_5, EventScr_Unk_0866E544, 6, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_0866E5A0, 7, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_0866E64C, 7, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_0866E488, 8, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_0866E684, 9, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_0866E6EC, 10, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_0867D0EC, 12, 15, FACTION_RED)
    EvtListTurnHard(0, EventScr_Unk_0866E720, 13, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_Unk_0866E788, 14, 0, FACTION_RED)
    EvtListEnd
};

// EventListScr @ 08668420
EventListScr CONST_DATA EventListScr_Unk_08668420[] =
{
    EvtListTalk(FLAG_CHAPTER11A_6, EventScr_Unk_0866E7BC, PID_LARUM, PID_ECHIDNA)
    EvtListFunc(FLAG_CHAPTER11A_7, EventScr_Unk_0866E808, func_fe6_0806BB34)
    EvtListTalk(FLAG_CHAPTER11A_8, EventScr_Unk_0866E824, PID_ROY, PID_KLEIN)
    EvtListTalk(FLAG_CHAPTER11A_8, EventScr_Unk_0866E870, PID_CLARINE, PID_KLEIN)
    EvtListFunc(FLAG_CHAPTER11A_10, EventScr_Unk_0866E8B4, func_fe6_0806BB68)
    EvtListFunc(FLAG_CHAPTER11A_12, EventScr_Unk_0866E94C, func_fe6_0806BB9C)
    EvtListTalk(FLAG_CHAPTER11A_10, EventScr_Unk_0866E900, PID_KLEIN, PID_THEA)
    EvtListTalk(FLAG_CHAPTER11A_13, EventScr_TalkKleinClarine, PID_CLARINE, PID_KLEIN)
    EvtListTalk(FLAG_CHAPTER11A_13, EventScr_TalkKleinClarine, PID_KLEIN, PID_CLARINE)
    EvtListEnd
};

// EventListScr @ 08668490
EventListScr CONST_DATA EventListScr_Unk_08668490[] =
{
    EvtListTileMapChange(FLAG_CHAPTER11A_14, EventScr_Unk_0866E984, 11, 18, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER11A_14, EVENT_NOSCRIPT, 11, 17, TILE_COMMAND_PILLAGE)
    EvtListTileMapChange(FLAG_CHAPTER11A_15, EventScr_Unk_0866E9CC, 24, 18, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER11A_15, EVENT_NOSCRIPT, 24, 17, TILE_COMMAND_PILLAGE)
    EvtListTileMapChange(FLAG_CHAPTER11A_16, EventScr_Unk_0866EA14, 18, 14, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER11A_16, EVENT_NOSCRIPT, 18, 13, TILE_COMMAND_PILLAGE)
    EvtListTileMapChange(FLAG_CHAPTER11A_17, EventScr_Unk_0866EA5C, 5, 18, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER11A_17, EVENT_NOSCRIPT, 5, 17, TILE_COMMAND_PILLAGE)
    EvtListTileMapChange(FLAG_CHAPTER11A_18, EventScr_Unk_0866EAA4, 18, 6, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER11A_18, EVENT_NOSCRIPT, 18, 5, TILE_COMMAND_PILLAGE)
    EvtListTileMapChange(FLAG_CHAPTER11A_19, EventScr_Unk_0866EAEC, 24, 6, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER11A_19, EVENT_NOSCRIPT, 24, 5, TILE_COMMAND_PILLAGE)
    EvtListTileMapChange(FLAG_CHAPTER11A_20, EventScr_Unk_0866EB34, 5, 24, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER11A_20, EVENT_NOSCRIPT, 5, 23, TILE_COMMAND_PILLAGE)
    EvtListTileMapChange(FLAG_CHAPTER11A_21, EventScr_Unk_0866EB7C, 11, 24, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER11A_21, EVENT_NOSCRIPT, 11, 23, TILE_COMMAND_PILLAGE)
    EvtListShop(0, ShopItems_Unk_0866A8A0, 11, 12, TILE_COMMAND_ARMORY)
    EvtListShop(0, ShopItems_Unk_0866A8B8, 11, 6, TILE_COMMAND_VENDOR)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 27, 2, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 08668578
EventListScr CONST_DATA EventListScr_Unk_08668578[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 08668588
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_08668588 =
{
    .event_list_turn = EventListScr_Unk_08668380,
    .event_list_talk = EventListScr_Unk_08668420,
    .event_list_tile = EventListScr_Unk_08668490,
    .event_list_move = EventListScr_Unk_08668578,
    .units_red = UnitInfo_Unk_0867CE9C,
    .units_blue = UnitInfo_Unk_0867CDAC,
    .event_script_victory = EventScr_Unk_0866EBC4,
};
