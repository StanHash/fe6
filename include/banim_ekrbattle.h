#pragma once

#include "common.h"
#include "unit.h"
#include "battle.h"
#include "banim_sprite.h"

struct ProcEkrBattleDeamon {
    PROC_HEADER;
};

struct ProcEkrBattle {
    PROC_HEADER;

    /* 29 */ u8 speedup;
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
void EkrBattle_Init(struct ProcEkrBattle * proc);
void EkrBattle_Main(struct ProcEkrBattle * proc);
void EkrBattleStartBattleQuote(struct ProcEkrBattle * proc);
void EkrBattleWaitBattleQuote(struct ProcEkrBattle * proc);
void EkrBattleWaitWindowAppear(struct ProcEkrBattle * proc);
void EkrBattlePreDragonIntro(struct ProcEkrBattle * proc);
void EkrBattleExecDragonIntro(struct ProcEkrBattle * proc);
void EkrBattleWaitDragonIntro(struct ProcEkrBattle * proc);
void EkrBattlePostDragonIntro(struct ProcEkrBattle * proc);
void EkrBattlePostDragonIntroDelay(struct ProcEkrBattle * proc);
void EkrBattleSetUnitFlashing(struct ProcEkrBattle * proc);
void EkrBattleExecTriangleAtk(struct ProcEkrBattle * proc);
void EkrBattleWaitTriangleIdle(struct ProcEkrBattle * proc);
void EkrBattleTriggerNewRoundStart(struct ProcEkrBattle * proc);
void EkrBattleReleaseStandingAnim(struct ProcEkrBattle * proc);
void EkrBattleStartPromotion(struct ProcEkrBattle * proc);
void EkrBattleWaitPromotion(struct ProcEkrBattle * proc);
void EkrBattleInRound(struct ProcEkrBattle * proc);
void EkrBattleTriggerEnding(struct ProcEkrBattle * proc);
void EkrBattleWaitNamewinAppear(struct ProcEkrBattle * proc);
void EkrBattleWaitForPostBattleAct(struct ProcEkrBattle * proc);
void EkrBattleExecExpGain(struct ProcEkrBattle * proc);
void func_fe6_08043078(struct ProcEkrBattle * proc);
void EkrBattleExecExpBar(struct ProcEkrBattle * proc);
void EkrBattleWaitExpBar(struct ProcEkrBattle * proc);
void EkrBattlePostExpBarDelay(struct ProcEkrBattle * proc);
void EkrBattleMergeLvupImgBG(struct ProcEkrBattle * proc);
void EkrBattleLvupHanlder(struct ProcEkrBattle * proc);
void EkrBattleExecEkrLvup(struct ProcEkrBattle * proc);
void func_fe6_080433E8(struct ProcEkrBattle * proc);
void EkrBattleExecPopup(struct ProcEkrBattle * proc);
void func_fe6_08043424(struct ProcEkrBattle * proc);
void func_fe6_08043448(struct ProcEkrBattle * proc);
void func_fe6_08043484(struct ProcEkrBattle * proc);
// func_fe6_08043534
// func_fe6_08043554
// func_fe6_0804358C
// func_fe6_08043590
// func_fe6_080435AC
