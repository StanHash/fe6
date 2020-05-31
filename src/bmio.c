
#include "common.h"

#include "hardware.h"
#include "proc.h"
#include "bm.h"
#include "unitsprite.h"

#include "constants/video-global.h"

struct TsImgAnim
{
    /* 00 */ u16 time;
    /* 02 */ u16 size;
    /* 04 */ void const* data;
};

struct TsPalAnim
{
    /* 00 */ void const* data;
    /* 04 */ u8 time;
    /* 05 */ u8 colorCount;
    /* 06 */ u8 colorStart;
};

struct BmVSyncProc
{
    PROC_HEADER;

    /* 2C */ struct TsImgAnim const* imgAnimStart;
    /* 30 */ struct TsImgAnim const* imgAnimCurrent;

    /* 34 */ short imgAnimClock;
    /* 36 */ short palAnimClock;

    /* 38 */ struct TsPalAnim const* palAnimStart;
    /* 3C */ struct TsPalAnim const* palAnimCurrent;
};

#include "data/tileset/anims.h"

static void BmVSync_TsImgAnim(struct BmVSyncProc* proc);
static void BmVSync_TsPalAnim(struct BmVSyncProc* proc);
static void BmVSync_Repeat(struct BmVSyncProc* proc);
static void BmVSync_End(struct BmVSyncProc* proc);

struct ProcScr CONST_DATA ProcScr_BmVSync[] =
{
    PROC_MARK(PROC_MARK_1),
    PROC_ONEND(BmVSync_End),

    PROC_SLEEP(0),

PROC_LABEL(0),
    PROC_CALL(BmVSync_TsImgAnim),
    PROC_CALL(BmVSync_TsPalAnim),
    PROC_CALL(SyncUnitSpriteSheet),
    PROC_CALL(UpdateWeatherGraphics),

    PROC_REPEAT(BmVSync_Repeat),

    PROC_END,
};

static void BmVSync_TsImgAnim(struct BmVSyncProc* proc)
{
    if (proc->imgAnimStart == NULL)
        return;

    if (proc->imgAnimClock)
    {
        proc->imgAnimClock--;
        return;
    }

    proc->imgAnimClock = proc->imgAnimCurrent->time;

    CpuFastCopy(
        proc->imgAnimCurrent->data,
        (u8*) VRAM + CHR_SIZE*(BGCHR_TILESET_A+0x100),
        proc->imgAnimCurrent->size);

    proc->imgAnimCurrent++;

    if (proc->imgAnimCurrent->time == 0)
        proc->imgAnimCurrent = proc->imgAnimStart;
}

static void BmVSync_TsPalAnim(struct BmVSyncProc* proc)
{
    if (!proc->palAnimStart)
        return;

    if (proc->palAnimClock)
    {
        proc->palAnimClock--;
        return;
    }

    proc->palAnimClock = proc->palAnimCurrent->time;

    CpuCopy16(
        proc->palAnimCurrent->data,
        gPal + proc->palAnimCurrent->colorStart + 0x10*BGPAL_TILESET,
        proc->palAnimCurrent->colorCount*2);

    EnablePalSync();

    proc->palAnimCurrent++;

    if (proc->palAnimCurrent->time == 0)
        proc->palAnimCurrent = proc->palAnimStart;
}

static void BmVSync_AnimInit(struct BmVSyncProc* proc)
{
	proc->imgAnimClock = 0;
	proc->palAnimClock = 0;

	proc->imgAnimStart = proc->imgAnimCurrent =
		ChapterAssets[GetChapterInfo(gPlaySt.chapter)->assetImgAnims];

	proc->palAnimStart = proc->palAnimCurrent =
		ChapterAssets[GetChapterInfo(gPlaySt.chapter)->assetPalAnims];
}

static void BmVSync_End(struct BmVSyncProc* proc)
{
	SetOnHBlankB(NULL);
}

static void BmVSync_Repeat(struct BmVSyncProc* proc)
{
	Proc_Goto(proc, 0);
}

void StartBmVSync(void)
{
    struct BmVSyncProc* proc = SpawnProc(ProcScr_BmVSync, PROC_TREE_VSYNC);

    BmVSync_AnimInit(proc);
    sub_8028D38();

    gBmSt.lockDisplay = 0;
}

void EndBmVSync(void)
{
    Proc_EndEach(ProcScr_BmVSync);
}

void LockBmDisplay(void)
{
    gBmSt.lockDisplay++;

    if (gBmSt.lockDisplay > 1)
        return;

    SetOnHBlankB(NULL);

    gPal[0] = 0;
    EnablePalSync();

    Proc_LockEachMarked(PROC_MARK_1);
}

void UnlockBmDisplay(void)
{
    ProcPtr proc;

    gBmSt.lockDisplay--;

    if (gBmSt.lockDisplay != 0)
        return;

    Proc_ReleaseEachMarked(PROC_MARK_1);

    proc = Proc_Find(ProcScr_BmVSync);

    if (proc != NULL)
    {
        Proc_End(proc);
        StartBmVSync();
    }
}
