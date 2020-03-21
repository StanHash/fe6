
#include "icon.h"

#include "hardware.h"
#include "move.h"

#include "constants/video-global.h"

enum { MAX_ICON_COUNT = 160 };
enum { MAX_ICON_DISPLAY_COUNT = 0x20 };

struct IconSt
{
    /* 00 */ u8 refCount;
    /* 01 */ u8 dispId;
};

extern u8 const gIconImg[];
extern u16 const gIconPal[];

static struct IconSt EWRAM_DATA sIconStTable[MAX_ICON_COUNT] = {};
static u8 EWRAM_DATA sIconDisplayList[MAX_ICON_DISPLAY_COUNT] = {};

void InitIcons(void)
{
    ClearIcons();
}

void ClearIcons(void)
{
    CpuFill16(0, &sIconStTable, sizeof sIconStTable);
    CpuFill16(0, &sIconDisplayList, sizeof sIconDisplayList);
}

void ApplyIconPalettes(int palid)
{
    ApplyPalettes(gIconPal, palid, 2);
}

void ApplyIconPalette(int num, int palid)
{
    ApplyPalette(gIconPal + 0x10 * num, palid);
}

static int CountActiveIcons(void)
{ 
    int i, result = 0;

    for (i = MAX_ICON_DISPLAY_COUNT - 1; i >= 0; i--)
    {
        if (sIconDisplayList[i] != 0)
            result++;
    }

    return result;
}

static u16 IconSlot2Chr(int num)
{
    return BGCHR_ICON_END - num * 4;
}

static int GetNewIconSlot(int icon)
{
    int i;

    for (i = 0; i < MAX_ICON_DISPLAY_COUNT; ++i)
    {
        if (sIconDisplayList[i] == 0)
        {
            sIconDisplayList[i] = icon + 1;
            return i;
        }
    }

    return -1;
}

static int GetIconChr(int icon)
{
    if (sIconStTable[icon].dispId != 0)
    {
        if (sIconStTable[icon].refCount < UINT8_MAX)
            sIconStTable[icon].refCount++;

        return IconSlot2Chr(sIconStTable[icon].dispId);
    }

    sIconStTable[icon].refCount++;
    sIconStTable[icon].dispId = GetNewIconSlot(icon) + 1;

    RegisterBgVramMove(
        gIconImg + (icon * 0x80),
        VRAM + 0x20 * IconSlot2Chr(sIconStTable[icon].dispId), 0x80);

    return IconSlot2Chr(sIconStTable[icon].dispId);
}

void PutIcon(u16* tm, int icon, int tileref)
{
    if (icon < 0)
    {
        tm[0x00] = 0;
        tm[0x01] = 0;
        tm[0x20] = 0;
        tm[0x21] = 0;
    }
    else
    {
        u16 tile = GetIconChr(icon) + tileref;

        tm[0x00] = tile++;
        tm[0x01] = tile++;
        tm[0x20] = tile++;
        tm[0x21] = tile;
    }
}

void ClearIcon(int icon)
{
    sIconDisplayList[sIconStTable[icon].dispId - 1] = 0;
    sIconStTable[icon].dispId = 0;
}

void PutIconObjImg(int icon, int chr)
{
    u8 const* src;
    u8* dst;

    dst = OBJ_VRAM0;
    dst += 0x20 * (chr & 0x3FF);

    if (icon < 0)
    {
        RegisterDataFill(0, dst,         0x40);
        RegisterDataFill(0, dst + 0x400, 0x40);
    }
    else
    {
        src = gIconImg;
        src += 0x80 * icon;

        RegisterDataMove(src,        dst,         0x40);
        RegisterDataMove(src + 0x40, dst + 0x400, 0x40);
    }
}
