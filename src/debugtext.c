#include "debugtext.h"

#include <stdarg.h>

#include "hardware.h"
#include "move.h"
#include "oam.h"
#include "armfunc.h"
#include "sprite.h"

#include "constants/videoalloc_global.h"

extern u8 CONST_DATA Img_DebugFont[];

struct DebugTextSt
{
    /* 00 */ int vramOffset;
    /* 04 */ short bg;
    /* 06 */ u16 chr;

    /* 08 */ int hcur;
    /* 0C */ u32 vcur;
    /* 10 */ u32 vdisp;

    /* 14 */ char screen[256][32];
};

static struct DebugTextSt EWRAM_DATA sDebugTextSt = {};

char EWRAM_DATA gNumberStr[9] = {};

static int EWRAM_DATA sDebugOam2Chr = 0;
static int EWRAM_DATA sDebugOam2Pal = 0;

void DebugInitBg(int bg, int vramOffset)
{
    if (vramOffset == 0)
        vramOffset = BGCHR_DEBUGTEXT_DEFAULT * CHR_SIZE;

    SetBgChrOffset(bg, 0);
    SetBgScreenSize(bg, BG_SIZE_256x256);

    RegisterVramMove(Img_DebugFont, vramOffset, 0x40 * CHR_SIZE);

    PAL_BG_COLOR(0, 0) = RGB(0, 0, 0);
    PAL_BG_COLOR(0, 2) = RGB(31, 31, 31);

    EnablePalSync();

    TmFill(GetBgTilemap(bg), 0);

    sDebugTextSt.bg = bg;
    sDebugTextSt.vramOffset = vramOffset;
    sDebugTextSt.chr = GetBgChrId(bg, vramOffset);
}

void DebugPutStr(u16 * tm, char const * str)
{
    while (*str)
    {
        *tm = *str > '`'
            ? *str - '`' + (sDebugTextSt.chr + 0x20)
            : *str - ' ' + (sDebugTextSt.chr);

        tm++;
        str++;
    }

    EnableBgSyncById(sDebugTextSt.bg);
}

void DebugPutFmt(u16 * tm, char const * fmt, ...)
{
    char buffer[0x100];
    va_list args;

    va_start(args, fmt);
    // vsprintf(buffer, fmt, args);
    va_end(args);

    DebugPutStr(tm, buffer);
}

void DebugScreenInit(void)
{
    int i;

    for (i = 0; i < 0x100; i++)
        sDebugTextSt.screen[i & 0xFF][0] = '\0';

    sDebugTextSt.hcur = 0;
    sDebugTextSt.vcur = 0;

    TmFill(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);
}

void DebugPrintFmt(char const * fmt, ...)
{
    char buffer[0x100];
    va_list args;

    va_start(args, fmt);
    // vsprintf(buffer, fmt, args);
    va_end(args);

    DebugPrintStr(buffer);
}

static void ClearNumberStr(void)
{
    u32 * ptr = (u32 *) gNumberStr;

    *ptr++ = 0x20202020; // '    '
    *ptr   = 0x20202020; // '    '

    gNumberStr[8] = 0;
}

void GenNumberStr(int number)
{
    int i;

    ClearNumberStr();

    for (i = 7; i >= 0; i--)
    {
        gNumberStr[i] = '0' + number % 10;

        number /= 10;

        if (number == 0)
            break;
    }
}

void GenNumberOrBlankStr(int number)
{
    ClearNumberStr();

    if (number == 255 || number == -1)
    {
        gNumberStr[6] = gNumberStr[7] = ':';
    }
    else
    {
        GenNumberStr(number);
    }
}

void DebugPrintNumber(int number, int length)
{
    GenNumberStr(number);
    DebugPrintStr(gNumberStr + 8 - length);
}

void GenNumberHexStr(int number)
{
    static char const hexLut[] = "0123456789ABCDEF";

    int i;

    ClearNumberStr();

    for (i = 7; i >= 0; i--)
    {
        gNumberStr[i] = hexLut[number & 0xF];

        number >>= 4;

        if (number == 0)
            break;
    }
}

void DebugPrintNumberHex(int number, int length)
{
    GenNumberHexStr(number);
    DebugPrintStr(gNumberStr + 8 - length);
}

void DebugPrintStr(char const * str)
{
    while (*str)
    {
        char chr = *str;

        if (sDebugTextSt.hcur == 0x30)
            chr = 0;
        else
            str++;

        if (chr == '\n')
            chr = 0;

        sDebugTextSt.screen[sDebugTextSt.vcur & 0xFF][sDebugTextSt.hcur] = chr;
        sDebugTextSt.hcur++;

        if (chr == 0)
        {
            sDebugTextSt.hcur = 0;
            sDebugTextSt.vcur++;
        }
    }

    if (sDebugTextSt.vcur > sDebugTextSt.vdisp + 20)
        sDebugTextSt.vdisp = sDebugTextSt.vcur - 20;
}

void DebugPutScreen(void)
{
    u16 * tm;
    u16 chr;
    int ih, iv;

    TmFill(gBg2Tm, 0);

    for (iv = 0; iv < 20; iv++)
    {
        tm = gBg2Tm + TM_OFFSET(0, iv);

        for (ih = 0; sDebugTextSt.screen[(iv + sDebugTextSt.vdisp) & 0xFF][ih]; ++tm, ++ih)
        {
            chr = sDebugTextSt.screen[(iv + sDebugTextSt.vdisp) & 0xFF][ih];

            if (chr > '`')
                chr = chr - 0x40;
            else
                chr = chr - 0x20;

            *tm = chr + sDebugTextSt.chr;
        }
    }

    EnableBgSync(BG2_SYNC_BIT);
}

bool DebugUpdateScreen(u16 held, u16 pressed)
{
    int top, bottom;

    if (pressed & KEY_BUTTON_B)
        return FALSE;

    DebugPutScreen();

    top = sDebugTextSt.vcur - 256;

    if (top < 0)
        top = 0;

    bottom = sDebugTextSt.vcur - 20;

    if (bottom < 0)
        bottom = 0;

    if ((held & KEY_DPAD_UP) && top < sDebugTextSt.vdisp)
        sDebugTextSt.vdisp--;

    if ((held & KEY_DPAD_DOWN) && bottom > sDebugTextSt.vdisp)
        sDebugTextSt.vdisp++;

    return TRUE;
}

void DebugInitObj(int offset, int palid)
{
    if (offset < 0)
        offset = OBJCHR_DEBUGTEXT_DEFAULT * CHR_SIZE;

    offset &= 0xFFFF;

    sDebugOam2Chr = offset / CHR_SIZE;
    sDebugOam2Pal = OAM2_PAL(palid);

    RegisterVramMove(Img_DebugFont, 0x10000 + offset, 0x40 * CHR_SIZE);

    PAL_OBJ_COLOR(palid, 0) = RGB(0, 0, 0);
    PAL_OBJ_COLOR(palid, 1) = RGB(0, 0, 31);
    PAL_OBJ_COLOR(palid, 2) = RGB(31, 31, 31);

    EnablePalSync();
}

void DebugPutObjStr(int x, int y, char const * str)
{
    while (*str)
    {
        char chr = *str > 0x60
            ? *str - 0x40
            : *str - 0x20;

        PutOamHi(x, y, Sprite_8x8, chr + sDebugOam2Chr + sDebugOam2Pal);

        x += 8;
        str++;
    }
}

void DebugPutObjNumber(int x, int y, int number, int length)
{
    GenNumberStr(number);
    DebugPutObjStr(x, y, gNumberStr + 8 - length);
}

void DebugPutObjNumberHex(int x, int y, int number, int length)
{
    GenNumberHexStr(number);
    DebugPutObjStr(x, y, gNumberStr + 8 - length);
}
