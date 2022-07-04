
	.include "macro.inc"

	.syntax unified

	thumb_func_start func_fe6_0806AAEC
func_fe6_0806AAEC: @ 0x0806AAEC
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	ldr r3, [r2]
	ldr r0, [r3, #8]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	lsrs r4, r1, #8
	movs r1, #0xff
	lsls r1, r1, #0x10
	ands r1, r0
	lsrs r5, r1, #0x10
	lsrs r1, r0, #0x18
	ldrb r0, [r3, #8]
	ldrb r6, [r2, #0x18]
	cmp r0, r6
	bne .L0806AB28
	movs r0, #0x19
	ldrsb r0, [r2, r0]
	cmp r4, r0
	bne .L0806AB28
	ldr r0, [r3, #4]
	str r0, [r2, #4]
	ldr r0, [r2]
	ldrh r0, [r0, #2]
	str r0, [r2, #8]
	str r5, [r2, #0xc]
	str r1, [r2, #0x10]
	movs r0, #1
	b .L0806AB2A
.L0806AB28:
	movs r0, #0
.L0806AB2A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806AB30
func_fe6_0806AB30: @ 0x0806AB30
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	ldr r3, [r2]
	ldr r0, [r3, #8]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	lsrs r4, r1, #8
	movs r1, #0xff
	lsls r1, r1, #0x10
	ands r1, r0
	lsrs r5, r1, #0x10
	lsrs r1, r0, #0x18
	ldrb r0, [r3, #8]
	ldrb r6, [r2, #0x18]
	cmp r0, r6
	bne .L0806AB6C
	movs r0, #0x19
	ldrsb r0, [r2, r0]
	cmp r4, r0
	bne .L0806AB6C
	ldr r0, [r3, #4]
	str r0, [r2, #4]
	ldr r0, [r2]
	ldrh r0, [r0, #2]
	str r0, [r2, #8]
	str r5, [r2, #0xc]
	str r1, [r2, #0x10]
	movs r0, #1
	b .L0806AB6E
.L0806AB6C:
	movs r0, #0
.L0806AB6E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806AB74
func_fe6_0806AB74: @ 0x0806AB74
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r2, [r4]
	ldr r1, [r2, #8]
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r1
	lsrs r3, r0, #8
	movs r0, #0xff
	lsls r0, r0, #0x10
	ands r1, r0
	lsrs r5, r1, #0x10
	ldrb r2, [r2, #8]
	ldrb r0, [r4, #0x18]
	cmp r2, r0
	bne .L0806ABC8
	movs r0, #0x19
	ldrsb r0, [r4, r0]
	cmp r3, r0
	bne .L0806ABC8
	cmp r5, #0x15
	bne .L0806ABB2
	ldr r0, .L0806ABC4 @ =gActiveUnit
	ldr r0, [r0]
	movs r1, #0x6d
	bl FindUnitItemSlot
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq .L0806ABC8
.L0806ABB2:
	ldr r0, [r4]
	ldr r1, [r0, #4]
	str r1, [r4, #4]
	ldrh r0, [r0, #2]
	str r0, [r4, #8]
	str r5, [r4, #0xc]
	movs r0, #1
	b .L0806ABCA
	.align 2, 0
.L0806ABC4: .4byte gActiveUnit
.L0806ABC8:
	movs r0, #0
.L0806ABCA:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806ABD0
func_fe6_0806ABD0: @ 0x0806ABD0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, .L0806AC28 @ =gActiveUnit
	ldr r2, [r0]
	ldrb r0, [r2, #0xf]
	mov ip, r0
	ldr r3, [r5]
	ldr r1, [r3, #8]
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r1
	lsrs r4, r0, #8
	movs r0, #0xff
	lsls r0, r0, #0x10
	ands r0, r1
	lsrs r7, r0, #0x10
	lsrs r6, r1, #0x18
	movs r0, #8
	ldrsb r0, [r3, r0]
	ldrb r2, [r2, #0xe]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	cmp r0, r2
	bgt .L0806AC2C
	lsls r1, r4, #0x18
	mov r4, ip
	lsls r0, r4, #0x18
	asrs r4, r0, #0x18
	cmp r1, r0
	bgt .L0806AC2C
	lsls r0, r7, #0x18
	asrs r0, r0, #0x18
	cmp r0, r2
	blt .L0806AC2C
	lsls r0, r6, #0x18
	asrs r0, r0, #0x18
	cmp r0, r4
	blt .L0806AC2C
	ldr r0, [r3, #4]
	str r0, [r5, #4]
	ldrh r0, [r3, #2]
	str r0, [r5, #8]
	movs r0, #1
	b .L0806AC2E
	.align 2, 0
.L0806AC28: .4byte gActiveUnit
.L0806AC2C:
	movs r0, #0
.L0806AC2E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806AC34
func_fe6_0806AC34: @ 0x0806AC34
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0806AC58 @ =gPlaySt
	movs r0, #0x40
	ldrb r1, [r1, #0x14]
	ands r0, r1
	cmp r0, #0
	beq .L0806AC5C
	movs r0, #2
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806AC5C
	adds r0, r4, #0
	bl func_fe6_0806ABD0
	b .L0806AC5E
	.align 2, 0
.L0806AC58: .4byte gPlaySt
.L0806AC5C:
	movs r0, #0
.L0806AC5E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806AC64
func_fe6_0806AC64: @ 0x0806AC64
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4]
	ldr r1, [r0, #8]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806AC7C
	movs r0, #0
	b .L0806AC88
.L0806AC7C:
	ldr r0, [r4]
	ldr r1, [r0, #4]
	str r1, [r4, #4]
	ldrh r0, [r0, #2]
	str r0, [r4, #8]
	movs r0, #1
.L0806AC88:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806AC90
func_fe6_0806AC90: @ 0x0806AC90
	adds r3, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r0, [r3, #0x1a]
	cmp r0, r1
	bne .L0806ACB4
	ldrb r0, [r3, #0x1b]
	cmp r0, r2
	bne .L0806ACB4
	ldr r0, [r3]
	ldr r1, [r0, #4]
	str r1, [r3, #4]
	ldrh r0, [r0, #2]
	str r0, [r3, #8]
	movs r0, #1
	b .L0806ACB6
.L0806ACB4:
	movs r0, #0
.L0806ACB6:
	bx lr

	thumb_func_start func_fe6_0806ACB8
func_fe6_0806ACB8: @ 0x0806ACB8
	push {r4, r5, lr}
	adds r5, r1, #0
	adds r4, r2, #0
	ldr r1, .L0806ACE0 @ =gActiveUnit
	ldr r2, [r1]
	movs r1, #0xe
	ldrsb r1, [r2, r1]
	cmp r1, r0
	blt .L0806ACE4
	cmp r1, r4
	bgt .L0806ACE4
	movs r1, #0xf
	ldrsb r1, [r2, r1]
	cmp r1, r5
	blt .L0806ACE4
	cmp r1, r3
	bgt .L0806ACE4
	movs r0, #1
	b .L0806ACE6
	.align 2, 0
.L0806ACE0: .4byte gActiveUnit
.L0806ACE4:
	movs r0, #0
.L0806ACE6:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806ACEC
func_fe6_0806ACEC: @ 0x0806ACEC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r7, r1, #0
	adds r6, r2, #0
	adds r5, r3, #0
	movs r4, #1
.L0806ACFC:
	adds r0, r4, #0
	bl GetUnit
	adds r1, r0, #0
	cmp r1, #0
	beq .L0806AD34
	ldr r0, [r1]
	cmp r0, #0
	beq .L0806AD34
	movs r0, #4
	ldrh r2, [r1, #0xc]
	ands r0, r2
	cmp r0, #0
	bne .L0806AD34
	movs r0, #0xe
	ldrsb r0, [r1, r0]
	cmp r0, r8
	blt .L0806AD34
	cmp r0, r6
	bgt .L0806AD34
	movs r0, #0xf
	ldrsb r0, [r1, r0]
	cmp r0, r7
	blt .L0806AD34
	cmp r0, r5
	bgt .L0806AD34
	movs r0, #1
	b .L0806AD3C
.L0806AD34:
	adds r4, #1
	cmp r4, #0x3f
	ble .L0806ACFC
	movs r0, #0
.L0806AD3C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806AD48
func_fe6_0806AD48: @ 0x0806AD48
	push {lr}
	ldr r0, .L0806AD68 @ =gPlaySt
	ldrb r0, [r0, #0xf]
	cmp r0, #0x80
	bne .L0806AD6C
	movs r0, #0
	movs r1, #0xf
	movs r2, #0x19
	movs r3, #0x17
	bl func_fe6_0806ACEC
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806AD6C
	movs r0, #1
	b .L0806AD6E
	.align 2, 0
.L0806AD68: .4byte gPlaySt
.L0806AD6C:
	movs r0, #0
.L0806AD6E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806AD74
func_fe6_0806AD74: @ 0x0806AD74
	push {lr}
	ldr r0, .L0806ADB8 @ =gPlaySt
	ldrb r0, [r0, #0xf]
	cmp r0, #0x80
	bne .L0806ADB4
	movs r0, #0
	movs r1, #0x18
	movs r2, #0x10
	movs r3, #0x1b
	bl func_fe6_0806ACEC
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806ADBC
	movs r0, #0
	movs r1, #0x15
	movs r2, #2
	movs r3, #0x17
	bl func_fe6_0806ACEC
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806ADBC
	movs r0, #3
	movs r1, #0x14
	movs r2, #5
	movs r3, #0x16
	bl func_fe6_0806ACEC
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806ADBC
.L0806ADB4:
	movs r0, #0
	b .L0806ADBE
	.align 2, 0
.L0806ADB8: .4byte gPlaySt
.L0806ADBC:
	movs r0, #1
.L0806ADBE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806ADC4
func_fe6_0806ADC4: @ 0x0806ADC4
	push {lr}
	movs r0, #0xc
	movs r1, #0x15
	movs r2, #0x1f
	movs r3, #0x18
	bl func_fe6_0806ACEC
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806ADDC
func_fe6_0806ADDC: @ 0x0806ADDC
	push {lr}
	ldr r0, .L0806ADF8 @ =gPlaySt
	ldrb r0, [r0, #0xf]
	cmp r0, #0x80
	bne .L0806ADFC
	movs r0, #0x11
	movs r1, #0x15
	movs r2, #0x1f
	movs r3, #0x23
	bl func_fe6_0806ACEC
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b .L0806ADFE
	.align 2, 0
.L0806ADF8: .4byte gPlaySt
.L0806ADFC:
	movs r0, #0
.L0806ADFE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806AE04
func_fe6_0806AE04: @ 0x0806AE04
	push {lr}
	ldr r0, .L0806AE20 @ =gPlaySt
	ldrb r0, [r0, #0xf]
	cmp r0, #0x80
	bne .L0806AE24
	movs r0, #0
	movs r1, #0xf
	movs r2, #8
	movs r3, #0x12
	bl func_fe6_0806ACEC
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b .L0806AE26
	.align 2, 0
.L0806AE20: .4byte gPlaySt
.L0806AE24:
	movs r0, #0
.L0806AE26:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806AE2C
func_fe6_0806AE2C: @ 0x0806AE2C
	push {lr}
	ldr r0, .L0806AE48 @ =gPlaySt
	ldrb r0, [r0, #0xf]
	cmp r0, #0x80
	bne .L0806AE4C
	movs r0, #0
	movs r1, #0x18
	movs r2, #0xc
	movs r3, #0x1b
	bl func_fe6_0806ACEC
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b .L0806AE4E
	.align 2, 0
.L0806AE48: .4byte gPlaySt
.L0806AE4C:
	movs r0, #0
.L0806AE4E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806AE54
func_fe6_0806AE54: @ 0x0806AE54
	push {lr}
	ldr r0, .L0806AE70 @ =gPlaySt
	ldrb r0, [r0, #0xf]
	cmp r0, #0x80
	bne .L0806AE74
	movs r0, #0x15
	movs r1, #0
	movs r2, #0x1e
	movs r3, #6
	bl func_fe6_0806ACEC
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b .L0806AE76
	.align 2, 0
.L0806AE70: .4byte gPlaySt
.L0806AE74:
	movs r0, #0
.L0806AE76:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806AE7C
func_fe6_0806AE7C: @ 0x0806AE7C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r7, r1, #0
	adds r6, r2, #0
	adds r5, r3, #0
	movs r4, #0x81
.L0806AE8C:
	adds r0, r4, #0
	bl GetUnit
	adds r1, r0, #0
	cmp r1, #0
	beq .L0806AEC4
	ldr r0, [r1]
	cmp r0, #0
	beq .L0806AEC4
	movs r0, #4
	ldrh r2, [r1, #0xc]
	ands r0, r2
	cmp r0, #0
	bne .L0806AEC4
	movs r0, #0xe
	ldrsb r0, [r1, r0]
	cmp r0, r8
	blt .L0806AEC4
	cmp r0, r6
	bgt .L0806AEC4
	movs r0, #0xf
	ldrsb r0, [r1, r0]
	cmp r0, r7
	blt .L0806AEC4
	cmp r0, r5
	bgt .L0806AEC4
	movs r0, #1
	b .L0806AECC
.L0806AEC4:
	adds r4, #1
	cmp r4, #0xbf
	ble .L0806AE8C
	movs r0, #0
.L0806AECC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806AED8
func_fe6_0806AED8: @ 0x0806AED8
	push {lr}
	sub sp, #0x1c
	ldr r0, .L0806AEFC @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl GetChapterEventInfo
	ldr r0, [r0]
	str r0, [sp]
	mov r0, sp
	bl func_fe6_0806A8CC
	cmp r0, #0
	bne .L0806AF00
	movs r0, #0
	b .L0806AF02
	.align 2, 0
.L0806AEFC: .4byte gPlaySt
.L0806AF00:
	movs r0, #1
.L0806AF02:
	add sp, #0x1c
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806AF08
func_fe6_0806AF08: @ 0x0806AF08
	push {lr}
	sub sp, #0x1c
	ldr r0, .L0806AF30 @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl GetChapterEventInfo
	ldr r0, [r0]
	str r0, [sp]
	mov r0, sp
	bl func_fe6_0806A8CC
	cmp r0, #0
	beq .L0806AF44
	mov r0, sp
	bl func_fe6_0806A8AC
	b .L0806AF3A
	.align 2, 0
.L0806AF30: .4byte gPlaySt
.L0806AF34:
	mov r0, sp
	bl func_fe6_0806A8AC
.L0806AF3A:
	mov r0, sp
	bl func_fe6_0806A920
	cmp r0, #0
	bne .L0806AF34
.L0806AF44:
	add sp, #0x1c
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806AF4C
func_fe6_0806AF4C: @ 0x0806AF4C
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldr r0, .L0806AF80 @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl GetChapterEventInfo
	ldr r0, [r0, #4]
	str r0, [sp]
	mov r0, sp
	strb r4, [r0, #0x1a]
	strb r5, [r0, #0x1b]
	bl func_fe6_0806A8CC
	cmp r0, #0
	bne .L0806AF84
	movs r0, #0
	b .L0806AF86
	.align 2, 0
.L0806AF80: .4byte gPlaySt
.L0806AF84:
	movs r0, #1
.L0806AF86:
	add sp, #0x1c
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806AF90
func_fe6_0806AF90: @ 0x0806AF90
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldr r0, .L0806AFCC @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl GetChapterEventInfo
	ldr r0, [r0, #4]
	str r0, [sp]
	mov r0, sp
	strb r4, [r0, #0x1a]
	strb r5, [r0, #0x1b]
	bl func_fe6_0806A8CC
	cmp r0, #0
	beq .L0806AFC4
	mov r0, sp
	bl func_fe6_0806A8AC
.L0806AFC4:
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0806AFCC: .4byte gPlaySt

	thumb_func_start func_fe6_0806AFD0
func_fe6_0806AFD0: @ 0x0806AFD0
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	movs r5, #0
	ldr r1, .L0806AFE0 @ =gUnk_08666CF8
	b .L0806B00E
	.align 2, 0
.L0806AFE0: .4byte gUnk_08666CF8
.L0806AFE4:
	adds r0, r3, #0
	ldrb r3, [r1, #1]
	cmp r0, r6
	bne .L0806AFF0
	cmp r3, r4
	beq .L0806AFF8
.L0806AFF0:
	cmp r3, r6
	bne .L0806B00C
	cmp r0, r4
	bne .L0806B00C
.L0806AFF8:
	cmp r2, #1
	bne .L0806AFFE
	ldr r5, [r1, #4]
.L0806AFFE:
	cmp r2, #2
	bne .L0806B004
	ldr r5, [r1, #8]
.L0806B004:
	cmp r2, #3
	bne .L0806B014
	ldr r5, [r1, #0xc]
	b .L0806B014
.L0806B00C:
	adds r1, #0x10
.L0806B00E:
	ldrb r3, [r1]
	cmp r3, #0
	bne .L0806AFE4
.L0806B014:
	cmp r5, #0
	beq .L0806B022
	adds r0, r5, #0
	bl StartTalkSupportEvent
	bl DisableEventSkip
.L0806B022:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806B028
func_fe6_0806B028: @ 0x0806B028
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldr r0, .L0806B05C @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl GetChapterEventInfo
	ldr r0, [r0, #8]
	str r0, [sp]
	mov r0, sp
	strb r4, [r0, #0x18]
	strb r5, [r0, #0x19]
	bl func_fe6_0806A8CC
	cmp r0, #0
	beq .L0806B060
	ldr r0, [sp, #0xc]
	b .L0806B062
	.align 2, 0
.L0806B05C: .4byte gPlaySt
.L0806B060:
	movs r0, #0
.L0806B062:
	add sp, #0x1c
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806B06C
func_fe6_0806B06C: @ 0x0806B06C
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldr r0, .L0806B0B0 @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl GetChapterEventInfo
	ldr r0, [r0, #8]
	str r0, [sp]
	mov r0, sp
	strb r4, [r0, #0x18]
	strb r5, [r0, #0x19]
	bl func_fe6_0806A8CC
	cmp r0, #0
	bne .L0806B09C
	b .L0806B24A
.L0806B09C:
	ldr r0, [sp, #0xc]
	cmp r0, #0x1d
	bls .L0806B0A4
	b .L0806B24A
.L0806B0A4:
	lsls r0, r0, #2
	ldr r1, .L0806B0B4 @ =.L0806B0B8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0806B0B0: .4byte gPlaySt
.L0806B0B4: .4byte .L0806B0B8
.L0806B0B8: @ jump table
	.4byte .L0806B248 @ case 0
	.4byte .L0806B24A @ case 1
	.4byte .L0806B24A @ case 2
	.4byte .L0806B24A @ case 3
	.4byte .L0806B24A @ case 4
	.4byte .L0806B24A @ case 5
	.4byte .L0806B24A @ case 6
	.4byte .L0806B24A @ case 7
	.4byte .L0806B24A @ case 8
	.4byte .L0806B24A @ case 9
	.4byte .L0806B24A @ case 10
	.4byte .L0806B24A @ case 11
	.4byte .L0806B24A @ case 12
	.4byte .L0806B24A @ case 13
	.4byte .L0806B130 @ case 14
	.4byte .L0806B130 @ case 15
	.4byte .L0806B160 @ case 16
	.4byte .L0806B160 @ case 17
	.4byte .L0806B192 @ case 18
	.4byte .L0806B214 @ case 19
	.4byte .L0806B224 @ case 20
	.4byte .L0806B234 @ case 21
	.4byte .L0806B244 @ case 22
	.4byte .L0806B24A @ case 23
	.4byte .L0806B24A @ case 24
	.4byte .L0806B24A @ case 25
	.4byte .L0806B24A @ case 26
	.4byte .L0806B24A @ case 27
	.4byte .L0806B24A @ case 28
	.4byte .L0806B13E @ case 29
.L0806B130:
	mov r0, sp
	bl func_fe6_0806A8AC
	ldr r0, [sp, #0x10]
	cmp r0, #3
	beq .L0806B13E
	b .L0806B24A
.L0806B13E:
	mov r0, sp
	ldrb r0, [r0, #0x18]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r1, sp
	ldrb r1, [r1, #0x19]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	bl GetMapChangeIdAt
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl StartMapChangeEvent
.L0806B15A:
	bl DisableEventSkip
	b .L0806B24A
.L0806B160:
	ldr r0, [sp, #4]
	cmp r0, #1
	bne .L0806B18A
	mov r0, sp
	ldrb r0, [r0, #0x18]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r1, sp
	ldrb r1, [r1, #0x19]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	bl GetMapChangeIdAt
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl StartMapChangeEvent
	ldr r0, [sp, #8]
	bl SetEid
	b .L0806B15A
.L0806B18A:
	mov r0, sp
	bl func_fe6_0806A8AC
	b .L0806B15A
.L0806B192:
	ldr r4, [sp, #0x14]
	cmp r4, #0
	bne .L0806B1BC
	mov r0, sp
	ldrb r0, [r0, #0x18]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r1, sp
	ldrb r1, [r1, #0x19]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	bl GetMapChangeIdAt
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl StartMapChangeEvent
	mov r0, sp
	bl func_fe6_0806A8AC
	b .L0806B208
.L0806B1BC:
	cmp r4, #0x6f
	beq .L0806B1E6
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r0, sp
	ldrb r0, [r0, #0x18]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r1, sp
	ldrb r1, [r1, #0x19]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	bl GetMapChangeIdAt
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl StartChestItemEvent
	b .L0806B208
.L0806B1E6:
	ldr r4, [sp, #0x10]
	mov r0, sp
	ldrb r0, [r0, #0x18]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r1, sp
	ldrb r1, [r1, #0x19]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	bl GetMapChangeIdAt
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl StartChestMoneyEvent
.L0806B208:
	bl DisableEventSkip
	ldr r0, [sp, #8]
	bl SetEid
	b .L0806B24A
.L0806B214:
	ldr r0, .L0806B220 @ =gActiveUnit
	ldr r0, [r0]
	ldr r1, [sp, #4]
	bl func_fe6_08095E10
	b .L0806B24A
	.align 2, 0
.L0806B220: .4byte gActiveUnit
.L0806B224:
	ldr r0, .L0806B230 @ =gActiveUnit
	ldr r0, [r0]
	ldr r1, [sp, #4]
	bl func_fe6_08095E30
	b .L0806B24A
	.align 2, 0
.L0806B230: .4byte gActiveUnit
.L0806B234:
	ldr r0, .L0806B240 @ =gActiveUnit
	ldr r0, [r0]
	ldr r1, [sp, #4]
	bl func_fe6_08095E50
	b .L0806B24A
	.align 2, 0
.L0806B240: .4byte gActiveUnit
.L0806B244:
	mov r8, r8
	b .L0806B24A
.L0806B248:
	mov r8, r8
.L0806B24A:
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806B254
func_fe6_0806B254: @ 0x0806B254
	push {lr}
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	bl func_fe6_0806B06C
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806B268
func_fe6_0806B268: @ 0x0806B268
	push {lr}
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	bl func_fe6_0806B028
	cmp r0, #0xe
	beq .L0806B27E
	movs r0, #0
	b .L0806B280
.L0806B27E:
	movs r0, #1
.L0806B280:
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806B284
func_fe6_0806B284: @ 0x0806B284
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	asrs r5, r0, #0x18
	lsls r1, r1, #0x18
	asrs r4, r1, #0x18
	adds r0, r5, #0
	adds r1, r4, #0
	bl func_fe6_0806B268
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806B2A4
	adds r0, r5, #0
	adds r1, r4, #0
	bl func_fe6_0806B06C
.L0806B2A4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806B2AC
func_fe6_0806B2AC: @ 0x0806B2AC
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r6, r0, #0x18
	asrs r5, r0, #0x18
	lsrs r7, r1, #0x18
	asrs r4, r1, #0x18
	adds r0, r5, #0
	adds r1, r4, #0
	bl func_fe6_0806B028
	cmp r0, #0x13
	beq .L0806B308
	adds r0, r5, #0
	adds r1, r4, #0
	bl func_fe6_0806B028
	cmp r0, #0x14
	beq .L0806B308
	adds r0, r5, #0
	adds r1, r4, #0
	bl func_fe6_0806B028
	cmp r0, #0x15
	bne .L0806B2F0
	ldr r0, .L0806B304 @ =gActiveUnit
	ldr r0, [r0]
	movs r1, #0x6d
	bl FindUnitItemSlot
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bne .L0806B308
.L0806B2F0:
	lsls r0, r6, #0x18
	asrs r0, r0, #0x18
	lsls r1, r7, #0x18
	asrs r1, r1, #0x18
	bl func_fe6_0806B028
	cmp r0, #0x16
	beq .L0806B308
	movs r0, #0
	b .L0806B30A
	.align 2, 0
.L0806B304: .4byte gActiveUnit
.L0806B308:
	movs r0, #1
.L0806B30A:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806B310
func_fe6_0806B310: @ 0x0806B310
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	asrs r5, r0, #0x18
	lsls r1, r1, #0x18
	asrs r4, r1, #0x18
	adds r0, r5, #0
	adds r1, r4, #0
	bl func_fe6_0806B2AC
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806B330
	adds r0, r5, #0
	adds r1, r4, #0
	bl func_fe6_0806B06C
.L0806B330:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start IsThereClosedChestAt
IsThereClosedChestAt: @ 0x0806B338
	push {lr}
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	bl func_fe6_0806B028
	cmp r0, #0x12
	beq .L0806B34E
	movs r0, #0
	b .L0806B350
.L0806B34E:
	movs r0, #1
.L0806B350:
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806B354
func_fe6_0806B354: @ 0x0806B354
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	asrs r5, r0, #0x18
	lsls r1, r1, #0x18
	asrs r4, r1, #0x18
	adds r0, r5, #0
	adds r1, r4, #0
	bl IsThereClosedChestAt
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806B374
	adds r0, r5, #0
	adds r1, r4, #0
	bl func_fe6_0806B06C
.L0806B374:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806B37C
func_fe6_0806B37C: @ 0x0806B37C
	push {lr}
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	bl func_fe6_0806B028
	cmp r0, #0x10
	beq .L0806B392
	movs r0, #0
	b .L0806B394
.L0806B392:
	movs r0, #1
.L0806B394:
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806B398
func_fe6_0806B398: @ 0x0806B398
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	asrs r5, r0, #0x18
	lsls r1, r1, #0x18
	asrs r4, r1, #0x18
	adds r0, r5, #0
	adds r1, r4, #0
	bl func_fe6_0806B37C
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806B3B8
	adds r0, r5, #0
	adds r1, r4, #0
	bl func_fe6_0806B06C
.L0806B3B8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806B3C0
func_fe6_0806B3C0: @ 0x0806B3C0
	push {lr}
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	bl func_fe6_0806B028
	cmp r0, #0x11
	beq .L0806B3D6
	movs r0, #0
	b .L0806B3D8
.L0806B3D6:
	movs r0, #1
.L0806B3D8:
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806B3DC
func_fe6_0806B3DC: @ 0x0806B3DC
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	asrs r5, r0, #0x18
	lsls r1, r1, #0x18
	asrs r4, r1, #0x18
	adds r0, r5, #0
	adds r1, r4, #0
	bl func_fe6_0806B3C0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806B3FC
	adds r0, r5, #0
	adds r1, r4, #0
	bl func_fe6_0806B06C
.L0806B3FC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806B404
func_fe6_0806B404: @ 0x0806B404
	push {lr}
	bl func_fe6_0806B580
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0806B414
func_fe6_0806B414: @ 0x0806B414
	push {lr}
	bl func_fe6_0806B5B0
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806B420
func_fe6_0806B420: @ 0x0806B420
	push {lr}
	ldr r0, .L0806B438 @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne .L0806B432
	bl func_fe6_0806C6B0
.L0806B432:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
.L0806B438: .4byte gPlaySt

	thumb_func_start func_fe6_0806B43C
func_fe6_0806B43C: @ 0x0806B43C
	push {lr}
	sub sp, #0x1c
	ldr r0, .L0806B460 @ =gUnk_086676E0
	str r0, [sp]
	ldr r0, .L0806B464 @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne .L0806B468
	mov r0, sp
	bl func_fe6_0806A8CC
	cmp r0, #0
	beq .L0806B468
	movs r0, #1
	b .L0806B46A
	.align 2, 0
.L0806B460: .4byte gUnk_086676E0
.L0806B464: .4byte gPlaySt
.L0806B468:
	movs r0, #0
.L0806B46A:
	add sp, #0x1c
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806B470
func_fe6_0806B470: @ 0x0806B470
	push {lr}
	sub sp, #0x1c
	ldr r0, .L0806B49C @ =gUnk_086676E0
	str r0, [sp]
	ldr r0, .L0806B4A0 @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne .L0806B494
	mov r0, sp
	bl func_fe6_0806A8CC
	cmp r0, #0
	beq .L0806B494
	mov r0, sp
	bl func_fe6_0806A8AC
.L0806B494:
	movs r0, #0
	add sp, #0x1c
	pop {r1}
	bx r1
	.align 2, 0
.L0806B49C: .4byte gUnk_086676E0
.L0806B4A0: .4byte gPlaySt

	thumb_func_start func_fe6_0806B4A4
func_fe6_0806B4A4: @ 0x0806B4A4
	movs r0, #0
	bx lr

	thumb_func_start func_fe6_0806B4A8
func_fe6_0806B4A8: @ 0x0806B4A8
	movs r0, #0
	bx lr

	thumb_func_start func_fe6_0806B4AC
func_fe6_0806B4AC: @ 0x0806B4AC
	push {lr}
	ldr r0, .L0806B4C4 @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne .L0806B4BE
	bl func_fe6_0806C718
.L0806B4BE:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
.L0806B4C4: .4byte gPlaySt

	thumb_func_start func_fe6_0806B4C8
func_fe6_0806B4C8: @ 0x0806B4C8
	push {lr}
	ldr r0, .L0806B4E0 @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne .L0806B4DA
	bl func_fe6_0806C734
.L0806B4DA:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
.L0806B4E0: .4byte gPlaySt

	thumb_func_start func_fe6_0806B4E4
func_fe6_0806B4E4: @ 0x0806B4E4
	push {lr}
	ldr r0, .L0806B4FC @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne .L0806B4F6
	bl func_fe6_0806C750
.L0806B4F6:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
.L0806B4FC: .4byte gPlaySt

	thumb_func_start func_fe6_0806B500
func_fe6_0806B500: @ 0x0806B500
	push {lr}
	sub sp, #0x1c
	ldr r0, .L0806B530 @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl GetChapterEventInfo
	ldr r0, [r0, #0xc]
	str r0, [sp]
	mov r1, sp
	ldr r0, .L0806B534 @ =gActiveUnit
	ldr r2, [r0]
	ldrb r0, [r2, #0xe]
	strb r0, [r1, #0x18]
	ldrb r0, [r2, #0xf]
	strb r0, [r1, #0x19]
	mov r0, sp
	bl func_fe6_0806A8CC
	cmp r0, #0
	bne .L0806B538
	movs r0, #0
	b .L0806B53A
	.align 2, 0
.L0806B530: .4byte gPlaySt
.L0806B534: .4byte gActiveUnit
.L0806B538:
	movs r0, #1
.L0806B53A:
	add sp, #0x1c
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806B540
func_fe6_0806B540: @ 0x0806B540
	push {lr}
	sub sp, #0x1c
	ldr r0, .L0806B578 @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl GetChapterEventInfo
	ldr r0, [r0, #0xc]
	str r0, [sp]
	mov r1, sp
	ldr r0, .L0806B57C @ =gActiveUnit
	ldr r2, [r0]
	ldrb r0, [r2, #0xe]
	strb r0, [r1, #0x18]
	ldrb r0, [r2, #0xf]
	strb r0, [r1, #0x19]
	mov r0, sp
	bl func_fe6_0806A8CC
	cmp r0, #0
	beq .L0806B572
	mov r0, sp
	bl func_fe6_0806A8AC
.L0806B572:
	add sp, #0x1c
	pop {r0}
	bx r0
	.align 2, 0
.L0806B578: .4byte gPlaySt
.L0806B57C: .4byte gActiveUnit

	thumb_func_start func_fe6_0806B580
func_fe6_0806B580: @ 0x0806B580
	push {lr}
	ldr r0, .L0806B5AC @ =gPlaySt
	ldrb r0, [r0, #0xe]
	cmp r0, #0x19
	bne .L0806B59C
	movs r0, #0x72
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806B59C
	movs r0, #3
	bl SetEid
.L0806B59C:
	movs r0, #3
	bl CheckFlag
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0
.L0806B5AC: .4byte gPlaySt

	thumb_func_start func_fe6_0806B5B0
func_fe6_0806B5B0: @ 0x0806B5B0
	push {r4, lr}
	movs r0, #3
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806B5FC
	ldr r4, .L0806B5E0 @ =gPlaySt
	ldrb r0, [r4, #0xe]
	cmp r0, #0x19
	bne .L0806B5E4
	bl func_fe6_0806CD78
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806B5FC
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	bl GetChapterEventInfo
	ldr r0, [r0, #0x18]
	bl StartEvent
	b .L0806B5FC
	.align 2, 0
.L0806B5E0: .4byte gPlaySt
.L0806B5E4:
	bl func_fe6_0806B404
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806B5FC
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	bl GetChapterEventInfo
	ldr r0, [r0, #0x18]
	bl StartEvent
.L0806B5FC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806B604
func_fe6_0806B604: @ 0x0806B604
	push {lr}
	sub sp, #0x1c
	ldr r0, .L0806B634 @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl GetChapterEventInfo
	ldr r0, [r0, #0x10]
	str r0, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	bl BatchCreateUnits
	bl func_fe6_0806BAF0
	bl RefreshEntityMaps
	bl RefreshUnitSprites
	add sp, #0x1c
	pop {r0}
	bx r0
	.align 2, 0
.L0806B634: .4byte gPlaySt

	thumb_func_start func_fe6_0806B638
func_fe6_0806B638: @ 0x0806B638
	push {lr}
	ldr r0, .L0806B64C @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl GetChapterEventInfo
	ldr r0, [r0, #0x14]
	pop {r1}
	bx r1
	.align 2, 0
.L0806B64C: .4byte gPlaySt

	thumb_func_start func_fe6_0806B650
func_fe6_0806B650: @ 0x0806B650
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r4, .L0806B660 @ =gUnk_086663CC
	b .L0806B6A2
	.align 2, 0
.L0806B660: .4byte gUnk_086663CC
.L0806B664:
	ldr r0, [r4, #8]
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806B6A0
	ldrb r1, [r4]
	ldrb r0, [r4, #1]
	cmp r6, r1
	bne .L0806B67C
	cmp r5, r0
	beq .L0806B684
.L0806B67C:
	cmp r6, r0
	bne .L0806B6A0
	cmp r5, r1
	bne .L0806B6A0
.L0806B684:
	ldrb r0, [r4, #2]
	cmp r0, #0x2d
	beq .L0806B698
	ldr r0, .L0806B69C @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrb r1, [r4, #2]
	cmp r0, r1
	bne .L0806B6A0
.L0806B698:
	adds r0, r4, #0
	b .L0806B6AA
	.align 2, 0
.L0806B69C: .4byte gPlaySt
.L0806B6A0:
	adds r4, #0xc
.L0806B6A2:
	ldrb r0, [r4, #1]
	cmp r0, #0
	bne .L0806B664
	movs r0, #0
.L0806B6AA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806B6B0
func_fe6_0806B6B0: @ 0x0806B6B0
	push {r4, r5, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b .L0806B6EA
.L0806B6BA:
	ldr r0, [r4, #8]
	bl CheckFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0806B6E8
	ldrb r0, [r4]
	cmp r5, r0
	bne .L0806B6E8
	ldrb r1, [r4, #1]
	cmp r1, #0x2d
	beq .L0806B6E0
	ldr r0, .L0806B6E4 @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrb r1, [r4, #1]
	cmp r0, r1
	bne .L0806B6E8
.L0806B6E0:
	adds r0, r4, #0
	b .L0806B6F2
	.align 2, 0
.L0806B6E4: .4byte gPlaySt
.L0806B6E8:
	adds r4, #0x10
.L0806B6EA:
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0806B6BA
	movs r0, #0
.L0806B6F2:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806B6F8
func_fe6_0806B6F8: @ 0x0806B6F8
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r7, r4, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r5, r1, #0
	adds r0, r4, #0
	bl func_fe6_0806B650
	cmp r0, #0
	bne .L0806B740
	ldr r6, .L0806B744 @ =gUnk_0866618C
	adds r0, r4, #0
	adds r1, r6, #0
	bl func_fe6_0806B6B0
	cmp r0, #0
	bne .L0806B740
	adds r0, r5, #0
	adds r1, r6, #0
	bl func_fe6_0806B6B0
	cmp r0, #0
	bne .L0806B740
	ldr r1, .L0806B748 @ =gUnk_08666528
	adds r0, r7, #0
	bl func_fe6_0806B6B0
	cmp r0, #0
	beq .L0806B74C
	bl BattleIsTriangleAttack
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806B74C
.L0806B740:
	movs r0, #1
	b .L0806B74E
	.align 2, 0
.L0806B744: .4byte gUnk_0866618C
.L0806B748: .4byte gUnk_08666528
.L0806B74C:
	movs r0, #0
.L0806B74E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806B754
func_fe6_0806B754: @ 0x0806B754
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	mov r8, r5
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r6, r1, #0
	adds r0, r5, #0
	bl func_fe6_0806B650
	adds r4, r0, #0
	cmp r4, #0
	bne .L0806B790
	ldr r7, .L0806B7A4 @ =gUnk_0866618C
	adds r0, r5, #0
	adds r1, r7, #0
	bl func_fe6_0806B6B0
	adds r4, r0, #0
	cmp r4, #0
	bne .L0806B790
	adds r0, r6, #0
	adds r1, r7, #0
	bl func_fe6_0806B6B0
	adds r4, r0, #0
	cmp r4, #0
	beq .L0806B7A8
.L0806B790:
	ldr r0, [r4, #4]
	bl StartTalkEvent
	bl DisableEventSkip
	ldr r0, [r4, #8]
	bl SetEid
	b .L0806B7D0
	.align 2, 0
.L0806B7A4: .4byte gUnk_0866618C
.L0806B7A8:
	ldr r1, .L0806B7DC @ =gUnk_08666528
	mov r0, r8
	bl func_fe6_0806B6B0
	adds r4, r0, #0
	cmp r4, #0
	beq .L0806B7D0
	bl BattleIsTriangleAttack
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806B7D0
	ldr r0, [r4, #4]
	bl StartTalkEvent
	bl DisableEventSkip
	ldr r0, [r4, #8]
	bl SetEid
.L0806B7D0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0806B7DC: .4byte gUnk_08666528

	thumb_func_start ShouldDisplayDeathQuote
ShouldDisplayDeathQuote: @ 0x0806B7E0
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r1, .L0806B7FC @ =gUnk_08666598
	adds r0, r4, #0
	bl func_fe6_0806B6B0
	cmp r0, #0
	bne .L0806B800
	cmp r4, #1
	beq .L0806B800
	movs r0, #0
	b .L0806B802
	.align 2, 0
.L0806B7FC: .4byte gUnk_08666598
.L0806B800:
	movs r0, #1
.L0806B802:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0806B808
func_fe6_0806B808: @ 0x0806B808
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r1, .L0806B88C @ =gUnk_08666598
	adds r0, r5, #0
	bl func_fe6_0806B6B0
	adds r4, r0, #0
	cmp r4, #0
	beq .L0806B848
	ldr r0, [r4, #4]
	cmp r0, #0
	beq .L0806B826
	bl StartTalkEvent
.L0806B826:
	bl DisableEventSkip
	ldr r0, [r4, #8]
	bl SetEid
	adds r0, r5, #0
	bl GetUnitByPid
	movs r1, #0xc0
	ldrb r0, [r0, #0xb]
	ands r1, r0
	cmp r1, #0
	bne .L0806B848
	movs r0, #0x45
	movs r1, #0
	bl StartBgm
.L0806B848:
	ldr r0, .L0806B890 @ =gPlaySt
	ldrb r0, [r0, #0xe]
	cmp r0, #0x19
	bne .L0806B85A
	cmp r5, #0x66
	bne .L0806B85A
	movs r0, #4
	bl FadeBgmOut
.L0806B85A:
	cmp r5, #1
	bne .L0806B884
	movs r0, #0x65
	bl SetEid
	ldr r4, .L0806B890 @ =gPlaySt
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	cmp r0, #0
	beq .L0806B87C
	ldr r0, .L0806B894 @ =gUnk_0866AAF8
	bl StartEvent
	movs r0, #0x37
	movs r1, #0
	bl StartBgm
.L0806B87C:
	movs r0, #1
	ldrb r1, [r4, #0x1d]
	orrs r0, r1
	strb r0, [r4, #0x1d]
.L0806B884:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0806B88C: .4byte gUnk_08666598
.L0806B890: .4byte gPlaySt
.L0806B894: .4byte gUnk_0866AAF8

	thumb_func_start func_fe6_0806B898
func_fe6_0806B898: @ 0x0806B898
	movs r0, #0
	bx lr

	thumb_func_start func_fe6_0806B89C
func_fe6_0806B89C: @ 0x0806B89C
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0806B8A0
func_fe6_0806B8A0: @ 0x0806B8A0
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0806B8A4
func_fe6_0806B8A4: @ 0x0806B8A4
	movs r0, #0
	bx lr

	thumb_func_start func_fe6_0806B8A8
func_fe6_0806B8A8: @ 0x0806B8A8
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0806B8AC
func_fe6_0806B8AC: @ 0x0806B8AC
	movs r0, #0
	bx lr

	thumb_func_start func_fe6_0806B8B0
func_fe6_0806B8B0: @ 0x0806B8B0
	movs r0, #0
	bx lr

	thumb_func_start func_fe6_0806B8B4
func_fe6_0806B8B4: @ 0x0806B8B4
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0806B8B8
func_fe6_0806B8B8: @ 0x0806B8B8
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0806B8BC
func_fe6_0806B8BC: @ 0x0806B8BC
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0806B8C0
func_fe6_0806B8C0: @ 0x0806B8C0
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0806B8C4
func_fe6_0806B8C4: @ 0x0806B8C4
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0806B8C8
func_fe6_0806B8C8: @ 0x0806B8C8
	adds r3, r0, #0
	cmp r3, #0
	beq .L0806B8F0
	subs r3, #1
	ldr r1, .L0806B8F4 @ =0x03004898
	adds r0, r3, #0
	cmp r3, #0
	bge .L0806B8DA
	adds r0, r3, #7
.L0806B8DA:
	asrs r0, r0, #3
	adds r2, r0, r1
	ldr r1, .L0806B8F8 @ =gUnk_08666184
	lsls r0, r0, #3
	subs r0, r3, r0
	adds r0, r0, r1
	ldrb r1, [r2]
	ldrb r0, [r0]
	orrs r1, r0
	adds r0, r1, #0
	strb r0, [r2]
.L0806B8F0:
	bx lr
	.align 2, 0
.L0806B8F4: .4byte 0x03004898
.L0806B8F8: .4byte gUnk_08666184

	thumb_func_start CheckChapterEid
CheckChapterEid: @ 0x0806B8FC
	adds r3, r0, #0
	cmp r3, #0
	beq .L0806B926
	subs r3, #1
	ldr r1, .L0806B92C @ =0x03004898
	adds r0, r3, #0
	cmp r3, #0
	bge .L0806B90E
	adds r0, r3, #7
.L0806B90E:
	asrs r0, r0, #3
	adds r2, r0, r1
	ldr r1, .L0806B930 @ =gUnk_08666184
	lsls r0, r0, #3
	subs r0, r3, r0
	adds r0, r0, r1
	ldrb r2, [r2]
	ldrb r0, [r0]
	ands r2, r0
	adds r0, r2, #0
	cmp r0, #0
	bne .L0806B934
.L0806B926:
	movs r0, #0
	b .L0806B936
	.align 2, 0
.L0806B92C: .4byte 0x03004898
.L0806B930: .4byte gUnk_08666184
.L0806B934:
	movs r0, #1
.L0806B936:
	bx lr

	thumb_func_start func_fe6_0806B938
func_fe6_0806B938: @ 0x0806B938
	adds r2, r0, #0
	cmp r2, #0
	beq .L0806B966
	subs r2, #1
	ldr r3, .L0806B968 @ =gUnk_08666184
	adds r1, r2, #0
	cmp r2, #0
	bge .L0806B94A
	adds r1, r2, #7
.L0806B94A:
	asrs r1, r1, #3
	lsls r0, r1, #3
	subs r0, r2, r0
	adds r0, r0, r3
	ldrb r0, [r0]
	mvns r0, r0
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r0, .L0806B96C @ =0x03004898
	adds r1, r1, r0
	adds r0, r3, #0
	ldrb r2, [r1]
	ands r0, r2
	strb r0, [r1]
.L0806B966:
	bx lr
	.align 2, 0
.L0806B968: .4byte gUnk_08666184
.L0806B96C: .4byte 0x03004898

	thumb_func_start func_fe6_0806B970
func_fe6_0806B970: @ 0x0806B970
	ldr r1, .L0806B980 @ =0x03004898
	movs r2, #0
	adds r0, r1, #3
.L0806B976:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge .L0806B976
	bx lr
	.align 2, 0
.L0806B980: .4byte 0x03004898

	thumb_func_start func_fe6_0806B984
func_fe6_0806B984: @ 0x0806B984
	adds r3, r0, #0
	cmp r3, #0x63
	ble .L0806B9B0
	cmp r3, #0x64
	beq .L0806B9B0
	subs r3, #0x65
	ldr r1, .L0806B9B4 @ =0x03004890
	adds r0, r3, #0
	cmp r3, #0
	bge .L0806B99A
	adds r0, r3, #7
.L0806B99A:
	asrs r0, r0, #3
	adds r2, r0, r1
	ldr r1, .L0806B9B8 @ =gUnk_08666184
	lsls r0, r0, #3
	subs r0, r3, r0
	adds r0, r0, r1
	ldrb r1, [r2]
	ldrb r0, [r0]
	orrs r1, r0
	adds r0, r1, #0
	strb r0, [r2]
.L0806B9B0:
	bx lr
	.align 2, 0
.L0806B9B4: .4byte 0x03004890
.L0806B9B8: .4byte gUnk_08666184

	thumb_func_start CheckGlobalEid
CheckGlobalEid: @ 0x0806B9BC
	adds r3, r0, #0
	cmp r3, #0x64
	ble .L0806B9E6
	subs r3, #0x65
	ldr r1, .L0806B9EC @ =0x03004890
	adds r0, r3, #0
	cmp r3, #0
	bge .L0806B9CE
	adds r0, r3, #7
.L0806B9CE:
	asrs r0, r0, #3
	adds r2, r0, r1
	ldr r1, .L0806B9F0 @ =gUnk_08666184
	lsls r0, r0, #3
	subs r0, r3, r0
	adds r0, r0, r1
	ldrb r2, [r2]
	ldrb r0, [r0]
	ands r2, r0
	adds r0, r2, #0
	cmp r0, #0
	bne .L0806B9F4
.L0806B9E6:
	movs r0, #0
	b .L0806B9F6
	.align 2, 0
.L0806B9EC: .4byte 0x03004890
.L0806B9F0: .4byte gUnk_08666184
.L0806B9F4:
	movs r0, #1
.L0806B9F6:
	bx lr

	thumb_func_start func_fe6_0806B9F8
func_fe6_0806B9F8: @ 0x0806B9F8
	adds r2, r0, #0
	cmp r2, #0x63
	ble .L0806BA2A
	cmp r2, #0x64
	beq .L0806BA2A
	subs r2, #0x65
	ldr r3, .L0806BA2C @ =gUnk_08666184
	adds r1, r2, #0
	cmp r2, #0
	bge .L0806BA0E
	adds r1, r2, #7
.L0806BA0E:
	asrs r1, r1, #3
	lsls r0, r1, #3
	subs r0, r2, r0
	adds r0, r0, r3
	ldrb r0, [r0]
	mvns r0, r0
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r0, .L0806BA30 @ =0x03004890
	adds r1, r1, r0
	adds r0, r3, #0
	ldrb r2, [r1]
	ands r0, r2
	strb r0, [r1]
.L0806BA2A:
	bx lr
	.align 2, 0
.L0806BA2C: .4byte gUnk_08666184
.L0806BA30: .4byte 0x03004890

	thumb_func_start func_fe6_0806BA34
func_fe6_0806BA34: @ 0x0806BA34
	ldr r1, .L0806BA44 @ =0x03004890
	movs r2, #0
	adds r0, r1, #4
.L0806BA3A:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge .L0806BA3A
	bx lr
	.align 2, 0
.L0806BA44: .4byte 0x03004890

	thumb_func_start SetEid
SetEid: @ 0x0806BA48
	push {lr}
	cmp r0, #0x63
	bgt .L0806BA54
	bl func_fe6_0806B8C8
	b .L0806BA58
.L0806BA54:
	bl func_fe6_0806B984
.L0806BA58:
	pop {r0}
	bx r0

	thumb_func_start CheckFlag
CheckFlag: @ 0x0806BA5C
	push {lr}
	cmp r0, #0x63
	ble .L0806BA68
	bl CheckGlobalEid
	b .L0806BA6C
.L0806BA68:
	bl CheckChapterEid
.L0806BA6C:
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1

	thumb_func_start ClearEid
ClearEid: @ 0x0806BA74
	push {lr}
	cmp r0, #0x63
	bgt .L0806BA80
	bl func_fe6_0806B938
	b .L0806BA84
.L0806BA80:
	bl func_fe6_0806B9F8
.L0806BA84:
	pop {r0}
	bx r0

	thumb_func_start GetGlobalEidData
GetGlobalEidData: @ 0x0806BA88
	ldr r0, .L0806BA8C @ =0x03004890
	bx lr
	.align 2, 0
.L0806BA8C: .4byte 0x03004890

	thumb_func_start func_fe6_0806BA90
func_fe6_0806BA90: @ 0x0806BA90
	movs r0, #5
	bx lr

	thumb_func_start GetChapterEidData
GetChapterEidData: @ 0x0806BA94
	ldr r0, .L0806BA98 @ =0x03004898
	bx lr
	.align 2, 0
.L0806BA98: .4byte 0x03004898

	thumb_func_start func_fe6_0806BA9C
func_fe6_0806BA9C: @ 0x0806BA9C
	movs r0, #4
	bx lr
