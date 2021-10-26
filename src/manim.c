#include "common.h"

#include "text.h"
#include "event.h"
#include "util.h"
#include "item.h"
#include "unit.h"
#include "battle.h"
#include "faction.h"
#include "mu.h"

void sub_8061838(ProcPtr proc)
{
    switch (gMapAnimSt.unk_62)
    {

    case 1:
        break;

    default:
        return;

    }

    StartPopup_08012178(gMapAnimSt.actor[1].bu->weapon, proc);
}

void sub_8061878(ProcPtr proc)
{
    struct BattleUnit* bu = NULL;

    if (sub_80618D4(&gBattleUnitA))
        bu = &gBattleUnitA;

    if (sub_80618D4(&gBattleUnitB))
        bu = &gBattleUnitB;

    if (bu != NULL)
    {
        StartWeaponBrokePopup(bu->weapon_before, proc);
    }
}

bool sub_80618D4(struct BattleUnit* bu)
{
    if (UNIT_FACTION(&bu->unit) == FACTION_BLUE)
        return DidBattleUnitBreakWeapon(bu);

    return FALSE;
}

void sub_8061908(ProcPtr proc)
{
    struct BattleUnit* bu = NULL;

    if (sub_8061964(&gBattleUnitA))
        bu = &gBattleUnitA;

    if (sub_8061964(&gBattleUnitB))
        bu = &gBattleUnitB;

    if (bu != NULL)
    {
        StartWeaponLevelGainedPopup(bu->weapon_kind, proc);
    }
}

bool sub_8061964(struct BattleUnit* bu)
{
    if (UNIT_FACTION(&bu->unit) == FACTION_BLUE)
        if (HasBattleUnitGainedWeaponLevel(bu))
            return TRUE;

    return FALSE;
}

void sub_806199C(ProcPtr proc)
{
    ResetText();
}

void sub_80619B0(ProcPtr proc)
{
    ResetMuAnims();
    ResetTextFont();
    sub_8062CF0();
    InitBmBgLayers();
    LoadUiFrameGraphics();
    ApplySystemObjectsGraphics();

    if (IsEventRunning())
        EndAllMus();
}

void sub_80619E8(void)
{
    gMapAnimSt.attacker_actor = !!(gMapAnimSt.hit_it->info & BATTLE_HIT_INFO_RETALIATION);
    gMapAnimSt.defender_actor = 1 - gMapAnimSt.attacker_actor;

    gMapAnimSt.hit_attributes = gMapAnimSt.hit_it->attributes;
    gMapAnimSt.hit_info = gMapAnimSt.hit_it->info;
    gMapAnimSt.hit_damage = gMapAnimSt.hit_it->damage;

    if (gMapAnimSt.unk_5E == 1)
    {
        gMapAnimSt.attacker_actor = 0;
        gMapAnimSt.defender_actor = 0;
    }

    gMapAnimSt.hit_it++;
}

void sub_8061AC8(ProcPtr proc)
{
    if (gMapAnimSt.hit_it->info & BATTLE_HIT_INFO_END)
    {
        Proc_Break(proc);
        Proc_GotoScript(proc, ProcScr_Unk_08664E4C);

        return;
    }

    sub_80619E8();

    Proc_Break(proc);
}

void sub_8061B10(ProcPtr proc)
{
    SpawnProcLocking(sub_8068A48(), proc);
}

void sub_8061B30(ProcPtr proc)
{
    if (gMapAnimSt.hit_attributes & BATTLE_HIT_ATTR_POISON)
    {
        sub_8064B7C(gMapAnimSt.actor[gMapAnimSt.defender_actor].unit);
        StartTemporaryLock(proc, 100);
    }
}

void MA_MoveCameraOntoActor(ProcPtr proc)
{
    CameraMoveWatchPosition(proc, gMapAnimSt.actor[0].unit->x, gMapAnimSt.actor[0].unit->y);
}

void MA_MoveCamOntoTarget(ProcPtr proc)
{
    if (gMapAnimSt.unk_5E == 1)
        return;

    CameraMoveWatchPosition(proc, gMapAnimSt.actor[1].unit->x, gMapAnimSt.actor[1].unit->y);
}

/*

*/
