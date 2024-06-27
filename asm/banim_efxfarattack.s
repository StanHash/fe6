	.include "macro.inc"

	.syntax unified

	.section .data

	.global ProcScr_efxFarAttack
ProcScr_efxFarAttack: @ 085CB8F0
	.incbin "fe6-base.gba", 0x5CB8F0, (0x5CB918 - 0x5CB8F0) @ length: 0028

	.section .text
	thumb_func_start NewEfxFarAttackWithDistance
NewEfxFarAttackWithDistance: @ 0x08045C90
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	ldr r0, .L08045CAC @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #4
	bhi .L08045D5C
	lsls r0, r0, #2
	ldr r1, .L08045CB0 @ =.L08045CB4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08045CAC: .4byte gEkrDistanceType
.L08045CB0: .4byte .L08045CB4
.L08045CB4: @ jump table
	.4byte .L08045D5C @ case 0
	.4byte .L08045CC8 @ case 1
	.4byte .L08045CC8 @ case 2
	.4byte .L08045D5C @ case 3
	.4byte .L08045D5C @ case 4
.L08045CC8:
	ldr r0, .L08045CFC @ =ProcScr_efxFarAttack
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	adds r0, r5, #0
	bl GetAnimPosition
	adds r2, r4, #0
	adds r2, #0x29
	movs r1, #0
	strb r0, [r2]
	strh r1, [r4, #0x2c]
	lsls r1, r6, #0x10
	asrs r2, r1, #0x10
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	beq .L08045D04
	asrs r0, r1, #0x11
	strh r0, [r4, #0x2e]
	subs r0, r2, r0
	strh r0, [r4, #0x30]
	ldr r2, .L08045D00 @ =gEkrDistanceType
	b .L08045D1E
	.align 2, 0
.L08045CFC: .4byte ProcScr_efxFarAttack
.L08045D00: .4byte gEkrDistanceType
.L08045D04:
	ldr r0, .L08045D14 @ =gEkrDistanceType
	adds r2, r0, #0
	ldrh r0, [r2]
	cmp r0, #1
	bne .L08045D18
	movs r0, #5
	b .L08045D1A
	.align 2, 0
.L08045D14: .4byte gEkrDistanceType
.L08045D18:
	movs r0, #7
.L08045D1A:
	strh r0, [r4, #0x2e]
	strh r0, [r4, #0x30]
.L08045D1E:
	movs r1, #0xf0
	ldrh r2, [r2]
	cmp r2, #1
	bne .L08045D28
	movs r1, #0x20
.L08045D28:
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r2, [r0]
	cmp r2, #0
	bne .L08045D40
	rsbs r0, r1, #0
	strh r0, [r4, #0x32]
	lsrs r0, r0, #1
	strh r0, [r4, #0x34]
	strh r0, [r4, #0x36]
	strh r2, [r4, #0x38]
	b .L08045D4E
.L08045D40:
	movs r0, #0
	strh r0, [r4, #0x32]
	rsbs r1, r1, #0
	lsrs r0, r1, #1
	strh r0, [r4, #0x34]
	strh r0, [r4, #0x36]
	strh r1, [r4, #0x38]
.L08045D4E:
	ldr r1, .L08045D64 @ =gEkrBgPosition
	movs r2, #0x32
	ldrsh r0, [r4, r2]
	str r0, [r1]
	ldr r1, .L08045D68 @ =gEfxFarAttackExist
	movs r0, #1
	str r0, [r1]
.L08045D5C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08045D64: .4byte gEkrBgPosition
.L08045D68: .4byte gEfxFarAttackExist

	thumb_func_start func_fe6_08045D6C
func_fe6_08045D6C: @ 0x08045D6C
	push {r4, r5, lr}
	ldr r3, .L08045D9C @ =gAnims
	ldr r4, [r3]
	rsbs r1, r1, #0
	ldr r2, .L08045DA0 @ =gEkrXPosReal
	ldrh r5, [r2]
	adds r0, r5, r1
	strh r0, [r4, #2]
	ldr r4, [r3, #4]
	ldrh r5, [r2]
	adds r0, r5, r1
	strh r0, [r4, #2]
	ldr r4, [r3, #8]
	ldrh r5, [r2, #2]
	adds r0, r5, r1
	strh r0, [r4, #2]
	ldr r4, [r3, #0xc]
	ldrh r2, [r2, #2]
	adds r1, r2, r1
	strh r1, [r4, #2]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08045D9C: .4byte gAnims
.L08045DA0: .4byte gEkrXPosReal

	thumb_func_start func_fe6_08045DA4
func_fe6_08045DA4: @ 0x08045DA4
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r1, [r4, r0]
	adds r0, r4, #0
	bl func_fe6_08045D6C
	bl GetEkrDragonStateType
	cmp r0, #0
	beq .L08045DC2
	movs r1, #0x32
	ldrsh r0, [r4, r1]
	bl EkrDragonTmCpyExt
.L08045DC2:
	movs r1, #0x32
	ldrsh r0, [r4, r1]
	bl func_fe6_08045EE8
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08045DDC
func_fe6_08045DDC: @ 0x08045DDC
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r1, [r4, r0]
	movs r5, #0x34
	ldrsh r2, [r4, r5]
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r5, #0x2e
	ldrsh r0, [r4, r5]
	str r0, [sp]
	movs r0, #1
	bl Interpolate
	adds r1, r0, #0
	ldr r5, .L08045E4C @ =gEkrBgPosition
	str r1, [r5]
	adds r0, r4, #0
	bl func_fe6_08045D6C
	bl GetEkrDragonStateType
	cmp r0, #0
	beq .L08045E14
	ldr r0, [r5]
	bl EkrDragonTmCpyExt
.L08045E14:
	ldr r0, [r5]
	bl func_fe6_08045EE8
	bl GetBattleAnimArenaFlag
	cmp r0, #0
	beq .L08045E28
	ldr r0, [r5]
	bl func_fe6_0804C50C
.L08045E28:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08045E42
	movs r0, #1
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl Proc_Break
.L08045E42:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08045E4C: .4byte gEkrBgPosition

	thumb_func_start func_fe6_08045E50
func_fe6_08045E50: @ 0x08045E50
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0x36
	ldrsh r1, [r4, r0]
	movs r5, #0x38
	ldrsh r2, [r4, r5]
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r5, #0x30
	ldrsh r0, [r4, r5]
	str r0, [sp]
	movs r0, #4
	bl Interpolate
	adds r1, r0, #0
	ldr r5, .L08045EBC @ =gEkrBgPosition
	str r1, [r5]
	adds r0, r4, #0
	bl func_fe6_08045D6C
	bl GetEkrDragonStateType
	cmp r0, #0
	beq .L08045E88
	ldr r0, [r5]
	bl EkrDragonTmCpyExt
.L08045E88:
	ldr r0, [r5]
	bl func_fe6_08045EE8
	bl GetBattleAnimArenaFlag
	cmp r0, #0
	beq .L08045E9C
	ldr r0, [r5]
	bl func_fe6_0804C50C
.L08045E9C:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x30]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08045ED6
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08045EC4
	ldr r1, .L08045EC0 @ =gEkrInitPosReal
	movs r0, #1
	b .L08045EC8
	.align 2, 0
.L08045EBC: .4byte gEkrBgPosition
.L08045EC0: .4byte gEkrInitPosReal
.L08045EC4:
	ldr r1, .L08045EE0 @ =gEkrInitPosReal
	movs r0, #0
.L08045EC8:
	str r0, [r1]
	ldr r1, .L08045EE4 @ =gEfxFarAttackExist
	movs r0, #0
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L08045ED6:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08045EE0: .4byte gEkrInitPosReal
.L08045EE4: .4byte gEfxFarAttackExist

	thumb_func_start func_fe6_08045EE8
func_fe6_08045EE8: @ 0x08045EE8
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	bl GetEkrDragonStateTypeIdunn
	cmp r0, #0
	bne .L08045F38
	bl GetBattleAnimArenaFlag
	cmp r0, #0
	bne .L08045F38
	asrs r4, r5, #3
	movs r1, #7
	ands r1, r5
	movs r0, #2
	movs r2, #0
	bl SetBgOffset
	lsls r4, r4, #1
	ldr r0, .L08045F40 @ =gTmA_Banim + 0x42
	adds r4, r4, r0
	movs r0, #0x84
	lsls r0, r0, #1
	adds r4, r4, r0
	ldr r2, .L08045F44 @ =gBg2Tm
	movs r0, #0x20
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	subs r0, #0x15
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x42
	movs r3, #0x20
	bl EfxTmCpyExt
	movs r0, #4
	bl EnableBgSync
.L08045F38:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08045F40: .4byte gTmA_Banim + 0x42
.L08045F44: .4byte gBg2Tm
