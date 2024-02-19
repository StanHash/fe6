#include "talk.h"

#include <string.h>

#include "armfunc.h"
#include "hardware.h"
#include "oam.h"
#include "sound.h"
#include "proc.h"
#include "debugtext.h"
#include "text.h"
#include "sprite.h"
#include "face.h"
#include "event.h"
#include "msg.h"
#include "util.h"
#include "bm.h"
#include "unit.h"
#include "chapter.h"
#include "ui.h"
#include "banim_ekrbattle.h"
#include "manim.h"

#include "constants/videoalloc_global.h"
#include "constants/songs.h"
#include "constants/msg.h"

struct TalkChoiceEnt
{
    u16 msg;
    Func onSwitch;
};

struct TalkChoiceProc
{
    /* 00 */ PROC_HEADER;

    /* 2A */ short selectedChoice;
    /* 2C */ short x_disp;
    /* 2E */ short y_disp;
    /* 30 */ int unused30;
    /* 34 */ struct TalkChoiceEnt const * choices;
};

static void TalkSkipListener_OnIdle(ProcPtr proc);
static void Talk_OnInit(ProcPtr proc);
static void Talk_OnIdle(ProcPtr proc);
static bool TalkPrepNextChar(ProcPtr proc);
static bool TalkSpritePrepNextChar(ProcPtr proc);
static void LockTalk(ProcPtr proc);
static int TalkInterpret(ProcPtr proc);
static void TalkInterpretNewFace(ProcPtr proc);
static int GetFaceIdByX(int x);
static void SetTalkFaceLayer(int talk_face, int toBack);
static void MoveTalkFace(int talkFaceFrom, int talkFaceTo);
static bool IsTalkFaceMoving(void);
static void StartTalkFaceMove(int talkFaceFrom, int talkFaceTo, bool isSwap);
static void TalkFaceMove_OnInit(struct GenericProc * proc);
static void TalkFaceMove_OnIdle(struct GenericProc * proc);
static void Talk_OnEnd(ProcPtr proc);
static void TalkPause_OnIdle(struct GenericProc * proc);
static void TalkWaitForInput_OnIdle(struct GenericProc * proc);
static void TalkShiftClearAll_OnInit(struct GenericProc * proc);
static void TalkShiftClearAll_OnIdle(struct GenericProc * proc);
static void StartTalkChoice(struct TalkChoiceEnt const * choices, struct Text * text, u16 * tm, int defaultChoice, int color, ProcPtr parent);
static void TalkChoice_OnIdle(struct TalkChoiceProc * proc);
static void TalkShiftClear_OnInit(struct GenericProc * proc);
static void TalkShiftClear_OnIdle(struct GenericProc * proc);
static int GetTalkPauseCmdDuration(int cmd);
static void PutTalkBubble(int xAnchor, int yAnchor, int width, int height);
static void StartOpenTalkBubble(void);
static void func_fe6_0800B3D4(ProcPtr proc);
static void func_fe6_0800B3F8(ProcPtr proc);
static void TalkOpenBubble_OnIdle(struct GenericProc * proc);
static void InitTalkTextWin(int x, int y, int width, int height);
static void TalkOpen_OnEnd(struct GenericProc * proc);
static void TalkOpen_InitBlend(struct GenericProc * proc);
static void TalkOpen_PutTalkBubble(struct GenericProc * proc);
static void TalkOpen_OnIdle(struct GenericProc * proc);
static void StartTalkOpen(int talk_face, ProcPtr parent);
static bool TalkHasCorrectBubble(void);
static int GetTalkFaceHPos(int talk_face);
static void SetTalkFaceDisp(int talk_face, int faceDisp);
static void SetTalkFaceMouthMove(int talk_face);
static void SetTalkFaceNoMouthMove(int talk_face);
static void TalkPutSpriteText_OnIdle(struct GenericProc * proc);
static void TalkPutSpriteText_OnEnd(struct GenericProc * proc);
static int GetStrTalkLen(char const * str, bool isBubbleOpen);
static void TalkDebug_Unk_0800CA88(struct GenericProc * proc);
static void TalkDebug_Unk_0800CAA0(struct GenericProc * proc);
static void TalkDebug_OnInit(struct GenericProc * proc);
static void TalkDebug_OnIdle(struct GenericProc * proc);
static void TalkBgSync(int bgflags);

#define TALK_TEXT_BY_LINE(line) (sTalkText + ((line) + sTalkSt->top_text_num) % sTalkSt->lines)

static struct TalkSt sTalkStObj;
static struct TalkSt * CONST_DATA sTalkSt = &sTalkStObj;

static struct Text sTalkText[3];
static int sTalkChoiceResult;
static struct Font sTalkFont;

struct ProcScr CONST_DATA ProcScr_TalkSkipListener[] =
{
    PROC_MARK(PROC_MARK_5),
    PROC_REPEAT(TalkSkipListener_OnIdle),

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Talk[] =
{
    PROC_MARK(PROC_MARK_5),
    PROC_ONEND(Talk_OnEnd),

    PROC_SLEEP(1),

    PROC_CALL(Talk_OnInit),
    PROC_REPEAT(Talk_OnIdle),

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_TalkLock[] =
{
    PROC_BLOCK,
};

struct ProcScr CONST_DATA ProcScr_TalkMoveFace[] =
{
    PROC_SLEEP(1),

    PROC_CALL(TalkFaceMove_OnInit),
    PROC_REPEAT(TalkFaceMove_OnIdle),

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_TalkPause[] =
{
    PROC_MARK(PROC_MARK_5),
    PROC_SLEEP(1),

    PROC_REPEAT(TalkPause_OnIdle),

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_TalkWaitForInput[] =
{
    PROC_MARK(PROC_MARK_5),
    PROC_SLEEP(8),

    PROC_REPEAT(TalkWaitForInput_OnIdle),
    PROC_SLEEP(1),

    PROC_END,
};

u16 CONST_DATA Sprite_PressKeyArrowA[] =
{
    1, OAM0_SHAPE_8x8 + OAM0_Y(0), OAM1_SIZE_8x8, OAM2_CHR(0),
};

u16 CONST_DATA Sprite_PressKeyArrowB[] =
{
    1, OAM0_SHAPE_8x8 + OAM0_Y(1), OAM1_SIZE_8x8, OAM2_CHR(0),
};

u16 CONST_DATA Sprite_PressKeyArrowC[] =
{
    1, OAM0_SHAPE_8x8 + OAM0_Y(2), OAM1_SIZE_8x8, OAM2_CHR(0),
};

u16 const * CONST_DATA gPressKeyArrowSpriteLut[] =
{
    Sprite_PressKeyArrowA,
    Sprite_PressKeyArrowA,
    Sprite_PressKeyArrowA,
    Sprite_PressKeyArrowA,
    Sprite_PressKeyArrowA,
    Sprite_PressKeyArrowA,
    Sprite_PressKeyArrowA,
    Sprite_PressKeyArrowA,
    Sprite_PressKeyArrowA,
    Sprite_PressKeyArrowA,

    Sprite_PressKeyArrowB,

    Sprite_PressKeyArrowC,
    Sprite_PressKeyArrowC,
    Sprite_PressKeyArrowC,
    Sprite_PressKeyArrowC,

    Sprite_PressKeyArrowB,
};

struct ProcScr CONST_DATA ProcScr_TalkShiftClearAll[] =
{
    PROC_MARK(PROC_MARK_5),

    PROC_CALL(TalkShiftClearAll_OnInit),
    PROC_REPEAT(TalkShiftClearAll_OnIdle),

    PROC_END,
};

struct TalkChoiceEnt CONST_DATA gYesNoTalkChoice[] =
{
    { MSG_2BF, NULL }, // Yes
    { MSG_2C0, NULL }, // No
};

struct TalkChoiceEnt CONST_DATA gBuySellTalkChoice[] =
{
    { MSG_2C1, func_fe6_08095FC4 }, // Buy
    { MSG_2C2, func_fe6_08095FF8 }, // Sell
};

struct ProcScr CONST_DATA ProcScr_TalkChoice[] =
{
    PROC_SLEEP(8),

    PROC_REPEAT(TalkChoice_OnIdle),

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_TalkShiftClear[] =
{
    PROC_MARK(PROC_MARK_5),

    PROC_CALL(TalkShiftClear_OnInit),
    PROC_REPEAT(TalkShiftClear_OnIdle),

    PROC_SLEEP(1),

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Unk_085C3E7C[] =
{
    PROC_MARK(PROC_MARK_5),

    PROC_CALL(func_fe6_0800B3D4),
    PROC_SLEEP(0),

    PROC_CALL(func_fe6_0800B3F8),
    PROC_SLEEP(1),

    PROC_END,
};

int CONST_DATA gTalkPauseDurations[] = { 8, 16, 32, 64 };

struct ProcScr CONST_DATA ProcScr_TalkOpenBubble[] =
{
    PROC_REPEAT(TalkOpenBubble_OnIdle),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_TalkOpen[] =
{
    PROC_MARK(PROC_MARK_5),
    PROC_ONEND(TalkOpen_OnEnd),

    PROC_CALL(TalkOpen_InitBlend),
    PROC_REPEAT(TalkOpen_PutTalkBubble),

    PROC_REPEAT(TalkOpen_OnIdle),

    PROC_END,
};

int CONST_DATA gTalkFaceHPosLut[] = { 3, 6, 9, 21, 24, 27, -8, 38 };

u16 CONST_DATA Sprite_TalkTextFront[] =
{
    4,
    OAM0_SHAPE_64x32 + OAM0_Y(8), OAM1_SIZE_64x32 + OAM1_X(8),       OAM2_CHR(0x21),
    OAM0_SHAPE_64x32 + OAM0_Y(8), OAM1_SIZE_64x32 + OAM1_X(8 + 64),  OAM2_CHR(0x29),
    OAM0_SHAPE_64x32 + OAM0_Y(8), OAM1_SIZE_64x32 + OAM1_X(8 + 128), OAM2_CHR(0x31),
    OAM0_SHAPE_32x32 + OAM0_Y(8), OAM1_SIZE_32x32 + OAM1_X(8 + 192), OAM2_CHR(0x39),
};

u16 CONST_DATA Sprite_TalkTextBack[] =
{
    12,
    OAM0_SHAPE_64x32 + OAM0_Y(0),  OAM1_SIZE_64x32 + OAM1_X(0),   OAM2_CHR(0x00),
    OAM0_SHAPE_64x32 + OAM0_Y(0),  OAM1_SIZE_64x32 + OAM1_X(64),  OAM2_CHR(0x08),
    OAM0_SHAPE_64x32 + OAM0_Y(0),  OAM1_SIZE_64x32 + OAM1_X(128), OAM2_CHR(0x10),
    OAM0_SHAPE_64x32 + OAM0_Y(0),  OAM1_SIZE_64x32 + OAM1_X(192), OAM2_CHR(0x18),
    OAM0_SHAPE_32x16 + OAM0_Y(32), OAM1_SIZE_32x16 + OAM1_X(0),   OAM2_CHR(0x80),
    OAM0_SHAPE_32x16 + OAM0_Y(32), OAM1_SIZE_32x16 + OAM1_X(32),  OAM2_CHR(0x84),
    OAM0_SHAPE_32x16 + OAM0_Y(32), OAM1_SIZE_32x16 + OAM1_X(64),  OAM2_CHR(0x88),
    OAM0_SHAPE_32x16 + OAM0_Y(32), OAM1_SIZE_32x16 + OAM1_X(96),  OAM2_CHR(0x8C),
    OAM0_SHAPE_32x16 + OAM0_Y(32), OAM1_SIZE_32x16 + OAM1_X(128), OAM2_CHR(0x90),
    OAM0_SHAPE_32x16 + OAM0_Y(32), OAM1_SIZE_32x16 + OAM1_X(160), OAM2_CHR(0x94),
    OAM0_SHAPE_32x16 + OAM0_Y(32), OAM1_SIZE_32x16 + OAM1_X(192), OAM2_CHR(0x98),
    OAM0_SHAPE_32x16 + OAM0_Y(32), OAM1_SIZE_32x16 + OAM1_X(224), OAM2_CHR(0x9C),
};

struct ProcScr CONST_DATA ProcScr_TalkPutSpriteText[] =
{
    PROC_ONEND(TalkPutSpriteText_OnEnd),

    PROC_REPEAT(TalkPutSpriteText_OnIdle),

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_TalkDebug[] =
{
    PROC_CALL(LockGame),
    PROC_SLEEP(1),

    PROC_CALL(TalkDebug_Unk_0800CAA0),
    PROC_SLEEP(1),

    PROC_CALL(TalkDebug_OnInit),
    PROC_REPEAT(TalkDebug_OnIdle),

    PROC_CALL(UnlockGame),
    PROC_END,
};

void InitTalk(int chr, int lines, bool unpack_bubble)
{
    int i;

    InitTextFont(&sTalkFont, (u8 *) VRAM + GetBgChrOffset(0) + ((chr & 0x3FF) << 5), chr, BGPAL_TALK);
    SetInitTalkTextFont();

    sTalkSt->lines = lines;

    for (i = 0; i < lines; ++i)
    {
        InitText(sTalkText + i, 30);
        Text_SetColor(sTalkText + i, TEXT_COLOR_0456);
    }

    if (unpack_bubble)
    {
        Decompress(Img_TalkBubble, (u8 *) VRAM + GetBgChrOffset(1) + 0x200);
        ApplyPalette(Pal_TalkBubble, BGPAL_TALK_BUBBLE);
    }

    for (i = 0; i < TALK_FACE_COUNT; ++i)
        sTalkSt->faces[i] = NULL;
}

void InitSpriteTalk(int chr, int lines, int palid)
{
    int i;

    InitSpriteTextFont(&sTalkFont, (u8 *) VRAM + 0x10000 + ((chr & 0x3FF) << 5), palid);

    SetTextFont(&sTalkFont);
    SetTextFontGlyphs(TEXT_GLYPHS_TALK);

    ApplyPalette(Pal_Text+0x10, 0x10 + palid);

    PAL_OBJ_COLOR(palid, 4)  = RGB(7,  18, 28);
    PAL_OBJ_COLOR(palid, 14) = RGB(14, 13, 12);
    PAL_OBJ_COLOR(palid, 15) = RGB(31, 31, 31);

    sTalkSt->lines = lines;

    for (i = 0; i < lines; ++i)
    {
        InitSpriteText(sTalkText + i);

        SpriteText_DrawBackground(sTalkText + i);
        Text_SetColor(sTalkText + i, TEXT_COLOR_4DEF);
        Text_SetCursor(sTalkText + i, 4);
    }
}

void SetInitTalkTextFont(void)
{
    SetTextFont(&sTalkFont);
    InitTalkTextFont();
}

ProcPtr StartTalkExt(int x, int y, char const * str, ProcPtr parent)
{
    sTalkSt->x_text = x;
    sTalkSt->y_text = y;

    sTalkSt->str = str;
    sTalkSt->str_back = NULL;

    sTalkSt->print_color = TEXT_COLOR_0456;
    sTalkSt->line_active = 0;
    sTalkSt->top_text_num = 0;
    sTalkSt->print_delay = GetTextPrintDelay();
    sTalkSt->print_clock = 0;

    SetActiveTalkFace(TALK_FACE_NONE);

    sTalkSt->speak_talk_face = (i8) TALK_FACE_NONE;
    sTalkSt->put_lines = FALSE;
    sTalkSt->instant_print = FALSE;
    sTalkSt->unk_16 = 1;
    sTalkSt->unk_17 = 0;

    sTalkSt->flags = 0;

    sTalkSt->active_width = Div(7 + GetStrTalkLen(sTalkSt->str, FALSE), 8) + 2;

    if (parent)
        return SpawnProcLocking(ProcScr_Talk, parent);
    else
        return SpawnProc(ProcScr_Talk, PROC_TREE_3);
}

ProcPtr StartTalkMsg(int x, int y, int msg)
{
    return StartTalkExt(x, y, DecodeMsg(msg), NULL);
}

ProcPtr StartTalkMsgExt(int x, int y, int msg, ProcPtr parent)
{
    return StartTalkExt(x, y, DecodeMsg(msg), parent);
}

ProcPtr StartTalk(int x, int y, char const * str)
{
    return StartTalkExt(x, y, str, NULL);
}

void EndTalk(void)
{
    Proc_EndEach(ProcScr_Talk);
    EndPutTalkSpriteText();
}

void SetTalkLines(int lines)
{
    sTalkSt->lines = lines;
}

void SetTalkFlag(int flag)
{
    sTalkSt->flags |= flag;
}

void ClearTalkFlag(int flag)
{
    sTalkSt->flags &= ~flag;
}

int CheckTalkFlag(int flag)
{
    return sTalkSt->flags & flag;
}

void SetTalkPrintDelay(int print_delay)
{
    sTalkSt->print_delay = print_delay;

    if (sTalkSt->print_delay < 0)
        sTalkSt->print_delay = 0;
}

void SetTalkPrintColor(int color)
{
    int i;

    sTalkSt->print_color = color;

    for (i = 0; i < sTalkSt->lines; ++i)
        Text_SetColor(sTalkText + i, sTalkSt->print_color);
}

static void TalkSkipListener_OnIdle(ProcPtr proc)
{
    if (FindProc(ProcScr_TalkShiftClearAll) != NULL)
        return;

    if (FindProc(ProcScr_TalkShiftClear) != NULL)
        return;

    if (!CheckTalkFlag(TALK_FLAG_NOSKIP) && (gKeySt->pressed & (KEY_BUTTON_B | KEY_BUTTON_START)))
    {
        SetEventTalkSkipped();
        SetTalkFaceNoMouthMove(sTalkSt->active_talk_face);

        Proc_End(proc);
        EndTalk();

        return;
    }

    if (FindProc(ProcScr_TalkWaitForInput) != NULL)
        return;

    if (!CheckTalkFlag(TALK_FLAG_NOFAST) && (gKeySt->pressed & (KEY_BUTTON_A | KEY_BUTTON_B | KEY_DPAD_ANY)))
    {
        sTalkSt->instant_print = TRUE;
    }
}

static void Talk_OnInit(ProcPtr proc)
{
    if (!CheckTalkFlag(TALK_FLAG_SPRITE))
    {
        ApplySystemObjectsGraphics();

        SetBgOffset(0, 0, 0);
        SetBgOffset(1, 0, 0);
    }

    SpawnProc(ProcScr_TalkSkipListener, PROC_TREE_3);
}

static void Talk_OnIdle(ProcPtr proc)
{
    if (IsTalkFaceMoving())
        return;

    if (!sTalkSt->instant_print)
    {
        sTalkSt->print_clock++;

        if (sTalkSt->print_clock < sTalkSt->print_delay)
            return;
    }

    sTalkSt->print_clock = 0;

    for (;;)
    {
        SetTalkFaceNoMouthMove(sTalkSt->active_talk_face);

        switch (TalkInterpret(proc))
        {

        case 0:
            Proc_Break(proc);
            return;

        case 1:
            goto print_next_char;

        case 2:
            if (sTalkSt->instant_print || sTalkSt->print_delay <= 0)
            {
                break;
                goto reset_print_clock; // ..?
            }

            return;

        case 3:
        reset_print_clock:
            sTalkSt->print_clock = sTalkSt->print_delay;
            sTalkSt->instant_print = FALSE;

            return;

        default:
        print_next_char:
            if (!CheckTalkFlag(TALK_FLAG_SPRITE))
            {
                if (TalkPrepNextChar(proc) == TRUE)
                    return;
            }
            else
            {
                if (TalkSpritePrepNextChar(proc) == TRUE)
                    return;
            }

            sTalkSt->str = Text_DrawCharacter(TALK_TEXT_BY_LINE(sTalkSt->line_active), sTalkSt->str);

            if (!CheckTalkFlag(TALK_FLAG_SILENT))
            {
                if (CheckTalkFlag(TALK_FLAG_7))
                {
                    PlaySe(SONG_7A);
                }
                else
                {
                    if ((GetTextPrintDelay() == 1) && !(GetGameTime() & 1))
                        break;

                    PlaySe(SONG_6E);
                }
            }
        }

        if (!sTalkSt->instant_print && sTalkSt->print_delay > 0)
            return;
    }
}

static bool TalkPrepNextChar(ProcPtr proc)
{
    if (!TalkHasCorrectBubble() && sTalkSt->active_talk_face != TALK_FACE_NONE && !CheckTalkFlag(TALK_FLAG_NOBUBBLE))
    {
        sTalkSt->active_width = 2 + Div(7 + GetStrTalkLen(sTalkSt->str, FALSE), 8);
        ClearTalkBubble();

        StartTalkOpen(sTalkSt->active_talk_face, proc);
        SetTalkFaceLayer(sTalkSt->active_talk_face, CheckTalkFlag(TALK_FLAG_4));

        return TRUE;
    }

    if (sTalkSt->line_active >= sTalkSt->lines)
    {
        sTalkSt->instant_print = FALSE;
        SpawnProcLocking(ProcScr_TalkShiftClear, proc);

        return TRUE;
    }

    if (!sTalkSt->put_lines)
    {
        PutText(TALK_TEXT_BY_LINE(sTalkSt->line_active),
            gBg0Tm + TM_OFFSET(sTalkSt->x_text, sTalkSt->y_text + sTalkSt->line_active*2));

        TalkBgSync(BG0_SYNC_BIT);

        sTalkSt->put_lines = TRUE;
    }

    if (sTalkSt->unk_16 != 0)
        SetTalkFaceMouthMove(sTalkSt->active_talk_face);

    return FALSE;
}

static bool TalkSpritePrepNextChar(ProcPtr proc)
{
    if (sTalkSt->line_active >= sTalkSt->lines)
    {
        sTalkSt->instant_print = FALSE;
        SpawnProcLocking(ProcScr_Unk_085C3E7C, proc);

        return TRUE;
    }

    if (!sTalkSt->put_lines)
        sTalkSt->put_lines = TRUE;

    return FALSE;
}

static void LockTalk(ProcPtr proc)
{
    SpawnProcLocking(ProcScr_TalkLock, proc);
}

bool IsTalkLocked(void)
{
    return Proc_Exists(ProcScr_TalkLock);
}

void ResumeTalk(void)
{
    Proc_EndEach(ProcScr_TalkLock);
}

static int TalkInterpret(ProcPtr proc)
{
    struct GenericProc * gproc;
    int i;

    for (;TRUE;)
    {
        switch (*sTalkSt->str)
        {

        case 0x12:
        case 0x13:
        case 0x14:
            sTalkSt->str++;

            sTalkSt->active_width = 2 + Div(7 + GetStrTalkLen(sTalkSt->str, TalkHasCorrectBubble()), 8);

            continue;

        }

        break;
    }

    switch (*sTalkSt->str)
    {

    case 0x81:
        if (sTalkSt->str[1] == 0x40)
        {
            sTalkSt->str += 2;

            Text_Skip(TALK_TEXT_BY_LINE(sTalkSt->line_active), 6);

            if (sTalkSt->instant_print || sTalkSt->print_delay <= 0)
            {
                return 2;
            }

            gproc = SpawnProcLocking(ProcScr_TalkPause, proc);
            gproc->unk64 = GetTalkPauseCmdDuration(4);

            return 3;
        }

        return 1;

    case 0x00: // end
        if (sTalkSt->str_back == NULL)
            return 0;

        sTalkSt->str = sTalkSt->str_back;
        sTalkSt->str_back = NULL;

        return TalkInterpret(proc);

    case 0x01: // newline
        if (sTalkSt->put_lines == TRUE || sTalkSt->line_active == 1)
        {
            sTalkSt->line_active++;
        }

        sTalkSt->put_lines = FALSE;

        sTalkSt->str++;
        return 2;

    case 0x02:
        if (!CheckTalkFlag(TALK_FLAG_INSTANTSHIFT))
            SpawnProcLocking(ProcScr_TalkShiftClearAll, proc);
        else
            ClearTalkText();

        sTalkSt->str++;
        return 3;

    case 0x03: // wait for input to continue
        StartTalkWaitForInput(proc,
            sTalkSt->x_text*8 + Text_GetCursor(TALK_TEXT_BY_LINE(sTalkSt->line_active)) + 4,
            sTalkSt->y_text*8 + sTalkSt->line_active*16 + 8);

        sTalkSt->str++;
        return 3;

    case 0x04 ... 0x07:
        if (sTalkSt->instant_print)
        {
            sTalkSt->str++;
            return 2;
        }

        gproc = SpawnProcLocking(ProcScr_TalkPause, proc);
        gproc->unk64 = GetTalkPauseCmdDuration (* sTalkSt->str);

        sTalkSt->str++;
        return 3;

    case 0x15:
        ClearTalkBubble();

        sTalkSt->str++;
        return 3;

    case 0x16:
        sTalkSt->unk_16 = 1 - sTalkSt->unk_16;

        sTalkSt->str++;
        return 3;

    case 0x17:
        sTalkSt->unk_17 = 1 - sTalkSt->unk_17;

        sTalkSt->str++;
        return 3;

    case 0x10:
        for (;TRUE;)
        {
            switch (*sTalkSt->str)
            {

            case 0x08 ... 0x0F:
                SetActiveTalkFace (* sTalkSt->str - 0x08);

                sTalkSt->str++;
                continue;

            case 0x10:
                sTalkSt->str++;

                TalkInterpretNewFace(proc);

                sTalkSt->str++;
                sTalkSt->str++;

                continue;

            }

            break;
        }

        return 3;

    case 0x11:
        if (TalkHasCorrectBubble())
            ClearTalkBubble();

        StartFaceFadeOut(sTalkSt->faces[sTalkSt->active_talk_face]);
        sTalkSt->faces[sTalkSt->active_talk_face] = NULL;

        sTalkSt->str++;

        StartTemporaryLock(proc, 16);

        return 3;

    case 0x1C:
        if (CheckTalkFlag(TALK_FLAG_4))
            ClearTalkFlag(TALK_FLAG_4);
        else
            SetTalkFlag(TALK_FLAG_4);

        sTalkSt->str++;
        return 3;

    case 0x08 ... 0x0F:
        SetTalkFaceNoMouthMove(sTalkSt->active_talk_face);
        SetActiveTalkFace (* sTalkSt->str - 8);

        sTalkSt->str++;
        return 3;

    case 0x18: // Yes/No choice (default: Yes)
        StartTalkChoice(gYesNoTalkChoice,
            TALK_TEXT_BY_LINE(sTalkSt->line_active),
            gBg0Tm + TM_OFFSET(sTalkSt->x_text, sTalkSt->y_text + 2*sTalkSt->line_active),
            1, sTalkSt->print_color, proc);

        sTalkSt->str++;
        return 3;

    case 0x19: // Yes/No choice (default: No)
        StartTalkChoice(gYesNoTalkChoice,
            TALK_TEXT_BY_LINE(sTalkSt->line_active),
            gBg0Tm + TM_OFFSET(sTalkSt->x_text, sTalkSt->y_text + 2*sTalkSt->line_active),
            2, sTalkSt->print_color, proc);

        sTalkSt->str++;
        return 3;

    case 0x1A:
        StartTalkChoice(gBuySellTalkChoice,
            TALK_TEXT_BY_LINE(sTalkSt->line_active),
            gBg0Tm + TM_OFFSET(sTalkSt->x_text, sTalkSt->y_text + 2*sTalkSt->line_active),
            1, sTalkSt->print_color, proc);

        sTalkSt->str++;
        return 3;

    case 0x1B:
        StartTalkChoice(gBuySellTalkChoice,
            TALK_TEXT_BY_LINE(sTalkSt->line_active),
            gBg0Tm + TM_OFFSET(sTalkSt->x_text, sTalkSt->y_text + 2*sTalkSt->line_active),
            2, sTalkSt->print_color, proc);

        sTalkSt->str++;
        return 3;

    case 0x80:
        switch (*++sTalkSt->str)
        {

        case 0 ... 3:
            sTalkSt->print_color = *++sTalkSt->str;

            for (i = 0; i < sTalkSt->lines; ++i)
                Text_SetColor(sTalkText + i, sTalkSt->print_color);

            sTalkSt->str++;
            return 3;

        case 4:
            LockTalk(proc);

            sTalkSt->str++;
            return 3;

        case 5:
            NumberToString(sTalkSt->number, sTalkSt->buf_number_str);

            sTalkSt->str++;

            sTalkSt->str_back = sTalkSt->str;
            sTalkSt->str = sTalkSt->buf_number_str;

            return TalkInterpret(proc);

        case 6:
            sTalkSt->str++;

            sTalkSt->str_back = sTalkSt->str;
            sTalkSt->str = sTalkSt->buf_unk_str;

            return TalkInterpret(proc);

        case 8:
            sTalkSt->str++;
            return 3;

        case 7:
            sTalkSt->str++;
            return 3;

        case 10 ... 17:
            MoveTalkFace(sTalkSt->active_talk_face, *sTalkSt->str - 10);
            SetActiveTalkFace (* sTalkSt->str - 10);

            sTalkSt->str++;

            return 3;

        default:
            return 0;

        }

    default:
        return 1;

    }

    return 3;
}

void SetActiveTalkFace(int talk_face)
{
    sTalkSt->active_talk_face = talk_face;
}

static void TalkInterpretNewFace(ProcPtr proc)
{
    int faceDisp = 0;
    int fid;

    if (sTalkSt->active_talk_face == TALK_FACE_NONE)
        SetActiveTalkFace(TALK_FACE_1);

    if (IsBattleDeamonActive())
        SetFightEventFaceConfig();
    else
        faceDisp |= FACE_DISP_KIND(FACE_96x80);

    if (GetTalkFaceHPos(sTalkSt->active_talk_face) <= 14)
        faceDisp |= FACE_DISP_FLIPPED;
    else
        faceDisp |= 0;

    fid = (sTalkSt->str[0]);
    fid = (sTalkSt->str[1] * 0x100) + fid;

    if (fid == UINT16_MAX)
        fid = GetUnitFid(gActiveUnit);
    else
        fid = fid - 0x100;

    sTalkSt->faces[sTalkSt->active_talk_face] = StartFaceAuto(fid,
        GetTalkFaceHPos(sTalkSt->active_talk_face)*8, 80, faceDisp);

    StartFaceFadeIn(sTalkSt->faces[sTalkSt->active_talk_face]);

    SetTalkFaceLayer(sTalkSt->active_talk_face, CheckTalkFlag(TALK_FLAG_4));
    StartTemporaryLock(proc, 8);
}

void StartTalkFace(int fid, int x, int y, int disp, int talk_face)
{
    sTalkSt->faces[talk_face] = StartFaceAuto(fid, x, y, disp);
}

static int GetFaceIdByX(int x)
{
    int i;

    for (i = 0; i < 4; ++i)
    {
        if (gFaces[i] == NULL)
            continue;

        if (gFaces[i]->x_disp == x)
            return i;
    }

    return -1;
}

static void SetTalkFaceLayer(int talk_face, int toBack)
{
    int i;

    int argLayer, otherLayer;
    int iStart, iEnd;

    if (toBack)
    {
        argLayer = 6;
        otherLayer = 5;
    }
    else
    {
        argLayer = 5;
        otherLayer = 6;
    }

    switch (talk_face)
    {

    case TALK_FACE_0 ... TALK_FACE_2:
    default:
        iStart = TALK_FACE_0;
        iEnd = TALK_FACE_2;

        break;

    case TALK_FACE_3 ... TALK_FACE_5:
        iStart = TALK_FACE_3;
        iEnd = TALK_FACE_5;

        break;

    }

    for (i = iStart; i <= iEnd; ++i)
    {
        if (!sTalkSt->faces[i])
            continue;

        if (i == talk_face)
            sTalkSt->faces[i]->sprite_layer = argLayer;
        else
            sTalkSt->faces[i]->sprite_layer = otherLayer;
    }
}

static void MoveTalkFace(int talkFaceFrom, int talkFaceTo)
{
    struct FaceProc * face;
    bool isSwap = FALSE;

    if (sTalkSt->faces[talkFaceTo] != NULL)
    {
        isSwap = TRUE;
        StartTalkFaceMove(talkFaceTo, talkFaceFrom, isSwap);
    }

    StartTalkFaceMove(talkFaceFrom, talkFaceTo, isSwap);

    face = sTalkSt->faces[talkFaceFrom];
    sTalkSt->faces[talkFaceFrom] = sTalkSt->faces[talkFaceTo];
    sTalkSt->faces[talkFaceTo] = face;
}

static bool IsTalkFaceMoving(void)
{
    if (FindProc(ProcScr_TalkMoveFace) != NULL)
        return TRUE;

    return FALSE;
}

static void StartTalkFaceMove(int talkFaceFrom, int talkFaceTo, bool isSwap)
{
    struct GenericProc * proc;

    int slot = GetFaceIdByX(GetTalkFaceHPos(talkFaceFrom) * 8);

    if (slot == -1)
        return;

    proc = SpawnProc(ProcScr_TalkMoveFace, gFaces[slot]);

    proc->unk64 = slot;
    proc->unk66 = talkFaceTo;
    proc->unk68 = gFaces[slot]->x_disp;
    proc->unk6A = isSwap;
}

static void TalkFaceMove_OnInit(struct GenericProc * proc)
{
    proc->unk58 = 0;

    if (((proc->unk68 - GetTalkFaceHPos(proc->unk66)*8) < 0)
        ? (GetTalkFaceHPos(proc->unk66)*8 - proc->unk68) > 24
        : (proc->unk68 - GetTalkFaceHPos(proc->unk66)*8) > 24)
    {
        proc->unk5C = 32;
    }
    else
    {
        proc->unk5C = 16;
    }
}

static void TalkFaceMove_OnIdle(struct GenericProc * proc)
{
    if (proc->unk5C > 16)
    {
        if (proc->unk58 == proc->unk5C / 8)
            gFaces[proc->unk64]->y_disp++;

        if (proc->unk58 == proc->unk5C / 2)
            gFaces[proc->unk64]->y_disp--;

        if (proc->unk58 == proc->unk5C * 5 / 8)
            gFaces[proc->unk64]->y_disp++;
    }
    else
    {
        if (proc->unk58 == proc->unk5C / 2)
            gFaces[proc->unk64]->y_disp++;
    }

    if (proc->unk58 >= proc->unk5C)
    {
        gFaces[proc->unk64]->y_disp--;
        Proc_Break(proc);
    }
    else
    {
        gFaces[proc->unk64]->x_disp = Interpolate(INTERPOLATE_RSQUARE,
            proc->unk68, GetTalkFaceHPos(proc->unk66)*8,
            proc->unk58++, proc->unk5C);
    }
}

static void Talk_OnEnd(ProcPtr proc)
{
    Proc_EndEach(ProcScr_TalkSkipListener);
    Proc_EndEach(ProcScr_TalkShiftClearAll);
}

static void TalkPause_OnIdle(struct GenericProc * proc)
{
    if (proc->unk64 == 0)
    {
        Proc_Break(proc);
        return;
    }

    proc->unk64--;
}

static void TalkWaitForInput_OnIdle(struct GenericProc * proc)
{
    int frame = (GetGameTime() / 2) % 0x10;

    if (!CheckTalkFlag(TALK_FLAG_SPRITE))
    {
        PutSprite(2,
            proc->unk64, proc->unk66,
            gPressKeyArrowSpriteLut[frame], OAM2_CHR(4));
    }
    else
    {
        PutSprite(0,
            proc->unk64, proc->unk66,
            gPressKeyArrowSpriteLut[frame], OAM2_CHR(0x321) + OAM2_PAL(11)); // TODO: Chr/Pal constants
    }

    if (gKeySt->pressed & (KEY_BUTTON_A | KEY_BUTTON_B | KEY_DPAD_ANY))
        Proc_Break(proc);
}

void func_fe6_0800AD58(struct GenericProc * proc)
{
}

void StartTalkWaitForInput(ProcPtr parent, int x, int y)
{
    struct GenericProc * proc = SpawnProcLocking(ProcScr_TalkWaitForInput, parent);

    proc->unk64 = x;
    proc->unk66 = y;
}

static void TalkShiftClearAll_OnInit(struct GenericProc * proc)
{
    TmFillRect(gBg0Tm + TM_OFFSET(sTalkSt->x_text, sTalkSt->y_text + 4),
        sTalkSt->active_width-2, sTalkSt->lines*2, 0);

    TalkBgSync(BG0_SYNC_BIT);

    proc->unk64 = 0;

    if (sTalkSt->line_active == 0)
    {
        proc->unk66 = 16;
    }
    else if (sTalkSt->line_active + 1 >= sTalkSt->lines)
    {
        proc->unk66 = sTalkSt->lines * 16;
    }
    else
    {
        proc->unk66 = (sTalkSt->line_active + 1) * 16;
    }
}

static void TalkShiftClearAll_OnIdle(struct GenericProc * proc)
{
    proc->unk64 = proc->unk64 + 1;

    SetBgOffset(0, 0, proc->unk64);

    if (proc->unk64 >= proc->unk66)
    {
        SetBgOffset(0, 0, 0);
        ClearPutTalkText();

        Proc_Break(proc);
    }
}

static void StartTalkChoice(struct TalkChoiceEnt const * choices, struct Text * text, u16 * tm, int defaultChoice, int color, ProcPtr parent)
{
    struct TalkChoiceProc * proc;

    int x = Text_GetCursor(text) + 16;

    Text_InsertDrawString(text, x,      color, DecodeMsg(choices[0].msg));
    Text_InsertDrawString(text, x + 40, color, DecodeMsg(choices[1].msg));

    PutText(text, tm);

    TalkBgSync(BG0_SYNC_BIT);

    proc = SpawnProcLocking(ProcScr_TalkChoice, parent);

    proc->selectedChoice = defaultChoice;

    proc->x_disp = (((tm - gBg0Tm) & 0x1F) * 8) - gDispIo.bg_off[0].x + x;
    proc->y_disp = (((tm - gBg0Tm) / 0x20) * 8) - gDispIo.bg_off[0].y;

    proc->choices = choices;

    if (proc->choices[defaultChoice - 1].onSwitch)
        proc->choices[defaultChoice - 1].onSwitch();
}

void TalkChoice_OnIdle(struct TalkChoiceProc * proc)
{
    if (gKeySt->pressed & KEY_BUTTON_B)
    {
        PlaySe(SONG_6B);

        sTalkChoiceResult = 0;

        Proc_Break(proc);
        return;
    }
    else if (gKeySt->pressed & KEY_BUTTON_A)
    {
        PlaySe(SONG_6A);

        sTalkChoiceResult = proc->selectedChoice;

        Proc_Break(proc);
        return;
    }

    if ((gKeySt->pressed & KEY_DPAD_LEFT) && (proc->selectedChoice == 2))
    {
        PlaySe(SONG_67);

        proc->selectedChoice = 1;

        if (proc->choices[0].onSwitch)
            proc->choices[0].onSwitch();
    }

    if ((gKeySt->pressed & KEY_DPAD_RIGHT) && (proc->selectedChoice == 1))
    {
        PlaySe(SONG_67);

        proc->selectedChoice = 2;

        if (proc->choices[1].onSwitch)
            proc->choices[1].onSwitch();
    }

    PutUiHand(proc->x_disp + (proc->selectedChoice - 1) * 40 - 4, proc->y_disp);
}

static void TalkShiftClear_OnInit(struct GenericProc * proc)
{
    TmFillRect(gBg0Tm + TM_OFFSET(sTalkSt->x_text, sTalkSt->y_text + 4),
        sTalkSt->active_width-2, sTalkSt->lines*2, 0);

    TalkBgSync(BG0_SYNC_BIT);

    proc->unk64 = 0;
}

static void TalkShiftClear_OnIdle(struct GenericProc * proc)
{
    proc->unk64 = proc->unk64 + 1;

    SetBgOffset(0, 0, proc->unk64);

    if (proc->unk64 >= 16)
    {
        int i;

        sTalkSt->line_active--;
        sTalkSt->top_text_num++;

        SetBgOffset(0, 0, 0);

        for (i = 0; i < sTalkSt->lines - 1; ++i)
        {
            PutText(TALK_TEXT_BY_LINE(i),
                gBg0Tm + TM_OFFSET(sTalkSt->x_text, sTalkSt->y_text + 2*i));
        }

        TmFillRect(gBg0Tm + TM_OFFSET(sTalkSt->x_text, sTalkSt->y_text + (sTalkSt->lines - 1)*2),
            sTalkSt->active_width - 2, 2, 0);

        ClearText(TALK_TEXT_BY_LINE(sTalkSt->lines - 1));
        Text_SetColor(TALK_TEXT_BY_LINE(sTalkSt->lines - 1), sTalkSt->print_color);

        TalkBgSync(BG0_SYNC_BIT);

        Proc_Break(proc);
    }
}

static void func_fe6_0800B3D4(ProcPtr proc)
{
    func_fe6_08094030(0x361, 0x1C, 0x44444444, proc);
}

static void func_fe6_0800B3F8(ProcPtr proc)
{
    sTalkSt->line_active--;

    SpriteText_DrawBackground(sTalkText + 1);

    Text_SetColor(sTalkText + 1, TEXT_COLOR_4DEF);
    Text_SetCursor(sTalkText + 1, 4);
}

static int GetTalkPauseCmdDuration(int cmd)
{
    return gTalkPauseDurations[cmd - 4];
}

void ClearTalkBubble(void)
{
    sTalkSt->speak_talk_face = (i8) TALK_FACE_NONE;

    TmFill(gBg1Tm, 0);
    TalkBgSync(BG1_SYNC_BIT);

    ClearPutTalkText();

    SetWinEnable(0, 0, 0);
}

void ClearPutTalkText(void)
{
    int i;

    TmFill(gBg0Tm, 0);
    TalkBgSync(BG0_SYNC_BIT);

    sTalkSt->line_active = 0;
    sTalkSt->put_lines = 0;
    sTalkSt->top_text_num = 0;

    for (i = 0; i < sTalkSt->lines; ++i)
    {
        ClearText(sTalkText + i);
        Text_SetColor(sTalkText + i, sTalkSt->print_color);
    }
}

void ClearTalkText(void)
{
    int i;

    sTalkSt->line_active = 0;
    sTalkSt->put_lines = 0;
    sTalkSt->top_text_num = 0;

    for (i = 0; i < sTalkSt->lines; ++i)
    {
        ClearText(sTalkText + i);
        Text_SetColor(sTalkText + i, sTalkSt->print_color);
    }
}

static void PutTalkBubble(int xAnchor, int yAnchor, int width, int height)
{
    int xTail;
    int kind;
    int tmp;
    int x, y;

    xTail = 0;

    x = 0;
    y = 0;

    TmFill(gBg1Tm, 0);

    if (xAnchor < 16)
        kind = 0;
    else
        kind = 1;

    if (IsBattleDeamonActive())
        kind += 2;

    y = yAnchor - height + 1;

    switch (kind)
    {

    case 0:
        xTail = xAnchor + 3;

        tmp = xTail - width / 2;

        if (tmp <= 0)
            x = 1;
        else
            x = tmp;

        break;

    case 1:
        xTail = xAnchor - 5;

        tmp = xTail + (width + 1) / 2;

        if (tmp > 29)
            x = 29 - width;
        else
            x = xTail - width / 2;

        break;

    case 2:
        x = 9;
        y = 14;

        width = 20;
        xTail = x - 1;
        yAnchor = y + 2;

        break;

    case 3:
        x = 1;
        y = 14;

        width = 20;
        xTail = x + width - 1;
        yAnchor = y + 2;

        break;
    }

    sTalkSt->x_text = x + 1;
    sTalkSt->y_text = y + 1;

    PutTalkBubbleTm(x, y, width, height);
    PutTalkBubbleTail(xTail, yAnchor, kind);
    InitTalkTextWin(x, y, width, height);

    StartOpenTalkBubble();

    TalkBgSync(BG1_SYNC_BIT);
}

static void StartOpenTalkBubble(void)
{
    struct GenericProc * proc = SpawnProc(ProcScr_TalkOpenBubble, PROC_TREE_3);
    proc->unk64 = 0;
}

static void TalkOpenBubble_OnIdle(struct GenericProc * proc)
{
    u8 const * img_list[] =
    {
        Img_TalkBubbleOpeningA,
        Img_TalkBubbleOpeningB,
        Img_TalkBubbleOpeningC,
        Img_TalkBubbleOpeningD,
        Img_TalkBubbleOpeningE,
        Img_TalkBubble,
        NULL,
    };

    if ((proc->unk64++) & 1)
        return;

    Decompress(img_list[proc->unk64 >> 1],
        (u8 *) VRAM + GetBgChrOffset(1) + 0x10 * CHR_SIZE);

    if (img_list[(proc->unk64 >> 1) + 1] == NULL)
        Proc_Break(proc);
}

static void InitTalkTextWin(int x, int y, int width, int height)
{
    SetWinEnable(1, 0, 0);

    SetWin0Box((x + 1) * 8, (y + 1) * 8, (x + width - 1) * 8, (y + height - 1) * 8);

    SetWin0Layers(1, 1, 1, 1, 1);
    SetWOutLayers(0, 1, 1, 1, 1);
}

void PutTalkBubbleTail(int x, int y, int kind)
{
    switch (kind)
    {

    case 0:
        gBg1Tm[TM_OFFSET(x,     y)]     = TILEREF(0x10 + 4, BGPAL_TALK_BUBBLE);
        gBg1Tm[TM_OFFSET(x + 1, y)]     = TILEREF(0x10 + 4, BGPAL_TALK_BUBBLE) + TILE_HFLIP;
        gBg1Tm[TM_OFFSET(x,     y + 1)] = TILEREF(0x10 + 6, BGPAL_TALK_BUBBLE) + TILE_HFLIP;
        gBg1Tm[TM_OFFSET(x + 1, y + 1)] = TILEREF(0x10 + 5, BGPAL_TALK_BUBBLE) + TILE_HFLIP;

        break;

    case 1:
        gBg1Tm[TM_OFFSET(x,     y)]     = TILEREF(0x10 + 4, BGPAL_TALK_BUBBLE);
        gBg1Tm[TM_OFFSET(x + 1, y)]     = TILEREF(0x10 + 4, BGPAL_TALK_BUBBLE) + TILE_HFLIP;
        gBg1Tm[TM_OFFSET(x,     y + 1)] = TILEREF(0x10 + 5, BGPAL_TALK_BUBBLE);
        gBg1Tm[TM_OFFSET(x + 1, y + 1)] = TILEREF(0x10 + 6, BGPAL_TALK_BUBBLE);

        break;

    case 2:
        gBg1Tm[TM_OFFSET(x,     y)]     = TILEREF(0x10 + 8, BGPAL_TALK_BUBBLE) + TILE_HFLIP;
        gBg1Tm[TM_OFFSET(x,     y + 1)] = TILEREF(0x10 + 9, BGPAL_TALK_BUBBLE) + TILE_HFLIP;
        gBg1Tm[TM_OFFSET(x + 1, y)]     = TILEREF(0x10 + 7, BGPAL_TALK_BUBBLE) + TILE_HFLIP;
        gBg1Tm[TM_OFFSET(x + 1, y + 1)] = TILEREF(0x10 + 7, BGPAL_TALK_BUBBLE) + TILE_HFLIP + TILE_VFLIP;

        break;

    case 3:
        gBg1Tm[TM_OFFSET(x,     y)]     = TILEREF(0x10 + 7, BGPAL_TALK_BUBBLE);
        gBg1Tm[TM_OFFSET(x,     y + 1)] = TILEREF(0x10 + 7, BGPAL_TALK_BUBBLE) + TILE_VFLIP;
        gBg1Tm[TM_OFFSET(x + 1, y)]     = TILEREF(0x10 + 8, BGPAL_TALK_BUBBLE);
        gBg1Tm[TM_OFFSET(x + 1, y + 1)] = TILEREF(0x10 + 9, BGPAL_TALK_BUBBLE);

        break;

    }
}

void PutTalkBubbleTm(int x, int y, int width, int height)
{
    int i, j;

    width = width - 1;
    height = height - 1;

    for (i = x; i < x + width; ++i)
    {
        gBg1Tm[TM_OFFSET(i, y)]          = TILEREF(0x10 + 1, BGPAL_TALK_BUBBLE);
        gBg1Tm[TM_OFFSET(i, y + height)] = TILEREF(0x10 + 1, BGPAL_TALK_BUBBLE) + TILE_VFLIP;
    }

    for (i = y; i < y + height; ++i)
    {
        gBg1Tm[TM_OFFSET(x, i)]         = TILEREF(0x10 + 2, BGPAL_TALK_BUBBLE);
        gBg1Tm[TM_OFFSET(x + width, i)] = TILEREF(0x10 + 2, BGPAL_TALK_BUBBLE) + TILE_HFLIP;
    }

    for (i = x + 1; i < x + width; ++i)
        for (j = y + 1; j < y + height; ++j)
            gBg1Tm[TM_OFFSET(i, j)] = TILEREF(0x10 + 3, BGPAL_TALK_BUBBLE);

    gBg1Tm[TM_OFFSET(x,         y)]          = TILEREF(0x10 + 0, BGPAL_TALK_BUBBLE);
    gBg1Tm[TM_OFFSET(x + width, y)]          = TILEREF(0x10 + 0, BGPAL_TALK_BUBBLE) + TILE_HFLIP;
    gBg1Tm[TM_OFFSET(x,         y + height)] = TILEREF(0x10 + 0, BGPAL_TALK_BUBBLE) + TILE_VFLIP;
    gBg1Tm[TM_OFFSET(x + width, y + height)] = TILEREF(0x10 + 0, BGPAL_TALK_BUBBLE) + TILE_HFLIP + TILE_VFLIP;
}

static void TalkOpen_OnEnd(struct GenericProc * proc)
{
}

static void TalkOpen_InitBlend(struct GenericProc * proc)
{
    proc->unk58 = 0;

    SetBlendTargetA(0, 1, 0, 0, 0);
    SetBlendTargetB(0, 0, 1, 1, 1);

    SetBlendBackdropB(1);

    gDispIo.win_ct.win0_enable_blend = 1;
    gDispIo.win_ct.wout_enable_blend = 1;

    SetBlendAlpha(0, 0x10);
}

static void TalkOpen_PutTalkBubble(struct GenericProc * proc)
{
    PutTalkBubble(proc->unk64, proc->unk66, proc->unk68, proc->unk6A);
    Proc_Break(proc);
}

static void TalkOpen_OnIdle(struct GenericProc * proc)
{
    int var;

    proc->unk58++;

    var = Interpolate(INTERPOLATE_RSQUARE, -30, 0, proc->unk58, 12);

    SetBgOffset(1, 0, var/2);
    SetBlendAlpha(var/2 + 0x10, 1 - var/2);

    if (proc->unk58 == 12)
        Proc_Break(proc);
}

static void StartTalkOpen(int talk_face, ProcPtr parent)
{
    struct GenericProc * proc = SpawnProcLocking(ProcScr_TalkOpen, parent);

    proc->unk64 = GetTalkFaceHPos(talk_face);
    proc->unk66 = 8;

    proc->unk68 = sTalkSt->active_width;
    proc->unk6A = 6;

    if (proc->unk64 < 0)
        proc->unk64 = 0;

    if (proc->unk64 > 29)
        proc->unk64 = 30;

    sTalkSt->speak_talk_face = talk_face;
    sTalkSt->speak_width = sTalkSt->active_width;
}

static bool TalkHasCorrectBubble(void)
{
    if (sTalkSt->speak_talk_face == sTalkSt->active_talk_face && sTalkSt->speak_width == sTalkSt->active_width)
        return TRUE;

    return FALSE;
}

int GetTalkFaceHPos(int talk_face)
{
    if (IsBattleDeamonActive())
        return 4;

    return gTalkFaceHPosLut[talk_face];
}

static void SetTalkFaceDisp(int talk_face, int faceDisp)
{
    int lut[] = { 0, FACE_DISP_SMILE };
    int disp;

    if (talk_face == TALK_FACE_NONE)
        return;

    disp = GetFaceDisp(sTalkSt->faces[talk_face]);
    disp &= ~(FACE_DISP_SMILE | FACE_DISP_TALK_1 | FACE_DISP_TALK_2);

    SetFaceDisp(sTalkSt->faces[talk_face], disp | faceDisp | lut[sTalkSt->unk_17]);
}

static void SetTalkFaceMouthMove(int talk_face)
{
    SetTalkFaceDisp(talk_face, FACE_DISP_TALK_1);
}

static void SetTalkFaceNoMouthMove(int talk_face)
{
    SetTalkFaceDisp(talk_face, 0);
}

bool IsTalkActive(void)
{
    return Proc_Exists(ProcScr_Talk);
}

bool FaceExists(void)
{
    return Proc_Exists(ProcScr_Face);
}

int GetTalkChoiceResult(void)
{
    return sTalkChoiceResult;
}

void SetTalkNumber(int number)
{
    sTalkSt->number = number;
}

void SetTalkUnkStr(char const * str)
{
    strcpy(sTalkSt->buf_unk_str, str);
}

void PrintStringToTexts(struct Text ** texts, char const * str, int x, int y)
{
    int uh, line;

    line = 0;

    for (;;)
    {
        uh = 0;

        switch (*str)
        {

        case 0: // end
            uh += 1;
            break;

        case 1: // newline
            PutText(texts[line], gBg0Tm + TM_OFFSET(x, line*2 + y));

            line += 1;
            str++;

            break;

        }

        if (uh != 0)
            break;

        str = Text_DrawCharacter(texts[line], str);

        continue;
        break; // ..?
    }

    PutText(texts[line], gBg0Tm + TM_OFFSET(x, line*2 + y));
}

static void TalkPutSpriteText_OnIdle(struct GenericProc * proc)
{
    PutSprite(3,
        proc->x, proc->y, Sprite_TalkTextBack,
        OAM2_CHR(proc->unk52) | OAM2_PAL(proc->unk64));

    PutSprite(3,
        proc->x, proc->y, Sprite_TalkTextFront,
        OAM2_CHR(proc->unk52) | OAM2_PAL(sTalkFont.palid));
}

static void ClearHBlankA(void)
{
    SetOnHBlankA(NULL);
}

static void TalkPutSpriteText_OnEnd(struct GenericProc * proc)
{
    CallDelayed(ClearHBlankA, 1);
}

void StartPutTalkSpriteText(int x, int y, int chr, int palid, ProcPtr parent)
{
    struct GenericProc * proc;

    proc = FindProc(ProcScr_TalkPutSpriteText);

    if (!proc)
        proc = SpawnProc(ProcScr_TalkPutSpriteText, parent);

    proc->x = x;
    proc->y = y;
    proc->unk52 = chr;
    proc->unk64 = palid;

    InitScanlineEffect();
    func_fe6_0806A218(y + 7, y + 41, 0x44C3, 0x7247);
}

void EndPutTalkSpriteText(void)
{
    Proc_EndEach(ProcScr_TalkPutSpriteText);
}

int GetStrTalkLen(char const * str, bool isBubbleOpen)
{
    char buf[0x20];

    int speakFace = sTalkSt->speak_talk_face;
    int activeFace = sTalkSt->active_talk_face;

    i32 chrlen;

    int currentLineLen = 0;
    int maxLineLen = 24;

    for (;TRUE;)
    {
        switch (*str)
        {

        case 0x00: // end
            if (currentLineLen > maxLineLen)
                maxLineLen = currentLineLen;

            currentLineLen = 0;

            goto ret;

        case 0x01 ... 0x02:
            if (currentLineLen > maxLineLen)
                maxLineLen = currentLineLen;

            currentLineLen = 0;

            str++;
            break;

        case 0x03:
            currentLineLen += 12;
            str++;
            break;

        case 0x04 ... 0x07:
            str++;
            break;

        case 0x08 ... 0x0F:
            activeFace = *str - 0x08;
            str++;
            break;

        case 0x10:
            for (;TRUE;)
            {
                switch (*str)
                {

                case 0x08 ... 0x0F:
                    activeFace = *str - 0x08;
                    str++;
                    continue;

                case 0x10:
                    str++;
                    str++;
                    str++;

                    continue;

                }

                break;
            }

            break;

        case 0x11: 
            if (activeFace == speakFace)
            {
                if (currentLineLen > maxLineLen)
                    maxLineLen = currentLineLen;

                currentLineLen = 0;

                goto ret;
            }

            str++;
            break;

        case 0x12 ... 0x15:
            if (!isBubbleOpen)
            {
                if (currentLineLen > maxLineLen)
                    maxLineLen = currentLineLen;

                currentLineLen = 0;

                goto ret;
            }

            str++;
            break;

        case 0x16 ... 0x17:
            str++;
            break;

        case 0x18 ... 0x1B: // choice
            currentLineLen += 128;
            str++;
            break;

        case 0x1C:
            str++;
            break;

        case 0x80:
            str++;

            switch (*str)
            {

            case 0x00 ... 0x03:
                str++;
                break;

            case 0x04:
                str++;
                break;

            case 0x05:
                NumberToString(sTalkSt->number, buf);
                currentLineLen += GetStrTalkLen(buf, isBubbleOpen);

                str++;
                break;

            case 0x06:
                StringCopy(sTalkSt->buf_unk_str, buf); // BUG: arguments are reversed?
                currentLineLen += GetStrTalkLen(buf, isBubbleOpen);

                str++;
                break;

            case 0x07 ... 0x08:
                str++;
                break;

            case 0x09:
                str++;
                break;

            case 0x0A ... 0x11:
                activeFace = *str - 0x0A;
                str++;
                break;

            default:
                break;

            }

            break;

        case 0x81:
            if (str[1] == 0x40)
            {
                str += 2;
                currentLineLen += 6;
                break;
            }

            // fallthrough

        default:
            if ((activeFace != speakFace) && (activeFace != TALK_FACE_NONE))
            {
                if (!isBubbleOpen)
                {
                    isBubbleOpen = TRUE;
                    speakFace = activeFace;
                }
                else
                {
                    if (currentLineLen > maxLineLen)
                        maxLineLen = currentLineLen;

                    currentLineLen = 0;

                    goto ret;
                }
            }

            str = GetCharTextLen(str, &chrlen);
            currentLineLen += chrlen;
        }
    }

ret:
    return maxLineLen;
}

bool IsTalkDebugActive(void)
{
    return Proc_Exists(ProcScr_TalkDebug);
}

void StartTalkDebug(void)
{
    SpawnProc(ProcScr_TalkDebug, PROC_TREE_3);
}

static void TalkDebug_Unk_0800CA88(struct GenericProc * proc)
{
    proc->unk34 = 1;
}

static void TalkDebug_Unk_0800CAA0(struct GenericProc * proc)
{
    DisplayBackground(BACKGROUND_7);
}

static void TalkDebug_OnInit(struct GenericProc * proc)
{
    proc->x = 0;
    TalkDebug_Unk_0800CA88(proc);
}

static void TalkDebug_OnIdle(struct GenericProc * proc)
{
    int msg = proc->x;

    if (IsTalkLocked())
        ResumeTalk();

    if (IsEventRunning())
        return;

    if (proc->unk34 == 0)
    {
        DebugInitObj(-1, 9);
        TalkDebug_Unk_0800CA88(proc);
    }

    DebugPutObjNumber(112, 100, msg, 4);

    if (gKeySt->pressed & KEY_BUTTON_SELECT)
    {
        Proc_Break(proc);
        return;
    }

    if (gKeySt->repeated & KEY_DPAD_UP)
        msg++;

    if (gKeySt->repeated & KEY_DPAD_DOWN)
        msg--;

    if (gKeySt->repeated & KEY_DPAD_RIGHT)
        msg += 10;

    if (gKeySt->repeated & KEY_DPAD_LEFT)
        msg -= 10;

    if (gKeySt->repeated & KEY_BUTTON_R)
        msg += 100;

    if (gKeySt->repeated & KEY_BUTTON_L)
        msg -= 100;

    if (msg < 0)
        msg = 0;

    if (msg > MSG_COUNT - 1)
        msg = MSG_COUNT - 1;

    if (msg != proc->x)
    {
        ClearTalk();
        EndTalk();

        DebugInitObj(-1, 9);

        proc->x = msg;

        InitTalk(0x80, 2, TRUE);
        StartTalkMsg(1, 1, proc->x);

        SetTalkFlag(TALK_FLAG_INSTANTSHIFT);
        SetTalkFlag(TALK_FLAG_NOBUBBLE);
        SetTalkFlag(TALK_FLAG_NOSKIP);

        SetTalkPrintDelay(-1);

        TalkBgSync(BG0_SYNC_BIT);

        return;
    }

    if (gKeySt->pressed & KEY_BUTTON_A)
    {
        ClearTalk();
        EndTalk();

        proc->unk34 = 0;

        StartTalkEvent(proc->x);
    }
}

static void TalkBgSync(int bgflags)
{
    if (!CheckTalkFlag(TALK_FLAG_SPRITE))
        EnableBgSync(bgflags);
}
