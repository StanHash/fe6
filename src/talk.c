
#include "common.h"
#include "talk.h"

#include <string.h>

#include "armfunc.h"
#include "hardware.h"
#include "oam.h"
#include "sound.h"
#include "proc.h"
#include "debug-text.h"
#include "text.h"
#include "sprite.h"
#include "face.h"
#include "event.h"
#include "msg.h"
#include "util.h"
#include "bm.h"
#include "unit.h"

#include "constants/video-global.h"

struct TalkChoiceEnt
{
    u16 msg;
    Func onSwitch;
};

struct TalkChoiceProc
{
    /* 00 */ PROC_HEADER;

    /* 2A */ short selectedChoice;
    /* 2C */ short xDisp;
    /* 2E */ short yDisp;
    /* 30 */ int unused30;
    /* 34 */ struct TalkChoiceEnt const* choices;
};

static void TalkSkipListener_OnIdle(ProcPtr proc);
static void Talk_OnInit(ProcPtr proc);
static void Talk_OnIdle(ProcPtr proc);
static s8 TalkPrepNextChar(ProcPtr proc);
static s8 TalkSpritePrepNextChar(ProcPtr proc);
static void LockTalk(ProcPtr proc);
static int TalkInterpret(ProcPtr proc);
static void TalkInterpretNewFace(ProcPtr proc);
static int GetFaceIdByX(int x);
static void SetTalkFaceLayer(int talkFace, int toBack);
static void MoveTalkFace(int talkFaceFrom, int talkFaceTo);
static s8 IsTalkFaceMoving(void);
static void StartTalkFaceMove(int talkFaceFrom, int talkFaceTo, s8 isSwap);
static void TalkFaceMove_OnInit(struct GenericProc* proc);
static void TalkFaceMove_OnIdle(struct GenericProc* proc);
static void Talk_OnEnd(ProcPtr proc);
static void TalkPause_OnIdle(struct GenericProc* proc);
static void TalkWaitForInput_OnIdle(struct GenericProc* proc);
static void TalkShiftClearAll_OnInit(struct GenericProc* proc);
static void TalkShiftClearAll_OnIdle(struct GenericProc* proc);
static void StartTalkChoice(struct TalkChoiceEnt const* choices, struct Text* text, u16* tm, int defaultChoice, int color, ProcPtr parent);
static void TalkChoice_OnIdle(struct TalkChoiceProc* proc);
static void TalkShiftClear_OnInit(struct GenericProc* proc);
static void TalkShiftClear_OnIdle(struct GenericProc* proc);
static int GetTalkPauseCmdDuration(int cmd);
static void PutTalkBubble(int xAnchor, int yAnchor, int width, int height);
static void StartOpenTalkBubble(void);
static void sub_800B3D4(ProcPtr proc);
static void sub_800B3F8(ProcPtr proc);
static void TalkOpenBubble_OnIdle(struct GenericProc* proc);
static void InitTalkTextWin(int x, int y, int width, int height);
static void TalkOpen_OnEnd(struct GenericProc* proc);
static void TalkOpen_InitBlend(struct GenericProc* proc);
static void TalkOpen_PutTalkBubble(struct GenericProc* proc);
static void TalkOpen_OnIdle(struct GenericProc* proc);
static void StartTalkOpen(int talkFace, ProcPtr parent);
static s8 TalkHasCorrectBubble(void);
static int GetTalkFaceHPos(int talkFace);
static void SetTalkFaceDisp(int talkFace, int faceDisp);
static void SetTalkFaceMouthMove(int talkFace);
static void SetTalkFaceNoMouthMove(int talkFace);
static void TalkPutSpriteText_OnIdle(struct GenericProc* proc);
static void TalkPutSpriteText_OnEnd(struct GenericProc* proc);
static int GetStrTalkLen(char const* str, s8 isBubbleOpen);
static void TalkDebug_Unk_0800CA88(struct GenericProc* proc);
static void TalkDebug_Unk_0800CAA0(struct GenericProc* proc);
static void TalkDebug_OnInit(struct GenericProc* proc);
static void TalkDebug_OnIdle(struct GenericProc* proc);
static void TalkBgSync(int bgflags);

#define TALK_TEXT_BY_LINE(line) (sTalkText + ((line) + sTalkSt->topTextNum) % sTalkSt->lines)

static struct TalkSt sTalkStObj;
static struct TalkSt* CONST_DATA sTalkSt = &sTalkStObj;

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

u16 const* CONST_DATA gPressKeyArrowSpriteLut[] =
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
    { 0x2BF, NULL }, // Yes (TODO: msgids)
    { 0x2C0, NULL }, // No (TODO: msgids)
};

struct TalkChoiceEnt CONST_DATA gBuySellTalkChoice[] =
{
    { 0x2C1, sub_8095FC4 }, // Buy (TODO: msgids)
    { 0x2C2, sub_8095FF8 }, // Sell (TODO: msgids)
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

    PROC_CALL(sub_800B3D4),
    PROC_SLEEP(0),

    PROC_CALL(sub_800B3F8),
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

void InitTalk(int chr, int lines, s8 unpackBubble)
{
    int i;

    InitTextFont(&sTalkFont, (u8*) VRAM + GetBgChrOffset(0) + ((chr & 0x3FF) << 5), chr, BGPAL_TALK);
    SetInitTalkTextFont();

    sTalkSt->lines = lines;

    for (i = 0; i < lines; ++i)
    {
        InitText(sTalkText + i, 30);
        Text_SetColor(sTalkText + i, TEXT_COLOR_0456);
    }

    if (unpackBubble)
    {
        Decompress(Img_TalkBubble, (u8*) VRAM + GetBgChrOffset(1) + 0x200);
        ApplyPalette(Pal_TalkBubble, BGPAL_TALK_BUBBLE);
    }

    for (i = 0; i < TALK_FACE_COUNT; ++i)
        sTalkSt->faces[i] = NULL;
}

void InitSpriteTalk(int chr, int lines, int palid)
{
    int i;

    InitSpriteTextFont(&sTalkFont, (u8*) VRAM + 0x10000 + ((chr & 0x3FF) << 5), palid);

    SetTextFont(&sTalkFont);
    SetTextFontGlyphs(TEXT_GLYPHS_TALK);

    ApplyPalette(Pal_TalkText, 0x10 + palid);

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

ProcPtr StartTalkExt(int x, int y, char const* str, ProcPtr parent)
{
    sTalkSt->xText = x;
    sTalkSt->yText = y;

    sTalkSt->str = str;
    sTalkSt->strBack = NULL;

    sTalkSt->printColor = TEXT_COLOR_0456;
    sTalkSt->lineActive = 0;
    sTalkSt->topTextNum = 0;
    sTalkSt->printDelay = GetTextPrintDelay();
    sTalkSt->printClock = 0;

    SetActiveTalkFace(TALK_FACE_NONE);

    sTalkSt->speakTalkFace = (s8) TALK_FACE_NONE;
    sTalkSt->putLines = FALSE;
    sTalkSt->instantPrint = FALSE;
    sTalkSt->unk16 = 1;
    sTalkSt->unk17 = 0;

    sTalkSt->flags = 0;

    sTalkSt->activeWidth = Div(7 + GetStrTalkLen(sTalkSt->str, FALSE), 8) + 2;

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

ProcPtr StartTalk(int x, int y, char const* str)
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

void SetTalkPrintDelay(int printDelay)
{
    sTalkSt->printDelay = printDelay;

    if (sTalkSt->printDelay < 0)
        sTalkSt->printDelay = 0;
}

void SetTalkPrintColor(int color)
{
    int i;

    sTalkSt->printColor = color;

    for (i = 0; i < sTalkSt->lines; ++i)
        Text_SetColor(sTalkText + i, sTalkSt->printColor);
}

static void TalkSkipListener_OnIdle(ProcPtr proc)
{
    if (Proc_Find(ProcScr_TalkShiftClearAll) != NULL)
        return;

    if (Proc_Find(ProcScr_TalkShiftClear) != NULL)
        return;

    if (!CheckTalkFlag(TALK_FLAG_NOSKIP) && (gKeySt->pressed & (B_BUTTON | START_BUTTON)))
    {
        SetEventTalkSkipped();
        SetTalkFaceNoMouthMove(sTalkSt->activeTalkFace);

        Proc_End(proc);
        EndTalk();

        return;
    }

    if (Proc_Find(ProcScr_TalkWaitForInput) != NULL)
        return;

    if (!CheckTalkFlag(TALK_FLAG_NOFAST) && (gKeySt->pressed & (A_BUTTON | B_BUTTON | DPAD_ANY)))
    {
        sTalkSt->instantPrint = TRUE;
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

    if (!sTalkSt->instantPrint)
    {
        sTalkSt->printClock++;

        if (sTalkSt->printClock < sTalkSt->printDelay)
            return;
    }

    sTalkSt->printClock = 0;

    for (;;)
    {
        SetTalkFaceNoMouthMove(sTalkSt->activeTalkFace);

        switch (TalkInterpret(proc))
        {

        case 0:
            Proc_Break(proc);
            return;

        case 1:
            goto print_next_char;

        case 2:
            if (sTalkSt->instantPrint || sTalkSt->printDelay <= 0)
            {
                break;
                goto reset_print_clock; // ..?
            }

            return;

        case 3:
        reset_print_clock:
            sTalkSt->printClock = sTalkSt->printDelay;
            sTalkSt->instantPrint = FALSE;

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

            sTalkSt->str = Text_DrawCharacter(TALK_TEXT_BY_LINE(sTalkSt->lineActive), sTalkSt->str);

            if (!CheckTalkFlag(TALK_FLAG_SILENT))
            {
                if (CheckTalkFlag(TALK_FLAG_7))
                {
                    PlaySe(0x7A); // TODO: song ids
                }
                else
                {
                    if ((GetTextPrintDelay() == 1) && !(GetGameTime() & 1))
                        break;

                    PlaySe(0x6E); // TODO: song ids
                }
            }
        }

        if (!sTalkSt->instantPrint && sTalkSt->printDelay > 0)
            return;
    }
}

static Bool TalkPrepNextChar(ProcPtr proc)
{
    if (!TalkHasCorrectBubble() && sTalkSt->activeTalkFace != TALK_FACE_NONE && !CheckTalkFlag(TALK_FLAG_1))
    {
        sTalkSt->activeWidth = 2 + Div(7 + GetStrTalkLen(sTalkSt->str, FALSE), 8);
        ClearTalkBubble();

        StartTalkOpen(sTalkSt->activeTalkFace, proc);
        SetTalkFaceLayer(sTalkSt->activeTalkFace, CheckTalkFlag(TALK_FLAG_4));

        return TRUE;
    }

    if (sTalkSt->lineActive >= sTalkSt->lines)
    {
        sTalkSt->instantPrint = FALSE;
        SpawnProcLocking(ProcScr_TalkShiftClear, proc);

        return TRUE;
    }

    if (!sTalkSt->putLines)
    {
        PutText(TALK_TEXT_BY_LINE(sTalkSt->lineActive),
            gBg0Tm + TM_OFFSET(sTalkSt->xText, sTalkSt->yText + sTalkSt->lineActive*2));

        TalkBgSync(BG0_SYNC_BIT);

        sTalkSt->putLines = TRUE;
    }

    if (sTalkSt->unk16 != 0)
        SetTalkFaceMouthMove(sTalkSt->activeTalkFace);

    return FALSE;
}

static Bool TalkSpritePrepNextChar(ProcPtr proc)
{
    if (sTalkSt->lineActive >= sTalkSt->lines)
    {
        sTalkSt->instantPrint = FALSE;
        SpawnProcLocking(ProcScr_Unk_085C3E7C, proc);

        return TRUE;
    }

    if (!sTalkSt->putLines)
        sTalkSt->putLines = TRUE;

    return FALSE;
}

static void LockTalk(ProcPtr proc)
{
    SpawnProcLocking(ProcScr_TalkLock, proc);
}

s8 IsTalkLocked(void)
{
    return Proc_Exists(ProcScr_TalkLock);
}

void ResumeTalk(void)
{
    Proc_EndEach(ProcScr_TalkLock);
}

static int TalkInterpret(ProcPtr proc)
{
    struct GenericProc* gproc;
    int i;

    for (;TRUE;)
    {
        switch (*sTalkSt->str)
        {

        case 0x12:
        case 0x13:
        case 0x14:
            sTalkSt->str++;

            sTalkSt->activeWidth = 2 + Div(7 + GetStrTalkLen(sTalkSt->str, TalkHasCorrectBubble()), 8);

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

            Text_Skip(TALK_TEXT_BY_LINE(sTalkSt->lineActive), 6);

            if (sTalkSt->instantPrint || sTalkSt->printDelay <= 0)
            {
                return 2;
            }

            gproc = SpawnProcLocking(ProcScr_TalkPause, proc);
            gproc->unk64 = GetTalkPauseCmdDuration(4);

            return 3;
        }

        return 1;

    case 0x00: // end
        if (sTalkSt->strBack == NULL)
            return 0;

        sTalkSt->str = sTalkSt->strBack;
        sTalkSt->strBack = NULL;

        return TalkInterpret(proc);

    case 0x01: // newline
        if (sTalkSt->putLines == TRUE || sTalkSt->lineActive == 1)
        {
            sTalkSt->lineActive++;
        }

        sTalkSt->putLines = FALSE;

        sTalkSt->str++;
        return 2;

    case 0x02:
        if (!CheckTalkFlag(TALK_FLAG_0))
            SpawnProcLocking(ProcScr_TalkShiftClearAll, proc);
        else
            ClearTalkText();

        sTalkSt->str++;
        return 3;

    case 0x03: // wait for input to continue
        StartTalkWaitForInput(proc,
            sTalkSt->xText*8 + Text_GetCursor(TALK_TEXT_BY_LINE(sTalkSt->lineActive)) + 4,
            sTalkSt->yText*8 + sTalkSt->lineActive*16 + 8);

        sTalkSt->str++;
        return 3;

    case 0x04 ... 0x07:
        if (sTalkSt->instantPrint)
        {
            sTalkSt->str++;
            return 2;
        }

        gproc = SpawnProcLocking(ProcScr_TalkPause, proc);
        gproc->unk64 = GetTalkPauseCmdDuration(*sTalkSt->str);

        sTalkSt->str++;
        return 3;

    case 0x15:
        ClearTalkBubble();

        sTalkSt->str++;
        return 3;

    case 0x16:
        sTalkSt->unk16 = 1 - sTalkSt->unk16;

        sTalkSt->str++;
        return 3;

    case 0x17:
        sTalkSt->unk17 = 1 - sTalkSt->unk17;

        sTalkSt->str++;
        return 3;

    case 0x10:
        for (;TRUE;)
        {
            switch (*sTalkSt->str)
            {

            case 0x08 ... 0x0F:
                SetActiveTalkFace(*sTalkSt->str - 0x08);

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

        StartFaceFadeOut(sTalkSt->faces[sTalkSt->activeTalkFace]);
        sTalkSt->faces[sTalkSt->activeTalkFace] = NULL;

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
        SetTalkFaceNoMouthMove(sTalkSt->activeTalkFace);
        SetActiveTalkFace(*sTalkSt->str - 8);

        sTalkSt->str++;
        return 3;

    case 0x18: // Yes/No choice (default: Yes)
        StartTalkChoice(gYesNoTalkChoice,
            TALK_TEXT_BY_LINE(sTalkSt->lineActive),
            gBg0Tm + TM_OFFSET(sTalkSt->xText, sTalkSt->yText + 2*sTalkSt->lineActive),
            1, sTalkSt->printColor, proc);

        sTalkSt->str++;
        return 3;

    case 0x19: // Yes/No choice (default: No)
        StartTalkChoice(gYesNoTalkChoice,
            TALK_TEXT_BY_LINE(sTalkSt->lineActive),
            gBg0Tm + TM_OFFSET(sTalkSt->xText, sTalkSt->yText + 2*sTalkSt->lineActive),
            2, sTalkSt->printColor, proc);

        sTalkSt->str++;
        return 3;

    case 0x1A:
        StartTalkChoice(gBuySellTalkChoice,
            TALK_TEXT_BY_LINE(sTalkSt->lineActive),
            gBg0Tm + TM_OFFSET(sTalkSt->xText, sTalkSt->yText + 2*sTalkSt->lineActive),
            1, sTalkSt->printColor, proc);

        sTalkSt->str++;
        return 3;

    case 0x1B:
        StartTalkChoice(gBuySellTalkChoice,
            TALK_TEXT_BY_LINE(sTalkSt->lineActive),
            gBg0Tm + TM_OFFSET(sTalkSt->xText, sTalkSt->yText + 2*sTalkSt->lineActive),
            2, sTalkSt->printColor, proc);

        sTalkSt->str++;
        return 3;

    case 0x80:
        switch (*++sTalkSt->str)
        {

        case 0 ... 3:
            sTalkSt->printColor = *++sTalkSt->str;

            for (i = 0; i < sTalkSt->lines; ++i)
                Text_SetColor(sTalkText + i, sTalkSt->printColor);

            sTalkSt->str++;
            return 3;

        case 4:
            LockTalk(proc);

            sTalkSt->str++;
            return 3;

        case 5:
            NumberToString(sTalkSt->number, sTalkSt->bufNumberStr);

            sTalkSt->str++;

            sTalkSt->strBack = sTalkSt->str;
            sTalkSt->str = sTalkSt->bufNumberStr;

            return TalkInterpret(proc);

        case 6:
            sTalkSt->str++;

            sTalkSt->strBack = sTalkSt->str;
            sTalkSt->str = sTalkSt->bufUnkStr;

            return TalkInterpret(proc);

        case 8:
            sTalkSt->str++;
            return 3;

        case 7:
            sTalkSt->str++;
            return 3;

        case 10 ... 17:
            MoveTalkFace(sTalkSt->activeTalkFace, *sTalkSt->str - 10);
            SetActiveTalkFace(*sTalkSt->str - 10);

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

void SetActiveTalkFace(int talkFace)
{
    sTalkSt->activeTalkFace = talkFace;
}

static void TalkInterpretNewFace(ProcPtr proc)
{
    int faceDisp = 0;
    int fid;

    if (sTalkSt->activeTalkFace == TALK_FACE_NONE)
        SetActiveTalkFace(TALK_FACE_1);

    if (sub_80425C4())
        SetFightEventFaceConfig();
    else
        faceDisp |= FACE_DISP_KIND(FACE_96x80);

    if (GetTalkFaceHPos(sTalkSt->activeTalkFace) <= 14)
        faceDisp |= FACE_DISP_FLIPPED;
    else
        faceDisp |= 0;

    fid = (sTalkSt->str[0]);
    fid = (sTalkSt->str[1] * 0x100) + fid;

    if (fid == UINT16_MAX)
        fid = GetUnitFid(gActiveUnit);
    else
        fid = fid - 0x100;

    sTalkSt->faces[sTalkSt->activeTalkFace] = StartFaceAuto(fid,
        GetTalkFaceHPos(sTalkSt->activeTalkFace)*8, 80, faceDisp);

    StartFaceFadeIn(sTalkSt->faces[sTalkSt->activeTalkFace]);

    SetTalkFaceLayer(sTalkSt->activeTalkFace, CheckTalkFlag(TALK_FLAG_4));
    StartTemporaryLock(proc, 8);
}

void StartTalkFace(int fid, int x, int y, int disp, int talkFace)
{
    sTalkSt->faces[talkFace] = StartFaceAuto(fid, x, y, disp);
}

static int GetFaceIdByX(int x)
{
    int i;

    for (i = 0; i < 4; ++i)
    {
        if (gFaces[i] == NULL)
            continue;

        if (gFaces[i]->xDisp == x)
            return i;
    }

    return -1;
}

static void SetTalkFaceLayer(int talkFace, int toBack)
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

    switch (talkFace)
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

        if (i == talkFace)
            sTalkSt->faces[i]->sprLayer = argLayer;
        else
            sTalkSt->faces[i]->sprLayer = otherLayer;
    }
}

static void MoveTalkFace(int talkFaceFrom, int talkFaceTo)
{
    struct FaceProc* face;
    s8 isSwap = FALSE;

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

static s8 IsTalkFaceMoving(void)
{

#if NONMATCHING

    return Proc_Find(ProcScr_TalkMoveFace) ? TRUE : FALSE;

#else
    asm("\n\
        .section .rodata\n\
        .4byte ProcScr_TalkMoveFace\n\
        .text\n\
        ldr r1, _0800A840\n\
        add r0, r1, #0\n\
        bl Proc_Find\n\
        cmp r0, #0\n\
        beq _0800A844\n\
        mov r0, #1\n\
        b _0800A848\n\
        .align 2, 0\n\
    _0800A840: .4byte ProcScr_TalkMoveFace\n\
    _0800A844:\n\
        mov r0, #0\n\
        b _0800A848\n\
    _0800A848:\n\
    ");
#endif

}

static void StartTalkFaceMove(int talkFaceFrom, int talkFaceTo, s8 isSwap)
{
    struct GenericProc* proc;

    int slot = GetFaceIdByX(GetTalkFaceHPos(talkFaceFrom) * 8);

    if (slot == -1)
        return;

    proc = SpawnProc(ProcScr_TalkMoveFace, gFaces[slot]);

    proc->unk64 = slot;
    proc->unk66 = talkFaceTo;
    proc->unk68 = gFaces[slot]->xDisp;
    proc->unk6A = isSwap;
}

static void TalkFaceMove_OnInit(struct GenericProc* proc)
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

static void TalkFaceMove_OnIdle(struct GenericProc* proc)
{
    if (proc->unk5C > 16)
    {
        if (proc->unk58 == proc->unk5C / 8)
            gFaces[proc->unk64]->yDisp++;

        if (proc->unk58 == proc->unk5C / 2)
            gFaces[proc->unk64]->yDisp--;

        if (proc->unk58 == proc->unk5C * 5 / 8)
            gFaces[proc->unk64]->yDisp++;
    }
    else
    {
        if (proc->unk58 == proc->unk5C / 2)
            gFaces[proc->unk64]->yDisp++;
    }

    if (proc->unk58 >= proc->unk5C)
    {
        gFaces[proc->unk64]->yDisp--;
        Proc_Break(proc);
    }
    else
    {
        gFaces[proc->unk64]->xDisp = Interpolate(INTERPOLATE_RSQUARE,
            proc->unk68, GetTalkFaceHPos(proc->unk66)*8,
            proc->unk58++, proc->unk5C);
    }
}

static void Talk_OnEnd(ProcPtr proc)
{
    Proc_EndEach(ProcScr_TalkSkipListener);
    Proc_EndEach(ProcScr_TalkShiftClearAll);
}

static void TalkPause_OnIdle(struct GenericProc* proc)
{
    if (proc->unk64 == 0)
    {
        Proc_Break(proc);
        return;
    }

    proc->unk64--;
}

static void TalkWaitForInput_OnIdle(struct GenericProc* proc)
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

    if (gKeySt->pressed & (A_BUTTON | B_BUTTON | DPAD_ANY))
        Proc_Break(proc);
}

void sub_800AD58(struct GenericProc* proc)
{
}

void StartTalkWaitForInput(ProcPtr parent, int x, int y)
{
    struct GenericProc* proc = SpawnProcLocking(ProcScr_TalkWaitForInput, parent);

    proc->unk64 = x;
    proc->unk66 = y;
}

static void TalkShiftClearAll_OnInit(struct GenericProc* proc)
{
    TmFillRect_t(gBg0Tm + TM_OFFSET(sTalkSt->xText, sTalkSt->yText + 4),
        sTalkSt->activeWidth-2, sTalkSt->lines*2, 0);

    TalkBgSync(BG0_SYNC_BIT);

    proc->unk64 = 0;

    if (sTalkSt->lineActive == 0)
    {
        proc->unk66 = 16;
    }
    else if (sTalkSt->lineActive + 1 >= sTalkSt->lines)
    {
        proc->unk66 = sTalkSt->lines * 16;
    }
    else
    {
        proc->unk66 = (sTalkSt->lineActive + 1) * 16;
    }
}

static void TalkShiftClearAll_OnIdle(struct GenericProc* proc)
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

static void StartTalkChoice(struct TalkChoiceEnt const* choices, struct Text* text, u16* tm, int defaultChoice, int color, ProcPtr parent)
{
    struct TalkChoiceProc* proc;

    int x = Text_GetCursor(text) + 16;

    Text_InsertDrawString(text, x,      color, DecodeMsg(choices[0].msg));
    Text_InsertDrawString(text, x + 40, color, DecodeMsg(choices[1].msg));

    PutText(text, tm);

    TalkBgSync(BG0_SYNC_BIT);

    proc = SpawnProcLocking(ProcScr_TalkChoice, parent);

    proc->selectedChoice = defaultChoice;

    proc->xDisp = (((tm - gBg0Tm) & 0x1F) * 8) - gDispIo.bgOff[0].x + x;
    proc->yDisp = (((tm - gBg0Tm) / 0x20) * 8) - gDispIo.bgOff[0].y;

    proc->choices = choices;

    if (proc->choices[defaultChoice - 1].onSwitch)
        proc->choices[defaultChoice - 1].onSwitch();
}

void TalkChoice_OnIdle(struct TalkChoiceProc* proc)
{
    if (gKeySt->pressed & B_BUTTON)
    {
        PlaySe(0x6B); // TODO: song ids

        sTalkChoiceResult = 0;

        Proc_Break(proc);
        return;
    }
    else if (gKeySt->pressed & A_BUTTON)
    {
        PlaySe(0x6A); // TODO: song ids

        sTalkChoiceResult = proc->selectedChoice;

        Proc_Break(proc);
        return;
    }

    if ((gKeySt->pressed & DPAD_LEFT) && (proc->selectedChoice == 2))
    {
        PlaySe(0x67); // TODO: song ids

        proc->selectedChoice = 1;

        if (proc->choices[0].onSwitch)
            proc->choices[0].onSwitch();
    }

    if ((gKeySt->pressed & DPAD_RIGHT) && (proc->selectedChoice == 1))
    {
        PlaySe(0x67); // TODO: song ids

        proc->selectedChoice = 2;

        if (proc->choices[1].onSwitch)
            proc->choices[1].onSwitch();
    }

    sub_80415CC(proc->xDisp + (proc->selectedChoice - 1) * 40 - 4, proc->yDisp);
}

static void TalkShiftClear_OnInit(struct GenericProc* proc)
{
    TmFillRect_t(gBg0Tm + TM_OFFSET(sTalkSt->xText, sTalkSt->yText + 4),
        sTalkSt->activeWidth-2, sTalkSt->lines*2, 0);

    TalkBgSync(BG0_SYNC_BIT);

    proc->unk64 = 0;
}

static void TalkShiftClear_OnIdle(struct GenericProc* proc)
{
    proc->unk64 = proc->unk64 + 1;

    SetBgOffset(0, 0, proc->unk64);

    if (proc->unk64 >= 16)
    {
        int i;

        sTalkSt->lineActive--;
        sTalkSt->topTextNum++;

        SetBgOffset(0, 0, 0);

        for (i = 0; i < sTalkSt->lines - 1; ++i)
        {
            PutText(TALK_TEXT_BY_LINE(i),
                gBg0Tm + TM_OFFSET(sTalkSt->xText, sTalkSt->yText + 2*i));
        }

        TmFillRect_t(gBg0Tm + TM_OFFSET(sTalkSt->xText, sTalkSt->yText + (sTalkSt->lines - 1)*2),
            sTalkSt->activeWidth - 2, 2, 0);

        ClearText(TALK_TEXT_BY_LINE(sTalkSt->lines - 1));
        Text_SetColor(TALK_TEXT_BY_LINE(sTalkSt->lines - 1), sTalkSt->printColor);

        TalkBgSync(BG0_SYNC_BIT);

        Proc_Break(proc);
    }
}

static void sub_800B3D4(ProcPtr proc)
{
    sub_8094030(0x361, 0x1C, 0x44444444, proc);
}

static void sub_800B3F8(ProcPtr proc)
{
    sTalkSt->lineActive--;

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
    sTalkSt->speakTalkFace = (s8) TALK_FACE_NONE;

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

    sTalkSt->lineActive = 0;
    sTalkSt->putLines = 0;
    sTalkSt->topTextNum = 0;

    for (i = 0; i < sTalkSt->lines; ++i)
    {
        ClearText(sTalkText + i);
        Text_SetColor(sTalkText + i, sTalkSt->printColor);
    }
}

void ClearTalkText(void)
{
    int i;

    sTalkSt->lineActive = 0;
    sTalkSt->putLines = 0;
    sTalkSt->topTextNum = 0;

    for (i = 0; i < sTalkSt->lines; ++i)
    {
        ClearText(sTalkText + i);
        Text_SetColor(sTalkText + i, sTalkSt->printColor);
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

    if (sub_80425C4())
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

    sTalkSt->xText = x + 1;
    sTalkSt->yText = y + 1;

    PutTalkBubbleTm(x, y, width, height);
    PutTalkBubbleTail(xTail, yAnchor, kind);
    InitTalkTextWin(x, y, width, height);

    StartOpenTalkBubble();

    TalkBgSync(BG1_SYNC_BIT);
}

static void StartOpenTalkBubble(void)
{
    struct GenericProc* proc = SpawnProc(ProcScr_TalkOpenBubble, PROC_TREE_3);
    proc->unk64 = 0;
}

static void TalkOpenBubble_OnIdle(struct GenericProc* proc)
{
    u8 const* imgLut[] =
    {
        Img_TalkBubbleOpeningA,
        Img_TalkBubbleOpeningB,
        Img_TalkBubbleOpeningC,
        Img_TalkBubbleOpeningD,
        Img_TalkBubbleOpeningE,
        Img_TalkBubble,
        NULL
    };

    if ((proc->unk64++) & 1)
        return;

    Decompress(imgLut[proc->unk64 >> 1],
        (u8*) VRAM + GetBgChrOffset(1) + 0x10 * CHR_SIZE);

    if (imgLut[(proc->unk64 >> 1) + 1] == NULL)
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

static void TalkOpen_OnEnd(struct GenericProc* proc)
{
}

static void TalkOpen_InitBlend(struct GenericProc* proc)
{
    proc->unk58 = 0;

    SetBlendTargetA(0, 1, 0, 0, 0);
    SetBlendTargetB(0, 0, 1, 1, 1);

    SetBlendBackdropB(1);

    gDispIo.winCt.win0_enableBlend = 1;
    gDispIo.winCt.wout_enableBlend = 1;

    SetBlendAlpha(0, 0x10);
}

static void TalkOpen_PutTalkBubble(struct GenericProc* proc)
{
    PutTalkBubble(proc->unk64, proc->unk66, proc->unk68, proc->unk6A);
    Proc_Break(proc);
}

static void TalkOpen_OnIdle(struct GenericProc* proc)
{
    int var;

    proc->unk58++;

    var = Interpolate(INTERPOLATE_RSQUARE, -30, 0, proc->unk58, 12);

    SetBgOffset(1, 0, var/2);
    SetBlendAlpha(var/2 + 0x10, 1 - var/2);

    if (proc->unk58 == 12)
        Proc_Break(proc);
}

static void StartTalkOpen(int talkFace, ProcPtr parent)
{
    struct GenericProc* proc = SpawnProcLocking(ProcScr_TalkOpen, parent);

    proc->unk64 = GetTalkFaceHPos(talkFace);
    proc->unk66 = 8;

    proc->unk68 = sTalkSt->activeWidth;
    proc->unk6A = 6;

    if (proc->unk64 < 0)
        proc->unk64 = 0;

    if (proc->unk64 > 29)
        proc->unk64 = 30;

    sTalkSt->speakTalkFace = talkFace;
    sTalkSt->speakWidth = sTalkSt->activeWidth;
}

static Bool TalkHasCorrectBubble(void)
{
    if (sTalkSt->speakTalkFace == sTalkSt->activeTalkFace && sTalkSt->speakWidth == sTalkSt->activeWidth)
        return TRUE;

    return FALSE;
}

int GetTalkFaceHPos(int talkFace)
{
    if (sub_80425C4())
        return 4;

    return gTalkFaceHPosLut[talkFace];
}

static void SetTalkFaceDisp(int talkFace, int faceDisp)
{
    int lut[] = { 0, FACE_DISP_SMILE };
    int disp;

    if (talkFace == TALK_FACE_NONE)
        return;

    disp = GetFaceDisp(sTalkSt->faces[talkFace]);
    disp &= ~(FACE_DISP_SMILE | FACE_DISP_TALK_1 | FACE_DISP_TALK_2);

    SetFaceDisp(sTalkSt->faces[talkFace], disp | faceDisp | lut[sTalkSt->unk17]);
}

static void SetTalkFaceMouthMove(int talkFace)
{
    SetTalkFaceDisp(talkFace, FACE_DISP_TALK_1);
}

static void SetTalkFaceNoMouthMove(int talkFace)
{
    SetTalkFaceDisp(talkFace, 0);
}

s8 IsTalkActive(void)
{
    return Proc_Exists(ProcScr_Talk);
}

s8 FaceExists(void)
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

void SetTalkUnkStr(char const* str)
{
    strcpy(sTalkSt->bufUnkStr, str);
}

void PrintStringToTexts(struct Text** texts, char const* str, int x, int y)
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

static void TalkPutSpriteText_OnIdle(struct GenericProc* proc)
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

static void TalkPutSpriteText_OnEnd(struct GenericProc* proc)
{
    CallDelayed(ClearHBlankA, 1);
}

void StartPutTalkSpriteText(int x, int y, int chr, int palid, ProcPtr parent)
{
    struct GenericProc* proc;

    proc = Proc_Find(ProcScr_TalkPutSpriteText);

    if (!proc)
        proc = SpawnProc(ProcScr_TalkPutSpriteText, parent);

    proc->x = x;
    proc->y = y;
    proc->unk52 = chr;
    proc->unk64 = palid;

    sub_8069C34();
    sub_806A218(y + 7, y + 41, 0x44C3, 0x7247);
}

void EndPutTalkSpriteText(void)
{
    Proc_EndEach(ProcScr_TalkPutSpriteText);
}

int GetStrTalkLen(char const* str, s8 isBubbleOpen)
{
    char buf[0x20];

    int speakFace = sTalkSt->speakTalkFace;
    int activeFace = sTalkSt->activeTalkFace;

    int chrlen;

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
                StringCopy(sTalkSt->bufUnkStr, buf); // BUG: arguments are reversed?
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

s8 IsTalkDebugActive(void)
{
    return Proc_Exists(ProcScr_TalkDebug);
}

void StartTalkDebug(void)
{
    SpawnProc(ProcScr_TalkDebug, PROC_TREE_3);
}

static void TalkDebug_Unk_0800CA88(struct GenericProc* proc)
{
    proc->unk34 = 1;
}

static void TalkDebug_Unk_0800CAA0(struct GenericProc* proc)
{
    DisplayBackground(BACKGROUND_7);
}

static void TalkDebug_OnInit(struct GenericProc* proc)
{
    proc->x = 0;
    TalkDebug_Unk_0800CA88(proc);
}

static void TalkDebug_OnIdle(struct GenericProc* proc)
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

    if (gKeySt->pressed & SELECT_BUTTON)
    {
        Proc_Break(proc);
        return;
    }

    if (gKeySt->repeated & DPAD_UP)
        msg++;

    if (gKeySt->repeated & DPAD_DOWN)
        msg--;

    if (gKeySt->repeated & DPAD_RIGHT)
        msg += 10;

    if (gKeySt->repeated & DPAD_LEFT)
        msg -= 10;

    if (gKeySt->repeated & R_BUTTON)
        msg += 100;

    if (gKeySt->repeated & L_BUTTON)
        msg -= 100;

    if (msg < 0)
        msg = 0;

    if (msg > 0xD0D) // TODO: msgid
        msg = 0xD0D; // TODO: msgid

    if (msg != proc->x)
    {
        ClearTalk();
        EndTalk();

        DebugInitObj(-1, 9);

        proc->x = msg;

        InitTalk(0x80, 2, TRUE);
        StartTalkMsg(1, 1, proc->x);

        SetTalkFlag(TALK_FLAG_0);
        SetTalkFlag(TALK_FLAG_1);
        SetTalkFlag(TALK_FLAG_NOSKIP);

        SetTalkPrintDelay(-1);

        TalkBgSync(BG0_SYNC_BIT);

        return;
    }

    if (gKeySt->pressed & A_BUTTON)
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
