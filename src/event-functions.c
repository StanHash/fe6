#include "common.h"

#include "event.h"
#include "unit.h"
#include "item.h"
#include "bm.h"
#include "faction.h"
#include "chapter-info.h"

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

int GetHardModeBonusLevelsByPid(u8 pid)
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

/*

bool func_fe6_0806BB34(void * unk)
{
    if (CheckFlag(10))
        return FALSE;

    if (!IsKleinInNonBlueTeam())
        return FALSE;

    return EventInfoCheckTalk(unk, 0x31, 0x2E);
}

*/
