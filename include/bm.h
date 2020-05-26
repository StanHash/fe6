
#pragma once

#include "common.h"
#include "proc.h"

enum
{
    BM_FLAG_0 = (1 << 0),
    BM_FLAG_1 = (1 << 1),
    BM_FLAG_2 = (1 << 2),
    BM_FLAG_3 = (1 << 3),
    BM_FLAG_4 = (1 << 4),
};

enum
{
    PARTIAL_ACTION_RESCUE_TRANSFER = (1 << 0),
    PARTIAL_ACTION_TRADED = (1 << 1),
    PARTIAL_ACTION_SUPPLY = (1 << 2),
};

enum
{
    PLAY_FLAG_0    = (1 << 0),
    PLAY_FLAG_1    = (1 << 1),
    PLAY_FLAG_2    = (1 << 2),
    PLAY_FLAG_3    = (1 << 3),
    PLAY_FLAG_4    = (1 << 4),
    PLAY_FLAG_5    = (1 << 5),
    PLAY_FLAG_HARD = (1 << 6),
    PLAY_FLAG_7    = (1 << 7),
};

enum
{
    WEATHER_NONE,

    WEATHER_SNOW,
    WEATHER_SNOWSTORM,
    WEATHER_3,
    WEATHER_RAIN,
    WEATHER_FLAMES,
    WEATHER_SANDSTORM,
    WEATHER_CLOUDS,
};

enum
{
    MAP_CURSOR_DEFAULT,
    MAP_CURSOR_REGULAR,
    MAP_CURSOR_RED_MOVING,
    MAP_CURSOR_STRETCHED,
    MAP_CURSOR_RED_STATIC,
};

enum
{
    L_BMMAIN_INIT,
    L_BMMAIN_CHANGEPHASE,
    L_BMMAIN_2,
    L_BMMAIN_DURINGPHASE,
    L_BMMAIN_4,
    L_BMMAIN_5,
    L_BMMAIN_6,
    L_BMMAIN_STARTPHASE,
    L_BMMAIN_8,
};

struct BmSt
{
    /* 00 */ Bool mainLoopEnded;
    /* 01 */ u8 lock;
    /* 02 */ u8 lockDisplay;
    /* 03 */ u8 pad_03;
    /* 04 */ u8 flags;
    /* 05 */ // pad
    /* 06 */ u16 mainLoopEndScanline;
    /* 08 */ int pad08;
    /* 0C */ struct Vec2 camera;
    /* 10 */ struct Vec2 cameraPrevious;
    /* 14 */ struct Vec2 cursor;
    /* 18 */ struct Vec2 cursorPrevious;
    /* 1C */ struct Vec2 cursorSprTarget;
    /* 20 */ struct Vec2 cursorSpr;
    /* 24 */ struct Vec2 mapRenderAnchor;
    /* 28 */ struct Vec2 cameraMax;
    /* 2C */ u16 itemOverflow;
    /* 2E */ u16 unk_2E;
    /* 30 */ Bool unk_30;
    /* 31 */ Bool unk_31;
    /* 32 */ short unk_32;
    /* 34 */ short unk_34;
    /* 36 */ s8 unk_36;
    /* 37 */ s8 unk_37;
    /* 38 */ u8 altBlendA_ca;
    /* 39 */ u8 altBlendA_cb;
    /* 3A */ u8 altBlendB_ca;
    /* 3B */ u8 altBlendB_cb;
    /* 3C */ u8 unk_3C;
    /* 3D */ u8 partialActionsTaken;
    /* 3E */ u8 unk_3E;
    /* 3F */ u8 unk_3F;
};

struct PlaySt
{
    /* 00 */ u32 unk00; // a time value
    /* 04 */ u32 unk04; // a time value

    /* 08 */ int gold;
    /* 0C */ u8 saveSlot;
    /* 0D */ u8 vision;
    /* 0E */ s8 chapter;
    /* 0F */ u8 faction;
    /* 10 */ u16 turn;
    /* 12 */ u8 xCursor, yCursor;
    /* 14 */ u8 flags;
    /* 15 */ u8 weather;
    /* 16 */ u16 supportGain;
    /* 18 */ u8 playId;
    /* 19 */ u8 unk19;
    /* 1A */ u8 lastSortId;
    /* 1B */ u8 unk1B;

    // option bits
    u32 unk_1C_1:1; // 1
    u32 unk_1C_2:1; // 
    u32 unk_1C_3:2; // 
    u32 configNoAutoCursor:1;
    u32 configTextSpeed:2;
    u32 unk_1C_8:1;
    u32 configBgmDisable:1;
    u32 configSeDisable:1;
    u32 configWindowColor:2;
    u32 unk_1D_5:1; // 
    u32 unk_1D_6:1; // 
    u32 configNoAutoEndTurn:1;
    u32 unk_1D_8:1; // 
    u32 unk_1E_1:2; // 2
    u32 unk_1E_3:1; // 
    u32 unk_1E_4:2; // 
    u32 unk_1E_6:1; // 
    u32 debugRedControl:2;
    u32 debugGreenControl:2;
    u32 unk_1F_3:6; // 
};

void OnVBlank(void);
void OnMain(void);
void LockGame(void);
void UnlockGame(void);
u8 GetGameLock(void);
void InitBmBgLayers(void);
void ApplySystemObjectsGraphics(void);
void ApplySystemGraphics(void);
void HandleMapCursorInput(u16 keys);
void HandleMoveMapCursor(int step);
void HandleMoveCameraWithMapCursor(int step);
u16 GetCameraAdjustedX(int x);
u16 GetCameraAdjustedY(int y);
u16 GetCameraCenteredX(int x);
u16 GetCameraCenteredY(int y);
void PutMapCursor(int x, int y, int kind);
void SetMapCursorPosition(int x, int y);
void PutSysArrow(int x, int y, u8 isDown);
void PutSysAButton(int x, int y, int palid);
Bool CameraMoveWatchPosition(ProcPtr proc, int x, int y);
Bool IsCameraNotWatchingPosition(int x, int y);
Bool CameraMove_08016290(ProcPtr proc);
void Unused_08016344(int x, int y, int duration);
int GetActiveMapSong(void);
void StartMapSongBgm(void);

extern struct ProcScr CONST_DATA ProcScr_BmMain[];
extern struct ProcScr CONST_DATA ProcScr_CamMove[];

extern struct BmSt EWRAM_DATA gBmSt;
extern struct PlaySt EWRAM_DATA gPlaySt;
