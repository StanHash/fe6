#include "ui.h"

#include "hardware.h"
#include "move.h"
#include "oam.h"
#include "sprite.h"
#include "util.h"
#include "bm.h"

#include "constants/video-global.h"

#define FRAME_TILE(chr) TILEREF((chr), BGPAL_WINDOW_FRAME)

u16 const UiWindowFrameModelTmRegular[] =
{
    FRAME_TILE(0x01), FRAME_TILE(0x02), FRAME_TILE(0x02), FRAME_TILE(0x03),
    FRAME_TILE(0x04), FRAME_TILE(0x5B), FRAME_TILE(0x5C), FRAME_TILE(0x06),
    FRAME_TILE(0x04), FRAME_TILE(0x5D), FRAME_TILE(0x5E), FRAME_TILE(0x06),
    FRAME_TILE(0x07), FRAME_TILE(0x08), FRAME_TILE(0x08), FRAME_TILE(0x09),
};

u16 const UiWindowFrameModelTmFill[] =
{
    FRAME_TILE(0x64), FRAME_TILE(0x65), FRAME_TILE(0x66), FRAME_TILE(0x67),
    FRAME_TILE(0x68), FRAME_TILE(0x5B), FRAME_TILE(0x5C), FRAME_TILE(0x69),
    FRAME_TILE(0x6A), FRAME_TILE(0x5D), FRAME_TILE(0x5E), FRAME_TILE(0x6B),
    FRAME_TILE(0x6C), FRAME_TILE(0x6D), FRAME_TILE(0x6E), FRAME_TILE(0x6F),
};

u16 const UiWindowFrameModelTmSable[] =
{
    FRAME_TILE(0x0A), FRAME_TILE(0x0B), FRAME_TILE(0x0B), FRAME_TILE(0x0C),
    FRAME_TILE(0x0D), FRAME_TILE(0x0E), FRAME_TILE(0x0E), FRAME_TILE(0x0F),
    FRAME_TILE(0x0D), FRAME_TILE(0x0E), FRAME_TILE(0x0E), FRAME_TILE(0x0F),
    FRAME_TILE(0x10), FRAME_TILE(0x11), FRAME_TILE(0x11), FRAME_TILE(0x12),
};

#undef FRAME_TILE

u16 const * CONST_DATA gUiWindowFrameModelLut[] =
{
    [UI_WINDOW_REGULAR] = UiWindowFrameModelTmRegular,
    [UI_WINDOW_FILL]    = UiWindowFrameModelTmFill,
    [UI_WINDOW_SABLE]   = UiWindowFrameModelTmSable,
};

u16 const * CONST_DATA gUiWindowFramePalLut[] =
{
    [UI_WINDOW_THEME_BLUE]  = Pal_UiWindowFrame_ThemeBlue,
    [UI_WINDOW_THEME_RED]   = Pal_UiWindowFrame_ThemeRed,
    [UI_WINDOW_THEME_GRAY]  = Pal_UiWindowFrame_ThemeGray,
    [UI_WINDOW_THEME_GREEN] = Pal_UiWindowFrame_ThemeGreen,
};

u8 const * CONST_DATA gUiWindowFrameImgLut[] =
{
    [UI_WINDOW_THEME_BLUE]  = Img_UiWindowFrame_ThemeBlue,
    [UI_WINDOW_THEME_RED]   = Img_UiWindowFrame_ThemeRed,
    [UI_WINDOW_THEME_GRAY]  = Img_UiWindowFrame_ThemeGray,
    [UI_WINDOW_THEME_GREEN] = Img_UiWindowFrame_ThemeGreen,
};

u16 const * CONST_DATA gUiStatBarPalLut[] =
{
    [UI_WINDOW_THEME_BLUE]  = Pal_UiStatBar_ThemeBlue,
    [UI_WINDOW_THEME_RED]   = Pal_UiStatBar_ThemeRed,
    [UI_WINDOW_THEME_GRAY]  = Pal_UiStatBar_ThemeGray,
    [UI_WINDOW_THEME_GREEN] = Pal_UiStatBar_ThemeGreen,
};

void ApplyUiWindowFramePal(int palid)
{
    if (palid < 0)
        palid = BGPAL_WINDOW_FRAME;

    ApplyPalette(gUiWindowFramePalLut[gPlaySt.config_window_theme], palid);
}

void UnpackUiWindowFrameImg(void * vram)
{
    if (vram == NULL)
        vram = (void *) VRAM + CHR_SIZE * BGCHR_WINDOW_FRAME;

    Decompress(gUiWindowFrameImgLut[gPlaySt.config_window_theme], vram);
}

void ApplyUiStatBarPal(int palid)
{
    if (palid < 0)
        palid = BGPAL_UI_STATBAR;

    ApplyPalette(gUiStatBarPalLut[gPlaySt.config_window_theme], palid);
}

void UnpackUiWindowFrameGraphics2(int window_theme)
{
    void * buf;
    u32 len;

    if (window_theme < 0)
        window_theme = gPlaySt.config_window_theme;

    len = GetDataSize(gUiWindowFrameImgLut[window_theme]);
    buf = gBuf + ARRAY_COUNT(gBuf) - (len / sizeof(*gBuf));

    Decompress(gUiWindowFrameImgLut[window_theme], buf);
    RegisterDataMove(buf, (void *) VRAM + CHR_SIZE * BGCHR_WINDOW_FRAME, len);

    ApplyUiWindowFramePal(-1);
}

void PutUiWindowFrame(int x, int y, int width, int height, int window_kind)
{
    #define WINDOW_MODEL_OFFSET(x, y) ((x) + (y) * 4)

    int iy, ix;

    u16 const * model = gUiWindowFrameModelLut[window_kind];
    int x_edge = x + width - 1;
    int y_edge = y + height - 1;

    // put middle tiles

    for (iy = y + 1; iy < y_edge; iy += 2)
    {
        for (ix = x + 1; ix < x_edge; ix += 2)
        {
            u16 tm_offset;

            tm_offset = TM_OFFSET(ix, iy);
            gBg0Tm[tm_offset] = 0;
            gBg1Tm[tm_offset] = model[WINDOW_MODEL_OFFSET(1, 1)];

            tm_offset += TM_OFFSET(1, 0);
            gBg0Tm[tm_offset] = 0;
            gBg1Tm[tm_offset] = model[WINDOW_MODEL_OFFSET(2, 1)];

            tm_offset += TM_OFFSET(-1, 1);
            gBg0Tm[tm_offset] = 0;
            gBg1Tm[tm_offset] = model[WINDOW_MODEL_OFFSET(1, 2)];

            tm_offset += TM_OFFSET(1, 0);
            gBg0Tm[tm_offset] = 0;
            gBg1Tm[tm_offset] = model[WINDOW_MODEL_OFFSET(2, 2)];
        }
    }

    // put edge tiles

    for (ix = x + 1; ix < x_edge; ix += 2)
    {
        gBg0Tm[TM_OFFSET(ix+0, y)]      = 0;
        gBg1Tm[TM_OFFSET(ix+0, y)]      = model[WINDOW_MODEL_OFFSET(1, 0)];

        gBg0Tm[TM_OFFSET(ix+1, y)]      = 0;
        gBg1Tm[TM_OFFSET(ix+1, y)]      = model[WINDOW_MODEL_OFFSET(2, 0)];

        gBg0Tm[TM_OFFSET(ix+0, y_edge)] = 0;
        gBg1Tm[TM_OFFSET(ix+0, y_edge)] = model[WINDOW_MODEL_OFFSET(1, 3)];

        gBg0Tm[TM_OFFSET(ix+1, y_edge)] = 0;
        gBg1Tm[TM_OFFSET(ix+1, y_edge)] = model[WINDOW_MODEL_OFFSET(2, 3)];
    }

    for (iy = y + 1; iy < y_edge; iy += 2)
    {
        gBg0Tm[TM_OFFSET(x,      iy+0)] = 0;
        gBg1Tm[TM_OFFSET(x,      iy+0)] = model[WINDOW_MODEL_OFFSET(0, 1)];

        gBg0Tm[TM_OFFSET(x_edge, iy+0)] = 0;
        gBg1Tm[TM_OFFSET(x_edge, iy+0)] = model[WINDOW_MODEL_OFFSET(3, 1)];

        gBg0Tm[TM_OFFSET(x,      iy+1)] = 0;
        gBg1Tm[TM_OFFSET(x,      iy+1)] = model[WINDOW_MODEL_OFFSET(0, 2)];

        gBg0Tm[TM_OFFSET(x_edge, iy+1)] = 0;
        gBg1Tm[TM_OFFSET(x_edge, iy+1)] = model[WINDOW_MODEL_OFFSET(3, 2)];
    }

    // put corner tiles

    gBg0Tm[TM_OFFSET(x,      y)]      = 0;
    gBg0Tm[TM_OFFSET(x_edge, y)]      = 0;
    gBg0Tm[TM_OFFSET(x,      y_edge)] = 0;
    gBg0Tm[TM_OFFSET(x_edge, y_edge)] = 0;

    gBg1Tm[TM_OFFSET(x,      y)]      = model[WINDOW_MODEL_OFFSET(0, 0)];
    gBg1Tm[TM_OFFSET(x_edge, y)]      = model[WINDOW_MODEL_OFFSET(3, 0)];
    gBg1Tm[TM_OFFSET(x,      y_edge)] = model[WINDOW_MODEL_OFFSET(0, 3)];
    gBg1Tm[TM_OFFSET(x_edge, y_edge)] = model[WINDOW_MODEL_OFFSET(3, 3)];

    SetBgOffset(0, 0, 0);
    SetBgOffset(1, 0, 0);

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);

    #undef WINDOW_MODEL_OFFSET
}

struct Vec2i EWRAM_DATA gPrevUiHandPutPosition = { 0, 0 };
int EWRAM_DATA gPrevUiHandClockFrame = 0;

u16 CONST_DATA Sprite_UiHand[] =
{
    1, OAM0_SHAPE_16x16 + OAM0_Y(2), OAM1_SIZE_16x16, 0,
};

u8 CONST_DATA gUiHandOffsetLut[] =
{
    0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 3, 3, 3, 3,
    4, 4, 4, 4, 4, 4, 4, 3, 3, 2, 2, 2, 1, 1, 1, 1,
};

void PutUiHand(int x, int y)
{
    if ((GetGameTime() - 1) == gPrevUiHandClockFrame)
    {
        x = (x + gPrevUiHandPutPosition.x) >> 1;
        y = (y + gPrevUiHandPutPosition.y) >> 1;
    }

    gPrevUiHandPutPosition.x = x;
    gPrevUiHandPutPosition.y = y;

    gPrevUiHandClockFrame = GetGameTime();

    x += gUiHandOffsetLut[GetGameTime() % ARRAY_COUNT(gUiHandOffsetLut)] - 14;

    PutSprite(2, x, y, Sprite_UiHand, 0);
}

void PutFrozenUiHand(int x, int y)
{
    PutSprite(3, x - 12, y, Sprite_UiHand, 0);
}

int GetUiHandPrevX(void)
{
    return gPrevUiHandPutPosition.x;
}

int GetUiHandPrevY(void)
{
    return gPrevUiHandPutPosition.y;
}

void ClearUi(void)
{
    TmFill(gBg0Tm, 0);
    TmFill(gBg1Tm, 0);

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);
}

enum
{
    UI_ENTRY_HOVER_TILE_LEFT,
    UI_ENTRY_HOVER_TILE_MIDDLE_EVEN,
    UI_ENTRY_HOVER_TILE_RIGHT_EVEN,
    UI_ENTRY_HOVER_TILE_UNK_3,
    UI_ENTRY_HOVER_TILE_MIDDLE_ODD,
    UI_ENTRY_HOVER_TILE_RIGHT_ODD,
    UI_ENTRY_HOVER_TILE_CLEAR_EVEN,
    UI_ENTRY_HOVER_TILE_CLEAR_ODD,
};

u16 const gUiEntryHoverTileLut[] =
{
    [UI_ENTRY_HOVER_TILE_LEFT]        = TILEREF(0x78, BGPAL_WINDOW_FRAME),
    [UI_ENTRY_HOVER_TILE_MIDDLE_EVEN] = TILEREF(0x79, BGPAL_WINDOW_FRAME),
    [UI_ENTRY_HOVER_TILE_RIGHT_EVEN]  = TILEREF(0x7A, BGPAL_WINDOW_FRAME),
    [UI_ENTRY_HOVER_TILE_UNK_3]       = TILEREF(0x7B, BGPAL_WINDOW_FRAME),
    [UI_ENTRY_HOVER_TILE_MIDDLE_ODD]  = TILEREF(0x7C, BGPAL_WINDOW_FRAME),
    [UI_ENTRY_HOVER_TILE_RIGHT_ODD]   = TILEREF(0x7D, BGPAL_WINDOW_FRAME),
    [UI_ENTRY_HOVER_TILE_CLEAR_EVEN]  = TILEREF(0x5D, BGPAL_WINDOW_FRAME),
    [UI_ENTRY_HOVER_TILE_CLEAR_ODD]   = TILEREF(0x5E, BGPAL_WINDOW_FRAME),
};

void PutUiEntryHover(int x, int y, int width)
{
    int x_edge = x + width - 1;
    y += 1;

    gBg1Tm[TM_OFFSET(x, y)] = gUiEntryHoverTileLut[UI_ENTRY_HOVER_TILE_LEFT];

    for (x += 1; x < x_edge; x += 2)
    {
        gBg1Tm[TM_OFFSET(x + 0, y)] = gUiEntryHoverTileLut[UI_ENTRY_HOVER_TILE_MIDDLE_ODD];
        gBg1Tm[TM_OFFSET(x + 1, y)] = gUiEntryHoverTileLut[UI_ENTRY_HOVER_TILE_MIDDLE_EVEN];
    }

    gBg1Tm[TM_OFFSET(x_edge, y)] = (width % 2) != 0
        ? gUiEntryHoverTileLut[UI_ENTRY_HOVER_TILE_RIGHT_EVEN]
        : gUiEntryHoverTileLut[UI_ENTRY_HOVER_TILE_RIGHT_ODD];

    EnableBgSync(BG1_SYNC_BIT);
}

void RemoveUiEntryHover(int x, int y, int width)
{
    int x_edge = x + width - 1;
    y += 1;

    for (; x < x_edge; x += 2)
    {
        gBg1Tm[TM_OFFSET(x + 0, y)] = gUiEntryHoverTileLut[UI_ENTRY_HOVER_TILE_CLEAR_EVEN];
        gBg1Tm[TM_OFFSET(x + 1, y)] = gUiEntryHoverTileLut[UI_ENTRY_HOVER_TILE_CLEAR_ODD];
    }

    gBg1Tm[TM_OFFSET(x_edge, y)] = (width % 2) != 0
        ? gUiEntryHoverTileLut[UI_ENTRY_HOVER_TILE_CLEAR_EVEN]
        : gUiEntryHoverTileLut[UI_ENTRY_HOVER_TILE_CLEAR_ODD];

    EnableBgSync(BG1_SYNC_BIT);
}

void UnpackUiUnitNameFrameGraphics(void * vram, int palid, int palcount)
{
    Decompress(Img_UiUnitNameFrame, vram);
    ApplyPalettes(Pal_UiUnitNameFrame, palid, palcount);
}

void UnpackUiWindowFrameGraphics(void)
{
    UnpackUiWindowFrameImg(NULL);
    ApplyUiWindowFramePal(-1);
}
