#include "common.h"

#include "random.h"
#include "hardware.h"
#include "sound.h"
#include "talk.h"
#include "event.h"
#include "util.h"
#include "unit.h"
#include "item.h"
#include "bm.h"
#include "bmfx.h"
#include "gold.h"
#include "faction.h"
#include "chapterinfo.h"
#include "chapterevents.h"
#include "save_stats.h"

#include "constants/flags.h"
#include "constants/pids.h"
#include "constants/chapters.h"

// TODO: move
bool IsKleinInNonBlueTeam(void); // NOTE: this should return bool
bool IsKleinInBlueTeam(void); // NOTE: this should return bool

extern u16 const gUnk_08342A98[]; // colors

extern u8 gUnk_030048A8;
extern u32 EWRAM_DATA gUnk_0203D354;
extern u32 EWRAM_DATA gUnk_0203D358;

struct HardModeBonusLevelsOverrideEnt
{
    /* 00 */ u8 pid;
    /* 04 */ int bonus_levels;
};

extern struct HardModeBonusLevelsOverrideEnt CONST_DATA gHardModeBonusLevelsOverrideList[];

bool EvtCheck_IsHard(void)
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

    if (!IsKleinInNonBlueTeam())
        return FALSE;

    return EventInfoCheckTalk(info, PID_SHANNA, PID_THEA);
}

bool func_fe6_0806BB68(struct EventInfo * info)
{
    if (!CheckFlag(FLAG_CHAPTER11A_7))
        return FALSE;

    if (!IsKleinInBlueTeam())
        return FALSE;

    return EventInfoCheckTalk(info, PID_SHANNA, PID_THEA);
}

bool func_fe6_0806BB9C(struct EventInfo * info)
{
    if (CheckFlag(FLAG_CHAPTER11A_7))
        return FALSE;

    if (!IsKleinInBlueTeam())
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

    if (DivRem(RandNextB(), 11) == 0)
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
#  define IsKleinInNonBlueTeamBugged IsKleinInNonBlueTeam
#  define IsKleinInBlueTeamBugged IsKleinInBlueTeam
#else
#  define IsKleinInNonBlueTeamBugged ((int (*)(void))(IsKleinInNonBlueTeam))
#  define IsKleinInBlueTeamBugged ((int (*)(void))(IsKleinInBlueTeam))
#endif

bool func_fe6_0806BE00(struct EventInfo * info)
{
    if (CheckFlag(FLAG_CHAPTER10B_8))
        return FALSE;

    if (!IsKleinInNonBlueTeamBugged())
        return FALSE;

    return EventInfoCheckTalk(info, PID_SHANNA, PID_THEA);
}

bool func_fe6_0806BE30(struct EventInfo * info)
{
    if (CheckFlag(FLAG_CHAPTER10B_5))
        return FALSE;

    if (!IsKleinInBlueTeamBugged())
        return FALSE;

    return EventInfoCheckTalk(info, PID_SHANNA, PID_THEA);
}

bool func_fe6_0806BE60(struct EventInfo * info)
{
    if (!CheckFlag(FLAG_CHAPTER10B_5))
        return FALSE;

    if (!IsKleinInBlueTeamBugged())
        return FALSE;

    return EventInfoCheckTalk(info, PID_SHANNA, PID_THEA);
}

#undef IsKleinInBlueTeamBugged
#undef IsKleinInNonBlueTeamBugged

bool func_fe6_0806BE90(struct EventInfo * info)
{
    if (!func_fe6_0806C3CC())
        return FALSE;

    return EventInfoCheckTalk(info, PID_SHANNA, PID_THEA);
}

bool func_fe6_0806BEB8(struct EventInfo * info)
{
    if (!CheckFlag(9)) // TODO: which chapter?
        return FALSE;

    if (func_fe6_0806C3CC())
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
    if (!CheckFlag(FLAG_FIRST_CHAPTER))
        return FALSE;

    if (IsPidInNonBlueTeam(PID_UNKNOWN_DA))
        return FALSE;

    return TRUE;
}

bool func_fe6_0806BF38(void)
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

void func_fe6_0806BFC0(void)
{
    SetFogVision(0);
}

void func_fe6_0806BFCC(void)
{
    SetGold(GetGold() + 5000);
}

void func_fe6_0806BFE4(int gold_amount)
{
    if (GetGold() >= gold_amount)
    {
        SetGold(GetGold() - gold_amount);
    }
}

void func_fe6_0806C000(struct Unit * unit)
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

void func_fe6_0806C068(fu8 pid)
{
    func_fe6_0806C000(GetUnitByPid(pid));
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

bool func_fe6_0806C1A4(void)
{
    return IsPidBlue(PID_BORS);
}

bool func_fe6_0806C1B4(void)
{
    return IsPidBlue(PID_LILINA);
}

bool func_fe6_0806C1C4(void)
{
    return IsPidBlue(PID_ELEN);
}

bool func_fe6_0806C1D4(void)
{
    return IsPidBlue(PID_RAIGH);
}

bool func_fe6_0806C1E4(void)
{
    return IsPidBlue(PID_SUE);
}

bool func_fe6_0806C1F4(void)
{
    return IsPidBlue(PID_CATH);
}

bool func_fe6_0806C204(void)
{
    return IsPidBlue(PID_MELADY);
}

bool func_fe6_0806C214(void)
{
    return IsPidBlue(PID_ZEISS);
}

bool func_fe6_0806C224(void)
{
    return IsPidBlue(PID_SOPHIA);
}

bool func_fe6_0806C234(void)
{
    return IsPidBlue(PID_JUNO);
}

bool func_fe6_0806C244(void)
{
    return IsPidBlue(PID_ZELOT);
}

bool func_fe6_0806C254(void)
{
    return IsPidBlue(PID_ELFFIN);
}

bool IsItTeamFae(void)
{
    return IsPidBlue(PID_FAE);
}

bool func_fe6_0806C274(void)
{
    return IsPidBlue(PID_SIN);
}

bool func_fe6_0806C284(void)
{
    return IsPidBlue(PID_DAYAN);
}

bool IsKleinInBlueTeam(void)
{
    return IsPidBlue(PID_KLEIN);
}

bool func_fe6_0806C2A4(void)
{
    return IsPidBlue(PID_THEA);
}

bool func_fe6_0806C2B4(void)
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

bool IsPidInNonBlueTeam(fu8 pid)
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

bool func_fe6_0806C34C(void)
{
    return IsPidInNonBlueTeam(PID_THEA);
}

bool func_fe6_0806C35C(void)
{
    return IsPidInNonBlueTeam(PID_UNKNOWN_5E);
}

bool IsKleinInNonBlueTeam(void)
{
    return IsPidInNonBlueTeam(PID_KLEIN);
}

bool func_fe6_0806C37C(void)
{
    return IsPidInNonBlueTeam(PID_CATH);
}

bool func_fe6_0806C38C(void)
{
    return IsPidInNonBlueTeam(PID_HUGH);
}

bool func_fe6_0806C39C(void)
{
    return IsPidInNonBlueTeam(PID_GALLE);
}

bool func_fe6_0806C3AC(void)
{
    return IsPidInNonBlueTeam(PID_UNKNOWN_C4);
}

bool func_fe6_0806C3BC(void)
{
    return IsPidInNonBlueTeam(PID_UNKNOWN_C6);
}

bool func_fe6_0806C3CC(void)
{
    return IsPidInNonBlueTeam(PID_DOUGLAS);
}

bool func_fe6_0806C3DC(void)
{
    return IsPidInNonBlueTeam(PID_PERCEVAL);
}

bool func_fe6_0806C3EC(void)
{
    return IsPidInNonBlueTeam(PID_UNKNOWN_D5);
}

bool func_fe6_0806C3FC(void)
{
    return IsPidInNonBlueTeam(PID_UNKNOWN_D6);
}

bool func_fe6_0806C40C(void)
{
    return IsPidInNonBlueTeam(PID_UNKNOWN_D7);
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

bool func_fe6_0806C49C(void)
{
    if (gPlaySt.turn > 20)
        return TRUE;

    return FALSE;
}

bool func_fe6_0806C4B0(void)
{
    if (gPlaySt.turn > 25)
        return TRUE;

    return FALSE;
}

bool func_fe6_0806C4C4(void)
{
    if (gPlaySt.turn > 30)
        return TRUE;

    return FALSE;
}

bool func_fe6_0806C4D8(void)
{
    if (gPlaySt.faction != FACTION_BLUE)
        return FALSE;

    return TRUE;
}

bool func_fe6_0806C4EC(void)
{
    if (gPlaySt.faction != FACTION_RED)
        return FALSE;

    return TRUE;
}

bool func_fe6_0806C500(void)
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

bool func_fe6_0806C5A8(void)
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
