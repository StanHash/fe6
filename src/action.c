
#include "action.h"

#include "random.h"
#include "sound.h"
#include "util.h"
#include "unit.h"
#include "map.h"
#include "mapwork.h"
#include "bmfx.h"
#include "support.h"
#include "battle.h"
#include "unitsprite.h"
#include "item-action.h"
#include "mu.h"

#include "constants/terrains.h"
#include "constants/songs.h"

struct DeathDropAnimProc
{
    /* 00 */ PROC_HEADER;
    /* 2C */ struct Unit* unit;
    /* 30 */ int xDrop, yDrop;
    /* 38 */ short xFrom, yFrom;
    /* 3C */ short xTo, yTo;
    /* 40 */ short yOffset;
    /* 42 */ short ySpeed;
    /* 44 */ short yAccel;
    /* 46 */ short clock;
    /* 48 */ short clockEnd;
};

static bool DoRescueAction(ProcPtr proc);
static bool DoRescueDropAction(ProcPtr proc);
static bool func_fe6_0802A208(ProcPtr proc);
static bool func_fe6_0802A274(ProcPtr proc);
static bool func_fe6_0802A2C0(ProcPtr proc);
static bool DoCombatAction(ProcPtr proc);
static bool func_fe6_0802A35C(ProcPtr proc);
static bool DoRefreshAction(ProcPtr proc);
static bool DoTalkAction(ProcPtr proc);
static bool DoSupportAction(ProcPtr proc);
static bool DoStealAction(ProcPtr proc);

struct Action EWRAM_DATA gAction = {};

static void DeathDropSpriteAnim_Loop(struct DeathDropAnimProc* proc);
static void DeathDropSpriteAnim_End(struct DeathDropAnimProc* proc);

struct ProcScr CONST_DATA ProcScr_DeathDropAnim[] =
{
    PROC_REPEAT(DeathDropSpriteAnim_Loop),
    PROC_CALL(DeathDropSpriteAnim_End),
    PROC_END,
};

static void CombatAction_MaybeSkipPostBanimDeathFades(struct GenericProc* proc);
static void CombatAction_PostBanimDeathFades(struct GenericProc* proc);
static void CombatAction_PostBanimDeathFadesEnd(struct GenericProc* proc);
static void CombatAction_DoHandleDeaths(struct GenericProc* proc);
static void CombatAction_0802A814(struct GenericProc* proc);
static void CombatAction_0802A840(struct GenericProc* proc);

struct ProcScr CONST_DATA ProcScr_CombatAction[] =
{
    PROC_CALL(BeginBattleAnimations),
    PROC_SLEEP(1),

    PROC_CALL(BattleApplyGameStateUpdates),

    PROC_WHILE(IsMapFadeActive),

    PROC_CALL(CombatAction_MaybeSkipPostBanimDeathFades),
    PROC_CALL(CombatAction_PostBanimDeathFades),

    PROC_SLEEP(32),

    PROC_CALL(CombatAction_PostBanimDeathFadesEnd),

PROC_LABEL(1),
    PROC_CALL(CombatAction_DoHandleDeaths),
    PROC_SLEEP(0),

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_085C7DC4[] =
{
    PROC_SLEEP(0),

    PROC_CALL(CombatAction_0802A814),
    PROC_CALL(CombatAction_PostBanimDeathFades),

    PROC_SLEEP(32),

    PROC_CALL(CombatAction_PostBanimDeathFadesEnd),

PROC_LABEL(1),
    PROC_CALL(CombatAction_0802A840),
    PROC_SLEEP(0),

    PROC_END,
};

void SaveActionRand(void)
{
    RandGetSt(gAction.action_rand_st);
}

void RestoreActionRand(void)
{
    RandSetSt(gAction.action_rand_st);
}

bool DoAction(ProcPtr proc)
{
    gActiveUnit = GetUnit(gAction.instigator);

    switch (gAction.id)
    {

    case ACTION_WAIT:
    case ACTION_TRAPPED:
        gActiveUnit->state |= US_HAS_MOVED;
        return TRUE;

    case ACTION_RESCUE:
        return DoRescueAction(proc);

    case ACTION_DROP:
        return DoRescueDropAction(proc);

    case ACTION_0E:
    case ACTION_0F:
        return func_fe6_0802A208(proc);

    case ACTION_COMBAT:
        return DoCombatAction(proc);

    case ACTION_STAFF:
        DoItemAction(proc);
        return FALSE;

    case ACTION_REFRESH:
        return DoRefreshAction(proc);

    case ACTION_TALK:
        return DoTalkAction(proc);

    case ACTION_SUPPORT:
        return DoSupportAction(proc);

    case ACTION_DOOR:
    case ACTION_CHEST:
        DoItemAction(proc);
        return FALSE;

    case ACTION_STEAL:
        return DoStealAction(proc);

    case ACTION_16:
        return func_fe6_0802A35C(proc);

    case ACTION_USEITEM:
        DoItemAction(proc);
        return FALSE;

    default:
        return TRUE;

    }
}

static bool DoRescueAction(ProcPtr proc)
{
    struct Unit* instigator = GetUnit(gAction.instigator);
    struct Unit* target = GetUnit(gAction.target);

    StartRescueTransferAnim(target, func_fe6_0801C160(instigator->x, instigator->y, target->x, target->y), FALSE, proc);
    UnitRescue(instigator, target);
    HideUnitSprite(target);

    return FALSE;
}

static bool DoRescueDropAction(ProcPtr proc)
{
    struct Unit* target = GetUnit(gAction.target);

    if (gMapHidden[gAction.y_target][gAction.x_target] != 0)
    {
        gWorkingMoveScr[0] = MOVE_CMD_BUMP;
        gWorkingMoveScr[1] = MOVE_CMD_HALT;

        SetAutoMuMoveScript(gWorkingMoveScr);

        return FALSE;
    }

    UnitSyncMovement(GetUnit(gAction.instigator));

    StartRescueTransferAnim(target, func_fe6_0801C160(gAction.x_target, gAction.y_target, target->x, target->y), TRUE, proc);
    UnitDropRescue(GetUnit(gAction.instigator), gAction.x_target, gAction.y_target);

    return FALSE;
}

static bool func_fe6_0802A208(ProcPtr proc)
{
    int x = GetUnit(gAction.instigator)->x;
    int y = GetUnit(gAction.instigator)->y;

    func_fe6_0806B06C(x, y);

    return FALSE;
}

static void func_fe6_0802A234(ProcPtr proc, struct Unit* unitA, struct Unit* unitB)
{
    struct Unit* rescue = GetUnit(unitA->rescue);

    StartRescueTransferAnim(rescue, func_fe6_0801C160(unitB->x, unitB->y, unitA->x, unitA->y), FALSE, proc);
}

static bool func_fe6_0802A274(ProcPtr proc)
{
    UnitSyncMovement(GetUnit(gAction.target));

    func_fe6_0802A234(proc, GetUnit(gAction.target), GetUnit(gAction.instigator));
    UnitGiveRescue(GetUnit(gAction.target), GetUnit(gAction.instigator));

    return FALSE;
}

static bool func_fe6_0802A2C0(ProcPtr proc)
{
    UnitSyncMovement(GetUnit(gAction.instigator));

    func_fe6_0802A234(proc, GetUnit(gAction.instigator), GetUnit(gAction.target));
    UnitGiveRescue(GetUnit(gAction.instigator), GetUnit(gAction.target));

    return FALSE;
}

static bool DoCombatAction(ProcPtr proc)
{
    struct Unit* target = GetUnit(gAction.target);

    if (target == NULL)
        InitObstacleBattleUnit();

    if (gAction.item_slot == ITEMSLOT_BALLISTA)
        BattleGenerateBallistaReal(GetUnit(gAction.instigator), target);
    else
        BattleGenerateReal(GetUnit(gAction.instigator), target);

    SpawnProcLocking(ProcScr_CombatAction, proc);

    return FALSE;
}

static bool func_fe6_0802A35C(ProcPtr proc)
{
    SpawnProcLocking(ProcScr_085C7DC4, proc);
    return FALSE;
}

static bool DoRefreshAction(ProcPtr proc)
{
    GetUnit(gAction.target)->state &= ~(US_TURN_ENDED | US_HAS_MOVED | US_HAS_MOVED_AI);

    BattleInitItemEffect(GetUnit(gAction.instigator), -1);
    BattleInitItemEffectTarget(GetUnit(gAction.target));

    gBattleSt.flags = BATTLE_FLAG_REFRESH;

    BattleApplyMiscAction(proc);

    BeginBattleAnimations();

    return FALSE;
}

static bool DoTalkAction(ProcPtr proc)
{
    func_fe6_0806AF90(GetUnit(gAction.instigator)->pinfo->id, GetUnit(gAction.target)->pinfo->id);
    return FALSE;
}

static bool DoSupportAction(ProcPtr proc)
{
    int expA, expB;

    struct Unit* target = GetUnit(gAction.target);

    int numA = GetUnitSupportNumByPid(gActiveUnit, target->pinfo->id);
    int numB = GetUnitSupportNumByPid(target, gActiveUnit->pinfo->id);

    if (!CanUnitSupportNow(target, numB))
    {
    }

    UnitGainSupportLevel(gActiveUnit, numA);
    UnitGainSupportLevel(target, numB);

    func_fe6_0806AFD0(gActiveUnit->pinfo->id, target->pinfo->id, GetUnitSupportLevel(gActiveUnit, numA));

    expA = gActiveUnit->supports[numA];
    expB = target->supports[numB];

    if (expA != expB)
    {
        if (expA > expB)
            target->supports[numB] = expA;

        if (expA < expB)
            gActiveUnit->supports[numA] = expB;
    }

    return FALSE;
}

static bool DoStealAction(ProcPtr proc)
{
    int item = GetUnit(gAction.target)->items[gAction.item_slot];
    UnitRemoveItem(GetUnit(gAction.target), gAction.item_slot);
    UnitAddItem(GetUnit(gAction.instigator), item);

    BattleInitItemEffect(GetUnit(gAction.instigator), -1);

    gBattleUnitB.terrain = TERRAIN_PLAINS;

    InitBattleUnit(&gBattleUnitB, GetUnit(gAction.target));
    gBattleUnitB.weapon = item;

    BattleApplyMiscAction(proc);

    EndAllMus();
    func_fe6_08062690();

    return FALSE;
}

static void DeathDropSpriteAnim_Loop(struct DeathDropAnimProc* proc)
{
    int x = Interpolate(INTERPOLATE_LINEAR, proc->xFrom, proc->xTo, proc->clock, proc->clockEnd);
    int y = Interpolate(INTERPOLATE_LINEAR, proc->yFrom, proc->yTo, proc->clock, proc->clockEnd);

    y += proc->yOffset;

    proc->yOffset += proc->ySpeed;
    proc->ySpeed += proc->yAccel;

    PutUnitSprite(7, x - gBmSt.camera.x, y - gBmSt.camera.y, proc->unit);

    ++proc->clock;

    if (proc->clock == proc->clockEnd)
        Proc_Break(proc);
}

static void DeathDropSpriteAnim_End(struct DeathDropAnimProc* proc)
{
    RefreshEntityMaps();
    RefreshUnitSprites();
}

void DropRescueOnDeath(ProcPtr parent, struct Unit* unit)
{
    if (GetUnitCurrentHp(unit) == 0 && (unit->state & US_RESCUING))
    {
        struct DeathDropAnimProc* proc = SpawnProcLocking(ProcScr_DeathDropAnim, parent);

        proc->unit = GetUnit(unit->rescue);

        UnitGetDropPositionOnDeath(unit, &proc->xDrop, &proc->yDrop);
        UnitDropRescue(unit, proc->xDrop, proc->yDrop);

        proc->xFrom = unit->x*16;
        proc->yFrom = unit->y*16;

        proc->xTo = proc->xDrop*16;
        proc->yTo = proc->yDrop*16;

        proc->yOffset = 0;
        proc->ySpeed = -5;
        proc->yAccel = +1;

        proc->clock = 0;
        proc->clockEnd = 11;

        proc->unit->state &= ~US_TURN_ENDED;

        UseUnitSprite(GetUnitMapSprite(proc->unit));
        ForceSyncUnitSpriteSheet();

        PlaySe(SONG_AC);
    }
}

void KillUnitOnCombatDeath(struct Unit* unit, struct Unit* opponent)
{
    if (GetUnitCurrentHp(unit) == 0)
    {
        func_fe6_08084AEC(unit->pinfo->id, opponent->pinfo->id, 2);
        KillUnit(unit);
    }
}

void func_fe6_0802A6B4(struct Unit* unit)
{
    if (GetUnitCurrentHp(unit) == 0)
    {
        KillUnit(unit);
        func_fe6_08084AEC(unit->pinfo->id, 0, 6);
    }
}

static void CombatAction_MaybeSkipPostBanimDeathFades(struct GenericProc* proc)
{
    if ((gBattleSt.flags & BATTLE_FLAG_MAPANIMS) || (gBattleUnitA.unit.hp != 0 && gBattleUnitB.unit.hp != 0))
        Proc_Goto(proc, 1);
}

static void CombatAction_PostBanimDeathFades(struct GenericProc* proc)
{
    struct MuProc* mu;

    if (gBattleUnitA.unit.hp == 0)
    {
        mu = Proc_Find(ProcScr_Mu);

        StartMuDeathFade(mu);
        proc->ptr = mu;
    }

    if (gBattleUnitB.unit.hp == 0)
    {
        RefreshUnitSprites();
        HideUnitSprite(GetUnit(gBattleUnitB.unit.id));

        mu = StartMu(&gBattleUnitB.unit);

        gWorkingMoveScr[0] = MOVE_CMD_MOVE_BASE
            + func_fe6_080629FC(gBattleUnitA.unit.x, gBattleUnitA.unit.y, gBattleUnitB.unit.x, gBattleUnitB.unit.y);
        gWorkingMoveScr[1] = MOVE_CMD_HALT;

        SetMuMoveScript(mu, gWorkingMoveScr);
        StartMuDeathFade(mu);

        proc->ptr = mu;
    }
}

static void CombatAction_PostBanimDeathFadesEnd(struct GenericProc* proc)
{
    EndMu(proc->ptr);
}

static void CombatAction_DoHandleDeaths(struct GenericProc* proc)
{
    struct Unit* unitA = GetUnit(gBattleUnitA.unit.id);
    struct Unit* unitB = GetUnit(gBattleUnitB.unit.id);

    DropRescueOnDeath(proc, unitA);
    DropRescueOnDeath(proc, unitB);

    KillUnitOnCombatDeath(unitA, unitB);
    KillUnitOnCombatDeath(unitB, unitA);
}

void func_fe6_0802A7F4(void)
{
    int songId = GetActiveMapSong();

    if (GetCurrentBgmSong() != songId)
        StartBgmExt(songId, 6, NULL);
}

static void CombatAction_0802A814(struct GenericProc* proc)
{
    gBattleUnitB.unit.hp = 1;

    if (gBattleUnitA.unit.hp != 0)
        Proc_Goto(proc, 1);
}

static void CombatAction_0802A840(struct GenericProc* proc)
{
    func_fe6_0802A6B4(gActiveUnit);
    DropRescueOnDeath(proc, gActiveUnit);
}
