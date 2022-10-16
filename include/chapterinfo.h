#pragma once

#include "common.h"

struct ChapterInfo const * GetChapterInfo(int chapter);
u8 const * GetChapterMap(int chapter);
struct MapChangeInfo const * GetChapterMapChanges(int chapter);
struct ChapterEventInfo const * GetChapterEventInfo(int chapter);
char const * GetChapterUnk_0802BBD0(int chapter);
