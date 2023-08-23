
#include "bmio.h"

#include "random.h"
#include "armfunc.h"
#include "hardware.h"
#include "oam.h"
#include "proc.h"
#include "sprite.h"
#include "util.h"
#include "bm.h"
#include "map.h"
#include "unitsprite.h"
#include "chapterinfo.h"

#include "constants/videoalloc_global.h"

struct TsImgAnim
{
    /* 00 */ u16 time;
    /* 02 */ u16 size;
    /* 04 */ void const * data;
};

struct TsPalAnim
{
    /* 00 */ void const * data;
    /* 04 */ u8 time;
    /* 05 */ u8 colorCount;
    /* 06 */ u8 colorStart;
};

struct WeatherParticle
{
    /* 00 */ short x;
    /* 02 */ short y;

    /* 04 */ short x_speed;
    /* 06 */ short y_speed;

    /* 08 */ u8 chr;
    /* 09 */ u8 kind;
};

union WeatherEffect
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

union WeatherGradient
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

    /* 2C */ struct TsImgAnim const * imgAnimStart;
    /* 30 */ struct TsImgAnim const * imgAnimCurrent;

    /* 34 */ short imgAnimClock;
    /* 36 */ short palAnimClock;

    /* 38 */ struct TsPalAnim const * palAnimStart;
    /* 3C */ struct TsPalAnim const * palAnimCurrent;
};

static void WeatherInit_None(void);
static void WeatherInit_Snow(void);
static void WeatherVBlank_Snow(void);
static void WeatherInit_Rain(void);
static void WeatherVBlank_Rain(void);
static void WeatherInit_Sandstorm(void);
static void WeatherVBlank_Sandstorm(void);
static void WeatherInit_Snowstorm(void);
static void WeatherVBlank_Snowstorm(void);
static void WeatherInit_Blue(void);
static void WeatherVBlank_Blue(void);
static void WeatherInit_Flames(void);
static void WeatherVBlank_Flames(void);
static void WeatherInit_Clouds(void);
static void WeatherVBlank_Clouds(void);
static void WeatherUpdate_Clouds(void);

extern union WeatherEffect gWeatherEffect;
extern union WeatherGradient gWeatherGradient;

#include "data/tileset/anims.h"

static void BmVSync_TsImgAnim(struct BmVSyncProc * proc);
static void BmVSync_TsPalAnim(struct BmVSyncProc * proc);
static void BmVSync_Repeat(struct BmVSyncProc * proc);
static void BmVSync_End(struct BmVSyncProc * proc);

struct ProcScr CONST_DATA ProcScr_BmVSync[] =
{
    PROC_MARK(PROC_MARK_1),
    PROC_ONEND(BmVSync_End),

    PROC_SLEEP(0),

PROC_LABEL(0),
    PROC_CALL(BmVSync_TsImgAnim),
    PROC_CALL(BmVSync_TsPalAnim),
    PROC_CALL(SyncUnitSpriteSheet),
    PROC_CALL(WeatherVBlank),

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
    PROC_CALL(WeatherUpdate),
    PROC_CALL(UpdateRenderMap),
    PROC_SLEEP(0),

    PROC_GOTO(0),
};

u16 CONST_DATA Sprite_085C7C34[] =
{
    1, OAM0_SHAPE_8x8, OAM1_SIZE_8x8, OAM2_CHR(OBCHR_SYSTEM_OBJECTS + 0x2A) + OAM2_PAL(OBPAL_1),
};

u16 CONST_DATA Sprite_085C7C3C[] =
{
    1, OAM0_SHAPE_8x16, OAM1_SIZE_8x16, OAM2_CHR(OBCHR_SYSTEM_OBJECTS + 0xA) + OAM2_PAL(OBPAL_1),
};

static u16 const * CONST_DATA sRainSprites[] =
{
    Sprite_085C7C34,
    Sprite_085C7C3C,
    Sprite_085C7C3C,
};

u16 CONST_DATA Sprite_CloudWeather[] =
{
    18,
    OAM0_SHAPE_64x32 + OAM0_Y(0),   OAM1_SIZE_64x32 + OAM1_X(0),   0,
    OAM0_SHAPE_64x32 + OAM0_Y(0),   OAM1_SIZE_64x32 + OAM1_X(48),  OAM2_CHR(0x6),
    OAM0_SHAPE_64x32 + OAM0_Y(0),   OAM1_SIZE_64x32 + OAM1_X(112), 0,
    OAM0_SHAPE_64x32 + OAM0_Y(0),   OAM1_SIZE_64x32 + OAM1_X(160), OAM2_CHR(0x6),
    OAM0_SHAPE_16x32 + OAM0_Y(0),   OAM1_SIZE_16x32 + OAM1_X(224), 0,
    OAM0_SHAPE_32x32 + OAM0_Y(32),  OAM1_SIZE_32x32 + OAM1_X(0),   OAM2_CHR(0xA),
    OAM0_SHAPE_64x32 + OAM0_Y(32),  OAM1_SIZE_64x32 + OAM1_X(32),  0,
    OAM0_SHAPE_64x32 + OAM0_Y(32),  OAM1_SIZE_64x32 + OAM1_X(80),  OAM2_CHR(0x6),
    OAM0_SHAPE_64x32 + OAM0_Y(32),  OAM1_SIZE_64x32 + OAM1_X(144), 0,
    OAM0_SHAPE_64x32 + OAM0_Y(32),  OAM1_SIZE_64x32 + OAM1_X(192), OAM2_CHR(0x6),
    OAM0_SHAPE_64x32 + OAM0_Y(64),  OAM1_SIZE_64x32 + OAM1_X(0),   0,
    OAM0_SHAPE_64x32 + OAM0_Y(64),  OAM1_SIZE_64x32 + OAM1_X(176), 0,
    OAM0_SHAPE_64x32 + OAM0_Y(96),  OAM1_SIZE_64x32 + OAM1_X(0),   OAM2_CHR(0x4),
    OAM0_SHAPE_64x32 + OAM0_Y(96),  OAM1_SIZE_64x32 + OAM1_X(176), OAM2_CHR(0x4),
    OAM0_SHAPE_64x32 + OAM0_Y(128), OAM1_SIZE_64x32 + OAM1_X(0),   0,
    OAM0_SHAPE_64x32 + OAM0_Y(128), OAM1_SIZE_64x32 + OAM1_X(176), 0,
    OAM0_SHAPE_64x32 + OAM0_Y(160), OAM1_SIZE_64x32 + OAM1_X(0),   0,
    OAM0_SHAPE_64x32 + OAM0_Y(160), OAM1_SIZE_64x32 + OAM1_X(176), 0,
};

/**
 * Each 3 array entries represent one config template
 * First two values are initial speed, third is generic kind id
 * Used for the "slower" weathers (regular snow, rain & flames)
 */
static u16 const sParticleTemplates[] =
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

static void BmVSync_TsImgAnim(struct BmVSyncProc * proc)
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
        (u8 *) VRAM + CHR_SIZE*(BGCHR_TILESET_A+0x100),
        proc->imgAnimCurrent->size);

    proc->imgAnimCurrent++;

    if (proc->imgAnimCurrent->time == 0)
        proc->imgAnimCurrent = proc->imgAnimStart;
}

static void BmVSync_TsPalAnim(struct BmVSyncProc * proc)
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

static void BmVSync_AnimInit(struct BmVSyncProc * proc)
{
    proc->imgAnimClock = 0;
    proc->palAnimClock = 0;

    proc->imgAnimStart = proc->imgAnimCurrent =
        ChapterAssets[GetChapterInfo(gPlaySt.chapter)->asset_img_anims];

    proc->palAnimStart = proc->palAnimCurrent =
        ChapterAssets[GetChapterInfo(gPlaySt.chapter)->asset_pal_anims];
}

static void BmVSync_End(struct BmVSyncProc * proc)
{
    SetOnHBlankB(NULL);
}

static void BmVSync_Repeat(struct BmVSyncProc * proc)
{
    Proc_Goto(proc, 0);
}

void StartBmVSync(void)
{
    struct BmVSyncProc * proc = SpawnProc(ProcScr_BmVSync, PROC_TREE_VSYNC);

    BmVSync_AnimInit(proc);
    WeatherInit();

    gBmSt.lock_display = 0;
}

void EndBmVSync(void)
{
    Proc_EndEach(ProcScr_BmVSync);
}

void LockBmDisplay(void)
{
    gBmSt.lock_display++;

    if (gBmSt.lock_display > 1)
        return;

    SetOnHBlankB(NULL);
    SetBackdropColor(0);

    Proc_LockEachMarked(PROC_MARK_1);
}

void UnlockBmDisplay(void)
{
    ProcPtr proc;

    gBmSt.lock_display--;

    if (gBmSt.lock_display != 0)
        return;

    Proc_ReleaseEachMarked(PROC_MARK_1);

    proc = FindProc(ProcScr_BmVSync);

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

static void WeatherInit_None(void)
{
    AllocWeatherParticles(gPlaySt.weather);
    SetOnHBlankB(NULL);
}

static void WeatherInit_Snow(void)
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

        gWeatherEffect.particles[i].x_speed = sParticleTemplates[templateId + 0] * 2;
        gWeatherEffect.particles[i].y_speed = sParticleTemplates[templateId + 1] * 2;
        gWeatherEffect.particles[i].kind = sParticleTemplates[templateId + 2];

        gWeatherEffect.particles[i].chr = chrs[sParticleTemplates[templateId + 2]];
    }
}

static void WeatherVBlank_Snow(void)
{
    if (GetOamSplice() != 0)
    {
        struct Vec2i origins[3];
        int i;

        struct WeatherParticle * it = gWeatherEffect.particles + ((GetGameTime() % 2) * 0x20);

        origins[0].x = (gBmSt.camera.x * 12) / 16;
        origins[0].y = gBmSt.camera.y;

        origins[1].x = gBmSt.camera.x;
        origins[1].y = gBmSt.camera.y;

        origins[2].x = (gBmSt.camera.x * 20) / 16;
        origins[2].y = gBmSt.camera.y;

        for (i = 0; i < 0x20; ++i)
        {
            it->x += it->x_speed;
            it->y += it->y_speed;

            PutOamLo(
                ((it->x >> 8) - origins[it->kind].x) & 0xFF,
                ((it->y >> 8) - origins[it->kind].y) & 0xFF,
                Sprite_8x8, OAM2_PAL(OBPAL_1) + it->chr);

            ++it;
        }
    }
}

static void WeatherInit_Rain(void)
{
    int i;

    AllocWeatherParticles(gPlaySt.weather);

    for (i = 0; i < 0x40; ++i)
    {
        int templateId = (i & 0xF) * 3;

        gWeatherEffect.particles[i].x = RandNextB();
        gWeatherEffect.particles[i].y = RandNextB();

        gWeatherEffect.particles[i].x_speed = sParticleTemplates[templateId+0] * 6;
        gWeatherEffect.particles[i].y_speed = sParticleTemplates[templateId+1] * 16;
        gWeatherEffect.particles[i].chr = sParticleTemplates[templateId+2];
    }
}

static void WeatherVBlank_Rain(void)
{
    if (GetOamSplice() != 0)
    {
        int i;

        struct WeatherParticle * it = gWeatherEffect.particles + ((GetGameTime() % 2) * 0x20);

        for (i = 0; i < 0x20; ++i)
        {
            it->x += it->x_speed;
            it->y += it->y_speed;

            PutOamLo(
                ((it->x >> 8) - gBmSt.camera.x) & 0xFF,
                ((it->y >> 8) - gBmSt.camera.y) & 0xFF,
                sRainSprites[it->chr], 0);

            ++it;
        }
    }
}

static void WeatherInit_Sandstorm(void)
{
    int i;

    AllocWeatherParticles(gPlaySt.weather);

    Decompress(Img_SandstormParticles, gBuf);
    Copy2dChr(gBuf, OBJ_VRAM0 + OBCHR_SANDSTORM_PARTICLE*CHR_SIZE, 4, 4);

    for (i = 0; i < 0x40; ++i)
    {
        gWeatherEffect.particles[i].x = RandNextB();
        gWeatherEffect.particles[i].y = (RandNextB() % DISPLAY_HEIGHT + DISPLAY_HEIGHT*3/2) & 0xFF;

        gWeatherEffect.particles[i].x_speed = (RandNextB() & 0x7) - 32;
        gWeatherEffect.particles[i].y_speed = 0;
    }
}

static void WeatherVBlank_Sandstorm(void)
{
    if (GetOamSplice() != 0)
    {
        int i;

        struct WeatherParticle * it = gWeatherEffect.particles + ((GetGameTime() % 2) * 0x20);

        for (i = 0; i < 0x20; ++i)
        {
            it->x += it->x_speed;

            PutOamLo(
                OAM1_X((it->x & 0xFF) - 0x10),
                it->y,
                Sprite_32x32, OAM2_PAL(OBPAL_1) + OBCHR_SANDSTORM_PARTICLE);

            ++it;
        }
    }
}

static void WeatherInit_Snowstorm(void)
{
    int i;

    u8 kindLut[8] = { 0, 0, 0, 0, 0, 0, 1, 1 };

    AllocWeatherParticles(gPlaySt.weather);

    Decompress(Img_SnowstormParticles, gBuf);
    Copy2dChr(gBuf, OBJ_VRAM0 + OBCHR_SNOWSTORM_PARTICLE*CHR_SIZE, 8, 4);

    for (i = 0; i < 0x40; ++i)
    {
        int kind = kindLut[i & 7];

        gWeatherEffect.particles[i].x = RandNextB();
        gWeatherEffect.particles[i].y = RandNextB();

        gWeatherEffect.particles[i].y_speed = (RandNextB() & 0x3FF) - 0x100;
        gWeatherEffect.particles[i].chr = kind;

        switch (kind)
        {

        case 0:
            gWeatherEffect.particles[i].x_speed = 0x700 + (RandNextB() & 0x1FF);
            break;

        case 1:
            gWeatherEffect.particles[i].x_speed = 0xA00 + (RandNextB() & 0x1FF);
            break;

        }
    }
}

static void WeatherVBlank_Snowstorm(void)
{
    if (GetOamSplice() != 0)
    {
        int i;

        struct WeatherParticle * it = gWeatherEffect.particles + ((GetGameTime() % 2) * 0x20);

        for (i = 0; i < 0x20; ++i)
        {
            it->x += it->x_speed;
            it->y += it->y_speed;

            PutOamLo(
                ((it->x >> 8) - gBmSt.camera.x) & 0xFF,
                ((it->y >> 8) - gBmSt.camera.y) & 0xFF,
                Sprite_32x32, OAM2_PAL(OBPAL_1) + OBCHR_SNOWSTORM_PARTICLE + (it->chr * 4));

            ++it;
        }
    }
}

static void BlueWeatherHBlank(void)
{
    u16 nextLine = (REG_VCOUNT + 1);

    if (nextLine > DISPLAY_HEIGHT)
        nextLine = 0;

    nextLine += gBmSt.camera.y / 2;

    if (nextLine >= 320)
        ((u16 *) PLTT)[0] = 0;
    else
        ((u16 *) PLTT)[0] = nextLine[gWeatherGradient.lines];
}

static void WeatherInit_Blue(void)
{
    int i;

    u16 * colors = gWeatherGradient.lines;

    for (i = 0; i < 320; ++i)
        *colors++ = RGB(0, 0, (31 - i / 10));

    SetOnHBlankB(BlueWeatherHBlank);
}

static void WeatherVBlank_Blue(void)
{
}

static void FlamesWeatherHBlank(void)
{
    const u16 * src;
    u16 * dst;

    u16 nextLine = (REG_VCOUNT + 1);

    if (nextLine < DISPLAY_HEIGHT*3/5)
        return;

    if (nextLine >= DISPLAY_HEIGHT)
        return;

    nextLine -= DISPLAY_HEIGHT*3/5;

    src = gWeatherGradient.fireGradient[0];
    src += nextLine * 8;

    dst = ((u16 *) PLTT) + 0x10*(BGPAL_TILESET+1) + (nextLine % 8) * 8;

    CpuFastCopy(src, dst, 8);
}

void ApplyFlamesWeatherGradient(void)
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

static void FlamesWeatherInitGradient(void)
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

    SetOnHBlankB(FlamesWeatherHBlank);
}

static void FlamesWeatherInitParticles(void)
{
    int i;

    AllocWeatherParticles(gPlaySt.weather);

    Decompress(Img_FlamesParticles, OBJ_VRAM0 + OBCHR_SNOWSTORM_PARTICLE * 0x20);
    ApplyPalette(Pal_FlamesParticles, 0x10+OBPAL_10);

    for (i = 0; i < 0x10; ++i)
    {
        gWeatherEffect.particles[i].x = RandNextB();
        gWeatherEffect.particles[i].y = RandNextB();

        gWeatherEffect.particles[i].x_speed = -sParticleTemplates[i*3 + 0];
        gWeatherEffect.particles[i].y_speed = -sParticleTemplates[i*3 + 1];
    }
}

static void WeatherInit_Flames(void)
{
    FlamesWeatherInitGradient();
    FlamesWeatherInitParticles();
}

static void FlamesWeatherUpdateGradient(void)
{
    int i, j;

    CpuFastCopy(
        gPal + (BGPAL_TILESET+1)*0x10,
        ((u16 *)(PLTT)) + (BGPAL_TILESET+1)*0x10,
        4*0x20);

    for (i = 12; i < 16; ++i)
    {
        const int color = gPal[(BGPAL_TILESET+3) * 0x10 + i];

        int r = RGB_GET_RED(color);
        int g = RGB_GET_GREEN(color);
        int b = RGB_GET_BLUE(color);

        for (j = 0; j < 8; ++j)
        {
            r = r + 2;

            if (r > 31)
                r = 31;

            gWeatherGradient.fireGradient[j][0x10 * 2 + i] = (b << 10) + (g << 5) + r;
        }
    }
}

static void FlamesWeatherUpdateParticles(void)
{
    struct WeatherParticle * it = gWeatherEffect.particles;

    if (GetOamSplice() != 0)
    {
        int i;

        for (i = 0; i < 0x10; ++i, ++it)
        {
            int y, oam2;

            it->x += it->x_speed;
            it->y += it->y_speed;

            y = ((it->y >> 8) - gBmSt.camera.y) & 0xFF;

            if (y < 0x40)
                continue;

            if (y > 0xA0)
                continue;

            oam2 = 31 - ((y - 0x40) / 8);

            if (oam2 < 24)
                oam2 = 24;

            PutOamLo(
                ((it->x >> 8) - gBmSt.camera.x) & 0xFF, y,
                Sprite_8x8, oam2 + OAM2_PAL(OBPAL_10));
        }
    }
}

static void WeatherVBlank_Flames(void)
{
    FlamesWeatherUpdateGradient();
    FlamesWeatherUpdateParticles();
}

static void CloudWeatherAnimateImage(u32 * lines)
{
    u32 buf[8];
    int ix, iy;

    // What this function is doing is "shifting" a 14
    // tile wide 4bpp image one pixel to the right(?)

    // Remember: lowest nibble of any gfx data is the leftmost pixel

    // Saving the rightmost tile column for later

    for (iy = 0; iy < 8; ++iy)
        buf[iy] = lines[iy + 0x68];

    // Shift all tiles right one pixel

    for (ix = (14 - 1); ix >= 0; --ix)
    {
        for (iy = 0; iy < 8; ++iy)
        {
            lines[(8*(ix - 1)) + iy + 8] =
                (lines[(8*(ix - 1)) + iy + 8] << 4) | (lines[(8*(ix - 1)) + iy] >> 28);
        }
    }

    // the leftmost pixel column now contains garbage
    // but that's only, we're fixing it now
    // this is why we needed the rightmost column to be saved

    for (iy = 0; iy < 8; ++iy)
    {
        lines[iy] &= ~0xF;
        lines[iy] = (lines[iy]) | (buf[iy] >> 28);
    }
}

static void WeatherInit_Clouds(void)
{
    AllocWeatherParticles(WEATHER_NONE);

    Decompress(Img_CloudWeather, gWeatherEffect.imgCloud);
    ApplyPalette(Pal_CloudWeather, 0x10+OBPAL_10);
}

static void WeatherVBlank_Clouds(void)
{
    u32 * img = gWeatherEffect.imgCloud;

    switch (GetGameTime() % 8)
    {

    case 0:
        CloudWeatherAnimateImage(img + 0*(14*8));
        break;

    case 2:
        CloudWeatherAnimateImage(img + 1*(14*8));
        break;

    case 4:
        CloudWeatherAnimateImage(img + 2*(14*8));
        break;

    case 6:
        CloudWeatherAnimateImage(img + 3*(14*8));
        break;

    case 7:
        Copy2dChr(img, OBJ_VRAM0 + CHR_SIZE*OBCHR_CLOUDS, 14, 4);
        break;

    }
}

static void WeatherUpdate_Clouds(void)
{
    int y = gBmSt.camera.y;

    PutSprite(14, 0, -(y/5),
        Sprite_CloudWeather, OAM2_CHR(OBCHR_CLOUDS) + OAM2_LAYER(3) + OAM2_PAL(OBPAL_10));
}

void WeatherInit(void)
{
    switch (gPlaySt.weather)
    {

    case WEATHER_NONE:
        WeatherInit_None();
        break;

    case WEATHER_SNOW:
        WeatherInit_Snow();
        break;

    case WEATHER_SANDSTORM:
        WeatherInit_Sandstorm();
        break;

    case WEATHER_SNOWSTORM:
        WeatherInit_Snowstorm();
        break;

    case WEATHER_RAIN:
        WeatherInit_Rain();
        break;

    case WEATHER_NIGHT:
        WeatherInit_Blue();
        break;

    case WEATHER_FLAMES:
        WeatherInit_Flames();
        break;

    case WEATHER_CLOUDS:
        WeatherInit_Clouds();
        break;

    }
}

void WeatherVBlank(void)
{
    switch (gPlaySt.weather)
    {

    case WEATHER_SNOW:
        WeatherVBlank_Snow();
        break;

    case WEATHER_SANDSTORM:
        WeatherVBlank_Sandstorm();
        break;

    case WEATHER_SNOWSTORM:
        WeatherVBlank_Snowstorm();
        break;

    case WEATHER_RAIN:
        WeatherVBlank_Rain();
        break;

    case WEATHER_NIGHT:
        WeatherVBlank_Blue();
        break;

    case WEATHER_FLAMES:
        WeatherVBlank_Flames();
        break;

    case WEATHER_CLOUDS:
        WeatherVBlank_Clouds();
        break;

    }
}

void WeatherUpdate(void)
{
    if (gPlaySt.weather == WEATHER_CLOUDS)
        WeatherUpdate_Clouds();
}

void DisableTilesetPalAnim(void)
{
    struct BmVSyncProc * proc = FindProc(ProcScr_BmVSync);

    if (proc)
        proc->palAnimStart = NULL;
}

void EnableTilesetPalAnim(void)
{
    struct BmVSyncProc * proc = FindProc(ProcScr_BmVSync);

    if (proc)
    {
        proc->palAnimStart = proc->palAnimCurrent =
            ChapterAssets[GetChapterInfo(gPlaySt.chapter)->asset_pal_anims];
    }
}

void SetWeather(int weather)
{
    gPlaySt.weather = weather;

    AllocWeatherParticles(weather);
    WeatherInit();
}
