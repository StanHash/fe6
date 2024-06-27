#include "banim_sprite.h"

#include "hardware.h"
#include "oam.h"

static int BasRunScript(struct BaSprite * BaSprite);
static void BasInsert(struct BaSprite * BaSprite);
static void PutBas(struct BaSprite * BaSprite);

typedef void (* BasFunc)(struct BaSprite * bas);

static struct BaSprite EWRAM_DATA sBasPool[BAS_MAX_COUNT] = {};
static struct BaSprite * EWRAM_DATA sFirstBas = NULL;

void BasUpdateAll(void)
{
    struct BaSprite * bas;
    int boolNeedsSort = FALSE;

    if (!sFirstBas)
        return;

    for (bas = sFirstBas;; bas = bas->next)
    {
        if (BAS_IS_DISABLED(bas))
            continue;

        if (!(bas->flags & BAS_BIT_FROZEN))
        {
            if (bas->timer != 0)
                bas->timer--;

            if (bas->timer == 0)
            {
                do
                {
                    if (BasRunScript(bas) == TRUE)
                        boolNeedsSort = TRUE;
                }
                while (bas->timer == 0);
            }

            if (BAS_IS_DISABLED(bas))
                continue;
        }

        if (!(bas->flags & BAS_BIT_HIDDEN))
            PutBas(bas);

        if (!bas->next)
            break;
    }

    if (boolNeedsSort == TRUE)
        BasSort();
}

void BasInit(void)
{
    struct BaSprite * it;

    for (it = sBasPool; it < sBasPool + BAS_MAX_COUNT; ++it)
    {
        it->flags = 0;
        it->prev = NULL;
        it->next = NULL;
    }

    sFirstBas = NULL;
}

struct BaSprite * BasCreate2(void const * script)
{
    struct BaSprite * bas;

    // Find bas slot for new bas
    for (bas = sBasPool; bas < sBasPool + BAS_MAX_COUNT; ++bas)
    {
        if (BAS_IS_DISABLED(bas))
            break;
    }

    // return null if no bas slot was found
    if (bas == sBasPool + BAS_MAX_COUNT)
        return NULL;

    bas->flags = BAS_BIT_ENABLED;

    bas->script = bas->scrCur = script;

    bas->timer = 0;
    bas->oam2 = 0;
    bas->priority = 0;
    bas->flags2 = 0;
    bas->flags3 = 0;
    bas->oam01 = 0;

    bas->cqSize = 0;

    bas->unk2C = NULL;
    bas->sprDataPool = NULL;
    bas->unk40 = NULL;
    bas->unk_44 = NULL;

    BasInsert(bas);

    return bas;
}

struct BaSprite * BasCreate(void const * script, u16 displayPriority)
{
    struct BaSprite * bas;

    // Find bas slot for new bas
    for (bas = sBasPool; bas < sBasPool + BAS_MAX_COUNT; ++bas)
    {
        if (BAS_IS_DISABLED(bas))
            break;
    }

    // return null if no bas slot was found
    if (bas == sBasPool + BAS_MAX_COUNT)
        return NULL;

    bas->flags = BAS_BIT_ENABLED;

    bas->script = bas->scrCur = script;

    bas->timer = 0;
    bas->oam2 = 0;
    bas->priority = displayPriority;
    bas->flags2 = 0;
    bas->flags3 = 0;
    bas->oam01 = 0;

    bas->cqSize = 0;

    bas->unk2C = NULL;
    bas->sprDataPool = NULL;
    bas->unk40 = NULL;
    bas->unk_44 = NULL;

    BasInsert(bas);

    return bas;
}

void BasSort(void)
{
    struct BaSprite * bas;

    for (bas = sBasPool; bas < sBasPool + BAS_MAX_COUNT; ++bas)
    {
        if (BAS_IS_DISABLED(bas))
            continue;

        bas->prev = NULL;
        bas->next = NULL;
    }

    sFirstBas = NULL;

    for (bas = sBasPool; bas < sBasPool + BAS_MAX_COUNT; ++bas)
    {
        if (BAS_IS_DISABLED(bas))
            continue;

        BasInsert(bas);
    }
}

void BasRemove(struct BaSprite * bas)
{
    struct BaSprite * n;

    if (bas->prev == NULL)
    {
        sFirstBas = bas->next;

        n = bas->next;
        n->prev = NULL;
    }
    else
    {
        n = bas->prev;
        n->next = bas->next;

        n = bas->next;
        n->prev = bas->prev;
    }

    bas->flags = 0;
    bas->prev = NULL;
    bas->next = NULL;
}

void BasPutOam(struct BaSprite * bas)
{
    PutBas(bas);
}

int BasRunScript(struct BaSprite * bas)
{
    u32 ins;

    int boolNeedsResort = FALSE;

    ins = *bas->scrCur++;

    if (ins & 0x80000000)
    {
        if (ins & 0x40000000)
        {
            switch ((ins >> 28) & 0x3)
            {

            case 0: // function call
                ((BasFunc) (ins &~ 0xF0000000))(bas);
                break;

            case 1: // set new frame data
                bas->scrCur = bas->script = (u32 const *) (ins &~ 0xF0000000);
                bas->timer = 1;

                break;

            }
        }
        else
        {
            switch (0x3F & (ins >> 24))
            {

            case BAS_INS_KIND_STOP:
                bas->scrCur--;
                bas->timer = 1;

                bas->flags2 = (bas->flags2 & 0xFFF) | 0x4000;

                break;

            case BAS_INS_KIND_END:
                bas->flags = 0;
                bas->timer = 1;

                boolNeedsResort = TRUE;

                break;

            case BAS_INS_KIND_LOOP:
                bas->scrCur = bas->script;
                bas->timer = 1;

                break;

            case BAS_INS_KIND_WAIT:
                bas->timer = (ins) & 0xFFFF;
                break;

            case BAS_INS_KIND_MOVE:
                bas->xPosition += (i8) (ins);
                bas->yPosition += (i8) (ins >> 8);

                bas->timer = (ins >> 16) & 0xFF;

                break;

            case BAS_INS_KIND_COMMAND:
                bas->flags2 = (bas->flags2 & 0xFFF) | 0x1000;

                if (bas->cqSize > 7) {}

                bas->cq[bas->cqSize] = ins & 0xFF;
                bas->cqSize++;

                bas->timer = 1;

                switch (ins & 0xFF)
                {

                case BAS_CMD_WAIT_01:
                case BAS_CMD_WAIT_02:
                case BAS_CMD_WAIT_03:
                case BAS_CMD_WAIT_04:
                case BAS_CMD_WAIT_05:
                case BAS_CMD_WAIT_13:
                case BAS_CMD_WAIT_18:
                case BAS_CMD_WAIT_39:
                    bas->scrCur--;
                    break;

                }

                break;

            case BAS_INS_KIND_FRAME:
                bas->timer = ins & 0xFFFF;
                bas->unk13 = (ins >> 16) & 0xFF;

                bas->imgSheet = (void const *) *bas->scrCur++;

                // weird but ok
                bas->sprData = (void const *) *bas->scrCur++;
                bas->sprData += (int) bas->sprDataPool;

                bas->flags2 = (bas->flags2 & 0xFFF) | 0x2000;

                break;

            }
        }
    }
    else
    {
        bas->sprData = (u8 const *) (ins &~ 0xF0000003);
        bas->timer   = ((ins >> 26) & 0x1C) + (ins & 3);
    }

    return boolNeedsResort;
}

void BasInsert(struct BaSprite * bas)
{
    struct BaSprite * bas2 = bas;
    struct BaSprite * it = sFirstBas;

    if (!sFirstBas)
    {
        sFirstBas = bas2;
        return;
    }

    for (;;)
    {
        if (FALSE)
            break;

        if (bas2->priority > it->priority)
        {
            struct BaSprite * prev = it->prev;

            bas2->prev = it->prev;
            bas2->next = it;
            it->prev = bas2;

            if (!bas2->prev)
                sFirstBas = bas2;
            else
                prev->next = bas2;

            return;
        }
        else if (!it->next)
        {
            bas2->next = it->next;
            bas2->prev = it;
            it->next = bas2;

            return;
        }
        else
        {
            it = it->next;
        }
    }
}

void PutBas(struct BaSprite * bas)
{
    struct BaSpriteData const * it;
    struct BaSpriteData const * sprData;

    int x, y;
    int i;

    unsigned affId = gOamAffinePutId;

    sprData = bas->sprData;

    if (!sprData)
        return;

    if ((sprData->header &~ 0xFFFF) == 0xFFFF0000)
    {
        i = sprData->header & 0xFFFF;

        for (;;)
        {
            if (FALSE)
                break;

            if (i == 0)
                break;

            gOamAffinePutIt->aff = sprData->as.affine.pa;
            gOamAffinePutIt++;

            gOamAffinePutIt->aff = sprData->as.affine.pb;
            gOamAffinePutIt++;

            gOamAffinePutIt->aff = sprData->as.affine.pc;
            gOamAffinePutIt++;

            gOamAffinePutIt->aff = sprData->as.affine.pd;
            gOamAffinePutIt++;

            gOamAffinePutId++;

            i--;
            sprData++;
        }
    }

    it = sprData;

    for (;;)
    {
        if (FALSE)
            break;

        if (it->header == 1 || gOamHiPutIt >= (gOam + 0x200))
            return;

        x = it->as.object.x + bas->xPosition;
        y = it->as.object.y + bas->yPosition;

        if (x > 0x100)
            x = 0x180;
        else if (x < -0x40)
            x = 0x180;

        if (y > 0x0A0)
            x = 0x180;
        else if (y < -0x40)
            x = 0x180;

        x = OAM1_X(x);
        y = OAM0_Y(y);

        i = 0;

        if (it->header & OAM0_AFFINE_ENABLE)
            i = (affId << 25);

        i = i + bas->oam01;

        *(u32 *) ((u32 *) gOamHiPutIt)++ = (it->header + i) | (x << 16) | (y);
        *(u16 *) ((u32 *) gOamHiPutIt)++ = (it->as.object.oam2 & 0xF3FF) + bas->oam2;

        it++;
    }
}
