
#include "common.h"
#include "sound.h"

#include "proc.h"
#include "util.h"

struct SoundSt
{
    /* 00 */ u16 unused_00;
    /* 02 */ u16 overwritten_song;
    /* 04 */ u16 song;
    /* 06 */ i8 is_song_playing;
};

struct MusicProc
{
    /* 00 */ PROC_HEADER;

    /* 29 */ u8 pad_29[0x4A - 0x29];
    /* 4A */ short song;
    /* 4C */ short clock;
    /* 4E */ short fi_time_end;

    /* 50 */ u8 pad_50[0x54 - 0x50];
    /* 54 */ struct MusicPlayer * music_player;

    /* 58 */ u8 pad_60[0x64 - 0x58];
    /* 64 */ short vc_init_volume;
    /* 66 */ short vc_end_volume;
    /* 68 */ short vc_clock;
    /* 6A */ short vc_time_end;
};

static void MusicFi_OnLoop(struct MusicProc * proc);
static void MusicVc_OnLoop(struct MusicProc * proc);
static void DelaySong_OnLoop(struct MusicProc * proc);

static void PlaySongDelayed(int song, int delay, struct MusicPlayer * music_player);
static void PlaySongCore(int song, struct MusicPlayer * music_player);

static struct SoundSt EWRAM_DATA sSoundSt = { 0 };

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
    return sSoundSt.song;
}

bool IsBgmPlaying(void)
{
    return sSoundSt.is_song_playing;
}

void func_fe6_08002F9C(int volume)
{
    m4aMPlayVolumeControl(&gMusicPlayer_03006530, 0xFFFF, volume);
    m4aMPlayVolumeControl(&gMusicPlayer_03006600, 0xFFFF, volume);
    m4aMPlayVolumeControl(&gMusicPlayer_03006570, 0xFFFF, volume);
    m4aMPlayVolumeControl(&gMusicPlayer_03006260, 0xFFFF, volume);
    m4aMPlayVolumeControl(&gMusicPlayer_030062A0, 0xFFFF, volume);
    m4aMPlayVolumeControl(&gMusicPlayer_030064B0, 0xFFFF, volume);
}

void SetBgmVolume(int volume)
{
    m4aMPlayVolumeControl(&gMusicPlayer_FightBgm, 0xFFFF, volume);
    m4aMPlayVolumeControl(&gMusicPlayer_MainBgm, 0xFFFF, volume);
}

void FadeBgmOut(int speed)
{
    if (speed < 0)
        speed = 6;

    m4aMPlayFadeOut(&gMusicPlayer_FightBgm, speed);
    m4aMPlayFadeOut(&gMusicPlayer_MainBgm, speed);

    sSoundSt.is_song_playing = FALSE;
}

void func_fe6_080030B4(int speed)
{
    if (speed == 0)
        speed = 6;

    m4aMPlayFadeOut(&gMusicPlayer_03006530, speed);
    m4aMPlayFadeOut(&gMusicPlayer_03006600, speed);
    m4aMPlayFadeOut(&gMusicPlayer_03006570, speed);
    m4aMPlayFadeOut(&gMusicPlayer_03006260, speed);
    m4aMPlayFadeOut(&gMusicPlayer_030062A0, speed);
    m4aMPlayFadeOut(&gMusicPlayer_030064B0, speed);
}

void StartBgmCore(int song, struct MusicPlayer * music_player)
{
    sSoundSt.is_song_playing = TRUE;
    sSoundSt.song = song;

    PlaySongCore(song, music_player);

    m4aMPlayImmInit(&gMusicPlayer_FightBgm);
    m4aMPlayImmInit(&gMusicPlayer_MainBgm);
}

void StartOrChangeBgm(int song, int speed, struct MusicPlayer * music_player)
{
    if (sSoundSt.is_song_playing && GetCurrentBgmSong() == song)
        return;

    if (gPlaySt.config_bgm_disable)
        return;

    if (sSoundSt.is_song_playing)
    {
        FadeBgmOut(speed);
        PlaySongDelayed(song, speed * 16, music_player);
    }
    else
    {
        StartBgmCore(song, music_player);
    }
}

void StartBgm(int song, struct MusicPlayer * music_player)
{
    StartOrChangeBgm(song, 3, music_player);
}

void StartBgmExt(int song, int speed, struct MusicPlayer * music_player)
{
    StartOrChangeBgm(song, speed, music_player);
}

void MusicFi_OnLoop(struct MusicProc * proc)
{
    int volume = Interpolate(INTERPOLATE_LINEAR, 0, 0x100, proc->clock, proc->fi_time_end);

    m4aMPlayVolumeControl(&gMusicPlayer_FightBgm, 0xFFFF, volume);
    m4aMPlayVolumeControl(&gMusicPlayer_MainBgm, 0xFFFF, volume);

    proc->clock++;

    if (proc->clock >= proc->fi_time_end)
        Proc_Break(proc);
}

void StartBgmFadeIn(int song, int duration, struct MusicPlayer * music_player)
{
    struct MusicProc * proc;

    if (gPlaySt.config_bgm_disable)
        return;

    sSoundSt.is_song_playing = TRUE;
    sSoundSt.song = song;

    proc = SpawnProc(ProcScr_MusicFadeIn, PROC_TREE_3);

    m4aMPlayStop(&gMusicPlayer_FightBgm);
    m4aMPlayStop(&gMusicPlayer_MainBgm);

    PlaySongCore(song, music_player);

    m4aMPlayImmInit(&gMusicPlayer_FightBgm);
    m4aMPlayImmInit(&gMusicPlayer_MainBgm);

    m4aMPlayVolumeControl(&gMusicPlayer_FightBgm, 0xFFFF, 0);
    m4aMPlayVolumeControl(&gMusicPlayer_MainBgm, 0xFFFF, 0);

    proc->clock = 0;
    proc->fi_time_end = duration * 16;
}

void OverrideBgm(int song)
{
    if (gPlaySt.config_bgm_disable)
        return;

    sSoundSt.overwritten_song = sSoundSt.song;

    m4aMPlayFadeOutTemporarily(&gMusicPlayer_MainBgm, 3);

    sSoundSt.is_song_playing = FALSE;

    if (song != 0)
        PlaySongDelayed(song, 32, &gMusicPlayer_FightBgm);
}

void RestoreBgm(void)
{
    if (gPlaySt.config_bgm_disable)
        return;

    if (sSoundSt.overwritten_song == 0)
        return;

    m4aMPlayFadeOut(&gMusicPlayer_FightBgm, 3);
    m4aMPlayFadeIn(&gMusicPlayer_MainBgm, 6);

    sSoundSt.is_song_playing = TRUE;

    sSoundSt.song = sSoundSt.overwritten_song;
    sSoundSt.overwritten_song = 0;
}

void MakeBgmOverridePersist(void)
{
    if (gPlaySt.config_bgm_disable)
        return;

    sSoundSt.song = sSoundSt.overwritten_song;
    sSoundSt.overwritten_song = 0;
}

void StartBgmVolumeChange(int volume_from, int volume_to, int duration, ProcPtr parent)
{
    struct MusicProc * proc = SpawnProcLocking(ProcScr_MusicVolChange, parent);

    proc->vc_init_volume = volume_from;
    proc->vc_end_volume = volume_to;
    proc->vc_clock = 0;
    proc->vc_time_end = duration;
}

void MusicVc_OnLoop(struct MusicProc * proc)
{
    int volume = Interpolate(INTERPOLATE_LINEAR, proc->vc_init_volume, proc->vc_end_volume, proc->vc_clock++, proc->vc_time_end);

    SetBgmVolume(volume);

    if (proc->vc_clock >= proc->vc_time_end)
    {
        if (proc->vc_end_volume == 0)
        {
            m4aSongNumStop(GetCurrentBgmSong());
            sSoundSt.is_song_playing = FALSE;
        }

        Proc_Break(proc);
    }
}

void DelaySong_OnLoop(struct MusicProc * proc)
{
    proc->clock--;

    if (proc->clock >= 0)
        return;

    sSoundSt.is_song_playing = TRUE;
    sSoundSt.song = proc->song;

    PlaySongCore(proc->song, proc->music_player);
    Proc_End(proc);
}

static void PlaySongDelayed(int song, int delay, struct MusicPlayer * music_player)
{
    struct MusicProc * proc;

    if (gPlaySt.config_bgm_disable)
        return;

    proc = SpawnProc(ProcScr_DelaySong, PROC_TREE_3);

    proc->clock = delay;
    proc->song = song;
    proc->music_player = music_player;
}

static void PlaySongCore(int song, struct MusicPlayer * music_player)
{
    if (music_player)
        m4aMPlayStart(music_player, gSongTable[song].song);
    else
        m4aSongNumStart(song);
}
