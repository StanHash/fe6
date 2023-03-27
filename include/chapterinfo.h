#pragma once

#include "common.h"

#include "event.h"
#include "unit.h"
#include "eventinfo.h"

struct ChapterEventInfo
{
    /* 00 */ EventListScr const * event_list_turn;
    /* 04 */ EventListScr const * event_list_talk;
    /* 08 */ EventListScr const * event_list_tile;
    /* 0C */ EventListScr const * event_list_move;
    /* 10 */ struct UnitInfo const * units_red;
    /* 14 */ struct UnitInfo const * units_blue;
    /* 18 */ EventScr const * event_script_victory;
};

struct ChapterInfo const * GetChapterInfo(int chapter);
u8 const * GetChapterMap(int chapter);
struct MapChangeInfo const * GetChapterMapChanges(int chapter);
struct ChapterEventInfo const * GetChapterEventInfo(int chapter);
char const * GetChapterUnk_0802BBD0(int chapter);
