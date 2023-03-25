
#include "common.h"
#include "text.h"

#include "hardware.h"
#include "ramfunc.h"
#include "proc.h"

#include "constants/videoalloc_global.h"

struct SpecialCharSt
{
    i8 color;
    i8 id;
    i16 chr_position;
};

struct TextPrintProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ struct Text * text;
    /* 30 */ char const * str;
    /* 34 */ i8 interval;
    /* 35 */ i8 clock;
    /* 36 */ i8 char_per_tick;
};

static u8 * GetTextDrawDest(struct Text * text);
static u16 const * GetColorLut(int color);
static void DrawTextGlyph(struct Text * text, struct Glyph const * glyph);
static void DrawTextGlyphNoClear(struct Text * text, struct Glyph const * glyph);
static void Text_DrawStringAscii(struct Text * text, char const * str);
static char const * Text_DrawCharacterAscii(struct Text * text, char const * str);
static int GetStringTextLenAscii(char const * str);
static u8 * GetSpriteTextDrawDest(struct Text * text);
static void DrawSpriteTextGlyph(struct Text * text, struct Glyph const * glyph);
static void TextPrint_OnLoop(struct TextPrintProc * proc);
static void GreenText_OnLoop(ProcPtr proc);
static void DrawSpecialCharGlyph(int chr_position, int color, struct Glyph const * glyph);
static int AddSpecialChar(struct SpecialCharSt * st, int color, int id);
static int GetSpecialCharChr(int color, int id);

extern u16 CONST_DATA TextColorLut_0123[];
extern u16 CONST_DATA TextColorLut_0456[];
extern u16 CONST_DATA TextColorLut_0789[];
extern u16 CONST_DATA TextColorLut_0ABC[];
extern u16 CONST_DATA TextColorLut_0DEF[];
extern u16 CONST_DATA TextColorLut_0030[];
extern u16 CONST_DATA TextColorLut_4DEF[];
extern u16 CONST_DATA TextColorLut_456F[];
extern u16 CONST_DATA TextColorLut_47CF[];
extern u16 CONST_DATA TextColorLut_InverseMask[];

struct Font EWRAM_DATA gDefaultFont = {};
struct Font * EWRAM_DATA gActiveFont = 0;

static struct SpecialCharSt EWRAM_DATA sSpecialCharStList[0x40] = {};

static u16 const * CONST_DATA s2bppTo4bppLutTable[] =
{
    TextColorLut_0123,
    TextColorLut_0456,
    TextColorLut_0789,
    TextColorLut_0ABC,
    TextColorLut_0DEF,
    TextColorLut_0030,
    TextColorLut_4DEF,
    TextColorLut_456F,
    TextColorLut_47CF,
    TextColorLut_InverseMask,
};

struct ProcScr CONST_DATA ProcScr_TextPrint[] =
{
    PROC_REPEAT(TextPrint_OnLoop),
    PROC_END,
};

struct ProcScr ProcScr_GreenTextColor[] =
{
    PROC_END_IF_DUP,
    PROC_REPEAT(GreenText_OnLoop),
    PROC_END,
};

int GetLang(void)
{
    return LANG_JAPANESE;
}

void ResetText(void)
{
    InitTextFont(&gDefaultFont,
        (u8 *)(VRAM + BGCHR_TEXT_DEFAULT * CHR_SIZE),
        BGCHR_TEXT_DEFAULT, BGPAL_TEXT_DEFAULT);

    sSpecialCharStList[0].color = -1;
}

void InitTextFont(struct Font * font, void * draw_dest, int chr, int palid)
{
    if (font == NULL)
        font = &gDefaultFont;

    font->draw_dest = draw_dest;
    font->get_draw_dest = GetTextDrawDest;
    font->palid = palid;
    font->tileref = TILEREF(chr, palid);
    font->chr_counter = 0;
    font->lang = GetLang();

    SetTextFont(font);
    InitSystemTextFont();
}

void SetTextFontGlyphs(int glyphSet)
{
    if (glyphSet == TEXT_GLYPHS_SYSTEM)
    {
        gActiveFont->glyphs = TextGlyphs_System;
    }
    else
    {
        gActiveFont->glyphs = TextGlyphs_Talk;
    }
}

void ResetTextFont(void)
{
    gActiveFont->chr_counter = 0;
    sSpecialCharStList[0].color = -1;
}

void SetTextFont(struct Font * font)
{
    if (font == NULL)
        gActiveFont = &gDefaultFont;
    else
        gActiveFont = font;
}

void InitText(struct Text * text, int width)
{
    text->chr_position = gActiveFont->chr_counter;
    text->tile_width = width;
    text->db_id = 0;
    text->db_enabled = FALSE;
    text->is_printing = FALSE;

    gActiveFont->chr_counter += width;

    ClearText(text);
}

void InitTextDb(struct Text * text, int width)
{
    text->chr_position = gActiveFont->chr_counter;
    text->tile_width = width;
    text->db_id = 0;
    text->db_enabled = TRUE;
    text->is_printing = FALSE;

    gActiveFont->chr_counter += width * 2;
}

void InitTextList(struct TextInitInfo const * info)
{
    while (info->text != NULL)
    {
        InitText(info->text, info->width);
        info++;
    }
}

void ClearText(struct Text * text)
{
    text->x = 0;
    text->color = 0;

    CpuFastFill16(0, gActiveFont->get_draw_dest(text), text->tile_width * 2 * CHR_SIZE);
}

void ClearTextPart(struct Text * text, int tile_off, int tile_width)
{
    u8 * dst = gActiveFont->draw_dest + (text->chr_position + text->db_id * text->tile_width + tile_off) * 2 * CHR_SIZE;

    CpuFastFill16(0, dst, tile_width * 2 * CHR_SIZE);
}

int Text_GetChrOffset(struct Text * text)
{
    return (text->chr_position + text->db_id * text->tile_width) * 2;
}

int Text_GetCursor(struct Text * text)
{
    return text->x;
}

void Text_SetCursor(struct Text * text, int x)
{
    text->x = x;
}

void Text_Skip(struct Text * text, int x)
{
    text->x += x;
}

void Text_SetColor(struct Text * text, int color)
{
    text->color = color;
}

int Text_GetColor(struct Text * text)
{
    return text->color;
}

void Text_SetParams(struct Text * text, int x, int color)
{
    text->x = x;
    text->color = color;
}

void PutText(struct Text * text, u16 * tm)
{
    int tileref = gActiveFont->tileref + (text->chr_position + text->db_id * text->tile_width) * 2;
    int i;

    for (i = 0; i < text->tile_width; i++)
    {
        tm[0x00] = tileref++;
        tm[0x20] = tileref++;

        tm++;
    }

    if (!text->db_enabled)
        return;

    text->db_id = text->db_id ^ 1;
}

void PutBlankText(struct Text * text, u16 * tm)
{
    int i;

    for (i = 0; i < text->tile_width; i++)
    {
        tm[0x00] = 0;
        tm[0x20] = 0;

        tm++;
    }
}

int GetStringTextLen(char const * str)
{
    struct Glyph const * glyph;
    char byte2, byte1;

    int result = 0;

    if (gActiveFont->lang != LANG_JAPANESE)
        return GetStringTextLenAscii(str);

    while (*str > 1)
    {
        byte1 = *str++;

        if (byte1 < 0x20)
            continue;

        byte2 = *str++;

        glyph = gActiveFont->glyphs[byte2 - 0x40];

        while (glyph)
        {
            if (glyph->sjis_byte_1 == byte1)
            {
                result += glyph->width;
                break;
            }

            glyph = glyph->next;
        }
    }

    return result;
}

char const * GetCharTextLen(char const * str, int * out_width)
{
    struct Glyph const * glyph;
    char byte2, byte1;

    if (gActiveFont->lang != LANG_JAPANESE) { }

    byte1 = *str++;
    byte2 = *str++;

    glyph = gActiveFont->glyphs[byte2 - 0x40];

    while (glyph)
    {
        if (glyph->sjis_byte_1 == byte1)
        {
            *out_width = glyph->width;
            break;
        }

        glyph = glyph->next;
    }

    return str;
}

int GetStringTextCenteredPos(int areaLength, char const * str)
{
    return (areaLength - GetStringTextLen(str)) / 2;
}

void GetStringTextBox(char const * str, int * out_width, int * out_height)
{
    *out_width = 0;
    *out_height = 0;

    while (*str > 1)
    {
        int width = GetStringTextLen(str);

        if (*out_width < width)
            *out_width = width;

        *out_height += 16;

        str = GetStringLineEnd(str);

        if (*str == 0)
            break;

        str++;
    }
}

char const * GetStringLineEnd(char const * str)
{
    while (*str > 1)
    {
        if (*str == 4)
        {
            str++;
            continue;
        }

        str += 2;
    }

    return str;
}

void Text_DrawString(struct Text * text, char const * str)
{
    struct Glyph const * glyph;
    char byte2, byte1;

    if (gActiveFont->lang != LANG_JAPANESE)
    {
        Text_DrawStringAscii(text, str);
        return;
    }

    while (*str > 1)
    {
        byte1 = *str++;

        if (byte1 < 0x20)
            continue;

        byte2 = *str++;

    retry_draw:
        glyph = gActiveFont->glyphs[byte2 - 0x40];

        while (glyph)
        {
            if (glyph->sjis_byte_1 == byte1)
            {
                gActiveFont->draw_glyph(text, glyph);
                break;
            }

            glyph = glyph->next;

            if (glyph == NULL)
            {
                byte1 = 0x81;
                byte2 = 0xA7;

                goto retry_draw;
            }
        }
    }
}

void Text_DrawNumber(struct Text * text, int number)
{
    if (number == 0)
    {
        Text_DrawCharacter(text, JTEXT("０"));
        return;
    }

    while (number != 0)
    {
        u16 chr = 0x4F82 + ((number % 10) << 8);
        number /= 10;

        Text_DrawCharacter(text, (char const *) &chr);

        text->x -= 16;
    }
}

void Text_DrawNumberOrBlank(struct Text * text, int number)
{
    if (number == 0xFF || number == -1)
    {
        Text_Skip(text, -8);
        Text_DrawString(text, JTEXT("ーー"));

        return;
    }

    Text_DrawNumber(text, number);
}

char const * Text_DrawCharacter(struct Text * text, char const * str)
{
    struct Glyph const * glyph;
    char byte2, byte1;

    if (gActiveFont->lang != LANG_JAPANESE)
        return Text_DrawCharacterAscii(text, str);

    byte1 = *str++;
    byte2 = *str++;

retry_draw:
    glyph = gActiveFont->glyphs[byte2 - 0x40];

    while (glyph)
    {
        if (glyph->sjis_byte_1 == byte1)
        {
            gActiveFont->draw_glyph(text, glyph);
            break;
        }

        glyph = glyph->next;
    }

    if (glyph == NULL)
    {
        byte1 = 0x81;
        byte2 = 0xA7;

        goto retry_draw;
    }

    return str;
}

static u8 * GetTextDrawDest(struct Text * text)
{
    int chrNumber = (text->chr_position + text->db_id * text->tile_width + text->x / 8);

    return gActiveFont->draw_dest + chrNumber * 2 * CHR_SIZE;
}

static u16 const * GetColorLut(int color)
{
    return s2bppTo4bppLutTable[color];
}

static void DrawTextGlyph(struct Text * text, struct Glyph const * glyph)
{
    u8 * draw_dest = gActiveFont->get_draw_dest(text);
    int subx = text->x & 7;
    u32 const * bitmap = glyph->bitmap;

    DrawGlyphRam(GetColorLut(text->color), draw_dest, bitmap, subx);
    text->x += glyph->width;
}

static void DrawTextGlyphNoClear(struct Text * text, struct Glyph const * glyph)
{
    int i;

    u32 * dst = (u32 *) gActiveFont->get_draw_dest(text);
    int subx = text->x & 7;
    u32 const * bitmap = glyph->bitmap;

    u64 bitmapRow;

    u16 const * maskLut = GetColorLut(TEXT_COLOR_MASK);
    u16 const * colorLut = GetColorLut(text->color);

    int unused;

    for (i = 0; i < 16; ++i)
    {
        // read one row of 32 bits from the bitmap
        bitmapRow = (u64) *bitmap << subx * 2;

        dst[0x00] &= maskLut[bitmapRow & 0xFF] | (maskLut[(bitmapRow >> 8) & 0xFF] << 16);
        dst[0x00] |= colorLut[bitmapRow & 0xFF] | (colorLut[(bitmapRow >> 8) & 0xFF] << 16);

        dst[0x10] &= maskLut[(bitmapRow >> 16) & 0xFF] | (maskLut[(bitmapRow >> 24) & 0xFF] << 16);
        dst[0x10] |= colorLut[(bitmapRow >> 16) & 0xFF] | (colorLut[(bitmapRow >> 24) & 0xFF] << 16);

        dst[0x20] &= maskLut[(bitmapRow >> 32) & 0xFF] | (maskLut[(bitmapRow >> 40) & 0xFF] << 16);
        dst[0x20] |= colorLut[(bitmapRow >> 32) & 0xFF] | (colorLut[(bitmapRow >> 40) & 0xFF] << 16);

        dst++;
        bitmap++;
    }

    text->x += glyph->width;
}

void InitSystemTextFont(void)
{
    ApplyPalette(Pal_SystemText, gActiveFont->palid);
    PAL_COLOR(gActiveFont->palid, 0) = 0;

    gActiveFont->draw_glyph = DrawTextGlyph;
    SetTextFontGlyphs(TEXT_GLYPHS_SYSTEM);
}

void InitTalkTextFont(void)
{
    ApplyPalette(Pal_TalkText, gActiveFont->palid);
    PAL_COLOR(gActiveFont->palid, 0) = 0;

    gActiveFont->draw_glyph = DrawTextGlyph;
    SetTextFontGlyphs(TEXT_GLYPHS_TALK);
}

void SetTextDrawNoClear(void)
{
    gActiveFont->draw_glyph = DrawTextGlyphNoClear;
}

void PutDrawText(struct Text * text, u16 * tm, int color, int x, int tile_width, char const * str)
{
    struct Text tmpText;

    if (text == NULL)
    {
        text = &tmpText;
        InitText(text, tile_width);
    }

    Text_SetCursor(text, x);
    Text_SetColor(text, color);
    Text_DrawString(text, str);

    PutText(text, tm);
}

void Text_InsertDrawString(struct Text * text, int x, int color, char const * str)
{
    Text_SetCursor(text, x);
    Text_SetColor(text, color);
    Text_DrawString(text, str);
}

void Text_InsertDrawNumberOrBlank(struct Text * text, int x, int color, int number)
{
    Text_SetCursor(text, x);
    Text_SetColor(text, color);
    Text_DrawNumberOrBlank(text, number);
}

static void Text_DrawStringAscii(struct Text * text, char const * str)
{
    struct Glyph const * glyph;

    while (*str != 0)
    {
        glyph = gActiveFont->glyphs[*str++];

        if (glyph == NULL)
            glyph = gActiveFont->glyphs['?'];

        gActiveFont->draw_glyph(text, glyph);
    }
}

static char const * Text_DrawCharacterAscii(struct Text * text, char const * str)
{
    struct Glyph const * glyph = gActiveFont->glyphs[*str++];

    if (glyph == NULL)
        glyph = gActiveFont->glyphs['?'];

    gActiveFont->draw_glyph(text, glyph);

    return str;
}

static int GetStringTextLenAscii(char const * str)
{
    struct Glyph const * glyph;

    int result = 0;

    while (*str != 0)
    {
        glyph = gActiveFont->glyphs[*str++];
        result += glyph->width;
    }

    return result;
}

void func_fe6_080065BC(void)
{
}

void InitSpriteTextFont(struct Font * font, u8 * draw_dest, int palid)
{
    font->draw_dest = draw_dest;
    font->get_draw_dest = GetSpriteTextDrawDest;
    font->palid = (palid & 0xF) + 0x10;
    font->tileref = ((u32) draw_dest & 0x1FFFF) >> 5;
    font->chr_counter = 0;
    font->lang = GetLang();

    SetTextFont(font);

    font->draw_glyph = DrawSpriteTextGlyph;
}

void InitSpriteText(struct Text * text)
{
    text->chr_position = gActiveFont->chr_counter;
    text->tile_width = 0x20;
    text->db_id = 0;
    text->db_enabled = FALSE;
    text->is_printing = FALSE;

    gActiveFont->chr_counter += 2 * 0x20;

    text->x = 0;
    text->color = 0;
}

void SpriteText_DrawBackground(struct Text * text)
{
    if (text->tile_width == 0)
        return;

    text->x = 0;

    CpuFastFill(0x44444444, gActiveFont->get_draw_dest(text),                   0x1B * CHR_SIZE);
    CpuFastFill(0x44444444, gActiveFont->get_draw_dest(text) + 0x20 * CHR_SIZE, 0x1B * CHR_SIZE);
}

void SpriteText_DrawBackgroundExt(struct Text * text, u32 line)
{
    text->x = 0;

    CpuFastFill(line, gActiveFont->get_draw_dest(text), 2 * 0x20 * CHR_SIZE);
}

static u8 * GetSpriteTextDrawDest(struct Text * text)
{
    int chr = (text->chr_position + text->db_id * text->tile_width + text->x / 8);

    return gActiveFont->draw_dest + chr * CHR_SIZE;
}

static void DrawSpriteTextGlyph(struct Text * text, struct Glyph const * glyph)
{
    int i;

    u32 * dst = (u32 *) gActiveFont->get_draw_dest(text);
    int subx = text->x & 7;
    u32 const * bitmap = glyph->bitmap;

    u64 bitmapRow;

    u16 const * lut = GetColorLut(text->color);

    for (i = 0; i < 8; ++i)
    {
        bitmapRow = (u64) *bitmap << subx * 2;

        dst[0x00] |= lut[bitmapRow & 0xFF] | (lut[(bitmapRow >> 8) & 0xFF] << 16);
        dst[0x08] |= lut[(bitmapRow >> 16) & 0xFF] | (lut[(bitmapRow >> 24) & 0xFF] << 16);
        dst[0x10] |= lut[(bitmapRow >> 32) & 0xFF] | (lut[(bitmapRow >> 40) & 0xFF] << 16);

        dst++;
        bitmap++;
    }

    dst = (u32 *) (gActiveFont->get_draw_dest(text) + 0x20 * CHR_SIZE);

    for (i = 0; i < 8; ++i)
    {
        bitmapRow = (u64) *bitmap << subx * 2;

        dst[0x00] |= lut[bitmapRow & 0xFF] | (lut[(bitmapRow >> 8) & 0xFF] << 16);
        dst[0x08] |= lut[(bitmapRow >> 16) & 0xFF] | (lut[(bitmapRow >> 24) & 0xFF] << 16);
        dst[0x10] |= lut[(bitmapRow >> 32) & 0xFF] | (lut[(bitmapRow >> 40) & 0xFF] << 16);

        dst++;
        bitmap++;
    }

    text->x += glyph->width;
}

static void TextPrint_OnLoop(struct TextPrintProc * proc)
{
    int i;

    proc->clock--;

    if (proc->clock > 0)
        return;

    proc->clock = proc->interval;

    for (i = 0; i < proc->char_per_tick; ++i)
    {
        switch (*proc->str)
        {

        case 0: // end
            // fallthrough

        case 1: // newline
            proc->text->is_printing = FALSE;
            Proc_Break(proc);

            return;

        case 4: // space?
            proc->str++;
            Text_Skip(proc->text, 6);

            break;

        default:
            proc->str = Text_DrawCharacter(proc->text, proc->str);

        }
    }
}

char const * StartTextPrint(struct Text * text, char const * str, int interval, int char_per_tick)
{
    struct TextPrintProc * proc;

    if (interval == 0)
        Text_DrawString(text, str);

    if (char_per_tick == 0)
        char_per_tick = 1;

    proc = SpawnProc(ProcScr_TextPrint, PROC_TREE_3);

    proc->text = text;
    proc->str = str;

    proc->char_per_tick = char_per_tick;
    proc->interval = interval;
    proc->clock = 0;

    text->is_printing = TRUE;

    return GetStringLineEnd(str);
}

i8 IsTextPrinting(struct Text * text)
{
    return text->is_printing;
}

void EndTextPrinting(void)
{
    Proc_EndEach(ProcScr_TextPrint);
}

static void GreenText_OnLoop(ProcPtr proc)
{
    int index = (GetGameTime() / 4) & 0xF;

    PAL_BG_COLOR(BGPAL_TEXT_DEFAULT, 14) = *(Pal_GreenTextColors + index);
    EnablePalSync();
}

void StartGreenText(ProcPtr parent)
{
    if (parent)
        SpawnProc(ProcScr_GreenTextColor, parent);
    else
        SpawnProc(ProcScr_GreenTextColor, PROC_TREE_3);
}

void EndGreenText(void)
{
    Proc_EndEach(ProcScr_GreenTextColor);
}

static void DrawSpecialCharGlyph(int chr_position, int color, struct Glyph const * glyph)
{
    int i;

    u32 * dst = (u32 *) (gActiveFont->draw_dest + chr_position * 2 * CHR_SIZE);
    u32 const * bitmap = glyph->bitmap;

    int lo, hi;

    u16 const * lut = GetColorLut(color);

    for (i = 0; i < 16; ++i)
    {
        lo = lut[(*bitmap) & 0xFF];
        hi = lut[(*bitmap >> 8) & 0xFF];

        *dst = lo + (hi << 16);

        dst++;
        bitmap++;
    }
}

static int AddSpecialChar(struct SpecialCharSt * st, int color, int id)
{
    st->color = color;
    st->id = id;
    st->chr_position = gActiveFont->chr_counter++;

    (st + 1)->color = -1;

    DrawSpecialCharGlyph(st->chr_position, color, TextGlyphs_Special[id]);

    return st->chr_position;
}

static int GetSpecialCharChr(int color, int id)
{
    struct SpecialCharSt * it = sSpecialCharStList;

    while (TRUE)
    {
        if (it->color < 0)
            return AddSpecialChar(it, color, id);

        if (it->color == color && it->id == id)
            return it->chr_position;

        it++;
    }
}

void PutSpecialChar(u16 * tm, int color, int id)
{
    int chr;

    if (id == TEXT_SPECIAL_NOTHING)
    {
        tm[0x00] = 0;
        tm[0x20] = 0;

        return;
    }

    chr = GetSpecialCharChr(color, id) * 2 + gActiveFont->tileref;

    tm[0x00] = chr;
    tm[0x20] = chr + 1;
}

void PutNumberExt(u16 * tm, int color, int number, int id_zero)
{
    if (number == 0)
    {
        PutSpecialChar(tm, color, id_zero);
        return;
    }

    while (number != 0)
    {
        PutSpecialChar(tm, color, number % 10 + id_zero);
        number /= 10;

        tm--;
    }
}

void PutNumber(u16 * tm, int color, int number)
{
    PutNumberExt(tm, color, number, TEXT_SPECIAL_BIGNUM_0);
}

void PutNumberOrBlank(u16 * tm, int color, int number)
{
    if (number < 0 || number == 0xFF)
        PutTwoSpecialChar(tm - 1, color, TEXT_SPECIAL_DASH, TEXT_SPECIAL_DASH);
    else
        PutNumber(tm, color, number);
}

void PutNumberTwoChr(u16 * tm, int color, int number)
{
    if (number == 100)
        PutTwoSpecialChar(tm - 1, color, TEXT_SPECIAL_100_A, TEXT_SPECIAL_100_B);
    else if (number < 0 || number == 255)
        PutTwoSpecialChar(tm - 1, color, TEXT_SPECIAL_DASH, TEXT_SPECIAL_DASH);
    else
        PutNumber(tm, color, number);
}

void PutNumberSmall(u16 * tm, int color, int number)
{
    PutNumberExt(tm, color, number, TEXT_SPECIAL_SMALLNUM_0);
}

void PutNumberBonus(int number, u16 * tm)
{
    if (number == 0)
        return;

    PutSpecialChar(tm, TEXT_COLOR_SYSTEM_GREEN, TEXT_SPECIAL_PLUS);
    PutNumberSmall(tm + ((number >= 10) ? 2 : 1), TEXT_COLOR_SYSTEM_GREEN, number);
}

void SpecialCharTest(void)
{
    int ix, iy;

    int cnt = GetGameTime();

    for (iy = 0; iy < 10; ++iy)
        for (ix = 0; ix < 30; ++ix)
            PutSpecialChar(gBg0Tm + TM_OFFSET(ix, iy * 2), TEXT_COLOR_SYSTEM_WHITE, (cnt++) & 1);

    EnableBgSync(BG0_SYNC_BIT);
}

inline void PutNumber2DigitExt(u16 * tm, int color, int number, int id_zero)
{
    PutSpecialChar(tm, color, number % 10 + id_zero);
    PutSpecialChar(tm - 1, color, (number / 10) % 10 + id_zero);
}

inline void PutNumber2Digit(u16 * tm, int color, int number)
{
    PutNumber2DigitExt(tm, color, number, TEXT_SPECIAL_BIGNUM_0);
}

inline void PutNumber2DigitSmall(u16 * tm, int color, int number)
{
    PutNumber2DigitExt(tm, color, number, TEXT_SPECIAL_SMALLNUM_0);
}

void PutTime(u16 * tm, int color, int time, bool always_display_punctuation)
{
    u16 hours, minutes, seconds;
    i8 hs = FormatTime(time, &hours, &minutes, &seconds);

    PutNumber(tm + 2, color, hours);
    PutNumber2Digit(tm + 5, color, minutes);
    PutNumber2DigitSmall(tm + 8, color, seconds);

    if (hs == FALSE || always_display_punctuation)
    {
        PutSpecialChar(tm + 3, color, TEXT_SPECIAL_COLON);
        PutSpecialChar(tm + 6, color, TEXT_SPECIAL_DOT);
    }
    else
    {
        PutSpecialChar(tm + 3, color, TEXT_SPECIAL_NOTHING);
        PutSpecialChar(tm + 6, color, TEXT_SPECIAL_NOTHING);
    }
}

void PutTwoSpecialChar(u16 * tm, int color, int id_a, int id_b)
{
    PutSpecialChar(tm++, color, id_a);
    PutSpecialChar(tm,   color, id_b);
}

#include "data/text/color-lut.h"
