#include "common.h"

#include "event.h"
#include "unit.h"
#include "item.h"
#include "bm.h"
#include "faction.h"
#include "chapter-info.h"

struct Unk_08666C78
{
    /* 00 */ u8 unk_00;
    /* 04 */ int unk_04;
};

extern struct Unk_08666C78 CONST_DATA gUnk_08666C78[];

bool EvtCheck_IsHard(void)
{
    if (gPlaySt.flags & PLAY_FLAG_HARD)
        return TRUE;

    return FALSE;
}

int sub_806BAB8(u8 arg_00)
{
    struct Unk_08666C78 const* it = gUnk_08666C78;

    while (it->unk_00 != 0)
    {
        if (it->unk_00 == arg_00)
            return it->unk_04;

        ++it;
    }

    return GetChapterInfo(gPlaySt.chapter)->hard_bonus_levels;
}

void sub_806BAF0(void)
{
    if (gPlaySt.flags & PLAY_FLAG_HARD)
    {
        FOR_UNITS_FACTION(FACTION_RED, unit,
        {
            int bonus_levels = sub_806BAB8(unit->pinfo->id);

            if (bonus_levels != 0)
                UnitApplyBonusLevels(unit, bonus_levels);
        })
    }
}

/*

*/
