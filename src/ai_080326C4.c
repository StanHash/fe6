#include "ai_unk.h"
#include "ai.h"

#include "random.h"
#include "item.h"
#include "unit.h"
#include "map.h"
#include "mapwork.h"
#include "battle.h"
#include "faction.h"
#include "ai_decide.h"
#include "ai_utility.h"
#include "ai_data.h"
#include "ai_battle.h"

#include "constants/iids.h"
#include "constants/terrains.h"

struct AiStaffAttemptEnt
{
    u16 iid;
    void (* func)(int slot, bool (* is_enemy)(struct Unit * unit));
};

struct AiConsumableAttemptEnt
{
    u16 iid;
    void (* func)(int slot);
};

void AiAttemptHealStaff(int slot, bool (* is_enemy)(struct Unit * unit));
void AiAttemptRangedHealStaff(int slot, bool (* is_enemy)(struct Unit * unit));
void AiAttemptFortifyStaff(int slot, bool (* is_enemy)(struct Unit * unit));
void AiAttemptWarpStaff(int slot, bool (* is_enemy)(struct Unit * unit));
void AiAttemptRestoreStaff(int slot, bool (* is_enemy)(struct Unit * unit));
void AiAttemptSilenceStaff(int slot, bool (* is_enemy)(struct Unit * unit));
void AiAttemptOffensiveStaff(int slot, bool (* is_enemy)(struct Unit * unit));
void AiAttemptBarrierStaff(int slot, bool (* is_enemy)(struct Unit * unit));

void AiAttemptDoorKey(int slot);
void AiAttemptLockpick(int slot);
void AiAttemptAntitoxin(int slot);

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

void AiFillDangerMap(void)
{
    int i, j, ix, iy;

    fu16 item = 0;
    fu8 might = 0;

    for (i = 1; i < 0xC0; ++i)
    {
        fu16 item_tmp;

        struct Unit * unit = GetUnit(i);

        if (unit == NULL)
            continue;

        if (unit->pinfo == NULL)
            continue;

        if (unit->flags & (UNIT_FLAG_HIDDEN | UNIT_FLAG_DEAD | UNIT_FLAG_NOT_DEPLOYED))
            continue;

        if (AreUnitIdsAllied(gActiveUnitId, unit->id))
            continue;

#if BUGFIX
        item = 0;
#endif

        for (j = 0; (j < ITEMSLOT_INV_COUNT) && (item_tmp = unit->items[j]); ++j)
        {
            if (!CanUnitUseWeapon(unit, item_tmp))
                continue;

            if (GetItemMight(item_tmp) > might)
            {
                item = item_tmp;
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

bool AiCheckDangerAt(int x, int y, fu8 threshold)
{
    if (gMapOther[y][x] > threshold)
        return FALSE;

    return TRUE;
}

bool AiTryGetNearestHealPoint(struct Vec2i * pos_out)
{
    static u8 CONST_DATA fort_terrains[] = { TERRAIN_FORT, 0 };

    struct Unit * unit;

    int ix, iy;

    int current_count = 10000;
    int current_move = UINT8_MAX;

    if (gActiveUnit->ai_config & AI_UNIT_CONFIG_FLAG_STAY)
        return FALSE;

    if (UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_LORD)
        return FALSE;

    MapFlood_UpTo(gActiveUnit, MAP_MOVEMENT_EXTENDED);

    for (iy = gMapSize.y - 1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x - 1; ix >= 0; --ix)
        {
            int count;

            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if (!AiIsInByteList(fort_terrains, gMapTerrain[iy][ix]))
            {
                if (gMapUnit[iy][ix] == 0 || !AreUnitIdsAllied(gActiveUnitId, gMapUnit[iy][ix]))
                    continue;

                unit = GetUnit(gMapUnit[iy][ix]);

                if (!(unit->ai_flags & AI_UNIT_FLAG_HEALER))
                    continue;
            }
            else
            {
                if (gMapUnit[iy][ix] != 0)
                {
                    if (!AreUnitIdsAllied(gActiveUnitId, gMapUnit[iy][ix]))
                        continue;

                    unit = GetUnit(gMapUnit[iy][ix]);

                    if (unit->ai_config & AI_UNIT_CONFIG_FLAG_STAY)
                        if (!(unit->ai_flags & AI_UNIT_FLAG_HEALER))
                            continue;
                }
            }

            count = AiCountNearbyEnemyUnits(ix, iy);

            if ((count <= current_count) && (gMapMovementSigned[iy][ix] <= current_move))
            {
                current_count = count;
                current_move = gMapMovement[iy][ix];
                pos_out->x = ix;
                pos_out->y = iy;
            }
        }
    }

    if (current_move != 0xFF)
    {
        if (gMapUnit[pos_out->y][pos_out->x] != 0 && gMapUnit[pos_out->y][pos_out->x] != gActiveUnitId)
        {
            unit = GetUnit(gMapUnit[pos_out->y][pos_out->x]);
            unit->ai_flags |= AI_UNIT_FLAG_1;
        }

        return TRUE;
    }

    return FALSE;
}

void AiUpdateUnitsSeekHealing(void)
{
    int i, count = 0;

    fu8 faction = gPlaySt.faction;

    SHOULD_BE_STATIC int SHOULD_BE_CONST faction_unit_count_table[3] =
    {
        UNIT_AMOUNT_BLUE,
        UNIT_AMOUNT_GREEN,
        UNIT_AMOUNT_RED,
    };

    for (i = 0; i < faction_unit_count_table[faction >> 6]; ++i)
    {
        struct Unit * unit = GetUnit(faction+i+1);

        if (!unit)
            continue;

        if (!unit->pinfo)
            continue;

        AiUpdateUnitSeeksHealing(unit);
    }
}

bool AiUpdateUnitSeeksHealing(struct Unit * unit)
{
    fu16 hp_percent = Div(GetUnitCurrentHp(unit) * 100, GetUnitMaxHp(unit));

    if (unit->ai_flags & AI_UNIT_FLAG_SEEK_HEALING)
    {
        if (gUnk_085C8820[unit->ai_config & AI_UNIT_CONFIG_HEALTHRESHOLD_MASK].exit_threshold > hp_percent)
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
        if (gUnk_085C8820[unit->ai_config & AI_UNIT_CONFIG_HEALTHRESHOLD_MASK].enter_threshold > hp_percent)
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
        fu16 item = gActiveUnit->items[i];

        if (item == 0)
            return FALSE;

        if (GetItemIid(item) == IID_VULNERARY || GetItemIid(item) == IID_ELIXIR)
        {
            if (!(gAiSt.flags & AI_FLAG_STAY))
            {
                struct Vec2i pos;

                if (AiFindSafestReachableLocation(gActiveUnit, &pos) == TRUE)
                {
                    AiSetDecision(pos.x, pos.y, AI_ACTION_USEITEM, 0, i, 0, 0);
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
    struct AiEscapePt const * escape_pt;

    MapFlood_UpTo(gActiveUnit, MAP_MOVEMENT_EXTENDED);
    escape_pt = AiGetNearestEscapePoint();

    if (escape_pt != NULL)
    {
        if (gMapMovementSigned[escape_pt->y][escape_pt->x] <= UNIT_MOV(gActiveUnit))
        {
            AiTryMoveTowards(escape_pt->x, escape_pt->y, AI_ACTION_NONE, -1, TRUE);

            AiSetDecision(gAiDecision.x_move, gAiDecision.y_move, AI_ACTION_ESCAPE,
                escape_pt->x, escape_pt->y, escape_pt->facing, 0);

            return TRUE;
        }
        else
        {
            AiTryMoveTowards(escape_pt->x, escape_pt->y, AI_ACTION_NONE, -1, FALSE);
            return gAiDecision.action_performed;
        }
    }

    return FALSE;
}

struct AiEscapePt const * AiGetNearestEscapePoint(void)
{
    int i = 0;

    struct AiEscapePt const * list = NULL;
    struct AiEscapePt const * result = NULL;

    int chapter = gPlaySt.chapter;

    fu8 resultMove = UINT8_MAX;

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
            result = list + i;
        }
    }

    return result;
}

bool AiCanEquip(void)
{
    if ((gActiveUnit->flags & UNIT_FLAG_HAD_ACTION) != 0)
        return FALSE;

    if (gAiDecision.action_id == AI_ACTION_COMBAT)
        return FALSE;

    if (gActiveUnit->status == UNIT_STATUS_BERSERK)
        return FALSE;

    return TRUE;
}

bool AiEquipGetFlags(u16 * equip_flags_out)
{
    int i;

    u32 percent;

    if (GetUnitItemCount(gActiveUnit) == 0)
        return FALSE;

    for (i = 0; i < ITEMSLOT_INV_COUNT; ++i)
    {
        fu16 item;

        equip_flags_out[i] = 0;

        item = gActiveUnit->items[i];

        if (item == 0)
            break;

        if ((GetItemAttributes(item) & (ITEM_ATTR_WEAPON | ITEM_ATTR_STAFF)) == 0)
            continue;

        if ((GetItemAttributes(item) & ITEM_ATTR_LOCK_DRAGON) != 0)
            continue;

        if (!CanUnitUseWeapon(gActiveUnit, item) && !CanUnitUseStaff(gActiveUnit, item))
            continue;

        if (GetItemAttributes(item) & ITEM_ATTR_WEAPON)
        {
            if (GetItemMinRange(item) > 1)
                equip_flags_out[i] |= AI_EQUIP_FLAG_RANGE;

            if (GetItemMaxRange(item) == 1)
                equip_flags_out[i] |= AI_EQUIP_FLAG_MELEE;

            percent = Div(percent = GetItemUses(item) * 100, GetItemMaxUses(item));

            if (percent <= 10)
                equip_flags_out[i] |= AI_EQUIP_FLAG_LOW_USES;
        }
        else
        {
            AiUpdateUnitFlagsFromStaff(item);
            equip_flags_out[i] |= AI_EQUIP_FLAG_STAFF;
        }

        equip_flags_out[i] |= AI_EQUIP_FLAG_MIGHT(GetItemMight(item));
    }

#ifdef BUGFIX
    return TRUE;
#endif
}

void AiEquipGetDanger(int x, int y, u16 * range_danger_out, u16 * melee_danger_out, u16 * combined_danger_out)
{
    int iy, ix;
    int might;
    u16 item;

    *combined_danger_out = 0;
    *melee_danger_out = 0;
    *range_danger_out = 0;

    MapFill(gMapOther, 0);

    FOR_UNITS_ALL(unit,
    {
        if ((unit->flags & (UNIT_FLAG_HIDDEN | UNIT_FLAG_RESCUED)) != 0)
            continue;

        if (AreUnitIdsAllied(gActiveUnitId, unit->id))
            continue;

        if (!AiIsWithinFlyingDistance(unit, x, y))
            continue;

        MapFlood_UpToMove(unit);

        if (gMapMovement[y][x] == 0xFF)
            continue;

        might = AiGetUnitAttackAndWeapon(unit, &item);

        if (GetItemMinRange(item) > 1)
            *range_danger_out += might;

        if (GetItemMaxRange(item) == 1)
            *melee_danger_out += might;

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

    *combined_danger_out = *range_danger_out + *melee_danger_out;
}

void AiEquipBestMatch(int equip_flag, u16 const * equip_flags)
{
    int i;

    int item_slot = -1;
    fu16 best_might = 0;

    for (i = 0; i < ITEMSLOT_INV_COUNT; i++)
    {
        if (equip_flags[i] == 0)
            continue;

        if ((equip_flags[i] & equip_flag) == 0)
            continue;

        if ((equip_flags[i] & AI_EQUIP_FLAG_MIGHT_MASK) > best_might)
        {
            best_might = equip_flags[i] & AI_EQUIP_FLAG_MIGHT_MASK;
            item_slot = i;
        }
    }

    if (item_slot > 0)
        UnitEquipItemSlot(gActiveUnit, item_slot);
}

void AiEquipBestConsideringDanger(fu16 range_danger, fu16 melee_danger, fu16 combined_danger, u16 const * equip_flags)
{
    if ((melee_danger + range_danger) != 0)
    {
        if (melee_danger >= range_danger)
            AiEquipBestMatch(AI_EQUIP_FLAG_MELEE, equip_flags);
        else
            AiEquipBestMatch(AI_EQUIP_FLAG_RANGE, equip_flags);
    }
}

void AiUpdateUnitFlagsFromStaff(fu16 item)
{
    switch (GetItemIid(item))
    {
        case IID_HEALSTAFF:
        case IID_MENDSTAFF:
        case IID_RECOVERSTAFF:
        case IID_PHYSICSTAFF:
        case IID_FORTIFYSTAFF:
            gActiveUnit->ai_flags |= AI_UNIT_FLAG_HEALER;
            break;

        case IID_HAMMERNESTAFF:
            gActiveUnit->ai_flags |= AI_UNIT_FLAG_REPAIRER;
            break;
    }
}

bool AiIsWithinFlyingDistance(struct Unit * unit, int x, int y)
{
    int mov = UNIT_MOV(unit);
    int dist = RECT_DISTANCE(x, y, unit->x, unit->y);

    if (mov >= dist)
        return TRUE;

    return FALSE;
}

int AiGetUnitAttackAndWeapon(struct Unit * unit, u16 * item_out)
{
    fu16 item = GetUnitEquippedWeapon(unit);

    *item_out = item;
    return GetUnitPower(unit) + GetItemMight(item);
}

void AiTryRefreshOrStealAfterMove(void)
{
    if (gAiDecision.action_id == AI_ACTION_ESCAPE)
        return;

    if (AiTryRefreshAt(gAiDecision.x_move, gAiDecision.y_move) == TRUE)
        return;

    AiTryStealAt(gAiDecision.x_move, gAiDecision.y_move);
}

void AiTryActionAfterMove(void)
{
    if (AiTryRefreshAt(gAiDecision.x_move, gAiDecision.y_move) == TRUE)
        return;

    if (AiTryStealAt(gAiDecision.x_move, gAiDecision.y_move) == TRUE)
        return;

    AiTryCombatAt(gAiDecision.x_move, gAiDecision.y_move);
}

bool AiTryRefreshAt(int x, int y)
{
    int ix, iy;
    struct Unit * unit;

    fu8 level = 0;
    fu8 target = 0;

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

bool AiTryStealAt(int x, int y)
{
    if ((UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_STEAL) == 0)
        return FALSE;

    MapFill(gMapMovement, -1);

    gMapMovement[y][x] = 0;
    MapAddInRange(x, y, 1, MAP_MOVEMENT_MAX);

#if BUGFIX
    return AiAttemptStealActionWithinMovement();
#else
    if (AiAttemptStealActionWithinMovement() != -1)
        return TRUE;

    return FALSE;
#endif
}

bool AiTryCombatAt(int x, int y)
{
    int ix, iy;
    struct Unit * unit;

    fu16 item = GetUnitEquippedWeapon(gActiveUnit);

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

bool AiFunc_CountEnemiesInRange_IsEnemyAt(int x, int y)
{
    if (gMapUnit[y][x] == 0)
        return FALSE;

    if (((gActiveUnitId ^ gMapUnit[y][x]) & 0x80) != 0)
        return TRUE;

    return FALSE;
}

bool AiFunc_CountEnemiesInRange(void const * arg)
{
    struct AiCountEnemiesInRangeArg const * cast = arg;

    fu16 item;
    int ix, iy;
    fu16 move;

    fu8 count = 0;

    move = (UNIT_MOV(gActiveUnit) * cast->move_coeff_q4);
    move = move >> 4;

    item = GetUnitEquippedWeapon(gActiveUnit);

    if (cast->attack_range != 0 && item != 0)
    {
        AiFloodMovementAndRange(gActiveUnit, move, item);

        for (iy = gMapSize.y - 1; iy >= 0; iy--)
        {
            for (ix = gMapSize.x - 1; ix >= 0; ix--)
            {
                if (gMapRangeSigned[iy][ix] == 0)
                    continue;

                if (AiFunc_CountEnemiesInRange_IsEnemyAt(ix, iy) == TRUE)
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

                if (AiFunc_CountEnemiesInRange_IsEnemyAt(ix, iy) == TRUE)
                    count++;
            }
        }
    }

    gAiSt.cmd_result[cast->result_slot] = count;

    return 0;
}

bool AiFunc_080334F4(void const * arg)
{
    struct UnkAiFuncArg_080334F4 const * cast = arg;

    fu16 item;
    int ix;
    int iy;
    int x_unk;
    int y_unk;
    fu16 move;
    int x_prev;
    int y_prev;

    move = UNIT_MOV(gActiveUnit) * cast->unk_04;
    move = move >> 4;

    item = GetUnitEquippedWeapon(gActiveUnit);

    x_unk = cast->unk_00[((gActiveUnit->ai_config & 0x1FC0) >> 8) * 2 + 0];
    y_unk = cast->unk_00[((gActiveUnit->ai_config & 0x1FC0) >> 8) * 2 + 1];

    x_prev = gActiveUnit->x;
    y_prev = gActiveUnit->y;

    gActiveUnit->x = x_unk;
    gActiveUnit->y = y_unk;

    if ((cast->unk_05 != 0) && (item != 0))
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

    MapFlood_UpToMove(gActiveUnit);

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

bool AiFunc_GetCounter(void const * no_input)
{
    gAiSt.cmd_result[0] = gActiveUnit->ai_counter;
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

bool func_fe6_0803372C(struct Vec2i * pos_out)
{
    struct Vec2i const * pos_a;
    struct Vec2i const * pos_b;

    int idx = (gActiveUnit->ai_config & 0x1FC0) >> 8;
    int unk46 = gActiveUnit->ai_counter;

    if (gUnk_085C8878 == NULL)
        return FALSE;

    pos_a = gUnk_085C8878[idx];

    if (pos_a == NULL)
        return FALSE;

    pos_b = pos_a + unk46;

    if (pos_b->x == -1)
    {
        unk46 = 0;
        gActiveUnit->ai_counter = 0;
        pos_b = pos_a;
    }

    pos_out->x = pos_b->x;
    pos_out->y = pos_b->y;

    if (gMapMovement[pos_b->y][pos_b->x] != 0xFF)
    {
        unk46++;
        gActiveUnit->ai_counter = unk46;
    }

    return TRUE;
}

bool func_fe6_080337B4(void const * no_input)
{
    int enemies_in_range;
    struct Vec2i pos;

    fu16 item = GetUnitEquippedWeapon(gActiveUnit);

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
        MapFlood_UpToMove(gActiveUnit);
    }

    if (func_fe6_0803372C(&pos) == 1)
    {
        AiTryMoveTowards(pos.x, pos.y, 0, 0xff, 1);
        return TRUE;
    }

    return FALSE;
}

bool AiFunc_IsInArea(void const * arg)
{
    struct AiIsInAreaArg const * cast = arg;

    fu8 x = gActiveUnit->x;
    fu8 y = gActiveUnit->y;

    if (cast->x1 <= x && cast->x2 >= x && cast->y1 <= y && cast->y2 >= y)
    {
        gAiSt.cmd_result[0] = TRUE;
        return FALSE;
    }

    gAiSt.cmd_result[0] = FALSE;
    return FALSE;
}

bool AiFunc_DecideTalk(void const * input)
{
    struct AiDecideTalkArg const * cast = input;

    AiUpdateDecision(AI_ACTION_TALK, 0,
        GetUnitByPid(cast->pid_a)->id, GetUnitByPid(cast->pid_b)->id, 0xff);

    return TRUE;
}

bool func_fe6_08033898(void const * input)
{
    int i = 0;

    fu16 lead_ai_a;
    fu16 lead_ai_a_pc;
    struct Unit * lead_unit;

    fu8 unit_id = gActiveUnitId;
    struct Unit * unit = gActiveUnit;

    fu16 lead_unit_id = GetUnitLeaderPid(gActiveUnit);

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
        gAiSt.cmd_result[1] = TRUE;
        return FALSE;
    }

    AiAttemptOffensiveAction(func_fe6_0803395C);

    gAiSt.cmd_result[0] = 0;

    if ((gAiDecision.action_performed == TRUE) && (gAiDecision.action_id == AI_ACTION_COMBAT))
        gAiSt.cmd_result[0] = gAiDecision.target_id;

    AiClearDecision();

    return FALSE;
}

bool AiIsUnitEnemyCmdResult(struct Unit * unit)
{
    if (unit->id != gAiSt.cmd_result[0])
        return FALSE;

    if (AreUnitIdsAllied(gActiveUnit->id, unit->id))
        return FALSE;

    return TRUE;
}

bool AiIsUnitEnemyOnTheWayToCmdResult(struct Unit * unit)
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

bool AiFunc_AttackCmdResult(void const * no_input)
{
    struct Unit * unit;

    if (gAiSt.cmd_result[0] == 0)
        return TRUE;

    unit = GetUnit(gAiSt.cmd_result[0]);

    AiAttemptOffensiveAction(AiIsUnitEnemyCmdResult);

    if (gAiDecision.action_performed == TRUE)
        return TRUE;

    AiAttemptOffensiveAction(AiIsUnitEnemyOnTheWayToCmdResult);

    if (gAiDecision.action_performed == TRUE)
        return TRUE;

    AiTryMoveTowards(unit->x, unit->y, 0, 0xff, 1);
    return TRUE;
}

bool AiFunc_08033B04(void const * arg)
{
    struct UnkAiFuncArg_08033B04 const * cast = arg;
    fu8 random_number = RandNext(100);

    gAiSt.maximum_heal_percent = cast->maximum_heal_percent;

    if (random_number <= cast->action_random_threshold)
    {
        if (AiAttemptStaffAction(AiIsUnitEnemy) == FALSE)
            AiAttemptOffensiveAction(AiIsUnitEnemy);

        return TRUE;
    }

    gAiSt.decide_state = 4;
    return TRUE;
}

bool AiFunc_08033B50(void const * arg)
{
    struct UnkAiFuncArg_08033B50 const * cast = arg;

    fu8 random_number = RandNext(100);

    if (random_number <= cast->do_anything_threshold)
    {
        if (AiAttemptConsumableAction() != FALSE)
            return TRUE;

        // this was also fixed in fe8 (maybe fe7)
#if BUGFIX
        random_number = RandNext(100);
#else
        RandNext(100);
#endif

        if (random_number <= cast->do_offensive_threshold)
            AiAttemptOffensiveAction(AiIsUnitEnemy);

        return TRUE;
    }

    gAiSt.decide_state = 4;
    return TRUE;
}

struct AiStaffAttemptEnt const gAiStaffAttemptList[] =
{
    { IID_HEALSTAFF, AiAttemptHealStaff },
    { IID_MENDSTAFF, AiAttemptHealStaff },
    { IID_RECOVERSTAFF, AiAttemptHealStaff },
    { IID_PHYSICSTAFF, AiAttemptRangedHealStaff },
    { IID_FORTIFYSTAFF, AiAttemptFortifyStaff },
    { IID_WARPSTAFF, AiAttemptWarpStaff },
    { IID_RESCUESTAFF, AiAttemptRangedHealStaff },
    { IID_RESTORESTAFF, AiAttemptRestoreStaff },
    { IID_SILENCESTAFF, AiAttemptSilenceStaff },
    { IID_SLEEPSTAFF, AiAttemptOffensiveStaff },
    { IID_BERSERKSTAFF, AiAttemptOffensiveStaff },
    { IID_BARRIERSTAFF, AiAttemptBarrierStaff },
    { 0 }, // end
};

struct AiConsumableAttemptEnt const gAiConsumableAttemptList[] =
{
    { IID_DOORKEY, AiAttemptDoorKey },
    { IID_LOCKPICK, AiAttemptLockpick },
    { IID_ANTITOXIN, AiAttemptAntitoxin },
    { 0 }, // end
};

int AiGetStaffAttemptId(fu16 item)
{
    fu16 iid;
    int i = 0;

    if (!CanUnitUseStaff(gActiveUnit, item))
        return -1;

    iid = GetItemIid(item);

    for (i = 0; gAiStaffAttemptList[i].iid != 0; i++)
    {
        if (iid == gAiStaffAttemptList[i].iid && gAiStaffAttemptList[i].func != NULL)
            return i;
    }

    return -1;
}

bool AiAttemptStaffAction(bool (* is_enemy)(struct Unit * unit))
{
    int i, item;
    int ent_id;

    fu8 max_wexp = 0;

    for (i = 0; i < ITEMSLOT_INV_COUNT && (item = gActiveUnit->items[i]) != 0; ++i)
    {
        // hm...
        if ((GetItemAttributes(item) & ITEM_ATTR_STAFF) == 0)
        {
        }

        if (GetItemRequiredExp(item) < max_wexp)
            continue;

        ent_id = AiGetStaffAttemptId(item);

        if (ent_id != -1)
        {
            gAiStaffAttemptList[ent_id].func(i, is_enemy);
            max_wexp = GetItemRequiredExp(item);
        }
    }

    return gAiDecision.action_performed;
}

bool AiGetReachableAdjacentPosition(int x_center, int y_center, struct Vec2i * pos_out)
{
    struct LargeVec2i
    {
        int x, y;
    };

    static struct LargeVec2i CONST_DATA unit_vecs[] =
    {
        { +1,  0 },
        { -1,  0 },
        {  0, +1 },
        {  0, -1 },
    };

    u32 score;
    u32 score_max = 0;

    int i;

    for (i = 0; i < (int) ARRAY_COUNT(unit_vecs); i++)
    {
        int x = x_center + unit_vecs[i].x;
        int y = y_center + unit_vecs[i].y;

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

void AiAttemptHealStaff(int slot, bool (* is_enemy)(struct Unit * unit))
{
    int iy, ix;
    struct Unit * unit;
    struct Vec2i pos;

    // lower is better
    fu8 score_min = 100;
    fu8 score;

    int x_decide = -1;
    int y_decide = -1;
    int target_decide = 0;

    AiStayAwareMapFlood_UpToMove(gActiveUnit);
    MapMovementMarkFloodEdges();

    if (gAiSt.maximum_heal_percent != 0)
        score_min = gAiSt.maximum_heal_percent;

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

            if (gAiSt.maximum_heal_percent == 0 && (unit->ai_flags & AI_UNIT_FLAG_SEEK_HEALING) == 0)
                continue;

            score = Div(100 * GetUnitCurrentHp(unit), GetUnitMaxHp(unit));

            if (score <= score_min && AiGetReachableAdjacentPosition(ix, iy, &pos))
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

void AiAttemptRangedHealStaff(int slot, bool (* is_enemy)(struct Unit * unit))
{
    struct Vec2i pos;

    // lower is better
    fu8 score_min = 100;
    fu8 score;

    int x_decide = -1;
    int y_decide = -1;
    int target_decide = 0;

    if ((gAiSt.flags & AI_FLAG_BERSERKED) != 0)
        return;

    AiStayAwareMapFlood_UpToMove(gActiveUnit);

    if (gAiSt.maximum_heal_percent != 0)
        score_min = gAiSt.maximum_heal_percent;

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

        if (gAiSt.maximum_heal_percent == 0 && (unit->ai_flags & AI_UNIT_FLAG_SEEK_HEALING) == 0)
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

        if (!AiFindGoodMovePositionWithinRange(&pos))
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

void AiAttemptFortifyStaff(int slot, bool (* is_enemy)(struct Unit * unit))
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

    AiStayAwareMapFlood_UpToMove(gActiveUnit);

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

void AiAttemptWarpStaff(int slot, bool (* is_enemy)(struct Unit * unit))
{
    int iy, ix;
    struct Unit * unit;
    struct Vec2i pos;

    fu8 max_level = 0;

    int x_decide = 0;
    int y_decide = 0;
    int target_decide = 0;

    if ((gAiSt.flags & AI_FLAG_BERSERKED) != 0)
        return;

    AiStayAwareMapFlood_UpToMove(gActiveUnit);
    MapMovementMarkFloodEdges();

    for (iy = gMapSize.y - 1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x - 1; ix >= 0; --ix)
        {
            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if (gMapUnit[iy][ix] == 0)
                continue;

            unit = GetUnit(gMapUnit[iy][ix]);

            if ((gAiSt.flags & AI_FLAG_BERSERKED) == 0 && is_enemy != NULL)
            {
                if (is_enemy(unit) == TRUE)
                    continue;
            }

            if ((unit->ai_flags & (AI_UNIT_FLAG_SEEK_HEALING | AI_UNIT_FLAG_3)) != 0)
                continue;

            if (unit->level >= max_level && AiGetReachableAdjacentPosition(ix, iy, &pos))
            {
                max_level = unit->level;
                x_decide = pos.x;
                y_decide = pos.y;
                target_decide = gMapUnit[iy][ix];
            }
        }
    }

    if (max_level != 0 && AiGetGoodWarpPosition(&pos))
    {
        AiSetDecision(x_decide, y_decide, AI_ACTION_STAFF, target_decide, slot, pos.x, pos.y);
    }
}

void AiAttemptRestoreStaff(int slot, bool (* is_enemy)(struct Unit * unit))
{
    int iy, ix;
    struct Unit * unit;
    struct Vec2i pos;

    fu8 max_level = 0;

    int x_decide = 0;
    int y_decide = 0;
    int target_decide = 0;

    if ((gAiSt.flags & AI_FLAG_BERSERKED) != 0)
        return;

    AiStayAwareMapFlood_UpToMove(gActiveUnit);
    MapMovementMarkFloodEdges();

    for (iy = gMapSize.y - 1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x - 1; ix >= 0; --ix)
        {
            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if (gMapUnit[iy][ix] == 0)
                continue;

            unit = GetUnit(gMapUnit[iy][ix]);

            if ((gAiSt.flags & AI_FLAG_BERSERKED) == 0 && is_enemy != NULL)
            {
                if (is_enemy(unit) == TRUE)
                    continue;
            }

            if (unit->status == UNIT_STATUS_NONE)
                continue;

            if (unit->level >= max_level && AiGetReachableAdjacentPosition(ix, iy, &pos))
            {
                max_level = unit->level;
                x_decide = pos.x;
                y_decide = pos.y;
                target_decide = gMapUnit[iy][ix];
            }
        }
    }

    if (max_level != 0)
    {
        AiSetDecision(x_decide, y_decide, AI_ACTION_STAFF, target_decide, slot, 0, 0);
    }
}

// used to check if this unit should be ignored when finding a target for status staves
bool AiIsUnitArmed(struct Unit * unit)
{
    int i;

    for (i = 0; i < ITEMSLOT_INV_COUNT; ++i)
    {
        fu16 item = unit->items[i];

        if (item == 0)
            return FALSE;

        if ((GetItemAttributes(item) & (ITEM_ATTR_WEAPON | ITEM_ATTR_STAFF | ITEM_ATTR_LOCK_DRAGON)) == 0)
            continue;

        if (CanUnitUseWeapon(unit, item) || CanUnitUseStaff(unit, item))
            return TRUE;
    }

    return FALSE;
}

// used to find the "best" target for a silence staff use
int AiGetSilenceStaffTargetScore(struct Unit * unit)
{
    fu16 item;

    fu8 score = GetOffensiveStaffAccuracy(gActiveUnit, unit);

    if (score < 5)
        return FALSE;

    score = score + GetUnitPower(unit);

    item = GetUnitEquippedWeapon(unit);

    if (item != 0 && (GetItemAttributes(item) & ITEM_ATTR_MAGIC))
        score = score * 2;

    return score;
}

void AiAttemptSilenceStaff(int slot, bool (* is_enemy)(struct Unit * unit))
{
    struct Vec2i pos;

    fu8 score_max = 0;
    fu8 score;

    int x_decide = 0;
    int y_decide = 0;
    int target_decide = 0;

    if ((gAiSt.flags & AI_FLAG_BERSERKED) != 0)
        return;

    AiStayAwareMapFlood_UpToMove(gActiveUnit);

    FOR_UNITS_ALL(unit,
    {
        if ((unit->flags & (UNIT_FLAG_HIDDEN | UNIT_FLAG_DEAD)) != 0)
            continue;

        if ((gAiSt.flags & AI_FLAG_BERSERKED) == 0 && is_enemy != NULL)
        {
            if (is_enemy(unit) == FALSE)
                continue;
        }

        if (unit->status == UNIT_STATUS_SILENCED)
            continue;

        if (!AiUnitHasAnyStaff(unit))
            continue;

        if (!AiIsWithinRectDistance(
            gActiveUnit->x, gActiveUnit->y,
            unit->x, unit->y,
            GetUnitMagRange(gActiveUnit) + UNIT_MOV(gActiveUnit)))
        {
            continue;
        }

        if (!AiIsUnitArmed(unit))
            continue;

        score = AiGetSilenceStaffTargetScore(unit);

        if (score != 0 && score >= score_max)
        {
            MapFill(gMapRange, 0);
            MapAddInRange(unit->x, unit->y, GetUnitMagRange(gActiveUnit), 1);

            if (AiFindGoodMovePositionWithinRange(&pos))
            {
                score_max = score;
                x_decide = pos.x;
                y_decide = pos.y;
                target_decide = unit->id;
            }
        }
    })

    if (score_max != 0)
    {
        AiSetDecision(x_decide, y_decide, AI_ACTION_STAFF, target_decide, slot, 0, 0);
    }
}

void AiAttemptOffensiveStaff(int slot, bool (* is_enemy)(struct Unit * unit))
{
    struct Vec2i pos;

    fu8 level_max = 0;
    fu8 accuracy;

    int x_decide = 0;
    int y_decide = 0;
    int target_decide = 0;

    if ((gAiSt.flags & AI_FLAG_BERSERKED) != 0)
        return;

    AiStayAwareMapFlood_UpToMove(gActiveUnit);

    FOR_UNITS_ALL(unit,
    {
        if ((unit->flags & (UNIT_FLAG_HIDDEN | UNIT_FLAG_DEAD)) != 0)
            continue;

        if ((gAiSt.flags & AI_FLAG_BERSERKED) == 0 && is_enemy != NULL)
        {
            if (is_enemy(unit) == FALSE)
                continue;
        }

        if (unit->status != UNIT_STATUS_NONE)
            continue;

        if (!AiIsWithinRectDistance(
            gActiveUnit->x, gActiveUnit->y,
            unit->x, unit->y,
            GetUnitMagRange(gActiveUnit) + UNIT_MOV(gActiveUnit)))
        {
            continue;
        }

        if (!AiIsUnitArmed(unit))
            continue;

        accuracy = GetOffensiveStaffAccuracy(gActiveUnit, unit);

        if (accuracy >= 5 && accuracy + unit->level >= level_max)
        {
            MapFill(gMapRange, 0);
            MapAddInRange(unit->x, unit->y, GetUnitMagRange(gActiveUnit), 1);

            if (AiFindGoodMovePositionWithinRange(&pos))
            {
                level_max = unit->level;
                x_decide = pos.x;
                y_decide = pos.y;
                target_decide = unit->id;
            }
        }
    })

    if (level_max != 0)
    {
        AiSetDecision(x_decide, y_decide, AI_ACTION_STAFF, target_decide, slot, 0, 0);
    }
}

void AiAttemptBarrierStaff(int slot, bool (* is_enemy)(struct Unit * unit))
{
    int iy, ix;
    struct Unit * unit;
    struct Vec2i pos;

    fu8 min_resistance = UINT8_MAX;

    int x_decide = 0;
    int y_decide = 0;
    int target_decide = 0;

    if ((gAiSt.flags & AI_FLAG_BERSERKED) != 0)
        return;

    AiStayAwareMapFlood_UpToMove(gActiveUnit);
    MapMovementMarkFloodEdges();

    for (iy = gMapSize.y - 1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x - 1; ix >= 0; --ix)
        {
            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if (gMapUnit[iy][ix] == 0)
                continue;

            unit = GetUnit(gMapUnit[iy][ix]);

            if ((gAiSt.flags & AI_FLAG_BERSERKED) == 0 && is_enemy != NULL)
            {
                if (is_enemy(unit) == TRUE)
                    continue;
            }

            if (GetUnitResistance(unit) <= min_resistance && AiGetReachableAdjacentPosition(ix, iy, &pos))
            {
                min_resistance = GetUnitResistance(unit);
                x_decide = pos.x;
                y_decide = pos.y;
                target_decide = gMapUnit[iy][ix];
            }
        }
    }

    if (min_resistance != UINT8_MAX)
    {
        AiSetDecision(x_decide, y_decide, AI_ACTION_STAFF, target_decide, slot, 0, 0);
    }
}

bool AiGetGoodWarpPosition(struct Vec2i * pos_out)
{
    // idk how this is supposed to work
    // this function doesn't know the warp target

    int iy, ix;

    fu8 min_score = UINT8_MAX;
    fu8 nearest_enemy_distance = UINT8_MAX;
    fu8 some_other_distance = UINT8_MAX;

    int x_found = 0;
    int y_found = 0;

    i8 const * mov_table = gActiveUnit->jinfo->mov_table;

    int alliance = GetActiveFactionAlliance();

    FOR_UNITS(alliance + 1, alliance + 0x80, unit,
    {
        if (unit->flags & (UNIT_FLAG_HIDDEN | UNIT_FLAG_DEAD | UNIT_FLAG_RESCUED))
            continue;

        AiMapFloodRange_UpToMove(unit);

        for (iy = gMapSize.y - 1; iy >= 0; --iy)
        {
            for (ix = gMapSize.x - 1; ix >= 0; --ix)
            {
                if (gMapRange[iy][ix] > MAP_MOVEMENT_MAX)
                    continue;

                if (gMapUnit[iy][ix] != 0)
                {
                    if (!AreUnitIdsAllied(unit->id, gMapUnit[iy][ix]))
                    {
                        if (nearest_enemy_distance > gMapRangeSigned[iy][ix])
                            nearest_enemy_distance = gMapRangeSigned[iy][ix];
                    }

                    continue;
                }
                else
                {
                    if (mov_table[gMapTerrain[iy][ix]] <= 0)
                        continue;

                    if (gMapMovementSigned[iy][ix] <= MAP_MOVEMENT_MAX)
                        continue;

                    if (some_other_distance <= gMapRangeSigned[iy][ix])
                        continue;

                    x_found = ix;
                    y_found = iy;
                    some_other_distance = gMapRangeSigned[iy][ix];
                }
            }
        }

        if (nearest_enemy_distance != UINT8_MAX && min_score >= nearest_enemy_distance && some_other_distance != UINT8_MAX)
        {
            pos_out->x = x_found;
            pos_out->y = y_found;
            min_score = nearest_enemy_distance;
        }
    })

    if (min_score != UINT8_MAX)
        return TRUE;

    return FALSE;
}

int AiGetConsumableAttemptId(fu16 item)
{
    fu16 iid;
    int i = 0;

    iid = GetItemIid(item);

    while (gAiConsumableAttemptList[i].iid != 0)
    {
        if (iid == gAiConsumableAttemptList[i].iid)
        {
            if (iid == IID_LOCKPICK && (UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_STEAL) == 0)
            {
#if BUGFIX
                i++;
#endif
                continue;
            }

            if (gAiConsumableAttemptList[i].func != NULL)
                return i;
        }

        i++;
    }

    return -1;
}

bool AiAttemptConsumableAction(void)
{
    int i, item;
    int ent_id;

    if ((gAiSt.flags & AI_FLAG_STAY) != 0)
        return FALSE;

    for (i = 0; i < ITEMSLOT_INV_COUNT && (item = gActiveUnit->items[i]) != 0; ++i)
    {
        // hm...
        if (GetItemKind(item) == ITEM_KIND_SWORD)
            continue;

        ent_id = AiGetConsumableAttemptId(item);

        if (ent_id != -1)
        {
            gAiConsumableAttemptList[ent_id].func(i);
        }
    }

    if (gAiSt.decide_state == 0)
        return TRUE;

    return gAiDecision.action_performed;
}

void AiAttemptDoorKey(int slot)
{
    struct Vec2i pos;

    if ((gAiSt.special_item_flags & (0x80000001)) == 0)
        return;

    if (!AiFindGoodDoorKeyUsePosition(gActiveUnit, &pos))
        return;

    AiTryMoveTowards(pos.x, pos.y, AI_ACTION_NONE, gAiSt.unk_7E, TRUE);

    if (gAiDecision.action_performed != TRUE)
        return;

    if (AiIsWithinRectDistance(pos.x, pos.y, gAiDecision.x_move, gAiDecision.y_move, 1) != TRUE)
        return;

    AiSetDecision(gAiDecision.x_move, gAiDecision.y_move, AI_ACTION_USEITEM, 0, slot, 0, 0);
}

void AiAttemptLockpick(int slot)
{
    struct Vec2i pos;

    int findpos_flags = 0;

    if ((gAiSt.special_item_flags & (2)) == 0)
        return;

    if (GetUnitItemCount(gActiveUnit) >= ITEMSLOT_INV_COUNT && (gActiveUnit->ai_flags & AI_UNIT_FLAG_3) == 0)
    {
        gActiveUnit->ai_flags |= AI_UNIT_FLAG_3;
        gAiSt.decide_state = 0;
        return;
    }

    if (GetUnitItemCount(gActiveUnit) >= ITEMSLOT_INV_COUNT)
        findpos_flags |= AI_FINDPOS_FLAG_NO_CHESTS;

    if (AiFindGoodLockpickUsePosition(gActiveUnit, findpos_flags, &pos) == TRUE)
    {
        AiTryMoveTowards(pos.x, pos.y, AI_ACTION_NONE, gAiSt.unk_7E, FALSE);

        if (gAiDecision.action_performed != TRUE)
            return;

        if (AiIsWithinRectDistance(pos.x, pos.y, gAiDecision.x_move, gAiDecision.y_move, 0) != TRUE)
            return;

        AiSetDecision(gAiDecision.x_move, gAiDecision.y_move, AI_ACTION_USEITEM, 0, slot, 0, 0);
    }
}

void AiAttemptAntitoxin(int slot)
{
    struct Vec2i pos;

    if ((gAiSt.special_item_flags & (4)) == 0)
        return;

    if (gActiveUnit->status != UNIT_STATUS_POISON)
        return;

    if (AiFindSafestReachableLocation(gActiveUnit, &pos) != TRUE)
        return;

    AiSetDecision(pos.x, pos.y, AI_ACTION_USEITEM, 0, slot, 0, 0);
}

// unused
fu8 AiGetRangeAt(int x, int y)
{
    if (gMapRangeSigned[y][x] >= MAP_MOVEMENT_MAX)
        return UINT8_MAX;

    if (gMapUnit[y][x] != 0 && gMapUnit[y][x] != gActiveUnitId)
        return UINT8_MAX;

    return gMapRange[y][x];
}

bool AiFindGoodDoorKeyUsePosition(struct Unit * unit, struct Vec2i * pos_out)
{
    static u8 CONST_DATA door_terrains[] = { TERRAIN_DOOR, 0 };

    AiMapFloodRange_NoDoors_Pass(unit);

    if (!AiFindClosestTerrainAdjacentPosition(door_terrains, 0, pos_out))
        return FALSE;

    AiMapFloodRange(unit);

    if (gMapRangeSigned[pos_out->y][pos_out->x] >= MAP_MOVEMENT_MAX)
        return FALSE;

    return TRUE;
}

bool AiFindGoodChestKeyUsePosition(struct Unit * unit, struct Vec2i * pos_out)
{
    static u8 CONST_DATA chest_terrains[] = { TERRAIN_CHEST, 0 };

    AiMapFloodRange(unit);

    if (!AiFindClosestTerrainPosition(chest_terrains, 0, pos_out))
        return FALSE;

    return TRUE;
}

int AiFindGoodLockpickUsePosition(struct Unit * unit, int findpos_flags, struct Vec2i * pos_out)
{
    AiMapFlood(unit);

    AiMapFloodRange_NoDoors(unit);

    if (AiFindClosestUnlockPosition(findpos_flags | AI_FINDPOS_FLAG_CHECK_ENEMY, pos_out) == TRUE)
    {
        if (gMapMovementSigned[pos_out->y][pos_out->x] < MAP_MOVEMENT_MAX)
            return TRUE;
    }

    AiMapFloodRange_NoDoors_Pass(unit);

    if ((AiFindClosestUnlockPosition(findpos_flags, pos_out) == TRUE))
    {
        if ((gMapMovementSigned[pos_out->y][pos_out->x] < MAP_MOVEMENT_MAX) && (gMapUnit[pos_out->y][pos_out->x] == 0))
            return FALSE;

        return TRUE;
    }

    return FALSE;
}

void AiSetWorkingMovTableIgnoringWalls(i8 const * mov_table)
{
    fu16 i;

    for (i = 1; i < TERRAIN_COUNT; i++)
    {
        if (mov_table[i] > 0)
            gWorkingMovTable[i] = mov_table[i];
        else
            gWorkingMovTable[i] = 1;
    }
}

void AiSetWorkingMovTableIgnoringTerrain(i8 const * mov_table, int free_terrain)
{
    fu16 i;

    for (i = 1; i < TERRAIN_COUNT; i++)
        gWorkingMovTable[i] = mov_table[i];

    gWorkingMovTable[free_terrain] = 1;
}

void AiMapFlood(struct Unit * unit)
{
    SetWorkingMovTable(unit->jinfo->mov_table);
    SetWorkingMap(gMapMovement);

    BeginMapFlood(unit->x, unit->y, MAP_MOVEMENT_EXTENDED, unit->id);
}

void AiMapFloodRange(struct Unit * unit)
{
    SetWorkingMovTable(unit->jinfo->mov_table);
    SetWorkingMap(gMapRange);

    BeginMapFlood(unit->x, unit->y, MAP_MOVEMENT_EXTENDED, unit->id);
}

void AiMapFlood_NoWall(struct Unit * unit)
{
    AiSetWorkingMovTableIgnoringWalls(unit->jinfo->mov_table);
    SetWorkingMap(gMapMovement);

    BeginMapFlood(unit->x, unit->y, MAP_MOVEMENT_EXTENDED, unit->id);
}

void AiMapFlood_NoWall_Pass(struct Unit * unit)
{
    AiSetWorkingMovTableIgnoringWalls(unit->jinfo->mov_table);
    SetWorkingMap(gMapMovement);

    BeginMapFlood(unit->x, unit->y, MAP_MOVEMENT_EXTENDED, 0);
}

void AiMapFloodRange_NoDoors(struct Unit * unit)
{
    AiSetWorkingMovTableIgnoringTerrain(unit->jinfo->mov_table, TERRAIN_DOOR);
    SetWorkingMap(gMapRange);

    BeginMapFlood(unit->x, unit->y, MAP_MOVEMENT_EXTENDED, unit->id);
}

void AiMapFloodRange_NoDoors_Pass(struct Unit * unit)
{
    AiSetWorkingMovTableIgnoringTerrain(unit->jinfo->mov_table, TERRAIN_DOOR);
    SetWorkingMap(gMapRange);

    BeginMapFlood(unit->x, unit->y, MAP_MOVEMENT_EXTENDED, 0);
}

void AiMapFloodRange_UpToMove(struct Unit * unit)
{
    SetWorkingMovTable(unit->jinfo->mov_table);
    SetWorkingMap(gMapRange);

    BeginMapFlood(unit->x, unit->y, UNIT_MOV(unit), unit->id);
}

void AiUpdateStayFlag(struct Unit * unit)
{
    if ((unit->ai_config & AI_UNIT_CONFIG_FLAG_STAY) != 0)
    {
        gAiSt.flags |= AI_FLAG_STAY;
    }
    else
    {
        gAiSt.flags &= ~AI_FLAG_STAY;
    }
}

void AiMapFloodRangeFrom(int x, int y, struct Unit * unit)
{
    SetWorkingMovTable(unit->jinfo->mov_table);
    SetWorkingMap(gMapRange);

    BeginMapFlood(x, y, MAP_MOVEMENT_EXTENDED, unit->id);
}
