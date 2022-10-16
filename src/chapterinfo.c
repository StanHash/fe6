#include "chapterinfo.h"

#include "hardware.h"
#include "msg.h"
#include "sram.h"

struct ChapterInfo const * GetChapterInfo(int chapter)
{
    if (chapter < 0)
        return gTrialLoadInfo->chapter_info;

    return ChapterInfoTable + chapter;
}

u8 const * GetChapterMap(int chapter)
{
    if (chapter >= 0)
        return ChapterAssets[GetChapterInfo(chapter)->asset_map];

    ReadSramFast(func_fe6_080865EC(), gBuf, func_fe6_08086608());
    return gBuf;
}

struct MapChangeInfo const * GetChapterMapChanges(int chapter)
{
    if (chapter >= 0)
        return ChapterAssets[GetChapterInfo(chapter)->asset_map_changes];

    return gTrialLoadInfo->map_change_info;
}

struct ChapterEventInfo const * GetChapterEventInfo(int chapter)
{
    if (chapter >= 0)
        return ChapterAssets[GetChapterInfo(chapter)->asset_event_info];

    return gTrialLoadInfo->event_info;
}

char const * GetChapterUnk_0802BBD0(int chapter)
{
    if (chapter >= 0)
        return DecodeMsg(GetChapterInfo(chapter)->msg_38);

    return gTrialLoadInfo->msg_0C;
}
