#include "save_xmap.h"

#include "hardware.h"
#include "msg.h"
#include "util.h"
#include "unit.h"
#include "map.h"
#include "battle.h"
#include "chapterinfo.h"
#include "gbasram.h"
#include "chapterunits.h"
#include "save_core.h"
#include "savelayout.h"

#include "constants/msg.h"
#include "constants/chapters.h"

struct ExtraMapSaveHead EWRAM_DATA gExtraMapSaveHead = { 0 };

void * CONST_DATA gSramExtraMap = SRAM_XMAP_ADDR;
struct ExtraMapInfo * CONST_DATA gExtraMapInfo = (void *) EWRAM_START + 0x40000 - 0x1000; // 0x40000 = EWRAM_SIZE

bool ReadExtraMapSaveHead(void)
{
    ReadSramFast(gSramExtraMap, &gExtraMapSaveHead, sizeof(struct ExtraMapSaveHead));

    if (gExtraMapSaveHead.xmap_magic != XMAP_MAGIC)
        return FALSE;

    if (gExtraMapSaveHead.save_magic32 != SAVE_MAGIC32_XMAP + (GetLang() << 24))
        return FALSE;

    gExtraMapSaveHead.map_sram += (ptrdiff_t) gSramExtraMap;
    gExtraMapSaveHead.info_sram += (ptrdiff_t) gSramExtraMap;

    return TRUE;
}

void const * GetExtraMapMapReadAddr(void)
{
    if (gExtraMapSaveHead.xmap_magic != XMAP_MAGIC)
        return NULL;

    return gExtraMapSaveHead.map_sram;
}

u32 GetExtraMapMapSize(void)
{
    if (gExtraMapSaveHead.xmap_magic != XMAP_MAGIC)
        return 0;

    return gExtraMapSaveHead.map_size;
}

void const * GetExtraMapInfoReadAddr(void)
{
    if (gExtraMapSaveHead.xmap_magic != XMAP_MAGIC)
        return NULL;

    return gExtraMapSaveHead.info_sram;
}

u32 GetExtraMapInfoSize(void)
{
    if (gExtraMapSaveHead.xmap_magic != XMAP_MAGIC)
        return 0;

    return gExtraMapSaveHead.info_size;
}

u16 ExtraMapChecksum(void const * data, int size)
{
    u16 const * data_u16 = data;
    int i, result = 0;

    for (i = 0; i < size / 2; i++)
        result += *data_u16++;

    return result;
}

bool IsExtraMapAvailable(void)
{
    struct ExtraMapSaveHead * buf = (struct ExtraMapSaveHead *) gBuf;

    if (!IsSramWorking())
        return FALSE;

    ReadSramFast(SRAM_XMAP_ADDR, buf, SRAM_XMAP_SIZE);

    if (buf->xmap_magic != XMAP_MAGIC)
        return FALSE;

    if (buf->save_magic32 != SAVE_MAGIC32_XMAP + (GetLang() << 24))
        return FALSE;

    if (buf->xmap_size == 0)
        return FALSE;

    if (buf->xmap_checksum != ExtraMapChecksum(&buf->save_magic32, buf->xmap_size))
        return FALSE;

    return TRUE;
}

void ReadExtraMapInfo(void)
{
    ReadExtraMapSaveHead();

    ReadSramFast(GetExtraMapInfoReadAddr(), gBuf, GetExtraMapInfoSize());
    Decompress(gBuf, gExtraMapInfo);

    gExtraMapInfo->play_st = &gPlaySt;
    gExtraMapInfo->bm_st = &gBmSt;
    gExtraMapInfo->active_unit = &gActiveUnit;
    gExtraMapInfo->unit_lut = gUnitLut;
    gExtraMapInfo->bu_a = &gBattleUnitA;
    gExtraMapInfo->bu_b = &gBattleUnitB;
    gExtraMapInfo->battle_hits = gBattleHits;
    gExtraMapInfo->traps = GetTrap(0);
    gExtraMapInfo->permanent_flags = GetPermanentFlagBits();
    gExtraMapInfo->chapter_frags = GetChapterFlagBits();
}

bool ListAvailableTrialChapters(i8 * list_out)
{
    struct GlobalSaveInfo info;
    ReadGlobalSaveInfo(&info);

    *list_out++ = CHAPTER_TRIAL_A;
    *list_out++ = CHAPTER_TRIAL_B;

    if (info.completed_true)
        *list_out++ = CHAPTER_TRIAL_C;

    if (info.completed_hard)
        *list_out++ = CHAPTER_TRIAL_D;

    if (info.completed_true_hard)
        *list_out++ = CHAPTER_TRIAL_E;

    if (IsExtraMapAvailable())
    {
        ReadExtraMapInfo();
        *list_out++ = -1;
    }

    *list_out = 0;

    return TRUE;
}

char const * func_fe6_080867F0(int chapter)
{
    return GetChapterUnk_0802BBD0(chapter);
}

char const * func_fe6_080867FC(int chapter)
{
    int msg = 0;

    switch (chapter)
    {
        case CHAPTER_TRIAL_A:
            msg = MSG_C7C;
            break;

        case CHAPTER_TRIAL_B:
            msg = MSG_C7F;
            break;

        case CHAPTER_TRIAL_C:
            msg = MSG_C82;
            break;

        case CHAPTER_TRIAL_D:
            msg = MSG_C85;
            break;

        case CHAPTER_TRIAL_E:
            msg = MSG_C88;
            break;

        case -1:
            return gExtraMapInfo->msg_10;

    }

    return DecodeMsg(msg);
}

char const * func_fe6_08086910(int chapter)
{
    int msg = 0;

    switch (chapter)
    {
        case CHAPTER_TRIAL_A:
            msg = MSG_C7D;
            break;

        case CHAPTER_TRIAL_B:
            msg = MSG_C80;
            break;

        case CHAPTER_TRIAL_C:
            msg = MSG_C83;
            break;

        case CHAPTER_TRIAL_D:
            msg = MSG_C86;
            break;

        case CHAPTER_TRIAL_E:
            msg = MSG_C89;
            break;

        case -1:
            return gExtraMapInfo->msg_14;

    }

    return DecodeMsg(msg);
}

void CreateTrialChapterBonusUnits(void)
{
    int count = GetGlobalCompletedPlaythroughCount() + 1;

    gMapHidden = NULL;

    if (count > 1)
        BatchCreateUnits(UnitInfo_TrialBonusUnitA);

    if (count > 2)
        BatchCreateUnits(UnitInfo_TrialBonusUnitB);

    if (count > 3)
        BatchCreateUnits(UnitInfo_TrialBonusUnitC);

    if (count > 4)
        BatchCreateUnits(UnitInfo_TrialBonusUnitD);

    if (count > 5)
        BatchCreateUnits(UnitInfo_TrialBonusUnitE);

    if (count > 6)
        BatchCreateUnits(UnitInfo_TrialBonusUnitF);

    if (count > 7)
        BatchCreateUnits(UnitInfo_TrialBonusUnitG);

    if (count > 9)
        BatchCreateUnits(UnitInfo_TrialBonusUnitH);
}
