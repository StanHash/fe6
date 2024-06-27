	.include "macro.inc"

	.syntax unified

	.section .data
	.global ProcScr_EfxSoundSE
ProcScr_EfxSoundSE: @ 08605D40
	.incbin "fe6-base.gba", 0x605D40, (0x605F18 - 0x605D40) @ length: 01D8

	.global gBanimBossBGMs
gBanimBossBGMs: @ 08605F18
	.incbin "fe6-base.gba", 0x605F18, (0x605F34 - 0x605F18) @ length: 001C

	.global gUnk_08605F34
gUnk_08605F34: @ 08605F34
	.incbin "fe6-base.gba", 0x605F34, (0x605F50 - 0x605F34) @ length: 001C

	.global gUnk_08605F50
gUnk_08605F50: @ 08605F50
	.incbin "fe6-base.gba", 0x605F50, (0x605F6C - 0x605F50) @ length: 001C

	.global gUnk_08605F6C
gUnk_08605F6C: @ 08605F6C
	.incbin "fe6-base.gba", 0x605F6C, (0x605F88 - 0x605F6C) @ length: 001C

	.section .text

	thumb_func_start EfxPlaySE
EfxPlaySE: @ 0x0805BCA8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	ldr r1, .L0805BCE4 @ =gBmSt
	movs r0, #0x20
	ldrb r1, [r1, #4]
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne .L0805BCFA
	bl func_fe6_0805BDB4
	cmp r0, #0
	bne .L0805BCEC
	bl func_fe6_0805BDA8
	adds r0, r5, #0
	bl func_fe6_08002F9C
	ldr r0, .L0805BCE8 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0805BCFA
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	bl m4aSongNumStart
	b .L0805BCFA
	.align 2, 0
.L0805BCE4: .4byte gBmSt
.L0805BCE8: .4byte gPlaySt
.L0805BCEC:
	ldr r0, .L0805BD00 @ =ProcScr_EfxSoundSE
	movs r1, #3
	bl SpawnProc
	str r5, [r0, #0x44]
	str r6, [r0, #0x48]
	strh r4, [r0, #0x2c]
.L0805BCFA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805BD00: .4byte ProcScr_EfxSoundSE

	thumb_func_start func_fe6_0805BD04
func_fe6_0805BD04: @ 0x0805BD04
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	bne .L0805BD1E
	adds r0, r4, #0
	bl Proc_Break
	b .L0805BD4A
.L0805BD1E:
	bl func_fe6_0805BDB4
	cmp r0, #0
	bne .L0805BD4A
	bl func_fe6_0805BDA8
	ldr r0, [r4, #0x44]
	bl func_fe6_08002F9C
	ldr r0, .L0805BD50 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0805BD44
	ldr r0, [r4, #0x48]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl m4aSongNumStart
.L0805BD44:
	adds r0, r4, #0
	bl Proc_Break
.L0805BD4A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805BD50: .4byte gPlaySt

	thumb_func_start DoM4aSongNumStop
DoM4aSongNumStop: @ 0x0805BD54
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl m4aSongNumStop
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0805BD64
func_fe6_0805BD64: @ 0x0805BD64
	push {r4, lr}
	adds r4, r0, #0
	adds r2, r1, #0
	ldr r1, .L0805BD88 @ =gBmSt
	movs r0, #0x20
	ldrb r1, [r1, #4]
	ands r0, r1
	cmp r0, #0
	bne .L0805BD82
	adds r0, r2, #0
	bl SetBgmVolume
	adds r0, r4, #0
	bl OverrideBgm
.L0805BD82:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805BD88: .4byte gBmSt

	thumb_func_start func_fe6_0805BD8C
func_fe6_0805BD8C: @ 0x0805BD8C
	push {lr}
	ldr r0, .L0805BD98 @ =gMusicPlayer_FightBgm
	bl m4aMPlayStop
	pop {r0}
	bx r0
	.align 2, 0
.L0805BD98: .4byte gMusicPlayer_FightBgm

	thumb_func_start UnregisterEfxSoundSeExist
UnregisterEfxSoundSeExist: @ 0x0805BD9C
	ldr r1, .L0805BDA4 @ =gUnk_Banim_0201F050
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
.L0805BDA4: .4byte gUnk_Banim_0201F050

	thumb_func_start func_fe6_0805BDA8
func_fe6_0805BDA8: @ 0x0805BDA8
	ldr r1, .L0805BDB0 @ =gUnk_Banim_0201F050
	movs r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
.L0805BDB0: .4byte gUnk_Banim_0201F050

	thumb_func_start func_fe6_0805BDB4
func_fe6_0805BDB4: @ 0x0805BDB4
	ldr r0, .L0805BDBC @ =gUnk_Banim_0201F050
	ldr r0, [r0]
	bx lr
	.align 2, 0
.L0805BDBC: .4byte gUnk_Banim_0201F050

	thumb_func_start M4aPlayWithPostionCtrl
M4aPlayWithPostionCtrl: @ 0x0805BDC0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r1, .L0805BDEC @ =gBmSt
	movs r0, #0x20
	ldrb r1, [r1, #4]
	ands r0, r1
	cmp r0, #0
	bne .L0805BE68
	cmp r2, #0
	beq .L0805BE38
	cmp r6, #0x77
	bgt .L0805BDF0
	adds r0, r6, #0
	muls r0, r6, r0
	movs r1, #0x78
	bl Div
	adds r5, r0, #0
	subs r5, #0x78
	b .L0805BE04
	.align 2, 0
.L0805BDEC: .4byte gBmSt
.L0805BDF0:
	movs r0, #0xf0
	subs r0, r0, r6
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	movs r1, #0x78
	bl Div
	movs r1, #0x78
	subs r5, r1, r0
.L0805BE04:
	ldr r2, .L0805BE2C @ =gMusicPlayerTable
	ldr r0, .L0805BE30 @ =gSongTable
	lsls r1, r4, #3
	adds r1, r1, r0
	ldrh r3, [r1, #4]
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r4, [r0]
	adds r0, r4, #0
	bl m4aMPlayImmInit
	ldr r1, .L0805BE34 @ =0x0000FFFF
	lsls r2, r5, #0x18
	asrs r2, r2, #0x18
	adds r0, r4, #0
	bl m4aMPlayPanpotControl
	b .L0805BE68
	.align 2, 0
.L0805BE2C: .4byte gMusicPlayerTable
.L0805BE30: .4byte gSongTable
.L0805BE34: .4byte 0x0000FFFF
.L0805BE38:
	ldr r2, .L0805BE70 @ =gMusicPlayerTable
	ldr r0, .L0805BE74 @ =gSongTable
	lsls r1, r4, #3
	adds r1, r1, r0
	ldrh r3, [r1, #4]
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r4, [r0]
	adds r0, r4, #0
	bl m4aMPlayImmInit
	ldr r5, .L0805BE78 @ =0x0000FFFF
	adds r0, r6, #0
	bl Screen2Pan
	adds r2, r0, #0
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r0, r4, #0
	adds r1, r5, #0
	bl m4aMPlayPanpotControl
.L0805BE68:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805BE70: .4byte gMusicPlayerTable
.L0805BE74: .4byte gSongTable
.L0805BE78: .4byte 0x0000FFFF

	thumb_func_start EfxPlaySEwithCmdCtrl
EfxPlaySEwithCmdCtrl: @ 0x0805BE7C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	mov r8, r0
	mov sb, r1
	bl GetAnimAnotherSide
	adds r6, r0, #0
	mov r0, r8
	bl GetAnimLayer
	cmp r0, #1
	bne .L0805BE9C
	b .L0805C190
.L0805BE9C:
	mov r0, r8
	bl GetAnimPosition
	adds r5, r0, #0
	cmp r5, #0
	bne .L0805BEB4
	ldr r0, .L0805BEB0 @ =0x0203CDC0
	movs r1, #0
	ldrsh r4, [r0, r1]
	b .L0805BEBA
	.align 2, 0
.L0805BEB0: .4byte 0x0203CDC0
.L0805BEB4:
	ldr r0, .L0805BEE4 @ =0x0203CDC0
	movs r3, #2
	ldrsh r4, [r0, r3]
.L0805BEBA:
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl func_fe6_0805C1A0
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r4, #0x14
	bne .L0805BED6
	mov r0, r8
	bl func_fe6_0805C2B0
	cmp r0, #0
	bne .L0805BED6
	movs r7, #2
.L0805BED6:
	cmp r5, #0
	bne .L0805BEEC
	ldr r0, .L0805BEE8 @ =0x0203CDC4
	movs r1, #0
	ldrsh r0, [r0, r1]
	b .L0805BEF2
	.align 2, 0
.L0805BEE4: .4byte 0x0203CDC0
.L0805BEE8: .4byte 0x0203CDC4
.L0805BEEC:
	ldr r0, .L0805BF30 @ =0x0203CDC4
	movs r3, #2
	ldrsh r0, [r0, r3]
.L0805BEF2:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl func_fe6_0805C2E0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r4, .L0805BF34 @ =0x0000FFFF
	mov r0, r8
	str r2, [sp]
	bl func_fe6_0805C76C
	mov r1, r8
	ldrh r1, [r1, #2]
	adds r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #1
	mov r8, r0
	mov r0, sb
	subs r0, #0x19
	ldr r2, [sp]
	cmp r0, #0x31
	bls .L0805BF24
	b .L0805C16A
.L0805BF24:
	lsls r0, r0, #2
	ldr r1, .L0805BF38 @ =.L0805BF3C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0805BF30: .4byte 0x0203CDC4
.L0805BF34: .4byte 0x0000FFFF
.L0805BF38: .4byte .L0805BF3C
.L0805BF3C: @ jump table
	.4byte .L0805C004 @ case 0
	.4byte .L0805C16A @ case 1
	.4byte .L0805C0D4 @ case 2
	.4byte .L0805C008 @ case 3
	.4byte .L0805C010 @ case 4
	.4byte .L0805C018 @ case 5
	.4byte .L0805C020 @ case 6
	.4byte .L0805C040 @ case 7
	.4byte .L0805C060 @ case 8
	.4byte .L0805C09E @ case 9
	.4byte .L0805C0A2 @ case 10
	.4byte .L0805C0A6 @ case 11
	.4byte .L0805C0AA @ case 12
	.4byte .L0805C16A @ case 13
	.4byte .L0805C16A @ case 14
	.4byte .L0805C0B4 @ case 15
	.4byte .L0805C0B8 @ case 16
	.4byte .L0805C0C0 @ case 17
	.4byte .L0805C0C6 @ case 18
	.4byte .L0805C16A @ case 19
	.4byte .L0805C16A @ case 20
	.4byte .L0805C16A @ case 21
	.4byte .L0805C16A @ case 22
	.4byte .L0805C16A @ case 23
	.4byte .L0805C16A @ case 24
	.4byte .L0805C16A @ case 25
	.4byte .L0805C0D0 @ case 26
	.4byte .L0805C0D4 @ case 27
	.4byte .L0805C0EC @ case 28
	.4byte .L0805C0FC @ case 29
	.4byte .L0805C100 @ case 30
	.4byte .L0805C104 @ case 31
	.4byte .L0805C16A @ case 32
	.4byte .L0805C16A @ case 33
	.4byte .L0805C16A @ case 34
	.4byte .L0805C108 @ case 35
	.4byte .L0805C11C @ case 36
	.4byte .L0805C130 @ case 37
	.4byte .L0805C134 @ case 38
	.4byte .L0805C13A @ case 39
	.4byte .L0805C144 @ case 40
	.4byte .L0805C148 @ case 41
	.4byte .L0805C14C @ case 42
	.4byte .L0805C16A @ case 43
	.4byte .L0805C16A @ case 44
	.4byte .L0805C152 @ case 45
	.4byte .L0805C16A @ case 46
	.4byte .L0805C156 @ case 47
	.4byte .L0805C15A @ case 48
	.4byte .L0805C164 @ case 49
.L0805C004:
	movs r4, #0xd1
	b .L0805C16C
.L0805C008:
	ldr r1, .L0805C00C @ =gUnk_08605F34
	b .L0805C0D6
	.align 2, 0
.L0805C00C: .4byte gUnk_08605F34
.L0805C010:
	ldr r1, .L0805C014 @ =gUnk_08605F50
	b .L0805C0D6
	.align 2, 0
.L0805C014: .4byte gUnk_08605F50
.L0805C018:
	ldr r1, .L0805C01C @ =gUnk_08605F6C
	b .L0805C0D6
	.align 2, 0
.L0805C01C: .4byte gUnk_08605F6C
.L0805C020:
	adds r0, r6, #0
	bl func_fe6_0805C3B8
	adds r0, r6, #0
	bl func_fe6_0805C308
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	beq .L0805C088
	cmp r0, #1
	bgt .L0805C07E
	cmp r0, #0
	bne .L0805C08E
	movs r4, #0xd2
	b .L0805C08E
.L0805C040:
	adds r0, r6, #0
	bl func_fe6_0805C3B8
	adds r0, r6, #0
	bl func_fe6_0805C308
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	beq .L0805C088
	cmp r0, #1
	bgt .L0805C07E
	cmp r0, #0
	bne .L0805C08E
	movs r4, #0xd3
	b .L0805C08E
.L0805C060:
	adds r0, r6, #0
	bl func_fe6_0805C3B8
	adds r0, r6, #0
	bl func_fe6_0805C308
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	beq .L0805C088
	cmp r0, #1
	bgt .L0805C07E
	cmp r0, #0
	beq .L0805C084
	b .L0805C08E
.L0805C07E:
	cmp r0, #2
	beq .L0805C08C
	b .L0805C08E
.L0805C084:
	movs r4, #0xd4
	b .L0805C08E
.L0805C088:
	movs r4, #0xd5
	b .L0805C08E
.L0805C08C:
	movs r4, #0xec
.L0805C08E:
	adds r0, r6, #0
	bl func_fe6_0805C76C
	ldrh r6, [r6, #2]
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	b .L0805C16C
.L0805C09E:
	movs r4, #0xc9
	b .L0805C16C
.L0805C0A2:
	movs r4, #0xc8
	b .L0805C16C
.L0805C0A6:
	movs r4, #0xca
	b .L0805C16C
.L0805C0AA:
	ldr r4, .L0805C0B0 @ =0x00000263
	b .L0805C0EE
	.align 2, 0
.L0805C0B0: .4byte 0x00000263
.L0805C0B4:
	movs r4, #0xf6
	b .L0805C16C
.L0805C0B8:
	ldr r4, .L0805C0BC @ =0x00000141
	b .L0805C16C
	.align 2, 0
.L0805C0BC: .4byte 0x00000141
.L0805C0C0:
	movs r4, #0xa1
	lsls r4, r4, #1
	b .L0805C16C
.L0805C0C6:
	ldr r4, .L0805C0CC @ =0x00000267
	b .L0805C0EE
	.align 2, 0
.L0805C0CC: .4byte 0x00000267
.L0805C0D0:
	movs r4, #0xe7
	b .L0805C16C
.L0805C0D4:
	ldr r1, .L0805C0E8 @ =gBanimBossBGMs
.L0805C0D6:
	lsls r0, r7, #2
	adds r0, r0, r1
	ldr r1, [r0]
	lsls r0, r2, #1
	adds r0, r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r4, [r0]
	b .L0805C16C
	.align 2, 0
.L0805C0E8: .4byte gBanimBossBGMs
.L0805C0EC:
	ldr r4, .L0805C0F8 @ =0x00000265
.L0805C0EE:
	cmp r5, #0
	bne .L0805C16C
	subs r4, #1
	b .L0805C16C
	.align 2, 0
.L0805C0F8: .4byte 0x00000265
.L0805C0FC:
	movs r4, #0xce
	b .L0805C16C
.L0805C100:
	movs r4, #0xcf
	b .L0805C16C
.L0805C104:
	movs r4, #0xcb
	b .L0805C16C
.L0805C108:
	ldr r4, .L0805C118 @ =0x00000263
	cmp r5, #0
	bne .L0805C110
	subs r4, #1
.L0805C110:
	movs r1, #0x80
	mov r8, r1
	b .L0805C16C
	.align 2, 0
.L0805C118: .4byte 0x00000263
.L0805C11C:
	ldr r4, .L0805C12C @ =0x00000267
	cmp r5, #0
	bne .L0805C124
	subs r4, #1
.L0805C124:
	movs r0, #0x80
	mov r8, r0
	b .L0805C16C
	.align 2, 0
.L0805C12C: .4byte 0x00000267
.L0805C130:
	movs r4, #0xf1
	b .L0805C16C
.L0805C134:
	movs r4, #0x9b
	lsls r4, r4, #1
	b .L0805C16C
.L0805C13A:
	ldr r4, .L0805C140 @ =0x00000117
	b .L0805C16C
	.align 2, 0
.L0805C140: .4byte 0x00000117
.L0805C144:
	movs r4, #0xeb
	b .L0805C16C
.L0805C148:
	movs r4, #0xea
	b .L0805C16C
.L0805C14C:
	movs r4, #0x8c
	lsls r4, r4, #1
	b .L0805C16C
.L0805C152:
	movs r4, #0xe0
	b .L0805C16C
.L0805C156:
	movs r4, #0xed
	b .L0805C16C
.L0805C15A:
	ldr r4, .L0805C160 @ =0x00000135
	b .L0805C16C
	.align 2, 0
.L0805C160: .4byte 0x00000135
.L0805C164:
	movs r4, #0x9a
	lsls r4, r4, #1
	b .L0805C16C
.L0805C16A:
	movs r4, #0
.L0805C16C:
	lsls r0, r4, #0x10
	asrs r4, r0, #0x10
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	beq .L0805C190
	mov r1, r8
	adds r0, r4, #0
	str r3, [sp, #4]
	bl EfxPlaySE
	ldr r3, [sp, #4]
	lsls r1, r3, #0x10
	asrs r1, r1, #0x10
	movs r2, #1
	adds r0, r4, #0
	bl M4aPlayWithPostionCtrl
.L0805C190:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0805C1A0
func_fe6_0805C1A0: @ 0x0805C1A0
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	bl GetBattleAnimArenaFlag
	cmp r0, #1
	bne .L0805C1B2
.L0805C1AE:
	movs r0, #0
	b .L0805C2AA
.L0805C1B2:
	cmp r4, #0x32
	bhi .L0805C2A8
	lsls r0, r4, #2
	ldr r1, .L0805C1C0 @ =.L0805C1C4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0805C1C0: .4byte .L0805C1C4
.L0805C1C4: @ jump table
	.4byte .L0805C2A8 @ case 0
	.4byte .L0805C1AE @ case 1
	.4byte .L0805C1AE @ case 2
	.4byte .L0805C1AE @ case 3
	.4byte .L0805C1AE @ case 4
	.4byte .L0805C1AE @ case 5
	.4byte .L0805C2A4 @ case 6
	.4byte .L0805C2A4 @ case 7
	.4byte .L0805C2A4 @ case 8
	.4byte .L0805C2A4 @ case 9
	.4byte .L0805C1AE @ case 10
	.4byte .L0805C2A4 @ case 11
	.4byte .L0805C290 @ case 12
	.4byte .L0805C290 @ case 13
	.4byte .L0805C29C @ case 14
	.4byte .L0805C29C @ case 15
	.4byte .L0805C294 @ case 16
	.4byte .L0805C1AE @ case 17
	.4byte .L0805C298 @ case 18
	.4byte .L0805C2A0 @ case 19
	.4byte .L0805C2A0 @ case 20
	.4byte .L0805C294 @ case 21
	.4byte .L0805C294 @ case 22
	.4byte .L0805C2A4 @ case 23
	.4byte .L0805C2A4 @ case 24
	.4byte .L0805C1AE @ case 25
	.4byte .L0805C1AE @ case 26
	.4byte .L0805C1AE @ case 27
	.4byte .L0805C1AE @ case 28
	.4byte .L0805C2A4 @ case 29
	.4byte .L0805C2A4 @ case 30
	.4byte .L0805C2A4 @ case 31
	.4byte .L0805C2A4 @ case 32
	.4byte .L0805C2A4 @ case 33
	.4byte .L0805C1AE @ case 34
	.4byte .L0805C1AE @ case 35
	.4byte .L0805C2A4 @ case 36
	.4byte .L0805C1AE @ case 37
	.4byte .L0805C298 @ case 38
	.4byte .L0805C1AE @ case 39
	.4byte .L0805C1AE @ case 40
	.4byte .L0805C1AE @ case 41
	.4byte .L0805C298 @ case 42
	.4byte .L0805C1AE @ case 43
	.4byte .L0805C2A8 @ case 44
	.4byte .L0805C2A4 @ case 45
	.4byte .L0805C2A8 @ case 46
	.4byte .L0805C1AE @ case 47
	.4byte .L0805C2A4 @ case 48
	.4byte .L0805C2A4 @ case 49
	.4byte .L0805C2A4 @ case 50
.L0805C290:
	movs r0, #1
	b .L0805C2AA
.L0805C294:
	movs r0, #2
	b .L0805C2AA
.L0805C298:
	movs r0, #3
	b .L0805C2AA
.L0805C29C:
	movs r0, #4
	b .L0805C2AA
.L0805C2A0:
	movs r0, #5
	b .L0805C2AA
.L0805C2A4:
	movs r0, #6
	b .L0805C2AA
.L0805C2A8:
	movs r0, #0
.L0805C2AA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0805C2B0
func_fe6_0805C2B0: @ 0x0805C2B0
	push {r4, r5, lr}
	adds r4, r0, #0
	bl func_fe6_0805C76C
	movs r2, #2
	ldrsh r1, [r4, r2]
	adds r5, r0, r1
	adds r0, r4, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L0805C2CE
	cmp r5, #0x58
	bgt .L0805C2D6
	b .L0805C2D2
.L0805C2CE:
	cmp r5, #0x97
	ble .L0805C2D6
.L0805C2D2:
	movs r0, #1
	b .L0805C2D8
.L0805C2D6:
	movs r0, #0
.L0805C2D8:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0805C2E0
func_fe6_0805C2E0: @ 0x0805C2E0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r2, r0, #0
	movs r1, #0
	cmp r0, #4
	bls .L0805C302
	cmp r0, #8
	bhi .L0805C2F4
	movs r1, #1
	b .L0805C302
.L0805C2F4:
	cmp r0, #0xb
	bhi .L0805C2FC
	movs r1, #2
	b .L0805C302
.L0805C2FC:
	cmp r2, #0xf
	bhi .L0805C302
	movs r1, #3
.L0805C302:
	adds r0, r1, #0
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0805C308
func_fe6_0805C308: @ 0x0805C308
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r4, .L0805C348 @ =gEfxHpLutOff
	bl GetAnimPosition
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r6, [r0, r1]
	adds r0, r5, #0
	bl GetAnimPosition
	lsls r1, r6, #1
	adds r6, r1, r0
	adds r0, r6, #0
	bl GetEfxHp
	adds r4, r0, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r6, #2
	bl GetEfxHp
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r4, r0
	beq .L0805C350
	cmp r0, #0
	beq .L0805C34C
	movs r0, #0
	b .L0805C352
	.align 2, 0
.L0805C348: .4byte gEfxHpLutOff
.L0805C34C:
	movs r0, #1
	b .L0805C352
.L0805C350:
	movs r0, #2
.L0805C352:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0805C358
func_fe6_0805C358: @ 0x0805C358
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, .L0805C37C @ =0x0000FFFF
	bl func_fe6_0805C3B8
	adds r0, r5, #0
	bl func_fe6_0805C308
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	beq .L0805C38A
	cmp r0, #1
	bgt .L0805C380
	cmp r0, #0
	beq .L0805C386
	b .L0805C390
	.align 2, 0
.L0805C37C: .4byte 0x0000FFFF
.L0805C380:
	cmp r0, #2
	beq .L0805C38E
	b .L0805C390
.L0805C386:
	movs r4, #0xd4
	b .L0805C390
.L0805C38A:
	movs r4, #0xd5
	b .L0805C390
.L0805C38E:
	movs r4, #0xec
.L0805C390:
	lsls r0, r4, #0x10
	asrs r4, r0, #0x10
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	beq .L0805C3B2
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, #0
	bl EfxPlaySE
	movs r0, #2
	ldrsh r1, [r5, r0]
	adds r0, r4, #0
	movs r2, #1
	bl M4aPlayWithPostionCtrl
.L0805C3B2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805C3B8
func_fe6_0805C3B8: @ 0x0805C3B8
	push {r4, r5, lr}
	adds r4, r0, #0
	bl GetAnimAnotherSide
	adds r5, r0, #0
	adds r0, r4, #0
	bl func_fe6_0805C308
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bgt .L0805C3F4
	cmp r0, #0
	blt .L0805C3F4
	adds r0, r5, #0
	bl CheckRoundCrit
	cmp r0, #1
	bne .L0805C3F4
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0xd8
	bl EfxPlaySE
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r0, #0xd8
	movs r2, #1
	bl M4aPlayWithPostionCtrl
.L0805C3F4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0805C3FC
func_fe6_0805C3FC: @ 0x0805C3FC
	ldr r2, .L0805C414 @ =gBattleHits
	movs r1, #8
	ldrb r2, [r2, #2]
	ands r1, r2
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	rsbs r1, r1, #0
	lsrs r1, r1, #0x1f
	cmp r0, r1
	beq .L0805C418
	movs r0, #0
	b .L0805C41A
	.align 2, 0
.L0805C414: .4byte gBattleHits
.L0805C418:
	movs r0, #1
.L0805C41A:
	bx lr

	thumb_func_start func_fe6_0805C41C
func_fe6_0805C41C: @ 0x0805C41C
	push {lr}
	cmp r0, #0
	beq .L0805C518
	bl GetItemIid
	subs r0, #0x43
	cmp r0, #0x34
	bhi .L0805C518
	lsls r0, r0, #2
	ldr r1, .L0805C438 @ =.L0805C43C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0805C438: .4byte .L0805C43C
.L0805C43C: @ jump table
	.4byte .L0805C510 @ case 0
	.4byte .L0805C510 @ case 1
	.4byte .L0805C510 @ case 2
	.4byte .L0805C510 @ case 3
	.4byte .L0805C510 @ case 4
	.4byte .L0805C518 @ case 5
	.4byte .L0805C518 @ case 6
	.4byte .L0805C510 @ case 7
	.4byte .L0805C514 @ case 8
	.4byte .L0805C514 @ case 9
	.4byte .L0805C518 @ case 10
	.4byte .L0805C510 @ case 11
	.4byte .L0805C518 @ case 12
	.4byte .L0805C514 @ case 13
	.4byte .L0805C518 @ case 14
	.4byte .L0805C510 @ case 15
	.4byte .L0805C518 @ case 16
	.4byte .L0805C518 @ case 17
	.4byte .L0805C518 @ case 18
	.4byte .L0805C518 @ case 19
	.4byte .L0805C518 @ case 20
	.4byte .L0805C518 @ case 21
	.4byte .L0805C518 @ case 22
	.4byte .L0805C518 @ case 23
	.4byte .L0805C518 @ case 24
	.4byte .L0805C518 @ case 25
	.4byte .L0805C518 @ case 26
	.4byte .L0805C518 @ case 27
	.4byte .L0805C518 @ case 28
	.4byte .L0805C518 @ case 29
	.4byte .L0805C518 @ case 30
	.4byte .L0805C518 @ case 31
	.4byte .L0805C518 @ case 32
	.4byte .L0805C518 @ case 33
	.4byte .L0805C518 @ case 34
	.4byte .L0805C518 @ case 35
	.4byte .L0805C518 @ case 36
	.4byte .L0805C518 @ case 37
	.4byte .L0805C518 @ case 38
	.4byte .L0805C518 @ case 39
	.4byte .L0805C518 @ case 40
	.4byte .L0805C518 @ case 41
	.4byte .L0805C518 @ case 42
	.4byte .L0805C518 @ case 43
	.4byte .L0805C518 @ case 44
	.4byte .L0805C518 @ case 45
	.4byte .L0805C518 @ case 46
	.4byte .L0805C518 @ case 47
	.4byte .L0805C518 @ case 48
	.4byte .L0805C518 @ case 49
	.4byte .L0805C518 @ case 50
	.4byte .L0805C510 @ case 51
	.4byte .L0805C510 @ case 52
.L0805C510:
	movs r0, #2
	b .L0805C51A
.L0805C514:
	movs r0, #1
	b .L0805C51A
.L0805C518:
	movs r0, #0
.L0805C51A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EkrPlayMainBGM
EkrPlayMainBGM: @ 0x0805C520
	push {r4, r5, r6, lr}
	ldr r0, .L0805C570 @ =gpEkrBattleUnitLeft
	ldr r1, .L0805C574 @ =gpEkrBattleUnitRight
	ldr r4, [r0]
	ldr r6, [r1]
	ldr r1, .L0805C578 @ =gBmSt
	movs r0, #0x20
	ldrb r1, [r1, #4]
	ands r0, r1
	cmp r0, #0
	beq .L0805C538
	b .L0805C728
.L0805C538:
	ldr r1, .L0805C57C @ =gUnk_Banim_0201F04C
	movs r0, #1
	str r0, [r1]
	ldr r1, .L0805C580 @ =gBanimFactionPal
	ldr r0, .L0805C584 @ =gEkrInitialHitSide
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r5, #0x49
	ldrh r0, [r0]
	cmp r0, #1
	beq .L0805C554
	movs r5, #0x48
.L0805C554:
	bl GetBattleAnimArenaFlag
	cmp r0, #1
	beq .L0805C564
	bl GetBanimLinkArenaFlag
	cmp r0, #1
	bne .L0805C588
.L0805C564:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x3a
	bl func_fe6_0805BD64
	b .L0805C72E
	.align 2, 0
.L0805C570: .4byte gpEkrBattleUnitLeft
.L0805C574: .4byte gpEkrBattleUnitRight
.L0805C578: .4byte gBmSt
.L0805C57C: .4byte gUnk_Banim_0201F04C
.L0805C580: .4byte gBanimFactionPal
.L0805C584: .4byte gEkrInitialHitSide
.L0805C588:
	ldr r0, .L0805C59C @ =gEkrDistanceType
	ldrh r0, [r0]
	cmp r0, #4
	bne .L0805C5A0
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x1c
	bl func_fe6_0805BD64
	b .L0805C72E
	.align 2, 0
.L0805C59C: .4byte gEkrDistanceType
.L0805C5A0:
	movs r2, #0
	ldr r0, [r4]
	ldrb r1, [r0, #4]
	adds r3, r0, #0
	cmp r1, #0x65
	bne .L0805C5AE
	movs r2, #1
.L0805C5AE:
	cmp r1, #0x66
	bne .L0805C5B4
	movs r2, #1
.L0805C5B4:
	cmp r2, #1
	bne .L0805C5C4
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x19
	bl func_fe6_0805BD64
	b .L0805C72E
.L0805C5C4:
	movs r2, #0
	cmp r1, #0x62
	bne .L0805C5CC
	movs r2, #1
.L0805C5CC:
	ldr r0, [r6]
	ldrb r0, [r0, #4]
	cmp r0, #0x62
	bne .L0805C5D6
	movs r2, #1
.L0805C5D6:
	cmp r1, #0x63
	bne .L0805C5DC
	movs r2, #1
.L0805C5DC:
	cmp r0, #0x63
	bne .L0805C5E2
	movs r2, #1
.L0805C5E2:
	cmp r1, #0x59
	bne .L0805C5E8
	movs r2, #1
.L0805C5E8:
	cmp r0, #0x59
	bne .L0805C5EE
	movs r2, #1
.L0805C5EE:
	cmp r2, #1
	bne .L0805C5FE
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x17
	bl func_fe6_0805BD64
	b .L0805C72E
.L0805C5FE:
	movs r2, #0
	ldrb r1, [r3, #4]
	cmp r1, #0x64
	bne .L0805C608
	movs r2, #1
.L0805C608:
	cmp r0, #0x64
	bne .L0805C60E
	movs r2, #1
.L0805C60E:
	cmp r2, #1
	bne .L0805C61E
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x18
	bl func_fe6_0805BD64
	b .L0805C72E
.L0805C61E:
	movs r2, #0
	cmp r1, #0x67
	bne .L0805C626
	movs r2, #1
.L0805C626:
	cmp r2, #1
	bne .L0805C636
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x15
	bl func_fe6_0805BD64
	b .L0805C72E
.L0805C636:
	movs r2, #0
	ldr r1, [r4, #4]
	ldr r0, [r3, #0x28]
	ldr r1, [r1, #0x24]
	orrs r0, r1
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	beq .L0805C656
	movs r0, #0xc0
	ldrb r4, [r4, #0xb]
	ands r0, r4
	cmp r0, #0x80
	bne .L0805C656
	movs r2, #1
.L0805C656:
	cmp r2, #1
	bne .L0805C666
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x16
	bl func_fe6_0805BD64
	b .L0805C72E
.L0805C666:
	movs r2, #0
	ldr r0, [r6, #4]
	adds r3, r0, #0
	ldrb r0, [r3, #4]
	cmp r0, #0x37
	bne .L0805C682
	ldr r1, .L0805C694 @ =gBattleSt
	movs r0, #0x40
	ldrb r1, [r1, #1]
	ands r0, r1
	movs r2, #1
	cmp r0, #0
	beq .L0805C682
	movs r2, #2
.L0805C682:
	cmp r2, #1
	bne .L0805C698
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x40
	bl func_fe6_0805BD64
	b .L0805C72E
	.align 2, 0
.L0805C694: .4byte gBattleSt
.L0805C698:
	cmp r2, #2
	bne .L0805C6A8
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x41
	bl func_fe6_0805BD64
	b .L0805C72E
.L0805C6A8:
	movs r2, #0
	ldrb r3, [r3, #4]
	cmp r3, #0x36
	bne .L0805C6C0
	ldr r1, .L0805C6D0 @ =gBattleSt
	movs r0, #0x40
	ldrb r1, [r1, #1]
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	rsbs r0, r0, #0
	lsrs r2, r0, #0x1f
.L0805C6C0:
	cmp r2, #1
	bne .L0805C6D4
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x14
	bl func_fe6_0805BD64
	b .L0805C72E
	.align 2, 0
.L0805C6D0: .4byte gBattleSt
.L0805C6D4:
	movs r0, #0
	bl func_fe6_0805C3FC
	cmp r0, #1
	bne .L0805C6E8
	ldr r0, .L0805C6E4 @ =gBattleUnitA
	b .L0805C6F4
	.align 2, 0
.L0805C6E4: .4byte gBattleUnitA
.L0805C6E8:
	movs r0, #1
	bl func_fe6_0805C3FC
	cmp r0, #1
	bne .L0805C704
	ldr r0, .L0805C700 @ =gBattleUnitB
.L0805C6F4:
	adds r0, #0x4a
	ldrh r0, [r0]
	bl func_fe6_0805C41C
	b .L0805C706
	.align 2, 0
.L0805C700: .4byte gBattleUnitB
.L0805C704:
	movs r0, #0
.L0805C706:
	cmp r0, #1
	beq .L0805C712
	cmp r0, #2
	bne .L0805C714
	movs r5, #0x1b
	b .L0805C714
.L0805C712:
	movs r5, #0x1a
.L0805C714:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r5, r0
	beq .L0805C728
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r5, #0
	bl func_fe6_0805BD64
	b .L0805C72E
.L0805C728:
	ldr r1, .L0805C734 @ =gUnk_Banim_0201F04C
	movs r0, #0
	str r0, [r1]
.L0805C72E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805C734: .4byte gUnk_Banim_0201F04C

	thumb_func_start EkrRestoreBGM
EkrRestoreBGM: @ 0x0805C738
	push {lr}
	bl func_fe6_08058F38
	cmp r0, #0
	bne .L0805C756
	ldr r1, .L0805C75C @ =gBmSt
	movs r0, #0x20
	ldrb r1, [r1, #4]
	ands r0, r1
	cmp r0, #0
	bne .L0805C756
	ldr r0, .L0805C760 @ =gUnk_Banim_0201F04C
	ldr r0, [r0]
	cmp r0, #0
	bne .L0805C764
.L0805C756:
	bl MakeBgmOverridePersist
	b .L0805C768
	.align 2, 0
.L0805C75C: .4byte gBmSt
.L0805C760: .4byte gUnk_Banim_0201F04C
.L0805C764:
	bl RestoreBgm
.L0805C768:
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805C76C
func_fe6_0805C76C: @ 0x0805C76C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r2, [r0, #0x3c]
	ldr r3, [r2]
	ldr r1, .L0805C79C @ =0xFFFF0000
	adds r0, r3, #0
	ands r0, r1
	cmp r0, r1
	bne .L0805C790
	ldr r7, .L0805C7A0 @ =0x0000FFFF
	ands r7, r3
	cmp r7, #0
	beq .L0805C790
.L0805C788:
	subs r7, #1
	adds r2, #0xc
	cmp r7, #0
	bne .L0805C788
.L0805C790:
	adds r6, r2, #0
	movs r7, #0
	movs r0, #0
	mov r8, r0
	b .L0805C7D8
	.align 2, 0
.L0805C79C: .4byte 0xFFFF0000
.L0805C7A0: .4byte 0x0000FFFF
.L0805C7A4:
	movs r0, #6
	ldrsh r5, [r6, r0]
	ldr r0, [r6]
	bl GetAnimSpriteRotScaleX
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r5, r5, r0
	ldr r0, [r6]
	bl GetAnimSpriteRotScaleX
	adds r4, r0, #0
	ldr r0, [r6]
	bl GetAnimSpriteRotScaleY
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r1, r4, #0
	muls r1, r0, r1
	adds r0, r1, #0
	muls r0, r5, r0
	add r8, r0
	adds r7, r7, r1
	adds r6, #0xc
.L0805C7D8:
	ldr r0, [r6]
	cmp r0, #1
	bne .L0805C7A4
	cmp r7, #0
	bne .L0805C7EC
	ldr r0, .L0805C7E8 @ =0x7FFFFFFF
	b .L0805C7F4
	.align 2, 0
.L0805C7E8: .4byte 0x7FFFFFFF
.L0805C7EC:
	mov r0, r8
	adds r1, r7, #0
	bl Div
.L0805C7F4:
	mov r8, r0
	mov r0, r8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0805C804
func_fe6_0805C804: @ 0x0805C804
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	adds r6, r3, #0
	bl EfxPlaySE
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl M4aPlayWithPostionCtrl
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805C820
func_fe6_0805C820: @ 0x0805C820
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r2, #0
	bl EfxPlaySE
	adds r0, r4, #0
	bl func_fe6_0805C76C
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #1
	bl M4aPlayWithPostionCtrl
	pop {r4, r5}
	pop {r0}
	bx r0
