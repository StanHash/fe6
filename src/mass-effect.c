
#include "mass-effect.h"

#include "armfunc.h"
#include "hardware.h"
#include "oam.h"
#include "sound.h"
#include "util.h"
#include "unit.h"
#include "map.h"
#include "battle.h"
#include "trap.h"
#include "bmfx.h"
#include "faction.h"
#include "action.h"
#include "target-list.h"
#include "unitsprite.h"
#include "mu.h"

#include "constants/items.h"

#include "constants/video-global.h"
#include "constants/songs.h"

void ApplyHazardHealing(ProcPtr proc, struct Unit* unit, int hp, int status)
{
    if (status >= 0)
        SetUnitStatus(unit, status);

    AddUnitHp(unit, hp);

    if (GetUnitCurrentHp(unit) <= 0)
        KillUnit(unit);

    DropRescueOnDeath(proc, unit);
}

static void RenderMapForFogFadeIfUnitDied(struct Unit* unit)
{
    if (GetUnitCurrentHp(unit) == 0 && gPlaySt.vision != 0)
        RenderMapForFade();
}

void BeginUnitHealAnim(struct Unit* unit, int hp)
{
    BattleInitItemEffect(unit, -1);

    gBattleUnitA.weapon = IID_VULNERARY;
    gBattleUnitA.weapon_before = IID_VULNERARY;

    AddUnitHp(&gBattleUnitA.unit, hp);

    gBattleHitIt->damage = gBattleUnitA.previous_hp - gBattleUnitA.unit.hp;

    BattleHitTerminate();

    BeginBattleAnimations();
}

void BeginUnitDamageAnim(struct Unit* unit, int damage)
{
    BattleInitItemEffect(unit, -1);

    AddUnitHp(&gBattleUnitA.unit, -damage);

    if (gBattleUnitA.unit.hp < 0)
        gBattleUnitA.unit.hp = 0;

    gBattleHitIt->damage = gBattleUnitA.previous_hp - gBattleUnitA.unit.hp;

    if (gBattleUnitA.unit.hp == 0)
        gBattleHitIt->info |= BATTLE_HIT_INFO_FINISHES;

    BattleHitTerminate();

    sub_8062598();

    RenderMapForFogFadeIfUnitDied(unit);
}

void BeginUnitCritDamageAnim(struct Unit* unit, int damage)
{
    BattleInitItemEffect(unit, -1);

    AddUnitHp(&gBattleUnitA.unit, -damage);

    if (gBattleUnitA.unit.hp < 0)
        gBattleUnitA.unit.hp = 0;

    gBattleHitIt->damage = gBattleUnitA.previous_hp - gBattleUnitA.unit.hp;

    if (gBattleUnitA.unit.hp == 0)
    {
        gBattleHitIt->attributes |= BATTLE_HIT_ATTR_CRIT;
        gBattleHitIt->info |= BATTLE_HIT_INFO_FINISHES;
    }

    BattleHitTerminate();

    sub_8062614();

    RenderMapForFogFadeIfUnitDied(unit);
}

static void KillAllRedUnits_Init(struct GenericProc* proc)
{
    BeginTargetList(0, 0);

    FOR_UNITS_FACTION(FACTION_RED, unit,
    {
        if (unit->state & (US_DEAD | US_NOT_DEPLOYED))
            continue;

        EnlistTarget(unit->x, unit->y, unit->id, 0);
    })

    proc->unk4C = 0;
}

static void KillAllRedUnits_Loop(struct GenericProc* proc)
{
    struct Unit* unit;
    int x, y;

    if (proc->unk4C == CountTargets())
    {
        Proc_Goto(proc, 99);
        return;
    }

    unit = GetUnit(GetTarget(proc->unk4C)->uid);

    HideUnitSprite(unit);
    KillUnit(unit);

    x = unit->x*16 - gBmSt.camera.x;
    y = unit->y*16 - gBmSt.camera.y;

    if (x < 0 || x > DISPLAY_WIDTH || y < 0 || y > DISPLAY_HEIGHT)
    {
        proc->unk4C++;
        Proc_Goto(proc, 0);
    }
    else
    {
        struct MuProc* mu;

        mu = StartMu(unit);
        StartMuDeathFade(mu);

        proc->unk4C++;
        Proc_Break(proc);
    }
}

struct ProcScr CONST_DATA ProcScr_Unused_KillAllRedUnits[] =
{
    PROC_CALL(KillAllRedUnits_Init),

PROC_LABEL(0),
    PROC_REPEAT(KillAllRedUnits_Loop),
    PROC_SLEEP(0x20),

    PROC_CALL(EndAllMus),

    PROC_GOTO(0),

PROC_LABEL(99),
    PROC_CALL(RefreshEntityMaps),
    PROC_CALL(RenderMap),
    PROC_CALL(RefreshUnitSprites),
    PROC_END,
};

static void StatusHealEffect_OverlayBg_Init(void)
{
    int i;

    ClearBg0Bg1();

    Decompress(Img_StatusHealEffect, (void*) VRAM + BGCHR_STATUSHEAL*CHR_SIZE);
    ApplyPalette(Pal_StatusHealEffect, BGPAL_STATUSHEAL);
    TmApplyTsa_t(gBg0Tm, Tsa_StatusHealEffect, TILEREF(BGCHR_STATUSHEAL, BGPAL_STATUSHEAL));

    for (i = 1; i < 8; ++i)
        TmCopyRect_t(gBg0Tm, gBg0Tm + TM_OFFSET(0, i*4), 2, 4);

    EnableBgSync(BG0_SYNC_BIT);
}

static void StatusHealEffect_OverlayBg_Loop(void)
{
    SetBgOffset(0,
        -(gActiveUnit->x*16 - gBmSt.camera.x), GetGameTime());
}

struct ProcScr CONST_DATA ProcScr_StatusHealEffect_OverlayBg[] =
{
    PROC_CALL(StatusHealEffect_OverlayBg_Init),
    PROC_REPEAT(StatusHealEffect_OverlayBg_Loop),

    PROC_END,
};

static void StatusHealEffect_BlendedSprite_Init(struct GenericProc* proc)
{
    HideUnitSprite(gActiveUnit);

    SetWinEnable(0, 0, 1);

    gDispIo.win_ct.wout_enableBlend = 0;
    gDispIo.win_ct.wobj_enableBlend = 1;

    SetWOutLayers(0, 0, 0, 1, 1);
    SetWObjLayers(1, 0, 0, 1, 1);

    SetBlendTargetA(1, 0, 0, 0, 0);
    SetBlendTargetB(0, 0, 0, 0, 1);

    proc->unk4C = 0x40;
}

static void StatusHealEffect_BlendedSprite_Loop(struct GenericProc* proc)
{
    PutBlendWindowUnitSprite(4,
        gActiveUnit->x*16 - gBmSt.camera.x,
        gActiveUnit->y*16 - gBmSt.camera.y,
        OAM2_LAYER(2) + OAM2_PAL(OBJPAL_STATUSHEAL_UNITSPRITE), gActiveUnit);

    proc->unk4C--;

    if (proc->unk4C < 0)
        Proc_Break(proc);
}

static void StatusHealEffect_BlendedSprite_Finish(struct GenericProc* proc)
{
    ShowUnitSprite(gActiveUnit);
}

struct ProcScr CONST_DATA ProcScr_StatusHealEffect_BlendedSprite[] =
{
    PROC_CALL(StatusHealEffect_BlendedSprite_Init),
    PROC_REPEAT(StatusHealEffect_BlendedSprite_Loop),

    PROC_CALL(StatusHealEffect_BlendedSprite_Finish),

    PROC_END,
};

static void StatusHealEffect_BlendSpriteAnim_InitIn(struct GenericProc* proc)
{
    proc->unk4C = 15;
    proc->x = 0;
    proc->unk34 = 1;
}

static void StatusHealEffect_BlendSpriteAnim_InitOut(struct GenericProc* proc)
{
    proc->unk4C = 15;
    proc->x = 0x10;
    proc->unk34 = -1;
}

static void StatusHealEffect_BlendSpriteAnim_Loop(struct GenericProc* proc)
{
    proc->x += proc->unk34;

    SetBlendAlpha(proc->x, 0x10);

    proc->unk4C--;

    if (proc->unk4C < 0)
        Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_StatusHealEffect_BlendAnim[] =
{
    PROC_CALL(StatusHealEffect_BlendSpriteAnim_InitIn),
    PROC_REPEAT(StatusHealEffect_BlendSpriteAnim_Loop),

    PROC_SLEEP(0x20),

    PROC_CALL(StatusHealEffect_BlendSpriteAnim_InitOut),
    PROC_REPEAT(StatusHealEffect_BlendSpriteAnim_Loop),

    PROC_END,
};

static void StatusHealEffect_PalSpriteAnim_Init(struct GenericProc* proc)
{
    u16 const* pal = NULL;

    switch (UNIT_FACTION(gActiveUnit))
    {

    case FACTION_BLUE:
        pal = &PAL_COLOR(0x10 + OBJPAL_UNITSPRITE_BLUE, 0);
        break;

    case FACTION_RED:
        pal = &PAL_COLOR(0x10 + OBJPAL_UNITSPRITE_RED, 0);
        break;

    case FACTION_GREEN:
        pal = &PAL_COLOR(0x10 + OBJPAL_UNITSPRITE_GREEN, 0);
        break;

    }

    ApplyPalette(pal, 0x10 + OBJPAL_STATUSHEAL_UNITSPRITE);

    proc->unk4C = 0;
}

static void StatusHealEffect_PalSpriteAnim_SetOutlineIntensity(struct GenericProc* proc, int intensity)
{
    if (intensity > 31)
        intensity = 31;

    if (intensity < 0)
        intensity = 0;

    PAL_COLOR(0x10 + OBJPAL_STATUSHEAL_UNITSPRITE, 15) = RGB(intensity, intensity, intensity);
    EnablePalSync();
}

static void StatusHealEffect_PalSpriteAnim_LoopIn(struct GenericProc* proc)
{
    StatusHealEffect_PalSpriteAnim_SetOutlineIntensity(proc, proc->unk4C);

    proc->unk4C++;

    if (proc->unk4C == 0x20)
        Proc_Break(proc);
}

static void StatusHealEffect_PalSpriteAnim_LoopOut(struct GenericProc* proc)
{
    StatusHealEffect_PalSpriteAnim_SetOutlineIntensity(proc, proc->unk4C);

    proc->unk4C--;

    if (proc->unk4C < 0)
        Proc_Break(proc);
}

struct ProcScr CONST_DATA ProcScr_StatusHealEffect_PalAnim[] =
{
    PROC_CALL(StatusHealEffect_PalSpriteAnim_Init),
    PROC_REPEAT(StatusHealEffect_PalSpriteAnim_LoopIn),
    PROC_REPEAT(StatusHealEffect_PalSpriteAnim_LoopOut),

    PROC_END,
};

static void StatusHealEffect_Finish(struct GenericProc* proc)
{
    ClearBg0Bg1();

    SetWinEnable(0, 0, 0);

    SetBlendNone();

    gDispIo.win_ct.wout_enableBlend = 1;
    gDispIo.win_ct.wobj_enableBlend = 1;
}

struct ProcScr CONST_DATA ProcScr_StatusHealEffect[] =
{
    PROC_START_CHILD(ProcScr_StatusHealEffect_OverlayBg),
    PROC_START_CHILD(ProcScr_StatusHealEffect_BlendedSprite),
    PROC_START_CHILD(ProcScr_StatusHealEffect_BlendAnim),
    PROC_START_CHILD(ProcScr_StatusHealEffect_PalAnim),

    PROC_SLEEP(0x42),

    PROC_CALL(StatusHealEffect_Finish),
    PROC_END,
};

void StartStatusHealEffect(struct Unit* unit, ProcPtr parent)
{
    gActiveUnit = unit;

    SpawnProcLocking(ProcScr_StatusHealEffect, parent);

    PlaySe(SONG_AA);
}

static void TerrainHealDisplay_Init(struct GenericProc* proc)
{
    ListTerrainHealingTargets(gPlaySt.faction);

    if (CountTargets() == 0)
    {
        Proc_End(proc);
        return;
    }

    proc->unk4C = 0;
}

static void MassEffectDisplay_Check(struct GenericProc* proc)
{
    struct SelectTarget* target = GetTarget(proc->unk4C);
    struct Unit* unit = GetUnit(target->uid);

    gAction.instigator = target->uid;

    if (proc->unk4C == CountTargets())
    {
        Proc_End(proc);
        return;
    }

    if (gMapFog[unit->y][unit->x] == 0)
        Proc_Goto(proc, 1);
}

static void MassEffectDisplay_Watch(struct GenericProc* proc)
{
    struct SelectTarget* target = GetTarget(proc->unk4C);
    CameraMoveWatchPosition(proc, target->x, target->y);
}

static void TerrainHealDisplay_Display(struct GenericProc* proc)
{
    struct SelectTarget* target = GetTarget(proc->unk4C);
    struct Unit* unit = GetUnit(target->uid);

    if (target->extra < 0)
    {
        StartStatusHealEffect(unit, proc);
    }
    else
    {
        HideUnitSprite(unit);
        BeginUnitHealAnim(unit, target->extra);
    }
}

void FinishDamageDisplay(ProcPtr proc)
{
    EndAllMus();

    if (gBattleUnitA.unit.hp != 0)
    {
        ShowUnitSprite(GetUnit(gAction.instigator));
    }
    else
    {
        gActiveUnit = GetUnit(gAction.instigator);

        if (sub_806B500())
            sub_806B540();
    }
}

static void TerrainHealDisplay_Next(struct GenericProc* proc)
{
    struct SelectTarget* target = GetTarget(proc->unk4C);
    struct Unit* unit = GetUnit(target->uid);

    if (target->extra < 0)
    {
        ApplyHazardHealing(proc, unit, 0, UNIT_STATUS_NONE);
    }
    else
    {
        ApplyHazardHealing(proc, unit, target->extra, -1);
    }

    proc->unk4C++;
}

struct ProcScr CONST_DATA ProcScr_TerrainHealDisplay[] =
{
    PROC_CALL(TerrainHealDisplay_Init),

PROC_LABEL(0),
    PROC_CALL(MassEffectDisplay_Check),
    PROC_CALL(MassEffectDisplay_Watch),
    PROC_SLEEP(0),

    PROC_CALL(TerrainHealDisplay_Display),
    PROC_SLEEP(0),

    PROC_CALL(FinishDamageDisplay),

PROC_LABEL(1),
    PROC_CALL(TerrainHealDisplay_Next),

    PROC_GOTO(0),

    PROC_END,
};

static void PoisonDamageDisplay_Init(struct GenericProc* proc)
{
    ListPoisonDamageTargets(gPlaySt.faction);
    sub_8021B30(4);

    if (CountTargets() == 0)
    {
        Proc_End(proc);
        return;
    }

    proc->unk4C = 0;
}

static void PoisonDamageDisplay_Display(struct GenericProc* proc)
{
    struct SelectTarget* target = GetTarget(proc->unk4C);
    struct Unit* unit = GetUnit(target->uid);

    HideUnitSprite(unit);
    BeginUnitDamageAnim(unit, target->extra);
}

static void PoisonDamageDisplay_Next(struct GenericProc* proc)
{
    struct SelectTarget* target = GetTarget(proc->unk4C);
    struct Unit* unit = GetUnit(target->uid);

    ApplyHazardHealing(proc, unit, -target->extra, -1);

    proc->unk4C++;
}

struct ProcScr CONST_DATA ProcScr_PoisonDamageDisplay[] =
{
    PROC_CALL(PoisonDamageDisplay_Init),

PROC_LABEL(0),
    PROC_CALL(MassEffectDisplay_Check),
    PROC_CALL(MassEffectDisplay_Watch),
    PROC_SLEEP(0),

    PROC_CALL(PoisonDamageDisplay_Display),
    PROC_SLEEP(0),

    PROC_CALL(FinishDamageDisplay),

PROC_LABEL(1),
    PROC_CALL(PoisonDamageDisplay_Next),
    PROC_SLEEP(0),

    PROC_GOTO(0),

    PROC_END,
};

static void StatusDecayDisplay_Init(struct GenericProc* proc)
{
    if (CountTargets() == 0)
    {
        Proc_End(proc);
        return;
    }

    proc->unk4C = 0;
}

static void StatusDecayDisplay_Display(struct GenericProc* proc)
{
    struct SelectTarget* target = GetTarget(proc->unk4C);

    SetUnitStatus(GetUnit(gAction.instigator), UNIT_STATUS_NONE);
    StartStatusHealEffect(GetUnit(target->uid), proc);
}

static void StatusDecayDisplay_Next(struct GenericProc* proc)
{
    SetUnitStatus(GetUnit(gAction.instigator), UNIT_STATUS_NONE);

    proc->unk4C++;
}

struct ProcScr CONST_DATA ProcScr_StatusDecayDisplay[] =
{
    PROC_CALL(StatusDecayDisplay_Init),

PROC_LABEL(0),
    PROC_CALL(MassEffectDisplay_Check),
    PROC_CALL(MassEffectDisplay_Watch),
    PROC_SLEEP(0),

    PROC_CALL(StatusDecayDisplay_Display),
    PROC_SLEEP(0),

PROC_LABEL(1),
    PROC_CALL(StatusDecayDisplay_Next),

    PROC_GOTO(0),

    PROC_END,
};

static void TrapDamageDisplay_Init(struct GenericProc* proc)
{
    proc->unk4C = 0;
}

static void TrapDamageDisplay_Check(struct GenericProc* proc)
{
    struct SelectTarget* target = GetTarget(proc->unk4C);
    struct Unit* unit = GetUnit(target->uid);

    gAction.instigator = target->uid;

    if (proc->unk4C == CountTargets())
    {
        Proc_End(proc);
        return;
    }

    if (target->uid != 0 && gMapFog[unit->y][unit->x] == 0)
        Proc_Goto(proc, 1);
}

static void TrapDamageDisplay_Watch(struct GenericProc* proc)
{
    struct SelectTarget* target = GetTarget(proc->unk4C);

    if (target->uid != 0 || target->extra != 8)
        CameraMoveWatchPosition(proc, target->x, target->y);
}

static void TrapDamageDisplay_Display(struct GenericProc* proc)
{
    struct SelectTarget* target = GetTarget(proc->unk4C);

    if (target->uid == 0)
    {
        switch (target->extra)
        {

        case TRAP_FIRE:
            StartFireTrapAnim(proc, target->x, target->y);
            break;

        case 100:
            StartGasTrapAnim(proc, target->x, target->y, FACING_UP);
            break;

        case 101:
            StartGasTrapAnim(proc, target->x, target->y, FACING_DOWN);
            break;

        case 102:
            StartGasTrapAnim(proc, target->x, target->y, FACING_LEFT);
            break;

        case 103:
            StartGasTrapAnim(proc, target->x, target->y, FACING_RIGHT);
            break;

        case TRAP_LIGHTARROW:
            StartArrowTrapAnim(proc, target->x);
            break;

        case TRAP_8:
            sub_801D920(proc, target->x, target->y);
            break;

        }

        proc->unk4C++;

        Proc_Goto(proc, 0);
        return;
    }

    gAction.instigator = target->uid;
    gAction.extra = target->extra;

    HideUnitSprite(GetUnit(gAction.instigator));

    if (gAction.extra < 6)
        BeginUnitDamageAnim(GetUnit(gAction.instigator), target->extra);
    else
        BeginUnitCritDamageAnim(GetUnit(gAction.instigator), target->extra);
}

static void TrapDamageDisplay_Next(struct GenericProc* proc)
{
    struct SelectTarget* target = GetTarget(proc->unk4C);
    struct Unit* unit = GetUnit(target->uid);

    if (target->extra < 6)
        ApplyHazardHealing(proc, unit, -target->extra, UNIT_STATUS_POISON);
    else
        ApplyHazardHealing(proc, unit, -target->extra, -1);

    proc->unk4C++;
}

struct ProcScr CONST_DATA ProcScr_TrapDamageDisplay[] =
{
    PROC_CALL(TrapDamageDisplay_Init),

PROC_LABEL(0),
    PROC_SLEEP(0),

    PROC_CALL(TrapDamageDisplay_Check),

    PROC_CALL(TrapDamageDisplay_Watch),
    PROC_SLEEP(0),

    PROC_CALL(TrapDamageDisplay_Display),
    PROC_SLEEP(0),

    PROC_CALL(FinishDamageDisplay),

PROC_LABEL(1),
    PROC_CALL(TrapDamageDisplay_Next),

    PROC_GOTO(0),

    PROC_END,
};
