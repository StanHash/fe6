#include "common.h"

#include "event.h"
#include "event-script.h"

enum { EVENT_NOSCRIPT = 1 };

struct EventInfo
{
    /* 00 */ u32 unk_00;
    /* 04 */ EventScr const* script;
    /* 08 */ int flag;
};

void func_fe6_0806A8AC(struct EventInfo const* info)
{
    if (info->script == NULL)
        return;

    SetEid(info->flag);

    if ((int) info->script != EVENT_NOSCRIPT)
        StartEvent(info->script);
}
