
#include "popup.h"

#include "armfunc.h"
#include "hardware.h"
#include "oam.h"
#include "sound.h"
#include "ramfunc.h"
#include "proc.h"
#include "icon.h"
#include "sprite.h"

#include "unks.h"

#include "constants/video-global.h"

struct PopupProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ struct PopupInfo const* info;
    /* 30 */ int clock;

    /* 34 */ s8 xParam;
    /* 35 */ s8 yParam;

    /* 36 */ u8 winKind;

    /* 37 */ u8 frameX;
    /* 38 */ u8 frameY;

    /* 39 */ u8 frameWidth;
    /* 3A */ u8 frameHeight;

    /* 3B */ u8 color;

    /* 3C */ u8 pad3C[0x3E - 0x3C];

    /* 3E */ u16 icon;
    /* 40 */ u16 iconChr;
    /* 42 */ u8 iconPalid;
    /* 43 */ u8 pad43;
    /* 44 */ u8 iconX;
    /* 45 */ u8 pad45;

    /* 46 */ u16 widthPx;

    /* 48 */ u16 songPlayed;
};

static int PreparePopup(struct PopupProc* proc);
static void PutPopup(struct PopupInfo const* info, struct Text text);

static void Popup_OnInit(struct PopupProc* proc);
static void Popup_Prepare(struct PopupProc* proc);
static void Popup_FadeBgmOut(struct PopupProc* proc);
static void Popup_PlaySe(struct PopupProc* proc);
static void Popup_FadeBgmIn(struct PopupProc* proc);
static void Popup_Display(struct PopupProc* proc);
static void Popup_WaitForEnd(struct PopupProc* proc);
static void Popup_Clear(struct PopupProc* proc);

static void PopupIconSprite_OnIdle(struct GenericProc* proc);

static struct Unit* sPopupUnit;
static u16 sPopupItem;
static int sPopupNumber;

struct ProcScr CONST_DATA ProcScr_Popup[] =
{
    PROC_SET_END_FUNC(Popup_Clear),

    PROC_CALL(Popup_OnInit),
    PROC_SLEEP(10),

    PROC_CALL(Popup_Prepare),
    PROC_CALL(Popup_FadeBgmOut),
    PROC_SLEEP(0),

    PROC_CALL(Popup_PlaySe),
    PROC_CALL(Popup_Display),
    PROC_REPEAT(Popup_WaitForEnd),

    PROC_CALL(Popup_FadeBgmIn),
    PROC_SLEEP(0),

    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_PopupIconSprite[] =
{
    PROC_REPEAT(PopupIconSprite_OnIdle),
};

static int PreparePopup(struct PopupProc* proc)
{
    int result = 0;

    char buf[0x10];
    struct PopupInfo const* it;

    for (it = proc->info; it->cmd; ++it)
    {
        switch (it->cmd)
        {

        case POPUP_CMD_SONG:
            proc->songPlayed = it->arg;
            break;

        case POPUP_CMD_NUMBER:
            result += sub_8014BE4(sPopupNumber, buf)*8;
            break;

        case POPUP_CMD_ICON_ITEM:
            proc->iconX = result;
            proc->icon = sub_80172D8(sPopupItem);
            ApplyIconPalette(0, proc->iconPalid);

            result += 16;
            break;

        case POPUP_CMD_ICON_IKIND:
            proc->iconX = result;
            proc->icon = sPopupItem + 0x70; // TODO: icon constants?
            ApplyIconPalette(1, proc->iconPalid);

            result += 16;
            break;

        case POPUP_CMD_COLOR:
            break;

        case POPUP_CMD_MSG:
            result += GetStringTextLen(MsgDecode(it->arg));
            break;

        case POPUP_CMD_STR:
            result += GetStringTextLen((char const*) it->arg);
            break;

        case POPUP_CMD_UNIT_NAME:
            result += GetStringTextLen(MsgDecode(sPopupUnit->person->msgName));
            break;

        case POPUP_CMD_ITEM_NAME:
            result += GetStringTextLen(sub_8017130(sPopupItem));
            break;

        case POPUP_CMD_SPACE:
            result += it->arg;
            break;

        default:
            break;

        }
    }

    return result;
}

static void PutPopup(struct PopupInfo const* info, struct Text text)
{
    char buf[0x10];

    for (; info->cmd; ++info)
    {
        switch (info->cmd)
        {

        case POPUP_CMD_NUMBER:
            sub_8014BE4(sPopupNumber, buf);
            Text_DrawString(&text, buf);
            break;

        case POPUP_CMD_ICON_ITEM:
            Text_Skip(&text, 16);
            break;

        case POPUP_CMD_ICON_IKIND:
            Text_Skip(&text, 16);
            break;

        case POPUP_CMD_COLOR:
            Text_SetColor(&text, info->arg);
            break;

        case POPUP_CMD_MSG:
            Text_DrawString(&text, MsgDecode(info->arg));
            break;

        case POPUP_CMD_STR:
            Text_DrawString(&text, (char const*) info->arg);
            break;

        case POPUP_CMD_UNIT_NAME:
            Text_DrawString(&text, MsgDecode(sPopupUnit->person->msgName));
            break;

        case POPUP_CMD_ITEM_NAME:
            Text_DrawString(&text, sub_8017130(sPopupItem));
            break;

        case POPUP_CMD_SPACE:
            Text_Skip(&text, info->arg);
            break;

        default:
            break;

        }
    }

    EnableBgSync(BG0_SYNC_BIT + BG1_SYNC_BIT);
}

static void Popup_OnInit(struct PopupProc* proc)
{
    proc->xParam = 0xFF;
    proc->yParam = 0xFF;

    proc->color = TEXT_COLOR_SYSTEM_WHITE;

    proc->icon = UINT16_MAX;
    proc->iconX = 0;

    proc->songPlayed = 0;
}

static void Popup_Prepare(struct PopupProc* proc)
{
    InitTextFont(NULL,
        (u8*) VRAM + GetBgChrOffset(0) + BGCHR_0_TEXT_POPUP * CHR_SIZE,
        BGCHR_0_TEXT_POPUP, BGPAL_TEXT_DEFAULT);

    ClearIcons();
    LoadUiFrameGraphics();

    SetBlendNone();
    SetWinEnable(0, 0, 0);

    proc->widthPx = PreparePopup(proc);
}

static void Popup_FadeBgmOut(struct PopupProc* proc)
{
    if (proc->songPlayed != 0)
        StartMusicVolumeChange(0x100, 0x80, 16, proc);
}

static void Popup_PlaySe(struct PopupProc* proc)
{
    if (proc->songPlayed != 0)
        PlaySE(proc->songPlayed);
}

static void Popup_FadeBgmIn(struct PopupProc* proc)
{
    if (proc->songPlayed != 0)
        StartMusicVolumeChange(0x80, 0x100, 16, proc);
}

static void PopupIconSprite_OnIdle(struct GenericProc* proc)
{
    PutOamHiRam(proc->x, proc->y, Sprite_16x16, proc->unk4A);
}

static void Popup_Display(struct PopupProc* proc)
{
    struct GenericProc* gproc;

    struct Text text;

    int width;
    int textoff;
    int x, y;

    proc->widthPx = PreparePopup(proc);
    width = proc->widthPx >> 3;

    if (proc->widthPx & 7)
        width++;

    textoff = (width*8 - proc->widthPx) >> 1;

    if (proc->xParam == -1)
        x = ((30 - width) >> 1) - 1;
    else
        x = proc->xParam;

    if (proc->yParam == -1)
        y = 8;
    else
        y = proc->yParam;

    sub_8041358(x, y, width + 2, 4, proc->winKind);

    proc->frameX = x;
    proc->frameY = y;

    proc->frameWidth = width + 2;
    proc->frameHeight = 3;

    proc->iconX += textoff;

    InitText(&text, width);

    Text_SetColor(&text, proc->color);
    Text_SetCursor(&text, textoff);

    PutPopup(proc->info, text);

    if (proc->icon != UINT16_MAX)
        PutIconObjImg(proc->icon, proc->iconChr);

    PutText(&text, gBg0Tm + TM_OFFSET(x + 1, y + 1));

    ResetText();

    if (proc->icon != UINT16_MAX)
    {
        gproc = SpawnProc(ProcScr_PopupIconSprite, proc);

        gproc->x = (proc->frameX+1)*8 + proc->iconX;
        gproc->y = (proc->frameY+1)*8;

        gproc->unk4A = proc->iconChr | OAM2_PAL(proc->iconPalid);
    }
}

static void Popup_WaitForEnd(struct PopupProc* proc)
{
    if (proc->clock < 0)
    {
        if (gKeySt->pressed)
            Proc_Break(proc);
    }
    else
    {
        if (proc->clock == 0)
            return;

        proc->clock--;

        if (proc->clock == 0)
            Proc_Break(proc);
    }
}

static void Popup_Clear(struct PopupProc* proc)
{
    TmFillRect_t(gBg0Tm + TM_OFFSET(proc->frameX, proc->frameY), proc->frameWidth, proc->frameHeight, 0);
    TmFillRect_t(gBg1Tm + TM_OFFSET(proc->frameX, proc->frameY), proc->frameWidth, proc->frameHeight, 0);

    EnableBgSync(BG0_SYNC_BIT + BG1_SYNC_BIT);
}

void SetPopupUnit(struct Unit* unit)
{
    sPopupUnit = unit;
}

void SetPopupItem(u16 item)
{
    sPopupItem = item;
}

void SetPopupNumber(int number)
{
    sPopupNumber = number;
}

ProcPtr StartPopup(struct PopupInfo const* info, int duration, int winKind, ProcPtr parent)
{
    return StartPopupExt(info, duration, winKind, 0x240, 4, parent);
}

ProcPtr StartPopupExt(struct PopupInfo const* info, int duration, int winKind, int iconChr, int iconPal, ProcPtr parent)
{
    struct PopupProc* proc;

    if (parent)
        proc = SpawnProcLocking(ProcScr_Popup, parent);
    else
        proc = SpawnProc(ProcScr_Popup, PROC_TREE_3);

    proc->clock = duration;
    proc->info = info;
    proc->winKind = winKind;
    proc->iconChr = iconChr;
    proc->iconPalid = iconPal + 0x10;

    return proc;
}

void EndPopup(void)
{
    Proc_EndEach(ProcScr_Popup);
}
