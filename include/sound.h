
#pragma once

#include "common.h"
#include "proc.h"

#include "m4a.h"

extern struct MusicPlayerInfo gMpi_03006530;
extern struct MusicPlayerInfo gMpi_03006600;
extern struct MusicPlayerInfo gMpi_03006570;
extern struct MusicPlayerInfo gMpi_03006260;
extern struct MusicPlayerInfo gMpi_030062A0;
extern struct MusicPlayerInfo gMpi_030064B0;
extern struct MusicPlayerInfo gMpi_FightBgm;
extern struct MusicPlayerInfo gMpi_MainBgm;

int GetCurrentBgmSong(void);
s8 IsBgmPlaying(void);
void sub_8002F9C(int volume);
void SetBgmVolume(int volume);
void FadeBgmOut(int speed);
void sub_80030B4(int speed);
void StartBgmCore(int songId, struct MusicPlayerInfo* mpi);
void StartOrChangeBgm(int songId, int speed, struct MusicPlayerInfo* mpi);
void StartBgm(int songId, struct MusicPlayerInfo* mpi);
void StartBgmExt(int songId, int speed, struct MusicPlayerInfo* mpi);
void StartBgmFadeIn(int songId, int b, struct MusicPlayerInfo* mpi);
void OverrideBgm(int songId);
void RestoreBgm(void);
void MakeBgmOverridePersist(void);
void StartBgmVolumeChange(int volumeInit, int volumeEnd, int duration, ProcPtr parent);

#define PlaySe(id) \
    if (!gPlaySt.cfgSeDisable) \
        m4aSongNumStart((id))
