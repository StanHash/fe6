
	.include "macro.inc"

	.syntax unified

	thumb_func_start func_fe6_08068578
func_fe6_08068578: @ 0x08068578
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	str r0, [r7]
	ldr r0, [r7]
	cmp r0, #0
	beq .L08068598
	ldr r1, .L08068594 @ =ProcScr_Unk_0866569C
	adds r0, r1, #0
	ldr r1, [r7]
	bl SpawnProcLocking
	b .L080685A2
	.align 2, 0
.L08068594: .4byte ProcScr_Unk_0866569C
.L08068598:
	ldr r1, .L080685AC @ =ProcScr_Unk_0866569C
	adds r0, r1, #0
	movs r1, #3
	bl SpawnProc
.L080685A2:
	add sp, #4
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080685AC: .4byte ProcScr_Unk_0866569C

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
	ldr r1, .L08068604 @ =ProcScr_Unk_086656B4
	adds r0, r1, #0
	movs r1, #3
	bl SpawnProc
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08068604: .4byte ProcScr_Unk_086656B4

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
	ldr r1, .L080689EC @ =ProcScr_Unk_086656CC
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
.L080689EC: .4byte ProcScr_Unk_086656CC

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
	ldr r0, .L08068A5C @ =ProcScr_Unk_086656FC
	b .L08068A6C
	.align 2, 0
.L08068A58: .4byte gMapAnimSt
.L08068A5C: .4byte ProcScr_Unk_086656FC
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
