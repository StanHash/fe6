#pragma once

#include "prelude.h"
#include "banim_sprite.h"

extern ProcPtr gpProcEkrIdunnBodyFlashing;
extern u16 gEkrDragonIntroDone[2];
extern u16 gEkrDragonFastenConf[2];

enum EkrDragonState_idx {
    DRAGON_STATE_DEFAULT = 0,
    DRAGON_STATE_1 = 1,
    DRAGON_STATE_ENDING = 2,
};

extern u16 gEkrDragonState[2];
extern u16 gUnk_Banim_0201E7CC[];
extern u16 gEkrDragonJid[2];
extern u16 gEkrDragonFastenConf[2];
extern u16 gEkrBgPaletteBackup1[0x20];
extern u16 gEkrBgPaletteBackup2[0x20];
extern u16 gEkrBgPaletteBackup3[0x40];

void ResetEkrDragonStatus(void);
bool EkrDragonIntroDone(struct BaSprite * anim);
void TriggerEkrDragonEnding(struct BaSprite * anim);
bool CheckEkrDragonEndingDone(struct BaSprite * anim);

enum ekr_dragon_status_type_bitfile {
    EDRAGON_TYPE_MANAKETE_L = 1 << 0,
    EDRAGON_TYPE_MANAKETE_R = 1 << 1,
    EDRAGON_TYPE_FAE_L = 1 << 2,
    EDRAGON_TYPE_FAE_R = 1 << 3,
    EDRAGON_TYPE_IDUNN_L = 1 << 4,
    EDRAGON_TYPE_IDUNN_R = 1 << 5,
};

u32 GetEkrDragonStateTypeGeneric(void); /* Different form FE8, this is a bitfile rather than enum */
u32 GetEkrDragonStateType(void);
u32 GetEkrDragonStateTypeIdunn(void);
bool CheckSkipDragonTransfer(struct BaSprite * anim);
u16 * GetEkrDragonJid(int pos);
u16 * CheckEkrDragonFasten(struct BaSprite * anim);
ProcPtr GetEkrDragonProc(struct BaSprite * anim);
void EndEkrDragonDaemon(struct BaSprite * anim);
void SetDragonBasLayer(u8 layer);

struct ProcEkrDragonIntroFx {
    PROC_HEADER;

    /* 29 */ u8 flag;
    /* 2A */ u16 unk2A;
    /* 2C */ i16 timer;
    /* 2E */ i16 timer2;

    STRUCT_PAD(0x30, 0x32);

    /* 32 */ u16 x;
    /* 34 */ i16 x_hi;

    STRUCT_PAD(0x36, 0x3A);

    /* 3A */ i16 y;
    /* 3C */ i16 y_hi;

    STRUCT_PAD(0x3E, 0x44);

    /* 44 */ int duration;
    /* 48 */ int step;
    /* 4C */ int speed;
    /* 50 */ int unk50;
};

struct ProcEkrDragon {
    PROC_HEADER;

    /* 29 */ u8 done;

    STRUCT_PAD(0x2A, 0x2C);

    /* 2C */ i16 timer;
    /* 2E */ i16 terminator;
    /* 30 */ i16 timer2;
    /* 32 */ i16 x; 

    STRUCT_PAD(0x34, 0x3A);

    /* 3A */ i16 y_lo;
    /* 3C */ i16 y_hi;

    STRUCT_PAD(0x3E, 0x44);

    /* 44 */ ProcPtr sproc_flashingobj;
    /* 48 */ ProcPtr sproc_bg2fx;
    /* 4C */ ProcPtr sproc_bg2scroll;
    /* 50 */ ProcPtr mainfxproc;
    /* 54 */ ProcPtr proc54;
    /* 58 */ ProcPtr sproc_bg2scrollhandle;
    /* 5C */ struct BaSprite * anim;
    /* 60 */ ProcPtr sproc1;
    /* 64 */ struct ProcEkrDragonIntroFx * procfx;
    /* 68 */ ProcPtr sproc_flashingbg;
};

extern struct ProcEkrDragon * EkrDragonProcs[2];

struct ProcEkrDragonDeamon {
    PROC_HEADER;

    /* 29 */ u8 fxtype;

    STRUCT_PAD(0x2A, 0x2C);

    /* 2C */ i16 timer;

    STRUCT_PAD(0x2E, 0x32);

    /* 32 */ i16 x;
    /* 34 */ i16 x_hi;

    STRUCT_PAD(0x36, 0x3A);

    /* 3A */ i16 y;
    /* 3C */ i16 y_hi;

    STRUCT_PAD(0x3E, 0x44);

    /* 44 */ u32 frame;
    /* 48 */ const i16 * conf;
    /* 4C */ const u16 * pal;

    STRUCT_PAD(0x50, 0x54);

    /* 54 */ u32 round_cur;

    STRUCT_PAD(0x58, 0x5C);

    /* 5C */ struct BaSprite * anim;
};

extern struct ProcEkrDragonDeamon * gEkrDragonDeamonProcs[2];

void PutManaketeBodyPalette(struct ProcEkrDragon * proc);
void PutManaketeBodyIntro2(struct ProcEkrDragon * proc);
void PutManaketeBodyIntro1(struct ProcEkrDragon * proc);
void PutManaketeBodyStd(struct ProcEkrDragon * proc);

struct ProcEkrDragonMoveBg3 {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);
    
    /* 2C */ i16 timer;

    STRUCT_PAD(0x2E, 0x44);

    /* 44 */ int x;
};

void EkrDragonMoveBg3(int x);
void EkrDragonMoveBg3_Loop(struct ProcEkrDragonMoveBg3 * proc);
void PutManaketeTotalImg(struct ProcEkrDragon * proc);
void ResetDragonAnimfx(void);
void RestoreBodyFlashingPalForManakete(int pos);
void RestoreBodyFlashingPalForIdunn(int pos);
void EfxBodyFlashingForDragon(int pos);
int GetDragonPosition(void);
void InitEkrDragonStatus(void);
int func_fe6_08058F38(void);
void EkrDragonTmCpyExt(int x);
void func_fe6_08058FA8(const u8 * tsa);
void func_fe6_08059018(const u8 * tsa);

struct ProcEkrDragonBark {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x5C);

    /* 5C */ struct BaSprite * anim;
};

void NewEkrDragonBark(struct BaSprite * anim);
void EkrDragonBarkExt(struct ProcEkrDragonBark * proc);

void NewEkrManakete(struct BaSprite * anim);
void EkrManakete_BgFadeIn(struct ProcEkrDragon * proc);
void func_fe6_08059144(struct ProcEkrDragon * proc);
void EkrManakete_PauseOnStart(struct ProcEkrDragon * proc);
void func_fe6_080591CC(struct ProcEkrDragon * proc);
void func_fe6_080592D0(struct ProcEkrDragon * proc);
void EkrManakete_UpdateBanimfx(struct ProcEkrDragon * proc);
void EkrManakete_BlockingInBattle(struct ProcEkrDragon * proc);
void EkrManakete_EndDeamon(struct ProcEkrDragon * proc);
void EkrManakete_StartExit(struct ProcEkrDragon * proc);
void func_fe6_0805946C(struct ProcEkrDragon * proc);
void func_fe6_080594CC(struct ProcEkrDragon * proc);
void func_fe6_08059578(struct ProcEkrDragon * proc);
void func_fe6_080595EC(struct ProcEkrDragon * proc);
void EkrManakete_ReloadBg(struct ProcEkrDragon * proc);
void EkrManakete_TriggerEnding(struct ProcEkrDragon * proc);

struct ProcEkrManaketefx {
    PROC_HEADER;
    STRUCT_PAD(0x29, 0x2C);

    /* 2C */ i16 timer;

    STRUCT_PAD(0x2E, 0x5C);

    /* 5C */ struct BaSprite * anim;
    /* 60 */ struct BaSprite * animfx;
};

void StartManaketeTransferAnim(struct BaSprite * anim, int type);
void EkrManakete_OnEnd(struct ProcEkrManaketefx * proc);
void EkrManaketeEnter1(struct ProcEkrManaketefx * proc);
void EkrManaketeEnter2(struct ProcEkrManaketefx * proc);
void EkrManaketeEnter3(struct ProcEkrManaketefx * proc);
void EkrManaketeExit3(struct ProcEkrManaketefx * proc);
void EkrManaketeExit2(struct ProcEkrManaketefx * proc);
void EkrManaketeExit1(struct ProcEkrManaketefx * proc);

void NewEkrManaketeDeamon(struct BaSprite * anim);
void EkrManaketeDeamon_Loop(struct ProcEkrDragonDeamon * proc);

void NewEkrDragonFae(struct BaSprite * anim);
void EkrFae_PauseOnStart(struct ProcEkrDragon * proc);
void EkrFae_StartTransfer(struct ProcEkrDragon * proc);
void EkrFae_UpdateBanimfx(struct ProcEkrDragon * proc);
void EkrFae_WaitBattleDone(struct ProcEkrDragon * proc);
void EkrFae_ReloadBanimBak(struct ProcEkrDragon * proc);
void EkrFae_PauseOnEnd(struct ProcEkrDragon * proc);
void EkrFae_TriggerEnding(struct ProcEkrDragon * proc);

struct ProcEkrFaefx {
    PROC_HEADER;

    /* 29 */ u8 fxtype;

    STRUCT_PAD(0x2A, 0x2C);

    /* 2C */ i16 timer;

    STRUCT_PAD(0x2E, 0x44);

    /* 44 */ u32 frame;
    /* 48 */ const u16 * frame_config;
    /* 4C */ const u16 ** tsal;
    /* 50 */ const u16 ** tsar;
    /* 54 */ u16 ** img;
    /* 58 */ u16 ** pal;
    /* 5C */ struct BaSprite * anim;
};

void StartEkrFaeTransferfx(struct BaSprite * anim);
void EkrFaeTransferBackfx_Loop(struct ProcEkrFaefx * proc);

void NewEkrDragonIdunn(struct BaSprite * anim);
void EkrIdunn_BgFadeIn(struct ProcEkrDragon * proc);
void EkrIdunn_InitBanimfx(struct ProcEkrDragon * proc);
void EkrIdunn_InitBodyfx(struct ProcEkrDragon * proc);
void EkrIdunn_PreMainBodyIntro(struct ProcEkrDragon * proc);
void EkrIdunn_InitIntroBodyPosition(struct ProcEkrDragon * proc);
void func_fe6_0805A0BC(struct ProcEkrDragon * proc);
void EkrIdunn_BodyFallInAndTriggerBattleStart(struct ProcEkrDragon * proc);
void EkrIdunn_BlockingInBattle(struct ProcEkrDragon * proc);
void func_fe6_0805A270(struct ProcEkrDragon * proc);
void func_fe6_0805A2BC(struct ProcEkrDragon * proc);
void func_fe6_0805A35C(struct ProcEkrDragon * proc);
void func_fe6_0805A394(struct ProcEkrDragon * proc);
void func_fe6_0805A3EC(struct ProcEkrDragon * proc);

ProcPtr NewEfxIdunnIntro(struct BaSprite * anim);
// func_fe6_0805A434
// func_fe6_0805A4B4
// func_fe6_0805A4C8
// func_fe6_0805A51C
// func_fe6_0805A584
ProcPtr NewEfxIdunnMain(struct BaSprite * anim);
// func_fe6_0805A5C4
// func_fe6_0805A63C
ProcPtr NewEkrIdunnExitAnim2(struct BaSprite * anim, int, int);
// func_fe6_0805A6B8
// func_fe6_0805A6DC
// func_fe6_0805A768
ProcPtr NewEkrIdunnIntroDeamon1(struct BaSprite * anim);
// func_fe6_0805A7C0
ProcPtr NewEkrIdunnIntroDeamon2(struct BaSprite * anim);
// func_fe6_0805A82C
void NewEkrIdunnBodyFlashing(struct BaSprite * anim);
void EndEkrIdunnBodyFlashing(void);
// func_fe6_0805A8B0
void NewEfxAvoidForIdunn(struct BaSprite * anim);
// func_fe6_0805A9F8
// func_fe6_0805AAA0
// func_fe6_0805AB50
ProcPtr NewEkrIdunnExitAnim1(struct BaSprite * anim);
// func_fe6_0805ABC0
// func_fe6_0805AC54
// func_fe6_0805ADE4
// func_fe6_0805AE08
// func_fe6_0805AE1C
// func_fe6_0805AE6C
// func_fe6_0805AEDC
// func_fe6_0805AF34
// func_fe6_0805AFA4
// func_fe6_0805AFD4
// func_fe6_0805AFEC
