	.include "macro.inc"

	.syntax unified

	thumb_func_start func_fe6_080741EC
func_fe6_080741EC: @ 0x080741EC
	push {r4, r5, r6, lr}
	ldr r0, .L08074248 @ =0x0200D6B4
	bl UnitRearrangeInit
	movs r4, #0
	ldr r0, .L0807424C @ =0x0200CD38
	ldrb r1, [r0]
	cmp r4, r1
	bge .L08074212
	ldr r6, .L08074250 @ =0x0200CC38
	adds r5, r0, #0
.L08074202:
	ldm r6!, {r0}
	ldr r0, [r0]
	bl UnitRearrangeAdd
	adds r4, #1
	ldrb r2, [r5]
	cmp r4, r2
	blt .L08074202
.L08074212:
	movs r4, #1
.L08074214:
	adds r0, r4, #0
	bl GetUnit
	adds r1, r0, #0
	cmp r1, #0
	beq .L08074236
	ldr r0, [r1]
	cmp r0, #0
	beq .L08074236
	movs r0, #4
	ldrh r2, [r1, #0xc]
	ands r0, r2
	cmp r0, #0
	beq .L08074236
	adds r0, r1, #0
	bl UnitRearrangeAdd
.L08074236:
	adds r4, #1
	cmp r4, #0x3f
	ble .L08074214
	bl UnitRearrangeApply
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08074248: .4byte 0x0200D6B4
.L0807424C: .4byte 0x0200CD38
.L08074250: .4byte 0x0200CC38

	thumb_func_start func_fe6_08074254
func_fe6_08074254: @ 0x08074254
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	ldr r0, .L080742CC @ =gUnk_08678744
	ldr r3, [r0]
	movs r0, #0xa0
	lsls r0, r0, #7
	str r0, [sp]
	movs r0, #0xd
	mov r1, r8
	adds r2, r7, #0
	bl PutSpriteExt
	movs r5, #0
	subs r0, r6, #1
	cmp r5, r0
	bge .L080742A8
	mov r4, r8
	adds r4, #8
.L0807428A:
	ldr r0, .L080742CC @ =gUnk_08678744
	ldr r3, [r0, #4]
	movs r0, #0xa0
	lsls r0, r0, #7
	str r0, [sp]
	movs r0, #0xd
	adds r1, r4, #0
	adds r2, r7, #0
	bl PutSpriteExt
	adds r4, #0x10
	adds r5, #1
	subs r0, r6, #1
	cmp r5, r0
	blt .L0807428A
.L080742A8:
	lsls r1, r5, #4
	add r1, r8
	adds r1, #8
	ldr r0, .L080742CC @ =gUnk_08678744
	ldr r3, [r0, #8]
	movs r0, #0xa0
	lsls r0, r0, #7
	str r0, [sp]
	movs r0, #0xd
	adds r2, r7, #0
	bl PutSpriteExt
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080742CC: .4byte gUnk_08678744

	thumb_func_start func_fe6_080742D0
func_fe6_080742D0: @ 0x080742D0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r0, .L0807432C @ =gBg2Tm+0x68
	movs r1, #4
	movs r2, #1
	movs r3, #0
	bl TmFillRect_thm
	ldr r4, .L08074330 @ =0x0200D6AC
	adds r0, r4, #0
	bl ClearText
	movs r3, #0
	ldr r0, .L08074334 @ =gUnk_08678840
	mov r8, r0
	adds r5, r4, #0
	mov sb, r8
.L080742FA:
	movs r2, #0
	lsls r1, r3, #3
	adds r6, r3, #1
	adds r1, r1, r3
	lsls r1, r1, #4
	mov r0, sb
	adds r0, #4
	adds r4, r1, r0
	add r1, r8
.L0807430C:
	ldrb r0, [r1]
	cmp r0, r7
	bne .L08074360
	cmp r3, #5
	bne .L08074338
	cmp r2, #0
	beq .L08074338
	adds r1, r2, #0
	adds r1, #0x6f
	ldr r0, .L0807432C @ =gBg2Tm+0x68
	movs r2, #0xa0
	lsls r2, r2, #7
	bl PutIcon
	b .L0807436A
	.align 2, 0
.L0807432C: .4byte gBg2Tm+0x68
.L08074330: .4byte 0x0200D6AC
.L08074334: .4byte gUnk_08678840
.L08074338:
	adds r0, r5, #0
	movs r1, #0
	bl Text_SetCursor
	adds r0, r5, #0
	movs r1, #0
	bl Text_SetColor
	ldr r1, [r4]
	adds r0, r5, #0
	bl Text_DrawString
	adds r0, r5, #0
	ldr r1, .L0807435C @ =gBg2Tm+0x68
	bl PutText
	b .L0807436A
	.align 2, 0
.L0807435C: .4byte gBg2Tm+0x68
.L08074360:
	adds r4, #0x10
	adds r1, #0x10
	adds r2, #1
	cmp r2, #8
	ble .L0807430C
.L0807436A:
	adds r3, r6, #0
	cmp r3, #9
	ble .L080742FA
	movs r0, #4
	bl EnableBgSync
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08074384
func_fe6_08074384: @ 0x08074384
	push {r4, lr}
	adds r3, r0, #0
	movs r2, #0
	ldr r1, .L080743B4 @ =0x0200E6B4
.L0807438C:
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, r3
	beq .L080743C2
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #7
	bls .L0807438C
	movs r2, #0
	ldr r4, .L080743B4 @ =0x0200E6B4
.L080743A4:
	lsls r0, r2, #2
	adds r1, r0, r4
	ldr r0, [r1]
	cmp r0, #0xff
	bne .L080743B8
	str r3, [r1]
	b .L080743C2
	.align 2, 0
.L080743B4: .4byte 0x0200E6B4
.L080743B8:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #7
	bls .L080743A4
.L080743C2:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080743C8
func_fe6_080743C8: @ 0x080743C8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x28
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x14
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	movs r5, #0
	ldr r2, .L08074494 @ =0x0200CD38
	movs r1, #0xff
.L080743DE:
	lsls r0, r5, #2
	add r0, sp
	str r1, [r0]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #7
	bls .L080743DE
	cmp r6, #0
	beq .L080743F8
	subs r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
.L080743F8:
	movs r5, #0
	ldrb r2, [r2]
	cmp r6, r2
	bge .L08074440
	ldr r7, .L08074498 @ =0x0200CC38
.L08074402:
	adds r0, r6, r5
	lsls r0, r0, #2
	adds r4, r0, r7
	ldr r0, [r4]
	ldr r0, [r0]
	bl GetUnitEquippedWeapon
	lsls r0, r0, #0x10
	cmp r0, #0
	beq .L0807442C
	ldr r0, [r4]
	ldr r0, [r0]
	bl GetUnitEquippedWeapon
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl GetItemIcon
	lsls r1, r5, #2
	add r1, sp
	str r0, [r1]
.L0807442C:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #7
	bhi .L08074440
	adds r1, r5, r6
	ldr r0, .L08074494 @ =0x0200CD38
	ldrb r0, [r0]
	cmp r1, r0
	blt .L08074402
.L08074440:
	movs r5, #0
	ldr r7, .L0807449C @ =0x0200E6B4
	mov r8, r7
.L08074446:
	lsls r1, r5, #2
	mov r2, r8
	adds r0, r1, r2
	ldr r0, [r0]
	adds r6, r5, #1
	cmp r0, #0xff
	beq .L08074480
	movs r5, #0
	movs r2, #0
	adds r3, r0, #0
.L0807445A:
	lsls r0, r2, #2
	add r0, sp
	ldr r0, [r0]
	cmp r0, r3
	bne .L08074466
	movs r5, #1
.L08074466:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #7
	bls .L0807445A
	cmp r5, #0
	bne .L08074480
	adds r4, r1, r7
	ldr r0, [r4]
	bl ClearIcon
	movs r0, #0xff
	str r0, [r4]
.L08074480:
	lsls r0, r6, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #7
	bls .L08074446
	add sp, #0x28
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08074494: .4byte 0x0200CD38
.L08074498: .4byte 0x0200CC38
.L0807449C: .4byte 0x0200E6B4

	thumb_func_start func_fe6_080744A0
func_fe6_080744A0: @ 0x080744A0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r0, r1, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r0, r0, #0x18
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	lsrs r0, r0, #0x1b
	movs r1, #6
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r6, r3, #0
	cmp r4, #0
	bne .L0807450C
	lsls r0, r5, #0x18
	asrs r2, r0, #0x18
	cmp r2, #0
	beq .L080744F4
	ldr r2, .L080744E8 @ =gBg2Tm
	ldr r0, .L080744EC @ =0x0000F368
	adds r1, r3, r0
	movs r4, #0x80
	lsls r4, r4, #1
	adds r0, r2, r4
	strh r1, [r0]
	ldr r0, .L080744F0 @ =0x0000F36E
	adds r1, r3, r0
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r0, r2, r3
	strh r1, [r0]
	b .L08074546
	.align 2, 0
.L080744E8: .4byte gBg2Tm
.L080744EC: .4byte 0x0000F368
.L080744F0: .4byte 0x0000F36E
.L080744F4:
	ldr r1, .L08074508 @ =gBg2Tm
	movs r4, #0x80
	lsls r4, r4, #1
	adds r0, r1, r4
	strh r2, [r0]
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r0, r1, r3
	strh r2, [r0]
	b .L08074546
	.align 2, 0
.L08074508: .4byte gBg2Tm
.L0807450C:
	lsls r0, r5, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq .L08074534
	ldr r2, .L0807452C @ =gBg2Tm
	ldr r4, .L08074530 @ =0x0000F768
	adds r0, r6, r4
	movs r3, #0x9d
	lsls r3, r3, #1
	adds r1, r2, r3
	strh r0, [r1]
	adds r4, #6
	adds r0, r6, r4
	adds r3, #0x40
	adds r1, r2, r3
	b .L08074544
	.align 2, 0
.L0807452C: .4byte gBg2Tm
.L08074530: .4byte 0x0000F768
.L08074534:
	ldr r1, .L08074554 @ =gBg2Tm
	movs r4, #0x9d
	lsls r4, r4, #1
	adds r2, r1, r4
	strh r0, [r2]
	movs r2, #0xbd
	lsls r2, r2, #1
	adds r1, r1, r2
.L08074544:
	strh r0, [r1]
.L08074546:
	movs r0, #4
	bl EnableBgSync
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08074554: .4byte gBg2Tm

	thumb_func_start func_fe6_08074558
func_fe6_08074558: @ 0x08074558
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	cmp r1, #0
	beq .L080745A2
	ldr r0, .L08074570 @ =0x0200E7D8
	ldr r2, [r0]
	b .L080745A8
	.align 2, 0
.L08074570: .4byte 0x0200E7D8
.L08074574:
	adds r0, r6, #0
	adds r0, #0x2c
	strb r5, [r0]
	adds r0, #0x14
	strh r5, [r0]
	b .L0807465E
.L08074580:
	adds r0, r6, #0
	adds r0, #0x2c
	strb r5, [r0]
	adds r0, #0x14
	strh r3, [r0]
	b .L0807465E
.L0807458C:
	subs r1, r5, r1
	adds r0, r6, #0
	adds r0, #0x2c
	strb r1, [r0]
	b .L0807465E
.L08074596:
	adds r1, r6, #0
	adds r1, #0x2c
	movs r0, #1
	strb r0, [r1]
	strh r3, [r7]
	b .L0807465E
.L080745A2:
	bl GetLastStatScreenUnitId
	adds r2, r0, #0
.L080745A8:
	movs r5, #0
	ldr r0, .L080745DC @ =0x0200CD38
	ldrb r3, [r0]
	mov r8, r0
	cmp r5, r3
	bhs .L0807465E
	lsls r0, r4, #0x18
	asrs r7, r0, #0x18
	ldr r4, .L080745E0 @ =0x0200CC38
	movs r0, #0x2c
	adds r0, r0, r6
	mov ip, r0
	adds r1, r6, #0
	adds r1, #0x40
.L080745C4:
	cmp r7, #0
	beq .L080745E4
	lsls r0, r5, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	cmp r0, r2
	beq .L080745F6
	b .L08074654
	.align 2, 0
.L080745DC: .4byte 0x0200CD38
.L080745E0: .4byte 0x0200CC38
.L080745E4:
	lsls r0, r5, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, #0xb]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r2
	bne .L08074654
.L080745F6:
	adds r0, r6, #0
	adds r0, #0x30
	movs r3, #0
	strb r5, [r0]
	cmp r5, #0
	beq .L08074574
	mov r0, r8
	ldrb r2, [r0]
	subs r0, r2, #1
	cmp r5, r0
	bne .L08074622
	cmp r2, #6
	bls .L08074580
	movs r0, #5
	mov r2, ip
	strb r0, [r2]
	mov r2, r8
	ldrb r0, [r2]
	subs r0, #6
	lsls r0, r0, #4
	strh r0, [r1]
	b .L0807465E
.L08074622:
	ldrh r1, [r1]
	lsrs r1, r1, #4
	adds r0, r1, #0
	adds r4, r6, #0
	adds r4, #0x40
	cmp r5, r0
	bls .L08074636
	adds r0, #5
	cmp r5, r0
	blt .L0807458C
.L08074636:
	adds r7, r4, #0
	ldrh r2, [r4]
	subs r0, r5, #1
	lsls r3, r0, #4
	cmp r2, r3
	bgt .L08074596
	subs r0, r5, #4
	lsls r1, r0, #4
	cmp r2, r1
	bge .L0807465E
	movs r0, #4
	mov r2, ip
	strb r0, [r2]
	strh r1, [r4]
	b .L0807465E
.L08074654:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, r3
	blo .L080745C4
.L0807465E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08074668
func_fe6_08074668: @ 0x08074668
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	asrs r2, r0, #0x18
	cmp r2, #0
	beq .L0807470C
	ldr r0, .L08074708 @ =gDispIo
	mov ip, r0
	movs r0, #0x20
	mov r1, ip
	ldrb r1, [r1, #1]
	orrs r0, r1
	movs r1, #0x40
	orrs r0, r1
	movs r1, #0x7f
	ands r0, r1
	mov r2, ip
	strb r0, [r2, #1]
	mov r0, ip
	adds r0, #0x2d
	movs r2, #0
	strb r2, [r0]
	mov r1, ip
	adds r1, #0x31
	movs r0, #0x38
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x2c
	movs r3, #0xf0
	strb r3, [r0]
	subs r1, #1
	movs r0, #0x98
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x2f
	strb r2, [r0]
	adds r0, #4
	strb r2, [r0]
	subs r0, #5
	strb r3, [r0]
	adds r1, #2
	movs r0, #0x20
	strb r0, [r1]
	adds r1, #2
	movs r0, #1
	ldrb r3, [r1]
	orrs r0, r3
	movs r4, #2
	orrs r0, r4
	movs r3, #4
	orrs r0, r3
	movs r2, #8
	orrs r0, r2
	movs r5, #0x10
	orrs r0, r5
	strb r0, [r1]
	mov r6, ip
	adds r6, #0x35
	movs r1, #2
	rsbs r1, r1, #0
	adds r0, r1, #0
	ldrb r7, [r6]
	ands r0, r7
	orrs r0, r4
	orrs r0, r3
	orrs r0, r2
	orrs r0, r5
	strb r0, [r6]
	mov r5, ip
	adds r5, #0x36
	ldrb r0, [r5]
	ands r1, r0
	orrs r1, r4
	orrs r1, r3
	orrs r1, r2
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r1, r0
	strb r1, [r5]
	b .L0807476C
	.align 2, 0
.L08074708: .4byte gDispIo
.L0807470C:
	ldr r1, .L08074774 @ =gDispIo
	mov ip, r1
	movs r0, #0x20
	ldrb r3, [r1, #1]
	orrs r0, r3
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	mov r6, ip
	strb r0, [r6, #1]
	mov r0, ip
	adds r0, #0x2d
	strb r2, [r0]
	mov r1, ip
	adds r1, #0x31
	movs r0, #0x38
	strb r0, [r1]
	subs r1, #5
	movs r0, #0xf0
	strb r0, [r1]
	adds r1, #4
	movs r0, #0x98
	strb r0, [r1]
	adds r1, #4
	movs r0, #1
	ldrb r7, [r1]
	orrs r0, r7
	movs r5, #2
	orrs r0, r5
	movs r4, #4
	orrs r0, r4
	movs r3, #8
	orrs r0, r3
	movs r2, #0x10
	orrs r0, r2
	strb r0, [r1]
	adds r1, #2
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r6, [r1]
	ands r0, r6
	orrs r0, r5
	orrs r0, r4
	orrs r0, r3
	orrs r0, r2
	strb r0, [r1]
.L0807476C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08074774: .4byte gDispIo

	thumb_func_start func_fe6_08074778
func_fe6_08074778: @ 0x08074778
	push {r4, lr}
	adds r4, r0, #0
	bl EndAllMus
	ldr r0, [r4, #0x44]
	bl Proc_End
	ldr r0, [r4, #0x48]
	bl Proc_End
	bl EndGreenText
	ldr r2, .L080747B8 @ =gDispIo
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
	adds r0, r4, #0
	adds r0, #0x39
	ldrb r0, [r0]
	cmp r0, #1
	bne .L080747BC
	movs r0, #4
	bl SetStatScreenExcludedUnitFlags
	b .L080747C2
	.align 2, 0
.L080747B8: .4byte gDispIo
.L080747BC:
	movs r0, #0xc
	bl SetStatScreenExcludedUnitFlags
.L080747C2:
	ldr r1, .L080747FC @ =0x0200CC38
	adds r0, r4, #0
	adds r0, #0x30
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	adds r1, r4, #0
	bl StartStatScreen
	ldr r1, .L08074800 @ =gPlaySt
	adds r0, r4, #0
	adds r0, #0x34
	ldrb r0, [r0]
	lsls r0, r0, #7
	adds r2, r4, #0
	adds r2, #0x32
	ldrb r2, [r2]
	adds r0, r2, r0
	strb r0, [r1, #0x1a]
	adds r1, r4, #0
	adds r1, #0x29
	movs r0, #4
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080747FC: .4byte 0x0200CC38
.L08074800: .4byte gPlaySt

	thumb_func_start func_fe6_08074804
func_fe6_08074804: @ 0x08074804
	push {lr}
	bl func_fe6_08074EF0
	ldr r2, .L0807482C @ =gDispIo
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r1, [r2, #1]
	ands r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #2
	ands r0, r1
	subs r1, #4
	ands r0, r1
	subs r1, #8
	ands r0, r1
	strb r0, [r2, #1]
	pop {r0}
	bx r0
	.align 2, 0
.L0807482C: .4byte gDispIo

	thumb_func_start func_fe6_08074830
func_fe6_08074830: @ 0x08074830
	ldr r2, .L0807484C @ =gDispIo
	movs r0, #1
	ldrb r1, [r2, #1]
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	movs r1, #8
	orrs r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #1]
	bx lr
	.align 2, 0
.L0807484C: .4byte gDispIo

	thumb_func_start func_fe6_08074850
func_fe6_08074850: @ 0x08074850
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r0, [r4, #0x14]
	str r0, [r4, #0x2c]
	adds r0, r4, #0
	adds r0, #0x3b
	movs r1, #0
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r0, [r4, #0x2c]
	adds r0, #0x40
	ldrh r0, [r0]
	strh r0, [r4, #0x38]
	adds r0, r4, #0
	adds r0, #0x3a
	strb r1, [r0]
	subs r0, #0xa
	strb r1, [r0]
	adds r0, r4, #0
	bl func_fe6_0808230C
	str r0, [r4, #0x34]
	ldr r1, [r4, #0x2c]
	adds r1, #0x40
	ldrh r1, [r1]
	str r1, [sp]
	ldr r1, .L080748A8 @ =0x0200CD38
	ldrb r1, [r1]
	str r1, [sp, #4]
	movs r1, #6
	str r1, [sp, #8]
	movs r1, #0xe0
	movs r2, #0x40
	movs r3, #0xa
	bl func_fe6_08082320
	bl ForceSyncUnitSpriteSheet
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080748A8: .4byte 0x0200CD38

	thumb_func_start func_fe6_080748AC
func_fe6_080748AC: @ 0x080748AC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r6, r0, #0
	ldr r1, .L080748F4 @ =gUnk_08327148
	add r0, sp, #0xc
	movs r2, #4
	bl memcpy
	ldr r0, [r6, #0x2c]
	adds r0, #0x34
	ldrb r0, [r0]
	cmp r0, #0
	bne .L080748FC
	adds r4, r6, #0
	adds r4, #0x3b
	ldrb r1, [r4]
	lsrs r0, r1, #3
	movs r1, #3
	ands r0, r1
	add r0, sp
	adds r0, #0xc
	ldrb r2, [r0]
	adds r2, #7
	ldr r3, .L080748F8 @ =gUnk_08678750
	movs r0, #0x90
	lsls r0, r0, #8
	str r0, [sp]
	movs r0, #0xb
	movs r1, #0xb8
	bl PutSpriteExt
	b .L08074920
	.align 2, 0
.L080748F4: .4byte gUnk_08327148
.L080748F8: .4byte gUnk_08678750
.L080748FC:
	ldr r1, .L080749A4 @ =0x000020B8
	adds r4, r6, #0
	adds r4, #0x3b
	ldrb r2, [r4]
	lsrs r0, r2, #3
	movs r2, #3
	ands r0, r2
	add r0, sp
	adds r0, #0xc
	ldrb r2, [r0]
	adds r2, #7
	ldr r3, .L080749A8 @ =gUnk_08678750
	movs r0, #0x90
	lsls r0, r0, #8
	str r0, [sp]
	movs r0, #0xb
	bl PutSpriteExt
.L08074920:
	str r4, [sp, #0x10]
	ldr r1, .L080749AC @ =gUnk_08678818
	ldr r0, [r6, #0x2c]
	adds r0, #0x2f
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	movs r5, #0x90
	lsls r5, r5, #8
	str r5, [sp]
	movs r0, #0xd
	movs r1, #0x20
	movs r2, #8
	bl PutSpriteExt
	ldr r3, .L080749B0 @ =gUnk_08678758
	str r5, [sp]
	movs r0, #0xd
	movs r1, #0xa0
	movs r2, #0
	bl PutSpriteExt
	ldr r0, [r6, #0x34]
	ldr r1, [r6, #0x2c]
	adds r1, #0x40
	ldrh r1, [r1]
	str r1, [sp]
	ldr r1, .L080749B4 @ =0x0200CD38
	ldrb r1, [r1]
	str r1, [sp, #4]
	movs r1, #6
	str r1, [sp, #8]
	movs r1, #0xe0
	movs r2, #0x40
	movs r3, #0xa
	bl func_fe6_08082320
	ldr r4, [r6, #0x2c]
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #2
	bls .L080749BC
	ldr r1, .L080749B8 @ =gUnk_08678840
	adds r3, r4, #0
	adds r3, #0x2d
	adds r2, r4, #0
	adds r2, #0x2f
	ldrb r5, [r2]
	lsls r0, r5, #3
	adds r0, r0, r5
	ldrb r3, [r3]
	adds r0, r3, r0
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrb r0, [r0, #8]
	adds r1, r4, #0
	adds r1, #0x2c
	ldrb r1, [r1]
	lsls r1, r1, #4
	adds r1, #0x28
	bl PutUiHand
	b .L080749D2
	.align 2, 0
.L080749A4: .4byte 0x000020B8
.L080749A8: .4byte gUnk_08678750
.L080749AC: .4byte gUnk_08678818
.L080749B0: .4byte gUnk_08678758
.L080749B4: .4byte 0x0200CD38
.L080749B8: .4byte gUnk_08678840
.L080749BC:
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	lsls r2, r0, #4
	adds r2, #0x40
	ldr r3, .L08074A24 @ =gUnk_08678760
	str r5, [sp]
	movs r0, #0xd
	movs r1, #4
	bl PutSpriteExt
.L080749D2:
	ldr r0, [r6, #0x2c]
	adds r1, r0, #0
	adds r1, #0x40
	ldrh r0, [r6, #0x38]
	ldrh r2, [r1]
	cmp r0, r2
	bne .L080749E8
	movs r0, #0xf
	ands r0, r2
	cmp r0, #0
	beq .L08074A30
.L080749E8:
	ldr r0, .L08074A28 @ =gPal
	ldr r1, .L08074A2C @ =0x02016874
	ldrh r1, [r1, #0x10]
	movs r5, #0xcf
	lsls r5, r5, #2
	adds r0, r0, r5
	strh r1, [r0]
	bl EnablePalSync
	adds r2, r6, #0
	adds r2, #0x3c
	movs r0, #0x20
	strb r0, [r2]
	ldr r0, [r6, #0x2c]
	adds r0, #0x40
	ldrh r0, [r0]
	strh r0, [r6, #0x38]
	adds r0, r6, #0
	adds r0, #0x3a
	ldrb r1, [r0]
	str r2, [sp, #0x14]
	adds r7, r0, #0
	cmp r1, #0
	bne .L08074A6A
	movs r0, #1
	bl func_fe6_08074668
	movs r0, #1
	b .L08074A68
	.align 2, 0
.L08074A24: .4byte gUnk_08678760
.L08074A28: .4byte gPal
.L08074A2C: .4byte 0x02016874
.L08074A30:
	ldr r2, .L08074B20 @ =gPal
	ldr r3, .L08074B24 @ =0x02016874
	adds r4, r6, #0
	adds r4, #0x3c
	ldrb r1, [r4]
	lsrs r0, r1, #2
	movs r1, #0xf
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r5, #0xcf
	lsls r5, r5, #2
	adds r2, r2, r5
	strh r0, [r2]
	bl EnablePalSync
	adds r0, r6, #0
	adds r0, #0x3a
	str r4, [sp, #0x14]
	adds r7, r0, #0
	ldrb r0, [r7]
	cmp r0, #1
	bne .L08074A6A
	movs r0, #0
	bl func_fe6_08074668
	movs r0, #0
.L08074A68:
	strb r0, [r7]
.L08074A6A:
	bl SyncUnitSpriteSheet
	ldrh r1, [r6, #0x38]
	lsrs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r0, #0xf
	ands r1, r0
	rsbs r1, r1, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov sl, r1
	movs r4, #0
	ldr r0, .L08074B28 @ =0x0200CD38
	movs r1, #0x30
	adds r1, r1, r6
	mov r8, r1
	ldrb r0, [r0]
	cmp r5, r0
	bge .L08074AC8
	mov r2, sl
	lsls r0, r2, #0x18
	asrs r0, r0, #0x18
	adds r0, #0x38
	mov sb, r0
.L08074A9C:
	lsls r2, r4, #4
	add r2, sb
	adds r0, r4, r5
	lsls r0, r0, #2
	ldr r1, .L08074B2C @ =0x0200CC38
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r3, [r0]
	movs r0, #4
	movs r1, #8
	bl PutUnitSprite
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #5
	bhi .L08074AC8
	adds r1, r4, r5
	ldr r0, .L08074B28 @ =0x0200CD38
	ldrb r0, [r0]
	cmp r1, r0
	blt .L08074A9C
.L08074AC8:
	ldrb r0, [r7]
	cmp r0, #0
	beq .L08074AF6
	adds r3, r4, r5
	ldr r0, .L08074B28 @ =0x0200CD38
	ldrb r0, [r0]
	cmp r3, r0
	bge .L08074AF6
	lsls r2, r4, #4
	mov r5, sl
	lsls r0, r5, #0x18
	asrs r0, r0, #0x18
	adds r0, #0x38
	adds r2, r2, r0
	ldr r1, .L08074B2C @ =0x0200CC38
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r3, [r0]
	movs r0, #4
	movs r1, #8
	bl PutUnitSprite
.L08074AF6:
	ldr r0, [r6, #0x2c]
	adds r1, r0, #0
	adds r1, #0x2f
	adds r2, r0, #0
	adds r2, #0x2e
	ldrb r1, [r1]
	ldrb r2, [r2]
	cmp r1, r2
	bhs .L08074B30
	adds r0, #0x39
	ldrb r0, [r0]
	cmp r0, #3
	beq .L08074B30
	mov r0, r8
	ldrb r1, [r0]
	movs r0, #1
	movs r2, #1
	bl func_fe6_080744A0
	b .L08074B3C
	.align 2, 0
.L08074B20: .4byte gPal
.L08074B24: .4byte 0x02016874
.L08074B28: .4byte 0x0200CD38
.L08074B2C: .4byte 0x0200CC38
.L08074B30:
	mov r2, r8
	ldrb r1, [r2]
	movs r0, #1
	movs r2, #0
	bl func_fe6_080744A0
.L08074B3C:
	ldr r0, [r6, #0x2c]
	adds r1, r0, #0
	adds r1, #0x2f
	ldrb r1, [r1]
	cmp r1, #1
	bls .L08074B5E
	adds r0, #0x39
	ldrb r0, [r0]
	cmp r0, #3
	beq .L08074B5E
	mov r5, r8
	ldrb r1, [r5]
	movs r0, #0
	movs r2, #1
	bl func_fe6_080744A0
	b .L08074B6A
.L08074B5E:
	mov r0, r8
	ldrb r1, [r0]
	movs r0, #0
	movs r2, #0
	bl func_fe6_080744A0
.L08074B6A:
	mov r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x1b
	cmp r0, #5
	bls .L08074B7E
	movs r0, #0
	strb r0, [r1]
.L08074B7E:
	ldr r2, [sp, #0x10]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldr r5, [sp, #0x14]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08074BA0
func_fe6_08074BA0: @ 0x08074BA0
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_08074BA4
func_fe6_08074BA4: @ 0x08074BA4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp]
	ldr r0, .L08074D3C @ =gPlaySt
	ldrb r0, [r0, #0xf]
	adds r1, r0, #1
	mov sb, r1
	adds r0, #0x40
	cmp sb, r0
	blt .L08074BC2
	b .L08074D2C
.L08074BC2:
	ldr r2, .L08074D40 @ =0x0200CD38
	mov r8, r2
	ldr r0, .L08074D44 @ =gBattleUnitA
	str r0, [sp, #4]
.L08074BCA:
	mov r0, sb
	bl GetUnit
	adds r7, r0, #0
	movs r1, #1
	add r1, sb
	mov sl, r1
	cmp r7, #0
	bne .L08074BDE
	b .L08074D1E
.L08074BDE:
	ldr r0, [r7]
	cmp r0, #0
	bne .L08074BE6
	b .L08074D1E
.L08074BE6:
	ldrh r1, [r7, #0xc]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq .L08074BF2
	b .L08074D1E
.L08074BF2:
	ldr r0, [sp]
	adds r0, #0x39
	ldrb r0, [r0]
	cmp r0, #1
	beq .L08074C06
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq .L08074C06
	b .L08074D1E
.L08074C06:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne .L08074C18
	ldr r1, [sp]
	adds r1, #0x3b
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
.L08074C18:
	mov r2, r8
	ldrb r2, [r2]
	lsls r0, r2, #1
	mov r1, r8
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r2, .L08074D48 @ =0x0200C938
	adds r0, r0, r2
	str r7, [r0]
	adds r0, r7, #0
	movs r1, #1
	rsbs r1, r1, #0
	bl BattleGenerateDisplayStats
	mov r0, r8
	ldrb r0, [r0]
	lsls r1, r0, #1
	mov r2, r8
	ldrb r2, [r2]
	adds r1, r1, r2
	lsls r1, r1, #2
	ldr r0, .L08074D48 @ =0x0200C938
	adds r1, r1, r0
	ldr r0, [sp, #4]
	adds r0, #0x58
	ldrh r0, [r0]
	adds r0, #1
	movs r2, #0xff
	ands r0, r2
	subs r0, #1
	strh r0, [r1, #4]
	mov r0, r8
	ldrb r0, [r0]
	lsls r1, r0, #1
	mov r2, r8
	ldrb r2, [r2]
	adds r1, r1, r2
	lsls r1, r1, #2
	ldr r0, .L08074D48 @ =0x0200C938
	adds r1, r1, r0
	ldr r0, [sp, #4]
	adds r0, #0x5e
	ldrh r0, [r0]
	adds r0, #1
	movs r2, #0xff
	ands r0, r2
	subs r0, #1
	strh r0, [r1, #6]
	mov r0, r8
	ldrb r0, [r0]
	lsls r1, r0, #1
	mov r2, r8
	ldrb r2, [r2]
	adds r1, r1, r2
	lsls r1, r1, #2
	ldr r0, .L08074D48 @ =0x0200C938
	adds r1, r1, r0
	ldr r2, .L08074D4C @ =gBattleUnitA+0x60
	ldrh r0, [r2]
	adds r0, #1
	movs r2, #0xff
	ands r0, r2
	subs r0, #1
	strh r0, [r1, #8]
	adds r0, r7, #0
	bl GetUnitSupportCount
	adds r6, r0, #0
	movs r5, #0
	movs r4, #0
	movs r0, #1
	add r0, sb
	mov sl, r0
	cmp r5, r6
	bge .L08074CCE
.L08074CB0:
	adds r0, r7, #0
	adds r1, r4, #0
	bl CanUnitSupportNow
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08074CC4
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
.L08074CC4:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, r6
	blt .L08074CB0
.L08074CCE:
	cmp r5, #3
	bls .L08074CE2
	subs r0, r5, #1
	movs r1, #3
	bl __divsi3
	adds r0, #6
	ldr r1, [sp]
	adds r1, #0x2e
	strb r0, [r1]
.L08074CE2:
	mov r1, r8
	ldrb r1, [r1]
	lsls r0, r1, #1
	mov r2, r8
	ldrb r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #2
	ldr r1, .L08074D48 @ =0x0200C938
	adds r0, r0, r1
	strb r5, [r0, #0xa]
	ldr r0, .L08074D50 @ =0x0200CC38
	mov r2, r8
	ldrb r1, [r2]
	lsls r2, r1, #2
	adds r2, r2, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, .L08074D48 @ =0x0200C938
	adds r0, r0, r1
	str r0, [r2]
	mov r2, r8
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	adds r0, r7, #0
	bl GetUnitMapSprite
	bl UseUnitSprite
.L08074D1E:
	mov sb, sl
	ldr r0, .L08074D3C @ =gPlaySt
	ldrb r0, [r0, #0xf]
	adds r0, #0x40
	cmp sb, r0
	bge .L08074D2C
	b .L08074BCA
.L08074D2C:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08074D3C: .4byte gPlaySt
.L08074D40: .4byte 0x0200CD38
.L08074D44: .4byte gBattleUnitA
.L08074D48: .4byte 0x0200C938
.L08074D4C: .4byte gBattleUnitA+0x60
.L08074D50: .4byte 0x0200CC38

	thumb_func_start func_fe6_08074D54
func_fe6_08074D54: @ 0x08074D54
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp]
	movs r0, #1
	mov sb, r0
	ldr r1, .L08074EDC @ =0x0200CD38
	mov r8, r1
	ldr r2, .L08074EE0 @ =gBattleUnitA
	str r2, [sp, #4]
.L08074D6E:
	mov r0, sb
	bl GetUnit
	adds r7, r0, #0
	movs r0, #1
	add r0, sb
	mov sl, r0
	cmp r7, #0
	bne .L08074D82
	b .L08074EC2
.L08074D82:
	ldr r0, [r7]
	cmp r0, #0
	bne .L08074D8A
	b .L08074EC2
.L08074D8A:
	ldrh r1, [r7, #0xc]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq .L08074D96
	b .L08074EC2
.L08074D96:
	ldr r0, [sp]
	adds r0, #0x39
	ldrb r0, [r0]
	cmp r0, #1
	beq .L08074DAA
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq .L08074DAA
	b .L08074EC2
.L08074DAA:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne .L08074DBC
	ldr r1, [sp]
	adds r1, #0x3b
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
.L08074DBC:
	mov r1, r8
	ldrb r1, [r1]
	lsls r0, r1, #1
	mov r2, r8
	ldrb r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #2
	ldr r1, .L08074EE4 @ =0x0200C938
	adds r0, r0, r1
	str r7, [r0]
	adds r0, r7, #0
	movs r1, #1
	rsbs r1, r1, #0
	bl BattleGenerateDisplayStats
	mov r2, r8
	ldrb r2, [r2]
	lsls r1, r2, #1
	mov r0, r8
	ldrb r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r2, .L08074EE4 @ =0x0200C938
	adds r1, r1, r2
	ldr r0, [sp, #4]
	adds r0, #0x58
	ldrh r0, [r0]
	adds r0, #1
	movs r2, #0xff
	ands r0, r2
	subs r0, #1
	strh r0, [r1, #4]
	mov r0, r8
	ldrb r0, [r0]
	lsls r1, r0, #1
	mov r2, r8
	ldrb r2, [r2]
	adds r1, r1, r2
	lsls r1, r1, #2
	ldr r0, .L08074EE4 @ =0x0200C938
	adds r1, r1, r0
	ldr r0, [sp, #4]
	adds r0, #0x5e
	ldrh r0, [r0]
	adds r0, #1
	movs r2, #0xff
	ands r0, r2
	subs r0, #1
	strh r0, [r1, #6]
	mov r0, r8
	ldrb r0, [r0]
	lsls r1, r0, #1
	mov r2, r8
	ldrb r2, [r2]
	adds r1, r1, r2
	lsls r1, r1, #2
	ldr r0, .L08074EE4 @ =0x0200C938
	adds r1, r1, r0
	ldr r2, .L08074EE8 @ =gBattleUnitA+0x60
	ldrh r0, [r2]
	adds r0, #1
	movs r2, #0xff
	ands r0, r2
	subs r0, #1
	strh r0, [r1, #8]
	adds r0, r7, #0
	bl GetUnitSupportCount
	adds r6, r0, #0
	movs r5, #0
	movs r4, #0
	movs r0, #1
	add r0, sb
	mov sl, r0
	cmp r5, r6
	bge .L08074E72
.L08074E54:
	adds r0, r7, #0
	adds r1, r4, #0
	bl CanUnitSupportNow
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08074E68
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
.L08074E68:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, r6
	blt .L08074E54
.L08074E72:
	cmp r5, #3
	bls .L08074E86
	subs r0, r5, #1
	movs r1, #3
	bl __divsi3
	adds r0, #6
	ldr r1, [sp]
	adds r1, #0x2e
	strb r0, [r1]
.L08074E86:
	mov r1, r8
	ldrb r1, [r1]
	lsls r0, r1, #1
	mov r2, r8
	ldrb r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #2
	ldr r1, .L08074EE4 @ =0x0200C938
	adds r0, r0, r1
	strb r5, [r0, #0xa]
	ldr r0, .L08074EEC @ =0x0200CC38
	mov r2, r8
	ldrb r1, [r2]
	lsls r2, r1, #2
	adds r2, r2, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, .L08074EE4 @ =0x0200C938
	adds r0, r0, r1
	str r0, [r2]
	mov r2, r8
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	adds r0, r7, #0
	bl GetUnitMapSprite
	bl UseUnitSprite
.L08074EC2:
	mov sb, sl
	mov r0, sb
	cmp r0, #0x3f
	bgt .L08074ECC
	b .L08074D6E
.L08074ECC:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08074EDC: .4byte 0x0200CD38
.L08074EE0: .4byte gBattleUnitA
.L08074EE4: .4byte 0x0200C938
.L08074EE8: .4byte gBattleUnitA+0x60
.L08074EEC: .4byte 0x0200CC38

	thumb_func_start func_fe6_08074EF0
func_fe6_08074EF0: @ 0x08074EF0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov r8, r0
	ldr r2, .L08074FCC @ =gDispIo
	movs r5, #1
	ldrb r0, [r2, #1]
	orrs r0, r5
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	movs r1, #8
	orrs r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #1]
	movs r0, #0
	bl SetOnVMatch
	movs r0, #0
	bl InitBgs
	bl ResetText
	bl ResetTextFont
	bl ClearIcons
	bl ApplyUnitSpritePalettes
	bl ApplySystemObjectsGraphics
	mov r0, r8
	bl StartGreenText
	ldr r1, .L08074FD0 @ =0x0200CD38
	movs r0, #0
	strb r0, [r1]
	mov r1, r8
	adds r1, #0x3b
	movs r0, #0
	strb r0, [r1]
	mov r0, r8
	adds r0, #0x2e
	movs r6, #6
	strb r6, [r0]
	mov r0, r8
	bl func_fe6_08074D54
	mov r0, r8
	adds r0, #0x39
	ldrb r0, [r0]
	cmp r0, #1
	bne .L08074F7E
	mov r0, r8
	adds r0, #0x2a
	movs r1, #0x32
	add r1, r8
	mov sl, r1
	movs r2, #0x29
	add r2, r8
	mov sb, r2
	mov r7, r8
	adds r7, #0x2f
	ldrb r0, [r0]
	cmp r0, #1
	bne .L08074FEC
.L08074F7E:
	ldr r4, .L08074FD4 @ =gPlaySt
	ldrb r1, [r4, #0x1a]
	mov r3, r8
	adds r3, #0x34
	movs r0, #0x32
	add r0, r8
	mov sl, r0
	cmp r1, #0
	beq .L08074FA4
	lsrs r0, r1, #7
	ands r0, r5
	mov r2, r8
	adds r2, #0x33
	strb r0, [r2]
	strb r0, [r3]
	movs r0, #0x7f
	ands r1, r0
	mov r2, sl
	strb r1, [r2]
.L08074FA4:
	mov r0, r8
	adds r0, #0x29
	mov sb, r0
	mov r7, r8
	adds r7, #0x2f
	ldrb r0, [r0]
	cmp r0, #4
	beq .L08074FE2
	ldrb r0, [r7]
	cmp r0, #0
	beq .L08074FE2
	ldrb r4, [r4, #0x19]
	lsrs r1, r4, #4
	cmp r1, #0
	beq .L08074FE2
	cmp r1, #6
	bls .L08074FD8
	strb r6, [r7]
	b .L08074FDA
	.align 2, 0
.L08074FCC: .4byte gDispIo
.L08074FD0: .4byte 0x0200CD38
.L08074FD4: .4byte gPlaySt
.L08074FD8:
	strb r1, [r7]
.L08074FDA:
	ldrb r0, [r7]
	mov r1, r8
	adds r1, #0x36
	strb r0, [r1]
.L08074FE2:
	mov r1, sl
	ldrb r0, [r1]
	ldrb r1, [r3]
	bl func_fe6_08076D3C
.L08074FEC:
	ldr r0, .L080750DC @ =gUnk_083198CC
	ldr r1, .L080750E0 @ =0x06017200
	bl Decompress
	ldr r0, .L080750E4 @ =gUnk_08319E88
	movs r1, #0x88
	lsls r1, r1, #2
	movs r2, #0x60
	bl ApplyPaletteExt
	ldr r0, .L080750E8 @ =gBg0Tm
	movs r1, #0
	bl TmFill
	ldr r4, .L080750EC @ =gBg1Tm
	adds r0, r4, #0
	movs r1, #0
	bl TmFill
	ldr r0, .L080750F0 @ =gBg2Tm
	movs r1, #0
	bl TmFill
	bl InitIcons
	movs r0, #4
	bl ApplyIconPalettes
	bl UnpackUiWindowFrameGraphics
	ldr r0, .L080750F4 @ =gUnk_083215B8
	ldr r1, .L080750F8 @ =0x06014800
	bl Decompress
	ldr r0, .L080750FC @ =gUnk_08321EE4
	movs r1, #0xc8
	lsls r1, r1, #2
	movs r2, #0x20
	bl ApplyPaletteExt
	bl func_fe6_08082CBC
	ldr r1, .L08075100 @ =gUnk_083210A0
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r4, #0
	bl TmApplyTsa_thm
	movs r5, #0
	mov r2, r8
	adds r2, #0x2e
	str r2, [sp, #8]
	mov r6, r8
	adds r6, #0x39
	str r6, [sp, #0xc]
	mov r0, r8
	adds r0, #0x2b
	str r0, [sp, #4]
	mov r1, r8
	adds r1, #0x40
	str r1, [sp, #0x10]
	ldr r6, .L08075104 @ =0x0200D5F4
.L08075068:
	lsls r0, r5, #3
	ldr r1, .L08075108 @ =0x0200D5BC
	adds r0, r0, r1
	movs r1, #5
	bl InitText
	lsls r4, r5, #1
	adds r4, r4, r5
	lsls r4, r4, #3
	adds r0, r4, r6
	movs r1, #7
	bl InitTextDb
	adds r0, r6, #0
	adds r0, #8
	adds r0, r4, r0
	movs r1, #7
	bl InitText
	ldr r2, .L0807510C @ =0x0200D604
	adds r4, r4, r2
	adds r0, r4, #0
	movs r1, #5
	bl InitText
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #6
	bls .L08075068
	ldr r0, .L08075110 @ =0x0200D69C
	movs r1, #4
	bl InitText
	ldr r0, .L08075114 @ =0x0200D6A4
	movs r1, #0x14
	bl InitText
	ldr r0, .L08075118 @ =0x0200D6AC
	movs r1, #4
	bl InitText
	mov r6, sl
	ldrb r0, [r6]
	bl func_fe6_080742D0
	mov r0, sb
	ldrb r0, [r0]
	cmp r0, #4
	bne .L0807511C
	mov r0, r8
	movs r1, #0
	bl func_fe6_08074558
	movs r0, #0
	mov r1, sb
	strb r0, [r1]
	b .L0807512C
	.align 2, 0
.L080750DC: .4byte gUnk_083198CC
.L080750E0: .4byte 0x06017200
.L080750E4: .4byte gUnk_08319E88
.L080750E8: .4byte gBg0Tm
.L080750EC: .4byte gBg1Tm
.L080750F0: .4byte gBg2Tm
.L080750F4: .4byte gUnk_083215B8
.L080750F8: .4byte 0x06014800
.L080750FC: .4byte gUnk_08321EE4
.L08075100: .4byte gUnk_083210A0
.L08075104: .4byte 0x0200D5F4
.L08075108: .4byte 0x0200D5BC
.L0807510C: .4byte 0x0200D604
.L08075110: .4byte 0x0200D69C
.L08075114: .4byte 0x0200D6A4
.L08075118: .4byte 0x0200D6AC
.L0807511C:
	ldr r2, [sp, #0xc]
	ldrb r2, [r2]
	cmp r2, #1
	bne .L0807512C
	mov r0, r8
	movs r1, #1
	bl func_fe6_08074558
.L0807512C:
	movs r1, #0
	movs r0, #0
	mov r6, r8
	strh r0, [r6, #0x3e]
	ldr r0, [sp, #4]
	strb r1, [r0]
	ldr r4, .L08075184 @ =0x0200D69C
	adds r0, r4, #0
	bl ClearText
	adds r0, r4, #0
	movs r1, #0
	bl Text_SetCursor
	adds r0, r4, #0
	movs r1, #0
	bl Text_SetColor
	ldr r1, .L08075188 @ =gUnk_0832714C
	adds r0, r4, #0
	bl Text_DrawString
	ldr r1, .L0807518C @ =gBg2Tm+0x146
	adds r0, r4, #0
	bl PutText
	movs r5, #0
	ldr r2, .L08075190 @ =0x0200E6B4
	movs r1, #0xff
.L08075166:
	lsls r0, r5, #2
	adds r0, r0, r2
	str r1, [r0]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x13
	bls .L08075166
	ldr r1, [sp, #0x10]
	ldrh r1, [r1]
	lsrs r0, r1, #4
	lsls r1, r0, #0x18
	lsrs r5, r1, #0x18
	b .L080751B0
	.align 2, 0
.L08075184: .4byte 0x0200D69C
.L08075188: .4byte gUnk_0832714C
.L0807518C: .4byte gBg2Tm+0x146
.L08075190: .4byte 0x0200E6B4
.L08075194:
	ldrb r3, [r7]
	movs r0, #1
	str r0, [sp]
	mov r0, r8
	adds r1, r5, #0
	ldr r2, .L080752EC @ =gBg0Tm
	bl func_fe6_08076448
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r2, [sp, #0x10]
	ldrh r2, [r2]
	lsrs r0, r2, #4
.L080751B0:
	adds r0, #6
	cmp r5, r0
	bge .L080751BE
	ldr r0, .L080752F0 @ =0x0200CD38
	ldrb r0, [r0]
	cmp r5, r0
	blo .L08075194
.L080751BE:
	ldr r6, [sp, #8]
	ldrb r0, [r6]
	ldrb r1, [r7]
	movs r2, #1
	bl func_fe6_080763D8
	ldr r7, .L080752F4 @ =gDispIo
	movs r0, #0x20
	ldrb r1, [r7, #1]
	orrs r0, r1
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r7, #1]
	adds r1, r7, #0
	adds r1, #0x2d
	movs r5, #0x10
	movs r0, #0x10
	strb r0, [r1]
	adds r1, #4
	movs r0, #0x38
	strb r0, [r1]
	subs r1, #5
	movs r0, #0xe0
	strb r0, [r1]
	adds r1, #4
	movs r0, #0x98
	strb r0, [r1]
	adds r2, r7, #0
	adds r2, #0x34
	movs r6, #1
	mov sb, r6
	ldrb r0, [r2]
	mov r1, sb
	orrs r0, r1
	movs r4, #2
	orrs r0, r4
	movs r3, #4
	orrs r0, r3
	movs r1, #8
	orrs r0, r1
	orrs r0, r5
	strb r0, [r2]
	adds r2, #2
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r6, [r2]
	ands r0, r6
	orrs r0, r4
	orrs r0, r3
	orrs r0, r1
	orrs r0, r5
	strb r0, [r2]
	movs r0, #0xf
	bl EnableBgSync
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	ldr r0, [sp, #0x10]
	ldrh r2, [r0]
	subs r2, #0x38
	movs r0, #0xff
	ands r2, r0
	movs r0, #0
	movs r1, #0
	bl SetBgOffset
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	ldrb r2, [r7, #0xc]
	ands r0, r2
	strb r0, [r7, #0xc]
	adds r0, r1, #0
	ldrb r6, [r7, #0x10]
	ands r0, r6
	orrs r0, r4
	strb r0, [r7, #0x10]
	ldrb r0, [r7, #0x14]
	ands r1, r0
	mov r2, sb
	orrs r1, r2
	strb r1, [r7, #0x14]
	movs r0, #3
	ldrb r6, [r7, #0x18]
	orrs r0, r6
	strb r0, [r7, #0x18]
	ldr r0, .L080752F8 @ =gUnk_08320EEC
	ldr r1, .L080752FC @ =gBg1Tm+0x500
	bl Decompress
	ldr r0, .L08075300 @ =gUnk_08319E88
	movs r1, #0xf0
	lsls r1, r1, #1
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, .L08075304 @ =gUnk_086786F4
	mov r1, r8
	bl SpawnProc
	mov r1, r8
	str r0, [r1, #0x44]
	ldr r2, [sp, #0xc]
	ldrb r2, [r2]
	cmp r2, #1
	bne .L08075310
	mov r0, r8
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08075310
	ldr r4, .L08075308 @ =gUnk_0831B0A8
	movs r0, #3
	bl GetBgChrOffset
	adds r1, r0, #0
	movs r6, #0xc0
	lsls r6, r6, #0x13
	adds r1, r1, r6
	adds r0, r4, #0
	bl Decompress
	ldr r0, .L0807530C @ =gUnk_08320D98
	movs r1, #0xa0
	lsls r1, r1, #1
	movs r2, #0x80
	bl ApplyPaletteExt
	mov r0, r8
	bl func_fe6_08082560
	mov r1, r8
	str r0, [r1, #0x48]
	b .L0807531E
	.align 2, 0
.L080752EC: .4byte gBg0Tm
.L080752F0: .4byte 0x0200CD38
.L080752F4: .4byte gDispIo
.L080752F8: .4byte gUnk_08320EEC
.L080752FC: .4byte gBg1Tm+0x500
.L08075300: .4byte gUnk_08319E88
.L08075304: .4byte gUnk_086786F4
.L08075308: .4byte gUnk_0831B0A8
.L0807530C: .4byte gUnk_08320D98
.L08075310:
	movs r0, #0
	movs r1, #0
	movs r2, #0xa
	bl StartMuralBackground
	mov r2, r8
	str r0, [r2, #0x48]
.L0807531E:
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0
	bl func_fe6_08070E70
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08075338
func_fe6_08075338: @ 0x08075338
	push {lr}
	adds r3, r0, #0
	adds r0, #0x29
	movs r1, #0
	strb r1, [r0]
	adds r0, #8
	movs r2, #1
	strb r2, [r0]
	subs r0, #5
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #3
	strb r1, [r0]
	adds r0, #9
	ldrb r0, [r0]
	cmp r0, #3
	bne .L08075364
	adds r0, r3, #0
	adds r0, #0x2f
	strb r1, [r0]
	b .L0807536A
.L08075364:
	adds r0, r3, #0
	adds r0, #0x2f
	strb r2, [r0]
.L0807536A:
	ldrb r0, [r0]
	adds r1, r3, #0
	adds r1, #0x36
	movs r2, #0
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0
	strh r2, [r0]
	adds r2, r3, #0
	adds r2, #0x32
	movs r0, #1
	strb r0, [r2]
	subs r2, #8
	strb r1, [r2]
	adds r2, #9
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x34
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, r3, #0
	bl func_fe6_08074EF0
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080753A0
func_fe6_080753A0: @ 0x080753A0
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r0, #0x30
	ldrb r7, [r0]
	adds r4, r7, #0
	ldr r1, .L0807542C @ =0x0200CC38
	lsls r0, r7, #2
	adds r6, r0, r1
	ldr r0, [r6]
	ldr r1, [r0]
	movs r0, #8
	ldrh r2, [r1, #0xc]
	ands r0, r2
	cmp r0, #0
	beq .L08075470
	adds r0, r5, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #0
	beq .L080753D6
	adds r0, r1, #0
	bl func_fe6_08082B74
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08075454
.L080753D6:
	adds r0, r5, #0
	adds r0, #0x3a
	adds r4, r5, #0
	adds r4, #0x3b
	ldrb r0, [r0]
	ldrb r1, [r4]
	cmp r0, r1
	bls .L0807543C
	ldr r0, [r6]
	ldr r1, [r0]
	ldr r0, .L08075430 @ =0x0000FFF5
	ldrh r2, [r1, #0xc]
	ands r0, r2
	strh r0, [r1, #0xc]
	ldr r0, [r6]
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	bl func_fe6_080791B4
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldr r0, .L08075434 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08075414
	movs r0, #0x6a
	bl m4aSongNumStart
.L08075414:
	ldr r2, .L08075438 @ =gBg0Tm
	adds r0, r5, #0
	adds r0, #0x2f
	ldrb r3, [r0]
	movs r0, #1
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r7, #0
	bl func_fe6_08076448
	b .L080754E8
	.align 2, 0
.L0807542C: .4byte 0x0200CC38
.L08075430: .4byte 0x0000FFF5
.L08075434: .4byte gPlaySt
.L08075438: .4byte gBg0Tm
.L0807543C:
	ldr r0, .L08075450 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L080754E8
	movs r0, #0x6c
	bl m4aSongNumStart
	b .L080754E8
	.align 2, 0
.L08075450: .4byte gPlaySt
.L08075454:
	adds r0, r5, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	lsls r1, r0, #4
	adds r1, #0x38
	ldr r2, .L0807546C @ =0x000006C1
	movs r0, #0
	adds r3, r5, #0
	bl func_fe6_08082B00
	b .L080754E8
	.align 2, 0
.L0807546C: .4byte 0x000006C1
.L08075470:
	adds r0, r5, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08075486
	adds r0, r1, #0
	bl func_fe6_08079404
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L080754D8
.L08075486:
	ldr r0, [r6]
	ldr r1, [r0]
	movs r0, #0xa
	ldrh r2, [r1, #0xc]
	orrs r0, r2
	strh r0, [r1, #0xc]
	ldr r0, [r6]
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	bl func_fe6_080791DC
	ldr r0, .L080754D0 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L080754AE
	movs r0, #0x6b
	bl m4aSongNumStart
.L080754AE:
	adds r1, r5, #0
	adds r1, #0x3b
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	ldr r2, .L080754D4 @ =gBg0Tm
	adds r0, r5, #0
	adds r0, #0x2f
	ldrb r3, [r0]
	movs r0, #1
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r4, #0
	bl func_fe6_08076448
	b .L080754E8
	.align 2, 0
.L080754D0: .4byte gPlaySt
.L080754D4: .4byte gBg0Tm
.L080754D8:
	ldr r0, .L080754F0 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L080754E8
	movs r0, #0x6c
	bl m4aSongNumStart
.L080754E8:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080754F0: .4byte gPlaySt

	thumb_func_start func_fe6_080754F4
func_fe6_080754F4: @ 0x080754F4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, [r6]
	ldrb r0, [r0, #4]
	cmp r0, #0x42
	bne .L08075518
	ldr r0, .L08075514 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08075564
	movs r0, #0x6c
	bl m4aSongNumStart
	b .L08075564
	.align 2, 0
.L08075514: .4byte gPlaySt
.L08075518:
	ldrh r4, [r6, #0xc]
	movs r5, #0xc0
	lsls r5, r5, #8
	lsrs r2, r4, #0xe
	adds r0, r2, r1
	adds r0, #3
	movs r1, #3
	bl __modsi3
	lsls r2, r0, #0xe
	ldr r0, .L0807554C @ =0x00003FFF
	ands r0, r4
	orrs r0, r2
	strh r0, [r6, #0xc]
	ands r2, r5
	cmp r2, #0
	beq .L08075554
	ldr r0, .L08075550 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08075564
	movs r0, #0x6a
	bl m4aSongNumStart
	b .L08075564
	.align 2, 0
.L0807554C: .4byte 0x00003FFF
.L08075550: .4byte gPlaySt
.L08075554:
	ldr r0, .L0807556C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08075564
	movs r0, #0x6b
	bl m4aSongNumStart
.L08075564:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0807556C: .4byte gPlaySt

	thumb_func_start func_fe6_08075570
func_fe6_08075570: @ 0x08075570
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	str r0, [sp, #4]
	adds r5, r7, #0
	adds r5, #0x29
	ldrb r0, [r5]
	cmp r0, #1
	bne .L08075590
	b .L080759A2
.L08075590:
	cmp r0, #1
	bgt .L0807559A
	cmp r0, #0
	beq .L080755AE
	b .L080758C6
.L0807559A:
	cmp r0, #2
	bne .L080755A0
	b .L080759B4
.L080755A0:
	cmp r0, #3
	bne .L080755A6
	b .L080759F2
.L080755A6:
	movs r1, #0x2b
	adds r1, r1, r7
	mov r8, r1
	b .L08075CB2
.L080755AE:
	ldr r2, .L080755C8 @ =gKeySt
	ldr r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ldrh r1, [r1, #4]
	ands r0, r1
	cmp r0, #0
	beq .L080755CC
	adds r1, r7, #0
	adds r1, #0x31
	movs r0, #2
	b .L080755D2
	.align 2, 0
.L080755C8: .4byte gKeySt
.L080755CC:
	adds r1, r7, #0
	adds r1, #0x31
	movs r0, #1
.L080755D2:
	strb r0, [r1]
	mov sb, r1
	ldr r1, [r2]
	ldrh r2, [r1, #8]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0
	beq .L080755F2
	adds r0, r7, #0
	movs r1, #3
	bl Proc_Goto
	b .L08075D18
.L080755F2:
	movs r3, #1
	mov r8, r3
	mov r5, r8
	ands r5, r2
	cmp r5, #0
	beq .L080756A0
	adds r0, r7, #0
	adds r0, #0x39
	ldrb r0, [r0]
	cmp r0, #1
	beq .L0807561E
	cmp r0, #1
	bgt .L08075612
	cmp r0, #0
	beq .L08075660
	b .L08075690
.L08075612:
	cmp r0, #3
	beq .L08075626
	movs r6, #0x2b
	adds r6, r6, r7
	mov r8, r6
	b .L08075CB2
.L0807561E:
	adds r0, r7, #0
	bl func_fe6_080753A0
	b .L080758C6
.L08075626:
	ldr r1, .L08075658 @ =0x0200CC38
	adds r4, r7, #0
	adds r4, #0x30
	ldrb r2, [r4]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	movs r1, #1
	bl func_fe6_080754F4
	ldrb r1, [r4]
	ldr r2, .L0807565C @ =gBg0Tm
	adds r0, r7, #0
	adds r0, #0x2f
	ldrb r3, [r0]
	str r6, [sp]
	adds r0, r7, #0
	bl func_fe6_08076448
	movs r3, #0x2b
	adds r3, r3, r7
	mov r8, r3
	b .L08075CB2
	.align 2, 0
.L08075658: .4byte 0x0200CC38
.L0807565C: .4byte gBg0Tm
.L08075660:
	ldr r1, .L08075698 @ =0x0200CC38
	adds r0, r7, #0
	adds r0, #0x30
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, #0xb]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl SetStatScreenLastUnitId
	ldr r0, .L0807569C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807568A
	movs r0, #0x6a
	bl m4aSongNumStart
.L0807568A:
	adds r0, r7, #0
	bl Proc_Break
.L08075690:
	movs r4, #0x2b
	adds r4, r4, r7
	mov r8, r4
	b .L08075CB2
	.align 2, 0
.L08075698: .4byte 0x0200CC38
.L0807569C: .4byte gPlaySt
.L080756A0:
	ldrh r3, [r1, #6]
	movs r4, #0x20
	adds r0, r4, #0
	ands r0, r3
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0
	beq .L0807573C
	adds r0, r7, #0
	adds r0, #0x39
	ldrb r0, [r0]
	cmp r0, #3
	bne .L080756F8
	adds r0, r4, #0
	ands r0, r2
	movs r6, #0x2b
	adds r6, r6, r7
	mov r8, r6
	cmp r0, #0
	bne .L080756CA
	b .L08075CB2
.L080756CA:
	ldr r1, .L080756F0 @ =0x0200CC38
	adds r4, r7, #0
	adds r4, #0x30
	ldrb r2, [r4]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	bl func_fe6_080754F4
	ldrb r1, [r4]
	ldr r2, .L080756F4 @ =gBg0Tm
	adds r0, r7, #0
	adds r0, #0x2f
	ldrb r3, [r0]
	str r5, [sp]
	b .L08075782
	.align 2, 0
.L080756F0: .4byte 0x0200CC38
.L080756F4: .4byte gBg0Tm
.L080756F8:
	adds r0, r7, #0
	adds r0, #0x2f
	movs r3, #0x2b
	adds r3, r3, r7
	mov r8, r3
	ldrb r0, [r0]
	cmp r0, #1
	bhi .L0807570A
	b .L08075CB2
.L0807570A:
	adds r1, r7, #0
	adds r1, #0x36
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	movs r1, #2
	bl Proc_Goto
	adds r0, r7, #0
	adds r0, #0x2d
	strb r5, [r0]
	ldr r0, .L08075738 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	bge .L0807572E
	b .L08075CB2
.L0807572E:
	movs r0, #0x6f
	bl m4aSongNumStart
	b .L08075CB2
	.align 2, 0
.L08075738: .4byte gPlaySt
.L0807573C:
	movs r4, #0x10
	adds r0, r4, #0
	ands r0, r3
	cmp r0, #0
	beq .L080757D4
	adds r0, r7, #0
	adds r0, #0x39
	ldrb r0, [r0]
	cmp r0, #3
	bne .L08075794
	adds r0, r4, #0
	ands r0, r2
	movs r4, #0x2b
	adds r4, r4, r7
	mov r8, r4
	cmp r0, #0
	bne .L08075760
	b .L08075CB2
.L08075760:
	ldr r1, .L0807578C @ =0x0200CC38
	adds r4, r7, #0
	adds r4, #0x30
	ldrb r2, [r4]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	movs r1, #1
	bl func_fe6_080754F4
	ldrb r1, [r4]
	ldr r2, .L08075790 @ =gBg0Tm
	adds r0, r7, #0
	adds r0, #0x2f
	ldrb r3, [r0]
	str r6, [sp]
.L08075782:
	adds r0, r7, #0
	bl func_fe6_08076448
	b .L08075CB2
	.align 2, 0
.L0807578C: .4byte 0x0200CC38
.L08075790: .4byte gBg0Tm
.L08075794:
	adds r0, r7, #0
	adds r0, #0x2f
	adds r1, r7, #0
	adds r1, #0x2e
	movs r3, #0x2b
	adds r3, r3, r7
	mov r8, r3
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	blo .L080757AC
	b .L08075CB2
.L080757AC:
	adds r1, r7, #0
	adds r1, #0x36
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x2d
	strb r6, [r0]
	ldr r0, .L080757D0 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	bge .L080757C8
	b .L08075C48
.L080757C8:
	movs r0, #0x6f
	bl m4aSongNumStart
	b .L08075C48
	.align 2, 0
.L080757D0: .4byte gPlaySt
.L080757D4:
	movs r4, #0x40
	adds r0, r4, #0
	ands r0, r3
	cmp r0, #0
	bne .L080757F4
	movs r0, #0x80
	lsls r0, r0, #2
	ldrh r6, [r1, #4]
	ands r0, r6
	cmp r0, #0
	beq .L080758CE
	adds r0, r4, #0
	ldrh r1, [r1, #0x10]
	ands r0, r1
	cmp r0, #0
	beq .L080758CE
.L080757F4:
	adds r5, r7, #0
	adds r5, #0x30
	ldrb r0, [r5]
	cmp r0, #0
	bne .L0807582C
	adds r0, r4, #0
	ands r0, r2
	movs r1, #0x2b
	adds r1, r1, r7
	mov r8, r1
	cmp r0, #0
	bne .L0807580E
	b .L08075CB2
.L0807580E:
	ldr r0, .L08075828 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807581E
	movs r0, #0x66
	bl m4aSongNumStart
.L0807581E:
	adds r1, r7, #0
	adds r1, #0x29
	movs r0, #3
	strb r0, [r1]
	b .L08075CB2
	.align 2, 0
.L08075828: .4byte gPlaySt
.L0807582C:
	subs r0, #1
	strb r0, [r5]
	ldr r0, .L080758B8 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08075840
	movs r0, #0x66
	bl m4aSongNumStart
.L08075840:
	adds r0, r7, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	adds r4, r0, #0
	cmp r1, #1
	bhi .L080758C0
	adds r6, r7, #0
	adds r6, #0x40
	ldrh r2, [r6]
	lsrs r0, r2, #4
	cmp r0, #0
	beq .L080758C0
	cmp r1, #0
	bne .L08075866
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	movs r0, #1
	strb r0, [r4]
.L08075866:
	ldrh r3, [r6]
	lsrs r1, r3, #4
	subs r1, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, .L080758BC @ =gBg0Tm
	adds r0, r7, #0
	adds r0, #0x2f
	ldrb r3, [r0]
	mov r0, r8
	str r0, [sp]
	adds r0, r7, #0
	bl func_fe6_08076448
	adds r1, r7, #0
	adds r1, #0x29
	movs r0, #2
	strb r0, [r1]
	mov r1, sb
	ldrb r1, [r1]
	lsls r2, r1, #2
	ldrh r3, [r6]
	subs r2, r3, r2
	strh r2, [r6]
	subs r2, #0x38
	movs r0, #0xff
	ands r2, r0
	movs r0, #0
	movs r1, #0
	bl SetBgOffset
	ldrb r0, [r4]
	movs r6, #0x2b
	adds r6, r6, r7
	mov r8, r6
	cmp r0, #0
	beq .L080758B2
	b .L08075CB2
.L080758B2:
	adds r0, #1
	strb r0, [r4]
	b .L08075CB2
	.align 2, 0
.L080758B8: .4byte gPlaySt
.L080758BC: .4byte gBg0Tm
.L080758C0:
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
.L080758C6:
	movs r0, #0x2b
	adds r0, r0, r7
	mov r8, r0
	b .L08075CB2
.L080758CE:
	ldr r0, .L08075984 @ =gKeySt
	ldr r1, [r0]
	movs r2, #0x80
	adds r0, r2, #0
	ldrh r3, [r1, #6]
	ands r0, r3
	cmp r0, #0
	bne .L080758FE
	movs r0, #0x80
	lsls r0, r0, #2
	ldrh r4, [r1, #4]
	ands r0, r4
	movs r6, #0x2b
	adds r6, r6, r7
	mov r8, r6
	cmp r0, #0
	bne .L080758F2
	b .L08075CB2
.L080758F2:
	adds r0, r2, #0
	ldrh r1, [r1, #0x10]
	ands r0, r1
	cmp r0, #0
	bne .L080758FE
	b .L08075CB2
.L080758FE:
	adds r5, r7, #0
	adds r5, #0x30
	ldrb r1, [r5]
	ldr r6, .L08075988 @ =0x0200CD38
	ldrb r0, [r6]
	subs r0, #1
	movs r2, #0x2b
	adds r2, r2, r7
	mov r8, r2
	cmp r1, r0
	blt .L08075916
	b .L08075CB2
.L08075916:
	adds r0, r1, #1
	strb r0, [r5]
	ldr r0, .L0807598C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807592A
	movs r0, #0x66
	bl m4aSongNumStart
.L0807592A:
	adds r0, r7, #0
	adds r0, #0x2c
	adds r4, r0, #0
	ldrb r3, [r4]
	cmp r3, #4
	bne .L08075994
	ldrb r1, [r5]
	ldrb r0, [r6]
	subs r0, #1
	cmp r1, r0
	beq .L08075994
	adds r4, r7, #0
	adds r4, #0x40
	ldrh r6, [r4]
	lsrs r1, r6, #4
	adds r1, #6
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, .L08075990 @ =gBg0Tm
	adds r0, r7, #0
	adds r0, #0x2f
	ldrb r3, [r0]
	movs r5, #1
	str r5, [sp]
	adds r0, r7, #0
	bl func_fe6_08076448
	adds r0, r7, #0
	adds r0, #0x29
	strb r5, [r0]
	mov r0, sb
	ldrb r0, [r0]
	lsls r2, r0, #2
	ldrh r1, [r4]
	adds r2, r1, r2
	strh r2, [r4]
	subs r2, #0x38
	movs r0, #0xff
	ands r2, r0
	movs r0, #0
	movs r1, #0
	bl SetBgOffset
	b .L08075CB2
	.align 2, 0
.L08075984: .4byte gKeySt
.L08075988: .4byte 0x0200CD38
.L0807598C: .4byte gPlaySt
.L08075990: .4byte gBg0Tm
.L08075994:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	movs r2, #0x2b
	adds r2, r2, r7
	mov r8, r2
	b .L08075CB2
.L080759A2:
	adds r4, r7, #0
	adds r4, #0x40
	adds r0, r7, #0
	adds r0, #0x31
	ldrb r0, [r0]
	lsls r2, r0, #2
	ldrh r3, [r4]
	adds r2, r3, r2
	b .L080759C4
.L080759B4:
	adds r4, r7, #0
	adds r4, #0x40
	adds r0, r7, #0
	adds r0, #0x31
	ldrb r0, [r0]
	lsls r2, r0, #2
	ldrh r3, [r4]
	subs r2, r3, r2
.L080759C4:
	strh r2, [r4]
	subs r2, #0x38
	movs r0, #0xff
	ands r2, r0
	movs r0, #0
	movs r1, #0
	bl SetBgOffset
	movs r0, #0xf
	ldrh r6, [r4]
	ands r0, r6
	movs r1, #0x2b
	adds r1, r1, r7
	mov r8, r1
	cmp r0, #0
	beq .L080759E6
	b .L08075CB2
.L080759E6:
	movs r0, #0
	strb r0, [r5]
	ldrh r0, [r4]
	bl func_fe6_080743C8
	b .L08075CB2
.L080759F2:
	adds r1, r7, #0
	adds r1, #0x2b
	ldrb r0, [r1]
	ldr r2, .L08075A1C @ =gKeySt
	mov r8, r1
	cmp r0, #0
	beq .L08075A20
	ldr r1, [r2]
	movs r0, #0x81
	lsls r0, r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L08075A20
	bl CloseHelpBox
	movs r0, #0
	mov r2, r8
	strb r0, [r2]
	b .L08075D18
	.align 2, 0
.L08075A1C: .4byte gKeySt
.L08075A20:
	ldr r1, [r2]
	movs r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L08075B14
	mov r3, r8
	ldrb r0, [r3]
	cmp r0, #0
	bne .L08075B14
	adds r1, r7, #0
	adds r1, #0x32
	ldrb r4, [r1]
	str r4, [sp, #8]
	adds r2, r7, #0
	adds r2, #0x2a
	movs r0, #1
	strb r0, [r2]
	ldr r0, .L08075AAC @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	mov sb, r1
	cmp r0, #0
	blt .L08075A56
	movs r0, #0x6a
	bl m4aSongNumStart
.L08075A56:
	ldr r1, .L08075AB0 @ =gUnk_08678840
	adds r6, r7, #0
	adds r6, #0x2d
	adds r5, r7, #0
	adds r5, #0x2f
	ldrb r2, [r5]
	lsls r0, r2, #3
	adds r0, r0, r2
	ldrb r3, [r6]
	adds r0, r3, r0
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r4, sb
	strb r0, [r4]
	adds r4, r7, #0
	adds r4, #0x33
	ldrb r0, [r4]
	adds r0, #1
	movs r1, #1
	ands r0, r1
	strb r0, [r4]
	mov r1, sb
	ldrb r0, [r1]
	ldrb r1, [r4]
	bl func_fe6_08076D3C
	lsls r0, r0, #0x18
	mov sl, r6
	str r4, [sp, #0xc]
	adds r2, r7, #0
	adds r2, #0x34
	str r2, [sp, #0x10]
	adds r3, r7, #0
	adds r3, #0x35
	str r3, [sp, #0x14]
	cmp r0, #0
	beq .L08075AE4
	movs r4, #0
	ldr r0, .L08075AB4 @ =0x0200CD38
	adds r6, #0x13
	b .L08075AD2
	.align 2, 0
.L08075AAC: .4byte gPlaySt
.L08075AB0: .4byte gUnk_08678840
.L08075AB4: .4byte 0x0200CD38
.L08075AB8:
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	ldrb r3, [r5]
	movs r0, #1
	str r0, [sp]
	adds r0, r7, #0
	ldr r2, .L08075B0C @ =gBg0Tm
	bl func_fe6_08076448
	adds r4, #1
	cmp r4, #5
	bgt .L08075AD8
	ldr r0, .L08075B10 @ =0x0200CD38
.L08075AD2:
	ldrb r0, [r0]
	cmp r4, r0
	blt .L08075AB8
.L08075AD8:
	ldrh r0, [r6]
	bl func_fe6_080743C8
	movs r0, #1
	bl EnableBgSync
.L08075AE4:
	ldr r4, [sp, #0xc]
	ldrb r0, [r4]
	ldr r6, [sp, #0x10]
	strb r0, [r6]
	mov r1, sl
	ldrb r0, [r1]
	ldr r2, [sp, #0x14]
	strb r0, [r2]
	mov r3, sb
	ldrb r3, [r3]
	ldr r4, [sp, #8]
	cmp r3, r4
	bne .L08075B00
	b .L08075CB2
.L08075B00:
	mov r6, sb
	ldrb r0, [r6]
	bl func_fe6_080742D0
	b .L08075CB2
	.align 2, 0
.L08075B0C: .4byte gBg0Tm
.L08075B10: .4byte 0x0200CD38
.L08075B14:
	ldr r1, [r2]
	movs r0, #0x80
	ldrh r1, [r1, #6]
	ands r0, r1
	cmp r0, #0
	beq .L08075B4C
	mov r0, r8
	ldrb r4, [r0]
	cmp r4, #0
	bne .L08075B4C
	ldr r0, .L08075B48 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08075B38
	movs r0, #0x66
	bl m4aSongNumStart
.L08075B38:
	adds r1, r7, #0
	adds r1, #0x33
	movs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x29
	strb r4, [r0]
	b .L08075CB2
	.align 2, 0
.L08075B48: .4byte gPlaySt
.L08075B4C:
	ldr r1, [r2]
	ldrh r3, [r1, #6]
	movs r0, #0x20
	ands r0, r3
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq .L08075BE2
	adds r1, r7, #0
	adds r1, #0x33
	movs r0, #1
	strb r0, [r1]
	subs r1, #6
	ldrb r0, [r1]
	mov sl, r1
	cmp r0, #0
	bne .L08075BDC
	adds r0, r7, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #1
	bhi .L08075B7A
	b .L08075CB2
.L08075B7A:
	adds r0, r7, #0
	adds r0, #0x39
	ldrb r0, [r0]
	cmp r0, #3
	bne .L08075B86
	b .L08075CB2
.L08075B86:
	ldr r0, .L08075BD4 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08075B96
	movs r0, #0x6f
	bl m4aSongNumStart
.L08075B96:
	adds r1, r7, #0
	adds r1, #0x36
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	movs r4, #8
	ldr r2, .L08075BD8 @ =gUnk_08678840
	lsls r0, r0, #3
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r1, r0, #4
	adds r0, r1, #0
	adds r0, #0x80
	adds r0, r0, r2
	ldrb r0, [r0, #8]
	cmp r0, #0
	bne .L08075BCC
	adds r0, r1, r2
	adds r1, r0, #0
	adds r1, #0x80
.L08075BBE:
	subs r1, #0x10
	subs r4, #1
	cmp r4, #0
	ble .L08075BCC
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq .L08075BBE
.L08075BCC:
	mov r1, sl
	strb r4, [r1]
	b .L08075C48
	.align 2, 0
.L08075BD4: .4byte gPlaySt
.L08075BD8: .4byte gUnk_08678840
.L08075BDC:
	subs r0, #1
	strb r0, [r1]
	b .L08075C5E
.L08075BE2:
	movs r0, #0x10
	ands r0, r3
	cmp r0, #0
	beq .L08075C74
	adds r1, r7, #0
	adds r1, #0x33
	movs r0, #1
	strb r0, [r1]
	adds r2, r7, #0
	adds r2, #0x2d
	adds r5, r7, #0
	adds r5, #0x2f
	ldrb r3, [r2]
	cmp r3, #8
	beq .L08075C16
	ldr r0, .L08075C54 @ =gUnk_08678840
	adds r3, #1
	ldrb r6, [r5]
	lsls r1, r6, #3
	adds r1, r1, r6
	adds r1, r1, r3
	lsls r1, r1, #4
	adds r1, r1, r0
	ldrb r0, [r1, #8]
	cmp r0, #0
	bne .L08075C5C
.L08075C16:
	adds r0, r7, #0
	adds r0, #0x2e
	ldrb r5, [r5]
	ldrb r0, [r0]
	cmp r5, r0
	bhs .L08075CB2
	adds r0, r7, #0
	adds r0, #0x39
	ldrb r0, [r0]
	cmp r0, #3
	beq .L08075CB2
	strb r4, [r2]
	ldr r0, .L08075C58 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08075C3E
	movs r0, #0x6f
	bl m4aSongNumStart
.L08075C3E:
	adds r1, r7, #0
	adds r1, #0x36
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
.L08075C48:
	adds r0, r7, #0
	movs r1, #2
	bl Proc_Goto
	b .L08075CB2
	.align 2, 0
.L08075C54: .4byte gUnk_08678840
.L08075C58: .4byte gPlaySt
.L08075C5C:
	strb r3, [r2]
.L08075C5E:
	ldr r0, .L08075C70 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08075CB2
	movs r0, #0x67
	bl m4aSongNumStart
	b .L08075CB2
	.align 2, 0
.L08075C70: .4byte gPlaySt
.L08075C74:
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L08075CB2
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0
	bne .L08075CB2
	movs r0, #1
	strb r0, [r1]
	ldr r2, .L08075D28 @ =gUnk_08678840
	adds r3, r7, #0
	adds r3, #0x2d
	adds r0, r7, #0
	adds r0, #0x2f
	ldrb r4, [r0]
	lsls r1, r4, #3
	adds r1, r1, r4
	ldrb r3, [r3]
	adds r1, r3, r1
	lsls r1, r1, #4
	adds r0, r1, r2
	ldrb r0, [r0, #8]
	adds r2, #0xc
	adds r1, r1, r2
	ldr r2, [r1]
	movs r1, #0x28
	bl StartHelpBox
.L08075CB2:
	ldr r0, .L08075D2C @ =gKeySt
	ldr r1, [r0]
	movs r0, #2
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L08075CE4
	mov r6, r8
	ldrb r0, [r6]
	cmp r0, #0
	bne .L08075CEC
	ldr r0, .L08075D30 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08075CD8
	movs r0, #0x6b
	bl m4aSongNumStart
.L08075CD8:
	movs r0, #0
	bl SetStatScreenLastUnitId
	adds r0, r7, #0
	bl Proc_Break
.L08075CE4:
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0
	beq .L08075D18
.L08075CEC:
	adds r3, r7, #0
	adds r3, #0x2d
	ldr r2, [sp, #4]
	ldrb r4, [r3]
	cmp r2, r4
	beq .L08075D18
	ldr r2, .L08075D28 @ =gUnk_08678840
	adds r0, r7, #0
	adds r0, #0x36
	ldrb r6, [r0]
	lsls r1, r6, #3
	adds r1, r1, r6
	adds r1, r4, r1
	lsls r1, r1, #4
	adds r0, r1, r2
	ldrb r0, [r0, #8]
	adds r2, #0xc
	adds r1, r1, r2
	ldr r2, [r1]
	movs r1, #0x28
	bl StartHelpBox
.L08075D18:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08075D28: .4byte gUnk_08678840
.L08075D2C: .4byte gKeySt
.L08075D30: .4byte gPlaySt

	thumb_func_start func_fe6_08075D34
func_fe6_08075D34: @ 0x08075D34
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x39
	ldrb r0, [r0]
	cmp r0, #1
	bne .L08075D5C
	ldr r2, .L08075DDC @ =0x0200E7D8
	ldr r1, .L08075DE0 @ =0x0200CC38
	adds r0, r4, #0
	adds r0, #0x30
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	str r0, [r2]
	bl func_fe6_080741EC
.L08075D5C:
	ldr r2, .L08075DE4 @ =gPlaySt
	adds r0, r4, #0
	adds r0, #0x34
	ldrb r0, [r0]
	lsls r0, r0, #7
	adds r1, r4, #0
	adds r1, #0x32
	ldrb r1, [r1]
	adds r0, r1, r0
	strb r0, [r2, #0x1a]
	adds r0, r4, #0
	adds r0, #0x2f
	ldrb r1, [r0]
	cmp r1, #0
	beq .L08075D86
	lsls r1, r1, #4
	movs r0, #0xf
	ldrb r3, [r2, #0x19]
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, #0x19]
.L08075D86:
	ldr r0, [r4, #0x44]
	bl Proc_End
	ldr r0, [r4, #0x48]
	cmp r0, #0
	beq .L08075D96
	bl Proc_End
.L08075D96:
	bl EndGreenText
	ldr r0, .L08075DE8 @ =gBg0Tm
	movs r1, #0
	bl TmFill
	ldr r0, .L08075DEC @ =gBg1Tm
	movs r1, #0
	bl TmFill
	ldr r0, .L08075DF0 @ =gBg2Tm
	movs r1, #0
	bl TmFill
	movs r0, #0xf
	bl EnableBgSync
	ldr r2, .L08075DF4 @ =gDispIo
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
	bl ResetTextFont
	bl ClearIcons
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08075DDC: .4byte 0x0200E7D8
.L08075DE0: .4byte 0x0200CC38
.L08075DE4: .4byte gPlaySt
.L08075DE8: .4byte gBg0Tm
.L08075DEC: .4byte gBg1Tm
.L08075DF0: .4byte gBg2Tm
.L08075DF4: .4byte gDispIo

	thumb_func_start func_fe6_08075DF8
func_fe6_08075DF8: @ 0x08075DF8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, .L08075E20 @ =0x0200CD3A
	movs r1, #0x1f
	movs r2, #0x1f
	movs r3, #0
	bl TmFillRect_thm
	adds r0, r5, #0
	adds r0, #0x40
	ldrh r0, [r0]
	lsrs r4, r0, #4
	adds r0, r4, #6
	cmp r4, r0
	bge .L08075E52
	ldr r0, .L08075E24 @ =0x0200CD38
	adds r6, r5, #0
	adds r6, #0x2f
	b .L08075E4C
	.align 2, 0
.L08075E20: .4byte 0x0200CD3A
.L08075E24: .4byte 0x0200CD38
.L08075E28:
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	ldrb r3, [r6]
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	ldr r2, .L08075E88 @ =0x0200CD3A
	bl func_fe6_08076448
	adds r4, #1
	adds r0, r5, #0
	adds r0, #0x40
	ldrh r0, [r0]
	lsrs r0, r0, #4
	adds r0, #6
	cmp r4, r0
	bge .L08075E52
	ldr r0, .L08075E8C @ =0x0200CD38
.L08075E4C:
	ldrb r0, [r0]
	cmp r4, r0
	blt .L08075E28
.L08075E52:
	ldr r4, .L08075E90 @ =0x0200D53A
	adds r0, r4, #0
	movs r1, #0x1f
	movs r2, #1
	movs r3, #0
	bl TmFillRect_thm
	adds r6, r5, #0
	adds r6, #0x2f
	ldrb r1, [r6]
	adds r0, r4, #0
	bl func_fe6_08076314
	movs r1, #0
	movs r0, #0
	strh r0, [r5, #0x3e]
	ldrb r0, [r6]
	adds r2, r5, #0
	adds r2, #0x37
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x38
	strb r1, [r0]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08075E88: .4byte 0x0200CD3A
.L08075E8C: .4byte 0x0200CD38
.L08075E90: .4byte 0x0200D53A

	thumb_func_start func_fe6_08075E94
func_fe6_08075E94: @ 0x08075E94
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	adds r1, r7, #0
	adds r1, #0x38
	ldr r0, .L08075EF8 @ =gUnk_0867871C
	ldrh r2, [r7, #0x3e]
	adds r0, r2, r0
	ldrb r2, [r1]
	ldrb r0, [r0]
	adds r0, r2, r0
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x14
	bls .L08075EC0
	movs r0, #0x14
	strb r0, [r1]
.L08075EC0:
	ldrh r0, [r7, #0x3e]
	adds r0, #1
	strh r0, [r7, #0x3e]
	movs r3, #0
	str r1, [sp, #0x10]
	adds r0, r7, #0
	adds r0, #0x36
	str r0, [sp, #0xc]
	adds r1, r7, #0
	adds r1, #0x2f
	str r1, [sp, #8]
	adds r2, r7, #0
	adds r2, #0x40
	str r2, [sp, #0x14]
	ldr r0, [sp, #0x10]
	str r0, [sp, #4]
.L08075EE0:
	ldr r1, [sp, #0xc]
	ldrb r2, [r1]
	ldr r1, [sp, #8]
	ldrb r1, [r1]
	cmp r2, r1
	bls .L08075EFC
	ldr r2, [sp, #4]
	ldrb r2, [r2]
	adds r0, r2, r3
	cmp r0, #0x14
	bgt .L08075F04
	b .L08075F0A
	.align 2, 0
.L08075EF8: .4byte gUnk_0867871C
.L08075EFC:
	ldr r1, [sp, #4]
	ldrb r0, [r1]
	cmp r3, r0
	bge .L08075F08
.L08075F04:
	movs r1, #0
	b .L08075F10
.L08075F08:
	subs r0, r3, r0
.L08075F0A:
	adds r0, #8
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
.L08075F10:
	ldr r6, [sp, #0x14]
	ldrh r2, [r6]
	lsrs r4, r2, #3
	adds r0, r4, #0
	adds r0, #0xc
	lsls r5, r1, #1
	adds r1, r3, #1
	mov sl, r1
	cmp r4, r0
	bge .L08075F58
	movs r2, #0x1f
	mov sb, r2
	ldr r0, .L08075FD8 @ =gBg0Tm
	mov r8, r0
	ldr r1, .L08075FDC @ =0x0200CD3A
	mov ip, r1
	adds r2, r5, #0
.L08075F32:
	adds r0, r4, #0
	mov r1, sb
	ands r0, r1
	lsls r1, r0, #5
	adds r1, #8
	adds r1, r1, r3
	lsls r1, r1, #1
	add r1, r8
	lsls r0, r0, #6
	adds r0, r2, r0
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r1]
	adds r4, #1
	ldrh r1, [r6]
	lsrs r0, r1, #3
	adds r0, #0xc
	cmp r4, r0
	blt .L08075F32
.L08075F58:
	ldr r0, .L08075FE0 @ =gBg2Tm
	ldr r1, .L08075FE4 @ =0x0200D53A
	adds r2, r5, r1
	adds r1, r3, #0
	adds r1, #0xa8
	movs r4, #1
	lsls r1, r1, #1
	adds r1, r1, r0
.L08075F68:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #0x40
	adds r1, #0x40
	subs r4, #1
	cmp r4, #0
	bge .L08075F68
	mov r3, sl
	cmp r3, #0x13
	ble .L08075EE0
	movs r0, #5
	bl EnableBgSync
	ldr r2, [sp, #0x10]
	ldrb r2, [r2]
	cmp r2, #0x13
	bls .L08076042
	ldr r1, [sp, #0xc]
	ldrb r0, [r1]
	ldr r2, [sp, #8]
	strb r0, [r2]
	ldr r0, .L08075FE8 @ =gBg2Tm+0x150
	movs r1, #0x16
	movs r2, #1
	movs r3, #0
	bl TmFillRect_thm
	ldr r0, .L08075FEC @ =gBg0Tm+0x10
	movs r1, #0x16
	movs r2, #0x1f
	movs r3, #0
	bl TmFillRect_thm
	adds r4, r7, #0
	adds r4, #0x32
	adds r5, r7, #0
	adds r5, #0x2e
	ldr r1, .L08075FF0 @ =0x0200E6B4
	movs r2, #0xff
	adds r0, r1, #0
	adds r0, #0x4c
.L08075FBA:
	str r2, [r0]
	subs r0, #4
	cmp r0, r1
	bge .L08075FBA
	bl ClearIcons
	ldrb r0, [r4]
	bl func_fe6_080742D0
	ldr r0, [sp, #0x14]
	ldrh r0, [r0]
	lsrs r4, r0, #4
	adds r0, r4, #6
	b .L08076012
	.align 2, 0
.L08075FD8: .4byte gBg0Tm
.L08075FDC: .4byte 0x0200CD3A
.L08075FE0: .4byte gBg2Tm
.L08075FE4: .4byte 0x0200D53A
.L08075FE8: .4byte gBg2Tm+0x150
.L08075FEC: .4byte gBg0Tm+0x10
.L08075FF0: .4byte 0x0200E6B4
.L08075FF4:
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	ldr r2, [sp, #8]
	ldrb r3, [r2]
	movs r0, #0
	str r0, [sp]
	adds r0, r7, #0
	ldr r2, .L08076054 @ =0x0200CD3A
	bl func_fe6_08076448
	adds r4, #1
	ldr r1, [sp, #0x14]
	ldrh r1, [r1]
	lsrs r0, r1, #4
	adds r0, #6
.L08076012:
	cmp r4, r0
	bge .L0807601E
	ldr r0, .L08076058 @ =0x0200CD38
	ldrb r0, [r0]
	cmp r4, r0
	blt .L08075FF4
.L0807601E:
	ldr r0, .L0807605C @ =0x0200D53A
	ldr r2, [sp, #8]
	ldrb r1, [r2]
	bl func_fe6_08076314
	ldrb r0, [r5]
	ldr r2, [sp, #8]
	ldrb r1, [r2]
	movs r2, #0
	bl func_fe6_080763D8
	movs r0, #0
	ldr r1, [sp, #0x10]
	strb r0, [r1]
	strh r0, [r7, #0x3e]
	adds r0, r7, #0
	bl Proc_Break
.L08076042:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08076054: .4byte 0x0200CD3A
.L08076058: .4byte 0x0200CD38
.L0807605C: .4byte 0x0200D53A

	thumb_func_start func_fe6_08076060
func_fe6_08076060: @ 0x08076060
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	str r0, [sp]
	adds r2, r0, #0
	adds r2, #0x38
	ldr r0, .L08076150 @ =gUnk_08678722
	ldr r1, [sp]
	ldrh r1, [r1, #0x3e]
	adds r0, r1, r0
	ldrb r3, [r2]
	ldrb r0, [r0]
	adds r0, r3, r0
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x14
	bls .L0807608E
	movs r0, #0x14
	strb r0, [r2]
.L0807608E:
	ldr r5, [sp]
	ldrh r0, [r5, #0x3e]
	adds r0, #1
	strh r0, [r5, #0x3e]
	adds r0, r5, #0
	adds r0, #0x36
	adds r1, r5, #0
	adds r1, #0x37
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bls .L08076164
	movs r5, #0
	str r2, [sp, #8]
	ldrb r6, [r2]
	cmp r5, r6
	blt .L080760B2
	b .L08076202
.L080760B2:
	ldr r7, [sp]
	adds r7, #0x40
	str r7, [sp, #4]
	str r2, [sp, #0x10]
.L080760BA:
	ldr r0, [sp, #4]
	ldrh r0, [r0]
	lsrs r4, r0, #3
	adds r0, r4, #0
	adds r0, #0xc
	adds r6, r5, #0
	adds r6, #0x1c
	movs r1, #8
	adds r1, r1, r5
	mov ip, r1
	adds r5, #1
	mov sb, r5
	cmp r4, r0
	bge .L08076116
	str r6, [sp, #0xc]
	ldr r2, .L08076154 @ =0x0200CD3A
	mov sl, r2
	lsls r1, r1, #1
	str r1, [sp, #0x14]
	movs r3, #0x1f
	mov r8, r3
.L080760E4:
	adds r3, r4, #0
	mov r5, r8
	ands r3, r5
	lsls r1, r3, #5
	ldr r2, [sp, #0xc]
	ldr r7, [sp, #0x10]
	ldrb r7, [r7]
	subs r0, r2, r7
	adds r1, r1, r0
	lsls r1, r1, #1
	ldr r0, .L08076158 @ =gBg0Tm
	adds r1, r1, r0
	lsls r0, r3, #6
	ldr r2, [sp, #0x14]
	adds r0, r2, r0
	add r0, sl
	ldrh r0, [r0]
	strh r0, [r1]
	adds r4, #1
	ldr r3, [sp, #4]
	ldrh r3, [r3]
	lsrs r0, r3, #3
	adds r0, #0xc
	cmp r4, r0
	blt .L080760E4
.L08076116:
	ldr r5, .L0807615C @ =gBg2Tm
	mov r8, r5
	adds r5, r6, #0
	mov r6, ip
	lsls r0, r6, #1
	ldr r7, .L08076160 @ =0x0200D53A
	adds r2, r0, r7
	movs r3, #0xa0
	movs r4, #1
.L08076128:
	ldr r1, [sp, #0x10]
	ldrb r1, [r1]
	subs r0, r5, r1
	adds r0, r3, r0
	lsls r0, r0, #1
	add r0, r8
	ldrh r1, [r2]
	strh r1, [r0]
	adds r2, #0x40
	adds r3, #0x20
	subs r4, #1
	cmp r4, #0
	bge .L08076128
	mov r5, sb
	ldr r2, [sp, #0x10]
	ldrb r2, [r2]
	cmp r5, r2
	blt .L080760BA
	b .L08076202
	.align 2, 0
.L08076150: .4byte gUnk_08678722
.L08076154: .4byte 0x0200CD3A
.L08076158: .4byte gBg0Tm
.L0807615C: .4byte gBg2Tm
.L08076160: .4byte 0x0200D53A
.L08076164:
	movs r5, #0
	str r2, [sp, #8]
	ldrb r3, [r2]
	cmp r5, r3
	bge .L08076202
	ldr r6, [sp]
	adds r6, #0x40
	mov sl, r6
	str r2, [sp, #0x10]
.L08076176:
	mov r7, sl
	ldrh r7, [r7]
	lsrs r4, r7, #3
	adds r0, r4, #0
	adds r0, #0xc
	adds r6, r5, #0
	adds r6, #0x1c
	adds r1, r5, #1
	mov sb, r1
	cmp r4, r0
	bge .L080761CC
	mov ip, r6
	movs r2, #0x1f
	mov r8, r2
.L08076192:
	adds r3, r4, #0
	mov r7, r8
	ands r3, r7
	lsls r2, r3, #5
	adds r2, #8
	adds r2, r2, r5
	lsls r2, r2, #1
	ldr r0, .L08076228 @ =gBg0Tm
	adds r2, r2, r0
	str r2, [sp, #0x14]
	mov r2, ip
	ldr r1, [sp, #0x10]
	ldrb r1, [r1]
	subs r0, r2, r1
	lsls r0, r0, #1
	lsls r1, r3, #6
	adds r0, r0, r1
	ldr r2, .L0807622C @ =0x0200CD3A
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r3, [sp, #0x14]
	strh r0, [r3]
	adds r4, #1
	mov r7, sl
	ldrh r7, [r7]
	lsrs r0, r7, #3
	adds r0, #0xc
	cmp r4, r0
	blt .L08076192
.L080761CC:
	movs r4, #0
	ldr r0, .L08076230 @ =0x0200D53A
	mov ip, r0
	adds r3, r6, #0
	adds r0, r5, #0
	adds r0, #0xa8
	lsls r0, r0, #1
	ldr r1, .L08076234 @ =gBg2Tm
	adds r2, r0, r1
.L080761DE:
	ldr r5, [sp, #0x10]
	ldrb r5, [r5]
	subs r0, r3, r5
	lsls r0, r0, #1
	lsls r1, r4, #6
	adds r0, r0, r1
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #0x40
	adds r4, #1
	cmp r4, #1
	ble .L080761DE
	mov r5, sb
	ldr r6, [sp, #0x10]
	ldrb r6, [r6]
	cmp r5, r6
	blt .L08076176
.L08076202:
	movs r0, #5
	bl EnableBgSync
	ldr r7, [sp, #8]
	ldrb r7, [r7]
	cmp r7, #0x13
	bls .L08076216
	ldr r0, [sp]
	bl Proc_Break
.L08076216:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08076228: .4byte gBg0Tm
.L0807622C: .4byte 0x0200CD3A
.L08076230: .4byte 0x0200D53A
.L08076234: .4byte gBg2Tm

	thumb_func_start func_fe6_08076238
func_fe6_08076238: @ 0x08076238
	push {lr}
	ldr r0, .L0807624C @ =gUnk_08678484
	movs r1, #3
	bl SpawnProc
	adds r0, #0x39
	movs r1, #0
	strb r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
.L0807624C: .4byte gUnk_08678484

	thumb_func_start func_fe6_08076250
func_fe6_08076250: @ 0x08076250
	push {r4, lr}
	adds r1, r0, #0
	cmp r1, #0
	bne .L08076268
	ldr r0, .L08076264 @ =gUnk_08678594
	movs r1, #3
	bl SpawnProc
	b .L0807626E
	.align 2, 0
.L08076264: .4byte gUnk_08678594
.L08076268:
	ldr r0, .L08076290 @ =gUnk_08678594
	bl SpawnProcLocking
.L0807626E:
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x39
	movs r0, #1
	strb r0, [r1]
	bl func_fe6_08036984
	adds r1, r0, #0
	cmp r1, #1
	bne .L08076294
	adds r0, r4, #0
	adds r0, #0x3c
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x3a
	movs r0, #5
	b .L080762A4
	.align 2, 0
.L08076290: .4byte gUnk_08678594
.L08076294:
	adds r0, r4, #0
	adds r0, #0x3c
	movs r1, #0
	strb r1, [r0]
	bl GetPlayerDeployCount
	adds r1, r4, #0
	adds r1, #0x3a
.L080762A4:
	strb r0, [r1]
	adds r1, r4, #0
	adds r1, #0x3b
	movs r0, #0
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080762B4
func_fe6_080762B4: @ 0x080762B4
	push {lr}
	adds r1, r0, #0
	cmp r1, #0
	bne .L080762CC
	ldr r0, .L080762C8 @ =gUnk_0867865C
	movs r1, #3
	bl SpawnProc
	b .L080762D2
	.align 2, 0
.L080762C8: .4byte gUnk_0867865C
.L080762CC:
	ldr r0, .L080762E0 @ =gUnk_0867865C
	bl SpawnProcLocking
.L080762D2:
	adds r1, r0, #0
	adds r1, #0x39
	movs r0, #3
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
.L080762E0: .4byte gUnk_0867865C

	thumb_func_start func_fe6_080762E4
func_fe6_080762E4: @ 0x080762E4
	push {lr}
	adds r1, r0, #0
	cmp r1, #0
	bne .L080762FC
	ldr r0, .L080762F8 @ =gUnk_08678594
	movs r1, #3
	bl SpawnProc
	b .L08076302
	.align 2, 0
.L080762F8: .4byte gUnk_08678594
.L080762FC:
	ldr r0, .L08076310 @ =gUnk_08678594
	bl SpawnProcLocking
.L08076302:
	adds r1, r0, #0
	adds r1, #0x39
	movs r0, #4
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
.L08076310: .4byte gUnk_08678594

	thumb_func_start func_fe6_08076314
func_fe6_08076314: @ 0x08076314
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	adds r0, #0x12
	movs r1, #0x13
	movs r2, #1
	movs r3, #0
	bl TmFillRect_thm
	ldr r7, .L0807635C @ =0x0200D6A4
	adds r0, r7, #0
	bl ClearText
	cmp r4, #5
	bne .L08076360
	movs r5, #0
.L0807633C:
	lsls r0, r5, #2
	adds r0, #0x12
	adds r0, r6, r0
	adds r1, r5, #0
	adds r1, #0x70
	movs r2, #0xa0
	lsls r2, r2, #7
	bl PutIcon
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #7
	bls .L0807633C
	b .L080763BE
	.align 2, 0
.L0807635C: .4byte 0x0200D6A4
.L08076360:
	movs r5, #1
	ldr r2, .L080763D0 @ =gUnk_08678840
	lsls r0, r4, #3
	adds r0, r0, r4
	lsls r1, r0, #4
	adds r0, r1, r2
	ldrb r0, [r0, #0x18]
	adds r6, #0x10
	mov sb, r6
	cmp r0, #0
	beq .L080763B6
	mov r8, r7
	adds r7, r2, #0
	adds r6, r1, #0
.L0807637C:
	lsls r4, r5, #4
	adds r4, r4, r6
	adds r0, r4, r7
	ldrb r1, [r0, #8]
	subs r1, #0x40
	mov r0, r8
	bl Text_SetCursor
	mov r0, r8
	movs r1, #0
	bl Text_SetColor
	adds r0, r7, #4
	adds r4, r4, r0
	ldr r1, [r4]
	mov r0, r8
	bl Text_DrawString
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #8
	bhi .L080763B6
	lsls r0, r5, #4
	adds r0, r0, r6
	adds r0, r0, r7
	ldrb r0, [r0, #8]
	cmp r0, #0
	bne .L0807637C
.L080763B6:
	ldr r0, .L080763D4 @ =0x0200D6A4
	mov r1, sb
	bl PutText
.L080763BE:
	movs r0, #4
	bl EnableBgSync
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080763D0: .4byte gUnk_08678840
.L080763D4: .4byte 0x0200D6A4

	thumb_func_start func_fe6_080763D8
func_fe6_080763D8: @ 0x080763D8
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r7, r2, #0x18
	cmp r5, #0
	beq .L08076414
	ldr r4, .L08076410 @ =gBg2Tm+0x74
	adds r0, r4, #0
	movs r1, #2
	adds r2, r5, #0
	bl PutNumber
	adds r0, r4, #2
	movs r1, #0
	movs r2, #0x16
	bl PutSpecialChar
	adds r4, #4
	adds r0, r4, #0
	movs r1, #2
	adds r2, r6, #0
	bl PutNumber
	b .L08076426
	.align 2, 0
.L08076410: .4byte gBg2Tm+0x74
.L08076414:
	ldr r0, .L08076440 @ =gBg1Tm+0x32
	movs r1, #6
	movs r2, #3
	movs r3, #0
	bl TmFillRect_thm
	movs r0, #2
	bl EnableBgSync
.L08076426:
	cmp r7, #0
	beq .L08076432
	ldr r0, .L08076444 @ =gBg2Tm+0x140
	adds r1, r5, #0
	bl func_fe6_08076314
.L08076432:
	movs r0, #4
	bl EnableBgSync
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08076440: .4byte gBg1Tm+0x32
.L08076444: .4byte gBg2Tm+0x140

	thumb_func_start func_fe6_08076448
func_fe6_08076448: @ 0x08076448
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x54
	str r0, [sp, #0x24]
	str r2, [sp, #0x28]
	ldr r4, [sp, #0x74]
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r3, [sp, #0x2c]
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r7, #0
	movs r1, #7
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x30]
	lsls r0, r7, #1
	mov sl, r0
	movs r0, #0x1f
	mov r1, sl
	ands r1, r0
	mov sl, r1
	ldr r1, .L080764E8 @ =0x0200CC38
	lsls r0, r7, #2
	adds r0, r0, r1
	mov r8, r0
	ldr r0, [r0]
	ldr r1, [r0]
	movs r0, #8
	ldrh r1, [r1, #0xc]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	rsbs r0, r0, #0
	lsrs r0, r0, #0x1f
	mov sb, r0
	cmp r4, #0
	beq .L08076528
	ldr r2, [sp, #0x30]
	lsls r4, r2, #3
	ldr r0, .L080764EC @ =0x0200D5BC
	adds r5, r4, r0
	adds r0, r5, #0
	bl ClearText
	adds r0, r5, #0
	movs r1, #0
	bl Text_SetCursor
	ldr r0, [sp, #0x24]
	adds r0, #0x3c
	ldrb r0, [r0]
	adds r6, r4, #0
	cmp r0, #0
	bne .L080764F0
	ldr r0, [sp, #0x24]
	adds r0, #0x39
	ldrb r0, [r0]
	cmp r0, #1
	bne .L080764F0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0]
	bl func_fe6_08079404
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080764F0
	adds r0, r5, #0
	movs r1, #4
	bl Text_SetColor
	b .L080764FA
	.align 2, 0
.L080764E8: .4byte 0x0200CC38
.L080764EC: .4byte 0x0200D5BC
.L080764F0:
	ldr r0, .L08076574 @ =0x0200D5BC
	adds r0, r6, r0
	mov r1, sb
	bl Text_SetColor
.L080764FA:
	ldr r4, .L08076574 @ =0x0200D5BC
	adds r4, r6, r4
	ldr r1, .L08076578 @ =0x0200CC38
	lsls r0, r7, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	ldr r0, [r0]
	ldrh r0, [r0]
	bl DecodeMsg
	adds r1, r0, #0
	adds r0, r4, #0
	bl Text_DrawString
	mov r6, sl
	lsls r1, r6, #6
	ldr r0, [sp, #0x28]
	adds r1, r0, r1
	adds r1, #6
	adds r0, r4, #0
	bl PutText
.L08076528:
	ldr r1, [sp, #0x30]
	lsls r5, r1, #1
	adds r0, r5, r1
	lsls r0, r0, #3
	mov r8, r0
	ldr r6, .L0807657C @ =0x0200D5F4
	adds r0, r0, r6
	bl ClearText
	adds r0, r6, #0
	adds r0, #8
	add r0, r8
	bl ClearText
	mov r2, sl
	lsls r4, r2, #6
	ldr r3, [sp, #0x28]
	adds r3, r3, r4
	str r3, [sp, #0x34]
	adds r0, r3, #0
	adds r0, #0x10
	movs r1, #0x18
	movs r2, #1
	movs r3, #0
	bl TmFillRect_thm
	mov sl, r4
	str r5, [sp, #0x50]
	ldr r4, [sp, #0x2c]
	cmp r4, #5
	bls .L08076568
	b .L08076BA8
.L08076568:
	lsls r0, r4, #2
	ldr r1, .L08076580 @ =.L08076584
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08076574: .4byte 0x0200D5BC
.L08076578: .4byte 0x0200CC38
.L0807657C: .4byte 0x0200D5F4
.L08076580: .4byte .L08076584
.L08076584: @ jump table
	.4byte .L0807659C @ case 0
	.4byte .L08076724 @ case 1
	.4byte .L080767E8 @ case 2
	.4byte .L08076906 @ case 3
	.4byte .L08076A14 @ case 4
	.4byte .L08076B48 @ case 5
.L0807659C:
	ldr r0, .L0807660C @ =0x0200CC38
	lsls r6, r7, #2
	adds r0, r0, r6
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrh r0, [r0]
	bl DecodeMsg
	adds r2, r0, #0
	ldr r0, [sp, #0x50]
	ldr r1, [sp, #0x30]
	adds r5, r0, r1
	lsls r5, r5, #3
	ldr r4, .L08076610 @ =0x0200D5F4
	adds r0, r5, r4
	ldr r7, [sp, #0x28]
	add r7, sl
	adds r1, r7, #0
	adds r1, #0x10
	movs r3, #0
	str r3, [sp]
	str r2, [sp, #4]
	movs r2, #0
	bl PutDrawText
	adds r4, #8
	adds r5, r5, r4
	mov r4, sb
	adds r0, r5, #0
	adds r1, r4, #0
	bl Text_SetColor
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0]
	bl GetUnitEquippedWeapon
	lsls r0, r0, #0x10
	str r6, [sp, #0x4c]
	cmp r0, #0
	bne .L08076618
	adds r1, r7, #0
	adds r1, #0x22
	movs r2, #0
	str r2, [sp]
	ldr r0, .L08076614 @ =gUnk_08327154
	str r0, [sp, #4]
	adds r0, r5, #0
	adds r2, r4, #0
	movs r3, #0
	bl PutDrawText
	b .L08076676
	.align 2, 0
.L0807660C: .4byte 0x0200CC38
.L08076610: .4byte 0x0200D5F4
.L08076614: .4byte gUnk_08327154
.L08076618:
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0]
	bl GetUnitEquippedWeapon
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl GetItemName
	adds r1, r7, #0
	adds r1, #0x22
	movs r6, #0
	str r6, [sp]
	str r0, [sp, #4]
	adds r0, r5, #0
	adds r2, r4, #0
	movs r3, #0
	bl PutDrawText
	adds r4, r7, #0
	adds r4, #0x1e
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0]
	bl GetUnitEquippedWeapon
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl GetItemIcon
	adds r1, r0, #0
	movs r2, #0x80
	lsls r2, r2, #7
	adds r0, r4, #0
	bl PutIcon
	mov r2, r8
	ldr r0, [r2]
	ldr r0, [r0]
	bl GetUnitEquippedWeapon
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl GetItemIcon
	bl func_fe6_08074384
.L08076676:
	ldr r3, [sp, #0x50]
	ldr r4, [sp, #0x30]
	adds r0, r3, r4
	lsls r0, r0, #3
	ldr r1, .L080766A8 @ =0x0200D604
	adds r4, r0, r1
	adds r0, r4, #0
	bl ClearText
	ldr r0, .L080766AC @ =0x0200CC38
	ldr r6, [sp, #0x4c]
	adds r0, r6, r0
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r0, [r1]
	ldrb r0, [r0, #4]
	cmp r0, #0x42
	bne .L080766B0
	ldr r1, [sp, #0x28]
	add r1, sl
	adds r1, #0x30
	movs r0, #0
	str r0, [sp]
	b .L08076710
	.align 2, 0
.L080766A8: .4byte 0x0200D604
.L080766AC: .4byte 0x0200CC38
.L080766B0:
	movs r3, #0xc0
	lsls r3, r3, #8
	ldrh r1, [r1, #0xc]
	ands r3, r1
	movs r0, #0x80
	lsls r0, r0, #7
	cmp r3, r0
	beq .L080766D4
	cmp r3, r0
	bgt .L080766CA
	cmp r3, #0
	beq .L08076708
	b .L08076D10
.L080766CA:
	movs r0, #0x80
	lsls r0, r0, #8
	cmp r3, r0
	beq .L080766E8
	b .L08076D10
.L080766D4:
	ldr r1, [sp, #0x28]
	add r1, sl
	adds r1, #0x30
	movs r0, #0
	str r0, [sp]
	ldr r0, .L080766E4 @ =gUnk_08327168
	b .L080766F4
	.align 2, 0
.L080766E4: .4byte gUnk_08327168
.L080766E8:
	ldr r1, [sp, #0x28]
	add r1, sl
	adds r1, #0x30
	movs r0, #0
	str r0, [sp]
	ldr r0, .L08076704 @ =gUnk_0832716C
.L080766F4:
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r2, #4
	movs r3, #8
	bl PutDrawText
	b .L08076D10
	.align 2, 0
.L08076704: .4byte gUnk_0832716C
.L08076708:
	ldr r1, [sp, #0x28]
	add r1, sl
	adds r1, #0x30
	str r3, [sp]
.L08076710:
	ldr r0, .L08076720 @ =gUnk_08327160
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #4
	bl PutDrawText
	b .L08076D10
	.align 2, 0
.L08076720: .4byte gUnk_08327160
.L08076724:
	ldr r1, .L080767E0 @ =0x0200CC38
	lsls r0, r7, #2
	adds r6, r0, r1
	ldr r0, [r6]
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrh r0, [r0]
	bl DecodeMsg
	adds r3, r0, #0
	ldr r1, [sp, #0x50]
	ldr r2, [sp, #0x30]
	adds r0, r1, r2
	lsls r0, r0, #3
	ldr r1, .L080767E4 @ =0x0200D5F4
	adds r0, r0, r1
	ldr r4, [sp, #0x28]
	add r4, sl
	adds r1, r4, #0
	adds r1, #0x10
	mov r8, sb
	movs r2, #0
	str r2, [sp]
	str r3, [sp, #4]
	mov r2, r8
	movs r3, #0
	bl PutDrawText
	adds r3, r4, #0
	adds r3, #0x22
	movs r1, #2
	mov r0, sb
	cmp r0, #0
	beq .L0807676A
	movs r1, #1
.L0807676A:
	ldr r0, [r6]
	ldr r0, [r0]
	movs r2, #8
	ldrsb r2, [r0, r2]
	adds r0, r3, #0
	bl PutNumberOrBlank
	adds r3, r4, #0
	adds r3, #0x28
	movs r1, #2
	mov r2, sb
	cmp r2, #0
	beq .L08076786
	movs r1, #1
.L08076786:
	ldr r0, [r6]
	ldr r0, [r0]
	ldrb r2, [r0, #9]
	adds r0, r3, #0
	bl PutNumberOrBlank
	adds r5, r4, #0
	adds r5, #0x2e
	movs r7, #2
	mov r3, sb
	cmp r3, #0
	beq .L080767A0
	movs r7, #1
.L080767A0:
	ldr r0, [r6]
	ldr r0, [r0]
	bl GetUnitCurrentHp
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r7, #0
	bl PutNumberOrBlank
	adds r0, r4, #0
	adds r0, #0x30
	mov r1, r8
	movs r2, #0x16
	bl PutSpecialChar
	adds r4, #0x34
	movs r5, #2
	mov r0, sb
	cmp r0, #0
	beq .L080767CA
	movs r5, #1
.L080767CA:
	ldr r0, [r6]
	ldr r0, [r0]
	bl GetUnitMaxHp
	adds r2, r0, #0
	adds r0, r4, #0
	adds r1, r5, #0
	bl PutNumberOrBlank
	b .L08076D10
	.align 2, 0
.L080767E0: .4byte 0x0200CC38
.L080767E4: .4byte 0x0200D5F4
.L080767E8:
	ldr r5, [sp, #0x28]
	add r5, sl
	movs r1, #0x12
	adds r1, r1, r5
	mov r8, r1
	ldr r1, .L080768F4 @ =0x0200CC38
	lsls r0, r7, #2
	adds r4, r0, r1
	ldr r0, [r4]
	ldr r1, [r0]
	ldr r0, [r1, #4]
	movs r6, #2
	ldrb r0, [r0, #0x14]
	ldrb r2, [r1, #0x12]
	cmp r0, r2
	bne .L0807680A
	movs r6, #4
.L0807680A:
	adds r0, r1, #0
	bl GetUnitPower
	adds r2, r0, #0
	mov r0, r8
	adds r1, r6, #0
	bl PutNumberOrBlank
	adds r7, r5, #0
	adds r7, #0x18
	ldr r0, [r4]
	ldr r1, [r0]
	ldr r0, [r1, #4]
	movs r6, #2
	ldrb r0, [r0, #0x15]
	ldrb r3, [r1, #0x13]
	cmp r0, r3
	bne .L08076830
	movs r6, #4
.L08076830:
	adds r0, r1, #0
	bl GetUnitSkill
	adds r2, r0, #0
	adds r0, r7, #0
	adds r1, r6, #0
	bl PutNumberOrBlank
	adds r7, r5, #0
	adds r7, #0x1e
	ldr r0, [r4]
	ldr r1, [r0]
	ldr r0, [r1, #4]
	movs r6, #2
	ldrb r0, [r0, #0x16]
	ldrb r2, [r1, #0x14]
	cmp r0, r2
	bne .L08076856
	movs r6, #4
.L08076856:
	adds r0, r1, #0
	bl GetUnitSpeed
	adds r2, r0, #0
	adds r0, r7, #0
	adds r1, r6, #0
	bl PutNumberOrBlank
	adds r7, r5, #0
	adds r7, #0x24
	ldr r0, [r4]
	ldr r0, [r0]
	movs r6, #2
	ldrb r3, [r0, #0x17]
	cmp r3, #0x1e
	bne .L08076878
	movs r6, #4
.L08076878:
	bl GetUnitLuck
	adds r2, r0, #0
	adds r0, r7, #0
	adds r1, r6, #0
	bl PutNumberOrBlank
	adds r7, r5, #0
	adds r7, #0x2a
	ldr r0, [r4]
	ldr r1, [r0]
	ldr r0, [r1, #4]
	movs r6, #2
	ldrb r0, [r0, #0x17]
	ldrb r2, [r1, #0x15]
	cmp r0, r2
	bne .L0807689C
	movs r6, #4
.L0807689C:
	adds r0, r1, #0
	bl GetUnitDefense
	adds r2, r0, #0
	adds r0, r7, #0
	adds r1, r6, #0
	bl PutNumberOrBlank
	adds r7, r5, #0
	adds r7, #0x30
	ldr r0, [r4]
	ldr r1, [r0]
	ldr r0, [r1, #4]
	movs r6, #2
	ldrb r0, [r0, #0x18]
	ldrb r3, [r1, #0x16]
	cmp r0, r3
	bne .L080768C2
	movs r6, #4
.L080768C2:
	adds r0, r1, #0
	bl GetUnitResistance
	adds r2, r0, #0
	adds r0, r7, #0
	adds r1, r6, #0
	bl PutNumberOrBlank
	ldr r0, [r4]
	ldr r0, [r0]
	bl GetUnitAffinityIcon
	adds r1, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L080768F8
	adds r0, r5, #0
	adds r0, #0x34
	movs r1, #2
	movs r2, #0x14
	bl PutSpecialChar
	b .L08076D10
	.align 2, 0
.L080768F4: .4byte 0x0200CC38
.L080768F8:
	adds r0, r5, #0
	adds r0, #0x34
	movs r2, #0xa0
	lsls r2, r2, #7
	bl PutIcon
	b .L08076D10
.L08076906:
	ldr r0, .L08076940 @ =0x0200CC38
	lsls r4, r7, #2
	adds r7, r4, r0
	ldr r0, [r7]
	ldr r0, [r0]
	bl GetUnitEquippedWeapon
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	str r4, [sp, #0x4c]
	cmp r3, #0
	bne .L0807694C
	ldr r4, [sp, #0x50]
	ldr r6, [sp, #0x30]
	adds r0, r4, r6
	lsls r0, r0, #3
	ldr r1, .L08076944 @ =0x0200D5F4
	adds r0, r0, r1
	ldr r1, [sp, #0x28]
	add r1, sl
	adds r1, #0x14
	mov r2, sb
	str r3, [sp]
	ldr r3, .L08076948 @ =gUnk_08327154
	str r3, [sp, #4]
	movs r3, #0
	bl PutDrawText
	b .L080769B0
	.align 2, 0
.L08076940: .4byte 0x0200CC38
.L08076944: .4byte 0x0200D5F4
.L08076948: .4byte gUnk_08327154
.L0807694C:
	ldr r0, [r7]
	ldr r0, [r0]
	bl GetUnitEquippedWeapon
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl GetItemName
	adds r5, r0, #0
	ldr r1, [sp, #0x50]
	ldr r2, [sp, #0x30]
	adds r0, r1, r2
	lsls r0, r0, #3
	ldr r1, .L08076A0C @ =0x0200D5F4
	adds r0, r0, r1
	ldr r4, [sp, #0x28]
	add r4, sl
	adds r1, r4, #0
	adds r1, #0x14
	mov r2, sb
	movs r3, #0
	str r3, [sp]
	str r5, [sp, #4]
	bl PutDrawText
	adds r4, #0x10
	ldr r0, [r7]
	ldr r0, [r0]
	bl GetUnitEquippedWeapon
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl GetItemIcon
	adds r1, r0, #0
	movs r2, #0x80
	lsls r2, r2, #7
	adds r0, r4, #0
	bl PutIcon
	ldr r0, [r7]
	ldr r0, [r0]
	bl GetUnitEquippedWeapon
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl GetItemIcon
	bl func_fe6_08074384
.L080769B0:
	ldr r5, [sp, #0x28]
	add r5, sl
	adds r3, r5, #0
	adds r3, #0x24
	movs r1, #2
	mov r4, sb
	cmp r4, #0
	beq .L080769C2
	movs r1, #1
.L080769C2:
	ldr r0, .L08076A10 @ =0x0200CC38
	ldr r6, [sp, #0x4c]
	adds r4, r6, r0
	ldr r0, [r4]
	movs r6, #4
	ldrsh r2, [r0, r6]
	adds r0, r3, #0
	bl PutNumberOrBlank
	adds r3, r5, #0
	adds r3, #0x2c
	movs r1, #2
	mov r0, sb
	cmp r0, #0
	beq .L080769E2
	movs r1, #1
.L080769E2:
	ldr r0, [r4]
	movs r6, #6
	ldrsh r2, [r0, r6]
	adds r0, r3, #0
	bl PutNumberOrBlank
	adds r1, r5, #0
	adds r1, #0x34
	movs r3, #2
	mov r0, sb
	cmp r0, #0
	beq .L080769FC
	movs r3, #1
.L080769FC:
	ldr r0, [r4]
	movs r4, #8
	ldrsh r2, [r0, r4]
	adds r0, r1, #0
	adds r1, r3, #0
	bl PutNumberOrBlank
	b .L08076D10
	.align 2, 0
.L08076A0C: .4byte 0x0200D5F4
.L08076A10: .4byte 0x0200CC38
.L08076A14:
	ldr r0, .L08076A5C @ =0x0200CC38
	lsls r1, r7, #2
	adds r0, r1, r0
	ldr r0, [r0]
	ldr r2, [r0]
	movs r0, #0x10
	ldrh r6, [r2, #0xc]
	ands r0, r6
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	str r1, [sp, #0x4c]
	cmp r3, #0
	beq .L08076A64
	adds r0, r2, #0
	bl GetUnitRescueName
	adds r5, r0, #0
	ldr r1, [sp, #0x50]
	ldr r2, [sp, #0x30]
	adds r0, r1, r2
	lsls r0, r0, #3
	ldr r1, .L08076A60 @ =0x0200D5FC
	adds r0, r0, r1
	ldr r1, [sp, #0x28]
	add r1, sl
	adds r1, #0x24
	mov r3, sb
	rsbs r4, r3, #0
	mov r2, sb
	movs r3, #0
	str r3, [sp]
	str r5, [sp, #4]
	bl PutDrawText
	b .L08076A86
	.align 2, 0
.L08076A5C: .4byte 0x0200CC38
.L08076A60: .4byte 0x0200D5FC
.L08076A64:
	ldr r4, [sp, #0x50]
	ldr r6, [sp, #0x30]
	adds r0, r4, r6
	lsls r0, r0, #3
	ldr r1, .L08076B38 @ =0x0200D5FC
	adds r0, r0, r1
	ldr r1, [sp, #0x28]
	add r1, sl
	adds r1, #0x24
	mov r2, sb
	rsbs r4, r2, #0
	str r3, [sp]
	ldr r3, .L08076B3C @ =gUnk_08327170
	str r3, [sp, #4]
	movs r3, #0
	bl PutDrawText
.L08076A86:
	mov r8, r4
	ldr r7, [sp, #0x28]
	add r7, sl
	adds r3, r7, #0
	adds r3, #0x14
	movs r1, #2
	mov r4, sb
	cmp r4, #0
	beq .L08076A9A
	movs r1, #1
.L08076A9A:
	ldr r0, .L08076B40 @ =0x0200CC38
	ldr r6, [sp, #0x4c]
	adds r4, r6, r0
	ldr r0, [r4]
	ldr r0, [r0]
	movs r2, #0x1a
	ldrsb r2, [r0, r2]
	ldr r0, [r0, #4]
	ldrb r0, [r0, #0x12]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r2, r2, r0
	adds r0, r3, #0
	bl PutNumberOrBlank
	adds r3, r7, #0
	adds r3, #0x1a
	movs r5, #2
	mov r0, sb
	cmp r0, #0
	beq .L08076AC6
	movs r5, #1
.L08076AC6:
	ldr r0, [r4]
	ldr r1, [r0]
	ldr r0, [r1, #4]
	movs r2, #0x11
	ldrsb r2, [r0, r2]
	ldr r0, [r1]
	ldrb r0, [r0, #0x13]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r2, r2, r0
	movs r0, #0x18
	ldrsb r0, [r1, r0]
	adds r2, r2, r0
	adds r0, r3, #0
	adds r1, r5, #0
	bl PutNumberOrBlank
	adds r5, r7, #0
	adds r5, #0x20
	movs r6, #2
	mov r1, sb
	cmp r1, #0
	beq .L08076AF6
	movs r6, #1
.L08076AF6:
	ldr r0, [r4]
	ldr r0, [r0]
	bl GetUnitAid
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r6, #0
	bl PutNumberOrBlank
	ldr r0, [r4]
	ldr r0, [r0]
	bl GetUnitStatusName
	adds r4, r0, #0
	ldr r2, [sp, #0x50]
	ldr r3, [sp, #0x30]
	adds r0, r2, r3
	lsls r0, r0, #3
	ldr r1, .L08076B44 @ =0x0200D5F4
	adds r0, r0, r1
	adds r1, r7, #0
	adds r1, #0x2e
	mov r6, r8
	mov r2, sb
	orrs r6, r2
	lsrs r2, r6, #0x1f
	movs r3, #0
	str r3, [sp]
	str r4, [sp, #4]
	bl PutDrawText
	b .L08076D10
	.align 2, 0
.L08076B38: .4byte 0x0200D5FC
.L08076B3C: .4byte gUnk_08327170
.L08076B40: .4byte 0x0200CC38
.L08076B44: .4byte 0x0200D5F4
.L08076B48:
	movs r6, #0
	lsls r3, r7, #2
	ldr r0, .L08076BA0 @ =0x0200CC38
	adds r7, r3, r0
	ldr r5, [sp, #0x28]
	add r5, sl
.L08076B54:
	add r1, sp, #8
	ldr r0, .L08076BA4 @ =gUnk_08327178
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, [r7]
	ldr r0, [r0]
	adds r0, #0x26
	adds r0, r0, r6
	ldrb r0, [r0]
	bl GetWeaponLevelFromExp
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r0, r6, #2
	adds r0, #0x14
	adds r3, r5, r0
	movs r1, #2
	cmp r4, #6
	bne .L08076B84
	movs r1, #4
.L08076B84:
	lsls r0, r4, #2
	add r0, sp
	adds r0, #8
	ldr r2, [r0]
	adds r0, r3, #0
	bl PutSpecialChar
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #7
	bls .L08076B54
	b .L08076D10
	.align 2, 0
.L08076BA0: .4byte 0x0200CC38
.L08076BA4: .4byte gUnk_08327178
.L08076BA8:
	ldr r1, [sp, #0x2c]
	subs r1, #6
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x38]
	movs r4, #0
	str r4, [sp, #0x3c]
	ldr r1, .L08076C60 @ =0x0200CC38
	lsls r0, r7, #2
	adds r5, r0, r1
	ldr r0, [r5]
	ldr r0, [r0]
	bl GetUnitSupportCount
	str r0, [sp, #0x40]
	adds r0, r6, #0
	adds r0, #0x10
	add r0, r8
	bl ClearText
	movs r6, #0
	ldr r0, [sp, #0x40]
	cmp r4, r0
	bge .L08076CCE
	adds r7, r5, #0
	mov r1, r8
	str r1, [sp, #0x44]
	ldr r2, [sp, #0x34]
	str r2, [sp, #0x48]
	mov r3, sb
	rsbs r3, r3, #0
	mov r0, sb
	orrs r3, r0
	mov r8, r3
.L08076BF0:
	ldr r0, [r7]
	ldr r0, [r0]
	adds r1, r6, #0
	bl CanUnitSupportNow
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08076CC2
	ldr r1, [sp, #0x3c]
	ldr r2, [sp, #0x38]
	cmp r1, r2
	blo .L08076CB8
	ldr r0, [r7]
	ldr r0, [r0]
	adds r1, r6, #0
	bl GetUnitSupportUnit
	movs r1, #8
	ldrh r0, [r0, #0xc]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	cmp r5, #0
	bne .L08076C68
	ldr r0, [r7]
	ldr r0, [r0]
	adds r1, r6, #0
	bl GetUnitSupportPid
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetPInfo
	ldrh r0, [r0]
	bl DecodeMsg
	adds r2, r0, #0
	lsls r0, r4, #3
	ldr r1, .L08076C64 @ =0x0200D5F4
	adds r0, r0, r1
	ldr r3, [sp, #0x44]
	adds r0, r3, r0
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #2
	adds r1, #0x12
	ldr r3, [sp, #0x48]
	adds r1, r3, r1
	str r5, [sp]
	str r2, [sp, #4]
	mov r3, r8
	lsrs r2, r3, #0x1f
	movs r3, #0
	bl PutDrawText
	b .L08076CA6
	.align 2, 0
.L08076C60: .4byte 0x0200CC38
.L08076C64: .4byte 0x0200D5F4
.L08076C68:
	ldr r0, [r7]
	ldr r0, [r0]
	adds r1, r6, #0
	bl GetUnitSupportPid
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetPInfo
	ldrh r0, [r0]
	bl DecodeMsg
	adds r3, r0, #0
	lsls r0, r4, #3
	ldr r1, .L08076CB4 @ =0x0200D5F4
	adds r0, r0, r1
	ldr r1, [sp, #0x44]
	adds r0, r1, r0
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #2
	adds r1, #0x12
	ldr r2, [sp, #0x48]
	adds r1, r2, r1
	movs r2, #0
	str r2, [sp]
	str r3, [sp, #4]
	movs r2, #1
	movs r3, #0
	bl PutDrawText
.L08076CA6:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	beq .L08076CCE
	b .L08076CC2
	.align 2, 0
.L08076CB4: .4byte 0x0200D5F4
.L08076CB8:
	ldr r0, [sp, #0x3c]
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x3c]
.L08076CC2:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r3, [sp, #0x40]
	cmp r6, r3
	blt .L08076BF0
.L08076CCE:
	cmp r4, #2
	bhi .L08076D10
	ldr r6, [sp, #0x50]
	ldr r1, [sp, #0x30]
	adds r0, r6, r1
	lsls r5, r0, #3
	ldr r7, [sp, #0x28]
	add r7, sl
	mov r2, sb
	rsbs r6, r2, #0
	orrs r6, r2
.L08076CE4:
	lsls r0, r4, #3
	ldr r1, .L08076D28 @ =0x0200D5F4
	adds r0, r0, r1
	adds r0, r5, r0
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #2
	adds r1, #0x12
	adds r1, r7, r1
	movs r2, #0
	str r2, [sp]
	ldr r2, .L08076D2C @ =gUnk_08327170
	str r2, [sp, #4]
	lsrs r2, r6, #0x1f
	movs r3, #0
	bl PutDrawText
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #2
	bls .L08076CE4
.L08076D10:
	movs r0, #1
	bl EnableBgSync
	add sp, #0x54
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08076D28: .4byte 0x0200D5F4
.L08076D2C: .4byte gUnk_08327170

	thumb_func_start func_fe6_08076D30
func_fe6_08076D30: @ 0x08076D30
	adds r1, r0, #0
	movs r0, #0xc0
	lsls r0, r0, #8
	ldrh r1, [r1, #0xc]
	ands r0, r1
	bx lr

	thumb_func_start func_fe6_08076D3C
func_fe6_08076D3C: @ 0x08076D3C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x64
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	movs r1, #1
	ands r2, r1
	subs r0, #1
	cmp r0, #0x1f
	bls .L08076D5E
	bl .L0807918C
.L08076D5E:
	lsls r0, r0, #2
	ldr r1, .L08076D68 @ =.L08076D6C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08076D68: .4byte .L08076D6C
.L08076D6C: @ jump table
	.4byte .L08076DEC @ case 0
	.4byte .L080770EC @ case 1
	.4byte .L08076FD8 @ case 2
	.4byte .L080771F8 @ case 3
	.4byte .L080772FC @ case 4
	.4byte .L08077404 @ case 5
	.4byte .L08077510 @ case 6
	.4byte .L08077618 @ case 7
	.4byte .L08077720 @ case 8
	.4byte .L0807782C @ case 9
	.4byte .L08077934 @ case 10
	.4byte .L08077A3C @ case 11
	.4byte .L08077DA4 @ case 12
	.4byte .L08077EB0 @ case 13
	.4byte .L080780BC @ case 14
	.4byte .L080781B0 @ case 15
	.4byte .L080782A4 @ case 16
	.4byte .L08078398 @ case 17
	.4byte .L08077B48 @ case 18
	.4byte .L08077C9C @ case 19
	.4byte .L080784C0 @ case 20
	.4byte .L080785D4 @ case 21
	.4byte .L08078768 @ case 22
	.4byte .L0807886C @ case 23
	.4byte .L08078970 @ case 24
	.4byte .L08078A74 @ case 25
	.4byte .L08078B78 @ case 26
	.4byte .L08078C7C @ case 27
	.4byte .L08078D80 @ case 28
	.4byte .L08078E84 @ case 29
	.4byte .L08078F8C @ case 30
	.4byte .L08079080 @ case 31
.L08076DEC:
	cmp r2, #0
	bne .L08076EE4
	movs r0, #0
	str r0, [sp, #0x40]
	movs r1, #0
	ldr r3, .L08076EDC @ =0x0200CD38
	mov sl, r3
	ldrb r0, [r3]
	subs r0, #1
	cmp r2, r0
	bge .L08076E62
	adds r4, r3, #0
	mov sb, r4
	ldr r7, .L08076EE0 @ =0x0200CC38
	mov ip, r7
.L08076E0A:
	movs r3, #0
	adds r0, r1, #1
	mov r2, sb
	ldrb r2, [r2]
	subs r1, r2, r0
	mov r8, r0
	cmp r3, r1
	bge .L08076E52
	mov r7, ip
.L08076E1C:
	adds r6, r3, #1
	lsls r0, r6, #2
	adds r5, r0, r7
	ldr r4, [r5]
	ldr r0, [r4]
	ldr r1, [r0]
	lsls r0, r3, #2
	adds r3, r0, r7
	ldr r2, [r3]
	ldr r0, [r2]
	ldr r0, [r0]
	ldrb r1, [r1, #0xa]
	ldrb r0, [r0, #0xa]
	cmp r1, r0
	bhs .L08076E42
	str r4, [r3]
	str r2, [r5]
	movs r3, #1
	str r3, [sp, #0x40]
.L08076E42:
	lsls r0, r6, #0x18
	lsrs r3, r0, #0x18
	mov r4, sb
	ldrb r4, [r4]
	mov r1, r8
	subs r0, r4, r1
	cmp r3, r0
	blt .L08076E1C
.L08076E52:
	mov r2, r8
	lsls r0, r2, #0x18
	lsrs r1, r0, #0x18
	mov r3, sl
	ldrb r0, [r3]
	subs r0, #1
	cmp r1, r0
	blt .L08076E0A
.L08076E62:
	movs r1, #0
	ldr r4, .L08076EDC @ =0x0200CD38
	ldrb r0, [r4]
	subs r0, #1
	cmp r1, r0
	bge .L08076ED6
	mov sl, r4
.L08076E70:
	movs r3, #0
	adds r0, r1, #1
	mov r7, sl
	ldrb r7, [r7]
	subs r1, r7, r0
	mov r8, r0
	cmp r3, r1
	bge .L08076EC6
	ldr r0, .L08076EE0 @ =0x0200CC38
	mov sb, r0
	movs r1, #2
	mov ip, r1
.L08076E88:
	adds r7, r3, #1
	lsls r0, r7, #2
	mov r2, sb
	adds r6, r0, r2
	ldr r5, [r6]
	ldr r0, [r5]
	mov r2, ip
	ldrh r0, [r0, #0xc]
	ands r2, r0
	lsls r0, r3, #2
	mov r3, sb
	adds r4, r0, r3
	ldr r3, [r4]
	ldr r1, [r3]
	mov r0, ip
	ldrh r1, [r1, #0xc]
	ands r0, r1
	cmp r2, r0
	bhs .L08076EB6
	str r5, [r4]
	str r3, [r6]
	movs r4, #1
	str r4, [sp, #0x40]
.L08076EB6:
	lsls r0, r7, #0x18
	lsrs r3, r0, #0x18
	mov r7, sl
	ldrb r7, [r7]
	mov r1, r8
	subs r0, r7, r1
	cmp r3, r0
	blt .L08076E88
.L08076EC6:
	mov r2, r8
	lsls r0, r2, #0x18
	lsrs r1, r0, #0x18
	ldr r3, .L08076EDC @ =0x0200CD38
	ldrb r0, [r3]
	subs r0, #1
	cmp r1, r0
	blt .L08076E70
.L08076ED6:
	ldr r4, [sp, #0x40]
	bl .L080780AA
	.align 2, 0
.L08076EDC: .4byte 0x0200CD38
.L08076EE0: .4byte 0x0200CC38
.L08076EE4:
	movs r7, #0
	str r7, [sp, #0x44]
	movs r1, #0
	ldr r0, .L08076FD0 @ =0x0200CD38
	mov sl, r0
	ldrb r0, [r0]
	subs r0, #1
	cmp r7, r0
	bge .L08076F56
	ldr r2, .L08076FD0 @ =0x0200CD38
	mov sb, r2
	ldr r3, .L08076FD4 @ =0x0200CC38
	mov ip, r3
.L08076EFE:
	movs r3, #0
	adds r0, r1, #1
	mov r4, sb
	ldrb r4, [r4]
	subs r1, r4, r0
	mov r8, r0
	cmp r3, r1
	bge .L08076F46
	mov r7, ip
.L08076F10:
	adds r6, r3, #1
	lsls r0, r6, #2
	adds r5, r0, r7
	ldr r4, [r5]
	ldr r0, [r4]
	ldr r1, [r0]
	lsls r0, r3, #2
	adds r3, r0, r7
	ldr r2, [r3]
	ldr r0, [r2]
	ldr r0, [r0]
	ldrb r1, [r1, #0xa]
	ldrb r0, [r0, #0xa]
	cmp r1, r0
	bls .L08076F36
	str r4, [r3]
	str r2, [r5]
	movs r0, #1
	str r0, [sp, #0x44]
.L08076F36:
	lsls r0, r6, #0x18
	lsrs r3, r0, #0x18
	mov r1, sb
	ldrb r1, [r1]
	mov r2, r8
	subs r0, r1, r2
	cmp r3, r0
	blt .L08076F10
.L08076F46:
	mov r3, r8
	lsls r0, r3, #0x18
	lsrs r1, r0, #0x18
	mov r4, sl
	ldrb r0, [r4]
	subs r0, #1
	cmp r1, r0
	blt .L08076EFE
.L08076F56:
	movs r1, #0
	ldr r7, .L08076FD0 @ =0x0200CD38
	ldrb r0, [r7]
	subs r0, #1
	cmp r1, r0
	bge .L08076FC8
	mov sl, r7
.L08076F64:
	movs r3, #0
	adds r0, r1, #1
	mov r2, sl
	ldrb r2, [r2]
	subs r1, r2, r0
	mov r8, r0
	cmp r3, r1
	bge .L08076FB8
	ldr r4, .L08076FD4 @ =0x0200CC38
	mov sb, r4
	movs r7, #2
	mov ip, r7
.L08076F7C:
	adds r7, r3, #1
	lsls r0, r7, #2
	mov r1, sb
	adds r6, r0, r1
	ldr r5, [r6]
	ldr r0, [r5]
	mov r2, ip
	ldrh r0, [r0, #0xc]
	ands r2, r0
	lsls r0, r3, #2
	adds r4, r0, r1
	ldr r3, [r4]
	ldr r1, [r3]
	mov r0, ip
	ldrh r1, [r1, #0xc]
	ands r0, r1
	cmp r2, r0
	bls .L08076FA8
	str r5, [r4]
	str r3, [r6]
	movs r2, #1
	str r2, [sp, #0x44]
.L08076FA8:
	lsls r0, r7, #0x18
	lsrs r3, r0, #0x18
	mov r4, sl
	ldrb r4, [r4]
	mov r7, r8
	subs r0, r4, r7
	cmp r3, r0
	blt .L08076F7C
.L08076FB8:
	mov r1, r8
	lsls r0, r1, #0x18
	lsrs r1, r0, #0x18
	ldr r2, .L08076FD0 @ =0x0200CD38
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L08076F64
.L08076FC8:
	ldr r3, [sp, #0x44]
	bl .L08078F78
	.align 2, 0
.L08076FD0: .4byte 0x0200CD38
.L08076FD4: .4byte 0x0200CC38
.L08076FD8:
	cmp r2, #0
	bne .L08077064
	movs r4, #0
	mov sl, r4
	movs r1, #0
	ldr r7, .L0807705C @ =0x0200CD38
	mov ip, r7
	mov r3, ip
	ldrb r0, [r3]
	subs r0, #1
	cmp r2, r0
	blt .L08076FF4
	bl .L08078F76
.L08076FF4:
	adds r4, r3, #0
	mov sb, r4
.L08076FF8:
	movs r2, #0
	adds r0, r1, #1
	mov r7, sb
	ldrb r7, [r7]
	subs r1, r7, r0
	adds r7, r0, #0
	cmp r2, r1
	bge .L08077048
	ldr r0, .L08077060 @ =0x0200CC38
	mov r8, r0
.L0807700C:
	adds r6, r2, #1
	lsls r0, r6, #2
	mov r1, r8
	adds r5, r0, r1
	ldr r4, [r5]
	ldr r1, [r4]
	lsls r0, r2, #2
	mov r3, r8
	adds r2, r0, r3
	ldr r3, [r2]
	ldr r0, [r3]
	ldrb r1, [r1, #8]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	ldrb r0, [r0, #8]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	ble .L0807703A
	str r4, [r2]
	str r3, [r5]
	movs r4, #1
	mov sl, r4
.L0807703A:
	lsls r0, r6, #0x18
	lsrs r2, r0, #0x18
	mov r1, sb
	ldrb r1, [r1]
	subs r0, r1, r7
	cmp r2, r0
	blt .L0807700C
.L08077048:
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L08076FF8
	bl .L08078F76
	.align 2, 0
.L0807705C: .4byte 0x0200CD38
.L08077060: .4byte 0x0200CC38
.L08077064:
	movs r4, #0
	mov sl, r4
	movs r1, #0
	ldr r7, .L080770E4 @ =0x0200CD38
	mov ip, r7
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp sl, r0
	blt .L0807707C
	bl .L08078F76
.L0807707C:
	adds r3, r2, #0
	mov sb, r3
.L08077080:
	movs r2, #0
	adds r0, r1, #1
	mov r4, sb
	ldrb r4, [r4]
	subs r1, r4, r0
	adds r7, r0, #0
	cmp r2, r1
	bge .L080770D0
	ldr r0, .L080770E8 @ =0x0200CC38
	mov r8, r0
.L08077094:
	adds r6, r2, #1
	lsls r0, r6, #2
	mov r1, r8
	adds r5, r0, r1
	ldr r4, [r5]
	ldr r1, [r4]
	lsls r0, r2, #2
	mov r3, r8
	adds r2, r0, r3
	ldr r3, [r2]
	ldr r0, [r3]
	ldrb r1, [r1, #8]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	ldrb r0, [r0, #8]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bge .L080770C2
	str r4, [r2]
	str r3, [r5]
	movs r4, #1
	mov sl, r4
.L080770C2:
	lsls r0, r6, #0x18
	lsrs r2, r0, #0x18
	mov r1, sb
	ldrb r1, [r1]
	subs r0, r1, r7
	cmp r2, r0
	blt .L08077094
.L080770D0:
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L08077080
	bl .L08078F76
	.align 2, 0
.L080770E4: .4byte 0x0200CD38
.L080770E8: .4byte 0x0200CC38
.L080770EC:
	cmp r2, #0
	bne .L08077174
	movs r4, #0
	mov sl, r4
	movs r1, #0
	ldr r7, .L0807716C @ =0x0200CD38
	mov ip, r7
	mov r3, ip
	ldrb r0, [r3]
	subs r0, #1
	cmp r2, r0
	blt .L08077108
	bl .L08078F76
.L08077108:
	adds r4, r3, #0
	mov sb, r4
.L0807710C:
	movs r2, #0
	adds r0, r1, #1
	mov r7, sb
	ldrb r7, [r7]
	subs r1, r7, r0
	adds r7, r0, #0
	cmp r2, r1
	bge .L08077158
	ldr r0, .L08077170 @ =0x0200CC38
	mov r8, r0
.L08077120:
	adds r6, r2, #1
	lsls r0, r6, #2
	mov r1, r8
	adds r5, r0, r1
	ldr r4, [r5]
	ldr r0, [r4]
	ldr r1, [r0, #4]
	lsls r0, r2, #2
	mov r3, r8
	adds r2, r0, r3
	ldr r3, [r2]
	ldr r0, [r3]
	ldr r0, [r0, #4]
	ldrb r1, [r1, #0xa]
	ldrb r0, [r0, #0xa]
	cmp r1, r0
	bhs .L0807714A
	str r4, [r2]
	str r3, [r5]
	movs r4, #1
	mov sl, r4
.L0807714A:
	lsls r0, r6, #0x18
	lsrs r2, r0, #0x18
	mov r1, sb
	ldrb r1, [r1]
	subs r0, r1, r7
	cmp r2, r0
	blt .L08077120
.L08077158:
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L0807710C
	bl .L08078F76
	.align 2, 0
.L0807716C: .4byte 0x0200CD38
.L08077170: .4byte 0x0200CC38
.L08077174:
	movs r4, #0
	mov sl, r4
	movs r1, #0
	ldr r7, .L080771F0 @ =0x0200CD38
	mov ip, r7
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp sl, r0
	blt .L0807718C
	bl .L08078F76
.L0807718C:
	adds r3, r2, #0
	mov sb, r3
.L08077190:
	movs r2, #0
	adds r0, r1, #1
	mov r4, sb
	ldrb r4, [r4]
	subs r1, r4, r0
	adds r7, r0, #0
	cmp r2, r1
	bge .L080771DC
	ldr r0, .L080771F4 @ =0x0200CC38
	mov r8, r0
.L080771A4:
	adds r6, r2, #1
	lsls r0, r6, #2
	mov r1, r8
	adds r5, r0, r1
	ldr r4, [r5]
	ldr r0, [r4]
	ldr r1, [r0, #4]
	lsls r0, r2, #2
	mov r3, r8
	adds r2, r0, r3
	ldr r3, [r2]
	ldr r0, [r3]
	ldr r0, [r0, #4]
	ldrb r1, [r1, #0xa]
	ldrb r0, [r0, #0xa]
	cmp r1, r0
	bls .L080771CE
	str r4, [r2]
	str r3, [r5]
	movs r4, #1
	mov sl, r4
.L080771CE:
	lsls r0, r6, #0x18
	lsrs r2, r0, #0x18
	mov r1, sb
	ldrb r1, [r1]
	subs r0, r1, r7
	cmp r2, r0
	blt .L080771A4
.L080771DC:
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L08077190
	bl .L08078F76
	.align 2, 0
.L080771F0: .4byte 0x0200CD38
.L080771F4: .4byte 0x0200CC38
.L080771F8:
	cmp r2, #0
	bne .L0807727C
	movs r4, #0
	mov sl, r4
	movs r1, #0
	ldr r7, .L08077274 @ =0x0200CD38
	mov ip, r7
	mov r3, ip
	ldrb r0, [r3]
	subs r0, #1
	cmp r2, r0
	blt .L08077214
	bl .L08078F76
.L08077214:
	adds r4, r3, #0
	mov sb, r4
.L08077218:
	movs r2, #0
	adds r0, r1, #1
	mov r7, sb
	ldrb r7, [r7]
	subs r1, r7, r0
	adds r7, r0, #0
	cmp r2, r1
	bge .L08077260
	ldr r0, .L08077278 @ =0x0200CC38
	mov r8, r0
.L0807722C:
	adds r6, r2, #1
	lsls r0, r6, #2
	mov r1, r8
	adds r5, r0, r1
	ldr r4, [r5]
	ldr r1, [r4]
	lsls r0, r2, #2
	mov r3, r8
	adds r2, r0, r3
	ldr r3, [r2]
	ldr r0, [r3]
	ldrb r1, [r1, #9]
	ldrb r0, [r0, #9]
	cmp r1, r0
	bls .L08077252
	str r4, [r2]
	str r3, [r5]
	movs r4, #1
	mov sl, r4
.L08077252:
	lsls r0, r6, #0x18
	lsrs r2, r0, #0x18
	mov r1, sb
	ldrb r1, [r1]
	subs r0, r1, r7
	cmp r2, r0
	blt .L0807722C
.L08077260:
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L08077218
	bl .L08078F76
	.align 2, 0
.L08077274: .4byte 0x0200CD38
.L08077278: .4byte 0x0200CC38
.L0807727C:
	movs r4, #0
	mov sl, r4
	movs r1, #0
	ldr r7, .L080772F4 @ =0x0200CD38
	mov ip, r7
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp sl, r0
	blt .L08077294
	bl .L08078F76
.L08077294:
	adds r3, r2, #0
	mov sb, r3
.L08077298:
	movs r2, #0
	adds r0, r1, #1
	mov r4, sb
	ldrb r4, [r4]
	subs r1, r4, r0
	adds r7, r0, #0
	cmp r2, r1
	bge .L080772E0
	ldr r0, .L080772F8 @ =0x0200CC38
	mov r8, r0
.L080772AC:
	adds r6, r2, #1
	lsls r0, r6, #2
	mov r1, r8
	adds r5, r0, r1
	ldr r4, [r5]
	ldr r1, [r4]
	lsls r0, r2, #2
	mov r3, r8
	adds r2, r0, r3
	ldr r3, [r2]
	ldr r0, [r3]
	ldrb r1, [r1, #9]
	ldrb r0, [r0, #9]
	cmp r1, r0
	bhs .L080772D2
	str r4, [r2]
	str r3, [r5]
	movs r4, #1
	mov sl, r4
.L080772D2:
	lsls r0, r6, #0x18
	lsrs r2, r0, #0x18
	mov r1, sb
	ldrb r1, [r1]
	subs r0, r1, r7
	cmp r2, r0
	blt .L080772AC
.L080772E0:
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L08077298
	bl .L08078F76
	.align 2, 0
.L080772F4: .4byte 0x0200CD38
.L080772F8: .4byte 0x0200CC38
.L080772FC:
	cmp r2, #0
	bne .L08077384
	movs r4, #0
	mov sl, r4
	movs r1, #0
	ldr r3, .L0807737C @ =0x0200CD38
	ldrb r0, [r3]
	subs r0, #1
	cmp r2, r0
	blt .L08077314
	bl .L0807917A
.L08077314:
	movs r5, #0
	adds r0, r1, #1
	ldrb r3, [r3]
	subs r1, r3, r0
	mov r8, r0
	cmp r5, r1
	bge .L08077366
	ldr r7, .L08077380 @ =0x0200CC38
	mov sb, r7
.L08077326:
	adds r7, r5, #1
	lsls r0, r7, #2
	mov r1, sb
	adds r6, r0, r1
	ldr r0, [r6]
	ldr r0, [r0]
	bl GetUnitCurrentHp
	adds r4, r0, #0
	lsls r0, r5, #2
	mov r2, sb
	adds r5, r0, r2
	ldr r0, [r5]
	ldr r0, [r0]
	bl GetUnitCurrentHp
	cmp r4, r0
	ble .L08077356
	ldr r1, [r5]
	ldr r0, [r6]
	str r0, [r5]
	str r1, [r6]
	movs r3, #1
	mov sl, r3
.L08077356:
	lsls r0, r7, #0x18
	lsrs r5, r0, #0x18
	ldr r0, .L0807737C @ =0x0200CD38
	ldrb r0, [r0]
	mov r4, r8
	subs r0, r0, r4
	cmp r5, r0
	blt .L08077326
.L08077366:
	mov r7, r8
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	ldr r3, .L0807737C @ =0x0200CD38
	ldrb r0, [r3]
	subs r0, #1
	cmp r1, r0
	blt .L08077314
	bl .L0807917A
	.align 2, 0
.L0807737C: .4byte 0x0200CD38
.L08077380: .4byte 0x0200CC38
.L08077384:
	movs r1, #0
	mov sl, r1
	ldr r2, .L080773FC @ =0x0200CD38
	ldrb r0, [r2]
	subs r0, #1
	cmp sl, r0
	blt .L08077396
	bl .L0807906C
.L08077396:
	movs r5, #0
	adds r0, r1, #1
	ldrb r2, [r2]
	subs r1, r2, r0
	mov r8, r0
	cmp r5, r1
	bge .L080773E8
	ldr r2, .L08077400 @ =0x0200CC38
	mov sb, r2
.L080773A8:
	adds r7, r5, #1
	lsls r0, r7, #2
	mov r3, sb
	adds r6, r0, r3
	ldr r0, [r6]
	ldr r0, [r0]
	bl GetUnitCurrentHp
	adds r4, r0, #0
	lsls r0, r5, #2
	mov r1, sb
	adds r5, r0, r1
	ldr r0, [r5]
	ldr r0, [r0]
	bl GetUnitCurrentHp
	cmp r4, r0
	bge .L080773D8
	ldr r1, [r5]
	ldr r0, [r6]
	str r0, [r5]
	str r1, [r6]
	movs r2, #1
	mov sl, r2
.L080773D8:
	lsls r0, r7, #0x18
	lsrs r5, r0, #0x18
	ldr r0, .L080773FC @ =0x0200CD38
	ldrb r0, [r0]
	mov r3, r8
	subs r0, r0, r3
	cmp r5, r0
	blt .L080773A8
.L080773E8:
	mov r4, r8
	lsls r0, r4, #0x18
	lsrs r1, r0, #0x18
	ldr r2, .L080773FC @ =0x0200CD38
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L08077396
	bl .L0807906C
	.align 2, 0
.L080773FC: .4byte 0x0200CD38
.L08077400: .4byte 0x0200CC38
.L08077404:
	cmp r2, #0
	bne .L0807748C
	movs r0, #0
	mov sl, r0
	movs r1, #0
	ldr r3, .L08077484 @ =0x0200CD38
	ldrb r0, [r3]
	subs r0, #1
	cmp r2, r0
	blt .L0807741C
	bl .L080790F6
.L0807741C:
	movs r5, #0
	adds r0, r1, #1
	ldrb r3, [r3]
	subs r1, r3, r0
	mov r8, r0
	cmp r5, r1
	bge .L0807746E
	ldr r1, .L08077488 @ =0x0200CC38
	mov sb, r1
.L0807742E:
	adds r7, r5, #1
	lsls r0, r7, #2
	mov r2, sb
	adds r6, r0, r2
	ldr r0, [r6]
	ldr r0, [r0]
	bl GetUnitMaxHp
	adds r4, r0, #0
	lsls r0, r5, #2
	mov r3, sb
	adds r5, r0, r3
	ldr r0, [r5]
	ldr r0, [r0]
	bl GetUnitMaxHp
	cmp r4, r0
	ble .L0807745E
	ldr r1, [r5]
	ldr r0, [r6]
	str r0, [r5]
	str r1, [r6]
	movs r4, #1
	mov sl, r4
.L0807745E:
	lsls r0, r7, #0x18
	lsrs r5, r0, #0x18
	ldr r0, .L08077484 @ =0x0200CD38
	ldrb r0, [r0]
	mov r7, r8
	subs r0, r0, r7
	cmp r5, r0
	blt .L0807742E
.L0807746E:
	mov r1, r8
	lsls r0, r1, #0x18
	lsrs r1, r0, #0x18
	ldr r3, .L08077484 @ =0x0200CD38
	ldrb r0, [r3]
	subs r0, #1
	cmp r1, r0
	blt .L0807741C
	bl .L080790F6
	.align 2, 0
.L08077484: .4byte 0x0200CD38
.L08077488: .4byte 0x0200CC38
.L0807748C:
	movs r3, #0
	mov sl, r3
	movs r1, #0
	ldr r2, .L08077508 @ =0x0200CD38
	ldrb r0, [r2]
	subs r0, #1
	cmp sl, r0
	blt .L080774A0
	bl .L0807917A
.L080774A0:
	movs r5, #0
	adds r0, r1, #1
	ldrb r2, [r2]
	subs r1, r2, r0
	mov r8, r0
	cmp r5, r1
	bge .L080774F2
	ldr r4, .L0807750C @ =0x0200CC38
	mov sb, r4
.L080774B2:
	adds r7, r5, #1
	lsls r0, r7, #2
	mov r1, sb
	adds r6, r0, r1
	ldr r0, [r6]
	ldr r0, [r0]
	bl GetUnitMaxHp
	adds r4, r0, #0
	lsls r0, r5, #2
	mov r2, sb
	adds r5, r0, r2
	ldr r0, [r5]
	ldr r0, [r0]
	bl GetUnitMaxHp
	cmp r4, r0
	bge .L080774E2
	ldr r1, [r5]
	ldr r0, [r6]
	str r0, [r5]
	str r1, [r6]
	movs r3, #1
	mov sl, r3
.L080774E2:
	lsls r0, r7, #0x18
	lsrs r5, r0, #0x18
	ldr r0, .L08077508 @ =0x0200CD38
	ldrb r0, [r0]
	mov r4, r8
	subs r0, r0, r4
	cmp r5, r0
	blt .L080774B2
.L080774F2:
	mov r7, r8
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	ldr r2, .L08077508 @ =0x0200CD38
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L080774A0
	bl .L0807917A
	.align 2, 0
.L08077508: .4byte 0x0200CD38
.L0807750C: .4byte 0x0200CC38
.L08077510:
	cmp r2, #0
	bne .L08077594
	movs r1, #0
	mov sl, r1
	ldr r3, .L0807758C @ =0x0200CD38
	ldrb r0, [r3]
	subs r0, #1
	cmp r2, r0
	blt .L08077526
	bl .L0807906C
.L08077526:
	movs r5, #0
	adds r0, r1, #1
	ldrb r3, [r3]
	subs r1, r3, r0
	mov r8, r0
	cmp r5, r1
	bge .L08077578
	ldr r2, .L08077590 @ =0x0200CC38
	mov sb, r2
.L08077538:
	adds r7, r5, #1
	lsls r0, r7, #2
	mov r3, sb
	adds r6, r0, r3
	ldr r0, [r6]
	ldr r0, [r0]
	bl GetUnitPower
	adds r4, r0, #0
	lsls r0, r5, #2
	mov r1, sb
	adds r5, r0, r1
	ldr r0, [r5]
	ldr r0, [r0]
	bl GetUnitPower
	cmp r4, r0
	ble .L08077568
	ldr r1, [r5]
	ldr r0, [r6]
	str r0, [r5]
	str r1, [r6]
	movs r2, #1
	mov sl, r2
.L08077568:
	lsls r0, r7, #0x18
	lsrs r5, r0, #0x18
	ldr r0, .L0807758C @ =0x0200CD38
	ldrb r0, [r0]
	mov r3, r8
	subs r0, r0, r3
	cmp r5, r0
	blt .L08077538
.L08077578:
	mov r4, r8
	lsls r0, r4, #0x18
	lsrs r1, r0, #0x18
	ldr r3, .L0807758C @ =0x0200CD38
	ldrb r0, [r3]
	subs r0, #1
	cmp r1, r0
	blt .L08077526
	bl .L0807906C
	.align 2, 0
.L0807758C: .4byte 0x0200CD38
.L08077590: .4byte 0x0200CC38
.L08077594:
	movs r0, #0
	mov sl, r0
	movs r1, #0
	ldr r2, .L08077610 @ =0x0200CD38
	ldrb r0, [r2]
	subs r0, #1
	cmp sl, r0
	blt .L080775A8
	bl .L080790F6
.L080775A8:
	movs r5, #0
	adds r0, r1, #1
	ldrb r2, [r2]
	subs r1, r2, r0
	mov r8, r0
	cmp r5, r1
	bge .L080775FA
	ldr r1, .L08077614 @ =0x0200CC38
	mov sb, r1
.L080775BA:
	adds r7, r5, #1
	lsls r0, r7, #2
	mov r2, sb
	adds r6, r0, r2
	ldr r0, [r6]
	ldr r0, [r0]
	bl GetUnitPower
	adds r4, r0, #0
	lsls r0, r5, #2
	mov r3, sb
	adds r5, r0, r3
	ldr r0, [r5]
	ldr r0, [r0]
	bl GetUnitPower
	cmp r4, r0
	bge .L080775EA
	ldr r1, [r5]
	ldr r0, [r6]
	str r0, [r5]
	str r1, [r6]
	movs r4, #1
	mov sl, r4
.L080775EA:
	lsls r0, r7, #0x18
	lsrs r5, r0, #0x18
	ldr r0, .L08077610 @ =0x0200CD38
	ldrb r0, [r0]
	mov r7, r8
	subs r0, r0, r7
	cmp r5, r0
	blt .L080775BA
.L080775FA:
	mov r1, r8
	lsls r0, r1, #0x18
	lsrs r1, r0, #0x18
	ldr r2, .L08077610 @ =0x0200CD38
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L080775A8
	bl .L080790F6
	.align 2, 0
.L08077610: .4byte 0x0200CD38
.L08077614: .4byte 0x0200CC38
.L08077618:
	cmp r2, #0
	bne .L080776A0
	movs r3, #0
	mov sl, r3
	movs r1, #0
	ldr r3, .L08077698 @ =0x0200CD38
	ldrb r0, [r3]
	subs r0, #1
	cmp r2, r0
	blt .L08077630
	bl .L0807917A
.L08077630:
	movs r5, #0
	adds r0, r1, #1
	ldrb r3, [r3]
	subs r1, r3, r0
	mov r8, r0
	cmp r5, r1
	bge .L08077682
	ldr r4, .L0807769C @ =0x0200CC38
	mov sb, r4
.L08077642:
	adds r7, r5, #1
	lsls r0, r7, #2
	mov r1, sb
	adds r6, r0, r1
	ldr r0, [r6]
	ldr r0, [r0]
	bl GetUnitSkill
	adds r4, r0, #0
	lsls r0, r5, #2
	mov r2, sb
	adds r5, r0, r2
	ldr r0, [r5]
	ldr r0, [r0]
	bl GetUnitSkill
	cmp r4, r0
	ble .L08077672
	ldr r1, [r5]
	ldr r0, [r6]
	str r0, [r5]
	str r1, [r6]
	movs r3, #1
	mov sl, r3
.L08077672:
	lsls r0, r7, #0x18
	lsrs r5, r0, #0x18
	ldr r0, .L08077698 @ =0x0200CD38
	ldrb r0, [r0]
	mov r4, r8
	subs r0, r0, r4
	cmp r5, r0
	blt .L08077642
.L08077682:
	mov r7, r8
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	ldr r3, .L08077698 @ =0x0200CD38
	ldrb r0, [r3]
	subs r0, #1
	cmp r1, r0
	blt .L08077630
	bl .L0807917A
	.align 2, 0
.L08077698: .4byte 0x0200CD38
.L0807769C: .4byte 0x0200CC38
.L080776A0:
	movs r1, #0
	mov sl, r1
	ldr r2, .L08077718 @ =0x0200CD38
	ldrb r0, [r2]
	subs r0, #1
	cmp sl, r0
	blt .L080776B2
	bl .L0807906C
.L080776B2:
	movs r5, #0
	adds r0, r1, #1
	ldrb r2, [r2]
	subs r1, r2, r0
	mov r8, r0
	cmp r5, r1
	bge .L08077704
	ldr r2, .L0807771C @ =0x0200CC38
	mov sb, r2
.L080776C4:
	adds r7, r5, #1
	lsls r0, r7, #2
	mov r3, sb
	adds r6, r0, r3
	ldr r0, [r6]
	ldr r0, [r0]
	bl GetUnitSkill
	adds r4, r0, #0
	lsls r0, r5, #2
	mov r1, sb
	adds r5, r0, r1
	ldr r0, [r5]
	ldr r0, [r0]
	bl GetUnitSkill
	cmp r4, r0
	bge .L080776F4
	ldr r1, [r5]
	ldr r0, [r6]
	str r0, [r5]
	str r1, [r6]
	movs r2, #1
	mov sl, r2
.L080776F4:
	lsls r0, r7, #0x18
	lsrs r5, r0, #0x18
	ldr r0, .L08077718 @ =0x0200CD38
	ldrb r0, [r0]
	mov r3, r8
	subs r0, r0, r3
	cmp r5, r0
	blt .L080776C4
.L08077704:
	mov r4, r8
	lsls r0, r4, #0x18
	lsrs r1, r0, #0x18
	ldr r2, .L08077718 @ =0x0200CD38
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L080776B2
	bl .L0807906C
	.align 2, 0
.L08077718: .4byte 0x0200CD38
.L0807771C: .4byte 0x0200CC38
.L08077720:
	cmp r2, #0
	bne .L080777A8
	movs r0, #0
	mov sl, r0
	movs r1, #0
	ldr r3, .L080777A0 @ =0x0200CD38
	ldrb r0, [r3]
	subs r0, #1
	cmp r2, r0
	blt .L08077738
	bl .L080790F6
.L08077738:
	movs r5, #0
	adds r0, r1, #1
	ldrb r3, [r3]
	subs r1, r3, r0
	mov r8, r0
	cmp r5, r1
	bge .L0807778A
	ldr r1, .L080777A4 @ =0x0200CC38
	mov sb, r1
.L0807774A:
	adds r7, r5, #1
	lsls r0, r7, #2
	mov r2, sb
	adds r6, r0, r2
	ldr r0, [r6]
	ldr r0, [r0]
	bl GetUnitSpeed
	adds r4, r0, #0
	lsls r0, r5, #2
	mov r3, sb
	adds r5, r0, r3
	ldr r0, [r5]
	ldr r0, [r0]
	bl GetUnitSpeed
	cmp r4, r0
	ble .L0807777A
	ldr r1, [r5]
	ldr r0, [r6]
	str r0, [r5]
	str r1, [r6]
	movs r4, #1
	mov sl, r4
.L0807777A:
	lsls r0, r7, #0x18
	lsrs r5, r0, #0x18
	ldr r0, .L080777A0 @ =0x0200CD38
	ldrb r0, [r0]
	mov r7, r8
	subs r0, r0, r7
	cmp r5, r0
	blt .L0807774A
.L0807778A:
	mov r1, r8
	lsls r0, r1, #0x18
	lsrs r1, r0, #0x18
	ldr r3, .L080777A0 @ =0x0200CD38
	ldrb r0, [r3]
	subs r0, #1
	cmp r1, r0
	blt .L08077738
	bl .L080790F6
	.align 2, 0
.L080777A0: .4byte 0x0200CD38
.L080777A4: .4byte 0x0200CC38
.L080777A8:
	movs r3, #0
	mov sl, r3
	movs r1, #0
	ldr r2, .L08077824 @ =0x0200CD38
	ldrb r0, [r2]
	subs r0, #1
	cmp sl, r0
	blt .L080777BC
	bl .L0807917A
.L080777BC:
	movs r5, #0
	adds r0, r1, #1
	ldrb r2, [r2]
	subs r1, r2, r0
	mov r8, r0
	cmp r5, r1
	bge .L0807780E
	ldr r4, .L08077828 @ =0x0200CC38
	mov sb, r4
.L080777CE:
	adds r7, r5, #1
	lsls r0, r7, #2
	mov r1, sb
	adds r6, r0, r1
	ldr r0, [r6]
	ldr r0, [r0]
	bl GetUnitSpeed
	adds r4, r0, #0
	lsls r0, r5, #2
	mov r2, sb
	adds r5, r0, r2
	ldr r0, [r5]
	ldr r0, [r0]
	bl GetUnitSpeed
	cmp r4, r0
	bge .L080777FE
	ldr r1, [r5]
	ldr r0, [r6]
	str r0, [r5]
	str r1, [r6]
	movs r3, #1
	mov sl, r3
.L080777FE:
	lsls r0, r7, #0x18
	lsrs r5, r0, #0x18
	ldr r0, .L08077824 @ =0x0200CD38
	ldrb r0, [r0]
	mov r4, r8
	subs r0, r0, r4
	cmp r5, r0
	blt .L080777CE
.L0807780E:
	mov r7, r8
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	ldr r2, .L08077824 @ =0x0200CD38
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L080777BC
	bl .L0807917A
	.align 2, 0
.L08077824: .4byte 0x0200CD38
.L08077828: .4byte 0x0200CC38
.L0807782C:
	cmp r2, #0
	bne .L080778B0
	movs r1, #0
	mov sl, r1
	ldr r3, .L080778A8 @ =0x0200CD38
	ldrb r0, [r3]
	subs r0, #1
	cmp r2, r0
	blt .L08077842
	bl .L0807906C
.L08077842:
	movs r5, #0
	adds r0, r1, #1
	ldrb r3, [r3]
	subs r1, r3, r0
	mov r8, r0
	cmp r5, r1
	bge .L08077894
	ldr r2, .L080778AC @ =0x0200CC38
	mov sb, r2
.L08077854:
	adds r7, r5, #1
	lsls r0, r7, #2
	mov r3, sb
	adds r6, r0, r3
	ldr r0, [r6]
	ldr r0, [r0]
	bl GetUnitLuck
	adds r4, r0, #0
	lsls r0, r5, #2
	mov r1, sb
	adds r5, r0, r1
	ldr r0, [r5]
	ldr r0, [r0]
	bl GetUnitLuck
	cmp r4, r0
	ble .L08077884
	ldr r1, [r5]
	ldr r0, [r6]
	str r0, [r5]
	str r1, [r6]
	movs r2, #1
	mov sl, r2
.L08077884:
	lsls r0, r7, #0x18
	lsrs r5, r0, #0x18
	ldr r0, .L080778A8 @ =0x0200CD38
	ldrb r0, [r0]
	mov r3, r8
	subs r0, r0, r3
	cmp r5, r0
	blt .L08077854
.L08077894:
	mov r4, r8
	lsls r0, r4, #0x18
	lsrs r1, r0, #0x18
	ldr r3, .L080778A8 @ =0x0200CD38
	ldrb r0, [r3]
	subs r0, #1
	cmp r1, r0
	blt .L08077842
	bl .L0807906C
	.align 2, 0
.L080778A8: .4byte 0x0200CD38
.L080778AC: .4byte 0x0200CC38
.L080778B0:
	movs r0, #0
	mov sl, r0
	movs r1, #0
	ldr r2, .L0807792C @ =0x0200CD38
	ldrb r0, [r2]
	subs r0, #1
	cmp sl, r0
	blt .L080778C4
	bl .L080790F6
.L080778C4:
	movs r5, #0
	adds r0, r1, #1
	ldrb r2, [r2]
	subs r1, r2, r0
	mov r8, r0
	cmp r5, r1
	bge .L08077916
	ldr r1, .L08077930 @ =0x0200CC38
	mov sb, r1
.L080778D6:
	adds r7, r5, #1
	lsls r0, r7, #2
	mov r2, sb
	adds r6, r0, r2
	ldr r0, [r6]
	ldr r0, [r0]
	bl GetUnitLuck
	adds r4, r0, #0
	lsls r0, r5, #2
	mov r3, sb
	adds r5, r0, r3
	ldr r0, [r5]
	ldr r0, [r0]
	bl GetUnitLuck
	cmp r4, r0
	bge .L08077906
	ldr r1, [r5]
	ldr r0, [r6]
	str r0, [r5]
	str r1, [r6]
	movs r4, #1
	mov sl, r4
.L08077906:
	lsls r0, r7, #0x18
	lsrs r5, r0, #0x18
	ldr r0, .L0807792C @ =0x0200CD38
	ldrb r0, [r0]
	mov r7, r8
	subs r0, r0, r7
	cmp r5, r0
	blt .L080778D6
.L08077916:
	mov r1, r8
	lsls r0, r1, #0x18
	lsrs r1, r0, #0x18
	ldr r2, .L0807792C @ =0x0200CD38
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L080778C4
	bl .L080790F6
	.align 2, 0
.L0807792C: .4byte 0x0200CD38
.L08077930: .4byte 0x0200CC38
.L08077934:
	cmp r2, #0
	bne .L080779BC
	movs r3, #0
	mov sl, r3
	movs r1, #0
	ldr r3, .L080779B4 @ =0x0200CD38
	ldrb r0, [r3]
	subs r0, #1
	cmp r2, r0
	blt .L0807794C
	bl .L0807917A
.L0807794C:
	movs r5, #0
	adds r0, r1, #1
	ldrb r3, [r3]
	subs r1, r3, r0
	mov r8, r0
	cmp r5, r1
	bge .L0807799E
	ldr r4, .L080779B8 @ =0x0200CC38
	mov sb, r4
.L0807795E:
	adds r7, r5, #1
	lsls r0, r7, #2
	mov r1, sb
	adds r6, r0, r1
	ldr r0, [r6]
	ldr r0, [r0]
	bl GetUnitDefense
	adds r4, r0, #0
	lsls r0, r5, #2
	mov r2, sb
	adds r5, r0, r2
	ldr r0, [r5]
	ldr r0, [r0]
	bl GetUnitDefense
	cmp r4, r0
	ble .L0807798E
	ldr r1, [r5]
	ldr r0, [r6]
	str r0, [r5]
	str r1, [r6]
	movs r3, #1
	mov sl, r3
.L0807798E:
	lsls r0, r7, #0x18
	lsrs r5, r0, #0x18
	ldr r0, .L080779B4 @ =0x0200CD38
	ldrb r0, [r0]
	mov r4, r8
	subs r0, r0, r4
	cmp r5, r0
	blt .L0807795E
.L0807799E:
	mov r7, r8
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	ldr r3, .L080779B4 @ =0x0200CD38
	ldrb r0, [r3]
	subs r0, #1
	cmp r1, r0
	blt .L0807794C
	bl .L0807917A
	.align 2, 0
.L080779B4: .4byte 0x0200CD38
.L080779B8: .4byte 0x0200CC38
.L080779BC:
	movs r1, #0
	mov sl, r1
	ldr r2, .L08077A34 @ =0x0200CD38
	ldrb r0, [r2]
	subs r0, #1
	cmp sl, r0
	blt .L080779CE
	bl .L0807906C
.L080779CE:
	movs r5, #0
	adds r0, r1, #1
	ldrb r2, [r2]
	subs r1, r2, r0
	mov r8, r0
	cmp r5, r1
	bge .L08077A20
	ldr r2, .L08077A38 @ =0x0200CC38
	mov sb, r2
.L080779E0:
	adds r7, r5, #1
	lsls r0, r7, #2
	mov r3, sb
	adds r6, r0, r3
	ldr r0, [r6]
	ldr r0, [r0]
	bl GetUnitDefense
	adds r4, r0, #0
	lsls r0, r5, #2
	mov r1, sb
	adds r5, r0, r1
	ldr r0, [r5]
	ldr r0, [r0]
	bl GetUnitDefense
	cmp r4, r0
	bge .L08077A10
	ldr r1, [r5]
	ldr r0, [r6]
	str r0, [r5]
	str r1, [r6]
	movs r2, #1
	mov sl, r2
.L08077A10:
	lsls r0, r7, #0x18
	lsrs r5, r0, #0x18
	ldr r0, .L08077A34 @ =0x0200CD38
	ldrb r0, [r0]
	mov r3, r8
	subs r0, r0, r3
	cmp r5, r0
	blt .L080779E0
.L08077A20:
	mov r4, r8
	lsls r0, r4, #0x18
	lsrs r1, r0, #0x18
	ldr r2, .L08077A34 @ =0x0200CD38
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L080779CE
	bl .L0807906C
	.align 2, 0
.L08077A34: .4byte 0x0200CD38
.L08077A38: .4byte 0x0200CC38
.L08077A3C:
	cmp r2, #0
	bne .L08077AC4
	movs r0, #0
	mov sl, r0
	movs r1, #0
	ldr r3, .L08077ABC @ =0x0200CD38
	ldrb r0, [r3]
	subs r0, #1
	cmp r2, r0
	blt .L08077A54
	bl .L080790F6
.L08077A54:
	movs r5, #0
	adds r0, r1, #1
	ldrb r3, [r3]
	subs r1, r3, r0
	mov r8, r0
	cmp r5, r1
	bge .L08077AA6
	ldr r1, .L08077AC0 @ =0x0200CC38
	mov sb, r1
.L08077A66:
	adds r7, r5, #1
	lsls r0, r7, #2
	mov r2, sb
	adds r6, r0, r2
	ldr r0, [r6]
	ldr r0, [r0]
	bl GetUnitResistance
	adds r4, r0, #0
	lsls r0, r5, #2
	mov r3, sb
	adds r5, r0, r3
	ldr r0, [r5]
	ldr r0, [r0]
	bl GetUnitResistance
	cmp r4, r0
	ble .L08077A96
	ldr r1, [r5]
	ldr r0, [r6]
	str r0, [r5]
	str r1, [r6]
	movs r4, #1
	mov sl, r4
.L08077A96:
	lsls r0, r7, #0x18
	lsrs r5, r0, #0x18
	ldr r0, .L08077ABC @ =0x0200CD38
	ldrb r0, [r0]
	mov r7, r8
	subs r0, r0, r7
	cmp r5, r0
	blt .L08077A66
.L08077AA6:
	mov r1, r8
	lsls r0, r1, #0x18
	lsrs r1, r0, #0x18
	ldr r3, .L08077ABC @ =0x0200CD38
	ldrb r0, [r3]
	subs r0, #1
	cmp r1, r0
	blt .L08077A54
	bl .L080790F6
	.align 2, 0
.L08077ABC: .4byte 0x0200CD38
.L08077AC0: .4byte 0x0200CC38
.L08077AC4:
	movs r3, #0
	mov sl, r3
	movs r1, #0
	ldr r2, .L08077B40 @ =0x0200CD38
	ldrb r0, [r2]
	subs r0, #1
	cmp sl, r0
	blt .L08077AD8
	bl .L0807917A
.L08077AD8:
	movs r5, #0
	adds r0, r1, #1
	ldrb r2, [r2]
	subs r1, r2, r0
	mov r8, r0
	cmp r5, r1
	bge .L08077B2A
	ldr r4, .L08077B44 @ =0x0200CC38
	mov sb, r4
.L08077AEA:
	adds r7, r5, #1
	lsls r0, r7, #2
	mov r1, sb
	adds r6, r0, r1
	ldr r0, [r6]
	ldr r0, [r0]
	bl GetUnitResistance
	adds r4, r0, #0
	lsls r0, r5, #2
	mov r2, sb
	adds r5, r0, r2
	ldr r0, [r5]
	ldr r0, [r0]
	bl GetUnitResistance
	cmp r4, r0
	bge .L08077B1A
	ldr r1, [r5]
	ldr r0, [r6]
	str r0, [r5]
	str r1, [r6]
	movs r3, #1
	mov sl, r3
.L08077B1A:
	lsls r0, r7, #0x18
	lsrs r5, r0, #0x18
	ldr r0, .L08077B40 @ =0x0200CD38
	ldrb r0, [r0]
	mov r4, r8
	subs r0, r0, r4
	cmp r5, r0
	blt .L08077AEA
.L08077B2A:
	mov r7, r8
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	ldr r2, .L08077B40 @ =0x0200CD38
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L08077AD8
	bl .L0807917A
	.align 2, 0
.L08077B40: .4byte 0x0200CD38
.L08077B44: .4byte 0x0200CC38
.L08077B48:
	cmp r2, #0
	bne .L08077BF4
	movs r1, #0
	str r1, [sp, #0x48]
	ldr r3, .L08077BEC @ =0x0200CD38
	ldrb r0, [r3]
	subs r0, #1
	cmp r2, r0
	bge .L08077BE6
	adds r4, r3, #0
	mov sl, r4
.L08077B5E:
	movs r2, #0
	adds r0, r1, #1
	mov r7, sl
	ldrb r7, [r7]
	subs r1, r7, r0
	mov sb, r0
	cmp r2, r1
	bge .L08077BD6
	ldr r0, .L08077BF0 @ =0x0200CC38
	mov ip, r0
.L08077B72:
	adds r1, r2, #1
	mov r8, r1
	lsls r0, r1, #2
	mov r3, ip
	adds r7, r0, r3
	ldr r6, [r7]
	ldr r1, [r6]
	ldr r0, [r1, #4]
	movs r3, #0x11
	ldrsb r3, [r0, r3]
	ldr r0, [r1]
	ldrb r0, [r0, #0x13]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r3, r3, r0
	movs r0, #0x18
	ldrsb r0, [r1, r0]
	adds r3, r3, r0
	lsls r0, r2, #2
	mov r1, ip
	adds r4, r0, r1
	ldr r5, [r4]
	ldr r2, [r5]
	ldr r0, [r2, #4]
	ldrb r0, [r0, #0x11]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r1, [r2]
	ldrb r1, [r1, #0x13]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r0, r0, r1
	movs r1, #0x18
	ldrsb r1, [r2, r1]
	adds r0, r0, r1
	cmp r3, r0
	ble .L08077BC4
	str r6, [r4]
	str r5, [r7]
	movs r2, #1
	str r2, [sp, #0x48]
.L08077BC4:
	mov r3, r8
	lsls r0, r3, #0x18
	lsrs r2, r0, #0x18
	mov r4, sl
	ldrb r4, [r4]
	mov r7, sb
	subs r0, r4, r7
	cmp r2, r0
	blt .L08077B72
.L08077BD6:
	mov r1, sb
	lsls r0, r1, #0x18
	lsrs r1, r0, #0x18
	ldr r2, .L08077BEC @ =0x0200CD38
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L08077B5E
.L08077BE6:
	ldr r3, [sp, #0x48]
	bl .L08078F78
	.align 2, 0
.L08077BEC: .4byte 0x0200CD38
.L08077BF0: .4byte 0x0200CC38
.L08077BF4:
	movs r4, #0
	str r4, [sp, #0x4c]
	movs r1, #0
	ldr r7, .L08077C94 @ =0x0200CD38
	ldrb r0, [r7]
	subs r0, #1
	cmp r4, r0
	bge .L08077C90
	adds r0, r7, #0
	mov sl, r0
.L08077C08:
	movs r2, #0
	adds r0, r1, #1
	mov r3, sl
	ldrb r3, [r3]
	subs r1, r3, r0
	mov sb, r0
	cmp r2, r1
	bge .L08077C80
	ldr r4, .L08077C98 @ =0x0200CC38
	mov ip, r4
.L08077C1C:
	adds r7, r2, #1
	mov r8, r7
	lsls r0, r7, #2
	mov r1, ip
	adds r7, r0, r1
	ldr r6, [r7]
	ldr r1, [r6]
	ldr r0, [r1, #4]
	movs r3, #0x11
	ldrsb r3, [r0, r3]
	ldr r0, [r1]
	ldrb r0, [r0, #0x13]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r3, r3, r0
	movs r0, #0x18
	ldrsb r0, [r1, r0]
	adds r3, r3, r0
	lsls r0, r2, #2
	mov r2, ip
	adds r4, r0, r2
	ldr r5, [r4]
	ldr r2, [r5]
	ldr r0, [r2, #4]
	ldrb r0, [r0, #0x11]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r1, [r2]
	ldrb r1, [r1, #0x13]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r0, r0, r1
	movs r1, #0x18
	ldrsb r1, [r2, r1]
	adds r0, r0, r1
	cmp r3, r0
	bge .L08077C6E
	str r6, [r4]
	str r5, [r7]
	movs r3, #1
	str r3, [sp, #0x4c]
.L08077C6E:
	mov r4, r8
	lsls r0, r4, #0x18
	lsrs r2, r0, #0x18
	mov r7, sl
	ldrb r7, [r7]
	mov r1, sb
	subs r0, r7, r1
	cmp r2, r0
	blt .L08077C1C
.L08077C80:
	mov r2, sb
	lsls r0, r2, #0x18
	lsrs r1, r0, #0x18
	ldr r3, .L08077C94 @ =0x0200CD38
	ldrb r0, [r3]
	subs r0, #1
	cmp r1, r0
	blt .L08077C08
.L08077C90:
	ldr r4, [sp, #0x4c]
	b .L080780AA
	.align 2, 0
.L08077C94: .4byte 0x0200CD38
.L08077C98: .4byte 0x0200CC38
.L08077C9C:
	cmp r2, #0
	bne .L08077D24
	movs r7, #0
	mov sl, r7
	movs r1, #0
	ldr r3, .L08077D1C @ =0x0200CD38
	ldrb r0, [r3]
	subs r0, #1
	cmp r2, r0
	blt .L08077CB4
	bl .L0807917A
.L08077CB4:
	movs r5, #0
	adds r0, r1, #1
	ldrb r3, [r3]
	subs r1, r3, r0
	mov r8, r0
	cmp r5, r1
	bge .L08077D06
	ldr r0, .L08077D20 @ =0x0200CC38
	mov sb, r0
.L08077CC6:
	adds r7, r5, #1
	lsls r0, r7, #2
	mov r1, sb
	adds r6, r0, r1
	ldr r0, [r6]
	ldr r0, [r0]
	bl GetUnitAid
	adds r4, r0, #0
	lsls r0, r5, #2
	mov r2, sb
	adds r5, r0, r2
	ldr r0, [r5]
	ldr r0, [r0]
	bl GetUnitAid
	cmp r4, r0
	ble .L08077CF6
	ldr r1, [r5]
	ldr r0, [r6]
	str r0, [r5]
	str r1, [r6]
	movs r3, #1
	mov sl, r3
.L08077CF6:
	lsls r0, r7, #0x18
	lsrs r5, r0, #0x18
	ldr r0, .L08077D1C @ =0x0200CD38
	ldrb r0, [r0]
	mov r4, r8
	subs r0, r0, r4
	cmp r5, r0
	blt .L08077CC6
.L08077D06:
	mov r7, r8
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	ldr r3, .L08077D1C @ =0x0200CD38
	ldrb r0, [r3]
	subs r0, #1
	cmp r1, r0
	blt .L08077CB4
	bl .L0807917A
	.align 2, 0
.L08077D1C: .4byte 0x0200CD38
.L08077D20: .4byte 0x0200CC38
.L08077D24:
	movs r1, #0
	mov sl, r1
	ldr r2, .L08077D9C @ =0x0200CD38
	ldrb r0, [r2]
	subs r0, #1
	cmp sl, r0
	blt .L08077D36
	bl .L0807906C
.L08077D36:
	movs r5, #0
	adds r0, r1, #1
	ldrb r2, [r2]
	subs r1, r2, r0
	mov r8, r0
	cmp r5, r1
	bge .L08077D88
	ldr r2, .L08077DA0 @ =0x0200CC38
	mov sb, r2
.L08077D48:
	adds r7, r5, #1
	lsls r0, r7, #2
	mov r3, sb
	adds r6, r0, r3
	ldr r0, [r6]
	ldr r0, [r0]
	bl GetUnitAid
	adds r4, r0, #0
	lsls r0, r5, #2
	mov r1, sb
	adds r5, r0, r1
	ldr r0, [r5]
	ldr r0, [r0]
	bl GetUnitAid
	cmp r4, r0
	bge .L08077D78
	ldr r1, [r5]
	ldr r0, [r6]
	str r0, [r5]
	str r1, [r6]
	movs r2, #1
	mov sl, r2
.L08077D78:
	lsls r0, r7, #0x18
	lsrs r5, r0, #0x18
	ldr r0, .L08077D9C @ =0x0200CD38
	ldrb r0, [r0]
	mov r3, r8
	subs r0, r0, r3
	cmp r5, r0
	blt .L08077D48
.L08077D88:
	mov r4, r8
	lsls r0, r4, #0x18
	lsrs r1, r0, #0x18
	ldr r2, .L08077D9C @ =0x0200CD38
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L08077D36
	bl .L0807906C
	.align 2, 0
.L08077D9C: .4byte 0x0200CD38
.L08077DA0: .4byte 0x0200CC38
.L08077DA4:
	cmp r2, #0
	bne .L08077E2C
	movs r0, #0
	mov sl, r0
	movs r1, #0
	ldr r3, .L08077E24 @ =0x0200CD38
	ldrb r0, [r3]
	subs r0, #1
	cmp r2, r0
	blt .L08077DBC
	bl .L080790F6
.L08077DBC:
	movs r5, #0
	adds r0, r1, #1
	ldrb r3, [r3]
	subs r1, r3, r0
	mov r8, r0
	cmp r5, r1
	bge .L08077E0E
	ldr r1, .L08077E28 @ =0x0200CC38
	mov sb, r1
.L08077DCE:
	adds r7, r5, #1
	lsls r0, r7, #2
	mov r2, sb
	adds r6, r0, r2
	ldr r0, [r6]
	ldr r0, [r0]
	bl GetUnitAffinityIcon
	adds r4, r0, #0
	lsls r0, r5, #2
	mov r3, sb
	adds r5, r0, r3
	ldr r0, [r5]
	ldr r0, [r0]
	bl GetUnitAffinityIcon
	cmp r4, r0
	bge .L08077DFE
	ldr r1, [r5]
	ldr r0, [r6]
	str r0, [r5]
	str r1, [r6]
	movs r4, #1
	mov sl, r4
.L08077DFE:
	lsls r0, r7, #0x18
	lsrs r5, r0, #0x18
	ldr r0, .L08077E24 @ =0x0200CD38
	ldrb r0, [r0]
	mov r7, r8
	subs r0, r0, r7
	cmp r5, r0
	blt .L08077DCE
.L08077E0E:
	mov r1, r8
	lsls r0, r1, #0x18
	lsrs r1, r0, #0x18
	ldr r3, .L08077E24 @ =0x0200CD38
	ldrb r0, [r3]
	subs r0, #1
	cmp r1, r0
	blt .L08077DBC
	bl .L080790F6
	.align 2, 0
.L08077E24: .4byte 0x0200CD38
.L08077E28: .4byte 0x0200CC38
.L08077E2C:
	movs r3, #0
	mov sl, r3
	movs r1, #0
	ldr r2, .L08077EA8 @ =0x0200CD38
	ldrb r0, [r2]
	subs r0, #1
	cmp sl, r0
	blt .L08077E40
	bl .L0807917A
.L08077E40:
	movs r5, #0
	adds r0, r1, #1
	ldrb r2, [r2]
	subs r1, r2, r0
	mov r8, r0
	cmp r5, r1
	bge .L08077E92
	ldr r4, .L08077EAC @ =0x0200CC38
	mov sb, r4
.L08077E52:
	adds r7, r5, #1
	lsls r0, r7, #2
	mov r1, sb
	adds r6, r0, r1
	ldr r0, [r6]
	ldr r0, [r0]
	bl GetUnitAffinityIcon
	adds r4, r0, #0
	lsls r0, r5, #2
	mov r2, sb
	adds r5, r0, r2
	ldr r0, [r5]
	ldr r0, [r0]
	bl GetUnitAffinityIcon
	cmp r4, r0
	ble .L08077E82
	ldr r1, [r5]
	ldr r0, [r6]
	str r0, [r5]
	str r1, [r6]
	movs r3, #1
	mov sl, r3
.L08077E82:
	lsls r0, r7, #0x18
	lsrs r5, r0, #0x18
	ldr r0, .L08077EA8 @ =0x0200CD38
	ldrb r0, [r0]
	mov r4, r8
	subs r0, r0, r4
	cmp r5, r0
	blt .L08077E52
.L08077E92:
	mov r7, r8
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	ldr r2, .L08077EA8 @ =0x0200CD38
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L08077E40
	bl .L0807917A
	.align 2, 0
.L08077EA8: .4byte 0x0200CD38
.L08077EAC: .4byte 0x0200CC38
.L08077EB0:
	cmp r2, #0
	beq .L08077EB6
	b .L08077FB4
.L08077EB6:
	movs r1, #0
	str r1, [sp, #0x50]
	movs r4, #0
	ldr r0, .L08077EF4 @ =0x0200CD38
	ldrb r0, [r0]
	cmp r2, r0
	bhs .L08077EEE
	ldr r5, .L08077EF8 @ =0x0200CC38
.L08077EC6:
	lsls r0, r4, #2
	adds r0, r0, r5
	ldr r0, [r0]
	ldr r0, [r0]
	bl GetUnitEquippedWeapon
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl GetItemIid
	mov r2, sp
	adds r1, r2, r4
	strb r0, [r1]
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, .L08077EF4 @ =0x0200CD38
	ldrb r0, [r0]
	cmp r4, r0
	blo .L08077EC6
.L08077EEE:
	movs r4, #0
	b .L08077FA2
	.align 2, 0
.L08077EF4: .4byte 0x0200CD38
.L08077EF8: .4byte 0x0200CC38
.L08077EFC:
	movs r6, #0
	adds r0, r4, #1
	ldrb r1, [r1]
	subs r1, r1, r0
	str r0, [sp, #0x58]
	cmp r6, r1
	bge .L08077F9C
	ldr r3, .L08077F44 @ =0x0200CC38
	mov sl, r3
.L08077F0E:
	adds r0, r6, #1
	mov r4, sp
	adds r4, r4, r0
	mov r8, r4
	mov r7, sp
	adds r5, r7, r6
	ldrb r4, [r4]
	adds r3, r4, #0
	ldrb r2, [r5]
	mov sb, r0
	cmp r3, r2
	bls .L08077F48
	adds r1, r2, #0
	strb r4, [r5]
	mov r0, r8
	strb r1, [r0]
	lsls r2, r6, #2
	add r2, sl
	ldr r3, [r2]
	mov r4, sb
	lsls r1, r4, #2
	add r1, sl
	ldr r0, [r1]
	str r0, [r2]
	str r3, [r1]
	b .L08077F86
	.align 2, 0
.L08077F44: .4byte 0x0200CC38
.L08077F48:
	cmp r3, r2
	bne .L08077F8A
	mov r1, sb
	lsls r0, r1, #2
	mov r2, sl
	adds r7, r0, r2
	ldr r0, [r7]
	ldr r0, [r0]
	bl GetUnitEquippedWeapon
	adds r4, r0, #0
	lsls r0, r6, #2
	mov r3, sl
	adds r6, r0, r3
	ldr r0, [r6]
	ldr r0, [r0]
	bl GetUnitEquippedWeapon
	lsls r4, r4, #0x10
	lsls r0, r0, #0x10
	cmp r4, r0
	bls .L08077F8A
	ldrb r1, [r5]
	mov r4, r8
	ldrb r0, [r4]
	strb r0, [r5]
	strb r1, [r4]
	ldr r3, [r6]
	ldr r0, [r7]
	str r0, [r6]
	str r3, [r7]
.L08077F86:
	movs r7, #1
	str r7, [sp, #0x50]
.L08077F8A:
	mov r1, sb
	lsls r0, r1, #0x18
	lsrs r6, r0, #0x18
	ldr r0, .L08077FB0 @ =0x0200CD38
	ldrb r0, [r0]
	ldr r2, [sp, #0x58]
	subs r0, r0, r2
	cmp r6, r0
	blt .L08077F0E
.L08077F9C:
	ldr r3, [sp, #0x58]
	lsls r0, r3, #0x18
	lsrs r4, r0, #0x18
.L08077FA2:
	ldr r1, .L08077FB0 @ =0x0200CD38
	ldrb r0, [r1]
	subs r0, #1
	cmp r4, r0
	blt .L08077EFC
	ldr r4, [sp, #0x50]
	b .L080780AA
	.align 2, 0
.L08077FB0: .4byte 0x0200CD38
.L08077FB4:
	movs r7, #0
	str r7, [sp, #0x54]
	movs r4, #0
	ldr r0, .L08077FF0 @ =0x0200CD38
	ldrb r0, [r0]
	cmp r7, r0
	bhs .L08077FEC
	ldr r5, .L08077FF4 @ =0x0200CC38
.L08077FC4:
	lsls r0, r4, #2
	adds r0, r0, r5
	ldr r0, [r0]
	ldr r0, [r0]
	bl GetUnitEquippedWeapon
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl GetItemIid
	mov r2, sp
	adds r1, r2, r4
	strb r0, [r1]
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, .L08077FF0 @ =0x0200CD38
	ldrb r0, [r0]
	cmp r4, r0
	blo .L08077FC4
.L08077FEC:
	movs r4, #0
	b .L0807809E
	.align 2, 0
.L08077FF0: .4byte 0x0200CD38
.L08077FF4: .4byte 0x0200CC38
.L08077FF8:
	movs r6, #0
	adds r0, r4, #1
	ldrb r1, [r1]
	subs r1, r1, r0
	str r0, [sp, #0x5c]
	cmp r6, r1
	bge .L08078098
	ldr r3, .L08078040 @ =0x0200CC38
	mov sl, r3
.L0807800A:
	adds r0, r6, #1
	mov r4, sp
	adds r4, r4, r0
	mov r8, r4
	mov r7, sp
	adds r5, r7, r6
	ldrb r4, [r4]
	adds r3, r4, #0
	ldrb r2, [r5]
	mov sb, r0
	cmp r3, r2
	bhs .L08078044
	adds r1, r2, #0
	strb r4, [r5]
	mov r0, r8
	strb r1, [r0]
	lsls r2, r6, #2
	add r2, sl
	ldr r3, [r2]
	mov r4, sb
	lsls r1, r4, #2
	add r1, sl
	ldr r0, [r1]
	str r0, [r2]
	str r3, [r1]
	b .L08078082
	.align 2, 0
.L08078040: .4byte 0x0200CC38
.L08078044:
	cmp r3, r2
	bne .L08078086
	mov r1, sb
	lsls r0, r1, #2
	mov r2, sl
	adds r7, r0, r2
	ldr r0, [r7]
	ldr r0, [r0]
	bl GetUnitEquippedWeapon
	adds r4, r0, #0
	lsls r0, r6, #2
	mov r3, sl
	adds r6, r0, r3
	ldr r0, [r6]
	ldr r0, [r0]
	bl GetUnitEquippedWeapon
	lsls r4, r4, #0x10
	lsls r0, r0, #0x10
	cmp r4, r0
	bhs .L08078086
	ldrb r1, [r5]
	mov r4, r8
	ldrb r0, [r4]
	strb r0, [r5]
	strb r1, [r4]
	ldr r3, [r6]
	ldr r0, [r7]
	str r0, [r6]
	str r3, [r7]
.L08078082:
	movs r7, #1
	str r7, [sp, #0x54]
.L08078086:
	mov r1, sb
	lsls r0, r1, #0x18
	lsrs r6, r0, #0x18
	ldr r0, .L080780B8 @ =0x0200CD38
	ldrb r0, [r0]
	ldr r2, [sp, #0x5c]
	subs r0, r0, r2
	cmp r6, r0
	blt .L0807800A
.L08078098:
	ldr r3, [sp, #0x5c]
	lsls r0, r3, #0x18
	lsrs r4, r0, #0x18
.L0807809E:
	ldr r1, .L080780B8 @ =0x0200CD38
	ldrb r0, [r1]
	subs r0, #1
	cmp r4, r0
	blt .L08077FF8
	ldr r4, [sp, #0x54]
.L080780AA:
	cmp r4, #0
	bne .L080780B2
	bl .L0807918C
.L080780B2:
	movs r0, #1
	bl .L0807918E
	.align 2, 0
.L080780B8: .4byte 0x0200CD38
.L080780BC:
	cmp r2, #0
	bne .L08078138
	movs r7, #0
	mov ip, r7
	movs r1, #0
	ldr r3, .L08078130 @ =0x0200CD38
	ldrb r0, [r3]
	subs r0, #1
	cmp r2, r0
	bge .L0807812A
	adds r4, r3, #0
	mov sl, r4
.L080780D4:
	movs r2, #0
	adds r0, r1, #1
	mov r7, sl
	ldrb r7, [r7]
	subs r1, r7, r0
	mov sb, r0
	cmp r2, r1
	bge .L0807811A
	mov r8, sb
.L080780E6:
	adds r6, r2, #1
	lsls r0, r6, #2
	ldr r1, .L08078134 @ =0x0200CC38
	adds r5, r0, r1
	ldr r4, [r5]
	lsls r0, r2, #2
	adds r2, r0, r1
	ldr r3, [r2]
	movs r7, #4
	ldrsh r1, [r4, r7]
	movs r7, #4
	ldrsh r0, [r3, r7]
	cmp r1, r0
	ble .L0807810A
	str r4, [r2]
	str r3, [r5]
	movs r0, #1
	mov ip, r0
.L0807810A:
	lsls r0, r6, #0x18
	lsrs r2, r0, #0x18
	mov r1, sl
	ldrb r1, [r1]
	mov r3, r8
	subs r0, r1, r3
	cmp r2, r0
	blt .L080780E6
.L0807811A:
	mov r4, sb
	lsls r0, r4, #0x18
	lsrs r1, r0, #0x18
	ldr r7, .L08078130 @ =0x0200CD38
	ldrb r0, [r7]
	subs r0, #1
	cmp r1, r0
	blt .L080780D4
.L0807812A:
	mov r0, ip
	bl .L0807917C
	.align 2, 0
.L08078130: .4byte 0x0200CD38
.L08078134: .4byte 0x0200CC38
.L08078138:
	movs r1, #0
	mov ip, r1
	ldr r2, .L080781A8 @ =0x0200CD38
	ldrb r0, [r2]
	subs r0, #1
	cmp ip, r0
	bge .L080781A0
	adds r3, r2, #0
	mov sl, r3
.L0807814A:
	movs r2, #0
	adds r0, r1, #1
	mov r4, sl
	ldrb r4, [r4]
	subs r1, r4, r0
	mov sb, r0
	cmp r2, r1
	bge .L08078190
	mov r8, sb
.L0807815C:
	adds r6, r2, #1
	lsls r0, r6, #2
	ldr r7, .L080781AC @ =0x0200CC38
	adds r5, r0, r7
	ldr r4, [r5]
	lsls r0, r2, #2
	adds r2, r0, r7
	ldr r3, [r2]
	movs r0, #4
	ldrsh r1, [r4, r0]
	movs r7, #4
	ldrsh r0, [r3, r7]
	cmp r1, r0
	bge .L08078180
	str r4, [r2]
	str r3, [r5]
	movs r0, #1
	mov ip, r0
.L08078180:
	lsls r0, r6, #0x18
	lsrs r2, r0, #0x18
	mov r1, sl
	ldrb r1, [r1]
	mov r3, r8
	subs r0, r1, r3
	cmp r2, r0
	blt .L0807815C
.L08078190:
	mov r4, sb
	lsls r0, r4, #0x18
	lsrs r1, r0, #0x18
	ldr r7, .L080781A8 @ =0x0200CD38
	ldrb r0, [r7]
	subs r0, #1
	cmp r1, r0
	blt .L0807814A
.L080781A0:
	mov r0, ip
	bl .L0807917C
	.align 2, 0
.L080781A8: .4byte 0x0200CD38
.L080781AC: .4byte 0x0200CC38
.L080781B0:
	cmp r2, #0
	bne .L0807822C
	movs r1, #0
	mov ip, r1
	ldr r3, .L08078224 @ =0x0200CD38
	ldrb r0, [r3]
	subs r0, #1
	cmp r2, r0
	bge .L0807821C
	adds r4, r3, #0
	mov sl, r4
.L080781C6:
	movs r2, #0
	adds r0, r1, #1
	mov r7, sl
	ldrb r7, [r7]
	subs r1, r7, r0
	mov sb, r0
	cmp r2, r1
	bge .L0807820C
	mov r8, sb
.L080781D8:
	adds r6, r2, #1
	lsls r0, r6, #2
	ldr r1, .L08078228 @ =0x0200CC38
	adds r5, r0, r1
	ldr r4, [r5]
	lsls r0, r2, #2
	adds r2, r0, r1
	ldr r3, [r2]
	movs r7, #6
	ldrsh r1, [r4, r7]
	movs r7, #6
	ldrsh r0, [r3, r7]
	cmp r1, r0
	ble .L080781FC
	str r4, [r2]
	str r3, [r5]
	movs r0, #1
	mov ip, r0
.L080781FC:
	lsls r0, r6, #0x18
	lsrs r2, r0, #0x18
	mov r1, sl
	ldrb r1, [r1]
	mov r3, r8
	subs r0, r1, r3
	cmp r2, r0
	blt .L080781D8
.L0807820C:
	mov r4, sb
	lsls r0, r4, #0x18
	lsrs r1, r0, #0x18
	ldr r7, .L08078224 @ =0x0200CD38
	ldrb r0, [r7]
	subs r0, #1
	cmp r1, r0
	blt .L080781C6
.L0807821C:
	mov r0, ip
	bl .L0807917C
	.align 2, 0
.L08078224: .4byte 0x0200CD38
.L08078228: .4byte 0x0200CC38
.L0807822C:
	movs r1, #0
	mov ip, r1
	ldr r2, .L0807829C @ =0x0200CD38
	ldrb r0, [r2]
	subs r0, #1
	cmp ip, r0
	bge .L08078294
	adds r3, r2, #0
	mov sl, r3
.L0807823E:
	movs r2, #0
	adds r0, r1, #1
	mov r4, sl
	ldrb r4, [r4]
	subs r1, r4, r0
	mov sb, r0
	cmp r2, r1
	bge .L08078284
	mov r8, sb
.L08078250:
	adds r6, r2, #1
	lsls r0, r6, #2
	ldr r7, .L080782A0 @ =0x0200CC38
	adds r5, r0, r7
	ldr r4, [r5]
	lsls r0, r2, #2
	adds r2, r0, r7
	ldr r3, [r2]
	movs r0, #6
	ldrsh r1, [r4, r0]
	movs r7, #6
	ldrsh r0, [r3, r7]
	cmp r1, r0
	bge .L08078274
	str r4, [r2]
	str r3, [r5]
	movs r0, #1
	mov ip, r0
.L08078274:
	lsls r0, r6, #0x18
	lsrs r2, r0, #0x18
	mov r1, sl
	ldrb r1, [r1]
	mov r3, r8
	subs r0, r1, r3
	cmp r2, r0
	blt .L08078250
.L08078284:
	mov r4, sb
	lsls r0, r4, #0x18
	lsrs r1, r0, #0x18
	ldr r7, .L0807829C @ =0x0200CD38
	ldrb r0, [r7]
	subs r0, #1
	cmp r1, r0
	blt .L0807823E
.L08078294:
	mov r0, ip
	bl .L0807917C
	.align 2, 0
.L0807829C: .4byte 0x0200CD38
.L080782A0: .4byte 0x0200CC38
.L080782A4:
	cmp r2, #0
	bne .L08078320
	movs r1, #0
	mov ip, r1
	ldr r3, .L08078318 @ =0x0200CD38
	ldrb r0, [r3]
	subs r0, #1
	cmp r2, r0
	bge .L08078310
	adds r4, r3, #0
	mov sl, r4
.L080782BA:
	movs r2, #0
	adds r0, r1, #1
	mov r7, sl
	ldrb r7, [r7]
	subs r1, r7, r0
	mov sb, r0
	cmp r2, r1
	bge .L08078300
	mov r8, sb
.L080782CC:
	adds r6, r2, #1
	lsls r0, r6, #2
	ldr r1, .L0807831C @ =0x0200CC38
	adds r5, r0, r1
	ldr r4, [r5]
	lsls r0, r2, #2
	adds r2, r0, r1
	ldr r3, [r2]
	movs r7, #8
	ldrsh r1, [r4, r7]
	movs r7, #8
	ldrsh r0, [r3, r7]
	cmp r1, r0
	ble .L080782F0
	str r4, [r2]
	str r3, [r5]
	movs r0, #1
	mov ip, r0
.L080782F0:
	lsls r0, r6, #0x18
	lsrs r2, r0, #0x18
	mov r1, sl
	ldrb r1, [r1]
	mov r3, r8
	subs r0, r1, r3
	cmp r2, r0
	blt .L080782CC
.L08078300:
	mov r4, sb
	lsls r0, r4, #0x18
	lsrs r1, r0, #0x18
	ldr r7, .L08078318 @ =0x0200CD38
	ldrb r0, [r7]
	subs r0, #1
	cmp r1, r0
	blt .L080782BA
.L08078310:
	mov r0, ip
	bl .L0807917C
	.align 2, 0
.L08078318: .4byte 0x0200CD38
.L0807831C: .4byte 0x0200CC38
.L08078320:
	movs r1, #0
	mov ip, r1
	ldr r2, .L08078390 @ =0x0200CD38
	ldrb r0, [r2]
	subs r0, #1
	cmp ip, r0
	bge .L08078388
	adds r3, r2, #0
	mov sl, r3
.L08078332:
	movs r2, #0
	adds r0, r1, #1
	mov r4, sl
	ldrb r4, [r4]
	subs r1, r4, r0
	mov sb, r0
	cmp r2, r1
	bge .L08078378
	mov r8, sb
.L08078344:
	adds r6, r2, #1
	lsls r0, r6, #2
	ldr r7, .L08078394 @ =0x0200CC38
	adds r5, r0, r7
	ldr r4, [r5]
	lsls r0, r2, #2
	adds r2, r0, r7
	ldr r3, [r2]
	movs r0, #8
	ldrsh r1, [r4, r0]
	movs r7, #8
	ldrsh r0, [r3, r7]
	cmp r1, r0
	bge .L08078368
	str r4, [r2]
	str r3, [r5]
	movs r0, #1
	mov ip, r0
.L08078368:
	lsls r0, r6, #0x18
	lsrs r2, r0, #0x18
	mov r1, sl
	ldrb r1, [r1]
	mov r3, r8
	subs r0, r1, r3
	cmp r2, r0
	blt .L08078344
.L08078378:
	mov r4, sb
	lsls r0, r4, #0x18
	lsrs r1, r0, #0x18
	ldr r7, .L08078390 @ =0x0200CD38
	ldrb r0, [r7]
	subs r0, #1
	cmp r1, r0
	blt .L08078332
.L08078388:
	mov r0, ip
	bl .L0807917C
	.align 2, 0
.L08078390: .4byte 0x0200CD38
.L08078394: .4byte 0x0200CC38
.L08078398:
	cmp r2, #0
	bne .L0807842C
	movs r1, #0
	mov ip, r1
	ldr r3, .L08078424 @ =0x0200CD38
	ldrb r0, [r3]
	subs r0, #1
	cmp r2, r0
	bge .L0807841E
	adds r4, r3, #0
	mov sl, r4
.L080783AE:
	movs r3, #0
	adds r0, r1, #1
	mov r7, sl
	ldrb r7, [r7]
	subs r1, r7, r0
	mov r8, r0
	cmp r3, r1
	bge .L0807840E
	ldr r0, .L08078428 @ =0x0200CC38
	mov sb, r0
.L080783C2:
	adds r7, r3, #1
	lsls r0, r7, #2
	mov r1, sb
	adds r6, r0, r1
	ldr r5, [r6]
	ldr r0, [r5]
	movs r2, #0x1a
	ldrsb r2, [r0, r2]
	ldr r0, [r0, #4]
	ldrb r0, [r0, #0x12]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r2, r2, r0
	lsls r0, r3, #2
	adds r3, r0, r1
	ldr r4, [r3]
	ldr r0, [r4]
	movs r1, #0x1a
	ldrsb r1, [r0, r1]
	ldr r0, [r0, #4]
	ldrb r0, [r0, #0x12]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r1, r1, r0
	cmp r2, r1
	ble .L080783FE
	str r5, [r3]
	str r4, [r6]
	movs r2, #1
	mov ip, r2
.L080783FE:
	lsls r0, r7, #0x18
	lsrs r3, r0, #0x18
	mov r4, sl
	ldrb r4, [r4]
	mov r7, r8
	subs r0, r4, r7
	cmp r3, r0
	blt .L080783C2
.L0807840E:
	mov r1, r8
	lsls r0, r1, #0x18
	lsrs r1, r0, #0x18
	ldr r2, .L08078424 @ =0x0200CD38
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L080783AE
.L0807841E:
	mov r3, ip
	bl .L08078F78
	.align 2, 0
.L08078424: .4byte 0x0200CD38
.L08078428: .4byte 0x0200CC38
.L0807842C:
	movs r4, #0
	mov ip, r4
	movs r1, #0
	ldr r7, .L080784B8 @ =0x0200CD38
	ldrb r0, [r7]
	subs r0, #1
	cmp ip, r0
	bge .L080784B0
	adds r0, r7, #0
	mov sl, r0
.L08078440:
	movs r3, #0
	adds r0, r1, #1
	mov r2, sl
	ldrb r2, [r2]
	subs r1, r2, r0
	mov r8, r0
	cmp r3, r1
	bge .L080784A0
	ldr r4, .L080784BC @ =0x0200CC38
	mov sb, r4
.L08078454:
	adds r7, r3, #1
	lsls r0, r7, #2
	mov r1, sb
	adds r6, r0, r1
	ldr r5, [r6]
	ldr r0, [r5]
	movs r2, #0x1a
	ldrsb r2, [r0, r2]
	ldr r0, [r0, #4]
	ldrb r0, [r0, #0x12]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r2, r2, r0
	lsls r0, r3, #2
	adds r3, r0, r1
	ldr r4, [r3]
	ldr r0, [r4]
	movs r1, #0x1a
	ldrsb r1, [r0, r1]
	ldr r0, [r0, #4]
	ldrb r0, [r0, #0x12]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r1, r1, r0
	cmp r2, r1
	bge .L08078490
	str r5, [r3]
	str r4, [r6]
	movs r2, #1
	mov ip, r2
.L08078490:
	lsls r0, r7, #0x18
	lsrs r3, r0, #0x18
	mov r4, sl
	ldrb r4, [r4]
	mov r7, r8
	subs r0, r4, r7
	cmp r3, r0
	blt .L08078454
.L080784A0:
	mov r1, r8
	lsls r0, r1, #0x18
	lsrs r1, r0, #0x18
	ldr r2, .L080784B8 @ =0x0200CD38
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L08078440
.L080784B0:
	mov r3, ip
	bl .L08078F78
	.align 2, 0
.L080784B8: .4byte 0x0200CD38
.L080784BC: .4byte 0x0200CC38
.L080784C0:
	cmp r2, #0
	bne .L0807854C
	movs r4, #0
	mov sl, r4
	movs r1, #0
	ldr r7, .L08078544 @ =0x0200CD38
	mov ip, r7
	mov r3, ip
	ldrb r0, [r3]
	subs r0, #1
	cmp r2, r0
	blt .L080784DC
	bl .L08078F76
.L080784DC:
	adds r4, r3, #0
	mov sb, r4
.L080784E0:
	movs r2, #0
	adds r0, r1, #1
	mov r7, sb
	ldrb r7, [r7]
	subs r1, r7, r0
	adds r7, r0, #0
	cmp r2, r1
	bge .L08078530
	ldr r0, .L08078548 @ =0x0200CC38
	mov r8, r0
.L080784F4:
	adds r6, r2, #1
	lsls r0, r6, #2
	mov r1, r8
	adds r5, r0, r1
	ldr r4, [r5]
	ldr r0, [r4]
	adds r0, #0x2e
	ldrb r0, [r0]
	lsls r1, r0, #0x1c
	lsls r0, r2, #2
	mov r3, r8
	adds r2, r0, r3
	ldr r3, [r2]
	ldr r0, [r3]
	adds r0, #0x2e
	ldrb r0, [r0]
	lsls r0, r0, #0x1c
	cmp r1, r0
	bls .L08078522
	str r4, [r2]
	str r3, [r5]
	movs r4, #1
	mov sl, r4
.L08078522:
	lsls r0, r6, #0x18
	lsrs r2, r0, #0x18
	mov r1, sb
	ldrb r1, [r1]
	subs r0, r1, r7
	cmp r2, r0
	blt .L080784F4
.L08078530:
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L080784E0
	bl .L08078F76
	.align 2, 0
.L08078544: .4byte 0x0200CD38
.L08078548: .4byte 0x0200CC38
.L0807854C:
	movs r4, #0
	mov sl, r4
	movs r1, #0
	ldr r7, .L080785CC @ =0x0200CD38
	mov ip, r7
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp sl, r0
	blt .L08078564
	bl .L08078F76
.L08078564:
	adds r3, r2, #0
	mov sb, r3
.L08078568:
	movs r2, #0
	adds r0, r1, #1
	mov r4, sb
	ldrb r4, [r4]
	subs r1, r4, r0
	adds r7, r0, #0
	cmp r2, r1
	bge .L080785B8
	ldr r0, .L080785D0 @ =0x0200CC38
	mov r8, r0
.L0807857C:
	adds r6, r2, #1
	lsls r0, r6, #2
	mov r1, r8
	adds r5, r0, r1
	ldr r4, [r5]
	ldr r0, [r4]
	adds r0, #0x2e
	ldrb r0, [r0]
	lsls r1, r0, #0x1c
	lsls r0, r2, #2
	mov r3, r8
	adds r2, r0, r3
	ldr r3, [r2]
	ldr r0, [r3]
	adds r0, #0x2e
	ldrb r0, [r0]
	lsls r0, r0, #0x1c
	cmp r1, r0
	bhs .L080785AA
	str r4, [r2]
	str r3, [r5]
	movs r4, #1
	mov sl, r4
.L080785AA:
	lsls r0, r6, #0x18
	lsrs r2, r0, #0x18
	mov r1, sb
	ldrb r1, [r1]
	subs r0, r1, r7
	cmp r2, r0
	blt .L0807857C
.L080785B8:
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L08078568
	bl .L08078F76
	.align 2, 0
.L080785CC: .4byte 0x0200CD38
.L080785D0: .4byte 0x0200CC38
.L080785D4:
	cmp r2, #0
	bne .L080786A0
	movs r4, #0
	mov sb, r4
	movs r3, #0
	ldr r0, .L0807860C @ =0x0200CD38
	ldrb r1, [r0]
	cmp r2, r1
	bhs .L08078624
	ldr r6, .L08078610 @ =0x0200CC38
	adds r2, r1, #0
	movs r5, #0x10
	movs r4, #1
.L080785EE:
	lsls r0, r3, #2
	adds r0, r0, r6
	ldr r0, [r0]
	ldr r1, [r0]
	adds r0, r5, #0
	ldrh r1, [r1, #0xc]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq .L08078614
	mov r7, sp
	adds r0, r7, r3
	strb r4, [r0]
	b .L0807861A
	.align 2, 0
.L0807860C: .4byte 0x0200CD38
.L08078610: .4byte 0x0200CC38
.L08078614:
	mov r7, sp
	adds r0, r7, r3
	strb r1, [r0]
.L0807861A:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, r2
	blo .L080785EE
.L08078624:
	movs r3, #0
	ldr r1, .L08078698 @ =0x0200CD38
	ldrb r0, [r1]
	subs r0, #1
	cmp r3, r0
	bge .L08078690
	mov r8, r1
	ldr r2, .L0807869C @ =0x0200CC38
	mov ip, r2
	mov sl, r8
.L08078638:
	movs r2, #0
	adds r0, r3, #1
	mov r3, r8
	ldrb r3, [r3]
	subs r1, r3, r0
	adds r6, r0, #0
	cmp r2, r1
	bge .L08078682
	mov r7, ip
.L0807864A:
	adds r5, r2, #1
	mov r0, sp
	adds r4, r0, r5
	adds r1, r0, r2
	ldrb r3, [r4]
	ldrb r0, [r1]
	cmp r3, r0
	bls .L08078674
	ldrb r0, [r1]
	strb r3, [r1]
	strb r0, [r4]
	lsls r2, r2, #2
	adds r2, r2, r7
	ldr r3, [r2]
	lsls r1, r5, #2
	adds r1, r1, r7
	ldr r0, [r1]
	str r0, [r2]
	str r3, [r1]
	movs r1, #1
	mov sb, r1
.L08078674:
	lsls r0, r5, #0x18
	lsrs r2, r0, #0x18
	mov r3, r8
	ldrb r3, [r3]
	subs r0, r3, r6
	cmp r2, r0
	blt .L0807864A
.L08078682:
	lsls r0, r6, #0x18
	lsrs r3, r0, #0x18
	mov r4, sl
	ldrb r0, [r4]
	subs r0, #1
	cmp r3, r0
	blt .L08078638
.L08078690:
	mov r7, sb
	bl .L0807906E
	.align 2, 0
.L08078698: .4byte 0x0200CD38
.L0807869C: .4byte 0x0200CC38
.L080786A0:
	movs r0, #0
	mov sb, r0
	movs r3, #0
	ldr r0, .L080786D4 @ =0x0200CD38
	ldrb r1, [r0]
	cmp sb, r1
	bhs .L080786EC
	ldr r6, .L080786D8 @ =0x0200CC38
	adds r2, r1, #0
	movs r5, #0x10
	movs r4, #1
.L080786B6:
	lsls r0, r3, #2
	adds r0, r0, r6
	ldr r0, [r0]
	ldr r1, [r0]
	adds r0, r5, #0
	ldrh r1, [r1, #0xc]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq .L080786DC
	mov r1, sp
	adds r0, r1, r3
	strb r4, [r0]
	b .L080786E2
	.align 2, 0
.L080786D4: .4byte 0x0200CD38
.L080786D8: .4byte 0x0200CC38
.L080786DC:
	mov r7, sp
	adds r0, r7, r3
	strb r1, [r0]
.L080786E2:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, r2
	blo .L080786B6
.L080786EC:
	movs r3, #0
	ldr r1, .L08078760 @ =0x0200CD38
	ldrb r0, [r1]
	subs r0, #1
	cmp r3, r0
	bge .L08078758
	mov r8, r1
	ldr r2, .L08078764 @ =0x0200CC38
	mov ip, r2
	mov sl, r8
.L08078700:
	movs r2, #0
	adds r0, r3, #1
	mov r3, r8
	ldrb r3, [r3]
	subs r1, r3, r0
	adds r6, r0, #0
	cmp r2, r1
	bge .L0807874A
	mov r7, ip
.L08078712:
	adds r5, r2, #1
	mov r0, sp
	adds r4, r0, r5
	adds r1, r0, r2
	ldrb r3, [r4]
	ldrb r0, [r1]
	cmp r3, r0
	bhs .L0807873C
	ldrb r0, [r1]
	strb r3, [r1]
	strb r0, [r4]
	lsls r2, r2, #2
	adds r2, r2, r7
	ldr r3, [r2]
	lsls r1, r5, #2
	adds r1, r1, r7
	ldr r0, [r1]
	str r0, [r2]
	str r3, [r1]
	movs r1, #1
	mov sb, r1
.L0807873C:
	lsls r0, r5, #0x18
	lsrs r2, r0, #0x18
	mov r3, r8
	ldrb r3, [r3]
	subs r0, r3, r6
	cmp r2, r0
	blt .L08078712
.L0807874A:
	lsls r0, r6, #0x18
	lsrs r3, r0, #0x18
	mov r4, sl
	ldrb r0, [r4]
	subs r0, #1
	cmp r3, r0
	blt .L08078700
.L08078758:
	mov r7, sb
	bl .L0807906E
	.align 2, 0
.L08078760: .4byte 0x0200CD38
.L08078764: .4byte 0x0200CC38
.L08078768:
	cmp r2, #0
	bne .L080787EC
	movs r0, #0
	mov sl, r0
	movs r1, #0
	ldr r3, .L080787E4 @ =0x0200CD38
	mov ip, r3
	ldrb r0, [r3]
	subs r0, #1
	cmp r2, r0
	blt .L08078782
	bl .L08078F76
.L08078782:
	adds r4, r3, #0
	mov sb, r4
.L08078786:
	movs r2, #0
	adds r0, r1, #1
	mov r7, sb
	ldrb r7, [r7]
	subs r1, r7, r0
	adds r7, r0, #0
	cmp r2, r1
	bge .L080787D2
	ldr r0, .L080787E8 @ =0x0200CC38
	mov r8, r0
.L0807879A:
	adds r6, r2, #1
	lsls r0, r6, #2
	mov r1, r8
	adds r5, r0, r1
	ldr r4, [r5]
	ldr r1, [r4]
	adds r1, #0x26
	lsls r0, r2, #2
	mov r3, r8
	adds r2, r0, r3
	ldr r3, [r2]
	ldr r0, [r3]
	adds r0, #0x26
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bls .L080787C4
	str r4, [r2]
	str r3, [r5]
	movs r4, #1
	mov sl, r4
.L080787C4:
	lsls r0, r6, #0x18
	lsrs r2, r0, #0x18
	mov r1, sb
	ldrb r1, [r1]
	subs r0, r1, r7
	cmp r2, r0
	blt .L0807879A
.L080787D2:
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L08078786
	b .L08078F76
	.align 2, 0
.L080787E4: .4byte 0x0200CD38
.L080787E8: .4byte 0x0200CC38
.L080787EC:
	movs r4, #0
	mov sl, r4
	movs r1, #0
	ldr r7, .L08078864 @ =0x0200CD38
	mov ip, r7
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp sl, r0
	blt .L08078802
	b .L08078F76
.L08078802:
	adds r3, r2, #0
	mov sb, r3
.L08078806:
	movs r2, #0
	adds r0, r1, #1
	mov r4, sb
	ldrb r4, [r4]
	subs r1, r4, r0
	adds r7, r0, #0
	cmp r2, r1
	bge .L08078852
	ldr r0, .L08078868 @ =0x0200CC38
	mov r8, r0
.L0807881A:
	adds r6, r2, #1
	lsls r0, r6, #2
	mov r1, r8
	adds r5, r0, r1
	ldr r4, [r5]
	ldr r1, [r4]
	adds r1, #0x26
	lsls r0, r2, #2
	mov r3, r8
	adds r2, r0, r3
	ldr r3, [r2]
	ldr r0, [r3]
	adds r0, #0x26
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bhs .L08078844
	str r4, [r2]
	str r3, [r5]
	movs r4, #1
	mov sl, r4
.L08078844:
	lsls r0, r6, #0x18
	lsrs r2, r0, #0x18
	mov r1, sb
	ldrb r1, [r1]
	subs r0, r1, r7
	cmp r2, r0
	blt .L0807881A
.L08078852:
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L08078806
	b .L08078F76
	.align 2, 0
.L08078864: .4byte 0x0200CD38
.L08078868: .4byte 0x0200CC38
.L0807886C:
	cmp r2, #0
	bne .L080788F0
	movs r4, #0
	mov sl, r4
	movs r1, #0
	ldr r7, .L080788E8 @ =0x0200CD38
	mov ip, r7
	mov r3, ip
	ldrb r0, [r3]
	subs r0, #1
	cmp r2, r0
	blt .L08078886
	b .L08078F76
.L08078886:
	adds r4, r3, #0
	mov sb, r4
.L0807888A:
	movs r2, #0
	adds r0, r1, #1
	mov r7, sb
	ldrb r7, [r7]
	subs r1, r7, r0
	adds r7, r0, #0
	cmp r2, r1
	bge .L080788D6
	ldr r0, .L080788EC @ =0x0200CC38
	mov r8, r0
.L0807889E:
	adds r6, r2, #1
	lsls r0, r6, #2
	mov r1, r8
	adds r5, r0, r1
	ldr r4, [r5]
	ldr r1, [r4]
	adds r1, #0x27
	lsls r0, r2, #2
	mov r3, r8
	adds r2, r0, r3
	ldr r3, [r2]
	ldr r0, [r3]
	adds r0, #0x27
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bls .L080788C8
	str r4, [r2]
	str r3, [r5]
	movs r4, #1
	mov sl, r4
.L080788C8:
	lsls r0, r6, #0x18
	lsrs r2, r0, #0x18
	mov r1, sb
	ldrb r1, [r1]
	subs r0, r1, r7
	cmp r2, r0
	blt .L0807889E
.L080788D6:
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L0807888A
	b .L08078F76
	.align 2, 0
.L080788E8: .4byte 0x0200CD38
.L080788EC: .4byte 0x0200CC38
.L080788F0:
	movs r4, #0
	mov sl, r4
	movs r1, #0
	ldr r7, .L08078968 @ =0x0200CD38
	mov ip, r7
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp sl, r0
	blt .L08078906
	b .L08078F76
.L08078906:
	adds r3, r2, #0
	mov sb, r3
.L0807890A:
	movs r2, #0
	adds r0, r1, #1
	mov r4, sb
	ldrb r4, [r4]
	subs r1, r4, r0
	adds r7, r0, #0
	cmp r2, r1
	bge .L08078956
	ldr r0, .L0807896C @ =0x0200CC38
	mov r8, r0
.L0807891E:
	adds r6, r2, #1
	lsls r0, r6, #2
	mov r1, r8
	adds r5, r0, r1
	ldr r4, [r5]
	ldr r1, [r4]
	adds r1, #0x27
	lsls r0, r2, #2
	mov r3, r8
	adds r2, r0, r3
	ldr r3, [r2]
	ldr r0, [r3]
	adds r0, #0x27
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bhs .L08078948
	str r4, [r2]
	str r3, [r5]
	movs r4, #1
	mov sl, r4
.L08078948:
	lsls r0, r6, #0x18
	lsrs r2, r0, #0x18
	mov r1, sb
	ldrb r1, [r1]
	subs r0, r1, r7
	cmp r2, r0
	blt .L0807891E
.L08078956:
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L0807890A
	b .L08078F76
	.align 2, 0
.L08078968: .4byte 0x0200CD38
.L0807896C: .4byte 0x0200CC38
.L08078970:
	cmp r2, #0
	bne .L080789F4
	movs r4, #0
	mov sl, r4
	movs r1, #0
	ldr r7, .L080789EC @ =0x0200CD38
	mov ip, r7
	mov r3, ip
	ldrb r0, [r3]
	subs r0, #1
	cmp r2, r0
	blt .L0807898A
	b .L08078F76
.L0807898A:
	adds r4, r3, #0
	mov sb, r4
.L0807898E:
	movs r2, #0
	adds r0, r1, #1
	mov r7, sb
	ldrb r7, [r7]
	subs r1, r7, r0
	adds r7, r0, #0
	cmp r2, r1
	bge .L080789DA
	ldr r0, .L080789F0 @ =0x0200CC38
	mov r8, r0
.L080789A2:
	adds r6, r2, #1
	lsls r0, r6, #2
	mov r1, r8
	adds r5, r0, r1
	ldr r4, [r5]
	ldr r1, [r4]
	adds r1, #0x28
	lsls r0, r2, #2
	mov r3, r8
	adds r2, r0, r3
	ldr r3, [r2]
	ldr r0, [r3]
	adds r0, #0x28
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bls .L080789CC
	str r4, [r2]
	str r3, [r5]
	movs r4, #1
	mov sl, r4
.L080789CC:
	lsls r0, r6, #0x18
	lsrs r2, r0, #0x18
	mov r1, sb
	ldrb r1, [r1]
	subs r0, r1, r7
	cmp r2, r0
	blt .L080789A2
.L080789DA:
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L0807898E
	b .L08078F76
	.align 2, 0
.L080789EC: .4byte 0x0200CD38
.L080789F0: .4byte 0x0200CC38
.L080789F4:
	movs r4, #0
	mov sl, r4
	movs r1, #0
	ldr r7, .L08078A6C @ =0x0200CD38
	mov ip, r7
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp sl, r0
	blt .L08078A0A
	b .L08078F76
.L08078A0A:
	adds r3, r2, #0
	mov sb, r3
.L08078A0E:
	movs r2, #0
	adds r0, r1, #1
	mov r4, sb
	ldrb r4, [r4]
	subs r1, r4, r0
	adds r7, r0, #0
	cmp r2, r1
	bge .L08078A5A
	ldr r0, .L08078A70 @ =0x0200CC38
	mov r8, r0
.L08078A22:
	adds r6, r2, #1
	lsls r0, r6, #2
	mov r1, r8
	adds r5, r0, r1
	ldr r4, [r5]
	ldr r1, [r4]
	adds r1, #0x28
	lsls r0, r2, #2
	mov r3, r8
	adds r2, r0, r3
	ldr r3, [r2]
	ldr r0, [r3]
	adds r0, #0x28
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bhs .L08078A4C
	str r4, [r2]
	str r3, [r5]
	movs r4, #1
	mov sl, r4
.L08078A4C:
	lsls r0, r6, #0x18
	lsrs r2, r0, #0x18
	mov r1, sb
	ldrb r1, [r1]
	subs r0, r1, r7
	cmp r2, r0
	blt .L08078A22
.L08078A5A:
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L08078A0E
	b .L08078F76
	.align 2, 0
.L08078A6C: .4byte 0x0200CD38
.L08078A70: .4byte 0x0200CC38
.L08078A74:
	cmp r2, #0
	bne .L08078AF8
	movs r4, #0
	mov sl, r4
	movs r1, #0
	ldr r7, .L08078AF0 @ =0x0200CD38
	mov ip, r7
	mov r3, ip
	ldrb r0, [r3]
	subs r0, #1
	cmp r2, r0
	blt .L08078A8E
	b .L08078F76
.L08078A8E:
	adds r4, r3, #0
	mov sb, r4
.L08078A92:
	movs r2, #0
	adds r0, r1, #1
	mov r7, sb
	ldrb r7, [r7]
	subs r1, r7, r0
	adds r7, r0, #0
	cmp r2, r1
	bge .L08078ADE
	ldr r0, .L08078AF4 @ =0x0200CC38
	mov r8, r0
.L08078AA6:
	adds r6, r2, #1
	lsls r0, r6, #2
	mov r1, r8
	adds r5, r0, r1
	ldr r4, [r5]
	ldr r1, [r4]
	adds r1, #0x29
	lsls r0, r2, #2
	mov r3, r8
	adds r2, r0, r3
	ldr r3, [r2]
	ldr r0, [r3]
	adds r0, #0x29
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bls .L08078AD0
	str r4, [r2]
	str r3, [r5]
	movs r4, #1
	mov sl, r4
.L08078AD0:
	lsls r0, r6, #0x18
	lsrs r2, r0, #0x18
	mov r1, sb
	ldrb r1, [r1]
	subs r0, r1, r7
	cmp r2, r0
	blt .L08078AA6
.L08078ADE:
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L08078A92
	b .L08078F76
	.align 2, 0
.L08078AF0: .4byte 0x0200CD38
.L08078AF4: .4byte 0x0200CC38
.L08078AF8:
	movs r4, #0
	mov sl, r4
	movs r1, #0
	ldr r7, .L08078B70 @ =0x0200CD38
	mov ip, r7
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp sl, r0
	blt .L08078B0E
	b .L08078F76
.L08078B0E:
	adds r3, r2, #0
	mov sb, r3
.L08078B12:
	movs r2, #0
	adds r0, r1, #1
	mov r4, sb
	ldrb r4, [r4]
	subs r1, r4, r0
	adds r7, r0, #0
	cmp r2, r1
	bge .L08078B5E
	ldr r0, .L08078B74 @ =0x0200CC38
	mov r8, r0
.L08078B26:
	adds r6, r2, #1
	lsls r0, r6, #2
	mov r1, r8
	adds r5, r0, r1
	ldr r4, [r5]
	ldr r1, [r4]
	adds r1, #0x29
	lsls r0, r2, #2
	mov r3, r8
	adds r2, r0, r3
	ldr r3, [r2]
	ldr r0, [r3]
	adds r0, #0x29
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bhs .L08078B50
	str r4, [r2]
	str r3, [r5]
	movs r4, #1
	mov sl, r4
.L08078B50:
	lsls r0, r6, #0x18
	lsrs r2, r0, #0x18
	mov r1, sb
	ldrb r1, [r1]
	subs r0, r1, r7
	cmp r2, r0
	blt .L08078B26
.L08078B5E:
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L08078B12
	b .L08078F76
	.align 2, 0
.L08078B70: .4byte 0x0200CD38
.L08078B74: .4byte 0x0200CC38
.L08078B78:
	cmp r2, #0
	bne .L08078BFC
	movs r4, #0
	mov sl, r4
	movs r1, #0
	ldr r7, .L08078BF4 @ =0x0200CD38
	mov ip, r7
	mov r3, ip
	ldrb r0, [r3]
	subs r0, #1
	cmp r2, r0
	blt .L08078B92
	b .L08078F76
.L08078B92:
	adds r4, r3, #0
	mov sb, r4
.L08078B96:
	movs r2, #0
	adds r0, r1, #1
	mov r7, sb
	ldrb r7, [r7]
	subs r1, r7, r0
	adds r7, r0, #0
	cmp r2, r1
	bge .L08078BE2
	ldr r0, .L08078BF8 @ =0x0200CC38
	mov r8, r0
.L08078BAA:
	adds r6, r2, #1
	lsls r0, r6, #2
	mov r1, r8
	adds r5, r0, r1
	ldr r4, [r5]
	ldr r1, [r4]
	adds r1, #0x2a
	lsls r0, r2, #2
	mov r3, r8
	adds r2, r0, r3
	ldr r3, [r2]
	ldr r0, [r3]
	adds r0, #0x2a
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bls .L08078BD4
	str r4, [r2]
	str r3, [r5]
	movs r4, #1
	mov sl, r4
.L08078BD4:
	lsls r0, r6, #0x18
	lsrs r2, r0, #0x18
	mov r1, sb
	ldrb r1, [r1]
	subs r0, r1, r7
	cmp r2, r0
	blt .L08078BAA
.L08078BE2:
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L08078B96
	b .L08078F76
	.align 2, 0
.L08078BF4: .4byte 0x0200CD38
.L08078BF8: .4byte 0x0200CC38
.L08078BFC:
	movs r4, #0
	mov sl, r4
	movs r1, #0
	ldr r7, .L08078C74 @ =0x0200CD38
	mov ip, r7
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp sl, r0
	blt .L08078C12
	b .L08078F76
.L08078C12:
	adds r3, r2, #0
	mov sb, r3
.L08078C16:
	movs r2, #0
	adds r0, r1, #1
	mov r4, sb
	ldrb r4, [r4]
	subs r1, r4, r0
	adds r7, r0, #0
	cmp r2, r1
	bge .L08078C62
	ldr r0, .L08078C78 @ =0x0200CC38
	mov r8, r0
.L08078C2A:
	adds r6, r2, #1
	lsls r0, r6, #2
	mov r1, r8
	adds r5, r0, r1
	ldr r4, [r5]
	ldr r1, [r4]
	adds r1, #0x2a
	lsls r0, r2, #2
	mov r3, r8
	adds r2, r0, r3
	ldr r3, [r2]
	ldr r0, [r3]
	adds r0, #0x2a
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bhs .L08078C54
	str r4, [r2]
	str r3, [r5]
	movs r4, #1
	mov sl, r4
.L08078C54:
	lsls r0, r6, #0x18
	lsrs r2, r0, #0x18
	mov r1, sb
	ldrb r1, [r1]
	subs r0, r1, r7
	cmp r2, r0
	blt .L08078C2A
.L08078C62:
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L08078C16
	b .L08078F76
	.align 2, 0
.L08078C74: .4byte 0x0200CD38
.L08078C78: .4byte 0x0200CC38
.L08078C7C:
	cmp r2, #0
	bne .L08078D00
	movs r4, #0
	mov sl, r4
	movs r1, #0
	ldr r7, .L08078CF8 @ =0x0200CD38
	mov ip, r7
	mov r3, ip
	ldrb r0, [r3]
	subs r0, #1
	cmp r2, r0
	blt .L08078C96
	b .L08078F76
.L08078C96:
	adds r4, r3, #0
	mov sb, r4
.L08078C9A:
	movs r2, #0
	adds r0, r1, #1
	mov r7, sb
	ldrb r7, [r7]
	subs r1, r7, r0
	adds r7, r0, #0
	cmp r2, r1
	bge .L08078CE6
	ldr r0, .L08078CFC @ =0x0200CC38
	mov r8, r0
.L08078CAE:
	adds r6, r2, #1
	lsls r0, r6, #2
	mov r1, r8
	adds r5, r0, r1
	ldr r4, [r5]
	ldr r1, [r4]
	adds r1, #0x2b
	lsls r0, r2, #2
	mov r3, r8
	adds r2, r0, r3
	ldr r3, [r2]
	ldr r0, [r3]
	adds r0, #0x2b
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bls .L08078CD8
	str r4, [r2]
	str r3, [r5]
	movs r4, #1
	mov sl, r4
.L08078CD8:
	lsls r0, r6, #0x18
	lsrs r2, r0, #0x18
	mov r1, sb
	ldrb r1, [r1]
	subs r0, r1, r7
	cmp r2, r0
	blt .L08078CAE
.L08078CE6:
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L08078C9A
	b .L08078F76
	.align 2, 0
.L08078CF8: .4byte 0x0200CD38
.L08078CFC: .4byte 0x0200CC38
.L08078D00:
	movs r4, #0
	mov sl, r4
	movs r1, #0
	ldr r7, .L08078D78 @ =0x0200CD38
	mov ip, r7
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp sl, r0
	blt .L08078D16
	b .L08078F76
.L08078D16:
	adds r3, r2, #0
	mov sb, r3
.L08078D1A:
	movs r2, #0
	adds r0, r1, #1
	mov r4, sb
	ldrb r4, [r4]
	subs r1, r4, r0
	adds r7, r0, #0
	cmp r2, r1
	bge .L08078D66
	ldr r0, .L08078D7C @ =0x0200CC38
	mov r8, r0
.L08078D2E:
	adds r6, r2, #1
	lsls r0, r6, #2
	mov r1, r8
	adds r5, r0, r1
	ldr r4, [r5]
	ldr r1, [r4]
	adds r1, #0x2b
	lsls r0, r2, #2
	mov r3, r8
	adds r2, r0, r3
	ldr r3, [r2]
	ldr r0, [r3]
	adds r0, #0x2b
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bhs .L08078D58
	str r4, [r2]
	str r3, [r5]
	movs r4, #1
	mov sl, r4
.L08078D58:
	lsls r0, r6, #0x18
	lsrs r2, r0, #0x18
	mov r1, sb
	ldrb r1, [r1]
	subs r0, r1, r7
	cmp r2, r0
	blt .L08078D2E
.L08078D66:
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L08078D1A
	b .L08078F76
	.align 2, 0
.L08078D78: .4byte 0x0200CD38
.L08078D7C: .4byte 0x0200CC38
.L08078D80:
	cmp r2, #0
	bne .L08078E04
	movs r4, #0
	mov sl, r4
	movs r1, #0
	ldr r7, .L08078DFC @ =0x0200CD38
	mov ip, r7
	mov r3, ip
	ldrb r0, [r3]
	subs r0, #1
	cmp r2, r0
	blt .L08078D9A
	b .L08078F76
.L08078D9A:
	adds r4, r3, #0
	mov sb, r4
.L08078D9E:
	movs r2, #0
	adds r0, r1, #1
	mov r7, sb
	ldrb r7, [r7]
	subs r1, r7, r0
	adds r7, r0, #0
	cmp r2, r1
	bge .L08078DEA
	ldr r0, .L08078E00 @ =0x0200CC38
	mov r8, r0
.L08078DB2:
	adds r6, r2, #1
	lsls r0, r6, #2
	mov r1, r8
	adds r5, r0, r1
	ldr r4, [r5]
	ldr r1, [r4]
	adds r1, #0x2c
	lsls r0, r2, #2
	mov r3, r8
	adds r2, r0, r3
	ldr r3, [r2]
	ldr r0, [r3]
	adds r0, #0x2c
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bls .L08078DDC
	str r4, [r2]
	str r3, [r5]
	movs r4, #1
	mov sl, r4
.L08078DDC:
	lsls r0, r6, #0x18
	lsrs r2, r0, #0x18
	mov r1, sb
	ldrb r1, [r1]
	subs r0, r1, r7
	cmp r2, r0
	blt .L08078DB2
.L08078DEA:
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L08078D9E
	b .L08078F76
	.align 2, 0
.L08078DFC: .4byte 0x0200CD38
.L08078E00: .4byte 0x0200CC38
.L08078E04:
	movs r4, #0
	mov sl, r4
	movs r1, #0
	ldr r7, .L08078E7C @ =0x0200CD38
	mov ip, r7
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp sl, r0
	blt .L08078E1A
	b .L08078F76
.L08078E1A:
	adds r3, r2, #0
	mov sb, r3
.L08078E1E:
	movs r2, #0
	adds r0, r1, #1
	mov r4, sb
	ldrb r4, [r4]
	subs r1, r4, r0
	adds r7, r0, #0
	cmp r2, r1
	bge .L08078E6A
	ldr r0, .L08078E80 @ =0x0200CC38
	mov r8, r0
.L08078E32:
	adds r6, r2, #1
	lsls r0, r6, #2
	mov r1, r8
	adds r5, r0, r1
	ldr r4, [r5]
	ldr r1, [r4]
	adds r1, #0x2c
	lsls r0, r2, #2
	mov r3, r8
	adds r2, r0, r3
	ldr r3, [r2]
	ldr r0, [r3]
	adds r0, #0x2c
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bhs .L08078E5C
	str r4, [r2]
	str r3, [r5]
	movs r4, #1
	mov sl, r4
.L08078E5C:
	lsls r0, r6, #0x18
	lsrs r2, r0, #0x18
	mov r1, sb
	ldrb r1, [r1]
	subs r0, r1, r7
	cmp r2, r0
	blt .L08078E32
.L08078E6A:
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L08078E1E
	b .L08078F76
	.align 2, 0
.L08078E7C: .4byte 0x0200CD38
.L08078E80: .4byte 0x0200CC38
.L08078E84:
	cmp r2, #0
	bne .L08078F04
	movs r4, #0
	mov sl, r4
	movs r1, #0
	ldr r7, .L08078EFC @ =0x0200CD38
	mov ip, r7
	mov r3, ip
	ldrb r0, [r3]
	subs r0, #1
	cmp r2, r0
	bge .L08078F76
	adds r4, r3, #0
	mov sb, r4
.L08078EA0:
	movs r2, #0
	adds r0, r1, #1
	mov r7, sb
	ldrb r7, [r7]
	subs r1, r7, r0
	adds r7, r0, #0
	cmp r2, r1
	bge .L08078EEC
	ldr r0, .L08078F00 @ =0x0200CC38
	mov r8, r0
.L08078EB4:
	adds r6, r2, #1
	lsls r0, r6, #2
	mov r1, r8
	adds r5, r0, r1
	ldr r4, [r5]
	ldr r1, [r4]
	adds r1, #0x2d
	lsls r0, r2, #2
	mov r3, r8
	adds r2, r0, r3
	ldr r3, [r2]
	ldr r0, [r3]
	adds r0, #0x2d
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bls .L08078EDE
	str r4, [r2]
	str r3, [r5]
	movs r4, #1
	mov sl, r4
.L08078EDE:
	lsls r0, r6, #0x18
	lsrs r2, r0, #0x18
	mov r1, sb
	ldrb r1, [r1]
	subs r0, r1, r7
	cmp r2, r0
	blt .L08078EB4
.L08078EEC:
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L08078EA0
	b .L08078F76
	.align 2, 0
.L08078EFC: .4byte 0x0200CD38
.L08078F00: .4byte 0x0200CC38
.L08078F04:
	movs r4, #0
	mov sl, r4
	movs r1, #0
	ldr r7, .L08078F84 @ =0x0200CD38
	mov ip, r7
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp sl, r0
	bge .L08078F76
	adds r3, r2, #0
	mov sb, r3
.L08078F1C:
	movs r2, #0
	adds r0, r1, #1
	mov r4, sb
	ldrb r4, [r4]
	subs r1, r4, r0
	adds r7, r0, #0
	cmp r2, r1
	bge .L08078F68
	ldr r0, .L08078F88 @ =0x0200CC38
	mov r8, r0
.L08078F30:
	adds r6, r2, #1
	lsls r0, r6, #2
	mov r1, r8
	adds r5, r0, r1
	ldr r4, [r5]
	ldr r1, [r4]
	adds r1, #0x2d
	lsls r0, r2, #2
	mov r3, r8
	adds r2, r0, r3
	ldr r3, [r2]
	ldr r0, [r3]
	adds r0, #0x2d
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bhs .L08078F5A
	str r4, [r2]
	str r3, [r5]
	movs r4, #1
	mov sl, r4
.L08078F5A:
	lsls r0, r6, #0x18
	lsrs r2, r0, #0x18
	mov r1, sb
	ldrb r1, [r1]
	subs r0, r1, r7
	cmp r2, r0
	blt .L08078F30
.L08078F68:
	lsls r0, r7, #0x18
	lsrs r1, r0, #0x18
	mov r2, ip
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L08078F1C
.L08078F76:
	mov r3, sl
.L08078F78:
	cmp r3, #0
	bne .L08078F7E
	b .L0807918C
.L08078F7E:
	movs r0, #1
	b .L0807918E
	.align 2, 0
.L08078F84: .4byte 0x0200CD38
.L08078F88: .4byte 0x0200CC38
.L08078F8C:
	cmp r2, #0
	bne .L08079004
	movs r4, #0
	mov sl, r4
	movs r1, #0
	ldr r7, .L08078FFC @ =0x0200CD38
	mov ip, r7
	mov r3, ip
	ldrb r0, [r3]
	subs r0, #1
	cmp r2, r0
	bge .L0807906C
	adds r4, r3, #0
	mov sb, r4
.L08078FA8:
	movs r4, #0
	adds r0, r1, #1
	mov r7, sb
	ldrb r7, [r7]
	subs r1, r7, r0
	mov r8, r0
	cmp r4, r1
	bge .L08078FEA
	ldr r6, .L08079000 @ =0x0200CC38
	str r0, [sp, #0x60]
.L08078FBC:
	adds r5, r4, #1
	lsls r0, r5, #2
	adds r3, r0, r6
	ldr r2, [r3]
	lsls r0, r4, #2
	adds r0, r0, r6
	ldr r1, [r0]
	ldrb r4, [r2, #0xa]
	ldrb r7, [r1, #0xa]
	cmp r4, r7
	bls .L08078FDA
	str r2, [r0]
	str r1, [r3]
	movs r0, #1
	mov sl, r0
.L08078FDA:
	lsls r0, r5, #0x18
	lsrs r4, r0, #0x18
	mov r1, sb
	ldrb r1, [r1]
	ldr r2, [sp, #0x60]
	subs r0, r1, r2
	cmp r4, r0
	blt .L08078FBC
.L08078FEA:
	mov r3, r8
	lsls r0, r3, #0x18
	lsrs r1, r0, #0x18
	mov r4, ip
	ldrb r0, [r4]
	subs r0, #1
	cmp r1, r0
	blt .L08078FA8
	b .L0807906C
	.align 2, 0
.L08078FFC: .4byte 0x0200CD38
.L08079000: .4byte 0x0200CC38
.L08079004:
	movs r0, #0
	mov sl, r0
	movs r1, #0
	ldr r2, .L08079078 @ =0x0200CD38
	mov ip, r2
	ldrb r0, [r2]
	subs r0, #1
	cmp sl, r0
	bge .L0807906C
	adds r3, r2, #0
	mov sb, r3
.L0807901A:
	movs r4, #0
	adds r0, r1, #1
	mov r7, sb
	ldrb r7, [r7]
	subs r1, r7, r0
	mov r8, r0
	cmp r4, r1
	bge .L0807905C
	ldr r6, .L0807907C @ =0x0200CC38
	str r0, [sp, #0x60]
.L0807902E:
	adds r5, r4, #1
	lsls r0, r5, #2
	adds r3, r0, r6
	ldr r2, [r3]
	lsls r0, r4, #2
	adds r0, r0, r6
	ldr r1, [r0]
	ldrb r4, [r2, #0xa]
	ldrb r7, [r1, #0xa]
	cmp r4, r7
	bhs .L0807904C
	str r2, [r0]
	str r1, [r3]
	movs r0, #1
	mov sl, r0
.L0807904C:
	lsls r0, r5, #0x18
	lsrs r4, r0, #0x18
	mov r1, sb
	ldrb r1, [r1]
	ldr r2, [sp, #0x60]
	subs r0, r1, r2
	cmp r4, r0
	blt .L0807902E
.L0807905C:
	mov r3, r8
	lsls r0, r3, #0x18
	lsrs r1, r0, #0x18
	mov r4, ip
	ldrb r0, [r4]
	subs r0, #1
	cmp r1, r0
	blt .L0807901A
.L0807906C:
	mov r7, sl
.L0807906E:
	cmp r7, #0
	bne .L08079074
	b .L0807918C
.L08079074:
	movs r0, #1
	b .L0807918E
	.align 2, 0
.L08079078: .4byte 0x0200CD38
.L0807907C: .4byte 0x0200CC38
.L08079080:
	cmp r2, #0
	bne .L08079108
	movs r0, #0
	mov sl, r0
	movs r1, #0
	ldr r2, .L08079100 @ =0x0200CD38
	ldrb r0, [r2]
	subs r0, #1
	cmp sl, r0
	bge .L080790F6
.L08079094:
	movs r5, #0
	adds r0, r1, #1
	ldrb r2, [r2]
	subs r1, r2, r0
	mov r8, r0
	cmp r5, r1
	bge .L080790E6
	ldr r1, .L08079104 @ =0x0200CC38
	mov sb, r1
.L080790A6:
	adds r7, r5, #1
	lsls r0, r7, #2
	mov r2, sb
	adds r6, r0, r2
	ldr r0, [r6]
	ldr r0, [r0]
	bl func_fe6_08076D30
	adds r4, r0, #0
	lsls r0, r5, #2
	mov r3, sb
	adds r5, r0, r3
	ldr r0, [r5]
	ldr r0, [r0]
	bl func_fe6_08076D30
	cmp r4, r0
	ble .L080790D6
	ldr r1, [r5]
	ldr r0, [r6]
	str r0, [r5]
	str r1, [r6]
	movs r4, #1
	mov sl, r4
.L080790D6:
	lsls r0, r7, #0x18
	lsrs r5, r0, #0x18
	ldr r0, .L08079100 @ =0x0200CD38
	ldrb r0, [r0]
	mov r7, r8
	subs r0, r0, r7
	cmp r5, r0
	blt .L080790A6
.L080790E6:
	mov r1, r8
	lsls r0, r1, #0x18
	lsrs r1, r0, #0x18
	ldr r2, .L08079100 @ =0x0200CD38
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	blt .L08079094
.L080790F6:
	mov r2, sl
	cmp r2, #0
	beq .L0807918C
	movs r0, #1
	b .L0807918E
	.align 2, 0
.L08079100: .4byte 0x0200CD38
.L08079104: .4byte 0x0200CC38
.L08079108:
	movs r3, #0
	mov sl, r3
	movs r2, #0
	ldr r1, .L08079184 @ =0x0200CD38
	ldrb r0, [r1]
	subs r0, #1
	cmp sl, r0
	bge .L0807917A
.L08079118:
	movs r5, #0
	adds r0, r2, #1
	ldrb r1, [r1]
	subs r1, r1, r0
	mov r8, r0
	cmp r5, r1
	bge .L0807916A
	ldr r4, .L08079188 @ =0x0200CC38
	mov sb, r4
.L0807912A:
	adds r7, r5, #1
	lsls r0, r7, #2
	mov r1, sb
	adds r6, r0, r1
	ldr r0, [r6]
	ldr r0, [r0]
	bl func_fe6_08076D30
	adds r4, r0, #0
	lsls r0, r5, #2
	mov r2, sb
	adds r5, r0, r2
	ldr r0, [r5]
	ldr r0, [r0]
	bl func_fe6_08076D30
	cmp r4, r0
	bge .L0807915A
	ldr r1, [r5]
	ldr r0, [r6]
	str r0, [r5]
	str r1, [r6]
	movs r3, #1
	mov sl, r3
.L0807915A:
	lsls r0, r7, #0x18
	lsrs r5, r0, #0x18
	ldr r0, .L08079184 @ =0x0200CD38
	ldrb r0, [r0]
	mov r4, r8
	subs r0, r0, r4
	cmp r5, r0
	blt .L0807912A
.L0807916A:
	mov r7, r8
	lsls r0, r7, #0x18
	lsrs r2, r0, #0x18
	ldr r1, .L08079184 @ =0x0200CD38
	ldrb r0, [r1]
	subs r0, #1
	cmp r2, r0
	blt .L08079118
.L0807917A:
	mov r0, sl
.L0807917C:
	cmp r0, #0
	beq .L0807918C
	movs r0, #1
	b .L0807918E
	.align 2, 0
.L08079184: .4byte 0x0200CD38
.L08079188: .4byte 0x0200CC38
.L0807918C:
	movs r0, #0
.L0807918E:
	add sp, #0x64
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_080791A0
func_fe6_080791A0: @ 0x080791A0
	ldr r1, .L080791B0 @ =0x0203D494
	movs r2, #0
	adds r0, r1, #4
.L080791A6:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge .L080791A6
	bx lr
	.align 2, 0
.L080791B0: .4byte 0x0203D494

	thumb_func_start func_fe6_080791B4
func_fe6_080791B4: @ 0x080791B4
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	movs r2, #0
	ldr r4, .L080791CC @ =0x0203D494
.L080791BE:
	adds r1, r2, r4
	ldrb r0, [r1]
	cmp r0, #0
	bne .L080791D0
	strb r3, [r1]
	b .L080791D6
	.align 2, 0
.L080791CC: .4byte 0x0203D494
.L080791D0:
	adds r2, #1
	cmp r2, #4
	ble .L080791BE
.L080791D6:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080791DC
func_fe6_080791DC: @ 0x080791DC
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	movs r1, #0
	ldr r3, .L0807920C @ =0x0203D494
	adds r4, r3, #0
.L080791E8:
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, r2
	bne .L08079210
	adds r2, r1, #0
	cmp r1, #3
	bgt .L08079204
	adds r1, r1, r4
.L080791F8:
	ldrb r0, [r1, #1]
	strb r0, [r1]
	adds r1, #1
	adds r2, #1
	cmp r2, #3
	ble .L080791F8
.L08079204:
	movs r0, #0
	strb r0, [r3, #4]
	b .L08079216
	.align 2, 0
.L0807920C: .4byte 0x0203D494
.L08079210:
	adds r1, #1
	cmp r1, #4
	ble .L080791E8
.L08079216:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0807921C
func_fe6_0807921C: @ 0x0807921C
	push {r4, lr}
	movs r4, #1
.L08079220:
	adds r0, r4, #0
	bl GetUnit
	adds r1, r0, #0
	cmp r1, #0
	beq .L08079242
	ldr r0, [r1]
	cmp r0, #0
	beq .L08079242
	ldrh r2, [r1, #0xc]
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq .L08079242
	movs r0, #4
	orrs r0, r2
	strh r0, [r1, #0xc]
.L08079242:
	adds r4, #1
	cmp r4, #0x3f
	ble .L08079220
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08079250
func_fe6_08079250: @ 0x08079250
	push {r4, r5, r6, lr}
	movs r1, #0
	strh r1, [r0, #0x30]
	ldr r0, .L080792C4 @ =gDispIo
	mov ip, r0
	movs r0, #0x20
	mov r1, ip
	ldrb r1, [r1, #1]
	orrs r0, r1
	movs r1, #0x40
	orrs r0, r1
	movs r1, #0x7f
	ands r0, r1
	mov r2, ip
	strb r0, [r2, #1]
	mov r5, ip
	adds r5, #0x34
	subs r1, #0x81
	adds r0, r1, #0
	ldrb r2, [r5]
	ands r0, r2
	movs r6, #3
	rsbs r6, r6, #0
	ands r0, r6
	movs r4, #5
	rsbs r4, r4, #0
	ands r0, r4
	movs r2, #8
	orrs r0, r2
	movs r3, #0x11
	rsbs r3, r3, #0
	ands r0, r3
	strb r0, [r5]
	mov r0, ip
	adds r0, #0x35
	ldrb r5, [r0]
	ands r1, r5
	ands r1, r6
	ands r1, r4
	orrs r1, r2
	ands r1, r3
	strb r1, [r0]
	mov r3, ip
	adds r3, #0x36
	movs r0, #1
	ldrb r1, [r3]
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	orrs r0, r2
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r3]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080792C4: .4byte gDispIo

	thumb_func_start func_fe6_080792C8
func_fe6_080792C8: @ 0x080792C8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrh r0, [r6, #0x30]
	adds r0, #8
	strh r0, [r6, #0x30]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bls .L080792DE
	movs r0, #0x40
	strh r0, [r6, #0x30]
.L080792DE:
	ldr r0, .L08079340 @ =gDispIo
	mov ip, r0
	adds r0, #0x2d
	movs r4, #0x68
	strb r4, [r0]
	mov r1, ip
	adds r1, #0x31
	movs r0, #0x20
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x2c
	movs r5, #0xf0
	strb r5, [r0]
	ldrh r2, [r6, #0x30]
	adds r3, r2, #0
	adds r1, r3, #0
	adds r1, #0x20
	adds r0, #4
	strb r1, [r0]
	subs r0, #1
	strb r4, [r0]
	movs r0, #0xa0
	subs r0, r0, r3
	mov r1, ip
	adds r1, #0x33
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x2e
	strb r5, [r0]
	subs r1, #1
	movs r0, #0xa0
	strb r0, [r1]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	cmp r2, #0x40
	bne .L0807937C
	adds r0, r6, #0
	bl Proc_Break
	movs r0, #0
	strh r0, [r6, #0x30]
	ldr r0, [r6, #0x14]
	adds r1, r0, #0
	adds r1, #0x2a
	ldrb r0, [r1]
	cmp r0, #0
	bne .L08079344
	movs r0, #1
	b .L08079346
	.align 2, 0
.L08079340: .4byte gDispIo
.L08079344:
	movs r0, #0
.L08079346:
	strb r0, [r1]
	ldr r0, [r6, #0x14]
	bl func_fe6_0807A67C
	ldr r2, .L08079384 @ =gDispIo
	movs r0, #0x20
	ldrb r1, [r2, #1]
	orrs r0, r1
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r2, #1]
	adds r1, r2, #0
	adds r1, #0x2d
	movs r0, #0x68
	strb r0, [r1]
	adds r1, #4
	movs r0, #0x20
	strb r0, [r1]
	subs r1, #5
	movs r0, #0xf0
	strb r0, [r1]
	adds r1, #4
	movs r0, #0xa0
	strb r0, [r1]
.L0807937C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08079384: .4byte gDispIo

	thumb_func_start func_fe6_08079388
func_fe6_08079388: @ 0x08079388
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrh r0, [r5, #0x30]
	adds r0, #8
	strh r0, [r5, #0x30]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bls .L0807939E
	movs r0, #0x40
	strh r0, [r5, #0x30]
.L0807939E:
	ldr r4, .L080793EC @ =gDispIo
	adds r1, r4, #0
	adds r1, #0x2d
	movs r0, #0x68
	strb r0, [r1]
	ldrh r2, [r5, #0x30]
	adds r3, r2, #0
	adds r0, r3, #0
	adds r0, #0x20
	adds r1, #4
	strb r0, [r1]
	subs r1, #5
	movs r0, #0xf0
	strb r0, [r1]
	movs r0, #0xa0
	subs r0, r0, r3
	adds r1, #4
	strb r0, [r1]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	cmp r2, #0x40
	bne .L080793E4
	adds r0, r5, #0
	bl Proc_Break
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrb r1, [r4, #1]
	ands r0, r1
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r4, #1]
.L080793E4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080793EC: .4byte gDispIo

	thumb_func_start func_fe6_080793F0
func_fe6_080793F0: @ 0x080793F0
	push {lr}
	adds r1, r0, #0
	ldr r0, .L08079400 @ =gUnk_08678DE0
	bl SpawnProc
	pop {r0}
	bx r0
	.align 2, 0
.L08079400: .4byte gUnk_08678DE0

	thumb_func_start func_fe6_08079404
func_fe6_08079404: @ 0x08079404
	ldr r0, [r0]
	ldrb r1, [r0, #4]
	cmp r1, #1
	beq .L08079418
	ldr r0, .L0807941C @ =gPlaySt
	ldrb r0, [r0, #0xe]
	cmp r0, #0x18
	bne .L08079420
	cmp r1, #3
	bne .L08079420
.L08079418:
	movs r0, #1
	b .L08079422
	.align 2, 0
.L0807941C: .4byte gPlaySt
.L08079420:
	movs r0, #0
.L08079422:
	bx lr

	thumb_func_start func_fe6_08079424
func_fe6_08079424: @ 0x08079424
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, .L0807957C @ =func_fe6_0807C5B8
	ldr r2, .L08079580 @ =0x000006AE
	ldr r1, .L08079584 @ =0x00000659
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r3, #0
	bl func_fe6_0807CC34
	ldr r0, .L08079588 @ =func_fe6_0807C7B8
	ldr r2, .L0807958C @ =0x000006AF
	ldr r1, .L08079590 @ =0x0000065A
	str r1, [sp]
	movs r5, #1
	str r5, [sp, #4]
	movs r1, #0
	movs r3, #0
	bl func_fe6_0807CC34
	bl func_fe6_0808D0F8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq .L0807948A
	adds r1, r4, #0
	adds r1, #0x2c
	adds r0, r5, #0
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne .L0807948A
	ldr r1, .L08079594 @ =gPlaySt
	movs r0, #0x20
	ldrb r1, [r1, #0x14]
	ands r0, r1
	cmp r0, #0
	bne .L0807948A
	ldr r0, .L08079598 @ =func_fe6_0807CB08
	ldr r2, .L0807959C @ =0x000006B7
	ldr r1, .L080795A0 @ =0x000006A3
	str r1, [sp]
	movs r1, #0xa
	str r1, [sp, #4]
	movs r1, #0
	movs r3, #0
	bl func_fe6_0807CC34
.L0807948A:
	ldr r1, .L080795A4 @ =func_fe6_0807C884
	movs r3, #0
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #1
	bne .L0807949A
	movs r3, #1
.L0807949A:
	ldr r0, .L080795A8 @ =0x0000065F
	str r0, [sp]
	movs r0, #5
	str r0, [sp, #4]
	adds r0, r1, #0
	movs r1, #1
	ldr r2, .L080795AC @ =0x000006B3
	bl func_fe6_0807CC34
	adds r1, r4, #0
	adds r1, #0x2c
	movs r0, #1
	ldrb r2, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	bne .L08079506
	ldr r1, .L08079594 @ =gPlaySt
	movs r0, #0x20
	ldrb r1, [r1, #0x14]
	ands r0, r1
	cmp r0, #0
	bne .L080794DC
	ldr r0, .L080795B0 @ =func_fe6_0807CB78
	ldr r2, .L080795B4 @ =0x000006B1
	ldr r1, .L080795B8 @ =0x0000065C
	str r1, [sp]
	movs r1, #3
	str r1, [sp, #4]
	movs r1, #0
	movs r3, #0
	bl func_fe6_0807CC34
.L080794DC:
	ldr r0, .L080795BC @ =func_fe6_0807CBB0
	ldr r2, .L080795C0 @ =0x000006B2
	ldr r1, .L080795C4 @ =0x0000065D
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	movs r1, #0
	movs r3, #0
	bl func_fe6_0807CC34
	ldr r0, .L080795C8 @ =func_fe6_0807C97C
	ldr r2, .L080795CC @ =0x000006B4
	movs r1, #0xcc
	lsls r1, r1, #3
	str r1, [sp]
	movs r1, #6
	str r1, [sp, #4]
	movs r1, #1
	movs r3, #0
	bl func_fe6_0807CC34
.L08079506:
	ldr r0, .L080795D0 @ =func_fe6_0807C9F4
	ldr r2, .L080795D4 @ =0x000006B5
	ldr r1, .L080795D8 @ =0x00000661
	str r1, [sp]
	movs r1, #7
	str r1, [sp, #4]
	movs r1, #1
	movs r3, #0
	bl func_fe6_0807CC34
	ldr r0, .L080795DC @ =func_fe6_0807CA48
	ldr r2, .L080795E0 @ =0x000006B6
	ldr r1, .L080795E4 @ =0x00000662
	str r1, [sp]
	movs r1, #8
	str r1, [sp, #4]
	movs r1, #1
	movs r3, #0
	bl func_fe6_0807CC34
	movs r4, #1
	adds r0, r4, #0
	ldrb r1, [r5]
	ands r0, r1
	cmp r0, #0
	bne .L08079564
	ldr r1, .L08079594 @ =gPlaySt
	movs r0, #0x60
	ldrb r1, [r1, #0x14]
	ands r0, r1
	cmp r0, #0
	bne .L0807955A
	ldr r0, .L080795E8 @ =func_fe6_0807CA9C
	ldr r2, .L080795EC @ =0x000006B9
	ldr r1, .L080795F0 @ =0x00000663
	str r1, [sp]
	movs r1, #9
	str r1, [sp, #4]
	movs r1, #1
	movs r3, #0
	bl func_fe6_0807CC34
.L0807955A:
	adds r0, r4, #0
	ldrb r5, [r5]
	ands r0, r5
	cmp r0, #0
	beq .L080795FC
.L08079564:
	ldr r0, .L080795F4 @ =func_fe6_0807CBDC
	movs r2, #0xd6
	lsls r2, r2, #3
	ldr r1, .L080795F8 @ =0x000006F1
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r3, #0
	bl func_fe6_0807CC34
	b .L08079610
	.align 2, 0
.L0807957C: .4byte func_fe6_0807C5B8
.L08079580: .4byte 0x000006AE
.L08079584: .4byte 0x00000659
.L08079588: .4byte func_fe6_0807C7B8
.L0807958C: .4byte 0x000006AF
.L08079590: .4byte 0x0000065A
.L08079594: .4byte gPlaySt
.L08079598: .4byte func_fe6_0807CB08
.L0807959C: .4byte 0x000006B7
.L080795A0: .4byte 0x000006A3
.L080795A4: .4byte func_fe6_0807C884
.L080795A8: .4byte 0x0000065F
.L080795AC: .4byte 0x000006B3
.L080795B0: .4byte func_fe6_0807CB78
.L080795B4: .4byte 0x000006B1
.L080795B8: .4byte 0x0000065C
.L080795BC: .4byte func_fe6_0807CBB0
.L080795C0: .4byte 0x000006B2
.L080795C4: .4byte 0x0000065D
.L080795C8: .4byte func_fe6_0807C97C
.L080795CC: .4byte 0x000006B4
.L080795D0: .4byte func_fe6_0807C9F4
.L080795D4: .4byte 0x000006B5
.L080795D8: .4byte 0x00000661
.L080795DC: .4byte func_fe6_0807CA48
.L080795E0: .4byte 0x000006B6
.L080795E4: .4byte 0x00000662
.L080795E8: .4byte func_fe6_0807CA9C
.L080795EC: .4byte 0x000006B9
.L080795F0: .4byte 0x00000663
.L080795F4: .4byte func_fe6_0807CBDC
.L080795F8: .4byte 0x000006F1
.L080795FC:
	ldr r0, .L08079618 @ =func_fe6_0807CBDC
	ldr r2, .L0807961C @ =0x000006BA
	ldr r1, .L08079620 @ =0x0000065E
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0
	movs r3, #0
	bl func_fe6_0807CC34
.L08079610:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08079618: .4byte func_fe6_0807CBDC
.L0807961C: .4byte 0x000006BA
.L08079620: .4byte 0x0000065E

	thumb_func_start func_fe6_08079624
func_fe6_08079624: @ 0x08079624
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r7, r1, #0
	adds r0, r7, #0
	adds r0, #0x50
	movs r2, #8
	ldrsb r2, [r5, r2]
	movs r1, #2
	bl PutNumberOrBlank
	adds r0, r7, #0
	adds r0, #0x56
	ldrb r2, [r5, #9]
	movs r1, #2
	bl PutNumberOrBlank
	adds r4, r7, #0
	adds r4, #0xd6
	adds r0, r5, #0
	bl GetUnitCurrentHp
	adds r2, r0, #0
	adds r0, r4, #0
	movs r1, #2
	bl PutNumberOrBlank
	subs r4, #6
	adds r0, r5, #0
	bl GetUnitMaxHp
	adds r2, r0, #0
	adds r0, r4, #0
	movs r1, #2
	bl PutNumberOrBlank
	ldr r0, [r5]
	ldrh r0, [r0]
	bl DecodeMsg
	bl GetStringTextLen
	movs r4, #0x38
	subs r4, r4, r0
	asrs r4, r4, #1
	ldr r6, .L080796AC @ =0x0200E89C
	adds r0, r6, #0
	bl ClearText
	ldr r0, [r5]
	ldrh r0, [r0]
	bl DecodeMsg
	movs r2, #0xa3
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r2, #0
	str r2, [sp]
	str r0, [sp, #4]
	adds r0, r6, #0
	adds r3, r4, #0
	bl PutDrawText
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080796AC: .4byte 0x0200E89C

	thumb_func_start func_fe6_080796B0
func_fe6_080796B0: @ 0x080796B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sb, r0
	ldr r0, .L0807978C @ =gUnk_08320FCE
	mov r8, r0
	ldr r4, .L08079790 @ =0x0200E8A4
	adds r0, r4, #0
	movs r1, #0x1d
	movs r2, #0x1d
	movs r3, #0
	bl TmFillRect_thm
	movs r1, #0
	ldr r2, .L08079794 @ =0x0200E89C
	mov sl, r2
	mov ip, r4
	movs r6, #0x1a
	movs r3, #0x80
	lsls r3, r3, #5
	adds r4, r3, #0
.L080796E0:
	adds r0, r1, #0
	adds r0, #0xa
	adds r5, r1, #1
	movs r7, #7
	subs r1, r7, r1
	muls r1, r6, r1
	add r1, r8
	lsls r0, r0, #6
	mov r3, ip
	adds r2, r0, r3
	movs r3, #0xc
.L080796F6:
	ldrh r7, [r1]
	adds r0, r4, r7
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge .L080796F6
	adds r1, r5, #0
	cmp r1, #7
	ble .L080796E0
	movs r4, #0
	mov r0, sl
	bl ClearText
	ldr r5, .L08079798 @ =0x0200E976
	adds r0, r5, #0
	movs r1, #3
	movs r2, #0x16
	bl PutSpecialChar
	adds r0, r5, #0
	subs r0, #8
	movs r1, #3
	movs r2, #0x22
	bl PutSpecialChar
	subs r0, r5, #6
	movs r1, #3
	movs r2, #0x23
	bl PutSpecialChar
	adds r0, r5, #0
	subs r0, #0x88
	movs r1, #3
	movs r2, #0x24
	bl PutSpecialChar
	adds r0, r5, #0
	subs r0, #0x86
	movs r1, #3
	movs r2, #0x25
	bl PutSpecialChar
	adds r0, r5, #0
	subs r0, #0x80
	movs r1, #3
	movs r2, #0x1f
	bl PutSpecialChar
	adds r1, r5, #0
	subs r1, #0xd2
	mov r0, sb
	bl func_fe6_08079624
	mov r0, sb
	bl GetUnitFid
	adds r1, r5, #0
	subs r1, #0x90
	movs r2, #0x8c
	lsls r2, r2, #2
	str r4, [sp]
	movs r3, #2
	bl PutFaceChibi
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0807978C: .4byte gUnk_08320FCE
.L08079790: .4byte 0x0200E8A4
.L08079794: .4byte 0x0200E89C
.L08079798: .4byte 0x0200E976

	thumb_func_start func_fe6_0807979C
func_fe6_0807979C: @ 0x0807979C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, [r5, #0x48]
	ldr r4, .L080797D8 @ =gBg0Tm+0x4E
	adds r0, r4, #0
	movs r1, #1
	movs r2, #3
	movs r3, #0
	bl TmFillRect_thm
	adds r0, r4, #6
	movs r1, #1
	movs r2, #3
	movs r3, #0
	bl TmFillRect_thm
	subs r4, #0x4e
	adds r0, r6, #0
	adds r1, r4, #0
	bl func_fe6_08079624
	movs r0, #1
	bl EnableBgSync
	adds r0, r5, #0
	bl Proc_Break
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080797D8: .4byte gBg0Tm+0x4E

	thumb_func_start func_fe6_080797DC
func_fe6_080797DC: @ 0x080797DC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080797FC @ =gUnk_08678E00
	adds r1, r4, #0
	bl SpawnProc
	ldr r2, .L08079800 @ =0x0200E6D4
	adds r4, #0x30
	ldrb r4, [r4]
	lsls r1, r4, #2
	adds r1, r1, r2
	ldr r1, [r1]
	str r1, [r0, #0x48]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080797FC: .4byte gUnk_08678E00
.L08079800: .4byte 0x0200E6D4

	thumb_func_start func_fe6_08079804
func_fe6_08079804: @ 0x08079804
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	ldr r4, .L080798D8 @ =gBg0Tm+0xD2
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0x16
	bl PutSpecialChar
	adds r0, r4, #0
	subs r0, #8
	movs r1, #3
	movs r2, #0x22
	bl PutSpecialChar
	subs r0, r4, #6
	movs r1, #3
	movs r2, #0x23
	bl PutSpecialChar
	adds r0, r4, #0
	subs r0, #0x88
	movs r1, #3
	movs r2, #0x24
	bl PutSpecialChar
	adds r0, r4, #0
	subs r0, #0x86
	movs r1, #3
	movs r2, #0x25
	bl PutSpecialChar
	subs r4, #0x80
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0x1f
	bl PutSpecialChar
	movs r1, #0
	ldr r0, .L080798DC @ =0x0200E6D4
	mov sl, r0
	mov r2, sb
	adds r2, #0x30
	str r2, [sp, #4]
	ldr r3, .L080798E0 @ =gBg1Tm
	mov r8, r3
	movs r6, #7
	mov ip, r6
	movs r7, #0x1a
	movs r0, #0x80
	lsls r0, r0, #5
	adds r5, r0, #0
.L08079874:
	lsls r0, r1, #6
	adds r4, r1, #1
	mov r2, ip
	subs r1, r2, r1
	muls r1, r7, r1
	ldr r3, .L080798E4 @ =gUnk_08320FCE
	adds r1, r1, r3
	mov r6, r8
	adds r2, r0, r6
	movs r3, #0xc
.L08079888:
	ldrh r6, [r1]
	adds r0, r5, r6
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge .L08079888
	adds r1, r4, #0
	cmp r1, #7
	ble .L08079874
	movs r4, #0
	ldr r1, [sp, #4]
	ldrb r1, [r1]
	lsls r0, r1, #2
	add r0, sl
	ldr r0, [r0]
	bl GetUnitFid
	ldr r1, .L080798E8 @ =gBg0Tm+0x42
	movs r2, #0x8c
	lsls r2, r2, #2
	str r4, [sp]
	movs r3, #2
	bl PutFaceChibi
	mov r0, sb
	bl func_fe6_080797DC
	movs r0, #3
	bl EnableBgSync
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080798D8: .4byte gBg0Tm+0xD2
.L080798DC: .4byte 0x0200E6D4
.L080798E0: .4byte gBg1Tm
.L080798E4: .4byte gUnk_08320FCE
.L080798E8: .4byte gBg0Tm+0x42

	thumb_func_start func_fe6_080798EC
func_fe6_080798EC: @ 0x080798EC
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, .L08079920 @ =0x0200E6D4
	adds r0, #0x30
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl GetUnitFid
	ldr r1, .L08079924 @ =gBg0Tm+0x42
	movs r2, #0x8c
	lsls r2, r2, #2
	movs r3, #0
	str r3, [sp]
	movs r3, #2
	bl PutFaceChibi
	adds r0, r4, #0
	bl func_fe6_080797DC
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08079920: .4byte 0x0200E6D4
.L08079924: .4byte gBg0Tm+0x42

	thumb_func_start func_fe6_08079928
func_fe6_08079928: @ 0x08079928
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r3, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r3, r0
	bhs .L08079A0A
	ldr r4, .L0807995C @ =0x0200E6D4
	adds r5, r7, #0
	adds r5, #0x36
	adds r6, r7, #0
	adds r6, #0x44
.L08079948:
	cmp r2, #0
	beq .L08079960
	lsls r0, r3, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	cmp r0, r1
	beq .L08079970
	b .L080799FA
	.align 2, 0
.L0807995C: .4byte 0x0200E6D4
.L08079960:
	lsls r0, r3, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldrb r0, [r0, #0xb]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r1
	bne .L080799FA
.L08079970:
	adds r0, r7, #0
	adds r0, #0x30
	movs r1, #0
	mov r8, r1
	strb r3, [r0]
	lsrs r0, r3, #1
	adds r2, r0, #0
	adds r4, r2, #0
	cmp r2, #0
	bne .L0807998A
	strb r2, [r5]
	strh r2, [r6]
	b .L08079A0A
.L0807998A:
	movs r0, #0x2d
	adds r0, r0, r7
	mov ip, r0
	ldrb r3, [r0]
	subs r0, r3, #1
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	cmp r2, r0
	bne .L080799C0
	cmp r3, #0xe
	bhi .L080799AA
	strb r4, [r5]
	mov r1, r8
	strh r1, [r6]
	b .L08079A0A
.L080799AA:
	movs r0, #6
	strb r0, [r5]
	mov r1, ip
	ldrb r0, [r1]
	subs r0, #0xd
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	lsls r0, r0, #4
	strh r0, [r6]
	b .L08079A0A
.L080799C0:
	ldrh r6, [r6]
	lsrs r1, r6, #4
	adds r0, r1, #0
	cmp r2, r0
	bls .L080799D6
	adds r0, #6
	cmp r2, r0
	bge .L080799D6
	subs r0, r4, r1
	strb r0, [r5]
	b .L08079A0A
.L080799D6:
	adds r3, r7, #0
	adds r3, #0x44
	ldrh r0, [r3]
	lsrs r2, r0, #4
	adds r0, r4, #0
	subs r1, r0, #1
	cmp r2, r1
	ble .L080799EA
	movs r0, #1
	b .L080799F2
.L080799EA:
	subs r1, r0, #5
	cmp r2, r1
	bge .L08079A0A
	movs r0, #5
.L080799F2:
	strb r0, [r5]
	lsls r0, r1, #4
	strh r0, [r3]
	b .L08079A0A
.L080799FA:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r0, r7, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r3, r0
	blo .L08079948
.L08079A0A:
	adds r0, r7, #0
	adds r0, #0x44
	ldrh r2, [r0]
	subs r2, #0x28
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #2
	movs r1, #0
	bl SetBgOffset
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08079A28
func_fe6_08079A28: @ 0x08079A28
	push {r4, lr}
	ldr r0, .L08079A90 @ =0x0200F0A4
	bl UnitRearrangeInit
	movs r4, #1
.L08079A32:
	adds r0, r4, #0
	bl GetUnit
	adds r1, r0, #0
	cmp r1, #0
	beq .L08079A54
	ldr r0, [r1]
	cmp r0, #0
	beq .L08079A54
	movs r0, #0xc
	ldrh r2, [r1, #0xc]
	ands r0, r2
	cmp r0, #0
	bne .L08079A54
	adds r0, r1, #0
	bl UnitRearrangeAdd
.L08079A54:
	adds r4, #1
	cmp r4, #0x3f
	ble .L08079A32
	movs r4, #1
.L08079A5C:
	adds r0, r4, #0
	bl GetUnit
	adds r1, r0, #0
	cmp r1, #0
	beq .L08079A7E
	ldr r0, [r1]
	cmp r0, #0
	beq .L08079A7E
	movs r0, #0xc
	ldrh r2, [r1, #0xc]
	ands r0, r2
	cmp r0, #0
	beq .L08079A7E
	adds r0, r1, #0
	bl UnitRearrangeAdd
.L08079A7E:
	adds r4, #1
	cmp r4, #0x3f
	ble .L08079A5C
	bl UnitRearrangeApply
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08079A90: .4byte 0x0200F0A4

	thumb_func_start func_fe6_08079A94
func_fe6_08079A94: @ 0x08079A94
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x35
	ldrb r0, [r4]
	bl func_fe6_0807CD24
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldrb r0, [r4]
	cmp r0, #0
	bne .L08079B30
	adds r0, r6, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08079AC2
	movs r0, #0xc
	movs r1, #1
	bl func_fe6_0807CEF0
	b .L08079ACA
.L08079AC2:
	movs r0, #0xc
	movs r1, #0
	bl func_fe6_0807CEF0
.L08079ACA:
	ldr r4, .L08079B24 @ =gBg0Tm
	adds r0, r4, #0
	movs r1, #0xc
	movs r2, #0x13
	movs r3, #0
	bl TmFillRect_thm
	ldr r0, .L08079B28 @ =gBg1Tm
	movs r1, #0xc
	movs r2, #0x13
	movs r3, #0
	bl TmFillRect_thm
	lsls r3, r7, #1
	adds r3, #2
	movs r0, #0
	str r0, [sp]
	movs r1, #4
	movs r2, #0xc
	bl PutUiWindowFrame
	ldr r0, .L08079B2C @ =0x0200E864
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r4, r4, r1
	movs r1, #0
	adds r2, r4, #0
	adds r3, r7, #0
	bl func_fe6_0807CD5C
	adds r1, r6, #0
	adds r1, #0x35
	adds r0, r6, #0
	adds r0, #0x33
	ldrb r1, [r1]
	adds r0, r1, r0
	ldrb r0, [r0]
	lsls r1, r0, #1
	adds r1, #5
	movs r0, #1
	movs r2, #0xa
	bl PutUiEntryHover
	b .L08079BAE
	.align 2, 0
.L08079B24: .4byte gBg0Tm
.L08079B28: .4byte gBg1Tm
.L08079B2C: .4byte 0x0200E864
.L08079B30:
	ldr r1, .L08079B50 @ =0x0200E6D4
	adds r0, r6, #0
	adds r0, #0x30
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl GetUnitItemCount
	cmp r0, #0
	ble .L08079B54
	movs r0, #6
	movs r1, #0
	bl func_fe6_0807CEF0
	b .L08079B5C
	.align 2, 0
.L08079B50: .4byte 0x0200E6D4
.L08079B54:
	movs r0, #6
	movs r1, #1
	bl func_fe6_0807CEF0
.L08079B5C:
	ldr r4, .L08079BBC @ =gBg0Tm+0x200
	adds r0, r4, #0
	movs r1, #0xc
	movs r2, #0xb
	movs r3, #0
	bl TmFillRect_thm
	ldr r0, .L08079BC0 @ =gBg1Tm+0x200
	movs r1, #0xc
	movs r2, #0xb
	movs r3, #0
	bl TmFillRect_thm
	lsls r3, r7, #1
	adds r3, #2
	movs r0, #0
	str r0, [sp]
	movs r1, #8
	movs r2, #0xd
	bl PutUiWindowFrame
	ldr r0, .L08079BC4 @ =0x0200E864
	adds r5, r6, #0
	adds r5, #0x35
	ldrb r1, [r5]
	adds r4, #0x44
	adds r2, r4, #0
	adds r3, r7, #0
	bl func_fe6_0807CD5C
	adds r0, r6, #0
	adds r0, #0x33
	ldrb r5, [r5]
	adds r0, r5, r0
	ldrb r0, [r0]
	lsls r1, r0, #1
	adds r1, #9
	movs r0, #1
	movs r2, #0xa
	bl PutUiEntryHover
.L08079BAE:
	movs r0, #3
	bl EnableBgSync
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08079BBC: .4byte gBg0Tm+0x200
.L08079BC0: .4byte gBg1Tm+0x200
.L08079BC4: .4byte 0x0200E864

	thumb_func_start func_fe6_08079BC8
func_fe6_08079BC8: @ 0x08079BC8
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, [r5, #0x14]
	str r0, [r5, #0x30]
	ldr r1, .L08079C30 @ =0x0200E6D4
	adds r0, #0x30
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r5, #0x2c]
	ldr r0, .L08079C34 @ =gBg0Tm+0x200
	movs r1, #0xc
	movs r2, #0xb
	movs r3, #0
	bl TmFillRect_thm
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #8
	movs r2, #0xd
	movs r3, #0xc
	bl PutUiWindowFrame
	movs r0, #3
	bl EnableBgSync
	adds r0, r5, #0
	adds r0, #0x34
	strb r4, [r0]
	ldr r0, [r5, #0x2c]
	bl GetUnitItemCount
	adds r4, r5, #0
	adds r4, #0x35
	strb r0, [r4]
	bl ClearIcons
	ldrb r1, [r4]
	cmp r1, #0
	bne .L08079C28
	ldr r0, [r5, #0x30]
	str r1, [r0, #0x5c]
	adds r0, r5, #0
	bl Proc_End
.L08079C28:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08079C30: .4byte 0x0200E6D4
.L08079C34: .4byte gBg0Tm+0x200

	thumb_func_start func_fe6_08079C38
func_fe6_08079C38: @ 0x08079C38
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	movs r0, #0
	mov sb, r0
	adds r5, r6, #0
	adds r5, #0x34
	ldr r1, .L08079D48 @ =0x0200E864
	mov r8, r1
	ldr r2, .L08079D4C @ =gBg0Tm+0x2
	mov sl, r2
.L08079C54:
	ldrb r1, [r5]
	lsls r0, r1, #3
	add r0, r8
	bl ClearText
	ldrb r2, [r5]
	lsls r1, r2, #1
	adds r4, r1, #0
	adds r4, #9
	lsls r4, r4, #6
	add r4, sl
	ldr r0, [r6, #0x2c]
	adds r0, #0x1c
	adds r0, r0, r1
	ldrh r0, [r0]
	bl GetItemIcon
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x80
	lsls r2, r2, #7
	bl PutIcon
	ldrb r2, [r5]
	lsls r0, r2, #3
	mov r1, r8
	adds r4, r0, r1
	ldr r0, [r6, #0x2c]
	lsls r2, r2, #1
	adds r1, r0, #0
	adds r1, #0x1c
	adds r1, r1, r2
	ldrh r1, [r1]
	bl IsItemDisplayUseable
	movs r1, #0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08079CA4
	movs r1, #1
.L08079CA4:
	adds r0, r4, #0
	bl Text_SetColor
	ldrb r2, [r5]
	lsls r0, r2, #3
	add r0, r8
	movs r1, #0
	bl Text_SetCursor
	ldrb r1, [r5]
	lsls r4, r1, #3
	add r4, r8
	ldr r0, [r6, #0x2c]
	lsls r1, r1, #1
	adds r0, #0x1c
	adds r0, r0, r1
	ldrh r0, [r0]
	bl GetItemName
	adds r1, r0, #0
	adds r0, r4, #0
	bl Text_DrawString
	ldrb r1, [r5]
	lsls r0, r1, #3
	add r0, r8
	lsls r1, r1, #7
	add r1, sl
	movs r2, #0x91
	lsls r2, r2, #2
	adds r1, r1, r2
	bl PutText
	ldrb r0, [r5]
	lsls r2, r0, #1
	adds r0, r2, #0
	adds r0, #9
	lsls r0, r0, #6
	ldr r1, .L08079D50 @ =gBg0Tm+0x16
	adds r7, r0, r1
	ldr r0, [r6, #0x2c]
	adds r1, r0, #0
	adds r1, #0x1c
	adds r1, r1, r2
	ldrh r1, [r1]
	bl IsItemDisplayUseable
	lsls r0, r0, #0x18
	movs r4, #1
	cmp r0, #0
	beq .L08079D0C
	movs r4, #2
.L08079D0C:
	ldr r0, [r6, #0x2c]
	ldrb r2, [r5]
	lsls r1, r2, #1
	adds r0, #0x1c
	adds r0, r0, r1
	ldrh r0, [r0]
	bl GetItemUses
	adds r2, r0, #0
	adds r0, r7, #0
	adds r1, r4, #0
	bl PutNumberOrBlank
	ldrb r0, [r5]
	adds r0, #1
	movs r2, #0
	strb r0, [r5]
	adds r1, r6, #0
	adds r1, #0x35
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo .L08079D54
	ldr r0, [r6, #0x30]
	str r2, [r0, #0x5c]
	adds r0, r6, #0
	bl Proc_Break
	b .L08079D60
	.align 2, 0
.L08079D48: .4byte 0x0200E864
.L08079D4C: .4byte gBg0Tm+0x2
.L08079D50: .4byte gBg0Tm+0x16
.L08079D54:
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #4
	bgt .L08079D60
	b .L08079C54
.L08079D60:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08079D70
func_fe6_08079D70: @ 0x08079D70
	push {lr}
	adds r1, r0, #0
	ldr r0, .L08079D80 @ =gUnk_08678E18
	bl SpawnProc
	pop {r1}
	bx r1
	.align 2, 0
.L08079D80: .4byte gUnk_08678E18

	thumb_func_start func_fe6_08079D84
func_fe6_08079D84: @ 0x08079D84
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r4, r0, #0
	ldr r5, .L08079E90 @ =0x0200E6D4
	adds r4, #0x30
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r5
	ldr r0, [r0]
	mov sb, r0
	ldr r7, .L08079E94 @ =gBg0Tm+0x200
	adds r0, r7, #0
	movs r1, #0xc
	movs r2, #0xb
	movs r3, #0
	bl TmFillRect_thm
	movs r0, #0
	str r0, [sp]
	movs r1, #8
	movs r2, #0xd
	movs r3, #0xc
	bl PutUiWindowFrame
	ldrb r4, [r4]
	lsls r0, r4, #2
	adds r0, r0, r5
	ldr r0, [r0]
	bl GetUnitItemCount
	mov sl, r0
	bl ClearIcons
	movs r6, #0
	cmp r6, sl
	bge .L08079E78
	movs r0, #0x56
	adds r0, r0, r7
	mov r8, r0
	adds r7, #0x42
	movs r1, #0x90
	lsls r1, r1, #2
	str r1, [sp, #4]
.L08079DE2:
	lsls r1, r6, #3
	ldr r0, .L08079E98 @ =0x0200E864
	adds r4, r1, r0
	adds r0, r4, #0
	bl ClearText
	lsls r1, r6, #1
	mov r0, sb
	adds r0, #0x1c
	adds r5, r0, r1
	ldrh r0, [r5]
	bl GetItemIcon
	adds r1, r0, #0
	adds r0, r7, #0
	movs r2, #0x80
	lsls r2, r2, #7
	bl PutIcon
	ldrh r1, [r5]
	mov r0, sb
	bl IsItemDisplayUseable
	movs r1, #0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08079E1A
	movs r1, #1
.L08079E1A:
	adds r0, r4, #0
	bl Text_SetColor
	adds r0, r4, #0
	movs r1, #0
	bl Text_SetCursor
	ldrh r0, [r5]
	bl GetItemName
	adds r1, r0, #0
	adds r0, r4, #0
	bl Text_DrawString
	ldr r1, .L08079E9C @ =gBg0Tm+0x2
	adds r1, #4
	ldr r0, [sp, #4]
	adds r1, r0, r1
	adds r0, r4, #0
	bl PutText
	ldrh r1, [r5]
	mov r0, sb
	bl IsItemDisplayUseable
	lsls r0, r0, #0x18
	movs r4, #1
	cmp r0, #0
	beq .L08079E56
	movs r4, #2
.L08079E56:
	ldrh r0, [r5]
	bl GetItemUses
	adds r2, r0, #0
	mov r0, r8
	adds r1, r4, #0
	bl PutNumberOrBlank
	movs r1, #0x80
	add r8, r1
	adds r7, #0x80
	ldr r0, [sp, #4]
	adds r0, #0x80
	str r0, [sp, #4]
	adds r6, #1
	cmp r6, sl
	blt .L08079DE2
.L08079E78:
	movs r0, #3
	bl EnableBgSync
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08079E90: .4byte 0x0200E6D4
.L08079E94: .4byte gBg0Tm+0x200
.L08079E98: .4byte 0x0200E864
.L08079E9C: .4byte gBg0Tm+0x2

	thumb_func_start func_fe6_08079EA0
func_fe6_08079EA0: @ 0x08079EA0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r4, .L08079F3C @ =0x0200E7DC
	adds r0, r4, #0
	bl ClearText
	adds r0, r4, #0
	movs r1, #0
	bl Text_SetCursor
	adds r0, r4, #0
	movs r1, #0
	bl Text_SetColor
	ldr r1, .L08079F40 @ =gUnk_08327254
	adds r0, r4, #0
	bl Text_DrawString
	adds r0, r4, #0
	movs r1, #0x18
	bl Text_SetCursor
	adds r0, r4, #0
	movs r1, #2
	bl Text_SetColor
	adds r6, r5, #0
	adds r6, #0x2e
	adds r5, #0x2f
	ldrb r0, [r6]
	ldrb r5, [r5]
	subs r1, r0, r5
	adds r0, r4, #0
	bl Text_DrawNumberOrBlank
	adds r0, r4, #0
	movs r1, #0
	bl Text_SetColor
	adds r0, r4, #0
	movs r1, #0x20
	bl Text_SetCursor
	ldr r1, .L08079F44 @ =gUnk_0832725C
	adds r0, r4, #0
	bl Text_DrawString
	adds r0, r4, #0
	movs r1, #0x28
	bl Text_SetCursor
	ldr r1, .L08079F48 @ =gUnk_08327260
	adds r0, r4, #0
	bl Text_DrawString
	adds r0, r4, #0
	movs r1, #0x38
	bl Text_SetCursor
	adds r0, r4, #0
	movs r1, #2
	bl Text_SetColor
	ldrb r1, [r6]
	adds r0, r4, #0
	bl Text_DrawNumberOrBlank
	ldr r1, .L08079F4C @ =gBg0Tm+0x6A
	adds r0, r4, #0
	bl PutText
	movs r0, #1
	bl EnableBgSync
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08079F3C: .4byte 0x0200E7DC
.L08079F40: .4byte gUnk_08327254
.L08079F44: .4byte gUnk_0832725C
.L08079F48: .4byte gUnk_08327260
.L08079F4C: .4byte gBg0Tm+0x6A

	thumb_func_start func_fe6_08079F50
func_fe6_08079F50: @ 0x08079F50
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sl, r0
	lsls r1, r1, #0x19
	lsrs r7, r1, #0x18
	movs r0, #0xf
	ands r0, r7
	str r0, [sp]
	movs r0, #0x1f
	ands r0, r7
	lsls r0, r0, #6
	ldr r1, .L08079FD4 @ =gBg2Tm
	adds r0, r0, r1
	movs r1, #0xf
	movs r2, #1
	movs r3, #0
	bl TmFillRect_thm
	movs r1, #0
	mov r8, r1
	mov r0, sl
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r7, r0
	bge .L0807A05C
	ldr r2, .L08079FD8 @ =0x0200E7E4
	mov sb, r2
.L08079F8E:
	ldr r4, [sp]
	add r4, r8
	lsls r0, r4, #3
	mov r1, sb
	adds r5, r0, r1
	adds r0, r5, #0
	bl ClearText
	adds r0, r5, #0
	movs r1, #0
	bl Text_SetCursor
	mov r1, sl
	adds r1, #0x2c
	movs r0, #1
	ldrb r1, [r1]
	ands r0, r1
	mov r2, r8
	adds r6, r7, r2
	cmp r0, #0
	bne .L08079FE0
	lsls r0, r6, #2
	ldr r1, .L08079FDC @ =0x0200E6D4
	adds r0, r0, r1
	ldr r0, [r0]
	bl func_fe6_08079404
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08079FE0
	adds r0, r5, #0
	movs r1, #4
	bl Text_SetColor
	b .L0807A00E
	.align 2, 0
.L08079FD4: .4byte gBg2Tm
.L08079FD8: .4byte 0x0200E7E4
.L08079FDC: .4byte 0x0200E6D4
.L08079FE0:
	lsls r0, r6, #2
	ldr r2, .L0807A000 @ =0x0200E6D4
	adds r0, r0, r2
	ldr r1, [r0]
	movs r0, #8
	ldrh r1, [r1, #0xc]
	ands r0, r1
	cmp r0, #0
	beq .L0807A004
	lsls r0, r4, #3
	add r0, sb
	movs r1, #1
	bl Text_SetColor
	b .L0807A00E
	.align 2, 0
.L0807A000: .4byte 0x0200E6D4
.L0807A004:
	lsls r0, r4, #3
	add r0, sb
	movs r1, #0
	bl Text_SetColor
.L0807A00E:
	lsls r4, r4, #3
	add r4, sb
	lsls r0, r6, #2
	ldr r1, .L0807A074 @ =0x0200E6D4
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	ldrh r0, [r0]
	bl DecodeMsg
	adds r1, r0, #0
	adds r0, r4, #0
	bl Text_DrawString
	movs r1, #0x1f
	ands r1, r7
	lsls r1, r1, #5
	mov r2, r8
	lsls r0, r2, #3
	adds r1, r1, r0
	lsls r1, r1, #1
	ldr r0, .L0807A078 @ =gBg2Tm
	adds r1, r1, r0
	adds r0, r4, #0
	bl PutText
	mov r0, r8
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	cmp r0, #1
	bhi .L0807A05C
	adds r0, r7, r0
	mov r1, sl
	adds r1, #0x2d
	ldrb r1, [r1]
	cmp r0, r1
	blt .L08079F8E
.L0807A05C:
	movs r0, #4
	bl EnableBgSync
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0807A074: .4byte 0x0200E6D4
.L0807A078: .4byte gBg2Tm

	thumb_func_start func_fe6_0807A07C
func_fe6_0807A07C: @ 0x0807A07C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x100
	bl GetPlayerDeployCount
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	movs r0, #0
	mov sb, r0
	mov r8, r0
	movs r4, #1
.L0807A09A:
	adds r0, r4, #0
	bl GetUnit
	adds r1, r0, #0
	cmp r1, #0
	beq .L0807A0BE
	ldr r0, [r1]
	cmp r0, #0
	beq .L0807A0BE
	mov r2, r8
	lsls r0, r2, #2
	add r0, sp
	str r1, [r0]
	mov r0, r8
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
.L0807A0BE:
	adds r4, #1
	cmp r4, #0x3f
	ble .L0807A09A
	movs r5, #0
	cmp r5, r8
	bge .L0807A118
	mov r6, sp
.L0807A0CC:
	ldr r1, [r6]
	movs r0, #4
	ldrh r3, [r1, #0xc]
	ands r0, r3
	cmp r0, #0
	bne .L0807A110
	adds r0, r1, #0
	bl func_fe6_08079404
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0807A110
	cmp r5, #0
	ble .L0807A110
	mov r1, sp
	subs r1, #4
	lsls r0, r5, #2
	adds r4, r1, r0
.L0807A0F0:
	subs r7, r5, #1
	ldr r0, [r4]
	bl func_fe6_08079404
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0807A110
	ldr r1, [r4, #4]
	ldr r0, [r4]
	str r0, [r4, #4]
	str r1, [r4]
	subs r4, #4
	subs r6, #4
	adds r5, r7, #0
	cmp r5, #0
	bgt .L0807A0F0
.L0807A110:
	adds r6, #4
	adds r5, #1
	cmp r5, r8
	blt .L0807A0CC
.L0807A118:
	ldr r0, .L0807A170 @ =0x0200F0A4
	bl UnitRearrangeInit
	mov r0, r8
	cmp r0, #0
	beq .L0807A134
	mov r4, sp
	mov r5, r8
.L0807A128:
	ldm r4!, {r0}
	bl UnitRearrangeAdd
	subs r5, #1
	cmp r5, #0
	bne .L0807A128
.L0807A134:
	bl UnitRearrangeApply
	movs r4, #1
.L0807A13A:
	adds r0, r4, #0
	bl GetUnit
	adds r2, r0, #0
	cmp r2, #0
	beq .L0807A17E
	ldr r0, [r2]
	cmp r0, #0
	beq .L0807A17E
	ldrh r1, [r2, #0xc]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne .L0807A17E
	cmp sl, sb
	bls .L0807A178
	ldr r3, .L0807A174 @ =0x0000FFF7
	adds r0, r3, #0
	ands r0, r1
	strh r0, [r2, #0xc]
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	b .L0807A17E
	.align 2, 0
.L0807A170: .4byte 0x0200F0A4
.L0807A174: .4byte 0x0000FFF7
.L0807A178:
	movs r0, #8
	orrs r0, r1
	strh r0, [r2, #0xc]
.L0807A17E:
	adds r4, #1
	cmp r4, #0x3f
	ble .L0807A13A
	add sp, #0x100
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0807A194
func_fe6_0807A194: @ 0x0807A194
	push {r4, lr}
	movs r4, #1
.L0807A198:
	adds r0, r4, #0
	bl GetUnit
	adds r1, r0, #0
	cmp r1, #0
	beq .L0807A1BA
	ldr r0, [r1]
	cmp r0, #0
	beq .L0807A1BA
	ldrh r2, [r1, #0xc]
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	bne .L0807A1BA
	movs r0, #8
	orrs r0, r2
	strh r0, [r1, #0xc]
.L0807A1BA:
	adds r4, #1
	cmp r4, #0x3f
	ble .L0807A198
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0807A1C8
func_fe6_0807A1C8: @ 0x0807A1C8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	adds r0, #0x2f
	movs r1, #0
	strb r1, [r0]
	subs r0, #2
	strb r1, [r0]
	ldr r0, .L0807A228 @ =0x0200E7D4
	strb r1, [r0]
	movs r4, #1
.L0807A1E0:
	adds r0, r4, #0
	bl GetUnit
	adds r3, r0, #0
	cmp r3, #0
	beq .L0807A256
	ldr r0, [r3]
	cmp r0, #0
	beq .L0807A256
	movs r0, #4
	ldrh r1, [r3, #0xc]
	ands r0, r1
	cmp r0, #0
	bne .L0807A256
	ldr r1, .L0807A22C @ =0x0200E6D4
	adds r2, r5, #0
	adds r2, #0x2d
	ldrb r7, [r2]
	lsls r0, r7, #2
	adds r0, r0, r1
	str r3, [r0]
	ldrh r1, [r3, #0xc]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne .L0807A234
	ldr r7, .L0807A230 @ =0x0000FFFD
	adds r0, r7, #0
	ands r0, r1
	strh r0, [r3, #0xc]
	adds r1, r5, #0
	adds r1, #0x2f
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b .L0807A23A
	.align 2, 0
.L0807A228: .4byte 0x0200E7D4
.L0807A22C: .4byte 0x0200E6D4
.L0807A230: .4byte 0x0000FFFD
.L0807A234:
	movs r0, #0xa
	orrs r0, r1
	strh r0, [r3, #0xc]
.L0807A23A:
	ldr r0, .L0807A264 @ =0x0200E7D4
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	cmp r6, #0
	beq .L0807A256
	adds r0, r3, #0
	bl GetUnitMapSprite
	bl UseUnitSprite
.L0807A256:
	adds r4, #1
	cmp r4, #0x3f
	ble .L0807A1E0
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0807A264: .4byte 0x0200E7D4

	thumb_func_start func_fe6_0807A268
func_fe6_0807A268: @ 0x0807A268
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	bl ResetTextFont
	bl ClearIcons
	bl ApplyUnitSpritePalettes
	bl ResetText
	bl InitIcons
	movs r0, #4
	bl ApplyIconPalettes
	bl UnpackUiWindowFrameGraphics
	movs r0, #0
	movs r1, #0xe
	bl func_fe6_08070E70
	ldr r2, .L0807A2E0 @ =gDispIo
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r1, [r2, #1]
	ands r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #2
	ands r0, r1
	subs r1, #4
	ands r0, r1
	subs r1, #8
	ands r0, r1
	strb r0, [r2, #1]
	bl ApplySystemObjectsGraphics
	bl ResetUnitSprites
	adds r0, r7, #0
	bl StartGreenText
	bl func_fe6_08082CBC
	adds r1, r7, #0
	adds r1, #0x2c
	movs r0, #1
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq .L0807A2E4
	adds r1, r7, #0
	adds r1, #0x2e
	movs r0, #5
	b .L0807A2EC
	.align 2, 0
.L0807A2E0: .4byte gDispIo
.L0807A2E4:
	bl GetPlayerDeployCount
	adds r1, r7, #0
	adds r1, #0x2e
.L0807A2EC:
	strb r0, [r1]
	adds r4, r1, #0
	movs r0, #0
	str r0, [r7, #0x5c]
	adds r0, r7, #0
	movs r1, #1
	bl func_fe6_0807A1C8
	adds r0, r7, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	ldrb r2, [r4]
	cmp r2, r0
	bls .L0807A30A
	strb r0, [r4]
.L0807A30A:
	adds r0, r7, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	cmp r0, #6
	bne .L0807A324
	bl GetLastStatScreenUnitId
	adds r1, r0, #0
	adds r0, r7, #0
	movs r2, #0
	bl func_fe6_08079928
	b .L0807A334
.L0807A324:
	cmp r0, #9
	bne .L0807A334
	ldr r0, .L0807A514 @ =0x0200E7D8
	ldr r1, [r0]
	adds r0, r7, #0
	movs r2, #1
	bl func_fe6_08079928
.L0807A334:
	ldr r0, .L0807A518 @ =gBg0Tm
	movs r1, #0
	bl TmFill
	ldr r0, .L0807A51C @ =gBg1Tm
	movs r1, #0
	bl TmFill
	ldr r0, .L0807A520 @ =gBg2Tm
	movs r1, #0
	bl TmFill
	adds r6, r7, #0
	adds r6, #0x42
	movs r3, #0x44
	adds r3, r3, r7
	mov r8, r3
	movs r4, #0x2a
	adds r4, r4, r7
	mov sb, r4
	movs r0, #0x29
	adds r0, r0, r7
	mov sl, r0
	ldr r5, .L0807A524 @ =0x0200E864
	movs r4, #4
.L0807A366:
	adds r0, r5, #0
	movs r1, #7
	bl InitTextDb
	adds r5, #8
	subs r4, #1
	cmp r4, #0
	bge .L0807A366
	ldr r4, .L0807A528 @ =0x0200E88C
	adds r0, r4, #0
	movs r1, #7
	bl InitText
	adds r4, #8
	adds r0, r4, #0
	movs r1, #7
	bl InitText
	ldr r5, .L0807A52C @ =0x0200E7E4
	movs r4, #0xf
.L0807A38E:
	adds r0, r5, #0
	movs r1, #5
	bl InitText
	adds r5, #8
	subs r4, #1
	cmp r4, #0
	bge .L0807A38E
	ldr r0, .L0807A530 @ =0x0200E7DC
	movs r1, #9
	bl InitTextDb
	ldr r0, .L0807A534 @ =0x0200E89C
	movs r1, #7
	bl InitText
	ldr r0, .L0807A538 @ =gUnk_0831A268
	ldr r1, .L0807A53C @ =0x06014800
	bl Decompress
	ldr r0, .L0807A540 @ =gUnk_0831AABC
	movs r1, #0x90
	lsls r1, r1, #2
	movs r2, #0x40
	bl ApplyPaletteExt
	ldr r0, .L0807A544 @ =gUnk_08326930
	ldr r1, .L0807A548 @ =0x06017000
	bl Decompress
	ldr r0, .L0807A54C @ =gUnk_08326E64
	movs r1, #0xb0
	lsls r1, r1, #2
	movs r2, #0x80
	bl ApplyPaletteExt
	ldr r0, .L0807A550 @ =gUnk_08327108
	movs r1, #0xa0
	lsls r1, r1, #2
	movs r2, #0x20
	bl ApplyPaletteExt
	movs r4, #0
	ldr r2, .L0807A554 @ =gPal
	ldr r3, .L0807A558 @ =0x000002CA
	adds r1, r2, r3
	adds r3, r6, #0
	movs r6, #0xf
	mov ip, r6
	movs r5, #0xc8
	lsls r5, r5, #1
.L0807A3F4:
	ldrh r6, [r3]
	lsrs r0, r6, #2
	adds r0, r0, r4
	mov r6, ip
	ands r0, r6
	adds r0, r0, r5
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r4, #1
	cmp r4, #9
	ble .L0807A3F4
	bl EnablePalSync
	ldr r0, .L0807A55C @ =gDispIo
	mov ip, r0
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	mov r2, ip
	ldrb r2, [r2, #0xc]
	ands r0, r2
	movs r2, #1
	orrs r0, r2
	mov r3, ip
	strb r0, [r3, #0xc]
	adds r0, r1, #0
	ldrb r4, [r3, #0x10]
	ands r0, r4
	movs r6, #2
	orrs r0, r6
	strb r0, [r3, #0x10]
	ldrb r0, [r3, #0x14]
	ands r1, r0
	orrs r1, r2
	strb r1, [r3, #0x14]
	movs r0, #3
	ldrb r1, [r3, #0x18]
	orrs r0, r1
	strb r0, [r3, #0x18]
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrb r3, [r3, #1]
	ands r0, r3
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	mov r4, ip
	strb r0, [r4, #1]
	mov r1, ip
	adds r1, #0x2d
	movs r0, #0
	strb r0, [r1]
	adds r1, #4
	strb r0, [r1]
	subs r1, #5
	movs r0, #0xf0
	strb r0, [r1]
	adds r1, #4
	movs r0, #0xa0
	strb r0, [r1]
	adds r4, #0x34
	ldrb r0, [r4]
	orrs r0, r2
	orrs r0, r6
	movs r5, #4
	orrs r0, r5
	movs r3, #8
	orrs r0, r3
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4]
	adds r4, #1
	ldrb r0, [r4]
	orrs r0, r2
	orrs r0, r6
	orrs r0, r5
	orrs r0, r3
	orrs r0, r1
	strb r0, [r4]
	adds r4, #1
	ldrb r0, [r4]
	orrs r2, r0
	orrs r2, r6
	movs r0, #5
	rsbs r0, r0, #0
	ands r2, r0
	orrs r2, r3
	orrs r2, r1
	strb r2, [r4]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	mov r1, r8
	ldrh r2, [r1]
	subs r2, #0x28
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #2
	movs r1, #0
	bl SetBgOffset
	ldr r0, .L0807A560 @ =gUnk_08320E18
	ldr r1, .L0807A564 @ =0x06004800
	bl Decompress
	ldr r0, .L0807A568 @ =gUnk_08319E88
	movs r1, #0xf0
	lsls r1, r1, #1
	movs r2, #0x20
	bl ApplyPaletteExt
	bl func_fe6_0807CC28
	adds r0, r7, #0
	bl func_fe6_08079424
	mov r2, sb
	ldrb r2, [r2]
	cmp r2, #1
	bne .L0807A502
	adds r0, r7, #0
	bl func_fe6_08079804
.L0807A502:
	mov r3, sl
	ldrb r0, [r3]
	cmp r0, #0
	bne .L0807A56C
	adds r0, r7, #0
	bl func_fe6_08079A94
	b .L0807A576
	.align 2, 0
.L0807A514: .4byte 0x0200E7D8
.L0807A518: .4byte gBg0Tm
.L0807A51C: .4byte gBg1Tm
.L0807A520: .4byte gBg2Tm
.L0807A524: .4byte 0x0200E864
.L0807A528: .4byte 0x0200E88C
.L0807A52C: .4byte 0x0200E7E4
.L0807A530: .4byte 0x0200E7DC
.L0807A534: .4byte 0x0200E89C
.L0807A538: .4byte gUnk_0831A268
.L0807A53C: .4byte 0x06014800
.L0807A540: .4byte gUnk_0831AABC
.L0807A544: .4byte gUnk_08326930
.L0807A548: .4byte 0x06017000
.L0807A54C: .4byte gUnk_08326E64
.L0807A550: .4byte gUnk_08327108
.L0807A554: .4byte gPal
.L0807A558: .4byte 0x000002CA
.L0807A55C: .4byte gDispIo
.L0807A560: .4byte gUnk_08320E18
.L0807A564: .4byte 0x06004800
.L0807A568: .4byte gUnk_08319E88
.L0807A56C:
	cmp r0, #1
	bne .L0807A576
	adds r0, r7, #0
	bl func_fe6_08079D84
.L0807A576:
	adds r0, r7, #0
	bl func_fe6_0807A67C
	movs r0, #0xf
	bl EnableBgSync
	ldr r0, [r7, #0x60]
	movs r1, #0xc0
	lsls r1, r1, #7
	movs r2, #0xd
	bl func_fe6_08082D08
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0807A59C
func_fe6_0807A59C: @ 0x0807A59C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r0, #0
	bl InitBgs
	adds r0, r5, #0
	bl func_fe6_0807A268
	adds r1, r5, #0
	adds r1, #0x2c
	movs r0, #1
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq .L0807A5C6
	movs r0, #0
	movs r1, #0
	movs r2, #0xa
	bl StartMuralBackground
	b .L0807A5EE
.L0807A5C6:
	ldr r4, .L0807A65C @ =gUnk_0831B0A8
	movs r0, #3
	bl GetBgChrOffset
	adds r1, r0, #0
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r1, r1, r0
	adds r0, r4, #0
	bl Decompress
	ldr r0, .L0807A660 @ =gUnk_08320D98
	movs r1, #0xa0
	lsls r1, r1, #1
	movs r2, #0x80
	bl ApplyPaletteExt
	adds r0, r5, #0
	bl func_fe6_08082560
.L0807A5EE:
	str r0, [r5, #0x58]
	ldr r0, .L0807A664 @ =gUnk_08321FA4
	ldr r1, .L0807A668 @ =0x020104A4
	bl Decompress
	ldr r0, .L0807A66C @ =gUnk_08326910
	movs r1, #0xe0
	lsls r1, r1, #1
	movs r2, #0x20
	bl ApplyPaletteExt
	movs r5, #0
	ldr r7, .L0807A670 @ =gPlaySt
	ldr r6, .L0807A674 @ =0x0600E000
.L0807A60A:
	movs r0, #0xe
	ldrsb r0, [r7, r0]
	bl GetChapterInfo
	adds r4, r0, #0
	movs r0, #0xe
	ldrsb r0, [r7, r0]
	bl GetChapterInfo
	adds r1, r0, #0
	adds r4, #0x40
	ldrb r4, [r4]
	adds r0, r4, r5
	lsls r0, r0, #5
	adds r1, #0x3f
	ldrb r1, [r1]
	adds r0, r1, r0
	lsls r0, r0, #5
	ldr r1, .L0807A668 @ =0x020104A4
	adds r0, r0, r1
	adds r1, r6, #0
	movs r2, #0x78
	bl CpuFastSet
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r6, r6, r0
	adds r5, #1
	cmp r5, #0xb
	ble .L0807A60A
	movs r2, #0
	movs r1, #0x1f
	ldr r0, .L0807A678 @ =0x0600F81F
.L0807A64C:
	strb r2, [r0]
	subs r0, #1
	subs r1, #1
	cmp r1, #0
	bge .L0807A64C
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0807A65C: .4byte gUnk_0831B0A8
.L0807A660: .4byte gUnk_08320D98
.L0807A664: .4byte gUnk_08321FA4
.L0807A668: .4byte 0x020104A4
.L0807A66C: .4byte gUnk_08326910
.L0807A670: .4byte gPlaySt
.L0807A674: .4byte 0x0600E000
.L0807A678: .4byte 0x0600F81F

	thumb_func_start func_fe6_0807A67C
func_fe6_0807A67C: @ 0x0807A67C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0
	beq .L0807A694
	b .L0807A7C8
.L0807A694:
	ldr r0, .L0807A7A0 @ =gUnk_08326EE6
	mov sl, r0
	movs r1, #0x80
	lsls r1, r1, #8
	movs r0, #2
	bl SetBgChrOffset
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #2
	bl GetBgTilemap
	ldr r1, .L0807A7A4 @ =0x0000E3C0
	bl TmFill
	movs r4, #0
	ldr r1, .L0807A7A8 @ =gBg0Tm
	mov r8, r1
	ldr r0, .L0807A7AC @ =0x0200E7DC
	mov sb, r0
	ldr r7, .L0807A7B0 @ =gBg2Tm
	movs r5, #0
	movs r2, #0xae
	ldr r1, .L0807A7B4 @ =0xFFFFE300
	adds r6, r1, #0
.L0807A6CC:
	movs r3, #0xe
	adds r0, r5, r6
	adds r1, r0, #0
	adds r1, #0xe
	lsls r0, r2, #1
	adds r0, r0, r7
	adds r0, #0x1c
.L0807A6DA:
	strh r1, [r0]
	subs r1, #1
	subs r0, #2
	subs r3, #1
	cmp r3, #0
	bge .L0807A6DA
	adds r5, #0xf
	adds r2, #0x20
	adds r4, #1
	cmp r4, #0xb
	ble .L0807A6CC
	movs r4, #0
	ldr r0, .L0807A7B8 @ =gBg1Tm
	mov ip, r0
	movs r7, #0xf
	movs r1, #0x80
	lsls r1, r1, #5
	adds r6, r1, #0
.L0807A6FE:
	movs r3, #0
	adds r5, r4, #1
	adds r0, r4, #4
	lsls r0, r0, #5
	adds r0, #0xd
	subs r2, r7, r4
	lsls r1, r2, #4
	adds r1, r1, r2
	lsls r1, r1, #1
	add r1, sl
	lsls r0, r0, #1
	mov r4, ip
	adds r2, r0, r4
.L0807A718:
	ldrh r4, [r1]
	adds r0, r6, r4
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	adds r3, #1
	cmp r3, #0x10
	ble .L0807A718
	adds r4, r5, #0
	cmp r4, #0xf
	ble .L0807A6FE
	movs r0, #0x94
	lsls r0, r0, #1
	add r0, r8
	movs r1, #0
	strh r1, [r0]
	movs r0, #0x95
	lsls r0, r0, #1
	add r0, r8
	strh r1, [r0]
	movs r0, #0x9d
	lsls r0, r0, #3
	add r0, r8
	strh r1, [r0]
	ldr r0, .L0807A7BC @ =0x000004EA
	add r0, r8
	strh r1, [r0]
	mov r0, sb
	bl ClearText
	ldr r4, .L0807A7C0 @ =gPlaySt
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	bl GetChapterInfo
	ldrh r0, [r0, #0x3c]
	bl DecodeMsg
	bl GetStringTextLen
	movs r1, #0x48
	subs r1, r1, r0
	asrs r1, r1, #1
	mov r0, sb
	bl Text_SetCursor
	mov r0, sb
	movs r1, #0
	bl Text_SetColor
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	bl GetChapterInfo
	ldrh r0, [r0, #0x3c]
	bl DecodeMsg
	adds r1, r0, #0
	mov r0, sb
	bl Text_DrawString
	ldr r1, .L0807A7C4 @ =0x00000462
	add r1, r8
	mov r0, sb
	bl PutText
	b .L0807A82E
	.align 2, 0
.L0807A7A0: .4byte gUnk_08326EE6
.L0807A7A4: .4byte 0x0000E3C0
.L0807A7A8: .4byte gBg0Tm
.L0807A7AC: .4byte 0x0200E7DC
.L0807A7B0: .4byte gBg2Tm
.L0807A7B4: .4byte 0xFFFFE300
.L0807A7B8: .4byte gBg1Tm
.L0807A7BC: .4byte 0x000004EA
.L0807A7C0: .4byte gPlaySt
.L0807A7C4: .4byte 0x00000462
.L0807A7C8:
	movs r0, #2
	movs r1, #0
	bl SetBgChrOffset
	ldr r0, .L0807A844 @ =gBg2Tm
	movs r1, #0
	bl TmFill
	adds r0, r6, #0
	adds r0, #0x44
	ldrh r1, [r0]
	lsrs r4, r1, #4
	adds r1, r4, #7
	adds r5, r0, #0
	adds r7, r6, #0
	adds r7, #0x33
	cmp r4, r1
	bge .L0807A802
.L0807A7EC:
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	adds r0, r6, #0
	bl func_fe6_08079F50
	adds r4, #1
	ldrh r1, [r5]
	lsrs r0, r1, #4
	adds r0, #7
	cmp r4, r0
	blt .L0807A7EC
.L0807A802:
	movs r0, #0
	str r0, [sp]
	movs r0, #0xd
	movs r1, #4
	movs r2, #0x11
	movs r3, #0x10
	bl PutUiWindowFrame
	ldr r1, .L0807A848 @ =0x0000FF80
	ldrh r2, [r5]
	subs r2, #0x28
	movs r0, #0xff
	ands r2, r0
	movs r0, #2
	bl SetBgOffset
	ldrb r0, [r7]
	cmp r0, #0
	bne .L0807A82E
	adds r0, r6, #0
	bl func_fe6_08079EA0
.L0807A82E:
	movs r0, #7
	bl EnableBgSync
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0807A844: .4byte gBg2Tm
.L0807A848: .4byte 0x0000FF80

	thumb_func_start func_fe6_0807A84C
func_fe6_0807A84C: @ 0x0807A84C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0
	ldr r1, .L0807A898 @ =0x0200E7D8
	movs r0, #0
	str r0, [r1]
	str r0, [r4, #0x48]
	str r0, [r4, #0x4c]
	adds r1, r4, #0
	adds r1, #0x44
	movs r5, #0
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x30
	strb r5, [r0]
	subs r1, #0x13
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x29
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	adds r0, #0xb
	strb r5, [r0]
	bl func_fe6_08036984
	adds r1, r0, #0
	cmp r1, #1
	bne .L0807A89C
	adds r0, r4, #0
	adds r0, #0x2c
	strb r1, [r0]
	b .L0807A8AA
	.align 2, 0
.L0807A898: .4byte 0x0200E7D8
.L0807A89C:
	adds r0, r4, #0
	adds r0, #0x2c
	strb r5, [r0]
	movs r0, #0x22
	movs r1, #0
	bl StartBgm
.L0807A8AA:
	adds r0, r4, #0
	adds r0, #0x38
	movs r1, #0
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #2
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	adds r0, #2
	strb r1, [r0]
	adds r3, r4, #0
	adds r3, #0x35
	adds r1, r4, #0
	adds r1, #0x33
	movs r2, #0
	subs r0, #9
.L0807A8D6:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge .L0807A8D6
	movs r0, #0
	strb r0, [r3]
	adds r0, r4, #0
	bl func_fe6_08082CF4
	str r0, [r4, #0x60]
	adds r0, r4, #0
	bl func_fe6_0807A59C
	adds r0, r4, #0
	bl func_fe6_0807C508
	mov r8, r0
	str r0, [r4, #0x50]
	ldr r5, .L0807A93C @ =gPlaySt
	movs r0, #0xe
	ldrsb r0, [r5, r0]
	bl GetChapterInfo
	adds r0, #0x41
	ldrb r0, [r0]
	lsls r6, r0, #0x1b
	lsrs r6, r6, #0x18
	movs r0, #0xe
	ldrsb r0, [r5, r0]
	bl GetChapterInfo
	adds r0, #0x42
	ldrb r0, [r0]
	lsls r4, r0, #0x1b
	lsrs r4, r4, #0x18
	movs r0, #0xe
	ldrsb r0, [r5, r0]
	bl GetChapterInfo
	adds r0, #0x3e
	ldrb r3, [r0]
	mov r0, r8
	adds r1, r6, #0
	adds r2, r4, #0
	bl func_fe6_0807B8CC
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0807A93C: .4byte gPlaySt

	thumb_func_start func_fe6_0807A940
func_fe6_0807A940: @ 0x0807A940
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r0, #0x30
	ldrb r0, [r0]
	mov r8, r0
	ldr r2, .L0807A968 @ =gKeySt
	ldr r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ldrh r1, [r1, #4]
	ands r0, r1
	cmp r0, #0
	beq .L0807A96C
	adds r1, r4, #0
	adds r1, #0x3f
	movs r0, #2
	b .L0807A972
	.align 2, 0
.L0807A968: .4byte gKeySt
.L0807A96C:
	adds r1, r4, #0
	adds r1, #0x3f
	movs r0, #1
.L0807A972:
	strb r0, [r1]
	adds r5, r1, #0
	ldr r1, [r2]
	movs r0, #8
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L0807A9F8
	adds r1, r4, #0
	adds r1, #0x2c
	movs r6, #1
	adds r0, r6, #0
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne .L0807A9F8
	adds r1, r4, #0
	adds r1, #0x3c
	adds r0, r6, #0
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq .L0807A9D8
	adds r0, r4, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq .L0807A9D8
	adds r0, r4, #0
	movs r1, #5
	bl Proc_Goto
	ldr r0, [r4, #0x50]
	adds r0, #0x2a
	strb r6, [r0]
	ldr r0, .L0807A9D4 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	adds r5, r4, #0
	adds r5, #0x30
	adds r6, r4, #0
	adds r6, #0x36
	cmp r0, #0
	bge .L0807A9CC
	b .L0807AB76
.L0807A9CC:
	movs r0, #0x6a
	bl m4aSongNumStart
	b .L0807AB76
	.align 2, 0
.L0807A9D4: .4byte gPlaySt
.L0807A9D8:
	ldr r0, .L0807A9F4 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	adds r5, r4, #0
	adds r5, #0x30
	adds r6, r4, #0
	adds r6, #0x36
	cmp r0, #0
	bge .L0807A9EC
	b .L0807AB76
.L0807A9EC:
	movs r0, #0x6c
	bl m4aSongNumStart
	b .L0807AB76
	.align 2, 0
.L0807A9F4: .4byte gPlaySt
.L0807A9F8:
	ldr r1, [r2]
	movs r3, #0x80
	adds r0, r3, #0
	ldrh r6, [r1, #6]
	ands r0, r6
	cmp r0, #0
	bne .L0807AA16
	adds r0, r3, #0
	ldrh r1, [r1, #0x10]
	ands r0, r1
	cmp r0, #0
	beq .L0807AA70
	ldrb r0, [r5]
	cmp r0, #2
	bne .L0807AA70
.L0807AA16:
	adds r1, r4, #0
	adds r1, #0x3c
	ldrb r2, [r1]
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq .L0807AA44
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq .L0807AA44
	strb r0, [r1]
	ldr r0, .L0807AA40 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	adds r5, r4, #0
	adds r5, #0x30
	adds r6, r4, #0
	adds r6, #0x36
	b .L0807AAE6
	.align 2, 0
.L0807AA40: .4byte gPlaySt
.L0807AA44:
	adds r0, r4, #0
	adds r0, #0x30
	ldrb r3, [r0]
	adds r3, #2
	adds r2, r4, #0
	adds r2, #0x2d
	adds r5, r0, #0
	adds r6, r4, #0
	adds r6, #0x36
	ldrb r2, [r2]
	cmp r3, r2
	blt .L0807AA5E
	b .L0807AB76
.L0807AA5E:
	strb r3, [r5]
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	movs r0, #1
	ldrb r2, [r1]
	ands r0, r2
	strb r0, [r1]
	b .L0807AB76
.L0807AA70:
	ldr r1, [r2]
	movs r3, #0x40
	adds r0, r3, #0
	ldrh r6, [r1, #6]
	ands r0, r6
	cmp r0, #0
	bne .L0807AA8E
	adds r0, r3, #0
	ldrh r6, [r1, #0x10]
	ands r0, r6
	cmp r0, #0
	beq .L0807AB10
	ldrb r5, [r5]
	cmp r5, #2
	bne .L0807AB10
.L0807AA8E:
	adds r7, r4, #0
	adds r7, #0x3c
	ldrb r2, [r7]
	movs r0, #1
	mov ip, r0
	ands r0, r2
	adds r6, r4, #0
	adds r6, #0x36
	cmp r0, #0
	beq .L0807AAF8
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r0, #0
	bne .L0807AAF8
	adds r0, r4, #0
	adds r0, #0x44
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0807AAF8
	adds r0, r3, #0
	ldrh r1, [r1, #8]
	ands r0, r1
	adds r5, r4, #0
	adds r5, #0x30
	cmp r0, #0
	beq .L0807AB76
	adds r0, r4, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq .L0807AB76
	adds r1, r4, #0
	adds r1, #0x2c
	mov r0, ip
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne .L0807AB76
	movs r0, #2
	orrs r0, r2
	strb r0, [r7]
	ldr r0, .L0807AAF4 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
.L0807AAE6:
	cmp r0, #0
	blt .L0807AB76
	movs r0, #0x66
	bl m4aSongNumStart
	b .L0807AB76
	.align 2, 0
.L0807AAF4: .4byte gPlaySt
.L0807AAF8:
	adds r0, r4, #0
	adds r0, #0x30
	ldrb r1, [r0]
	subs r1, #2
	adds r5, r0, #0
	cmp r1, #0
	blt .L0807AB76
	strb r1, [r5]
	ldrb r0, [r6]
	subs r0, #1
	strb r0, [r6]
	b .L0807AB76
.L0807AB10:
	ldr r0, [r2]
	ldrh r1, [r0, #6]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq .L0807AB40
	adds r1, r4, #0
	adds r1, #0x30
	ldrb r2, [r1]
	movs r0, #1
	ands r0, r2
	adds r5, r1, #0
	adds r6, r4, #0
	adds r6, #0x36
	cmp r0, #0
	beq .L0807AB76
	adds r1, #0xc
	movs r0, #3
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #3
	beq .L0807AB76
	subs r0, r2, #1
	b .L0807AB74
.L0807AB40:
	movs r0, #0x10
	ands r0, r1
	adds r5, r4, #0
	adds r5, #0x30
	adds r6, r4, #0
	adds r6, #0x36
	cmp r0, #0
	beq .L0807AB76
	adds r1, r4, #0
	adds r1, #0x3c
	movs r0, #3
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #3
	beq .L0807AB76
	ldrb r1, [r5]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L0807AB76
	adds r0, r1, #1
	adds r1, r4, #0
	adds r1, #0x2d
	ldrb r1, [r1]
	cmp r0, r1
	bge .L0807AB76
.L0807AB74:
	strb r0, [r5]
.L0807AB76:
	ldrb r2, [r5]
	cmp r2, r8
	beq .L0807ABA4
	adds r0, r4, #0
	bl func_fe6_080798EC
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	beq .L0807AB8C
	bl Proc_End
.L0807AB8C:
	adds r0, r4, #0
	bl func_fe6_08079D70
	str r0, [r4, #0x5c]
	ldr r0, .L0807ABCC @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807ABA4
	movs r0, #0x66
	bl m4aSongNumStart
.L0807ABA4:
	ldrb r0, [r6]
	cmp r0, #6
	bne .L0807ABD0
	ldrb r2, [r5]
	adds r2, #2
	asrs r2, r2, #1
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	subs r0, #1
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	cmp r2, r0
	bgt .L0807ABD0
	movs r0, #5
	strb r0, [r6]
	movs r0, #1
	b .L0807ABEA
	.align 2, 0
.L0807ABCC: .4byte gPlaySt
.L0807ABD0:
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r0, #0
	bne .L0807ABE8
	ldrb r5, [r5]
	lsrs r0, r5, #1
	cmp r0, #0
	beq .L0807ABE8
	movs r0, #1
	strb r0, [r6]
	subs r0, #2
	b .L0807ABEA
.L0807ABE8:
	movs r0, #0
.L0807ABEA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0807ABF4
func_fe6_0807ABF4: @ 0x0807ABF4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r1, r6, #0
	adds r1, #0x44
	ldrh r0, [r1]
	lsrs r4, r0, #4
	adds r2, r6, #0
	adds r2, #0x31
	ldrb r0, [r2]
	adds r3, r6, #0
	adds r3, #0x30
	strb r0, [r3]
	movs r0, #0xff
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0x40
	ldrh r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	beq .L0807AC2A
	ldrb r0, [r3]
	lsrs r1, r0, #1
	cmp r1, r4
	ble .L0807AC38
	adds r0, r4, #6
	cmp r1, r0
	bge .L0807AC38
.L0807AC2A:
	ldrb r3, [r3]
	lsrs r0, r3, #1
	subs r0, r0, r4
	adds r1, r6, #0
	adds r1, #0x36
	strb r0, [r1]
	b .L0807AC8E
.L0807AC38:
	adds r0, r6, #0
	adds r0, #0x40
	ldrh r0, [r0]
	adds r4, r6, #0
	adds r4, #0x44
	strh r0, [r4]
	adds r0, r6, #0
	adds r0, #0x37
	ldrb r0, [r0]
	adds r1, r6, #0
	adds r1, #0x36
	strb r0, [r1]
	ldr r0, .L0807AC94 @ =gBg2Tm
	movs r1, #0
	bl TmFill
	ldr r1, .L0807AC98 @ =0x0000FF80
	ldrh r2, [r4]
	subs r2, #0x28
	movs r0, #0xff
	ands r2, r0
	movs r0, #2
	bl SetBgOffset
	ldrh r1, [r4]
	lsrs r5, r1, #4
	adds r0, r5, #7
	cmp r5, r0
	bge .L0807AC88
.L0807AC72:
	lsls r1, r5, #0x18
	lsrs r1, r1, #0x18
	adds r0, r6, #0
	bl func_fe6_08079F50
	adds r5, #1
	ldrh r1, [r4]
	lsrs r0, r1, #4
	adds r0, #7
	cmp r5, r0
	blt .L0807AC72
.L0807AC88:
	movs r0, #4
	bl EnableBgSync
.L0807AC8E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0807AC94: .4byte gBg2Tm
.L0807AC98: .4byte 0x0000FF80

	thumb_func_start func_fe6_0807AC9C
func_fe6_0807AC9C: @ 0x0807AC9C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r6, #0
	adds r7, #0x35
	ldrb r5, [r7]
	cmp r5, #0
	bne .L0807ACB2
	movs r1, #6
	bl Proc_Goto
	b .L0807ACCC
.L0807ACB2:
	cmp r5, #1
	bne .L0807ACCC
	adds r0, r6, #0
	bl func_fe6_0807ABF4
	adds r0, r6, #0
	adds r0, #0x29
	movs r4, #0
	strb r5, [r0]
	adds r0, r6, #0
	bl func_fe6_08079D84
	strb r4, [r7]
.L0807ACCC:
	ldr r0, .L0807ACE4 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807ACDC
	movs r0, #0x6b
	bl m4aSongNumStart
.L0807ACDC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0807ACE4: .4byte gPlaySt

	thumb_func_start func_fe6_0807ACE8
func_fe6_0807ACE8: @ 0x0807ACE8
	push {lr}
	ldr r0, [r0, #0x50]
	movs r1, #2
	bl Proc_Goto
	bl EndGreenText
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0807ACFC
func_fe6_0807ACFC: @ 0x0807ACFC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	ldr r2, .L0807AD68 @ =gDispIo
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r1, [r2, #1]
	ands r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #2
	ands r0, r1
	subs r1, #4
	ands r0, r1
	subs r1, #8
	ands r0, r1
	strb r0, [r2, #1]
	movs r4, #1
.L0807AD22:
	adds r0, r4, #0
	bl GetUnit
	adds r1, r0, #0
	cmp r1, #0
	beq .L0807AD44
	ldr r0, [r1]
	cmp r0, #0
	beq .L0807AD44
	movs r0, #4
	ldrh r1, [r1, #0xc]
	ands r0, r1
	cmp r0, #0
	bne .L0807AD44
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
.L0807AD44:
	adds r4, #1
	cmp r4, #0x3f
	ble .L0807AD22
	cmp r5, #0
	bne .L0807AD62
	str r5, [r6, #0x58]
	adds r1, r6, #0
	adds r1, #0x3e
	movs r0, #1
	strb r0, [r1]
	adds r0, r6, #0
	movs r1, #0xb
	bl Proc_Goto
	str r5, [r6, #0x50]
.L0807AD62:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0807AD68: .4byte gDispIo

	thumb_func_start func_fe6_0807AD6C
func_fe6_0807AD6C: @ 0x0807AD6C
	push {lr}
	bl func_fe6_0807A84C
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0807AD78
func_fe6_0807AD78: @ 0x0807AD78
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	adds r0, #0x35
	ldrb r2, [r0]
	subs r0, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	str r0, [sp]
	str r2, [sp, #4]
	adds r5, r6, #0
	adds r5, #0x29
	ldrb r4, [r5]
	cmp r4, #0
	beq .L0807ADA6
	cmp r4, #1
	bne .L0807ADA4
	b .L0807AF30
.L0807ADA4:
	b .L0807B0BC
.L0807ADA6:
	adds r0, r6, #0
	adds r0, #0x3d
	ldrb r1, [r0]
	mov sb, r0
	ldr r2, .L0807ADCC @ =gKeySt
	cmp r1, #0
	beq .L0807ADD0
	ldr r1, [r2]
	movs r0, #0x81
	lsls r0, r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L0807ADD0
	bl CloseHelpBox
	mov r0, sb
	strb r4, [r0]
	b .L0807B0BC
	.align 2, 0
.L0807ADCC: .4byte gKeySt
.L0807ADD0:
	ldr r1, [r2]
	ldrh r3, [r1, #8]
	movs r0, #1
	ands r0, r3
	cmp r0, #0
	beq .L0807AE0C
	mov r1, sb
	ldrb r0, [r1]
	adds r4, r6, #0
	adds r4, #0x35
	cmp r0, #0
	bne .L0807AECC
	adds r0, r6, #0
	bl func_fe6_0807CCC4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0807AECC
	ldr r0, .L0807AE08 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807AECC
	movs r0, #0x6c
	bl m4aSongNumStart
	b .L0807AECC
	.align 2, 0
.L0807AE08: .4byte gPlaySt
.L0807AE0C:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r3
	cmp r0, #0
	beq .L0807AE2A
	mov r2, sb
	ldrb r0, [r2]
	adds r4, r6, #0
	adds r4, #0x35
	cmp r0, #0
	bne .L0807AECC
	adds r0, r6, #0
	bl func_fe6_0807CDF4
	b .L0807AECC
.L0807AE2A:
	ldrh r1, [r1, #6]
	movs r0, #0x40
	mov ip, r0
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	cmp r0, #0
	beq .L0807AE6E
	adds r0, r6, #0
	adds r0, #0x35
	ldrb r5, [r0]
	adds r7, r6, #0
	adds r7, #0x33
	adds r2, r7, r5
	ldrb r1, [r2]
	adds r4, r0, #0
	cmp r1, #0
	beq .L0807AE56
	subs r0, r1, #1
	strb r0, [r2]
	b .L0807AECC
.L0807AE56:
	mov r0, ip
	ands r0, r3
	cmp r0, #0
	beq .L0807AECC
	adds r0, r5, #0
	bl func_fe6_0807CD24
	ldrb r2, [r4]
	adds r1, r2, r7
	subs r0, #1
	strb r0, [r1]
	b .L0807AECC
.L0807AE6E:
	movs r0, #0x80
	mov sl, r0
	ands r0, r1
	cmp r0, #0
	beq .L0807AEBA
	adds r4, r6, #0
	adds r4, #0x35
	ldrb r0, [r4]
	adds r7, r6, #0
	adds r7, #0x33
	adds r1, r7, r0
	ldrb r5, [r1]
	str r2, [sp, #8]
	bl func_fe6_0807CD24
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	subs r0, #1
	ldr r2, [sp, #8]
	cmp r5, r0
	bge .L0807AEA4
	ldrb r2, [r4]
	adds r1, r2, r7
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b .L0807AECC
.L0807AEA4:
	ldr r1, [r2]
	mov r0, sl
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L0807AECC
	ldrb r1, [r4]
	adds r0, r1, r7
	mov r2, r8
	strb r2, [r0]
	b .L0807AECC
.L0807AEBA:
	movs r0, #2
	ands r0, r3
	adds r4, r6, #0
	adds r4, #0x35
	cmp r0, #0
	beq .L0807AECC
	adds r0, r6, #0
	bl func_fe6_0807AC9C
.L0807AECC:
	adds r1, r4, #0
	ldr r0, [sp, #4]
	ldrb r2, [r1]
	cmp r0, r2
	beq .L0807AED8
	b .L0807B0BC
.L0807AED8:
	adds r0, r6, #0
	adds r0, #0x33
	adds r0, r2, r0
	ldr r1, [sp]
	ldrb r0, [r0]
	cmp r1, r0
	bne .L0807AEE8
	b .L0807B0BC
.L0807AEE8:
	mov r2, sb
	ldrb r0, [r2]
	cmp r0, #0
	beq .L0807AEF6
	adds r0, r6, #0
	bl func_fe6_0807CDF4
.L0807AEF6:
	ldrb r4, [r4]
	cmp r4, #1
	bne .L0807AF18
	ldr r4, [r6, #0x50]
	adds r0, r6, #0
	adds r0, #0x34
	ldrb r0, [r0]
	movs r1, #1
	bl func_fe6_0807CF2C
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	subs r1, #5
	adds r0, r4, #0
	bl func_fe6_0807B8B0
.L0807AF18:
	ldr r0, .L0807AF2C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	bge .L0807AF24
	b .L0807B0BC
.L0807AF24:
	movs r0, #0x66
	bl m4aSongNumStart
	b .L0807B0BC
	.align 2, 0
.L0807AF2C: .4byte gPlaySt
.L0807AF30:
	ldr r7, .L0807AF60 @ =gKeySt
	ldr r0, [r7]
	ldrh r1, [r0, #8]
	adds r3, r1, #0
	ands r3, r4
	cmp r3, #0
	beq .L0807AF68
	adds r0, r6, #0
	bl func_fe6_0807CCC4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0807AF4C
	b .L0807B0BC
.L0807AF4C:
	ldr r0, .L0807AF64 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	bge .L0807AF58
	b .L0807B0BC
.L0807AF58:
	movs r0, #0x6c
	bl m4aSongNumStart
	b .L0807B0BC
	.align 2, 0
.L0807AF60: .4byte gKeySt
.L0807AF64: .4byte gPlaySt
.L0807AF68:
	movs r4, #2
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq .L0807B010
	adds r0, r2, #0
	cmp r0, #0
	bne .L0807AFB6
	ldr r0, .L0807AFA8 @ =gBg0Tm+0x28
	movs r1, #0xa
	movs r2, #3
	movs r3, #0
	bl TmFillRect_thm
	movs r0, #1
	bl EnableBgSync
	adds r1, r6, #0
	adds r1, #0x3c
	adds r0, r4, #0
	ldrb r2, [r1]
	ands r0, r2
	strb r0, [r1]
	adds r2, r6, #0
	adds r2, #0x31
	ldrb r1, [r2]
	adds r0, r1, #0
	cmp r0, #0xff
	beq .L0807AFAC
	movs r0, #0xff
	strb r0, [r2]
	b .L0807AFF8
	.align 2, 0
.L0807AFA8: .4byte gBg0Tm+0x28
.L0807AFAC:
	adds r0, r6, #0
	movs r1, #0xa
	bl Proc_Goto
	b .L0807AFF8
.L0807AFB6:
	cmp r0, #1
	bne .L0807AFF8
	strb r3, [r5]
	ldr r4, [r6, #0x50]
	adds r0, r6, #0
	adds r0, #0x34
	ldrb r0, [r0]
	movs r1, #1
	bl func_fe6_0807CF2C
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	subs r1, #5
	adds r0, r4, #0
	bl func_fe6_0807B8B0
	adds r0, r6, #0
	bl func_fe6_08079A94
	adds r1, r6, #0
	adds r1, #0x30
	ldrb r0, [r1]
	adds r2, r6, #0
	adds r2, #0x32
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0x31
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r6, #0
	bl func_fe6_080798EC
.L0807AFF8:
	ldr r0, .L0807B00C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807B0BC
	movs r0, #0x6b
	bl m4aSongNumStart
	b .L0807B0BC
	.align 2, 0
.L0807B00C: .4byte gPlaySt
.L0807B010:
	adds r0, r6, #0
	bl func_fe6_0807A940
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r0, #0
	beq .L0807B040
	lsls r0, r1, #0x18
	asrs r4, r0, #0x18
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	bne .L0807B032
	adds r0, r6, #0
	movs r1, #7
	bl Proc_Goto
.L0807B032:
	cmp r4, #1
	bne .L0807B0BC
	adds r0, r6, #0
	movs r1, #8
	bl Proc_Goto
	b .L0807B0BC
.L0807B040:
	ldr r1, [r7]
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L0807B06E
	adds r1, r6, #0
	adds r1, #0x3c
	movs r0, #3
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #3
	beq .L0807B06E
	adds r1, r6, #0
	adds r1, #0x3b
	movs r0, #6
	strb r0, [r1]
	adds r0, r6, #0
	movs r1, #3
	bl Proc_Goto
	b .L0807B0BC
.L0807B06E:
	ldr r0, .L0807B0CC @ =gKeySt
	ldr r1, [r0]
	movs r0, #4
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L0807B0BC
	adds r0, r6, #0
	adds r0, #0x35
	ldrb r0, [r0]
	cmp r0, #1
	beq .L0807B0BC
	ldr r2, .L0807B0D0 @ =0x0200E7D8
	ldr r1, .L0807B0D4 @ =0x0200E6D4
	adds r0, r6, #0
	adds r0, #0x30
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	str r0, [r2]
	ldr r0, .L0807B0D8 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807B0AC
	movs r0, #0x6a
	bl m4aSongNumStart
.L0807B0AC:
	adds r1, r6, #0
	adds r1, #0x3b
	movs r0, #9
	strb r0, [r1]
	adds r0, r6, #0
	movs r1, #0xd
	bl Proc_Goto
.L0807B0BC:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0807B0CC: .4byte gKeySt
.L0807B0D0: .4byte 0x0200E7D8
.L0807B0D4: .4byte 0x0200E6D4
.L0807B0D8: .4byte gPlaySt

	thumb_func_start func_fe6_0807B0DC
func_fe6_0807B0DC: @ 0x0807B0DC
	adds r0, #0x3e
	movs r1, #1
	strb r1, [r0]
	bx lr

	thumb_func_start func_fe6_0807B0E4
func_fe6_0807B0E4: @ 0x0807B0E4
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x3e
	ldrb r0, [r0]
	cmp r0, #0
	beq .L0807B0FA
	bl func_fe6_08079A28
	bl func_fe6_0802B7E4
	b .L0807B10C
.L0807B0FA:
	adds r1, r4, #0
	adds r1, #0x2c
	movs r0, #1
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq .L0807B10C
	bl func_fe6_08036994
.L0807B10C:
	bl EndGreenText
	ldr r0, [r4, #0x58]
	bl Proc_End
	ldr r0, [r4, #0x50]
	cmp r0, #0
	beq .L0807B122
	movs r1, #5
	bl Proc_Goto
.L0807B122:
	bl InitPlayerDeployUnitPositions
	bl ResetUnitSprites
	bl RefreshEntityMaps
	bl RefreshUnitSprites
	ldr r3, .L0807B170 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0xc0
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	movs r1, #0
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r1, r3, #0
	adds r1, #0x46
	movs r0, #0x10
	strb r0, [r1]
	ldr r0, .L0807B174 @ =0x0000FFE0
	ldrh r1, [r3, #0x3c]
	ands r0, r1
	movs r1, #0x1f
	orrs r0, r1
	strh r0, [r3, #0x3c]
	movs r0, #0x20
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0807B170: .4byte gDispIo
.L0807B174: .4byte 0x0000FFE0

	thumb_func_start func_fe6_0807B178
func_fe6_0807B178: @ 0x0807B178
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x44
	ldrh r1, [r6]
	movs r4, #0xf
	adds r0, r1, #0
	ands r0, r4
	cmp r0, #0
	bne .L0807B19A
	lsrs r1, r1, #4
	subs r1, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r5, #0
	bl func_fe6_08079F50
.L0807B19A:
	adds r0, r5, #0
	adds r0, #0x3f
	ldrb r0, [r0]
	lsls r0, r0, #2
	ldrh r1, [r6]
	subs r0, r1, r0
	strh r0, [r6]
	adds r0, r4, #0
	ldrh r1, [r6]
	ands r0, r1
	cmp r0, #0
	bne .L0807B1F4
	adds r0, r5, #0
	bl func_fe6_0807A940
	lsls r0, r0, #0x18
	asrs r4, r0, #0x18
	cmp r4, #0
	bne .L0807B1C8
	adds r0, r5, #0
	movs r1, #1
	bl Proc_Goto
.L0807B1C8:
	cmp r4, #1
	bne .L0807B1D4
	adds r0, r5, #0
	movs r1, #8
	bl Proc_Goto
.L0807B1D4:
	ldrh r6, [r6]
	lsrs r0, r6, #3
	adds r0, #0xe
	movs r1, #0x1f
	ands r0, r1
	lsls r0, r0, #6
	ldr r1, .L0807B1FC @ =gBg2Tm
	adds r0, r0, r1
	movs r1, #0xc
	movs r2, #1
	movs r3, #0
	bl TmFillRect_thm
	movs r0, #4
	bl EnableBgSync
.L0807B1F4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0807B1FC: .4byte gBg2Tm

	thumb_func_start func_fe6_0807B200
func_fe6_0807B200: @ 0x0807B200
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0x44
	ldrh r1, [r6]
	movs r5, #0xf
	adds r0, r1, #0
	ands r0, r5
	cmp r0, #0
	bne .L0807B222
	lsrs r1, r1, #4
	adds r1, #7
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl func_fe6_08079F50
.L0807B222:
	adds r0, r4, #0
	adds r0, #0x3f
	ldrb r0, [r0]
	lsls r0, r0, #2
	ldrh r1, [r6]
	adds r0, r1, r0
	strh r0, [r6]
	adds r0, r5, #0
	ldrh r1, [r6]
	ands r0, r1
	cmp r0, #0
	bne .L0807B280
	adds r0, r4, #0
	bl func_fe6_0807A940
	lsls r0, r0, #0x18
	asrs r5, r0, #0x18
	cmp r5, #0
	bne .L0807B250
	adds r0, r4, #0
	movs r1, #1
	bl Proc_Goto
.L0807B250:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r5, r0
	bne .L0807B260
	adds r0, r4, #0
	movs r1, #7
	bl Proc_Goto
.L0807B260:
	ldrh r6, [r6]
	lsrs r0, r6, #3
	subs r0, #2
	movs r1, #0x1f
	ands r0, r1
	lsls r0, r0, #6
	ldr r1, .L0807B288 @ =gBg2Tm
	adds r0, r0, r1
	movs r1, #0xc
	movs r2, #1
	movs r3, #0
	bl TmFillRect_thm
	movs r0, #4
	bl EnableBgSync
.L0807B280:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0807B288: .4byte gBg2Tm

	thumb_func_start func_fe6_0807B28C
func_fe6_0807B28C: @ 0x0807B28C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	subs r0, #2
	cmp r0, #8
	bls .L0807B29C
	b .L0807B3C4
.L0807B29C:
	lsls r0, r0, #2
	ldr r1, .L0807B2A8 @ =.L0807B2AC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0807B2A8: .4byte .L0807B2AC
.L0807B2AC: @ jump table
	.4byte .L0807B2D0 @ case 0
	.4byte .L0807B2DE @ case 1
	.4byte .L0807B2D6 @ case 2
	.4byte .L0807B2E4 @ case 3
	.4byte .L0807B380 @ case 4
	.4byte .L0807B308 @ case 5
	.4byte .L0807B2F4 @ case 6
	.4byte .L0807B328 @ case 7
	.4byte .L0807B336 @ case 8
.L0807B2D0:
	adds r0, r4, #0
	movs r1, #2
	b .L0807B2E8
.L0807B2D6:
	adds r0, r4, #0
	bl func_fe6_08081E3C
	b .L0807B2EC
.L0807B2DE:
	adds r0, r4, #0
	movs r1, #4
	b .L0807B2E8
.L0807B2E4:
	adds r0, r4, #0
	movs r1, #0
.L0807B2E8:
	bl func_fe6_080815BC
.L0807B2EC:
	adds r0, r4, #0
	bl func_fe6_0807ACE8
	b .L0807B3C4
.L0807B2F4:
	ldr r0, [r4, #0x58]
	bl Proc_End
	ldr r0, .L0807B304 @ =ProcScr_Unk_0868B010
	adds r1, r4, #0
	bl SpawnProcLocking
	b .L0807B350
	.align 2, 0
.L0807B304: .4byte ProcScr_Unk_0868B010
.L0807B308:
	ldr r0, [r4, #0x58]
	bl Proc_End
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0x80
	movs r2, #0x20
	movs r3, #0
	bl StartBgmVolumeChange
	bl InitPlayerDeployUnitPositions
	adds r0, r4, #0
	bl func_fe6_08089234
	b .L0807B350
.L0807B328:
	ldr r0, [r4, #0x58]
	bl Proc_End
	adds r0, r4, #0
	bl func_fe6_08076250
	b .L0807B350
.L0807B336:
	ldr r0, [r4, #0x58]
	bl Proc_End
	ldr r1, .L0807B378 @ =0x0200E6D4
	adds r0, r4, #0
	adds r0, #0x30
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r4, #0
	bl func_fe6_08095DF0
.L0807B350:
	adds r0, r4, #0
	bl func_fe6_0807ACE8
	ldr r2, .L0807B37C @ =gDispIo
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r1, [r2, #1]
	ands r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #2
	ands r0, r1
	subs r1, #4
	ands r0, r1
	subs r1, #8
	ands r0, r1
	strb r0, [r2, #1]
	b .L0807B3C4
	.align 2, 0
.L0807B378: .4byte 0x0200E6D4
.L0807B37C: .4byte gDispIo
.L0807B380:
	ldr r0, [r4, #0x58]
	bl Proc_End
	adds r0, r4, #0
	bl func_fe6_0807ACE8
	ldr r2, .L0807B3D0 @ =gDispIo
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r1, [r2, #1]
	ands r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #2
	ands r0, r1
	subs r1, #4
	ands r0, r1
	subs r1, #8
	ands r0, r1
	strb r0, [r2, #1]
	movs r0, #4
	bl SetStatScreenExcludedUnitFlags
	ldr r1, .L0807B3D4 @ =0x0200E6D4
	adds r0, r4, #0
	adds r0, #0x30
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r4, #0
	bl StartStatScreen
.L0807B3C4:
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0807B3D0: .4byte gDispIo
.L0807B3D4: .4byte 0x0200E6D4

	thumb_func_start func_fe6_0807B3D8
func_fe6_0807B3D8: @ 0x0807B3D8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	subs r0, #2
	cmp r0, #8
	bhi .L0807B466
	lsls r0, r0, #2
	ldr r1, .L0807B3F0 @ =.L0807B3F4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0807B3F0: .4byte .L0807B3F4
.L0807B3F4: @ jump table
	.4byte .L0807B418 @ case 0
	.4byte .L0807B418 @ case 1
	.4byte .L0807B418 @ case 2
	.4byte .L0807B418 @ case 3
	.4byte .L0807B458 @ case 4
	.4byte .L0807B432 @ case 5
	.4byte .L0807B458 @ case 6
	.4byte .L0807B458 @ case 7
	.4byte .L0807B440 @ case 8
.L0807B418:
	adds r0, r4, #0
	bl func_fe6_0807A268
	ldr r0, [r4, #0x50]
	movs r1, #0
	bl Proc_Goto
	movs r1, #1
	rsbs r1, r1, #0
	adds r0, r4, #0
	bl func_fe6_080829E8
	b .L0807B466
.L0807B432:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x80
	movs r2, #0x20
	movs r3, #0
	bl StartBgmVolumeChange
.L0807B440:
	movs r0, #0x22
	movs r1, #0
	bl StartBgm
	adds r0, r4, #0
	bl func_fe6_0807A59C
	ldr r0, [r4, #0x50]
	movs r1, #0
	bl Proc_Goto
	b .L0807B466
.L0807B458:
	adds r0, r4, #0
	bl func_fe6_0807A59C
	ldr r0, [r4, #0x50]
	movs r1, #0
	bl Proc_Goto
.L0807B466:
	adds r0, r4, #0
	adds r0, #0x3b
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #6
	bne .L0807B47C
	adds r0, r4, #0
	movs r1, #0xf
	bl Proc_Goto
	b .L0807B490
.L0807B47C:
	cmp r1, #6
	bls .L0807B48A
	adds r0, r4, #0
	movs r1, #0xc
	bl Proc_Goto
	b .L0807B490
.L0807B48A:
	adds r0, r4, #0
	bl Proc_Break
.L0807B490:
	movs r0, #0
	strb r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0807B49C
func_fe6_0807B49C: @ 0x0807B49C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, .L0807B4BC @ =0x0200E6D4
	adds r0, #0x30
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl func_fe6_080796B0
	adds r4, #0x42
	movs r0, #0
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0807B4BC: .4byte 0x0200E6D4

	thumb_func_start func_fe6_0807B4C0
func_fe6_0807B4C0: @ 0x0807B4C0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov r8, r0
	mov r5, r8
	adds r5, #0x42
	ldrh r0, [r5]
	cmp r0, #0
	bne .L0807B50C
	mov r1, r8
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	mov r0, r8
	bl func_fe6_0807A67C
	ldr r0, .L0807B594 @ =gBg0Tm
	movs r1, #0xc
	movs r2, #0x13
	movs r3, #0
	bl TmFillRect_thm
	ldr r0, .L0807B598 @ =gBg1Tm
	movs r1, #0xc
	movs r2, #0x13
	movs r3, #0
	bl TmFillRect_thm
	mov r0, r8
	bl func_fe6_08079D84
.L0807B50C:
	ldrh r4, [r5]
	adds r4, #0x10
	ldrh r0, [r5]
	movs r1, #0xc
	bl __udivsi3
	subs r4, r4, r0
	strh r4, [r5]
	lsls r4, r4, #0x10
	lsrs r7, r4, #0x13
	movs r0, #0
	rsbs r1, r7, #0
	str r1, [sp]
.L0807B526:
	adds r1, r0, #1
	mov ip, r1
	cmp r7, #0
	beq .L0807B56C
	ldr r3, .L0807B59C @ =0x0200E8A4
	adds r2, r0, #0
	adds r2, #0xa
	lsls r2, r2, #6
	ldr r1, [sp]
	adds r1, #0xd
	lsls r4, r0, #6
	ldr r0, .L0807B598 @ =gBg1Tm
	mov sl, r0
	ldr r0, .L0807B594 @ =gBg0Tm
	mov sb, r0
	adds r6, r7, #0
	lsls r1, r1, #1
	adds r0, r4, r3
	adds r5, r1, r0
	adds r2, r2, r3
	adds r2, r1, r2
.L0807B550:
	mov r0, sl
	adds r1, r4, r0
	ldrh r0, [r2]
	strh r0, [r1]
	mov r0, sb
	adds r1, r4, r0
	ldrh r0, [r5]
	strh r0, [r1]
	adds r5, #2
	adds r2, #2
	adds r4, #2
	subs r6, #1
	cmp r6, #0
	bne .L0807B550
.L0807B56C:
	mov r0, ip
	cmp r0, #7
	ble .L0807B526
	movs r0, #3
	bl EnableBgSync
	cmp r7, #0xc
	ble .L0807B582
	mov r0, r8
	bl Proc_Break
.L0807B582:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0807B594: .4byte gBg0Tm
.L0807B598: .4byte gBg1Tm
.L0807B59C: .4byte 0x0200E8A4

	thumb_func_start func_fe6_0807B5A0
func_fe6_0807B5A0: @ 0x0807B5A0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x42
	ldrh r1, [r5]
	cmp r1, #0
	bne .L0807B5BA
	adds r0, #0x2b
	strb r1, [r0]
.L0807B5BA:
	ldrh r4, [r5]
	adds r4, #0x10
	ldrh r0, [r5]
	movs r1, #0xc
	bl __udivsi3
	subs r4, r4, r0
	strh r4, [r5]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x13
	mov sl, r4
	movs r2, #0
	movs r0, #0xd
	mov r1, sl
	subs r1, r0, r1
	mov r8, r1
	movs r3, #0
	mov sb, r3
	mov r0, sl
	lsls r7, r0, #1
.L0807B5E2:
	movs r5, #0
	lsls r1, r2, #6
	adds r3, r2, #1
	mov ip, r3
	adds r0, r7, r1
	ldr r3, .L0807B610 @ =0x0200E8A4
	adds r4, r0, r3
	ldr r0, .L0807B614 @ =gBg0Tm
	adds r3, r1, r0
	ldr r0, .L0807B618 @ =gBg1Tm
	adds r1, r1, r0
	adds r0, r2, #0
	adds r0, #0xa
	lsls r0, r0, #6
	ldr r2, .L0807B610 @ =0x0200E8A4
	adds r0, r0, r2
	adds r2, r7, r0
.L0807B604:
	cmp r5, r8
	blt .L0807B61C
	mov r0, sb
	strh r0, [r1]
	b .L0807B622
	.align 2, 0
.L0807B610: .4byte 0x0200E8A4
.L0807B614: .4byte gBg0Tm
.L0807B618: .4byte gBg1Tm
.L0807B61C:
	ldrh r0, [r2]
	strh r0, [r1]
	ldrh r0, [r4]
.L0807B622:
	strh r0, [r3]
	adds r4, #2
	adds r3, #2
	adds r2, #2
	adds r1, #2
	adds r5, #1
	cmp r5, #0xc
	ble .L0807B604
	mov r2, ip
	cmp r2, #7
	ble .L0807B5E2
	movs r0, #3
	bl EnableBgSync
	mov r1, sl
	cmp r1, #0xc
	ble .L0807B68A
	adds r1, r6, #0
	adds r1, #0x29
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r0, r6, #0
	bl func_fe6_08079A94
	adds r0, r6, #0
	bl Proc_Break
	ldr r1, .L0807B698 @ =0x0200E6D4
	adds r0, r6, #0
	adds r0, #0x30
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r4, [r0, #4]
	bl func_fe6_08079A28
	adds r0, r6, #0
	movs r1, #0
	bl func_fe6_0807A1C8
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #1
	bl func_fe6_08079928
	adds r0, r6, #0
	bl func_fe6_0807A67C
.L0807B68A:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0807B698: .4byte 0x0200E6D4

	thumb_func_start func_fe6_0807B69C
func_fe6_0807B69C: @ 0x0807B69C
	ldr r2, .L0807B6B8 @ =gDispIo
	movs r0, #1
	ldrb r1, [r2, #1]
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	movs r1, #8
	orrs r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #1]
	bx lr
	.align 2, 0
.L0807B6B8: .4byte gDispIo

	thumb_func_start func_fe6_0807B6BC
func_fe6_0807B6BC: @ 0x0807B6BC
	push {lr}
	ldr r0, .L0807B6CC @ =gUnk_08678E38
	movs r1, #3
	bl SpawnProc
	pop {r0}
	bx r0
	.align 2, 0
.L0807B6CC: .4byte gUnk_08678E38

	thumb_func_start func_fe6_0807B6D0
func_fe6_0807B6D0: @ 0x0807B6D0
	push {lr}
	ldr r0, .L0807B6E8 @ =gUnk_08678E38
	movs r1, #3
	bl SpawnProc
	bl func_fe6_0807A194
	bl func_fe6_080791A0
	pop {r0}
	bx r0
	.align 2, 0
.L0807B6E8: .4byte gUnk_08678E38

	thumb_func_start func_fe6_0807B6EC
func_fe6_0807B6EC: @ 0x0807B6EC
	adds r0, #0x42
	movs r1, #0
	strh r1, [r0]
	ldr r3, .L0807B70C @ =gPal
	ldr r2, .L0807B710 @ =0x020100A4
	movs r1, #0x80
	lsls r1, r1, #2
.L0807B6FA:
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, #2
	adds r2, #2
	subs r1, #1
	cmp r1, #0
	bne .L0807B6FA
	bx lr
	.align 2, 0
.L0807B70C: .4byte gPal
.L0807B710: .4byte 0x020100A4

	thumb_func_start func_fe6_0807B714
func_fe6_0807B714: @ 0x0807B714
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r0
	adds r0, #0x42
	ldrb r5, [r0]
	ldr r2, .L0807B7B8 @ =gDispIo
	movs r0, #1
	ldrb r1, [r2, #1]
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	movs r1, #8
	orrs r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #1]
	movs r6, #0
	ldr r4, .L0807B7BC @ =gPal
	mov sl, r4
	movs r0, #0xf8
	lsls r0, r0, #7
	mov r8, r0
	ldr r1, .L0807B7C0 @ =0x020100A4
	mov ip, r1
.L0807B74E:
	lsls r7, r6, #1
	mov r4, ip
	ldrh r1, [r4]
	mov r0, r8
	ands r0, r1
	muls r0, r5, r0
	asrs r2, r0, #4
	mov r0, r8
	ands r2, r0
	movs r4, #0xf8
	lsls r4, r4, #2
	adds r0, r4, #0
	ands r0, r1
	muls r0, r5, r0
	asrs r3, r0, #4
	ands r3, r4
	movs r4, #0x1f
	adds r0, r4, #0
	ands r0, r1
	muls r0, r5, r0
	asrs r0, r0, #4
	ands r0, r4
	mov r4, sl
	adds r1, r7, r4
	orrs r2, r3
	orrs r2, r0
	strh r2, [r1]
	movs r0, #2
	add ip, r0
	adds r6, #1
	ldr r0, .L0807B7C4 @ =0x000001FF
	cmp r6, r0
	ble .L0807B74E
	bl EnablePalSync
	mov r1, sb
	adds r1, #0x42
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	cmp r5, #0x10
	bne .L0807B7A8
	mov r0, sb
	bl Proc_Break
.L0807B7A8:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0807B7B8: .4byte gDispIo
.L0807B7BC: .4byte gPal
.L0807B7C0: .4byte 0x020100A4
.L0807B7C4: .4byte 0x000001FF

	thumb_func_start func_fe6_0807B7C8
func_fe6_0807B7C8: @ 0x0807B7C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r0
	mov r1, sb
	adds r1, #0x42
	movs r0, #0x10
	ldrb r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r6, #0
	ldr r0, .L0807B878 @ =gPal
	mov sl, r0
	movs r1, #0xf8
	lsls r1, r1, #7
	mov r8, r1
	ldr r4, .L0807B87C @ =0x020100A4
	mov ip, r4
.L0807B7F2:
	lsls r7, r6, #1
	mov r0, ip
	ldrh r1, [r0]
	mov r0, r8
	ands r0, r1
	muls r0, r5, r0
	asrs r2, r0, #4
	mov r4, r8
	ands r2, r4
	movs r4, #0xf8
	lsls r4, r4, #2
	adds r0, r4, #0
	ands r0, r1
	muls r0, r5, r0
	asrs r3, r0, #4
	ands r3, r4
	movs r4, #0x1f
	adds r0, r4, #0
	ands r0, r1
	muls r0, r5, r0
	asrs r0, r0, #4
	ands r0, r4
	mov r4, sl
	adds r1, r7, r4
	orrs r2, r3
	orrs r2, r0
	strh r2, [r1]
	movs r0, #2
	add ip, r0
	adds r6, #1
	ldr r0, .L0807B880 @ =0x000001FF
	cmp r6, r0
	ble .L0807B7F2
	bl EnablePalSync
	mov r1, sb
	adds r1, #0x42
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	cmp r5, #0
	bne .L0807B86A
	ldr r2, .L0807B884 @ =gDispIo
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r1, [r2, #1]
	ands r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #2
	ands r0, r1
	subs r1, #4
	ands r0, r1
	subs r1, #8
	ands r0, r1
	strb r0, [r2, #1]
	mov r0, sb
	bl Proc_Break
.L0807B86A:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0807B878: .4byte gPal
.L0807B87C: .4byte 0x020100A4
.L0807B880: .4byte 0x000001FF
.L0807B884: .4byte gDispIo

	thumb_func_start func_fe6_0807B888
func_fe6_0807B888: @ 0x0807B888
	push {lr}
	adds r1, r0, #0
	ldr r0, .L0807B898 @ =gUnk_08679008
	bl SpawnProcLocking
	pop {r0}
	bx r0
	.align 2, 0
.L0807B898: .4byte gUnk_08679008

	thumb_func_start func_fe6_0807B89C
func_fe6_0807B89C: @ 0x0807B89C
	push {lr}
	adds r1, r0, #0
	ldr r0, .L0807B8AC @ =gUnk_08679028
	bl SpawnProcLocking
	pop {r0}
	bx r0
	.align 2, 0
.L0807B8AC: .4byte gUnk_08679028

	thumb_func_start func_fe6_0807B8B0
func_fe6_0807B8B0: @ 0x0807B8B0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r2, r0, #0
	adds r2, #0x43
	ldrb r3, [r2]
	cmp r3, r1
	beq .L0807B8C0
	strb r1, [r2]
.L0807B8C0:
	adds r1, r0, #0
	adds r1, #0x44
	movs r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0807B8CC
func_fe6_0807B8CC: @ 0x0807B8CC
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, #0x34
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #2
	strb r3, [r0]
	ldr r4, .L0807B908 @ =gPlaySt
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	bl GetChapterInfo
	adds r0, #0x3f
	ldrb r1, [r0]
	adds r0, r5, #0
	adds r0, #0x38
	strb r1, [r0]
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	bl GetChapterInfo
	adds r0, #0x40
	ldrb r1, [r0]
	adds r0, r5, #0
	adds r0, #0x39
	strb r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0807B908: .4byte gPlaySt

	thumb_func_start func_fe6_0807B90C
func_fe6_0807B90C: @ 0x0807B90C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r0, r1, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r0, r0, #0x18
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	lsrs r0, r0, #0x1b
	movs r1, #6
	bl __umodsi3
	lsls r0, r0, #0x19
	lsrs r3, r0, #0x18
	adds r5, r3, #0
	cmp r4, #0
	bne .L0807B978
	lsls r0, r6, #0x18
	asrs r2, r0, #0x18
	cmp r2, #0
	beq .L0807B960
	ldr r2, .L0807B954 @ =gBg0Tm
	ldr r1, .L0807B958 @ =0x0000F240
	adds r0, r3, r1
	movs r4, #0x94
	lsls r4, r4, #1
	adds r1, r2, r4
	strh r0, [r1]
	ldr r1, .L0807B95C @ =0x0000F241
	adds r0, r3, r1
	movs r3, #0x95
	lsls r3, r3, #1
	adds r1, r2, r3
	strh r0, [r1]
	b .L0807B9B8
	.align 2, 0
.L0807B954: .4byte gBg0Tm
.L0807B958: .4byte 0x0000F240
.L0807B95C: .4byte 0x0000F241
.L0807B960:
	ldr r1, .L0807B974 @ =gBg0Tm
	movs r4, #0x94
	lsls r4, r4, #1
	adds r0, r1, r4
	strh r2, [r0]
	movs r3, #0x95
	lsls r3, r3, #1
	adds r0, r1, r3
	b .L0807B9B6
	.align 2, 0
.L0807B974: .4byte gBg0Tm
.L0807B978:
	lsls r0, r6, #0x18
	asrs r2, r0, #0x18
	cmp r2, #0
	beq .L0807B9A8
	ldr r1, .L0807B99C @ =gBg0Tm
	ldr r4, .L0807B9A0 @ =0x0000FA40
	adds r2, r5, r4
	movs r3, #0x9d
	lsls r3, r3, #3
	adds r0, r1, r3
	strh r2, [r0]
	adds r4, #1
	adds r0, r5, r4
	ldr r2, .L0807B9A4 @ =0x000004EA
	adds r1, r1, r2
	strh r0, [r1]
	b .L0807B9B8
	.align 2, 0
.L0807B99C: .4byte gBg0Tm
.L0807B9A0: .4byte 0x0000FA40
.L0807B9A4: .4byte 0x000004EA
.L0807B9A8:
	ldr r0, .L0807B9C4 @ =gBg0Tm
	movs r3, #0x9d
	lsls r3, r3, #3
	adds r1, r0, r3
	strh r2, [r1]
	ldr r4, .L0807B9C8 @ =0x000004EA
	adds r0, r0, r4
.L0807B9B6:
	strh r2, [r0]
.L0807B9B8:
	movs r0, #1
	bl EnableBgSync
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0807B9C4: .4byte gBg0Tm
.L0807B9C8: .4byte 0x000004EA

	thumb_func_start func_fe6_0807B9CC
func_fe6_0807B9CC: @ 0x0807B9CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sl, r0
	ldr r0, [r0, #0x14]
	adds r0, #0x44
	ldrh r2, [r0]
	rsbs r1, r2, #0
	adds r0, r1, #0
	cmp r1, #0
	bge .L0807B9EA
	adds r0, #0xf
.L0807B9EA:
	asrs r0, r0, #4
	lsls r0, r0, #4
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	lsrs r0, r2, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #4]
	mov r0, sl
	adds r0, #0x40
	ldrh r0, [r0]
	cmp r0, r2
	beq .L0807BAAC
	ldr r0, .L0807BAA8 @ =gDispIo
	mov ip, r0
	movs r0, #0x20
	mov r1, ip
	ldrb r1, [r1, #1]
	orrs r0, r1
	movs r1, #0x40
	orrs r0, r1
	movs r1, #0x7f
	ands r0, r1
	mov r2, ip
	strb r0, [r2, #1]
	mov r1, ip
	adds r1, #0x35
	movs r2, #1
	ldrb r0, [r1]
	orrs r0, r2
	movs r6, #2
	orrs r0, r6
	movs r3, #5
	rsbs r3, r3, #0
	mov sb, r3
	ands r0, r3
	movs r5, #8
	orrs r0, r5
	movs r4, #0x10
	orrs r0, r4
	strb r0, [r1]
	mov r3, ip
	adds r3, #0x34
	ldrb r0, [r3]
	orrs r0, r2
	orrs r0, r6
	movs r1, #4
	orrs r0, r1
	orrs r0, r5
	orrs r0, r4
	strb r0, [r3]
	mov r0, ip
	adds r0, #0x2d
	movs r3, #0
	strb r3, [r0]
	adds r0, #4
	movs r1, #0x28
	mov r8, r1
	mov r1, r8
	strb r1, [r0]
	subs r0, #5
	movs r4, #0xf0
	strb r4, [r0]
	mov r1, ip
	adds r1, #0x30
	movs r0, #0x98
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x2f
	strb r3, [r0]
	adds r0, #4
	strb r3, [r0]
	subs r0, #5
	strb r4, [r0]
	adds r0, #4
	mov r3, r8
	strb r3, [r0]
	adds r1, #6
	ldrb r0, [r1]
	orrs r2, r0
	orrs r2, r6
	mov r3, sb
	ands r2, r3
	orrs r2, r5
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r2, r0
	strb r2, [r1]
	mov r1, sl
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	b .L0807BB2A
	.align 2, 0
.L0807BAA8: .4byte gDispIo
.L0807BAAC:
	mov r7, sl
	adds r7, #0x29
	ldrb r0, [r7]
	cmp r0, #1
	bne .L0807BB2A
	ldr r1, .L0807BBFC @ =gDispIo
	mov r8, r1
	movs r0, #0x20
	ldrb r2, [r1, #1]
	orrs r0, r2
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	mov r3, r8
	strb r0, [r3, #1]
	mov r2, r8
	adds r2, #0x35
	movs r1, #1
	ldrb r0, [r2]
	orrs r0, r1
	movs r6, #2
	orrs r0, r6
	movs r3, #4
	orrs r0, r3
	movs r5, #8
	orrs r0, r5
	movs r4, #0x10
	orrs r0, r4
	strb r0, [r2]
	subs r2, #1
	ldrb r0, [r2]
	orrs r0, r1
	orrs r0, r6
	orrs r0, r3
	orrs r0, r5
	orrs r0, r4
	strb r0, [r2]
	mov r0, r8
	adds r0, #0x2d
	movs r3, #0
	strb r3, [r0]
	subs r2, #3
	movs r0, #0x28
	strb r0, [r2]
	subs r2, #5
	movs r0, #0xf0
	strb r0, [r2]
	adds r2, #4
	movs r0, #0x98
	strb r0, [r2]
	adds r2, #6
	ldrb r0, [r2]
	orrs r1, r0
	orrs r1, r6
	movs r0, #5
	rsbs r0, r0, #0
	ands r1, r0
	orrs r1, r5
	orrs r1, r4
	strb r1, [r2]
	strb r3, [r7]
.L0807BB2A:
	mov r1, sl
	ldr r0, [r1, #0x14]
	adds r1, r0, #0
	adds r1, #0x31
	ldrb r0, [r1]
	ldr r2, [sp]
	lsls r7, r2, #0x10
	cmp r0, #0xff
	beq .L0807BB5C
	adds r2, r0, #0
	lsrs r0, r2, #1
	ldr r3, [sp, #4]
	subs r1, r0, r3
	cmp r1, #6
	bhi .L0807BB5C
	movs r0, #1
	ands r2, r0
	lsls r0, r2, #6
	adds r0, #0x70
	lsls r1, r1, #4
	asrs r2, r7, #0x10
	adds r1, r1, r2
	adds r1, #0x28
	bl PutFrozenUiHand
.L0807BB5C:
	movs r5, #0
	ldr r0, [sp, #4]
	lsls r6, r0, #1
	asrs r0, r7, #0x10
	adds r0, #0x28
	mov r8, r0
.L0807BB68:
	adds r3, r6, r5
	mov r1, sl
	ldr r0, [r1, #0x14]
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r3, r0
	bge .L0807BB9A
	lsrs r0, r5, #1
	lsls r0, r0, #4
	mov r2, r8
	adds r4, r0, r2
	cmp r4, #0x27
	ble .L0807BB9A
	movs r1, #1
	ands r1, r5
	lsls r1, r1, #6
	adds r1, #0x70
	ldr r2, .L0807BC00 @ =0x0200E6D4
	lsls r0, r3, #2
	adds r0, r0, r2
	ldr r3, [r0]
	movs r0, #3
	adds r2, r4, #0
	bl PutUnitSprite
.L0807BB9A:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0xd
	bls .L0807BB68
	asrs r0, r7, #0x10
	cmp r0, #0
	beq .L0807BBEA
	cmp r5, #0xf
	bhi .L0807BBEA
	adds r7, r0, #0
	adds r7, #0x28
.L0807BBB2:
	adds r4, r6, r5
	mov r3, sl
	ldr r0, [r3, #0x14]
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r4, r0
	bge .L0807BBE0
	movs r1, #1
	ands r1, r5
	lsls r1, r1, #6
	adds r1, #0x70
	lsrs r2, r5, #1
	lsls r2, r2, #4
	adds r2, r2, r7
	movs r0, #0xff
	ands r2, r0
	ldr r3, .L0807BC00 @ =0x0200E6D4
	lsls r0, r4, #2
	adds r0, r0, r3
	ldr r3, [r0]
	movs r0, #3
	bl PutUnitSprite
.L0807BBE0:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0xf
	bls .L0807BBB2
.L0807BBEA:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0807BBFC: .4byte gDispIo
.L0807BC00: .4byte 0x0200E6D4

	thumb_func_start func_fe6_0807BC04
func_fe6_0807BC04: @ 0x0807BC04
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	ldr r1, .L0807BC74 @ =gUnk_08327264
	add r0, sp, #4
	movs r2, #6
	bl memcpy
	movs r7, #0x28
	mov r0, r8
	adds r0, #0x35
	ldrb r0, [r0]
	cmp r0, #0x1f
	bhi .L0807BC2A
	movs r7, #0x74
.L0807BC2A:
	mov r1, r8
	ldr r0, [r1, #0x14]
	adds r0, #0x2c
	movs r2, #1
	adds r5, r2, #0
	ldrb r0, [r0]
	ands r5, r0
	cmp r5, #0
	bne .L0807BD28
	mov r0, r8
	adds r0, #0x37
	ldrb r1, [r0]
	mov sl, r0
	cmp r1, #0
	beq .L0807BD28
	adds r4, r2, #0
	ands r4, r1
	cmp r4, #0
	beq .L0807BC80
	movs r2, #0xa4
	mov sb, r2
	adds r2, r7, #2
	ldr r3, .L0807BC78 @ =gUnk_086790BA
	str r5, [sp]
	movs r0, #4
	movs r1, #0xa6
	bl PutSpriteExt
	ldr r0, .L0807BC7C @ =gUnk_0867913C
	ldr r3, [r0, #0x28]
	str r5, [sp]
	movs r0, #4
	movs r1, #0xdc
	adds r2, r7, #0
	bl PutSpriteExt
	b .L0807BCA0
	.align 2, 0
.L0807BC74: .4byte gUnk_08327264
.L0807BC78: .4byte gUnk_086790BA
.L0807BC7C: .4byte gUnk_0867913C
.L0807BC80:
	movs r6, #0xa8
	mov sb, r6
	adds r2, r7, #2
	ldr r3, .L0807BCD0 @ =gUnk_086790A0
	str r4, [sp]
	movs r0, #4
	movs r1, #0xaa
	bl PutSpriteExt
	ldr r3, .L0807BCD4 @ =gUnk_08679098
	str r4, [sp]
	movs r0, #4
	movs r1, #0xe0
	adds r2, r7, #0
	bl PutSpriteExt
.L0807BCA0:
	ldr r3, .L0807BCD8 @ =gUnk_0867908A
	movs r6, #0
	str r6, [sp]
	movs r0, #4
	mov r1, sb
	adds r2, r7, #0
	bl PutSpriteExt
	mov r1, sl
	ldrb r1, [r1]
	lsrs r0, r1, #1
	cmp r0, #9
	bhi .L0807BCE0
	mov r1, sb
	adds r1, #0x28
	ldr r0, .L0807BCDC @ =gUnk_0867913C
	ldr r3, [r0, #0x2c]
	str r6, [sp]
	movs r0, #4
	adds r2, r7, #0
	bl PutSpriteExt
	b .L0807BD00
	.align 2, 0
.L0807BCD0: .4byte gUnk_086790A0
.L0807BCD4: .4byte gUnk_08679098
.L0807BCD8: .4byte gUnk_0867908A
.L0807BCDC: .4byte gUnk_0867913C
.L0807BCE0:
	mov r5, sb
	adds r5, #0x28
	ldr r4, .L0807BDC4 @ =gUnk_0867913C
	movs r1, #0xa
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x16
	adds r0, r0, r4
	ldr r3, [r0]
	str r6, [sp]
	movs r0, #4
	adds r1, r5, #0
	adds r2, r7, #0
	bl PutSpriteExt
.L0807BD00:
	mov r5, sb
	adds r5, #0x30
	ldr r4, .L0807BDC4 @ =gUnk_0867913C
	mov r2, sl
	ldrb r2, [r2]
	lsrs r0, r2, #1
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x16
	adds r0, r0, r4
	ldr r3, [r0]
	movs r0, #0
	str r0, [sp]
	movs r0, #4
	adds r1, r5, #0
	adds r2, r7, #0
	bl PutSpriteExt
.L0807BD28:
	mov r0, r8
	adds r0, #0x33
	ldrb r3, [r0]
	movs r1, #0xf
	ands r1, r3
	adds r2, r0, #0
	cmp r1, #0
	bne .L0807BD5A
	adds r0, r3, #0
	adds r0, #0x10
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x5f
	bls .L0807BD48
	strb r1, [r2]
.L0807BD48:
	ldrb r0, [r2]
	movs r1, #0xf0
	ands r1, r0
	lsrs r0, r0, #4
	add r0, sp
	adds r0, #4
	ldrb r0, [r0]
	adds r1, r0, r1
	strb r1, [r2]
.L0807BD5A:
	ldrb r0, [r2]
	subs r0, #1
	movs r6, #0
	strb r0, [r2]
	mov r4, r8
	adds r4, #0x34
	ldrb r7, [r4]
	cmp r7, #0x1f
	bhi .L0807BDE0
	adds r1, r7, #0
	adds r1, #0x68
	mov r5, r8
	adds r5, #0x35
	ldrb r2, [r5]
	adds r2, #0x26
	ldr r3, .L0807BDC8 @ =gUnk_08679048
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x1c
	lsls r0, r0, #2
	str r0, [sp]
	movs r0, #4
	bl PutSpriteExt
	ldrb r0, [r4]
	ldr r2, .L0807BDCC @ =0x00001088
	adds r1, r0, r2
	ldrb r2, [r5]
	adds r2, #0x1e
	ldr r3, .L0807BDD0 @ =gUnk_0867907A
	str r6, [sp]
	movs r0, #4
	bl PutSpriteExt
	ldrb r7, [r4]
	ldr r0, .L0807BDD4 @ =0x00001068
	adds r1, r7, r0
	ldrb r2, [r5]
	adds r2, #0x1e
	ldr r3, .L0807BDD8 @ =gUnk_08679082
	str r6, [sp]
	movs r0, #4
	bl PutSpriteExt
	ldrb r1, [r4]
	adds r1, #0x68
	ldrb r2, [r5]
	adds r2, #0x16
	ldr r3, .L0807BDDC @ =gUnk_08679050
	str r6, [sp]
	movs r0, #4
	bl PutSpriteExt
	b .L0807BE32
	.align 2, 0
.L0807BDC4: .4byte gUnk_0867913C
.L0807BDC8: .4byte gUnk_08679048
.L0807BDCC: .4byte 0x00001088
.L0807BDD0: .4byte gUnk_0867907A
.L0807BDD4: .4byte 0x00001068
.L0807BDD8: .4byte gUnk_08679082
.L0807BDDC: .4byte gUnk_08679050
.L0807BDE0:
	ldrb r1, [r4]
	adds r1, #0x62
	mov r5, r8
	adds r5, #0x35
	ldrb r2, [r5]
	adds r2, #0x26
	ldr r3, .L0807BE70 @ =gUnk_08679048
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x1c
	lsls r0, r0, #2
	str r0, [sp]
	movs r0, #4
	bl PutSpriteExt
	ldrb r1, [r4]
	adds r1, #0x42
	ldrb r2, [r5]
	adds r2, #0x1e
	ldr r3, .L0807BE74 @ =gUnk_0867907A
	str r6, [sp]
	movs r0, #4
	bl PutSpriteExt
	ldrb r1, [r4]
	adds r1, #0x62
	ldrb r2, [r5]
	adds r2, #0x1e
	ldr r3, .L0807BE78 @ =gUnk_08679082
	str r6, [sp]
	movs r0, #4
	bl PutSpriteExt
	ldrb r1, [r4]
	adds r1, #0x42
	ldrb r2, [r5]
	adds r2, #0x16
	ldr r3, .L0807BE7C @ =gUnk_08679050
	str r6, [sp]
	movs r0, #4
	bl PutSpriteExt
.L0807BE32:
	movs r1, #0
	ldr r3, .L0807BE80 @ =gPal
	ldr r6, .L0807BE84 @ =0x000002CA
	adds r2, r3, r6
	movs r5, #0xf
	movs r4, #0xc8
	lsls r4, r4, #1
.L0807BE40:
	mov r7, r8
	ldrh r7, [r7, #0x3e]
	lsrs r0, r7, #1
	adds r0, r0, r1
	ands r0, r5
	adds r0, r0, r4
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r1, #1
	cmp r1, #9
	ble .L0807BE40
	bl EnablePalSync
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0807BE70: .4byte gUnk_08679048
.L0807BE74: .4byte gUnk_0867907A
.L0807BE78: .4byte gUnk_08679082
.L0807BE7C: .4byte gUnk_08679050
.L0807BE80: .4byte gPal
.L0807BE84: .4byte 0x000002CA

	thumb_func_start func_fe6_0807BE88
func_fe6_0807BE88: @ 0x0807BE88
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r2, [r5, #0x14]
	adds r0, r2, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	beq .L0807BEA0
	cmp r0, #1
	beq .L0807BED0
	b .L0807BF5A
.L0807BEA0:
	adds r1, r2, #0
	adds r1, #0x35
	ldrb r0, [r1]
	cmp r0, #0
	bne .L0807BEB6
	adds r0, r2, #0
	adds r0, #0x33
	ldrb r0, [r0]
	lsls r1, r0, #4
	adds r1, #0x28
	b .L0807BEC8
.L0807BEB6:
	cmp r0, #1
	bne .L0807BF5A
	adds r0, r2, #0
	adds r0, #0x33
	ldrb r1, [r1]
	adds r0, r1, r0
	ldrb r0, [r0]
	lsls r1, r0, #4
	adds r1, #0x48
.L0807BEC8:
	movs r0, #0xc
	bl PutUiHand
	b .L0807BF5A
.L0807BED0:
	adds r1, r2, #0
	adds r1, #0x3c
	movs r0, #2
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq .L0807BEF2
	adds r0, r2, #0
	adds r0, #0x33
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0807BEF2
	movs r0, #0x6c
	movs r1, #8
	bl PutUiHand
	b .L0807BF5A
.L0807BEF2:
	ldr r1, [r5, #0x14]
	adds r2, r1, #0
	adds r2, #0x30
	movs r4, #1
	adds r0, r4, #0
	ldrb r2, [r2]
	ands r0, r2
	lsls r0, r0, #6
	adds r0, #0x70
	adds r1, #0x36
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	lsls r1, r1, #4
	adds r1, #0x28
	bl PutUiHand
	ldr r0, [r5, #0x14]
	adds r1, r0, #0
	adds r1, #0x30
	ldrb r1, [r1]
	ands r4, r1
	lsls r4, r4, #6
	adds r4, #0x70
	adds r0, #0x36
	movs r2, #0
	ldrsb r2, [r0, r2]
	lsls r2, r2, #4
	adds r2, #0x30
	ldr r3, .L0807BF64 @ =gUnk_0867916C
	movs r0, #0xc0
	lsls r0, r0, #6
	str r0, [sp]
	movs r0, #0xd
	adds r1, r4, #0
	bl PutSpriteExt
	ldr r2, .L0807BF68 @ =gPal
	ldr r3, .L0807BF6C @ =0x02016874
	ldrh r5, [r5, #0x3e]
	lsrs r0, r5, #2
	movs r1, #0xf
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0x9f
	lsls r1, r1, #2
	adds r2, r2, r1
	strh r0, [r2]
	bl EnablePalSync
.L0807BF5A:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0807BF64: .4byte gUnk_0867916C
.L0807BF68: .4byte gPal
.L0807BF6C: .4byte 0x02016874

	thumb_func_start func_fe6_0807BF70
func_fe6_0807BF70: @ 0x0807BF70
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r2, [r7, #0x14]
	adds r1, r2, #0
	adds r1, #0x3c
	movs r0, #1
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq .L0807BFA2
	adds r0, r2, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq .L0807BFA2
	ldrh r0, [r7, #0x3c]
	cmp r0, #0xff
	bhi .L0807BFAC
	adds r0, #0x20
	b .L0807BFAA
.L0807BFA2:
	ldrh r0, [r7, #0x3c]
	cmp r0, #0
	beq .L0807BFAC
	subs r0, #0x20
.L0807BFAA:
	strh r0, [r7, #0x3c]
.L0807BFAC:
	ldrh r0, [r7, #0x3c]
	cmp r0, #0x10
	bls .L0807C06A
	ldr r2, .L0807C07C @ =gPal
	ldrh r1, [r7, #0x3e]
	lsrs r0, r1, #3
	movs r1, #0xf
	ands r0, r1
	lsls r0, r0, #1
	ldr r1, .L0807C080 @ =gUnk_0831AAFC
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, .L0807C084 @ =0x0000027A
	adds r2, r2, r1
	strh r0, [r2]
	bl EnablePalSync
	movs r2, #0x2a
	adds r2, r2, r7
	mov sl, r2
	ldrb r0, [r2]
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi .L0807C05E
	ldr r4, .L0807C088 @ =gSinLut
	movs r0, #0x80
	adds r0, r0, r4
	mov sb, r0
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #4
	movs r2, #0x80
	lsls r2, r2, #1
	mov r8, r2
	mov r1, r8
	bl Div
	adds r6, r0, #0
	lsls r6, r6, #0x10
	asrs r6, r6, #0x10
	movs r1, #0
	ldrsh r0, [r4, r1]
	rsbs r0, r0, #0
	lsls r0, r0, #4
	ldrh r1, [r7, #0x3c]
	bl Div
	adds r5, r0, #0
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	movs r2, #0
	ldrsh r0, [r4, r2]
	lsls r0, r0, #4
	mov r1, r8
	bl Div
	adds r4, r0, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	mov r1, sb
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #4
	ldrh r1, [r7, #0x3c]
	bl Div
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	movs r0, #0
	adds r1, r6, #0
	adds r2, r5, #0
	adds r3, r4, #0
	bl SetObjAffine
	movs r2, #0xff
	lsls r2, r2, #1
	ldr r3, .L0807C08C @ =gUnk_086791A2
	movs r0, #0xc0
	lsls r0, r0, #6
	str r0, [sp]
	movs r0, #4
	movs r1, #0x68
	bl PutSprite
.L0807C05E:
	mov r1, sl
	ldrb r0, [r1]
	cmp r0, #0
	beq .L0807C06A
	adds r0, #1
	strb r0, [r1]
.L0807C06A:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0807C07C: .4byte gPal
.L0807C080: .4byte gUnk_0831AAFC
.L0807C084: .4byte 0x0000027A
.L0807C088: .4byte gSinLut
.L0807C08C: .4byte gUnk_086791A2

	thumb_func_start func_fe6_0807C090
func_fe6_0807C090: @ 0x0807C090
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r3, .L0807C118 @ =gDispIo
	adds r1, r3, #0
	adds r1, #0x3c
	movs r0, #0x3f
	ldrb r2, [r1]
	ands r0, r2
	strb r0, [r1]
	adds r1, #8
	movs r2, #0
	movs r0, #0xe
	strb r0, [r1]
	adds r1, #1
	movs r0, #8
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x46
	strb r2, [r0]
	ldr r0, .L0807C11C @ =0x0000FFE0
	ldrh r1, [r3, #0x3c]
	ands r0, r1
	movs r1, #0x10
	orrs r0, r1
	ldr r1, .L0807C120 @ =0x0000E0FF
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r3, #0x3c]
	movs r4, #0
	movs r5, #0x80
	lsls r5, r5, #6
.L0807C0DA:
	lsls r1, r4, #5
	str r5, [sp]
	movs r0, #0xd
	movs r2, #4
	ldr r3, .L0807C124 @ =gUnk_0867917A
	bl PutSprite
	adds r4, #1
	cmp r4, #7
	ble .L0807C0DA
	adds r4, r6, #0
	adds r4, #0x30
	ldrb r0, [r4]
	cmp r0, #0
	beq .L0807C12C
	adds r1, r0, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	lsls r2, r1, #4
	muls r1, r2, r1
	subs r0, r0, r1
	movs r1, #0xa
	bl __divsi3
	strh r0, [r6, #0x3a]
	ldrb r0, [r4]
	cmp r0, #9
	bhi .L0807C128
	adds r0, #1
	b .L0807C12A
	.align 2, 0
.L0807C118: .4byte gDispIo
.L0807C11C: .4byte 0x0000FFE0
.L0807C120: .4byte 0x0000E0FF
.L0807C124: .4byte gUnk_0867917A
.L0807C128:
	movs r0, #0
.L0807C12A:
	strb r0, [r4]
.L0807C12C:
	ldr r0, [r6, #0x14]
	adds r0, #0x2b
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0807C13E
	ldrh r0, [r6, #0x3a]
	subs r0, #0xa0
	mov r8, r0
	b .L0807C144
.L0807C13E:
	ldrh r1, [r6, #0x3a]
	rsbs r1, r1, #0
	mov r8, r1
.L0807C144:
	ldr r0, [r6, #0x14]
	adds r0, #0x35
	ldrb r0, [r0]
	cmp r0, #1
	bne .L0807C1A8
	adds r2, r6, #0
	adds r2, #0x44
	ldrb r0, [r2]
	cmp r0, #0
	bne .L0807C16C
	adds r0, r6, #0
	adds r0, #0x46
	ldrh r1, [r0]
	adds r7, r0, #0
	cmp r1, #0xff
	bhi .L0807C19C
	adds r0, r1, #0
	adds r0, #0x20
	strh r0, [r7]
	b .L0807C19C
.L0807C16C:
	adds r0, r6, #0
	adds r0, #0x46
	ldrh r1, [r0]
	adds r7, r0, #0
	cmp r1, #0x3f
	bls .L0807C180
	adds r0, r1, #0
	subs r0, #0x40
	strh r0, [r7]
	b .L0807C19C
.L0807C180:
	movs r0, #0
	strb r0, [r2]
	strh r0, [r7]
	ldr r0, [r6, #0x14]
	ldr r0, [r0, #0x60]
	adds r1, r6, #0
	adds r1, #0x43
	ldrb r1, [r1]
	bl func_fe6_08082D54
	adds r1, r6, #0
	adds r1, #0x48
	movs r0, #0x60
	strh r0, [r1]
.L0807C19C:
	ldr r1, [r6, #0x14]
	adds r0, r1, #0
	adds r0, #0x35
	ldrb r0, [r0]
	cmp r0, #1
	beq .L0807C208
.L0807C1A8:
	mov r1, r8
	adds r1, #8
	ldr r5, .L0807C1E4 @ =0x000001FF
	ands r1, r5
	ldr r3, .L0807C1E8 @ =gUnk_08679182
	movs r4, #0x80
	lsls r4, r4, #6
	str r4, [sp]
	movs r0, #0xd
	movs r2, #8
	bl PutSprite
	adds r0, r6, #0
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0807C1EC
	ldr r2, [r6, #0x14]
	adds r1, r2, #0
	adds r1, #0x2c
	movs r0, #1
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne .L0807C24E
	adds r0, r6, #0
	bl func_fe6_0807BF70
	b .L0807C23E
	.align 2, 0
.L0807C1E4: .4byte 0x000001FF
.L0807C1E8: .4byte gUnk_08679182
.L0807C1EC:
	movs r1, #0xa0
	lsls r1, r1, #1
	add r1, r8
	ands r1, r5
	ldr r3, .L0807C204 @ =gUnk_086791B0
	str r4, [sp]
	movs r0, #0xd
	movs r2, #8
	bl PutSprite
	b .L0807C23E
	.align 2, 0
.L0807C204: .4byte gUnk_086791B0
.L0807C208:
	ldr r0, [r1, #0x60]
	adds r4, r6, #0
	adds r4, #0x48
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r2, [r4]
	subs r1, r1, r2
	ldr r5, .L0807C280 @ =0x000001FF
	ands r1, r5
	ldrh r3, [r7]
	movs r2, #7
	bl func_fe6_08082DA4
	ldr r0, [r6, #0x14]
	ldr r0, [r0, #0x60]
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r2, [r4]
	subs r1, r1, r2
	ands r1, r5
	ldrh r3, [r7]
	movs r2, #7
	bl func_fe6_08082DA4
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
.L0807C23E:
	ldr r2, [r6, #0x14]
	adds r1, r2, #0
	adds r1, #0x2c
	movs r0, #1
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq .L0807C272
.L0807C24E:
	adds r0, r2, #0
	adds r0, #0x35
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0807C272
	mov r0, r8
	asrs r1, r0, #1
	adds r1, #0xbc
	ldr r0, .L0807C280 @ =0x000001FF
	ands r1, r0
	ldr r3, .L0807C284 @ =gUnk_086791BE
	movs r0, #0x80
	lsls r0, r0, #7
	str r0, [sp]
	movs r0, #4
	movs r2, #8
	bl PutSpriteExt
.L0807C272:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0807C280: .4byte 0x000001FF
.L0807C284: .4byte gUnk_086791BE

	thumb_func_start func_fe6_0807C288
func_fe6_0807C288: @ 0x0807C288
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r0, #0x2a
	movs r6, #0
	strb r6, [r0]
	movs r4, #0
	strh r6, [r5, #0x3e]
	subs r0, #1
	strb r4, [r0]
	ldr r0, [r5, #0x14]
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r5, #0
	adds r0, #0x40
	strh r1, [r0]
	bl ForceSyncUnitSpriteSheet
	ldr r0, [r5, #0x14]
	adds r1, r0, #0
	adds r1, #0x35
	adds r0, #0x33
	ldrb r1, [r1]
	adds r0, r1, r0
	ldrb r0, [r0]
	adds r1, r5, #0
	adds r1, #0x2b
	strb r0, [r1]
	ldr r0, [r5, #0x14]
	adds r0, #0x35
	ldrb r1, [r0]
	adds r0, r5, #0
	adds r0, #0x2c
	strb r1, [r0]
	movs r0, #0xa0
	strh r0, [r5, #0x3a]
	ldr r0, [r5, #0x14]
	adds r0, #0x29
	ldrb r0, [r0]
	adds r1, r5, #0
	adds r1, #0x2d
	strb r0, [r1]
	ldr r0, [r5, #0x14]
	adds r0, #0x2a
	ldrb r0, [r0]
	adds r1, #1
	strb r0, [r1]
	ldr r0, [r5, #0x14]
	adds r0, #0x2b
	ldrb r0, [r0]
	adds r1, #1
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x30
	strb r4, [r0]
	adds r0, #2
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	ldr r0, [r5, #0x14]
	bl func_fe6_0807CE98
	adds r1, r5, #0
	adds r1, #0x31
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x44
	strb r4, [r0]
	ldr r0, [r5, #0x14]
	adds r0, #0x34
	ldrb r0, [r0]
	adds r2, r5, #0
	adds r2, #0x43
	strb r0, [r2]
	adds r1, #0x17
	movs r0, #0x60
	strh r0, [r1]
	ldr r0, [r5, #0x14]
	ldrh r1, [r0, #0x34]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	bne .L0807C33E
	adds r0, r5, #0
	adds r0, #0x46
	strh r1, [r0]
	ldr r0, [r5, #0x14]
	ldr r0, [r0, #0x60]
	movs r1, #5
	bl func_fe6_08082D54
	b .L0807C35E
.L0807C33E:
	adds r0, r5, #0
	adds r0, #0x46
	strh r6, [r0]
	ldr r0, [r5, #0x14]
	ldr r4, [r0, #0x60]
	ldrb r0, [r2]
	movs r1, #1
	bl func_fe6_0807CF2C
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	subs r1, #5
	adds r0, r4, #0
	bl func_fe6_08082D54
.L0807C35E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0807C364
func_fe6_0807C364: @ 0x0807C364
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x14]
	adds r0, #0x2a
	adds r1, r5, #0
	adds r1, #0x2e
	ldrb r0, [r0]
	ldrb r2, [r1]
	cmp r0, r2
	beq .L0807C37A
	strb r0, [r1]
.L0807C37A:
	ldr r0, [r5, #0x14]
	adds r1, r0, #0
	adds r1, #0x2b
	adds r4, r5, #0
	adds r4, #0x2f
	ldrb r1, [r1]
	ldrb r2, [r4]
	cmp r1, r2
	beq .L0807C3A4
	bl func_fe6_0807CE98
	adds r1, r5, #0
	adds r1, #0x31
	strb r0, [r1]
	ldr r0, [r5, #0x14]
	adds r0, #0x2b
	ldrb r0, [r0]
	strb r0, [r4]
	subs r1, #1
	movs r0, #1
	strb r0, [r1]
.L0807C3A4:
	bl SyncUnitSpriteSheet
	ldr r2, [r5, #0x14]
	adds r0, r2, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0807C3C0
	adds r0, r5, #0
	bl func_fe6_0807BC04
	adds r4, r5, #0
	adds r4, #0x32
	b .L0807C432
.L0807C3C0:
	ldr r1, .L0807C3F4 @ =0x0000FF80
	adds r0, r2, #0
	adds r0, #0x44
	ldrh r2, [r0]
	subs r2, #0x28
	movs r0, #0xff
	ands r2, r0
	movs r0, #2
	bl SetBgOffset
	adds r0, r5, #0
	bl func_fe6_0807B9CC
	ldr r0, [r5, #0x14]
	adds r0, #0x44
	ldrh r0, [r0]
	cmp r0, #0
	beq .L0807C3F8
	adds r4, r5, #0
	adds r4, #0x32
	ldrb r1, [r4]
	movs r0, #0
	movs r2, #1
	bl func_fe6_0807B90C
	b .L0807C406
	.align 2, 0
.L0807C3F4: .4byte 0x0000FF80
.L0807C3F8:
	adds r4, r5, #0
	adds r4, #0x32
	ldrb r1, [r4]
	movs r0, #0
	movs r2, #0
	bl func_fe6_0807B90C
.L0807C406:
	ldr r1, [r5, #0x14]
	adds r0, r1, #0
	adds r0, #0x44
	ldrh r0, [r0]
	lsrs r0, r0, #4
	adds r0, #7
	lsls r0, r0, #1
	adds r1, #0x2d
	ldrb r1, [r1]
	cmp r0, r1
	bge .L0807C428
	ldrb r1, [r4]
	movs r0, #1
	movs r2, #1
	bl func_fe6_0807B90C
	b .L0807C432
.L0807C428:
	ldrb r1, [r4]
	movs r0, #1
	movs r2, #0
	bl func_fe6_0807B90C
.L0807C432:
	adds r0, r5, #0
	bl func_fe6_0807BE88
	adds r0, r5, #0
	bl func_fe6_0807C090
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x1b
	cmp r0, #5
	bls .L0807C450
	movs r0, #0
	strb r0, [r4]
.L0807C450:
	ldr r0, [r5, #0x14]
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r5, #0
	adds r0, #0x40
	strh r1, [r0]
	adds r3, r5, #0
	adds r3, #0x2c
	ldr r0, [r5, #0x14]
	adds r2, r0, #0
	adds r2, #0x35
	ldrb r1, [r2]
	ldrb r4, [r3]
	cmp r4, r1
	beq .L0807C476
	strb r1, [r3]
	adds r4, r5, #0
	adds r4, #0x2b
	b .L0807C4E4
.L0807C476:
	adds r1, r5, #0
	adds r1, #0x2b
	ldrb r2, [r2]
	adds r0, #0x33
	adds r0, r0, r2
	adds r4, r1, #0
	ldrb r1, [r4]
	ldrb r0, [r0]
	cmp r1, r0
	beq .L0807C4E4
	cmp r2, #0
	bne .L0807C4B6
	lsls r1, r1, #1
	adds r1, #5
	movs r0, #1
	movs r2, #0xa
	bl RemoveUiEntryHover
	ldr r0, [r5, #0x14]
	adds r1, r0, #0
	adds r1, #0x35
	adds r0, #0x33
	ldrb r1, [r1]
	adds r0, r1, r0
	ldrb r0, [r0]
	lsls r1, r0, #1
	adds r1, #5
	movs r0, #1
	movs r2, #0xa
	bl PutUiEntryHover
	b .L0807C4DE
.L0807C4B6:
	ldrb r2, [r4]
	lsls r1, r2, #1
	adds r1, #9
	movs r0, #1
	movs r2, #0xa
	bl RemoveUiEntryHover
	ldr r0, [r5, #0x14]
	adds r1, r0, #0
	adds r1, #0x35
	adds r0, #0x33
	ldrb r1, [r1]
	adds r0, r1, r0
	ldrb r0, [r0]
	lsls r1, r0, #1
	adds r1, #9
	movs r0, #1
	movs r2, #0xa
	bl PutUiEntryHover
.L0807C4DE:
	movs r0, #2
	bl EnableBgSync
.L0807C4E4:
	ldr r0, [r5, #0x14]
	adds r1, r0, #0
	adds r1, #0x35
	adds r0, #0x33
	ldrb r1, [r1]
	adds r0, r1, r0
	ldrb r0, [r0]
	strb r0, [r4]
	ldrh r0, [r5, #0x3e]
	adds r0, #1
	strh r0, [r5, #0x3e]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0807C500
func_fe6_0807C500: @ 0x0807C500
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0807C504
func_fe6_0807C504: @ 0x0807C504
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0807C508
func_fe6_0807C508: @ 0x0807C508
	push {lr}
	adds r1, r0, #0
	ldr r0, .L0807C51C @ =gUnk_0867923C
	bl SpawnProc
	movs r1, #0
	strh r1, [r0, #0x3c]
	pop {r1}
	bx r1
	.align 2, 0
.L0807C51C: .4byte gUnk_0867923C

	thumb_func_start func_fe6_0807C520
func_fe6_0807C520: @ 0x0807C520
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r2, r0, #0
	adds r3, r2, #0
	subs r3, #0x38
	cmp r3, #0
	bge .L0807C536
	movs r7, #0
	adds r6, r2, #0
	b .L0807C54C
.L0807C536:
	adds r0, r2, #0
	adds r0, #0x38
	cmp r0, #0xf0
	ble .L0807C546
	movs r7, #0xf
	adds r6, r2, #0
	subs r6, #0x78
	b .L0807C54C
.L0807C546:
	asrs r7, r3, #3
	lsls r0, r7, #3
	subs r6, r2, r0
.L0807C54C:
	adds r3, r1, #0
	subs r3, #0x28
	adds r0, r1, #0
	adds r0, #0x30
	cmp r0, #0xa0
	ble .L0807C55E
	movs r5, #8
	subs r1, #0x40
	b .L0807C56E
.L0807C55E:
	adds r0, r3, #0
	cmp r0, #0
	bge .L0807C568
	adds r0, r1, #0
	subs r0, #0x21
.L0807C568:
	asrs r5, r0, #3
	lsls r0, r5, #3
	subs r1, r1, r0
.L0807C56E:
	mov r8, r1
	ldr r4, .L0807C5B4 @ =gBg0Tm+0x8
	adds r0, r4, #0
	movs r1, #2
	adds r2, r7, #0
	bl PutNumberOrBlank
	adds r0, r4, #0
	adds r0, #0x80
	movs r1, #2
	adds r2, r5, #0
	bl PutNumberOrBlank
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #2
	adds r2, r6, #0
	bl PutNumberOrBlank
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #2
	mov r2, r8
	bl PutNumberOrBlank
	movs r0, #1
	bl EnableBgSync
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0807C5B4: .4byte gBg0Tm+0x8

	thumb_func_start func_fe6_0807C5B8
func_fe6_0807C5B8: @ 0x0807C5B8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	adds r0, #0x29
	ldrb r5, [r0]
	cmp r5, #0
	bne .L0807C5F8
	adds r1, r4, #0
	adds r1, #0x3c
	movs r0, #1
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #9
	bl Proc_Goto
	ldr r0, .L0807C5F4 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	bge .L0807C5EA
	b .L0807C7A6
.L0807C5EA:
	movs r0, #0x6a
	bl m4aSongNumStart
	b .L0807C7A6
	.align 2, 0
.L0807C5F4: .4byte gPlaySt
.L0807C5F8:
	cmp r5, #1
	beq .L0807C5FE
	b .L0807C7A6
.L0807C5FE:
	adds r1, r4, #0
	adds r1, #0x2f
	ldrb r0, [r1]
	mov sb, r0
	adds r0, r4, #0
	adds r0, #0x3c
	ldrb r2, [r0]
	adds r0, r5, #0
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq .L0807C64C
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq .L0807C64C
	mov r1, sb
	cmp r1, #0
	beq .L0807C6D4
	adds r0, r4, #0
	movs r1, #5
	bl Proc_Goto
	ldr r0, [r4, #0x50]
	adds r0, #0x2a
	strb r5, [r0]
	ldr r0, .L0807C648 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	bge .L0807C63E
	b .L0807C798
.L0807C63E:
	movs r0, #0x6a
	bl m4aSongNumStart
	b .L0807C798
	.align 2, 0
.L0807C648: .4byte gPlaySt
.L0807C64C:
	ldr r7, .L0807C6C8 @ =0x0200E6D4
	adds r5, r4, #0
	adds r5, #0x30
	ldrb r2, [r5]
	lsls r0, r2, #2
	adds r0, r0, r7
	ldr r2, [r0]
	movs r0, #8
	ldrh r1, [r2, #0xc]
	ands r0, r1
	cmp r0, #0
	beq .L0807C714
	adds r1, r4, #0
	adds r1, #0x2c
	movs r6, #1
	adds r0, r6, #0
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq .L0807C680
	adds r0, r2, #0
	bl func_fe6_08082B74
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0807C6EC
.L0807C680:
	adds r0, r4, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	mov r2, r8
	ldrb r2, [r2]
	cmp r0, r2
	bls .L0807C6D4
	ldrb r1, [r5]
	lsls r0, r1, #2
	adds r0, r0, r7
	ldr r1, [r0]
	ldr r0, .L0807C6CC @ =0x0000FFF5
	ldrh r2, [r1, #0xc]
	ands r0, r2
	strh r0, [r1, #0xc]
	ldrb r5, [r5]
	lsls r0, r5, #2
	adds r0, r0, r7
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	bl func_fe6_080791B4
	ldr r0, .L0807C6D0 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807C6BE
	movs r0, #0x6a
	bl m4aSongNumStart
.L0807C6BE:
	mov r1, r8
	ldrb r0, [r1]
	adds r0, #1
	b .L0807C764
	.align 2, 0
.L0807C6C8: .4byte 0x0200E6D4
.L0807C6CC: .4byte 0x0000FFF5
.L0807C6D0: .4byte gPlaySt
.L0807C6D4:
	ldr r0, .L0807C6E8 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807C798
	movs r0, #0x6c
	bl m4aSongNumStart
	b .L0807C798
	.align 2, 0
.L0807C6E8: .4byte gPlaySt
.L0807C6EC:
	adds r0, r6, #0
	ldrb r5, [r5]
	ands r0, r5
	lsls r0, r0, #6
	adds r0, #0x70
	adds r1, r4, #0
	adds r1, #0x36
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	lsls r1, r1, #4
	adds r1, #0x28
	ldr r2, .L0807C710 @ =0x000006C1
	adds r3, r4, #0
	bl func_fe6_08082B00
	b .L0807C7A6
	.align 2, 0
.L0807C710: .4byte 0x000006C1
.L0807C714:
	adds r1, r4, #0
	adds r1, #0x2c
	movs r0, #1
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne .L0807C72E
	adds r0, r2, #0
	bl func_fe6_08079404
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0807C788
.L0807C72E:
	ldrb r2, [r5]
	lsls r0, r2, #2
	adds r0, r0, r7
	ldr r1, [r0]
	movs r0, #0xa
	ldrh r2, [r1, #0xc]
	orrs r0, r2
	strh r0, [r1, #0xc]
	ldrb r5, [r5]
	lsls r0, r5, #2
	adds r0, r0, r7
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	bl func_fe6_080791DC
	ldr r0, .L0807C784 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807C75E
	movs r0, #0x6b
	bl m4aSongNumStart
.L0807C75E:
	mov r1, r8
	ldrb r0, [r1]
	subs r0, #1
.L0807C764:
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x44
	ldrh r0, [r0]
	lsrs r1, r0, #4
	adds r0, r4, #0
	adds r0, #0x36
	ldrb r0, [r0]
	adds r1, r0, r1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl func_fe6_08079F50
	b .L0807C798
	.align 2, 0
.L0807C784: .4byte gPlaySt
.L0807C788:
	ldr r0, .L0807C7B4 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807C798
	movs r0, #0x6c
	bl m4aSongNumStart
.L0807C798:
	mov r2, r8
	ldrb r2, [r2]
	cmp sb, r2
	beq .L0807C7A6
	adds r0, r4, #0
	bl func_fe6_08079EA0
.L0807C7A6:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0807C7B4: .4byte gPlaySt

	thumb_func_start func_fe6_0807C7B8
func_fe6_0807C7B8: @ 0x0807C7B8
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x29
	adds r0, r0, r4
	mov ip, r0
	ldrb r3, [r0]
	cmp r3, #0
	bne .L0807C7E8
	adds r0, r4, #0
	movs r1, #9
	bl Proc_Goto
	ldr r0, .L0807C7E4 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807C834
	movs r0, #0x6a
	bl m4aSongNumStart
	b .L0807C834
	.align 2, 0
.L0807C7E4: .4byte gPlaySt
.L0807C7E8:
	cmp r3, #1
	bne .L0807C834
	adds r1, r4, #0
	adds r1, #0x30
	ldrb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x31
	strb r0, [r2]
	ldrb r0, [r1]
	adds r1, #2
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x44
	ldrh r1, [r0]
	subs r0, #4
	movs r2, #0
	strh r1, [r0]
	subs r0, #0xa
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x37
	strb r0, [r1]
	mov r0, ip
	strb r2, [r0]
	adds r0, r4, #0
	adds r0, #0x35
	strb r3, [r0]
	ldr r0, .L0807C83C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807C82E
	movs r0, #0x6a
	bl m4aSongNumStart
.L0807C82E:
	adds r0, r4, #0
	bl func_fe6_08079A94
.L0807C834:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0807C83C: .4byte gPlaySt

	thumb_func_start func_fe6_0807C840
func_fe6_0807C840: @ 0x0807C840
	mov ip, r0
	mov r3, ip
	adds r3, #0x30
	adds r0, #0x31
	ldrb r1, [r3]
	ldrb r0, [r0]
	cmp r1, r0
	bne .L0807C882
	ldrb r1, [r3]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L0807C87E
	adds r2, r1, #1
	mov r0, ip
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r2, r0
	bge .L0807C86A
	strb r2, [r3]
	b .L0807C882
.L0807C86A:
	cmp r1, #1
	bls .L0807C882
	subs r0, r1, #2
	strb r0, [r3]
	mov r1, ip
	adds r1, #0x36
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	b .L0807C882
.L0807C87E:
	subs r0, r1, #1
	strb r0, [r3]
.L0807C882:
	bx lr

	thumb_func_start func_fe6_0807C884
func_fe6_0807C884: @ 0x0807C884
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x29
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0807C8E0
	adds r0, r5, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #1
	beq .L0807C916
	ldr r0, [r5, #0x50]
	movs r1, #5
	bl func_fe6_0807B8B0
	adds r0, r5, #0
	adds r0, #0x32
	ldrb r1, [r0]
	subs r0, #2
	strb r1, [r0]
	movs r0, #1
	strb r0, [r4]
	adds r0, r5, #0
	bl func_fe6_0807C840
	adds r0, r5, #0
	bl func_fe6_08079D84
	adds r0, r5, #0
	bl func_fe6_080798EC
	ldr r0, .L0807C8DC @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807C96C
	movs r0, #0x6a
	bl m4aSongNumStart
	b .L0807C96C
	.align 2, 0
.L0807C8DC: .4byte gPlaySt
.L0807C8E0:
	cmp r0, #1
	bne .L0807C96C
	adds r7, r5, #0
	adds r7, #0x30
	adds r6, r5, #0
	adds r6, #0x31
	ldrb r0, [r7]
	ldrb r1, [r6]
	cmp r0, r1
	beq .L0807C916
	ldr r0, .L0807C928 @ =0x0200E6D4
	mov r8, r0
	ldrb r1, [r7]
	lsls r0, r1, #2
	add r0, r8
	ldr r0, [r0]
	bl GetUnitItemCount
	adds r4, r0, #0
	ldrb r1, [r6]
	lsls r0, r1, #2
	add r0, r8
	ldr r0, [r0]
	bl GetUnitItemCount
	cmn r4, r0
	bne .L0807C930
.L0807C916:
	ldr r0, .L0807C92C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807C96C
	movs r0, #0x6c
	bl m4aSongNumStart
	b .L0807C96C
	.align 2, 0
.L0807C928: .4byte 0x0200E6D4
.L0807C92C: .4byte gPlaySt
.L0807C930:
	ldrb r6, [r6]
	lsls r0, r6, #2
	add r0, r8
	ldr r0, [r0]
	str r0, [r5, #0x48]
	ldrb r7, [r7]
	lsls r0, r7, #2
	add r0, r8
	ldr r0, [r0]
	str r0, [r5, #0x4c]
	adds r0, r5, #0
	movs r1, #1
	bl func_fe6_080829E8
	adds r1, r5, #0
	adds r1, #0x3b
	movs r0, #2
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #3
	bl Proc_Goto
	ldr r0, .L0807C978 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807C96C
	movs r0, #0x6a
	bl m4aSongNumStart
.L0807C96C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0807C978: .4byte gPlaySt

	thumb_func_start func_fe6_0807C97C
func_fe6_0807C97C: @ 0x0807C97C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0807C9EA
	ldr r6, .L0807C9B0 @ =0x0200E6D4
	adds r5, r4, #0
	adds r5, #0x30
	ldrb r1, [r5]
	lsls r0, r1, #2
	adds r0, r0, r6
	ldr r0, [r0]
	bl GetUnitItemCount
	cmp r0, #0
	bne .L0807C9B8
	ldr r0, .L0807C9B4 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807C9EA
	movs r0, #0x6c
	bl m4aSongNumStart
	b .L0807C9EA
	.align 2, 0
.L0807C9B0: .4byte 0x0200E6D4
.L0807C9B4: .4byte gPlaySt
.L0807C9B8:
	ldrb r5, [r5]
	lsls r0, r5, #2
	adds r0, r0, r6
	ldr r0, [r0]
	str r0, [r4, #0x48]
	adds r0, r4, #0
	movs r1, #1
	bl func_fe6_080829E8
	adds r1, r4, #0
	adds r1, #0x3b
	movs r0, #4
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #3
	bl Proc_Goto
	ldr r0, .L0807C9F0 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807C9EA
	movs r0, #0x6a
	bl m4aSongNumStart
.L0807C9EA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0807C9F0: .4byte gPlaySt

	thumb_func_start func_fe6_0807C9F4
func_fe6_0807C9F4: @ 0x0807C9F4
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0807CA38
	ldr r1, .L0807CA40 @ =0x0200E6D4
	adds r0, r4, #0
	adds r0, #0x30
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r4, #0x48]
	adds r0, r4, #0
	movs r1, #1
	bl func_fe6_080829E8
	adds r1, r4, #0
	adds r1, #0x3b
	movs r0, #3
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #3
	bl Proc_Goto
	ldr r0, .L0807CA44 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807CA38
	movs r0, #0x6a
	bl m4aSongNumStart
.L0807CA38:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0807CA40: .4byte 0x0200E6D4
.L0807CA44: .4byte gPlaySt

	thumb_func_start func_fe6_0807CA48
func_fe6_0807CA48: @ 0x0807CA48
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0807CA8C
	ldr r1, .L0807CA94 @ =0x0200E6D4
	adds r0, r4, #0
	adds r0, #0x30
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r4, #0x48]
	adds r0, r4, #0
	movs r1, #1
	bl func_fe6_080829E8
	adds r1, r4, #0
	adds r1, #0x3b
	movs r0, #5
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #3
	bl Proc_Goto
	ldr r0, .L0807CA98 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807CA8C
	movs r0, #0x6a
	bl m4aSongNumStart
.L0807CA8C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0807CA94: .4byte 0x0200E6D4
.L0807CA98: .4byte gPlaySt

	thumb_func_start func_fe6_0807CA9C
func_fe6_0807CA9C: @ 0x0807CA9C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0807CAC8
	ldr r0, .L0807CAD0 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807CAB8
	movs r0, #0x6a
	bl m4aSongNumStart
.L0807CAB8:
	adds r1, r4, #0
	adds r1, #0x3b
	movs r0, #0xa
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0xd
	bl Proc_Goto
.L0807CAC8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0807CAD0: .4byte gPlaySt

	thumb_func_start func_fe6_0807CAD4
func_fe6_0807CAD4: @ 0x0807CAD4
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0807CAFE
	adds r1, r4, #0
	adds r1, #0x35
	movs r0, #2
	strb r0, [r1]
	ldr r0, .L0807CB04 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807CAF8
	movs r0, #0x6a
	bl m4aSongNumStart
.L0807CAF8:
	adds r0, r4, #0
	bl func_fe6_08079A94
.L0807CAFE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0807CB04: .4byte gPlaySt

	thumb_func_start func_fe6_0807CB08
func_fe6_0807CB08: @ 0x0807CB08
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0807CB34
	ldr r0, .L0807CB3C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807CB24
	movs r0, #0x6a
	bl m4aSongNumStart
.L0807CB24:
	adds r1, r4, #0
	adds r1, #0x3b
	movs r0, #8
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0xd
	bl Proc_Goto
.L0807CB34:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0807CB3C: .4byte gPlaySt

	thumb_func_start func_fe6_0807CB40
func_fe6_0807CB40: @ 0x0807CB40
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0807CB6C
	ldr r0, .L0807CB74 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807CB5C
	movs r0, #0x6a
	bl m4aSongNumStart
.L0807CB5C:
	adds r1, r4, #0
	adds r1, #0x3b
	movs r0, #9
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0xd
	bl Proc_Goto
.L0807CB6C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0807CB74: .4byte gPlaySt

	thumb_func_start func_fe6_0807CB78
func_fe6_0807CB78: @ 0x0807CB78
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0807CBA4
	ldr r0, .L0807CBAC @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807CB94
	movs r0, #0x6a
	bl m4aSongNumStart
.L0807CB94:
	adds r1, r4, #0
	adds r1, #0x3b
	movs r0, #7
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0xd
	bl Proc_Goto
.L0807CBA4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0807CBAC: .4byte gPlaySt

	thumb_func_start func_fe6_0807CBB0
func_fe6_0807CBB0: @ 0x0807CBB0
	push {lr}
	adds r1, r0, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0807CBD4
	adds r0, r1, #0
	movs r1, #6
	bl Proc_Goto
	ldr r0, .L0807CBD8 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807CBD4
	movs r0, #0x6a
	bl m4aSongNumStart
.L0807CBD4:
	pop {r0}
	bx r0
	.align 2, 0
.L0807CBD8: .4byte gPlaySt

	thumb_func_start func_fe6_0807CBDC
func_fe6_0807CBDC: @ 0x0807CBDC
	push {lr}
	adds r1, r0, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0807CC20
	adds r0, r1, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	cmp r0, #0
	beq .L0807CC10
	adds r0, r1, #0
	movs r1, #0xe
	bl Proc_Goto
	ldr r0, .L0807CC0C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807CC20
	movs r0, #0x6a
	bl m4aSongNumStart
	b .L0807CC20
	.align 2, 0
.L0807CC0C: .4byte gPlaySt
.L0807CC10:
	ldr r0, .L0807CC24 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807CC20
	movs r0, #0x6c
	bl m4aSongNumStart
.L0807CC20:
	pop {r0}
	bx r0
	.align 2, 0
.L0807CC24: .4byte gPlaySt

	thumb_func_start func_fe6_0807CC28
func_fe6_0807CC28: @ 0x0807CC28
	ldr r1, .L0807CC30 @ =0x020155E4
	movs r0, #0
	strb r0, [r1]
	bx lr
	.align 2, 0
.L0807CC30: .4byte 0x020155E4

	thumb_func_start func_fe6_0807CC34
func_fe6_0807CC34: @ 0x0807CC34
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r2, #0
	ldr r0, [sp, #0x18]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r3, r3, #0x18
	lsrs r4, r3, #0x18
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov ip, r0
	ldr r3, .L0807CCBC @ =0x020155E4
	ldrb r0, [r3]
	cmp r0, #0xf
	bhi .L0807CCB4
	ldr r2, .L0807CCC0 @ =0x020154A4
	lsls r0, r0, #2
	ldrb r7, [r3]
	adds r0, r0, r7
	lsls r0, r0, #2
	adds r0, r0, r2
	strb r1, [r0, #9]
	ldrb r1, [r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	str r5, [r0]
	ldrb r7, [r3]
	lsls r0, r7, #2
	adds r1, r7, #0
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	strb r4, [r0, #8]
	ldrb r7, [r3]
	lsls r0, r7, #2
	adds r1, r7, #0
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r2, #0
	adds r1, #0xc
	adds r0, r0, r1
	str r6, [r0]
	ldrb r7, [r3]
	lsls r0, r7, #2
	adds r1, r7, #0
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r2, #4
	adds r0, r0, r1
	ldr r1, [sp, #0x14]
	str r1, [r0]
	ldrb r7, [r3]
	lsls r0, r7, #2
	adds r1, r7, #0
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	mov r7, ip
	strb r7, [r0, #0x10]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
.L0807CCB4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0807CCBC: .4byte 0x020155E4
.L0807CCC0: .4byte 0x020154A4

	thumb_func_start func_fe6_0807CCC4
func_fe6_0807CCC4: @ 0x0807CCC4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r5, #0
	movs r3, #0
	ldr r0, .L0807CD04 @ =0x020155E4
	adds r6, r0, #0
	ldrb r0, [r6]
	cmp r3, r0
	bge .L0807CD1C
	adds r2, r4, #0
	adds r2, #0x35
	ldr r1, .L0807CD08 @ =0x020154A4
.L0807CCDC:
	ldrb r7, [r1, #9]
	ldrb r0, [r2]
	cmp r7, r0
	bne .L0807CD12
	adds r0, r4, #0
	adds r0, #0x33
	ldrb r7, [r2]
	adds r0, r7, r0
	ldrb r0, [r0]
	cmp r5, r0
	bne .L0807CD0C
	ldrb r0, [r1, #8]
	cmp r0, #1
	beq .L0807CD1C
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #1
	b .L0807CD1E
	.align 2, 0
.L0807CD04: .4byte 0x020155E4
.L0807CD08: .4byte 0x020154A4
.L0807CD0C:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
.L0807CD12:
	adds r1, #0x14
	adds r3, #1
	ldrb r7, [r6]
	cmp r3, r7
	blt .L0807CCDC
.L0807CD1C:
	movs r0, #0
.L0807CD1E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0807CD24
func_fe6_0807CD24: @ 0x0807CD24
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r3, #0
	ldr r0, .L0807CD54 @ =0x020155E4
	ldrb r0, [r0]
	cmp r3, r0
	bge .L0807CD4C
	ldr r2, .L0807CD58 @ =0x020154A4
	adds r1, r0, #0
.L0807CD38:
	ldrb r0, [r2, #9]
	cmp r0, r4
	bne .L0807CD44
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
.L0807CD44:
	adds r2, #0x14
	subs r1, #1
	cmp r1, #0
	bne .L0807CD38
.L0807CD4C:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L0807CD54: .4byte 0x020155E4
.L0807CD58: .4byte 0x020154A4

	thumb_func_start func_fe6_0807CD5C
func_fe6_0807CD5C: @ 0x0807CD5C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov sl, r1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov sb, r3
	movs r0, #0
	mov r8, r0
	movs r7, #0
	ldr r0, .L0807CDEC @ =0x020155E4
	ldrb r0, [r0]
	cmp r7, r0
	bge .L0807CDDC
	ldr r0, .L0807CDF0 @ =0x020154A4
	adds r5, r0, #0
	adds r5, #8
	adds r6, r2, #0
.L0807CD8A:
	ldrb r0, [r5, #1]
	cmp r0, sl
	bne .L0807CDD0
	adds r0, r4, #0
	bl ClearText
	adds r0, r4, #0
	movs r1, #0
	bl Text_SetCursor
	movs r1, #0
	ldrb r0, [r5]
	cmp r0, #1
	bne .L0807CDA8
	movs r1, #1
.L0807CDA8:
	adds r0, r4, #0
	bl Text_SetColor
	ldr r0, [r5, #4]
	bl DecodeMsg
	adds r1, r0, #0
	adds r0, r4, #0
	bl Text_DrawString
	adds r0, r4, #0
	adds r1, r6, #0
	bl PutText
	adds r6, #0x80
	adds r4, #8
	movs r0, #1
	add r8, r0
	cmp r8, sb
	bge .L0807CDDC
.L0807CDD0:
	adds r5, #0x14
	adds r7, #1
	ldr r0, .L0807CDEC @ =0x020155E4
	ldrb r0, [r0]
	cmp r7, r0
	blt .L0807CD8A
.L0807CDDC:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0807CDEC: .4byte 0x020155E4
.L0807CDF0: .4byte 0x020154A4

	thumb_func_start func_fe6_0807CDF4
func_fe6_0807CDF4: @ 0x0807CDF4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	movs r0, #0
	mov sl, r0
	movs r4, #0
	ldr r0, .L0807CE4C @ =0x020155E4
	mov sb, r0
	ldrb r1, [r0]
	cmp r4, r1
	bge .L0807CE8A
	ldr r7, .L0807CE50 @ =0x020154A4
	mov ip, r7
	mov r3, r8
	adds r3, #0x35
	mov r6, ip
	movs r5, #0
.L0807CE1C:
	ldrb r0, [r6, #9]
	ldrb r1, [r3]
	cmp r0, r1
	bne .L0807CE7C
	ldrb r0, [r3]
	mov r2, r8
	adds r2, #0x33
	adds r1, r2, r0
	ldrb r7, [r1]
	cmp sl, r7
	bne .L0807CE72
	cmp r0, #0
	bne .L0807CE54
	ldrb r2, [r2]
	lsls r1, r2, #4
	adds r1, #0x28
	mov r0, ip
	adds r0, #4
	adds r0, r5, r0
	ldr r2, [r0]
	movs r0, #0xc
	bl StartHelpBox
	b .L0807CE68
	.align 2, 0
.L0807CE4C: .4byte 0x020155E4
.L0807CE50: .4byte 0x020154A4
.L0807CE54:
	ldrb r1, [r1]
	lsls r1, r1, #4
	adds r1, #0x48
	mov r0, ip
	adds r0, #4
	adds r0, r5, r0
	ldr r2, [r0]
	movs r0, #0xc
	bl StartHelpBox
.L0807CE68:
	mov r1, r8
	adds r1, #0x3d
	movs r0, #1
	strb r0, [r1]
	b .L0807CE8A
.L0807CE72:
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
.L0807CE7C:
	adds r6, #0x14
	adds r5, #0x14
	adds r4, #1
	mov r0, sb
	ldrb r0, [r0]
	cmp r4, r0
	blt .L0807CE1C
.L0807CE8A:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0807CE98
func_fe6_0807CE98: @ 0x0807CE98
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r4, #0
	movs r2, #0
	ldr r0, .L0807CED0 @ =0x020155E4
	ldrb r1, [r0]
	cmp r2, r1
	bge .L0807CEE6
	ldr r0, .L0807CED4 @ =0x020154A4
	adds r3, r5, #0
	adds r3, #0x35
	ldrb r6, [r3]
	mov ip, r6
	adds r6, r1, #0
	adds r1, r0, #0
	adds r1, #9
	adds r5, #0x33
.L0807CEBA:
	ldrb r7, [r1]
	cmp r7, ip
	bne .L0807CEDE
	ldrb r7, [r3]
	adds r0, r7, r5
	ldrb r0, [r0]
	cmp r4, r0
	bne .L0807CED8
	ldrb r0, [r1, #7]
	b .L0807CEE8
	.align 2, 0
.L0807CED0: .4byte 0x020155E4
.L0807CED4: .4byte 0x020154A4
.L0807CED8:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
.L0807CEDE:
	adds r1, #0x14
	adds r2, #1
	cmp r2, r6
	blt .L0807CEBA
.L0807CEE6:
	movs r0, #0xff
.L0807CEE8:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0807CEF0
func_fe6_0807CEF0: @ 0x0807CEF0
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r2, #0
	ldr r3, .L0807CF14 @ =0x020155E4
	ldrb r0, [r3]
	cmp r2, r0
	bge .L0807CF26
	ldr r0, .L0807CF18 @ =0x020154A4
	adds r0, #8
.L0807CF08:
	ldrb r5, [r0, #8]
	cmp r5, r4
	bne .L0807CF1C
	strb r1, [r0]
	b .L0807CF26
	.align 2, 0
.L0807CF14: .4byte 0x020155E4
.L0807CF18: .4byte 0x020154A4
.L0807CF1C:
	adds r0, #0x14
	adds r2, #1
	ldrb r5, [r3]
	cmp r2, r5
	blt .L0807CF08
.L0807CF26:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0807CF2C
func_fe6_0807CF2C: @ 0x0807CF2C
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	movs r1, #0
	movs r3, #0
	ldr r0, .L0807CF58 @ =0x020155E4
	ldrb r2, [r0]
	cmp r3, r2
	bge .L0807CF6E
	ldr r0, .L0807CF5C @ =0x020154A4
	adds r4, r2, #0
	adds r2, r0, #0
	adds r2, #9
.L0807CF4A:
	ldrb r0, [r2]
	cmp r0, r5
	bne .L0807CF66
	cmp r1, r6
	bne .L0807CF60
	ldrb r0, [r2, #7]
	b .L0807CF70
	.align 2, 0
.L0807CF58: .4byte 0x020155E4
.L0807CF5C: .4byte 0x020154A4
.L0807CF60:
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
.L0807CF66:
	adds r2, #0x14
	adds r3, #1
	cmp r3, r4
	blt .L0807CF4A
.L0807CF6E:
	movs r0, #0xff
.L0807CF70:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0807CF78
func_fe6_0807CF78: @ 0x0807CF78
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x34
	movs r1, #0xc
	bl InitTextDb
	adds r0, r4, #0
	adds r0, #0x3c
	movs r1, #0xc
	bl InitTextDb
	adds r0, r4, #0
	adds r0, #0x44
	movs r1, #0xc
	bl InitText
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0807CFA0
func_fe6_0807CFA0: @ 0x0807CFA0
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0807CFA4
func_fe6_0807CFA4: @ 0x0807CFA4
	push {lr}
	adds r1, r0, #0
	ldr r0, .L0807CFB4 @ =gUnk_08679368
	bl SpawnProc
	pop {r1}
	bx r1
	.align 2, 0
.L0807CFB4: .4byte gUnk_08679368

	thumb_func_start func_fe6_0807CFB8
func_fe6_0807CFB8: @ 0x0807CFB8
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0807CFBC
func_fe6_0807CFBC: @ 0x0807CFBC
	adds r1, r0, #0
	movs r0, #0
	strh r0, [r1, #0x2a]
	ldr r0, [r1, #0x14]
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #3
	bhi .L0807CFD2
	movs r0, #0xe4
	lsls r0, r0, #7
	b .L0807CFD6
.L0807CFD2:
	movs r0, #0xa0
	lsls r0, r0, #7
.L0807CFD6:
	str r0, [r1, #0x30]
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0807CFDC
func_fe6_0807CFDC: @ 0x0807CFDC
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r3, .L0807D06C @ =gUnk_086792B6
	ldr r0, [r4, #0x30]
	cmp r0, #0
	bge .L0807CFEC
	adds r0, #0x1f
.L0807CFEC:
	asrs r0, r0, #5
	str r0, [sp]
	movs r0, #0xb
	movs r1, #0x80
	lsls r1, r1, #5
	movs r2, #0
	bl PutSpriteExt
	ldr r3, .L0807D070 @ =gUnk_086792A8
	ldr r0, [r4, #0x30]
	cmp r0, #0
	bge .L0807D006
	adds r0, #0x1f
.L0807D006:
	asrs r0, r0, #5
	str r0, [sp]
	movs r0, #0xb
	movs r1, #0xb0
	movs r2, #0
	bl PutSpriteExt
	ldr r1, [r4, #0x14]
	adds r2, r1, #0
	adds r2, #0x2f
	ldrb r3, [r2]
	lsls r0, r3, #3
	subs r0, r0, r3
	lsls r0, r0, #4
	adds r0, #0x10
	adds r1, #0x2e
	ldrb r1, [r1]
	lsls r1, r1, #4
	adds r1, #0x48
	bl PutUiHand
	ldr r1, [r4, #0x14]
	adds r2, r1, #0
	adds r2, #0x30
	ldrb r0, [r2]
	cmp r0, #0xff
	beq .L0807D052
	ldrb r3, [r2]
	lsls r0, r3, #3
	subs r0, r0, r3
	lsls r0, r0, #4
	adds r0, #0x10
	adds r1, #0x31
	ldrb r1, [r1]
	lsls r1, r1, #4
	adds r1, #0x48
	bl PutFrozenUiHand
.L0807D052:
	ldrh r2, [r4, #0x2a]
	movs r0, #0
	movs r1, #4
	bl func_fe6_0807CFB8
	ldrh r0, [r4, #0x2a]
	adds r0, #1
	strh r0, [r4, #0x2a]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0807D06C: .4byte gUnk_086792B6
.L0807D070: .4byte gUnk_086792A8

	thumb_func_start func_fe6_0807D074
func_fe6_0807D074: @ 0x0807D074
	push {lr}
	adds r1, r0, #0
	ldr r0, .L0807D084 @ =gUnk_08679388
	bl SpawnProc
	pop {r1}
	bx r1
	.align 2, 0
.L0807D084: .4byte gUnk_08679388

	thumb_func_start func_fe6_0807D088
func_fe6_0807D088: @ 0x0807D088
	adds r1, r0, #0
	movs r0, #0
	strh r0, [r1, #0x2a]
	ldr r0, [r1, #0x14]
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #3
	bhi .L0807D09E
	movs r0, #0xe4
	lsls r0, r0, #7
	b .L0807D0A2
.L0807D09E:
	movs r0, #0xa0
	lsls r0, r0, #7
.L0807D0A2:
	str r0, [r1, #0x30]
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0807D0A8
func_fe6_0807D0A8: @ 0x0807D0A8
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r3, .L0807D160 @ =gUnk_086792B6
	ldr r0, [r4, #0x30]
	cmp r0, #0
	bge .L0807D0B8
	adds r0, #0x1f
.L0807D0B8:
	asrs r0, r0, #5
	str r0, [sp]
	movs r0, #0xb
	movs r1, #0x80
	lsls r1, r1, #5
	movs r2, #0
	bl PutSpriteExt
	ldr r3, .L0807D164 @ =gUnk_086792A8
	ldr r0, [r4, #0x30]
	cmp r0, #0
	bge .L0807D0D2
	adds r0, #0x1f
.L0807D0D2:
	asrs r0, r0, #5
	str r0, [sp]
	movs r0, #0xb
	movs r1, #0xb0
	movs r2, #0
	bl PutSpriteExt
	ldr r1, [r4, #0x14]
	adds r0, r1, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	cmp r0, #0x64
	bne .L0807D0FC
	adds r0, r1, #0
	adds r0, #0x31
	ldrb r0, [r0]
	lsls r1, r0, #4
	adds r1, #0x28
	movs r0, #0x80
	bl PutFrozenUiHand
.L0807D0FC:
	ldr r0, [r4, #0x14]
	adds r0, #0x46
	ldrb r0, [r0]
	ldrh r1, [r4, #0x2a]
	ldr r2, [r4, #0x30]
	bl func_fe6_0807DFEC
	ldr r1, [r4, #0x14]
	adds r0, r1, #0
	adds r0, #0x2f
	ldrb r2, [r0]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #4
	adds r0, #0x10
	adds r1, #0x2e
	ldrb r1, [r1]
	lsls r1, r1, #4
	lsls r2, r2, #5
	subs r2, #0x48
	subs r1, r1, r2
	bl PutUiHand
	ldr r1, [r4, #0x14]
	ldr r0, [r1, #0x60]
	adds r1, #0x50
	ldrh r1, [r1]
	str r1, [sp]
	ldr r1, .L0807D168 @ =0x0201636A
	ldrh r1, [r1]
	str r1, [sp, #4]
	movs r1, #7
	str r1, [sp, #8]
	movs r1, #0xe0
	movs r2, #0x30
	movs r3, #0xc
	bl func_fe6_08082320
	ldrh r2, [r4, #0x2a]
	movs r0, #3
	movs r1, #4
	bl func_fe6_0807CFB8
	ldrh r0, [r4, #0x2a]
	adds r0, #1
	strh r0, [r4, #0x2a]
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0807D160: .4byte gUnk_086792B6
.L0807D164: .4byte gUnk_086792A8
.L0807D168: .4byte 0x0201636A

	thumb_func_start func_fe6_0807D16C
func_fe6_0807D16C: @ 0x0807D16C
	push {lr}
	adds r1, r0, #0
	ldr r0, .L0807D17C @ =gUnk_086793A8
	bl SpawnProc
	pop {r1}
	bx r1
	.align 2, 0
.L0807D17C: .4byte gUnk_086793A8

	thumb_func_start func_fe6_0807D180
func_fe6_0807D180: @ 0x0807D180
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	strh r0, [r4, #0x2a]
	adds r0, r4, #0
	bl func_fe6_0807CFA4
	str r0, [r4, #0x2c]
	ldr r0, [r4, #0x14]
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #3
	bhi .L0807D1A0
	movs r0, #0xe4
	lsls r0, r0, #7
	b .L0807D1A4
.L0807D1A0:
	movs r0, #0xa0
	lsls r0, r0, #7
.L0807D1A4:
	str r0, [r4, #0x30]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0807D1AC
func_fe6_0807D1AC: @ 0x0807D1AC
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r3, .L0807D204 @ =gUnk_086792C4
	ldr r0, [r4, #0x30]
	cmp r0, #0
	bge .L0807D1BC
	adds r0, #0x1f
.L0807D1BC:
	asrs r0, r0, #5
	str r0, [sp]
	movs r0, #0xb
	movs r1, #0x88
	movs r2, #0
	bl PutSpriteExt
	ldr r1, [r4, #0x14]
	adds r0, r1, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0807D20C
	ldr r3, .L0807D208 @ =gUnk_086792B6
	ldr r0, [r4, #0x30]
	cmp r0, #0
	bge .L0807D1E0
	adds r0, #0x1f
.L0807D1E0:
	asrs r0, r0, #5
	str r0, [sp]
	movs r0, #0xb
	movs r1, #0x80
	lsls r1, r1, #5
	movs r2, #0
	bl PutSpriteExt
	ldr r0, [r4, #0x14]
	adds r0, #0x31
	ldrb r0, [r0]
	lsls r1, r0, #4
	adds r1, #0x48
	movs r0, #0xa0
	bl PutUiHand
	b .L0807D2BA
	.align 2, 0
.L0807D204: .4byte gUnk_086792C4
.L0807D208: .4byte gUnk_086792B6
.L0807D20C:
	adds r0, r1, #0
	adds r0, #0x31
	ldrb r0, [r0]
	cmp r0, #2
	beq .L0807D230
	ldr r3, .L0807D26C @ =gUnk_086792B6
	ldr r0, [r4, #0x30]
	cmp r0, #0
	bge .L0807D220
	adds r0, #0x1f
.L0807D220:
	asrs r0, r0, #5
	str r0, [sp]
	movs r0, #0xb
	movs r1, #0x80
	lsls r1, r1, #5
	movs r2, #0
	bl PutSpriteExt
.L0807D230:
	ldr r1, [r4, #0x14]
	adds r0, r1, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	cmp r0, #0x14
	bne .L0807D270
	adds r0, r1, #0
	adds r0, #0x2f
	ldrb r2, [r0]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #4
	adds r0, #0x10
	adds r1, #0x2e
	ldrb r1, [r1]
	lsls r1, r1, #4
	lsls r2, r2, #5
	subs r2, #0x48
	subs r1, r1, r2
	bl PutFrozenUiHand
	ldr r0, [r4, #0x14]
	adds r0, #0x30
	ldrb r0, [r0]
	lsls r0, r0, #5
	adds r0, #0x24
	movs r1, #0x40
	bl PutUiHand
	b .L0807D28E
	.align 2, 0
.L0807D26C: .4byte gUnk_086792B6
.L0807D270:
	adds r0, r1, #0
	adds r0, #0x2f
	ldrb r2, [r0]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #4
	adds r0, #0x10
	adds r1, #0x2e
	ldrb r1, [r1]
	lsls r1, r1, #4
	lsls r2, r2, #5
	subs r2, #0x48
	subs r1, r1, r2
	bl PutUiHand
.L0807D28E:
	ldr r0, [r4, #0x14]
	adds r0, #0x46
	ldrb r0, [r0]
	ldrh r1, [r4, #0x2a]
	ldr r2, [r4, #0x30]
	bl func_fe6_0807DFEC
	ldr r1, [r4, #0x14]
	ldr r0, [r1, #0x60]
	adds r1, #0x50
	ldrh r1, [r1]
	str r1, [sp]
	ldr r1, .L0807D2DC @ =0x0201636A
	ldrh r1, [r1]
	str r1, [sp, #4]
	movs r1, #7
	str r1, [sp, #8]
	movs r1, #0xe0
	movs r2, #0x30
	movs r3, #0xc
	bl func_fe6_08082320
.L0807D2BA:
	ldr r0, [r4, #0x14]
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #3
	bhi .L0807D2CE
	ldrh r2, [r4, #0x2a]
	movs r0, #2
	movs r1, #4
	bl func_fe6_0807CFB8
.L0807D2CE:
	ldrh r0, [r4, #0x2a]
	adds r0, #1
	strh r0, [r4, #0x2a]
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0807D2DC: .4byte 0x0201636A

	thumb_func_start func_fe6_0807D2E0
func_fe6_0807D2E0: @ 0x0807D2E0
	push {lr}
	adds r1, r0, #0
	ldr r0, .L0807D2F0 @ =gUnk_086793C8
	bl SpawnProc
	pop {r1}
	bx r1
	.align 2, 0
.L0807D2F0: .4byte gUnk_086793C8

	thumb_func_start func_fe6_0807D2F4
func_fe6_0807D2F4: @ 0x0807D2F4
	push {r4, lr}
	adds r3, r0, #0
	movs r2, #0
	ldr r1, .L0807D324 @ =0x02015698
.L0807D2FC:
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, r3
	beq .L0807D332
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x13
	bls .L0807D2FC
	movs r2, #0
	ldr r4, .L0807D324 @ =0x02015698
.L0807D314:
	lsls r0, r2, #2
	adds r1, r0, r4
	ldr r0, [r1]
	cmp r0, #0xff
	bne .L0807D328
	str r3, [r1]
	b .L0807D332
	.align 2, 0
.L0807D324: .4byte 0x02015698
.L0807D328:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x13
	bls .L0807D314
.L0807D332:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0807D338
func_fe6_0807D338: @ 0x0807D338
	push {lr}
	bl InitIcons
	ldr r1, .L0807D354 @ =0x02015698
	movs r2, #0xff
	adds r0, r1, #0
	adds r0, #0x4c
.L0807D346:
	str r2, [r0]
	subs r0, #4
	cmp r0, r1
	bge .L0807D346
	pop {r0}
	bx r0
	.align 2, 0
.L0807D354: .4byte 0x02015698

	thumb_func_start func_fe6_0807D358
func_fe6_0807D358: @ 0x0807D358
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x50
	mov r8, r0
	adds r0, #0x50
	ldrh r0, [r0]
	lsrs r0, r0, #4
	mov sb, r0
	mov r0, r8
	ldr r7, [r0, #0x54]
	adds r0, r7, #0
	bl GetUnitItemCount
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r5, #0
	movs r4, #0
	cmp r4, r6
	bhs .L0807D3A6
.L0807D382:
	lsls r1, r4, #1
	adds r0, r7, #0
	adds r0, #0x1c
	adds r0, r0, r1
	ldrh r0, [r0]
	bl GetItemIcon
	lsls r1, r5, #2
	add r1, sp
	str r0, [r1]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r6
	blo .L0807D382
.L0807D3A6:
	ldr r6, .L0807D45C @ =0x0201636A
	ldrh r0, [r6]
	cmp r0, #0
	beq .L0807D3D8
	ldr r2, .L0807D460 @ =0x02015D28
	mov r0, r8
	adds r0, #0x50
	ldrh r0, [r0]
	lsrs r0, r0, #4
	mov r1, r8
	adds r1, #0x2e
	ldrb r1, [r1]
	adds r0, r1, r0
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0, #2]
	bl GetItemKind
	lsls r1, r5, #2
	add r1, sp
	adds r0, #0x70
	str r0, [r1]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
.L0807D3D8:
	mov r0, sb
	cmp r0, #0
	beq .L0807D3E6
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
.L0807D3E6:
	mov r4, sb
	adds r0, r4, #0
	adds r0, #9
	cmp r4, r0
	bge .L0807D424
	ldrh r6, [r6]
	cmp r4, r6
	bhs .L0807D424
	ldr r6, .L0807D460 @ =0x02015D28
.L0807D3F8:
	lsls r0, r4, #2
	adds r0, r0, r6
	ldrh r0, [r0, #2]
	bl GetItemIcon
	lsls r1, r5, #2
	add r1, sp
	str r0, [r1]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	mov r0, sb
	adds r0, #9
	cmp r4, r0
	bge .L0807D424
	ldr r0, .L0807D45C @ =0x0201636A
	ldrh r0, [r0]
	cmp r4, r0
	blo .L0807D3F8
.L0807D424:
	cmp r5, #0x13
	bhi .L0807D43A
	movs r1, #0xff
.L0807D42A:
	lsls r0, r5, #2
	add r0, sp
	str r1, [r0]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0x13
	bls .L0807D42A
.L0807D43A:
	movs r4, #0
	ldr r7, .L0807D464 @ =0x02015698
.L0807D43E:
	ldr r0, .L0807D464 @ =0x02015698
	lsls r1, r4, #2
	adds r0, r1, r0
	ldr r3, [r0]
	adds r6, r4, #1
	adds r5, r1, #0
	cmp r3, #0xff
	beq .L0807D492
	movs r4, #0
	movs r2, #0
	ldr r0, [sp]
	cmp r3, r0
	bne .L0807D468
	movs r4, #1
	b .L0807D492
	.align 2, 0
.L0807D45C: .4byte 0x0201636A
.L0807D460: .4byte 0x02015D28
.L0807D464: .4byte 0x02015698
.L0807D468:
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0x13
	bhi .L0807D482
	adds r1, r5, r7
	lsls r0, r2, #2
	add r0, sp
	ldr r1, [r1]
	ldr r0, [r0]
	cmp r1, r0
	bne .L0807D468
	movs r4, #1
.L0807D482:
	cmp r4, #0
	bne .L0807D492
	adds r4, r5, r7
	ldr r0, [r4]
	bl ClearIcon
	movs r0, #0xff
	str r0, [r4]
.L0807D492:
	lsls r0, r6, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x13
	bls .L0807D43E
	add sp, #0x50
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0807D4A8
func_fe6_0807D4A8: @ 0x0807D4A8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r2, [sp, #8]
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp, #4]
	ldr r6, [r3, #0x2c]
	adds r0, r6, #0
	adds r0, #0x34
	bl ClearText
	adds r0, r6, #0
	adds r0, #0x3c
	bl ClearText
	adds r0, r6, #0
	adds r0, #0x44
	bl ClearText
	ldr r0, .L0807D4FC @ =0x0201636A
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0807D508
	ldr r0, .L0807D500 @ =gBg0Tm
	movs r1, #0xe
	movs r2, #0x13
	movs r3, #0
	bl TmFillRect_thm
	ldr r0, .L0807D504 @ =gBg1Tm
	movs r1, #0xe
	movs r2, #0x13
	movs r3, #0
	bl TmFillRect_thm
	b .L0807D692
	.align 2, 0
.L0807D4FC: .4byte 0x0201636A
.L0807D500: .4byte gBg0Tm
.L0807D504: .4byte gBg1Tm
.L0807D508:
	movs r0, #0
	str r0, [sp]
	adds r0, r7, #0
	ldr r1, [sp, #4]
	movs r2, #0xe
	movs r3, #8
	bl PutUiWindowFrame
	ldr r0, [sp, #8]
	bl GetItemKind
	cmp r0, #9
	beq .L0807D530
	cmp r0, #9
	bgt .L0807D52C
	cmp r0, #4
	beq .L0807D530
	b .L0807D578
.L0807D52C:
	cmp r0, #0xb
	bne .L0807D578
.L0807D530:
	ldr r0, [sp, #8]
	bl GetItemUseDescMsg
	bl DecodeMsg
	adds r4, r0, #0
	ldr r0, [sp, #4]
	adds r0, #1
	adds r6, #0x34
	lsls r0, r0, #5
	adds r0, #1
	adds r5, r0, r7
	b .L0807D550
.L0807D54A:
	adds r4, #1
	adds r5, #0x40
	adds r6, #8
.L0807D550:
	lsls r1, r5, #1
	ldr r0, .L0807D574 @ =gBg0Tm
	adds r1, r1, r0
	str r4, [sp]
	adds r0, r6, #0
	movs r2, #0
	movs r3, #0
	bl func_fe6_08082360
	adds r0, r4, #0
	bl GetStringLineEnd
	adds r4, r0, #0
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0807D54A
	b .L0807D692
	.align 2, 0
.L0807D574: .4byte gBg0Tm
.L0807D578:
	adds r5, r6, #0
	adds r5, #0x44
	ldr r3, .L0807D6A8 @ =gUnk_0832726C
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl Text_InsertDrawString
	adds r4, r6, #0
	adds r4, #0x34
	ldr r3, .L0807D6AC @ =gUnk_08327274
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	bl Text_InsertDrawString
	adds r6, #0x3c
	mov sl, r6
	ldr r3, .L0807D6B0 @ =gUnk_0832727C
	mov r0, sl
	movs r1, #2
	movs r2, #0
	bl Text_InsertDrawString
	ldr r3, .L0807D6B4 @ =gUnk_08327284
	adds r0, r4, #0
	movs r1, #0x32
	movs r2, #0
	bl Text_InsertDrawString
	ldr r3, .L0807D6B8 @ =gUnk_0832728C
	mov r0, sl
	movs r1, #0x32
	movs r2, #0
	bl Text_InsertDrawString
	ldr r6, [sp, #4]
	adds r6, #3
	lsls r6, r6, #5
	adds r1, r6, #1
	adds r1, r1, r7
	lsls r1, r1, #1
	ldr r0, .L0807D6BC @ =gBg0Tm
	mov sb, r0
	add r1, sb
	adds r0, r4, #0
	bl PutText
	ldr r0, [sp, #4]
	adds r0, #1
	lsls r0, r0, #5
	mov r8, r0
	mov r1, r8
	adds r1, #5
	adds r1, r1, r7
	lsls r1, r1, #1
	add r1, sb
	adds r0, r5, #0
	bl PutText
	ldr r5, [sp, #4]
	adds r5, #5
	lsls r5, r5, #5
	adds r1, r5, #1
	adds r1, r1, r7
	lsls r1, r1, #1
	add r1, sb
	mov r0, sl
	bl PutText
	adds r4, r6, #5
	adds r4, r4, r7
	lsls r4, r4, #1
	add r4, sb
	ldr r0, [sp, #8]
	bl GetItemMight
	adds r2, r0, #0
	adds r0, r4, #0
	movs r1, #2
	bl PutNumber
	adds r4, r5, #5
	adds r4, r4, r7
	lsls r4, r4, #1
	add r4, sb
	ldr r0, [sp, #8]
	bl GetItemHit
	adds r2, r0, #0
	adds r0, r4, #0
	movs r1, #2
	bl PutNumber
	adds r6, #0xb
	adds r6, r6, r7
	lsls r6, r6, #1
	add r6, sb
	ldr r0, [sp, #8]
	bl GetItemCrit
	adds r2, r0, #0
	adds r0, r6, #0
	movs r1, #2
	bl PutNumber
	adds r5, #0xb
	adds r5, r5, r7
	lsls r5, r5, #1
	add r5, sb
	ldr r0, [sp, #8]
	bl GetItemWeight
	adds r2, r0, #0
	adds r0, r5, #0
	movs r1, #2
	bl PutNumber
	movs r0, #7
	add r8, r0
	add r8, r7
	mov r0, r8
	lsls r0, r0, #1
	mov r8, r0
	add r8, sb
	ldr r0, [sp, #8]
	bl GetItemKind
	adds r1, r0, #0
	adds r1, #0x70
	movs r2, #0xa0
	lsls r2, r2, #7
	mov r0, r8
	bl PutIcon
	ldr r0, [sp, #8]
	bl GetItemKind
	adds r0, #0x70
	bl func_fe6_0807D2F4
.L0807D692:
	movs r0, #3
	bl EnableBgSync
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0807D6A8: .4byte gUnk_0832726C
.L0807D6AC: .4byte gUnk_08327274
.L0807D6B0: .4byte gUnk_0832727C
.L0807D6B4: .4byte gUnk_08327284
.L0807D6B8: .4byte gUnk_0832728C
.L0807D6BC: .4byte gBg0Tm

	thumb_func_start func_fe6_0807D6C0
func_fe6_0807D6C0: @ 0x0807D6C0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	str r1, [sp, #4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r1, #0
	bl GetUnitItemCount
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #8]
	movs r0, #0
	mov sl, r0
	ldr r2, [sp]
	lsls r1, r2, #2
	adds r0, r1, r2
	lsls r5, r0, #4
	adds r6, r1, #0
	lsls r3, r2, #3
	str r3, [sp, #0x14]
	subs r0, r3, r2
	lsls r4, r0, #1
.L0807D6F6:
	mov r1, sl
	lsls r0, r1, #3
	ldr r1, .L0807D82C @ =0x020155E8
	adds r0, r0, r1
	adds r0, r5, r0
	bl ClearText
	mov r2, sl
	lsls r0, r2, #6
	movs r3, #0x91
	lsls r3, r3, #1
	adds r0, r0, r3
	adds r0, r0, r4
	lsls r0, r0, #1
	ldr r1, .L0807D830 @ =gBg0Tm
	adds r0, r0, r1
	movs r1, #0xb
	movs r2, #1
	movs r3, #0
	bl TmFillRect_thm
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	cmp r0, #4
	bls .L0807D6F6
	movs r0, #0
	mov sl, r0
	ldr r1, [sp, #8]
	cmp sl, r1
	bhs .L0807D816
	ldr r2, [sp]
	adds r0, r6, r2
	lsls r0, r0, #4
	str r0, [sp, #0xc]
.L0807D740:
	mov r3, sl
	lsls r5, r3, #1
	ldr r0, [sp, #4]
	adds r0, #0x1c
	adds r0, r0, r5
	mov r8, r0
	ldrh r1, [r0]
	ldr r0, [sp, #4]
	bl IsItemDisplayUseable
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	rsbs r2, r0, #0
	orrs r2, r0
	mov r1, sl
	lsls r0, r1, #3
	ldr r1, .L0807D82C @ =0x020155E8
	adds r0, r0, r1
	ldr r3, [sp, #0xc]
	adds r4, r3, r0
	movs r1, #0
	lsrs r2, r2, #0x1f
	str r2, [sp, #0x10]
	cmp r2, #0
	bne .L0807D774
	movs r1, #1
.L0807D774:
	adds r0, r4, #0
	bl Text_SetColor
	adds r0, r4, #0
	movs r1, #0
	bl Text_SetCursor
	mov r1, r8
	ldrh r0, [r1]
	bl GetItemName
	adds r1, r0, #0
	adds r0, r4, #0
	bl Text_DrawString
	adds r0, r5, #0
	adds r0, #9
	lsls r6, r0, #5
	adds r1, r6, #4
	ldr r2, [sp, #0x14]
	ldr r3, [sp]
	subs r0, r2, r3
	lsls r5, r0, #1
	adds r1, r1, r5
	lsls r1, r1, #1
	ldr r0, .L0807D830 @ =gBg0Tm
	mov sb, r0
	add r1, sb
	adds r0, r4, #0
	bl PutText
	adds r0, r6, #0
	adds r0, #0xd
	adds r0, r0, r5
	lsls r0, r0, #1
	mov r1, sb
	adds r4, r0, r1
	movs r7, #1
	ldr r2, [sp, #0x10]
	cmp r2, #0
	beq .L0807D7C8
	movs r7, #2
.L0807D7C8:
	mov r3, r8
	ldrh r0, [r3]
	bl GetItemUses
	adds r2, r0, #0
	adds r0, r4, #0
	adds r1, r7, #0
	bl PutNumberOrBlank
	adds r4, r6, #2
	adds r4, r4, r5
	lsls r4, r4, #1
	add r4, sb
	mov r1, r8
	ldrh r0, [r1]
	bl GetItemIcon
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x80
	lsls r2, r2, #7
	bl PutIcon
	mov r2, r8
	ldrh r0, [r2]
	bl GetItemIcon
	bl func_fe6_0807D2F4
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	cmp r0, #4
	bhi .L0807D816
	ldr r3, [sp, #8]
	cmp sl, r3
	blo .L0807D740
.L0807D816:
	movs r0, #1
	bl EnableBgSync
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0807D82C: .4byte 0x020155E8
.L0807D830: .4byte gBg0Tm

	thumb_func_start func_fe6_0807D834
func_fe6_0807D834: @ 0x0807D834
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	lsls r0, r0, #0x19
	lsrs r0, r0, #0x18
	mov sl, r0
	ldr r1, .L0807D8A8 @ =0x0201636A
	movs r0, #0
	strh r0, [r1]
	movs r4, #0
	ldr r0, .L0807D8AC @ =0x02016368
	ldrh r0, [r0]
	cmp r4, r0
	bge .L0807D8A2
	ldr r7, .L0807D8B0 @ =gUnk_08679354
	mov r0, sl
	adds r0, #1
	adds r0, r0, r7
	mov r8, r0
	ldr r0, .L0807D8B4 @ =0x020156E8
	mov sb, r0
	adds r6, r1, #0
.L0807D866:
	ldr r1, .L0807D8B8 @ =0x02015D28
	lsls r0, r4, #2
	adds r5, r0, r1
	ldrh r0, [r5, #2]
	bl GetItemKind
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	mov r2, sl
	adds r0, r2, r7
	ldrb r0, [r0]
	cmp r1, r0
	blo .L0807D898
	mov r0, r8
	ldrb r0, [r0]
	cmp r1, r0
	bhi .L0807D898
	ldrh r1, [r6]
	lsls r0, r1, #2
	add r0, sb
	ldr r1, [r5]
	str r1, [r0]
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
.L0807D898:
	adds r4, #1
	ldr r0, .L0807D8AC @ =0x02016368
	ldrh r0, [r0]
	cmp r4, r0
	blt .L0807D866
.L0807D8A2:
	movs r2, #1
	b .L0807D8C2
	.align 2, 0
.L0807D8A8: .4byte 0x0201636A
.L0807D8AC: .4byte 0x02016368
.L0807D8B0: .4byte gUnk_08679354
.L0807D8B4: .4byte 0x020156E8
.L0807D8B8: .4byte 0x02015D28
.L0807D8BC:
	lsls r0, r2, #1
	adds r0, r0, r2
	adds r2, r0, #1
.L0807D8C2:
	ldr r1, .L0807D8E0 @ =0x0201636A
	ldrh r0, [r1]
	movs r1, #3
	str r2, [sp]
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, [sp]
	cmp r2, r0
	blt .L0807D8BC
	cmp r2, #0
	ble .L0807D95C
.L0807D8DC:
	adds r4, r2, #0
	b .L0807D946
	.align 2, 0
.L0807D8E0: .4byte 0x0201636A
.L0807D8E4:
	subs r7, r4, r2
	adds r4, #1
	mov sb, r4
	cmp r7, #0
	blt .L0807D944
	ldr r1, .L0807D9D0 @ =0x020156E8
	mov r8, r1
.L0807D8F2:
	lsls r0, r7, #2
	mov r1, r8
	adds r6, r0, r1
	ldrh r0, [r6, #2]
	str r2, [sp]
	bl GetItemIid
	adds r4, r0, #0
	ldr r2, [sp]
	adds r0, r7, r2
	lsls r0, r0, #2
	mov r1, r8
	adds r5, r0, r1
	ldrh r0, [r5, #2]
	bl GetItemIid
	ldr r2, [sp]
	cmp r4, r0
	bgt .L0807D936
	ldrh r0, [r6, #2]
	str r2, [sp]
	bl GetItemIid
	adds r4, r0, #0
	ldrh r0, [r5, #2]
	bl GetItemIid
	ldr r2, [sp]
	cmp r4, r0
	bne .L0807D944
	ldrh r0, [r6, #2]
	ldrh r1, [r5, #2]
	cmp r0, r1
	bls .L0807D93E
.L0807D936:
	ldr r1, [r6]
	ldr r0, [r5]
	str r0, [r6]
	str r1, [r5]
.L0807D93E:
	subs r7, r7, r2
	cmp r7, #0
	bge .L0807D8F2
.L0807D944:
	mov r4, sb
.L0807D946:
	ldr r0, .L0807D9D4 @ =0x0201636A
	ldrh r0, [r0]
	cmp r4, r0
	blt .L0807D8E4
	adds r0, r2, #0
	movs r1, #3
	bl __divsi3
	adds r2, r0, #0
	cmp r2, #0
	bgt .L0807D8DC
.L0807D95C:
	movs r7, #0
	movs r4, #0
	ldr r0, .L0807D9D8 @ =0x02016368
	ldrh r0, [r0]
	cmp r4, r0
	bge .L0807D9B2
	ldr r6, .L0807D9DC @ =gUnk_08679354
	mov r0, sl
	adds r0, #1
	adds r0, r0, r6
	mov r8, r0
	ldr r2, .L0807D9D0 @ =0x020156E8
	mov sb, r2
.L0807D976:
	ldr r1, .L0807D9E0 @ =0x02015D28
	lsls r0, r4, #2
	adds r5, r0, r1
	ldrh r0, [r5, #2]
	bl GetItemKind
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	mov r2, sl
	adds r0, r2, r6
	ldrb r0, [r0]
	cmp r1, r0
	blo .L0807D998
	mov r0, r8
	ldrb r0, [r0]
	cmp r1, r0
	bls .L0807D9A8
.L0807D998:
	ldr r0, .L0807D9D4 @ =0x0201636A
	ldrh r0, [r0]
	adds r0, r0, r7
	lsls r0, r0, #2
	add r0, sb
	ldr r1, [r5]
	str r1, [r0]
	adds r7, #1
.L0807D9A8:
	adds r4, #1
	ldr r0, .L0807D9D8 @ =0x02016368
	ldrh r0, [r0]
	cmp r4, r0
	blt .L0807D976
.L0807D9B2:
	ldr r0, .L0807D9E0 @ =0x02015D28
	ldr r1, .L0807D9D0 @ =0x020156E8
	movs r2, #0xc8
	lsls r2, r2, #3
	bl memcpy
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0807D9D0: .4byte 0x020156E8
.L0807D9D4: .4byte 0x0201636A
.L0807D9D8: .4byte 0x02016368
.L0807D9DC: .4byte gUnk_08679354
.L0807D9E0: .4byte 0x02015D28

	thumb_func_start func_fe6_0807D9E4
func_fe6_0807D9E4: @ 0x0807D9E4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sl, r0
	str r2, [sp]
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	str r3, [sp, #4]
	ldr r5, .L0807DAC4 @ =gBg2Tm
	adds r0, r5, #0
	movs r1, #0
	bl TmFill
	ldr r6, .L0807DAC8 @ =0x0201636A
	ldrh r0, [r6]
	cmp r0, #0
	bne .L0807DA40
	mov r0, sl
	bl ClearText
	mov r0, sl
	movs r1, #0
	bl Text_SetCursor
	mov r0, sl
	movs r1, #1
	bl Text_SetColor
	ldr r1, .L0807DACC @ =gUnk_08327294
	mov r0, sl
	bl Text_DrawString
	lsls r1, r4, #3
	subs r1, r1, r4
	lsls r1, r1, #2
	adds r0, r5, #0
	adds r0, #8
	adds r1, r1, r0
	mov r0, sl
	bl PutText
.L0807DA40:
	ldr r0, [sp, #4]
	mov r8, r0
	adds r0, #7
	cmp r8, r0
	blt .L0807DA4C
	b .L0807DB5E
.L0807DA4C:
	ldrh r6, [r6]
	cmp r8, r6
	blo .L0807DA54
	b .L0807DB5E
.L0807DA54:
	lsls r0, r4, #3
	subs r0, r0, r4
	lsls r0, r0, #1
	str r0, [sp, #8]
.L0807DA5C:
	movs r4, #7
	mov r1, r8
	ands r4, r1
	lsls r4, r4, #3
	add r4, sl
	adds r0, r4, #0
	bl ClearText
	adds r0, r4, #0
	movs r1, #0
	bl Text_SetCursor
	mov r0, r8
	lsls r6, r0, #1
	movs r4, #0x1f
	ands r4, r6
	lsls r4, r4, #5
	adds r4, #2
	ldr r1, [sp, #8]
	adds r4, r4, r1
	lsls r4, r4, #1
	ldr r0, .L0807DAC4 @ =gBg2Tm
	adds r4, r4, r0
	ldr r0, .L0807DAD0 @ =0x02015D28
	mov r1, r8
	lsls r5, r1, #2
	adds r7, r5, r0
	ldrh r0, [r7, #2]
	bl GetItemIcon
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x80
	lsls r2, r2, #7
	bl PutIcon
	ldrh r0, [r7, #2]
	bl GetItemIcon
	bl func_fe6_0807D2F4
	ldr r0, [sp]
	cmp r0, #0
	beq .L0807DAC0
	ldrh r1, [r7, #2]
	bl IsItemDisplayUseable
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0807DAD4
.L0807DAC0:
	movs r2, #1
	b .L0807DAD6
	.align 2, 0
.L0807DAC4: .4byte gBg2Tm
.L0807DAC8: .4byte 0x0201636A
.L0807DACC: .4byte gUnk_08327294
.L0807DAD0: .4byte 0x02015D28
.L0807DAD4:
	movs r2, #0
.L0807DAD6:
	movs r0, #7
	mov r1, r8
	ands r0, r1
	lsls r0, r0, #3
	mov r1, sl
	adds r7, r1, r0
	movs r1, #0
	mov sb, r2
	cmp r2, #0
	bne .L0807DAEC
	movs r1, #1
.L0807DAEC:
	adds r0, r7, #0
	bl Text_SetColor
	ldr r0, .L0807DB74 @ =0x02015D28
	adds r5, r5, r0
	ldrh r0, [r5, #2]
	bl GetItemName
	adds r1, r0, #0
	adds r0, r7, #0
	bl Text_DrawString
	movs r4, #0x1f
	ands r4, r6
	lsls r4, r4, #5
	adds r1, r4, #4
	ldr r0, [sp, #8]
	adds r1, r1, r0
	lsls r1, r1, #1
	ldr r0, .L0807DB78 @ =gBg2Tm
	adds r1, r1, r0
	adds r0, r7, #0
	bl PutText
	adds r4, #0xd
	ldr r1, [sp, #8]
	adds r4, r4, r1
	lsls r4, r4, #1
	ldr r0, .L0807DB78 @ =gBg2Tm
	adds r4, r4, r0
	movs r6, #1
	mov r1, sb
	cmp r1, #0
	beq .L0807DB32
	movs r6, #2
.L0807DB32:
	ldrh r0, [r5, #2]
	bl GetItemUses
	adds r2, r0, #0
	adds r0, r4, #0
	adds r1, r6, #0
	bl PutNumberOrBlank
	mov r0, r8
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	ldr r0, [sp, #4]
	adds r0, #7
	cmp r8, r0
	bge .L0807DB5E
	ldr r0, .L0807DB7C @ =0x0201636A
	ldrh r0, [r0]
	cmp r8, r0
	bhs .L0807DB5E
	b .L0807DA5C
.L0807DB5E:
	movs r0, #4
	bl EnableBgSync
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0807DB74: .4byte 0x02015D28
.L0807DB78: .4byte gBg2Tm
.L0807DB7C: .4byte 0x0201636A

	thumb_func_start func_fe6_0807DB80
func_fe6_0807DB80: @ 0x0807DB80
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp]
	adds r7, r3, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov sl, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r8, r2
	movs r0, #0xf
	mov sb, r8
	mov r1, sb
	ands r1, r0
	mov sb, r1
	lsls r4, r1, #6
	mov r2, sl
	lsls r5, r2, #3
	subs r5, r5, r2
	lsls r5, r5, #1
	adds r0, r4, r5
	lsls r0, r0, #1
	ldr r6, .L0807DC14 @ =gBg2Tm
	adds r0, r0, r6
	movs r1, #0x10
	movs r2, #1
	movs r3, #0
	bl TmFillRect_thm
	movs r0, #7
	mov r1, r8
	ands r0, r1
	lsls r0, r0, #3
	ldr r2, [sp]
	adds r0, r2, r0
	bl ClearText
	adds r4, #2
	adds r4, r4, r5
	lsls r4, r4, #1
	adds r4, r4, r6
	ldr r1, .L0807DC18 @ =0x02015D28
	mov r2, r8
	lsls r0, r2, #2
	adds r5, r0, r1
	ldrh r0, [r5, #2]
	bl GetItemIcon
	adds r1, r0, #0
	movs r2, #0x80
	lsls r2, r2, #7
	adds r0, r4, #0
	bl PutIcon
	ldrh r0, [r5, #2]
	bl GetItemIcon
	bl func_fe6_0807D2F4
	cmp r7, #0
	beq .L0807DC10
	ldrh r1, [r5, #2]
	adds r0, r7, #0
	bl IsItemDisplayUseable
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0807DC1C
.L0807DC10:
	movs r2, #1
	b .L0807DC1E
	.align 2, 0
.L0807DC14: .4byte gBg2Tm
.L0807DC18: .4byte 0x02015D28
.L0807DC1C:
	movs r2, #0
.L0807DC1E:
	movs r0, #7
	mov r1, r8
	ands r0, r1
	lsls r0, r0, #3
	ldr r1, [sp]
	adds r7, r1, r0
	movs r1, #0
	str r2, [sp, #4]
	cmp r2, #0
	bne .L0807DC34
	movs r1, #1
.L0807DC34:
	adds r0, r7, #0
	bl Text_SetColor
	adds r0, r7, #0
	movs r1, #0
	bl Text_SetCursor
	ldr r1, .L0807DCB0 @ =0x02015D28
	mov r2, r8
	lsls r0, r2, #2
	adds r0, r0, r1
	mov r8, r0
	ldrh r0, [r0, #2]
	bl GetItemName
	adds r1, r0, #0
	adds r0, r7, #0
	bl Text_DrawString
	mov r0, sb
	lsls r4, r0, #6
	adds r1, r4, #4
	mov r2, sl
	lsls r5, r2, #3
	subs r5, r5, r2
	lsls r5, r5, #1
	adds r1, r1, r5
	lsls r1, r1, #1
	ldr r6, .L0807DCB4 @ =gBg2Tm
	adds r1, r1, r6
	adds r0, r7, #0
	bl PutText
	adds r4, #0xd
	adds r4, r4, r5
	lsls r4, r4, #1
	adds r4, r4, r6
	movs r5, #1
	ldr r0, [sp, #4]
	cmp r0, #0
	beq .L0807DC88
	movs r5, #2
.L0807DC88:
	mov r1, r8
	ldrh r0, [r1, #2]
	bl GetItemUses
	adds r2, r0, #0
	adds r0, r4, #0
	adds r1, r5, #0
	bl PutNumberOrBlank
	movs r0, #4
	bl EnableBgSync
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0807DCB0: .4byte 0x02015D28
.L0807DCB4: .4byte gBg2Tm

	thumb_func_start func_fe6_0807DCB8
func_fe6_0807DCB8: @ 0x0807DCB8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	adds r6, r4, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r8, r2
	mov r0, r8
	str r0, [sp]
	lsls r3, r3, #0x18
	lsrs r7, r3, #0x18
	mov sl, r7
	ldr r0, .L0807DD04 @ =gBg0Tm+0x1E
	mov sb, r0
	movs r1, #0xf
	movs r2, #1
	movs r3, #0
	bl TmFillRect_thm
	ldr r0, .L0807DD08 @ =0x0201636A
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0807DD0C
	mov r0, sb
	adds r0, #0xa
	movs r1, #9
	movs r2, #1
	movs r3, #0
	bl TmFillRect_thm
	b .L0807DDB0
	.align 2, 0
.L0807DD04: .4byte gBg0Tm+0x1E
.L0807DD08: .4byte 0x0201636A
.L0807DD0C:
	cmp r4, #0
	bne .L0807DD58
	adds r0, r5, #0
	bl ClearText
	adds r0, r5, #0
	movs r1, #0
	bl Text_SetColor
	ldr r4, .L0807DD54 @ =gUnk_083272A4
	adds r0, r4, #0
	bl GetStringTextLen
	movs r1, #0x28
	subs r1, r1, r0
	lsrs r0, r1, #0x1f
	adds r1, r1, r0
	asrs r1, r1, #1
	adds r0, r5, #0
	bl Text_SetCursor
	adds r0, r5, #0
	adds r1, r4, #0
	bl Text_DrawString
	lsls r1, r7, #5
	add r1, r8
	lsls r1, r1, #1
	mov r0, sb
	subs r0, #0x1e
	adds r1, r1, r0
	adds r0, r5, #0
	bl PutText
	b .L0807DDB0
	.align 2, 0
.L0807DD54: .4byte gUnk_083272A4
.L0807DD58:
	adds r0, r6, #0
	bl GetUnitByPid
	adds r4, r0, #0
	adds r0, r5, #0
	bl ClearText
	adds r0, r5, #0
	movs r1, #0
	bl Text_SetColor
	ldr r0, [r4]
	ldrh r0, [r0]
	bl DecodeMsg
	bl GetStringTextLen
	movs r1, #0x28
	subs r1, r1, r0
	lsrs r0, r1, #0x1f
	adds r1, r1, r0
	asrs r1, r1, #1
	adds r0, r5, #0
	bl Text_SetCursor
	ldr r0, [r4]
	ldrh r0, [r0]
	bl DecodeMsg
	adds r1, r0, #0
	adds r0, r5, #0
	bl Text_DrawString
	mov r0, sl
	lsls r1, r0, #5
	ldr r0, [sp]
	adds r1, r1, r0
	lsls r1, r1, #1
	mov r0, sb
	subs r0, #0x1e
	adds r1, r1, r0
	adds r0, r5, #0
	bl PutText
.L0807DDB0:
	movs r0, #1
	bl EnableBgSync
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0807DDC8
func_fe6_0807DDC8: @ 0x0807DDC8
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r1, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	bl func_fe6_08082A08
	adds r6, r0, #0
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	lsls r4, r4, #5
	subs r0, r4, #3
	adds r0, r0, r5
	lsls r0, r0, #1
	ldr r1, .L0807DE54 @ =gBg0Tm
	mov r8, r1
	add r0, r8
	movs r1, #6
	movs r2, #1
	movs r3, #0
	bl TmFillRect_thm
	ldr r0, .L0807DE58 @ =0x02015690
	mov r1, r8
	adds r1, #0x24
	ldr r2, .L0807DE5C @ =gUnk_083272A4
	str r2, [sp]
	movs r2, #0
	movs r3, #4
	bl func_fe6_08082360
	adds r0, r4, r5
	lsls r0, r0, #1
	add r0, r8
	movs r1, #2
	adds r2, r6, #0
	bl PutNumber
	adds r0, r4, #4
	adds r0, r0, r5
	lsls r0, r0, #1
	add r0, r8
	movs r1, #2
	movs r2, #0x64
	bl PutNumber
	adds r4, #1
	adds r4, r4, r5
	lsls r4, r4, #1
	add r4, r8
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0x16
	bl PutSpecialChar
	movs r0, #1
	bl EnableBgSync
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0807DE54: .4byte gBg0Tm
.L0807DE58: .4byte 0x02015690
.L0807DE5C: .4byte gUnk_083272A4

	thumb_func_start func_fe6_0807DE60
func_fe6_0807DE60: @ 0x0807DE60
	push {r4, r5, r6, lr}
	bl GetSupplyItems
	adds r4, r0, #0
	movs r2, #0
	movs r3, #0
	ldr r0, .L0807DEC0 @ =0x02016368
	ldrh r1, [r0]
	cmp r2, r1
	bhs .L0807DE9C
	ldr r6, .L0807DEC4 @ =0x02015D28
	adds r5, r0, #0
.L0807DE78:
	lsls r0, r3, #2
	adds r1, r0, r6
	ldrb r0, [r1]
	cmp r0, #0
	bne .L0807DE90
	lsls r0, r2, #1
	adds r0, r0, r4
	ldrh r1, [r1, #2]
	strh r1, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
.L0807DE90:
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldrh r0, [r5]
	cmp r3, r0
	blo .L0807DE78
.L0807DE9C:
	cmp r2, #0x63
	bhi .L0807DEB2
	movs r1, #0
.L0807DEA2:
	lsls r0, r2, #1
	adds r0, r0, r4
	strh r1, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0x63
	bls .L0807DEA2
.L0807DEB2:
	movs r0, #0x18
	movs r1, #0
	bl func_fe6_0807DDC8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0807DEC0: .4byte 0x02016368
.L0807DEC4: .4byte 0x02015D28

	thumb_func_start func_fe6_0807DEC8
func_fe6_0807DEC8: @ 0x0807DEC8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	bl GetItemKind
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	movs r2, #0
	ldr r0, .L0807DF58 @ =gUnk_08679354
	ldrb r1, [r0]
	cmp r3, r1
	beq .L0807DF0A
	ldrb r1, [r0, #1]
	cmp r3, r1
	beq .L0807DF0A
	adds r4, r0, #0
.L0807DEEC:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #8
	bhi .L0807DF0A
	lsls r1, r2, #1
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r3, r0
	beq .L0807DF0A
	adds r0, r1, #1
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r3, r0
	bne .L0807DEEC
.L0807DF0A:
	adds r5, r6, #0
	adds r5, #0x46
	ldrb r0, [r5]
	cmp r0, r2
	beq .L0807DF4E
	strb r2, [r5]
	adds r0, r6, #0
	adds r0, #0x32
	adds r0, r2, r0
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r4, r6, #0
	adds r4, #0x50
	strh r0, [r4]
	ldrb r0, [r5]
	bl func_fe6_0807D834
	ldrb r0, [r5]
	adds r0, #0x3b
	adds r0, r6, r0
	adds r1, r4, #0
	bl func_fe6_080823A0
	ldr r0, .L0807DF5C @ =0x02015638
	ldr r2, [r6, #0x54]
	ldrh r4, [r4]
	lsrs r3, r4, #4
	movs r1, #1
	str r1, [sp]
	bl func_fe6_0807D9E4
	adds r0, r6, #0
	bl func_fe6_0807D358
.L0807DF4E:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0807DF58: .4byte gUnk_08679354
.L0807DF5C: .4byte 0x02015638

	thumb_func_start func_fe6_0807DF60
func_fe6_0807DF60: @ 0x0807DF60
	push {r4, r5, r6, r7, lr}
	lsls r1, r1, #0x18
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	ldr r6, .L0807DFD4 @ =0x02015D28
	lsls r4, r5, #2
	adds r4, r4, r6
	ldr r3, [r4]
	lsrs r1, r1, #0x17
	adds r2, r0, #0
	adds r2, #0x1c
	adds r2, r2, r1
	ldrh r1, [r2]
	strh r1, [r4, #2]
	lsrs r3, r3, #0x10
	strh r3, [r2]
	bl UnitRemoveInvalidItems
	ldrh r0, [r4, #2]
	cmp r0, #0
	bne .L0807DFE0
	adds r2, r5, #0
	ldr r0, .L0807DFD8 @ =0x02016368
	adds r4, r0, #0
	ldr r7, .L0807DFDC @ =0x0201636A
	ldrh r0, [r4]
	cmp r2, r0
	bhs .L0807DFC0
	adds r3, r6, #0
	adds r5, r4, #0
.L0807DF9C:
	lsls r0, r2, #2
	adds r1, r0, r3
	adds r2, #1
	lsls r0, r2, #2
	adds r0, r0, r3
	ldr r0, [r0]
	str r0, [r1]
	ldrb r0, [r1]
	cmp r0, #0
	bne .L0807DFB6
	ldrb r0, [r1, #1]
	subs r0, #1
	strb r0, [r1, #1]
.L0807DFB6:
	lsls r0, r2, #0x10
	lsrs r2, r0, #0x10
	ldrh r0, [r5]
	cmp r2, r0
	blo .L0807DF9C
.L0807DFC0:
	ldrh r0, [r7]
	subs r0, #1
	strh r0, [r7]
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	bl func_fe6_0807DE60
	movs r0, #1
	b .L0807DFE6
	.align 2, 0
.L0807DFD4: .4byte 0x02015D28
.L0807DFD8: .4byte 0x02016368
.L0807DFDC: .4byte 0x0201636A
.L0807DFE0:
	bl func_fe6_0807DE60
	movs r0, #0
.L0807DFE6:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0807DFEC
func_fe6_0807DFEC: @ 0x0807DFEC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r2, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r1, r1, #0x18
	ldr r3, .L0807E058 @ =gUnk_0831B068
	ldr r2, .L0807E05C @ =gPal
	lsrs r1, r1, #0x1a
	movs r0, #0xf
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r3
	ldrh r0, [r1]
	ldr r1, .L0807E060 @ =0x0000025A
	adds r2, r2, r1
	strh r0, [r2]
	bl EnablePalSync
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r6, r0, #0
	adds r6, #0x7c
	ldr r0, .L0807E064 @ =gUnk_08679330
	lsls r4, r4, #2
	adds r4, r4, r0
	ldr r3, [r4]
	adds r0, r5, #0
	cmp r5, #0
	bge .L0807E02E
	adds r0, #0x1f
.L0807E02E:
	asrs r0, r0, #5
	movs r1, #0x80
	lsls r1, r1, #6
	adds r4, r0, r1
	str r4, [sp]
	movs r0, #4
	adds r1, r6, #0
	movs r2, #0x18
	bl PutSprite
	ldr r3, .L0807E068 @ =gUnk_08679326
	str r4, [sp]
	movs r0, #4
	adds r1, r6, #0
	movs r2, #0x18
	bl PutSprite
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0807E058: .4byte gUnk_0831B068
.L0807E05C: .4byte gPal
.L0807E060: .4byte 0x0000025A
.L0807E064: .4byte gUnk_08679330
.L0807E068: .4byte gUnk_08679326

	thumb_func_start func_fe6_0807E06C
func_fe6_0807E06C: @ 0x0807E06C
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0807E0A8
	movs r1, #0
	ldr r0, .L0807E0A0 @ =gBg0Tm
	ldr r2, .L0807E0A4 @ =0x00003328
	adds r5, r2, #0
	adds r2, #0x40
	adds r4, r2, #0
	movs r2, #0x8f
	lsls r2, r2, #1
	adds r3, r0, r2
	adds r2, r0, #0
	adds r2, #0xde
.L0807E08A:
	adds r0, r1, r5
	strh r0, [r2]
	adds r0, r1, r4
	strh r0, [r3]
	adds r3, #2
	adds r2, #2
	adds r1, #1
	cmp r1, #0xe
	ble .L0807E08A
	b .L0807E0C4
	.align 2, 0
.L0807E0A0: .4byte gBg0Tm
.L0807E0A4: .4byte 0x00003328
.L0807E0A8:
	ldr r0, .L0807E0D0 @ =gBg0Tm
	movs r3, #0
	movs r1, #0x8f
	lsls r1, r1, #1
	adds r2, r0, r1
	adds r0, #0xde
	movs r1, #0xe
.L0807E0B6:
	strh r3, [r0]
	strh r3, [r2]
	adds r2, #2
	adds r0, #2
	subs r1, #1
	cmp r1, #0
	bge .L0807E0B6
.L0807E0C4:
	movs r0, #3
	bl EnableBgSync
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0807E0D0: .4byte gBg0Tm

	thumb_func_start func_fe6_0807E0D4
func_fe6_0807E0D4: @ 0x0807E0D4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x2d
	ldrb r0, [r6]
	cmp r0, #3
	bhi .L0807E0F4
	adds r1, r5, #0
	adds r1, #0x4b
	movs r0, #0
	strb r0, [r1]
.L0807E0F4:
	bl ResetText
	bl ResetTextFont
	ldr r3, .L0807E2B4 @ =gDispIo
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
	adds r0, r1, #0
	ldrb r2, [r3, #0x14]
	ands r0, r2
	strb r0, [r3, #0x14]
	ldrb r0, [r3, #0x18]
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	strb r1, [r3, #0x18]
	bl ClearIcons
	movs r4, #0
	str r6, [sp, #0x28]
	adds r1, r5, #0
	adds r1, #0x4b
	str r1, [sp, #0x10]
	adds r2, r5, #0
	adds r2, #0x50
	str r2, [sp, #0x18]
	adds r3, r5, #0
	adds r3, #0x45
	str r3, [sp, #4]
	movs r0, #0x2e
	adds r0, r0, r5
	mov sl, r0
	movs r1, #0x30
	adds r1, r1, r5
	mov r8, r1
	movs r2, #0x31
	adds r2, r2, r5
	mov sb, r2
	adds r3, #3
	str r3, [sp, #0xc]
	adds r0, r5, #0
	adds r0, #0x2c
	str r0, [sp, #0x24]
	adds r1, r5, #0
	adds r1, #0x52
	str r1, [sp, #0x1c]
	adds r2, r5, #0
	adds r2, #0x29
	str r2, [sp, #0x20]
	adds r3, #6
	str r3, [sp, #0x14]
	adds r0, #0x1b
	str r0, [sp, #8]
	adds r7, r5, #0
	adds r7, #0x4c
	subs r1, #0x20
	str r1, [sp, #0x2c]
	adds r2, #0x12
	str r2, [sp, #0x30]
	ldr r2, .L0807E2B8 @ =0x02015698
	movs r1, #0xff
.L0807E182:
	lsls r0, r4, #2
	adds r0, r0, r2
	str r1, [r0]
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x13
	bls .L0807E182
	ldr r0, .L0807E2BC @ =gBg0Tm
	movs r1, #0
	bl TmFill
	ldr r0, .L0807E2C0 @ =gBg1Tm
	movs r1, #0
	bl TmFill
	ldr r0, .L0807E2C4 @ =gBg2Tm
	movs r1, #0
	bl TmFill
	bl InitIcons
	movs r0, #4
	bl ApplyIconPalettes
	bl UnpackUiWindowFrameGraphics
	ldr r4, .L0807E2C8 @ =0x02015688
	adds r0, r4, #0
	movs r1, #6
	bl InitText
	adds r4, #8
	adds r0, r4, #0
	movs r1, #5
	bl InitTextDb
	movs r4, #0
	ldr r6, .L0807E2CC @ =0x020155E8
.L0807E1D0:
	lsls r0, r4, #3
	adds r0, r0, r6
	movs r1, #7
	bl InitTextDb
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #4
	bls .L0807E1D0
	movs r4, #0
	ldr r6, .L0807E2D0 @ =0x02015638
.L0807E1E8:
	lsls r0, r4, #3
	adds r0, r0, r6
	movs r1, #7
	bl InitTextDb
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #7
	bls .L0807E1E8
	ldr r0, .L0807E2D4 @ =gUnk_08319E88
	movs r1, #0x90
	lsls r1, r1, #2
	movs r2, #0x60
	bl ApplyPaletteExt
	ldr r0, .L0807E2D8 @ =gUnk_0831AABC
	movs r1, #0xc0
	lsls r1, r1, #2
	movs r2, #0x40
	bl ApplyPaletteExt
	ldr r0, .L0807E2DC @ =gUnk_0831A248
	movs r1, #0x60
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, .L0807E2E0 @ =gUnk_08319EE8
	ldr r1, .L0807E2E4 @ =gBg0Tm+0x500
	bl Decompress
	ldr r0, .L0807E2E8 @ =gUnk_0831A088
	ldr r1, .L0807E2EC @ =gBg1Tm+0x500
	bl Decompress
	movs r4, #0
	movs r2, #0
	ldr r3, [sp, #0x18]
	strh r2, [r3]
	ldr r0, [sp, #4]
	strb r4, [r0]
	mov r1, sl
	strb r4, [r1]
	movs r0, #0xff
	mov r3, r8
	ldrb r1, [r3]
	orrs r1, r0
	strb r1, [r3]
	mov r1, sb
	ldrb r1, [r1]
	orrs r0, r1
	mov r3, sb
	strb r0, [r3]
	ldr r0, [sp, #0xc]
	strb r4, [r0]
	ldr r1, [sp, #0x24]
	strb r4, [r1]
	ldr r3, [sp, #0x1c]
	strh r2, [r3]
	ldr r0, [sp, #0x20]
	strb r4, [r0]
	ldr r1, [sp, #0x14]
	strh r2, [r1]
	ldr r2, [sp, #8]
	strb r4, [r2]
	adds r0, r5, #0
	bl func_fe6_0808230C
	str r0, [r5, #0x60]
	ldr r3, [sp, #0x28]
	ldrb r3, [r3]
	cmp r3, #3
	bhi .L0807E300
	ldr r0, .L0807E2F0 @ =gUnk_0831AB1C
	ldr r1, .L0807E2F4 @ =0x06011000
	bl Decompress
	ldr r0, .L0807E2F8 @ =gUnk_083198CC
	ldr r1, .L0807E2FC @ =0x06017200
	bl Decompress
	ldr r1, [r5, #0x14]
	ldr r0, [r1, #0x48]
	str r0, [r5, #0x54]
	ldr r0, [r1, #0x4c]
	str r0, [r5, #0x58]
	ldr r0, [r5, #0x60]
	movs r1, #0xe4
	lsls r1, r1, #7
	movs r2, #2
	bl func_fe6_08082348
	ldr r1, [r5, #0x14]
	adds r1, #0x2c
	movs r2, #1
	adds r0, r2, #0
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq .L0807E314
	strb r2, [r7]
	b .L0807E316
	.align 2, 0
.L0807E2B4: .4byte gDispIo
.L0807E2B8: .4byte 0x02015698
.L0807E2BC: .4byte gBg0Tm
.L0807E2C0: .4byte gBg1Tm
.L0807E2C4: .4byte gBg2Tm
.L0807E2C8: .4byte 0x02015688
.L0807E2CC: .4byte 0x020155E8
.L0807E2D0: .4byte 0x02015638
.L0807E2D4: .4byte gUnk_08319E88
.L0807E2D8: .4byte gUnk_0831AABC
.L0807E2DC: .4byte gUnk_0831A248
.L0807E2E0: .4byte gUnk_08319EE8
.L0807E2E4: .4byte gBg0Tm+0x500
.L0807E2E8: .4byte gUnk_0831A088
.L0807E2EC: .4byte gBg1Tm+0x500
.L0807E2F0: .4byte gUnk_0831AB1C
.L0807E2F4: .4byte 0x06011000
.L0807E2F8: .4byte gUnk_083198CC
.L0807E2FC: .4byte 0x06017200
.L0807E300:
	ldr r0, .L0807E40C @ =gUnk_083198CC
	ldr r1, .L0807E410 @ =0x06015000
	bl Decompress
	ldr r0, [r5, #0x60]
	movs r1, #0xa0
	lsls r1, r1, #7
	movs r2, #2
	bl func_fe6_08082348
.L0807E314:
	strb r4, [r7]
.L0807E316:
	ldr r1, [sp, #0x10]
	ldrb r0, [r1]
	cmp r0, #0
	bne .L0807E394
	str r0, [sp]
	movs r0, #1
	movs r1, #8
	movs r2, #0xe
	movs r3, #0xc
	bl PutUiWindowFrame
	ldr r4, .L0807E414 @ =0x02015688
	adds r0, r4, #0
	bl ClearText
	adds r0, r4, #0
	movs r1, #0
	bl Text_SetColor
	ldr r0, [r5, #0x54]
	ldr r0, [r0]
	ldrh r0, [r0]
	bl DecodeMsg
	bl GetStringTextLen
	movs r1, #0x30
	subs r1, r1, r0
	lsrs r0, r1, #0x1f
	adds r1, r1, r0
	asrs r1, r1, #1
	adds r0, r4, #0
	bl Text_SetCursor
	ldr r0, [r5, #0x54]
	ldr r0, [r0]
	ldrh r0, [r0]
	bl DecodeMsg
	adds r1, r0, #0
	adds r0, r4, #0
	bl Text_DrawString
	ldr r1, .L0807E418 @ =gBg0Tm
	adds r0, r4, #0
	bl PutText
	ldr r1, [r5, #0x54]
	movs r0, #0
	bl func_fe6_0807D6C0
	ldr r0, [r5, #0x54]
	bl GetUnitFid
	adds r1, r0, #0
	movs r3, #4
	rsbs r3, r3, #0
	movs r0, #3
	str r0, [sp]
	movs r0, #0
	movs r2, #0x40
	bl StartFace
.L0807E394:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	ldr r2, [sp, #4]
	ldrb r1, [r2]
	ldr r3, [sp, #0x18]
	ldrh r2, [r3]
	subs r2, #0x28
	movs r0, #0xff
	ands r2, r0
	movs r0, #2
	bl SetBgOffset
	movs r4, #0
	ldr r3, [sp, #0x2c]
	movs r1, #0
	ldr r2, [sp, #0x30]
.L0807E3C4:
	adds r0, r3, r4
	strb r1, [r0]
	adds r0, r2, r4
	strb r1, [r0]
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #8
	bls .L0807E3C4
	movs r0, #7
	bl EnableBgSync
	ldr r0, [sp, #0x28]
	ldrb r0, [r0]
	cmp r0, #3
	bhi .L0807E3F0
	adds r0, r5, #0
	adds r0, #0x2a
	ldrb r1, [r0]
	adds r0, r5, #0
	bl Proc_Goto
.L0807E3F0:
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0
	bl func_fe6_08070E70
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0807E40C: .4byte gUnk_083198CC
.L0807E410: .4byte 0x06015000
.L0807E414: .4byte 0x02015688
.L0807E418: .4byte gBg0Tm

	thumb_func_start func_fe6_0807E41C
func_fe6_0807E41C: @ 0x0807E41C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r6, #0
	str r6, [sp]
	movs r0, #0xf
	movs r1, #8
	movs r2, #0xe
	movs r3, #0xc
	bl PutUiWindowFrame
	ldr r4, .L0807E4B8 @ =0x02015690
	adds r0, r4, #0
	bl ClearText
	adds r0, r4, #0
	movs r1, #0
	bl Text_SetColor
	ldr r0, [r5, #0x58]
	ldr r0, [r0]
	ldrh r0, [r0]
	bl DecodeMsg
	bl GetStringTextLen
	movs r1, #0x28
	subs r1, r1, r0
	lsrs r0, r1, #0x1f
	adds r1, r1, r0
	asrs r1, r1, #1
	adds r0, r4, #0
	bl Text_SetCursor
	ldr r0, [r5, #0x58]
	ldr r0, [r0]
	ldrh r0, [r0]
	bl DecodeMsg
	adds r1, r0, #0
	adds r0, r4, #0
	bl Text_DrawString
	ldr r1, .L0807E4BC @ =gBg0Tm+0x30
	adds r0, r4, #0
	bl PutText
	ldr r1, [r5, #0x58]
	movs r0, #1
	bl func_fe6_0807D6C0
	ldr r0, [r5, #0x58]
	bl GetUnitFid
	adds r1, r0, #0
	movs r3, #4
	rsbs r3, r3, #0
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	movs r2, #0xac
	bl StartFace
	adds r0, r5, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #3
	beq .L0807E4CE
	ldr r0, [r5, #0x54]
	bl GetUnitItemCount
	cmp r0, #0
	bne .L0807E4C0
	adds r1, r5, #0
	adds r1, #0x2f
	movs r0, #1
	strb r0, [r1]
	b .L0807E4C6
	.align 2, 0
.L0807E4B8: .4byte 0x02015690
.L0807E4BC: .4byte gBg0Tm+0x30
.L0807E4C0:
	adds r0, r5, #0
	adds r0, #0x2f
	strb r6, [r0]
.L0807E4C6:
	adds r1, r5, #0
	adds r1, #0x2e
	movs r0, #0
	strb r0, [r1]
.L0807E4CE:
	adds r2, r5, #0
	adds r2, #0x30
	movs r0, #0xff
	ldrb r1, [r2]
	orrs r1, r0
	strb r1, [r2]
	adds r1, r5, #0
	adds r1, #0x31
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
	subs r1, #2
	ldrb r2, [r1]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	subs r1, #1
	ldrb r1, [r1]
	lsls r1, r1, #1
	adds r1, #9
	movs r2, #0xc
	bl PutUiEntryHover
	movs r0, #0xf
	bl EnableBgSync
	adds r1, r5, #0
	adds r1, #0x2c
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x2d
	ldrb r1, [r0]
	adds r4, r0, #0
	cmp r1, #0
	bne .L0807E524
	movs r1, #1
	rsbs r1, r1, #0
	adds r0, r5, #0
	bl func_fe6_080829E8
	b .L0807E52E
.L0807E524:
	cmp r1, #3
	bne .L0807E52E
	ldr r0, [r5, #0x5c]
	bl Proc_End
.L0807E52E:
	adds r0, r5, #0
	bl func_fe6_0807D074
	str r0, [r5, #0x5c]
	movs r0, #1
	strb r0, [r4]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0807E544
func_fe6_0807E544: @ 0x0807E544
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x54]
	bl GetUnitItemCount
	adds r5, r4, #0
	adds r5, #0x3b
	strb r0, [r5]
	ldr r0, [r4, #0x58]
	bl GetUnitItemCount
	adds r1, r4, #0
	adds r1, #0x3c
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #1
	bne .L0807E57E
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0807E57E
	ldrb r0, [r5]
	cmp r0, #4
	bhi .L0807E57E
	adds r0, #1
	strb r0, [r5]
.L0807E57E:
	adds r0, r4, #0
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0807E5A0
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0807E5A0
	adds r1, r4, #0
	adds r1, #0x3c
	ldrb r0, [r1]
	cmp r0, #4
	bhi .L0807E5A0
	adds r0, #1
	strb r0, [r1]
.L0807E5A0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0807E5A8
func_fe6_0807E5A8: @ 0x0807E5A8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r6, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	str r0, [sp, #4]
	adds r0, r6, #0
	bl func_fe6_0807E544
	adds r4, r6, #0
	adds r4, #0x29
	ldrb r0, [r4]
	cmp r0, #2
	bne .L0807E5F4
	ldr r0, .L0807E5F0 @ =gKeySt
	ldr r1, [r0]
	movs r0, #0x81
	lsls r0, r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L0807E5F4
	bl CloseHelpBox
	movs r0, #0
	strb r0, [r4]
	b .L0807EB60
	.align 2, 0
.L0807E5F0: .4byte gKeySt
.L0807E5F4:
	ldr r2, .L0807E674 @ =gKeySt
	ldr r1, [r2]
	movs r0, #0x20
	ldrh r1, [r1, #6]
	ands r0, r1
	mov r8, r2
	cmp r0, #0
	beq .L0807E67C
	adds r0, r6, #0
	adds r0, #0x2f
	adds r5, r0, #0
	ldrb r1, [r5]
	cmp r1, #1
	bne .L0807E67C
	adds r7, r6, #0
	adds r7, #0x3b
	ldrb r0, [r7]
	adds r2, r6, #0
	adds r2, #0x29
	str r2, [sp, #8]
	cmp r0, #0
	bne .L0807E622
	b .L0807EB1A
.L0807E622:
	ldr r0, .L0807E678 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807E632
	movs r0, #0x67
	bl m4aSongNumStart
.L0807E632:
	ldrb r3, [r5]
	lsls r0, r3, #3
	subs r0, r0, r3
	lsls r0, r0, #1
	adds r0, #2
	adds r4, r6, #0
	adds r4, #0x2e
	ldrb r2, [r4]
	lsls r1, r2, #1
	adds r1, #9
	movs r2, #0xc
	bl RemoveUiEntryHover
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	adds r0, r0, r7
	ldrb r0, [r0]
	ldrb r3, [r4]
	cmp r3, r0
	blo .L0807E660
	subs r0, #1
	strb r0, [r4]
.L0807E660:
	ldrb r7, [r5]
	lsls r0, r7, #3
	adds r5, r7, #0
	subs r0, r0, r5
	lsls r0, r0, #1
	adds r0, #2
	ldrb r4, [r4]
	lsls r1, r4, #1
	b .L0807EAB2
	.align 2, 0
.L0807E674: .4byte gKeySt
.L0807E678: .4byte gPlaySt
.L0807E67C:
	mov r0, r8
	ldr r1, [r0]
	movs r0, #0x10
	ldrh r1, [r1, #6]
	ands r0, r1
	cmp r0, #0
	beq .L0807E700
	adds r0, r6, #0
	adds r0, #0x2f
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	bne .L0807E700
	adds r0, #0xd
	ldrb r0, [r0]
	adds r1, r6, #0
	adds r1, #0x29
	str r1, [sp, #8]
	cmp r0, #0
	bne .L0807E6A6
	b .L0807EB1A
.L0807E6A6:
	ldr r0, .L0807E6FC @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807E6B6
	movs r0, #0x67
	bl m4aSongNumStart
.L0807E6B6:
	ldrb r2, [r5]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	adds r4, r6, #0
	adds r4, #0x2e
	ldrb r3, [r4]
	lsls r1, r3, #1
	adds r1, #9
	movs r2, #0xc
	bl RemoveUiEntryHover
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	adds r0, r6, #0
	adds r0, #0x3b
	ldrb r7, [r5]
	adds r0, r7, r0
	ldrb r0, [r0]
	ldrb r1, [r4]
	cmp r1, r0
	blo .L0807E6EA
	subs r0, #1
	strb r0, [r4]
.L0807E6EA:
	ldrb r2, [r5]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	ldrb r4, [r4]
	lsls r1, r4, #1
	b .L0807EAB2
	.align 2, 0
.L0807E6FC: .4byte gPlaySt
.L0807E700:
	mov r3, r8
	ldr r1, [r3]
	movs r4, #0x40
	mov sb, r4
	mov r0, sb
	ldrh r1, [r1, #6]
	ands r0, r1
	cmp r0, #0
	beq .L0807E7AC
	adds r0, r6, #0
	adds r0, #0x2f
	ldrb r2, [r0]
	adds r7, r6, #0
	adds r7, #0x3b
	adds r1, r7, r2
	ldrb r1, [r1]
	adds r5, r0, #0
	cmp r1, #0
	beq .L0807E7AC
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	adds r4, r6, #0
	adds r4, #0x2e
	ldrb r2, [r4]
	lsls r1, r2, #1
	adds r1, #9
	movs r2, #0xc
	bl RemoveUiEntryHover
	ldrb r0, [r4]
	cmp r0, #0
	beq .L0807E760
	subs r0, #1
	strb r0, [r4]
	ldr r0, .L0807E75C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807E788
	movs r0, #0x66
	bl m4aSongNumStart
	b .L0807E788
	.align 2, 0
.L0807E75C: .4byte gPlaySt
.L0807E760:
	mov r3, r8
	ldr r1, [r3]
	mov r0, sb
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L0807E788
	ldrb r1, [r5]
	adds r0, r1, r7
	ldrb r0, [r0]
	subs r0, #1
	strb r0, [r4]
	ldr r0, .L0807E7A8 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807E788
	movs r0, #0x66
	bl m4aSongNumStart
.L0807E788:
	ldrb r2, [r5]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	ldrb r4, [r4]
	lsls r1, r4, #1
	adds r1, #9
	movs r2, #0xc
	bl PutUiEntryHover
	adds r3, r6, #0
	adds r3, #0x29
	str r3, [sp, #8]
	b .L0807EB1A
	.align 2, 0
.L0807E7A8: .4byte gPlaySt
.L0807E7AC:
	mov r4, r8
	ldr r1, [r4]
	movs r7, #0x80
	mov sb, r7
	mov r0, sb
	ldrh r1, [r1, #6]
	ands r0, r1
	cmp r0, #0
	beq .L0807E858
	adds r0, r6, #0
	adds r0, #0x2f
	ldrb r2, [r0]
	adds r7, r6, #0
	adds r7, #0x3b
	adds r1, r7, r2
	ldrb r1, [r1]
	adds r5, r0, #0
	cmp r1, #0
	beq .L0807E858
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	adds r4, r6, #0
	adds r4, #0x2e
	ldrb r2, [r4]
	lsls r1, r2, #1
	adds r1, #9
	movs r2, #0xc
	bl RemoveUiEntryHover
	ldrb r1, [r4]
	ldrb r3, [r5]
	adds r0, r3, r7
	ldrb r0, [r0]
	subs r0, #1
	cmp r1, r0
	bge .L0807E814
	adds r0, r1, #1
	strb r0, [r4]
	ldr r0, .L0807E810 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807E836
	movs r0, #0x66
	bl m4aSongNumStart
	b .L0807E836
	.align 2, 0
.L0807E810: .4byte gPlaySt
.L0807E814:
	mov r7, r8
	ldr r1, [r7]
	mov r0, sb
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L0807E836
	movs r0, #0
	strb r0, [r4]
	ldr r0, .L0807E854 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807E836
	movs r0, #0x66
	bl m4aSongNumStart
.L0807E836:
	ldrb r1, [r5]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, #2
	ldrb r4, [r4]
	lsls r1, r4, #1
	adds r1, #9
	movs r2, #0xc
	bl PutUiEntryHover
	adds r2, r6, #0
	adds r2, #0x29
	str r2, [sp, #8]
	b .L0807EB1A
	.align 2, 0
.L0807E854: .4byte gPlaySt
.L0807E858:
	mov r3, r8
	ldr r1, [r3]
	movs r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	adds r4, r6, #0
	adds r4, #0x29
	str r4, [sp, #8]
	cmp r0, #0
	bne .L0807E86E
	b .L0807EA22
.L0807E86E:
	ldrb r0, [r4]
	cmp r0, #0
	beq .L0807E876
	b .L0807EA22
.L0807E876:
	ldr r0, .L0807E8F8 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807E886
	movs r0, #0x6a
	bl m4aSongNumStart
.L0807E886:
	adds r0, r6, #0
	adds r0, #0x30
	ldrb r1, [r0]
	mov sb, r0
	cmp r1, #0xff
	bne .L0807E8FC
	adds r5, r6, #0
	adds r5, #0x2f
	ldrb r0, [r5]
	mov r7, sb
	strb r0, [r7]
	adds r4, r6, #0
	adds r4, #0x2e
	ldrb r0, [r4]
	adds r1, r6, #0
	adds r1, #0x31
	strb r0, [r1]
	ldrb r1, [r5]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, #2
	ldrb r2, [r4]
	lsls r1, r2, #1
	adds r1, #9
	movs r2, #0xc
	bl RemoveUiEntryHover
	ldrb r0, [r5]
	adds r0, #1
	movs r1, #1
	ands r0, r1
	strb r0, [r5]
	lsls r1, r0, #2
	adds r0, r6, #0
	adds r0, #0x54
	adds r0, r0, r1
	ldr r0, [r0]
	bl GetUnitItemCount
	cmp r0, #4
	bgt .L0807E8E6
	adds r0, r6, #0
	adds r0, #0x3b
	ldrb r3, [r5]
	adds r0, r3, r0
	ldrb r0, [r0]
	strb r0, [r4]
.L0807E8E6:
	ldrb r7, [r5]
	lsls r0, r7, #3
	adds r5, r7, #0
	subs r0, r0, r5
	lsls r0, r0, #1
	adds r0, #2
	ldrb r4, [r4]
	lsls r1, r4, #1
	b .L0807EAB2
	.align 2, 0
.L0807E8F8: .4byte gPlaySt
.L0807E8FC:
	adds r0, r6, #0
	adds r0, #0x4c
	ldrb r0, [r0]
	adds r5, r6, #0
	adds r5, #0x2f
	adds r4, r6, #0
	adds r4, #0x2e
	movs r1, #0x31
	adds r1, r1, r6
	mov sl, r1
	adds r7, r6, #0
	adds r7, #0x54
	cmp r0, #0
	beq .L0807E958
	mov r2, sb
	ldrb r2, [r2]
	lsls r0, r2, #2
	adds r0, r7, r0
	ldr r0, [r0]
	ldrb r1, [r1]
	ldrb r3, [r5]
	lsls r2, r3, #2
	adds r2, r7, r2
	ldr r2, [r2]
	ldrb r3, [r4]
	bl func_fe6_08082B98
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0807E958
	ldrb r7, [r5]
	lsls r0, r7, #3
	adds r5, r7, #0
	subs r0, r0, r5
	lsls r0, r0, #4
	adds r0, #0x10
	ldrb r4, [r4]
	lsls r1, r4, #4
	adds r1, #0x48
	ldr r2, .L0807E954 @ =0x000006C2
	adds r3, r6, #0
	bl func_fe6_08082B00
	b .L0807EB1A
	.align 2, 0
.L0807E954: .4byte 0x000006C2
.L0807E958:
	mov r1, sb
	ldrb r1, [r1]
	lsls r0, r1, #2
	adds r0, r7, r0
	ldr r1, [r0]
	mov r8, sl
	mov r2, r8
	ldrb r2, [r2]
	lsls r0, r2, #1
	adds r1, #0x1c
	adds r1, r1, r0
	ldrh r3, [r1]
	mov ip, r3
	ldrb r2, [r5]
	lsls r0, r2, #2
	adds r0, r7, r0
	ldr r0, [r0]
	ldrb r3, [r4]
	lsls r2, r3, #1
	adds r0, #0x1c
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	ldrb r1, [r5]
	lsls r0, r1, #2
	adds r0, r7, r0
	ldr r0, [r0]
	ldrb r2, [r4]
	lsls r1, r2, #1
	adds r0, #0x1c
	adds r0, r0, r1
	mov r3, ip
	strh r3, [r0]
	ldrb r1, [r5]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, #2
	ldrb r2, [r4]
	lsls r1, r2, #1
	adds r1, #9
	movs r2, #0xc
	bl RemoveUiEntryHover
	ldr r0, [r6, #0x54]
	bl UnitRemoveInvalidItems
	ldr r0, [r6, #0x58]
	bl UnitRemoveInvalidItems
	ldr r1, [r6, #0x54]
	movs r0, #0
	bl func_fe6_0807D6C0
	ldr r1, [r6, #0x58]
	movs r0, #1
	bl func_fe6_0807D6C0
	mov r0, sb
	ldrb r3, [r0]
	lsls r0, r3, #2
	adds r0, r7, r0
	ldr r2, [r0]
	mov r7, r8
	ldrb r7, [r7]
	lsls r1, r7, #1
	adds r0, r2, #0
	adds r0, #0x1c
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq .L0807E9F0
	strb r3, [r5]
	mov r1, r8
	ldrb r0, [r1]
	b .L0807EA0A
.L0807E9F0:
	adds r0, r2, #0
	bl GetUnitItemCount
	cmp r0, #0
	ble .L0807EA08
	mov r2, sb
	ldrb r0, [r2]
	strb r0, [r5]
	mov r3, sl
	ldrb r0, [r3]
	subs r0, #1
	b .L0807EA0A
.L0807EA08:
	movs r0, #0
.L0807EA0A:
	strb r0, [r4]
	movs r0, #0xff
	mov r7, sb
	strb r0, [r7]
	ldrb r1, [r5]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, #2
	ldrb r4, [r4]
	lsls r1, r4, #1
	b .L0807EAB2
.L0807EA22:
	mov r2, r8
	ldr r0, [r2]
	ldrh r1, [r0, #8]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0807EABC
	ldr r0, .L0807EA60 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807EA40
	movs r0, #0x6b
	bl m4aSongNumStart
.L0807EA40:
	adds r7, r6, #0
	adds r7, #0x30
	ldrb r0, [r7]
	cmp r0, #0xff
	bne .L0807EA76
	adds r0, r6, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0807EA64
	adds r0, r6, #0
	movs r1, #7
	bl Proc_Goto
	b .L0807EB1A
	.align 2, 0
.L0807EA60: .4byte gPlaySt
.L0807EA64:
	adds r0, r6, #0
	movs r1, #1
	bl func_fe6_080829E8
	adds r0, r6, #0
	movs r1, #6
	bl Proc_Goto
	b .L0807EB1A
.L0807EA76:
	adds r4, r6, #0
	adds r4, #0x2f
	ldrb r3, [r4]
	lsls r0, r3, #3
	subs r0, r0, r3
	lsls r0, r0, #1
	adds r0, #2
	adds r5, r6, #0
	adds r5, #0x2e
	ldrb r2, [r5]
	lsls r1, r2, #1
	adds r1, #9
	movs r2, #0xc
	bl RemoveUiEntryHover
	ldrb r0, [r7]
	strb r0, [r4]
	adds r0, r6, #0
	adds r0, #0x31
	ldrb r0, [r0]
	strb r0, [r5]
	movs r0, #0xff
	strb r0, [r7]
	ldrb r3, [r4]
	lsls r0, r3, #3
	subs r0, r0, r3
	lsls r0, r0, #1
	adds r0, #2
	ldrb r5, [r5]
	lsls r1, r5, #1
.L0807EAB2:
	adds r1, #9
	movs r2, #0xc
	bl PutUiEntryHover
	b .L0807EB1A
.L0807EABC:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L0807EB1A
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0807EB1A
	adds r3, r6, #0
	adds r3, #0x2f
	ldrb r7, [r3]
	lsls r0, r7, #2
	adds r5, r6, #0
	adds r5, #0x54
	adds r0, r5, r0
	ldr r0, [r0]
	adds r2, r6, #0
	adds r2, #0x2e
	ldrb r4, [r2]
	lsls r1, r4, #1
	adds r0, #0x1c
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r2, #0
	cmp r0, #0
	beq .L0807EB1A
	movs r0, #2
	ldr r7, [sp, #8]
	strb r0, [r7]
	ldrb r2, [r3]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #4
	adds r0, #0x10
	ldrb r3, [r4]
	lsls r1, r3, #4
	adds r1, #0x48
	lsls r2, r2, #2
	adds r2, r5, r2
	ldr r2, [r2]
	lsls r3, r3, #1
	adds r2, #0x1c
	adds r2, r2, r3
	ldrh r2, [r2]
	bl StartItemHelpBox
.L0807EB1A:
	ldr r0, [sp, #8]
	ldrb r0, [r0]
	cmp r0, #2
	bne .L0807EB60
	adds r0, r6, #0
	adds r0, #0x2f
	adds r4, r6, #0
	adds r4, #0x2e
	ldr r1, [sp]
	ldrb r2, [r0]
	cmp r1, r2
	bne .L0807EB3A
	ldr r3, [sp, #4]
	ldrb r7, [r4]
	cmp r3, r7
	beq .L0807EB60
.L0807EB3A:
	ldrb r3, [r0]
	lsls r0, r3, #3
	subs r0, r0, r3
	lsls r0, r0, #4
	adds r0, #0x10
	ldrb r4, [r4]
	lsls r1, r4, #4
	adds r1, #0x48
	lsls r3, r3, #2
	adds r2, r6, #0
	adds r2, #0x54
	adds r2, r2, r3
	ldr r2, [r2]
	lsls r4, r4, #1
	adds r2, #0x1c
	adds r2, r2, r4
	ldrh r2, [r2]
	bl StartItemHelpBox
.L0807EB60:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0807EB70
func_fe6_0807EB70: @ 0x0807EB70
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	adds r6, r0, #0
	bl GetSupplyItems
	mov sl, r0
	movs r4, #0
	str r4, [sp]
	movs r0, #0xf
	movs r1, #4
	movs r2, #0xf
	movs r3, #0x10
	bl PutUiWindowFrame
	ldr r0, .L0807ED78 @ =0x02016368
	strh r4, [r0]
	movs r4, #1
.L0807EB9A:
	adds r0, r4, #0
	bl GetUnit
	adds r5, r0, #0
	adds r4, #1
	mov sb, r4
	adds r0, r6, #0
	adds r0, #0x46
	str r0, [sp, #0x28]
	adds r1, r6, #0
	adds r1, #0x4e
	str r1, [sp, #0x30]
	movs r2, #0x50
	adds r2, r2, r6
	mov r8, r2
	adds r3, r6, #0
	adds r3, #0x47
	str r3, [sp, #0x2c]
	adds r4, r6, #0
	adds r4, #0x2e
	str r4, [sp, #0x14]
	adds r7, r6, #0
	adds r7, #0x45
	str r7, [sp, #0x24]
	subs r0, #0x17
	str r0, [sp, #0x18]
	subs r1, #0x1e
	str r1, [sp, #0x1c]
	adds r2, r6, #0
	adds r2, #0x31
	str r2, [sp, #0x20]
	subs r3, #0x1b
	str r3, [sp, #0xc]
	subs r4, #1
	str r4, [sp, #0x10]
	cmp r5, #0
	beq .L0807EC46
	ldr r0, [r5]
	cmp r0, #0
	beq .L0807EC46
	movs r0, #4
	ldrh r7, [r5, #0xc]
	ands r0, r7
	cmp r0, #0
	bne .L0807EC46
	ldr r0, [r6, #0x54]
	cmp r5, r0
	beq .L0807EC46
	adds r0, r5, #0
	bl GetUnitItemCount
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	movs r3, #0
	cmp r3, r2
	bhs .L0807EC46
	ldr r7, .L0807ED7C @ =0x02015D28
	ldr r4, .L0807ED78 @ =0x02016368
	movs r0, #0x1c
	adds r0, r0, r5
	mov ip, r0
.L0807EC14:
	ldrh r0, [r4]
	lsls r1, r0, #2
	adds r1, r1, r7
	ldr r0, [r5]
	ldrb r0, [r0, #4]
	strb r0, [r1]
	ldrh r0, [r4]
	lsls r1, r0, #2
	adds r1, r1, r7
	lsls r0, r3, #1
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r1, #2]
	ldrh r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r7
	strb r3, [r0, #1]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, r2
	blo .L0807EC14
.L0807EC46:
	mov r4, sb
	cmp r4, #0x3f
	ble .L0807EB9A
	ldr r1, .L0807ED78 @ =0x02016368
	ldrh r4, [r1]
	movs r2, #0
	mov r3, sl
	ldrh r0, [r3]
	cmp r0, #0
	beq .L0807EC8C
	ldr r7, .L0807ED7C @ =0x02015D28
	movs r5, #0
	adds r3, r1, #0
.L0807EC60:
	adds r1, r2, r4
	lsls r1, r1, #2
	adds r1, r1, r7
	lsls r0, r2, #1
	add r0, sl
	ldrh r0, [r0]
	strh r0, [r1, #2]
	strb r5, [r1]
	strb r2, [r1, #1]
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x63
	bhi .L0807EC8C
	lsls r0, r2, #1
	add r0, sl
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0807EC60
.L0807EC8C:
	ldr r0, [r6, #0x14]
	adds r0, #0x39
	ldrb r0, [r0]
	movs r4, #0
	ldr r7, [sp, #0x28]
	strb r0, [r7]
	ldrb r0, [r7]
	bl func_fe6_0807D834
	ldr r1, [sp, #0x30]
	ldrh r0, [r1]
	movs r5, #0
	mov r2, r8
	strh r0, [r2]
	ldr r3, [sp, #0x2c]
	ldrb r0, [r3]
	ldr r7, [sp, #0x14]
	strb r0, [r7]
	ldr r0, [sp, #0x14]
	mov r1, r8
	bl func_fe6_080823A0
	ldr r0, .L0807ED80 @ =0x02015638
	ldr r2, [r6, #0x54]
	mov r1, r8
	ldrh r1, [r1]
	lsrs r3, r1, #4
	str r4, [sp]
	movs r1, #1
	bl func_fe6_0807D9E4
	adds r0, r6, #0
	bl func_fe6_0807D358
	ldr r2, [sp, #0x24]
	strb r5, [r2]
	movs r0, #1
	ldr r3, [sp, #0x18]
	strb r0, [r3]
	movs r0, #0xff
	ldr r4, [sp, #0x1c]
	ldrb r1, [r4]
	orrs r1, r0
	strb r1, [r4]
	ldr r7, [sp, #0x20]
	ldrb r7, [r7]
	orrs r0, r7
	ldr r1, [sp, #0x20]
	strb r0, [r1]
	ldr r0, .L0807ED84 @ =0x02015690
	ldr r2, .L0807ED7C @ =0x02015D28
	mov r3, r8
	ldrh r3, [r3]
	lsrs r1, r3, #4
	ldr r4, [sp, #0x14]
	ldrb r4, [r4]
	adds r1, r4, r1
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrb r1, [r1]
	movs r2, #0x18
	movs r3, #0
	bl func_fe6_0807DCB8
	ldr r7, [sp, #0x18]
	ldrb r2, [r7]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	ldr r3, [sp, #0x14]
	ldrb r3, [r3]
	lsls r1, r3, #1
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	bl PutUiEntryHover
	ldr r4, [sp, #0x24]
	ldrb r1, [r4]
	mov r7, r8
	ldrh r2, [r7]
	subs r2, #0x28
	movs r0, #0xff
	ands r2, r0
	movs r0, #2
	bl SetBgOffset
	ldr r0, [r6, #0x60]
	ldrh r1, [r7]
	str r1, [sp]
	ldr r1, .L0807ED88 @ =0x0201636A
	ldrh r1, [r1]
	str r1, [sp, #4]
	movs r1, #7
	str r1, [sp, #8]
	movs r1, #0xe0
	movs r2, #0x34
	movs r3, #0xb
	bl func_fe6_08082320
	movs r0, #0xf
	bl EnableBgSync
	ldr r0, [sp, #0xc]
	strb r5, [r0]
	ldr r1, [sp, #0x10]
	ldrb r0, [r1]
	cmp r0, #0
	bne .L0807ED8C
	movs r1, #1
	rsbs r1, r1, #0
	adds r0, r6, #0
	bl func_fe6_080829E8
	b .L0807ED96
	.align 2, 0
.L0807ED78: .4byte 0x02016368
.L0807ED7C: .4byte 0x02015D28
.L0807ED80: .4byte 0x02015638
.L0807ED84: .4byte 0x02015690
.L0807ED88: .4byte 0x0201636A
.L0807ED8C:
	cmp r0, #1
	bne .L0807ED96
	ldr r0, [r6, #0x5c]
	bl Proc_End
.L0807ED96:
	adds r0, r6, #0
	bl func_fe6_0807D16C
	str r0, [r6, #0x5c]
	movs r0, #1
	bl func_fe6_0807E06C
	movs r0, #3
	ldr r2, [sp, #0x10]
	strb r0, [r2]
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0807EDBC
func_fe6_0807EDBC: @ 0x0807EDBC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	adds r0, #0x46
	ldrb r0, [r0]
	str r0, [sp, #4]
	mov r1, r8
	adds r1, #0x2e
	mov r0, r8
	adds r0, #0x50
	ldrh r0, [r0]
	lsrs r0, r0, #4
	ldrb r1, [r1]
	adds r1, r1, r0
	str r1, [sp, #8]
	mov r4, r8
	adds r4, #0x29
	ldrb r2, [r4]
	cmp r2, #0
	beq .L0807EE14
	ldr r0, .L0807EE0C @ =gKeySt
	ldr r1, [r0]
	movs r0, #0x81
	lsls r0, r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L0807EE14
	cmp r2, #1
	beq .L0807EE10
	bl CloseHelpBox
	movs r0, #0
	strb r0, [r4]
	bl .L0807FBD8
	.align 2, 0
.L0807EE0C: .4byte gKeySt
.L0807EE10:
	movs r0, #0
	strb r0, [r4]
.L0807EE14:
	mov r0, r8
	adds r0, #0x2c
	ldrb r1, [r0]
	mov sb, r0
	cmp r1, #0x64
	bls .L0807EE24
	bl .L0807FA9A
.L0807EE24:
	lsls r0, r1, #2
	ldr r1, .L0807EE30 @ =.L0807EE34
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0807EE30: .4byte .L0807EE34
.L0807EE34: @ jump table
	.4byte .L0807F2FE @ case 0
	.4byte .L0807F7FC @ case 1
	.4byte .L0807F844 @ case 2
	.4byte .L0807FA9A @ case 3
	.4byte .L0807FA9A @ case 4
	.4byte .L0807F88C @ case 5
	.4byte .L0807F8A4 @ case 6
	.4byte .L0807F970 @ case 7
	.4byte .L0807FA9A @ case 8
	.4byte .L0807FA9A @ case 9
	.4byte .L0807F97A @ case 10
	.4byte .L0807F996 @ case 11
	.4byte .L0807FA84 @ case 12
	.4byte .L0807FA9A @ case 13
	.4byte .L0807FA9A @ case 14
	.4byte .L0807FA9A @ case 15
	.4byte .L0807FA9A @ case 16
	.4byte .L0807FA9A @ case 17
	.4byte .L0807FA9A @ case 18
	.4byte .L0807FA9A @ case 19
	.4byte .L0807FA9A @ case 20
	.4byte .L0807FA9A @ case 21
	.4byte .L0807FA9A @ case 22
	.4byte .L0807FA9A @ case 23
	.4byte .L0807FA9A @ case 24
	.4byte .L0807FA9A @ case 25
	.4byte .L0807FA9A @ case 26
	.4byte .L0807FA9A @ case 27
	.4byte .L0807FA9A @ case 28
	.4byte .L0807FA9A @ case 29
	.4byte .L0807FA9A @ case 30
	.4byte .L0807FA9A @ case 31
	.4byte .L0807FA9A @ case 32
	.4byte .L0807FA9A @ case 33
	.4byte .L0807FA9A @ case 34
	.4byte .L0807FA9A @ case 35
	.4byte .L0807FA9A @ case 36
	.4byte .L0807FA9A @ case 37
	.4byte .L0807FA9A @ case 38
	.4byte .L0807FA9A @ case 39
	.4byte .L0807FA9A @ case 40
	.4byte .L0807FA9A @ case 41
	.4byte .L0807FA9A @ case 42
	.4byte .L0807FA9A @ case 43
	.4byte .L0807FA9A @ case 44
	.4byte .L0807FA9A @ case 45
	.4byte .L0807FA9A @ case 46
	.4byte .L0807FA9A @ case 47
	.4byte .L0807FA9A @ case 48
	.4byte .L0807FA9A @ case 49
	.4byte .L0807FA9A @ case 50
	.4byte .L0807FA9A @ case 51
	.4byte .L0807FA9A @ case 52
	.4byte .L0807FA9A @ case 53
	.4byte .L0807FA9A @ case 54
	.4byte .L0807FA9A @ case 55
	.4byte .L0807FA9A @ case 56
	.4byte .L0807FA9A @ case 57
	.4byte .L0807FA9A @ case 58
	.4byte .L0807FA9A @ case 59
	.4byte .L0807FA9A @ case 60
	.4byte .L0807FA9A @ case 61
	.4byte .L0807FA9A @ case 62
	.4byte .L0807FA9A @ case 63
	.4byte .L0807FA9A @ case 64
	.4byte .L0807FA9A @ case 65
	.4byte .L0807FA9A @ case 66
	.4byte .L0807FA9A @ case 67
	.4byte .L0807FA9A @ case 68
	.4byte .L0807FA9A @ case 69
	.4byte .L0807FA9A @ case 70
	.4byte .L0807FA9A @ case 71
	.4byte .L0807FA9A @ case 72
	.4byte .L0807FA9A @ case 73
	.4byte .L0807FA9A @ case 74
	.4byte .L0807FA9A @ case 75
	.4byte .L0807FA9A @ case 76
	.4byte .L0807FA9A @ case 77
	.4byte .L0807FA9A @ case 78
	.4byte .L0807FA9A @ case 79
	.4byte .L0807FA9A @ case 80
	.4byte .L0807FA9A @ case 81
	.4byte .L0807FA9A @ case 82
	.4byte .L0807FA9A @ case 83
	.4byte .L0807FA9A @ case 84
	.4byte .L0807FA9A @ case 85
	.4byte .L0807FA9A @ case 86
	.4byte .L0807FA9A @ case 87
	.4byte .L0807FA9A @ case 88
	.4byte .L0807FA9A @ case 89
	.4byte .L0807FA9A @ case 90
	.4byte .L0807FA9A @ case 91
	.4byte .L0807FA9A @ case 92
	.4byte .L0807FA9A @ case 93
	.4byte .L0807FA9A @ case 94
	.4byte .L0807FA9A @ case 95
	.4byte .L0807FA9A @ case 96
	.4byte .L0807FA9A @ case 97
	.4byte .L0807FA9A @ case 98
	.4byte .L0807FA9A @ case 99
	.4byte .L0807EFC8 @ case 100
.L0807EFC8:
	mov r1, r8
	ldr r0, [r1, #0x54]
	bl GetUnitItemCount
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	mov r0, r8
	adds r0, #0x29
	ldrb r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	bne .L0807EFEA
	cmp r7, #4
	bhi .L0807EFEA
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
.L0807EFEA:
	ldr r2, .L0807F054 @ =gKeySt
	ldr r1, [r2]
	movs r4, #0x40
	mov sl, r4
	mov r0, sl
	ldrh r1, [r1, #6]
	ands r0, r1
	cmp r0, #0
	beq .L0807F078
	cmp r7, #1
	bls .L0807F078
	mov r5, r8
	adds r5, #0x2f
	ldrb r2, [r5]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	mov r4, r8
	adds r4, #0x2e
	ldrb r3, [r4]
	lsls r1, r3, #1
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	bl RemoveUiEntryHover
	ldrb r0, [r4]
	adds r6, r4, #0
	adds r4, r5, #0
	cmp r0, #0
	bne .L0807F05C
	ldr r0, .L0807F054 @ =gKeySt
	ldr r1, [r0]
	mov r0, sl
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	bne .L0807F03C
	b .L0807F5A6
.L0807F03C:
	subs r0, r7, #1
.L0807F03E:
	strb r0, [r6]
	ldr r0, .L0807F058 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	bge .L0807F04C
	b .L0807F5A6
.L0807F04C:
	movs r0, #0x66
	bl m4aSongNumStart
	b .L0807F5A6
	.align 2, 0
.L0807F054: .4byte gKeySt
.L0807F058: .4byte gPlaySt
.L0807F05C:
	subs r0, #1
	strb r0, [r6]
	ldr r0, .L0807F074 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	bge .L0807F06C
	b .L0807F5A6
.L0807F06C:
	movs r0, #0x66
	bl m4aSongNumStart
	b .L0807F5A6
	.align 2, 0
.L0807F074: .4byte gPlaySt
.L0807F078:
	ldr r2, .L0807F0C0 @ =gKeySt
	ldr r1, [r2]
	movs r4, #0x80
	mov sl, r4
	mov r0, sl
	ldrh r1, [r1, #6]
	ands r0, r1
	cmp r0, #0
	beq .L0807F0F4
	cmp r7, #1
	bls .L0807F0F4
	mov r5, r8
	adds r5, #0x2f
	ldrb r2, [r5]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	mov r4, r8
	adds r4, #0x2e
	ldrb r3, [r4]
	lsls r1, r3, #1
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	bl RemoveUiEntryHover
	ldrb r1, [r4]
	subs r0, r7, #1
	adds r6, r4, #0
	adds r4, r5, #0
	cmp r1, r0
	bge .L0807F0C4
	adds r0, r1, #1
	b .L0807F03E
	.align 2, 0
.L0807F0C0: .4byte gKeySt
.L0807F0C4:
	ldr r0, .L0807F0EC @ =gKeySt
	ldr r1, [r0]
	mov r0, sl
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	bne .L0807F0D4
	b .L0807F5A6
.L0807F0D4:
	movs r0, #0
	strb r0, [r6]
	ldr r0, .L0807F0F0 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	bge .L0807F0E4
	b .L0807F5A6
.L0807F0E4:
	movs r0, #0x66
	bl m4aSongNumStart
	b .L0807F5A6
	.align 2, 0
.L0807F0EC: .4byte gKeySt
.L0807F0F0: .4byte gPlaySt
.L0807F0F4:
	ldr r2, .L0807F164 @ =gKeySt
	ldr r1, [r2]
	movs r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	bne .L0807F104
	b .L0807F230
.L0807F104:
	ldrb r0, [r3]
	cmp r0, #0
	beq .L0807F10C
	b .L0807F230
.L0807F10C:
	mov r0, r8
	adds r0, #0x4c
	ldrb r0, [r0]
	mov r6, r8
	adds r6, #0x2e
	mov r5, r8
	adds r5, #0x31
	cmp r0, #0
	beq .L0807F170
	mov r3, r8
	ldr r0, [r3, #0x54]
	ldrb r1, [r6]
	ldr r3, .L0807F168 @ =0x02015D28
	mov r2, r8
	adds r2, #0x50
	ldrh r2, [r2]
	lsrs r2, r2, #4
	ldrb r4, [r5]
	adds r2, r4, r2
	lsls r2, r2, #2
	adds r2, r2, r3
	ldrh r2, [r2, #2]
	bl func_fe6_08082C34
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0807F170
	mov r1, r8
	adds r1, #0x2f
	ldrb r2, [r1]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #4
	adds r0, #0x10
	ldrb r6, [r6]
	lsls r1, r6, #4
	adds r1, #0x48
	ldr r2, .L0807F16C @ =0x000006C2
	mov r3, r8
	bl func_fe6_08082B00
	bl .L0807FA9A
	.align 2, 0
.L0807F164: .4byte gKeySt
.L0807F168: .4byte 0x02015D28
.L0807F16C: .4byte 0x000006C2
.L0807F170:
	ldr r0, .L0807F220 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807F180
	movs r0, #0x6a
	bl m4aSongNumStart
.L0807F180:
	mov r3, r8
	ldr r0, [r3, #0x54]
	ldrb r1, [r6]
	mov r4, r8
	adds r4, #0x50
	ldrh r3, [r4]
	lsrs r2, r3, #4
	ldrb r3, [r5]
	adds r2, r3, r2
	bl func_fe6_0807DF60
	mov r7, r8
	adds r7, #0x2f
	ldrb r2, [r7]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	ldrb r3, [r6]
	lsls r1, r3, #1
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	bl RemoveUiEntryHover
	ldrb r0, [r5]
	movs r5, #0
	strb r0, [r6]
	movs r0, #1
	strb r0, [r7]
	adds r0, r6, #0
	adds r1, r4, #0
	bl func_fe6_080823A0
	mov r0, r8
	ldr r1, [r0, #0x54]
	movs r0, #0
	bl func_fe6_0807D6C0
	ldr r0, .L0807F224 @ =0x02015638
	mov r1, r8
	ldr r2, [r1, #0x54]
	ldrh r1, [r4]
	lsrs r3, r1, #4
	str r5, [sp]
	movs r1, #1
	bl func_fe6_0807D9E4
	ldr r0, .L0807F228 @ =0x02015690
	ldr r2, .L0807F22C @ =0x02015D28
	ldrh r4, [r4]
	lsrs r1, r4, #4
	ldrb r3, [r6]
	adds r1, r3, r1
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrb r1, [r1]
	movs r2, #0x18
	movs r3, #0
	bl func_fe6_0807DCB8
	ldrb r2, [r7]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	ldrb r6, [r6]
	lsls r1, r6, #1
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	bl PutUiEntryHover
	mov r4, sb
	strb r5, [r4]
	bl .L0807FA9A
	.align 2, 0
.L0807F220: .4byte gPlaySt
.L0807F224: .4byte 0x02015638
.L0807F228: .4byte 0x02015690
.L0807F22C: .4byte 0x02015D28
.L0807F230:
	ldr r1, .L0807F294 @ =gKeySt
	ldr r0, [r1]
	ldrh r1, [r0, #8]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L0807F29C
	ldr r0, .L0807F298 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807F24E
	movs r0, #0x6b
	bl m4aSongNumStart
.L0807F24E:
	mov r5, r8
	adds r5, #0x2f
	ldrb r2, [r5]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	mov r4, r8
	adds r4, #0x2e
	ldrb r3, [r4]
	lsls r1, r3, #1
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	bl RemoveUiEntryHover
	mov r0, r8
	adds r0, #0x31
	ldrb r0, [r0]
	movs r1, #0
	strb r0, [r4]
	movs r0, #1
	strb r0, [r5]
	mov r0, sb
	strb r1, [r0]
	ldrb r2, [r5]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	ldrb r4, [r4]
	lsls r1, r4, #1
	b .L0807F5B4
	.align 2, 0
.L0807F294: .4byte gKeySt
.L0807F298: .4byte gPlaySt
.L0807F29C:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne .L0807F2AA
	bl .L0807FA9A
.L0807F2AA:
	mov r2, r8
	adds r2, #0x29
	ldrb r0, [r2]
	cmp r0, #0
	beq .L0807F2B8
	bl .L0807FA9A
.L0807F2B8:
	mov r1, r8
	ldr r0, [r1, #0x54]
	mov r3, r8
	adds r3, #0x2e
	ldrb r4, [r3]
	lsls r1, r4, #1
	adds r0, #0x1c
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0807F2D0
	b .L0807FA9A
.L0807F2D0:
	movs r0, #2
	strb r0, [r2]
	mov r0, r8
	adds r0, #0x2f
	ldrb r2, [r0]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #4
	adds r0, #0x10
	ldrb r3, [r3]
	lsls r1, r3, #4
	lsls r2, r2, #5
	subs r2, #0x48
	subs r1, r1, r2
	mov r4, r8
	ldr r2, [r4, #0x54]
	lsls r3, r3, #1
	adds r2, #0x1c
	adds r2, r2, r3
	ldrh r2, [r2]
	bl StartItemHelpBox
	b .L0807FA9A
.L0807F2FE:
	ldr r2, .L0807F318 @ =gKeySt
	ldr r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ldrh r1, [r1, #4]
	ands r0, r1
	cmp r0, #0
	beq .L0807F31C
	mov r1, r8
	adds r1, #0x4a
	movs r0, #2
	b .L0807F322
	.align 2, 0
.L0807F318: .4byte gKeySt
.L0807F31C:
	mov r1, r8
	adds r1, #0x4a
	movs r0, #1
.L0807F322:
	strb r0, [r1]
	adds r7, r1, #0
	ldr r0, .L0807F358 @ =gKeySt
	ldr r1, [r0]
	movs r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L0807F410
	mov r0, r8
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L0807F410
	ldr r0, .L0807F35C @ =0x0201636A
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0807F364
	ldr r0, .L0807F360 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807F410
	movs r0, #0x6c
	bl m4aSongNumStart
	b .L0807F410
	.align 2, 0
.L0807F358: .4byte gKeySt
.L0807F35C: .4byte 0x0201636A
.L0807F360: .4byte gPlaySt
.L0807F364:
	ldr r2, .L0807F3D8 @ =0x02015D28
	mov r1, r8
	adds r1, #0x2e
	mov r0, r8
	adds r0, #0x50
	ldrh r0, [r0]
	lsrs r0, r0, #4
	ldrb r3, [r1]
	adds r0, r3, r0
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r5, [r0]
	adds r6, r1, #0
	cmp r5, #0
	bne .L0807F3F0
	ldr r0, .L0807F3DC @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807F392
	movs r0, #0x6a
	bl m4aSongNumStart
.L0807F392:
	movs r0, #0x64
	mov r4, sb
	strb r0, [r4]
	ldrb r0, [r6]
	mov r1, r8
	adds r1, #0x31
	strb r0, [r1]
	mov r4, r8
	adds r4, #0x2f
	ldrb r2, [r4]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	ldrb r3, [r6]
	lsls r1, r3, #1
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	bl RemoveUiEntryHover
	mov r1, r8
	ldr r0, [r1, #0x54]
	bl GetUnitItemCount
	cmp r0, #4
	bgt .L0807F3E0
	mov r2, r8
	ldr r0, [r2, #0x54]
	bl GetUnitItemCount
	strb r0, [r6]
	b .L0807F3E2
	.align 2, 0
.L0807F3D8: .4byte 0x02015D28
.L0807F3DC: .4byte gPlaySt
.L0807F3E0:
	strb r5, [r6]
.L0807F3E2:
	movs r0, #0
	strb r0, [r4]
	ldrb r6, [r6]
	lsls r1, r6, #1
	adds r1, #9
	movs r0, #2
	b .L0807F5BA
.L0807F3F0:
	ldr r0, .L0807F40C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807F400
	movs r0, #0x6a
	bl m4aSongNumStart
.L0807F400:
	mov r0, r8
	movs r1, #7
	bl Proc_Goto
	b .L0807FA9A
	.align 2, 0
.L0807F40C: .4byte gPlaySt
.L0807F410:
	ldr r1, .L0807F440 @ =gKeySt
	ldr r0, [r1]
	ldrh r3, [r0, #8]
	movs r0, #2
	ands r0, r3
	cmp r0, #0
	beq .L0807F448
	ldr r0, .L0807F444 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807F42E
	movs r0, #0x6b
	bl m4aSongNumStart
.L0807F42E:
	mov r0, r8
	movs r1, #1
	bl func_fe6_080829E8
	mov r0, r8
	movs r1, #6
	bl Proc_Goto
	b .L0807FBD8
	.align 2, 0
.L0807F440: .4byte gKeySt
.L0807F444: .4byte gPlaySt
.L0807F448:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r3
	cmp r0, #0
	beq .L0807F4A4
	mov r1, r8
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	bne .L0807F4A4
	ldr r0, .L0807F49C @ =0x0201636A
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0807F466
	b .L0807FA9A
.L0807F466:
	movs r0, #2
	strb r0, [r1]
	mov r0, r8
	adds r0, #0x2f
	ldrb r3, [r0]
	lsls r0, r3, #3
	subs r0, r0, r3
	lsls r0, r0, #4
	adds r0, #0x10
	adds r1, #5
	ldrb r2, [r1]
	lsls r1, r2, #4
	lsls r3, r3, #5
	subs r3, #0x48
	subs r1, r1, r3
	ldr r4, .L0807F4A0 @ =0x02015D28
	mov r3, r8
	adds r3, #0x50
	ldrh r3, [r3]
	lsrs r3, r3, #4
	adds r2, r2, r3
	lsls r2, r2, #2
	adds r2, r2, r4
	ldrh r2, [r2, #2]
	bl StartItemHelpBox
	b .L0807FA9A
	.align 2, 0
.L0807F49C: .4byte 0x0201636A
.L0807F4A0: .4byte 0x02015D28
.L0807F4A4:
	ldr r3, .L0807F548 @ =gKeySt
	ldr r1, [r3]
	movs r2, #0x40
	adds r0, r2, #0
	ldrh r4, [r1, #6]
	ands r0, r4
	cmp r0, #0
	bne .L0807F4C8
	adds r0, r2, #0
	ldrh r1, [r1, #0x10]
	ands r0, r1
	cmp r0, #0
	bne .L0807F4C0
	b .L0807F5CC
.L0807F4C0:
	ldrb r0, [r7]
	cmp r0, #2
	beq .L0807F4C8
	b .L0807F5CC
.L0807F4C8:
	mov r0, r8
	adds r0, #0x2e
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	beq .L0807F5CC
	ldr r0, .L0807F54C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807F4E4
	movs r0, #0x66
	bl m4aSongNumStart
.L0807F4E4:
	ldrb r4, [r6]
	cmp r4, #1
	bne .L0807F55C
	mov r5, r8
	adds r5, #0x50
	ldrh r0, [r5]
	cmp r0, #0
	beq .L0807F55C
	ldr r0, .L0807F550 @ =0x02015638
	ldrh r1, [r5]
	lsrs r2, r1, #4
	subs r2, #1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r1, r8
	ldr r3, [r1, #0x54]
	movs r1, #0
	str r1, [sp]
	movs r1, #1
	bl func_fe6_0807DB80
	mov r0, r8
	bl func_fe6_0807D358
	ldr r1, .L0807F554 @ =0x02015D28
	ldrh r2, [r5]
	lsrs r0, r2, #4
	ldrb r6, [r6]
	adds r0, r6, r0
	subs r0, #1
	lsls r0, r0, #2
	adds r1, r0, r1
	movs r3, #0xff
	ldrb r0, [r1]
	cmp r3, r0
	beq .L0807F538
	ldr r0, .L0807F558 @ =0x02015690
	ldrb r1, [r1]
	movs r2, #0x18
	movs r3, #0
	bl func_fe6_0807DCB8
.L0807F538:
	ldrb r7, [r7]
	lsls r0, r7, #2
	ldrh r1, [r5]
	subs r0, r1, r0
	strh r0, [r5]
	mov r2, sb
	strb r4, [r2]
	b .L0807FA9A
	.align 2, 0
.L0807F548: .4byte gKeySt
.L0807F54C: .4byte gPlaySt
.L0807F550: .4byte 0x02015638
.L0807F554: .4byte 0x02015D28
.L0807F558: .4byte 0x02015690
.L0807F55C:
	mov r4, r8
	adds r4, #0x2f
	ldrb r2, [r4]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	ldrb r3, [r6]
	lsls r1, r3, #1
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	bl RemoveUiEntryHover
	ldrb r0, [r6]
	subs r0, #1
	strb r0, [r6]
	ldr r1, .L0807F5C4 @ =0x02015D28
	mov r0, r8
	adds r0, #0x50
	ldrh r0, [r0]
	lsrs r0, r0, #4
	ldrb r2, [r6]
	adds r0, r2, r0
	lsls r0, r0, #2
	adds r1, r0, r1
	movs r3, #0xff
	ldrb r0, [r1]
	cmp r3, r0
	beq .L0807F5A6
	ldr r0, .L0807F5C8 @ =0x02015690
	ldrb r1, [r1]
	movs r2, #0x18
	movs r3, #0
	bl func_fe6_0807DCB8
.L0807F5A6:
	ldrb r2, [r4]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	ldrb r6, [r6]
	lsls r1, r6, #1
.L0807F5B4:
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
.L0807F5BA:
	movs r2, #0xc
	bl PutUiEntryHover
	b .L0807FA9A
	.align 2, 0
.L0807F5C4: .4byte 0x02015D28
.L0807F5C8: .4byte 0x02015690
.L0807F5CC:
	ldr r2, .L0807F664 @ =gKeySt
	ldr r1, [r2]
	movs r2, #0x80
	adds r0, r2, #0
	ldrh r3, [r1, #6]
	ands r0, r3
	cmp r0, #0
	bne .L0807F5F0
	adds r0, r2, #0
	ldrh r1, [r1, #0x10]
	ands r0, r1
	cmp r0, #0
	bne .L0807F5E8
	b .L0807F710
.L0807F5E8:
	ldrb r4, [r7]
	cmp r4, #2
	beq .L0807F5F0
	b .L0807F710
.L0807F5F0:
	mov r0, r8
	adds r0, #0x2e
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #5
	bls .L0807F5FE
	b .L0807F710
.L0807F5FE:
	ldr r3, .L0807F668 @ =0x0201636A
	cmp r1, #5
	bne .L0807F678
	mov r5, r8
	adds r5, #0x50
	ldrh r0, [r5]
	lsrs r2, r0, #4
	adds r1, r2, #7
	ldrh r0, [r3]
	cmp r1, r0
	bge .L0807F678
	ldr r0, .L0807F66C @ =0x02015638
	adds r2, r1, #0
	mov r1, r8
	ldr r3, [r1, #0x54]
	movs r1, #0
	str r1, [sp]
	movs r1, #1
	bl func_fe6_0807DB80
	mov r0, r8
	bl func_fe6_0807D358
	ldr r1, .L0807F670 @ =0x02015D28
	ldrh r2, [r5]
	lsrs r0, r2, #4
	ldrb r6, [r6]
	adds r0, r6, r0
	adds r0, #1
	lsls r0, r0, #2
	adds r1, r0, r1
	movs r3, #0xff
	ldrb r4, [r1]
	cmp r3, r4
	beq .L0807F650
	ldr r0, .L0807F674 @ =0x02015690
	ldrb r1, [r1]
	movs r2, #0x18
	movs r3, #0
	bl func_fe6_0807DCB8
.L0807F650:
	ldrb r7, [r7]
	lsls r0, r7, #2
	ldrh r1, [r5]
	adds r0, r1, r0
	strh r0, [r5]
	movs r0, #2
	mov r2, sb
	strb r0, [r2]
	b .L0807F6EE
	.align 2, 0
.L0807F664: .4byte gKeySt
.L0807F668: .4byte 0x0201636A
.L0807F66C: .4byte 0x02015638
.L0807F670: .4byte 0x02015D28
.L0807F674: .4byte 0x02015690
.L0807F678:
	mov r5, r8
	adds r5, #0x50
	ldrh r4, [r5]
	lsrs r0, r4, #4
	adds r4, r6, #0
	ldrb r1, [r4]
	adds r0, r0, r1
	adds r0, #1
	ldrh r3, [r3]
	cmp r0, r3
	blt .L0807F690
	b .L0807FA9A
.L0807F690:
	mov r7, r8
	adds r7, #0x2f
	ldrb r2, [r7]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	lsls r1, r1, #1
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	bl RemoveUiEntryHover
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldr r1, .L0807F704 @ =0x02015D28
	ldrh r5, [r5]
	lsrs r0, r5, #4
	ldrb r4, [r4]
	adds r0, r4, r0
	lsls r0, r0, #2
	adds r1, r0, r1
	movs r0, #0xff
	ldrb r2, [r1]
	cmp r0, r2
	beq .L0807F6D4
	ldr r0, .L0807F708 @ =0x02015690
	ldrb r1, [r1]
	movs r2, #0x18
	movs r3, #0
	bl func_fe6_0807DCB8
.L0807F6D4:
	ldrb r2, [r7]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	ldrb r6, [r6]
	lsls r1, r6, #1
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	bl PutUiEntryHover
.L0807F6EE:
	ldr r0, .L0807F70C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	bge .L0807F6FA
	b .L0807FA9A
.L0807F6FA:
	movs r0, #0x66
	bl m4aSongNumStart
	b .L0807FA9A
	.align 2, 0
.L0807F704: .4byte 0x02015D28
.L0807F708: .4byte 0x02015690
.L0807F70C: .4byte gPlaySt
.L0807F710:
	ldr r3, .L0807F780 @ =gKeySt
	ldr r0, [r3]
	ldrh r1, [r0, #6]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L0807F788
	ldr r0, .L0807F784 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807F72E
	movs r0, #0x67
	bl m4aSongNumStart
.L0807F72E:
	mov r2, r8
	adds r2, #0x46
	mov r0, r8
	adds r0, #0x32
	ldrb r4, [r2]
	adds r0, r4, r0
	mov r1, r8
	adds r1, #0x50
	ldrh r1, [r1]
	lsrs r1, r1, #4
	strb r1, [r0]
	mov r0, r8
	adds r0, #0x3b
	ldrb r2, [r2]
	adds r0, r2, r0
	mov r3, r8
	adds r3, #0x2e
	ldrb r1, [r3]
	strb r1, [r0]
	mov r0, r8
	adds r0, #0x2f
	ldrb r2, [r0]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	ldrb r3, [r3]
	lsls r1, r3, #1
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	bl RemoveUiEntryHover
	mov r1, r8
	adds r1, #0x45
	movs r0, #0x38
	strb r0, [r1]
	movs r0, #5
	b .L0807FA6E
	.align 2, 0
.L0807F780: .4byte gKeySt
.L0807F784: .4byte gPlaySt
.L0807F788:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne .L0807F792
	b .L0807FA9A
.L0807F792:
	ldr r0, .L0807F7F8 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807F7A2
	movs r0, #0x67
	bl m4aSongNumStart
.L0807F7A2:
	mov r2, r8
	adds r2, #0x46
	mov r0, r8
	adds r0, #0x32
	ldrb r3, [r2]
	adds r0, r3, r0
	mov r1, r8
	adds r1, #0x50
	ldrh r1, [r1]
	lsrs r1, r1, #4
	strb r1, [r0]
	mov r0, r8
	adds r0, #0x3b
	ldrb r2, [r2]
	adds r0, r2, r0
	mov r3, r8
	adds r3, #0x2e
	ldrb r1, [r3]
	strb r1, [r0]
	mov r0, r8
	adds r0, #0x2f
	ldrb r2, [r0]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	ldrb r3, [r3]
	lsls r1, r3, #1
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	bl RemoveUiEntryHover
	mov r1, r8
	adds r1, #0x45
	movs r0, #0xc8
	strb r0, [r1]
	movs r0, #0xa
	mov r4, sb
	strb r0, [r4]
	b .L0807FA9A
	.align 2, 0
.L0807F7F8: .4byte gPlaySt
.L0807F7FC:
	mov r0, r8
	adds r0, #0x50
	mov r1, r8
	adds r1, #0x4a
	ldrb r1, [r1]
	lsls r1, r1, #2
	ldrh r2, [r0]
	subs r1, r2, r1
	strh r1, [r0]
	ldrh r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq .L0807F81A
	b .L0807FA9A
.L0807F81A:
	lsrs r0, r1, #4
	adds r0, #7
	lsls r0, r0, #1
	movs r1, #0x1f
	ands r0, r1
	lsls r0, r0, #6
	ldr r1, .L0807F840 @ =gBg2Tm+0x1E
	adds r0, r0, r1
	movs r1, #0xf
	movs r2, #1
	movs r3, #0
	bl TmFillRect_thm
	movs r0, #4
	bl EnableBgSync
	movs r0, #0
	b .L0807F990
	.align 2, 0
.L0807F840: .4byte gBg2Tm+0x1E
.L0807F844:
	mov r0, r8
	adds r0, #0x50
	mov r1, r8
	adds r1, #0x4a
	ldrb r1, [r1]
	lsls r1, r1, #2
	ldrh r4, [r0]
	adds r1, r4, r1
	strh r1, [r0]
	ldrh r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq .L0807F862
	b .L0807FA9A
.L0807F862:
	lsrs r0, r1, #4
	subs r0, #1
	lsls r0, r0, #1
	movs r1, #0x1f
	ands r0, r1
	lsls r0, r0, #6
	ldr r1, .L0807F888 @ =gBg2Tm+0x1E
	adds r0, r0, r1
	movs r1, #0xf
	movs r2, #1
	movs r3, #0
	bl TmFillRect_thm
	movs r0, #4
	bl EnableBgSync
	movs r0, #0
	b .L0807FA6E
	.align 2, 0
.L0807F888: .4byte gBg2Tm+0x1E
.L0807F88C:
	mov r1, r8
	adds r1, #0x45
	ldrb r0, [r1]
	adds r0, #0x38
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x70
	beq .L0807F8A0
	b .L0807FA9A
.L0807F8A0:
	movs r0, #6
	b .L0807FA96
.L0807F8A4:
	mov r1, r8
	adds r1, #0x45
	movs r0, #0x90
	strb r0, [r1]
	mov r0, r8
	adds r0, #0x46
	ldrb r1, [r0]
	adds r7, r0, #0
	cmp r1, #8
	bne .L0807F8BC
	movs r0, #0
	b .L0807F8BE
.L0807F8BC:
	adds r0, r1, #1
.L0807F8BE:
	strb r0, [r7]
	mov r0, r8
	adds r0, #0x32
	ldrb r3, [r7]
	adds r0, r3, r0
	ldrb r0, [r0]
	lsls r0, r0, #4
	mov r5, r8
	adds r5, #0x50
	movs r6, #0
	strh r0, [r5]
	mov r0, r8
	adds r0, #0x3b
	ldrb r4, [r7]
	adds r0, r4, r0
	ldrb r0, [r0]
	mov r4, r8
	adds r4, #0x2e
	strb r0, [r4]
	ldrb r0, [r7]
	bl func_fe6_0807D834
	adds r0, r4, #0
	adds r1, r5, #0
	bl func_fe6_080823A0
	ldr r0, .L0807F960 @ =0x02015638
	mov r1, r8
	ldr r2, [r1, #0x54]
	ldrh r1, [r5]
	lsrs r3, r1, #4
	str r6, [sp]
	movs r1, #1
	bl func_fe6_0807D9E4
	mov r0, r8
	adds r0, #0x2f
	ldrb r2, [r0]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	ldrb r3, [r4]
	lsls r1, r3, #1
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	bl PutUiEntryHover
	ldr r1, .L0807F964 @ =0x02015D28
	ldrh r5, [r5]
	lsrs r0, r5, #4
	ldrb r4, [r4]
	adds r0, r4, r0
	lsls r0, r0, #2
	adds r1, r0, r1
	movs r4, #0xff
	ldrb r0, [r1]
	cmp r4, r0
	bne .L0807F940
	ldr r0, .L0807F968 @ =0x0201636A
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0807F94C
.L0807F940:
	ldr r0, .L0807F96C @ =0x02015690
	ldrb r1, [r1]
	movs r2, #0x18
	movs r3, #0
	bl func_fe6_0807DCB8
.L0807F94C:
	mov r0, r8
	bl func_fe6_0807D358
	mov r1, r8
	adds r1, #0x45
	ldrb r0, [r1]
	adds r0, #0xe
	strb r0, [r1]
	movs r0, #7
	b .L0807FA6E
	.align 2, 0
.L0807F960: .4byte 0x02015638
.L0807F964: .4byte 0x02015D28
.L0807F968: .4byte 0x0201636A
.L0807F96C: .4byte 0x02015690
.L0807F970:
	mov r1, r8
	adds r1, #0x45
	ldrb r0, [r1]
	adds r0, #0xe
	b .L0807FA8C
.L0807F97A:
	mov r1, r8
	adds r1, #0x45
	ldrb r0, [r1]
	subs r0, #0x38
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x90
	beq .L0807F98E
	b .L0807FA9A
.L0807F98E:
	movs r0, #0xb
.L0807F990:
	mov r3, sb
	strb r0, [r3]
	b .L0807FA9A
.L0807F996:
	mov r1, r8
	adds r1, #0x45
	movs r0, #0x70
	strb r0, [r1]
	mov r0, r8
	adds r0, #0x46
	ldrb r1, [r0]
	adds r7, r0, #0
	cmp r1, #0
	bne .L0807F9AE
	movs r0, #8
	b .L0807F9B0
.L0807F9AE:
	subs r0, r1, #1
.L0807F9B0:
	strb r0, [r7]
	movs r4, #0x2f
	add r4, r8
	mov sl, r4
	ldrb r2, [r4]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	mov r5, r8
	adds r5, #0x2e
	ldrb r3, [r5]
	lsls r1, r3, #1
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	bl RemoveUiEntryHover
	mov r0, r8
	adds r0, #0x32
	ldrb r4, [r7]
	adds r0, r4, r0
	ldrb r0, [r0]
	lsls r0, r0, #4
	mov r4, r8
	adds r4, #0x50
	movs r6, #0
	strh r0, [r4]
	mov r0, r8
	adds r0, #0x3b
	ldrb r1, [r7]
	adds r0, r1, r0
	ldrb r0, [r0]
	strb r0, [r5]
	ldrb r0, [r7]
	bl func_fe6_0807D834
	adds r0, r5, #0
	adds r1, r4, #0
	bl func_fe6_080823A0
	ldr r0, .L0807FA74 @ =0x02015638
	mov r3, r8
	ldr r2, [r3, #0x54]
	ldrh r1, [r4]
	lsrs r3, r1, #4
	str r6, [sp]
	movs r1, #1
	bl func_fe6_0807D9E4
	mov r3, sl
	ldrb r2, [r3]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	ldrb r3, [r5]
	lsls r1, r3, #1
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	bl PutUiEntryHover
	ldr r1, .L0807FA78 @ =0x02015D28
	ldrh r4, [r4]
	lsrs r0, r4, #4
	ldrb r5, [r5]
	adds r0, r5, r0
	lsls r0, r0, #2
	adds r1, r0, r1
	movs r4, #0xff
	ldrb r0, [r1]
	cmp r4, r0
	bne .L0807FA50
	ldr r0, .L0807FA7C @ =0x0201636A
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0807FA5C
.L0807FA50:
	ldr r0, .L0807FA80 @ =0x02015690
	ldrb r1, [r1]
	movs r2, #0x18
	movs r3, #0
	bl func_fe6_0807DCB8
.L0807FA5C:
	mov r0, r8
	bl func_fe6_0807D358
	mov r1, r8
	adds r1, #0x45
	ldrb r0, [r1]
	subs r0, #0xe
	strb r0, [r1]
	movs r0, #0xc
.L0807FA6E:
	mov r1, sb
	strb r0, [r1]
	b .L0807FA9A
	.align 2, 0
.L0807FA74: .4byte 0x02015638
.L0807FA78: .4byte 0x02015D28
.L0807FA7C: .4byte 0x0201636A
.L0807FA80: .4byte 0x02015690
.L0807FA84:
	mov r1, r8
	adds r1, #0x45
	ldrb r0, [r1]
	subs r0, #0xe
.L0807FA8C:
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne .L0807FA9A
.L0807FA96:
	mov r2, sb
	strb r0, [r2]
.L0807FA9A:
	mov r0, r8
	adds r0, #0x45
	ldrb r1, [r0]
	mov r5, r8
	adds r5, #0x50
	ldrh r2, [r5]
	subs r2, #0x28
	movs r0, #0xff
	ands r2, r0
	movs r0, #2
	bl SetBgOffset
	mov r6, r8
	adds r6, #0x29
	ldrb r2, [r6]
	cmp r2, #0
	beq .L0807FB52
	mov r0, r8
	adds r0, #0x46
	ldr r3, [sp, #4]
	ldrb r0, [r0]
	cmp r3, r0
	bne .L0807FADA
	mov r1, r8
	adds r1, #0x2e
	ldrh r4, [r5]
	lsrs r0, r4, #4
	ldrb r1, [r1]
	adds r0, r1, r0
	ldr r1, [sp, #8]
	cmp r1, r0
	beq .L0807FB52
.L0807FADA:
	mov r1, r8
	adds r1, #0x2f
	ldrb r0, [r1]
	cmp r0, #0
	bne .L0807FB0C
	adds r2, r0, #0
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #4
	adds r0, #0x10
	subs r1, #1
	ldrb r3, [r1]
	lsls r1, r3, #4
	lsls r2, r2, #5
	subs r2, #0x48
	subs r1, r1, r2
	mov r4, r8
	ldr r2, [r4, #0x54]
	lsls r3, r3, #1
	adds r2, #0x1c
	adds r2, r2, r3
	ldrh r2, [r2]
	bl StartItemHelpBox
	b .L0807FB52
.L0807FB0C:
	ldr r0, .L0807FB20 @ =0x0201636A
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0807FB24
	cmp r2, #1
	beq .L0807FB1C
	bl CloseHelpBox
.L0807FB1C:
	movs r0, #1
	b .L0807FB50
	.align 2, 0
.L0807FB20: .4byte 0x0201636A
.L0807FB24:
	ldrb r3, [r1]
	lsls r0, r3, #3
	subs r0, r0, r3
	lsls r0, r0, #4
	adds r0, #0x10
	mov r1, r8
	adds r1, #0x2e
	ldrb r2, [r1]
	lsls r1, r2, #4
	lsls r3, r3, #5
	subs r3, #0x48
	subs r1, r1, r3
	ldr r4, .L0807FBC8 @ =0x02015D28
	ldrh r5, [r5]
	lsrs r3, r5, #4
	adds r2, r2, r3
	lsls r2, r2, #2
	adds r2, r2, r4
	ldrh r2, [r2, #2]
	bl StartItemHelpBox
	movs r0, #2
.L0807FB50:
	strb r0, [r6]
.L0807FB52:
	mov r7, r8
	adds r7, #0x52
	ldrh r0, [r7]
	adds r1, r0, #0
	cmp r1, #1
	bne .L0807FBD0
	ldr r0, .L0807FBCC @ =gDispIo
	mov ip, r0
	movs r0, #0x20
	mov r1, ip
	ldrb r1, [r1, #1]
	orrs r0, r1
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	mov r2, ip
	strb r0, [r2, #1]
	mov r1, ip
	adds r1, #0x2d
	movs r0, #0x80
	strb r0, [r1]
	adds r1, #4
	movs r0, #0x28
	strb r0, [r1]
	subs r1, #5
	movs r0, #0xe0
	strb r0, [r1]
	adds r1, #4
	movs r0, #0x98
	strb r0, [r1]
	mov r5, ip
	adds r5, #0x34
	movs r1, #1
	ldrb r0, [r5]
	orrs r0, r1
	movs r6, #2
	orrs r0, r6
	movs r2, #4
	orrs r0, r2
	movs r4, #8
	orrs r0, r4
	movs r3, #0x10
	orrs r0, r3
	strb r0, [r5]
	mov r2, ip
	adds r2, #0x36
	ldrb r0, [r2]
	orrs r1, r0
	orrs r1, r6
	movs r0, #5
	rsbs r0, r0, #0
	ands r1, r0
	orrs r1, r4
	orrs r1, r3
	strb r1, [r2]
	movs r0, #2
	b .L0807FBD6
	.align 2, 0
.L0807FBC8: .4byte 0x02015D28
.L0807FBCC: .4byte gDispIo
.L0807FBD0:
	cmp r1, #1
	bhi .L0807FBD8
	adds r0, #1
.L0807FBD6:
	strh r0, [r7]
.L0807FBD8:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0807FBE8
func_fe6_0807FBE8: @ 0x0807FBE8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldr r0, .L0807FCF0 @ =gDispIo
	mov ip, r0
	movs r0, #0x20
	mov r1, ip
	ldrb r1, [r1, #1]
	orrs r0, r1
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	mov r2, ip
	strb r0, [r2, #1]
	mov r1, ip
	adds r1, #0x2d
	movs r0, #0
	mov r8, r0
	movs r0, #0x80
	strb r0, [r1]
	adds r1, #4
	movs r0, #0x28
	strb r0, [r1]
	subs r1, #5
	movs r0, #0xe0
	strb r0, [r1]
	adds r1, #4
	movs r0, #0x98
	strb r0, [r1]
	mov r5, ip
	adds r5, #0x34
	movs r1, #1
	ldrb r0, [r5]
	orrs r0, r1
	movs r6, #2
	orrs r0, r6
	movs r2, #4
	orrs r0, r2
	movs r4, #8
	orrs r0, r4
	movs r3, #0x10
	orrs r0, r3
	strb r0, [r5]
	mov r2, ip
	adds r2, #0x36
	ldrb r0, [r2]
	orrs r1, r0
	orrs r1, r6
	movs r0, #5
	rsbs r0, r0, #0
	ands r1, r0
	orrs r1, r4
	orrs r1, r3
	strb r1, [r2]
	mov r1, r8
	str r1, [sp]
	movs r0, #0xf
	movs r1, #4
	movs r2, #0xf
	movs r3, #0x10
	bl PutUiWindowFrame
	ldr r0, .L0807FCF4 @ =0x02015638
	ldr r2, [r7, #0x54]
	adds r4, r7, #0
	adds r4, #0x50
	ldrh r1, [r4]
	lsrs r3, r1, #4
	movs r5, #1
	str r5, [sp]
	movs r1, #1
	bl func_fe6_0807D9E4
	movs r0, #7
	bl EnableBgSync
	adds r0, r7, #0
	adds r0, #0x45
	ldrb r1, [r0]
	ldrh r2, [r4]
	subs r2, #0x28
	movs r0, #0xff
	ands r2, r0
	movs r0, #2
	bl SetBgOffset
	ldr r0, [r7, #0x60]
	ldrh r1, [r4]
	str r1, [sp]
	ldr r1, .L0807FCF8 @ =0x0201636A
	ldrh r1, [r1]
	str r1, [sp, #4]
	movs r1, #7
	str r1, [sp, #8]
	movs r1, #0xe0
	movs r2, #0x30
	movs r3, #0xc
	bl func_fe6_08082320
	adds r0, r7, #0
	adds r0, #0x2f
	ldrb r2, [r0]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	adds r1, r7, #0
	adds r1, #0x2e
	ldrb r1, [r1]
	lsls r1, r1, #1
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	bl PutUiEntryHover
	movs r0, #1
	bl func_fe6_0807E06C
	adds r0, r7, #0
	adds r0, #0x2b
	strb r5, [r0]
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0807FCF0: .4byte gDispIo
.L0807FCF4: .4byte 0x02015638
.L0807FCF8: .4byte 0x0201636A

	thumb_func_start func_fe6_0807FCFC
func_fe6_0807FCFC: @ 0x0807FCFC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	ldr r0, .L0807FDB0 @ =gBg0Tm+0x1E
	movs r1, #0xf
	movs r2, #0x13
	movs r3, #0
	bl TmFillRect_thm
	ldr r0, .L0807FDB4 @ =gBg1Tm+0x1E
	movs r1, #0xf
	movs r2, #0x13
	movs r3, #0
	bl TmFillRect_thm
	ldr r0, .L0807FDB8 @ =gBg2Tm+0x1E
	movs r1, #0xf
	movs r2, #0x1f
	movs r3, #0
	bl TmFillRect_thm
	ldr r0, [r6, #0x60]
	movs r5, #0
	str r5, [sp]
	str r5, [sp, #4]
	str r5, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0xd
	bl func_fe6_08082320
	adds r4, r6, #0
	adds r4, #0x30
	ldrb r0, [r4]
	cmp r0, #0xff
	bne .L0807FDD2
	bl GetSupplyItems
	adds r3, r0, #0
	strb r5, [r4]
	adds r0, r6, #0
	adds r0, #0x31
	strb r5, [r0]
	ldr r1, .L0807FDBC @ =0x02016368
	strh r5, [r1]
	movs r2, #0
	ldrh r0, [r3]
	adds r5, r6, #0
	adds r5, #0x46
	cmp r0, #0
	beq .L0807FD9C
	ldr r0, .L0807FDC0 @ =0x02015D28
	mov ip, r0
	movs r7, #0
	adds r4, r1, #0
.L0807FD72:
	lsls r1, r2, #2
	add r1, ip
	lsls r0, r2, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	strh r0, [r1, #2]
	strb r7, [r1]
	strb r2, [r1, #1]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0x63
	bhi .L0807FD9C
	lsls r0, r2, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0807FD72
.L0807FD9C:
	adds r0, r6, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #3
	bhi .L0807FDC4
	ldr r0, [r6, #0x14]
	adds r0, #0x3a
	ldrb r0, [r0]
	b .L0807FDC6
	.align 2, 0
.L0807FDB0: .4byte gBg0Tm+0x1E
.L0807FDB4: .4byte gBg1Tm+0x1E
.L0807FDB8: .4byte gBg2Tm+0x1E
.L0807FDBC: .4byte 0x02016368
.L0807FDC0: .4byte 0x02015D28
.L0807FDC4:
	movs r0, #0
.L0807FDC6:
	strb r0, [r5]
	adds r0, r6, #0
	adds r0, #0x46
	ldrb r0, [r0]
	bl func_fe6_0807D834
.L0807FDD2:
	adds r2, r6, #0
	adds r2, #0x46
	adds r0, r6, #0
	adds r0, #0x32
	ldrb r1, [r2]
	adds r0, r1, r0
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r5, r6, #0
	adds r5, #0x50
	strh r0, [r5]
	adds r1, r6, #0
	adds r1, #0x2f
	movs r0, #1
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x3b
	ldrb r2, [r2]
	adds r0, r2, r0
	ldrb r0, [r0]
	adds r4, r6, #0
	adds r4, #0x2e
	strb r0, [r4]
	adds r0, r4, #0
	adds r1, r5, #0
	bl func_fe6_080823A0
	adds r0, r6, #0
	adds r0, #0x4b
	ldrb r1, [r0]
	mov sb, r5
	mov sl, r4
	mov r8, r0
	cmp r1, #0
	bne .L0807FEA8
	ldr r0, [r6, #0x54]
	bl GetUnitItemCount
	movs r2, #0
	cmp r0, #0
	bne .L0807FE26
	movs r2, #1
.L0807FE26:
	ldr r4, .L0807FE6C @ =0x02015638
	ldr r5, .L0807FE70 @ =gBg2Tm+0x12A
	ldr r0, .L0807FE74 @ =gUnk_083272AC
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #0
	bl func_fe6_08082360
	adds r3, r4, #0
	adds r3, #8
	adds r1, r5, #0
	adds r1, #0x80
	movs r2, #0
	ldr r7, .L0807FE78 @ =0x02016368
	ldrh r0, [r7]
	cmp r0, #0
	bne .L0807FE4C
	movs r2, #1
.L0807FE4C:
	ldr r0, .L0807FE7C @ =gUnk_083272B8
	str r0, [sp]
	adds r0, r3, #0
	movs r3, #0
	bl func_fe6_08082360
	adds r0, r6, #0
	adds r0, #0x4c
	ldrb r0, [r0]
	cmp r0, #0
	beq .L0807FE80
	adds r1, r6, #0
	adds r1, #0x49
	movs r0, #2
	b .L0807FEA6
	.align 2, 0
.L0807FE6C: .4byte 0x02015638
.L0807FE70: .4byte gBg2Tm+0x12A
.L0807FE74: .4byte gUnk_083272AC
.L0807FE78: .4byte 0x02016368
.L0807FE7C: .4byte gUnk_083272B8
.L0807FE80:
	adds r3, r4, #0
	adds r3, #0x10
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r2, #0
	ldrh r0, [r7]
	cmp r0, #0
	bne .L0807FE94
	movs r2, #1
.L0807FE94:
	ldr r0, .L0807FF44 @ =gUnk_083272C4
	str r0, [sp]
	adds r0, r3, #0
	movs r3, #0
	bl func_fe6_08082360
	adds r1, r6, #0
	adds r1, #0x49
	movs r0, #3
.L0807FEA6:
	strb r0, [r1]
.L0807FEA8:
	movs r0, #2
	movs r1, #0
	movs r2, #0xd8
	bl SetBgOffset
	adds r0, r6, #0
	adds r0, #0x2c
	movs r5, #0
	strb r5, [r0]
	subs r0, #1
	strb r5, [r0]
	movs r0, #7
	bl EnableBgSync
	adds r4, r6, #0
	adds r4, #0x2d
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0807FEE0
	movs r1, #1
	rsbs r1, r1, #0
	adds r0, r6, #0
	bl func_fe6_080829E8
	adds r0, r6, #0
	bl func_fe6_0807D2E0
	str r0, [r6, #0x5c]
.L0807FEE0:
	movs r0, #0x18
	movs r1, #0
	bl func_fe6_0807DDC8
	ldrb r0, [r4]
	cmp r0, #4
	bne .L0807FF50
	adds r0, r6, #0
	bl func_fe6_0807D2E0
	str r0, [r6, #0x5c]
	movs r0, #5
	strb r0, [r4]
	mov r3, r8
	ldrb r0, [r3]
	cmp r0, #0
	beq .L0807FF5C
	adds r1, r6, #0
	adds r1, #0x31
	movs r0, #2
	strb r0, [r1]
	adds r0, r6, #0
	bl func_fe6_0807FBE8
	adds r0, r6, #0
	movs r1, #7
	bl Proc_Goto
	ldr r1, .L0807FF48 @ =0x02015D28
	mov r2, sb
	ldrh r2, [r2]
	lsrs r0, r2, #4
	mov r3, sl
	ldrb r3, [r3]
	adds r0, r3, r0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r2, [r0, #2]
	ldr r3, [r6, #0x5c]
	movs r0, #1
	movs r1, #0xb
	bl func_fe6_0807D4A8
	ldr r2, .L0807FF4C @ =0x00000C47
	movs r0, #0x10
	movs r1, #0x10
	adds r3, r6, #0
	bl func_fe6_08071B80
	b .L0807FF86
	.align 2, 0
.L0807FF44: .4byte gUnk_083272C4
.L0807FF48: .4byte 0x02015D28
.L0807FF4C: .4byte 0x00000C47
.L0807FF50:
	cmp r0, #3
	bhi .L0807FF5C
	movs r0, #2
	strb r0, [r4]
	mov r0, r8
	strb r5, [r0]
.L0807FF5C:
	adds r0, r6, #0
	adds r0, #0x49
	ldrb r0, [r0]
	lsls r3, r0, #1
	adds r3, #2
	movs r0, #0
	str r0, [sp]
	movs r0, #0x12
	movs r1, #8
	movs r2, #0xa
	bl PutUiWindowFrame
	adds r0, r6, #0
	adds r0, #0x31
	ldrb r0, [r0]
	lsls r1, r0, #1
	adds r1, #9
	movs r0, #0x13
	movs r2, #7
	bl PutUiEntryHover
.L0807FF86:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0807FF98
func_fe6_0807FF98: @ 0x0807FF98
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r0, #0x31
	ldrb r0, [r0]
	mov r8, r0
	adds r4, r5, #0
	adds r4, #0x29
	ldrb r0, [r4]
	ldr r7, .L0807FFCC @ =gKeySt
	cmp r0, #0
	beq .L0807FFD0
	ldr r1, [r7]
	movs r0, #0x81
	lsls r0, r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L0807FFD0
	bl CloseHelpBox
	movs r0, #0
	strb r0, [r4]
	b .L08080274
	.align 2, 0
.L0807FFCC: .4byte gKeySt
.L0807FFD0:
	ldr r2, [r7]
	ldrh r1, [r2, #6]
	movs r6, #0x80
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq .L0808004C
	adds r4, r5, #0
	adds r4, #0x31
	ldrb r0, [r4]
	lsls r1, r0, #1
	adds r1, #9
	movs r0, #0x13
	movs r2, #7
	bl RemoveUiEntryHover
	ldrb r1, [r4]
	adds r0, r5, #0
	adds r0, #0x49
	ldrb r0, [r0]
	subs r0, #1
	cmp r1, r0
	bge .L08080018
	adds r0, r1, #1
	strb r0, [r4]
	ldr r0, .L08080014 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08080038
	movs r0, #0x66
	bl m4aSongNumStart
	b .L08080038
	.align 2, 0
.L08080014: .4byte gPlaySt
.L08080018:
	ldr r1, [r7]
	adds r0, r6, #0
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L08080038
	movs r0, #0
	strb r0, [r4]
	ldr r0, .L08080048 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08080038
	movs r0, #0x66
	bl m4aSongNumStart
.L08080038:
	ldrb r4, [r4]
	lsls r1, r4, #1
	adds r1, #9
	movs r0, #0x13
	movs r2, #7
	bl PutUiEntryHover
	b .L080800F8
	.align 2, 0
.L08080048: .4byte gPlaySt
.L0808004C:
	movs r6, #0x40
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq .L080800C4
	adds r4, r5, #0
	adds r4, #0x31
	ldrb r0, [r4]
	lsls r1, r0, #1
	adds r1, #9
	movs r0, #0x13
	movs r2, #7
	bl RemoveUiEntryHover
	ldrb r0, [r4]
	cmp r0, #0
	beq .L08080088
	subs r0, #1
	strb r0, [r4]
	ldr r0, .L08080084 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L080800AE
	movs r0, #0x66
	bl m4aSongNumStart
	b .L080800AE
	.align 2, 0
.L08080084: .4byte gPlaySt
.L08080088:
	ldr r1, [r7]
	adds r0, r6, #0
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L080800AE
	ldr r0, .L080800C0 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L080800A4
	movs r0, #0x66
	bl m4aSongNumStart
.L080800A4:
	adds r0, r5, #0
	adds r0, #0x49
	ldrb r0, [r0]
	subs r0, #1
	strb r0, [r4]
.L080800AE:
	ldrb r4, [r4]
	lsls r1, r4, #1
	adds r1, #9
	movs r0, #0x13
	movs r2, #7
	bl PutUiEntryHover
	b .L080800F8
	.align 2, 0
.L080800C0: .4byte gPlaySt
.L080800C4:
	ldrh r1, [r2, #8]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq .L08080104
	ldr r0, .L08080100 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L080800DE
	movs r0, #0x6b
	bl m4aSongNumStart
.L080800DE:
	adds r0, r5, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #3
	bhi .L080800F0
	adds r0, r5, #0
	movs r1, #1
	bl func_fe6_080829E8
.L080800F0:
	adds r0, r5, #0
	movs r1, #6
	bl Proc_Goto
.L080800F8:
	adds r6, r5, #0
	adds r6, #0x29
	b .L08080250
	.align 2, 0
.L08080100: .4byte gPlaySt
.L08080104:
	movs r0, #1
	ands r0, r1
	adds r6, r5, #0
	adds r6, #0x29
	cmp r0, #0
	bne .L08080112
	b .L08080220
.L08080112:
	ldrb r0, [r6]
	cmp r0, #0
	beq .L0808011A
	b .L08080220
.L0808011A:
	adds r0, r5, #0
	adds r0, #0x31
	ldrb r4, [r0]
	cmp r4, #0
	bne .L08080150
	ldr r0, [r5, #0x54]
	bl GetUnitItemCount
	cmp r0, #0
	beq .L08080184
	ldr r0, .L0808014C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0808013E
	movs r0, #0x6a
	bl m4aSongNumStart
.L0808013E:
	adds r0, r5, #0
	adds r0, #0x2e
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	b .L080801FC
	.align 2, 0
.L0808014C: .4byte gPlaySt
.L08080150:
	cmp r4, #1
	bne .L08080178
	ldr r0, .L08080170 @ =0x02016368
	ldrh r0, [r0]
	cmp r0, #0
	beq .L08080184
	ldr r0, .L08080174 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L080801FC
	movs r0, #0x6a
	bl m4aSongNumStart
	b .L080801FC
	.align 2, 0
.L08080170: .4byte 0x02016368
.L08080174: .4byte gPlaySt
.L08080178:
	cmp r4, #2
	bne .L080801FC
	ldr r0, .L08080198 @ =0x02016368
	ldrh r0, [r0]
	cmp r0, #0
	bne .L080801A0
.L08080184:
	ldr r0, .L0808019C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08080274
	movs r0, #0x6c
	bl m4aSongNumStart
	b .L08080274
	.align 2, 0
.L08080198: .4byte 0x02016368
.L0808019C: .4byte gPlaySt
.L080801A0:
	ldr r0, .L0808020C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L080801B0
	movs r0, #0x6a
	bl m4aSongNumStart
.L080801B0:
	movs r0, #0
	bl EndFaceById
	ldr r0, .L08080210 @ =gBg0Tm
	movs r1, #0xf
	movs r2, #0x13
	movs r3, #0
	bl TmFillRect_thm
	ldr r0, .L08080214 @ =gBg1Tm
	movs r1, #0xf
	movs r2, #0x13
	movs r3, #0
	bl TmFillRect_thm
	ldr r0, .L08080218 @ =gBg2Tm
	movs r1, #0xf
	movs r2, #0x1f
	movs r3, #0
	bl TmFillRect_thm
	ldr r1, .L0808021C @ =0x02015D28
	adds r0, r5, #0
	adds r0, #0x50
	ldrh r0, [r0]
	lsrs r0, r0, #4
	adds r2, r5, #0
	adds r2, #0x2e
	ldrb r2, [r2]
	adds r0, r2, r0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r2, [r0, #2]
	ldr r3, [r5, #0x5c]
	movs r0, #1
	movs r1, #0xb
	bl func_fe6_0807D4A8
.L080801FC:
	adds r0, r5, #0
	bl func_fe6_0807FBE8
	adds r0, r5, #0
	bl Proc_Break
	b .L08080250
	.align 2, 0
.L0808020C: .4byte gPlaySt
.L08080210: .4byte gBg0Tm
.L08080214: .4byte gBg1Tm
.L08080218: .4byte gBg2Tm
.L0808021C: .4byte 0x02015D28
.L08080220:
	ldr r1, [r7]
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L08080250
	ldrb r0, [r6]
	cmp r0, #0
	bne .L08080250
	movs r0, #2
	strb r0, [r6]
	adds r0, r5, #0
	adds r0, #0x31
	ldrb r0, [r0]
	lsls r1, r0, #4
	adds r1, #0x48
	ldr r2, .L08080280 @ =gUnk_0867929C
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r2, [r0]
	movs r0, #0xa0
	bl StartHelpBox
.L08080250:
	ldrb r6, [r6]
	cmp r6, #2
	bne .L08080274
	adds r0, r5, #0
	adds r0, #0x31
	ldrb r1, [r0]
	cmp r1, r8
	beq .L08080274
	ldrb r0, [r0]
	lsls r1, r0, #4
	adds r1, #0x48
	ldr r2, .L08080280 @ =gUnk_0867929C
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r2, [r0]
	movs r0, #0xa0
	bl StartHelpBox
.L08080274:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08080280: .4byte gUnk_0867929C

	thumb_func_start func_fe6_08080284
func_fe6_08080284: @ 0x08080284
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r6, r0, #0
	adds r1, r6, #0
	adds r1, #0x2e
	adds r0, #0x50
	ldrh r0, [r0]
	lsrs r0, r0, #4
	ldrb r1, [r1]
	adds r0, r1, r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #4]
	adds r0, r6, #0
	adds r0, #0x46
	ldrb r0, [r0]
	str r0, [sp, #8]
	adds r4, r6, #0
	adds r4, #0x29
	ldrb r2, [r4]
	cmp r2, #0
	beq .L080802E0
	ldr r0, .L080802D8 @ =gKeySt
	ldr r1, [r0]
	movs r0, #0x81
	lsls r0, r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L080802E0
	cmp r2, #1
	beq .L080802DC
	bl CloseHelpBox
	movs r0, #0
	strb r0, [r4]
	bl .L080813D2
	.align 2, 0
.L080802D8: .4byte gKeySt
.L080802DC:
	movs r0, #0
	strb r0, [r4]
.L080802E0:
	adds r4, r6, #0
	adds r4, #0x2c
	ldrb r0, [r4]
	str r4, [sp, #0xc]
	cmp r0, #7
	bne .L080802F0
	bl .L080811E4
.L080802F0:
	cmp r0, #7
	bgt .L0808034C
	cmp r0, #2
	bne .L080802FC
	bl .L080810D0
.L080802FC:
	cmp r0, #2
	bgt .L08080322
	cmp r0, #0
	bne .L08080306
	b .L080806B0
.L08080306:
	cmp r0, #1
	bne .L0808030E
	bl .L08081078
.L0808030E:
	adds r7, r6, #0
	adds r7, #0x2e
	movs r0, #0x50
	adds r0, r0, r6
	mov r8, r0
	movs r1, #0x45
	adds r1, r1, r6
	mov sb, r1
	bl .L080812C6
.L08080322:
	cmp r0, #5
	bne .L0808032A
	bl .L08081128
.L0808032A:
	cmp r0, #6
	bne .L08080332
	bl .L08081152
.L08080332:
	adds r7, r6, #0
	adds r7, #0x2e
	movs r3, #0x50
	adds r3, r3, r6
	mov r8, r3
	movs r4, #0x45
	adds r4, r4, r6
	mov sb, r4
	movs r5, #0x52
	adds r5, r5, r6
	mov sl, r5
	bl .L080812FA
.L0808034C:
	cmp r0, #0xc
	bne .L08080354
	bl .L080812D4
.L08080354:
	cmp r0, #0xc
	bgt .L0808037C
	cmp r0, #0xa
	bne .L08080360
	bl .L080811EE
.L08080360:
	cmp r0, #0xb
	bne .L08080368
	bl .L08081216
.L08080368:
	adds r7, r6, #0
	adds r7, #0x2e
	movs r0, #0x50
	adds r0, r0, r6
	mov r8, r0
	movs r1, #0x45
	adds r1, r1, r6
	mov sb, r1
	bl .L080812C6
.L0808037C:
	cmp r0, #0x14
	bne .L08080382
	b .L080804B8
.L08080382:
	adds r7, r6, #0
	adds r7, #0x2e
	movs r3, #0x50
	adds r3, r3, r6
	mov r8, r3
	movs r4, #0x45
	adds r4, r4, r6
	mov sb, r4
	movs r5, #0x52
	adds r5, r5, r6
	mov sl, r5
	cmp r0, #0xff
	beq .L080803A0
	bl .L080812FA
.L080803A0:
	adds r0, r6, #0
	adds r0, #0x31
	ldrb r1, [r0]
	str r0, [sp, #0x10]
	cmp r1, #0
	bne .L080803CA
	subs r0, #2
	ldrb r2, [r0]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	ldrb r3, [r7]
	lsls r1, r3, #1
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	bl RemoveUiEntryHover
	b .L080803EA
.L080803CA:
	adds r2, r6, #0
	adds r2, #0x46
	adds r0, r6, #0
	adds r0, #0x3b
	ldrb r4, [r2]
	adds r0, r4, r0
	ldrb r1, [r7]
	strb r1, [r0]
	adds r0, r6, #0
	adds r0, #0x32
	ldrb r2, [r2]
	adds r0, r2, r0
	mov r5, r8
	ldrh r5, [r5]
	lsrs r1, r5, #4
	strb r1, [r0]
.L080803EA:
	ldr r0, [sp, #0x10]
	ldrb r0, [r0]
	cmp r0, #2
	bne .L0808047E
	ldr r0, [r6, #0x54]
	bl GetUnitFid
	adds r1, r0, #0
	movs r3, #4
	rsbs r3, r3, #0
	movs r0, #3
	str r0, [sp]
	movs r0, #0
	movs r2, #0x40
	bl StartFace
	ldr r5, .L080804A8 @ =gBg0Tm
	adds r0, r5, #0
	movs r1, #0xf
	movs r2, #0x13
	movs r3, #0
	bl TmFillRect_thm
	ldr r0, .L080804AC @ =gBg1Tm
	movs r1, #0xf
	movs r2, #0x13
	movs r3, #0
	bl TmFillRect_thm
	ldr r0, .L080804B0 @ =gBg2Tm
	movs r1, #0xf
	movs r2, #0x1f
	movs r3, #0
	bl TmFillRect_thm
	movs r0, #0
	str r0, [sp]
	movs r0, #1
	movs r1, #8
	movs r2, #0xe
	movs r3, #0xc
	bl PutUiWindowFrame
	bl func_fe6_0807D338
	ldr r0, [r6, #0x54]
	ldr r0, [r0]
	ldrh r0, [r0]
	bl DecodeMsg
	bl GetStringTextLen
	movs r4, #0x30
	subs r4, r4, r0
	lsrs r0, r4, #0x1f
	adds r4, r4, r0
	asrs r4, r4, #1
	ldr r0, [r6, #0x54]
	ldr r0, [r0]
	ldrh r0, [r0]
	bl DecodeMsg
	ldr r1, .L080804B4 @ =0x02015688
	str r0, [sp]
	adds r0, r1, #0
	adds r1, r5, #0
	movs r2, #0
	adds r3, r4, #0
	bl func_fe6_08082360
	ldr r1, [r6, #0x54]
	movs r0, #0
	bl func_fe6_0807D6C0
.L0808047E:
	adds r0, r6, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #3
	bhi .L08080494
	ldr r0, [r6, #0x14]
	adds r1, r6, #0
	adds r1, #0x46
	ldrb r1, [r1]
	adds r0, #0x3a
	strb r1, [r0]
.L08080494:
	adds r0, r6, #0
	movs r1, #4
	bl Proc_Goto
	movs r1, #0x45
	adds r1, r1, r6
	mov sb, r1
	bl .L080812C6
	.align 2, 0
.L080804A8: .4byte gBg0Tm
.L080804AC: .4byte gBg1Tm
.L080804B0: .4byte gBg2Tm
.L080804B4: .4byte 0x02015688
.L080804B8:
	ldr r0, .L080805D4 @ =gKeySt
	ldr r1, [r0]
	movs r0, #0x20
	ldrh r1, [r1, #6]
	ands r0, r1
	cmp r0, #0
	beq .L080804E4
	adds r1, r6, #0
	adds r1, #0x30
	ldrb r0, [r1]
	cmp r0, #0
	beq .L080804E4
	movs r0, #0
	strb r0, [r1]
	ldr r0, .L080805D8 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L080804E4
	movs r0, #0x66
	bl m4aSongNumStart
.L080804E4:
	ldr r0, .L080805D4 @ =gKeySt
	ldr r1, [r0]
	movs r0, #0x10
	ldrh r1, [r1, #6]
	ands r0, r1
	cmp r0, #0
	beq .L08080510
	adds r1, r6, #0
	adds r1, #0x30
	ldrb r3, [r1]
	cmp r3, #1
	beq .L08080510
	movs r0, #1
	strb r0, [r1]
	ldr r0, .L080805D8 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08080510
	movs r0, #0x66
	bl m4aSongNumStart
.L08080510:
	ldr r0, .L080805D4 @ =gKeySt
	ldr r0, [r0]
	ldrh r1, [r0, #8]
	movs r4, #1
	ands r4, r1
	cmp r4, #0
	beq .L080805F0
	ldr r0, .L080805D8 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0808052E
	movs r0, #0x6a
	bl m4aSongNumStart
.L0808052E:
	adds r0, r6, #0
	adds r0, #0x30
	ldrb r0, [r0]
	adds r7, r6, #0
	adds r7, #0x2e
	movs r4, #0x50
	adds r4, r4, r6
	mov r8, r4
	movs r5, #0x45
	adds r5, r5, r6
	mov sb, r5
	movs r1, #0x52
	adds r1, r1, r6
	mov sl, r1
	cmp r0, #0
	bne .L080805CC
	ldrh r2, [r4]
	lsrs r0, r2, #4
	ldrb r3, [r7]
	adds r0, r3, r0
	lsls r1, r0, #0x10
	ldr r4, .L080805DC @ =0x02016368
	adds r5, r4, #0
	ldr r2, .L080805E0 @ =0x0201636A
	mov ip, r2
	adds r3, r6, #0
	adds r3, #0x4b
	str r3, [sp, #0x14]
	ldrh r2, [r4]
	cmp r0, r2
	bge .L08080588
	ldr r3, .L080805E4 @ =0x02015D28
.L0808056E:
	asrs r1, r1, #0x10
	lsls r2, r1, #2
	adds r2, r2, r3
	adds r1, #1
	lsls r0, r1, #2
	adds r0, r0, r3
	ldrh r0, [r0, #2]
	strh r0, [r2, #2]
	lsls r1, r1, #0x10
	asrs r0, r1, #0x10
	ldrh r2, [r4]
	cmp r0, r2
	blt .L0808056E
.L08080588:
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	mov r3, ip
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
	adds r0, r7, #0
	mov r1, r8
	bl func_fe6_080823A0
	ldr r0, .L080805E8 @ =0x02015638
	ldr r2, [r6, #0x54]
	mov r4, r8
	ldrh r4, [r4]
	lsrs r3, r4, #4
	movs r1, #0
	str r1, [sp]
	movs r1, #1
	bl func_fe6_0807D9E4
	bl func_fe6_0807DE60
	ldr r1, .L080805EC @ =gAction
	movs r0, #0x19
	strb r0, [r1, #0x11]
	ldr r5, [sp, #0x14]
	ldrb r0, [r5]
	cmp r0, #0
	beq .L080805CC
	adds r0, r6, #0
	movs r1, #6
	bl Proc_Goto
.L080805CC:
	movs r0, #0
	ldr r1, [sp, #0xc]
	strb r0, [r1]
	b .L08080622
	.align 2, 0
.L080805D4: .4byte gKeySt
.L080805D8: .4byte gPlaySt
.L080805DC: .4byte 0x02016368
.L080805E0: .4byte 0x0201636A
.L080805E4: .4byte 0x02015D28
.L080805E8: .4byte 0x02015638
.L080805EC: .4byte gAction
.L080805F0:
	movs r0, #2
	ands r0, r1
	adds r7, r6, #0
	adds r7, #0x2e
	movs r2, #0x50
	adds r2, r2, r6
	mov r8, r2
	movs r3, #0x45
	adds r3, r3, r6
	mov sb, r3
	movs r5, #0x52
	adds r5, r5, r6
	mov sl, r5
	cmp r0, #0
	beq .L08080622
	ldr r0, .L0808069C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0808061E
	movs r0, #0x6b
	bl m4aSongNumStart
.L0808061E:
	ldr r0, [sp, #0xc]
	strb r4, [r0]
.L08080622:
	ldr r1, [sp, #0xc]
	ldrb r0, [r1]
	cmp r0, #0
	beq .L0808062E
	bl .L080812FA
.L0808062E:
	adds r0, r6, #0
	adds r0, #0x2f
	ldrb r2, [r0]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	ldrb r3, [r7]
	lsls r1, r3, #1
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	bl PutUiEntryHover
	ldr r0, .L080806A0 @ =gBg0Tm
	movs r1, #0xe
	movs r2, #0x13
	movs r3, #0
	bl TmFillRect_thm
	ldr r0, .L080806A4 @ =gBg1Tm
	movs r1, #0xe
	movs r2, #0x13
	movs r3, #0
	bl TmFillRect_thm
	ldr r1, .L080806A8 @ =0x02015D28
	mov r4, r8
	ldrh r4, [r4]
	lsrs r0, r4, #4
	ldrb r5, [r7]
	adds r0, r5, r0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r2, [r0, #2]
	ldr r3, [r6, #0x5c]
	movs r0, #1
	movs r1, #0xb
	bl func_fe6_0807D4A8
	movs r0, #3
	bl EnableBgSync
	ldr r0, .L080806AC @ =0x02016368
	ldrh r0, [r0]
	cmp r0, #0
	beq .L08080692
	bl .L080812FA
.L08080692:
	movs r0, #0xff
	ldr r1, [sp, #0xc]
	strb r0, [r1]
	bl .L080812FA
	.align 2, 0
.L0808069C: .4byte gPlaySt
.L080806A0: .4byte gBg0Tm
.L080806A4: .4byte gBg1Tm
.L080806A8: .4byte 0x02015D28
.L080806AC: .4byte 0x02016368
.L080806B0:
	ldr r1, .L080806F8 @ =gKeySt
	ldr r0, [r1]
	ldrh r2, [r0, #8]
	movs r0, #2
	ands r0, r2
	adds r3, r1, #0
	cmp r0, #0
	beq .L08080720
	adds r0, r6, #0
	adds r0, #0x4b
	ldrb r0, [r0]
	cmp r0, #0
	beq .L08080700
	ldr r0, .L080806FC @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	adds r7, r6, #0
	adds r7, #0x2e
	movs r2, #0x50
	adds r2, r2, r6
	mov r8, r2
	movs r3, #0x45
	adds r3, r3, r6
	mov sb, r3
	movs r4, #0x52
	adds r4, r4, r6
	mov sl, r4
	cmp r0, #0
	bge .L080806EE
	bl .L080812FA
.L080806EE:
	movs r0, #0x6c
	bl m4aSongNumStart
	bl .L080812FA
	.align 2, 0
.L080806F8: .4byte gKeySt
.L080806FC: .4byte gPlaySt
.L08080700:
	ldr r0, .L0808071C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08080710
	movs r0, #0x6b
	bl m4aSongNumStart
.L08080710:
	movs r0, #0xff
	strb r0, [r4]
	adds r7, r6, #0
	adds r7, #0x2e
	b .L08080BBA
	.align 2, 0
.L0808071C: .4byte gPlaySt
.L08080720:
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	bne .L0808072A
	b .L08080B68
.L0808072A:
	adds r0, r6, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	beq .L08080736
	b .L08080B68
.L08080736:
	adds r4, r6, #0
	adds r4, #0x2f
	ldrb r2, [r4]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	adds r5, r6, #0
	adds r5, #0x2e
	ldrb r3, [r5]
	lsls r1, r3, #1
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	bl RemoveUiEntryHover
	adds r0, r6, #0
	adds r0, #0x31
	ldrb r1, [r0]
	adds r7, r5, #0
	str r0, [sp, #0x10]
	adds r5, r4, #0
	cmp r1, #0
	beq .L0808076A
	b .L08080918
.L0808076A:
	bl func_fe6_08082A08
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x64
	bne .L080807A0
	ldr r0, .L0808079C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	movs r4, #0x50
	adds r4, r4, r6
	mov r8, r4
	movs r1, #0x45
	adds r1, r1, r6
	mov sb, r1
	movs r2, #0x52
	adds r2, r2, r6
	mov sl, r2
	cmp r0, #0
	bge .L08080794
	b .L08080A3E
.L08080794:
	movs r0, #0x6c
	bl m4aSongNumStart
	b .L08080A3E
	.align 2, 0
.L0808079C: .4byte gPlaySt
.L080807A0:
	adds r0, r6, #0
	adds r0, #0x4c
	ldrb r0, [r0]
	cmp r0, #0
	beq .L080807E0
	ldr r0, [r6, #0x54]
	ldrb r1, [r7]
	bl func_fe6_08082C80
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L080807E0
	ldrb r3, [r7]
	lsls r1, r3, #4
	adds r1, #0x48
	ldr r2, .L080807DC @ =0x000006C2
	movs r0, #0x10
	adds r3, r6, #0
	bl func_fe6_08082B00
	movs r4, #0x50
	adds r4, r4, r6
	mov r8, r4
	movs r0, #0x45
	adds r0, r0, r6
	mov sb, r0
	movs r1, #0x52
	adds r1, r1, r6
	mov sl, r1
	b .L08080A3E
	.align 2, 0
.L080807DC: .4byte 0x000006C2
.L080807E0:
	ldr r0, .L080808C8 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L080807F0
	movs r0, #0x6a
	bl m4aSongNumStart
.L080807F0:
	ldr r0, [r6, #0x54]
	ldrb r2, [r7]
	lsls r1, r2, #1
	adds r0, #0x1c
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r6, #0
	bl func_fe6_0807DEC8
	ldr r0, .L080808CC @ =0x02016368
	ldrh r0, [r0]
	lsls r2, r0, #0x10
	asrs r1, r2, #0x10
	adds r3, r6, #0
	adds r3, #0x50
	ldrh r4, [r3]
	lsrs r0, r4, #4
	mov r8, r3
	cmp r1, r0
	blt .L08080842
	ldr r0, .L080808D0 @ =0x02015D28
	mov sl, r0
	movs r1, #0
	mov sb, r1
.L08080820:
	asrs r2, r2, #0x10
	adds r1, r2, #1
	lsls r1, r1, #2
	add r1, sl
	lsls r0, r2, #2
	add r0, sl
	ldrh r0, [r0, #2]
	strh r0, [r1, #2]
	mov r4, sb
	strb r4, [r1]
	subs r2, #1
	lsls r2, r2, #0x10
	asrs r1, r2, #0x10
	ldrh r4, [r3]
	lsrs r0, r4, #4
	cmp r1, r0
	bge .L08080820
.L08080842:
	ldr r3, .L080808D0 @ =0x02015D28
	mov r0, r8
	ldrh r0, [r0]
	lsrs r1, r0, #4
	lsls r1, r1, #2
	adds r1, r1, r3
	ldr r0, [r6, #0x54]
	ldrb r4, [r7]
	lsls r2, r4, #1
	adds r0, #0x1c
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #0
	strh r0, [r1, #2]
	mov r1, r8
	ldrh r1, [r1]
	lsrs r0, r1, #4
	lsls r0, r0, #2
	adds r0, r0, r3
	strb r2, [r0]
	ldr r1, .L080808CC @ =0x02016368
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r1, .L080808D4 @ =0x0201636A
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r0, [r6, #0x54]
	ldrb r1, [r7]
	bl UnitRemoveItem
	ldr r1, [r6, #0x54]
	movs r0, #0
	bl func_fe6_0807D6C0
	bl func_fe6_0807DE60
	ldr r1, .L080808D8 @ =gAction
	movs r0, #0x19
	strb r0, [r1, #0x11]
	ldr r0, [r6, #0x54]
	bl GetUnitItemCount
	cmp r0, #0
	bne .L080808DC
	adds r0, r6, #0
	bl func_fe6_0807D358
	adds r0, r6, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #3
	bhi .L080808BA
	ldr r0, [r6, #0x14]
	adds r1, r6, #0
	adds r1, #0x46
	ldrb r1, [r1]
	adds r0, #0x3a
	strb r1, [r0]
.L080808BA:
	adds r0, r6, #0
	movs r1, #4
	bl Proc_Goto
	bl .L080813D2
	.align 2, 0
.L080808C8: .4byte gPlaySt
.L080808CC: .4byte 0x02016368
.L080808D0: .4byte 0x02015D28
.L080808D4: .4byte 0x0201636A
.L080808D8: .4byte gAction
.L080808DC:
	ldr r0, .L08080914 @ =0x02015638
	ldr r2, [r6, #0x54]
	mov r4, r8
	ldrh r4, [r4]
	lsrs r3, r4, #4
	movs r1, #0
	str r1, [sp]
	movs r1, #1
	bl func_fe6_0807D9E4
	ldr r0, [r6, #0x54]
	bl GetUnitItemCount
	ldrb r2, [r7]
	adds r1, r2, #1
	movs r3, #0x45
	adds r3, r3, r6
	mov sb, r3
	movs r4, #0x52
	adds r4, r4, r6
	mov sl, r4
	cmp r0, r1
	blt .L0808090C
	b .L08080A3E
.L0808090C:
	subs r0, r2, #1
	strb r0, [r7]
	b .L08080A3E
	.align 2, 0
.L08080914: .4byte 0x02015638
.L08080918:
	movs r0, #0x50
	adds r0, r0, r6
	mov r8, r0
	movs r2, #0x45
	adds r2, r2, r6
	mov sb, r2
	movs r3, #0x52
	adds r3, r3, r6
	mov sl, r3
	cmp r1, #1
	beq .L08080930
	b .L08080A3E
.L08080930:
	ldr r0, .L08080A04 @ =0x0201636A
	ldrh r0, [r0]
	cmp r0, #0
	beq .L08080A1C
	ldr r0, [r6, #0x54]
	bl GetUnitItemCount
	cmp r0, #4
	bgt .L08080A1C
	ldr r0, .L08080A08 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08080952
	movs r0, #0x6a
	bl m4aSongNumStart
.L08080952:
	ldr r0, [r6, #0x54]
	bl GetUnitItemCount
	ldr r1, [r6, #0x54]
	lsls r0, r0, #1
	adds r1, #0x1c
	adds r1, r1, r0
	mov r4, r8
	ldrh r4, [r4]
	lsrs r0, r4, #4
	ldrb r2, [r7]
	adds r0, r2, r0
	lsls r0, r0, #2
	ldr r3, .L08080A0C @ =0x02015D28
	adds r0, r0, r3
	ldrh r0, [r0, #2]
	strh r0, [r1]
	ldr r0, [r6, #0x54]
	bl UnitRemoveInvalidItems
	mov r4, r8
	ldrh r4, [r4]
	lsrs r0, r4, #4
	ldrb r1, [r7]
	adds r0, r1, r0
	lsls r1, r0, #0x10
	ldr r4, .L08080A10 @ =0x02016368
	ldrh r2, [r4]
	cmp r0, r2
	bge .L080809AA
	ldr r3, .L08080A0C @ =0x02015D28
.L08080990:
	asrs r1, r1, #0x10
	lsls r2, r1, #2
	adds r2, r2, r3
	adds r1, #1
	lsls r0, r1, #2
	adds r0, r0, r3
	ldrh r0, [r0, #2]
	strh r0, [r2, #2]
	lsls r1, r1, #0x10
	asrs r0, r1, #0x10
	ldrh r2, [r4]
	cmp r0, r2
	blt .L08080990
.L080809AA:
	ldr r4, .L08080A10 @ =0x02016368
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	ldr r1, .L08080A04 @ =0x0201636A
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	adds r0, r7, #0
	mov r1, r8
	bl func_fe6_080823A0
	ldr r0, .L08080A14 @ =0x02015638
	ldr r2, [r6, #0x54]
	mov r3, r8
	ldrh r1, [r3]
	lsrs r1, r1, #4
	mov ip, r1
	movs r1, #0
	str r1, [sp]
	movs r1, #1
	mov r3, ip
	bl func_fe6_0807D9E4
	ldr r1, [r6, #0x54]
	movs r0, #0
	bl func_fe6_0807D6C0
	bl func_fe6_0807DE60
	ldr r1, .L08080A18 @ =gAction
	movs r0, #0x19
	strb r0, [r1, #0x11]
	ldr r0, [r6, #0x54]
	bl GetUnitItemCount
	cmp r0, #5
	beq .L080809FC
	ldrh r0, [r4]
	cmp r0, #0
	bne .L08080A3E
.L080809FC:
	movs r0, #0xff
	ldr r2, [sp, #0xc]
	strb r0, [r2]
	b .L08080A3E
	.align 2, 0
.L08080A04: .4byte 0x0201636A
.L08080A08: .4byte gPlaySt
.L08080A0C: .4byte 0x02015D28
.L08080A10: .4byte 0x02016368
.L08080A14: .4byte 0x02015638
.L08080A18: .4byte gAction
.L08080A1C:
	ldr r0, .L08080A90 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	movs r3, #0x50
	adds r3, r3, r6
	mov r8, r3
	movs r4, #0x45
	adds r4, r4, r6
	mov sb, r4
	movs r1, #0x52
	adds r1, r1, r6
	mov sl, r1
	cmp r0, #0
	blt .L08080A3E
	movs r0, #0x6c
	bl m4aSongNumStart
.L08080A3E:
	ldr r2, [sp, #0x10]
	ldrb r2, [r2]
	cmp r2, #2
	beq .L08080A48
	b .L08080B60
.L08080A48:
	ldr r0, .L08080A94 @ =0x0201636A
	ldrh r0, [r0]
	cmp r0, #0
	beq .L08080B3C
	ldr r1, .L08080A98 @ =0x02015D28
	mov r3, r8
	ldrh r3, [r3]
	lsrs r0, r3, #4
	ldrb r4, [r7]
	adds r0, r4, r0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r0, [r0, #2]
	bl GetItemAttributes
	adds r4, r0, #0
	movs r0, #0x10
	ands r4, r0
	cmp r4, #0
	beq .L08080AA0
	ldrb r2, [r5]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #4
	adds r0, #0x10
	ldrb r3, [r7]
	lsls r1, r3, #4
	lsls r2, r2, #5
	subs r2, #0x48
	subs r1, r1, r2
	ldr r2, .L08080A9C @ =0x00000C33
	adds r3, r6, #0
	bl func_fe6_08082B00
	b .L08080E2E
	.align 2, 0
.L08080A90: .4byte gPlaySt
.L08080A94: .4byte 0x0201636A
.L08080A98: .4byte 0x02015D28
.L08080A9C: .4byte 0x00000C33
.L08080AA0:
	ldr r0, .L08080B20 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08080AB0
	movs r0, #0x6a
	bl m4aSongNumStart
.L08080AB0:
	adds r1, r6, #0
	adds r1, #0x30
	movs r0, #1
	strb r0, [r1]
	movs r0, #0x14
	ldr r5, [sp, #0xc]
	strb r0, [r5]
	str r4, [sp]
	movs r0, #2
	movs r1, #4
	movs r2, #0xc
	movs r3, #7
	bl PutUiWindowFrame
	ldr r4, .L08080B24 @ =0x020155E8
	ldr r5, .L08080B28 @ =gBg0Tm+0x148
	ldr r0, .L08080B2C @ =gUnk_083272CC
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	movs r3, #0
	bl func_fe6_08082360
	adds r0, r4, #0
	adds r0, #8
	adds r1, r5, #6
	ldr r2, .L08080B30 @ =gUnk_083272D4
	str r2, [sp]
	movs r2, #0
	movs r3, #0
	bl func_fe6_08082360
	adds r0, r4, #0
	adds r0, #0x10
	adds r1, r5, #0
	adds r1, #0xc2
	ldr r2, .L08080B34 @ =gUnk_083272E0
	str r2, [sp]
	movs r2, #0
	movs r3, #0
	bl func_fe6_08082360
	adds r4, #0x18
	adds r5, #0xca
	ldr r0, .L08080B38 @ =gUnk_083272E8
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	movs r3, #0
	bl func_fe6_08082360
	bl .L080812FA
	.align 2, 0
.L08080B20: .4byte gPlaySt
.L08080B24: .4byte 0x020155E8
.L08080B28: .4byte gBg0Tm+0x148
.L08080B2C: .4byte gUnk_083272CC
.L08080B30: .4byte gUnk_083272D4
.L08080B34: .4byte gUnk_083272E0
.L08080B38: .4byte gUnk_083272E8
.L08080B3C:
	ldr r0, .L08080B5C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08080B4C
	movs r0, #0x6c
	bl m4aSongNumStart
.L08080B4C:
	ldrb r2, [r5]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	ldrb r3, [r7]
	lsls r1, r3, #1
	b .L08080E3C
	.align 2, 0
.L08080B5C: .4byte gPlaySt
.L08080B60:
	adds r0, r6, #0
	bl func_fe6_0807D358
	b .L08080E2E
.L08080B68:
	ldr r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L08080C34
	adds r1, r6, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	bne .L08080C34
	adds r0, r6, #0
	adds r0, #0x31
	ldrb r2, [r0]
	cmp r2, #0
	bne .L08080BCE
	movs r0, #2
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x2f
	ldrb r2, [r0]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #4
	adds r0, #0x10
	adds r4, r6, #0
	adds r4, #0x2e
	ldrb r3, [r4]
	lsls r1, r3, #4
	lsls r2, r2, #5
	subs r2, #0x48
	subs r1, r1, r2
	ldr r2, [r6, #0x54]
	lsls r3, r3, #1
	adds r2, #0x1c
	adds r2, r2, r3
	ldrh r2, [r2]
	bl StartItemHelpBox
	adds r7, r4, #0
.L08080BBA:
	movs r5, #0x50
	adds r5, r5, r6
	mov r8, r5
	movs r0, #0x45
	adds r0, r0, r6
	mov sb, r0
	movs r1, #0x52
	adds r1, r1, r6
	mov sl, r1
	b .L080812FA
.L08080BCE:
	ldr r0, .L08080C2C @ =0x0201636A
	ldrh r0, [r0]
	adds r7, r6, #0
	adds r7, #0x2e
	movs r3, #0x50
	adds r3, r3, r6
	mov r8, r3
	movs r4, #0x45
	adds r4, r4, r6
	mov sb, r4
	movs r5, #0x52
	adds r5, r5, r6
	mov sl, r5
	cmp r0, #0
	bne .L08080BEE
	b .L080812FA
.L08080BEE:
	subs r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls .L08080BFA
	b .L080812FA
.L08080BFA:
	movs r0, #2
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x2f
	ldrb r2, [r0]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #4
	adds r0, #0x10
	ldrb r4, [r7]
	lsls r1, r4, #4
	lsls r2, r2, #5
	subs r2, #0x48
	subs r1, r1, r2
	ldr r2, .L08080C30 @ =0x02015D28
	mov ip, r2
	ldrh r3, [r3]
	lsrs r2, r3, #4
	adds r2, r2, r4
	lsls r2, r2, #2
	add r2, ip
	ldrh r2, [r2, #2]
	bl StartItemHelpBox
	b .L080812FA
	.align 2, 0
.L08080C2C: .4byte 0x0201636A
.L08080C30: .4byte 0x02015D28
.L08080C34:
	adds r0, r6, #0
	adds r0, #0x2f
	ldrb r2, [r0]
	adds r5, r0, #0
	cmp r2, #1
	beq .L08080C42
	b .L08080E50
.L08080C42:
	ldr r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #2
	ldrh r1, [r1, #4]
	ands r0, r1
	cmp r0, #0
	beq .L08080C5C
	adds r1, r6, #0
	adds r1, #0x4a
	movs r0, #2
	strb r0, [r1]
	adds r4, r1, #0
	b .L08080C64
.L08080C5C:
	adds r0, r6, #0
	adds r0, #0x4a
	strb r2, [r0]
	adds r4, r0, #0
.L08080C64:
	ldr r1, [r3]
	movs r2, #0x40
	adds r0, r2, #0
	ldrh r7, [r1, #6]
	ands r0, r7
	cmp r0, #0
	bne .L08080C82
	adds r0, r2, #0
	ldrh r1, [r1, #0x10]
	ands r0, r1
	cmp r0, #0
	beq .L08080D34
	ldrb r0, [r4]
	cmp r0, #2
	bne .L08080D34
.L08080C82:
	adds r0, r6, #0
	adds r0, #0x2e
	ldrb r1, [r0]
	mov sb, r1
	adds r7, r0, #0
	movs r2, #0x50
	adds r2, r2, r6
	mov r8, r2
	cmp r1, #1
	bne .L08080CEC
	ldrh r0, [r2]
	cmp r0, #0
	beq .L08080CEC
	ldr r0, .L08080CE4 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08080CAC
	movs r0, #0x66
	bl m4aSongNumStart
.L08080CAC:
	ldr r0, .L08080CE8 @ =0x02015638
	mov r3, r8
	ldrh r3, [r3]
	lsrs r2, r3, #4
	subs r2, #1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r3, [r6, #0x54]
	movs r1, #0
	str r1, [sp]
	movs r1, #1
	bl func_fe6_0807DB80
	adds r0, r6, #0
	bl func_fe6_0807D358
	ldrb r4, [r4]
	lsls r0, r4, #2
	mov r4, r8
	ldrh r4, [r4]
	subs r0, r4, r0
	mov r5, r8
	strh r0, [r5]
	mov r1, sb
	ldr r0, [sp, #0xc]
	strb r1, [r0]
	b .L08080DC2
	.align 2, 0
.L08080CE4: .4byte gPlaySt
.L08080CE8: .4byte 0x02015638
.L08080CEC:
	ldrb r0, [r7]
	movs r4, #0x45
	adds r4, r4, r6
	mov sb, r4
	movs r1, #0x52
	adds r1, r1, r6
	mov sl, r1
	cmp r0, #0
	bne .L08080D00
	b .L080812FA
.L08080D00:
	ldr r0, .L08080D30 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08080D10
	movs r0, #0x66
	bl m4aSongNumStart
.L08080D10:
	ldrb r2, [r5]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	ldrb r3, [r7]
	lsls r1, r3, #1
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	bl RemoveUiEntryHover
	ldrb r0, [r7]
	subs r0, #1
	b .L08080E2C
	.align 2, 0
.L08080D30: .4byte gPlaySt
.L08080D34:
	ldr r1, [r3]
	movs r2, #0x80
	adds r0, r2, #0
	ldrh r7, [r1, #6]
	ands r0, r7
	cmp r0, #0
	bne .L08080D5A
	adds r0, r2, #0
	ldrh r1, [r1, #0x10]
	ands r0, r1
	adds r7, r6, #0
	adds r7, #0x2e
	cmp r0, #0
	bne .L08080D52
	b .L08080F84
.L08080D52:
	ldrb r0, [r4]
	cmp r0, #2
	beq .L08080D5A
	b .L08080F84
.L08080D5A:
	adds r0, r6, #0
	adds r0, #0x2e
	ldrb r1, [r0]
	adds r7, r0, #0
	cmp r1, #5
	bls .L08080D68
	b .L08080F84
.L08080D68:
	movs r2, #0x50
	adds r2, r2, r6
	mov r8, r2
	ldr r3, .L08080DD0 @ =0x0201636A
	mov ip, r3
	cmp r1, #5
	bne .L08080DDC
	ldrh r1, [r2]
	lsrs r0, r1, #4
	adds r0, #7
	ldrh r1, [r3]
	cmp r0, r1
	bge .L08080DDC
	ldr r0, .L08080DD4 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08080D92
	movs r0, #0x66
	bl m4aSongNumStart
.L08080D92:
	ldr r0, .L08080DD8 @ =0x02015638
	mov r3, r8
	ldrh r3, [r3]
	lsrs r2, r3, #4
	adds r2, #7
	ldr r3, [r6, #0x54]
	movs r1, #0
	str r1, [sp]
	movs r1, #1
	bl func_fe6_0807DB80
	adds r0, r6, #0
	bl func_fe6_0807D358
	ldrb r4, [r4]
	lsls r0, r4, #2
	mov r4, r8
	ldrh r4, [r4]
	adds r0, r4, r0
	mov r5, r8
	strh r0, [r5]
	movs r0, #2
	ldr r1, [sp, #0xc]
	strb r0, [r1]
.L08080DC2:
	movs r2, #0x45
	adds r2, r2, r6
	mov sb, r2
	movs r3, #0x52
	adds r3, r3, r6
	mov sl, r3
	b .L080812FA
	.align 2, 0
.L08080DD0: .4byte 0x0201636A
.L08080DD4: .4byte gPlaySt
.L08080DD8: .4byte 0x02015638
.L08080DDC:
	mov r4, r8
	ldrh r4, [r4]
	lsrs r0, r4, #4
	ldrb r1, [r7]
	adds r0, r1, r0
	adds r0, #1
	movs r2, #0x45
	adds r2, r2, r6
	mov sb, r2
	movs r3, #0x52
	adds r3, r3, r6
	mov sl, r3
	mov r4, ip
	ldrh r4, [r4]
	cmp r0, r4
	blt .L08080DFE
	b .L080812FA
.L08080DFE:
	ldr r0, .L08080E4C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08080E0E
	movs r0, #0x66
	bl m4aSongNumStart
.L08080E0E:
	ldrb r2, [r5]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	ldrb r3, [r7]
	lsls r1, r3, #1
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	bl RemoveUiEntryHover
	ldrb r0, [r7]
	adds r0, #1
.L08080E2C:
	strb r0, [r7]
.L08080E2E:
	ldrb r2, [r5]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	ldrb r4, [r7]
	lsls r1, r4, #1
.L08080E3C:
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	bl PutUiEntryHover
	b .L080812FA
	.align 2, 0
.L08080E4C: .4byte gPlaySt
.L08080E50:
	ldr r0, [r3]
	ldrh r1, [r0, #6]
	movs r7, #0x40
	mov r8, r7
	mov r0, r8
	ands r0, r1
	cmp r0, #0
	beq .L08080EF4
	ldrb r2, [r5]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	adds r4, r6, #0
	adds r4, #0x2e
	ldrb r7, [r4]
	lsls r1, r7, #1
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	str r3, [sp, #0x18]
	bl RemoveUiEntryHover
	ldrb r0, [r4]
	adds r7, r4, #0
	ldr r3, [sp, #0x18]
	cmp r0, #0
	beq .L08080EA4
	ldr r0, .L08080EA0 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08080E9A
	movs r0, #0x66
	bl m4aSongNumStart
.L08080E9A:
	ldrb r0, [r7]
	b .L08080ED0
	.align 2, 0
.L08080EA0: .4byte gPlaySt
.L08080EA4:
	ldr r1, [r3]
	mov r0, r8
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L08080ED4
	ldr r0, .L08080EF0 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08080EC0
	movs r0, #0x66
	bl m4aSongNumStart
.L08080EC0:
	ldrb r0, [r5]
	lsls r1, r0, #2
	adds r0, r6, #0
	adds r0, #0x54
	adds r0, r0, r1
	ldr r0, [r0]
	bl GetUnitItemCount
.L08080ED0:
	subs r0, #1
	strb r0, [r7]
.L08080ED4:
	ldrb r2, [r5]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	ldrb r3, [r7]
	lsls r1, r3, #1
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	bl PutUiEntryHover
	b .L08080F84
	.align 2, 0
.L08080EF0: .4byte gPlaySt
.L08080EF4:
	movs r0, #0x80
	ands r0, r1
	adds r7, r6, #0
	adds r7, #0x2e
	cmp r0, #0
	beq .L08080F84
	ldrb r2, [r5]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	ldrb r4, [r7]
	lsls r1, r4, #1
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	bl RemoveUiEntryHover
	ldrb r4, [r7]
	ldr r0, [r6, #0x54]
	bl GetUnitItemCount
	subs r0, #1
	cmp r4, r0
	bge .L08080F48
	ldrb r0, [r7]
	cmp r0, #3
	bhi .L08080F48
	ldr r0, .L08080F44 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08080F3E
	movs r0, #0x66
	bl m4aSongNumStart
.L08080F3E:
	ldrb r0, [r7]
	adds r0, #1
	b .L08080F68
	.align 2, 0
.L08080F44: .4byte gPlaySt
.L08080F48:
	ldr r0, .L08081008 @ =gKeySt
	ldr r1, [r0]
	movs r0, #0x80
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L08080F6A
	ldr r0, .L0808100C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08080F66
	movs r0, #0x66
	bl m4aSongNumStart
.L08080F66:
	movs r0, #0
.L08080F68:
	strb r0, [r7]
.L08080F6A:
	ldrb r2, [r5]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	ldrb r3, [r7]
	lsls r1, r3, #1
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	bl PutUiEntryHover
.L08080F84:
	adds r4, r5, #0
	movs r0, #0x50
	adds r0, r0, r6
	mov r8, r0
	movs r1, #0x45
	adds r1, r1, r6
	mov sb, r1
	movs r2, #0x52
	adds r2, r2, r6
	mov sl, r2
	ldrb r3, [r4]
	cmp r3, #1
	beq .L08080FA0
	b .L080812FA
.L08080FA0:
	ldr r0, .L08081008 @ =gKeySt
	ldr r0, [r0]
	ldrh r1, [r0, #6]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq .L08081010
	ldr r0, .L0808100C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08080FBE
	movs r0, #0x67
	bl m4aSongNumStart
.L08080FBE:
	ldrb r2, [r4]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	ldrb r4, [r7]
	lsls r1, r4, #1
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	bl RemoveUiEntryHover
	adds r2, r6, #0
	adds r2, #0x46
	adds r0, r6, #0
	adds r0, #0x32
	ldrb r5, [r2]
	adds r0, r5, r0
	mov r3, r8
	ldrh r3, [r3]
	lsrs r1, r3, #4
	strb r1, [r0]
	adds r0, r6, #0
	adds r0, #0x3b
	ldrb r2, [r2]
	adds r0, r2, r0
	ldrb r1, [r7]
	strb r1, [r0]
	movs r0, #0x38
	mov r4, sb
	strb r0, [r4]
	movs r0, #5
	ldr r5, [sp, #0xc]
	strb r0, [r5]
	b .L080812FA
	.align 2, 0
.L08081008: .4byte gKeySt
.L0808100C: .4byte gPlaySt
.L08081010:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne .L0808101A
	b .L080812FA
.L0808101A:
	ldr r0, .L08081074 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0808102A
	movs r0, #0x67
	bl m4aSongNumStart
.L0808102A:
	ldrb r2, [r5]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	ldrb r3, [r7]
	lsls r1, r3, #1
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	bl RemoveUiEntryHover
	adds r2, r6, #0
	adds r2, #0x46
	adds r0, r6, #0
	adds r0, #0x32
	ldrb r4, [r2]
	adds r0, r4, r0
	mov r5, r8
	ldrh r5, [r5]
	lsrs r1, r5, #4
	strb r1, [r0]
	adds r0, r6, #0
	adds r0, #0x3b
	ldrb r2, [r2]
	adds r0, r2, r0
	ldrb r1, [r7]
	strb r1, [r0]
	movs r0, #0xc8
	mov r1, sb
	strb r0, [r1]
	movs r0, #0xa
	ldr r2, [sp, #0xc]
	strb r0, [r2]
	b .L080812FA
	.align 2, 0
.L08081074: .4byte gPlaySt
.L08081078:
	adds r0, r6, #0
	adds r0, #0x50
	adds r1, r6, #0
	adds r1, #0x4a
	ldrb r1, [r1]
	lsls r1, r1, #2
	ldrh r3, [r0]
	subs r1, r3, r1
	strh r1, [r0]
	ldrh r2, [r0]
	movs r1, #0xf
	ands r1, r2
	adds r7, r6, #0
	adds r7, #0x2e
	mov r8, r0
	movs r5, #0x45
	adds r5, r5, r6
	mov sb, r5
	movs r0, #0x52
	adds r0, r0, r6
	mov sl, r0
	cmp r1, #0
	beq .L080810A8
	b .L080812FA
.L080810A8:
	lsrs r0, r2, #4
	adds r0, #7
	lsls r0, r0, #1
	movs r1, #0x1f
	ands r0, r1
	lsls r0, r0, #6
	ldr r1, .L080810CC @ =gBg2Tm+0x1E
	adds r0, r0, r1
	movs r1, #0xf
	movs r2, #1
	movs r3, #0
	bl TmFillRect_thm
	movs r0, #4
	bl EnableBgSync
	movs r0, #0
	b .L080812F8
	.align 2, 0
.L080810CC: .4byte gBg2Tm+0x1E
.L080810D0:
	adds r0, r6, #0
	adds r0, #0x50
	adds r1, r6, #0
	adds r1, #0x4a
	ldrb r1, [r1]
	lsls r1, r1, #2
	ldrh r2, [r0]
	adds r1, r2, r1
	strh r1, [r0]
	ldrh r2, [r0]
	movs r1, #0xf
	ands r1, r2
	adds r7, r6, #0
	adds r7, #0x2e
	mov r8, r0
	movs r3, #0x45
	adds r3, r3, r6
	mov sb, r3
	movs r5, #0x52
	adds r5, r5, r6
	mov sl, r5
	cmp r1, #0
	beq .L08081100
	b .L080812FA
.L08081100:
	lsrs r0, r2, #4
	subs r0, #1
	lsls r0, r0, #1
	movs r1, #0x1f
	ands r0, r1
	lsls r0, r0, #6
	ldr r1, .L08081124 @ =gBg2Tm+0x1E
	adds r0, r0, r1
	movs r1, #0xf
	movs r2, #1
	movs r3, #0
	bl TmFillRect_thm
	movs r0, #4
	bl EnableBgSync
	movs r0, #0
	b .L080812F8
	.align 2, 0
.L08081124: .4byte gBg2Tm+0x1E
.L08081128:
	adds r1, r6, #0
	adds r1, #0x45
	ldrb r0, [r1]
	adds r0, #0x38
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r7, r6, #0
	adds r7, #0x2e
	movs r2, #0x50
	adds r2, r2, r6
	mov r8, r2
	mov sb, r1
	movs r3, #0x52
	adds r3, r3, r6
	mov sl, r3
	cmp r0, #0x70
	beq .L0808114E
	b .L080812FA
.L0808114E:
	movs r0, #6
	b .L080812F8
.L08081152:
	adds r2, r6, #0
	adds r2, #0x45
	movs r0, #0x90
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0x46
	ldrb r1, [r0]
	adds r5, r0, #0
	mov sb, r2
	cmp r1, #8
	bne .L0808116C
	movs r0, #0
	b .L0808116E
.L0808116C:
	adds r0, r1, #1
.L0808116E:
	strb r0, [r5]
	adds r0, r6, #0
	adds r0, #0x32
	ldrb r4, [r5]
	adds r0, r4, r0
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r4, r6, #0
	adds r4, #0x50
	strh r0, [r4]
	adds r0, r6, #0
	adds r0, #0x3b
	ldrb r7, [r5]
	adds r0, r7, r0
	ldrb r0, [r0]
	adds r7, r6, #0
	adds r7, #0x2e
	strb r0, [r7]
	ldrb r0, [r5]
	bl func_fe6_0807D834
	adds r0, r7, #0
	adds r1, r4, #0
	bl func_fe6_080823A0
	ldr r0, .L080811E0 @ =0x02015638
	ldr r2, [r6, #0x54]
	ldrh r1, [r4]
	lsrs r3, r1, #4
	movs r1, #1
	str r1, [sp]
	bl func_fe6_0807D9E4
	adds r0, r6, #0
	adds r0, #0x2f
	ldrb r2, [r0]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	ldrb r3, [r7]
	lsls r1, r3, #1
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	bl PutUiEntryHover
	adds r0, r6, #0
	bl func_fe6_0807D358
	mov r5, sb
	ldrb r0, [r5]
	adds r0, #0xe
	strb r0, [r5]
	movs r0, #7
	b .L080812C0
	.align 2, 0
.L080811E0: .4byte 0x02015638
.L080811E4:
	adds r1, r6, #0
	adds r1, #0x45
	ldrb r0, [r1]
	adds r0, #0xe
	b .L080812DC
.L080811EE:
	adds r1, r6, #0
	adds r1, #0x45
	ldrb r0, [r1]
	subs r0, #0x38
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r7, r6, #0
	adds r7, #0x2e
	movs r2, #0x50
	adds r2, r2, r6
	mov r8, r2
	mov sb, r1
	movs r3, #0x52
	adds r3, r3, r6
	mov sl, r3
	cmp r0, #0x90
	bne .L080812FA
	movs r0, #0xb
	b .L080812F8
.L08081216:
	adds r2, r6, #0
	adds r2, #0x45
	movs r0, #0x70
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0x46
	ldrb r1, [r0]
	adds r5, r0, #0
	mov sb, r2
	cmp r1, #0
	bne .L08081230
	movs r0, #8
	b .L08081232
.L08081230:
	subs r0, r1, #1
.L08081232:
	strb r0, [r5]
	movs r4, #0x2f
	adds r4, r4, r6
	mov r8, r4
	ldrb r2, [r4]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	adds r7, r6, #0
	adds r7, #0x2e
	ldrb r3, [r7]
	lsls r1, r3, #1
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	bl RemoveUiEntryHover
	adds r0, r6, #0
	adds r0, #0x32
	ldrb r4, [r5]
	adds r0, r4, r0
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r4, r6, #0
	adds r4, #0x50
	strh r0, [r4]
	adds r0, r6, #0
	adds r0, #0x3b
	ldrb r1, [r5]
	adds r0, r1, r0
	ldrb r0, [r0]
	strb r0, [r7]
	ldrb r0, [r5]
	bl func_fe6_0807D834
	adds r0, r7, #0
	adds r1, r4, #0
	bl func_fe6_080823A0
	ldr r0, .L080812D0 @ =0x02015638
	ldr r2, [r6, #0x54]
	ldrh r5, [r4]
	lsrs r3, r5, #4
	movs r1, #1
	str r1, [sp]
	bl func_fe6_0807D9E4
	mov r0, r8
	ldrb r2, [r0]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	ldrb r3, [r7]
	lsls r1, r3, #1
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	bl PutUiEntryHover
	adds r0, r6, #0
	bl func_fe6_0807D358
	mov r5, sb
	ldrb r0, [r5]
	subs r0, #0xe
	strb r0, [r5]
	movs r0, #0xc
.L080812C0:
	ldr r1, [sp, #0xc]
	strb r0, [r1]
	mov r8, r4
.L080812C6:
	movs r2, #0x52
	adds r2, r2, r6
	mov sl, r2
	b .L080812FA
	.align 2, 0
.L080812D0: .4byte 0x02015638
.L080812D4:
	adds r1, r6, #0
	adds r1, #0x45
	ldrb r0, [r1]
	subs r0, #0xe
.L080812DC:
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r7, r6, #0
	adds r7, #0x2e
	movs r3, #0x50
	adds r3, r3, r6
	mov r8, r3
	mov sb, r1
	movs r5, #0x52
	adds r5, r5, r6
	mov sl, r5
	cmp r0, #0
	bne .L080812FA
.L080812F8:
	strb r0, [r4]
.L080812FA:
	mov r1, r8
	ldrh r1, [r1]
	lsrs r0, r1, #4
	ldrb r3, [r7]
	adds r5, r0, r3
	ldr r2, [sp, #4]
	cmp r2, r5
	bne .L08081316
	adds r0, r6, #0
	adds r0, #0x46
	ldr r4, [sp, #8]
	ldrb r0, [r0]
	cmp r4, r0
	beq .L080813B6
.L08081316:
	adds r4, r6, #0
	adds r4, #0x29
	ldrb r1, [r4]
	adds r0, r6, #0
	adds r0, #0x31
	str r0, [sp, #0x10]
	cmp r1, #0
	beq .L08081392
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08081352
	adds r0, r6, #0
	adds r0, #0x2f
	ldrb r2, [r0]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #4
	adds r0, #0x10
	lsls r1, r3, #4
	lsls r2, r2, #5
	subs r2, #0x48
	subs r1, r1, r2
	ldr r2, [r6, #0x54]
	lsls r3, r3, #1
	adds r2, #0x1c
	adds r2, r2, r3
	ldrh r2, [r2]
	bl StartItemHelpBox
	b .L08081392
.L08081352:
	ldr r0, .L08081368 @ =0x0201636A
	ldrh r0, [r0]
	cmp r0, #0
	bne .L0808136C
	cmp r1, #1
	beq .L08081362
	bl CloseHelpBox
.L08081362:
	movs r0, #1
	b .L08081390
	.align 2, 0
.L08081368: .4byte 0x0201636A
.L0808136C:
	adds r0, r6, #0
	adds r0, #0x2f
	ldrb r2, [r0]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #4
	adds r0, #0x10
	lsls r1, r3, #4
	lsls r2, r2, #5
	subs r2, #0x48
	subs r1, r1, r2
	ldr r3, .L080813E4 @ =0x02015D28
	lsls r2, r5, #2
	adds r2, r2, r3
	ldrh r2, [r2, #2]
	bl StartItemHelpBox
	movs r0, #2
.L08081390:
	strb r0, [r4]
.L08081392:
	ldr r1, [sp, #0x10]
	ldrb r1, [r1]
	cmp r1, #2
	bne .L080813B6
	ldr r1, .L080813E4 @ =0x02015D28
	mov r2, r8
	ldrh r2, [r2]
	lsrs r0, r2, #4
	ldrb r7, [r7]
	adds r0, r7, r0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r2, [r0, #2]
	ldr r3, [r6, #0x5c]
	movs r0, #1
	movs r1, #0xb
	bl func_fe6_0807D4A8
.L080813B6:
	mov r3, sb
	ldrb r1, [r3]
	mov r4, r8
	ldrh r2, [r4]
	subs r2, #0x28
	movs r0, #0xff
	ands r2, r0
	movs r0, #2
	bl SetBgOffset
	mov r5, sl
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
.L080813D2:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080813E4: .4byte 0x02015D28

	thumb_func_start func_fe6_080813E8
func_fe6_080813E8: @ 0x080813E8
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #3
	bne .L08081460
	ldr r0, [r4, #0x14]
	adds r1, r4, #0
	adds r1, #0x46
	ldrb r2, [r1]
	adds r0, #0x39
	movs r1, #0
	strb r2, [r0]
	ldr r0, [r4, #0x60]
	str r1, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	movs r2, #0
	movs r3, #0xd
	bl func_fe6_08082320
	adds r3, r4, #0
	adds r3, #0x50
	ldrh r0, [r3]
	adds r1, r4, #0
	adds r1, #0x4e
	strh r0, [r1]
	adds r2, r4, #0
	adds r2, #0x2e
	ldrb r0, [r2]
	subs r1, #7
	strb r0, [r1]
	ldr r5, .L0808145C @ =0x02015D28
	ldrh r1, [r3]
	lsrs r0, r1, #4
	ldrb r1, [r2]
	adds r0, r1, r0
	lsls r0, r0, #2
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08081460
	adds r1, r4, #0
	adds r1, #0x2c
	movs r0, #0
	strb r0, [r1]
	ldrh r3, [r3]
	lsrs r0, r3, #4
	ldrb r2, [r2]
	adds r0, r2, r0
	lsls r0, r0, #2
	adds r0, r0, r5
	ldrb r1, [r0, #1]
	adds r0, r4, #0
	adds r0, #0x48
	strb r1, [r0]
	b .L08081536
	.align 2, 0
.L0808145C: .4byte 0x02015D28
.L08081460:
	adds r1, r4, #0
	adds r1, #0x2f
	ldrb r0, [r1]
	cmp r0, #0
	bne .L08081486
	adds r2, r0, #0
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	subs r1, #1
	ldrb r1, [r1]
	lsls r1, r1, #1
	lsls r2, r2, #2
	subs r2, #9
	subs r1, r1, r2
	movs r2, #0xc
	bl RemoveUiEntryHover
.L08081486:
	ldr r0, .L080814F0 @ =gBg0Tm+0x1E
	movs r1, #0xf
	movs r2, #0x13
	movs r3, #0
	bl TmFillRect_thm
	ldr r0, .L080814F4 @ =gBg1Tm+0x1E
	movs r1, #0xf
	movs r2, #0x13
	movs r3, #0
	bl TmFillRect_thm
	ldr r0, .L080814F8 @ =gBg2Tm+0x1E
	movs r1, #0xf
	movs r2, #0x1f
	movs r3, #0
	bl TmFillRect_thm
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #3
	bne .L08081522
	ldr r0, [r4, #0x14]
	adds r1, r4, #0
	adds r1, #0x46
	ldrb r1, [r1]
	adds r0, #0x39
	strb r1, [r0]
	ldr r7, .L080814FC @ =0x02015D28
	adds r5, r4, #0
	adds r5, #0x2e
	adds r6, r4, #0
	adds r6, #0x50
	ldrh r1, [r6]
	lsrs r0, r1, #4
	ldrb r1, [r5]
	adds r0, r1, r0
	lsls r0, r0, #2
	adds r1, r0, r7
	ldrb r0, [r1]
	cmp r0, #0
	bne .L08081500
	ldrb r1, [r1, #1]
	adds r0, r4, #0
	adds r0, #0x48
	strb r1, [r0]
	adds r0, r4, #0
	movs r1, #4
	bl Proc_Goto
	b .L08081530
	.align 2, 0
.L080814F0: .4byte gBg0Tm+0x1E
.L080814F4: .4byte gBg1Tm+0x1E
.L080814F8: .4byte gBg2Tm+0x1E
.L080814FC: .4byte 0x02015D28
.L08081500:
	ldrb r0, [r1]
	bl GetUnitByPid
	str r0, [r4, #0x58]
	ldrh r6, [r6]
	lsrs r0, r6, #4
	ldrb r1, [r5]
	adds r0, r1, r0
	lsls r0, r0, #2
	adds r0, r0, r7
	ldrb r0, [r0, #1]
	strb r0, [r5]
	adds r0, r4, #0
	movs r1, #2
	bl Proc_Goto
	b .L08081530
.L08081522:
	movs r0, #1
	bl EndFaceById
	adds r0, r4, #0
	movs r1, #0
	bl Proc_Goto
.L08081530:
	movs r0, #7
	bl EnableBgSync
.L08081536:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08081540
func_fe6_08081540: @ 0x08081540
	push {lr}
	adds r2, r0, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #5
	beq .L0808157A
	adds r3, r2, #0
	adds r3, #0x2a
	ldrb r0, [r3]
	cmp r0, #0
	bne .L08081562
	ldr r0, [r2, #0x14]
	adds r1, r2, #0
	adds r1, #0x46
	ldrb r1, [r1]
	adds r0, #0x39
	strb r1, [r0]
.L08081562:
	ldrb r3, [r3]
	cmp r3, #4
	bne .L08081574
	ldr r0, [r2, #0x14]
	adds r1, r2, #0
	adds r1, #0x46
	ldrb r1, [r1]
	adds r0, #0x3a
	strb r1, [r0]
.L08081574:
	bl InitBmBgLayers
	b .L08081580
.L0808157A:
	ldr r0, [r2, #0x5c]
	bl Proc_End
.L08081580:
	movs r0, #0
	bl EndFaceById
	movs r0, #1
	bl EndFaceById
	ldr r0, .L080815B0 @ =gBg0Tm
	movs r1, #0
	bl TmFill
	ldr r0, .L080815B4 @ =gBg1Tm
	movs r1, #0
	bl TmFill
	ldr r0, .L080815B8 @ =gBg2Tm
	movs r1, #0
	bl TmFill
	movs r0, #7
	bl EnableBgSync
	pop {r0}
	bx r0
	.align 2, 0
.L080815B0: .4byte gBg0Tm
.L080815B4: .4byte gBg1Tm
.L080815B8: .4byte gBg2Tm

	thumb_func_start func_fe6_080815BC
func_fe6_080815BC: @ 0x080815BC
	push {r4, lr}
	adds r2, r0, #0
	lsls r4, r1, #0x18
	lsrs r4, r4, #0x18
	ldr r0, .L080815E0 @ =gUnk_086793E8
	adds r1, r2, #0
	bl SpawnProcLocking
	adds r2, r0, #0
	adds r2, #0x2a
	movs r1, #0
	strb r4, [r2]
	adds r0, #0x2d
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080815E0: .4byte gUnk_086793E8

	thumb_func_start func_fe6_080815E4
func_fe6_080815E4: @ 0x080815E4
	push {r4, lr}
	adds r4, r0, #0
	cmp r1, #0
	bne .L080815FC
	ldr r0, .L080815F8 @ =gUnk_08679490
	movs r1, #3
	bl SpawnProc
	b .L08081602
	.align 2, 0
.L080815F8: .4byte gUnk_08679490
.L080815FC:
	ldr r0, .L0808161C @ =gUnk_08679490
	bl SpawnProcLocking
.L08081602:
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x2d
	movs r0, #0
	movs r1, #4
	strb r1, [r3]
	str r4, [r2, #0x54]
	adds r1, r2, #0
	adds r1, #0x4b
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0808161C: .4byte gUnk_08679490

	thumb_func_start func_fe6_08081620
func_fe6_08081620: @ 0x08081620
	push {r4, lr}
	adds r4, r0, #0
	cmp r1, #0
	bne .L08081638
	ldr r0, .L08081634 @ =gUnk_08679490
	movs r1, #3
	bl SpawnProc
	b .L0808163E
	.align 2, 0
.L08081634: .4byte gUnk_08679490
.L08081638:
	ldr r0, .L08081658 @ =gUnk_08679490
	bl SpawnProcLocking
.L0808163E:
	adds r1, r0, #0
	adds r2, r1, #0
	adds r2, #0x2d
	movs r0, #4
	strb r0, [r2]
	str r4, [r1, #0x54]
	adds r1, #0x4b
	movs r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08081658: .4byte gUnk_08679490

	thumb_func_start func_fe6_0808165C
func_fe6_0808165C: @ 0x0808165C
	push {lr}
	adds r0, #0x2e
	ldrb r0, [r0]
	bl UpdateEquipInfoWindow
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0808166C
func_fe6_0808166C: @ 0x0808166C
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #1
	bne .L080816EC
	movs r0, #0
	str r0, [sp]
	movs r0, #0x11
	movs r1, #4
	movs r2, #0xc
	movs r3, #7
	bl PutUiWindowFrame
	ldr r4, .L080816D8 @ =gBg0Tm+0x166
	ldr r0, .L080816DC @ =gUnk_083272F0
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl func_fe6_08082360
	adds r0, r5, #0
	adds r0, #8
	adds r1, r4, #6
	ldr r2, .L080816E0 @ =gUnk_083272F8
	str r2, [sp]
	movs r2, #0
	movs r3, #0
	bl func_fe6_08082360
	adds r0, r5, #0
	adds r0, #0x10
	adds r1, r4, #0
	adds r1, #0xc2
	ldr r2, .L080816E4 @ =gUnk_08327304
	str r2, [sp]
	movs r2, #0
	movs r3, #0
	bl func_fe6_08082360
	adds r0, r5, #0
	adds r0, #0x18
	adds r4, #0xca
	ldr r1, .L080816E8 @ =gUnk_0832730C
	str r1, [sp]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl func_fe6_08082360
	b .L08081704
	.align 2, 0
.L080816D8: .4byte gBg0Tm+0x166
.L080816DC: .4byte gUnk_083272F0
.L080816E0: .4byte gUnk_083272F8
.L080816E4: .4byte gUnk_08327304
.L080816E8: .4byte gUnk_0832730C
.L080816EC:
	ldr r0, .L08081714 @ =gBg0Tm+0x164
	movs r1, #0xd
	movs r2, #5
	movs r3, #0
	bl TmFillRect_thm
	ldr r0, .L08081718 @ =gBg1Tm+0x122
	movs r1, #0xc
	movs r2, #6
	movs r3, #0
	bl TmFillRect_thm
.L08081704:
	movs r0, #3
	bl EnableBgSync
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08081714: .4byte gBg0Tm+0x164
.L08081718: .4byte gBg1Tm+0x122

	thumb_func_start func_fe6_0808171C
func_fe6_0808171C: @ 0x0808171C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r5, r0, #0
	bl ResetTextFont
	bl ClearIcons
	ldr r3, .L0808193C @ =gDispIo
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
	strb r1, [r3, #0x14]
	movs r0, #3
	ldrb r1, [r3, #0x18]
	orrs r0, r1
	strb r0, [r3, #0x18]
	ldr r0, .L08081940 @ =gBg0Tm
	movs r1, #0
	bl TmFill
	ldr r0, .L08081944 @ =gBg1Tm
	movs r1, #0
	bl TmFill
	ldr r0, .L08081948 @ =gBg2Tm
	movs r1, #0
	bl TmFill
	bl ApplySystemObjectsGraphics
	bl InitIcons
	movs r0, #4
	bl ApplyIconPalettes
	ldr r0, .L0808194C @ =0x02015688
	movs r1, #6
	bl InitText
	movs r4, #0
	ldr r6, .L08081950 @ =0x020155E8
.L0808178C:
	lsls r0, r4, #3
	adds r0, r0, r6
	movs r1, #7
	bl InitTextDb
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #7
	bls .L0808178C
	movs r4, #0
	adds r7, r5, #0
	adds r7, #0x2f
	adds r2, r5, #0
	adds r2, #0x2e
	str r2, [sp, #0x18]
	movs r3, #0x30
	adds r3, r3, r5
	mov sl, r3
	movs r0, #0x31
	adds r0, r0, r5
	mov r8, r0
	movs r1, #0x45
	adds r1, r1, r5
	mov sb, r1
	adds r2, #0x22
	str r2, [sp, #4]
	adds r3, r5, #0
	adds r3, #0x2c
	str r3, [sp, #0x10]
	adds r0, r5, #0
	adds r0, #0x52
	str r0, [sp, #8]
	adds r1, r5, #0
	adds r1, #0x29
	str r1, [sp, #0xc]
	subs r2, #0x23
	str r2, [sp, #0x14]
	ldr r6, .L08081954 @ =0x02015638
.L080817DA:
	lsls r0, r4, #3
	adds r0, r0, r6
	movs r1, #7
	bl InitText
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls .L080817DA
	ldr r0, [r5, #0x14]
	ldr r1, [r0, #0x48]
	str r1, [r5, #0x54]
	ldr r0, [r0, #0x4c]
	str r0, [r5, #0x58]
	adds r0, r5, #0
	movs r2, #0x10
	movs r3, #0xb
	bl StartEquipInfoWindow
	movs r4, #0
	strb r4, [r7]
	ldr r3, [sp, #0x18]
	strb r4, [r3]
	mov r0, sl
	strb r4, [r0]
	mov r1, r8
	strb r4, [r1]
	mov r2, sb
	strb r4, [r2]
	movs r0, #0
	ldr r3, [sp, #4]
	strh r4, [r3]
	ldr r1, [sp, #0x10]
	strb r0, [r1]
	ldr r2, [sp, #8]
	strh r4, [r2]
	ldr r3, [sp, #0xc]
	strb r0, [r3]
	ldr r1, [sp, #0x14]
	strb r0, [r1]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	bl UnpackUiWindowFrameGraphics
	str r4, [sp]
	movs r0, #0x10
	movs r1, #0xb
	movs r2, #0xe
	movs r3, #8
	bl PutUiWindowFrame
	adds r0, r5, #0
	bl func_fe6_0808165C
	str r4, [sp]
	movs r0, #1
	movs r1, #8
	movs r2, #0xe
	movs r3, #0xc
	bl PutUiWindowFrame
	ldr r0, [r5, #0x54]
	bl GetUnitFid
	adds r1, r0, #0
	movs r3, #4
	rsbs r3, r3, #0
	movs r0, #3
	str r0, [sp]
	movs r0, #0
	movs r2, #0x40
	bl StartFace
	ldr r1, [r5, #0x54]
	movs r0, #0
	bl func_fe6_0807D6C0
	ldrb r2, [r7]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	ldr r3, [sp, #0x18]
	ldrb r3, [r3]
	lsls r1, r3, #1
	adds r1, #9
	movs r2, #0xc
	bl PutUiEntryHover
	ldr r0, [r5, #0x54]
	ldr r0, [r0]
	ldrh r0, [r0]
	bl DecodeMsg
	bl GetStringTextLen
	movs r4, #0x30
	subs r4, r4, r0
	lsrs r0, r4, #0x1f
	adds r4, r4, r0
	asrs r4, r4, #1
	ldr r0, [r5, #0x54]
	ldr r0, [r0]
	ldrh r0, [r0]
	bl DecodeMsg
	ldr r2, .L0808194C @ =0x02015688
	ldr r1, .L08081940 @ =gBg0Tm
	str r0, [sp]
	adds r0, r2, #0
	movs r2, #0
	adds r3, r4, #0
	bl func_fe6_08082360
	ldr r0, .L08081958 @ =gUnk_083198CC
	ldr r1, .L0808195C @ =0x06017200
	bl Decompress
	ldr r0, .L08081960 @ =gUnk_08319E88
	movs r1, #0x90
	lsls r1, r1, #2
	movs r2, #0x60
	bl ApplyPaletteExt
	ldr r0, .L08081964 @ =gUnk_0831AB1C
	ldr r1, .L08081968 @ =0x06011000
	bl Decompress
	ldr r0, .L0808196C @ =gUnk_0831AABC
	movs r1, #0xc0
	lsls r1, r1, #2
	movs r2, #0x20
	bl ApplyPaletteExt
	movs r0, #7
	bl EnableBgSync
	adds r0, r5, #0
	bl func_fe6_08081ED4
	movs r4, #1
	rsbs r4, r4, #0
	movs r0, #0
	adds r1, r4, #0
	bl func_fe6_08070E70
	adds r0, r5, #0
	adds r1, r4, #0
	bl func_fe6_080829E8
	adds r0, r5, #0
	movs r1, #0
	bl Proc_Goto
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0808193C: .4byte gDispIo
.L08081940: .4byte gBg0Tm
.L08081944: .4byte gBg1Tm
.L08081948: .4byte gBg2Tm
.L0808194C: .4byte 0x02015688
.L08081950: .4byte 0x020155E8
.L08081954: .4byte 0x02015638
.L08081958: .4byte gUnk_083198CC
.L0808195C: .4byte 0x06017200
.L08081960: .4byte gUnk_08319E88
.L08081964: .4byte gUnk_0831AB1C
.L08081968: .4byte 0x06011000
.L0808196C: .4byte gUnk_0831AABC

	thumb_func_start func_fe6_08081970
func_fe6_08081970: @ 0x08081970
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	str r0, [sp]
	adds r4, r7, #0
	adds r4, #0x29
	ldrb r0, [r4]
	cmp r0, #0
	beq .L080819AC
	ldr r0, .L080819A8 @ =gKeySt
	ldr r1, [r0]
	movs r0, #0x81
	lsls r0, r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L080819AC
	bl CloseHelpBox
	movs r0, #0
	strb r0, [r4]
	b .L08081DDC
	.align 2, 0
.L080819A8: .4byte gKeySt
.L080819AC:
	adds r0, r7, #0
	adds r0, #0x2c
	ldrb r4, [r0]
	adds r6, r0, #0
	cmp r4, #0
	beq .L080819C0
	cmp r4, #1
	bne .L080819BE
	b .L08081C20
.L080819BE:
	b .L08081C84
.L080819C0:
	ldr r2, .L08081A00 @ =gKeySt
	ldr r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	movs r1, #0x29
	adds r1, r1, r7
	mov sb, r1
	mov sl, r2
	cmp r0, #0
	beq .L08081A04
	ldrb r0, [r1]
	cmp r0, #0
	bne .L08081A04
	movs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x2e
	ldrb r2, [r0]
	lsls r1, r2, #4
	adds r1, #0x48
	ldr r0, [r7, #0x54]
	lsls r2, r2, #1
	adds r0, #0x1c
	adds r0, r0, r2
	ldrh r2, [r0]
	movs r0, #0x10
	bl StartItemHelpBox
	b .L08081DB2
	.align 2, 0
.L08081A00: .4byte gKeySt
.L08081A04:
	mov r2, sl
	ldr r1, [r2]
	movs r0, #0x40
	ldrh r1, [r1, #6]
	ands r0, r1
	cmp r0, #0
	beq .L08081A8C
	ldr r0, [r7, #0x54]
	bl GetUnitItemCount
	cmp r0, #1
	ble .L08081A8C
	adds r5, r7, #0
	adds r5, #0x2f
	ldrb r3, [r5]
	lsls r0, r3, #3
	subs r0, r0, r3
	lsls r0, r0, #1
	adds r0, #2
	adds r4, r7, #0
	adds r4, #0x2e
	ldrb r2, [r4]
	lsls r1, r2, #1
	adds r1, #9
	movs r2, #0xc
	bl RemoveUiEntryHover
	ldrb r0, [r4]
	mov r8, r4
	cmp r0, #0
	beq .L08081A60
	ldr r0, .L08081A5C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08081A52
	movs r0, #0x66
	bl m4aSongNumStart
.L08081A52:
	mov r3, r8
	ldrb r0, [r3]
	subs r0, #1
	b .L08081AFE
	.align 2, 0
.L08081A5C: .4byte gPlaySt
.L08081A60:
	mov r0, sl
	ldr r1, [r0]
	movs r0, #0x40
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L08081B3A
	ldr r0, .L08081A88 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08081A7E
	movs r0, #0x66
	bl m4aSongNumStart
.L08081A7E:
	ldr r0, [r7, #0x54]
	bl GetUnitItemCount
	subs r0, #1
	b .L08081B30
	.align 2, 0
.L08081A88: .4byte gPlaySt
.L08081A8C:
	ldr r0, .L08081B08 @ =gKeySt
	ldr r1, [r0]
	movs r0, #0x80
	ldrh r1, [r1, #6]
	ands r0, r1
	cmp r0, #0
	beq .L08081B5C
	ldr r0, [r7, #0x54]
	bl GetUnitItemCount
	cmp r0, #1
	ble .L08081B5C
	adds r6, r7, #0
	adds r6, #0x2f
	ldrb r0, [r6]
	lsls r1, r0, #2
	adds r0, r7, #0
	adds r0, #0x54
	adds r0, r0, r1
	ldr r0, [r0]
	bl GetUnitItemCount
	adds r4, r0, #0
	subs r4, #1
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldrb r1, [r6]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, #2
	adds r5, r7, #0
	adds r5, #0x2e
	ldrb r2, [r5]
	lsls r1, r2, #1
	adds r1, #9
	movs r2, #0xc
	bl RemoveUiEntryHover
	ldrb r0, [r5]
	mov r8, r5
	adds r5, r6, #0
	cmp r0, r4
	bhs .L08081B10
	cmp r0, #3
	bhi .L08081B10
	ldr r0, .L08081B0C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08081AF8
	movs r0, #0x66
	bl m4aSongNumStart
.L08081AF8:
	mov r3, r8
	ldrb r0, [r3]
	adds r0, #1
.L08081AFE:
	strb r0, [r3]
	adds r0, r7, #0
	bl func_fe6_0808165C
	b .L08081B3A
	.align 2, 0
.L08081B08: .4byte gKeySt
.L08081B0C: .4byte gPlaySt
.L08081B10:
	ldr r0, .L08081B54 @ =gKeySt
	ldr r1, [r0]
	movs r0, #0x80
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L08081B3A
	ldr r0, .L08081B58 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08081B2E
	movs r0, #0x66
	bl m4aSongNumStart
.L08081B2E:
	movs r0, #0
.L08081B30:
	mov r1, r8
	strb r0, [r1]
	adds r0, r7, #0
	bl func_fe6_0808165C
.L08081B3A:
	ldrb r2, [r5]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	mov r3, r8
	ldrb r3, [r3]
	lsls r1, r3, #1
	adds r1, #9
	movs r2, #0xc
	bl PutUiEntryHover
	b .L08081DB2
	.align 2, 0
.L08081B54: .4byte gKeySt
.L08081B58: .4byte gPlaySt
.L08081B5C:
	ldr r0, .L08081BA4 @ =gKeySt
	ldr r0, [r0]
	ldrh r1, [r0, #8]
	movs r5, #1
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L08081BF0
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, #0
	beq .L08081B76
	b .L08081DBA
.L08081B76:
	ldr r0, [r7, #0x54]
	adds r4, r7, #0
	adds r4, #0x2e
	ldrb r2, [r4]
	lsls r1, r2, #1
	adds r0, #0x1c
	adds r0, r0, r1
	ldrh r0, [r0]
	bl GetItemAttributes
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0
	beq .L08081BAC
	ldrb r4, [r4]
	lsls r1, r4, #4
	adds r1, #0x48
	ldr r2, .L08081BA8 @ =0x00000C33
	movs r0, #0x10
	adds r3, r7, #0
	bl func_fe6_08082B00
	b .L08081DB2
	.align 2, 0
.L08081BA4: .4byte gKeySt
.L08081BA8: .4byte 0x00000C33
.L08081BAC:
	ldr r0, .L08081BE8 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08081BBC
	movs r0, #0x6a
	bl m4aSongNumStart
.L08081BBC:
	ldr r0, .L08081BEC @ =0x02015638
	movs r1, #1
	bl func_fe6_0808166C
	adds r1, r7, #0
	adds r1, #0x2f
	ldrb r3, [r1]
	lsls r0, r3, #3
	subs r0, r0, r3
	lsls r0, r0, #1
	adds r0, #2
	ldrb r4, [r4]
	lsls r1, r4, #1
	adds r1, #9
	movs r2, #0xc
	bl RemoveUiEntryHover
	adds r0, r7, #0
	adds r0, #0x30
	strb r5, [r0]
	strb r5, [r6]
	b .L08081DB2
	.align 2, 0
.L08081BE8: .4byte gPlaySt
.L08081BEC: .4byte 0x02015638
.L08081BF0:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne .L08081BFA
	b .L08081DB2
.L08081BFA:
	ldr r0, .L08081C1C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08081C0A
	movs r0, #0x6b
	bl m4aSongNumStart
.L08081C0A:
	adds r0, r7, #0
	movs r1, #1
	bl func_fe6_080829E8
	adds r0, r7, #0
	movs r1, #1
	bl Proc_Goto
	b .L08081DB2
	.align 2, 0
.L08081C1C: .4byte gPlaySt
.L08081C20:
	ldr r2, .L08081C50 @ =gKeySt
	ldr r1, [r2]
	movs r0, #0x10
	ldrh r1, [r1, #6]
	ands r0, r1
	mov sl, r2
	cmp r0, #0
	beq .L08081C58
	adds r5, r7, #0
	adds r5, #0x30
	ldrb r0, [r5]
	cmp r0, #0
	bne .L08081C58
	ldr r0, .L08081C54 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08081C4A
	movs r0, #0x66
	bl m4aSongNumStart
.L08081C4A:
	strb r4, [r5]
	b .L08081C84
	.align 2, 0
.L08081C50: .4byte gKeySt
.L08081C54: .4byte gPlaySt
.L08081C58:
	mov r2, sl
	ldr r1, [r2]
	movs r0, #0x20
	ldrh r1, [r1, #6]
	ands r0, r1
	cmp r0, #0
	beq .L08081C90
	adds r4, r7, #0
	adds r4, #0x30
	ldrb r3, [r4]
	cmp r3, #1
	bne .L08081C90
	ldr r0, .L08081C8C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08081C80
	movs r0, #0x66
	bl m4aSongNumStart
.L08081C80:
	movs r0, #0
	strb r0, [r4]
.L08081C84:
	movs r0, #0x29
	adds r0, r0, r7
	mov sb, r0
	b .L08081DB2
	.align 2, 0
.L08081C8C: .4byte gPlaySt
.L08081C90:
	mov r2, sl
	ldr r1, [r2]
	movs r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L08081D60
	ldr r0, .L08081CF8 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08081CAE
	movs r0, #0x6a
	bl m4aSongNumStart
.L08081CAE:
	adds r0, r7, #0
	adds r0, #0x30
	ldrb r0, [r0]
	mov r8, r0
	cmp r0, #0
	bne .L08081D54
	ldr r0, [r7, #0x54]
	adds r5, r7, #0
	adds r5, #0x2e
	ldrb r1, [r5]
	bl UnitRemoveItem
	ldr r0, [r7, #0x54]
	bl UnitRemoveInvalidItems
	ldr r1, [r7, #0x54]
	movs r0, #0
	bl func_fe6_0807D6C0
	ldr r0, [r7, #0x54]
	bl GetUnitItemCount
	cmp r0, #0
	bne .L08081CFC
	adds r0, r7, #0
	movs r1, #1
	bl func_fe6_080829E8
	adds r0, r7, #0
	movs r1, #1
	bl Proc_Goto
	movs r3, #0x29
	adds r3, r3, r7
	mov sb, r3
	b .L08081DB2
	.align 2, 0
.L08081CF8: .4byte gPlaySt
.L08081CFC:
	ldrb r4, [r5]
	ldr r0, [r7, #0x54]
	bl GetUnitItemCount
	cmp r4, r0
	blt .L08081D3E
	adds r4, r7, #0
	adds r4, #0x2f
	ldrb r1, [r4]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #1
	adds r0, #2
	ldrb r2, [r5]
	lsls r1, r2, #1
	adds r1, #9
	movs r2, #0xc
	bl RemoveUiEntryHover
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	ldrb r3, [r4]
	lsls r0, r3, #3
	subs r0, r0, r3
	lsls r0, r0, #1
	adds r0, #2
	ldrb r5, [r5]
	lsls r1, r5, #1
	adds r1, #9
	movs r2, #0xc
	bl PutUiEntryHover
.L08081D3E:
	adds r0, r7, #0
	bl func_fe6_0808165C
	ldr r0, .L08081D50 @ =0x02015638
	movs r1, #0
	bl func_fe6_0808166C
	mov r0, r8
	b .L08081D5E
	.align 2, 0
.L08081D50: .4byte 0x02015638
.L08081D54:
	ldr r0, .L08081DEC @ =0x02015638
	movs r1, #0
	bl func_fe6_0808166C
	movs r0, #0
.L08081D5E:
	strb r0, [r6]
.L08081D60:
	ldr r0, .L08081DF0 @ =gKeySt
	ldr r1, [r0]
	movs r0, #2
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L08081D8A
	ldr r0, .L08081DF4 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08081D7E
	movs r0, #0x6b
	bl m4aSongNumStart
.L08081D7E:
	ldr r0, .L08081DEC @ =0x02015638
	movs r1, #0
	bl func_fe6_0808166C
	movs r0, #0
	strb r0, [r6]
.L08081D8A:
	ldrb r0, [r6]
	movs r1, #0x29
	adds r1, r1, r7
	mov sb, r1
	cmp r0, #0
	bne .L08081DB2
	adds r1, r7, #0
	adds r1, #0x2f
	ldrb r2, [r1]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, #2
	subs r1, #1
	ldrb r1, [r1]
	lsls r1, r1, #1
	adds r1, #9
	movs r2, #0xc
	bl PutUiEntryHover
.L08081DB2:
	mov r3, sb
	ldrb r0, [r3]
	cmp r0, #0
	beq .L08081DDC
.L08081DBA:
	adds r0, r7, #0
	adds r0, #0x2e
	ldr r1, [sp]
	ldrb r2, [r0]
	cmp r1, r2
	beq .L08081DDC
	ldrb r2, [r0]
	lsls r1, r2, #4
	adds r1, #0x48
	ldr r0, [r7, #0x54]
	lsls r2, r2, #1
	adds r0, #0x1c
	adds r0, r0, r2
	ldrh r2, [r0]
	movs r0, #0x10
	bl StartItemHelpBox
.L08081DDC:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08081DEC: .4byte 0x02015638
.L08081DF0: .4byte gKeySt
.L08081DF4: .4byte gPlaySt

	thumb_func_start func_fe6_08081DF8
func_fe6_08081DF8: @ 0x08081DF8
	push {lr}
	movs r0, #0
	bl EndFaceById
	ldr r0, .L08081E30 @ =gBg0Tm
	movs r1, #0
	bl TmFill
	ldr r0, .L08081E34 @ =gBg1Tm
	movs r1, #0
	bl TmFill
	ldr r0, .L08081E38 @ =gBg2Tm
	movs r1, #0
	bl TmFill
	movs r0, #7
	bl EnableBgSync
	bl ResetTextFont
	bl ClearIcons
	bl InitBmBgLayers
	pop {r0}
	bx r0
	.align 2, 0
.L08081E30: .4byte gBg0Tm
.L08081E34: .4byte gBg1Tm
.L08081E38: .4byte gBg2Tm

	thumb_func_start func_fe6_08081E3C
func_fe6_08081E3C: @ 0x08081E3C
	push {lr}
	adds r1, r0, #0
	ldr r0, .L08081E4C @ =gUnk_08679518
	bl SpawnProcLocking
	pop {r0}
	bx r0
	.align 2, 0
.L08081E4C: .4byte gUnk_08679518

	thumb_func_start func_fe6_08081E50
func_fe6_08081E50: @ 0x08081E50
	adds r0, #0x52
	movs r1, #0
	strh r1, [r0]
	bx lr

	thumb_func_start func_fe6_08081E58
func_fe6_08081E58: @ 0x08081E58
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r0, #0x52
	ldrh r2, [r0]
	movs r0, #1
	movs r1, #4
	bl func_fe6_0807CFB8
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r3, .L08081EAC @ =gUnk_086792B6
	movs r0, #0xe4
	lsls r0, r0, #2
	str r0, [sp]
	movs r0, #0xb
	movs r2, #0
	bl PutSpriteExt
	ldr r1, [r4, #0x14]
	adds r0, r1, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	cmp r0, #1
	bne .L08081EB0
	adds r0, r1, #0
	adds r0, #0x30
	ldrb r0, [r0]
	lsls r0, r0, #5
	adds r0, #0x9c
	movs r1, #0x40
	bl PutUiHand
	ldr r0, [r4, #0x14]
	adds r0, #0x2e
	ldrb r0, [r0]
	lsls r1, r0, #4
	adds r1, #0x48
	movs r0, #0x10
	bl PutFrozenUiHand
	b .L08081EC0
	.align 2, 0
.L08081EAC: .4byte gUnk_086792B6
.L08081EB0:
	adds r0, r1, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	lsls r1, r0, #4
	adds r1, #0x48
	movs r0, #0x10
	bl PutUiHand
.L08081EC0:
	adds r1, r4, #0
	adds r1, #0x52
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08081ED4
func_fe6_08081ED4: @ 0x08081ED4
	push {lr}
	adds r1, r0, #0
	ldr r0, .L08081EE4 @ =gUnk_08679558
	bl SpawnProc
	pop {r1}
	bx r1
	.align 2, 0
.L08081EE4: .4byte gUnk_08679558

	thumb_func_start func_fe6_08081EE8
func_fe6_08081EE8: @ 0x08081EE8
	adds r3, r0, #0
	adds r0, #0x2a
	movs r1, #0
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r2, #0
	strh r1, [r3, #0x2e]
	strh r1, [r3, #0x32]
	adds r0, #8
	strb r2, [r0]
	ldrh r0, [r3, #0x2e]
	strh r0, [r3, #0x30]
	movs r0, #0xe4
	lsls r0, r0, #2
	strh r0, [r3, #0x36]
	movs r0, #0x80
	lsls r0, r0, #5
	strh r0, [r3, #0x38]
	adds r0, r3, #0
	adds r0, #0x3a
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_08081F20
func_fe6_08081F20: @ 0x08081F20
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	adds r6, r0, #0
	adds r0, #0x34
	ldrh r1, [r6, #0x32]
	ldrb r0, [r0]
	cmp r1, r0
	bhi .L08081F3A
	b .L080822EC
.L08081F3A:
	movs r4, #0
	adds r0, r6, #0
	adds r0, #0x2c
	ldrb r2, [r0]
	lsrs r1, r2, #2
	str r0, [sp, #0x10]
	adds r3, r6, #0
	adds r3, #0x3a
	str r3, [sp, #0x18]
	adds r5, r6, #0
	adds r5, #0x3b
	str r5, [sp, #0x1c]
	cmp r4, r1
	bhs .L08081F84
.L08081F56:
	adds r0, r6, #0
	adds r0, #0x2a
	ldrb r1, [r0]
	adds r0, #1
	lsls r2, r4, #5
	ldrb r0, [r0]
	adds r2, r0, r2
	ldrh r7, [r6, #0x38]
	ldrh r3, [r6, #0x36]
	adds r0, r7, r3
	str r0, [sp]
	movs r0, #4
	ldr r3, .L080821E4 @ =gUnk_08679588
	bl PutSpriteExt
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r5, [sp, #0x10]
	ldrb r5, [r5]
	lsrs r0, r5, #2
	cmp r4, r0
	blo .L08081F56
.L08081F84:
	movs r7, #0
	lsls r1, r4, #2
	ldr r2, [sp, #0x10]
	ldrb r2, [r2]
	subs r0, r2, r1
	asrs r0, r0, #1
	adds r5, r1, #0
	cmp r7, r0
	bge .L08081FCE
.L08081F96:
	adds r0, r6, #0
	adds r0, #0x2a
	ldrb r1, [r0]
	adds r0, #1
	lsls r2, r7, #4
	ldrb r0, [r0]
	adds r2, r0, r2
	lsls r0, r4, #5
	adds r2, r2, r0
	mov r8, r2
	ldrh r3, [r6, #0x38]
	ldrh r2, [r6, #0x36]
	adds r0, r3, r2
	str r0, [sp]
	movs r0, #4
	mov r2, r8
	ldr r3, .L080821E8 @ =gUnk_08679580
	bl PutSpriteExt
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r3, [sp, #0x10]
	ldrb r3, [r3]
	subs r0, r3, r5
	asrs r0, r0, #1
	cmp r7, r0
	blt .L08081F96
.L08081FCE:
	movs r0, #0
	mov sb, r0
	lsls r1, r7, #1
	adds r0, r5, r1
	ldr r2, [sp, #0x10]
	ldrb r2, [r2]
	subs r0, r2, r0
	mov r8, r1
	adds r3, r4, r7
	mov sl, r3
	cmp sb, r0
	bge .L0808202A
.L08081FE6:
	adds r0, r6, #0
	adds r0, #0x2a
	ldrb r1, [r0]
	adds r0, #1
	mov r3, sb
	lsls r2, r3, #3
	ldrb r0, [r0]
	adds r2, r0, r2
	lsls r0, r7, #4
	adds r2, r2, r0
	lsls r0, r4, #5
	adds r2, r2, r0
	mov ip, r2
	ldrh r2, [r6, #0x38]
	ldrh r3, [r6, #0x36]
	adds r0, r2, r3
	str r0, [sp]
	movs r0, #4
	mov r2, ip
	ldr r3, .L080821EC @ =gUnk_08679578
	bl PutSpriteExt
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	mov r1, r8
	adds r0, r5, r1
	ldr r2, [sp, #0x10]
	ldrb r2, [r2]
	subs r0, r2, r0
	cmp sb, r0
	blt .L08081FE6
.L0808202A:
	mov r0, sl
	add r0, sb
	cmp r0, #0
	bgt .L08082034
	b .L0808229A
.L08082034:
	ldr r3, [sp, #0x10]
	ldrb r3, [r3]
	lsls r4, r3, #0x13
	ldrh r5, [r6, #0x2e]
	mov r8, r5
	ldrh r5, [r6, #0x32]
	adds r0, r6, #0
	adds r0, #0x34
	ldrb r7, [r0]
	str r0, [sp, #0x14]
	subs r0, #0xa
	str r0, [sp, #8]
	adds r1, r6, #0
	adds r1, #0x2b
	str r1, [sp, #0xc]
	cmp r5, r7
	bhi .L08082058
	b .L08082260
.L08082058:
	adds r0, r4, #0
	adds r1, r5, #0
	bl __udivsi3
	mov sb, r0
	adds r0, r4, #0
	muls r0, r7, r0
	adds r1, r5, #0
	bl __udivsi3
	adds r7, r0, #0
	mov r2, r8
	cmp r2, #0
	beq .L080820A2
	ldr r3, [sp, #8]
	ldrb r1, [r3]
	adds r1, #1
	movs r0, #0x80
	lsls r0, r0, #6
	orrs r1, r0
	ldr r4, [sp, #0xc]
	ldrb r2, [r4]
	subs r2, #8
	ldr r3, .L080821F0 @ =gUnk_08679654
	ldr r5, [sp, #0x18]
	ldrb r5, [r5]
	lsrs r0, r5, #3
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r3, [r0]
	ldrh r4, [r6, #0x38]
	ldrh r5, [r6, #0x36]
	adds r0, r4, r5
	str r0, [sp]
	movs r0, #4
	bl PutSpriteExt
.L080820A2:
	movs r4, #0
	lsrs r0, r7, #0x15
	str r0, [sp, #0x2c]
	mov r2, r8
	mov r1, sb
	muls r1, r2, r1
	str r1, [sp, #0x24]
	lsrs r7, r7, #0x10
	mov sl, r7
	cmp r4, r0
	bhs .L080820E4
.L080820B8:
	ldr r3, [sp, #8]
	ldrb r1, [r3]
	ldr r5, [sp, #0x24]
	lsrs r2, r5, #0x14
	ldr r7, [sp, #0xc]
	ldrb r7, [r7]
	adds r2, r7, r2
	lsls r0, r4, #5
	adds r2, r2, r0
	ldr r0, .L080821F4 @ =gUnk_086795F8
	ldr r3, [r0, #0x28]
	ldrh r5, [r6, #0x38]
	ldrh r7, [r6, #0x36]
	adds r0, r5, r7
	str r0, [sp]
	movs r0, #4
	bl PutSpriteExt
	adds r4, #1
	ldr r0, [sp, #0x2c]
	cmp r4, r0
	blo .L080820B8
.L080820E4:
	movs r7, #0
	lsls r5, r4, #5
	mov r1, sl
	subs r0, r1, r5
	lsrs r0, r0, #4
	str r5, [sp, #0x20]
	cmp r7, r0
	bhs .L08082132
.L080820F4:
	ldr r2, [sp, #8]
	ldrb r1, [r2]
	ldr r3, [sp, #0x24]
	lsrs r2, r3, #0x14
	ldr r4, [sp, #0xc]
	ldrb r4, [r4]
	adds r2, r4, r2
	mov r8, r5
	adds r2, r2, r5
	lsls r0, r7, #4
	adds r2, r2, r0
	ldr r0, .L080821F4 @ =gUnk_086795F8
	ldr r0, [r0, #0x24]
	mov sb, r0
	ldrh r3, [r6, #0x38]
	ldrh r4, [r6, #0x36]
	adds r0, r3, r4
	str r0, [sp]
	movs r0, #4
	mov r3, sb
	bl PutSpriteExt
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	mov r0, sl
	mov r1, r8
	subs r4, r0, r1
	lsrs r4, r4, #4
	cmp r7, r4
	blo .L080820F4
.L08082132:
	movs r2, #0
	mov sb, r2
	ldr r3, [sp, #0x20]
	mov r8, r3
	mov r4, sl
	subs r0, r4, r3
	lsls r7, r7, #4
	subs r0, r0, r7
	lsrs r0, r0, #3
	str r7, [sp, #4]
	cmp sb, r0
	bhs .L08082194
.L0808214A:
	ldr r5, [sp, #8]
	ldrb r1, [r5]
	ldr r0, [sp, #0x24]
	lsrs r2, r0, #0x14
	ldr r3, [sp, #0xc]
	ldrb r3, [r3]
	adds r2, r3, r2
	mov r4, r8
	str r4, [sp, #0x28]
	add r2, r8
	str r7, [sp, #0x2c]
	adds r2, r2, r7
	mov r5, sb
	lsls r0, r5, #3
	adds r2, r2, r0
	ldr r0, .L080821F4 @ =gUnk_086795F8
	ldr r3, [r0, #0x20]
	ldrh r4, [r6, #0x38]
	ldrh r5, [r6, #0x36]
	adds r0, r4, r5
	str r0, [sp]
	movs r0, #4
	bl PutSpriteExt
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	mov r0, sl
	ldr r1, [sp, #0x28]
	subs r4, r0, r1
	ldr r2, [sp, #0x2c]
	subs r4, r4, r2
	lsrs r4, r4, #3
	cmp sb, r4
	blo .L0808214A
.L08082194:
	ldrh r3, [r6, #0x2e]
	lsrs r0, r3, #4
	ldr r4, [sp, #0x14]
	ldrb r4, [r4]
	adds r0, r4, r0
	ldrh r5, [r6, #0x32]
	cmp r0, r5
	bne .L080821F8
	ldr r7, [sp, #8]
	ldrb r1, [r7]
	ldr r0, [sp, #0x24]
	lsrs r4, r0, #0x14
	ldr r3, [sp, #0xc]
	ldrb r3, [r3]
	adds r2, r3, r4
	ldr r5, [sp, #0x20]
	ldr r7, [sp, #4]
	adds r3, r5, r7
	mov r5, sb
	lsls r0, r5, #3
	adds r3, r3, r0
	adds r2, r2, r3
	ldr r7, .L080821F4 @ =gUnk_086795F8
	mov r8, r7
	ldr r5, [sp, #0x10]
	ldrb r5, [r5]
	lsls r0, r5, #3
	adds r4, r4, r3
	subs r0, r0, r4
	lsls r0, r0, #2
	add r0, r8
	ldr r3, [r0]
	ldrh r7, [r6, #0x38]
	ldrh r4, [r6, #0x36]
	adds r0, r7, r4
	str r0, [sp]
	movs r0, #4
	bl PutSpriteExt
	b .L08082260
	.align 2, 0
.L080821E4: .4byte gUnk_08679588
.L080821E8: .4byte gUnk_08679580
.L080821EC: .4byte gUnk_08679578
.L080821F0: .4byte gUnk_08679654
.L080821F4: .4byte gUnk_086795F8
.L080821F8:
	ldr r5, [sp, #8]
	ldrb r1, [r5]
	ldr r7, [sp, #0x24]
	lsrs r2, r7, #0x14
	ldr r0, [sp, #0xc]
	ldrb r0, [r0]
	adds r2, r0, r2
	ldr r3, [sp, #0x20]
	ldr r4, [sp, #4]
	adds r0, r3, r4
	mov r5, sb
	lsls r3, r5, #3
	adds r0, r0, r3
	adds r2, r2, r0
	ldr r3, .L080822FC @ =gUnk_086795F8
	movs r0, #7
	mov r7, sl
	ands r7, r0
	lsls r0, r7, #2
	adds r0, r0, r3
	ldr r3, [r0]
	ldrh r4, [r6, #0x38]
	ldrh r5, [r6, #0x36]
	adds r0, r4, r5
	str r0, [sp]
	movs r0, #4
	bl PutSpriteExt
	ldr r7, [sp, #8]
	ldrb r1, [r7]
	adds r1, #1
	ldr r0, [sp, #0x10]
	ldrb r0, [r0]
	lsls r2, r0, #3
	ldr r3, [sp, #0xc]
	ldrb r3, [r3]
	adds r2, r3, r2
	adds r2, #1
	ldr r3, .L08082300 @ =gUnk_08679654
	ldr r4, [sp, #0x1c]
	ldrb r4, [r4]
	lsrs r0, r4, #3
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r3, [r0]
	ldrh r5, [r6, #0x38]
	ldrh r7, [r6, #0x36]
	adds r0, r5, r7
	str r0, [sp]
	movs r0, #4
	bl PutSpriteExt
.L08082260:
	ldr r0, [sp, #8]
	ldrb r1, [r0]
	ldr r3, [sp, #0xc]
	ldrb r2, [r3]
	subs r2, #8
	ldr r3, .L08082304 @ =gUnk_08679590
	ldrh r4, [r6, #0x38]
	ldrh r5, [r6, #0x36]
	adds r0, r4, r5
	str r0, [sp]
	movs r0, #4
	bl PutSpriteExt
	ldr r7, [sp, #8]
	ldrb r1, [r7]
	ldr r0, [sp, #0x10]
	ldrb r0, [r0]
	lsls r2, r0, #3
	ldr r3, [sp, #0xc]
	ldrb r3, [r3]
	adds r2, r3, r2
	ldr r3, .L08082308 @ =gUnk_08679598
	ldrh r4, [r6, #0x38]
	ldrh r5, [r6, #0x36]
	adds r0, r4, r5
	str r0, [sp]
	movs r0, #4
	bl PutSpriteExt
.L0808229A:
	ldrh r1, [r6, #0x30]
	ldrh r0, [r6, #0x2e]
	cmp r1, r0
	beq .L080822C2
	cmp r1, r0
	bls .L080822AE
	ldr r7, [sp, #0x18]
	ldrb r0, [r7]
	adds r0, #1
	strb r0, [r7]
.L080822AE:
	ldrh r0, [r6, #0x30]
	ldrh r1, [r6, #0x2e]
	cmp r0, r1
	bhs .L080822BE
	ldr r2, [sp, #0x1c]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
.L080822BE:
	ldrh r0, [r6, #0x2e]
	strh r0, [r6, #0x30]
.L080822C2:
	ldr r3, [sp, #0x18]
	ldrb r0, [r3]
	adds r0, #1
	movs r1, #0
	strb r0, [r3]
	ldr r4, [sp, #0x1c]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldrb r5, [r3]
	lsrs r0, r5, #3
	cmp r0, #5
	bls .L080822DE
	strb r1, [r3]
.L080822DE:
	ldr r7, [sp, #0x1c]
	ldrb r7, [r7]
	lsrs r0, r7, #3
	cmp r0, #5
	bls .L080822EC
	ldr r0, [sp, #0x1c]
	strb r1, [r0]
.L080822EC:
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080822FC: .4byte gUnk_086795F8
.L08082300: .4byte gUnk_08679654
.L08082304: .4byte gUnk_08679590
.L08082308: .4byte gUnk_08679598

	thumb_func_start func_fe6_0808230C
func_fe6_0808230C: @ 0x0808230C
	push {lr}
	adds r1, r0, #0
	ldr r0, .L0808231C @ =gUnk_0867966C
	bl SpawnProc
	pop {r1}
	bx r1
	.align 2, 0
.L0808231C: .4byte gUnk_0867966C

	thumb_func_start func_fe6_08082320
func_fe6_08082320: @ 0x08082320
	push {r4, r5, r6, lr}
	mov ip, r0
	ldr r4, [sp, #0x10]
	ldr r5, [sp, #0x14]
	ldr r6, [sp, #0x18]
	adds r0, #0x2a
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r3, [r0]
	mov r0, ip
	strh r4, [r0, #0x2e]
	strh r5, [r0, #0x32]
	adds r0, #0x34
	strb r6, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08082348
func_fe6_08082348: @ 0x08082348
	adds r3, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	cmp r1, #0
	bge .L08082354
	adds r1, #0x1f
.L08082354:
	asrs r0, r1, #5
	strh r0, [r3, #0x36]
	lsls r0, r2, #0xc
	strh r0, [r3, #0x38]
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_08082360
func_fe6_08082360: @ 0x08082360
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	mov r8, r1
	adds r5, r2, #0
	adds r6, r3, #0
	ldr r7, [sp, #0x18]
	bl ClearText
	adds r0, r4, #0
	adds r1, r5, #0
	bl Text_SetColor
	adds r0, r4, #0
	adds r1, r6, #0
	bl Text_SetCursor
	adds r0, r4, #0
	adds r1, r7, #0
	bl Text_DrawString
	adds r0, r4, #0
	mov r1, r8
	bl PutText
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080823A0
func_fe6_080823A0: @ 0x080823A0
	push {r4, lr}
	adds r3, r0, #0
	ldr r4, .L080823B4 @ =0x0201636A
	ldrh r0, [r4]
	adds r2, r0, #0
	cmp r2, #0
	bne .L080823B8
	strb r2, [r3]
	strh r2, [r1]
	b .L080823EC
	.align 2, 0
.L080823B4: .4byte 0x0201636A
.L080823B8:
	cmp r2, #7
	bhi .L080823CA
	ldrb r4, [r3]
	cmp r4, r2
	blo .L080823C6
	subs r0, #1
	strb r0, [r3]
.L080823C6:
	movs r0, #0
	b .L080823EA
.L080823CA:
	ldrh r2, [r1]
	lsrs r0, r2, #4
	adds r2, r0, #7
	ldrh r0, [r4]
	cmp r2, r0
	bge .L080823E2
	ldrb r4, [r3]
	cmp r4, #6
	bne .L080823EC
	movs r0, #5
	strb r0, [r3]
	b .L080823EC
.L080823E2:
	cmp r2, r0
	ble .L080823EC
	subs r0, #7
	lsls r0, r0, #4
.L080823EA:
	strh r0, [r1]
.L080823EC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080823F4
func_fe6_080823F4: @ 0x080823F4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldr r4, .L0808248C @ =gBg3Tm
	adds r0, r4, #0
	movs r1, #0
	bl TmFill
	ldr r0, .L08082490 @ =gUnk_08320436
	mov sb, r0
	movs r0, #0
	movs r1, #0x2c
	adds r1, r1, r7
	mov sl, r1
	mov ip, r4
	movs r3, #0x27
	mov r8, r3
	movs r1, #0xa0
	lsls r1, r1, #8
	adds r4, r1, #0
.L08082422:
	movs r2, #0
	adds r6, r0, #1
	lsls r5, r0, #6
	mov r3, r8
	subs r1, r3, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	mov r1, sb
	adds r3, r0, r1
.L08082436:
	lsls r0, r2, #1
	adds r1, r5, r0
	add r1, ip
	adds r0, r0, r3
	ldrh r0, [r0]
	adds r0, r4, r0
	strh r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0x1d
	bls .L08082436
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls .L08082422
	movs r0, #8
	bl EnableBgSync
	movs r6, #0
	movs r5, #0
	strh r5, [r7, #0x2a]
	movs r4, #0xff
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	ldr r0, .L08082494 @ =0x0400001E
	ldrh r3, [r7, #0x2a]
	ands r4, r3
	strh r4, [r0]
	mov r0, sl
	strb r6, [r0]
	strh r5, [r7, #0x2a]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0808248C: .4byte gBg3Tm
.L08082490: .4byte gUnk_08320436
.L08082494: .4byte 0x0400001E

	thumb_func_start func_fe6_08082498
func_fe6_08082498: @ 0x08082498
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x2c
	ldrb r0, [r6]
	cmp r0, #3
	bne .L080824D6
	ldrh r0, [r5, #0x2a]
	adds r0, #1
	strh r0, [r5, #0x2a]
	lsls r0, r0, #0x10
	movs r1, #0xa0
	lsls r1, r1, #0x13
	cmp r0, r1
	bne .L080824BA
	movs r0, #0
	strh r0, [r5, #0x2a]
.L080824BA:
	movs r4, #0xff
	adds r2, r4, #0
	ldrh r1, [r5, #0x2a]
	ands r2, r1
	movs r0, #3
	movs r1, #0
	bl SetBgOffset
	ldr r0, .L0808254C @ =0x0400001E
	ldrh r1, [r5, #0x2a]
	ands r4, r1
	strh r4, [r0]
	movs r0, #0
	strb r0, [r6]
.L080824D6:
	adds r1, r5, #0
	adds r1, #0x2c
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldrh r1, [r5, #0x2a]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne .L08082544
	ldr r5, .L08082550 @ =gUnk_08320436
	lsrs r0, r1, #3
	subs r4, r0, #1
	movs r1, #0x1f
	ands r4, r1
	adds r0, #0x1e
	movs r1, #0x28
	bl __modsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r2, #0
	ldr r1, .L08082554 @ =gBg3Tm
	mov ip, r1
	lsls r4, r4, #6
	mov r7, ip
	movs r1, #0x27
	subs r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r3, r0, r5
	movs r0, #0xa0
	lsls r0, r0, #8
	adds r6, r0, #0
	adds r5, r4, #0
.L0808251E:
	lsls r0, r2, #1
	adds r1, r4, r0
	adds r1, r1, r7
	adds r0, r0, r3
	ldrh r0, [r0]
	adds r0, r6, r0
	strh r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0x1d
	bls .L0808251E
	mov r1, ip
	adds r0, r5, r1
	ldr r1, .L08082558 @ =0x06007800
	adds r1, r5, r1
	movs r2, #0xf
	bl CpuFastSet
.L08082544:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0808254C: .4byte 0x0400001E
.L08082550: .4byte gUnk_08320436
.L08082554: .4byte gBg3Tm
.L08082558: .4byte 0x06007800

	thumb_func_start func_fe6_0808255C
func_fe6_0808255C: @ 0x0808255C
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_08082560
func_fe6_08082560: @ 0x08082560
	push {lr}
	ldr r0, .L08082570 @ =gUnk_0867968C
	movs r1, #0
	bl SpawnProc
	pop {r1}
	bx r1
	.align 2, 0
.L08082570: .4byte gUnk_0867968C

	thumb_func_start func_fe6_08082574
func_fe6_08082574: @ 0x08082574
	ldr r0, .L0808258C @ =0x04000006
	ldrh r0, [r0]
	adds r3, r0, #0
	cmp r3, #0xa0
	bne .L08082594
	movs r3, #0
	ldr r0, .L08082590 @ =0x0201686C
	ldr r2, [r0]
	ldr r1, [r0, #4]
	str r1, [r0]
	str r2, [r0, #4]
	b .L0808259C
	.align 2, 0
.L0808258C: .4byte 0x04000006
.L08082590: .4byte 0x0201686C
.L08082594:
	ldr r0, .L080825B0 @ =0x0201686C
	cmp r3, #0xa0
	bls .L0808259C
	movs r3, #0
.L0808259C:
	ldr r2, .L080825B4 @ =0x04000042
	ldr r0, [r0]
	lsls r1, r3, #2
	adds r1, r1, r0
	ldrb r3, [r1]
	lsls r0, r3, #8
	ldrb r1, [r1, #1]
	orrs r0, r1
	strh r0, [r2]
	bx lr
	.align 2, 0
.L080825B0: .4byte 0x0201686C
.L080825B4: .4byte 0x04000042

	thumb_func_start func_fe6_080825B8
func_fe6_080825B8: @ 0x080825B8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	ldr r2, .L08082634 @ =gDispIo
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrb r1, [r2, #1]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r2, #1]
	adds r0, r4, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov ip, r2
	cmp r0, #0
	bge .L08082644
	movs r0, #0x96
	str r0, [r4, #0x2c]
	movs r3, #0
	ldr r0, .L08082638 @ =0x0201636C
	mov sb, r0
	adds r4, #0x29
	mov r8, r4
	ldr r1, .L0808263C @ =0x0201686C
	mov sl, r1
	mov r7, sb
	movs r4, #0
	movs r2, #0xf0
	movs r6, #0xa0
	lsls r6, r6, #2
	ldr r5, .L08082640 @ =0x00000281
.L08082606:
	lsls r0, r3, #2
	adds r0, r0, r7
	strb r4, [r0]
	strb r2, [r0, #1]
	adds r1, r0, r6
	strb r4, [r1]
	adds r0, r0, r5
	strb r2, [r0]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0x9f
	bls .L08082606
	mov r1, ip
	adds r1, #0x2f
	movs r0, #0
	strb r0, [r1]
	adds r1, #4
	strb r0, [r1]
	subs r1, #5
	movs r0, #0xf0
	b .L0808268C
	.align 2, 0
.L08082634: .4byte gDispIo
.L08082638: .4byte 0x0201636C
.L0808263C: .4byte 0x0201686C
.L08082640: .4byte 0x00000281
.L08082644:
	movs r0, #0
	str r0, [r4, #0x2c]
	movs r3, #0
	ldr r0, .L080826F8 @ =0x0201636C
	mov sb, r0
	adds r4, #0x29
	mov r8, r4
	ldr r1, .L080826FC @ =0x0201686C
	mov sl, r1
	mov r6, sb
	movs r2, #0x78
	movs r5, #0xa0
	lsls r5, r5, #2
	ldr r4, .L08082700 @ =0x00000281
.L08082660:
	lsls r0, r3, #2
	adds r0, r0, r6
	strb r2, [r0]
	strb r2, [r0, #1]
	adds r1, r0, r5
	strb r2, [r1]
	adds r0, r0, r4
	strb r2, [r0]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0x9f
	bls .L08082660
	mov r2, ip
	adds r2, #0x2f
	movs r1, #0
	movs r0, #0x78
	strb r0, [r2]
	adds r2, #4
	strb r1, [r2]
	mov r1, ip
	adds r1, #0x2e
.L0808268C:
	strb r0, [r1]
	adds r1, #4
	movs r0, #0xa0
	strb r0, [r1]
	mov r2, ip
	adds r2, #0x35
	movs r0, #1
	ldrb r1, [r2]
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	movs r1, #8
	orrs r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	adds r2, #1
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #2
	ands r0, r1
	subs r1, #4
	ands r0, r1
	subs r1, #8
	ands r0, r1
	strb r0, [r2]
	movs r0, #0
	mov r1, r8
	strb r0, [r1]
	mov r0, sb
	mov r1, sl
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #2
	add r0, sb
	str r0, [r1, #4]
	ldr r0, .L08082704 @ =func_fe6_08082574
	bl SetOnHBlankA
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080826F8: .4byte 0x0201636C
.L080826FC: .4byte 0x0201686C
.L08082700: .4byte 0x00000281
.L08082704: .4byte func_fe6_08082574

	thumb_func_start func_fe6_08082708
func_fe6_08082708: @ 0x08082708
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	adds r0, #0x2a
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldr r0, [r6, #0x2c]
	adds r0, r0, r1
	str r0, [r6, #0x2c]
	cmp r0, #0x96
	ble .L08082726
	movs r0, #0x96
	str r0, [r6, #0x2c]
.L08082726:
	ldr r0, [r6, #0x2c]
	cmp r0, #0
	bge .L08082730
	movs r0, #0
	str r0, [r6, #0x2c]
.L08082730:
	movs r1, #0
	movs r0, #0x29
	adds r0, r0, r6
	mov sb, r0
	ldr r7, .L08082770 @ =0x0201686C
	movs r2, #0x78
	mov r8, r2
.L0808273E:
	ldr r0, [r6, #0x2c]
	lsls r5, r1, #0x10
	cmp r0, #0
	ble .L0808275E
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	asrs r4, r5, #0x10
	adds r1, r4, #0
	subs r1, #0x50
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	subs r0, r0, r1
	cmp r0, #0
	bge .L08082774
.L0808275E:
	ldr r0, [r7, #4]
	asrs r1, r5, #0xe
	adds r0, r1, r0
	mov r4, r8
	strb r4, [r0]
	ldr r0, [r7, #4]
	adds r1, r1, r0
	strb r4, [r1, #1]
	b .L0808279A
	.align 2, 0
.L08082770: .4byte 0x0201686C
.L08082774:
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x78
	ble .L08082784
	movs r3, #0x78
.L08082784:
	ldr r1, [r7, #4]
	lsls r2, r4, #2
	adds r1, r2, r1
	mov r4, r8
	subs r0, r4, r3
	strb r0, [r1]
	ldr r0, [r7, #4]
	adds r2, r2, r0
	adds r0, r3, #0
	adds r0, #0x78
	strb r0, [r2, #1]
.L0808279A:
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r5, r1
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x9f
	ble .L0808273E
	mov r2, sb
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x28
	bne .L080827BE
	adds r0, r6, #0
	bl Proc_Break
.L080827BE:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080827CC
func_fe6_080827CC: @ 0x080827CC
	push {lr}
	movs r0, #0
	bl SetOnHBlankA
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080827D8
func_fe6_080827D8: @ 0x080827D8
	push {r4, lr}
	adds r2, r0, #0
	lsls r4, r1, #0x18
	lsrs r4, r4, #0x18
	ldr r0, .L080827F4 @ =gUnk_086796C4
	adds r1, r2, #0
	bl SpawnProcLocking
	adds r1, r0, #0
	adds r1, #0x2a
	strb r4, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L080827F4: .4byte gUnk_086796C4

	thumb_func_start func_fe6_080827F8
func_fe6_080827F8: @ 0x080827F8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r1, r0, #0
	adds r1, #0x29
	movs r7, #0
	strb r7, [r1]
	ldr r1, .L08082890 @ =gDispIo
	mov ip, r1
	movs r3, #1
	ldrb r1, [r1, #1]
	orrs r1, r3
	movs r2, #2
	mov r8, r2
	mov r2, r8
	orrs r1, r2
	movs r6, #4
	orrs r1, r6
	movs r5, #8
	orrs r1, r5
	movs r4, #0x10
	orrs r1, r4
	movs r2, #0x21
	rsbs r2, r2, #0
	ands r1, r2
	movs r2, #0x40
	orrs r1, r2
	movs r2, #0x7f
	ands r1, r2
	mov r2, ip
	strb r1, [r2, #1]
	mov r1, ip
	adds r1, #0x35
	ldrb r2, [r1]
	orrs r3, r2
	mov r2, r8
	orrs r3, r2
	orrs r3, r6
	orrs r3, r5
	orrs r3, r4
	strb r3, [r1]
	mov r3, ip
	adds r3, #0x36
	movs r1, #2
	rsbs r1, r1, #0
	ldrb r2, [r3]
	ands r1, r2
	movs r2, #3
	rsbs r2, r2, #0
	ands r1, r2
	subs r2, #2
	ands r1, r2
	subs r2, #4
	ands r1, r2
	subs r2, #8
	ands r1, r2
	strb r1, [r3]
	adds r0, #0x2a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble .L08082894
	mov r0, ip
	adds r0, #0x2f
	strb r7, [r0]
	adds r0, #4
	strb r7, [r0]
	mov r1, ip
	adds r1, #0x2e
	movs r0, #0xf0
	strb r0, [r1]
	adds r1, #4
	movs r0, #0xa0
	strb r0, [r1]
	b .L080828AE
	.align 2, 0
.L08082890: .4byte gDispIo
.L08082894:
	mov r1, ip
	adds r1, #0x2f
	movs r0, #0x78
	strb r0, [r1]
	mov r2, ip
	adds r2, #0x33
	movs r1, #0x50
	strb r1, [r2]
	subs r2, #5
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x32
	strb r1, [r0]
.L080828AE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080828B8
func_fe6_080828B8: @ 0x080828B8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	adds r2, r7, #0
	adds r2, #0x29
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldr r5, .L0808293C @ =gDispIo
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrb r1, [r5, #1]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r5, #1]
	ldrb r1, [r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r4, r0, #8
	lsls r0, r0, #7
	muls r0, r1, r0
	movs r1, #0xf
	bl __divsi3
	subs r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xf
	bl __divsi3
	asrs r6, r0, #4
	adds r0, r7, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r4, r5, #0
	cmp r0, #0
	ble .L08082940
	lsls r1, r6, #1
	adds r2, r1, r6
	adds r0, r4, #0
	adds r0, #0x2f
	strb r2, [r0]
	adds r0, #4
	strb r1, [r0]
	movs r3, #0x10
	rsbs r3, r3, #0
	adds r0, r3, #0
	subs r0, r0, r2
	adds r2, r4, #0
	adds r2, #0x2e
	strb r0, [r2]
	movs r2, #0x60
	rsbs r2, r2, #0
	adds r0, r2, #0
	subs r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x32
	strb r0, [r1]
	b .L08082964
	.align 2, 0
.L0808293C: .4byte gDispIo
.L08082940:
	lsls r2, r6, #1
	adds r1, r2, r6
	movs r0, #0x78
	subs r0, r0, r1
	adds r3, r4, #0
	adds r3, #0x2f
	strb r0, [r3]
	movs r0, #0x50
	subs r0, r0, r2
	adds r3, #4
	strb r0, [r3]
	adds r1, #0x78
	adds r0, r4, #0
	adds r0, #0x2e
	strb r1, [r0]
	adds r2, #0x50
	adds r0, #4
	strb r2, [r0]
.L08082964:
	adds r2, r4, #0
	adds r2, #0x35
	movs r0, #1
	ldrb r3, [r2]
	orrs r0, r3
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	movs r1, #8
	orrs r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2]
	adds r1, r4, #0
	adds r1, #0x36
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r2, [r1]
	ands r0, r2
	movs r3, #3
	rsbs r3, r3, #0
	mov sl, r3
	ands r0, r3
	movs r2, #5
	rsbs r2, r2, #0
	mov sb, r2
	ands r0, r2
	subs r3, #6
	mov r8, r3
	ands r0, r3
	movs r5, #0x11
	rsbs r5, r5, #0
	ands r0, r5
	strb r0, [r1]
	cmp r6, #0x27
	ble .L080829DA
	adds r0, r7, #0
	bl Proc_Break
	adds r0, r7, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble .L080829DA
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r1, [r4, #1]
	ands r0, r1
	mov r2, sl
	ands r0, r2
	mov r3, sb
	ands r0, r3
	mov r1, r8
	ands r0, r1
	ands r0, r5
	strb r0, [r4, #1]
.L080829DA:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080829E8
func_fe6_080829E8: @ 0x080829E8
	push {r4, lr}
	adds r2, r0, #0
	lsls r4, r1, #0x18
	lsrs r4, r4, #0x18
	ldr r0, .L08082A04 @ =gUnk_086796F4
	adds r1, r2, #0
	bl SpawnProcLocking
	adds r1, r0, #0
	adds r1, #0x2a
	strb r4, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L08082A04: .4byte gUnk_086796F4

	thumb_func_start func_fe6_08082A08
func_fe6_08082A08: @ 0x08082A08
	push {r4, lr}
	movs r4, #0
	bl GetSupplyItems
	adds r2, r0, #0
	movs r1, #0
	ldrh r0, [r2]
	cmp r0, #0
	beq .L08082A38
	movs r4, #1
.L08082A1C:
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x63
	bhi .L08082A38
	lsls r0, r1, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq .L08082A38
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	b .L08082A1C
.L08082A38:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_08082A40
func_fe6_08082A40: @ 0x08082A40
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2a]
	ldrh r1, [r4, #0x2c]
	cmp r0, r1
	bne .L08082A6C
	ldr r2, .L08082A78 @ =gDispIo
	movs r0, #1
	ldrb r1, [r2, #1]
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	movs r1, #4
	orrs r0, r1
	movs r1, #8
	orrs r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #1]
	adds r0, r4, #0
	bl Proc_Break
.L08082A6C:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08082A78: .4byte gDispIo

	thumb_func_start func_fe6_08082A7C
func_fe6_08082A7C: @ 0x08082A7C
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, .L08082AB4 @ =gUnk_0867971C
	bl SpawnProc
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r4, [r0, #0x2a]
	ldr r2, .L08082AB8 @ =gDispIo
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r1, [r2, #1]
	ands r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #2
	ands r0, r1
	subs r1, #4
	ands r0, r1
	subs r1, #8
	ands r0, r1
	strb r0, [r2, #1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08082AB4: .4byte gUnk_0867971C
.L08082AB8: .4byte gDispIo

	thumb_func_start func_fe6_08082ABC
func_fe6_08082ABC: @ 0x08082ABC
	adds r0, #0x28
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_08082AC8
func_fe6_08082AC8: @ 0x08082AC8
	adds r1, r0, #0
	adds r1, #0x28
	ldrb r0, [r1]
	cmp r0, #0
	beq .L08082AD6
	subs r0, #1
	strb r0, [r1]
.L08082AD6:
	bx lr

	thumb_func_start func_fe6_08082AD8
func_fe6_08082AD8: @ 0x08082AD8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L08082AFC @ =gKeySt
	ldr r1, [r0]
	movs r0, #0xf3
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L08082AF4
	bl CloseHelpBox
	adds r0, r4, #0
	bl Proc_Break
.L08082AF4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08082AFC: .4byte gKeySt

	thumb_func_start func_fe6_08082B00
func_fe6_08082B00: @ 0x08082B00
	push {r4, lr}
	adds r4, r3, #0
	bl StartHelpBox
	ldr r0, .L08082B18 @ =gUnk_0867973C
	adds r1, r4, #0
	bl SpawnProcLocking
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L08082B18: .4byte gUnk_0867973C

	thumb_func_start func_fe6_08082B1C
func_fe6_08082B1C: @ 0x08082B1C
	push {r4, lr}
	adds r4, r1, #0
	bl CanUnitUseWeapon
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08082B3C
	adds r0, r4, #0
	bl GetItemAttributes
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0
	bne .L08082B3C
	movs r0, #1
	b .L08082B3E
.L08082B3C:
	movs r0, #0
.L08082B3E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_08082B44
func_fe6_08082B44: @ 0x08082B44
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0
	movs r4, #0
.L08082B4C:
	lsls r1, r4, #1
	adds r0, r5, #0
	adds r0, #0x1c
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	bl func_fe6_08082B1C
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L08082B66
	adds r6, #1
.L08082B66:
	adds r4, #1
	cmp r4, #4
	ble .L08082B4C
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_08082B74
func_fe6_08082B74: @ 0x08082B74
	push {r4, lr}
	adds r4, r0, #0
	bl ArenaIsUnitAllowed
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08082B90
	adds r0, r4, #0
	bl func_fe6_08082B44
	cmp r0, #0
	beq .L08082B90
	movs r0, #1
	b .L08082B92
.L08082B90:
	movs r0, #0
.L08082B92:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_08082B98
func_fe6_08082B98: @ 0x08082B98
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r7, r1, #0
	adds r5, r2, #0
	adds r6, r3, #0
	cmp r4, r5
	beq .L08082C2A
	movs r0, #8
	ldrh r1, [r4, #0xc]
	ands r0, r1
	cmp r0, #0
	bne .L08082BE6
	lsls r1, r7, #1
	adds r0, r4, #0
	adds r0, #0x1c
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl func_fe6_08082B1C
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08082BE6
	adds r0, r4, #0
	bl func_fe6_08082B44
	cmp r0, #1
	bgt .L08082BE6
	lsls r1, r6, #1
	adds r0, r5, #0
	adds r0, #0x1c
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl func_fe6_08082B1C
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08082C26
.L08082BE6:
	movs r0, #8
	ldrh r1, [r5, #0xc]
	ands r0, r1
	cmp r0, #0
	bne .L08082C2A
	lsls r1, r6, #1
	adds r0, r5, #0
	adds r0, #0x1c
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	bl func_fe6_08082B1C
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08082C2A
	adds r0, r5, #0
	bl func_fe6_08082B44
	cmp r0, #1
	bgt .L08082C2A
	lsls r1, r7, #1
	adds r0, r4, #0
	adds r0, #0x1c
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	bl func_fe6_08082B1C
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08082C2A
.L08082C26:
	movs r0, #0
	b .L08082C2C
.L08082C2A:
	movs r0, #1
.L08082C2C:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08082C34
func_fe6_08082C34: @ 0x08082C34
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	movs r0, #8
	ldrh r2, [r4, #0xc]
	ands r0, r2
	cmp r0, #0
	bne .L08082C76
	lsls r1, r1, #1
	adds r0, r4, #0
	adds r0, #0x1c
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl func_fe6_08082B1C
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08082C76
	adds r0, r4, #0
	bl func_fe6_08082B44
	cmp r0, #1
	bne .L08082C76
	adds r0, r4, #0
	adds r1, r5, #0
	bl func_fe6_08082B1C
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08082C76
	movs r0, #0
	b .L08082C78
.L08082C76:
	movs r0, #1
.L08082C78:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08082C80
func_fe6_08082C80: @ 0x08082C80
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #8
	ldrh r2, [r4, #0xc]
	ands r0, r2
	cmp r0, #0
	bne .L08082CB2
	lsls r1, r1, #1
	adds r0, r4, #0
	adds r0, #0x1c
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl func_fe6_08082B1C
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08082CB2
	adds r0, r4, #0
	bl func_fe6_08082B44
	cmp r0, #1
	bne .L08082CB2
	movs r0, #0
	b .L08082CB4
.L08082CB2:
	movs r0, #1
.L08082CB4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08082CBC
func_fe6_08082CBC: @ 0x08082CBC
	push {r4, r5, lr}
	movs r1, #0
	ldr r4, .L08082CE8 @ =gPlaySt
	ldr r3, .L08082CEC @ =gUnk_08321F24
	ldr r2, .L08082CF0 @ =0x02016874
.L08082CC6:
	ldrb r5, [r4, #0x1d]
	lsls r0, r5, #0x1c
	lsrs r0, r0, #0x1e
	lsls r0, r0, #4
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r1, #1
	cmp r1, #0xf
	ble .L08082CC6
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08082CE8: .4byte gPlaySt
.L08082CEC: .4byte gUnk_08321F24
.L08082CF0: .4byte 0x02016874

	thumb_func_start func_fe6_08082CF4
func_fe6_08082CF4: @ 0x08082CF4
	push {lr}
	adds r1, r0, #0
	ldr r0, .L08082D04 @ =gUnk_08679774
	bl SpawnProc
	pop {r1}
	bx r1
	.align 2, 0
.L08082D04: .4byte gUnk_08679774

	thumb_func_start func_fe6_08082D08
func_fe6_08082D08: @ 0x08082D08
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	lsls r4, r2, #0x10
	lsrs r4, r4, #0x10
	ldr r1, .L08082D4C @ =0x06016000
	str r1, [r6, #0x2c]
	movs r5, #0xf
	ands r4, r5
	adds r4, #0x10
	adds r0, #0x30
	adds r2, r4, #0
	bl InitSpriteTextFont
	ldr r0, .L08082D50 @ =Pal_Text+0x20
	lsls r1, r4, #5
	movs r2, #0x20
	bl ApplyPaletteExt
	adds r0, r6, #0
	adds r0, #0x48
	bl InitSpriteText
	movs r0, #0
	bl SetTextFont
	ldrh r1, [r6, #0x2c]
	lsrs r0, r1, #5
	ands r4, r5
	lsls r4, r4, #0xc
	adds r0, r0, r4
	str r0, [r6, #0x50]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08082D4C: .4byte 0x06016000
.L08082D50: .4byte Pal_Text+0x20

	thumb_func_start func_fe6_08082D54
func_fe6_08082D54: @ 0x08082D54
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r0, #0x30
	bl SetTextFont
	adds r4, #0x48
	adds r0, r4, #0
	movs r1, #0
	bl SpriteText_DrawBackgroundExt
	movs r0, #1
	bl SetTextFontGlyphs
	adds r0, r4, #0
	movs r1, #0
	bl Text_SetColor
	adds r0, r4, #0
	movs r1, #0
	bl Text_SetCursor
	ldr r0, .L08082DA0 @ =gUnk_08679754
	lsls r5, r5, #2
	adds r5, r5, r0
	ldr r0, [r5]
	bl DecodeMsg
	adds r1, r0, #0
	adds r0, r4, #0
	bl Text_DrawString
	movs r0, #0
	bl SetTextFont
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08082DA0: .4byte gUnk_08679754

	thumb_func_start func_fe6_08082DA4
func_fe6_08082DA4: @ 0x08082DA4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r1, [sp, #4]
	adds r7, r2, #0
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov sl, r3
	str r0, [sp, #8]
	cmp r3, #0xf
	bls .L08082E56
	adds r2, #8
	adds r0, r3, #0
	asrs r0, r0, #5
	subs r7, r2, r0
	ldr r4, .L08082E68 @ =gSinLut
	movs r0, #0x80
	adds r0, r0, r4
	mov sb, r0
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #4
	movs r2, #0x80
	lsls r2, r2, #1
	mov r8, r2
	mov r1, r8
	bl Div
	adds r6, r0, #0
	lsls r6, r6, #0x10
	asrs r6, r6, #0x10
	movs r3, #0
	ldrsh r0, [r4, r3]
	rsbs r0, r0, #0
	lsls r0, r0, #4
	mov r1, sl
	bl Div
	adds r5, r0, #0
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	movs r1, #0
	ldrsh r0, [r4, r1]
	lsls r0, r0, #4
	mov r1, r8
	bl Div
	adds r4, r0, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	mov r2, sb
	movs r3, #0
	ldrsh r0, [r2, r3]
	lsls r0, r0, #4
	mov r1, sl
	bl Div
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	movs r0, #1
	adds r1, r6, #0
	adds r2, r5, #0
	adds r3, r4, #0
	bl SetObjAffine
	movs r5, #0
	ldr r6, .L08082E6C @ =0x000001FF
	ldr r4, [sp, #4]
.L08082E34:
	adds r1, r4, #0
	ands r1, r6
	lsls r2, r5, #2
	ldr r3, [sp, #8]
	ldr r0, [r3, #0x50]
	adds r0, r0, r2
	str r0, [sp]
	movs r0, #0xc
	adds r2, r7, #0
	ands r2, r6
	ldr r3, .L08082E70 @ =gUnk_0867976C
	bl PutSpriteExt
	adds r4, #0x20
	adds r5, #1
	cmp r5, #7
	ble .L08082E34
.L08082E56:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08082E68: .4byte gSinLut
.L08082E6C: .4byte 0x000001FF
.L08082E70: .4byte gUnk_0867976C

	thumb_func_start func_fe6_08082E74
func_fe6_08082E74: @ 0x08082E74
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r7, r1, #0
	ldr r0, .L08082EB0 @ =0x020168E8
	str r4, [r0]
	ldr r1, .L08082EB4 @ =0x020168EC
	movs r0, #1
	lsls r0, r4
	subs r0, #1
	str r0, [r1]
	ldr r6, .L08082EB8 @ =0x020168F0
	movs r0, #0x1c
	adds r1, r4, #0
	bl __divsi3
	adds r5, r0, #0
	str r5, [r6]
	movs r0, #0x1c
	adds r1, r4, #0
	bl __modsi3
	cmp r0, #0
	ble .L08082EA6
	adds r0, r5, #1
	str r0, [r6]
.L08082EA6:
	ldr r0, .L08082EBC @ =0x020168F4
	str r7, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08082EB0: .4byte 0x020168E8
.L08082EB4: .4byte 0x020168EC
.L08082EB8: .4byte 0x020168F0
.L08082EBC: .4byte 0x020168F4

	thumb_func_start func_fe6_08082EC0
func_fe6_08082EC0: @ 0x08082EC0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, .L08082EE8 @ =0x020168E8
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	bl __divsi3
	adds r6, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl __modsi3
	cmp r0, #0
	ble .L08082EE0
	adds r6, #1
.L08082EE0:
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
.L08082EE8: .4byte 0x020168E8

	thumb_func_start func_fe6_08082EEC
func_fe6_08082EEC: @ 0x08082EEC
	push {r4, r5, lr}
	ldr r5, .L08082F14 @ =0x02016920
	ldr r0, [r5]
	lsls r4, r0, #4
	adds r4, r4, r0
	lsls r4, r4, #0x13
	lsrs r4, r4, #0x10
	adds r0, r4, #0
	movs r1, #0x47
	bl __udivsi3
	adds r4, r4, r0
	adds r4, #3
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [r5]
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
.L08082F14: .4byte 0x02016920

	thumb_func_start func_fe6_08082F18
func_fe6_08082F18: @ 0x08082F18
	push {r4, r5, r6, lr}
	movs r4, #0
	ldr r1, .L08082F4C @ =0x020168F0
	ldr r0, [r1]
	cmp r4, r0
	bge .L08082F44
	ldr r6, .L08082F50 @ =0x02016924
	adds r5, r1, #0
.L08082F28:
	ldr r0, [r5]
	adds r0, r4, r0
	lsls r1, r4, #1
	adds r0, r0, r1
	adds r0, r0, r6
	ldrb r3, [r0]
	adds r2, r4, r6
	ldrb r1, [r2]
	strb r1, [r0]
	strb r3, [r2]
	adds r4, #1
	ldr r0, [r5]
	cmp r4, r0
	blt .L08082F28
.L08082F44:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08082F4C: .4byte 0x020168F0
.L08082F50: .4byte 0x02016924

	thumb_func_start func_fe6_08082F54
func_fe6_08082F54: @ 0x08082F54
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp]
	mov sl, r1
	mov r8, r2
	mov sb, r3
	bl func_fe6_08082EEC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r8, r0
	movs r0, #1
	mov r1, sb
	lsls r0, r1
	subs r0, #1
	mov r1, r8
	ands r1, r0
	mov r8, r1
	movs r2, #0
	cmp r2, sb
	bge .L08082FD4
.L08082F86:
	ldr r0, .L08082FE4 @ =0x020168E8
	mov r1, sl
	ldr r6, [r1]
	ldr r4, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	str r2, [sp, #4]
	bl __divsi3
	ldr r1, [sp]
	adds r7, r1, r0
	movs r5, #1
	ldr r2, [sp, #4]
	lsls r5, r2
	mov r0, r8
	ands r5, r0
	asrs r5, r2
	adds r0, r6, #0
	adds r1, r4, #0
	bl __modsi3
	adds r1, r0, #0
	ldr r2, [sp, #4]
	cmp r1, #0
	bge .L08082FBA
	adds r0, r1, #7
.L08082FBA:
	asrs r0, r0, #3
	lsls r0, r0, #3
	subs r0, r1, r0
	lsls r5, r0
	ldrb r1, [r7]
	orrs r5, r1
	strb r5, [r7]
	adds r0, r6, #1
	mov r1, sl
	str r0, [r1]
	adds r2, #1
	cmp r2, sb
	blt .L08082F86
.L08082FD4:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08082FE4: .4byte 0x020168E8

	thumb_func_start func_fe6_08082FE8
func_fe6_08082FE8: @ 0x08082FE8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	str r0, [sp]
	mov r8, r1
	mov sb, r2
	movs r0, #0
	mov sl, r0
	movs r7, #0
	cmp sl, sb
	bge .L0808304C
.L08083004:
	ldr r0, .L08083074 @ =0x020168E8
	mov r1, r8
	ldr r6, [r1]
	ldr r4, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl __divsi3
	ldr r2, [sp]
	adds r0, r2, r0
	ldrb r5, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl __modsi3
	adds r1, r0, #0
	cmp r1, #0
	bge .L0808302A
	adds r0, r1, #7
.L0808302A:
	asrs r0, r0, #3
	lsls r0, r0, #3
	subs r0, r1, r0
	movs r1, #1
	lsls r1, r0
	ands r5, r1
	asrs r5, r0
	lsls r5, r7
	mov r0, sl
	orrs r0, r5
	mov sl, r0
	adds r0, r6, #1
	mov r1, r8
	str r0, [r1]
	adds r7, #1
	cmp r7, sb
	blt .L08083004
.L0808304C:
	bl func_fe6_08082EEC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r2, sl
	subs r0, r2, r0
	movs r1, #1
	mov r2, sb
	lsls r1, r2
	subs r1, #1
	ands r0, r1
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
.L08083074: .4byte 0x020168E8

	thumb_func_start func_fe6_08083078
func_fe6_08083078: @ 0x08083078
	push {r4, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	movs r2, #0
	movs r1, #0
	cmp r2, r3
	bge .L08083098
.L08083086:
	adds r0, r4, r1
	adds r1, #1
	ldrb r0, [r0]
	muls r0, r1, r0
	adds r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r1, r3
	blt .L08083086
.L08083098:
	lsrs r0, r2, #9
	adds r0, r2, r0
	ldr r2, .L080830A8 @ =0x000001FF
	adds r1, r2, #0
	ands r0, r1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L080830A8: .4byte 0x000001FF

	thumb_func_start func_fe6_080830AC
func_fe6_080830AC: @ 0x080830AC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r6, #0
	ldr r0, .L080830E4 @ =0x020168F0
	ldr r0, [r0]
	ldr r5, .L080830E8 @ =0x02016924
	adds r0, r0, r5
	ldr r4, .L080830EC @ =0x020169C4
	ldrh r1, [r4, #6]
	bl func_fe6_08083078
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	adds r7, r5, #0
	mov r8, r4
.L080830D0:
	adds r0, r6, #0
	movs r1, #3
	bl __modsi3
	adds r5, r0, #0
	cmp r5, #0
	bne .L080830F0
	mov r0, r8
	ldrh r4, [r0]
	b .L08083108
	.align 2, 0
.L080830E4: .4byte 0x020168F0
.L080830E8: .4byte 0x02016924
.L080830EC: .4byte 0x020169C4
.L080830F0:
	cmp r5, #1
	bne .L08083104
	mov r0, r8
	ldrh r4, [r0, #2]
	adds r0, r6, #0
	movs r1, #3
	bl __divsi3
	adds r1, r5, #0
	b .L08083112
.L08083104:
	mov r0, r8
	ldrh r4, [r0, #4]
.L08083108:
	adds r0, r6, #0
	movs r1, #3
	bl __divsi3
	movs r1, #1
.L08083112:
	lsls r1, r0
	ands r4, r1
	asrs r4, r0
	ldr r5, .L08083170 @ =0x020168E8
	ldr r1, [r5]
	adds r0, r6, #0
	bl __modsi3
	lsls r4, r0
	ldrb r0, [r7]
	orrs r4, r0
	strb r4, [r7]
	adds r6, #1
	ldr r1, [r5]
	adds r0, r6, #0
	bl __modsi3
	cmp r0, #0
	bne .L0808313A
	adds r7, #1
.L0808313A:
	cmp r6, #0x1c
	bne .L080830D0
	movs r2, #0
	ldr r3, .L08083174 @ =0x020168F0
	ldr r0, [r3]
	cmp r2, r0
	bge .L08083160
	ldr r5, .L08083178 @ =0x02016924
	ldr r4, .L0808317C @ =0x020168EC
.L0808314C:
	adds r0, r2, r5
	ldrb r1, [r0]
	add r1, sb
	ldrb r6, [r4]
	ands r1, r6
	strb r1, [r0]
	adds r2, #1
	ldr r0, [r3]
	cmp r2, r0
	blt .L0808314C
.L08083160:
	bl func_fe6_08082F18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08083170: .4byte 0x020168E8
.L08083174: .4byte 0x020168F0
.L08083178: .4byte 0x02016924
.L0808317C: .4byte 0x020168EC

	thumb_func_start func_fe6_08083180
func_fe6_08083180: @ 0x08083180
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r0, #0
	mov sl, r0
	movs r7, #0
	bl func_fe6_08082F18
	ldr r4, .L08083218 @ =0x020168F0
	ldr r0, [r4]
	ldr r5, .L0808321C @ =0x02016924
	adds r0, r0, r5
	ldr r1, .L08083220 @ =0x020169C4
	ldrh r1, [r1, #6]
	bl func_fe6_08083078
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	movs r2, #0
	ldr r0, [r4]
	cmp sl, r0
	bge .L080831CA
	mov r8, r5
	ldr r5, .L08083224 @ =0x020168EC
.L080831B4:
	mov r1, r8
	adds r0, r2, r1
	ldrb r6, [r0]
	subs r1, r6, r3
	ldrb r6, [r5]
	ands r1, r6
	strb r1, [r0]
	adds r2, #1
	ldr r0, [r4]
	cmp r2, r0
	blt .L080831B4
.L080831CA:
	ldr r0, .L08083220 @ =0x020169C4
	movs r1, #0
	strh r1, [r0]
	strh r1, [r0, #2]
	strh r1, [r0, #4]
	ldr r1, .L0808321C @ =0x02016924
	ldr r2, .L08083228 @ =0x020168E8
	mov sb, r2
	mov r8, r0
	mov r0, sl
	adds r6, r0, r1
.L080831E0:
	adds r0, r7, #0
	movs r1, #3
	bl __modsi3
	adds r5, r0, #0
	cmp r5, #0
	bne .L0808322C
	ldrb r4, [r6]
	mov r2, sb
	ldr r1, [r2]
	adds r0, r7, #0
	bl __modsi3
	asrs r4, r0
	movs r0, #1
	ands r4, r0
	adds r0, r7, #0
	movs r1, #3
	bl __divsi3
	lsls r4, r0
	mov r0, r8
	ldrh r0, [r0]
	orrs r4, r0
	mov r1, r8
	strh r4, [r1]
	b .L0808327C
	.align 2, 0
.L08083218: .4byte 0x020168F0
.L0808321C: .4byte 0x02016924
.L08083220: .4byte 0x020169C4
.L08083224: .4byte 0x020168EC
.L08083228: .4byte 0x020168E8
.L0808322C:
	cmp r5, #1
	bne .L08083256
	ldrb r4, [r6]
	mov r2, sb
	ldr r1, [r2]
	adds r0, r7, #0
	bl __modsi3
	asrs r4, r0
	ands r4, r5
	adds r0, r7, #0
	movs r1, #3
	bl __divsi3
	lsls r4, r0
	mov r0, r8
	ldrh r0, [r0, #2]
	orrs r4, r0
	mov r1, r8
	strh r4, [r1, #2]
	b .L0808327C
.L08083256:
	ldrb r4, [r6]
	mov r2, sb
	ldr r1, [r2]
	adds r0, r7, #0
	bl __modsi3
	asrs r4, r0
	movs r0, #1
	ands r4, r0
	adds r0, r7, #0
	movs r1, #3
	bl __divsi3
	lsls r4, r0
	mov r0, r8
	ldrh r0, [r0, #4]
	orrs r4, r0
	mov r1, r8
	strh r4, [r1, #4]
.L0808327C:
	adds r7, #1
	mov r2, sb
	ldr r1, [r2]
	adds r0, r7, #0
	bl __modsi3
	cmp r0, #0
	bne .L0808328E
	adds r6, #1
.L0808328E:
	cmp r7, #0x1c
	bne .L080831E0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080832A0
func_fe6_080832A0: @ 0x080832A0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r3, r0, #0
	movs r0, #0
	str r0, [sp]
	ldr r6, .L0808335C @ =0x02016924
	ldr r5, .L08083360 @ =0x020168F0
	adds r2, r6, #0
	movs r1, #0
	adds r0, r6, #0
	adds r0, #0x9f
.L080832B6:
	strb r1, [r0]
	subs r0, #1
	cmp r0, r2
	bge .L080832B6
	ldr r1, [r5]
	adds r1, r1, r6
	mov r0, sp
	bl _call_via_r3
	ldr r0, [sp]
	bl func_fe6_08082EC0
	ldr r4, .L08083364 @ =0x020169C4
	strh r0, [r4, #6]
	ldr r0, [r5]
	adds r0, r0, r6
	ldrh r1, [r4, #6]
	bl func_fe6_08083078
	strh r0, [r4, #2]
	bl GetGameTime
	lsrs r0, r0, #3
	ldrh r1, [r4, #2]
	adds r0, r1, r0
	ldr r1, .L08083368 @ =0x000003FF
	ands r0, r1
	strh r0, [r4]
	ldr r1, .L0808336C @ =0x02016920
	ldrh r0, [r4]
	str r0, [r1]
	bl func_fe6_08082EEC
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	ldr r2, .L08083370 @ =0x000001FF
	adds r1, r2, #0
	ands r0, r1
	strh r0, [r4, #2]
	movs r5, #0
	ldrh r4, [r4, #6]
	cmp r5, r4
	bge .L08083330
	adds r4, r6, #0
.L0808330E:
	bl func_fe6_08082EEC
	ldr r1, .L08083360 @ =0x020168F0
	ldr r2, [r1]
	adds r2, r5, r2
	adds r2, r2, r4
	ldrb r1, [r2]
	adds r0, r1, r0
	ldr r1, .L08083374 @ =0x020168EC
	ldrb r1, [r1]
	ands r0, r1
	strb r0, [r2]
	adds r5, #1
	ldr r0, .L08083364 @ =0x020169C4
	ldrh r0, [r0, #6]
	cmp r5, r0
	blt .L0808330E
.L08083330:
	ldr r0, .L08083360 @ =0x020168F0
	ldr r0, [r0]
	ldr r1, .L0808335C @ =0x02016924
	adds r0, r0, r1
	ldr r5, .L08083364 @ =0x020169C4
	ldrh r1, [r5, #6]
	bl func_fe6_08083078
	adds r4, r0, #0
	bl func_fe6_08082EEC
	adds r4, r4, r0
	ldr r2, .L08083370 @ =0x000001FF
	adds r0, r2, #0
	ands r4, r0
	strh r4, [r5, #4]
	bl func_fe6_080830AC
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0808335C: .4byte 0x02016924
.L08083360: .4byte 0x020168F0
.L08083364: .4byte 0x020169C4
.L08083368: .4byte 0x000003FF
.L0808336C: .4byte 0x02016920
.L08083370: .4byte 0x000001FF
.L08083374: .4byte 0x020168EC

	thumb_func_start func_fe6_08083378
func_fe6_08083378: @ 0x08083378
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	mov sb, r0
	movs r0, #0
	str r0, [sp, #4]
	bl func_fe6_08083180
	ldr r1, .L08083424 @ =0x02016920
	ldr r4, .L08083428 @ =0x020169C4
	ldrh r0, [r4]
	str r0, [r1]
	ldr r0, .L0808342C @ =0x020168F0
	ldr r0, [r0]
	ldr r7, .L08083430 @ =0x02016924
	adds r0, r0, r7
	ldrh r1, [r4, #6]
	bl func_fe6_08083078
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	bl func_fe6_08082EEC
	mov r1, sp
	strh r0, [r1]
	movs r5, #0
	add r0, sp, #4
	mov r8, r0
	ldrh r4, [r4, #6]
	cmp r5, r4
	bge .L080833DE
	adds r4, r7, #0
.L080833BC:
	bl func_fe6_08082EEC
	ldr r1, .L0808342C @ =0x020168F0
	ldr r2, [r1]
	adds r2, r5, r2
	adds r2, r2, r4
	ldrb r1, [r2]
	subs r0, r1, r0
	ldr r1, .L08083434 @ =0x020168EC
	ldrb r1, [r1]
	ands r0, r1
	strb r0, [r2]
	adds r5, #1
	ldr r0, .L08083428 @ =0x020169C4
	ldrh r0, [r0, #6]
	cmp r5, r0
	blt .L080833BC
.L080833DE:
	bl func_fe6_08082EEC
	mov r1, sp
	strh r0, [r1, #2]
	ldr r5, .L0808342C @ =0x020168F0
	ldr r1, [r5]
	ldr r4, .L08083430 @ =0x02016924
	adds r1, r1, r4
	mov r0, r8
	bl _call_via_r9
	ldr r0, [r5]
	adds r0, r0, r4
	ldr r4, .L08083428 @ =0x020169C4
	ldrh r1, [r4, #6]
	bl func_fe6_08083078
	mov r1, sp
	ldrh r1, [r1]
	adds r0, r1, r0
	ldr r1, .L08083438 @ =0x000001FF
	adds r2, r1, #0
	ands r0, r2
	mov r1, sp
	ldrh r1, [r1, #2]
	adds r6, r6, r1
	ands r6, r2
	ldrh r1, [r4, #2]
	cmp r1, r0
	bne .L08083420
	ldrh r4, [r4, #4]
	cmp r4, r6
	beq .L0808343C
.L08083420:
	movs r0, #0
	b .L0808343E
	.align 2, 0
.L08083424: .4byte 0x02016920
.L08083428: .4byte 0x020169C4
.L0808342C: .4byte 0x020168F0
.L08083430: .4byte 0x02016924
.L08083434: .4byte 0x020168EC
.L08083438: .4byte 0x000001FF
.L0808343C:
	movs r0, #1
.L0808343E:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0808344C
func_fe6_0808344C: @ 0x0808344C
	adds r3, r0, #0
	movs r2, #0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	beq .L08083472
	ldrh r3, [r3]
.L0808345A:
	ldrh r0, [r1]
	cmp r0, r3
	bne .L08083466
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	b .L08083474
.L08083466:
	adds r1, #2
	adds r2, #1
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bne .L0808345A
.L08083472:
	ldr r0, .L08083478 @ =0x0000FFFF
.L08083474:
	bx lr
	.align 2, 0
.L08083478: .4byte 0x0000FFFF

	thumb_func_start func_fe6_0808347C
func_fe6_0808347C: @ 0x0808347C
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	adds r6, r1, #0
	movs r5, #0
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq .L080834A8
	adds r4, r2, #0
.L0808348E:
	adds r0, r4, #0
	adds r1, r6, #0
	bl func_fe6_0808344C
	ldr r1, .L080834B0 @ =0x02016924
	adds r1, r5, r1
	strb r0, [r1]
	adds r4, #2
	adds r5, #1
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bne .L0808348E
.L080834A8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080834B0: .4byte 0x02016924

	thumb_func_start func_fe6_080834B4
func_fe6_080834B4: @ 0x080834B4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r1, .L08083570 @ =0x02016920
	ldr r0, .L08083574 @ =0x020168F4
	ldr r0, [r0]
	str r0, [r1]
	ldr r6, .L08083578 @ =gUnk_030048C0
	ldrb r2, [r6, #0x11]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl func_fe6_08082F54
	bl func_fe6_0808F30C
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #0x10
	bl func_fe6_08082F54
	bl func_fe6_0808F470
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #0x10
	bl func_fe6_08082F54
	bl func_fe6_0808F4F0
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #7
	bl func_fe6_08082F54
	bl func_fe6_0808F59C
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #0xc
	bl func_fe6_08082F54
	bl func_fe6_08017104
	adds r2, r0, #0
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #0x18
	bl func_fe6_08082F54
	bl func_fe6_0808F648
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #0xc
	bl func_fe6_08082F54
	ldrb r2, [r6, #0xe]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #0xa
	bl func_fe6_08082F54
	ldrb r2, [r6, #0xf]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #6
	bl func_fe6_08082F54
	ldrb r2, [r6, #0x10]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #6
	bl func_fe6_08082F54
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08083570: .4byte 0x02016920
.L08083574: .4byte 0x020168F4
.L08083578: .4byte gUnk_030048C0

	thumb_func_start func_fe6_0808357C
func_fe6_0808357C: @ 0x0808357C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	ldr r1, .L0808360C @ =0x02016920
	ldr r0, .L08083610 @ =0x020168F4
	ldr r0, [r0]
	str r0, [r1]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #1
	bl func_fe6_08082FE8
	ldr r4, .L08083614 @ =gUnk_030048C0
	strb r0, [r4, #0x11]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0x10
	bl func_fe6_08082FE8
	strh r0, [r4]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0x10
	bl func_fe6_08082FE8
	strh r0, [r4, #2]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #7
	bl func_fe6_08082FE8
	strh r0, [r4, #4]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0xc
	bl func_fe6_08082FE8
	strh r0, [r4, #6]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0x18
	bl func_fe6_08082FE8
	str r0, [r4, #8]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0xc
	bl func_fe6_08082FE8
	strh r0, [r4, #0xc]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0xa
	bl func_fe6_08082FE8
	strb r0, [r4, #0xe]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #6
	bl func_fe6_08082FE8
	strb r0, [r4, #0xf]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #6
	bl func_fe6_08082FE8
	strb r0, [r4, #0x10]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0808360C: .4byte 0x02016920
.L08083610: .4byte 0x020168F4
.L08083614: .4byte gUnk_030048C0

	thumb_func_start func_fe6_08083618
func_fe6_08083618: @ 0x08083618
	push {r4, lr}
	sub sp, #0xc
	bl func_fe6_0808F30C
	ldr r4, .L08083654 @ =gUnk_030048C0
	strh r0, [r4]
	bl func_fe6_0808F470
	strh r0, [r4, #2]
	bl func_fe6_0808F4F0
	strh r0, [r4, #4]
	bl func_fe6_0808F59C
	strh r0, [r4, #6]
	bl func_fe6_08017104
	str r0, [r4, #8]
	bl func_fe6_0808F648
	strh r0, [r4, #0xc]
	ldr r1, .L08083658 @ =gPlaySt
	movs r0, #0x40
	ldrb r1, [r1, #0x14]
	ands r0, r1
	cmp r0, #0
	beq .L0808365C
	movs r0, #1
	b .L0808365E
	.align 2, 0
.L08083654: .4byte gUnk_030048C0
.L08083658: .4byte gPlaySt
.L0808365C:
	movs r0, #0
.L0808365E:
	strb r0, [r4, #0x11]
	bl func_fe6_0808EC1C
	add r2, sp, #4
	add r3, sp, #8
	mov r1, sp
	bl FormatTime
	ldr r1, .L08083684 @ =gUnk_030048C0
	ldr r0, [sp]
	strb r0, [r1, #0xe]
	ldr r0, [sp, #4]
	strb r0, [r1, #0xf]
	ldr r0, [sp, #8]
	strb r0, [r1, #0x10]
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08083684: .4byte gUnk_030048C0

	thumb_func_start func_fe6_08083688
func_fe6_08083688: @ 0x08083688
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	str r0, [sp, #0xc]
	mov r8, r1
	add r1, sp, #8
	movs r0, #0
	strb r0, [r1, #2]
	movs r0, #4
	bl EnableBgSync
	movs r0, #0
	str r0, [sp, #0x10]
	add r7, sp, #8
	movs r1, #0xe0
	lsls r1, r1, #1
	mov sl, r1
	mov sb, r0
	movs r6, #0
.L080836B4:
	ldr r2, [sp, #0xc]
	adds r0, r2, r6
	bl ClearText
	movs r5, #2
	bl InitTalkTextFont
	movs r4, #0
.L080836C4:
	mov r0, sb
	adds r2, r0, r4
	ldr r1, .L08083740 @ =0x020169C4
	ldr r0, .L08083744 @ =0x020168F0
	ldr r0, [r0]
	ldrh r1, [r1, #6]
	adds r0, r1, r0
	cmp r2, r0
	beq .L08083730
	ldr r1, .L08083748 @ =0x02016924
	adds r1, r2, r1
	ldrb r2, [r1]
	lsls r0, r2, #1
	add r0, r8
	ldrb r0, [r0]
	strb r0, [r7]
	ldrb r1, [r1]
	lsls r0, r1, #1
	add r0, r8
	ldrb r0, [r0, #1]
	strb r0, [r7, #1]
	movs r0, #0
	str r0, [sp]
	add r1, sp, #8
	str r1, [sp, #4]
	ldr r2, [sp, #0xc]
	adds r0, r2, r6
	ldr r1, .L0808374C @ =gBg2Tm+0x8
	add r1, sl
	movs r2, #1
	adds r3, r5, #0
	bl PutDrawText
	adds r5, #0xb
	adds r4, #1
	adds r0, r4, #0
	movs r1, #5
	bl __modsi3
	cmp r0, #0
	bne .L08083718
	adds r5, #0xb
.L08083718:
	cmp r4, #0xd
	ble .L080836C4
	movs r0, #0xc0
	add sl, r0
	movs r1, #0xe
	add sb, r1
	adds r6, #8
	ldr r2, [sp, #0x10]
	adds r2, #1
	str r2, [sp, #0x10]
	cmp r2, #2
	ble .L080836B4
.L08083730:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08083740: .4byte 0x020169C4
.L08083744: .4byte 0x020168F0
.L08083748: .4byte 0x02016924
.L0808374C: .4byte gBg2Tm+0x8

	thumb_func_start func_fe6_08083750
func_fe6_08083750: @ 0x08083750
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r5, r0, #0
	lsls r4, r5, #6
	ldr r0, .L080837C0 @ =gBg2Tm+0x4
	mov r8, r0
	adds r0, r4, r0
	ldr r6, .L080837C4 @ =gUnk_030048C0
	ldrh r2, [r6]
	movs r1, #2
	bl PutNumberOrBlank
	mov r0, r8
	adds r0, #8
	adds r0, r4, r0
	ldrh r2, [r6, #2]
	movs r1, #2
	bl PutNumberOrBlank
	mov r0, r8
	adds r0, #0x10
	adds r0, r4, r0
	ldrh r2, [r6, #4]
	movs r1, #2
	bl PutNumberOrBlank
	mov r0, r8
	adds r0, #0x18
	adds r0, r4, r0
	ldrh r2, [r6, #6]
	movs r1, #2
	bl PutNumberOrBlank
	movs r1, #0x28
	add r8, r1
	add r4, r8
	ldrh r2, [r6, #0xc]
	adds r0, r4, #0
	movs r1, #2
	bl PutNumberOrBlank
	adds r5, #2
	lsls r5, r5, #6
	add r5, r8
	ldr r2, [r6, #8]
	adds r0, r5, #0
	movs r1, #2
	bl PutNumberOrBlank
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080837C0: .4byte gBg2Tm+0x4
.L080837C4: .4byte gUnk_030048C0

	thumb_func_start func_fe6_080837C8
func_fe6_080837C8: @ 0x080837C8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0
	bl InitBgs
	bl ResetTextFont
	bl ResetText
	movs r0, #0
	strh r0, [r6, #0x2a]
	ldr r4, .L080838DC @ =gDispIo
	movs r2, #1
	ldrb r0, [r4, #1]
	orrs r0, r2
	movs r3, #2
	orrs r0, r3
	movs r1, #4
	orrs r0, r1
	movs r1, #8
	orrs r0, r1
	movs r1, #0x11
	rsbs r1, r1, #0
	ands r0, r1
	strb r0, [r4, #1]
	adds r1, #0xd
	adds r0, r1, #0
	ldrb r5, [r4, #0xc]
	ands r0, r5
	orrs r0, r2
	strb r0, [r4, #0xc]
	adds r0, r1, #0
	ldrb r2, [r4, #0x10]
	ands r0, r2
	orrs r0, r3
	strb r0, [r4, #0x10]
	ldrb r5, [r4, #0x14]
	ands r1, r5
	strb r1, [r4, #0x14]
	movs r0, #3
	ldrb r1, [r4, #0x18]
	orrs r0, r1
	strb r0, [r4, #0x18]
	bl UnpackUiWindowFrameGraphics
	bl EnablePalSync
	ldr r0, .L080838E0 @ =gBg0Tm
	movs r1, #0
	bl TmFill
	ldr r0, .L080838E4 @ =gBg1Tm
	movs r1, #0
	bl TmFill
	ldr r0, .L080838E8 @ =gBg2Tm
	movs r1, #0
	bl TmFill
	ldr r0, .L080838EC @ =gBg3Tm
	movs r1, #0
	bl TmFill
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrb r2, [r4, #1]
	ands r0, r2
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r4, #1]
	movs r0, #2
	str r0, [sp]
	movs r1, #6
	movs r2, #0x1a
	movs r3, #7
	bl PutUiWindowFrame
	movs r0, #0xf
	bl EnableBgSync
	ldr r5, .L080838F0 @ =0x020168F8
	movs r4, #2
.L0808389C:
	adds r0, r5, #0
	movs r1, #0x1b
	bl InitText
	adds r5, #8
	subs r4, #1
	cmp r4, #0
	bge .L0808389C
	bl func_fe6_08083618
	movs r0, #5
	movs r1, #0xb
	bl func_fe6_08082E74
	ldr r0, .L080838F4 @ =func_fe6_080834B4
	bl func_fe6_080832A0
	ldr r0, .L080838F0 @ =0x020168F8
	ldr r1, .L080838F8 @ =gUnk_0867978C
	bl func_fe6_08083688
	movs r0, #0
	movs r1, #0
	movs r2, #0xa
	bl StartMuralBackground
	str r0, [r6, #0x44]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080838DC: .4byte gDispIo
.L080838E0: .4byte gBg0Tm
.L080838E4: .4byte gBg1Tm
.L080838E8: .4byte gBg2Tm
.L080838EC: .4byte gBg3Tm
.L080838F0: .4byte 0x020168F8
.L080838F4: .4byte func_fe6_080834B4
.L080838F8: .4byte gUnk_0867978C

	thumb_func_start func_fe6_080838FC
func_fe6_080838FC: @ 0x080838FC
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_08083900
func_fe6_08083900: @ 0x08083900
	push {lr}
	ldr r0, [r0, #0x44]
	bl Proc_End
	ldr r2, .L0808392C @ =gDispIo
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r1, [r2, #1]
	ands r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #2
	ands r0, r1
	subs r1, #4
	ands r0, r1
	subs r1, #8
	ands r0, r1
	strb r0, [r2, #1]
	pop {r0}
	bx r0
	.align 2, 0
.L0808392C: .4byte gDispIo

	thumb_func_start func_fe6_08083930
func_fe6_08083930: @ 0x08083930
	push {lr}
	adds r1, r0, #0
	ldr r0, .L08083940 @ =gUnk_086797D0
	bl SpawnProcLocking
	pop {r1}
	bx r1
	.align 2, 0
.L08083940: .4byte gUnk_086797D0

	thumb_func_start func_fe6_08083944
func_fe6_08083944: @ 0x08083944
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	adds r7, r1, #0
	ldr r0, .L08083A54 @ =0x02016920
	ldr r1, .L08083A58 @ =0x020168F4
	ldr r1, [r1]
	str r1, [r0]
	ldr r0, .L08083A5C @ =0x0203D4A0
	mov sl, r0
	movs r1, #0
	mov sb, r1
	mov r6, sl
.L08083964:
	ldrb r2, [r6]
	adds r0, r7, #0
	mov r1, r8
	movs r3, #8
	bl func_fe6_08082F54
	ldrb r2, [r6, #1]
	adds r0, r7, #0
	mov r1, r8
	movs r3, #1
	bl func_fe6_08082F54
	ldrb r2, [r6, #2]
	adds r0, r7, #0
	mov r1, r8
	movs r3, #5
	bl func_fe6_08082F54
	ldrb r2, [r6, #3]
	adds r0, r7, #0
	mov r1, r8
	movs r3, #6
	bl func_fe6_08082F54
	ldrb r2, [r6, #4]
	adds r0, r7, #0
	mov r1, r8
	movs r3, #5
	bl func_fe6_08082F54
	ldrb r2, [r6, #5]
	adds r0, r7, #0
	mov r1, r8
	movs r3, #5
	bl func_fe6_08082F54
	ldrb r2, [r6, #6]
	adds r0, r7, #0
	mov r1, r8
	movs r3, #5
	bl func_fe6_08082F54
	ldrb r2, [r6, #7]
	adds r0, r7, #0
	mov r1, r8
	movs r3, #5
	bl func_fe6_08082F54
	ldrb r2, [r6, #8]
	adds r0, r7, #0
	mov r1, r8
	movs r3, #5
	bl func_fe6_08082F54
	ldrb r2, [r6, #9]
	adds r0, r7, #0
	mov r1, r8
	movs r3, #5
	bl func_fe6_08082F54
	ldrb r2, [r6, #0xa]
	adds r0, r7, #0
	mov r1, r8
	movs r3, #5
	bl func_fe6_08082F54
	mov r0, sl
	adds r0, #0xb
	mov r1, sb
	adds r4, r1, r0
	movs r5, #7
.L080839F2:
	ldrb r2, [r4]
	adds r0, r7, #0
	mov r1, r8
	movs r3, #3
	bl func_fe6_08082F54
	adds r4, #1
	subs r5, #1
	cmp r5, #0
	bge .L080839F2
	ldr r4, .L08083A60 @ =0x0203D4B3
	add r4, sb
	movs r5, #4
.L08083A0C:
	ldrb r2, [r4]
	adds r0, r7, #0
	mov r1, r8
	movs r3, #8
	bl func_fe6_08082F54
	adds r4, #1
	subs r5, #1
	cmp r5, #0
	bge .L08083A0C
	movs r0, #0x18
	add sb, r0
	adds r6, #0x18
	mov r0, sl
	adds r0, #0x60
	cmp r6, r0
	ble .L08083964
	movs r4, #0
	ldr r5, .L08083A64 @ =0x0203D518
.L08083A32:
	adds r0, r4, r5
	ldrb r2, [r0]
	adds r0, r7, #0
	mov r1, r8
	movs r3, #2
	bl func_fe6_08082F54
	adds r4, #1
	cmp r4, #9
	ble .L08083A32
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08083A54: .4byte 0x02016920
.L08083A58: .4byte 0x020168F4
.L08083A5C: .4byte 0x0203D4A0
.L08083A60: .4byte 0x0203D4B3
.L08083A64: .4byte 0x0203D518

	thumb_func_start func_fe6_08083A68
func_fe6_08083A68: @ 0x08083A68
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	adds r7, r1, #0
	ldr r0, .L08083B78 @ =0x02016920
	ldr r1, .L08083B7C @ =0x020168F4
	ldr r1, [r1]
	str r1, [r0]
	ldr r0, .L08083B80 @ =0x0203D4A0
	mov sl, r0
	movs r1, #0
	mov sb, r1
	mov r6, sl
.L08083A88:
	adds r0, r7, #0
	mov r1, r8
	movs r2, #8
	bl func_fe6_08082FE8
	strb r0, [r6]
	adds r0, r7, #0
	mov r1, r8
	movs r2, #1
	bl func_fe6_08082FE8
	strb r0, [r6, #1]
	adds r0, r7, #0
	mov r1, r8
	movs r2, #5
	bl func_fe6_08082FE8
	strb r0, [r6, #2]
	adds r0, r7, #0
	mov r1, r8
	movs r2, #6
	bl func_fe6_08082FE8
	strb r0, [r6, #3]
	adds r0, r7, #0
	mov r1, r8
	movs r2, #5
	bl func_fe6_08082FE8
	strb r0, [r6, #4]
	adds r0, r7, #0
	mov r1, r8
	movs r2, #5
	bl func_fe6_08082FE8
	strb r0, [r6, #5]
	adds r0, r7, #0
	mov r1, r8
	movs r2, #5
	bl func_fe6_08082FE8
	strb r0, [r6, #6]
	adds r0, r7, #0
	mov r1, r8
	movs r2, #5
	bl func_fe6_08082FE8
	strb r0, [r6, #7]
	adds r0, r7, #0
	mov r1, r8
	movs r2, #5
	bl func_fe6_08082FE8
	strb r0, [r6, #8]
	adds r0, r7, #0
	mov r1, r8
	movs r2, #5
	bl func_fe6_08082FE8
	strb r0, [r6, #9]
	adds r0, r7, #0
	mov r1, r8
	movs r2, #5
	bl func_fe6_08082FE8
	strb r0, [r6, #0xa]
	mov r0, sl
	adds r0, #0xb
	mov r1, sb
	adds r4, r1, r0
	movs r5, #7
.L08083B16:
	adds r0, r7, #0
	mov r1, r8
	movs r2, #3
	bl func_fe6_08082FE8
	strb r0, [r4]
	adds r4, #1
	subs r5, #1
	cmp r5, #0
	bge .L08083B16
	ldr r4, .L08083B84 @ =0x0203D4B3
	add r4, sb
	movs r5, #4
.L08083B30:
	adds r0, r7, #0
	mov r1, r8
	movs r2, #8
	bl func_fe6_08082FE8
	strb r0, [r4]
	adds r4, #1
	subs r5, #1
	cmp r5, #0
	bge .L08083B30
	movs r0, #0x18
	add sb, r0
	adds r6, #0x18
	mov r0, sl
	adds r0, #0x60
	cmp r6, r0
	ble .L08083A88
	movs r4, #0
	ldr r5, .L08083B88 @ =0x0203D518
.L08083B56:
	adds r0, r7, #0
	mov r1, r8
	movs r2, #2
	bl func_fe6_08082FE8
	adds r1, r4, r5
	strb r0, [r1]
	adds r4, #1
	cmp r4, #9
	ble .L08083B56
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08083B78: .4byte 0x02016920
.L08083B7C: .4byte 0x020168F4
.L08083B80: .4byte 0x0203D4A0
.L08083B84: .4byte 0x0203D4B3
.L08083B88: .4byte 0x0203D518

	thumb_func_start func_fe6_08083B8C
func_fe6_08083B8C: @ 0x08083B8C
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r1, #0
	movs r0, #0
.L08083B96:
	adds r3, r0, #1
	adds r2, r3, #0
	cmp r3, #4
	bgt .L08083BB4
.L08083B9E:
	cmp r0, r5
	bne .L08083BAC
	cmp r2, r4
	bne .L08083BAC
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	b .L08083BBC
.L08083BAC:
	adds r1, #1
	adds r2, #1
	cmp r2, #4
	ble .L08083B9E
.L08083BB4:
	adds r0, r3, #0
	cmp r0, #4
	ble .L08083B96
	movs r0, #0
.L08083BBC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08083BC4
func_fe6_08083BC4: @ 0x08083BC4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	cmp r0, r1
	bge .L08083CD8
	ldr r1, .L08083E60 @ =0x0203D4A0
	mov sl, r1
	movs r3, #0x1f
	mov sb, r0
	ldr r5, [sp]
	str r0, [sp, #0x10]
	mov r7, sl
.L08083BEA:
	ldr r0, [r5]
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	strb r0, [r7]
	ldr r0, [r5]
	ldr r1, [r0]
	ldr r2, [r0, #4]
	ldr r0, [r1, #0x28]
	ldr r1, [r2, #0x24]
	orrs r0, r1
	lsrs r0, r0, #8
	movs r1, #1
	ands r0, r1
	strb r0, [r7, #1]
	ldr r1, [r5]
	adds r0, r3, #0
	ldrb r1, [r1, #8]
	ands r0, r1
	strb r0, [r7, #2]
	ldr r1, [r5]
	movs r0, #0x3f
	ldrb r1, [r1, #0x10]
	ands r0, r1
	strb r0, [r7, #3]
	ldr r1, [r5]
	adds r0, r3, #0
	ldrb r1, [r1, #0x12]
	ands r0, r1
	strb r0, [r7, #4]
	ldr r1, [r5]
	adds r0, r3, #0
	ldrb r1, [r1, #0x13]
	ands r0, r1
	strb r0, [r7, #5]
	ldr r1, [r5]
	adds r0, r3, #0
	ldrb r1, [r1, #0x14]
	ands r0, r1
	strb r0, [r7, #6]
	ldr r1, [r5]
	adds r0, r3, #0
	ldrb r1, [r1, #0x15]
	ands r0, r1
	strb r0, [r7, #7]
	ldr r1, [r5]
	adds r0, r3, #0
	ldrb r1, [r1, #0x16]
	ands r0, r1
	strb r0, [r7, #8]
	ldr r1, [r5]
	adds r0, r3, #0
	ldrb r1, [r1, #0x17]
	ands r0, r1
	strb r0, [r7, #9]
	ldr r1, [r5]
	ldr r2, [r1, #4]
	ldr r0, [r1]
	ldrb r2, [r2, #0x11]
	ldrb r0, [r0, #0x13]
	adds r0, r2, r0
	ldrb r1, [r1, #0x18]
	adds r0, r1, r0
	movs r1, #0x1f
	ands r0, r1
	strb r0, [r7, #0xa]
	movs r6, #0
	ldr r0, [sp, #0x10]
	mov r8, r0
	mov r0, sl
	adds r0, #0xb
	mov r1, sb
	adds r4, r1, r0
.L08083C7A:
	ldr r0, [r5]
	adds r0, #0x26
	adds r0, r0, r6
	ldrb r0, [r0]
	str r3, [sp, #0x18]
	bl GetWeaponLevelFromExp
	movs r1, #7
	ands r0, r1
	strb r0, [r4]
	adds r4, #1
	adds r6, #1
	ldr r3, [sp, #0x18]
	cmp r6, #7
	ble .L08083C7A
	movs r6, #0
	ldr r4, .L08083E64 @ =0x0203D4B3
	add r4, sb
.L08083C9E:
	ldr r0, [sp]
	add r0, r8
	ldr r0, [r0]
	lsls r1, r6, #1
	adds r0, #0x1c
	adds r0, r0, r1
	ldrh r0, [r0]
	str r3, [sp, #0x18]
	bl GetItemIid
	strb r0, [r4]
	adds r4, #1
	adds r6, #1
	ldr r3, [sp, #0x18]
	cmp r6, #4
	ble .L08083C9E
	movs r0, #0x18
	add sb, r0
	adds r5, #4
	ldr r1, [sp, #0x10]
	adds r1, #4
	str r1, [sp, #0x10]
	adds r7, #0x18
	ldr r0, [sp, #8]
	adds r0, #1
	str r0, [sp, #8]
	ldr r1, [sp, #4]
	cmp r0, r1
	blt .L08083BEA
.L08083CD8:
	ldr r4, .L08083E68 @ =0x02016920
	bl GetGameTime
	lsls r0, r0, #0xd
	lsrs r0, r0, #0x10
	str r0, [r4]
	ldr r0, [sp, #8]
	cmp r0, #4
	bgt .L08083DA6
	ldr r1, .L08083E60 @ =0x0203D4A0
	mov sl, r1
	movs r0, #0x1f
	mov r8, r0
	ldr r1, [sp, #8]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	mov sb, r0
	mov r5, sb
	add r5, sl
.L08083D00:
	movs r0, #0
	strb r0, [r5]
	bl func_fe6_08082EEC
	movs r1, #1
	ands r1, r0
	strb r1, [r5, #1]
	bl func_fe6_08082EEC
	mov r1, r8
	ands r0, r1
	strb r0, [r5, #2]
	bl func_fe6_08082EEC
	movs r1, #0x3f
	ands r1, r0
	strb r1, [r5, #3]
	bl func_fe6_08082EEC
	mov r1, r8
	ands r0, r1
	strb r0, [r5, #4]
	bl func_fe6_08082EEC
	mov r1, r8
	ands r0, r1
	strb r0, [r5, #5]
	bl func_fe6_08082EEC
	mov r1, r8
	ands r0, r1
	strb r0, [r5, #6]
	bl func_fe6_08082EEC
	mov r1, r8
	ands r0, r1
	strb r0, [r5, #7]
	bl func_fe6_08082EEC
	mov r1, r8
	ands r0, r1
	strb r0, [r5, #8]
	bl func_fe6_08082EEC
	mov r1, r8
	ands r0, r1
	strb r0, [r5, #9]
	bl func_fe6_08082EEC
	mov r1, r8
	ands r0, r1
	strb r0, [r5, #0xa]
	mov r0, sl
	adds r0, #0xb
	mov r1, sb
	adds r4, r1, r0
	movs r7, #7
	movs r6, #7
.L08083D74:
	bl func_fe6_08082EEC
	ands r0, r7
	strb r0, [r4]
	adds r4, #1
	subs r6, #1
	cmp r6, #0
	bge .L08083D74
	ldr r4, .L08083E64 @ =0x0203D4B3
	add r4, sb
	movs r6, #4
.L08083D8A:
	bl func_fe6_08082EEC
	strb r0, [r4]
	adds r4, #1
	subs r6, #1
	cmp r6, #0
	bge .L08083D8A
	movs r0, #0x18
	add sb, r0
	adds r5, #0x18
	mov r0, sl
	adds r0, #0x60
	cmp r5, r0
	ble .L08083D00
.L08083DA6:
	ldr r1, .L08083E6C @ =0x0203D518
	movs r2, #0
	adds r0, r1, #0
	adds r0, #9
.L08083DAE:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge .L08083DAE
	movs r1, #0
	str r1, [sp, #8]
	ldr r0, [sp, #4]
	cmp r1, r0
	bge .L08083E50
.L08083DC0:
	ldr r1, [sp, #8]
	lsls r0, r1, #2
	ldr r1, [sp]
	adds r4, r0, r1
	ldr r0, [r4]
	bl GetUnitSupportCount
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0xc]
	movs r6, #0
	ldr r2, [sp, #8]
	adds r2, #1
	cmp r6, r0
	bge .L08083E48
	mov r8, r4
.L08083DE0:
	mov r1, r8
	ldr r0, [r1]
	adds r1, r6, #0
	str r2, [sp, #0x14]
	bl GetUnitSupportPid
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	ldr r2, [sp, #0x14]
	adds r5, r2, #0
	adds r0, r6, #1
	mov sl, r0
	ldr r1, [sp, #4]
	cmp r2, r1
	bge .L08083E40
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	ldr r1, .L08083E60 @ =0x0203D4A0
	adds r7, r0, r1
.L08083E0A:
	ldrb r0, [r7]
	cmp r0, sb
	bne .L08083E36
	ldr r0, [sp, #8]
	adds r1, r5, #0
	str r2, [sp, #0x14]
	bl func_fe6_08083B8C
	adds r4, r0, #0
	mov r1, r8
	ldr r0, [r1]
	adds r1, r6, #0
	bl GetUnitSupportLevel
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r1, .L08083E6C @ =0x0203D518
	adds r4, r4, r1
	movs r1, #3
	ands r0, r1
	strb r0, [r4]
	ldr r2, [sp, #0x14]
.L08083E36:
	adds r7, #0x18
	adds r5, #1
	ldr r0, [sp, #4]
	cmp r5, r0
	blt .L08083E0A
.L08083E40:
	mov r6, sl
	ldr r1, [sp, #0xc]
	cmp r6, r1
	blt .L08083DE0
.L08083E48:
	str r2, [sp, #8]
	ldr r0, [sp, #4]
	cmp r2, r0
	blt .L08083DC0
.L08083E50:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08083E60: .4byte 0x0203D4A0
.L08083E64: .4byte 0x0203D4B3
.L08083E68: .4byte 0x02016920
.L08083E6C: .4byte 0x0203D518

	thumb_func_start func_fe6_08083E70
func_fe6_08083E70: @ 0x08083E70
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sl, r0
	str r1, [sp, #0xc]
	add r1, sp, #8
	movs r0, #0
	strb r0, [r1, #2]
	movs r0, #4
	bl EnableBgSync
	bl InitTalkTextFont
	movs r0, #0
	str r0, [sp, #0x10]
	add r7, sp, #8
	movs r1, #0xc0
	mov sb, r1
	mov r8, r0
	movs r6, #0
.L08083E9E:
	mov r1, sl
	adds r0, r1, r6
	bl ClearText
	movs r5, #0
	movs r4, #0
.L08083EAA:
	mov r0, r8
	adds r2, r0, r4
	ldr r1, .L08083F30 @ =0x020169C4
	ldr r0, .L08083F34 @ =0x020168F0
	ldr r0, [r0]
	ldrh r1, [r1, #6]
	adds r0, r1, r0
	cmp r2, r0
	beq .L08083F1E
	ldr r0, .L08083F38 @ =0x02016924
	adds r0, r2, r0
	ldrb r0, [r0]
	lsls r1, r0, #1
	ldr r0, [sp, #0xc]
	adds r1, r0, r1
	ldrb r0, [r1]
	strb r0, [r7]
	ldrb r0, [r1, #1]
	strb r0, [r7, #1]
	movs r1, #0
	str r1, [sp]
	add r0, sp, #8
	str r0, [sp, #4]
	mov r1, sl
	adds r0, r1, r6
	ldr r1, .L08083F3C @ =gBg2Tm+0x4
	add r1, sb
	movs r2, #1
	adds r3, r5, #0
	bl PutDrawText
	adds r5, #0xa
	adds r4, #1
	adds r0, r4, #0
	movs r1, #6
	bl __modsi3
	cmp r0, #0
	bne .L08083F06
	adds r0, r4, #0
	movs r1, #6
	bl __divsi3
	cmp r0, #2
	bgt .L08083F06
	adds r5, #0xa
.L08083F06:
	cmp r4, #0x12
	ble .L08083EAA
	movs r0, #0xc0
	add sb, r0
	movs r1, #0x13
	add r8, r1
	adds r6, #8
	ldr r0, [sp, #0x10]
	adds r0, #1
	str r0, [sp, #0x10]
	cmp r0, #4
	ble .L08083E9E
.L08083F1E:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08083F30: .4byte 0x020169C4
.L08083F34: .4byte 0x020168F0
.L08083F38: .4byte 0x02016924
.L08083F3C: .4byte gBg2Tm+0x4

	thumb_func_start func_fe6_08083F40
func_fe6_08083F40: @ 0x08083F40
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r4, r4, #6
	ldr r6, .L08083FE8 @ =gBg2Tm+0x4
	adds r0, r4, r6
	ldr r5, .L08083FEC @ =0x0203D4A0
	ldrb r2, [r5]
	movs r1, #2
	bl PutNumberOrBlank
	adds r0, r6, #4
	adds r0, r4, r0
	ldrb r2, [r5, #1]
	movs r1, #2
	bl PutNumberOrBlank
	adds r0, r6, #0
	adds r0, #0xa
	adds r0, r4, r0
	ldrb r2, [r5, #2]
	movs r1, #2
	bl PutNumberOrBlank
	adds r0, r6, #0
	adds r0, #0x10
	adds r0, r4, r0
	ldrb r2, [r5, #3]
	movs r1, #2
	bl PutNumberOrBlank
	adds r0, r6, #0
	adds r0, #0x16
	adds r0, r4, r0
	ldrb r2, [r5, #4]
	movs r1, #2
	bl PutNumberOrBlank
	adds r0, r6, #0
	adds r0, #0x1c
	adds r0, r4, r0
	ldrb r2, [r5, #5]
	movs r1, #2
	bl PutNumberOrBlank
	adds r0, r6, #0
	adds r0, #0x22
	adds r0, r4, r0
	ldrb r2, [r5, #6]
	movs r1, #2
	bl PutNumberOrBlank
	adds r0, r6, #0
	adds r0, #0x28
	adds r0, r4, r0
	ldrb r2, [r5, #7]
	movs r1, #2
	bl PutNumberOrBlank
	adds r0, r6, #0
	adds r0, #0x2e
	adds r0, r4, r0
	ldrb r2, [r5, #8]
	movs r1, #2
	bl PutNumberOrBlank
	adds r0, r6, #0
	adds r0, #0x34
	adds r0, r4, r0
	ldrb r2, [r5, #9]
	movs r1, #2
	bl PutNumberOrBlank
	adds r0, r6, #0
	adds r0, #0x3a
	adds r4, r4, r0
	ldrb r2, [r5, #0xa]
	adds r0, r4, #0
	movs r1, #2
	bl PutNumberOrBlank
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08083FE8: .4byte gBg2Tm+0x4
.L08083FEC: .4byte 0x0203D4A0

	thumb_func_start func_fe6_08083FF0
func_fe6_08083FF0: @ 0x08083FF0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0
	bl InitBgs
	bl ResetTextFont
	bl ResetText
	movs r0, #0
	strh r0, [r6, #0x2a]
	ldr r4, .L08084110 @ =gDispIo
	movs r2, #1
	ldrb r0, [r4, #1]
	orrs r0, r2
	movs r3, #2
	orrs r0, r3
	movs r1, #4
	orrs r0, r1
	movs r1, #8
	orrs r0, r1
	movs r1, #0x11
	rsbs r1, r1, #0
	ands r0, r1
	strb r0, [r4, #1]
	adds r1, #0xd
	adds r0, r1, #0
	ldrb r5, [r4, #0xc]
	ands r0, r5
	orrs r0, r2
	strb r0, [r4, #0xc]
	adds r0, r1, #0
	ldrb r2, [r4, #0x10]
	ands r0, r2
	orrs r0, r3
	strb r0, [r4, #0x10]
	ldrb r5, [r4, #0x14]
	ands r1, r5
	strb r1, [r4, #0x14]
	movs r0, #3
	ldrb r1, [r4, #0x18]
	orrs r0, r1
	strb r0, [r4, #0x18]
	bl UnpackUiWindowFrameGraphics
	bl EnablePalSync
	ldr r0, .L08084114 @ =gBg0Tm
	movs r1, #0
	bl TmFill
	ldr r0, .L08084118 @ =gBg1Tm
	movs r1, #0
	bl TmFill
	ldr r0, .L0808411C @ =gBg2Tm
	movs r1, #0
	bl TmFill
	ldr r0, .L08084120 @ =gBg3Tm
	movs r1, #0
	bl TmFill
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	ldr r2, .L08084124 @ =0x0000FFF8
	movs r0, #1
	movs r1, #8
	bl SetBgOffset
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrb r2, [r4, #1]
	ands r0, r2
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r4, #1]
	movs r0, #2
	str r0, [sp]
	movs r0, #0
	movs r1, #2
	movs r2, #0x1e
	movs r3, #0x10
	bl PutUiWindowFrame
	movs r0, #0xf
	bl EnableBgSync
	ldr r5, .L08084128 @ =0x020168F8
	movs r4, #4
.L080840C6:
	adds r0, r5, #0
	movs r1, #0x1c
	bl InitText
	adds r5, #8
	subs r4, #1
	cmp r4, #0
	bge .L080840C6
	adds r0, r6, #0
	adds r0, #0x30
	adds r1, r6, #0
	adds r1, #0x2c
	ldrb r1, [r1]
	bl func_fe6_08083BC4
	movs r0, #7
	movs r1, #0xb
	bl func_fe6_08082E74
	ldr r0, .L0808412C @ =func_fe6_08083944
	bl func_fe6_080832A0
	ldr r0, .L08084128 @ =0x020168F8
	ldr r1, .L08084130 @ =gUnk_08679820
	bl func_fe6_08083E70
	movs r0, #0
	movs r1, #0
	movs r2, #0xa
	bl StartMuralBackground
	str r0, [r6, #0x44]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08084110: .4byte gDispIo
.L08084114: .4byte gBg0Tm
.L08084118: .4byte gBg1Tm
.L0808411C: .4byte gBg2Tm
.L08084120: .4byte gBg3Tm
.L08084124: .4byte 0x0000FFF8
.L08084128: .4byte 0x020168F8
.L0808412C: .4byte func_fe6_08083944
.L08084130: .4byte gUnk_08679820

	thumb_func_start func_fe6_08084134
func_fe6_08084134: @ 0x08084134
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_08084138
func_fe6_08084138: @ 0x08084138
	push {lr}
	ldr r0, [r0, #0x44]
	bl Proc_End
	ldr r2, .L08084164 @ =gDispIo
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r1, [r2, #1]
	ands r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #2
	ands r0, r1
	subs r1, #4
	ands r0, r1
	subs r1, #8
	ands r0, r1
	strb r0, [r2, #1]
	pop {r0}
	bx r0
	.align 2, 0
.L08084164: .4byte gDispIo

	thumb_func_start func_fe6_08084168
func_fe6_08084168: @ 0x08084168
	push {r4, r5, r6, r7, lr}
	adds r1, r0, #0
	ldr r0, .L08084184 @ =gUnk_08679924
	bl SpawnProcLocking
	adds r7, r0, #0
	adds r1, r7, #0
	adds r1, #0x2c
	movs r0, #0
	strb r0, [r1]
	movs r4, #0
	adds r6, r1, #0
	b .L08084190
	.align 2, 0
.L08084184: .4byte gUnk_08679924
.L08084188:
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	adds r4, r5, #0
.L08084190:
	cmp r4, #4
	bgt .L080841AC
	adds r5, r4, #1
	adds r0, r5, #0
	bl GetUnit
	lsls r2, r4, #2
	adds r1, r7, #0
	adds r1, #0x30
	adds r1, r1, r2
	str r0, [r1]
	ldr r0, [r0]
	cmp r0, #0
	bne .L08084188
.L080841AC:
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_080841B4
func_fe6_080841B4: @ 0x080841B4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080841E8 @ =gUnk_08679924
	bl SpawnProcLocking
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x2c
	movs r0, #0
	strb r0, [r1]
	movs r1, #4
	adds r0, r2, #0
	adds r0, #0x40
.L080841CE:
	str r4, [r0]
	subs r0, #4
	subs r1, #1
	cmp r1, #0
	bge .L080841CE
	adds r1, r2, #0
	adds r1, #0x2c
	movs r0, #5
	strb r0, [r1]
	adds r0, r2, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L080841E8: .4byte gUnk_08679924

	thumb_func_start func_fe6_080841EC
func_fe6_080841EC: @ 0x080841EC
	ldr r0, .L080841F4 @ =0x0203D524
	movs r1, #0
	strb r1, [r0]
	bx lr
	.align 2, 0
.L080841F4: .4byte 0x0203D524

	thumb_func_start func_fe6_080841F8
func_fe6_080841F8: @ 0x080841F8
	bx lr
	.align 2, 0
