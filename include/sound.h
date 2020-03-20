
#pragma once

#include "gba/gba.h"
#include "types.h"

#include "m4a.h"

#include "proc.h"

extern struct MusicPlayerInfo gMpi_03006530;
extern struct MusicPlayerInfo gMpi_03006600;
extern struct MusicPlayerInfo gMpi_03006570;
extern struct MusicPlayerInfo gMpi_03006260;
extern struct MusicPlayerInfo gMpi_030062A0;
extern struct MusicPlayerInfo gMpi_030064B0;
extern struct MusicPlayerInfo gMpi_030062E0;
extern struct MusicPlayerInfo gMpi_030064F0;

int GetCurrentMusicSong(void);
s8 IsMusicPlaying(void);
void sub_8002F9C(int volume);
void sub_8003028(int volume);
void sub_8003064(int speed);
void sub_80030B4(int speed);
void sub_800313C(int songId, struct MusicPlayerInfo* mpi);
void sub_800319C(int songId, int speed, struct MusicPlayerInfo* mpi);
void sub_8003210(int songId, struct MusicPlayerInfo* mpi);
void sub_800322C(int songId, int speed, struct MusicPlayerInfo* mpi);
void sub_80032F0(int songId, int b, struct MusicPlayerInfo* mpi);
void sub_80033C8(int songId);
void sub_8003434(void);
void sub_80034B8(void);
void sub_80034FC(int volume, int b, int c, ProcPtr parent);
