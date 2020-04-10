
// TODO: figure out what to do with this file

#include "gba/gba.h"
#include "types.h"

#include "hardware.h"

#include "unks.h"

static void sub_800CDB8(struct UnitInfo const* info, struct Unit* unit, ProcPtr proc);

static int sUnk_085C3FD8 = 0;
static int sUnk_030000F0;

u8 CONST_DATA gUnk_085C3FDC[] = { 9, 27, 28, 31, 38, 1, 0 };

void sub_800CCD4(void)
{
    sUnk_085C3FD8++;
}

void sub_800CCF0(struct UnitInfo const* info, ProcPtr parent)
{
    struct Unit* unit;

    if (sub_800F210(info))
        return;

    if (info->factionId == FACTION_ID_BLUE)
        unit = GetUnitByCharId(info->pid);
    else
        unit = NULL;

    if (!unit)
        unit = LoadUnit(info);

    if ((gPlaySt.flags & PLAY_FLAG_HARD) && info->factionId == FACTION_ID_RED)
        sub_80178F4(unit, GetChapterDefinition(gPlaySt.chapter)->hardBonusLevels);

    sub_800CDB8(info, unit, parent);
    RefreshEntityMaps();
}

void sub_800CD98(struct UnitInfo const* info, struct Unit* unit)
{
    sub_800CDB8(info, unit, NULL);
    RefreshEntityMaps();
}

static void sub_800CDB8(struct UnitInfo const* info, struct Unit* unit, ProcPtr parent)
{
    if (!unit)
        return;

    if (parent && !(unit->state & US_UNDER_A_ROOF))
    {
        TryMoveUnit(unit, info->xLoad, info->yLoad, FALSE);
        RefreshSMS();

        if (info->xLoad != info->xMove || info->yLoad != info->yMove)
            sub_800EEA0(parent, unit, info->xMove, info->yMove);
    }
    else
    {
        TryMoveUnit(unit, info->xMove, info->yMove, TRUE);
        RefreshSMS();
    }
}

Bool sub_800CE44(void)
{
    if (gKeySt->held & R_BUTTON)
        return TRUE;

    return FALSE;
}

Bool sub_800CE74(void)
{
    sUnk_030000F0 = 0;
    return TRUE;
}

int sub_800CE90(void)
{
    return gUnk_085C3FDC[sUnk_030000F0++];
}
