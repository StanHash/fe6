
#pragma once

#include "gba/gba.h"
#include "types.h"

#include "proc.h"
#include "text.h"

void sub_800CCB4(int bgflags);
void sub_8011FD0(void);
void Decompress(void const* src, void* dst);
void SetDialogueSkipEvbit(void);
int sub_8013B24(int, int, int, int, int);
void sub_8013C18(char const* src, char* dst);
void sub_8013E58(u16* tm, int tileref, int width, int height);
void sub_80141E0(int palid, int arg_2, ProcPtr proc);
void sub_8014218(u16 const* pal, int palid, int arg_2, ProcPtr proc);
void sub_8014374(int pal);
void sub_8014BAC(ProcPtr proc, int arg_1);
void sub_8014BE4(int number, char* buf);
void sub_80151A8(Func func, int time);
int sub_80184F0(struct Unit* unit);
int sub_8028E98(void);
char* MsgDecode(int msg);
void LoadObjUiGfx(void);
void sub_80415CC(int x, int y);
s8 sub_80425C4(void);
void sub_8069C34(void);
void sub_806A218(u16 yStart, u16 yEnd, int arg_2, int arg_3);
void sub_8094030(int arg_0, int arg_1, int arg_2, ProcPtr proc);
void sub_8095FC4(void);
void sub_8095FF8(void);
void LockGame(void);
void UnlockGame(void);

extern struct PlaySt gPlaySt;
extern struct Unit* gActiveUnit;

extern struct Glyph const* CONST_DATA TextGlyphs_Special[];
extern struct Glyph const* CONST_DATA TextGlyphs_System[];
extern struct Glyph const* CONST_DATA TextGlyphs_Talk[];
extern u16 CONST_DATA Pal_SystemText[];
extern u16 CONST_DATA Pal_TalkText[];
extern u16 CONST_DATA Pal_GreenTextColors[];
extern u8 const Img_FactionMiniCard[];
extern u16 const Pal_FactionMiniCard[];
extern u8 const Img_TalkBubble[];
extern u16 const Pal_TalkBubble[];
extern u8 const Img_TalkBubbleOpeningA[];
extern u8 const Img_TalkBubbleOpeningB[];
extern u8 const Img_TalkBubbleOpeningC[];
extern u8 const Img_TalkBubbleOpeningD[];
extern u8 const Img_TalkBubbleOpeningE[];
extern u8 const Tsa_Unk_08101974[];
extern u8 const Tsa_Unk_08101A2C[];
extern struct ProcScr CONST_DATA ProcScr_CamMove[];
extern struct FaceInfo CONST_DATA FaceInfoTable[];
