
#include "common.h"

#include "random.h"
#include "ramfunc.h"
#include "hardware.h"
#include "oam.h"
#include "proc.h"
#include "sprite.h"
#include "util.h"
#include "bm.h"
#include "map.h"
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

struct WeatherParticle
{
    /* 00 */ short x;
    /* 02 */ short y;

    /* 04 */ short xSpeed;
    /* 06 */ short ySpeed;

    /* 08 */ u8 chr;
    /* 09 */ u8 kind;
};

union WeatherEffectSt
{
    /**
     * Array of weather particles
     */
    struct WeatherParticle particles[0x40];

    /**
     * Buffer for cloud graphics
     */
    u32 imgCloud[0xC0];
};

union WeatherGradientSt
{
    /**
     * Buffer holding colors for vertical gradient.
     */
    u16 lines[320];

    /**
     * Buffer holding 8 different variations of the tileset palette
     * Variations have increasing amounts of red; used for flames weather effect
     */
    u16 fireGradient[8][0x40];
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

extern union WeatherEffectSt gWeatherEffect;
extern union WeatherGradientSt gWeatherGradient;

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

struct ProcScr CONST_DATA ProcScr_MapTask[] =
{
    PROC_19,
    PROC_19,
    PROC_MARK(PROC_MARK_1),
    PROC_SLEEP(0),

PROC_LABEL(0),
    PROC_CALL(PutUnitSpritesOam),
    PROC_CALL(sub_8028E10),
    PROC_CALL(UpdateRenderMap),
    PROC_SLEEP(0),

    PROC_GOTO(0),
};

u16 CONST_DATA Sprite_085C7C34[] =
{
    1, OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(OBJCHR_SYSTEM_OBJECTS + 0x2A) + OAM2_PAL(OBJPAL_1),
};

u16 CONST_DATA Sprite_085C7C3C[] =
{
    1, OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(OBJCHR_SYSTEM_OBJECTS + 0xA) + OAM2_PAL(OBJPAL_1),
};

u16 const* CONST_DATA gUnk_085C7C44[] =
{
    Sprite_085C7C34,
    Sprite_085C7C3C,
    Sprite_085C7C3C,
};

/**
 * Each 3 array entries represent one config template
 * First two values are initial speed, third is type id
 * Used for the "slower" weathers (regular snow, rain & flames)
 */
u16 const gInitialParticleConfigTemplates[] =
{
    0xB0,  0xC0,  0,
    0xB0,  0xD0,  0,
    0xB0,  0xE0,  0,
    0xB0,  0xF0,  0,
    0xB0,  0x100, 0,
    0xB0,  0x110, 0,

    0xF0,  0x140, 1,
    0xF0,  0x150, 1,
    0xF0,  0x160, 1,
    0xF0,  0x170, 1,
    0xF0,  0x180, 1,
    0xF0,  0x190, 1,
    0xF0,  0x1A0, 1,

    0x100, 0x200, 2,
    0xF0,  0x220, 2,
    0xE0,  0x240, 2,
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

void AllocWeatherParticles(int weather)
{
    switch (weather)
    {

    case WEATHER_SNOW:
    case WEATHER_SNOWSTORM:
    case WEATHER_RAIN:
    case WEATHER_SANDSTORM:
        InitOam(0x20);
        break;

    case WEATHER_FLAMES:
        InitOam(0x10);
        break;

    default:
        InitOam(0);
        break;

    }
}

void sub_8028448(void)
{
    AllocWeatherParticles(gPlaySt.weather);
    SetOnHBlankB(NULL);
}

void sub_8028460(void)
{
    int i;

    int chrs[] =
    {
        0x29,
        0x09,
        0x08
    };

    AllocWeatherParticles(gPlaySt.weather);

    for (i = 0; i < 0x40; ++i)
    {
        int templateId = (i & 0xF) * 3;

        gWeatherEffect.particles[i].x = RandNextB();
        gWeatherEffect.particles[i].y = RandNextB();

        gWeatherEffect.particles[i].xSpeed = gInitialParticleConfigTemplates[templateId + 0] * 2;
        gWeatherEffect.particles[i].ySpeed = gInitialParticleConfigTemplates[templateId + 1] * 2;
        gWeatherEffect.particles[i].kind = gInitialParticleConfigTemplates[templateId + 2];

        gWeatherEffect.particles[i].chr = chrs[gInitialParticleConfigTemplates[templateId + 2]];
    }
}

void sub_80284D8(void)
{
    if (GetOamSplice() != 0)
    {
        struct Vec2 origins[3];
        int i;

        struct WeatherParticle* it = gWeatherEffect.particles + ((GetGameTime() % 2) * 0x20);

        origins[0].x = (gBmSt.camera.x * 12) / 16;
        origins[0].y = gBmSt.camera.y;

        origins[1].x = gBmSt.camera.x;
        origins[1].y = gBmSt.camera.y;

        origins[2].x = (gBmSt.camera.x * 20) / 16;
        origins[2].y = gBmSt.camera.y;

        for (i = 0; i < 0x20; ++i)
        {
            it->x += it->xSpeed;
            it->y += it->ySpeed;

            PutOamLoRam(
                ((it->x >> 8) - origins[it->kind].x) & 0xFF,
                ((it->y >> 8) - origins[it->kind].y) & 0xFF,
                Sprite_8x8, OAM2_PAL(OBJPAL_1) + it->chr);

            ++it;
        }
    }
}

void sub_8028598(void)
{
    int i;

    AllocWeatherParticles(gPlaySt.weather);

    for (i = 0; i < 0x40; ++i)
    {
        int templateId = (i & 0xF) * 3;

        gWeatherEffect.particles[i].x = RandNextB();
        gWeatherEffect.particles[i].y = RandNextB();

        gWeatherEffect.particles[i].xSpeed = gInitialParticleConfigTemplates[templateId+0] * 6;
        gWeatherEffect.particles[i].ySpeed = gInitialParticleConfigTemplates[templateId+1] * 16;
        gWeatherEffect.particles[i].chr = gInitialParticleConfigTemplates[templateId+2];
    }
}

void sub_80285FC(void)
{
    if (GetOamSplice() != 0)
    {
        int i;

        struct WeatherParticle* it = gWeatherEffect.particles + ((GetGameTime() % 2) * 0x20);

        for (i = 0; i < 0x20; ++i)
        {
            it->x += it->xSpeed;
            it->y += it->ySpeed;

            PutOamLoRam(
                ((it->x >> 8) - gBmSt.camera.x) & 0xFF,
                ((it->y >> 8) - gBmSt.camera.y) & 0xFF,
                gUnk_085C7C44[it->chr], 0);

            ++it;
        }
    }
}

void sub_802867C(void)
{
    int i;

    AllocWeatherParticles(gPlaySt.weather);

    Decompress(Img_SandstormParticles, gBuf);
    Copy2dChr(gBuf, OBJ_VRAM0 + OBJCHR_SANDSTORM_PARTICLE*CHR_SIZE, 4, 4);

    for (i = 0; i < 0x40; ++i)
    {
        gWeatherEffect.particles[i].x = RandNextB();
        gWeatherEffect.particles[i].y = (RandNextB() % DISPLAY_HEIGHT + DISPLAY_HEIGHT*3/2) & 0xFF;

        gWeatherEffect.particles[i].xSpeed = (RandNextB() & 0x7) - 32;
        gWeatherEffect.particles[i].ySpeed = 0;
    }
}

void sub_80286EC(void)
{
    if (GetOamSplice() != 0)
    {
        int i;

        struct WeatherParticle* it = gWeatherEffect.particles + ((GetGameTime() % 2) * 0x20);

        for (i = 0; i < 0x20; ++i)
        {
            it->x += it->xSpeed;

            PutOamLoRam(
                OAM1_X((it->x & 0xFF) - 0x10),
                it->y,
                Sprite_32x32, OAM2_PAL(OBJPAL_1) + OBJCHR_SANDSTORM_PARTICLE);

            ++it;
        }
    }
}

void sub_8028748(void)
{
    int i;

    u8 kindLut[8] = { 0, 0, 0, 0, 0, 0, 1, 1 };

    AllocWeatherParticles(gPlaySt.weather);

    Decompress(Img_SnowstormParticles, gBuf);
    Copy2dChr(gBuf, OBJ_VRAM0 + OBJCHR_SNOWSTORM_PARTICLE*CHR_SIZE, 8, 4);

    for (i = 0; i < 0x40; ++i)
    {
        int kind = kindLut[i & 7];

        gWeatherEffect.particles[i].x = RandNextB();
        gWeatherEffect.particles[i].y = RandNextB();

        gWeatherEffect.particles[i].ySpeed = (RandNextB() & 0x3FF) - 0x100;
        gWeatherEffect.particles[i].chr = kind;

        switch (kind)
        {

        case 0:
            gWeatherEffect.particles[i].xSpeed = 0x700 + (RandNextB() & 0x1FF);
            break;

        case 1:
            gWeatherEffect.particles[i].xSpeed = 0xA00 + (RandNextB() & 0x1FF);
            break;

        }
    }
}

void sub_8028804(void)
{
    if (GetOamSplice() != 0)
    {
        int i;

        struct WeatherParticle* it = gWeatherEffect.particles + ((GetGameTime() % 2) * 0x20);

        for (i = 0; i < 0x20; ++i)
        {
            it->x += it->xSpeed;
            it->y += it->ySpeed;

            PutOamLoRam(
                ((it->x >> 8) - gBmSt.camera.x) & 0xFF,
                ((it->y >> 8) - gBmSt.camera.y) & 0xFF,
                Sprite_32x32, OAM2_PAL(OBJPAL_1) + OBJCHR_SNOWSTORM_PARTICLE + (it->chr * 4));

            ++it;
        }
    }
}

void sub_802887C(void)
{
    u16 nextLine = (REG_VCOUNT + 1);

    if (nextLine > DISPLAY_HEIGHT)
        nextLine = 0;

    nextLine += gBmSt.camera.y / 2;

    if (nextLine >= 320)
        ((u16*) PLTT)[0] = 0;
    else
        ((u16*) PLTT)[0] = nextLine[gWeatherGradient.lines];
}

void sub_80288D0(void)
{
    int i;

    u16* colors = gWeatherGradient.lines;

    for (i = 0; i < 320; ++i)
        *colors++ = RGB(0, 0, (31 - i / 10));

    SetOnHBlankB(sub_802887C);
}

void nullsub_4(void)
{
}

void sub_8028918(void)
{
    const u16* src;
    u16* dst;

    u16 nextLine = (REG_VCOUNT + 1);

    if (nextLine < DISPLAY_HEIGHT*3/5)
        return;

    if (nextLine >= DISPLAY_HEIGHT)
        return;

    nextLine -= DISPLAY_HEIGHT*3/5;

    src = gWeatherGradient.fireGradient[0];
    src += nextLine * 8;

    dst = ((u16*) PLTT) + 0x10*(BGPAL_TILESET+1) + (nextLine % 8) * 8;

    CpuFastCopy(src, dst, 8);
}

void noo_802895C(void)
{
    int i, j, k;

    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 0x10; ++j)
        {
            int const color = gPal[0x10 * (BGPAL_TILESET+1+i) + j];

            int r = RGB_GET_RED(color);
            int g = RGB_GET_GREEN(color);
            int b = RGB_GET_BLUE(color);

            for (k = 0; k < 8; ++k)
            {
                r = r + 2;

                if (r > 31)
                    r = 31;

                gWeatherGradient.fireGradient[k][0x10*i + j] = 
                    (b << 10) + (g << 5) + r;
            }
        }
    }
}

void sub_80289DC(void)
{
    int i, j, k;

    ApplyChapterMapPalettes();

    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 0x10; ++j)
        {
            int const color = gPal[0x10 * (BGPAL_TILESET+1+i) + j];

            int r = RGB_GET_RED(color);
            int g = RGB_GET_GREEN(color);
            int b = RGB_GET_BLUE(color);

            for (k = 0; k < 8; ++k)
            {
                r = r + 2;

                if (r > 31)
                    r = 31;

                gWeatherGradient.fireGradient[k][0x10*i + j] = 
                    (b << 10) + (g << 5) + r;
            }
        }
    }

    SetOnHBlankB(sub_8028918);
}
