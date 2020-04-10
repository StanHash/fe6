
#pragma once

#include "gba/gba.h"
#include "types.h"

#include "proc.h"
#include "text.h"
#include "face.h"

enum
{
    TALK_FACE_0,
    TALK_FACE_1,
    TALK_FACE_2,
    TALK_FACE_3,
    TALK_FACE_4,
    TALK_FACE_5,
    TALK_FACE_6,
    TALK_FACE_7,

    TALK_FACE_COUNT,

    TALK_FACE_NONE = 0xFF,
};

enum
{
    TALK_FLAG_0 = (1 << 0),
    TALK_FLAG_1 = (1 << 1),
    TALK_FLAG_NOSKIP = (1 << 2),
    TALK_FLAG_NOFAST = (1 << 3),
    TALK_FLAG_4 = (1 << 4),
    TALK_FLAG_SPRITE = (1 << 5),
    TALK_FLAG_SILENT = (1 << 6),
    TALK_FLAG_7 = (1 << 7),
};

struct TalkSt
{
    /* 00 */ char const* str;
    /* 04 */ char const* strBack;
    /* 08 */ u8 printColor;
    /* 09 */ u8 lineActive;
    /* 0A */ u8 lines;
    /* 0B */ u8 topTextNum;
    /* 0C */ u8 xText;
    /* 0D */ u8 yText;
    /* 0E */ u8 activeWidth;
    /* 0F */ s8 speakTalkFace;
    /* 10 */ u8 speakWidth;
    /* 11 */ u8 activeTalkFace;
    /* 12 */ Bool instantPrint;
    /* 13 */ s8 printDelay;
    /* 14 */ s8 printClock;
    /* 15 */ u8 putLines;
    /* 16 */ u8 unk16;
    /* 17 */ u8 unk17;
    /* 18 */ struct FaceProc* faces[TALK_FACE_COUNT];
    /* 38 */ u16 flags;
    /* 3A */ // pad
    /* 3C */ int number;
    /* 40 */ char bufNumberStr[0x20];
    /* 60 */ char bufUnkStr[0x20];
};

void InitTalk(int chr, int lines, Bool unpackBubble);
void InitSpriteTalk(int chr, int lines, int palid);
void SetInitTalkTextFont(void);
ProcPtr StartTalkExt(int x, int y, char const* str, ProcPtr parent);
ProcPtr StartTalkMsg(int x, int y, int msg);
ProcPtr StartTalkMsgExt(int x, int y, int msg, ProcPtr parent);
ProcPtr StartTalk(int x, int y, char const* str);
void EndTalk(void);
void SetTalkLines(int lines);
void SetTalkFlag(int flag);
void ClearTalkFlag(int flag);
int CheckTalkFlag(int flag);
void SetTalkPrintDelay(int printDelay);
void SetTalkPrintColor(int color);
s8 IsTalkLocked(void);
void ResumeTalk(void);
void SetActiveTalkFace(int talkFace);
void StartTalkFace(int fid, int x, int y, int disp, int talkFace);
void StartTalkWaitForInput(ProcPtr proc, int x, int y);
void ClearTalkBubble(void);
void ClearPutTalkText(void);
void ClearTalkText(void);
void PutTalkBubbleTail(int x, int y, int kind);
void PutTalkBubbleTm(int x, int y, int width, int height);
s8 IsTalkActive(void);
s8 FaceExists(void);
int GetTalkChoiceResult(void);
void SetTalkNumber(int number);
void SetTalkUnkStr(char const* str);
void PrintStringToTexts(struct Text** texts, char const* str, int x, int y);
void StartPutTalkSpriteText(int x, int y, int chr, int palid, ProcPtr parent);
void EndPutTalkSpriteText(void);
s8 IsTalkDebugActive(void);
void StartTalkDebug(void);

extern struct TalkSt* CONST_DATA gTalkSt;

extern struct ProcScr CONST_DATA ProcScr_TalkOpen[];
