
#include "trap.h"
#include "common.h"

#include "sound.h"
#include "proc.h"
#include "msg.h"
#include "item.h"
#include "map.h"
#include "bmfx.h"
#include "faction.h"
#include "target-list.h"
#include "unitsprite.h"
#include "action.h"
#include "chapter-info.h"
#include "mass-effect.h"
#include "mu.h"

#include "constants/items.h"
#include "constants/terrains.h"
#include "constants/songs.h"
#include "constants/msg.h"

enum { TRAP_MAX_COUNT = 0x20 };

static struct Trap EWRAM_DATA sTraps[TRAP_MAX_COUNT] = {};

static void UpdateTraps_CountDownTraps(ProcPtr proc);
static void UpdateTraps_08027248(ProcPtr proc);
static void UpdateTraps_08027264(ProcPtr proc);
static void UpdateTraps_ResetCountedDownTraps(ProcPtr proc);

struct ProcScr CONST_DATA ProcScr_UpdateTraps[] =
{
    PROC_CALL(UpdateTraps_CountDownTraps),
    PROC_CALL(UpdateTraps_08027248),

    PROC_CALL(ListDamagingTrapTargets),
    PROC_CALL(UpdateTraps_08027264),

    PROC_CALL(ListDamagingTrapTargetsForDisplay),
    PROC_START_CHILD_LOCKING(ProcScr_TrapDamageDisplay),

    PROC_CALL(UpdateTraps_ResetCountedDownTraps),
    PROC_CALL(RefreshEntityMaps),

    PROC_END,
};

static void StepPikeTrap_08027318(ProcPtr proc);
static void StepPikeTrap_StartAnim(ProcPtr proc);
static void StepPikeTrap_ApplyDamage(ProcPtr proc);
static void StepFireTrap_08027318(ProcPtr proc);
static void StepFireTrap_StartAnim(ProcPtr proc);
static void StepFireTrap_ApplyDamage(ProcPtr proc);
static void StepTrap_End(ProcPtr proc);

struct ProcScr CONST_DATA ProcScr_StepPikeTrap[] =
{
    PROC_SLEEP(1),

    PROC_CALL(StepPikeTrap_08027318),
    PROC_CALL(StepPikeTrap_StartAnim),
    PROC_SLEEP(0),

    PROC_CALL(StepPikeTrap_ApplyDamage),
    PROC_SLEEP(0),

    PROC_CALL(StepTrap_End),
    PROC_SLEEP(0),

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_StepFireTrap[] =
{
    PROC_SLEEP(1),

    PROC_CALL(StepFireTrap_08027318),
    PROC_CALL(StepFireTrap_StartAnim),
    PROC_SLEEP(0),

    PROC_CALL(StepFireTrap_ApplyDamage),
    PROC_SLEEP(0),

    PROC_CALL(StepTrap_End),
    PROC_SLEEP(0),

    PROC_END,
};

void InitTraps(void)
{
    int i;

    for (i = 0; i < TRAP_MAX_COUNT; ++i)
        sTraps[i].kind = TRAP_NONE;
}

inline struct Trap* GetTrap(int id)
{
    return sTraps + id;
}

struct Trap* GetTrapAt(int x, int y)
{
    struct Trap* trap;

    for (trap = GetTrap(0); trap->kind != TRAP_NONE; ++trap)
    {
        if (x == trap->x && y == trap->y)
            return trap;
    }

    return NULL;
}

struct Trap* AddTrap(int x, int y, int kind, int extra)
{
    struct Trap* trap;

    // Find first free trap
    for (trap = GetTrap(0); trap->kind != TRAP_NONE; ++trap)
    {
    }

    trap->x = x;
    trap->y = y;
    trap->kind = kind;
    trap->extra = extra;

    return trap;
}

struct Trap* AddDamagingTrap(int x, int y, int kind, int extra, int turnCountdown, int turnInterval, int damage)
{
    struct Trap* trap = AddTrap(x, y, kind, extra);

    trap->data[TRAPDATA_TRAP_INITCNT] = turnCountdown;
    trap->data[TRAPDATA_TRAP_INTERVAL] = turnInterval;
    trap->data[TRAPDATA_TRAP_COUNTER] = turnCountdown;
    trap->data[TRAPDATA_TRAP_DAMAGE] = damage;

    return trap;
}

void AddFireTrap(int x, int y, int turnCountdown, int turnInterval)
{
    AddDamagingTrap(x, y, TRAP_FIRE, 0, turnCountdown, turnInterval, 10);
}

void AddGasTrap(int x, int y, int facing, int turnCountdown, int turnInterval)
{
    AddDamagingTrap(x, y, TRAP_GAS, facing, turnCountdown, turnInterval, 3);
}

void AddArrowTrap(int x, int turnCountdown, int turnInterval)
{
    AddDamagingTrap(x, 0, TRAP_LIGHTARROW, 0, turnCountdown, turnInterval, 10);
}

void func_fe6_08026BA4(int x, int y, int turnCountdown, int turnInterval)
{
    AddDamagingTrap(x, y, TRAP_8, 0, turnCountdown, turnInterval, 0);
}

void func_fe6_08026BC0(int x, int y)
{
    AddTrap(x, y, TRAP_STEP_FIRE, 0);
}

void func_fe6_08026BD0(int x, int y, int extra)
{
    AddTrap(x, y, TRAP_STEP_PIKE, extra);
}

void InitMapTraps(void)
{
    int ix, iy;

    for (iy = gMapSize.y - 1; iy >= 0; --iy)
    {
        for (ix = gMapSize.x - 1; ix >= 0; --ix)
        {
            switch (gMapTerrain[iy][ix])
            {

            case TERRAIN_BALLISTA:
                AddTrap(ix, iy, TRAP_BALLISTA, GetItemMaxUses(IID_BALLISTA));
                break;

            case TERRAIN_LONGBALLISTA:
                AddTrap(ix, iy, TRAP_LONGBALLISTA, GetItemMaxUses(IID_LONGBALLISTA));
                break;

            case TERRAIN_KILLERBALLISTA:
                AddTrap(ix, iy, TRAP_KILLERBALLISTA, GetItemMaxUses(IID_KILLERBALLISTA));
                break;

            case TERRAIN_WALL_1B:
                if (gMapTerrain[iy-1][ix] == TERRAIN_WALL_1B)
                    break; // walls are stacked, only the topmost tile gets a trap

                AddTrap(ix, iy, TRAP_OBSTACLE, GetChapterInfo(gPlaySt.chapter)->wall_hp);
                break;

            }
        }
    }
}

void ApplyEnabledMapChanges(void)
{
    struct Trap* trap;

    for (trap = GetTrap(0); trap->kind != TRAP_NONE; ++trap)
    {
        switch (trap->kind)
        {

        case TRAP_MAPCHANGE:
            ApplyMapChange(trap->extra);
            break;

        case TRAP_8:
            // this is a mystery
            ApplyMapChange(trap->extra ? trap->y : trap->x);
            break;

        }
    }
}

struct Trap* GetBallistaTrapAt(int x, int y)
{
    struct Trap* trap;

    switch (gMapTerrain[y][x])
    {

    case TERRAIN_BALLISTA:
    case TERRAIN_LONGBALLISTA:
    case TERRAIN_KILLERBALLISTA:
        trap = GetTrapAt(x, y);

        if (trap == NULL)
            return NULL;

        if (trap->extra == 0)
            return NULL;

        return trap;

    default:
        return NULL;

    }
}


int GetBallistaItemAt(int x, int y)
{
    // NOTE: this functions doesn't use the standard item functions to build items
    // if item repr is changed by a hacker, this *will* break

    struct Trap* trap;

    switch (gMapTerrain[y][x])
    {

    case TERRAIN_BALLISTA:
    case TERRAIN_LONGBALLISTA:
    case TERRAIN_KILLERBALLISTA:
        trap = GetTrapAt(x, y);

        if (trap == NULL)
            return 0;

        if (trap->extra == 0)
            return 0;

        switch (trap->kind)
        {

        case TRAP_BALLISTA:
            return IID_BALLISTA + (trap->extra << 8);

        case TRAP_LONGBALLISTA:
            return IID_LONGBALLISTA + (trap->extra << 8);

        case TRAP_KILLERBALLISTA:
            return IID_KILLERBALLISTA + (trap->extra << 8);

        default:
            return 0;

        }

    default:
        return 0;

    }
}

int GetDummyBallistaItemAt(int x, int y)
{
    // NOTE: this functions doesn't use the standard item functions to build items
    // if item repr is changed by a hacker, this *will* break

    switch (gMapTerrain[y][x])
    {

    case TERRAIN_BALLISTA:
        return IID_BALLISTA + (1 << 8);

    case TERRAIN_LONGBALLISTA:
        return IID_LONGBALLISTA + (1 << 8);

    case TERRAIN_KILLERBALLISTA:
        return IID_KILLERBALLISTA + (1 << 8);

    default:
        return 0;

    }
}

int GetObstacleHpAt(int x, int y)
{
    struct Trap* trap;

    int terrain = gMapTerrain[y][x];

    if (terrain >= TERRAIN_BALLISTA && terrain <= TERRAIN_KILLERBALLISTA)
        return GetTrapAt(x, y)->extra;

    if (terrain != TERRAIN_WALL_1B)
        return 0;

    trap = GetTrapAt(x, y);

    if (trap == NULL)
        trap = GetTrapAt(x, y-1);

    return trap->extra;
}

const struct MapChangeInfo* GetMapChange(int id)
{
    struct MapChangeInfo const* info = GetChapterMapChanges(gPlaySt.chapter);

    if (info == NULL)
        return NULL;

    while (info->id >= 0)
    {
        if (id == info->id)
            return info;

        ++info;
    }

    return NULL;
}

int GetMapChangeIdAt(int x, int y)
{
    int result = -1;

    struct MapChangeInfo const* info = GetChapterMapChanges(gPlaySt.chapter);

    if (info == NULL)
        return result;

    while (info->id >= 0)
    {
        if (x >= info->x)
            if (y >= info->y)
                if (info->x + info->width - 1 >= x)
                    if (info->y + info->height - 1 >= y)
                        result = info->id;

        ++info;
    }

    return result;
}

void ApplyMapChange(int id)
{
    int ix, iy;

    struct MapChangeInfo const* info = GetMapChange(id);
    u16 const* it = info->metatiles;

    for (iy = 0; iy < info->height; ++iy)
    {
        for (ix = 0; ix < info->width; ++ix)
        {
            if (*it != 0)
                gMapMetatiles[info->y+iy][info->x+ix] = *it++;
            else
                ++it;
        }
    }
}

void AddMapChangeTrap(int id)
{
    AddTrap(0, 0, TRAP_MAPCHANGE, id);
}

void UnitHideIfUnderRoof(struct Unit* unit)
{
    if (gMapTerrain[unit->y][unit->x] == TERRAIN_ROOF)
        unit->flags |= (UNIT_FLAG_HIDDEN | UNIT_FLAG_UNDER_ROOF);
}

void UpdateRoofedUnits(void)
{
    int i;

    for (i = 1; i < 0xC0; ++i)
    {
        struct Unit* unit = GetUnit(i);

        if (!unit)
            continue;

        if (!unit->pinfo)
            continue;

        if (!(unit->flags & UNIT_FLAG_UNDER_ROOF))
            continue;

        if (gMapTerrain[unit->y][unit->x] != TERRAIN_ROOF)
        {
            unit->flags &= ~(UNIT_FLAG_UNDER_ROOF | UNIT_FLAG_HIDDEN);
            unit->flags |= UNIT_FLAG_SEEN;
        }
    }

    RefreshEntityMaps();
    RefreshUnitSprites();
}

void EnlistFireTrapTargets(int x, int y, int damage)
{
    if (gMapUnit[y][x] != 0)
        EnlistTarget(x, y, gMapUnit[y][x], damage);
}

void EnlistArrowTrapTargets(int x, int y, int damage)
{
    int iy;

    for (iy = 0; iy < gMapSize.y; ++iy)
    {
        if (gMapUnit[iy][x])
            EnlistTarget(x, iy, gMapUnit[iy][x], damage);
    }
}

void EnlistGasTrapTargets(int x, int y, int damage, int facing)
{
    int i;

    int xInc = 0;
    int yInc = 0;

    switch (facing)
    {

    case FACING_UP:
        xInc = 0;
        yInc = -1;

        break;

    case FACING_DOWN:
        xInc = 0;
        yInc = +1;

        break;

    case FACING_LEFT:
        xInc = -1;
        yInc = 0;

        break;

    case FACING_RIGHT:
        xInc = +1;
        yInc = 0;

        break;

    }

    for (i = 2; i >= 0; --i)
    {
        x += xInc;
        y += yInc;

        if (gMapUnit[y][x])
            EnlistTarget(x, y, gMapUnit[y][x], damage);
    }
}

void ListDamagingTrapTargets(void)
{
    struct Trap* trap;

    BeginTargetList(0, 0);

    for (trap = GetTrap(0); trap->kind != TRAP_NONE; ++trap)
    {
        if (trap->data[TRAPDATA_TRAP_COUNTER] == 0)
        {
            switch (trap->kind)
            {

            case TRAP_FIRE:
                EnlistFireTrapTargets(trap->x, trap->y, trap->data[TRAPDATA_TRAP_DAMAGE]);
                break;

            case TRAP_LIGHTARROW:
                EnlistArrowTrapTargets(trap->x, trap->y, trap->data[TRAPDATA_TRAP_DAMAGE]);
                break;

            case TRAP_GAS:
                EnlistGasTrapTargets(trap->x, trap->y, trap->data[TRAPDATA_TRAP_DAMAGE], trap->extra);
                break;

            }
        }
    }
}

void ListDamagingTrapTargetsForDisplay(void)
{
    struct Trap* trap;

    int specialType = 0;

    BeginTargetList(0, 0);

    for (trap = GetTrap(0); trap->kind != TRAP_NONE; ++trap)
    {
        if (trap->data[TRAPDATA_TRAP_COUNTER] == 0)
        {
            switch (trap->kind)
            {

            case TRAP_FIRE:
                EnlistTarget(trap->x, trap->y, 0, TRAP_FIRE);
                EnlistFireTrapTargets(trap->x, trap->y, trap->data[TRAPDATA_TRAP_DAMAGE]);

                break;

            case TRAP_GAS:
                switch (trap->extra)
                {

                    // TODO: figure out

                case FACING_UP:
                    specialType = 0x64;
                    break;

                case FACING_DOWN:
                    specialType = 0x65;
                    break;

                case FACING_LEFT:
                    specialType = 0x66;
                    break;

                case FACING_RIGHT:
                    specialType = 0x67;
                    break;

                }

                EnlistTarget(trap->x, trap->y, 0, specialType);
                EnlistGasTrapTargets(trap->x, trap->y, trap->data[TRAPDATA_TRAP_DAMAGE], trap->extra);

                break;

            case TRAP_LIGHTARROW:
                EnlistTarget(trap->x, trap->y, 0, TRAP_LIGHTARROW);
                EnlistArrowTrapTargets(trap->x, trap->y, trap->data[TRAPDATA_TRAP_DAMAGE]);
                break;

            case TRAP_8:
                EnlistTarget(trap->extra ? trap->x : trap->y, TRAP_ID(trap), 0, trap->kind);
                break;

            }
        }
    }
}

static void UpdateTraps_CountDownTraps(ProcPtr proc)
{
    struct Trap* trap;

    for (trap = GetTrap(0); trap->kind != TRAP_NONE; ++trap)
    {
        switch (trap->kind)
        {

        case TRAP_FIRE:
        case TRAP_GAS:
        case TRAP_LIGHTARROW:
        case TRAP_8:
            trap->data[TRAPDATA_TRAP_COUNTER]--;
            break;

        }
    }
}

static void UpdateTraps_ResetCountedDownTraps(ProcPtr proc)
{
    struct Trap* trap;

    for (trap = GetTrap(0); trap->kind != TRAP_NONE; ++trap)
    {
        switch (trap->kind)
        {

        case TRAP_FIRE:
        case TRAP_GAS:
        case TRAP_LIGHTARROW:
        case TRAP_8:
            if (trap->data[TRAPDATA_TRAP_COUNTER] == 0)
                trap->data[TRAPDATA_TRAP_COUNTER] = trap->data[TRAPDATA_TRAP_INTERVAL];

            break;

        }
    }
}

static void UpdateTraps_08027248(ProcPtr proc)
{
    int faction = gPlaySt.faction;
    gPlaySt.faction = FACTION_RED;

    RefreshEntityMaps();

    gPlaySt.faction = faction;
}

static void UpdateTraps_08027264(ProcPtr proc)
{
    func_fe6_08021B30(3);
}

static void StepPikeTrap_StartAnim(ProcPtr proc)
{
    struct Trap* trap = GetTrapAt(gActiveUnit->x, gActiveUnit->y);
    StartPikeTrapAnim(proc, gActiveUnit->x, gActiveUnit->y, trap->extra);
}

static void StepFireTrap_StartAnim(ProcPtr proc)
{
    StartFireTrapAnim(proc, gActiveUnit->x, gActiveUnit->y);
}

static void StepPikeTrap_ApplyDamage(ProcPtr proc)
{
    int damage = 10 - GetUnitDefense(gActiveUnit);

    if (damage < 0)
        damage = 0;

    EndAllMus();

    gAction.extra = damage;
    BeginUnitCritDamageAnim(gActiveUnit, damage);
}

static void StepFireTrap_ApplyDamage(ProcPtr proc)
{
    EndAllMus();

    gAction.extra = 10;
    BeginUnitCritDamageAnim(gActiveUnit, 10);
}

static void StepFireTrap_08027318(ProcPtr proc)
{
    if (GetUnitCurrentHp(gActiveUnit) <= 10)
        func_fe6_08084A10(gActiveUnit->pinfo->id);
}

static void StepPikeTrap_08027318(ProcPtr proc)
{
    int damage = 10 - GetUnitDefense(gActiveUnit);

    if (GetUnitCurrentHp(gActiveUnit) <= damage)
        func_fe6_08084A10(gActiveUnit->pinfo->id);
}

static void StepTrap_End(ProcPtr proc)
{
    ApplyHazardHealing(proc, GetUnit(gAction.instigator), -gAction.extra, -1);

    if (GetUnitCurrentHp(gActiveUnit) <= 0)
        func_fe6_08084AEC(gActiveUnit->pinfo->id, 0, 3);

    FinishDamageDisplay(proc);

    HideUnitSprite(GetUnit(gAction.instigator));
}

bool DoHandleStepTraps(ProcPtr proc)
{
    struct Trap* trap;

    if (GetUnitCurrentHp(gActiveUnit) <= 0)
        return TRUE;

    for (trap = GetTrap(0); trap->kind != TRAP_NONE; ++trap)
    {
        switch (trap->kind)
        {

        case TRAP_STEP_FIRE:
            if (gActiveUnit->x != trap->x)
                continue;

            if (gActiveUnit->y == trap->y)
                goto trap_step_fire;

            // continue;

        case TRAP_STEP_PIKE:
            if (gActiveUnit->x != trap->x)
                continue;

            if (gActiveUnit->y == trap->y)
                goto trap_step_pike;

            // continue;

        }
    }

    return TRUE;

trap_step_pike:
    if (UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_STEAL)
        goto disarm;

    SpawnProcLocking(ProcScr_StepPikeTrap, proc);
    return FALSE;

trap_step_fire:
    if (UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_STEAL)
        goto disarm;

    SpawnProcLocking(ProcScr_StepFireTrap, proc);
    return FALSE;

disarm:
    trap->kind = TRAP_STEP_DISARMED;

    PlaySe(SONG_B1);
    func_fe6_0801DA54(proc, -1, DecodeMsg(MSG_C1A));

    return FALSE;
}
