#pragma once

// EventListScr @ 08667D78
EventListScr CONST_DATA EventListScr_Unk_08667D78[] =
{
    EvtListTurn(0, EventScr_Unk_0866CE68, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_0866CF90, 2, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_0866CFD4, 3, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_0866D068, 9, 0, FACTION_GREEN)
    EvtListTurn(0, EventScr_Unk_0866D0A8, 10, 0, FACTION_GREEN)
    EvtListFlag(FLAG_CHAPTER7_5, EventScr_Unk_0866D0D0, FLAG_CHAPTER7_14)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867BA10, 15, 0, FACTION_RED)
    EvtListTurnHard(0, EventScr_LoadUnits_Unk_0867BA10, 20, 0, FACTION_RED)
    EvtListEnd
};

// EventListScr @ 08667DDC
EventListScr CONST_DATA EventListScr_Unk_08667DDC[] =
{
    EvtListTalk(FLAG_CHAPTER7_6, EventScr_Unk_0866D0F8, PID_ROY, PID_ZELOT)
    EvtListTalk(FLAG_CHAPTER7_6, EventScr_Unk_0866D1D4, PID_NOAH, PID_ZELOT)
    EvtListTalk(FLAG_CHAPTER7_6, EventScr_Unk_0866D208, PID_TREC, PID_ZELOT)
    EvtListTalk(FLAG_CHAPTER7_7, EventScr_Unk_0866D124, PID_ROY, PID_NOAH)
    EvtListTalk(FLAG_CHAPTER7_7, EventScr_Unk_0866D150, PID_ZELOT, PID_NOAH)
    EvtListTalk(FLAG_CHAPTER7_8, EventScr_Unk_0866D17C, PID_ZELOT, PID_TREC)
    EvtListTalk(FLAG_CHAPTER7_8, EventScr_Unk_0866D1A8, PID_ROY, PID_TREC)
    EvtListTalk(FLAG_CHAPTER7_9, EventScr_Unk_0866D23C, PID_ROY, PID_ZELOT)
    EvtListTalk(FLAG_CHAPTER7_9, EventScr_Unk_0866D23C, PID_ZELOT, PID_ROY)
    EvtListEnd
};

// EventListScr @ 08667E4C
EventListScr CONST_DATA EventListScr_Unk_08667E4C[] =
{
    EvtListTileMapChange(0, EventScr_Unk_0866D408, 19, 21, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 19, 20, TILE_COMMAND_PILLAGE)
    EvtListTileMapChange(0, EventScr_Unk_0866D258, 1, 18, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 1, 17, TILE_COMMAND_PILLAGE)
    EvtListTileMapChange(0, EventScr_Unk_0866D2A0, 1, 24, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 1, 23, TILE_COMMAND_PILLAGE)
    EvtListTileMapChange(0, EventScr_Unk_0866D2E8, 15, 15, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 15, 14, TILE_COMMAND_PILLAGE)
    EvtListTileMapChange(0, EventScr_Unk_0866D330, 13, 18, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 13, 17, TILE_COMMAND_PILLAGE)
    EvtListTileMapChange(0, EventScr_Unk_0866D378, 15, 21, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 15, 20, TILE_COMMAND_PILLAGE)
    EvtListTileMapChange(0, EventScr_Unk_0866D3C0, 13, 24, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 13, 23, TILE_COMMAND_PILLAGE)
    EvtListTileMapChange(0, EventScr_Unk_0866D450, 19, 15, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 19, 14, TILE_COMMAND_PILLAGE)
    EvtListChest(0, IID_RAPIER, 0, 18, 1, TILE_COMMAND_CHEST)
    EvtListChest(0, IID_BARRIERSTAFF, 0, 20, 1, TILE_COMMAND_CHEST)
    EvtListShop(0, ShopItems_Unk_0866A84E, 14, 10, TILE_COMMAND_ARMORY)
    EvtListShop(0, ShopItems_Unk_0866A85E, 19, 11, TILE_COMMAND_ARMORY)
    EvtListShop(0, ShopItems_Unk_0866A86C, 2, 12, TILE_COMMAND_VENDOR)
    EvtListDoor(0, EVENT_NOSCRIPT, 4, 8, TILE_COMMAND_DOOR)
    EvtListDoor(0, EVENT_NOSCRIPT, 5, 8, TILE_COMMAND_DOOR)
    EvtListDoor(0, EVENT_NOSCRIPT, 17, 3, TILE_COMMAND_DOOR)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 5, 1, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 08667F7C
EventListScr CONST_DATA EventListScr_Unk_08667F7C[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListArea(FLAG_CHAPTER7_14, EventScr_Unk_0866CF6C, 0, 0, 22, 6)
    EvtListArea(FLAG_CHAPTER7_14, EventScr_Unk_0866CF6C, 5, 7, 8, 7)
    EvtListEnd
};

// ChapterEventInfo @ 08667FA4
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_08667FA4 =
{
    .event_list_turn = EventListScr_Unk_08667D78,
    .event_list_talk = EventListScr_Unk_08667DDC,
    .event_list_tile = EventListScr_Unk_08667E4C,
    .event_list_move = EventListScr_Unk_08667F7C,
    .units_red = UnitInfo_Unk_0867B760,
    .units_blue = UnitInfo_Unk_0867B680,
    .event_script_victory = EventScr_Unk_0866D498,
};
