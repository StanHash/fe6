
#include "gba/gba.h"

#include "hardware.h"
#include "oam.h"

struct Anim
{
    /* 00 */ u16 state;
    /* 02 */ short xPosition;
    /* 04 */ short yPosition;
    /* 06 */ short timer;
    /* 08 */ u16 oam2Base;
    /* 0A */ u16 drawLayerPriority;
    /* 0C */ u16 state2;
    /* 0E */ u16 nextRoundId;
    /* 10 */ u16 state3;
    /* 12 */ u8 currentRoundType;
    /* 13 */ u8 unk13;

    /* 14 */ u8 commandQueueSize;
    /* 15 */ u8 commandQueue[7];

    /* 1C */ u32 oamBase;

    /* 20 */ const u32* pScrCurrent;
    /* 24 */ const u32* pScrStart;
    /* 28 */ const void* pImgSheet;
    /* 2C */ const void* pUnk2C;
    /* 30 */ const void* pSpriteDataPool; // aka "OAM data"

    /* 34 */ struct Anim* pPrev;
    /* 38 */ struct Anim* pNext;

    /* 3C */ const void* pSpriteData;
    /* 40 */ const void* pUnk40;
    /* 44 */ const void* pUnk44;
};

struct AnimSpriteData
{
    /* 00 */ u32 header;

    union
    {

    struct
    {
        /* 04 */ u16 pa;
        /* 06 */ u16 pb;
        /* 08 */ u16 pc;
        /* 0A */ u16 pd;
    } affine;

    struct
    {
        /* 04 */ u16 oam2;
        /* 06 */ short x;
        /* 08 */ short y;
    } object;

    } as;
};

enum
{
    // For use with Anim::state

    ANIM_BIT_ENABLED = (1 << 0),
    ANIM_BIT_HIDDEN  = (1 << 1),
    ANIM_BIT_2       = (1 << 2),
    ANIM_BIT_FROZEN  = (1 << 3),
};

enum
{
    ANIM_MAX_COUNT = 50,
};

enum
{
    // Animation Command Identifiers

    // TODO: complete during battle animation decomp

    ANIM_CMD_NOP     = 0x00,
    ANIM_CMD_WAIT_01 = 0x01, // wait for hp depletion
    ANIM_CMD_WAIT_02 = 0x02, // wait for dodge start, then dodge
    ANIM_CMD_WAIT_03 = 0x03, // wait for attack start
    ANIM_CMD_WAIT_04 = 0x04,
    ANIM_CMD_WAIT_05 = 0x05, // wait for spell animation?
    // TODO: more
    ANIM_CMD_WAIT_13 = 0x13, // unk
    ANIM_CMD_WAIT_18 = 0x18, // wait for dodge start, then forward dodge
    ANIM_CMD_WAIT_39 = 0x39, // unk
};

#define ANIM_IS_DISABLED(anim) ((anim)->state == 0)

void sub_800722C(void);
void AnimClearAll(void);
struct Anim* AnimCreate_unused(const void* script);
struct Anim* AnimCreate(const void* script, u16 displayPriority);
void sub_800751C(void);
void sub_800759C(struct Anim* anim);
void AnimDisplay(struct Anim* anim);

// static
int  sub_800761C(struct Anim* anim);
void sub_8007948(struct Anim* anim);
void sub_80079EC(struct Anim* anim);
void Anim_8005334(struct Anim* anim, u32 instruction);

#define ANINS_IS_NOT_FORCESPRITE(instruction) ((instruction) & 0x80000000)
#define ANINS_IS_PTRINS(instruction) ((instruction) & 0x40000000)

#define ANINS_FORCESPRITE_GET_ADDRESS(instruction) ((void*) ((instruction) &~ 0xF0000003))
#define ANINS_FORCESPRITE_GET_DELAY(instruction) ((((instruction) >> 26) & 0x1C) + ((instruction) & 3))

#define ANINS_PTRINS_GET_TYPE(instruction) (0x3 & ((instruction) >> 28))
#define ANINS_PTRINS_GET_ADDRESS(instruction) ((void*) ((instruction) &~ 0xF0000000))

#define ANINS_GET_TYPE(instruction) (0x3F & ((instruction) >> 24))

#define ANINS_WAIT_GET_DELAY(instruction) ((instruction) & 0xFFFF)

#define ANINS_MOVE_GET_XOFF(instruction) (((int) ((instruction) << 24)) >> 24)
#define ANINS_MOVE_GET_YOFF(instruction) (((int) ((instruction) << 16)) >> 24)
#define ANINS_MOVE_GET_DELAY(instruction) (((instruction) >> 16) & 0xFF)

#define ANINS_COMMAND_GET_ID(instruction) (0xFF & (instruction))

#define ANINS_FRAME_GET_DELAY(instruction) ((instruction) & 0xFFFF)
#define ANINS_FRAME_GET_UNK(instruction) ((instruction) >> 16) & 0xFF

enum
{
    ANIM_INS_TYPE_STOP    = 0,
    ANIM_INS_TYPE_END     = 1,
    ANIM_INS_TYPE_LOOP    = 2,
    ANIM_INS_TYPE_MOVE    = 3,
    ANIM_INS_TYPE_WAIT    = 4,
    ANIM_INS_TYPE_COMMAND = 5,
    ANIM_INS_TYPE_FRAME   = 6,
};

typedef void (*AnimCallback_t) (struct Anim* anim);

EWRAM_DATA static struct Anim sAnimPool[ANIM_MAX_COUNT] = {};
EWRAM_DATA static struct Anim* sFirstAnim = NULL;

void sub_800722C(void)
{
    struct Anim* anim;
    int boolNeedsSort = FALSE;

    if (!sFirstAnim)
        return;

    for (anim = sFirstAnim;; anim = anim->pNext)
    {
        if (ANIM_IS_DISABLED(anim))
            continue;

        if (!(anim->state & ANIM_BIT_FROZEN))
        {
            if (anim->timer != 0)
                anim->timer--;

            if (anim->timer == 0)
            {
                do
                {
                    if (sub_800761C(anim) == TRUE)
                        boolNeedsSort = TRUE;
                }
                while (anim->timer == 0);
            }

            if (ANIM_IS_DISABLED(anim))
                continue;
        }

        if (!(anim->state & ANIM_BIT_HIDDEN))
            sub_80079EC(anim);

        if (!anim->pNext)
            break;
    }

    if (boolNeedsSort == TRUE)
        sub_800751C();
}

void sub_8007300(void)
{
    struct Anim* it;

    for (it = sAnimPool; it < sAnimPool + ANIM_MAX_COUNT; ++it)
    {
        it->state = 0;
        it->pPrev = NULL;
        it->pNext = NULL;
    }

    sFirstAnim = NULL;
}

struct Anim* sub_8007350(const void* frameData)
{
    struct Anim* anim;

    // Find anim slot for new anim
    for (anim = sAnimPool; anim < sAnimPool + ANIM_MAX_COUNT; ++anim)
    {
        if (ANIM_IS_DISABLED(anim))
            break;
    }

    // return null if no anim slot was found
    if (anim == sAnimPool + ANIM_MAX_COUNT)
        return NULL;

    anim->state = ANIM_BIT_ENABLED;

    anim->pScrStart = anim->pScrCurrent = frameData;

    anim->timer = 0;
    anim->oam2Base = 0;
    anim->drawLayerPriority = 0;
    anim->state2 = 0;
    anim->state3 = 0;
    anim->oamBase = 0;

    anim->commandQueueSize = 0;

    anim->pUnk2C = NULL;
    anim->pSpriteDataPool = NULL;
    anim->pUnk40 = NULL;
    anim->pUnk44 = NULL;

    sub_8007948(anim);

    return anim;
}

struct Anim* sub_8007430(const void* frameData, u16 displayPriority)
{
    struct Anim* anim;

    // Find anim slot for new anim
    for (anim = sAnimPool; anim < sAnimPool + ANIM_MAX_COUNT; ++anim)
    {
        if (ANIM_IS_DISABLED(anim))
            break;
    }

    // return null if no anim slot was found
    if (anim == sAnimPool + ANIM_MAX_COUNT)
        return NULL;

    anim->state = ANIM_BIT_ENABLED;

    anim->pScrStart = anim->pScrCurrent = frameData;

    anim->timer = 0;
    anim->oam2Base = 0;
    anim->drawLayerPriority = displayPriority;
    anim->state2 = 0;
    anim->state3 = 0;
    anim->oamBase = 0;

    anim->commandQueueSize = 0;

    anim->pUnk2C = NULL;
    anim->pSpriteDataPool = NULL;
    anim->pUnk40 = NULL;
    anim->pUnk44 = NULL;

    sub_8007948(anim);

    return anim;
}

void sub_800751C(void)
{
    struct Anim* anim;

    for (anim = sAnimPool; anim < sAnimPool + ANIM_MAX_COUNT; ++anim)
    {
        if (ANIM_IS_DISABLED(anim))
            continue;

        anim->pPrev = NULL;
        anim->pNext = NULL;
    }

    sFirstAnim = NULL;

    for (anim = sAnimPool; anim < sAnimPool + ANIM_MAX_COUNT; ++anim)
    {
        if (ANIM_IS_DISABLED(anim))
            continue;

        sub_8007948(anim);
    }
}

void sub_800759C(struct Anim* anim)
{
    struct Anim* n;

    if (anim->pPrev == NULL)
    {
        sFirstAnim = anim->pNext;

        n = anim->pNext;
        n->pPrev = NULL;
    }
    else
    {
        n = anim->pPrev;
        n->pNext = anim->pNext;

        n = anim->pNext;
        n->pPrev = anim->pPrev;
    }

    anim->state = 0;
    anim->pPrev = NULL;
    anim->pNext = NULL;
}

void sub_8007604(struct Anim* anim)
{
    sub_80079EC(anim);
}

int sub_800761C(struct Anim* anim)
{
    u32 instruction;

    int boolNeedsResort = FALSE;

    instruction = *anim->pScrCurrent++;

    if (ANINS_IS_NOT_FORCESPRITE(instruction))
    {
        if (ANINS_IS_PTRINS(instruction))
        {
            switch (ANINS_PTRINS_GET_TYPE(instruction))
            {

            case 0: // function call
                ((AnimCallback_t) ANINS_PTRINS_GET_ADDRESS(instruction))(anim);
                break;

            case 1: // set new frame data
                anim->pScrCurrent = anim->pScrStart = ANINS_PTRINS_GET_ADDRESS(instruction);
                anim->timer = 1;

                break;

            } // switch (ANINS_PTRINS_GET_TYPE(instruction))
        }
        else
        {
            switch (ANINS_GET_TYPE(instruction))
            {

            case ANIM_INS_TYPE_STOP:
                anim->pScrCurrent--;
                anim->timer = 1;

                anim->state2 = (anim->state2 & 0xFFF) | 0x4000;

                break;

            case ANIM_INS_TYPE_END:
                anim->state = 0;
                anim->timer = 1;

                boolNeedsResort = TRUE;

                break;

            case ANIM_INS_TYPE_LOOP:
                anim->pScrCurrent = anim->pScrStart;
                anim->timer = 1;

                break;

            case ANIM_INS_TYPE_WAIT:
                anim->timer = ANINS_WAIT_GET_DELAY(instruction);
                break;

            case ANIM_INS_TYPE_MOVE:
                anim->xPosition += (s8) (instruction);
                anim->yPosition += (s8) (instruction >> 8);

                anim->timer = ANINS_MOVE_GET_DELAY(instruction);

                break;

            case ANIM_INS_TYPE_COMMAND:
                anim->state2 = (anim->state2 & 0xFFF) | 0x1000;

                if (anim->commandQueueSize > 7) {}

                anim->commandQueue[anim->commandQueueSize] = ANINS_COMMAND_GET_ID(instruction);
                anim->commandQueueSize++;

                anim->timer = 1;

                switch (ANINS_COMMAND_GET_ID(instruction))
                {

                case ANIM_CMD_WAIT_01:
                case ANIM_CMD_WAIT_02:
                case ANIM_CMD_WAIT_03:
                case ANIM_CMD_WAIT_04:
                case ANIM_CMD_WAIT_05:
                case ANIM_CMD_WAIT_13:
                case ANIM_CMD_WAIT_18:
                case ANIM_CMD_WAIT_39:
                    anim->pScrCurrent--;
                    break;

                } // switch (ANINS_COMMAND_GET_ID(instruction))

                break;

            case ANIM_INS_TYPE_FRAME:
                anim->timer = ANINS_FRAME_GET_DELAY(instruction);
                anim->unk13 = ANINS_FRAME_GET_UNK(instruction);

                anim->pImgSheet = (const void*) (*anim->pScrCurrent++);

                // ???????
                anim->pSpriteData = (const void*) (*anim->pScrCurrent++);
                anim->pSpriteData += (unsigned) anim->pSpriteDataPool;

                anim->state2 = (anim->state2 & 0xFFF) | 0x2000;

                break;

            } // switch (0x3F & (instruction >> 24))
        }
    }
    else
    {
        anim->pSpriteData = ANINS_FORCESPRITE_GET_ADDRESS(instruction);
        anim->timer       = ANINS_FORCESPRITE_GET_DELAY(instruction);
    }

    return boolNeedsResort;
}

void sub_8007948(struct Anim* anim)
{
    struct Anim* anim2 = anim;
    struct Anim* it = sFirstAnim;

    if (!sFirstAnim)
    {
        sFirstAnim = anim2;
        return;
    }

    for (;;)
    {
        if (FALSE)
            break;

        if (anim2->drawLayerPriority > it->drawLayerPriority)
        {
            struct Anim* prev = it->pPrev;

            anim2->pPrev = it->pPrev;
            anim2->pNext = it;
            it->pPrev = anim2;

            if (!anim2->pPrev)
                sFirstAnim = anim2;
            else
                prev->pNext = anim2;

            return;
        }
        else if (!it->pNext)
        {
            anim2->pNext = it->pNext;
            anim2->pPrev = it;
            it->pNext = anim2;

            return;
        }
        else
        {
            it = it->pNext;
        }
    }
}

void sub_80079EC(struct Anim* anim)
{
    const struct AnimSpriteData* it;
    const struct AnimSpriteData* oamData;

    int x, y;
    int i;

    unsigned baseAffineId = gOamAffinePutId;

    oamData = anim->pSpriteData;

    if (!oamData)
        return;

    if ((oamData->header &~ 0xFFFF) == 0xFFFF0000)
    {
        i = oamData->header & 0xFFFF;

        for (;;)
        {
            if (FALSE)
                break;

            if (i == 0)
                break;

            gOamAffinePutIt->aff = oamData->as.affine.pa;
            gOamAffinePutIt++;

            gOamAffinePutIt->aff = oamData->as.affine.pb;
            gOamAffinePutIt++;

            gOamAffinePutIt->aff = oamData->as.affine.pc;
            gOamAffinePutIt++;

            gOamAffinePutIt->aff = oamData->as.affine.pd;
            gOamAffinePutIt++;

            gOamAffinePutId++;
            i--;
            oamData++;
        }
    }

    it = oamData;

    for (;;)
    {
        if (FALSE)
            break;

        if (it->header == 1 || gOamHiPutIt >= (gOam + 0x200))
            return;

        x = it->as.object.x + anim->xPosition;
        y = it->as.object.y + anim->yPosition;

        if (x > 0x100)
            x = 0x180;
        else if (x < -0x40)
            x = 0x180;

        if (y > 0x0A0)
            x = 0x180;
        else if (y < -0x40)
            x = 0x180;

        x = x & 0x1FF;
        y = y & 0x0FF;

        i = 0;

        if (it->header & 0x100)
            i = (baseAffineId << 25);

        i = i + anim->oamBase;

        *(u32*) ((u32*) gOamHiPutIt)++ = (it->header + i) | (x << 16) | (y);
        *(u16*) ((u32*) gOamHiPutIt)++ = (it->as.object.oam2 & 0xF3FF) + anim->oam2Base;

        it++;
    }
}
