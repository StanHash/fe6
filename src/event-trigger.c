#include "common.h"

#include "event.h"
#include "event-script.h"
#include "bm.h"

enum { EVENT_NOSCRIPT = 1 };

typedef u32 EventTriggerScr;

struct EventInfo
{
    /* 00 */ EventTriggerScr const * trigger_script;
    /* 04 */ EventScr const * script;
    /* 08 */ int flag;
    /* 0C */ u32 unk_0C;
    /* 10 */ u32 unk_10;
    /* 14 */ u32 unk_14;
    /* 18 */ i8 unk_18;
    /* 19 */ i8 unk_19;
    /* 1A */ u8 unk_1A;
    /* 1B */ u8 unk_1B;
};

struct EventTriggerCmdInfo
{
    /* 00 */ int (* func)(struct EventInfo * info);
    /* 04 */ int length;
};

extern struct EventTriggerCmdInfo CONST_DATA gUnk_08666114[];

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
    int unk_a = EVT_CMD_B1(info->trigger_script[2]);
    int unk_b = EVT_CMD_B2(info->trigger_script[2]);
    int unk_c = EVT_CMD_B3(info->trigger_script[2]);

    info->unk_10 = 0;

    if (unk_a == info->unk_18 && unk_b == info->unk_19)
    {
        info->script = (EventScr const *) info->trigger_script[1];
        info->flag = EVT_CMD_HI(info->trigger_script[0]);
        info->unk_0C = unk_c;

        if (unk_c == 0x12) // TODO: named constant
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
    int unk_a = EVT_CMD_B1(info->trigger_script[2]);
    int unk_b = EVT_CMD_B2(info->trigger_script[2]);
    int unk_c = EVT_CMD_B3(info->trigger_script[2]);
    int unk_d = EVT_CMD_B4(info->trigger_script[2]);

    if (unk_a == info->unk_18 && unk_b == info->unk_19)
    {
        info->script = (EventScr const *) EVENT_NOSCRIPT;
        info->flag = EVT_CMD_HI(info->trigger_script[0]);
        info->unk_0C = unk_c;
        info->unk_10 = unk_d;
        info->unk_14 = EVT_CMD_LO(info->trigger_script[1]);
        info->unk_10 = EVT_CMD_HI(info->trigger_script[1]);

        return TRUE;
    }

    return FALSE;
}
