
#include "common.h"

#include "text.h"
#include "unit.h"
#include "faction.h"

#include "constants/icons.h"

extern struct SupportBonuses CONST_DATA AffinityBonuses[];

enum
{
    // Config

    MAX_SIMULTANEOUS_SUPPORT_COUNT = 5,
    SUPPORT_BONUSES_MAX_DISTANCE = 3,
};

enum
{
    SUPPORT_LEVEL_NONE,
    SUPPORT_LEVEL_C,
    SUPPORT_LEVEL_B,
    SUPPORT_LEVEL_A,
};

enum
{
    SUPPORT_EXP_C = 61,
    SUPPORT_EXP_B = 121,
    SUPPORT_EXP_A = 201,
};

struct SupportInfo
{
    /* 00 */ u8 pids[UNIT_SUPPORT_COUNT];
    /* 0A */ u8 expBase[UNIT_SUPPORT_COUNT];
    /* 14 */ u8 expGrowth[UNIT_SUPPORT_COUNT];
    /* 1E */ u8 count;
};

struct SupportBonuses
{
    /* 00 */ u8 affinity;

    /* 01 */ u8 bonusAttack;
    /* 02 */ u8 bonusDefense;
    /* 03 */ u8 bonusHit;
    /* 04 */ u8 bonusAvoid;
    /* 05 */ u8 bonusCrit;
    /* 06 */ u8 bonusDodge;
};

static int CONST_DATA sMaxExpLut[] =
{
    [SUPPORT_LEVEL_NONE] = SUPPORT_EXP_C-1,
    [SUPPORT_LEVEL_C]    = SUPPORT_EXP_B-1,
    [SUPPORT_LEVEL_B]    = SUPPORT_EXP_A-1,
    [SUPPORT_LEVEL_A]    = SUPPORT_EXP_A
};

int sub_8022A84(struct Unit* unit)
{
    if (!unit->person->supportInfo)
        return 0;

    return unit->person->supportInfo->count;
}

u8 sub_8022A94(struct Unit* unit, int num)
{
    if (!unit->person->supportInfo)
        return 0;

    return unit->person->supportInfo->pids[num];
}

struct Unit* sub_8022AA8(struct Unit* unit, int num)
{
    u8 pid = sub_8022A94(unit, num);

    int i, last;

    for (i = UNIT_FACTION(unit) + 1, last = UNIT_FACTION(unit) + 0x40; i < last; ++i)
    {
        unit = GetUnit(i);

        if (!unit)
            continue;

        if (!unit->person)
            continue;

        if (unit->person->id == pid)
            return unit;
    }

    return NULL;
}

int sub_8022AF0(struct Unit* unit, int num)
{
    int exp = unit->supports[num];

    if (exp >= SUPPORT_EXP_A)
        return SUPPORT_LEVEL_A;

    if (exp >= SUPPORT_EXP_B)
        return SUPPORT_LEVEL_B;

    if (exp >= SUPPORT_EXP_C)
        return SUPPORT_LEVEL_C;

    return SUPPORT_LEVEL_NONE;
}

int sub_8022B14(struct Unit* unit)
{
    int i, count, result;

    count = sub_8022A84(unit);

    for (i = 0, result = 0; i < count; ++i)
        result += sub_8022AF0(unit, i);

    return result;
}

void sub_8022B40(struct Unit* unit, int num)
{
    if (unit->person->supportInfo)
    {
        int gain = unit->person->supportInfo->expGrowth[num];
        int exp = unit->supports[num];
        int maxExp = sMaxExpLut[sub_8022AF0(unit, num)];

        if (exp + gain > maxExp)
            gain = maxExp - exp;

        unit->supports[num] = exp + gain;
        gPlaySt.supportGain += gain;
    }
}

void sub_8022B8C(struct Unit* unit, int num)
{
    unit->supports[num]++;
    gPlaySt.supportGain++;
}

Bool sub_8022BA4(struct Unit* unit, int num)
{
    int exp, maxExp;

    if (gPlaySt.flags & PLAY_FLAG_5)
        return FALSE;

    if (gPlaySt.flags & PLAY_FLAG_3)
        return FALSE;

    if (sub_8022B14(unit) >= MAX_SIMULTANEOUS_SUPPORT_COUNT)
        return FALSE;

    if (sub_8022B14(sub_8022AA8(unit, num)) >= MAX_SIMULTANEOUS_SUPPORT_COUNT)
        return FALSE;

    exp    = unit->supports[num];
    maxExp = sMaxExpLut[sub_8022AF0(unit, num)];

    if (exp == SUPPORT_EXP_A)
        return FALSE;

    return (exp == maxExp) ? TRUE : FALSE;
}

int sub_8022C10(struct Unit* unit, int num)
{
    if (!unit->person->supportInfo)
        return -1;

    return unit->person->supportInfo->expBase[num];
}

int sub_8022C28(struct Unit* unit, u8 charId)
{
    int i, count = sub_8022A84(unit);

    for (i = 0; i < count; ++i)
    {
        if (sub_8022A94(unit, i) == charId)
            return i;
    }

    return -1;
}

void sub_8022C60(struct Unit* unit)
{
    int i, count = sub_8022A84(unit);

    for (i = 0; i < count; ++i)
    {
        struct Unit* other = sub_8022AA8(unit, i);

        if (!other)
            continue;

        other->supports[sub_8022C28(other, unit->person->id)] = 0;
        unit->supports[i] = 0;
    }
}

void sub_8022CB4(void)
{
    int i, j, jend;

    if (gPlaySt.turn == 1)
        return;

    if (gPlaySt.supportGain >= 250)
        return;

    if (gPlaySt.flags & PLAY_FLAG_5)
        return;

    for (i = 1; i < 0x40; ++i)
    {
        struct Unit* unit = GetUnit(i);

        if (!unit)
            continue;

        if (!unit->person)
            continue;

        if (unit->state & US_UNAVAILABLE)
            continue;

        if (sub_8022B14(unit) >= MAX_SIMULTANEOUS_SUPPORT_COUNT)
            continue;

        jend = sub_8022A84(unit);

        for (j = 0; j < jend; ++j)
        {
            struct Unit* other = sub_8022AA8(unit, j);

            if (!other)
                continue;

            if (other->state & US_UNAVAILABLE)
                continue;

            if (UNIT_FACTION(other) != FACTION_BLUE)
                continue;

            switch (RECT_DISTANCE(unit->x, unit->y, other->x, other->y))
            {

            case 0:
                if (!(unit->rescue == other->id))
                    break;

                goto add_support_points;

            case 1:
                if ((unit->state & US_RESCUED) || (other->state & US_RESCUED))
                    break;

            add_support_points:
                if (sub_8022B14(other) < MAX_SIMULTANEOUS_SUPPORT_COUNT)
                    sub_8022B40(unit, j);

                break;

            }
        }
    }
}

static const struct SupportBonuses* sub_8022DB4(int affinity)
{
    const struct SupportBonuses* it;

    for (it = AffinityBonuses; it->affinity; ++it)
    {
        if (it->affinity == affinity)
            return it;
    }

    // return NULL; // BUG?
}

static void sub_8022DD4(struct SupportBonuses* bonuses, int affinity, int level)
{
    const struct SupportBonuses* added = sub_8022DB4(affinity);

    bonuses->bonusAttack  += level * added->bonusAttack;
    bonuses->bonusDefense += level * added->bonusDefense;
    bonuses->bonusHit     += level * added->bonusHit;
    bonuses->bonusAvoid   += level * added->bonusAvoid;
    bonuses->bonusCrit    += level * added->bonusCrit;
    bonuses->bonusDodge   += level * added->bonusDodge;
}

static void sub_8022E2C(struct SupportBonuses* bonuses)
{
    bonuses->bonusAttack  = 0;
    bonuses->bonusDefense = 0;
    bonuses->bonusHit     = 0;
    bonuses->bonusAvoid   = 0;
    bonuses->bonusCrit    = 0;
    bonuses->bonusDodge   = 0;
}

int sub_8022E3C(struct Unit* unit, struct SupportBonuses* bonuses)
{
    int i, count;
    int result = 0;

    sub_8022E2C(bonuses);

    count = sub_8022A84(unit);

    for (i = 0; i < count; ++i)
    {
        struct Unit* other;
        int levelA, levelB;

        result = result >> 1;
        other = sub_8022AA8(unit, i);

        if (!other)
            continue;

        if (!(gBmSt.flags & BM_FLAG_LINKARENA))
        {
            if (RECT_DISTANCE(unit->x, unit->y, other->x, other->y) > SUPPORT_BONUSES_MAX_DISTANCE)
                continue;
        }

        if (other->state & (US_UNAVAILABLE | US_RESCUED))
            continue;

        levelA = sub_8022AF0(other, sub_8022C28(other, unit->person->id));
        sub_8022DD4(bonuses, other->person->affinity, levelA);

        levelB = sub_8022AF0(unit, i);
        sub_8022DD4(bonuses, unit->person->affinity, levelB);

        if (levelA != 0 && levelB != 0)
            result += 1 << (count - 1);
    }

    bonuses->bonusAttack  /= 2;
    bonuses->bonusDefense /= 2;
    bonuses->bonusHit     /= 2;
    bonuses->bonusAvoid   /= 2;
    bonuses->bonusCrit    /= 2;
    bonuses->bonusDodge   /= 2;

    return result;
}

int sub_8022F44(struct Unit* unit)
{
    int affinity = unit->person->affinity;

    if (!affinity)
        return -1;

    return ICON_AFFINITY_BASE + affinity;
}

int sub_8022F58(int pid)
{
    int affinity = GetPersonInfo(pid)->affinity;

    if (!affinity)
        return -1;

    return ICON_AFFINITY_BASE + affinity;
}

int sub_8022F70(int level)
{
    u8 chars[4] =
    {
        TEXT_SPECIAL_DASH,
        TEXT_SPECIAL_C,
        TEXT_SPECIAL_B,
        TEXT_SPECIAL_A
    };

    return chars[level];
}

char const* sub_8022F94(int affinity)
{
    char const* lut[] =
    {
        "Å[",
        "âä",
        "óã",
        "ïó",
        "ïX",
        "à≈",
        "åı",
        "óù",
    };

    return lut[affinity];
}
