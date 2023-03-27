#pragma once

// EventListScr @ 086696E8
EventListScr CONST_DATA EventListScr_Chapter10B_Turn[] =
{
    EvtListTurn(0, EventScr_Unk_08672E40, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_08672ED8, 1, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_08672F64, 1, 0, FACTION_GREEN)
    EvtListTurn(0, EventScr_Unk_08672FB4, 4, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Unk_08673000, 6, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Chapter10B_KleinSquadArrives, 8, 0, FACTION_RED)
    EvtListTurn(0, EventScr_Chapter10B_TheaSquadArrives, 10, 0, FACTION_RED)
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
EventListScr CONST_DATA EventListScr_Chapter10B_Talk[] =
{
    EvtListTalk(FLAG_CHAPTER10B_4, EventScr_Chapter10B_LilinaRecruitsGonzalez, PID_LILINA, PID_GONZALEZ)
    EvtListFunc(FLAG_CHAPTER10B_5, EventScr_Chapter10B_TalkTheaShanna, Chapter10B_CheckTalkShannaThea)
    EvtListTalk(FLAG_CHAPTER10B_6, EventScr_Chapter10B_RoyRecruitsKlein, PID_ROY, PID_KLEIN)
    EvtListTalk(FLAG_CHAPTER10B_6, EventScr_Chapter10B_ClarineRecruitsKlein, PID_CLARINE, PID_KLEIN)
    EvtListFunc(FLAG_CHAPTER10B_8, EventScr_Chapter10B_ShannaRecruitsThea, Chapter10B_CheckShannaRecruitsThea)
    EvtListFunc(FLAG_CHAPTER10B_10, EventScr_Chapter10B_TalkTheaShannaAfterKlein, Chapter10B_CheckTalkShannaTheaAfterKlein)
    EvtListTalk(FLAG_CHAPTER10B_8, EventScr_Chapter10B_KleinRecruitsThea, PID_KLEIN, PID_THEA)
    EvtListTalk(FLAG_CHAPTER10B_11, EventScr_TalkKleinClarine, PID_CLARINE, PID_KLEIN)
    EvtListTalk(FLAG_CHAPTER10B_11, EventScr_TalkKleinClarine, PID_KLEIN, PID_CLARINE)
    EvtListEnd
};

// EventListScr @ 08669804
EventListScr CONST_DATA EventListScr_Chapter10B_Tile[] =
{
    EvtListTileMapChange(FLAG_CHAPTER10B_12, EventScr_Chapter10B_VillageA, 18, 11, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER10B_12, EVENT_NOSCRIPT, 18, 10, TILE_COMMAND_PILLAGE)
    EvtListTileMapChange(FLAG_CHAPTER10B_13, EventScr_Chapter10B_VillageB, 18, 16, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER10B_13, EVENT_NOSCRIPT, 18, 15, TILE_COMMAND_PILLAGE)
    EvtListTileMapChange(FLAG_CHAPTER10B_14, EventScr_Chapter10B_VillageC, 8, 20, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER10B_14, EVENT_NOSCRIPT, 8, 19, TILE_COMMAND_PILLAGE)
    EvtListTileMapChange(FLAG_CHAPTER10B_15, EventScr_Chapter10B_VillageD, 8, 8, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER10B_15, EVENT_NOSCRIPT, 8, 7, TILE_COMMAND_PILLAGE)
    EvtListTileMapChange(FLAG_CHAPTER10B_16, EventScr_Chapter10B_VillageE, 4, 8, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_CHAPTER10B_16, EVENT_NOSCRIPT, 4, 7, TILE_COMMAND_PILLAGE)
    EvtListTileMapChange(0, EventScr_Chapter10B_VillageF, 5, 13, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 5, 12, TILE_COMMAND_PILLAGE)
    EvtListTileMapChange(0, EventScr_Chapter10B_VillageG, 17, 23, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 17, 22, TILE_COMMAND_PILLAGE)
    EvtListShop(0, ShopItems_Chapter10B_Armory, 4, 22, TILE_COMMAND_ARMORY)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 20, 2, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 086698C8
EventListScr CONST_DATA EventListScr_Chapter10B_Move[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 086698D8
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_086698D8 =
{
    .event_list_turn = EventListScr_Chapter10B_Turn,
    .event_list_talk = EventListScr_Chapter10B_Talk,
    .event_list_tile = EventListScr_Chapter10B_Tile,
    .event_list_move = EventListScr_Chapter10B_Move,
    .units_red = UnitInfo_Chapter10B_Red,
    .units_blue = UnitInfo_Chapter10B_Deploy,
    .event_script_victory = EventScr_Chapter10B_Victory,
};
