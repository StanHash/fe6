#include "icon.h"

#include "hardware.h"
#include "move.h"

#include "constants/videoalloc_global.h"

enum { MAX_ICON_COUNT = 160 };
enum { MAX_ICON_DISPLAY_COUNT = 0x20 };

struct IconSt
{
    /* 00 */ u8 ref_count;
    /* 01 */ u8 disp_id;
};

extern u8 const Img_Icons[];
extern u16 const Pal_Icons[];

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
    ApplyPalettes(Pal_Icons, palid, 2);
}

void ApplyIconPalette(int num, int palid)
{
    ApplyPalette(Pal_Icons + 0x10 * num, palid);
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
    if (sIconStTable[icon].disp_id != 0)
    {
        if (sIconStTable[icon].ref_count < UINT8_MAX)
            sIconStTable[icon].ref_count++;

        return IconSlot2Chr(sIconStTable[icon].disp_id);
    }

    sIconStTable[icon].ref_count++;
    sIconStTable[icon].disp_id = GetNewIconSlot(icon) + 1;

    RegisterVramMove(
        Img_Icons + (icon * CHR_SIZE * 4),
        VRAM + CHR_SIZE * IconSlot2Chr(sIconStTable[icon].disp_id), CHR_SIZE * 4);

    return IconSlot2Chr(sIconStTable[icon].disp_id);
}

void PutIcon(u16 * tm, int icon, int tileref)
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
    sIconDisplayList[sIconStTable[icon].disp_id - 1] = 0;
    sIconStTable[icon].disp_id = 0;
}

void PutIconObjImg(int icon, int chr)
{
    u8 const * src;
    u8 * dst;

    dst = OBJ_VRAM0;
    dst += CHR_SIZE * (chr & 0x3FF);

    if (icon < 0)
    {
        RegisterDataFill(0, dst,         CHR_SIZE * 2);
        RegisterDataFill(0, dst + 0x400, CHR_SIZE * 2);
    }
    else
    {
        src = Img_Icons;
        src += CHR_SIZE * 4 * icon;

        RegisterDataMove(src,                dst,         CHR_SIZE * 2);
        RegisterDataMove(src + CHR_SIZE * 2, dst + 0x400, CHR_SIZE * 2);
    }
}
