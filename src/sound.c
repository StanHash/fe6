
#include "sound.h"

#include "proc.h"

extern struct PlaySt gPlaySt;

int sub_8013B24(int, int, int, int, int);

struct SoundSt
{
    /* 00 */ u16 unused00;
    /* 02 */ u16 overwrittenSongId;
    /* 04 */ u16 songId;
    /* 06 */ s8 songPlaying;
};

struct MusicProc
{
    /* 00 */ PROC_HEADER;

    /* 29 */ u8 pad29[0x4A - 0x29];
    /* 4A */ short songId;
    /* 4C */ short clock;
    /* 4E */ short fiTimeEnd;

    /* 50 */ u8 pad50[0x54 - 0x50];
    /* 54 */ struct MusicPlayerInfo* mpi;

    /* 58 */ u8 pad60[0x64 - 0x58];
    /* 64 */ short vcInitVolume;
    /* 66 */ short vcEndVolume;
    /* 68 */ short vcClock;
    /* 6A */ short vcTimeEnd;
};

static void MusicFi_OnLoop(struct MusicProc* proc);
static void MusicVc_OnLoop(struct MusicProc* proc);
static void DelaySong_OnLoop(struct MusicProc* proc);

static void PlaySongDelayed(int songId, int delay, struct MusicPlayerInfo* mpi);
static void PlaySongCore(int songId, struct MusicPlayerInfo* mpi);

static struct SoundSt EWRAM_DATA sSoundSt = {};

struct ProcScr CONST_DATA ProcScr_MusicFadeIn[] =
{
    PROC_END_DUPLICATES,
    PROC_REPEAT(MusicFi_OnLoop),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_MusicVolChange[] =
{
    PROC_REPEAT(MusicVc_OnLoop),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_DelaySong[] =
{
    PROC_REPEAT(DelaySong_OnLoop),
    PROC_END,
};

int GetCurrentMusicSong(void)
{
    return sSoundSt.songId;
}

s8 IsMusicPlaying(void)
{
    return sSoundSt.songPlaying;
}

void sub_8002F9C(int volume)
{
    m4aMPlayVolumeControl(&gMpi_03006530, 0xFFFF, volume);
    m4aMPlayVolumeControl(&gMpi_03006600, 0xFFFF, volume);
    m4aMPlayVolumeControl(&gMpi_03006570, 0xFFFF, volume);
    m4aMPlayVolumeControl(&gMpi_03006260, 0xFFFF, volume);
    m4aMPlayVolumeControl(&gMpi_030062A0, 0xFFFF, volume);
    m4aMPlayVolumeControl(&gMpi_030064B0, 0xFFFF, volume);
}

void sub_8003028(int volume)
{
    m4aMPlayVolumeControl(&gMpi_030062E0, 0xFFFF, volume);
    m4aMPlayVolumeControl(&gMpi_030064F0, 0xFFFF, volume);
}

void sub_8003064(int speed)
{
    if (speed < 0)
        speed = 6;

    m4aMPlayFadeOut(&gMpi_030062E0, speed);
    m4aMPlayFadeOut(&gMpi_030064F0, speed);

    sSoundSt.songPlaying = FALSE;
}

void sub_80030B4(int speed)
{
    if (speed == 0)
        speed = 6;

    m4aMPlayFadeOut(&gMpi_03006530, speed);
    m4aMPlayFadeOut(&gMpi_03006600, speed);
    m4aMPlayFadeOut(&gMpi_03006570, speed);
    m4aMPlayFadeOut(&gMpi_03006260, speed);
    m4aMPlayFadeOut(&gMpi_030062A0, speed);
    m4aMPlayFadeOut(&gMpi_030064B0, speed);
}

void sub_800313C(int songId, struct MusicPlayerInfo* mpi)
{
    sSoundSt.songPlaying = TRUE;
    sSoundSt.songId = songId;

    PlaySongCore(songId, mpi);

    m4aMPlayImmInit(&gMpi_030062E0);
    m4aMPlayImmInit(&gMpi_030064F0);
}

void sub_800319C(int songId, int speed, struct MusicPlayerInfo* mpi)
{
    if (sSoundSt.songPlaying && GetCurrentMusicSong() == songId)
        return;

    if (gPlaySt.unk1D_1)
        return;

    if (sSoundSt.songPlaying)
    {
        sub_8003064(speed);
        PlaySongDelayed(songId, speed * 16, mpi);
    }
    else
    {
        sub_800313C(songId, mpi);
    }
}

void sub_8003210(int songId, struct MusicPlayerInfo* mpi)
{
    sub_800319C(songId, 3, mpi);
}

void sub_800322C(int songId, int speed, struct MusicPlayerInfo* mpi)
{
    sub_800319C(songId, speed, mpi);
}

void MusicFi_OnLoop(struct MusicProc* proc)
{
    int volume = sub_8013B24(0, 0, 0x100, proc->clock, proc->fiTimeEnd);

    m4aMPlayVolumeControl(&gMpi_030062E0, 0xFFFF, volume);
    m4aMPlayVolumeControl(&gMpi_030064F0, 0xFFFF, volume);

    proc->clock++;

    if (proc->clock >= proc->fiTimeEnd)
        Proc_Break(proc);
}

void sub_80032F0(int songId, int duration, struct MusicPlayerInfo* mpi)
{
    struct MusicProc* proc;

    if (gPlaySt.unk1D_1)
        return;

    sSoundSt.songPlaying = TRUE;
    sSoundSt.songId = songId;

    proc = Proc_Create(ProcScr_MusicFadeIn, PROC_TREE_3);

    m4aMPlayStop(&gMpi_030062E0);
    m4aMPlayStop(&gMpi_030064F0);

    PlaySongCore(songId, mpi);

    m4aMPlayImmInit(&gMpi_030062E0);
    m4aMPlayImmInit(&gMpi_030064F0);

    m4aMPlayVolumeControl(&gMpi_030062E0, 0xFFFF, 0);
    m4aMPlayVolumeControl(&gMpi_030064F0, 0xFFFF, 0);

    proc->clock = 0;
    proc->fiTimeEnd = duration * 16;
}

void sub_80033C8(int songId)
{
    if (gPlaySt.unk1D_1)
        return;

    sSoundSt.overwrittenSongId = sSoundSt.songId;

    m4aMPlayFadeOutTemporarily(&gMpi_030064F0, 3);

    sSoundSt.songPlaying = FALSE;

    if (songId != 0)
        PlaySongDelayed(songId, 32, &gMpi_030062E0);
}

void sub_8003434(void)
{
    if (gPlaySt.unk1D_1)
        return;

    if (sSoundSt.overwrittenSongId == 0)
        return;

    m4aMPlayFadeOut(&gMpi_030062E0, 3);
    m4aMPlayFadeIn(&gMpi_030064F0, 6);

    sSoundSt.songPlaying = TRUE;

    sSoundSt.songId = sSoundSt.overwrittenSongId;
    sSoundSt.overwrittenSongId = 0;
}

void sub_80034B8(void)
{
    if (gPlaySt.unk1D_1)
        return;

    sSoundSt.songId = sSoundSt.overwrittenSongId;
    sSoundSt.overwrittenSongId = 0;
}

void StartMusicVolumeChange(int volumeInit, int volumeEnd, int duration, ProcPtr parent)
{
    struct MusicProc* proc = Proc_CreateBlockingChild(ProcScr_MusicVolChange, parent);

    proc->vcInitVolume = volumeInit;
    proc->vcEndVolume = volumeEnd;
    proc->vcClock = 0;
    proc->vcTimeEnd = duration;
}

void MusicVc_OnLoop(struct MusicProc* proc)
{
    int volume = sub_8013B24(0, proc->vcInitVolume, proc->vcEndVolume, proc->vcClock++, proc->vcTimeEnd);

    sub_8003028(volume);

    if (proc->vcClock >= proc->vcTimeEnd)
    {
        if (proc->vcEndVolume == 0)
        {
            m4aSongNumStop(GetCurrentMusicSong());
            sSoundSt.songPlaying = FALSE;
        }

        Proc_Break(proc);
    }
}

void DelaySong_OnLoop(struct MusicProc* proc)
{
    proc->clock--;

    if (proc->clock >= 0)
        return;

    sSoundSt.songPlaying = TRUE;
    sSoundSt.songId = proc->songId;

    PlaySongCore(proc->songId, proc->mpi);
    Proc_Delete(proc);
}

void PlaySongDelayed(int songId, int delay, struct MusicPlayerInfo* mpi)
{
    struct MusicProc* proc;

    if (gPlaySt.unk1D_1)
        return;

    proc = Proc_Create(ProcScr_DelaySong, PROC_TREE_3);

    proc->clock = delay;
    proc->songId = songId;
    proc->mpi = mpi;
}

void PlaySongCore(int songId, struct MusicPlayerInfo* mpi)
{
    if (mpi)
        MPlayStart(mpi, gSongTable[songId].header);
    else
        m4aSongNumStart(songId);
}
