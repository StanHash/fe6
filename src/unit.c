
#include "common.h"
#include "unit.h"

#include "msg.h"
#include "item.h"
#include "map.h"
#include "mapwork.h"
#include "bmfx.h"
#include "faction.h"
#include "unitsprite.h"
#include "support.h"
#include "battle.h"
#include "trap.h"
#include "action.h"
#include "ai-utility.h"

#include "constants/terrains.h"
#include "constants/items.h"
#include "constants/map-sprites.h"
#include "constants/icons.h"
#include "constants/faces.h"

extern struct PInfo CONST_DATA PersonInfoTable[];
extern struct JInfo CONST_DATA JobInfoTable[];

extern struct Unit * CONST_DATA gUnitLut[0x100];

u8 EWRAM_DATA gActiveUnitId = 0;
struct Vec2i EWRAM_DATA gActiveUnitMoveOrigin = {};

struct Unit EWRAM_DATA gUnitArrayBlue[UNIT_AMOUNT_BLUE]     = {};
struct Unit EWRAM_DATA gUnitArrayRed[UNIT_AMOUNT_RED]       = {};
struct Unit EWRAM_DATA gUnitArrayGreen[UNIT_AMOUNT_GREEN]   = {};
struct Unit EWRAM_DATA gUnitArrayPurple[UNIT_AMOUNT_PURPLE] = {};

inline struct Unit * GetUnit(int uid)
{
    return gUnitLut[uid & 0xFF];
}

inline struct JInfo const * GetJobInfo(int jid)
{
    if (jid < 1)
        return NULL;

    return JobInfoTable + (jid - 1);
}

inline struct PInfo const * GetPersonInfo(int pid)
{
    if (pid < 1)
        return NULL;

    return PersonInfoTable + (pid - 1);
}

void InitUnits(void)
{
    int i;

    for (i = 0; i < 0x100; ++i)
    {
        struct Unit * unit = GetUnit(i);

        if (!unit)
            continue;

        ClearUnit(unit);
        unit->id = i;
    }
}

void ClearUnit(struct Unit * unit)
{
    u8 id = unit->id;

    CpuFill16(0, unit, sizeof(struct Unit));

    unit->id = id;
}

void CopyUnit(struct Unit * src, struct Unit * dst)
{
    u8 id = dst->id;

    *dst = *src;

    dst->id = id;
}

struct Unit * GetFreeUnit(int faction)
{
    int i;

    int first = faction + 0x01;
    int last = faction + 0x40;

    for (i = first; i < last; ++i)
    {
        struct Unit * unit = GetUnit(i);

        if (unit->pinfo == NULL)
            return unit;
    }

    return NULL;
}

inline int GetUnitMaxHp(struct Unit * unit)
{
    return unit->max_hp + GetItemHpBonus(GetUnitEquippedWeapon(unit));
}

inline int GetUnitCurrentHp(struct Unit * unit)
{
    if (unit->hp > GetUnitMaxHp(unit))
        unit->hp = GetUnitMaxHp(unit);

    return unit->hp;
}

inline int GetUnitPower(struct Unit * unit)
{
    return unit->pow + GetItemPowBonus(GetUnitEquippedWeapon(unit));
}

inline int GetUnitSkill(struct Unit * unit)
{
    int weapon = GetUnitEquippedWeapon(unit);

    if (unit->flags & UNIT_FLAG_RESCUING)
        return unit->skl / 2 + GetItemSklBonus(weapon);

    return unit->skl + GetItemSklBonus(weapon);
}

inline int GetUnitSpeed(struct Unit * unit)
{
    int weapon = GetUnitEquippedWeapon(unit);

    if (unit->flags & UNIT_FLAG_RESCUING)
        return unit->spd / 2 + GetItemSpdBonus(weapon);

    return unit->spd + GetItemSpdBonus(weapon);
}

inline int GetUnitDefense(struct Unit * unit)
{
    return unit->def + GetItemDefBonus(GetUnitEquippedWeapon(unit));
}

inline int GetUnitResistance(struct Unit * unit)
{
    return unit->res + GetItemResBonus(GetUnitEquippedWeapon(unit)) + unit->barrier;
}

inline int GetUnitLuck(struct Unit * unit)
{
    return unit->lck + GetItemLckBonus(GetUnitEquippedWeapon(unit));
}

inline int GetUnitFid(struct Unit * unit)
{
    if (unit->pinfo->fid != FID_NONE)
        return unit->pinfo->fid;

    if (unit->jinfo->fid != FID_NONE)
        return unit->jinfo->fid;

#if BUGFIX
    return FID_NONE;
#endif
}

inline int GetUnitChibiId(struct Unit * unit)
{
    if (unit->pinfo->chibi_id != 0)
        return FID_FACTION_CHIBI + unit->pinfo->chibi_id;

    return GetUnitFid(unit);
}

inline int GetUnitLeaderPid(struct Unit * unit)
{
    if (UNIT_FACTION(unit) == FACTION_BLUE)
        return 0;

    return unit->supports[UNIT_SUPPORT_COUNT-1];
}

inline void SetUnitLeaderPid(struct Unit * unit, int pid)
{
    unit->supports[UNIT_SUPPORT_COUNT-1] = pid;
}

inline void SetUnitHp(struct Unit * unit, int hp)
{
    unit->hp = hp;

    if (unit->hp > GetUnitMaxHp(unit))
        unit->hp = GetUnitMaxHp(unit);
}

inline void AddUnitHp(struct Unit * unit, int amount)
{
    int hp = unit->hp;

    hp += amount;

    if (hp > GetUnitMaxHp(unit))
        hp = GetUnitMaxHp(unit);

    if (hp < 0)
        hp = 0;

    unit->hp = hp;
}

int GetUnitVision(struct Unit * unit)
{
    int result = gPlaySt.vision;

    if (UNIT_ATTRIBUTES(unit) & UNIT_ATTR_STEAL)
        result = result + 5;

    return result + unit->torch;
}

void SetUnitStatus(struct Unit * unit, int status)
{
    if (status == UNIT_STATUS_NONE)
    {
        unit->status = UNIT_STATUS_NONE;
        unit->status_duration = 0;
    }
    else
    {
        unit->status = status;
        unit->status_duration = 5;
    }
}

static char const * CONST_DATA sStatusNameStringLut[] =
{
    [UNIT_STATUS_BERSERK]  = TEXT("バサーク", "Berserk"),
    [UNIT_STATUS_SILENCED] = TEXT("サイレス", "Silence"),
    [UNIT_STATUS_SLEEP]    = TEXT("スリープ", "Sleep"),
    [UNIT_STATUS_POISON]   = TEXT("ポイズン", "Poison"),
    [UNIT_STATUS_NONE]     = JTEXT("ーーー"),
};

inline char const * GetUnitStatusName(struct Unit * unit)
{
    return sStatusNameStringLut[unit->status];
}

int GetUnitMapSprite(struct Unit * unit)
{
    if (!(UNIT_ATTRIBUTES(unit) & UNIT_ATTR_BALLISTA))
        return unit->jinfo->map_sprite;

    switch (gMapTerrain[unit->y][unit->x])
    {

    case TERRAIN_BALLISTA:
        return UNITSPRITE_BALLISTA_REGULAR;

    case TERRAIN_LONGBALLISTA:
        return UNITSPRITE_BALLISTA_LONG;

    case TERRAIN_KILLERBALLISTA:
        return UNITSPRITE_BALLISTA_KILLER;

    default:
        return unit->jinfo->map_sprite;

    }
}

bool UnitAddItem(struct Unit * unit, int item)
{
    int i;

    for (i = 0; i < ITEMSLOT_INV_COUNT; ++i)
    {
        if (unit->items[i] == 0)
        {
            unit->items[i] = item;
            return TRUE;
        }
    }

    return FALSE;
}

inline void UnitRemoveItem(struct Unit * unit, int slot)
{
    unit->items[slot] = 0;
    UnitRemoveInvalidItems(unit);
}

void UnitRemoveInvalidItems(struct Unit * unit)
{
    u16 items[ITEMSLOT_INV_COUNT + 1], i;
    u16 * it = items;

    // Build item buffer by iterating through unit's items and skipping blanks

    for (i = 0; i < ITEMSLOT_INV_COUNT; ++i)
    {
        if (unit->items[i])
            *it++ = unit->items[i];

        unit->items[i] = 0; // Clear the item from the unit
    }

    *it = 0; // null-terminate buffer

    // Write buffered items

    for (i = 0; i < ITEMSLOT_INV_COUNT; ++i)
    {
        if (!items[i])
            return; // Stop now if we reached end of buffer

        unit->items[i] = items[i];
    }
}

int GetUnitItemCount(struct Unit * unit)
{
    int i;

    for (i = (ITEMSLOT_INV_COUNT - 1); i >= 0; --i)
    {
        if (unit->items[i])
            return i + 1;
    }

    return 0;
}

bool UnitHasItem(struct Unit * unit, int item)
{
    int i;

    item = GetItemIid(item);

    for (i = 0; (i < ITEMSLOT_INV_COUNT) && unit->items[i]; ++i)
    {
        if (GetItemIid(unit->items[i]) == item)
            return TRUE;
    }

    return FALSE;
}

int BatchCreateUnits(struct UnitInfo const * info)
{
    int count = 0;

    while (info->pid)
    {
        CreateUnit(info);

        info++;
        count++;
    }

    return count;
}

struct Unit * CreateUnit(struct UnitInfo const * info)
{
    struct Unit * unit;

    switch (info->faction_id)
    {

    case FACTION_ID_BLUE:
        unit = GetFreeUnit(FACTION_BLUE);
        break;

    case FACTION_ID_RED:
        unit = GetFreeUnit(FACTION_RED);
        break;

    case FACTION_ID_GREEN:
        unit = GetFreeUnit(FACTION_GREEN);
        break;

    }

    if (unit == NULL)
        return NULL;

    ClearUnit(unit);

    UnitInitFromInfo(unit, info);
    UnitInitStats(unit, unit->pinfo);

    UnitHideIfUnderRoof(unit);

    if (info->autolevel)
    {
        if (UNIT_FACTION(unit) == FACTION_BLUE)
        {
            UnitAutolevelPlayer(unit);
            UnitAutolevelWeaponExp(unit, info);
        }
        else
        {
            UnitAutolevel(unit);
            UnitAutolevelWeaponExp(unit, info);

            SetUnitLeaderPid(unit, info->pid_lead);
        }
    }

    func_fe6_08017764(unit);
    UnitInitSupports(unit);

    UnitCheckStatOverflow(unit);

    unit->hp = GetUnitMaxHp(unit);

    return unit;
}

void UnitInitFromInfo(struct Unit * unit, struct UnitInfo const * info)
{
    int i;

    unit->pinfo = GetPersonInfo(info->pid);

    if (info->jid != 0)
        unit->jinfo = GetJobInfo(info->jid);
    else
        unit->jinfo = GetJobInfo(unit->pinfo->jid_default);

    unit->level = info->level;

    unit->x = info->x_move;
    unit->y = info->y_move;

    for (i = 0; (i < (int) ARRAY_COUNT(info->items)) && info->items[i]; ++i)
        UnitAddItem(unit, CreateItem(info->items[i]));

    UnitInitAiFromInfo(unit, info);
}

void UnitInitStats(struct Unit * unit, struct PInfo const * pinfo)
{
    int i;

    unit->max_hp = pinfo->base_hp + unit->jinfo->base_hp;
    unit->pow = pinfo->base_pow + unit->jinfo->base_pow;
    unit->skl = pinfo->base_skl + unit->jinfo->base_skl;
    unit->spd = pinfo->base_spd + unit->jinfo->base_spd;
    unit->def = pinfo->base_def + unit->jinfo->base_def;
    unit->res = pinfo->base_res + unit->jinfo->base_res;
    unit->lck = pinfo->base_lck;

    unit->bonus_con = 0;

    for (i = 0; i < UNIT_WEAPON_EXP_COUNT; ++i)
    {
        unit->wexp[i] = unit->jinfo->wexp[i];

        if (unit->pinfo->wexp[i] != 0)
            unit->wexp[i] = unit->pinfo->wexp[i];
    }

    if (UNIT_FACTION(unit) == FACTION_BLUE && (unit->level != UNIT_LEVEL_MAX))
        unit->exp = 0;
    else
        unit->exp = 0xFF;
}

void func_fe6_08017764(struct Unit * unit)
{
    if (UNIT_ATTRIBUTES(unit) & UNIT_ATTR_BIT23)
        unit->pinfo = GetPersonInfo(unit->pinfo->id - 1);
}

void UnitInitSupports(struct Unit * unit)
{
    int i, count = GetUnitSupportCount(unit);

    for (i = 0; i < count; ++i)
        unit->supports[i] = GetUnitInitialSupportExp(unit, i);
}

void UnitAutolevelWeaponExp(struct Unit * unit, struct UnitInfo const * info)
{
    int i;

    if (!info->autolevel)
        return;

    for (i = 0; i < GetUnitItemCount(unit); ++i)
    {
        int kind, item = unit->items[i];

        if (!(GetItemAttributes(item) & ITEM_ATTR_REQUIRES_EXP))
            continue;

        if (GetItemAttributes(item) & ITEM_ATTR_WEAPON)
            if (CanUnitUseWeapon(unit, item))
                continue;

        if (GetItemAttributes(item) & ITEM_ATTR_STAFF)
            if (CanUnitUseStaff(unit, item))
                continue;

        kind = GetItemKind(item);

        if (unit->wexp[kind] == 0)
            item = 0;

        unit->wexp[kind] = GetItemRequiredExp(item);
    }
}

void UnitAutolevelCore(struct Unit * unit, u8 jid, int levelCount)
{
    // BUG: jid is unused here

    if (levelCount)
    {
        unit->max_hp += GetAutoleveledStatIncrease(unit->jinfo->growth_hp,  levelCount);
        unit->pow   += GetAutoleveledStatIncrease(unit->jinfo->growth_pow, levelCount);
        unit->skl   += GetAutoleveledStatIncrease(unit->jinfo->growth_skl, levelCount);
        unit->spd   += GetAutoleveledStatIncrease(unit->jinfo->growth_spd, levelCount);
        unit->def   += GetAutoleveledStatIncrease(unit->jinfo->growth_def, levelCount);
        unit->res   += GetAutoleveledStatIncrease(unit->jinfo->growth_res, levelCount);
        unit->lck   += GetAutoleveledStatIncrease(unit->jinfo->growth_lck, levelCount);
    }
}

void UnitApplyBonusLevels(struct Unit * unit, int levelCount)
{
    UnitAutolevelCore(unit, unit->jinfo->id, levelCount);
    UnitCheckStatOverflow(unit);

    unit->hp = GetUnitMaxHp(unit);
}

void UnitAutolevel(struct Unit * unit)
{
    if (UNIT_ATTRIBUTES(unit) & UNIT_ATTR_PROMOTED)
        UnitAutolevelCore(unit, unit->jinfo->jid_promote, UNIT_LEVEL_MAX - 1);

    UnitAutolevelCore(unit, unit->jinfo->id, unit->level - 1);
}

void UnitAutolevelPlayer(struct Unit * unit)
{
    int i, levelCount = unit->level - unit->pinfo->base_level;

    for (i = 0; i < levelCount; ++i)
    {
        unit->max_hp += GetStatIncrease(unit->pinfo->growth_hp);
        unit->pow += GetStatIncrease(unit->pinfo->growth_pow);
        unit->skl += GetStatIncrease(unit->pinfo->growth_skl);
        unit->spd += GetStatIncrease(unit->pinfo->growth_spd);
        unit->def += GetStatIncrease(unit->pinfo->growth_def);
        unit->res += GetStatIncrease(unit->pinfo->growth_res);
        unit->lck += GetStatIncrease(unit->pinfo->growth_lck);
    }
}

void UnitCheckStatOverflow(struct Unit * unit)
{
    if (unit->max_hp > UNIT_HP_CAP(unit))
        unit->max_hp = UNIT_HP_CAP(unit);

    if (unit->pow > UNIT_POW_CAP(unit))
        unit->pow = UNIT_POW_CAP(unit);

    if (unit->skl > UNIT_SKL_CAP(unit))
        unit->skl = UNIT_SKL_CAP(unit);

    if (unit->spd > UNIT_SPD_CAP(unit))
        unit->spd = UNIT_SPD_CAP(unit);

    if (unit->def > UNIT_DEF_CAP(unit))
        unit->def = UNIT_DEF_CAP(unit);

    if (unit->res > UNIT_RES_CAP(unit))
        unit->res = UNIT_RES_CAP(unit);

    if (unit->lck > UNIT_LCK_CAP(unit))
        unit->lck = UNIT_LCK_CAP(unit);

    if (unit->bonus_con > (UNIT_CON_CAP(unit) - UNIT_CON_BASE(unit)))
        unit->bonus_con = (UNIT_CON_CAP(unit) - UNIT_CON_BASE(unit));

    if (unit->bonus_mov > (UNIT_MOV_CAP(unit) - UNIT_MOV_BASE(unit)))
        unit->bonus_mov = (UNIT_MOV_CAP(unit) - UNIT_MOV_BASE(unit));
}

struct Unit * GetUnitByPid(int pid)
{
    int i;

    for (i = 1; i < 0x100; ++i)
    {
        struct Unit * unit = GetUnit(i);

        if (!unit)
            continue;

        if (!unit->pinfo)
            continue;

        if (unit->pinfo->id == pid)
            return unit;
    }

    return NULL;
}

bool CanUnitCarry(struct Unit * unit, struct Unit * other)
{
    int aid = GetUnitAid(unit);
    int con = UNIT_CON(other);

    return (aid >= con) ? TRUE : FALSE;
}

void UnitRescue(struct Unit * unit, struct Unit * other)
{
    unit->flags |= UNIT_FLAG_RESCUING;
    other->flags |= UNIT_FLAG_RESCUED + UNIT_FLAG_HIDDEN;

    unit->rescue = other->id;
    other->rescue = unit->id;

    other->x = unit->x;
    other->y = unit->y;
}

void UnitDropRescue(struct Unit * unit, int x, int y)
{
    struct Unit * rescue = GetUnit(unit->rescue);

    unit->flags = unit->flags &~ (UNIT_FLAG_RESCUING + UNIT_FLAG_RESCUED);
    rescue->flags = rescue->flags &~ (UNIT_FLAG_RESCUING + UNIT_FLAG_RESCUED + UNIT_FLAG_HIDDEN);

    if (UNIT_FACTION(rescue) == gPlaySt.faction)
        rescue->flags |= UNIT_FLAG_TURN_ENDED;

    unit->rescue = 0;
    rescue->rescue = 0;

    rescue->x = x;
    rescue->y = y;
}

bool UnitGiveRescue(struct Unit * unit, struct Unit * other)
{
    struct Unit * rescue = GetUnit(unit->rescue);

    bool couldGive = CanUnitCarry(other, rescue);

    UnitDropRescue(unit, 0, 0);
    UnitRescue(other, rescue);

#if BUGFIX
    return couldGive;
#endif
}

inline char const * GetUnitRescueName(struct Unit * unit)
{
    if (unit->rescue == 0)
        return sStatusNameStringLut[UNIT_STATUS_NONE];

    return DecodeMsg(GetUnit(unit->rescue)->pinfo->msg_name);
}

void KillUnit(struct Unit * unit)
{
    if (UNIT_FACTION(unit) == FACTION_BLUE)
    {
        unit->flags |= UNIT_FLAG_DEAD + UNIT_FLAG_HIDDEN;
        ClearUnitSupports(unit);
    }
    else
    {
        // mark as free
        unit->pinfo = NULL;
    }
}

void UnitChangeFaction(struct Unit * unit, int faction)
{
    struct Unit * newUnit = GetFreeUnit(faction);

    if (gActiveUnit == unit)
        gActiveUnit = newUnit;

    CopyUnit(unit, newUnit);
    ClearUnit(unit);

    if (faction == FACTION_BLUE && newUnit->level != UNIT_LEVEL_MAX)
        newUnit->exp = 0;
    else
        newUnit->exp = 0xFF;

    if (newUnit->rescue)
        GetUnit(newUnit->rescue)->rescue = newUnit->id;
}

inline bool CanUnitCrossTerrain(struct Unit * unit, int terrain)
{
    return (unit->jinfo->mov_table[terrain] > 0) ? TRUE : FALSE;
}

void UnitSyncMovement(struct Unit * unit)
{
    if (unit->flags & UNIT_FLAG_RESCUING)
    {
        struct Unit * rescue = GetUnit(unit->rescue);

        rescue->x = unit->x;
        rescue->y = unit->y;
    }
}

void UnitGetDropPositionOnDeath(struct Unit * unit, int* xOut, int* yOut)
{
    int iy, ix, minDistance = 9999;

    struct Unit * rescue = GetUnit(unit->rescue);

    // Fill the movement map
    MapFlood_08019424(unit->x, unit->y, MoveTable_Unk_0860C912);

    // Put the active unit on the unit map (kinda, just marking its spot)
    gMapUnit[gActiveUnit->y][gActiveUnit->x] = 0xFF;

    // Remove the dying unit from the unit map (because it's dying)
    gMapUnit[unit->y][unit->x] = 0;

    for (iy = gMapSize.y - 1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x - 1; ix >= 0; --ix)
        {
            int distance;

            if (gMapMovement[iy][ix] > MAP_MOVEMENT_MAX)
                continue;

            if (gMapUnit[iy][ix] != 0)
                continue;

            if (gMapHidden[iy][ix] != 0)
                continue;

            if (!CanUnitCrossTerrain(rescue, gMapTerrain[iy][ix]))
                continue;

            distance = RECT_DISTANCE(ix, iy, unit->x, unit->y);

            if (minDistance >= distance)
            {
                minDistance = distance;

                *xOut = ix;
                *yOut = iy;
            }
        }
    }

    // Remove the active unit from the unit map again
    gMapUnit[gActiveUnit->y][gActiveUnit->x] = 0;
}

void UnitBeginAction(struct Unit * unit)
{
    gActiveUnit = unit;
    gActiveUnitId = unit->id;

    gActiveUnitMoveOrigin.x = unit->x;
    gActiveUnitMoveOrigin.y = unit->y;

    gAction.instigator = unit->id;
    gAction.id = ACTION_NONE;
    gAction.move_count = 0;

    gBmSt.partial_actions_taken = 0;
    gBmSt.unk_3F = 0xFF;

    func_fe6_08025780();

    gActiveUnit->flags |= UNIT_FLAG_HIDDEN;
    gMapUnit[unit->y][unit->x] = 0;
}

void UnitBeginReMoveAction(struct Unit * unit)
{
    gActiveUnit = unit;
    gActiveUnitId = unit->id;

    gActiveUnitMoveOrigin.x = unit->x;
    gActiveUnitMoveOrigin.y = unit->y;

    gAction.id = ACTION_NONE;

    gBmSt.partial_actions_taken = 0;

    func_fe6_08025780();

    gActiveUnit->flags |= UNIT_FLAG_HIDDEN;
    gMapUnit[unit->y][unit->x] = 0;
}

void func_fe6_08017EDC(int x, int y)
{
    gActiveUnit->x = x;
    gActiveUnit->y = y;

    gActiveUnit->flags |= UNIT_FLAG_TURN_ENDED;

    PidStatsAddSquaresMoved(gActiveUnit->pinfo->id, gAction.move_count);

    if (GetUnitCurrentHp(gActiveUnit) != 0)
        gActiveUnit->flags = gActiveUnit->flags &~ UNIT_FLAG_HIDDEN;

    UnitSyncMovement(gActiveUnit);
}

void ClearActiveFactionTurnEndedState(void)
{
    int i;

    for (i = gPlaySt.faction + 1; i < gPlaySt.faction + 0x40; ++i)
    {
        struct Unit * unit = GetUnit(i);

        if (!unit)
            continue;

        if (!unit->pinfo)
            continue;

        unit->flags &= ~(UNIT_FLAG_TURN_ENDED + UNIT_FLAG_HAD_ACTION + UNIT_FLAG_AI_PROCESSED);
    }
}

void TickActiveFactionTurnAndListStatusHeals(void)
{
    int i;

    bool visionChanged = FALSE;

    BeginTargetList(0, 0);

    for (i = gPlaySt.faction + 1; i < gPlaySt.faction + 0x40; ++i)
    {
        struct Unit * unit = GetUnit(i);

        if (!unit)
            continue;

        if (!unit->pinfo)
            continue;

        if (unit->flags & (UNIT_FLAG_UNAVAILABLE | UNIT_FLAG_RESCUED))
            continue;

        if (unit->barrier != 0)
            unit->barrier--;

        if (unit->torch != 0)
        {
            unit->torch--;
            visionChanged = TRUE;
        }

        if (unit->status_duration != 0)
        {
            unit->status_duration--;

            if (unit->status_duration == 0)
                EnlistTarget(unit->x, unit->y, unit->id, 0);
        }
    }

    if (visionChanged)
    {
        RenderMapForFade();
        RefreshEntityMaps();
        RenderMap();
        StartMapFade(TRUE);
        RefreshUnitSprites();
    }
}

void func_fe6_0801809C(void)
{
    int i;

    for (i = 1; i < 0xC0; ++i)
    {
        struct Unit * unit = GetUnit(i);

        if (!unit)
            continue;

        if (!unit->pinfo)
            continue;

        unit->flags &= ~UNIT_FLAG_SEEN;
    }
}

void UnitUpdateUsedItem(struct Unit * unit, int item_slot)
{
    if (unit->items[item_slot] != 0)
    {
        unit->items[item_slot] = GetItemAfterUse(unit->items[item_slot]);
        UnitRemoveInvalidItems(unit);
    }
}

int GetUnitAid(struct Unit * unit)
{
    if (!(UNIT_ATTRIBUTES(unit) & UNIT_ATTR_MOUNTED))
        return UNIT_CON(unit) - 1;

    if (UNIT_ATTRIBUTES(unit) & UNIT_ATTR_FEMALE)
        return 20 - UNIT_CON(unit);

    return 25 - UNIT_CON(unit);
}

int GetUnitMagRange(struct Unit * unit)
{
    return 5 + GetUnitPower(unit) / 2;
}

bool UnitKnowsMagic(struct Unit * unit)
{
    u8 combinedWeaponExp = 0; 

    combinedWeaponExp |= unit->wexp[ITEM_KIND_STAFF];
    combinedWeaponExp |= unit->wexp[ITEM_KIND_ANIMA];
    combinedWeaponExp |= unit->wexp[ITEM_KIND_LIGHT];
    combinedWeaponExp |= unit->wexp[ITEM_KIND_ELDER];

    return combinedWeaponExp ? TRUE : FALSE;
}

void func_fe6_080181B0(struct Unit * unit, int x, int y)
{
    if (!(unit->flags & UNIT_FLAG_UNDER_ROOF))
    {
        unit->flags = unit->flags &~ (UNIT_FLAG_HIDDEN | UNIT_FLAG_NOT_DEPLOYED);

        unit->x = x;
        unit->y = y;
    }
}

int GetUnitKeyItemSlotForTerrain(struct Unit * unit, int terrain)
{
    int item = 0;

    if (UNIT_ATTRIBUTES(unit) & UNIT_ATTR_STEAL)
    {
        int slot = FindUnitItemSlot(unit, IID_LOCKPICK);

        if (slot >= 0)
            return slot;
    }

    switch (terrain)
    {

    case TERRAIN_CHEST:
        item = IID_CHESTKEY;
        break;

    case TERRAIN_DOOR:
        item = IID_DOORKEY;
        break;

    case TERRAIN_DRAWBRIDGE:
        item = IID_BRIDGEKEY;
        break;

    } // switch (terrain)

    return FindUnitItemSlot(unit, item);
}

int GetAidIconFromAttributes(int attributes)
{
    if (attributes & UNIT_ATTR_MOUNT_ICON)
        return ICON_AID_MOUNT;

    if (attributes & UNIT_ATTR_PEGASUS_ICON)
        return ICON_AID_PEGASUS;

    if (attributes & UNIT_ATTR_WYVERN_ICON)
        return ICON_AID_WYVERN;

    return ICON_NONE;
}

int func_fe6_08018258(struct Unit * unit)
{
    int i, item, result = 0;

    for (i = 0; (i < ITEMSLOT_INV_COUNT) && (item = unit->items[i]); ++i)
    {
        if ((GetItemAttributes(item) & ITEM_ATTR_WEAPON) && CanUnitUseWeapon(unit, item))
            result |= UNIT_USEBIT_WEAPON;

        if ((GetItemAttributes(item) & ITEM_ATTR_STAFF) && CanUnitUseStaff(unit, item))
            result |= UNIT_USEBIT_STAFF;
    }

    return result;
}

bool CanActiveUnitStillMove(void)
{
    i8 adjLut[] =
    {
        -1,  0,
         0, -1,
        +1,  0,
         0, +1,
    };

    int move = UNIT_MOV(gActiveUnit) - gAction.move_count;

    int xUnit = gActiveUnit->x;
    int yUnit = gActiveUnit->y;

    int i;

    for (i = 0; i < 4; ++i)
    {
        int xLocal = xUnit + adjLut[i*2+0];
        int yLocal = yUnit + adjLut[i*2+1];

        int cost;

        if (gMapUnit[yLocal][xLocal] & FACTION_RED)
            continue;

        cost = gActiveUnit->jinfo->mov_table[gMapTerrain[yLocal][xLocal]];

        if ((cost < 0) || (cost > move))
            continue;

        return TRUE;
    }

    return FALSE;
}

struct Unit * CONST_DATA gUnitLut[0x100] =
{
    [FACTION_BLUE + 0x01] = gUnitArrayBlue + 0,
    [FACTION_BLUE + 0x02] = gUnitArrayBlue + 1,
    [FACTION_BLUE + 0x03] = gUnitArrayBlue + 2,
    [FACTION_BLUE + 0x04] = gUnitArrayBlue + 3,
    [FACTION_BLUE + 0x05] = gUnitArrayBlue + 4,
    [FACTION_BLUE + 0x06] = gUnitArrayBlue + 5,
    [FACTION_BLUE + 0x07] = gUnitArrayBlue + 6,
    [FACTION_BLUE + 0x08] = gUnitArrayBlue + 7,
    [FACTION_BLUE + 0x09] = gUnitArrayBlue + 8,
    [FACTION_BLUE + 0x0A] = gUnitArrayBlue + 9,
    [FACTION_BLUE + 0x0B] = gUnitArrayBlue + 10,
    [FACTION_BLUE + 0x0C] = gUnitArrayBlue + 11,
    [FACTION_BLUE + 0x0D] = gUnitArrayBlue + 12,
    [FACTION_BLUE + 0x0E] = gUnitArrayBlue + 13,
    [FACTION_BLUE + 0x0F] = gUnitArrayBlue + 14,
    [FACTION_BLUE + 0x10] = gUnitArrayBlue + 15,
    [FACTION_BLUE + 0x11] = gUnitArrayBlue + 16,
    [FACTION_BLUE + 0x12] = gUnitArrayBlue + 17,
    [FACTION_BLUE + 0x13] = gUnitArrayBlue + 18,
    [FACTION_BLUE + 0x14] = gUnitArrayBlue + 19,
    [FACTION_BLUE + 0x15] = gUnitArrayBlue + 20,
    [FACTION_BLUE + 0x16] = gUnitArrayBlue + 21,
    [FACTION_BLUE + 0x17] = gUnitArrayBlue + 22,
    [FACTION_BLUE + 0x18] = gUnitArrayBlue + 23,
    [FACTION_BLUE + 0x19] = gUnitArrayBlue + 24,
    [FACTION_BLUE + 0x1A] = gUnitArrayBlue + 25,
    [FACTION_BLUE + 0x1B] = gUnitArrayBlue + 26,
    [FACTION_BLUE + 0x1C] = gUnitArrayBlue + 27,
    [FACTION_BLUE + 0x1D] = gUnitArrayBlue + 28,
    [FACTION_BLUE + 0x1E] = gUnitArrayBlue + 29,
    [FACTION_BLUE + 0x1F] = gUnitArrayBlue + 30,
    [FACTION_BLUE + 0x20] = gUnitArrayBlue + 31,
    [FACTION_BLUE + 0x21] = gUnitArrayBlue + 32,
    [FACTION_BLUE + 0x22] = gUnitArrayBlue + 33,
    [FACTION_BLUE + 0x23] = gUnitArrayBlue + 34,
    [FACTION_BLUE + 0x24] = gUnitArrayBlue + 35,
    [FACTION_BLUE + 0x25] = gUnitArrayBlue + 36,
    [FACTION_BLUE + 0x26] = gUnitArrayBlue + 37,
    [FACTION_BLUE + 0x27] = gUnitArrayBlue + 38,
    [FACTION_BLUE + 0x28] = gUnitArrayBlue + 39,
    [FACTION_BLUE + 0x29] = gUnitArrayBlue + 40,
    [FACTION_BLUE + 0x2A] = gUnitArrayBlue + 41,
    [FACTION_BLUE + 0x2B] = gUnitArrayBlue + 42,
    [FACTION_BLUE + 0x2C] = gUnitArrayBlue + 43,
    [FACTION_BLUE + 0x2D] = gUnitArrayBlue + 44,
    [FACTION_BLUE + 0x2E] = gUnitArrayBlue + 45,
    [FACTION_BLUE + 0x2F] = gUnitArrayBlue + 46,
    [FACTION_BLUE + 0x30] = gUnitArrayBlue + 47,
    [FACTION_BLUE + 0x31] = gUnitArrayBlue + 48,
    [FACTION_BLUE + 0x32] = gUnitArrayBlue + 49,
    [FACTION_BLUE + 0x33] = gUnitArrayBlue + 50,
    [FACTION_BLUE + 0x34] = gUnitArrayBlue + 51,
    [FACTION_BLUE + 0x35] = gUnitArrayBlue + 52,
    [FACTION_BLUE + 0x36] = gUnitArrayBlue + 53,
    [FACTION_BLUE + 0x37] = gUnitArrayBlue + 54,
    [FACTION_BLUE + 0x38] = gUnitArrayBlue + 55,
    [FACTION_BLUE + 0x39] = gUnitArrayBlue + 56,
    [FACTION_BLUE + 0x3A] = gUnitArrayBlue + 57,
    [FACTION_BLUE + 0x3B] = gUnitArrayBlue + 58,
    [FACTION_BLUE + 0x3C] = gUnitArrayBlue + 59,
    [FACTION_BLUE + 0x3D] = gUnitArrayBlue + 60,
    [FACTION_BLUE + 0x3E] = gUnitArrayBlue + 61,

    [FACTION_RED + 0x01] = gUnitArrayRed + 0,
    [FACTION_RED + 0x02] = gUnitArrayRed + 1,
    [FACTION_RED + 0x03] = gUnitArrayRed + 2,
    [FACTION_RED + 0x04] = gUnitArrayRed + 3,
    [FACTION_RED + 0x05] = gUnitArrayRed + 4,
    [FACTION_RED + 0x06] = gUnitArrayRed + 5,
    [FACTION_RED + 0x07] = gUnitArrayRed + 6,
    [FACTION_RED + 0x08] = gUnitArrayRed + 7,
    [FACTION_RED + 0x09] = gUnitArrayRed + 8,
    [FACTION_RED + 0x0A] = gUnitArrayRed + 9,
    [FACTION_RED + 0x0B] = gUnitArrayRed + 10,
    [FACTION_RED + 0x0C] = gUnitArrayRed + 11,
    [FACTION_RED + 0x0D] = gUnitArrayRed + 12,
    [FACTION_RED + 0x0E] = gUnitArrayRed + 13,
    [FACTION_RED + 0x0F] = gUnitArrayRed + 14,
    [FACTION_RED + 0x10] = gUnitArrayRed + 15,
    [FACTION_RED + 0x11] = gUnitArrayRed + 16,
    [FACTION_RED + 0x12] = gUnitArrayRed + 17,
    [FACTION_RED + 0x13] = gUnitArrayRed + 18,
    [FACTION_RED + 0x14] = gUnitArrayRed + 19,
    [FACTION_RED + 0x15] = gUnitArrayRed + 20,
    [FACTION_RED + 0x16] = gUnitArrayRed + 21,
    [FACTION_RED + 0x17] = gUnitArrayRed + 22,
    [FACTION_RED + 0x18] = gUnitArrayRed + 23,
    [FACTION_RED + 0x19] = gUnitArrayRed + 24,
    [FACTION_RED + 0x1A] = gUnitArrayRed + 25,
    [FACTION_RED + 0x1B] = gUnitArrayRed + 26,
    [FACTION_RED + 0x1C] = gUnitArrayRed + 27,
    [FACTION_RED + 0x1D] = gUnitArrayRed + 28,
    [FACTION_RED + 0x1E] = gUnitArrayRed + 29,
    [FACTION_RED + 0x1F] = gUnitArrayRed + 30,
    [FACTION_RED + 0x20] = gUnitArrayRed + 31,
    [FACTION_RED + 0x21] = gUnitArrayRed + 32,
    [FACTION_RED + 0x22] = gUnitArrayRed + 33,
    [FACTION_RED + 0x23] = gUnitArrayRed + 34,
    [FACTION_RED + 0x24] = gUnitArrayRed + 35,
    [FACTION_RED + 0x25] = gUnitArrayRed + 36,
    [FACTION_RED + 0x26] = gUnitArrayRed + 37,
    [FACTION_RED + 0x27] = gUnitArrayRed + 38,
    [FACTION_RED + 0x28] = gUnitArrayRed + 39,
    [FACTION_RED + 0x29] = gUnitArrayRed + 40,
    [FACTION_RED + 0x2A] = gUnitArrayRed + 41,
    [FACTION_RED + 0x2B] = gUnitArrayRed + 42,
    [FACTION_RED + 0x2C] = gUnitArrayRed + 43,
    [FACTION_RED + 0x2D] = gUnitArrayRed + 44,
    [FACTION_RED + 0x2E] = gUnitArrayRed + 45,
    [FACTION_RED + 0x2F] = gUnitArrayRed + 46,
    [FACTION_RED + 0x30] = gUnitArrayRed + 47,
    [FACTION_RED + 0x31] = gUnitArrayRed + 48,
    [FACTION_RED + 0x32] = gUnitArrayRed + 49,

    [FACTION_GREEN + 0x01] = gUnitArrayGreen + 0,
    [FACTION_GREEN + 0x02] = gUnitArrayGreen + 1,
    [FACTION_GREEN + 0x03] = gUnitArrayGreen + 2,
    [FACTION_GREEN + 0x04] = gUnitArrayGreen + 3,
    [FACTION_GREEN + 0x05] = gUnitArrayGreen + 4,
    [FACTION_GREEN + 0x06] = gUnitArrayGreen + 5,
    [FACTION_GREEN + 0x07] = gUnitArrayGreen + 6,
    [FACTION_GREEN + 0x08] = gUnitArrayGreen + 7,
    [FACTION_GREEN + 0x09] = gUnitArrayGreen + 8,
    [FACTION_GREEN + 0x0A] = gUnitArrayGreen + 9,
    [FACTION_GREEN + 0x0B] = gUnitArrayGreen + 10,
    [FACTION_GREEN + 0x0C] = gUnitArrayGreen + 11,
    [FACTION_GREEN + 0x0D] = gUnitArrayGreen + 12,
    [FACTION_GREEN + 0x0E] = gUnitArrayGreen + 13,
    [FACTION_GREEN + 0x0F] = gUnitArrayGreen + 14,
    [FACTION_GREEN + 0x10] = gUnitArrayGreen + 15,
    [FACTION_GREEN + 0x11] = gUnitArrayGreen + 16,
    [FACTION_GREEN + 0x12] = gUnitArrayGreen + 17,
    [FACTION_GREEN + 0x13] = gUnitArrayGreen + 18,
    [FACTION_GREEN + 0x14] = gUnitArrayGreen + 19,

    [FACTION_PURPLE + 0x01] = gUnitArrayPurple + 0,
    [FACTION_PURPLE + 0x02] = gUnitArrayPurple + 1,
    [FACTION_PURPLE + 0x03] = gUnitArrayPurple + 2,
    [FACTION_PURPLE + 0x04] = gUnitArrayPurple + 3,
    [FACTION_PURPLE + 0x05] = gUnitArrayPurple + 4,
};
