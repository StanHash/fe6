
#include "ai-order.h"

#include "hardware.h"
#include "item.h"
#include "unit.h"
#include "bm.h"
#include "ai-decide.h"

static u32* CONST_DATA sUnitScores = (u32*) gBuf;

static void AiOrder_Main(ProcPtr proc);

struct ProcScr CONST_DATA ProcScr_AiOrder[] =
{
    PROC_19,
    PROC_REPEAT(AiOrder_Main),
    PROC_END,
};

static void AiOrder_Berserk_Init(ProcPtr proc);
static void AiOrder_End(ProcPtr proc);

struct ProcScr CONST_DATA ProcScr_AiOrder_Berserk[] =
{
    PROC_19,
    PROC_CALL(AiOrder_Berserk_Init),
    PROC_REPEAT(AiOrder_End),
    PROC_END,
};

static void AiOrder_Init(ProcPtr proc);
static void AiOrder_End(ProcPtr proc);

void AiOrder_Main(ProcPtr proc)
{
    typedef void(*OrderFunc)(ProcPtr proc);

    static OrderFunc CONST_DATA funcs[] =
    {
        AiOrder_Init,
        AiOrder_End,
    };

    funcs[gAiSt.order_state++](proc);
}

void AiOrder_Berserk_Init(ProcPtr proc)
{
    int i, count = 0;

    u8 faction = gPlaySt.faction;

    int factionUnitCountLut[3] = { UNIT_AMOUNT_BLUE, UNIT_AMOUNT_GREEN, UNIT_AMOUNT_RED };

    for (i = 0; i < factionUnitCountLut[faction >> 6]; ++i)
    {
        struct Unit* unit = GetUnit(faction+i+1);

        if (!unit->pinfo)
            continue;

        if (unit->status != UNIT_STATUS_BERSERK)
            continue;

        if (unit->state & (US_HIDDEN | US_TURN_ENDED | US_DEAD | US_RESCUED | US_HAS_MOVED_AI))
            continue;

        gAiSt.units[count++] = faction+i+1;
    }

    if (count != 0)
    {
        gAiSt.units[count] = 0;
        gAiSt.unit_it = gAiSt.units;

        AiDecideFunc = AiDecideAll;
        SpawnProcLocking(ProcScr_AiDecide, proc);
    }
}

void AiOrder_Init(ProcPtr proc)
{
    int count = BuildAiUnitList();

    if (count != 0)
    {
        SortAiUnitList(count);

        gAiSt.units[count] = 0;
        gAiSt.unit_it = gAiSt.units;

        AiDecideFunc = AiDecideAll;
        SpawnProcLocking(ProcScr_AiDecide, proc);
    }
}

int GetUnitBattleAiScore(struct Unit* unit)
{
    int i, item;

    u8 rangedCnt = 0;
    u8 meleeCnt = 0;

    for (i = 0; (i < ITEMSLOT_INV_COUNT) && (item = unit->items[i]); ++i)
    {
        if (!CanUnitUseWeapon(unit, item) && !CanUnitUseStaff(unit, item))
            continue;

        if (GetItemAttributes(item) & ITEM_ATTR_STAFF)
        {
            return 72;
        }

        if (GetItemAttributes(item) & ITEM_ATTR_WEAPON)
        {
            int range = GetItemMaxRange(item);

            if (range > 1)
                rangedCnt++;
            else
                meleeCnt++;
        }
    }

    if (rangedCnt != 0)
        return 40;

    if (meleeCnt != 0)
        return 20;

    return 87;
}

int GetUnitAiScore(struct Unit* unit)
{
    int score = UNIT_MOV(unit);

    u16 lead = GetUnitLeaderPid(unit);

    if (UNIT_ATTRIBUTES(unit) & UNIT_ATTR_REFRESHER)
        return score - 149;

    if (!(unit->ai_flags & AI_UNIT_FLAG_0))
    {
        score += lead << 8;

        if (UNIT_ATTRIBUTES(unit) & UNIT_ATTR_STEAL)
            return score + 60;

        if ((unit->pinfo->id == lead) || (UNIT_ATTRIBUTES(unit) & UNIT_ATTR_13))
            return score + 87;

        score = score + GetUnitBattleAiScore(unit);
    }

    return score;
}

int BuildAiUnitList(void)
{
    int i, count = 0;

    u8 faction = gPlaySt.faction;
    u32* prioIt = sUnitScores;

    int factionUnitCountLut[3] = { UNIT_AMOUNT_BLUE, UNIT_AMOUNT_GREEN, UNIT_AMOUNT_RED };

    for (i = 0; i < factionUnitCountLut[faction >> 6]; ++i)
    {
        struct Unit* unit = GetUnit(faction+i+1);

        if (!unit->pinfo)
            continue;

        if (unit->status == UNIT_STATUS_SLEEP)
            continue;

        if (unit->status == UNIT_STATUS_BERSERK)
            continue;

        if (unit->state & (US_HIDDEN | US_TURN_ENDED | US_DEAD | US_RESCUED | US_HAS_MOVED_AI))
            continue;

        gAiSt.units[count] = faction+i+1;
        *prioIt++ = GetUnitAiScore(unit);

        count++;
    }

    return count;
}

void SortAiUnitList(int count)
{
    int i, j;

#if !NONMATCHING
    // This bit is useless but required for match

    if (count < 2)
        return;

    ++count; --count;
#endif

    // this is a bubble sort, I think

    for (i = 0; i <= count - 2; ++i)
    {
        for (j = count - 2; j >= i; --j)
        {
            if (sUnitScores[j] > sUnitScores[j+1])
            {
                // swap

                int tmp;

                tmp = sUnitScores[j];
                sUnitScores[j] = sUnitScores[j+1];
                sUnitScores[j+1] = tmp;

                tmp = gAiSt.units[j];
                gAiSt.units[j] = gAiSt.units[j+1];
                gAiSt.units[j+1] = tmp;
            }
        }
    }
}

void AiOrder_End(ProcPtr proc)
{
    Proc_Break(proc);
}
