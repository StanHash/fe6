#pragma once

#include "types.h"

struct WaveData;
struct ToneData;
struct CgbChannel;
struct SoundChannel;
struct SoundInfo;
struct Song;
struct MusicPlayerTrack;
struct MusicPlayer;
struct MusicPlayerEnt;
struct SongEnt;

typedef void (* MPlayFunc)();
typedef void (* PlyNoteFunc)(u32, struct MusicPlayer *, struct MusicPlayerTrack *);
typedef void (* CgbSoundFunc)(void);
typedef void (* CgbOscOffFunc)(u8);
typedef u32 (* MidiKeyToCgbFreqFunc)(u8, u8, u8);
typedef void (* ExtVolPitFunc)(void);
typedef void (* MPlayMainFunc)(struct MusicPlayer *);

// ASCII encoding of 'Smsh' in reverse
// This is presumably short for SMASH, the developer of MKS4AGB.
enum { ID_NUMBER = 0x68736D53 };

enum { C_V = 0x40 }; // center value for PAN, BEND, and TUNE

enum
{
    SOUND_MODE_REVERB_VAL   = 0x0000007F,
    SOUND_MODE_REVERB_SET   = 0x00000080,
    SOUND_MODE_MAXCHN       = 0x00000F00,
    SOUND_MODE_MAXCHN_SHIFT = 8,
    SOUND_MODE_MASVOL       = 0x0000F000,
    SOUND_MODE_MASVOL_SHIFT = 12,
    SOUND_MODE_FREQ_05734   = 0x00010000,
    SOUND_MODE_FREQ_07884   = 0x00020000,
    SOUND_MODE_FREQ_10512   = 0x00030000,
    SOUND_MODE_FREQ_13379   = 0x00040000,
    SOUND_MODE_FREQ_15768   = 0x00050000,
    SOUND_MODE_FREQ_18157   = 0x00060000,
    SOUND_MODE_FREQ_21024   = 0x00070000,
    SOUND_MODE_FREQ_26758   = 0x00080000,
    SOUND_MODE_FREQ_31536   = 0x00090000,
    SOUND_MODE_FREQ_36314   = 0x000A0000,
    SOUND_MODE_FREQ_40137   = 0x000B0000,
    SOUND_MODE_FREQ_42048   = 0x000C0000,
    SOUND_MODE_FREQ         = 0x000F0000,
    SOUND_MODE_FREQ_SHIFT   = 16,
    SOUND_MODE_DA_BIT_9     = 0x00800000,
    SOUND_MODE_DA_BIT_8     = 0x00900000,
    SOUND_MODE_DA_BIT_7     = 0x00A00000,
    SOUND_MODE_DA_BIT_6     = 0x00B00000,
    SOUND_MODE_DA_BIT       = 0x00B00000,
    SOUND_MODE_DA_BIT_SHIFT = 20,
};

struct WaveData
{
    /* +00 */ u16 kind;
    /* +02 */ u16 status;
    /* +04 */ u32 freq;
    /* +08 */ u32 loop_start;
    /* +0C */ u32 size; // number of samples
    /* +10 */ i8 data[1]; // samples
};

enum
{
    TONEDATA_TYPE_CGB    = 0x07,
    TONEDATA_TYPE_FIX    = 0x08,
    TONEDATA_TYPE_SPL    = 0x40, // key split
    TONEDATA_TYPE_RHY    = 0x80, // rhythm

    TONEDATA_P_S_PAN     = 0xc0,
    TONEDATA_P_S_PAM     = TONEDATA_P_S_PAN,
};

struct ToneData
{
    /* +00 */ u8 kind;
    /* +01 */ u8 key;
    /* +02 */ u8 length; // sound length (compatible sound)
    /* +03 */ u8 pan_sweep; // pan or sweep (compatible sound ch. 1)
    /* +04 */ struct WaveData * wav;
    /* +08 */ u8 attack;
    /* +09 */ u8 decay;
    /* +0A */ u8 sustain;
    /* +0B */ u8 release;
};

enum
{
    SOUND_CHANNEL_SF_START       = 0x80,
    SOUND_CHANNEL_SF_STOP        = 0x40,
    SOUND_CHANNEL_SF_LOOP        = 0x10,
    SOUND_CHANNEL_SF_IEC         = 0x04,
    SOUND_CHANNEL_SF_ENV         = 0x03,
    SOUND_CHANNEL_SF_ENV_ATTACK  = 0x03,
    SOUND_CHANNEL_SF_ENV_DECAY   = 0x02,
    SOUND_CHANNEL_SF_ENV_SUSTAIN = 0x01,
    SOUND_CHANNEL_SF_ENV_RELEASE = 0x00,
    SOUND_CHANNEL_SF_ON = (SOUND_CHANNEL_SF_START | SOUND_CHANNEL_SF_STOP | SOUND_CHANNEL_SF_IEC | SOUND_CHANNEL_SF_ENV),
};

enum
{
    CGB_CHANNEL_MO_PIT = 0x02,
    CGB_CHANNEL_MO_VOL = 0x01,
};

enum
{
    CGB_NRx2_ENV_DIR_DEC = 0x00,
    CGB_NRx2_ENV_DIR_INC = 0x08,
};

struct CgbChannel
{
    /* +00 */ u8 flags;
    /* +01 */ u8 type;
    /* +02 */ u8 volume_right;
    /* +03 */ u8 volume_left;
    /* +04 */ u8 attack;
    /* +05 */ u8 decay;
    /* +06 */ u8 sustain;
    /* +07 */ u8 release;
    /* +08 */ u8 key;
    /* +09 */ u8 envelope_volume;
    /* +0A */ u8 envelope_goal;
    /* +0B */ u8 envelope_counter;
    /* +0C */ u8 pseudo_echo_volume;
    /* +0D */ u8 pseudo_echo_length;
    /* +0E */ u8 dummy1;
    /* +0F */ u8 dummy2;
    /* +10 */ u8 gate_time;
    /* +11 */ u8 midi_key;
    /* +12 */ u8 velocity;
    /* +13 */ u8 priority;
    /* +14 */ u8 rhythm_pan;
    /* +15 */ u8 dummy3[3];
    /* +18 */ u8 dummy5;
    /* +19 */ u8 sustain_goal;
    /* +1A */ u8 n4; // NR[1-4]4 register (initial, length bit)
    /* +1B */ u8 pan;
    /* +1C */ u8 pan_mask;
    /* +1D */ u8 modify;
    /* +1E */ u8 length;
    /* +1F */ u8 sweep;
    /* +20 */ u32 frequency;
    /* +24 */ u32 * wav; // instructs CgbMain to load targeted wave
    /* +28 */ u32 * current_ptr; // stores the currently loaded wave
    /* +2C */ struct MusicPlayerTrack * track;
    /* +30 */ void * prev_channel_ptr;
    /* +34 */ void * next_channel_ptr;
    /* +38 */ u8 dummy4[8];
};

struct SoundChannel
{
    /* +00 */ u8 flags;
    /* +01 */ u8 type;
    /* +02 */ u8 volume_right;
    /* +03 */ u8 volume_left;
    /* +04 */ u8 attack;
    /* +05 */ u8 decay;
    /* +06 */ u8 sustain;
    /* +07 */ u8 release;
    /* +08 */ u8 key; // midi key as it was translated into final pitch
    /* +09 */ u8 envelope_volume;
    /* +0A */ u8 envelope_volume_right;
    /* +0B */ u8 envelope_volume_left;
    /* +0C */ u8 pseudo_echo_volume;
    /* +0D */ u8 pseudo_echo_length;
    /* +0E */ u8 dummy1;
    /* +0F */ u8 dummy2;
    /* +10 */ u8 gate_time;
    /* +11 */ u8 midi_key; // midi key as it was used in the track data
    /* +12 */ u8 velocity;
    /* +13 */ u8 priority;
    /* +14 */ u8 rhythm_pan;
    /* +15 */ u8 dummy3[3];
    /* +18 */ u32 count;
    /* +1C */ u32 fw;
    /* +20 */ u32 frequency;
    /* +24 */ struct WaveData * wav;
    /* +28 */ i8 * current_ptr;
    /* +2C */ struct MusicPlayerTrack * track;
    /* +30 */ void * prev_channel_ptr;
    /* +34 */ void * next_channel_ptr;
    /* +38 */ u32 dummy4;
    /* +3C */ u16 xpi;
    /* +3E */ u16 xpc;
};

enum { MAX_DIRECTSOUND_CHANNELS = 12 };

enum { PCM_DMA_BUF_SIZE = 1584 }; // size of Direct Sound buffer

struct SoundInfo
{
    // This field is normally equal to ID_NUMBER but it is set to other
    // values during sensitive operations for locking purposes.
    // This field should be volatile but isn't. This could potentially cause
    // race conditions.
    /* +000 */ u32 ident;

    /* +004 */ u8 volatile pcm_dma_counter;

    // Direct Sound
    /* +005 */ u8 reverb;
    /* +006 */ u8 max_channels;
    /* +007 */ u8 master_volume;
    /* +008 */ u8 freq;

    /* +009 */ u8 mode;
    /* +00A */ u8 c15; // periodically counts from 14 down to 0 (15 states)
    /* +00B */ u8 pcm_dma_period; // number of V-blanks per PCM DMA
    /* +00C */ u8 max_lines;
    /* +00D */ u8 gap[3];
    /* +010 */ i32 pcm_samples_per_vblank;
    /* +014 */ i32 pcm_freq;
    /* +018 */ i32 div_freq;
    /* +01C */ struct CgbChannel * cgb_channels;
    /* +020 */ MPlayMainFunc mplay_head_func;
    /* +024 */ struct MusicPlayer * mplay_head;
    /* +028 */ CgbSoundFunc cgb_sound_func;
    /* +02C */ CgbOscOffFunc cgb_osc_off_func;
    /* +030 */ MidiKeyToCgbFreqFunc midi_to_cgb_func;
    /* +034 */ MPlayFunc * mplay_jump_table;
    /* +038 */ PlyNoteFunc plynote;
    /* +03C */ ExtVolPitFunc ext_vol_pit_func;
    /* +040 */ u8 gap2[16];
    /* +060 */ struct SoundChannel chans[MAX_DIRECTSOUND_CHANNELS];
    /* +360 */ i8 pcm_buffer[PCM_DMA_BUF_SIZE * 2];
};

struct Song
{
    /* +00 */ u8 track_count;
    /* +01 */ u8 block_count;
    /* +02 */ u8 priority;
    /* +03 */ u8 reverb;
    /* +04 */ struct ToneData * tone;
    /* +08 */ u8 * part[1];
};

enum
{
    MPT_FLG_VOLSET = 0x01,
    MPT_FLG_VOLCHG = 0x03,
    MPT_FLG_PITSET = 0x04,
    MPT_FLG_PITCHG = 0x0C,
    MPT_FLG_START  = 0x40,
    MPT_FLG_EXIST  = 0x80,
};

struct MusicPlayerTrack
{
    /* +00 */ u8 flags;
    /* +01 */ u8 wait;
    /* +02 */ u8 patternLevel;
    /* +03 */ u8 repN;
    /* +04 */ u8 gate_time;
    /* +05 */ u8 key;
    /* +06 */ u8 velocity;
    /* +07 */ u8 running_status;
    /* +08 */ u8 key_m;
    /* +09 */ u8 pit_m;
    /* +0A */ i8 key_shift;
    /* +0B */ i8 key_shift_x;
    /* +0C */ i8 tune;
    /* +0D */ u8 pit_x;
    /* +0E */ i8 bend;
    /* +0F */ u8 bend_range;
    /* +10 */ u8 vol_mr;
    /* +11 */ u8 vol_ml;
    /* +12 */ u8 vol;
    /* +13 */ u8 vol_x;
    /* +14 */ i8 pan;
    /* +15 */ i8 panX;
    /* +16 */ i8 mod_m;
    /* +17 */ u8 mod;
    /* +18 */ u8 mod_t;
    /* +19 */ u8 lfo_speed;
    /* +1A */ u8 lfo_speed_c;
    /* +1B */ u8 lfo_delay;
    /* +1C */ u8 lfo_delay_c;
    /* +1D */ u8 priority;
    /* +1E */ u8 pseudo_echo_volume;
    /* +1F */ u8 pseudo_echo_length;
    /* +20 */ struct SoundChannel * chan;
    /* +24 */ struct ToneData tone;
    /* +30 */ u8 gap[10];
    /* +3A */ u16 unk_3A;
    /* +3C */ u32 unk_3C;
    /* +40 */ u8 * cmd_ptr;
    /* +44 */ u8 * pattern_stack[3];
};

enum
{
    MUSICPLAYER_STATUS_TRACK = 0x0000ffff,
    MUSICPLAYER_STATUS_PAUSE = 0x80000000,
};

enum { MAX_MUSICPLAYER_TRACKS = 16 };

enum { TRACKS_ALL = 0xFFFF };

enum
{
    TEMPORARY_FADE = 0x0001,
    FADE_IN        = 0x0002,
    FADE_VOL_MAX   = 64,
    FADE_VOL_SHIFT = 2,
};

struct MusicPlayer
{
    /* +00 */ struct Song const * song;
    /* +04 */ u32 status;
    /* +08 */ u8 track_count;
    /* +09 */ u8 priority;
    /* +0A */ u8 cmd;
    /* +0B */ u8 unk_B;
    /* +0C */ u32 clock;
    /* +10 */ u8 gap[8];
    /* +18 */ u8 * mem_acc_area;
    /* +1C */ u16 tempo_d;
    /* +1E */ u16 tempo_u;
    /* +20 */ u16 tempo_i;
    /* +22 */ u16 tempo_c;
    /* +24 */ u16 fade_oi;
    /* +26 */ u16 fade_oc;
    /* +28 */ u16 fade_ov;
    /* +2C */ struct MusicPlayerTrack * tracks;
    /* +30 */ struct ToneData * tone;
    /* +34 */ u32 ident;
    /* +38 */ MPlayMainFunc next_func;
    /* +3C */ struct MusicPlayer * next;
};

struct MusicPlayerEnt
{
    /* +00 */ struct MusicPlayer * music_player;
    /* +04 */ struct MusicPlayerTrack * track;
    /* +08 */ u8 num_tracks;
    /* +0A */ u16 unk_A;
};

struct SongEnt
{
    /* +00 */ struct Song const * song;
    /* +04 */ u16 ms;
    /* +06 */ u16 me;
};

extern struct MusicPlayerEnt const gMusicPlayerTable[];
extern struct SongEnt const gSongTable[];

void m4aSoundInit(void);
void m4aSoundMode(u32 mode);
void m4aSoundMain(void);
void m4aSoundVSync(void);
void m4aSoundVSyncOn(void);
void m4aSoundVSyncOff(void);
void m4aSongNumStart(u16 n);
void m4aSongNumStartOrChange(u16 n);
void m4aSongNumStartOrContinue(u16 n);
void m4aSongNumStop(u16 n);
void m4aMPlayAllStop(void);
void m4aMPlayStart(struct MusicPlayer * music_player, struct Song const * song);
void m4aMPlayStop(struct MusicPlayer * music_player);
void m4aMPlayContinue(struct MusicPlayer * music_player);
void m4aMPlayFadeOut(struct MusicPlayer * music_player, u16 speed);
void m4aMPlayFadeOutTemporarily(struct MusicPlayer * music_player, u16 speed);
void m4aMPlayFadeIn(struct MusicPlayer * music_player, u16 speed);
void m4aMPlayImmInit(struct MusicPlayer * music_player);
void m4aMPlayTempoControl(struct MusicPlayer * music_player, u16 tempo);
void m4aMPlayVolumeControl(struct MusicPlayer * music_player, u16 track_bits, u16 volume);
void m4aMPlayPitchControl(struct MusicPlayer * music_player, u16 track_bits, i16 pitch);
void m4aMPlayPanpotControl(struct MusicPlayer * music_player, u16 track_bits, i8 pan);
void m4aMPlayModDepthSet(struct MusicPlayer * music_player, u16 track_bits, u8 mod_depth);
void m4aMPlayLFOSpeedSet(struct MusicPlayer * music_player, u16 track_bits, u8 lfo_speed);

// TODO: move elsewhere

enum
{
    SOUND_MODE = SOUND_MODE_DA_BIT_8
        | SOUND_MODE_FREQ_13379
        | (13 << SOUND_MODE_MASVOL_SHIFT)
        | (7 << SOUND_MODE_MAXCHN_SHIFT),
};

extern char gNumMusicPlayers[];
extern char gMaxLines[];

#define NUM_MUSIC_PLAYERS ((u16) (uptr) gNumMusicPlayers)
#define MAX_LINES ((u32) (uptr) gMaxLines)

// end TODO
