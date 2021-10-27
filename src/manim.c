#include "common.h"

#include "hardware.h"
#include "sound.h"
#include "text.h"
#include "event.h"
#include "util.h"
#include "item.h"
#include "unit.h"
#include "battle.h"
#include "faction.h"
#include "mu.h"

#include "constants/items.h"
#include "constants/jids.h"
#include "constants/video-global.h"
#include "constants/songs.h"
#include "constants/terrains.h"

struct MAnimExpBarProc
{
    /* 00 */ PROC_HEADER;

    /* 29 */ u8 pad_29[0x64 - 0x29];
    /* 64 */ short exp_from;
    /* 66 */ short exp_to;
    /* 68 */ short actor_num;
    /* 6A */ short unk_6A;
};

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

    if (gMapAnimSt.actor_count == 1)
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
    if (gMapAnimSt.actor_count == 1)
        return;

    CameraMoveWatchPosition(proc, gMapAnimSt.actor[1].unit->x, gMapAnimSt.actor[1].unit->y);
}

void MA_DisplayDeathQuote(ProcPtr proc)
{
    int actor_num = -1;

    switch (gMapAnimSt.actor_count)
    {

    case 2:
        if (gMapAnimSt.actor[1].unk_0D == 0)
            actor_num = 1;

        // fallthrough

    case 1:
        if (gMapAnimSt.actor[0].unk_0D == 0)
            actor_num = 0;

        break;

    }

    if (actor_num != -1)
    {
        int pid = gMapAnimSt.actor[actor_num].unit->pinfo->id;

        if (ShouldDisplayDeathQuote(pid))
        {
            sub_8062CF0();
            sub_806B808(pid);
            DisableEventSkip();
        }
    }
}

void MapAnimProc_DisplayDeathFade(ProcPtr proc)
{
    int actor_num = -1;

    switch (gMapAnimSt.actor_count)
    {

    case 2:
        if (gMapAnimSt.actor[1].unk_0D == 0)
            actor_num = 1;

        // fallthrough

    case 1:
        if (gMapAnimSt.actor[0].unk_0D == 0)
            actor_num = 0;

        break;

    }

    if (actor_num != -1)
    {
        StartMuDeathFade(gMapAnimSt.actor[actor_num].mu);
    }
}

void MapAnimProc_DisplayExpBar(ProcPtr proc)
{
    struct MAnimExpBarProc* exp_bar_proc;
    int actor_num = -1;

    switch (gMapAnimSt.actor_count)
    {

    case 2:
        if (gMapAnimSt.actor[1].bu->exp_gain != 0)
            actor_num = 1;

        // fallthrough

    case 1:
        if (gMapAnimSt.actor[0].bu->exp_gain != 0)
            actor_num = 0;

        break;

    }

    if (actor_num >= 0)
    {
        exp_bar_proc = SpawnProcLocking(ProcScr_MAnimExpBar, proc);

        exp_bar_proc->exp_from = gMapAnimSt.actor[actor_num].bu->previous_exp;
        exp_bar_proc->exp_to = gMapAnimSt.actor[actor_num].bu->previous_exp + gMapAnimSt.actor[actor_num].bu->exp_gain;
        exp_bar_proc->actor_num = actor_num;
    }
}

void sub_8061E14(ProcPtr proc)
{
    int y;

    SetBlendNone();

    switch (gMapAnimSt.unk_62)
    {

    case 1:
    case 2:
        return;

    default:
        break;

    }

    if (sub_805F7B4(gMapAnimSt.actor[0].bu->weapon_before) == 0)
        return;

    if (gMapAnimSt.actor_count == 1)
    {
        y = (gMapAnimSt.actor[0].unit->y << 4) - gBmSt.camera.y;

        if (y >= 112)
            y = y - 40;
        else
            y = y + 24;
    }
    else
    {
        int array[2];
        int i, actor_num;

        for (i = 0; i < gMapAnimSt.actor_count; ++i)
        {
            array[i] = (gMapAnimSt.actor[i].unit->y << 4) - gBmSt.camera.y;
        }

        if ((array[0] - array[1] >= 0)
            ? (array[0] - array[1] >= 80)
            : (array[1] - array[0] >= 80))
        {
            y = 64;
        }
        else
        {
            actor_num = array[0] > array[1] ? 0 : 1;

            if (array[actor_num] >= 112)
                y = array[1 - actor_num] - 40;
            else
                y = array[actor_num] + 24;
        }
    }

    MA_StartBattleInfoBox(15, y / 8, proc);
}

void sub_8061FD0(ProcPtr proc)
{
    switch (gMapAnimSt.actor_count)
    {

    case 2:
        sub_806B754(
            gMapAnimSt.actor[0].unit->pinfo->id,
            gMapAnimSt.actor[1].unit->pinfo->id);

        break;

    default:
        break;

    }

    DisableEventSkip();
}

void sub_8062018(int actor_num)
{
    switch (GetItemIid(gMapAnimSt.actor[actor_num].bu->weapon_before))
    {

    case IID_FIRESTONE:
        SetMuPal(gMapAnimSt.actor[actor_num].mu, OBJPAL_MANIM_SPECIALMU + actor_num);
        SetMuSpecialSprite(gMapAnimSt.actor[actor_num].mu, JID_FIREDRAGON, Pal_ManimFireDragonMu);
        break;

    case IID_DIVINESTONE:
        SetMuPal(gMapAnimSt.actor[actor_num].mu, OBJPAL_MANIM_SPECIALMU + actor_num);
        SetMuSpecialSprite(gMapAnimSt.actor[actor_num].mu, JID_DIVINEDRAGON, Pal_ManimDivineDragonMu);
        break;

    }
}

void sub_80620D8(ProcPtr proc)
{
    switch (gMapAnimSt.actor_count)
    {

    case 2:
        sub_8062018(1);
        // fallthrough

    case 1:
        sub_8062018(0);
        // fallthrough

    }
}

void sub_806210C(void)
{
    PlaySe(SONG_A0);
}

void MA_InitActor(int actor_num, struct BattleUnit* bu, struct Unit* unit)
{
    if (bu == NULL)
        return;

    gMapAnimSt.actor[actor_num].unit = unit;
    gMapAnimSt.actor[actor_num].bu = bu;
    gMapAnimSt.actor[actor_num].mu = StartMu(unit);

    FreezeSpriteAnim(gMapAnimSt.actor[actor_num].mu->sprite_anim);

    if (bu->terrain == TERRAIN_WALL_1B)
        HideMu(gMapAnimSt.actor[actor_num].mu);
}

/*

*/
