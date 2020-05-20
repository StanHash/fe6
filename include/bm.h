
#pragma once

#include "common.h"
#include "proc.h"

enum
{
    BM_FLAG_0 = (1 << 0),
    BM_FLAG_1 = (1 << 1),
    BM_FLAG_2 = (1 << 2),
    BM_FLAG_3 = (1 << 3),
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
    /* 24 */ struct Vec2u unk24;
    /* 28 */ struct Vec2 cameraMax;
    /* 2C */ u8 pad_2C[0x32 - 0x2C];
    /* 32 */ short unk_32;
    /* 34 */ short unk_34;
    /* 36 */ s8 unk_36;
    /* 37 */ s8 unk_37;
    /* 38 */ u8 pad_38[0x3D - 0x38];
    /* 3D */ u8 unk_3D;
    /* 3E */ u8 unk_3E;
    /* 3F */ u8 unk_3F;
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
    FACTION_BLUE   = 0x00,
    FACTION_RED    = 0x80,
    FACTION_GREEN  = 0x40,
    FACTION_PURPLE = 0xC0,
};

enum
{
    FACTION_ID_BLUE = 0,
    FACTION_ID_GREEN = 1,
    FACTION_ID_RED = 2,
    FACTION_ID_PURPLE = 3,
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

struct PlaySt
{
    /* 00 */ u32 unk00; // a time value
    /* 04 */ u32 unk04; // a time value

    /* 08 */ u32 gold;
    /* 0C */ u8 saveSlot;
    /* 0D */ u8 vision; // 0 means no fog
    /* 0E */ s8 chapter;
    /* 0F */ u8 faction;
    /* 10 */ u16 turn;
    /* 12 */ u8 xCursor, yCursor; // map cursor position
    /* 14 */ u8 flags; // +0x04 = postgame, +0x10 = in prep screen, +0x40 = difficult mode, +0x80 = link arena?
    /* 15 */ u8 weather;
    /* 16 */ u16 supportGain;
    /* 18 */ u8 playId;
    /* 19 */ u8 unk19;
    /* 1A */ u8 lastSortId;
    /* 1B */ u8 unk1B;

    // option bits
    u32 unk1C_1:1; // 1
    u32 unk1C_2:1; // 
    u32 unk1C_3:2; // 
    u32 unk1C_5:1; // 
    u32 cfgTextSpeed:2;
    u32 unk1C_8:1;
    u32 cfgBgmDisable:1;
    u32 cfgSeDisable:1;
    u32 cfgWindowColor:2;
    u32 unk1D_5:1; // 
    u32 unk1D_6:1; // 
    u32 unk1D_7:1; // 
    u32 unk1D_8:1; // 
    u32 unk1E_1:2; // 2
    u32 unk1E_3:1; // 
    u32 unk1E_4:2; // 
    u32 unk1E_6:1; // 
    u32 unk1E_7:1; // 
    u32 unk1E_8:2; // 
    u32 unk1F_2:2; // 
    u32 unk1F_4:5; // 
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

enum
{
    MAP_CURSOR_DEFAULT,
    MAP_CURSOR_REGULAR,
    MAP_CURSOR_RED_MOVING,
    MAP_CURSOR_STRETCHED,
    MAP_CURSOR_RED_STATIC,
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
Bool IsCameraWatchingPosition(int x, int y);
Bool CameraMove_08016290(ProcPtr proc);
void Unused_08016344(int x, int y, int duration);
int GetActiveMapSong(void);
void StartMapSongBgm(void);

extern struct ProcScr CONST_DATA ProcScr_BmMain[];
extern struct ProcScr CONST_DATA ProcScr_CamMove[];

extern struct BmSt EWRAM_DATA gBmSt;
extern struct PlaySt EWRAM_DATA gPlaySt;
