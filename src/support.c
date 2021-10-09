
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

int GetUnitSupportCount(struct Unit* unit)
{
    if (!unit->person->supportInfo)
        return 0;

    return unit->person->supportInfo->count;
}

u8 GetUnitSupportPid(struct Unit* unit, int num)
{
    if (!unit->person->supportInfo)
        return 0;

    return unit->person->supportInfo->pids[num];
}

struct Unit* GetUnitSupportUnit(struct Unit* unit, int num)
{
    u8 pid = GetUnitSupportPid(unit, num);

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

int GetUnitSupportLevel(struct Unit* unit, int num)
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

int GetUnitTotalSupportLevel(struct Unit* unit)
{
    int i, count, result;

    count = GetUnitSupportCount(unit);

    for (i = 0, result = 0; i < count; ++i)
        result += GetUnitSupportLevel(unit, i);

    return result;
}

void UnitGainSupportExp(struct Unit* unit, int num)
{
    if (unit->person->supportInfo)
    {
        int gain = unit->person->supportInfo->expGrowth[num];
        int exp = unit->supports[num];
        int maxExp = sMaxExpLut[GetUnitSupportLevel(unit, num)];

        if (exp + gain > maxExp)
            gain = maxExp - exp;

        unit->supports[num] = exp + gain;
        gPlaySt.supportGain += gain;
    }
}

void UnitGainSupportLevel(struct Unit* unit, int num)
{
    unit->supports[num]++;
    gPlaySt.supportGain++;
}

bool CanUnitSupportNow(struct Unit* unit, int num)
{
    int exp, maxExp;

    if (gPlaySt.flags & PLAY_FLAG_5)
        return FALSE;

    if (gPlaySt.flags & PLAY_FLAG_3)
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

int GetUnitInitialSupportExp(struct Unit* unit, int num)
{
    if (!unit->person->supportInfo)
        return -1;

    return unit->person->supportInfo->expBase[num];
}

int GetUnitSupportNumByPid(struct Unit* unit, u8 pid)
{
    int i, count = GetUnitSupportCount(unit);

    for (i = 0; i < count; ++i)
    {
        if (GetUnitSupportPid(unit, i) == pid)
            return i;
    }

    return -1;
}

void ClearUnitSupports(struct Unit* unit)
{
    int i, count = GetUnitSupportCount(unit);

    for (i = 0; i < count; ++i)
    {
        struct Unit* other = GetUnitSupportUnit(unit, i);

        if (!other)
            continue;

        other->supports[GetUnitSupportNumByPid(other, unit->person->id)] = 0;
        unit->supports[i] = 0;
    }
}

void DoTurnSupportExp(void)
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

        if (GetUnitTotalSupportLevel(unit) >= MAX_SIMULTANEOUS_SUPPORT_COUNT)
            continue;

        jend = GetUnitSupportCount(unit);

        for (j = 0; j < jend; ++j)
        {
            struct Unit* other = GetUnitSupportUnit(unit, j);

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
                if (GetUnitTotalSupportLevel(other) < MAX_SIMULTANEOUS_SUPPORT_COUNT)
                    UnitGainSupportExp(unit, j);

                break;

            }
        }
    }
}

static struct SupportBonuses const* GetAffinityBonuses(int affinity)
{
    struct SupportBonuses const* it;

    for (it = AffinityBonuses; it->affinity; ++it)
    {
        if (it->affinity == affinity)
            return it;
    }

    // return NULL; // BUG?
}

static void ApplyAffinityBonuses(struct SupportBonuses* bonuses, int affinity, int level)
{
    struct SupportBonuses const* added = GetAffinityBonuses(affinity);

    bonuses->bonusAttack  += level * added->bonusAttack;
    bonuses->bonusDefense += level * added->bonusDefense;
    bonuses->bonusHit     += level * added->bonusHit;
    bonuses->bonusAvoid   += level * added->bonusAvoid;
    bonuses->bonusCrit    += level * added->bonusCrit;
    bonuses->bonusDodge   += level * added->bonusDodge;
}

static void InitBonuses(struct SupportBonuses* bonuses)
{
    bonuses->bonusAttack  = 0;
    bonuses->bonusDefense = 0;
    bonuses->bonusHit     = 0;
    bonuses->bonusAvoid   = 0;
    bonuses->bonusCrit    = 0;
    bonuses->bonusDodge   = 0;
}

int GetUnitSupportBonuses(struct Unit* unit, struct SupportBonuses* bonuses)
{
    int i, count;
    int result = 0;

    InitBonuses(bonuses);

    count = GetUnitSupportCount(unit);

    for (i = 0; i < count; ++i)
    {
        struct Unit* other;
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

        if (other->state & (US_UNAVAILABLE | US_RESCUED))
            continue;

        levelA = GetUnitSupportLevel(other, GetUnitSupportNumByPid(other, unit->person->id));
        ApplyAffinityBonuses(bonuses, other->person->affinity, levelA);

        levelB = GetUnitSupportLevel(unit, i);
        ApplyAffinityBonuses(bonuses, unit->person->affinity, levelB);

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

int GetUnitAffinityIcon(struct Unit* unit)
{
    int affinity = unit->person->affinity;

    if (!affinity)
        return -1;

    return ICON_AFFINITY_BASE + affinity;
}

int GetAffinityIconByPid(int pid)
{
    int affinity = GetPersonInfo(pid)->affinity;

    if (!affinity)
        return -1;

    return ICON_AFFINITY_BASE + affinity;
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

char const* GetAffinityName(int affinity)
{
    char const* lut[] =
    {
        TEXT("\x81\x5B"), // "ー"
        TEXT("\x89\x8A"), // "炎"
        TEXT("\x97\x8B"), // "雷"
        TEXT("\x95\x97"), // "風"
        TEXT("\x95\x58"), // "氷"
        TEXT("\x88\xC5"), // "闇"
        TEXT("\x8C\xF5"), // "光"
        TEXT("\x97\x9D"), // "理"
    };

    return lut[affinity];
}
