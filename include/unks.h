
#pragma once

#include "gba/gba.h"
#include "types.h"

#include "proc.h"

void Decompress(void const* src, void* dst);
void sub_8013E58(u16* tm, int tileref, int width, int height);
void sub_80141E0(int palid, int arg_2, ProcPtr proc);
void sub_8014218(u16 const* pal, int palid, int arg_2, ProcPtr proc);
void sub_8014374(int pal);

extern u8 const Img_FactionMiniCard[];
extern u16 const Pal_FactionMiniCard[];
extern u8 const Tsa_Unk_08101974[];
extern u8 const Tsa_Unk_08101A2C[];
extern struct ProcScr CONST_DATA ProcScr_CamMove[];
extern struct FaceInfo CONST_DATA FaceInfoTable[];