#include "ai.h"

#include "random.h"
#include "item.h"
#include "unit.h"
#include "map.h"
#include "mapwork.h"
#include "faction.h"
#include "ai_decide.h"
#include "ai_utility.h"
#include "ai_data.h"
#include "ai_battle.h"

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

        for (iy = gMapSize.y - 1; iy >= 0; --iy)
        {
            for (ix = gMapSize.x - 1; ix >= 0; --ix)
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

    for (iy = gMapSize.y - 1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x - 1; ix >= 0; --ix)
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

void func_fe6_08032DF4(int x, int y, u16 * ranged_danger, u16 * melee_danger, u16 * combined_danger)
{
    int iy, ix;
    int might;
    u16 item;

    *combined_danger = 0;
    *melee_danger = 0;
    *ranged_danger = 0;

    MapFill(gMapOther, 0);

    FOR_UNITS_ALL(unit,
    {
        if ((unit->flags & (UNIT_FLAG_HIDDEN | UNIT_FLAG_RESCUED)) != 0)
            continue;

        if (AreUnitIdsAllied(gActiveUnitId, unit->id))
            continue;

        if (!func_fe6_08032FF4(unit, x, y))
            continue;

        MapFlood_08019344(unit);

        if (gMapMovement[y][x] == 0xFF)
            continue;

        might = func_fe6_08033038(unit, &item);

        if (GetItemMinRange(item) > 1)
            *ranged_danger += might;

        if (GetItemMaxRange(item) == 1)
            *melee_danger += might;

        for (iy = gMapSize.y - 1; iy >= 0; iy--)
        {
            for (ix = gMapSize.x - 1; ix >= 0; ix--)
            {
                if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                    continue;

                if (gMapOther[iy][ix] + might <= UINT8_MAX)
                    gMapOther[iy][ix] = gMapOther[iy][ix] + might;
                else
                    gMapOther[iy][ix] = UINT8_MAX;
            }
        }
    })

    *combined_danger = *ranged_danger + *melee_danger;
}

void func_fe6_08032F48(int arg_0, u16 * arg_1) {

    int i;

    int item_slot = -1;
    u16 unk = 0;

    for (i = 0; i < ITEMSLOT_INV_COUNT; i++)
    {
        if (arg_1[i] == 0)
            continue;

        if ((arg_1[i] & arg_0) == 0)
            continue;

        if ((arg_1[i] & 0xFF00) > unk)
        {
            unk = arg_1[i] & 0xFF00;
            item_slot = i;
        }
    }

    if (item_slot > 0)
        UnitEquipItemSlot(gActiveUnit, item_slot);
}

void func_fe6_08032F94(u16 arg_0, u16 arg_1, u16 arg_2, u16 * arg_3)
{
    if ((arg_1 + arg_0) != 0)
    {
        if (arg_1 >= arg_0)
            func_fe6_08032F48(1, arg_3);
        else
            func_fe6_08032F48(2, arg_3);
    }
}

void func_fe6_08032FBC(u16 item)
{
    switch (GetItemIid(item))
    {
        case IID_HEALSTAFF:
        case IID_MENDSTAFF:
        case IID_RECOVERSTAFF:
        case IID_PHYSICSTAFF:
        case IID_FORTIFYSTAFF:
            gActiveUnit->ai_flags |= AI_UNIT_FLAG_2;
            break;

        case IID_HAMMERNESTAFF:
            gActiveUnit->ai_flags |= AI_UNIT_FLAG_4;
            break;
    }
}

bool func_fe6_08032FF4(struct Unit * unit, int x, int y)
{
    int mov = UNIT_MOV(unit);
    int dist = RECT_DISTANCE(x, y, unit->x, unit->y);

    if (mov >= dist)
        return TRUE;

    return FALSE;
}

int func_fe6_08033038(struct Unit * unit, u16 * item_out)
{
    u16 item = GetUnitEquippedWeapon(unit);

    *item_out = item;
    return GetUnitPower(unit) + GetItemMight(item);
}

void AiTryDanceOrStealAfterMove(void)
{
    if (gAiDecision.action_id == AI_ACTION_ESCAPE)
        return;

    if (func_fe6_080330C8(gAiDecision.x_move, gAiDecision.y_move) == 1)
        return;

    func_fe6_080331EC(gAiDecision.x_move, gAiDecision.y_move);
}

void AiTryActionAfterMove(void)
{
    if (func_fe6_080330C8(gAiDecision.x_move, gAiDecision.y_move) == 1)
        return;

    if (func_fe6_080331EC(gAiDecision.x_move, gAiDecision.y_move) == 1)
        return;

    func_fe6_08033250(gAiDecision.x_move, gAiDecision.y_move);
}

bool func_fe6_080330C8(int x, int y)
{
    int ix, iy;
    struct Unit * unit;

    u8 level = 0;
    u8 target = 0;

    if ((UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_REFRESHER) == 0)
        return FALSE;

    MapFill(gMapMovement, -1);
    MapAddInRange(x, y, 1, 1);

    for (iy = gMapSize.y - 1; iy >= 0; iy--)
    {
        for (ix = gMapSize.x - 1; ix >= 0; ix--)
        {
            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if (gMapUnit[iy][ix] == 0)
                continue;

            if (!AreUnitIdsAllied(gActiveUnitId, gMapUnit[iy][ix]))
                continue;

            unit = GetUnit(gMapUnit[iy][ix]);

            if ((UNIT_ATTRIBUTES(unit) & UNIT_ATTR_REFRESHER) != 0)
                continue;

            if (level < unit->level)
            {
                level = unit->level;
                target = gMapUnit[iy][ix];
            }
        }
    }

    if (level != 0)
    {
        AiSetDecision(x, y, AI_ACTION_REFRESH, target, 0, 0, 0);
        return TRUE;
    }

    return FALSE;
}

bool func_fe6_080331EC(int x, int y)
{
    if ((UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_STEAL) == 0)
        return FALSE;

    MapFill(gMapMovement, -1);

    gMapMovement[y][x] = 0;
    MapAddInRange(x, y, 1, MAP_MOVEMENT_MAX);

    if (AiAttemptStealActionWithinMovement() != -1)
        return TRUE;

    return FALSE;
}

bool func_fe6_08033250(int x, int y)
{
    int ix, iy;
    struct Unit * unit;

    u16 item = GetUnitEquippedWeapon(gActiveUnit);

    if (item == 0)
        return FALSE;

    MapFill(gMapMovement, 0);
    MapIncInBoundedRange(x, y, GetItemMinRange(item), GetItemMaxRange(item));

    for (iy = gMapSize.y - 1; iy >= 0; iy--)
    {
        for (ix = gMapSize.x - 1; ix >= 0; ix--)
        {
            if (gMapMovementSigned[iy][ix] == 0)
                continue;

            if (gMapUnit[iy][ix] == 0)
                continue;

            if (AreUnitIdsAllied(gActiveUnitId, gMapUnit[iy][ix]) == 1)
                continue;

            unit = GetUnit(gMapUnit[iy][ix]);

            if (AiGetInRangeCombatPositionScoreComponent(x, y, unit))
            {
                AiSetDecision(x, y, AI_ACTION_COMBAT, unit->id, GetUnitEquippedWeaponSlot(gActiveUnit), 0, 0);
                return TRUE;
            }
        }
    }

    return FALSE;
}

bool func_fe6_08033380(int x, int y)
{
    if (gMapUnit[y][x] == 0)
        return FALSE;

    if ((gActiveUnitId ^ gMapUnit[y][x]) & 0x80)
        return TRUE;

    return FALSE;
}

bool func_fe6_080333B0(void const * input)
{
    u8 const * cast = input;

    u16 item;
    int ix, iy;
    u16 move;

    u8 count = 0;

    move = (UNIT_MOV(gActiveUnit) * cast[0]);
    move = move >> 4;

    item = GetUnitEquippedWeapon(gActiveUnit);

    if ((cast[1] != 0) && item != 0)
    {
        AiFloodMovementAndRange(gActiveUnit, move, item);

        for (iy = gMapSize.y - 1; iy >= 0; iy--)
        {
            for (ix = gMapSize.x - 1; ix >= 0; ix--)
            {
                if (gMapRangeSigned[iy][ix] == 0)
                    continue;

                if (func_fe6_08033380(ix, iy) == 1)
                    count++;
            }
        }
    }
    else
    {
        SetWorkingMovTable(gActiveUnit->jinfo->mov_table);
        SetWorkingMap(gMapRange);

        BeginMapFlood(gActiveUnit->x, gActiveUnit->y, move, 0);

        for (iy = gMapSize.y - 1; iy >= 0; iy--)
        {
            for (ix = gMapSize.x - 1; ix >= 0; ix--)
            {
                if (gMapRange[iy][ix] > MAP_MOVEMENT_MAX)
                    continue;

                if (func_fe6_08033380(ix, iy) == 1)
                    count++;
            }
        }
    }

    gAiSt.cmd_result[cast[2]] = count;

    return 0;
}

struct Unknown_Sub80315C
{
    /* 00 */ u8 * unk_00;
    /* 04 */ u8 unk_04;
    /* 05 */ u8 unk_05;
};

bool func_fe6_080334F4(struct Unknown_Sub80315C const * input)
{
    u16 item;
    int ix;
    int iy;
    int x_unk;
    int y_unk;
    u16 move;
    int x_prev;
    int y_prev;

    move = UNIT_MOV(gActiveUnit) * input->unk_04;
    move = move >> 4;

    item = GetUnitEquippedWeapon(gActiveUnit);

    x_unk = input->unk_00[((gActiveUnit->ai_config & 0x1fc0) >> 8)*2+0];
    y_unk = input->unk_00[((gActiveUnit->ai_config & 0x1fc0) >> 8)*2+1];

    x_prev = gActiveUnit->x;
    y_prev = gActiveUnit->y;

    gActiveUnit->x = x_unk;
    gActiveUnit->y = y_unk;

    if ((input->unk_05 != 0) && (item != 0))
    {
        AiFloodMovementAndRange(gActiveUnit, move, item);

        if (gMapRangeSigned[y_unk][x_unk] == 0)
        {
            gActiveUnit->x = x_prev;
            gActiveUnit->y = y_prev;
            AiTryMoveTowards(x_unk, y_unk, 0, 0xff, 1);
            return TRUE;
        }
    }
    else
    {
        SetWorkingMovTable(gActiveUnit->jinfo->mov_table);

        SetWorkingMap(gMapRange);
        BeginMapFlood(gActiveUnit->x, gActiveUnit->y, move, 0);

        if (gMapRange[y_unk][x_unk] > MAP_MOVEMENT_MAX)
        {
            gActiveUnit->x = x_prev;
            gActiveUnit->y = y_prev;
            AiTryMoveTowards(x_unk, y_unk, 0, 0xff, 1);
            return TRUE;
        }
    }

    gActiveUnit->x = x_prev;
    gActiveUnit->y = y_prev;

    MapFlood_08019344(gActiveUnit);

    for (iy = gMapSize.y - 1; iy >= 0; iy--)
    {
        for (ix = gMapSize.x - 1; ix >= 0; ix--)
        {
            if (item != 0)
            {
                if ((gMapMovementSigned[iy][ix] < MAP_MOVEMENT_MAX) && (gMapRangeSigned[iy][ix] != 0))
                    continue;

                gMapMovementSigned[iy][ix] = -1;
            }
            else
            {
                if ((gMapMovementSigned[iy][ix] < MAP_MOVEMENT_MAX) && (gMapRangeSigned[iy][ix] < MAP_MOVEMENT_MAX))
                    continue;

                gMapMovementSigned[iy][ix] = -1;
            }
        }
    }

    AiAttemptCombatWithinMovement(AiIsUnitEnemy);

    if (gAiDecision.action_performed == TRUE)
        return TRUE;

    AiTryMoveTowards(x_unk, y_unk, 0, UINT8_MAX, 1);

    return TRUE;
}

bool func_fe6_080336B0(void const * no_input)
{
    gAiSt.cmd_result[0] = gActiveUnit->unk_46;
    return FALSE;
}

bool func_fe6_080336CC(void const * no_input)
{
    int alliance = GetActiveFactionAlliance();

    // hm...
    FOR_UNITS(alliance + 1, alliance + 0x80, unit,
    {
    })

    gAiSt.decide_state = 0;

    return FALSE;
}

bool func_fe6_080336FC(void const * no_input)
{
    int alliance = GetActiveFactionAlliance();

    // hm...
    FOR_UNITS(alliance + 1, alliance + 0x80, unit,
    {
    })

    gAiSt.decide_state = 0;

    return FALSE;
}

bool func_fe6_0803372C(struct Vec2i * out)
{
    struct Vec2i const * pos_a;
    struct Vec2i const * pos_b;

    int idx = (gActiveUnit->ai_config & 0x1FC0) >> 8;
    int unk46 = gActiveUnit->unk_46;

    if (gUnk_085C8878 == NULL)
        return FALSE;

    pos_a = gUnk_085C8878[idx];

    if (pos_a == NULL)
        return FALSE;

    pos_b = pos_a + unk46;

    if (pos_b->x == -1)
    {
        unk46 = 0;
        gActiveUnit->unk_46 = 0;
        pos_b = pos_a;
    }

    out->x = pos_b->x;
    out->y = pos_b->y;

    if (gMapMovement[pos_b->y][pos_b->x] != 0xFF)
    {
        unk46++;
        gActiveUnit->unk_46 = unk46;
    }

    return TRUE;
}

bool func_fe6_080337B4(void const * input)
{
    int enemies_in_range;
    struct Vec2i pos;

    u16 item = GetUnitEquippedWeapon(gActiveUnit);

    if (item != 0)
    {
        AiMakeMoveRangeMapsForUnitAndWeapon(gActiveUnit, item);
        enemies_in_range = AiCountEnemyUnitsInRange();

        if (enemies_in_range != 0)
        {
            gAiSt.cmd_result[0] = enemies_in_range;
            return FALSE;
        }
    }
    else
    {
        MapFlood_08019344(gActiveUnit);
    }

    if (func_fe6_0803372C(&pos) == 1)
    {
        AiTryMoveTowards(pos.x, pos.y, 0, 0xff, 1);
        return TRUE;
    }

    return FALSE;
}

struct UnknownSub803F4A4
{
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
};

bool func_fe6_08033824(void const * input)
{
    struct UnknownSub803F4A4 const * cast = input;

    u8 x = gActiveUnit->x;
    u8 y = gActiveUnit->y;

    if (cast->unk_00 <= x && cast->unk_02 >= x && cast->unk_01 <= y && cast->unk_03 >= y)
    {
        gAiSt.cmd_result[0] = 1;
        return FALSE;
    }

    gAiSt.cmd_result[0] = 0;
    return FALSE;
}

bool AiFunc_DecideTalk(void const * input)
{
    u8 const * pids = input;

    AiUpdateDecision(AI_ACTION_TALK, 0,
        GetUnitByPid(pids[0])->id, GetUnitByPid(pids[1])->id, 0xff);

    return TRUE;
}

bool func_fe6_08033898(void const * input)
{
    int i = 0;

    u16 lead_ai_a;
    u16 lead_ai_a_pc;
    struct Unit * lead_unit;

    u8 unit_id = gActiveUnitId;
    struct Unit * unit = gActiveUnit;

    u16 lead_unit_id = GetUnitLeaderPid(gActiveUnit);

    if (lead_unit_id == 0)
        return FALSE;

    lead_unit = GetUnitByPid(lead_unit_id);

    gActiveUnit = lead_unit;

    if (lead_unit == 0)
    {
        gActiveUnit = unit;
        gAiSt.cmd_result[1] = 1;

        return FALSE;
    }

    gActiveUnitId = lead_unit->id;

    lead_ai_a = lead_unit->ai_a;
    lead_ai_a_pc = lead_unit->ai_a_pc;

    for (; i < 0x100; i++)
    {
        if (AiTryExecScriptA() == TRUE)
            goto skip_fallback;
    }

    AiExecFallbackScriptA();

skip_fallback:
    if ((gAiDecision.action_performed == 1) && (gAiDecision.action_id == AI_ACTION_COMBAT))
    {
        gAiSt.cmd_result[0] = gAiDecision.target_id;
    }
    else
    {
        gAiSt.cmd_result[0] = 0;
    }

    AiClearDecision();

    gActiveUnit->ai_a = lead_ai_a;
    gActiveUnit->ai_a_pc = lead_ai_a_pc;

    gActiveUnitId = unit_id;
    gActiveUnit = unit;

    return FALSE;
}

bool func_fe6_0803395C(struct Unit * unit)
{
    if (UNIT_PID(unit) != gUnk_Pid_02039694)
        return FALSE;

    if (AreUnitIdsAllied(gActiveUnit->id, unit->id))
        return FALSE;

    return TRUE;
}

bool func_fe6_08033998(void const * input)
{
    u8 const * cast = input;

    gUnk_Pid_02039694 = cast[0];

    if (AiUnitWithPidExists(cast[0]) != 1)
    {
        gAiSt.cmd_result[1] = 1;
        return FALSE;
    }

    AiAttemptOffensiveAction(func_fe6_0803395C);

    gAiSt.cmd_result[0] = 0;

    if ((gAiDecision.action_performed == 1) && (gAiDecision.action_id == AI_ACTION_COMBAT))
        gAiSt.cmd_result[0] = gAiDecision.target_id;

    AiClearDecision();

    return FALSE;
}

bool func_fe6_080339F8(struct Unit * unit)
{
    if (unit->id != gAiSt.cmd_result[0])
        return FALSE;

    if (AreUnitIdsAllied(gActiveUnit->id, unit->id))
        return FALSE;

    return TRUE;
}

bool func_fe6_08033A30(struct Unit * unit)
{
    int a;
    int b;
    int c;
    int d;

    struct Unit * other = GetUnit(gAiSt.cmd_result[0]);

    a = other->x - gActiveUnit->x;
    b = other->y - gActiveUnit->y;
    c = unit->x - gActiveUnit->x;
    d = unit->y - gActiveUnit->y;

    if (AreUnitIdsAllied(gActiveUnit->id, unit->id))
        return FALSE;

    if ((a * c) < 0)
        return FALSE;

    if ((d * b) < 0)
        return FALSE;

    return TRUE;
}

bool func_fe6_08033AA4(void const * input)
{
    struct Unit * unit;

    if (gAiSt.cmd_result[0] == 0)
        return TRUE;

    unit = GetUnit(gAiSt.cmd_result[0]);

    AiAttemptOffensiveAction(func_fe6_080339F8);

    if (gAiDecision.action_performed == 1)
        return TRUE;

    AiAttemptOffensiveAction(func_fe6_08033A30);

    if (gAiDecision.action_performed == 1)
        return TRUE;

    AiTryMoveTowards(unit->x, unit->y, 0, 0xff, 1);
    return TRUE;
}

bool func_fe6_08033B04(void const * input)
{
    u8 const * cast = input;
    u8 random_number = RandNext(100);

    gAiSt.unk_7C = cast[1];

    if (random_number <= cast[0])
    {
        if (func_fe6_08033C04(AiIsUnitEnemy) == FALSE)
            AiAttemptOffensiveAction(AiIsUnitEnemy);

        return TRUE;
    }

    gAiSt.decide_state = 4;
    return TRUE;
}

bool func_fe6_08033B50(void const * input)
{
    u8 const * cast = input;
    u8 random_number = RandNext(100);

    if (random_number <= cast[0])
    {
        if (AiTryDoSpecialItems() != FALSE)
            return TRUE;

        // this was also fixed in fe8 (maybe fe7)
#if BUGFIX
        random_number = RandNext(100);
#else
        RandNext(100);
#endif

        if (random_number <= cast[1])
            AiAttemptOffensiveAction(AiIsUnitEnemy);

        return TRUE;
    }

    gAiSt.decide_state = 4;
    return TRUE;
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
    { 0 }, // end
};

struct Unk_0810DB9C const gUnk_0810DB9C[] =
{
    { IID_DOORKEY, func_fe6_08034B58 },
    { IID_LOCKPICK, func_fe6_08034BF0 },
    { IID_ANTITOXIN, func_fe6_08034CC0 },
    { 0 }, // end
};

int func_fe6_08033B9C(u16 item)
{
    u16 iid;
    int i = 0;

    if (!CanUnitUseStaff(gActiveUnit, item))
        return -1;

    iid = GetItemIid(item);

    for (i = 0; gUnk_0810DB34[i].iid != 0; i++)
    {
        if (iid == gUnk_0810DB34[i].iid && gUnk_0810DB34[i].func != NULL)
            return i;
    }

    return -1;
}

struct Unk_085C98D0 CONST_DATA gUnk_085C98D0[] =
{
    { +1,  0 },
    { -1,  0 },
    {  0, +1 },
    {  0, -1 },
};

bool func_fe6_08033C04(bool (* is_enemy)(struct Unit * unit))
{
    int i, item;
    int ent_id;

    u8 max_wexp = 0;

    for (i = 0; i < ITEMSLOT_INV_COUNT && (item = gActiveUnit->items[i]) != 0; ++i)
    {
        // hm...
        if ((GetItemAttributes(item) & ITEM_ATTR_STAFF) == 0)
        {
        }

        if (GetItemRequiredExp(item) < max_wexp)
            continue;

        ent_id = func_fe6_08033B9C(item);

        if (ent_id != -1)
        {
            gUnk_0810DB34[ent_id].func(i, is_enemy);
            max_wexp = GetItemRequiredExp(item);
        }
    }

    return gAiDecision.action_performed;
}

bool func_fe6_08033C8C(int x_center, int y_center, struct Vec2i * pos_out)
{
    u32 score, score_max = 0;

    int i;

    for (i = 0; i < (int) ARRAY_COUNT(gUnk_085C98D0); i++)
    {
        int x = x_center + gUnk_085C98D0[i].x;
        int y = y_center + gUnk_085C98D0[i].y;

        if (gMapMovement[y][x] >= MAP_MOVEMENT_MAX)
            continue;

        if (gMapUnit[y][x] != 0 && gMapUnit[y][x] != gActiveUnitId)
            continue;

        score = AiGetTerrainCombatPositionScoreComponent(x, y);
        score = score + AiGetFriendZoneCombatPositionScoreComponent(x, y);

        score = score - gMapOther[y][x] / 8;
        score = score + INT32_MAX; // this is probably to ensure the value is not 0 per chance

        if (score_max < score)
        {
            pos_out->x = x;
            pos_out->y = y;
            score_max = score;
        }
    }

    if (score_max != 0)
        return TRUE;

    return FALSE;
}

void func_fe6_08033D5C(int slot, bool (* is_enemy)(struct Unit * unit))
{
    int iy, ix;
    struct Unit * unit;
    struct Vec2i pos;

    // lower is better
    u8 score_min = 100;
    u8 score;

    int x_decide = -1;
    int y_decide = -1;
    int target_decide = 0;

    func_fe6_08030CBC(gActiveUnit);
    MapMovementMarkFloodEdges();

    if (gAiSt.unk_7C != 0)
        score_min = gAiSt.unk_7C;

    for (iy = gMapSize.y - 1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x - 1; ix >= 0; --ix)
        {
            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if (gMapUnit[iy][ix] == 0 || gMapUnit[iy][ix] == gActiveUnitId)
                continue;

            unit = GetUnit(gMapUnit[iy][ix]);

            if ((gAiSt.flags & AI_FLAG_BERSERKED) == 0 && is_enemy != NULL)
            {
                if (is_enemy(unit) == TRUE)
                    continue;
            }

            if (gAiSt.unk_7C == 0 && (unit->ai_flags & AI_UNIT_FLAG_SEEK_HEALING) == 0)
                continue;

            score = Div(100 * GetUnitCurrentHp(unit), GetUnitMaxHp(unit));

            if (score <= score_min && func_fe6_08033C8C(ix, iy, &pos))
            {
                score_min = score;
                x_decide = pos.x;
                y_decide = pos.y;
                target_decide = gMapUnit[iy][ix];
            }
        }
    }

    if (x_decide != -1)
    {
        AiSetDecision(x_decide, y_decide, AI_ACTION_STAFF, target_decide, slot, 0, 0);
    }
}

void func_fe6_08033ECC(int slot, bool (* is_enemy)(struct Unit * unit))
{
    struct Vec2i pos;

    // lower is better
    u8 score_min = 100;
    u8 score;

    int x_decide = -1;
    int y_decide = -1;
    int target_decide = 0;

    if ((gAiSt.flags & AI_FLAG_BERSERKED) != 0)
        return;

    func_fe6_08030CBC(gActiveUnit);

    if (gAiSt.unk_7C != 0)
        score_min = gAiSt.unk_7C;

    FOR_UNITS_ALL(unit,
    {
        if (gMapUnit[unit->y][unit->x] == gActiveUnitId)
            continue;

        if ((unit->flags & (UNIT_FLAG_HIDDEN | UNIT_FLAG_DEAD)) != 0)
            continue;

        if ((gAiSt.flags & AI_FLAG_BERSERKED) == 0 && is_enemy != NULL)
        {
            if (is_enemy(unit) == TRUE)
                continue;
        }

        if (gAiSt.unk_7C == 0 && (unit->ai_flags & AI_UNIT_FLAG_SEEK_HEALING) == 0)
            continue;

        if (!AiIsWithinRectDistance(
            gActiveUnit->x, gActiveUnit->y,
            unit->x, unit->y,
            GetUnitMagRange(gActiveUnit) + UNIT_MOV(gActiveUnit)))
        {
            continue;
        }

        MapFill(gMapRange, 0);
        MapAddInRange(unit->x, unit->y, GetUnitMagRange(gActiveUnit), 1);

        if (!func_fe6_08030AB4(&pos))
            continue;

        score = Div(100 * GetUnitCurrentHp(unit), GetUnitMaxHp(unit));

        if (score <= score_min)
        {
            score_min = score;
            x_decide = pos.x;
            y_decide = pos.y;
            target_decide = gMapUnit[unit->y][unit->x];
        }
    })

    if (x_decide != -1)
    {
        AiSetDecision(x_decide, y_decide, AI_ACTION_STAFF, target_decide, slot, 0, 0);
    }
}



void func_fe6_08034094(int slot, bool (* is_enemy)(struct Unit * unit))
{
    int ix, iy;

    int score_max = 0;
    int score;

    int x_decide = 0;
    int y_decide = 0;

    if ((gAiSt.flags & AI_FLAG_BERSERKED) != 0)
        return;

    if (func_fe6_08030B94() < 3)
        return;

    func_fe6_08030CBC(gActiveUnit);

    for (iy = gMapSize.y - 1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x - 1; ix >= 0; --ix)
        {
            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            MapFill(gMapRange, 0);
            MapAddInRange(ix, iy, GetUnitMagRange(gActiveUnit), 1);

            score = func_fe6_08030BDC();

            if (score > score_max)
            {
                score_max = score;
                x_decide = ix;
                y_decide = iy;
            }
        }
    }

    if (score_max > 1)
    {
        AiSetDecision(x_decide, y_decide, AI_ACTION_STAFF, 0, slot, 0, 0);
    }
}

u8 CONST_DATA gUnk_085C98F0[] =
{
    TERRAIN_DOOR, 0,
};

u8 CONST_DATA gUnk_085C98F2[] =
{
    TERRAIN_CHEST, 0,
};
