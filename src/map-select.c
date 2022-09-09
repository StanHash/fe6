#include "map-select.h"

#include "hardware.h"
#include "sound.h"
#include "face.h"
#include "bm.h"
#include "chapter.h"

#include "constants/songs.h"

struct Vec2i EWRAM_DATA gMapSelectOrigin = { 0 };
struct SelectTarget EWRAM_DATA gTargetList[MAPSELECT_MAX_TARGETS] = { { 0 } };
i32 EWRAM_DATA gTargetCount = 0;

struct ProcScr CONST_DATA ProcScr_MapSelect[] =
{
PROC_LABEL(0),
    PROC_REPEAT(MapSelect_Main),
    PROC_SLEEP(1),
    PROC_CALL(InitBmDisplay),
    PROC_GOTO(0),
    PROC_END,
};

void BeginTargetList(int x, int y)
{
    gMapSelectOrigin.x = x;
    gMapSelectOrigin.y = y;
    gTargetCount = 0;
}

void EnlistTarget(int x, int y, int uid, int extra)
{
    gTargetList[gTargetCount].x = x;
    gTargetList[gTargetCount].y = y;
    gTargetList[gTargetCount].uid = uid;
    gTargetList[gTargetCount].extra = extra;
    gTargetCount++;
}

inline int CountTargets(void)
{
    return gTargetCount;
}

inline struct SelectTarget * GetTarget(int i)
{
    return gTargetList + i;
}

void LinkTargets(void)
{
    int i, last;

    for (i = 0; i < CountTargets(); i++)
    {
        GetTarget(i)->prev = GetTarget(i - 1);
        GetTarget(i)->next = GetTarget(i + 1);
    }

    last = CountTargets() - 1;

    GetTarget(0)->prev = GetTarget(last);
    GetTarget(last)->next = GetTarget(0);
}

void GetMapSelectActivePosition(struct MapSelectProc * proc, int * x_out, int * y_out)
{
    *x_out = proc->active_target->x * 16;
    *y_out = proc->active_target->y * 16;
}

void MapSelect_Main(struct MapSelectProc * proc)
{
    int x, y;
    u32 actions;

    if (proc->flags & MAPSELECT_FLAG_FROZEN)
    {
        GetMapSelectActivePosition(proc, &x, &y);
        PutMapCursor(x, y, MAP_CURSOR_RED_STATIC);

        return;
    }

    HandleMapSelectSwitching(proc);
    actions = HandleMapSelectActions(proc);

    if (actions & MAPSELECT_ACTION_END)
    {
        EndMapSelect(proc);
    }

    if (actions & MAPSELECT_ACTION_SE_6A)
    {
        PlaySe(SONG_6A);
    }

    if (actions & MAPSELECT_ACTION_SE_6B)
    {
        PlaySe(SONG_6B);
    }

    if (actions & MAPSELECT_ACTION_CLEARBGS)
    {
        ClearBg0Bg1();
    }

    if (actions & MAPSELECT_ACTION_ENDFACE)
    {
        EndFaceById(0);
    }

    if (!(actions & MAPSELECT_ACTION_ENDFAST))
    {
        GetMapSelectActivePosition(proc, &x, &y);

        if (CameraMoveWatchPosition(proc, x >> 4, y >> 4) != TRUE)
        {
            PutMapCursor(x, y, MAP_CURSOR_RED_MOVING);
        }
    }
}

ProcPtr StartMapSelect(struct MapSelectInfo const * info)
{
    struct MapSelectProc * proc;

    LockGame();

    proc = SpawnProc(ProcScr_MapSelect, PROC_TREE_3);

    proc->flags = MAPSELECT_FLAG_GAMELOCK;
    proc->info = info;
    proc->active_target = GetLinkedTargets();
    proc->on_a_press = NULL;

    if (proc->info->on_init != NULL)
        proc->info->on_init(proc);

    if (proc->info->on_init_b != NULL)
        proc->info->on_init_b(proc);

    if (proc->info->on_switch_in != NULL)
        proc->info->on_switch_in(proc, proc->active_target);

    gKeySt->pressed = 0;

    return proc;
}

ProcPtr StartMapSelectExt(struct MapSelectInfo const * info, fu8 (* on_a_press)(struct MapSelectProc * proc, struct SelectTarget * target))
{
    struct MapSelectProc * proc;

    proc = StartMapSelect(info);
    proc->on_a_press = on_a_press;

    return proc;
}

ProcPtr EndMapSelect(struct MapSelectProc * proc)
{
    if (proc->info->on_end != NULL)
        proc->info->on_end(proc);

    if (proc->flags & MAPSELECT_FLAG_GAMELOCK)
        UnlockGame();

    Proc_End(proc);

    return proc->proc_parent;
}

void HandleMapSelectSwitching(struct MapSelectProc * proc)
{
    struct SelectTarget * target_before = proc->active_target;

    if (gKeySt->repeated & (KEY_DPAD_UP | KEY_DPAD_LEFT))
    {
        if (proc->active_target->next != NULL)
            proc->active_target = proc->active_target->next;
    }

    if (gKeySt->repeated & (KEY_DPAD_DOWN | KEY_DPAD_RIGHT))
    {
        if (proc->active_target->prev != NULL)
            proc->active_target = proc->active_target->prev;
    }

    if (proc->active_target != target_before)
    {
        if (proc->info->on_switch_out)
            proc->info->on_switch_out(proc, target_before);

        if (proc->info->on_switch_in)
            proc->info->on_switch_in(proc, proc->active_target);

        PlaySe(SONG_67);
    }
}

u32 HandleMapSelectActions(struct MapSelectProc * proc)
{
    u32 result = 0;

    if (gKeySt->pressed & KEY_BUTTON_A)
    {
        if (proc->on_a_press)
        {
            result = proc->on_a_press(proc, proc->active_target);
        }
        else
        {
            if (proc->info->on_a_press)
                result = proc->info->on_a_press(proc, proc->active_target);
        }
    }
    else if (gKeySt->pressed & KEY_BUTTON_B)
    {
        if (proc->info->on_b_press)
            result = proc->info->on_b_press(proc, proc->active_target);
    }
    else if (gKeySt->pressed & KEY_BUTTON_R)
    {
        if (proc->info->on_r_press)
            result = proc->info->on_r_press(proc, proc->active_target);
    }

    return result;
}

void FreezeMapSelect(void)
{
    struct MapSelectProc * proc = Proc_Find(ProcScr_MapSelect);

    if (proc != NULL)
        proc->flags |= MAPSELECT_FLAG_FROZEN;
}

void ResumeMapSelect(void)
{
    struct MapSelectProc * proc = Proc_Find(ProcScr_MapSelect);

    if (proc != NULL)
        proc->flags &= ~MAPSELECT_FLAG_FROZEN;
}

int GetFurthestTargetDistance(void)
{
    int i, result = 0;
    struct SelectTarget * it = gTargetList;

    for (i = 0; i < CountTargets(); i++, it++)
    {
        int distance = RECT_DISTANCE(gMapSelectOrigin.x, gMapSelectOrigin.y, it->x, it->y);

        if (result < distance)
            result = distance;
    }

    return result;
}

struct NearTargetLinkOrderEnt { i8 x, y; };
struct NearTargetLinkOrderEnt CONST_DATA gNearTargetLinkOrder[13] =
{
    {  0,  0 },
    {  0, -2 }, {  0, -1 }, { +1, -1 }, { +1,  0 },
    { +2,  0 }, { +1, +1 }, {  0, +1 }, {  0, +2 },
    { -1, +1 }, { -1,  0 }, { -2,  0 }, { -1, -1 },
};

struct SelectTarget * GetLinkedTargetsNear(void)
{
    int i, j;

    struct SelectTarget * first = NULL;
    struct SelectTarget * last = NULL;

    for (i = 0; i < (int) ARRAY_COUNT(gNearTargetLinkOrder); i++)
    {
        struct SelectTarget * it;

        int x = gMapSelectOrigin.x + gNearTargetLinkOrder[i].x;
        int y = gMapSelectOrigin.y + gNearTargetLinkOrder[i].y;

        for (j = 0, it = gTargetList; j < gTargetCount; j++, it++)
        {
            if (x == it->x && y == it->y)
            {
                it->next = last;

                if (last != NULL)
                    last->prev = it;

                if (first == NULL)
                    first = it;

                last = it;
            }
        }
    }

    first->next = last;
    last->prev = first;

    return first;
}

struct SelectTarget * GetLinkedTargetsFar(void)
{
    LinkTargets();
    return gTargetList;
}

struct SelectTarget * GetLinkedTargets(void)
{
    if (GetFurthestTargetDistance() > 2)
        return GetLinkedTargetsFar();

    return GetLinkedTargetsNear();
}
