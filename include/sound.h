#pragma once

#include "common.h"

#include "proc.h"
#include "bm.h"

#include "m4a.h"

extern struct MusicPlayer gMusicPlayer_03006530;
extern struct MusicPlayer gMusicPlayer_03006600;
extern struct MusicPlayer gMusicPlayer_03006570;
extern struct MusicPlayer gMusicPlayer_03006260;
extern struct MusicPlayer gMusicPlayer_030062A0;
extern struct MusicPlayer gMusicPlayer_030064B0;
extern struct MusicPlayer gMusicPlayer_FightBgm;
extern struct MusicPlayer gMusicPlayer_MainBgm;

int GetCurrentBgmSong(void);
bool IsBgmPlaying(void);
void func_fe6_08002F9C(int volume);
void SetBgmVolume(int volume);
void FadeBgmOut(int speed);
void func_fe6_080030B4(int speed);
void StartBgmCore(int song, struct MusicPlayer * music_player);
void StartOrChangeBgm(int song, int speed, struct MusicPlayer * music_player);
void StartBgm(int song, struct MusicPlayer * music_player);
void StartBgmExt(int song, int speed, struct MusicPlayer * music_player);
void StartBgmFadeIn(int song, int b, struct MusicPlayer * music_player);
void OverrideBgm(int song);
void RestoreBgm(void);
void MakeBgmOverridePersist(void);
void StartBgmVolumeChange(int volumeInit, int volumeEnd, int duration, ProcPtr parent);

#define PlaySe(id) \
    if (!gPlaySt.config_se_disable) \
        m4aSongNumStart((id))
