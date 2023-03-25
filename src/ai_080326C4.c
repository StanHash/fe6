
#include "ai.h"

#include "item.h"
#include "unit.h"
#include "map.h"
#include "mapwork.h"
#include "faction.h"
#include "ai_decide.h"
#include "ai_utility.h"
#include "ai_data.h"

#include "constants/iids.h"
#include "constants/terrains.h"

struct Unk_0810DB34
{
    u16 iid;
    void (* func)(int slot, bool (* is_enemy)(struct Unit * unit));
};

struct Unk_0810DB9C
{
    u16 iid;
    void (* func)(int slot);
};

struct Unk_085C98D0
{
    int x, y;
};

struct AiEscapePt const * func_fe6_08032C2C(void);

static void AiFillDangerMap(void);

void func_fe6_08033D5C(int slot, bool (* is_enemy)(struct Unit * unit));
void func_fe6_08033ECC(int slot, bool (* is_enemy)(struct Unit * unit));
void func_fe6_08034094(int slot, bool (* is_enemy)(struct Unit * unit));
void func_fe6_08034178(int slot, bool (* is_enemy)(struct Unit * unit));
void func_fe6_080342C4(int slot, bool (* is_enemy)(struct Unit * unit));
void func_fe6_080344AC(int slot, bool (* is_enemy)(struct Unit * unit));
void func_fe6_0803462C(int slot, bool (* is_enemy)(struct Unit * unit));
void func_fe6_080347A4(int slot, bool (* is_enemy)(struct Unit * unit));

void func_fe6_08034B58(int slot);
void func_fe6_08034BF0(int slot);
void func_fe6_08034CC0(int slot);

u8 EWRAM_DATA gUnk_Pid_02039694 = 0;

void AiRefreshDangerMap(void)
{
    if (!gAiSt.danger_map_filled)
    {
        gAiSt.danger_map_filled = TRUE;

        MapFill(gMapOther, 0);
        AiFillDangerMap();
    }
}

static void AiFillDangerMap(void)
{
    int i, j, ix, iy;

    u16 item = 0;
    u8 might = 0;

    for (i = 1; i < 0xC0; ++i)
    {
        u16 itemTmp;

        struct Unit * unit = GetUnit(i);

        if (unit == NULL)
            continue;

        if (unit->pinfo == NULL)
            continue;

        if (unit->flags & (UNIT_FLAG_HIDDEN | UNIT_FLAG_DEAD | UNIT_FLAG_NOT_DEPLOYED))
            continue;

        if (AreUnitIdsAllied(gActiveUnitId, unit->id))
            continue;

        // BUG: item needs to be set back to 0 here

        for (j = 0; (j < ITEMSLOT_INV_COUNT) && (itemTmp = unit->items[j]); ++j)
        {
            if (!CanUnitUseWeapon(unit, itemTmp))
                continue;

            if (GetItemMight(itemTmp) > might)
            {
                item = itemTmp;
                might = GetItemMight(item);
            }
        }

        if (item == 0)
            continue;

        if (!AiCouldReachByBirdsEyeDistance(gActiveUnit, unit, item))
            continue;

        AiMakeMoveRangeMapsForUnitAndWeapon(unit, item);

        for (iy = gMapSize.y-1; iy >= 0; --iy)
        {
            for (ix = gMapSize.x-1; ix >= 0; --ix)
            {
                if (gMapRangeSigned[iy][ix] == 0)
                    continue;

                gMapOther[iy][ix] += (GetUnitPower(unit) + might) >> 1;
            }
        }
    }
}

bool AiCheckDangerAt(int x, int y, u8 threshold)
{
    if (gMapOther[y][x] > threshold)
        return FALSE;

    return TRUE;
}

bool AiTryGetNearestHealPoint(struct Vec2i * out)
{
    static u8 CONST_DATA fortTerrains[] = { TERRAIN_FORT, 0 };

    struct Unit * unit;

    int ix, iy;

    int currentCount = 10000;
    int currentMove = UINT8_MAX;

    if (gActiveUnit->ai_config & AI_UNIT_CONFIG_FLAG_UNK13)
        return FALSE;

    if (UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_LORD)
        return FALSE;

    MapFlood_08019384(gActiveUnit, MAP_MOVEMENT_EXTENDED);

    for (iy = gMapSize.y-1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x-1; ix >= 0; --ix)
        {
            int count;

            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if (!AiIsInByteList(fortTerrains, gMapTerrain[iy][ix]))
            {
                if (gMapUnit[iy][ix] == 0 || !AreUnitIdsAllied(gActiveUnitId, gMapUnit[iy][ix]))
                    continue;

                unit = GetUnit(gMapUnit[iy][ix]);

                if (!(unit->ai_flags & AI_UNIT_FLAG_2))
                    continue;
            }
            else
            {
                if (gMapUnit[iy][ix] != 0)
                {
                    if (!AreUnitIdsAllied(gActiveUnitId, gMapUnit[iy][ix]))
                        continue;

                    unit = GetUnit(gMapUnit[iy][ix]);

                    if (unit->ai_config & AI_UNIT_CONFIG_FLAG_UNK13)
                        if (!(unit->ai_flags & AI_UNIT_FLAG_2))
                            continue;
                }
            }

            count = AiCountNearbyEnemyUnits(ix, iy);

            if ((count <= currentCount) && (gMapMovementSigned[iy][ix] <= currentMove))
            {
                currentCount = count;
                currentMove = gMapMovement[iy][ix];
                out->x = ix;
                out->y = iy;
            }
        }
    }

    if (currentMove != 0xFF)
    {
        if (gMapUnit[out->y][out->x] != 0 && gMapUnit[out->y][out->x] != gActiveUnitId)
        {
            unit = GetUnit(gMapUnit[out->y][out->x]);
            unit->ai_flags |= AI_UNIT_FLAG_1;
        }

        return TRUE;
    }

    return FALSE;
}

void func_fe6_08032A08(void)
{
    int i, count = 0;

    u8 faction = gPlaySt.faction;

    int factionUnitCountLut[3] = { UNIT_AMOUNT_BLUE, UNIT_AMOUNT_GREEN, UNIT_AMOUNT_RED };

    for (i = 0; i < factionUnitCountLut[faction >> 6]; ++i)
    {
        struct Unit * unit = GetUnit(faction+i+1);

        if (!unit)
            continue;

        if (!unit->pinfo)
            continue;

        AiUpdateGetUnitIsHealing(unit);
    }
}

bool AiUpdateGetUnitIsHealing(struct Unit * unit)
{
    u16 hpPercentage = Div(GetUnitCurrentHp(unit) * 100, GetUnitMaxHp(unit));

    if (unit->ai_flags & AI_UNIT_FLAG_SEEK_HEALING)
    {
        if (gUnk_085C8820[unit->ai_config & AI_UNIT_CONFIG_HEALTHRESHOLD_MASK].exit_threshold > hpPercentage)
        {
            return TRUE;
        }
        else
        {
            unit->ai_flags &= ~AI_UNIT_FLAG_SEEK_HEALING;
            return FALSE;
        }
    }
    else
    {
        if (gUnk_085C8820[unit->ai_config & AI_UNIT_CONFIG_HEALTHRESHOLD_MASK].enter_threshold > hpPercentage)
        {
            unit->ai_flags |= AI_UNIT_FLAG_SEEK_HEALING;
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
}

bool AiTryHealSelf(void)
{
    int i;

    for (i = 0; i < ITEMSLOT_INV_COUNT; ++i)
    {
        u16 item = gActiveUnit->items[i];

        if (item == 0)
            return FALSE;

        if (GetItemIid(item) == IID_VULNERARY || GetItemIid(item) == IID_ELIXIR)
        {
            if (!(gAiSt.flags & AI_FLAG_1))
            {
                struct Vec2i position;

                if (AiFindSafestReachableLocation(gActiveUnit, &position) == TRUE)
                {
                    AiSetDecision(position.x, position.y, AI_ACTION_USEITEM, 0, i, 0, 0);
                    return TRUE;
                }
            }
            else
            {
                AiSetDecision(gActiveUnit->x, gActiveUnit->y, AI_ACTION_USEITEM, 0, i, 0, 0);
                return TRUE;
            }
        }
    }

    return FALSE;
}

bool AiTryMoveTowardsEscape(void)
{
    struct AiEscapePt const * escapePt;

    MapFlood_08019384(gActiveUnit, MAP_MOVEMENT_EXTENDED);
    escapePt = func_fe6_08032C2C();

    if (escapePt != NULL)
    {
        if (gMapMovementSigned[escapePt->y][escapePt->x] <= UNIT_MOV(gActiveUnit))
        {
            AiTryMoveTowards(escapePt->x, escapePt->y, AI_ACTION_NONE, -1, TRUE);

            AiSetDecision(gAiDecision.x_move, gAiDecision.y_move, AI_ACTION_ESCAPE,
                escapePt->x, escapePt->y, escapePt->facing, 0);

            return TRUE;
        }
        else
        {
            AiTryMoveTowards(escapePt->x, escapePt->y, AI_ACTION_NONE, -1, FALSE);
            return gAiDecision.action_performed;
        }
    }

    return FALSE;
}

struct AiEscapePt const * func_fe6_08032C2C(void)
{
    int i = 0;

    struct AiEscapePt const * list = NULL;
    struct AiEscapePt const * result = NULL;

    int chapter = gPlaySt.chapter;

    u8 resultMove = UINT8_MAX;

    switch (gPlaySt.faction)
    {

    case FACTION_BLUE:
        return NULL;

    case FACTION_RED:
        list = gUnk_085C86B8[chapter];
        break;

    case FACTION_GREEN:
        list = gUnk_085C876C[chapter];
        break;

    }

    for (; list[i].x != UINT8_MAX; ++i)
    {
        if (gMapMovement[list[i].y][list[i].x] > MAP_MOVEMENT_MAX)
            continue;

        if (resultMove > gMapMovementSigned[list[i].y][list[i].x])
        {
            resultMove = gMapMovementSigned[list[i].y][list[i].x];
            result = list+i;
        }
    }

    return result;
}

bool func_fe6_08032CB4(void)
{
    if (gActiveUnit->flags & UNIT_FLAG_HAD_ACTION)
        return FALSE;

    if (gAiDecision.action_id == AI_ACTION_COMBAT)
        return FALSE;

    if (gActiveUnit->status == UNIT_STATUS_BERSERK)
        return FALSE;

    return TRUE;
}

bool func_fe6_08032CE8(u16 * out)
{
    int i;

    u32 perc;

    if (GetUnitItemCount(gActiveUnit) == 0)
        return FALSE;

    for (i = 0; i < ITEMSLOT_INV_COUNT; ++i)
    {
        u16 item;

        out[i] = 0;

        item = gActiveUnit->items[i];

        if (item == 0)
            break;

        if (!(GetItemAttributes(item) & (ITEM_ATTR_WEAPON | ITEM_ATTR_STAFF)))
            continue;

        if (GetItemAttributes(item) & ITEM_ATTR_LOCK_DRAGON)
            continue;

        if (!CanUnitUseWeapon(gActiveUnit, item) && !CanUnitUseStaff(gActiveUnit, item))
            continue;

        if (GetItemAttributes(item) & ITEM_ATTR_WEAPON)
        {
            if (GetItemMinRange(item) > 1)
                out[i] |= 2;

            if (GetItemMaxRange(item) == 1)
                out[i] |= 1;

            perc = Div(perc = GetItemUses(item) * 100, GetItemMaxUses(item));

            if (perc <= 10)
                out[i] |= 4;
        }
        else
        {
            func_fe6_08032FBC(item);
            out[i] |= 8;
        }

        out[i] |= (GetItemMight(item) << 8);
    }

#ifdef BUGFIX
    return TRUE;
#endif
}

struct Unk_0810DB34 const gUnk_0810DB34[] =
{
    { IID_HEALSTAFF, func_fe6_08033D5C },
    { IID_MENDSTAFF, func_fe6_08033D5C },
    { IID_RECOVERSTAFF, func_fe6_08033D5C },
    { IID_PHYSICSTAFF, func_fe6_08033ECC },
    { IID_FORTIFYSTAFF, func_fe6_08034094 },
    { IID_WARPSTAFF, func_fe6_08034178 },
    { IID_RESCUESTAFF, func_fe6_08033ECC },
    { IID_RESTORESTAFF, func_fe6_080342C4 },
    { IID_SILENCESTAFF, func_fe6_080344AC },
    { IID_SLEEPSTAFF, func_fe6_0803462C },
    { IID_BERSERKSTAFF, func_fe6_0803462C },
    { IID_BARRIERSTAFF, func_fe6_080347A4 },
    {},
};

struct Unk_0810DB9C const gUnk_0810DB9C[] =
{
    { IID_DOORKEY, func_fe6_08034B58 },
    { IID_LOCKPICK, func_fe6_08034BF0 },
    { IID_ANTITOXIN, func_fe6_08034CC0 },
    {},
};

struct Unk_085C98D0 CONST_DATA gUnk_085C98D0[] =
{
    { +1,  0 },
    { -1,  0 },
    {  0, +1 },
    {  0, -1 },
};

u8 CONST_DATA gUnk_085C98F0[] =
{
    TERRAIN_DOOR, 0,
};

u8 CONST_DATA gUnk_085C98F2[] =
{
    TERRAIN_CHEST, 0,
};
