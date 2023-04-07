
#include "support.h"
#include "common.h"

#include "text.h"
#include "bm.h"
#include "unit.h"
#include "faction.h"

#include "constants/icons.h"

extern struct SupportBonuses CONST_DATA AffinityBonuses[];

enum
{
    // config

    MAX_SIMULTANEOUS_SUPPORT_COUNT = 5,
    SUPPORT_BONUSES_MAX_DISTANCE = 3,
};

static int CONST_DATA sMaxExpLut[] =
{
    [SUPPORT_LEVEL_NONE] = SUPPORT_EXP_C-1,
    [SUPPORT_LEVEL_C]    = SUPPORT_EXP_B-1,
    [SUPPORT_LEVEL_B]    = SUPPORT_EXP_A-1,
    [SUPPORT_LEVEL_A]    = SUPPORT_EXP_A
};

int GetUnitSupportCount(struct Unit * unit)
{
    if (!unit->pinfo->support_info)
        return 0;

    return unit->pinfo->support_info->count;
}

u8 GetUnitSupportPid(struct Unit * unit, int num)
{
    if (!unit->pinfo->support_info)
        return 0;

    return unit->pinfo->support_info->pids[num];
}

struct Unit * GetUnitSupportUnit(struct Unit * unit, int num)
{
    u8 pid = GetUnitSupportPid(unit, num);

    int i, last;

    for (i = UNIT_FACTION(unit) + 1, last = UNIT_FACTION(unit) + 0x40; i < last; ++i)
    {
        unit = GetUnit(i);

        if (!unit)
            continue;

        if (!unit->pinfo)
            continue;

        if (unit->pinfo->id == pid)
            return unit;
    }

    return NULL;
}

int GetUnitSupportLevel(struct Unit * unit, int num)
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

int GetUnitTotalSupportLevel(struct Unit * unit)
{
    int i, count, result;

    count = GetUnitSupportCount(unit);

    for (i = 0, result = 0; i < count; ++i)
        result += GetUnitSupportLevel(unit, i);

    return result;
}

void UnitGainSupportExp(struct Unit * unit, int num)
{
    if (unit->pinfo->support_info)
    {
        int gain = unit->pinfo->support_info->exp_growth[num];
        int exp = unit->supports[num];
        int maxExp = sMaxExpLut[GetUnitSupportLevel(unit, num)];

        if (exp + gain > maxExp)
            gain = maxExp - exp;

        unit->supports[num] = exp + gain;
        gPlaySt.support_gain += gain;
    }
}

void UnitGainSupportLevel(struct Unit * unit, int num)
{
    unit->supports[num]++;
    gPlaySt.support_gain++;
}

bool CanUnitSupportNow(struct Unit * unit, int num)
{
    int exp, maxExp;

    if (gPlaySt.flags & PLAY_FLAG_COMPLETE)
        return FALSE;

    if (gPlaySt.flags & PLAY_FLAG_TUTORIAL)
        return FALSE;

    if (GetUnitTotalSupportLevel(unit) >= MAX_SIMULTANEOUS_SUPPORT_COUNT)
        return FALSE;

    if (GetUnitTotalSupportLevel(GetUnitSupportUnit(unit, num)) >= MAX_SIMULTANEOUS_SUPPORT_COUNT)
        return FALSE;

    exp    = unit->supports[num];
    maxExp = sMaxExpLut[GetUnitSupportLevel(unit, num)];

    if (exp == SUPPORT_EXP_A)
        return FALSE;

    return (exp == maxExp) ? TRUE : FALSE;
}

int GetUnitInitialSupportExp(struct Unit * unit, int num)
{
    if (!unit->pinfo->support_info)
        return -1;

    return unit->pinfo->support_info->exp_base[num];
}

int GetUnitSupportNumByPid(struct Unit * unit, u8 pid)
{
    int i, count = GetUnitSupportCount(unit);

    for (i = 0; i < count; ++i)
    {
        if (GetUnitSupportPid(unit, i) == pid)
            return i;
    }

    return -1;
}

void ClearUnitSupports(struct Unit * unit)
{
    int i, count = GetUnitSupportCount(unit);

    for (i = 0; i < count; ++i)
    {
        struct Unit * other = GetUnitSupportUnit(unit, i);

        if (!other)
            continue;

        other->supports[GetUnitSupportNumByPid(other, unit->pinfo->id)] = 0;
        unit->supports[i] = 0;
    }
}

void DoTurnSupportExp(void)
{
    int i, j, jend;

    if (gPlaySt.turn == 1)
        return;

    if (gPlaySt.support_gain >= 250)
        return;

    if (gPlaySt.flags & PLAY_FLAG_COMPLETE)
        return;

    for (i = 1; i < 0x40; ++i)
    {
        struct Unit * unit = GetUnit(i);

        if (!unit)
            continue;

        if (!unit->pinfo)
            continue;

        if (unit->flags & UNIT_FLAG_UNAVAILABLE)
            continue;

        if (GetUnitTotalSupportLevel(unit) >= MAX_SIMULTANEOUS_SUPPORT_COUNT)
            continue;

        jend = GetUnitSupportCount(unit);

        for (j = 0; j < jend; ++j)
        {
            struct Unit * other = GetUnitSupportUnit(unit, j);

            if (!other)
                continue;

            if (other->flags & UNIT_FLAG_UNAVAILABLE)
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
                if ((unit->flags & UNIT_FLAG_RESCUED) || (other->flags & UNIT_FLAG_RESCUED))
                    break;

            add_support_points:
                if (GetUnitTotalSupportLevel(other) < MAX_SIMULTANEOUS_SUPPORT_COUNT)
                    UnitGainSupportExp(unit, j);

                break;

            }
        }
    }
}

static struct SupportBonuses const * GetAffinityBonuses(int affinity)
{
    struct SupportBonuses const * it;

    for (it = AffinityBonuses; it->affinity; ++it)
    {
        if (it->affinity == affinity)
            return it;
    }

#if BUGFIX
    return NULL;
#endif
}

static void ApplyAffinityBonuses(struct SupportBonuses * bonuses, int affinity, int level)
{
    struct SupportBonuses const * added = GetAffinityBonuses(affinity);

    bonuses->bonus_attack  += level * added->bonus_attack;
    bonuses->bonus_defense += level * added->bonus_defense;
    bonuses->bonus_hit     += level * added->bonus_hit;
    bonuses->bonus_avoid   += level * added->bonus_avoid;
    bonuses->bonus_crit    += level * added->bonus_crit;
    bonuses->bonus_dodge   += level * added->bonus_dodge;
}

static void InitBonuses(struct SupportBonuses * bonuses)
{
    bonuses->bonus_attack  = 0;
    bonuses->bonus_defense = 0;
    bonuses->bonus_hit     = 0;
    bonuses->bonus_avoid   = 0;
    bonuses->bonus_crit    = 0;
    bonuses->bonus_dodge   = 0;
}

int GetUnitSupportBonuses(struct Unit * unit, struct SupportBonuses * bonuses)
{
    int i, count;
    int result = 0;

    InitBonuses(bonuses);

    count = GetUnitSupportCount(unit);

    for (i = 0; i < count; ++i)
    {
        struct Unit * other;
        int levelA, levelB;

        result = result >> 1;
        other = GetUnitSupportUnit(unit, i);

        if (!other)
            continue;

        if (!(gBmSt.flags & BM_FLAG_LINKARENA))
        {
            if (RECT_DISTANCE(unit->x, unit->y, other->x, other->y) > SUPPORT_BONUSES_MAX_DISTANCE)
                continue;
        }

        if (other->flags & (UNIT_FLAG_UNAVAILABLE | UNIT_FLAG_RESCUED))
            continue;

        levelA = GetUnitSupportLevel(other, GetUnitSupportNumByPid(other, unit->pinfo->id));
        ApplyAffinityBonuses(bonuses, other->pinfo->affinity, levelA);

        levelB = GetUnitSupportLevel(unit, i);
        ApplyAffinityBonuses(bonuses, unit->pinfo->affinity, levelB);

        if (levelA != 0 && levelB != 0)
            result += 1 << (count - 1);
    }

    bonuses->bonus_attack  /= 2;
    bonuses->bonus_defense /= 2;
    bonuses->bonus_hit     /= 2;
    bonuses->bonus_avoid   /= 2;
    bonuses->bonus_crit    /= 2;
    bonuses->bonus_dodge   /= 2;

    return result;
}

int GetUnitAffinityIcon(struct Unit * unit)
{
    int affinity = unit->pinfo->affinity;

    if (affinity == 0)
        return -1;

    return ICON_AFFINITY_BASE + affinity - 1;
}

int GetAffinityIconByPid(int pid)
{
    int affinity = GetPInfo(pid)->affinity;

    if (affinity == 0)
        return -1;

    return ICON_AFFINITY_BASE + affinity - 1;
}

int GetSupportLevelSpecialChar(int level)
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

char const * GetAffinityName(int affinity)
{
    char const * lut[] =
    {
        [0] = JTEXT("ー"),
        [AFFINITY_1] = JTEXT("炎"),
        [AFFINITY_2] = JTEXT("雷"),
        [AFFINITY_3] = JTEXT("風"),
        [AFFINITY_4] = JTEXT("氷"),
        [AFFINITY_5] = JTEXT("闇"),
        [AFFINITY_6] = JTEXT("光"),
        [AFFINITY_7] = JTEXT("理"),
    };

    return lut[affinity];
}
