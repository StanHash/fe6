#include "common.h"

#include "random.h"
#include "ramfunc.h"
#include "hardware.h"
#include "move.h"
#include "oam.h"
#include "armfunc.h"
#include "sprite.h"
#include "sound.h"
#include "text.h"
#include "event.h"
#include "msg.h"
#include "util.h"
#include "item.h"
#include "unit.h"
#include "debugmenu.h"
#include "faction.h"
#include "unitsprite.h"
#include "battle.h"
#include "bmio.h"
#include "action.h"
#include "ui.h"
#include "mu.h"
#include "eventinfo.h"
#include "systemlabels.h"

#include "constants/iids.h"
#include "constants/pids.h"
#include "constants/jids.h"
#include "constants/videoalloc_global.h"
#include "constants/songs.h"
#include "constants/terrains.h"

struct MapAnimSt EWRAM_DATA gMapAnimSt = { { 0 } };

u16 EWRAM_DATA gUnk_0203CE48[DISPLAY_HEIGHT * 2] = { 0 };
u16 EWRAM_DATA gUnk_0203D0C8[DISPLAY_HEIGHT * 2] = { 0 };
u16 * EWRAM_DATA gUnk_0203D348[2] = { 0 };
u16 * EWRAM_DATA gUnk_0203D350 = NULL;

// GARBAGE START
// TODO: organize

extern u16 const gUnk_082DC840[]; // pal blue
extern u16 const gUnk_082DC860[]; // pal red
extern u16 const gUnk_082DC880[]; // pal green
extern u16 const gUnk_082DC8A0[]; // pal purple
extern u8 const gUnk_082DC8C0[]; // tsa
extern u8 const gUnk_082DC8EC[]; // tsa
extern u8 const gUnk_082DC918[]; // tsa
extern u8 const gUnk_08113584[]; // img exp bar a
extern u8 const gUnk_08113884[]; // img exp bar b
extern u8 const gUnk_08113B84[]; // img exp bar c
extern u16 const gUnk_08113D50[]; // pal exp bar
extern u8 const gUnk_082DC5B0[]; // tsa exp bar
extern u8 const gUnk_082DCAE4[]; // img
extern u16 const gUnk_082DCD70[]; // pal
extern u16 const gUnk_082A9228[]; // sprite anim
extern u8 const gUnk_082DB1C0[]; // img
extern u16 const gUnk_082DB2B0[]; // sprite anim
extern u8 const gUnk_082DB418[]; // img
extern u16 const gUnk_082DB55C[]; // sprite anim
extern u8 const gUnk_082DCEF4[]; // img
extern u16 const gUnk_082DD248[]; // pal
extern u16 const gUnk_082A9190[]; // sprite anim
extern u8 const gUnk_082DE994[]; // img
extern u16 const gUnk_082DEFBC[]; // pal/colors
extern u8 const gUnk_082DEFFC[]; // img
extern u16 const gUnk_082DE354[]; // tm
extern u8 const gUnk_082DD268[]; // img
extern u16 const gUnk_082DD4C8[]; // pal
extern u16 const gUnk_082DD4E8[]; // tm
extern u8 const gUnk_082DF3D8[]; // img
extern u16 const gUnk_082DF690[]; // pal
extern u16 const gUnk_082A8448[]; // sprite anim
extern u8 const gUnk_082E0E14[]; // img
extern u16 const gUnk_082E10EC[]; // pal
extern u16 const gUnk_082E110C[]; // sprite anim
extern u8 const gUnk_082DFAD4[]; // img
extern u16 const gUnk_081B4274[]; // pal
extern u8 const gUnk_082E07A8[]; // ???
extern u8 const gUnk_082DF868[]; // ??? ^
extern u8 const gUnk_08307928[]; // ???
extern u8 const gUnk_081B7468[]; // img
extern u16 const gUnk_081B7650[]; // pal
extern u16 const gUnk_082E0A14[]; // sprite anim
extern u8 const gUnk_082E161C[]; // img
extern u8 const gUnk_082E11DC[]; // img
extern u16 const gUnk_082E172C[]; // pal
extern u16 const gUnk_082E174C[]; // sprite anim
extern u8 const gUnk_082E1884[]; // img
extern u16 const gUnk_081B8934[]; // pal
extern u8 const gUnk_082E2440[]; // ???
extern u8 const gUnk_082DF724[]; // img
extern u8 const gUnk_082DF844[]; // ???
extern u8 const gUnk_082DF6B0[]; // img
extern u16 const gUnk_082DF704[]; // pal
extern u16 const gUnk_082DF824[]; // colors
extern u16 const gUnk_082A84A4[]; // sprite anim
extern u8 const gUnk_08114D80[]; // img (stat gains)
extern u8 const gUnk_08114FCC[]; // tiles (stat gains)
extern u16 const gUnk_081150C8[]; // pal (stat gains)
extern u8 const gUnk_082DBB24[]; // img
extern u16 const gUnk_082DBAC4[]; // pal
extern u8 const gUnk_082DBDB0[]; // img (raw)
extern u16 const gUnk_082A75FC[]; // sprite anim
extern u16 const gUnk_082DB6E8[]; // colors
extern u8 const gUnk_082DB8B0[]; // img
extern u16 const gUnk_082A7CBC[]; // sprite anim
extern u8 const gUnk_082DD7E8[]; // img
extern u16 const gUnk_082DD808[]; // pal
extern u8 const gUnk_082DD848[]; // img
extern u16 const gUnk_082DE974[]; // ^ pal
extern u16 const gUnk_082DE954[]; // ^ pal

struct UnkSt_030046D0
{
    /* 00 */ u16 unk_00;
    /* 02 */ u16 unk_02;
    /* 04 */ STRUCT_PAD(0x04, 0x08);
};

extern struct UnkSt_030046D0 gUnk_030046D0[];

extern u16 gUnk_03004750[]; // map palette save

enum { MAX_MANIM_DEBUG_HITS = 5 };

enum
{
    MANIM_DEBUG_PARAM_PID,
    MANIM_DEBUG_PARAM_X,
    MANIM_DEBUG_PARAM_Y,
    MANIM_DEBUG_PARAM_JID,
    MANIM_DEBUG_PARAM_IID,
    MANIM_DEBUG_PARAM_HITS,
    MAX_MANIM_DEBUG_PARAM = MANIM_DEBUG_PARAM_HITS + MAX_MANIM_DEBUG_HITS,
};

enum
{
    MANIM_DEBUG_HIT_KIND_NONE,
    MANIM_DEBUG_HIT_KIND_REGULAR,
    MANIM_DEBUG_HIT_KIND_REGULAR_DEVIL,
    MANIM_DEBUG_HIT_KIND_REGULAR_HPSTEAL,
    MANIM_DEBUG_HIT_KIND_REGULAR_POISON,
    MANIM_DEBUG_HIT_KIND_CRIT,
    MANIM_DEBUG_HIT_KIND_CRIT_DEVIL,
    MANIM_DEBUG_HIT_KIND_CRIT_HPSTEAL,
    MANIM_DEBUG_HIT_KIND_CRIT_POISON,
    MANIM_DEBUG_HIT_KIND_MISS,

    MAX_MANIM_DEBUG_HIT_KIND,
};

struct ManimDebugStEnt
{
    /* 00 */ short data[MAX_MANIM_DEBUG_PARAM];
    /* 14 */ struct Text text[MAX_MANIM_DEBUG_PARAM];
};

struct ManimDebugSt
{
    /* 00 */ u8 unk_00[8]; // unused?
    /* 08 */ struct ManimDebugStEnt ent[2];
};

struct ManimDebugParamInfo
{
    /* 00 */ u8 text_width;
    /* 01 */ i8 param_up;
    /* 02 */ i8 param_down;
    /* 03 */ i8 param_left;
    /* 04 */ i8 param_right;
    /* 05 */ u8 min;
    /* 06 */ u8 max;
};

struct ManimEffectProc
{
    /* 00 */ PROC_HEADER;
    /* 2C */ struct Unit * unit;
    /* 30 */ int x, y;
    /* 38 */ u8 pad_38[0x40 - 0x38];
    /* 40 */ u16 unk_40;
    /* 42 */ u16 unk_42;
    /* 44 */ u16 unk_44;
    /* 44 */ u8 pad_46[0x48 - 0x46];
    /* 48 */ short unk_48;
    /* 4A */ short unk_4A;
    /* 4C */ short unk_4C;
    /* 4E */ /* pad */
    /* 50 */ void const * img;
    /* 54 */ void const * pal;
    /* 58 */ u16 unk_58;
    /* 5A */ u8 pad_5A[0x64 - 0x5A];
    /* 64 */ short unk_64;
};

extern struct ProcScr CONST_DATA ProcScr_Unk_0866510C[];
extern struct ProcScr CONST_DATA ProcScr_Unk_0866512C[];
extern struct ProcScr CONST_DATA ProcScr_Unk_0866514C[];
extern struct ProcScr CONST_DATA ProcScr_Unk_08665194[];
extern struct ProcScr CONST_DATA ProcScr_Unk_086660FC[];

#define SCREEN_TILE_X(x_param) (((x_param) - (gBmSt.camera.x >> 4)) << 1)
#define SCREEN_TILE_Y(y_param) (((y_param) - (gBmSt.camera.y >> 4)) << 1)

void func_fe6_08063CF4(struct GenericProc * proc);
void func_fe6_08063EF0(struct GenericProc * proc);
void func_fe6_080640D0(struct GenericProc * proc);
void func_fe6_0806495C(struct GenericProc * proc);

void func_fe6_08064B20(struct ManimEffectProc * proc);
void func_fe6_08064BEC(struct ManimEffectProc * proc);
void func_fe6_08064CC0(struct ManimEffectProc * proc);
void func_fe6_08064DF8(struct ManimEffectProc * proc);
void func_fe6_08064F4C(struct ManimEffectProc * proc);
void func_fe6_08064FD0(struct ManimEffectProc * proc);
void func_fe6_08065AF8(ProcPtr proc);

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
    /* 68 */ short actor_id;
    /* 6A */ short unk_6A;
};

struct MAnimInfoWindowProc
{
    /* 00 */ PROC_HEADER;

    /* 2A */ i16 open_transition_value;
    /* 2C */ u16 unk_2C;
    /* 2E */ u8 x_tile;
    /* 2F */ u8 y_tile;
    /* 30 */ ProcPtr main_proc;
};

void func_fe6_08062D64(ProcPtr proc);
void func_fe6_08062D80(struct MAnimInfoWindowProc * proc);
void func_fe6_08062E94(struct MAnimInfoWindowProc * proc);
void func_fe6_08062FE8(struct MAnimInfoWindowProc * proc, int actor_id);
void func_fe6_08063120(struct MAnimInfoWindowProc * proc, int actor_id, int x_offset);
void func_fe6_080632C4(struct MAnimInfoWindowProc * proc);
void func_fe6_080633B0(struct MAnimInfoWindowProc * proc);
void func_fe6_08063504(struct MAnimExpBarProc * proc);
void func_fe6_080635B8(struct MAnimExpBarProc * proc);
void func_fe6_080635E0(struct MAnimExpBarProc * proc);
void func_fe6_0806367C(struct MAnimExpBarProc * proc);
void func_fe6_0806376C(struct MAnimExpBarProc * proc);
void func_fe6_08063848(struct MAnimExpBarProc * proc);

// GARBAGE END

struct ProcScr CONST_DATA ProcScr_Unk_08664C0C[] =
{
    PROC_CALL(LockGame),
    PROC_CALL(MA_MoveCameraOntoActor),
    PROC_SLEEP(2),
    PROC_CALL(func_fe6_08061E14),
    PROC_SLEEP(15),
    PROC_START_CHILD_LOCKING((void *) 0x08665F04), // TODO
    PROC_SLEEP(1),
    PROC_GOTO_SCR(ProcScr_Unk_08664E4C),
};

struct ProcScr CONST_DATA ProcScr_Unk_08664C4C[] =
{
    PROC_CALL(LockGame),
    PROC_CALL(MA_MoveCameraOntoActor),
    PROC_SLEEP(2),
    PROC_CALL(func_fe6_08061E14),
    PROC_SLEEP(15),
    PROC_START_CHILD_LOCKING((void *) 0x08665F54), // TODO
    PROC_SLEEP(1),
    PROC_GOTO_SCR(ProcScr_Unk_08664E4C),
};

struct ProcScr CONST_DATA ProcScr_Unk_08664C8C[] =
{
    PROC_CALL(LockGame),
    PROC_CALL(MA_MoveCamOntoTarget),
    PROC_SLEEP(2),
    PROC_CALL(MA_MoveCameraOntoActor),
    PROC_SLEEP(2),
    PROC_SLEEP(20),
    PROC_CALL(func_fe6_08068C84),
    PROC_CALL(func_fe6_08068E80),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08068E80),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08068E80),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08068E80),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_0806210C),
    PROC_SLEEP(20),
    PROC_CALL(func_fe6_08068F04),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08068F04),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08068F04),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08068F04),
    PROC_SLEEP(20),
    PROC_GOTO_SCR(ProcScr_Unk_08664E4C),
};

struct ProcScr CONST_DATA ProcScr_Unk_08664D5C[] =
{
    PROC_CALL(LockGame),
    PROC_CALL(MA_MoveCameraOntoActor),
    PROC_SLEEP(2),
    PROC_SLEEP(20),
    PROC_CALL(func_fe6_08068ADC),
    PROC_SLEEP(90),
    PROC_CALL(func_fe6_08068C28),
    PROC_SLEEP(20),
    PROC_GOTO_SCR(ProcScr_Unk_08664E4C),
};

struct ProcScr CONST_DATA ProcScr_Unk_08664DA4[] =
{
    PROC_CALL(LockGame),
    PROC_CALL(func_fe6_0806199C),
    PROC_SLEEP(1),
    PROC_CALL(MA_MoveCameraOntoActor),
    PROC_SLEEP(2),
    PROC_CALL(func_fe6_08061FD0),
    PROC_WHILE(IsEventRunning),
    PROC_SLEEP(5),
    PROC_CALL(func_fe6_080620D8),
    PROC_CALL(func_fe6_080622FC),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08061E14),
    PROC_SLEEP(15),
PROC_LABEL(0),
    PROC_REPEAT(func_fe6_08061AC8),
    PROC_CALL(func_fe6_08061B10),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08061B30),
    PROC_SLEEP(1),
    PROC_SLEEP(5),
    PROC_GOTO(0),
};

struct ProcScr CONST_DATA ProcScr_Unk_08664E4C[] =
{
    PROC_CALL(MA_DisplayDeathQuote),
    PROC_WHILE(IsEventRunning),
    PROC_CALL(MapAnimProc_DisplayDeathFade),
    PROC_WHILE_EXISTS(ProcScr_MuDeathFade),
    PROC_CALL(func_fe6_08062CF0),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08061838),
    PROC_SLEEP(0),
    PROC_CALL(MapAnimProc_DisplayExpBar),
    PROC_SLEEP(0),
    PROC_CALL(func_fe6_08061878),
    PROC_SLEEP(8),
    PROC_CALL(func_fe6_08061908),
    PROC_SLEEP(0),
    PROC_CALL(MA_MoveCameraOntoActor),
    PROC_SLEEP(2),
    PROC_CALL(UnlockGame),
    PROC_CALL(func_fe6_080619B0),
    PROC_END,
};

u16 CONST_DATA gUnk_08664EE4[] =
{
    4, 42,
    9, 47,
    9, 57,
    9, 67,
    9, 77,
    5, 87,
    0, 0,
};

int CONST_DATA gUnk_08664F00[] = { 5, 6 };

u8 const * CONST_DATA gUnk_08664F08[][2] = // tsa lut
{
    { gUnk_082DC8C0, gUnk_082DC8C0 },
    { gUnk_082DC8C0, gUnk_082DC8C0 },
    { gUnk_082DC8EC, gUnk_082DC918 },
};

struct ProcScr CONST_DATA ProcScr_MAnimInfoWindow[] =
{
    PROC_ONEND(func_fe6_08062D64),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_080632C4),
    PROC_CALL(func_fe6_08062D80),
    PROC_REPEAT(func_fe6_080633B0),
    PROC_REPEAT(func_fe6_08062E94),
    PROC_END,
};

u16 CONST_DATA gUnk_08664F58[] =
{
    6, BGCHR_MANIM_200 + 7,
    9, BGCHR_MANIM_200 + 14,
    9, BGCHR_MANIM_200 + 14,
    9, BGCHR_MANIM_200 + 14,
    9, BGCHR_MANIM_200 + 14,
    9, BGCHR_MANIM_200 + 14,
    9, BGCHR_MANIM_200 + 14,
    9, BGCHR_MANIM_200 + 14,
    9, BGCHR_MANIM_200 + 14,
    9, BGCHR_MANIM_200 + 14,
    9, BGCHR_MANIM_200 + 14,
    9, BGCHR_MANIM_200 + 14,
    6, BGCHR_MANIM_200 + 24,
    0, // end
};

struct ProcScr CONST_DATA ProcScr_MAnimExpBar[] =
{
    PROC_ONEND(func_fe6_08062D64),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08063504),
    PROC_CALL(func_fe6_0806367C),
    PROC_REPEAT(func_fe6_0806376C),
    PROC_SLEEP(20),
    PROC_CALL(func_fe6_080635B8),
    PROC_SLEEP(2),
    PROC_REPEAT(func_fe6_080635E0),
    PROC_SLEEP(20),
    PROC_CALL(func_fe6_08062D64),
    PROC_SLEEP(8),
    PROC_CALL(func_fe6_08063848),
    PROC_SLEEP(1),
    PROC_END,
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
    struct BattleUnit * bu = NULL;

    if (func_fe6_080618D4(&gBattleUnitA))
        bu = &gBattleUnitA;

    if (func_fe6_080618D4(&gBattleUnitB))
        bu = &gBattleUnitB;

    if (bu != NULL)
    {
        StartWeaponBrokePopup(bu->weapon_before, proc);
    }
}

bool func_fe6_080618D4(struct BattleUnit * bu)
{
    if (UNIT_FACTION(&bu->unit) == FACTION_BLUE)
        return DidBattleUnitBreakWeapon(bu);

    return FALSE;
}

void func_fe6_08061908(ProcPtr proc)
{
    struct BattleUnit * bu = NULL;

    if (func_fe6_08061964(&gBattleUnitA))
        bu = &gBattleUnitA;

    if (func_fe6_08061964(&gBattleUnitB))
        bu = &gBattleUnitB;

    if (bu != NULL)
    {
        StartWeaponLevelGainedPopup(bu->weapon_kind, proc);
    }
}

bool func_fe6_08061964(struct BattleUnit * bu)
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
    UnpackUiWindowFrameGraphics();
    ApplySystemObjectsGraphics();

    if (IsEventRunning())
        EndAllMus();
}

void func_fe6_080619E8(void)
{
    gMapAnimSt.attacker_actor = !!(gMapAnimSt.hit_it->info & BATTLE_HIT_INFO_ACTORB);
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
    int actor_id = -1;

    switch (gMapAnimSt.main_actor_count)
    {

    case 2:
        if (gMapAnimSt.actor[1].hp_cur == 0)
            actor_id = 1;

        // fallthrough

    case 1:
        if (gMapAnimSt.actor[0].hp_cur == 0)
            actor_id = 0;

        break;

    }

    if (actor_id != -1)
    {
        int pid = gMapAnimSt.actor[actor_id].unit->pinfo->id;

        if (CheckBattleDefeatTalk(pid))
        {
            func_fe6_08062CF0();
            StartBattleDefeatTalk(pid);
            DisableEventSkip();
        }
    }
}

void MapAnimProc_DisplayDeathFade(ProcPtr proc)
{
    int actor_id = -1;

    switch (gMapAnimSt.main_actor_count)
    {

    case 2:
        if (gMapAnimSt.actor[1].hp_cur == 0)
            actor_id = 1;

        // fallthrough

    case 1:
        if (gMapAnimSt.actor[0].hp_cur == 0)
            actor_id = 0;

        break;

    }

    if (actor_id != -1)
    {
        StartMuDeathFade(gMapAnimSt.actor[actor_id].mu);
    }
}

void MapAnimProc_DisplayExpBar(ProcPtr proc)
{
    struct MAnimExpBarProc * exp_bar_proc;
    int actor_id = -1;

    switch (gMapAnimSt.main_actor_count)
    {

    case 2:
        if (gMapAnimSt.actor[1].bu->exp_gain != 0)
            actor_id = 1;

        // fallthrough

    case 1:
        if (gMapAnimSt.actor[0].bu->exp_gain != 0)
            actor_id = 0;

        break;

    }

    if (actor_id >= 0)
    {
        exp_bar_proc = SpawnProcLocking(ProcScr_MAnimExpBar, proc);

        exp_bar_proc->exp_from = gMapAnimSt.actor[actor_id].bu->previous_exp;
        exp_bar_proc->exp_to = gMapAnimSt.actor[actor_id].bu->previous_exp + gMapAnimSt.actor[actor_id].bu->exp_gain;
        exp_bar_proc->actor_id = actor_id;
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
        int i, actor_id;

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
            actor_id = array[0] > array[1] ? 0 : 1;

            if (array[actor_id] >= 112)
                y = array[1 - actor_id] - 40;
            else
                y = array[actor_id] + 24;
        }
    }

    MA_StartBattleInfoBox(15, y / 8, proc);
}

void func_fe6_08061FD0(ProcPtr proc)
{
    switch (gMapAnimSt.main_actor_count)
    {

    case 2:
        StartBattleTalk(
            gMapAnimSt.actor[0].unit->pinfo->id,
            gMapAnimSt.actor[1].unit->pinfo->id);

        break;

    default:
        break;

    }

    DisableEventSkip();
}

void func_fe6_08062018(int actor_id)
{
    switch (GetItemIid(gMapAnimSt.actor[actor_id].bu->weapon_before))
    {

    case IID_FIRESTONE:
        SetMuPal(gMapAnimSt.actor[actor_id].mu, OBJPAL_MANIM_SPECIALMU + actor_id);
        SetMuSpecialSprite(gMapAnimSt.actor[actor_id].mu, JID_FIREDRAGON, Pal_ManimFireDragonMu);
        break;

    case IID_DIVINESTONE:
        SetMuPal(gMapAnimSt.actor[actor_id].mu, OBJPAL_MANIM_SPECIALMU + actor_id);
        SetMuSpecialSprite(gMapAnimSt.actor[actor_id].mu, JID_DIVINEDRAGON, Pal_ManimDivineDragonMu);
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

void MA_InitActor(int actor_id, struct BattleUnit * bu, struct Unit * unit)
{
    if (bu == NULL)
        return;

    gMapAnimSt.actor[actor_id].unit = unit;
    gMapAnimSt.actor[actor_id].bu = bu;
    gMapAnimSt.actor[actor_id].mu = StartMu(unit);

    FreezeSpriteAnim(gMapAnimSt.actor[actor_id].mu->sprite_anim);

    if (bu->terrain == TERRAIN_WALL_1B)
        HideMu(gMapAnimSt.actor[actor_id].mu);
}

void MA_SetActorFacing(int actor_id, int opponent_actor_id, int manim_facing)
{
    int mu_facing;

    switch (manim_facing)
    {

    case MANIM_FACING_OPPONENT:
        mu_facing = GetFacingFromTo(
            gMapAnimSt.actor[actor_id].unit->x, gMapAnimSt.actor[actor_id].unit->y,
            gMapAnimSt.actor[opponent_actor_id].unit->x, gMapAnimSt.actor[opponent_actor_id].unit->y);

        SetMuFacing(gMapAnimSt.actor[actor_id].mu, mu_facing);
        break;

    case MANIM_FACING_DEFAULT:
        SetMuDefaultFacing(gMapAnimSt.actor[actor_id].mu);
        break;

    case MANIM_FACING_UNKNOWN:
        mu_facing = GetFacingFromTo(
            gMapAnimSt.actor[actor_id].unit->x, gMapAnimSt.actor[actor_id].unit->y, 0, 0);

        SetMuFacing(gMapAnimSt.actor[actor_id].mu, mu_facing);
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

u8 const gManimMuSpriteLayerLut[] = { 10, 9, 8, 7 };

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

void func_fe6_0806283C(struct BattleUnit * bu_a, struct BattleUnit * bu_b, struct BattleHit * battle_hits)
{
    gMapAnimSt.main_actor_count = func_fe6_0805F784(bu_a->weapon_before);
    gMapAnimSt.hit_it = battle_hits;
    gMapAnimSt.special_proc_scr = func_fe6_0805F7A4(bu_a->weapon_before);
}

void func_fe6_08062890(struct BattleUnit * bu_a, struct BattleUnit * bu_b, struct BattleHit * battle_hits)
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

int GetFacingFromTo(int x_from, int y_from, int x_to, int y_to)
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
    Decompress(Img_Unk_082DC618, (u8 *) VRAM + GetBgChrOffset(0) + ((chr & 0x3FF) << 5));
}

void func_fe6_08062AB4(u16 * tm, int num, int tileref, int len, u16 blank_tileref)
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

void func_fe6_08062BA0(u8 const * src)
{
    func_fe6_08062A80(0x20);
    Decompress(src, (void *) (VRAM + CHR_SIZE * 42)); // TODO: CHR constant
    ApplyPalette(Pal_Unk_082E278C, 5);
}

void func_fe6_08062BD4(u16 * tm, int * arg_1, int pal, int arg_3, int chr)
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

void func_fe6_08062C38(u16 * tm, int arg_1, int arg_2, int arg_3, u16 const * arg_4)
{
    int unk, count = 0;
    u16 const * it;

    for (it = arg_4; it[0] != 0; it += 2)
        count -= 1 - it[0];

    count += 1;

    if (arg_1 == arg_2)
        unk = count;
    else
        unk = ((count << 8) / arg_1 * arg_2) >> 8;

    if (unk == 0 && arg_2 > 0)
        unk++;

    for (it = arg_4; it[0] != 0; tm++, it += 2)
        func_fe6_08062BD4(tm, &unk, gUnk_08664F00[arg_3], it[0], it[1]);
}

void func_fe6_08062CF0(void)
{
    Proc_EndEach(ProcScr_MAnimInfoWindow);
}

void MA_StartBattleInfoBox(int arg0, int arg1, ProcPtr main_proc)
{
    struct MAnimInfoWindowProc * proc = SpawnProc(ProcScr_MAnimInfoWindow, PROC_TREE_3);

    proc->x_tile = arg0;
    proc->y_tile = arg1;
    proc->main_proc = main_proc;
}

void func_fe6_08062D64(ProcPtr proc)
{
    SetOnHBlankA(NULL);
    ClearUi();
}

void func_fe6_08062D80(struct MAnimInfoWindowProc * proc)
{
    int left_actor_id;

    SetBgOffset(0, 0, 0);
    SetBgOffset(1, 0, 0);

    Decompress(
        gUnk_082DC6DC,
        ((void *) VRAM) + GetBgChrOffset(1) + BGCHR_MANIM_1 * CHR_SIZE);

    func_fe6_08062BA0(gUnk_082E25D4);

    switch (gMapAnimSt.main_actor_count)
    {

    case 1:
        func_fe6_08063120(proc, 0, -5);
        break;

    case 2:
        left_actor_id = 0;

        if (gMapAnimSt.actor[0].unit->x > gMapAnimSt.actor[1].unit->x)
            left_actor_id = 1;
        else if (UNIT_FACTION(gMapAnimSt.actor[0].unit) > UNIT_FACTION(gMapAnimSt.actor[1].unit))
            left_actor_id = 1;

        func_fe6_08063120(proc, left_actor_id, -10);
        func_fe6_08063120(proc, 1 - left_actor_id, 0);
        break;

    }

    func_fe6_08069C34();

    func_fe6_0806A0DC(
        gMapAnimSt.actor[0].unk_11 * 8,
        gMapAnimSt.actor[0].unk_11 * 8 + 0x20,
        PAL_COLOR(BGPAL_MANIM_1 + 0, 1),
        PAL_COLOR(BGPAL_MANIM_1 + 1, 1));
}

void func_fe6_08062E94(struct MAnimInfoWindowProc * proc)
{
    int i;
    u16 val;
    bool updated = FALSE;

    for (i = 0; i < gMapAnimSt.main_actor_count; ++i)
    {
        val = gMapAnimSt.actor[i].unk_0E;

        if (val > (gMapAnimSt.actor[i].hp_cur << 4))
            val = val - 16;

        if (val < (gMapAnimSt.actor[i].hp_cur << 4))
        {
            val = val + 4;

            if (val % 16 == 0)
                PlaySe(SONG_75);
        }

        if (val != gMapAnimSt.actor[i].unk_0E)
        {
            gMapAnimSt.actor[i].unk_0E = val;
            func_fe6_08062FE8(proc, i);
            updated = TRUE;
        }
    }

    if (!updated && gMapAnimSt.unk_5F)
        gMapAnimSt.unk_5F = FALSE;
}

void func_fe6_08062FE8(struct MAnimInfoWindowProc * proc, int actor_id)
{
    func_fe6_08062AB4(
        gBg0Tm + TM_OFFSET(
            gMapAnimSt.actor[actor_id].unk_10 + 2,
            gMapAnimSt.actor[actor_id].unk_11 + 2),
        gMapAnimSt.actor[actor_id].unk_0E / 16,
        TILEREF(BGCHR_MANIM_1 + 31, BGPAL_MANIM_5), 3, 0);

    func_fe6_08062C38(
        gBg0Tm + TM_OFFSET(
            gMapAnimSt.actor[actor_id].unk_10 + 3,
            gMapAnimSt.actor[actor_id].unk_11 + 2),
        gMapAnimSt.actor[actor_id].hp_max,
        gMapAnimSt.actor[actor_id].unk_0E / 16,
        0, gUnk_08664EE4);

    EnableBgSync(BG0_SYNC_BIT);
}

u16 const * func_fe6_080630C8(struct Unit * unit)
{
    switch (UNIT_FACTION(unit))
    {

    case FACTION_BLUE:
        return gUnk_082DC840;

    case FACTION_RED:
        return gUnk_082DC860;

    case FACTION_GREEN:
        return gUnk_082DC880;

    case FACTION_PURPLE:
        return gUnk_082DC8A0;

    default:
        return NULL;

    }
}

void func_fe6_08063120(struct MAnimInfoWindowProc * proc, int actor_id, int x_offset)
{
    gMapAnimSt.actor[actor_id].unk_10 = proc->x_tile + x_offset;
    gMapAnimSt.actor[actor_id].unk_11 = proc->y_tile;

    ApplyPalette(
        func_fe6_080630C8(gMapAnimSt.actor[actor_id].unit),
        BGPAL_MANIM_1 + actor_id);

    Decompress(
        gUnk_08664F08[gMapAnimSt.main_actor_count][actor_id], gBuf);

    TmApplyTsa_t(
        gBg1Tm + TM_OFFSET(
            gMapAnimSt.actor[actor_id].unk_10,
            gMapAnimSt.actor[actor_id].unk_11),
        gBuf, BGCHR_MANIM_1 | TILEREF(0, BGPAL_MANIM_1 + actor_id));

    EnableBgSync(BG1_SYNC_BIT);

    PutStringCentered(
        gBg0Tm + TM_OFFSET(
            gMapAnimSt.actor[actor_id].unk_10 + 1,
            gMapAnimSt.actor[actor_id].unk_11),
        TEXT_COLOR_SYSTEM_WHITE, 8,
        DecodeMsg(gMapAnimSt.actor[actor_id].unit->pinfo->msg_name));

    EnableBgSync(BG0_SYNC_BIT);

    gMapAnimSt.actor[actor_id].unk_0E = gMapAnimSt.actor[actor_id].hp_cur << 4;

    func_fe6_08062FE8(proc, actor_id);
}

void func_fe6_080632C4(struct MAnimInfoWindowProc * proc)
{
    proc->open_transition_value = 0;

    func_fe6_080633B0(proc);

    SetWinEnable(1, 0, 0);

    SetWin0Layers(1, 1, 1, 1, 1);
    SetWOutLayers(0, 0, 1, 1, 1);
}

void func_fe6_080633B0(struct MAnimInfoWindowProc * proc)
{
    SetWin0Box(
        0, (proc->y_tile + 2) * 8 - proc->open_transition_value,
        240, (proc->y_tile + 2) * 8 + proc->open_transition_value);

    proc->open_transition_value += 2;

    if (proc->open_transition_value > 0x10)
    {
        SetWinEnable(0, 0, 0);
        Proc_Break(proc);
    }
}

void func_fe6_08063494(int x_tm, int y_tm, int amt)
{
    func_fe6_08062AB4(
        gBg0Tm + TM_OFFSET(
            x_tm + 2,
            y_tm + 1),
        amt, TILEREF(BGCHR_MANIM_200 + 0x1F, BGPAL_MANIM_5), 2, TILEREF(BGCHR_MANIM_200 + 0x29, BGPAL_MANIM_5));

    func_fe6_08062C38(
        gBg0Tm + TM_OFFSET(
            x_tm + 3,
            y_tm + 1),
        99, amt, 0, gUnk_08664F58);

    EnableBgSync(BG0_SYNC_BIT);
}

void func_fe6_08063504(struct MAnimExpBarProc * proc)
{
    SetBgOffset(0, 0, 0);
    SetBgOffset(1, 0, 0);

    RegisterDataMove(
        gUnk_08113584,
        (void *)(VRAM) + GetBgChrOffset(0) + (BGCHR_MANIM_200 + 0x00) * CHR_SIZE,
        7 * CHR_SIZE);

    RegisterDataMove(
        gUnk_08113884,
        (void *)(VRAM) + GetBgChrOffset(0) + (BGCHR_MANIM_200 + 0x07) * CHR_SIZE,
        24 * CHR_SIZE);

    RegisterDataMove(
        gUnk_08113B84,
        (void *)(VRAM) + GetBgChrOffset(0) + (BGCHR_MANIM_200 + 0x1F) * CHR_SIZE,
        11 * CHR_SIZE);

    ApplyPalette(gUnk_08113D50, BGPAL_MANIM_5);

    TmApplyTsa_t(gBg0Tm + TM_OFFSET(6, 8), gUnk_082DC5B0, TILEREF(BGCHR_MANIM_200, BGPAL_MANIM_5));

    func_fe6_08063494(6, 8, proc->exp_from);
}

void func_fe6_080635B8(struct MAnimExpBarProc * proc)
{
    PlaySe(SONG_74);
}

void func_fe6_080635E0(struct MAnimExpBarProc * proc)
{
    proc->exp_from++;

    if (proc->exp_from >= 100)
        proc->exp_from = 0;

    func_fe6_08063494(6, 8, proc->exp_from);

    if (proc->exp_from == proc->exp_to % 100)
    {
        Proc_Break(proc);
        m4aSongNumStop(SONG_74);
    }
}

void func_fe6_0806367C(struct MAnimExpBarProc * proc)
{
    proc->unk_6A = 0;

    func_fe6_0806376C(proc);

    SetWinEnable(1, 0, 0);

    SetWin0Layers(1, 1, 1, 1, 1);
    SetWOutLayers(0, 0, 1, 1, 1);
}

void func_fe6_0806376C(struct MAnimExpBarProc * proc)
{
    SetWin0Box(
        0, 76 - proc->unk_6A,
        240, 76 + proc->unk_6A);

    proc->unk_6A += 2;

    if (proc->unk_6A > 12)
    {
        SetWinEnable(0, 0, 0);
        Proc_Break(proc);
    }
}

void func_fe6_08063848(struct MAnimExpBarProc * proc)
{
    if (proc->exp_to < 100)
        return;

    func_fe6_08067CF8(proc->actor_id, proc);
}

char const * CONST_DATA gManimDebugHitKindNameLut[] =
{
    JTEXT("ーーー"),
    JTEXT("攻撃"),
    JTEXT("攻撃デ"),
    JTEXT("攻撃リ"),
    JTEXT("攻撃毒"),
    JTEXT("必殺"),
    JTEXT("必殺デ"),
    JTEXT("必殺リ"),
    JTEXT("必殺毒"),
    JTEXT("空ぶり"),
};

struct ManimDebugParamInfo CONST_DATA gManimDebugParamInfoTable[] =
{
    [MANIM_DEBUG_PARAM_PID] =
    {
        .text_width = 9,
        .param_up = MANIM_DEBUG_PARAM_HITS + 4,
        .param_down = MANIM_DEBUG_PARAM_X,
        .param_left = MANIM_DEBUG_PARAM_PID,
        .param_right = MANIM_DEBUG_PARAM_PID,
        .min = 1, .max = MAX_PIDS,
    },

    [MANIM_DEBUG_PARAM_X] =
    {
        .text_width = 2,
        .param_up = MANIM_DEBUG_PARAM_PID,
        .param_down = MANIM_DEBUG_PARAM_JID,
        .param_left = MANIM_DEBUG_PARAM_Y,
        .param_right = MANIM_DEBUG_PARAM_Y,
        .min = 0, .max = 32,
    },

    [MANIM_DEBUG_PARAM_Y] =
    {
        .text_width = 2,
        .param_up = MANIM_DEBUG_PARAM_PID,
        .param_down = MANIM_DEBUG_PARAM_JID,
        .param_left = MANIM_DEBUG_PARAM_X,
        .param_right = MANIM_DEBUG_PARAM_X,
        .min = 0, .max = 32,
    },

    [MANIM_DEBUG_PARAM_JID] =
    {
        .text_width = 11,
        .param_up = MANIM_DEBUG_PARAM_X,
        .param_down = MANIM_DEBUG_PARAM_IID,
        .param_left = MANIM_DEBUG_PARAM_JID,
        .param_right = MANIM_DEBUG_PARAM_JID,
        .min = 1, .max = MAX_JIDS,
    },

    [MANIM_DEBUG_PARAM_IID] =
    {
        .text_width = 10,
        .param_up = MANIM_DEBUG_PARAM_JID,
        .param_down = MANIM_DEBUG_PARAM_HITS + 0,
        .param_left = MANIM_DEBUG_PARAM_IID,
        .param_right = MANIM_DEBUG_PARAM_IID,
        .min = 1, .max = MAX_IIDS,
    },

    [MANIM_DEBUG_PARAM_HITS + 0] =
    {
        .text_width = 9,
        .param_up = MANIM_DEBUG_PARAM_IID,
        .param_down = MANIM_DEBUG_PARAM_HITS + 1,
        .param_left = MANIM_DEBUG_PARAM_HITS + 0,
        .param_right = MANIM_DEBUG_PARAM_HITS + 0,
        .min = 0, .max = MAX_MANIM_DEBUG_HIT_KIND,
    },

    [MANIM_DEBUG_PARAM_HITS + 1] =
    {
        .text_width = 5,
        .param_up = MANIM_DEBUG_PARAM_HITS + 0,
        .param_down = MANIM_DEBUG_PARAM_HITS + 2,
        .param_left = MANIM_DEBUG_PARAM_HITS + 1,
        .param_right = MANIM_DEBUG_PARAM_HITS + 1,
        .min = 0, .max = MAX_MANIM_DEBUG_HIT_KIND,
    },

    [MANIM_DEBUG_PARAM_HITS + 2] =
    {
        .text_width = 5,
        .param_up = MANIM_DEBUG_PARAM_HITS + 1,
        .param_down = MANIM_DEBUG_PARAM_HITS + 3,
        .param_left = MANIM_DEBUG_PARAM_HITS + 2,
        .param_right = MANIM_DEBUG_PARAM_HITS + 2,
        .min = 0, .max = MAX_MANIM_DEBUG_HIT_KIND,
    },

    [MANIM_DEBUG_PARAM_HITS + 3] =
    {
        .text_width = 5,
        .param_up = MANIM_DEBUG_PARAM_HITS + 2,
        .param_down = MANIM_DEBUG_PARAM_HITS + 4,
        .param_left = MANIM_DEBUG_PARAM_HITS + 3,
        .param_right = MANIM_DEBUG_PARAM_HITS + 3,
        .min = 0, .max = MAX_MANIM_DEBUG_HIT_KIND,
    },

    [MANIM_DEBUG_PARAM_HITS + 4] =
    {
        .text_width = 5,
        .param_up = MANIM_DEBUG_PARAM_HITS + 3,
        .param_down = MANIM_DEBUG_PARAM_PID,
        .param_left = MANIM_DEBUG_PARAM_HITS + 4,
        .param_right = MANIM_DEBUG_PARAM_HITS + 4,
        .min = 0, .max = MAX_MANIM_DEBUG_HIT_KIND,
    },
};

char const * CONST_DATA gManimDebugParamLabelList[] =
{
    JTEXT("ＰＩＤ"),
    JTEXT("ＸＹ"),
    JTEXT("兵種"),
    JTEXT("武器"),
    JTEXT("１"),
    JTEXT("２"),
    JTEXT("３"),
    JTEXT("４"),
    JTEXT("５"),
    NULL, // end
};

extern struct ManimDebugSt gManimDebugStObj; // COMMON
struct ManimDebugSt * CONST_DATA gManimDebugSt = &gManimDebugStObj;

struct ProcScr CONST_DATA ProcScr_ManimDebug[] =
{
    PROC_SLEEP(1),
    PROC_CALL(LockGame),
    PROC_CALL(func_fe6_08073324),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08063CF4),
PROC_LABEL(0),
    PROC_CALL(func_fe6_08063EF0),
    PROC_REPEAT(func_fe6_080640D0),
    PROC_CALL(func_fe6_0806495C),
    PROC_WHILE_EXISTS(ProcScr_Unk_08664DA4),
    PROC_GOTO(0),
    PROC_END,
};

void StartDebugManim(void)
{
    SpawnProc(ProcScr_ManimDebug, PROC_TREE_3);
}

void func_fe6_08063894(int num, int param, int text_color)
{
    #define PARAM_DATA(param) (gManimDebugSt->ent[num].data[(param)])
    #define PARAM_TEXT(param) (&gManimDebugSt->ent[num].text[(param)])

    struct PInfo const * pinfo = GetPInfo(PARAM_DATA(MANIM_DEBUG_PARAM_PID));
    struct JInfo const * jinfo = GetJInfo(PARAM_DATA(MANIM_DEBUG_PARAM_JID));

    int pid = PARAM_DATA(MANIM_DEBUG_PARAM_PID);
    int jid = PARAM_DATA(MANIM_DEBUG_PARAM_JID);
    int iid = PARAM_DATA(MANIM_DEBUG_PARAM_IID);

    switch (param)
    {
        case MANIM_DEBUG_PARAM_PID:
            ClearText(PARAM_TEXT(MANIM_DEBUG_PARAM_PID));
            Text_InsertDrawNumberOrBlank(PARAM_TEXT(MANIM_DEBUG_PARAM_PID), 16, text_color, pid);
            PutDrawText(PARAM_TEXT(MANIM_DEBUG_PARAM_PID), gBg0Tm + TM_OFFSET(num * 12 + 6, 0), text_color, 24, 0, DecodeMsg(pinfo->msg_name));
            EnableBgSync(BG0_SYNC_BIT);
            break;

        case MANIM_DEBUG_PARAM_X:
            ClearText(PARAM_TEXT(MANIM_DEBUG_PARAM_X));
            Text_InsertDrawNumberOrBlank(PARAM_TEXT(MANIM_DEBUG_PARAM_X), 8, text_color, PARAM_DATA(MANIM_DEBUG_PARAM_X));
            PutText(PARAM_TEXT(MANIM_DEBUG_PARAM_X), gBg0Tm + TM_OFFSET(num * 12 + 7, 2));
            EnableBgSync(BG0_SYNC_BIT);
            break;

        case MANIM_DEBUG_PARAM_Y:
            ClearText(PARAM_TEXT(MANIM_DEBUG_PARAM_Y));
            Text_InsertDrawNumberOrBlank(PARAM_TEXT(MANIM_DEBUG_PARAM_Y), 8, text_color, PARAM_DATA(MANIM_DEBUG_PARAM_Y));
            PutText(PARAM_TEXT(MANIM_DEBUG_PARAM_Y), gBg0Tm + TM_OFFSET(num * 12 + 10, 2));
            EnableBgSync(BG0_SYNC_BIT);
            break;

        case MANIM_DEBUG_PARAM_JID:
            ClearText(PARAM_TEXT(MANIM_DEBUG_PARAM_JID));
            Text_InsertDrawNumberOrBlank(PARAM_TEXT(MANIM_DEBUG_PARAM_JID), 16, text_color, jid);
            PutDrawText(PARAM_TEXT(MANIM_DEBUG_PARAM_JID), gBg0Tm + TM_OFFSET(num * 12 + 6, 4), text_color, 24, 0, DecodeMsg(jinfo->msg_name));
            EnableBgSync(BG0_SYNC_BIT);
            break;

        case MANIM_DEBUG_PARAM_IID:
            ClearText(PARAM_TEXT(MANIM_DEBUG_PARAM_IID));
            Text_InsertDrawNumberOrBlank(PARAM_TEXT(MANIM_DEBUG_PARAM_IID), 16, text_color, iid);
            PutDrawText(PARAM_TEXT(MANIM_DEBUG_PARAM_IID), gBg0Tm + TM_OFFSET(num * 12 + 6, 6), text_color, 24, 0, GetItemName(PARAM_DATA(MANIM_DEBUG_PARAM_IID)));
            EnableBgSync(BG0_SYNC_BIT);
            break;

        case MANIM_DEBUG_PARAM_HITS ... MAX_MANIM_DEBUG_PARAM - 1:
            ClearText(PARAM_TEXT(param));
            Text_InsertDrawNumberOrBlank(PARAM_TEXT(param), 8, text_color, PARAM_DATA(param));
            PutDrawText(PARAM_TEXT(param), gBg0Tm + TM_OFFSET(num * 12 + 7, 8 + (param - MANIM_DEBUG_PARAM_HITS) * 2), text_color, 16, 0, gManimDebugHitKindNameLut[PARAM_DATA(param)]);
            EnableBgSync(BG0_SYNC_BIT);
            break;
    }

    #undef PARAM_TEXT
    #undef PARAM_DATA
}

void func_fe6_08063CF4(struct GenericProc * proc)
{
    Proc_EndEach(ProcScr_DebugMonitor);

    proc->unk64 = 0;
    proc->unk66 = 0;

    gManimDebugSt->ent[0].data[MANIM_DEBUG_PARAM_JID] = JID_ROY;
    gManimDebugSt->ent[0].data[MANIM_DEBUG_PARAM_PID] = PID_ROY;
    gManimDebugSt->ent[0].data[MANIM_DEBUG_PARAM_IID] = IID_IRONSWORD;
    gManimDebugSt->ent[0].data[MANIM_DEBUG_PARAM_X] = 4;
    gManimDebugSt->ent[0].data[MANIM_DEBUG_PARAM_Y] = 8;

    gManimDebugSt->ent[1].data[MANIM_DEBUG_PARAM_JID] = JID_MERCENARY;
    gManimDebugSt->ent[1].data[MANIM_DEBUG_PARAM_PID] = PID_LILINA;
    gManimDebugSt->ent[1].data[MANIM_DEBUG_PARAM_IID] = IID_BINDINGBLADE;
    gManimDebugSt->ent[1].data[MANIM_DEBUG_PARAM_X] = 5;
    gManimDebugSt->ent[1].data[MANIM_DEBUG_PARAM_Y] = 8;

    gManimDebugSt->ent[0].data[MANIM_DEBUG_PARAM_HITS + 0] = MANIM_DEBUG_HIT_KIND_REGULAR;
    gManimDebugSt->ent[0].data[MANIM_DEBUG_PARAM_HITS + 1] = MANIM_DEBUG_HIT_KIND_CRIT;
    gManimDebugSt->ent[0].data[MANIM_DEBUG_PARAM_HITS + 2] = MANIM_DEBUG_HIT_KIND_NONE;
    gManimDebugSt->ent[0].data[MANIM_DEBUG_PARAM_HITS + 3] = MANIM_DEBUG_HIT_KIND_NONE;
    gManimDebugSt->ent[0].data[MANIM_DEBUG_PARAM_HITS + 4] = MANIM_DEBUG_HIT_KIND_NONE;

    gManimDebugSt->ent[1].data[MANIM_DEBUG_PARAM_HITS + 0] = MANIM_DEBUG_HIT_KIND_REGULAR;
    gManimDebugSt->ent[1].data[MANIM_DEBUG_PARAM_HITS + 1] = MANIM_DEBUG_HIT_KIND_NONE;
    gManimDebugSt->ent[1].data[MANIM_DEBUG_PARAM_HITS + 2] = MANIM_DEBUG_HIT_KIND_NONE;
    gManimDebugSt->ent[1].data[MANIM_DEBUG_PARAM_HITS + 3] = MANIM_DEBUG_HIT_KIND_NONE;
    gManimDebugSt->ent[1].data[MANIM_DEBUG_PARAM_HITS + 4] = MANIM_DEBUG_HIT_KIND_NONE;
}

void func_fe6_08063EF0(struct GenericProc * proc)
{
    int i, j;

    EndAllMus();
    ResetText();

    SetBlendConfig(BLEND_EFFECT_BRIGHTEN, 8, 8, 0);
    SetBlendTargetA(0, 1, 0, 0, 0);
    SetBlendTargetB(0, 0, 1, 1, 1);
    SetWinEnable(0, 0, 0);

    PutUiWindowFrame(0, 0, 29, 19, UI_WINDOW_FILL);

    for (i = 0; gManimDebugParamLabelList[i] != NULL; i++)
    {
        PutString(gBg0Tm + TM_OFFSET(1, i * 2), 0, gManimDebugParamLabelList[i]);
    }

    for (i = 0; i < MAX_MANIM_DEBUG_PARAM; i++)
    {
        for (j = 0; j < 2; ++j)
        {
            InitTextDb(&gManimDebugSt->ent[j].text[i], gManimDebugParamInfoTable[i].text_width);

            if (j == proc->unk64 && i == proc->unk66)
                func_fe6_08063894(j, i, TEXT_COLOR_SYSTEM_WHITE);
            else
                func_fe6_08063894(j, i, TEXT_COLOR_SYSTEM_GRAY);
        }
    }

    EnableBgSync(BG0_SYNC_BIT);
}

void func_fe6_080640D0(struct GenericProc * proc)
{
    int actor_prev = proc->unk64;
    int param_prev = proc->unk66;
    int step;

    if (gKeySt->pressed & KEY_BUTTON_START)
    {
        if (!func_fe6_080646E4())
            return;

        Proc_Break(proc);
    }

    if (gKeySt->held & KEY_BUTTON_R)
        step = 10;
    else
        step = 1;

    if (gKeySt->repeated & KEY_BUTTON_A)
    {
        gManimDebugSt->ent[proc->unk64].data[proc->unk66] += step;

        if (gManimDebugSt->ent[proc->unk64].data[proc->unk66] >= gManimDebugParamInfoTable[proc->unk66].max)
        {
            if (step == 1)
                gManimDebugSt->ent[proc->unk64].data[proc->unk66] = gManimDebugParamInfoTable[proc->unk66].min;
            else
                gManimDebugSt->ent[proc->unk64].data[proc->unk66] = gManimDebugParamInfoTable[proc->unk66].max - 1;
        }
    }

    if (gKeySt->repeated & KEY_BUTTON_B)
    {
        gManimDebugSt->ent[proc->unk64].data[proc->unk66] -= step;

        if (gManimDebugSt->ent[proc->unk64].data[proc->unk66] < gManimDebugParamInfoTable[proc->unk66].min)
        {
            if (step == 1)
                gManimDebugSt->ent[proc->unk64].data[proc->unk66] = gManimDebugParamInfoTable[proc->unk66].max - 1;
            else
                gManimDebugSt->ent[proc->unk64].data[proc->unk66] = gManimDebugParamInfoTable[proc->unk66].min;
        }
    }

    if (gKeySt->repeated & KEY_DPAD_LEFT)
    {
        if (proc->unk66 != MANIM_DEBUG_PARAM_Y)
            proc->unk64 = 1 - proc->unk64;

        proc->unk66 = gManimDebugParamInfoTable[proc->unk66].param_left;
    }

    if (gKeySt->repeated & KEY_DPAD_RIGHT)
    {
        if (proc->unk66 != MANIM_DEBUG_PARAM_X)
            proc->unk64 = 1 - proc->unk64;

        proc->unk66 = gManimDebugParamInfoTable[proc->unk66].param_right;
    }

    if (gKeySt->repeated & KEY_DPAD_UP)
        proc->unk66 = gManimDebugParamInfoTable[proc->unk66].param_up;

    if (gKeySt->repeated & KEY_DPAD_DOWN)
        proc->unk66 = gManimDebugParamInfoTable[proc->unk66].param_down;

    if (gKeySt->repeated & KEY_DPAD_ANY)
        func_fe6_08063894(actor_prev, param_prev, TEXT_COLOR_SYSTEM_GRAY);

    if (gKeySt->repeated & (KEY_DPAD_ANY | KEY_BUTTON_A | KEY_BUTTON_B))
        func_fe6_08063894(proc->unk64, proc->unk66, TEXT_COLOR_SYSTEM_WHITE);
}

void func_fe6_080645F8(struct BattleUnit * bu, int num)
{
    bu->previous_hp = 30;
    bu->unit.max_hp = 60;

    bu->unit.pinfo = GetPInfo(gManimDebugSt->ent[num].data[MANIM_DEBUG_PARAM_PID]);
    bu->unit.jinfo = GetJInfo(gManimDebugSt->ent[num].data[MANIM_DEBUG_PARAM_JID]);

    bu->unit.x = gManimDebugSt->ent[num].data[MANIM_DEBUG_PARAM_X];
    bu->unit.y = gManimDebugSt->ent[num].data[MANIM_DEBUG_PARAM_Y];

    bu->weapon_before = gManimDebugSt->ent[num].data[MANIM_DEBUG_PARAM_IID];
    bu->exp_gain = 0;
}

bool func_fe6_080646E4(void)
{
    // There's some gross variable reuse going on here

    int hitnum, actnum, i;
    struct BattleHit * hit;
    int var_10;

    hit = gBattleHits;

    func_fe6_080645F8(&gBattleUnitA, 0);
    func_fe6_080645F8(&gBattleUnitB, 1);

    ClearBattleHits();

    var_10 = 0;

    for (hitnum = 0; hitnum < MAX_MANIM_DEBUG_HITS; ++hitnum)
    {
        for (actnum = 0; actnum < 2; ++actnum)
        {
            if (gManimDebugSt->ent[actnum].data[MANIM_DEBUG_PARAM_HITS + hitnum] != 0)
            {
                var_10 = 1;
                break;
            }
        }

        if (var_10 != 0)
            break;
    }

    if (hitnum == MAX_MANIM_DEBUG_HITS && actnum == 2)
        return FALSE;

    for (i = hitnum * 2 + actnum; i < 10; i++)
    {
        hitnum = i / 2;
        actnum = i & 1;

        hit->info = BATTLE_HIT_INFO_ACTOR(actnum);

        var_10 = gManimDebugSt->ent[actnum].data[5 + hitnum];

        switch (var_10)
        {
            case MANIM_DEBUG_HIT_KIND_CRIT ... MANIM_DEBUG_HIT_KIND_MISS - 1:
                hit->attributes |= BATTLE_HIT_ATTR_CRIT;
                hit->damage = 20;
                break;

            case MANIM_DEBUG_HIT_KIND_REGULAR ... MANIM_DEBUG_HIT_KIND_CRIT - 1:
                hit->damage = 10;
                break;

            case MANIM_DEBUG_HIT_KIND_MISS:
                hit->attributes |= BATTLE_HIT_ATTR_MISS;
                break;
        }

        switch (var_10)
        {
            case MANIM_DEBUG_HIT_KIND_REGULAR_DEVIL:
            case MANIM_DEBUG_HIT_KIND_CRIT_DEVIL:
                hit->attributes |= BATTLE_HIT_ATTR_DEVIL;
                break;
                break;

            case MANIM_DEBUG_HIT_KIND_REGULAR_HPSTEAL:
            case MANIM_DEBUG_HIT_KIND_CRIT_HPSTEAL:
                hit->attributes |= BATTLE_HIT_ATTR_HPSTEAL;
                break;
                break;

            case MANIM_DEBUG_HIT_KIND_REGULAR_POISON:
            case MANIM_DEBUG_HIT_KIND_CRIT_POISON:
                hit->attributes |= BATTLE_HIT_ATTR_POISON;
                break;
                break;
        }

        switch (var_10)
        {
            case MANIM_DEBUG_HIT_KIND_NONE:
                continue;

            default:
                hit++;
        }
    }

    hit->info |= BATTLE_HIT_INFO_END;
    return TRUE;
}

void func_fe6_0806495C(struct GenericProc * proc)
{
    TmFill(gBg0Tm, 0);
    TmFill(gBg1Tm, 0);
    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);
    func_fe6_080627D0();
}

void func_fe6_08064994(struct Unit * unit)
{
    Decompress(gUnk_082DB1C0, OBJ_VRAM0 + CHR_SIZE * OBJCHR_MANIM_180);

    StartSpriteAnimProc(gUnk_082DB2B0,
        SCREEN_TILE_X(unit->x) * 8 + 8,
        SCREEN_TILE_Y(unit->y) * 8 + 16,
        OAM2_CHR(OBJCHR_MANIM_180), 0, 2);
}

void func_fe6_08064A10(struct Unit * unit)
{
    Decompress(gUnk_082DB418, OBJ_VRAM0 + CHR_SIZE * OBJCHR_MANIM_180);

    StartSpriteAnimProc(gUnk_082DB55C,
        SCREEN_TILE_X(unit->x) * 8 + 8,
        SCREEN_TILE_Y(unit->y) * 8 + 16,
        OAM2_CHR(OBJCHR_MANIM_180), 0, 2);
}

struct ProcScr CONST_DATA ProcScr_Unk_0866510C[] =
{
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08064B20),
    PROC_WHILE(SpriteAnimProcExists),
    PROC_END,
};

void func_fe6_08064A8C(struct Unit * unit, int arg_04)
{
    struct ManimEffectProc * proc;

    proc = SpawnProc(ProcScr_Unk_0866510C, PROC_TREE_3);

    proc->unit = unit;
    proc->x = SCREEN_TILE_X(unit->x) * 8 + 8;
    proc->y = SCREEN_TILE_Y(unit->y) * 8 - 8;
    proc->unk_48 = arg_04 ^ 1;
}

void func_fe6_08064B20(struct ManimEffectProc * proc)
{
    Decompress(gUnk_082DCAE4, OBJ_VRAM0 + CHR_SIZE * OBJCHR_MANIM_180);
    ApplyPalette(gUnk_082DCD70, 0x10 + OBJPAL_MANIM_3);

    StartSpriteAnimProc(gUnk_082A9228,
        proc->x, proc->y + 16,
        OAM2_CHR(OBJCHR_MANIM_180) | OAM2_PAL(OBJPAL_MANIM_3), proc->unk_48, 2);
}

struct ProcScr CONST_DATA ProcScr_Unk_0866512C[] =
{
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08064BEC),
    PROC_WHILE(SpriteAnimProcExists),
    PROC_END,
};

void func_fe6_08064B7C(struct Unit * unit)
{
    struct ManimEffectProc * proc;

    proc = SpawnProc(ProcScr_Unk_0866512C, PROC_TREE_3);

    proc->unit = unit;
    proc->x = (SCREEN_TILE_X(unit->x) + 1) * 8;
    proc->y = (SCREEN_TILE_Y(unit->y) + 1) * 8;
}

void func_fe6_08064BEC(struct ManimEffectProc * proc)
{
    PlaySeSpacial(SONG_B7, proc->x);

    Decompress(gUnk_082DCEF4, OBJ_VRAM0 + CHR_SIZE * OBJCHR_MANIM_1C0);
    ApplyPalette(gUnk_082DD248, 0x10 + OBJPAL_MANIM_4);

    StartSpriteAnimProc(gUnk_082A9190,
        proc->x - 8, proc->y + 8,
        OAM2_CHR(OBJCHR_MANIM_1C0) | OAM2_PAL(OBJPAL_MANIM_4), 0, 2);
}

struct ProcScr CONST_DATA ProcScr_Unk_0866514C[] =
{
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08064CC0),
    PROC_REPEAT(func_fe6_08064DF8),
    PROC_START_CHILD_LOCKING(ProcScr_Unk_08665194),
    PROC_SLEEP(60),
    PROC_CALL(func_fe6_08065AF8),
    PROC_END,
};

void func_fe6_08064C50(struct Unit * unit)
{
    struct ManimEffectProc * proc;

    proc = SpawnProc(ProcScr_Unk_0866514C, PROC_TREE_3);

    proc->unit = unit;
    proc->x = (SCREEN_TILE_X(unit->x) + 1) * 8;
    proc->y = (SCREEN_TILE_Y(unit->y) + 1) * 8;
}

void func_fe6_08064CC0(struct ManimEffectProc * proc)
{
    func_fe6_08067324();

    SetBgOffset(2, 0, 0);

    Decompress(gUnk_082DE994, ((void *) VRAM) + GetBgChrOffset(2) + BGCHR_MANIM_140 * CHR_SIZE);

    SetBlendAlpha(16, 16);
    SetBlendTargetA(0, 0, 1, 0, 0); SetBlendBackdropA(0);
    SetBlendTargetB(0, 0, 0, 1, 1); SetBlendBackdropB(1);

    proc->unk_40 = 0;
    proc->unk_42 = 0;

    func_fe6_08014D9C(gUnk_082DEFBC, 0x20 * BGPAL_MANIM_4, 0x20, 2, proc);
}

i16 CONST_DATA gUnk_08665184[] =
{
    +1, -1,
    -2, +2,
    +2, +1,
    -2, -2,
};

void func_fe6_08064DF8(struct ManimEffectProc * proc)
{
    if (proc->unk_42 > 2)
    {
        func_fe6_08014D50();
        func_fe6_08014DB4(gUnk_082DEFBC, 0x20 * BGPAL_MANIM_4, 0x20, 4, proc);

        Decompress(gUnk_082DEFFC, ((void *) VRAM) + GetBgChrOffset(2) + BGCHR_MANIM_140 * CHR_SIZE);

        func_fe6_080650A4(proc->x / 8 - 4, proc->y / 8 - 4, 8, 60, 0, proc);

        Proc_Break(proc);
        PlaySeSpacial(SONG_8C, proc->x);
    }
    else
    {
        int x_offset = gUnk_08665184[proc->unk_42 * 2 + 0];
        int y_offset = gUnk_08665184[proc->unk_42 * 2 + 1];

        func_fe6_080650A4(proc->x / 8 + x_offset - 3, proc->y / 8 + y_offset - 3, 6, 10, 8, proc);

        PlaySeSpacial(SONG_89, proc->x);

        proc->unk_42++;
    }
}

void func_fe6_08064F28(struct ManimEffectProc * proc)
{
    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);
}

struct ProcScr CONST_DATA ProcScr_Unk_08665194[] =
{
    PROC_CALL(func_fe6_08064F4C),
    PROC_REPEAT(func_fe6_08064FD0),
    PROC_END,
};

void func_fe6_08064F4C(struct ManimEffectProc * proc)
{
    func_fe6_08014D50();

    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);

    SetBlendTargetA(1, 1, 1, 1, 1);
    SetBlendBackdropA(1);

    proc->unk_64 = 64;

    func_fe6_08064FD0(proc);
}

void func_fe6_08064FD0(struct ManimEffectProc * proc)
{
    SetBlendBrighten(proc->unk_64-- >> 2);

    if (proc->unk_64 == 0)
    {
        SetBlendNone();
        Proc_Break(proc);
    }
}

struct ManimSomethingProc_080650A4
{
    /* 00 */ PROC_HEADER;
    /* 2C */ int x, y;
    /* 34 */ u8 pad_34[0x10];
    /* 44 */ short freeze_duration;
    /* 48 */ u8 pad_46[0x54 - 0x48];
    /* 54 */ int square_size;
    /* 58 */ int fadeout_duration;
    /* 5C */ u8 pad_5C[0x64 - 0x5C];
    /* 64 */ short counter;
};

void func_fe6_080650F8(struct ManimSomethingProc_080650A4 * proc);
void func_fe6_0806511C(struct ManimSomethingProc_080650A4 * proc);
void func_fe6_08065140(struct ManimSomethingProc_080650A4 * proc);
void func_fe6_080651E0(struct ManimSomethingProc_080650A4 * proc);
void func_fe6_08065298(struct ManimSomethingProc_080650A4 * proc);
void func_fe6_080652E0(struct ManimSomethingProc_080650A4 * proc);

struct ProcScr CONST_DATA ProcScr_Unk_086651AC[] =
{
    PROC_ONEND(func_fe6_080650F8),
    PROC_CALL(func_fe6_0806511C),
    PROC_SLEEP(0),
    PROC_CALL(func_fe6_08065140),
    PROC_REPEAT(func_fe6_080651E0),
    PROC_REPEAT(func_fe6_08065298),
    PROC_REPEAT(func_fe6_080652E0),
    PROC_END,
};

void func_fe6_080650A4(int x, int y, int square_size, int freeze_duration, int fadeout_duration, ProcPtr parent)
{
    struct ManimSomethingProc_080650A4 * proc;

    proc = SpawnProcLocking(ProcScr_Unk_086651AC, parent);

    proc->x = x;
    proc->y = y;
    proc->square_size = square_size;
    proc->fadeout_duration = fadeout_duration;
    proc->freeze_duration = freeze_duration;
}

void func_fe6_080650F8(struct ManimSomethingProc_080650A4 * proc)
{
    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);
}

void func_fe6_0806511C(struct ManimSomethingProc_080650A4 * proc)
{
    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);
}

void func_fe6_08065140(struct ManimSomethingProc_080650A4 * proc)
{
    func_fe6_08014E30(gBg2Tm, proc->x, proc->y, TILEREF(BGCHR_MANIM_140, BGPAL_MANIM_4), proc->square_size, proc->square_size);
    EnableBgSync(BG2_SYNC_BIT);
    SetBlendAlpha(0, 0x10);
    proc->counter = 0;
}

void func_fe6_080651E0(struct ManimSomethingProc_080650A4 * proc)
{
    proc->counter += 2;
    SetBlendAlpha(proc->counter, 0x10);

    if (proc->counter >= 8)
    {
        proc->counter = 0;
        Proc_Break(proc);
    }
}

void func_fe6_08065298(struct ManimSomethingProc_080650A4 * proc)
{
    if (--proc->freeze_duration == -1)
        Proc_Break(proc);
}

void func_fe6_080652E0(struct ManimSomethingProc_080650A4 * proc)
{
    int coef;

    if (proc->fadeout_duration == 0)
    {
        Proc_Break(proc);
        return;
    }

    coef = Interpolate(INTERPOLATE_LINEAR, 8, 0, proc->counter++, proc->fadeout_duration);
    SetBlendAlpha(coef, 0x10);

    if (proc->counter >= proc->fadeout_duration)
    {
        proc->counter = 0;

        TmFill(gBg2Tm, 0);
        EnableBgSync(BG2_SYNC_BIT);

        Proc_Break(proc);
    }
}

struct ManimSomethingProc_080653BC
{
    /* 00 */ PROC_HEADER;
    /* 2C */ struct Unit * unit;
    /* 30 */ int x, y;
    /* 38 */ u8 pad_34[0x40 - 0x38];
    /* 40 */ u16 counter;
    /* 42 */ u8 pad_42[0x50 - 0x42];
    /* 50 */ void const * img;
    /* 54 */ void const * pal;
};

void func_fe6_0806543C(struct ManimSomethingProc_080653BC * proc);
void func_fe6_08065540(struct ManimSomethingProc_080653BC * proc);

struct ProcScr CONST_DATA ProcScr_Unk_086651EC[] =
{
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_0806543C),
    PROC_REPEAT(func_fe6_08065540),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08065AF8),
    PROC_END,
};

void func_fe6_080653BC(struct Unit * unit, void const * img, void const * pal)
{
    struct ManimSomethingProc_080653BC * proc;

    proc = SpawnProc(ProcScr_Unk_086651EC, PROC_TREE_3);

    proc->unit = unit;
    proc->x = (SCREEN_TILE_X(unit->x) + 1) * 8;
    proc->y = (SCREEN_TILE_Y(unit->y) + 1) * 8;
    proc->img = img;
    proc->pal = pal;
}

void func_fe6_0806543C(struct ManimSomethingProc_080653BC * proc)
{
    PlaySeSpacial(SONG_B6, proc->x);

    gDispIo.bg0_ct.priority = 0;
    gDispIo.bg1_ct.priority = 1;
    gDispIo.bg2_ct.priority = 1;
    gDispIo.bg3_ct.priority = 2;

    SetBgOffset(2, 0, 0);

    Decompress(proc->img, ((void *) VRAM) + GetBgChrOffset(2) + CHR_SIZE * BGCHR_MANIM_140);
    ApplyPalette(proc->pal, BGPAL_MANIM_4);

    func_fe6_08067324();

    SetBlendAlpha(0x10, 0x10);

    proc->counter = 0;
}

void func_fe6_08065540(struct ManimSomethingProc_080653BC * proc)
{
    static u8 SHOULD_BE_CONST lut[] =
    {
         0,  1,  2,  3,
         4,  5,  6,  7,
         8,  9, 10, 11,
        12, 13, 14, 15,
        16, 17, 18, 19,

        UINT8_MAX, // end
    };

    func_fe6_08014F70(gBg2Tm, proc->x / 8 - 3, proc->y / 8 - 3, TILEREF(BGCHR_MANIM_140, BGPAL_MANIM_4), 6, 6, gUnk_082DE354, lut[proc->counter / 2]);
    EnableBgSync(BG2_SYNC_BIT);

    proc->counter++;

    if (lut[proc->counter / 2] == UINT8_MAX)
    {
        Proc_Break(proc);
    }
}

struct ManimSomethingProc_08065608
{
    /* 00 */ PROC_HEADER;
    /* 29 */ u8 pad_29[0x30 - 0x29];
    /* 30 */ int x, y;
};

void func_fe6_08065674(struct ManimSomethingProc_08065608 * proc);

struct ProcScr CONST_DATA ProcScr_Unk_08665234[] =
{
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08065674),
    PROC_SLEEP(100),
    PROC_END,
};

void func_fe6_08065608(struct Unit * unit)
{
    struct ManimSomethingProc_08065608 * proc;

    proc = SpawnProc(ProcScr_Unk_08665234, PROC_TREE_3);

    proc->x = SCREEN_TILE_X(unit->x) * 8 + 8;
    proc->y = SCREEN_TILE_Y(unit->y) * 8 + 8;
}

void func_fe6_08065674(struct ManimSomethingProc_08065608 * proc)
{
    PlaySeSpacial(SONG_10F, proc->x);
}

struct ManimSomethingProc_08065694
{
    /* 00 */ PROC_HEADER;
    /* 2C */ struct Unit * unit;
    /* 30 */ u8 pad_30[0x40 - 0x30];
    /* 40 */ u16 ca;
    /* 42 */ u16 cb;
    /* 44 */ u8 pad_44[0x50 - 0x44];
    /* 50 */ void const * img;
    /* 54 */ void const * pal;
    /* 58 */ u16 song;
};

void func_fe6_080656F0(struct ManimSomethingProc_08065694 * proc);
void func_fe6_08065830(struct ManimSomethingProc_08065694 * proc);
void func_fe6_08065994(struct ManimSomethingProc_08065694 * proc);

struct ProcScr CONST_DATA ProcScr_Unk_08665254[] =
{
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_080656F0),
    PROC_REPEAT(func_fe6_08065830),
    PROC_SLEEP(30),
    PROC_REPEAT(func_fe6_08065994),
    PROC_CALL(func_fe6_08065AF8),
    PROC_END,
};

void func_fe6_08065694(struct Unit * unit, void const * img, void const * pal, fu16 song)
{
    struct ManimSomethingProc_08065694 * proc;

    proc = SpawnProc(ProcScr_Unk_08665254, PROC_TREE_3);

    proc->unit = unit;
    proc->img = img;
    proc->pal = pal;
    proc->song = song;
}

void func_fe6_080656F0(struct ManimSomethingProc_08065694 * proc)
{
    gDispIo.bg0_ct.priority = 0;
    gDispIo.bg1_ct.priority = 1;
    gDispIo.bg2_ct.priority = 1;
    gDispIo.bg3_ct.priority = 2;

    SetBgOffset(2, 0, 0);

    Decompress(proc->img, ((void *) VRAM) + GetBgChrOffset(2) + CHR_SIZE * BGCHR_MANIM_140);

    func_fe6_08014E30(gBg2Tm, SCREEN_TILE_X(proc->unit->x) - 2, SCREEN_TILE_Y(proc->unit->y) - 2, TILEREF(BGCHR_MANIM_140, BGPAL_MANIM_4), 6, 6);
    EnableBgSync(BG2_SYNC_BIT);

    func_fe6_08014DB4(proc->pal, BGPAL_MANIM_4 * 0x20, 0x20, 4, proc);

    proc->ca = 0;
    proc->cb = 0x10;

    PlaySeSpacial(proc->song, (SCREEN_TILE_X(proc->unit->x) + 1) * 8);
}

void func_fe6_08065830(struct ManimSomethingProc_08065694 * proc)
{
    proc->ca++;

    if (proc->ca == 0x10)
    {
        Proc_Break(proc);
    }

    proc->cb = 0x16 - proc->ca;

    if (proc->cb > 0x10)
        proc->cb = 0x10;

    SetBlendAlpha(proc->ca, proc->cb);

    SetBlendTargetA(0, 0, 1, 0, 0); SetBlendBackdropA(0);
    SetBlendTargetB(0, 0, 0, 1, 1); SetBlendBackdropB(1);
}

void func_fe6_08065994(struct ManimSomethingProc_08065694 * proc)
{
    proc->ca--;

    if (proc->ca == 0)
    {
        Proc_Break(proc);
    }

    proc->cb = 0x16 - proc->ca;

    if (proc->cb > 0x10)
        proc->cb = 0x10;

    SetBlendAlpha(proc->ca, proc->cb);

    SetBlendTargetA(0, 0, 1, 0, 0); SetBlendBackdropA(0);
    SetBlendTargetB(0, 0, 0, 1, 1); SetBlendBackdropB(1);
}

void func_fe6_08065AF8(ProcPtr proc)
{
    func_fe6_08014D50();

    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);

    SetBlendNone();
    SetWinEnable(0, 0, 0);
}

void func_fe6_08065B90(ProcPtr proc)
{
    SetOnHBlankA(NULL);

    func_fe6_08014D50();

    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);

    SetBlendNone();
    SetWinEnable(0, 0, 0);
}

struct ManimSomethingProc_08065C30
{
    /* 00 */ PROC_HEADER;
    /* 2C */ struct Unit * unit;
    /* 30 */ int x, y;
    /* 38 */ u8 pad_38[0x40 - 0x38];
    /* 40 */ u16 counter;
};

void func_fe6_08065C9C(struct ManimSomethingProc_08065C30 * proc);
void func_fe6_08065CF4(struct ManimSomethingProc_08065C30 * proc);

struct ProcScr CONST_DATA ProcScr_Unk_0866528C[] =
{
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08065C9C),
    PROC_REPEAT(func_fe6_08065CF4),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08065AF8),
    PROC_END,
};

void func_fe6_08065C30(struct Unit * unit, int arg_04, int arg_08)
{
    struct ManimSomethingProc_08065C30 * proc;

    proc = SpawnProc(ProcScr_Unk_0866528C, PROC_TREE_3);

    proc->unit = unit;
    proc->x = SCREEN_TILE_X(proc->unit->x);
    proc->y = SCREEN_TILE_Y(proc->unit->y);
}

void func_fe6_08065C9C(struct ManimSomethingProc_08065C30 * proc)
{
    SetBgOffset(2, 0, 0);

    Decompress(gUnk_082DD268, ((void *) VRAM) + GetBgChrOffset(2) + CHR_SIZE * BGCHR_MANIM_140);
    ApplyPalette(gUnk_082DD4C8, BGPAL_MANIM_4);

    func_fe6_080686D8();

    proc->counter = 0;
}

void func_fe6_08065CF4(struct ManimSomethingProc_08065C30 * proc)
{
    static u8 SHOULD_BE_CONST lut[] =
    {
        0, 1, 2, 3,
        3, 3, 3, 3,
        3, 3, 3, 3,
        3, 3, 3, 4,
        5, 6, 7, 8,
        9,
        UINT8_MAX, // end
    };

    func_fe6_08014F70(gBg2Tm, proc->x - 1, proc->y - 3, TILEREF(BGCHR_MANIM_140, BGPAL_MANIM_4), 4, 6, gUnk_082DD4E8, lut[proc->counter / 2]);
    EnableBgSync(BG2_SYNC_BIT);

    proc->counter++;

    if (lut[proc->counter / 2] == UINT8_MAX)
    {
        Proc_Break(proc);
    }

    func_fe6_08067324();

    SetBlendAlpha(12, 12);
}

struct ManimSomethingProc_08065E08
{
    /* 00 */ PROC_HEADER;
    /* 2C */ struct Unit * unit;
    /* 30 */ int x, y;
    /* 38 */ u8 pad_38[0x40 - 0x38];
    /* 40 */ u16 unk_40, unk_42;
};

void func_fe6_08065E78(struct ManimSomethingProc_08065E08 * proc);
void func_fe6_08065F9C(struct ManimSomethingProc_08065E08 * proc);
void func_fe6_08066094(struct ManimSomethingProc_08065E08 * proc);
void func_fe6_08066190(struct ManimSomethingProc_08065E08 * proc);

struct ProcScr CONST_DATA ProcScr_Unk_086652D4[] =
{
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08065E78),
    PROC_SLEEP(30),
    PROC_REPEAT(func_fe6_08065F9C),
    PROC_REPEAT(func_fe6_08066094),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08066190),
    PROC_CALL(func_fe6_08065B90),
    PROC_END,
};

void func_fe6_08065E08(struct Unit * unit)
{
    struct ManimSomethingProc_08065E08 * proc;

    proc = SpawnProc(ProcScr_Unk_086652D4, PROC_TREE_3);

    proc->unit = unit;
    proc->x = SCREEN_TILE_X(proc->unit->x) * 8;
    proc->y = SCREEN_TILE_Y(proc->unit->y) * 8;
}

void func_fe6_08065E78(struct ManimSomethingProc_08065E08 * proc)
{
    PlaySe(SONG_B3);

    Decompress(gUnk_082DF3D8, ((void *) VRAM) + 0x10000 + OBJCHR_MANIM_1C0 * CHR_SIZE);
    ApplyPalette(gUnk_082DF690, 0x10 + OBJPAL_MANIM_4);

    SetWhitePal(BGPAL_MANIM_4);
    func_fe6_08015208(((void *) VRAM) + GetBgChrOffset(2) + BGCHR_MANIM_140 * CHR_SIZE, CHR_SIZE / sizeof(u16), 0xFFFF);
    func_fe6_08015208(gBg2Tm, ARRAY_COUNT(gBg2Tm), TILEREF(BGCHR_MANIM_140, BGPAL_MANIM_4));
    EnableBgSync(BG2_SYNC_BIT);

    proc->unk_40 = 0;
    proc->unk_42 = 0;

    StartSpriteAnimProc(gUnk_082A8448, proc->x + 4, proc->y, OAM2_CHR(OBJCHR_MANIM_1C0) + OAM2_PAL(OBJPAL_MANIM_4), 0, 2);

    func_fe6_08069C34();
    func_fe6_08069C74();
    func_fe6_08067324();

    SetBlendAlpha(0, 0x10);
}

void func_fe6_08065F9C(struct ManimSomethingProc_08065E08 * proc)
{
    int var_04, ca;

    var_04 = Interpolate(INTERPOLATE_RCUBIC, 1, 160, proc->unk_40, 80);
    func_fe6_08069DA4(proc->x + 8, proc->y + 8, var_04);

    proc->unk_40++;

    ca = (proc->unk_40 * 0x10) / 40;

    if (ca >= 0x10)
        ca = 0x10;

    SetBlendAlpha(ca, 0x10);

    if (proc->unk_40 >= 40)
    {
        Proc_Break(proc);
        EndEachSpriteAnimProc();
    }
}

void func_fe6_08066094(struct ManimSomethingProc_08065E08 * proc)
{
    int var_04, ca;

    var_04 = Interpolate(INTERPOLATE_RCUBIC, 1, 160, proc->unk_40, 80);
    func_fe6_08069DA4(proc->x + 8, proc->y + 8, var_04);

    proc->unk_40++;

    ca = 0x10 - ((proc->unk_40 - 40) * 0x10) / 30;

    if (ca <= 0)
        ca = 0;

    SetBlendAlpha(ca, 0x10);

    if (proc->unk_40 >= 70)
    {
        Proc_Break(proc);
    }
}

void func_fe6_08066190(struct ManimSomethingProc_08065E08 * proc)
{
    func_fe6_08069DD8();
}

struct ManimSomethingProc_080661A4
{
    /* 00 */ PROC_HEADER;
    /* 2C */ struct Unit * unit;
    /* 30 */ int x, y;
    /* 38 */ u8 pad_38[0x48 - 0x38];
    /* 48 */ u16 unk_48;
};

void func_fe6_08066214(struct ManimSomethingProc_080661A4 * proc);

struct ProcScr CONST_DATA ProcScr_Unk_0866531C[] =
{
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08066214),
    PROC_SLEEP(120),
    PROC_CALL(func_fe6_08065AF8),
    PROC_END,
};

void func_fe6_080661A4(struct Unit * unit)
{
    struct ManimSomethingProc_080661A4 * proc;

    proc = SpawnProc(ProcScr_Unk_0866531C, PROC_TREE_3);

    proc->unit = unit;
    proc->x = (SCREEN_TILE_X(unit->x) + 1) * 8;
    proc->y = (SCREEN_TILE_Y(unit->y) + 1) * 8;
}

void func_fe6_08066214(struct ManimSomethingProc_080661A4 * proc)
{
    PlaySeSpacial(SONG_87, proc->x);
    SetBgOffset(2, 0, 0);
    func_fe6_08067324();
    Decompress(gUnk_082E0E14, ((void *) VRAM) + 0x10000 + CHR_SIZE * OBJCHR_MANIM_1C0);
    ApplyPalette(gUnk_082E10EC, 0x10 + OBJPAL_MANIM_4);
    StartSpriteAnimProc(gUnk_082E110C, proc->x, proc->y, OAM2_CHR(OBJCHR_MANIM_1C0) + OAM2_PAL(OBJPAL_MANIM_4), 0, 2);
    proc->unk_48 = 1;
}

struct ManimSomethingProc_08066294
{
    /* 00 */ PROC_HEADER;
    /* 2C */ struct Unit * unit;
    /* 30 */ int x, y;
    /* 38 */ u8 pad_38[0x40 - 0x38];
    /* 40 */ u16 unk_40, unk_42;
    /* 44 */ u8 pad_44[0x48 - 0x44];
    /* 48 */ i16 unk_48, unk_4A;
};

void func_fe6_08066300(struct ManimSomethingProc_08066294 * proc);
void func_fe6_0806631C(struct ManimSomethingProc_08066294 * proc);
void func_fe6_080663E0(struct ManimSomethingProc_08066294 * proc);
void func_fe6_08066484(struct ManimSomethingProc_08066294 * proc);
void func_fe6_08066544(struct ManimSomethingProc_08066294 * proc);

struct ProcScr CONST_DATA ProcScr_Unk_08665344[] =
{
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_0806631C),
    PROC_CALL(func_fe6_08066300),
    PROC_REPEAT(func_fe6_080663E0),
    PROC_REPEAT(func_fe6_08066484),
    PROC_REPEAT(func_fe6_08066544),
    PROC_CALL(func_fe6_08065AF8),
    PROC_END,
};

void func_fe6_0806664C(struct ManimSomethingProc_08066294 * proc);
void func_fe6_08066678(struct ManimSomethingProc_08066294 * proc);

struct ProcScr CONST_DATA ProcScr_Unk_08665384[] =
{
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_0806631C),
    PROC_CALL(func_fe6_0806664C),
    PROC_REPEAT(func_fe6_08066678),
    PROC_REPEAT(func_fe6_08066484),
    PROC_REPEAT(func_fe6_08066544),
    PROC_CALL(func_fe6_08065AF8),
    PROC_END,
};

void func_fe6_08066294(struct Unit * unit)
{
    struct ManimSomethingProc_08066294 * proc;

    proc = SpawnProc(ProcScr_Unk_08665344, PROC_TREE_3);

    proc->x = SCREEN_TILE_X(unit->x) * 8 + 8;
    proc->y = SCREEN_TILE_Y(unit->y) * 8 + 8;
}

void func_fe6_08066300(struct ManimSomethingProc_08066294 * proc)
{
    PlaySeSpacial(SONG_86, proc->x);
}

void func_fe6_0806631C(struct ManimSomethingProc_08066294 * proc)
{
    SetBgOffset(2, 0, 0);
    func_fe6_08067324();
    SetBlendAlpha(0x10, 0x10);
    Decompress(gUnk_082DFAD4, ((void *) VRAM) + GetBgChrOffset(2) + CHR_SIZE * BGCHR_MANIM_140);
    ApplyPalette(gUnk_081B4274, BGPAL_MANIM_4);
    proc->unk_48 = 0;
    proc->unk_4A = 0;
}

void func_fe6_080663E0(struct ManimSomethingProc_08066294 * proc)
{
    static u8 const unk_param_list[] =
    {
        0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6,
        UINT8_MAX, // end
    };

    func_fe6_0801501C(gBg2Tm,
        proc->x / 8 - 2, proc->y / 8 - 9,
        TILEREF(BGCHR_MANIM_140, BGPAL_MANIM_4),
        4, 11, gUnk_082E07A8,
        unk_param_list[proc->unk_48++]);

    EnableBgSync(BG2_SYNC_BIT);

    if (unk_param_list[proc->unk_48] == UINT8_MAX)
        Proc_Break(proc);
}

void func_fe6_08066484(struct ManimSomethingProc_08066294 * proc)
{
    SHOULD_BE_STATIC u8 SHOULD_BE_CONST blend_coef_list[] =
    {
        16, 14, 12, 10, 8, 10, 12, 14, 16,
        16, 14, 12, 10, 8, 10, 12, 14, 16,
        UINT8_MAX, // end
    };

    SetBlendAlpha(blend_coef_list[proc->unk_4A++], 0x10);

    if (blend_coef_list[proc->unk_4A] == UINT8_MAX)
    {
        proc->unk_4A = 0;
        Proc_Break(proc);
    }
}

void func_fe6_08066544(struct ManimSomethingProc_08066294 * proc)
{
    enum { DURATION = 30 };

    SetBlendAlpha(
        Interpolate(INTERPOLATE_LINEAR, 0x10, 0, proc->unk_4A++, DURATION), 0x10);

    if (proc->unk_4A > DURATION)
    {
        Proc_Break(proc);
    }
}

void func_fe6_080665E4(struct Unit * unit)
{
    struct ManimSomethingProc_08066294 * proc;

    proc = SpawnProc(ProcScr_Unk_08665384, PROC_TREE_3);

    proc->x = (SCREEN_TILE_X(unit->x) + 1) * 8;
    proc->y = (SCREEN_TILE_Y(unit->y) + 1) * 8;
}

void func_fe6_0806664C(struct ManimSomethingProc_08066294 * proc)
{
    PlaySeSpacial(SONG_82, proc->x);
    ApplyPalette(Pal_Unk_081B1710, BGPAL_MANIM_4);
}

void func_fe6_08066678(struct ManimSomethingProc_08066294 * proc)
{
    // same as func_fe6_080663E0 except gUnk_082E07A8 -> gUnk_082DF868

    static u8 const unk_param_list[] =
    {
        0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6,
        UINT8_MAX, // end
    };

    func_fe6_0801501C(gBg2Tm,
        proc->x / 8 - 2, proc->y / 8 - 9,
        TILEREF(BGCHR_MANIM_140, BGPAL_MANIM_4),
        4, 11, gUnk_082DF868,
        unk_param_list[proc->unk_48++]);

    EnableBgSync(BG2_SYNC_BIT);

    if (unk_param_list[proc->unk_48] == UINT8_MAX)
        Proc_Break(proc);
}

struct ManimSomethingProc_0806671C
{
    /* 00 */ PROC_HEADER;
    /* 2C */ struct Unit * unit;
    /* 30 */ int x, y;
    /* 38 */ u8 pad_38[0x40 - 0x38];
    /* 40 */ u16 unk_40, unk_42;
    /* 44 */ u8 pad_44[0x48 - 0x44];
    /* 48 */ i16 unk_48, unk_4A;
};

void func_fe6_08066784(struct ManimSomethingProc_0806671C * proc);
void func_fe6_080667F0(struct ManimSomethingProc_0806671C * proc);
void func_fe6_08066830(struct ManimSomethingProc_0806671C * proc);

struct ProcScr CONST_DATA ProcScr_Unk_086653C4[] =
{
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08066784),
    PROC_SLEEP(50),
    PROC_CALL(func_fe6_080667F0),
    PROC_SLEEP(50),
    PROC_CALL(func_fe6_08066830),
    PROC_CALL(func_fe6_08065AF8),
    PROC_END,
};

void func_fe6_0806671C(struct Unit * unit)
{
    struct ManimSomethingProc_0806671C * proc;

    proc = SpawnProc(ProcScr_Unk_086653C4, PROC_TREE_3);

    proc->x = (SCREEN_TILE_X(unit->x) + 1) * 8;
    proc->y = (SCREEN_TILE_Y(unit->y) + 1) * 8;
}

// TODO: VRAM as a pointer

void func_fe6_08066784(struct ManimSomethingProc_0806671C * proc)
{
    PlaySeSpacial(SONG_85, proc->x);

    SetBgOffset(2, 0, 0);
    func_fe6_08067324();

    Decompress(gUnk_081B7468, OBJ_VRAM0 + OBJCHR_MANIM_1C0 * CHR_SIZE);
    ApplyPalette(gUnk_081B7650, 0x10 + OBJPAL_MANIM_4);

    StartSpriteAnimProc(gUnk_082E0A14, proc->x, proc->y - 16, OAM2_CHR(OBJCHR_MANIM_1C0) + OAM2_PAL(OBJPAL_MANIM_4), 0, 2);
}

void func_fe6_080667F0(struct ManimSomethingProc_0806671C * proc)
{
    PlaySeSpacial(SONG_85, proc->x);

    StartSpriteAnimProc(gUnk_082E0A14, proc->x, proc->y - 8, OAM2_CHR(OBJCHR_MANIM_1C0) + OAM2_PAL(OBJPAL_MANIM_4), 0, 2);
}

void func_fe6_08066830(struct ManimSomethingProc_0806671C * proc)
{
    PlaySeSpacial(SONG_85, proc->x);

    StartSpriteAnimProc(gUnk_082E0A14, proc->x, proc->y, OAM2_CHR(OBJCHR_MANIM_1C0) + OAM2_PAL(OBJPAL_MANIM_4), 0, 2);
}

struct ManimSomethingProc_0806686C
{
    /* 00 */ PROC_HEADER;
    /* 29 */ u8 pad_29[0x30 - 0x29];
    /* 30 */ int x, y;
    /* 38 */ u8 pad_38[0x48 - 0x38];
    /* 48 */ i16 unk_48, unk_4A;
};

void func_fe6_080668D8(struct ManimSomethingProc_0806686C * proc);
void func_fe6_080669BC(struct ManimSomethingProc_0806686C * proc);
void func_fe6_08066A48(struct ManimSomethingProc_0806686C * proc);

struct ProcScr CONST_DATA gUnk_08665404[] =
{
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_080668D8),
    PROC_SLEEP(10),
    PROC_REPEAT(func_fe6_080669BC),
    PROC_SLEEP(60),
    PROC_REPEAT(func_fe6_08066A48),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08065B90),
    PROC_END,
};

void func_fe6_0806686C(struct Unit * unit)
{
    struct ManimSomethingProc_0806686C * proc;

    proc = SpawnProc(gUnk_08665404, PROC_TREE_3);

    proc->x = (SCREEN_TILE_X(unit->x) + 1) * 8;
    proc->y = (SCREEN_TILE_Y(unit->y)) * 8 + 18;
}

void func_fe6_080668D8(struct ManimSomethingProc_0806686C * proc)
{
    PlaySeSpacial(SONG_FD, proc->x);

    func_fe6_08069C34();
    func_fe6_08069C74();
    SetOnHBlankA(func_fe6_08069E50);
    func_fe6_08067324();
    SetBlendAlpha(0x10, 0x10);

    TmApplyTsa_t(gBg2Tm, gBuf, TILEREF(BGCHR_MANIM_140, BGPAL_MANIM_4));
    EnableBgSync(BG2_SYNC_BIT);

    func_fe6_08067498(2, 0, 1, proc);
    SpawnProc(ProcScr_Unk_086660FC, proc);

    proc->unk_48 = 0;
    proc->unk_4A = 0;
}

u8 CONST_DATA gUnk_0866544C[] =
{
    4, 6, 7, 8, 8, 9,
    UINT8_MAX, // end
};

void func_fe6_080669BC(struct ManimSomethingProc_0806686C * proc)
{
    if (proc->unk_48 >= 12)
    {
        proc->unk_48--;
        Proc_Break(proc);
    }

    func_fe6_0806A270(proc->x, proc->y, ++proc->unk_48, 12, gUnk_0866544C);
}

void func_fe6_08066A48(struct ManimSomethingProc_0806686C * proc)
{
    if (proc->unk_48 <= 0)
    {
        proc->unk_48++;
        Proc_Break(proc);
    }

    func_fe6_0806A270(proc->x, proc->y, --proc->unk_48, 12, gUnk_0866544C);
}

struct ManimSomethingProc_08066AD4
{
    /* 00 */ PROC_HEADER;
    /* 2C */ struct Unit * unit;
    /* 30 */ int x, y;
    /* 38 */ u8 pad_38[0x40 - 0x38];
    /* 40 */ u16 unk_40, unk_42;
    /* 44 */ u8 pad_44[0x48 - 0x44];
    /* 48 */ i16 unk_48, unk_4A;
};

void func_fe6_08066B3C(struct ManimSomethingProc_08066AD4 * proc);
void func_fe6_08066C70(struct ManimSomethingProc_08066AD4 * proc);
void func_fe6_08066D5C(struct ManimSomethingProc_08066AD4 * proc);

struct ProcScr CONST_DATA ProcScr_Unk_08665454[] =
{
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08066B3C),
    PROC_SLEEP(50),
    PROC_CALL(func_fe6_08066C70),
    PROC_SLEEP(40),
    PROC_REPEAT(func_fe6_08066D5C),
    PROC_CALL(func_fe6_08065AF8),
    PROC_END,
};

void func_fe6_08066AD4(struct Unit * unit)
{
    struct ManimSomethingProc_08066AD4 * proc;

    proc = SpawnProc(ProcScr_Unk_08665454, PROC_TREE_3);

    proc->x = (SCREEN_TILE_X(unit->x) + 1) * 8;
    proc->y = (SCREEN_TILE_Y(unit->y) + 1) * 8;
}

void func_fe6_08066B3C(struct ManimSomethingProc_08066AD4 * proc)
{
    PlaySeSpacial(SONG_83, proc->x);

    SetBgOffset(2, 0, 0);
    func_fe6_08067324();

    Decompress(gUnk_082E161C, ((void *) VRAM) + GetBgChrOffset(2) + CHR_SIZE * BGCHR_MANIM_140);
    Decompress(gUnk_082E11DC, ((void *) VRAM) + 0x10000 + CHR_SIZE * OBJCHR_MANIM_1C0);
    ApplyPalette(gUnk_082E172C, BGPAL_MANIM_4);
    ApplyPalette(gUnk_082E172C, 0x10 + OBJPAL_MANIM_4);

    StartSpriteAnimProc(gUnk_082E174C, proc->x, proc->y | OAM0_BLEND, OAM2_CHR(OBJCHR_MANIM_1C0) + OAM2_PAL(OBJPAL_MANIM_4), 0, 2);

    proc->unk_48 = 0;

    SetBlendTargetA(0, 0, 0, 0, 1); SetBlendBackdropA(0);
    SetBlendConfig(BLEND_EFFECT_NONE, 0x10, 0x10, 0);
}

void func_fe6_08066C70(struct ManimSomethingProc_08066AD4 * proc)
{
    PlaySeSpacial(SONG_84, proc->x);

    func_fe6_08014E30(gBg2Tm, proc->x / 8 - 2, proc->y / 8 - 2, TILEREF(BGCHR_MANIM_140, BGPAL_MANIM_4), 4, 4);
    EnableBgSync(BG2_SYNC_BIT);

    SetBlendTargetA(0, 0, 1, 0, 0); SetBlendBackdropA(0);
    SetBlendAlpha(0x10, 0x10);
}

void func_fe6_08066D5C(struct ManimSomethingProc_08066AD4 * proc)
{
    SetBlendAlpha(Interpolate(INTERPOLATE_LINEAR, 0x10, 0, proc->unk_48++, 30), 0x10);

    if (proc->unk_48 >= 30)
        Proc_Break(proc);
}

struct ManimSomethingProc_08066DFC
{
    /* 00 */ PROC_HEADER;
    /* 2C */ struct Unit * unit;
    /* 30 */ int x, y;
    /* 38 */ u8 pad_38[0x40 - 0x38];
    /* 40 */ u16 unk_40, unk_42;
    /* 44 */ u8 pad_44[0x48 - 0x44];
    /* 48 */ i16 unk_48, unk_4A;
};

void func_fe6_08066E64(struct ManimSomethingProc_08066DFC * proc);
void func_fe6_08066F34(struct ManimSomethingProc_08066DFC * proc);

struct ProcScr CONST_DATA ProcScr_Unk_08665494[] =
{
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08066E64),
    PROC_REPEAT(func_fe6_08066F34),
    PROC_CALL(func_fe6_08065AF8),
    PROC_END,
};

void func_fe6_08066DFC(struct Unit * unit)
{
    struct ManimSomethingProc_08066DFC * proc;

    proc = SpawnProc(ProcScr_Unk_08665494, PROC_TREE_3);

    proc->x = (SCREEN_TILE_X(unit->x) + 1) * 8;
    proc->y = (SCREEN_TILE_Y(unit->y) + 1) * 8;
}

void func_fe6_08066E64(struct ManimSomethingProc_08066DFC * proc)
{
    PlaySeSpacial(SONG_88, proc->x);

    SetBgOffset(2, 0, 0);
    func_fe6_08067324();

    SetBlendAlpha(0x10, 0x10);

    Decompress(gUnk_082E1884, ((void *) VRAM) + GetBgChrOffset(2) + CHR_SIZE * BGCHR_MANIM_140);
    ApplyPalette(gUnk_081B8934, BGPAL_MANIM_4);

    proc->unk_48 = 0;
    proc->unk_4A = 0;
}

void func_fe6_08066F34(struct ManimSomethingProc_08066DFC * proc)
{
    static u8 const unk_param_list[] =
    {
        0, 0, 1, 1, 2, 2, 3, 3,
        4, 4, 3, 3, 4, 4, 3, 3,
        4, 4, 3, 3, 4, 4, 3, 3,
        4, 4, 3, 3, 4, 4, 3, 3,
        4, 4, 3, 3, 4, 4, 3, 3,
        2, 2, 1, 1, 0, 0,
        UINT8_MAX, // end
    };

    func_fe6_0801501C(gBg2Tm,
        proc->x / 8 - 2, proc->y / 8 - 8,
        TILEREF(BGCHR_MANIM_140, BGPAL_MANIM_4),
        4, 10, gUnk_082E2440,
        unk_param_list[proc->unk_48++]);

    EnableBgSync(BG2_SYNC_BIT);

    if (unk_param_list[proc->unk_48] == UINT8_MAX)
        Proc_Break(proc);
}

struct ManimSomethingProc_08066FD8
{
    /* 00 */ PROC_HEADER;
    /* 2C */ struct Unit * unit;
    /* 30 */ int x, y;
    /* 38 */ u8 pad_38[0x40 - 0x38];
    /* 40 */ u16 unk_40, unk_42;
    /* 44 */ u8 pad_44[0x48 - 0x44];
    /* 48 */ i16 unk_48, unk_4A;
};

void func_fe6_08067040(void);
void func_fe6_08067084(void);
void func_fe6_080670B8(struct ManimSomethingProc_08066FD8 * proc);
void func_fe6_080671F4(struct ManimSomethingProc_08066FD8 * proc);
void func_fe6_080672B0(struct ManimSomethingProc_08066FD8 * proc);

struct ProcScr CONST_DATA ProcScr_Unk_086654BC[] =
{
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_080670B8),
    PROC_REPEAT(func_fe6_080671F4),
    PROC_SLEEP(80),
    PROC_REPEAT(func_fe6_080672B0),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08065B90),
    PROC_CALL(func_fe6_08067040),
    PROC_SLEEP(4),
    PROC_CALL(func_fe6_08067084),
    PROC_END,
};

void func_fe6_08066FD8(int x, int y)
{
    struct ManimSomethingProc_08066FD8 * proc;

    proc = SpawnProc(ProcScr_Unk_086654BC, PROC_TREE_3);

    proc->x = SCREEN_TILE_X(x) * 8 + 8;
    proc->y = SCREEN_TILE_Y(y) * 8 + 8;
}

void func_fe6_08067040(void)
{
    GetUnit(gAction.instigator)->flags |= UNIT_FLAG_HIDDEN;
    StartAvailableDoorTileEvent(gAction.x_target, gAction.y_target);
}

void func_fe6_08067084(void)
{
    GetUnit(gAction.instigator)->flags &= ~UNIT_FLAG_HIDDEN;
}

void func_fe6_080670B8(struct ManimSomethingProc_08066FD8 * proc)
{
    PlaySeSpacial(SONG_8D, proc->x);

    SetBgOffset(2, 0, 0);
    Decompress(gUnk_082DF724, ((void *) VRAM) + GetBgChrOffset(2) + CHR_SIZE * BGCHR_MANIM_140);

    func_fe6_0801501C(gBg2Tm,
        proc->x / 8 - 2, proc->y / 8 - 2,
        TILEREF(BGCHR_MANIM_140, BGPAL_MANIM_4),
        4, 4, gUnk_082DF844, 0);

    EnableBgSync(BG2_SYNC_BIT);

    Decompress(gUnk_082DF6B0, ((void *) VRAM) + 0x10000 + CHR_SIZE * OBJCHR_MANIM_1C0);
    ApplyPalette(gUnk_082DF704, 0x10 + OBJPAL_MANIM_4);

    func_fe6_08014D9C(gUnk_082DF824, 0x20 * BGPAL_MANIM_4, 0x20, 4, proc);

    func_fe6_08069C34();
    func_fe6_08069C74();
    func_fe6_08067324();

    SetBlendAlpha(0x10, 0x10);

    proc->unk_48 = 1;
}

void func_fe6_080671F4(struct ManimSomethingProc_08066FD8 * proc)
{
    int var_04 = Interpolate(INTERPOLATE_RCUBIC, 1, 0x10, proc->unk_48, 30);

    proc->unk_48++;

    func_fe6_08069DA4(proc->x, proc->y, var_04);

    if (proc->unk_48 >= 30)
    {
        proc->unk_48 = 0;

        Proc_Break(proc);

        StartSpriteAnimProc(gUnk_082A84A4, proc->x, proc->y, OAM2_CHR(OBJCHR_MANIM_1C0) + OAM2_PAL(OBJPAL_MANIM_4), 0, 2);
        StartSpriteAnimProc(gUnk_082A84A4, proc->x, proc->y, OAM2_CHR(OBJCHR_MANIM_1C0) + OAM2_PAL(OBJPAL_MANIM_4), 1, 2);
    }
}

void func_fe6_080672B0(struct ManimSomethingProc_08066FD8 * proc)
{
    int var_04 = Interpolate(INTERPOLATE_RCUBIC, 0x10, 0, proc->unk_48, 30);

    proc->unk_48++;

    func_fe6_08069DA4(proc->x, proc->y, var_04);

    if (proc->unk_48 >= 30)
        Proc_Break(proc);
}

void func_fe6_08067324(void)
{
    // TODO: macro?
    gDispIo.bg0_ct.priority = 0;
    gDispIo.bg1_ct.priority = 0;
    gDispIo.bg2_ct.priority = 0;
    gDispIo.bg3_ct.priority = 2;

    SetBlendTargetA(0, 0, 1, 0, 0); SetBlendBackdropA(0);
    SetBlendTargetB(0, 0, 0, 1, 1); SetBlendBackdropB(1);

    gDispIo.win_ct.win0_enable_blend = 1;
    gDispIo.win_ct.wout_enable_blend = 0;

    SetWin0Layers(1, 1, 1, 1, 1);
    SetWOutLayers(1, 1, 0, 1, 1);
}

struct ManimSomethingProc_08067498
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x58);
    /* 58 */ i32 unk_58;
    /* 5C */ STRUCT_PAD(0x5C, 0x64);
    /* 64 */ i16 unk_64;
    /* 66 */ i16 unk_66;
    /* 68 */ i16 unk_68;
    /* 6A */ i16 unk_6A;
};

void func_fe6_0806752C(struct ManimSomethingProc_08067498 * proc);

struct ProcScr CONST_DATA ProcScr_Unk_08665514[] =
{
    PROC_REPEAT(func_fe6_0806752C),
    PROC_END,
};

void func_fe6_08067498(int bg, int x_inc, int y_inc, ProcPtr parent)
{
    struct ManimSomethingProc_08067498 * proc;

    proc = SpawnProc(ProcScr_Unk_08665514, parent);

    proc->unk_58 = bg;

    proc->unk_64 = 0;
    proc->unk_66 = x_inc;
    proc->unk_68 = 0;
    proc->unk_6A = y_inc;
}

void func_fe6_08067514(void)
{
    Proc_EndEach(ProcScr_Unk_08665514);
}

void func_fe6_0806752C(struct ManimSomethingProc_08067498 * proc)
{
    SetBgOffset(proc->unk_58, proc->unk_64, proc->unk_68);

    proc->unk_64 += proc->unk_66;
    proc->unk_68 += proc->unk_6A;
}

struct ManimLevelUpLabelInfo
{
    /* 00 */ u8 x;
    /* 01 */ u8 y;
    /* 02 */ STRUCT_PAD(0x02, 0x04);
    /* 04 */ char const * const * labels[2];
};

struct ManimLevelUpLabelInfo CONST_DATA gManimLevelUpLabelInfoList[] =
{
    {
        .x = 9, .y = 0,
        .labels = { SystemLabel_Level, SystemLabel_Level },
    },

    {
        .x = 1, .y = 4,
        .labels = { SystemLabel_Hp, SystemLabel_Hp },
    },

    {
        .x = 1, .y = 6,
        .labels = { SystemLabel_Strength, SystemLabel_Magic },
    },

    {
        .x = 1, .y = 8,
        .labels = { SystemLabel_Skill, SystemLabel_Skill },
    },

    {
        .x = 1, .y = 10,
        .labels = { SystemLabel_Speed, SystemLabel_Speed },
    },

    {
        .x = 9, .y = 4,
        .labels = { SystemLabel_Luck, SystemLabel_Luck },
    },

    {
        .x = 9, .y = 6,
        .labels = { SystemLabel_Defense, SystemLabel_Defense },
    },

    {
        .x = 9, .y = 8,
        .labels = { SystemLabel_Resistance, SystemLabel_Resistance },
    },

    {
        .x = 9, .y = 10,
        .labels = { SystemLabel_Constitution, SystemLabel_Constitution },
    },

    // end
    { .x = UINT8_MAX, .y = UINT8_MAX },
};

void func_fe6_080675AC(int actor_id, int x, int y)
{
    int i;

    TmFill(gBg1Tm, 0);

    Decompress(gUnk_08114D80, ((void *) VRAM) + GetBgChrOffset(1) + BGCHR_MANIM_200 * CHR_SIZE);
    Decompress(gUnk_08114FCC, gBuf);
    func_fe6_080152C4((u16 const *) gBuf, gBg1Tm, 0x20 * 0x1C, TILEREF(BGCHR_MANIM_200, BGPAL_MANIM_5));
    ApplyPalette(gUnk_081150C8, BGPAL_MANIM_5);

    PutString(
        gBg0Tm + TM_OFFSET(x + 1, y),
        TEXT_COLOR_SYSTEM_WHITE,
        DecodeMsg(gMapAnimSt.actor[actor_id].unit->jinfo->msg_name));

    for (i = 0; gManimLevelUpLabelInfoList[i].x != UINT8_MAX; i++)
    {
        PutStringCentered(
            gBg0Tm + TM_OFFSET(x + gManimLevelUpLabelInfoList[i].x, y + gManimLevelUpLabelInfoList[i].y),
            TEXT_COLOR_SYSTEM_GOLD, 3,
            gManimLevelUpLabelInfoList[i].labels[UnitKnowsMagic(gMapAnimSt.actor[actor_id].unit) == TRUE][GetLang()]);
    }

    EnableBgSync(BG0_SYNC_BIT + BG1_SYNC_BIT);
}

void MALevelUp_DrawActorStat(int actor_id, int x, int y, int stat_num, bool arg_10)
{
    PutNumberOrBlank(
        gBg0Tm + TM_OFFSET(x + gManimLevelUpLabelInfoList[stat_num].x + 4, y + gManimLevelUpLabelInfoList[stat_num].y),
        TEXT_COLOR_SYSTEM_BLUE,
        func_fe6_08067920(actor_id, stat_num) + (arg_10 ? MALevelUp_GetActorStatUp(actor_id, stat_num) : 0));
}

int MALevelUp_GetActorStatUp(int actor_id, int stat_num)
{
    switch (stat_num)
    {
        case 0:
            return 1;

        case 1:
            return gMapAnimSt.actor[actor_id].bu->change_hp;

        case 2:
            return gMapAnimSt.actor[actor_id].bu->change_pow;

        case 3:
            return gMapAnimSt.actor[actor_id].bu->change_skl;

        case 4:
            return gMapAnimSt.actor[actor_id].bu->change_spd;

        case 5:
            return gMapAnimSt.actor[actor_id].bu->change_lck;

        case 6:
            return gMapAnimSt.actor[actor_id].bu->change_def;

        case 7:
            return gMapAnimSt.actor[actor_id].bu->change_res;

        case 8:
            return gMapAnimSt.actor[actor_id].bu->change_con;

        default:
            return 0;
    }
}

int func_fe6_08067920(int actor_id, int stat_num)
{
    // getting the original unit to ensure we get the base stats
    struct Unit * unit = GetUnit(gMapAnimSt.actor[actor_id].unit->id);

    switch (stat_num)
    {
        case 0:
            return gMapAnimSt.actor[actor_id].bu->previous_level;

        case 1:
            return unit->max_hp;

        case 2:
            return unit->pow;

        case 3:
            return unit->skl;

        case 4:
            return unit->spd;

        case 5:
            return unit->lck;

        case 6:
            return unit->def;

        case 7:
            return unit->res;

        case 8:
            return UNIT_CON_BASE(unit);

        default:
            return 0;
    }
}

void func_fe6_08067A14(ProcPtr proc)
{
    EndEachSpriteAnimProc();
}

struct ManimSomethingProc_08067A28_A
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2A);
    /* 2A */ u16 chr;
    /* 2C */ u16 pal;
    /* 2E */ u16 sprite_layer;
};

struct ProcScr CONST_DATA ProcScr_Unk_0866559C[] =
{
    PROC_ONEND(func_fe6_08067A14),
    PROC_BLOCK,
};

struct ManimSomethingProc_08067A28_B
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x54);
    /* 54 */ i32 unk_54;
    /* 58 */ STRUCT_PAD(0x58, 0x64);
    /* 64 */ i16 unk_64;
};

void func_fe6_08068048(struct ManimSomethingProc_08067A28_B * proc);
void func_fe6_08068060(struct ManimSomethingProc_08067A28_B * proc);

struct ProcScr CONST_DATA ProcScr_Unk_086655AC[] =
{
    PROC_CALL(func_fe6_08068048),
    PROC_REPEAT(func_fe6_08068060),
    PROC_END,
};

void func_fe6_08067A28(int chr, int pal, int sprite_layer, ProcPtr parent)
{
    struct ManimSomethingProc_08067A28_A * proc_a;
    struct ManimSomethingProc_08067A28_B * proc_b;

    proc_a = SpawnProc(ProcScr_Unk_0866559C, parent);

    proc_a->chr = chr;
    proc_a->pal = pal;
    proc_a->sprite_layer = sprite_layer;

    Decompress(gUnk_082DBB24, ((void *) VRAM) + 0x10000 + (OAM2_CHR(chr) << 5));
    ApplyPalette(gUnk_082DBAC4, 0x10 + pal);
    ApplyPalette(gUnk_082DBAC4, 0x10 + pal + 1);

    proc_b = SpawnProc(ProcScr_Unk_086655AC, proc_a);
    proc_b->unk_64 = pal;
}

void func_fe6_08067AF0(void)
{
    Proc_EndEach(ProcScr_Unk_0866559C);
}

void func_fe6_08067B08(int x, int y, int stat_num, int stat_gain)
{
    int var_10;
    int var_14, var_18;
    struct ManimSomethingProc_08067A28_A * proc;

    u8 const * var_20 = gUnk_082DBDB0;

    proc = FindProc(ProcScr_Unk_0866559C);
    var_14 = proc->chr;
    var_18 = proc->chr + (stat_num - 1) * 2;

    if (stat_num == 0)
    {
        StartSpriteAnimProc(gUnk_082A75FC,
            x - 18, y - 4,
            OAM2_PAL(proc->pal) + var_14 + ((proc->sprite_layer & 3) * 0x0400),
            0, 2);
    }
    else
    {
        if (stat_gain > 0)
            var_10 = 0;
        else
            var_10 = 1;

        StartSpriteAnimProc(gUnk_082A75FC,
            x, y,
            OAM2_PAL(proc->pal + var_10) + var_14 + ((proc->sprite_layer & 3) * 0x0400),
            1 + var_10, 2);

        StartSpriteAnimProc(gUnk_082A75FC,
            x - 3, y,
            OAM2_PAL(proc->pal) + var_18 + ((proc->sprite_layer & 3) * 0x0400),
            3 + var_10, 2);

        if (stat_gain > 0)
        {
            StartSpriteAnimProc(gUnk_082A75FC,
                x - 18, y - 4,
                OAM2_PAL(proc->pal) + var_14 + ((proc->sprite_layer & 3) * 0x0400),
                0, 2);
        }

        if (stat_gain < 0)
        {
            func_fe6_08015260(var_20 + 0x20 * CHR_SIZE,
                (void *) OBJ_VRAM0 + (OAM2_CHR(var_18 + 0x4C) << 5), CHR_SIZE);
        }

        func_fe6_08015260(var_20 + (OAM2_CHR(ABS(stat_gain)) << 5),
            (void *) OBJ_VRAM0 + (OAM2_CHR(var_18 + 0x2D) << 5), CHR_SIZE);

        func_fe6_08015260(var_20 + (OAM2_CHR(ABS(stat_gain) + 0x20) << 5),
            (void *) OBJ_VRAM0 + (OAM2_CHR(var_18 + 0x4D) << 5), CHR_SIZE);
    }
}

struct ManimSomethingProc_08067CF8
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2E);
    /* 2E */ i16 actor_id;
    /* 30 */ u8 next_stat_num;
    /* 31 */ u8 clock;
    /* 32 */ i16 y_scroll_offset;
};

void func_fe6_08067D2C(void);
void func_fe6_08067E50(void);
void func_fe6_08067E84(struct ManimSomethingProc_08067CF8 * proc);
void func_fe6_080680F0(struct ManimSomethingProc_08067CF8 * proc);
void func_fe6_08068164(struct ManimSomethingProc_08067CF8 * proc);
void func_fe6_080681D8(struct ManimSomethingProc_08067CF8 * proc);
void func_fe6_08068318(struct ManimSomethingProc_08067CF8 * proc);
void func_fe6_08068338(struct ManimSomethingProc_08067CF8 * proc);
void func_fe6_080684A4(struct ManimSomethingProc_08067CF8 * proc);
void func_fe6_080684B8(struct ManimSomethingProc_08067CF8 * proc);
void func_fe6_080684D8(struct ManimSomethingProc_08067CF8 * proc);

struct ProcScr CONST_DATA ProcScr_Unk_086655C4[] =
{
    PROC_ONEND(func_fe6_080684D8),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08067D2C),
    PROC_CALL(func_fe6_08068318),
    PROC_SLEEP(0),
    PROC_CALL(func_fe6_08068338),
    PROC_SLEEP(70),
    PROC_CALL(func_fe6_080684A4),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_080684B8),
    PROC_SLEEP(0),
    PROC_CALL(func_fe6_08067E84),
    PROC_SLEEP(0),
    PROC_REPEAT(func_fe6_080680F0),
    PROC_SLEEP(30),
    PROC_REPEAT(func_fe6_080681D8),
    PROC_SLEEP(60),
    PROC_CALL(func_fe6_08067AF0),
    PROC_SLEEP(1),
    PROC_REPEAT(func_fe6_08068164),
    PROC_CALL(func_fe6_08067E50),
    PROC_CALL(ClearTalk),
    PROC_SLEEP(4),
    PROC_END,
};

void func_fe6_08067CF8(int actor_id, ProcPtr parent)
{
    struct ManimSomethingProc_08067CF8 * proc;

    proc = SpawnProcLocking(ProcScr_Unk_086655C4, parent);
    proc->actor_id = actor_id;
}

void func_fe6_08067D2C(void)
{
    SetWinEnable(1, 0, 0);
    SetWin0Box(0, 0, 240, 48);
    SetWin0Layers(0, 0, 1, 1, 1);
    SetWOutLayers(1, 1, 1, 1, 1);
}

void func_fe6_08067E50(void)
{
    SetWinEnable(0, 0, 0);
}

void func_fe6_08067E84(struct ManimSomethingProc_08067CF8 * proc)
{
    int i;

    ResetTextFont();
    TmFill(gBg0Tm, 0);
    func_fe6_080675AC(proc->actor_id, 1, 1);

    for (i = 0; i < 9; i++)
    {
        MALevelUp_DrawActorStat(proc->actor_id, 1, 1, i, FALSE);
    }

    EnableBgSync(BG0_SYNC_BIT);

    proc->next_stat_num = 0;
    proc->clock = 0;
    proc->y_scroll_offset = -144;

    gDispIo.bg0_ct.priority = 0;
    gDispIo.bg1_ct.priority = 1;
    gDispIo.bg2_ct.priority = 1;
    gDispIo.bg3_ct.priority = 2;

    SetBlendNone();
    SetWinEnable(0, 0, 0);

    SetBgOffset(0, 0, proc->y_scroll_offset);
    SetBgOffset(1, 0, proc->y_scroll_offset);

    StartFace(0, gMapAnimSt.actor[proc->actor_id].unit->pinfo->fid, 184, 80, FACE_DISP_KIND(FACE_96x80) | FACE_DISP_HLAYER(1));
    gFaces[0]->y_disp = -proc->y_scroll_offset;

    // TODO: constants
    func_fe6_08067A28(0x200, 3, 1, proc);
}

void func_fe6_08068048(struct ManimSomethingProc_08067A28_B * proc)
{
    proc->unk_54 = 0;
}

void func_fe6_08068060(struct ManimSomethingProc_08067A28_B * proc)
{
    int var_04;

    u16 const * var_08 = gUnk_082DB6E8;

    proc->unk_54++;

    if ((proc->unk_54 % 4) != 0)
        return;
    {
        var_04 = (proc->unk_54 >> 2) & 0xF;

        // TODO: constants
        ApplyPaletteExt(var_08 + var_04 + 0x00, (0x10 + proc->unk_64 + 0) * 0x20 + 0x12, 0x0E);
        ApplyPaletteExt(var_08 + var_04 + 0x20, (0x10 + proc->unk_64 + 1) * 0x20 + 0x12, 0x0E);
    }
}

void func_fe6_080680F0(struct ManimSomethingProc_08067CF8 * proc)
{
    proc->y_scroll_offset += 8;

    SetBgOffset(0, 0, proc->y_scroll_offset);
    SetBgOffset(1, 0, proc->y_scroll_offset);

    // NOTE: this is inconsistent with math in func_fe6_08067E84
    gFaces[0]->y_disp = 32 - proc->y_scroll_offset;

    if (proc->y_scroll_offset >= -48)
        Proc_Break(proc);
}

void func_fe6_08068164(struct ManimSomethingProc_08067CF8 * proc)
{
    proc->y_scroll_offset -= 8;

    SetBgOffset(0, 0, proc->y_scroll_offset);
    SetBgOffset(1, 0, proc->y_scroll_offset);

    // NOTE: this is inconsistent with math in func_fe6_08067E84
    gFaces[0]->y_disp = 32 - proc->y_scroll_offset;

    if (proc->y_scroll_offset <= -144)
        Proc_Break(proc);
}

void func_fe6_080681D8(struct ManimSomethingProc_08067CF8 * proc)
{
    int stat_num;

    if (proc->clock != 0)
    {
        proc->clock--;
        return;
    }

    for (stat_num = proc->next_stat_num; stat_num < 9; stat_num++)
    {
        if (MALevelUp_GetActorStatUp(proc->actor_id, stat_num) != 0)
            break;
    }

    if (stat_num >= 9)
    {
        Proc_Break(proc);
        return;
    }

    MALevelUp_DrawActorStat(proc->actor_id, 1, 1, stat_num, TRUE);
    EnableBgSync(BG0_SYNC_BIT);

    func_fe6_08067B08(
        gManimLevelUpLabelInfoList[stat_num].x * 8 + 62,
        gManimLevelUpLabelInfoList[stat_num].y * 8 + 23 - proc->y_scroll_offset,
        stat_num, MALevelUp_GetActorStatUp(proc->actor_id, stat_num));

    PlaySe(SONG_76);

    proc->next_stat_num = stat_num + 1;
    proc->clock = 20;
}

void func_fe6_08068318(struct ManimSomethingProc_08067CF8 * proc)
{
    StartBgmVolumeChange(0x100, 0x80, 0x10, proc);
}

void func_fe6_08068338(struct ManimSomethingProc_08067CF8 * proc)
{
    int x, y;

    Decompress(gUnk_082DB8B0, (void *) OBJ_VRAM0 + OBJCHR_MANIM_1C0 * CHR_SIZE);
    ApplyPalettes(gUnk_082DBAC4, 0x10 + OBJPAL_MANIM_3, 3);

    x = SCREEN_TILE_X(gMapAnimSt.actor[proc->actor_id].unit->x) * 8 + 16;
    y = SCREEN_TILE_Y(gMapAnimSt.actor[proc->actor_id].unit->y) * 8 - 8;

    if (SCREEN_TILE_Y(gMapAnimSt.actor[proc->actor_id].unit->y) < 4)
        y = y + 32;

    if (SCREEN_TILE_X(gMapAnimSt.actor[proc->actor_id].unit->x) < 4)
        x = 48;

    if (SCREEN_TILE_X(gMapAnimSt.actor[proc->actor_id].unit->x) > 25)
        x = 208;

    StartSpriteAnimProc(gUnk_082A7CBC, x, y, OAM2_CHR(OBJCHR_MANIM_1C0) + OAM2_PAL(OBJPAL_MANIM_3), 0, 2);
    PlaySe(SONG_5B);
}

void func_fe6_080684A4(struct ManimSomethingProc_08067CF8 * proc)
{
    EndEachSpriteAnimProc();
}

void func_fe6_080684B8(struct ManimSomethingProc_08067CF8 * proc)
{
    StartBgmVolumeChange(0x80, 0x100, 0x10, proc);
}

void func_fe6_080684D8(struct ManimSomethingProc_08067CF8 * proc)
{
    ClearTalk();
}

void func_fe6_08068524(ProcPtr proc);

struct ProcScr CONST_DATA ProcScr_Unk_08665684[] =
{
    PROC_CALL(func_fe6_08068524),
    PROC_SLEEP(15),
    PROC_END,
};

void func_fe6_080684EC(ProcPtr parent)
{
    if (parent != NULL)
        SpawnProcLocking(ProcScr_Unk_08665684, parent);
    else
        SpawnProc(ProcScr_Unk_08665684, PROC_TREE_3);
}

void func_fe6_08068524(ProcPtr proc)
{
    int i;

    CpuFastCopy(gPal + 0x10 * BGPAL_TILESET, gUnk_03004750, 10 * 0x20);

    for (i = 0; i < 10; i++)
    {
        SetPalFadeStop(StartPalFade(Pal_AllBlack, BGPAL_TILESET + i, 60, proc), 15);
    }
}

void func_fe6_080685B0(ProcPtr proc);

struct ProcScr CONST_DATA ProcScr_Unk_0866569C[] =
{
    PROC_CALL(func_fe6_080685B0),
    PROC_SLEEP(16),
    PROC_END,
};

void func_fe6_08068578(ProcPtr parent)
{
    if (parent != NULL)
        SpawnProcLocking(ProcScr_Unk_0866569C, parent);
    else
        SpawnProc(ProcScr_Unk_0866569C, PROC_TREE_3);
}

void func_fe6_080685B0(ProcPtr proc)
{
    int i;

    for (i = 0; i < 10; i++)
    {
        StartPalFade(gUnk_03004750 + i * 0x10, BGPAL_TILESET + i, 15, proc);
    }
}

struct ManimSomethingProc_080685F0
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x64);
    /* 64 */ i16 unk_64;
};

void func_fe6_08068608(struct ManimSomethingProc_080685F0 * proc);
void func_fe6_08068628(struct ManimSomethingProc_080685F0 * proc);

struct ProcScr CONST_DATA ProcScr_Unk_086656B4[] =
{
    PROC_CALL(func_fe6_08068608),
    PROC_REPEAT(func_fe6_08068628),
    PROC_END,
};

void func_fe6_080685F0(void)
{
    SpawnProc(ProcScr_Unk_086656B4, PROC_TREE_3);
}

void func_fe6_08068608(struct ManimSomethingProc_080685F0 * proc)
{
    proc->unk_64 = 0;
}

void func_fe6_08068628(struct ManimSomethingProc_080685F0 * proc)
{
    SetBgOffset(0, DivRem(RandNextB(), 9) - 4, DivRem(RandNextB(), 9) - 4);
    SetBgOffset(1, DivRem(RandNextB(), 9) - 4, DivRem(RandNextB(), 9) - 4);

    if (proc->unk_64++ >= 0x10)
    {
        SetBgOffset(0, 0, 0);
        SetBgOffset(1, 0, 0);
        Proc_Break(proc);
    }
}

void func_fe6_080686D8(void)
{
    Decompress(gUnk_082DD7E8, (void *) OBJ_VRAM0 + OBJCHR_MANIM_1C0 * CHR_SIZE);
    ApplyPalette(gUnk_082DD808, 0x10 + OBJPAL_MANIM_4);
}

void func_fe6_08068704(int x, int y)
{
    if (x < -4)
        return;
    if (x >= DISPLAY_WIDTH - 4)
        return;

    if (y < -4)
        return;
    if (y >= DISPLAY_HEIGHT - 4)
        return;

    PutOamHiRam(OAM1_X(x - 4), OAM0_Y(y - 4), Sprite_8x8, OAM2_CHR(OBJCHR_MANIM_1C0) + OAM2_PAL(OBJPAL_MANIM_4));
}

void func_fe6_0806875C(int x, int y, int radius, int angle)
{
    func_fe6_08068704(
        x + ((radius * SIN_Q12(angle)) >> 12),
        y + ((radius * COS_Q12(angle)) >> 12));
}

struct ManimSomethingProc_08068938
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2A);
    /* 2A */ i16 unk_2A;
    /* 2C */ i16 unk_2C;
    /* 2E */ i16 unk_2E;
    /* 30 */ i16 unk_30;
    /* 32 */ STRUCT_PAD(0x32, 0x36);
    /* 36 */ u16 unk_36;
    /* 38 */ u16 unk_38;
    /* 3A */ u16 unk_3A;
    /* 3C */ u16 unk_3C;
    /* 3E */ u16 unk_3E;
    /* 40 */ u16 unk_40;
};

void func_fe6_080687BC(struct ManimSomethingProc_08068938 * proc);
void func_fe6_08068858(struct ManimSomethingProc_08068938 * proc);

struct ProcScr CONST_DATA ProcScr_Unk_086656CC[] =
{
    PROC_CALL(LockGame),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_080687BC),
    PROC_REPEAT(func_fe6_08068858),
    PROC_CALL(UnlockGame),
    PROC_END,
};

void func_fe6_080687BC(struct ManimSomethingProc_08068938 * proc)
{
    int i;

    func_fe6_080686D8();

    for (i = 0; i < 0x10; i++)
    {
        gUnk_030046D0[i].unk_00 = 0x10;
        gUnk_030046D0[i].unk_02 = (i * 16) << 4;
    }

    proc->unk_36 = 0;
    proc->unk_38 = 0;
    proc->unk_3A = proc->unk_3C;
}

void func_fe6_08068858(struct ManimSomethingProc_08068938 * proc)
{
    int i, var_08;

    var_08 = Interpolate(INTERPOLATE_RCUBIC, proc->unk_2E, proc->unk_30, proc->unk_3A, proc->unk_3E) << 4;

    proc->unk_36 = var_08;
    proc->unk_38 = var_08 / 2;

    for (i = 0; i < 0x10; i++)
    {
        func_fe6_0806875C(proc->unk_2A, proc->unk_2C,
            (proc->unk_36 + gUnk_030046D0[i].unk_00) >> 4,
            (proc->unk_38 + gUnk_030046D0[i].unk_02) >> 4);
    }

    proc->unk_3A++;

    if (proc->unk_3A > proc->unk_40)
        Proc_Break(proc);
}

void func_fe6_08068938(int x, int y, int beg_radius, int end_radius, int arg_1C, int arg_20, int arg_24)
{
    struct ManimSomethingProc_08068938 * proc;

    proc = SpawnProc(ProcScr_Unk_086656CC, PROC_TREE_3);

    proc->unk_2A = x;
    proc->unk_2C = y;
    proc->unk_2E = beg_radius;
    proc->unk_30 = end_radius;
    proc->unk_3C = arg_1C;
    proc->unk_3E = arg_20;
    proc->unk_40 = arg_24;
}

void func_fe6_080689F0(int x, int y)
{
    func_fe6_08068938(x, y, 1, 200, 0, 80, 40);
}

void func_fe6_08068A1C(int x, int y)
{
    func_fe6_08068938(x, y, 200, 1, 0, 60, 55);
}

void func_fe6_08068A74(ProcPtr proc);
void func_fe6_08068AA8(ProcPtr proc);
void func_fe6_08068F88(ProcPtr proc);
void func_fe6_08068FD8(ProcPtr proc);
void func_fe6_08069028(ProcPtr proc);
void func_fe6_08069098(ProcPtr proc);
void func_fe6_08069504(ProcPtr proc);
void func_fe6_08069530(ProcPtr proc);
void func_fe6_08069560(ProcPtr proc);
void func_fe6_08069590(ProcPtr proc);
void func_fe6_080695C0(ProcPtr proc);
void func_fe6_080695F0(ProcPtr proc);
void func_fe6_0806962C(ProcPtr proc);
void func_fe6_08069668(ProcPtr proc);
void func_fe6_080696A4(ProcPtr proc);
void func_fe6_080696E0(ProcPtr proc);
void func_fe6_0806971C(ProcPtr proc);
void func_fe6_08069758(ProcPtr proc);
void func_fe6_08069794(ProcPtr proc);
void func_fe6_0806984C(ProcPtr proc);
void func_fe6_0806988C(ProcPtr proc);
void func_fe6_080698BC(ProcPtr proc);
void func_fe6_080698E4(ProcPtr proc);
void func_fe6_08069914(ProcPtr proc);
void func_fe6_08069944(ProcPtr proc);
void func_fe6_08069974(ProcPtr proc);
void func_fe6_080699A4(ProcPtr proc);
void func_fe6_080699D8(ProcPtr proc);
void func_fe6_08069A0C(ProcPtr proc);
void func_fe6_08069A40(ProcPtr proc);
void func_fe6_08069AB4(ProcPtr proc);
void func_fe6_08069B3C(ProcPtr proc);
void func_fe6_08069B70(ProcPtr proc);
void func_fe6_08069C04(ProcPtr proc);
void func_fe6_08069C1C(ProcPtr proc);

struct ProcScr CONST_DATA ProcScr_Unk_086656FC[] =
{
    PROC_CALL(func_fe6_08068C84),
    PROC_CALL(func_fe6_08068E80),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08068E80),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08068E80),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08068E80),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08068FD8),
    PROC_SLEEP(2),
    PROC_CALL(func_fe6_08069098),
    PROC_SLEEP(8),
    PROC_REPEAT(func_fe6_08069504),
    PROC_CALL(func_fe6_08068F04),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08068F04),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08068F04),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08068F04),
    PROC_SLEEP(20),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_086657B4[] =
{
    PROC_CALL(DisableTilesetPalAnim),
    PROC_CALL(func_fe6_08069C04),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08068A74),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_080695C0),
    PROC_SLEEP(2),
    PROC_SLEEP(200),
    PROC_SLEEP(10),
    PROC_CALL(func_fe6_08068AA8),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_08069C1C),
    PROC_SLEEP(1),
    PROC_CALL(EnableTilesetPalAnim),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_0866582C[] =
{
    PROC_CALL(func_fe6_08068A74),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_080695F0),
    PROC_SLEEP(2),
    PROC_SLEEP(70),
    PROC_SLEEP(10),
    PROC_CALL(func_fe6_08068AA8),
    PROC_SLEEP(30),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_08665874[] =
{
    PROC_CALL(func_fe6_08068A74),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_0806962C),
    PROC_SLEEP(2),
    PROC_SLEEP(70),
    PROC_SLEEP(10),
    PROC_CALL(func_fe6_08068AA8),
    PROC_SLEEP(30),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_086658BC[] =
{
    PROC_CALL(func_fe6_08068A74),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_08069668),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_08069098),
    PROC_SLEEP(30),
    PROC_REPEAT(func_fe6_08069504),
    PROC_SLEEP(10),
    PROC_CALL(func_fe6_08068AA8),
    PROC_SLEEP(30),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_08665914[] =
{
    PROC_CALL(func_fe6_08068A74),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_08069758),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_08069098),
    PROC_SLEEP(30),
    PROC_REPEAT(func_fe6_08069504),
    PROC_SLEEP(10),
    PROC_CALL(func_fe6_08068AA8),
    PROC_SLEEP(30),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_0866596C[] =
{
    PROC_CALL(func_fe6_08068FD8),
    PROC_SLEEP(2),
    PROC_CALL(func_fe6_08068A74),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_080696A4),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_08069098),
    PROC_SLEEP(30),
    PROC_REPEAT(func_fe6_08069504),
    PROC_SLEEP(10),
    PROC_CALL(func_fe6_08068AA8),
    PROC_SLEEP(30),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_086659D4[] =
{
    PROC_CALL(func_fe6_08068FD8),
    PROC_SLEEP(2),
    PROC_CALL(func_fe6_08068A74),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_080696E0),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_08069098),
    PROC_SLEEP(30),
    PROC_REPEAT(func_fe6_08069504),
    PROC_SLEEP(10),
    PROC_CALL(func_fe6_08068AA8),
    PROC_SLEEP(30),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_08665A3C[] =
{
    PROC_CALL(func_fe6_08068FD8),
    PROC_SLEEP(2),
    PROC_CALL(func_fe6_08068A74),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_0806971C),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_08069098),
    PROC_SLEEP(30),
    PROC_REPEAT(func_fe6_08069504),
    PROC_SLEEP(10),
    PROC_CALL(func_fe6_08068AA8),
    PROC_SLEEP(30),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_08665AA4[] =
{
    PROC_CALL(func_fe6_08068FD8),
    PROC_SLEEP(2),
    PROC_CALL(func_fe6_08068A74),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_080696A4),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_08069098),
    PROC_SLEEP(30),
    PROC_REPEAT(func_fe6_08069504),
    PROC_SLEEP(10),
    PROC_CALL(func_fe6_08068AA8),
    PROC_SLEEP(30),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_08665B0C[] =
{
    PROC_CALL(func_fe6_08068A74),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_0806988C),
    PROC_SLEEP(2),
    PROC_SLEEP(100),
    PROC_SLEEP(10),
    PROC_CALL(func_fe6_08068AA8),
    PROC_SLEEP(30),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_08665B54[] =
{
    PROC_CALL(DisableTilesetPalAnim),
    PROC_CALL(func_fe6_08069C04),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08069028),
    PROC_SLEEP(2),
    PROC_CALL(func_fe6_08068A74),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_080698BC),
    PROC_SLEEP(2),
    PROC_SLEEP(140),
    PROC_SLEEP(10),
    PROC_CALL(func_fe6_08068AA8),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_08069C1C),
    PROC_SLEEP(1),
    PROC_CALL(EnableTilesetPalAnim),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_08665BDC[] =
{
    PROC_CALL(DisableTilesetPalAnim),
    PROC_CALL(func_fe6_08069C04),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08068FD8),
    PROC_SLEEP(2),
    PROC_CALL(func_fe6_08068A74),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_080698E4),
    PROC_SLEEP(2),
    PROC_SLEEP(50),
    PROC_CALL(func_fe6_08069098),
    PROC_SLEEP(30),
    PROC_REPEAT(func_fe6_08069504),
    PROC_SLEEP(10),
    PROC_CALL(func_fe6_08068AA8),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_08069C1C),
    PROC_SLEEP(1),
    PROC_CALL(EnableTilesetPalAnim),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_08665C7C[] =
{
    PROC_CALL(DisableTilesetPalAnim),
    PROC_CALL(func_fe6_08069C04),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08068FD8),
    PROC_SLEEP(2),
    PROC_CALL(func_fe6_08068A74),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_08069944),
    PROC_SLEEP(2),
    PROC_SLEEP(140),
    PROC_CALL(func_fe6_08069098),
    PROC_SLEEP(30),
    PROC_REPEAT(func_fe6_08069504),
    PROC_SLEEP(10),
    PROC_CALL(func_fe6_08068AA8),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_08069C1C),
    PROC_SLEEP(1),
    PROC_CALL(EnableTilesetPalAnim),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_08665D1C[] =
{
    PROC_CALL(DisableTilesetPalAnim),
    PROC_CALL(func_fe6_08069C04),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08068FD8),
    PROC_SLEEP(2),
    PROC_CALL(func_fe6_08068A74),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_08069560),
    PROC_SLEEP(2),
    PROC_SLEEP(64),
    PROC_CALL(func_fe6_08069098),
    PROC_SLEEP(30),
    PROC_REPEAT(func_fe6_08069504),
    PROC_SLEEP(10),
    PROC_CALL(func_fe6_08068AA8),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_08069C1C),
    PROC_SLEEP(1),
    PROC_CALL(EnableTilesetPalAnim),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_08665DBC[] =
{
    PROC_CALL(DisableTilesetPalAnim),
    PROC_CALL(func_fe6_08069C04),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08068FD8),
    PROC_SLEEP(2),
    PROC_CALL(func_fe6_08068A74),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_08069914),
    PROC_SLEEP(2),
    PROC_SLEEP(80),
    PROC_SLEEP(10),
    PROC_CALL(func_fe6_08068AA8),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_08069C1C),
    PROC_SLEEP(1),
    PROC_CALL(EnableTilesetPalAnim),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_08665E44[] =
{
    PROC_CALL(DisableTilesetPalAnim),
    PROC_CALL(func_fe6_08069C04),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08068FD8),
    PROC_SLEEP(2),
    PROC_CALL(func_fe6_08068A74),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_08069974),
    PROC_SLEEP(2),
    PROC_SLEEP(80),
    PROC_SLEEP(10),
    PROC_CALL(func_fe6_08068AA8),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_08069C1C),
    PROC_SLEEP(1),
    PROC_CALL(EnableTilesetPalAnim),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_08665ECC[] =
{
    PROC_CALL(func_fe6_08068FD8),
    PROC_SLEEP(2),
    PROC_CALL(func_fe6_08069530),
    PROC_SLEEP(2),
    PROC_SLEEP(94),
    PROC_SLEEP(10),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_08665F04[] =
{
    PROC_CALL(func_fe6_08068FD8),
    PROC_SLEEP(2),
    PROC_CALL(func_fe6_08069530),
    PROC_SLEEP(2),
    PROC_SLEEP(50),
    PROC_CALL(func_fe6_08069098),
    PROC_SLEEP(30),
    PROC_REPEAT(func_fe6_08069504),
    PROC_SLEEP(44),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_08665F54[] =
{
    PROC_CALL(func_fe6_08068FD8),
    PROC_SLEEP(2),
    PROC_CALL(func_fe6_08069098),
    PROC_SLEEP(30),
    PROC_REPEAT(func_fe6_08069504),
    PROC_SLEEP(20),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_08665F8C[] =
{
    PROC_CALL(DisableTilesetPalAnim),
    PROC_CALL(func_fe6_08069C04),
    PROC_SLEEP(1),
    PROC_CALL(func_fe6_08068FD8),
    PROC_SLEEP(2),
    PROC_CALL(func_fe6_08068A74),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_08069590),
    PROC_SLEEP(2),
    PROC_SLEEP(60),
    PROC_SLEEP(10),
    PROC_CALL(func_fe6_08068AA8),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_08069C1C),
    PROC_SLEEP(1),
    PROC_CALL(EnableTilesetPalAnim),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_08666014[] =
{
    PROC_CALL(func_fe6_08068FD8),
    PROC_SLEEP(2),
    PROC_CALL(func_fe6_08068A74),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_08069794),
    PROC_SLEEP(10),
    PROC_CALL(func_fe6_080699A4),
    PROC_SLEEP(20),
    PROC_CALL(func_fe6_08069A40),
    PROC_SLEEP(2),
    PROC_CALL(func_fe6_08069A0C),
    PROC_SLEEP(8),
    PROC_CALL(func_fe6_08069B70),
    PROC_SLEEP(30),
    PROC_CALL(func_fe6_08069028),
    PROC_SLEEP(2),
    PROC_CALL(func_fe6_08069AB4),
    PROC_SLEEP(40),
    PROC_CALL(func_fe6_0806984C),
    PROC_SLEEP(10),
    PROC_CALL(func_fe6_08069B3C),
    PROC_CALL(func_fe6_080699D8),
    PROC_SLEEP(16),
    PROC_SLEEP(10),
    PROC_CALL(func_fe6_08068F88),
    PROC_SLEEP(2),
    PROC_CALL(func_fe6_08068AA8),
    PROC_SLEEP(30),
    PROC_END,
};

struct ProcScr const * func_fe6_08068A48(void)
{
    if (gMapAnimSt.special_proc_scr == NULL)
        return ProcScr_Unk_086656FC;

    return gMapAnimSt.special_proc_scr;
}

void func_fe6_08068A74(ProcPtr proc)
{
    StartMuActionAnim(gMapAnimSt.actor[gMapAnimSt.attacker_actor].mu);
}

void func_fe6_08068AA8(ProcPtr proc)
{
    StartMuDelayedFaceTarget(gMapAnimSt.actor[gMapAnimSt.attacker_actor].mu);
}

void func_fe6_08068BA8(void);
void func_fe6_08068BE8(void);

void func_fe6_08068ADC(ProcPtr proc)
{
    int unk;

    if (UNIT_JID(gMapAnimSt.actor[gMapAnimSt.attacker_actor].unit) == JID_DANCER)
    {
        CallDelayed(func_fe6_08068BA8, 9);
    }
    else
    {
        CallDelayed(func_fe6_08068BE8, 12);
    }

    ResetSpriteAnimClock(gMapAnimSt.actor[gMapAnimSt.attacker_actor].mu->sprite_anim);
    SetSpriteAnimId(gMapAnimSt.actor[gMapAnimSt.attacker_actor].mu->sprite_anim, 5);
}

void func_fe6_08068BA8(void)
{
    PlaySeSpacial(SONG_A8, gMapAnimSt.actor[gMapAnimSt.attacker_actor].unit->x * 16 - gBmSt.camera.x);
}

void func_fe6_08068BE8(void)
{
    PlaySeSpacial(SONG_A9, gMapAnimSt.actor[gMapAnimSt.attacker_actor].unit->x * 16 - gBmSt.camera.x);
}

void func_fe6_08068C28(ProcPtr proc)
{
    FreezeSpriteAnim(gMapAnimSt.actor[gMapAnimSt.attacker_actor].mu->sprite_anim);
}

void func_fe6_08068C84(ProcPtr proc)
{
    StartMuSlowDownAnim(gMapAnimSt.actor[gMapAnimSt.attacker_actor].mu);
}

void func_fe6_08068CB8(struct MuProc * mu_a, struct MuProc * mu_b)
{
    mu_a->x_q4 += mu_b->x_q4 - mu_a->x_q4 <= 0 ? (mu_b->x_q4 - mu_a->x_q4 < 0 ? -0x10 : 0) : +0x10;
    mu_a->y_q4 += mu_b->y_q4 - mu_a->y_q4 <= 0 ? (mu_b->y_q4 - mu_a->y_q4 < 0 ? -0x10 : 0) : +0x10;
}

void func_fe6_08068D9C(struct MuProc * mu_a, struct MuProc * mu_b)
{
    mu_a->x_q4 += mu_a->x_q4 - mu_b->x_q4 <= 0 ? (mu_a->x_q4 - mu_b->x_q4 < 0 ? -0x10 : 0) : +0x10;
    mu_a->y_q4 += mu_a->y_q4 - mu_b->y_q4 <= 0 ? (mu_a->y_q4 - mu_b->y_q4 < 0 ? -0x10 : 0) : +0x10;
}

void func_fe6_08068E80(ProcPtr proc)
{
    struct MuProc * attacker_mu = gMapAnimSt.actor[gMapAnimSt.attacker_actor].mu;
    struct MuProc * defender_mu = gMapAnimSt.actor[gMapAnimSt.defender_actor].mu;

    func_fe6_08068CB8(attacker_mu, defender_mu);

    if (gMapAnimSt.hit_attributes & BATTLE_HIT_ATTR_TATTACK)
    {
        attacker_mu = gMapAnimSt.actor[2].mu;
        func_fe6_08068CB8(attacker_mu, defender_mu);

        attacker_mu = gMapAnimSt.actor[3].mu;
        func_fe6_08068CB8(attacker_mu, defender_mu);
    }
}

void func_fe6_08068F04(ProcPtr proc)
{
    struct MuProc * attacker_mu = gMapAnimSt.actor[gMapAnimSt.attacker_actor].mu;
    struct MuProc * defender_mu = gMapAnimSt.actor[gMapAnimSt.defender_actor].mu;

    func_fe6_08068D9C(attacker_mu, defender_mu);

    if ((gMapAnimSt.hit_attributes & BATTLE_HIT_ATTR_TATTACK) != 0)
    {
        attacker_mu = gMapAnimSt.actor[2].mu;
        func_fe6_08068D9C(attacker_mu, defender_mu);

        attacker_mu = gMapAnimSt.actor[3].mu;
        func_fe6_08068D9C(attacker_mu, defender_mu);
    }
}

void func_fe6_08068F88(ProcPtr proc)
{
    CameraMoveWatchPosition(proc,
        gMapAnimSt.actor[gMapAnimSt.attacker_actor].unit->x,
        gMapAnimSt.actor[gMapAnimSt.attacker_actor].unit->y);
}

void func_fe6_08068FD8(ProcPtr proc)
{
    CameraMoveWatchPosition(proc,
        gMapAnimSt.actor[gMapAnimSt.defender_actor].unit->x,
        gMapAnimSt.actor[gMapAnimSt.defender_actor].unit->y);
}

void func_fe6_08069028(ProcPtr proc)
{
    // ???
    gMapAnimSt.unk_60 = gBattleUnitB.change_hp;
    gMapAnimSt.unk_61 = gBattleUnitB.change_pow;

    CameraMoveWatchPosition(proc, gMapAnimSt.unk_60, gMapAnimSt.unk_61);
}

void func_fe6_08069098(ProcPtr proc)
{
    int hit_song;
    int attacker_actor, defender_actor;
    int is_obstacle;

    attacker_actor = gMapAnimSt.attacker_actor;

    if ((gMapAnimSt.hit_attributes & BATTLE_HIT_ATTR_DEVIL) != 0)
        defender_actor = gMapAnimSt.attacker_actor;
    else
        defender_actor = gMapAnimSt.defender_actor;

    if (func_fe6_0805F7B4(gMapAnimSt.actor[attacker_actor].bu->weapon_before) == 0)
    {
        if ((gMapAnimSt.hit_attributes & BATTLE_HIT_ATTR_MISS) != 0)
            func_fe6_08064994(gMapAnimSt.actor[defender_actor].unit);

        return;
    }

    gMapAnimSt.unk_5F = 1;

    func_fe6_08069430(defender_actor, gMapAnimSt.hit_damage);

    if ((gMapAnimSt.hit_attributes & BATTLE_HIT_ATTR_HPSTEAL) != 0)
        func_fe6_08069430(attacker_actor, -gMapAnimSt.hit_damage);

    if (gMapAnimSt.hit_damage < 0)
        return;

    if ((gMapAnimSt.hit_attributes & BATTLE_HIT_ATTR_MISS) != 0)
    {
        PlaySeSpacial(SONG_C8, gMapAnimSt.actor[defender_actor].unit->x * 16 - gBmSt.camera.x);
        func_fe6_08064994(gMapAnimSt.actor[defender_actor].unit);
        return;
    }

    if (gMapAnimSt.hit_damage == 0)
    {
        PlaySeSpacial(SONG_EC, gMapAnimSt.actor[defender_actor].unit->x * 16 - gBmSt.camera.x);
        func_fe6_08064A10(gMapAnimSt.actor[defender_actor].unit);
        return;
    }

    is_obstacle = gMapAnimSt.actor[defender_actor].bu->terrain == TERRAIN_WALL_1B ? TRUE : FALSE;

    if (is_obstacle)
    {
        if ((gMapAnimSt.hit_info & BATTLE_HIT_INFO_FINISHES) != 0)
        {
            hit_song = SONG_AF;
            func_fe6_08064A8C(gMapAnimSt.actor[defender_actor].unit, TRUE);
        }
        else
        {
            hit_song = SONG_B0;
            func_fe6_08064A8C(gMapAnimSt.actor[defender_actor].unit, FALSE);
        }
    }
    else
    {
        if ((gMapAnimSt.hit_info & BATTLE_HIT_INFO_FINISHES) != 0)
        {
            hit_song = SONG_D5;
        }
        else
        {
            hit_song = SONG_D2;
        }
    }

    if ((gMapAnimSt.hit_attributes & BATTLE_HIT_ATTR_CRIT) != 0)
    {
        PlaySeSpacial(hit_song, gMapAnimSt.actor[defender_actor].unit->x * 16 - gBmSt.camera.x);
        func_fe6_0806142C(gMapAnimSt.actor[defender_actor].mu, func_fe6_0805F7D4(gMapAnimSt.actor[attacker_actor].bu->weapon_before));
        func_fe6_080685F0();
        PlaySeSpacial(SONG_D8, gMapAnimSt.actor[defender_actor].unit->x * 16 - gBmSt.camera.x);
        StartMuSlowDownAnim(gMapAnimSt.actor[attacker_actor].mu);
    }
    else
    {
        PlaySeSpacial(hit_song, gMapAnimSt.actor[defender_actor].unit->x * 16 - gBmSt.camera.x);
        StartMuFlashFadeFrom(gMapAnimSt.actor[defender_actor].mu, func_fe6_0805F7D4(gMapAnimSt.actor[attacker_actor].bu->weapon_before));
    }
}

void func_fe6_08069430(int actor_id, int damage)
{
    if (gMapAnimSt.actor[actor_id].hp_cur <= damage)
        gMapAnimSt.actor[actor_id].hp_cur = 0;
    else
        gMapAnimSt.actor[actor_id].hp_cur -= damage;

    if (gMapAnimSt.actor[actor_id].hp_cur > gMapAnimSt.actor[actor_id].hp_max)
        gMapAnimSt.actor[actor_id].hp_cur = gMapAnimSt.actor[actor_id].hp_max;
}

void func_fe6_08069504(ProcPtr proc)
{
    if (gMapAnimSt.unk_5F != 0)
        return;

    Proc_Break(proc);
}

void func_fe6_08069530(ProcPtr proc)
{
    func_fe6_08064B7C(gMapAnimSt.actor[gMapAnimSt.defender_actor].unit);
}

void func_fe6_08069560(ProcPtr proc)
{
    func_fe6_08066AD4(gMapAnimSt.actor[gMapAnimSt.defender_actor].unit);
}

void func_fe6_08069590(ProcPtr proc)
{
    func_fe6_08066DFC(gMapAnimSt.actor[gMapAnimSt.defender_actor].unit);
}

void func_fe6_080695C0(ProcPtr proc)
{
    func_fe6_08064C50(gMapAnimSt.actor[gMapAnimSt.attacker_actor].unit);
}

void func_fe6_080695F0(ProcPtr proc)
{
    func_fe6_080653BC(gMapAnimSt.actor[gMapAnimSt.attacker_actor].unit, gUnk_082DD848, gUnk_082DE974);
}

void func_fe6_0806962C(ProcPtr proc)
{
    func_fe6_080653BC(gMapAnimSt.actor[gMapAnimSt.attacker_actor].unit, gUnk_082DD848, gUnk_082DE954);
}

extern u8 const gUnk_082DED00[]; // img
extern u8 const gUnk_082DE994[]; // img
extern u8 const gUnk_082DEB08[]; // pal

void func_fe6_08069668(ProcPtr proc)
{
    func_fe6_08065694(gMapAnimSt.actor[gMapAnimSt.defender_actor].unit, gUnk_082DED00, gUnk_082DEFBC, SONG_8B);
}

void func_fe6_080696A4(ProcPtr proc)
{
    func_fe6_08065694(gMapAnimSt.actor[gMapAnimSt.defender_actor].unit, gUnk_082DE994, gUnk_082DEFBC, SONG_89);
}

void func_fe6_080696E0(ProcPtr proc)
{
    func_fe6_08065694(gMapAnimSt.actor[gMapAnimSt.defender_actor].unit, gUnk_082DEB08, gUnk_082DEFBC, SONG_8A);
}

void func_fe6_0806971C(ProcPtr proc)
{
    func_fe6_08065694(gMapAnimSt.actor[gMapAnimSt.defender_actor].unit, gUnk_082DED00, gUnk_082DEFBC, SONG_8B);
}

void func_fe6_08069758(ProcPtr proc)
{
    func_fe6_08065694(gMapAnimSt.actor[gMapAnimSt.defender_actor].unit, gUnk_082DE994, gUnk_082DEFBC, SONG_89);
}

void func_fe6_08069794(ProcPtr proc)
{
    PlaySe(SONG_B4);

    // ???
    gMapAnimSt.unk_60 = gBattleUnitB.change_hp;
    gMapAnimSt.unk_61 = gBattleUnitB.change_pow;

    func_fe6_08065C30(
        gMapAnimSt.actor[gMapAnimSt.defender_actor].unit,
        gMapAnimSt.actor[gMapAnimSt.defender_actor].unit->x,
        gMapAnimSt.actor[gMapAnimSt.defender_actor].unit->y);
}

void func_fe6_0806984C(ProcPtr proc)
{
    func_fe6_08065C30(gMapAnimSt.actor[gMapAnimSt.defender_actor].unit,
        gMapAnimSt.unk_60, gMapAnimSt.unk_61);
}

void func_fe6_0806988C(ProcPtr proc)
{
    func_fe6_08065E08(gMapAnimSt.actor[gMapAnimSt.attacker_actor].unit);
}

void func_fe6_080698BC(ProcPtr proc)
{
    func_fe6_08066FD8(gMapAnimSt.unk_60, gMapAnimSt.unk_61);
}

void func_fe6_080698E4(ProcPtr proc)
{
    func_fe6_080661A4(gMapAnimSt.actor[gMapAnimSt.defender_actor].unit);
}

void func_fe6_08069914(ProcPtr proc)
{
    func_fe6_080665E4(gMapAnimSt.actor[gMapAnimSt.defender_actor].unit);
}

void func_fe6_08069944(ProcPtr proc)
{
    func_fe6_0806671C(gMapAnimSt.actor[gMapAnimSt.defender_actor].unit);
}

void func_fe6_08069974(ProcPtr proc)
{
    func_fe6_08066294(gMapAnimSt.actor[gMapAnimSt.defender_actor].unit);
}

void func_fe6_080699A4(ProcPtr proc)
{
    StartMuFadeIntoFlash(gMapAnimSt.actor[gMapAnimSt.defender_actor].mu, MU_FLASH_WHITE);
}

void func_fe6_080699D8(ProcPtr proc)
{
    StartMuFadeFromFlash(gMapAnimSt.actor[gMapAnimSt.defender_actor].mu);
}

void func_fe6_08069A0C(ProcPtr proc)
{
    HideMu(gMapAnimSt.actor[gMapAnimSt.defender_actor].mu);
}

void func_fe6_08069A40(ProcPtr proc)
{
    func_fe6_080689F0(
        gMapAnimSt.actor[gMapAnimSt.defender_actor].unit->x * 16 - gBmSt.camera.x + 8,
        gMapAnimSt.actor[gMapAnimSt.defender_actor].unit->y * 16 - gBmSt.camera.y + 8);
}

void func_fe6_08069AB4(ProcPtr proc)
{
    PlaySe(SONG_B5);

    func_fe6_08068A1C(
        gMapAnimSt.actor[gMapAnimSt.defender_actor].unit->x * 16 - gBmSt.camera.x + 8,
        gMapAnimSt.actor[gMapAnimSt.defender_actor].unit->y * 16 - gBmSt.camera.y + 8);
}

void func_fe6_08069B3C(ProcPtr proc)
{
    ShowMu(gMapAnimSt.actor[gMapAnimSt.defender_actor].mu);
}

void func_fe6_08069B70(ProcPtr proc)
{
    struct Unit * unit = gMapAnimSt.actor[gMapAnimSt.defender_actor].unit;

    SetMuScreenPosition(gMapAnimSt.actor[gMapAnimSt.defender_actor].mu,
        gMapAnimSt.unk_60 * 16, gMapAnimSt.unk_61 * 16);

    unit->x = gMapAnimSt.unk_60;
    unit->y = gMapAnimSt.unk_61;
}

void func_fe6_08069C04(ProcPtr proc)
{
    func_fe6_080684EC(proc);
}

void func_fe6_08069C1C(ProcPtr proc)
{
    func_fe6_08068578(proc);
}

void func_fe6_08069C34(void)
{
    func_fe6_0806A44C(gUnk_0203CE48);
    func_fe6_0806A44C(gUnk_0203D0C8);

    gUnk_0203D348[0] = gUnk_0203CE48;
    gUnk_0203D348[1] = gUnk_0203D0C8;
    gUnk_0203D350 = gUnk_0203D348[0];
}

void func_fe6_08069DE8(void);

void func_fe6_08069C74(void)
{
    SetWinEnable(1, 0, 0);
    SetWin0Box(0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT);
    SetWin0Layers(0, 0, 0, 0, 0);
    SetWOutLayers(1, 1, 1, 1, 1);
    SetOnHBlankA(func_fe6_08069DE8);
}

void func_fe6_08069DA4(int x, int y, int arg_08)
{
    func_fe6_0806A44C(gUnk_0203D348[1]);
    func_fe6_0806A51C(gUnk_0203D348[1], x, y, arg_08);
    func_fe6_0806A424();
}

void func_fe6_08069DD8(void)
{
    SetOnHBlankA(NULL);
}

void func_fe6_08069DE8(void)
{
    u16 vcount = REG_VCOUNT;

    if (vcount >= DISPLAY_HEIGHT)
    {
        gUnk_0203D350 = gUnk_0203D348[0];
        vcount = 0;
    }
    else
    {
        vcount++;
    }

    REG_WIN0H = gUnk_0203D350[vcount];
}

void func_fe6_08069E50(void)
{
    u16 vcount = REG_VCOUNT;

    if (vcount >= DISPLAY_HEIGHT)
    {
        gUnk_0203D350 = gUnk_0203D348[0];
        vcount = 0;
    }
    else
    {
        vcount++;
    }

    REG_WIN0H = gUnk_0203D350[vcount];
    REG_BG2HOFS = gUnk_0203D350[DISPLAY_HEIGHT + vcount];
}

void func_fe6_08069ED4(void)
{
    u16 vcount = REG_VCOUNT;

    if (vcount >= DISPLAY_HEIGHT)
    {
        gUnk_0203D350 = gUnk_0203D348[0];
        vcount = 0;
    }
    else
    {
        vcount++;
    }

    // TODO: better constants
    ((u16 volatile *) PLTT)[0x10 * 1 + 1] = gUnk_0203D350[vcount];
    ((u16 volatile *) PLTT)[0x10 * 2 + 1] = gUnk_0203D350[DISPLAY_HEIGHT + vcount];
}

void func_fe6_08069F58(void)
{
    u16 vcount = REG_VCOUNT;

    if (vcount >= DISPLAY_HEIGHT)
    {
        gUnk_0203D350 = gUnk_0203D348[0];
        vcount = 0;
    }
    else
    {
        vcount++;
    }

    // TODO: better constants
    ((u16 volatile *) PLTT)[0x10 * 0x19 + 4] = gUnk_0203D350[vcount];
    ((u16 volatile *) PLTT)[0x10 * 0x1D + 4] = gUnk_0203D350[vcount];
}

void func_fe6_08069FD8(void)
{
    u16 vcount = REG_VCOUNT;

    if (vcount >= DISPLAY_HEIGHT)
    {
        gUnk_0203D350 = gUnk_0203D348[0];
        vcount = 0;
    }
    else
    {
        vcount++;
    }

    REG_BLDALPHA = gUnk_0203D350[vcount];
}

void func_fe6_0806A040(void)
{
    u16 vcount = REG_VCOUNT;

    if (vcount >= DISPLAY_HEIGHT)
    {
        gUnk_0203D350 = gUnk_0203D348[0];
        vcount = 0;
    }
    else
    {
        vcount++;
    }

    REG_BG0VOFS = gUnk_0203D350[vcount];
    REG_BG0HOFS = gUnk_0203D350[vcount];
    REG_BG1VOFS = gUnk_0203D350[DISPLAY_HEIGHT + vcount];
}

void func_fe6_0806A0DC(u16 arg_0, u16 arg_1, u16 color_2, u16 color_3)
{
    #define RGB_HALVED(color, component_mask) \
        ((((component_mask) & (color)) >> 1) & (component_mask))

    func_fe6_0806A600(gUnk_0203D348[1], arg_0, arg_1, color_2,
        RGB_HALVED(color_2, 0x1F) | RGB_HALVED(color_2, 0x1F << 5) | RGB_HALVED(color_2, 0x1F << 10));
    func_fe6_0806A600(gUnk_0203D348[1] + DISPLAY_HEIGHT, arg_0, arg_1, color_3,
        RGB_HALVED(color_3, 0x1F) | RGB_HALVED(color_3, 0x1F << 5) | RGB_HALVED(color_3, 0x1F << 10));
    func_fe6_0806A424();

    SetOnHBlankA(func_fe6_08069ED4);

    #undef RGB_HALVED
}

void func_fe6_0806A218(u16 yStart, u16 yEnd, u16 arg_2, u16 arg_3)
{
    func_fe6_0806A600(gUnk_0203D348[1], yStart, yEnd, arg_2, arg_3);
    func_fe6_0806A424();

    SetOnHBlankA(func_fe6_08069F58);
}

void func_fe6_0806A270(int x, int y, int a, int b, u8 const * unk)
{
    int var_10;

    func_fe6_0806A44C(gUnk_0203D348[1]);

    while (*unk != 0xFF && y >= 0)
    {
        var_10 = Div(*unk * a, b);
        unk++;

        if (var_10 > 0)
        {
            func_fe6_0806A4D4(gUnk_0203D348[1], x + var_10 - 1, y);
            func_fe6_0806A488(gUnk_0203D348[1], x - var_10, y);
        }

        y--;
    }

    if (var_10 > 0)
    {
        while (y >= 0)
        {
            func_fe6_0806A4D4(gUnk_0203D348[1], x + var_10 - 1, y);
            func_fe6_0806A488(gUnk_0203D348[1], x - var_10, y);
            y--;
        }
    }
}

void func_fe6_0806A330(u16 * buf, fi16 phase, fi16 amplitude, fi16 frequence)
{
    int i;

    for (i = 0; i < DISPLAY_HEIGHT; i++)
    {
        *buf++ = (SIN_Q12(i * frequence + phase) * amplitude) >> 12;
    }
}

void func_fe6_0806A3A8(u16 * buf, fi16 phase, fi16 amplitude, fi16 frequence, int y_start, int y_end)
{
    int i;

    for (i = y_start; i < y_end; i++)
    {
        *buf++ = (SIN_Q12(i * frequence + phase) * amplitude) >> 12;
    }
}

void func_fe6_0806A424(void)
{
    u16 * tmp = gUnk_0203D348[0];
    gUnk_0203D348[0] = gUnk_0203D348[1];
    gUnk_0203D348[1] = tmp;
}

void func_fe6_0806A44C(u16 * buf)
{
    int i;
    u16 * it = buf;

    for (i = 0; i < DISPLAY_HEIGHT; i++)
    {
        // TODO: WINH macro?
        *it++ = DISPLAY_WIDTH | (DISPLAY_WIDTH << 8);
    }
}

void func_fe6_0806A488(u16 * buf, int x, int y)
{
    if (x < 0)
        x = 0;

    if (x > DISPLAY_WIDTH - 1)
        x = DISPLAY_WIDTH - 1;

    if (y < 0 || y > DISPLAY_HEIGHT - 1)
        return;

    // TODO: better? (WINH right)
    ((u8 *) (buf + y))[1] = x;
}

void func_fe6_0806A4D4(u16 * buf, int x, int y)
{
    if (x < 0)
        x = 0;

    if (x > DISPLAY_WIDTH - 1)
        x = DISPLAY_WIDTH - 1;

    if (y < 0 || y > DISPLAY_HEIGHT - 1)
        return;

    // TODO: better? (WINH left)
    ((u8 *) (buf + y))[0] = x;
}

void func_fe6_0806A51C(u16 * buf, int x, int y, int arg_0C)
{
    int var_10, i;

    var_10 = arg_0C;

    for (i = 0; var_10 >= i; i++)
    {
        func_fe6_0806A4D4(buf, x + var_10, y + i);
        func_fe6_0806A4D4(buf, x + var_10, y - i);
        func_fe6_0806A4D4(buf, x + i, y + var_10);
        func_fe6_0806A4D4(buf, x + i, y - var_10);

        func_fe6_0806A488(buf, x - var_10, y + i);
        func_fe6_0806A488(buf, x - var_10, y - i);
        func_fe6_0806A488(buf, x - i, y + var_10);
        func_fe6_0806A488(buf, x - i, y - var_10);

        arg_0C -= (i << 1) - 1;

        if (arg_0C < 0)
        {
            arg_0C = arg_0C + ((var_10 - 1) << 1);
            var_10 = var_10 - 1;
        }
    }
}

void func_fe6_0806A600(u16 * buf, u16 arg_04, u16 arg_06, u16 arg_08, u16 arg_0A)
{
    int var_0C, var_10, r, g, b, var_20;

    var_20 = arg_06 - arg_04;
    var_10 = 0;

    for (var_0C = 0; var_0C < DISPLAY_HEIGHT; var_0C++)
    {
        if (var_0C < arg_04)
        {
            *buf++ = arg_08;
            continue;
        }

        if (var_0C > arg_06)
        {
            *buf++ = arg_0A;
            continue;
        }

        // TODO: RGB color mask constants

        r = Interpolate(INTERPOLATE_LINEAR, arg_08 & 0x001F, arg_0A & 0x001F, var_10, var_20);
        g = Interpolate(INTERPOLATE_LINEAR, arg_08 & 0x03E0, arg_0A & 0x03E0, var_10, var_20);
        b = Interpolate(INTERPOLATE_LINEAR, arg_08 & 0x7C00, arg_0A & 0x7C00, var_10, var_20);

        *buf++ = (r & 0x001F) | (g & 0x03E0) | (b & 0x7C00);

        var_10++;
    }
}

struct ManimSomethingProc_086660FC
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x64);
    /* 64 */ i16 unk_64;
};

void func_fe6_0806A750(struct ManimSomethingProc_086660FC * proc);
void func_fe6_0806A770(struct ManimSomethingProc_086660FC * proc);

struct ProcScr CONST_DATA ProcScr_Unk_086660FC[] =
{
    PROC_CALL(func_fe6_0806A750),
    PROC_REPEAT(func_fe6_0806A770),
    PROC_END,
};

void func_fe6_0806A750(struct ManimSomethingProc_086660FC * proc)
{
    proc->unk_64 = 0;
}

void func_fe6_0806A770(struct ManimSomethingProc_086660FC * proc)
{
    func_fe6_0806A330(gUnk_0203D348[1] + DISPLAY_HEIGHT, proc->unk_64++, 0x10, 8);
    func_fe6_0806A424();
}

void func_fe6_0806A7AC(void)
{
    int i;

    for (i = 0; i < DISPLAY_HEIGHT; i++)
    {
        gUnk_0203D348[0][i] = 0x1000;
    }

    for (i = 8; i < DISPLAY_HEIGHT - 8; i++)
    {
        gUnk_0203D348[0][i] = 0x10;
    }

    for (i = 0; i <= 32; i++)
    {
        // ugly
        *(gUnk_0203D348[0] + (i + 8)) = ((0x10 - (i >> 1)) << 8) | (i >> 1);
        *(gUnk_0203D348[0] - (i - DISPLAY_HEIGHT + 8)) = ((0x10 - (i >> 1)) << 8) | (i >> 1);
    }
}

u16 * func_fe6_0806A87C(int arg_00, int arg_04)
{
    return gUnk_0203D348[arg_00] + arg_04;
}
