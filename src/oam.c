
#include "oam.h"

#include "armfunc.h"

struct OamSection
{
    u16 * buf;
    void * oam;
    u16 offset;
    u16 count;
};

static struct OamSection sOamHi;
static struct OamSection sOamLo;

u16 COMMON_DATA(gOam) gOam[0x200] = { 0 };
u16 * COMMON_DATA(gOamHiPutIt) gOamHiPutIt = NULL;
u16 * COMMON_DATA(gOamLoPutIt) gOamLoPutIt = NULL;
struct OamView * COMMON_DATA(gOamAffinePutIt) gOamAffinePutIt = NULL;
u16 COMMON_DATA(gOamAffinePutId) gOamAffinePutId = 0;

void InitOam(int loSz)
{
    sOamLo.buf = gOam;
    sOamLo.oam = (void *) OAM;
    sOamLo.offset = 0;
    sOamLo.count = loSz;

    sOamHi.buf = gOam + loSz*4;
    sOamHi.oam = (void *) OAM + loSz*8;
    sOamHi.offset = loSz*8;
    sOamHi.count = 0x80 - loSz;
}

inline int GetOamSplice(void)
{
    return sOamLo.count;
}

void SyncHiOam(void)
{
    CpuFastCopy(sOamHi.buf, sOamHi.oam, sOamHi.count * 8);
    ClearOam(sOamHi.buf, sOamHi.count);

    gOamHiPutIt = sOamHi.buf;

    gOamAffinePutIt = (struct OamView *) gOam;
    gOamAffinePutId = 0;
}

void SyncLoOam(void)
{
    if (sOamLo.count == 0)
        return;

    CpuFastCopy(sOamLo.buf, sOamLo.oam, sOamLo.count * 8);
    ClearOam(sOamLo.buf, sOamLo.count);

    gOamLoPutIt = sOamLo.buf;
}

void SetObjAffine(int id, fi16 pa, fi16 pb, fi16 pc, fi16 pd)
{
    gOam[id*0x10 + 3]  = pa;
    gOam[id*0x10 + 7]  = pb;
    gOam[id*0x10 + 11] = pc;
    gOam[id*0x10 + 15] = pd;
}

void PutUnkSprite(struct UnkSprite * sprites, int xBase, int yBase)
{
    int x, y;

    for (;;)
    {
        if (FALSE)
            return;

        if (sprites->oam01 == 1 || gOamHiPutIt >= gOam + 0x80)
            return;

        x = OAM1_X(sprites->x + xBase);
        y = OAM0_Y(sprites->y + yBase);

#if MODERN
        *gOamHiPutIt++ = (sprites->oam01 >>  0) | y;
        *gOamHiPutIt++ = (sprites->oam01 >> 16) | x;
        *gOamHiPutIt++ = sprites->oam2;
        *gOamHiPutIt++ = 0;
#else
        *(u32 *) ((u32 *) gOamHiPutIt)++ = sprites->oam01 | (x << 16) | (y);
        *(u16 *) ((u32 *) gOamHiPutIt)++ = sprites->oam2;
#endif

        sprites++;
    }
}
