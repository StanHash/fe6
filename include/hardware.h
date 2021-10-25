#pragma once

#include "common.h"

struct KeySt
{
    /* 00 */ u8 repeat_delay;    // initial delay before generating auto-repeat presses
    /* 01 */ u8 repeat_interval; // time between auto-repeat presses
    /* 02 */ u8 repeat_clock;    // (decreased by one each frame, reset to repeat_delay when Presses change and repeat_interval when reaches 0)
    /* 04 */ u16 held;           // keys that are currently held down
    /* 06 */ u16 repeated;       // auto-repeated keys
    /* 08 */ u16 pressed;        // keys that went down this frame
    /* 0A */ u16 previous;       // keys that were held down last frame
    /* 0C */ u16 last;
    /* 0E */ u16 ablr_pressed; // 1 for Release (A B L R Only), 0 Otherwise
    /* 10 */ u16 pressed2;
    /* 12 */ u16 time_since_start_select; // Time since last Non-Start Non-Select Button was pressed
};

struct DispIo
{
    /* 00 */ struct DispCnt disp_ct;
    /* 04 */ struct DispStat disp_stat;
    /* 08 */ u8 pad_08[4];
    /* 0C */ struct BgCnt bg0_ct;
    /* 10 */ struct BgCnt bg1_ct;
    /* 14 */ struct BgCnt bg2_ct;
    /* 18 */ struct BgCnt bg3_ct;
    /* 1C */ struct Vec2u bg_off[4];
    /* 2C */ u8 win0_right, win0_left, win1_right, win1_left;
    /* 30 */ u8 win0_bottom, win0_top, win1_bottom, win1_top;
    /* 34 */ struct WinCnt win_ct;
    /* 38 */ u16 mosaic;
    /* 3A */ u8 pad_3A[2];
    /* 3C */ struct BlendCnt blend_ct;
    /* 40 */ u8 pad_40[4];
    /* 44 */ u8 blend_coef_a;
    /* 45 */ u8 blend_coef_b;
    /* 46 */ u8 blend_y;
    /* 48 */ u16 bg2pa;
    /* 4A */ u16 bg2pb;
    /* 4C */ u16 bg2pc;
    /* 4E */ u16 bg2pd;
    /* 50 */ u32 bg2x;
    /* 54 */ u32 bg2y;
    /* 58 */ u16 bg3pa;
    /* 5A */ u16 bg3pb;
    /* 5C */ u16 bg3pc;
    /* 5E */ u16 bg3pd;
    /* 60 */ u32 bg3x;
    /* 64 */ u32 bg3y;
    /* 68 */ i8 color_addition;
};

enum
{
    BG0_SYNC_BIT = (1 << 0),
    BG1_SYNC_BIT = (1 << 1),
    BG2_SYNC_BIT = (1 << 2),
    BG3_SYNC_BIT = (1 << 3),
};

unsigned GetGameTime(void);
void SetGameTime(unsigned time);
void IncGameTime(void);
bool FormatTime(unsigned time, u16* hours, u16* minutes, u16* seconds);
void EnableBgSync(int bits);
void EnableBgSyncById(int bgid);
void DisableBgSync(int bits);
void EnablePalSync(void);
void DisablePalSync(void);
void ApplyPaletteExt(void const* data, int startOffset, int size);
void SyncDispIo(void);
int GetBgChrOffset(int bg);
int GetBgChrId(int bg, int offset);
int GetBgTilemapOffset(int bg);
void SetBgChrOffset(int bg, int offset);
void SetBgTilemapOffset(int bg, int offset);
void SetBgScreenSize(int bg, int size);
void SetBgBpp(int bg, int bpp);
void SyncBgsAndPal(void);
void TmFill(u16* dest, int tileref);
void SetBlankChr(int chr);
void SetOnVBlank(Func func);
void SetOnVMatch(Func func);
void SetNextVCount(int vcount);
void SetVCount(int vcount);
void SetMainFunc(Func func);
void RunMainFunc(void);
void RefreshKeySt(struct KeySt* keySt);
void ClearKeySt(struct KeySt* keySt);
void InitKeySt(struct KeySt* keySt);
void SetBgOffset(u16 bgid, u16 xOffset, u16 yOffset);
void sub_8001AE4(void);
void sub_8001B18(u8 a, u8 b);
void sub_8001B4C(u16* a, u16* b);
void sub_8001B8C(void* outTm, void const* inData, u8 base, u8 linebits);
void sub_8001C68(u16* outTm, short const* inData, int unused);
void sub_8001D0C(void);
void sub_8001D44(u16 const* inPal, int bank, int count, int unk);
void sub_8001E68(int a, int b, int c, int d);
void sub_8001F88(int a, int b, int c);
void sub_8001FD4(i8 a);
void sub_800210C(i8 a);
void sub_8002234(i8 a);
void sub_800236C(i8 a);
void sub_80024A4(void);
void InitBgs(u16 const* config);
u16* GetBgTilemap(int bg);
void SoftResetIfKeyCombo(void);
void sub_800285C(int unk);
void SetOnHBlankA(Func func);
void SetOnHBlankB(Func func);

extern u8 EWRAM_DATA gBuf[0x2000];

extern u16 EWRAM_DATA gPal[0x200];

extern u16 EWRAM_DATA gBg0Tm[0x400];
extern u16 EWRAM_DATA gBg1Tm[0x400];
extern u16 EWRAM_DATA gBg2Tm[0x400];
extern u16 EWRAM_DATA gBg3Tm[0x400];

extern struct KeySt* CONST_DATA gKeySt;

extern struct DispIo gDispIo;

extern short const gSinLut[];

#define RGB_GET_RED(color) ((color) & 0x1F)
#define RGB_GET_GREEN(color) (((color) >> 5) & 0x1F)
#define RGB_GET_BLUE(color) (((color) >> 10) & 0x1F)

#define TM_OFFSET(x, y) (((y) << 5) + (x))

#define TILEREF(chr, pal) ((chr) + ((pal) << 12))
#define TILE_HFLIP 0x0400
#define TILE_VFLIP 0x0800

#define PAL_COLOR(palid, colornum) gPal[(palid) * 0x10 + (colornum)]
#define PAL_BG_COLOR(palid, colornum) PAL_COLOR(palid, colornum)
#define PAL_OBJ_COLOR(palid, colornum) PAL_COLOR((palid) + 0x10, colornum)

#define SIN_Q12(angle) (gSinLut[(angle) & 0xFF])
#define COS_Q12(angle) (gSinLut[0x40 + ((angle) & 0xFF)])

#define ApplyPalettes(src, num, count) ApplyPaletteExt((src), 0x20 * (num), 0x20 * (count))
#define ApplyPalette(src, num) ApplyPalettes((src), (num), 1)

#define SetDispEnable(bg0, bg1, bg2, bg3, obj) \
    gDispIo.disp_ct.bg0_on = (bg0); \
    gDispIo.disp_ct.bg1_on = (bg1); \
    gDispIo.disp_ct.bg2_on = (bg2); \
    gDispIo.disp_ct.bg3_on = (bg3); \
    gDispIo.disp_ct.obj_on = (obj)

#define SetWinEnable(win0, win1, objwin) \
    gDispIo.disp_ct.win0_on = (win0); \
    gDispIo.disp_ct.win1_on = (win1); \
    gDispIo.disp_ct.objWin_on = (objwin)

#define SetWin0Box(left, top, right, bottom) \
    gDispIo.win0_left = (left); \
    gDispIo.win0_top = (top); \
    gDispIo.win0_right = (right); \
    gDispIo.win0_bottom = (bottom)

#define SetWin1Box(left, top, right, bottom) \
    gDispIo.win1_left = (left); \
    gDispIo.win1_top = (top); \
    gDispIo.win1_right = (right); \
    gDispIo.win1_bottom = (bottom)

#define SetWin0Layers(bg0, bg1, bg2, bg3, obj) \
    gDispIo.win_ct.win0_enableBg0 = (bg0); \
    gDispIo.win_ct.win0_enableBg1 = (bg1); \
    gDispIo.win_ct.win0_enableBg2 = (bg2); \
    gDispIo.win_ct.win0_enableBg3 = (bg3); \
    gDispIo.win_ct.win0_enableObj = (obj)

#define SetWin1Layers(bg0, bg1, bg2, bg3, obj) \
    gDispIo.win_ct.win1_enableBg0 = (bg0); \
    gDispIo.win_ct.win1_enableBg1 = (bg1); \
    gDispIo.win_ct.win1_enableBg2 = (bg2); \
    gDispIo.win_ct.win1_enableBg3 = (bg3); \
    gDispIo.win_ct.win1_enableObj = (obj)

#define SetWObjLayers(bg0, bg1, bg2, bg3, obj) \
    gDispIo.win_ct.wobj_enableBg0 = (bg0); \
    gDispIo.win_ct.wobj_enableBg1 = (bg1); \
    gDispIo.win_ct.wobj_enableBg2 = (bg2); \
    gDispIo.win_ct.wobj_enableBg3 = (bg3); \
    gDispIo.win_ct.wobj_enableObj = (obj)

#define SetWOutLayers(bg0, bg1, bg2, bg3, obj) \
    gDispIo.win_ct.wout_enableBg0 = (bg0); \
    gDispIo.win_ct.wout_enableBg1 = (bg1); \
    gDispIo.win_ct.wout_enableBg2 = (bg2); \
    gDispIo.win_ct.wout_enableBg3 = (bg3); \
    gDispIo.win_ct.wout_enableObj = (obj)

#define SetBlendConfig(eff, ca, cb, cy) \
    gDispIo.blend_ct.effect = (eff); \
    gDispIo.blend_coef_a = (ca); \
    gDispIo.blend_coef_b = (cb); \
    gDispIo.blend_y = (cy)

#define SetBlendAlpha(ca, cb) \
    SetBlendConfig(1, (ca), (cb), 0)

#define SetBlendBrighten(cy) \
    SetBlendConfig(2, 0, 0, (cy))

#define SetBlendDarken(cy) \
    SetBlendConfig(3, 0, 0, (cy))

#define SetBlendNone() \
    SetBlendConfig(0, 0x10, 0, 0)

#define SetBlendTargetA(bg0, bg1, bg2, bg3, obj) \
    *((u16*) &gDispIo.blend_ct) &= 0xFFE0; \
    *((u16*) &gDispIo.blend_ct) |= ((bg0) + ((bg1) << 1) + ((bg2) << 2) + ((bg3) << 3) + ((obj) << 4))

#define SetBlendTargetB(bg0, bg1, bg2, bg3, obj) \
    *((u16*) &gDispIo.blend_ct) &= 0xE0FF; \
    *((u16*) &gDispIo.blend_ct) |= (((bg0) << 8) + ((bg1) << 9) + ((bg2) << 10) + ((bg3) << 11) + ((obj) << 12))

#define SetBlendBackdropA(enable) \
    gDispIo.blend_ct.target1_bd_on = (enable);

#define SetBlendBackdropB(enable) \
    gDispIo.blend_ct.target2_bd_on = (enable);
