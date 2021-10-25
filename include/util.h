#pragma once

#include "common.h"

#include "proc.h"
#include "text.h"

enum
{
    INTERPOLATE_LINEAR,
    INTERPOLATE_SQUARE,
    INTERPOLATE_CUBIC,
    INTERPOLATE_POW4,
    INTERPOLATE_RSQUARE,
    INTERPOLATE_RCUBIC,
};

struct PalFadeSt
{
    /* 00 */ u16 fromColors[0x10];
    /* 20 */ u16 const* toColors;
    /* 24 */ u16* pal;
    /* 28 */ u16 clock;
    /* 2A */ u16 clockEnd;
    /* 2C */ u16 clockStop;
};

int Interpolate(int method, int lo, int hi, int x, int end);
void nullsub_12(void);
bool StringEquals(char const* strA, char const* strB);
void StringCopy(char* dst, char const* src);
void Decompress_Unused_08013C74(u8 const* src, u8* dst);
void Decompress(u8 const* src, void* dst);
int GetDataSize(u8 const* data);
void Register2dChrMove(u8 const* img, u8* vram, int width, int height);
void Copy2dChr(void const* src, u8* dst, int width, int height);
void sub_8013DAC(u8 const* src, u8* dst, int width, int height);
void PutIncrTileref(u16* tm, int tileref, int width, int height);
void sub_8013E8C(u16* tm, u8 const* src, int tileref, int len);
// sub_8013EBC
// sub_8013EC4
// sub_8013ED8
// sub_8013EE4
// sub_8013F04
// sub_8013F7C
// DarkenPals
// nullsub_13
// sub_8014130
void StartSpacialSeTest(void);
void nullsub_14(void);
void StartPalFadeToBlack(int palid, int duration, ProcPtr parent);
void StartPalFadeToWhite(int palid, int duration, ProcPtr parent);
struct PalFadeSt* StartPalFade(u16 const* colors, int pal, int duration, ProcPtr parent);
void EndPalFade(void);
void SetPalFadeStop(struct PalFadeSt* st, int val);
void SetBlackPal(int palid);
void SetWhitePal(int palid);
void SetAllBlackPals(void);
void SetAllWhitePals(void);
bool FadeExists(void);
void StartFadeToBlack(int q4_speed);
void StartFadeFromBlack(int q4_speed);
void StartLockingFadeToBlack(int q4_speed, ProcPtr parent);
void StartLockingFadeFromBlack(int q4_speed, ProcPtr parent);
void StartLockingFadeToWhite(int q4_speed, ProcPtr parent);
void StartLockingFadeFromWhite(int q4_speed, ProcPtr parent);
void StartMidFadeToBlack(void);
void StartSlowFadeToBlack(void);
void StartFastFadeToBlack(void);
void StartMidFadeFromBlack(void);
void StartSlowFadeFromBlack(void);
void StartFastFadeFromBlack(void);
void StartMidLockingFadeToBlack(ProcPtr parent);
void StartSlowLockingFadeToBlack(ProcPtr parent);
void StartFastLockingFadeToBlack(ProcPtr parent);
void StartMidLockingFadeFromBlack(ProcPtr parent);
void StartSlowLockingFadeFromBlack(ProcPtr parent);
void StartFastLockingFadeFromBlack(ProcPtr parent);
void StartSlowLockingFadeToWhite(ProcPtr parent);
void StartSlowLockingFadeFromWhite(ProcPtr parent);
// sub_8014778
// sub_8014790
// sub_80147A8
// sub_80147C0
// sub_80147D8
// sub_80147F0
// sub_8014804
// sub_8014818
// sub_801482C
// sub_8014840
// sub_8014858
// sub_8014870
// sub_8014888
// sub_80148A0
// sub_80148B8
// sub_80148CC
// sub_80148E0
// sub_80148F8
// sub_801490C
// sub_8014920
// sub_8014934
// sub_8014948
// sub_801495C
// sub_8014970
// sub_8014984
// sub_8014998
void WhileFadeExists(ProcPtr proc);
// sub_80149CC
void sub_80149E0(int kind, int speed, ProcPtr parent, Func endFunc);
// sub_8014A28
// sub_8014A38
// sub_8014A44
// sub_8014A68
void sub_8014AB8(void);
// sub_8014ACC
void sub_8014ADC(void);
void sub_8014AF8(void);
void sub_8014B68(void);
void StartTemporaryLock(ProcPtr proc, int arg_1);
int NumberToString(int number, char* buf);
struct Text* PutStringCentered(u16* tm, int color, int width, char const* str);
struct Text* PutString(u16* tm, int color, char const* str);
// sub_8014D50
// sub_8014D60
// sub_8014D9C
// sub_8014DB4
// sub_8014DCC
// sub_8014E30
// sub_8014E98
// sub_8014F70
// sub_801501C
// sub_80150DC
void CallDelayed(void(*func)(void), int delay);
void CallDelayedArg(void(*func)(int), int arg, int delay);
// sub_80151E4
// sub_80151F8
// sub_8015208
void StartPartialGameLock(ProcPtr proc);
void sub_8015260(u8 const* src, u8* dst, int size);
void sub_8015298(u8 const* src, u8* dst, int width, int height);
void sub_80152C4(u16 const* src, u16* dst, int size, u16 tileref);
u16* GetTmOffsetById(int bgid, int x, int y);
void sub_8015344(void);
int Screen2Pan(int x);
void PlaySeSpacial(int song, int x);
void PlaySeDelayed(int song, int delay);
void sub_801548C(short song);
void sub_801549C(short speed);
// sub_80154AC
// sub_8015504
void PutDrawTextCentered(struct Text* text, int x, int y, char const* str, int width);
void VecMulMat(int const* vec, int const* mat, int* ovec);
void MatMulMat(int const* lmat, int const* rmat, int* omat);
void MatIdent(int* mat);
void MatCopy(int const* src, int* dst);
void MatRotA(int* mat, short angle);
void MatRotB(int* mat, short angle);
void MatRotC(int* mat, short angle);
void nullsub_15(void);
int VecDotVec(int const* lvec, int const* rvec);
void VecCrossVec(int const* lvec, int const* rvec, int* ovec);
int sub_80158B8(int arg_0, int arg_1, int arg_2, int arg_3);

extern u16 CONST_DATA Pal_AllBlack[];
extern u16 CONST_DATA Pal_AllWhite[];
extern u16 CONST_DATA Pal_AllRed[];
extern u16 CONST_DATA Pal_AllGreen[];
extern u16 CONST_DATA Pal_AllBlue[];
extern u16 CONST_DATA Pal_085C4F2C[];
