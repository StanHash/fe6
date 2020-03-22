
#include "debug-text.h"

#include <stdarg.h>

#include "hardware.h"
#include "move.h"
#include "ramfunc.h"

#include "constants/video-global.h"

extern u16 CONST_DATA gSprite_8x8[];

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

struct DebugTextSt EWRAM_DATA gDebugTextSt = {};
char EWRAM_DATA gNumberStr[9] = {};
int EWRAM_DATA gUnknown_02028E50 = 0;
int EWRAM_DATA gUnknown_02028E54 = 0;

void DebugInitBg(int bg, int vramOffset)
{
    if (vramOffset == 0)
        vramOffset = BGCHR_DEBUGTEXT_DEFAULT * CHR_SIZE;

    SetBgChrOffset(bg, 0);
    SetBgScreenSize(bg, 0);

    RegisterVramMove(Img_DebugFont, vramOffset, 0x40 * CHR_SIZE);

    PAL_BG_COLOR(0, 0) = RGB(0, 0, 0);
    PAL_BG_COLOR(0, 2) = RGB(31, 31, 31);

    EnablePalSync();

    FillTm(GetBgTilemap(bg), 0);

    gDebugTextSt.bg = bg;
    gDebugTextSt.vramOffset = vramOffset;
    gDebugTextSt.chr = GetBgChrId(bg, vramOffset);
}

void DebugPutStr(u16* tm, char const* str)
{
    while (*str)
    {
        *tm = *str > '`'
            ? *str - '`' + (gDebugTextSt.chr + 0x20)
            : *str - ' ' + (gDebugTextSt.chr);

        tm++;
        str++;
    }

    EnableBgSyncById(gDebugTextSt.bg);
}

void DebugPutFmt(u16* tm, char const* fmt, ...)
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
        gDebugTextSt.screen[i & 0xFF][0] = '\0';

    gDebugTextSt.hcur = 0;
    gDebugTextSt.vcur = 0;

    FillTm(gBg2Tm, 0);
    EnableBgSync(BG2_SYNC_BIT);
}

void DebugPrintFmt(char const* fmt, ...)
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
    u32* ptr = (u32*) gNumberStr;

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

void DebugPrintStr(char const* str)
{
    while (*str)
    {
        char chr = *str;

        if (gDebugTextSt.hcur == 0x30)
            chr = 0;
        else
            str++;

        if (chr == '\n')
            chr = 0;

        gDebugTextSt.screen[gDebugTextSt.vcur & 0xFF][gDebugTextSt.hcur] = chr;
        gDebugTextSt.hcur++;

        if (chr == 0)
        {
            gDebugTextSt.hcur = 0;
            gDebugTextSt.vcur++;
        }
    }

    if (gDebugTextSt.vcur > gDebugTextSt.vdisp + 20)
        gDebugTextSt.vdisp = gDebugTextSt.vcur - 20;
}

void DebugPutScreen(void)
{
    u16* tm;
    u16 chr;
    int ih, iv;

    FillTm(gBg2Tm, 0);

    for (iv = 0; iv < 20; iv++)
    {
        tm = gBg2Tm + TM_OFFSET(0, iv);

        for (ih = 0; gDebugTextSt.screen[(iv + gDebugTextSt.vdisp) & 0xFF][ih]; ++tm, ++ih)
        {
            chr = gDebugTextSt.screen[(iv + gDebugTextSt.vdisp) & 0xFF][ih];

            if (chr > '`')
                chr = chr - 0x40;
            else
                chr = chr - 0x20;

            *tm = chr + gDebugTextSt.chr;
        }
    }

    EnableBgSync(BG2_SYNC_BIT);
}

s8 DebugUpdateScreen(u16 held, u16 pressed)
{
    int top, bottom;

    if (pressed & B_BUTTON)
        return FALSE;

    DebugPutScreen();

    top = gDebugTextSt.vcur - 256;

    if (top < 0)
        top = 0;

    bottom = gDebugTextSt.vcur - 20;

    if (bottom < 0)
        bottom = 0;

    if ((held & DPAD_UP) && top < gDebugTextSt.vdisp)
        gDebugTextSt.vdisp--;

    if ((held & DPAD_DOWN) && bottom > gDebugTextSt.vdisp)
        gDebugTextSt.vdisp++;

    return TRUE;
}

void DebugInitObj(int offset, int palid)
{
    if (offset < 0)
        offset = OBJCHR_DEBUGTEXT_DEFAULT * CHR_SIZE;

    offset &= 0xFFFF;

    gUnknown_02028E50 = offset / CHR_SIZE;
    gUnknown_02028E54 = (palid & 0xF) * 0x1000;

    RegisterVramMove(Img_DebugFont, 0x10000 + offset, 0x40 * CHR_SIZE);

    PAL_OBJ_COLOR(palid, 0) = RGB(0, 0, 0);
    PAL_OBJ_COLOR(palid, 1) = RGB(0, 0, 31);
    PAL_OBJ_COLOR(palid, 2) = RGB(31, 31, 31);

    EnablePalSync();
}

void DebugPutObjStr(int x, int y, char const* str)
{
    while (*str)
    {
        char chr = *str > 0x60
            ? *str - 0x40
            : *str - 0x20;

        PutOamHiRam(x, y, gSprite_8x8, chr + gUnknown_02028E50 + gUnknown_02028E54);

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
