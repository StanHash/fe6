
#include "chapter-info.h"

#include "hardware.h"
#include "msg.h"
#include "sram.h"

struct ChapterInfo const* GetChapterInfo(int chapter)
{
    if (chapter < 0)
        return gTrialLoadInfo->chapterInfo;

    return ChapterInfoTable + chapter;
}

u8 const* GetChapterMap(int chapter)
{
    if (chapter >= 0)
        return ChapterAssets[GetChapterInfo(chapter)->assetMap];

    ReadSramFast(sub_80865EC(), gBuf, sub_8086608());
    return gBuf;
}

struct MapChangeInfo const* GetChapterMapChanges(int chapter)
{
    if (chapter >= 0)
        return ChapterAssets[GetChapterInfo(chapter)->assetMapChanges];

    return gTrialLoadInfo->mapChangeInfo;
}

struct ChapterEventInfo const* GetChapterEventInfo(int chapter)
{
    if (chapter >= 0)
        return ChapterAssets[GetChapterInfo(chapter)->assetEventInfo];

    return gTrialLoadInfo->eventInfo;
}

char const* GetChapterUnk_0802BBD0(int chapter)
{
    if (chapter >= 0)
        return DecodeMsg(GetChapterInfo(chapter)->msg_38);

    return gTrialLoadInfo->msg_0C;
}
