
#pragma once

#include "common.h"

enum
{
    ACTION_NONE,
    ACTION_WAIT = 0x01,
    ACTION_COMBAT = 0x02,
    ACTION_STAFF = 0x03,
    ACTION_REFRESH = 0x04,

    ACTION_STEAL = 0x06,
    ACTION_RESCUE = 0x07,
    ACTION_DROP = 0x08,
    ACTION_TAKE = 0x09,
    ACTION_GIVE = 0x0A,

    ACTION_TALK = 0x0C,
    ACTION_SUPPORT = 0x0D,
    ACTION_0E = 0x0E, // ACTION_VISIT?
    ACTION_0F = 0x0F, // ACTION_SEIZE?
    ACTION_DOOR = 0x10,

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
    /* 00 */ u16 actionRandSt[3];
    /* 06 */ u16 arenaBeginRandSt[3];

    /* 0C */ u8 instigator;
    /* 0D */ u8 target;

    /* 0E */ u8 xMove;
    /* 0F */ u8 yMove;

    /* 10 */ u8 moveCount;

    /* 11 */ u8 id;

    /* 12 */ u8 itemSlot;

    /* 13 */ u8 xTarget;
    /* 14 */ u8 yTarget;

    /* 15 */ u8 extra;

    /* 16 */ u8 suspendPoint;

    /* 18 */ struct BattleHit* scriptedBattleHits;

    /* 1C+ TODO (sizeof(struct ActionData) == 0x38) */
};

extern struct Action gAction;

void SaveActionRand(void);
void RestoreActionRand(void);
Bool DoAction(ProcPtr proc);
