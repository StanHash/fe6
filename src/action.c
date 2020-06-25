
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

static Bool DoRescueAction(ProcPtr proc);
static Bool DoRescueDropAction(ProcPtr proc);
static Bool sub_802A208(ProcPtr proc);
static Bool sub_802A274(ProcPtr proc);
static Bool sub_802A2C0(ProcPtr proc);
static Bool DoCombatAction(ProcPtr proc);
static Bool sub_802A35C(ProcPtr proc);
static Bool DoRefreshAction(ProcPtr proc);
static Bool DoTalkAction(ProcPtr proc);
static Bool DoSupportAction(ProcPtr proc);
static Bool DoStealAction(ProcPtr proc);

struct Action EWRAM_DATA gAction = {};

static void DeathDropAnim_Loop(struct DeathDropAnimProc* proc);
static void DeathDropAnim_End(struct DeathDropAnimProc* proc);

struct ProcScr CONST_DATA ProcScr_DeathDropAnim[] =
{
    PROC_REPEAT(DeathDropAnim_Loop),
    PROC_CALL(DeathDropAnim_End),
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
    RandGetSt(gAction.actionRandSt);
}

void RestoreActionRand(void)
{
    RandSetSt(gAction.actionRandSt);
}

Bool DoAction(ProcPtr proc)
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
        return sub_802A208(proc);

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
        return sub_802A35C(proc);

    case ACTION_USEITEM:
        DoItemAction(proc);
        return FALSE;

    default:
        return TRUE;

    }
}

static Bool DoRescueAction(ProcPtr proc)
{
    struct Unit* instigator = GetUnit(gAction.instigator);
    struct Unit* target = GetUnit(gAction.target);

    StartRescueTransferAnim(target, sub_801C160(instigator->x, instigator->y, target->x, target->y), FALSE, proc);
    UnitRescue(instigator, target);
    HideUnitSprite(target);

    return FALSE;
}

static Bool DoRescueDropAction(ProcPtr proc)
{
    struct Unit* target = GetUnit(gAction.target);

    if (gMapHidden[gAction.yTarget][gAction.xTarget] != 0)
    {
        gWorkingMoveScr[0] = MOVE_CMD_BUMP;
        gWorkingMoveScr[1] = MOVE_CMD_HALT;

        sub_805FC80(gWorkingMoveScr);

        return FALSE;
    }

    UnitSyncMovement(GetUnit(gAction.instigator));

    StartRescueTransferAnim(target, sub_801C160(gAction.xTarget, gAction.yTarget, target->x, target->y), TRUE, proc);
    UnitDropRescue(GetUnit(gAction.instigator), gAction.xTarget, gAction.yTarget);

    return FALSE;
}

static Bool sub_802A208(ProcPtr proc)
{
    int x = GetUnit(gAction.instigator)->x;
    int y = GetUnit(gAction.instigator)->y;

    sub_806B06C(x, y);

    return FALSE;
}

static void sub_802A234(ProcPtr proc, struct Unit* unitA, struct Unit* unitB)
{
    struct Unit* rescue = GetUnit(unitA->rescue);

    StartRescueTransferAnim(rescue, sub_801C160(unitB->x, unitB->y, unitA->x, unitA->y), FALSE, proc);
}

static Bool sub_802A274(ProcPtr proc)
{
    UnitSyncMovement(GetUnit(gAction.target));

    sub_802A234(proc, GetUnit(gAction.target), GetUnit(gAction.instigator));
    UnitGiveRescue(GetUnit(gAction.target), GetUnit(gAction.instigator));

    return FALSE;
}

static Bool sub_802A2C0(ProcPtr proc)
{
    UnitSyncMovement(GetUnit(gAction.instigator));

    sub_802A234(proc, GetUnit(gAction.instigator), GetUnit(gAction.target));
    UnitGiveRescue(GetUnit(gAction.instigator), GetUnit(gAction.target));

    return FALSE;
}

static Bool DoCombatAction(ProcPtr proc)
{
    struct Unit* target = GetUnit(gAction.target);

    if (target == NULL)
        InitObstacleBattleUnit();

    if (gAction.itemSlot == ITEMSLOT_BALLISTA)
        BattleGenerateBallistaReal(GetUnit(gAction.instigator), target);
    else
        BattleGenerateReal(GetUnit(gAction.instigator), target);

    SpawnProcLocking(ProcScr_CombatAction, proc);

    return FALSE;
}

static Bool sub_802A35C(ProcPtr proc)
{
    SpawnProcLocking(ProcScr_085C7DC4, proc);
    return FALSE;
}

static Bool DoRefreshAction(ProcPtr proc)
{
    GetUnit(gAction.target)->state &= ~(US_TURN_ENDED | US_HAS_MOVED | US_HAS_MOVED_AI);

    BattleInitItemEffect(GetUnit(gAction.instigator), -1);
    BattleInitItemEffectTarget(GetUnit(gAction.target));

    gBattleSt.flags = BATTLE_FLAG_REFRESH;

    BattleApplyMiscAction(proc);

    BeginBattleAnimations();

    return FALSE;
}

static Bool DoTalkAction(ProcPtr proc)
{
    sub_806AF90(GetUnit(gAction.instigator)->person->id, GetUnit(gAction.target)->person->id);
    return FALSE;
}

static Bool DoSupportAction(ProcPtr proc)
{
    int expA, expB;

    struct Unit* target = GetUnit(gAction.target);

    int numA = GetUnitSupportNumByPid(gActiveUnit, target->person->id);
    int numB = GetUnitSupportNumByPid(target, gActiveUnit->person->id);

    if (!CanUnitSupportNow(target, numB))
    {
    }

    UnitGainSupportLevel(gActiveUnit, numA);
    UnitGainSupportLevel(target, numB);

    sub_806AFD0(gActiveUnit->person->id, target->person->id, GetUnitSupportLevel(gActiveUnit, numA));

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

static Bool DoStealAction(ProcPtr proc)
{
    int item = GetUnit(gAction.target)->items[gAction.itemSlot];
    UnitRemoveItem(GetUnit(gAction.target), gAction.itemSlot);
    UnitAddItem(GetUnit(gAction.instigator), item);

    BattleInitItemEffect(GetUnit(gAction.instigator), -1);

    gBattleUnitB.terrain = TERRAIN_PLAINS;

    InitBattleUnit(&gBattleUnitB, GetUnit(gAction.target));
    gBattleUnitB.weapon = item;

    BattleApplyMiscAction(proc);

    MU_EndAll();
    sub_8062690();

    return FALSE;
}

static void DeathDropAnim_Loop(struct DeathDropAnimProc* proc)
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

static void DeathDropAnim_End(struct DeathDropAnimProc* proc)
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

        PlaySe(0xAC); // TODO: song ids
    }
}

void KillUnitOnCombatDeath(struct Unit* unit, struct Unit* opponent)
{
    if (GetUnitCurrentHp(unit) == 0)
    {
        sub_8084AEC(unit->person->id, opponent->person->id, 2);
        KillUnit(unit);
    }
}

void sub_802A6B4(struct Unit* unit)
{
    if (GetUnitCurrentHp(unit) == 0)
    {
        KillUnit(unit);
        sub_8084AEC(unit->person->id, 0, 6);
    }
}

static void CombatAction_MaybeSkipPostBanimDeathFades(struct GenericProc* proc)
{
    if ((gBattleSt.flags & BATTLE_FLAG_MAPANIMS) || (gBattleUnitA.unit.hpCur != 0 && gBattleUnitB.unit.hpCur != 0))
        Proc_Goto(proc, 1);
}

static void CombatAction_PostBanimDeathFades(struct GenericProc* proc)
{
    struct MuProc* mu;

    if (gBattleUnitA.unit.hpCur == 0)
    {
        mu = Proc_Find(ProcScr_Mu);

        MU_StartDeathFade(mu);
        proc->ptr = mu;
    }

    if (gBattleUnitB.unit.hpCur == 0)
    {
        RefreshUnitSprites();
        HideUnitSprite(GetUnit(gBattleUnitB.unit.id));

        mu = MU_Start(&gBattleUnitB.unit);

        gWorkingMoveScr[0] = MOVE_CMD_MOVE_BASE
            + sub_80629FC(gBattleUnitA.unit.x, gBattleUnitA.unit.y, gBattleUnitB.unit.x, gBattleUnitB.unit.y);
        gWorkingMoveScr[1] = MOVE_CMD_HALT;

        sub_805FD78(mu, gWorkingMoveScr);
        MU_StartDeathFade(mu);

        proc->ptr = mu;
    }
}

static void CombatAction_PostBanimDeathFadesEnd(struct GenericProc* proc)
{
    sub_80608EC(proc->ptr);
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

void sub_802A7F4(void)
{
    int songId = GetActiveMapSong();

    if (GetCurrentBgmSong() != songId)
        StartBgmExt(songId, 6, NULL);
}

static void CombatAction_0802A814(struct GenericProc* proc)
{
    gBattleUnitB.unit.hpCur = 1;

    if (gBattleUnitA.unit.hpCur != 0)
        Proc_Goto(proc, 1);
}

static void CombatAction_0802A840(struct GenericProc* proc)
{
    sub_802A6B4(gActiveUnit);
    DropRescueOnDeath(proc, gActiveUnit);
}
