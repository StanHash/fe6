
#include "common.h"
#include "sound.h"

#include "proc.h"
#include "util.h"

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
    PROC_END_DUPS,
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

int GetCurrentBgmSong(void)
{
    return sSoundSt.songId;
}

Bool IsBgmPlaying(void)
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

void SetBgmVolume(int volume)
{
    m4aMPlayVolumeControl(&gMpi_FightBgm, 0xFFFF, volume);
    m4aMPlayVolumeControl(&gMpi_MainBgm, 0xFFFF, volume);
}

void FadeBgmOut(int speed)
{
    if (speed < 0)
        speed = 6;

    m4aMPlayFadeOut(&gMpi_FightBgm, speed);
    m4aMPlayFadeOut(&gMpi_MainBgm, speed);

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

void StartBgmCore(int songId, struct MusicPlayerInfo* mpi)
{
    sSoundSt.songPlaying = TRUE;
    sSoundSt.songId = songId;

    PlaySongCore(songId, mpi);

    m4aMPlayImmInit(&gMpi_FightBgm);
    m4aMPlayImmInit(&gMpi_MainBgm);
}

void StartOrChangeBgm(int songId, int speed, struct MusicPlayerInfo* mpi)
{
    if (sSoundSt.songPlaying && GetCurrentBgmSong() == songId)
        return;

    if (gPlaySt.cfgBgmDisable)
        return;

    if (sSoundSt.songPlaying)
    {
        FadeBgmOut(speed);
        PlaySongDelayed(songId, speed * 16, mpi);
    }
    else
    {
        StartBgmCore(songId, mpi);
    }
}

void StartBgm(int songId, struct MusicPlayerInfo* mpi)
{
    StartOrChangeBgm(songId, 3, mpi);
}

void StartBgmExt(int songId, int speed, struct MusicPlayerInfo* mpi)
{
    StartOrChangeBgm(songId, speed, mpi);
}

void MusicFi_OnLoop(struct MusicProc* proc)
{
    int volume = Interpolate(INTERPOLATE_LINEAR, 0, 0x100, proc->clock, proc->fiTimeEnd);

    m4aMPlayVolumeControl(&gMpi_FightBgm, 0xFFFF, volume);
    m4aMPlayVolumeControl(&gMpi_MainBgm, 0xFFFF, volume);

    proc->clock++;

    if (proc->clock >= proc->fiTimeEnd)
        Proc_Break(proc);
}

void StartBgmFadeIn(int songId, int duration, struct MusicPlayerInfo* mpi)
{
    struct MusicProc* proc;

    if (gPlaySt.cfgBgmDisable)
        return;

    sSoundSt.songPlaying = TRUE;
    sSoundSt.songId = songId;

    proc = SpawnProc(ProcScr_MusicFadeIn, PROC_TREE_3);

    m4aMPlayStop(&gMpi_FightBgm);
    m4aMPlayStop(&gMpi_MainBgm);

    PlaySongCore(songId, mpi);

    m4aMPlayImmInit(&gMpi_FightBgm);
    m4aMPlayImmInit(&gMpi_MainBgm);

    m4aMPlayVolumeControl(&gMpi_FightBgm, 0xFFFF, 0);
    m4aMPlayVolumeControl(&gMpi_MainBgm, 0xFFFF, 0);

    proc->clock = 0;
    proc->fiTimeEnd = duration * 16;
}

void OverrideBgm(int songId)
{
    if (gPlaySt.cfgBgmDisable)
        return;

    sSoundSt.overwrittenSongId = sSoundSt.songId;

    m4aMPlayFadeOutTemporarily(&gMpi_MainBgm, 3);

    sSoundSt.songPlaying = FALSE;

    if (songId != 0)
        PlaySongDelayed(songId, 32, &gMpi_FightBgm);
}

void RestoreBgm(void)
{
    if (gPlaySt.cfgBgmDisable)
        return;

    if (sSoundSt.overwrittenSongId == 0)
        return;

    m4aMPlayFadeOut(&gMpi_FightBgm, 3);
    m4aMPlayFadeIn(&gMpi_MainBgm, 6);

    sSoundSt.songPlaying = TRUE;

    sSoundSt.songId = sSoundSt.overwrittenSongId;
    sSoundSt.overwrittenSongId = 0;
}

void MakeBgmOverridePersist(void)
{
    if (gPlaySt.cfgBgmDisable)
        return;

    sSoundSt.songId = sSoundSt.overwrittenSongId;
    sSoundSt.overwrittenSongId = 0;
}

void StartBgmVolumeChange(int volumeInit, int volumeEnd, int duration, ProcPtr parent)
{
    struct MusicProc* proc = SpawnProcLocking(ProcScr_MusicVolChange, parent);

    proc->vcInitVolume = volumeInit;
    proc->vcEndVolume = volumeEnd;
    proc->vcClock = 0;
    proc->vcTimeEnd = duration;
}

void MusicVc_OnLoop(struct MusicProc* proc)
{
    int volume = Interpolate(INTERPOLATE_LINEAR, proc->vcInitVolume, proc->vcEndVolume, proc->vcClock++, proc->vcTimeEnd);

    SetBgmVolume(volume);

    if (proc->vcClock >= proc->vcTimeEnd)
    {
        if (proc->vcEndVolume == 0)
        {
            m4aSongNumStop(GetCurrentBgmSong());
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
    Proc_End(proc);
}

static void PlaySongDelayed(int songId, int delay, struct MusicPlayerInfo* mpi)
{
    struct MusicProc* proc;

    if (gPlaySt.cfgBgmDisable)
        return;

    proc = SpawnProc(ProcScr_DelaySong, PROC_TREE_3);

    proc->clock = delay;
    proc->songId = songId;
    proc->mpi = mpi;
}

static void PlaySongCore(int songId, struct MusicPlayerInfo* mpi)
{
    if (mpi)
        MPlayStart(mpi, gSongTable[songId].header);
    else
        m4aSongNumStart(songId);
}
