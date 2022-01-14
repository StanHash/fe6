#include "common.h"

#include "hardware.h"
#include "sound.h"
#include "text.h"
#include "event.h"
#include "util.h"
#include "item.h"
#include "unit.h"
#include "unitsprite.h"
#include "battle.h"
#include "faction.h"
#include "mu.h"

#include "constants/items.h"
#include "constants/jids.h"
#include "constants/video-global.h"
#include "constants/songs.h"
#include "constants/terrains.h"

enum
{
    MANIM_FACING_OPPONENT,
    MANIM_FACING_DEFAULT,
    MANIM_FACING_UNKNOWN,
};

struct MAnimExpBarProc
{
    /* 00 */ PROC_HEADER;

    /* 29 */ u8 pad_29[0x64 - 0x29];
    /* 64 */ short exp_from;
    /* 66 */ short exp_to;
    /* 68 */ short actor_num;
    /* 6A */ short unk_6A;
};

struct MAnimInfoWindowProc
{
    /* 00 */ PROC_HEADER;

    /* 2A */ u16 unk_2A;
    /* 2C */ u16 unk_2C;
    /* 2E */ u8 unk_2E;
    /* 2F */ u8 unk_2F;
    /* 30 */ ProcPtr main_proc;
};

void func_fe6_08061838(ProcPtr proc)
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

void func_fe6_08061878(ProcPtr proc)
{
    struct BattleUnit* bu = NULL;

    if (func_fe6_080618D4(&gBattleUnitA))
        bu = &gBattleUnitA;

    if (func_fe6_080618D4(&gBattleUnitB))
        bu = &gBattleUnitB;

    if (bu != NULL)
    {
        StartWeaponBrokePopup(bu->weapon_before, proc);
    }
}

bool func_fe6_080618D4(struct BattleUnit* bu)
{
    if (UNIT_FACTION(&bu->unit) == FACTION_BLUE)
        return DidBattleUnitBreakWeapon(bu);

    return FALSE;
}

void func_fe6_08061908(ProcPtr proc)
{
    struct BattleUnit* bu = NULL;

    if (func_fe6_08061964(&gBattleUnitA))
        bu = &gBattleUnitA;

    if (func_fe6_08061964(&gBattleUnitB))
        bu = &gBattleUnitB;

    if (bu != NULL)
    {
        StartWeaponLevelGainedPopup(bu->weapon_kind, proc);
    }
}

bool func_fe6_08061964(struct BattleUnit* bu)
{
    if (UNIT_FACTION(&bu->unit) == FACTION_BLUE)
        if (HasBattleUnitGainedWeaponLevel(bu))
            return TRUE;

    return FALSE;
}

void func_fe6_0806199C(ProcPtr proc)
{
    ResetText();
}

void func_fe6_080619B0(ProcPtr proc)
{
    ResetMuAnims();
    ResetTextFont();
    func_fe6_08062CF0();
    InitBmBgLayers();
    LoadUiFrameGraphics();
    ApplySystemObjectsGraphics();

    if (IsEventRunning())
        EndAllMus();
}

void func_fe6_080619E8(void)
{
    gMapAnimSt.attacker_actor = !!(gMapAnimSt.hit_it->info & BATTLE_HIT_INFO_RETALIATION);
    gMapAnimSt.defender_actor = 1 - gMapAnimSt.attacker_actor;

    gMapAnimSt.hit_attributes = gMapAnimSt.hit_it->attributes;
    gMapAnimSt.hit_info = gMapAnimSt.hit_it->info;
    gMapAnimSt.hit_damage = gMapAnimSt.hit_it->damage;

    if (gMapAnimSt.main_actor_count == 1)
    {
        gMapAnimSt.attacker_actor = 0;
        gMapAnimSt.defender_actor = 0;
    }

    gMapAnimSt.hit_it++;
}

void func_fe6_08061AC8(ProcPtr proc)
{
    if (gMapAnimSt.hit_it->info & BATTLE_HIT_INFO_END)
    {
        Proc_Break(proc);
        Proc_GotoScript(proc, ProcScr_Unk_08664E4C);

        return;
    }

    func_fe6_080619E8();

    Proc_Break(proc);
}

void func_fe6_08061B10(ProcPtr proc)
{
    SpawnProcLocking(func_fe6_08068A48(), proc);
}

void func_fe6_08061B30(ProcPtr proc)
{
    if (gMapAnimSt.hit_attributes & BATTLE_HIT_ATTR_POISON)
    {
        func_fe6_08064B7C(gMapAnimSt.actor[gMapAnimSt.defender_actor].unit);
        StartTemporaryLock(proc, 100);
    }
}

void MA_MoveCameraOntoActor(ProcPtr proc)
{
    CameraMoveWatchPosition(proc, gMapAnimSt.actor[0].unit->x, gMapAnimSt.actor[0].unit->y);
}

void MA_MoveCamOntoTarget(ProcPtr proc)
{
    if (gMapAnimSt.main_actor_count == 1)
        return;

    CameraMoveWatchPosition(proc, gMapAnimSt.actor[1].unit->x, gMapAnimSt.actor[1].unit->y);
}

void MA_DisplayDeathQuote(ProcPtr proc)
{
    int actor_num = -1;

    switch (gMapAnimSt.main_actor_count)
    {

    case 2:
        if (gMapAnimSt.actor[1].hp_cur == 0)
            actor_num = 1;

        // fallthrough

    case 1:
        if (gMapAnimSt.actor[0].hp_cur == 0)
            actor_num = 0;

        break;

    }

    if (actor_num != -1)
    {
        int pid = gMapAnimSt.actor[actor_num].unit->pinfo->id;

        if (ShouldDisplayDeathQuote(pid))
        {
            func_fe6_08062CF0();
            func_fe6_0806B808(pid);
            DisableEventSkip();
        }
    }
}

void MapAnimProc_DisplayDeathFade(ProcPtr proc)
{
    int actor_num = -1;

    switch (gMapAnimSt.main_actor_count)
    {

    case 2:
        if (gMapAnimSt.actor[1].hp_cur == 0)
            actor_num = 1;

        // fallthrough

    case 1:
        if (gMapAnimSt.actor[0].hp_cur == 0)
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

    switch (gMapAnimSt.main_actor_count)
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

void func_fe6_08061E14(ProcPtr proc)
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

    if (func_fe6_0805F7B4(gMapAnimSt.actor[0].bu->weapon_before) == 0)
        return;

    if (gMapAnimSt.main_actor_count == 1)
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

        for (i = 0; i < gMapAnimSt.main_actor_count; ++i)
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

void func_fe6_08061FD0(ProcPtr proc)
{
    switch (gMapAnimSt.main_actor_count)
    {

    case 2:
        func_fe6_0806B754(
            gMapAnimSt.actor[0].unit->pinfo->id,
            gMapAnimSt.actor[1].unit->pinfo->id);

        break;

    default:
        break;

    }

    DisableEventSkip();
}

void func_fe6_08062018(int actor_num)
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

void func_fe6_080620D8(ProcPtr proc)
{
    switch (gMapAnimSt.main_actor_count)
    {

    case 2:
        func_fe6_08062018(1);
        // fallthrough

    case 1:
        func_fe6_08062018(0);
        // fallthrough

    }
}

void func_fe6_0806210C(void)
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

void MA_SetActorFacing(int actor_num, int opponent_actor_num, int manim_facing)
{
    int mu_facing;

    switch (manim_facing)
    {

    case MANIM_FACING_OPPONENT:
        mu_facing = func_fe6_080629FC(
            gMapAnimSt.actor[actor_num].unit->x, gMapAnimSt.actor[actor_num].unit->y,
            gMapAnimSt.actor[opponent_actor_num].unit->x, gMapAnimSt.actor[opponent_actor_num].unit->y);

        SetMuFacing(gMapAnimSt.actor[actor_num].mu, mu_facing);
        break;

    case MANIM_FACING_DEFAULT:
        SetMuDefaultFacing(gMapAnimSt.actor[actor_num].mu);
        break;

    case MANIM_FACING_UNKNOWN:
        mu_facing = func_fe6_080629FC(
            gMapAnimSt.actor[actor_num].unit->x, gMapAnimSt.actor[actor_num].unit->y, 0, 0);

        SetMuFacing(gMapAnimSt.actor[actor_num].mu, mu_facing);
        // break;

    }
}

void func_fe6_080622FC(void)
{
    int manim_facing = GetItemMaFacing(gMapAnimSt.actor[0].bu->weapon_before);

    MA_SortMuLayers();

    switch (gMapAnimSt.main_actor_count)
    {

    case 2:
        if (gBattleHits[0].attributes & BATTLE_HIT_ATTR_TATTACK)
        {
            // In triangle attacks, both partners face the opponent too
            MA_SetActorFacing(2, 1, manim_facing);
            MA_SetActorFacing(3, 1, manim_facing);
        }

        MA_SetActorFacing(1, 0, manim_facing);

        // fallthrough

    case 1:
        MA_SetActorFacing(0, 1, manim_facing);
        break;

    }
}

void MA_SortMuLayers(void)
{
    u8 array[4];
    u8 tmp;
    int i, j;
    int swap_requests;

    int actor_count = gMapAnimSt.main_actor_count;

    switch (gMapAnimSt.main_actor_count)
    {

    case 2:
        if (gBattleHits[0].attributes & BATTLE_HIT_ATTR_TATTACK)
        {
            actor_count += 2;
        }

        break;

    case 1:
        break;

    }

    // initialize index array

    for (i = 0; i < actor_count; ++i)
        array[i] = i;

    // sort index array
    // it uses selection sort

    for (i = 0; i < actor_count - 1; ++i)
    {
        for (j = i + 1; j < actor_count; ++j)
        {
            swap_requests = 0;

            if (gMapAnimSt.actor[array[i]].unit->y == gMapAnimSt.actor[array[j]].unit->y)
            {
                if (gMapAnimSt.actor[array[i]].unit->x >= gMapAnimSt.actor[array[j]].unit->x)
                    swap_requests++;
            }
            else if (gMapAnimSt.actor[array[i]].unit->y >= gMapAnimSt.actor[array[j]].unit->y)
            {
                swap_requests++;
            }

            if (swap_requests != 0)
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }

    // apply

    for (i = 0; i < actor_count; ++i)
        gMapAnimSt.actor[array[i]].mu->sprite_anim->layer = gManimMuSpriteLayerLut[i];
}

void func_fe6_08062598(void)
{
    gBattleUnitA.weapon_before = IID_VULNERARY;

    gMapAnimSt.unk_62 = 0;
    gMapAnimSt.main_actor_count = 1;

    gMapAnimSt.hit_it = gBattleHits;
    func_fe6_080619E8();

    func_fe6_08062890(&gBattleUnitA, &gBattleUnitB, gBattleHits);
    SpawnProc(ProcScr_Unk_08664C0C, PROC_TREE_3);
}

void func_fe6_08062614(void)
{
    gBattleUnitA.weapon_before = IID_VULNERARY;

    gMapAnimSt.unk_62 = 0;
    gMapAnimSt.main_actor_count = 1;

    gMapAnimSt.hit_it = gBattleHits;
    func_fe6_080619E8();

    func_fe6_08062890(&gBattleUnitA, &gBattleUnitB, gBattleHits);
    SpawnProc(ProcScr_Unk_08664C4C, PROC_TREE_3);
}

void func_fe6_08062690(void)
{
    gBattleUnitA.weapon_before = IID_IRONSWORD;

    gMapAnimSt.unk_62 = 1;
    gMapAnimSt.main_actor_count = 2;

    gMapAnimSt.attacker_actor = 0;
    gMapAnimSt.defender_actor = 1;

    func_fe6_08062890(&gBattleUnitA, &gBattleUnitB, gBattleHits);
    SpawnProc(ProcScr_Unk_08664C8C, PROC_TREE_3);
}

void func_fe6_08062734(void)
{
    gBattleUnitA.weapon_before = IID_FORTIFYSTAFF;

    gMapAnimSt.unk_62 = 2;
    gMapAnimSt.main_actor_count = 1;

    gMapAnimSt.attacker_actor = 0;
    gMapAnimSt.defender_actor = 0;

    func_fe6_08062890(&gBattleUnitA, &gBattleUnitB, gBattleHits);
    SpawnProc(ProcScr_Unk_08664D5C, PROC_TREE_3);
}

void func_fe6_080627D0(void)
{
    if (gBattleSt.flags & BATTLE_FLAG_REFRESH)
    {
        func_fe6_08062734();
        return;
    }

    gMapAnimSt.unk_62 = 0;

    func_fe6_0806283C(&gBattleUnitA, &gBattleUnitB, gBattleHits);

    func_fe6_08062890(&gBattleUnitA, &gBattleUnitB, gBattleHits);
    SpawnProc(ProcScr_Unk_08664DA4, PROC_TREE_3);
}

void func_fe6_0806283C(struct BattleUnit* bu_a, struct BattleUnit* bu_b, struct BattleHit* battle_hits)
{
    gMapAnimSt.main_actor_count = func_fe6_0805F784(bu_a->weapon_before);
    gMapAnimSt.hit_it = battle_hits;
    gMapAnimSt.special_proc_scr = func_fe6_0805F7A4(bu_a->weapon_before);
}

void func_fe6_08062890(struct BattleUnit* bu_a, struct BattleUnit* bu_b, struct BattleHit* battle_hits)
{
    int i;

    MA_InitActor(0, bu_a, &bu_a->unit);

    if (gMapAnimSt.main_actor_count > 1)
    {
        HideUnitSprite(&gBattleUnitB.unit);
        MA_InitActor(1, bu_b, &bu_b->unit);
    }

    if (gBattleHits->attributes & BATTLE_HIT_ATTR_TATTACK)
    {
        MA_InitActor(2, bu_a, gBattleSt.ta_unit_a);
        MA_InitActor(3, bu_a, gBattleSt.ta_unit_b);

        HideUnitSprite(gBattleSt.ta_unit_a);
        HideUnitSprite(gBattleSt.ta_unit_b);
    }

    func_fe6_080622FC();

    for (i = 0; i < gMapAnimSt.main_actor_count; ++i)
    {
        gMapAnimSt.actor[i].hp_cur = gMapAnimSt.actor[i].bu->previous_hp;
        gMapAnimSt.actor[i].hp_max = GetUnitMaxHp(gMapAnimSt.actor[i].unit);
    }

    SetBlendNone();
}

int func_fe6_080629FC(int x_from, int y_from, int x_to, int y_to)
{
    if (ABS(x_to - x_from) * 2 < ABS(y_to - y_from))
    {
        if (y_from < y_to)
            return FACING_DOWN;
        else
            return FACING_UP;
    }
    else
    {
        if (x_from < x_to)
            return FACING_RIGHT;
        else
            return FACING_LEFT;
    }
}

void func_fe6_08062A80(int chr)
{
    Decompress(Img_Unk_082DC618, (u8*) VRAM + GetBgChrOffset(0) + ((chr & 0x3FF) << 5));
}

void func_fe6_08062AB4(u16* tm, int num, int tileref, int len, u16 blank_tileref)
{
    char buf[8];
    int i, j;

    for (i = sizeof(buf)-1; i >= 0; --i)
    {
        buf[i] = '0' + num % 10;
        num = num / 10;

        if (num == 0)
        {
            for (j = i - 1; j >= 0; --j)
                buf[j] = ' ';

            break;
        }
    }

    func_fe6_08013E8C(tm, buf + sizeof(buf) - 1, tileref, len);

    for (i = len - 1; i > 0; --i)
    {
        if (buf[sizeof(buf) - 1 - i] != ' ')
            return;

        *(tm - i) = blank_tileref;
    }
}

void func_fe6_08062BA0(u8 const* src)
{
    func_fe6_08062A80(0x20);
    Decompress(src, (void*) (VRAM + CHR_SIZE * 42)); // TODO: CHR constant
    ApplyPalette(Pal_Unk_082E278C, 5);
}

void func_fe6_08062BD4(u16* tm, int* arg_1, int pal, int arg_3, int chr)
{
    int tmp;

    if (*arg_1 > arg_3)
        tmp = arg_3;
    else
        tmp = *arg_1;

    *tm = TILEREF(chr + tmp, pal);
    *arg_1 += 1 - arg_3;

    if (*arg_1 < 0)
        *arg_1 = 0;
}

void func_fe6_08062C38(u16* tm, int arg_1, int arg_2, int arg_3, u16* arg_4)
{
    int unk, count = 0;
    u16* it;

    for (it = arg_4; it[0]; it += 2)
        count -= 1 - it[0];

    count += 1;

    if (arg_1 == arg_2)
        unk = count;
    else
        unk = ((count << 8) / arg_1 * arg_2) >> 8;

    if (unk == 0 && arg_2 > 0)
        unk++;

    for (it = arg_4; it[0]; ++tm, it += 2)
        func_fe6_08062BD4(tm, &unk, gUnk_08664F00[arg_3], it[0], it[1]);
}

void func_fe6_08062CF0(void)
{
    Proc_EndEach(ProcScr_MAnimInfoWindow);
}

void MA_StartBattleInfoBox(int arg0, int arg1, ProcPtr main_proc)
{
    struct MAnimInfoWindowProc* proc = SpawnProc(ProcScr_MAnimInfoWindow, PROC_TREE_3);

    proc->unk_2E = arg0;
    proc->unk_2F = arg1;
    proc->main_proc = main_proc;
}

void func_fe6_08062D64(struct MAnimInfoWindowProc* proc)
{
    SetOnHBlankA(NULL);
    ClearBg0Bg1();
}

/*

*/
