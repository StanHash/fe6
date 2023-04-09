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
    /* 00 */ u16 from_colors[0x10];
    /* 20 */ u16 const * to_colors;
    /* 24 */ u16 * pal;
    /* 28 */ u16 clock;
    /* 2A */ u16 clock_end;
    /* 2C */ u16 clock_stop;
};

int Interpolate(int method, int lo, int hi, int x, int end);
void func_fe6_08013BEC(void);
bool StringEquals(char const * strA, char const * strB);
void StringCopy(char * dst, char const * src);
void Decompress_Unused_08013C74(void const * src, void * dst);
void Decompress(void const * src, void * dst);
int GetDataSize(void const * data);
void Register2dChrMove(u8 const * img, u8 * vram, int width, int height);
void Copy2dChr(void const * src, u8 * dst, int width, int height);
void ApplyBitmap(u8 const * src, void * dst, int width, int height);
void PutAppliedBitmap(u16 * tm, int tileref, int width, int height);
void PutDigits(u16 * tm, u8 const * src, int tileref, int len);
// func_fe6_08013EBC
// func_fe6_08013EC4
// func_fe6_08013ED8
// func_fe6_08013EE4
// func_fe6_08013F04
// func_fe6_08013F7C
void DarkenPals(int reduction);
// func_fe6_0801412C
// func_fe6_08014130
void StartSpacialSeTest(void);
void func_fe6_080141DC(void);
void StartPalFadeToBlack(int palid, int duration, ProcPtr parent);
void StartPalFadeToWhite(int palid, int duration, ProcPtr parent);
struct PalFadeSt * StartPalFade(u16 const * colors, int pal, int duration, ProcPtr parent);
void EndPalFade(void);
void SetPalFadeStop(struct PalFadeSt * st, int val);
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
// func_fe6_08014778
// func_fe6_08014790
// func_fe6_080147A8
// func_fe6_080147C0
// func_fe6_080147D8
// func_fe6_080147F0
// func_fe6_08014804
// func_fe6_08014818
// func_fe6_0801482C
// func_fe6_08014840
// func_fe6_08014858
// func_fe6_08014870
// func_fe6_08014888
// func_fe6_080148A0
// func_fe6_080148B8
// func_fe6_080148CC
// func_fe6_080148E0
// func_fe6_080148F8
// func_fe6_0801490C
// func_fe6_08014920
// func_fe6_08014934
// func_fe6_08014948
// func_fe6_0801495C
// func_fe6_08014970
// func_fe6_08014984
// func_fe6_08014998
void WhileFadeExists(ProcPtr proc);
// func_fe6_080149CC
void func_fe6_080149E0(int kind, int speed, ProcPtr parent, Func endFunc);
// func_fe6_08014A28
// func_fe6_08014A38
// func_fe6_08014A44
// func_fe6_08014A68
void func_fe6_08014AB8(void);
// func_fe6_08014ACC
void func_fe6_08014ADC(void);
void func_fe6_08014AF8(void);
void func_fe6_08014B68(void);
void StartTemporaryLock(ProcPtr proc, int arg_1);
int NumberToString(int number, char * buf);
struct Text * PutStringCentered(u16 * tm, int color, int width, char const * str);
struct Text * PutString(u16 * tm, int color, char const * str);
void func_fe6_08014D50(void);
// func_fe6_08014D60
void func_fe6_08014D9C(u16 const * colors, int pal_offset, int pal_size, int interval, ProcPtr parent);
void func_fe6_08014DB4(u16 const * colors, int pal_offset, int pal_size, int interval, ProcPtr parent);
// func_fe6_08014DCC
void func_fe6_08014E30(u16 * tm, int x, int y, u16 tileref, int width, int height);
// func_fe6_08014E98
void func_fe6_08014F70(u16 * tm, int x, int y, u16 tileref, int width, int height, u16 const * src, int arg_7);
void func_fe6_0801501C(u16 * tm, int x, int y, u16 tileref, int width, int height, u8 const * src, int arg_7);
// func_fe6_080150DC
void CallDelayed(void (* func)(void), int delay);
void CallDelayedArg(void (* func)(int), int arg, int delay);
// func_fe6_080151E4
// func_fe6_080151F8
void func_fe6_08015208(u16 * out, int size, int value);
void StartPartialGameLock(ProcPtr proc);
void VramCopy(u8 const * src, u8 * dst, int size);
void func_fe6_08015298(u8 const * src, u8 * dst, int width, int height);
void PutTmLinear(u16 const * src, u16 * dst, int size, u16 tileref);
u16 * GetTmOffsetById(int bgid, int x, int y);
void func_fe6_08015344(void);
int Screen2Pan(int x);
void PlaySeSpacial(int song, int x);
void PlaySeDelayed(int song, int delay);
void func_fe6_0801548C(short song);
void func_fe6_0801549C(short speed);
// func_fe6_080154AC
// func_fe6_08015504
void PutDrawTextCentered(struct Text * text, int x, int y, char const * str, int width);
void VecMulMat(int const * vec, int const * mat, int * ovec);
void MatMulMat(int const * lmat, int const * rmat, int * omat);
void MatIdent(int * mat);
void MatCopy(int const * src, int * dst);
void MatRotA(int * mat, short angle);
void MatRotB(int * mat, short angle);
void MatRotC(int * mat, short angle);
void func_fe6_08015858(void);
int VecDotVec(int const * lvec, int const * rvec);
void VecCrossVec(int const * lvec, int const * rvec, int * ovec);
int func_fe6_080158B8(int arg_0, int arg_1, int arg_2, int arg_3);

extern u16 CONST_DATA Pal_AllBlack[];
extern u16 CONST_DATA Pal_AllWhite[];
extern u16 CONST_DATA Pal_AllRed[];
extern u16 CONST_DATA Pal_AllGreen[];
extern u16 CONST_DATA Pal_AllBlue[];
extern u16 CONST_DATA Pal_085C4F2C[];
