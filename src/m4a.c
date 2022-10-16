#include "m4a.h"

#include "common.h"

#define MPLAY_JUMP_TABLE_FUNC(n) (*(gMPlayJumpTable + (n)))

extern const u8 gCgb3Vol[];

// m4a_1
extern u32 MulByQ32(u32 multiplier, u32 multiplicand);
extern void SoundMain(void);
extern void SoundMainRam_load(struct SoundInfo * sound_info);
extern void RealClear64byte(void);
extern void RealClearChain(void * x);
extern void MPlayJumpTableCopy(MPlayFunc * mplay_jump_table);
extern void MPlayMain(struct MusicPlayer * music_player);
extern void TrackStop(struct MusicPlayer * music_player, struct MusicPlayerTrack * track);

// m4a
extern void MPlayContinue(struct MusicPlayer * music_player);
extern void FadeOutBody(struct MusicPlayer * music_player);
extern void TrkVolPitSet(struct MusicPlayer * music_player, struct MusicPlayerTrack * track);
extern void MPlayFadeOut(struct MusicPlayer * music_player, u16 speed);
extern void ClearChain(void * x);
extern void Clear64byte(void * addr);
extern void SoundInit(struct SoundInfo * soundInfo);
extern void MPlayExtender(struct CgbChannel * cgb_channels);
extern void MPlayOpen(struct MusicPlayer * music_player, struct MusicPlayerTrack * track, u8 a3);
extern void CgbSound(void);
extern void CgbOscOff(u8);
extern void CgbModVol(struct CgbChannel * chan);
extern u32 MidiKeyToCgbFreq(u8, u8, u8);
extern void DummyFunc(void);
extern void SampleFreqSet(u32 freq);
extern void ClearModM(struct MusicPlayerTrack * track);

// sound command handler functions
extern void ply_fine(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_goto(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_patt(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_pend(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_rept(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_memacc(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_prio(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_tempo(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_keysh(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_voice(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_vol(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_pan(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_bend(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_bendr(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_lfos(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_lfodl(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_mod(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_modt(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_tune(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_port(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_xcmd(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_endtie(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_note(u32 note_cmd, struct MusicPlayer *, struct MusicPlayerTrack *);

// extended sound command handler functions
extern void ply_xxx(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_xwave(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_xtype(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_xatta(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_xdeca(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_xsust(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_xrele(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_xiecv(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_xiecl(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_xleng(struct MusicPlayer *, struct MusicPlayerTrack *);
extern void ply_xswee(struct MusicPlayer *, struct MusicPlayerTrack *);

SECTION(".iwram.SoundMainRam") ALIGNED(4)
u8 SoundMainRam[0x400] = { 0 };

SECTION(".iwram.gSoundInfo")
struct SoundInfo gSoundInfo = { 0 };

SECTION(".iwram.gMPlayJumpTable")
MPlayFunc gMPlayJumpTable[36] = { 0 };

SECTION(".iwram.gCgbChans")
struct CgbChannel gCgbChans[4] = { { 0 } };

SECTION(".iwram.gMPlayMemAccArea")
u8 gMPlayMemAccArea[0x10] = { 0 };

typedef void (* XcmdFunc)(struct MusicPlayer *, struct MusicPlayerTrack *);

extern XcmdFunc const gXcmdTable[];

extern MPlayFunc const gMPlayJumpTableTemplate[];
extern u8 const gScaleTable[];
extern u32 const gFreqTable[];
extern u16 const gPcmSamplesPerVBlankTable[];

extern u8 const gCgbScaleTable[];
extern i16 const gCgbFreqTable[];
extern u8 const gNoiseTable[];

extern u8 const gScaleTable[];
extern u32 const gFreqTable[];

extern const u8 gCgb3Vol[];

u32 MidiKeyToFreq(struct WaveData * wav, u8 key, u8 fine_adjust)
{
    u32 val1;
    u32 val2;
    u32 fine_adjust_shifted = fine_adjust << 24;

    if (key > 178)
    {
        key = 178;
        fine_adjust_shifted = 255 << 24;
    }

    val1 = gScaleTable[key];
    val1 = gFreqTable[val1 & 0xF] >> (val1 >> 4);

    val2 = gScaleTable[key + 1];
    val2 = gFreqTable[val2 & 0xF] >> (val2 >> 4);

    return MulByQ32(wav->freq, val1 + MulByQ32(val2 - val1, fine_adjust_shifted));
}

void UnusedDummyFunc()
{
}

void MPlayContinue(struct MusicPlayer * music_player)
{
    if (music_player->ident == ID_NUMBER)
    {
        music_player->ident++;
        music_player->status &= ~MUSICPLAYER_STATUS_PAUSE;
        music_player->ident = ID_NUMBER;
    }
}

void MPlayFadeOut(struct MusicPlayer * music_player, u16 speed)
{
    if (music_player->ident == ID_NUMBER)
    {
        music_player->ident++;
        music_player->fade_oc = speed;
        music_player->fade_oi = speed;
        music_player->fade_ov = 64 << FADE_VOL_SHIFT;
        music_player->ident = ID_NUMBER;
    }
}

void m4aSoundInit(void)
{
    int i;

    CpuCopy32(((void *) (((iptr) SoundMainRam_load) & ~1)), SoundMainRam, sizeof(SoundMainRam));

    SoundInit(&gSoundInfo);
    MPlayExtender(gCgbChans);
    m4aSoundMode(SOUND_MODE);

    for (i = 0; i < NUM_MUSIC_PLAYERS; i++)
    {
        struct MusicPlayer * music_player = gMusicPlayerTable[i].music_player;
        MPlayOpen(music_player, gMusicPlayerTable[i].track, gMusicPlayerTable[i].num_tracks);
        music_player->unk_B = gMusicPlayerTable[i].unk_A;
        music_player->mem_acc_area = gMPlayMemAccArea;
    }
}

void m4aSoundMain(void)
{
    SoundMain();
}

void m4aSongNumStart(u16 n)
{
    struct MusicPlayerEnt const * music_player_table = gMusicPlayerTable;
    struct SongEnt const * song_table = gSongTable;
    struct SongEnt const * song_ent = song_table + n;
    struct MusicPlayerEnt const * music_player_ent = music_player_table + song_ent->ms;

    m4aMPlayStart(music_player_ent->music_player, song_ent->song);
}

void m4aSongNumStartOrChange(u16 n)
{
    struct MusicPlayerEnt const * music_player_table = gMusicPlayerTable;
    struct SongEnt const * song_table = gSongTable;
    struct SongEnt const * song_ent = song_table + n;
    struct MusicPlayerEnt const * music_player_ent = music_player_table + song_ent->ms;

    if (music_player_ent->music_player->song != song_ent->song)
    {
        m4aMPlayStart(music_player_ent->music_player, song_ent->song);
    }
    else
    {
        if ((music_player_ent->music_player->status & MUSICPLAYER_STATUS_TRACK) == 0
        || ((music_player_ent->music_player->status & MUSICPLAYER_STATUS_PAUSE) != 0))
        {
            m4aMPlayStart(music_player_ent->music_player, song_ent->song);
        }
    }
}

void m4aSongNumStartOrContinue(u16 n)
{
    struct MusicPlayerEnt const * music_player_table = gMusicPlayerTable;
    struct SongEnt const * song_table = gSongTable;
    struct SongEnt const * song_ent = song_table + n;
    struct MusicPlayerEnt const * music_player_ent = music_player_table + song_ent->ms;

    if (music_player_ent->music_player->song != song_ent->song)
        m4aMPlayStart(music_player_ent->music_player, song_ent->song);
    else if ((music_player_ent->music_player->status & MUSICPLAYER_STATUS_TRACK) == 0)
        m4aMPlayStart(music_player_ent->music_player, song_ent->song);
    else if (music_player_ent->music_player->status & MUSICPLAYER_STATUS_PAUSE)
        MPlayContinue(music_player_ent->music_player);
}

void m4aSongNumStop(u16 n)
{
    struct MusicPlayerEnt const * music_player_table = gMusicPlayerTable;
    struct SongEnt const * song_table = gSongTable;
    struct SongEnt const * song_ent = song_table + n;
    struct MusicPlayerEnt const * music_player_ent = music_player_table + song_ent->ms;

    if (music_player_ent->music_player->song == song_ent->song)
        m4aMPlayStop(music_player_ent->music_player);
}

void m4aSongNumContinue(u16 n)
{
    struct MusicPlayerEnt const * music_player_table = gMusicPlayerTable;
    struct SongEnt const * song_table = gSongTable;
    struct SongEnt const * song_ent = song_table + n;
    struct MusicPlayerEnt const * music_player_ent = music_player_table + song_ent->ms;

    if (music_player_ent->music_player->song == song_ent->song)
        MPlayContinue(music_player_ent->music_player);
}

void m4aMPlayAllStop(void)
{
    int i;

    for (i = 0; i < NUM_MUSIC_PLAYERS; i++)
        m4aMPlayStop(gMusicPlayerTable[i].music_player);
}

void m4aMPlayContinue(struct MusicPlayer * music_player)
{
    MPlayContinue(music_player);
}

void m4aMPlayAllContinue(void)
{
    int i;

    for (i = 0; i < NUM_MUSIC_PLAYERS; i++)
        MPlayContinue(gMusicPlayerTable[i].music_player);
}

void m4aMPlayFadeOut(struct MusicPlayer * music_player, u16 speed)
{
    MPlayFadeOut(music_player, speed);
}

void m4aMPlayFadeOutTemporarily(struct MusicPlayer * music_player, u16 speed)
{
    if (music_player->ident == ID_NUMBER)
    {
        music_player->ident++;
        music_player->fade_oc = speed;
        music_player->fade_oi = speed;
        music_player->fade_ov = (64 << FADE_VOL_SHIFT) | TEMPORARY_FADE;
        music_player->ident = ID_NUMBER;
    }
}

void m4aMPlayFadeIn(struct MusicPlayer * music_player, u16 speed)
{
    if (music_player->ident == ID_NUMBER)
    {
        music_player->ident++;
        music_player->fade_oc = speed;
        music_player->fade_oi = speed;
        music_player->fade_ov = (0 << FADE_VOL_SHIFT) | FADE_IN;
        music_player->status &= ~MUSICPLAYER_STATUS_PAUSE;
        music_player->ident = ID_NUMBER;
    }
}

void m4aMPlayImmInit(struct MusicPlayer * music_player)
{
    int track_count = music_player->track_count;
    struct MusicPlayerTrack * track = music_player->tracks;

    while (track_count > 0)
    {
        if (track->flags & MPT_FLG_EXIST)
        {
            if (track->flags & MPT_FLG_START)
            {
                Clear64byte(track);
                track->flags = MPT_FLG_EXIST;
                track->bend_range = 2;
                track->vol_x = 64;
                track->lfo_speed = 22;
                track->tone.kind = 1;
            }
        }

        track_count--;
        track++;
    }
}

void MPlayExtender(struct CgbChannel * cgb_channels)
{
    struct SoundInfo * sound_info;
    u32 ident;

    REG_SOUNDCNT_X = SOUND_MASTER_ENABLE
        | SOUND_4_ON
        | SOUND_3_ON
        | SOUND_2_ON
        | SOUND_1_ON;

    REG_SOUNDCNT_L = 0; // set master volume to zero
    REG_NR12 = 0x8;
    REG_NR22 = 0x8;
    REG_NR42 = 0x8;
    REG_NR14 = 0x80;
    REG_NR24 = 0x80;
    REG_NR44 = 0x80;
    REG_NR30 = 0;
    REG_NR50 = 0x77;

    sound_info = SOUND_INFO_PTR;

    ident = sound_info->ident;

    if (ident != ID_NUMBER)
        return;

    sound_info->ident++;

    gMPlayJumpTable[8] = ply_memacc;
    gMPlayJumpTable[17] = ply_lfos;
    gMPlayJumpTable[19] = ply_mod;
    gMPlayJumpTable[28] = ply_xcmd;
    gMPlayJumpTable[29] = ply_endtie;
    gMPlayJumpTable[30] = SampleFreqSet;
    gMPlayJumpTable[31] = TrackStop;
    gMPlayJumpTable[32] = FadeOutBody;
    gMPlayJumpTable[33] = TrkVolPitSet;

    sound_info->cgb_channels = cgb_channels;
    sound_info->cgb_sound_func = CgbSound;
    sound_info->cgb_osc_off_func = CgbOscOff;
    sound_info->midi_to_cgb_func = MidiKeyToCgbFreq;
    sound_info->max_lines = MAX_LINES;

    CpuFill32(0, cgb_channels, sizeof(struct CgbChannel) * 4);

    cgb_channels[0].type = 1;
    cgb_channels[0].pan_mask = 0x11;
    cgb_channels[1].type = 2;
    cgb_channels[1].pan_mask = 0x22;
    cgb_channels[2].type = 3;
    cgb_channels[2].pan_mask = 0x44;
    cgb_channels[3].type = 4;
    cgb_channels[3].pan_mask = 0x88;

    sound_info->ident = ident;
}

void MusicPlayerJumpTableCopy(void)
{
    asm("swi 0x2A");
}

void ClearChain(void * x)
{
    void (* func)(void *) = MPLAY_JUMP_TABLE_FUNC(34);
    func(x);
}

void Clear64byte(void * x)
{
    void (* func)(void *) = MPLAY_JUMP_TABLE_FUNC(35);
    func(x);
}

void SoundInit(struct SoundInfo * sound_info)
{
    sound_info->ident = 0;

    if (REG_DMA1CNT & (DMA_REPEAT << 16))
        REG_DMA1CNT = ((DMA_ENABLE | DMA_START_NOW | DMA_32BIT | DMA_SRC_INC | DMA_DEST_FIXED) << 16) | 4;

    if (REG_DMA2CNT & (DMA_REPEAT << 16))
        REG_DMA2CNT = ((DMA_ENABLE | DMA_START_NOW | DMA_32BIT | DMA_SRC_INC | DMA_DEST_FIXED) << 16) | 4;

    REG_DMA1CNT_H = DMA_32BIT;
    REG_DMA2CNT_H = DMA_32BIT;
    REG_SOUNDCNT_X = SOUND_MASTER_ENABLE
        | SOUND_4_ON
        | SOUND_3_ON
        | SOUND_2_ON
        | SOUND_1_ON;
    REG_SOUNDCNT_H = SOUND_B_FIFO_RESET | SOUND_B_TIMER_0 | SOUND_B_LEFT_OUTPUT
        | SOUND_A_FIFO_RESET | SOUND_A_TIMER_0 | SOUND_A_RIGHT_OUTPUT
        | SOUND_ALL_MIX_FULL;
    REG_SOUNDBIAS_H = (REG_SOUNDBIAS_H & 0x3F) | 0x40;

    REG_DMA1SAD = (uptr) sound_info->pcm_buffer;
    REG_DMA1DAD = (uptr) &REG_FIFO_A;
    REG_DMA2SAD = (uptr) sound_info->pcm_buffer + PCM_DMA_BUF_SIZE;
    REG_DMA2DAD = (uptr) &REG_FIFO_B;

    SOUND_INFO_PTR = sound_info;
    CpuFill32(0, sound_info, sizeof(struct SoundInfo));

    sound_info->max_channels = 8;
    sound_info->master_volume = 15;
    sound_info->plynote = ply_note;
    sound_info->cgb_sound_func = (CgbSoundFunc) DummyFunc;
    sound_info->cgb_osc_off_func = (CgbOscOffFunc) DummyFunc;
    sound_info->midi_to_cgb_func = (MidiKeyToCgbFreqFunc) DummyFunc;
    sound_info->ext_vol_pit_func = (ExtVolPitFunc) DummyFunc;

    MPlayJumpTableCopy(gMPlayJumpTable);

    sound_info->mplay_jump_table = gMPlayJumpTable;

    SampleFreqSet(SOUND_MODE_FREQ_13379);

    sound_info->ident = ID_NUMBER;
}

void SampleFreqSet(u32 freq)
{
    struct SoundInfo * sound_info = SOUND_INFO_PTR;

    freq = (freq & 0xF0000) >> 16;
    sound_info->freq = freq;
    sound_info->pcm_samples_per_vblank = gPcmSamplesPerVBlankTable[freq - 1];
    sound_info->pcm_dma_period = PCM_DMA_BUF_SIZE / sound_info->pcm_samples_per_vblank;

    // LCD refresh rate 59.7275Hz
    sound_info->pcm_freq = (597275 * sound_info->pcm_samples_per_vblank + 5000) / 10000;

    // CPU frequency 16.78Mhz
    sound_info->div_freq = (16777216 / sound_info->pcm_freq + 1) >> 1;

    // Turn off timer 0.
    REG_TM0CNT_H = 0;

    // cycles per LCD fresh 280896
    REG_TM0CNT_L = -(280896 / sound_info->pcm_samples_per_vblank);

    m4aSoundVSyncOn();

    while (*(u8 volatile *) &REG_VCOUNT == 159)
        ;

    while (*(u8 volatile *) &REG_VCOUNT != 159)
        ;

    REG_TM0CNT_H = TIMER_ENABLE | TIMER_1CLK;
}


void m4aSoundMode(u32 mode)
{
    struct SoundInfo * sound_info = SOUND_INFO_PTR;
    u32 temp;

    if (sound_info->ident != ID_NUMBER)
        return;

    sound_info->ident++;

    temp = mode & (SOUND_MODE_REVERB_SET | SOUND_MODE_REVERB_VAL);

    if (temp)
        sound_info->reverb = temp & SOUND_MODE_REVERB_VAL;

    temp = mode & SOUND_MODE_MAXCHN;

    if (temp)
    {
        struct SoundChannel * chan;

        sound_info->max_channels = temp >> SOUND_MODE_MAXCHN_SHIFT;

        temp = MAX_DIRECTSOUND_CHANNELS;
        chan = sound_info->chans;

        while (temp != 0)
        {
            chan->flags = 0;
            temp--;
            chan++;
        }
    }

    temp = mode & SOUND_MODE_MASVOL;

    if (temp)
        sound_info->master_volume = temp >> SOUND_MODE_MASVOL_SHIFT;

    temp = mode & SOUND_MODE_DA_BIT;

    if (temp)
    {
        temp = (temp & 0x300000) >> 14;
        REG_SOUNDBIAS_H = (REG_SOUNDBIAS_H & 0x3F) | temp;
    }

    temp = mode & SOUND_MODE_FREQ;

    if (temp)
    {
        m4aSoundVSyncOff();
        SampleFreqSet(temp);
    }

    sound_info->ident = ID_NUMBER;
}

void SoundClear(void)
{
    struct SoundInfo * sound_info = SOUND_INFO_PTR;
    int i;
    void * chan;

    if (sound_info->ident != ID_NUMBER)
        return;

    sound_info->ident++;

    i = MAX_DIRECTSOUND_CHANNELS;
    chan = &sound_info->chans[0];

    while (i > 0)
    {
        ((struct SoundChannel *) chan)->flags = 0;
        i--;
        chan = (void *) ((iptr) chan + sizeof(struct SoundChannel));
    }

    chan = sound_info->cgb_channels;

    if (chan)
    {
        i = 1;

        while (i <= 4)
        {
            sound_info->cgb_osc_off_func(i);
            ((struct CgbChannel *) chan)->flags = 0;
            i++;
            chan = (void *) ((iptr) chan + sizeof(struct CgbChannel));
        }
    }

    sound_info->ident = ID_NUMBER;
}

void m4aSoundVSyncOff(void)
{
    struct SoundInfo * sound_info = SOUND_INFO_PTR;

    if (sound_info->ident >= ID_NUMBER && sound_info->ident <= ID_NUMBER + 1)
    {
        sound_info->ident += 10;

        if (REG_DMA1CNT & (DMA_REPEAT << 16))
            REG_DMA1CNT = ((DMA_ENABLE | DMA_START_NOW | DMA_32BIT | DMA_SRC_INC | DMA_DEST_FIXED) << 16) | 4;

        if (REG_DMA2CNT & (DMA_REPEAT << 16))
            REG_DMA2CNT = ((DMA_ENABLE | DMA_START_NOW | DMA_32BIT | DMA_SRC_INC | DMA_DEST_FIXED) << 16) | 4;

        REG_DMA1CNT_H = DMA_32BIT;
        REG_DMA2CNT_H = DMA_32BIT;

        CpuFill32(0, sound_info->pcm_buffer, sizeof(sound_info->pcm_buffer));
    }
}

void m4aSoundVSyncOn(void)
{
    struct SoundInfo * sound_info = SOUND_INFO_PTR;
    u32 ident = sound_info->ident;

    if (ident == ID_NUMBER)
        return;

    REG_DMA1CNT_H = DMA_ENABLE | DMA_START_SPECIAL | DMA_32BIT | DMA_REPEAT;
    REG_DMA2CNT_H = DMA_ENABLE | DMA_START_SPECIAL | DMA_32BIT | DMA_REPEAT;

    sound_info->pcm_dma_counter = 0;
    sound_info->ident = ident - 10;
}

void MPlayOpen(struct MusicPlayer * music_player, struct MusicPlayerTrack * tracks, u8 track_count)
{
    struct SoundInfo * sound_info;

    if (track_count == 0)
        return;

    if (track_count > MAX_MUSICPLAYER_TRACKS)
        track_count = MAX_MUSICPLAYER_TRACKS;

    sound_info = SOUND_INFO_PTR;

    if (sound_info->ident != ID_NUMBER)
        return;

    sound_info->ident++;

    Clear64byte(music_player);

    music_player->tracks = tracks;
    music_player->track_count = track_count;
    music_player->status = MUSICPLAYER_STATUS_PAUSE;

    while (track_count != 0)
    {
        tracks->flags = 0;
        track_count--;
        tracks++;
    }

    if (sound_info->mplay_head_func != NULL)
    {
        music_player->next_func = sound_info->mplay_head_func;
        music_player->next = sound_info->mplay_head;
        sound_info->mplay_head_func = NULL;
    }

    sound_info->mplay_head = music_player;
    sound_info->mplay_head_func = MPlayMain;
    sound_info->ident = ID_NUMBER;
    music_player->ident = ID_NUMBER;
}

void m4aMPlayStart(struct MusicPlayer * music_player, struct Song * song_header)
{
    int i;
    u8 unk_B;
    struct MusicPlayerTrack * track;

    if (music_player->ident != ID_NUMBER)
        return;

    unk_B = music_player->unk_B;

    if (!unk_B
        || ((!music_player->song || !(music_player->tracks[0].flags & MPT_FLG_START))
            && ((music_player->status & MUSICPLAYER_STATUS_TRACK) == 0
                || (music_player->status & MUSICPLAYER_STATUS_PAUSE)))
        || (music_player->priority <= song_header->priority))
    {
        music_player->ident++;
        music_player->status = 0;
        music_player->song = song_header;
        music_player->tone = song_header->tone;
        music_player->priority = song_header->priority;
        music_player->clock = 0;
        music_player->tempo_d = 150;
        music_player->tempo_i = 150;
        music_player->tempo_u = 0x100;
        music_player->tempo_c = 0;
        music_player->fade_oi = 0;

        i = 0;
        track = music_player->tracks;

        while (i < song_header->track_count && i < music_player->track_count)
        {
            TrackStop(music_player, track);
            track->flags = MPT_FLG_EXIST | MPT_FLG_START;
            track->chan = 0;
            track->cmd_ptr = song_header->part[i];
            i++;
            track++;
        }

        while (i < music_player->track_count)
        {
            TrackStop(music_player, track);
            track->flags = 0;
            i++;
            track++;
        }

        if (song_header->reverb & SOUND_MODE_REVERB_SET)
            m4aSoundMode(song_header->reverb);

        music_player->ident = ID_NUMBER;
    }
}

void m4aMPlayStop(struct MusicPlayer * music_player)
{
    int i;
    struct MusicPlayerTrack * track;

    if (music_player->ident != ID_NUMBER)
        return;

    music_player->ident++;
    music_player->status |= MUSICPLAYER_STATUS_PAUSE;

    i = music_player->track_count;
    track = music_player->tracks;

    while (i > 0)
    {
        TrackStop(music_player, track);
        i--;
        track++;
    }

    music_player->ident = ID_NUMBER;
}

void FadeOutBody(struct MusicPlayer * music_player)
{
    int i;
    struct MusicPlayerTrack * track;
    u16 fade_ov;

    if (music_player->fade_oi == 0)
        return;
    if (--music_player->fade_oc != 0)
        return;

    music_player->fade_oc = music_player->fade_oi;

    if (music_player->fade_ov & FADE_IN)
    {
        if ((u16) (music_player->fade_ov += (4 << FADE_VOL_SHIFT)) >= (64 << FADE_VOL_SHIFT))
        {
            music_player->fade_ov = (64 << FADE_VOL_SHIFT);
            music_player->fade_oi = 0;
        }
    }
    else
    {
        if ((i16) (music_player->fade_ov -= (4 << FADE_VOL_SHIFT)) <= 0)
        {
            i = music_player->track_count;
            track = music_player->tracks;

            while (i > 0)
            {
                u32 val;

                TrackStop(music_player, track);

                val = TEMPORARY_FADE;
                fade_ov = music_player->fade_ov;
                val &= fade_ov;

                if (!val)
                    track->flags = 0;

                i--;
                track++;
            }

            if (music_player->fade_ov & TEMPORARY_FADE)
                music_player->status |= MUSICPLAYER_STATUS_PAUSE;
            else
                music_player->status = MUSICPLAYER_STATUS_PAUSE;

            music_player->fade_oi = 0;
            return;
        }
    }

    i = music_player->track_count;
    track = music_player->tracks;

    while (i > 0)
    {
        if (track->flags & MPT_FLG_EXIST)
        {
            fade_ov = music_player->fade_ov;

            track->vol_x = (fade_ov >> FADE_VOL_SHIFT);
            track->flags |= MPT_FLG_VOLCHG;
        }

        i--;
        track++;
    }
}

void TrkVolPitSet(struct MusicPlayer * music_player, struct MusicPlayerTrack * track)
{
    if (track->flags & MPT_FLG_VOLSET)
    {
        int x;
        int y;

        x = (u32) (track->vol * track->vol_x) >> 5;

        if (track->mod_t == 1)
            x = (u32) (x * (track->mod_m + 128)) >> 7;

        y = 2 * track->pan + track->panX;

        if (track->mod_t == 2)
            y += track->mod_m;

        if (y < -128)
            y = -128;
        else if (y > 127)
            y = 127;

        track->vol_mr = (u32) ((y + 128) * x) >> 8;
        track->vol_ml = (u32) ((127 - y) * x) >> 8;
    }

    if (track->flags & MPT_FLG_PITSET)
    {
        int bend = track->bend * track->bend_range;
        int x = (track->tune + bend)
              * 4
              + (track->key_shift << 8)
              + (track->key_shift_x << 8)
              + track->pit_x;

        if (track->mod_t == 0)
            x += 16 * track->mod_m;

        track->key_m = x >> 8;
        track->pit_m = x;
    }

    track->flags &= ~(MPT_FLG_PITSET | MPT_FLG_VOLSET);
}

u32 MidiKeyToCgbFreq(u8 chan_num, u8 key, u8 fine_adjust)
{
    if (chan_num == 4)
    {
        if (key <= 20)
        {
            key = 0;
        }
        else
        {
            key -= 21;
            if (key > 59)
                key = 59;
        }

        return gNoiseTable[key];
    }
    else
    {
        int val1;
        int val2;

        if (key <= 35)
        {
            fine_adjust = 0;
            key = 0;
        }
        else
        {
            key -= 36;
            if (key > 130)
            {
                key = 130;
                fine_adjust = 255;
            }
        }

        val1 = gCgbScaleTable[key];
        val1 = gCgbFreqTable[val1 & 0xF] >> (val1 >> 4);

        val2 = gCgbScaleTable[key + 1];
        val2 = gCgbFreqTable[val2 & 0xF] >> (val2 >> 4);

        return val1 + ((fine_adjust * (val2 - val1)) >> 8) + 2048;
    }
}

void CgbOscOff(u8 chan_num)
{
    switch (chan_num)
    {
    case 1:
        REG_NR12 = 8;
        REG_NR14 = 0x80;
        break;
    case 2:
        REG_NR22 = 8;
        REG_NR24 = 0x80;
        break;
    case 3:
        REG_NR30 = 0;
        break;
    default:
        REG_NR42 = 8;
        REG_NR44 = 0x80;
    }
}

static inline int CgbPan(struct CgbChannel * chan)
{
    u32 volume_right = chan->volume_right;
    u32 volume_left = chan->volume_left;

    if ((volume_right = (u8) volume_right) >= (volume_left = (u8) volume_left))
    {
        if (volume_right / 2 >= volume_left)
        {
            chan->pan = 0x0F;
            return 1;
        }
    }
    else
    {
        if (volume_left / 2 >= volume_right)
        {
            chan->pan = 0xF0;
            return 1;
        }
    }

    return 0;
}

void CgbModVol(struct CgbChannel * chan)
{
    struct SoundInfo * sound_info = SOUND_INFO_PTR;

    if (!CgbPan(chan))
    {
        chan->pan = 0xFF;
        chan->envelope_goal = (u32)(chan->volume_left + chan->volume_right);
        chan->envelope_goal /= 16;
    }
    else
    {
        chan->envelope_goal = (u32)(chan->volume_left + chan->volume_right);
        chan->envelope_goal /= 16;
        if (chan->envelope_goal > 15)
            chan->envelope_goal = 15;
    }

    chan->sustain_goal = (chan->envelope_goal * chan->sustain + 15) >> 4;
    chan->pan &= chan->pan_mask;
}

void CgbSound(void)
{
    int ch;
    struct CgbChannel * channels;
    int prev_c15;
    struct SoundInfo * sound_info = SOUND_INFO_PTR;
    volatile u8 * nrx0ptr;
    volatile u8 * nrx1ptr;
    volatile u8 * nrx2ptr;
    volatile u8 * nrx3ptr;
    volatile u8 * nrx4ptr;
    int envelope_step_time_and_dir;

    // Most comparision operations that cast to i8 perform 'and' by 0xFF.
    int mask = 0xff;

    if (sound_info->c15)
        sound_info->c15--;
    else
        sound_info->c15 = 14;

    for (ch = 1, channels = sound_info->cgb_channels; ch <= 4; ch++, channels++)
    {
        if (!(channels->flags & SOUND_CHANNEL_SF_ON))
            continue;

        /* 1. determine hardware channel registers */
        switch (ch)
        {
        case 1:
            nrx0ptr = (volatile u8 *) (&REG_NR10);
            nrx1ptr = (volatile u8 *) (&REG_NR11);
            nrx2ptr = (volatile u8 *) (&REG_NR12);
            nrx3ptr = (volatile u8 *) (&REG_NR13);
            nrx4ptr = (volatile u8 *) (&REG_NR14);
            break;
        case 2:
            nrx0ptr = (volatile u8 *) (&REG_NR10)+1;
            nrx1ptr = (volatile u8 *) (&REG_NR21);
            nrx2ptr = (volatile u8 *) (&REG_NR22);
            nrx3ptr = (volatile u8 *) (&REG_NR23);
            nrx4ptr = (volatile u8 *) (&REG_NR24);
            break;
        case 3:
            nrx0ptr = (volatile u8 *) (&REG_NR30);
            nrx1ptr = (volatile u8 *) (&REG_NR31);
            nrx2ptr = (volatile u8 *) (&REG_NR32);
            nrx3ptr = (volatile u8 *) (&REG_NR33);
            nrx4ptr = (volatile u8 *) (&REG_NR34);
            break;
        default:
            nrx0ptr = (volatile u8 *) (&REG_NR30)+1;
            nrx1ptr = (volatile u8 *) (&REG_NR41);
            nrx2ptr = (volatile u8 *) (&REG_NR42);
            nrx3ptr = (volatile u8 *) (&REG_NR43);
            nrx4ptr = (volatile u8 *) (&REG_NR44);
            break;
        }

        prev_c15 = sound_info->c15;
        envelope_step_time_and_dir = *nrx2ptr;

        /* 2. calculate envelope volume */
        if (channels->flags & SOUND_CHANNEL_SF_START)
        {
            if (!(channels->flags & SOUND_CHANNEL_SF_STOP))
            {
                channels->flags = SOUND_CHANNEL_SF_ENV_ATTACK;
                channels->modify = CGB_CHANNEL_MO_PIT | CGB_CHANNEL_MO_VOL;
                CgbModVol(channels);
                switch (ch)
                {
                case 1:
                    *nrx0ptr = channels->sweep;
                    // fallthrough
                case 2:
                    *nrx1ptr = ((u32)channels->wav << 6) + channels->length;
                    goto init_env_step_time_dir;
                case 3:
                    if (channels->wav != channels->current_ptr)
                    {
                        *nrx0ptr = 0x40;
                        REG_WAVE_RAM0 = channels->wav[0];
                        REG_WAVE_RAM1 = channels->wav[1];
                        REG_WAVE_RAM2 = channels->wav[2];
                        REG_WAVE_RAM3 = channels->wav[3];
                        channels->current_ptr = channels->wav;
                    }
                    *nrx0ptr = 0;
                    *nrx1ptr = channels->length;
                    if (channels->length)
                        channels->n4 = 0xC0;
                    else
                        channels->n4 = 0x80;
                    break;
                default:
                    *nrx1ptr = channels->length;
                    *nrx3ptr = (u32)channels->wav << 3;
                init_env_step_time_dir:
                    envelope_step_time_and_dir = channels->attack + CGB_NRx2_ENV_DIR_INC;
                    if (channels->length)
                        channels->n4 = 0x40;
                    else
                        channels->n4 = 0x00;
                    break;
                }
                channels->envelope_counter = channels->attack;
                if ((i8)(channels->attack & mask))
                {
                    channels->envelope_volume = 0;
                    goto envelope_step_complete;
                }
                else
                {
                    // skip attack phase if attack is instantaneous (=0)
                    goto envelope_decay_start;
                }
            }
            else
            {
                goto oscillator_off;
            }
        }
        else if (channels->flags & SOUND_CHANNEL_SF_IEC)
        {
            channels->pseudo_echo_length--;
            if ((i8)(channels->pseudo_echo_length & mask) <= 0)
            {
            oscillator_off:
                CgbOscOff(ch);
                channels->flags = 0;
                goto channel_complete;
            }
            goto envelope_complete;
        }
        else if ((channels->flags & SOUND_CHANNEL_SF_STOP) && (channels->flags & SOUND_CHANNEL_SF_ENV))
        {
            channels->flags &= ~SOUND_CHANNEL_SF_ENV;
            channels->envelope_counter = channels->release;
            if ((i8)(channels->release & mask))
            {
                channels->modify |= CGB_CHANNEL_MO_VOL;
                if (ch != 3)
                    envelope_step_time_and_dir = channels->release | CGB_NRx2_ENV_DIR_DEC;
                goto envelope_step_complete;
            }
            else
            {
                goto envelope_pseudoecho_start;
            }
        }
        else
        {
        envelope_step_repeat:
            if (channels->envelope_counter == 0)
            {
                if (ch == 3)
                    channels->modify |= CGB_CHANNEL_MO_VOL;

                CgbModVol(channels);
                if ((channels->flags & SOUND_CHANNEL_SF_ENV) == SOUND_CHANNEL_SF_ENV_RELEASE)
                {
                    channels->envelope_volume--;
                    if ((i8)(channels->envelope_volume & mask) <= 0)
                    {
                    envelope_pseudoecho_start:
                        channels->envelope_volume = ((channels->envelope_goal * channels->pseudo_echo_volume) + 0xFF) >> 8;
                        if (channels->envelope_volume)
                        {
                            channels->flags |= SOUND_CHANNEL_SF_IEC;
                            channels->modify |= CGB_CHANNEL_MO_VOL;
                            if (ch != 3)
                                envelope_step_time_and_dir = 0 | CGB_NRx2_ENV_DIR_INC;
                            goto envelope_complete;
                        }
                        else
                        {
                            goto oscillator_off;
                        }
                    }
                    else
                    {
                        channels->envelope_counter = channels->release;
                    }
                }
                else if ((channels->flags & SOUND_CHANNEL_SF_ENV) == SOUND_CHANNEL_SF_ENV_SUSTAIN)
                {
                envelope_sustain:
                    channels->envelope_volume = channels->sustain_goal;
                    channels->envelope_counter = 7;
                }
                else if ((channels->flags & SOUND_CHANNEL_SF_ENV) == SOUND_CHANNEL_SF_ENV_DECAY)
                {
                    int envelope_volume, sustain_goal;

                    channels->envelope_volume--;
                    envelope_volume = (i8)(channels->envelope_volume & mask);
                    sustain_goal = (i8)(channels->sustain_goal);
                    if (envelope_volume <= sustain_goal)
                    {
                    envelope_sustain_start:
                        if (channels->sustain == 0)
                        {
                            channels->flags &= ~SOUND_CHANNEL_SF_ENV;
                            goto envelope_pseudoecho_start;
                        }
                        else
                        {
                            channels->flags--;
                            channels->modify |= CGB_CHANNEL_MO_VOL;
                            if (ch != 3)
                                envelope_step_time_and_dir = 0 | CGB_NRx2_ENV_DIR_INC;
                            goto envelope_sustain;
                        }
                    }
                    else
                    {
                        channels->envelope_counter = channels->decay;
                    }
                }
                else
                {
                    channels->envelope_volume++;
                    if ((u8)(channels->envelope_volume & mask) >= channels->envelope_goal)
                    {
                    envelope_decay_start:
                        channels->flags--;
                        channels->envelope_counter = channels->decay;
                        if ((u8)(channels->envelope_counter & mask))
                        {
                            channels->modify |= CGB_CHANNEL_MO_VOL;
                            channels->envelope_volume = channels->envelope_goal;
                            if (ch != 3)
                                envelope_step_time_and_dir = channels->decay | CGB_NRx2_ENV_DIR_DEC;
                        }
                        else
                        {
                            goto envelope_sustain_start;
                        }
                    }
                    else
                    {
                        channels->envelope_counter = channels->attack;
                    }
                }
            }
        }

    envelope_step_complete:
        // every 15 frames, envelope calculation has to be done twice
        // to keep up with the hardware envelope rate (1/64 s)
        channels->envelope_counter--;
        if (prev_c15 == 0)
        {
            prev_c15--;
            goto envelope_step_repeat;
        }

    envelope_complete:
        /* 3. apply pitch to HW registers */
        if (channels->modify & CGB_CHANNEL_MO_PIT)
        {
            if (ch < 4 && (channels->type & TONEDATA_TYPE_FIX))
            {
                int dac_pwm_rate = REG_SOUNDBIAS_H;

                if (dac_pwm_rate < 0x40)        // if PWM rate = 32768 Hz
                    channels->frequency = (channels->frequency + 2) & 0x7fc;
                else if (dac_pwm_rate < 0x80)   // if PWM rate = 65536 Hz
                    channels->frequency = (channels->frequency + 1) & 0x7fe;
            }

            if (ch != 4)
                *nrx3ptr = channels->frequency;
            else
                *nrx3ptr = (*nrx3ptr & 0x08) | channels->frequency;
            channels->n4 = (channels->n4 & 0xC0) + (*((u8*)(&channels->frequency) + 1));
            *nrx4ptr = (i8)(channels->n4 & mask);
        }

        /* 4. apply envelope & volume to HW registers */
        if (channels->modify & CGB_CHANNEL_MO_VOL)
        {
            REG_NR51 = (REG_NR51 & ~channels->pan_mask) | channels->pan;
            if (ch == 3)
            {
                *nrx2ptr = gCgb3Vol[channels->envelope_volume];
                if (channels->n4 & 0x80)
                {
                    *nrx0ptr = 0x80;
                    *nrx4ptr = channels->n4;
                    channels->n4 &= 0x7f;
                }
            }
            else
            {
                u32 envMask = 0xF;
                *nrx2ptr = (envelope_step_time_and_dir & envMask) + (channels->envelope_volume << 4);
                *nrx4ptr = channels->n4 | 0x80;
                if (ch == 1 && !(*nrx0ptr & 0x08))
                    *nrx4ptr = channels->n4 | 0x80;
            }
        }

    channel_complete:
        channels->modify = 0;
    }
}

void m4aMPlayTempoControl(struct MusicPlayer * music_player, u16 tempo)
{
    if (music_player->ident == ID_NUMBER)
    {
        music_player->ident++;
        music_player->tempo_u = tempo;
        music_player->tempo_i = (music_player->tempo_d * music_player->tempo_u) >> 8;
        music_player->ident = ID_NUMBER;
    }
}

void m4aMPlayVolumeControl(struct MusicPlayer * music_player, u16 track_bits, u16 volume)
{
    int i;
    u32 bit;
    struct MusicPlayerTrack * track;

    if (music_player->ident != ID_NUMBER)
        return;

    music_player->ident++;

    i = music_player->track_count;
    track = music_player->tracks;
    bit = 1;

    while (i > 0)
    {
        if (track_bits & bit)
        {
            if (track->flags & MPT_FLG_EXIST)
            {
                track->vol_x = volume / 4;
                track->flags |= MPT_FLG_VOLCHG;
            }
        }

        i--;
        track++;
        bit <<= 1;
    }

    music_player->ident = ID_NUMBER;
}

void m4aMPlayPitchControl(struct MusicPlayer * music_player, u16 track_bits, i16 pitch)
{
    int i;
    u32 bit;
    struct MusicPlayerTrack * track;

    if (music_player->ident != ID_NUMBER)
        return;

    music_player->ident++;

    i = music_player->track_count;
    track = music_player->tracks;
    bit = 1;

    while (i > 0)
    {
        if (track_bits & bit)
        {
            if (track->flags & MPT_FLG_EXIST)
            {
                track->key_shift_x = pitch >> 8;
                track->pit_x = pitch;
                track->flags |= MPT_FLG_PITCHG;
            }
        }

        i--;
        track++;
        bit <<= 1;
    }

    music_player->ident = ID_NUMBER;
}

void m4aMPlayPanpotControl(struct MusicPlayer * music_player, u16 track_bits, i8 pan)
{
    int i;
    u32 bit;
    struct MusicPlayerTrack * track;

    if (music_player->ident != ID_NUMBER)
        return;

    music_player->ident++;

    i = music_player->track_count;
    track = music_player->tracks;
    bit = 1;

    while (i > 0)
    {
        if (track_bits & bit)
        {
            if (track->flags & MPT_FLG_EXIST)
            {
                track->panX = pan;
                track->flags |= MPT_FLG_VOLCHG;
            }
        }

        i--;
        track++;
        bit <<= 1;
    }

    music_player->ident = ID_NUMBER;
}

void ClearModM(struct MusicPlayerTrack * track)
{
    track->lfo_speed_c = 0;
    track->mod_m = 0;

    if (track->mod_t == 0)
        track->flags |= MPT_FLG_PITCHG;
    else
        track->flags |= MPT_FLG_VOLCHG;
}

void m4aMPlayModDepthSet(struct MusicPlayer * music_player, u16 track_bits, u8 mod_depth)
{
    int i;
    u32 bit;
    struct MusicPlayerTrack * track;

    if (music_player->ident != ID_NUMBER)
        return;

    music_player->ident++;

    i = music_player->track_count;
    track = music_player->tracks;
    bit = 1;

    while (i > 0)
    {
        if (track_bits & bit)
        {
            if (track->flags & MPT_FLG_EXIST)
            {
                track->mod = mod_depth;

                if (!track->mod)
                    ClearModM(track);
            }
        }

        i--;
        track++;
        bit <<= 1;
    }

    music_player->ident = ID_NUMBER;
}

void m4aMPlayLFOSpeedSet(struct MusicPlayer * music_player, u16 track_bits, u8 lfo_speed)
{
    int i;
    u32 bit;
    struct MusicPlayerTrack * track;

    if (music_player->ident != ID_NUMBER)
        return;

    music_player->ident++;

    i = music_player->track_count;
    track = music_player->tracks;
    bit = 1;

    while (i > 0)
    {
        if (track_bits & bit)
        {
            if (track->flags & MPT_FLG_EXIST)
            {
                track->lfo_speed = lfo_speed;

                if (!track->lfo_speed)
                    ClearModM(track);
            }
        }

        i--;
        track++;
        bit <<= 1;
    }

    music_player->ident = ID_NUMBER;
}

void ply_memacc(struct MusicPlayer * music_player, struct MusicPlayerTrack * track)
{
    u32 op;
    u8 * addr;
    u8 data;

    #define MEMACC_COND_JUMP(cond) \
    if (cond)                      \
        goto cond_true;            \
    else                           \
        goto cond_false;           \

    op = *track->cmd_ptr;
    track->cmd_ptr++;

    addr = music_player->mem_acc_area + *track->cmd_ptr;
    track->cmd_ptr++;

    data = *track->cmd_ptr;
    track->cmd_ptr++;

    switch (op)
    {
    case 0:
        *addr = data;
        return;
    case 1:
        *addr += data;
        return;
    case 2:
        *addr -= data;
        return;
    case 3:
        *addr = music_player->mem_acc_area[data];
        return;
    case 4:
        *addr += music_player->mem_acc_area[data];
        return;
    case 5:
        *addr -= music_player->mem_acc_area[data];
        return;
    case 6:
        MEMACC_COND_JUMP(*addr == data)
        return;
    case 7:
        MEMACC_COND_JUMP(*addr != data)
        return;
    case 8:
        MEMACC_COND_JUMP(*addr > data)
        return;
    case 9:
        MEMACC_COND_JUMP(*addr >= data)
        return;
    case 10:
        MEMACC_COND_JUMP(*addr <= data)
        return;
    case 11:
        MEMACC_COND_JUMP(*addr < data)
        return;
    case 12:
        MEMACC_COND_JUMP(*addr == music_player->mem_acc_area[data])
        return;
    case 13:
        MEMACC_COND_JUMP(*addr != music_player->mem_acc_area[data])
        return;
    case 14:
        MEMACC_COND_JUMP(*addr > music_player->mem_acc_area[data])
        return;
    case 15:
        MEMACC_COND_JUMP(*addr >= music_player->mem_acc_area[data])
        return;
    case 16:
        MEMACC_COND_JUMP(*addr <= music_player->mem_acc_area[data])
        return;
    case 17:
        MEMACC_COND_JUMP(*addr < music_player->mem_acc_area[data])
        return;
    default:
        return;
    }

cond_true:
    {
        (MPLAY_JUMP_TABLE_FUNC(1))(music_player, track);
        return;
    }

cond_false:
    track->cmd_ptr += 4;

    #undef MEMACC_COND_JUMP
}

void ply_xcmd(struct MusicPlayer * music_player, struct MusicPlayerTrack * track)
{
    u32 n = *track->cmd_ptr;
    track->cmd_ptr++;

    gXcmdTable[n](music_player, track);
}

void ply_xxx(struct MusicPlayer * music_player, struct MusicPlayerTrack * track)
{
    gMPlayJumpTable[0](music_player, track);
}

#define READ_XCMD_BYTE(var, n)      \
{                                   \
    u32 byte = track->cmd_ptr[(n)]; \
    byte <<= n * 8;                 \
    (var) &= ~(0xFF << (n * 8));    \
    (var) |= byte;                  \
}

void ply_xwave(struct MusicPlayer * music_player, struct MusicPlayerTrack * track)
{
    u32 wav;

#ifdef BUGFIX
    wav = 0;
#endif

    READ_XCMD_BYTE(wav, 0) // UB: uninitialized variable
    READ_XCMD_BYTE(wav, 1)
    READ_XCMD_BYTE(wav, 2)
    READ_XCMD_BYTE(wav, 3)

    track->tone.wav = (struct WaveData *) wav;
    track->cmd_ptr += 4;
}

void ply_xtype(struct MusicPlayer * music_player, struct MusicPlayerTrack * track)
{
    track->tone.kind = *track->cmd_ptr;
    track->cmd_ptr++;
}

void ply_xatta(struct MusicPlayer * music_player, struct MusicPlayerTrack * track)
{
    track->tone.attack = *track->cmd_ptr;
    track->cmd_ptr++;
}

void ply_xdeca(struct MusicPlayer * music_player, struct MusicPlayerTrack * track)
{
    track->tone.decay = *track->cmd_ptr;
    track->cmd_ptr++;
}

void ply_xsust(struct MusicPlayer * music_player, struct MusicPlayerTrack * track)
{
    track->tone.sustain = *track->cmd_ptr;
    track->cmd_ptr++;
}

void ply_xrele(struct MusicPlayer * music_player, struct MusicPlayerTrack * track)
{
    track->tone.release = *track->cmd_ptr;
    track->cmd_ptr++;
}

void ply_xiecv(struct MusicPlayer * music_player, struct MusicPlayerTrack * track)
{
    track->pseudo_echo_volume = *track->cmd_ptr;
    track->cmd_ptr++;
}

void ply_xiecl(struct MusicPlayer * music_player, struct MusicPlayerTrack * track)
{
    track->pseudo_echo_length = *track->cmd_ptr;
    track->cmd_ptr++;
}

void ply_xleng(struct MusicPlayer * music_player, struct MusicPlayerTrack * track)
{
    track->tone.length = *track->cmd_ptr;
    track->cmd_ptr++;
}

void ply_xswee(struct MusicPlayer * music_player, struct MusicPlayerTrack * track)
{
    track->tone.pan_sweep = *track->cmd_ptr;
    track->cmd_ptr++;
}

#undef READ_XCMD_BYTE

void DummyFunc(void)
{
}

MPlayFunc const gMPlayJumpTableTemplate[] =
{
    ply_fine,
    ply_goto,
    ply_patt,
    ply_pend,
    ply_rept,
    ply_fine,
    ply_fine,
    ply_fine,
    ply_fine,
    ply_prio,
    ply_tempo,
    ply_keysh,
    ply_voice,
    ply_vol,
    ply_pan,
    ply_bend,
    ply_bendr,
    ply_lfos,
    ply_lfodl,
    ply_mod,
    ply_modt,
    ply_fine,
    ply_fine,
    ply_tune,
    ply_fine,
    ply_fine,
    ply_fine,
    ply_port,
    ply_fine,
    ply_endtie,
    SampleFreqSet,
    TrackStop,
    FadeOutBody,
    TrkVolPitSet,
    RealClearChain,
    RealClear64byte,
};

const u8 gScaleTable[] =
{
    0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB,
    0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB,
    0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB,
    0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB,
    0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB,
    0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B,
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B,
    0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B,
    0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B,
    0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B,
    0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B,
    0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B,
    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B,
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B,
};

const u32 gFreqTable[] =
{
    2147483648u,
    2275179671u,
    2410468894u,
    2553802834u,
    2705659852u,
    2866546760u,
    3037000500u,
    3217589947u,
    3408917802u,
    3611622603u,
    3826380858u,
    4053909305u,
};

const u16 gPcmSamplesPerVBlankTable[] =
{
    96,
    132,
    176,
    224,
    264,
    304,
    352,
    448,
    528,
    608,
    672,
    704,
};

const u8 gCgbScaleTable[] =
{
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B,
    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B,
    0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B,
    0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B,
    0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B,
    0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B,
    0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B,
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B,
    0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B,
    0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB,
};

const i16 gCgbFreqTable[] =
{
    -2004,
    -1891,
    -1785,
    -1685,
    -1591,
    -1501,
    -1417,
    -1337,
    -1262,
    -1192,
    -1125,
    -1062,
};

const u8 gNoiseTable[] =
{
    0xD7, 0xD6, 0xD5, 0xD4,
    0xC7, 0xC6, 0xC5, 0xC4,
    0xB7, 0xB6, 0xB5, 0xB4,
    0xA7, 0xA6, 0xA5, 0xA4,
    0x97, 0x96, 0x95, 0x94,
    0x87, 0x86, 0x85, 0x84,
    0x77, 0x76, 0x75, 0x74,
    0x67, 0x66, 0x65, 0x64,
    0x57, 0x56, 0x55, 0x54,
    0x47, 0x46, 0x45, 0x44,
    0x37, 0x36, 0x35, 0x34,
    0x27, 0x26, 0x25, 0x24,
    0x17, 0x16, 0x15, 0x14,
    0x07, 0x06, 0x05, 0x04,
    0x03, 0x02, 0x01, 0x00,
};

const u8 gCgb3Vol[] =
{
    0x00, 0x00,
    0x60, 0x60, 0x60, 0x60,
    0x40, 0x40, 0x40, 0x40,
    0x80, 0x80, 0x80, 0x80,
    0x20, 0x20,
};

const u8 gClockTable[] =
{
    0x00,
    0x01,
    0x02,
    0x03,
    0x04,
    0x05,
    0x06,
    0x07,
    0x08,
    0x09,
    0x0A,
    0x0B,
    0x0C,
    0x0D,
    0x0E,
    0x0F,
    0x10,
    0x11,
    0x12,
    0x13,
    0x14,
    0x15,
    0x16,
    0x17,
    0x18,
    0x1C,
    0x1E,
    0x20,
    0x24,
    0x28,
    0x2A,
    0x2C,
    0x30,
    0x34,
    0x36,
    0x38,
    0x3C,
    0x40,
    0x42,
    0x44,
    0x48,
    0x4C,
    0x4E,
    0x50,
    0x54,
    0x58,
    0x5A,
    0x5C,
    0x60,
};

XcmdFunc const gXcmdTable[] =
{
    ply_xxx,
    ply_xwave,
    ply_xtype,
    ply_xxx,
    ply_xatta,
    ply_xdeca,
    ply_xsust,
    ply_xrele,
    ply_xiecv,
    ply_xiecl,
    ply_xleng,
    ply_xswee
};
