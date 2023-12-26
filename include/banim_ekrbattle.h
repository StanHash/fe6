#pragma once

#include "common.h"
#include "banim_sprite.h"

struct ProcEkrBattleDeamon {
    PROC_HEADER;
};

struct ProcEkrBattle {
    PROC_HEADER;

    /* 29 */ u8 unk29;
    /* 2A */ STRUCT_PAD(0x2A, 0x2C);
    /* 2C */ i16 timer;
    /* 2E */ i16 end;
    /* 30 */ STRUCT_PAD(0x30, 0x44);
    /* 44 */ int side;
    /* 48 */ int counter;
    /* 4C */ STRUCT_PAD(0x4C, 0x54);
    /* 54 */ int quote;
    /* 58 */ int unk58;
    /* 5C */ struct BaSprite * anim;
};

extern struct ProcEkrBattle * gpProcEkrBattle;

void SetBanimLinkArenaFlag(int arg_0);
// GetBanimLinkArenaFlag
// NewEkrBattleDeamon
// EndEkrBattleDeamon
i8 IsBattleDeamonActive(void);
// EkrBattleDeamon_OnEnd
// null_080425EC
// NewEkrBattle
void InBattleMainRoutine(void);
void MainUpdateEkrBattle(void);
// null_08042780
// EkrBattle_Init
// func_fe6_08042818
// func_fe6_0804286C
// func_fe6_08042908
// func_fe6_0804294C
// func_fe6_08042970
// func_fe6_0804298C
// func_fe6_08042A3C
// func_fe6_08042A5C
// func_fe6_08042AA8
// func_fe6_08042AC4
// func_fe6_08042B18
// func_fe6_08042B4C
// func_fe6_08042B74
// func_fe6_08042BF8
// func_fe6_08042C0C
// func_fe6_08042C48
// func_fe6_08042C74
// func_fe6_08042D70
// func_fe6_08042D84
// func_fe6_08042E14
// func_fe6_08042E58
// func_fe6_08043078
// func_fe6_080430C4
// func_fe6_0804312C
// func_fe6_08043208
// func_fe6_0804323C
// func_fe6_08043288
// func_fe6_080433B0
// func_fe6_080433E8
// func_fe6_0804340C
// func_fe6_08043424
// func_fe6_08043448
// func_fe6_08043484
// func_fe6_08043534
// func_fe6_08043554
// func_fe6_0804358C
// func_fe6_08043590
// func_fe6_080435AC

extern int gEkrDebugTimer;
extern int gEkrDebugUnk1;
extern int gEkrDebugUnk2;
extern int gCtrlC01Blocking;

extern i16 gEkrDebugModeMaybe;

extern struct ProcScr ProcScr_EkrBattleDeamon[];
extern struct ProcScr ProcScr_EkrBattle[];
extern u32 gEkrBattleEndFlag;
extern u32 gBanimDoneFlag[2];
