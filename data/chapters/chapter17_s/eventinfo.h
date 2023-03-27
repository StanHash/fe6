#pragma once

// EventListScr @ 08669A70
EventListScr CONST_DATA EventListScr_Unk_08669A70[] =
{
    EvtListTurn(0, EventScr_Unk_08673CE8, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_08673DBC, 2, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08682F50, 3, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08682F50, 6, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08682F50, 9, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08682F70, 6, 8, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08682FA0, 12, 15, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_08682F70, 16, 20, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_08682FA0, 11, 15, FACTION_RED)
    EvtListEnd
};

// EventListScr @ 08669AE0
EventListScr CONST_DATA EventListScr_Unk_08669AE0[] =
{
    EvtListEnd
};

// EventListScr @ 08669AE4
EventListScr CONST_DATA EventListScr_Unk_08669AE4[] =
{
    EvtListTileMapChange(0, EventScr_Unk_08673DC4, 2, 17, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 2, 16, TILE_COMMAND_PILLAGE)
    EvtListTileMapChange(0, EventScr_Unk_08673E0C, 30, 2, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 30, 1, TILE_COMMAND_PILLAGE)
    EvtListShop(0, ShopItems_Unk_0866AA76, 3, 19, TILE_COMMAND_ARMORY)
    EvtListTile(0, EventScr_Unk_08673E54, 1, 18, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Unk_08673E90, 6, 15, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 29, 18, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 08669B48
EventListScr CONST_DATA EventListScr_Unk_08669B48[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 08669B58
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_08669B58 =
{
    .event_list_turn = EventListScr_Unk_08669A70,
    .event_list_talk = EventListScr_Unk_08669AE0,
    .event_list_tile = EventListScr_Unk_08669AE4,
    .event_list_move = EventListScr_Unk_08669B48,
    .units_red = UnitInfo_Unk_08682D60,
    .units_blue = UnitInfo_Unk_08682C70,
    .event_script_victory = EventScr_Unk_08673ECC,
};
