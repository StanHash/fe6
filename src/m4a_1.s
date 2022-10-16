    .include "asm_macros.inc"
    .include "asm_m4a.inc"
    .include "asm_gbaio.inc"

    .text

    .syntax unified
    .thumb

    function MulByQ32
MulByQ32:
    adr r2, 1f
    bx r2
1:
    .arm
    umull r2, r3, r0, r1
    add r0, r3, 0
    bx lr
    .thumb

    endfunction MulByQ32

    function SoundMain
SoundMain:
    @ id check
    ldr r0, .L0809BB98 @ =SOUND_INFO_PTR
    ldr r0, [r0]
    ldr r2, .L0809BB9C @ =ID_NUMBER
    ldr r3, [r0, O_SoundInfo_ident]
    cmp r2, r3
    beq 1f
    @ end if id check failed
    bx lr
1:
    adds r3, 1
    str r3, [r0, O_SoundInfo_ident]
    push {r4, r5, r6, r7, lr}
    mov r1, r8
    mov r2, sb
    mov r3, sl
    mov r4, fp
    push {r0, r1, r2, r3, r4}
    sub sp, 0x18
    ldrb r1, [r0, O_SoundInfo_max_lines]
    cmp r1, 0 @ if max_lines is 0, there is no maximum
    beq .L0809BB5E
    ldr r2, .L0809BBA4 @ =REG_VCOUNT
    ldrb r2, [r2]
    cmp r2, 0xA0
    bhs .L0809BB5C
    adds r2, 0xE4
.L0809BB5C:
    adds r1, r1, r2
.L0809BB5E:
    str r1, [sp, 0x14]
    ldr r3, [r0, O_SoundInfo_mplay_head_func]
    cmp r3, 0
    beq .L0809BB6E
    ldr r0, [r0, O_SoundInfo_mplay_head]
    bl .Lcall_via_r3
    ldr r0, [sp, 0x18] @ restore r0 = *SOUND_INFO_PTR
.L0809BB6E:
    ldr r3, [r0, O_SoundInfo_cgb_sound_func]
    bl .Lcall_via_r3
    ldr r0, [sp, 0x18] @ restore r0 = *SOUND_INFO_PTR
    ldr r3, [r0, O_SoundInfo_pcm_samples_per_vblank]
    mov r8, r3
    ldr r5, .L0809BBA8 @ =O_SoundInfo_pcm_buffer
    adds r5, r5, r0
    ldrb r4, [r0, O_SoundInfo_pcm_dma_counter]
    subs r7, r4, 1
    bls .L0809BB8E
    ldrb r1, [r0, O_SoundInfo_pcm_dma_period]
    subs r1, r1, r7
    mov r2, r8
    muls r2, r1, r2
    adds r5, r5, r2
.L0809BB8E:
    str r5, [sp, 8]
    ldr r6, .L0809BBAC @ =PCM_DMA_BUF_SIZE
    ldr r3, .L0809BBA0 @ =SoundMainRam + 1
    bx r3

    .align 2, 0
.L0809BB98: .4byte SOUND_INFO_PTR
.L0809BB9C: .4byte ID_NUMBER
.L0809BBA0: .4byte SoundMainRam + 1
.L0809BBA4: .4byte REG_VCOUNT
.L0809BBA8: .4byte O_SoundInfo_pcm_buffer
.L0809BBAC: .4byte PCM_DMA_BUF_SIZE

    endfunction SoundMain

    function SoundMainRam_load
SoundMainRam_load:
    ldrb r3, [r0, O_SoundInfo_reverb]
    cmp r3, 0
    beq .L0809BC10
    adr r1, .L0809BBBC
    bx r1

    .align 2, 0
.L0809BBBC:
    .arm
    cmp r4, 2
    addeq r7, r0, O_SoundInfo_pcm_buffer
    addne r7, r5, r8
    mov r4, r8
.L0809BBCC:
    ldsb r0, [r5, r6]
    ldsb r1, [r5]
    add r0, r1
    ldsb r1, [r7, r6]
    add r0, r1
    ldsb r1, [r7], 1
    add r0, r1
    mul r1, r0, r3
    mov r0, r1, asr 9
    tst r0, 0x80
    addne r0, 1
    strb r0, [r5, r6]
    strb r0, [r5], 1
    subs r4, r4, 1
    bgt .L0809BBCC
    adr r0, .L0809BC3E + 1 @ plus 1 because THUMB
    bx r0
    .thumb
.L0809BC10:
    movs r0, 0
    mov r1, r8
    adds r6, r5
    lsrs r1, 3
    bcc .L0809BC1E
    stm r5!, {r0}
    stm r6!, {r0}
.L0809BC1E:
    lsrs r1, 1
    bcc .L0809BC2A
    stm r5!, {r0}
    stm r6!, {r0}
    stm r5!, {r0}
    stm r6!, {r0}
.L0809BC2A:
    stm r5!, {r0}
    stm r6!, {r0}
    stm r5!, {r0}
    stm r6!, {r0}
    stm r5!, {r0}
    stm r6!, {r0}
    stm r5!, {r0}
    stm r6!, {r0}
    subs r1, 1
    bgt .L0809BC2A
.L0809BC3E:
    ldr r4, [sp, 0x18]
    ldr r0, [r4, O_SoundInfo_div_freq]
    mov r12, r0
    ldrb r0, [r4, O_SoundInfo_max_chans]
    adds r4, O_SoundInfo_chans
.L0809BC48:
    str r0, [sp, 0x04]
    ldr r3, [r4, O_SoundChannel_wav]
    ldr r0, [sp, 0x14]
    cmp r0, 0
    beq 2f
    ldr r1, .L0809BC64 @ =REG_VCOUNT
    ldrb r1, [r1]
    cmp r1, 0xA0
    bhs 1f
    adds r1, 0xE4
1:
    cmp r1, r0
    blo 2f
    b .L0809BF3A

    .align 2, 0
.L0809BC64: .4byte REG_VCOUNT

2:
    ldrb r6, [r4, O_SoundChannel_flags]
    movs r0, SOUND_CHANNEL_SF_ON
    tst r0, r6
    bne 1f
    b .L0809BF30
1:
    movs r0, SOUND_CHANNEL_SF_START
    tst r0, r6
    beq .L0809BCA2
    movs r0, SOUND_CHANNEL_SF_STOP
    tst r0, r6
    bne .L0809BCB2
    movs r6, SOUND_CHANNEL_SF_ENV_ATTACK
    strb r6, [r4, O_SoundChannel_flags]
    adds r0, r3, 0
    adds r0, O_WaveData_data
    str r0, [r4, O_SoundChannel_current_ptr]
    ldr r0, [r3, O_WaveData_size]
    str r0, [r4, O_SoundChannel_count]
    movs r5, 0
    strb r5, [r4, O_SoundChannel_envelope_volume]
    str r5, [r4, O_SoundChannel_fw]
    ldrb r2, [r3, O_WaveData_flags]
    movs r0, WAVE_DATA_FLAG_LOOP
    tst r0, r2
    beq .L0809BCFA
    movs r0, SOUND_CHANNEL_SF_LOOP
    orrs r6, r0
    strb r6, [r4, O_SoundChannel_flags]
    b .L0809BCFA
.L0809BCA2:
    ldrb r5, [r4, O_SoundChannel_envelope_volume]
    movs r0, SOUND_CHANNEL_SF_IEC
    tst r0, r6
    beq .L0809BCB8
    ldrb r0, [r4, O_SoundChannel_pseudo_echo_length]
    subs r0, 1
    strb r0, [r4, O_SoundChannel_pseudo_echo_length]
    bhi .L0809BD08
.L0809BCB2:
    movs r0, 0
    strb r0, [r4, O_SoundChannel_flags]
    b .L0809BF30
.L0809BCB8:
    movs r0, SOUND_CHANNEL_SF_STOP
    tst r0, r6
    beq .L0809BCD8
    ldrb r0, [r4, O_SoundChannel_release]
    muls r5, r0
    lsrs r5, 8
    ldrb r0, [r4, O_SoundChannel_pseudo_echo_volume]
    cmp r5, r0
    bhi .L0809BD08
.L0809BCCA:
    ldrb r5, [r4, O_SoundChannel_pseudo_echo_volume]
    cmp r5, 0
    beq .L0809BCB2
    movs r0, SOUND_CHANNEL_SF_IEC
    orrs r6, r0
    strb r6, [r4, O_SoundChannel_flags]
    b .L0809BD08
.L0809BCD8:
    movs r2, SOUND_CHANNEL_SF_ENV
    ands r2, r6
    cmp r2, SOUND_CHANNEL_SF_ENV_DECAY
    bne .L0809BCF6
    ldrb r0, [r4, O_SoundChannel_decay]
    muls r5, r0
    lsrs r5, 8
    ldrb r0, [r4, O_SoundChannel_sustain]
    cmp r5, r0
    bhi .L0809BD08
    adds r5, r0, 0
    beq .L0809BCCA
    subs r6, 1
    strb r6, [r4, O_SoundChannel_flags]
    b .L0809BD08
.L0809BCF6:
    cmp r2, SOUND_CHANNEL_SF_ENV_ATTACK
    bne .L0809BD08
.L0809BCFA:
    ldrb r0, [r4, O_SoundChannel_attack]
    adds r5, r0
    cmp r5, 0xFF
    bcc .L0809BD08
    movs r5, 0xFF
    subs r6, 1
    strb r6, [r4, O_SoundChannel_flags]
.L0809BD08:
    strb r5, [r4, O_SoundChannel_envelope_volume]
    ldr r0, [sp, 0x18]
    ldrb r0, [r0, O_SoundChannel_release]
    adds r0, 1
    muls r0, r5
    lsrs r5, r0, 4
    ldrb r0, [r4, O_SoundChannel_volume_right]
    muls r0, r5
    lsrs r0, 8
    strb r0, [r4, O_SoundChannel_envelope_volume_right]
    ldrb r0, [r4, O_SoundChannel_volume_left]
    muls r0, r5
    lsrs r0, 8
    strb r0, [r4, O_SoundChannel_envelope_volume_left]
    movs r0, SOUND_CHANNEL_SF_LOOP
    ands r0, r6
    str r0, [sp, 0x10]
    beq .L0809BD3C
    adds r0, r3, 0
    adds r0, O_WaveData_data
    ldr r1, [r3, O_WaveData_loop_start]
    adds r0, r1
    str r0, [sp, 0x0C]
    ldr r0, [r3, O_WaveData_size]
    subs r0, r1
    str r0, [sp, 0x10]
.L0809BD3C:
    ldr r5, [sp, 0x8]
    ldr r2, [r4, O_SoundChannel_count]
    ldr r3, [r4, O_SoundChannel_current_ptr]
    adr r0, .L0809BD48
    bx r0

    .align 2, 0
.L0809BD48:
    .arm
    str r8, [sp]
    ldrb r10, [r4, O_SoundChannel_envelope_volume_right]
    ldrb r11, [r4, O_SoundChannel_envelope_volume_left]
    mov r10, r10, lsl 16
    mov r11, r11, lsl 16
    ldrb r0, [r4, O_SoundChannel_type]
    tst r0, 0x8
    beq .L0809BE88
.L0809BD68:
    cmp r2, 4
    ble .L0809BDD8
    subs r2, r2, r8
    movgt lr, 0
    bgt .L0809BD94
    mov lr, r8
    add r2, r8
    sub r8, r2, 4
    sub lr, r8
    ands r2, 0x3
    moveq r2, 4
.L0809BD94:
    ldr r6, [r5]
    ldr r7, [r5, PCM_DMA_BUF_SIZE]
.L0809BD9C:
    ldsb r0, [r3], 1
    mul r1, r10, r0
    bic r1, 0xFF0000
    add r6, r1, r6, ror 8
    mul r1, r11, r0
    bic r1, 0xFF0000
    add r7, r1, r7, ror 8
    adds r5, r5, 0x40000000
    bcc .L0809BD9C
    str r7, [r5, PCM_DMA_BUF_SIZE]
    str r6, [r5], 4
    subs r8, 4
    bgt .L0809BD94
    adds r8, r8, lr
    beq .L0809BF1C
.L0809BDD8:
    ldr r6, [r5]
    ldr r7, [r5, PCM_DMA_BUF_SIZE]
.L0809BDE0:
    ldsb r0, [r3], 1
    mul r1, r10, r0
    bic r1, 0xFF0000
    add r6, r1, r6, ror 8
    mul r1, r11, r0
    bic r1, 0xFF0000
    add r7, r1, r7, ror 8
    subs r2, 1
    beq .L0809BE50
.L0809BE04:
    adds r5, r5, 0x40000000
    bcc .L0809BDE0
    str r7, [r5, PCM_DMA_BUF_SIZE]
    str r6, [r5], 4
    subs r8, 4
    bgt .L0809BD68
    b .L0809BF1C
.L0809BE20:
    ldr r0, [sp, 0x18]
    cmp r0, 0
    beq .L0809BE44
    ldr r3, [sp, 0x14]
    rsb r9, r2, 0
.L0809BE34:
    adds r2, r0, r2
    bgt .L0809BEEC
    sub r9, r0
    b .L0809BE34
.L0809BE44:
    pop {r4, r12}
    mov r2, 0
    b .L0809BE60
.L0809BE50:
    ldr r2, [sp, 0x10]
    cmp r2, 0
    ldrne r3, [sp, 0x0C]
    bne .L0809BE04
.L0809BE60:
    strb r2, [r4, O_SoundChannel_flags]
    mov r0, r5, lsr 30
    bic r5, r5, 0xC0000000
    rsb r0, r0, 0x3
    mov r0, r0, lsl 3
    mov r6, r6, ror r0
    mov r7, r7, ror r0
    str r7, [r5, PCM_DMA_BUF_SIZE]
    str r6, [r5], 4
    b .L0809BF24
.L0809BE88:
    push {r4, r12}
    ldr lr, [r4, O_SoundChannel_fw]
    ldr r1, [r4, O_SoundChannel_frequency]
    mul r4, r12, r1
    ldsb r0, [r3]
    ldsb r1, [r3, 1]!
    sub r1, r0
.L0809BEA4:
    ldr r6, [r5]
    ldr r7, [r5, PCM_DMA_BUF_SIZE]
.L0809BEAC:
    mul r9, lr, r1
    add r9, r0, r9, asr 23
    mul r12, r10, r9
    bic r12, 0xFF0000
    add r6, r12, r6, ror 8
    mul r12, r11, r9
    bic r12, 0xFF0000
    add r7, r12, r7, ror 8
    add lr, r4
    movs r9, lr, lsr 23
    beq .L0809BEF8
    bic lr, lr, 0x3F800000
    subs r2, r9
    ble .L0809BE20
    subs r9, 1
    addeq r0, r1
.L0809BEEC:
    ldsbne r0, [r3, r9]!
    ldsb r1, [r3, 1]!
    sub r1, r0
.L0809BEF8:
    adds r5, 0x40000000
    bcc .L0809BEAC
    str r7, [r5, PCM_DMA_BUF_SIZE]
    str r6, [r5], 4
    subs r8, 4
    bgt .L0809BEA4
    sub r3, 1
    pop {r4, r12}
    str lr, [r4, O_SoundChannel_fw]
.L0809BF1C:
    str r2, [r4, O_SoundChannel_count]
    str r3, [r4, O_SoundChannel_current_ptr]
.L0809BF24:
    ldr r8, [sp]
    adr r0, .L0809BF30 + 1
    bx r0
    .thumb
.L0809BF30:
    ldr r0, [sp, 0x04]
    subs r0, 1
    ble .L0809BF3A
    adds r4, SoundChannel_size
    b .L0809BC48
.L0809BF3A:
    ldr r0, [sp, 0x18]
    ldr r3, .L0809BF50 @ =ID_NUMBER
    str r3, [r0]
    add sp, 0x1C
    pop {r0-r7}
    mov r8, r0
    mov r9, r1
    mov r10, r2
    mov r11, r3
    pop {r3}
.Lcall_via_r3:
    bx r3

    .align 2, 0
.L0809BF50: .4byte ID_NUMBER

    endfunction SoundMainRam_load

    function RealClear64byte
RealClear64byte:
    mov r12, r4
    movs r1, 0
    movs r2, 0
    movs r3, 0
    movs r4, 0
    stm r0!, {r1-r4}
    stm r0!, {r1-r4}
    stm r0!, {r1-r4}
    stm r0!, {r1-r4}
    mov r4, r12
    bx lr

    endfunction RealClear64byte

    function RealClearChain
RealClearChain:
    ldr r3, [r0, O_SoundChannel_track]
    cmp r3, 0
    beq 4f
    ldr r1, [r0, O_SoundChannel_next_ptr]
    ldr r2, [r0, O_SoundChannel_prev_ptr]
    cmp r2, 0
    beq 1f
    str r1, [r2, O_SoundChannel_next_ptr]
    b 2f
1:
    str r1, [r3, O_MusicPlayerTrack_chan]
2:
    cmp r1, 0
    beq 3f
    str r2, [r1, O_SoundChannel_prev_ptr]
3:
    movs r1, 0
    str r1, [r0, O_SoundChannel_track]
4:
    bx lr

    endfunction RealClearChain

    function ply_fine
ply_fine:
    push {r4, r5, lr}
    adds r5, r1, 0
    ldr r4, [r5, O_MusicPlayerTrack_chan]
    cmp r4, 0
    beq .Lply_fine_done
.Lply_fine_loop:
    ldrb r1, [r4, O_SoundChannel_flags]
    movs r0, SOUND_CHANNEL_SF_ON
    tst r0, r1
    beq .Lply_fine_ok
    movs r0, SOUND_CHANNEL_SF_STOP
    orrs r1, r0
    strb r1, [r4, O_SoundChannel_flags]
.Lply_fine_ok:
    adds r0, r4, 0
    bl RealClearChain
    ldr r4, [r4, O_SoundChannel_next_ptr]
    cmp r4, 0
    bne .Lply_fine_loop
.Lply_fine_done:
    movs r0, 0
    strb r0, [r5, O_MusicPlayerTrack_flags]
    pop {r4, r5}
    pop {r0}
    bx r0

    endfunction ply_fine

    function MPlayJumpTableCopy
MPlayJumpTableCopy: @ 0x08117DD4
    mov ip, lr
    movs r1, 0x24
    ldr r2, .L0809BFEC @ =gMPlayJumpTableTemplate
.L0809BFC2:
    ldr r3, [r2]
    bl chk_adr_r2
    stm r0!, {r3}
    adds r2, 4
    subs r1, 1
    bgt .L0809BFC2
    bx ip

    .align 2, 0

ldrb_r3_r2:
    ldrb r3, [r2]
    @ fallthrough
chk_adr_r2:
    push {r0}
    lsrs r0, r2, 0x19
    bne .Lchk_adr_r2_done
    ldr r0, .L0809BFEC @ =gMPlayJumpTableTemplate
    cmp r2, r0
    blo .Lchk_adr_r2_reject
    lsrs r0, r2, 0xE
    beq .Lchk_adr_r2_done
.Lchk_adr_r2_reject:
    movs r3, 0
.Lchk_adr_r2_done:
    pop {r0}
    bx lr

    .align 2, 0
.L0809BFEC: .4byte gMPlayJumpTableTemplate

ld_r3_tp_adr_i:
    ldr r2, [r1, O_MusicPlayerTrack_cmd_ptr]
    @ fallthrough
st_r2_inc_pt_cmd_ptr:
    adds r3, r2, 1
    str r3, [r1, O_MusicPlayerTrack_cmd_ptr]
    ldrb r3, [r2]
    b chk_adr_r2

    endfunction MPlayJumpTableCopy

    function ply_goto
ply_goto:
    push {lr}
    @ fallthrough
ply_goto_inner:
    ldr r2, [r1, O_MusicPlayerTrack_cmd_ptr]
    ldrb r0, [r2, 3]
    lsls r0, 8
    ldrb r3, [r2, 2]
    orrs r0, r3
    lsls r0, 8
    ldrb r3, [r2, 1]
    orrs r0, r3
    lsls r0, 8
    bl ldrb_r3_r2
    orrs r0, r3
    str r0, [r1, O_MusicPlayerTrack_cmd_ptr]
    pop {r0}
    bx r0

    endfunction ply_goto

    function ply_patt
ply_patt:
    ldrb r2, [r1, O_MusicPlayerTrack_patternLevel]
    cmp r2, 3
    bhs .Lply_patt_done
    lsls r2, 2
    adds r3, r1, r2
    ldr r2, [r1, O_MusicPlayerTrack_cmd_ptr]
    adds r2, 4
    str r2, [r3, O_MusicPlayerTrack_pattern_stack]
    ldrb r2, [r1, O_MusicPlayerTrack_patternLevel]
    adds r2, 1
    strb r2, [r1, O_MusicPlayerTrack_patternLevel]
    b ply_goto
.Lply_patt_done:
    b ply_fine

    endfunction ply_patt

    function ply_pend
ply_pend:
    ldrb r2, [r1, O_MusicPlayerTrack_patternLevel]
    cmp r2, 0
    beq .Lply_pend_done
    subs r2, 1
    strb r2, [r1, O_MusicPlayerTrack_patternLevel]
    lsls r2, 2
    adds r3, r1, r2
    ldr r2, [r3, O_MusicPlayerTrack_pattern_stack]
    str r2, [r1, O_MusicPlayerTrack_cmd_ptr]
.Lply_pend_done:
    bx lr

    endfunction ply_pend

    function ply_rept
ply_rept:
    push {lr}
    ldr r2, [r1, O_MusicPlayerTrack_cmd_ptr]
    ldrb r3, [r2]
    cmp r3, 0
    bne .Lply_rept_1
    adds r2, 1
    str r2, [r1, O_MusicPlayerTrack_cmd_ptr]
    b ply_goto_inner
.Lply_rept_1:
    ldrb r3, [r1, O_MusicPlayerTrack_repN]
    adds r3, 1
    strb r3, [r1, O_MusicPlayerTrack_repN]
    mov r12, r3
    bl ld_r3_tp_adr_i
    cmp r12, r3
    bhs .Lply_rept_2
    b ply_goto_inner
.Lply_rept_2:
    movs r3, 0
    strb r3, [r1, O_MusicPlayerTrack_repN]
    adds r2, 5
    str r2, [r1, O_MusicPlayerTrack_cmd_ptr]
    pop {r0}
    bx r0

    endfunction ply_rept

    function ply_prio
ply_prio:
    mov r12, lr
    bl ld_r3_tp_adr_i
    strb r3, [r1, O_MusicPlayerTrack_priority]
    bx r12

    endfunction ply_prio

    function ply_tempo
ply_tempo:
    mov r12, lr
    bl ld_r3_tp_adr_i
    lsls r3, 1
    strh r3, [r0, O_MusicPlayer_tempo_d]
    ldrh r2, [r0, O_MusicPlayer_tempo_u]
    muls r3, r2
    lsrs r3, 8
    strh r3, [r0, O_MusicPlayer_tempo_i]
    bx r12

    endfunction ply_tempo

    function ply_keysh
ply_keysh:
    mov r12, lr
    bl ld_r3_tp_adr_i
    strb r3, [r1, O_MusicPlayerTrack_key_shift]
    ldrb r3, [r1, O_MusicPlayerTrack_flags]
    movs r2, 0x0C
    orrs r3, r2
    strb r3, [r1, O_MusicPlayerTrack_flags]
    bx r12

    endfunction ply_keysh

    function ply_voice
ply_voice:
    mov r12, lr
    ldr r2, [r1, O_MusicPlayerTrack_cmd_ptr]
    ldrb r3, [r2]
    adds r2, 1
    str r2, [r1, O_MusicPlayerTrack_cmd_ptr]
    lsls r2, r3, 1
    adds r2, r3
    lsls r2, 2
    ldr r3, [r0, O_MusicPlayer_tone]
    adds r2, r3
    ldr r3, [r2, O_ToneData_type]
    bl chk_adr_r2
    str r3, [r1, O_MusicPlayerTrack_ToneData_type]
    ldr r3, [r2, O_ToneData_wav]
    bl chk_adr_r2
    str r3, [r1, O_MusicPlayerTrack_ToneData_wav]
    ldr r3, [r2, O_ToneData_attack]
    bl chk_adr_r2
    str r3, [r1, O_MusicPlayerTrack_ToneData_attack]
    bx r12

    endfunction ply_voice

    function ply_vol
ply_vol:
    mov r12, lr
    bl ld_r3_tp_adr_i
    strb r3, [r1, O_MusicPlayerTrack_vol]
    ldrb r3, [r1, O_MusicPlayerTrack_flags]
    movs r2, MPT_FLG_VOLCHG
    orrs r3, r2
    strb r3, [r1, O_MusicPlayerTrack_flags]
    bx r12

    endfunction ply_vol

    function ply_pan
ply_pan:
    mov r12, lr
    bl ld_r3_tp_adr_i
    subs r3, C_V
    strb r3, [r1, O_MusicPlayerTrack_pan]
    ldrb r3, [r1, O_MusicPlayerTrack_flags]
    movs r2, MPT_FLG_VOLCHG
    orrs r3, r2
    strb r3, [r1, O_MusicPlayerTrack_flags]
    bx r12

    endfunction ply_pan

    function ply_bend
ply_bend:
    mov r12, lr
    bl ld_r3_tp_adr_i
    subs r3, C_V
    strb r3, [r1, O_MusicPlayerTrack_bend]
    ldrb r3, [r1, O_MusicPlayerTrack_flags]
    movs r2, MPT_FLG_PITCHG
    orrs r3, r2
    strb r3, [r1, O_MusicPlayerTrack_flags]
    bx r12

    endfunction ply_bend

    function ply_bendr
ply_bendr:
    mov r12, lr
    bl ld_r3_tp_adr_i
    strb r3, [r1, O_MusicPlayerTrack_bend_range]
    ldrb r3, [r1, O_MusicPlayerTrack_flags]
    movs r2, MPT_FLG_PITCHG
    orrs r3, r2
    strb r3, [r1, O_MusicPlayerTrack_flags]
    bx r12

    endfunction ply_bendr

    function ply_lfodl
ply_lfodl:
    mov r12, lr
    bl ld_r3_tp_adr_i
    strb r3, [r1, O_MusicPlayerTrack_lfo_delay]
    bx r12

    endfunction ply_lfodl

    function ply_modt
ply_modt:
    mov r12, lr
    bl ld_r3_tp_adr_i
    ldrb r0, [r1, O_MusicPlayerTrack_mod_t]
    cmp r0, r3
    beq .Lply_modt_done
    strb r3, [r1, O_MusicPlayerTrack_mod_t]
    ldrb r3, [r1, O_MusicPlayerTrack_flags]
    movs r2, MPT_FLG_VOLCHG | MPT_FLG_PITCHG
    orrs r3, r2
    strb r3, [r1, O_MusicPlayerTrack_flags]
.Lply_modt_done:
    bx r12
    endfunction ply_modt

    function ply_tune
ply_tune:
    mov r12, lr
    bl ld_r3_tp_adr_i
    subs r3, C_V
    strb r3, [r1, O_MusicPlayerTrack_tune]
    ldrb r3, [r1, O_MusicPlayerTrack_flags]
    movs r2, MPT_FLG_PITCHG
    orrs r3, r2
    strb r3, [r1, O_MusicPlayerTrack_flags]
    bx r12

    endfunction ply_tune

    function ply_port
ply_port:
    mov r12, lr
    ldr r2, [r1, O_MusicPlayerTrack_cmd_ptr]
    ldrb r3, [r2]
    adds r2, 1
    ldr r0, .L0809C17C @ =REG_SOUND_BASE
    adds r0, r3
    bl st_r2_inc_pt_cmd_ptr
    strb r3, [r0]
    bx r12

    .align 2, 0
.L0809C17C: .4byte REG_SOUND_BASE

    endfunction ply_port

    function m4aSoundVSync
m4aSoundVSync: @ 0x08117F98
    ldr r0, .L0809C42C @ =SOUND_INFO_PTR
    ldr r0, [r0]
    ldr r2, .L0809C430 @ =ID_NUMBER
    ldr r3, [r0, O_SoundInfo_ident]
    subs r3, r3, r2
    cmp r3, 1
    bhi .L0809C1C0
    ldrb r1, [r0, O_SoundInfo_pcm_dma_counter]
    subs r1, 1
    strb r1, [r0, O_SoundInfo_pcm_dma_counter]
    bgt .L0809C1C0
    ldrb r1, [r0, O_SoundInfo_pcm_dma_period]
    strb r1, [r0, O_SoundInfo_pcm_dma_counter]
    ldr r2, .L0809C1C4 @ =REG_DMA1SAD
    ldr r1, [r2, REG_DMA1CNT - REG_DMA1SAD]
    lsls r1, r1, 7
    blo .L0809C1A6
    ldr r1, .L0809C1C8 @ =0x84400004 @ (DMA_ENABLE | DMA_START_NOW | DMA_32BIT | DMA_SRC_INCREMENT | DMA_DST_FIXED) | 4
    str r1, [r2, REG_DMA1CNT - REG_DMA1SAD]
.L0809C1A6:
    ldr r1, [r2, REG_DMA2CNT - REG_DMA1SAD]
    lsls r1, r1, 7
    blo .L0809C1B0
    ldr r1, .L0809C1C8 @ =0x84400004 @ (DMA_ENABLE | DMA_START_NOW | DMA_32BIT | DMA_SRC_INCREMENT | DMA_DST_FIXED) | 4
    str r1, [r2, REG_DMA2CNT - REG_DMA1SAD]
.L0809C1B0:
    movs r1, 4 @ DMA_32BIT >> 24
    lsls r1, r1, 8
    strh r1, [r2, REG_DMA1CNT_H - REG_DMA1SAD]
    strh r1, [r2, REG_DMA2CNT_H - REG_DMA1SAD]
    movs r1, 0xB6 @ (DMA_ENABLE | DMA_START_SPECIAL | DMA_32BIT | DMA_REPEAT) >> 24
    lsls r1, r1, 8
    strh r1, [r2, REG_DMA1CNT_H - REG_DMA1SAD]
    strh r1, [r2, REG_DMA2CNT_H - REG_DMA1SAD]
.L0809C1C0:
    bx lr

    .align 2, 0
.L0809C1C4: .4byte REG_DMA1SAD
.L0809C1C8: .4byte 0x84400004 @ (DMA_ENABLE | DMA_START_NOW | DMA_32BIT | DMA_SRC_INCREMENT | DMA_DST_FIXED) | 4

    endfunction m4aSoundVSync

    function MPlayMain
MPlayMain:
    ldr r2, .L0809C430 @ =ID_NUMBER
    ldr r3, [r0, O_MusicPlayer_ident]
    cmp r2, r3
    beq .L0809C1D6
    bx lr
.L0809C1D6:
    adds r3, 1
    str r3, [r0, O_MusicPlayer_ident]
    push {r0, lr}
    ldr r3, [r0, O_MusicPlayer_next_func]
    cmp r3, 0
    beq .L0809C1E8
    ldr r0, [r0, O_MusicPlayer_next]
    bl .Lbx_r3
.L0809C1E8:
    pop {r0}
    push {r4-r7}
    mov r4, r8
    mov r5, r9
    mov r6, r10
    mov r7, r11
    push {r4-r7}
    adds r7, r0, 0
    ldr r0, [r7, O_MusicPlayer_status]
    cmp r0, 0
    bge .L0809C200
    b .L0809C414
.L0809C200:
    ldr r0, .L0809C42C @ =SOUND_INFO_PTR
    ldr r0, [r0]
    mov r8, r0
    adds r0, r7, 0
    bl FadeOutBody
    ldr r0, [r7, O_MusicPlayer_status]
    cmp r0, 0
    bge .L0809C214
    b .L0809C414
.L0809C214:
    ldrh r0, [r7, O_MusicPlayer_tempo_c]
    ldrh r1, [r7, O_MusicPlayer_tempo_i]
    adds r0, r1
    b .L0809C364
.L0809C21C:
    ldrb r6, [r7, O_MusicPlayer_track_count]
    ldr r5, [r7, O_MusicPlayer_tracks]
    movs r3, 1
    movs r4, 0
.L0809C224:
    ldrb r0, [r5, O_MusicPlayerTrack_flags]
    movs r1, MPT_FLG_EXIST
    tst r1, r0
    bne .L0809C22E
    b .L0809C340
.L0809C22E:
    mov r10, r3
    orrs r4, r3
    mov r11, r4
    ldr r4, [r5, O_MusicPlayerTrack_chan]
    cmp r4, 0
    beq .L0809C262
.L0809C23A:
    ldrb r1, [r4, O_SoundChannel_flags]
    movs r0, SOUND_CHANNEL_SF_ON
    tst r0, r1
    beq .L0809C256
    ldrb r0, [r4, O_SoundChannel_gate_time]
    cmp r0, 0
    beq .L0809C25C
    subs r0, 1
    strb r0, [r4, O_SoundChannel_gate_time]
    bne .L0809C25C
    movs r0, SOUND_CHANNEL_SF_STOP
    orrs r1, r0
    strb r1, [r4, O_SoundChannel_flags]
    b .L0809C25C
.L0809C256:
    adds r0, r4, 0
    bl ClearChain
.L0809C25C:
    ldr r4, [r4, O_SoundChannel_next_ptr]
    cmp r4, 0
    bne .L0809C23A
.L0809C262:
    ldrb r3, [r5, O_MusicPlayerTrack_flags]
    movs r0, MPT_FLG_START
    tst r0, r3
    beq .L0809C2E0
    adds r0, r5, 0
    bl Clear64byte
    movs r0, MPT_FLG_EXIST
    strb r0, [r5, O_MusicPlayerTrack_flags]
    movs r0, 0x2
    strb r0, [r5, O_MusicPlayerTrack_bend_range]
    movs r0, 0x40
    strb r0, [r5, O_MusicPlayerTrack_vol_x]
    movs r0, 0x16
    strb r0, [r5, O_MusicPlayerTrack_lfo_speed]
    movs r0, 1
    adds r1, r5, 6
    strb r0, [r1, O_MusicPlayerTrack_ToneData_type - 6]
    b .L0809C2E0
.L0809C288:
    ldr r2, [r5, O_MusicPlayerTrack_cmd_ptr]
    ldrb r1, [r2]
    cmp r1, 0x80
    bhs .L0809C294
    ldrb r1, [r5, O_MusicPlayerTrack_running_status]
    b .L0809C29E
.L0809C294:
    adds r2, 1
    str r2, [r5, O_MusicPlayerTrack_cmd_ptr]
    cmp r1, 0xBD
    bcc .L0809C29E
    strb r1, [r5, O_MusicPlayerTrack_running_status]
.L0809C29E:
    cmp r1, 0xCF
    bcc .L0809C2B4
    mov r0, r8
    ldr r3, [r0, O_SoundInfo_plynote_func]
    adds r0, r1, 0
    subs r0, 0xCF
    adds r1, r7, 0
    adds r2, r5, 0
    bl .Lbx_r3
    b .L0809C2E0
.L0809C2B4:
    cmp r1, 0xB0
    bls .L0809C2D6
    adds r0, r1, 0
    subs r0, 0xB1
    strb r0, [r7, O_MusicPlayer_cmd]
    mov r3, r8
    ldr r3, [r3, O_SoundInfo_mplay_jump_table]
    lsls r0, 2
    ldr r3, [r3, r0]
    adds r0, r7, 0
    adds r1, r5, 0
    bl .Lbx_r3
    ldrb r0, [r5, O_MusicPlayerTrack_flags]
    cmp r0, 0
    beq .L0809C33C
    b .L0809C2E0
.L0809C2D6:
    ldr r0, .L0809C428 @ =gClockTable
    subs r1, 0x80
    adds r1, r0
    ldrb r0, [r1]
    strb r0, [r5, O_MusicPlayerTrack_wait]
.L0809C2E0:
    ldrb r0, [r5, O_MusicPlayerTrack_wait]
    cmp r0, 0
    beq .L0809C288
    subs r0, 1
    strb r0, [r5, O_MusicPlayerTrack_wait]
    ldrb r1, [r5, O_MusicPlayerTrack_lfo_speed]
    cmp r1, 0
    beq .L0809C33C
    ldrb r0, [r5, O_MusicPlayerTrack_mod]
    cmp r0, 0
    beq .L0809C33C
    ldrb r0, [r5, O_MusicPlayerTrack_lfo_delay_c]
    cmp r0, 0
    beq .L0809C302
    subs r0, 1
    strb r0, [r5, O_MusicPlayerTrack_lfo_delay_c]
    b .L0809C33C
.L0809C302:
    ldrb r0, [r5, O_MusicPlayerTrack_lfo_speed_c]
    adds r0, r1
    strb r0, [r5, O_MusicPlayerTrack_lfo_speed_c]
    adds r1, r0, 0
    subs r0, 0x40
    lsls r0, 24
    bpl .L0809C316
    lsls r2, r1, 24
    asrs r2, 24
    b .L0809C31A
.L0809C316:
    movs r0, 0x80
    subs r2, r0, r1
.L0809C31A:
    ldrb r0, [r5, O_MusicPlayerTrack_mod]
    muls r0, r2
    asrs r2, r0, 6
    ldrb r0, [r5, O_MusicPlayerTrack_mod_m]
    eors r0, r2
    lsls r0, 24
    beq .L0809C33C
    strb r2, [r5, O_MusicPlayerTrack_mod_m]
    ldrb r0, [r5]
    ldrb r1, [r5, O_MusicPlayerTrack_mod_t]
    cmp r1, 0
    bne .L0809C336
    movs r1, MPT_FLG_PITCHG
    b .L0809C338
.L0809C336:
    movs r1, MPT_FLG_VOLCHG
.L0809C338:
    orrs r0, r1
    strb r0, [r5, O_MusicPlayerTrack_flags]
.L0809C33C:
    mov r3, r10
    mov r4, r11
.L0809C340:
    subs r6, 1
    ble .L0809C34C
    movs r0, MusicPlayerTrack_size
    adds r5, r0
    lsls r3, 1
    b .L0809C224
.L0809C34C:
    ldr r0, [r7, O_MusicPlayer_clock]
    adds r0, 1
    str r0, [r7, O_MusicPlayer_clock]
    cmp r4, 0
    bne .L0809C35E
    movs r0, 0x80
    lsls r0, 24
    str r0, [r7, O_MusicPlayer_status]
    b .L0809C414
.L0809C35E:
    str r4, [r7, O_MusicPlayer_status]
    ldrh r0, [r7, O_MusicPlayer_tempo_c]
    subs r0, 150
.L0809C364:
    strh r0, [r7, O_MusicPlayer_tempo_c]
    cmp r0, 150
    bcc .L0809C36C
    b .L0809C21C
.L0809C36C:
    ldrb r2, [r7, O_MusicPlayer_track_count]
    ldr r5, [r7, O_MusicPlayer_tracks]
.L0809C370:
    ldrb r0, [r5, O_MusicPlayerTrack_flags]
    movs r1, 0x80
    tst r1, r0
    beq .L0809C40A
    movs r1, MPT_FLG_VOLCHG | MPT_FLG_PITCHG
    tst r1, r0
    beq .L0809C40A
    mov r9, r2
    adds r0, r7, 0
    adds r1, r5, 0
    bl TrkVolPitSet
    ldr r4, [r5, O_MusicPlayerTrack_chan]
    cmp r4, 0
    beq .L0809C400
.L0809C38E:
    ldrb r1, [r4, O_SoundChannel_flags]
    movs r0, SOUND_CHANNEL_SF_ON
    tst r0, r1
    bne .L0809C39E
    adds r0, r4, 0
    bl ClearChain
    b .L0809C3FA
.L0809C39E:
    ldrb r0, [r4, O_SoundChannel_type]
    movs r6, TONEDATA_TYPE_CGB
    ands r6, r0
    ldrb r3, [r5, O_MusicPlayerTrack_flags]
    movs r0, MPT_FLG_VOLCHG
    tst r0, r3
    beq .L0809C3BC
    bl ChnVolSetAsm
    cmp r6, 0
    beq .L0809C3BC
    ldrb r0, [r4, O_CgbChannel_modify]
    movs r1, 1
    orrs r0, r1
    strb r0, [r4, O_CgbChannel_modify]
.L0809C3BC:
    ldrb r3, [r5, O_MusicPlayerTrack_flags]
    movs r0, MPT_FLG_PITCHG
    tst r0, r3
    beq .L0809C3FA
    ldrb r1, [r4, O_SoundChannel_key]
    movs r0, O_MusicPlayerTrack_key_m
    ldsb r0, [r5, r0]
    adds r2, r1, r0
    bpl .L0809C3D0
    movs r2, 0
.L0809C3D0:
    cmp r6, 0
    beq .L0809C3EE
    mov r0, r8
    ldr r3, [r0, O_SoundInfo_midi_to_cgb_func]
    adds r1, r2, 0
    ldrb r2, [r5, O_MusicPlayerTrack_pit_m]
    adds r0, r6, 0
    bl .Lbx_r3
    str r0, [r4, O_CgbChannel_frequency]
    ldrb r0, [r4, O_CgbChannel_modify]
    movs r1, CGB_CHANNEL_MO_PIT
    orrs r0, r1
    strb r0, [r4, O_CgbChannel_modify]
    b .L0809C3FA
.L0809C3EE:
    adds r1, r2, 0
    ldrb r2, [r5, O_MusicPlayerTrack_pit_m]
    ldr r0, [r4, O_SoundChannel_wav]
    bl MidiKeyToFreq
    str r0, [r4, O_SoundChannel_frequency]
.L0809C3FA:
    ldr r4, [r4, O_SoundChannel_next_ptr]
    cmp r4, 0
    bne .L0809C38E
.L0809C400:
    ldrb r0, [r5, O_MusicPlayerTrack_flags]
    movs r1, 0xF0
    ands r0, r1
    strb r0, [r5, O_MusicPlayerTrack_flags]
    mov r2, r9
.L0809C40A:
    subs r2, 1
    ble .L0809C414
    movs r0, MusicPlayerTrack_size
    adds r5, r0
    bgt .L0809C370
.L0809C414:
    ldr r0, .L0809C430 @ =ID_NUMBER
    str r0, [r7, O_MusicPlayer_ident]
    pop {r0-r7}
    mov r8, r0
    mov r9, r1
    mov r10, r2
    mov r11, r3
    pop {r3}
.Lbx_r3:
    bx r3

    .align 2, 0
.L0809C428: .4byte gClockTable
.L0809C42C: .4byte SOUND_INFO_PTR
.L0809C430: .4byte ID_NUMBER

    endfunction MPlayMain

    function TrackStop
TrackStop: @ 0x0811824C
    push {r4, r5, r6, lr}
    adds r5, r1, 0
    ldrb r1, [r5]
    movs r0, 0x80
    tst r0, r1
    beq .L0809C46C
    ldr r4, [r5, 0x20]
    cmp r4, 0
    beq .L0809C46A
    movs r6, 0
.L0809C448:
    ldrb r0, [r4]
    cmp r0, 0
    beq .L0809C462
    ldrb r0, [r4, 1]
    movs r3, 7
    ands r0, r3
    beq .L0809C460
    ldr r3, .L0809C474 @ =SOUND_INFO_PTR
    ldr r3, [r3]
    ldr r3, [r3, 0x2C]
    bl .Lbx_r3
.L0809C460:
    strb r6, [r4]
.L0809C462:
    str r6, [r4, 0x2C]
    ldr r4, [r4, 0x34]
    cmp r4, 0
    bne .L0809C448
.L0809C46A:
    str r4, [r5, 0x20]
.L0809C46C:
    pop {r4, r5, r6}
    pop {r0}
    bx r0

    .align 2, 0
.L0809C474: .4byte SOUND_INFO_PTR

    endfunction TrackStop

    function ChnVolSetAsm
ChnVolSetAsm:
    ldrb r1, [r4, O_SoundChannel_velocity]
    movs r0, O_SoundChannel_rhythm_pan
    ldrsb r2, [r4, r0]
    movs r3, 0x80
    adds r3, r2
    muls r3, r1
    ldrb r0, [r5, O_MusicPlayerTrack_vol_mr]
    muls r0, r3
    asrs r0, 14
    cmp r0, 0xFF
    bls .L0809C490
    movs r0, 0xFF
.L0809C490:
    strb r0, [r4, O_SoundChannel_volume_right]
    movs r3, 0x7F
    subs r3, r2
    muls r3, r1
    ldrb r0, [r5, O_MusicPlayerTrack_vol_ml]
    muls r0, r3
    asrs r0, 14
    cmp r0, 0xFF
    bls .L0809C4A4
    movs r0, 0xFF
.L0809C4A4:
    strb r0, [r4, O_SoundChannel_volume_left]
    bx lr

    endfunction ChnVolSetAsm

    @ note: documented addresses are wrong from here on (they we copied over from pokeemerald)
    @ couldn't be bothered to change them

    function ply_note
ply_note:
    push {r4-r7,lr}
    mov r4, r8
    mov r5, r9
    mov r6, r10
    mov r7, r11
    push {r4-r7}
    sub sp, 0x18
    str r1, [sp]
    adds r5, r2, 0
    ldr r1, =SOUND_INFO_PTR
    ldr r1, [r1]
    str r1, [sp, 0x4]
    ldr r1, =gClockTable
    adds r0, r1
    ldrb r0, [r0]
    strb r0, [r5, O_MusicPlayerTrack_gate_time]
    ldr r3, [r5, O_MusicPlayerTrack_cmd_ptr]
    ldrb r0, [r3]
    cmp r0, 0x80
    bhs .L0809C4EE
    strb r0, [r5, O_MusicPlayerTrack_key]
    adds r3, 1
    ldrb r0, [r3]
    cmp r0, 0x80
    bhs .L0809C4EC
    strb r0, [r5, O_MusicPlayerTrack_velocity]
    adds r3, 1
    ldrb r0, [r3]
    cmp r0, 0x80
    bhs .L0809C4EC
    ldrb r1, [r5, O_MusicPlayerTrack_gate_time]
    adds r1, r0
    strb r1, [r5, O_MusicPlayerTrack_gate_time]
    adds r3, 1
.L0809C4EC:
    str r3, [r5, O_MusicPlayerTrack_cmd_ptr]
.L0809C4EE:
    movs r0, 0
    str r0, [sp, 0x14]
    adds r4, r5, 0
    adds r4, O_MusicPlayerTrack_ToneData_type
    ldrb r2, [r4]
    movs r0, TONEDATA_TYPE_RHY | TONEDATA_TYPE_SPL
    tst r0, r2
    beq .L0809C540
    ldrb r3, [r5, O_MusicPlayerTrack_key]
    movs r0, TONEDATA_TYPE_SPL
    tst r0, r2
    beq .L0809C50E
    ldr r1, [r5, O_MusicPlayerTrack_ToneData_keySplitTable]
    adds r1, r3
    ldrb r0, [r1]
    b .L0809C510
.L0809C50E:
    adds r0, r3, 0
.L0809C510:
    lsls r1, r0, 1
    adds r1, r0
    lsls r1, 2
    ldr r0, [r5, O_MusicPlayerTrack_ToneData_wav]
    adds r1, r0
    mov r9, r1
    mov r6, r9
    ldrb r1, [r6]
    movs r0, TONEDATA_TYPE_SPL | TONEDATA_TYPE_RHY
    tst r0, r1
    beq .L0809C528
    b .L0809C68E
.L0809C528:
    movs r0, TONEDATA_TYPE_RHY
    tst r0, r2
    beq .L0809C544
    ldrb r1, [r6, O_ToneData_pan_sweep]
    movs r0, 0x80
    tst r0, r1
    beq .L0809C53C
    subs r1, TONEDATA_P_S_PAN
    lsls r1, 1
    str r1, [sp, 0x14]
.L0809C53C:
    ldrb r3, [r6, O_SoundChannel_type]
    b .L0809C544
.L0809C540:
    mov r9, r4
    ldrb r3, [r5, O_MusicPlayerTrack_key]
.L0809C544:
    str r3, [sp, 0x8]
    ldr r6, [sp]
    ldrb r1, [r6, O_MusicPlayer_priority]
    ldrb r0, [r5, O_MusicPlayerTrack_priority]
    adds r0, r1
    cmp r0, 0xFF
    bls .L0809C554
    movs r0, 0xFF
.L0809C554:
    str r0, [sp, 0x10]
    mov r6, r9
    ldrb r0, [r6, O_ToneData_type]
    movs r6, TONEDATA_TYPE_CGB
    ands r6, r0
    str r6, [sp, 0xC]
    beq .L0809C594
    ldr r0, [sp, 0x4]
    ldr r4, [r0, O_SoundInfo_cgb_chans]
    cmp r4, 0
    bne .L0809C56C
    b .L0809C68E
.L0809C56C:
    subs r6, 1
    lsls r0, r6, 6
    adds r4, r0
    ldrb r1, [r4, O_CgbChannel_flags]
    movs r0, SOUND_CHANNEL_SF_ON
    tst r0, r1
    beq .L0809C5E8
    movs r0, SOUND_CHANNEL_SF_STOP
    tst r0, r1
    bne .L0809C5E8
    ldrb r1, [r4, O_CgbChannel_priority]
    ldr r0, [sp, 0x10]
    cmp r1, r0
    bcc .L0809C5E8
    beq .L0809C58C
    b .L0809C68E
.L0809C58C:
    ldr r0, [r4, O_CgbChannel_track]
    cmp r0, r5
    bcs .L0809C5E8
    b .L0809C68E
.L0809C594:
    ldr r6, [sp, 0x10]
    adds r7, r5, 0
    movs r2, 0
    mov r8, r2
    ldr r4, [sp, 0x4]
    ldrb r3, [r4, O_SoundInfo_max_chans]
    adds r4, O_SoundInfo_chans
.L0809C5A2:
    ldrb r1, [r4, O_SoundChannel_flags]
    movs r0, SOUND_CHANNEL_SF_ON
    tst r0, r1
    beq .L0809C5E8
    movs r0, SOUND_CHANNEL_SF_STOP
    tst r0, r1
    beq .L0809C5BC
    cmp r2, 0
    bne .L0809C5C0
    adds r2, 1
    ldrb r6, [r4, O_SoundChannel_priority]
    ldr r7, [r4, O_SoundChannel_track]
    b .L0809C5DA
.L0809C5BC:
    cmp r2, 0
    bne .L0809C5DC
.L0809C5C0:
    ldrb r0, [r4, O_SoundChannel_priority]
    cmp r0, r6
    bcs .L0809C5CC
    adds r6, r0, 0
    ldr r7, [r4, O_SoundChannel_track]
    b .L0809C5DA
.L0809C5CC:
    bhi .L0809C5DC
    ldr r0, [r4, O_SoundChannel_track]
    cmp r0, r7
    bls .L0809C5D8
    adds r7, r0, 0
    b .L0809C5DA
.L0809C5D8:
    bcc .L0809C5DC
.L0809C5DA:
    mov r8, r4
.L0809C5DC:
    adds r4, SoundChannel_size
    subs r3, 1
    bgt .L0809C5A2
    mov r4, r8
    cmp r4, 0
    beq .L0809C68E
.L0809C5E8:
    adds r0, r4, 0
    bl ClearChain
    movs r1, 0
    str r1, [r4, O_SoundChannel_prev_ptr]
    ldr r3, [r5, O_MusicPlayerTrack_chan]
    str r3, [r4, O_SoundChannel_next_ptr]
    cmp r3, 0
    beq .L0809C5FC
    str r4, [r3, O_SoundChannel_prev_ptr]
.L0809C5FC:
    str r4, [r5, O_MusicPlayerTrack_chan]
    str r5, [r4, O_SoundChannel_track]
    ldrb r0, [r5, O_MusicPlayerTrack_lfo_delay]
    strb r0, [r5, O_MusicPlayerTrack_lfo_delay_c]
    cmp r0, r1
    beq .L0809C60E
    adds r1, r5, 0
    bl clear_mod_m
.L0809C60E:
    ldr r0, [sp]
    adds r1, r5, 0
    bl TrkVolPitSet
    ldr r0, [r5, O_MusicPlayerTrack_gate_time]
    str r0, [r4, O_SoundChannel_gate_time]
    ldr r0, [sp, 0x10]
    strb r0, [r4, O_SoundChannel_priority]
    ldr r0, [sp, 0x8]
    strb r0, [r4, O_SoundChannel_key]
    ldr r0, [sp, 0x14]
    strb r0, [r4, O_SoundChannel_rhythm_pan]
    mov r6, r9
    ldrb r0, [r6, O_ToneData_type]
    strb r0, [r4, O_SoundChannel_type]
    ldr r7, [r6, O_ToneData_wav]
    str r7, [r4, O_SoundChannel_wav]
    ldr r0, [r6, O_ToneData_attack]
    str r0, [r4, O_SoundChannel_attack]
    ldrh r0, [r5, O_MusicPlayerTrack_pseudo_echo_volume]
    strh r0, [r4, O_SoundChannel_pseudo_echo_volume]
    bl ChnVolSetAsm
    ldrb r1, [r4, O_SoundChannel_key]
    movs r0, O_MusicPlayerTrack_key_m
    ldsb r0, [r5, r0]
    adds r3, r1, r0
    bpl .L0809C648
    movs r3, 0
.L0809C648:
    ldr r6, [sp, 0xC]
    cmp r6, 0
    beq .L0809C676
    mov r6, r9
    ldrb r0, [r6, O_ToneData_length]
    strb r0, [r4, O_CgbChannel_length]
    ldrb r1, [r6, O_ToneData_pan_sweep]
    movs r0, 0x80
    tst r0, r1
    bne .L0809C662
    movs r0, 0x70
    tst r0, r1
    bne .L0809C664
.L0809C662:
    movs r1, 0x8
.L0809C664:
    strb r1, [r4, O_CgbChannel_sweep]
    ldrb r2, [r5, O_MusicPlayerTrack_pit_m]
    adds r1, r3, 0
    ldr r0, [sp, 0xC]
    ldr r3, [sp, 0x4]
    ldr r3, [r3, O_SoundInfo_midi_to_cgb_func]
    bl .Lbx_r3
    b .L0809C680
.L0809C676:
    ldrb r2, [r5, O_MusicPlayerTrack_pit_m]
    adds r1, r3, 0
    adds r0, r7, 0
    bl MidiKeyToFreq
.L0809C680:
    str r0, [r4, O_SoundChannel_frequency]
    movs r0, SOUND_CHANNEL_SF_START
    strb r0, [r4, O_SoundChannel_flags]
    ldrb r1, [r5, O_MusicPlayerTrack_flags]
    movs r0, 0xF0
    ands r0, r1
    strb r0, [r5, O_MusicPlayerTrack_flags]
.L0809C68E:
    add sp, 0x18
    pop {r0-r7}
    mov r8, r0
    mov r9, r1
    mov r10, r2
    mov r11, r3
    pop {r0}
    bx r0

    .pool

    endfunction ply_note

    function ply_endtie
ply_endtie:
    push {r4, r5}
    ldr r2, [r1, O_MusicPlayerTrack_cmd_ptr]
    ldrb r3, [r2]
    cmp r3, 0x80
    bhs .Lply_endtie_load_key
    strb r3, [r1, O_MusicPlayerTrack_key]
    adds r2, #1
    str r2, [r1, O_MusicPlayerTrack_cmd_ptr]
    b 1f
.Lply_endtie_load_key:
    ldrb r3, [r1, O_MusicPlayerTrack_key]
1:
    ldr r1, [r1, O_MusicPlayerTrack_chan]
    cmp r1, 0
    beq .Lply_endtie_done
    movs r4, SOUND_CHANNEL_SF_START | SOUND_CHANNEL_SF_ENV
    movs r5, SOUND_CHANNEL_SF_STOP
.Lply_endtie_loop:
    ldrb r2, [r1, O_SoundChannel_flags]
    tst r2, r4
    beq .Lply_endtie_continue
    tst r2, r5
    bne .Lply_endtie_continue
    ldrb r0, [r1, O_SoundChannel_midi_key]
    cmp r0, r3
    bne .Lply_endtie_continue
    movs r0, SOUND_CHANNEL_SF_STOP
    orrs r2, r0
    strb r2, [r1, O_SoundChannel_flags]
    b .Lply_endtie_done
.Lply_endtie_continue:
    ldr r1, [r1, O_SoundChannel_next_ptr]
    cmp r1, 0
    bne .Lply_endtie_loop
.Lply_endtie_done:
    pop {r4, r5}
    bx lr

    endfunction ply_endtie

    .align 2, 0
clear_mod_m:
    movs r2, 0
    strb r2, [r1, O_MusicPlayerTrack_mod_m]
    strb r2, [r1, O_MusicPlayerTrack_lfo_speed_c]
    ldrb r2, [r1, O_MusicPlayerTrack_mod_t]
    cmp r2, 0
    bne .Lclear_mod_m_volchg
    movs r2, MPT_FLG_PITCHG
    b 1f
.Lclear_mod_m_volchg:
    movs r2, MPT_FLG_VOLCHG
1:
    ldrb r3, [r1]
    orrs r3, r2
    strb r3, [r1]
    bx lr

    .align 2, 0
ld_r3_tp_adr_i_unchecked:
    ldr r2, [r1, O_MusicPlayerTrack_cmd_ptr]
    adds r3, r2, 1
    str r3, [r1, O_MusicPlayerTrack_cmd_ptr]
    ldrb r3, [r2]
    bx lr

    function ply_lfos
ply_lfos:
    mov r12, lr
    bl ld_r3_tp_adr_i_unchecked
    strb r3, [r1, O_MusicPlayerTrack_lfo_speed]
    cmp r3, 0
    bne .Lply_lfos_done
    bl clear_mod_m
.Lply_lfos_done:
    bx r12

    endfunction ply_lfos

    function ply_mod
ply_mod:
    mov r12, lr
    bl ld_r3_tp_adr_i_unchecked
    strb r3, [r1, O_MusicPlayerTrack_mod]
    cmp r3, 0
    bne .Lply_mod_done
    bl clear_mod_m
.Lply_mod_done:
    bx r12

    endfunction ply_mod

    .align 2, 0
