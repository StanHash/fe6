#ifndef ACTION_H
#define ACTION_H

#include "prelude.h"

// valid IDs for Action::id
enum
{
    ACTION_NONE,
    ACTION_WAIT = 0x01,
    ACTION_COMBAT = 0x02,
    ACTION_STAFF = 0x03,
    ACTION_REFRESH = 0x04,
    // 05?
    ACTION_STEAL = 0x06,
    ACTION_RESCUE = 0x07,
    ACTION_DROP = 0x08,
    ACTION_TAKE = 0x09,
    ACTION_GIVE = 0x0A,
    // 0B?
    ACTION_TALK = 0x0C,
    ACTION_SUPPORT = 0x0D,
    ACTION_VISIT = 0x0E,
    ACTION_SEIZE = 0x0F,
    ACTION_DOOR = 0x10,
    // 11?
    ACTION_CHEST = 0x12,
    // ACTION_SHOPPED,
    // ACTION_ARENA,
    ACTION_16 = 0x16,
    ACTION_USEITEM = 0x17,
    ACTION_TRADED = 0x18,
    ACTION_TRADED_SUPPLY = 0x19,
    ACTION_TRADED_NOCHANGES = 0x1A,
    ACTION_TRAPPED = 0x1B,
    ACTION_1C = 0x1C,
};

// valid values for Action::suspend_point
enum
{
    SUSPEND_POINT_PLAYER_PHASE,
    SUSPEND_POINT_DURING_ACTION,
    SUSPEND_POINT_AI_PHASE,
    SUSPEND_POINT_BERSERK_PHASE,
    SUSPEND_POINT_DURING_ARENA,
    SUSPEND_POINT_5,
    SUSPEND_POINT_6,
    SUSPEND_POINT_7,
    SUSPEND_POINT_8,
    SUSPEND_POINT_CHANGE_PHASE,
};

struct Action
{
    /* 00 */ u16 action_rand_st[3];
    /* 06 */ u16 arena_begin_rand_st[3];
    /* 0C */ u8 instigator;
    /* 0D */ u8 target;
    /* 0E */ u8 x_move, y_move;
    /* 10 */ u8 move_count;
    /* 11 */ u8 id;
    /* 12 */ u8 item_slot;
    /* 13 */ u8 x_target, y_target;
    /* 15 */ u8 extra;
    /* 16 */ u8 suspend_point;
};

extern struct Action gAction;

void SaveActionRand(void);
void RestoreActionRand(void);
bool DoAction(ProcPtr proc);

void DropRescueOnDeath(ProcPtr parent, struct Unit * unit);
void KillUnitOnCombatDeath(struct Unit * unit, struct Unit * opponent);
void KillUnitOnArenaDeath(struct Unit * unit);
void func_fe6_0802A7F4(void);

extern struct ProcScr CONST_DATA ProcScr_CombatAction[];

#endif // ACTION_H
