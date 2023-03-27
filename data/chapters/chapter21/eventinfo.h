#pragma once

// EventListScr @ 086691F8
EventListScr CONST_DATA EventListScr_Unk_086691F8[] =
{
    EvtListTurn(0, EventScr_Unk_08671B48, 1, 0, FACTION_BLUE)
    EvtListTurn(0, EventScr_Unk_08671E6C, 31, 0, FACTION_BLUE)
    EvtListFunc(FLAG_CHAPTER21_4, EventScr_Unk_08671C4C, func_fe6_0806ADC4)
    EvtListFunc(0, EventScr_Unk_08671CA8, func_fe6_0806ADDC)
    EvtListFunc(0, EventScr_Unk_08671D34, func_fe6_0806AE04)
    EvtListFunc(FLAG_CHAPTER21_11, EventScr_Unk_08671DC0, func_fe6_0806AE2C)
    EvtListFunc(0, EventScr_Unk_08671DD4, func_fe6_0806AE54)
    EvtListEnd
};

// EventListScr @ 08669250
EventListScr CONST_DATA EventListScr_Unk_08669250[] =
{
    EvtListTalk(FLAG_CHAPTER21_17, EventScr_Unk_08671EE0, PID_SAUL, PID_YODER)
    EvtListTalk(FLAG_CHAPTER21_17, EventScr_Unk_08671EE0, PID_YODER, PID_SAUL)
    EvtListTalk(FLAG_CHAPTER21_18, EventScr_Unk_08671EF4, PID_DOROTHY, PID_YODER)
    EvtListTalk(FLAG_CHAPTER21_18, EventScr_Unk_08671EF4, PID_YODER, PID_DOROTHY)
    EvtListTalk(FLAG_CHAPTER21_15, EventScr_Unk_08671EA0, PID_MELADY, PID_GALLE)
    EvtListTalk(FLAG_CHAPTER21_16, EventScr_Unk_08671EC0, PID_ZEISS, PID_GALLE)
    EvtListEnd
};

// EventListScr @ 0866929C
EventListScr CONST_DATA EventListScr_Unk_0866929C[] =
{
    EvtListShop(0, ShopItems_Unk_0866A99E, 5, 1, TILE_COMMAND_ARMORY)
    EvtListShop(0, ShopItems_Unk_0866A9B0, 9, 1, TILE_COMMAND_VENDOR)
    EvtListShop(0, ShopItems_Unk_0866A9C8, 30, 13, TILE_COMMAND_SECRET)
    EvtListTileMapChange(0, EventScr_Unk_08671F08, 11, 11, TILE_COMMAND_VISIT)
    EvtListTile(0, EVENT_NOSCRIPT, 11, 10, TILE_COMMAND_1D)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 24, 27, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 086692E8
EventListScr CONST_DATA EventListScr_Unk_086692E8[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 086692F8
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_086692F8 =
{
    .event_list_turn = EventListScr_Unk_086691F8,
    .event_list_talk = EventListScr_Unk_08669250,
    .event_list_tile = EventListScr_Unk_0866929C,
    .event_list_move = EventListScr_Unk_086692E8,
    .units_red = UnitInfo_Unk_08680454,
    .units_blue = UnitInfo_Unk_08680324,
    .event_script_victory = EventScr_Unk_08671F50,
};
