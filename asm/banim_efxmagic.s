	.include "macro.inc"
	.syntax unified

	thumb_func_start StartSpellAnimation
StartSpellAnimation: @ 0x0804C898
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, .L0804C8C4 @ =gEkrSpellAnimIndex
	bl GetAnimPosition
	lsls r0, r0, #1
	adds r0, r0, r4
	ldr r1, .L0804C8C8 @ =gUnk_085D0DA0
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	ldr r1, .L0804C8CC @ =gUnk_Banim_0201E7A4
	movs r0, #0
	str r0, [r1]
	adds r0, r5, #0
	bl _call_via_r2
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804C8C4: .4byte gEkrSpellAnimIndex
.L0804C8C8: .4byte gUnk_085D0DA0
.L0804C8CC: .4byte gUnk_Banim_0201E7A4

	thumb_func_start func_fe6_0804C8D0
func_fe6_0804C8D0: @ 0x0804C8D0
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0804C8D4
func_fe6_0804C8D4: @ 0x0804C8D4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	mov r8, r3
	ldr r7, [sp, #0x18]
	ldr r1, .L0804C910 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804C914 @ =gUnk_085D0E94
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	str r5, [r0, #0x44]
	str r6, [r0, #0x48]
	mov r1, r8
	str r1, [r0, #0x4c]
	str r7, [r0, #0x50]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
.L0804C910: .4byte gEfxBgSemaphore
.L0804C914: .4byte gUnk_085D0E94

	thumb_func_start func_fe6_0804C918
func_fe6_0804C918: @ 0x0804C918
	ldr r1, .L0804C924 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
.L0804C924: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804C928
func_fe6_0804C928: @ 0x0804C928
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r2, r0, #0
	ldr r0, .L0804C9A8 @ =gUnk_Banim_0201E3D8
	ldr r0, [r0]
	ldr r4, .L0804C9AC @ =gUnk_Banim_0201E3E4
	cmp r0, #0
	bne .L0804C940
	ldr r4, .L0804C9B0 @ =gUnk_Banim_0201E524
.L0804C940:
	ldrh r0, [r2, #0x2e]
	lsls r1, r0, #0x18
	lsrs r3, r1, #0x18
	ldr r1, [r2, #0x50]
	adds r0, r0, r1
	strh r0, [r2, #0x2e]
	movs r1, #0
	ldr r0, [r2, #0x44]
	mov r8, r0
	ldr r6, [r2, #0x48]
	mov sl, r6
	ldr r7, .L0804C9B4 @ =gUnk_08605A94
	mov ip, r7
	ldr r5, [r2, #0x4c]
	ldr r0, .L0804C9B8 @ =gDispIo
	mov sb, r0
.L0804C960:
	mov r6, sl
	adds r0, r3, r6
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	lsls r0, r3, #1
	add r0, ip
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r5, r0
	lsls r0, r0, #8
	lsrs r0, r0, #0x10
	mov r6, sb
	ldrh r6, [r6, #0x20]
	adds r0, r6, r0
	strh r0, [r4]
	adds r4, #2
	adds r1, #1
	cmp r1, #0x77
	bls .L0804C960
	ldrh r0, [r2, #0x2c]
	adds r0, #1
	strh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r8
	bne .L0804C99A
	adds r0, r2, #0
	bl Proc_End
.L0804C99A:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804C9A8: .4byte gUnk_Banim_0201E3D8
.L0804C9AC: .4byte gUnk_Banim_0201E3E4
.L0804C9B0: .4byte gUnk_Banim_0201E524
.L0804C9B4: .4byte gUnk_08605A94
.L0804C9B8: .4byte gDispIo

	thumb_func_start func_fe6_0804C9BC
func_fe6_0804C9BC: @ 0x0804C9BC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L0804C9E4 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804C9E8 @ =gUnk_085D0EB4
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	str r5, [r0, #0x44]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804C9E4: .4byte gEfxBgSemaphore
.L0804C9E8: .4byte gUnk_085D0EB4

	thumb_func_start func_fe6_0804C9EC
func_fe6_0804C9EC: @ 0x0804C9EC
	ldr r1, .L0804C9F8 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
.L0804C9F8: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804C9FC
func_fe6_0804C9FC: @ 0x0804C9FC
	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r0, .L0804CA38 @ =gUnk_Banim_0201E3D8
	ldr r0, [r0]
	ldr r1, .L0804CA3C @ =gUnk_Banim_0201E3E4
	cmp r0, #0
	bne .L0804CA0C
	ldr r1, .L0804CA40 @ =gUnk_Banim_0201E524
.L0804CA0C:
	movs r2, #0
	ldr r5, [r3, #0x44]
	ldr r4, .L0804CA44 @ =gDispIo
.L0804CA12:
	ldrh r0, [r4, #0x20]
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, #0x77
	bls .L0804CA12
	ldrh r0, [r3, #0x2c]
	adds r0, #1
	strh r0, [r3, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r5
	bne .L0804CA32
	adds r0, r3, #0
	bl Proc_End
.L0804CA32:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804CA38: .4byte gUnk_Banim_0201E3D8
.L0804CA3C: .4byte gUnk_Banim_0201E3E4
.L0804CA40: .4byte gUnk_Banim_0201E524
.L0804CA44: .4byte gDispIo

	thumb_func_start func_fe6_0804CA48
func_fe6_0804CA48: @ 0x0804CA48
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r6, r3, #0
	ldr r1, .L0804CA90 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804CA94 @ =gUnk_085D0ED4
	movs r1, #3
	bl SpawnProc
	adds r7, r0, #0
	mov r0, r8
	str r0, [r7, #0x5c]
	movs r1, #0
	mov sb, r1
	movs r0, #0
	strh r0, [r7, #0x2c]
	strh r0, [r7, #0x2e]
	str r4, [r7, #0x44]
	str r5, [r7, #0x54]
	str r6, [r7, #0x58]
	mov r0, r8
	bl GetAnimAnotherSide
	bl GetAnimPosition
	cmp r0, #0
	bne .L0804CA9C
	ldr r0, .L0804CA98 @ =0x0000FFB8
	b .L0804CA9E
	.align 2, 0
.L0804CA90: .4byte gEfxBgSemaphore
.L0804CA94: .4byte gUnk_085D0ED4
.L0804CA98: .4byte 0x0000FFB8
.L0804CA9C:
	ldr r0, .L0804CABC @ =0x0000FFF8
.L0804CA9E:
	strh r0, [r7, #0x32]
	ldr r0, .L0804CAC0 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L0804CACA
	mov r0, r8
	bl GetAnimPosition
	cmp r0, #0
	bne .L0804CAC4
	ldrh r0, [r7, #0x32]
	adds r0, #0x18
	b .L0804CAC8
	.align 2, 0
.L0804CABC: .4byte 0x0000FFF8
.L0804CAC0: .4byte gEkrDistanceType
.L0804CAC4:
	ldrh r0, [r7, #0x32]
	subs r0, #0x18
.L0804CAC8:
	strh r0, [r7, #0x32]
.L0804CACA:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0804CAD8
func_fe6_0804CAD8: @ 0x0804CAD8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r0, .L0804CB20 @ =gUnk_Banim_0201E14C
	ldr r0, [r0]
	ldr r5, .L0804CB24 @ =gUnk_Banim_0201E158
	cmp r0, #0
	bne .L0804CAE8
	ldr r5, .L0804CB28 @ =gUnk_Banim_0201E298
.L0804CAE8:
	ldr r1, [r4, #0x54]
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r1, [r4, #0x58]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r3, [r0]
	ldr r0, .L0804CB2C @ =0x0000FFFF
	cmp r2, r0
	beq .L0804CB54
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	movs r2, #0
	ldr r6, [r4, #0x44]
	ldr r7, .L0804CB30 @ =0x00007FFF
	mov ip, r7
.L0804CB10:
	ldrh r1, [r3]
	movs r7, #0
	ldrsh r0, [r3, r7]
	cmp r0, ip
	bne .L0804CB34
	movs r0, #0
	b .L0804CB46
	.align 2, 0
.L0804CB20: .4byte gUnk_Banim_0201E14C
.L0804CB24: .4byte gUnk_Banim_0201E158
.L0804CB28: .4byte gUnk_Banim_0201E298
.L0804CB2C: .4byte 0x0000FFFF
.L0804CB30: .4byte 0x00007FFF
.L0804CB34:
	ldrh r0, [r4, #0x32]
	adds r1, r1, r0
	ldrh r7, [r3, #2]
	adds r0, r0, r7
	lsls r1, r1, #0x10
	asrs r1, r1, #8
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	orrs r0, r1
.L0804CB46:
	strh r0, [r5]
	adds r3, #4
	adds r5, #2
	adds r2, #1
	cmp r2, #0x77
	bls .L0804CB10
	b .L0804CB64
.L0804CB54:
	movs r2, #0
	ldr r6, [r4, #0x44]
	movs r0, #0
.L0804CB5A:
	strh r0, [r5]
	adds r5, #2
	adds r2, #1
	cmp r2, #0x77
	bls .L0804CB5A
.L0804CB64:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	movs r1, #0x2c
	ldrsh r0, [r4, r1]
	cmp r0, r6
	bne .L0804CB80
	ldr r1, .L0804CB88 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804CB80:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804CB88: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804CB8C
func_fe6_0804CB8C: @ 0x0804CB8C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	mov sb, r1
	adds r5, r3, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r1, .L0804CC34 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r1, .L0804CC38 @ =gUnk_Banim_0201E158
	movs r0, #0
	adds r7, r1, #0
	ldr r4, .L0804CC3C @ =gUnk_Banim_0201E298
	ldr r3, .L0804CC40 @ =gUnk_Banim_0201E3E4
	ldr r6, .L0804CC44 @ =gUnk_Banim_0201E14C
	mov ip, r6
	ldr r6, .L0804CC48 @ =gUnk_Banim_0201E3D8
	mov sl, r6
.L0804CBBA:
	strh r2, [r1]
	adds r1, #2
	adds r0, #1
	cmp r0, #0x9f
	bls .L0804CBBA
	adds r1, r4, #0
	movs r0, #0
.L0804CBC8:
	strh r2, [r1]
	adds r1, #2
	adds r0, #1
	cmp r0, #0x9f
	bls .L0804CBC8
	adds r1, r3, #0
	movs r0, #0
.L0804CBD6:
	strh r2, [r1]
	adds r1, #2
	adds r0, #1
	cmp r0, #0x9f
	bls .L0804CBD6
	ldr r1, .L0804CC4C @ =gUnk_Banim_0201E524
	movs r0, #0
.L0804CBE4:
	strh r2, [r1]
	adds r1, #2
	adds r0, #1
	cmp r0, #0x9f
	bls .L0804CBE4
	movs r4, #0
	mov r0, ip
	str r4, [r0]
	mov r1, sl
	str r4, [r1]
	ldr r6, .L0804CC50 @ =gUnk_Banim_0201E150
	str r7, [r6]
	ldr r0, .L0804CC54 @ =gUnk_Banim_0201E3DC
	str r3, [r0]
	ldr r1, .L0804CC58 @ =gUnk_Banim_0201E154
	str r7, [r1]
	ldr r6, .L0804CC5C @ =gUnk_Banim_0201E3E0
	str r3, [r6]
	adds r0, r5, #0
	bl SetOnHBlankA
	ldr r1, .L0804CC60 @ =gUnk_Banim_0201E7A4
	movs r0, #1
	str r0, [r1]
	ldr r0, .L0804CC64 @ =gUnk_085D0EEC
	movs r1, #0
	bl SpawnProc
	mov r1, r8
	str r1, [r0, #0x5c]
	strh r4, [r0, #0x2c]
	mov r6, sb
	str r6, [r0, #0x44]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804CC34: .4byte gEfxBgSemaphore
.L0804CC38: .4byte gUnk_Banim_0201E158
.L0804CC3C: .4byte gUnk_Banim_0201E298
.L0804CC40: .4byte gUnk_Banim_0201E3E4
.L0804CC44: .4byte gUnk_Banim_0201E14C
.L0804CC48: .4byte gUnk_Banim_0201E3D8
.L0804CC4C: .4byte gUnk_Banim_0201E524
.L0804CC50: .4byte gUnk_Banim_0201E150
.L0804CC54: .4byte gUnk_Banim_0201E3DC
.L0804CC58: .4byte gUnk_Banim_0201E154
.L0804CC5C: .4byte gUnk_Banim_0201E3E0
.L0804CC60: .4byte gUnk_Banim_0201E7A4
.L0804CC64: .4byte gUnk_085D0EEC

	thumb_func_start func_fe6_0804CC68
func_fe6_0804CC68: @ 0x0804CC68
	push {lr}
	adds r3, r2, #0
	movs r2, #0
	bl func_fe6_0804CB8C
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0804CC78
func_fe6_0804CC78: @ 0x0804CC78
	push {lr}
	bl Proc_Break
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0804CC84
func_fe6_0804CC84: @ 0x0804CC84
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0804CCA8 @ =gBmSt
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq .L0804CD04
	ldr r1, .L0804CCAC @ =gUnk_Banim_0201E14C
	ldr r0, [r1]
	cmp r0, #1
	bne .L0804CCB8
	movs r0, #0
	str r0, [r1]
	ldr r1, .L0804CCB0 @ =gUnk_Banim_0201E150
	ldr r0, .L0804CCB4 @ =gUnk_Banim_0201E158
	b .L0804CCC0
	.align 2, 0
.L0804CCA8: .4byte gBmSt
.L0804CCAC: .4byte gUnk_Banim_0201E14C
.L0804CCB0: .4byte gUnk_Banim_0201E150
.L0804CCB4: .4byte gUnk_Banim_0201E158
.L0804CCB8:
	movs r0, #1
	str r0, [r1]
	ldr r1, .L0804CCD8 @ =gUnk_Banim_0201E150
	ldr r0, .L0804CCDC @ =gUnk_Banim_0201E298
.L0804CCC0:
	str r0, [r1]
	adds r3, r1, #0
	ldr r1, .L0804CCE0 @ =gUnk_Banim_0201E3D8
	ldr r0, [r1]
	cmp r0, #1
	bne .L0804CCEC
	movs r0, #0
	str r0, [r1]
	ldr r1, .L0804CCE4 @ =gUnk_Banim_0201E3DC
	ldr r0, .L0804CCE8 @ =gUnk_Banim_0201E3E4
	b .L0804CCF4
	.align 2, 0
.L0804CCD8: .4byte gUnk_Banim_0201E150
.L0804CCDC: .4byte gUnk_Banim_0201E298
.L0804CCE0: .4byte gUnk_Banim_0201E3D8
.L0804CCE4: .4byte gUnk_Banim_0201E3DC
.L0804CCE8: .4byte gUnk_Banim_0201E3E4
.L0804CCEC:
	movs r0, #1
	str r0, [r1]
	ldr r1, .L0804CD34 @ =gUnk_Banim_0201E3DC
	ldr r0, .L0804CD38 @ =gUnk_Banim_0201E524
.L0804CCF4:
	str r0, [r1]
	adds r2, r1, #0
	ldr r1, .L0804CD3C @ =gUnk_Banim_0201E154
	ldr r0, [r3]
	str r0, [r1]
	ldr r1, .L0804CD40 @ =gUnk_Banim_0201E3E0
	ldr r0, [r2]
	str r0, [r1]
.L0804CD04:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r4, #0x44]
	cmp r0, r1
	bne .L0804CD2E
	ldr r1, .L0804CD44 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	movs r0, #0
	bl SetOnHBlankA
	ldr r1, .L0804CD48 @ =gUnk_Banim_0201E7A4
	movs r0, #0
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804CD2E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804CD34: .4byte gUnk_Banim_0201E3DC
.L0804CD38: .4byte gUnk_Banim_0201E524
.L0804CD3C: .4byte gUnk_Banim_0201E154
.L0804CD40: .4byte gUnk_Banim_0201E3E0
.L0804CD44: .4byte gEfxBgSemaphore
.L0804CD48: .4byte gUnk_Banim_0201E7A4

	thumb_func_start func_fe6_0804CD4C
func_fe6_0804CD4C: @ 0x0804CD4C
	ldr r0, .L0804CD78 @ =0x04000004
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L0804CD74
	ldr r3, .L0804CD7C @ =0x04000040
	ldr r2, .L0804CD80 @ =gUnk_Banim_0201E154
	ldr r0, [r2]
	ldrh r1, [r0]
	strh r1, [r3]
	adds r0, #2
	str r0, [r2]
	subs r3, #0x2c
	ldr r2, .L0804CD84 @ =gUnk_Banim_0201E3E0
	ldr r0, [r2]
	ldrh r1, [r0]
	strh r1, [r3]
	adds r0, #2
	str r0, [r2]
.L0804CD74:
	bx lr
	.align 2, 0
.L0804CD78: .4byte 0x04000004
.L0804CD7C: .4byte 0x04000040
.L0804CD80: .4byte gUnk_Banim_0201E154
.L0804CD84: .4byte gUnk_Banim_0201E3E0

	thumb_func_start func_fe6_0804CD88
func_fe6_0804CD88: @ 0x0804CD88
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	mov r8, r3
	ldr r7, [sp, #0x18]
	ldr r1, .L0804CDC8 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804CDCC @ =gUnk_085D0F0C
	movs r1, #3
	bl SpawnProc
	str r5, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r4, [r0, #0x2e]
	adds r4, r4, r6
	strh r4, [r0, #0x30]
	mov r1, r8
	str r1, [r0, #0x44]
	str r7, [r0, #0x48]
	ldr r1, [sp, #0x1c]
	str r1, [r0, #0x4c]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804CDC8: .4byte gEfxBgSemaphore
.L0804CDCC: .4byte gUnk_085D0F0C

	thumb_func_start func_fe6_0804CDD0
func_fe6_0804CDD0: @ 0x0804CDD0
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	movs r7, #0
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r5, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	blt .L0804CEC4
	ldr r1, [r5, #0x44]
	ldr r2, [r5, #0x48]
	movs r6, #0x2c
	ldrsh r3, [r5, r6]
	movs r0, #0x2e
	ldrsh r4, [r5, r0]
	subs r3, r3, r4
	movs r6, #0x30
	ldrsh r0, [r5, r6]
	subs r0, r0, r4
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	adds r6, r0, #0
	ldr r0, [r5, #0x4c]
	cmp r0, #1
	beq .L0804CE44
	cmp r0, #1
	bgt .L0804CE16
	cmp r0, #0
	beq .L0804CE1C
	b .L0804CEAA
.L0804CE16:
	cmp r0, #2
	beq .L0804CE6C
	b .L0804CEAA
.L0804CE1C:
	ldr r3, .L0804CE40 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	strb r6, [r0]
	adds r1, r3, #0
	adds r1, #0x45
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r3, #0
	b .L0804CEA6
	.align 2, 0
.L0804CE40: .4byte gDispIo
.L0804CE44:
	ldr r3, .L0804CE68 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	strb r7, [r0]
	adds r0, #1
	strb r7, [r0]
	adds r0, #1
	strb r6, [r0]
	b .L0804CEAA
	.align 2, 0
.L0804CE68: .4byte gDispIo
.L0804CE6C:
	movs r2, #0x2c
	ldrsh r3, [r5, r2]
	movs r0, #0x2e
	ldrsh r1, [r5, r0]
	subs r3, r3, r1
	movs r2, #0x30
	ldrsh r0, [r5, r2]
	subs r0, r0, r1
	str r0, [sp]
	movs r0, #0
	movs r1, #8
	movs r2, #0x10
	bl Interpolate
	ldr r4, .L0804CECC @ =gDispIo
	adds r3, r4, #0
	adds r3, #0x3c
	movs r1, #0x3f
	ldrb r2, [r3]
	ands r1, r2
	movs r2, #0x40
	orrs r1, r2
	strb r1, [r3]
	adds r1, r4, #0
	adds r1, #0x44
	strb r6, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r0, r4, #0
.L0804CEA6:
	adds r0, #0x46
	strb r7, [r0]
.L0804CEAA:
	movs r6, #0x2c
	ldrsh r1, [r5, r6]
	movs r2, #0x30
	ldrsh r0, [r5, r2]
	cmp r1, r0
	blt .L0804CEC4
	ldr r1, .L0804CED0 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r5, #0
	bl Proc_Break
.L0804CEC4:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804CECC: .4byte gDispIo
.L0804CED0: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804CED4
func_fe6_0804CED4: @ 0x0804CED4
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	mov r8, r0
	mov sb, r1
	mov sl, r2
	adds r5, r3, #0
	ldr r6, [sp, #0x1c]
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	ldr r1, .L0804CF2C @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804CF30 @ =gUnk_085D0F24
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	mov r0, r8
	str r0, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	strh r0, [r4, #0x2e]
	mov r0, sb
	str r0, [r4, #0x44]
	mov r0, sl
	str r0, [r4, #0x54]
	mov r0, r8
	bl GetAnimAnotherSide
	strh r5, [r4, #0x32]
	strh r6, [r4, #0x3a]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804CF2C: .4byte gEfxBgSemaphore
.L0804CF30: .4byte gUnk_085D0F24

	thumb_func_start func_fe6_0804CF34
func_fe6_0804CF34: @ 0x0804CF34
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	ldr r0, .L0804CFB4 @ =gUnk_Banim_0201E14C
	ldr r0, [r0]
	ldr r1, .L0804CFB8 @ =gUnk_Banim_0201E158
	mov r8, r1
	cmp r0, #0
	bne .L0804CF4E
	ldr r2, .L0804CFBC @ =gUnk_Banim_0201E298
	mov r8, r2
.L0804CF4E:
	ldr r4, [r5, #0x54]
	movs r7, #0x2e
	ldrsh r0, [r5, r7]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r7, [r0]
	adds r0, r7, #0
	bl func_fe6_08013F7C
	adds r6, r0, #0
	movs r1, #0x2e
	ldrsh r0, [r5, r1]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldr r1, .L0804CFC0 @ =0x0000FFFF
	ldrh r0, [r0, #2]
	cmp r0, r1
	beq .L0804CF78
	ldrh r0, [r5, #0x2e]
	adds r0, #1
	strh r0, [r5, #0x2e]
.L0804CF78:
	ldrh r1, [r5, #0x3a]
	subs r0, r1, r7
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r0, #0
	bge .L0804CF86
	movs r2, #0
.L0804CF86:
	adds r0, r7, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xa0
	ble .L0804CF94
	movs r1, #0xa0
.L0804CF94:
	movs r3, #0
	lsls r0, r2, #0x10
	ldr r2, [r5, #0x44]
	mov ip, r2
	asrs r0, r0, #0x10
	mov sb, r0
	lsls r0, r1, #0x10
	asrs r4, r0, #0x10
.L0804CFA4:
	cmp sb, r3
	bhi .L0804CFAC
	cmp r4, r3
	bhs .L0804CFC4
.L0804CFAC:
	movs r0, #0
	mov r7, r8
	strh r0, [r7]
	b .L0804CFF4
	.align 2, 0
.L0804CFB4: .4byte gUnk_Banim_0201E14C
.L0804CFB8: .4byte gUnk_Banim_0201E158
.L0804CFBC: .4byte gUnk_Banim_0201E298
.L0804CFC0: .4byte 0x0000FFFF
.L0804CFC4:
	ldrh r2, [r5, #0x32]
	ldrh r1, [r6]
	adds r0, r2, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r0, #0
	bge .L0804CFD4
	movs r1, #0
.L0804CFD4:
	ldrh r7, [r6, #2]
	adds r0, r2, r7
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf0
	ble .L0804CFE4
	movs r2, #0xf0
.L0804CFE4:
	lsls r1, r1, #0x10
	asrs r1, r1, #8
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	orrs r0, r1
	mov r1, r8
	strh r0, [r1]
	adds r6, #4
.L0804CFF4:
	movs r2, #2
	add r8, r2
	adds r3, #1
	cmp r3, #0x9f
	bls .L0804CFA4
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	movs r3, #0
	strh r0, [r5, #0x2c]
	movs r4, #0x2c
	ldrsh r0, [r5, r4]
	cmp r0, ip
	bne .L0804D03A
	ldr r1, .L0804D048 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	ldr r2, .L0804D04C @ =gDispIo
	adds r1, r2, #0
	adds r1, #0x3c
	movs r0, #0x3f
	ldrb r7, [r1]
	ands r0, r7
	strb r0, [r1]
	adds r1, #8
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x45
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, r5, #0
	bl Proc_Break
.L0804D03A:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D048: .4byte gEfxBgSemaphore
.L0804D04C: .4byte gDispIo

	thumb_func_start func_fe6_0804D050
func_fe6_0804D050: @ 0x0804D050
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r1, .L0804D080 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804D084 @ =gUnk_085D0F3C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #6
	movs r1, #0
	bl NewEfxQuakePure
	str r0, [r4, #0x60]
	movs r0, #0
	strh r0, [r4, #0x2c]
	strh r6, [r4, #0x2e]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D080: .4byte gEfxBgSemaphore
.L0804D084: .4byte gUnk_085D0F3C

	thumb_func_start func_fe6_0804D088
func_fe6_0804D088: @ 0x0804D088
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	ldr r5, .L0804D120 @ =gEkrBg2QuakeVec
	ldrh r1, [r5]
	ldrh r2, [r5, #2]
	movs r0, #2
	bl SetBgOffset
	ldr r4, .L0804D124 @ =gEkrBg0QuakeVec
	ldrh r0, [r5]
	ldrh r2, [r4]
	adds r1, r0, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r3, [r5, #2]
	ldrh r0, [r4, #2]
	adds r2, r3, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0
	bl SetBgOffset
	ldrh r1, [r5]
	ldrh r2, [r4]
	adds r0, r1, r2
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r3, [r5, #2]
	ldrh r2, [r4, #2]
	adds r1, r3, r2
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl func_fe6_0804392C
	ldrh r3, [r5]
	ldrh r1, [r4]
	adds r0, r3, r1
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r2, [r5, #2]
	ldrh r4, [r4, #2]
	adds r1, r2, r4
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl func_fe6_08044230
	bl GetEkrDragonStateType
	cmp r0, #0
	beq .L0804D10C
	ldrh r1, [r5]
	ldrh r2, [r5, #2]
	adds r2, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #3
	bl SetBgOffset
.L0804D10C:
	bl GetEkrDragonStateType
	cmp r0, #0
	beq .L0804D12C
	ldr r3, .L0804D128 @ =gEkrXPosReal
	ldrh r4, [r3]
	ldrh r1, [r5]
	subs r0, r4, r1
	b .L0804D134
	.align 2, 0
.L0804D120: .4byte gEkrBg2QuakeVec
.L0804D124: .4byte gEkrBg0QuakeVec
.L0804D128: .4byte gEkrXPosReal
.L0804D12C:
	ldr r3, .L0804D244 @ =gEkrXPosReal
	ldrh r1, [r3]
	ldrh r2, [r5]
	adds r0, r1, r2
.L0804D134:
	ldr r2, .L0804D248 @ =gEkrBgPosition
	ldr r1, [r2]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r1, .L0804D24C @ =gEkrYPosReal
	ldrh r4, [r1]
	ldrh r5, [r5, #2]
	subs r0, r4, r5
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	mov sb, r3
	mov sl, r1
	ldr r2, .L0804D250 @ =gEkrBg2QuakeVec
	mov r1, sb
	ldrh r1, [r1, #2]
	ldrh r3, [r2]
	adds r0, r1, r3
	ldr r4, .L0804D248 @ =gEkrBgPosition
	ldr r1, [r4]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	mov r1, sl
	ldrh r1, [r1, #2]
	ldrh r2, [r2, #2]
	subs r0, r1, r2
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	lsls r2, r6, #0x10
	asrs r2, r2, #0x10
	movs r0, #0
	bl SetEkrFrontAnimPostion
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r2, r4, #0x10
	asrs r2, r2, #0x10
	movs r0, #1
	bl SetEkrFrontAnimPostion
	mov r2, r8
	ldrh r0, [r2, #0x2c]
	adds r0, #1
	strh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	ldrh r3, [r2, #0x2e]
	lsls r1, r3, #0x10
	cmp r0, r1
	ble .L0804D236
	ldr r1, .L0804D254 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	ldr r4, .L0804D258 @ =gEkrBg0QuakeVec
	ldrh r1, [r4]
	ldrh r2, [r4, #2]
	movs r0, #0
	bl SetBgOffset
	ldrh r1, [r4]
	rsbs r0, r1, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r2, [r4, #2]
	rsbs r1, r2, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl func_fe6_0804392C
	ldrh r3, [r4]
	rsbs r0, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r4, [r4, #2]
	rsbs r1, r4, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl func_fe6_08044230
	bl GetEkrDragonStateType
	cmp r0, #0
	beq .L0804D1F4
	movs r0, #3
	movs r1, #0
	movs r2, #0x10
	bl SetBgOffset
.L0804D1F4:
	ldr r4, .L0804D248 @ =gEkrBgPosition
	ldr r0, [r4]
	mov r2, sb
	ldrh r2, [r2]
	subs r1, r2, r0
	mov r3, sb
	ldrh r3, [r3, #2]
	subs r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	mov r0, sl
	ldrh r4, [r0, #2]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r0, #0
	bl SetEkrFrontAnimPostion
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r2, r4, #0x10
	asrs r2, r2, #0x10
	movs r0, #1
	bl SetEkrFrontAnimPostion
	mov r4, r8
	ldr r0, [r4, #0x60]
	bl Proc_End
	mov r0, r8
	bl Proc_Break
.L0804D236:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D244: .4byte gEkrXPosReal
.L0804D248: .4byte gEkrBgPosition
.L0804D24C: .4byte gEkrYPosReal
.L0804D250: .4byte gEkrBg2QuakeVec
.L0804D254: .4byte gEfxBgSemaphore
.L0804D258: .4byte gEkrBg0QuakeVec

	thumb_func_start func_fe6_0804D25C
func_fe6_0804D25C: @ 0x0804D25C
	push {r4, lr}
	adds r4, r0, #0
	bl SpellFx_Begin
	bl SpellFx_SetBG1Position
	ldr r0, .L0804D27C @ =gUnk_085D0F54
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D27C: .4byte gUnk_085D0F54

	thumb_func_start func_fe6_0804D280
func_fe6_0804D280: @ 0x0804D280
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	bl GetAnimAnotherSide
	adds r4, r0, #0
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	movs r6, #0
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0804D2A6
	movs r0, #9
	ldrh r1, [r4, #0x10]
	orrs r0, r1
	strh r0, [r4, #0x10]
	b .L0804D2CE
.L0804D2A6:
	cmp r0, #0xa
	bne .L0804D2CE
	adds r0, r4, #0
	bl GetAnimNextRoundType
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq .L0804D2C4
	movs r0, #2
	ldrh r1, [r4, #0x10]
	orrs r0, r1
	strh r0, [r4, #0x10]
.L0804D2C4:
	bl SpellFx_Finish
	adds r0, r5, #0
	bl Proc_Break
.L0804D2CE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0804D2D4
func_fe6_0804D2D4: @ 0x0804D2D4
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl SpellFx_SetBG1Position
	ldr r0, .L0804D308 @ =gUnk_085D0F6C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D308: .4byte gUnk_085D0F6C

	thumb_func_start func_fe6_0804D30C
func_fe6_0804D30C: @ 0x0804D30C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	bl GetAnimAnotherSide
	adds r6, r0, #0
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0804D38A
	ldr r0, [r5, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl NewEfxFarAttackWithDistance
	ldr r0, [r5, #0x5c]
	bl func_fe6_0804D3A8
	ldrh r0, [r5, #0x2c]
	cmp r0, #1
	bne .L0804D38A
	movs r0, #9
	ldrh r1, [r6, #0x10]
	orrs r0, r1
	strh r0, [r6, #0x10]
	adds r4, r5, #0
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r6, #0
	bl StartBattleAnimHitEffectsDefault
	adds r0, r6, #0
	bl func_fe6_0805C308
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	beq .L0804D37C
	ldr r0, [r5, #0x5c]
	bl CheckRoundCrit
	cmp r0, #1
	bne .L0804D370
	adds r0, r6, #0
	bl func_fe6_08056B08
	b .L0804D37C
.L0804D370:
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804D3A0
	ldr r0, [r5, #0x5c]
	bl func_fe6_08056C3C
.L0804D37C:
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804D3A0
	adds r0, r6, #0
	bl func_fe6_0805C358
	b .L0804D3A0
.L0804D38A:
	movs r1, #0x2c
	ldrsh r0, [r5, r1]
	cmp r0, #0x46
	beq .L0804D3A0
	cmp r0, #0x50
	bne .L0804D3A0
	bl SpellFx_Finish
	adds r0, r5, #0
	bl Proc_Break
.L0804D3A0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0804D3A8
func_fe6_0804D3A8: @ 0x0804D3A8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, .L0804D3EC @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804D3F0 @ =gUnk_085D0F84
	movs r1, #3
	bl SpawnProc
	adds r6, r0, #0
	str r4, [r6, #0x5c]
	movs r0, #0
	strh r0, [r6, #0x2c]
	ldr r1, .L0804D3F4 @ =gUnk_085D4148
	ldr r2, .L0804D3F8 @ =gUnk_085D3DB0
	ldr r3, .L0804D3FC @ =gUnk_085D41A4
	ldr r0, .L0804D400 @ =gUnk_085D3E0C
	str r0, [sp]
	adds r0, r4, #0
	bl EfxCreateFrontAnim
	adds r5, r0, #0
	str r5, [r6, #0x60]
	adds r0, r4, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L0804D404
	ldrh r0, [r5, #2]
	adds r0, #0x48
	b .L0804D408
	.align 2, 0
.L0804D3EC: .4byte gEfxBgSemaphore
.L0804D3F0: .4byte gUnk_085D0F84
.L0804D3F4: .4byte gUnk_085D4148
.L0804D3F8: .4byte gUnk_085D3DB0
.L0804D3FC: .4byte gUnk_085D41A4
.L0804D400: .4byte gUnk_085D3E0C
.L0804D404:
	ldrh r0, [r5, #2]
	subs r0, #0x48
.L0804D408:
	strh r0, [r5, #2]
	ldr r0, .L0804D418 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L0804D41C
	movs r0, #0x23
	b .L0804D41E
	.align 2, 0
.L0804D418: .4byte gEkrDistanceType
.L0804D41C:
	movs r0, #0xa
.L0804D41E:
	strh r0, [r6, #0x2e]
	ldr r0, [r6, #0x5c]
	ldr r1, [r6, #0x60]
	bl func_fe6_0804D590
	str r0, [r6, #0x64]
	ldr r0, .L0804D444 @ =gUnk_0811B3E8
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0804D448 @ =gUnk_0811AFE8
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D444: .4byte gUnk_0811B3E8
.L0804D448: .4byte gUnk_0811AFE8

	thumb_func_start func_fe6_0804D44C
func_fe6_0804D44C: @ 0x0804D44C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L0804D49E
	ldr r1, .L0804D48C @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	ldr r0, [r4, #0x60]
	bl BasRemove
	ldr r0, .L0804D490 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L0804D498
	ldr r0, .L0804D494 @ =gUnk_Banim_02017750
	movs r1, #1
	str r1, [r0]
	ldr r0, [r4, #0x64]
	bl Proc_End
	adds r0, r4, #0
	bl Proc_End
	b .L0804D49E
	.align 2, 0
.L0804D48C: .4byte gEfxBgSemaphore
.L0804D490: .4byte gEkrDistanceType
.L0804D494: .4byte gUnk_Banim_02017750
.L0804D498:
	adds r0, r4, #0
	bl Proc_Break
.L0804D49E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0804D4A4
func_fe6_0804D4A4: @ 0x0804D4A4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0804D4C8 @ =gUnk_Banim_0201774C
	movs r0, #0
	str r0, [r1]
	ldr r0, [r4, #0x64]
	bl Proc_End
	ldr r0, [r4, #0x5c]
	bl func_fe6_0804D4CC
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D4C8: .4byte gUnk_Banim_0201774C

	thumb_func_start func_fe6_0804D4CC
func_fe6_0804D4CC: @ 0x0804D4CC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, .L0804D50C @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804D510 @ =gUnk_085D0FA4
	movs r1, #3
	bl SpawnProc
	adds r6, r0, #0
	str r4, [r6, #0x5c]
	movs r0, #0
	strh r0, [r6, #0x2c]
	ldr r3, .L0804D514 @ =gUnk_085D41C4
	ldr r2, .L0804D518 @ =gUnk_085D3E2C
	str r2, [sp]
	adds r0, r4, #0
	adds r1, r3, #0
	bl EfxCreateFrontAnim
	adds r5, r0, #0
	str r5, [r6, #0x60]
	adds r0, r4, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L0804D51C
	ldrh r0, [r5, #2]
	adds r0, #0x48
	b .L0804D520
	.align 2, 0
.L0804D50C: .4byte gEfxBgSemaphore
.L0804D510: .4byte gUnk_085D0FA4
.L0804D514: .4byte gUnk_085D41C4
.L0804D518: .4byte gUnk_085D3E2C
.L0804D51C:
	ldrh r0, [r5, #2]
	subs r0, #0x48
.L0804D520:
	strh r0, [r5, #2]
	ldr r0, .L0804D548 @ =gUnk_0811B3E8
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0804D54C @ =gUnk_0811AFE8
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	ldr r0, [r6, #0x5c]
	ldr r1, [r6, #0x60]
	bl func_fe6_0804D590
	str r0, [r6, #0x64]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D548: .4byte gUnk_0811B3E8
.L0804D54C: .4byte gUnk_0811AFE8

	thumb_func_start func_fe6_0804D550
func_fe6_0804D550: @ 0x0804D550
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x11
	bne .L0804D582
	ldr r1, .L0804D588 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	ldr r1, .L0804D58C @ =gUnk_Banim_02017750
	movs r0, #1
	str r0, [r1]
	ldr r0, [r4, #0x64]
	bl Proc_End
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L0804D582:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D588: .4byte gEfxBgSemaphore
.L0804D58C: .4byte gUnk_Banim_02017750

	thumb_func_start func_fe6_0804D590
func_fe6_0804D590: @ 0x0804D590
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	ldr r1, .L0804D5CC @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804D5D0 @ =gUnk_085D0FBC
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r6, [r4, #0x5c]
	str r5, [r4, #0x60]
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #1
	strh r0, [r4, #0x2e]
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #2
	ldrsh r2, [r6, r0]
	movs r0, #0xcd
	movs r3, #1
	bl func_fe6_0805C804
	adds r0, r4, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
.L0804D5CC: .4byte gEfxBgSemaphore
.L0804D5D0: .4byte gUnk_085D0FBC

	thumb_func_start func_fe6_0804D5D4
func_fe6_0804D5D4: @ 0x0804D5D4
	ldr r1, .L0804D5E0 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
.L0804D5E0: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804D5E4
func_fe6_0804D5E4: @ 0x0804D5E4
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #8
	bne .L0804D626
	ldr r0, [r4, #0x60]
	bl func_fe6_0805C76C
	adds r2, r0, #0
	ldr r0, [r4, #0x60]
	ldrh r0, [r0, #2]
	adds r2, r0, r2
	movs r1, #0x80
	lsls r1, r1, #1
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	movs r0, #0xcd
	movs r3, #1
	bl func_fe6_0805C804
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldrh r1, [r4, #0x2e]
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	cmp r0, #8
	bgt .L0804D626
	adds r0, r1, #1
	strh r0, [r4, #0x2e]
.L0804D626:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0804D62C
func_fe6_0804D62C: @ 0x0804D62C
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl SpellFx_SetBG1Position
	ldr r0, .L0804D660 @ =gUnk_085D0FDC
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D660: .4byte gUnk_085D0FDC

	thumb_func_start func_fe6_0804D664
func_fe6_0804D664: @ 0x0804D664
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	bl GetAnimAnotherSide
	adds r6, r0, #0
	bl EfxGetCamMovDuration
	adds r4, r0, #0
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0804D6FA
	ldr r0, [r5, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl NewEfxFarAttackWithDistance
	ldr r0, [r5, #0x5c]
	bl func_fe6_0804D728
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r5, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xcc
	movs r3, #1
	bl func_fe6_0805C804
	ldrh r0, [r5, #0x2c]
	cmp r0, #1
	bne .L0804D6FA
	movs r0, #9
	ldrh r1, [r6, #0x10]
	orrs r0, r1
	strh r0, [r6, #0x10]
	adds r4, r5, #0
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r6, #0
	bl StartBattleAnimHitEffectsDefault
	adds r0, r6, #0
	bl func_fe6_0805C308
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	beq .L0804D6EC
	ldr r0, [r5, #0x5c]
	bl CheckRoundCrit
	cmp r0, #1
	bne .L0804D6E0
	adds r0, r6, #0
	bl func_fe6_08056B08
	b .L0804D6EC
.L0804D6E0:
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804D720
	ldr r0, [r5, #0x5c]
	bl func_fe6_08056C3C
.L0804D6EC:
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804D720
	adds r0, r6, #0
	bl func_fe6_0805C358
	b .L0804D720
.L0804D6FA:
	movs r3, #0x2c
	ldrsh r1, [r5, r3]
	adds r0, r4, #0
	adds r0, #9
	cmp r1, r0
	bne .L0804D70E
	ldr r0, [r5, #0x5c]
	bl GetAnimAnotherSide
	b .L0804D720
.L0804D70E:
	adds r0, r4, #0
	adds r0, #0xa
	cmp r1, r0
	bne .L0804D720
	bl SpellFx_Finish
	adds r0, r5, #0
	bl Proc_Break
.L0804D720:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0804D728
func_fe6_0804D728: @ 0x0804D728
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L0804D770 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804D774 @ =gUnk_085D0FF4
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r1, .L0804D778 @ =gUnk_085D42F0
	ldr r2, .L0804D77C @ =gUnk_085D4264
	ldr r3, .L0804D780 @ =gUnk_085D4300
	ldr r0, .L0804D784 @ =gUnk_085D4274
	str r0, [sp]
	adds r0, r5, #0
	bl EfxCreateFrontAnim
	str r0, [r4, #0x60]
	ldr r0, .L0804D788 @ =gUnk_0811B3E8
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0804D78C @ =gUnk_0811B408
	movs r1, #0x60
	bl SpellFx_RegisterObjGfx
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D770: .4byte gEfxBgSemaphore
.L0804D774: .4byte gUnk_085D0FF4
.L0804D778: .4byte gUnk_085D42F0
.L0804D77C: .4byte gUnk_085D4264
.L0804D780: .4byte gUnk_085D4300
.L0804D784: .4byte gUnk_085D4274
.L0804D788: .4byte gUnk_0811B3E8
.L0804D78C: .4byte gUnk_0811B408

	thumb_func_start func_fe6_0804D790
func_fe6_0804D790: @ 0x0804D790
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bne .L0804D7B6
	ldr r0, .L0804D7BC @ =gEfxBgSemaphore
	ldr r1, [r0]
	subs r1, #1
	str r1, [r0]
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L0804D7B6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D7BC: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804D7C0
func_fe6_0804D7C0: @ 0x0804D7C0
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl SpellFx_SetBG1Position
	ldr r0, .L0804D810 @ =gUnk_085D100C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	adds r0, r5, #0
	movs r1, #0
	bl func_fe6_0804DBAC
	ldr r0, .L0804D814 @ =gUnk_0811B674
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0804D818 @ =gUnk_0811B444
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D810: .4byte gUnk_085D100C
.L0804D814: .4byte gUnk_0811B674
.L0804D818: .4byte gUnk_0811B444

	thumb_func_start func_fe6_0804D81C
func_fe6_0804D81C: @ 0x0804D81C
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl SpellFx_SetBG1Position
	ldr r0, .L0804D86C @ =gUnk_085D100C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	adds r0, r5, #0
	movs r1, #1
	bl func_fe6_0804DBAC
	ldr r0, .L0804D870 @ =gUnk_0811B8B0
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0804D874 @ =gUnk_0811B694
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D86C: .4byte gUnk_085D100C
.L0804D870: .4byte gUnk_0811B8B0
.L0804D874: .4byte gUnk_0811B694

	thumb_func_start func_fe6_0804D878
func_fe6_0804D878: @ 0x0804D878
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl SpellFx_SetBG1Position
	ldr r0, .L0804D8C8 @ =gUnk_085D100C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	adds r0, r5, #0
	movs r1, #0
	bl func_fe6_0804DBAC
	ldr r0, .L0804D8CC @ =gUnk_0811BAE8
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0804D8D0 @ =gUnk_0811B8D0
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D8C8: .4byte gUnk_085D100C
.L0804D8CC: .4byte gUnk_0811BAE8
.L0804D8D0: .4byte gUnk_0811B8D0

	thumb_func_start func_fe6_0804D8D4
func_fe6_0804D8D4: @ 0x0804D8D4
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl SpellFx_SetBG1Position
	ldr r0, .L0804D924 @ =gUnk_085D100C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	adds r0, r5, #0
	movs r1, #1
	bl func_fe6_0804DBAC
	ldr r0, .L0804D928 @ =gUnk_0811BD24
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0804D92C @ =gUnk_0811BB08
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D924: .4byte gUnk_085D100C
.L0804D928: .4byte gUnk_0811BD24
.L0804D92C: .4byte gUnk_0811BB08

	thumb_func_start func_fe6_0804D930
func_fe6_0804D930: @ 0x0804D930
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl SpellFx_SetBG1Position
	ldr r0, .L0804D980 @ =gUnk_085D100C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	adds r0, r5, #0
	movs r1, #1
	bl func_fe6_0804DBAC
	ldr r0, .L0804D984 @ =gUnk_0811BF70
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0804D988 @ =gUnk_0811BD44
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D980: .4byte gUnk_085D100C
.L0804D984: .4byte gUnk_0811BF70
.L0804D988: .4byte gUnk_0811BD44

	thumb_func_start func_fe6_0804D98C
func_fe6_0804D98C: @ 0x0804D98C
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl SpellFx_SetBG1Position
	ldr r0, .L0804D9DC @ =gUnk_085D100C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	adds r0, r5, #0
	movs r1, #1
	bl func_fe6_0804DBAC
	ldr r0, .L0804D9E0 @ =gUnk_0811C1D8
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0804D9E4 @ =gUnk_0811BF90
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804D9DC: .4byte gUnk_085D100C
.L0804D9E0: .4byte gUnk_0811C1D8
.L0804D9E4: .4byte gUnk_0811BF90

	thumb_func_start func_fe6_0804D9E8
func_fe6_0804D9E8: @ 0x0804D9E8
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl SpellFx_SetBG1Position
	ldr r0, .L0804DA38 @ =gUnk_085D100C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	adds r0, r5, #0
	movs r1, #1
	bl func_fe6_0804DBAC
	ldr r0, .L0804DA3C @ =gUnk_0811C430
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0804DA40 @ =gUnk_0811C1F8
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804DA38: .4byte gUnk_085D100C
.L0804DA3C: .4byte gUnk_0811C430
.L0804DA40: .4byte gUnk_0811C1F8

	thumb_func_start func_fe6_0804DA44
func_fe6_0804DA44: @ 0x0804DA44
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl SpellFx_SetBG1Position
	ldr r0, .L0804DA94 @ =gUnk_085D100C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	adds r0, r5, #0
	movs r1, #1
	bl func_fe6_0804DBAC
	ldr r0, .L0804DA98 @ =gUnk_0811C6B4
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0804DA9C @ =gUnk_0811C450
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804DA94: .4byte gUnk_085D100C
.L0804DA98: .4byte gUnk_0811C6B4
.L0804DA9C: .4byte gUnk_0811C450

	thumb_func_start func_fe6_0804DAA0
func_fe6_0804DAA0: @ 0x0804DAA0
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl SpellFx_SetBG1Position
	ldr r0, .L0804DAF0 @ =gUnk_085D100C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	adds r0, r5, #0
	movs r1, #1
	bl func_fe6_0804DBAC
	ldr r0, .L0804DAF4 @ =gUnk_0811C944
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0804DAF8 @ =gUnk_0811C6D4
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804DAF0: .4byte gUnk_085D100C
.L0804DAF4: .4byte gUnk_0811C944
.L0804DAF8: .4byte gUnk_0811C6D4

	thumb_func_start func_fe6_0804DAFC
func_fe6_0804DAFC: @ 0x0804DAFC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0804DB86
	ldr r0, [r5, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl NewEfxFarAttackWithDistance
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r5, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xca
	movs r3, #1
	bl func_fe6_0805C804
	ldrh r0, [r5, #0x2c]
	cmp r0, #1
	bne .L0804DB86
	ldr r0, [r5, #0x5c]
	bl GetAnimAnotherSide
	adds r6, r0, #0
	movs r0, #9
	ldrh r1, [r6, #0x10]
	orrs r0, r1
	strh r0, [r6, #0x10]
	adds r4, r5, #0
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r6, #0
	bl StartBattleAnimHitEffectsDefault
	adds r0, r6, #0
	bl func_fe6_0805C308
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	beq .L0804DB78
	ldr r0, [r5, #0x5c]
	bl CheckRoundCrit
	cmp r0, #1
	bne .L0804DB6C
	adds r0, r6, #0
	bl func_fe6_08056B08
	b .L0804DB78
.L0804DB6C:
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804DBA4
	ldr r0, [r5, #0x5c]
	bl func_fe6_08056C3C
.L0804DB78:
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804DBA4
	adds r0, r6, #0
	bl func_fe6_0805C358
	b .L0804DBA4
.L0804DB86:
	movs r3, #0x2c
	ldrsh r0, [r5, r3]
	cmp r0, #0xe
	bne .L0804DB96
	ldr r0, [r5, #0x5c]
	bl GetAnimAnotherSide
	b .L0804DBA4
.L0804DB96:
	cmp r0, #0x10
	bne .L0804DBA4
	bl SpellFx_Finish
	adds r0, r5, #0
	bl Proc_Break
.L0804DBA4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0804DBAC
func_fe6_0804DBAC: @ 0x0804DBAC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r1, .L0804DBD8 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804DBDC @ =gUnk_085D1024
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r6, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	cmp r4, #0
	bne .L0804DBE8
	ldr r2, .L0804DBE0 @ =gUnk_085D44E4
	ldr r3, .L0804DBE4 @ =gUnk_085D4738
	b .L0804DBEC
	.align 2, 0
.L0804DBD8: .4byte gEfxBgSemaphore
.L0804DBDC: .4byte gUnk_085D1024
.L0804DBE0: .4byte gUnk_085D44E4
.L0804DBE4: .4byte gUnk_085D4738
.L0804DBE8:
	ldr r2, .L0804DC0C @ =gUnk_085D4998
	ldr r3, .L0804DC10 @ =gUnk_085D4BF8
.L0804DBEC:
	str r2, [sp]
	adds r0, r6, #0
	adds r1, r3, #0
	bl EfxCreateFrontAnim
	adds r4, r0, #0
	str r4, [r5, #0x60]
	adds r0, r6, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L0804DC14
	ldrh r0, [r4, #2]
	adds r0, #0x38
	b .L0804DC18
	.align 2, 0
.L0804DC0C: .4byte gUnk_085D4998
.L0804DC10: .4byte gUnk_085D4BF8
.L0804DC14:
	ldrh r0, [r4, #2]
	subs r0, #0x38
.L0804DC18:
	strh r0, [r4, #2]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0804DC24
func_fe6_0804DC24: @ 0x0804DC24
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc
	bne .L0804DC4A
	ldr r0, .L0804DC50 @ =gEfxBgSemaphore
	ldr r1, [r0]
	subs r1, #1
	str r1, [r0]
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L0804DC4A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804DC50: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804DC54
func_fe6_0804DC54: @ 0x0804DC54
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl SpellFx_SetBG1Position
	ldr r0, .L0804DC88 @ =gUnk_085D103C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804DC88: .4byte gUnk_085D103C

	thumb_func_start func_fe6_0804DC8C
func_fe6_0804DC8C: @ 0x0804DC8C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	bl GetAnimAnotherSide
	adds r4, r0, #0
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	movs r6, #0
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x27
	bne .L0804DCC4
	adds r0, r4, #0
	bl func_fe6_0804DD38
	adds r0, r4, #0
	bl func_fe6_0804DDC8
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #2
	ldrsh r2, [r4, r0]
	movs r0, #0xef
	movs r3, #1
	bl func_fe6_0805C804
.L0804DCC4:
	movs r1, #0x2c
	ldrsh r0, [r5, r1]
	cmp r0, #0x45
	bne .L0804DD1C
	movs r0, #9
	ldrh r1, [r4, #0x10]
	orrs r0, r1
	strh r0, [r4, #0x10]
	adds r0, r5, #0
	adds r0, #0x29
	ldrb r1, [r0]
	adds r0, r4, #0
	bl StartBattleAnimStatusChgHitEffects
	adds r0, r4, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L0804DD00
	ldr r0, .L0804DCF8 @ =gpEfxUnitPaletteBackup
	ldr r0, [r0]
	ldr r1, .L0804DCFC @ =gPal+0x2E0
	movs r2, #8
	bl CpuFastSet
	b .L0804DD0C
	.align 2, 0
.L0804DCF8: .4byte gpEfxUnitPaletteBackup
.L0804DCFC: .4byte gPal+0x2E0
.L0804DD00:
	ldr r0, .L0804DD14 @ =gpEfxUnitPaletteBackup
	ldr r0, [r0, #4]
	ldr r1, .L0804DD18 @ =gPal+0x320
	movs r2, #8
	bl CpuFastSet
.L0804DD0C:
	adds r0, r4, #0
	bl EnableEfxStatusUnits
	b .L0804DD32
	.align 2, 0
.L0804DD14: .4byte gpEfxUnitPaletteBackup
.L0804DD18: .4byte gPal+0x320
.L0804DD1C:
	cmp r0, #0x64
	bne .L0804DD32
	movs r0, #2
	ldrh r1, [r4, #0x10]
	orrs r0, r1
	strh r0, [r4, #0x10]
	bl SpellFx_Finish
	adds r0, r5, #0
	bl Proc_Break
.L0804DD32:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0804DD38
func_fe6_0804DD38: @ 0x0804DD38
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, .L0804DD80 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804DD84 @ =gUnk_085D1054
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r0, .L0804DD88 @ =gUnk_0811CAF8
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	ldr r0, .L0804DD8C @ =gUnk_0811CD14
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	ldr r0, [r4, #0x5c]
	ldr r2, .L0804DD90 @ =gUnk_0811D0D4
	adds r1, r2, #0
	bl SpellFx_WriteBgMap
	bl SpellFx_SetBG1Position
	bl SpellFx_SetSomeColorEffect
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804DD80: .4byte gEfxBgSemaphore
.L0804DD84: .4byte gUnk_085D1054
.L0804DD88: .4byte gUnk_0811CAF8
.L0804DD8C: .4byte gUnk_0811CD14
.L0804DD90: .4byte gUnk_0811D0D4

	thumb_func_start func_fe6_0804DD94
func_fe6_0804DD94: @ 0x0804DD94
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1f
	bne .L0804DDBC
	bl SpellFx_ClearBG1
	bl SpellFx_ClearColorEffects
	ldr r1, .L0804DDC4 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804DDBC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804DDC4: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804DDC8
func_fe6_0804DDC8: @ 0x0804DDC8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0804DDF4 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804DDF8 @ =gUnk_085D106C
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L0804DDFC @ =gUnk_08119CDC
	str r1, [r0, #0x48]
	ldr r1, .L0804DE00 @ =gUnk_0811CD14
	str r1, [r0, #0x4c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804DDF4: .4byte gEfxBgSemaphore
.L0804DDF8: .4byte gUnk_085D106C
.L0804DDFC: .4byte gUnk_08119CDC
.L0804DE00: .4byte gUnk_0811CD14

	thumb_func_start func_fe6_0804DE04
func_fe6_0804DE04: @ 0x0804DE04
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L0804DE2A
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	b .L0804DE40
.L0804DE2A:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L0804DE40
	ldr r1, .L0804DE48 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804DE40:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804DE48: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804DE4C
func_fe6_0804DE4C: @ 0x0804DE4C
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl SpellFx_SetBG1Position
	ldr r0, .L0804DE80 @ =gUnk_085D108C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804DE80: .4byte gUnk_085D108C

	thumb_func_start func_fe6_0804DE84
func_fe6_0804DE84: @ 0x0804DE84
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	bl GetAnimAnotherSide
	adds r4, r0, #0
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	movs r6, #0
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x19
	bne .L0804DEBC
	adds r0, r4, #0
	bl func_fe6_0804DD38
	adds r0, r4, #0
	bl func_fe6_0804DDC8
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #2
	ldrsh r2, [r4, r0]
	movs r0, #0xef
	movs r3, #1
	bl func_fe6_0805C804
.L0804DEBC:
	movs r1, #0x2c
	ldrsh r0, [r5, r1]
	cmp r0, #0x37
	bne .L0804DF14
	movs r0, #9
	ldrh r1, [r4, #0x10]
	orrs r0, r1
	strh r0, [r4, #0x10]
	adds r0, r5, #0
	adds r0, #0x29
	ldrb r1, [r0]
	adds r0, r4, #0
	bl StartBattleAnimStatusChgHitEffects
	adds r0, r4, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L0804DEF8
	ldr r0, .L0804DEF0 @ =gpEfxUnitPaletteBackup
	ldr r0, [r0]
	ldr r1, .L0804DEF4 @ =gPal+0x2E0
	movs r2, #8
	bl CpuFastSet
	b .L0804DF04
	.align 2, 0
.L0804DEF0: .4byte gpEfxUnitPaletteBackup
.L0804DEF4: .4byte gPal+0x2E0
.L0804DEF8:
	ldr r0, .L0804DF0C @ =gpEfxUnitPaletteBackup
	ldr r0, [r0, #4]
	ldr r1, .L0804DF10 @ =gPal+0x320
	movs r2, #8
	bl CpuFastSet
.L0804DF04:
	adds r0, r4, #0
	bl EnableEfxStatusUnits
	b .L0804DF2A
	.align 2, 0
.L0804DF0C: .4byte gpEfxUnitPaletteBackup
.L0804DF10: .4byte gPal+0x320
.L0804DF14:
	cmp r0, #0x64
	bne .L0804DF2A
	movs r0, #2
	ldrh r1, [r4, #0x10]
	orrs r0, r1
	strh r0, [r4, #0x10]
	bl SpellFx_Finish
	adds r0, r5, #0
	bl Proc_Break
.L0804DF2A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0804DF30
func_fe6_0804DF30: @ 0x0804DF30
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl SpellFx_SetBG1Position
	ldr r0, .L0804DF7C @ =gUnk_085D10A4
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r1, r4, #0
	adds r1, #0x29
	strb r0, [r1]
	movs r0, #0x9b
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	movs r3, #1
	bl func_fe6_0805C804
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804DF7C: .4byte gUnk_085D10A4

	thumb_func_start func_fe6_0804DF80
func_fe6_0804DF80: @ 0x0804DF80
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	bl GetAnimAnotherSide
	adds r6, r0, #0
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bne .L0804DFA6
	ldr r0, [r5, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl NewEfxFarAttackWithDistance
	b .L0804E038
.L0804DFA6:
	movs r1, #0x2c
	ldrsh r0, [r5, r1]
	cmp r0, #0x22
	bne .L0804DFC8
	ldr r0, .L0804DFC4 @ =0x00000137
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r5, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	movs r3, #1
	bl func_fe6_0805C804
	b .L0804E038
	.align 2, 0
.L0804DFC4: .4byte 0x00000137
.L0804DFC8:
	cmp r0, #0x2a
	bne .L0804DFD4
	adds r0, r6, #0
	bl func_fe6_0804E040
	b .L0804E038
.L0804DFD4:
	cmp r0, #0x2d
	bne .L0804E026
	movs r0, #9
	ldrh r1, [r6, #0x10]
	orrs r0, r1
	strh r0, [r6, #0x10]
	adds r4, r5, #0
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r6, #0
	bl StartBattleAnimHitEffectsDefault
	adds r0, r6, #0
	bl func_fe6_0805C308
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	beq .L0804E018
	ldr r0, [r5, #0x5c]
	bl CheckRoundCrit
	cmp r0, #1
	bne .L0804E00C
	adds r0, r6, #0
	bl func_fe6_08056B08
	b .L0804E018
.L0804E00C:
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804E038
	ldr r0, [r5, #0x5c]
	bl func_fe6_08056C3C
.L0804E018:
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804E038
	adds r0, r6, #0
	bl func_fe6_0805C358
	b .L0804E038
.L0804E026:
	cmp r0, #0x3e
	beq .L0804E038
	cmp r0, #0x40
	bne .L0804E038
	bl SpellFx_Finish
	adds r0, r5, #0
	bl Proc_Break
.L0804E038:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0804E040
func_fe6_0804E040: @ 0x0804E040
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L0804E094 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804E098 @ =gUnk_085D10BC
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r7, #0
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r3, .L0804E09C @ =gUnk_085D4CFC
	ldr r2, .L0804E0A0 @ =gUnk_085D4D98
	str r2, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	bl EfxCreateFrontAnim
	adds r6, r0, #0
	str r6, [r4, #0x60]
	ldrh r0, [r6, #4]
	adds r0, #0x10
	strh r0, [r6, #4]
	movs r0, #0xc0
	lsls r0, r0, #4
	ldrh r1, [r6, #8]
	ands r0, r1
	strh r0, [r6, #8]
	adds r0, r5, #0
	bl GetAnimPosition
	cmp r0, #1
	bne .L0804E0A4
	movs r1, #0xe4
	lsls r1, r1, #7
	b .L0804E0A8
	.align 2, 0
.L0804E094: .4byte gEfxBgSemaphore
.L0804E098: .4byte gUnk_085D10BC
.L0804E09C: .4byte gUnk_085D4CFC
.L0804E0A0: .4byte gUnk_085D4D98
.L0804E0A4:
	movs r1, #0x93
	lsls r1, r1, #8
.L0804E0A8:
	adds r0, r1, #0
	ldrh r1, [r6, #8]
	orrs r0, r1
	strh r0, [r6, #8]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0804E0B8
func_fe6_0804E0B8: @ 0x0804E0B8
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xa
	ble .L0804E0DE
	ldr r0, [r4, #0x60]
	bl BasRemove
	ldr r1, .L0804E0E4 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804E0DE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E0E4: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804E0E8
func_fe6_0804E0E8: @ 0x0804E0E8
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl func_fe6_08047300
	bl SpellFx_SetBG1Position
	ldr r0, .L0804E120 @ =gUnk_085D10D4
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E120: .4byte gUnk_085D10D4

	thumb_func_start func_fe6_0804E124
func_fe6_0804E124: @ 0x0804E124
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	adds r5, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0804E148
	ldr r0, [r4, #0x5c]
	movs r1, #6
	bl NewEfxFlashBgWhite
	b .L0804E1BA
.L0804E148:
	cmp r0, #6
	bne .L0804E180
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl NewEfxFarAttackWithDistance
	adds r0, r5, #0
	movs r1, #9
	bl func_fe6_0804E1C0
	adds r0, r5, #0
	movs r1, #9
	bl func_fe6_0804E2B4
	adds r0, r5, #0
	bl func_fe6_0804E3C0
	movs r0, #0x86
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl func_fe6_0805C804
	b .L0804E1BA
.L0804E180:
	cmp r0, #0xa
	bne .L0804E1A4
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl StartBattleAnimHitEffectsDefault
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804E1BA
	adds r0, r5, #0
	bl func_fe6_0805C358
	b .L0804E1BA
.L0804E1A4:
	cmp r0, #0x19
	beq .L0804E1BA
	cmp r0, #0x1e
	bne .L0804E1BA
	bl SpellFx_Finish
	bl func_fe6_08047358
	adds r0, r4, #0
	bl Proc_Break
.L0804E1BA:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0804E1C0
func_fe6_0804E1C0: @ 0x0804E1C0
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r1, .L0804E220 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804E224 @ =gUnk_085D10EC
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	strh r6, [r4, #0x2e]
	ldr r0, .L0804E228 @ =gUnk_0811F22C
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	ldr r0, .L0804E22C @ =gUnk_0811E36C
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	ldr r0, .L0804E230 @ =gUnk_0811F32C
	ldr r5, .L0804E234 @ =gEkrTsaBuffer
	adds r1, r5, #0
	bl LZ77UnCompWram
	ldr r0, [r4, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L0804E23C
	ldr r1, .L0804E238 @ =gBg1Tm
	movs r0, #1
	str r0, [sp]
	adds r0, #0xff
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x14
	bl EfxTmCpyBG
	b .L0804E250
	.align 2, 0
.L0804E220: .4byte gEfxBgSemaphore
.L0804E224: .4byte gUnk_085D10EC
.L0804E228: .4byte gUnk_0811F22C
.L0804E22C: .4byte gUnk_0811E36C
.L0804E230: .4byte gUnk_0811F32C
.L0804E234: .4byte gEkrTsaBuffer
.L0804E238: .4byte gBg1Tm
.L0804E23C:
	ldr r1, .L0804E278 @ =gBg1Tm
	movs r0, #1
	str r0, [sp]
	adds r0, #0xff
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x14
	bl EfxTmCpyBgHFlip
.L0804E250:
	movs r0, #2
	bl EnableBgSync
	bl SpellFx_SetSomeColorEffect
	ldr r2, .L0804E27C @ =gDispIo
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrb r1, [r2, #1]
	ands r0, r1
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r2, #1]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E278: .4byte gBg1Tm
.L0804E27C: .4byte gDispIo

	thumb_func_start func_fe6_0804E280
func_fe6_0804E280: @ 0x0804E280
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L0804E2AA
	bl SpellFx_ClearBG1
	ldr r1, .L0804E2B0 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	adds r0, r4, #0
	bl Proc_Break
.L0804E2AA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E2B0: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804E2B4
func_fe6_0804E2B4: @ 0x0804E2B4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L0804E2E4 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804E2E8 @ =gUnk_085D1104
	movs r1, #3
	bl SpawnProc
	adds r6, r0, #0
	str r4, [r6, #0x5c]
	movs r0, #0
	strh r0, [r6, #0x2c]
	strh r5, [r6, #0x2e]
	adds r0, r4, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L0804E2EC
	movs r0, #0xd8
	b .L0804E2F0
	.align 2, 0
.L0804E2E4: .4byte gEfxBgSemaphore
.L0804E2E8: .4byte gUnk_085D1104
.L0804E2EC:
	movs r0, #0xd8
	rsbs r0, r0, #0
.L0804E2F0:
	str r0, [r6, #0x44]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0804E2F8
func_fe6_0804E2F8: @ 0x0804E2F8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r2, [r6, #0x44]
	movs r0, #0x2c
	ldrsh r3, [r6, r0]
	movs r1, #0x2e
	ldrsh r0, [r6, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	bl Interpolate
	ldr r4, .L0804E330 @ =gDispIo
	strh r0, [r4, #0x20]
	ldr r0, [r6, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L0804E334
	ldrh r4, [r4, #0x20]
	lsrs r0, r4, #3
	adds r7, r0, #0
	adds r7, #0x1e
	b .L0804E33A
	.align 2, 0
.L0804E330: .4byte gDispIo
.L0804E334:
	ldrh r4, [r4, #0x20]
	lsrs r0, r4, #3
	subs r7, r0, #1
.L0804E33A:
	movs r2, #0x1f
	mov r8, r2
	adds r0, r7, #0
	ands r0, r2
	lsls r0, r0, #1
	ldr r5, .L0804E3B8 @ =gBg1Tm
	adds r0, r0, r5
	movs r4, #0x80
	lsls r4, r4, #1
	str r4, [sp]
	movs r1, #1
	movs r2, #0x14
	movs r3, #1
	bl FillBGRect
	adds r0, r7, #1
	mov r1, r8
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r5
	str r4, [sp]
	movs r1, #1
	movs r2, #0x14
	movs r3, #1
	bl FillBGRect
	adds r0, r7, #2
	mov r2, r8
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r5
	str r4, [sp]
	movs r1, #1
	movs r2, #0x14
	movs r3, #1
	bl FillBGRect
	movs r0, #2
	bl EnableBgSync
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r6, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0804E3AC
	ldr r1, .L0804E3BC @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearBG1
	adds r0, r6, #0
	bl Proc_Break
.L0804E3AC:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E3B8: .4byte gBg1Tm
.L0804E3BC: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804E3C0
func_fe6_0804E3C0: @ 0x0804E3C0
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0804E3EC @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804E3F0 @ =gUnk_085D111C
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L0804E3F4 @ =gUnk_08119D56
	str r1, [r0, #0x48]
	ldr r1, .L0804E3F8 @ =gUnk_0811F22C
	str r1, [r0, #0x4c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E3EC: .4byte gEfxBgSemaphore
.L0804E3F0: .4byte gUnk_085D111C
.L0804E3F4: .4byte gUnk_08119D56
.L0804E3F8: .4byte gUnk_0811F22C

	thumb_func_start func_fe6_0804E3FC
func_fe6_0804E3FC: @ 0x0804E3FC
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L0804E422
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	b .L0804E43C
.L0804E422:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L0804E43C
	bl SpellFx_ClearColorEffects
	ldr r1, .L0804E444 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804E43C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E444: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804E448
func_fe6_0804E448: @ 0x0804E448
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl func_fe6_08047300
	bl SpellFx_SetBG1Position
	ldr r0, .L0804E480 @ =gUnk_085D113C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E480: .4byte gUnk_085D113C

	thumb_func_start func_fe6_0804E484
func_fe6_0804E484: @ 0x0804E484
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	adds r5, r0, #0
	bl EfxGetCamMovDuration
	adds r6, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r7, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0804E4B2
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl NewEfxFarAttackWithDistance
.L0804E4B2:
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	adds r0, r6, #1
	cmp r1, r0
	bne .L0804E500
	ldr r0, .L0804E4FC @ =0x0000010D
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl func_fe6_0805C804
	adds r0, r5, #0
	bl func_fe6_0804E540
	ldr r0, [r4, #0x5c]
	movs r1, #6
	bl NewEfxFlashBgWhite
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl StartBattleAnimHitEffectsDefault
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804E536
	adds r0, r5, #0
	bl func_fe6_0805C358
	b .L0804E536
	.align 2, 0
.L0804E4FC: .4byte 0x0000010D
.L0804E500:
	adds r0, r6, #0
	adds r0, #0x1c
	cmp r1, r0
	bne .L0804E51A
	str r7, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0xe
	movs r3, #0x10
	bl func_fe6_0804CD88
	b .L0804E536
.L0804E51A:
	adds r0, r6, #0
	adds r0, #0x32
	cmp r1, r0
	beq .L0804E536
	adds r0, #5
	cmp r1, r0
	bne .L0804E536
	bl SpellFx_Finish
	bl func_fe6_08047358
	adds r0, r4, #0
	bl Proc_Break
.L0804E536:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0804E540
func_fe6_0804E540: @ 0x0804E540
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L0804E598 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804E59C @ =gUnk_085D1154
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x34
	strh r0, [r4, #0x2e]
	adds r0, r5, #0
	bl GetAnimPosition
	ldr r3, .L0804E5A0 @ =gUnk_085D6E78
	cmp r0, #0
	bne .L0804E570
	ldr r3, .L0804E5A4 @ =gUnk_085D6218
.L0804E570:
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	str r0, [r4, #0x60]
	ldr r0, .L0804E5A8 @ =gUnk_081203F4
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0804E5AC @ =gUnk_0811F6F4
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E598: .4byte gEfxBgSemaphore
.L0804E59C: .4byte gUnk_085D1154
.L0804E5A0: .4byte gUnk_085D6E78
.L0804E5A4: .4byte gUnk_085D6218
.L0804E5A8: .4byte gUnk_081203F4
.L0804E5AC: .4byte gUnk_0811F6F4

	thumb_func_start func_fe6_0804E5B0
func_fe6_0804E5B0: @ 0x0804E5B0
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0804E5D8
	ldr r0, [r4, #0x60]
	bl BasRemove
	ldr r1, .L0804E5E0 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804E5D8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E5E0: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804E5E4
func_fe6_0804E5E4: @ 0x0804E5E4
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl SpellFx_SetBG1Position
	ldr r0, .L0804E618 @ =gUnk_085D116C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E618: .4byte gUnk_085D116C

	thumb_func_start func_fe6_0804E61C
func_fe6_0804E61C: @ 0x0804E61C
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	adds r5, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r6, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0804E67C
	ldr r0, [r4, #0x5c]
	movs r1, #0x5a
	bl func_fe6_0804D050
	adds r0, r5, #0
	bl func_fe6_0804E6BC
	adds r0, r5, #0
	bl func_fe6_0804E778
	adds r0, r5, #0
	bl func_fe6_0804E848
	str r6, [sp]
	str r6, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x28
	movs r2, #0xf
	movs r3, #0x10
	bl func_fe6_0804CD88
	ldr r0, .L0804E678 @ =0x0000011D
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl func_fe6_0805C804
	b .L0804E6B2
	.align 2, 0
.L0804E678: .4byte 0x0000011D
.L0804E67C:
	cmp r0, #0xf
	bne .L0804E6A0
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl StartBattleAnimHitEffectsDefault
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804E6B2
	adds r0, r5, #0
	bl func_fe6_0805C358
	b .L0804E6B2
.L0804E6A0:
	cmp r0, #0x78
	beq .L0804E6B2
	cmp r0, #0x82
	bne .L0804E6B2
	bl SpellFx_Finish
	adds r0, r4, #0
	bl Proc_Break
.L0804E6B2:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0804E6BC
func_fe6_0804E6BC: @ 0x0804E6BC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r1, .L0804E70C @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804E710 @ =gUnk_085D1184
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r6, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	movs r0, #0x34
	strh r0, [r5, #0x2e]
	adds r0, r6, #0
	bl GetAnimPosition
	ldr r3, .L0804E714 @ =gUnk_085D9208
	cmp r0, #0
	bne .L0804E6EC
	ldr r3, .L0804E718 @ =gUnk_085D8608
.L0804E6EC:
	str r3, [sp]
	adds r0, r6, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	adds r4, r0, #0
	str r4, [r5, #0x60]
	adds r0, r6, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L0804E71C
	ldrh r0, [r4, #2]
	adds r0, #0x20
	b .L0804E720
	.align 2, 0
.L0804E70C: .4byte gEfxBgSemaphore
.L0804E710: .4byte gUnk_085D1184
.L0804E714: .4byte gUnk_085D9208
.L0804E718: .4byte gUnk_085D8608
.L0804E71C:
	ldrh r0, [r4, #2]
	subs r0, #0x20
.L0804E720:
	strh r0, [r4, #2]
	ldr r0, .L0804E73C @ =gUnk_081203F4
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0804E740 @ =gUnk_0811F6F4
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E73C: .4byte gUnk_081203F4
.L0804E740: .4byte gUnk_0811F6F4

	thumb_func_start func_fe6_0804E744
func_fe6_0804E744: @ 0x0804E744
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0804E76C
	ldr r0, [r4, #0x60]
	bl BasRemove
	ldr r1, .L0804E774 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804E76C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E774: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804E778
func_fe6_0804E778: @ 0x0804E778
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, .L0804E7D8 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804E7DC @ =gUnk_085D119C
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	movs r0, #0x70
	strh r0, [r5, #0x2e]
	ldr r0, .L0804E7E0 @ =gUnk_0813A6F8
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	ldr r0, [r5, #0x5c]
	ldr r2, .L0804E7E4 @ =gUnk_0813BA64
	adds r1, r2, #0
	bl SpellFx_WriteBgMap
	bl SpellFx_SetBG1Position
	bl SpellFx_SetSomeColorEffect
	ldr r0, .L0804E7E8 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L0804E808
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L0804E7EC
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L0804E7F6
	.align 2, 0
.L0804E7D8: .4byte gEfxBgSemaphore
.L0804E7DC: .4byte gUnk_085D119C
.L0804E7E0: .4byte gUnk_0813A6F8
.L0804E7E4: .4byte gUnk_0813BA64
.L0804E7E8: .4byte gEkrDistanceType
.L0804E7EC:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L0804E7F6:
	ldr r0, .L0804E810 @ =gBg1Tm+0x3C
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #2
	movs r2, #0x14
	movs r3, #1
	bl func_fe6_0805B0D4
.L0804E808:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E810: .4byte gBg1Tm+0x3C

	thumb_func_start func_fe6_0804E814
func_fe6_0804E814: @ 0x0804E814
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L0804E83E
	bl SpellFx_ClearBG1
	bl SpellFx_ClearColorEffects
	ldr r1, .L0804E844 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804E83E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E844: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804E848
func_fe6_0804E848: @ 0x0804E848
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0804E874 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804E878 @ =gUnk_085D11B4
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L0804E87C @ =gUnk_08119D78
	str r1, [r0, #0x48]
	ldr r1, .L0804E880 @ =gUnk_0813B6B4
	str r1, [r0, #0x4c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E874: .4byte gEfxBgSemaphore
.L0804E878: .4byte gUnk_085D11B4
.L0804E87C: .4byte gUnk_08119D78
.L0804E880: .4byte gUnk_0813B6B4

	thumb_func_start func_fe6_0804E884
func_fe6_0804E884: @ 0x0804E884
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L0804E8AA
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	b .L0804E8C0
.L0804E8AA:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L0804E8C0
	ldr r1, .L0804E8C8 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804E8C0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E8C8: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804E8CC
func_fe6_0804E8CC: @ 0x0804E8CC
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl func_fe6_08047300
	bl SpellFx_SetBG1Position
	ldr r0, .L0804E904 @ =gUnk_085D11D4
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E904: .4byte gUnk_085D11D4

	thumb_func_start func_fe6_0804E908
func_fe6_0804E908: @ 0x0804E908
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	adds r5, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0804E942
	ldr r0, [r4, #0x5c]
	movs r1, #0x5a
	bl func_fe6_0804D050
	ldr r0, [r4, #0x5c]
	bl func_fe6_0804E988
	movs r0, #0x8f
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl func_fe6_0805C804
.L0804E942:
	movs r1, #0x2c
	ldrsh r0, [r4, r1]
	cmp r0, #4
	bne .L0804E96A
	movs r0, #9
	ldrh r3, [r5, #0x10]
	orrs r0, r3
	strh r0, [r5, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl StartBattleAnimHitEffectsDefault
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804E980
	adds r0, r5, #0
	bl func_fe6_0805C358
	b .L0804E980
.L0804E96A:
	cmp r0, #0x32
	beq .L0804E980
	cmp r0, #0x3c
	bne .L0804E980
	bl SpellFx_Finish
	bl func_fe6_08047358
	adds r0, r4, #0
	bl Proc_Break
.L0804E980:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0804E988
func_fe6_0804E988: @ 0x0804E988
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, .L0804E9C4 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804E9C8 @ =gUnk_085D11EC
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	ldr r2, .L0804E9CC @ =gUnk_085D9E38
	ldr r3, .L0804E9D0 @ =gUnk_085DAA68
	str r2, [sp]
	adds r0, r4, #0
	adds r1, r3, #0
	bl EfxCreateFrontAnim
	adds r6, r0, #0
	str r6, [r5, #0x60]
	adds r0, r4, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L0804E9D4
	ldrh r0, [r6, #2]
	adds r0, #0x20
	b .L0804E9D8
	.align 2, 0
.L0804E9C4: .4byte gEfxBgSemaphore
.L0804E9C8: .4byte gUnk_085D11EC
.L0804E9CC: .4byte gUnk_085D9E38
.L0804E9D0: .4byte gUnk_085DAA68
.L0804E9D4:
	ldrh r0, [r6, #2]
	subs r0, #0x20
.L0804E9D8:
	strh r0, [r6, #2]
	ldr r0, .L0804E9F4 @ =gUnk_081214B8
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0804E9F8 @ =gUnk_0811F6F4
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804E9F4: .4byte gUnk_081214B8
.L0804E9F8: .4byte gUnk_0811F6F4

	thumb_func_start func_fe6_0804E9FC
func_fe6_0804E9FC: @ 0x0804E9FC
	push {lr}
	ldr r2, .L0804EA10 @ =gEfxBgSemaphore
	ldr r1, [r2]
	subs r1, #1
	str r1, [r2]
	ldr r0, [r0, #0x60]
	bl BasRemove
	pop {r0}
	bx r0
	.align 2, 0
.L0804EA10: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804EA14
func_fe6_0804EA14: @ 0x0804EA14
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl SpellFx_SetBG1Position
	ldr r0, .L0804EA48 @ =gUnk_085D120C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804EA48: .4byte gUnk_085D120C

	thumb_func_start func_fe6_0804EA4C
func_fe6_0804EA4C: @ 0x0804EA4C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	adds r5, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0804EA90
	ldr r0, [r4, #0x5c]
	movs r1, #0x5a
	bl func_fe6_0804D050
	ldr r0, [r4, #0x5c]
	bl func_fe6_0804EAD4
	ldr r0, [r4, #0x5c]
	bl func_fe6_0804EB7C
	ldr r0, [r4, #0x5c]
	bl func_fe6_0804EC04
	ldr r0, .L0804EAB8 @ =0x0000011F
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl func_fe6_0805C804
.L0804EA90:
	movs r1, #0x2c
	ldrsh r0, [r4, r1]
	cmp r0, #4
	bne .L0804EABC
	movs r0, #9
	ldrh r3, [r5, #0x10]
	orrs r0, r3
	strh r0, [r5, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl StartBattleAnimHitEffectsDefault
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804EACE
	adds r0, r5, #0
	bl func_fe6_0805C358
	b .L0804EACE
	.align 2, 0
.L0804EAB8: .4byte 0x0000011F
.L0804EABC:
	cmp r0, #0x20
	beq .L0804EACE
	cmp r0, #0x30
	bne .L0804EACE
	bl SpellFx_Finish
	adds r0, r4, #0
	bl Proc_Break
.L0804EACE:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0804EAD4
func_fe6_0804EAD4: @ 0x0804EAD4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0804EB10 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804EB14 @ =gUnk_085D1224
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L0804EB18 @ =gUnk_08119DEA
	str r1, [r0, #0x48]
	ldr r1, .L0804EB1C @ =gUnk_085D123C
	str r1, [r0, #0x4c]
	str r1, [r0, #0x50]
	ldr r0, .L0804EB20 @ =gUnk_081214F8
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	bl SpellFx_SetSomeColorEffect
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804EB10: .4byte gEfxBgSemaphore
.L0804EB14: .4byte gUnk_085D1224
.L0804EB18: .4byte gUnk_08119DEA
.L0804EB1C: .4byte gUnk_085D123C
.L0804EB20: .4byte gUnk_081214F8

	thumb_func_start func_fe6_0804EB24
func_fe6_0804EB24: @ 0x0804EB24
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	blt .L0804EB52
	ldr r1, [r4, #0x4c]
	ldr r3, [r4, #0x50]
	ldr r0, [r4, #0x5c]
	lsls r2, r2, #2
	adds r1, r2, r1
	ldr r1, [r1]
	adds r2, r2, r3
	ldr r2, [r2]
	bl SpellFx_WriteBgMap
	b .L0804EB70
.L0804EB52:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne .L0804EB70
	bl SpellFx_ClearBG1
	ldr r1, .L0804EB78 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	adds r0, r4, #0
	bl Proc_Break
.L0804EB70:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804EB78: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804EB7C
func_fe6_0804EB7C: @ 0x0804EB7C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0804EBA8 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804EBAC @ =gUnk_085D126C
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L0804EBB0 @ =gUnk_08119E30
	str r1, [r0, #0x48]
	ldr r1, .L0804EBB4 @ =gUnk_0813E75C
	str r1, [r0, #0x4c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804EBA8: .4byte gEfxBgSemaphore
.L0804EBAC: .4byte gUnk_085D126C
.L0804EBB0: .4byte gUnk_08119E30
.L0804EBB4: .4byte gUnk_0813E75C

	thumb_func_start func_fe6_0804EBB8
func_fe6_0804EBB8: @ 0x0804EBB8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L0804EBDE
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	b .L0804EBF8
.L0804EBDE:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L0804EBF8
	bl SpellFx_ClearColorEffects
	ldr r1, .L0804EC00 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804EBF8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804EC00: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804EC04
func_fe6_0804EC04: @ 0x0804EC04
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L0804EC48 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804EC4C @ =gUnk_085D128C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x37
	strh r0, [r4, #0x2e]
	ldr r3, .L0804EC50 @ =gUnk_085DB6A4
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	adds r6, r0, #0
	str r6, [r4, #0x60]
	adds r0, r5, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L0804EC54
	ldrh r0, [r6, #2]
	adds r0, #0x24
	b .L0804EC58
	.align 2, 0
.L0804EC48: .4byte gEfxBgSemaphore
.L0804EC4C: .4byte gUnk_085D128C
.L0804EC50: .4byte gUnk_085DB6A4
.L0804EC54:
	ldrh r0, [r6, #2]
	subs r0, #0x24
.L0804EC58:
	strh r0, [r6, #2]
	ldrh r0, [r6, #4]
	adds r0, #0xc
	strh r0, [r6, #4]
	ldr r0, .L0804EC7C @ =gUnk_081214D8
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0804EC80 @ =gUnk_0811F6F4
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804EC7C: .4byte gUnk_081214D8
.L0804EC80: .4byte gUnk_0811F6F4

	thumb_func_start func_fe6_0804EC84
func_fe6_0804EC84: @ 0x0804EC84
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L0804ECAC
	ldr r0, .L0804ECB4 @ =gEfxBgSemaphore
	ldr r1, [r0]
	subs r1, #1
	str r1, [r0]
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L0804ECAC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804ECB4: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804ECB8
func_fe6_0804ECB8: @ 0x0804ECB8
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl func_fe6_08047300
	bl SpellFx_SetBG1Position
	ldr r0, .L0804ECF0 @ =gUnk_085D12A4
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804ECF0: .4byte gUnk_085D12A4

	thumb_func_start func_fe6_0804ECF4
func_fe6_0804ECF4: @ 0x0804ECF4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	adds r5, r0, #0
	bl EfxGetCamMovDuration
	adds r6, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0804ED1E
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl NewEfxFarAttackWithDistance
.L0804ED1E:
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	adds r0, r6, #1
	cmp r1, r0
	bne .L0804ED3C
	adds r0, r5, #0
	bl func_fe6_0804ED94
	adds r0, r5, #0
	bl func_fe6_0804EE9C
	adds r0, r5, #0
	bl func_fe6_0804EF24
	b .L0804ED8E
.L0804ED3C:
	adds r0, r6, #4
	cmp r1, r0
	bne .L0804ED72
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl StartBattleAnimHitEffectsDefault
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #2
	ldrsh r2, [r5, r0]
	movs r0, #0xf5
	movs r3, #1
	bl func_fe6_0805C804
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804ED8E
	adds r0, r5, #0
	bl func_fe6_0805C358
	b .L0804ED8E
.L0804ED72:
	adds r0, r6, #0
	adds r0, #0x50
	cmp r1, r0
	beq .L0804ED8E
	adds r0, #0x10
	cmp r1, r0
	bne .L0804ED8E
	bl SpellFx_Finish
	bl func_fe6_08047358
	adds r0, r4, #0
	bl Proc_Break
.L0804ED8E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0804ED94
func_fe6_0804ED94: @ 0x0804ED94
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L0804EDEC @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804EDF0 @ =gUnk_085D12BC
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L0804EDF4 @ =gUnk_08119ED2
	str r0, [r5, #0x48]
	ldr r0, .L0804EDF8 @ =gUnk_085D12D4
	str r0, [r5, #0x4c]
	ldr r0, .L0804EDFC @ =gUnk_085D12DC
	str r0, [r5, #0x50]
	ldr r0, .L0804EE00 @ =gUnk_0812C68C
	movs r1, #0x86
	lsls r1, r1, #5
	bl SpellFx_RegisterBgGfx
	bl SpellFx_SetSomeColorEffect
	ldr r0, .L0804EE04 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L0804EE12
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L0804EE08
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L0804EE12
	.align 2, 0
.L0804EDEC: .4byte gEfxBgSemaphore
.L0804EDF0: .4byte gUnk_085D12BC
.L0804EDF4: .4byte gUnk_08119ED2
.L0804EDF8: .4byte gUnk_085D12D4
.L0804EDFC: .4byte gUnk_085D12DC
.L0804EE00: .4byte gUnk_0812C68C
.L0804EE04: .4byte gEkrDistanceType
.L0804EE08:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L0804EE12:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0804EE18
func_fe6_0804EE18: @ 0x0804EE18
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r6, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r5, r0, #0x10
	cmp r5, #0
	blt .L0804EE70
	ldr r1, [r4, #0x4c]
	ldr r3, [r4, #0x50]
	ldr r0, [r4, #0x5c]
	lsls r2, r5, #2
	adds r1, r2, r1
	ldr r1, [r1]
	adds r2, r2, r3
	ldr r2, [r2]
	bl SpellFx_WriteBgMap
	cmp r5, #0
	bne .L0804EE4E
	ldr r6, .L0804EE68 @ =0x0000011F
.L0804EE4E:
	cmp r5, #1
	bne .L0804EE56
	movs r6, #0xa8
	lsls r6, r6, #1
.L0804EE56:
	ldr r0, .L0804EE6C @ =gBg1Tm+0x3C
	str r6, [sp]
	movs r1, #2
	movs r2, #0x14
	movs r3, #1
	bl FillBGRect
	b .L0804EE8E
	.align 2, 0
.L0804EE68: .4byte 0x0000011F
.L0804EE6C: .4byte gBg1Tm+0x3C
.L0804EE70:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r5, r0
	bne .L0804EE8E
	bl SpellFx_ClearBG1
	ldr r1, .L0804EE98 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	adds r0, r4, #0
	bl Proc_Break
.L0804EE8E:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804EE98: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804EE9C
func_fe6_0804EE9C: @ 0x0804EE9C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0804EEC8 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804EECC @ =gUnk_085D12E4
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L0804EED0 @ =gUnk_08119EDC
	str r1, [r0, #0x48]
	ldr r1, .L0804EED4 @ =gUnk_0812CF48
	str r1, [r0, #0x4c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804EEC8: .4byte gEfxBgSemaphore
.L0804EECC: .4byte gUnk_085D12E4
.L0804EED0: .4byte gUnk_08119EDC
.L0804EED4: .4byte gUnk_0812CF48

	thumb_func_start func_fe6_0804EED8
func_fe6_0804EED8: @ 0x0804EED8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L0804EEFE
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	b .L0804EF18
.L0804EEFE:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L0804EF18
	bl SpellFx_ClearColorEffects
	ldr r1, .L0804EF20 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804EF18:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804EF20: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804EF24
func_fe6_0804EF24: @ 0x0804EF24
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L0804EF6C @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804EF70 @ =gUnk_085D1304
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r3, .L0804EF74 @ =gUnk_085E2508
	ldr r2, .L0804EF78 @ =gUnk_085E19DC
	str r2, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	bl EfxCreateFrontAnim
	str r0, [r4, #0x60]
	ldr r0, .L0804EF7C @ =gUnk_0812D80C
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0804EF80 @ =gUnk_0812D374
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804EF6C: .4byte gEfxBgSemaphore
.L0804EF70: .4byte gUnk_085D1304
.L0804EF74: .4byte gUnk_085E2508
.L0804EF78: .4byte gUnk_085E19DC
.L0804EF7C: .4byte gUnk_0812D80C
.L0804EF80: .4byte gUnk_0812D374

	thumb_func_start func_fe6_0804EF84
func_fe6_0804EF84: @ 0x0804EF84
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x32
	ble .L0804EFAA
	ldr r0, [r4, #0x60]
	bl BasRemove
	ldr r1, .L0804EFB0 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804EFAA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804EFB0: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804EFB4
func_fe6_0804EFB4: @ 0x0804EFB4
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl func_fe6_08047300
	bl SpellFx_SetBG1Position
	ldr r0, .L0804EFF4 @ =gUnk_085D131C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r1, #0
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	adds r0, #0x2a
	strb r1, [r0]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804EFF4: .4byte gUnk_085D131C

	thumb_func_start func_fe6_0804EFF8
func_fe6_0804EFF8: @ 0x0804EFF8
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl func_fe6_08047300
	bl SpellFx_SetBG1Position
	ldr r0, .L0804F038 @ =gUnk_085D131C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r1, r4, #0
	adds r1, #0x2a
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F038: .4byte gUnk_085D131C

	thumb_func_start func_fe6_0804F03C
func_fe6_0804F03C: @ 0x0804F03C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	adds r6, r0, #0
	ldr r0, .L0804F068 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L0804F06C
	movs r5, #0x20
	movs r7, #0x34
	movs r3, #0x36
	mov r8, r3
	movs r0, #0x55
	mov sb, r0
	b .L0804F078
	.align 2, 0
.L0804F068: .4byte gEkrDistanceType
.L0804F06C:
	movs r5, #0x28
	movs r7, #0x3c
	movs r1, #0x41
	mov r8, r1
	movs r3, #0x60
	mov sb, r3
.L0804F078:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0804F0A4
	ldr r0, [r4, #0x5c]
	bl func_fe6_0804F144
	ldr r0, [r4, #0x5c]
	bl func_fe6_0804F1FC
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xf1
	movs r3, #1
	bl func_fe6_0805C804
.L0804F0A4:
	movs r1, #0x2c
	ldrsh r0, [r4, r1]
	cmp r0, r5
	bne .L0804F0B8
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl NewEfxFarAttackWithDistance
	b .L0804F138
.L0804F0B8:
	cmp r0, r7
	bne .L0804F122
	movs r0, #9
	ldrh r3, [r6, #0x10]
	orrs r0, r3
	strh r0, [r6, #0x10]
	adds r5, r4, #0
	adds r5, #0x29
	ldrb r1, [r5]
	adds r0, r6, #0
	bl StartBattleAnimHitEffectsDefault
	ldrb r0, [r5]
	cmp r0, #0
	bne .L0804F138
	adds r0, r4, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0804F0F8
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #2
	ldrsh r2, [r6, r0]
	movs r0, #0xf7
	movs r3, #1
	bl func_fe6_0805C804
	adds r0, r6, #0
	bl func_fe6_0804F2D0
	b .L0804F11A
.L0804F0F8:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r6, r3]
	movs r0, #0xf8
	movs r3, #1
	bl func_fe6_0805C804
	adds r0, r6, #0
	bl func_fe6_0804F3B8
	adds r0, r6, #0
	bl func_fe6_0804F484
	adds r0, r6, #0
	bl func_fe6_0804F510
.L0804F11A:
	adds r0, r6, #0
	bl func_fe6_0805C358
	b .L0804F138
.L0804F122:
	cmp r0, r8
	beq .L0804F138
	cmp r0, sb
	bne .L0804F138
	bl SpellFx_Finish
	bl func_fe6_08047358
	adds r0, r4, #0
	bl Proc_Break
.L0804F138:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0804F144
func_fe6_0804F144: @ 0x0804F144
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0804F188 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804F18C @ =gUnk_085D1334
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L0804F190 @ =gUnk_08119F1E
	str r1, [r0, #0x48]
	ldr r1, .L0804F194 @ =gUnk_085D134C
	str r1, [r0, #0x4c]
	ldr r1, .L0804F198 @ =gUnk_085D137C
	str r1, [r0, #0x50]
	ldr r0, .L0804F19C @ =gUnk_0812E4A4
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	ldr r0, .L0804F1A0 @ =gUnk_0812D8AC
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	bl SpellFx_SetSomeColorEffect
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F188: .4byte gEfxBgSemaphore
.L0804F18C: .4byte gUnk_085D1334
.L0804F190: .4byte gUnk_08119F1E
.L0804F194: .4byte gUnk_085D134C
.L0804F198: .4byte gUnk_085D137C
.L0804F19C: .4byte gUnk_0812E4A4
.L0804F1A0: .4byte gUnk_0812D8AC

	thumb_func_start func_fe6_0804F1A4
func_fe6_0804F1A4: @ 0x0804F1A4
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	blt .L0804F1D2
	ldr r1, [r4, #0x4c]
	ldr r3, [r4, #0x50]
	ldr r0, [r4, #0x5c]
	lsls r2, r2, #2
	adds r1, r2, r1
	ldr r1, [r1]
	adds r2, r2, r3
	ldr r2, [r2]
	bl SpellFx_WriteBgMap
	b .L0804F1F0
.L0804F1D2:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne .L0804F1F0
	bl SpellFx_ClearBG1
	ldr r1, .L0804F1F8 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	adds r0, r4, #0
	bl Proc_Break
.L0804F1F0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F1F8: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804F1FC
func_fe6_0804F1FC: @ 0x0804F1FC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r1, .L0804F240 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804F244 @ =gUnk_085D13AC
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r6, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r1, .L0804F248 @ =gUnk_085E2CA8
	ldr r2, .L0804F24C @ =gUnk_085E2920
	ldr r3, .L0804F250 @ =gUnk_085E2CD4
	ldr r0, .L0804F254 @ =gUnk_085E294C
	str r0, [sp]
	adds r0, r6, #0
	bl EfxCreateFrontAnim
	adds r5, r0, #0
	str r5, [r4, #0x60]
	adds r0, r6, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L0804F258
	ldrh r0, [r6, #2]
	subs r0, #8
	b .L0804F25C
	.align 2, 0
.L0804F240: .4byte gEfxBgSemaphore
.L0804F244: .4byte gUnk_085D13AC
.L0804F248: .4byte gUnk_085E2CA8
.L0804F24C: .4byte gUnk_085E2920
.L0804F250: .4byte gUnk_085E2CD4
.L0804F254: .4byte gUnk_085E294C
.L0804F258:
	ldrh r0, [r6, #2]
	adds r0, #8
.L0804F25C:
	strh r0, [r5, #2]
	ldrh r0, [r6, #4]
	adds r0, #8
	strh r0, [r5, #4]
	ldr r0, .L0804F280 @ =gUnk_0812FFD8
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0804F284 @ =gUnk_0812F9DC
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F280: .4byte gUnk_0812FFD8
.L0804F284: .4byte gUnk_0812F9DC

	thumb_func_start func_fe6_0804F288
func_fe6_0804F288: @ 0x0804F288
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x25
	bne .L0804F2AE
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xf2
	movs r3, #1
	bl func_fe6_0805C804
	b .L0804F2C6
.L0804F2AE:
	cmp r0, #0x32
	ble .L0804F2C6
	ldr r0, [r4, #0x60]
	bl BasRemove
	ldr r1, .L0804F2CC @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804F2C6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F2CC: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804F2D0
func_fe6_0804F2D0: @ 0x0804F2D0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L0804F328 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804F32C @ =gUnk_085D13C4
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L0804F330 @ =gUnk_08119F50
	str r0, [r5, #0x48]
	ldr r0, .L0804F334 @ =gUnk_085D1430
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L0804F338 @ =gUnk_085D13DC
	str r0, [r5, #0x54]
	ldr r0, .L0804F33C @ =gUnk_08138BF0
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	bl SpellFx_SetSomeColorEffect
	ldr r0, .L0804F340 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L0804F34E
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L0804F344
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L0804F34E
	.align 2, 0
.L0804F328: .4byte gEfxBgSemaphore
.L0804F32C: .4byte gUnk_085D13C4
.L0804F330: .4byte gUnk_08119F50
.L0804F334: .4byte gUnk_085D1430
.L0804F338: .4byte gUnk_085D13DC
.L0804F33C: .4byte gUnk_08138BF0
.L0804F340: .4byte gEkrDistanceType
.L0804F344:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L0804F34E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0804F354
func_fe6_0804F354: @ 0x0804F354
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r0, #0x2c
	adds r1, r7, #0
	adds r1, #0x44
	ldr r2, [r7, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	blt .L0804F390
	ldr r5, [r7, #0x4c]
	ldr r6, [r7, #0x50]
	ldr r0, [r7, #0x54]
	lsls r4, r4, #2
	adds r0, r4, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	ldr r0, [r7, #0x5c]
	adds r5, r4, r5
	ldr r1, [r5]
	adds r4, r4, r6
	ldr r2, [r4]
	bl SpellFx_WriteBgMap
	b .L0804F3AE
.L0804F390:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	bne .L0804F3AE
	bl SpellFx_ClearBG1
	ldr r1, .L0804F3B4 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	adds r0, r7, #0
	bl Proc_End
.L0804F3AE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F3B4: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804F3B8
func_fe6_0804F3B8: @ 0x0804F3B8
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, .L0804F414 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804F418 @ =gUnk_085D1484
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	ldr r0, .L0804F41C @ =gUnk_0813A6F8
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	ldr r0, [r5, #0x5c]
	ldr r2, .L0804F420 @ =gUnk_0813B8B4
	adds r1, r2, #0
	bl SpellFx_WriteBgMap
	bl SpellFx_SetBG1Position
	bl SpellFx_SetSomeColorEffect
	ldr r0, .L0804F424 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L0804F444
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L0804F428
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L0804F432
	.align 2, 0
.L0804F414: .4byte gEfxBgSemaphore
.L0804F418: .4byte gUnk_085D1484
.L0804F41C: .4byte gUnk_0813A6F8
.L0804F420: .4byte gUnk_0813B8B4
.L0804F424: .4byte gEkrDistanceType
.L0804F428:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L0804F432:
	ldr r0, .L0804F44C @ =gBg1Tm+0x3C
	movs r1, #0x80
	lsls r1, r1, #1
	str r1, [sp]
	movs r1, #2
	movs r2, #0x14
	movs r3, #1
	bl func_fe6_0805B0D4
.L0804F444:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F44C: .4byte gBg1Tm+0x3C

	thumb_func_start func_fe6_0804F450
func_fe6_0804F450: @ 0x0804F450
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x28
	bne .L0804F478
	bl SpellFx_ClearBG1
	bl SpellFx_ClearColorEffects
	ldr r1, .L0804F480 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804F478:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F480: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804F484
func_fe6_0804F484: @ 0x0804F484
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0804F4B8 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804F4BC @ =gUnk_085D149C
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L0804F4C0 @ =gUnk_08119FA6
	str r1, [r0, #0x48]
	ldr r1, .L0804F4C4 @ =gUnk_0813B6B4
	str r1, [r0, #0x4c]
	adds r0, r1, #0
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F4B8: .4byte gEfxBgSemaphore
.L0804F4BC: .4byte gUnk_085D149C
.L0804F4C0: .4byte gUnk_08119FA6
.L0804F4C4: .4byte gUnk_0813B6B4

	thumb_func_start func_fe6_0804F4C8
func_fe6_0804F4C8: @ 0x0804F4C8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L0804F4EE
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	b .L0804F504
.L0804F4EE:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L0804F504
	ldr r1, .L0804F50C @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804F504:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F50C: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804F510
func_fe6_0804F510: @ 0x0804F510
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L0804F550 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804F554 @ =gUnk_085D14BC
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r3, .L0804F558 @ =gUnk_085E48C4
	ldr r2, .L0804F55C @ =gUnk_085E3AA4
	str r2, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	bl EfxCreateFrontAnim
	adds r6, r0, #0
	str r6, [r4, #0x60]
	adds r0, r5, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L0804F560
	ldrh r0, [r6, #2]
	subs r0, #8
	b .L0804F564
	.align 2, 0
.L0804F550: .4byte gEfxBgSemaphore
.L0804F554: .4byte gUnk_085D14BC
.L0804F558: .4byte gUnk_085E48C4
.L0804F55C: .4byte gUnk_085E3AA4
.L0804F560:
	ldrh r0, [r6, #2]
	adds r0, #8
.L0804F564:
	strh r0, [r6, #2]
	ldr r0, [r6, #0x1c]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r6, #0x1c]
	ldr r0, .L0804F58C @ =gUnk_0813BD74
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0804F590 @ =gUnk_0813BAFC
	movs r1, #0x80
	lsls r1, r1, #4
	bl SpellFx_RegisterObjGfx
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F58C: .4byte gUnk_0813BD74
.L0804F590: .4byte gUnk_0813BAFC

	thumb_func_start func_fe6_0804F594
func_fe6_0804F594: @ 0x0804F594
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x28
	ble .L0804F5BA
	ldr r0, [r4, #0x60]
	bl BasRemove
	ldr r1, .L0804F5C0 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804F5BA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F5C0: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804F5C4
func_fe6_0804F5C4: @ 0x0804F5C4
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl func_fe6_08047300
	bl SpellFx_SetBG1Position
	ldr r0, .L0804F5FC @ =gUnk_085D14D4
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F5FC: .4byte gUnk_085D14D4

	thumb_func_start func_fe6_0804F600
func_fe6_0804F600: @ 0x0804F600
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	adds r5, r0, #0
	bl EfxGetCamMovDuration
	adds r6, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r1, #0
	mov r8, r1
	movs r7, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0804F636
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl NewEfxFarAttackWithDistance
.L0804F636:
	movs r2, #0x2c
	ldrsh r1, [r4, r2]
	adds r0, r6, #1
	cmp r1, r0
	bne .L0804F692
	adds r0, r5, #0
	bl func_fe6_0804F738
	adds r0, r5, #0
	bl func_fe6_0804F99C
	ldr r3, .L0804F6A8 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	mov r2, r8
	strb r2, [r0]
	adds r0, #1
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	str r1, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0x10
	movs r3, #0
	bl func_fe6_0804CD88
	movs r0, #0x91
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl func_fe6_0805C804
.L0804F692:
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	adds r0, r6, #0
	adds r0, #0x52
	cmp r1, r0
	bne .L0804F6AC
	ldr r0, [r4, #0x5c]
	movs r1, #4
	bl NewEfxFlashBgWhite
	b .L0804F72C
	.align 2, 0
.L0804F6A8: .4byte gDispIo
.L0804F6AC:
	adds r0, r6, #0
	adds r0, #0x55
	cmp r1, r0
	bne .L0804F6E8
	adds r0, r5, #0
	bl func_fe6_0804F820
	adds r0, r5, #0
	bl func_fe6_0804F908
	str r7, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x18
	movs r2, #0x10
	movs r3, #0x10
	bl func_fe6_0804CD88
	ldr r0, .L0804F6E4 @ =0x00000123
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl func_fe6_0805C804
	b .L0804F72C
	.align 2, 0
.L0804F6E4: .4byte 0x00000123
.L0804F6E8:
	adds r0, r6, #0
	adds r0, #0x58
	cmp r1, r0
	bne .L0804F710
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl StartBattleAnimHitEffectsDefault
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804F72C
	adds r0, r5, #0
	bl func_fe6_0805C358
	b .L0804F72C
.L0804F710:
	adds r0, r6, #0
	adds r0, #0x88
	cmp r1, r0
	beq .L0804F72C
	adds r0, #0x19
	cmp r1, r0
	bne .L0804F72C
	bl SpellFx_Finish
	bl func_fe6_08047358
	adds r0, r4, #0
	bl Proc_Break
.L0804F72C:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0804F738
func_fe6_0804F738: @ 0x0804F738
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L0804F78C @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804F790 @ =gUnk_085D14EC
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L0804F794 @ =gUnk_08119FFC
	str r0, [r5, #0x48]
	ldr r0, .L0804F798 @ =gUnk_085D1504
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L0804F79C @ =gUnk_085D151C
	str r0, [r5, #0x54]
	ldr r0, .L0804F7A0 @ =gUnk_081521C0
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	ldr r0, .L0804F7A4 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L0804F7B2
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L0804F7A8
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L0804F7B2
	.align 2, 0
.L0804F78C: .4byte gEfxBgSemaphore
.L0804F790: .4byte gUnk_085D14EC
.L0804F794: .4byte gUnk_08119FFC
.L0804F798: .4byte gUnk_085D1504
.L0804F79C: .4byte gUnk_085D151C
.L0804F7A0: .4byte gUnk_081521C0
.L0804F7A4: .4byte gEkrDistanceType
.L0804F7A8:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L0804F7B2:
	bl SpellFx_SetSomeColorEffect
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0804F7BC
func_fe6_0804F7BC: @ 0x0804F7BC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	cmp r3, #0
	blt .L0804F7F8
	ldr r1, [r4, #0x4c]
	ldr r2, [r4, #0x50]
	ldr r5, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	lsls r4, r3, #2
	adds r1, r4, r1
	ldr r1, [r1]
	adds r2, r4, r2
	ldr r2, [r2]
	bl SpellFx_WriteBgMap
	adds r4, r4, r5
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	b .L0804F816
.L0804F7F8:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r3, r0
	bne .L0804F816
	bl SpellFx_ClearBG1
	ldr r1, .L0804F81C @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	adds r0, r4, #0
	bl Proc_Break
.L0804F816:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F81C: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804F820
func_fe6_0804F820: @ 0x0804F820
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L0804F874 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804F878 @ =gUnk_085D1534
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L0804F87C @ =gUnk_0811A06A
	str r0, [r5, #0x48]
	ldr r0, .L0804F880 @ =gUnk_085D154C
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L0804F884 @ =gUnk_085D1578
	str r0, [r5, #0x54]
	ldr r0, .L0804F888 @ =gUnk_0814A498
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	ldr r0, .L0804F88C @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L0804F89A
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L0804F890
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L0804F89A
	.align 2, 0
.L0804F874: .4byte gEfxBgSemaphore
.L0804F878: .4byte gUnk_085D1534
.L0804F87C: .4byte gUnk_0811A06A
.L0804F880: .4byte gUnk_085D154C
.L0804F884: .4byte gUnk_085D1578
.L0804F888: .4byte gUnk_0814A498
.L0804F88C: .4byte gEkrDistanceType
.L0804F890:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L0804F89A:
	bl SpellFx_SetSomeColorEffect
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0804F8A4
func_fe6_0804F8A4: @ 0x0804F8A4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	cmp r3, #0
	blt .L0804F8E0
	ldr r1, [r4, #0x4c]
	ldr r2, [r4, #0x50]
	ldr r5, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	lsls r4, r3, #2
	adds r1, r4, r1
	ldr r1, [r1]
	adds r2, r4, r2
	ldr r2, [r2]
	bl SpellFx_WriteBgMap
	adds r4, r4, r5
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	b .L0804F8FE
.L0804F8E0:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r3, r0
	bne .L0804F8FE
	bl SpellFx_ClearBG1
	ldr r1, .L0804F904 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	adds r0, r4, #0
	bl Proc_Break
.L0804F8FE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F904: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804F908
func_fe6_0804F908: @ 0x0804F908
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L0804F958 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804F95C @ =gUnk_085D15A4
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r3, .L0804F960 @ =gUnk_085E79F8
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	str r0, [r4, #0x60]
	ldrh r1, [r0, #2]
	adds r1, #0x18
	strh r1, [r0, #2]
	ldr r0, .L0804F964 @ =gUnk_081AC0F4
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0804F968 @ =gUnk_08152E78
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F958: .4byte gEfxBgSemaphore
.L0804F95C: .4byte gUnk_085D15A4
.L0804F960: .4byte gUnk_085E79F8
.L0804F964: .4byte gUnk_081AC0F4
.L0804F968: .4byte gUnk_08152E78

	thumb_func_start func_fe6_0804F96C
func_fe6_0804F96C: @ 0x0804F96C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x33
	ble .L0804F992
	ldr r0, [r4, #0x60]
	bl BasRemove
	ldr r1, .L0804F998 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804F992:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F998: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804F99C
func_fe6_0804F99C: @ 0x0804F99C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0804F9D8 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804F9DC @ =gUnk_085D15BC
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r2, #0
	strh r2, [r0, #0x2c]
	strh r2, [r0, #0x2e]
	movs r1, #1
	str r1, [r0, #0x44]
	str r2, [r0, #0x48]
	ldr r0, .L0804F9E0 @ =gUnk_081AC0F4
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0804F9E4 @ =gUnk_08152E78
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804F9D8: .4byte gEfxBgSemaphore
.L0804F9DC: .4byte gUnk_085D15BC
.L0804F9E0: .4byte gUnk_081AC0F4
.L0804F9E4: .4byte gUnk_08152E78

	thumb_func_start func_fe6_0804F9E8
func_fe6_0804F9E8: @ 0x0804F9E8
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
.L0804F9EE:
	ldr r0, [r5, #0x5c]
	adds r1, r4, #0
	bl func_fe6_0804FA14
	adds r4, #1
	cmp r4, #0x1f
	ble .L0804F9EE
	ldr r1, .L0804FA10 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r5, #0
	bl Proc_Break
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804FA10: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804FA14
func_fe6_0804FA14: @ 0x0804FA14
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	mov r8, r1
	mov r4, sp
	mov r0, sp
	movs r1, #0
	movs r2, #8
	bl memset
	movs r5, #0
	movs r0, #1
	strb r0, [r4, #6]
	strb r0, [r4, #7]
	ldr r1, .L0804FAA4 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804FAA8 @ =gUnk_085D15D4
	movs r1, #3
	bl SpawnProc
	adds r7, r0, #0
	str r6, [r7, #0x5c]
	strh r5, [r7, #0x2c]
	movs r0, #0x64
	strh r0, [r7, #0x2e]
	movs r0, #7
	mov r1, r8
	ands r0, r1
	mov r2, sp
	adds r4, r2, r0
	ldrb r0, [r4]
	adds r1, r7, #0
	adds r1, #0x29
	strb r0, [r1]
	ldr r0, .L0804FAAC @ =gUnk_085E7A64
	movs r1, #0x78
	bl BasCreate
	str r0, [r7, #0x60]
	movs r1, #0xa1
	lsls r1, r1, #6
	strh r1, [r0, #8]
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0, #2]
	strh r1, [r0, #4]
	ldr r5, .L0804FAB0 @ =0x0000FFFF
	adds r0, r5, #0
	bl func_fe6_0805B9C8
	strh r0, [r7, #0x32]
	adds r0, r5, #0
	bl func_fe6_0805B9C8
	strh r0, [r7, #0x3a]
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804FAB8
	adds r0, r5, #0
	bl func_fe6_0805B9C8
	ldr r2, .L0804FAB4 @ =0x000001FF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #0xe0
	lsls r1, r1, #3
	b .L0804FACA
	.align 2, 0
.L0804FAA4: .4byte gEfxBgSemaphore
.L0804FAA8: .4byte gUnk_085D15D4
.L0804FAAC: .4byte gUnk_085E7A64
.L0804FAB0: .4byte 0x0000FFFF
.L0804FAB4: .4byte 0x000001FF
.L0804FAB8:
	adds r0, r5, #0
	bl func_fe6_0805B9C8
	ldr r2, .L0804FB14 @ =0x000001FF
	adds r1, r2, #0
	ands r0, r1
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r2, #0
.L0804FACA:
	adds r0, r0, r1
	strh r0, [r7, #0x34]
	ldr r4, .L0804FB18 @ =0x0000FF0F
	adds r0, r4, #0
	bl func_fe6_0805B9C8
	ldr r2, .L0804FB1C @ =0x000003FF
	adds r1, r2, #0
	ands r0, r1
	ldr r1, .L0804FB20 @ =0xFFFFFF00
	adds r0, r0, r1
	strh r0, [r7, #0x3c]
	adds r0, r4, #0
	bl func_fe6_0805B9C8
	strh r0, [r7, #0x36]
	adds r0, r4, #0
	bl func_fe6_0805B9C8
	strh r0, [r7, #0x3e]
	movs r0, #7
	mov r2, r8
	ands r0, r2
	add r0, sp
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0804FB24
	adds r0, r4, #0
	bl func_fe6_0805B9C8
	ldr r2, .L0804FB14 @ =0x000001FF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #0xe0
	lsls r1, r1, #3
	b .L0804FB36
	.align 2, 0
.L0804FB14: .4byte 0x000001FF
.L0804FB18: .4byte 0x0000FF0F
.L0804FB1C: .4byte 0x000003FF
.L0804FB20: .4byte 0xFFFFFF00
.L0804FB24:
	adds r0, r4, #0
	bl func_fe6_0805B9C8
	ldr r2, .L0804FB5C @ =0x000001FF
	adds r1, r2, #0
	ands r0, r1
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r2, #0
.L0804FB36:
	adds r0, r0, r1
	strh r0, [r7, #0x38]
	ldr r0, .L0804FB60 @ =0x0000FF0F
	bl func_fe6_0805B9C8
	ldr r2, .L0804FB64 @ =0x000003FF
	adds r1, r2, #0
	ands r0, r1
	ldr r1, .L0804FB68 @ =0xFFFFFF00
	adds r0, r0, r1
	adds r1, r7, #0
	adds r1, #0x40
	strh r0, [r1]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804FB5C: .4byte 0x000001FF
.L0804FB60: .4byte 0x0000FF0F
.L0804FB64: .4byte 0x000003FF
.L0804FB68: .4byte 0xFFFFFF00

	thumb_func_start func_fe6_0804FB6C
func_fe6_0804FB6C: @ 0x0804FB6C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r3, [r4, #0x60]
	ldrh r2, [r4, #0x2c]
	adds r2, #1
	strh r2, [r4, #0x2c]
	lsls r1, r2, #0x10
	ldrh r5, [r4, #0x2e]
	lsls r0, r5, #0x10
	cmp r1, r0
	ble .L0804FB9C
	ldr r1, .L0804FB98 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r3, #0
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
	b .L0804FC1C
	.align 2, 0
.L0804FB98: .4byte gEfxBgSemaphore
.L0804FB9C:
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	bne .L0804FBE0
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0804FBB8
	ldr r0, .L0804FBB4 @ =gUnk_085E7AC4
	b .L0804FBBA
	.align 2, 0
.L0804FBB4: .4byte gUnk_085E7AC4
.L0804FBB8:
	ldr r0, .L0804FBDC @ =gUnk_085E7ACC
.L0804FBBA:
	str r0, [r3, #0x24]
	str r0, [r3, #0x20]
	movs r0, #0
	strh r0, [r3, #6]
	ldrh r1, [r4, #0x32]
	ldrh r2, [r4, #0x34]
	adds r0, r1, r2
	strh r0, [r4, #0x32]
	ldrh r5, [r4, #0x3a]
	ldrh r2, [r4, #0x3c]
	adds r1, r5, r2
	strh r1, [r4, #0x3a]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x18
	strh r0, [r3, #2]
	ldrh r4, [r4, #0x3a]
	b .L0804FC18
	.align 2, 0
.L0804FBDC: .4byte gUnk_085E7ACC
.L0804FBE0:
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0804FBF4
	ldr r0, .L0804FBF0 @ =gUnk_085E7AC4
	b .L0804FBF6
	.align 2, 0
.L0804FBF0: .4byte gUnk_085E7AC4
.L0804FBF4:
	ldr r0, .L0804FC24 @ =gUnk_085E7ACC
.L0804FBF6:
	str r0, [r3, #0x24]
	str r0, [r3, #0x20]
	movs r0, #0
	strh r0, [r3, #6]
	ldrh r5, [r4, #0x3e]
	ldrh r1, [r4, #0x38]
	adds r0, r5, r1
	strh r0, [r4, #0x3e]
	adds r1, r4, #0
	adds r1, #0x40
	ldrh r1, [r1]
	adds r0, r1, r0
	strh r0, [r4, #0x3e]
	ldrh r2, [r4, #0x36]
	lsrs r0, r2, #8
	strh r0, [r3, #2]
	ldrh r4, [r4, #0x3e]
.L0804FC18:
	lsrs r0, r4, #8
	strh r0, [r3, #4]
.L0804FC1C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804FC24: .4byte gUnk_085E7ACC

	thumb_func_start func_fe6_0804FC28
func_fe6_0804FC28: @ 0x0804FC28
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl func_fe6_08047300
	bl SpellFx_SetBG1Position
	ldr r0, .L0804FC60 @ =gUnk_085D15EC
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804FC60: .4byte gUnk_085D15EC

	thumb_func_start func_fe6_0804FC64
func_fe6_0804FC64: @ 0x0804FC64
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	adds r5, r0, #0
	bl EfxGetCamMovDuration
	adds r6, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0804FC8E
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl NewEfxFarAttackWithDistance
.L0804FC8E:
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	adds r0, r6, #1
	cmp r1, r0
	bne .L0804FCB4
	ldr r0, .L0804FCFC @ =0x00000119
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl func_fe6_0805C804
	adds r0, r5, #0
	bl func_fe6_0804FD24
	adds r0, r5, #0
	bl func_fe6_0804FE60
.L0804FCB4:
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	adds r0, r6, #0
	adds r0, #0x59
	cmp r1, r0
	bne .L0804FCCA
	adds r0, r5, #0
	movs r1, #2
	movs r2, #3
	bl func_fe6_0804FF94
.L0804FCCA:
	movs r3, #0x2c
	ldrsh r1, [r4, r3]
	adds r0, r6, #0
	adds r0, #0x5e
	cmp r1, r0
	bne .L0804FD00
	adds r0, r5, #0
	bl func_fe6_0804FDD4
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl StartBattleAnimHitEffectsDefault
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0804FD1C
	adds r0, r5, #0
	bl func_fe6_0805C358
	b .L0804FD1C
	.align 2, 0
.L0804FCFC: .4byte 0x00000119
.L0804FD00:
	adds r0, r6, #0
	adds r0, #0xc3
	cmp r1, r0
	beq .L0804FD1C
	adds r0, #5
	cmp r1, r0
	bne .L0804FD1C
	bl SpellFx_Finish
	bl func_fe6_08047358
	adds r0, r4, #0
	bl Proc_Break
.L0804FD1C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0804FD24
func_fe6_0804FD24: @ 0x0804FD24
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0804FD60 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804FD64 @ =gUnk_085D1604
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L0804FD68 @ =gUnk_0811A098
	str r1, [r0, #0x48]
	ldr r1, .L0804FD6C @ =gUnk_085D1648
	str r1, [r0, #0x4c]
	str r1, [r0, #0x50]
	ldr r1, .L0804FD70 @ =gUnk_085D161C
	str r1, [r0, #0x54]
	ldr r0, .L0804FD74 @ =gUnk_0813E75C
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	bl SpellFx_SetSomeColorEffect
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804FD60: .4byte gEfxBgSemaphore
.L0804FD64: .4byte gUnk_085D1604
.L0804FD68: .4byte gUnk_0811A098
.L0804FD6C: .4byte gUnk_085D1648
.L0804FD70: .4byte gUnk_085D161C
.L0804FD74: .4byte gUnk_0813E75C

	thumb_func_start func_fe6_0804FD78
func_fe6_0804FD78: @ 0x0804FD78
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r0, #0x2c
	adds r1, r7, #0
	adds r1, #0x44
	ldr r2, [r7, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	blt .L0804FDB4
	ldr r5, [r7, #0x4c]
	ldr r6, [r7, #0x50]
	ldr r0, [r7, #0x54]
	lsls r4, r4, #2
	adds r0, r4, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	ldr r0, [r7, #0x5c]
	adds r5, r4, r5
	ldr r1, [r5]
	adds r4, r4, r6
	ldr r2, [r4]
	bl SpellFx_WriteBgMap
	b .L0804FDCA
.L0804FDB4:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	bne .L0804FDCA
	ldr r1, .L0804FDD0 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r7, #0
	bl Proc_End
.L0804FDCA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804FDD0: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804FDD4
func_fe6_0804FDD4: @ 0x0804FDD4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0804FDF0 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804FDF4 @ =gUnk_085D1674
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804FDF0: .4byte gEfxBgSemaphore
.L0804FDF4: .4byte gUnk_085D1674

	thumb_func_start func_fe6_0804FDF8
func_fe6_0804FDF8: @ 0x0804FDF8
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	ldr r3, .L0804FE30 @ =gUnk_085E5858
	str r3, [sp]
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	str r0, [r4, #0x60]
	ldr r0, .L0804FE34 @ =gUnk_0812D80C
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0804FE38 @ =gUnk_0812D374
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	adds r0, r4, #0
	bl Proc_Break
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804FE30: .4byte gUnk_085E5858
.L0804FE34: .4byte gUnk_0812D80C
.L0804FE38: .4byte gUnk_0812D374

	thumb_func_start func_fe6_0804FE3C
func_fe6_0804FE3C: @ 0x0804FE3C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x60]
	bl BasRemove
	ldr r1, .L0804FE5C @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804FE5C: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804FE60
func_fe6_0804FE60: @ 0x0804FE60
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0804FE7C @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804FE80 @ =gUnk_085D169C
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804FE7C: .4byte gEfxBgSemaphore
.L0804FE80: .4byte gUnk_085D169C

	thumb_func_start func_fe6_0804FE84
func_fe6_0804FE84: @ 0x0804FE84
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x8d
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	movs r3, #1
	bl func_fe6_0805C804
	ldr r0, [r4, #0x5c]
	movs r1, #0x26
	bl NewEfxFlashBgWhite
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #5
	strh r0, [r4, #0x2e]
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0804FEB8
func_fe6_0804FEB8: @ 0x0804FEB8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r6, r0]
	movs r1, #0x2e
	ldrsh r0, [r6, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0
	bl Interpolate
	adds r5, r0, #0
	ldr r0, .L0804FF14 @ =gPal
	ldr r4, .L0804FF18 @ =gEfxPal
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r4, #0
	bl CpuFastSet
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x20
	adds r3, r5, #0
	bl EfxPalWhiteInOut
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r6, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0804FF0C
	movs r0, #0
	strh r0, [r6, #0x2c]
	movs r0, #0xa
	strh r0, [r6, #0x2e]
	adds r0, r6, #0
	bl Proc_Break
.L0804FF0C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804FF14: .4byte gPal
.L0804FF18: .4byte gEfxPal

	thumb_func_start func_fe6_0804FF1C
func_fe6_0804FF1C: @ 0x0804FF1C
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0
	bl Interpolate
	ldr r2, .L0804FF8C @ =gDispIo
	mov ip, r2
	mov r3, ip
	adds r3, #0x3c
	movs r1, #0x3f
	ldrb r2, [r3]
	ands r1, r2
	movs r2, #0x40
	orrs r1, r2
	strb r1, [r3]
	mov r1, ip
	adds r1, #0x44
	movs r2, #0
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x10
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x46
	strb r2, [r0]
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0804FF84
	bl SpellFx_ClearBG1
	bl SpellFx_ClearColorEffects
	ldr r1, .L0804FF90 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0804FF84:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804FF8C: .4byte gDispIo
.L0804FF90: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0804FF94
func_fe6_0804FF94: @ 0x0804FF94
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	ldr r1, .L0804FFC8 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0804FFCC @ =gPal
	ldr r1, .L0804FFD0 @ =gEfxPal
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuFastSet
	ldr r0, .L0804FFD4 @ =gUnk_085D16DC
	movs r1, #0
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	strh r6, [r0, #0x30]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804FFC8: .4byte gEfxBgSemaphore
.L0804FFCC: .4byte gPal
.L0804FFD0: .4byte gEfxPal
.L0804FFD4: .4byte gUnk_085D16DC

	thumb_func_start func_fe6_0804FFD8
func_fe6_0804FFD8: @ 0x0804FFD8
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r1, #0x2e
	ldrsh r0, [r5, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0x10
	bl Interpolate
	adds r3, r0, #0
	ldr r4, .L08050034 @ =gEfxPal
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x20
	bl EfxPalBlackInOut
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r4, #0
	bl CpuFastSet
	bl DisablePalSync
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r5, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0805002C
	movs r0, #0
	strh r0, [r5, #0x2c]
	adds r0, r5, #0
	bl Proc_Break
.L0805002C:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08050034: .4byte gEfxPal

	thumb_func_start func_fe6_08050038
func_fe6_08050038: @ 0x08050038
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L08050074 @ =gEfxPal
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuFastSet
	bl DisablePalSync
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x30]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0805006C
	ldr r1, .L08050078 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0805006C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08050074: .4byte gEfxPal
.L08050078: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0805007C
func_fe6_0805007C: @ 0x0805007C
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl func_fe6_08047300
	bl SpellFx_SetBG1Position
	ldr r0, .L080500B4 @ =gUnk_085D16FC
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080500B4: .4byte gUnk_085D16FC

	thumb_func_start func_fe6_080500B8
func_fe6_080500B8: @ 0x080500B8
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	adds r5, r0, #0
	bl EfxGetCamMovDuration
	adds r2, r0, #0
	ldr r0, .L08050110 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #0x3a
	cmp r0, #0
	beq .L080500DA
	movs r3, #0x32
.L080500DA:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r6, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08050114
	ldr r0, [r4, #0x5c]
	bl func_fe6_08050308
	movs r0, #0x84
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	movs r3, #1
	bl func_fe6_0805C804
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl NewEfxFarAttackWithDistance
	b .L080501B0
	.align 2, 0
.L08050110: .4byte gEkrDistanceType
.L08050114:
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	adds r0, r3, r2
	cmp r1, r0
	bne .L08050128
	ldr r0, [r4, #0x5c]
	movs r1, #6
	bl NewEfxFlashBgWhite
	b .L080501B0
.L08050128:
	adds r0, r2, #6
	adds r0, r3, r0
	cmp r1, r0
	bne .L08050164
	adds r0, r5, #0
	bl func_fe6_080501B8
	adds r0, r5, #0
	bl func_fe6_0805027C
	str r6, [sp]
	str r6, [sp, #4]
	adds r0, r5, #0
	movs r1, #6
	movs r2, #5
	movs r3, #0x10
	bl func_fe6_0804CD88
	ldr r0, .L08050160 @ =0x00000109
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl func_fe6_0805C804
	b .L080501B0
	.align 2, 0
.L08050160: .4byte 0x00000109
.L08050164:
	adds r0, r2, #0
	adds r0, #8
	adds r0, r3, r0
	cmp r1, r0
	bne .L0805018E
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl StartBattleAnimHitEffectsDefault
	ldrb r0, [r4]
	cmp r0, #0
	bne .L080501B0
	adds r0, r5, #0
	bl func_fe6_0805C358
	b .L080501B0
.L0805018E:
	adds r0, r2, #0
	adds r0, #0xc
	adds r0, r3, r0
	cmp r1, r0
	beq .L080501B0
	adds r0, r2, #0
	adds r0, #0xe
	adds r0, r3, r0
	cmp r1, r0
	bne .L080501B0
	bl SpellFx_Finish
	bl func_fe6_08047358
	adds r0, r4, #0
	bl Proc_Break
.L080501B0:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080501B8
func_fe6_080501B8: @ 0x080501B8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, .L08050204 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08050208 @ =gUnk_085D1714
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	str r0, [r4, #0x44]
	ldr r0, .L0805020C @ =gUnk_0811A0DE
	str r0, [r4, #0x48]
	ldr r0, .L08050210 @ =gUnk_085D172C
	str r0, [r4, #0x4c]
	ldr r0, .L08050214 @ =gUnk_08159D98
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	bl SpellFx_SetSomeColorEffect
	ldr r0, [r4, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L08050218
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L08050222
	.align 2, 0
.L08050204: .4byte gEfxBgSemaphore
.L08050208: .4byte gUnk_085D1714
.L0805020C: .4byte gUnk_0811A0DE
.L08050210: .4byte gUnk_085D172C
.L08050214: .4byte gUnk_08159D98
.L08050218:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L08050222:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08050228
func_fe6_08050228: @ 0x08050228
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L08050254
	ldr r2, [r4, #0x4c]
	ldr r0, [r4, #0x5c]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	movs r2, #0x20
	movs r3, #0x14
	bl SpellFx_WriteBgMapExt
	b .L08050272
.L08050254:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L08050272
	bl SpellFx_ClearBG1
	ldr r1, .L08050278 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	adds r0, r4, #0
	bl Proc_Break
.L08050272:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08050278: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0805027C
func_fe6_0805027C: @ 0x0805027C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L080502B0 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080502B4 @ =gUnk_085D1734
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	str r1, [r0, #0x44]
	ldr r1, .L080502B8 @ =gUnk_0811A0E8
	str r1, [r0, #0x48]
	ldr r1, .L080502BC @ =gUnk_0815B364
	str r1, [r0, #0x4c]
	adds r0, r1, #0
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080502B0: .4byte gEfxBgSemaphore
.L080502B4: .4byte gUnk_085D1734
.L080502B8: .4byte gUnk_0811A0E8
.L080502BC: .4byte gUnk_0815B364

	thumb_func_start func_fe6_080502C0
func_fe6_080502C0: @ 0x080502C0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L080502E6
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	b .L080502FC
.L080502E6:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080502FC
	ldr r1, .L08050304 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L080502FC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08050304: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08050308
func_fe6_08050308: @ 0x08050308
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, .L0805034C @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08050350 @ =gUnk_085D1754
	movs r1, #3
	bl SpawnProc
	adds r6, r0, #0
	str r4, [r6, #0x5c]
	movs r0, #0
	strh r0, [r6, #0x2c]
	ldr r1, .L08050354 @ =gUnk_085EA7F0
	ldr r2, .L08050358 @ =gUnk_085E90AC
	ldr r3, .L0805035C @ =gUnk_085EA8A4
	ldr r0, .L08050360 @ =gUnk_085E9160
	str r0, [sp]
	adds r0, r4, #0
	bl EfxCreateFrontAnim
	adds r5, r0, #0
	str r5, [r6, #0x60]
	adds r0, r4, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L08050364
	ldrh r0, [r5, #2]
	adds r0, #0x48
	b .L08050368
	.align 2, 0
.L0805034C: .4byte gEfxBgSemaphore
.L08050350: .4byte gUnk_085D1754
.L08050354: .4byte gUnk_085EA7F0
.L08050358: .4byte gUnk_085E90AC
.L0805035C: .4byte gUnk_085EA8A4
.L08050360: .4byte gUnk_085E9160
.L08050364:
	ldrh r0, [r5, #2]
	subs r0, #0x48
.L08050368:
	strh r0, [r5, #2]
	movs r0, #0x60
	strh r0, [r6, #0x2e]
	ldr r0, .L08050388 @ =gUnk_0815BED4
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0805038C @ =gUnk_0815B910
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08050388: .4byte gUnk_0815BED4
.L0805038C: .4byte gUnk_0815B910

	thumb_func_start func_fe6_08050390
func_fe6_08050390: @ 0x08050390
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x2c]
	adds r0, #1
	strh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	ldrh r3, [r2, #0x2e]
	lsls r1, r3, #0x10
	cmp r0, r1
	bne .L080503B2
	ldr r1, .L080503B8 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r2, #0
	bl Proc_Break
.L080503B2:
	pop {r0}
	bx r0
	.align 2, 0
.L080503B8: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_080503BC
func_fe6_080503BC: @ 0x080503BC
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl func_fe6_08047300
	bl SpellFx_SetBG1Position
	ldr r0, .L080503F4 @ =gUnk_085D176C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080503F4: .4byte gUnk_085D176C

	thumb_func_start func_fe6_080503F8
func_fe6_080503F8: @ 0x080503F8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	adds r5, r0, #0
	bl EfxGetCamMovDuration
	adds r2, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08050434
	movs r0, #0x85
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	movs r3, #1
	bl func_fe6_0805C804
	adds r0, r5, #0
	bl func_fe6_080504F0
	b .L080504E8
.L08050434:
	cmp r0, #0x18
	bne .L08050440
	ldr r0, [r4, #0x5c]
	bl func_fe6_080506B4
	b .L080504E8
.L08050440:
	cmp r0, #0x82
	bne .L08050450
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl NewEfxFarAttackWithDistance
	b .L080504E8
.L08050450:
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	adds r0, r2, #0
	adds r0, #0x83
	cmp r1, r0
	bne .L08050466
	adds r0, r5, #0
	bl func_fe6_080506F8
	str r0, [r4, #0x64]
	b .L080504E8
.L08050466:
	adds r0, r2, #0
	adds r0, #0x96
	cmp r1, r0
	bne .L0805048C
	ldr r0, .L08050488 @ =0x0000010B
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl func_fe6_0805C804
	ldr r0, [r4, #0x5c]
	bl func_fe6_080505A0
	b .L080504E8
	.align 2, 0
.L08050488: .4byte 0x0000010B
.L0805048C:
	adds r0, r2, #0
	adds r0, #0xaa
	cmp r1, r0
	bne .L0805049C
	ldr r0, [r4, #0x64]
	bl Proc_End
	b .L080504E8
.L0805049C:
	adds r0, r2, #0
	adds r0, #0xc3
	cmp r1, r0
	bne .L080504CC
	ldr r0, [r4, #0x5c]
	movs r1, #6
	bl NewEfxFlashBgWhite
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl StartBattleAnimHitEffectsDefault
	ldrb r0, [r4]
	cmp r0, #0
	bne .L080504E8
	adds r0, r5, #0
	bl func_fe6_0805C358
	b .L080504E8
.L080504CC:
	adds r0, r2, #0
	adds r0, #0xe6
	cmp r1, r0
	beq .L080504E8
	adds r0, #0xa
	cmp r1, r0
	bne .L080504E8
	bl SpellFx_Finish
	bl func_fe6_08047358
	adds r0, r4, #0
	bl Proc_Break
.L080504E8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080504F0
func_fe6_080504F0: @ 0x080504F0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L08050548 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0805054C @ =gUnk_085D1784
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L08050550 @ =gUnk_0811A102
	str r0, [r5, #0x48]
	ldr r0, .L08050554 @ =gUnk_085D179C
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L08050558 @ =gUnk_085D1840
	str r0, [r5, #0x54]
	ldr r0, .L0805055C @ =gUnk_0815F880
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	bl SpellFx_SetSomeColorEffect
	ldr r0, .L08050560 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L0805056E
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L08050564
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
	b .L0805056E
	.align 2, 0
.L08050548: .4byte gEfxBgSemaphore
.L0805054C: .4byte gUnk_085D1784
.L08050550: .4byte gUnk_0811A102
.L08050554: .4byte gUnk_085D179C
.L08050558: .4byte gUnk_085D1840
.L0805055C: .4byte gUnk_0815F880
.L08050560: .4byte gEkrDistanceType
.L08050564:
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
.L0805056E:
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L08050584
	ldr r0, .L08050580 @ =gDispIo
	ldrh r1, [r0, #0x20]
	adds r1, #4
	b .L0805058A
	.align 2, 0
.L08050580: .4byte gDispIo
.L08050584:
	ldr r0, .L0805059C @ =gDispIo
	ldrh r1, [r0, #0x20]
	subs r1, #4
.L0805058A:
	strh r1, [r0, #0x20]
	adds r1, r0, #0
	ldrh r0, [r1, #0x22]
	adds r0, #8
	strh r0, [r1, #0x22]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805059C: .4byte gDispIo

	thumb_func_start func_fe6_080505A0
func_fe6_080505A0: @ 0x080505A0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L08050620 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08050624 @ =gUnk_085D1784
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r4, #0
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L08050628 @ =gUnk_0811A134
	str r0, [r5, #0x48]
	ldr r0, .L0805062C @ =gUnk_085D179C
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L08050630 @ =gUnk_085D1840
	str r0, [r5, #0x54]
	ldr r0, .L08050634 @ =gUnk_0815F8A0
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	bl SpellFx_SetSomeColorEffect
	ldr r3, .L08050638 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r1, r3, #0
	adds r1, #0x44
	movs r0, #0xa
	strb r0, [r1]
	adds r1, #1
	movs r0, #7
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x46
	strb r4, [r0]
	ldr r0, .L0805063C @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L0805064A
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L08050640
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
	b .L0805064A
	.align 2, 0
.L08050620: .4byte gEfxBgSemaphore
.L08050624: .4byte gUnk_085D1784
.L08050628: .4byte gUnk_0811A134
.L0805062C: .4byte gUnk_085D179C
.L08050630: .4byte gUnk_085D1840
.L08050634: .4byte gUnk_0815F8A0
.L08050638: .4byte gDispIo
.L0805063C: .4byte gEkrDistanceType
.L08050640:
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
.L0805064A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08050650
func_fe6_08050650: @ 0x08050650
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r0, #0x2c
	adds r1, r7, #0
	adds r1, #0x44
	ldr r2, [r7, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	blt .L0805068C
	ldr r5, [r7, #0x4c]
	ldr r6, [r7, #0x50]
	ldr r0, [r7, #0x54]
	lsls r4, r4, #2
	adds r0, r4, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	ldr r0, [r7, #0x5c]
	adds r5, r4, r5
	ldr r1, [r5]
	adds r4, r4, r6
	ldr r2, [r4]
	bl SpellFx_WriteBgMap
	b .L080506AA
.L0805068C:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	bne .L080506AA
	bl SpellFx_ClearBG1
	ldr r1, .L080506B0 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	adds r0, r7, #0
	bl Proc_End
.L080506AA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080506B0: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_080506B4
func_fe6_080506B4: @ 0x080506B4
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L080506EC @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080506F0 @ =gUnk_085D18E4
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	adds r0, r5, #0
	bl GetAnimAnotherSide
	ldr r3, .L080506F4 @ =AnimScr_ManaketeFlame
	ldr r0, [r4, #0x5c]
	str r3, [sp]
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	str r0, [r4, #0x60]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080506EC: .4byte gEfxBgSemaphore
.L080506F0: .4byte gUnk_085D18E4
.L080506F4: .4byte AnimScr_ManaketeFlame

	thumb_func_start func_fe6_080506F8
func_fe6_080506F8: @ 0x080506F8
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L08050738 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0805073C @ =gUnk_085D192C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	adds r0, r5, #0
	bl GetAnimAnotherSide
	ldr r3, .L08050740 @ =AnimScr_ManaketeFlame
	ldr r0, [r4, #0x5c]
	str r3, [sp]
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	str r0, [r4, #0x60]
	ldrh r1, [r0, #4]
	subs r1, #4
	strh r1, [r0, #4]
	adds r0, r4, #0
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
.L08050738: .4byte gEfxBgSemaphore
.L0805073C: .4byte gUnk_085D192C
.L08050740: .4byte AnimScr_ManaketeFlame

	thumb_func_start func_fe6_08050744
func_fe6_08050744: @ 0x08050744
	push {lr}
	ldr r2, .L08050758 @ =gEfxBgSemaphore
	ldr r1, [r2]
	subs r1, #1
	str r1, [r2]
	ldr r0, [r0, #0x60]
	bl BasRemove
	pop {r0}
	bx r0
	.align 2, 0
.L08050758: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0805075C
func_fe6_0805075C: @ 0x0805075C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, .L0805078C @ =gUnk_085EABC0
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L08050790 @ =gUnk_081629D4
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L08050794 @ =gUnk_08161DDC
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805078C: .4byte gUnk_085EABC0
.L08050790: .4byte gUnk_081629D4
.L08050794: .4byte gUnk_08161DDC

	thumb_func_start func_fe6_08050798
func_fe6_08050798: @ 0x08050798
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, .L080507C8 @ =gUnk_085EADB0
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L080507CC @ =gUnk_081629D4
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L080507D0 @ =gUnk_081621DC
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080507C8: .4byte gUnk_085EADB0
.L080507CC: .4byte gUnk_081629D4
.L080507D0: .4byte gUnk_081621DC

	thumb_func_start func_fe6_080507D4
func_fe6_080507D4: @ 0x080507D4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, .L08050804 @ =gUnk_085EB264
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L08050808 @ =gUnk_081629D4
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0805080C @ =gUnk_0816261C
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08050804: .4byte gUnk_085EB264
.L08050808: .4byte gUnk_081629D4
.L0805080C: .4byte gUnk_0816261C

	thumb_func_start func_fe6_08050810
func_fe6_08050810: @ 0x08050810
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, .L08050838 @ =gUnk_085EB1A8
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	movs r0, #0x14
	strh r0, [r1, #0xa]
	bl BasSort
	movs r0, #0x27
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08050838: .4byte gUnk_085EB1A8

	thumb_func_start func_fe6_0805083C
func_fe6_0805083C: @ 0x0805083C
	adds r1, r0, #0
	ldr r2, [r1, #0x60]
	ldrh r0, [r1, #0x2c]
	adds r0, #1
	movs r3, #0
	strh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x28
	bne .L0805085A
	ldr r0, .L0805085C @ =gUnk_085EB1DC
	str r0, [r2, #0x24]
	str r0, [r2, #0x20]
	strh r3, [r2, #6]
	strh r3, [r1, #0x2c]
.L0805085A:
	bx lr
	.align 2, 0
.L0805085C: .4byte gUnk_085EB1DC

	thumb_func_start func_fe6_08050860
func_fe6_08050860: @ 0x08050860
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl func_fe6_08047300
	bl SpellFx_SetBG1Position
	ldr r0, .L08050898 @ =gUnk_085D195C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08050898: .4byte gUnk_085D195C

	thumb_func_start func_fe6_0805089C
func_fe6_0805089C: @ 0x0805089C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	adds r6, r0, #0
	bl EfxGetCamMovDuration
	adds r5, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r1, #0
	mov r8, r1
	movs r7, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L080508D2
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl NewEfxFarAttackWithDistance
.L080508D2:
	movs r2, #0x2c
	ldrsh r1, [r4, r2]
	adds r0, r5, #1
	cmp r1, r0
	bne .L08050930
	ldr r3, .L0805092C @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	mov r2, r8
	strb r2, [r0]
	adds r0, #1
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	str r1, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0xa
	movs r3, #0
	bl func_fe6_0804CD88
	str r7, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r1, #0x28
	movs r2, #0x28
	movs r3, #0x10
	bl func_fe6_0804CD88
	adds r0, r6, #0
	bl func_fe6_08050A70
	movs r0, #0x92
	lsls r0, r0, #1
	b .L08050982
	.align 2, 0
.L0805092C: .4byte gDispIo
.L08050930:
	adds r0, r5, #0
	adds r0, #0xf
	cmp r1, r0
	bne .L0805096C
	movs r0, #2
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #0x52
	movs r2, #0xf
	movs r3, #0
	bl func_fe6_0804C8D4
	adds r1, r0, #0
	adds r0, r6, #0
	movs r2, #0x3c
	bl func_fe6_08050D68
	ldr r0, .L08050964 @ =gDispIo
	movs r1, #0x20
	ldrsh r2, [r0, r1]
	ldr r3, .L08050968 @ =func_fe6_0804CD4C
	adds r0, r6, #0
	movs r1, #0x53
	bl func_fe6_0804CB8C
	b .L080509D8
	.align 2, 0
.L08050964: .4byte gDispIo
.L08050968: .4byte func_fe6_0804CD4C
.L0805096C:
	adds r0, r5, #0
	adds r0, #0x64
	cmp r1, r0
	bne .L08050998
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r1, [r0]
	adds r0, r6, #0
	bl func_fe6_080509E4
	ldr r0, .L08050994 @ =0x00000125
.L08050982:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r6, r3]
	movs r3, #1
	bl func_fe6_0805C804
	b .L080509D8
	.align 2, 0
.L08050994: .4byte 0x00000125
.L08050998:
	adds r0, r5, #0
	adds r0, #0x69
	cmp r1, r0
	bne .L080509C0
	movs r0, #9
	ldrh r1, [r6, #0x10]
	orrs r0, r1
	strh r0, [r6, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r6, #0
	bl StartBattleAnimResireHitEffects
	ldrb r0, [r4]
	cmp r0, #0
	bne .L080509D8
	adds r0, r6, #0
	bl func_fe6_0805C358
	b .L080509D8
.L080509C0:
	adds r0, r5, #0
	adds r0, #0x96
	cmp r1, r0
	beq .L080509D8
	adds r0, #0x14
	cmp r1, r0
	bne .L080509D8
	bl SpellFx_Finish
	adds r0, r4, #0
	bl Proc_Break
.L080509D8:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080509E4
func_fe6_080509E4: @ 0x080509E4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L08050A44 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08050A48 @ =gUnk_085D1974
	movs r1, #3
	bl SpawnProc
	adds r6, r0, #0
	str r4, [r6, #0x5c]
	adds r1, r6, #0
	adds r1, #0x29
	movs r0, #0
	strb r5, [r1]
	strh r0, [r6, #0x2c]
	str r0, [r6, #0x44]
	ldr r0, .L08050A4C @ =gUnk_0811A1AA
	str r0, [r6, #0x48]
	ldr r0, .L08050A50 @ =gUnk_085D1A88
	str r0, [r6, #0x4c]
	str r0, [r6, #0x50]
	ldr r0, .L08050A54 @ =gUnk_085D19BC
	str r0, [r6, #0x54]
	ldr r0, .L08050A58 @ =gUnk_0816B328
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	bl SpellFx_SetSomeColorEffect
	ldr r0, .L08050A5C @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08050A6A
	ldr r0, [r6, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L08050A60
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L08050A6A
	.align 2, 0
.L08050A44: .4byte gEfxBgSemaphore
.L08050A48: .4byte gUnk_085D1974
.L08050A4C: .4byte gUnk_0811A1AA
.L08050A50: .4byte gUnk_085D1A88
.L08050A54: .4byte gUnk_085D19BC
.L08050A58: .4byte gUnk_0816B328
.L08050A5C: .4byte gEkrDistanceType
.L08050A60:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L08050A6A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08050A70
func_fe6_08050A70: @ 0x08050A70
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L08050AE0 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08050AE4 @ =gUnk_085D19A4
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L08050AE8 @ =gUnk_0811A276
	str r0, [r5, #0x48]
	ldr r0, .L08050AEC @ =gUnk_085D1A88
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L08050AF0 @ =gUnk_085D19BC
	str r0, [r5, #0x54]
	ldr r0, .L08050AF4 @ =gUnk_0816B328
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	bl SpellFx_SetSomeColorEffect
	ldr r2, .L08050AF8 @ =gDispIo
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrb r1, [r2, #1]
	ands r0, r1
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r2, #1]
	ldr r0, .L08050AFC @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08050B0A
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L08050B00
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L08050B0A
	.align 2, 0
.L08050AE0: .4byte gEfxBgSemaphore
.L08050AE4: .4byte gUnk_085D19A4
.L08050AE8: .4byte gUnk_0811A276
.L08050AEC: .4byte gUnk_085D1A88
.L08050AF0: .4byte gUnk_085D19BC
.L08050AF4: .4byte gUnk_0816B328
.L08050AF8: .4byte gDispIo
.L08050AFC: .4byte gEkrDistanceType
.L08050B00:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L08050B0A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08050B10
func_fe6_08050B10: @ 0x08050B10
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r0, #0x2c
	adds r1, r7, #0
	adds r1, #0x44
	ldr r2, [r7, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	blt .L08050B4C
	ldr r5, [r7, #0x4c]
	ldr r6, [r7, #0x50]
	ldr r0, [r7, #0x54]
	lsls r4, r4, #2
	adds r0, r4, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	ldr r0, [r7, #0x5c]
	adds r5, r4, r5
	ldr r1, [r5]
	adds r4, r4, r6
	ldr r2, [r4]
	bl SpellFx_WriteBgMap
	b .L08050B8E
.L08050B4C:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	bne .L08050B8E
	bl SpellFx_ClearBG1
	adds r0, r7, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #1
	bne .L08050B80
	ldr r1, .L08050B7C @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	bl func_fe6_08047358
	adds r0, r7, #0
	bl Proc_End
	b .L08050B8E
	.align 2, 0
.L08050B7C: .4byte gEfxBgSemaphore
.L08050B80:
	movs r0, #0
	strh r0, [r7, #0x2c]
	movs r0, #0x1e
	strh r0, [r7, #0x2e]
	adds r0, r7, #0
	bl Proc_Break
.L08050B8E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08050B94
func_fe6_08050B94: @ 0x08050B94
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, .L08050BB8 @ =gEfxHpBarResireFlag
	ldr r0, [r5]
	cmp r0, #2
	bne .L08050BC0
	ldr r1, .L08050BBC @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	bl func_fe6_08047358
	adds r0, r4, #0
	bl Proc_End
	b .L08050C1A
	.align 2, 0
.L08050BB8: .4byte gEfxHpBarResireFlag
.L08050BBC: .4byte gEfxBgSemaphore
.L08050BC0:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r3, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x2e
	ldrsh r2, [r4, r1]
	ldrh r1, [r4, #0x2e]
	cmp r0, r2
	ble .L08050BD8
	strh r1, [r4, #0x2c]
.L08050BD8:
	movs r1, #0x2c
	ldrsh r0, [r4, r1]
	cmp r0, r2
	bne .L08050C1A
	ldr r0, [r5]
	cmp r0, #1
	bne .L08050C1A
	strh r3, [r4, #0x2c]
	strh r3, [r4, #0x2e]
	str r3, [r4, #0x44]
	ldr r0, .L08050C20 @ =gUnk_0811A218
	str r0, [r4, #0x48]
	ldr r0, .L08050C24 @ =gUnk_085D1A88
	str r0, [r4, #0x4c]
	str r0, [r4, #0x50]
	ldr r0, .L08050C28 @ =gUnk_085D19BC
	str r0, [r4, #0x54]
	ldr r0, .L08050C2C @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08050C14
	bl EfxGetCamMovDuration
	strh r0, [r4, #0x2e]
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl NewEfxFarAttackWithDistance
.L08050C14:
	adds r0, r4, #0
	bl Proc_Break
.L08050C1A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08050C20: .4byte gUnk_0811A218
.L08050C24: .4byte gUnk_085D1A88
.L08050C28: .4byte gUnk_085D19BC
.L08050C2C: .4byte gEkrDistanceType

	thumb_func_start func_fe6_08050C30
func_fe6_08050C30: @ 0x08050C30
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	adds r5, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08050C96
	ldr r0, .L08050C6C @ =gEkrDistanceType
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	beq .L08050C7A
	ldr r0, [r4, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L08050C70
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
	b .L08050C7A
	.align 2, 0
.L08050C6C: .4byte gEkrDistanceType
.L08050C70:
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
.L08050C7A:
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x93
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl func_fe6_0805C804
	adds r0, r4, #0
	bl Proc_Break
.L08050C96:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08050C9C
func_fe6_08050C9C: @ 0x08050C9C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r0, #0x2c
	adds r1, r7, #0
	adds r1, #0x44
	ldr r2, [r7, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	blt .L08050CD8
	ldr r5, [r7, #0x4c]
	ldr r6, [r7, #0x50]
	ldr r0, [r7, #0x54]
	lsls r4, r4, #2
	adds r0, r4, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	ldr r0, [r7, #0x5c]
	adds r5, r4, r5
	ldr r1, [r5]
	adds r4, r4, r6
	ldr r2, [r4]
	bl SpellFx_WriteBgMap
	b .L08050CFA
.L08050CD8:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	bne .L08050CFA
	bl SpellFx_ClearBG1
	ldr r1, .L08050D00 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	bl func_fe6_08047358
	adds r0, r7, #0
	bl Proc_Break
.L08050CFA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08050D00: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08050D04
func_fe6_08050D04: @ 0x08050D04
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r0, #0x2c
	adds r1, r7, #0
	adds r1, #0x44
	ldr r2, [r7, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	blt .L08050D40
	ldr r5, [r7, #0x4c]
	ldr r6, [r7, #0x50]
	ldr r0, [r7, #0x54]
	lsls r4, r4, #2
	adds r0, r4, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	ldr r0, [r7, #0x5c]
	adds r5, r4, r5
	ldr r1, [r5]
	adds r4, r4, r6
	ldr r2, [r4]
	bl SpellFx_WriteBgMap
	b .L08050D5E
.L08050D40:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	bne .L08050D5E
	bl SpellFx_ClearBG1
	ldr r1, .L08050D64 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	adds r0, r7, #0
	bl Proc_Break
.L08050D5E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08050D64: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08050D68
func_fe6_08050D68: @ 0x08050D68
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	ldr r1, .L08050D90 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08050D94 @ =gUnk_085D1B54
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	str r6, [r0, #0x64]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08050D90: .4byte gEfxBgSemaphore
.L08050D94: .4byte gUnk_085D1B54

	thumb_func_start func_fe6_08050D98
func_fe6_08050D98: @ 0x08050D98
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r4, [r5, #0x64]
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r1, #0x2e
	ldrsh r0, [r5, r1]
	str r0, [sp]
	movs r0, #4
	movs r1, #0
	movs r2, #0x80
	bl Interpolate
	str r0, [r4, #0x4c]
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r5, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08050DD4
	ldr r1, .L08050DDC @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r5, #0
	bl Proc_Break
.L08050DD4:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08050DDC: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08050DE0
func_fe6_08050DE0: @ 0x08050DE0
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl func_fe6_08047300
	bl SpellFx_SetBG1Position
	ldr r0, .L08050E18 @ =gUnk_085D1B6C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08050E18: .4byte gUnk_085D1B6C

	thumb_func_start func_fe6_08050E1C
func_fe6_08050E1C: @ 0x08050E1C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	adds r5, r0, #0
	bl EfxGetCamMovDuration
	adds r6, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08050E46
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl NewEfxFarAttackWithDistance
.L08050E46:
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	adds r0, r6, #1
	cmp r1, r0
	bne .L08050E6A
	movs r0, #0x90
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl func_fe6_0805C804
	adds r0, r5, #0
	bl func_fe6_08050ED4
	b .L08050ECC
.L08050E6A:
	adds r0, r6, #0
	adds r0, #0x1a
	cmp r1, r0
	bne .L08050EB0
	ldr r0, .L08050EAC @ =0x00000121
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl func_fe6_0805C804
	ldr r0, [r4, #0x5c]
	movs r1, #4
	bl NewEfxFlashBgWhite
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl StartBattleAnimHitEffectsDefault
	ldrb r0, [r4]
	cmp r0, #0
	bne .L08050ECC
	adds r0, r5, #0
	bl func_fe6_0805C358
	b .L08050ECC
	.align 2, 0
.L08050EAC: .4byte 0x00000121
.L08050EB0:
	adds r0, r6, #0
	adds r0, #0x2f
	cmp r1, r0
	beq .L08050ECC
	adds r0, #1
	cmp r1, r0
	bne .L08050ECC
	bl SpellFx_Finish
	bl func_fe6_08047358
	adds r0, r4, #0
	bl Proc_Break
.L08050ECC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08050ED4
func_fe6_08050ED4: @ 0x08050ED4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L08050F28 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08050F2C @ =gUnk_085D1B84
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L08050F30 @ =gUnk_0811A27C
	str r0, [r5, #0x48]
	ldr r0, .L08050F34 @ =gUnk_085D1CA4
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L08050F38 @ =gUnk_085D1B9C
	str r0, [r5, #0x54]
	ldr r0, .L08050F3C @ =gUnk_085D1C20
	str r0, [r5, #0x58]
	bl SpellFx_SetSomeColorEffect
	ldr r0, .L08050F40 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08050F4E
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L08050F44
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L08050F4E
	.align 2, 0
.L08050F28: .4byte gEfxBgSemaphore
.L08050F2C: .4byte gUnk_085D1B84
.L08050F30: .4byte gUnk_0811A27C
.L08050F34: .4byte gUnk_085D1CA4
.L08050F38: .4byte gUnk_085D1B9C
.L08050F3C: .4byte gUnk_085D1C20
.L08050F40: .4byte gEkrDistanceType
.L08050F44:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L08050F4E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08050F54
func_fe6_08050F54: @ 0x08050F54
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	adds r0, #0x2c
	adds r1, r7, #0
	adds r1, #0x44
	ldr r2, [r7, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r5, r0, #0x10
	cmp r5, #0
	blt .L08050FDC
	ldr r6, [r7, #0x4c]
	ldr r0, [r7, #0x50]
	mov r8, r0
	ldr r0, [r7, #0x54]
	ldr r4, [r7, #0x58]
	lsls r5, r5, #2
	adds r0, r5, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	adds r4, r5, r4
	ldr r0, [r4]
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	ldr r0, [r7, #0x5c]
	adds r6, r5, r6
	ldr r1, [r6]
	add r5, r8
	ldr r2, [r5]
	bl SpellFx_WriteBgMap
	ldr r0, .L08050FBC @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08050FFA
	ldr r0, [r7, #0x5c]
	bl GetAnimPosition
	adds r1, r0, #0
	cmp r1, #0
	bne .L08050FC4
	ldr r0, .L08050FC0 @ =gBg1Tm
	b .L08050FC8
	.align 2, 0
.L08050FBC: .4byte gEkrDistanceType
.L08050FC0: .4byte gBg1Tm
.L08050FC4:
	ldr r0, .L08050FD8 @ =gBg1Tm+0x3A
	movs r1, #0
.L08050FC8:
	str r1, [sp]
	movs r1, #3
	movs r2, #0x14
	movs r3, #0
	bl FillBGRect
	b .L08050FFA
	.align 2, 0
.L08050FD8: .4byte gBg1Tm+0x3A
.L08050FDC:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r5, r0
	bne .L08050FFA
	bl SpellFx_ClearBG1
	ldr r1, .L08051008 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	adds r0, r7, #0
	bl Proc_End
.L08050FFA:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08051008: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0805100C
func_fe6_0805100C: @ 0x0805100C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl func_fe6_08047300
	bl SpellFx_SetBG1Position
	ldr r0, .L08051048 @ =gUnk_085D1D28
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r6, #0
	strh r6, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	ldr r0, .L0805104C @ =gUnk_Banim_0201E7A8
	str r6, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08051048: .4byte gUnk_085D1D28
.L0805104C: .4byte gUnk_Banim_0201E7A8

	thumb_func_start func_fe6_08051050
func_fe6_08051050: @ 0x08051050
	push {lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldr r0, .L0805106C @ =gUnk_Banim_0201E7A8
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq .L08051070
	adds r1, #0xff
	movs r0, #0xfe
	bl func_fe6_0805C804
	b .L0805107A
	.align 2, 0
.L0805106C: .4byte gUnk_Banim_0201E7A8
.L08051070:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0xff
	bl func_fe6_0805C804
.L0805107A:
	ldr r1, .L08051088 @ =gUnk_Banim_0201E7A8
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
.L08051088: .4byte gUnk_Banim_0201E7A8

	thumb_func_start func_fe6_0805108C
func_fe6_0805108C: @ 0x0805108C
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	ldr r0, [r6, #0x5c]
	bl GetAnimAnotherSide
	adds r5, r0, #0
	bl EfxGetCamMovDuration
	adds r4, r0, #0
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	movs r7, #0
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L080510BA
	ldr r0, [r6, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl NewEfxFarAttackWithDistance
.L080510BA:
	movs r0, #0x2c
	ldrsh r1, [r6, r0]
	adds r0, r4, #1
	cmp r1, r0
	bne .L080510DC
	adds r0, r5, #0
	movs r1, #4
	bl NewEfxFlashBgWhite
	adds r0, r5, #0
	bl func_fe6_080511BC
	adds r0, r5, #0
	bl func_fe6_08051288
	movs r0, #0x30
	b .L08051102
.L080510DC:
	adds r0, r4, #0
	adds r0, #0x15
	cmp r1, r0
	bne .L080510F0
	adds r0, r5, #0
	movs r1, #4
	bl NewEfxFlashBgWhite
	movs r0, #0xa0
	b .L08051102
.L080510F0:
	adds r0, r4, #0
	adds r0, #0x29
	cmp r1, r0
	bne .L0805110A
	adds r0, r5, #0
	movs r1, #4
	bl NewEfxFlashBgWhite
	movs r0, #0x70
.L08051102:
	movs r1, #0
	bl func_fe6_08051050
	b .L080511B4
.L0805110A:
	adds r0, r4, #0
	adds r0, #0x3d
	cmp r1, r0
	bne .L0805113E
	adds r0, r5, #0
	movs r1, #4
	bl NewEfxFlashBgWhite
	movs r0, #0x10
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r1, #3
	movs r2, #0xa
	movs r3, #0
	bl func_fe6_0804CD88
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	adds r0, r1, #0
	movs r3, #1
	bl func_fe6_0805C804
	b .L080511B4
.L0805113E:
	adds r0, r4, #0
	adds r0, #0x5e
	cmp r1, r0
	bne .L08051184
	adds r0, r5, #0
	movs r1, #4
	bl NewEfxFlashBgWhite
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, r6, #0
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl StartBattleAnimHitEffectsDefault
	ldr r0, .L08051180 @ =0x00000101
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl func_fe6_0805C804
	ldrb r0, [r4]
	cmp r0, #0
	bne .L080511B4
	adds r0, r5, #0
	bl func_fe6_0805C358
	b .L080511B4
	.align 2, 0
.L08051180: .4byte 0x00000101
.L08051184:
	adds r0, r4, #0
	adds r0, #0x69
	cmp r1, r0
	bne .L0805119E
	str r7, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0x14
	movs r3, #8
	bl func_fe6_0804CD88
	b .L080511B4
.L0805119E:
	adds r0, r4, #0
	adds r0, #0x71
	cmp r1, r0
	bne .L080511B4
	bl SpellFx_Finish
	bl func_fe6_08047358
	adds r0, r6, #0
	bl Proc_Break
.L080511B4:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080511BC
func_fe6_080511BC: @ 0x080511BC
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L080511F4 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080511F8 @ =gUnk_085D1D40
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L080511FC @ =gUnk_0811A302
	str r1, [r0, #0x48]
	ldr r1, .L08051200 @ =gUnk_085D1FC8
	str r1, [r0, #0x4c]
	str r1, [r0, #0x50]
	ldr r1, .L08051204 @ =gUnk_085D1D58
	str r1, [r0, #0x54]
	ldr r1, .L08051208 @ =gUnk_085D1E90
	str r1, [r0, #0x58]
	bl SpellFx_SetSomeColorEffect
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080511F4: .4byte gEfxBgSemaphore
.L080511F8: .4byte gUnk_085D1D40
.L080511FC: .4byte gUnk_0811A302
.L08051200: .4byte gUnk_085D1FC8
.L08051204: .4byte gUnk_085D1D58
.L08051208: .4byte gUnk_085D1E90

	thumb_func_start func_fe6_0805120C
func_fe6_0805120C: @ 0x0805120C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r0, #0x2c
	adds r1, r7, #0
	adds r1, #0x44
	ldr r2, [r7, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r5, r0, #0x10
	cmp r5, #0
	blt .L0805125A
	ldr r6, [r7, #0x4c]
	ldr r0, [r7, #0x50]
	mov r8, r0
	ldr r0, [r7, #0x54]
	ldr r4, [r7, #0x58]
	lsls r5, r5, #2
	adds r0, r5, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	adds r4, r5, r4
	ldr r0, [r4]
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	ldr r0, [r7, #0x5c]
	adds r6, r5, r6
	ldr r1, [r6]
	add r5, r8
	ldr r2, [r5]
	bl SpellFx_WriteBgMap
	b .L08051278
.L0805125A:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r5, r0
	bne .L08051278
	bl SpellFx_ClearBG1
	ldr r1, .L08051284 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	adds r0, r7, #0
	bl Proc_End
.L08051278:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08051284: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08051288
func_fe6_08051288: @ 0x08051288
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L080512B4 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080512B8 @ =gUnk_085D2100
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r2, #0
	strh r2, [r0, #0x2c]
	movs r1, #7
	str r1, [r0, #0x44]
	strh r2, [r0, #0x2e]
	movs r1, #6
	str r1, [r0, #0x48]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080512B4: .4byte gEfxBgSemaphore
.L080512B8: .4byte gUnk_085D2100

	thumb_func_start func_fe6_080512BC
func_fe6_080512BC: @ 0x080512BC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r5, #0x44]
	cmp r0, r1
	ble .L08051318
	movs r0, #0
	strh r0, [r5, #0x2c]
	ldr r2, .L08051320 @ =gUnk_085D2120
	movs r1, #0x2e
	ldrsh r0, [r5, r1]
	lsls r1, r0, #3
	adds r1, r1, r2
	ldr r4, [r1]
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r2, [r0]
	ldr r0, [r5, #0x60]
	adds r1, r4, #0
	bl func_fe6_08051328
	adds r0, r4, #0
	movs r1, #1
	bl func_fe6_08051050
	ldrh r0, [r5, #0x2e]
	adds r0, #1
	strh r0, [r5, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r5, #0x48]
	cmp r0, r1
	ble .L08051318
	ldr r1, .L08051324 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r5, #0
	bl Proc_Break
.L08051318:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08051320: .4byte gUnk_085D2120
.L08051324: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08051328
func_fe6_08051328: @ 0x08051328
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r2
	ldr r1, .L08051380 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08051384 @ =gUnk_085D2158
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	ldr r3, .L08051388 @ =gUnk_085EDCC8
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	str r0, [r4, #0x60]
	strh r6, [r0, #2]
	mov r1, r8
	strh r1, [r0, #4]
	ldr r0, .L0805138C @ =gUnk_081AB190
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L08051390 @ =gUnk_081AAECC
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08051380: .4byte gEfxBgSemaphore
.L08051384: .4byte gUnk_085D2158
.L08051388: .4byte gUnk_085EDCC8
.L0805138C: .4byte gUnk_081AB190
.L08051390: .4byte gUnk_081AAECC

	thumb_func_start func_fe6_08051394
func_fe6_08051394: @ 0x08051394
	push {lr}
	ldr r0, [r0, #0x60]
	bl BasRemove
	ldr r1, .L080513A8 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
.L080513A8: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_080513AC
func_fe6_080513AC: @ 0x080513AC
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl func_fe6_08047300
	bl SpellFx_SetBG1Position
	ldr r0, .L080513E4 @ =gUnk_085D2178
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080513E4: .4byte gUnk_085D2178

	thumb_func_start func_fe6_080513E8
func_fe6_080513E8: @ 0x080513E8
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	ldr r0, [r6, #0x5c]
	bl GetAnimAnotherSide
	adds r5, r0, #0
	bl EfxGetCamMovDuration
	adds r4, r0, #0
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	movs r7, #0
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08051416
	ldr r0, [r6, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl NewEfxFarAttackWithDistance
.L08051416:
	movs r0, #0x2c
	ldrsh r1, [r6, r0]
	adds r0, r4, #1
	cmp r1, r0
	bne .L08051448
	adds r0, r5, #0
	bl func_fe6_0805151C
	bl func_fe6_080516B8
	adds r0, r5, #0
	movs r1, #0xa0
	bl func_fe6_08051624
	ldr r0, .L08051444 @ =0x0000012D
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl func_fe6_0805C804
	b .L08051514
	.align 2, 0
.L08051444: .4byte 0x0000012D
.L08051448:
	adds r0, r4, #0
	adds r0, #0x5a
	cmp r1, r0
	bne .L0805146A
	adds r0, r5, #0
	movs r1, #0x3c
	bl func_fe6_08051720
	movs r0, #0x97
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0x78
	movs r3, #0
	bl func_fe6_0805C804
	b .L08051514
.L0805146A:
	adds r0, r4, #0
	adds r0, #0xa0
	cmp r1, r0
	bne .L0805147C
	ldr r0, [r6, #0x5c]
	movs r1, #3
	bl NewEfxFlashBgRed
	b .L08051514
.L0805147C:
	adds r0, r4, #0
	adds r0, #0xa3
	cmp r1, r0
	bne .L080514F4
	adds r0, r5, #0
	movs r1, #0x64
	bl func_fe6_0804D050
	adds r0, r5, #0
	movs r1, #0x64
	bl func_fe6_08051870
	str r7, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x50
	movs r2, #0x14
	movs r3, #0x10
	bl func_fe6_0804CD88
	ldr r2, .L080514EC @ =func_fe6_08051C00
	adds r0, r5, #0
	movs r1, #0x64
	bl func_fe6_0804CC68
	movs r0, #0x64
	bl func_fe6_08051C30
	adds r0, r5, #0
	bl func_fe6_08051A14
	ldr r0, .L080514F0 @ =0x0000012F
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0x78
	movs r3, #0
	bl func_fe6_0805C804
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, r6, #0
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl StartBattleAnimHitEffectsDefault
	ldrb r0, [r4]
	cmp r0, #0
	bne .L08051514
	adds r0, r5, #0
	bl func_fe6_0805C358
	b .L08051514
	.align 2, 0
.L080514EC: .4byte func_fe6_08051C00
.L080514F0: .4byte 0x0000012F
.L080514F4:
	adds r0, r4, #0
	adds r0, #0xfa
	cmp r1, r0
	beq .L08051514
	movs r2, #0x82
	lsls r2, r2, #1
	adds r0, r4, r2
	cmp r1, r0
	bne .L08051514
	bl SpellFx_Finish
	bl func_fe6_08047358
	adds r0, r6, #0
	bl Proc_Break
.L08051514:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805151C
func_fe6_0805151C: @ 0x0805151C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L08051570 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08051574 @ =gUnk_085D2190
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L08051578 @ =gUnk_0811A478
	str r0, [r5, #0x48]
	ldr r0, .L0805157C @ =gUnk_085D21A8
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L08051580 @ =gUnk_085D21DC
	str r0, [r5, #0x54]
	ldr r0, .L08051584 @ =gUnk_081408CC
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	ldr r0, .L08051588 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08051596
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L0805158C
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L08051596
	.align 2, 0
.L08051570: .4byte gEfxBgSemaphore
.L08051574: .4byte gUnk_085D2190
.L08051578: .4byte gUnk_0811A478
.L0805157C: .4byte gUnk_085D21A8
.L08051580: .4byte gUnk_085D21DC
.L08051584: .4byte gUnk_081408CC
.L08051588: .4byte gEkrDistanceType
.L0805158C:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L08051596:
	bl SpellFx_SetSomeColorEffect
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080515A0
func_fe6_080515A0: @ 0x080515A0
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	adds r0, #0x2c
	adds r1, r7, #0
	adds r1, #0x44
	ldr r2, [r7, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	blt .L080515F8
	ldr r5, [r7, #0x4c]
	ldr r6, [r7, #0x50]
	ldr r0, [r7, #0x54]
	lsls r4, r4, #2
	adds r0, r4, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	ldr r0, [r7, #0x5c]
	adds r5, r4, r5
	ldr r1, [r5]
	adds r4, r4, r6
	ldr r2, [r4]
	bl SpellFx_WriteBgMap
	ldr r0, .L080515F0 @ =gBg1Tm+0x3C
	ldr r1, .L080515F4 @ =0x0000011F
	str r1, [sp]
	movs r1, #2
	movs r2, #0x14
	movs r3, #1
	bl FillBGRect
	b .L08051616
	.align 2, 0
.L080515F0: .4byte gBg1Tm+0x3C
.L080515F4: .4byte 0x0000011F
.L080515F8:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	bne .L08051616
	bl SpellFx_ClearBG1
	ldr r1, .L08051620 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	adds r0, r7, #0
	bl Proc_Break
.L08051616:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08051620: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08051624
func_fe6_08051624: @ 0x08051624
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L0805165C @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08051660 @ =gUnk_085D2210
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	strh r5, [r0, #0x30]
	str r1, [r0, #0x44]
	ldr r1, .L08051664 @ =gUnk_0811A50E
	str r1, [r0, #0x48]
	ldr r1, .L08051668 @ =gUnk_081408CC
	str r1, [r0, #0x4c]
	adds r0, r1, #0
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805165C: .4byte gEfxBgSemaphore
.L08051660: .4byte gUnk_085D2210
.L08051664: .4byte gUnk_0811A50E
.L08051668: .4byte gUnk_081408CC

	thumb_func_start func_fe6_0805166C
func_fe6_0805166C: @ 0x0805166C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L08051690
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
.L08051690:
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x30]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L080516AE
	ldr r1, .L080516B4 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L080516AE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080516B4: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_080516B8
func_fe6_080516B8: @ 0x080516B8
	push {lr}
	ldr r0, .L080516D0 @ =gEfxBgSemaphore
	ldr r1, [r0]
	adds r1, #1
	str r1, [r0]
	ldr r0, .L080516D4 @ =gUnk_085D2230
	movs r1, #3
	bl SpawnProc
	pop {r0}
	bx r0
	.align 2, 0
.L080516D0: .4byte gEfxBgSemaphore
.L080516D4: .4byte gUnk_085D2230

	thumb_func_start func_fe6_080516D8
func_fe6_080516D8: @ 0x080516D8
	push {lr}
	ldr r2, .L080516E8 @ =gDispIo
	movs r1, #8
	strh r1, [r2, #0x22]
	bl Proc_Break
	pop {r0}
	bx r0
	.align 2, 0
.L080516E8: .4byte gDispIo

	thumb_func_start func_fe6_080516EC
func_fe6_080516EC: @ 0x080516EC
	push {lr}
	ldr r2, .L080516FC @ =gDispIo
	movs r1, #0x10
	strh r1, [r2, #0x22]
	bl Proc_Break
	pop {r0}
	bx r0
	.align 2, 0
.L080516FC: .4byte gDispIo

	thumb_func_start func_fe6_08051700
func_fe6_08051700: @ 0x08051700
	push {lr}
	ldr r2, .L08051718 @ =gDispIo
	movs r1, #0x18
	strh r1, [r2, #0x22]
	ldr r2, .L0805171C @ =gEfxBgSemaphore
	ldr r1, [r2]
	subs r1, #1
	str r1, [r2]
	bl Proc_Break
	pop {r0}
	bx r0
	.align 2, 0
.L08051718: .4byte gDispIo
.L0805171C: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08051720
func_fe6_08051720: @ 0x08051720
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L08051760 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08051764 @ =gUnk_085D2270
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r2, #0
	strh r2, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	strh r2, [r0, #0x30]
	movs r1, #1
	str r1, [r0, #0x44]
	str r2, [r0, #0x48]
	ldr r0, .L08051768 @ =gUnk_08143EE4
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	ldr r0, .L0805176C @ =gUnk_08144A00
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08051760: .4byte gEfxBgSemaphore
.L08051764: .4byte gUnk_085D2270
.L08051768: .4byte gUnk_08143EE4
.L0805176C: .4byte gUnk_08144A00

	thumb_func_start func_fe6_08051770
func_fe6_08051770: @ 0x08051770
	push {r4, lr}
	adds r3, r0, #0
	ldrh r0, [r3, #0x2c]
	adds r0, #1
	movs r2, #0
	strh r0, [r3, #0x2c]
	lsls r0, r0, #0x10
	ldrh r4, [r3, #0x2e]
	lsls r1, r4, #0x10
	cmp r0, r1
	bne .L0805179C
	ldr r1, .L08051798 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r3, #0
	bl Proc_Break
	b .L080517DA
	.align 2, 0
.L08051798: .4byte gEfxBgSemaphore
.L0805179C:
	ldrh r0, [r3, #0x30]
	adds r0, #1
	strh r0, [r3, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r3, #0x44]
	cmp r0, r1
	bne .L080517DA
	strh r2, [r3, #0x30]
	movs r0, #2
	str r0, [r3, #0x44]
	ldr r4, .L080517E0 @ =gUnk_085D2288
	ldr r0, [r3, #0x48]
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r1, [r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080517C6
	str r2, [r3, #0x48]
.L080517C6:
	ldr r2, [r3, #0x48]
	lsls r0, r2, #2
	adds r0, r0, r4
	ldr r1, [r0]
	adds r2, #1
	str r2, [r3, #0x48]
	ldr r0, [r3, #0x5c]
	movs r2, #0x50
	bl func_fe6_080517E4
.L080517DA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080517E0: .4byte gUnk_085D2288

	thumb_func_start func_fe6_080517E4
func_fe6_080517E4: @ 0x080517E4
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r2
	ldr r1, .L08051830 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08051834 @ =gUnk_085D22E0
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0xc
	strh r0, [r4, #0x2e]
	ldr r3, .L08051838 @ =gUnk_085E5C10
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	str r0, [r4, #0x60]
	strh r6, [r0, #2]
	mov r1, r8
	strh r1, [r0, #4]
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08051830: .4byte gEfxBgSemaphore
.L08051834: .4byte gUnk_085D22E0
.L08051838: .4byte gUnk_085E5C10

	thumb_func_start func_fe6_0805183C
func_fe6_0805183C: @ 0x0805183C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08051864
	ldr r0, .L0805186C @ =gEfxBgSemaphore
	ldr r1, [r0]
	subs r1, #1
	str r1, [r0]
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L08051864:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805186C: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08051870
func_fe6_08051870: @ 0x08051870
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L080518E0 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080518E4 @ =gUnk_085D22F8
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	strh r1, [r0, #0x30]
	ldr r0, .L080518E8 @ =gUnk_08141320
	ldr r1, .L080518EC @ =gSpellAnimBgfx
	bl LZ77UnCompWram
	ldr r0, .L080518F0 @ =gUnk_08142EAC
	ldr r1, .L080518F4 @ =gBuf_Banim + 0x1000
	bl LZ77UnCompWram
	ldr r0, .L080518F8 @ =gUnk_08143AB8
	ldr r4, .L080518FC @ =gEkrTsaBuffer
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L08051900 @ =gUnk_08143DA8
	movs r1, #0x80
	lsls r1, r1, #4
	adds r4, r4, r1
	adds r1, r4, #0
	bl LZ77UnCompWram
	movs r0, #2
	bl EnableBgSync
	bl SpellFx_SetSomeColorEffect
	ldr r2, .L08051904 @ =gDispIo
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrb r1, [r2, #1]
	ands r0, r1
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r2, #1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080518E0: .4byte gEfxBgSemaphore
.L080518E4: .4byte gUnk_085D22F8
.L080518E8: .4byte gUnk_08141320
.L080518EC: .4byte gSpellAnimBgfx
.L080518F0: .4byte gUnk_08142EAC
.L080518F4: .4byte gBuf_Banim + 0x1000
.L080518F8: .4byte gUnk_08143AB8
.L080518FC: .4byte gEkrTsaBuffer
.L08051900: .4byte gUnk_08143DA8
.L08051904: .4byte gDispIo

	thumb_func_start func_fe6_08051908
func_fe6_08051908: @ 0x08051908
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r5, #1
	adds r0, r5, #0
	ldrh r1, [r4, #0x2c]
	ands r0, r1
	cmp r0, #0
	bne .L080519A0
	movs r2, #0x30
	ldrsh r0, [r4, r2]
	cmp r0, #1
	beq .L0805193C
	cmp r0, #1
	bgt .L0805192C
	cmp r0, #0
	beq .L08051932
	b .L0805194C
.L0805192C:
	cmp r0, #2
	beq .L08051944
	b .L0805194C
.L08051932:
	ldr r0, .L08051938 @ =gUnk_08143A38
	b .L0805194E
	.align 2, 0
.L08051938: .4byte gUnk_08143A38
.L0805193C:
	ldr r0, .L08051940 @ =gUnk_08143A58
	b .L0805194E
	.align 2, 0
.L08051940: .4byte gUnk_08143A58
.L08051944:
	ldr r0, .L08051948 @ =gUnk_08143A78
	b .L0805194E
	.align 2, 0
.L08051948: .4byte gUnk_08143A78
.L0805194C:
	movs r0, #0
.L0805194E:
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	ldrh r0, [r4, #0x30]
	adds r0, #1
	strh r0, [r4, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	bne .L08051966
	movs r0, #0
	strh r0, [r4, #0x30]
.L08051966:
	ldr r0, .L08051990 @ =gSpellAnimBgfx
	ldr r1, .L08051994 @ =0x06002000
	movs r2, #0x80
	lsls r2, r2, #6
	bl RegisterDataMove
	ldr r0, .L08051998 @ =gEkrTsaBuffer
	ldr r1, .L0805199C @ =gBg1Tm
	movs r2, #1
	str r2, [sp]
	adds r2, #0xff
	str r2, [sp, #4]
	movs r2, #0x20
	movs r3, #0x10
	bl EfxTmCpyBG
	movs r0, #2
	bl EnableBgSync
	b .L080519CE
	.align 2, 0
.L08051990: .4byte gSpellAnimBgfx
.L08051994: .4byte 0x06002000
.L08051998: .4byte gEkrTsaBuffer
.L0805199C: .4byte gBg1Tm
.L080519A0:
	ldr r0, .L080519FC @ =gUnk_08143A98
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	ldr r0, .L08051A00 @ =gBuf_Banim + 0x1000
	ldr r1, .L08051A04 @ =0x06002000
	movs r2, #0x80
	lsls r2, r2, #5
	bl RegisterDataMove
	ldr r0, .L08051A08 @ =gEkrTsaBuffer + 0x800
	ldr r1, .L08051A0C @ =gBg1Tm
	str r5, [sp]
	movs r2, #0x80
	lsls r2, r2, #1
	str r2, [sp, #4]
	movs r2, #0x20
	movs r3, #0x10
	bl EfxTmCpyBG
	movs r0, #2
	bl EnableBgSync
.L080519CE:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L080519F4
	bl SpellFx_ClearBG1
	ldr r1, .L08051A10 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	adds r0, r4, #0
	bl Proc_End
.L080519F4:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080519FC: .4byte gUnk_08143A98
.L08051A00: .4byte gBuf_Banim + 0x1000
.L08051A04: .4byte 0x06002000
.L08051A08: .4byte gEkrTsaBuffer + 0x800
.L08051A0C: .4byte gBg1Tm
.L08051A10: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08051A14
func_fe6_08051A14: @ 0x08051A14
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L08051A50 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08051A54 @ =gUnk_085D2310
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r2, #0
	strh r2, [r0, #0x2c]
	strh r2, [r0, #0x2e]
	movs r1, #2
	str r1, [r0, #0x44]
	str r2, [r0, #0x48]
	ldr r0, .L08051A58 @ =gUnk_08143EE4
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	ldr r0, .L08051A5C @ =gUnk_08144A00
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08051A50: .4byte gEfxBgSemaphore
.L08051A54: .4byte gUnk_085D2310
.L08051A58: .4byte gUnk_08143EE4
.L08051A5C: .4byte gUnk_08144A00

	thumb_func_start func_fe6_08051A60
func_fe6_08051A60: @ 0x08051A60
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x41
	bne .L08051A88
	ldr r1, .L08051A84 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
	b .L08051ABC
	.align 2, 0
.L08051A84: .4byte gEfxBgSemaphore
.L08051A88:
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r4, #0x44]
	cmp r0, r1
	bne .L08051ABC
	movs r0, #0
	strh r0, [r4, #0x2e]
	movs r0, #2
	str r0, [r4, #0x44]
	ldr r0, [r4, #0x5c]
	ldr r2, [r4, #0x48]
	adds r1, r2, #0
	adds r2, #1
	str r2, [r4, #0x48]
	bl func_fe6_08051AC4
	ldr r0, [r4, #0x5c]
	ldr r2, [r4, #0x48]
	adds r1, r2, #0
	adds r2, #1
	str r2, [r4, #0x48]
	bl func_fe6_08051AC4
.L08051ABC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08051AC4
func_fe6_08051AC4: @ 0x08051AC4
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L08051B1C @ =gUnk_0811A520
	mov r0, sp
	movs r2, #0x10
	bl memcpy
	ldr r1, .L08051B20 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08051B24 @ =gUnk_085D2328
	movs r1, #3
	bl SpawnProc
	adds r6, r0, #0
	str r4, [r6, #0x5c]
	movs r4, #0
	strh r4, [r6, #0x2c]
	movs r0, #7
	ands r0, r5
	lsls r0, r0, #1
	add r0, sp
	ldrh r0, [r0]
	strh r0, [r6, #0x2e]
	movs r0, #0xe0
	bl func_fe6_0805B9C8
	adds r0, #8
	strh r0, [r6, #0x32]
	strh r4, [r6, #0x3a]
	movs r0, #9
	bl func_fe6_0805B9C8
	cmp r0, #9
	bhi .L08051B78
	lsls r0, r0, #2
	ldr r1, .L08051B28 @ =.L08051B2C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08051B1C: .4byte gUnk_0811A520
.L08051B20: .4byte gEfxBgSemaphore
.L08051B24: .4byte gUnk_085D2328
.L08051B28: .4byte .L08051B2C
.L08051B2C: @ jump table
	.4byte .L08051B54 @ case 0
	.4byte .L08051B54 @ case 1
	.4byte .L08051B54 @ case 2
	.4byte .L08051B54 @ case 3
	.4byte .L08051B54 @ case 4
	.4byte .L08051B54 @ case 5
	.4byte .L08051B54 @ case 6
	.4byte .L08051B5C @ case 7
	.4byte .L08051B64 @ case 8
	.4byte .L08051B6C @ case 9
.L08051B54:
	ldr r0, .L08051B58 @ =gUnk_085E5C44
	b .L08051B6E
	.align 2, 0
.L08051B58: .4byte gUnk_085E5C44
.L08051B5C:
	ldr r0, .L08051B60 @ =gUnk_085E5C3C
	b .L08051B6E
	.align 2, 0
.L08051B60: .4byte gUnk_085E5C3C
.L08051B64:
	ldr r0, .L08051B68 @ =gUnk_085E5C34
	b .L08051B6E
	.align 2, 0
.L08051B68: .4byte gUnk_085E5C34
.L08051B6C:
	ldr r0, .L08051B8C @ =gUnk_085E5C2C
.L08051B6E:
	movs r1, #0x78
	bl BasCreate
	adds r4, r0, #0
	str r4, [r6, #0x60]
.L08051B78:
	cmp r4, #0
	bne .L08051B94
	ldr r1, .L08051B90 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r6, #0
	bl Proc_End
	b .L08051BA2
	.align 2, 0
.L08051B8C: .4byte gUnk_085E5C2C
.L08051B90: .4byte gEfxBgSemaphore
.L08051B94:
	movs r0, #0x91
	lsls r0, r0, #6
	strh r0, [r4, #8]
	ldrh r0, [r6, #0x32]
	strh r0, [r4, #2]
	ldrh r0, [r6, #0x3a]
	strh r0, [r4, #4]
.L08051BA2:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08051BAC
func_fe6_08051BAC: @ 0x08051BAC
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r5, [r4, #0x60]
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	cmp r1, r0
	ble .L08051BDC
	ldr r1, .L08051BD8 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r5, #0
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
	b .L08051BF8
	.align 2, 0
.L08051BD8: .4byte gEfxBgSemaphore
.L08051BDC:
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r0, #1
	movs r1, #0x78
	movs r2, #8
	bl Interpolate
	strh r0, [r5, #4]
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L08051BF8:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08051C00
func_fe6_08051C00: @ 0x08051C00
	ldr r0, .L08051C24 @ =0x04000004
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L08051C20
	ldr r2, .L08051C28 @ =0x04000014
	ldr r3, .L08051C2C @ =gUnk_Banim_0201E154
	ldr r1, [r3]
	ldrh r0, [r1]
	strh r0, [r2]
	adds r2, #2
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	str r1, [r3]
.L08051C20:
	bx lr
	.align 2, 0
.L08051C24: .4byte 0x04000004
.L08051C28: .4byte 0x04000014
.L08051C2C: .4byte gUnk_Banim_0201E154

	thumb_func_start func_fe6_08051C30
func_fe6_08051C30: @ 0x08051C30
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L08051C54 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08051C58 @ =gUnk_085D2340
	movs r1, #3
	bl SpawnProc
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r4, [r0, #0x2e]
	strh r1, [r0, #0x30]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08051C54: .4byte gEfxBgSemaphore
.L08051C58: .4byte gUnk_085D2340

	thumb_func_start func_fe6_08051C5C
func_fe6_08051C5C: @ 0x08051C5C
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	ldr r0, .L08051CBC @ =gUnk_Banim_0201E3D8
	ldr r0, [r0]
	ldr r4, .L08051CC0 @ =gUnk_Banim_0201E158
	cmp r0, #0
	bne .L08051C6C
	ldr r4, .L08051CC4 @ =gUnk_Banim_0201E298
.L08051C6C:
	movs r2, #0
	ldr r6, .L08051CC8 @ =gSinLut
	movs r5, #0xff
.L08051C72:
	lsls r0, r2, #1
	movs r7, #0x30
	ldrsh r1, [r3, r7]
	adds r0, r0, r1
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	asrs r0, r0, #0xa
	adds r0, #4
	strh r0, [r4]
	adds r4, #2
	adds r2, #1
	cmp r2, #0x9f
	bls .L08051C72
	ldrh r0, [r3, #0x30]
	adds r0, #2
	strh r0, [r3, #0x30]
	ldrh r0, [r3, #0x2c]
	adds r0, #1
	strh r0, [r3, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r3, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08051CB6
	ldr r1, .L08051CCC @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r3, #0
	bl Proc_Break
.L08051CB6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08051CBC: .4byte gUnk_Banim_0201E3D8
.L08051CC0: .4byte gUnk_Banim_0201E158
.L08051CC4: .4byte gUnk_Banim_0201E298
.L08051CC8: .4byte gSinLut
.L08051CCC: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08051CD0
func_fe6_08051CD0: @ 0x08051CD0
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl func_fe6_08047300
	bl SpellFx_SetBG1Position
	ldr r0, .L08051D08 @ =gUnk_085D2358
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08051D08: .4byte gUnk_085D2358

	thumb_func_start func_fe6_08051D0C
func_fe6_08051D0C: @ 0x08051D0C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	adds r5, r0, #0
	bl EfxGetCamMovDuration
	adds r3, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #1
	bne .L08051D50
	ldr r0, .L08051D4C @ =0x00000127
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	movs r3, #1
	bl func_fe6_0805C804
	adds r0, r5, #0
	bl func_fe6_08051DFC
	ldr r0, [r4, #0x5c]
	bl func_fe6_08051FEC
	b .L08051DF6
	.align 2, 0
.L08051D4C: .4byte 0x00000127
.L08051D50:
	cmp r2, #0x14
	bne .L08051D64
	movs r0, #0x94
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	b .L08051D90
.L08051D64:
	cmp r2, #0x32
	bne .L08051D74
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl NewEfxFarAttackWithDistance
	b .L08051DF6
.L08051D74:
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	adds r0, r3, #0
	adds r0, #0x46
	cmp r1, r0
	bne .L08051D9C
	adds r0, r5, #0
	bl func_fe6_08051E80
	ldr r0, .L08051D98 @ =0x00000129
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
.L08051D90:
	movs r3, #1
	bl func_fe6_0805C804
	b .L08051DF6
	.align 2, 0
.L08051D98: .4byte 0x00000129
.L08051D9C:
	adds r0, r3, #0
	adds r0, #0x49
	cmp r1, r0
	bne .L08051DAE
	ldr r0, [r4, #0x5c]
	movs r1, #0xa
	bl NewEfxFlashBgWhite
	b .L08051DF6
.L08051DAE:
	adds r0, r3, #0
	adds r0, #0x4b
	cmp r1, r0
	bne .L08051DDC
	adds r0, r5, #0
	bl func_fe6_08051F04
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl StartBattleAnimHitEffectsDefault
	ldrb r0, [r4]
	cmp r0, #0
	bne .L08051DF6
	adds r0, r5, #0
	bl func_fe6_0805C358
	b .L08051DF6
.L08051DDC:
	adds r0, r3, #0
	adds r0, #0x5a
	cmp r1, r0
	beq .L08051DF6
	cmp r2, #0x64
	bne .L08051DF6
	bl SpellFx_Finish
	bl func_fe6_08047358
	adds r0, r4, #0
	bl Proc_Break
.L08051DF6:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08051DFC
func_fe6_08051DFC: @ 0x08051DFC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L08051E50 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08051E54 @ =gUnk_085D2370
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L08051E58 @ =gUnk_0811A530
	str r0, [r5, #0x48]
	ldr r0, .L08051E5C @ =gUnk_085D23D8
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L08051E60 @ =gUnk_085D2388
	str r0, [r5, #0x54]
	ldr r0, .L08051E64 @ =gUnk_08176A6C
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	ldr r0, .L08051E68 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08051E76
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L08051E6C
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
	b .L08051E76
	.align 2, 0
.L08051E50: .4byte gEfxBgSemaphore
.L08051E54: .4byte gUnk_085D2370
.L08051E58: .4byte gUnk_0811A530
.L08051E5C: .4byte gUnk_085D23D8
.L08051E60: .4byte gUnk_085D2388
.L08051E64: .4byte gUnk_08176A6C
.L08051E68: .4byte gEkrDistanceType
.L08051E6C:
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
.L08051E76:
	bl SpellFx_SetSomeColorEffect
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08051E80
func_fe6_08051E80: @ 0x08051E80
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L08051ED4 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08051ED8 @ =gUnk_085D2370
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L08051EDC @ =gUnk_0811A59E
	str r0, [r5, #0x48]
	ldr r0, .L08051EE0 @ =gUnk_085D2434
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L08051EE4 @ =gUnk_085D2428
	str r0, [r5, #0x54]
	ldr r0, .L08051EE8 @ =gUnk_08176A6C
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	ldr r0, .L08051EEC @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08051EFA
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L08051EF0
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L08051EFA
	.align 2, 0
.L08051ED4: .4byte gEfxBgSemaphore
.L08051ED8: .4byte gUnk_085D2370
.L08051EDC: .4byte gUnk_0811A59E
.L08051EE0: .4byte gUnk_085D2434
.L08051EE4: .4byte gUnk_085D2428
.L08051EE8: .4byte gUnk_08176A6C
.L08051EEC: .4byte gEkrDistanceType
.L08051EF0:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L08051EFA:
	bl SpellFx_SetSomeColorEffect
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08051F04
func_fe6_08051F04: @ 0x08051F04
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L08051F58 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08051F5C @ =gUnk_085D2370
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L08051F60 @ =gUnk_0811A5AC
	str r0, [r5, #0x48]
	ldr r0, .L08051F64 @ =gUnk_085D2494
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L08051F68 @ =gUnk_085D2440
	str r0, [r5, #0x54]
	ldr r0, .L08051F6C @ =gUnk_08176A4C
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	ldr r0, .L08051F70 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08051F7E
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L08051F74
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L08051F7E
	.align 2, 0
.L08051F58: .4byte gEfxBgSemaphore
.L08051F5C: .4byte gUnk_085D2370
.L08051F60: .4byte gUnk_0811A5AC
.L08051F64: .4byte gUnk_085D2494
.L08051F68: .4byte gUnk_085D2440
.L08051F6C: .4byte gUnk_08176A4C
.L08051F70: .4byte gEkrDistanceType
.L08051F74:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L08051F7E:
	bl SpellFx_SetSomeColorEffect
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08051F88
func_fe6_08051F88: @ 0x08051F88
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r0, #0x2c
	adds r1, r7, #0
	adds r1, #0x44
	ldr r2, [r7, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	blt .L08051FC4
	ldr r5, [r7, #0x4c]
	ldr r6, [r7, #0x50]
	ldr r0, [r7, #0x54]
	lsls r4, r4, #2
	adds r0, r4, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	ldr r0, [r7, #0x5c]
	adds r5, r4, r5
	ldr r1, [r5]
	adds r4, r4, r6
	ldr r2, [r4]
	bl SpellFx_WriteBgMap
	b .L08051FE2
.L08051FC4:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	bne .L08051FE2
	bl SpellFx_ClearBG1
	ldr r1, .L08051FE8 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	adds r0, r7, #0
	bl Proc_Break
.L08051FE2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08051FE8: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08051FEC
func_fe6_08051FEC: @ 0x08051FEC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L0805202C @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08052030 @ =gUnk_085D24E8
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r3, .L08052034 @ =gUnk_085EB83C
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	adds r6, r0, #0
	str r6, [r4, #0x60]
	adds r0, r5, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L08052038
	ldrh r0, [r6, #2]
	subs r0, #6
	b .L0805203C
	.align 2, 0
.L0805202C: .4byte gEfxBgSemaphore
.L08052030: .4byte gUnk_085D24E8
.L08052034: .4byte gUnk_085EB83C
.L08052038:
	ldrh r0, [r6, #2]
	adds r0, #6
.L0805203C:
	strh r0, [r6, #2]
	ldr r0, .L08052058 @ =gUnk_0817AC2C
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0805205C @ =gUnk_0817AAC0
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08052058: .4byte gUnk_0817AC2C
.L0805205C: .4byte gUnk_0817AAC0

	thumb_func_start func_fe6_08052060
func_fe6_08052060: @ 0x08052060
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x2c
	bne .L08052086
	ldr r0, [r4, #0x60]
	bl BasRemove
	ldr r1, .L0805208C @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L08052086:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805208C: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08052090
func_fe6_08052090: @ 0x08052090
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl func_fe6_08047300
	bl SpellFx_SetBG1Position
	ldr r0, .L080520C8 @ =gUnk_085D2500
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080520C8: .4byte gUnk_085D2500

	thumb_func_start func_fe6_080520CC
func_fe6_080520CC: @ 0x080520CC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	adds r5, r0, #0
	bl EfxGetCamMovDuration
	adds r6, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r7, #0
	movs r1, #0
	mov r8, r1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08052100
	ldr r0, [r4, #0x5c]
	subs r1, #1
	bl NewEfxFarAttackWithDistance
.L08052100:
	movs r2, #0x2c
	ldrsh r1, [r4, r2]
	adds r0, r6, #1
	cmp r1, r0
	bne .L08052158
	adds r0, r5, #0
	bl func_fe6_08052238
	ldr r3, .L08052154 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	strb r7, [r0]
	adds r0, #1
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r7, [r0]
	str r1, [sp]
	mov r2, r8
	str r2, [sp, #4]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0x20
	movs r3, #0
	bl func_fe6_0804CD88
	adds r0, r5, #0
	movs r1, #0xaa
	bl func_fe6_080524F4
	movs r0, #0x95
	lsls r0, r0, #1
	b .L08052162
	.align 2, 0
.L08052154: .4byte gDispIo
.L08052158:
	ldr r2, .L08052174 @ =0x0000011B
	adds r0, r6, r2
	cmp r1, r0
	bne .L0805217C
	ldr r0, .L08052178 @ =0x0000012B
.L08052162:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl func_fe6_0805C804
	b .L0805222A
	.align 2, 0
.L08052174: .4byte 0x0000011B
.L08052178: .4byte 0x0000012B
.L0805217C:
	ldr r2, .L08052190 @ =0x0000013B
	adds r0, r6, r2
	cmp r1, r0
	bne .L08052194
	adds r0, r5, #0
	movs r1, #0x19
	bl func_fe6_080526F4
	b .L0805222A
	.align 2, 0
.L08052190: .4byte 0x0000013B
.L08052194:
	movs r3, #0xaa
	lsls r3, r3, #1
	adds r0, r6, r3
	cmp r1, r0
	bne .L080521C6
	adds r0, r5, #0
	movs r1, #0xc
	bl NewEfxFlashBgWhite
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl func_fe6_08047610
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0805222A
	adds r0, r5, #0
	bl func_fe6_0805C358
	b .L0805222A
.L080521C6:
	movs r2, #0xad
	lsls r2, r2, #1
	adds r0, r6, r2
	cmp r1, r0
	bne .L08052212
	movs r0, #0x96
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0x78
	movs r3, #0
	bl func_fe6_0805C804
	adds r0, r5, #0
	movs r1, #0x64
	bl func_fe6_0804D050
	adds r0, r5, #0
	movs r1, #0x64
	bl func_fe6_08052334
	adds r0, r5, #0
	movs r1, #0x64
	bl func_fe6_08052460
	mov r3, r8
	str r3, [sp]
	str r3, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x46
	movs r2, #0x1e
	movs r3, #0x10
	bl func_fe6_0804CD88
	adds r0, r5, #0
	bl func_fe6_08052848
	b .L0805222A
.L08052212:
	movs r2, #0xf5
	lsls r2, r2, #1
	adds r0, r6, r2
	cmp r1, r0
	bne .L0805222A
	bl SpellFx_Finish
	bl func_fe6_08047358
	adds r0, r4, #0
	bl Proc_Break
.L0805222A:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08052238
func_fe6_08052238: @ 0x08052238
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L0805228C @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08052290 @ =gUnk_085D2518
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L08052294 @ =gUnk_0811A602
	str r0, [r5, #0x48]
	ldr r0, .L08052298 @ =gUnk_085D2544
	str r0, [r5, #0x4c]
	ldr r0, .L0805229C @ =gUnk_085D2530
	str r0, [r5, #0x54]
	ldr r0, .L080522A0 @ =gUnk_081BB35C
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	bl SpellFx_SetBG1Position
	bl SpellFx_SetSomeColorEffect
	ldr r0, .L080522A4 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L080522B4
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L080522A8
	movs r0, #1
	movs r1, #0xf8
	b .L080522AC
	.align 2, 0
.L0805228C: .4byte gEfxBgSemaphore
.L08052290: .4byte gUnk_085D2518
.L08052294: .4byte gUnk_0811A602
.L08052298: .4byte gUnk_085D2544
.L0805229C: .4byte gUnk_085D2530
.L080522A0: .4byte gUnk_081BB35C
.L080522A4: .4byte gEkrDistanceType
.L080522A8:
	movs r0, #1
	movs r1, #0x18
.L080522AC:
	movs r2, #0
	bl SetBgOffset
	b .L080522C8
.L080522B4:
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L080522C8
	movs r0, #1
	movs r1, #0x10
	movs r2, #0
	bl SetBgOffset
.L080522C8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080522D0
func_fe6_080522D0: @ 0x080522D0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r0, #0x2c
	adds r1, r6, #0
	adds r1, #0x44
	ldr r2, [r6, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	blt .L0805230A
	ldr r5, [r6, #0x4c]
	ldr r0, [r6, #0x54]
	lsls r4, r4, #2
	adds r0, r4, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	ldr r0, [r6, #0x5c]
	adds r4, r4, r5
	ldr r1, [r4]
	movs r2, #0x20
	movs r3, #0x14
	bl SpellFx_WriteBgMapExt
	b .L08052328
.L0805230A:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	bne .L08052328
	bl SpellFx_ClearBG1
	ldr r1, .L08052330 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	adds r0, r6, #0
	bl Proc_Break
.L08052328:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08052330: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08052334
func_fe6_08052334: @ 0x08052334
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L0805237C @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08052380 @ =gUnk_085D2558
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	strh r1, [r0, #0x32]
	strh r1, [r0, #0x3a]
	strh r1, [r0, #0x34]
	strh r1, [r0, #0x3c]
	ldr r0, .L08052384 @ =gUnk_081B8E64
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	ldr r0, .L08052388 @ =gUnk_081BB37C
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	bl SpellFx_SetBG1Position
	bl SpellFx_SetSomeColorEffect
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805237C: .4byte gEfxBgSemaphore
.L08052380: .4byte gUnk_085D2558
.L08052384: .4byte gUnk_081B8E64
.L08052388: .4byte gUnk_081BB37C

	thumb_func_start func_fe6_0805238C
func_fe6_0805238C: @ 0x0805238C
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r6, #1
	adds r0, r6, #0
	ldrh r1, [r5, #0x2c]
	ands r0, r1
	cmp r0, #0
	beq .L080523E8
	ldrh r2, [r5, #0x32]
	subs r2, #0xc
	strh r2, [r5, #0x32]
	ldrh r1, [r5, #0x3a]
	adds r1, #0xc
	strh r1, [r5, #0x3a]
	ldr r0, .L080523D8 @ =gDispIo
	strh r2, [r0, #0x20]
	strh r1, [r0, #0x22]
	ldr r0, .L080523DC @ =gUnk_081BB5E4
	ldr r4, .L080523E0 @ =gEkrTsaBuffer
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L080523E4 @ =gBg1Tm
	str r6, [sp]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r2, #0x20
	movs r3, #0x20
	bl EfxTmCpyBG
	movs r0, #2
	bl EnableBgSync
	b .L0805241E
	.align 2, 0
.L080523D8: .4byte gDispIo
.L080523DC: .4byte gUnk_081BB5E4
.L080523E0: .4byte gEkrTsaBuffer
.L080523E4: .4byte gBg1Tm
.L080523E8:
	ldrh r2, [r5, #0x34]
	adds r2, #8
	strh r2, [r5, #0x34]
	ldrh r1, [r5, #0x3c]
	adds r1, #8
	strh r1, [r5, #0x3c]
	ldr r0, .L0805244C @ =gDispIo
	strh r2, [r0, #0x20]
	strh r1, [r0, #0x22]
	ldr r0, .L08052450 @ =gUnk_081BB5E4
	ldr r4, .L08052454 @ =gEkrTsaBuffer
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L08052458 @ =gBg1Tm
	str r6, [sp]
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r2, #0x20
	movs r3, #0x20
	bl EfxTmCpyBgHFlip
	movs r0, #2
	bl EnableBgSync
.L0805241E:
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r5, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L08052444
	bl SpellFx_ClearBG1
	bl SpellFx_ClearColorEffects
	ldr r1, .L0805245C @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r5, #0
	bl Proc_Break
.L08052444:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805244C: .4byte gDispIo
.L08052450: .4byte gUnk_081BB5E4
.L08052454: .4byte gEkrTsaBuffer
.L08052458: .4byte gBg1Tm
.L0805245C: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08052460
func_fe6_08052460: @ 0x08052460
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L08052498 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0805249C @ =gUnk_085D2570
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	strh r5, [r0, #0x30]
	str r1, [r0, #0x44]
	ldr r1, .L080524A0 @ =gUnk_0811A618
	str r1, [r0, #0x48]
	ldr r1, .L080524A4 @ =gUnk_081BB37C
	str r1, [r0, #0x4c]
	adds r0, r1, #0
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08052498: .4byte gEfxBgSemaphore
.L0805249C: .4byte gUnk_085D2570
.L080524A0: .4byte gUnk_0811A618
.L080524A4: .4byte gUnk_081BB37C

	thumb_func_start func_fe6_080524A8
func_fe6_080524A8: @ 0x080524A8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L080524CC
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
.L080524CC:
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x30]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L080524EA
	ldr r1, .L080524F0 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L080524EA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080524F0: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_080524F4
func_fe6_080524F4: @ 0x080524F4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L08052534 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08052538 @ =gUnk_085D2590
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r2, #0
	strh r2, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	strh r2, [r0, #0x30]
	movs r1, #0xa
	str r1, [r0, #0x44]
	str r2, [r0, #0x48]
	ldr r0, .L0805253C @ =gUnk_081BC0A8
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L08052540 @ =gUnk_081BBBB4
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08052534: .4byte gEfxBgSemaphore
.L08052538: .4byte gUnk_085D2590
.L0805253C: .4byte gUnk_081BC0A8
.L08052540: .4byte gUnk_081BBBB4

	thumb_func_start func_fe6_08052544
func_fe6_08052544: @ 0x08052544
	push {lr}
	adds r3, r0, #0
	ldrh r0, [r3, #0x2c]
	adds r0, #1
	strh r0, [r3, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r3, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L0805256C
	ldr r1, .L08052568 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r3, #0
	bl Proc_Break
	b .L08052592
	.align 2, 0
.L08052568: .4byte gEfxBgSemaphore
.L0805256C:
	ldrh r0, [r3, #0x30]
	adds r0, #1
	strh r0, [r3, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r3, #0x44]
	cmp r0, r1
	bne .L08052592
	movs r0, #0
	strh r0, [r3, #0x30]
	movs r0, #0xa
	str r0, [r3, #0x44]
	ldr r0, [r3, #0x5c]
	ldr r2, [r3, #0x48]
	adds r1, r2, #0
	adds r2, #1
	str r2, [r3, #0x48]
	bl func_fe6_08052598
.L08052592:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08052598
func_fe6_08052598: @ 0x08052598
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, .L08052624 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08052628 @ =gUnk_085D25A8
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r6, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x1e
	bl func_fe6_0805B9C8
	adds r0, #0x8c
	strh r0, [r4, #0x2e]
	movs r0, #0x1e
	bl func_fe6_0805B9C8
	adds r5, r0, #0
	movs r0, #0x1e
	bl func_fe6_0805B9C8
	adds r1, r0, #0
	adds r0, r5, #0
	adds r0, #0x46
	strh r0, [r4, #0x32]
	adds r0, r1, #0
	adds r0, #0x28
	strh r0, [r4, #0x34]
	ldr r0, .L0805262C @ =0x0000FFEC
	strh r0, [r4, #0x3a]
	movs r0, #0xa0
	strh r0, [r4, #0x3c]
	ldr r0, .L08052630 @ =gEkrDistanceType
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne .L080525F8
	adds r0, r5, #0
	adds r0, #0x5e
	strh r0, [r4, #0x32]
	adds r0, r1, #0
	adds r0, #0x40
	strh r0, [r4, #0x34]
.L080525F8:
	adds r0, r6, #0
	bl GetAnimPosition
	cmp r0, #1
	bne .L08052610
	movs r0, #0xf0
	ldrh r2, [r4, #0x32]
	subs r1, r0, r2
	strh r1, [r4, #0x32]
	ldrh r1, [r4, #0x34]
	subs r0, r0, r1
	strh r0, [r4, #0x34]
.L08052610:
	movs r0, #2
	bl func_fe6_0805B9C8
	cmp r0, #0
	beq .L08052638
	cmp r0, #1
	beq .L08052640
	ldr r0, .L08052634 @ =gUnk_08603B2C
	b .L08052642
	.align 2, 0
.L08052624: .4byte gEfxBgSemaphore
.L08052628: .4byte gUnk_085D25A8
.L0805262C: .4byte 0x0000FFEC
.L08052630: .4byte gEkrDistanceType
.L08052634: .4byte gUnk_08603B2C
.L08052638:
	ldr r0, .L0805263C @ =gUnk_08603B1C
	b .L08052642
	.align 2, 0
.L0805263C: .4byte gUnk_08603B1C
.L08052640:
	ldr r0, .L08052660 @ =gUnk_08603B24
.L08052642:
	movs r1, #0x78
	bl BasCreate
	adds r1, r0, #0
	str r1, [r4, #0x60]
	cmp r1, #0
	bne .L08052668
	ldr r1, .L08052664 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_End
	b .L08052676
	.align 2, 0
.L08052660: .4byte gUnk_08603B24
.L08052664: .4byte gEfxBgSemaphore
.L08052668:
	movs r0, #0x91
	lsls r0, r0, #6
	strh r0, [r1, #8]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1, #2]
	strh r0, [r1, #4]
.L08052676:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805267C
func_fe6_0805267C: @ 0x0805267C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r6, [r5, #0x60]
	movs r0, #0x2c
	ldrsh r1, [r5, r0]
	movs r2, #0x2e
	ldrsh r0, [r5, r2]
	cmp r1, r0
	ble .L080526AC
	ldr r1, .L080526A8 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r6, #0
	bl BasRemove
	adds r0, r5, #0
	bl Proc_Break
	b .L080526EC
	.align 2, 0
.L080526A8: .4byte gEfxBgSemaphore
.L080526AC:
	movs r4, #0x32
	ldrsh r1, [r5, r4]
	movs r7, #0x34
	ldrsh r2, [r5, r7]
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r4, #0x2e
	ldrsh r0, [r5, r4]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r7, #0x3a
	ldrsh r1, [r5, r7]
	movs r0, #0x3c
	ldrsh r2, [r5, r0]
	movs r7, #0x2c
	ldrsh r3, [r5, r7]
	movs r7, #0x2e
	ldrsh r0, [r5, r7]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	strh r4, [r6, #2]
	strh r0, [r6, #4]
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
.L080526EC:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080526F4
func_fe6_080526F4: @ 0x080526F4
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r1, .L0805278C @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08052790 @ =gUnk_085D25C0
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r6, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	strh r0, [r5, #0x2e]
	strh r4, [r5, #0x30]
	movs r0, #0x5b
	strh r0, [r5, #0x32]
	movs r0, #0x3f
	strh r0, [r5, #0x34]
	ldr r0, .L08052794 @ =0x0000FFF6
	strh r0, [r5, #0x3a]
	movs r0, #0x64
	strh r0, [r5, #0x3c]
	ldr r0, .L08052798 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L0805273A
	movs r0, #0x73
	strh r0, [r5, #0x32]
	movs r0, #0x57
	strh r0, [r5, #0x34]
.L0805273A:
	adds r0, r6, #0
	bl GetAnimPosition
	cmp r0, #1
	bne .L08052752
	movs r0, #0xf0
	ldrh r2, [r5, #0x32]
	subs r1, r0, r2
	strh r1, [r5, #0x32]
	ldrh r1, [r5, #0x34]
	subs r0, r0, r1
	strh r0, [r5, #0x34]
.L08052752:
	ldr r3, .L0805279C @ =gUnk_08603B34
	str r3, [sp]
	adds r0, r6, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	str r0, [r5, #0x60]
	ldrh r1, [r5, #0x32]
	strh r1, [r0, #2]
	ldrh r1, [r5, #0x3a]
	strh r1, [r0, #4]
	ldr r3, .L080527A0 @ =gUnk_08603B58
	str r3, [sp]
	adds r0, r6, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	str r0, [r5, #0x64]
	ldrh r1, [r5, #0x32]
	strh r1, [r0, #2]
	ldrh r1, [r5, #0x3a]
	strh r1, [r0, #4]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805278C: .4byte gEfxBgSemaphore
.L08052790: .4byte gUnk_085D25C0
.L08052794: .4byte 0x0000FFF6
.L08052798: .4byte gEkrDistanceType
.L0805279C: .4byte gUnk_08603B34
.L080527A0: .4byte gUnk_08603B58

	thumb_func_start func_fe6_080527A4
func_fe6_080527A4: @ 0x080527A4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r4, r0, #0
	ldr r6, [r4, #0x60]
	ldr r5, [r4, #0x64]
	movs r0, #0x32
	ldrsh r1, [r4, r0]
	movs r7, #0x34
	ldrsh r2, [r4, r7]
	movs r0, #0x2e
	ldrsh r3, [r4, r0]
	movs r7, #0x30
	ldrsh r0, [r4, r7]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	movs r1, #0
	mov r8, r1
	strh r0, [r5, #2]
	strh r0, [r6, #2]
	movs r2, #0x3a
	ldrsh r1, [r4, r2]
	movs r7, #0x3c
	ldrsh r2, [r4, r7]
	movs r0, #0x2e
	ldrsh r3, [r4, r0]
	movs r7, #0x30
	ldrsh r0, [r4, r7]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	strh r0, [r5, #4]
	strh r0, [r6, #4]
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x11
	bne .L0805280A
	mov r0, r8
	strh r0, [r4, #0x2c]
	ldr r0, .L08052840 @ =gUnk_08603B58
	str r0, [r5, #0x24]
	str r0, [r5, #0x20]
	mov r1, r8
	strh r1, [r6, #6]
.L0805280A:
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x30]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08052834
	adds r0, r6, #0
	bl BasRemove
	adds r0, r5, #0
	bl BasRemove
	ldr r1, .L08052844 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L08052834:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08052840: .4byte gUnk_08603B58
.L08052844: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08052848
func_fe6_08052848: @ 0x08052848
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L08052870 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08052874 @ =gUnk_085D25D8
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r2, #0
	strh r2, [r0, #0x2c]
	strh r2, [r0, #0x2e]
	movs r1, #1
	str r1, [r0, #0x44]
	str r2, [r0, #0x48]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08052870: .4byte gEfxBgSemaphore
.L08052874: .4byte gUnk_085D25D8

	thumb_func_start func_fe6_08052878
func_fe6_08052878: @ 0x08052878
	push {lr}
	adds r3, r0, #0
	ldrh r0, [r3, #0x2c]
	adds r0, #1
	strh r0, [r3, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x2f
	bne .L080528A0
	ldr r1, .L0805289C @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r3, #0
	bl Proc_Break
	b .L080528C6
	.align 2, 0
.L0805289C: .4byte gEfxBgSemaphore
.L080528A0:
	ldrh r0, [r3, #0x2e]
	adds r0, #1
	strh r0, [r3, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r3, #0x44]
	cmp r0, r1
	bne .L080528C6
	movs r0, #0
	strh r0, [r3, #0x2e]
	movs r0, #1
	str r0, [r3, #0x44]
	ldr r0, [r3, #0x5c]
	ldr r2, [r3, #0x48]
	adds r1, r2, #0
	adds r2, #1
	str r2, [r3, #0x48]
	bl func_fe6_080528CC
.L080528C6:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080528CC
func_fe6_080528CC: @ 0x080528CC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L08052928 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0805292C @ =gUnk_085D25F0
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	movs r0, #0x14
	strh r0, [r5, #0x2e]
	movs r0, #0x78
	bl func_fe6_0805B9C8
	adds r1, r0, #0
	subs r1, #0x3c
	strh r1, [r5, #0x32]
	adds r0, #0xb4
	strh r0, [r5, #0x34]
	movs r1, #0x32
	ldrsh r0, [r5, r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	asrs r1, r1, #1
	movs r0, #0x34
	ldrsh r2, [r5, r0]
	lsls r0, r2, #1
	adds r0, r0, r2
	asrs r0, r0, #1
	adds r1, #0xc0
	strh r1, [r5, #0x3a]
	ldr r1, .L08052930 @ =0xFFFFFEB8
	adds r0, r0, r1
	strh r0, [r5, #0x3c]
	movs r0, #2
	bl func_fe6_0805B9C8
	cmp r0, #1
	bne .L08052938
	ldr r0, .L08052934 @ =gUnk_08603BA4
	b .L0805293A
	.align 2, 0
.L08052928: .4byte gEfxBgSemaphore
.L0805292C: .4byte gUnk_085D25F0
.L08052930: .4byte 0xFFFFFEB8
.L08052934: .4byte gUnk_08603BA4
.L08052938:
	ldr r0, .L08052958 @ =gUnk_08603BC0
.L0805293A:
	movs r1, #0x78
	bl BasCreate
	adds r1, r0, #0
	str r1, [r5, #0x60]
	cmp r1, #0
	bne .L08052960
	ldr r1, .L0805295C @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r5, #0
	bl Proc_End
	b .L0805296E
	.align 2, 0
.L08052958: .4byte gUnk_08603BC0
.L0805295C: .4byte gEfxBgSemaphore
.L08052960:
	movs r0, #0x91
	lsls r0, r0, #6
	strh r0, [r1, #8]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1, #2]
	strh r0, [r1, #4]
.L0805296E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08052974
func_fe6_08052974: @ 0x08052974
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r6, [r5, #0x60]
	movs r0, #0x2c
	ldrsh r1, [r5, r0]
	movs r2, #0x2e
	ldrsh r0, [r5, r2]
	cmp r1, r0
	ble .L080529A4
	ldr r1, .L080529A0 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r6, #0
	bl BasRemove
	adds r0, r5, #0
	bl Proc_Break
	b .L080529E4
	.align 2, 0
.L080529A0: .4byte gEfxBgSemaphore
.L080529A4:
	movs r4, #0x32
	ldrsh r1, [r5, r4]
	movs r7, #0x34
	ldrsh r2, [r5, r7]
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r4, #0x2e
	ldrsh r0, [r5, r4]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r7, #0x3a
	ldrsh r1, [r5, r7]
	movs r0, #0x3c
	ldrsh r2, [r5, r0]
	movs r7, #0x2c
	ldrsh r3, [r5, r7]
	movs r7, #0x2e
	ldrsh r0, [r5, r7]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	strh r4, [r6, #2]
	strh r0, [r6, #4]
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
.L080529E4:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080529EC
func_fe6_080529EC: @ 0x080529EC
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl func_fe6_08047300
	bl SpellFx_SetBG1Position
	ldr r0, .L08052A24 @ =gUnk_085D2608
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08052A24: .4byte gUnk_085D2608

	thumb_func_start func_fe6_08052A28
func_fe6_08052A28: @ 0x08052A28
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	ldr r0, [r6, #0x5c]
	bl GetAnimAnotherSide
	adds r5, r0, #0
	bl EfxGetCamMovDuration
	adds r4, r0, #0
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	movs r7, #0
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08052A56
	ldr r0, [r6, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl NewEfxFarAttackWithDistance
.L08052A56:
	movs r0, #0x2c
	ldrsh r1, [r6, r0]
	adds r0, r4, #1
	cmp r1, r0
	bne .L08052AD4
	ldr r4, .L08052AC4 @ =0x000001D1
	adds r0, r5, #0
	adds r1, r4, #0
	bl func_fe6_08052BA8
	adds r0, r5, #0
	bl func_fe6_08052D40
	adds r0, r5, #0
	bl func_fe6_08052C68
	ldr r1, .L08052AC8 @ =0x0000018B
	adds r0, r5, #0
	movs r2, #0xa
	bl func_fe6_0805315C
	ldr r1, .L08052ACC @ =0x0000019F
	adds r0, r5, #0
	movs r2, #0x14
	bl func_fe6_080531C4
	adds r0, r5, #0
	bl func_fe6_08052DF4
	adds r0, r5, #0
	adds r1, r4, #0
	bl func_fe6_0805304C
	movs r0, #3
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x14
	movs r3, #0x80
	bl func_fe6_0804C8D4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x8c
	bl func_fe6_080530E4
	ldr r2, .L08052AD0 @ =func_fe6_0804CD4C
	adds r0, r5, #0
	adds r1, r4, #0
	bl func_fe6_0804CC68
	movs r0, #0x82
	lsls r0, r0, #1
	b .L08052B38
	.align 2, 0
.L08052AC4: .4byte 0x000001D1
.L08052AC8: .4byte 0x0000018B
.L08052ACC: .4byte 0x0000019F
.L08052AD0: .4byte func_fe6_0804CD4C
.L08052AD4:
	adds r0, r4, #0
	adds r0, #0x92
	cmp r1, r0
	bne .L08052AE4
	ldr r0, .L08052AE0 @ =0x00000105
	b .L08052B38
	.align 2, 0
.L08052AE0: .4byte 0x00000105
.L08052AE4:
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r4, r2
	cmp r1, r0
	bne .L08052AFA
	adds r0, r5, #0
	movs r1, #0xa
	movs r2, #0x14
	bl NewEfxWhiteOUT
	b .L08052B9A
.L08052AFA:
	ldr r2, .L08052B48 @ =0x000001D5
	adds r0, r4, r2
	cmp r1, r0
	bne .L08052B4C
	adds r0, r5, #0
	movs r1, #0xa0
	bl func_fe6_0805327C
	str r7, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x6e
	movs r2, #0x28
	movs r3, #0x10
	bl func_fe6_0804CD88
	adds r0, r5, #0
	movs r1, #0x8c
	movs r2, #0x18
	bl func_fe6_08053420
	adds r0, r5, #0
	movs r1, #0x3c
	bl func_fe6_08053530
	adds r0, r5, #0
	movs r1, #0x5a
	bl func_fe6_0804D050
	movs r0, #0x83
	lsls r0, r0, #1
.L08052B38:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0x78
	movs r3, #0
	bl func_fe6_0805C804
	b .L08052B9A
	.align 2, 0
.L08052B48: .4byte 0x000001D5
.L08052B4C:
	ldr r2, .L08052B78 @ =0x0000020D
	adds r0, r4, r2
	cmp r1, r0
	bne .L08052B7C
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, r6, #0
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl StartBattleAnimHitEffectsDefault
	ldrb r0, [r4]
	cmp r0, #0
	bne .L08052B9A
	adds r0, r5, #0
	bl func_fe6_0805C358
	b .L08052B9A
	.align 2, 0
.L08052B78: .4byte 0x0000020D
.L08052B7C:
	ldr r2, .L08052BA4 @ =0x00000271
	adds r0, r4, r2
	cmp r1, r0
	beq .L08052B9A
	adds r2, #0xa
	adds r0, r4, r2
	cmp r1, r0
	bne .L08052B9A
	bl SpellFx_Finish
	bl func_fe6_08047358
	adds r0, r6, #0
	bl Proc_Break
.L08052B9A:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08052BA4: .4byte 0x00000271

	thumb_func_start func_fe6_08052BA8
func_fe6_08052BA8: @ 0x08052BA8
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L08052C18 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08052C1C @ =gUnk_085D2620
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	ldr r0, .L08052C20 @ =gUnk_0817AC4C
	movs r1, #0x84
	lsls r1, r1, #5
	bl SpellFx_RegisterBgGfx
	bl SpellFx_ClearBG1
	ldr r0, .L08052C24 @ =gUnk_0817B438
	ldr r4, .L08052C28 @ =gEkrTsaBuffer
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L08052C2C @ =gBg1Tm
	movs r0, #1
	str r0, [sp]
	adds r0, #0xff
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r2, #0x20
	movs r3, #0x14
	bl EfxTmCpyBG
	bl SpellFx_SetSomeColorEffect
	ldr r2, .L08052C30 @ =gDispIo
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrb r1, [r2, #1]
	ands r0, r1
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r2, #1]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08052C18: .4byte gEfxBgSemaphore
.L08052C1C: .4byte gUnk_085D2620
.L08052C20: .4byte gUnk_0817AC4C
.L08052C24: .4byte gUnk_0817B438
.L08052C28: .4byte gEkrTsaBuffer
.L08052C2C: .4byte gBg1Tm
.L08052C30: .4byte gDispIo

	thumb_func_start func_fe6_08052C34
func_fe6_08052C34: @ 0x08052C34
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L08052C5E
	bl SpellFx_ClearBG1
	ldr r1, .L08052C64 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	adds r0, r4, #0
	bl Proc_End
.L08052C5E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08052C64: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08052C68
func_fe6_08052C68: @ 0x08052C68
	push {r4, lr}
	ldr r1, .L08052C94 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08052C98 @ =gUnk_085D2638
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	movs r0, #1
	movs r1, #0
	movs r2, #0x10
	bl SetBgOffset
	movs r0, #0
	strh r0, [r4, #0x2c]
	strh r0, [r4, #0x2e]
	strh r0, [r4, #0x30]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08052C94: .4byte gEfxBgSemaphore
.L08052C98: .4byte gUnk_085D2638

	thumb_func_start func_fe6_08052C9C
func_fe6_08052C9C: @ 0x08052C9C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0x30
	ldrsh r3, [r6, r0]
	movs r0, #0x96
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0xff
	bl Interpolate
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldrh r1, [r6, #0x30]
	movs r3, #0x30
	ldrsh r0, [r6, r3]
	cmp r0, #0x96
	bgt .L08052CC6
	adds r0, r1, #1
	strh r0, [r6, #0x30]
.L08052CC6:
	ldrh r3, [r6, #0x2e]
	movs r1, #0xff
	ands r1, r3
	ldr r5, .L08052D34 @ =gUnk_08605A94
	lsls r0, r1, #1
	adds r0, r0, r5
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	ldrh r0, [r0]
	muls r0, r2, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	ldr r4, .L08052D38 @ =gDispIo
	strh r0, [r4, #0x20]
	adds r1, #0x40
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	adds r0, r1, #0
	muls r0, r2, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	adds r0, #0x10
	strh r0, [r4, #0x22]
	adds r3, #2
	strh r3, [r6, #0x2e]
	movs r0, #1
	ldrh r1, [r6, #0x2c]
	ands r0, r1
	cmp r0, #0
	bne .L08052D0E
	movs r0, #1
	movs r1, #0
	movs r2, #0x10
	bl SetBgOffset
.L08052D0E:
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	movs r1, #0xa0
	lsls r1, r1, #0x11
	cmp r0, r1
	bne .L08052D2C
	ldr r1, .L08052D3C @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r6, #0
	bl Proc_Break
.L08052D2C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08052D34: .4byte gUnk_08605A94
.L08052D38: .4byte gDispIo
.L08052D3C: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08052D40
func_fe6_08052D40: @ 0x08052D40
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L08052D7C @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08052D80 @ =gUnk_085D2658
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	movs r1, #0x10
	strh r1, [r0, #0x2e]
	ldr r0, .L08052D84 @ =gUnk_0817B418
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	ldr r0, .L08052D88 @ =gPal
	movs r1, #1
	movs r2, #1
	movs r3, #0x10
	bl EfxPalBlackInOut
	bl EnablePalSync
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08052D7C: .4byte gEfxBgSemaphore
.L08052D80: .4byte gUnk_085D2658
.L08052D84: .4byte gUnk_0817B418
.L08052D88: .4byte gPal

	thumb_func_start func_fe6_08052D8C
func_fe6_08052D8C: @ 0x08052D8C
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r1, #0x2e
	ldrsh r0, [r5, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0
	bl Interpolate
	adds r4, r0, #0
	ldr r0, .L08052DE8 @ =gUnk_0817B418
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	ldr r0, .L08052DEC @ =gPal
	movs r1, #1
	movs r2, #1
	adds r3, r4, #0
	bl EfxPalBlackInOut
	bl EnablePalSync
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r5, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08052DDE
	ldr r1, .L08052DF0 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r5, #0
	bl Proc_Break
.L08052DDE:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08052DE8: .4byte gUnk_0817B418
.L08052DEC: .4byte gPal
.L08052DF0: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08052DF4
func_fe6_08052DF4: @ 0x08052DF4
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
.L08052DFA:
	ldr r0, .L08052E24 @ =gUnk_085D2678
	movs r1, #3
	bl SpawnProc
	str r5, [r0, #0x5c]
	str r4, [r0, #0x44]
	adds r4, #1
	cmp r4, #7
	bls .L08052DFA
	ldr r0, .L08052E28 @ =gUnk_0817BBB4
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L08052E2C @ =gUnk_0817B8D0
	movs r1, #0x80
	lsls r1, r1, #4
	bl SpellFx_RegisterObjGfx
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08052E24: .4byte gUnk_085D2678
.L08052E28: .4byte gUnk_0817BBB4
.L08052E2C: .4byte gUnk_0817B8D0

	thumb_func_start func_fe6_08052E30
func_fe6_08052E30: @ 0x08052E30
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, .L08052E90 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	movs r0, #0
	strh r0, [r4, #0x2c]
	strh r0, [r4, #0x2e]
	ldr r0, [r4, #0x44]
	lsls r1, r0, #0xd
	strh r1, [r4, #0x30]
	ldr r1, .L08052E94 @ =gUnk_085D26B0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	ldr r0, [r4, #0x5c]
	str r3, [sp]
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	str r0, [r4, #0x60]
	ldr r1, .L08052E98 @ =0x0000F3FF
	ldrh r2, [r0, #8]
	ands r1, r2
	movs r3, #0x80
	lsls r3, r3, #3
	adds r2, r3, #0
	orrs r1, r2
	strh r1, [r0, #8]
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0, #2]
	strh r1, [r0, #4]
	movs r0, #0x78
	strh r0, [r4, #0x32]
	movs r0, #0x40
	strh r0, [r4, #0x3a]
	adds r0, r4, #0
	bl Proc_Break
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08052E90: .4byte gEfxBgSemaphore
.L08052E94: .4byte gUnk_085D26B0
.L08052E98: .4byte 0x0000F3FF

	thumb_func_start func_fe6_08052E9C
func_fe6_08052E9C: @ 0x08052E9C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r4, [r5, #0x60]
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r7, #0x3c
	str r7, [sp]
	movs r0, #0
	movs r1, #0xb4
	movs r2, #0x32
	bl Interpolate
	ldrh r2, [r5, #0x30]
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r1, r2, r3
	movs r6, #0
	strh r1, [r5, #0x30]
	lsrs r2, r1, #8
	ldr r3, .L08052F24 @ =gSinLut
	lsls r1, r2, #1
	adds r1, r1, r3
	adds r2, #0x40
	lsls r2, r2, #1
	adds r2, r2, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r1, r0, r1
	lsls r1, r1, #4
	movs r3, #0
	ldrsh r2, [r2, r3]
	muls r0, r2, r0
	lsls r0, r0, #4
	asrs r1, r1, #0x10
	ldrh r2, [r5, #0x32]
	adds r1, r2, r1
	asrs r0, r0, #0x10
	ldrh r3, [r5, #0x3a]
	adds r0, r3, r0
	strh r1, [r4, #2]
	strh r0, [r4, #4]
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3c
	ble .L08052F04
	strh r7, [r5, #0x2c]
.L08052F04:
	ldrh r0, [r5, #0x2e]
	adds r0, #1
	strh r0, [r5, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x78
	ble .L08052F1C
	strh r6, [r5, #0x2c]
	strh r6, [r5, #0x2e]
	adds r0, r5, #0
	bl Proc_Break
.L08052F1C:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08052F24: .4byte gSinLut

	thumb_func_start func_fe6_08052F28
func_fe6_08052F28: @ 0x08052F28
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r4, [r5, #0x60]
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r7, #0x50
	str r7, [sp]
	movs r0, #0
	movs r1, #0x32
	movs r2, #0
	bl Interpolate
	ldrh r2, [r5, #0x30]
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r1, r2, r3
	movs r6, #0
	strh r1, [r5, #0x30]
	lsrs r2, r1, #8
	ldr r3, .L08052FB0 @ =gSinLut
	lsls r1, r2, #1
	adds r1, r1, r3
	adds r2, #0x40
	lsls r2, r2, #1
	adds r2, r2, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r1, r0, r1
	lsls r1, r1, #4
	movs r3, #0
	ldrsh r2, [r2, r3]
	muls r0, r2, r0
	lsls r0, r0, #4
	asrs r1, r1, #0x10
	ldrh r2, [r5, #0x32]
	adds r1, r2, r1
	asrs r0, r0, #0x10
	ldrh r3, [r5, #0x3a]
	adds r0, r3, r0
	strh r1, [r4, #2]
	strh r0, [r4, #4]
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x50
	ble .L08052F90
	strh r7, [r5, #0x2c]
.L08052F90:
	ldrh r0, [r5, #0x2e]
	adds r0, #1
	strh r0, [r5, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x50
	ble .L08052FA8
	strh r6, [r5, #0x2c]
	strh r6, [r5, #0x2e]
	adds r0, r5, #0
	bl Proc_Break
.L08052FA8:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08052FB0: .4byte gSinLut

	thumb_func_start func_fe6_08052FB4
func_fe6_08052FB4: @ 0x08052FB4
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r4, [r5, #0x60]
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r6, #0x32
	str r6, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0xb4
	bl Interpolate
	ldrh r2, [r5, #0x30]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r2, r3
	strh r1, [r5, #0x30]
	lsrs r2, r1, #8
	ldr r3, .L08053044 @ =gSinLut
	lsls r1, r2, #1
	adds r1, r1, r3
	adds r2, #0x40
	lsls r2, r2, #1
	adds r2, r2, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	muls r1, r0, r1
	lsls r1, r1, #4
	movs r3, #0
	ldrsh r2, [r2, r3]
	muls r0, r2, r0
	lsls r0, r0, #4
	asrs r1, r1, #0x10
	ldrh r2, [r5, #0x32]
	adds r1, r2, r1
	asrs r0, r0, #0x10
	ldrh r3, [r5, #0x3a]
	adds r0, r3, r0
	strh r1, [r4, #2]
	strh r0, [r4, #4]
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x32
	ble .L0805301A
	strh r6, [r5, #0x2c]
.L0805301A:
	ldrh r0, [r5, #0x2e]
	adds r0, #1
	strh r0, [r5, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x32
	ble .L0805303C
	ldr r0, .L08053048 @ =gEfxBgSemaphore
	ldr r1, [r0]
	subs r1, #1
	str r1, [r0]
	ldr r0, [r5, #0x60]
	bl BasRemove
	adds r0, r5, #0
	bl Proc_Break
.L0805303C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08053044: .4byte gSinLut
.L08053048: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0805304C
func_fe6_0805304C: @ 0x0805304C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L0805307C @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08053080 @ =gUnk_085D26D0
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	strh r5, [r0, #0x30]
	str r1, [r0, #0x44]
	ldr r1, .L08053084 @ =gUnk_0811A62A
	str r1, [r0, #0x48]
	ldr r1, .L08053088 @ =gUnk_0817BBB6
	str r1, [r0, #0x4c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805307C: .4byte gEfxBgSemaphore
.L08053080: .4byte gUnk_085D26D0
.L08053084: .4byte gUnk_0811A62A
.L08053088: .4byte gUnk_0817BBB6

	thumb_func_start func_fe6_0805308C
func_fe6_0805308C: @ 0x0805308C
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	cmp r3, #0
	blt .L080530B6
	ldr r0, [r4, #0x4c]
	ldr r1, .L080530DC @ =gPal+0x2
	movs r2, #0xf
	str r2, [sp]
	adds r2, r3, #0
	movs r3, #0xf
	bl func_fe6_08047B6C
.L080530B6:
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x30]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L080530D4
	ldr r1, .L080530E0 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L080530D4:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080530DC: .4byte gPal+0x2
.L080530E0: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_080530E4
func_fe6_080530E4: @ 0x080530E4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	ldr r1, .L0805310C @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08053110 @ =gUnk_085D26F0
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	str r6, [r0, #0x64]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805310C: .4byte gEfxBgSemaphore
.L08053110: .4byte gUnk_085D26F0

	thumb_func_start func_fe6_08053114
func_fe6_08053114: @ 0x08053114
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r4, [r5, #0x64]
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r1, #0x2e
	ldrsh r0, [r5, r1]
	str r0, [sp]
	movs r0, #4
	movs r1, #0x80
	movs r2, #0
	bl Interpolate
	str r0, [r4, #0x4c]
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r5, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08053150
	ldr r1, .L08053158 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r5, #0
	bl Proc_Break
.L08053150:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08053158: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0805315C
func_fe6_0805315C: @ 0x0805315C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r1, .L08053184 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08053188 @ =gUnk_085D2708
	movs r1, #3
	bl SpawnProc
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r4, [r0, #0x2e]
	strh r5, [r0, #0x30]
	str r6, [r0, #0x5c]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08053184: .4byte gEfxBgSemaphore
.L08053188: .4byte gUnk_085D2708

	thumb_func_start func_fe6_0805318C
func_fe6_0805318C: @ 0x0805318C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L080531B8
	ldr r1, .L080531C0 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	ldr r0, [r4, #0x5c]
	movs r2, #0x30
	ldrsh r1, [r4, r2]
	bl NewEfxFlashBgWhite
	adds r0, r4, #0
	bl Proc_Break
.L080531B8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080531C0: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_080531C4
func_fe6_080531C4: @ 0x080531C4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r1, .L080531EC @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080531F0 @ =gUnk_085D2720
	movs r1, #3
	bl SpawnProc
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r4, [r0, #0x2e]
	strh r5, [r0, #0x30]
	str r6, [r0, #0x5c]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080531EC: .4byte gEfxBgSemaphore
.L080531F0: .4byte gUnk_085D2720

	thumb_func_start func_fe6_080531F4
func_fe6_080531F4: @ 0x080531F4
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x2c]
	adds r0, #1
	strh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	ldrh r3, [r2, #0x2e]
	lsls r1, r3, #0x10
	cmp r0, r1
	ble .L08053212
	movs r0, #0
	strh r0, [r2, #0x2c]
	adds r0, r2, #0
	bl Proc_Break
.L08053212:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08053218
func_fe6_08053218: @ 0x08053218
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r1, #0x30
	ldrsh r0, [r5, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0x10
	bl Interpolate
	adds r4, r0, #0
	ldr r0, .L08053270 @ =gUnk_0817B418
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	ldr r0, .L08053274 @ =gPal
	movs r1, #1
	movs r2, #1
	adds r3, r4, #0
	bl EfxPalWhiteInOut
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r5, #0x30]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08053266
	ldr r1, .L08053278 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r5, #0
	bl Proc_Break
.L08053266:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08053270: .4byte gUnk_0817B418
.L08053274: .4byte gPal
.L08053278: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0805327C
func_fe6_0805327C: @ 0x0805327C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r1, .L08053320 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08053324 @ =gUnk_085D2740
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r6, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	strh r0, [r5, #0x2e]
	strh r4, [r5, #0x30]
	str r0, [r5, #0x44]
	ldr r0, .L08053328 @ =gUnk_0811A668
	str r0, [r5, #0x48]
	ldr r0, .L0805332C @ =gUnk_085D2768
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L08053330 @ =gUnk_085D2758
	str r0, [r5, #0x54]
	ldr r0, .L08053334 @ =gUnk_08181E60
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	bl SpellFx_SetSomeColorEffect
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	bl GetEkrDragonStateType
	cmp r0, #0
	beq .L08053318
	ldr r0, [r5, #0x5c]
	bl GetAnimAnotherSide
	ldr r4, .L08053338 @ =gDispIo
	movs r2, #4
	rsbs r2, r2, #0
	adds r1, r2, #0
	ldrb r3, [r4, #0xc]
	ands r1, r3
	strb r1, [r4, #0xc]
	adds r1, r2, #0
	ldrb r3, [r4, #0x18]
	ands r1, r3
	movs r3, #1
	orrs r1, r3
	strb r1, [r4, #0x18]
	ldrb r1, [r4, #0x10]
	ands r2, r1
	movs r1, #2
	orrs r2, r1
	strb r2, [r4, #0x10]
	movs r1, #3
	ldrb r2, [r4, #0x14]
	orrs r1, r2
	strb r1, [r4, #0x14]
	ldr r1, .L0805333C @ =0x0000F3FF
	adds r2, r1, #0
	ldrh r3, [r6, #8]
	ands r2, r3
	movs r4, #0x80
	lsls r4, r4, #3
	adds r3, r4, #0
	orrs r2, r3
	strh r2, [r6, #8]
	ldrh r2, [r0, #8]
	ands r1, r2
	orrs r1, r3
	strh r1, [r0, #8]
.L08053318:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08053320: .4byte gEfxBgSemaphore
.L08053324: .4byte gUnk_085D2740
.L08053328: .4byte gUnk_0811A668
.L0805332C: .4byte gUnk_085D2768
.L08053330: .4byte gUnk_085D2758
.L08053334: .4byte gUnk_08181E60
.L08053338: .4byte gDispIo
.L0805333C: .4byte 0x0000F3FF

	thumb_func_start func_fe6_08053340
func_fe6_08053340: @ 0x08053340
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r0, [r7, #0x5c]
	bl GetAnimAnotherSide
	mov r8, r0
	adds r0, r7, #0
	adds r0, #0x2c
	adds r1, r7, #0
	adds r1, #0x44
	ldr r2, [r7, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	blt .L08053388
	ldr r5, [r7, #0x4c]
	ldr r6, [r7, #0x50]
	ldr r0, [r7, #0x54]
	lsls r4, r4, #2
	adds r0, r4, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	ldr r0, [r7, #0x5c]
	adds r5, r4, r5
	ldr r1, [r5]
	adds r4, r4, r6
	ldr r2, [r4]
	bl SpellFx_WriteBgMap
.L08053388:
	ldrh r0, [r7, #0x2e]
	adds r0, #1
	strh r0, [r7, #0x2e]
	lsls r0, r0, #0x10
	ldrh r2, [r7, #0x30]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L08053408
	bl GetEkrDragonStateType
	cmp r0, #0
	beq .L080533F2
	ldr r3, .L08053414 @ =gDispIo
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	ldrb r2, [r3, #0xc]
	ands r0, r2
	strb r0, [r3, #0xc]
	adds r0, r1, #0
	ldrb r2, [r3, #0x10]
	ands r0, r2
	movs r2, #1
	orrs r0, r2
	strb r0, [r3, #0x10]
	ldrb r0, [r3, #0x18]
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	strb r1, [r3, #0x18]
	movs r0, #3
	ldrb r1, [r3, #0x14]
	orrs r0, r1
	strb r0, [r3, #0x14]
	ldr r2, [r7, #0x5c]
	ldr r1, .L08053418 @ =0x0000F3FF
	adds r0, r1, #0
	ldrh r3, [r2, #8]
	ands r0, r3
	strh r0, [r2, #8]
	ldr r2, [r7, #0x5c]
	movs r0, #0x80
	lsls r0, r0, #4
	adds r3, r0, #0
	ldrh r0, [r2, #8]
	orrs r0, r3
	strh r0, [r2, #8]
	mov r2, r8
	ldrh r2, [r2, #8]
	ands r1, r2
	orrs r1, r3
	mov r3, r8
	strh r1, [r3, #8]
.L080533F2:
	bl SpellFx_ClearBG1
	ldr r1, .L0805341C @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	adds r0, r7, #0
	bl Proc_End
.L08053408:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08053414: .4byte gDispIo
.L08053418: .4byte 0x0000F3FF
.L0805341C: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08053420
func_fe6_08053420: @ 0x08053420
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r2
	ldr r1, .L080534A4 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080534A8 @ =gUnk_085D2778
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	strh r6, [r4, #0x2e]
	mov r0, r8
	strh r0, [r4, #0x30]
	ldr r3, .L080534AC @ =gUnk_085EBF40
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	adds r5, r0, #0
	str r5, [r4, #0x60]
	movs r0, #0x78
	strh r0, [r5, #2]
	movs r0, #0x48
	strh r0, [r5, #4]
	movs r0, #0x14
	strh r0, [r5, #0xa]
	bl BasSort
	bl GetEkrDragonStateType
	cmp r0, #0
	beq .L08053486
	ldr r0, .L080534B0 @ =0x0000F3FF
	ldrh r1, [r5, #8]
	ands r0, r1
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5, #8]
.L08053486:
	ldr r0, .L080534B4 @ =gUnk_081629D4
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L080534B8 @ =gUnk_081830F4
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080534A4: .4byte gEfxBgSemaphore
.L080534A8: .4byte gUnk_085D2778
.L080534AC: .4byte gUnk_085EBF40
.L080534B0: .4byte 0x0000F3FF
.L080534B4: .4byte gUnk_081629D4
.L080534B8: .4byte gUnk_081830F4

	thumb_func_start func_fe6_080534BC
func_fe6_080534BC: @ 0x080534BC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0x60]
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r3, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r5, [r4, #0x2e]
	lsls r1, r5, #0x10
	cmp r0, r1
	ble .L080534EE
	strh r3, [r4, #0x2c]
	ldr r0, .L080534F4 @ =gUnk_085EC478
	str r0, [r2, #0x24]
	str r0, [r2, #0x20]
	strh r3, [r2, #6]
	ldr r0, .L080534F8 @ =gUnk_0818360C
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	adds r0, r4, #0
	bl Proc_Break
.L080534EE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080534F4: .4byte gUnk_085EC478
.L080534F8: .4byte gUnk_0818360C

	thumb_func_start func_fe6_080534FC
func_fe6_080534FC: @ 0x080534FC
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x30]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08053524
	ldr r0, [r4, #0x60]
	bl BasRemove
	ldr r1, .L0805352C @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L08053524:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805352C: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08053530
func_fe6_08053530: @ 0x08053530
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L08053560 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08053564 @ =gUnk_085D2798
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r2, #0
	strh r2, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	strh r2, [r0, #0x30]
	movs r1, #1
	str r1, [r0, #0x44]
	str r2, [r0, #0x48]
	str r2, [r0, #0x4c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08053560: .4byte gEfxBgSemaphore
.L08053564: .4byte gUnk_085D2798

	thumb_func_start func_fe6_08053568
func_fe6_08053568: @ 0x08053568
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r1, #0
	mov ip, r1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L08053594
	ldr r1, .L08053590 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
	b .L080535E4
	.align 2, 0
.L08053590: .4byte gEfxBgSemaphore
.L08053594:
	ldrh r0, [r4, #0x30]
	adds r0, #1
	strh r0, [r4, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r4, #0x44]
	cmp r0, r1
	bne .L080535E4
	mov r0, ip
	strh r0, [r4, #0x30]
	movs r0, #2
	str r0, [r4, #0x44]
	ldr r3, .L080535EC @ =gUnk_085D27B0
	ldr r1, [r4, #0x4c]
	lsls r2, r1, #2
	adds r0, r2, r3
	ldr r7, [r0]
	ldr r0, .L080535F0 @ =gUnk_085D287C
	adds r0, r2, r0
	ldr r6, [r0]
	ldr r0, .L080535F4 @ =gUnk_085D2944
	adds r2, r2, r0
	ldr r5, [r2]
	adds r1, #1
	str r1, [r4, #0x4c]
	lsls r1, r1, #2
	adds r1, r1, r3
	ldr r1, [r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080535D8
	mov r1, ip
	str r1, [r4, #0x4c]
.L080535D8:
	ldr r0, [r4, #0x5c]
	adds r1, r7, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl func_fe6_080535F8
.L080535E4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080535EC: .4byte gUnk_085D27B0
.L080535F0: .4byte gUnk_085D287C
.L080535F4: .4byte gUnk_085D2944

	thumb_func_start func_fe6_080535F8
func_fe6_080535F8: @ 0x080535F8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	mov r8, r0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r7, r3, #0
	ldr r1, .L08053644 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08053648 @ =gUnk_085D2A0C
	movs r1, #3
	bl SpawnProc
	adds r6, r0, #0
	mov r0, r8
	str r0, [r6, #0x5c]
	movs r0, #0
	strh r0, [r6, #0x2c]
	strh r4, [r6, #0x2e]
	str r5, [r6, #0x44]
	lsls r4, r4, #0xb
	adds r5, r5, r4
	str r5, [r6, #0x48]
	movs r0, #0x78
	strh r0, [r6, #0x32]
	movs r0, #0x48
	strh r0, [r6, #0x3a]
	cmp r7, #6
	bhi .L0805367C
	lsls r0, r7, #2
	ldr r1, .L0805364C @ =.L08053650
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08053644: .4byte gEfxBgSemaphore
.L08053648: .4byte gUnk_085D2A0C
.L0805364C: .4byte .L08053650
.L08053650: @ jump table
	.4byte .L0805366C @ case 0
	.4byte .L0805366C @ case 1
	.4byte .L0805366C @ case 2
	.4byte .L0805366C @ case 3
	.4byte .L0805366C @ case 4
	.4byte .L08053674 @ case 5
	.4byte .L0805367C @ case 6
.L0805366C:
	ldr r3, .L08053670 @ =gUnk_085EBF60
	b .L0805367E
	.align 2, 0
.L08053670: .4byte gUnk_085EBF60
.L08053674:
	ldr r3, .L08053678 @ =gUnk_085EBF58
	b .L0805367E
	.align 2, 0
.L08053678: .4byte gUnk_085EBF58
.L0805367C:
	ldr r3, .L080536BC @ =gUnk_085EBF50
.L0805367E:
	str r3, [sp]
	mov r0, r8
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	adds r4, r0, #0
	str r4, [r6, #0x60]
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r4, #2]
	strh r0, [r4, #4]
	bl GetEkrDragonStateType
	cmp r0, #0
	beq .L080536AE
	ldr r0, .L080536C0 @ =0x0000F3FF
	ldrh r1, [r4, #8]
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r4, #8]
.L080536AE:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080536BC: .4byte gUnk_085EBF50
.L080536C0: .4byte 0x0000F3FF

	thumb_func_start func_fe6_080536C4
func_fe6_080536C4: @ 0x080536C4
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r5, [r6, #0x60]
	movs r0, #0x2c
	ldrsh r3, [r6, r0]
	movs r1, #0x2e
	ldrsh r0, [r6, r1]
	str r0, [sp]
	movs r0, #1
	movs r1, #0x6e
	movs r2, #0
	bl Interpolate
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r1, [r6, #0x44]
	ldr r2, [r6, #0x48]
	movs r7, #0x2c
	ldrsh r3, [r6, r7]
	movs r7, #0x2e
	ldrsh r0, [r6, r7]
	str r0, [sp]
	movs r0, #1
	bl Interpolate
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x18
	ldr r2, .L0805375C @ =gSinLut
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r0, #0x40
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	muls r1, r4, r1
	lsls r1, r1, #4
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r4, r0
	lsls r0, r0, #4
	asrs r1, r1, #0x10
	ldrh r2, [r6, #0x32]
	adds r1, r2, r1
	asrs r0, r0, #0x10
	ldrh r7, [r6, #0x3a]
	adds r0, r7, r0
	strh r1, [r5, #2]
	strh r0, [r5, #4]
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r6, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08053752
	ldr r0, [r6, #0x60]
	bl BasRemove
	ldr r1, .L08053760 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r6, #0
	bl Proc_Break
.L08053752:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805375C: .4byte gSinLut
.L08053760: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08053764
func_fe6_08053764: @ 0x08053764
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl func_fe6_08047300
	bl SpellFx_SetBG1Position
	ldr r0, .L0805379C @ =gUnk_085D2A24
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805379C: .4byte gUnk_085D2A24

	thumb_func_start func_fe6_080537A0
func_fe6_080537A0: @ 0x080537A0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	ldr r0, [r6, #0x5c]
	bl GetAnimAnotherSide
	adds r5, r0, #0
	bl EfxGetCamMovDuration
	adds r4, r0, #0
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	movs r1, #0
	mov r8, r1
	movs r7, #0
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L080537D6
	ldr r0, [r6, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl NewEfxFarAttackWithDistance
.L080537D6:
	movs r2, #0x2c
	ldrsh r1, [r6, r2]
	adds r0, r4, #1
	cmp r1, r0
	bne .L08053848
	ldr r3, .L08053844 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	mov r2, r8
	strb r2, [r0]
	adds r0, #1
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	str r1, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0x1e
	movs r3, #0
	bl func_fe6_0804CD88
	str r7, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r1, #0xa0
	movs r2, #0x1e
	movs r3, #0x10
	bl func_fe6_0804CD88
	ldr r0, [r6, #0x5c]
	bl func_fe6_08053954
	ldr r0, [r6, #0x5c]
	bl func_fe6_08053CB4
	movs r0, #0x9c
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0x78
	movs r3, #0
	bl func_fe6_0805C804
	b .L08053946
	.align 2, 0
.L08053844: .4byte gDispIo
.L08053848:
	adds r0, r4, #0
	adds r0, #0x7f
	cmp r1, r0
	bne .L0805387C
	movs r0, #2
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0x52
	movs r2, #0xf
	movs r3, #0
	bl func_fe6_0804C8D4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x3c
	bl func_fe6_08050D68
	ldr r2, .L08053878 @ =func_fe6_0804CD4C
	adds r0, r5, #0
	movs r1, #0x53
	bl func_fe6_0804CC68
	b .L08053946
	.align 2, 0
.L08053878: .4byte func_fe6_0804CD4C
.L0805387C:
	adds r0, r4, #0
	adds r0, #0xd2
	cmp r1, r0
	bne .L0805388C
	adds r0, r5, #0
	bl func_fe6_080539C4
	b .L08053946
.L0805388C:
	adds r0, r4, #0
	adds r0, #0xd7
	cmp r1, r0
	bne .L080538AC
	ldr r0, .L080538A8 @ =0x00000139
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl func_fe6_0805C804
	b .L08053946
	.align 2, 0
.L080538A8: .4byte 0x00000139
.L080538AC:
	adds r0, r4, #0
	adds r0, #0xf1
	cmp r1, r0
	bne .L080538BC
	ldr r0, [r6, #0x5c]
	bl func_fe6_08053AFC
	b .L08053946
.L080538BC:
	movs r2, #0x9e
	lsls r2, r2, #1
	adds r0, r4, r2
	cmp r1, r0
	bne .L08053902
	movs r0, #0x9d
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl func_fe6_0805C804
	adds r0, r5, #0
	movs r1, #0xa
	bl NewEfxFlashBgWhite
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, r6, #0
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl StartBattleAnimHitEffectsDefault
	ldrb r0, [r4]
	cmp r0, #0
	bne .L08053946
	adds r0, r5, #0
	bl func_fe6_0805C358
	b .L08053946
.L08053902:
	movs r2, #0xa3
	lsls r2, r2, #1
	adds r0, r4, r2
	cmp r1, r0
	bne .L08053924
	adds r0, r5, #0
	bl func_fe6_08053A44
	str r7, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x10
	movs r2, #0xa
	movs r3, #0x10
	bl func_fe6_0804CD88
	b .L08053946
.L08053924:
	movs r3, #0xaf
	lsls r3, r3, #1
	adds r0, r4, r3
	cmp r1, r0
	beq .L08053946
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r0, r4, r2
	cmp r1, r0
	bne .L08053946
	bl SpellFx_Finish
	bl func_fe6_08047358
	adds r0, r6, #0
	bl Proc_Break
.L08053946:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08053954
func_fe6_08053954: @ 0x08053954
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L080539A8 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080539AC @ =gUnk_085D2A3C
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L080539B0 @ =gUnk_0811A67A
	str r1, [r0, #0x48]
	ldr r1, .L080539B4 @ =gUnk_085D2A54
	str r1, [r0, #0x4c]
	str r1, [r0, #0x50]
	ldr r1, .L080539B8 @ =gUnk_085D2AC0
	str r1, [r0, #0x54]
	ldr r0, .L080539BC @ =gUnk_0816B328
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	bl SpellFx_SetSomeColorEffect
	ldr r2, .L080539C0 @ =gDispIo
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrb r1, [r2, #1]
	ands r0, r1
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r2, #1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080539A8: .4byte gEfxBgSemaphore
.L080539AC: .4byte gUnk_085D2A3C
.L080539B0: .4byte gUnk_0811A67A
.L080539B4: .4byte gUnk_085D2A54
.L080539B8: .4byte gUnk_085D2AC0
.L080539BC: .4byte gUnk_0816B328
.L080539C0: .4byte gDispIo

	thumb_func_start func_fe6_080539C4
func_fe6_080539C4: @ 0x080539C4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L08053A28 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08053A2C @ =gUnk_085D2A3C
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r4, #0
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L08053A30 @ =gUnk_0811A680
	str r1, [r0, #0x48]
	ldr r1, .L08053A34 @ =gUnk_085D2A54
	str r1, [r0, #0x4c]
	str r1, [r0, #0x50]
	ldr r1, .L08053A38 @ =gUnk_085D2AC0
	str r1, [r0, #0x54]
	ldr r0, .L08053A3C @ =gUnk_0818BBCC
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	bl SpellFx_SetSomeColorEffect
	ldr r3, .L08053A40 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r1, r3, #0
	adds r1, #0x44
	movs r0, #0xc
	strb r0, [r1]
	adds r1, #1
	movs r0, #6
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x46
	strb r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08053A28: .4byte gEfxBgSemaphore
.L08053A2C: .4byte gUnk_085D2A3C
.L08053A30: .4byte gUnk_0811A680
.L08053A34: .4byte gUnk_085D2A54
.L08053A38: .4byte gUnk_085D2AC0
.L08053A3C: .4byte gUnk_0818BBCC
.L08053A40: .4byte gDispIo

	thumb_func_start func_fe6_08053A44
func_fe6_08053A44: @ 0x08053A44
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L08053A80 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08053A84 @ =gUnk_085D2A3C
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L08053A88 @ =gUnk_0811A722
	str r1, [r0, #0x48]
	ldr r1, .L08053A8C @ =gUnk_085D2A54
	str r1, [r0, #0x4c]
	str r1, [r0, #0x50]
	ldr r1, .L08053A90 @ =gUnk_085D2AC0
	str r1, [r0, #0x54]
	ldr r0, .L08053A94 @ =gUnk_0818BBEC
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	bl SpellFx_SetSomeColorEffect
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08053A80: .4byte gEfxBgSemaphore
.L08053A84: .4byte gUnk_085D2A3C
.L08053A88: .4byte gUnk_0811A722
.L08053A8C: .4byte gUnk_085D2A54
.L08053A90: .4byte gUnk_085D2AC0
.L08053A94: .4byte gUnk_0818BBEC

	thumb_func_start func_fe6_08053A98
func_fe6_08053A98: @ 0x08053A98
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r0, #0x2c
	adds r1, r7, #0
	adds r1, #0x44
	ldr r2, [r7, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	blt .L08053AD4
	ldr r5, [r7, #0x4c]
	ldr r6, [r7, #0x50]
	ldr r0, [r7, #0x54]
	lsls r4, r4, #2
	adds r0, r4, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	ldr r0, [r7, #0x5c]
	adds r5, r4, r5
	ldr r1, [r5]
	adds r4, r4, r6
	ldr r2, [r4]
	bl SpellFx_WriteBgMap
	b .L08053AF2
.L08053AD4:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	bne .L08053AF2
	bl SpellFx_ClearBG1
	ldr r1, .L08053AF8 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	adds r0, r7, #0
	bl Proc_Break
.L08053AF2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08053AF8: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08053AFC
func_fe6_08053AFC: @ 0x08053AFC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L08053B54 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08053B58 @ =gUnk_085D2B2C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	adds r0, r5, #0
	bl GetAnimAnotherSide
	adds r5, r0, #0
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r3, .L08053B5C @ =AnimScr_ManaketeFlame
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	adds r6, r0, #0
	str r6, [r4, #0x60]
	ldr r0, .L08053B60 @ =0x0000F3FF
	ldrh r1, [r6, #8]
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r6, #8]
	adds r0, r5, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L08053B64
	ldrh r0, [r6, #2]
	subs r0, #8
	b .L08053B68
	.align 2, 0
.L08053B54: .4byte gEfxBgSemaphore
.L08053B58: .4byte gUnk_085D2B2C
.L08053B5C: .4byte AnimScr_ManaketeFlame
.L08053B60: .4byte 0x0000F3FF
.L08053B64:
	ldrh r0, [r6, #2]
	adds r0, #8
.L08053B68:
	strh r0, [r6, #2]
	ldrh r0, [r6, #4]
	subs r0, #0x10
	strh r0, [r6, #4]
	bl GetEkrDragonStateTypeIdunn
	cmp r0, #0
	beq .L08053B7E
	ldrh r0, [r6, #2]
	subs r0, #0x10
	strh r0, [r6, #2]
.L08053B7E:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08053B88
func_fe6_08053B88: @ 0x08053B88
	push {lr}
	ldr r2, .L08053B9C @ =gEfxBgSemaphore
	ldr r1, [r2]
	subs r1, #1
	str r1, [r2]
	ldr r0, [r0, #0x60]
	bl BasRemove
	pop {r0}
	bx r0
	.align 2, 0
.L08053B9C: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08053BA0
func_fe6_08053BA0: @ 0x08053BA0
	push {r4, lr}
	adds r1, r0, #0
	ldr r2, [r1, #0x60]
	ldrh r0, [r1, #0x2c]
	adds r0, #1
	movs r4, #0
	strh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	cmp r3, #1
	bne .L08053BE4
	ldr r0, .L08053BD8 @ =gUnk_085EC630
	str r0, [r2, #0x24]
	str r0, [r2, #0x20]
	strh r4, [r2, #6]
	movs r0, #0xa
	strh r0, [r1, #0x2e]
	ldr r0, .L08053BDC @ =gUnk_0818EA78
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L08053BE0 @ =gUnk_0818DD18
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	b .L08053BF4
	.align 2, 0
.L08053BD8: .4byte gUnk_085EC630
.L08053BDC: .4byte gUnk_0818EA78
.L08053BE0: .4byte gUnk_0818DD18
.L08053BE4:
	movs r2, #0x2e
	ldrsh r0, [r1, r2]
	cmp r3, r0
	bne .L08053BF4
	strh r4, [r1, #0x2c]
	adds r0, r1, #0
	bl Proc_Break
.L08053BF4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08053BFC
func_fe6_08053BFC: @ 0x08053BFC
	push {r4, lr}
	adds r1, r0, #0
	ldr r2, [r1, #0x60]
	ldrh r0, [r1, #0x2c]
	adds r0, #1
	movs r4, #0
	strh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	cmp r3, #1
	bne .L08053C40
	ldr r0, .L08053C34 @ =gUnk_085EC938
	str r0, [r2, #0x24]
	str r0, [r2, #0x20]
	strh r4, [r2, #6]
	movs r0, #0xa
	strh r0, [r1, #0x2e]
	ldr r0, .L08053C38 @ =gUnk_0818EA78
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L08053C3C @ =gUnk_0818E1E4
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	b .L08053C50
	.align 2, 0
.L08053C34: .4byte gUnk_085EC938
.L08053C38: .4byte gUnk_0818EA78
.L08053C3C: .4byte gUnk_0818E1E4
.L08053C40:
	movs r2, #0x2e
	ldrsh r0, [r1, r2]
	cmp r3, r0
	bne .L08053C50
	strh r4, [r1, #0x2c]
	adds r0, r1, #0
	bl Proc_Break
.L08053C50:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08053C58
func_fe6_08053C58: @ 0x08053C58
	push {r4, lr}
	adds r1, r0, #0
	ldr r2, [r1, #0x60]
	ldrh r0, [r1, #0x2c]
	adds r0, #1
	movs r4, #0
	strh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	cmp r3, #1
	bne .L08053C9C
	ldr r0, .L08053C90 @ =gUnk_085ECC34
	str r0, [r2, #0x24]
	str r0, [r2, #0x20]
	strh r4, [r2, #6]
	movs r0, #0xa
	strh r0, [r1, #0x2e]
	ldr r0, .L08053C94 @ =gUnk_0818EA78
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L08053C98 @ =gUnk_0818E67C
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	b .L08053CAC
	.align 2, 0
.L08053C90: .4byte gUnk_085ECC34
.L08053C94: .4byte gUnk_0818EA78
.L08053C98: .4byte gUnk_0818E67C
.L08053C9C:
	movs r2, #0x2e
	ldrsh r0, [r1, r2]
	cmp r3, r0
	bne .L08053CAC
	strh r4, [r1, #0x2c]
	adds r0, r1, #0
	bl Proc_Break
.L08053CAC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08053CB4
func_fe6_08053CB4: @ 0x08053CB4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L08053CEC @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08053CF0 @ =gUnk_085D2B74
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	movs r1, #0x64
	strh r1, [r0, #0x30]
	ldr r0, .L08053CF4 @ =gUnk_081629D4
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L08053CF8 @ =gUnk_08161DDC
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08053CEC: .4byte gEfxBgSemaphore
.L08053CF0: .4byte gUnk_085D2B74
.L08053CF4: .4byte gUnk_081629D4
.L08053CF8: .4byte gUnk_08161DDC

	thumb_func_start func_fe6_08053CFC
func_fe6_08053CFC: @ 0x08053CFC
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x12
	bne .L08053D4E
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r0, .L08053D54 @ =gUnk_085D2B8C
	movs r1, #0x2e
	ldrsh r2, [r4, r1]
	lsls r1, r2, #2
	adds r1, r1, r0
	lsls r2, r2, #1
	adds r2, #1
	lsls r2, r2, #1
	adds r2, r2, r0
	ldr r0, [r4, #0x5c]
	movs r3, #0
	ldrsh r1, [r1, r3]
	movs r3, #0
	ldrsh r2, [r2, r3]
	bl func_fe6_08053D5C
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #6
	bne .L08053D4E
	ldr r1, .L08053D58 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L08053D4E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08053D54: .4byte gUnk_085D2B8C
.L08053D58: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08053D5C
func_fe6_08053D5C: @ 0x08053D5C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r2
	ldr r1, .L08053DA4 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08053DA8 @ =gUnk_085D2BA4
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r3, .L08053DAC @ =gUnk_085EAC34
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	str r0, [r4, #0x60]
	strh r6, [r0, #2]
	mov r1, r8
	strh r1, [r0, #4]
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08053DA4: .4byte gEfxBgSemaphore
.L08053DA8: .4byte gUnk_085D2BA4
.L08053DAC: .4byte gUnk_085EAC34

	thumb_func_start func_fe6_08053DB0
func_fe6_08053DB0: @ 0x08053DB0
	push {lr}
	ldr r2, .L08053DC4 @ =gEfxBgSemaphore
	ldr r1, [r2]
	subs r1, #1
	str r1, [r2]
	ldr r0, [r0, #0x60]
	bl BasRemove
	pop {r0}
	bx r0
	.align 2, 0
.L08053DC4: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08053DC8
func_fe6_08053DC8: @ 0x08053DC8
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl func_fe6_08047300
	bl SpellFx_SetBG1Position
	ldr r0, .L08053E00 @ =gUnk_085D2BC4
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08053E00: .4byte gUnk_085D2BC4

	thumb_func_start func_fe6_08053E04
func_fe6_08053E04: @ 0x08053E04
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	ldr r0, [r6, #0x5c]
	bl GetAnimAnotherSide
	adds r5, r0, #0
	bl EfxGetCamMovDuration
	adds r4, r0, #0
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	movs r1, #0
	mov r8, r1
	movs r7, #0
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08053E3A
	ldr r0, [r6, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl NewEfxFarAttackWithDistance
.L08053E3A:
	movs r2, #0x2c
	ldrsh r1, [r6, r2]
	adds r0, r4, #1
	cmp r1, r0
	bne .L08053ED0
	adds r0, r5, #0
	movs r1, #0x64
	bl func_fe6_08053FF4
	adds r0, r5, #0
	movs r1, #0x64
	bl func_fe6_080540D0
	movs r4, #0x80
	lsls r4, r4, #1
	movs r0, #1
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0x64
	movs r2, #2
	adds r3, r4, #0
	bl func_fe6_0804C8D4
	ldr r2, .L08053EC8 @ =func_fe6_0804CD4C
	adds r0, r5, #0
	movs r1, #0x69
	bl func_fe6_0804CC68
	ldr r3, .L08053ECC @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	mov r2, r8
	strb r2, [r0]
	adds r0, #1
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	str r1, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0xf
	movs r3, #0
	bl func_fe6_0804CD88
	str r7, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x46
	movs r2, #0xf
	movs r3, #0x10
	bl func_fe6_0804CD88
	movs r0, #0x98
	lsls r0, r0, #1
	adds r1, r4, #0
	movs r2, #0x78
	movs r3, #0
	bl func_fe6_0805C804
	b .L08053FE8
	.align 2, 0
.L08053EC8: .4byte func_fe6_0804CD4C
.L08053ECC: .4byte gDispIo
.L08053ED0:
	adds r0, r4, #0
	adds r0, #0x28
	cmp r1, r0
	bne .L08053EE8
	adds r0, r5, #0
	movs r1, #0x4a
	bl func_fe6_08054168
	ldr r0, .L08053EE4 @ =0x00000131
	b .L08053F40
	.align 2, 0
.L08053EE4: .4byte 0x00000131
.L08053EE8:
	adds r0, r4, #0
	adds r0, #0x6e
	cmp r1, r0
	bne .L08053EF8
	adds r0, r5, #0
	bl func_fe6_080541FC
	b .L08053FE8
.L08053EF8:
	adds r0, r4, #0
	adds r0, #0x6f
	cmp r1, r0
	beq .L08053F3C
	adds r0, r4, #0
	adds r0, #0x8b
	cmp r1, r0
	beq .L08053F3C
	adds r0, r4, #0
	adds r0, #0xa7
	cmp r1, r0
	beq .L08053F3C
	adds r0, r4, #0
	adds r0, #0xc3
	cmp r1, r0
	beq .L08053F3C
	adds r0, r4, #0
	adds r0, #0xdf
	cmp r1, r0
	beq .L08053F3C
	adds r0, r4, #0
	adds r0, #0xfb
	cmp r1, r0
	beq .L08053F3C
	ldr r2, .L08053F50 @ =0x00000117
	adds r0, r4, r2
	cmp r1, r0
	beq .L08053F3C
	movs r0, #0x2c
	ldrsh r1, [r6, r0]
	ldr r7, .L08053F54 @ =0x00000133
	adds r0, r4, r7
	cmp r1, r0
	bne .L08053F58
.L08053F3C:
	movs r0, #0x99
	lsls r0, r0, #1
.L08053F40:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r3, #1
	bl func_fe6_0805C804
	b .L08053FE8
	.align 2, 0
.L08053F50: .4byte 0x00000117
.L08053F54: .4byte 0x00000133
.L08053F58:
	movs r2, #0xb3
	lsls r2, r2, #1
	adds r0, r4, r2
	cmp r1, r0
	bne .L08053FA2
	adds r0, r5, #0
	movs r1, #0xa
	bl NewEfxFlashBgWhite
	adds r0, r5, #0
	bl func_fe6_080543C4
	movs r0, #9
	ldrh r3, [r5, #0x10]
	orrs r0, r3
	strh r0, [r5, #0x10]
	adds r4, r6, #0
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl StartBattleAnimHitEffectsDefault
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #2
	ldrsh r2, [r5, r0]
	adds r0, r7, #0
	movs r3, #1
	bl func_fe6_0805C804
	ldrb r0, [r4]
	cmp r0, #0
	bne .L08053FE8
	adds r0, r5, #0
	bl func_fe6_0805C358
	b .L08053FE8
.L08053FA2:
	movs r2, #0xb8
	lsls r2, r2, #1
	adds r0, r4, r2
	cmp r1, r0
	bne .L08053FC6
	adds r0, r5, #0
	bl func_fe6_0805428C
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x12
	movs r2, #8
	movs r3, #0x10
	bl func_fe6_0804CD88
	b .L08053FE8
.L08053FC6:
	movs r3, #0xcd
	lsls r3, r3, #1
	adds r0, r4, r3
	cmp r1, r0
	beq .L08053FE8
	movs r2, #0xd2
	lsls r2, r2, #1
	adds r0, r4, r2
	cmp r1, r0
	bne .L08053FE8
	bl SpellFx_Finish
	bl func_fe6_08047358
	adds r0, r6, #0
	bl Proc_Break
.L08053FE8:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08053FF4
func_fe6_08053FF4: @ 0x08053FF4
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L08054068 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0805406C @ =gUnk_085D2BDC
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	ldr r0, .L08054070 @ =gUnk_0818EA98
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	bl SpellFx_ClearBG1
	ldr r0, .L08054074 @ =gUnk_0818F3D8
	ldr r4, .L08054078 @ =gEkrTsaBuffer
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L0805407C @ =gBg1Tm
	movs r0, #1
	str r0, [sp]
	adds r0, #0xff
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r2, #0x20
	movs r3, #0x20
	bl EfxTmCpyBG
	movs r0, #2
	bl EnableBgSync
	bl SpellFx_SetSomeColorEffect
	ldr r2, .L08054080 @ =gDispIo
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrb r1, [r2, #1]
	ands r0, r1
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r2, #1]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08054068: .4byte gEfxBgSemaphore
.L0805406C: .4byte gUnk_085D2BDC
.L08054070: .4byte gUnk_0818EA98
.L08054074: .4byte gUnk_0818F3D8
.L08054078: .4byte gEkrTsaBuffer
.L0805407C: .4byte gBg1Tm
.L08054080: .4byte gDispIo

	thumb_func_start func_fe6_08054084
func_fe6_08054084: @ 0x08054084
	push {lr}
	bl SpellFx_ClearBG1
	ldr r1, .L0805409C @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	pop {r0}
	bx r0
	.align 2, 0
.L0805409C: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_080540A0
func_fe6_080540A0: @ 0x080540A0
	push {lr}
	adds r2, r0, #0
	ldr r0, .L080540CC @ =gDispIo
	ldrh r1, [r0, #0x22]
	adds r1, #1
	strh r1, [r0, #0x22]
	ldrh r1, [r0, #0x20]
	subs r1, #1
	strh r1, [r0, #0x20]
	ldrh r0, [r2, #0x2c]
	adds r0, #1
	strh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	ldrh r3, [r2, #0x2e]
	lsls r1, r3, #0x10
	cmp r0, r1
	ble .L080540C8
	adds r0, r2, #0
	bl Proc_Break
.L080540C8:
	pop {r0}
	bx r0
	.align 2, 0
.L080540CC: .4byte gDispIo

	thumb_func_start func_fe6_080540D0
func_fe6_080540D0: @ 0x080540D0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L08054108 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0805410C @ =gUnk_085D2BFC
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	strh r5, [r0, #0x30]
	str r1, [r0, #0x44]
	ldr r1, .L08054110 @ =gUnk_0811A758
	str r1, [r0, #0x48]
	ldr r1, .L08054114 @ =gUnk_0818F1F8
	str r1, [r0, #0x4c]
	adds r0, r1, #0
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08054108: .4byte gEfxBgSemaphore
.L0805410C: .4byte gUnk_085D2BFC
.L08054110: .4byte gUnk_0811A758
.L08054114: .4byte gUnk_0818F1F8

	thumb_func_start func_fe6_08054118
func_fe6_08054118: @ 0x08054118
	ldr r1, .L08054124 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
.L08054124: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08054128
func_fe6_08054128: @ 0x08054128
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L0805414C
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
.L0805414C:
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x30]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08054162
	adds r0, r4, #0
	bl Proc_Break
.L08054162:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08054168
func_fe6_08054168: @ 0x08054168
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r1, .L080541B4 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080541B8 @ =gUnk_085D2C24
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	strh r6, [r4, #0x2e]
	ldr r3, .L080541BC @ =gUnk_085ED924
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	str r0, [r4, #0x60]
	ldr r0, .L080541C0 @ =gUnk_0819875C
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L080541C4 @ =gUnk_08197BE0
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080541B4: .4byte gEfxBgSemaphore
.L080541B8: .4byte gUnk_085D2C24
.L080541BC: .4byte gUnk_085ED924
.L080541C0: .4byte gUnk_0819875C
.L080541C4: .4byte gUnk_08197BE0

	thumb_func_start func_fe6_080541C8
func_fe6_080541C8: @ 0x080541C8
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L080541F0
	ldr r0, .L080541F8 @ =gEfxBgSemaphore
	ldr r1, [r0]
	subs r1, #1
	str r1, [r0]
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L080541F0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080541F8: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_080541FC
func_fe6_080541FC: @ 0x080541FC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L08054260 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08054264 @ =gUnk_085D2C3C
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L08054268 @ =gUnk_0811A796
	str r0, [r5, #0x48]
	ldr r0, .L0805426C @ =gUnk_085D2D20
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L08054270 @ =gUnk_085D2C54
	str r0, [r5, #0x54]
	ldr r0, .L08054274 @ =gUnk_08193598
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	bl SpellFx_SetSomeColorEffect
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	ldr r0, .L08054278 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08054286
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L0805427C
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L08054286
	.align 2, 0
.L08054260: .4byte gEfxBgSemaphore
.L08054264: .4byte gUnk_085D2C3C
.L08054268: .4byte gUnk_0811A796
.L0805426C: .4byte gUnk_085D2D20
.L08054270: .4byte gUnk_085D2C54
.L08054274: .4byte gUnk_08193598
.L08054278: .4byte gEkrDistanceType
.L0805427C:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L08054286:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805428C
func_fe6_0805428C: @ 0x0805428C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L080542E4 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080542E8 @ =gUnk_085D2C3C
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L080542EC @ =gUnk_08119F50
	str r0, [r5, #0x48]
	ldr r0, .L080542F0 @ =gUnk_085D1430
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L080542F4 @ =gUnk_085D13DC
	str r0, [r5, #0x54]
	ldr r0, .L080542F8 @ =gUnk_081935B8
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	bl SpellFx_SetSomeColorEffect
	ldr r0, .L080542FC @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L0805430A
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L08054300
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L0805430A
	.align 2, 0
.L080542E4: .4byte gEfxBgSemaphore
.L080542E8: .4byte gUnk_085D2C3C
.L080542EC: .4byte gUnk_08119F50
.L080542F0: .4byte gUnk_085D1430
.L080542F4: .4byte gUnk_085D13DC
.L080542F8: .4byte gUnk_081935B8
.L080542FC: .4byte gEkrDistanceType
.L08054300:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L0805430A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08054310
func_fe6_08054310: @ 0x08054310
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	adds r0, #0x2c
	adds r1, r7, #0
	adds r1, #0x44
	ldr r2, [r7, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	blt .L08054398
	ldr r5, [r7, #0x4c]
	ldr r6, [r7, #0x50]
	ldr r0, [r7, #0x54]
	lsls r4, r4, #2
	adds r0, r4, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	ldr r0, [r7, #0x5c]
	adds r5, r4, r5
	ldr r1, [r5]
	adds r4, r4, r6
	ldr r2, [r4]
	bl SpellFx_WriteBgMap
	ldr r0, .L08054374 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L080543B6
	ldr r0, [r7, #0x5c]
	bl GetAnimPosition
	adds r1, r0, #0
	cmp r1, #0
	bne .L0805437C
	ldr r0, .L08054378 @ =gBg1Tm
	str r1, [sp]
	movs r1, #3
	movs r2, #0x14
	movs r3, #0
	bl FillBGRect
	b .L0805438C
	.align 2, 0
.L08054374: .4byte gEkrDistanceType
.L08054378: .4byte gBg1Tm
.L0805437C:
	ldr r0, .L08054394 @ =gBg1Tm+0x3A
	movs r1, #0
	str r1, [sp]
	movs r1, #3
	movs r2, #0x14
	movs r3, #0
	bl FillBGRect
.L0805438C:
	movs r0, #2
	bl EnableBgSync
	b .L080543B6
	.align 2, 0
.L08054394: .4byte gBg1Tm+0x3A
.L08054398:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	bne .L080543B6
	bl SpellFx_ClearBG1
	ldr r1, .L080543C0 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	adds r0, r7, #0
	bl Proc_Break
.L080543B6:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080543C0: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_080543C4
func_fe6_080543C4: @ 0x080543C4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L080543FC @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08054400 @ =gUnk_085D2DEC
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	str r1, [r0, #0x44]
	ldr r0, .L08054404 @ =gUnk_0819877C
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L08054408 @ =gUnk_08197BE0
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080543FC: .4byte gEfxBgSemaphore
.L08054400: .4byte gUnk_085D2DEC
.L08054404: .4byte gUnk_0819877C
.L08054408: .4byte gUnk_08197BE0

	thumb_func_start func_fe6_0805440C
func_fe6_0805440C: @ 0x0805440C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bne .L0805444C
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r0, [r4, #0x5c]
	ldr r2, [r4, #0x44]
	adds r1, r2, #0
	adds r2, #1
	str r2, [r4, #0x44]
	bl func_fe6_08054458
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #8
	bne .L0805444C
	ldr r1, .L08054454 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0805444C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08054454: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08054458
func_fe6_08054458: @ 0x08054458
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r1, .L08054498 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0805449C @ =gUnk_085D2E04
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r6, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	movs r0, #0x1e
	strh r0, [r5, #0x2e]
	ldr r1, .L080544A0 @ =gUnk_085D2E1C
	movs r0, #7
	ands r0, r4
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r5, #0x44]
	movs r1, #0
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	beq .L080544A4
	cmp r0, #1
	beq .L080544AC
	b .L080544B8
	.align 2, 0
.L08054498: .4byte gEfxBgSemaphore
.L0805449C: .4byte gUnk_085D2E04
.L080544A0: .4byte gUnk_085D2E1C
.L080544A4:
	ldr r0, .L080544A8 @ =gUnk_085ED8CC
	b .L080544AE
	.align 2, 0
.L080544A8: .4byte gUnk_085ED8CC
.L080544AC:
	ldr r0, .L080544D4 @ =gUnk_085ED8F8
.L080544AE:
	movs r1, #0x78
	bl BasCreate
	adds r1, r0, #0
	str r1, [r5, #0x60]
.L080544B8:
	movs r0, #0xa1
	lsls r0, r0, #6
	strh r0, [r1, #8]
	ldrh r0, [r6, #2]
	strh r0, [r1, #2]
	ldrh r0, [r6, #2]
	strh r0, [r5, #0x32]
	ldrh r0, [r6, #4]
	strh r0, [r1, #4]
	ldrh r0, [r6, #4]
	strh r0, [r5, #0x3a]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080544D4: .4byte gUnk_085ED8F8

	thumb_func_start func_fe6_080544D8
func_fe6_080544D8: @ 0x080544D8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r5, [r6, #0x60]
	movs r2, #0x96
	lsls r2, r2, #1
	movs r0, #0x2c
	ldrsh r3, [r6, r0]
	movs r1, #0x2e
	ldrsh r0, [r6, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	bl Interpolate
	ldr r4, .L08054550 @ =gSinLut
	ldr r2, [r6, #0x44]
	lsls r1, r2, #1
	adds r1, r1, r4
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r3, r0, #0
	muls r3, r1, r3
	adds r2, #0x40
	lsls r2, r2, #1
	adds r2, r2, r4
	movs r4, #0
	ldrsh r1, [r2, r4]
	muls r0, r1, r0
	asrs r3, r3, #0xc
	ldrh r1, [r6, #0x32]
	adds r3, r1, r3
	strh r3, [r5, #2]
	asrs r0, r0, #0xc
	ldrh r2, [r6, #0x3a]
	adds r0, r2, r0
	strh r0, [r5, #4]
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	ldrh r3, [r6, #0x2e]
	lsls r1, r3, #0x10
	cmp r0, r1
	ble .L08054546
	ldr r0, .L08054554 @ =gEfxBgSemaphore
	ldr r1, [r0]
	subs r1, #1
	str r1, [r0]
	ldr r0, [r6, #0x60]
	bl BasRemove
	adds r0, r6, #0
	bl Proc_Break
.L08054546:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08054550: .4byte gSinLut
.L08054554: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08054558
func_fe6_08054558: @ 0x08054558
	push {r4, lr}
	adds r4, r0, #0
	bl SpellFx_Begin
	bl func_fe6_08047300
	bl SpellFx_SetBG1Position
	ldr r0, .L0805457C @ =gUnk_085D2E3C
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805457C: .4byte gUnk_085D2E3C

	thumb_func_start func_fe6_08054580
func_fe6_08054580: @ 0x08054580
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	adds r5, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r6, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L080545B0
	ldr r0, [r4, #0x5c]
	bl func_fe6_08054F8C
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xf3
	b .L0805465C
.L080545B0:
	cmp r0, #0x34
	bne .L08054618
	ldr r0, [r4, #0x5c]
	movs r1, #0
	bl func_fe6_08054B98
	ldr r0, [r4, #0x5c]
	movs r1, #0
	bl func_fe6_08054D78
	ldr r3, .L08054614 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	strb r6, [r0]
	adds r1, r3, #0
	adds r1, #0x45
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x46
	strb r6, [r0]
	ldr r0, [r4, #0x5c]
	movs r1, #1
	movs r2, #0xc
	movs r3, #0
	bl func_fe6_08054EA0
	ldr r0, [r4, #0x5c]
	movs r1, #0x23
	movs r2, #0x19
	movs r3, #1
	bl func_fe6_08054EA0
	movs r0, #0x87
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	b .L0805465C
	.align 2, 0
.L08054614: .4byte gDispIo
.L08054618:
	cmp r0, #0x37
	bne .L08054626
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	b .L080546A0
.L08054626:
	cmp r0, #0x71
	bne .L08054668
	ldr r0, [r4, #0x5c]
	movs r1, #0
	bl func_fe6_08054C54
	ldr r0, [r4, #0x5c]
	movs r1, #0
	bl func_fe6_08054DE8
	ldr r0, [r4, #0x5c]
	movs r1, #1
	movs r2, #0xc
	movs r3, #0
	bl func_fe6_08054EA0
	ldr r0, [r4, #0x5c]
	movs r1, #0x1d
	movs r2, #0x19
	movs r3, #1
	bl func_fe6_08054EA0
	ldr r0, .L08054664 @ =0x0000010F
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
.L0805465C:
	movs r3, #1
	bl func_fe6_0805C804
	b .L080546A0
	.align 2, 0
.L08054664: .4byte 0x0000010F
.L08054668:
	cmp r0, #0xa6
	bne .L08054674
	adds r0, r5, #0
	bl NewEfxHpBarLive
	b .L080546A0
.L08054674:
	cmp r0, #0xb5
	bne .L080546A0
	bl SpellFx_Finish
	bl func_fe6_08047358
	adds r0, r5, #0
	bl GetAnimNextRoundType
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq .L0805469A
	movs r0, #2
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
.L0805469A:
	adds r0, r4, #0
	bl Proc_Break
.L080546A0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080546A8
func_fe6_080546A8: @ 0x080546A8
	push {r4, lr}
	adds r4, r0, #0
	bl SpellFx_Begin
	bl func_fe6_08047300
	bl SpellFx_SetBG1Position
	ldr r0, .L080546CC @ =gUnk_085D2E54
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080546CC: .4byte gUnk_085D2E54

	thumb_func_start func_fe6_080546D0
func_fe6_080546D0: @ 0x080546D0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	adds r5, r0, #0
	bl EfxGetCamMovDuration
	adds r2, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r6, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08054706
	ldr r0, [r4, #0x5c]
	bl func_fe6_08054F8C
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xf3
	b .L080547EE
.L08054706:
	cmp r0, #0x34
	bne .L0805476C
	ldr r0, [r4, #0x5c]
	movs r1, #1
	bl func_fe6_08054B98
	ldr r0, [r4, #0x5c]
	movs r1, #1
	bl func_fe6_08054D78
	ldr r3, .L08054768 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	strb r6, [r0]
	adds r1, r3, #0
	adds r1, #0x45
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x46
	strb r6, [r0]
	ldr r0, [r4, #0x5c]
	movs r1, #1
	movs r2, #0xc
	movs r3, #0
	bl func_fe6_08054EA0
	ldr r0, [r4, #0x5c]
	movs r1, #0x23
	movs r2, #0x19
	movs r3, #1
	bl func_fe6_08054EA0
	movs r0, #0x88
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	b .L080547EE
	.align 2, 0
.L08054768: .4byte gDispIo
.L0805476C:
	cmp r0, #0x37
	bne .L0805477A
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	b .L08054840
.L0805477A:
	cmp r0, #0x71
	bne .L0805478A
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl NewEfxFarAttackWithDistance
	b .L08054840
.L0805478A:
	movs r3, #0x2c
	ldrsh r1, [r4, r3]
	adds r0, r2, #0
	adds r0, #0x72
	cmp r1, r0
	bne .L08054800
	ldr r0, [r4, #0x5c]
	movs r1, #1
	bl func_fe6_08054C54
	ldr r0, [r4, #0x5c]
	movs r1, #1
	bl func_fe6_08054DE8
	ldr r3, .L080547F8 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	strb r6, [r0]
	adds r1, r3, #0
	adds r1, #0x45
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x46
	strb r6, [r0]
	ldr r0, [r4, #0x5c]
	movs r1, #1
	movs r2, #0xc
	movs r3, #0
	bl func_fe6_08054EA0
	ldr r0, [r4, #0x5c]
	movs r1, #0x1d
	movs r2, #0x19
	movs r3, #1
	bl func_fe6_08054EA0
	ldr r0, .L080547FC @ =0x00000111
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
.L080547EE:
	movs r3, #1
	bl func_fe6_0805C804
	b .L08054840
	.align 2, 0
.L080547F8: .4byte gDispIo
.L080547FC: .4byte 0x00000111
.L08054800:
	adds r0, r2, #0
	adds r0, #0xa6
	cmp r1, r0
	bne .L08054810
	adds r0, r5, #0
	bl NewEfxHpBarLive
	b .L08054840
.L08054810:
	adds r0, r2, #0
	adds r0, #0xb5
	cmp r1, r0
	bne .L08054840
	bl SpellFx_Finish
	bl func_fe6_08047358
	adds r0, r5, #0
	bl GetAnimNextRoundType
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq .L0805483A
	movs r0, #2
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
.L0805483A:
	adds r0, r4, #0
	bl Proc_Break
.L08054840:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08054848
func_fe6_08054848: @ 0x08054848
	push {r4, lr}
	adds r4, r0, #0
	bl SpellFx_Begin
	bl func_fe6_08047300
	bl SpellFx_SetBG1Position
	ldr r0, .L0805486C @ =gUnk_085D2E6C
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805486C: .4byte gUnk_085D2E6C

	thumb_func_start func_fe6_08054870
func_fe6_08054870: @ 0x08054870
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	adds r5, r0, #0
	bl EfxGetCamMovDuration
	adds r2, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r6, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L080548A6
	ldr r0, [r4, #0x5c]
	bl func_fe6_08054F8C
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xf3
	b .L0805498E
.L080548A6:
	cmp r0, #0x34
	bne .L0805490C
	ldr r0, [r4, #0x5c]
	movs r1, #2
	bl func_fe6_08054B98
	ldr r0, [r4, #0x5c]
	movs r1, #2
	bl func_fe6_08054D78
	ldr r3, .L08054908 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	strb r6, [r0]
	adds r1, r3, #0
	adds r1, #0x45
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x46
	strb r6, [r0]
	ldr r0, [r4, #0x5c]
	movs r1, #1
	movs r2, #0xc
	movs r3, #0
	bl func_fe6_08054EA0
	ldr r0, [r4, #0x5c]
	movs r1, #0x23
	movs r2, #0x19
	movs r3, #1
	bl func_fe6_08054EA0
	movs r0, #0x89
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	b .L0805498E
	.align 2, 0
.L08054908: .4byte gDispIo
.L0805490C:
	cmp r0, #0x37
	bne .L0805491A
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	b .L080549E0
.L0805491A:
	cmp r0, #0x71
	bne .L0805492A
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl NewEfxFarAttackWithDistance
	b .L080549E0
.L0805492A:
	movs r3, #0x2c
	ldrsh r1, [r4, r3]
	adds r0, r2, #0
	adds r0, #0x72
	cmp r1, r0
	bne .L080549A0
	ldr r0, [r4, #0x5c]
	movs r1, #2
	bl func_fe6_08054C54
	ldr r0, [r4, #0x5c]
	movs r1, #2
	bl func_fe6_08054DE8
	ldr r3, .L08054998 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	strb r6, [r0]
	adds r1, r3, #0
	adds r1, #0x45
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x46
	strb r6, [r0]
	ldr r0, [r4, #0x5c]
	movs r1, #1
	movs r2, #0xc
	movs r3, #0
	bl func_fe6_08054EA0
	ldr r0, [r4, #0x5c]
	movs r1, #0x1d
	movs r2, #0x19
	movs r3, #1
	bl func_fe6_08054EA0
	ldr r0, .L0805499C @ =0x00000113
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
.L0805498E:
	movs r3, #1
	bl func_fe6_0805C804
	b .L080549E0
	.align 2, 0
.L08054998: .4byte gDispIo
.L0805499C: .4byte 0x00000113
.L080549A0:
	adds r0, r2, #0
	adds r0, #0xa6
	cmp r1, r0
	bne .L080549B0
	adds r0, r5, #0
	bl NewEfxHpBarLive
	b .L080549E0
.L080549B0:
	adds r0, r2, #0
	adds r0, #0xb5
	cmp r1, r0
	bne .L080549E0
	bl SpellFx_Finish
	bl func_fe6_08047358
	adds r0, r5, #0
	bl GetAnimNextRoundType
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq .L080549DA
	movs r0, #2
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
.L080549DA:
	adds r0, r4, #0
	bl Proc_Break
.L080549E0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080549E8
func_fe6_080549E8: @ 0x080549E8
	push {r4, lr}
	adds r4, r0, #0
	bl SpellFx_Begin
	bl func_fe6_08047300
	bl SpellFx_SetBG1Position
	ldr r0, .L08054A0C @ =gUnk_085D2E84
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08054A0C: .4byte gUnk_085D2E84

	thumb_func_start func_fe6_08054A10
func_fe6_08054A10: @ 0x08054A10
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	adds r5, r0, #0
	bl EfxGetCamMovDuration
	adds r2, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r6, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08054A4E
	ldr r0, [r4, #0x5c]
	bl func_fe6_08054F8C
	ldr r0, [r4, #0x5c]
	movs r1, #0
	bl func_fe6_080550EC
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xf3
	b .L08054B3E
.L08054A4E:
	cmp r0, #0x34
	bne .L08054AB4
	ldr r0, [r4, #0x5c]
	movs r1, #0
	bl func_fe6_08054B98
	ldr r0, [r4, #0x5c]
	movs r1, #0
	bl func_fe6_08054D78
	ldr r3, .L08054AB0 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	strb r6, [r0]
	adds r1, r3, #0
	adds r1, #0x45
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x46
	strb r6, [r0]
	ldr r0, [r4, #0x5c]
	movs r1, #1
	movs r2, #0xc
	movs r3, #0
	bl func_fe6_08054EA0
	ldr r0, [r4, #0x5c]
	movs r1, #0x23
	movs r2, #0x19
	movs r3, #1
	bl func_fe6_08054EA0
	movs r0, #0x87
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	b .L08054B3E
	.align 2, 0
.L08054AB0: .4byte gDispIo
.L08054AB4:
	cmp r0, #0x37
	bne .L08054AC2
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	b .L08054B90
.L08054AC2:
	cmp r0, #0x97
	bne .L08054ADA
	ldr r0, [r4, #0x5c]
	movs r1, #1
	bl func_fe6_080550EC
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl NewEfxFarAttackWithDistance
	b .L08054B90
.L08054ADA:
	movs r3, #0x2c
	ldrsh r1, [r4, r3]
	adds r0, r2, #0
	adds r0, #0xa1
	cmp r1, r0
	bne .L08054B50
	ldr r0, [r4, #0x5c]
	movs r1, #0
	bl func_fe6_08054C54
	ldr r0, [r4, #0x5c]
	movs r1, #0
	bl func_fe6_08054DE8
	ldr r3, .L08054B48 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	strb r6, [r0]
	adds r1, r3, #0
	adds r1, #0x45
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x46
	strb r6, [r0]
	ldr r0, [r4, #0x5c]
	movs r1, #1
	movs r2, #0xc
	movs r3, #0
	bl func_fe6_08054EA0
	ldr r0, [r4, #0x5c]
	movs r1, #0x1d
	movs r2, #0x19
	movs r3, #1
	bl func_fe6_08054EA0
	ldr r0, .L08054B4C @ =0x0000010F
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
.L08054B3E:
	movs r3, #1
	bl func_fe6_0805C804
	b .L08054B90
	.align 2, 0
.L08054B48: .4byte gDispIo
.L08054B4C: .4byte 0x0000010F
.L08054B50:
	adds r0, r2, #0
	adds r0, #0xd3
	cmp r1, r0
	bne .L08054B60
	adds r0, r5, #0
	bl NewEfxHpBarLive
	b .L08054B90
.L08054B60:
	adds r0, r2, #0
	adds r0, #0xdd
	cmp r1, r0
	bne .L08054B90
	bl SpellFx_Finish
	bl func_fe6_08047358
	adds r0, r5, #0
	bl GetAnimNextRoundType
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq .L08054B8A
	movs r0, #2
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
.L08054B8A:
	adds r0, r4, #0
	bl Proc_Break
.L08054B90:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08054B98
func_fe6_08054B98: @ 0x08054B98
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r1, .L08054BE0 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08054BE4 @ =gUnk_085D2E9C
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	cmp r6, #0
	beq .L08054BF8
	cmp r6, #2
	bhi .L08054C4A
	adds r1, r5, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	ldr r0, .L08054BE8 @ =gUnk_0811A8A4
	str r0, [r5, #0x48]
	ldr r0, .L08054BEC @ =gUnk_081AC90C
	str r0, [r5, #0x4c]
	ldr r0, .L08054BF0 @ =gUnk_081AD26C
	str r0, [r5, #0x50]
	ldr r0, .L08054BF4 @ =gUnk_081AC114
	movs r1, #0xa8
	lsls r1, r1, #5
	bl SpellFx_RegisterBgGfx
	b .L08054C4A
	.align 2, 0
.L08054BE0: .4byte gEfxBgSemaphore
.L08054BE4: .4byte gUnk_085D2E9C
.L08054BE8: .4byte gUnk_0811A8A4
.L08054BEC: .4byte gUnk_081AC90C
.L08054BF0: .4byte gUnk_081AD26C
.L08054BF4: .4byte gUnk_081AC114
.L08054BF8:
	adds r1, r5, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	ldr r0, .L08054C30 @ =gUnk_0811A898
	str r0, [r5, #0x48]
	ldr r0, .L08054C34 @ =gUnk_081AB340
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L08054C38 @ =gUnk_081AB1B0
	movs r1, #0x80
	lsls r1, r1, #3
	bl SpellFx_RegisterBgGfx
	ldr r0, .L08054C3C @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08054C4A
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L08054C40
	movs r0, #1
	movs r1, #0x18
	b .L08054C44
	.align 2, 0
.L08054C30: .4byte gUnk_0811A898
.L08054C34: .4byte gUnk_081AB340
.L08054C38: .4byte gUnk_081AB1B0
.L08054C3C: .4byte gEkrDistanceType
.L08054C40:
	movs r0, #1
	movs r1, #0xe8
.L08054C44:
	movs r2, #0
	bl SetBgOffset
.L08054C4A:
	bl SpellFx_SetSomeColorEffect
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08054C54
func_fe6_08054C54: @ 0x08054C54
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r1, .L08054C9C @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08054CA0 @ =gUnk_085D2E9C
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r1, #0
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	adds r0, r5, #0
	adds r0, #0x29
	strb r1, [r0]
	cmp r6, #0
	beq .L08054CB4
	cmp r6, #2
	bhi .L08054CFE
	ldr r0, .L08054CA4 @ =gUnk_0811A8AA
	str r0, [r5, #0x48]
	ldr r0, .L08054CA8 @ =gUnk_081AC90C
	str r0, [r5, #0x4c]
	ldr r0, .L08054CAC @ =gUnk_081AD26C
	str r0, [r5, #0x50]
	ldr r0, .L08054CB0 @ =gUnk_081AC114
	movs r1, #0xa8
	lsls r1, r1, #5
	bl SpellFx_RegisterBgGfx
	b .L08054CFE
	.align 2, 0
.L08054C9C: .4byte gEfxBgSemaphore
.L08054CA0: .4byte gUnk_085D2E9C
.L08054CA4: .4byte gUnk_0811A8AA
.L08054CA8: .4byte gUnk_081AC90C
.L08054CAC: .4byte gUnk_081AD26C
.L08054CB0: .4byte gUnk_081AC114
.L08054CB4:
	ldr r0, .L08054CE4 @ =gUnk_0811A89E
	str r0, [r5, #0x48]
	ldr r0, .L08054CE8 @ =gUnk_081AB340
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L08054CEC @ =gUnk_081AB1B0
	movs r1, #0x80
	lsls r1, r1, #3
	bl SpellFx_RegisterBgGfx
	ldr r0, .L08054CF0 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08054CFE
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L08054CF4
	movs r0, #1
	movs r1, #0xe8
	b .L08054CF8
	.align 2, 0
.L08054CE4: .4byte gUnk_0811A89E
.L08054CE8: .4byte gUnk_081AB340
.L08054CEC: .4byte gUnk_081AB1B0
.L08054CF0: .4byte gEkrDistanceType
.L08054CF4:
	movs r0, #1
	movs r1, #0x18
.L08054CF8:
	movs r2, #0
	bl SetBgOffset
.L08054CFE:
	bl SpellFx_SetSomeColorEffect
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08054D08
func_fe6_08054D08: @ 0x08054D08
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	cmp r3, #0
	blt .L08054D3A
	ldr r1, [r4, #0x4c]
	ldr r2, [r4, #0x50]
	ldr r0, [r4, #0x5c]
	lsls r4, r3, #2
	adds r4, r4, r3
	lsls r3, r4, #4
	subs r3, r3, r4
	lsls r3, r3, #4
	adds r1, r1, r3
	adds r2, r2, r3
	bl EfxCreateBackAnim
	b .L08054D6C
.L08054D3A:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r3, r0
	bne .L08054D6C
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08054D54
	bl SpellFx_ClearBG1
	bl SpellFx_ClearColorEffects
.L08054D54:
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	ldr r1, .L08054D74 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L08054D6C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08054D74: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08054D78
func_fe6_08054D78: @ 0x08054D78
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L08054DA0 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08054DA4 @ =gUnk_085D2EB4
	movs r1, #3
	bl SpawnProc
	adds r1, r0, #0
	str r4, [r1, #0x5c]
	movs r0, #0
	strh r0, [r1, #0x2c]
	str r0, [r1, #0x44]
	cmp r5, #0
	bne .L08054DAC
	ldr r0, .L08054DA8 @ =gUnk_0811A8B0
	b .L08054DBA
	.align 2, 0
.L08054DA0: .4byte gEfxBgSemaphore
.L08054DA4: .4byte gUnk_085D2EB4
.L08054DA8: .4byte gUnk_0811A8B0
.L08054DAC:
	cmp r5, #1
	bne .L08054DB8
	ldr r0, .L08054DB4 @ =gUnk_0811A934
	b .L08054DBA
	.align 2, 0
.L08054DB4: .4byte gUnk_0811A934
.L08054DB8:
	ldr r0, .L08054DC4 @ =gUnk_0811A966
.L08054DBA:
	str r0, [r1, #0x48]
	cmp r5, #0
	bne .L08054DCC
	ldr r0, .L08054DC8 @ =gUnk_081ABCA0
	b .L08054DDA
	.align 2, 0
.L08054DC4: .4byte gUnk_0811A966
.L08054DC8: .4byte gUnk_081ABCA0
.L08054DCC:
	cmp r5, #1
	bne .L08054DD8
	ldr r0, .L08054DD4 @ =gUnk_081ADDEC
	b .L08054DDA
	.align 2, 0
.L08054DD4: .4byte gUnk_081ADDEC
.L08054DD8:
	ldr r0, .L08054DE4 @ =gUnk_081ADBCC
.L08054DDA:
	str r0, [r1, #0x4c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08054DE4: .4byte gUnk_081ADBCC

	thumb_func_start func_fe6_08054DE8
func_fe6_08054DE8: @ 0x08054DE8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L08054E10 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08054E14 @ =gUnk_085D2EB4
	movs r1, #3
	bl SpawnProc
	adds r1, r0, #0
	str r4, [r1, #0x5c]
	movs r0, #0
	strh r0, [r1, #0x2c]
	str r0, [r1, #0x44]
	cmp r5, #0
	bne .L08054E1C
	ldr r0, .L08054E18 @ =gUnk_0811A8F2
	b .L08054E2A
	.align 2, 0
.L08054E10: .4byte gEfxBgSemaphore
.L08054E14: .4byte gUnk_085D2EB4
.L08054E18: .4byte gUnk_0811A8F2
.L08054E1C:
	cmp r5, #1
	bne .L08054E28
	ldr r0, .L08054E24 @ =gUnk_0811A934
	b .L08054E2A
	.align 2, 0
.L08054E24: .4byte gUnk_0811A934
.L08054E28:
	ldr r0, .L08054E34 @ =gUnk_0811A966
.L08054E2A:
	str r0, [r1, #0x48]
	cmp r5, #0
	bne .L08054E3C
	ldr r0, .L08054E38 @ =gUnk_081ABCA0
	b .L08054E4A
	.align 2, 0
.L08054E34: .4byte gUnk_0811A966
.L08054E38: .4byte gUnk_081ABCA0
.L08054E3C:
	cmp r5, #1
	bne .L08054E48
	ldr r0, .L08054E44 @ =gUnk_081ADDEC
	b .L08054E4A
	.align 2, 0
.L08054E44: .4byte gUnk_081ADDEC
.L08054E48:
	ldr r0, .L08054E54 @ =gUnk_081ADBCC
.L08054E4A:
	str r0, [r1, #0x4c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08054E54: .4byte gUnk_081ADBCC

	thumb_func_start func_fe6_08054E58
func_fe6_08054E58: @ 0x08054E58
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L08054E7E
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	b .L08054E94
.L08054E7E:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L08054E94
	ldr r1, .L08054E9C @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L08054E94:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08054E9C: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08054EA0
func_fe6_08054EA0: @ 0x08054EA0
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	mov r8, r3
	ldr r1, .L08054ED4 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08054ED8 @ =gUnk_085D2ED4
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	strh r5, [r0, #0x2c]
	strh r6, [r0, #0x2e]
	adds r0, #0x29
	mov r1, r8
	strb r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08054ED4: .4byte gEfxBgSemaphore
.L08054ED8: .4byte gUnk_085D2ED4

	thumb_func_start func_fe6_08054EDC
func_fe6_08054EDC: @ 0x08054EDC
	push {lr}
	adds r1, r0, #0
	ldrh r0, [r1, #0x2c]
	subs r0, #1
	strh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L08054EF2
	adds r0, r1, #0
	bl Proc_Break
.L08054EF2:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08054EF8
func_fe6_08054EF8: @ 0x08054EF8
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	cmp r1, r0
	ble .L08054F20
	ldr r1, .L08054F1C @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
	b .L08054F7E
	.align 2, 0
.L08054F1C: .4byte gEfxBgSemaphore
.L08054F20:
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08054F3C
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0x10
	b .L08054F4C
.L08054F3C:
	movs r2, #0x2c
	ldrsh r3, [r4, r2]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0
.L08054F4C:
	bl Interpolate
	adds r5, r0, #0
	ldr r3, .L08054F88 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	movs r1, #0
	strb r5, [r0]
	adds r2, #9
	movs r0, #0x10
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x46
	strb r1, [r0]
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
.L08054F7E:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08054F88: .4byte gDispIo

	thumb_func_start func_fe6_08054F8C
func_fe6_08054F8C: @ 0x08054F8C
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L08054FD8 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08054FDC @ =gUnk_085D2EF4
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x33
	strh r0, [r4, #0x2e]
	ldr r3, .L08054FE0 @ =gUnk_085F0A14
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	str r0, [r4, #0x60]
	ldr r0, .L08054FE4 @ =gUnk_081AC0F4
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L08054FE8 @ =gUnk_081ABEA0
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08054FD8: .4byte gEfxBgSemaphore
.L08054FDC: .4byte gUnk_085D2EF4
.L08054FE0: .4byte gUnk_085F0A14
.L08054FE4: .4byte gUnk_081AC0F4
.L08054FE8: .4byte gUnk_081ABEA0

	thumb_func_start func_fe6_08054FEC
func_fe6_08054FEC: @ 0x08054FEC
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L0805503C @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08055040 @ =gUnk_085D2F0C
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x33
	strh r0, [r4, #0x2e]
	movs r0, #0x34
	strh r0, [r4, #0x30]
	ldr r3, .L08055044 @ =gUnk_085F0A14
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	str r0, [r4, #0x60]
	ldr r0, .L08055048 @ =gUnk_081AC0F4
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0805504C @ =gUnk_081ABEA0
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805503C: .4byte gEfxBgSemaphore
.L08055040: .4byte gUnk_085D2F0C
.L08055044: .4byte gUnk_085F0A14
.L08055048: .4byte gUnk_081AC0F4
.L0805504C: .4byte gUnk_081ABEA0

	thumb_func_start func_fe6_08055050
func_fe6_08055050: @ 0x08055050
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L08055078
	ldr r0, .L08055080 @ =gEfxBgSemaphore
	ldr r1, [r0]
	subs r1, #1
	str r1, [r0]
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L08055078:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08055080: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08055084
func_fe6_08055084: @ 0x08055084
	push {r4, r5, lr}
	adds r2, r0, #0
	ldr r3, [r2, #0x60]
	ldrh r0, [r2, #0x2c]
	adds r0, #1
	movs r4, #0
	strh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	ldrh r5, [r2, #0x2e]
	lsls r1, r5, #0x10
	cmp r0, r1
	bne .L080550AC
	ldr r0, .L080550B4 @ =gUnk_085F0AA4
	str r0, [r3, #0x24]
	str r0, [r3, #0x20]
	strh r4, [r3, #6]
	strh r4, [r2, #0x2c]
	adds r0, r2, #0
	bl Proc_Break
.L080550AC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080550B4: .4byte gUnk_085F0AA4

	thumb_func_start func_fe6_080550B8
func_fe6_080550B8: @ 0x080550B8
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x30]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L080550E0
	ldr r0, .L080550E8 @ =gEfxBgSemaphore
	ldr r1, [r0]
	subs r1, #1
	str r1, [r0]
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L080550E0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080550E8: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_080550EC
func_fe6_080550EC: @ 0x080550EC
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r1, .L0805511C @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08055120 @ =gUnk_085D2F2C
	movs r1, #3
	bl SpawnProc
	adds r1, r0, #0
	str r5, [r1, #0x5c]
	movs r0, #0
	strh r0, [r1, #0x2c]
	adds r0, r1, #0
	adds r0, #0x29
	strb r4, [r0]
	cmp r4, #0
	bne .L08055124
	movs r0, #0x2b
	strh r0, [r1, #0x2e]
	movs r0, #0x44
	b .L0805512A
	.align 2, 0
.L0805511C: .4byte gEfxBgSemaphore
.L08055120: .4byte gUnk_085D2F2C
.L08055124:
	movs r0, #0x1f
	strh r0, [r1, #0x2e]
	movs r0, #0x3d
.L0805512A:
	strh r0, [r1, #0x30]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08055134
func_fe6_08055134: @ 0x08055134
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L080551F2
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0805519A
	ldr r0, .L0805517C @ =gUnk_085F1FC0
	mov r8, r0
	ldr r7, .L08055180 @ =gUnk_085F35C0
	ldr r0, .L08055184 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08055188
	ldr r0, [r4, #0x5c]
	bl GetAnimPosition
	movs r5, #0x88
	cmp r0, #0
	bne .L08055196
	movs r5, #0x68
	b .L08055196
	.align 2, 0
.L0805517C: .4byte gUnk_085F1FC0
.L08055180: .4byte gUnk_085F35C0
.L08055184: .4byte gEkrDistanceType
.L08055188:
	ldr r0, [r4, #0x5c]
	bl GetAnimPosition
	movs r5, #0x70
	cmp r0, #0
	bne .L08055196
	movs r5, #0x80
.L08055196:
	movs r6, #0x4e
	b .L080551D8
.L0805519A:
	ldr r2, .L080551BC @ =gUnk_085F2034
	mov r8, r2
	ldr r7, .L080551C0 @ =gUnk_085F3634
	ldr r0, .L080551C4 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L080551C8
	ldr r0, [r4, #0x5c]
	bl GetAnimPosition
	movs r5, #0x4c
	cmp r0, #0
	bne .L080551D6
	movs r5, #0xa4
	b .L080551D6
	.align 2, 0
.L080551BC: .4byte gUnk_085F2034
.L080551C0: .4byte gUnk_085F3634
.L080551C4: .4byte gEkrDistanceType
.L080551C8:
	ldr r0, [r4, #0x5c]
	bl GetAnimPosition
	movs r5, #0x64
	cmp r0, #0
	bne .L080551D6
	movs r5, #0x8c
.L080551D6:
	movs r6, #0x40
.L080551D8:
	ldr r0, [r4, #0x5c]
	mov r2, r8
	str r2, [sp]
	adds r1, r7, #0
	adds r3, r7, #0
	bl EfxCreateFrontAnim
	str r0, [r4, #0x60]
	strh r5, [r0, #2]
	strh r6, [r0, #4]
	adds r0, r4, #0
	bl Proc_Break
.L080551F2:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08055200
func_fe6_08055200: @ 0x08055200
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x30]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L08055228
	ldr r0, .L08055230 @ =gEfxBgSemaphore
	ldr r1, [r0]
	subs r1, #1
	str r1, [r0]
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L08055228:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08055230: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08055234
func_fe6_08055234: @ 0x08055234
	push {r4, lr}
	adds r4, r0, #0
	bl SpellFx_Begin
	bl func_fe6_08047300
	bl SpellFx_SetBG1Position
	ldr r0, .L08055260 @ =gUnk_085D2F4C
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r2, #0
	movs r1, #0
	strh r1, [r0, #0x2c]
	adds r0, #0x29
	strb r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08055260: .4byte gUnk_085D2F4C

	thumb_func_start func_fe6_08055264
func_fe6_08055264: @ 0x08055264
	push {r4, lr}
	adds r4, r0, #0
	bl SpellFx_Begin
	bl func_fe6_08047300
	bl SpellFx_SetBG1Position
	ldr r0, .L08055290 @ =gUnk_085D2F4C
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	adds r0, #0x29
	movs r1, #1
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08055290: .4byte gUnk_085D2F4C

	thumb_func_start func_fe6_08055294
func_fe6_08055294: @ 0x08055294
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r5, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #1
	bne .L080552C2
	ldr r0, [r4, #0x5c]
	bl func_fe6_08054FEC
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xf3
	movs r3, #1
	bl func_fe6_0805C804
	b .L08055358
.L080552C2:
	cmp r1, #0x34
	bne .L080552DA
	ldr r0, [r4, #0x5c]
	bl func_fe6_08055364
	ldr r0, [r4, #0x5c]
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r1, [r1]
	bl func_fe6_08055434
	b .L08055358
.L080552DA:
	cmp r1, #0xb7
	bne .L08055344
	movs r0, #0x8a
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0x78
	movs r3, #0
	bl func_fe6_0805C804
	ldr r0, [r4, #0x5c]
	bl func_fe6_080554C8
	ldr r0, [r4, #0x5c]
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r1, [r1]
	bl func_fe6_08055628
	ldr r3, .L08055340 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	strb r5, [r0]
	adds r1, r3, #0
	adds r1, #0x45
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x46
	strb r5, [r0]
	ldr r0, [r4, #0x5c]
	movs r1, #1
	movs r2, #0x14
	movs r3, #0
	bl func_fe6_08054EA0
	ldr r0, [r4, #0x5c]
	movs r1, #0xb4
	movs r2, #0x28
	movs r3, #1
	bl func_fe6_08054EA0
	b .L08055358
	.align 2, 0
.L08055340: .4byte gDispIo
.L08055344:
	ldr r0, .L08055360 @ =0x000001C5
	cmp r1, r0
	bne .L08055358
	bl SpellFx_Finish
	bl func_fe6_08047358
	adds r0, r4, #0
	bl Proc_Break
.L08055358:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08055360: .4byte 0x000001C5

	thumb_func_start func_fe6_08055364
func_fe6_08055364: @ 0x08055364
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L080553A0 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080553A4 @ =gUnk_085D2F64
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L080553A8 @ =gUnk_0811A9A8
	str r1, [r0, #0x48]
	ldr r1, .L080553AC @ =gUnk_085D2F7C
	str r1, [r0, #0x4c]
	str r1, [r0, #0x50]
	ldr r0, .L080553B0 @ =gUnk_081AB1B0
	movs r1, #0x80
	lsls r1, r1, #3
	bl SpellFx_RegisterBgGfx
	bl SpellFx_SetSomeColorEffect
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080553A0: .4byte gEfxBgSemaphore
.L080553A4: .4byte gUnk_085D2F64
.L080553A8: .4byte gUnk_0811A9A8
.L080553AC: .4byte gUnk_085D2F7C
.L080553B0: .4byte gUnk_081AB1B0

	thumb_func_start func_fe6_080553B4
func_fe6_080553B4: @ 0x080553B4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	adds r6, r0, #0
	adds r0, r4, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r5, r0, #0x10
	cmp r5, #0
	blt .L0805540C
	ldr r1, [r4, #0x4c]
	ldr r2, [r4, #0x50]
	lsls r0, r5, #2
	adds r1, r0, r1
	ldr r1, [r1]
	adds r0, r0, r2
	ldr r2, [r0]
	adds r0, r6, #0
	bl SpellFx_WriteBgMap
	ldr r0, .L08055404 @ =gUnk_0811A9BA
	lsls r1, r5, #1
	adds r0, r1, r0
	ldrh r0, [r0]
	ldr r2, .L08055408 @ =gUnk_0811A9C2
	adds r1, r1, r2
	ldrh r2, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #0
	bl func_fe6_0805C804
	b .L0805542A
	.align 2, 0
.L08055404: .4byte gUnk_0811A9BA
.L08055408: .4byte gUnk_0811A9C2
.L0805540C:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r5, r0
	bne .L0805542A
	bl SpellFx_ClearBG1
	ldr r1, .L08055430 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	adds r0, r4, #0
	bl Proc_Break
.L0805542A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08055430: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08055434
func_fe6_08055434: @ 0x08055434
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L08055460 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08055464 @ =gUnk_085D2F8C
	movs r1, #3
	bl SpawnProc
	adds r1, r0, #0
	str r4, [r1, #0x5c]
	movs r0, #0
	strh r0, [r1, #0x2c]
	str r0, [r1, #0x44]
	ldr r0, .L08055468 @ =gUnk_0811A9CA
	str r0, [r1, #0x48]
	cmp r5, #0
	bne .L08055470
	ldr r0, .L0805546C @ =gUnk_081AE88C
	b .L08055472
	.align 2, 0
.L08055460: .4byte gEfxBgSemaphore
.L08055464: .4byte gUnk_085D2F8C
.L08055468: .4byte gUnk_0811A9CA
.L0805546C: .4byte gUnk_081AE88C
.L08055470:
	ldr r0, .L0805547C @ =gUnk_081AEA8C
.L08055472:
	str r0, [r1, #0x4c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805547C: .4byte gUnk_081AEA8C

	thumb_func_start func_fe6_08055480
func_fe6_08055480: @ 0x08055480
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L080554A6
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	b .L080554BC
.L080554A6:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080554BC
	ldr r1, .L080554C4 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L080554BC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080554C4: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_080554C8
func_fe6_080554C8: @ 0x080554C8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, .L0805555C @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08055560 @ =gUnk_085D2FAC
	movs r1, #3
	bl SpawnProc
	str r5, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L08055564 @ =gUnk_0811AACC
	str r1, [r0, #0x48]
	ldr r1, .L08055568 @ =gUnk_085D2FC4
	str r1, [r0, #0x4c]
	str r1, [r0, #0x50]
	ldr r0, .L0805556C @ =gUnk_081AC114
	movs r1, #0xa8
	lsls r1, r1, #5
	bl SpellFx_RegisterBgGfx
	ldr r4, .L08055570 @ =gDispIo
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	ldrb r2, [r4, #0xc]
	ands r0, r2
	strb r0, [r4, #0xc]
	adds r0, r1, #0
	ldrb r2, [r4, #0x14]
	ands r0, r2
	movs r2, #1
	orrs r0, r2
	strb r0, [r4, #0x14]
	ldrb r0, [r4, #0x10]
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	strb r1, [r4, #0x10]
	movs r0, #3
	ldrb r1, [r4, #0x18]
	orrs r0, r1
	strb r0, [r4, #0x18]
	bl func_fe6_08047C1C
	ldr r0, .L08055574 @ =0x0000F3FF
	ldrh r2, [r5, #8]
	ands r0, r2
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5, #8]
	bl SpellFx_SetSomeColorEffect
	ldr r0, .L08055578 @ =0x0000FFE0
	ldrh r1, [r4, #0x3c]
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	ldr r1, .L0805557C @ =0x0000E0FF
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r4, #0x3c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805555C: .4byte gEfxBgSemaphore
.L08055560: .4byte gUnk_085D2FAC
.L08055564: .4byte gUnk_0811AACC
.L08055568: .4byte gUnk_085D2FC4
.L0805556C: .4byte gUnk_081AC114
.L08055570: .4byte gDispIo
.L08055574: .4byte 0x0000F3FF
.L08055578: .4byte 0x0000FFE0
.L0805557C: .4byte 0x0000E0FF

	thumb_func_start func_fe6_08055580
func_fe6_08055580: @ 0x08055580
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	adds r5, r0, #0
	ldr r6, [r4, #0x5c]
	adds r0, r4, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	cmp r3, #0
	blt .L080555BA
	ldr r1, [r4, #0x4c]
	ldr r2, [r4, #0x50]
	lsls r0, r3, #2
	adds r1, r0, r1
	ldr r1, [r1]
	adds r0, r0, r2
	ldr r2, [r0]
	adds r0, r5, #0
	bl SpellFx_WriteBgMap
	b .L08055614
.L080555BA:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r3, r0
	bne .L08055614
	bl SpellFx_ClearBG1
	ldr r1, .L0805561C @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	ldr r3, .L08055620 @ =gDispIo
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	ldrb r2, [r3, #0xc]
	ands r0, r2
	strb r0, [r3, #0xc]
	adds r0, r1, #0
	ldrb r2, [r3, #0x10]
	ands r0, r2
	movs r2, #1
	orrs r0, r2
	strb r0, [r3, #0x10]
	ldrb r0, [r3, #0x14]
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	strb r1, [r3, #0x14]
	movs r0, #3
	ldrb r1, [r3, #0x18]
	orrs r0, r1
	strb r0, [r3, #0x18]
	ldr r0, .L08055624 @ =0x0000F3FF
	ldrh r2, [r6, #8]
	ands r0, r2
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r6, #8]
	bl SpellFx_ClearColorEffects
	adds r0, r4, #0
	bl Proc_Break
.L08055614:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805561C: .4byte gEfxBgSemaphore
.L08055620: .4byte gDispIo
.L08055624: .4byte 0x0000F3FF

	thumb_func_start func_fe6_08055628
func_fe6_08055628: @ 0x08055628
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L08055654 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08055658 @ =gUnk_085D2FC8
	movs r1, #3
	bl SpawnProc
	adds r1, r0, #0
	str r4, [r1, #0x5c]
	movs r0, #0
	strh r0, [r1, #0x2c]
	str r0, [r1, #0x44]
	ldr r0, .L0805565C @ =gUnk_0811AAD2
	str r0, [r1, #0x48]
	cmp r5, #0
	bne .L08055664
	ldr r0, .L08055660 @ =gUnk_081ABCA0
	b .L08055666
	.align 2, 0
.L08055654: .4byte gEfxBgSemaphore
.L08055658: .4byte gUnk_085D2FC8
.L0805565C: .4byte gUnk_0811AAD2
.L08055660: .4byte gUnk_081ABCA0
.L08055664:
	ldr r0, .L08055670 @ =gUnk_081AEC8C
.L08055666:
	str r0, [r1, #0x4c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08055670: .4byte gUnk_081AEC8C

	thumb_func_start func_fe6_08055674
func_fe6_08055674: @ 0x08055674
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L0805569A
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	b .L080556B0
.L0805569A:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080556B0
	ldr r1, .L080556B8 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L080556B0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080556B8: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_080556BC
func_fe6_080556BC: @ 0x080556BC
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl func_fe6_08047300
	bl SpellFx_SetBG1Position
	ldr r0, .L080556F4 @ =gUnk_085D2FE8
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080556F4: .4byte gUnk_085D2FE8

	thumb_func_start func_fe6_080556F8
func_fe6_080556F8: @ 0x080556F8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	adds r6, r0, #0
	bl EfxGetCamMovDuration
	adds r5, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r1, #0
	mov r8, r1
	movs r7, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0805572E
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl NewEfxFarAttackWithDistance
.L0805572E:
	movs r2, #0x2c
	ldrsh r1, [r4, r2]
	adds r0, r5, #1
	cmp r1, r0
	bne .L080557A4
	adds r0, r6, #0
	bl func_fe6_0805581C
	movs r5, #8
	str r5, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r1, #0x28
	movs r2, #0x1e
	movs r3, #0x10
	bl func_fe6_0804CD88
	movs r4, #0x10
	str r4, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r1, #0x47
	movs r2, #0x1e
	movs r3, #8
	bl func_fe6_0804CD88
	str r5, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r1, #0x66
	movs r2, #0x1e
	movs r3, #0x10
	bl func_fe6_0804CD88
	str r4, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r1, #0x85
	movs r2, #0x1e
	movs r3, #8
	bl func_fe6_0804CD88
	str r7, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r1, #0xa4
	movs r2, #0x3c
	movs r3, #0x10
	bl func_fe6_0804CD88
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #2
	ldrsh r2, [r6, r0]
	movs r0, #0xfd
	movs r3, #1
	bl func_fe6_0805C804
	b .L08055810
.L080557A4:
	adds r0, r5, #0
	adds r0, #0x50
	cmp r1, r0
	bne .L080557B4
	adds r0, r6, #0
	bl func_fe6_080558D4
	b .L08055810
.L080557B4:
	adds r0, r5, #0
	adds r0, #0xa4
	cmp r1, r0
	bne .L080557CA
	adds r0, r6, #0
	movs r1, #1
	movs r2, #5
	movs r3, #0
	bl NewEfxFlashUnit
	b .L08055810
.L080557CA:
	adds r0, r5, #0
	adds r0, #0xc8
	cmp r1, r0
	bne .L080557F0
	movs r0, #9
	ldrh r1, [r6, #0x10]
	orrs r0, r1
	strh r0, [r6, #0x10]
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r1, [r0]
	adds r0, r6, #0
	bl StartBattleAnimStatusChgHitEffects
	adds r0, r6, #0
	movs r1, #0
	bl SetUnitEfxDebuff
	b .L08055810
.L080557F0:
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r5, r2
	cmp r1, r0
	bne .L08055810
	movs r0, #2
	ldrh r1, [r6, #0x10]
	orrs r0, r1
	strh r0, [r6, #0x10]
	bl SpellFx_Finish
	bl func_fe6_08047358
	adds r0, r4, #0
	bl Proc_Break
.L08055810:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805581C
func_fe6_0805581C: @ 0x0805581C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L08055858 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0805585C @ =gUnk_085D3000
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L08055860 @ =gUnk_0811ABB0
	str r1, [r0, #0x48]
	ldr r1, .L08055864 @ =gUnk_085D3018
	str r1, [r0, #0x4c]
	str r1, [r0, #0x50]
	ldr r1, .L08055868 @ =gUnk_085D304C
	str r1, [r0, #0x54]
	ldr r0, .L0805586C @ =Pal_Unk_081B1710
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	bl SpellFx_SetSomeColorEffect
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08055858: .4byte gEfxBgSemaphore
.L0805585C: .4byte gUnk_085D3000
.L08055860: .4byte gUnk_0811ABB0
.L08055864: .4byte gUnk_085D3018
.L08055868: .4byte gUnk_085D304C
.L0805586C: .4byte Pal_Unk_081B1710

	thumb_func_start func_fe6_08055870
func_fe6_08055870: @ 0x08055870
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	cmp r3, #0
	blt .L080558AC
	ldr r1, [r4, #0x4c]
	ldr r2, [r4, #0x50]
	ldr r5, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	lsls r4, r3, #2
	adds r1, r4, r1
	ldr r1, [r1]
	adds r2, r4, r2
	ldr r2, [r2]
	bl SpellFx_WriteBgMap
	adds r4, r4, r5
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	b .L080558CA
.L080558AC:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r3, r0
	bne .L080558CA
	bl SpellFx_ClearBG1
	ldr r1, .L080558D0 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	adds r0, r4, #0
	bl Proc_Break
.L080558CA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080558D0: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_080558D4
func_fe6_080558D4: @ 0x080558D4
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, .L08055910 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08055914 @ =gUnk_085D3080
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	ldr r3, .L08055918 @ =gUnk_085F63A8
	str r3, [sp]
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	adds r6, r0, #0
	str r6, [r5, #0x60]
	adds r0, r4, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L0805591C
	ldrh r0, [r6, #2]
	subs r0, #8
	b .L08055920
	.align 2, 0
.L08055910: .4byte gEfxBgSemaphore
.L08055914: .4byte gUnk_085D3080
.L08055918: .4byte gUnk_085F63A8
.L0805591C:
	ldrh r0, [r6, #2]
	adds r0, #8
.L08055920:
	strh r0, [r6, #2]
	ldrh r0, [r6, #4]
	subs r0, #8
	strh r0, [r6, #4]
	ldr r0, .L08055944 @ =gUnk_081B7650
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L08055948 @ =gUnk_081B7468
	movs r1, #0x80
	lsls r1, r1, #4
	bl SpellFx_RegisterObjGfx
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08055944: .4byte gUnk_081B7650
.L08055948: .4byte gUnk_081B7468

	thumb_func_start func_fe6_0805594C
func_fe6_0805594C: @ 0x0805594C
	ldr r1, .L08055958 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
.L08055958: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_0805595C
func_fe6_0805595C: @ 0x0805595C
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl func_fe6_08047300
	bl SpellFx_SetBG1Position
	ldr r0, .L08055994 @ =gUnk_085D30A0
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08055994: .4byte gUnk_085D30A0

	thumb_func_start func_fe6_08055998
func_fe6_08055998: @ 0x08055998
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	adds r5, r0, #0
	bl EfxGetCamMovDuration
	adds r6, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r1, #0
	mov r8, r1
	movs r7, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L080559DC
	ldr r0, [r4, #0x5c]
	bl func_fe6_08055B84
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xfa
	movs r3, #1
	bl func_fe6_0805C804
.L080559DC:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0x29
	bne .L080559EE
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl NewEfxFarAttackWithDistance
	b .L08055A92
.L080559EE:
	movs r3, #0x2c
	ldrsh r1, [r4, r3]
	adds r0, r6, #0
	adds r0, #0x44
	cmp r1, r0
	bne .L08055A22
	ldr r0, [r4, #0x5c]
	bl func_fe6_08055AA0
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #2
	ldrsh r2, [r5, r0]
	movs r0, #0xfb
	movs r3, #1
	bl func_fe6_0805C804
	ldr r0, [r4, #0x5c]
	str r7, [sp]
	str r7, [sp, #4]
	movs r1, #0x42
	movs r2, #0x14
	movs r3, #0x10
	bl func_fe6_0804CD88
	b .L08055A92
.L08055A22:
	adds r0, r6, #0
	adds r0, #0x86
	cmp r1, r0
	bne .L08055A74
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r0, #0xfc
	movs r3, #1
	bl func_fe6_0805C804
	bl func_fe6_0805BD8C
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r6, r4, #0
	adds r6, #0x29
	ldrb r1, [r6]
	adds r0, r5, #0
	bl StartBattleAnimStatusChgHitEffects
	ldr r0, [r4, #0x5c]
	movs r1, #0xa
	bl NewEfxFlashBgWhite
	ldrb r0, [r6]
	cmp r0, #0
	bne .L08055A92
	adds r0, r5, #0
	bl GetUnitEfxDebuff
	cmp r0, #0
	bne .L08055A92
	adds r0, r5, #0
	movs r1, #3
	bl SetUnitEfxDebuff
	b .L08055A92
.L08055A74:
	adds r0, r6, #0
	adds r0, #0x9e
	cmp r1, r0
	bne .L08055A92
	movs r0, #2
	ldrh r3, [r5, #0x10]
	orrs r0, r3
	strh r0, [r5, #0x10]
	bl SpellFx_Finish
	bl func_fe6_08047358
	adds r0, r4, #0
	bl Proc_Break
.L08055A92:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08055AA0
func_fe6_08055AA0: @ 0x08055AA0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L08055B00 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08055B04 @ =gUnk_085D30B8
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L08055B08 @ =gUnk_0811ABE6
	str r0, [r5, #0x48]
	ldr r0, .L08055B0C @ =gUnk_085D30D0
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L08055B10 @ =gUnk_081B4254
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	ldr r0, .L08055B14 @ =gUnk_081B2348
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	bl SpellFx_SetSomeColorEffect
	ldr r0, .L08055B18 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08055B26
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L08055B1C
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
	b .L08055B26
	.align 2, 0
.L08055B00: .4byte gEfxBgSemaphore
.L08055B04: .4byte gUnk_085D30B8
.L08055B08: .4byte gUnk_0811ABE6
.L08055B0C: .4byte gUnk_085D30D0
.L08055B10: .4byte gUnk_081B4254
.L08055B14: .4byte gUnk_081B2348
.L08055B18: .4byte gEkrDistanceType
.L08055B1C:
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
.L08055B26:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08055B2C
func_fe6_08055B2C: @ 0x08055B2C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	blt .L08055B5A
	ldr r1, [r4, #0x4c]
	ldr r3, [r4, #0x50]
	ldr r0, [r4, #0x5c]
	lsls r2, r2, #2
	adds r1, r2, r1
	ldr r1, [r1]
	adds r2, r2, r3
	ldr r2, [r2]
	bl SpellFx_WriteBgMap
	b .L08055B78
.L08055B5A:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne .L08055B78
	bl SpellFx_ClearBG1
	ldr r1, .L08055B80 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	adds r0, r4, #0
	bl Proc_Break
.L08055B78:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08055B80: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08055B84
func_fe6_08055B84: @ 0x08055B84
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L08055BC8 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08055BCC @ =gUnk_085D3118
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	ldr r3, .L08055BD0 @ =gUnk_085F6674
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	str r0, [r4, #0x60]
	ldr r0, .L08055BD4 @ =gUnk_081B4254
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L08055BD8 @ =gUnk_081B3D34
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08055BC8: .4byte gEfxBgSemaphore
.L08055BCC: .4byte gUnk_085D3118
.L08055BD0: .4byte gUnk_085F6674
.L08055BD4: .4byte gUnk_081B4254
.L08055BD8: .4byte gUnk_081B3D34

	thumb_func_start func_fe6_08055BDC
func_fe6_08055BDC: @ 0x08055BDC
	push {lr}
	ldr r0, [r0, #0x60]
	bl BasRemove
	ldr r1, .L08055BF0 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
.L08055BF0: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08055BF4
func_fe6_08055BF4: @ 0x08055BF4
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl func_fe6_08047300
	bl SpellFx_SetBG1Position
	ldr r0, .L08055C2C @ =gUnk_085D3138
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08055C2C: .4byte gUnk_085D3138

	thumb_func_start func_fe6_08055C30
func_fe6_08055C30: @ 0x08055C30
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	adds r5, r0, #0
	bl EfxGetCamMovDuration
	adds r6, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r1, #0
	mov r8, r1
	movs r7, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08055C74
	ldr r0, [r4, #0x5c]
	bl func_fe6_08055E14
	ldr r0, .L08055CC8 @ =0x0000011B
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	movs r3, #1
	bl func_fe6_0805C804
.L08055C74:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0x64
	bne .L08055C84
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl NewEfxFarAttackWithDistance
.L08055C84:
	movs r2, #0x2c
	ldrsh r1, [r4, r2]
	adds r0, r6, #0
	adds r0, #0x82
	cmp r1, r0
	bne .L08055CCC
	adds r0, r5, #0
	bl func_fe6_08055E6C
	adds r0, r5, #0
	bl func_fe6_08055ED0
	ldr r0, [r4, #0x5c]
	bl func_fe6_08055D30
	movs r0, #0x10
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0x14
	movs r3, #0
	bl func_fe6_0804CD88
	str r7, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r1, #0xe6
	movs r2, #0x14
	movs r3, #0x10
	bl func_fe6_0804CD88
	b .L08055D22
	.align 2, 0
.L08055CC8: .4byte 0x0000011B
.L08055CCC:
	movs r3, #0xa5
	lsls r3, r3, #1
	adds r0, r6, r3
	cmp r1, r0
	bne .L08055D02
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl StartBattleAnimStatusChgHitEffects
	ldrb r0, [r4]
	cmp r0, #0
	bne .L08055D22
	adds r0, r5, #0
	bl GetUnitEfxDebuff
	cmp r0, #0
	bne .L08055D22
	adds r0, r5, #0
	movs r1, #2
	bl SetUnitEfxDebuff
	b .L08055D22
.L08055D02:
	movs r2, #0xb9
	lsls r2, r2, #1
	adds r0, r6, r2
	cmp r1, r0
	bne .L08055D22
	movs r0, #2
	ldrh r3, [r5, #0x10]
	orrs r0, r3
	strh r0, [r5, #0x10]
	bl SpellFx_Finish
	bl func_fe6_08047358
	adds r0, r4, #0
	bl Proc_Break
.L08055D22:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08055D30
func_fe6_08055D30: @ 0x08055D30
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L08055D90 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08055D94 @ =gUnk_085D3150
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L08055D98 @ =gUnk_0811AC30
	str r0, [r5, #0x48]
	ldr r0, .L08055D9C @ =gUnk_085D3168
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L08055DA0 @ =gUnk_081B6688
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	ldr r0, .L08055DA4 @ =gUnk_081B57BC
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	bl SpellFx_SetSomeColorEffect
	ldr r0, .L08055DA8 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08055DB6
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L08055DAC
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
	b .L08055DB6
	.align 2, 0
.L08055D90: .4byte gEfxBgSemaphore
.L08055D94: .4byte gUnk_085D3150
.L08055D98: .4byte gUnk_0811AC30
.L08055D9C: .4byte gUnk_085D3168
.L08055DA0: .4byte gUnk_081B6688
.L08055DA4: .4byte gUnk_081B57BC
.L08055DA8: .4byte gEkrDistanceType
.L08055DAC:
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
.L08055DB6:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08055DBC
func_fe6_08055DBC: @ 0x08055DBC
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	blt .L08055DEA
	ldr r1, [r4, #0x4c]
	ldr r3, [r4, #0x50]
	ldr r0, [r4, #0x5c]
	lsls r2, r2, #2
	adds r1, r2, r1
	ldr r1, [r1]
	adds r2, r2, r3
	ldr r2, [r2]
	bl SpellFx_WriteBgMap
	b .L08055E08
.L08055DEA:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne .L08055E08
	bl SpellFx_ClearBG1
	ldr r1, .L08055E10 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	adds r0, r4, #0
	bl Proc_Break
.L08055E08:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08055E10: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08055E14
func_fe6_08055E14: @ 0x08055E14
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L08055E58 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08055E5C @ =gUnk_085D31A8
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	ldr r3, .L08055E60 @ =gUnk_085FE544
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	str r0, [r4, #0x60]
	ldr r0, .L08055E64 @ =gUnk_081B7650
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L08055E68 @ =gUnk_081B7468
	movs r1, #0x80
	lsls r1, r1, #4
	bl SpellFx_RegisterObjGfx
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08055E58: .4byte gEfxBgSemaphore
.L08055E5C: .4byte gUnk_085D31A8
.L08055E60: .4byte gUnk_085FE544
.L08055E64: .4byte gUnk_081B7650
.L08055E68: .4byte gUnk_081B7468

	thumb_func_start func_fe6_08055E6C
func_fe6_08055E6C: @ 0x08055E6C
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L08055EB4 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08055EB8 @ =gUnk_085D31C8
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	ldr r3, .L08055EBC @ =gUnk_085FE3C4
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	adds r5, r0, #0
	str r5, [r4, #0x60]
	ldrh r0, [r5, #4]
	subs r0, #8
	strh r0, [r5, #4]
	bl GetEkrDragonStateTypeIdunn
	cmp r0, #0
	beq .L08055EAC
	ldrh r0, [r5, #2]
	subs r0, #0x10
	strh r0, [r5, #2]
.L08055EAC:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08055EB4: .4byte gEfxBgSemaphore
.L08055EB8: .4byte gUnk_085D31C8
.L08055EBC: .4byte gUnk_085FE3C4

	thumb_func_start func_fe6_08055EC0
func_fe6_08055EC0: @ 0x08055EC0
	ldr r1, .L08055ECC @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
.L08055ECC: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08055ED0
func_fe6_08055ED0: @ 0x08055ED0
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L08055EEC @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08055EF0 @ =gUnk_085D31E8
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08055EEC: .4byte gEfxBgSemaphore
.L08055EF0: .4byte gUnk_085D31E8

	thumb_func_start func_fe6_08055EF4
func_fe6_08055EF4: @ 0x08055EF4
	push {r4, lr}
	movs r3, #0x8e
	lsls r3, r3, #1
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r0, #0x5c]
	movs r4, #2
	ldrsh r2, [r0, r4]
	adds r0, r3, #0
	movs r3, #1
	bl func_fe6_0805C804
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08055F14
func_fe6_08055F14: @ 0x08055F14
	ldr r1, .L08055F20 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
.L08055F20: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08055F24
func_fe6_08055F24: @ 0x08055F24
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl func_fe6_08047300
	bl SpellFx_SetBG1Position
	ldr r0, .L08055F5C @ =gUnk_085D3230
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08055F5C: .4byte gUnk_085D3230

	thumb_func_start func_fe6_08055F60
func_fe6_08055F60: @ 0x08055F60
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	adds r6, r0, #0
	bl EfxGetCamMovDuration
	adds r5, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r1, #0
	mov r8, r1
	movs r7, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08055F96
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl NewEfxFarAttackWithDistance
.L08055F96:
	movs r2, #0x2c
	ldrsh r1, [r4, r2]
	adds r0, r5, #1
	cmp r1, r0
	bne .L08056010
	adds r0, r6, #0
	bl func_fe6_08056080
	movs r5, #8
	str r5, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r1, #0x28
	movs r2, #0x1e
	movs r3, #0x10
	bl func_fe6_0804CD88
	movs r4, #0x10
	str r4, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r1, #0x47
	movs r2, #0x1e
	movs r3, #8
	bl func_fe6_0804CD88
	str r5, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r1, #0x66
	movs r2, #0x1e
	movs r3, #0x10
	bl func_fe6_0804CD88
	str r4, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r1, #0x85
	movs r2, #0x1e
	movs r3, #8
	bl func_fe6_0804CD88
	str r7, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r1, #0xa4
	movs r2, #0x3c
	movs r3, #0x10
	bl func_fe6_0804CD88
	ldr r0, .L0805600C @ =0x00000103
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r6, r3]
	movs r3, #1
	bl func_fe6_0805C804
	b .L08056074
	.align 2, 0
.L0805600C: .4byte 0x00000103
.L08056010:
	adds r0, r5, #0
	adds r0, #0x50
	cmp r1, r0
	bne .L08056020
	adds r0, r6, #0
	bl func_fe6_08056138
	b .L08056074
.L08056020:
	adds r0, r5, #0
	adds r0, #0xa4
	cmp r1, r0
	bne .L08056036
	adds r0, r6, #0
	movs r1, #1
	movs r2, #5
	movs r3, #0
	bl NewEfxFlashUnit
	b .L08056074
.L08056036:
	adds r0, r5, #0
	adds r0, #0xc8
	cmp r1, r0
	bne .L08056054
	movs r0, #9
	ldrh r1, [r6, #0x10]
	orrs r0, r1
	strh r0, [r6, #0x10]
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r1, [r0]
	adds r0, r6, #0
	bl StartBattleAnimStatusChgHitEffects
	b .L08056074
.L08056054:
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r5, r2
	cmp r1, r0
	bne .L08056074
	movs r0, #2
	ldrh r3, [r6, #0x10]
	orrs r0, r3
	strh r0, [r6, #0x10]
	bl SpellFx_Finish
	bl func_fe6_08047358
	adds r0, r4, #0
	bl Proc_Break
.L08056074:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08056080
func_fe6_08056080: @ 0x08056080
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L080560BC @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080560C0 @ =gUnk_085D3248
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L080560C4 @ =gUnk_0811AD32
	str r1, [r0, #0x48]
	ldr r1, .L080560C8 @ =gUnk_085D3260
	str r1, [r0, #0x4c]
	str r1, [r0, #0x50]
	ldr r1, .L080560CC @ =gUnk_085D3294
	str r1, [r0, #0x54]
	ldr r0, .L080560D0 @ =gUnk_081B4274
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	bl SpellFx_SetSomeColorEffect
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080560BC: .4byte gEfxBgSemaphore
.L080560C0: .4byte gUnk_085D3248
.L080560C4: .4byte gUnk_0811AD32
.L080560C8: .4byte gUnk_085D3260
.L080560CC: .4byte gUnk_085D3294
.L080560D0: .4byte gUnk_081B4274

	thumb_func_start func_fe6_080560D4
func_fe6_080560D4: @ 0x080560D4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r3, r0, #0x10
	cmp r3, #0
	blt .L08056110
	ldr r1, [r4, #0x4c]
	ldr r2, [r4, #0x50]
	ldr r5, [r4, #0x54]
	ldr r0, [r4, #0x5c]
	lsls r4, r3, #2
	adds r1, r4, r1
	ldr r1, [r1]
	adds r2, r4, r2
	ldr r2, [r2]
	bl SpellFx_WriteBgMap
	adds r4, r4, r5
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	b .L0805612E
.L08056110:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r3, r0
	bne .L0805612E
	bl SpellFx_ClearBG1
	ldr r1, .L08056134 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	adds r0, r4, #0
	bl Proc_Break
.L0805612E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08056134: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08056138
func_fe6_08056138: @ 0x08056138
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L0805617C @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08056180 @ =gUnk_085D32C8
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	ldr r3, .L08056184 @ =gUnk_085F9358
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	str r0, [r4, #0x60]
	ldr r0, .L08056188 @ =gUnk_081B7670
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0805618C @ =gUnk_081B7468
	movs r1, #0x80
	lsls r1, r1, #4
	bl SpellFx_RegisterObjGfx
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805617C: .4byte gEfxBgSemaphore
.L08056180: .4byte gUnk_085D32C8
.L08056184: .4byte gUnk_085F9358
.L08056188: .4byte gUnk_081B7670
.L0805618C: .4byte gUnk_081B7468

	thumb_func_start func_fe6_08056190
func_fe6_08056190: @ 0x08056190
	ldr r1, .L0805619C @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
.L0805619C: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_080561A0
func_fe6_080561A0: @ 0x080561A0
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl func_fe6_08047300
	bl SpellFx_SetBG1Position
	ldr r0, .L080561D8 @ =gUnk_085D32E8
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080561D8: .4byte gUnk_085D32E8

	thumb_func_start func_fe6_080561DC
func_fe6_080561DC: @ 0x080561DC
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	adds r5, r0, #0
	bl EfxGetCamMovDuration
	adds r6, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r7, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0805620A
	ldr r0, [r4, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl NewEfxFarAttackWithDistance
.L0805620A:
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	adds r0, r6, #1
	cmp r1, r0
	bne .L0805625C
	adds r0, r5, #0
	bl func_fe6_080564E4
	adds r0, r5, #0
	movs r1, #0x4a
	bl func_fe6_080562C0
	adds r0, r5, #0
	movs r1, #0x4a
	bl func_fe6_08056444
	movs r4, #0x80
	lsls r4, r4, #1
	movs r0, #1
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0x4a
	movs r2, #0xa
	adds r3, r4, #0
	bl func_fe6_0804C8D4
	ldr r2, .L08056258 @ =func_fe6_0804CD4C
	adds r0, r5, #0
	movs r1, #0x4a
	bl func_fe6_0804CC68
	movs r1, #2
	ldrsh r2, [r5, r1]
	movs r0, #0xf9
	adds r1, r4, #0
	movs r3, #1
	bl func_fe6_0805C804
	b .L080562B6
	.align 2, 0
.L08056258: .4byte func_fe6_0804CD4C
.L0805625C:
	adds r0, r6, #0
	adds r0, #0x4a
	cmp r1, r0
	bne .L08056298
	adds r0, r5, #0
	movs r1, #5
	bl NewEfxFlashBgWhite
	movs r0, #9
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r5, #0
	bl StartBattleAnimStatusChgHitEffects
	ldrb r0, [r4]
	cmp r0, #0
	bne .L080562B6
	adds r0, r5, #0
	bl GetUnitEfxDebuff
	cmp r0, #0
	bne .L080562B6
	adds r0, r5, #0
	movs r1, #4
	bl SetUnitEfxDebuff
	b .L080562B6
.L08056298:
	adds r0, r6, #0
	adds r0, #0x5a
	cmp r1, r0
	bne .L080562B6
	movs r0, #2
	ldrh r1, [r5, #0x10]
	orrs r0, r1
	strh r0, [r5, #0x10]
	bl SpellFx_Finish
	bl func_fe6_08047358
	adds r0, r4, #0
	bl Proc_Break
.L080562B6:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080562C0
func_fe6_080562C0: @ 0x080562C0
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r1, .L080563B8 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080563BC @ =gUnk_085D3300
	movs r1, #3
	bl SpawnProc
	str r5, [r0, #0x5c]
	movs r6, #0
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r4, [r0, #0x2e]
	ldr r0, .L080563C0 @ =gUnk_081B7690
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	ldr r0, .L080563C4 @ =gUnk_081B4E9C
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	ldr r0, .L080563C8 @ =gUnk_081B4F9C
	ldr r1, .L080563CC @ =gBg1Tm
	movs r2, #1
	str r2, [sp]
	adds r2, #0xff
	str r2, [sp, #4]
	movs r2, #0x20
	movs r3, #0x20
	bl EfxTmCpyBG
	movs r0, #2
	bl EnableBgSync
	bl SpellFx_SetSomeColorEffect
	ldr r0, .L080563D0 @ =gDispIo
	mov ip, r0
	mov r2, ip
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	mov r1, ip
	adds r1, #0x44
	movs r0, #0xe
	strb r0, [r1]
	adds r1, #1
	movs r4, #8
	movs r0, #8
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x46
	strb r6, [r0]
	mov r6, ip
	adds r6, #0x37
	movs r3, #0x20
	ldrb r1, [r6]
	orrs r1, r3
	movs r0, #0x21
	rsbs r0, r0, #0
	mov r2, ip
	ldrb r2, [r2, #1]
	ands r0, r2
	movs r2, #0x41
	rsbs r2, r2, #0
	ands r0, r2
	movs r2, #0x80
	orrs r0, r2
	mov r7, ip
	strb r0, [r7, #1]
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	movs r0, #4
	orrs r1, r0
	orrs r1, r4
	movs r0, #0x10
	orrs r1, r0
	strb r1, [r6]
	ldr r0, .L080563D4 @ =0x0000FFE0
	ldrh r1, [r7, #0x3c]
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	ldr r1, .L080563D8 @ =0x0000E0FF
	ands r0, r1
	movs r2, #0xe0
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r7, #0x3c]
	mov r0, ip
	adds r0, #0x3d
	ldrb r7, [r0]
	orrs r3, r7
	strb r3, [r0]
	ldr r0, [r5, #0x1c]
	movs r1, #0x80
	lsls r1, r1, #4
	orrs r0, r1
	str r0, [r5, #0x1c]
	ldr r0, .L080563DC @ =0x0000F3FF
	ldrh r1, [r5, #8]
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5, #8]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080563B8: .4byte gEfxBgSemaphore
.L080563BC: .4byte gUnk_085D3300
.L080563C0: .4byte gUnk_081B7690
.L080563C4: .4byte gUnk_081B4E9C
.L080563C8: .4byte gUnk_081B4F9C
.L080563CC: .4byte gBg1Tm
.L080563D0: .4byte gDispIo
.L080563D4: .4byte 0x0000FFE0
.L080563D8: .4byte 0x0000E0FF
.L080563DC: .4byte 0x0000F3FF

	thumb_func_start func_fe6_080563E0
func_fe6_080563E0: @ 0x080563E0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x5c]
	ldr r1, .L08056434 @ =gDispIo
	ldrh r0, [r1, #0x22]
	subs r0, #1
	strh r0, [r1, #0x22]
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L0805642C
	bl SpellFx_ClearBG1
	bl SpellFx_ClearColorEffects
	ldr r0, [r5, #0x1c]
	ldr r1, .L08056438 @ =0xFFFFF7FF
	ands r0, r1
	str r0, [r5, #0x1c]
	ldr r0, .L0805643C @ =0x0000F3FF
	ldrh r1, [r5, #8]
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5, #8]
	ldr r1, .L08056440 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0805642C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08056434: .4byte gDispIo
.L08056438: .4byte 0xFFFFF7FF
.L0805643C: .4byte 0x0000F3FF
.L08056440: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08056444
func_fe6_08056444: @ 0x08056444
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, .L08056468 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0805646C @ =gUnk_085D3318
	movs r1, #4
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08056468: .4byte gEfxBgSemaphore
.L0805646C: .4byte gUnk_085D3318

	thumb_func_start func_fe6_08056470
func_fe6_08056470: @ 0x08056470
	push {r4, lr}
	sub sp, #0x48
	adds r4, r0, #0
	ldr r2, [r4, #0x5c]
	mov r1, sp
	ldrh r0, [r2, #2]
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	strh r0, [r1, #4]
	ldr r0, [r2, #0x3c]
	str r0, [sp, #0x3c]
	ldr r0, [r2, #0x1c]
	ldr r1, .L080564CC @ =0xFFFFF7FF
	ands r0, r1
	str r0, [sp, #0x1c]
	mov r0, sp
	ldrh r1, [r2, #8]
	strh r1, [r0, #8]
	mov r2, sp
	ldr r0, .L080564D0 @ =0x0000F3FF
	ands r0, r1
	strh r0, [r2, #8]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2, #8]
	mov r0, sp
	bl BasPutOam
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L080564C2
	adds r0, r4, #0
	bl Proc_Break
.L080564C2:
	add sp, #0x48
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080564CC: .4byte 0xFFFFF7FF
.L080564D0: .4byte 0x0000F3FF

	thumb_func_start func_fe6_080564D4
func_fe6_080564D4: @ 0x080564D4
	ldr r1, .L080564E0 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
.L080564E0: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_080564E4
func_fe6_080564E4: @ 0x080564E4
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L0805652C @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08056530 @ =gUnk_085D3338
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	adds r0, r5, #0
	bl GetAnimAnotherSide
	ldr r3, .L08056534 @ =AnimScr_ManaketeFlame
	ldr r0, [r4, #0x5c]
	str r3, [sp]
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	str r0, [r4, #0x60]
	ldr r1, .L08056538 @ =0x0000F3FF
	ldrh r2, [r0, #8]
	ands r1, r2
	movs r3, #0x80
	lsls r3, r3, #3
	adds r2, r3, #0
	orrs r1, r2
	strh r1, [r0, #8]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805652C: .4byte gEfxBgSemaphore
.L08056530: .4byte gUnk_085D3338
.L08056534: .4byte AnimScr_ManaketeFlame
.L08056538: .4byte 0x0000F3FF

	thumb_func_start func_fe6_0805653C
func_fe6_0805653C: @ 0x0805653C
	push {lr}
	ldr r2, .L08056550 @ =gEfxBgSemaphore
	ldr r1, [r2]
	subs r1, #1
	str r1, [r2]
	ldr r0, [r0, #0x60]
	bl BasRemove
	pop {r0}
	bx r0
	.align 2, 0
.L08056550: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08056554
func_fe6_08056554: @ 0x08056554
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, .L08056584 @ =gUnk_085FEAF8
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L08056588 @ =gUnk_081B7F68
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0805658C @ =gUnk_081B76B0
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08056584: .4byte gUnk_085FEAF8
.L08056588: .4byte gUnk_081B7F68
.L0805658C: .4byte gUnk_081B76B0

	thumb_func_start func_fe6_08056590
func_fe6_08056590: @ 0x08056590
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, .L080565C0 @ =gUnk_085FEB0C
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L080565C4 @ =gUnk_081B7F68
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L080565C8 @ =gUnk_081B76B0
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080565C0: .4byte gUnk_085FEB0C
.L080565C4: .4byte gUnk_081B7F68
.L080565C8: .4byte gUnk_081B76B0

	thumb_func_start func_fe6_080565CC
func_fe6_080565CC: @ 0x080565CC
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, .L080565FC @ =gUnk_085FEB20
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L08056600 @ =gUnk_081B7F68
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L08056604 @ =gUnk_081B76B0
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080565FC: .4byte gUnk_085FEB20
.L08056600: .4byte gUnk_081B7F68
.L08056604: .4byte gUnk_081B76B0

	thumb_func_start func_fe6_08056608
func_fe6_08056608: @ 0x08056608
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, .L08056638 @ =gUnk_085FEB34
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L0805663C @ =gUnk_081B7F68
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L08056640 @ =gUnk_081B76B0
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08056638: .4byte gUnk_085FEB34
.L0805663C: .4byte gUnk_081B7F68
.L08056640: .4byte gUnk_081B76B0

	thumb_func_start func_fe6_08056644
func_fe6_08056644: @ 0x08056644
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, .L08056674 @ =gUnk_085FEB48
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L08056678 @ =gUnk_081B7F68
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0805667C @ =gUnk_081B76B0
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08056674: .4byte gUnk_085FEB48
.L08056678: .4byte gUnk_081B7F68
.L0805667C: .4byte gUnk_081B76B0

	thumb_func_start func_fe6_08056680
func_fe6_08056680: @ 0x08056680
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, .L080566B0 @ =gUnk_085FEEBC
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L080566B4 @ =gUnk_081B7F68
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L080566B8 @ =gUnk_081B7B48
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080566B0: .4byte gUnk_085FEEBC
.L080566B4: .4byte gUnk_081B7F68
.L080566B8: .4byte gUnk_081B7B48

	thumb_func_start func_fe6_080566BC
func_fe6_080566BC: @ 0x080566BC
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, .L080566EC @ =gUnk_085FEEC8
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L080566F0 @ =gUnk_081B7F68
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L080566F4 @ =gUnk_081B7B48
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080566EC: .4byte gUnk_085FEEC8
.L080566F0: .4byte gUnk_081B7F68
.L080566F4: .4byte gUnk_081B7B48

	thumb_func_start func_fe6_080566F8
func_fe6_080566F8: @ 0x080566F8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, .L08056728 @ =gUnk_085FEED4
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L0805672C @ =gUnk_081B7F68
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L08056730 @ =gUnk_081B7B48
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08056728: .4byte gUnk_085FEED4
.L0805672C: .4byte gUnk_081B7F68
.L08056730: .4byte gUnk_081B7B48

	thumb_func_start func_fe6_08056734
func_fe6_08056734: @ 0x08056734
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, .L08056764 @ =gUnk_085FEEE0
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L08056768 @ =gUnk_081B7F68
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0805676C @ =gUnk_081B7B48
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08056764: .4byte gUnk_085FEEE0
.L08056768: .4byte gUnk_081B7F68
.L0805676C: .4byte gUnk_081B7B48

	thumb_func_start func_fe6_08056770
func_fe6_08056770: @ 0x08056770
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, .L080567A0 @ =gUnk_085FEEEC
	str r0, [r1, #0x24]
	str r0, [r1, #0x20]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, .L080567A4 @ =gUnk_081B7F68
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L080567A8 @ =gUnk_081B7B48
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080567A0: .4byte gUnk_085FEEEC
.L080567A4: .4byte gUnk_081B7F68
.L080567A8: .4byte gUnk_081B7B48

	thumb_func_start func_fe6_080567AC
func_fe6_080567AC: @ 0x080567AC
	push {r4, r5, lr}
	adds r5, r0, #0
	bl SpellFx_Begin
	bl func_fe6_08047300
	bl SpellFx_SetBG1Position
	ldr r0, .L080567E4 @ =gUnk_085D33F0
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r5, #0
	bl GetAnimRoundTypeAnotherSide
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl CheckRoundMiss
	adds r4, #0x29
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080567E4: .4byte gUnk_085D33F0

	thumb_func_start func_fe6_080567E8
func_fe6_080567E8: @ 0x080567E8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x5c]
	bl GetAnimAnotherSide
	adds r4, r0, #0
	bl EfxGetCamMovDuration
	adds r6, r0, #0
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	movs r7, #0
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08056814
	ldr r0, [r5, #0x5c]
	movs r1, #1
	rsbs r1, r1, #0
	bl NewEfxFarAttackWithDistance
.L08056814:
	movs r0, #0x2c
	ldrsh r1, [r5, r0]
	adds r0, r6, #1
	cmp r1, r0
	bne .L08056844
	ldr r0, [r5, #0x5c]
	bl func_fe6_080568B4
	adds r0, r4, #0
	bl func_fe6_08056968
	adds r0, r4, #0
	bl func_fe6_080569C0
	movs r0, #0x81
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r4, r3]
	movs r3, #1
	bl func_fe6_0805C804
	b .L080568AE
.L08056844:
	adds r0, r6, #0
	adds r0, #0x28
	cmp r1, r0
	beq .L08056854
	adds r0, r6, #0
	adds r0, #0x50
	cmp r1, r0
	bne .L0805685C
.L08056854:
	adds r0, r4, #0
	bl func_fe6_080569C0
	b .L080568AE
.L0805685C:
	adds r0, r6, #0
	adds r0, #0xb0
	cmp r1, r0
	bne .L08056872
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #0
	bl NewEfxFlashUnit
	b .L080568AE
.L08056872:
	adds r0, r6, #0
	adds r0, #0xe1
	cmp r1, r0
	bne .L08056890
	movs r0, #9
	ldrh r1, [r4, #0x10]
	orrs r0, r1
	strh r0, [r4, #0x10]
	adds r0, r5, #0
	adds r0, #0x29
	ldrb r1, [r0]
	adds r0, r4, #0
	bl StartBattleAnimStatusChgHitEffects
	b .L080568AE
.L08056890:
	adds r0, r6, #0
	adds r0, #0xe6
	cmp r1, r0
	bne .L080568AE
	movs r0, #2
	ldrh r3, [r4, #0x10]
	orrs r0, r3
	strh r0, [r4, #0x10]
	bl SpellFx_Finish
	bl func_fe6_08047358
	adds r0, r5, #0
	bl Proc_Break
.L080568AE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080568B4
func_fe6_080568B4: @ 0x080568B4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L080568F8 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080568FC @ =gUnk_085D3408
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L08056900 @ =gUnk_0811AD68
	str r1, [r0, #0x48]
	ldr r1, .L08056904 @ =gUnk_085D3420
	str r1, [r0, #0x4c]
	str r1, [r0, #0x50]
	ldr r0, .L08056908 @ =gUnk_081B8934
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	ldr r0, .L0805690C @ =gUnk_081B80A8
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	bl SpellFx_SetSomeColorEffect
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080568F8: .4byte gEfxBgSemaphore
.L080568FC: .4byte gUnk_085D3408
.L08056900: .4byte gUnk_0811AD68
.L08056904: .4byte gUnk_085D3420
.L08056908: .4byte gUnk_081B8934
.L0805690C: .4byte gUnk_081B80A8

	thumb_func_start func_fe6_08056910
func_fe6_08056910: @ 0x08056910
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	blt .L0805693E
	ldr r1, [r4, #0x4c]
	ldr r3, [r4, #0x50]
	ldr r0, [r4, #0x5c]
	lsls r2, r2, #2
	adds r1, r2, r1
	ldr r1, [r1]
	adds r2, r2, r3
	ldr r2, [r2]
	bl SpellFx_WriteBgMap
	b .L0805695C
.L0805693E:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne .L0805695C
	bl SpellFx_ClearBG1
	ldr r1, .L08056964 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	adds r0, r4, #0
	bl Proc_Break
.L0805695C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08056964: .4byte gEfxBgSemaphore

	thumb_func_start func_fe6_08056968
func_fe6_08056968: @ 0x08056968
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L080569AC @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080569B0 @ =gUnk_085D3434
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	ldr r3, .L080569B4 @ =gUnk_08602FAC
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	str r0, [r4, #0x60]
	ldr r0, .L080569B8 @ =gUnk_081B8E44
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L080569BC @ =gUnk_081B7468
	movs r1, #0x80
	lsls r1, r1, #4
	bl SpellFx_RegisterObjGfx
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080569AC: .4byte gEfxBgSemaphore
.L080569B0: .4byte gUnk_085D3434
.L080569B4: .4byte gUnk_08602FAC
.L080569B8: .4byte gUnk_081B8E44
.L080569BC: .4byte gUnk_081B7468

	thumb_func_start func_fe6_080569C0
func_fe6_080569C0: @ 0x080569C0
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, .L080569F4 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L080569F8 @ =gUnk_085D3454
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	ldr r3, .L080569FC @ =gUnk_086030FC
	str r3, [sp]
	adds r0, r5, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	str r0, [r4, #0x60]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080569F4: .4byte gEfxBgSemaphore
.L080569F8: .4byte gUnk_085D3454
.L080569FC: .4byte gUnk_086030FC

	thumb_func_start func_fe6_08056A00
func_fe6_08056A00: @ 0x08056A00
	push {lr}
	ldr r0, [r0, #0x60]
	bl BasRemove
	ldr r1, .L08056A14 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
.L08056A14: .4byte gEfxBgSemaphore
