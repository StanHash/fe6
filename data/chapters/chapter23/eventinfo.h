#pragma once

// EventListScr @ 086694D8
EventListScr CONST_DATA EventListScr_Unk_086694D8[] =
{
    EvtListTurn(0, EventScr_Unk_08672560, 1, 0, FACTION_BLUE)
    EvtListTurn(FLAG_CHAPTER23_4, EventScr_Unk_08672638, 1, 0, FACTION_RED)
    EvtListEnd
};

// EventListScr @ 086694F4
EventListScr CONST_DATA EventListScr_Unk_086694F4[] =
{
    EvtListTalk(FLAG_CHAPTER23_5, EventScr_Unk_0867276C, PID_FIR, PID_KAREL)
    EvtListTalk(FLAG_CHAPTER23_5, EventScr_Unk_0867276C, PID_KAREL, PID_FIR)
    EvtListTalk(FLAG_CHAPTER23_6, EventScr_Unk_08672788, PID_BARTRE, PID_KAREL)
    EvtListTalk(FLAG_CHAPTER23_6, EventScr_Unk_08672788, PID_KAREL, PID_BARTRE)
    EvtListTalk(FLAG_CHAPTER23_7, EventScr_Unk_086727A4, PID_ROY, PID_KAREL)
    EvtListTalk(FLAG_CHAPTER23_7, EventScr_Unk_086727A4, PID_KAREL, PID_ROY)
    EvtListEnd
};

// EventListScr @ 08669540
EventListScr CONST_DATA EventListScr_Unk_08669540[] =
{
    EvtListShop(0, ShopItems_Unk_0866A9EC, 16, 26, TILE_COMMAND_ARMORY)
    EvtListShop(0, ShopItems_Unk_0866AA12, 17, 25, TILE_COMMAND_ARMORY)
    EvtListShop(0, ShopItems_Unk_0866AA2A, 0, 6, TILE_COMMAND_VENDOR)
    EvtListShop(0, ShopItems_Unk_0866AA3C, 15, 26, TILE_COMMAND_VENDOR)
    EvtListTile(0, EventScr_Unk_08672684, 22, 23, TILE_COMMAND_VISIT)
    EvtListTile(FLAG_3, EVENT_NOSCRIPT, 5, 1, TILE_COMMAND_SEIZE)
    EvtListEnd
};

// EventListScr @ 0866958C
EventListScr CONST_DATA EventListScr_Unk_0866958C[] =
{
    EvtListFlag(0, EventScr_GameOver, FLAG_101)
    EvtListEnd
};

// ChapterEventInfo @ 0866959C
struct ChapterEventInfo CONST_DATA ChapterEventInfo_Unk_0866959C =
{
    .event_list_turn = EventListScr_Unk_086694D8,
    .event_list_talk = EventListScr_Unk_086694F4,
    .event_list_tile = EventListScr_Unk_08669540,
    .event_list_move = EventListScr_Unk_0866958C,
    .units_red = UnitInfo_Unk_086815C0,
    .units_blue = UnitInfo_Unk_086814B0,
    .event_script_victory = EventScr_Unk_086727C0,
};
