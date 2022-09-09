#pragma once

#include "types.h"

#define REG(type, addr) (*((type volatile *) (addr)))

#define REG_DISPCNT     REG(u16, 0x04000000)
#define REG_DISPSTAT    REG(u16, 0x04000004)
#define REG_VCOUNT      REG(u16, 0x04000006)
#define REG_BG0CNT      REG(u16, 0x04000008)
#define REG_BG1CNT      REG(u16, 0x0400000A)
#define REG_BG2CNT      REG(u16, 0x0400000C)
#define REG_BG3CNT      REG(u16, 0x0400000E)
#define REG_BG0HOFS     REG(u16, 0x04000010)
#define REG_BG0VOFS     REG(u16, 0x04000012)
#define REG_BG1HOFS     REG(u16, 0x04000014)
#define REG_BG1VOFS     REG(u16, 0x04000016)
#define REG_BG2HOFS     REG(u16, 0x04000018)
#define REG_BG2VOFS     REG(u16, 0x0400001A)
#define REG_BG3HOFS     REG(u16, 0x0400001C)
#define REG_BG3VOFS     REG(u16, 0x0400001E)
#define REG_BG2PA       REG(i16, 0x04000020)
#define REG_BG2PB       REG(i16, 0x04000022)
#define REG_BG2PC       REG(i16, 0x04000024)
#define REG_BG2PD       REG(i16, 0x04000026)
#define REG_BG2X        REG(i32, 0x04000028)
#define REG_BG2Y        REG(i32, 0x0400002C)
#define REG_BG3PA       REG(i16, 0x04000030)
#define REG_BG3PB       REG(i16, 0x04000032)
#define REG_BG3PC       REG(i16, 0x04000034)
#define REG_BG3PD       REG(i16, 0x04000036)
#define REG_BG3X        REG(i32, 0x04000038)
#define REG_BG3Y        REG(i32, 0x0400003C)
#define REG_WIN0H       REG(u16, 0x04000040)
#define REG_WIN1H       REG(u16, 0x04000042)
#define REG_WIN0V       REG(u16, 0x04000044)
#define REG_WIN1V       REG(u16, 0x04000046)
#define REG_WININ       REG(u16, 0x04000048)
#define REG_WINOUT      REG(u16, 0x0400004A)
#define REG_MOSAIC      REG(u16, 0x0400004C)
#define REG_BLDCNT      REG(u16, 0x04000050)
#define REG_BLDALPHA    REG(u16, 0x04000052)
#define REG_BLDCA       REG(u8,  0x04000052 + 0)
#define REG_BLDCB       REG(u8,  0x04000052 + 1)
#define REG_BLDY        REG(u8,  0x04000054)

#define REG_SOUND1CNT_L REG(u16, 0x04000060)
#define REG_NR10        REG(u8,  0x04000060)
#define REG_SOUND1CNT_H REG(u16, 0x04000062)
#define REG_NR11        REG(u8,  0x04000062)
#define REG_NR12        REG(u8,  0x04000063)
#define REG_SOUND1CNT_X REG(u16, 0x04000064)
#define REG_NR13        REG(u8,  0x04000064)
#define REG_NR14        REG(u8,  0x04000065)
#define REG_SOUND2CNT_L REG(u16, 0x04000068)
#define REG_NR21        REG(u8,  0x04000068)
#define REG_NR22        REG(u8,  0x04000069)
#define REG_SOUND2CNT_H REG(u16, 0x0400006C)
#define REG_NR23        REG(u8,  0x0400006C)
#define REG_NR24        REG(u8,  0x0400006D)
#define REG_SOUND3CNT_L REG(u16, 0x04000070)
#define REG_NR30        REG(u8,  0x04000070)
#define REG_SOUND3CNT_H REG(u16, 0x04000072)
#define REG_NR31        REG(u8,  0x04000072)
#define REG_NR32        REG(u8,  0x04000073)
#define REG_SOUND3CNT_X REG(u16, 0x04000074)
#define REG_NR33        REG(u8,  0x04000074)
#define REG_NR34        REG(u8,  0x04000075)
#define REG_SOUND4CNT_L REG(u16, 0x04000078)
#define REG_NR41        REG(u8,  0x04000078)
#define REG_NR42        REG(u8,  0x04000079)
#define REG_SOUND4CNT_H REG(u16, 0x0400007C)
#define REG_NR43        REG(u8,  0x0400007C)
#define REG_NR44        REG(u8,  0x0400007D)
#define REG_SOUNDCNT_L  REG(u16, 0x04000080)
#define REG_NR50        REG(u8,  0x04000080)
#define REG_NR51        REG(u8,  0x04000081)
#define REG_SOUNDCNT_H  REG(u16, 0x04000082)
#define REG_SOUNDCNT_X  REG(u16, 0x04000084)
#define REG_NR52        REG(u8,  0x04000084)
#define REG_SOUNDBIAS   REG(u16, 0x04000088)
#define REG_SOUNDBIAS_L REG(u8,  0x04000088)
#define REG_SOUNDBIAS_H REG(u8,  0x04000089)
#define REG_WAVE_RAM0   REG(u32, 0x04000090)
#define REG_WAVE_RAM1   REG(u32, 0x04000094)
#define REG_WAVE_RAM2   REG(u32, 0x04000098)
#define REG_WAVE_RAM3   REG(u32, 0x0400009C)
#define REG_FIFO_A      REG(u32, 0x040000A0)
#define REG_FIFO_B      REG(u32, 0x040000A4)

#define REG_DMA0SAD     REG(u32, 0x040000B0)
#define REG_DMA0DAD     REG(u32, 0x040000B4)
#define REG_DMA0CNT     REG(u32, 0x040000B8)
#define REG_DMA0CNT_L   REG(u16, 0x040000B8)
#define REG_DMA0CNT_H   REG(u16, 0x040000BA)

#define REG_DMA1SAD     REG(u32, 0x040000BC)
#define REG_DMA1DAD     REG(u32, 0x040000C0)
#define REG_DMA1CNT     REG(u32, 0x040000C4)
#define REG_DMA1CNT_L   REG(u16, 0x040000C4)
#define REG_DMA1CNT_H   REG(u16, 0x040000C6)

#define REG_DMA2SAD     REG(u32, 0x040000C8)
#define REG_DMA2DAD     REG(u32, 0x040000CC)
#define REG_DMA2CNT     REG(u32, 0x040000D0)
#define REG_DMA2CNT_L   REG(u16, 0x040000D0)
#define REG_DMA2CNT_H   REG(u16, 0x040000D2)

#define REG_DMA3SAD     REG(u32, 0x040000D4)
#define REG_DMA3DAD     REG(u32, 0x040000D8)
#define REG_DMA3CNT     REG(u32, 0x040000DC)
#define REG_DMA3CNT_L   REG(u16, 0x040000DC)
#define REG_DMA3CNT_H   REG(u16, 0x040000DE)

#define REG_TM0CNT      REG(u32, 0x04000100)
#define REG_TM0CNT_L    REG(u16, 0x04000100)
#define REG_TM0CNT_H    REG(u16, 0x04000102)
#define REG_TM1CNT      REG(u32, 0x04000104)
#define REG_TM1CNT_L    REG(u16, 0x04000104)
#define REG_TM1CNT_H    REG(u16, 0x04000106)
#define REG_TM2CNT      REG(u32, 0x04000108)
#define REG_TM2CNT_L    REG(u16, 0x04000108)
#define REG_TM2CNT_H    REG(u16, 0x0400010A)
#define REG_TM3CNT      REG(u32, 0x0400010C)
#define REG_TM3CNT_L    REG(u16, 0x0400010C)
#define REG_TM3CNT_H    REG(u16, 0x0400010E)

#define REG_SIOCNT      REG(u16, 0x04000128)
#define REG_SIODATA8    REG(u16, 0x0400012A)
#define REG_SIODATA32   REG(u32, 0x04000120)
#define REG_SIOMLT_SEND REG(u16, 0x0400012A)
#define REG_SIOMLT_RECV REG(u64, 0x04000120)
#define REG_SIOMULTI0   REG(u16, 0x04000120)
#define REG_SIOMULTI1   REG(u16, 0x04000122)
#define REG_SIOMULTI2   REG(u16, 0x04000124)
#define REG_SIOMULTI3   REG(u16, 0x04000126)

#define REG_KEYINPUT    REG(u16, 0x04000130)
#define REG_KEYCNT      REG(u16, 0x04000132)

#define REG_RCNT        REG(u16, 0x04000134)

#define REG_IE          REG(u16, 0x04000200)
#define REG_IF          REG(u16, 0x04000202)
#define REG_IME         REG(u16, 0x04000208)

#define REG_WAITCNT     REG(u16, 0x04000204)

// DISPCNT

enum
{
    BG_MODE_REGULAR        = 0,
    BG_MODE_MIXED          = 1,
    BG_MODE_AFFINE         = 2,
    BG_MODE_BITMAP         = 3,
    BG_MODE_BITMAP_INDEXED = 4,
    BG_MODE_BITMAP_SMALL   = 5,
};

enum
{
    OBJ_MAPPING_2D = 0,
    OBJ_MAPPING_1D = 1,
};

enum
{
    #define DISPCNT_BG_MODE(n) (((n) & 7) << 0)
    #define DISPCNT_BITMAP_FRAME(n) (((n) & 1) << 4)
    #define DISPCNT_OBJ_MAPPING(n) (((n) & 1) << 6)

    DISPCNT_BG_MODE_REGULAR        = DISPCNT_BG_MODE(BG_MODE_REGULAR),
    DISPCNT_BG_MODE_MIXED          = DISPCNT_BG_MODE(BG_MODE_MIXED),
    DISPCNT_BG_MODE_AFFINE         = DISPCNT_BG_MODE(BG_MODE_AFFINE),
    DISPCNT_BG_MODE_BITMAP         = DISPCNT_BG_MODE(BG_MODE_BITMAP),
    DISPCNT_BG_MODE_BITMAP_INDEXED = DISPCNT_BG_MODE(BG_MODE_BITMAP_INDEXED),
    DISPCNT_BG_MODE_BITMAP_SMALL   = DISPCNT_BG_MODE(BG_MODE_BITMAP_SMALL),
    DISPCNT_BITMAP_FRAME_0         = DISPCNT_BITMAP_FRAME(0),
    DISPCNT_BITMAP_FRAME_1         = DISPCNT_BITMAP_FRAME(1),
    DISPCNT_HBLANK_INTERVAL_FREE   = 1 << 5,
    DISPCNT_OBJ_MAPPING_2D         = DISPCNT_OBJ_MAPPING(OBJ_MAPPING_2D),
    DISPCNT_OBJ_MAPPING_1D         = DISPCNT_OBJ_MAPPING(OBJ_MAPPING_1D),
    DISPCNT_FORCE_BLANK            = 1 << 7,
    DISPCNT_BG0_ENABLE             = 1 << 8,
    DISPCNT_BG1_ENABLE             = 1 << 9,
    DISPCNT_BG2_ENABLE             = 1 << 10,
    DISPCNT_BG3_ENABLE             = 1 << 11,
    DISPCNT_OBJ_ENABLE             = 1 << 12,
    DISPCNT_WIN0_ENABLE            = 1 << 13,
    DISPCNT_WIN1_ENABLE            = 1 << 14,
    DISPCNT_OBJWIN_ENABLE          = 1 << 15,
};

// DISPSTAT

enum
{
    #define DISPSTAT_VCOUNT_COMPARE(n) (((n) & 0xFF) << 8)

    DISPSTAT_VBLANK            = 1 << 0,
    DISPSTAT_HBLANK            = 1 << 1,
    DISPSTAT_VCOUNT            = 1 << 2,
    DISPSTAT_VBLANK_INT_ENABLE = 1 << 3,
    DISPSTAT_HBLANK_INT_ENABLE = 1 << 4,
    DISPSTAT_VCOUNT_INT_ENABLE = 1 << 5,
};

// BGCNT

enum
{
    BG_COLORDEPTH_4BPP = 0,
    BG_COLORDEPTH_8BPP = 1,
};

enum
{
    BG_SIZE_256x256 = 0,
    BG_SIZE_512x256 = 1,
    BG_SIZE_256x512 = 2,
    BG_SIZE_512x512 = 3,
};

enum
{
    BG_AFFINE_SIZE_128x128   = 0,
    BG_AFFINE_SIZE_256x256   = 1,
    BG_AFFINE_SIZE_512x512   = 2,
    BG_AFFINE_SIZE_1024x1024 = 3,
};

enum
{
    #define BGCNT_PRIORITY(n)    (((n) & 3)  << 0) // Values 0 - 3. Lower priority BGs will be drawn on top of higher priority BGs.
    #define BGCNT_CHR_BLOCK(n)   (((n) & 3)  << 2) // Values 0 - 3. Base block for tile pixel data.
    #define BGCNT_COLORDEPTH(n)  (((n) & 1)  << 7) // 4 or 8 bits per pixel
    #define BGCNT_TM_BLOCK(n)    (((n) & 31) << 8) // Values 0 - 31. Base block for tile map.
    #define BGCNT_SIZE(n)        (((n) & 3) << 14) // Internal screen size size of text mode BG.
    #define BGCNT_AFFINE_SIZE(n) (((n) & 3) << 14) // Internal screen size size of affine mode BG.

    BGCNT_MOSAIC                = 1 << 6,
    BGCNT_COLORDEPTH_4BPP       = BGCNT_COLORDEPTH(BG_COLORDEPTH_4BPP),
    BGCNT_COLORDEPTH_8BPP       = BGCNT_COLORDEPTH(BG_COLORDEPTH_8BPP),
    BGCNT_WRAP                  = 1 << 13,
    BGCNT_SIZE_256x256          = BGCNT_SIZE(BG_SIZE_256x256),
    BGCNT_SIZE_512x256          = BGCNT_SIZE(BG_SIZE_512x256),
    BGCNT_SIZE_256x512          = BGCNT_SIZE(BG_SIZE_256x512),
    BGCNT_SIZE_512x512          = BGCNT_SIZE(BG_SIZE_512x512),
    BGCNT_AFFINE_SIZE_128x128   = BGCNT_AFFINE_SIZE(BG_AFFINE_SIZE_128x128),
    BGCNT_AFFINE_SIZE_256x256   = BGCNT_AFFINE_SIZE(BG_AFFINE_SIZE_256x256),
    BGCNT_AFFINE_SIZE_512x512   = BGCNT_AFFINE_SIZE(BG_AFFINE_SIZE_512x512),
    BGCNT_AFFINE_SIZE_1024x1024 = BGCNT_AFFINE_SIZE(BG_AFFINE_SIZE_1024x1024),
};

// BLDCNT

enum
{
    BLEND_EFFECT_NONE = 0,
    BLEND_EFFECT_ALPHA = 1,
    BLEND_EFFECT_BRIGHTEN = 2,
    BLEND_EFFECT_DARKEN = 3,
};

enum
{
    #define BLDCNT_TARGETA(bg0, bg1, bg2, bg3, obj) ((bg0) + ((bg1) << 1) + ((bg2) << 2) + ((bg3) << 3) + ((obj) << 4))
    #define BLDCNT_TARGETB(bg0, bg1, bg2, bg3, obj) (((bg0) << 8) + ((bg1) << 9) + ((bg2) << 10) + ((bg3) << 11) + ((obj) << 12))
    #define BLDCNT_EFFECT(n) (((n) & 3) << 6)

    BLDCNT_TARGETA_BG0    = 1 << 0,
    BLDCNT_TARGETA_BG1    = 1 << 1,
    BLDCNT_TARGETA_BG2    = 1 << 2,
    BLDCNT_TARGETA_BG3    = 1 << 3,
    BLDCNT_TARGETA_OBJ    = 1 << 4,
    BLDCNT_TARGETA_BD     = 1 << 5,
    BLDCNT_EFFECT_NONE    = BLDCNT_EFFECT(BLEND_EFFECT_NONE),
    BLDCNT_EFFECT_ALPHA   = BLDCNT_EFFECT(BLEND_EFFECT_ALPHA),
    BLDCNT_EFFECT_LIGHTEN = BLDCNT_EFFECT(BLEND_EFFECT_BRIGHTEN),
    BLDCNT_EFFECT_DARKEN  = BLDCNT_EFFECT(BLEND_EFFECT_DARKEN),
    BLDCNT_TARGETB_BG0    = 1 << 8,
    BLDCNT_TARGETB_BG1    = 1 << 9,
    BLDCNT_TARGETB_BG2    = 1 << 10,
    BLDCNT_TARGETB_BG3    = 1 << 11,
    BLDCNT_TARGETB_OBJ    = 1 << 12,
    BLDCNT_TARGETB_BD     = 1 << 13,
};

// BLDALPHA

#define BLDALPHA_BLEND(ca, cb) (((cb) << 8) | (ca))

// SOUNDCNT_H

enum
{
    SOUND_CGB_MIX_QUARTER = 0x0000,
    SOUND_CGB_MIX_HALF    = 0x0001,
    SOUND_CGB_MIX_FULL    = 0x0002,
    SOUND_A_MIX_HALF      = 0x0000,
    SOUND_A_MIX_FULL      = 0x0004,
    SOUND_B_MIX_HALF      = 0x0000,
    SOUND_B_MIX_FULL      = 0x0008,
    SOUND_ALL_MIX_FULL    = 0x000E,
    SOUND_A_RIGHT_OUTPUT  = 0x0100,
    SOUND_A_LEFT_OUTPUT   = 0x0200,
    SOUND_A_TIMER_0       = 0x0000,
    SOUND_A_TIMER_1       = 0x0400,
    SOUND_A_FIFO_RESET    = 0x0800,
    SOUND_B_RIGHT_OUTPUT  = 0x1000,
    SOUND_B_LEFT_OUTPUT   = 0x2000,
    SOUND_B_TIMER_0       = 0x0000,
    SOUND_B_TIMER_1       = 0x4000,
    SOUND_B_FIFO_RESET    = 0x8000,
};

// SOUNDCNT_X

enum
{
    SOUND_1_ON          = 0x0001,
    SOUND_2_ON          = 0x0002,
    SOUND_3_ON          = 0x0004,
    SOUND_4_ON          = 0x0008,
    SOUND_MASTER_ENABLE = 0x0080,
};

// DMA
#define DMA_DEST_INC      0x0000
#define DMA_DEST_DEC      0x0020
#define DMA_DEST_FIXED    0x0040
#define DMA_DEST_RELOAD   0x0060
#define DMA_SRC_INC       0x0000
#define DMA_SRC_DEC       0x0080
#define DMA_SRC_FIXED     0x0100
#define DMA_REPEAT        0x0200
#define DMA_16BIT         0x0000
#define DMA_32BIT         0x0400
#define DMA_DREQ_ON       0x0800
#define DMA_START_NOW     0x0000
#define DMA_START_VBLANK  0x1000
#define DMA_START_HBLANK  0x2000
#define DMA_START_SPECIAL 0x3000
#define DMA_START_MASK    0x3000
#define DMA_INTR_ENABLE   0x4000
#define DMA_ENABLE        0x8000

// timer
#define TIMER_1CLK        0x00
#define TIMER_64CLK       0x01
#define TIMER_256CLK      0x02
#define TIMER_1024CLK     0x03
#define TIMER_INTR_ENABLE 0x40
#define TIMER_ENABLE      0x80

// serial
#define SIO_ID             0x0030 // Communication ID

#define SIO_8BIT_MODE      0x0000 // Normal 8-bit communication mode
#define SIO_32BIT_MODE     0x1000 // Normal 32-bit communication mode
#define SIO_MULTI_MODE     0x2000 // Multi-player communication mode
#define SIO_UART_MODE      0x3000 // UART communication mode

#define SIO_9600_BPS       0x0000 // baud rate   9600 bps
#define SIO_38400_BPS      0x0001 //            38400 bps
#define SIO_57600_BPS      0x0002 //            57600 bps
#define SIO_115200_BPS     0x0003 //           115200 bps

#define SIO_MULTI_SI       0x0004 // Multi-player communication SI terminal
#define SIO_MULTI_SD       0x0008 //                            SD terminal
#define SIO_MULTI_BUSY     0x0080

#define SIO_ERROR          0x0040 // Detect error
#define SIO_START          0x0080 // Start transfer
#define SIO_ENABLE         0x0080 // Enable SIO

#define SIO_INTR_ENABLE    0x4000

#define SIO_MULTI_SI_SHIFT 2
#define SIO_MULTI_SI_MASK  0x1
#define SIO_MULTI_DI_SHIFT 3
#define SIO_MULTI_DI_MASK  0x1

enum
{
    KEY_BUTTON_A      = (1 << 0),
    KEY_BUTTON_B      = (1 << 1),
    KEY_BUTTON_SELECT = (1 << 2),
    KEY_BUTTON_START  = (1 << 3),
    KEY_DPAD_RIGHT    = (1 << 4),
    KEY_DPAD_LEFT     = (1 << 5),
    KEY_DPAD_UP       = (1 << 6),
    KEY_DPAD_DOWN     = (1 << 7),
    KEY_BUTTON_R      = (1 << 8),
    KEY_BUTTON_L      = (1 << 9),

    KEY_ANY           = (1 << 10) - 1,
    KEY_DPAD_ANY      = KEY_DPAD_RIGHT + KEY_DPAD_LEFT + KEY_DPAD_UP + KEY_DPAD_DOWN,
    KEY_BUTTON_ANY    = KEY_ANY &~ KEY_DPAD_ANY,
};

#define KEY_INTR_ENABLE 0x0400
#define KEY_OR_INTR     0x0000
#define KEY_AND_INTR    0x8000

// interrupt flags
#define INTR_FLAG_VBLANK  (1 <<  0)
#define INTR_FLAG_HBLANK  (1 <<  1)
#define INTR_FLAG_VCOUNT  (1 <<  2)
#define INTR_FLAG_TIMER0  (1 <<  3)
#define INTR_FLAG_TIMER1  (1 <<  4)
#define INTR_FLAG_TIMER2  (1 <<  5)
#define INTR_FLAG_TIMER3  (1 <<  6)
#define INTR_FLAG_SERIAL  (1 <<  7)
#define INTR_FLAG_DMA0    (1 <<  8)
#define INTR_FLAG_DMA1    (1 <<  9)
#define INTR_FLAG_DMA2    (1 << 10)
#define INTR_FLAG_DMA3    (1 << 11)
#define INTR_FLAG_KEYPAD  (1 << 12)
#define INTR_FLAG_GAMEPAK (1 << 13)

// WAITCNT
#define WAITCNT_SRAM_4          (0 << 0)
#define WAITCNT_SRAM_3          (1 << 0)
#define WAITCNT_SRAM_2          (2 << 0)
#define WAITCNT_SRAM_8          (3 << 0)
#define WAITCNT_SRAM_MASK       (3 << 0)

#define WAITCNT_WS0_N_4         (0 << 2)
#define WAITCNT_WS0_N_3         (1 << 2)
#define WAITCNT_WS0_N_2         (2 << 2)
#define WAITCNT_WS0_N_8         (3 << 2)
#define WAITCNT_WS0_N_MASK      (3 << 2)

#define WAITCNT_WS0_S_2         (0 << 4)
#define WAITCNT_WS0_S_1         (1 << 4)

#define WAITCNT_WS1_N_4         (0 << 5)
#define WAITCNT_WS1_N_3         (1 << 5)
#define WAITCNT_WS1_N_2         (2 << 5)
#define WAITCNT_WS1_N_8         (3 << 5)
#define WAITCNT_WS1_N_MASK      (3 << 5)

#define WAITCNT_WS1_S_4         (0 << 7)
#define WAITCNT_WS1_S_1         (1 << 7)

#define WAITCNT_WS2_N_4         (0 << 8)
#define WAITCNT_WS2_N_3         (1 << 8)
#define WAITCNT_WS2_N_2         (2 << 8)
#define WAITCNT_WS2_N_8         (3 << 8)
#define WAITCNT_WS2_N_MASK      (3 << 8)

#define WAITCNT_WS2_S_8         (0 << 10)
#define WAITCNT_WS2_S_1         (1 << 10)

#define WAITCNT_PHI_OUT_NONE    (0 << 11)
#define WAITCNT_PHI_OUT_4MHZ    (1 << 11)
#define WAITCNT_PHI_OUT_8MHZ    (2 << 11)
#define WAITCNT_PHI_OUT_16MHZ   (3 << 11)
#define WAITCNT_PHI_OUT_MASK    (3 << 11)

#define WAITCNT_PREFETCH_ENABLE (1 << 14)

#define WAITCNT_AGB (0 << 15)
#define WAITCNT_CGB (1 << 15)
