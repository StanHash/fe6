
#include "move.h"

struct MoveStats
{
    /* 00 */ int count;
    /* 04 */ int totalSize;
};

struct MoveEntry
{
    /* 00 */ void const* src;
    /* 04 */ void* dest;
    /* 08 */ u16 size;
    /* 0A */ u16 mode;
};

enum { MOVE_MAX = 0x20 };

enum
{
    MOVE_MODE_COPY,
    MOVE_MODE_COPY_FAST,
    MOVE_MODE_FILL_FAST,
};

struct MoveStats EWRAM_DATA gMoveStats = {};
struct MoveEntry EWRAM_DATA gMoveList[MOVE_MAX] = {};

static void ClearMoveList(void)
{
    int i;

    gMoveStats.count = 0;
    gMoveStats.totalSize = 0;

    for (i = 0; i < MOVE_MAX; ++i)
    {
        gMoveList[i].src = NULL;
        gMoveList[i].dest = NULL;
        gMoveList[i].size = 0;
        gMoveList[i].mode = 0;
    }

    gMoveList[0].src = 0;
}

void RegisterDataMove(void const* src, void* dst, int size)
{
    struct MoveEntry* entry = gMoveList + gMoveStats.count;

    entry->src = src;
    entry->dest = dst;
    entry->size = size;
    entry->mode = (size & 0x1F)
        ? MOVE_MODE_COPY
        : MOVE_MODE_COPY_FAST;

    gMoveStats.totalSize += size;
    gMoveStats.count++;
}

void RegisterDataFill(u32 value, void* dst, int size)
{
    struct MoveEntry* entry = gMoveList + gMoveStats.count;

    entry->src = (void const*) value;
    entry->dest = dst;
    entry->size = size;
    entry->mode = MOVE_MODE_FILL_FAST;

    gMoveStats.totalSize += size;
    gMoveStats.count++;
}

void ApplyDataMoves(void)
{
    struct MoveEntry* it = gMoveList;
    int i;

    for (i = 0; i < gMoveStats.count; ++i)
    {
        switch (it->mode)
        {

        case MOVE_MODE_COPY:
            CpuCopy16(it->src, it->dest, it->size);
            break;

        case MOVE_MODE_COPY_FAST:
            CpuFastCopy(it->src, it->dest, it->size);
            break;

        case MOVE_MODE_FILL_FAST:
            CpuFastFill((u32) it->src, it->dest, it->size);
            break;

        }

        it++;
    }

    ClearMoveList();
}
