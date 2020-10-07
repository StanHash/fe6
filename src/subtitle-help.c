
#include "common.h"

#include "hardware.h"
#include "oam.h"
#include "proc.h"
#include "text.h"
#include "sprite.h"
#include "map.h"
#include "bm.h"

#include "constants/video-global.h"

struct SubtitleHelpProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ char const* string;
    /* 30 */ struct Font font;
    /* 48 */ struct Text text[2];
    /* 58 */ short textOffset;
    /* 5A */ short textShowCnt;
    /* 5C */ short textNum;
    /* 5E */ short textCount;
};

static void PutSubtitleHelpText(struct SubtitleHelpProc* proc, int y)
{
    static u16 lut[] =
    {
        0x00, 0x04, 0x08, 0x0C, 0x10, 0x14, 0x18,
              0x44, 0x48, 0x4C, 0x50, 0x54, 0x58,
    };

    int i;

    for (i = 0; i < 9; ++i)
    {
        int x = i*32 - 32 + proc->textOffset;
        int num = (proc->textNum + i) % proc->textCount;

        PutSprite(2, x, y,
            Sprite_32x16, OAM2_CHR(OBJCHR_SUBTITLEHELP_TEXT) + OAM2_PAL(OBJPAL_SUBTITLEHELP_TEXT) + lut[num]);
    }
}

static void InitSubtitleHelpText(struct SubtitleHelpProc* proc)
{
    enum { TEXT_WIDTH = DISPLAY_WIDTH-16 };

    int line;

    char const* it = proc->string;

    InitSpriteTextFont(&proc->font, OBJ_VRAM0 + OBJCHR_SUBTITLEHELP_TEXT*CHR_SIZE, 0x10+OBJPAL_SUBTITLEHELP_TEXT);
    SetTextFontGlyphs(TEXT_GLYPHS_TALK);

    ApplyPalette(Pal_TalkText, 0x10+OBJPAL_SUBTITLEHELP_TEXT);

    for (line = 0; line < 2; ++line)
    {
        InitSpriteText(proc->text+line);

        SpriteText_DrawBackgroundExt(proc->text+line, 0);
        Text_SetColor(proc->text+line, TEXT_COLOR_0123);
    }

    line = 0;

    while (*it > 1)
    {
        it = Text_DrawCharacter(proc->text+line, it);

        if (Text_GetCursor(proc->text+line) > TEXT_WIDTH)
        {
            int width;

            it -= 2;
            line += 1;

            GetCharTextLen(it, &width);

            Text_SetCursor(proc->text+line,
                Text_GetCursor(proc->text+0) + 32 - width - TEXT_WIDTH);
        }
    }

    proc->textCount = ((GetStringTextLen(proc->string)+16) >> 5) + 1;
    proc->textNum = proc->textCount - 1;

    SetTextFont(NULL);
}

static void SubtitleHelpDarkenerOnHBlank(void)
{
    static u8 bldyLut[] =
    {
        0, 0, 0, 0, 0, 0, 0, 0, // 128 .. 135
        0, 0, 0, 0, 1, 2, 3, 4, // 136 .. 143
        5, 6, 7, 7, 7, 7, 7, 7, // 144 .. 151
        7, 7, 7, 7, 7, 7, 7, 7, // 152 .. 159
    };

    u16 vcount = REG_VCOUNT;

    if (vcount < 140 || vcount > 160)
    {
        REG_BLDCNT   = *(u16*)(&gDispIo.blendCt);
        REG_BLDALPHA = *(u16*)(&gDispIo.blendCoeffA);
        REG_BLDY     = gDispIo.blendY;
    }
    else
    {
        int bldy;

        bldy = bldyLut[vcount - 128];
        bldy = bldy - gBmSt.altBlendA_ca;

        if (bldy < 0)
            bldy = 0;

        REG_BLDCNT = BLDCNT_DARKEN | BLDCNT_TARGETA(0, 0, 1, 1, 0) | BLDCNT_TARGETA_BD;
        REG_BLDY   = bldy;
    }
}

static void SubtitleHelpDarkener_Init(ProcPtr proc)
{
    gBmSt.altBlendA_ca = 8;
    SetOnHBlankA(SubtitleHelpDarkenerOnHBlank);
}

static void SubtitleHelpDarkener_FadeIn(ProcPtr proc)
{
    if (gBmSt.altBlendA_ca != 0)
        gBmSt.altBlendA_ca -= 1;
}

static void SubtitleHelpDarkener_FadeOut(ProcPtr proc)
{
    gBmSt.altBlendA_ca += 1;

    if (gBmSt.altBlendA_ca == 8)
    {
        SetOnHBlankA(NULL);
        Proc_Break(proc);
    }
}

struct ProcScr CONST_DATA ProcScr_SubtitleHelpDarkener[] =
{
    PROC_END_DUPS,

    PROC_CALL(SubtitleHelpDarkener_Init),
    PROC_REPEAT(SubtitleHelpDarkener_FadeIn),
    PROC_REPEAT(SubtitleHelpDarkener_FadeOut),

    PROC_END,
};

static void SubtitleHelp_Init(struct SubtitleHelpProc* proc)
{
    proc->textOffset = 31;
    proc->textShowCnt = 6;

    SpawnProc(ProcScr_SubtitleHelpDarkener, PROC_TREE_3);
}

static void SubtitleHelp_OnEnd(struct SubtitleHelpProc* proc)
{
    gBmSt.cameraMax.y -= 16;
    CameraMove_08016290(NULL);

    Proc_BreakEach(ProcScr_SubtitleHelpDarkener);
}

static void SubtitleHelp_Loop(struct SubtitleHelpProc* proc)
{
    static u8 lut[] =
    {
        144, 145, 146, 148, 150, 153, 156,
    };

    PutSubtitleHelpText(proc, lut[proc->textShowCnt]);

    if (proc->textShowCnt != 0)
        proc->textShowCnt--;

    proc->textOffset--;

    if (proc->textOffset < 0)
    {
        proc->textOffset = 31;
        proc->textNum++;
    }
}

struct ProcScr CONST_DATA ProcScr_SubtitleHelp[] =
{
    PROC_19,
    PROC_19,

    PROC_ONEND(SubtitleHelp_OnEnd),
    PROC_SLEEP(0),

    PROC_CALL(SubtitleHelp_Init),
    PROC_REPEAT(SubtitleHelp_Loop),

    PROC_BLOCK,
};

void StartSubtitleHelp(ProcPtr parent, char const* str)
{
    if (gPlaySt.configNoSubtitleHelp != TRUE)
    {
        struct SubtitleHelpProc* proc;

        proc = SpawnProc(ProcScr_SubtitleHelp, parent);
        proc->string = str;

        InitSubtitleHelpText(proc);

        sub_80192E4();

        gBmSt.cameraMax.y += 16;
    }
}

void EndSubtitleHelp(void)
{
    Proc_EndEach(ProcScr_SubtitleHelp);
}

Bool IsSubtitleHelpActive(void)
{
    return Proc_Exists(ProcScr_SubtitleHelp);
}
