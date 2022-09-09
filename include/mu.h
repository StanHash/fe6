#pragma once

#include "common.h"

#include "proc.h"
#include "sprite-anim.h"

enum
{
    MU_STATE_NONE,
    MU_STATE_INACTIVE,
    MU_STATE_MOVEMENT,
    MU_STATE_SLEEPING,
    MU_STATE_UNK4,
    MU_STATE_BUMPING,
    MU_STATE_DISPLAY_UI,
    MU_STATE_DEATHFADE,
};

enum
{
    MU_FLASH_WHITE,
    MU_FLASH_BLACK,
    MU_FLASH_RED,
    MU_FLASH_GREEN,
    MU_FLASH_BLUE,
    MU_FLASH_5,
};

struct MuInfo
{
    u8 const* img;
    u16 const* anim;
};

struct MuConfig;

struct MuProc
{
    /* 00 */ PROC_HEADER;

    /* 2C */ struct Unit* unit;
    /* 30 */ struct SpriteAnim* sprite_anim;
    /* 34 */ struct MuConfig* config;

    /* 38 */ u8 cam_b;
    /* 39 */ u8 state;
    /* 3A */ u8 hidden_b;
    /* 3B */ u8 jid;
    /* 3C */ i8 facing;
    /* 3D */ u8 step_sound_clock;
    /* 3E */ u8 fast_walk_b;
    /* 3F */ // pad
    /* 40 */ u16 move_clock_q4;
    /* 42 */ i16 move_config;
    /* 44 */ i16 x_q4, y_q4;
    /* 48 */ i16 x_offset_q4, y_offset_q4;
};

struct MuConfig
{
    /* 00 */ u8 id;
    /* 01 */ u8 pal;
    /* 02 */ u16 chr;
    /* 04 */ u8 pc;
    /* 05 */ i8 movescr[0x40];
    /* 45 */ // 3 byte padding
    /* 48 */ struct MuProc* mu;
};

void InitMus(void);
struct MuProc* StartMuExt(int x, int y, int jid, int arg_3);
struct MuProc* StartMu(struct Unit* unit);
void UpdateMu(struct MuProc* mu);
void EnableMuCamera(struct MuProc* mu);
void DisableMuCamera(struct MuProc* mu);
struct MuProc* StartUiMu(struct Unit* unit, int x, int y);
struct MuProc* StartMuInternal(u16 x, u16 y, u16 jid, int pal);
void SetMuFacing(struct MuProc* mu, int facing);
void SetMuDefaultFacing(struct MuProc* mu);
void SetAutoMuDefaultFacing(void);
void SetAutoMuMoveScript(u8 const* movescr);
bool MuExists(void);
bool MuExistsActive(void);
bool IsMuActive(struct MuProc* proc);
void SetMuMoveScript(struct MuProc* mu, u8 const* movescr);
struct MuProc* StartMuScripted(u16 x, u16 y, u16 jid, int pal, u8 const* movescr);
void StartPlayMuStepSe(int song, int alt_offset, int x);
void PlayMuStepSe(struct MuProc* mu);
void EndMuMovement(struct MuProc* mu);
void RunMuMoveScript(struct MuProc* mu);
void StartMuFogBump(int x, int y);
bool IsMuFogBumpActive(void);
void UpdateMuStepSounds(struct MuProc* mu);
void EndAllMus(void);
void EndMu(struct MuProc* proc);
void HaltMu(struct MuProc* mu);
void LockMus(void);
void ReleaseMus(void);
void ApplyMoveScriptToCoordinates(int* x, int* y, u8 const* movescr);
bool CanStartMu(void);
void ResetMuAnims(void);
struct MuConfig* GetNewMuConfig(void);
bool GetMuDisplayPosition(struct MuProc* mu, struct Vec2i* out);
void PutMu(struct MuProc* mu);
u16 GetMuQ4MovementSpeed(struct MuProc* mu);
u8* GetMuImgBufById(int id);
u8 const* GetMuImg(struct MuProc* proc);
u16 const* GetMuAnimForJid(u16 jid);
void StartMuDeathFade(struct MuProc* mu);
void HideMu(struct MuProc* mu);
void ShowMu(struct MuProc* mu);
void SetMuScreenPosition(struct MuProc* mu, int x, int y);
void SetMuScreenOffset(struct MuProc* mu, int x_offset, int y_offset);
void StartMuFadeIntoFlash(struct MuProc* mu, int flash);
void StartMuFadeFromFlash(struct MuProc* mu);
void StartMuActionAnim(struct MuProc* mu);
void StartMuDelayedFaceTarget(struct MuProc* mu);
void StartMuSlowDownAnim(struct MuProc* mu);
void func_fe6_0806142C(struct MuProc* mu, int flash);
void StartMuFlashFadeFrom(struct MuProc* mu, int flash);
void SetMuMaxWalkSpeed(void);
void SetMuSpecialSprite(struct MuProc* mu, int jid, u16 const* pal);
void SetMuPal(struct MuProc* mu, int pal);

extern struct ProcScr CONST_DATA ProcScr_Mu[];
extern struct ProcScr CONST_DATA ProcScr_MuDeathFade[];
extern struct MuInfo CONST_DATA MuInfoTable[];
