#pragma once

#include "gba/gba.h"

#include "proc.h"

struct Glyph
{
    struct Glyph const * next;

    u8 sjis_byte_1;
    u8 width;
    u32 bitmap[16];
};

struct Text
{
    /* 00 */ u16 chr_position;
    /* 02 */ u8 x;
    /* 03 */ u8 color;
    /* 04 */ u8 tile_width;
    /* 05 */ bool db_enabled;
    /* 06 */ u8 db_id;
    /* 07 */ bool is_printing;
};

struct Font
{
    /* 00 */ u8 * draw_dest;
    /* 04 */ struct Glyph const * const * glyphs;
    /* 08 */ void (* draw_glyph)(struct Text * text, struct Glyph const * glyph);
    /* 0C */ u8 * (* get_draw_dest)(struct Text * text);
    /* 10 */ u16 tileref;
    /* 12 */ u16 chr_counter;
    /* 14 */ u16 palid;
    /* 16 */ u8 lang;
};

struct TextInitInfo
{
    /* 00 */ struct Text * text;
    /* 04 */ u8 width;
};

enum
{
    LANG_JAPANESE,
    LANG_ENGLISH,
};

enum
{
    TEXT_GLYPHS_SYSTEM,
    TEXT_GLYPHS_TALK,
};

enum
{
    TEXT_COLOR_0123 = 0,
    TEXT_COLOR_0456 = 1,
    TEXT_COLOR_0789 = 2,
    TEXT_COLOR_0ABC = 3,
    TEXT_COLOR_0DEF = 4,
    TEXT_COLOR_0030 = 5,
    TEXT_COLOR_4DEF = 6,
    TEXT_COLOR_456F = 7,
    TEXT_COLOR_47CF = 8,
    TEXT_COLOR_MASK = 9,

    TEXT_COLOR_COUNT,

    TEXT_COLOR_SYSTEM_WHITE = TEXT_COLOR_0123,
    TEXT_COLOR_SYSTEM_GRAY  = TEXT_COLOR_0456,
    TEXT_COLOR_SYSTEM_BLUE  = TEXT_COLOR_0789,
    TEXT_COLOR_SYSTEM_GOLD  = TEXT_COLOR_0ABC,
    TEXT_COLOR_SYSTEM_GREEN = TEXT_COLOR_0DEF,

    // TEXT_COLOR_TALK_...
};

enum
{
    TEXT_SPECIAL_BIGNUM_0,
    TEXT_SPECIAL_BIGNUM_1,
    TEXT_SPECIAL_BIGNUM_2,
    TEXT_SPECIAL_BIGNUM_3,
    TEXT_SPECIAL_BIGNUM_4,
    TEXT_SPECIAL_BIGNUM_5,
    TEXT_SPECIAL_BIGNUM_6,
    TEXT_SPECIAL_BIGNUM_7,
    TEXT_SPECIAL_BIGNUM_8,
    TEXT_SPECIAL_BIGNUM_9,
    TEXT_SPECIAL_SMALLNUM_0,
    TEXT_SPECIAL_SMALLNUM_1,
    TEXT_SPECIAL_SMALLNUM_2,
    TEXT_SPECIAL_SMALLNUM_3,
    TEXT_SPECIAL_SMALLNUM_4,
    TEXT_SPECIAL_SMALLNUM_5,
    TEXT_SPECIAL_SMALLNUM_6,
    TEXT_SPECIAL_SMALLNUM_7,
    TEXT_SPECIAL_SMALLNUM_8,
    TEXT_SPECIAL_SMALLNUM_9,
    TEXT_SPECIAL_DASH,
    TEXT_SPECIAL_PLUS,
    TEXT_SPECIAL_SLASH,
    TEXT_SPECIAL_TILDE,
    TEXT_SPECIAL_S,
    TEXT_SPECIAL_A,
    TEXT_SPECIAL_B,
    TEXT_SPECIAL_C,
    TEXT_SPECIAL_D,
    TEXT_SPECIAL_E,
    TEXT_SPECIAL_G,
    TEXT_SPECIAL_K, // NOTE: this is an E? used as statscreen exp label and equip marker
    TEXT_SPECIAL_COLON,
    TEXT_SPECIAL_DOT,
    TEXT_SPECIAL_HP_A,
    TEXT_SPECIAL_HP_B,
    TEXT_SPECIAL_LV_A,
    TEXT_SPECIAL_LV_B,
    TEXT_SPECIAL_ARROW,
    TEXT_SPECIAL_HEART,
    TEXT_SPECIAL_100_A,
    TEXT_SPECIAL_100_B,
    TEXT_SPECIAL_PERCENT,
    // TODO: rest

    TEXT_SPECIAL_NOTHING = 0xFF,
};

int GetLang(void);
void ResetText(void);
void InitTextFont(struct Font * font, void * draw_dest, int chr, int palid);
void SetTextFontGlyphs(int glyphSet);
void ResetTextFont(void);
void SetTextFont(struct Font * font);
void InitText(struct Text * text, int width);
void InitTextDb(struct Text * text, int width);
void InitTextList(struct TextInitInfo const * info);
void ClearText(struct Text * text);
void ClearTextPart(struct Text * text, int tile_off, int tile_width);
int Text_GetChrOffset(struct Text * text);
int Text_GetCursor(struct Text * text);
void Text_SetCursor(struct Text * text, int x);
void Text_Skip(struct Text * text, int x);
void Text_SetColor(struct Text * text, int color);
int Text_GetColor(struct Text * text);
void Text_SetParams(struct Text * text, int x, int color);
void PutText(struct Text * text, u16 * tm);
void PutBlankText(struct Text * text, u16 * tm);
int GetStringTextLen(char const * str);
char const * GetCharTextLen(char const * str, int * out_width);
int GetStringTextCenteredPos(int areaLength, char const * str);
void GetStringTextBox(char const * str, int * out_width, int * out_height);
char const * GetStringLineEnd(char const * str);
void Text_DrawString(struct Text * text, char const * str);
void Text_DrawNumber(struct Text * text, int number);
void Text_DrawNumberOrBlank(struct Text * text, int number);
char const * Text_DrawCharacter(struct Text * text, char const * str);
void InitSystemTextFont(void);
void InitTalkTextFont(void);
void SetTextDrawNoClear(void);
void PutDrawText(struct Text * text, u16 * tm, int color, int x, int tile_width, char const * str);
void Text_InsertDrawString(struct Text * text, int x, int color, const char * str);
void Text_InsertDrawNumberOrBlank(struct Text * text, int x, int color, int number);
void InitSpriteTextFont(struct Font * font, u8 * draw_dest, int palid);
void InitSpriteText(struct Text * text);
void SpriteText_DrawBackground(struct Text * text);
void SpriteText_DrawBackgroundExt(struct Text * text, u32 line);
char const * StartTextPrint(struct Text * text, char const * str, int interval, int char_per_tick);
bool IsTextPrinting(struct Text * text);
void EndTextPrinting(void);
void StartGreenText(ProcPtr parent);
void EndGreenText(void);
void PutSpecialChar(u16 * tm, int color, int id);
void PutNumberExt(u16 * tm, int color, int number, int id_zero);
void PutNumber(u16 * tm, int color, int number);
void PutNumberOrBlank(u16 * tm, int color, int number);
void PutNumberTwoChr(u16 * tm, int color, int number);
void PutNumberSmall(u16 * tm, int color, int number);
void PutNumberBonus(int number, u16 * tm);
void PutNumber2DigitExt(u16 * tm, int color, int number, int id_zero);
void PutNumber2Digit(u16 * tm, int color, int number);
void PutNumber2DigitSmall(u16 * tm, int color, int number);
void PutTime(u16 * tm, int color, int time, bool always_display_punctuation);
void PutTwoSpecialChar(u16 * tm, int color, int id_a, int id_b);

extern struct Font EWRAM_DATA gDefaultFont;
extern struct Font * EWRAM_DATA gActiveFont;
