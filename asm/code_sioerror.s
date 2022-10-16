	.include "macro.inc"

	.syntax unified

	thumb_func_start func_fe6_08073370
func_fe6_08073370: @ 0x08073370
	push {lr}
	ldr r1, .L08073390 @ =0x03007FF8
	movs r0, #1
	strh r0, [r1]
	bl SyncDispIo
	bl SyncBgsAndPal
	bl ApplyDataMoves
	bl m4aSoundVSync
	bl m4aSoundMain
	pop {r0}
	bx r0
	.align 2, 0
.L08073390: .4byte 0x03007FF8

	thumb_func_start func_fe6_08073394
func_fe6_08073394: @ 0x08073394
	push {r4, lr}
	ldr r4, .L080733BC @ =gKeySt
	ldr r0, [r4]
	bl RefreshKeySt
	ldr r1, [r4]
	movs r0, #9
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L080733B0
	movs r0, #0xff
	bl SoftReset
.L080733B0:
	bl VBlankIntrWait
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080733BC: .4byte gKeySt

	thumb_func_start func_fe6_080733C0
func_fe6_080733C0: @ 0x080733C0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x7c
	add r5, sp, #0x18
	bl ResetText
	bl InitTalkTextFont
	add r7, sp, #8
	add r0, sp, #0x10
	mov r8, r0
	mov r4, sp
	movs r6, #2
.L080733DC:
	adds r0, r4, #0
	movs r1, #0x16
	bl InitText
	adds r0, r4, #0
	movs r1, #0
	bl Text_SetColor
	adds r4, #8
	subs r6, #1
	cmp r6, #0
	bge .L080733DC
	movs r1, #0
	str r1, [r5, #0x30]
	mov r0, sp
	str r0, [r5, #0x34]
	str r7, [r5, #0x38]
	mov r0, r8
	str r0, [r5, #0x3c]
	adds r0, r5, #0
	adds r0, #0x5c
	strh r1, [r0]
	ldr r0, .L0807344C @ =0x00000C48
	bl DecodeMsg
	str r0, [r5, #0x2c]
	adds r0, r5, #0
	bl func_fe6_08071308
	ldr r4, .L08073450 @ =gBg0Tm+0x188
	mov r0, sp
	adds r1, r4, #0
	bl PutText
	adds r1, r4, #0
	adds r1, #0xc0
	adds r0, r7, #0
	bl PutText
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r4, r4, r0
	mov r0, r8
	adds r1, r4, #0
	bl PutText
	movs r0, #1
	bl EnableBgSync
	add sp, #0x7c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0807344C: .4byte 0x00000C48
.L08073450: .4byte gBg0Tm+0x188

	thumb_func_start func_fe6_08073454
func_fe6_08073454: @ 0x08073454
	push {r4, r5, lr}
	sub sp, #8
	movs r0, #0
	bl InitBgs
	bl m4aSoundInit
	bl InitProcs
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	ldr r2, .L080734FC @ =gDispIo
	movs r0, #1
	ldrb r1, [r2, #1]
	orrs r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #2
	ands r0, r1
	subs r1, #4
	ands r0, r1
	subs r1, #8
	ands r0, r1
	subs r1, #0x10
	ands r0, r1
	subs r1, #0x20
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r2, #1]
	adds r1, r2, #0
	adds r1, #0x3c
	movs r0, #0x3f
	ldrb r3, [r1]
	ands r0, r3
	strb r0, [r1]
	adds r1, #8
	movs r4, #0
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x45
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	strh r4, [r2, #0x38]
	bl SyncDispIo
	str r4, [sp]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	ldr r5, .L08073500 @ =0x01000008
	mov r0, sp
	adds r2, r5, #0
	bl CpuFastSet
	str r4, [sp, #4]
	add r0, sp, #4
	ldr r1, .L08073504 @ =0x06008000
	adds r2, r5, #0
	bl CpuFastSet
	bl func_fe6_080733C0
	ldr r0, .L08073508 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L080734EC
	movs r0, #0x7b
	bl m4aSongNumStart
.L080734EC:
	ldr r0, .L0807350C @ =func_fe6_08073394
	bl SetMainFunc
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080734FC: .4byte gDispIo
.L08073500: .4byte 0x01000008
.L08073504: .4byte 0x06008000
.L08073508: .4byte gPlaySt
.L0807350C: .4byte func_fe6_08073394

	thumb_func_start func_fe6_08073510
func_fe6_08073510: @ 0x08073510
	push {lr}
	ldr r1, .L08073538 @ =0x04000004
	movs r0, #8
	strh r0, [r1]
	ldr r1, .L0807353C @ =0x04000208
	movs r0, #1
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r0, #0
	strh r0, [r1]
	ldr r0, .L08073540 @ =func_fe6_08073370
	bl SetOnVBlank
	ldr r0, .L08073544 @ =func_fe6_08073454
	bl SetMainFunc
	pop {r0}
	bx r0
	.align 2, 0
.L08073538: .4byte 0x04000004
.L0807353C: .4byte 0x04000208
.L08073540: .4byte func_fe6_08073370
.L08073544: .4byte func_fe6_08073454
