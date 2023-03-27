#pragma once

// EventListScr @ 08669B74
EventListScr CONST_DATA EventListScr_Unk_08669B74[] =
{
    EvtListTurn(0, EventScr_Unk_08673F24, 1, 0, FACTION_BLUE)
    EvtListFlag(FLAG_CHAPTER18S_6, EventScr_Unk_08673FD4, FLAG_CHAPTER18S_5)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086833B8, 10, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086833B8, 15, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086833B8, 20, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086833F8, 12, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086833F8, 17, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_086833F8, 22, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08683618, 13, 0, FACTION_RED)
    EvtListTurn(0, EventScr_LoadUnits_Unk_08683618, 23, 0, FACTION_RED)
    EvtListEnd
};

// EventListScr @ 08669BF0
EventListScr CONST_DATA EventListScr_Unk_08669BF0[] =
{
    EvtListEnd
};

// EventListScr @ 08669BF4
EventListScr CONST_DATA EventListScr_Unk_08669BF4[] =
{
    EvtListShop(0, ShopItems_Unk_0866AA98, 4, 3, TILE_COMMAND_ARMORY)
    EvtListShop(0, ShopItems_Unk_0866AAB0, 2, 3, TILE_COMMAND_VENDOR)
    EvtListTile(0, EventScr_Unk_086741D8, 8, 17, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Unk_08674214, 8, 21, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Unk_08674250, 12, 7, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Unk_0867428C, 15, 6, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 17, 19, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 08669C4C
EventListScr CONST_DATA EventListScr_Unk_08669C4C[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListArea(FLAG_CHAPTER18S_5, EventScr_Unk_08673FB0, 14, 15, 20, 15)
    EvtListArea(FLAG_CHAPTER18S_5, EventScr_Unk_08673FB0, 13, 16, 21, 22)
    EvtListArea(FLAG_CHAPTER18S_5, EventScr_Unk_08673FB0, 14, 23, 20, 23)
    EvtListEnd
};

// ChapterEventInfo @ 08669C80
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_08669C80 =
{
    .event_list_turn = EventListScr_Unk_08669B74,
    .event_list_talk = EventListScr_Unk_08669BF0,
    .event_list_tile = EventListScr_Unk_08669BF4,
    .event_list_move = EventListScr_Unk_08669C4C,
    .units_red = UnitInfo_Unk_086831B8,
    .units_blue = UnitInfo_Unk_086830B8,
    .event_script_victory = EventScr_Unk_086742C8,
};
