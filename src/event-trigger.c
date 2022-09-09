#include "common.h"

#include "event.h"
#include "event-script.h"
#include "bm.h"
#include "item.h"
#include "unit.h"
#include "faction.h"
#include "chapter-info.h"
#include "support.h"

#include "constants/items.h"

enum { EVENT_NOSCRIPT = 1 };

enum
{
    EVENT_TRIGGER_COMMAND_00 = 0x00,
    EVENT_TRIGGER_COMMAND_12 = 0x12,
};

typedef u32 EventTriggerScr;

struct EventInfo
{
    /* 00 */ EventTriggerScr const * trigger_script;
    /* 04 */ EventScr const * script;
    /* 08 */ u32 flag;
    /* 0C */ u32 command;
    /* 10 */ u32 unk_10;
    /* 14 */ u32 unk_14;
    /* 18 */ i8 x_18;
    /* 19 */ i8 y_19;
    /* 1A */ u8 unk_1A;
    /* 1B */ u8 unk_1B;
};

struct EventTriggerCmdInfo
{
    /* 00 */ int (* func)(struct EventInfo * info);
    /* 04 */ int length;
};

struct SupportTalkInfo
{
    /* +00 */ u8 pid_a, pid_b;
    /* +02 */ u8 pad_02[2];
    /* +04 */ int msg_talk_c;
    /* +08 */ int msg_talk_b;
    /* +0C */ int msg_talk_a;
};

extern struct EventTriggerCmdInfo CONST_DATA gUnk_08666114[];

extern struct SupportTalkInfo CONST_DATA gSupportTalkInfo[];

#define EVT_CMD_LO(cmd) (((cmd) & 0x0000FFFF))
#define EVT_CMD_HI(cmd) (((cmd) & 0xFFFF0000) >> 16)
#define EVT_CMD_B1(cmd) (((cmd) & 0x000000FF))
#define EVT_CMD_B2(cmd) (((cmd) & 0x0000FF00) >> 8)
#define EVT_CMD_B3(cmd) (((cmd) & 0x00FF0000) >> 16)
#define EVT_CMD_B4(cmd) (((cmd) & 0xFF000000) >> 24)

void func_fe6_0806A8AC(struct EventInfo const * info)
{
    if (info->script == NULL)
        return;

    SetEid(info->flag);

    if ((int) info->script != EVENT_NOSCRIPT)
        StartEvent(info->script);
}

struct EventInfo * func_fe6_0806A8CC(struct EventInfo * info)
{
    info->script = NULL;
    info->flag = 0;

    for (;;)
    {
        int cmdid = EVT_CMD_LO(info->trigger_script[0]);

        if (!CheckFlag(EVT_CMD_HI(info->trigger_script[0])))
        {
            if (gUnk_08666114[cmdid].func(info) == TRUE)
            {
                if (info->script != NULL)
                    return info;

                break;
            }
        }

        info->trigger_script += gUnk_08666114[cmdid].length;
    }

    return NULL;
}

struct EventInfo * func_fe6_0806A920(struct EventInfo * info)
{
    int cmdid;

    if (info == NULL)
        return NULL;

    cmdid = EVT_CMD_LO(info->trigger_script[0]);
    info->trigger_script += gUnk_08666114[cmdid].length;

#if BUGFIX
    return func_fe6_0806A8CC(info);
#else
    func_fe6_0806A8CC(info);
#endif
}

int func_fe6_0806A950(struct EventInfo * info)
{
    return TRUE;
}

int func_fe6_0806A954(struct EventInfo * info)
{
    if (CheckFlag(EVT_CMD_LO(info->trigger_script[2])))
    {
        info->script = (EventScr const *) info->trigger_script[1];
        info->flag = EVT_CMD_HI(info->trigger_script[0]);

        return TRUE;
    }

    return FALSE;
}

int func_fe6_0806A97C(struct EventInfo * info)
{
    int turn = EVT_CMD_B1(info->trigger_script[2]);
    int turn_max = EVT_CMD_B2(info->trigger_script[2]);
    int faction = EVT_CMD_B3(info->trigger_script[2]);

    if (turn_max == 0)
    {
        if ((gPlaySt.turn == turn) && (gPlaySt.faction == faction))
        {
            info->script = (EventScr const *) info->trigger_script[1];
            info->flag = EVT_CMD_HI(info->trigger_script[0]);

            return TRUE;
        }
    }
    else
    {
        if ((gPlaySt.turn >= turn && gPlaySt.turn <= turn_max) && (gPlaySt.faction == faction))
        {
            info->script = (EventScr const *) info->trigger_script[1];
            info->flag = EVT_CMD_HI(info->trigger_script[0]);

            return TRUE;
        }
    }

    return FALSE;
}

int func_fe6_0806A9DC(struct EventInfo * info)
{
    if (!(gPlaySt.flags & PLAY_FLAG_HARD))
        return FALSE;

    if (CheckFlag(2)) // TODO: flag ids
        return FALSE;

    return func_fe6_0806A97C(info);
}

int func_fe6_0806AA0C(struct EventInfo * info)
{
    int unk_a = EVT_CMD_B1(info->trigger_script[2]);
    int unk_b = EVT_CMD_B2(info->trigger_script[2]);

    if (info->unk_1A == unk_a && info->unk_1B == unk_b)
    {
        info->script = (EventScr const *) info->trigger_script[1];
        info->flag = EVT_CMD_HI(info->trigger_script[0]);

        return TRUE;
    }

    return FALSE;
}

int func_fe6_0806AA40(struct EventInfo * info)
{
    int x = EVT_CMD_B1(info->trigger_script[2]);
    int y = EVT_CMD_B2(info->trigger_script[2]);
    int command = EVT_CMD_B3(info->trigger_script[2]);

    info->unk_10 = 0;

    if (x == info->x_18 && y == info->y_19)
    {
        info->script = (EventScr const *) info->trigger_script[1];
        info->flag = EVT_CMD_HI(info->trigger_script[0]);
        info->command = command;

        if (command == EVENT_TRIGGER_COMMAND_12)
            info->unk_14 = 0;

        return TRUE;
    }

    return FALSE;
}

int func_fe6_0806AA8C(struct EventInfo * info)
{
    int result = func_fe6_0806AA40(info);
    info->unk_10 = 3; // TODO: named constant
    return result;
}

int func_fe6_0806AAA0(struct EventInfo * info)
{
    int x = EVT_CMD_B1(info->trigger_script[2]);
    int y = EVT_CMD_B2(info->trigger_script[2]);
    int command = EVT_CMD_B3(info->trigger_script[2]);
    int unk_d = EVT_CMD_B4(info->trigger_script[2]);

    if (x == info->x_18 && y == info->y_19)
    {
        info->script = (EventScr const *) EVENT_NOSCRIPT;
        info->flag = EVT_CMD_HI(info->trigger_script[0]);
        info->command = command;
        info->unk_10 = unk_d;
        info->unk_14 = EVT_CMD_LO(info->trigger_script[1]);
        info->unk_10 = EVT_CMD_HI(info->trigger_script[1]);

        return TRUE;
    }

    return FALSE;
}

int func_fe6_0806AAEC(struct EventInfo * info)
{
    int x = EVT_CMD_B1(info->trigger_script[2]);
    int y = EVT_CMD_B2(info->trigger_script[2]);
    int command = EVT_CMD_B3(info->trigger_script[2]);
    int unk_d = EVT_CMD_B4(info->trigger_script[2]);

    if (x == info->x_18 && y == info->y_19)
    {
        info->script = (EventScr const *) info->trigger_script[1];
#if !NONMATCHING
        asm("":::"memory"); // TODO: add to nonmatch doc
#endif
        info->flag = EVT_CMD_HI(info->trigger_script[0]);
        info->command = command;
        info->unk_10 = unk_d;

        return TRUE;
    }

    return FALSE;
}

int func_fe6_0806AB30(struct EventInfo * info)
{
    int x = EVT_CMD_B1(info->trigger_script[2]);
    int y = EVT_CMD_B2(info->trigger_script[2]);
    int command = EVT_CMD_B3(info->trigger_script[2]);
    int unk_d = EVT_CMD_B4(info->trigger_script[2]);

    if (x == info->x_18 && y == info->y_19)
    {
        info->script = (EventScr const *) info->trigger_script[1];
#if !NONMATCHING
        asm("":::"memory"); // TODO: add to nonmatch doc
#endif
        info->flag = EVT_CMD_HI(info->trigger_script[0]);
        info->command = command;
        info->unk_10 = unk_d;

        return TRUE;
    }

    return FALSE;
}

int func_fe6_0806AB74(struct EventInfo * info)
{
    int x = EVT_CMD_B1(info->trigger_script[2]);
    int y = EVT_CMD_B2(info->trigger_script[2]);
    int command = EVT_CMD_B3(info->trigger_script[2]);

    if (x == info->x_18 && y == info->y_19)
    {
        if (command != 0x15 || FindUnitItemSlot(gActiveUnit, IID_MEMBERCARD) != -1)
        {
            info->script = (EventScr const *) info->trigger_script[1];
            info->flag = EVT_CMD_HI(info->trigger_script[0]);
            info->command = command;

            return TRUE;
        }
    }

    return FALSE;
}

int func_fe6_0806ABD0(struct EventInfo * info)
{
    fi8 x = gActiveUnit->x;
    fi8 y = gActiveUnit->y;

    fi8 x1 = (i8) EVT_CMD_B1(info->trigger_script[2]);
    fi8 y1 = (i8) EVT_CMD_B2(info->trigger_script[2]);
    fi8 x2 = (i8) EVT_CMD_B3(info->trigger_script[2]);
    fi8 y2 = (i8) EVT_CMD_B4(info->trigger_script[2]);

    if (x1 <= x && y1 <= y && x2 >= x && y2 >= y)
    {
        info->script = (EventScr const *) info->trigger_script[1];
        info->flag = EVT_CMD_HI(info->trigger_script[0]);

        return TRUE;
    }

    return FALSE;
}

int func_fe6_0806AC34(struct EventInfo * info)
{
    if (!(gPlaySt.flags & PLAY_FLAG_HARD))
        return FALSE;

    if (CheckFlag(2)) // TODO: flag ids
        return FALSE;

    return func_fe6_0806ABD0(info);
}

int func_fe6_0806AC64(struct EventInfo * info)
{
    bool (* func)(struct EventInfo * info) = (void const *) info->trigger_script[2];

    if (func(info))
    {
        info->script = (EventScr const *) info->trigger_script[1];
        info->flag = EVT_CMD_HI(info->trigger_script[0]);

        return TRUE;
    }

    return FALSE;
}

int func_fe6_0806AC90(struct EventInfo * info, fu8 pid_a, fu8 pid_b)
{
    if (info->unk_1A == pid_a && info->unk_1B == pid_b)
    {
        info->script = (EventScr const *) info->trigger_script[1];
        info->flag = EVT_CMD_HI(info->trigger_script[0]);

        return TRUE;
    }

    return FALSE;
}

int func_fe6_0806ACB8(int x1, int y1, int x2, int y2)
{
    if (gActiveUnit->x >= x1 && gActiveUnit->x <= x2 && gActiveUnit->y >= y1 && gActiveUnit->y <= y2)
    {
        return TRUE;
    }

    return FALSE;
}

bool func_fe6_0806ACEC(int x1, int y1, int x2, int y2)
{
    FOR_UNITS_FACTION(FACTION_BLUE, unit,
    {
        if (unit->state & US_DEAD)
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

    if (func_fe6_0806ACEC(0, 15, 25, 23))
        return FALSE;

    return TRUE;
}

bool func_fe6_0806AD74(struct EventInfo * info)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    if (func_fe6_0806ACEC(0, 24, 16, 27))
        return TRUE;

    if (func_fe6_0806ACEC(0, 21, 2, 23))
        return TRUE;

    if (func_fe6_0806ACEC(3, 20, 5, 22))
        return TRUE;

    return FALSE;
}

bool func_fe6_0806ADC4(struct EventInfo * info)
{
    return func_fe6_0806ACEC(12, 21, 31, 24);
}

bool func_fe6_0806ADDC(struct EventInfo * info)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    return func_fe6_0806ACEC(17, 21, 31, 35);
}

bool func_fe6_0806AE04(struct EventInfo * info)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    return func_fe6_0806ACEC(0, 15, 8, 18);
}

bool func_fe6_0806AE2C(struct EventInfo * info)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    return func_fe6_0806ACEC(0, 24, 12, 27);
}

bool func_fe6_0806AE54(struct EventInfo * info)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    return func_fe6_0806ACEC(21, 0, 30, 6);
}

bool func_fe6_0806AE7C(int x1, int y1, int x2, int y2)
{
    FOR_UNITS_FACTION(FACTION_RED, unit,
    {
        if (unit->state & US_DEAD)
            continue;

        if (unit->x >= x1 && unit->x <= x2 && unit->y >= y1 && unit->y <= y2)
        {
            return TRUE;
        }
    })

    return FALSE;
}

bool func_fe6_0806AED8(void)
{
    struct EventInfo info;

    info.trigger_script = GetChapterEventInfo(gPlaySt.chapter)->trigger_script_00;

    if (func_fe6_0806A8CC(&info))
    {
        return TRUE;
    }

    return FALSE;
}

void func_fe6_0806AF08(void)
{
    struct EventInfo info;

    info.trigger_script = GetChapterEventInfo(gPlaySt.chapter)->trigger_script_00;

    if (func_fe6_0806A8CC(&info))
    {
        func_fe6_0806A8AC(&info);

        while (func_fe6_0806A920(&info) != NULL)
        {
            func_fe6_0806A8AC(&info);
        }
    }
}

bool func_fe6_0806AF4C(fu8 pid_a, fu8 pid_b)
{
    struct EventInfo info;

    info.trigger_script = GetChapterEventInfo(gPlaySt.chapter)->trigger_script_04;
    info.unk_1A = pid_a;
    info.unk_1B = pid_b;

    if (func_fe6_0806A8CC(&info))
    {
        return TRUE;
    }

    return FALSE;
}

void func_fe6_0806AF90(fu8 pid_a, fu8 pid_b)
{
    struct EventInfo info;

    info.trigger_script = GetChapterEventInfo(gPlaySt.chapter)->trigger_script_04;
    info.unk_1A = pid_a;
    info.unk_1B = pid_b;

    if (func_fe6_0806A8CC(&info))
    {
        func_fe6_0806A8AC(&info);
    }
}

void func_fe6_0806AFD0(fu8 pid_a, fu8 pid_b, int support_level)
{
    int msg = 0;

    struct SupportTalkInfo const * it = gSupportTalkInfo;

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

int func_fe6_0806B028(fi8 x, fi8 y)
{
    struct EventInfo info;

    info.trigger_script = GetChapterEventInfo(gPlaySt.chapter)->trigger_script_08;
    info.x_18 = x;
    info.y_19 = y;

    if (!func_fe6_0806A8CC(&info))
    {
        return FALSE;
    }

    return info.command;
}
