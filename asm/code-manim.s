
	.include "macro.inc"

	.syntax unified

	thumb_func_start func_fe6_08066484
func_fe6_08066484: @ 0x08066484
	push {r4, r5, r7, lr}
	sub sp, #0x18
	mov r7, sp
	str r0, [r7]
	adds r0, r7, #4
	adds r1, r7, #4
	ldr r2, .L0806653C @ =gUnk_08307944
	adds r0, r1, #0
	adds r1, r2, #0
	movs r2, #0x13
	bl memcpy
	ldr r0, .L08066540 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x3c
	ldrb r1, [r0]
	movs r2, #0x3f
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x40
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08066540 @ =gDispIo
	adds r1, r7, #4
	ldr r2, [r7]
	adds r3, r2, #0
	adds r2, #0x4a
	ldrh r3, [r2]
	adds r4, r3, #1
	adds r5, r4, #0
	strh r5, [r2]
	lsls r3, r3, #0x10
	asrs r2, r3, #0x10
	adds r1, r1, r2
	adds r2, r0, #0
	adds r0, #0x44
	ldrb r2, [r0]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	ldrb r1, [r1]
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strb r1, [r0]
	ldr r0, .L08066540 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x45
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x10
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08066540 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x46
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	adds r0, r7, #4
	ldr r2, [r7]
	adds r1, r2, #0
	adds r2, #0x4a
	movs r3, #0
	ldrsh r1, [r2, r3]
	adds r0, r0, r1
	ldrb r1, [r0]
	cmp r1, #0xff
	bne .L08066534
	ldr r0, [r7]
	adds r1, r0, #0
	adds r0, #0x4a
	ldrh r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strh r2, [r0]
	ldr r0, [r7]
	bl Proc_Break
.L08066534:
	add sp, #0x18
	pop {r4, r5, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0806653C: .4byte gUnk_08307944
.L08066540: .4byte gDispIo

	thumb_func_start func_fe6_08066544
func_fe6_08066544: @ 0x08066544
	push {r7, lr}
	sub sp, #8
	add r7, sp, #4
	str r0, [r7]
	ldr r0, .L080665E0 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x3c
	ldrb r1, [r0]
	movs r2, #0x3f
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x40
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, [r7]
	adds r1, r0, #0
	adds r0, #0x4a
	ldrh r1, [r0]
	adds r2, r1, #1
	adds r3, r2, #0
	strh r3, [r0]
	lsls r0, r1, #0x10
	asrs r3, r0, #0x10
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0
	bl Interpolate
	ldr r1, .L080665E0 @ =gDispIo
	adds r2, r1, #0
	adds r1, #0x44
	ldrb r2, [r1]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	adds r2, r3, #0
	orrs r2, r0
	adds r0, r2, #0
	strb r0, [r1]
	ldr r0, .L080665E0 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x45
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x10
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L080665E0 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x46
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x4a
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0x1e
	ble .L080665D6
	ldr r0, [r7]
	bl Proc_Break
.L080665D6:
	add sp, #8
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080665E0: .4byte gDispIo

	thumb_func_start func_fe6_080665E4
func_fe6_080665E4: @ 0x080665E4
	push {r4, r7, lr}
	sub sp, #8
	mov r7, sp
	str r0, [r7]
	ldr r1, .L08066644 @ =gUnk_08665384
	adds r0, r1, #0
	movs r1, #3
	bl SpawnProc
	str r0, [r7, #4]
	ldr r0, [r7, #4]
	ldr r2, [r7]
	movs r1, #0xe
	ldrsb r1, [r2, r1]
	ldr r2, .L08066648 @ =gBmSt
	movs r4, #0xc
	ldrsh r3, [r2, r4]
	asrs r2, r3, #4
	adds r4, r2, #0
	lsls r3, r4, #0x10
	asrs r2, r3, #0x10
	subs r1, r1, r2
	lsls r2, r1, #1
	adds r1, r2, #1
	adds r2, r1, #0
	lsls r1, r2, #3
	str r1, [r0, #0x30]
	ldr r0, [r7, #4]
	ldr r2, [r7]
	movs r1, #0xf
	ldrsb r1, [r2, r1]
	ldr r2, .L08066648 @ =gBmSt
	movs r4, #0xe
	ldrsh r3, [r2, r4]
	asrs r2, r3, #4
	adds r4, r2, #0
	lsls r3, r4, #0x10
	asrs r2, r3, #0x10
	subs r1, r1, r2
	lsls r2, r1, #1
	adds r1, r2, #1
	adds r2, r1, #0
	lsls r1, r2, #3
	str r1, [r0, #0x34]
	add sp, #8
	pop {r4, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08066644: .4byte gUnk_08665384
.L08066648: .4byte gBmSt

	thumb_func_start func_fe6_0806664C
func_fe6_0806664C: @ 0x0806664C
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, [r7]
	ldr r1, [r0, #0x30]
	movs r0, #0x82
	bl PlaySeSpacial
	ldr r1, .L08066674 @ =gUnk_081B1710
	adds r0, r1, #0
	movs r1, #0x80
	movs r2, #0x20
	bl ApplyPaletteExt
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08066674: .4byte gUnk_081B1710

	thumb_func_start func_fe6_08066678
func_fe6_08066678: @ 0x08066678
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	add r7, sp, #0x10
	str r0, [r7]
	ldr r0, .L0806670C @ =gBg2Tm
	ldr r1, [r7]
	ldr r2, [r1, #0x30]
	adds r1, r2, #0
	cmp r1, #0
	bge .L08066694
	adds r1, #7
.L08066694:
	asrs r2, r1, #3
	subs r1, r2, #2
	ldr r2, [r7]
	ldr r3, [r2, #0x34]
	adds r2, r3, #0
	cmp r2, #0
	bge .L080666A4
	adds r2, #7
.L080666A4:
	asrs r3, r2, #3
	adds r2, r3, #0
	subs r2, #9
	ldr r3, .L08066710 @ =0x00004140
	movs r4, #4
	str r4, [sp]
	movs r4, #0xb
	str r4, [sp, #4]
	ldr r4, .L08066714 @ =gUnk_082DF868
	str r4, [sp, #8]
	ldr r4, .L08066718 @ =gUnk_08307970
	str r4, [r7, #4]
	ldr r5, [r7]
	adds r6, r5, #0
	adds r5, #0x48
	ldrh r6, [r5]
	adds r4, r6, #1
	mov r8, r4
	mov sb, r8
	mov r4, sb
	strh r4, [r5]
	lsls r6, r6, #0x10
	asrs r5, r6, #0x10
	ldr r6, [r7, #4]
	adds r4, r6, r5
	ldrb r5, [r4]
	str r5, [sp, #0xc]
	bl func_fe6_0801501C
	movs r0, #4
	bl EnableBgSync
	ldr r0, .L08066718 @ =gUnk_08307970
	ldr r2, [r7]
	adds r1, r2, #0
	adds r2, #0x48
	movs r3, #0
	ldrsh r1, [r2, r3]
	adds r0, r0, r1
	ldrb r1, [r0]
	cmp r1, #0xff
	bne .L080666FE
	ldr r0, [r7]
	bl Proc_Break
.L080666FE:
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0806670C: .4byte gBg2Tm
.L08066710: .4byte 0x00004140
.L08066714: .4byte gUnk_082DF868
.L08066718: .4byte gUnk_08307970

	thumb_func_start func_fe6_0806671C
func_fe6_0806671C: @ 0x0806671C
	push {r4, r7, lr}
	sub sp, #8
	mov r7, sp
	str r0, [r7]
	ldr r1, .L0806677C @ =gUnk_086653C4
	adds r0, r1, #0
	movs r1, #3
	bl SpawnProc
	str r0, [r7, #4]
	ldr r0, [r7, #4]
	ldr r2, [r7]
	movs r1, #0xe
	ldrsb r1, [r2, r1]
	ldr r2, .L08066780 @ =gBmSt
	movs r4, #0xc
	ldrsh r3, [r2, r4]
	asrs r2, r3, #4
	adds r4, r2, #0
	lsls r3, r4, #0x10
	asrs r2, r3, #0x10
	subs r1, r1, r2
	lsls r2, r1, #1
	adds r1, r2, #1
	adds r2, r1, #0
	lsls r1, r2, #3
	str r1, [r0, #0x30]
	ldr r0, [r7, #4]
	ldr r2, [r7]
	movs r1, #0xf
	ldrsb r1, [r2, r1]
	ldr r2, .L08066780 @ =gBmSt
	movs r4, #0xe
	ldrsh r3, [r2, r4]
	asrs r2, r3, #4
	adds r4, r2, #0
	lsls r3, r4, #0x10
	asrs r2, r3, #0x10
	subs r1, r1, r2
	lsls r2, r1, #1
	adds r1, r2, #1
	adds r2, r1, #0
	lsls r1, r2, #3
	str r1, [r0, #0x34]
	add sp, #8
	pop {r4, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0806677C: .4byte gUnk_086653C4
.L08066780: .4byte gBmSt

	thumb_func_start func_fe6_08066784
func_fe6_08066784: @ 0x08066784
	push {r4, r7, lr}
	sub sp, #0xc
	add r7, sp, #8
	str r0, [r7]
	ldr r0, [r7]
	ldr r1, [r0, #0x30]
	movs r0, #0x85
	bl PlaySeSpacial
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	bl func_fe6_08067324
	ldr r0, .L080667DC @ =gUnk_081B7468
	ldr r1, .L080667E0 @ =0x06013800
	bl Decompress
	ldr r0, .L080667E4 @ =gUnk_081B7650
	movs r1, #0xa0
	lsls r1, r1, #2
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, .L080667E8 @ =gUnk_082E0A14
	ldr r2, [r7]
	ldr r1, [r2, #0x30]
	ldr r2, [r7]
	ldr r3, [r2, #0x34]
	adds r2, r3, #0
	subs r2, #0x10
	ldr r3, .L080667EC @ =0x000041C0
	movs r4, #0
	str r4, [sp]
	movs r4, #2
	str r4, [sp, #4]
	bl StartSpriteAnimProc
	add sp, #0xc
	pop {r4, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080667DC: .4byte gUnk_081B7468
.L080667E0: .4byte 0x06013800
.L080667E4: .4byte gUnk_081B7650
.L080667E8: .4byte gUnk_082E0A14
.L080667EC: .4byte 0x000041C0

	thumb_func_start func_fe6_080667F0
func_fe6_080667F0: @ 0x080667F0
	push {r4, r7, lr}
	sub sp, #0xc
	add r7, sp, #8
	str r0, [r7]
	ldr r0, [r7]
	ldr r1, [r0, #0x30]
	movs r0, #0x85
	bl PlaySeSpacial
	ldr r0, .L08066828 @ =gUnk_082E0A14
	ldr r2, [r7]
	ldr r1, [r2, #0x30]
	ldr r2, [r7]
	ldr r3, [r2, #0x34]
	adds r2, r3, #0
	subs r2, #8
	ldr r3, .L0806682C @ =0x000041C0
	movs r4, #0
	str r4, [sp]
	movs r4, #2
	str r4, [sp, #4]
	bl StartSpriteAnimProc
	add sp, #0xc
	pop {r4, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08066828: .4byte gUnk_082E0A14
.L0806682C: .4byte 0x000041C0

	thumb_func_start func_fe6_08066830
func_fe6_08066830: @ 0x08066830
	push {r4, r7, lr}
	sub sp, #0xc
	add r7, sp, #8
	str r0, [r7]
	ldr r0, [r7]
	ldr r1, [r0, #0x30]
	movs r0, #0x85
	bl PlaySeSpacial
	ldr r0, .L08066864 @ =gUnk_082E0A14
	ldr r2, [r7]
	ldr r1, [r2, #0x30]
	ldr r3, [r7]
	ldr r2, [r3, #0x34]
	ldr r3, .L08066868 @ =0x000041C0
	movs r4, #0
	str r4, [sp]
	movs r4, #2
	str r4, [sp, #4]
	bl StartSpriteAnimProc
	add sp, #0xc
	pop {r4, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08066864: .4byte gUnk_082E0A14
.L08066868: .4byte 0x000041C0

	thumb_func_start func_fe6_0806686C
func_fe6_0806686C: @ 0x0806686C
	push {r4, r7, lr}
	sub sp, #8
	mov r7, sp
	str r0, [r7]
	ldr r1, .L080668D0 @ =gUnk_08665404
	adds r0, r1, #0
	movs r1, #3
	bl SpawnProc
	str r0, [r7, #4]
	ldr r0, [r7, #4]
	ldr r2, [r7]
	movs r1, #0xe
	ldrsb r1, [r2, r1]
	ldr r2, .L080668D4 @ =gBmSt
	movs r4, #0xc
	ldrsh r3, [r2, r4]
	asrs r2, r3, #4
	adds r4, r2, #0
	lsls r3, r4, #0x10
	asrs r2, r3, #0x10
	subs r1, r1, r2
	lsls r2, r1, #1
	adds r1, r2, #1
	adds r2, r1, #0
	lsls r1, r2, #3
	str r1, [r0, #0x30]
	ldr r0, [r7, #4]
	ldr r2, [r7]
	movs r1, #0xf
	ldrsb r1, [r2, r1]
	ldr r2, .L080668D4 @ =gBmSt
	movs r4, #0xe
	ldrsh r3, [r2, r4]
	asrs r2, r3, #4
	adds r4, r2, #0
	lsls r3, r4, #0x10
	asrs r2, r3, #0x10
	subs r1, r1, r2
	lsls r2, r1, #1
	adds r1, r2, #0
	lsls r2, r1, #3
	adds r1, r2, #0
	adds r1, #0x12
	str r1, [r0, #0x34]
	add sp, #8
	pop {r4, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080668D0: .4byte gUnk_08665404
.L080668D4: .4byte gBmSt

	thumb_func_start func_fe6_080668D8
func_fe6_080668D8: @ 0x080668D8
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, [r7]
	ldr r1, [r0, #0x30]
	movs r0, #0xfd
	bl PlaySeSpacial
	bl func_fe6_08069C34
	bl func_fe6_08069C74
	ldr r1, .L080669A4 @ =func_fe6_08069E50
	adds r0, r1, #0
	bl SetOnHBlankA
	bl func_fe6_08067324
	ldr r0, .L080669A8 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x3c
	ldrb r1, [r0]
	movs r2, #0x3f
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x40
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L080669A8 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x44
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x10
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L080669A8 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x45
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x10
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L080669A8 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x46
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L080669AC @ =gBg2Tm
	ldr r1, .L080669B0 @ =gBuf
	ldr r2, .L080669B4 @ =0x00004140
	bl TmApplyTsa_t
	movs r0, #4
	bl EnableBgSync
	movs r0, #2
	movs r1, #0
	movs r2, #1
	ldr r3, [r7]
	bl func_fe6_08067498
	ldr r1, .L080669B8 @ =gUnk_086660FC
	adds r0, r1, #0
	ldr r1, [r7]
	bl SpawnProc
	ldr r0, [r7]
	adds r1, r0, #0
	adds r0, #0x48
	ldrh r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strh r2, [r0]
	ldr r0, [r7]
	adds r1, r0, #0
	adds r0, #0x4a
	ldrh r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strh r2, [r0]
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080669A4: .4byte func_fe6_08069E50
.L080669A8: .4byte gDispIo
.L080669AC: .4byte gBg2Tm
.L080669B0: .4byte gBuf
.L080669B4: .4byte 0x00004140
.L080669B8: .4byte gUnk_086660FC

	thumb_func_start func_fe6_080669BC
func_fe6_080669BC: @ 0x080669BC
	push {r4, r5, r7, lr}
	sub sp, #8
	add r7, sp, #4
	str r0, [r7]
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x48
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0xb
	ble .L080669FE
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x48
	ldr r0, [r7]
	ldr r2, [r7]
	adds r1, r2, #0
	adds r2, #0x48
	ldrh r3, [r2]
	subs r1, r3, #1
	adds r2, r0, #0
	adds r0, #0x48
	ldrh r2, [r0]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strh r1, [r0]
	ldr r0, [r7]
	bl Proc_Break
.L080669FE:
	ldr r1, [r7]
	ldr r0, [r1, #0x30]
	ldr r2, [r7]
	ldr r1, [r2, #0x34]
	ldr r3, [r7]
	adds r2, r3, #0
	adds r4, r3, #0
	adds r4, #0x48
	ldr r3, [r7]
	ldr r4, [r7]
	adds r2, r4, #0
	adds r4, #0x48
	ldrh r5, [r4]
	adds r2, r5, #1
	adds r4, r3, #0
	adds r3, #0x48
	ldrh r4, [r3]
	movs r5, #0
	ands r4, r5
	adds r5, r4, #0
	adds r4, r2, #0
	orrs r5, r4
	adds r4, r5, #0
	strh r4, [r3]
	lsls r3, r2, #0x10
	asrs r2, r3, #0x10
	ldr r3, .L08066A44 @ =gUnk_0866544C
	str r3, [sp]
	movs r3, #0xc
	bl func_fe6_0806A270
	add sp, #8
	pop {r4, r5, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08066A44: .4byte gUnk_0866544C

	thumb_func_start func_fe6_08066A48
func_fe6_08066A48: @ 0x08066A48
	push {r4, r5, r7, lr}
	sub sp, #8
	add r7, sp, #4
	str r0, [r7]
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x48
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bgt .L08066A8A
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x48
	ldr r0, [r7]
	ldr r2, [r7]
	adds r1, r2, #0
	adds r2, #0x48
	ldrh r3, [r2]
	adds r1, r3, #1
	adds r2, r0, #0
	adds r0, #0x48
	ldrh r2, [r0]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strh r1, [r0]
	ldr r0, [r7]
	bl Proc_Break
.L08066A8A:
	ldr r1, [r7]
	ldr r0, [r1, #0x30]
	ldr r2, [r7]
	ldr r1, [r2, #0x34]
	ldr r3, [r7]
	adds r2, r3, #0
	adds r4, r3, #0
	adds r4, #0x48
	ldr r3, [r7]
	ldr r4, [r7]
	adds r2, r4, #0
	adds r4, #0x48
	ldrh r5, [r4]
	subs r2, r5, #1
	adds r4, r3, #0
	adds r3, #0x48
	ldrh r4, [r3]
	movs r5, #0
	ands r4, r5
	adds r5, r4, #0
	adds r4, r2, #0
	orrs r5, r4
	adds r4, r5, #0
	strh r4, [r3]
	lsls r3, r2, #0x10
	asrs r2, r3, #0x10
	ldr r3, .L08066AD0 @ =gUnk_0866544C
	str r3, [sp]
	movs r3, #0xc
	bl func_fe6_0806A270
	add sp, #8
	pop {r4, r5, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08066AD0: .4byte gUnk_0866544C

	thumb_func_start func_fe6_08066AD4
func_fe6_08066AD4: @ 0x08066AD4
	push {r4, r7, lr}
	sub sp, #8
	mov r7, sp
	str r0, [r7]
	ldr r1, .L08066B34 @ =gUnk_08665454
	adds r0, r1, #0
	movs r1, #3
	bl SpawnProc
	str r0, [r7, #4]
	ldr r0, [r7, #4]
	ldr r2, [r7]
	movs r1, #0xe
	ldrsb r1, [r2, r1]
	ldr r2, .L08066B38 @ =gBmSt
	movs r4, #0xc
	ldrsh r3, [r2, r4]
	asrs r2, r3, #4
	adds r4, r2, #0
	lsls r3, r4, #0x10
	asrs r2, r3, #0x10
	subs r1, r1, r2
	lsls r2, r1, #1
	adds r1, r2, #1
	adds r2, r1, #0
	lsls r1, r2, #3
	str r1, [r0, #0x30]
	ldr r0, [r7, #4]
	ldr r2, [r7]
	movs r1, #0xf
	ldrsb r1, [r2, r1]
	ldr r2, .L08066B38 @ =gBmSt
	movs r4, #0xe
	ldrsh r3, [r2, r4]
	asrs r2, r3, #4
	adds r4, r2, #0
	lsls r3, r4, #0x10
	asrs r2, r3, #0x10
	subs r1, r1, r2
	lsls r2, r1, #1
	adds r1, r2, #1
	adds r2, r1, #0
	lsls r1, r2, #3
	str r1, [r0, #0x34]
	add sp, #8
	pop {r4, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08066B34: .4byte gUnk_08665454
.L08066B38: .4byte gBmSt

	thumb_func_start func_fe6_08066B3C
func_fe6_08066B3C: @ 0x08066B3C
	push {r4, r7, lr}
	sub sp, #0xc
	add r7, sp, #8
	str r0, [r7]
	ldr r0, [r7]
	ldr r1, [r0, #0x30]
	movs r0, #0x83
	bl PlaySeSpacial
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	bl func_fe6_08067324
	ldr r4, .L08066C48 @ =gUnk_082E161C
	movs r0, #2
	bl GetBgChrOffset
	ldr r2, .L08066C4C @ =0x06002800
	adds r1, r0, r2
	adds r0, r4, #0
	bl Decompress
	ldr r0, .L08066C50 @ =gUnk_082E11DC
	ldr r1, .L08066C54 @ =0x06013800
	bl Decompress
	ldr r1, .L08066C58 @ =gUnk_082E172C
	adds r0, r1, #0
	movs r1, #0x80
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, .L08066C58 @ =gUnk_082E172C
	movs r1, #0xa0
	lsls r1, r1, #2
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, .L08066C5C @ =gUnk_082E174C
	ldr r2, [r7]
	ldr r1, [r2, #0x30]
	ldr r2, [r7]
	ldr r3, [r2, #0x34]
	movs r4, #0x80
	lsls r4, r4, #3
	adds r2, r3, #0
	orrs r2, r4
	ldr r3, .L08066C60 @ =0x000041C0
	movs r4, #0
	str r4, [sp]
	movs r4, #2
	str r4, [sp, #4]
	bl StartSpriteAnimProc
	ldr r0, [r7]
	adds r1, r0, #0
	adds r0, #0x48
	ldrh r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strh r2, [r0]
	ldr r0, .L08066C64 @ =gDispIo+0x3C
	ldr r1, .L08066C64 @ =gDispIo+0x3C
	ldrh r2, [r1]
	ldr r3, .L08066C68 @ =0x0000FFE0
	adds r1, r2, #0
	ands r1, r3
	adds r2, r1, #0
	strh r2, [r0]
	ldr r0, .L08066C64 @ =gDispIo+0x3C
	ldr r1, .L08066C64 @ =gDispIo+0x3C
	ldrh r2, [r1]
	movs r3, #0x10
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strh r2, [r0]
	ldr r0, .L08066C6C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x3c
	ldrb r1, [r0]
	movs r2, #0xdf
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08066C6C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x3c
	ldrb r1, [r0]
	movs r2, #0x3f
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08066C6C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x44
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x10
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08066C6C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x45
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x10
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08066C6C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x46
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	add sp, #0xc
	pop {r4, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08066C48: .4byte gUnk_082E161C
.L08066C4C: .4byte 0x06002800
.L08066C50: .4byte gUnk_082E11DC
.L08066C54: .4byte 0x06013800
.L08066C58: .4byte gUnk_082E172C
.L08066C5C: .4byte gUnk_082E174C
.L08066C60: .4byte 0x000041C0
.L08066C64: .4byte gDispIo+0x3C
.L08066C68: .4byte 0x0000FFE0
.L08066C6C: .4byte gDispIo

	thumb_func_start func_fe6_08066C70
func_fe6_08066C70: @ 0x08066C70
	push {r4, r7, lr}
	sub sp, #0xc
	add r7, sp, #8
	str r0, [r7]
	ldr r0, [r7]
	ldr r1, [r0, #0x30]
	movs r0, #0x84
	bl PlaySeSpacial
	ldr r0, .L08066D48 @ =gBg2Tm
	ldr r1, [r7]
	ldr r2, [r1, #0x30]
	adds r1, r2, #0
	cmp r1, #0
	bge .L08066C90
	adds r1, #7
.L08066C90:
	asrs r2, r1, #3
	subs r1, r2, #2
	ldr r2, [r7]
	ldr r3, [r2, #0x34]
	adds r2, r3, #0
	cmp r2, #0
	bge .L08066CA0
	adds r2, #7
.L08066CA0:
	asrs r3, r2, #3
	subs r2, r3, #2
	ldr r3, .L08066D4C @ =0x00004140
	movs r4, #4
	str r4, [sp]
	movs r4, #4
	str r4, [sp, #4]
	bl func_fe6_08014E30
	movs r0, #4
	bl EnableBgSync
	ldr r0, .L08066D50 @ =gDispIo+0x3C
	ldr r1, .L08066D50 @ =gDispIo+0x3C
	ldrh r2, [r1]
	ldr r3, .L08066D54 @ =0x0000FFE0
	adds r1, r2, #0
	ands r1, r3
	adds r2, r1, #0
	strh r2, [r0]
	ldr r0, .L08066D50 @ =gDispIo+0x3C
	ldr r1, .L08066D50 @ =gDispIo+0x3C
	ldrh r2, [r1]
	movs r3, #4
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strh r2, [r0]
	ldr r0, .L08066D58 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x3c
	ldrb r1, [r0]
	movs r2, #0xdf
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08066D58 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x3c
	ldrb r1, [r0]
	movs r2, #0x3f
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x40
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08066D58 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x44
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x10
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08066D58 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x45
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x10
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08066D58 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x46
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	add sp, #0xc
	pop {r4, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08066D48: .4byte gBg2Tm
.L08066D4C: .4byte 0x00004140
.L08066D50: .4byte gDispIo+0x3C
.L08066D54: .4byte 0x0000FFE0
.L08066D58: .4byte gDispIo

	thumb_func_start func_fe6_08066D5C
func_fe6_08066D5C: @ 0x08066D5C
	push {r7, lr}
	sub sp, #8
	add r7, sp, #4
	str r0, [r7]
	ldr r0, .L08066DF8 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x3c
	ldrb r1, [r0]
	movs r2, #0x3f
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x40
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, [r7]
	adds r1, r0, #0
	adds r0, #0x48
	ldrh r1, [r0]
	adds r2, r1, #1
	adds r3, r2, #0
	strh r3, [r0]
	lsls r0, r1, #0x10
	asrs r3, r0, #0x10
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0
	bl Interpolate
	ldr r1, .L08066DF8 @ =gDispIo
	adds r2, r1, #0
	adds r1, #0x44
	ldrb r2, [r1]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	adds r2, r3, #0
	orrs r2, r0
	adds r0, r2, #0
	strb r0, [r1]
	ldr r0, .L08066DF8 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x45
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x10
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08066DF8 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x46
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x48
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0x1d
	ble .L08066DEE
	ldr r0, [r7]
	bl Proc_Break
.L08066DEE:
	add sp, #8
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08066DF8: .4byte gDispIo

	thumb_func_start func_fe6_08066DFC
func_fe6_08066DFC: @ 0x08066DFC
	push {r4, r7, lr}
	sub sp, #8
	mov r7, sp
	str r0, [r7]
	ldr r1, .L08066E5C @ =gUnk_08665494
	adds r0, r1, #0
	movs r1, #3
	bl SpawnProc
	str r0, [r7, #4]
	ldr r0, [r7, #4]
	ldr r2, [r7]
	movs r1, #0xe
	ldrsb r1, [r2, r1]
	ldr r2, .L08066E60 @ =gBmSt
	movs r4, #0xc
	ldrsh r3, [r2, r4]
	asrs r2, r3, #4
	adds r4, r2, #0
	lsls r3, r4, #0x10
	asrs r2, r3, #0x10
	subs r1, r1, r2
	lsls r2, r1, #1
	adds r1, r2, #1
	adds r2, r1, #0
	lsls r1, r2, #3
	str r1, [r0, #0x30]
	ldr r0, [r7, #4]
	ldr r2, [r7]
	movs r1, #0xf
	ldrsb r1, [r2, r1]
	ldr r2, .L08066E60 @ =gBmSt
	movs r4, #0xe
	ldrsh r3, [r2, r4]
	asrs r2, r3, #4
	adds r4, r2, #0
	lsls r3, r4, #0x10
	asrs r2, r3, #0x10
	subs r1, r1, r2
	lsls r2, r1, #1
	adds r1, r2, #1
	adds r2, r1, #0
	lsls r1, r2, #3
	str r1, [r0, #0x34]
	add sp, #8
	pop {r4, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08066E5C: .4byte gUnk_08665494
.L08066E60: .4byte gBmSt

	thumb_func_start func_fe6_08066E64
func_fe6_08066E64: @ 0x08066E64
	push {r4, r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, [r7]
	ldr r1, [r0, #0x30]
	movs r0, #0x88
	bl PlaySeSpacial
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	bl func_fe6_08067324
	ldr r0, .L08066F24 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x3c
	ldrb r1, [r0]
	movs r2, #0x3f
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x40
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08066F24 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x44
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x10
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08066F24 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x45
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x10
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08066F24 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x46
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r4, .L08066F28 @ =gUnk_082E1884
	movs r0, #2
	bl GetBgChrOffset
	ldr r2, .L08066F2C @ =0x06002800
	adds r1, r0, r2
	adds r0, r4, #0
	bl Decompress
	ldr r1, .L08066F30 @ =gUnk_081B8934
	adds r0, r1, #0
	movs r1, #0x80
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, [r7]
	adds r1, r0, #0
	adds r0, #0x48
	ldrh r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strh r2, [r0]
	ldr r0, [r7]
	adds r1, r0, #0
	adds r0, #0x4a
	ldrh r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strh r2, [r0]
	add sp, #4
	pop {r4, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08066F24: .4byte gDispIo
.L08066F28: .4byte gUnk_082E1884
.L08066F2C: .4byte 0x06002800
.L08066F30: .4byte gUnk_081B8934

	thumb_func_start func_fe6_08066F34
func_fe6_08066F34: @ 0x08066F34
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	add r7, sp, #0x10
	str r0, [r7]
	ldr r0, .L08066FC8 @ =gBg2Tm
	ldr r1, [r7]
	ldr r2, [r1, #0x30]
	adds r1, r2, #0
	cmp r1, #0
	bge .L08066F50
	adds r1, #7
.L08066F50:
	asrs r2, r1, #3
	subs r1, r2, #2
	ldr r2, [r7]
	ldr r3, [r2, #0x34]
	adds r2, r3, #0
	cmp r2, #0
	bge .L08066F60
	adds r2, #7
.L08066F60:
	asrs r3, r2, #3
	adds r2, r3, #0
	subs r2, #8
	ldr r3, .L08066FCC @ =0x00004140
	movs r4, #4
	str r4, [sp]
	movs r4, #0xa
	str r4, [sp, #4]
	ldr r4, .L08066FD0 @ =gUnk_082E2440
	str r4, [sp, #8]
	ldr r4, .L08066FD4 @ =gUnk_08307A10
	str r4, [r7, #4]
	ldr r5, [r7]
	adds r6, r5, #0
	adds r5, #0x48
	ldrh r6, [r5]
	adds r4, r6, #1
	mov r8, r4
	mov sb, r8
	mov r4, sb
	strh r4, [r5]
	lsls r6, r6, #0x10
	asrs r5, r6, #0x10
	ldr r6, [r7, #4]
	adds r4, r6, r5
	ldrb r5, [r4]
	str r5, [sp, #0xc]
	bl func_fe6_0801501C
	movs r0, #4
	bl EnableBgSync
	ldr r0, .L08066FD4 @ =gUnk_08307A10
	ldr r2, [r7]
	adds r1, r2, #0
	adds r2, #0x48
	movs r3, #0
	ldrsh r1, [r2, r3]
	adds r0, r0, r1
	ldrb r1, [r0]
	cmp r1, #0xff
	bne .L08066FBA
	ldr r0, [r7]
	bl Proc_Break
.L08066FBA:
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08066FC8: .4byte gBg2Tm
.L08066FCC: .4byte 0x00004140
.L08066FD0: .4byte gUnk_082E2440
.L08066FD4: .4byte gUnk_08307A10

	thumb_func_start func_fe6_08066FD8
func_fe6_08066FD8: @ 0x08066FD8
	push {r7, lr}
	sub sp, #0xc
	mov r7, sp
	str r0, [r7]
	str r1, [r7, #4]
	ldr r1, .L08067038 @ =gUnk_086654BC
	adds r0, r1, #0
	movs r1, #3
	bl SpawnProc
	str r0, [r7, #8]
	ldr r0, [r7, #8]
	ldr r1, .L0806703C @ =gBmSt
	movs r3, #0xc
	ldrsh r2, [r1, r3]
	asrs r1, r2, #4
	adds r3, r1, #0
	lsls r2, r3, #0x10
	asrs r1, r2, #0x10
	ldr r2, [r7]
	subs r1, r2, r1
	lsls r2, r1, #1
	adds r1, r2, #0
	lsls r2, r1, #3
	adds r1, r2, #0
	adds r1, #8
	str r1, [r0, #0x30]
	ldr r0, [r7, #8]
	ldr r1, .L0806703C @ =gBmSt
	movs r3, #0xe
	ldrsh r2, [r1, r3]
	asrs r1, r2, #4
	adds r3, r1, #0
	lsls r2, r3, #0x10
	asrs r1, r2, #0x10
	ldr r2, [r7, #4]
	subs r1, r2, r1
	lsls r2, r1, #1
	adds r1, r2, #0
	lsls r2, r1, #3
	adds r1, r2, #0
	adds r1, #8
	str r1, [r0, #0x34]
	add sp, #0xc
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08067038: .4byte gUnk_086654BC
.L0806703C: .4byte gBmSt

	thumb_func_start func_fe6_08067040
func_fe6_08067040: @ 0x08067040
	push {r4, r7, lr}
	mov r7, sp
	ldr r0, .L08067080 @ =gAction
	ldrb r1, [r0, #0xc]
	adds r0, r1, #0
	bl GetUnit
	adds r4, r0, #0
	ldrh r0, [r4, #0xc]
	movs r1, #1
	orrs r0, r1
	ldrh r1, [r4, #0xc]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	adds r1, r2, #0
	orrs r1, r0
	adds r0, r1, #0
	strh r0, [r4, #0xc]
	ldr r1, .L08067080 @ =gAction
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	ldr r1, .L08067080 @ =gAction
	movs r2, #0x14
	ldrsb r2, [r1, r2]
	adds r1, r2, #0
	bl StartAvailableDoorTileEvent
	pop {r4, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08067080: .4byte gAction

	thumb_func_start func_fe6_08067084
func_fe6_08067084: @ 0x08067084
	push {r4, r7, lr}
	mov r7, sp
	ldr r0, .L080670B0 @ =gAction
	ldrb r1, [r0, #0xc]
	adds r0, r1, #0
	bl GetUnit
	adds r4, r0, #0
	ldrh r0, [r4, #0xc]
	ldr r1, .L080670B4 @ =0x0000FFFE
	ands r0, r1
	ldrh r1, [r4, #0xc]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	adds r1, r2, #0
	orrs r1, r0
	adds r0, r1, #0
	strh r0, [r4, #0xc]
	pop {r4, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080670B0: .4byte gAction
.L080670B4: .4byte 0x0000FFFE

	thumb_func_start func_fe6_080670B8
func_fe6_080670B8: @ 0x080670B8
	push {r4, r7, lr}
	sub sp, #0x14
	add r7, sp, #0x10
	str r0, [r7]
	ldr r0, [r7]
	ldr r1, [r0, #0x30]
	movs r0, #0x8d
	bl PlaySeSpacial
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	ldr r4, .L080671CC @ =gUnk_082DF724
	movs r0, #2
	bl GetBgChrOffset
	ldr r2, .L080671D0 @ =0x06002800
	adds r1, r0, r2
	adds r0, r4, #0
	bl Decompress
	ldr r0, .L080671D4 @ =gBg2Tm
	ldr r1, [r7]
	ldr r2, [r1, #0x30]
	adds r1, r2, #0
	cmp r1, #0
	bge .L080670F4
	adds r1, #7
.L080670F4:
	asrs r2, r1, #3
	subs r1, r2, #2
	ldr r2, [r7]
	ldr r3, [r2, #0x34]
	adds r2, r3, #0
	cmp r2, #0
	bge .L08067104
	adds r2, #7
.L08067104:
	asrs r3, r2, #3
	subs r2, r3, #2
	ldr r3, .L080671D8 @ =0x00004140
	movs r4, #4
	str r4, [sp]
	movs r4, #4
	str r4, [sp, #4]
	ldr r4, .L080671DC @ =gUnk_082DF844
	str r4, [sp, #8]
	movs r4, #0
	str r4, [sp, #0xc]
	bl func_fe6_0801501C
	movs r0, #4
	bl EnableBgSync
	ldr r0, .L080671E0 @ =gUnk_082DF6B0
	ldr r1, .L080671E4 @ =0x06013800
	bl Decompress
	ldr r0, .L080671E8 @ =gUnk_082DF704
	movs r1, #0xa0
	lsls r1, r1, #2
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, .L080671EC @ =gUnk_082DF824
	ldr r1, [r7]
	str r1, [sp]
	movs r1, #0x80
	movs r2, #0x20
	movs r3, #4
	bl func_fe6_08014D9C
	bl func_fe6_08069C34
	bl func_fe6_08069C74
	bl func_fe6_08067324
	ldr r0, .L080671F0 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x3c
	ldrb r1, [r0]
	movs r2, #0x3f
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x40
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L080671F0 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x44
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x10
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L080671F0 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x45
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x10
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L080671F0 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x46
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, [r7]
	adds r1, r0, #0
	adds r0, #0x48
	ldrh r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #1
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strh r2, [r0]
	add sp, #0x14
	pop {r4, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080671CC: .4byte gUnk_082DF724
.L080671D0: .4byte 0x06002800
.L080671D4: .4byte gBg2Tm
.L080671D8: .4byte 0x00004140
.L080671DC: .4byte gUnk_082DF844
.L080671E0: .4byte gUnk_082DF6B0
.L080671E4: .4byte 0x06013800
.L080671E8: .4byte gUnk_082DF704
.L080671EC: .4byte gUnk_082DF824
.L080671F0: .4byte gDispIo

	thumb_func_start func_fe6_080671F4
func_fe6_080671F4: @ 0x080671F4
	push {r4, r7, lr}
	sub sp, #0x10
	add r7, sp, #8
	str r0, [r7]
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x48
	movs r0, #0
	ldrsh r3, [r1, r0]
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #5
	movs r1, #1
	movs r2, #0x10
	bl Interpolate
	str r0, [r7, #4]
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x48
	ldr r0, [r7]
	ldr r2, [r7]
	adds r1, r2, #0
	adds r2, #0x48
	ldrh r3, [r2]
	adds r1, r3, #1
	adds r2, r0, #0
	adds r0, #0x48
	ldrh r2, [r0]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strh r1, [r0]
	ldr r1, [r7]
	ldr r0, [r1, #0x30]
	ldr r2, [r7]
	ldr r1, [r2, #0x34]
	ldr r2, [r7, #4]
	bl func_fe6_08069DA4
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x48
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0x1d
	ble .L0806729E
	ldr r0, [r7]
	adds r1, r0, #0
	adds r0, #0x48
	ldrh r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strh r2, [r0]
	ldr r0, [r7]
	bl Proc_Break
	ldr r0, .L080672A8 @ =gUnk_082A84A4
	ldr r2, [r7]
	ldr r1, [r2, #0x30]
	ldr r3, [r7]
	ldr r2, [r3, #0x34]
	ldr r3, .L080672AC @ =0x000041C0
	movs r4, #0
	str r4, [sp]
	movs r4, #2
	str r4, [sp, #4]
	bl StartSpriteAnimProc
	ldr r0, .L080672A8 @ =gUnk_082A84A4
	ldr r2, [r7]
	ldr r1, [r2, #0x30]
	ldr r3, [r7]
	ldr r2, [r3, #0x34]
	ldr r3, .L080672AC @ =0x000041C0
	movs r4, #1
	str r4, [sp]
	movs r4, #2
	str r4, [sp, #4]
	bl StartSpriteAnimProc
.L0806729E:
	add sp, #0x10
	pop {r4, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080672A8: .4byte gUnk_082A84A4
.L080672AC: .4byte 0x000041C0

	thumb_func_start func_fe6_080672B0
func_fe6_080672B0: @ 0x080672B0
	push {r7, lr}
	sub sp, #0xc
	add r7, sp, #4
	str r0, [r7]
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x48
	movs r0, #0
	ldrsh r3, [r1, r0]
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #5
	movs r1, #0x10
	movs r2, #0
	bl Interpolate
	str r0, [r7, #4]
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x48
	ldr r0, [r7]
	ldr r2, [r7]
	adds r1, r2, #0
	adds r2, #0x48
	ldrh r3, [r2]
	adds r1, r3, #1
	adds r2, r0, #0
	adds r0, #0x48
	ldrh r2, [r0]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strh r1, [r0]
	ldr r1, [r7]
	ldr r0, [r1, #0x30]
	ldr r2, [r7]
	ldr r1, [r2, #0x34]
	ldr r2, [r7, #4]
	bl func_fe6_08069DA4
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x48
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0x1d
	ble .L0806731A
	ldr r0, [r7]
	bl Proc_Break
.L0806731A:
	add sp, #0xc
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08067324
func_fe6_08067324: @ 0x08067324
	push {r7, lr}
	mov r7, sp
	ldr r0, .L08067488 @ =gDispIo
	ldrb r1, [r0, #0xc]
	movs r2, #0xfc
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0, #0xc]
	ldr r0, .L08067488 @ =gDispIo
	ldrb r1, [r0, #0x10]
	movs r2, #0xfc
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0, #0x10]
	ldr r0, .L08067488 @ =gDispIo
	ldrb r1, [r0, #0x14]
	movs r2, #0xfc
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0, #0x14]
	ldr r0, .L08067488 @ =gDispIo
	ldrb r1, [r0, #0x18]
	movs r2, #0xfc
	ands r1, r2
	adds r2, r1, #0
	movs r3, #2
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0, #0x18]
	ldr r0, .L0806748C @ =gDispIo+0x3C
	ldr r1, .L0806748C @ =gDispIo+0x3C
	ldrh r2, [r1]
	ldr r3, .L08067490 @ =0x0000FFE0
	adds r1, r2, #0
	ands r1, r3
	adds r2, r1, #0
	strh r2, [r0]
	ldr r0, .L0806748C @ =gDispIo+0x3C
	ldr r1, .L0806748C @ =gDispIo+0x3C
	ldrh r2, [r1]
	movs r3, #4
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strh r2, [r0]
	ldr r0, .L08067488 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x3c
	ldrb r1, [r0]
	movs r2, #0xdf
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L0806748C @ =gDispIo+0x3C
	ldr r1, .L0806748C @ =gDispIo+0x3C
	ldrh r2, [r1]
	ldr r3, .L08067494 @ =0x0000E0FF
	adds r1, r2, #0
	ands r1, r3
	adds r2, r1, #0
	strh r2, [r0]
	ldr r0, .L0806748C @ =gDispIo+0x3C
	ldr r1, .L0806748C @ =gDispIo+0x3C
	ldrh r2, [r1]
	movs r3, #0xc0
	lsls r3, r3, #5
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strh r2, [r0]
	ldr r0, .L08067488 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x3d
	ldrb r1, [r0]
	movs r2, #0x20
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08067488 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r2, #0x20
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08067488 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r2, #0xdf
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08067488 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r2, #1
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08067488 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r2, #2
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08067488 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r2, #4
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08067488 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r2, #8
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08067488 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r2, #0x10
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08067488 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r2, #1
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08067488 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r2, #2
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08067488 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r2, #0xfb
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08067488 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r2, #8
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08067488 @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r2, #0x10
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08067488: .4byte gDispIo
.L0806748C: .4byte gDispIo+0x3C
.L08067490: .4byte 0x0000FFE0
.L08067494: .4byte 0x0000E0FF

	thumb_func_start func_fe6_08067498
func_fe6_08067498: @ 0x08067498
	push {r7, lr}
	sub sp, #0x14
	mov r7, sp
	str r0, [r7]
	str r1, [r7, #4]
	str r2, [r7, #8]
	str r3, [r7, #0xc]
	ldr r0, .L08067510 @ =gUnk_08665514
	ldr r1, [r7, #0xc]
	bl SpawnProc
	str r0, [r7, #0x10]
	ldr r0, [r7, #0x10]
	ldr r1, [r7]
	str r1, [r0, #0x58]
	ldr r0, [r7, #0x10]
	adds r1, r0, #0
	adds r0, #0x64
	ldrh r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strh r2, [r0]
	ldr r1, [r7, #0x10]
	ldr r2, [r7, #4]
	adds r0, r2, #0
	adds r2, r1, #0
	adds r1, #0x66
	ldrh r2, [r1]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	orrs r0, r3
	adds r2, r0, #0
	strh r2, [r1]
	ldr r0, [r7, #0x10]
	adds r1, r0, #0
	adds r0, #0x68
	ldrh r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strh r2, [r0]
	ldr r1, [r7, #0x10]
	ldr r2, [r7, #8]
	adds r0, r2, #0
	adds r2, r1, #0
	adds r1, #0x6a
	ldrh r2, [r1]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	orrs r0, r3
	adds r2, r0, #0
	strh r2, [r1]
	add sp, #0x14
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08067510: .4byte gUnk_08665514

	thumb_func_start func_fe6_08067514
func_fe6_08067514: @ 0x08067514
	push {r7, lr}
	mov r7, sp
	ldr r1, .L08067528 @ =gUnk_08665514
	adds r0, r1, #0
	bl Proc_EndEach
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08067528: .4byte gUnk_08665514

	thumb_func_start func_fe6_0806752C
func_fe6_0806752C: @ 0x0806752C
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, [r7]
	ldr r1, [r0, #0x58]
	adds r0, r1, #0
	lsls r1, r0, #0x10
	lsrs r0, r1, #0x10
	ldr r2, [r7]
	adds r1, r2, #0
	adds r2, #0x64
	ldrh r1, [r2]
	ldr r3, [r7]
	adds r2, r3, #0
	adds r3, #0x68
	ldrh r2, [r3]
	bl SetBgOffset
	ldr r0, [r7]
	ldr r1, [r7]
	adds r2, r1, #0
	adds r1, #0x64
	ldr r3, [r7]
	adds r2, r3, #0
	adds r3, #0x66
	ldrh r1, [r1]
	ldrh r2, [r3]
	adds r1, r1, r2
	adds r2, r0, #0
	adds r0, #0x64
	ldrh r2, [r0]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strh r1, [r0]
	ldr r0, [r7]
	ldr r1, [r7]
	adds r2, r1, #0
	adds r1, #0x68
	ldr r3, [r7]
	adds r2, r3, #0
	adds r3, #0x6a
	ldrh r1, [r1]
	ldrh r2, [r3]
	adds r1, r1, r2
	adds r2, r0, #0
	adds r0, #0x68
	ldrh r2, [r0]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strh r1, [r0]
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080675AC
func_fe6_080675AC: @ 0x080675AC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	mov r7, sp
	str r0, [r7]
	str r1, [r7, #4]
	str r2, [r7, #8]
	ldr r1, .L0806764C @ =gBg1Tm
	adds r0, r1, #0
	movs r1, #0
	bl TmFill
	ldr r5, .L08067650 @ =gUnk_08114D80
	movs r0, #1
	bl GetBgChrOffset
	ldr r2, .L08067654 @ =0x06004000
	adds r1, r0, r2
	adds r0, r5, #0
	bl Decompress
	ldr r0, .L08067658 @ =gUnk_08114FCC
	ldr r1, .L0806765C @ =gBuf
	bl Decompress
	ldr r0, .L0806765C @ =gBuf
	ldr r1, .L0806764C @ =gBg1Tm
	movs r2, #0xe0
	lsls r2, r2, #2
	movs r3, #0xa4
	lsls r3, r3, #7
	bl func_fe6_080152C4
	ldr r1, .L08067660 @ =gUnk_081150C8
	adds r0, r1, #0
	movs r1, #0xa0
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r1, [r7, #8]
	lsls r0, r1, #5
	adds r1, r0, #1
	ldr r2, [r7, #4]
	adds r0, r1, r2
	adds r1, r0, #0
	lsls r0, r1, #1
	ldr r1, .L08067664 @ =gBg0Tm
	adds r5, r0, r1
	ldr r0, .L08067668 @ =gMapAnimSt
	ldr r1, [r7]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, [r1, #4]
	ldrh r1, [r0]
	adds r0, r1, #0
	bl DecodeMsg
	adds r2, r0, #0
	adds r0, r5, #0
	movs r1, #0
	bl PutString
	movs r0, #0
	str r0, [r7, #0xc]
.L08067636:
	ldr r0, .L0806766C @ =gUnk_08665524
	ldr r1, [r7, #0xc]
	adds r3, r1, #0
	lsls r2, r3, #1
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	cmp r1, #0xff
	bne .L08067670
	b .L0806770C
	.align 2, 0
.L0806764C: .4byte gBg1Tm
.L08067650: .4byte gUnk_08114D80
.L08067654: .4byte 0x06004000
.L08067658: .4byte gUnk_08114FCC
.L0806765C: .4byte gBuf
.L08067660: .4byte gUnk_081150C8
.L08067664: .4byte gBg0Tm
.L08067668: .4byte gMapAnimSt
.L0806766C: .4byte gUnk_08665524
.L08067670:
	ldr r0, .L080676E0 @ =gUnk_08665524
	ldr r1, [r7, #0xc]
	adds r3, r1, #0
	lsls r2, r3, #1
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldrb r1, [r0, #1]
	ldr r0, [r7, #8]
	adds r1, r1, r0
	lsls r0, r1, #5
	ldr r1, .L080676E0 @ =gUnk_08665524
	ldr r2, [r7, #0xc]
	adds r5, r2, #0
	lsls r3, r5, #1
	adds r3, r3, r2
	lsls r2, r3, #2
	adds r1, r1, r2
	ldrb r2, [r1]
	ldr r3, [r7, #4]
	adds r1, r2, r3
	adds r0, r0, r1
	adds r1, r0, #0
	lsls r0, r1, #1
	ldr r1, .L080676E4 @ =gBg0Tm
	adds r5, r0, r1
	ldr r0, .L080676E8 @ =gMapAnimSt
	ldr r1, [r7]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r1, #0
	bl UnitKnowsMagic
	strb r0, [r7, #0x10]
	bl GetLang
	ldr r1, .L080676E0 @ =gUnk_08665524
	ldr r2, [r7, #0xc]
	mov r8, r2
	mov r6, r8
	lsls r3, r6, #1
	adds r3, r3, r2
	lsls r2, r3, #2
	adds r4, r2, #0
	ldrb r2, [r7, #0x10]
	lsls r3, r2, #0x18
	asrs r2, r3, #0x18
	cmp r2, #1
	bne .L080676EC
	adds r2, r4, #4
	b .L080676EE
	.align 2, 0
.L080676E0: .4byte gUnk_08665524
.L080676E4: .4byte gBg0Tm
.L080676E8: .4byte gMapAnimSt
.L080676EC:
	adds r2, r4, #0
.L080676EE:
	adds r3, r1, #4
	adds r1, r3, r2
	lsls r2, r0, #2
	ldr r1, [r1]
	adds r0, r2, r1
	ldr r3, [r0]
	adds r0, r5, #0
	movs r1, #3
	movs r2, #3
	bl PutStringCentered
	ldr r0, [r7, #0xc]
	adds r1, r0, #1
	str r1, [r7, #0xc]
	b .L08067636
.L0806770C:
	movs r0, #3
	bl EnableBgSync
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start MALevelUp_DrawActorStat
MALevelUp_DrawActorStat: @ 0x08067720
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	mov r7, sp
	str r0, [r7]
	str r1, [r7, #4]
	str r2, [r7, #8]
	str r3, [r7, #0xc]
	ldr r0, [r7, #0x28]
	adds r1, r7, #0
	adds r1, #0x10
	strb r0, [r1]
	ldr r0, .L080677A0 @ =gUnk_08665524
	ldr r1, [r7, #0xc]
	adds r3, r1, #0
	lsls r2, r3, #1
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldrb r1, [r0, #1]
	ldr r2, [r7, #8]
	adds r0, r1, r2
	lsls r1, r0, #5
	adds r0, r1, #4
	ldr r1, .L080677A0 @ =gUnk_08665524
	ldr r2, [r7, #0xc]
	adds r5, r2, #0
	lsls r3, r5, #1
	adds r3, r3, r2
	lsls r2, r3, #2
	adds r1, r1, r2
	ldrb r2, [r1]
	ldr r3, [r7, #4]
	adds r1, r2, r3
	adds r0, r0, r1
	adds r1, r0, #0
	lsls r0, r1, #1
	ldr r1, .L080677A4 @ =gBg0Tm
	adds r5, r0, r1
	ldr r1, [r7, #0xc]
	ldr r0, [r7]
	bl func_fe6_08067920
	adds r4, r0, #0
	adds r6, r4, #0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #0
	beq .L0806778E
	ldr r1, [r7, #0xc]
	ldr r0, [r7]
	bl MALevelUp_GetActorStatUp
	adds r6, r6, r0
.L0806778E:
	adds r0, r5, #0
	movs r1, #2
	adds r2, r6, #0
	bl PutNumberOrBlank
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080677A0: .4byte gUnk_08665524
.L080677A4: .4byte gBg0Tm

	thumb_func_start MALevelUp_GetActorStatUp
MALevelUp_GetActorStatUp: @ 0x080677A8
	push {r7, lr}
	sub sp, #8
	mov r7, sp
	str r0, [r7]
	str r1, [r7, #4]
	ldr r0, [r7, #4]
	cmp r0, #8
	bls .L080677BA
	b .L08067914
.L080677BA:
	ldr r0, [r7, #4]
	adds r1, r0, #0
	lsls r0, r1, #2
	ldr r1, .L080677C8 @ =.L080677CC
	adds r0, r0, r1
	ldr r1, [r0]
	mov pc, r1
	.align 2, 0
.L080677C8: .4byte .L080677CC
.L080677CC: @ jump table
	.4byte .L080677F0 @ case 0
	.4byte .L080677F4 @ case 1
	.4byte .L08067818 @ case 2
	.4byte .L0806783C @ case 3
	.4byte .L08067860 @ case 4
	.4byte .L08067884 @ case 5
	.4byte .L080678A8 @ case 6
	.4byte .L080678CC @ case 7
	.4byte .L080678F0 @ case 8
.L080677F0:
	movs r0, #1
	b .L08067918
.L080677F4:
	ldr r0, .L08067814 @ =gMapAnimSt
	ldr r1, [r7]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #4
	adds r1, r0, r1
	ldr r2, [r1]
	adds r0, r2, #0
	adds r2, #0x6f
	movs r1, #0
	ldrsb r1, [r2, r1]
	adds r0, r1, #0
	b .L08067918
	.align 2, 0
.L08067814: .4byte gMapAnimSt
.L08067818:
	ldr r0, .L08067838 @ =gMapAnimSt
	ldr r1, [r7]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #4
	adds r1, r0, r1
	ldr r2, [r1]
	adds r0, r2, #0
	adds r2, #0x70
	movs r1, #0
	ldrsb r1, [r2, r1]
	adds r0, r1, #0
	b .L08067918
	.align 2, 0
.L08067838: .4byte gMapAnimSt
.L0806783C:
	ldr r0, .L0806785C @ =gMapAnimSt
	ldr r1, [r7]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #4
	adds r1, r0, r1
	ldr r2, [r1]
	adds r0, r2, #0
	adds r2, #0x71
	movs r1, #0
	ldrsb r1, [r2, r1]
	adds r0, r1, #0
	b .L08067918
	.align 2, 0
.L0806785C: .4byte gMapAnimSt
.L08067860:
	ldr r0, .L08067880 @ =gMapAnimSt
	ldr r1, [r7]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #4
	adds r1, r0, r1
	ldr r2, [r1]
	adds r0, r2, #0
	adds r2, #0x72
	movs r1, #0
	ldrsb r1, [r2, r1]
	adds r0, r1, #0
	b .L08067918
	.align 2, 0
.L08067880: .4byte gMapAnimSt
.L08067884:
	ldr r0, .L080678A4 @ =gMapAnimSt
	ldr r1, [r7]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #4
	adds r1, r0, r1
	ldr r2, [r1]
	adds r0, r2, #0
	adds r2, #0x75
	movs r1, #0
	ldrsb r1, [r2, r1]
	adds r0, r1, #0
	b .L08067918
	.align 2, 0
.L080678A4: .4byte gMapAnimSt
.L080678A8:
	ldr r0, .L080678C8 @ =gMapAnimSt
	ldr r1, [r7]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #4
	adds r1, r0, r1
	ldr r2, [r1]
	adds r0, r2, #0
	adds r2, #0x73
	movs r1, #0
	ldrsb r1, [r2, r1]
	adds r0, r1, #0
	b .L08067918
	.align 2, 0
.L080678C8: .4byte gMapAnimSt
.L080678CC:
	ldr r0, .L080678EC @ =gMapAnimSt
	ldr r1, [r7]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #4
	adds r1, r0, r1
	ldr r2, [r1]
	adds r0, r2, #0
	adds r2, #0x74
	movs r1, #0
	ldrsb r1, [r2, r1]
	adds r0, r1, #0
	b .L08067918
	.align 2, 0
.L080678EC: .4byte gMapAnimSt
.L080678F0:
	ldr r0, .L08067910 @ =gMapAnimSt
	ldr r1, [r7]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #4
	adds r1, r0, r1
	ldr r2, [r1]
	adds r0, r2, #0
	adds r2, #0x76
	movs r1, #0
	ldrsb r1, [r2, r1]
	adds r0, r1, #0
	b .L08067918
	.align 2, 0
.L08067910: .4byte gMapAnimSt
.L08067914:
	movs r0, #0
	b .L08067918
.L08067918:
	add sp, #8
	pop {r7}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_08067920
func_fe6_08067920: @ 0x08067920
	push {r7, lr}
	sub sp, #0xc
	mov r7, sp
	str r0, [r7]
	str r1, [r7, #4]
	ldr r0, .L0806795C @ =gMapAnimSt
	ldr r1, [r7]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r2, #0xb
	ldrsb r2, [r1, r2]
	adds r0, r2, #0
	bl GetUnit
	str r0, [r7, #8]
	ldr r0, [r7, #4]
	cmp r0, #8
	bhi .L08067A08
	ldr r0, [r7, #4]
	adds r1, r0, #0
	lsls r0, r1, #2
	ldr r1, .L08067960 @ =.L08067964
	adds r0, r0, r1
	ldr r1, [r0]
	mov pc, r1
	.align 2, 0
.L0806795C: .4byte gMapAnimSt
.L08067960: .4byte .L08067964
.L08067964: @ jump table
	.4byte .L08067988 @ case 0
	.4byte .L080679AC @ case 1
	.4byte .L080679B6 @ case 2
	.4byte .L080679C0 @ case 3
	.4byte .L080679CA @ case 4
	.4byte .L080679D4 @ case 5
	.4byte .L080679DE @ case 6
	.4byte .L080679E8 @ case 7
	.4byte .L080679F2 @ case 8
.L08067988:
	ldr r0, .L080679A8 @ =gMapAnimSt
	ldr r1, [r7]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #4
	adds r1, r0, r1
	ldr r2, [r1]
	adds r0, r2, #0
	adds r2, #0x6c
	movs r1, #0
	ldrsb r1, [r2, r1]
	adds r0, r1, #0
	b .L08067A0C
	.align 2, 0
.L080679A8: .4byte gMapAnimSt
.L080679AC:
	ldr r0, [r7, #8]
	movs r1, #0x10
	ldrsb r1, [r0, r1]
	adds r0, r1, #0
	b .L08067A0C
.L080679B6:
	ldr r0, [r7, #8]
	movs r1, #0x12
	ldrsb r1, [r0, r1]
	adds r0, r1, #0
	b .L08067A0C
.L080679C0:
	ldr r0, [r7, #8]
	movs r1, #0x13
	ldrsb r1, [r0, r1]
	adds r0, r1, #0
	b .L08067A0C
.L080679CA:
	ldr r0, [r7, #8]
	movs r1, #0x14
	ldrsb r1, [r0, r1]
	adds r0, r1, #0
	b .L08067A0C
.L080679D4:
	ldr r0, [r7, #8]
	movs r1, #0x17
	ldrsb r1, [r0, r1]
	adds r0, r1, #0
	b .L08067A0C
.L080679DE:
	ldr r0, [r7, #8]
	movs r1, #0x15
	ldrsb r1, [r0, r1]
	adds r0, r1, #0
	b .L08067A0C
.L080679E8:
	ldr r0, [r7, #8]
	movs r1, #0x16
	ldrsb r1, [r0, r1]
	adds r0, r1, #0
	b .L08067A0C
.L080679F2:
	ldr r0, [r7, #8]
	ldr r2, [r0, #4]
	movs r1, #0x11
	ldrsb r1, [r2, r1]
	ldr r0, [r7, #8]
	ldr r2, [r0]
	movs r0, #0x13
	ldrsb r0, [r2, r0]
	adds r1, r1, r0
	adds r0, r1, #0
	b .L08067A0C
.L08067A08:
	movs r0, #0
	b .L08067A0C
.L08067A0C:
	add sp, #0xc
	pop {r7}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_08067A14
func_fe6_08067A14: @ 0x08067A14
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	bl EndEachSpriteAnimProc
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08067A28
func_fe6_08067A28: @ 0x08067A28
	push {r7, lr}
	sub sp, #0x18
	mov r7, sp
	str r0, [r7]
	str r1, [r7, #4]
	str r2, [r7, #8]
	str r3, [r7, #0xc]
	ldr r0, .L08067ADC @ =gUnk_0866559C
	ldr r1, [r7, #0xc]
	bl SpawnProc
	str r0, [r7, #0x10]
	ldr r0, [r7, #0x10]
	ldr r2, [r7]
	adds r1, r2, #0
	ldrh r2, [r0, #0x2a]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strh r2, [r0, #0x2a]
	ldr r0, [r7, #0x10]
	ldr r2, [r7, #4]
	adds r1, r2, #0
	ldrh r2, [r0, #0x2c]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strh r2, [r0, #0x2c]
	ldr r0, [r7, #0x10]
	ldr r2, [r7, #8]
	adds r1, r2, #0
	ldrh r2, [r0, #0x2e]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strh r2, [r0, #0x2e]
	ldr r0, .L08067AE0 @ =gUnk_082DBB24
	ldr r1, [r7]
	lsls r2, r1, #0x16
	lsrs r1, r2, #0x16
	lsls r2, r1, #5
	ldr r3, .L08067AE4 @ =0x06010000
	adds r1, r2, r3
	bl Decompress
	ldr r0, .L08067AE8 @ =gUnk_082DBAC4
	ldr r2, [r7, #4]
	adds r1, r2, #0
	adds r1, #0x10
	adds r2, r1, #0
	lsls r1, r2, #5
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, .L08067AE8 @ =gUnk_082DBAC4
	ldr r2, [r7, #4]
	adds r1, r2, #0
	adds r1, #0x11
	adds r2, r1, #0
	lsls r1, r2, #5
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, .L08067AEC @ =gUnk_086655AC
	ldr r1, [r7, #0x10]
	bl SpawnProc
	str r0, [r7, #0x14]
	ldr r1, [r7, #0x14]
	ldr r2, [r7, #4]
	adds r0, r2, #0
	adds r2, r1, #0
	adds r1, #0x64
	ldrh r2, [r1]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	orrs r0, r3
	adds r2, r0, #0
	strh r2, [r1]
	add sp, #0x18
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08067ADC: .4byte gUnk_0866559C
.L08067AE0: .4byte gUnk_082DBB24
.L08067AE4: .4byte 0x06010000
.L08067AE8: .4byte gUnk_082DBAC4
.L08067AEC: .4byte gUnk_086655AC

	thumb_func_start func_fe6_08067AF0
func_fe6_08067AF0: @ 0x08067AF0
	push {r7, lr}
	mov r7, sp
	ldr r1, .L08067B04 @ =gUnk_0866559C
	adds r0, r1, #0
	bl Proc_EndEach
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08067B04: .4byte gUnk_0866559C

	thumb_func_start func_fe6_08067B08
func_fe6_08067B08: @ 0x08067B08
	push {r4, r5, r6, r7, lr}
	sub sp, #0x2c
	add r7, sp, #8
	str r0, [r7]
	str r1, [r7, #4]
	str r2, [r7, #8]
	str r3, [r7, #0xc]
	ldr r0, .L08067B88 @ =gUnk_082DBDB0
	str r0, [r7, #0x20]
	ldr r1, .L08067B8C @ =gUnk_0866559C
	adds r0, r1, #0
	bl Proc_Find
	str r0, [r7, #0x1c]
	ldr r0, [r7, #0x1c]
	ldrh r1, [r0, #0x2a]
	str r1, [r7, #0x14]
	ldr r1, [r7, #0x1c]
	ldrh r0, [r1, #0x2a]
	ldr r2, [r7, #8]
	subs r1, r2, #1
	adds r2, r1, #0
	lsls r1, r2, #1
	adds r0, r0, r1
	str r0, [r7, #0x18]
	ldr r0, [r7, #8]
	cmp r0, #0
	bne .L08067B94
	ldr r0, .L08067B90 @ =gUnk_082A75FC
	ldr r2, [r7]
	adds r1, r2, #0
	subs r1, #0x12
	ldr r3, [r7, #4]
	subs r2, r3, #4
	ldr r3, [r7, #0x1c]
	ldrh r4, [r3, #0x2c]
	movs r5, #0xf
	adds r3, r4, #0
	ands r3, r5
	adds r5, r3, #0
	lsls r4, r5, #0x10
	lsrs r3, r4, #0x10
	adds r4, r3, #0
	lsls r3, r4, #0xc
	ldr r4, [r7, #0x14]
	adds r3, r3, r4
	ldr r4, [r7, #0x1c]
	ldrh r5, [r4, #0x2e]
	movs r6, #3
	adds r4, r5, #0
	ands r4, r6
	adds r6, r4, #0
	lsls r5, r6, #0x10
	lsrs r4, r5, #0x10
	adds r5, r4, #0
	lsls r4, r5, #0xa
	adds r3, r3, r4
	movs r4, #0
	str r4, [sp]
	movs r4, #2
	str r4, [sp, #4]
	bl StartSpriteAnimProc
	b .L08067CE8
	.align 2, 0
.L08067B88: .4byte gUnk_082DBDB0
.L08067B8C: .4byte gUnk_0866559C
.L08067B90: .4byte gUnk_082A75FC
.L08067B94:
	ldr r0, [r7, #0xc]
	cmp r0, #0
	ble .L08067BA0
	movs r0, #0
	str r0, [r7, #0x10]
	b .L08067BA4
.L08067BA0:
	movs r0, #1
	str r0, [r7, #0x10]
.L08067BA4:
	ldr r0, .L08067CF0 @ =gUnk_082A75FC
	ldr r2, [r7, #4]
	ldr r1, [r7, #0x1c]
	ldrh r3, [r1, #0x2c]
	ldr r4, [r7, #0x10]
	adds r1, r3, r4
	movs r3, #0xf
	ands r1, r3
	adds r3, r1, #0
	lsls r1, r3, #0xc
	ldr r3, [r7, #0x14]
	adds r1, r1, r3
	ldr r3, [r7, #0x1c]
	ldrh r4, [r3, #0x2e]
	movs r5, #3
	adds r3, r4, #0
	ands r3, r5
	adds r5, r3, #0
	lsls r4, r5, #0x10
	lsrs r3, r4, #0x10
	adds r4, r3, #0
	lsls r5, r4, #0xa
	adds r3, r1, r5
	ldr r1, [r7, #0x10]
	adds r4, r1, #1
	str r4, [sp]
	movs r1, #2
	str r1, [sp, #4]
	ldr r1, [r7]
	bl StartSpriteAnimProc
	ldr r0, .L08067CF0 @ =gUnk_082A75FC
	ldr r2, [r7]
	subs r1, r2, #3
	ldr r2, [r7, #4]
	ldr r3, [r7, #0x1c]
	ldrh r4, [r3, #0x2c]
	movs r5, #0xf
	adds r3, r4, #0
	ands r3, r5
	adds r5, r3, #0
	lsls r4, r5, #0x10
	lsrs r3, r4, #0x10
	adds r4, r3, #0
	lsls r3, r4, #0xc
	ldr r4, [r7, #0x18]
	adds r3, r3, r4
	ldr r4, [r7, #0x1c]
	ldrh r5, [r4, #0x2e]
	movs r6, #3
	adds r4, r5, #0
	ands r4, r6
	adds r6, r4, #0
	lsls r5, r6, #0x10
	lsrs r4, r5, #0x10
	adds r5, r4, #0
	lsls r4, r5, #0xa
	adds r3, r3, r4
	ldr r4, [r7, #0x10]
	adds r5, r4, #3
	str r5, [sp]
	movs r4, #2
	str r4, [sp, #4]
	bl StartSpriteAnimProc
	ldr r0, [r7, #0xc]
	cmp r0, #0
	ble .L08067C72
	ldr r0, .L08067CF0 @ =gUnk_082A75FC
	ldr r2, [r7]
	adds r1, r2, #0
	subs r1, #0x12
	ldr r3, [r7, #4]
	subs r2, r3, #4
	ldr r3, [r7, #0x1c]
	ldrh r4, [r3, #0x2c]
	movs r5, #0xf
	adds r3, r4, #0
	ands r3, r5
	adds r5, r3, #0
	lsls r4, r5, #0x10
	lsrs r3, r4, #0x10
	adds r4, r3, #0
	lsls r3, r4, #0xc
	ldr r4, [r7, #0x14]
	adds r3, r3, r4
	ldr r4, [r7, #0x1c]
	ldrh r5, [r4, #0x2e]
	movs r6, #3
	adds r4, r5, #0
	ands r4, r6
	adds r6, r4, #0
	lsls r5, r6, #0x10
	lsrs r4, r5, #0x10
	adds r5, r4, #0
	lsls r4, r5, #0xa
	adds r3, r3, r4
	movs r4, #0
	str r4, [sp]
	movs r4, #2
	str r4, [sp, #4]
	bl StartSpriteAnimProc
.L08067C72:
	ldr r0, [r7, #0xc]
	cmp r0, #0
	bge .L08067C96
	ldr r1, [r7, #0x20]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r1, r2
	ldr r2, [r7, #0x18]
	adds r1, r2, #0
	adds r1, #0x4c
	lsls r2, r1, #0x16
	lsrs r1, r2, #0x16
	lsls r2, r1, #5
	ldr r3, .L08067CF4 @ =0x06010000
	adds r1, r2, r3
	movs r2, #0x20
	bl func_fe6_08015260
.L08067C96:
	ldr r0, [r7, #0xc]
	cmp r0, #0
	bge .L08067C9E
	rsbs r0, r0, #0
.L08067C9E:
	lsls r1, r0, #0x16
	lsrs r0, r1, #0x16
	lsls r1, r0, #5
	ldr r2, [r7, #0x20]
	adds r0, r1, r2
	ldr r2, [r7, #0x18]
	adds r1, r2, #0
	adds r1, #0x2d
	lsls r2, r1, #0x16
	lsrs r1, r2, #0x16
	lsls r2, r1, #5
	ldr r3, .L08067CF4 @ =0x06010000
	adds r1, r2, r3
	movs r2, #0x20
	bl func_fe6_08015260
	ldr r0, [r7, #0xc]
	cmp r0, #0
	bge .L08067CC6
	rsbs r0, r0, #0
.L08067CC6:
	adds r0, #0x20
	lsls r1, r0, #0x16
	lsrs r0, r1, #0x16
	lsls r1, r0, #5
	ldr r2, [r7, #0x20]
	adds r0, r1, r2
	ldr r2, [r7, #0x18]
	adds r1, r2, #0
	adds r1, #0x4d
	lsls r2, r1, #0x16
	lsrs r1, r2, #0x16
	lsls r2, r1, #5
	ldr r3, .L08067CF4 @ =0x06010000
	adds r1, r2, r3
	movs r2, #0x20
	bl func_fe6_08015260
.L08067CE8:
	add sp, #0x2c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08067CF0: .4byte gUnk_082A75FC
.L08067CF4: .4byte 0x06010000

	thumb_func_start func_fe6_08067CF8
func_fe6_08067CF8: @ 0x08067CF8
	push {r7, lr}
	sub sp, #0xc
	mov r7, sp
	str r0, [r7]
	str r1, [r7, #4]
	ldr r0, .L08067D28 @ =gUnk_086655C4
	ldr r1, [r7, #4]
	bl SpawnProcLocking
	str r0, [r7, #8]
	ldr r0, [r7, #8]
	ldr r2, [r7]
	adds r1, r2, #0
	ldrh r2, [r0, #0x2e]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strh r2, [r0, #0x2e]
	add sp, #0xc
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08067D28: .4byte gUnk_086655C4

	thumb_func_start func_fe6_08067D2C
func_fe6_08067D2C: @ 0x08067D2C
	push {r7, lr}
	mov r7, sp
	ldr r0, .L08067E4C @ =gDispIo
	ldrb r1, [r0, #1]
	movs r2, #0x20
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0, #1]
	ldr r0, .L08067E4C @ =gDispIo
	ldrb r1, [r0, #1]
	movs r2, #0xbf
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0, #1]
	ldr r0, .L08067E4C @ =gDispIo
	ldrb r1, [r0, #1]
	movs r2, #0x7f
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0, #1]
	ldr r0, .L08067E4C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x2d
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08067E4C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x31
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08067E4C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0xf0
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08067E4C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x30
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x30
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08067E4C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r2, #0xfe
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08067E4C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r2, #0xfd
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08067E4C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r2, #4
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08067E4C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r2, #8
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08067E4C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r2, #0x10
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08067E4C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r2, #1
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08067E4C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r2, #2
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08067E4C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r2, #4
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08067E4C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r2, #8
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08067E4C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r2, #0x10
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08067E4C: .4byte gDispIo

	thumb_func_start func_fe6_08067E50
func_fe6_08067E50: @ 0x08067E50
	push {r7, lr}
	mov r7, sp
	ldr r0, .L08067E80 @ =gDispIo
	ldrb r1, [r0, #1]
	movs r2, #0xdf
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0, #1]
	ldr r0, .L08067E80 @ =gDispIo
	ldrb r1, [r0, #1]
	movs r2, #0xbf
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0, #1]
	ldr r0, .L08067E80 @ =gDispIo
	ldrb r1, [r0, #1]
	movs r2, #0x7f
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0, #1]
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08067E80: .4byte gDispIo

	thumb_func_start func_fe6_08067E84
func_fe6_08067E84: @ 0x08067E84
	push {r7, lr}
	sub sp, #0xc
	add r7, sp, #4
	str r0, [r7]
	bl ResetTextFont
	ldr r1, .L08067EB8 @ =gBg0Tm
	adds r0, r1, #0
	movs r1, #0
	bl TmFill
	ldr r0, [r7]
	movs r2, #0x2e
	ldrsh r1, [r0, r2]
	adds r0, r1, #0
	movs r1, #1
	movs r2, #1
	bl func_fe6_080675AC
	movs r0, #0
	str r0, [r7, #4]
.L08067EAE:
	ldr r0, [r7, #4]
	cmp r0, #8
	ble .L08067EBC
	b .L08067ED8
	.align 2, 0
.L08067EB8: .4byte gBg0Tm
.L08067EBC:
	ldr r1, [r7]
	movs r3, #0x2e
	ldrsh r0, [r1, r3]
	ldr r3, [r7, #4]
	movs r1, #0
	str r1, [sp]
	movs r1, #1
	movs r2, #1
	bl MALevelUp_DrawActorStat
	ldr r0, [r7, #4]
	adds r1, r0, #1
	str r1, [r7, #4]
	b .L08067EAE
.L08067ED8:
	movs r0, #1
	bl EnableBgSync
	ldr r0, [r7]
	adds r1, r0, #0
	adds r0, #0x30
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, [r7]
	adds r1, r0, #0
	adds r0, #0x31
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, [r7]
	ldrh r1, [r0, #0x32]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	ldr r3, .L08068038 @ =0x0000FF70
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strh r2, [r0, #0x32]
	ldr r0, .L0806803C @ =gDispIo
	ldrb r1, [r0, #0xc]
	movs r2, #0xfc
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0, #0xc]
	ldr r0, .L0806803C @ =gDispIo
	ldrb r1, [r0, #0x10]
	movs r2, #0xfc
	ands r1, r2
	adds r2, r1, #0
	movs r3, #1
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0, #0x10]
	ldr r0, .L0806803C @ =gDispIo
	ldrb r1, [r0, #0x14]
	movs r2, #0xfc
	ands r1, r2
	adds r2, r1, #0
	movs r3, #1
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0, #0x14]
	ldr r0, .L0806803C @ =gDispIo
	ldrb r1, [r0, #0x18]
	movs r2, #0xfc
	ands r1, r2
	adds r2, r1, #0
	movs r3, #2
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0, #0x18]
	ldr r0, .L0806803C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x3c
	ldrb r1, [r0]
	movs r2, #0x3f
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L0806803C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x44
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x10
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L0806803C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x45
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L0806803C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x46
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L0806803C @ =gDispIo
	ldrb r1, [r0, #1]
	movs r2, #0xdf
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0, #1]
	ldr r0, .L0806803C @ =gDispIo
	ldrb r1, [r0, #1]
	movs r2, #0xbf
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0, #1]
	ldr r0, .L0806803C @ =gDispIo
	ldrb r1, [r0, #1]
	movs r2, #0x7f
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0, #1]
	ldr r0, [r7]
	ldrh r2, [r0, #0x32]
	movs r0, #0
	movs r1, #0
	bl SetBgOffset
	ldr r0, [r7]
	ldrh r2, [r0, #0x32]
	movs r0, #1
	movs r1, #0
	bl SetBgOffset
	ldr r0, .L08068040 @ =gMapAnimSt
	ldr r2, [r7]
	movs r3, #0x2e
	ldrsh r1, [r2, r3]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, [r1]
	ldrh r1, [r0, #6]
	movs r0, #0x42
	str r0, [sp]
	movs r0, #0
	movs r2, #0xb8
	movs r3, #0x50
	bl StartFace
	ldr r1, .L08068044 @ =gFaces
	ldr r0, [r1]
	ldr r1, [r7]
	ldrh r2, [r1, #0x32]
	rsbs r1, r2, #0
	ldrh r2, [r0, #0x30]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strh r1, [r0, #0x30]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r1, #0
	movs r1, #3
	movs r2, #1
	ldr r3, [r7]
	bl func_fe6_08067A28
	add sp, #0xc
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08068038: .4byte 0x0000FF70
.L0806803C: .4byte gDispIo
.L08068040: .4byte gMapAnimSt
.L08068044: .4byte gFaces

	thumb_func_start func_fe6_08068048
func_fe6_08068048: @ 0x08068048
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, [r7]
	movs r1, #0
	str r1, [r0, #0x54]
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08068060
func_fe6_08068060: @ 0x08068060
	push {r7, lr}
	sub sp, #0xc
	mov r7, sp
	str r0, [r7]
	ldr r0, .L08068088 @ =gUnk_082DB6E8
	str r0, [r7, #8]
	ldr r1, [r7]
	ldr r0, [r7]
	ldr r1, [r7]
	ldr r2, [r1, #0x54]
	adds r1, r2, #1
	str r1, [r0, #0x54]
	ldr r0, [r7]
	ldr r1, [r0, #0x54]
	movs r2, #3
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq .L0806808C
	b .L080680E8
	.align 2, 0
.L08068088: .4byte gUnk_082DB6E8
.L0806808C:
	ldr r0, [r7]
	ldr r1, [r0, #0x54]
	asrs r0, r1, #2
	movs r1, #0xf
	ands r0, r1
	str r0, [r7, #4]
	ldr r0, [r7, #4]
	adds r1, r0, #0
	lsls r0, r1, #1
	ldr r1, [r7, #8]
	adds r0, r0, r1
	ldr r2, [r7]
	adds r1, r2, #0
	adds r2, #0x64
	movs r3, #0
	ldrsh r1, [r2, r3]
	adds r2, r1, #0
	adds r2, #0x10
	adds r1, r2, #0
	lsls r2, r1, #5
	adds r1, r2, #0
	adds r1, #0x12
	movs r2, #0xe
	bl ApplyPaletteExt
	ldr r0, [r7, #4]
	adds r1, r0, #0
	lsls r0, r1, #1
	ldr r2, [r7, #8]
	adds r1, r0, r2
	adds r0, r1, #0
	adds r0, #0x40
	ldr r2, [r7]
	adds r1, r2, #0
	adds r2, #0x64
	movs r3, #0
	ldrsh r1, [r2, r3]
	adds r2, r1, #0
	adds r2, #0x11
	adds r1, r2, #0
	lsls r2, r1, #5
	adds r1, r2, #0
	adds r1, #0x12
	movs r2, #0xe
	bl ApplyPaletteExt
.L080680E8:
	add sp, #0xc
	pop {r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080680F0
func_fe6_080680F0: @ 0x080680F0
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, [r7]
	ldr r1, [r7]
	ldrh r2, [r1, #0x32]
	adds r1, r2, #0
	adds r1, #8
	ldrh r2, [r0, #0x32]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strh r1, [r0, #0x32]
	ldr r0, [r7]
	ldrh r2, [r0, #0x32]
	movs r0, #0
	movs r1, #0
	bl SetBgOffset
	ldr r0, [r7]
	ldrh r2, [r0, #0x32]
	movs r0, #1
	movs r1, #0
	bl SetBgOffset
	ldr r1, .L08068160 @ =gFaces
	ldr r0, [r1]
	ldr r1, [r7]
	ldrh r2, [r1, #0x32]
	movs r3, #0x20
	subs r1, r3, r2
	ldrh r2, [r0, #0x30]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strh r1, [r0, #0x30]
	ldr r0, [r7]
	movs r2, #0x32
	ldrsh r1, [r0, r2]
	movs r0, #0x30
	cmn r1, r0
	blt .L08068158
	ldr r0, [r7]
	bl Proc_Break
.L08068158:
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08068160: .4byte gFaces

	thumb_func_start func_fe6_08068164
func_fe6_08068164: @ 0x08068164
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, [r7]
	ldr r1, [r7]
	ldrh r2, [r1, #0x32]
	adds r1, r2, #0
	subs r1, #8
	ldrh r2, [r0, #0x32]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strh r1, [r0, #0x32]
	ldr r0, [r7]
	ldrh r2, [r0, #0x32]
	movs r0, #0
	movs r1, #0
	bl SetBgOffset
	ldr r0, [r7]
	ldrh r2, [r0, #0x32]
	movs r0, #1
	movs r1, #0
	bl SetBgOffset
	ldr r1, .L080681D4 @ =gFaces
	ldr r0, [r1]
	ldr r1, [r7]
	ldrh r2, [r1, #0x32]
	movs r3, #0x20
	subs r1, r3, r2
	ldrh r2, [r0, #0x30]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strh r1, [r0, #0x30]
	ldr r0, [r7]
	movs r2, #0x32
	ldrsh r1, [r0, r2]
	movs r0, #0x90
	cmn r1, r0
	bgt .L080681CC
	ldr r0, [r7]
	bl Proc_Break
.L080681CC:
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080681D4: .4byte gFaces

	thumb_func_start func_fe6_080681D8
func_fe6_080681D8: @ 0x080681D8
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r7, sp, #4
	str r0, [r7]
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x31
	ldrb r0, [r1]
	cmp r0, #0
	beq .L08068214
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x31
	ldr r0, [r7]
	ldr r2, [r7]
	adds r1, r2, #0
	adds r2, #0x31
	ldrb r3, [r2]
	subs r1, r3, #1
	adds r2, r0, #0
	adds r0, #0x31
	ldrb r2, [r0]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strb r1, [r0]
	b .L08068308
.L08068214:
	ldr r1, [r7]
	adds r0, r1, #0
	adds r1, #0x30
	ldrb r0, [r1]
	str r0, [r7, #4]
.L0806821E:
	ldr r0, [r7, #4]
	cmp r0, #8
	ble .L08068226
	b .L08068244
.L08068226:
	ldr r0, [r7]
	movs r2, #0x2e
	ldrsh r1, [r0, r2]
	ldr r2, [r7, #4]
	adds r0, r1, #0
	adds r1, r2, #0
	bl MALevelUp_GetActorStatUp
	cmp r0, #0
	beq .L0806823C
	b .L08068244
.L0806823C:
	ldr r0, [r7, #4]
	adds r1, r0, #1
	str r1, [r7, #4]
	b .L0806821E
.L08068244:
	ldr r0, [r7, #4]
	cmp r0, #8
	ble .L08068252
	ldr r0, [r7]
	bl Proc_Break
	b .L08068308
.L08068252:
	ldr r1, [r7]
	movs r3, #0x2e
	ldrsh r0, [r1, r3]
	ldr r3, [r7, #4]
	movs r1, #1
	str r1, [sp]
	movs r1, #1
	movs r2, #1
	bl MALevelUp_DrawActorStat
	movs r0, #1
	bl EnableBgSync
	ldr r0, .L08068310 @ =gUnk_08665524
	ldr r1, [r7, #4]
	adds r3, r1, #0
	lsls r2, r3, #1
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	adds r0, r1, #0
	lsls r1, r0, #3
	adds r4, r1, #0
	adds r4, #0x3e
	ldr r0, .L08068310 @ =gUnk_08665524
	ldr r1, [r7, #4]
	adds r3, r1, #0
	lsls r2, r3, #1
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldrb r1, [r0, #1]
	adds r2, r1, #0
	lsls r0, r2, #3
	ldr r1, [r7]
	movs r3, #0x32
	ldrsh r2, [r1, r3]
	adds r1, r2, #0
	subs r1, #0x17
	subs r5, r0, r1
	ldr r6, [r7, #4]
	ldr r0, [r7]
	movs r2, #0x2e
	ldrsh r1, [r0, r2]
	ldr r2, [r7, #4]
	adds r0, r1, #0
	adds r1, r2, #0
	bl MALevelUp_GetActorStatUp
	adds r3, r0, #0
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl func_fe6_08067B08
	ldr r0, .L08068314 @ =gPlaySt
	ldrb r1, [r0, #0x1d]
	lsls r2, r1, #0x1e
	lsrs r0, r2, #0x1f
	cmp r0, #0
	bne .L080682D4
	movs r0, #0x76
	bl m4aSongNumStart
.L080682D4:
	ldr r0, [r7]
	ldr r1, [r7, #4]
	adds r2, r1, #0
	adds r1, r2, #1
	adds r2, r0, #0
	adds r0, #0x30
	ldrb r2, [r0]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strb r1, [r0]
	ldr r0, [r7]
	adds r1, r0, #0
	adds r0, #0x31
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x14
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
.L08068308:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08068310: .4byte gUnk_08665524
.L08068314: .4byte gPlaySt

	thumb_func_start func_fe6_08068318
func_fe6_08068318: @ 0x08068318
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r1, #0
	movs r1, #0x80
	movs r2, #0x10
	ldr r3, [r7]
	bl StartBgmVolumeChange
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08068338
func_fe6_08068338: @ 0x08068338
	push {r4, r7, lr}
	sub sp, #0x14
	add r7, sp, #8
	str r0, [r7]
	ldr r0, .L08068488 @ =gUnk_082DB8B0
	ldr r1, .L0806848C @ =0x06013800
	bl Decompress
	ldr r0, .L08068490 @ =gUnk_082DBAC4
	movs r1, #0x98
	lsls r1, r1, #2
	movs r2, #0x60
	bl ApplyPaletteExt
	ldr r0, .L08068494 @ =gMapAnimSt
	ldr r2, [r7]
	movs r3, #0x2e
	ldrsh r1, [r2, r3]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0xe
	ldrsb r0, [r1, r0]
	ldr r1, .L08068498 @ =gBmSt
	movs r3, #0xc
	ldrsh r2, [r1, r3]
	asrs r1, r2, #4
	adds r3, r1, #0
	lsls r2, r3, #0x10
	asrs r1, r2, #0x10
	subs r0, r0, r1
	lsls r1, r0, #1
	adds r0, r1, #0
	lsls r1, r0, #3
	adds r0, r1, #0
	adds r0, #0x10
	str r0, [r7, #4]
	ldr r0, .L08068494 @ =gMapAnimSt
	ldr r2, [r7]
	movs r3, #0x2e
	ldrsh r1, [r2, r3]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0xf
	ldrsb r0, [r1, r0]
	ldr r1, .L08068498 @ =gBmSt
	movs r3, #0xe
	ldrsh r2, [r1, r3]
	asrs r1, r2, #4
	adds r3, r1, #0
	lsls r2, r3, #0x10
	asrs r1, r2, #0x10
	subs r0, r0, r1
	lsls r1, r0, #1
	adds r0, r1, #0
	lsls r1, r0, #3
	adds r0, r1, #0
	subs r0, #8
	str r0, [r7, #8]
	ldr r0, .L08068494 @ =gMapAnimSt
	ldr r2, [r7]
	movs r3, #0x2e
	ldrsh r1, [r2, r3]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0xf
	ldrsb r0, [r1, r0]
	ldr r1, .L08068498 @ =gBmSt
	movs r3, #0xe
	ldrsh r2, [r1, r3]
	asrs r1, r2, #4
	adds r3, r1, #0
	lsls r2, r3, #0x10
	asrs r1, r2, #0x10
	subs r0, r0, r1
	lsls r1, r0, #1
	cmp r1, #3
	bgt .L080683F2
	ldr r0, [r7, #8]
	adds r1, r0, #0
	adds r1, #0x20
	str r1, [r7, #8]
.L080683F2:
	ldr r0, .L08068494 @ =gMapAnimSt
	ldr r2, [r7]
	movs r3, #0x2e
	ldrsh r1, [r2, r3]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0xe
	ldrsb r0, [r1, r0]
	ldr r1, .L08068498 @ =gBmSt
	movs r3, #0xc
	ldrsh r2, [r1, r3]
	asrs r1, r2, #4
	adds r3, r1, #0
	lsls r2, r3, #0x10
	asrs r1, r2, #0x10
	subs r0, r0, r1
	lsls r1, r0, #1
	cmp r1, #3
	bgt .L08068424
	movs r0, #0x30
	str r0, [r7, #4]
.L08068424:
	ldr r0, .L08068494 @ =gMapAnimSt
	ldr r2, [r7]
	movs r3, #0x2e
	ldrsh r1, [r2, r3]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0xe
	ldrsb r0, [r1, r0]
	ldr r1, .L08068498 @ =gBmSt
	movs r3, #0xc
	ldrsh r2, [r1, r3]
	asrs r1, r2, #4
	adds r3, r1, #0
	lsls r2, r3, #0x10
	asrs r1, r2, #0x10
	subs r0, r0, r1
	lsls r1, r0, #1
	cmp r1, #0x19
	ble .L08068456
	movs r0, #0xd0
	str r0, [r7, #4]
.L08068456:
	ldr r0, .L0806849C @ =gUnk_082A7CBC
	ldr r1, [r7, #4]
	ldr r2, [r7, #8]
	movs r3, #0xc7
	lsls r3, r3, #6
	movs r4, #0
	str r4, [sp]
	movs r4, #2
	str r4, [sp, #4]
	bl StartSpriteAnimProc
	ldr r0, .L080684A0 @ =gPlaySt
	ldrb r1, [r0, #0x1d]
	lsls r2, r1, #0x1e
	lsrs r0, r2, #0x1f
	cmp r0, #0
	bne .L0806847E
	movs r0, #0x5b
	bl m4aSongNumStart
.L0806847E:
	add sp, #0x14
	pop {r4, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08068488: .4byte gUnk_082DB8B0
.L0806848C: .4byte 0x06013800
.L08068490: .4byte gUnk_082DBAC4
.L08068494: .4byte gMapAnimSt
.L08068498: .4byte gBmSt
.L0806849C: .4byte gUnk_082A7CBC
.L080684A0: .4byte gPlaySt

	thumb_func_start func_fe6_080684A4
func_fe6_080684A4: @ 0x080684A4
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	bl EndEachSpriteAnimProc
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080684B8
func_fe6_080684B8: @ 0x080684B8
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x80
	movs r2, #0x10
	ldr r3, [r7]
	bl StartBgmVolumeChange
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080684D8
func_fe6_080684D8: @ 0x080684D8
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	bl ClearTalk
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080684EC
func_fe6_080684EC: @ 0x080684EC
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, [r7]
	cmp r0, #0
	beq .L0806850C
	ldr r1, .L08068508 @ =gUnk_08665684
	adds r0, r1, #0
	ldr r1, [r7]
	bl SpawnProcLocking
	b .L08068516
	.align 2, 0
.L08068508: .4byte gUnk_08665684
.L0806850C:
	ldr r1, .L08068520 @ =gUnk_08665684
	adds r0, r1, #0
	movs r1, #3
	bl SpawnProc
.L08068516:
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08068520: .4byte gUnk_08665684

	thumb_func_start func_fe6_08068524
func_fe6_08068524: @ 0x08068524
	push {r7, lr}
	sub sp, #8
	mov r7, sp
	str r0, [r7]
	ldr r0, .L08068544 @ =gPal+0xC0
	ldr r1, .L08068548 @ =gUnk_03004750
	movs r2, #0x50
	bl CpuFastSet
	movs r0, #0
	str r0, [r7, #4]
.L0806853A:
	ldr r0, [r7, #4]
	cmp r0, #9
	ble .L0806854C
	b .L08068570
	.align 2, 0
.L08068544: .4byte gPal+0xC0
.L08068548: .4byte gUnk_03004750
.L0806854C:
	ldr r0, .L0806856C @ =Pal_AllBlack
	ldr r2, [r7, #4]
	adds r1, r2, #6
	movs r2, #0x3c
	ldr r3, [r7]
	bl StartPalFade
	adds r1, r0, #0
	adds r0, r1, #0
	movs r1, #0xf
	bl SetPalFadeStop
	ldr r0, [r7, #4]
	adds r1, r0, #1
	str r1, [r7, #4]
	b .L0806853A
	.align 2, 0
.L0806856C: .4byte Pal_AllBlack
.L08068570:
	add sp, #8
	pop {r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08068578
func_fe6_08068578: @ 0x08068578
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, [r7]
	cmp r0, #0
	beq .L08068598
	ldr r1, .L08068594 @ =gUnk_0866569C
	adds r0, r1, #0
	ldr r1, [r7]
	bl SpawnProcLocking
	b .L080685A2
	.align 2, 0
.L08068594: .4byte gUnk_0866569C
.L08068598:
	ldr r1, .L080685AC @ =gUnk_0866569C
	adds r0, r1, #0
	movs r1, #3
	bl SpawnProc
.L080685A2:
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080685AC: .4byte gUnk_0866569C

	thumb_func_start func_fe6_080685B0
func_fe6_080685B0: @ 0x080685B0
	push {r7, lr}
	sub sp, #8
	mov r7, sp
	str r0, [r7]
	movs r0, #0
	str r0, [r7, #4]
.L080685BC:
	ldr r0, [r7, #4]
	cmp r0, #9
	ble .L080685C4
	b .L080685E8
.L080685C4:
	ldr r0, [r7, #4]
	adds r1, r0, #0
	lsls r0, r1, #5
	ldr r1, .L080685E4 @ =gUnk_03004750
	adds r0, r0, r1
	ldr r2, [r7, #4]
	adds r1, r2, #6
	movs r2, #0xf
	ldr r3, [r7]
	bl StartPalFade
	ldr r0, [r7, #4]
	adds r1, r0, #1
	str r1, [r7, #4]
	b .L080685BC
	.align 2, 0
.L080685E4: .4byte gUnk_03004750
.L080685E8:
	add sp, #8
	pop {r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080685F0
func_fe6_080685F0: @ 0x080685F0
	push {r7, lr}
	mov r7, sp
	ldr r1, .L08068604 @ =gUnk_086656B4
	adds r0, r1, #0
	movs r1, #3
	bl SpawnProc
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08068604: .4byte gUnk_086656B4

	thumb_func_start func_fe6_08068608
func_fe6_08068608: @ 0x08068608
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, [r7]
	adds r1, r0, #0
	adds r0, #0x64
	ldrh r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strh r2, [r0]
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08068628
func_fe6_08068628: @ 0x08068628
	push {r4, r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	bl RandNextB
	adds r1, r0, #0
	adds r0, r1, #0
	movs r1, #9
	bl DivRem
	adds r1, r0, #0
	subs r0, r1, #4
	adds r1, r0, #0
	lsls r0, r1, #0x10
	lsrs r4, r0, #0x10
	bl RandNextB
	adds r1, r0, #0
	adds r0, r1, #0
	movs r1, #9
	bl DivRem
	adds r1, r0, #0
	subs r0, r1, #4
	adds r1, r0, #0
	lsls r0, r1, #0x10
	lsrs r2, r0, #0x10
	movs r0, #0
	adds r1, r4, #0
	bl SetBgOffset
	bl RandNextB
	adds r1, r0, #0
	adds r0, r1, #0
	movs r1, #9
	bl DivRem
	adds r1, r0, #0
	subs r0, r1, #4
	adds r1, r0, #0
	lsls r0, r1, #0x10
	lsrs r4, r0, #0x10
	bl RandNextB
	adds r1, r0, #0
	adds r0, r1, #0
	movs r1, #9
	bl DivRem
	adds r1, r0, #0
	subs r0, r1, #4
	adds r1, r0, #0
	lsls r0, r1, #0x10
	lsrs r2, r0, #0x10
	movs r0, #1
	adds r1, r4, #0
	bl SetBgOffset
	ldr r0, [r7]
	adds r1, r0, #0
	adds r0, #0x64
	ldrh r1, [r0]
	adds r2, r1, #1
	adds r3, r2, #0
	strh r3, [r0]
	lsls r1, r1, #0x10
	asrs r0, r1, #0x10
	cmp r0, #0xf
	ble .L080686D0
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	ldr r0, [r7]
	bl Proc_Break
.L080686D0:
	add sp, #4
	pop {r4, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080686D8
func_fe6_080686D8: @ 0x080686D8
	push {r7, lr}
	mov r7, sp
	ldr r0, .L080686F8 @ =gUnk_082DD7E8
	ldr r1, .L080686FC @ =0x06013800
	bl Decompress
	ldr r0, .L08068700 @ =gUnk_082DD808
	movs r1, #0xa0
	lsls r1, r1, #2
	movs r2, #0x20
	bl ApplyPaletteExt
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080686F8: .4byte gUnk_082DD7E8
.L080686FC: .4byte 0x06013800
.L08068700: .4byte gUnk_082DD808

	thumb_func_start func_fe6_08068704
func_fe6_08068704: @ 0x08068704
	push {r7, lr}
	sub sp, #8
	mov r7, sp
	str r0, [r7]
	str r1, [r7, #4]
	ldr r0, [r7]
	movs r1, #4
	cmn r0, r1
	bge .L08068718
	b .L0806874A
.L08068718:
	ldr r0, [r7]
	cmp r0, #0xeb
	ble .L08068720
	b .L0806874A
.L08068720:
	ldr r0, [r7, #4]
	movs r1, #4
	cmn r0, r1
	bge .L0806872A
	b .L0806874A
.L0806872A:
	ldr r0, [r7, #4]
	cmp r0, #0x9b
	ble .L08068732
	b .L0806874A
.L08068732:
	ldr r1, [r7]
	subs r0, r1, #4
	lsls r1, r0, #0x17
	lsrs r0, r1, #0x17
	ldr r2, [r7, #4]
	subs r1, r2, #4
	movs r2, #0xff
	ands r1, r2
	ldr r2, .L08068754 @ =Sprite_8x8
	ldr r3, .L08068758 @ =0x000041C0
	bl PutOamHiRam
.L0806874A:
	add sp, #8
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08068754: .4byte Sprite_8x8
.L08068758: .4byte 0x000041C0

	thumb_func_start func_fe6_0806875C
func_fe6_0806875C: @ 0x0806875C
	push {r7, lr}
	sub sp, #0x10
	mov r7, sp
	str r0, [r7]
	str r1, [r7, #4]
	str r2, [r7, #8]
	str r3, [r7, #0xc]
	ldr r0, .L080687B8 @ =gSinLut
	ldr r1, [r7, #0xc]
	movs r2, #0xff
	ands r1, r2
	adds r2, r1, #0
	lsls r1, r2, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, [r7, #8]
	adds r0, r1, #0
	muls r0, r2, r0
	asrs r1, r0, #0xc
	ldr r2, [r7]
	adds r0, r1, r2
	ldr r1, .L080687B8 @ =gSinLut
	ldr r2, [r7, #0xc]
	movs r3, #0xff
	ands r2, r3
	adds r3, r2, #0
	adds r3, #0x40
	adds r2, r3, #0
	lsls r3, r2, #1
	adds r1, r1, r3
	movs r3, #0
	ldrsh r2, [r1, r3]
	ldr r3, [r7, #8]
	adds r1, r2, #0
	muls r1, r3, r1
	asrs r2, r1, #0xc
	ldr r3, [r7, #4]
	adds r1, r2, r3
	bl func_fe6_08068704
	add sp, #0x10
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080687B8: .4byte gSinLut

	thumb_func_start func_fe6_080687BC
func_fe6_080687BC: @ 0x080687BC
	push {r7, lr}
	sub sp, #8
	mov r7, sp
	str r0, [r7]
	bl func_fe6_080686D8
	movs r0, #0
	str r0, [r7, #4]
.L080687CC:
	ldr r0, [r7, #4]
	cmp r0, #0xf
	ble .L080687D4
	b .L08068820
.L080687D4:
	ldr r0, .L0806881C @ =gUnk_030046D0
	ldr r1, [r7, #4]
	adds r2, r1, #0
	lsls r1, r2, #3
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x10
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strh r2, [r0]
	ldr r0, .L0806881C @ =gUnk_030046D0
	ldr r1, [r7, #4]
	adds r2, r1, #0
	lsls r1, r2, #3
	adds r0, r0, r1
	ldr r1, [r7, #4]
	adds r2, r1, #0
	lsls r1, r2, #4
	adds r2, r1, #0
	lsls r1, r2, #4
	ldrh r2, [r0, #2]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strh r1, [r0, #2]
	ldr r0, [r7, #4]
	adds r1, r0, #1
	str r1, [r7, #4]
	b .L080687CC
	.align 2, 0
.L0806881C: .4byte gUnk_030046D0
.L08068820:
	ldr r0, [r7]
	ldrh r1, [r0, #0x36]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strh r2, [r0, #0x36]
	ldr r0, [r7]
	ldrh r1, [r0, #0x38]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strh r2, [r0, #0x38]
	ldr r0, [r7]
	ldr r1, [r7]
	ldrh r2, [r0, #0x3a]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	ldrh r1, [r1, #0x3c]
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strh r1, [r0, #0x3a]
	add sp, #8
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08068858
func_fe6_08068858: @ 0x08068858
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r7, sp, #4
	str r0, [r7]
	ldr r0, [r7]
	movs r2, #0x2e
	ldrsh r1, [r0, r2]
	ldr r0, [r7]
	movs r3, #0x30
	ldrsh r2, [r0, r3]
	ldr r0, [r7]
	ldrh r3, [r0, #0x3a]
	ldr r0, [r7]
	ldrh r4, [r0, #0x3e]
	str r4, [sp]
	movs r0, #5
	bl Interpolate
	lsls r1, r0, #4
	str r1, [r7, #8]
	ldr r0, [r7]
	ldr r2, [r7, #8]
	adds r1, r2, #0
	ldrh r2, [r0, #0x36]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strh r2, [r0, #0x36]
	ldr r0, [r7]
	ldr r1, [r7, #8]
	asrs r2, r1, #0x1f
	lsrs r3, r2, #0x1f
	adds r2, r1, r3
	asrs r1, r2, #1
	ldrh r2, [r0, #0x38]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strh r1, [r0, #0x38]
	movs r0, #0
	str r0, [r7, #4]
.L080688B4:
	ldr r0, [r7, #4]
	cmp r0, #0xf
	ble .L080688BC
	b .L08068900
.L080688BC:
	ldr r1, [r7]
	movs r2, #0x2a
	ldrsh r0, [r1, r2]
	ldr r2, [r7]
	movs r3, #0x2c
	ldrsh r1, [r2, r3]
	ldr r3, [r7]
	ldrh r2, [r3, #0x36]
	ldr r3, .L080688FC @ =gUnk_030046D0
	ldr r4, [r7, #4]
	adds r5, r4, #0
	lsls r4, r5, #3
	adds r3, r3, r4
	ldrh r4, [r3]
	adds r3, r2, r4
	asrs r2, r3, #4
	ldr r4, [r7]
	ldrh r3, [r4, #0x38]
	ldr r4, .L080688FC @ =gUnk_030046D0
	ldr r5, [r7, #4]
	adds r6, r5, #0
	lsls r5, r6, #3
	adds r4, r4, r5
	ldrh r5, [r4, #2]
	adds r4, r3, r5
	asrs r3, r4, #4
	bl func_fe6_0806875C
	ldr r0, [r7, #4]
	adds r1, r0, #1
	str r1, [r7, #4]
	b .L080688B4
	.align 2, 0
.L080688FC: .4byte gUnk_030046D0
.L08068900:
	ldr r1, [r7]
	ldr r0, [r7]
	ldr r1, [r7]
	ldrh r2, [r1, #0x3a]
	adds r1, r2, #1
	ldrh r2, [r0, #0x3a]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strh r1, [r0, #0x3a]
	ldr r0, [r7]
	ldr r2, [r7]
	adds r1, r2, #0
	adds r2, #0x40
	ldrh r0, [r0, #0x3a]
	ldrh r1, [r2]
	cmp r0, r1
	bls .L08068930
	ldr r0, [r7]
	bl Proc_Break
.L08068930:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08068938
func_fe6_08068938: @ 0x08068938
	push {r7, lr}
	sub sp, #0x14
	mov r7, sp
	str r0, [r7]
	str r1, [r7, #4]
	str r2, [r7, #8]
	str r3, [r7, #0xc]
	ldr r1, .L080689EC @ =gUnk_086656CC
	adds r0, r1, #0
	movs r1, #3
	bl SpawnProc
	str r0, [r7, #0x10]
	ldr r0, [r7, #0x10]
	ldr r2, [r7]
	adds r1, r2, #0
	ldrh r2, [r0, #0x2a]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strh r2, [r0, #0x2a]
	ldr r0, [r7, #0x10]
	ldr r2, [r7, #4]
	adds r1, r2, #0
	ldrh r2, [r0, #0x2c]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strh r2, [r0, #0x2c]
	ldr r0, [r7, #0x10]
	ldr r2, [r7, #8]
	adds r1, r2, #0
	ldrh r2, [r0, #0x2e]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strh r2, [r0, #0x2e]
	ldr r0, [r7, #0x10]
	ldr r2, [r7, #0xc]
	adds r1, r2, #0
	ldrh r2, [r0, #0x30]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strh r2, [r0, #0x30]
	ldr r0, [r7, #0x10]
	ldr r2, [r7, #0x1c]
	adds r1, r2, #0
	ldrh r2, [r0, #0x3c]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strh r2, [r0, #0x3c]
	ldr r0, [r7, #0x10]
	ldr r2, [r7, #0x20]
	adds r1, r2, #0
	ldrh r2, [r0, #0x3e]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strh r2, [r0, #0x3e]
	ldr r1, [r7, #0x10]
	ldr r2, [r7, #0x24]
	adds r0, r2, #0
	adds r2, r1, #0
	adds r1, #0x40
	ldrh r2, [r1]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	orrs r0, r3
	adds r2, r0, #0
	strh r2, [r1]
	add sp, #0x14
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080689EC: .4byte gUnk_086656CC

	thumb_func_start func_fe6_080689F0
func_fe6_080689F0: @ 0x080689F0
	push {r7, lr}
	sub sp, #0x14
	add r7, sp, #0xc
	str r0, [r7]
	str r1, [r7, #4]
	ldr r1, [r7, #4]
	movs r0, #0
	str r0, [sp]
	movs r0, #0x50
	str r0, [sp, #4]
	movs r0, #0x28
	str r0, [sp, #8]
	ldr r0, [r7]
	movs r2, #1
	movs r3, #0xc8
	bl func_fe6_08068938
	add sp, #0x14
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08068A1C
func_fe6_08068A1C: @ 0x08068A1C
	push {r7, lr}
	sub sp, #0x14
	add r7, sp, #0xc
	str r0, [r7]
	str r1, [r7, #4]
	ldr r1, [r7, #4]
	movs r0, #0
	str r0, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	movs r0, #0x37
	str r0, [sp, #8]
	ldr r0, [r7]
	movs r2, #0xc8
	movs r3, #1
	bl func_fe6_08068938
	add sp, #0x14
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08068A48
func_fe6_08068A48: @ 0x08068A48
	push {r7, lr}
	mov r7, sp
	ldr r0, .L08068A58 @ =gMapAnimSt
	ldr r1, [r0, #0x54]
	cmp r1, #0
	bne .L08068A60
	ldr r0, .L08068A5C @ =gUnk_086656FC
	b .L08068A6C
	.align 2, 0
.L08068A58: .4byte gMapAnimSt
.L08068A5C: .4byte gUnk_086656FC
.L08068A60:
	ldr r0, .L08068A68 @ =gMapAnimSt
	ldr r1, [r0, #0x54]
	adds r0, r1, #0
	b .L08068A6C
	.align 2, 0
.L08068A68: .4byte gMapAnimSt
.L08068A6C:
	pop {r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08068A74
func_fe6_08068A74: @ 0x08068A74
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L08068AA4 @ =gMapAnimSt
	ldr r2, .L08068AA4 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x58
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #8
	adds r1, r0, r1
	ldr r2, [r1]
	adds r0, r2, #0
	bl StartMuActionAnim
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08068AA4: .4byte gMapAnimSt

	thumb_func_start func_fe6_08068AA8
func_fe6_08068AA8: @ 0x08068AA8
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L08068AD8 @ =gMapAnimSt
	ldr r2, .L08068AD8 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x58
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #8
	adds r1, r0, r1
	ldr r2, [r1]
	adds r0, r2, #0
	bl StartMuDelayedFaceTarget
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08068AD8: .4byte gMapAnimSt

	thumb_func_start func_fe6_08068ADC
func_fe6_08068ADC: @ 0x08068ADC
	push {r7, lr}
	sub sp, #8
	mov r7, sp
	str r0, [r7]
	ldr r0, .L08068B10 @ =gMapAnimSt
	ldr r2, .L08068B10 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x58
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, [r1, #4]
	ldrb r1, [r0, #4]
	cmp r1, #0x37
	bne .L08068B18
	ldr r1, .L08068B14 @ =func_fe6_08068BA8
	adds r0, r1, #0
	movs r1, #9
	bl CallDelayed
	b .L08068B22
	.align 2, 0
.L08068B10: .4byte gMapAnimSt
.L08068B14: .4byte func_fe6_08068BA8
.L08068B18:
	ldr r1, .L08068BA0 @ =func_fe6_08068BE8
	adds r0, r1, #0
	movs r1, #0xc
	bl CallDelayed
.L08068B22:
	ldr r0, .L08068BA4 @ =gMapAnimSt
	ldr r2, .L08068BA4 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x58
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #8
	adds r1, r0, r1
	ldr r2, [r1]
	ldr r0, [r2, #0x30]
	ldrh r1, [r0, #0x18]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strh r2, [r0, #0x18]
	ldr r0, .L08068BA4 @ =gMapAnimSt
	ldr r2, .L08068BA4 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x58
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #8
	adds r1, r0, r1
	ldr r2, [r1]
	ldr r0, [r2, #0x30]
	ldrh r1, [r0, #0x1a]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strh r2, [r0, #0x1a]
	ldr r0, .L08068BA4 @ =gMapAnimSt
	ldr r2, .L08068BA4 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x58
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #8
	adds r1, r0, r1
	ldr r0, [r1]
	ldr r1, [r0, #0x30]
	adds r0, r1, #0
	movs r1, #5
	bl SetSpriteAnimId
	add sp, #8
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08068BA0: .4byte func_fe6_08068BE8
.L08068BA4: .4byte gMapAnimSt

	thumb_func_start func_fe6_08068BA8
func_fe6_08068BA8: @ 0x08068BA8
	push {r7, lr}
	mov r7, sp
	ldr r0, .L08068BE0 @ =gMapAnimSt
	ldr r2, .L08068BE0 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x58
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0xe
	ldrsb r0, [r1, r0]
	adds r1, r0, #0
	lsls r0, r1, #4
	ldr r1, .L08068BE4 @ =gBmSt
	movs r3, #0xc
	ldrsh r2, [r1, r3]
	subs r1, r0, r2
	movs r0, #0xa8
	bl PlaySeSpacial
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08068BE0: .4byte gMapAnimSt
.L08068BE4: .4byte gBmSt

	thumb_func_start func_fe6_08068BE8
func_fe6_08068BE8: @ 0x08068BE8
	push {r7, lr}
	mov r7, sp
	ldr r0, .L08068C20 @ =gMapAnimSt
	ldr r2, .L08068C20 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x58
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0xe
	ldrsb r0, [r1, r0]
	adds r1, r0, #0
	lsls r0, r1, #4
	ldr r1, .L08068C24 @ =gBmSt
	movs r3, #0xc
	ldrsh r2, [r1, r3]
	subs r1, r0, r2
	movs r0, #0xa9
	bl PlaySeSpacial
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08068C20: .4byte gMapAnimSt
.L08068C24: .4byte gBmSt

	thumb_func_start func_fe6_08068C28
func_fe6_08068C28: @ 0x08068C28
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L08068C80 @ =gMapAnimSt
	ldr r2, .L08068C80 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x58
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #8
	adds r1, r0, r1
	ldr r2, [r1]
	ldr r0, [r2, #0x30]
	ldrh r1, [r0, #0x18]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strh r2, [r0, #0x18]
	ldr r0, .L08068C80 @ =gMapAnimSt
	ldr r2, .L08068C80 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x58
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #8
	adds r1, r0, r1
	ldr r2, [r1]
	ldr r0, [r2, #0x30]
	ldrh r1, [r0, #0x1a]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strh r2, [r0, #0x1a]
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08068C80: .4byte gMapAnimSt

	thumb_func_start func_fe6_08068C84
func_fe6_08068C84: @ 0x08068C84
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L08068CB4 @ =gMapAnimSt
	ldr r2, .L08068CB4 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x58
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #8
	adds r1, r0, r1
	ldr r2, [r1]
	adds r0, r2, #0
	bl StartMuSlowDownAnim
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08068CB4: .4byte gMapAnimSt

	thumb_func_start func_fe6_08068CB8
func_fe6_08068CB8: @ 0x08068CB8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	mov r7, sp
	str r0, [r7]
	str r1, [r7, #4]
	ldr r2, [r7]
	ldr r4, [r7]
	adds r3, r4, #0
	adds r4, #0x44
	movs r3, #0
	ldrsh r0, [r4, r3]
	ldr r4, [r7, #4]
	adds r3, r4, #0
	adds r4, #0x44
	movs r5, #0
	ldrsh r3, [r4, r5]
	ldr r5, [r7]
	adds r4, r5, #0
	adds r5, #0x44
	movs r6, #0
	ldrsh r4, [r5, r6]
	subs r3, r3, r4
	cmp r3, #0
	bgt .L08068D12
	adds r3, r0, #0
	ldr r5, [r7, #4]
	adds r4, r5, #0
	adds r5, #0x44
	movs r6, #0
	ldrsh r4, [r5, r6]
	ldr r6, [r7]
	adds r5, r6, #0
	adds r5, r6, #0
	adds r5, #0x44
	str r5, [r7, #8]
	ldr r6, [r7, #8]
	movs r5, #0
	ldrsh r6, [r6, r5]
	str r6, [r7, #0xc]
	ldr r6, [r7, #0xc]
	subs r4, r4, r6
	cmp r4, #0
	bge .L08068D10
	subs r3, #0x10
.L08068D10:
	b .L08068D18
.L08068D12:
	adds r4, r0, #0
	adds r4, #0x10
	adds r3, r4, #0
.L08068D18:
	adds r4, r2, #0
	adds r2, #0x44
	ldrh r4, [r2]
	movs r5, #0
	ands r4, r5
	adds r5, r4, #0
	orrs r3, r5
	adds r4, r3, #0
	strh r4, [r2]
	ldr r2, [r7]
	ldr r4, [r7]
	adds r3, r4, #0
	adds r4, #0x46
	movs r3, #0
	ldrsh r1, [r4, r3]
	ldr r4, [r7, #4]
	adds r3, r4, #0
	adds r4, #0x46
	movs r5, #0
	ldrsh r3, [r4, r5]
	ldr r5, [r7]
	adds r4, r5, #0
	adds r5, #0x46
	movs r6, #0
	ldrsh r4, [r5, r6]
	subs r3, r3, r4
	cmp r3, #0
	bgt .L08068D7A
	adds r3, r1, #0
	ldr r5, [r7, #4]
	adds r4, r5, #0
	adds r5, #0x46
	movs r6, #0
	ldrsh r4, [r5, r6]
	ldr r6, [r7]
	adds r5, r6, #0
	adds r5, r6, #0
	adds r5, #0x46
	str r5, [r7, #8]
	ldr r6, [r7, #8]
	movs r5, #0
	ldrsh r6, [r6, r5]
	str r6, [r7, #0xc]
	ldr r6, [r7, #0xc]
	subs r4, r4, r6
	cmp r4, #0
	bge .L08068D78
	subs r3, #0x10
.L08068D78:
	b .L08068D80
.L08068D7A:
	adds r4, r1, #0
	adds r4, #0x10
	adds r3, r4, #0
.L08068D80:
	adds r4, r2, #0
	adds r2, #0x46
	ldrh r4, [r2]
	movs r5, #0
	ands r4, r5
	adds r5, r4, #0
	orrs r3, r5
	adds r4, r3, #0
	strh r4, [r2]
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08068D9C
func_fe6_08068D9C: @ 0x08068D9C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	mov r7, sp
	str r0, [r7]
	str r1, [r7, #4]
	ldr r2, [r7]
	ldr r4, [r7]
	adds r3, r4, #0
	adds r4, #0x44
	movs r3, #0
	ldrsh r0, [r4, r3]
	ldr r4, [r7]
	adds r3, r4, #0
	adds r4, #0x44
	movs r5, #0
	ldrsh r3, [r4, r5]
	ldr r5, [r7, #4]
	adds r4, r5, #0
	adds r5, #0x44
	movs r6, #0
	ldrsh r4, [r5, r6]
	subs r3, r3, r4
	cmp r3, #0
	bgt .L08068DF6
	adds r3, r0, #0
	ldr r5, [r7]
	adds r4, r5, #0
	adds r5, #0x44
	movs r6, #0
	ldrsh r4, [r5, r6]
	ldr r6, [r7, #4]
	adds r5, r6, #0
	adds r5, r6, #0
	adds r5, #0x44
	str r5, [r7, #8]
	ldr r6, [r7, #8]
	movs r5, #0
	ldrsh r6, [r6, r5]
	str r6, [r7, #0xc]
	ldr r6, [r7, #0xc]
	subs r4, r4, r6
	cmp r4, #0
	bge .L08068DF4
	subs r3, #0x10
.L08068DF4:
	b .L08068DFC
.L08068DF6:
	adds r4, r0, #0
	adds r4, #0x10
	adds r3, r4, #0
.L08068DFC:
	adds r4, r2, #0
	adds r2, #0x44
	ldrh r4, [r2]
	movs r5, #0
	ands r4, r5
	adds r5, r4, #0
	orrs r3, r5
	adds r4, r3, #0
	strh r4, [r2]
	ldr r2, [r7]
	ldr r4, [r7]
	adds r3, r4, #0
	adds r4, #0x46
	movs r3, #0
	ldrsh r1, [r4, r3]
	ldr r4, [r7]
	adds r3, r4, #0
	adds r4, #0x46
	movs r5, #0
	ldrsh r3, [r4, r5]
	ldr r5, [r7, #4]
	adds r4, r5, #0
	adds r5, #0x46
	movs r6, #0
	ldrsh r4, [r5, r6]
	subs r3, r3, r4
	cmp r3, #0
	bgt .L08068E5E
	adds r3, r1, #0
	ldr r5, [r7]
	adds r4, r5, #0
	adds r5, #0x46
	movs r6, #0
	ldrsh r4, [r5, r6]
	ldr r6, [r7, #4]
	adds r5, r6, #0
	adds r5, r6, #0
	adds r5, #0x46
	str r5, [r7, #8]
	ldr r6, [r7, #8]
	movs r5, #0
	ldrsh r6, [r6, r5]
	str r6, [r7, #0xc]
	ldr r6, [r7, #0xc]
	subs r4, r4, r6
	cmp r4, #0
	bge .L08068E5C
	subs r3, #0x10
.L08068E5C:
	b .L08068E64
.L08068E5E:
	adds r4, r1, #0
	adds r4, #0x10
	adds r3, r4, #0
.L08068E64:
	adds r4, r2, #0
	adds r2, #0x46
	ldrh r4, [r2]
	movs r5, #0
	ands r4, r5
	adds r5, r4, #0
	orrs r3, r5
	adds r4, r3, #0
	strh r4, [r2]
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08068E80
func_fe6_08068E80: @ 0x08068E80
	push {r7, lr}
	sub sp, #0xc
	mov r7, sp
	str r0, [r7]
	ldr r0, .L08068F00 @ =gMapAnimSt
	ldr r2, .L08068F00 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x58
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #8
	adds r1, r0, r1
	ldr r0, [r1]
	str r0, [r7, #4]
	ldr r0, .L08068F00 @ =gMapAnimSt
	ldr r2, .L08068F00 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x59
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #8
	adds r1, r0, r1
	ldr r0, [r1]
	str r0, [r7, #8]
	ldr r0, [r7, #4]
	ldr r1, [r7, #8]
	bl func_fe6_08068CB8
	ldr r1, .L08068F00 @ =gMapAnimSt
	adds r0, r1, #0
	adds r1, #0x5a
	ldrh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #3
	ands r0, r1
	adds r2, r0, #0
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0
	beq .L08068EF8
	ldr r0, .L08068F00 @ =gMapAnimSt
	ldr r1, [r0, #0x30]
	str r1, [r7, #4]
	ldr r0, [r7, #4]
	ldr r1, [r7, #8]
	bl func_fe6_08068CB8
	ldr r0, .L08068F00 @ =gMapAnimSt
	ldr r1, [r0, #0x44]
	str r1, [r7, #4]
	ldr r0, [r7, #4]
	ldr r1, [r7, #8]
	bl func_fe6_08068CB8
.L08068EF8:
	add sp, #0xc
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08068F00: .4byte gMapAnimSt

	thumb_func_start func_fe6_08068F04
func_fe6_08068F04: @ 0x08068F04
	push {r7, lr}
	sub sp, #0xc
	mov r7, sp
	str r0, [r7]
	ldr r0, .L08068F84 @ =gMapAnimSt
	ldr r2, .L08068F84 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x58
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #8
	adds r1, r0, r1
	ldr r0, [r1]
	str r0, [r7, #4]
	ldr r0, .L08068F84 @ =gMapAnimSt
	ldr r2, .L08068F84 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x59
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #8
	adds r1, r0, r1
	ldr r0, [r1]
	str r0, [r7, #8]
	ldr r0, [r7, #4]
	ldr r1, [r7, #8]
	bl func_fe6_08068D9C
	ldr r1, .L08068F84 @ =gMapAnimSt
	adds r0, r1, #0
	adds r1, #0x5a
	ldrh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #3
	ands r0, r1
	adds r2, r0, #0
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0
	beq .L08068F7C
	ldr r0, .L08068F84 @ =gMapAnimSt
	ldr r1, [r0, #0x30]
	str r1, [r7, #4]
	ldr r0, [r7, #4]
	ldr r1, [r7, #8]
	bl func_fe6_08068D9C
	ldr r0, .L08068F84 @ =gMapAnimSt
	ldr r1, [r0, #0x44]
	str r1, [r7, #4]
	ldr r0, [r7, #4]
	ldr r1, [r7, #8]
	bl func_fe6_08068D9C
.L08068F7C:
	add sp, #0xc
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08068F84: .4byte gMapAnimSt

	thumb_func_start func_fe6_08068F88
func_fe6_08068F88: @ 0x08068F88
	push {r4, r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L08068FD4 @ =gMapAnimSt
	ldr r2, .L08068FD4 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x58
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r2, [r0]
	movs r1, #0xe
	ldrsb r1, [r2, r1]
	ldr r0, .L08068FD4 @ =gMapAnimSt
	ldr r3, .L08068FD4 @ =gMapAnimSt
	adds r2, r3, #0
	adds r3, #0x58
	ldrb r2, [r3]
	adds r4, r2, #0
	lsls r3, r4, #2
	adds r3, r3, r2
	lsls r2, r3, #2
	adds r0, r0, r2
	ldr r3, [r0]
	movs r2, #0xf
	ldrsb r2, [r3, r2]
	ldr r0, [r7]
	bl CameraMoveWatchPosition
	add sp, #4
	pop {r4, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08068FD4: .4byte gMapAnimSt

	thumb_func_start func_fe6_08068FD8
func_fe6_08068FD8: @ 0x08068FD8
	push {r4, r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L08069024 @ =gMapAnimSt
	ldr r2, .L08069024 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x59
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r2, [r0]
	movs r1, #0xe
	ldrsb r1, [r2, r1]
	ldr r0, .L08069024 @ =gMapAnimSt
	ldr r3, .L08069024 @ =gMapAnimSt
	adds r2, r3, #0
	adds r3, #0x59
	ldrb r2, [r3]
	adds r4, r2, #0
	lsls r3, r4, #2
	adds r3, r3, r2
	lsls r2, r3, #2
	adds r0, r0, r2
	ldr r3, [r0]
	movs r2, #0xf
	ldrsb r2, [r3, r2]
	ldr r0, [r7]
	bl CameraMoveWatchPosition
	add sp, #4
	pop {r4, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08069024: .4byte gMapAnimSt

	thumb_func_start func_fe6_08069028
func_fe6_08069028: @ 0x08069028
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L08069090 @ =gMapAnimSt
	ldr r1, .L08069094 @ =gBattleUnitB
	adds r2, r1, #0
	adds r1, #0x6f
	adds r2, r0, #0
	adds r0, #0x60
	ldrb r2, [r0]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	ldrb r1, [r1]
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strb r1, [r0]
	ldr r0, .L08069090 @ =gMapAnimSt
	ldr r1, .L08069094 @ =gBattleUnitB
	adds r2, r1, #0
	adds r1, #0x70
	adds r2, r0, #0
	adds r0, #0x61
	ldrb r2, [r0]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	ldrb r1, [r1]
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strb r1, [r0]
	ldr r1, .L08069090 @ =gMapAnimSt
	adds r0, r1, #0
	adds r2, r1, #0
	adds r2, #0x60
	ldrb r1, [r2]
	ldr r2, .L08069090 @ =gMapAnimSt
	adds r0, r2, #0
	adds r3, r2, #0
	adds r3, #0x61
	ldrb r2, [r3]
	ldr r0, [r7]
	bl CameraMoveWatchPosition
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08069090: .4byte gMapAnimSt
.L08069094: .4byte gBattleUnitB

	thumb_func_start func_fe6_08069098
func_fe6_08069098: @ 0x08069098
	push {r4, r7, lr}
	sub sp, #0x14
	mov r7, sp
	str r0, [r7]
	ldr r1, .L080690CC @ =gMapAnimSt
	adds r0, r1, #0
	adds r1, #0x58
	ldrb r0, [r1]
	str r0, [r7, #8]
	ldr r1, .L080690CC @ =gMapAnimSt
	adds r0, r1, #0
	adds r1, #0x5a
	ldrh r0, [r1]
	movs r1, #0x80
	ands r0, r1
	adds r2, r0, #0
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0
	beq .L080690D0
	ldr r1, .L080690CC @ =gMapAnimSt
	adds r0, r1, #0
	adds r1, #0x58
	ldrb r0, [r1]
	str r0, [r7, #0xc]
	b .L080690DA
	.align 2, 0
.L080690CC: .4byte gMapAnimSt
.L080690D0:
	ldr r1, .L08069130 @ =gMapAnimSt
	adds r0, r1, #0
	adds r1, #0x59
	ldrb r0, [r1]
	str r0, [r7, #0xc]
.L080690DA:
	ldr r0, .L08069130 @ =gMapAnimSt
	ldr r1, [r7, #8]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #4
	adds r1, r0, r1
	ldr r2, [r1]
	adds r0, r2, #0
	adds r1, r2, #0
	adds r1, #0x4a
	ldrh r2, [r1]
	adds r0, r2, #0
	bl func_fe6_0805F7B4
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #0
	bne .L08069134
	ldr r1, .L08069130 @ =gMapAnimSt
	adds r0, r1, #0
	adds r1, #0x5a
	ldrh r0, [r1]
	movs r1, #2
	ands r0, r1
	adds r2, r0, #0
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0
	beq .L0806912E
	ldr r0, .L08069130 @ =gMapAnimSt
	ldr r1, [r7, #0xc]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r1, #0
	bl func_fe6_08064994
.L0806912E:
	b .L0806941E
	.align 2, 0
.L08069130: .4byte gMapAnimSt
.L08069134:
	ldr r0, .L08069198 @ =gMapAnimSt
	adds r1, r0, #0
	adds r0, #0x5f
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #1
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, [r7, #0xc]
	ldr r2, .L08069198 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x5d
	movs r1, #0
	ldrsb r1, [r2, r1]
	bl func_fe6_08069430
	ldr r1, .L08069198 @ =gMapAnimSt
	adds r0, r1, #0
	adds r1, #0x5a
	ldrh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	ands r0, r1
	adds r2, r0, #0
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0
	beq .L08069188
	ldr r0, [r7, #8]
	ldr r2, .L08069198 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x5d
	movs r1, #0
	ldrsb r1, [r2, r1]
	rsbs r2, r1, #0
	adds r1, r2, #0
	bl func_fe6_08069430
.L08069188:
	ldr r1, .L08069198 @ =gMapAnimSt
	adds r0, r1, #0
	adds r1, #0x5d
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge .L0806919C
	b .L0806941E
	.align 2, 0
.L08069198: .4byte gMapAnimSt
.L0806919C:
	ldr r1, .L080691F0 @ =gMapAnimSt
	adds r0, r1, #0
	adds r1, #0x5a
	ldrh r0, [r1]
	movs r1, #2
	ands r0, r1
	adds r2, r0, #0
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0
	beq .L080691F8
	ldr r0, .L080691F0 @ =gMapAnimSt
	ldr r1, [r7, #0xc]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0xe
	ldrsb r0, [r1, r0]
	adds r1, r0, #0
	lsls r0, r1, #4
	ldr r1, .L080691F4 @ =gBmSt
	movs r3, #0xc
	ldrsh r2, [r1, r3]
	subs r1, r0, r2
	movs r0, #0xc8
	bl PlaySeSpacial
	ldr r0, .L080691F0 @ =gMapAnimSt
	ldr r1, [r7, #0xc]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r1, #0
	bl func_fe6_08064994
	b .L0806941E
	.align 2, 0
.L080691F0: .4byte gMapAnimSt
.L080691F4: .4byte gBmSt
.L080691F8:
	ldr r1, .L08069244 @ =gMapAnimSt
	adds r0, r1, #0
	adds r1, #0x5d
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bne .L0806924C
	ldr r0, .L08069244 @ =gMapAnimSt
	ldr r1, [r7, #0xc]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0xe
	ldrsb r0, [r1, r0]
	adds r1, r0, #0
	lsls r0, r1, #4
	ldr r1, .L08069248 @ =gBmSt
	movs r4, #0xc
	ldrsh r2, [r1, r4]
	subs r1, r0, r2
	movs r0, #0xec
	bl PlaySeSpacial
	ldr r0, .L08069244 @ =gMapAnimSt
	ldr r1, [r7, #0xc]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r1, #0
	bl func_fe6_08064A10
	b .L0806941E
	.align 2, 0
.L08069244: .4byte gMapAnimSt
.L08069248: .4byte gBmSt
.L0806924C:
	movs r0, #0
	ldr r1, .L080692AC @ =gMapAnimSt
	ldr r2, [r7, #0xc]
	adds r4, r2, #0
	lsls r3, r4, #2
	adds r3, r3, r2
	lsls r2, r3, #2
	adds r1, #4
	adds r2, r1, r2
	ldr r3, [r2]
	adds r1, r3, #0
	adds r2, r3, #0
	adds r2, #0x53
	ldrb r1, [r2]
	cmp r1, #0x1b
	bne .L0806926E
	movs r0, #1
.L0806926E:
	str r0, [r7, #0x10]
	ldr r0, [r7, #0x10]
	cmp r0, #0
	beq .L080692D4
	ldr r1, .L080692AC @ =gMapAnimSt
	adds r0, r1, #0
	adds r1, #0x5c
	ldrb r0, [r1]
	movs r1, #2
	ands r0, r1
	adds r2, r0, #0
	lsls r1, r2, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #0
	beq .L080692B0
	movs r0, #0xaf
	str r0, [r7, #4]
	ldr r0, .L080692AC @ =gMapAnimSt
	ldr r1, [r7, #0xc]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r1, #0
	movs r1, #1
	bl func_fe6_08064A8C
	b .L080692CC
	.align 2, 0
.L080692AC: .4byte gMapAnimSt
.L080692B0:
	movs r0, #0xb0
	str r0, [r7, #4]
	ldr r0, .L080692D0 @ =gMapAnimSt
	ldr r1, [r7, #0xc]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r1, #0
	movs r1, #0
	bl func_fe6_08064A8C
.L080692CC:
	b .L080692F8
	.align 2, 0
.L080692D0: .4byte gMapAnimSt
.L080692D4:
	ldr r1, .L080692F0 @ =gMapAnimSt
	adds r0, r1, #0
	adds r1, #0x5c
	ldrb r0, [r1]
	movs r1, #2
	ands r0, r1
	adds r2, r0, #0
	lsls r1, r2, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #0
	beq .L080692F4
	movs r0, #0xd5
	str r0, [r7, #4]
	b .L080692F8
	.align 2, 0
.L080692F0: .4byte gMapAnimSt
.L080692F4:
	movs r0, #0xd2
	str r0, [r7, #4]
.L080692F8:
	ldr r1, .L080693B4 @ =gMapAnimSt
	adds r0, r1, #0
	adds r1, #0x5a
	ldrh r0, [r1]
	movs r1, #1
	ands r0, r1
	adds r2, r0, #0
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0
	beq .L080693BC
	ldr r0, [r7, #4]
	ldr r1, .L080693B4 @ =gMapAnimSt
	ldr r2, [r7, #0xc]
	adds r4, r2, #0
	lsls r3, r4, #2
	adds r3, r3, r2
	lsls r2, r3, #2
	adds r1, r1, r2
	ldr r2, [r1]
	movs r1, #0xe
	ldrsb r1, [r2, r1]
	adds r2, r1, #0
	lsls r1, r2, #4
	ldr r2, .L080693B8 @ =gBmSt
	movs r4, #0xc
	ldrsh r3, [r2, r4]
	subs r1, r1, r3
	bl PlaySeSpacial
	ldr r0, .L080693B4 @ =gMapAnimSt
	ldr r1, [r7, #0xc]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #8
	adds r1, r0, r1
	ldr r4, [r1]
	ldr r0, .L080693B4 @ =gMapAnimSt
	ldr r1, [r7, #8]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #4
	adds r1, r0, r1
	ldr r2, [r1]
	adds r0, r2, #0
	adds r1, r2, #0
	adds r1, #0x4a
	ldrh r2, [r1]
	adds r0, r2, #0
	bl func_fe6_0805F7D4
	lsls r2, r0, #0x18
	lsrs r1, r2, #0x18
	adds r0, r4, #0
	bl func_fe6_0806142C
	bl func_fe6_080685F0
	ldr r0, .L080693B4 @ =gMapAnimSt
	ldr r1, [r7, #0xc]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0xe
	ldrsb r0, [r1, r0]
	adds r1, r0, #0
	lsls r0, r1, #4
	ldr r1, .L080693B8 @ =gBmSt
	movs r3, #0xc
	ldrsh r2, [r1, r3]
	subs r1, r0, r2
	movs r0, #0xd8
	bl PlaySeSpacial
	ldr r0, .L080693B4 @ =gMapAnimSt
	ldr r1, [r7, #8]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #8
	adds r1, r0, r1
	ldr r2, [r1]
	adds r0, r2, #0
	bl StartMuSlowDownAnim
	b .L0806941E
	.align 2, 0
.L080693B4: .4byte gMapAnimSt
.L080693B8: .4byte gBmSt
.L080693BC:
	ldr r0, [r7, #4]
	ldr r1, .L08069428 @ =gMapAnimSt
	ldr r2, [r7, #0xc]
	adds r4, r2, #0
	lsls r3, r4, #2
	adds r3, r3, r2
	lsls r2, r3, #2
	adds r1, r1, r2
	ldr r2, [r1]
	movs r1, #0xe
	ldrsb r1, [r2, r1]
	adds r2, r1, #0
	lsls r1, r2, #4
	ldr r2, .L0806942C @ =gBmSt
	movs r4, #0xc
	ldrsh r3, [r2, r4]
	subs r1, r1, r3
	bl PlaySeSpacial
	ldr r0, .L08069428 @ =gMapAnimSt
	ldr r1, [r7, #0xc]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #8
	adds r1, r0, r1
	ldr r4, [r1]
	ldr r0, .L08069428 @ =gMapAnimSt
	ldr r1, [r7, #8]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #4
	adds r1, r0, r1
	ldr r2, [r1]
	adds r0, r2, #0
	adds r1, r2, #0
	adds r1, #0x4a
	ldrh r2, [r1]
	adds r0, r2, #0
	bl func_fe6_0805F7D4
	lsls r2, r0, #0x18
	lsrs r1, r2, #0x18
	adds r0, r4, #0
	bl StartMuFlashFadeFrom
.L0806941E:
	add sp, #0x14
	pop {r4, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08069428: .4byte gMapAnimSt
.L0806942C: .4byte gBmSt

	thumb_func_start func_fe6_08069430
func_fe6_08069430: @ 0x08069430
	push {r4, r7, lr}
	sub sp, #8
	mov r7, sp
	str r0, [r7]
	str r1, [r7, #4]
	ldr r0, .L0806946C @ =gMapAnimSt
	ldr r1, [r7]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldrb r1, [r0, #0xd]
	ldr r0, [r7, #4]
	cmp r1, r0
	bgt .L08069470
	ldr r0, .L0806946C @ =gMapAnimSt
	ldr r1, [r7]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldrb r1, [r0, #0xd]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0, #0xd]
	b .L080694A4
	.align 2, 0
.L0806946C: .4byte gMapAnimSt
.L08069470:
	ldr r0, .L08069500 @ =gMapAnimSt
	ldr r1, [r7]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, .L08069500 @ =gMapAnimSt
	ldr r2, [r7]
	adds r4, r2, #0
	lsls r3, r4, #2
	adds r3, r3, r2
	lsls r2, r3, #2
	adds r1, r1, r2
	ldr r3, [r7, #4]
	adds r2, r3, #0
	ldrb r3, [r1, #0xd]
	subs r1, r3, r2
	ldrb r2, [r0, #0xd]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strb r1, [r0, #0xd]
.L080694A4:
	ldr r0, .L08069500 @ =gMapAnimSt
	ldr r1, [r7]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, .L08069500 @ =gMapAnimSt
	ldr r2, [r7]
	adds r4, r2, #0
	lsls r3, r4, #2
	adds r3, r3, r2
	lsls r2, r3, #2
	adds r1, r1, r2
	ldrb r0, [r0, #0xd]
	ldrb r1, [r1, #0xc]
	cmp r0, r1
	bls .L080694F6
	ldr r0, .L08069500 @ =gMapAnimSt
	ldr r1, [r7]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, .L08069500 @ =gMapAnimSt
	ldr r2, [r7]
	adds r4, r2, #0
	lsls r3, r4, #2
	adds r3, r3, r2
	lsls r2, r3, #2
	adds r1, r1, r2
	ldrb r2, [r0, #0xd]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	ldrb r1, [r1, #0xc]
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strb r1, [r0, #0xd]
.L080694F6:
	add sp, #8
	pop {r4, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08069500: .4byte gMapAnimSt

	thumb_func_start func_fe6_08069504
func_fe6_08069504: @ 0x08069504
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r1, .L0806951C @ =gMapAnimSt
	adds r0, r1, #0
	adds r1, #0x5f
	ldrb r0, [r1]
	cmp r0, #0
	beq .L08069520
	b .L08069526
	.align 2, 0
.L0806951C: .4byte gMapAnimSt
.L08069520:
	ldr r0, [r7]
	bl Proc_Break
.L08069526:
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08069530
func_fe6_08069530: @ 0x08069530
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L0806955C @ =gMapAnimSt
	ldr r2, .L0806955C @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x59
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r1, #0
	bl func_fe6_08064B7C
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0806955C: .4byte gMapAnimSt

	thumb_func_start func_fe6_08069560
func_fe6_08069560: @ 0x08069560
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L0806958C @ =gMapAnimSt
	ldr r2, .L0806958C @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x59
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r1, #0
	bl func_fe6_08066AD4
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0806958C: .4byte gMapAnimSt

	thumb_func_start func_fe6_08069590
func_fe6_08069590: @ 0x08069590
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L080695BC @ =gMapAnimSt
	ldr r2, .L080695BC @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x59
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r1, #0
	bl func_fe6_08066DFC
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080695BC: .4byte gMapAnimSt

	thumb_func_start func_fe6_080695C0
func_fe6_080695C0: @ 0x080695C0
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L080695EC @ =gMapAnimSt
	ldr r2, .L080695EC @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x58
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r1, #0
	bl func_fe6_08064C50
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080695EC: .4byte gMapAnimSt

	thumb_func_start func_fe6_080695F0
func_fe6_080695F0: @ 0x080695F0
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L08069620 @ =gMapAnimSt
	ldr r2, .L08069620 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x58
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r2, r0, r1
	ldr r0, [r2]
	ldr r1, .L08069624 @ =gUnk_082DD848
	ldr r2, .L08069628 @ =gUnk_082DE974
	bl func_fe6_080653BC
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08069620: .4byte gMapAnimSt
.L08069624: .4byte gUnk_082DD848
.L08069628: .4byte gUnk_082DE974

	thumb_func_start func_fe6_0806962C
func_fe6_0806962C: @ 0x0806962C
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L0806965C @ =gMapAnimSt
	ldr r2, .L0806965C @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x58
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r2, r0, r1
	ldr r0, [r2]
	ldr r1, .L08069660 @ =gUnk_082DD848
	ldr r2, .L08069664 @ =gUnk_082DE954
	bl func_fe6_080653BC
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0806965C: .4byte gMapAnimSt
.L08069660: .4byte gUnk_082DD848
.L08069664: .4byte gUnk_082DE954

	thumb_func_start func_fe6_08069668
func_fe6_08069668: @ 0x08069668
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L08069698 @ =gMapAnimSt
	ldr r2, .L08069698 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x59
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r2, r0, r1
	ldr r0, [r2]
	ldr r1, .L0806969C @ =gUnk_082DED00
	ldr r2, .L080696A0 @ =gUnk_082DEFBC
	movs r3, #0x8b
	bl func_fe6_08065694
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08069698: .4byte gMapAnimSt
.L0806969C: .4byte gUnk_082DED00
.L080696A0: .4byte gUnk_082DEFBC

	thumb_func_start func_fe6_080696A4
func_fe6_080696A4: @ 0x080696A4
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L080696D4 @ =gMapAnimSt
	ldr r2, .L080696D4 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x59
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r2, r0, r1
	ldr r0, [r2]
	ldr r1, .L080696D8 @ =gUnk_082DE994
	ldr r2, .L080696DC @ =gUnk_082DEFBC
	movs r3, #0x89
	bl func_fe6_08065694
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080696D4: .4byte gMapAnimSt
.L080696D8: .4byte gUnk_082DE994
.L080696DC: .4byte gUnk_082DEFBC

	thumb_func_start func_fe6_080696E0
func_fe6_080696E0: @ 0x080696E0
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L08069710 @ =gMapAnimSt
	ldr r2, .L08069710 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x59
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r2, r0, r1
	ldr r0, [r2]
	ldr r1, .L08069714 @ =gUnk_082DEB08
	ldr r2, .L08069718 @ =gUnk_082DEFBC
	movs r3, #0x8a
	bl func_fe6_08065694
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08069710: .4byte gMapAnimSt
.L08069714: .4byte gUnk_082DEB08
.L08069718: .4byte gUnk_082DEFBC

	thumb_func_start func_fe6_0806971C
func_fe6_0806971C: @ 0x0806971C
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L0806974C @ =gMapAnimSt
	ldr r2, .L0806974C @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x59
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r2, r0, r1
	ldr r0, [r2]
	ldr r1, .L08069750 @ =gUnk_082DED00
	ldr r2, .L08069754 @ =gUnk_082DEFBC
	movs r3, #0x8b
	bl func_fe6_08065694
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0806974C: .4byte gMapAnimSt
.L08069750: .4byte gUnk_082DED00
.L08069754: .4byte gUnk_082DEFBC

	thumb_func_start func_fe6_08069758
func_fe6_08069758: @ 0x08069758
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L08069788 @ =gMapAnimSt
	ldr r2, .L08069788 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x59
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r2, r0, r1
	ldr r0, [r2]
	ldr r1, .L0806978C @ =gUnk_082DE994
	ldr r2, .L08069790 @ =gUnk_082DEFBC
	movs r3, #0x89
	bl func_fe6_08065694
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08069788: .4byte gMapAnimSt
.L0806978C: .4byte gUnk_082DE994
.L08069790: .4byte gUnk_082DEFBC

	thumb_func_start func_fe6_08069794
func_fe6_08069794: @ 0x08069794
	push {r4, r5, r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L08069840 @ =gPlaySt
	ldrb r1, [r0, #0x1d]
	lsls r2, r1, #0x1e
	lsrs r0, r2, #0x1f
	cmp r0, #0
	bne .L080697AE
	movs r0, #0xb4
	bl m4aSongNumStart
.L080697AE:
	ldr r0, .L08069844 @ =gMapAnimSt
	ldr r1, .L08069848 @ =gBattleUnitB
	adds r2, r1, #0
	adds r1, #0x6f
	adds r2, r0, #0
	adds r0, #0x60
	ldrb r2, [r0]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	ldrb r1, [r1]
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strb r1, [r0]
	ldr r0, .L08069844 @ =gMapAnimSt
	ldr r1, .L08069848 @ =gBattleUnitB
	adds r2, r1, #0
	adds r1, #0x70
	adds r2, r0, #0
	adds r0, #0x61
	ldrb r2, [r0]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	ldrb r1, [r1]
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strb r1, [r0]
	ldr r0, .L08069844 @ =gMapAnimSt
	ldr r2, .L08069844 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x59
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r2, r0, r1
	ldr r0, [r2]
	ldr r1, .L08069844 @ =gMapAnimSt
	ldr r3, .L08069844 @ =gMapAnimSt
	adds r2, r3, #0
	adds r3, #0x59
	ldrb r2, [r3]
	adds r4, r2, #0
	lsls r3, r4, #2
	adds r3, r3, r2
	lsls r2, r3, #2
	adds r1, r1, r2
	ldr r2, [r1]
	movs r1, #0xe
	ldrsb r1, [r2, r1]
	ldr r2, .L08069844 @ =gMapAnimSt
	ldr r4, .L08069844 @ =gMapAnimSt
	adds r3, r4, #0
	adds r4, #0x59
	ldrb r3, [r4]
	adds r5, r3, #0
	lsls r4, r5, #2
	adds r4, r4, r3
	lsls r3, r4, #2
	adds r2, r2, r3
	ldr r3, [r2]
	movs r2, #0xf
	ldrsb r2, [r3, r2]
	bl func_fe6_08065C30
	add sp, #4
	pop {r4, r5, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08069840: .4byte gPlaySt
.L08069844: .4byte gMapAnimSt
.L08069848: .4byte gBattleUnitB

	thumb_func_start func_fe6_0806984C
func_fe6_0806984C: @ 0x0806984C
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L08069888 @ =gMapAnimSt
	ldr r2, .L08069888 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x59
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r2, r0, r1
	ldr r0, [r2]
	ldr r2, .L08069888 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x60
	ldrb r1, [r2]
	ldr r3, .L08069888 @ =gMapAnimSt
	adds r2, r3, #0
	adds r3, #0x61
	ldrb r2, [r3]
	bl func_fe6_08065C30
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08069888: .4byte gMapAnimSt

	thumb_func_start func_fe6_0806988C
func_fe6_0806988C: @ 0x0806988C
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L080698B8 @ =gMapAnimSt
	ldr r2, .L080698B8 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x58
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r1, #0
	bl func_fe6_08065E08
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080698B8: .4byte gMapAnimSt

	thumb_func_start func_fe6_080698BC
func_fe6_080698BC: @ 0x080698BC
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r1, .L080698E0 @ =gMapAnimSt
	adds r0, r1, #0
	adds r1, #0x60
	ldrb r0, [r1]
	ldr r2, .L080698E0 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x61
	ldrb r1, [r2]
	bl func_fe6_08066FD8
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080698E0: .4byte gMapAnimSt

	thumb_func_start func_fe6_080698E4
func_fe6_080698E4: @ 0x080698E4
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L08069910 @ =gMapAnimSt
	ldr r2, .L08069910 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x59
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r1, #0
	bl func_fe6_080661A4
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08069910: .4byte gMapAnimSt

	thumb_func_start func_fe6_08069914
func_fe6_08069914: @ 0x08069914
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L08069940 @ =gMapAnimSt
	ldr r2, .L08069940 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x59
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r1, #0
	bl func_fe6_080665E4
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08069940: .4byte gMapAnimSt

	thumb_func_start func_fe6_08069944
func_fe6_08069944: @ 0x08069944
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L08069970 @ =gMapAnimSt
	ldr r2, .L08069970 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x59
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r1, #0
	bl func_fe6_0806671C
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08069970: .4byte gMapAnimSt

	thumb_func_start func_fe6_08069974
func_fe6_08069974: @ 0x08069974
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L080699A0 @ =gMapAnimSt
	ldr r2, .L080699A0 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x59
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r1, #0
	bl func_fe6_08066294
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080699A0: .4byte gMapAnimSt

	thumb_func_start func_fe6_080699A4
func_fe6_080699A4: @ 0x080699A4
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L080699D4 @ =gMapAnimSt
	ldr r2, .L080699D4 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x59
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #8
	adds r1, r0, r1
	ldr r2, [r1]
	adds r0, r2, #0
	movs r1, #0
	bl StartMuFadeIntoFlash
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080699D4: .4byte gMapAnimSt

	thumb_func_start func_fe6_080699D8
func_fe6_080699D8: @ 0x080699D8
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L08069A08 @ =gMapAnimSt
	ldr r2, .L08069A08 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x59
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #8
	adds r1, r0, r1
	ldr r2, [r1]
	adds r0, r2, #0
	bl StartMuFadeFromFlash
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08069A08: .4byte gMapAnimSt

	thumb_func_start func_fe6_08069A0C
func_fe6_08069A0C: @ 0x08069A0C
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L08069A3C @ =gMapAnimSt
	ldr r2, .L08069A3C @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x59
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #8
	adds r1, r0, r1
	ldr r2, [r1]
	adds r0, r2, #0
	bl HideMu
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08069A3C: .4byte gMapAnimSt

	thumb_func_start func_fe6_08069A40
func_fe6_08069A40: @ 0x08069A40
	push {r4, r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L08069AAC @ =gMapAnimSt
	ldr r2, .L08069AAC @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x59
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0xe
	ldrsb r0, [r1, r0]
	adds r1, r0, #0
	lsls r0, r1, #4
	ldr r1, .L08069AB0 @ =gBmSt
	movs r3, #0xc
	ldrsh r2, [r1, r3]
	subs r1, r0, r2
	adds r0, r1, #0
	adds r0, #8
	ldr r1, .L08069AAC @ =gMapAnimSt
	ldr r3, .L08069AAC @ =gMapAnimSt
	adds r2, r3, #0
	adds r3, #0x59
	ldrb r2, [r3]
	adds r4, r2, #0
	lsls r3, r4, #2
	adds r3, r3, r2
	lsls r2, r3, #2
	adds r1, r1, r2
	ldr r2, [r1]
	movs r1, #0xf
	ldrsb r1, [r2, r1]
	adds r2, r1, #0
	lsls r1, r2, #4
	ldr r2, .L08069AB0 @ =gBmSt
	movs r4, #0xe
	ldrsh r3, [r2, r4]
	subs r1, r1, r3
	adds r2, r1, #0
	adds r2, #8
	adds r1, r2, #0
	bl func_fe6_080689F0
	add sp, #4
	pop {r4, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08069AAC: .4byte gMapAnimSt
.L08069AB0: .4byte gBmSt

	thumb_func_start func_fe6_08069AB4
func_fe6_08069AB4: @ 0x08069AB4
	push {r4, r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L08069B30 @ =gPlaySt
	ldrb r1, [r0, #0x1d]
	lsls r2, r1, #0x1e
	lsrs r0, r2, #0x1f
	cmp r0, #0
	bne .L08069ACE
	movs r0, #0xb5
	bl m4aSongNumStart
.L08069ACE:
	ldr r0, .L08069B34 @ =gMapAnimSt
	ldr r2, .L08069B34 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x59
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0xe
	ldrsb r0, [r1, r0]
	adds r1, r0, #0
	lsls r0, r1, #4
	ldr r1, .L08069B38 @ =gBmSt
	movs r3, #0xc
	ldrsh r2, [r1, r3]
	subs r1, r0, r2
	adds r0, r1, #0
	adds r0, #8
	ldr r1, .L08069B34 @ =gMapAnimSt
	ldr r3, .L08069B34 @ =gMapAnimSt
	adds r2, r3, #0
	adds r3, #0x59
	ldrb r2, [r3]
	adds r4, r2, #0
	lsls r3, r4, #2
	adds r3, r3, r2
	lsls r2, r3, #2
	adds r1, r1, r2
	ldr r2, [r1]
	movs r1, #0xf
	ldrsb r1, [r2, r1]
	adds r2, r1, #0
	lsls r1, r2, #4
	ldr r2, .L08069B38 @ =gBmSt
	movs r4, #0xe
	ldrsh r3, [r2, r4]
	subs r1, r1, r3
	adds r2, r1, #0
	adds r2, #8
	adds r1, r2, #0
	bl func_fe6_08068A1C
	add sp, #4
	pop {r4, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08069B30: .4byte gPlaySt
.L08069B34: .4byte gMapAnimSt
.L08069B38: .4byte gBmSt

	thumb_func_start func_fe6_08069B3C
func_fe6_08069B3C: @ 0x08069B3C
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L08069B6C @ =gMapAnimSt
	ldr r2, .L08069B6C @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x59
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #8
	adds r1, r0, r1
	ldr r2, [r1]
	adds r0, r2, #0
	bl ShowMu
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08069B6C: .4byte gMapAnimSt

	thumb_func_start func_fe6_08069B70
func_fe6_08069B70: @ 0x08069B70
	push {r7, lr}
	sub sp, #8
	mov r7, sp
	str r0, [r7]
	ldr r0, .L08069C00 @ =gMapAnimSt
	ldr r2, .L08069C00 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x59
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	str r1, [r7, #4]
	ldr r0, .L08069C00 @ =gMapAnimSt
	ldr r2, .L08069C00 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x59
	ldrb r1, [r2]
	adds r3, r1, #0
	lsls r2, r3, #2
	adds r2, r2, r1
	lsls r1, r2, #2
	adds r0, #8
	adds r1, r0, r1
	ldr r0, [r1]
	ldr r2, .L08069C00 @ =gMapAnimSt
	adds r1, r2, #0
	adds r2, #0x60
	ldrb r1, [r2]
	adds r2, r1, #0
	lsls r1, r2, #4
	ldr r3, .L08069C00 @ =gMapAnimSt
	adds r2, r3, #0
	adds r3, #0x61
	ldrb r2, [r3]
	adds r3, r2, #0
	lsls r2, r3, #4
	bl SetMuScreenPosition
	ldr r0, [r7, #4]
	ldr r1, .L08069C00 @ =gMapAnimSt
	adds r2, r1, #0
	adds r1, #0x60
	ldrb r2, [r0, #0xe]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	ldrb r1, [r1]
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strb r1, [r0, #0xe]
	ldr r0, [r7, #4]
	ldr r1, .L08069C00 @ =gMapAnimSt
	adds r2, r1, #0
	adds r1, #0x61
	ldrb r2, [r0, #0xf]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	ldrb r1, [r1]
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strb r1, [r0, #0xf]
	add sp, #8
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08069C00: .4byte gMapAnimSt

	thumb_func_start func_fe6_08069C04
func_fe6_08069C04: @ 0x08069C04
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, [r7]
	bl func_fe6_080684EC
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08069C1C
func_fe6_08069C1C: @ 0x08069C1C
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, [r7]
	bl func_fe6_08068578
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08069C34
func_fe6_08069C34: @ 0x08069C34
	push {r7, lr}
	mov r7, sp
	ldr r1, .L08069C64 @ =0x0203CE48
	adds r0, r1, #0
	bl func_fe6_0806A44C
	ldr r1, .L08069C68 @ =0x0203D0C8
	adds r0, r1, #0
	bl func_fe6_0806A44C
	ldr r0, .L08069C6C @ =0x0203D348
	ldr r1, .L08069C64 @ =0x0203CE48
	str r1, [r0]
	ldr r0, .L08069C6C @ =0x0203D348
	ldr r1, .L08069C68 @ =0x0203D0C8
	str r1, [r0, #4]
	ldr r0, .L08069C70 @ =0x0203D350
	ldr r1, .L08069C6C @ =0x0203D348
	ldr r2, [r1]
	str r2, [r0]
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08069C64: .4byte 0x0203CE48
.L08069C68: .4byte 0x0203D0C8
.L08069C6C: .4byte 0x0203D348
.L08069C70: .4byte 0x0203D350

	thumb_func_start func_fe6_08069C74
func_fe6_08069C74: @ 0x08069C74
	push {r7, lr}
	mov r7, sp
	ldr r0, .L08069D9C @ =gDispIo
	ldrb r1, [r0, #1]
	movs r2, #0x20
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0, #1]
	ldr r0, .L08069D9C @ =gDispIo
	ldrb r1, [r0, #1]
	movs r2, #0xbf
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0, #1]
	ldr r0, .L08069D9C @ =gDispIo
	ldrb r1, [r0, #1]
	movs r2, #0x7f
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0, #1]
	ldr r0, .L08069D9C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x2d
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08069D9C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x31
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08069D9C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0xf0
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08069D9C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x30
	ldrb r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	movs r3, #0xa0
	adds r1, r2, #0
	orrs r1, r3
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08069D9C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r2, #0xfe
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08069D9C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r2, #0xfd
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08069D9C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r2, #0xfb
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08069D9C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r2, #0xf7
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08069D9C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x34
	ldrb r1, [r0]
	movs r2, #0xef
	ands r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08069D9C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r2, #1
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08069D9C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r2, #2
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08069D9C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r2, #4
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08069D9C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r2, #8
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r0, .L08069D9C @ =gDispIo
	adds r1, r0, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r2, #0x10
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	ldr r1, .L08069DA0 @ =func_fe6_08069DE8
	adds r0, r1, #0
	bl SetOnHBlankA
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08069D9C: .4byte gDispIo
.L08069DA0: .4byte func_fe6_08069DE8

	thumb_func_start func_fe6_08069DA4
func_fe6_08069DA4: @ 0x08069DA4
	push {r7, lr}
	sub sp, #0xc
	mov r7, sp
	str r0, [r7]
	str r1, [r7, #4]
	str r2, [r7, #8]
	ldr r0, .L08069DD4 @ =0x0203D348
	ldr r1, [r0, #4]
	adds r0, r1, #0
	bl func_fe6_0806A44C
	ldr r1, .L08069DD4 @ =0x0203D348
	ldr r0, [r1, #4]
	ldr r2, [r7, #4]
	ldr r3, [r7, #8]
	ldr r1, [r7]
	bl func_fe6_0806A51C
	bl func_fe6_0806A424
	add sp, #0xc
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08069DD4: .4byte 0x0203D348

	thumb_func_start func_fe6_08069DD8
func_fe6_08069DD8: @ 0x08069DD8
	push {r7, lr}
	mov r7, sp
	movs r0, #0
	bl SetOnHBlankA
	pop {r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08069DE8
func_fe6_08069DE8: @ 0x08069DE8
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	adds r0, r7, #0
	ldr r1, .L08069E10 @ =0x04000006
	ldrh r2, [r1]
	strh r2, [r0]
	adds r0, r7, #0
	ldrh r1, [r0]
	cmp r1, #0x9f
	bls .L08069E1C
	ldr r0, .L08069E14 @ =0x0203D350
	ldr r1, .L08069E18 @ =0x0203D348
	ldr r2, [r1]
	str r2, [r0]
	adds r0, r7, #0
	movs r1, #0
	strh r1, [r0]
	b .L08069E2A
	.align 2, 0
.L08069E10: .4byte 0x04000006
.L08069E14: .4byte 0x0203D350
.L08069E18: .4byte 0x0203D348
.L08069E1C:
	adds r1, r7, #0
	adds r0, r7, #0
	adds r1, r7, #0
	ldrh r2, [r1]
	adds r1, r2, #1
	adds r2, r1, #0
	strh r2, [r0]
.L08069E2A:
	ldr r0, .L08069E48 @ =0x04000040
	adds r1, r7, #0
	ldrh r2, [r1]
	adds r3, r2, #0
	lsls r1, r3, #1
	ldr r3, .L08069E4C @ =0x0203D350
	ldr r2, [r3]
	adds r1, r1, r2
	ldrh r2, [r1]
	strh r2, [r0]
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08069E48: .4byte 0x04000040
.L08069E4C: .4byte 0x0203D350

	thumb_func_start func_fe6_08069E50
func_fe6_08069E50: @ 0x08069E50
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	adds r0, r7, #0
	ldr r1, .L08069E78 @ =0x04000006
	ldrh r2, [r1]
	strh r2, [r0]
	adds r0, r7, #0
	ldrh r1, [r0]
	cmp r1, #0x9f
	bls .L08069E84
	ldr r0, .L08069E7C @ =0x0203D350
	ldr r1, .L08069E80 @ =0x0203D348
	ldr r2, [r1]
	str r2, [r0]
	adds r0, r7, #0
	movs r1, #0
	strh r1, [r0]
	b .L08069E92
	.align 2, 0
.L08069E78: .4byte 0x04000006
.L08069E7C: .4byte 0x0203D350
.L08069E80: .4byte 0x0203D348
.L08069E84:
	adds r1, r7, #0
	adds r0, r7, #0
	adds r1, r7, #0
	ldrh r2, [r1]
	adds r1, r2, #1
	adds r2, r1, #0
	strh r2, [r0]
.L08069E92:
	ldr r0, .L08069EC8 @ =0x04000040
	adds r1, r7, #0
	ldrh r2, [r1]
	adds r3, r2, #0
	lsls r1, r3, #1
	ldr r3, .L08069ECC @ =0x0203D350
	ldr r2, [r3]
	adds r1, r1, r2
	ldrh r2, [r1]
	strh r2, [r0]
	ldr r0, .L08069ED0 @ =0x04000018
	adds r1, r7, #0
	ldrh r2, [r1]
	adds r3, r2, #0
	lsls r1, r3, #1
	ldr r3, .L08069ECC @ =0x0203D350
	ldr r2, [r3]
	adds r1, r1, r2
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r2, r1, r3
	ldrh r1, [r2]
	strh r1, [r0]
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08069EC8: .4byte 0x04000040
.L08069ECC: .4byte 0x0203D350
.L08069ED0: .4byte 0x04000018

	thumb_func_start func_fe6_08069ED4
func_fe6_08069ED4: @ 0x08069ED4
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	adds r0, r7, #0
	ldr r1, .L08069EFC @ =0x04000006
	ldrh r2, [r1]
	strh r2, [r0]
	adds r0, r7, #0
	ldrh r1, [r0]
	cmp r1, #0x9f
	bls .L08069F08
	ldr r0, .L08069F00 @ =0x0203D350
	ldr r1, .L08069F04 @ =0x0203D348
	ldr r2, [r1]
	str r2, [r0]
	adds r0, r7, #0
	movs r1, #0
	strh r1, [r0]
	b .L08069F16
	.align 2, 0
.L08069EFC: .4byte 0x04000006
.L08069F00: .4byte 0x0203D350
.L08069F04: .4byte 0x0203D348
.L08069F08:
	adds r1, r7, #0
	adds r0, r7, #0
	adds r1, r7, #0
	ldrh r2, [r1]
	adds r1, r2, #1
	adds r2, r1, #0
	strh r2, [r0]
.L08069F16:
	ldr r0, .L08069F4C @ =0x05000022
	adds r1, r7, #0
	ldrh r2, [r1]
	adds r3, r2, #0
	lsls r1, r3, #1
	ldr r3, .L08069F50 @ =0x0203D350
	ldr r2, [r3]
	adds r1, r1, r2
	ldrh r2, [r1]
	strh r2, [r0]
	ldr r0, .L08069F54 @ =0x05000042
	adds r1, r7, #0
	ldrh r2, [r1]
	adds r3, r2, #0
	lsls r1, r3, #1
	ldr r3, .L08069F50 @ =0x0203D350
	ldr r2, [r3]
	adds r1, r1, r2
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r2, r1, r3
	ldrh r1, [r2]
	strh r1, [r0]
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08069F4C: .4byte 0x05000022
.L08069F50: .4byte 0x0203D350
.L08069F54: .4byte 0x05000042

	thumb_func_start func_fe6_08069F58
func_fe6_08069F58: @ 0x08069F58
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	adds r0, r7, #0
	ldr r1, .L08069F80 @ =0x04000006
	ldrh r2, [r1]
	strh r2, [r0]
	adds r0, r7, #0
	ldrh r1, [r0]
	cmp r1, #0x9f
	bls .L08069F8C
	ldr r0, .L08069F84 @ =0x0203D350
	ldr r1, .L08069F88 @ =0x0203D348
	ldr r2, [r1]
	str r2, [r0]
	adds r0, r7, #0
	movs r1, #0
	strh r1, [r0]
	b .L08069F9A
	.align 2, 0
.L08069F80: .4byte 0x04000006
.L08069F84: .4byte 0x0203D350
.L08069F88: .4byte 0x0203D348
.L08069F8C:
	adds r1, r7, #0
	adds r0, r7, #0
	adds r1, r7, #0
	ldrh r2, [r1]
	adds r1, r2, #1
	adds r2, r1, #0
	strh r2, [r0]
.L08069F9A:
	ldr r0, .L08069FCC @ =0x05000328
	adds r1, r7, #0
	ldrh r2, [r1]
	adds r3, r2, #0
	lsls r1, r3, #1
	ldr r3, .L08069FD0 @ =0x0203D350
	ldr r2, [r3]
	adds r1, r1, r2
	ldrh r2, [r1]
	strh r2, [r0]
	ldr r0, .L08069FD4 @ =0x050003A8
	adds r1, r7, #0
	ldrh r2, [r1]
	adds r3, r2, #0
	lsls r1, r3, #1
	ldr r3, .L08069FD0 @ =0x0203D350
	ldr r2, [r3]
	adds r1, r1, r2
	ldrh r2, [r1]
	strh r2, [r0]
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08069FCC: .4byte 0x05000328
.L08069FD0: .4byte 0x0203D350
.L08069FD4: .4byte 0x050003A8

	thumb_func_start func_fe6_08069FD8
func_fe6_08069FD8: @ 0x08069FD8
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	adds r0, r7, #0
	ldr r1, .L0806A000 @ =0x04000006
	ldrh r2, [r1]
	strh r2, [r0]
	adds r0, r7, #0
	ldrh r1, [r0]
	cmp r1, #0x9f
	bls .L0806A00C
	ldr r0, .L0806A004 @ =0x0203D350
	ldr r1, .L0806A008 @ =0x0203D348
	ldr r2, [r1]
	str r2, [r0]
	adds r0, r7, #0
	movs r1, #0
	strh r1, [r0]
	b .L0806A01A
	.align 2, 0
.L0806A000: .4byte 0x04000006
.L0806A004: .4byte 0x0203D350
.L0806A008: .4byte 0x0203D348
.L0806A00C:
	adds r1, r7, #0
	adds r0, r7, #0
	adds r1, r7, #0
	ldrh r2, [r1]
	adds r1, r2, #1
	adds r2, r1, #0
	strh r2, [r0]
.L0806A01A:
	ldr r0, .L0806A038 @ =0x04000052
	adds r1, r7, #0
	ldrh r2, [r1]
	adds r3, r2, #0
	lsls r1, r3, #1
	ldr r3, .L0806A03C @ =0x0203D350
	ldr r2, [r3]
	adds r1, r1, r2
	ldrh r2, [r1]
	strh r2, [r0]
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0806A038: .4byte 0x04000052
.L0806A03C: .4byte 0x0203D350

	thumb_func_start func_fe6_0806A040
func_fe6_0806A040: @ 0x0806A040
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	adds r0, r7, #0
	ldr r1, .L0806A068 @ =0x04000006
	ldrh r2, [r1]
	strh r2, [r0]
	adds r0, r7, #0
	ldrh r1, [r0]
	cmp r1, #0x9f
	bls .L0806A074
	ldr r0, .L0806A06C @ =0x0203D350
	ldr r1, .L0806A070 @ =0x0203D348
	ldr r2, [r1]
	str r2, [r0]
	adds r0, r7, #0
	movs r1, #0
	strh r1, [r0]
	b .L0806A082
	.align 2, 0
.L0806A068: .4byte 0x04000006
.L0806A06C: .4byte 0x0203D350
.L0806A070: .4byte 0x0203D348
.L0806A074:
	adds r1, r7, #0
	adds r0, r7, #0
	adds r1, r7, #0
	ldrh r2, [r1]
	adds r1, r2, #1
	adds r2, r1, #0
	strh r2, [r0]
.L0806A082:
	ldr r0, .L0806A0CC @ =0x04000012
	adds r1, r7, #0
	ldrh r2, [r1]
	adds r3, r2, #0
	lsls r1, r3, #1
	ldr r3, .L0806A0D0 @ =0x0203D350
	ldr r2, [r3]
	adds r1, r1, r2
	ldrh r2, [r1]
	strh r2, [r0]
	ldr r0, .L0806A0D4 @ =0x04000010
	adds r1, r7, #0
	ldrh r2, [r1]
	adds r3, r2, #0
	lsls r1, r3, #1
	ldr r3, .L0806A0D0 @ =0x0203D350
	ldr r2, [r3]
	adds r1, r1, r2
	ldrh r2, [r1]
	strh r2, [r0]
	ldr r0, .L0806A0D8 @ =0x04000016
	adds r1, r7, #0
	ldrh r2, [r1]
	adds r3, r2, #0
	lsls r1, r3, #1
	ldr r3, .L0806A0D0 @ =0x0203D350
	ldr r2, [r3]
	adds r1, r1, r2
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r2, r1, r3
	ldrh r1, [r2]
	strh r1, [r0]
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0806A0CC: .4byte 0x04000012
.L0806A0D0: .4byte 0x0203D350
.L0806A0D4: .4byte 0x04000010
.L0806A0D8: .4byte 0x04000016

	thumb_func_start func_fe6_0806A0DC
func_fe6_0806A0DC: @ 0x0806A0DC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	add r7, sp, #4
	adds r5, r0, #0
	adds r4, r1, #0
	adds r1, r2, #0
	adds r0, r3, #0
	adds r2, r7, #0
	adds r3, r5, #0
	strh r3, [r2]
	adds r2, r7, #2
	adds r3, r4, #0
	strh r3, [r2]
	adds r2, r7, #4
	strh r1, [r2]
	adds r1, r7, #6
	strh r0, [r1]
	ldr r1, .L0806A210 @ =0x0203D348
	ldr r0, [r1, #4]
	adds r2, r7, #0
	ldrh r1, [r2]
	adds r3, r7, #2
	ldrh r2, [r3]
	adds r4, r7, #4
	ldrh r3, [r4]
	adds r4, r7, #4
	ldrh r5, [r4]
	movs r6, #0x1f
	adds r4, r5, #0
	ands r4, r6
	adds r6, r4, #0
	lsls r5, r6, #0x10
	lsrs r4, r5, #0x10
	lsrs r5, r4, #1
	adds r4, r5, #0
	movs r5, #0x1f
	ands r4, r5
	adds r5, r7, #4
	ldrh r6, [r5]
	movs r5, #0xf8
	lsls r5, r5, #2
	mov r8, r5
	mov r5, r8
	ands r5, r6
	mov r8, r5
	mov r5, r8
	lsls r6, r5, #0x10
	lsrs r5, r6, #0x10
	lsrs r6, r5, #1
	adds r5, r6, #0
	movs r6, #0xf8
	lsls r6, r6, #2
	ands r5, r6
	orrs r4, r5
	adds r5, r7, #4
	ldrh r6, [r5]
	movs r5, #0xf8
	lsls r5, r5, #7
	mov r8, r5
	mov r5, r8
	ands r5, r6
	mov r8, r5
	mov r5, r8
	lsls r6, r5, #0x10
	lsrs r5, r6, #0x10
	lsrs r6, r5, #1
	adds r5, r6, #0
	movs r6, #0xf8
	lsls r6, r6, #7
	ands r5, r6
	orrs r4, r5
	adds r6, r4, #0
	lsls r5, r6, #0x10
	lsrs r4, r5, #0x10
	str r4, [sp]
	bl func_fe6_0806A600
	ldr r0, .L0806A210 @ =0x0203D348
	ldr r1, [r0, #4]
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r0, r1, r2
	adds r2, r7, #0
	ldrh r1, [r2]
	adds r3, r7, #2
	ldrh r2, [r3]
	adds r4, r7, #6
	ldrh r3, [r4]
	adds r4, r7, #6
	ldrh r5, [r4]
	movs r6, #0x1f
	adds r4, r5, #0
	ands r4, r6
	adds r6, r4, #0
	lsls r5, r6, #0x10
	lsrs r4, r5, #0x10
	lsrs r5, r4, #1
	adds r4, r5, #0
	movs r5, #0x1f
	ands r4, r5
	adds r5, r7, #6
	ldrh r6, [r5]
	movs r5, #0xf8
	lsls r5, r5, #2
	mov r8, r5
	mov r5, r8
	ands r5, r6
	mov r8, r5
	mov r5, r8
	lsls r6, r5, #0x10
	lsrs r5, r6, #0x10
	lsrs r6, r5, #1
	adds r5, r6, #0
	movs r6, #0xf8
	lsls r6, r6, #2
	ands r5, r6
	orrs r4, r5
	adds r5, r7, #6
	ldrh r6, [r5]
	movs r5, #0xf8
	lsls r5, r5, #7
	mov r8, r5
	mov r5, r8
	ands r5, r6
	mov r8, r5
	mov r5, r8
	lsls r6, r5, #0x10
	lsrs r5, r6, #0x10
	lsrs r6, r5, #1
	adds r5, r6, #0
	movs r6, #0xf8
	lsls r6, r6, #7
	ands r5, r6
	orrs r4, r5
	adds r6, r4, #0
	lsls r5, r6, #0x10
	lsrs r4, r5, #0x10
	str r4, [sp]
	bl func_fe6_0806A600
	bl func_fe6_0806A424
	ldr r1, .L0806A214 @ =func_fe6_08069ED4
	adds r0, r1, #0
	bl SetOnHBlankA
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0806A210: .4byte 0x0203D348
.L0806A214: .4byte func_fe6_08069ED4

	thumb_func_start func_fe6_0806A218
func_fe6_0806A218: @ 0x0806A218
	push {r4, r5, r7, lr}
	sub sp, #0xc
	add r7, sp, #4
	adds r5, r0, #0
	adds r4, r1, #0
	adds r1, r2, #0
	adds r0, r3, #0
	adds r2, r7, #0
	adds r3, r5, #0
	strh r3, [r2]
	adds r2, r7, #2
	adds r3, r4, #0
	strh r3, [r2]
	adds r2, r7, #4
	strh r1, [r2]
	adds r1, r7, #6
	strh r0, [r1]
	ldr r1, .L0806A268 @ =0x0203D348
	ldr r0, [r1, #4]
	adds r2, r7, #0
	ldrh r1, [r2]
	adds r3, r7, #2
	ldrh r2, [r3]
	adds r4, r7, #4
	ldrh r3, [r4]
	adds r4, r7, #6
	ldrh r5, [r4]
	str r5, [sp]
	bl func_fe6_0806A600
	bl func_fe6_0806A424
	ldr r1, .L0806A26C @ =func_fe6_08069F58
	adds r0, r1, #0
	bl SetOnHBlankA
	add sp, #0xc
	pop {r4, r5, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0806A268: .4byte 0x0203D348
.L0806A26C: .4byte func_fe6_08069F58

	thumb_func_start func_fe6_0806A270
func_fe6_0806A270: @ 0x0806A270
	push {r7, lr}
	sub sp, #0x14
	mov r7, sp
	str r0, [r7]
	str r1, [r7, #4]
	str r2, [r7, #8]
	str r3, [r7, #0xc]
	ldr r0, .L0806A298 @ =0x0203D348
	ldr r1, [r0, #4]
	adds r0, r1, #0
	bl func_fe6_0806A44C
.L0806A288:
	ldr r0, [r7, #0x1c]
	ldrb r1, [r0]
	cmp r1, #0xff
	beq .L0806A29C
	ldr r0, [r7, #4]
	cmp r0, #0
	bge .L0806A29E
	b .L0806A29C
	.align 2, 0
.L0806A298: .4byte 0x0203D348
.L0806A29C:
	b .L0806A2EC
.L0806A29E:
	ldr r0, [r7, #0x1c]
	ldrb r1, [r0]
	ldr r2, [r7, #8]
	adds r0, r1, #0
	muls r0, r2, r0
	ldr r1, [r7, #0xc]
	bl Div
	str r0, [r7, #0x10]
	ldr r0, [r7, #0x1c]
	adds r1, r0, #1
	str r1, [r7, #0x1c]
	ldr r0, [r7, #0x10]
	cmp r0, #0
	ble .L0806A2DE
	ldr r1, .L0806A2E8 @ =0x0203D348
	ldr r0, [r1, #4]
	ldr r1, [r7]
	ldr r3, [r7, #0x10]
	adds r2, r1, r3
	subs r1, r2, #1
	ldr r2, [r7, #4]
	bl func_fe6_0806A4D4
	ldr r1, .L0806A2E8 @ =0x0203D348
	ldr r0, [r1, #4]
	ldr r1, [r7]
	ldr r2, [r7, #0x10]
	subs r1, r1, r2
	ldr r2, [r7, #4]
	bl func_fe6_0806A488
.L0806A2DE:
	ldr r0, [r7, #4]
	subs r1, r0, #1
	str r1, [r7, #4]
	b .L0806A288
	.align 2, 0
.L0806A2E8: .4byte 0x0203D348
.L0806A2EC:
	ldr r0, [r7, #0x10]
	cmp r0, #0
	ble .L0806A328
.L0806A2F2:
	ldr r0, [r7, #4]
	cmp r0, #0
	bge .L0806A2FA
	b .L0806A328
.L0806A2FA:
	ldr r1, .L0806A324 @ =0x0203D348
	ldr r0, [r1, #4]
	ldr r1, [r7]
	ldr r3, [r7, #0x10]
	adds r2, r1, r3
	subs r1, r2, #1
	ldr r2, [r7, #4]
	bl func_fe6_0806A4D4
	ldr r1, .L0806A324 @ =0x0203D348
	ldr r0, [r1, #4]
	ldr r1, [r7]
	ldr r2, [r7, #0x10]
	subs r1, r1, r2
	ldr r2, [r7, #4]
	bl func_fe6_0806A488
	ldr r0, [r7, #4]
	subs r1, r0, #1
	str r1, [r7, #4]
	b .L0806A2F2
	.align 2, 0
.L0806A324: .4byte 0x0203D348
.L0806A328:
	add sp, #0x14
	pop {r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806A330
func_fe6_0806A330: @ 0x0806A330
	push {r4, r5, r7, lr}
	sub sp, #0x10
	mov r7, sp
	str r0, [r7]
	adds r4, r1, #0
	adds r1, r2, #0
	adds r0, r3, #0
	adds r2, r7, #4
	adds r3, r4, #0
	strh r3, [r2]
	adds r2, r7, #6
	strh r1, [r2]
	adds r1, r7, #0
	adds r1, #8
	strh r0, [r1]
	movs r0, #0
	str r0, [r7, #0xc]
.L0806A352:
	ldr r0, [r7, #0xc]
	cmp r0, #0x9f
	ble .L0806A35A
	b .L0806A3A0
.L0806A35A:
	ldr r0, [r7]
	ldr r1, .L0806A39C @ =gSinLut
	adds r2, r7, #0
	adds r2, #8
	movs r4, #0
	ldrsh r3, [r2, r4]
	ldr r4, [r7, #0xc]
	adds r2, r3, #0
	muls r2, r4, r2
	adds r3, r7, #4
	movs r5, #0
	ldrsh r4, [r3, r5]
	adds r2, r2, r4
	movs r3, #0xff
	ands r2, r3
	adds r3, r2, #0
	lsls r2, r3, #1
	adds r3, r1, r2
	movs r2, #0
	ldrsh r1, [r3, r2]
	adds r2, r7, #6
	movs r4, #0
	ldrsh r3, [r2, r4]
	muls r1, r3, r1
	asrs r2, r1, #0xc
	adds r1, r2, #0
	strh r1, [r0]
	adds r0, #2
	str r0, [r7]
	ldr r0, [r7, #0xc]
	adds r1, r0, #1
	str r1, [r7, #0xc]
	b .L0806A352
	.align 2, 0
.L0806A39C: .4byte gSinLut
.L0806A3A0:
	add sp, #0x10
	pop {r4, r5, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806A3A8
func_fe6_0806A3A8: @ 0x0806A3A8
	push {r4, r5, r7, lr}
	sub sp, #0x10
	mov r7, sp
	str r0, [r7]
	adds r4, r1, #0
	adds r1, r2, #0
	adds r0, r3, #0
	adds r2, r7, #4
	adds r3, r4, #0
	strh r3, [r2]
	adds r2, r7, #6
	strh r1, [r2]
	adds r1, r7, #0
	adds r1, #8
	strh r0, [r1]
	ldr r0, [r7, #0x20]
	str r0, [r7, #0xc]
.L0806A3CA:
	ldr r0, [r7, #0xc]
	ldr r1, [r7, #0x24]
	cmp r0, r1
	blt .L0806A3D4
	b .L0806A41C
.L0806A3D4:
	ldr r0, [r7]
	ldr r1, .L0806A418 @ =gSinLut
	adds r2, r7, #0
	adds r2, #8
	movs r4, #0
	ldrsh r3, [r2, r4]
	ldr r4, [r7, #0xc]
	adds r2, r3, #0
	muls r2, r4, r2
	adds r3, r7, #4
	movs r5, #0
	ldrsh r4, [r3, r5]
	adds r2, r2, r4
	movs r3, #0xff
	ands r2, r3
	adds r3, r2, #0
	lsls r2, r3, #1
	adds r3, r1, r2
	movs r2, #0
	ldrsh r1, [r3, r2]
	adds r2, r7, #6
	movs r4, #0
	ldrsh r3, [r2, r4]
	muls r1, r3, r1
	asrs r2, r1, #0xc
	adds r1, r2, #0
	strh r1, [r0]
	adds r0, #2
	str r0, [r7]
	ldr r0, [r7, #0xc]
	adds r1, r0, #1
	str r1, [r7, #0xc]
	b .L0806A3CA
	.align 2, 0
.L0806A418: .4byte gSinLut
.L0806A41C:
	add sp, #0x10
	pop {r4, r5, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806A424
func_fe6_0806A424: @ 0x0806A424
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	ldr r0, .L0806A448 @ =0x0203D348
	ldr r1, [r0]
	str r1, [r7]
	ldr r0, .L0806A448 @ =0x0203D348
	ldr r1, .L0806A448 @ =0x0203D348
	ldr r2, [r1, #4]
	str r2, [r0]
	ldr r0, .L0806A448 @ =0x0203D348
	ldr r1, [r7]
	str r1, [r0, #4]
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0806A448: .4byte 0x0203D348

	thumb_func_start func_fe6_0806A44C
func_fe6_0806A44C: @ 0x0806A44C
	push {r7, lr}
	sub sp, #0xc
	mov r7, sp
	str r0, [r7]
	ldr r0, [r7]
	str r0, [r7, #8]
	movs r0, #0
	str r0, [r7, #4]
.L0806A45C:
	ldr r0, [r7, #4]
	cmp r0, #0x9f
	ble .L0806A464
	b .L0806A480
.L0806A464:
	adds r0, r7, #0
	adds r0, #8
	ldr r1, [r0]
	ldr r3, .L0806A47C @ =0x0000F0F0
	adds r2, r3, #0
	strh r2, [r1]
	adds r1, #2
	str r1, [r0]
	ldr r0, [r7, #4]
	adds r1, r0, #1
	str r1, [r7, #4]
	b .L0806A45C
	.align 2, 0
.L0806A47C: .4byte 0x0000F0F0
.L0806A480:
	add sp, #0xc
	pop {r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806A488
func_fe6_0806A488: @ 0x0806A488
	push {r7, lr}
	sub sp, #0xc
	mov r7, sp
	str r0, [r7]
	str r1, [r7, #4]
	str r2, [r7, #8]
	ldr r0, [r7, #4]
	cmp r0, #0
	bge .L0806A49E
	movs r0, #0
	str r0, [r7, #4]
.L0806A49E:
	ldr r0, [r7, #4]
	cmp r0, #0xef
	ble .L0806A4A8
	movs r0, #0xef
	str r0, [r7, #4]
.L0806A4A8:
	ldr r0, [r7, #8]
	cmp r0, #0
	blt .L0806A4B6
	ldr r0, [r7, #8]
	cmp r0, #0x9f
	bgt .L0806A4B6
	b .L0806A4B8
.L0806A4B6:
	b .L0806A4CA
.L0806A4B8:
	ldr r0, [r7, #8]
	adds r1, r0, #0
	lsls r0, r1, #1
	ldr r2, [r7]
	adds r1, r0, r2
	adds r0, r1, #1
	ldr r1, [r7, #4]
	adds r2, r1, #0
	strb r2, [r0]
.L0806A4CA:
	add sp, #0xc
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806A4D4
func_fe6_0806A4D4: @ 0x0806A4D4
	push {r7, lr}
	sub sp, #0xc
	mov r7, sp
	str r0, [r7]
	str r1, [r7, #4]
	str r2, [r7, #8]
	ldr r0, [r7, #4]
	cmp r0, #0
	bge .L0806A4EA
	movs r0, #0
	str r0, [r7, #4]
.L0806A4EA:
	ldr r0, [r7, #4]
	cmp r0, #0xef
	ble .L0806A4F4
	movs r0, #0xef
	str r0, [r7, #4]
.L0806A4F4:
	ldr r0, [r7, #8]
	cmp r0, #0
	blt .L0806A502
	ldr r0, [r7, #8]
	cmp r0, #0x9f
	bgt .L0806A502
	b .L0806A504
.L0806A502:
	b .L0806A514
.L0806A504:
	ldr r0, [r7, #8]
	adds r1, r0, #0
	lsls r0, r1, #1
	ldr r1, [r7]
	adds r0, r0, r1
	ldr r1, [r7, #4]
	adds r2, r1, #0
	strb r2, [r0]
.L0806A514:
	add sp, #0xc
	pop {r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806A51C
func_fe6_0806A51C: @ 0x0806A51C
	push {r7, lr}
	sub sp, #0x18
	mov r7, sp
	str r0, [r7]
	str r1, [r7, #4]
	str r2, [r7, #8]
	str r3, [r7, #0xc]
	ldr r0, [r7, #0xc]
	str r0, [r7, #0x10]
	movs r0, #0
	str r0, [r7, #0x14]
.L0806A532:
	ldr r0, [r7, #0x10]
	ldr r1, [r7, #0x14]
	cmp r0, r1
	bge .L0806A53C
	b .L0806A5F8
.L0806A53C:
	ldr r0, [r7, #4]
	ldr r2, [r7, #0x10]
	adds r1, r0, r2
	ldr r0, [r7, #8]
	ldr r3, [r7, #0x14]
	adds r2, r0, r3
	ldr r0, [r7]
	bl func_fe6_0806A4D4
	ldr r0, [r7, #4]
	ldr r2, [r7, #0x10]
	adds r1, r0, r2
	ldr r0, [r7, #8]
	ldr r3, [r7, #0x14]
	subs r2, r0, r3
	ldr r0, [r7]
	bl func_fe6_0806A4D4
	ldr r0, [r7, #4]
	ldr r2, [r7, #0x14]
	adds r1, r0, r2
	ldr r0, [r7, #8]
	ldr r3, [r7, #0x10]
	adds r2, r0, r3
	ldr r0, [r7]
	bl func_fe6_0806A4D4
	ldr r0, [r7, #4]
	ldr r2, [r7, #0x14]
	adds r1, r0, r2
	ldr r0, [r7, #8]
	ldr r3, [r7, #0x10]
	subs r2, r0, r3
	ldr r0, [r7]
	bl func_fe6_0806A4D4
	ldr r0, [r7, #4]
	ldr r2, [r7, #0x10]
	subs r1, r0, r2
	ldr r0, [r7, #8]
	ldr r3, [r7, #0x14]
	adds r2, r0, r3
	ldr r0, [r7]
	bl func_fe6_0806A488
	ldr r0, [r7, #4]
	ldr r2, [r7, #0x10]
	subs r1, r0, r2
	ldr r0, [r7, #8]
	ldr r3, [r7, #0x14]
	subs r2, r0, r3
	ldr r0, [r7]
	bl func_fe6_0806A488
	ldr r0, [r7, #4]
	ldr r2, [r7, #0x14]
	subs r1, r0, r2
	ldr r0, [r7, #8]
	ldr r3, [r7, #0x10]
	adds r2, r0, r3
	ldr r0, [r7]
	bl func_fe6_0806A488
	ldr r0, [r7, #4]
	ldr r2, [r7, #0x14]
	subs r1, r0, r2
	ldr r0, [r7, #8]
	ldr r3, [r7, #0x10]
	subs r2, r0, r3
	ldr r0, [r7]
	bl func_fe6_0806A488
	ldr r1, [r7, #0xc]
	adds r0, r1, #1
	ldr r2, [r7, #0x14]
	lsls r1, r2, #1
	subs r0, r0, r1
	str r0, [r7, #0xc]
	ldr r0, [r7, #0xc]
	cmp r0, #0
	bge .L0806A5F0
	ldr r1, [r7, #0x10]
	subs r0, r1, #1
	lsls r1, r0, #1
	ldr r0, [r7, #0xc]
	adds r1, r0, r1
	str r1, [r7, #0xc]
	ldr r0, [r7, #0x10]
	subs r1, r0, #1
	str r1, [r7, #0x10]
.L0806A5F0:
	ldr r0, [r7, #0x14]
	adds r1, r0, #1
	str r1, [r7, #0x14]
	b .L0806A532
.L0806A5F8:
	add sp, #0x18
	pop {r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806A600
func_fe6_0806A600: @ 0x0806A600
	push {r4, r7, lr}
	sub sp, #0x28
	add r7, sp, #4
	str r0, [r7]
	adds r4, r1, #0
	adds r1, r3, #0
	ldr r0, [r7, #0x30]
	adds r3, r7, #4
	strh r4, [r3]
	adds r3, r7, #6
	strh r2, [r3]
	adds r2, r7, #0
	adds r2, #8
	strh r1, [r2]
	adds r1, r7, #0
	adds r1, #0xa
	strh r0, [r1]
	adds r1, r7, #6
	ldrh r0, [r1]
	adds r1, r7, #4
	ldrh r2, [r1]
	subs r0, r0, r2
	str r0, [r7, #0x20]
	movs r0, #0
	str r0, [r7, #0x10]
	movs r0, #0
	str r0, [r7, #0xc]
.L0806A636:
	ldr r0, [r7, #0xc]
	cmp r0, #0x9f
	ble .L0806A63E
	b .L0806A748
.L0806A63E:
	adds r0, r7, #4
	ldrh r1, [r0]
	ldr r0, [r7, #0xc]
	cmp r0, r1
	bge .L0806A658
	ldr r0, [r7]
	adds r1, r7, #0
	adds r1, #8
	ldrh r2, [r1]
	strh r2, [r0]
	adds r0, #2
	str r0, [r7]
	b .L0806A740
.L0806A658:
	adds r0, r7, #6
	ldrh r1, [r0]
	ldr r0, [r7, #0xc]
	cmp r0, r1
	ble .L0806A672
	ldr r0, [r7]
	adds r1, r7, #0
	adds r1, #0xa
	ldrh r2, [r1]
	strh r2, [r0]
	adds r0, #2
	str r0, [r7]
	b .L0806A740
.L0806A672:
	adds r0, r7, #0
	adds r0, #8
	ldrh r1, [r0]
	movs r2, #0x1f
	adds r0, r1, #0
	ands r0, r2
	adds r1, r0, #0
	lsls r0, r1, #0x10
	lsrs r1, r0, #0x10
	adds r0, r7, #0
	adds r0, #0xa
	ldrh r2, [r0]
	movs r3, #0x1f
	adds r0, r2, #0
	ands r0, r3
	adds r2, r0, #0
	lsls r0, r2, #0x10
	lsrs r2, r0, #0x10
	ldr r3, [r7, #0x10]
	ldr r0, [r7, #0x20]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	str r0, [r7, #0x14]
	adds r0, r7, #0
	adds r0, #8
	ldrh r1, [r0]
	movs r2, #0xf8
	lsls r2, r2, #2
	adds r0, r1, #0
	ands r0, r2
	adds r1, r0, #0
	lsls r0, r1, #0x10
	lsrs r1, r0, #0x10
	adds r0, r7, #0
	adds r0, #0xa
	ldrh r2, [r0]
	movs r3, #0xf8
	lsls r3, r3, #2
	adds r0, r2, #0
	ands r0, r3
	adds r2, r0, #0
	lsls r0, r2, #0x10
	lsrs r2, r0, #0x10
	ldr r3, [r7, #0x10]
	ldr r0, [r7, #0x20]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	str r0, [r7, #0x18]
	adds r0, r7, #0
	adds r0, #8
	ldrh r1, [r0]
	movs r2, #0xf8
	lsls r2, r2, #7
	adds r0, r1, #0
	ands r0, r2
	adds r1, r0, #0
	lsls r0, r1, #0x10
	lsrs r1, r0, #0x10
	adds r0, r7, #0
	adds r0, #0xa
	ldrh r2, [r0]
	movs r3, #0xf8
	lsls r3, r3, #7
	adds r0, r2, #0
	ands r0, r3
	adds r2, r0, #0
	lsls r0, r2, #0x10
	lsrs r2, r0, #0x10
	ldr r3, [r7, #0x10]
	ldr r0, [r7, #0x20]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	str r0, [r7, #0x1c]
	ldr r0, [r7]
	ldr r2, [r7, #0x14]
	adds r1, r2, #0
	movs r2, #0x1f
	ands r1, r2
	ldr r3, [r7, #0x18]
	adds r2, r3, #0
	movs r3, #0xf8
	lsls r3, r3, #2
	ands r2, r3
	orrs r1, r2
	ldr r3, [r7, #0x1c]
	adds r2, r3, #0
	movs r3, #0xf8
	lsls r3, r3, #7
	ands r2, r3
	orrs r1, r2
	adds r2, r1, #0
	strh r2, [r0]
	adds r0, #2
	str r0, [r7]
	ldr r0, [r7, #0x10]
	adds r1, r0, #1
	str r1, [r7, #0x10]
.L0806A740:
	ldr r0, [r7, #0xc]
	adds r1, r0, #1
	str r1, [r7, #0xc]
	b .L0806A636
.L0806A748:
	add sp, #0x28
	pop {r4, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806A750
func_fe6_0806A750: @ 0x0806A750
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, [r7]
	adds r1, r0, #0
	adds r0, #0x64
	ldrh r1, [r0]
	movs r2, #0
	ands r1, r2
	adds r2, r1, #0
	strh r2, [r0]
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806A770
func_fe6_0806A770: @ 0x0806A770
	push {r4, r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, .L0806A7A8 @ =0x0203D348
	ldr r1, [r0, #4]
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r1, [r7]
	adds r2, r1, #0
	adds r1, #0x64
	ldrh r2, [r1]
	adds r3, r2, #1
	adds r4, r3, #0
	strh r4, [r1]
	lsls r2, r2, #0x10
	asrs r1, r2, #0x10
	movs r2, #0x10
	movs r3, #8
	bl func_fe6_0806A330
	bl func_fe6_0806A424
	add sp, #4
	pop {r4, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0806A7A8: .4byte 0x0203D348

	thumb_func_start func_fe6_0806A7AC
func_fe6_0806A7AC: @ 0x0806A7AC
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	movs r0, #0
	str r0, [r7]
.L0806A7B6:
	ldr r0, [r7]
	cmp r0, #0x9f
	ble .L0806A7BE
	b .L0806A7E0
.L0806A7BE:
	ldr r0, .L0806A7DC @ =0x0203D348
	ldr r1, [r7]
	adds r2, r1, #0
	lsls r1, r2, #1
	ldr r2, [r0]
	adds r0, r1, r2
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r2, #0
	strh r1, [r0]
	ldr r0, [r7]
	adds r1, r0, #1
	str r1, [r7]
	b .L0806A7B6
	.align 2, 0
.L0806A7DC: .4byte 0x0203D348
.L0806A7E0:
	movs r0, #8
	str r0, [r7]
.L0806A7E4:
	ldr r0, [r7]
	cmp r0, #0x97
	ble .L0806A7EC
	b .L0806A808
.L0806A7EC:
	ldr r0, .L0806A804 @ =0x0203D348
	ldr r1, [r7]
	adds r2, r1, #0
	lsls r1, r2, #1
	ldr r2, [r0]
	adds r0, r1, r2
	movs r1, #0x10
	strh r1, [r0]
	ldr r0, [r7]
	adds r1, r0, #1
	str r1, [r7]
	b .L0806A7E4
	.align 2, 0
.L0806A804: .4byte 0x0203D348
.L0806A808:
	movs r0, #0
	str r0, [r7]
.L0806A80C:
	ldr r0, [r7]
	cmp r0, #0x20
	ble .L0806A814
	b .L0806A874
.L0806A814:
	ldr r0, .L0806A86C @ =0x0203D348
	ldr r1, [r7]
	adds r2, r1, #0
	lsls r1, r2, #1
	ldr r0, [r0]
	adds r1, r1, r0
	adds r0, r1, #0
	adds r0, #0x10
	ldr r2, [r7]
	asrs r1, r2, #1
	adds r2, r1, #0
	movs r3, #0x10
	subs r1, r3, r2
	adds r2, r1, #0
	lsls r1, r2, #8
	ldr r3, [r7]
	asrs r2, r3, #1
	orrs r1, r2
	adds r2, r1, #0
	strh r2, [r0]
	ldr r0, .L0806A86C @ =0x0203D348
	ldr r1, [r7]
	adds r2, r1, #0
	lsls r1, r2, #1
	ldr r3, .L0806A870 @ =0xFFFFFED0
	adds r2, r1, r3
	ldr r1, [r0]
	subs r0, r1, r2
	ldr r2, [r7]
	asrs r1, r2, #1
	adds r2, r1, #0
	movs r3, #0x10
	subs r1, r3, r2
	adds r2, r1, #0
	lsls r1, r2, #8
	ldr r3, [r7]
	asrs r2, r3, #1
	orrs r1, r2
	adds r2, r1, #0
	strh r2, [r0]
	ldr r0, [r7]
	adds r1, r0, #1
	str r1, [r7]
	b .L0806A80C
	.align 2, 0
.L0806A86C: .4byte 0x0203D348
.L0806A870: .4byte 0xFFFFFED0
.L0806A874:
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806A87C
func_fe6_0806A87C: @ 0x0806A87C
	push {r7, lr}
	sub sp, #8
	mov r7, sp
	str r0, [r7]
	str r1, [r7, #4]
	ldr r0, .L0806A8A0 @ =0x0203D348
	ldr r1, [r7]
	adds r2, r1, #0
	lsls r1, r2, #2
	adds r0, r0, r1
	ldr r1, [r7, #4]
	adds r2, r1, #0
	lsls r1, r2, #1
	ldr r0, [r0]
	adds r1, r1, r0
	adds r0, r1, #0
	b .L0806A8A4
	.align 2, 0
.L0806A8A0: .4byte 0x0203D348
.L0806A8A4:
	add sp, #8
	pop {r7}
	pop {r1}
	bx r1
