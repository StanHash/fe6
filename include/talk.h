#pragma once

#include "common.h"
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
    TALK_FLAG_INSTANTSHIFT = (1 << 0),
    TALK_FLAG_NOBUBBLE = (1 << 1),
    TALK_FLAG_NOSKIP = (1 << 2),
    TALK_FLAG_NOFAST = (1 << 3),
    TALK_FLAG_4 = (1 << 4),
    TALK_FLAG_SPRITE = (1 << 5),
    TALK_FLAG_SILENT = (1 << 6),
    TALK_FLAG_7 = (1 << 7),
};

struct TalkSt
{
    /* 00 */ char const * str;
    /* 04 */ char const * str_back;
    /* 08 */ u8 print_color;
    /* 09 */ u8 line_active;
    /* 0A */ u8 lines;
    /* 0B */ u8 top_text_num;
    /* 0C */ u8 x_text;
    /* 0D */ u8 y_text;
    /* 0E */ u8 active_width;
    /* 0F */ i8 speak_talk_face;
    /* 10 */ u8 speak_width;
    /* 11 */ u8 active_talk_face;
    /* 12 */ bool8 instant_print;
    /* 13 */ i8 print_delay;
    /* 14 */ i8 print_clock;
    /* 15 */ u8 put_lines;
    /* 16 */ u8 unk_16;
    /* 17 */ u8 unk_17;
    /* 18 */ struct FaceProc * faces[TALK_FACE_COUNT];
    /* 38 */ u16 flags;
    /* 3A */ // pad
    /* 3C */ int number;
    /* 40 */ char buf_number_str[0x20];
    /* 60 */ char buf_unk_str[0x20];
};

void InitTalk(int chr, int lines, bool unpack_bubble);
void InitSpriteTalk(int chr, int lines, int palid);
void SetInitTalkTextFont(void);
ProcPtr StartTalkExt(int x, int y, char const * str, ProcPtr parent);
ProcPtr StartTalkMsg(int x, int y, int msg);
ProcPtr StartTalkMsgExt(int x, int y, int msg, ProcPtr parent);
ProcPtr StartTalk(int x, int y, char const * str);
void EndTalk(void);
void SetTalkLines(int lines);
void SetTalkFlag(int flag);
void ClearTalkFlag(int flag);
int CheckTalkFlag(int flag);
void SetTalkPrintDelay(int print_delay);
void SetTalkPrintColor(int color);
bool IsTalkLocked(void);
void ResumeTalk(void);
void SetActiveTalkFace(int talk_face);
void StartTalkFace(int fid, int x, int y, int disp, int talk_face);
void StartTalkWaitForInput(ProcPtr proc, int x, int y);
void ClearTalkBubble(void);
void ClearPutTalkText(void);
void ClearTalkText(void);
void PutTalkBubbleTail(int x, int y, int kind);
void PutTalkBubbleTm(int x, int y, int width, int height);
bool IsTalkActive(void);
bool FaceExists(void);
int GetTalkChoiceResult(void);
void SetTalkNumber(int number);
void SetTalkUnkStr(char const * str);
void PrintStringToTexts(struct Text ** texts, char const * str, int x, int y);
void StartPutTalkSpriteText(int x, int y, int chr, int palid, ProcPtr parent);
void EndPutTalkSpriteText(void);
bool IsTalkDebugActive(void);
void StartTalkDebug(void);

extern struct ProcScr CONST_DATA ProcScr_TalkOpen[];
