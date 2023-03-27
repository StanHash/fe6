#pragma once

// EventListScr @ 086677BC
EventListScr CONST_DATA EventListScr_Unk_086677BC[] =
{
    EvtListTurn(0, EventScr_Unk_0866B9D0, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_0866BBD0, 2, 0, FACTION_BLUE)
    EvtListEnd
};

// EventListScr @ 086677D8
EventListScr CONST_DATA EventListScr_Unk_086677D8[] =
{
    EvtListTalk(FLAG_CHAPTER2_5, EventScr_Unk_0866BCA0, PID_ROY, PID_DIECK)
    EvtListTalk(FLAG_CHAPTER2_5, EventScr_Unk_0866BCA0, PID_DIECK, PID_ROY)
    EvtListEnd
};

// EventListScr @ 086677F4
EventListScr CONST_DATA EventListScr_Unk_086677F4[] =
{
    EvtListShop(0, ShopItems_Unk_0866A81C, 7, 9, TILE_COMMAND_VENDOR)
    EvtListShop(0, ShopItems_Unk_0866A820, 6, 1, TILE_COMMAND_ARMORY)
    EvtListTileMapChange(0, EventScr_Unk_0866BD08, 3, 4, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 3, 3, TILE_COMMAND_1D)
    EvtListTile(0, EventScr_Unk_0866BD50, 6, 7, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Unk_0866BD8C, 0, 4, TILE_COMMAND_VISIT)
    EvtListTile(0, EventScr_Unk_0866BDC8, 5, 7, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 16, 3, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 08667858
EventListScr CONST_DATA EventListScr_Unk_08667858[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 08667868
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_08667868 =
{
    .event_list_turn = EventListScr_Unk_086677BC,
    .event_list_talk = EventListScr_Unk_086677D8,
    .event_list_tile = EventListScr_Unk_086677F4,
    .event_list_move = EventListScr_Unk_08667858,
    .units_red = UnitInfo_Unk_08679E7C,
    .units_blue = UnitInfo_Unk_08679DEC,
    .event_script_victory = EventScr_Unk_0866BE04,
};
