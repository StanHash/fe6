#include "eventinfo.h"

#include "sound.h"
#include "event.h"
#include "eventscript.h"
#include "bm.h"
#include "item.h"
#include "unit.h"
#include "map.h"
#include "unitsprite.h"
#include "battle.h"
#include "faction.h"
#include "chapterinfo.h"
#include "support.h"
#include "trap.h"

#include "constants/iids.h"
#include "constants/chapters.h"
#include "constants/pids.h"
#include "constants/songs.h"

// TODO: move elsewhere (macros shared with event.c)
#define EVT_CMD_LO(cmd) (((cmd) & 0x0000FFFF))
#define EVT_CMD_HI(cmd) (((cmd) & 0xFFFF0000) >> 16)
#define EVT_CMD_B1(cmd) (((cmd) & 0x000000FF))
#define EVT_CMD_B2(cmd) (((cmd) & 0x0000FF00) >> 8)
#define EVT_CMD_B3(cmd) (((cmd) & 0x00FF0000) >> 16)
#define EVT_CMD_B4(cmd) (((cmd) & 0xFF000000) >> 24)

// TODO: move elsewhere (probably events.h?)
extern EventListScr CONST_DATA EventListScr_Tutorial_ActionSelect[];
extern struct SupportTalkEnt CONST_DATA gSupportTalkList[];
extern struct BattleTalkExtEnt CONST_DATA gBattleTalkExtList[];
extern struct BattleTalkEnt CONST_DATA gBattleTalkList[];
extern struct BattleTalkEnt CONST_DATA gTriangleAttackTalkList[];
extern struct BattleTalkEnt CONST_DATA gBattleDefeatTalkList[];
extern EventScr CONST_DATA EventScr_0866AAF8[];

struct EventListCmdInfo
{
    /* 00 */ int (* func)(struct EventInfo * info);
    /* 04 */ int length;
};

struct EventListCmdInfo CONST_DATA gEventListCmdInfoTable[] =
{
    [EVT_LIST_CMD_END]            = { EvtListCmd_End, 1 },
    [EVT_LIST_CMD_FLAG]           = { EvtListCmd_Flag, 3 },
    [EVT_LIST_CMD_TURN]           = { EvtListCmd_Turn, 3 },
    [EVT_LIST_CMD_TURN_HARD]      = { EvtListCmd_TurnHard, 3 },
    [EVT_LIST_CMD_TALK]           = { EvtListCmd_Talk, 3 },
    [EVT_LIST_CMD_TILE]           = { EvtListCmd_Tile, 3 },
    [EVT_LIST_CMD_TILE_MAPCHANGE] = { EvtListCmd_TileWithMapChange, 3 },
    [EVT_LIST_CMD_ITEM]           = { EvtListCmd_ItemChest, 3 },
    [EVT_LIST_CMD_DOOR]           = { EvtListCmd_Door, 3 },
    [EVT_LIST_CMD_DRAWBRIDGE]     = { EvtListCmd_Drawbridge, 3 },
    [EVT_LIST_CMD_SHOP]           = { EvtListCmd_Shop, 3 },
    [EVT_LIST_CMD_AREA]           = { EvtListCmd_Area, 3 },
    [EVT_LIST_CMD_AREA_HARD]      = { EvtListCmd_AreaHard, 3 },
    [EVT_LIST_CMD_FUNC]           = { EvtListCmd_Func, 3 },
};

void StartEventFromInfo(struct EventInfo const * info)
{
    if (info->script == NULL)
        return;

    SetFlag(info->flag);

    if ((int) info->script != EVENT_NOSCRIPT)
        StartEvent(info->script);
}

struct EventInfo * SearchAvailableEvent(struct EventInfo * info)
{
    info->script = NULL;
    info->flag = 0;

    for (;;)
    {
        int cmdid = EVT_CMD_LO(info->list_script[0]);

        if (!CheckFlag(EVT_CMD_HI(info->list_script[0])))
        {
            if (gEventListCmdInfoTable[cmdid].func(info) == TRUE)
            {
                if (info->script != NULL)
                    return info;

                break;
            }
        }

        info->list_script += gEventListCmdInfoTable[cmdid].length;
    }

    return NULL;
}

struct EventInfo * SearchNextAvailableEvent(struct EventInfo * info)
{
    int cmdid;

    if (info == NULL)
        return NULL;

    cmdid = EVT_CMD_LO(info->list_script[0]);
    info->list_script += gEventListCmdInfoTable[cmdid].length;

#if BUGFIX
    return SearchAvailableEvent(info);
#else
    SearchAvailableEvent(info);
#endif
}

int EvtListCmd_End(struct EventInfo * info)
{
    return TRUE;
}

int EvtListCmd_Flag(struct EventInfo * info)
{
    if (CheckFlag(EVT_CMD_LO(info->list_script[2])))
    {
        info->script = (void const *) info->list_script[1];
        info->flag = EVT_CMD_HI(info->list_script[0]);

        return TRUE;
    }

    return FALSE;
}

int EvtListCmd_Turn(struct EventInfo * info)
{
    int turn = EVT_CMD_B1(info->list_script[2]);
    int turn_max = EVT_CMD_B2(info->list_script[2]);
    int faction = EVT_CMD_B3(info->list_script[2]);

    if (turn_max == 0)
    {
        if ((gPlaySt.turn == turn) && (gPlaySt.faction == faction))
        {
            info->script = (void const *) info->list_script[1];
            info->flag = EVT_CMD_HI(info->list_script[0]);

            return TRUE;
        }
    }
    else
    {
        if ((gPlaySt.turn >= turn && gPlaySt.turn <= turn_max) && (gPlaySt.faction == faction))
        {
            info->script = (void const *) info->list_script[1];
            info->flag = EVT_CMD_HI(info->list_script[0]);

            return TRUE;
        }
    }

    return FALSE;
}

int EvtListCmd_TurnHard(struct EventInfo * info)
{
    if (!(gPlaySt.flags & PLAY_FLAG_HARD))
        return FALSE;

    if (CheckFlag(2)) // TODO: flag ids
        return FALSE;

    return EvtListCmd_Turn(info);
}

int EvtListCmd_Talk(struct EventInfo * info)
{
    int pid_a = EVT_CMD_B1(info->list_script[2]);
    int pid_b = EVT_CMD_B2(info->list_script[2]);

    if (info->pid_a == pid_a && info->pid_b == pid_b)
    {
        info->script = (void const *) info->list_script[1];
        info->flag = EVT_CMD_HI(info->list_script[0]);

        return TRUE;
    }

    return FALSE;
}

int EvtListCmd_Tile(struct EventInfo * info)
{
    int x = EVT_CMD_B1(info->list_script[2]);
    int y = EVT_CMD_B2(info->list_script[2]);
    int tile_command = EVT_CMD_B3(info->list_script[2]);

    info->given_money = 0;

    if (x == info->x_location && y == info->y_location)
    {
        info->script = (void const *) info->list_script[1];
        info->flag = EVT_CMD_HI(info->list_script[0]);
        info->tile_command = tile_command;

        if (tile_command == TILE_COMMAND_CHEST)
            info->given_iid = 0;

        return TRUE;
    }

    return FALSE;
}

int EvtListCmd_TileWithMapChange(struct EventInfo * info)
{
    int result = EvtListCmd_Tile(info);
    info->given_money = 3; // TODO: named constant
    return result;
}

int EvtListCmd_ItemChest(struct EventInfo * info)
{
    int x = EVT_CMD_B1(info->list_script[2]);
    int y = EVT_CMD_B2(info->list_script[2]);
    int tile_command = EVT_CMD_B3(info->list_script[2]);
    int unk_d = EVT_CMD_B4(info->list_script[2]);

    if (x == info->x_location && y == info->y_location)
    {
        info->script = (void const *) EVENT_NOSCRIPT;
        info->flag = EVT_CMD_HI(info->list_script[0]);
        info->tile_command = tile_command;
        info->given_money = unk_d;
        info->given_iid = EVT_CMD_LO(info->list_script[1]);
        info->given_money = EVT_CMD_HI(info->list_script[1]);

        return TRUE;
    }

    return FALSE;
}

int EvtListCmd_Door(struct EventInfo * info)
{
    int x = EVT_CMD_B1(info->list_script[2]);
    int y = EVT_CMD_B2(info->list_script[2]);
    int tile_command = EVT_CMD_B3(info->list_script[2]);
    int unk_d = EVT_CMD_B4(info->list_script[2]);

    if (x == info->x_location && y == info->y_location)
    {
        info->script = (void const *) info->list_script[1];
#if !NONMATCHING
        asm("":::"memory");
#endif
        info->flag = EVT_CMD_HI(info->list_script[0]);
        info->tile_command = tile_command;
        info->given_money = unk_d;

        return TRUE;
    }

    return FALSE;
}

int EvtListCmd_Drawbridge(struct EventInfo * info)
{
    int x = EVT_CMD_B1(info->list_script[2]);
    int y = EVT_CMD_B2(info->list_script[2]);
    int tile_command = EVT_CMD_B3(info->list_script[2]);
    int unk_d = EVT_CMD_B4(info->list_script[2]);

    if (x == info->x_location && y == info->y_location)
    {
        info->script = (void const *) info->list_script[1];
#if !NONMATCHING
        asm("":::"memory");
#endif
        info->flag = EVT_CMD_HI(info->list_script[0]);
        info->tile_command = tile_command;
        info->given_money = unk_d;

        return TRUE;
    }

    return FALSE;
}

int EvtListCmd_Shop(struct EventInfo * info)
{
    int x = EVT_CMD_B1(info->list_script[2]);
    int y = EVT_CMD_B2(info->list_script[2]);
    int tile_command = EVT_CMD_B3(info->list_script[2]);

    if (x == info->x_location && y == info->y_location)
    {
        if (tile_command != TILE_COMMAND_SECRET || FindUnitItemSlot(gActiveUnit, IID_MEMBERCARD) != -1)
        {
            info->script = (void const *) info->list_script[1];
            info->flag = EVT_CMD_HI(info->list_script[0]);
            info->tile_command = tile_command;

            return TRUE;
        }
    }

    return FALSE;
}

int EvtListCmd_Area(struct EventInfo * info)
{
    fi8 x = gActiveUnit->x;
    fi8 y = gActiveUnit->y;

    fi8 x1 = (i8) EVT_CMD_B1(info->list_script[2]);
    fi8 y1 = (i8) EVT_CMD_B2(info->list_script[2]);
    fi8 x2 = (i8) EVT_CMD_B3(info->list_script[2]);
    fi8 y2 = (i8) EVT_CMD_B4(info->list_script[2]);

    if (x1 <= x && y1 <= y && x2 >= x && y2 >= y)
    {
        info->script = (void const *) info->list_script[1];
        info->flag = EVT_CMD_HI(info->list_script[0]);

        return TRUE;
    }

    return FALSE;
}

int EvtListCmd_AreaHard(struct EventInfo * info)
{
    if (!(gPlaySt.flags & PLAY_FLAG_HARD))
        return FALSE;

    if (CheckFlag(2)) // TODO: flag ids
        return FALSE;

    return EvtListCmd_Area(info);
}

int EvtListCmd_Func(struct EventInfo * info)
{
    bool (* func)(struct EventInfo * info) = (void const *) info->list_script[2];

    if (func(info))
    {
        info->script = (void const *) info->list_script[1];
        info->flag = EVT_CMD_HI(info->list_script[0]);

        return TRUE;
    }

    return FALSE;
}

int EventInfoCheckTalk(struct EventInfo * info, fu8 pid_a, fu8 pid_b)
{
    if (info->pid_a == pid_a && info->pid_b == pid_b)
    {
        info->script = (void const *) info->list_script[1];
        info->flag = EVT_CMD_HI(info->list_script[0]);

        return TRUE;
    }

    return FALSE;
}

int CheckActiveUnitArea(int x1, int y1, int x2, int y2)
{
    if (gActiveUnit->x >= x1 && gActiveUnit->x <= x2 && gActiveUnit->y >= y1 && gActiveUnit->y <= y2)
    {
        return TRUE;
    }

    return FALSE;
}

bool CheckAnyBlueUnitArea(int x1, int y1, int x2, int y2)
{
    FOR_UNITS_FACTION(FACTION_BLUE, unit,
    {
        if (unit->flags & UNIT_FLAG_DEAD)
            continue;

        if (unit->x >= x1 && unit->x <= x2 && unit->y >= y1 && unit->y <= y2)
        {
            return TRUE;
        }
    })

    return FALSE;
}

bool func_fe6_0806AD48(struct EventInfo * info)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    if (CheckAnyBlueUnitArea(0, 15, 25, 23))
        return FALSE;

    return TRUE;
}

bool func_fe6_0806AD74(struct EventInfo * info)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    if (CheckAnyBlueUnitArea(0, 24, 16, 27))
        return TRUE;

    if (CheckAnyBlueUnitArea(0, 21, 2, 23))
        return TRUE;

    if (CheckAnyBlueUnitArea(3, 20, 5, 22))
        return TRUE;

    return FALSE;
}

bool func_fe6_0806ADC4(struct EventInfo * info)
{
    return CheckAnyBlueUnitArea(12, 21, 31, 24);
}

bool func_fe6_0806ADDC(struct EventInfo * info)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    return CheckAnyBlueUnitArea(17, 21, 31, 35);
}

bool func_fe6_0806AE04(struct EventInfo * info)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    return CheckAnyBlueUnitArea(0, 15, 8, 18);
}

bool func_fe6_0806AE2C(struct EventInfo * info)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    return CheckAnyBlueUnitArea(0, 24, 12, 27);
}

bool func_fe6_0806AE54(struct EventInfo * info)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    return CheckAnyBlueUnitArea(21, 0, 30, 6);
}

bool func_fe6_0806AE7C(int x1, int y1, int x2, int y2)
{
    FOR_UNITS_FACTION(FACTION_RED, unit,
    {
        if (unit->flags & UNIT_FLAG_DEAD)
            continue;

        if (unit->x >= x1 && unit->x <= x2 && unit->y >= y1 && unit->y <= y2)
        {
            return TRUE;
        }
    })

    return FALSE;
}

bool CheckAvailableTurnEvent(void)
{
    struct EventInfo info;

    info.list_script = GetChapterEventInfo(gPlaySt.chapter)->event_list_turn;

    if (SearchAvailableEvent(&info))
    {
        return TRUE;
    }

    return FALSE;
}

void StartAvailableTurnEvents(void)
{
    struct EventInfo info;

    info.list_script = GetChapterEventInfo(gPlaySt.chapter)->event_list_turn;

    if (SearchAvailableEvent(&info))
    {
        StartEventFromInfo(&info);

        while (SearchNextAvailableEvent(&info) != NULL)
        {
            StartEventFromInfo(&info);
        }
    }
}

bool CheckAvailableTalkEvent(fu8 pid_a, fu8 pid_b)
{
    struct EventInfo info;

    info.list_script = GetChapterEventInfo(gPlaySt.chapter)->event_list_talk;
    info.pid_a = pid_a;
    info.pid_b = pid_b;

    if (SearchAvailableEvent(&info))
    {
        return TRUE;
    }

    return FALSE;
}

void StartAvailableTalkEvent(fu8 pid_a, fu8 pid_b)
{
    struct EventInfo info;

    info.list_script = GetChapterEventInfo(gPlaySt.chapter)->event_list_talk;
    info.pid_a = pid_a;
    info.pid_b = pid_b;

    if (SearchAvailableEvent(&info))
    {
        StartEventFromInfo(&info);
    }
}

void StartAvailableSupportEvent(fu8 pid_a, fu8 pid_b, int support_level)
{
    int msg = 0;

    struct SupportTalkEnt const * it = gSupportTalkList;

    while (it->pid_a != 0)
    {
        if ((it->pid_a == pid_a && it->pid_b == pid_b) || (it->pid_b == pid_a && it->pid_a == pid_b))
        {
            if (support_level == SUPPORT_LEVEL_C)
                msg = it->msg_talk_c;

            if (support_level == SUPPORT_LEVEL_B)
                msg = it->msg_talk_b;

            if (support_level == SUPPORT_LEVEL_A)
                msg = it->msg_talk_a;

            break;
        }

        ++it;
    }

    if (msg != 0)
    {
        StartTalkSupportEvent(msg);
        DisableEventSkip();
    }
}

int GetAvailableTileEventCommand(fi8 x, fi8 y)
{
    struct EventInfo info;

    info.list_script = GetChapterEventInfo(gPlaySt.chapter)->event_list_tile;
    info.x_location = x;
    info.y_location = y;

    if (!SearchAvailableEvent(&info))
    {
        return TILE_COMMAND_NONE;
    }

    return info.tile_command;
}

void StartAvailableTileEvent(fi8 x, fi8 y)
{
    struct EventInfo info;

    info.list_script = GetChapterEventInfo(gPlaySt.chapter)->event_list_tile;
    info.x_location = x;
    info.y_location = y;

    if (SearchAvailableEvent(&info) == NULL)
        return;

    switch (info.tile_command)
    {
        case TILE_COMMAND_VISIT:
        case TILE_COMMAND_SEIZE:
            StartEventFromInfo(&info);

            if (info.given_money != 3) // TODO: constant
                return;

            // fallthrough

        case TILE_COMMAND_1D:
            StartMapChangeEvent(GetMapChangeIdAt(info.x_location, info.y_location));
            DisableEventSkip();
            return;

        case TILE_COMMAND_DOOR:
        case TILE_COMMAND_BRIDGE:
            if ((int) info.script == EVENT_NOSCRIPT)
            {
                StartMapChangeEvent(GetMapChangeIdAt(info.x_location, info.y_location));
                SetFlag(info.flag);
            }
            else
            {
                StartEventFromInfo(&info);
            }

            DisableEventSkip();
            return;

        case TILE_COMMAND_CHEST:
            if (info.given_iid == 0)
            {
                StartMapChangeEvent(GetMapChangeIdAt(info.x_location, info.y_location));
                StartEventFromInfo(&info);
            }
            else
            {
                if (info.given_iid != IID_GOLD)
                {
                    StartChestItemEvent(info.given_iid, GetMapChangeIdAt(info.x_location, info.y_location));
                }
                else
                {
                    StartChestMoneyEvent(info.given_money, GetMapChangeIdAt(info.x_location, info.y_location));
                }
            }

            DisableEventSkip();
            SetFlag(info.flag);
            return;

        case TILE_COMMAND_ARMORY:
            func_fe6_08095E10(gActiveUnit, info.script);
            return;

        case TILE_COMMAND_VENDOR:
            func_fe6_08095E30(gActiveUnit, info.script);
            return;

        case TILE_COMMAND_SECRET:
            func_fe6_08095E50(gActiveUnit, info.script);
            return;

#if !NONMATCHING
        case TILE_COMMAND_SHOP_UNK:
            asm("nop");
            return;

        case TILE_COMMAND_NONE:
            asm("nop");
            return;
#endif
    }
}

void StartAvailableTileEvent_Unused(fi8 x, fi8 y)
{
    StartAvailableTileEvent(x, y);
}

bool CheckAvailableVisitTileEvent(fi8 x, fi8 y)
{
    if (GetAvailableTileEventCommand(x, y) == TILE_COMMAND_VISIT)
        return TRUE;

    return FALSE;
}

void StartAvailableVisitTileEvent(fi8 x, fi8 y)
{
    if (CheckAvailableVisitTileEvent(x, y))
    {
        StartAvailableTileEvent(x, y);
    }
}

bool CheckAvailableShopTileEvent(fi8 x, fi8 y)
{
    if (GetAvailableTileEventCommand(x, y) == TILE_COMMAND_ARMORY)
        return TRUE;

    if (GetAvailableTileEventCommand(x, y) == TILE_COMMAND_VENDOR)
        return TRUE;

    if ((GetAvailableTileEventCommand(x, y) == TILE_COMMAND_SECRET) && FindUnitItemSlot(gActiveUnit, IID_MEMBERCARD) != -1)
        return TRUE;

    if (GetAvailableTileEventCommand(x, y) == TILE_COMMAND_SHOP_UNK)
        return TRUE;

    return FALSE;
}

void StartAvailableShopTileEvent(fi8 x, fi8 y)
{
    if (CheckAvailableShopTileEvent(x, y))
    {
        StartAvailableTileEvent(x, y);
    }
}

bool CheckAvailableChestTileEvent(fi8 x, fi8 y)
{
    if (GetAvailableTileEventCommand(x, y) == TILE_COMMAND_CHEST)
        return TRUE;

    return FALSE;
}

void StartAvailableChestTileEvent(fi8 x, fi8 y)
{
    if (CheckAvailableChestTileEvent(x, y))
    {
        StartAvailableTileEvent(x, y);
    }
}

bool CheckAvailableDoorTileEvent(fi8 x, fi8 y)
{
    if (GetAvailableTileEventCommand(x, y) == TILE_COMMAND_DOOR)
        return TRUE;

    return FALSE;
}

void StartAvailableDoorTileEvent(fi8 x, fi8 y)
{
    if (CheckAvailableDoorTileEvent(x, y))
    {
        StartAvailableTileEvent(x, y);
    }
}

bool CheckAvailableBridgeTileEvent(fi8 x, fi8 y)
{
    if (GetAvailableTileEventCommand(x, y) == TILE_COMMAND_BRIDGE)
        return TRUE;

    return FALSE;
}

void StartAvailableBridgeTileEvent(fi8 x, fi8 y)
{
    if (CheckAvailableBridgeTileEvent(x, y))
    {
        StartAvailableTileEvent(x, y);
    }
}

bool CheckAvailableVictoryEvent(void)
{
    return CheckChapterVictory();
}

void StartAvailableVictoryEvent(void)
{
    StartChapterVictoryEvent();
}

bool StartAvailableMoveSelectEvent(void)
{
    if (gPlaySt.chapter == CHAPTER_TUTORIAL)
        func_fe6_0806C6B0();

    return FALSE;
}

bool CheckAvailableActionSelectEvent(void)
{
    struct EventInfo info;

    info.list_script = EventListScr_Tutorial_ActionSelect;

    if (gPlaySt.chapter == CHAPTER_TUTORIAL && SearchAvailableEvent(&info) != NULL)
        return TRUE;

    return FALSE;
}

bool StartAvailableActionSelectEvent(void)
{
    struct EventInfo info;

    info.list_script = EventListScr_Tutorial_ActionSelect;

    if (gPlaySt.chapter == CHAPTER_TUTORIAL && SearchAvailableEvent(&info) != NULL)
    {
        StartEventFromInfo(&info);
#if BUGFIX
        return TRUE;
#endif
    }

    return FALSE;
}

bool CheckAvailableMoveSelectConfirmEvent(void)
{
    return FALSE;
}

bool StartAvailableMoveSelectConfirmEvent(void)
{
    return FALSE;
}

bool StartAvailableAttackMenuEvent(void)
{
    if (gPlaySt.chapter == CHAPTER_TUTORIAL)
    {
        func_fe6_0806C718();
    }

    return FALSE;
}

bool StartAvailableAttackMenuItemEvent(void)
{
    if (gPlaySt.chapter == CHAPTER_TUTORIAL)
    {
        func_fe6_0806C734();
    }

    return FALSE;
}

bool StartAvailableMapMenuEvent(void)
{
    if (gPlaySt.chapter == CHAPTER_TUTORIAL)
    {
        func_fe6_0806C750();
    }

    return FALSE;
}

bool CheckAvailableMoveEvent(void)
{
    struct EventInfo info;

    info.list_script = GetChapterEventInfo(gPlaySt.chapter)->event_list_move;
    info.x_location = gActiveUnit->x;
    info.y_location = gActiveUnit->y;

    if (SearchAvailableEvent(&info) != NULL)
        return TRUE;

    return FALSE;
}

void StartAvailableMoveEvent(void)
{
    struct EventInfo info;

    info.list_script = GetChapterEventInfo(gPlaySt.chapter)->event_list_move;
    info.x_location = gActiveUnit->x;
    info.y_location = gActiveUnit->y;

    if (SearchAvailableEvent(&info) != NULL)
    {
        StartEventFromInfo(&info);
    }
}

bool CheckChapterVictory(void)
{
    if (gPlaySt.chapter == CHAPTER_UNK_19 && CheckFlag(0x72)) // TODO: flag constants
        SetFlag(3); // TODO: flag constants

    return CheckFlag(3); // TODO: flag constants
}

void StartChapterVictoryEvent(void)
{
    if (CheckFlag(3)) // TODO: flag constants
    {
        if (gPlaySt.chapter == CHAPTER_UNK_19)
        {
            if (func_fe6_0806CD78())
                StartEvent(GetChapterEventInfo(gPlaySt.chapter)->script_18);
        }
        else
        {
            if (CheckAvailableVictoryEvent())
                StartEvent(GetChapterEventInfo(gPlaySt.chapter)->script_18);
        }
    }
}

void CreateInitialRedUnits(void)
{
    struct EventInfo info;

    info.script = GetChapterEventInfo(gPlaySt.chapter)->units_red;
    info.flag = 0;

    BatchCreateUnits(info.script);
    ApplyAllHardModeBonusLevels();

    RefreshEntityMaps();
    RefreshUnitSprites();
}

struct UnitInfo const * GetDeployUnitInfoList(void)
{
    return GetChapterEventInfo(gPlaySt.chapter)->units_blue;
}

struct BattleTalkEnt const * GetAvailableBattleTalkExt(fu8 pid_a, fu8 pid_b)
{
    struct BattleTalkExtEnt const * it;

    STATIC_ASSERT(offsetof(struct BattleTalkExtEnt, msg)  == offsetof(struct BattleTalkEnt, msg));
    STATIC_ASSERT(offsetof(struct BattleTalkExtEnt, flag) == offsetof(struct BattleTalkEnt, flag));

    for (it = gBattleTalkExtList; it->pid_b != 0; it++)
    {
        if (CheckFlag(it->flag))
            continue;

        if ((pid_a == it->pid_a && pid_b == it->pid_b) || (pid_a == it->pid_b && pid_b == it->pid_a))
        {
            if (it->chapter == CHAPTER_COUNT)
                return (struct BattleTalkEnt const *) it;

            if (gPlaySt.chapter == it->chapter)
                return (struct BattleTalkEnt const *) it;
        }
    }

    return NULL;
}

struct BattleTalkEnt const * GetAvailableBattleTalk(fu8 pid, struct BattleTalkEnt const * it)
{
    for (; it->pid != 0; it++)
    {
        if (CheckFlag(it->flag))
            continue;

        if (pid == it->pid)
        {
            if (it->chapter == CHAPTER_COUNT)
                return it;

            if (gPlaySt.chapter == it->chapter)
                return it;
        }
    }

    return NULL;
}

bool CheckBattleTalk(fu8 pid_a, fu8 pid_b)
{
    if (GetAvailableBattleTalkExt(pid_a, pid_b) != NULL)
        return TRUE;

    if (GetAvailableBattleTalk(pid_a, gBattleTalkList) != NULL)
        return TRUE;

    if (GetAvailableBattleTalk(pid_b, gBattleTalkList) != NULL)
        return TRUE;

    if (GetAvailableBattleTalk(pid_a, gTriangleAttackTalkList) != NULL && BattleIsTriangleAttack())
        return TRUE;

    return FALSE;
}

void StartBattleTalk(fu8 pid_a, fu8 pid_b)
{
    struct BattleTalkEnt const * ent;

    ent = GetAvailableBattleTalkExt(pid_a, pid_b);

    if (ent != NULL)
    {
        StartTalkEvent(ent->msg);
        DisableEventSkip();
        SetFlag(ent->flag);
        return;
    }

    ent = GetAvailableBattleTalk(pid_a, gBattleTalkList);

    if (ent != NULL)
    {
        StartTalkEvent(ent->msg);
        DisableEventSkip();
        SetFlag(ent->flag);
        return;
    }

    ent = GetAvailableBattleTalk(pid_b, gBattleTalkList);

    if (ent != NULL)
    {
        StartTalkEvent(ent->msg);
        DisableEventSkip();
        SetFlag(ent->flag);
        return;
    }

    if ((ent = GetAvailableBattleTalk(pid_a, gTriangleAttackTalkList)) != NULL && BattleIsTriangleAttack())
    {
        StartTalkEvent(ent->msg);
        DisableEventSkip();
        SetFlag(ent->flag);
        return;
    }
}

bool CheckBattleDefeatTalk(fu8 pid)
{
    if (GetAvailableBattleTalk(pid, gBattleDefeatTalkList) != NULL)
        return TRUE;

    if (pid == PID_ROY)
        return TRUE;

    return FALSE;
}

void StartBattleDefeatTalk(fu8 pid)
{
    struct BattleTalkEnt const * ent;

    ent = GetAvailableBattleTalk(pid, gBattleDefeatTalkList);

    if (ent != NULL)
    {
        if (ent->msg != 0)
            StartTalkEvent(ent->msg);

        DisableEventSkip();
        SetFlag(ent->flag);

        if (UNIT_FACTION(GetUnitByPid(pid)) == FACTION_BLUE)
            StartBgm(SONG_45, NULL);
    }

    if (gPlaySt.chapter == CHAPTER_UNK_19 && pid == PID_66)
        FadeBgmOut(4);

    if (pid == PID_ROY)
    {
        SetFlag(0x65); // TODO: flag constants

        if (gPlaySt.chapter != CHAPTER_TUTORIAL)
        {
            StartEvent(EventScr_0866AAF8);
            StartBgm(SONG_37, NULL);
        }

        gPlaySt.config_bgm_disable = TRUE;
    }
}

bool func_fe6_0806B898(void)
{
    return FALSE;
}

void func_fe6_0806B89C(void)
{
}

void func_fe6_0806B8A0(void)
{
}

bool func_fe6_0806B8A4(void)
{
    return FALSE;
}

void func_fe6_0806B8A8(void)
{
}

bool func_fe6_0806B8AC(void)
{
    return FALSE;
}

bool func_fe6_0806B8B0(void)
{
    return FALSE;
}

void func_fe6_0806B8B4(void)
{
}

void func_fe6_0806B8B8(void)
{
}

void func_fe6_0806B8BC(void)
{
}

void func_fe6_0806B8C0(void)
{
}

void func_fe6_0806B8C4(void)
{
}

u8 CONST_DATA gFlagBitMaskLut[] =
{
    1 << 0, 1 << 1, 1 << 2, 1 << 3,
    1 << 4, 1 << 5, 1 << 6, 1 << 7,
};

void SetChapterFlag(int flag)
{
    if (flag == 0)
        return;

    flag = flag - 1;

    gChapterFlagBits[flag / CHAR_BIT] |= gFlagBitMaskLut[flag % CHAR_BIT];
}

bool CheckChapterFlag(int flag)
{
    if (flag == 0)
        return FALSE;

    flag = flag - 1;

    if ((gChapterFlagBits[flag / CHAR_BIT] & gFlagBitMaskLut[flag % CHAR_BIT]) != 0)
        return TRUE;

    return FALSE;
}

void ClearChapterFlag(int flag)
{
    fu8 mask;

    if (flag == 0)
        return;

    flag = flag - 1;

    mask = ~gFlagBitMaskLut[flag % CHAR_BIT];
    gChapterFlagBits[flag / CHAR_BIT] = mask & gChapterFlagBits[flag / CHAR_BIT];
}

void ResetChapterFlags(void)
{
    int i;

    for (i = 0; i < (MAX_CHAPTER_FLAGS + CHAR_BIT - 1) / CHAR_BIT; i++)
        gChapterFlagBits[i] = 0;
}

void SetPermanentFlag(int flag)
{
    if (flag < FLAG_PERMANENT_BASE)
        return;

    if (flag == FLAG_PERMANENT_BASE)
        return;

    flag = flag - FLAG_PERMANENT_BASE - 1;

    gPermanentFlagBits[flag / CHAR_BIT] |= gFlagBitMaskLut[flag % CHAR_BIT];
}

bool CheckPermanentFlag(int flag)
{
    if (flag < FLAG_PERMANENT_BASE || flag == FLAG_PERMANENT_BASE)
        return FALSE;

    flag = flag - FLAG_PERMANENT_BASE - 1;

    if ((gPermanentFlagBits[flag / CHAR_BIT] & gFlagBitMaskLut[flag % CHAR_BIT]) != 0)
        return TRUE;

    return FALSE;
}

void ClearPermanentFlag(int flag)
{
    fu8 mask;

    if (flag < FLAG_PERMANENT_BASE)
        return;

    if (flag == FLAG_PERMANENT_BASE)
        return;

    flag = flag - FLAG_PERMANENT_BASE - 1;

    mask = ~gFlagBitMaskLut[flag % CHAR_BIT];
    gPermanentFlagBits[flag / CHAR_BIT] = mask & gPermanentFlagBits[flag / CHAR_BIT];
}

void ResetPermanentFlags(void)
{
    int i;

    for (i = 0; i < (MAX_PERMANENT_FLAGS + CHAR_BIT - 1) / CHAR_BIT; i++)
        gPermanentFlagBits[i] = 0;
}

void SetFlag(int flag)
{
    if (flag < FLAG_PERMANENT_BASE)
        SetChapterFlag(flag);
    else
        SetPermanentFlag(flag);
}

bool CheckFlag(int flag)
{
    if (flag < FLAG_PERMANENT_BASE)
        return CheckChapterFlag(flag);
    else
        return CheckPermanentFlag(flag);
}

void ClearFlag(int flag)
{
    if (flag < FLAG_PERMANENT_BASE)
        ClearChapterFlag(flag);
    else
        ClearPermanentFlag(flag);
}

u8 * GetPermanentFlagBits(void)
{
    return gPermanentFlagBits;
}

u32 GetPermanentFlagBitsSize(void)
{
    return sizeof gPermanentFlagBits;
}

u8 * GetChapterFlagBits(void)
{
    return gChapterFlagBits;
}

u32 GetChapterFlagBitsSize(void)
{
    return sizeof gChapterFlagBits;
}
