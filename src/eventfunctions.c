#include "eventfunctions.h"

#include "random.h"
#include "armfunc.h"
#include "hardware.h"
#include "oam.h"
#include "sound.h"
#include "talk.h"
#include "event.h"
#include "msg.h"
#include "util.h"
#include "gamecontroller.h"
#include "unit.h"
#include "item.h"
#include "map.h"
#include "unitsprite.h"
#include "supply.h"
#include "battle.h"
#include "bm.h"
#include "bmfx.h"
#include "bmio.h"
#include "support.h"
#include "chapter.h"
#include "trap.h"
#include "gold.h"
#include "faction.h"
#include "action.h"
#include "itemaction.h"
#include "mapselect.h"
#include "mu.h"
#include "manim.h"
#include "ui.h"
#include "chapterinfo.h"
#include "chapterevents.h"
#include "helpbox.h"
#include "mapui.h"
#include "save_stats.h"

#include "constants/flags.h"
#include "constants/pids.h"
#include "constants/jids.h"
#include "constants/iids.h"
#include "constants/chapters.h"
#include "constants/msg.h"
#include "constants/songs.h"
#include "constants/videoalloc_global.h"

extern u16 const gUnk_08342A98[]; // colors

extern struct ProcScr CONST_DATA ProcScr_Unk_08676220[];
extern struct ProcScr CONST_DATA ProcScr_Unk_08676844[];
extern struct ProcScr CONST_DATA ProcScr_Unk_08676854[];
extern struct ProcScr CONST_DATA ProcScr_Unk_0867686C[];

extern u8 gUnk_030048A8;
extern u32 EWRAM_DATA gUnk_0203D354;
extern u32 EWRAM_DATA gUnk_0203D358;
extern u8 EWRAM_DATA gUnk_0203D35C;
extern u8 EWRAM_DATA gUnk_0203D35D;

extern u8 EWRAM_DATA gUnk_0203D360;
extern u8 EWRAM_DATA gUnk_0203D361;
extern u8 EWRAM_DATA gUnk_0203D362;
extern u16 EWRAM_DATA gUnk_0203D364;

extern struct ProcScr CONST_DATA ProcScr_Unk_08677FE0[];

extern u32 EWRAM_DATA gUnk_0203D368;
extern u32 EWRAM_DATA gUnk_0203D36C;
extern struct Text EWRAM_DATA gUnkText_0203D370[];
extern struct Text EWRAM_DATA gUnkText_0203D3A0;

extern struct ProcScr CONST_DATA ProcScr_Unk_0867688C[];
extern struct ProcScr CONST_DATA ProcScr_Unk_086768DC[];

extern EventScr const * CONST_DATA gUnk_086770D4[];

extern u8 EWRAM_DATA gUnk_0203D3D8; // ending related value
extern u8 EWRAM_DATA gUnk_0203D3D9; // ending id

struct Unk_0867619C
{
    /* 00 */ u16 msg;
    /* 02 */ u8 y_offset;
};

extern struct Unk_0867619C CONST_DATA gUnk_0867619C[];

extern EventScr const * CONST_DATA gUnk_08676738[];

extern struct ProcScr CONST_DATA ProcScr_Unk_08677348[];

extern u8 const gUnk_0836F6D4[]; // img
extern u8 const gUnk_08373F80[]; // tm
extern u8 const gUnk_08374670[]; // compressed pal
extern u16 const gUnk_08353308[]; // pal
extern u16 CONST_DATA gUnk_08677360[]; // bg config

struct UnkProc0806D82C
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x4C);
    /* 4C */ i16 unk_4C;
};

struct UnkProc_08676854
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x64);
    /* 64 */ i16 unk_64;
};

struct UnkProc_0867686C
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x64);
    /* 64 */ i16 unk_64;
};

struct HardModeBonusLevelsOverrideEnt
{
    /* 00 */ u8 pid;
    /* 04 */ int bonus_levels;
};

extern struct HardModeBonusLevelsOverrideEnt CONST_DATA gHardModeBonusLevelsOverrideList[];

struct UnkProc_0806DDC4
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x44);
    /* 44 */ u8 unk_44;
    /* 45 */ u8 unk_45;
};

struct UnkProc_086768C4
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x64);
    /* 64 */ u16 unk_64;
};

extern struct ProcScr CONST_DATA ProcScr_Unk_086768C4[];

struct UnkProc_086768DC
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x4C);
    /* 4C */ ProcPtr unk_4C;
    /* 50 */ STRUCT_PAD(0x50, 0x64);
    /* 64 */ i16 unk_64;
};

struct UnkProc_086768FC
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x64);
    /* 64 */ i16 unk_64;
};

struct UnkProc_08676914
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x64);
    /* 64 */ i16 unk_64;
    /* 66 */ i16 unk_66;
};

extern struct ProcScr CONST_DATA ProcScr_Unk_086768FC[];
extern struct ProcScr CONST_DATA ProcScr_Unk_08676914[];

struct Unk_0867692C { u8 x, y; u16 more; };

extern struct Unk_0867692C CONST_DATA gUnk_0867692C[];
extern struct Unk_0867692C CONST_DATA gUnk_0867695C[];
extern i8 EWRAM_DATA gUnk_0203DCA7[];


struct UnkProc_08677348
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2C);
    /* 2C */ int unk_2C;
    /* 30 */ int unk_30;
    /* 34 */ int unk_34;
    /* 38 */ int unk_38;
    /* 3C */ i8 const * unk_3C;
    /* 40 */ int unk_40;
};

extern u8 gUnk_030048A4; // COMMON
extern u8 gUnk_030048B8; // COMMON
extern u8 const gUnk_0834B69C[]; // img
extern u8 const gUnk_08349A98[]; // img
extern u8 const gUnk_0834E1D4[]; // img
extern u8 const gUnk_08352160[]; // img
extern i8 CONST_DATA gUnk_086772FC[];
extern i8 CONST_DATA gUnk_0867730C[];
extern i8 CONST_DATA gUnk_0867731C[];
extern i8 CONST_DATA gUnk_08677327[];

extern struct ProcScr CONST_DATA ProcScr_Unk_08677378[];

// NOTE: this uses the RNG that is usually used for aesthetic purposes
// this means that random events will not be the same accross suspend reloads
#define EventRandNext_N(upper_bound) (DivRem(RandNextB(), (upper_bound)))

bool IsHard(void)
{
    if (gPlaySt.flags & PLAY_FLAG_HARD)
        return TRUE;

    return FALSE;
}

int GetHardModeBonusLevelsByPid(fu8 pid)
{
    struct HardModeBonusLevelsOverrideEnt const * it = gHardModeBonusLevelsOverrideList;

    while (it->pid != 0)
    {
        if (it->pid == pid)
            return it->bonus_levels;

        ++it;
    }

    return GetChapterInfo(gPlaySt.chapter)->hard_bonus_levels;
}

void ApplyAllHardModeBonusLevels(void)
{
    if (gPlaySt.flags & PLAY_FLAG_HARD)
    {
        FOR_UNITS_FACTION(FACTION_RED, unit,
        {
            int bonus_levels = GetHardModeBonusLevelsByPid(unit->pinfo->id);

            if (bonus_levels != 0)
                UnitApplyBonusLevels(unit, bonus_levels);
        })
    }
}

bool func_fe6_0806BB34(struct EventInfo * info)
{
    if (CheckFlag(FLAG_CHAPTER11A_10))
        return FALSE;

    if (!IsKleinNonBlue())
        return FALSE;

    return EventInfoCheckTalk(info, PID_SHANNA, PID_THEA);
}

bool func_fe6_0806BB68(struct EventInfo * info)
{
    if (!CheckFlag(FLAG_CHAPTER11A_7))
        return FALSE;

    if (!IsKleinBlue())
        return FALSE;

    return EventInfoCheckTalk(info, PID_SHANNA, PID_THEA);
}

bool func_fe6_0806BB9C(struct EventInfo * info)
{
    if (CheckFlag(FLAG_CHAPTER11A_7))
        return FALSE;

    if (!IsKleinBlue())
        return FALSE;

    return EventInfoCheckTalk(info, PID_SHANNA, PID_THEA);
}

bool func_fe6_0806BBD0(struct EventInfo * info)
{
    if (gPlaySt.turn < 4)
        return FALSE;

    return CheckAnyBlueUnitArea(20, 0, 45, 24);
}

bool func_fe6_0806BBF8(void)
{
    if (gPlaySt.faction != FACTION_BLUE)
        return FALSE;

    if (EventRandNext_N(11) == 0)
        return TRUE;

    return FALSE;
}

bool func_fe6_0806BC20(struct EventInfo * info)
{
    if (!IsPercivalBlueDeployed())
        return FALSE;

    if (EventInfoCheckTalk(info, PID_ROY, PID_PERCEVAL))
        return TRUE;

    if (EventInfoCheckTalk(info, PID_PERCEVAL, PID_ROY))
        return TRUE;

    return FALSE;
}

bool func_fe6_0806BC5C(struct EventInfo * info)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    if (!CheckFlag(FLAG_CHAPTER24_4))
        return FALSE;

    if (CheckFlag(FLAG_CHAPTER24_5))
        return FALSE;

    if ((gPlaySt.turn % 2) != 0)
        return FALSE;

    if (CheckFlag(FLAG_CHAPTER24_17))
        return FALSE;

    return TRUE;
}

bool func_fe6_0806BCA4(struct EventInfo * info)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    if (!CheckFlag(FLAG_CHAPTER24_5))
        return FALSE;

    if (CheckFlag(FLAG_CHAPTER24_6))
        return FALSE;

    if ((gPlaySt.turn % 2) == 0)
        return FALSE;

    if (CheckFlag(FLAG_CHAPTER24_17))
        return FALSE;

    return TRUE;
}

bool func_fe6_0806BCEC(struct EventInfo * info)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    if (!CheckFlag(FLAG_CHAPTER24_6))
        return FALSE;

    if (CheckFlag(FLAG_CHAPTER24_7))
        return FALSE;

    if ((gPlaySt.turn % 2) != 0)
        return FALSE;

    if (CheckFlag(FLAG_CHAPTER24_17))
        return FALSE;

    return TRUE;
}

bool func_fe6_0806BD34(struct EventInfo * info)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    if (!CheckFlag(FLAG_CHAPTER24_7))
        return FALSE;

    if (CheckFlag(FLAG_CHAPTER24_8))
        return FALSE;

    if ((gPlaySt.turn % 2) == 0)
        return FALSE;

    if (CheckFlag(FLAG_CHAPTER24_17))
        return FALSE;

    return TRUE;
}

bool func_fe6_0806BD7C(struct EventInfo * info)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    if (!CheckFlag(FLAG_CHAPTER24_8))
        return FALSE;

    if (CheckFlag(FLAG_CHAPTER24_9))
        return FALSE;

    if ((gPlaySt.turn % 2) != 0)
        return FALSE;

    if (CheckFlag(FLAG_CHAPTER24_17))
        return FALSE;

    return TRUE;
}

bool func_fe6_0806BDC4(struct EventInfo * info)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    if (!CheckFlag(FLAG_CHAPTER24_9))
        return FALSE;

    if ((gPlaySt.turn % 2) == 0)
        return FALSE;

    if (CheckFlag(FLAG_CHAPTER24_17))
        return FALSE;

    return TRUE;
}

#if BUGFIX
#  define IsKleinNonBlueBugged IsKleinNonBlue
#  define IsKleinBlueBugged IsKleinBlue
#else
#  define IsKleinNonBlueBugged ((int (*)(void))(IsKleinNonBlue))
#  define IsKleinBlueBugged ((int (*)(void))(IsKleinBlue))
#endif

bool Chapter10B_CheckTalkShannaThea(struct EventInfo * info)
{
    if (CheckFlag(FLAG_CHAPTER10B_8))
        return FALSE;

    if (!IsKleinNonBlueBugged())
        return FALSE;

    return EventInfoCheckTalk(info, PID_SHANNA, PID_THEA);
}

bool Chapter10B_CheckTalkShannaTheaAfterKlein(struct EventInfo * info)
{
    if (CheckFlag(FLAG_CHAPTER10B_5))
        return FALSE;

    if (!IsKleinBlueBugged())
        return FALSE;

    return EventInfoCheckTalk(info, PID_SHANNA, PID_THEA);
}

bool Chapter10B_CheckShannaRecruitsThea(struct EventInfo * info)
{
    if (!CheckFlag(FLAG_CHAPTER10B_5))
        return FALSE;

    if (!IsKleinBlueBugged())
        return FALSE;

    return EventInfoCheckTalk(info, PID_SHANNA, PID_THEA);
}

#undef IsKleinBlueBugged
#undef IsKleinNonBlueBugged

bool func_fe6_0806BE90(struct EventInfo * info)
{
    if (!IsDouglasNonBlue())
        return FALSE;

    return EventInfoCheckTalk(info, PID_SHANNA, PID_THEA);
}

bool func_fe6_0806BEB8(struct EventInfo * info)
{
    if (!CheckFlag(9)) // TODO: which chapter?
        return FALSE;

    if (IsDouglasNonBlue())
        return FALSE;

    return EventInfoCheckTalk(info, PID_SHANNA, PID_THEA);
}

bool func_fe6_0806BEEC(struct EventInfo * info)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    return func_fe6_0806AE7C(10, 14, 10, 14);
}

bool func_fe6_0806BF14(struct EventInfo * info)
{
    if (!CheckFlag(FLAG_CHAPTER_BASE))
        return FALSE;

    if (IsPidNonBlue(PID_UNKNOWN_DA))
        return FALSE;

    return TRUE;
}

bool IsGuinivereAround(void)
{
    if (gPlaySt.chapter > CHAPTER_12)
        return TRUE;

    if (gPlaySt.chapter == CHAPTER_2)
        return TRUE;

    if (gPlaySt.chapter == CHAPTER_3)
        return TRUE;

    if (gPlaySt.chapter == CHAPTER_4)
        return TRUE;

    if (gPlaySt.chapter == CHAPTER_5)
        return TRUE;

    if (gPlaySt.chapter == CHAPTER_6)
        return TRUE;

    if (gPlaySt.chapter == CHAPTER_7)
        return TRUE;

    if (gPlaySt.chapter == CHAPTER_8)
        return TRUE;

    // NOTE: this last check is useless, CHAPTER_8X (=0x20) is greater than CHAPTER_12 (=0x0C)
    if (gPlaySt.chapter == CHAPTER_8X)
        return TRUE;

    return FALSE;
}

void func_fe6_0806BF70(void)
{
    SoftReset(GBA_RESET_ALL & ~GBA_RESET_EWRAM);
}

bool func_fe6_0806BF7C(void)
{
    if (gKeySt->pressed & KEY_BUTTON_A)
        return FALSE;

    return TRUE;
}

void func_fe6_0806BF98(void)
{
    SoftReset(GBA_RESET_ALL & ~GBA_RESET_EWRAM);
}

bool func_fe6_0806BFA4(void)
{
    if (gKeySt->pressed & KEY_BUTTON_A)
        return TRUE;

    return FALSE;
}

void RemoveFog(void)
{
    SetFogVision(0);
}

void AddFiveThousandGold(void)
{
    SetGold(GetGold() + 5000);
}

void RemoveGold(int gold_amount)
{
    if (GetGold() >= gold_amount)
    {
        SetGold(GetGold() - gold_amount);
    }
}

void WeakenUnitStats(struct Unit * unit)
{
    if (unit->max_hp > 0)
        unit->max_hp--;

    if (unit->pow > 0)
        unit->pow--;

    if (unit->skl > 0)
        unit->skl--;

    if (unit->spd > 0)
        unit->spd--;

    if (unit->def > 0)
        unit->def--;

    if (unit->res > 0)
        unit->res--;

    if (unit->lck > 0)
        unit->lck--;
}

void WeakenUnitStatsByPid(fu8 pid)
{
    WeakenUnitStats(GetUnitByPid(pid));
}

bool IsPidBlueDeployed(fu8 pid)
{
    FOR_UNITS_FACTION(FACTION_BLUE, unit,
    {
        if (unit->flags & (UNIT_FLAG_DEAD | UNIT_FLAG_NOT_DEPLOYED))
            continue;

        if (UNIT_PID(unit) == pid)
            return TRUE;
    })

    return FALSE;
}

bool IsLilinaBlueDeployed(void)
{
    return IsPidBlueDeployed(PID_LILINA);
}

bool IsMarcusBlueDeployed(void)
{
    return IsPidBlueDeployed(PID_MARCUS);
}

bool IsMerlinusBlueDeployed(void)
{
    return IsPidBlueDeployed(PID_MERLINUS);
}

bool IsJunoBlueDeployed(void)
{
    return IsPidBlueDeployed(PID_JUNO);
}

bool IsZelotBlueDeployed(void)
{
    return IsPidBlueDeployed(PID_ZELOT);
}

bool IsSinBlueDeployed(void)
{
    return IsPidBlueDeployed(PID_SIN);
}

bool IsDayanBlueDeployed(void)
{
    return IsPidBlueDeployed(PID_DAYAN);
}

bool IsSueBlueDeployed(void)
{
    return IsPidBlueDeployed(PID_SUE);
}

bool IsMeladyBlueDeployed(void)
{
    return IsPidBlueDeployed(PID_MELADY);
}

bool IsZeissBlueDeployed(void)
{
    return IsPidBlueDeployed(PID_ZEISS);
}

bool IsPercivalBlueDeployed(void)
{
    return IsPidBlueDeployed(PID_PERCEVAL);
}

bool IsPidBlue(fu8 pid)
{
    FOR_UNITS_FACTION(FACTION_BLUE, unit,
    {
        if (unit->flags & UNIT_FLAG_DEAD)
            continue;

        if (UNIT_PID(unit) == pid)
            return TRUE;
    })

    return FALSE;
}

bool IsBorsBlue(void)
{
    return IsPidBlue(PID_BORS);
}

bool IsLilinaBlue(void)
{
    return IsPidBlue(PID_LILINA);
}

bool IsElenBlue(void)
{
    return IsPidBlue(PID_ELEN);
}

bool IsRaighBlue(void)
{
    return IsPidBlue(PID_RAIGH);
}

bool IsSueBlue(void)
{
    return IsPidBlue(PID_SUE);
}

bool IsCathBlue(void)
{
    return IsPidBlue(PID_CATH);
}

bool IsMeladyBlue(void)
{
    return IsPidBlue(PID_MELADY);
}

bool IsZeissBlue(void)
{
    return IsPidBlue(PID_ZEISS);
}

bool IsSophiaBlue(void)
{
    return IsPidBlue(PID_SOPHIA);
}

bool IsJunoBlue(void)
{
    return IsPidBlue(PID_JUNO);
}

bool IsZelotBlue(void)
{
    return IsPidBlue(PID_ZELOT);
}

bool IsElffinBlue(void)
{
    return IsPidBlue(PID_ELFFIN);
}

bool IsFaeBlue(void)
{
    return IsPidBlue(PID_FAE);
}

bool IsSinBlue(void)
{
    return IsPidBlue(PID_SIN);
}

bool IsDayanBlue(void)
{
    return IsPidBlue(PID_DAYAN);
}

bool IsKleinBlue(void)
{
    return IsPidBlue(PID_KLEIN);
}

bool IsTheaBlue(void)
{
    return IsPidBlue(PID_THEA);
}

bool IsDouglasBlue(void)
{
    return IsPidBlue(PID_DOUGLAS);
}

bool func_fe6_0806C2C4(void)
{
    FOR_UNITS(FACTION_GREEN + 1, FACTION_RED + 0x40, unit,
    {
        if (unit->flags & UNIT_FLAG_DEAD)
            continue;

        return TRUE;
    })

    return FALSE;
}

bool func_fe6_0806C2F8(void)
{
    return func_fe6_0806C2C4() ? FALSE : TRUE;
}

bool IsPidNonBlue(fu8 pid)
{
    FOR_UNITS(FACTION_GREEN + 1, FACTION_RED + 0x40, unit,
    {
        if (unit->flags & UNIT_FLAG_DEAD)
            continue;

        if (unit->pinfo->id == pid)
            return TRUE;
    })

    return FALSE;
}

bool IsTheaNonBlue(void)
{
    return IsPidNonBlue(PID_THEA);
}

bool func_fe6_0806C35C(void)
{
    return IsPidNonBlue(PID_UNKNOWN_5E);
}

bool IsKleinNonBlue(void)
{
    return IsPidNonBlue(PID_KLEIN);
}

bool IsCathNonBlue(void)
{
    return IsPidNonBlue(PID_CATH);
}

bool IsHughNonBlue(void)
{
    return IsPidNonBlue(PID_HUGH);
}

bool IsGalleNonBlue(void)
{
    return IsPidNonBlue(PID_GALLE);
}

bool func_fe6_0806C3AC(void)
{
    return IsPidNonBlue(PID_UNKNOWN_C4);
}

bool func_fe6_0806C3BC(void)
{
    return IsPidNonBlue(PID_UNKNOWN_C6);
}

bool IsDouglasNonBlue(void)
{
    return IsPidNonBlue(PID_DOUGLAS);
}

bool IsPercevalNonBlue(void)
{
    return IsPidNonBlue(PID_PERCEVAL);
}

bool func_fe6_0806C3EC(void)
{
    return IsPidNonBlue(PID_UNKNOWN_D5);
}

bool func_fe6_0806C3FC(void)
{
    return IsPidNonBlue(PID_UNKNOWN_D6);
}

bool func_fe6_0806C40C(void)
{
    return IsPidNonBlue(PID_UNKNOWN_D7);
}

int func_fe6_0806C41C(fu8 pid, int faction)
{
    int count = 0;

    FOR_UNITS_FACTION(faction, unit,
    {
        if (unit->flags & UNIT_FLAG_DEAD)
            continue;

        if (unit->pinfo->id == pid)
            count++;
    })

    return count;
}

int func_fe6_0806C460(int faction)
{
    int count = 0;

    FOR_UNITS_FACTION(faction, unit,
    {
        if (unit->flags & UNIT_FLAG_DEAD)
            continue;

        count++;
    })

    return count;
}

bool IsPastTurn20(void)
{
    if (gPlaySt.turn > 20)
        return TRUE;

    return FALSE;
}

bool IsPastTurn25(void)
{
    if (gPlaySt.turn > 25)
        return TRUE;

    return FALSE;
}

bool IsPastTurn30(void)
{
    if (gPlaySt.turn > 30)
        return TRUE;

    return FALSE;
}

bool IsBluePhase(void)
{
    if (gPlaySt.faction != FACTION_BLUE)
        return FALSE;

    return TRUE;
}

bool IsRedPhase(void)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    return TRUE;
}

bool IsActiveUnitMale(void)
{
    // hm
    if (UNIT_ATTRIBUTES(gActiveUnit) & UNIT_ATTR_FEMALE)
        return FALSE;

    return TRUE;
}

bool func_fe6_0806C524(void)
{
    if (GetGold() < 10000)
        return FALSE;

    return TRUE;
}

bool func_fe6_0806C540(void)
{
    if (GetGold() < 8000)
        return FALSE;

    return TRUE;
}

bool func_fe6_0806C55C(void)
{
    if (GetGold() < 6000)
        return FALSE;

    return TRUE;
}

bool func_fe6_0806C578(void)
{
    if (GetGold() < 5000)
        return FALSE;

    return TRUE;
}

bool func_fe6_0806C594(void)
{
    if (GetTalkChoiceResult() == 1) // TODO: talk choice constants
        return TRUE;

    return FALSE;
}

bool AreWeGoingToSacae(void)
{
    struct PidStats * stats;
    u32 sacae, ilia;

    stats = GetPidStats(PID_SUE);
    sacae = stats->exp_gained;

    stats = GetPidStats(PID_SIN);
    sacae = stats->exp_gained + sacae;

    stats = GetPidStats(PID_THEA);
    ilia = stats->exp_gained;

    stats = GetPidStats(PID_SHANNA);
    ilia = stats->exp_gained + ilia;

    if (sacae > ilia)
        return TRUE;

    return FALSE;
}

void func_fe6_0806C608(void)
{
    if (gPlaySt.flags & PLAY_FLAG_TUTORIAL || !gPlaySt.config_bgm_disable)
        FadeBgmOut(4);
}

bool func_fe6_0806C62C(void)
{
    if (gPlaySt.flags & PLAY_FLAG_COMPLETE)
        return TRUE;

    if (gPlaySt.flags & PLAY_FLAG_TUTORIAL)
        return TRUE;

    return FALSE;
}

void func_fe6_0806C64C(void)
{
    u32 unk;

    gUnk_030048A8 = 0;
    ClearFlag(FLAG_TUTORIAL_22);
    unk = func_fe6_0802BA08();
    gUnk_0203D358 = unk;
}

void func_fe6_0806C670(void)
{
    if (gUnk_030048A8 == 0)
    {
        gUnk_030048A8++;
        FreezeMenu();
    }
}

bool func_fe6_0806C68C(void)
{
    return gUnk_030048A8;
}

void func_fe6_0806C69C(void)
{
    gUnk_030048A8 = 0;
    ResumeMenu();
}

void func_fe6_0806C6B0(void)
{
    u32 unk = func_fe6_0802B9DC();
    gUnk_0203D354 = unk;

    switch (UNIT_PID(gActiveUnit))
    {
        case PID_ROY:
            StartEvent(gUnk_0866AF5C);
            break;

        case PID_WOLT:
            StartEvent(gUnk_0866AFEC);
            break;

        case PID_LILINA:
            StartEvent(gUnk_0866B07C);
            break;

        case PID_ALEN:
            StartEvent(gUnk_0866B10C);
            break;
    }
}

void func_fe6_0806C718(void)
{
    if (!CheckFlag(FLAG_TUTORIAL_9))
        StartEvent(gUnk_0866AEA8);
}

void func_fe6_0806C734(void)
{
    if (!CheckFlag(FLAG_TUTORIAL_10))
        StartEvent(gUnk_0866AEE0);
}

void func_fe6_0806C750(void)
{
    if (!CheckFlag(FLAG_TUTORIAL_11))
        StartEvent(gUnk_0866AF28);
}

void func_fe6_0806C76C(int a, int b, int c)
{
    int var = Interpolate(INTERPOLATE_SQUARE, a, b, c, 8);

    CpuFastCopy(gUnk_08342A98, gPal + 0x12 * 0x10, 0x10 * sizeof(u16));
    func_fe6_0805B644(gPal, 18, 1, var);
    EnablePalSync();
}

void func_fe6_0806C7BC(struct TutorialEventProcA * proc)
{
    proc->unk_64 = 0;
    proc->unk_66 = 0;
    ApplyPalette(gUnk_08342A98, 0x12);
}

void func_fe6_0806C7E0(struct TutorialEventProcA * proc)
{
    int x, y, r4;

    switch (gUnk_0203D35D)
    {
        case 0:
            for (r4 = 0; r4 < gUnk_0203D35C; r4++)
            {
                struct SelectTarget * target = GetTarget(r4);

                x = (target->x * 16) - gBmSt.camera.x;
                y = (target->y * 16) - gBmSt.camera.y;

                PutOamHi(OAM1_X(x + 0x200), OAM0_Y(y + 0x100), Sprite_0866ACCC, OAM2_CHR(OBJCHR_SYSTEM_OBJECTS + 0x22) + OAM2_PAL(2) + OAM2_LAYER(2));
            }

            break;

        case 1:
            x = 0xD0 - gBmSt.camera.x;
            y = 0x70 - gBmSt.camera.y;
            PutOamHi(OAM1_X(x + 0x200), OAM0_Y(y + 0x100), Sprite_0866ACCC, OAM2_CHR(OBJCHR_SYSTEM_OBJECTS + 0x22) + OAM2_PAL(2) + OAM2_LAYER(2));
            break;

        case 2:
            x = 0x160 - gBmSt.camera.x;
            y = 0x40 - gBmSt.camera.y;
            PutOamHi(OAM1_X(x + 0x200), OAM0_Y(y + 0x100), Sprite_0866ACCC, OAM2_CHR(OBJCHR_SYSTEM_OBJECTS + 0x22) + OAM2_PAL(2) + OAM2_LAYER(2));
            break;

    }

    if ((GetGameTime() & 1) == 0)
    {
        if (proc->unk_66 != 0)
        {
            func_fe6_0806C76C(0x10, 0, proc->unk_64);

            if (++proc->unk_64 > 8)
            {
                proc->unk_64 = 0;
                proc->unk_66 = 0;
            }
        }
        else
        {
            func_fe6_0806C76C(0, 0x10, proc->unk_64);

            if (++proc->unk_64 > 8)
            {
                proc->unk_64 = 0;
                proc->unk_66 = 1;
            }
        }
    }
}

void func_fe6_0806C948(struct TutorialEventProcB * proc)
{
    proc->unk_64 = 60;
}

void func_fe6_0806C950(struct TutorialEventProcB * proc)
{
    if (--proc->unk_64 != 0)
    {
        if (func_fe6_080718E0())
            return;

        if (!(gKeySt->pressed & KEY_BUTTON_R))
            return;
    }

    Proc_EndEach(ProcScr_Unk_0866ACE8);
    Proc_Break(proc);
}

void func_fe6_0806C998(int what)
{
    gUnk_0203D35D = what;

    func_fe6_0802BA44(gActiveUnit);
    gUnk_0203D35C = CountTargets();

    if (gUnk_0203D35C != 0)
    {
        struct SelectTarget * target;

        SpawnProc(ProcScr_Unk_0866ACE8, PROC_TREE_3);

        target = GetTarget(0);
        CameraMoveWatchPosition(NULL, target->x, target->y);
        SetMapCursorPosition(gActiveUnit->x, gActiveUnit->y);
    }
}

bool func_fe6_0806C9F8(void)
{
    bool result = func_fe6_080718E0();

    if (!result)
        SpawnProc(ProcScr_Unk_0866AD00, PROC_TREE_3);

    return result;
}

void func_fe6_0806CA1C(void)
{
    func_fe6_08071B80(16, 104, MSG_019, NULL);
}

void func_fe6_0806CA30(void)
{
    func_fe6_08071B80(16, 104, MSG_01A, NULL);
}

void func_fe6_0806CA44(void)
{
    func_fe6_08071B80(16, 104, MSG_01E, NULL);
}

void func_fe6_0806CA58(void)
{
    func_fe6_08071B80(16, 104, MSG_01F, NULL);
}

void func_fe6_0806CA6C(void)
{
    func_fe6_08071B80(16, 104, MSG_020, NULL);
    func_fe6_0806C998(0);
}

void func_fe6_0806CA84(void)
{
    func_fe6_08071B80(16, 104, MSG_023, NULL);
}

void func_fe6_0806CA98(void)
{
    func_fe6_08071B80(16, 104, MSG_024, NULL);
}

void func_fe6_0806CAAC(void)
{
    func_fe6_08071B80(16, 104, MSG_025, NULL);
    func_fe6_0806C998(0);
}

void func_fe6_0806CAC4(void)
{
    func_fe6_08071B80(16, 104, MSG_029, NULL);
}

void func_fe6_0806CAD8(void)
{
    func_fe6_08071B80(16, 104, MSG_02A, NULL);
}

void func_fe6_0806CAEC(void)
{
    func_fe6_08071B80(40, 104, MSG_02B, NULL);
}

void func_fe6_0806CB00(void)
{
    func_fe6_08071B80(16, 16, MSG_02D, NULL);
    func_fe6_0806C998(1);
}

void func_fe6_0806CB18(void)
{
    func_fe6_08071B80(16, 56, MSG_02E, NULL);
}

void func_fe6_0806CB2C(void)
{
    func_fe6_08071B80(16, 16, MSG_030, NULL);
}

void func_fe6_0806CB40(void)
{
    func_fe6_08071B80(16, 104, MSG_045, NULL);
}

void func_fe6_0806CB54(void)
{
    func_fe6_08071B80(16, 104, MSG_01B, NULL);
    func_fe6_0806C998(0);
}

void func_fe6_0806CB6C(void)
{
    func_fe6_08071B80(16, 104, MSG_040, NULL);
}

void func_fe6_0806CB80(void)
{
    func_fe6_08071B80(16, 104, MSG_03F, NULL);
}

void func_fe6_0806CB94(void)
{
    func_fe6_08071B80(16, 104, MSG_03E, NULL);
}

void func_fe6_0806CBA8(void)
{
    func_fe6_08071B80(16, 104, MSG_042, NULL);
}

void func_fe6_0806CBBC(void)
{
    switch (UNIT_PID(gActiveUnit))
    {
        case PID_ROY:
        case PID_ALEN:
            func_fe6_08071B80(16, 104, MSG_01C, NULL);
            break;

        case PID_WOLT:
            func_fe6_08071B80(16, 104, MSG_021, NULL);
            break;

        case PID_LILINA:
            func_fe6_08071B80(16, 104, MSG_026, NULL);
            break;
    }
}

bool IsActiveUnitRoy(void)
{
    return (UNIT_PID(gActiveUnit) == PID_ROY) ? TRUE : FALSE;
}

bool IsActiveUnitWolt(void)
{
    return (UNIT_PID(gActiveUnit) == PID_WOLT) ? TRUE : FALSE;
}

bool IsActiveUnitLilina(void)
{
    return (UNIT_PID(gActiveUnit) == PID_LILINA) ? TRUE : FALSE;
}

bool IsActiveUnitAlen(void)
{
    return (UNIT_PID(gActiveUnit) == PID_ALEN) ? TRUE : FALSE;
}

bool func_fe6_0806CC68(void)
{
    if ((gUnk_0203D354 & 2) != 0)
        return TRUE;

    return FALSE;
}

bool IsCombatAction(void)
{
    return gAction.id == ACTION_COMBAT ? TRUE : FALSE;
}

bool func_fe6_0806CC94(void)
{
    if (CheckFlag(FLAG_TUTORIAL_22))
        return FALSE;

    if (gAction.id == ACTION_VISIT)
    {
        SetFlag(FLAG_TUTORIAL_22);
        return TRUE;
    }

    return FALSE;
}

bool func_fe6_0806CCC0(void)
{
    return FALSE;
}

void func_fe6_0806CCC4(void)
{
    if (CheckFlag(FLAG_TUTORIAL_18))
        return;

    if (CheckFlag(FLAG_TUTORIAL_19))
        SetFlag(FLAG_TUTORIAL_18);
}

bool IsAnyTutorialUnitDamaged(void)
{
    FOR_UNITS_FACTION(FACTION_BLUE, unit,
    {
        if (UNIT_PID(unit) == PID_ROY || UNIT_PID(unit) == PID_WOLT || UNIT_PID(unit) == PID_LILINA || UNIT_PID(unit) == PID_ALEN)
        {
            if (GetUnitCurrentHp(unit) < GetUnitMaxHp(unit))
                return TRUE;
        }
    })

    return FALSE;
}

bool IsAnyTutorialUnitPastColumn16(void)
{
    FOR_UNITS_FACTION(FACTION_BLUE, unit,
    {
        if (UNIT_PID(unit) == PID_ROY || UNIT_PID(unit) == PID_WOLT || UNIT_PID(unit) == PID_LILINA || UNIT_PID(unit) == PID_ALEN)
        {
            if (unit->x > 16)
                return TRUE;
        }
    })

    return FALSE;
}

bool IsBossDefeated(void)
{
    FOR_UNITS(FACTION_GREEN + 1, FACTION_RED + 0x40, unit,
    {
        if (unit->pinfo->attributes & UNIT_ATTR_BOSS)
            return FALSE;
    })

    return TRUE;
}

bool IsPastTurn1(void)
{
    if (gPlaySt.turn > 1)
        return TRUE;

    return FALSE;
}

bool func_fe6_0806CDC0(void)
{
    switch (UNIT_PID(gActiveUnit))
    {
        case PID_ROY:
        case PID_ALEN:
            if (CheckFlag(FLAG_TUTORIAL_14))
                return FALSE;

            break;

        case PID_WOLT:
            if (CheckFlag(FLAG_TUTORIAL_15))
                return FALSE;

            break;

        case PID_LILINA:
            if (CheckFlag(FLAG_TUTORIAL_16))
                return FALSE;

            break;
    }

    if ((gUnk_0203D358 & 2) != 0)
        return TRUE;

    return FALSE;
}

bool func_fe6_0806CE18(void)
{
    if ((gUnk_0203D358 & 0x8000) != 0)
        return TRUE;

    return FALSE;
}

bool func_fe6_0806CE34(void)
{
    if ((gUnk_0203D358 & 0x10000) != 0)
        return TRUE;

    return FALSE;
}

bool func_fe6_0806CE50(void)
{
    if (CheckFlag(FLAG_TUTORIAL_18))
        return FALSE;

    if ((gUnk_0203D358 & 0x18002) != 0)
        return FALSE;

    return TRUE;
}

bool func_fe6_0806CE80(void)
{
    if (CheckFlag(FLAG_TUTORIAL_20))
        return FALSE;

    if ((gUnk_0203D358 & 0x100) != 0)
        return TRUE;

    return FALSE;
}

bool func_fe6_0806CEAC(void)
{
    if (CheckFlag(FLAG_TUTORIAL_21))
        return FALSE;

    if ((gUnk_0203D358 & 0x800000) != 0)
        return TRUE;

    return FALSE;
}

void RefreshClarine(void)
{
    GetUnitByPid(PID_CLARINE)->flags &= ~UNIT_FLAG_TURN_ENDED;
}

bool func_fe6_0806CEF0(void)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    if (CheckFlag(FLAG_CHAPTER6_6))
        return TRUE;

    if (CheckFlag(FLAG_CHAPTER6_5))
        SetFlag(FLAG_CHAPTER6_6);

    if (CheckFlag(FLAG_CHAPTER6_4))
        SetFlag(FLAG_CHAPTER6_5);

    return FALSE;
}

bool func_fe6_0806CF3C(void)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    if (CheckFlag(FLAG_CHAPTER6_10))
        return TRUE;

    if (CheckFlag(FLAG_CHAPTER6_9))
        SetFlag(FLAG_CHAPTER6_10);

    if (CheckFlag(FLAG_CHAPTER6_8))
        SetFlag(FLAG_CHAPTER6_9);

    return FALSE;
}

void Chapter8_WeakenNorthWestWall(void)
{
    // set wall hp to 10

    struct Trap * trap = GetTrapAt(6, 1);

    if (trap != NULL)
        trap->extra = 10;
}

void func_fe6_0806CFA0(void)
{
    m4aMPlayStart(&gMusicPlayer_MainBgm, &Song_Unk_0857B774);
}

void func_fe6_0806CFB8(void)
{
    m4aMPlayStart(&gMusicPlayer_MainBgm, &Song_Unk_0857C95C);
}

void func_fe6_0806CFD0(void)
{
    m4aMPlayStart(&gMusicPlayer_MainBgm, &Song_Unk_0857C1E4);
}

void func_fe6_0806CFE8(void)
{
    m4aMPlayStart(&gMusicPlayer_MainBgm, &Song_Unk_0857A61C);
}

void func_fe6_0806D000(void)
{
    PlaySe(SONG_C4);
}

void func_fe6_0806D01C(void)
{
    func_fe6_080030B4(0);
}

bool func_fe6_0806D028(void)
{
    if (gPlaySt.faction != FACTION_BLUE)
        return FALSE;

    if (UNIT_JID(gActiveUnit) == JID_THIEF)
        return TRUE;

    if (UNIT_JID(gActiveUnit) == JID_THIEF_F)
        return TRUE;

    if (EventRandNext_N(11) == 0)
        return TRUE;

    return FALSE;
}

void func_fe6_0806D064(void)
{
    if (CheckFlag(FLAG_CHAPTER16_15))
    {
        RemoveGold(10000);
    }

    if (CheckFlag(FLAG_CHAPTER16_16))
    {
        WeakenUnitStatsByPid(PID_HUGH);
        RemoveGold(8000);
    }

    if (CheckFlag(FLAG_CHAPTER16_17))
    {
        WeakenUnitStatsByPid(PID_HUGH);
        WeakenUnitStatsByPid(PID_HUGH);
        RemoveGold(6000);
    }

    if (CheckFlag(FLAG_CHAPTER16_18))
    {
        WeakenUnitStatsByPid(PID_HUGH);
        WeakenUnitStatsByPid(PID_HUGH);
        WeakenUnitStatsByPid(PID_HUGH);
        RemoveGold(5000);
    }
}

void func_fe6_0806D0E4(void)
{
    EndMapUi();
    func_fe6_08027DB4(GetUnitByPid(PID_ROY), ITEM_FROM_IID(IID_BINDINGBLADE));
}

bool func_fe6_0806D0FC(int iid)
{
    int i;

    if (FindSupplyItem(ITEM_FROM_IID(iid)) >= 0)
        return TRUE;

    FOR_UNITS_FACTION(FACTION_BLUE, unit,
    {
        if ((unit->flags & UNIT_FLAG_DEAD) != 0)
            continue;

        for (i = 0; i < ITEMSLOT_INV_COUNT; i++)
        {
            if (GetItemIid(unit->items[i]) == iid)
                return TRUE;
        }
    })

    return FALSE;
}

bool func_fe6_0806D150(void)
{
    u8 const * it;

    for (it = gUnk_08672458; *it != 0; it++)
    {
        if (!func_fe6_0806D0FC(*it))
            return FALSE;
    }

    return TRUE;
}

void func_fe6_0806D17C(void)
{
    StartMapChangeEvent(GetMapChangeIdAt(22, 23));
}

void func_fe6_0806D194(void)
{
    int i;

    for (i = 0; i <= FLAG_CHAPTER24_17 - FLAG_CHAPTER24_13; i++)
    {
        ClearFlag(FLAG_CHAPTER24_13 + i);
    }
}

void func_fe6_0806D1AC(void)
{
    int i;

    for (i = 0; i <= FLAG_CHAPTER24_17 - FLAG_CHAPTER24_13; i++)
    {
        int flag = FLAG_CHAPTER24_13 + i;

        if (!CheckFlag(flag))
        {
            SetFlag(flag);
            return;
        }
    }
}

void func_fe6_0806D1D4(void)
{
    gUnk_0203D360 = 0;
    gUnk_0203D361 = 0;
    gUnk_0203D362 = 0;
    gUnk_0203D364 = 0;
}

bool func_fe6_0806D1FC(struct EventProc * proc)
{
    struct Unit * unit;
    int i, j;

    if ((proc->flags & EVENT_FLAG_SKIPPED) != 0)
    {
        EndTalk();
        return FALSE;
    }

    if (IsTalkActive())
        return TRUE;

    switch (gUnk_0203D360)
    {
        case 0:
            i = 1;

            if (gUnk_0203D361 != 0)
                i = gUnk_0203D361;

            for (; i < 0x40; ++i)
            {
                unit = GetUnit(i);

                if (unit == NULL)
                    continue;

                if (unit->pinfo == NULL)
                    continue;

                if ((unit->flags & UNIT_FLAG_UNAVAILABLE) != 0)
                    continue;

                gUnk_0203D362 = UNIT_PID(unit);

                if (gUnk_0203D362 == PID_ROY)
                    continue;

                for (j = 0; gBattleDefeatTalkList[j].pid != 0; j++)
                {
                    if (gUnk_0203D362 == gBattleDefeatTalkList[j].pid)
                    {
                        gUnk_0203D364 = gBattleDefeatTalkList[j].unk_0C;
                        gUnk_0203D361 = i + 1;
                        gUnk_0203D360++;
                        return TRUE;
                    }
                }
            }

            return FALSE;

        case 1:
            unit = GetUnitByPid(gUnk_0203D362);

            CameraMoveWatchPosition(proc, unit->x, unit->y);
            SetMapCursorPosition(unit->x, unit->y);

            gUnk_0203D360++;
            break;

        case 2:
            SetInitTalkTextFont();
            ClearTalkText();
            ClearPutTalkText();
            ClearTalk();

            StartTalkExt(10, 14, DecodeMsg(gUnk_0203D364), proc);
            SetTalkPrintColor(TEXT_COLOR_0456);
            SetActiveTalkFace(TALK_FACE_1);

            gUnk_0203D360 = 0;
            break;
    }

    return TRUE;
}

bool func_fe6_0806D35C(void)
{
    int count = 0;

    FOR_UNITS(FACTION_GREEN + 1, FACTION_RED + 0x40, unit,
    {
        if ((unit->flags & UNIT_FLAG_DEAD) != 0)
            continue;

        count++;
    })

    if (count < 3)
        return FALSE;

    return TRUE;
}

bool func_fe6_0806D398(void)
{
    if (EventRandNext_N(5) == 0)
        return TRUE;

    return FALSE;
}

bool func_fe6_0806D3B4(void)
{
    if (func_fe6_0806D398())
    {
        if (gChapterFlagBits[sizeof(gChapterFlagBits) - 1] + 4 != func_fe6_0806C460(FACTION_RED))
            return TRUE;
    }

    return FALSE;
}

void func_fe6_0806D3E0(void)
{
    gChapterFlagBits[sizeof(gChapterFlagBits) - 2]++;
    gChapterFlagBits[sizeof(gChapterFlagBits) - 1] = func_fe6_0806C460(FACTION_RED);

    if (IsHard())
    {
        if (gChapterFlagBits[sizeof(gChapterFlagBits) - 2] == 10)
            return;
    }
    else
    {
        if (gChapterFlagBits[sizeof(gChapterFlagBits) - 2] == 5)
            return;
    }

    ClearFlag(FLAG_CHAPTER18S_6);
}

void func_fe6_0806D41C(void)
{
    AddFireTrap(10, 22, 1, 4);
    AddFireTrap(14, 21, 2, 3);
    AddFireTrap(14, 23, 2, 5);
    AddFireTrap(17, 22, 4, 2);
    AddFireTrap(19, 21, 4, 6);
    AddFireTrap(23, 18, 6, 4);
    AddFireTrap(25, 18, 6, 3);
    AddFireTrap(23, 16, 5, 3);
    AddFireTrap(24,  9, 5, 2);
    AddFireTrap(23,  8, 6, 5);
    AddFireTrap(25,  8, 5, 4);
    AddFireTrap(20,  1, 7, 5);
    AddFireTrap(19,  3, 6, 6);
    AddFireTrap(14,  8, 9, 2);
    AddFireTrap(15,  9, 3, 3);
    AddFireTrap(13,  9, 9, 4);
    AddFireTrap(14, 10, 11, 3);
    AddFireTrap(12, 12, 1, 5);
    AddFireTrap(11, 11, 1, 3);
    AddFireTrap(11, 13, 7, 3);
    AddFireTrap( 9, 13, 8, 4);
    AddFireTrap( 9, 11, 2, 4);
    AddFireTrap( 8, 12, 6, 2);
    AddFireTrap( 7, 11, 5, 3);
    AddFireTrap( 7, 13, 4, 5);
    AddFireTrap( 3, 10, 1, 3);
}

void func_fe6_0806D55C(void)
{
    gPlaySt.chapter = CHAPTER_8X;
}

void func_fe6_0806D568(void)
{
    AddGasTrap( 1,  2, FACING_DOWN, 1, 8);
    AddGasTrap( 1, 14, FACING_RIGHT, 7, 8);
    AddGasTrap(10,  7, FACING_LEFT, 2, 8);
    AddGasTrap( 8, 13, FACING_RIGHT, 3, 8);
    AddGasTrap(11,  2, FACING_DOWN, 5, 8);
    AddGasTrap(13, 13, FACING_DOWN, 4, 8);
    AddGasTrap(14, 17, FACING_UP, 1, 8);
    AddGasTrap(15,  1, FACING_UP, 5, 8);
    AddGasTrap(20, 18, FACING_LEFT, 2, 8);
    AddGasTrap(21,  9, FACING_LEFT, 6, 8);
    AddGasTrap(23, 12, FACING_RIGHT, 3, 8);
    AddGasTrap(23, 20, FACING_RIGHT, 7, 8);
}

void func_fe6_0806D620(void)
{
    int i;

    for (i = 0; i < (int) ARRAY_COUNT(gUnk_0867507C); i++)
    {
        func_fe6_08026BA4(i + 26, i, gUnk_0867507C[i].delay, gUnk_0867507C[i].interval);
    }
}

void func_fe6_0806D648(void)
{
    AddArrowTrap(14, 3, 5);
    AddArrowTrap( 6, 1, 9);
    AddArrowTrap( 8, 4, 9);
    AddArrowTrap( 4, 7, 9);
    AddArrowTrap(13, 8, 9);
    AddArrowTrap(16, 3, 5);
    AddArrowTrap(24, 2, 9);
    AddArrowTrap(26, 5, 9);
    AddArrowTrap(22, 9, 9);
    AddArrowTrap(17, 6, 9);
}

void func_fe6_0806D6B4(void)
{
    SetFlag(gUnk_08675750[EventRandNext_N(ARRAY_COUNT(gUnk_08675750))]);
}

void func_fe6_0806D6D8(void)
{
    AddStepFireTrap( 6, 6);
    AddStepFireTrap( 7, 8);
    AddStepFireTrap( 6, 10);
    AddStepFireTrap( 7, 13);
    AddStepFireTrap( 6, 15);
    AddStepFireTrap( 7, 17);
    AddStepFireTrap(24,  6);
    AddStepFireTrap(23,  8);
    AddStepFireTrap(24, 10);
    AddStepFireTrap(23, 13);
    AddStepFireTrap(24, 16);
    AddStepFireTrap(23, 17);

    AddStepPikeTrap(12, 14, FACING_UP);
    AddStepPikeTrap(18, 14, FACING_UP);
    AddStepPikeTrap(10,  7, FACING_RIGHT);
    AddStepPikeTrap(20,  7, FACING_LEFT);
    AddStepPikeTrap(14,  7, FACING_RIGHT);
    AddStepPikeTrap(16,  7, FACING_LEFT);
}

void func_fe6_0806D77C(void)
{
    int i, count;

    for (i = 0, count = 0;; i++)
    {
        if (!CheckFlag(gUnk_08675B90[i % (int) ARRAY_COUNT(gUnk_08675B90)]) && EventRandNext_N(11) == 0)
        {
            SetFlag(gUnk_08675B90[i % (int) ARRAY_COUNT(gUnk_08675B90)]);

            count++;

            if (count == 3)
                return;
        }
    }
}

void func_fe6_0806D7C8(void)
{
    func_fe6_08013A64();
    SetNextGameAction(GAME_ACTION_1);
    SpawnProc(ProcScr_Unk_08676220, PROC_TREE_4);
}

void func_fe6_0806D7E4(void)
{
    gPlaySt.config_battle_anim = 3; // TODO: battle anim config constants
}

void func_fe6_0806D7F4(void)
{
    gPlaySt.config_battle_anim = 0; // TODO: battle anim config constants
}

void func_fe6_0806D808(void)
{
    InitUnits();
    ClearTalk();
    Proc_EndEachMarked(PROC_MARK_1);
}

void func_fe6_0806D81C(void)
{
    Proc_EndEach(ProcScr_Unk_08676220);
}

void func_fe6_0806D82C(ProcPtr proc)
{
    if (gKeySt->pressed & (KEY_BUTTON_ANY & ~KEY_BUTTON_SELECT))
        Proc_Break(proc);
}

void func_fe6_0806D850(struct UnkProc0806D82C * proc)
{
    SetNextGameAction(GAME_ACTION_0);
    proc->unk_4C = 31;
}

void func_fe6_0806D868(struct UnkProc0806D82C * proc)
{
    DarkenPals(0x20 - proc->unk_4C);

    proc->unk_4C--;

    if (proc->unk_4C < 0)
        Proc_Break(proc);
}

void func_fe6_0806D894(void)
{
    CleanupGame(NULL);
    SyncHiOam();
    func_fe6_0806D808();
    func_fe6_0806D81C();
    KillTalkAndEvent();
}

void func_fe6_0806D8B0(void)
{
    struct HelpBoxPrintProc * proc;
    int i;

    SetDispEnable(1, 0, 0, 0, 0);

    SetBgOffset(0, 0, 0);

    ResetText();
    ResetTextFont();
    InitTalkTextFont();

    TmFill(gBg0Tm, 0);

    CpuFastFill(0, (void *) VRAM + GetBgChrOffset(3) + 0 * CHR_SIZE, CHR_SIZE);

    proc = SpawnProc(ProcScr_Unk_08677FE0, PROC_TREE_3);

    for (i = 0; i < (int) ARRAY_COUNT(proc->text); i++)
    {
        struct Text * text = gUnkText_0203D370 + i;

        InitText(text, 24);
        ClearText(text);

        Text_SetColor(text, TEXT_COLOR_0123);

        proc->text[i] = text;

        PutText(text, gBg0Tm + TM_OFFSET(3, 2 * i + gUnk_0867619C[gUnk_0203D36C].y_offset));
    }

    proc->font = NULL;
    proc->line = 0;
    proc->str_it = DecodeMsg(gUnk_0867619C[gUnk_0203D36C].msg);

    gUnk_0203D36C++;

    EnableBgSync(BG0_SYNC_BIT);
}

void func_fe6_0806D9B4(void)
{
    SetDispEnable(1, 1, 1, 1, 1);
    CpuFastFill(0, (void *) VRAM + 0x6000, 0x2000);
}

void func_fe6_0806D9F4(int chapter, int x, int y)
{
    InitUnits();

    gPlaySt.chapter = chapter;

    func_fe6_08029084();

    gPlaySt.vision = GetChapterInfo(gPlaySt.chapter)->fog;

    gBmSt.camera.x = GetCameraCenteredX(x * 16 + 8);
    gBmSt.camera.y = GetCameraCenteredY(y * 16 + 8);

    RefreshEntityMaps();
    RenderMap();
    RefreshUnitSprites();
}

void func_fe6_0806DA54(void)
{
    // TODO: constants?
    func_fe6_0806D9F4(CHAPTER_4, 11, 11);
    CpuFastCopy(gPal + (BGPAL_TILESET + 5) * 0x10, gPal + BGPAL_TILESET * 0x10, 5 * 0x20);
    func_fe6_0805B644(gPal, 26, 6, 8);
    EnablePalSync();
}

void func_fe6_0806DA90(void)
{
    func_fe6_0806D9F4(CHAPTER_1, 7, 5);
}

void func_fe6_0806DAA0(void)
{
    func_fe6_0806D9F4(CHAPTER_10_A, 0, 20);
}

void func_fe6_0806DAB0(void)
{
    func_fe6_0806D9F4(CHAPTER_2, 7, 10);
}

void func_fe6_0806DAC0(void)
{
    func_fe6_0806D9F4(CHAPTER_22, 15, 9);
}

void func_fe6_0806DAD0(void)
{
    struct Unit * unit = GetUnitByPid(PID_ROY);
    SetUnitHp(unit, GetUnitCurrentHp(unit) - 10);
}

EventScr const * func_fe6_0806DAF0(int arg_0, int arg_1)
{
    return gUnk_08676738[arg_1];
}

void func_fe6_0806DB00(int arg_0, ProcPtr proc)
{
    StartEventLocking(gUnk_08676738[arg_0], proc);

    gUnk_0203D368 = arg_0;
    gUnk_0203D36C = 0;
}

void func_fe6_0806DB2C(void)
{
    Proc_EndEachMarked(PROC_MARK_1);
}

void func_fe6_0806DB38(void)
{
    if (GetGameTime() % 2 == 0)
        return;

    gBmSt.camera.x ^= 2;
}

void func_fe6_0806DB58(ProcPtr proc)
{
    PlaySe(SONG_26A);
    SpawnProc(ProcScr_Unk_08676844, proc);
}

void func_fe6_0806DB88(void)
{
    Proc_EndEach(ProcScr_Unk_08676844);
    func_fe6_080030B4(4);
}

void func_fe6_0806DBA0(struct UnkProc_08676854 * proc)
{
    proc->unk_64 = 0;
}

void func_fe6_0806DBA8(struct UnkProc_08676854 * proc)
{
    if (GetGameTime() % 2 != 0)
    {
        gBmSt.camera.x ^= 2;

        proc->unk_64++;

        if (proc->unk_64 > 5)
            Proc_Break(proc);
    }

    SetBgOffset(2, gBmSt.camera.x - (u16) gBmSt.map_render_anchor.x * 16, gBmSt.camera.y - (u16) gBmSt.map_render_anchor.y * 16);
    SetBgOffset(3, gBmSt.camera.x - (u16) gBmSt.map_render_anchor.x * 16, gBmSt.camera.y - (u16) gBmSt.map_render_anchor.y * 16);
}

void func_fe6_0806DC24(ProcPtr parent)
{
    SpawnProc(ProcScr_Unk_08676854, parent);
}

void func_fe6_0806DC38(void)
{
    Proc_EndEach(ProcScr_Unk_08676854);
}

void func_fe6_0806DC48(struct UnkProc_0867686C * proc)
{
    proc->unk_64 = 0;
}

void func_fe6_0806DC50(struct UnkProc_0867686C * proc)
{
    if (GetGameTime() % 8 == 0)
    {
        if (proc->unk_64++ > 11)
            Proc_Break(proc);

        func_fe6_08001E68(0, 0x20, 0x20, -1);
        ColorFadeTick2();
    }
}

void func_fe6_0806DC90(ProcPtr parent)
{
    SpawnProc(ProcScr_Unk_0867686C, parent);
}

void func_fe6_0806DCA4(void)
{
    InitBgs(NULL);

    SetDispEnable(1, 1, 1, 1, 1);

    CpuFastFill(0, (void *) VRAM + GetBgChrOffset(3), CHR_SIZE);
    CpuFastFill(0, (void *) VRAM + 0x300 * CHR_SIZE, CHR_SIZE * 0x100);
}

void func_fe6_0806DD08(void)
{
    SetDispEnable(1, 0, 0, 0, 0);

    SetBgOffset(0, 0, 0);
    TmFill(gBg0Tm, 0);

    ResetText();
    InitTalkTextFont();

    InitText(&gUnkText_0203D3A0, 14);
    PutDrawText(&gUnkText_0203D3A0, gBg0Tm + TM_OFFSET(8, 9),
        TEXT_COLOR_0123, 0, 0, DecodeMsg(MSG_24A));
}

void func_fe6_0806DD84(ProcPtr parent)
{
    SpawnProc(ProcScr_Unk_0867688C, parent);
}

bool func_fe6_0806DD98(void)
{
    if (FindProc(ProcScr_Unk_0867688C) != NULL)
        return TRUE;

    Proc_EndEach(ProcScr_Unk_08677FE0);
    func_fe6_0806DCA4();

    return FALSE;
}

void func_fe6_0806DDC4(struct UnkProc_0806DDC4 * proc)
{
    proc->unk_44 = 0xFF;
}

void func_fe6_0806DDCC(struct UnkProc_0806DDC4 * proc)
{
    proc->unk_45 = 1;
}

void func_fe6_0806DDD4(void)
{
    SetWeather(WEATHER_NONE);
}

void func_fe6_0806DDE0(void)
{
    PlaySe(SONG_C4);
    SetWeather(WEATHER_SANDSTORM);
}

void func_fe6_0806DE00(void)
{
    PlaySe(SONG_269);
}

void func_fe6_0806DE20(void)
{
    PlaySe(SONG_269);
}

void func_fe6_0806DE40(void)
{
    PlaySe(SONG_6A);
}

void func_fe6_0806DE5C(struct UnkProc_086768C4 * proc)
{
    StartBgm(SONG_43, NULL);
    proc->unk_64 = 17600;
}

void func_fe6_0806DE78(struct UnkProc_086768C4 * proc)
{
    proc->unk_64--;

    if (proc->unk_64 == 0)
    {
        StartBgm(SONG_34, NULL);
        Proc_Break(proc);
    }
}

void func_fe6_0806DEA0(ProcPtr parent)
{
    SpawnProc(ProcScr_Unk_086768C4, parent);
}

void func_fe6_0806DEB4(void)
{
    Proc_EndEach(ProcScr_Unk_086768C4);
}

bool func_fe6_0806DEC4(void)
{
    // this is funny
#if BUGFIX
    if (IsLilinaBlue())
#else
    if (IsLilinaBlue != NULL)
#endif
    {
        struct Unit * roy = GetUnitByPid(PID_ROY);

        if (GetUnitSupportLevel(roy, GetUnitSupportNumByPid(roy, PID_LILINA)) > 2)
            return TRUE;
    }

    return FALSE;
}

void func_fe6_0806DEF8(void)
{
    RenderMapForFade();
    gPlaySt.vision = 0;
    RefreshEntityMaps();
    RefreshUnitSprites();
    RenderMap();
}

void func_fe6_0806DF18(struct UnkProc_086768DC * proc)
{
    proc->unk_64 = 1;

    if (CheckFlag(FLAG_123))
        proc->unk_64++;
}

void func_fe6_0806DF3C(struct UnkProc_086768DC * proc)
{
    for (;;)
    {
        if (!CanStartMu())
            return;

        proc->unk_64 = GetNextAvailableBlueUnitId(proc->unk_64);

        if (proc->unk_64 != 0)
        {
            TryMoveUnitDisplayed(proc->unk_4C, GetUnit(proc->unk_64), 8, (gBmSt.camera.x >> 4) + 13);
            proc->unk_64++;
            continue;
        }

        Proc_Break(proc);
        return;
    }
}

void func_fe6_0806DF94(ProcPtr parent)
{
    struct UnkProc_086768DC * proc;

    proc = SpawnProc(ProcScr_Unk_086768DC, parent);
    proc->unk_4C = parent;
}

bool func_fe6_0806DFAC(void)
{
    return FindProc(ProcScr_Unk_086768DC) != NULL ? TRUE : FALSE;
}

void func_fe6_0806DFC4(struct UnkProc_086768FC * proc)
{
    proc->unk_64 = 0x100;
}

void func_fe6_0806DFD0(struct UnkProc_08676914 * proc)
{
    proc->unk_64 = 0;
}

void func_fe6_0806DFD8(struct UnkProc_086768FC * proc)
{
    proc->unk_64 -= 3;

    if (proc->unk_64 <= 0)
    {
        proc->unk_64 = 0;
        Proc_Break(proc);
    }

    SetBgmVolume(proc->unk_64);
}

void func_fe6_0806E004(struct UnkProc_08676914 * proc)
{
    proc->unk_66++;

    if ((proc->unk_66 & 1) != 0)
    {
        proc->unk_64++;

        if (proc->unk_64 >= 0x100)
            Proc_Break(proc);

        SetBgmVolume(proc->unk_64);
    }
}

void func_fe6_0806E040(void)
{
    func_fe6_080030B4(0);
}

void func_fe6_0806E04C(ProcPtr parent)
{
    SpawnProc(ProcScr_Unk_086768FC, parent);
}

void func_fe6_0806E060(ProcPtr parent)
{
    SpawnProcLocking(ProcScr_Unk_08676914, parent);
}

void func_fe6_0806E074(void)
{
    int i;

    for (i = FACTION_BLUE; i < FACTION_BLUE + 0x40; i++)
    {
        struct Unit * unit = GetUnit(i);

        if (unit == NULL)
            continue;

        if (unit->pinfo == NULL)
            continue;

        if ((unit->flags & UNIT_FLAG_DEAD) != 0)
            continue;

        unit->flags &= ~(UNIT_FLAG_HIDDEN | UNIT_FLAG_TURN_ENDED | UNIT_FLAG_NOT_DEPLOYED);
    }

    RefreshEntityMaps();
    RefreshUnitSprites();
}

void func_fe6_0806E0B8(void)
{
    int i, j;
    int next_slot = 1;

    for (i = FACTION_BLUE + 1; i < FACTION_BLUE + 0x40; i++)
    {
        struct Unit * unit = GetUnit(i);

        if (unit == NULL)
            continue;

        if (unit->pinfo == NULL)
            continue;

        if ((unit->flags & UNIT_FLAG_DEAD) != 0)
            continue;

        switch (UNIT_PID(unit))
        {
            case PID_ROY:
                unit->flags &= ~(UNIT_FLAG_HIDDEN | UNIT_FLAG_NOT_DEPLOYED);
                unit->x = gUnk_0867692C[0].x;
                unit->y = gUnk_0867692C[0].y;
                break;

            default:
                for (j = 0; gUnk_0203DCA7[j] != -1; j++)
                {
                    if (gUnk_0203DCA7[j] == i)
                    {
                        unit->flags &= ~(UNIT_FLAG_HIDDEN | UNIT_FLAG_NOT_DEPLOYED);
                        unit->x = gUnk_0867692C[next_slot].x;
                        unit->y = gUnk_0867692C[next_slot].y;
                        next_slot++;
                    }
                }

                break;
        }
    }

    RefreshEntityMaps();
    RefreshUnitSprites();
}

void func_fe6_0806E178(void)
{
    int i, j, pid;
    int next_slot = 2;

    for (i = FACTION_BLUE + 1; i < FACTION_BLUE + 0x40; i++)
    {
        struct Unit * unit = GetUnit(i);

        if (unit == NULL)
            continue;

        if (unit->pinfo == NULL)
            continue;

        if ((unit->flags & UNIT_FLAG_DEAD) != 0)
            continue;

        switch (UNIT_PID(unit))
        {
            case PID_ROY:
                unit->flags |= UNIT_FLAG_HIDDEN;
                unit->x = gUnk_0867695C[0].x;
                unit->y = gUnk_0867695C[0].y;
                break;

            case PID_MERLINUS:
                unit->flags &= ~(UNIT_FLAG_HIDDEN | UNIT_FLAG_NOT_DEPLOYED);
                unit->x = gUnk_0867695C[1].x;
                unit->y = gUnk_0867695C[1].y;
                break;

            default:
                for (j = 0; gUnk_0203DCA7[j] != -1; j++)
                {
                    if (gUnk_0203DCA7[j] == i)
                    {
                        unit->flags &= ~(UNIT_FLAG_HIDDEN | UNIT_FLAG_NOT_DEPLOYED);
                        unit->x = gUnk_0867695C[next_slot].x;
                        unit->y = gUnk_0867695C[next_slot].y;
                        next_slot++;
                    }
                }

                break;
        }
    }

    RefreshEntityMaps();
    RefreshUnitSprites();
}

void func_fe6_0806E240(void)
{
    int i;

    for (i = FACTION_BLUE + 1; i < FACTION_BLUE + 0x40; i++)
    {
        struct Unit * unit = GetUnit(i);

        if (unit == NULL)
            continue;

        if (unit->pinfo == NULL)
            continue;

        if (UNIT_PID(unit) != PID_ROY)
            continue;

        unit->flags &= ~(UNIT_FLAG_HIDDEN | UNIT_FLAG_NOT_DEPLOYED);
        break;
    }
}

void func_fe6_0806E278(void)
{
    if (GetItemIid(gBattleUnitA.weapon_before) == IID_BINDINGBLADE ||
        GetItemIid(gBattleUnitB.weapon_before) == IID_BINDINGBLADE)
    {
        SetFlag(FLAG_123);
    }
}

void UpdateEndingId(void)
{
    if (gPlaySt.chapter == CHAPTER_FINAL)
    {
        if (CheckFlag(FLAG_123) && IsFaeBlue())
        {
            gUnk_0203D3D9 = 0;
        }
        else
        {
            gUnk_0203D3D9 = 1;
        }
    }
    else
    {
        gUnk_0203D3D9 = 2;
    }
}

fu8 GetEndingId(void)
{
    UpdateEndingId();
    return gUnk_0203D3D9;
}

void StartGameEndingScene(ProcPtr parent)
{
    StartEventLocking(gUnk_086770D4[GetEndingId()], parent);
}

void func_fe6_0806E32C(void)
{
    switch (GetEndingId())
    {
        case ENDING_0:
            gUnk_0203D3D8 = 0;
            func_fe6_080914DC();
            return;

        case ENDING_1:
            gUnk_0203D3D8 = 1;
            func_fe6_080914DC();
            return;

        case ENDING_2:
            gUnk_0203D3D8 = 0x80;
            func_fe6_0809154C();
            return;
    }
}

void func_fe6_0806E36C(struct UnkProc_08677348 * proc)
{
    if (gUnk_030048A4 == 0)
    {
        Decompress(gUnk_0834B69C, (void *) VRAM + 1 * CHR_SIZE);
        proc->unk_3C = gUnk_086772FC;
        proc->unk_38 = -28;
    }
    else if (gUnk_030048A4 == 1)
    {
        Decompress(gUnk_0834B69C, (void *) VRAM + 1 * CHR_SIZE);
        proc->unk_3C = gUnk_0867730C;
        proc->unk_38 = -28;
    }
    else if (gUnk_030048A4 == 2)
    {
        Decompress(gUnk_08349A98, (void *) VRAM + 1 * CHR_SIZE);
        proc->unk_3C = gUnk_0867731C;
        proc->unk_38 = -48;
    }
    else if (gUnk_030048A4 == 3)
    {
        Decompress(gUnk_0834E1D4, (void *) VRAM + 1 * CHR_SIZE);
        proc->unk_3C = gUnk_08677327;
        proc->unk_38 = -24;
    }

    proc->unk_30 = 0;
    proc->unk_2C = -144;
    proc->unk_34 = 0;
    proc->unk_40 = 0;

    func_fe6_0806E684(0, proc->unk_3C[0]);
    SetBgOffset(0, proc->unk_38, proc->unk_2C);
}

void func_fe6_0806E430(struct UnkProc_08677348 * proc)
{
    proc->unk_30++;

    if (proc->unk_30 < 7)
        return;

    proc->unk_30 = 0;

    proc->unk_2C++;
    SetBgOffset(0, proc->unk_38, proc->unk_2C);

    proc->unk_34++;

    if ((proc->unk_34 % 24) != 0)
        return;

    if (proc->unk_40 != 0)
    {
        func_fe6_0806E684(proc->unk_34 / 8, -3);
    }
    else
    {
        if (proc->unk_3C[proc->unk_34 / 24] == -2 && proc->unk_3C == gUnk_08677327)
        {
            Decompress(gUnk_08352160, (void *) VRAM + 1 * CHR_SIZE);
        }

        func_fe6_0806E684(proc->unk_34 / 8, proc->unk_3C[proc->unk_34 / 24]);
    }

    if (proc->unk_40 != 0 || proc->unk_3C[proc->unk_34 / 24] == -3)
    {
        proc->unk_40++;

        if (proc->unk_40 == 4)
            gUnk_030048B8 = 1;
    }
}

void func_fe6_0806E50C(ProcPtr parent)
{
    SpawnProc(ProcScr_Unk_08677348, parent);
}

void func_fe6_0806E520(void)
{
    int i;

    InitBgs(gUnk_08677360);
    DisableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);

    gDispIo.disp_ct.mode = DISPCNT_BG_MODE_REGULAR;
    SetDispEnable(1, 0, 1, 0, 0);
    SetWinEnable(0, 0, 0);

    SetBlendAlpha(0x10, 0x10);
    SetBlendTargetA(1, 0, 0, 0, 0);
    SetBlendTargetB(0, 0, 1, 0, 0);

    UnpackUiWindowFrameGraphics();

    TmFill(gBg0Tm, 0);
    TmFill(gBg1Tm, 0);
    SetBgOffset(2, 0, 0);

    Decompress(gUnk_0836F6D4, (void *) VRAM + GetBgChrOffset(2));
    Decompress(gUnk_08373F80, gBg2Tm);
    Decompress(gUnk_08374670, gBuf);

    for (i = 0; i < 8; i++)
    {
        func_fe6_0805B5C8((u16 const *) gBuf, i, 1, 2);
    }

    ApplyPalettes(gBuf, 0, 0x10);
    gPal[0] = 0;
    ApplyPalette(gUnk_08353308, 15);

    func_fe6_0809892C(1, 0, 1, 0, 1);

    InitScanlineEffect();
    SetOnHBlankA(OnHBlank_08069FD8);
    func_fe6_0806A7AC();

    gUnk_030048B8 = 0;

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT | BG2_SYNC_BIT | BG3_SYNC_BIT);
}

void func_fe6_0806E684(int arg_0, int arg_1)
{
    int iy, ix;

    if (arg_1 == -2)
        arg_1 = 0;

    for (iy = -1; iy < 3; iy++)
    {
        u16 * tm = gBg0Tm + TM_OFFSET(0, (arg_0 + iy) & 0x1F);

        if (iy == -1 || iy == 2)
        {
            for (ix = 0; ix < 0x20; ix++)
                *tm++ = 0;
        }
        else if (arg_1 == -1 || arg_1 == -3)
        {
            for (ix = 0; ix < 0x20; ix++)
                *tm++ = 0;
        }
        else
        {
            // TODO: constants
            int base = TILEREF(arg_1 * 0x40 + iy * 0x20 + 1, 15);

            for (ix = 0; ix < 0x20; ix++)
                *tm++ = base + ix;
        }
    }

    EnableBgSync(BG0_SYNC_BIT);
}

void func_fe6_0806E714(ProcPtr proc)
{
    if (gUnk_030048B8 != 0)
        Proc_Break(proc);
}

void func_fe6_0806E730(void)
{
    SetOnHBlankA(NULL);
}

void func_fe6_0806E73C(void)
{
    InitBgs(NULL);

    SetDispEnable(1, 1, 1, 1, 1);

    CpuFastFill(0, (void *) VRAM + GetBgChrOffset(3), CHR_SIZE);
    CpuFastFill(0, (void *) VRAM + 0x6000, 0x2000); // TODO: constants
}

void func_fe6_0806E7A0(ProcPtr parent)
{
    gUnk_030048A4 = 0;
    SpawnProc(ProcScr_Unk_08677378, parent);
}

void func_fe6_0806E7BC(ProcPtr parent)
{
    gUnk_030048A4 = 1;
    SpawnProc(ProcScr_Unk_08677378, parent);
}

void func_fe6_0806E7D8(ProcPtr parent)
{
    gUnk_030048A4 = 2;
    SpawnProc(ProcScr_Unk_08677378, parent);
}

void func_fe6_0806E7F4(ProcPtr parent)
{
    gUnk_030048A4 = 3;
    SpawnProc(ProcScr_Unk_08677378, parent);
}

bool func_fe6_0806E810(void)
{
    if (FindProc(ProcScr_Unk_08677378) != NULL)
        return TRUE;

    Proc_EndEach(ProcScr_Unk_08677348);
    func_fe6_0806DCA4();

    return FALSE;
}
