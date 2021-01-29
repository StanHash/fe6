
	.include "macro.inc"

	.syntax unified

	thumb_func_start sub_80350C8
sub_80350C8: @ 0x080350C8
	push {r4, r5, lr}
	ldr r4, _080350DC @ =0x03004568
	ldr r3, [r4]
	cmp r3, #0
	beq _080350E4
	cmp r3, #1
	beq _08035150
	ldr r0, _080350E0 @ =0x030013BC
	ldr r0, [r0]
	b _080351DA
	.align 2, 0
_080350DC: .4byte 0x03004568
_080350E0: .4byte 0x030013BC
_080350E4:
	ldr r0, _08035134 @ =0x04000134
	strh r3, [r0]
	ldr r2, _08035138 @ =0x04000128
	ldr r0, _0803513C @ =gUnk_Sio_085C98F4
	ldr r0, [r0]
	ldr r1, _08035140 @ =0x00001B78
	adds r0, r0, r1
	ldrh r0, [r0]
	mvns r0, r0
	strh r0, [r2, #2]
	ldr r1, _08035144 @ =0x030013B8
	movs r5, #0xc0
	lsls r5, r5, #7
	adds r0, r5, #0
	ldrb r1, [r1]
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	adds r2, r0, #0
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _080351D6
	ldr r1, _08035148 @ =0x030013BC
	movs r0, #4
	ands r2, r0
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	str r0, [r1]
	cmp r0, #0
	beq _08035128
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r1]
_08035128:
	ldr r0, _0803514C @ =0x030044D4
	str r3, [r0]
	movs r0, #1
	str r0, [r4]
	b _080351D6
	.align 2, 0
_08035134: .4byte 0x04000134
_08035138: .4byte 0x04000128
_0803513C: .4byte gUnk_Sio_085C98F4
_08035140: .4byte 0x00001B78
_08035144: .4byte 0x030013B8
_08035148: .4byte 0x030013BC
_0803514C: .4byte 0x030044D4
_08035150:
	ldr r0, _08035184 @ =0x04000128
	ldrh r0, [r0]
	adds r2, r0, #0
	ldr r0, _08035188 @ =0x030044D4
	ldr r0, [r0]
	ldr r3, _0803518C @ =gUnk_Sio_085C98F4
	cmp r0, #0
	beq _08035198
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	bne _08035198
	ldr r1, [r3]
	ldr r0, _08035190 @ =0x0000FFFF
	ldrh r1, [r1, #0x14]
	cmp r1, r0
	beq _08035198
	ldr r1, _08035194 @ =0x030013BC
	movs r0, #0x30
	ands r2, r0
	lsrs r0, r2, #4
	str r0, [r1]
	movs r1, #2
	str r1, [r4]
	b _080351DA
	.align 2, 0
_08035184: .4byte 0x04000128
_08035188: .4byte 0x030044D4
_0803518C: .4byte gUnk_Sio_085C98F4
_08035190: .4byte 0x0000FFFF
_08035194: .4byte 0x030013BC
_08035198:
	ldr r2, _080351B8 @ =0x04000128
	ldr r0, [r3]
	ldr r1, _080351BC @ =0x00001B78
	adds r0, r0, r1
	ldrh r0, [r0]
	mvns r0, r0
	strh r0, [r2, #2]
	ldr r0, _080351C0 @ =0x030013BC
	ldr r0, [r0]
	cmp r0, #0
	beq _080351C8
	ldr r1, _080351C4 @ =0x030013B8
	movs r3, #0xc0
	lsls r3, r3, #7
	adds r0, r3, #0
	b _080351D0
	.align 2, 0
_080351B8: .4byte 0x04000128
_080351BC: .4byte 0x00001B78
_080351C0: .4byte 0x030013BC
_080351C4: .4byte 0x030013B8
_080351C8:
	ldr r1, _080351E0 @ =0x030013B8
	movs r5, #0xc1
	lsls r5, r5, #7
	adds r0, r5, #0
_080351D0:
	ldrb r1, [r1]
	orrs r0, r1
	strh r0, [r2]
_080351D6:
	movs r0, #1
	rsbs r0, r0, #0
_080351DA:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080351E0: .4byte 0x030013B8

	thumb_func_start sub_80351E4
sub_80351E4: @ 0x080351E4
	ldr r0, _080351F0 @ =0x04000128
	ldrh r1, [r0]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	bx lr
	.align 2, 0
_080351F0: .4byte 0x04000128

	thumb_func_start sub_80351F4
sub_80351F4: @ 0x080351F4
	push {r4, r5, lr}
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _0803521C @ =gUnk_Sio_085C98F4
	ldr r3, [r3]
	ldr r5, _08035220 @ =0x00001B78
	adds r4, r3, r5
	strh r0, [r4]
	ldr r4, _08035224 @ =0x00001B7A
	adds r0, r3, r4
	strh r1, [r0]
	adds r5, #4
	adds r3, r3, r5
	strh r2, [r3]
	ldr r0, _08035228 @ =0x030013B8
	strb r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803521C: .4byte gUnk_Sio_085C98F4
_08035220: .4byte 0x00001B78
_08035224: .4byte 0x00001B7A
_08035228: .4byte 0x030013B8

	thumb_func_start sub_803522C
sub_803522C: @ 0x0803522C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _0803537C @ =0x030044D0
	movs r3, #0
	str r3, [r0]
	ldr r2, _08035380 @ =gUnk_Sio_085C98F4
	ldr r0, [r2]
	movs r1, #0
	strh r3, [r0, #0x22]
	strh r3, [r0, #0x24]
	ldr r4, _08035384 @ =0x00001B74
	adds r0, r0, r4
	strb r1, [r0]
	ldr r0, [r2]
	adds r4, #1
	adds r0, r0, r4
	strb r1, [r0]
	ldr r0, [r2]
	adds r4, #1
	adds r0, r0, r4
	strb r1, [r0]
	ldr r0, [r2]
	adds r4, #1
	adds r0, r0, r4
	strb r1, [r0]
	ldr r0, [r2]
	strb r1, [r0, #0x1e]
	ldr r0, [r2]
	strb r1, [r0, #0x1f]
	ldr r0, [r2]
	adds r0, #0x20
	strb r1, [r0]
	ldr r0, [r2]
	strh r3, [r0, #0x30]
	ldr r0, _08035388 @ =0x030013C8
	mov sb, r0
	ldr r1, _0803538C @ =0x030013CA
	mov r8, r1
	adds r5, r2, #0
	movs r4, #0
_08035280:
	ldr r0, [r5]
	adds r0, #0xb
	adds r0, r0, r3
	strb r4, [r0]
	ldr r1, [r5]
	lsls r2, r3, #1
	adds r0, r1, #0
	adds r0, #0x12
	adds r0, r0, r2
	strh r4, [r0]
	adds r1, #0x1a
	adds r1, r1, r3
	strb r4, [r1]
	ldr r0, [r5]
	adds r0, #0x26
	adds r0, r0, r2
	strh r4, [r0]
	adds r3, #1
	cmp r3, #3
	ble _08035280
	movs r3, #0
	ldr r5, _08035390 @ =0x03004580
	movs r2, #0
	ldr r4, _08035380 @ =gUnk_Sio_085C98F4
_080352B0:
	adds r0, r3, r5
	strb r2, [r0]
	ldr r0, [r4]
	lsls r1, r3, #1
	adds r0, #0x32
	adds r0, r0, r1
	strh r2, [r0]
	adds r3, #1
	cmp r3, #0x7f
	ble _080352B0
	movs r4, #0
	ldr r5, _08035380 @ =gUnk_Sio_085C98F4
	movs r1, #0
	movs r2, #0x9a
	lsls r2, r2, #1
_080352CE:
	ldr r0, [r5]
	adds r0, r0, r2
	strb r1, [r0]
	strb r1, [r0, #4]
	movs r3, #0x7f
	adds r0, #0x89
_080352DA:
	strb r1, [r0]
	subs r0, #1
	subs r3, #1
	cmp r3, #0
	bge _080352DA
	adds r2, #0x8c
	adds r4, #1
	cmp r4, #0x1f
	ble _080352CE
	movs r4, #0
	ldr r2, _08035380 @ =gUnk_Sio_085C98F4
	mov ip, r2
	movs r5, #0
	movs r7, #0x8c
	ldr r6, _08035394 @ =0x000012B4
_080352F8:
	adds r0, r4, #0
	muls r0, r7, r0
	adds r0, r0, r6
	mov r2, ip
	ldr r1, [r2]
	adds r1, r1, r0
	strb r5, [r1]
	strb r5, [r1, #4]
	adds r2, r4, #1
	movs r3, #0x7f
	adds r1, #0x89
_0803530E:
	strb r5, [r1]
	subs r1, #1
	subs r3, #1
	cmp r3, #0
	bge _0803530E
	adds r4, r2, #0
	cmp r4, #0xf
	ble _080352F8
	movs r0, #0
	mov r4, r8
	strh r0, [r4]
	mov r1, sb
	strh r0, [r1]
	movs r1, #0
	ldr r0, _08035398 @ =0x0203B218
	movs r3, #0x80
	lsls r3, r3, #2
_08035330:
	strh r1, [r0]
	adds r0, #2
	subs r3, #1
	cmp r3, #0
	bne _08035330
	movs r4, #0
	ldr r2, _0803539C @ =0x030013D0
	mov r8, r2
	movs r5, #0
	ldr r0, _080353A0 @ =0x000001FF
	mov ip, r0
	ldr r7, _080353A4 @ =0x0203B618
	ldr r6, _080353A8 @ =0x030013D8
_0803534A:
	lsls r0, r4, #1
	mov r1, r8
	adds r2, r0, r1
	adds r1, r0, r6
	strh r5, [r1]
	strh r5, [r2]
	adds r2, r4, #1
	adds r0, r0, r7
	mov r3, ip
	adds r3, #1
_0803535E:
	strh r5, [r0]
	adds r0, #8
	subs r3, #1
	cmp r3, #0
	bne _0803535E
	adds r4, r2, #0
	cmp r4, #3
	ble _0803534A
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803537C: .4byte 0x030044D0
_08035380: .4byte gUnk_Sio_085C98F4
_08035384: .4byte 0x00001B74
_08035388: .4byte 0x030013C8
_0803538C: .4byte 0x030013CA
_08035390: .4byte 0x03004580
_08035394: .4byte 0x000012B4
_08035398: .4byte 0x0203B218
_0803539C: .4byte 0x030013D0
_080353A0: .4byte 0x000001FF
_080353A4: .4byte 0x0203B618
_080353A8: .4byte 0x030013D8

	thumb_func_start sub_80353AC
sub_80353AC: @ 0x080353AC
	push {r4, lr}
	ldr r2, _08035408 @ =gUnk_Sio_085C98F4
	ldr r0, [r2]
	movs r4, #0
	strb r4, [r0]
	ldr r0, [r2]
	strb r4, [r0, #1]
	ldr r1, [r2]
	movs r3, #0
	strh r4, [r1, #2]
	strh r4, [r1, #4]
	movs r0, #0xff
	strb r0, [r1, #6]
	ldr r0, [r2]
	strb r3, [r0, #7]
	ldr r0, [r2]
	strb r3, [r0, #8]
	ldr r0, [r2]
	strb r3, [r0, #9]
	ldr r0, [r2]
	strb r3, [r0, #0xf]
	ldr r0, [r2]
	strb r3, [r0, #0x10]
	ldr r0, [r2]
	strb r3, [r0, #0x11]
	ldr r0, [r2]
	adds r0, #0x2e
	strb r3, [r0]
	ldr r0, [r2]
	strb r3, [r0, #0xa]
	ldr r0, _0803540C @ =0x00004321
	movs r1, #3
	movs r2, #0x88
	bl sub_80351F4
	movs r0, #0
	bl sub_8036494
	bl sub_803522C
	ldr r0, _08035410 @ =0x030013C4
	str r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08035408: .4byte gUnk_Sio_085C98F4
_0803540C: .4byte 0x00004321
_08035410: .4byte 0x030013C4

	thumb_func_start sub_8035414
sub_8035414: @ 0x08035414
	push {r4, lr}
	ldr r0, _08035464 @ =0x04000134
	movs r3, #0
	strh r3, [r0]
	ldr r2, _08035468 @ =0x04000128
	ldr r1, _0803546C @ =0x030013B8
	movs r4, #0x80
	lsls r4, r4, #6
	adds r0, r4, #0
	ldrb r1, [r1]
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _08035470 @ =0x0400010E
	strh r3, [r0]
	ldr r2, _08035474 @ =0x030044D4
	ldr r1, _08035478 @ =0x030044D0
	movs r0, #0
	str r0, [r1]
	str r0, [r2]
	ldr r1, _0803547C @ =0x03004568
	str r0, [r1]
	ldr r1, _08035480 @ =0x030013BC
	subs r0, #1
	str r0, [r1]
	ldr r1, _08035484 @ =sub_80354F0
	movs r0, #7
	bl SetIrqFunc
	ldr r1, _08035488 @ =sub_8035880
	movs r0, #6
	bl SetIrqFunc
	ldr r2, _0803548C @ =0x04000200
	ldrh r0, [r2]
	movs r1, #0xc0
	orrs r0, r1
	strh r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08035464: .4byte 0x04000134
_08035468: .4byte 0x04000128
_0803546C: .4byte 0x030013B8
_08035470: .4byte 0x0400010E
_08035474: .4byte 0x030044D4
_08035478: .4byte 0x030044D0
_0803547C: .4byte 0x03004568
_08035480: .4byte 0x030013BC
_08035484: .4byte sub_80354F0
_08035488: .4byte sub_8035880
_0803548C: .4byte 0x04000200

	thumb_func_start sub_8035490
sub_8035490: @ 0x08035490
	push {lr}
	ldr r1, _080354D4 @ =0x04000134
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r2, #0
	strh r0, [r1]
	subs r1, #0xc
	movs r0, #0
	strh r0, [r1]
	ldr r2, _080354D8 @ =0x030044D4
	ldr r1, _080354DC @ =0x030044D0
	movs r0, #0
	str r0, [r1]
	str r0, [r2]
	ldr r1, _080354E0 @ =0x03004568
	str r0, [r1]
	ldr r1, _080354E4 @ =0x030013BC
	subs r0, #1
	str r0, [r1]
	movs r0, #7
	movs r1, #0
	bl SetIrqFunc
	movs r0, #6
	movs r1, #0
	bl SetIrqFunc
	ldr r2, _080354E8 @ =0x04000200
	ldrh r1, [r2]
	ldr r0, _080354EC @ =0x0000FF3F
	ands r0, r1
	strh r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_080354D4: .4byte 0x04000134
_080354D8: .4byte 0x030044D4
_080354DC: .4byte 0x030044D0
_080354E0: .4byte 0x03004568
_080354E4: .4byte 0x030013BC
_080354E8: .4byte 0x04000200
_080354EC: .4byte 0x0000FF3F

	thumb_func_start sub_80354F0
sub_80354F0: @ 0x080354F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	movs r0, #0
	mov sb, r0
	ldr r0, _08035584 @ =0x030044D4
	movs r2, #1
	str r2, [r0]
	ldr r1, _08035588 @ =gUnk_Sio_085C98F4
	ldr r0, [r1]
	mov r3, sb
	strb r3, [r0, #0x1e]
	ldr r0, _0803558C @ =0x030044D0
	str r2, [r0]
	ldr r0, [r1]
	strb r3, [r0, #8]
	ldr r0, _08035590 @ =0x0400010E
	mov r5, sb
	strh r5, [r0]
	ldr r2, [r1]
	ldr r3, _08035594 @ =0x04000128
	ldrh r0, [r3]
	lsls r1, r0, #0x10
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	cmp r0, #6
	beq _08035534
	lsrs r0, r1, #0x14
	movs r1, #3
	ands r0, r1
	strb r0, [r2, #6]
_08035534:
	ldr r0, _08035598 @ =0x04000120
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r1, _0803559C @ =0x030013B8
	movs r2, #0xc0
	lsls r2, r2, #7
	adds r0, r2, #0
	ldrb r1, [r1]
	orrs r0, r1
	strh r0, [r3]
	ldr r0, _080355A0 @ =0x00007FFF
	strh r0, [r3, #2]
	movs r5, #0
	ldr r3, _080355A4 @ =0x0000FFFF
	mov sl, r3
	mov r4, sp
	movs r7, #0
_0803555A:
	ldrh r0, [r4]
	cmp r0, #0
	beq _080355A8
	cmp r0, sl
	beq _080355A8
	ldr r1, _08035588 @ =gUnk_Sio_085C98F4
	ldr r0, [r1]
	adds r0, #0xb
	adds r2, r0, r5
	ldrb r0, [r2]
	cmp r0, #0
	bne _08035576
	movs r0, #1
	strb r0, [r2]
_08035576:
	ldr r1, [r1]
	movs r0, #1
	lsls r0, r5
	ldrb r2, [r1, #8]
	orrs r0, r2
	strb r0, [r1, #8]
	b _080355E2
	.align 2, 0
_08035584: .4byte 0x030044D4
_08035588: .4byte gUnk_Sio_085C98F4
_0803558C: .4byte 0x030044D0
_08035590: .4byte 0x0400010E
_08035594: .4byte 0x04000128
_08035598: .4byte 0x04000120
_0803559C: .4byte 0x030013B8
_080355A0: .4byte 0x00007FFF
_080355A4: .4byte 0x0000FFFF
_080355A8:
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	bl sub_8035CB0
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _080355E2
	ldr r0, _080355D4 @ =gUnk_Sio_085C98F4
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x12
	adds r0, r0, r7
	ldrh r0, [r0]
	cmp r0, sl
	bne _080355D8
	adds r0, r1, #0
	adds r0, #0x1a
	adds r0, r0, r5
	ldrb r1, [r0]
	adds r1, #1
	b _080355E0
	.align 2, 0
_080355D4: .4byte gUnk_Sio_085C98F4
_080355D8:
	adds r0, r1, #0
	adds r0, #0x1a
	adds r0, r0, r5
	movs r1, #0
_080355E0:
	strb r1, [r0]
_080355E2:
	ldr r3, _0803563C @ =gUnk_Sio_085C98F4
	mov r8, r3
	ldr r6, [r3]
	adds r3, r6, #0
	adds r3, #0x12
	adds r3, r3, r7
	mov ip, r3
	ldr r1, _08035640 @ =0x0203B618
	ldr r2, _08035644 @ =0x030013D8
	adds r2, r7, r2
	ldrh r3, [r2]
	lsls r0, r3, #3
	adds r0, r7, r0
	adds r0, r0, r1
	ldrh r1, [r4]
	strh r1, [r0]
	ldr r0, _08035648 @ =0x0000FFFF
	ldrh r1, [r4]
	ands r0, r1
	mov r3, ip
	strh r0, [r3]
	ldrh r0, [r2]
	adds r0, #1
	ldr r1, _0803564C @ =0x000001FF
	mov ip, r1
	mov r3, ip
	ands r0, r3
	strh r0, [r2]
	adds r4, #2
	adds r7, #2
	adds r5, #1
	cmp r5, #3
	ble _0803555A
	mov r4, r8
	adds r0, r6, #0
	ldrh r5, [r0, #4]
	cmp r5, #4
	bls _08035708
	ldrb r0, [r0, #1]
	cmp r0, #1
	beq _08035650
	cmp r0, #3
	beq _080356B0
	b _08035708
	.align 2, 0
_0803563C: .4byte gUnk_Sio_085C98F4
_08035640: .4byte 0x0203B618
_08035644: .4byte 0x030013D8
_08035648: .4byte 0x0000FFFF
_0803564C: .4byte 0x000001FF
_08035650:
	ldr r0, _0803569C @ =0x030013CA
	ldr r2, _080356A0 @ =0x030013C8
	ldrh r3, [r2]
	ldrh r0, [r0]
	cmp r0, r3
	beq _08035676
	ldr r1, _080356A4 @ =0x0203B218
	lsls r0, r3, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	add r0, sp, #8
	strh r1, [r0]
	adds r1, r3, #1
	mov r3, ip
	ands r1, r3
	strh r1, [r2]
	movs r1, #1
	bl sub_8036078
_08035676:
	ldr r1, [r4]
	movs r0, #6
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bne _08035708
	ldr r5, _080356A8 @ =0x00001B7C
	adds r2, r1, r5
	ldrh r0, [r2]
	cmp r0, #0
	beq _08035708
	ldr r1, _080356AC @ =0x0400010C
	ldrh r2, [r2]
	rsbs r0, r2, #0
	str r0, [r1]
	adds r1, #2
	movs r0, #0xc3
	strh r0, [r1]
	b _08035708
	.align 2, 0
_0803569C: .4byte 0x030013CA
_080356A0: .4byte 0x030013C8
_080356A4: .4byte 0x0203B218
_080356A8: .4byte 0x00001B7C
_080356AC: .4byte 0x0400010C
_080356B0:
	movs r0, #6
	ldrsb r0, [r6, r0]
	cmp r0, #0
	beq _080356CA
	adds r0, r6, #0
	adds r0, #0x30
	movs r1, #1
	bl sub_8036078
	mov r0, r8
	ldr r1, [r0]
	ldr r0, _08035720 @ =0x00005FFF
	strh r0, [r1, #0x30]
_080356CA:
	movs r5, #0
	ldr r6, _08035724 @ =0x00009ABC
	mov r4, sp
_080356D0:
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	bl sub_8035CB0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080356EE
	ldrh r1, [r4]
	cmp r1, r6
	beq _080356EE
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
_080356EE:
	adds r4, #2
	adds r5, #1
	cmp r5, #3
	ble _080356D0
	mov r2, sb
	cmp r2, #0
	bne _08035708
	ldr r0, _08035728 @ =gUnk_Sio_085C98F4
	ldr r0, [r0]
	ldr r3, _0803572C @ =0x00001B7E
	adds r0, r0, r3
	movs r1, #1
	strh r1, [r0]
_08035708:
	ldr r1, _08035730 @ =0x030044D0
	movs r0, #0
	str r0, [r1]
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08035720: .4byte 0x00005FFF
_08035724: .4byte 0x00009ABC
_08035728: .4byte gUnk_Sio_085C98F4
_0803572C: .4byte 0x00001B7E
_08035730: .4byte 0x030044D0

	thumb_func_start sub_8035734
sub_8035734: @ 0x08035734
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r0, _08035770 @ =gUnk_Sio_085C98F4
	ldr r2, [r0]
	adds r5, r0, #0
	ldrh r0, [r2, #4]
	cmp r0, #4
	bhi _08035746
	b _08035874
_08035746:
	ldrb r0, [r2, #1]
	cmp r0, #0
	bne _0803574E
	b _08035874
_0803574E:
	ldrb r0, [r2, #0x1e]
	adds r0, #1
	strb r0, [r2, #0x1e]
	ldr r1, [r5]
	ldrh r0, [r1, #4]
	cmp r0, #6
	bne _080357DC
	adds r0, r1, #0
	adds r0, #0x21
	ldrb r0, [r0]
	cmp r0, #2
	beq _0803578E
	cmp r0, #2
	bgt _08035774
	cmp r0, #1
	beq _080357B4
	b _080357DC
	.align 2, 0
_08035770: .4byte gUnk_Sio_085C98F4
_08035774:
	cmp r0, #3
	bne _080357DC
	ldrb r0, [r1, #0x1e]
	cmp r0, #0x3c
	bls _0803578E
	movs r0, #6
	ldrsb r0, [r1, r0]
	adds r1, #0xb
	adds r1, r1, r0
	movs r0, #0
	strb r0, [r1]
	bl sub_8073510
_0803578E:
	ldr r4, _08035800 @ =gUnk_Sio_085C98F4
	ldr r0, [r4]
	ldrb r0, [r0, #1]
	cmp r0, #0
	beq _080357B4
	bl sub_8035CF8
	lsls r0, r0, #0x18
	asrs r2, r0, #0x18
	cmp r2, #0
	bne _080357B4
	ldr r0, [r4]
	movs r1, #6
	ldrsb r1, [r0, r1]
	adds r0, #0xb
	adds r0, r0, r1
	strb r2, [r0]
	bl sub_8073510
_080357B4:
	movs r4, #0
	ldr r5, _08035800 @ =gUnk_Sio_085C98F4
_080357B8:
	ldr r0, _08035800 @ =gUnk_Sio_085C98F4
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x1a
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0x3c
	bls _080357D6
	adds r0, r1, #0
	adds r0, #0xb
	adds r0, r0, r4
	movs r1, #0
	strb r1, [r0]
	bl sub_8073510
_080357D6:
	adds r4, #1
	cmp r4, #3
	ble _080357B8
_080357DC:
	adds r4, r5, #0
	ldr r1, [r4]
	ldrb r0, [r1, #1]
	adds r6, r0, #0
	cmp r6, #1
	bne _08035850
	ldrb r5, [r1, #0x10]
	cmp r5, #0
	bne _08035832
	ldrb r1, [r1, #0x11]
	cmp r1, #0x3c
	bls _08035804
	bl sub_8073510
	ldr r1, [r4]
	movs r0, #2
	strh r0, [r1, #4]
	b _08035874
	.align 2, 0
_08035800: .4byte gUnk_Sio_085C98F4
_08035804:
	mov r0, sp
	bl sub_80361A4
	cmp r0, #0
	beq _08035832
	ldr r1, [sp]
	adds r1, #6
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl sub_8035DC8
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _08035832
	ldr r0, [r4]
	strb r5, [r0, #0x10]
	ldr r1, [r4]
	ldrb r0, [r1, #0x11]
	adds r0, #1
	strb r0, [r1, #0x11]
	ldr r0, [r4]
	adds r0, #0x2e
	strb r6, [r0]
_08035832:
	ldr r2, _0803584C @ =gUnk_Sio_085C98F4
	ldr r1, [r2]
	ldrb r0, [r1, #0x10]
	adds r0, #1
	strb r0, [r1, #0x10]
	ldr r4, [r2]
	ldrb r0, [r4, #0x10]
	movs r1, #0x26
	bl __umodsi3
	strb r0, [r4, #0x10]
	b _08035874
	.align 2, 0
_0803584C: .4byte gUnk_Sio_085C98F4
_08035850:
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08035874
	movs r0, #6
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bne _08035874
	adds r0, r1, #0
	adds r0, #0x30
	movs r1, #1
	rsbs r1, r1, #0
	bl sub_8036078
	ldr r1, [r5]
	ldr r0, _0803587C @ =0x00005FFF
	strh r0, [r1, #0x30]
_08035874:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803587C: .4byte 0x00005FFF

	thumb_func_start sub_8035880
sub_8035880: @ 0x08035880
	ldr r1, _08035898 @ =0x0400010E
	movs r0, #0
	strh r0, [r1]
	ldr r2, _0803589C @ =0x04000128
	ldr r1, _080358A0 @ =0x030013B8
	movs r3, #0xc1
	lsls r3, r3, #7
	adds r0, r3, #0
	ldrb r1, [r1]
	orrs r0, r1
	strh r0, [r2]
	bx lr
	.align 2, 0
_08035898: .4byte 0x0400010E
_0803589C: .4byte 0x04000128
_080358A0: .4byte 0x030013B8

	thumb_func_start sub_80358A4
sub_80358A4: @ 0x080358A4
	push {r4, r5, lr}
	sub sp, #0x10
	adds r2, r0, #0
	mov r1, sp
	ldr r0, _080358D4 @ =gUnk_0810DBBC
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _080358D8 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt _080358CA
	lsls r0, r2, #2
	add r0, sp
	ldrh r0, [r0]
	bl m4aSongNumStart
_080358CA:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080358D4: .4byte gUnk_0810DBBC
_080358D8: .4byte gPlaySt

	thumb_func_start sub_80358DC
sub_80358DC: @ 0x080358DC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _08035930 @ =gUnk_Sio_085C98F4
	ldr r2, [r0]
	ldrb r1, [r2, #1]
	cmp r1, #1
	beq _080358EE
	b _08035C4A
_080358EE:
	movs r0, #6
	ldrsb r0, [r2, r0]
	lsls r1, r0
	ldrb r0, [r2, #0xf]
	orrs r1, r0
	strb r1, [r2, #0xf]
	movs r7, #0
_080358FC:
	lsls r4, r7, #0x18
	asrs r0, r4, #0x18
	ldr r5, _08035930 @ =gUnk_Sio_085C98F4
	ldr r1, [r5]
	adds r1, #0x32
	bl sub_8035EC0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r0, #0
	adds r2, r7, #1
	mov r8, r2
	cmp r0, #0
	bne _0803591A
	b _08035C42
_0803591A:
	cmp r0, #0x16
	beq _08035948
	cmp r0, #0x16
	bgt _08035934
	cmp r0, #4
	bne _08035928
	b _08035A78
_08035928:
	cmp r0, #0xa
	beq _08035948
	b _08035C42
	.align 2, 0
_08035930: .4byte gUnk_Sio_085C98F4
_08035934:
	cmp r0, #0x2e
	beq _08035948
	cmp r0, #0x2e
	bgt _08035942
	cmp r0, #0x2a
	beq _08035948
	b _08035C42
_08035942:
	cmp r1, #0x80
	beq _08035948
	b _08035C42
_08035948:
	ldr r6, _080359A0 @ =gUnk_Sio_085C98F4
	ldr r3, [r6]
	adds r5, r3, #0
	adds r5, #0x32
	ldrb r0, [r5]
	cmp r0, #0x1c
	beq _080359D4
	adds r4, r7, #1
	mov r8, r4
	cmp r0, #0x1f
	beq _08035960
	b _08035C42
_08035960:
	ldrb r0, [r5, #1]
	ldrb r1, [r5, #1]
	ldrb r2, [r3, #6]
	cmp r1, r2
	bne _0803596C
	b _08035C42
_0803596C:
	lsls r0, r0, #1
	adds r2, r3, #0
	adds r2, #0x26
	adds r0, r2, r0
	ldrh r4, [r5, #2]
	ldrh r0, [r0]
	cmp r4, r0
	beq _080359A8
	ldr r0, _080359A4 @ =0x0300456C
	movs r1, #0x1e
	strb r1, [r0]
	ldrb r3, [r3, #6]
	lsls r1, r3, #4
	ldrb r3, [r5, #1]
	orrs r1, r3
	strb r1, [r0, #1]
	ldrb r5, [r5, #1]
	lsls r1, r5, #1
	adds r1, r2, r1
	ldrh r1, [r1]
	strh r1, [r0, #2]
	movs r1, #4
	bl sub_8035DC8
	b _080358FC
	.align 2, 0
_080359A0: .4byte gUnk_Sio_085C98F4
_080359A4: .4byte 0x0300456C
_080359A8:
	adds r0, r5, #0
	bl sub_8036130
	ldr r0, _080359D0 @ =0x0300456C
	movs r1, #0x1e
	strb r1, [r0]
	ldr r2, [r6]
	ldrb r4, [r2, #6]
	lsls r1, r4, #4
	ldrb r3, [r5, #1]
	orrs r1, r3
	strb r1, [r0, #1]
	ldrb r5, [r5, #1]
	lsls r1, r5, #1
	adds r2, #0x26
	adds r2, r2, r1
	ldrh r1, [r2]
	adds r1, #1
	strh r1, [r0, #2]
	b _08035A68
	.align 2, 0
_080359D0: .4byte 0x0300456C
_080359D4:
	movs r2, #0
	lsls r1, r7, #4
	adds r0, r7, #1
	mov r8, r0
	ldr r0, _08035A38 @ =0x0203C618
	subs r1, r1, r7
	adds r3, #0x38
	adds r0, #0xa1
	adds r1, r1, r0
_080359E6:
	adds r0, r3, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, #1
	adds r2, #1
	cmp r2, #0xe
	ble _080359E6
	lsrs r0, r4, #0x18
	bl sub_8035CB0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08035A12
	ldr r0, _08035A3C @ =gUnk_Sio_085C98F4
	ldr r0, [r0]
	ldrb r1, [r0]
	ldrb r2, [r5, #2]
	cmp r1, r2
	bne _08035A12
	ldrh r0, [r0, #4]
	cmp r0, #5
	bls _08035A20
_08035A12:
	lsrs r0, r4, #0x18
	bl sub_8035CB0
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _08035A44
_08035A20:
	ldr r0, _08035A3C @ =gUnk_Sio_085C98F4
	ldr r2, [r0]
	movs r0, #6
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _08035A2E
	b _08035C42
_08035A2E:
	ldr r0, _08035A40 @ =0x0300456C
	movs r1, #0x16
	strb r1, [r0]
	ldrb r1, [r2, #6]
	b _08035A64
	.align 2, 0
_08035A38: .4byte 0x0203C618
_08035A3C: .4byte gUnk_Sio_085C98F4
_08035A40: .4byte 0x0300456C
_08035A44:
	ldr r0, _08035A70 @ =gUnk_Sio_085C98F4
	ldr r1, [r0]
	movs r0, #6
	ldrsb r0, [r1, r0]
	cmp r0, #0
	beq _08035A52
	b _08035C42
_08035A52:
	movs r2, #0x15
	ldrb r3, [r1]
	ldrb r5, [r5, #2]
	cmp r3, r5
	beq _08035A5E
	movs r2, #0x17
_08035A5E:
	ldr r0, _08035A74 @ =0x0300456C
	strb r2, [r0]
	ldrb r1, [r1, #6]
_08035A64:
	strb r1, [r0, #1]
	strh r7, [r0, #2]
_08035A68:
	movs r1, #4
	bl sub_8035DC8
	b _08035C42
	.align 2, 0
_08035A70: .4byte gUnk_Sio_085C98F4
_08035A74: .4byte 0x0300456C
_08035A78:
	ldr r0, [r5]
	adds r5, r0, #0
	adds r5, #0x32
	ldrb r0, [r5]
	subs r0, #0x14
	cmp r0, #0xa
	bls _08035A88
	b _08035C42
_08035A88:
	lsls r0, r0, #2
	ldr r1, _08035A94 @ =_08035A98
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08035A94: .4byte _08035A98
_08035A98: @ jump table
	.4byte _08035C38 @ case 0
	.4byte _08035BD0 @ case 1
	.4byte _08035BFC @ case 2
	.4byte _08035B8C @ case 3
	.4byte _08035C42 @ case 4
	.4byte _08035AC4 @ case 5
	.4byte _08035C42 @ case 6
	.4byte _08035C42 @ case 7
	.4byte _08035C42 @ case 8
	.4byte _08035C42 @ case 9
	.4byte _08035ADC @ case 10
_08035AC4:
	ldr r0, _08035AD8 @ =gUnk_Sio_085C98F4
	ldr r1, [r0]
	movs r0, #1
	ldrb r5, [r5, #1]
	lsls r0, r5
	ldrb r4, [r1, #0xa]
	orrs r0, r4
	strb r0, [r1, #0xa]
	b _08035C3E
	.align 2, 0
_08035AD8: .4byte gUnk_Sio_085C98F4
_08035ADC:
	ldr r6, _08035B80 @ =gUnk_Sio_085C98F4
	ldr r3, [r6]
	adds r0, r3, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	adds r7, #1
	mov r8, r7
	cmp r0, #0
	bne _08035AF0
	b _08035C42
_08035AF0:
	ldrb r2, [r5, #1]
	lsrs r4, r2, #4
	movs r1, #6
	ldrsb r1, [r3, r1]
	cmp r4, r1
	bne _08035AFE
	b _08035C42
_08035AFE:
	movs r0, #0xf
	ands r0, r2
	cmp r0, r1
	beq _08035B08
	b _08035C42
_08035B08:
	ldrh r0, [r3, #0x24]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r5, [r5, #2]
	cmp r5, r0
	beq _08035B18
	b _08035C42
_08035B18:
	movs r0, #1
	lsls r0, r4
	ldrb r1, [r3, #0xf]
	orrs r0, r1
	strb r0, [r3, #0xf]
	ldr r0, _08035B84 @ =0x030013C0
	ldr r1, [r0]
	ldr r0, [r6]
	ldrb r0, [r0, #0xf]
	strb r0, [r1]
	ldr r4, [r6]
	ldrb r0, [r4, #9]
	ldrb r2, [r4, #0xf]
	ands r0, r2
	ldrb r3, [r4, #9]
	cmp r0, r3
	beq _08035B3C
	b _08035C42
_08035B3C:
	ldrh r0, [r4, #0x24]
	adds r0, #1
	movs r3, #0
	strh r0, [r4, #0x24]
	ldr r2, _08035B88 @ =0x00001B74
	adds r1, r4, r2
	movs r0, #0x8c
	ldrb r1, [r1]
	muls r0, r1, r0
	adds r0, r4, r0
	movs r4, #0x9c
	lsls r4, r4, #1
	adds r0, r0, r4
	strb r3, [r0]
	ldr r0, [r6]
	adds r0, r0, r2
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	ldr r1, [r6]
	adds r1, r1, r2
	movs r0, #0x1f
	ldrb r2, [r1]
	ands r0, r2
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, #0x2e
	strb r3, [r0]
	ldr r0, [r6]
	strb r3, [r0, #0xf]
	strb r3, [r0, #0x11]
	strb r3, [r0, #0x10]
	b _08035C42
	.align 2, 0
_08035B80: .4byte gUnk_Sio_085C98F4
_08035B84: .4byte 0x030013C0
_08035B88: .4byte 0x00001B74
_08035B8C:
	ldrb r0, [r5, #2]
	bl sub_8035CB0
	lsls r0, r0, #0x18
	adds r7, #1
	mov r8, r7
	cmp r0, #0
	bne _08035C42
	ldr r3, _08035BCC @ =gUnk_Sio_085C98F4
	ldr r0, [r3]
	movs r1, #6
	ldrsb r1, [r0, r1]
	adds r0, #0xb
	adds r0, r0, r1
	movs r2, #2
	strb r2, [r0]
	ldr r1, [r3]
	movs r0, #0x30
	ldrh r4, [r1, #2]
	ands r0, r4
	lsrs r0, r0, #4
	adds r1, #0xb
	adds r1, r1, r0
	strb r2, [r1]
	ldr r0, [r3]
	adds r0, #0xb
	ldrh r5, [r5, #2]
	adds r0, r5, r0
	strb r2, [r0]
	ldr r1, [r3]
	b _08035BF0
	.align 2, 0
_08035BCC: .4byte gUnk_Sio_085C98F4
_08035BD0:
	ldrb r0, [r5, #2]
	bl sub_8035CB0
	lsls r0, r0, #0x18
	adds r7, #1
	mov r8, r7
	cmp r0, #0
	bne _08035C42
	ldr r2, _08035BF8 @ =gUnk_Sio_085C98F4
	ldr r0, [r2]
	adds r0, #0xb
	ldrh r5, [r5, #2]
	adds r0, r5, r0
	movs r1, #2
	strb r1, [r0]
	ldr r1, [r2]
_08035BF0:
	movs r0, #6
	strh r0, [r1, #4]
	b _08035C42
	.align 2, 0
_08035BF8: .4byte gUnk_Sio_085C98F4
_08035BFC:
	ldr r0, _08035C30 @ =0x0203C618
	adds r0, #0x9c
	ldrh r1, [r5, #2]
	adds r0, r1, r0
	movs r4, #0
	movs r2, #1
	strb r2, [r0]
	ldr r3, _08035C34 @ =gUnk_Sio_085C98F4
	ldr r0, [r3]
	adds r0, #0xb
	ldrh r1, [r5, #2]
	adds r0, r1, r0
	movs r1, #5
	strb r1, [r0]
	ldr r0, [r3]
	ldrh r1, [r5, #2]
	lsls r2, r1
	ldrb r1, [r0, #9]
	orrs r2, r1
	strb r2, [r0, #9]
	ldr r0, [r3]
	adds r0, #0x1a
	ldrh r5, [r5, #2]
	adds r0, r5, r0
	strb r4, [r0]
	b _08035C3E
	.align 2, 0
_08035C30: .4byte 0x0203C618
_08035C34: .4byte gUnk_Sio_085C98F4
_08035C38:
	ldrb r0, [r5, #1]
	bl sub_80358A4
_08035C3E:
	adds r7, #1
	mov r8, r7
_08035C42:
	mov r7, r8
	cmp r7, #3
	bgt _08035C4A
	b _080358FC
_08035C4A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start nullsub_16
nullsub_16: @ 0x08035C54
	bx lr
	.align 2, 0

	thumb_func_start sub_8035C58
sub_8035C58: @ 0x08035C58
	push {r4, r5, lr}
	movs r5, #0
	movs r4, #0
_08035C5E:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl sub_8035CB0
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _08035C74
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_08035C74:
	adds r4, #1
	cmp r4, #3
	ble _08035C5E
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_8035C84
sub_8035C84: @ 0x08035C84
	push {r4, r5, lr}
	movs r5, #0
	movs r4, #0
_08035C8A:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl sub_8035CD4
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _08035CA0
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_08035CA0:
	adds r4, #1
	cmp r4, #3
	ble _08035C8A
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_8035CB0
sub_8035CB0: @ 0x08035CB0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08035CCC @ =gUnk_Sio_085C98F4
	ldr r1, [r1]
	ldrb r1, [r1, #9]
	asrs r1, r0
	adds r0, r1, #0
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08035CD0
	movs r0, #0
	b _08035CD2
	.align 2, 0
_08035CCC: .4byte gUnk_Sio_085C98F4
_08035CD0:
	movs r0, #1
_08035CD2:
	bx lr

	thumb_func_start sub_8035CD4
sub_8035CD4: @ 0x08035CD4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08035CF0 @ =gUnk_Sio_085C98F4
	ldr r1, [r1]
	ldrb r1, [r1, #8]
	asrs r1, r0
	adds r0, r1, #0
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08035CF4
	movs r0, #0
	b _08035CF6
	.align 2, 0
_08035CF0: .4byte gUnk_Sio_085C98F4
_08035CF4:
	movs r0, #1
_08035CF6:
	bx lr

	thumb_func_start sub_8035CF8
sub_8035CF8: @ 0x08035CF8
	push {r4, lr}
	ldr r2, _08035D24 @ =gUnk_Sio_085C98F4
	ldr r3, [r2]
	ldrh r1, [r3, #2]
	movs r0, #0
	strh r0, [r3, #2]
	movs r4, #8
	ands r1, r4
	cmp r1, #0
	bne _08035D2C
	ldr r0, _08035D28 @ =0x04000128
	ldrh r1, [r0]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _08035D2C
	adds r1, r3, #0
	adds r1, #0x20
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08035D34
	.align 2, 0
_08035D24: .4byte gUnk_Sio_085C98F4
_08035D28: .4byte 0x04000128
_08035D2C:
	ldr r0, [r2]
	adds r0, #0x20
	movs r1, #0
	strb r1, [r0]
_08035D34:
	ldr r0, [r2]
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0xa
	bhi _08035D42
	movs r0, #1
	b _08035D44
_08035D42:
	movs r0, #0
_08035D44:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_8035D4C
sub_8035D4C: @ 0x08035D4C
	ldr r0, _08035D68 @ =gUnk_Sio_085C98F4
	ldr r0, [r0]
	ldr r2, _08035D6C @ =0x00001B75
	adds r1, r0, r2
	ldr r3, _08035D70 @ =0x00001B74
	adds r0, r0, r3
	ldrb r2, [r1]
	ldrb r3, [r0]
	cmp r2, r3
	bhs _08035D74
	adds r0, r3, #0
	subs r0, #0x20
	subs r0, r2, r0
	b _08035D7A
	.align 2, 0
_08035D68: .4byte gUnk_Sio_085C98F4
_08035D6C: .4byte 0x00001B75
_08035D70: .4byte 0x00001B74
_08035D74:
	ldrb r1, [r1]
	ldrb r0, [r0]
	subs r0, r1, r0
_08035D7A:
	bx lr

	thumb_func_start sub_8035D7C
sub_8035D7C: @ 0x08035D7C
	push {r4, lr}
	movs r2, #0
	movs r1, #0
	ldr r4, _08035DBC @ =gUnk_Sio_085C98F4
	ldr r0, [r4]
	adds r3, r0, #0
	adds r3, #0xb
_08035D8A:
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _08035D94
	adds r2, #1
_08035D94:
	adds r1, #1
	cmp r1, #3
	ble _08035D8A
	ldr r0, [r4]
	ldrb r0, [r0, #9]
	cmp r0, #3
	bne _08035DA6
	cmp r2, #2
	beq _08035DB6
_08035DA6:
	cmp r0, #7
	bne _08035DAE
	cmp r2, #3
	beq _08035DB6
_08035DAE:
	cmp r0, #0xf
	bne _08035DC0
	cmp r2, #4
	bne _08035DC0
_08035DB6:
	movs r0, #1
	b _08035DC2
	.align 2, 0
_08035DBC: .4byte gUnk_Sio_085C98F4
_08035DC0:
	movs r0, #0
_08035DC2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_8035DC8
sub_8035DC8: @ 0x08035DC8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	movs r0, #0
	mov r8, r0
	ldr r0, _08035E68 @ =0x030013CA
	ldrh r3, [r0]
	cmp r5, #0x80
	bhi _08035E60
	lsrs r5, r1, #0x11
	ldr r1, _08035E6C @ =0x00004FFF
	adds r4, r5, r1
	ldr r2, _08035E70 @ =0x0203B218
	lsls r0, r3, #1
	adds r0, r0, r2
	strh r1, [r0]
	adds r3, #1
	ldr r6, _08035E74 @ =0x000001FF
	ands r3, r6
	ldr r0, _08035E78 @ =0x030013C8
	ldrh r1, [r0]
	mov ip, r2
	mov sl, r0
	cmp r3, r1
	beq _08035E60
	lsls r0, r3, #1
	add r0, ip
	strh r5, [r0]
	adds r3, #1
	ands r3, r6
	lsls r6, r3, #1
	adds r7, r3, #1
	cmp r3, r1
	beq _08035E60
	movs r2, #0
	cmp r2, r5
	bge _08035E3C
	mov r3, sb
_08035E1E:
	adds r2, #1
	ldrh r0, [r3]
	adds r1, r0, #0
	muls r1, r2, r1
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	mvns r1, r1
	add r1, r8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	adds r3, #2
	cmp r2, r5
	blt _08035E1E
_08035E3C:
	mov r1, ip
	adds r0, r6, r1
	strh r4, [r0]
	ldr r4, _08035E74 @ =0x000001FF
	adds r3, r4, #0
	ands r3, r7
	mov r2, sl
	ldrh r1, [r2]
	cmp r3, r1
	beq _08035E60
	lsls r0, r3, #1
	add r0, ip
	mov r2, r8
	strh r2, [r0]
	adds r3, #1
	ands r3, r4
	cmp r3, r1
	bne _08035E7C
_08035E60:
	movs r0, #1
	rsbs r0, r0, #0
	b _08035EAC
	.align 2, 0
_08035E68: .4byte 0x030013CA
_08035E6C: .4byte 0x00004FFF
_08035E70: .4byte 0x0203B218
_08035E74: .4byte 0x000001FF
_08035E78: .4byte 0x030013C8
_08035E7C:
	movs r2, #0
	cmp r2, r5
	bge _08035EA4
	mov r8, ip
	adds r7, r4, #0
	mov r4, sb
	mov r6, sl
_08035E8A:
	lsls r0, r3, #1
	add r0, r8
	ldrh r1, [r4]
	strh r1, [r0]
	adds r3, #1
	ands r3, r7
	ldrh r0, [r6]
	cmp r3, r0
	beq _08035E60
	adds r4, #2
	adds r2, #1
	cmp r2, r5
	blt _08035E8A
_08035EA4:
	ldr r1, _08035EBC @ =0x030013CA
	strh r3, [r1]
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
_08035EAC:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08035EBC: .4byte 0x030013CA

	thumb_func_start sub_8035EC0
sub_8035EC0: @ 0x08035EC0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	str r1, [sp, #4]
	lsls r0, r0, #0x18
	movs r1, #0
	mov r8, r1
	movs r2, #0
	str r2, [sp, #0xc]
	ldr r1, _08035F38 @ =0x030013D0
	lsrs r3, r0, #0x18
	str r3, [sp]
	asrs r2, r0, #0x17
	adds r3, r2, r1
	ldr r0, _08035F3C @ =0x030013D8
	adds r7, r2, r0
	ldrh r5, [r7]
	mov sl, r1
	ldrh r0, [r3]
	cmp r0, r5
	beq _08035FC2
	ldr r1, _08035F40 @ =0x0203B618
	ldrh r4, [r3]
	lsls r0, r4, #3
	adds r0, r2, r0
	adds r0, r0, r1
	ldr r6, _08035F44 @ =0x00004FFF
	mov sb, r1
	ldrh r0, [r0]
	cmp r0, r6
	beq _08035F4C
	cmp r4, r5
	beq _08035F7A
	adds r4, r2, #0
	adds r2, r3, #0
	mov ip, r6
	adds r3, r7, #0
	ldr r6, _08035F48 @ =0x000001FF
	mov r5, sb
_08035F14:
	ldrh r0, [r2]
	adds r0, #1
	ands r0, r6
	strh r0, [r2]
	ldrh r1, [r2]
	lsls r0, r1, #3
	adds r0, r4, r0
	adds r0, r0, r5
	ldrh r0, [r0]
	cmp r0, ip
	bne _08035F30
	ldrh r7, [r3]
	cmp r1, r7
	bne _08035F4C
_08035F30:
	ldrh r0, [r3]
	cmp r1, r0
	bne _08035F14
	b _08035F7A
	.align 2, 0
_08035F38: .4byte 0x030013D0
_08035F3C: .4byte 0x030013D8
_08035F40: .4byte 0x0203B618
_08035F44: .4byte 0x00004FFF
_08035F48: .4byte 0x000001FF
_08035F4C:
	ldr r1, [sp]
	lsls r0, r1, #0x18
	asrs r1, r0, #0x17
	ldr r3, _08035F6C @ =0x030013D8
	adds r2, r1, r3
	add r1, sl
	ldrh r2, [r2]
	ldrh r1, [r1]
	adds r4, r0, #0
	cmp r2, r1
	bhs _08035F70
	movs r7, #0x80
	lsls r7, r7, #2
	adds r0, r2, r7
	subs r0, r0, r1
	b _08035F72
	.align 2, 0
_08035F6C: .4byte 0x030013D8
_08035F70:
	subs r0, r2, r1
_08035F72:
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #4
	bhi _08035F80
_08035F7A:
	movs r0, #4
	rsbs r0, r0, #0
	b _08036068
_08035F80:
	asrs r0, r4, #0x17
	add r0, sl
	ldrh r3, [r0]
	adds r3, #1
	ldr r0, _08035F94 @ =0x000001FF
	cmp r3, r0
	bgt _08035F98
	lsls r0, r3, #0x10
	lsrs r0, r0, #0x10
	b _08035F9A
	.align 2, 0
_08035F94: .4byte 0x000001FF
_08035F98:
	movs r0, #0
_08035F9A:
	asrs r4, r4, #0x17
	lsls r0, r0, #3
	adds r0, r4, r0
	add r0, sb
	ldrh r6, [r0]
	cmp r6, #0x80
	bls _08035FBC
	mov r1, sl
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r1, #1
	ldr r2, _08035FB8 @ =0x000001FF
	ands r1, r2
	strh r1, [r0]
	b _08035F7A
	.align 2, 0
_08035FB8: .4byte 0x000001FF
_08035FBC:
	adds r0, r6, #6
	cmp r0, r1
	ble _08035FC8
_08035FC2:
	movs r0, #2
	rsbs r0, r0, #0
	b _08036068
_08035FC8:
	mov r3, sl
	adds r2, r4, r3
	ldrh r0, [r2]
	adds r0, #2
	ldr r7, _0803605C @ =0x000001FF
	ands r0, r7
	strh r0, [r2]
	ldrh r1, [r2]
	lsls r0, r1, #3
	adds r0, r4, r0
	add r0, sb
	ldrh r0, [r0]
	str r0, [sp, #8]
	adds r1, #1
	ands r1, r7
	strh r1, [r2]
	ldrh r1, [r2]
	lsls r0, r1, #3
	adds r0, r4, r0
	add r0, sb
	ldrh r0, [r0]
	mov sl, r0
	adds r1, #1
	ands r1, r7
	strh r1, [r2]
	ldr r0, _08036060 @ =0x00004FFF
	add r0, r8
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	movs r3, #0
	cmp r3, r6
	bge _0803604A
	mov ip, r4
	adds r4, r2, #0
	ldr r5, [sp, #4]
_08036012:
	ldrh r7, [r4]
	lsls r0, r7, #3
	add r0, ip
	add r0, sb
	ldrh r2, [r0]
	adds r3, #1
	adds r1, r2, #0
	muls r1, r3, r1
	mov r7, r8
	adds r0, r7, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	mvns r1, r1
	ldr r0, [sp, #0xc]
	adds r1, r0, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0xc]
	strh r2, [r5]
	ldrh r0, [r4]
	adds r0, #1
	ldr r1, _0803605C @ =0x000001FF
	ands r0, r1
	strh r0, [r4]
	adds r5, #2
	cmp r3, r6
	blt _08036012
_0803604A:
	ldr r2, [sp, #8]
	cmp r8, r2
	bne _08036056
	ldr r3, [sp, #0xc]
	cmp r3, sl
	beq _08036064
_08036056:
	movs r0, #3
	rsbs r0, r0, #0
	b _08036068
	.align 2, 0
_0803605C: .4byte 0x000001FF
_08036060: .4byte 0x00004FFF
_08036064:
	lsls r0, r6, #0x11
	asrs r0, r0, #0x10
_08036068:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_8036078
sub_8036078: @ 0x08036078
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08036090 @ =gUnk_Sio_085C98F4
	ldr r3, [r0]
	movs r2, #6
	ldrsb r2, [r3, r2]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne _08036094
	adds r0, r2, #0
	b _080360B6
	.align 2, 0
_08036090: .4byte gUnk_Sio_085C98F4
_08036094:
	ldr r2, _080360BC @ =0x04000128
	ldrh r0, [r4]
	strh r0, [r2, #2]
	movs r0, #6
	ldrsb r0, [r3, r0]
	cmp r0, #0
	bne _080360B4
	cmp r1, #0
	bge _080360B4
	ldr r1, _080360C0 @ =0x030013B8
	movs r3, #0xc1
	lsls r3, r3, #7
	adds r0, r3, #0
	ldrb r1, [r1]
	orrs r0, r1
	strh r0, [r2]
_080360B4:
	movs r0, #0
_080360B6:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080360BC: .4byte 0x04000128
_080360C0: .4byte 0x030013B8

	thumb_func_start sub_80360C4
sub_80360C4: @ 0x080360C4
	push {r4, r5, r6, r7, lr}
	adds r2, r1, #0
	ldr r1, _080360EC @ =0x030013D0
	ldr r0, _080360F0 @ =0x030013D8
	ldrh r3, [r1]
	ldrh r0, [r0]
	cmp r3, r0
	bne _080360F8
	ldr r7, _080360F4 @ =0x00007FFF
	adds r0, r7, #0
	strh r0, [r2]
	adds r2, #2
	strh r0, [r2]
	adds r2, #2
	strh r0, [r2]
	strh r0, [r2, #2]
	movs r0, #2
	rsbs r0, r0, #0
	b _08036122
	.align 2, 0
_080360EC: .4byte 0x030013D0
_080360F0: .4byte 0x030013D8
_080360F4: .4byte 0x00007FFF
_080360F8:
	movs r4, #0
	ldr r6, _08036128 @ =0x0203B618
	ldr r5, _0803612C @ =0x000001FF
	adds r3, r1, #0
_08036100:
	lsls r0, r4, #1
	ldrh r7, [r3]
	lsls r1, r7, #3
	adds r0, r0, r1
	adds r0, r0, r6
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	ldrh r0, [r3]
	adds r0, #1
	ands r0, r5
	strh r0, [r3]
	adds r3, #2
	adds r4, #1
	cmp r4, #3
	ble _08036100
	movs r0, #0
_08036122:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08036128: .4byte 0x0203B618
_0803612C: .4byte 0x000001FF

	thumb_func_start sub_8036130
sub_8036130: @ 0x08036130
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r3, _08036198 @ =gUnk_Sio_085C98F4
	ldr r2, [r3]
	ldr r0, _0803619C @ =0x00001B77
	adds r1, r2, r0
	movs r0, #0x8c
	ldrb r1, [r1]
	muls r0, r1, r0
	ldr r1, _080361A0 @ =0x000012B4
	adds r0, r0, r1
	adds r1, r2, r0
	ldrb r0, [r4]
	strb r0, [r1, #4]
	ldrb r0, [r4, #1]
	strb r0, [r1, #5]
	ldrh r0, [r4, #2]
	strh r0, [r1, #6]
	ldrh r0, [r4, #4]
	strh r0, [r1, #8]
	movs r2, #0
	adds r6, r3, #0
	ldrh r0, [r4, #4]
	cmp r2, r0
	bge _08036178
	adds r5, r1, #0
	adds r5, #0xa
	adds r3, r4, #6
_08036168:
	adds r0, r5, r2
	adds r1, r3, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	ldrh r1, [r4, #4]
	cmp r2, r1
	blt _08036168
_08036178:
	ldr r0, [r6]
	ldr r2, _0803619C @ =0x00001B77
	adds r0, r0, r2
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	ldr r1, [r6]
	adds r1, r1, r2
	movs r0, #0xf
	ldrb r2, [r1]
	ands r0, r2
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08036198: .4byte gUnk_Sio_085C98F4
_0803619C: .4byte 0x00001B77
_080361A0: .4byte 0x000012B4

	thumb_func_start sub_80361A4
sub_80361A4: @ 0x080361A4
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r0, _080361F4 @ =gUnk_Sio_085C98F4
	ldr r3, [r0]
	ldr r0, _080361F8 @ =0x00001B74
	adds r4, r3, r0
	movs r6, #0x8c
	ldrb r1, [r4]
	adds r5, r1, #0
	muls r5, r6, r5
	adds r0, r3, r5
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x1f
	bne _08036200
	ldr r1, _080361FC @ =0x030013C0
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r0, r3, r0
	str r0, [r1]
	ldrb r1, [r4]
	adds r0, r1, #0
	muls r0, r6, r0
	adds r0, r3, r0
	movs r1, #0x9e
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	str r0, [r7]
	ldrb r4, [r4]
	adds r0, r4, #0
	muls r0, r6, r0
	adds r0, r0, r2
	adds r0, r3, r0
	adds r0, #4
	b _08036202
	.align 2, 0
_080361F4: .4byte gUnk_Sio_085C98F4
_080361F8: .4byte 0x00001B74
_080361FC: .4byte 0x030013C0
_08036200:
	movs r0, #0
_08036202:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_8036208
sub_8036208: @ 0x08036208
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov ip, r0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	ldr r6, _080362A4 @ =0x030013C4
	movs r0, #1
	str r0, [r6]
	ldr r4, _080362A8 @ =gUnk_Sio_085C98F4
	ldr r1, [r4]
	ldr r2, _080362AC @ =0x00001B75
	adds r0, r1, r2
	movs r5, #0x8c
	ldrb r0, [r0]
	muls r0, r5, r0
	adds r1, r1, r0
	movs r3, #0x9a
	lsls r3, r3, #1
	adds r1, r1, r3
	movs r0, #0
	strb r0, [r1]
	ldr r1, [r4]
	adds r2, r1, r2
	ldrb r2, [r2]
	adds r0, r2, #0
	muls r0, r5, r0
	adds r0, r0, r3
	adds r5, r1, r0
	adds r2, r5, #4
	movs r0, #0x1f
	strb r0, [r5, #4]
	ldr r0, [r4]
	ldrb r0, [r0, #6]
	strb r0, [r2, #1]
	ldr r1, [r4]
	ldrh r0, [r1, #0x22]
	strh r0, [r2, #2]
	strh r7, [r2, #4]
	ldrh r0, [r1, #0x22]
	adds r0, #1
	strh r0, [r1, #0x22]
	movs r3, #0
	mov r8, r6
	adds r6, r4, #0
	cmp r3, r7
	bhs _0803627C
	adds r2, #6
_08036268:
	adds r1, r2, r3
	mov r4, ip
	adds r0, r4, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, r7
	blo _08036268
_0803627C:
	ldr r1, [r6]
	ldr r3, _080362AC @ =0x00001B75
	adds r1, r1, r3
	ldrb r0, [r1]
	adds r2, r0, #1
	movs r4, #0
	strb r2, [r1]
	ldr r2, [r6]
	adds r2, r2, r3
	movs r1, #0x1f
	ldrb r3, [r2]
	ands r1, r3
	strb r1, [r2]
	mov r1, r8
	str r4, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080362A4: .4byte 0x030013C4
_080362A8: .4byte gUnk_Sio_085C98F4
_080362AC: .4byte 0x00001B75

	thumb_func_start sub_80362B0
sub_80362B0: @ 0x080362B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sb, r0
	str r1, [sp]
	mov sl, r2
_080362C2:
	ldr r0, _080362F0 @ =gUnk_Sio_085C98F4
	mov r8, r0
	ldr r2, [r0]
	ldr r7, _080362F4 @ =0x00001B76
	adds r1, r2, r7
	movs r0, #0x8c
	ldrb r1, [r1]
	muls r0, r1, r0
	ldr r1, _080362F8 @ =0x000012B4
	adds r0, r0, r1
	adds r5, r2, r0
	adds r6, r5, #4
	ldrb r3, [r5, #4]
	cmp r3, #0x1f
	bne _080362EA
	ldrb r0, [r6, #1]
	ldrb r1, [r6, #1]
	ldrb r3, [r2, #6]
	cmp r1, r3
	bne _080362FC
_080362EA:
	movs r0, #0
	b _08036424
	.align 2, 0
_080362F0: .4byte gUnk_Sio_085C98F4
_080362F4: .4byte 0x00001B76
_080362F8: .4byte 0x000012B4
_080362FC:
	lsls r0, r0, #1
	adds r3, r2, #0
	adds r3, #0x26
	adds r0, r3, r0
	ldrh r1, [r6, #2]
	ldrh r0, [r0]
	cmp r1, r0
	beq _08036348
	ldr r0, _08036344 @ =0x0300456C
	movs r1, #0x1e
	strb r1, [r0]
	ldrb r2, [r2, #6]
	lsls r1, r2, #4
	ldrb r2, [r6, #1]
	orrs r1, r2
	strb r1, [r0, #1]
	ldrb r6, [r6, #1]
	lsls r1, r6, #1
	adds r1, r3, r1
	ldrh r1, [r1]
	movs r4, #0
	strh r1, [r0, #2]
	movs r1, #4
	bl sub_8035DC8
	strb r4, [r5, #4]
	mov r3, r8
	ldr r0, [r3]
	adds r0, r0, r7
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	ldr r1, [r3]
	adds r1, r1, r7
	b _080363B6
	.align 2, 0
_08036344: .4byte 0x0300456C
_08036348:
	movs r2, #0
	ldrh r3, [r6, #4]
	cmp r2, r3
	bhs _0803636A
	adds r3, r5, #0
	adds r3, #0xa
_08036354:
	mov r0, sb
	adds r1, r0, r2
	adds r0, r3, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldrh r1, [r6, #4]
	cmp r2, r1
	blo _08036354
_0803636A:
	mov r2, sl
	cmp r2, #0
	beq _080363CC
	mov r0, sb
	bl _call_via_sl
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080363CC
	ldr r0, _080363C0 @ =0x0300456C
	movs r1, #0x1e
	strb r1, [r0]
	ldr r4, _080363C4 @ =gUnk_Sio_085C98F4
	ldr r2, [r4]
	ldrb r3, [r2, #6]
	lsls r1, r3, #4
	ldrb r3, [r6, #1]
	orrs r1, r3
	strb r1, [r0, #1]
	ldrb r3, [r6, #1]
	lsls r1, r3, #1
	adds r2, #0x26
	adds r2, r2, r1
	ldrh r1, [r2]
	movs r5, #0
	strh r1, [r0, #2]
	movs r1, #4
	bl sub_8035DC8
	strb r5, [r6]
	ldr r0, [r4]
	ldr r2, _080363C8 @ =0x00001B76
	adds r0, r0, r2
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	ldr r1, [r4]
	adds r1, r1, r2
_080363B6:
	movs r0, #0xf
	ldrb r2, [r1]
	ands r0, r2
	strb r0, [r1]
	b _080362C2
	.align 2, 0
_080363C0: .4byte 0x0300456C
_080363C4: .4byte gUnk_Sio_085C98F4
_080363C8: .4byte 0x00001B76
_080363CC:
	movs r0, #0
	strb r0, [r6]
	ldrb r5, [r6, #1]
	ldr r4, _08036434 @ =gUnk_Sio_085C98F4
	ldr r2, [r4]
	lsls r1, r5, #1
	adds r0, r2, #0
	adds r0, #0x26
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	ldr r3, _08036438 @ =0x00001B76
	adds r2, r2, r3
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldr r1, [r4]
	adds r1, r1, r3
	movs r0, #0xf
	ldrb r3, [r1]
	ands r0, r3
	strb r0, [r1]
	ldr r0, [sp]
	strb r5, [r0]
	ldr r0, _0803643C @ =0x0300456C
	movs r1, #0x1e
	strb r1, [r0]
	ldr r2, [r4]
	ldrb r3, [r2, #6]
	lsls r1, r3, #4
	ldrb r3, [r6, #1]
	orrs r1, r3
	strb r1, [r0, #1]
	ldrb r3, [r6, #1]
	lsls r1, r3, #1
	adds r2, #0x26
	adds r2, r2, r1
	ldrh r1, [r2]
	strh r1, [r0, #2]
	movs r1, #4
	bl sub_8035DC8
	ldrh r0, [r6, #4]
_08036424:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08036434: .4byte gUnk_Sio_085C98F4
_08036438: .4byte 0x00001B76
_0803643C: .4byte 0x0300456C

	thumb_func_start sub_8036440
sub_8036440: @ 0x08036440
	push {lr}
	sub sp, #4
	ldr r1, _0803647C @ =0x00007FFF
	mov r0, sp
	strh r1, [r0]
	ldr r0, _08036480 @ =gUnk_Sio_085C98F4
	ldr r1, [r0]
	movs r0, #0
	strb r0, [r1, #1]
	mov r0, sp
	movs r1, #1
	bl sub_8036078
	ldr r1, _08036484 @ =0x030013CA
	ldr r0, _08036488 @ =0x030013C8
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r3, _0803648C @ =0x030013D0
	ldr r2, _08036490 @ =0x030013D8
	movs r1, #3
_08036468:
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, #2
	adds r2, #2
	subs r1, #1
	cmp r1, #0
	bge _08036468
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_0803647C: .4byte 0x00007FFF
_08036480: .4byte gUnk_Sio_085C98F4
_08036484: .4byte 0x030013CA
_08036488: .4byte 0x030013C8
_0803648C: .4byte 0x030013D0
_08036490: .4byte 0x030013D8

	thumb_func_start sub_8036494
sub_8036494: @ 0x08036494
	ldr r1, _080364A0 @ =gUnk_Sio_085C98F4
	ldr r1, [r1]
	adds r1, #0x21
	strb r0, [r1]
	bx lr
	.align 2, 0
_080364A0: .4byte gUnk_Sio_085C98F4

	thumb_func_start sub_80364A4
sub_80364A4: @ 0x080364A4
	push {lr}
	sub sp, #4
	ldr r1, _080364F8 @ =0x00007FFF
	mov r0, sp
	strh r1, [r0]
	ldr r1, _080364FC @ =gUnk_Sio_085C98F4
	ldr r0, [r1]
	movs r2, #0
	strb r2, [r0, #1]
	ldr r0, [r1]
	ldr r1, _08036500 @ =0x00001B7C
	adds r0, r0, r1
	strh r2, [r0]
	mov r0, sp
	movs r1, #1
	bl sub_8036078
	ldr r1, _08036504 @ =0x030013CA
	ldr r0, _08036508 @ =0x030013C8
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r3, _0803650C @ =0x030013D0
	ldr r2, _08036510 @ =0x030013D8
	movs r1, #3
_080364D4:
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, #2
	adds r2, #2
	subs r1, #1
	cmp r1, #0
	bge _080364D4
	ldr r0, _080364FC @ =gUnk_Sio_085C98F4
	ldr r2, [r0]
	ldr r0, _08036514 @ =0x00001B7E
	adds r1, r2, r0
	movs r0, #0
	strh r0, [r1]
	movs r0, #3
	strb r0, [r2, #1]
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_080364F8: .4byte 0x00007FFF
_080364FC: .4byte gUnk_Sio_085C98F4
_08036500: .4byte 0x00001B7C
_08036504: .4byte 0x030013CA
_08036508: .4byte 0x030013C8
_0803650C: .4byte 0x030013D0
_08036510: .4byte 0x030013D8
_08036514: .4byte 0x00001B7E

	thumb_func_start sub_8036518
sub_8036518: @ 0x08036518
	push {r4, lr}
	sub sp, #4
	ldr r1, _08036574 @ =0x00002586
	mov r0, sp
	strh r1, [r0]
	ldr r3, _08036578 @ =gUnk_Sio_085C98F4
	ldr r1, [r3]
	movs r2, #0
	movs r0, #0
	strh r0, [r1, #4]
	strb r2, [r1, #1]
	ldr r0, [r3]
	ldr r1, _0803657C @ =0x00001B7C
	adds r0, r0, r1
	movs r1, #0x88
	strh r1, [r0]
	ldr r1, _08036580 @ =0x030013CA
	ldr r0, _08036584 @ =0x030013C8
	ldrh r0, [r0]
	strh r0, [r1]
	adds r4, r3, #0
	ldr r3, _08036588 @ =0x030013D0
	ldr r2, _0803658C @ =0x030013D8
	movs r1, #3
_08036548:
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, #2
	adds r2, #2
	subs r1, #1
	cmp r1, #0
	bge _08036548
	ldr r1, [r4]
	movs r0, #1
	strb r0, [r1, #1]
	ldr r1, [r4]
	movs r0, #6
	strh r0, [r1, #4]
	movs r1, #1
	rsbs r1, r1, #0
	mov r0, sp
	bl sub_8036078
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08036574: .4byte 0x00002586
_08036578: .4byte gUnk_Sio_085C98F4
_0803657C: .4byte 0x00001B7C
_08036580: .4byte 0x030013CA
_08036584: .4byte 0x030013C8
_08036588: .4byte 0x030013D0
_0803658C: .4byte 0x030013D8

	thumb_func_start sub_8036590
sub_8036590: @ 0x08036590
	push {r4, lr}
	sub sp, #4
	ldr r1, _080365EC @ =0x00002586
	mov r0, sp
	strh r1, [r0]
	ldr r3, _080365F0 @ =gUnk_Sio_085C98F4
	ldr r1, [r3]
	movs r2, #0
	movs r0, #0
	strh r0, [r1, #4]
	strb r2, [r1, #1]
	ldr r0, [r3]
	ldr r1, _080365F4 @ =0x00001B7C
	adds r0, r0, r1
	movs r1, #0x18
	strh r1, [r0]
	ldr r1, _080365F8 @ =0x030013CA
	ldr r0, _080365FC @ =0x030013C8
	ldrh r0, [r0]
	strh r0, [r1]
	adds r4, r3, #0
	ldr r3, _08036600 @ =0x030013D0
	ldr r2, _08036604 @ =0x030013D8
	movs r1, #3
_080365C0:
	ldrh r0, [r3]
	strh r0, [r2]
	adds r3, #2
	adds r2, #2
	subs r1, #1
	cmp r1, #0
	bge _080365C0
	ldr r1, [r4]
	movs r0, #1
	strb r0, [r1, #1]
	ldr r1, [r4]
	movs r0, #6
	strh r0, [r1, #4]
	movs r1, #1
	rsbs r1, r1, #0
	mov r0, sp
	bl sub_8036078
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080365EC: .4byte 0x00002586
_080365F0: .4byte gUnk_Sio_085C98F4
_080365F4: .4byte 0x00001B7C
_080365F8: .4byte 0x030013CA
_080365FC: .4byte 0x030013C8
_08036600: .4byte 0x030013D0
_08036604: .4byte 0x030013D8

	thumb_func_start sub_8036608
sub_8036608: @ 0x08036608
	ldr r0, _08036614 @ =0x030013CA
	ldr r1, _08036618 @ =0x030013C8
	ldrh r1, [r1]
	strh r1, [r0]
	bx lr
	.align 2, 0
_08036614: .4byte 0x030013CA
_08036618: .4byte 0x030013C8

	thumb_func_start sub_803661C
sub_803661C: @ 0x0803661C
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r5, _08036678 @ =gUnk_Sio_085C98F4
	ldr r1, [r5]
	adds r2, r1, #0
	adds r2, #0x2e
	movs r0, #0
	strb r0, [r2]
	strh r0, [r1, #0x22]
	strh r0, [r1, #0x24]
	ldr r1, [r5]
	strh r0, [r1, #0x2c]
	strh r0, [r1, #0x2a]
	strh r0, [r1, #0x28]
	strh r0, [r1, #0x26]
	bl sub_803522C
	mov r1, sp
	adds r0, r4, #0
	adds r0, #0x34
	ldrb r0, [r0]
	strb r0, [r1]
	mov r2, sp
	ldrh r1, [r4, #0x36]
	lsrs r0, r1, #8
	strb r0, [r2, #1]
	mov r0, sp
	strb r1, [r0, #2]
	mov r1, sp
	adds r4, #0x3a
	ldrb r0, [r4]
	strb r0, [r1, #3]
	mov r0, sp
	movs r1, #4
	bl sub_8036208
	ldr r0, [r5]
	adds r0, #0x2e
	movs r1, #1
	strb r1, [r0]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08036678: .4byte gUnk_Sio_085C98F4

	thumb_func_start sub_803667C
sub_803667C: @ 0x0803667C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x2c]
	cmp r1, #0
	beq _0803668A
	bl _call_via_r1
_0803668A:
	ldr r5, _080366E8 @ =gUnk_Sio_085C98F4
	ldr r1, [r5]
	adds r0, r1, #0
	adds r0, #0x2e
	ldrb r6, [r0]
	cmp r6, #0
	bne _080366E0
	ldrh r2, [r4, #0x38]
	ldrh r0, [r1, #0x24]
	subs r0, #1
	cmp r2, r0
	beq _080366BE
	ldr r0, [r4, #0x30]
	adds r0, #0x7a
	str r0, [r4, #0x30]
	movs r0, #0x64
	muls r0, r2, r0
	ldrh r1, [r4, #0x36]
	bl __divsi3
	adds r1, r4, #0
	adds r1, #0x3b
	strb r0, [r1]
	ldrh r0, [r4, #0x38]
	adds r0, #1
	strh r0, [r4, #0x38]
_080366BE:
	ldr r0, [r4, #0x30]
	movs r1, #0x7a
	bl sub_8036208
	ldr r0, [r5]
	adds r0, #0x2e
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r5]
	strb r6, [r0, #0x10]
	ldrh r0, [r4, #0x38]
	ldrh r1, [r4, #0x36]
	cmp r0, r1
	blo _080366E0
	adds r0, r4, #0
	bl Proc_Break
_080366E0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080366E8: .4byte gUnk_Sio_085C98F4

	thumb_func_start sub_80366EC
sub_80366EC: @ 0x080366EC
	push {lr}
	ldr r2, _08036710 @ =gUnk_Sio_085C98F4
	ldr r1, [r2]
	adds r3, r1, #0
	adds r3, #0x2e
	movs r0, #0
	strb r0, [r3]
	strh r0, [r1, #0x22]
	strh r0, [r1, #0x24]
	ldr r1, [r2]
	strh r0, [r1, #0x2c]
	strh r0, [r1, #0x2a]
	strh r0, [r1, #0x28]
	strh r0, [r1, #0x26]
	bl sub_803522C
	pop {r0}
	bx r0
	.align 2, 0
_08036710: .4byte gUnk_Sio_085C98F4

	thumb_func_start sub_8036714
sub_8036714: @ 0x08036714
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	add r1, sp, #4
	mov r0, sp
	movs r2, #0
	bl sub_80362B0
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08036750
	mov r0, sp
	ldrb r1, [r0]
	adds r0, r4, #0
	adds r0, #0x34
	strb r1, [r0]
	mov r0, sp
	ldrb r1, [r0, #1]
	lsls r1, r1, #8
	ldrb r0, [r0, #2]
	adds r0, r0, r1
	strh r0, [r4, #0x36]
	mov r0, sp
	ldrb r0, [r0, #3]
	adds r1, r4, #0
	adds r1, #0x3a
	strb r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
_08036750:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_8036758
sub_8036758: @ 0x08036758
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r5, _08036794 @ =gBuf
	ldrh r0, [r4, #0x36]
	subs r0, #1
	ldrh r1, [r4, #0x38]
	cmp r1, r0
	bge _08036798
	ldr r0, [r4, #0x30]
	mov r1, sp
	movs r2, #0
	bl sub_80362B0
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080367E2
	ldr r0, [r4, #0x30]
	adds r0, #0x7a
	str r0, [r4, #0x30]
	movs r0, #0x64
	ldrh r1, [r4, #0x38]
	muls r0, r1, r0
	ldrh r1, [r4, #0x36]
	bl __divsi3
	adds r1, r4, #0
	adds r1, #0x3b
	strb r0, [r1]
	b _080367DC
	.align 2, 0
_08036794: .4byte gBuf
_08036798:
	adds r0, r5, #0
	mov r1, sp
	movs r2, #0
	bl sub_80362B0
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080367E2
	movs r2, #0
	adds r3, r4, #0
	adds r3, #0x3a
	adds r6, r4, #0
	adds r6, #0x3b
	ldrb r0, [r3]
	cmp r2, r0
	bge _080367CE
_080367B8:
	ldr r1, [r4, #0x30]
	adds r0, r5, r2
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, [r4, #0x30]
	adds r0, #1
	str r0, [r4, #0x30]
	adds r2, #1
	ldrb r1, [r3]
	cmp r2, r1
	blt _080367B8
_080367CE:
	movs r0, #0x64
	ldrh r1, [r4, #0x38]
	muls r0, r1, r0
	ldrh r1, [r4, #0x36]
	bl __divsi3
	strb r0, [r6]
_080367DC:
	ldrh r0, [r4, #0x38]
	adds r0, #1
	strh r0, [r4, #0x38]
_080367E2:
	ldr r1, [r4, #0x2c]
	cmp r1, #0
	beq _080367EE
	adds r0, r4, #0
	bl _call_via_r1
_080367EE:
	ldrh r0, [r4, #0x38]
	ldrh r1, [r4, #0x36]
	cmp r0, r1
	blo _080367FC
	adds r0, r4, #0
	bl Proc_Break
_080367FC:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_8036804
sub_8036804: @ 0x08036804
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r4, r1, #0
	mov r8, r2
	lsls r3, r3, #0x18
	lsrs r6, r3, #0x18
	ldr r0, _08036820 @ =0x0079FF86
	cmp r4, r0
	bls _08036824
	movs r0, #1
	rsbs r0, r0, #0
	b _08036876
	.align 2, 0
_08036820: .4byte 0x0079FF86
_08036824:
	adds r0, r4, #0
	movs r1, #0x7a
	bl __udivsi3
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r4, #0
	movs r1, #0x7a
	bl __umodsi3
	adds r4, r0, #0
	cmp r4, #0
	beq _08036846
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
_08036846:
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r0, _08036880 @ =gUnk_Sio_085C98F8
	ldr r1, [sp, #0x18]
	bl SpawnProcLocking
	adds r3, r0, #0
	str r7, [r3, #0x30]
	adds r0, #0x34
	movs r2, #0
	strb r6, [r0]
	mov r0, r8
	str r0, [r3, #0x2c]
	movs r1, #0
	strh r5, [r3, #0x36]
	adds r0, r3, #0
	adds r0, #0x3a
	strb r4, [r0]
	adds r0, #1
	strb r1, [r0]
	strh r2, [r3, #0x38]
	adds r0, #1
	strb r1, [r0]
	movs r0, #0
_08036876:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08036880: .4byte gUnk_Sio_085C98F8

	thumb_func_start sub_8036884
sub_8036884: @ 0x08036884
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r1, r2, #0
	ldr r0, _080368AC @ =gUnk_Sio_085C9918
	bl SpawnProcLocking
	str r4, [r0, #0x2c]
	str r5, [r0, #0x30]
	adds r2, r0, #0
	adds r2, #0x3b
	movs r1, #0
	strb r1, [r2]
	movs r2, #0
	strh r1, [r0, #0x38]
	adds r0, #0x3c
	strb r2, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080368AC: .4byte gUnk_Sio_085C9918

	thumb_func_start sub_80368B0
sub_80368B0: @ 0x080368B0
	push {lr}
	ldr r0, _080368CC @ =gUnk_Sio_085C98F8
	bl Proc_Find
	cmp r0, #0
	bne _080368D4
	ldr r0, _080368D0 @ =gUnk_Sio_085C9918
	bl Proc_Find
	cmp r0, #0
	bne _080368D4
	movs r0, #0
	b _080368D6
	.align 2, 0
_080368CC: .4byte gUnk_Sio_085C98F8
_080368D0: .4byte gUnk_Sio_085C9918
_080368D4:
	movs r0, #1
_080368D6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_80368DC
sub_80368DC: @ 0x080368DC
	movs r3, #0
	b _080368E8
_080368E0:
	strb r2, [r1]
	adds r0, #1
	adds r1, #1
	adds r3, #1
_080368E8:
	ldrb r2, [r0]
	cmp r2, #0
	bne _080368E0
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r3, #0
	bx lr
	.align 2, 0

	thumb_func_start sub_80368F8
sub_80368F8: @ 0x080368F8
	push {lr}
	bl sub_8035414
	bl sub_80353AC
	ldr r2, _08036914 @ =gUnk_Sio_085C98F4
	ldr r1, [r2]
	movs r3, #0
	movs r0, #1
	strb r0, [r1, #1]
	ldr r0, [r2]
	strh r3, [r0, #4]
	pop {r0}
	bx r0
	.align 2, 0
_08036914: .4byte gUnk_Sio_085C98F4

	thumb_func_start sub_8036918
sub_8036918: @ 0x08036918
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _0803695C @ =0x00002586
	mov r1, sp
	strh r0, [r1]
	bl sub_80350C8
	movs r5, #1
	rsbs r5, r5, #0
	cmp r0, r5
	beq _08036954
	ldr r4, _08036960 @ =gUnk_Sio_085C98F4
	ldr r1, [r4]
	movs r0, #0
	strb r0, [r1, #0x11]
	ldr r1, [r4]
	movs r0, #5
	strh r0, [r1, #4]
	bl sub_80351E4
	ldr r1, [r4]
	strb r0, [r1, #6]
	mov r0, sp
	adds r1, r5, #0
	bl sub_8036078
	adds r0, r6, #0
	bl Proc_Break
_08036954:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803695C: .4byte 0x00002586
_08036960: .4byte gUnk_Sio_085C98F4

	thumb_func_start sub_8036964
sub_8036964: @ 0x08036964
	ldr r0, _08036970 @ =gBmSt
	movs r1, #0x40
	ldrb r2, [r0, #4]
	orrs r1, r2
	strb r1, [r0, #4]
	bx lr
	.align 2, 0
_08036970: .4byte gBmSt

	thumb_func_start sub_8036974
sub_8036974: @ 0x08036974
	ldr r1, _08036980 @ =gBmSt
	movs r0, #0xbf
	ldrb r2, [r1, #4]
	ands r0, r2
	strb r0, [r1, #4]
	bx lr
	.align 2, 0
_08036980: .4byte gBmSt

	thumb_func_start sub_8036984
sub_8036984: @ 0x08036984
	ldr r0, _08036990 @ =gBmSt
	ldrb r0, [r0, #4]
	lsrs r0, r0, #6
	movs r1, #1
	ands r0, r1
	bx lr
	.align 2, 0
_08036990: .4byte gBmSt

	thumb_func_start sub_8036994
sub_8036994: @ 0x08036994
	ldr r1, _0803699C @ =0x0203C618
	movs r0, #0xff
	strb r0, [r1, #4]
	bx lr
	.align 2, 0
_0803699C: .4byte 0x0203C618

	thumb_func_start sub_80369A0
sub_80369A0: @ 0x080369A0
	push {r4, lr}
	ldr r3, _080369D4 @ =gDispIo+0x3C
	ldr r1, _080369D8 @ =0x0000FFE0
	ldrh r2, [r3]
	ands r1, r2
	movs r2, #4
	orrs r1, r2
	ldr r2, _080369DC @ =0x0000E0FF
	ands r1, r2
	movs r4, #0xd8
	lsls r4, r4, #5
	adds r2, r4, #0
	orrs r1, r2
	strh r1, [r3]
	movs r1, #0x3f
	ldrb r2, [r3]
	ands r1, r2
	strb r1, [r3]
	movs r1, #0
	strb r1, [r3, #8]
	strb r1, [r3, #9]
	strb r1, [r3, #0xa]
	str r1, [r0, #0x58]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080369D4: .4byte gDispIo+0x3C
_080369D8: .4byte 0x0000FFE0
_080369DC: .4byte 0x0000E0FF

	thumb_func_start sub_80369E0
sub_80369E0: @ 0x080369E0
	push {r4, r5, lr}
	ldr r1, [r0, #0x58]
	adds r1, #1
	str r1, [r0, #0x58]
	movs r4, #0x3f
	adds r3, r4, #0
	ands r3, r1
	cmp r3, #0x1f
	ble _080369F6
	movs r0, #0x40
	subs r3, r0, r3
_080369F6:
	cmp r3, #0x10
	ble _080369FC
	movs r3, #0x10
_080369FC:
	ldr r2, _08036A34 @ =gDispIo+0x3C
	ldr r0, _08036A38 @ =0x0000FFE0
	ldrh r1, [r2]
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	ldr r1, _08036A3C @ =0x0000E0FF
	ands r0, r1
	movs r5, #0xd8
	lsls r5, r5, #5
	adds r1, r5, #0
	orrs r0, r1
	strh r0, [r2]
	adds r0, r4, #0
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	movs r1, #0
	strb r3, [r2, #8]
	movs r0, #0x10
	subs r0, r0, r3
	strb r0, [r2, #9]
	strb r1, [r2, #0xa]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08036A34: .4byte gDispIo+0x3C
_08036A38: .4byte 0x0000FFE0
_08036A3C: .4byte 0x0000E0FF

	thumb_func_start sub_8036A40
sub_8036A40: @ 0x08036A40
	ldr r0, _08036A50 @ =gDispIo
	ldrh r1, [r0, #0x20]
	adds r1, #1
	strh r1, [r0, #0x20]
	ldrh r1, [r0, #0x24]
	subs r1, #1
	strh r1, [r0, #0x24]
	bx lr
	.align 2, 0
_08036A50: .4byte gDispIo

	thumb_func_start sub_8036A54
sub_8036A54: @ 0x08036A54
	push {lr}
	adds r2, r0, #0
	ldr r0, _08036A74 @ =gUnk_Sio_085C98F4
	ldr r0, [r0]
	ldr r1, _08036A78 @ =0x00009ABC
	strh r1, [r0, #0x30]
	ldr r1, _08036A7C @ =0x00001B7E
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08036A70
	adds r0, r2, #0
	bl Proc_Break
_08036A70:
	pop {r0}
	bx r0
	.align 2, 0
_08036A74: .4byte gUnk_Sio_085C98F4
_08036A78: .4byte 0x00009ABC
_08036A7C: .4byte 0x00001B7E

	thumb_func_start sub_8036A80
sub_8036A80: @ 0x08036A80
	ldr r0, _08036A90 @ =gUnk_Sio_085C98F4
	ldr r2, [r0]
	movs r1, #6
	ldrsb r1, [r2, r1]
	movs r0, #1
	lsls r0, r1
	strb r0, [r2, #0xa]
	bx lr
	.align 2, 0
_08036A90: .4byte gUnk_Sio_085C98F4

	thumb_func_start sub_8036A94
sub_8036A94: @ 0x08036A94
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08036AD4 @ =0x0300456C
	movs r2, #0
	movs r1, #0x19
	strb r1, [r0]
	ldr r4, _08036AD8 @ =gUnk_Sio_085C98F4
	ldr r1, [r4]
	ldrb r1, [r1, #6]
	strb r1, [r0, #1]
	strh r2, [r0, #2]
	movs r1, #4
	bl sub_8035DC8
	ldr r4, [r4]
	ldrb r0, [r4, #9]
	ldrb r1, [r4, #0xa]
	ands r0, r1
	ldrb r1, [r4, #9]
	cmp r0, r1
	bne _08036ACE
	movs r1, #6
	ldrsb r1, [r4, r1]
	movs r0, #1
	lsls r0, r1
	strb r0, [r4, #0xa]
	adds r0, r5, #0
	bl Proc_Break
_08036ACE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08036AD4: .4byte 0x0300456C
_08036AD8: .4byte gUnk_Sio_085C98F4

	thumb_func_start sub_8036ADC
sub_8036ADC: @ 0x08036ADC
	push {lr}
	adds r2, r0, #0
	ldr r1, [r2, #0x30]
	ldr r0, [r2, #0x38]
	cmp r1, r0
	bge _08036AF4
	ldr r0, [r2, #0x34]
	cmp r1, r0
	ble _08036AF4
	ldr r0, [r2, #0x2c]
	bl sub_804163C
_08036AF4:
	pop {r0}
	bx r0

	thumb_func_start sub_8036AF8
sub_8036AF8: @ 0x08036AF8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	mov r8, r3
	ldr r7, [sp, #0x18]
	ldr r0, _08036B24 @ =gUnk_Sio_085C99E0
	adds r1, r4, #0
	bl SpawnProc
	str r5, [r0, #0x2c]
	str r6, [r0, #0x30]
	mov r1, r8
	str r1, [r0, #0x38]
	str r7, [r0, #0x34]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08036B24: .4byte gUnk_Sio_085C99E0

	thumb_func_start sub_8036B28
sub_8036B28: @ 0x08036B28
	push {lr}
	ldr r0, _08036B34 @ =gUnk_Sio_085C99E0
	bl Proc_EndEach
	pop {r0}
	bx r0
	.align 2, 0
_08036B34: .4byte gUnk_Sio_085C99E0

	thumb_func_start sub_8036B38
sub_8036B38: @ 0x08036B38
	ldr r2, [r0, #0x30]
	adds r2, r2, r1
	str r2, [r0, #0x30]
	bx lr

	thumb_func_start sub_8036B40
sub_8036B40: @ 0x08036B40
	push {lr}
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
	ldr r0, _08036B8C @ =gBg0Tm
	movs r1, #0
	bl TmFill
	ldr r0, _08036B90 @ =gBg1Tm
	movs r1, #0
	bl TmFill
	ldr r0, _08036B94 @ =gBg2Tm
	movs r1, #0
	bl TmFill
	movs r0, #7
	bl EnableBgSync
	pop {r0}
	bx r0
	.align 2, 0
_08036B8C: .4byte gBg0Tm
_08036B90: .4byte gBg1Tm
_08036B94: .4byte gBg2Tm

	thumb_func_start sub_8036B98
sub_8036B98: @ 0x08036B98
	push {lr}
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
	ldr r0, _08036BEC @ =gBg0Tm
	movs r1, #0
	bl TmFill
	ldr r0, _08036BF0 @ =gBg1Tm
	movs r1, #0
	bl TmFill
	ldr r0, _08036BF4 @ =gBg2Tm
	movs r1, #0
	bl TmFill
	ldr r0, _08036BF8 @ =gBg3Tm
	movs r1, #0
	bl TmFill
	movs r0, #0xf
	bl EnableBgSync
	pop {r0}
	bx r0
	.align 2, 0
_08036BEC: .4byte gBg0Tm
_08036BF0: .4byte gBg1Tm
_08036BF4: .4byte gBg2Tm
_08036BF8: .4byte gBg3Tm

	thumb_func_start sub_8036BFC
sub_8036BFC: @ 0x08036BFC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	lsls r1, r4, #3
	ldr r0, _08036C28 @ =0x0203C900
	adds r5, r1, r0
	adds r0, r5, #0
	bl ClearText
	cmp r6, #0
	bge _08036C30
	lsls r1, r4, #7
	movs r0, #0x80
	lsls r0, r0, #3
	adds r1, r1, r0
	ldr r0, _08036C2C @ =gBg2Tm+0x2
	adds r1, r1, r0
	adds r0, r5, #0
	bl PutText
	b _08036C56
	.align 2, 0
_08036C28: .4byte 0x0203C900
_08036C2C: .4byte gBg2Tm+0x2
_08036C30:
	adds r0, r6, #0
	bl DecodeMsg
	adds r1, r0, #0
	adds r0, r5, #0
	bl Text_DrawString
	lsls r1, r4, #7
	movs r0, #0x80
	lsls r0, r0, #3
	adds r1, r1, r0
	ldr r0, _08036C5C @ =gBg2Tm+0x2
	adds r1, r1, r0
	adds r0, r5, #0
	bl PutText
	movs r0, #4
	bl EnableBgSync
_08036C56:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08036C5C: .4byte gBg2Tm+0x2

	thumb_func_start sub_8036C60
sub_8036C60: @ 0x08036C60
	push {r4, r5, lr}
	ldr r5, _08036CA4 @ =0x0203C67C
	movs r4, #5
_08036C66:
	adds r0, r5, #0
	movs r1, #0xc
	bl InitText
	adds r5, #8
	subs r4, #1
	cmp r4, #0
	bge _08036C66
	ldr r5, _08036CA8 @ =0x0203C624
	movs r4, #0xa
_08036C7A:
	adds r0, r5, #0
	movs r1, #0xc
	bl InitText
	adds r5, #8
	subs r4, #1
	cmp r4, #0
	bge _08036C7A
	ldr r5, _08036CAC @ =0x0203C900
	movs r4, #1
_08036C8E:
	adds r0, r5, #0
	movs r1, #0x18
	bl InitText
	adds r5, #8
	subs r4, #1
	cmp r4, #0
	bge _08036C8E
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08036CA4: .4byte 0x0203C67C
_08036CA8: .4byte 0x0203C624
_08036CAC: .4byte 0x0203C900

	thumb_func_start sub_8036CB0
sub_8036CB0: @ 0x08036CB0
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r1, _08036D04 @ =gUnk_Sio_0810F151
	mov r0, sp
	movs r2, #8
	bl memcpy
	movs r1, #0
	movs r4, #4
	adds r0, r5, #0
	adds r0, #0x24
_08036CC8:
	strh r1, [r0]
	subs r0, #2
	subs r4, #1
	cmp r4, #0
	bge _08036CC8
	movs r4, #0
_08036CD4:
	cmp r4, #4
	beq _08036CF6
	adds r0, r5, #0
	adds r0, #0x26
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _08036CF6
	mov r1, sp
	adds r0, r1, r4
	movs r1, #0xff
	lsls r1, r1, #8
	ldrb r0, [r0]
	orrs r1, r0
	adds r0, r5, #0
	bl UnitAddItem
_08036CF6:
	adds r4, #1
	cmp r4, #7
	ble _08036CD4
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08036D04: .4byte gUnk_Sio_0810F151

	thumb_func_start sub_8036D08
sub_8036D08: @ 0x08036D08
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r1, _08036D34 @ =gUnk_Sio_0810F15A
	mov r0, sp
	movs r2, #8
	bl memcpy
	ldr r0, _08036D38 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt _08036D2C
	lsls r0, r4, #1
	add r0, sp
	ldrh r0, [r0]
	bl m4aSongNumStart
_08036D2C:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08036D34: .4byte gUnk_Sio_0810F15A
_08036D38: .4byte gPlaySt

	thumb_func_start sub_8036D3C
sub_8036D3C: @ 0x08036D3C
	push {r4, lr}
	ldr r4, _08036D5C @ =0x0203C704
	adds r0, r4, #0
	bl sub_8086530
	movs r0, #8
	ldrb r1, [r4]
	orrs r0, r1
	strb r0, [r4]
	adds r0, r4, #0
	bl sub_80864F4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08036D5C: .4byte 0x0203C704

	thumb_func_start sub_8036D60
sub_8036D60: @ 0x08036D60
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08036D84 @ =gKeySt
	ldr r0, [r0]
	ldrh r4, [r0, #8]
	adds r3, r4, #0
	cmp r3, #0
	bne _08036D90
	ldr r1, _08036D88 @ =0x0203C940
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	cmp r0, #0x13
	ble _08036DE4
	ldr r0, _08036D8C @ =0x030013E4
	str r3, [r1]
	str r3, [r0]
	b _08036DE4
	.align 2, 0
_08036D84: .4byte gKeySt
_08036D88: .4byte 0x0203C940
_08036D8C: .4byte 0x030013E4
_08036D90:
	ldr r0, _08036DC4 @ =0x0203C940
	movs r6, #0
	str r6, [r0]
	ldr r1, _08036DC8 @ =0x0203C920
	ldr r2, _08036DCC @ =0x030013E0
	ldr r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	strh r4, [r0]
	ldr r1, _08036DD0 @ =0x030013E4
	ldr r4, [r1]
	lsls r0, r4, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	cmp r3, r0
	bne _08036DD8
	adds r0, r4, #1
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldr r1, _08036DD4 @ =0x0000FFFF
	ldrh r0, [r0]
	cmp r0, r1
	bne _08036DDA
	movs r0, #1
	b _08036DE6
	.align 2, 0
_08036DC4: .4byte 0x0203C940
_08036DC8: .4byte 0x0203C920
_08036DCC: .4byte 0x030013E0
_08036DD0: .4byte 0x030013E4
_08036DD4: .4byte 0x0000FFFF
_08036DD8:
	str r6, [r1]
_08036DDA:
	ldr r0, [r2]
	adds r0, #1
	movs r1, #0xf
	ands r0, r1
	str r0, [r2]
_08036DE4:
	movs r0, #0
_08036DE6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_8036DEC
sub_8036DEC: @ 0x08036DEC
	push {lr}
	ldr r0, _08036DFC @ =gUnk_Sio_085C9A18
	bl sub_8036D60
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0
_08036DFC: .4byte gUnk_Sio_085C9A18

	thumb_func_start sub_8036E00
sub_8036E00: @ 0x08036E00
	push {lr}
	adds r1, r0, #0
	ldr r0, _08036E10 @ =gUnk_Sio_085C9AE0
	bl SpawnProcLocking
	pop {r0}
	bx r0
	.align 2, 0
_08036E10: .4byte gUnk_Sio_085C9AE0

	thumb_func_start sub_8036E14
sub_8036E14: @ 0x08036E14
	mov ip, r0
	mov r2, ip
	adds r2, #0x4a
	movs r3, #0
	movs r1, #0
	movs r0, #0xd8
	strh r0, [r2]
	mov r0, ip
	adds r0, #0x48
	strb r3, [r0]
	mov r0, ip
	str r1, [r0, #0x40]
	str r1, [r0, #0x3c]
	adds r0, #0x52
	strb r3, [r0]
	adds r2, #0xa
	movs r0, #0xff
	ldrb r1, [r2]
	orrs r1, r0
	strb r1, [r2]
	mov r1, ip
	adds r1, #0x53
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x4c
	strb r3, [r0]
	bx lr
	.align 2, 0

	thumb_func_start sub_8036E50
sub_8036E50: @ 0x08036E50
	push {r4, lr}
	ldr r0, _08036E5C @ =0x0203C618
	ldrb r0, [r0, #0xa]
	cmp r0, #0
	bne _08036E64
	b _08036E7C
	.align 2, 0
_08036E5C: .4byte 0x0203C618
_08036E60:
	movs r0, #1
	b _08036E7E
_08036E64:
	movs r2, #0
	movs r3, #0x80
	ldr r1, _08036E84 @ =0x0203C770
_08036E6A:
	adds r0, r3, #0
	ldrb r4, [r1, #0xf]
	ands r0, r4
	cmp r0, #0
	bne _08036E60
	adds r1, #0x14
	adds r2, #1
	cmp r2, #9
	ble _08036E6A
_08036E7C:
	movs r0, #0
_08036E7E:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08036E84: .4byte 0x0203C770

	thumb_func_start sub_8036E88
sub_8036E88: @ 0x08036E88
	push {r4, lr}
	movs r2, #0
	movs r3, #0x80
	ldr r1, _08036EA0 @ =0x0203C770
_08036E90:
	adds r0, r3, #0
	ldrb r4, [r1, #0xf]
	ands r0, r4
	cmp r0, #0
	bne _08036EA4
	movs r0, #1
	b _08036EAE
	.align 2, 0
_08036EA0: .4byte 0x0203C770
_08036EA4:
	adds r1, #0x14
	adds r2, #1
	cmp r2, #9
	ble _08036E90
	movs r0, #0
_08036EAE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_8036EB4
sub_8036EB4: @ 0x08036EB4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	mov sb, r0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	movs r7, #0
	ldr r1, _08036EE4 @ =gUnk_Sio_085C9AC8
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r0, [r0]
	mov r8, r0
	bl InitUnits
	cmp r4, #0
	beq _08036EE8
	cmp r4, #0
	blt _08036F92
	cmp r4, #2
	bgt _08036F92
	movs r6, #0
	b _08036F54
	.align 2, 0
_08036EE4: .4byte gUnk_Sio_085C9AC8
_08036EE8:
	movs r6, #0
	mov r1, sb
	lsls r0, r1, #4
	mov r1, r8
	adds r5, r0, r1
	movs r0, #1
	mov r8, r0
	movs r7, #0
_08036EF8:
	ldr r0, _08036F14 @ =0x0203C770
	adds r4, r7, r0
	adds r0, r6, #0
	adds r1, r4, #0
	bl sub_8086220
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _08036F18
	ldrb r0, [r5, #4]
	strb r0, [r4, #0x10]
	strb r6, [r4, #0xf]
	b _08036F30
	.align 2, 0
_08036F14: .4byte 0x0203C770
_08036F18:
	ldr r0, _08036F50 @ =gUnk_Sio_0810F164
	adds r1, r4, #0
	bl sub_80368DC
	ldrb r0, [r5, #5]
	strb r0, [r4, #0x10]
	movs r0, #0x80
	rsbs r0, r0, #0
	adds r1, r0, #0
	adds r0, r6, #0
	orrs r0, r1
	strb r0, [r4, #0xf]
_08036F30:
	mov r0, r8
	bl GetUnit
	adds r1, r0, #0
	adds r0, r6, #0
	mov r2, sp
	bl sub_808642C
	movs r1, #5
	add r8, r1
	adds r7, #0x14
	adds r6, #1
	cmp r6, #9
	ble _08036EF8
	adds r7, r6, #0
	b _08036F92
	.align 2, 0
_08036F50: .4byte gUnk_Sio_0810F164
_08036F54:
	lsls r0, r7, #2
	adds r5, r0, r7
	lsls r1, r5, #2
	ldr r0, _08036FA4 @ =0x0203C770
	adds r4, r1, r0
	adds r0, r6, #0
	adds r1, r4, #0
	bl sub_8086220
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _08036F8C
	mov r1, sb
	lsls r0, r1, #4
	add r0, r8
	ldrb r0, [r0, #4]
	strb r0, [r4, #0x10]
	strb r6, [r4, #0xf]
	adds r0, r5, #1
	bl GetUnit
	adds r1, r0, #0
	adds r0, r6, #0
	mov r2, sp
	bl sub_808642C
	adds r7, #1
_08036F8C:
	adds r6, #1
	cmp r6, #9
	ble _08036F54
_08036F92:
	adds r0, r7, #0
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08036FA4: .4byte 0x0203C770

	thumb_func_start sub_8036FA8
sub_8036FA8: @ 0x08036FA8
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	adds r5, r0, #0
	lsls r0, r5, #3
	mov r8, r0
	ldr r6, _08037010 @ =0x0203C624
	adds r0, r0, r6
	mov sb, r0
	bl ClearText
	mov r0, sb
	movs r1, #0
	bl Text_SetColor
	lsls r4, r5, #2
	adds r4, r4, r5
	lsls r4, r4, #2
	ldr r0, _08037014 @ =0x0203C770
	adds r4, r4, r0
	mov r0, sb
	adds r1, r4, #0
	bl Text_DrawString
	subs r6, #0xc
	add r8, r6
	ldr r1, _08037018 @ =0x00000FFF
	mov r2, r8
	ldrh r2, [r2, #0xc]
	ands r1, r2
	movs r0, #0xf
	ldrb r4, [r4, #0x10]
	ands r0, r4
	lsls r0, r0, #0xc
	orrs r1, r0
	mov r0, r8
	strh r1, [r0, #0xc]
	lsls r5, r5, #7
	ldr r0, _0803701C @ =gBg1Tm+0x16
	adds r5, r5, r0
	mov r0, sb
	adds r1, r5, #0
	bl PutText
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08037010: .4byte 0x0203C624
_08037014: .4byte 0x0203C770
_08037018: .4byte 0x00000FFF
_0803701C: .4byte gBg1Tm+0x16

	thumb_func_start sub_8037020
sub_8037020: @ 0x08037020
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
	b _08037030
_08037028:
	adds r0, r4, #0
	bl sub_8036FA8
	adds r4, #1
_08037030:
	ldr r0, [r5, #0x38]
	cmp r4, r0
	blt _08037028
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_803703C
sub_803703C: @ 0x0803703C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	lsls r1, r1, #0x18
	ldr r0, _0803707C @ =gUnk_Sio_085C9AC8
	lsrs r1, r1, #0x16
	adds r1, r1, r0
	ldr r1, [r1]
	mov r8, r1
	movs r6, #0
	ldr r0, [r4, #0x38]
	cmp r6, r0
	bge _080370C8
	ldr r0, _08037080 @ =0x0203C618
	adds r5, r0, #0
	adds r5, #0xc
	ldr r3, _08037084 @ =0x0203C770
	movs r2, #0
_08037064:
	ldr r0, _08037084 @ =0x0203C770
	adds r1, r2, r0
	movs r0, #0x80
	ldrb r7, [r1, #0xf]
	ands r0, r7
	cmp r0, #0
	bne _08037088
	ldr r0, [r4, #0x3c]
	lsls r0, r0, #4
	add r0, r8
	ldrb r0, [r0, #4]
	b _08037090
	.align 2, 0
_0803707C: .4byte gUnk_Sio_085C9AC8
_08037080: .4byte 0x0203C618
_08037084: .4byte 0x0203C770
_08037088:
	ldr r0, [r4, #0x3c]
	lsls r0, r0, #4
	add r0, r8
	ldrb r0, [r0, #5]
_08037090:
	strb r0, [r1, #0x10]
	ldr r0, _080370DC @ =0x00000FFF
	adds r1, r0, #0
	ldrh r7, [r5]
	ands r1, r7
	movs r0, #0xf
	ldrb r7, [r3, #0x10]
	ands r0, r7
	lsls r0, r0, #0xc
	orrs r1, r0
	strh r1, [r5]
	lsls r1, r6, #7
	ldr r0, _080370E0 @ =gBg1Tm+0x16
	adds r1, r1, r0
	adds r0, r5, #0
	str r2, [sp]
	str r3, [sp, #4]
	bl PutText
	adds r5, #8
	ldr r3, [sp, #4]
	adds r3, #0x14
	ldr r2, [sp]
	adds r2, #0x14
	adds r6, #1
	ldr r0, [r4, #0x38]
	cmp r6, r0
	blt _08037064
_080370C8:
	movs r0, #2
	bl EnableBgSync
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080370DC: .4byte 0x00000FFF
_080370E0: .4byte gBg1Tm+0x16

	thumb_func_start sub_80370E4
sub_80370E4: @ 0x080370E4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldr r5, [r7, #0x40]
	ldr r1, _08037168 @ =gUnk_Sio_085C9AC8
	ldr r0, _0803716C @ =0x0203C618
	mov sb, r0
	ldrb r2, [r0]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	mov r8, r0
	lsls r4, r5, #2
	adds r4, r4, r5
	adds r0, r4, #1
	bl GetUnit
	adds r6, r0, #0
	ldr r0, _08037170 @ =0x0203C770
	lsls r4, r4, #2
	adds r4, r4, r0
	movs r0, #0x7f
	ldrb r3, [r4, #0xf]
	ands r0, r3
	bl sub_8086264
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl sub_808642C
	ldr r0, _08037174 @ =gUnk_Sio_0810F164
	adds r1, r4, #0
	bl sub_80368DC
	ldr r0, [r7, #0x3c]
	lsls r0, r0, #4
	add r0, r8
	ldrb r0, [r0, #5]
	strb r0, [r4, #0x10]
	movs r0, #0x80
	rsbs r0, r0, #0
	adds r1, r0, #0
	adds r0, r5, #0
	orrs r0, r1
	strb r0, [r4, #0xf]
	adds r0, r5, #0
	bl sub_8036FA8
	bl sub_8036E88
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08037178
	mov r1, sb
	ldrb r0, [r1]
	adds r1, r7, #0
	bl sub_80372B0
	adds r0, r7, #0
	movs r1, #2
	bl Proc_Goto
	b _0803718C
	.align 2, 0
_08037168: .4byte gUnk_Sio_085C9AC8
_0803716C: .4byte 0x0203C618
_08037170: .4byte 0x0203C770
_08037174: .4byte gUnk_Sio_0810F164
_08037178:
	adds r0, r7, #0
	adds r0, #0x4d
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803718C
	mov r2, sb
	ldrb r0, [r2]
	adds r1, r7, #0
	bl sub_80372B0
_0803718C:
	ldr r0, [r7, #0x38]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r7, #0
	adds r1, #0x4a
	ldrh r1, [r1]
	adds r1, #0x28
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl sub_8040AEC
	movs r0, #2
	bl EnableBgSync
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_80371B4
sub_80371B4: @ 0x080371B4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	ldr r7, [r0, #0x40]
	adds r0, #0x53
	ldrb r0, [r0]
	mov r8, r0
	ldr r2, _0803721C @ =0x0203C770
	lsls r5, r0, #2
	add r5, r8
	lsls r0, r5, #2
	adds r6, r0, r2
	movs r1, #0x7f
	adds r0, r1, #0
	ldrb r3, [r6, #0xf]
	ands r0, r3
	lsls r4, r7, #2
	adds r4, r4, r7
	lsls r4, r4, #2
	adds r4, r4, r2
	ldrb r2, [r4, #0xf]
	ands r1, r2
	bl sub_8086330
	ldrb r1, [r6, #0x10]
	ldrb r0, [r4, #0x10]
	strb r0, [r6, #0x10]
	strb r1, [r4, #0x10]
	adds r5, #1
	adds r0, r5, #0
	bl GetUnit
	adds r1, r0, #0
	mov r0, r8
	adds r2, r6, #0
	bl sub_808642C
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08037224
	ldr r0, _08037220 @ =gUnk_Sio_0810F164
	adds r1, r6, #0
	bl sub_80368DC
	movs r3, #0x80
	rsbs r3, r3, #0
	adds r1, r3, #0
	mov r0, r8
	orrs r0, r1
	b _08037226
	.align 2, 0
_0803721C: .4byte 0x0203C770
_08037220: .4byte gUnk_Sio_0810F164
_08037224:
	mov r0, r8
_08037226:
	strb r0, [r6, #0xf]
	lsls r4, r7, #2
	adds r4, r4, r7
	adds r0, r4, #1
	bl GetUnit
	adds r1, r0, #0
	lsls r4, r4, #2
	ldr r0, _08037260 @ =0x0203C770
	adds r4, r4, r0
	adds r0, r7, #0
	adds r2, r4, #0
	bl sub_808642C
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08037268
	ldr r0, _08037264 @ =gUnk_Sio_0810F164
	adds r1, r4, #0
	bl sub_80368DC
	movs r2, #0x80
	rsbs r2, r2, #0
	adds r1, r2, #0
	adds r0, r7, #0
	orrs r0, r1
	strb r0, [r4, #0xf]
	b _0803726A
	.align 2, 0
_08037260: .4byte 0x0203C770
_08037264: .4byte gUnk_Sio_0810F164
_08037268:
	strb r7, [r4, #0xf]
_0803726A:
	adds r0, r7, #0
	bl sub_8036FA8
	mov r0, r8
	bl sub_8036FA8
	mov r3, sb
	ldr r0, [r3, #0x38]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r1, sb
	adds r1, #0x4a
	ldrh r1, [r1]
	adds r1, #0x28
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl sub_8040AEC
	mov r1, sb
	ldr r0, [r1, #0x30]
	bl Proc_End
	mov r1, sb
	adds r1, #0x52
	movs r0, #4
	strb r0, [r1]
	movs r0, #2
	bl EnableBgSync
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_80372B0
sub_80372B0: @ 0x080372B0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	mov r8, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r6, #0
	ldr r2, _08037324 @ =gUnk_Sio_085C9AC8
	lsls r1, r0, #2
	adds r1, r1, r2
	ldr r7, [r1]
	cmp r0, #1
	bne _08037334
	ldr r1, _08037328 @ =0x0203C618
	ldrb r0, [r1, #5]
	adds r0, #2
	cmp r6, r0
	bge _0803731A
	mov sb, r1
	movs r0, #5
	mov r8, r0
	mov r5, sb
	adds r5, #0x64
	movs r7, #0
_080372E4:
	ldr r4, _0803732C @ =0x0203C944
	adds r4, r7, r4
	ldr r0, _08037330 @ =gUnk_Sio_0810F170
	adds r1, r4, #0
	bl sub_80368DC
	adds r0, r5, #0
	bl ClearText
	movs r0, #0xa
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	mov r2, r8
	adds r3, r4, #0
	bl PutDrawTextCentered
	movs r1, #3
	add r8, r1
	adds r5, #8
	adds r7, #0xf
	adds r6, #1
	mov r1, sb
	ldrb r0, [r1, #5]
	adds r0, #2
	cmp r6, r0
	blt _080372E4
_0803731A:
	ldr r0, _08037328 @ =0x0203C618
	ldrb r0, [r0, #5]
	adds r0, #2
	b _08037394
	.align 2, 0
_08037324: .4byte gUnk_Sio_085C9AC8
_08037328: .4byte 0x0203C618
_0803732C: .4byte 0x0203C944
_08037330: .4byte gUnk_Sio_0810F170
_08037334:
	lsls r0, r6, #4
	adds r1, r0, r7
	ldr r0, [r1, #8]
	cmp r0, #0
	bne _08037342
	adds r0, r6, #0
	b _08037394
_08037342:
	mov r0, r8
	adds r0, #0x4d
	adds r4, r0, r6
	movs r0, #1
	strb r0, [r4]
	movs r5, #0
	ldr r0, [r1, #0xc]
	cmp r0, #0
	beq _08037362
	bl _call_via_r0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08037362
	strb r5, [r4]
	movs r5, #1
_08037362:
	lsls r4, r6, #3
	ldr r0, _08037390 @ =0x0203C67C
	adds r4, r4, r0
	adds r0, r4, #0
	bl ClearText
	adds r0, r4, #0
	adds r1, r5, #0
	bl Text_SetColor
	lsls r2, r6, #1
	adds r2, #5
	lsls r0, r6, #4
	adds r0, r0, r7
	ldr r3, [r0, #8]
	movs r0, #7
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #1
	bl PutDrawTextCentered
	adds r6, #1
	b _08037334
	.align 2, 0
_08037390: .4byte 0x0203C67C
_08037394:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_80373A4
sub_80373A4: @ 0x080373A4
	adds r3, r0, #0
	ldr r2, _080373C0 @ =gUnk_Sio_085C9AC8
	ldr r0, _080373C4 @ =0x0203C618
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r2
	ldr r2, [r0]
	cmp r1, #1
	beq _080373C8
	ldr r0, [r3, #0x3c]
	lsls r0, r0, #4
	adds r0, r0, r2
	ldrh r0, [r0, #2]
	b _080373DA
	.align 2, 0
_080373C0: .4byte gUnk_Sio_085C9AC8
_080373C4: .4byte 0x0203C618
_080373C8:
	ldr r0, [r3, #0x3c]
	cmp r0, #0
	beq _080373D8
	ldr r0, _080373D4 @ =0x000006D2
	b _080373DA
	.align 2, 0
_080373D4: .4byte 0x000006D2
_080373D8:
	ldr r0, _080373DC @ =0x000006D1
_080373DA:
	bx lr
	.align 2, 0
_080373DC: .4byte 0x000006D1

	thumb_func_start sub_80373E0
sub_80373E0: @ 0x080373E0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r4, _080375C0 @ =Pal_SystemText
	bl sub_8036B40
	bl sub_803FA14
	ldr r0, _080375C4 @ =gUnk_08107820
	ldr r1, _080375C8 @ =0x06014800
	bl Decompress
	movs r0, #0
	movs r1, #2
	bl sub_803FAA4
	ldr r0, _080375CC @ =gBg2Tm+0x112
	ldr r1, _080375D0 @ =gUnk_08109DF4
	movs r2, #0x80
	lsls r2, r2, #5
	bl TmApplyTsa_t
	ldr r0, _080375D4 @ =gUnk_08109A00
	movs r1, #0x98
	lsls r1, r1, #2
	movs r2, #0x80
	bl ApplyPaletteExt
	ldr r0, _080375D8 @ =gUnk_081080D4
	ldr r1, _080375DC @ =0x06016000
	bl Decompress
	ldr r0, _080375E0 @ =gUnk_0831AABC
	movs r1, #0x88
	lsls r1, r1, #2
	movs r2, #0x40
	bl ApplyPaletteExt
	ldr r2, _080375E4 @ =gPal
	adds r1, r2, #0
	adds r1, #0x40
	movs r0, #0
	strh r0, [r1]
	adds r2, #0x42
	movs r3, #2
_0803743E:
	ldrh r0, [r4, #8]
	strh r0, [r2]
	adds r4, #2
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge _0803743E
	bl EnablePalSync
	ldr r0, _080375E8 @ =0x0203C758
	bl SetTextFont
	bl InitSystemTextFont
	bl ResetTextFont
	bl sub_8036C60
	bl ApplyUnitSpritePalettes
	bl ResetUnitSprites
	bl ForceSyncUnitSpriteSheet
	ldr r0, [r7, #0x3c]
	ldr r1, _080375EC @ =0x0203C618
	ldrb r1, [r1]
	bl sub_8036EB4
	str r0, [r7, #0x38]
	adds r6, r7, #0
	adds r6, #0x5c
	adds r5, r7, #0
	adds r5, #0x4a
	movs r1, #0
	add r0, sp, #0xc
_08037486:
	strb r1, [r0]
	subs r0, #1
	add r2, sp, #8
	cmp r0, r2
	bge _08037486
	ldr r0, [r7, #0x3c]
	mov r1, sp
	adds r1, r1, r0
	adds r1, #8
	movs r0, #1
	strb r0, [r1]
	ldr r4, _080375EC @ =0x0203C618
	ldrb r0, [r4]
	adds r1, r7, #0
	bl sub_80372B0
	str r0, [r7, #0x34]
	adds r0, r7, #0
	bl sub_8037020
	ldr r1, [r7, #0x34]
	adds r0, r7, #0
	add r2, sp, #8
	bl sub_80403C0
	str r0, [r7, #0x2c]
	movs r3, #0
	adds r4, #6
	movs r2, #0xff
_080374C0:
	adds r1, r3, r4
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	adds r3, #1
	cmp r3, #3
	ble _080374C0
	movs r4, #0
	strb r4, [r6]
	ldrh r2, [r5]
	movs r0, #1
	movs r1, #0
	bl SetBgOffset
	ldr r0, _080375F0 @ =gDispIo
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
	strb r4, [r0]
	mov r1, ip
	adds r1, #0x31
	movs r0, #0x28
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x2c
	movs r2, #0xf0
	strb r2, [r0]
	adds r0, #4
	movs r1, #0x88
	strb r1, [r0]
	subs r0, #1
	strb r4, [r0]
	adds r0, #4
	strb r1, [r0]
	subs r0, #5
	strb r2, [r0]
	mov r1, ip
	adds r1, #0x32
	movs r0, #0xa0
	strb r0, [r1]
	mov r5, ip
	adds r5, #0x34
	movs r2, #1
	ldrb r0, [r5]
	orrs r0, r2
	movs r1, #2
	orrs r0, r1
	movs r4, #4
	orrs r0, r4
	movs r3, #8
	orrs r0, r3
	movs r6, #0x10
	orrs r0, r6
	strb r0, [r5]
	movs r0, #0x35
	add r0, ip
	mov r8, r0
	ldrb r0, [r0]
	orrs r0, r2
	movs r5, #3
	rsbs r5, r5, #0
	ands r0, r5
	orrs r0, r4
	orrs r0, r3
	movs r1, #0x11
	rsbs r1, r1, #0
	ands r0, r1
	mov r1, r8
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x36
	ldrb r1, [r0]
	orrs r2, r1
	ands r2, r5
	orrs r2, r4
	orrs r2, r3
	orrs r2, r6
	strb r2, [r0]
	ldr r0, [r7, #0x2c]
	ldr r1, _080375F4 @ =gUnk_Sio_0810F19C
	ldr r4, _080375EC @ =0x0203C618
	ldrb r2, [r4]
	adds r1, r2, r1
	ldrb r1, [r1]
	bl sub_803FC3C
	ldr r0, _080375F8 @ =gUnk_Sio_085C9AD4
	ldrb r3, [r4]
	lsls r1, r3, #2
	adds r0, r1, r0
	ldr r0, [r0]
	ldr r2, _080375FC @ =gUnk_Sio_0810F190
	adds r1, r1, r2
	ldr r1, [r1]
	str r3, [sp]
	ldr r2, [r7, #0x2c]
	str r2, [sp, #4]
	movs r2, #0
	movs r3, #8
	bl sub_803FD40
	adds r0, r7, #0
	bl sub_80373A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #1
	bl sub_8036BFC
	movs r0, #0xf
	bl EnableBgSync
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080375C0: .4byte Pal_SystemText
_080375C4: .4byte gUnk_08107820
_080375C8: .4byte 0x06014800
_080375CC: .4byte gBg2Tm+0x112
_080375D0: .4byte gUnk_08109DF4
_080375D4: .4byte gUnk_08109A00
_080375D8: .4byte gUnk_081080D4
_080375DC: .4byte 0x06016000
_080375E0: .4byte gUnk_0831AABC
_080375E4: .4byte gPal
_080375E8: .4byte 0x0203C758
_080375EC: .4byte 0x0203C618
_080375F0: .4byte gDispIo
_080375F4: .4byte gUnk_Sio_0810F19C
_080375F8: .4byte gUnk_Sio_085C9AD4
_080375FC: .4byte gUnk_Sio_0810F190

	thumb_func_start sub_8037600
sub_8037600: @ 0x08037600
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r6, r3, #0x18
	ldr r1, _08037660 @ =gKeySt
	ldr r2, [r1]
	ldrh r3, [r2, #6]
	movs r0, #0x40
	ands r0, r3
	cmp r0, #0
	beq _08037636
	ldr r0, [r4]
	cmp r0, r5
	bgt _0803762A
	ldrh r2, [r2, #8]
	cmp r3, r2
	bne _08037636
_0803762A:
	subs r0, #1
	str r0, [r4]
	cmp r0, #0
	bge _08037636
	subs r0, r6, #1
	str r0, [r4]
_08037636:
	ldr r1, [r1]
	ldrh r2, [r1, #6]
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _0803765A
	ldr r0, [r4]
	cmp r0, r7
	blt _0803764E
	ldrh r1, [r1, #8]
	cmp r2, r1
	bne _0803765A
_0803764E:
	adds r0, #1
	str r0, [r4]
	adds r1, r6, #0
	bl __modsi3
	str r0, [r4]
_0803765A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08037660: .4byte gKeySt

	thumb_func_start sub_8037664
sub_8037664: @ 0x08037664
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	ldr r6, [r4, #0x3c]
	ldr r1, _08037730 @ =gUnk_Sio_085C9AC8
	ldr r0, _08037734 @ =0x0203C618
	mov r8, r0
	ldrb r2, [r0]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r5, [r4, #0x2c]
	adds r0, r5, #0
	adds r0, #0x44
	movs r3, #0
	mov sl, r3
	movs r7, #1
	strb r7, [r0]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r5, #0x48]
	adds r0, r4, #0
	adds r0, #0x3c
	ldr r3, [r4, #0x34]
	subs r1, r3, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	movs r2, #0
	bl sub_8037600
	ldr r0, [r4, #0x3c]
	cmp r6, r0
	beq _080376E2
	movs r0, #3
	bl sub_8036D08
	adds r0, r5, #0
	adds r0, #0x3a
	adds r1, r0, r6
	mov r2, sl
	strb r2, [r1]
	ldr r1, [r4, #0x3c]
	adds r0, r0, r1
	strb r7, [r0]
	mov r3, r8
	ldrb r1, [r3]
	adds r0, r4, #0
	bl sub_803703C
	adds r0, r4, #0
	bl sub_80373A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #1
	bl sub_8036BFC
_080376E2:
	ldr r0, _08037738 @ =gKeySt
	ldr r1, [r0]
	adds r0, r7, #0
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _08037774
	mov r0, r8
	ldrb r0, [r0]
	cmp r0, #1
	beq _08037752
	adds r0, r4, #0
	adds r0, #0x4d
	ldr r1, [r4, #0x3c]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803774A
	lsls r0, r1, #4
	add r0, sb
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x52
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bne _0803773C
	movs r0, #1
	bl sub_8036D08
	adds r0, r4, #0
	movs r1, #9
	bl Proc_Goto
	movs r0, #0xff
	mov r1, r8
	strb r0, [r1, #3]
	b _080377CE
	.align 2, 0
_08037730: .4byte gUnk_Sio_085C9AC8
_08037734: .4byte 0x0203C618
_08037738: .4byte gKeySt
_0803773C:
	movs r0, #2
	bl sub_8036D08
	adds r0, r4, #0
	bl Proc_Break
	b _08037774
_0803774A:
	movs r0, #0
	bl sub_8036D08
	b _08037774
_08037752:
	movs r0, #2
	bl sub_8036D08
	adds r1, r4, #0
	adds r1, #0x52
	movs r0, #8
	strb r0, [r1]
	ldr r0, [r4, #0x3c]
	adds r1, #1
	strb r0, [r1]
	mov r2, sl
	str r2, [r4, #0x44]
	adds r0, r4, #0
	movs r1, #5
	bl Proc_Goto
	b _080377CE
_08037774:
	ldr r5, _080377DC @ =gKeySt
	ldr r1, [r5]
	movs r0, #2
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _08037796
	movs r0, #1
	bl sub_8036D08
	adds r0, r4, #0
	movs r1, #9
	bl Proc_Goto
	ldr r1, _080377E0 @ =0x0203C618
	movs r0, #0xff
	strb r0, [r1, #3]
_08037796:
	ldr r1, [r5]
	movs r0, #8
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _080377CE
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _080377CE
	ldr r0, _080377E4 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt _080377C0
	movs r0, #0x6a
	bl m4aSongNumStart
_080377C0:
	ldr r1, _080377E0 @ =0x0203C618
	movs r0, #0
	strb r0, [r1, #3]
	adds r0, r4, #0
	movs r1, #9
	bl Proc_Goto
_080377CE:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080377DC: .4byte gKeySt
_080377E0: .4byte 0x0203C618
_080377E4: .4byte gPlaySt

	thumb_func_start sub_80377E8
sub_80377E8: @ 0x080377E8
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, [r4, #0x2c]
	bl Proc_End
	bl sub_803FB74
	bl InitUnits
	movs r0, #1
	bl GetUnit
	adds r1, r0, #0
	ldr r3, _08037828 @ =0x0203C770
	ldr r2, [r4, #0x40]
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrb r0, [r0, #0xf]
	mov r2, sp
	bl sub_808642C
	adds r0, r4, #0
	bl sub_80762E4
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08037828: .4byte 0x0203C770

	thumb_func_start sub_803782C
sub_803782C: @ 0x0803782C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08037848 @ =gUnk_08678594
	bl Proc_Find
	cmp r0, #0
	bne _08037840
	adds r0, r4, #0
	bl Proc_Break
_08037840:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08037848: .4byte gUnk_08678594

	thumb_func_start sub_803784C
sub_803784C: @ 0x0803784C
	movs r1, #0
	ldr r2, _08037868 @ =0x0203C618
	ldrb r0, [r2, #5]
	adds r0, #2
	cmp r1, r0
	bge _08037872
	adds r3, r2, #6
	adds r2, r0, #0
_0803785C:
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _0803786C
	movs r0, #0
	b _08037874
	.align 2, 0
_08037868: .4byte 0x0203C618
_0803786C:
	adds r1, #1
	cmp r1, r2
	blt _0803785C
_08037872:
	movs r0, #1
_08037874:
	bx lr
	.align 2, 0

	thumb_func_start sub_8037878
sub_8037878: @ 0x08037878
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldr r0, [r7, #0x40]
	mov sb, r0
	ldr r1, [r7, #0x2c]
	str r1, [sp, #4]
	ldr r0, _080378BC @ =gUnk_Sio_085C9A08
	bl sub_8036D60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080378C4
	ldr r0, _080378C0 @ =0x0203C770
	mov r2, sb
	lsls r1, r2, #2
	add r1, sb
	lsls r1, r1, #2
	adds r1, r1, r0
	movs r0, #0x80
	ldrb r1, [r1, #0xf]
	ands r0, r1
	cmp r0, #0
	bne _080378C4
	adds r0, r7, #0
	movs r1, #8
	bl Proc_Goto
	b _08037D64
	.align 2, 0
_080378BC: .4byte gUnk_Sio_085C9A08
_080378C0: .4byte 0x0203C770
_080378C4:
	ldr r1, [sp, #4]
	adds r1, #0x44
	movs r0, #0
	strb r0, [r1]
	adds r1, r7, #0
	adds r1, #0x48
	ldr r0, [r7, #0x40]
	ldrb r3, [r1]
	subs r0, r0, r3
	lsls r0, r0, #4
	adds r0, #0x28
	ldr r2, [sp, #4]
	str r0, [r2, #0x48]
	adds r0, r7, #0
	adds r0, #0x4c
	movs r2, #0
	ldrsb r2, [r0, r2]
	mov sl, r1
	str r0, [sp, #8]
	cmp r2, #0
	ble _08037926
	adds r4, r7, #0
	adds r4, #0x4a
	ldrh r0, [r4]
	subs r0, #4
	strh r0, [r4]
	ldr r3, [sp, #8]
	ldrb r0, [r3]
	subs r0, #1
	strb r0, [r3]
	ldrh r2, [r4]
	movs r0, #1
	movs r1, #0
	bl SetBgOffset
	ldr r0, [r7, #0x30]
	cmp r0, #0
	beq _08037916
	movs r1, #4
	bl sub_8036B38
_08037916:
	movs r0, #4
	bl sub_8040530
	ldr r1, [r7, #0x40]
	mov r0, sl
	ldrb r0, [r0]
	subs r1, r1, r0
	b _08037964
_08037926:
	cmp r2, #0
	bge _08037982
	adds r4, r7, #0
	adds r4, #0x4a
	ldrh r0, [r4]
	adds r0, #4
	strh r0, [r4]
	ldr r1, [sp, #8]
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldrh r2, [r4]
	movs r0, #1
	movs r1, #0
	bl SetBgOffset
	ldr r0, [r7, #0x30]
	cmp r0, #0
	beq _08037954
	movs r1, #4
	rsbs r1, r1, #0
	bl sub_8036B38
_08037954:
	movs r0, #4
	rsbs r0, r0, #0
	bl sub_8040530
	ldr r1, [r7, #0x40]
	mov r2, sl
	ldrb r2, [r2]
	subs r1, r1, r2
_08037964:
	lsls r1, r1, #4
	adds r1, #0x28
	movs r0, #0x50
	bl sub_80415CC
	ldr r0, [r7, #0x38]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrh r1, [r4]
	adds r1, #0x28
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl sub_8040AEC
	b _08037D64
_08037982:
	ldr r1, [r7, #0x40]
	mov r3, sl
	ldrb r3, [r3]
	subs r1, r1, r3
	lsls r1, r1, #4
	adds r1, #0x28
	movs r0, #0x50
	bl sub_80415CC
	ldr r0, _080379C0 @ =gKeySt
	ldr r1, [r0]
	movs r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	bne _080379A4
	b _08037BBA
_080379A4:
	adds r0, r7, #0
	adds r0, #0x52
	ldrb r1, [r0]
	subs r1, #1
	adds r4, r0, #0
	cmp r1, #7
	bls _080379B4
	b _08037BBA
_080379B4:
	lsls r0, r1, #2
	ldr r1, _080379C4 @ =_080379C8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080379C0: .4byte gKeySt
_080379C4: .4byte _080379C8
_080379C8: @ jump table
	.4byte _080379E8 @ case 0
	.4byte _08037A18 @ case 1
	.4byte _08037A40 @ case 2
	.4byte _08037A6C @ case 3
	.4byte _08037AD0 @ case 4
	.4byte _08037ADE @ case 5
	.4byte _08037BBA @ case 6
	.4byte _08037B2C @ case 7
_080379E8:
	ldr r0, _08037A10 @ =0x0203C770
	mov r2, sb
	lsls r1, r2, #2
	add r1, sb
	lsls r1, r1, #2
	adds r1, r1, r0
	movs r0, #0x80
	ldrb r1, [r1, #0xf]
	ands r0, r1
	cmp r0, #0
	bne _08037A00
	b _08037B24
_08037A00:
	movs r0, #2
	bl sub_8036D08
	ldr r1, _08037A14 @ =0x0203C618
	ldr r0, [r7, #0x40]
	strb r0, [r1, #3]
	b _08037A30
	.align 2, 0
_08037A10: .4byte 0x0203C770
_08037A14: .4byte 0x0203C618
_08037A18:
	movs r0, #2
	bl sub_8036D08
	ldr r2, _08037A38 @ =0x0203C618
	ldr r1, _08037A3C @ =0x0203C770
	mov r3, sb
	lsls r0, r3, #2
	add r0, sb
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0, #0xf]
	strb r0, [r2, #3]
_08037A30:
	adds r0, r7, #0
	bl Proc_Break
	b _08037D64
	.align 2, 0
_08037A38: .4byte 0x0203C618
_08037A3C: .4byte 0x0203C770
_08037A40:
	ldr r0, _08037A68 @ =0x0203C770
	mov r2, sb
	lsls r1, r2, #2
	add r1, sb
	lsls r1, r1, #2
	adds r1, r1, r0
	movs r0, #0x80
	ldrb r1, [r1, #0xf]
	ands r0, r1
	cmp r0, #0
	bne _08037B24
	movs r0, #2
	bl sub_8036D08
	adds r0, r7, #0
	movs r1, #4
	bl Proc_Goto
	b _08037D64
	.align 2, 0
_08037A68: .4byte 0x0203C770
_08037A6C:
	ldr r0, [r7, #0x38]
	cmp r0, #1
	bgt _08037A74
	b _08037BBA
_08037A74:
	movs r0, #2
	bl sub_8036D08
	adds r0, r7, #0
	adds r0, #0x53
	mov r3, sb
	strb r3, [r0]
	mov r1, sl
	ldrb r1, [r1]
	subs r2, r3, r1
	lsls r2, r2, #4
	adds r2, #0x28
	movs r0, #0x27
	str r0, [sp]
	adds r0, r7, #0
	movs r1, #0x50
	movs r3, #0x88
	bl sub_8036AF8
	str r0, [r7, #0x30]
	mov r1, sb
	adds r1, #1
	ldr r0, [r7, #0x38]
	cmp r1, r0
	bge _08037AB8
	ldr r0, _08037AB4 @ =gKeySt
	ldr r1, [r0]
	movs r0, #0x80
	ldrh r2, [r1, #6]
	orrs r0, r2
	b _08037AC2
	.align 2, 0
_08037AB4: .4byte gKeySt
_08037AB8:
	ldr r0, _08037ACC @ =gKeySt
	ldr r1, [r0]
	movs r0, #0x40
	ldrh r3, [r1, #6]
	orrs r0, r3
_08037AC2:
	strh r0, [r1, #6]
	movs r0, #5
	strb r0, [r4]
	b _08037BBA
	.align 2, 0
_08037ACC: .4byte gKeySt
_08037AD0:
	movs r0, #2
	bl sub_8036D08
	adds r0, r7, #0
	bl sub_80371B4
	b _08037BBA
_08037ADE:
	ldr r0, _08037B20 @ =0x0203C770
	mov r2, sb
	lsls r1, r2, #2
	add r1, sb
	lsls r1, r1, #2
	adds r1, r1, r0
	movs r0, #0x80
	ldrb r1, [r1, #0xf]
	ands r0, r1
	cmp r0, #0
	bne _08037B24
	movs r0, #2
	bl sub_8036D08
	mov r0, sb
	mov r3, sl
	ldrb r3, [r3]
	subs r2, r0, r3
	lsls r2, r2, #4
	adds r2, #0x28
	movs r0, #0x27
	str r0, [sp]
	adds r0, r7, #0
	movs r1, #0x50
	movs r3, #0x88
	bl sub_8036AF8
	str r0, [r7, #0x30]
	adds r0, r7, #0
	movs r1, #7
	bl Proc_Goto
	b _08037BBA
	.align 2, 0
_08037B20: .4byte 0x0203C770
_08037B24:
	movs r0, #0
	bl sub_8036D08
	b _08037BBA
_08037B2C:
	movs r0, #2
	bl sub_8036D08
	mov r0, sb
	lsls r4, r0, #2
	add r4, sb
	lsls r4, r4, #2
	ldr r0, _08037BE4 @ =0x0203C770
	adds r4, r4, r0
	movs r1, #0x53
	adds r1, r1, r7
	mov r8, r1
	ldrb r2, [r1]
	lsls r1, r2, #4
	mov r3, r8
	ldrb r3, [r3]
	subs r1, r1, r3
	ldr r6, _08037BE8 @ =0x0203C944
	adds r1, r1, r6
	adds r0, r4, #0
	bl sub_80368DC
	ldr r5, _08037BEC @ =0x0203C618
	adds r0, r5, #6
	mov r1, r8
	ldrb r1, [r1]
	adds r0, r1, r0
	ldrb r1, [r4, #0xf]
	strb r1, [r0]
	mov r2, r8
	ldrb r2, [r2]
	lsls r0, r2, #3
	adds r5, #0x64
	adds r0, r0, r5
	bl ClearText
	mov r3, r8
	ldrb r1, [r3]
	lsls r0, r1, #3
	adds r0, r0, r5
	lsls r2, r1, #1
	adds r2, r2, r1
	adds r2, #5
	lsls r3, r1, #4
	subs r3, r3, r1
	adds r3, r3, r6
	movs r1, #0xa
	str r1, [sp]
	movs r1, #1
	bl PutDrawTextCentered
	bl sub_803784C
	adds r1, r7, #0
	adds r1, #0x5c
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08037BAE
	ldr r1, [sp, #4]
	ldr r0, [r1, #0x40]
	cmp r0, #0
	bne _08037BAE
	movs r0, #8
	str r0, [r1, #0x40]
_08037BAE:
	movs r0, #0
	str r0, [r7, #0x44]
	adds r0, r7, #0
	movs r1, #6
	bl Proc_Goto
_08037BBA:
	ldr r0, _08037BF0 @ =gKeySt
	ldr r1, [r0]
	movs r0, #2
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _08037C0E
	movs r0, #1
	bl sub_8036D08
	adds r1, r7, #0
	adds r1, #0x52
	ldrb r0, [r1]
	cmp r0, #5
	bne _08037BF4
	movs r0, #4
	strb r0, [r1]
	ldr r0, [r7, #0x30]
	bl Proc_End
	b _08037D64
	.align 2, 0
_08037BE4: .4byte 0x0203C770
_08037BE8: .4byte 0x0203C944
_08037BEC: .4byte 0x0203C618
_08037BF0: .4byte gKeySt
_08037BF4:
	cmp r0, #8
	beq _08037C02
	adds r0, r7, #0
	movs r1, #2
	bl Proc_Goto
	b _08037C0E
_08037C02:
	movs r0, #0
	str r0, [r7, #0x44]
	adds r0, r7, #0
	movs r1, #6
	bl Proc_Goto
_08037C0E:
	ldr r0, _08037CB8 @ =gKeySt
	ldr r1, [r0]
	movs r0, #8
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _08037C48
	adds r0, r7, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08037C48
	ldr r0, _08037CBC @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt _08037C3A
	movs r0, #0x6a
	bl m4aSongNumStart
_08037C3A:
	ldr r1, _08037CC0 @ =0x0203C618
	movs r0, #0
	strb r0, [r1, #3]
	adds r0, r7, #0
	movs r1, #9
	bl Proc_Goto
_08037C48:
	ldr r0, _08037CB8 @ =gKeySt
	ldr r1, [r0]
	movs r0, #0x40
	ldrh r1, [r1, #6]
	ands r0, r1
	cmp r0, #0
	beq _08037CCE
	mov r2, sl
	ldrb r0, [r2]
	cmp r0, #0
	beq _08037CC4
	ldr r0, [r7, #0x40]
	ldrb r3, [r2]
	subs r0, r0, r3
	cmp r0, #1
	bgt _08037CC4
	adds r4, r7, #0
	adds r4, #0x4a
	ldrh r0, [r4]
	subs r0, #4
	strh r0, [r4]
	ldr r0, [r7, #0x30]
	cmp r0, #0
	beq _08037C7E
	movs r1, #4
	bl sub_8036B38
_08037C7E:
	movs r0, #4
	bl sub_8040530
	mov r1, sl
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	movs r0, #3
	ldr r2, [sp, #8]
	strb r0, [r2]
	ldr r0, [r7, #0x40]
	subs r0, #1
	str r0, [r7, #0x40]
	ldrh r2, [r4]
	movs r0, #1
	movs r1, #0
	bl SetBgOffset
	ldr r0, [r7, #0x38]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrh r1, [r4]
	adds r1, #0x28
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl sub_8040AEC
	b _08037CCE
	.align 2, 0
_08037CB8: .4byte gKeySt
_08037CBC: .4byte gPlaySt
_08037CC0: .4byte 0x0203C618
_08037CC4:
	ldr r0, [r7, #0x40]
	cmp r0, #0
	ble _08037CCE
	subs r0, #1
	str r0, [r7, #0x40]
_08037CCE:
	ldr r0, _08037D48 @ =gKeySt
	ldr r1, [r0]
	movs r0, #0x80
	ldrh r1, [r1, #6]
	ands r0, r1
	cmp r0, #0
	beq _08037D58
	ldr r1, [r7, #0x38]
	cmp r1, #6
	ble _08037D4C
	mov r3, sl
	ldrb r2, [r3]
	adds r0, r2, #6
	cmp r0, r1
	bge _08037D4C
	ldr r0, [r7, #0x40]
	subs r0, r0, r2
	cmp r0, #3
	ble _08037D4C
	adds r4, r7, #0
	adds r4, #0x4a
	ldrh r0, [r4]
	adds r0, #4
	strh r0, [r4]
	ldr r0, [r7, #0x30]
	cmp r0, #0
	beq _08037D0C
	movs r1, #4
	rsbs r1, r1, #0
	bl sub_8036B38
_08037D0C:
	movs r0, #4
	rsbs r0, r0, #0
	bl sub_8040530
	mov r1, sl
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #0xfd
	ldr r2, [sp, #8]
	strb r0, [r2]
	ldr r0, [r7, #0x40]
	adds r0, #1
	str r0, [r7, #0x40]
	ldrh r2, [r4]
	movs r0, #1
	movs r1, #0
	bl SetBgOffset
	ldr r0, [r7, #0x38]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrh r1, [r4]
	adds r1, #0x28
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl sub_8040AEC
	b _08037D58
	.align 2, 0
_08037D48: .4byte gKeySt
_08037D4C:
	subs r0, r1, #1
	ldr r1, [r7, #0x40]
	cmp r1, r0
	bge _08037D58
	adds r0, r1, #1
	str r0, [r7, #0x40]
_08037D58:
	ldr r0, [r7, #0x40]
	cmp sb, r0
	beq _08037D64
	movs r0, #3
	bl sub_8036D08
_08037D64:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_8037D74
sub_8037D74: @ 0x08037D74
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	rsbs r1, r1, #0
	subs r1, #8
	movs r2, #4
	adds r0, #0x38
_08037D80:
	strh r1, [r0]
	subs r0, #2
	subs r2, #1
	cmp r2, #0
	bge _08037D80
	bx lr

	thumb_func_start sub_8037D8C
sub_8037D8C: @ 0x08037D8C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, [r4, #0x2c]
	ldr r0, _08037DF0 @ =gUnk_Sio_0810F19F
	ldr r1, [r4, #0x44]
	adds r1, r1, r0
	movs r5, #0
	ldrsb r5, [r1, r5]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r5, r0
	bne _08037DAC
	adds r0, r4, #0
	movs r1, #3
	bl Proc_Goto
_08037DAC:
	ldr r0, [r4, #0x44]
	adds r0, #1
	str r0, [r4, #0x44]
	movs r0, #2
	rsbs r0, r0, #0
	cmp r5, r0
	bne _08037DF8
	ldr r3, _08037DF4 @ =gDispIo
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	ldrb r2, [r3, #0x10]
	ands r0, r2
	strb r0, [r3, #0x10]
	adds r0, r1, #0
	ldrb r2, [r3, #0x14]
	ands r0, r2
	movs r2, #1
	orrs r0, r2
	strb r0, [r3, #0x14]
	ldrb r0, [r3, #0xc]
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	strb r1, [r3, #0xc]
	movs r0, #3
	ldrb r1, [r3, #0x18]
	orrs r0, r1
	strb r0, [r3, #0x18]
	adds r1, r6, #0
	adds r1, #0x44
	movs r0, #0
	strb r0, [r1]
	b _08037E0C
	.align 2, 0
_08037DF0: .4byte gUnk_Sio_0810F19F
_08037DF4: .4byte gDispIo
_08037DF8:
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0
	movs r2, #0
	bl SetBgOffset
	adds r0, r6, #0
	adds r1, r5, #0
	bl sub_8037D74
_08037E0C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8037E14
sub_8037E14: @ 0x08037E14
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r6, [r4, #0x2c]
	ldr r1, _08037E7C @ =gUnk_Sio_0810F19F
	ldr r0, [r4, #0x44]
	adds r0, r0, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	movs r7, #1
	rsbs r7, r7, #0
	cmp r5, r7
	bne _08037E34
	adds r0, r4, #0
	movs r1, #2
	bl Proc_Goto
_08037E34:
	ldr r0, [r4, #0x44]
	adds r0, #1
	str r0, [r4, #0x44]
	movs r0, #2
	rsbs r0, r0, #0
	cmp r5, r0
	bne _08037E84
	ldr r3, _08037E80 @ =gDispIo
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
	adds r1, r6, #0
	adds r1, #0x44
	movs r0, #1
	strb r0, [r1]
	str r7, [r6, #0x48]
	b _08037E98
	.align 2, 0
_08037E7C: .4byte gUnk_Sio_0810F19F
_08037E80: .4byte gDispIo
_08037E84:
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0
	movs r2, #0
	bl SetBgOffset
	adds r0, r6, #0
	adds r1, r5, #0
	bl sub_8037D74
_08037E98:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8037EA0
sub_8037EA0: @ 0x08037EA0
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0x55
	movs r0, #1
	strb r0, [r1]
	bl sub_80410BC
	adds r1, r5, #0
	adds r1, #0x48
	ldr r0, [r5, #0x40]
	ldrb r1, [r1]
	subs r0, r0, r1
	cmp r0, #2
	ble _08037EC4
	lsls r0, r0, #1
	subs r0, #2
	b _08037EC8
_08037EC4:
	lsls r0, r0, #1
	adds r0, #5
_08037EC8:
	str r0, [r5, #0x58]
	ldr r4, _08037EF8 @ =0x0203C6A4
	adds r0, r4, #0
	bl ClearText
	ldr r1, _08037EFC @ =gUnk_Sio_0810F1AC
	adds r0, r4, #0
	bl Text_DrawString
	ldr r1, [r5, #0x58]
	adds r1, #4
	lsls r1, r1, #6
	ldr r0, _08037F00 @ =gBg0Tm+0x1E
	adds r1, r1, r0
	adds r0, r4, #0
	bl PutText
	movs r0, #1
	bl EnableBgSync
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08037EF8: .4byte 0x0203C6A4
_08037EFC: .4byte gUnk_Sio_0810F1AC
_08037F00: .4byte gBg0Tm+0x1E

	thumb_func_start sub_8037F04
sub_8037F04: @ 0x08037F04
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x58]
	lsls r1, r1, #3
	adds r1, #0x18
	movs r0, #0x60
	bl sub_80410F8
	ldr r0, _08037FA8 @ =gKeySt
	ldr r1, [r0]
	movs r0, #0x20
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _08037F36
	adds r1, r4, #0
	adds r1, #0x55
	ldrb r0, [r1]
	cmp r0, #1
	bne _08037F36
	movs r0, #0
	strb r0, [r1]
	movs r0, #3
	bl sub_8036D08
_08037F36:
	ldr r0, _08037FA8 @ =gKeySt
	ldr r1, [r0]
	movs r0, #0x10
	ldrh r1, [r1, #8]
	ands r0, r1
	adds r5, r4, #0
	adds r5, #0x55
	cmp r0, #0
	beq _08037F58
	ldrb r0, [r5]
	cmp r0, #0
	bne _08037F58
	movs r0, #1
	strb r0, [r5]
	movs r0, #3
	bl sub_8036D08
_08037F58:
	ldrb r1, [r5]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x70
	ldr r1, [r4, #0x58]
	lsls r1, r1, #3
	adds r1, #0x20
	bl sub_80415CC
	ldr r0, _08037FA8 @ =gKeySt
	ldr r0, [r0]
	ldrh r1, [r0, #8]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08037FB0
	movs r0, #1
	bl sub_8036D08
	ldr r0, [r4, #0x30]
	bl Proc_End
	ldr r0, [r4, #0x58]
	adds r0, #4
	lsls r0, r0, #6
	ldr r1, _08037FAC @ =gBg0Tm+0x1E
	adds r0, r0, r1
	movs r1, #0xc
	movs r2, #2
	movs r3, #0
	bl TmFillRect_t
	movs r0, #1
	bl EnableBgSync
	adds r0, r4, #0
	bl Proc_Break
	b _08037FF8
	.align 2, 0
_08037FA8: .4byte gKeySt
_08037FAC: .4byte gBg0Tm+0x1E
_08037FB0:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08037FF8
	ldr r0, [r4, #0x30]
	bl Proc_End
	ldrb r0, [r5]
	cmp r0, #0
	bne _08037FD2
	adds r0, r4, #0
	bl sub_80370E4
	movs r0, #2
	bl sub_8036D08
	b _08037FD8
_08037FD2:
	movs r0, #1
	bl sub_8036D08
_08037FD8:
	ldr r0, [r4, #0x58]
	adds r0, #4
	lsls r0, r0, #6
	ldr r1, _08038000 @ =gBg0Tm+0x1E
	adds r0, r0, r1
	movs r1, #0xc
	movs r2, #2
	movs r3, #0
	bl TmFillRect_t
	movs r0, #1
	bl EnableBgSync
	adds r0, r4, #0
	bl Proc_Break
_08037FF8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08038000: .4byte gBg0Tm+0x1E

	thumb_func_start sub_8038004
sub_8038004: @ 0x08038004
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r4, [r5, #0x40]
	movs r0, #1
	bl GetUnit
	adds r1, r0, #0
	adds r0, r4, #0
	mov r2, sp
	bl sub_808642C
	adds r0, r5, #0
	bl sub_8084168
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_803802C
sub_803802C: @ 0x0803802C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x34
	muls r0, r1, r0
	ldr r1, _0803803C @ =gUnk_Sio_0810DBCC
	adds r0, r0, r1
	bx lr
	.align 2, 0
_0803803C: .4byte gUnk_Sio_0810DBCC

	thumb_func_start sub_8038040
sub_8038040: @ 0x08038040
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	movs r6, #0
	adds r5, r0, #0
	adds r5, #0x31
	ldr r1, _0803811C @ =0x0203C708
	mov r8, r1
	adds r7, r0, #0
	adds r7, #0x30
_0803805A:
	ldrb r3, [r5]
	lsls r0, r3, #2
	adds r0, r0, r3
	adds r0, r6, r0
	lsls r0, r0, #3
	add r0, r8
	bl ClearText
	ldrb r1, [r5]
	lsls r0, r1, #2
	adds r0, r0, r1
	adds r0, r6, r0
	lsls r0, r0, #3
	add r0, r8
	movs r1, #0
	bl Text_SetColor
	movs r2, #0
	lsls r3, r6, #4
	mov sb, r3
	lsls r0, r6, #1
	mov sl, r0
	adds r1, r6, #1
	str r1, [sp]
_0803808A:
	mov r3, sb
	subs r0, r3, r6
	adds r0, r0, r2
	lsls r0, r0, #1
	ldr r1, _08038120 @ =gUnk_Sio_0810EFD2
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x34
	muls r1, r0, r1
	ldr r0, _08038124 @ =gUnk_Sio_0810DBCC
	adds r4, r1, r0
	ldrb r1, [r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r4, r0
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, #0
	beq _080380E6
	ldrb r3, [r5]
	lsls r0, r3, #2
	adds r0, r0, r3
	adds r0, r6, r0
	lsls r0, r0, #3
	add r0, r8
	ldrh r1, [r4, #0x24]
	str r2, [sp, #4]
	bl Text_SetCursor
	ldrb r1, [r5]
	lsls r0, r1, #2
	adds r0, r0, r1
	adds r0, r6, r0
	lsls r0, r0, #3
	add r0, r8
	ldrb r3, [r7]
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r1, r1, #2
	adds r1, r4, r1
	ldr r1, [r1]
	bl Text_DrawString
	ldr r2, [sp, #4]
_080380E6:
	adds r2, #1
	cmp r2, #0xe
	ble _0803808A
	ldrb r1, [r5]
	lsls r0, r1, #2
	adds r0, r0, r1
	adds r0, r6, r0
	lsls r0, r0, #3
	add r0, r8
	mov r1, sl
	adds r1, #9
	lsls r1, r1, #6
	ldr r2, _08038128 @ =gBg1Tm
	adds r1, r1, r2
	bl PutText
	ldr r6, [sp]
	cmp r6, #4
	ble _0803805A
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803811C: .4byte 0x0203C708
_08038120: .4byte gUnk_Sio_0810EFD2
_08038124: .4byte gUnk_Sio_0810DBCC
_08038128: .4byte gBg1Tm

	thumb_func_start sub_803812C
sub_803812C: @ 0x0803812C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _08038158 @ =0x0203C910
	adds r0, r5, #0
	bl ClearText
	adds r4, #0x3a
	adds r0, r5, #0
	adds r1, r4, #0
	bl Text_DrawString
	ldr r1, _0803815C @ =gBg0Tm+0x158
	adds r0, r5, #0
	bl PutText
	movs r0, #1
	bl EnableBgSync
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08038158: .4byte 0x0203C910
_0803815C: .4byte gBg0Tm+0x158

	thumb_func_start sub_8038160
sub_8038160: @ 0x08038160
	push {r4, r5, r6, lr}
	sub sp, #0x18
	adds r6, r0, #0
	ldr r1, _0803826C @ =gUnk_Sio_0810F1BD
	add r0, sp, #8
	movs r2, #0xa
	bl memcpy
	bl sub_8036B40
	bl sub_803FA14
	ldr r0, _08038270 @ =gUnk_08107820
	ldr r1, _08038274 @ =0x06014800
	bl Decompress
	ldr r0, _08038278 @ =gUnk_08109A00
	movs r1, #0x98
	lsls r1, r1, #2
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, _0803827C @ =gUnk_08109C40
	movs r1, #0xa0
	lsls r1, r1, #2
	movs r2, #0x20
	bl ApplyPaletteExt
	movs r0, #0
	movs r1, #0
	bl sub_803FAA4
	ldr r0, _08038280 @ =gBg2Tm+0x200
	ldr r1, _08038284 @ =gUnk_0810A044
	movs r2, #0x80
	lsls r2, r2, #5
	bl TmApplyTsa_t
	ldr r0, _08038288 @ =0x0203C758
	bl SetTextFont
	bl InitSystemTextFont
	bl ResetTextFont
	add r0, sp, #0x14
	movs r4, #0
	strh r4, [r0]
	adds r1, r6, #0
	adds r1, #0x3a
	ldr r5, _0803828C @ =0x01000007
	adds r2, r5, #0
	bl CpuSet
	mov r0, sp
	adds r0, #0x16
	strh r4, [r0]
	adds r1, r6, #0
	adds r1, #0x4a
	adds r2, r5, #0
	bl CpuSet
	adds r0, r6, #0
	adds r0, #0x36
	strb r4, [r0]
	ldr r0, _08038290 @ =0x0203C910
	movs r1, #8
	bl InitText
	adds r0, r6, #0
	adds r0, #0x30
	strb r4, [r0]
	movs r0, #6
	strh r0, [r6, #0x32]
	bl sub_803802C
	ldrh r1, [r0, #0x24]
	subs r1, #4
	ldrh r2, [r0, #0x26]
	adds r2, #1
	adds r0, r6, #0
	bl sub_804067C
	str r0, [r6, #0x2c]
	adds r0, r6, #0
	adds r0, #0x37
	strb r4, [r0]
	ldr r5, _08038294 @ =0x0203C708
	movs r4, #9
_08038212:
	adds r0, r5, #0
	movs r1, #0x1a
	bl InitText
	adds r5, #8
	subs r4, #1
	cmp r4, #0
	bge _08038212
	ldr r4, _08038298 @ =0x0203C6A4
	adds r0, r4, #0
	movs r1, #0xc
	bl InitText
	ldr r0, [r6, #0x2c]
	movs r1, #3
	bl sub_803FC3C
	subs r4, #0x8c
	ldrb r0, [r4]
	str r0, [sp]
	ldr r0, [r6, #0x2c]
	str r0, [sp, #4]
	add r0, sp, #8
	movs r1, #0xa
	movs r2, #0
	movs r3, #8
	bl sub_803FD40
	ldr r1, _0803829C @ =0x0203C918
	movs r0, #0
	strb r0, [r1]
	adds r1, r6, #0
	adds r1, #0x31
	movs r0, #0
	strb r0, [r1]
	adds r0, r6, #0
	bl sub_8038040
	movs r0, #0xf
	bl EnableBgSync
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803826C: .4byte gUnk_Sio_0810F1BD
_08038270: .4byte gUnk_08107820
_08038274: .4byte 0x06014800
_08038278: .4byte gUnk_08109A00
_0803827C: .4byte gUnk_08109C40
_08038280: .4byte gBg2Tm+0x200
_08038284: .4byte gUnk_0810A044
_08038288: .4byte 0x0203C758
_0803828C: .4byte 0x01000007
_08038290: .4byte 0x0203C910
_08038294: .4byte 0x0203C708
_08038298: .4byte 0x0203C6A4
_0803829C: .4byte 0x0203C918

	thumb_func_start sub_80382A0
sub_80382A0: @ 0x080382A0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	mov sb, r1
	movs r0, #0x81
	bl GetUnit
	mov r8, r0
	mov r4, r8
	movs r6, #4
_080382BA:
	adds r0, r4, #0
	bl ClearUnit
	adds r4, #0x48
	subs r6, #1
	cmp r6, #0
	bge _080382BA
	movs r6, #0
	mov r7, r8
_080382CC:
	ldr r0, _08038320 @ =0x0203D494
	adds r0, r6, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _080382FE
	bl GetUnitByPid
	adds r4, r0, #0
	movs r0, #8
	ldrh r1, [r4, #0xc]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne _080382FE
	adds r0, r4, #0
	movs r1, #0
	bl SetUnitStatus
	strh r5, [r4, #0xc]
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0x48
	bl sub_8015504
_080382FE:
	adds r7, #0x48
	adds r6, #1
	cmp r6, #4
	ble _080382CC
	mov r0, sb
	mov r1, r8
	mov r2, sl
	bl sub_80863CC
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08038320: .4byte 0x0203D494

	thumb_func_start sub_8038324
sub_8038324: @ 0x08038324
	push {r4, r5, r6, r7, lr}
	mov ip, r0
	lsls r5, r1, #1
	adds r2, #0x2a
	adds r2, r2, r5
	ldrh r4, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r0, #0x34
	muls r0, r1, r0
	ldr r7, _0803837C @ =gUnk_Sio_0810DBCC
	adds r2, r0, r7
	mov r1, ip
	adds r1, #0x30
	ldrb r3, [r1]
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r3, r0, #2
	adds r0, r2, r3
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, #0
	bne _08038372
	adds r1, r5, #0
	movs r6, #0x34
	adds r5, r7, #0
_08038358:
	adds r0, r2, #0
	adds r0, #0x2a
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	adds r2, r0, r5
	adds r0, r2, r3
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, #0
	beq _08038358
_08038372:
	mov r3, ip
	strh r4, [r3, #0x32]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803837C: .4byte gUnk_Sio_0810DBCC

	thumb_func_start sub_8038380
sub_8038380: @ 0x08038380
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	adds r6, r5, #0
	adds r6, #0x36
	ldrb r0, [r6]
	cmp r0, #0xd
	bhi _080383EC
	movs r0, #2
	bl sub_8036D08
	adds r4, r5, #0
	adds r4, #0x30
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r7, r0
	ldr r0, [r0]
	ldrb r1, [r6]
	adds r1, #0x3a
	adds r1, r5, r1
	bl sub_80368DC
	ldrb r1, [r6]
	lsrs r0, r1, #1
	lsls r0, r0, #1
	adds r2, r5, #0
	adds r2, #0x4a
	adds r2, r2, r0
	ldr r1, _080383E8 @ =0x00003FFF
	ldrh r0, [r5, #0x32]
	ands r1, r0
	movs r0, #3
	ldrb r4, [r4]
	ands r0, r4
	lsls r0, r0, #0xe
	orrs r1, r0
	strh r1, [r2]
	ldrb r0, [r6]
	adds r0, #2
	cmp r0, #0xd
	bgt _080383D8
	strb r0, [r6]
_080383D8:
	adds r0, r5, #0
	bl sub_803812C
	adds r1, r5, #0
	adds r1, #0x37
	movs r0, #0
	strb r0, [r1]
	b _080383F2
	.align 2, 0
_080383E8: .4byte 0x00003FFF
_080383EC:
	movs r0, #0
	bl sub_8036D08
_080383F2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_80383F8
sub_80383F8: @ 0x080383F8
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x36
	ldrb r0, [r4]
	cmp r0, #0
	beq _08038448
	movs r0, #2
	bl sub_8036D08
	ldrb r1, [r4]
	lsrs r0, r1, #1
	lsls r0, r0, #1
	adds r2, r5, #0
	adds r2, #0x4a
	adds r0, r2, r0
	ldrh r0, [r0]
	cmp r0, #0
	bne _08038422
	subs r0, r1, #2
	strb r0, [r4]
_08038422:
	ldrb r1, [r4]
	adds r0, r1, r5
	adds r0, #0x3a
	movs r1, #0
	strb r1, [r0]
	ldrb r4, [r4]
	lsrs r0, r4, #1
	lsls r0, r0, #1
	adds r0, r2, r0
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	adds r0, r5, #0
	adds r0, #0x37
	strb r2, [r0]
	adds r0, r5, #0
	bl sub_803812C
	b _0803844E
_08038448:
	movs r0, #0
	bl sub_8036D08
_0803844E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_8038454
sub_8038454: @ 0x08038454
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x3a
	ldrb r0, [r4]
	cmp r0, #0
	beq _08038480
	movs r0, #2
	bl sub_8036D08
	ldr r0, _0803847C @ =0x0203C618
	ldrb r1, [r0, #3]
	adds r0, r4, #0
	bl sub_80382A0
	adds r0, r5, #0
	bl Proc_Break
	b _08038486
	.align 2, 0
_0803847C: .4byte 0x0203C618
_08038480:
	movs r0, #0
	bl sub_8036D08
_08038486:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_803848C
sub_803848C: @ 0x0803848C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	str r2, [sp]
	mov r8, r3
	adds r0, #0x30
	ldrb r0, [r0]
	cmp r0, #2
	bne _080384BC
	cmp r3, #0
	bne _080384BC
	movs r0, #2
	bl sub_8036D08
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_8038380
	b _0803857A
_080384BC:
	adds r7, r4, #0
	adds r7, #0x36
	ldrb r0, [r7]
	cmp r0, #0
	beq _0803856E
	ldrb r0, [r7]
	lsrs r2, r0, #1
	lsls r1, r2, #1
	adds r5, r4, #0
	adds r5, #0x4a
	adds r1, r5, r1
	ldr r3, _0803855C @ =0x00003FFF
	adds r0, r3, #0
	ldrh r1, [r1]
	ands r0, r1
	movs r1, #1
	mov sb, r1
	cmp r0, #0
	beq _080384E6
	movs r0, #0
	mov sb, r0
_080384E6:
	mov r0, sb
	subs r1, r2, r0
	lsls r1, r1, #1
	adds r1, r5, r1
	adds r0, r3, #0
	ldrh r1, [r1]
	ands r0, r1
	bl sub_803802C
	mov sl, r0
	ldrb r1, [r7]
	lsrs r0, r1, #1
	mov r2, sb
	subs r0, r0, r2
	lsls r0, r0, #1
	adds r0, r5, r0
	ldrh r0, [r0]
	lsrs r5, r0, #0xe
	ldr r3, [sp]
	lsls r6, r3, #2
	adds r1, r4, #0
	adds r1, #0x30
	ldrb r2, [r1]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r6, r0
	add r0, sl
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, #0
	beq _08038560
	movs r0, #2
	bl sub_8036D08
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r0, r6, r0
	add r0, sl
	ldr r0, [r0]
	ldrb r1, [r7]
	adds r1, #0x3a
	adds r1, r4, r1
	mov r3, sb
	lsls r2, r3, #1
	subs r1, r1, r2
	bl sub_80368DC
	adds r0, r4, #0
	bl sub_803812C
	adds r0, r4, #0
	adds r0, #0x37
	mov r1, sp
	ldrb r1, [r1]
	strb r1, [r0]
	movs r0, #1
	b _0803857C
	.align 2, 0
_0803855C: .4byte 0x00003FFF
_08038560:
	mov r2, r8
	cmp r2, #0
	bne _0803857A
	movs r0, #0
	bl sub_8036D08
	b _0803857A
_0803856E:
	mov r3, r8
	cmp r3, #0
	bne _0803857A
	movs r0, #0
	bl sub_8036D08
_0803857A:
	movs r0, #0
_0803857C:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start sub_803858C
sub_803858C: @ 0x0803858C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r4, _0803860C @ =gKeySt
	ldr r1, [r4]
	movs r0, #0x40
	ldrh r1, [r1, #6]
	ands r0, r1
	cmp r0, #0
	beq _080385AA
	adds r0, r5, #0
	movs r1, #0
	adds r2, r6, #0
	bl sub_8038324
_080385AA:
	ldr r1, [r4]
	movs r0, #0x80
	ldrh r1, [r1, #6]
	ands r0, r1
	cmp r0, #0
	beq _080385C0
	adds r0, r5, #0
	movs r1, #1
	adds r2, r6, #0
	bl sub_8038324
_080385C0:
	ldr r1, [r4]
	movs r0, #0x20
	ldrh r1, [r1, #6]
	ands r0, r1
	cmp r0, #0
	beq _080385D6
	adds r0, r5, #0
	movs r1, #2
	adds r2, r6, #0
	bl sub_8038324
_080385D6:
	ldr r1, [r4]
	movs r0, #0x10
	ldrh r1, [r1, #6]
	ands r0, r1
	cmp r0, #0
	beq _080385EC
	adds r0, r5, #0
	movs r1, #3
	adds r2, r6, #0
	bl sub_8038324
_080385EC:
	ldr r1, [r4]
	movs r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _080386C6
	adds r0, r6, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #7
	bhi _080386C6
	lsls r0, r0, #2
	ldr r1, _08038610 @ =_08038614
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803860C: .4byte gKeySt
_08038610: .4byte _08038614
_08038614: @ jump table
	.4byte _08038634 @ case 0
	.4byte _08038668 @ case 1
	.4byte _08038684 @ case 2
	.4byte _080386AA @ case 3
	.4byte _0803863E @ case 4
	.4byte _08038648 @ case 5
	.4byte _08038652 @ case 6
	.4byte _0803865A @ case 7
_08038634:
	adds r0, r5, #0
	adds r1, r6, #0
	bl sub_8038380
	b _080386C6
_0803863E:
	adds r0, r5, #0
	adds r1, r6, #0
	bl sub_80383F8
	b _080386C6
_08038648:
	adds r0, r5, #0
	adds r1, r6, #0
	bl sub_8038454
	b _080386C6
_08038652:
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #1
	b _08038660
_0803865A:
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #2
_08038660:
	movs r3, #0
	bl sub_803848C
	b _080386C6
_08038668:
	adds r4, r5, #0
	adds r4, #0x30
	ldrb r0, [r4]
	cmp r0, #0
	beq _080386A2
	movs r0, #2
	bl sub_8036D08
	movs r0, #0
	strb r0, [r4]
	adds r1, r5, #0
	adds r1, #0x37
	strb r0, [r1]
	b _0803877E
_08038684:
	adds r4, r5, #0
	adds r4, #0x30
	ldrb r0, [r4]
	cmp r0, #1
	beq _080386A2
	movs r0, #2
	bl sub_8036D08
	movs r1, #0
	movs r0, #1
_08038698:
	strb r0, [r4]
	adds r0, r5, #0
	adds r0, #0x37
	strb r1, [r0]
	b _0803877E
_080386A2:
	movs r0, #0
	bl sub_8036D08
	b _080386C6
_080386AA:
	adds r4, r5, #0
	adds r4, #0x30
	ldrb r1, [r4]
	cmp r1, #2
	beq _080386C0
	movs r0, #2
	bl sub_8036D08
	movs r1, #0
	movs r0, #2
	b _08038698
_080386C0:
	movs r0, #0
	bl sub_8036D08
_080386C6:
	ldr r0, _080386E0 @ =gKeySt
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _0803870E
	adds r0, r5, #0
	adds r0, #0x37
	ldrb r7, [r0]
	adds r4, r0, #0
	b _080386F6
	.align 2, 0
_080386E0: .4byte gKeySt
_080386E4:
	ldrb r2, [r4]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r3, #1
	bl sub_803848C
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803870E
_080386F6:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldrb r0, [r4]
	movs r1, #3
	bl __umodsi3
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r7, r0
	bne _080386E4
_0803870E:
	ldr r4, _08038788 @ =gKeySt
	ldr r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #2
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _08038726
	adds r0, r5, #0
	adds r1, r6, #0
	bl sub_80383F8
_08038726:
	ldr r1, [r4]
	movs r0, #8
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _0803873C
	movs r0, #3
	bl sub_8036D08
	movs r0, #5
	strh r0, [r5, #0x32]
_0803873C:
	ldr r0, [r4]
	ldrh r1, [r0, #8]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0803878C
	movs r0, #2
	bl sub_8036D08
	adds r4, r5, #0
	adds r4, #0x30
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldrb r0, [r4]
	movs r1, #3
	bl __umodsi3
	strb r0, [r4]
	lsls r0, r0, #1
	ldrb r4, [r4]
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r0, r6, r0
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803877E
	adds r0, r5, #0
	movs r1, #0
	adds r2, r6, #0
	bl sub_8038324
_0803877E:
	adds r0, r5, #0
	movs r1, #1
	bl Proc_Goto
	b _080387B6
	.align 2, 0
_08038788: .4byte gKeySt
_0803878C:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080387B6
	adds r0, r5, #0
	adds r0, #0x36
	ldrb r0, [r0]
	cmp r0, #0
	beq _080387A8
	adds r0, r5, #0
	adds r1, r6, #0
	bl sub_80383F8
	b _080387B6
_080387A8:
	movs r0, #1
	bl sub_8036D08
	adds r0, r5, #0
	movs r1, #3
	bl Proc_Goto
_080387B6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_80387BC
sub_80387BC: @ 0x080387BC
	push {r4, r5, lr}
	sub sp, #0x18
	adds r5, r0, #0
	movs r1, #0x32
	ldrsh r0, [r5, r1]
	bl sub_803802C
	adds r4, r0, #0
	ldrh r0, [r5, #0x32]
	strh r0, [r5, #0x34]
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_803858C
	ldrh r0, [r5, #0x34]
	ldrh r1, [r5, #0x32]
	cmp r0, r1
	beq _080387E6
	movs r0, #3
	bl sub_8036D08
_080387E6:
	movs r1, #0x32
	ldrsh r0, [r5, r1]
	bl sub_803802C
	adds r4, r0, #0
	adds r0, r5, #0
	adds r0, #0x3a
	add r1, sp, #8
	bl sub_80368DC
	add r1, sp, #8
	movs r0, #0
	strb r0, [r1, #0xc]
	adds r0, r1, #0
	bl GetStringTextLen
	adds r3, r0, #0
	ldr r0, [r5, #0x2c]
	ldrh r1, [r4, #0x24]
	subs r1, #4
	ldrh r2, [r4, #0x26]
	adds r2, #1
	adds r4, #0x28
	ldrb r4, [r4]
	str r4, [sp]
	adds r4, r5, #0
	adds r4, #0x30
	ldrb r4, [r4]
	str r4, [sp, #4]
	bl sub_80406B8
	add sp, #0x18
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_803882C
sub_803882C: @ 0x0803882C
	ldr r0, _08038854 @ =0x04000006
	ldrh r0, [r0]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xa0
	bhi _08038878
	cmp r0, #0x27
	bhi _08038860
	ldr r1, _08038858 @ =0x04000050
	movs r2, #0x84
	lsls r2, r2, #4
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, _0803885C @ =0x00000F08
	adds r0, r2, #0
	strh r0, [r1]
	b _08038878
	.align 2, 0
_08038854: .4byte 0x04000006
_08038858: .4byte 0x04000050
_0803885C: .4byte 0x00000F08
_08038860:
	ldr r1, _0803887C @ =0x04000050
	ldr r2, _08038880 @ =0x00000442
	adds r0, r2, #0
	strh r0, [r1]
	ldr r2, _08038884 @ =0x04000052
	ldr r0, _08038888 @ =0x030013E8
	ldrb r1, [r0]
	movs r0, #0xf
	subs r0, r0, r1
	lsls r0, r0, #8
	adds r1, r1, r0
	strh r1, [r2]
_08038878:
	bx lr
	.align 2, 0
_0803887C: .4byte 0x04000050
_08038880: .4byte 0x00000442
_08038884: .4byte 0x04000052
_08038888: .4byte 0x030013E8

	thumb_func_start sub_803888C
sub_803888C: @ 0x0803888C
	push {lr}
	adds r0, #0x38
	movs r1, #0
	strb r1, [r0]
	ldr r0, _080388A0 @ =sub_803882C
	bl SetOnHBlankA
	pop {r0}
	bx r0
	.align 2, 0
_080388A0: .4byte sub_803882C

	thumb_func_start sub_80388A4
sub_80388A4: @ 0x080388A4
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r5, _080388E0 @ =0x030013E8
	adds r4, r6, #0
	adds r4, #0x38
	ldrb r3, [r4]
	movs r0, #8
	str r0, [sp]
	movs r0, #0
	movs r1, #0xf
	movs r2, #0
	bl Interpolate
	strb r0, [r5]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bls _080388D6
	adds r0, r6, #0
	bl Proc_Break
_080388D6:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080388E0: .4byte 0x030013E8

	thumb_func_start sub_80388E4
sub_80388E4: @ 0x080388E4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r2, r4, #0
	adds r2, #0x31
	ldrb r0, [r2]
	adds r0, #1
	movs r5, #0
	movs r1, #1
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	bl sub_8038040
	movs r0, #2
	bl EnableBgSync
	adds r4, #0x38
	strb r5, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8038910
sub_8038910: @ 0x08038910
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r5, _08038950 @ =0x030013E8
	adds r4, r6, #0
	adds r4, #0x38
	ldrb r3, [r4]
	movs r0, #8
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0xf
	bl Interpolate
	strb r0, [r5]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bls _08038948
	movs r0, #0
	bl SetOnHBlankA
	adds r0, r6, #0
	bl Proc_Break
_08038948:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08038950: .4byte 0x030013E8

	thumb_func_start sub_8038954
sub_8038954: @ 0x08038954
	push {r4, lr}
	adds r0, #0x39
	movs r1, #1
	strb r1, [r0]
	bl sub_80410BC
	ldr r4, _08038984 @ =0x0203C6A4
	adds r0, r4, #0
	bl ClearText
	ldr r1, _08038988 @ =gUnk_Sio_0810F1C8
	adds r0, r4, #0
	bl Text_DrawString
	ldr r1, _0803898C @ =gBg0Tm+0x316
	adds r0, r4, #0
	bl PutText
	movs r0, #1
	bl EnableBgSync
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08038984: .4byte 0x0203C6A4
_08038988: .4byte gUnk_Sio_0810F1C8
_0803898C: .4byte gBg0Tm+0x316

	thumb_func_start sub_8038990
sub_8038990: @ 0x08038990
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x40
	movs r1, #0x58
	bl sub_80410F8
	ldr r0, _08038A20 @ =gKeySt
	ldr r1, [r0]
	movs r0, #0x20
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _080389BE
	adds r1, r5, #0
	adds r1, #0x39
	ldrb r0, [r1]
	cmp r0, #1
	bne _080389BE
	movs r0, #0
	strb r0, [r1]
	movs r0, #3
	bl sub_8036D08
_080389BE:
	ldr r0, _08038A20 @ =gKeySt
	ldr r1, [r0]
	movs r0, #0x10
	ldrh r1, [r1, #8]
	ands r0, r1
	adds r4, r5, #0
	adds r4, #0x39
	cmp r0, #0
	beq _080389E0
	ldrb r0, [r4]
	cmp r0, #0
	bne _080389E0
	movs r0, #1
	strb r0, [r4]
	movs r0, #3
	bl sub_8036D08
_080389E0:
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x50
	movs r1, #0x60
	bl sub_80415CC
	ldr r0, _08038A20 @ =gKeySt
	ldr r0, [r0]
	ldrh r1, [r0, #8]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08038A28
	movs r0, #1
	bl sub_8036D08
	ldr r0, _08038A24 @ =gBg0Tm+0x316
	movs r1, #0xc
	movs r2, #2
	movs r3, #0
	bl TmFillRect_t
	movs r0, #1
	bl EnableBgSync
	adds r0, r5, #0
	bl Proc_Break
	b _08038A6E
	.align 2, 0
_08038A20: .4byte gKeySt
_08038A24: .4byte gBg0Tm+0x316
_08038A28:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08038A6E
	ldrb r0, [r4]
	cmp r0, #0
	bne _08038A50
	movs r0, #2
	bl sub_8036D08
	ldr r1, _08038A4C @ =0x0203C918
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #2
	bl Proc_Goto
	b _08038A56
	.align 2, 0
_08038A4C: .4byte 0x0203C918
_08038A50:
	movs r0, #1
	bl sub_8036D08
_08038A56:
	ldr r0, _08038A74 @ =gBg0Tm+0x316
	movs r1, #0xc
	movs r2, #2
	movs r3, #0
	bl TmFillRect_t
	movs r0, #1
	bl EnableBgSync
	adds r0, r5, #0
	bl Proc_Break
_08038A6E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08038A74: .4byte gBg0Tm+0x316

	thumb_func_start sub_8038A78
sub_8038A78: @ 0x08038A78
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x40
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0x42
	ldrb r2, [r1]
	lsls r1, r2, #3
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r1, r3
	adds r2, #0xa
	bl UnpackFaceChibiSprGraphics
	movs r0, #0
	str r0, [r4, #0x3c]
	subs r0, #0x26
	str r0, [r4, #0x34]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8038AA4
sub_8038AA4: @ 0x08038AA4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r4, [r6, #0x2c]
	ldr r0, [r4, #0x64]
	cmp r0, #0
	bne _08038AC8
	ldr r0, [r6, #0x3c]
	cmp r0, #0x20
	ble _08038AC2
	adds r0, r6, #0
	bl Proc_Break
_08038AC2:
	ldr r0, [r4, #0x64]
	cmp r0, #0
	beq _08038ACE
_08038AC8:
	ldr r0, [r6, #0x34]
	adds r0, #1
	str r0, [r6, #0x34]
_08038ACE:
	ldr r0, [r6, #0x38]
	subs r0, #1
	str r0, [r6, #0x38]
	cmp r0, #0
	bge _08038ADC
	movs r0, #0
	str r0, [r6, #0x38]
_08038ADC:
	ldr r4, [r6, #0x38]
	cmp r4, #0
	beq _08038AE4
	b _08038BF4
_08038AE4:
	ldr r3, [r6, #0x3c]
	cmp r3, #0x20
	bgt _08038AFC
	movs r1, #0x50
	rsbs r1, r1, #0
	movs r0, #0x20
	str r0, [sp]
	movs r0, #4
	movs r2, #0
	bl Interpolate
	str r0, [r6, #0x30]
_08038AFC:
	ldr r0, [r6, #0x3c]
	adds r0, #1
	str r0, [r6, #0x3c]
	ldr r1, [r6, #0x30]
	ldr r2, [r6, #0x34]
	subs r2, #0x10
	ldr r3, _08038BA8 @ =gUnk_Sio_085C9D08
	movs r0, #0x43
	adds r0, r0, r6
	mov r8, r0
	ldrb r5, [r0]
	lsls r0, r5, #2
	adds r0, r0, r3
	ldr r3, [r0]
	str r4, [sp]
	movs r0, #4
	bl PutSprite
	ldr r1, [r6, #0x30]
	adds r1, #0x48
	ldr r2, [r6, #0x34]
	subs r2, #6
	ldr r3, _08038BAC @ =gUnk_Sio_085C9CF8
	adds r5, r6, #0
	adds r5, #0x42
	ldrb r7, [r5]
	lsls r0, r7, #2
	adds r0, r0, r3
	ldr r3, [r0]
	str r4, [sp]
	movs r0, #4
	bl PutSprite
	ldr r1, [r6, #0x30]
	adds r1, #0x60
	ldr r2, [r6, #0x34]
	adds r2, #8
	ldr r3, _08038BB0 @ =gUnk_Sio_0810F220
	str r4, [sp]
	movs r0, #4
	bl PutSprite
	ldr r1, [r6, #0x30]
	adds r1, #0x40
	ldr r2, [r6, #0x34]
	adds r2, #8
	ldr r3, _08038BB4 @ =gUnk_Sio_0810F256
	mov r4, r8
	ldrb r4, [r4]
	lsls r0, r4, #2
	adds r0, #0x50
	str r0, [sp]
	movs r0, #4
	bl PutSprite
	ldr r1, [r6, #0x30]
	rsbs r1, r1, #0
	adds r1, #0x70
	ldr r2, [r6, #0x34]
	subs r2, #8
	ldr r3, _08038BB8 @ =gUnk_Sio_0810F228
	movs r0, #0xf
	ldrb r7, [r5]
	ands r0, r7
	lsls r0, r0, #0xc
	movs r4, #0x80
	lsls r4, r4, #3
	adds r0, r0, r4
	str r0, [sp]
	movs r0, #4
	bl PutSprite
	ldr r0, [r6, #0x30]
	rsbs r0, r0, #0
	adds r1, r0, #0
	adds r1, #0x7c
	ldr r2, [r6, #0x34]
	ldr r3, _08038BBC @ =gUnk_Sio_0810F242
	ldrb r0, [r5]
	cmp r0, #3
	beq _08038BC0
	lsls r0, r0, #3
	ldrb r4, [r5]
	adds r0, r0, r4
	b _08038BC2
	.align 2, 0
_08038BA8: .4byte gUnk_Sio_085C9D08
_08038BAC: .4byte gUnk_Sio_085C9CF8
_08038BB0: .4byte gUnk_Sio_0810F220
_08038BB4: .4byte gUnk_Sio_0810F256
_08038BB8: .4byte gUnk_Sio_0810F228
_08038BBC: .4byte gUnk_Sio_0810F242
_08038BC0:
	movs r0, #0x40
_08038BC2:
	str r0, [sp]
	movs r0, #4
	bl PutSprite
	ldr r1, [r6, #0x30]
	rsbs r1, r1, #0
	adds r1, #0xd0
	ldr r2, [r6, #0x34]
	subs r2, #8
	ldr r3, _08038C00 @ =gUnk_Sio_0810F25E
	ldrb r4, [r5]
	adds r0, r4, #0
	adds r0, #0xa
	movs r5, #0xf
	ands r0, r5
	lsls r0, r0, #0xc
	lsls r4, r4, #3
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r4, r4, r5
	adds r0, r0, r4
	str r0, [sp]
	movs r0, #5
	bl PutSprite
_08038BF4:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08038C00: .4byte gUnk_Sio_0810F25E

	thumb_func_start sub_8038C04
sub_8038C04: @ 0x08038C04
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, [r5, #0x30]
	ldr r2, [r5, #0x34]
	subs r2, #0x10
	ldr r3, _08038CB4 @ =gUnk_Sio_085C9D08
	movs r0, #0x43
	adds r0, r0, r5
	mov r8, r0
	ldrb r4, [r0]
	lsls r0, r4, #2
	adds r0, r0, r3
	ldr r3, [r0]
	movs r4, #0
	str r4, [sp]
	movs r0, #4
	bl PutSprite
	ldr r1, [r5, #0x30]
	adds r1, #0x48
	ldr r2, [r5, #0x34]
	subs r2, #6
	ldr r3, _08038CB8 @ =gUnk_Sio_085C9CF8
	adds r6, r5, #0
	adds r6, #0x42
	ldrb r7, [r6]
	lsls r0, r7, #2
	adds r0, r0, r3
	ldr r3, [r0]
	str r4, [sp]
	movs r0, #4
	bl PutSprite
	ldr r1, [r5, #0x30]
	adds r1, #0x60
	ldr r2, [r5, #0x34]
	adds r2, #8
	ldr r3, _08038CBC @ =gUnk_Sio_0810F220
	str r4, [sp]
	movs r0, #4
	bl PutSprite
	ldr r1, [r5, #0x30]
	adds r1, #0x40
	ldr r2, [r5, #0x34]
	adds r2, #8
	ldr r3, _08038CC0 @ =gUnk_Sio_0810F256
	mov r4, r8
	ldrb r4, [r4]
	lsls r0, r4, #2
	adds r0, #0x50
	str r0, [sp]
	movs r0, #4
	bl PutSprite
	ldr r1, [r5, #0x30]
	rsbs r1, r1, #0
	adds r1, #0x70
	ldr r2, [r5, #0x34]
	subs r2, #8
	ldr r3, _08038CC4 @ =gUnk_Sio_0810F228
	movs r0, #0xf
	ldrb r7, [r6]
	ands r0, r7
	lsls r0, r0, #0xc
	movs r4, #0x80
	lsls r4, r4, #3
	adds r0, r0, r4
	str r0, [sp]
	movs r0, #4
	bl PutSprite
	ldr r0, [r5, #0x30]
	rsbs r0, r0, #0
	adds r1, r0, #0
	adds r1, #0x7c
	ldr r2, [r5, #0x34]
	ldr r3, _08038CC8 @ =gUnk_Sio_0810F242
	ldrb r0, [r6]
	cmp r0, #3
	beq _08038CCC
	lsls r0, r0, #3
	ldrb r6, [r6]
	adds r0, r0, r6
	b _08038CCE
	.align 2, 0
_08038CB4: .4byte gUnk_Sio_085C9D08
_08038CB8: .4byte gUnk_Sio_085C9CF8
_08038CBC: .4byte gUnk_Sio_0810F220
_08038CC0: .4byte gUnk_Sio_0810F256
_08038CC4: .4byte gUnk_Sio_0810F228
_08038CC8: .4byte gUnk_Sio_0810F242
_08038CCC:
	movs r0, #0x40
_08038CCE:
	str r0, [sp]
	movs r0, #4
	bl PutSprite
	ldr r1, [r5, #0x30]
	rsbs r1, r1, #0
	adds r1, #0xd0
	ldr r2, [r5, #0x34]
	subs r2, #8
	ldr r3, _08038D10 @ =gUnk_Sio_0810F25E
	adds r0, r5, #0
	adds r0, #0x42
	ldrb r4, [r0]
	adds r0, r4, #0
	adds r0, #0xa
	movs r5, #0xf
	ands r0, r5
	lsls r0, r0, #0xc
	lsls r4, r4, #3
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r4, r4, r5
	adds r0, r0, r4
	str r0, [sp]
	movs r0, #5
	bl PutSprite
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08038D10: .4byte gUnk_Sio_0810F25E

	thumb_func_start sub_8038D14
sub_8038D14: @ 0x08038D14
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	mov r8, r0
	mov sb, r1
	adds r4, r2, #0
	adds r6, r3, #0
	ldr r5, [sp, #0x18]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldr r0, _08038D60 @ =gUnk_Sio_085C9D18
	mov r1, r8
	bl SpawnProc
	adds r1, r0, #0
	mov r0, r8
	str r0, [r1, #0x2c]
	mov r0, sb
	str r0, [r1, #0x38]
	adds r0, r1, #0
	adds r0, #0x40
	strh r4, [r0]
	adds r0, #3
	strb r5, [r0]
	subs r0, #1
	strb r6, [r0]
	adds r0, r1, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08038D60: .4byte gUnk_Sio_085C9D18

	thumb_func_start sub_8038D64
sub_8038D64: @ 0x08038D64
	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0
	adds r0, #0x40
	ldrb r5, [r0]
	ldr r6, _08038DA4 @ =gBg2Tm
	adds r3, r2, #0
	adds r3, #0x42
	adds r4, r2, #0
	adds r4, #0x41
	ldrb r1, [r4]
	subs r1, #1
	lsls r0, r1, #3
	adds r0, r2, r0
	adds r0, #0x44
	ldrb r3, [r3]
	ldrb r0, [r0]
	cmp r3, r0
	bne _08038DB4
	ldr r2, _08038DA8 @ =gUnk_Sio_0810F26C
	lsls r0, r1, #1
	lsls r1, r5, #3
	adds r0, r0, r1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #6
	adds r0, r0, r6
	ldr r1, _08038DAC @ =gUnk_08109CC0
	ldr r2, _08038DB0 @ =0x00002060
	bl TmApplyTsa_t
	b _08038DDE
	.align 2, 0
_08038DA4: .4byte gBg2Tm
_08038DA8: .4byte gUnk_Sio_0810F26C
_08038DAC: .4byte gUnk_08109CC0
_08038DB0: .4byte 0x00002060
_08038DB4:
	movs r2, #0
	ldr r7, _08038DE4 @ =gUnk_Sio_0810F26C
	adds r3, r4, #0
	lsls r1, r5, #3
	ldr r5, _08038DE8 @ =0x00001034
	adds r4, r5, #0
_08038DC0:
	ldrb r0, [r3]
	subs r0, #1
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, r0, r7
	movs r5, #0
	ldrsh r0, [r0, r5]
	lsls r0, r0, #5
	adds r0, r0, r2
	lsls r0, r0, #1
	adds r0, r0, r6
	strh r4, [r0]
	adds r2, #1
	cmp r2, #0x5f
	ble _08038DC0
_08038DDE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08038DE4: .4byte gUnk_Sio_0810F26C
_08038DE8: .4byte 0x00001034

	thumb_func_start sub_8038DEC
sub_8038DEC: @ 0x08038DEC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	str r0, [sp]
	adds r0, #0x40
	ldrb r0, [r0]
	mov sb, r0
	ldr r0, _08038E40 @ =gFont_Unk_Sio_02001000
	bl SetTextFont
	movs r5, #0
	cmp r5, sb
	bge _08038E7A
	mov sl, r5
	movs r0, #0x98
	mov r8, r0
	movs r7, #0
	movs r6, #0
_08038E16:
	ldr r0, _08038E44 @ =0x0203C6B9
	adds r4, r6, r0
	adds r0, r4, #0
	bl GetStringTextLen
	adds r1, r0, #0
	movs r0, #0x48
	subs r0, r0, r1
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r1, r0, #1
	cmp r5, #2
	bgt _08038E4C
	adds r1, r7, r1
	ldr r0, _08038E48 @ =0x0203C708
	movs r2, #0
	adds r3, r4, #0
	bl Text_InsertDrawString
	b _08038E56
	.align 2, 0
_08038E40: .4byte gFont_Unk_Sio_02001000
_08038E44: .4byte 0x0203C6B9
_08038E48: .4byte 0x0203C708
_08038E4C:
	ldr r0, _08038E8C @ =0x0203C710
	movs r2, #0
	adds r3, r4, #0
	bl Text_InsertDrawString
_08038E56:
	ldr r0, [sp]
	adds r0, #0x48
	add r0, sl
	ldr r3, [r0]
	ldr r0, _08038E8C @ =0x0203C710
	mov r1, r8
	movs r2, #2
	bl Text_InsertDrawNumberOrBlank
	movs r0, #8
	add sl, r0
	movs r0, #0x20
	add r8, r0
	adds r7, #0x48
	adds r6, #0xf
	adds r5, #1
	cmp r5, sb
	blt _08038E16
_08038E7A:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08038E8C: .4byte 0x0203C710

	thumb_func_start sub_8038E90
sub_8038E90: @ 0x08038E90
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08038EB0 @ =gUnk_Sio_085C9D98
	adds r1, r4, #0
	bl SpawnProc
	adds r1, r0, #0
	adds r0, r4, #0
	adds r0, #0x42
	adds r4, #0x44
	ldrb r0, [r0]
	ldrb r4, [r4]
	cmp r0, r4
	bne _08038EB4
	movs r0, #1
	b _08038EB6
	.align 2, 0
_08038EB0: .4byte gUnk_Sio_085C9D98
_08038EB4:
	movs r0, #0
_08038EB6:
	str r0, [r1, #0x58]
	adds r0, r1, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_8038EC0
sub_8038EC0: @ 0x08038EC0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	bl sub_8036B40
	bl sub_803FA14
	ldr r0, _08039024 @ =gUnk_08107820
	ldr r1, _08039028 @ =0x06014800
	bl Decompress
	ldr r0, _0803902C @ =gUnk_081088E8
	ldr r1, _08039030 @ =0x06016000
	bl Decompress
	ldr r0, _08039034 @ =gUnk_08108B14
	ldr r1, _08039038 @ =0x06016800
	bl Decompress
	ldr r0, _0803903C @ =gUnk_08109A00
	movs r1, #0x98
	lsls r1, r1, #2
	movs r2, #0x80
	bl ApplyPaletteExt
	ldr r0, _08039040 @ =gUnk_08109BA0
	movs r1, #0xb8
	lsls r1, r1, #2
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, _08039044 @ =gUnk_08109290
	ldr r1, _08039048 @ =0x06000C00
	bl Decompress
	ldr r0, _0803904C @ =gUnk_08109BE0
	movs r1, #0x40
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r4, _08039050 @ =gUnk_0810BAE0
	movs r0, #3
	bl GetBgChrOffset
	adds r1, r0, #0
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r1, r1, r0
	adds r0, r4, #0
	bl Decompress
	ldr r0, _08039054 @ =gUnk_0810D134
	movs r1, #0xa0
	lsls r1, r1, #1
	movs r2, #0x80
	bl ApplyPaletteExt
	ldr r0, _08039058 @ =gBg3Tm
	ldr r1, _0803905C @ =gUnk_0810D1B4
	movs r2, #0
	bl TmApplyTsa_t
	ldr r0, _08039060 @ =gFont_Unk_Sio_02001000
	ldr r1, _08039064 @ =0x06012000
	movs r2, #0xe
	bl InitSpriteTextFont
	ldr r0, _08039068 @ =Pal_SystemText
	movs r1, #0xf0
	lsls r1, r1, #2
	movs r2, #0x20
	bl ApplyPaletteExt
	movs r0, #0
	bl SetTextFontGlyphs
	bl ResetTextFont
	ldr r4, _0803906C @ =0x0203C708
	movs r5, #1
_08038F60:
	adds r0, r4, #0
	bl InitSpriteText
	adds r0, r4, #0
	movs r1, #0
	bl SpriteText_DrawBackgroundExt
	adds r4, #8
	subs r5, #1
	cmp r5, #0
	bge _08038F60
	ldr r0, _08039070 @ =gUnk_Sio_085C98F4
	ldr r0, [r0]
	ldrb r2, [r0, #7]
	adds r1, r6, #0
	adds r1, #0x40
	movs r3, #0
	strb r2, [r1]
	ldrb r1, [r0, #7]
	adds r2, r6, #0
	adds r2, #0x41
	strb r1, [r2]
	ldrb r0, [r0, #6]
	adds r1, r6, #0
	adds r1, #0x42
	strb r0, [r1]
	mov r0, sp
	movs r5, #0
	strh r3, [r0]
	adds r4, r6, #0
	adds r4, #0x44
	ldr r2, _08039074 @ =0x01000010
	adds r1, r4, #0
	bl CpuSet
	adds r0, r4, #0
	bl sub_803C094
	adds r0, r6, #0
	bl sub_8038DEC
	movs r0, #0xb0
	str r0, [r6, #0x64]
	movs r0, #2
	movs r1, #0
	movs r2, #0xb0
	bl SetBgOffset
	ldr r3, _08039078 @ =gDispIo
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrb r1, [r3, #1]
	ands r0, r1
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r3, #1]
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
	movs r1, #8
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r5, [r0]
	ldr r0, _0803907C @ =0x0000FFE0
	ldrh r2, [r3, #0x3c]
	ands r0, r2
	movs r1, #4
	orrs r0, r1
	ldr r1, _08039080 @ =0x0000E0FF
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r3, #0x3c]
	adds r0, r6, #0
	bl sub_8038E90
	movs r0, #8
	bl EnableBgSync
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08039024: .4byte gUnk_08107820
_08039028: .4byte 0x06014800
_0803902C: .4byte gUnk_081088E8
_08039030: .4byte 0x06016000
_08039034: .4byte gUnk_08108B14
_08039038: .4byte 0x06016800
_0803903C: .4byte gUnk_08109A00
_08039040: .4byte gUnk_08109BA0
_08039044: .4byte gUnk_08109290
_08039048: .4byte 0x06000C00
_0803904C: .4byte gUnk_08109BE0
_08039050: .4byte gUnk_0810BAE0
_08039054: .4byte gUnk_0810D134
_08039058: .4byte gBg3Tm
_0803905C: .4byte gUnk_0810D1B4
_08039060: .4byte gFont_Unk_Sio_02001000
_08039064: .4byte 0x06012000
_08039068: .4byte Pal_SystemText
_0803906C: .4byte 0x0203C708
_08039070: .4byte gUnk_Sio_085C98F4
_08039074: .4byte 0x01000010
_08039078: .4byte gDispIo
_0803907C: .4byte 0x0000FFE0
_08039080: .4byte 0x0000E0FF

	thumb_func_start sub_8039084
sub_8039084: @ 0x08039084
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r0, #0x40
	ldrb r6, [r0]
	ldr r2, [r4, #0x64]
	subs r2, #1
	str r2, [r4, #0x64]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #2
	movs r1, #0
	bl SetBgOffset
	bl sub_8040F70
	adds r5, r4, #0
	adds r5, #0x41
	ldrb r0, [r5]
	cmp r0, #0
	beq _0803910E
	ldr r2, [r4, #0x64]
	asrs r2, r2, #3
	ldr r3, _08039124 @ =gUnk_Sio_0810F26C
	ldrb r0, [r5]
	subs r0, #1
	lsls r0, r0, #1
	lsls r1, r6, #3
	adds r0, r0, r1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r0, #4
	cmp r2, r0
	bne _0803910E
	adds r0, r4, #0
	bl sub_8038D64
	movs r0, #4
	bl EnableBgSync
	ldr r2, _08039128 @ =0x0203C984
	ldrb r1, [r5]
	subs r1, #1
	lsls r0, r1, #3
	adds r0, r4, r0
	adds r0, #0x44
	ldrb r3, [r0]
	lsls r0, r3, #1
	adds r2, #0x24
	adds r0, r0, r2
	ldrh r2, [r0]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp]
	adds r0, r4, #0
	movs r1, #0x28
	bl sub_8038D14
	ldrb r2, [r5]
	subs r2, #1
	lsls r2, r2, #2
	adds r1, r4, #0
	adds r1, #0x2c
	adds r1, r1, r2
	str r0, [r1]
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
_0803910E:
	ldr r0, [r4, #0x64]
	cmp r0, #0
	bne _0803911A
	adds r0, r4, #0
	bl Proc_Break
_0803911A:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08039124: .4byte gUnk_Sio_0810F26C
_08039128: .4byte 0x0203C984

	thumb_func_start sub_803912C
sub_803912C: @ 0x0803912C
	push {r4, lr}
	adds r4, r0, #0
	bl sub_8040F70
	ldr r0, _08039168 @ =gKeySt
	ldr r1, [r0]
	movs r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _08039162
	ldr r2, _0803916C @ =gMPlayTable
	ldr r1, _08039170 @ =gSongTable
	ldr r0, _08039174 @ =0x0000040C
	adds r1, r1, r0
	ldrh r3, [r1]
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	movs r1, #1
	bl m4aMPlayFadeOut
	adds r0, r4, #0
	bl Proc_Break
_08039162:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08039168: .4byte gKeySt
_0803916C: .4byte gMPlayTable
_08039170: .4byte gSongTable
_08039174: .4byte 0x0000040C

	thumb_func_start sub_8039178
sub_8039178: @ 0x08039178
	push {lr}
	ldr r0, [r0, #0x58]
	cmp r0, #0
	beq _0803918C
	movs r0, #0x46
	movs r1, #0
	movs r2, #0
	bl StartBgmExt
	b _08039196
_0803918C:
	movs r0, #0x4a
	movs r1, #0
	movs r2, #0
	bl StartBgmExt
_08039196:
	ldr r0, _080391AC @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt _080391A6
	movs r0, #0x81
	bl m4aSongNumStart
_080391A6:
	pop {r0}
	bx r0
	.align 2, 0
_080391AC: .4byte gPlaySt

	thumb_func_start sub_80391B0
sub_80391B0: @ 0x080391B0
	push {lr}
	movs r0, #0x4a
	movs r1, #0
	movs r2, #0
	bl StartBgmExt
	pop {r0}
	bx r0

	thumb_func_start sub_80391C0
sub_80391C0: @ 0x080391C0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r1
	mov sl, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r4, r3, #0
	movs r2, #0
	ldr r1, _080391F4 @ =0x0203C838
_080391DC:
	ldr r0, [r1]
	lsrs r0, r0, #5
	cmp r0, r4
	bhs _080391F8
	adds r7, r2, #0
	movs r2, #9
	lsls r3, r3, #5
	str r3, [sp, #4]
	cmp r2, r7
	ble _08039274
	b _08039206
	.align 2, 0
_080391F4: .4byte 0x0203C838
_080391F8:
	adds r1, #0x14
	adds r2, #1
	cmp r2, #9
	ble _080391DC
	movs r0, #1
	rsbs r0, r0, #0
	b _080392D8
_08039206:
	ldr r6, _080392E8 @ =0x0203C838
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r5, r1, r6
	subs r2, #1
	mov r8, r2
	lsls r4, r2, #2
	add r4, r8
	lsls r4, r4, #2
	adds r4, r4, r6
	ldrb r0, [r4]
	lsls r2, r0, #0x1e
	lsrs r2, r2, #0x1e
	movs r0, #4
	rsbs r0, r0, #0
	ldrb r3, [r5]
	ands r0, r3
	orrs r0, r2
	strb r0, [r5]
	ldr r3, [r4]
	lsrs r3, r3, #5
	lsls r3, r3, #5
	ldr r0, [r5]
	movs r2, #0x1f
	ands r0, r2
	orrs r0, r3
	str r0, [r5]
	movs r2, #0xc
	ldrb r0, [r4]
	ands r2, r0
	movs r0, #0xd
	rsbs r0, r0, #0
	ldrb r3, [r5]
	ands r0, r3
	orrs r0, r2
	strb r0, [r5]
	movs r3, #0x10
	ldrb r4, [r4]
	ands r3, r4
	movs r2, #0x11
	rsbs r2, r2, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r5]
	adds r0, r6, #0
	subs r0, #0x10
	adds r0, r1, r0
	adds r6, #4
	adds r1, r1, r6
	bl sub_80368DC
	mov r2, r8
	cmp r2, r7
	bgt _08039206
_08039274:
	ldr r5, _080392E8 @ =0x0203C838
	lsls r1, r7, #2
	adds r1, r1, r7
	lsls r1, r1, #2
	adds r4, r1, r5
	movs r3, #3
	ldr r2, [sp]
	ands r2, r3
	movs r0, #4
	rsbs r0, r0, #0
	ldrb r6, [r4]
	ands r0, r6
	orrs r0, r2
	strb r0, [r4]
	ldr r0, [r4]
	movs r2, #0x1f
	ands r0, r2
	ldr r2, [sp, #4]
	orrs r0, r2
	str r0, [r4]
	mov r6, sb
	ands r6, r3
	lsls r2, r6, #2
	movs r0, #0xd
	rsbs r0, r0, #0
	ldrb r3, [r4]
	ands r0, r3
	orrs r0, r2
	movs r2, #1
	mov r6, sl
	ands r6, r2
	lsls r3, r6, #4
	movs r2, #0x11
	rsbs r2, r2, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r4]
	ldr r0, _080392EC @ =gUnk_Sio_085C98F4
	ldr r0, [r0]
	movs r2, #6
	ldrsb r2, [r0, r2]
	lsls r0, r2, #4
	subs r0, r0, r2
	ldr r2, _080392F0 @ =0x0203C6B9
	adds r0, r0, r2
	adds r5, #4
	adds r1, r1, r5
	bl sub_80368DC
	adds r0, r7, #0
_080392D8:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080392E8: .4byte 0x0203C838
_080392EC: .4byte gUnk_Sio_085C98F4
_080392F0: .4byte 0x0203C6B9

	thumb_func_start sub_80392F4
sub_80392F4: @ 0x080392F4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldr r0, _08039364 @ =0x0203C618
	adds r1, r0, #0
	adds r1, #0xec
	ldrb r1, [r1]
	lsls r5, r1, #0x1e
	lsrs r5, r5, #0x1f
	adds r0, #0xa0
	ldrb r0, [r0]
	subs r0, #1
	mov sb, r0
	bl sub_803D208
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r1, _08039368 @ =0x0203C984
	ldr r0, _0803936C @ =gUnk_Sio_085C98F4
	ldr r0, [r0]
	ldrb r0, [r0, #6]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r1, #0x14
	adds r0, r0, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r6, _08039370 @ =0x0203C838
	adds r0, r6, #0
	bl sub_80864CC
	adds r0, r4, #0
	mov r1, sb
	adds r2, r5, #0
	mov r3, r8
	bl sub_80391C0
	str r0, [r7, #0x58]
	adds r0, r6, #0
	bl sub_8086490
	ldr r1, [r7, #0x58]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08039374
	adds r0, r1, #0
	adds r1, r7, #0
	bl sub_803AE58
	b _0803937A
	.align 2, 0
_08039364: .4byte 0x0203C618
_08039368: .4byte 0x0203C984
_0803936C: .4byte gUnk_Sio_085C98F4
_08039370: .4byte 0x0203C838
_08039374:
	movs r0, #1
	bl FadeBgmOut
_0803937A:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8039388
sub_8039388: @ 0x08039388
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r1, _0803940C @ =gUnk_Sio_0810F294
	mov r0, sp
	movs r2, #3
	bl memcpy
	bl InitUnits
	movs r6, #0
	ldr r1, _08039410 @ =0x0203C618
	ldrb r0, [r1, #5]
	adds r0, #2
	cmp r6, r0
	bge _08039460
	mov sb, r1
_080393B0:
	lsls r4, r6, #6
	adds r4, #1
	adds r0, r4, #0
	bl GetUnit
	adds r5, r0, #0
	mov r0, sb
	adds r0, #6
	adds r0, r6, r0
	ldrb r0, [r0]
	lsls r2, r6, #4
	subs r2, r2, r6
	ldr r1, _08039414 @ =0x0203C6B9
	adds r2, r2, r1
	adds r1, r5, #0
	bl sub_808642C
	movs r7, #0
	adds r2, r6, #1
	mov sl, r2
	lsls r0, r6, #1
	ldr r1, _08039418 @ =0x0203C9A8
	adds r0, r0, r1
	mov r8, r0
_080393E0:
	adds r0, r4, #0
	bl GetUnit
	adds r5, r0, #0
	movs r2, #0
	strb r2, [r5, #9]
	movs r1, #0
	bl SetUnitStatus
	movs r0, #0
	strb r0, [r5, #0x19]
	movs r0, #4
	ldr r1, _0803941C @ =0x0203C704
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _08039420
	adds r0, r5, #0
	bl sub_8036CB0
	b _08039426
	.align 2, 0
_0803940C: .4byte gUnk_Sio_0810F294
_08039410: .4byte 0x0203C618
_08039414: .4byte 0x0203C6B9
_08039418: .4byte 0x0203C9A8
_0803941C: .4byte 0x0203C704
_08039420:
	adds r0, r5, #0
	bl sub_8040CA8
_08039426:
	cmp r7, #0
	bne _08039434
	adds r0, r5, #0
	bl GetUnitChibiId
	mov r2, r8
	strh r0, [r2]
_08039434:
	strb r4, [r5, #0xb]
	cmp r6, #0
	beq _0803944C
	movs r0, #1
	ldr r1, _08039498 @ =0x0203C704
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _0803944C
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r5, #0xc]
_0803944C:
	adds r4, #1
	adds r7, #1
	cmp r7, #4
	ble _080393E0
	mov r6, sl
	mov r2, sb
	ldrb r0, [r2, #5]
	adds r0, #2
	cmp r6, r0
	blt _080393B0
_08039460:
	ldr r0, _0803949C @ =0x0203C984
	movs r1, #0
	strb r1, [r0]
	ldr r2, _080394A0 @ =gUnk_Sio_085C98F4
	ldr r0, [r2]
	strb r1, [r0, #6]
	ldr r3, [r2]
	ldr r1, _080394A4 @ =0x0203C618
	ldrb r0, [r1, #5]
	add r0, sp
	ldrb r0, [r0]
	strb r0, [r3, #9]
	ldr r2, [r2]
	ldrb r0, [r1, #5]
	adds r0, #2
	strb r0, [r2, #7]
	ldrb r0, [r1, #5]
	adds r0, #2
	adds r1, #0xa0
	strb r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08039498: .4byte 0x0203C704
_0803949C: .4byte 0x0203C984
_080394A0: .4byte gUnk_Sio_085C98F4
_080394A4: .4byte 0x0203C618

	thumb_func_start sub_80394A8
sub_80394A8: @ 0x080394A8
	push {lr}
	ldr r0, _080394B8 @ =gUnk_Sio_085CAD04
	movs r1, #2
	bl SpawnProc
	pop {r0}
	bx r0
	.align 2, 0
_080394B8: .4byte gUnk_Sio_085CAD04

	thumb_func_start sub_80394BC
sub_80394BC: @ 0x080394BC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080394F4 @ =gUnk_Sio_085CAD04
	bl Proc_Find
	cmp r0, #0
	bne _080394EE
	ldr r5, _080394F8 @ =0x0203C618
	ldrb r0, [r5, #0xb]
	cmp r0, #1
	bne _080394DA
	adds r0, r4, #0
	movs r1, #1
	bl Proc_Goto
_080394DA:
	ldrb r5, [r5, #0xb]
	cmp r5, #2
	bne _080394E8
	adds r0, r4, #0
	movs r1, #4
	bl Proc_Goto
_080394E8:
	adds r0, r4, #0
	bl Proc_Break
_080394EE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080394F4: .4byte gUnk_Sio_085CAD04
_080394F8: .4byte 0x0203C618

	thumb_func_start sub_80394FC
sub_80394FC: @ 0x080394FC
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	mov r8, r0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r6, r3, #0
	bl SetInitTalkTextFont
	bl ClearTalkText
	bl ResetTextFont
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, r8
	adds r3, r6, #0
	bl StartTalkExt
	movs r0, #1
	bl SetTalkPrintColor
	movs r0, #1
	bl SetTalkFlag
	movs r0, #2
	bl SetTalkFlag
	movs r0, #4
	bl SetTalkFlag
	movs r0, #2
	bl SetTalkPrintDelay
	movs r0, #1
	bl SetActiveTalkFace
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_8039550
sub_8039550: @ 0x08039550
	push {lr}
	ldr r0, _08039568 @ =gUnk_Sio_085C9968
	bl Proc_EndEach
	ldr r0, _0803956C @ =gUnk_Sio_085C9990
	bl Proc_EndEach
	ldr r0, _08039570 @ =gUnk_Sio_085C9940
	bl Proc_EndEach
	pop {r0}
	bx r0
	.align 2, 0
_08039568: .4byte gUnk_Sio_085C9968
_0803956C: .4byte gUnk_Sio_085C9990
_08039570: .4byte gUnk_Sio_085C9940

	thumb_func_start sub_8039574
sub_8039574: @ 0x08039574
	push {lr}
	bl sub_8035490
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8039580
sub_8039580: @ 0x08039580
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r6, #0
	ldr r0, _080395F8 @ =0x0203C618
	mov sb, r0
	movs r1, #0x98
	lsls r1, r1, #2
	mov r8, r1
	movs r0, #0xa1
	add r0, sb
	mov sl, r0
	movs r7, #5
_080395A0:
	mov r0, sb
	adds r0, #0x9c
	adds r5, r6, r0
	ldr r0, _080395FC @ =gUnk_Sio_085C98F4
	ldr r0, [r0]
	adds r0, #0xb
	adds r0, r0, r6
	ldrb r0, [r0]
	ldrb r1, [r5]
	cmp r1, r0
	beq _0803962C
	strb r0, [r5]
	lsls r1, r6, #3
	mov r0, sb
	adds r0, #0xc
	adds r4, r1, r0
	adds r0, r4, #0
	bl ClearText
	adds r0, r4, #0
	movs r1, #0
	bl Text_SetColor
	ldrb r0, [r5]
	cmp r0, #4
	bhi _08039608
	ldr r1, _08039600 @ =gUnk_Sio_085C99B0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	movs r0, #0xa
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0xa
	adds r2, r7, #0
	bl PutDrawTextCentered
	ldr r0, _08039604 @ =gUnk_08109C60
	mov r1, r8
	movs r2, #0x20
	bl ApplyPaletteExt
	b _08039626
	.align 2, 0
_080395F8: .4byte 0x0203C618
_080395FC: .4byte gUnk_Sio_085C98F4
_08039600: .4byte gUnk_Sio_085C99B0
_08039604: .4byte gUnk_08109C60
_08039608:
	movs r0, #0xa
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0xa
	adds r2, r7, #0
	mov r3, sl
	bl PutDrawTextCentered
	lsls r0, r6, #5
	ldr r1, _0803964C @ =gUnk_08109A00
	adds r0, r0, r1
	mov r1, r8
	movs r2, #0x20
	bl ApplyPaletteExt
_08039626:
	movs r0, #1
	bl EnableBgSync
_0803962C:
	movs r1, #0x20
	add r8, r1
	movs r0, #0xf
	add sl, r0
	adds r7, #3
	adds r6, #1
	cmp r6, #3
	ble _080395A0
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803964C: .4byte gUnk_08109A00

	thumb_func_start sub_8039650
sub_8039650: @ 0x08039650
	push {r4, r5, r6, lr}
	sub sp, #0x18
	adds r6, r0, #0
	bl sub_8036B40
	bl sub_803FA14
	ldr r0, _0803976C @ =gUnk_08107820
	ldr r1, _08039770 @ =0x06014800
	bl Decompress
	ldr r0, _08039774 @ =gUnk_081088E8
	ldr r1, _08039778 @ =0x06016000
	bl Decompress
	ldr r0, _0803977C @ =gUnk_081080D4
	ldr r1, _08039780 @ =0x06016800
	bl Decompress
	movs r4, #0x98
	lsls r4, r4, #2
	movs r5, #3
_0803967C:
	ldr r0, _08039784 @ =gUnk_08109C60
	adds r1, r4, #0
	movs r2, #0x20
	bl ApplyPaletteExt
	adds r4, #0x20
	subs r5, #1
	cmp r5, #0
	bge _0803967C
	movs r0, #0
	movs r1, #2
	bl sub_803FAA4
	ldr r4, _08039788 @ =0x0203C618
	ldrb r0, [r4, #3]
	add r1, sp, #8
	bl sub_8086220
	ldr r0, _0803978C @ =0x0203C758
	bl SetTextFont
	bl InitSystemTextFont
	bl ResetTextFont
	bl sub_8036C60
	movs r5, #0
	adds r4, #0x9c
	movs r2, #0xff
_080396B8:
	adds r1, r5, r4
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	adds r5, #1
	cmp r5, #3
	ble _080396B8
	bl sub_8039580
	movs r5, #0
	ldr r2, _08039790 @ =0x030044E6
_080396CE:
	adds r0, r5, r2
	mov r1, sp
	adds r1, r1, r5
	adds r1, #8
	ldrb r1, [r1]
	strb r1, [r0]
	adds r5, #1
	cmp r5, #0xe
	ble _080396CE
	movs r0, #0
	str r0, [r6, #0x34]
	str r0, [r6, #0x30]
	movs r0, #0xc0
	movs r1, #0x10
	adds r2, r6, #0
	bl sub_803F9C4
	movs r0, #0x48
	movs r1, #0x20
	adds r2, r6, #0
	bl sub_8040F00
	str r0, [r6, #0x2c]
	ldr r0, _08039794 @ =gUnk_Sio_085C9E88
	bl SetFaceConfig
	movs r0, #2
	str r0, [sp]
	movs r0, #3
	movs r1, #0xc0
	movs r2, #0xd0
	movs r3, #0x50
	bl StartFace
	ldr r0, [r6, #0x2c]
	ldr r1, _08039798 @ =gUnk_Sio_0810F19C
	ldr r4, _08039788 @ =0x0203C618
	ldrb r2, [r4]
	adds r1, r2, r1
	ldrb r1, [r1]
	bl sub_803FC3C
	ldr r0, _0803979C @ =gUnk_Sio_085C9AD4
	ldrb r3, [r4]
	lsls r1, r3, #2
	adds r0, r1, r0
	ldr r0, [r0]
	ldr r2, _080397A0 @ =gUnk_Sio_0810F190
	adds r1, r1, r2
	ldr r1, [r1]
	str r3, [sp]
	ldr r2, [r6, #0x2c]
	str r2, [sp, #4]
	movs r2, #0
	movs r3, #8
	bl sub_803FD40
	ldr r0, [r6, #0x30]
	ldr r1, _080397A4 @ =0x000006D7
	adds r0, r0, r1
	movs r1, #1
	bl sub_8036BFC
	ldr r2, _080397A8 @ =gDispIo
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
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803976C: .4byte gUnk_08107820
_08039770: .4byte 0x06014800
_08039774: .4byte gUnk_081088E8
_08039778: .4byte 0x06016000
_0803977C: .4byte gUnk_081080D4
_08039780: .4byte 0x06016800
_08039784: .4byte gUnk_08109C60
_08039788: .4byte 0x0203C618
_0803978C: .4byte 0x0203C758
_08039790: .4byte 0x030044E6
_08039794: .4byte gUnk_Sio_085C9E88
_08039798: .4byte gUnk_Sio_0810F19C
_0803979C: .4byte gUnk_Sio_085C9AD4
_080397A0: .4byte gUnk_Sio_0810F190
_080397A4: .4byte 0x000006D7
_080397A8: .4byte gDispIo

	thumb_func_start sub_80397AC
sub_80397AC: @ 0x080397AC
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, _080397E4 @ =0x00002586
	mov r0, sp
	strh r1, [r0]
	ldr r0, _080397E8 @ =gUnk_Sio_085C9968
	movs r1, #0
	bl SpawnProc
	ldr r0, _080397EC @ =gUnk_Sio_085C9990
	adds r1, r4, #0
	bl SpawnProc
	ldr r0, _080397F0 @ =gUnk_Sio_085C9940
	adds r1, r4, #0
	bl SpawnProc
	movs r1, #1
	rsbs r1, r1, #0
	mov r0, sp
	bl sub_8036078
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080397E4: .4byte 0x00002586
_080397E8: .4byte gUnk_Sio_085C9968
_080397EC: .4byte gUnk_Sio_085C9990
_080397F0: .4byte gUnk_Sio_085C9940

	thumb_func_start sub_80397F4
sub_80397F4: @ 0x080397F4
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r6, #0
	movs r1, #0
	ldr r5, [r4, #0x2c]
	ldr r0, _08039834 @ =0x0203C91C
	str r1, [r0]
	mov r0, sp
	strb r1, [r0]
	bl sub_8039580
	ldr r0, _08039838 @ =gUnk_Sio_085C9940
	bl Proc_Find
	cmp r0, #0
	beq _08039840
	ldr r0, _0803983C @ =gKeySt
	ldr r1, [r0]
	movs r0, #2
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	bne _08039826
	b _08039A0A
_08039826:
	movs r0, #1
	bl sub_8036D08
	bl sub_803F9F4
	b _08039874
	.align 2, 0
_08039834: .4byte 0x0203C91C
_08039838: .4byte gUnk_Sio_085C9940
_0803983C: .4byte gKeySt
_08039840:
	bl sub_803F9F4
	ldr r2, _08039888 @ =gUnk_Sio_085C98F4
	ldr r1, [r2]
	movs r0, #6
	ldrsb r0, [r1, r0]
	str r0, [r5, #0x34]
	movs r3, #0
	adds r1, #0x1a
	adds r5, r2, #0
_08039854:
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0x3c
	bls _0803985E
	adds r6, #1
_0803985E:
	adds r3, #1
	cmp r3, #3
	ble _08039854
	ldr r0, [r5]
	movs r1, #6
	ldrsb r1, [r0, r1]
	adds r0, #0xb
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #2
	bne _0803988C
_08039874:
	bl sub_8039550
	bl sub_8039574
	adds r0, r4, #0
	movs r1, #2
	bl Proc_Goto
	b _08039A0A
	.align 2, 0
_08039888: .4byte gUnk_Sio_085C98F4
_0803988C:
	bl sub_8035CF8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080398A2
	ldr r0, [r5]
	ldrb r1, [r0, #0x1e]
	cmp r1, #0x3c
	bhi _080398A2
	cmp r6, #0
	beq _080398CC
_080398A2:
	bl sub_8039550
	bl sub_8039574
	adds r0, r4, #0
	bl sub_80397AC
	movs r0, #0
	str r0, [r4, #0x30]
	ldr r0, _080398C8 @ =0x000006D7
	movs r1, #1
	bl sub_8036BFC
	movs r0, #0xc0
	movs r1, #0x10
	adds r2, r4, #0
	bl sub_803F9C4
	b _08039A0A
	.align 2, 0
_080398C8: .4byte 0x000006D7
_080398CC:
	ldrb r0, [r0, #6]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08039960
	bl sub_8035D7C
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _08039960
	ldr r0, [r4, #0x30]
	cmp r0, #2
	beq _080398F4
	movs r0, #2
	str r0, [r4, #0x30]
	ldr r0, _08039950 @ =0x000006D9
	movs r1, #1
	bl sub_8036BFC
_080398F4:
	ldr r0, _08039954 @ =gKeySt
	ldr r1, [r0]
	movs r0, #8
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _08039974
	ldr r0, [r5]
	movs r2, #0
	movs r1, #6
	strh r1, [r0, #4]
	strb r2, [r0, #0x1e]
	movs r3, #0
	adds r2, r5, #0
	movs r1, #0
_08039912:
	ldr r0, [r2]
	adds r0, #0x1a
	adds r0, r0, r3
	strb r1, [r0]
	adds r3, #1
	cmp r3, #3
	ble _08039912
	movs r0, #2
	bl sub_8036D08
	bl sub_8035C58
	ldr r2, _08039958 @ =gUnk_Sio_085C98F4
	ldr r1, [r2]
	strb r0, [r1, #7]
	ldr r0, _0803995C @ =0x0203C618
	ldr r1, [r2]
	ldrb r1, [r1, #7]
	adds r0, #0xa0
	strb r1, [r0]
	bl sub_8036608
	mov r1, sp
	movs r0, #0x18
	strb r0, [r1]
	mov r0, sp
	movs r1, #4
	bl sub_8036208
	str r0, [r4, #0x34]
	b _080399D2
	.align 2, 0
_08039950: .4byte 0x000006D9
_08039954: .4byte gKeySt
_08039958: .4byte gUnk_Sio_085C98F4
_0803995C: .4byte 0x0203C618
_08039960:
	ldr r0, [r4, #0x30]
	cmp r0, #1
	beq _08039974
	movs r0, #1
	str r0, [r4, #0x30]
	movs r0, #0xdb
	lsls r0, r0, #3
	movs r1, #1
	bl sub_8036BFC
_08039974:
	ldr r5, _080399DC @ =gUnk_Sio_085C98F4
	ldr r1, [r5]
	movs r0, #6
	ldrsb r0, [r1, r0]
	cmp r0, #0
	beq _080399E4
	ldrb r0, [r1, #6]
	bl sub_8035CB0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080399E4
	add r1, sp, #4
	mov r0, sp
	movs r2, #0
	bl sub_80362B0
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080399E4
	ldr r0, [r5]
	movs r2, #0
	movs r1, #6
	strh r1, [r0, #4]
	strb r2, [r0, #0x1e]
	movs r3, #0
	adds r2, r5, #0
	movs r1, #0
_080399AC:
	ldr r0, [r2]
	adds r0, #0x1a
	adds r0, r0, r3
	strb r1, [r0]
	adds r3, #1
	cmp r3, #3
	ble _080399AC
	bl sub_8035C58
	ldr r2, _080399DC @ =gUnk_Sio_085C98F4
	ldr r1, [r2]
	strb r0, [r1, #7]
	ldr r0, _080399E0 @ =0x0203C618
	ldr r1, [r2]
	ldrb r1, [r1, #7]
	adds r0, #0xa0
	strb r1, [r0]
	bl sub_8036608
_080399D2:
	adds r0, r4, #0
	bl Proc_Break
	b _08039A0A
	.align 2, 0
_080399DC: .4byte gUnk_Sio_085C98F4
_080399E0: .4byte 0x0203C618
_080399E4:
	bl GetGameTime
	movs r1, #0x26
	bl __umodsi3
	cmp r0, #0
	bne _08039A0A
	ldr r0, _08039A14 @ =0x030044E0
	movs r1, #0x1c
	strb r1, [r0]
	ldr r1, _08039A18 @ =gUnk_Sio_085C98F4
	ldr r2, [r1]
	ldrb r1, [r2, #6]
	strb r1, [r0, #1]
	ldrb r1, [r2]
	strh r1, [r0, #2]
	movs r1, #0x16
	bl sub_8035DC8
_08039A0A:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08039A14: .4byte 0x030044E0
_08039A18: .4byte gUnk_Sio_085C98F4

	thumb_func_start sub_8039A1C
sub_8039A1C: @ 0x08039A1C
	push {r4, lr}
	adds r4, r0, #0
	bl sub_8039580
	ldr r1, _08039A74 @ =0x0203C91C
	ldr r0, [r1]
	adds r3, r0, #1
	str r3, [r1]
	ldr r0, _08039A78 @ =0x0203C618
	adds r0, #0xa0
	ldr r1, _08039A7C @ =gUnk_Sio_085C98F4
	ldr r2, [r1]
	ldrb r0, [r0]
	ldrb r1, [r2, #7]
	cmp r0, r1
	bne _08039A44
	movs r0, #0x96
	lsls r0, r0, #2
	cmp r3, r0
	ble _08039A84
_08039A44:
	bl sub_8039550
	bl sub_8039574
	adds r0, r4, #0
	bl sub_80397AC
	movs r0, #0
	str r0, [r4, #0x30]
	ldr r0, _08039A80 @ =0x000006D7
	movs r1, #1
	bl sub_8036BFC
	movs r0, #0xc0
	movs r1, #0x10
	adds r2, r4, #0
	bl sub_803F9C4
	adds r0, r4, #0
	movs r1, #3
	bl Proc_Goto
	b _08039AA8
	.align 2, 0
_08039A74: .4byte 0x0203C91C
_08039A78: .4byte 0x0203C618
_08039A7C: .4byte gUnk_Sio_085C98F4
_08039A80: .4byte 0x000006D7
_08039A84:
	movs r0, #6
	ldrsb r0, [r2, r0]
	cmp r0, #0
	bne _08039AB0
	ldr r1, [r4, #0x34]
	movs r0, #0x8c
	muls r0, r1, r0
	adds r0, r2, r0
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r1, [r2, #9]
	ldrb r0, [r0]
	ands r1, r0
	adds r0, r1, #0
	ldrb r2, [r2, #9]
	cmp r0, r2
	bne _08039AB6
_08039AA8:
	adds r0, r4, #0
	bl Proc_Break
	b _08039AB6
_08039AB0:
	adds r0, r4, #0
	bl Proc_Break
_08039AB6:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_8039ABC
sub_8039ABC: @ 0x08039ABC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	movs r0, #0xdb
	lsls r0, r0, #3
	movs r1, #1
	bl sub_8036BFC
	ldr r0, _08039B54 @ =gUnk_Sio_085C98F4
	ldr r0, [r0]
	ldrb r0, [r0, #6]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08039B3E
	bl GetGameTime
	ldr r4, _08039B58 @ =0x0203C618
	adds r5, r4, #0
	adds r5, #0xa0
	ldrb r1, [r5]
	bl __umodsi3
	adds r6, r7, #0
	adds r6, #0x3b
	strb r0, [r6]
	bl RandNextB
	movs r1, #3
	ands r1, r0
	adds r1, #4
	ldrb r5, [r5]
	adds r3, r5, #0
	muls r3, r1, r3
	ldrb r0, [r6]
	adds r3, r0, r3
	adds r0, r7, #0
	adds r0, #0x39
	strb r3, [r0]
	mov r2, sp
	adds r4, #0xec
	ldrb r1, [r4]
	lsls r0, r1, #0x1f
	lsrs r0, r0, #0x1f
	strb r0, [r2]
	lsls r0, r1, #0x1d
	lsrs r0, r0, #0x1f
	strb r0, [r2, #1]
	mov r0, sp
	lsls r1, r1, #0x1e
	lsrs r1, r1, #0x1f
	strb r1, [r0, #2]
	mov r1, sp
	ldrb r0, [r6]
	strb r0, [r1, #3]
	mov r0, sp
	strb r3, [r0, #4]
	adds r0, #6
	bl RandGetSt
	mov r0, sp
	movs r1, #0x10
	bl sub_8036208
	str r0, [r7, #0x34]
_08039B3E:
	adds r0, r7, #0
	adds r0, #0x3a
	movs r1, #0
	strb r1, [r0]
	subs r0, #2
	strb r1, [r0]
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08039B54: .4byte gUnk_Sio_085C98F4
_08039B58: .4byte 0x0203C618

	thumb_func_start sub_8039B5C
sub_8039B5C: @ 0x08039B5C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r5, r0, #0
	ldr r7, [r5, #0x2c]
	ldr r0, _08039B98 @ =gUnk_Sio_085C98F4
	ldr r2, [r0]
	movs r4, #6
	ldrsb r4, [r2, r4]
	cmp r4, #0
	bne _08039BA0
	ldr r1, [r5, #0x34]
	movs r0, #0x8c
	muls r0, r1, r0
	adds r0, r2, r0
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	ldrb r2, [r2, #9]
	cmp r0, r2
	bne _08039C20
	ldr r0, _08039B9C @ =0x000006DD
	movs r1, #1
	bl sub_8036BFC
	str r4, [r7, #0x38]
	adds r0, r5, #0
	bl Proc_Break
	b _08039C20
	.align 2, 0
_08039B98: .4byte gUnk_Sio_085C98F4
_08039B9C: .4byte 0x000006DD
_08039BA0:
	bl GetGameTime
	movs r1, #0x26
	bl __umodsi3
	adds r6, r0, #0
	cmp r6, #0
	bne _08039C20
	add r1, sp, #0x10
	mov r0, sp
	movs r2, #0
	bl sub_80362B0
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08039C20
	ldr r4, _08039C28 @ =0x0203C618
	mov r0, sp
	adds r4, #0xec
	movs r3, #1
	ldrb r1, [r0]
	ands r1, r3
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r2, [r4]
	ands r0, r2
	orrs r0, r1
	mov r1, sp
	ldrb r1, [r1, #1]
	ands r1, r3
	lsls r1, r1, #2
	movs r2, #5
	rsbs r2, r2, #0
	ands r0, r2
	orrs r0, r1
	mov r1, sp
	ldrb r1, [r1, #2]
	ands r1, r3
	lsls r1, r1, #1
	adds r2, #2
	ands r0, r2
	orrs r0, r1
	strb r0, [r4]
	mov r0, sp
	ldrb r0, [r0, #3]
	adds r1, r5, #0
	adds r1, #0x3b
	strb r0, [r1]
	mov r0, sp
	ldrb r0, [r0, #4]
	subs r1, #2
	strb r0, [r1]
	mov r0, sp
	adds r0, #6
	bl RandSetSt
	ldr r0, _08039C2C @ =0x000006DD
	movs r1, #1
	bl sub_8036BFC
	str r6, [r7, #0x38]
	adds r0, r5, #0
	bl Proc_Break
_08039C20:
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08039C28: .4byte 0x0203C618
_08039C2C: .4byte 0x000006DD

	thumb_func_start sub_8039C30
sub_8039C30: @ 0x08039C30
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r7, [r6, #0x2c]
	adds r1, r6, #0
	adds r1, #0x38
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x10
	bls _08039CD0
	movs r0, #0
	strb r0, [r1]
	adds r4, r6, #0
	adds r4, #0x3a
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldr r1, _08039CA8 @ =0x0203C618
	adds r1, #0xa0
	ldrb r0, [r4]
	ldrb r1, [r1]
	bl __umodsi3
	strb r0, [r4]
	adds r5, r6, #0
	adds r5, #0x39
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	ldrb r0, [r4]
	str r0, [r7, #0x38]
	ldr r0, _08039CAC @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt _08039C82
	movs r0, #0x7d
	bl m4aSongNumStart
_08039C82:
	ldrb r0, [r5]
	cmp r0, #0
	bne _08039CD0
	adds r0, r6, #0
	adds r0, #0x3b
	ldr r1, _08039CB0 @ =gUnk_Sio_085C98F4
	ldr r1, [r1]
	ldrb r2, [r0]
	adds r4, r0, #0
	ldrb r0, [r4]
	ldrb r1, [r1, #6]
	cmp r0, r1
	beq _08039CB8
	ldr r1, _08039CB4 @ =0x000006DF
	adds r0, r2, r1
	movs r1, #1
	bl sub_8036BFC
	b _08039CC0
	.align 2, 0
_08039CA8: .4byte 0x0203C618
_08039CAC: .4byte gPlaySt
_08039CB0: .4byte gUnk_Sio_085C98F4
_08039CB4: .4byte 0x000006DF
_08039CB8:
	ldr r0, _08039CD8 @ =0x000006DE
	movs r1, #1
	bl sub_8036BFC
_08039CC0:
	ldrb r0, [r4]
	str r0, [r7, #0x38]
	ldr r1, _08039CDC @ =0x0203C984
	ldrb r0, [r4]
	strb r0, [r1]
	adds r0, r6, #0
	bl Proc_Break
_08039CD0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08039CD8: .4byte 0x000006DE
_08039CDC: .4byte 0x0203C984

	thumb_func_start sub_8039CE0
sub_8039CE0: @ 0x08039CE0
	push {lr}
	ldr r0, _08039CF8 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt _08039CF2
	movs r0, #0x7e
	bl m4aSongNumStart
_08039CF2:
	pop {r0}
	bx r0
	.align 2, 0
_08039CF8: .4byte gPlaySt

	thumb_func_start sub_8039CFC
sub_8039CFC: @ 0x08039CFC
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
	strb r4, [r5, #9]
	movs r1, #0
	bl SetUnitStatus
	strb r4, [r5, #0x19]
	ldr r1, _08039D24 @ =0x0203C618
	adds r1, #0xec
	movs r0, #4
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _08039D28
	adds r0, r5, #0
	bl sub_8036CB0
	b _08039D2E
	.align 2, 0
_08039D24: .4byte 0x0203C618
_08039D28:
	adds r0, r5, #0
	bl sub_8040CA8
_08039D2E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start sub_8039D34
sub_8039D34: @ 0x08039D34
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r0
	ldr r0, _08039DF0 @ =gUnk_Sio_085C98F4
	ldr r0, [r0]
	ldrb r0, [r0, #6]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #6
	adds r0, #1
	mov r8, r0
	ldr r1, _08039DF4 @ =0x0203C91C
	movs r0, #0
	str r0, [r1]
	bl InitUnits
	ldr r0, _08039DF8 @ =0x0203C618
	ldrb r0, [r0, #3]
	ldr r4, _08039DFC @ =gUnk_Sio_085C9EA8
	ldr r1, [r4]
	bl sub_80861EC
	movs r6, #0
	ldr r0, _08039E00 @ =0x0203C9A8
	mov sl, r0
	movs r7, #0x10
_08039D6E:
	mov r1, r8
	adds r4, r1, r6
	adds r0, r4, #0
	bl GetUnit
	adds r5, r0, #0
	bl ClearUnit
	ldr r1, _08039DFC @ =gUnk_Sio_085C9EA8
	ldr r0, [r1]
	adds r0, r0, r7
	adds r1, r5, #0
	bl sub_80855C4
	adds r0, r5, #0
	bl sub_8039CFC
	strb r4, [r5, #0xb]
	cmp r6, #0
	bne _08039DAC
	adds r0, r5, #0
	bl GetUnitChibiId
	ldr r1, _08039DF0 @ =gUnk_Sio_085C98F4
	ldr r1, [r1]
	ldrb r1, [r1, #6]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	lsls r1, r1, #1
	add r1, sl
	strh r0, [r1]
_08039DAC:
	adds r7, #0x28
	adds r6, #1
	cmp r6, #4
	ble _08039D6E
	ldr r2, _08039DF0 @ =gUnk_Sio_085C98F4
	mov r3, sb
	adds r3, #0x64
	mov r4, sb
	adds r4, #0x4c
	ldr r0, _08039DF8 @ =0x0203C618
	movs r1, #0
	movs r6, #3
	adds r0, #0x9f
_08039DC6:
	strb r1, [r0]
	subs r0, #1
	subs r6, #1
	cmp r6, #0
	bge _08039DC6
	ldr r2, [r2]
	movs r1, #6
	ldrsb r1, [r2, r1]
	movs r0, #1
	lsls r0, r1
	movs r1, #0
	strb r0, [r2, #0xa]
	strh r1, [r3]
	strh r1, [r4]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08039DF0: .4byte gUnk_Sio_085C98F4
_08039DF4: .4byte 0x0203C91C
_08039DF8: .4byte 0x0203C618
_08039DFC: .4byte gUnk_Sio_085C9EA8
_08039E00: .4byte 0x0203C9A8

	thumb_func_start sub_8039E04
sub_8039E04: @ 0x08039E04
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	mov r8, r0
	movs r0, #0
	mov sl, r0
	mov r0, r8
	adds r0, #0x4c
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _08039E32
	ldr r0, _08039F6C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt _08039E32
	movs r0, #0x7c
	bl m4aSongNumStart
_08039E32:
	mov r1, r8
	adds r1, #0x4c
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x17
	ble _08039E48
	movs r0, #0
	strh r0, [r1]
_08039E48:
	mov r4, r8
	adds r4, #0x64
	movs r3, #0
	ldrsh r0, [r4, r3]
	cmp r0, #4
	bgt _08039E88
	ldr r2, _08039F70 @ =gUnk_Sio_085C9EA8
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, #0x10
	ldr r0, [r2]
	adds r0, r0, r1
	movs r1, #0x28
	bl sub_8036208
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r3, r8
	str r0, [r3, #0x58]
	ldrh r2, [r4]
	adds r2, #1
	strh r2, [r4]
	ldr r1, _08039F74 @ =0x0203C618
	ldr r0, _08039F78 @ =gUnk_Sio_085C98F4
	ldr r0, [r0]
	ldrb r0, [r0, #6]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r1, #0x9c
	adds r0, r0, r1
	strb r2, [r0]
_08039E88:
	bl GetGameTime
	movs r1, #0x26
	bl __umodsi3
	cmp r0, #0
	bne _08039F5C
	add r6, sp, #0x28
	mov r0, sp
	adds r1, r6, #0
	movs r2, #0
	bl sub_80362B0
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08039F18
	ldrb r0, [r6]
	lsls r4, r0, #6
	adds r4, #1
	ldr r1, _08039F74 @ =0x0203C618
	mov sb, r1
	mov r7, sb
	adds r7, #0x9c
	adds r0, r0, r7
	ldrb r0, [r0]
	adds r0, r0, r4
	bl GetUnit
	adds r5, r0, #0
	bl ClearUnit
	mov r0, sp
	adds r1, r5, #0
	bl sub_80855C4
	adds r0, r5, #0
	bl sub_8039CFC
	ldrb r3, [r6]
	adds r0, r3, r7
	ldrb r0, [r0]
	adds r4, r0, r4
	strb r4, [r5, #0xb]
	ldrb r1, [r6]
	adds r0, r1, r7
	ldrb r0, [r0]
	cmp r0, #0
	bne _08039EFA
	adds r0, r5, #0
	bl GetUnitChibiId
	ldr r1, _08039F7C @ =0x0203C984
	ldrb r3, [r6]
	lsls r2, r3, #1
	adds r1, #0x24
	adds r2, r2, r1
	strh r0, [r2]
_08039EFA:
	mov r1, sb
	adds r1, #0xec
	movs r0, #1
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _08039F0E
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r5, #0xc]
_08039F0E:
	ldrb r6, [r6]
	adds r1, r6, r7
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08039F18:
	movs r4, #0
	ldr r5, _08039F80 @ =0x0203C6B4
_08039F1C:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl sub_8035CB0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08039F3C
	adds r0, r4, r5
	ldrb r0, [r0]
	cmp r0, #4
	bhi _08039F3C
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
_08039F3C:
	adds r4, #1
	cmp r4, #3
	ble _08039F1C
	mov r0, sl
	cmp r0, #0
	bne _08039F5C
	ldr r0, _08039F78 @ =gUnk_Sio_085C98F4
	ldr r2, [r0]
	movs r1, #6
	ldrsb r1, [r2, r1]
	movs r0, #1
	lsls r0, r1
	strb r0, [r2, #0xa]
	mov r0, r8
	bl Proc_Break
_08039F5C:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08039F6C: .4byte gPlaySt
_08039F70: .4byte gUnk_Sio_085C9EA8
_08039F74: .4byte 0x0203C618
_08039F78: .4byte gUnk_Sio_085C98F4
_08039F7C: .4byte 0x0203C984
_08039F80: .4byte 0x0203C6B4

	thumb_func_start sub_8039F84
sub_8039F84: @ 0x08039F84
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r0, #0x4c
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _08039FA2
	ldr r0, _0803A014 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt _08039FA2
	movs r0, #0x7c
	bl m4aSongNumStart
_08039FA2:
	adds r1, r5, #0
	adds r1, #0x4c
	ldrh r0, [r1]
	adds r0, #1
	movs r6, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x17
	ble _08039FB8
	strh r6, [r1]
_08039FB8:
	ldr r0, _0803A018 @ =0x0203C91C
	ldr r1, [r0]
	adds r1, #1
	str r1, [r0]
	movs r0, #0x96
	lsls r0, r0, #2
	cmp r1, r0
	ble _08039FCC
	bl sub_8073510
_08039FCC:
	ldr r0, _0803A01C @ =0x0300456C
	movs r1, #0x19
	strb r1, [r0]
	ldr r4, _0803A020 @ =gUnk_Sio_085C98F4
	ldr r1, [r4]
	ldrb r1, [r1, #6]
	strb r1, [r0, #1]
	strh r6, [r0, #2]
	movs r1, #4
	bl sub_8035DC8
	ldr r4, [r4]
	ldr r1, [r5, #0x58]
	movs r0, #0x8c
	muls r0, r1, r0
	adds r0, r4, r0
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r1, [r4, #9]
	ldrb r2, [r0]
	cmp r2, r1
	bne _0803A00E
	ldrb r0, [r4, #0xa]
	ands r0, r1
	cmp r0, r2
	bne _0803A00E
	ldr r0, _0803A024 @ =gUnk_Sio_085C99C8
	bl Proc_EndEach
	adds r0, r5, #0
	bl Proc_Break
_0803A00E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803A014: .4byte gPlaySt
_0803A018: .4byte 0x0203C91C
_0803A01C: .4byte 0x0300456C
_0803A020: .4byte gUnk_Sio_085C98F4
_0803A024: .4byte gUnk_Sio_085C99C8

	thumb_func_start sub_803A028
sub_803A028: @ 0x0803A028
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_8036B40
	bl sub_803FA14
	bl sub_8040F50
	movs r0, #3
	bl EndFaceById
	ldr r4, _0803A07C @ =0x0203C66C
	adds r0, r4, #0
	bl ClearText
	adds r0, r4, #0
	movs r1, #0
	bl Text_SetColor
	ldr r1, _0803A080 @ =gUnk_Sio_0810F0C0
	adds r0, r4, #0
	bl Text_DrawString
	ldr r1, _0803A084 @ =gBg2Tm+0x312
	adds r0, r4, #0
	bl PutText
	ldr r0, _0803A088 @ =gUnk_Sio_085C99C8
	adds r1, r5, #0
	bl SpawnProc
	movs r0, #0
	movs r1, #0
	bl sub_803FAA4
	movs r0, #0xf
	bl EnableBgSync
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803A07C: .4byte 0x0203C66C
_0803A080: .4byte gUnk_Sio_0810F0C0
_0803A084: .4byte gBg2Tm+0x312
_0803A088: .4byte gUnk_Sio_085C99C8

	thumb_func_start sub_803A08C
sub_803A08C: @ 0x0803A08C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	mov sb, r0
	bl sub_8036B40
	bl sub_803FA14
	ldr r4, _0803A1A8 @ =gUnk_08108514
	movs r0, #1
	bl GetBgChrOffset
	adds r1, r0, #0
	ldr r0, _0803A1AC @ =0x06000C00
	adds r1, r1, r0
	adds r0, r4, #0
	bl Decompress
	ldr r0, _0803A1B0 @ =gUnk_08109A80
	movs r1, #0xc0
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, _0803A1B4 @ =gUnk_08107820
	ldr r1, _0803A1B8 @ =0x06014800
	bl Decompress
	ldr r0, _0803A1BC @ =gUnk_08109A00
	movs r1, #0x98
	lsls r1, r1, #2
	movs r2, #0x80
	bl ApplyPaletteExt
	movs r0, #0
	bl sub_803FB08
	ldr r0, _0803A1C0 @ =0x0203C758
	bl SetTextFont
	bl ResetTextFont
	bl sub_8036C60
	add r0, sp, #8
	bl sub_803AE70
	movs r0, #1
	movs r1, #0xfe
	movs r2, #0
	bl SetBgOffset
	movs r5, #0
	movs r7, #0xc0
	lsls r7, r7, #1
	ldr r6, _0803A1C4 @ =gUnk_Sio_0810F298
_0803A0FE:
	lsls r4, r5, #3
	ldr r1, _0803A1C8 @ =0x0203C624
	mov r8, r1
	add r4, r8
	adds r0, r4, #0
	bl ClearText
	adds r0, r4, #0
	movs r1, #0
	bl Text_SetColor
	ldr r1, [r6]
	adds r0, r4, #0
	bl Text_DrawString
	ldr r1, _0803A1CC @ =gBg0Tm+0xC
	adds r1, r7, r1
	adds r0, r4, #0
	bl PutText
	mov r0, sp
	adds r0, r0, r5
	adds r0, #8
	ldrb r1, [r0]
	adds r0, r5, #0
	bl sub_803AED0
	adds r7, #0xc0
	adds r6, #0x14
	adds r5, #1
	cmp r5, #2
	ble _0803A0FE
	ldr r5, _0803A1C4 @ =gUnk_Sio_0810F298
	ldr r0, [r5, #0x18]
	lsls r0, r0, #1
	ldr r4, _0803A1D0 @ =gBg1Tm+0x23C
	adds r0, r0, r4
	movs r1, #0
	bl sub_803A680
	ldr r0, [r5, #0x1c]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #1
	bl sub_803A680
	ldr r0, _0803A1D4 @ =gUnk_Sio_0810F19C
	mov r4, r8
	subs r4, #0xc
	ldrb r2, [r4]
	adds r0, r2, r0
	ldrb r1, [r0]
	mov r0, sb
	bl sub_803FC3C
	ldr r0, _0803A1D8 @ =gUnk_Sio_085C9AD4
	ldrb r3, [r4]
	lsls r1, r3, #2
	adds r0, r1, r0
	ldr r0, [r0]
	ldr r2, _0803A1DC @ =gUnk_Sio_0810F190
	adds r1, r1, r2
	ldr r1, [r1]
	str r3, [sp]
	mov r2, sb
	str r2, [sp, #4]
	movs r2, #0
	movs r3, #8
	bl sub_803FD40
	ldr r0, _0803A1E0 @ =0x000006DA
	movs r1, #1
	bl sub_8036BFC
	movs r0, #0xf
	bl EnableBgSync
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803A1A8: .4byte gUnk_08108514
_0803A1AC: .4byte 0x06000C00
_0803A1B0: .4byte gUnk_08109A80
_0803A1B4: .4byte gUnk_08107820
_0803A1B8: .4byte 0x06014800
_0803A1BC: .4byte gUnk_08109A00
_0803A1C0: .4byte 0x0203C758
_0803A1C4: .4byte gUnk_Sio_0810F298
_0803A1C8: .4byte 0x0203C624
_0803A1CC: .4byte gBg0Tm+0xC
_0803A1D0: .4byte gBg1Tm+0x23C
_0803A1D4: .4byte gUnk_Sio_0810F19C
_0803A1D8: .4byte gUnk_Sio_085C9AD4
_0803A1DC: .4byte gUnk_Sio_0810F190
_0803A1E0: .4byte 0x000006DA

	thumb_func_start sub_803A1E4
sub_803A1E4: @ 0x0803A1E4
	push {lr}
	movs r0, #3
	bl sub_8036494
	pop {r0}
	bx r0

	thumb_func_start sub_803A1F0
sub_803A1F0: @ 0x0803A1F0
	push {lr}
	movs r0, #0
	bl sub_8036494
	pop {r0}
	bx r0

	thumb_func_start sub_803A1FC
sub_803A1FC: @ 0x0803A1FC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x4c
	adds r7, r0, #0
	movs r0, #0
	str r0, [sp, #0x3c]
	add r5, sp, #0x28
	ldr r1, _0803A2D8 @ =gUnk_Sio_0810F2D4
	adds r0, r5, #0
	movs r2, #6
	bl memcpy
	bl sub_8036B40
	bl sub_803FA14
	ldr r0, _0803A2DC @ =gUnk_08107820
	ldr r1, _0803A2E0 @ =0x06014800
	bl Decompress
	movs r0, #0
	movs r1, #4
	bl sub_803FAA4
	ldr r0, _0803A2E4 @ =0x0203C758
	bl SetTextFont
	bl InitSystemTextFont
	bl ResetTextFont
	movs r0, #0xc0
	movs r1, #0x10
	adds r2, r7, #0
	bl sub_803F9C4
	ldr r4, _0803A2E8 @ =0x0203C900
	adds r0, r4, #0
	movs r1, #0x18
	bl InitText
	adds r4, #8
	adds r0, r4, #0
	movs r1, #0x18
	bl InitText
	ldr r0, _0803A2EC @ =0x000006DB
	movs r1, #0
	bl sub_8036BFC
	ldr r0, _0803A2F0 @ =0x000006DC
	movs r1, #1
	bl sub_8036BFC
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r7, #0x4c]
	movs r1, #2
	mov r8, r1
	mov r2, sp
	adds r2, #0x30
	str r2, [sp, #0x40]
	adds r5, r7, #0
	adds r5, #0x40
	movs r0, #8
	mov sl, r0
	add r1, sp, #0x38
	mov sb, r1
_0803A28A:
	movs r0, #0
	mov r2, sb
	str r0, [r2]
	mov r0, r8
	bl sub_808525C
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803A322
	mov r0, r8
	add r1, sp, #8
	bl sub_8085270
	add r0, sp, #8
	bl sub_8070E0C
	adds r2, r7, #0
	adds r2, #0x2c
	mov r1, sl
	adds r4, r2, r1
	str r0, [r4]
	add r1, sp, #8
	movs r0, #0x40
	ldrb r1, [r1, #0x14]
	ands r0, r1
	str r2, [sp, #0x44]
	cmp r0, #0
	beq _0803A2C8
	movs r0, #2
	mov r2, sb
	str r0, [r2]
_0803A2C8:
	mov r0, r8
	bl sub_8085290
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803A2F4
	ldr r0, [r4]
	b _0803A2F8
	.align 2, 0
_0803A2D8: .4byte gUnk_Sio_0810F2D4
_0803A2DC: .4byte gUnk_08107820
_0803A2E0: .4byte 0x06014800
_0803A2E4: .4byte 0x0203C758
_0803A2E8: .4byte 0x0203C900
_0803A2EC: .4byte 0x000006DB
_0803A2F0: .4byte 0x000006DC
_0803A2F4:
	movs r0, #1
	rsbs r0, r0, #0
_0803A2F8:
	str r0, [r5]
	adds r6, r7, #0
	adds r6, #0x38
	mov r1, sl
	adds r0, r6, r1
	ldr r0, [r0]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, r2
	beq _0803A338
	ldr r0, [sp, #0x3c]
	cmp r0, #0
	bne _0803A31C
	mov r1, r8
	str r1, [r7, #0x50]
	movs r2, #1
	str r2, [sp, #0x3c]
	b _0803A338
_0803A31C:
	mov r0, r8
	str r0, [r7, #0x4c]
	b _0803A338
_0803A322:
	adds r1, r7, #0
	adds r1, #0x2c
	mov r2, sl
	adds r0, r1, r2
	movs r2, #1
	rsbs r2, r2, #0
	str r2, [r5]
	str r2, [r0]
	str r1, [sp, #0x44]
	adds r6, r7, #0
	adds r6, #0x38
_0803A338:
	subs r5, #4
	movs r0, #4
	rsbs r0, r0, #0
	add sl, r0
	add sb, r0
	movs r1, #1
	rsbs r1, r1, #0
	add r8, r1
	mov r2, r8
	cmp r2, #0
	bge _0803A28A
	ldr r1, [r7, #0x4c]
	adds r0, #3
	cmp r1, r0
	bne _0803A35E
	ldr r0, [r7, #0x50]
	str r0, [r7, #0x4c]
	str r0, [r7, #0x48]
	b _0803A360
_0803A35E:
	str r1, [r7, #0x48]
_0803A360:
	movs r0, #1
	movs r1, #4
	bl sub_8070CB4
	movs r0, #3
	movs r1, #5
	bl sub_8070CB4
	movs r0, #5
	movs r1, #6
	bl sub_8070CB4
	movs r0, #0
	movs r1, #7
	bl sub_8070CB4
	movs r0, #2
	movs r1, #8
	bl sub_8070CB4
	movs r0, #4
	movs r1, #9
	bl sub_8070CB4
	movs r0, #0xd0
	lsls r0, r0, #1
	bl sub_8070D48
	movs r0, #0xa0
	lsls r0, r0, #1
	mov sl, r0
	ldr r1, [sp, #0x44]
	str r1, [sp, #0x48]
	movs r2, #0x88
	lsls r2, r2, #7
	mov sb, r2
	movs r5, #0x80
	lsls r5, r5, #1
	ldr r4, [sp, #0x40]
	movs r0, #2
	mov r8, r0
_0803A3B2:
	ldr r1, [r6]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _0803A3C0
	movs r0, #1
	b _0803A3C8
_0803A3C0:
	ldr r0, [r4]
	cmp r0, #2
	beq _0803A3CA
	movs r0, #0
_0803A3C8:
	str r0, [r4]
_0803A3CA:
	ldr r0, _0803A458 @ =gBg1Tm+0x6
	adds r0, r5, r0
	ldr r1, [r4]
	adds r1, #4
	bl sub_8070DC8
	mov r1, sb
	lsls r0, r1, #0xf
	lsrs r0, r0, #0x14
	ldr r2, [sp, #0x48]
	ldm r2!, {r1}
	str r2, [sp, #0x48]
	bl sub_8070D08
	ldr r0, _0803A45C @ =gBg0Tm+0x6
	add r0, sl
	ldm r4!, {r1}
	adds r1, #7
	bl sub_8070DA8
	movs r0, #0x80
	lsls r0, r0, #1
	add sl, r0
	movs r1, #0x80
	lsls r1, r1, #4
	add sb, r1
	adds r5, r5, r0
	adds r6, #4
	movs r2, #1
	rsbs r2, r2, #0
	add r8, r2
	mov r0, r8
	cmp r0, #0
	bge _0803A3B2
	ldr r2, _0803A460 @ =gDispIo
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
	adds r0, r7, #0
	movs r1, #1
	bl sub_803FC3C
	ldr r0, _0803A464 @ =0x0203C618
	ldrb r0, [r0]
	str r0, [sp]
	str r7, [sp, #4]
	add r0, sp, #0x28
	movs r1, #6
	movs r2, #0
	movs r3, #8
	bl sub_803FD40
	movs r0, #0xf
	bl EnableBgSync
	add sp, #0x4c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803A458: .4byte gBg1Tm+0x6
_0803A45C: .4byte gBg0Tm+0x6
_0803A460: .4byte gDispIo
_0803A464: .4byte 0x0203C618

	thumb_func_start sub_803A468
sub_803A468: @ 0x0803A468
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r3, #0
	ldr r0, [sp, #0x14]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov ip, r1
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r1, _0803A4F0 @ =gKeySt
	ldr r3, [r1]
	ldrh r2, [r3, #6]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _0803A4B6
	ldr r0, [r4]
	cmp r0, r6
	bgt _0803A498
	ldrh r3, [r3, #8]
	cmp r2, r3
	bne _0803A4B6
_0803A498:
	subs r2, r7, #1
	movs r3, #1
	rsbs r3, r3, #0
_0803A49E:
	ldr r0, [r4]
	subs r0, #1
	str r0, [r4]
	cmp r0, #0
	bge _0803A4AA
	str r2, [r4]
_0803A4AA:
	ldr r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r0, [r0]
	cmp r0, r3
	beq _0803A49E
_0803A4B6:
	ldr r1, [r1]
	ldrh r2, [r1, #6]
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _0803A4EA
	ldr r0, [r4]
	cmp r0, ip
	blt _0803A4CE
	ldrh r1, [r1, #8]
	cmp r2, r1
	bne _0803A4EA
_0803A4CE:
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
	adds r1, r7, #0
	bl __modsi3
	str r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r1, [r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0803A4CE
_0803A4EA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803A4F0: .4byte gKeySt

	thumb_func_start sub_803A4F4
sub_803A4F4: @ 0x0803A4F4
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r5, [r6, #0x48]
	adds r0, #0x48
	ldr r1, [r6, #0x50]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, [r6, #0x4c]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r3, r6, #0
	adds r3, #0x38
	movs r4, #3
	str r4, [sp]
	bl sub_803A468
	ldr r1, [r6, #0x48]
	lsls r1, r1, #5
	adds r1, #0x28
	movs r0, #0x18
	bl sub_80415CC
	ldr r0, [r6, #0x48]
	cmp r5, r0
	beq _0803A52E
	movs r0, #3
	bl sub_8036D08
_0803A52E:
	ldr r4, _0803A56C @ =gKeySt
	ldr r1, [r4]
	movs r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _0803A548
	movs r0, #2
	bl sub_8036D08
	adds r0, r6, #0
	bl Proc_Break
_0803A548:
	ldr r1, [r4]
	movs r0, #2
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _0803A562
	movs r0, #1
	bl sub_8036D08
	adds r0, r6, #0
	movs r1, #4
	bl Proc_Goto
_0803A562:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803A56C: .4byte gKeySt

	thumb_func_start sub_803A570
sub_803A570: @ 0x0803A570
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x48]
	bl sub_80851B4
	ldr r1, _0803A5A4 @ =gPlaySt
	movs r0, #0xdf
	ldrb r2, [r1, #0x14]
	ands r0, r2
	strb r0, [r1, #0x14]
	movs r0, #0xd
	rsbs r0, r0, #0
	ldrb r2, [r1, #0x1d]
	ands r0, r2
	strb r0, [r1, #0x1d]
	ldr r1, _0803A5A8 @ =0x0203C618
	ldr r0, [r4, #0x48]
	strb r0, [r1, #4]
	bl ApplyUnitSpritePalettes
	bl sub_803CE7C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803A5A4: .4byte gPlaySt
_0803A5A8: .4byte 0x0203C618

	thumb_func_start sub_803A5AC
sub_803A5AC: @ 0x0803A5AC
	push {lr}
	adds r1, r0, #0
	ldr r0, _0803A5C4 @ =0x0203C618
	ldrb r0, [r0, #3]
	cmp r0, #0xff
	bne _0803A5C0
	adds r0, r1, #0
	movs r1, #1
	bl Proc_Goto
_0803A5C0:
	pop {r0}
	bx r0
	.align 2, 0
_0803A5C4: .4byte 0x0203C618

	thumb_func_start sub_803A5C8
sub_803A5C8: @ 0x0803A5C8
	push {lr}
	adds r1, r0, #0
	ldr r0, _0803A5E0 @ =0x0203C618
	ldrb r0, [r0, #4]
	cmp r0, #0xff
	bne _0803A5DC
	adds r0, r1, #0
	movs r1, #2
	bl Proc_Goto
_0803A5DC:
	pop {r0}
	bx r0
	.align 2, 0
_0803A5E0: .4byte 0x0203C618

	thumb_func_start sub_803A5E4
sub_803A5E4: @ 0x0803A5E4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0803A600 @ =gUnk_08678E38
	bl Proc_Find
	cmp r0, #0
	bne _0803A5F8
	adds r0, r4, #0
	bl Proc_Break
_0803A5F8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803A600: .4byte gUnk_08678E38

	thumb_func_start sub_803A604
sub_803A604: @ 0x0803A604
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0803A63C @ =0x0203C918
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0803A634
	bl sub_8036B98
	bl sub_803FB74
	bl sub_803FC60
	bl sub_803FDD8
	bl sub_803F9F4
	bl sub_807B6BC
	adds r0, r4, #0
	movs r1, #5
	bl Proc_Goto
_0803A634:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803A63C: .4byte 0x0203C918

	thumb_func_start sub_803A640
sub_803A640: @ 0x0803A640
	adds r3, r0, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	ldr r2, _0803A67C @ =0x00004060
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r1, #2
	ble _0803A65C
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r2, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0803A65C:
	strh r2, [r3]
	adds r0, r2, #1
	strh r0, [r3, #2]
	adds r0, r2, #2
	strh r0, [r3, #4]
	adds r1, r3, #0
	adds r1, #0x40
	adds r0, #0x1e
	strh r0, [r1]
	adds r1, #2
	adds r0, #1
	strh r0, [r1]
	adds r1, #2
	adds r0, #1
	strh r0, [r1]
	bx lr
	.align 2, 0
_0803A67C: .4byte 0x00004060

	thumb_func_start sub_803A680
sub_803A680: @ 0x0803A680
	push {r4, lr}
	lsls r1, r1, #0x12
	movs r2, #0xa0
	lsls r2, r2, #0x10
	adds r1, r1, r2
	lsrs r1, r1, #0x10
	movs r3, #0xc0
	lsls r3, r3, #7
	adds r2, r1, r3
	strh r2, [r0]
	ldr r4, _0803A6B4 @ =0x00006001
	adds r2, r1, r4
	strh r2, [r0, #2]
	adds r3, r0, #0
	adds r3, #0x40
	adds r4, #1
	adds r2, r1, r4
	strh r2, [r3]
	adds r0, #0x42
	ldr r2, _0803A6B8 @ =0x00006003
	adds r1, r1, r2
	strh r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803A6B4: .4byte 0x00006001
_0803A6B8: .4byte 0x00006003

	thumb_func_start sub_803A6BC
sub_803A6BC: @ 0x0803A6BC
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	adds r5, r0, #0
	mov sb, r1
	adds r6, r2, #0
	adds r4, r3, #0
	ldr r0, [sp, #0x18]
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	adds r0, r5, #0
	movs r1, #8
	movs r2, #0
	mov r3, sb
	bl Text_InsertDrawString
	adds r0, r5, #0
	movs r1, #0x60
	movs r2, #2
	adds r3, r4, #0
	bl Text_InsertDrawNumberOrBlank
	ldr r3, _0803A73C @ =gUnk_Sio_0810EDA4
	adds r0, r5, #0
	movs r1, #0x68
	movs r2, #0
	bl Text_InsertDrawString
	adds r0, r5, #0
	movs r1, #0x86
	movs r2, #2
	adds r3, r6, #0
	bl Text_InsertDrawNumberOrBlank
	ldr r3, _0803A740 @ =gUnk_Sio_0810F2DC
	adds r0, r5, #0
	movs r1, #0x8e
	movs r2, #0
	bl Text_InsertDrawString
	adds r0, r5, #0
	movs r1, #0x9c
	movs r2, #2
	mov r3, r8
	bl Text_InsertDrawNumberOrBlank
	ldr r3, _0803A744 @ =gUnk_Sio_0810F2E0
	adds r0, r5, #0
	movs r1, #0xa4
	movs r2, #0
	bl Text_InsertDrawString
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803A73C: .4byte gUnk_Sio_0810EDA4
_0803A740: .4byte gUnk_Sio_0810F2DC
_0803A744: .4byte gUnk_Sio_0810F2E0

	thumb_func_start sub_803A748
sub_803A748: @ 0x0803A748
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r6, #0
	ldr r0, _0803A7DC @ =0x0203C83C
	ldr r1, _0803A7E0 @ =gBg1Tm+0x4
	mov sl, r1
	subs r7, r0, #4
	movs r1, #0x24
	add r1, sl
	mov sb, r1
	mov r8, r0
_0803A766:
	lsls r5, r6, #3
	ldr r0, _0803A7E4 @ =0x0203C708
	adds r5, r5, r0
	adds r0, r5, #0
	bl ClearText
	ldrb r0, [r7]
	lsls r2, r0, #0x1e
	lsrs r2, r2, #6
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r2, r2, r1
	lsrs r2, r2, #0x18
	ldr r3, [r7]
	lsls r3, r3, #0xb
	lsrs r3, r3, #0x10
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1e
	adds r0, #1
	str r0, [sp]
	adds r0, r5, #0
	mov r1, r8
	bl sub_803A6BC
	lsls r4, r6, #7
	mov r1, sl
	adds r0, r4, r1
	adds r1, r6, #0
	bl sub_803A640
	mov r0, sl
	adds r0, #6
	adds r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl PutText
	ldrb r0, [r7]
	lsls r1, r0, #0x1b
	lsrs r1, r1, #0x1f
	mov r0, sb
	bl sub_803A680
	adds r7, #0x14
	movs r1, #0x80
	add sb, r1
	movs r0, #0x14
	add r8, r0
	adds r6, #1
	cmp r6, #9
	ble _0803A766
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803A7DC: .4byte 0x0203C83C
_0803A7E0: .4byte gBg1Tm+0x4
_0803A7E4: .4byte 0x0203C708

	thumb_func_start sub_803A7E8
sub_803A7E8: @ 0x0803A7E8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r1, _0803A9A4 @ =gUnk_Sio_0810F2E3
	add r0, sp, #8
	movs r2, #8
	bl memcpy
	bl sub_8036B40
	bl sub_803FA14
	ldr r4, _0803A9A8 @ =gUnk_08108514
	movs r0, #1
	bl GetBgChrOffset
	adds r1, r0, #0
	ldr r0, _0803A9AC @ =0x06000C00
	adds r1, r1, r0
	adds r0, r4, #0
	bl Decompress
	ldr r0, _0803A9B0 @ =gUnk_08109AC0
	movs r1, #0x80
	movs r2, #0x40
	bl ApplyPaletteExt
	ldr r0, _0803A9B4 @ =gUnk_08109A80
	movs r1, #0xc0
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, _0803A9B8 @ =gUnk_08107820
	ldr r1, _0803A9BC @ =0x06014800
	bl Decompress
	ldr r0, _0803A9C0 @ =gUnk_08109A00
	movs r1, #0x98
	lsls r1, r1, #2
	movs r2, #0x80
	bl ApplyPaletteExt
	movs r0, #0
	movs r1, #2
	bl sub_803FAA4
	ldr r0, _0803A9C4 @ =gBg2Tm+0x102
	ldr r1, _0803A9C8 @ =gUnk_0810A318
	movs r2, #0x80
	lsls r2, r2, #5
	bl TmApplyTsa_t
	ldr r0, _0803A9CC @ =0x0203C758
	bl SetTextFont
	bl InitSystemTextFont
	bl ResetTextFont
	movs r1, #0
	movs r0, #0xc8
	strh r0, [r7, #0x36]
	adds r0, r7, #0
	adds r0, #0x39
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	subs r0, #4
	strb r1, [r0]
	ldrh r2, [r7, #0x36]
	movs r0, #1
	movs r1, #0
	bl SetBgOffset
	ldr r5, _0803A9D0 @ =0x0203C708
	movs r4, #9
_0803A880:
	adds r0, r5, #0
	movs r1, #0x18
	bl InitText
	adds r5, #8
	subs r4, #1
	cmp r4, #0
	bge _0803A880
	ldr r4, _0803A9D4 @ =0x0203C900
	adds r0, r4, #0
	movs r1, #0x18
	bl InitText
	adds r0, r4, #0
	adds r0, #8
	movs r1, #0x18
	bl InitText
	adds r0, r4, #0
	bl ClearText
	ldr r3, _0803A9D8 @ =gUnk_Sio_0810F2EC
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #0
	bl Text_InsertDrawString
	ldr r3, _0803A9DC @ =gUnk_Sio_0810F2F8
	adds r0, r4, #0
	movs r1, #0x5e
	movs r2, #0
	bl Text_InsertDrawString
	ldr r3, _0803A9E0 @ =gUnk_Sio_0810F300
	adds r0, r4, #0
	movs r1, #0x84
	movs r2, #0
	bl Text_InsertDrawString
	ldr r3, _0803A9E4 @ =gUnk_Sio_0810F308
	adds r0, r4, #0
	movs r1, #0x9c
	movs r2, #0
	bl Text_InsertDrawString
	ldr r1, _0803A9E8 @ =gBg0Tm+0x14A
	adds r0, r4, #0
	bl PutText
	ldr r0, _0803A9EC @ =0x000006D3
	movs r1, #1
	bl sub_8036BFC
	ldr r0, _0803A9F0 @ =0x0203C838
	bl sub_80864CC
	bl sub_803A748
	ldr r1, _0803A9F4 @ =gDispIo
	mov ip, r1
	movs r0, #0x20
	ldrb r2, [r1, #1]
	orrs r0, r2
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	mov r1, ip
	strb r0, [r1, #1]
	adds r1, #0x2d
	movs r0, #0
	strb r0, [r1]
	adds r1, #4
	movs r0, #0x38
	strb r0, [r1]
	subs r1, #5
	movs r0, #0xf0
	strb r0, [r1]
	adds r1, #4
	movs r0, #0x88
	strb r0, [r1]
	mov r5, ip
	adds r5, #0x34
	movs r1, #1
	ldrb r0, [r5]
	orrs r0, r1
	movs r2, #2
	orrs r0, r2
	movs r6, #4
	orrs r0, r6
	movs r4, #8
	orrs r0, r4
	movs r3, #0x10
	orrs r0, r3
	strb r0, [r5]
	mov r2, ip
	adds r2, #0x36
	ldrb r0, [r2]
	orrs r1, r0
	movs r0, #3
	rsbs r0, r0, #0
	ands r1, r0
	orrs r1, r6
	orrs r1, r4
	orrs r1, r3
	strb r1, [r2]
	ldrh r0, [r7, #0x36]
	adds r0, #0x38
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	str r7, [sp, #4]
	movs r0, #0xd8
	movs r1, #0x38
	movs r2, #0xa
	movs r3, #5
	bl sub_8040A80
	adds r0, r7, #0
	movs r1, #5
	bl sub_803FC3C
	ldr r0, _0803A9F8 @ =0x0203C618
	ldrb r0, [r0]
	str r0, [sp]
	str r7, [sp, #4]
	add r0, sp, #8
	movs r1, #8
	movs r2, #0
	movs r3, #8
	bl sub_803FD40
	movs r0, #0xc0
	movs r1, #0x10
	adds r2, r7, #0
	bl sub_803F9C4
	movs r0, #0xf
	bl EnableBgSync
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803A9A4: .4byte gUnk_Sio_0810F2E3
_0803A9A8: .4byte gUnk_08108514
_0803A9AC: .4byte 0x06000C00
_0803A9B0: .4byte gUnk_08109AC0
_0803A9B4: .4byte gUnk_08109A80
_0803A9B8: .4byte gUnk_08107820
_0803A9BC: .4byte 0x06014800
_0803A9C0: .4byte gUnk_08109A00
_0803A9C4: .4byte gBg2Tm+0x102
_0803A9C8: .4byte gUnk_0810A318
_0803A9CC: .4byte 0x0203C758
_0803A9D0: .4byte 0x0203C708
_0803A9D4: .4byte 0x0203C900
_0803A9D8: .4byte gUnk_Sio_0810F2EC
_0803A9DC: .4byte gUnk_Sio_0810F2F8
_0803A9E0: .4byte gUnk_Sio_0810F300
_0803A9E4: .4byte gUnk_Sio_0810F308
_0803A9E8: .4byte gBg0Tm+0x14A
_0803A9EC: .4byte 0x000006D3
_0803A9F0: .4byte 0x0203C838
_0803A9F4: .4byte gDispIo
_0803A9F8: .4byte 0x0203C618

	thumb_func_start sub_803A9FC
sub_803A9FC: @ 0x0803A9FC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0x38
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r0, #0
	ble _0803AA18
	ldrh r0, [r4, #0x36]
	subs r0, #4
	strh r0, [r4, #0x36]
	ldrb r0, [r6]
	subs r0, #1
	b _0803AA26
_0803AA18:
	cmp r0, #0
	bge _0803AA42
	ldrh r0, [r4, #0x36]
	adds r0, #4
	strh r0, [r4, #0x36]
	ldrb r0, [r6]
	adds r0, #1
_0803AA26:
	strb r0, [r6]
	ldrh r2, [r4, #0x36]
	movs r0, #1
	movs r1, #0
	bl SetBgOffset
	ldrh r1, [r4, #0x36]
	adds r1, #0x38
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r0, #0xa
	bl sub_8040AEC
	b _0803AAEE
_0803AA42:
	ldr r0, _0803AAF4 @ =gKeySt
	ldr r1, [r0]
	movs r0, #0x40
	ldrh r1, [r1, #6]
	ands r0, r1
	cmp r0, #0
	beq _0803AA88
	adds r5, r4, #0
	adds r5, #0x34
	ldrb r0, [r5]
	cmp r0, #0
	beq _0803AA88
	movs r0, #3
	bl sub_8036D08
	ldrh r0, [r4, #0x36]
	subs r0, #4
	strh r0, [r4, #0x36]
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	movs r0, #3
	strb r0, [r6]
	ldrh r2, [r4, #0x36]
	movs r0, #1
	movs r1, #0
	bl SetBgOffset
	ldrh r1, [r4, #0x36]
	adds r1, #0x38
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r0, #0xa
	bl sub_8040AEC
_0803AA88:
	ldr r0, _0803AAF4 @ =gKeySt
	ldr r1, [r0]
	movs r0, #0x80
	ldrh r1, [r1, #6]
	ands r0, r1
	cmp r0, #0
	beq _0803AAD4
	adds r5, r4, #0
	adds r5, #0x34
	ldrb r0, [r5]
	adds r0, #5
	cmp r0, #9
	bgt _0803AAD4
	movs r0, #3
	bl sub_8036D08
	ldrh r0, [r4, #0x36]
	adds r0, #4
	strh r0, [r4, #0x36]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	adds r1, r4, #0
	adds r1, #0x38
	movs r0, #0xfd
	strb r0, [r1]
	ldrh r2, [r4, #0x36]
	movs r0, #1
	movs r1, #0
	bl SetBgOffset
	ldrh r1, [r4, #0x36]
	adds r1, #0x38
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r0, #0xa
	bl sub_8040AEC
_0803AAD4:
	ldr r0, _0803AAF4 @ =gKeySt
	ldr r1, [r0]
	movs r0, #2
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _0803AAEE
	movs r0, #1
	bl sub_8036D08
	adds r0, r4, #0
	bl Proc_Break
_0803AAEE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803AAF4: .4byte gKeySt

	thumb_func_start sub_803AAF8
sub_803AAF8: @ 0x0803AAF8
	cmp r0, #6
	ble _0803AB00
	movs r0, #5
	b _0803AB0C
_0803AB00:
	subs r0, #2
	cmp r0, #0
	bge _0803AB08
	movs r0, #0
_0803AB08:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_0803AB0C:
	bx lr
	.align 2, 0

	thumb_func_start sub_803AB10
sub_803AB10: @ 0x0803AB10
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r1, _0803AD18 @ =gUnk_Sio_0810F30D
	add r0, sp, #8
	movs r2, #7
	bl memcpy
	bl sub_8036B40
	bl sub_803FA14
	ldr r4, _0803AD1C @ =gUnk_08108514
	movs r0, #1
	bl GetBgChrOffset
	adds r1, r0, #0
	ldr r0, _0803AD20 @ =0x06000C00
	adds r1, r1, r0
	adds r0, r4, #0
	bl Decompress
	ldr r0, _0803AD24 @ =gUnk_08109AC0
	movs r1, #0x80
	movs r2, #0x40
	bl ApplyPaletteExt
	ldr r0, _0803AD28 @ =gUnk_08109A80
	movs r1, #0xc0
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, _0803AD2C @ =gUnk_08107820
	ldr r1, _0803AD30 @ =0x06014800
	bl Decompress
	ldr r0, _0803AD34 @ =gUnk_08109648
	ldr r1, _0803AD38 @ =0x06016000
	bl Decompress
	ldr r0, _0803AD3C @ =gUnk_08109BE0
	movs r1, #0x98
	lsls r1, r1, #2
	movs r2, #0x20
	bl ApplyPaletteExt
	movs r0, #0
	movs r1, #0
	bl sub_803FAA4
	ldr r0, _0803AD40 @ =gBg2Tm+0x102
	ldr r1, _0803AD44 @ =gUnk_0810A318
	movs r2, #0x80
	lsls r2, r2, #5
	bl TmApplyTsa_t
	ldr r0, _0803AD48 @ =0x0203C758
	bl SetTextFont
	bl InitSystemTextFont
	bl ResetTextFont
	adds r1, r7, #0
	adds r1, #0x34
	movs r4, #0
	movs r0, #5
	strb r0, [r1]
	movs r1, #0
	movs r0, #0x8c
	lsls r0, r0, #1
	strh r0, [r7, #0x36]
	adds r0, r7, #0
	adds r0, #0x39
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	ldr r0, [r7, #0x3c]
	bl sub_803AAF8
	adds r1, r7, #0
	adds r1, #0x35
	strb r0, [r1]
	str r4, [r7, #0x40]
	ldrh r2, [r7, #0x36]
	movs r0, #1
	movs r1, #0
	bl SetBgOffset
	ldr r5, _0803AD4C @ =0x0203C708
	movs r4, #9
_0803ABCE:
	adds r0, r5, #0
	movs r1, #0x18
	bl InitText
	adds r5, #8
	subs r4, #1
	cmp r4, #0
	bge _0803ABCE
	ldr r4, _0803AD50 @ =0x0203C900
	adds r0, r4, #0
	movs r1, #0x18
	bl InitText
	adds r0, r4, #0
	adds r0, #8
	movs r1, #0x18
	bl InitText
	adds r0, r4, #0
	bl ClearText
	ldr r3, _0803AD54 @ =gUnk_Sio_0810F2EC
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #0
	bl Text_InsertDrawString
	ldr r3, _0803AD58 @ =gUnk_Sio_0810F2F8
	adds r0, r4, #0
	movs r1, #0x5e
	movs r2, #0
	bl Text_InsertDrawString
	ldr r3, _0803AD5C @ =gUnk_Sio_0810F300
	adds r0, r4, #0
	movs r1, #0x84
	movs r2, #0
	bl Text_InsertDrawString
	ldr r3, _0803AD60 @ =gUnk_Sio_0810F308
	adds r0, r4, #0
	movs r1, #0x9c
	movs r2, #0
	bl Text_InsertDrawString
	ldr r1, _0803AD64 @ =gBg0Tm+0x14A
	adds r0, r4, #0
	bl PutText
	ldr r0, _0803AD68 @ =0x0203C838
	bl sub_80864CC
	bl sub_803A748
	ldr r1, _0803AD6C @ =gDispIo
	mov ip, r1
	movs r0, #0x20
	ldrb r2, [r1, #1]
	orrs r0, r2
	movs r1, #0x40
	orrs r0, r1
	movs r1, #0x7f
	ands r0, r1
	mov r1, ip
	strb r0, [r1, #1]
	mov r0, ip
	adds r0, #0x2d
	movs r2, #0
	mov r8, r2
	mov r1, r8
	strb r1, [r0]
	adds r0, #4
	movs r2, #0x38
	mov sl, r2
	mov r1, sl
	strb r1, [r0]
	subs r0, #5
	movs r6, #0xf0
	strb r6, [r0]
	mov r1, ip
	adds r1, #0x30
	movs r0, #0x88
	strb r0, [r1]
	mov r3, ip
	adds r3, #0x34
	movs r2, #1
	ldrb r0, [r3]
	orrs r0, r2
	movs r1, #2
	orrs r0, r1
	movs r5, #4
	orrs r0, r5
	movs r4, #8
	orrs r0, r4
	movs r1, #0x10
	mov sb, r1
	mov r1, sb
	orrs r0, r1
	strb r0, [r3]
	mov r0, ip
	adds r0, #0x2f
	mov r1, r8
	strb r1, [r0]
	mov r1, ip
	adds r1, #0x33
	movs r0, #0x18
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x2e
	strb r6, [r0]
	adds r0, #4
	mov r1, sl
	strb r1, [r0]
	mov r6, ip
	adds r6, #0x35
	ldrb r0, [r6]
	orrs r0, r2
	movs r3, #3
	rsbs r3, r3, #0
	ands r0, r3
	orrs r0, r5
	orrs r0, r4
	movs r1, #0x11
	rsbs r1, r1, #0
	ands r0, r1
	strb r0, [r6]
	mov r0, ip
	adds r0, #0x36
	ldrb r1, [r0]
	orrs r2, r1
	ands r2, r3
	orrs r2, r5
	orrs r2, r4
	mov r1, sb
	orrs r2, r1
	strb r2, [r0]
	ldr r0, _0803AD70 @ =0x0203C618
	ldrb r0, [r0]
	str r0, [sp]
	str r7, [sp, #4]
	add r0, sp, #8
	movs r1, #7
	movs r2, #0
	movs r3, #8
	bl sub_803FD40
	ldr r1, [r7, #0x3c]
	lsls r1, r1, #4
	subs r1, #0x18
	movs r0, #0xe
	adds r2, r7, #0
	bl sub_804108C
	str r0, [r7, #0x2c]
	movs r0, #0xf
	bl EnableBgSync
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803AD18: .4byte gUnk_Sio_0810F30D
_0803AD1C: .4byte gUnk_08108514
_0803AD20: .4byte 0x06000C00
_0803AD24: .4byte gUnk_08109AC0
_0803AD28: .4byte gUnk_08109A80
_0803AD2C: .4byte gUnk_08107820
_0803AD30: .4byte 0x06014800
_0803AD34: .4byte gUnk_08109648
_0803AD38: .4byte 0x06016000
_0803AD3C: .4byte gUnk_08109BE0
_0803AD40: .4byte gBg2Tm+0x102
_0803AD44: .4byte gUnk_0810A318
_0803AD48: .4byte 0x0203C758
_0803AD4C: .4byte 0x0203C708
_0803AD50: .4byte 0x0203C900
_0803AD54: .4byte gUnk_Sio_0810F2EC
_0803AD58: .4byte gUnk_Sio_0810F2F8
_0803AD5C: .4byte gUnk_Sio_0810F300
_0803AD60: .4byte gUnk_Sio_0810F308
_0803AD64: .4byte gBg0Tm+0x14A
_0803AD68: .4byte 0x0203C838
_0803AD6C: .4byte gDispIo
_0803AD70: .4byte 0x0203C618

	thumb_func_start sub_803AD74
sub_803AD74: @ 0x0803AD74
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r0, [r4, #0x2c]
	mov r8, r0
	ldr r0, [r4, #0x40]
	adds r0, #1
	str r0, [r4, #0x40]
	cmp r0, #0x3b
	ble _0803AE26
	adds r7, r4, #0
	adds r7, #0x35
	ldrb r1, [r7]
	cmp r1, #5
	bne _0803AD9A
	adds r0, r4, #0
	bl Proc_Break
_0803AD9A:
	adds r5, r4, #0
	adds r5, #0x38
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	ble _0803ADD4
	ldrh r0, [r4, #0x36]
	subs r0, #2
	strh r0, [r4, #0x36]
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	ldrh r2, [r4, #0x36]
	movs r0, #1
	movs r1, #0
	bl SetBgOffset
	ldrh r1, [r4, #0x36]
	adds r1, #0x38
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r0, #0xa
	bl sub_8040AEC
	mov r1, r8
	ldr r0, [r1, #0x30]
	adds r0, #2
	str r0, [r1, #0x30]
	b _0803AE26
_0803ADD4:
	adds r6, r4, #0
	adds r6, #0x34
	ldrb r0, [r7]
	ldrb r1, [r6]
	cmp r0, r1
	beq _0803AE10
	ldrh r0, [r4, #0x36]
	subs r0, #2
	strh r0, [r4, #0x36]
	ldrb r0, [r6]
	subs r0, #1
	strb r0, [r6]
	movs r0, #7
	strb r0, [r5]
	ldrh r2, [r4, #0x36]
	movs r0, #1
	movs r1, #0
	bl SetBgOffset
	ldrh r1, [r4, #0x36]
	adds r1, #0x38
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r0, #0xa
	bl sub_8040AEC
	mov r1, r8
	ldr r0, [r1, #0x30]
	adds r0, #2
	str r0, [r1, #0x30]
_0803AE10:
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	bne _0803AE26
	ldrb r6, [r6]
	ldrb r7, [r7]
	cmp r6, r7
	bne _0803AE26
	adds r0, r4, #0
	bl Proc_Break
_0803AE26:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_803AE30
sub_803AE30: @ 0x0803AE30
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0803AE54 @ =gKeySt
	ldr r1, [r0]
	movs r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _0803AE4E
	movs r0, #0
	bl FadeBgmOut
	adds r0, r4, #0
	bl Proc_Break
_0803AE4E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803AE54: .4byte gKeySt

	thumb_func_start sub_803AE58
sub_803AE58: @ 0x0803AE58
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0803AE6C @ =gUnk_Sio_085CA364
	bl SpawnProcLocking
	str r4, [r0, #0x3c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803AE6C: .4byte gUnk_Sio_085CA364

	thumb_func_start sub_803AE70
sub_803AE70: @ 0x0803AE70
	ldr r1, _0803AE8C @ =0x0203C618
	adds r1, #0xec
	ldrb r2, [r1]
	lsls r1, r2, #0x1f
	lsrs r1, r1, #0x1f
	strb r1, [r0]
	lsls r1, r2, #0x1e
	lsrs r1, r1, #0x1f
	strb r1, [r0, #1]
	lsls r2, r2, #0x1d
	lsrs r2, r2, #0x1f
	strb r2, [r0, #2]
	bx lr
	.align 2, 0
_0803AE8C: .4byte 0x0203C618

	thumb_func_start sub_803AE90
sub_803AE90: @ 0x0803AE90
	push {r4, r5, lr}
	ldr r5, _0803AECC @ =0x0203C618
	adds r5, #0xec
	movs r4, #1
	ldrb r2, [r0]
	ands r2, r4
	movs r1, #2
	rsbs r1, r1, #0
	ldrb r3, [r5]
	ands r1, r3
	orrs r1, r2
	ldrb r2, [r0, #1]
	ands r2, r4
	lsls r2, r2, #1
	movs r3, #3
	rsbs r3, r3, #0
	ands r1, r3
	orrs r1, r2
	ldrb r0, [r0, #2]
	ands r4, r0
	lsls r4, r4, #2
	movs r0, #5
	rsbs r0, r0, #0
	ands r1, r0
	orrs r1, r4
	strb r1, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803AECC: .4byte 0x0203C618

	thumb_func_start sub_803AED0
sub_803AED0: @ 0x0803AED0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r1, [sp, #8]
	ldr r1, _0803AF6C @ =gUnk_Sio_0810F314
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [sp]
	str r2, [sp, #4]
	movs r7, #0
	lsls r1, r0, #1
	ldr r2, _0803AF70 @ =gUnk_Sio_0810F298
	mov r8, r2
	adds r1, r1, r0
	adds r1, #6
	lsls r1, r1, #5
	mov sl, r1
	adds r2, #4
	lsls r6, r0, #4
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r2, r2, r1
	mov sb, r2
	adds r5, r1, #0
_0803AF08:
	ldr r4, _0803AF74 @ =0x0203C67C
	adds r4, r6, r4
	adds r0, r4, #0
	bl ClearText
	ldr r1, [sp, #8]
	adds r0, r1, r7
	movs r1, #1
	ands r0, r1
	lsls r0, r0, #2
	add r0, sp
	ldr r1, [r0]
	adds r0, r4, #0
	bl Text_SetColor
	mov r0, r8
	adds r0, #0xc
	adds r0, r5, r0
	ldr r1, [r0]
	adds r0, r4, #0
	bl Text_DrawString
	mov r2, sb
	adds r2, #4
	mov sb, r2
	subs r2, #4
	ldm r2!, {r1}
	add r1, sl
	lsls r1, r1, #1
	ldr r0, _0803AF78 @ =gBg0Tm
	adds r1, r1, r0
	adds r0, r4, #0
	bl PutText
	adds r6, #8
	adds r5, #4
	adds r7, #1
	cmp r7, #1
	ble _0803AF08
	movs r0, #1
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
_0803AF6C: .4byte gUnk_Sio_0810F314
_0803AF70: .4byte gUnk_Sio_0810F298
_0803AF74: .4byte 0x0203C67C
_0803AF78: .4byte gBg0Tm

	thumb_func_start sub_803AF7C
sub_803AF7C: @ 0x0803AF7C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov r8, r0
	add r6, sp, #0xc
	ldr r1, _0803B0E8 @ =gUnk_Sio_0810F31C
	adds r0, r6, #0
	movs r2, #9
	bl memcpy
	bl sub_8036B40
	bl sub_803FA14
	ldr r4, _0803B0EC @ =gUnk_08108514
	movs r0, #1
	bl GetBgChrOffset
	adds r1, r0, #0
	ldr r0, _0803B0F0 @ =0x06000C00
	adds r1, r1, r0
	adds r0, r4, #0
	bl Decompress
	ldr r0, _0803B0F4 @ =gUnk_08109A80
	movs r1, #0xc0
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, _0803B0F8 @ =gUnk_08107820
	ldr r1, _0803B0FC @ =0x06014800
	bl Decompress
	ldr r0, _0803B100 @ =gUnk_08109A00
	movs r1, #0x98
	lsls r1, r1, #2
	movs r2, #0x80
	bl ApplyPaletteExt
	movs r0, #0
	bl sub_803FB08
	ldr r0, _0803B104 @ =0x0203C758
	bl SetTextFont
	bl ResetTextFont
	bl sub_8036C60
	movs r0, #0
	mov r1, r8
	str r0, [r1, #0x30]
	mov r0, r8
	bl sub_8040744
	mov r2, r8
	str r0, [r2, #0x2c]
	movs r0, #1
	movs r1, #0xfe
	movs r2, #0
	bl SetBgOffset
	add r0, sp, #8
	bl sub_803AE70
	mov r3, r8
	ldr r0, [r3, #0x2c]
	ldr r4, [r3, #0x30]
	movs r2, #0x30
	ldrsh r1, [r3, r2]
	ldr r5, _0803B108 @ =gUnk_Sio_0810F298
	mov r3, sp
	adds r3, r3, r4
	adds r3, #8
	lsls r2, r4, #2
	adds r2, r2, r4
	ldrb r3, [r3]
	adds r2, r3, r2
	lsls r2, r2, #2
	adds r3, r5, #4
	adds r2, r2, r3
	ldr r2, [r2]
	lsls r2, r2, #0x13
	asrs r2, r2, #0x10
	lsls r3, r4, #1
	adds r3, r3, r4
	lsls r3, r3, #0x13
	movs r4, #0xc0
	lsls r4, r4, #0xe
	adds r3, r3, r4
	asrs r3, r3, #0x10
	bl sub_8040768
	movs r7, #0
	mov sl, r6
	movs r6, #0xc0
	lsls r6, r6, #1
_0803B044:
	lsls r4, r7, #3
	ldr r0, _0803B10C @ =0x0203C624
	mov sb, r0
	add r4, sb
	adds r0, r4, #0
	bl ClearText
	adds r0, r4, #0
	movs r1, #0
	bl Text_SetColor
	ldr r1, [r5]
	adds r0, r4, #0
	bl Text_DrawString
	ldr r1, _0803B110 @ =gBg0Tm+0xC
	adds r1, r6, r1
	adds r0, r4, #0
	bl PutText
	mov r0, sp
	adds r0, r0, r7
	adds r0, #8
	ldrb r1, [r0]
	adds r0, r7, #0
	bl sub_803AED0
	adds r6, #0xc0
	adds r5, #0x14
	adds r7, #1
	cmp r7, #2
	ble _0803B044
	ldr r5, _0803B108 @ =gUnk_Sio_0810F298
	ldr r0, [r5, #0x18]
	lsls r0, r0, #1
	ldr r4, _0803B114 @ =gBg1Tm+0x23C
	adds r0, r0, r4
	movs r1, #0
	bl sub_803A680
	ldr r0, [r5, #0x1c]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #1
	bl sub_803A680
	mov r1, r8
	ldr r0, [r1, #0x2c]
	movs r1, #6
	bl sub_803FC3C
	mov r0, sb
	subs r0, #0xc
	ldrb r0, [r0]
	str r0, [sp]
	mov r2, r8
	ldr r0, [r2, #0x2c]
	str r0, [sp, #4]
	mov r0, sl
	movs r1, #9
	movs r2, #0
	movs r3, #8
	bl sub_803FD40
	mov r3, r8
	ldr r0, [r3, #0x30]
	ldr r4, _0803B118 @ =0x000006D4
	adds r0, r0, r4
	movs r1, #1
	bl sub_8036BFC
	movs r0, #0xf
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
_0803B0E8: .4byte gUnk_Sio_0810F31C
_0803B0EC: .4byte gUnk_08108514
_0803B0F0: .4byte 0x06000C00
_0803B0F4: .4byte gUnk_08109A80
_0803B0F8: .4byte gUnk_08107820
_0803B0FC: .4byte 0x06014800
_0803B100: .4byte gUnk_08109A00
_0803B104: .4byte 0x0203C758
_0803B108: .4byte gUnk_Sio_0810F298
_0803B10C: .4byte 0x0203C624
_0803B110: .4byte gBg0Tm+0xC
_0803B114: .4byte gBg1Tm+0x23C
_0803B118: .4byte 0x000006D4

	thumb_func_start sub_803B11C
sub_803B11C: @ 0x0803B11C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r4, #0
	movs r7, #0
	ldr r5, _0803B238 @ =gKeySt
	ldr r1, [r5]
	movs r0, #2
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _0803B146
	movs r0, #1
	bl sub_8036D08
	ldr r0, _0803B23C @ =0x0203C704
	bl sub_80864F4
	adds r0, r6, #0
	bl Proc_Break
_0803B146:
	mov r0, sp
	bl sub_803AE70
	ldr r1, [r5]
	movs r0, #0x40
	ldrh r1, [r1, #6]
	ands r0, r1
	cmp r0, #0
	beq _0803B164
	ldr r0, [r6, #0x30]
	cmp r0, #0
	beq _0803B164
	subs r0, #1
	str r0, [r6, #0x30]
	movs r4, #1
_0803B164:
	ldr r2, _0803B238 @ =gKeySt
	ldr r1, [r2]
	movs r0, #0x80
	ldrh r1, [r1, #6]
	ands r0, r1
	adds r5, r2, #0
	cmp r0, #0
	beq _0803B184
	ldr r0, [r6, #0x30]
	cmp r0, #1
	bgt _0803B184
	adds r0, #1
	str r0, [r6, #0x30]
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_0803B184:
	ldr r1, [r5]
	movs r0, #0x20
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _0803B1AC
	ldr r0, [r6, #0x30]
	mov r1, sp
	adds r3, r1, r0
	ldrb r1, [r3]
	subs r1, #1
	movs r2, #1
	ands r1, r2
	strb r1, [r3]
	ldrb r1, [r3]
	bl sub_803AED0
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_0803B1AC:
	ldr r1, [r5]
	movs r0, #0x10
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _0803B1D4
	ldr r0, [r6, #0x30]
	mov r2, sp
	adds r3, r2, r0
	ldrb r1, [r3]
	adds r1, #1
	movs r2, #1
	ands r1, r2
	strb r1, [r3]
	ldrb r1, [r3]
	bl sub_803AED0
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_0803B1D4:
	mov r0, sp
	bl sub_803AE90
	cmp r4, #0
	beq _0803B22E
	movs r0, #3
	bl sub_8036D08
	ldr r5, [r6, #0x30]
	cmp r5, #1
	bne _0803B1EE
	movs r7, #2
	rsbs r7, r7, #0
_0803B1EE:
	ldr r0, [r6, #0x2c]
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	ldr r3, _0803B240 @ =gUnk_Sio_0810F298
	mov r2, sp
	adds r4, r2, r5
	lsls r2, r5, #2
	adds r2, r2, r5
	ldrb r4, [r4]
	adds r2, r4, r2
	lsls r2, r2, #2
	adds r3, #4
	adds r2, r2, r3
	ldr r2, [r2]
	adds r2, r2, r7
	lsls r2, r2, #0x13
	asrs r2, r2, #0x10
	lsls r3, r5, #1
	adds r3, r3, r5
	lsls r3, r3, #0x13
	movs r4, #0xc0
	lsls r4, r4, #0xe
	adds r3, r3, r4
	asrs r3, r3, #0x10
	bl sub_8040768
	ldr r0, [r6, #0x30]
	ldr r1, _0803B244 @ =0x000006D4
	adds r0, r0, r1
	movs r1, #1
	bl sub_8036BFC
_0803B22E:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803B238: .4byte gKeySt
_0803B23C: .4byte 0x0203C704
_0803B240: .4byte gUnk_Sio_0810F298
_0803B244: .4byte 0x000006D4

	thumb_func_start sub_803B248
sub_803B248: @ 0x0803B248
	push {r4, r5, r6, lr}
	sub sp, #0x28
	adds r2, r0, #0
	adds r3, r1, #0
	mov r0, sp
	ldr r1, _0803B27C @ =gUnk_Sio_0810F328
	ldm r1!, {r4, r5, r6}
	stm r0!, {r4, r5, r6}
	ldm r1!, {r4, r5, r6}
	stm r0!, {r4, r5, r6}
	ldm r1!, {r4, r5, r6}
	stm r0!, {r4, r5, r6}
	ldr r1, [r1]
	str r1, [r0]
	cmp r3, #0
	bne _0803B284
	adds r0, r2, #0
	adds r0, #0x58
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0803B298
	ldr r0, _0803B280 @ =0x000006C4
	b _0803B2A4
	.align 2, 0
_0803B27C: .4byte gUnk_Sio_0810F328
_0803B280: .4byte 0x000006C4
_0803B284:
	adds r0, r2, #0
	adds r0, #0x58
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0803B298
	movs r0, #1
	rsbs r0, r0, #0
	b _0803B2A4
_0803B298:
	ldr r0, [r2, #0x48]
	lsls r0, r0, #1
	adds r0, r0, r3
	lsls r0, r0, #2
	add r0, sp
	ldr r0, [r0]
_0803B2A4:
	add sp, #0x28
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_803B2AC
sub_803B2AC: @ 0x0803B2AC
	push {r4, lr}
	movs r4, #0
_0803B2B0:
	adds r0, r4, #0
	bl sub_808525C
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803B2CC
	adds r0, r4, #0
	bl sub_8085290
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803B2CC
	movs r0, #1
	b _0803B2D4
_0803B2CC:
	adds r4, #1
	cmp r4, #2
	ble _0803B2B0
	movs r0, #0
_0803B2D4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_803B2DC
sub_803B2DC: @ 0x0803B2DC
	push {lr}
	bl sub_803B2AC
	ldr r1, _0803B308 @ =0x0203C618
	strb r0, [r1, #0xa]
	ldr r1, _0803B30C @ =0x0203C920
	movs r2, #0
	adds r0, r1, #0
	adds r0, #0x1e
_0803B2EE:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _0803B2EE
	movs r1, #0
	ldr r3, _0803B310 @ =0x030013E0
	ldr r2, _0803B314 @ =0x030013E4
	ldr r0, _0803B318 @ =0x0203C940
	str r1, [r0]
	str r1, [r2]
	str r1, [r3]
	pop {r0}
	bx r0
	.align 2, 0
_0803B308: .4byte 0x0203C618
_0803B30C: .4byte 0x0203C920
_0803B310: .4byte 0x030013E0
_0803B314: .4byte 0x030013E4
_0803B318: .4byte 0x0203C940

	thumb_func_start sub_803B31C
sub_803B31C: @ 0x0803B31C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r1, _0803B3B0 @ =gUnk_Sio_0810F35A
	add r0, sp, #8
	movs r2, #5
	bl memcpy
	ldr r4, _0803B3B4 @ =0x0203C704
	adds r0, r4, #0
	bl sub_8086530
	ldrb r4, [r4]
	lsls r0, r4, #0x1c
	lsrs r0, r0, #0x1f
	adds r5, r6, #0
	adds r5, #0x59
	movs r4, #0
	strb r0, [r5]
	bl sub_803FA14
	ldr r0, _0803B3B8 @ =gUnk_08106CC8
	ldr r1, _0803B3BC @ =0x06014800
	bl Decompress
	ldr r0, _0803B3C0 @ =gUnk_081099A0
	movs r1, #0x98
	lsls r1, r1, #2
	movs r2, #0x60
	bl ApplyPaletteExt
	movs r0, #0
	movs r1, #4
	bl sub_803FAA4
	ldr r0, _0803B3C4 @ =0x0203C758
	bl SetTextFont
	bl InitSystemTextFont
	bl ResetTextFont
	bl sub_8036C60
	str r4, [r6, #0x4c]
	bl sub_8086558
	adds r2, r6, #0
	adds r2, #0x58
	strb r0, [r2]
	adds r1, r6, #0
	adds r1, #0x40
	movs r0, #1
	strb r0, [r1]
	movs r1, #0
	ldrsb r1, [r2, r1]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r1, r0, #0x1f
	adds r0, r6, #0
	adds r0, #0x41
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	bne _0803B3C8
	movs r1, #0
	movs r0, #3
	b _0803B3CC
	.align 2, 0
_0803B3B0: .4byte gUnk_Sio_0810F35A
_0803B3B4: .4byte 0x0203C704
_0803B3B8: .4byte gUnk_08106CC8
_0803B3BC: .4byte 0x06014800
_0803B3C0: .4byte gUnk_081099A0
_0803B3C4: .4byte 0x0203C758
_0803B3C8:
	movs r1, #1
	movs r0, #4
_0803B3CC:
	str r0, [r6, #0x50]
	adds r0, r6, #0
	adds r0, #0x44
	strb r1, [r0]
	ldr r0, _0803B454 @ =0x0203C618
	ldrb r0, [r0, #1]
	str r0, [r6, #0x48]
	adds r2, r6, #0
	adds r2, #0x40
	adds r0, r2, r0
	movs r1, #2
	strb r1, [r0]
	movs r4, #4
	adds r7, r2, #0
	adds r5, r6, #0
	adds r5, #0x3c
_0803B3EC:
	lsls r3, r4, #0x18
	lsrs r3, r3, #0x18
	adds r0, r7, r4
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #0xb0
	movs r2, #0xa0
	bl sub_8040014
	str r0, [r5]
	subs r5, #4
	subs r4, #1
	cmp r4, #0
	bge _0803B3EC
	ldr r0, [r6, #0x2c]
	movs r1, #0
	bl sub_803FC3C
	movs r4, #0
	str r4, [sp]
	ldr r0, [r6, #0x2c]
	str r0, [sp, #4]
	add r0, sp, #8
	movs r1, #5
	movs r2, #0
	movs r3, #0xa8
	bl sub_803FD40
	ldr r0, _0803B458 @ =gUnk_Sio_085CA404
	bl SetFaceConfig
	movs r0, #2
	str r0, [sp]
	movs r0, #3
	movs r1, #0xc0
	movs r2, #0xd0
	movs r3, #0x50
	bl StartFace
	str r4, [r6, #0x54]
	movs r0, #0x39
	movs r1, #0
	bl StartBgm
	bl sub_803CF9C
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803B454: .4byte 0x0203C618
_0803B458: .4byte gUnk_Sio_085CA404

	thumb_func_start sub_803B45C
sub_803B45C: @ 0x0803B45C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r1, #0x50
	rsbs r1, r1, #0
	ldr r5, _0803B504 @ =gUnk_Sio_0810F350
	ldrb r2, [r5]
	ldr r3, [r7, #0x54]
	movs r4, #0x20
	str r4, [sp]
	movs r0, #4
	bl Interpolate
	adds r6, r0, #0
	ldrb r2, [r5, #1]
	ldr r3, [r7, #0x54]
	str r4, [sp]
	movs r0, #5
	movs r1, #0xa0
	bl Interpolate
	mov sb, r0
	movs r5, #4
	lsls r6, r6, #0x10
	mov r8, r6
	lsls r6, r0, #0x10
	adds r4, r7, #0
	adds r4, #0x3c
_0803B49A:
	ldr r0, [r4]
	mov r2, r8
	asrs r1, r2, #0x10
	asrs r2, r6, #0x10
	bl sub_8040098
	subs r4, #4
	subs r5, #1
	cmp r5, #0
	bge _0803B49A
	mov r1, sb
	adds r1, #8
	movs r0, #0
	bl sub_803FE28
	ldr r0, [r7, #0x54]
	cmp r0, #0x1f
	ble _0803B4F0
	movs r0, #0
	str r0, [r7, #0x54]
	adds r0, r7, #0
	movs r1, #0
	bl sub_803B248
	movs r1, #0
	bl sub_8036BFC
	adds r0, r7, #0
	movs r1, #1
	bl sub_803B248
	movs r1, #1
	bl sub_8036BFC
	ldr r0, _0803B504 @ =gUnk_Sio_0810F350
	ldrb r1, [r0, #1]
	adds r1, #8
	movs r0, #0
	bl sub_803FE28
	adds r0, r7, #0
	bl Proc_Break
_0803B4F0:
	ldr r0, [r7, #0x54]
	adds r0, #1
	str r0, [r7, #0x54]
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803B504: .4byte gUnk_Sio_0810F350

	thumb_func_start sub_803B508
sub_803B508: @ 0x0803B508
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, [r5, #0x48]
	lsls r0, r0, #1
	movs r7, #4
	ldr r1, _0803B59C @ =gUnk_Sio_0810F350
	movs r2, #0x10
	mov r8, r2
	adds r6, r1, #0
	adds r6, #8
	adds r4, r0, r1
	mov sl, r4
	adds r0, #1
	adds r0, r0, r1
	mov sb, r0
_0803B530:
	ldrb r2, [r6]
	ldr r3, [r5, #0x54]
	mov r0, r8
	str r0, [sp]
	movs r0, #4
	mov r4, sl
	ldrb r1, [r4]
	bl Interpolate
	adds r4, r0, #0
	mov r0, sb
	ldrb r1, [r0]
	ldrb r2, [r6, #1]
	ldr r3, [r5, #0x54]
	mov r0, r8
	str r0, [sp]
	movs r0, #4
	bl Interpolate
	adds r2, r0, #0
	lsls r1, r7, #2
	adds r0, r5, #0
	adds r0, #0x2c
	adds r0, r0, r1
	ldr r0, [r0]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	adds r1, r4, #0
	bl sub_8040098
	subs r6, #2
	subs r7, #1
	cmp r7, #0
	bge _0803B530
	ldr r0, [r5, #0x54]
	cmp r0, #0xf
	ble _0803B584
	adds r0, r5, #0
	bl Proc_Break
_0803B584:
	ldr r0, [r5, #0x54]
	adds r0, #1
	str r0, [r5, #0x54]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803B59C: .4byte gUnk_Sio_0810F350

	thumb_func_start sub_803B5A0
sub_803B5A0: @ 0x0803B5A0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r1, _0803B63C @ =gUnk_Sio_0810F35A
	add r0, sp, #8
	movs r2, #5
	bl memcpy
	ldr r4, _0803B640 @ =0x0203C704
	adds r0, r4, #0
	bl sub_8086530
	ldrb r4, [r4]
	lsls r0, r4, #0x1c
	lsrs r0, r0, #0x1f
	adds r5, r6, #0
	adds r5, #0x59
	movs r4, #0
	strb r0, [r5]
	bl sub_803FA14
	ldr r0, _0803B644 @ =gUnk_08106CC8
	ldr r1, _0803B648 @ =0x06014800
	bl Decompress
	ldr r0, _0803B64C @ =gUnk_081099A0
	movs r1, #0x98
	lsls r1, r1, #2
	movs r2, #0x60
	bl ApplyPaletteExt
	movs r0, #0
	movs r1, #4
	bl sub_803FAA4
	ldr r0, _0803B650 @ =0x0203C758
	bl SetTextFont
	bl InitSystemTextFont
	bl ResetTextFont
	bl sub_8036C60
	str r4, [r6, #0x4c]
	bl sub_8086558
	adds r2, r6, #0
	adds r2, #0x58
	strb r0, [r2]
	adds r1, r6, #0
	adds r1, #0x40
	movs r0, #1
	strb r0, [r1]
	movs r1, #0
	ldrsb r1, [r2, r1]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r1, r0, #0x1f
	adds r0, r6, #0
	adds r0, #0x41
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	bne _0803B654
	movs r1, #0
	movs r0, #3
	b _0803B658
	.align 2, 0
_0803B63C: .4byte gUnk_Sio_0810F35A
_0803B640: .4byte 0x0203C704
_0803B644: .4byte gUnk_08106CC8
_0803B648: .4byte 0x06014800
_0803B64C: .4byte gUnk_081099A0
_0803B650: .4byte 0x0203C758
_0803B654:
	movs r1, #1
	movs r0, #4
_0803B658:
	str r0, [r6, #0x50]
	adds r0, r6, #0
	adds r0, #0x44
	strb r1, [r0]
	ldr r0, _0803B724 @ =0x0203C618
	ldrb r0, [r0, #1]
	str r0, [r6, #0x48]
	adds r2, r6, #0
	adds r2, #0x40
	adds r0, r2, r0
	movs r1, #2
	strb r1, [r0]
	ldr r1, [r6, #0x48]
	lsls r1, r1, #1
	movs r5, #4
	mov sb, r2
	ldr r2, _0803B728 @ =gUnk_Sio_0810F350
	adds r0, r1, #1
	adds r0, r0, r2
	mov r8, r0
	adds r4, r6, #0
	adds r4, #0x3c
	adds r1, r1, r2
	mov sl, r1
_0803B688:
	lsls r3, r5, #0x18
	lsrs r3, r3, #0x18
	mov r1, sb
	adds r0, r1, r5
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r6, #0
	mov r2, sl
	ldrb r1, [r2]
	mov r7, r8
	ldrb r2, [r7]
	bl sub_8040014
	str r0, [r4]
	subs r4, #4
	subs r5, #1
	cmp r5, #0
	bge _0803B688
	ldr r0, [r6, #0x2c]
	movs r1, #0
	bl sub_803FC3C
	ldr r1, _0803B728 @ =gUnk_Sio_0810F350
	ldr r0, [r6, #0x48]
	lsls r0, r0, #1
	adds r0, #1
	adds r0, r0, r1
	ldrb r3, [r0]
	adds r3, #8
	movs r4, #0
	str r4, [sp]
	ldr r0, [r6, #0x2c]
	str r0, [sp, #4]
	add r0, sp, #8
	movs r1, #5
	movs r2, #0
	bl sub_803FD40
	ldr r0, _0803B72C @ =gUnk_Sio_085CA424
	bl SetFaceConfig
	movs r0, #2
	str r0, [sp]
	movs r0, #3
	movs r1, #0xc0
	movs r2, #0xd0
	movs r3, #0x50
	bl StartFace
	adds r0, r6, #0
	movs r1, #0
	bl sub_803B248
	movs r1, #0
	bl sub_8036BFC
	adds r0, r6, #0
	movs r1, #1
	bl sub_803B248
	movs r1, #1
	bl sub_8036BFC
	bl sub_803CF9C
	movs r0, #0x39
	movs r1, #0
	bl StartBgm
	str r4, [r6, #0x54]
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803B724: .4byte 0x0203C618
_0803B728: .4byte gUnk_Sio_0810F350
_0803B72C: .4byte gUnk_Sio_085CA424

	thumb_func_start sub_803B730
sub_803B730: @ 0x0803B730
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	ldr r0, [r5, #0x48]
	cmp r0, #1
	bne _0803B7B0
	ldr r0, _0803B828 @ =gKeySt
	ldr r1, [r0]
	movs r0, #0x20
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _0803B77A
	ldr r1, _0803B82C @ =0x0203C618
	ldrb r0, [r1, #5]
	subs r0, #1
	strb r0, [r1, #5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0803B762
	movs r0, #2
	strb r0, [r1, #5]
_0803B762:
	ldr r0, [r5, #0x30]
	movs r1, #6
	rsbs r1, r1, #0
	movs r2, #4
	str r2, [sp]
	movs r2, #0x34
	movs r3, #0x1f
	bl sub_8040084
	movs r0, #3
	bl sub_8036D08
_0803B77A:
	ldr r0, _0803B828 @ =gKeySt
	ldr r1, [r0]
	movs r0, #0x10
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _0803B7B0
	ldr r4, _0803B82C @ =0x0203C618
	ldrb r0, [r4, #5]
	adds r0, #1
	strb r0, [r4, #5]
	ldrb r0, [r4, #5]
	movs r1, #3
	bl __umodsi3
	strb r0, [r4, #5]
	ldr r0, [r5, #0x30]
	movs r1, #0x1f
	str r1, [sp]
	movs r1, #0
	movs r2, #0x3a
	movs r3, #4
	bl sub_8040084
	movs r0, #3
	bl sub_8036D08
_0803B7B0:
	ldr r1, _0803B828 @ =gKeySt
	ldr r2, [r1]
	ldrh r3, [r2, #6]
	movs r0, #0x40
	ands r0, r3
	adds r4, r1, #0
	cmp r0, #0
	beq _0803B7EA
	ldr r1, [r5, #0x48]
	ldr r0, [r5, #0x4c]
	cmp r1, r0
	bgt _0803B7CE
	ldrh r2, [r2, #8]
	cmp r3, r2
	bne _0803B7EA
_0803B7CE:
	subs r2, r6, #1
	adds r1, r5, #0
	adds r1, #0x40
_0803B7D4:
	ldr r0, [r5, #0x48]
	subs r0, #1
	str r0, [r5, #0x48]
	cmp r0, #0
	bge _0803B7E0
	str r2, [r5, #0x48]
_0803B7E0:
	ldr r0, [r5, #0x48]
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803B7D4
_0803B7EA:
	ldr r2, [r4]
	ldrh r3, [r2, #6]
	movs r0, #0x80
	ands r0, r3
	cmp r0, #0
	beq _0803B81E
	ldr r1, [r5, #0x48]
	ldr r0, [r5, #0x50]
	cmp r1, r0
	blt _0803B804
	ldrh r2, [r2, #8]
	cmp r3, r2
	bne _0803B81E
_0803B804:
	adds r4, r5, #0
	adds r4, #0x40
_0803B808:
	ldr r0, [r5, #0x48]
	adds r0, #1
	str r0, [r5, #0x48]
	adds r1, r6, #0
	bl __modsi3
	str r0, [r5, #0x48]
	adds r0, r4, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803B808
_0803B81E:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803B828: .4byte gKeySt
_0803B82C: .4byte 0x0203C618

	thumb_func_start sub_803B830
sub_803B830: @ 0x0803B830
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x48]
	ldr r0, _0803B928 @ =gUnk_Sio_085C99F8
	bl sub_8036D60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803B860
	ldr r1, _0803B92C @ =0x0203C618
	ldr r0, [r4, #0x48]
	strb r0, [r1]
	strb r0, [r1, #1]
	movs r0, #3
	bl EndFaceById
	ldr r0, _0803B930 @ =gUnk_Sio_085CA638
	adds r1, r4, #0
	bl SpawnProcLocking
	adds r0, r4, #0
	movs r1, #1
	bl Proc_Goto
_0803B860:
	adds r0, r4, #0
	movs r1, #5
	bl sub_803B730
	ldr r0, [r4, #0x48]
	cmp r5, r0
	beq _0803B8DA
	movs r0, #3
	bl sub_8036D08
	lsls r0, r5, #2
	adds r1, r4, #0
	adds r1, #0x2c
	adds r0, r1, r0
	ldr r3, [r0]
	adds r2, r3, #0
	adds r2, #0x2e
	movs r0, #1
	strb r0, [r2]
	ldr r0, [r4, #0x48]
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r3, [r1]
	adds r1, r3, #0
	adds r1, #0x2e
	movs r0, #2
	strb r0, [r1]
	movs r0, #0x2a
	ldrsh r1, [r3, r0]
	movs r0, #0x2c
	ldrsh r2, [r3, r0]
	adds r0, r3, #0
	bl sub_804085C
	adds r0, r4, #0
	movs r1, #0
	bl sub_803B248
	movs r1, #0
	bl sub_8036BFC
	adds r0, r4, #0
	movs r1, #1
	bl sub_803B248
	movs r1, #1
	bl sub_8036BFC
	ldr r1, _0803B934 @ =gUnk_Sio_0810F350
	ldr r0, [r4, #0x48]
	lsls r0, r0, #1
	adds r0, #1
	adds r0, r0, r1
	ldrb r1, [r0]
	adds r1, #8
	movs r0, #0
	bl sub_803FE0C
	ldr r0, [r4, #0x48]
	bl sub_803FE48
_0803B8DA:
	ldr r5, _0803B938 @ =gKeySt
	ldr r1, [r5]
	movs r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _0803B8FE
	movs r0, #0
	str r0, [r4, #0x54]
	movs r0, #2
	bl sub_8036D08
	ldr r1, _0803B92C @ =0x0203C618
	ldr r0, [r4, #0x48]
	strb r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
_0803B8FE:
	ldr r1, [r5]
	movs r0, #2
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _0803B922
	movs r0, #1
	bl sub_8036D08
	movs r0, #2
	bl FadeBgmOut
	ldr r1, _0803B92C @ =0x0203C618
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
_0803B922:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803B928: .4byte gUnk_Sio_085C99F8
_0803B92C: .4byte 0x0203C618
_0803B930: .4byte gUnk_Sio_085CA638
_0803B934: .4byte gUnk_Sio_0810F350
_0803B938: .4byte gKeySt

	thumb_func_start sub_803B93C
sub_803B93C: @ 0x0803B93C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	ldr r4, _0803B9E8 @ =0x0203C618
	ldrb r0, [r4]
	cmp r0, #0xff
	bne _0803B958
	adds r0, r5, #0
	bl Proc_Break
_0803B958:
	ldrb r2, [r4]
	ldr r0, [r5, #0x54]
	cmp r0, #0x10
	bgt _0803B9C6
	movs r0, #4
	mov r8, r0
	lsls r2, r2, #1
	ldr r1, _0803B9EC @ =gUnk_Sio_0810F350
	movs r4, #0x10
	mov sb, r4
	adds r0, r2, #1
	adds r0, r0, r1
	str r0, [sp, #4]
	adds r6, r5, #0
	adds r6, #0x3c
	adds r7, r1, #0
	adds r7, #8
	adds r2, r2, r1
	mov sl, r2
_0803B97E:
	ldrb r1, [r7]
	ldr r3, [r5, #0x54]
	mov r0, sb
	str r0, [sp]
	movs r0, #4
	mov r4, sl
	ldrb r2, [r4]
	bl Interpolate
	adds r4, r0, #0
	ldrb r1, [r7, #1]
	ldr r0, [sp, #4]
	ldrb r2, [r0]
	ldr r3, [r5, #0x54]
	mov r0, sb
	str r0, [sp]
	movs r0, #4
	bl Interpolate
	adds r2, r0, #0
	ldr r0, [r6]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	adds r1, r4, #0
	bl sub_8040098
	subs r6, #4
	subs r7, #2
	movs r4, #1
	rsbs r4, r4, #0
	add r8, r4
	mov r0, r8
	cmp r0, #0
	bge _0803B97E
_0803B9C6:
	ldr r0, [r5, #0x54]
	cmp r0, #0x20
	ble _0803B9D2
	adds r0, r5, #0
	bl Proc_Break
_0803B9D2:
	ldr r0, [r5, #0x54]
	adds r0, #1
	str r0, [r5, #0x54]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803B9E8: .4byte 0x0203C618
_0803B9EC: .4byte gUnk_Sio_0810F350

	thumb_func_start sub_803B9F0
sub_803B9F0: @ 0x0803B9F0
	push {r4, r5, r6, lr}
	sub sp, #0x14
	adds r6, r0, #0
	mov r1, sp
	ldr r0, _0803BA40 @ =gUnk_Sio_0810F360
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3}
	stm r1!, {r2, r3}
	movs r0, #3
	bl EndFaceById
	adds r5, r6, #0
	adds r5, #0x2c
	movs r4, #4
_0803BA0E:
	ldm r5!, {r0}
	bl Proc_End
	subs r4, #1
	cmp r4, #0
	bge _0803BA0E
	ldr r1, _0803BA44 @ =0x0203C618
	ldrb r2, [r1]
	adds r0, r2, #0
	cmp r0, #0xff
	bne _0803BA4C
	bl EndBmVSync
	bl sub_803FB74
	bl sub_8036974
	ldr r0, _0803BA48 @ =ProcScr_DebugMonitor
	bl Proc_EndEach
	adds r0, r6, #0
	bl Proc_End
	b _0803BA5C
	.align 2, 0
_0803BA40: .4byte gUnk_Sio_0810F360
_0803BA44: .4byte 0x0203C618
_0803BA48: .4byte ProcScr_DebugMonitor
_0803BA4C:
	strb r2, [r1, #1]
	ldrb r1, [r1]
	lsls r0, r1, #2
	add r0, sp
	ldr r0, [r0]
	adds r1, r6, #0
	bl SpawnProcLocking
_0803BA5C:
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_803BA64
sub_803BA64: @ 0x0803BA64
	push {r4, lr}
	adds r4, r0, #0
	bl LoadUiFrameGraphics
	ldr r0, _0803BAC8 @ =0x0203C758
	ldr r1, _0803BACC @ =0x06001800
	movs r2, #0xc0
	movs r3, #0
	bl InitTextFont
	movs r0, #5
	bl sub_808525C
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803BA88
	bl sub_80860A4
_0803BA88:
	ldr r1, _0803BAD0 @ =0x0203C618
	movs r0, #0
	strb r0, [r1, #5]
	strb r0, [r1, #3]
	strb r0, [r1, #1]
	bl sub_8036964
	bl sub_803CE7C
	bl StartBmVSync
	ldr r1, _0803BAD4 @ =gPlaySt
	movs r0, #0xdf
	ldrb r2, [r1, #0x14]
	ands r0, r2
	strb r0, [r1, #0x14]
	movs r0, #0xd
	rsbs r0, r0, #0
	ldrb r2, [r1, #0x1d]
	ands r0, r2
	strb r0, [r1, #0x1d]
	ldr r0, _0803BAD8 @ =gUnk_Sio_085CA444
	adds r1, r4, #0
	bl SpawnProcLocking
	ldr r0, _0803BADC @ =ProcScr_DebugMonitor
	movs r1, #3
	bl SpawnProc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803BAC8: .4byte 0x0203C758
_0803BACC: .4byte 0x06001800
_0803BAD0: .4byte 0x0203C618
_0803BAD4: .4byte gPlaySt
_0803BAD8: .4byte gUnk_Sio_085CA444
_0803BADC: .4byte ProcScr_DebugMonitor

	thumb_func_start sub_803BAE0
sub_803BAE0: @ 0x0803BAE0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r4, #0
	ldr r0, _0803BB08 @ =gUnk_Sio_085C9940
	bl Proc_Find
	cmp r0, #0
	beq _0803BB10
	ldr r0, _0803BB0C @ =gKeySt
	ldr r1, [r0]
	movs r0, #2
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _0803BBEC
	adds r0, r5, #0
	movs r1, #4
	b _0803BBA8
	.align 2, 0
_0803BB08: .4byte gUnk_Sio_085C9940
_0803BB0C: .4byte gKeySt
_0803BB10:
	ldr r0, _0803BB30 @ =gUnk_Sio_085C98F4
	ldr r2, [r0]
	movs r0, #6
	ldrsb r0, [r2, r0]
	cmp r0, #1
	bgt _0803BB2A
	adds r1, r0, #0
	adds r0, r2, #0
	adds r0, #0xb
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #2
	bne _0803BB34
_0803BB2A:
	adds r0, r5, #0
	movs r1, #0
	b _0803BBA8
	.align 2, 0
_0803BB30: .4byte gUnk_Sio_085C98F4
_0803BB34:
	movs r1, #0
	adds r2, #0x1a
_0803BB38:
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0x3c
	bls _0803BB42
	adds r4, #1
_0803BB42:
	adds r1, #1
	cmp r1, #3
	ble _0803BB38
	bl sub_8035CF8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803BB60
	ldr r6, _0803BB68 @ =gUnk_Sio_085C98F4
	ldr r2, [r6]
	ldrb r0, [r2, #0x1e]
	cmp r0, #0x3c
	bhi _0803BB60
	cmp r4, #0
	beq _0803BB6C
_0803BB60:
	adds r0, r5, #0
	movs r1, #0
	b _0803BBA8
	.align 2, 0
_0803BB68: .4byte gUnk_Sio_085C98F4
_0803BB6C:
	ldr r0, _0803BBB0 @ =0x030044E0
	movs r1, #0x1c
	strb r1, [r0]
	ldrb r1, [r2, #6]
	strb r1, [r0, #1]
	ldrb r1, [r2]
	strh r1, [r0, #2]
	movs r1, #0xa
	bl sub_8035DC8
	ldr r0, [r6]
	ldrb r0, [r0, #6]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0803BBB4
	bl sub_808667C
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803BBB4
	mov r1, sp
	movs r0, #1
	strb r0, [r1]
	mov r0, sp
	movs r1, #4
	bl sub_8036208
	adds r0, r5, #0
	movs r1, #3
_0803BBA8:
	bl EventGotoLabel
_0803BBAC:
	movs r0, #0
	b _0803BBEE
	.align 2, 0
_0803BBB0: .4byte 0x030044E0
_0803BBB4:
	ldr r4, _0803BBE8 @ =gUnk_Sio_085C98F4
	ldr r1, [r4]
	movs r0, #3
	ldrb r2, [r1, #9]
	ands r0, r2
	cmp r0, #3
	bne _0803BBEC
	strb r0, [r1, #9]
	bl sub_8036608
	ldr r1, [r4]
	movs r2, #0
	movs r0, #6
	strh r0, [r1, #4]
	strb r2, [r1, #0x1e]
	ldr r0, [r4]
	ldrb r0, [r0, #6]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0803BBAC
	adds r0, r5, #0
	movs r1, #1
	bl EventGotoLabel
	b _0803BBAC
	.align 2, 0
_0803BBE8: .4byte gUnk_Sio_085C98F4
_0803BBEC:
	movs r0, #1
_0803BBEE:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_803BBF8
sub_803BBF8: @ 0x0803BBF8
	push {lr}
	adds r1, r0, #0
	ldr r0, _0803BC14 @ =gUnk_Sio_085C98F4
	ldr r0, [r0]
	ldrb r0, [r0, #9]
	cmp r0, #3
	bls _0803BC0E
	adds r0, r1, #0
	movs r1, #0
	bl EventGotoLabel
_0803BC0E:
	pop {r0}
	bx r0
	.align 2, 0
_0803BC14: .4byte gUnk_Sio_085C98F4

	thumb_func_start sub_803BC18
sub_803BC18: @ 0x0803BC18
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	bl GetTalkChoiceResult
	cmp r0, #1
	bne _0803BC30
	ldr r1, _0803BC2C @ =0x0203C980
	movs r0, #0
	b _0803BC34
	.align 2, 0
_0803BC2C: .4byte 0x0203C980
_0803BC30:
	ldr r1, _0803BC5C @ =0x0203C980
	movs r0, #1
_0803BC34:
	str r0, [r1]
	adds r4, r1, #0
	mov r0, sp
	ldr r1, [r4]
	strb r1, [r0]
	movs r1, #4
	bl sub_8036208
	ldr r0, [r4]
	cmp r0, #0
	beq _0803BC52
	adds r0, r5, #0
	movs r1, #5
	bl EventGotoLabel
_0803BC52:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803BC5C: .4byte 0x0203C980

	thumb_func_start sub_803BC60
sub_803BC60: @ 0x0803BC60
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r4, #0
	movs r1, #0
	ldr r0, _0803BCA8 @ =gUnk_Sio_085C98F4
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #0x1a
_0803BC72:
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0x3c
	bls _0803BC7C
	adds r4, #1
_0803BC7C:
	adds r1, #1
	cmp r1, #3
	ble _0803BC72
	bl sub_8035CF8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803BC9A
	ldr r0, _0803BCA8 @ =gUnk_Sio_085C98F4
	ldr r0, [r0]
	ldrb r0, [r0, #0x1e]
	cmp r0, #0x3c
	bhi _0803BC9A
	cmp r4, #0
	beq _0803BCAC
_0803BC9A:
	adds r0, r5, #0
	movs r1, #0
	bl EventGotoLabel
_0803BCA2:
	movs r0, #0
	b _0803BCD0
	.align 2, 0
_0803BCA8: .4byte gUnk_Sio_085C98F4
_0803BCAC:
	add r1, sp, #4
	mov r0, sp
	movs r2, #0
	bl sub_80362B0
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0803BCCE
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803BCA2
	adds r0, r5, #0
	movs r1, #5
	bl EventGotoLabel
	b _0803BCA2
_0803BCCE:
	movs r0, #1
_0803BCD0:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start sub_803BCD8
sub_803BCD8: @ 0x0803BCD8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	bl ClearText
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl Text_InsertDrawString
	adds r0, r4, #0
	movs r1, #0x36
	movs r2, #2
	adds r3, r6, #0
	bl Text_InsertDrawNumberOrBlank
	ldr r3, _0803BD18 @ =gUnk_Sio_0810F374
	adds r0, r4, #0
	movs r1, #0x3e
	movs r2, #0
	bl Text_InsertDrawString
	ldr r1, _0803BD1C @ =gBg0Tm+0x31E
	adds r0, r4, #0
	bl PutText
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803BD18: .4byte gUnk_Sio_0810F374
_0803BD1C: .4byte gBg0Tm+0x31E

	thumb_func_start sub_803BD20
sub_803BD20: @ 0x0803BD20
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r5, #0x3c
	adds r0, #0x3b
	ldrb r1, [r5]
	ldrb r0, [r0]
	cmp r1, r0
	bhs _0803BD76
	ldr r0, _0803BD80 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt _0803BD42
	movs r0, #0x7d
	bl m4aSongNumStart
_0803BD42:
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	ldr r0, _0803BD84 @ =0x0203C67C
	ldr r1, _0803BD88 @ =gUnk_Sio_0810F378
	ldrb r2, [r5]
	bl sub_803BCD8
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r2, _0803BD8C @ =gBg0Tm+0x3DC
	movs r3, #0xc0
	lsls r3, r3, #7
	movs r1, #0x64
	str r1, [sp]
	ldrb r4, [r5]
	str r4, [sp, #4]
	ldrb r5, [r5]
	subs r1, r1, r5
	str r1, [sp, #8]
	movs r1, #0xe
	bl sub_806E998
	movs r0, #1
	bl EnableBgSync
_0803BD76:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803BD80: .4byte gPlaySt
_0803BD84: .4byte 0x0203C67C
_0803BD88: .4byte gUnk_Sio_0810F378
_0803BD8C: .4byte gBg0Tm+0x3DC

	thumb_func_start sub_803BD90
sub_803BD90: @ 0x0803BD90
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r5, #0x3c
	adds r0, #0x3b
	ldrb r1, [r5]
	ldrb r0, [r0]
	cmp r1, r0
	bhs _0803BDE6
	ldr r0, _0803BDF0 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt _0803BDB2
	movs r0, #0x7d
	bl m4aSongNumStart
_0803BDB2:
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	ldr r0, _0803BDF4 @ =0x0203C67C
	ldr r1, _0803BDF8 @ =gUnk_Sio_0810F380
	ldrb r2, [r5]
	bl sub_803BCD8
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r2, _0803BDFC @ =gBg0Tm+0x3DC
	movs r3, #0xc0
	lsls r3, r3, #7
	movs r1, #0x64
	str r1, [sp]
	ldrb r4, [r5]
	str r4, [sp, #4]
	ldrb r5, [r5]
	subs r1, r1, r5
	str r1, [sp, #8]
	movs r1, #0xe
	bl sub_806E998
	movs r0, #1
	bl EnableBgSync
_0803BDE6:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803BDF0: .4byte gPlaySt
_0803BDF4: .4byte 0x0203C67C
_0803BDF8: .4byte gUnk_Sio_0810F380
_0803BDFC: .4byte gBg0Tm+0x3DC

	thumb_func_start sub_803BE00
sub_803BE00: @ 0x0803BE00
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _0803BE44 @ =0x0203C758
	bl SetTextFont
	bl InitSystemTextFont
	ldr r0, _0803BE48 @ =gUnk_Sio_085C98F4
	ldr r0, [r0]
	ldrb r0, [r0, #6]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0803BE5C
	ldr r1, _0803BE4C @ =ReadSramFast
	ldr r0, _0803BE50 @ =0x0E007000
	ldr r4, _0803BE54 @ =gUnk_Sio_02000000
	movs r5, #0x80
	lsls r5, r5, #5
	ldr r3, [r1]
	adds r1, r4, #0
	adds r2, r5, #0
	bl _call_via_r3
	ldr r2, _0803BE58 @ =sub_803BD20
	str r6, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #0
	bl sub_8036804
	b _0803BE66
	.align 2, 0
_0803BE44: .4byte 0x0203C758
_0803BE48: .4byte gUnk_Sio_085C98F4
_0803BE4C: .4byte ReadSramFast
_0803BE50: .4byte 0x0E007000
_0803BE54: .4byte gUnk_Sio_02000000
_0803BE58: .4byte sub_803BD20
_0803BE5C:
	ldr r0, _0803BE70 @ =gUnk_Sio_02000000
	ldr r1, _0803BE74 @ =sub_803BD90
	adds r2, r6, #0
	bl sub_8036884
_0803BE66:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803BE70: .4byte gUnk_Sio_02000000
_0803BE74: .4byte sub_803BD90

	thumb_func_start sub_803BE78
sub_803BE78: @ 0x0803BE78
	push {lr}
	bl sub_80368B0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803BE88
	movs r0, #1
	b _0803BEB8
_0803BE88:
	ldr r0, _0803BEBC @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt _0803BE98
	movs r0, #0x7e
	bl m4aSongNumStart
_0803BE98:
	bl InitTalkTextFont
	ldr r0, _0803BEC0 @ =gUnk_Sio_085C98F4
	ldr r0, [r0]
	ldrb r0, [r0, #6]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0803BEB6
	ldr r0, _0803BEC4 @ =gUnk_Sio_02000000
	ldr r1, _0803BEC8 @ =0x0E007000
	movs r2, #0x80
	lsls r2, r2, #5
	bl WriteAndVerifySramFast
_0803BEB6:
	movs r0, #0
_0803BEB8:
	pop {r1}
	bx r1
	.align 2, 0
_0803BEBC: .4byte gPlaySt
_0803BEC0: .4byte gUnk_Sio_085C98F4
_0803BEC4: .4byte gUnk_Sio_02000000
_0803BEC8: .4byte 0x0E007000

	thumb_func_start sub_803BECC
sub_803BECC: @ 0x0803BECC
	ldr r0, _0803BEDC @ =gUnk_Sio_085C98F4
	ldr r2, [r0]
	movs r1, #6
	ldrsb r1, [r2, r1]
	movs r0, #1
	lsls r0, r1
	strb r0, [r2, #0xa]
	bx lr
	.align 2, 0
_0803BEDC: .4byte gUnk_Sio_085C98F4

	thumb_func_start sub_803BEE0
sub_803BEE0: @ 0x0803BEE0
	push {r4, lr}
	ldr r0, _0803BF0C @ =0x0300456C
	movs r2, #0
	movs r1, #0x19
	strb r1, [r0]
	ldr r4, _0803BF10 @ =gUnk_Sio_085C98F4
	ldr r1, [r4]
	ldrb r1, [r1, #6]
	strb r1, [r0, #1]
	strh r2, [r0, #2]
	movs r1, #4
	bl sub_8035DC8
	ldr r4, [r4]
	ldrb r0, [r4, #9]
	ldrb r1, [r4, #0xa]
	ands r0, r1
	ldrb r1, [r4, #9]
	cmp r0, r1
	beq _0803BF14
	movs r0, #1
	b _0803BF20
	.align 2, 0
_0803BF0C: .4byte 0x0300456C
_0803BF10: .4byte gUnk_Sio_085C98F4
_0803BF14:
	movs r1, #6
	ldrsb r1, [r4, r1]
	movs r0, #1
	lsls r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0
_0803BF20:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_803BF28
sub_803BF28: @ 0x0803BF28
	push {r4, lr}
	sub sp, #0xc
	movs r0, #6
	bl sub_80412DC
	movs r4, #0
	str r4, [sp]
	movs r0, #0xd
	movs r1, #0xb
	movs r2, #0x10
	movs r3, #6
	bl sub_8041358
	ldr r0, _0803BF7C @ =0x0203C758
	bl SetTextFont
	bl InitSystemTextFont
	ldr r0, _0803BF80 @ =0x0203C67C
	ldr r1, _0803BF84 @ =gUnk_Sio_0810F388
	movs r2, #0
	bl sub_803BCD8
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r2, _0803BF88 @ =gBg0Tm+0x3DC
	movs r3, #0xc0
	lsls r3, r3, #7
	movs r1, #0x64
	str r1, [sp]
	str r4, [sp, #4]
	str r1, [sp, #8]
	movs r1, #0xd
	bl sub_806E998
	movs r0, #1
	bl EnableBgSync
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803BF7C: .4byte 0x0203C758
_0803BF80: .4byte 0x0203C67C
_0803BF84: .4byte gUnk_Sio_0810F388
_0803BF88: .4byte gBg0Tm+0x3DC

	thumb_func_start sub_803BF8C
sub_803BF8C: @ 0x0803BF8C
	ldr r2, _0803BFAC @ =gDispIo
	adds r2, #0x36
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
	bx lr
	.align 2, 0
_0803BFAC: .4byte gDispIo

	thumb_func_start sub_803BFB0
sub_803BFB0: @ 0x0803BFB0
	push {r4, r5, lr}
	ldr r4, [r0, #0x14]
	movs r0, #3
	bl EndFaceById
	adds r5, r4, #0
	adds r5, #0x2c
	movs r4, #4
_0803BFC0:
	ldm r5!, {r0}
	bl Proc_End
	subs r4, #1
	cmp r4, #0
	bge _0803BFC0
	bl sub_803FA14
	movs r0, #0
	movs r1, #0
	bl sub_803FAA4
	ldr r0, _0803C000 @ =gUnk_Sio_085C98F4
	ldr r1, [r0]
	movs r0, #3
	strb r0, [r1]
	ldr r0, _0803C004 @ =0x0203C758
	bl SetTextFont
	bl InitSystemTextFont
	ldr r0, _0803C008 @ =0x0203C67C
	movs r1, #0xa
	bl InitTextDb
	movs r0, #1
	bl FadeBgmOut
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803C000: .4byte gUnk_Sio_085C98F4
_0803C004: .4byte 0x0203C758
_0803C008: .4byte 0x0203C67C

	thumb_func_start sub_803C00C
sub_803C00C: @ 0x0803C00C
	push {lr}
	adds r1, r0, #0
	ldr r0, _0803C024 @ =gUnk_Sio_085C98F4
	ldr r2, [r0]
	movs r0, #3
	strb r0, [r2]
	ldr r0, _0803C028 @ =gUnk_Sio_085CA504
	bl StartEventLocking
	pop {r0}
	bx r0
	.align 2, 0
_0803C024: .4byte gUnk_Sio_085C98F4
_0803C028: .4byte gUnk_Sio_085CA504

	thumb_func_start sub_803C02C
sub_803C02C: @ 0x0803C02C
	push {lr}
	bl sub_8036B40
	bl sub_8039550
	bl sub_8039574
	bl sub_80353AC
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_803C044
sub_803C044: @ 0x0803C044
	push {r4, lr}
	adds r4, r0, #0
	bl GetTalkChoiceResult
	cmp r0, #1
	beq _0803C058
	adds r0, r4, #0
	movs r1, #1
	bl EventGotoLabel
_0803C058:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_803C060
sub_803C060: @ 0x0803C060
	push {r4, lr}
	adds r4, r0, #0
	bl GetTalkChoiceResult
	cmp r0, #1
	bne _0803C072
	bl sub_808439C
	b _0803C07A
_0803C072:
	adds r0, r4, #0
	movs r1, #1
	bl EventGotoLabel
_0803C07A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_803C080
sub_803C080: @ 0x0803C080
	push {lr}
	adds r1, r0, #0
	ldr r0, _0803C090 @ =gUnk_Sio_085CA6B8
	bl StartEventLocking
	pop {r0}
	bx r0
	.align 2, 0
_0803C090: .4byte gUnk_Sio_085CA6B8

	thumb_func_start sub_803C094
sub_803C094: @ 0x0803C094
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	ldr r0, _0803C0D8 @ =0x0203C618
	adds r1, r0, #0
	adds r1, #0xa0
	ldrb r3, [r1]
	adds r0, #0xec
	movs r1, #2
	ldrb r0, [r0]
	ands r1, r0
	cmp r1, #0
	beq _0803C0E0
	movs r6, #0
	cmp r6, r3
	bge _0803C13A
	ldr r4, _0803C0DC @ =0x0203C993
	adds r5, r4, #5
	mov r2, r8
_0803C0BC:
	adds r1, r6, r4
	ldrb r0, [r1]
	strb r0, [r2]
	ldrb r1, [r1]
	lsls r0, r1, #2
	adds r0, r0, r5
	ldr r0, [r0]
	str r0, [r2, #4]
	adds r2, #8
	adds r6, #1
	cmp r6, r3
	blt _0803C0BC
	b _0803C13A
	.align 2, 0
_0803C0D8: .4byte 0x0203C618
_0803C0DC: .4byte 0x0203C993
_0803C0E0:
	movs r6, #0
	subs r0, r3, #2
	mov ip, r0
	cmp r6, r3
	bge _0803C100
	ldr r0, _0803C104 @ =0x0203C984
	adds r2, r0, #0
	adds r2, #0x14
	mov r1, r8
_0803C0F2:
	strb r6, [r1]
	ldm r2!, {r0}
	str r0, [r1, #4]
	adds r1, #8
	adds r6, #1
	cmp r6, r3
	blt _0803C0F2
_0803C100:
	movs r6, #0
	b _0803C134
	.align 2, 0
_0803C104: .4byte 0x0203C984
_0803C108:
	adds r5, r0, #0
	adds r7, r6, #1
	cmp r0, r6
	blt _0803C132
	lsls r0, r0, #3
	mov r1, r8
	adds r2, r0, r1
_0803C116:
	ldr r4, [r2, #4]
	ldr r3, [r2, #0xc]
	cmp r4, r3
	bhs _0803C12A
	ldrb r1, [r2]
	ldrb r0, [r2, #8]
	strb r0, [r2]
	strb r1, [r2, #8]
	str r3, [r2, #4]
	str r4, [r2, #0xc]
_0803C12A:
	subs r2, #8
	subs r5, #1
	cmp r5, r6
	bge _0803C116
_0803C132:
	adds r6, r7, #0
_0803C134:
	mov r0, ip
	cmp r6, r0
	ble _0803C108
_0803C13A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_803C144
sub_803C144: @ 0x0803C144
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	lsls r0, r2, #5
	adds r0, r0, r6
	lsls r0, r0, #1
	ldr r1, _0803C19C @ =gBg1Tm
	adds r0, r0, r1
	movs r1, #0
	adds r5, r2, #1
_0803C158:
	adds r2, r1, #1
	movs r1, #5
_0803C15C:
	strh r3, [r0]
	adds r0, #2
	adds r3, #1
	subs r1, #1
	cmp r1, #0
	bge _0803C15C
	adds r0, #0x34
	adds r1, r2, #0
	cmp r1, #3
	ble _0803C158
	adds r0, r4, #0
	bl ClearText
	adds r0, r4, #0
	movs r1, #0x18
	movs r2, #2
	ldr r3, [sp, #0x10]
	bl Text_InsertDrawNumberOrBlank
	lsls r1, r5, #5
	adds r1, #1
	adds r1, r1, r6
	lsls r1, r1, #1
	ldr r0, _0803C1A0 @ =gBg0Tm
	adds r1, r1, r0
	adds r0, r4, #0
	bl PutText
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803C19C: .4byte gBg1Tm
_0803C1A0: .4byte gBg0Tm

	thumb_func_start sub_803C1A4
sub_803C1A4: @ 0x0803C1A4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _0803C264 @ =gUnk_081094B0
	ldr r1, _0803C268 @ =0x06002000
	bl Decompress
	ldr r0, _0803C26C @ =gUnk_08109A00
	movs r1, #0x40
	movs r2, #0x80
	bl ApplyPaletteExt
	movs r0, #0
	bl SetTextFont
	bl ResetTextFont
	movs r0, #0
	mov sb, r0
	ldr r0, _0803C270 @ =gUnk_Sio_0810F390
	mov sl, r0
	adds r6, r4, #0
	adds r6, #0x2c
	ldr r7, _0803C274 @ =gUnk_Sio_0810F400
_0803C1DC:
	ldr r0, _0803C278 @ =gUnk_Sio_085C98F4
	ldr r0, [r0]
	ldrb r0, [r0, #6]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	add r0, sb
	add r0, sl
	ldrb r5, [r0]
	adds r0, r5, #0
	bl sub_8035CB0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803C23E
	ldr r0, _0803C27C @ =0x0203C984
	mov r8, r0
	adds r0, #0xa
	adds r0, r5, r0
	ldrb r0, [r0]
	adds r4, r5, #2
	cmp r0, #0
	bne _0803C214
	lsls r1, r4, #5
	ldr r0, _0803C280 @ =gUnk_08109C60
	movs r2, #0x20
	bl ApplyPaletteExt
_0803C214:
	movs r0, #0xf
	ands r4, r0
	lsls r4, r4, #0xc
	adds r0, #0xf1
	adds r4, r4, r0
	adds r0, r6, #0
	movs r1, #4
	bl InitTextDb
	ldrb r1, [r7]
	ldrb r2, [r7, #1]
	lsls r0, r5, #2
	mov r3, r8
	adds r3, #0x14
	adds r0, r0, r3
	ldr r0, [r0]
	str r0, [sp]
	adds r0, r6, #0
	adds r3, r4, #0
	bl sub_803C144
_0803C23E:
	adds r6, #8
	adds r7, #2
	movs r0, #1
	add sb, r0
	mov r0, sb
	cmp r0, #3
	ble _0803C1DC
	movs r0, #3
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
_0803C264: .4byte gUnk_081094B0
_0803C268: .4byte 0x06002000
_0803C26C: .4byte gUnk_08109A00
_0803C270: .4byte gUnk_Sio_0810F390
_0803C274: .4byte gUnk_Sio_0810F400
_0803C278: .4byte gUnk_Sio_085C98F4
_0803C27C: .4byte 0x0203C984
_0803C280: .4byte gUnk_08109C60

	thumb_func_start nullsub_17
nullsub_17: @ 0x0803C284
	bx lr
	.align 2, 0

	thumb_func_start sub_803C288
sub_803C288: @ 0x0803C288
	push {lr}
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	ldr r0, _0803C2AC @ =gUnk_Sio_085CA6F4
	movs r1, #3
	bl SpawnProc
	pop {r0}
	bx r0
	.align 2, 0
_0803C2AC: .4byte gUnk_Sio_085CA6F4

	thumb_func_start sub_803C2B0
sub_803C2B0: @ 0x0803C2B0
	push {lr}
	ldr r0, _0803C2C0 @ =gUnk_Sio_085CA6F4
	bl Proc_EndEach
	bl ClearBg0Bg1
	pop {r0}
	bx r0
	.align 2, 0
_0803C2C0: .4byte gUnk_Sio_085CA6F4

	thumb_func_start sub_803C2C4
sub_803C2C4: @ 0x0803C2C4
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, #0x33
	ldrb r0, [r0]
	bl GetUnit
	adds r4, r0, #0
	ldr r1, _0803C314 @ =gUnk_Sio_0810F3A0
	adds r2, r5, #0
	adds r2, #0x32
	ldr r0, _0803C318 @ =gUnk_Sio_085C98F4
	ldr r0, [r0]
	ldrb r0, [r0, #6]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	ldrb r2, [r2]
	adds r0, r2, r0
	adds r0, r0, r1
	ldrb r2, [r0]
	adds r0, r5, #0
	adds r0, #0x40
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0803C31C
	ldrb r0, [r4, #0xe]
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	lsls r0, r0, #4
	subs r0, #0x10
	strh r0, [r5, #0x2a]
	movs r0, #0xf
	ldrsb r0, [r4, r0]
	lsls r0, r0, #4
	strh r0, [r5, #0x2c]
	lsls r2, r2, #1
	b _0803C344
	.align 2, 0
_0803C314: .4byte gUnk_Sio_0810F3A0
_0803C318: .4byte gUnk_Sio_085C98F4
_0803C31C:
	movs r1, #0xe
	ldrsb r1, [r4, r1]
	lsls r1, r1, #4
	ldr r3, _0803C380 @ =gUnk_Sio_085CA70C
	lsls r0, r2, #3
	adds r0, r0, r3
	ldr r0, [r0]
	adds r0, r0, r1
	subs r0, #0xc
	strh r0, [r5, #0x2a]
	movs r1, #0xf
	ldrsb r1, [r4, r1]
	lsls r1, r1, #4
	lsls r2, r2, #1
	adds r0, r2, #1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrh r0, [r0]
	adds r1, r0, r1
	strh r1, [r5, #0x2c]
_0803C344:
	ldr r1, _0803C384 @ =gUnk_Sio_0810F400
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, #8
	movs r4, #0
	strh r0, [r5, #0x2e]
	adds r0, r2, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, #8
	strh r0, [r5, #0x30]
	ldr r0, _0803C388 @ =gFont_Unk_Sio_02001000
	bl SetTextFont
	ldr r0, _0803C38C @ =gText_Unk_Sio_02001018
	adds r1, r5, #0
	adds r1, #0x32
	ldrb r1, [r1]
	lsls r1, r1, #5
	adds r1, #0x18
	ldr r3, [r5, #0x34]
	movs r2, #2
	bl Text_InsertDrawNumberOrBlank
	str r4, [r5, #0x3c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803C380: .4byte gUnk_Sio_085CA70C
_0803C384: .4byte gUnk_Sio_0810F400
_0803C388: .4byte gFont_Unk_Sio_02001000
_0803C38C: .4byte gText_Unk_Sio_02001018

	thumb_func_start sub_803C390
sub_803C390: @ 0x0803C390
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	adds r0, #0x33
	ldrb r0, [r0]
	bl GetUnit
	str r0, [sp, #4]
	ldr r3, [r7, #0x3c]
	cmp r3, #0x10
	bhi _0803C424
	movs r0, #0x80
	lsls r0, r0, #1
	mov r8, r0
	movs r0, #0x10
	str r0, [sp]
	movs r0, #1
	movs r1, #0x10
	mov r2, r8
	bl Interpolate
	mov sl, r0
	ldr r4, _0803C454 @ =gSinLut
	movs r1, #0x80
	adds r1, r1, r4
	mov sb, r1
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #4
	mov r1, r8
	bl Div
	adds r6, r0, #0
	lsls r6, r6, #0x10
	asrs r6, r6, #0x10
	movs r1, #0
	ldrsh r0, [r4, r1]
	rsbs r0, r0, #0
	lsls r0, r0, #4
	mov r1, sl
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
	mov r1, sl
	bl Div
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	movs r0, #0
	adds r1, r6, #0
	adds r2, r5, #0
	adds r3, r4, #0
	bl SetObjAffine
_0803C424:
	adds r0, r7, #0
	adds r0, #0x40
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0803C476
	ldr r1, [r7, #0x3c]
	cmp r1, #3
	bls _0803C476
	cmp r1, #0x16
	bhi _0803C476
	subs r1, #4
	ldr r4, [sp, #4]
	ldrb r4, [r4, #0xe]
	cmp r4, #8
	bne _0803C45C
	ldr r0, _0803C458 @ =gUnk_Sio_085CA72C
	lsls r1, r1, #1
	adds r0, r1, r0
	ldrh r2, [r7, #0x2a]
	ldrh r0, [r0]
	adds r0, r2, r0
	b _0803C468
	.align 2, 0
_0803C454: .4byte gSinLut
_0803C458: .4byte gUnk_Sio_085CA72C
_0803C45C:
	ldr r0, _0803C4BC @ =gUnk_Sio_085CA72C
	lsls r1, r1, #1
	adds r0, r1, r0
	ldrh r4, [r7, #0x2a]
	ldrh r0, [r0]
	subs r0, r4, r0
_0803C468:
	strh r0, [r7, #0x2a]
	ldr r0, _0803C4C0 @ =gUnk_Sio_085CA752
	adds r0, r1, r0
	ldrh r1, [r7, #0x2c]
	ldrh r0, [r0]
	subs r0, r1, r0
	strh r0, [r7, #0x2c]
_0803C476:
	movs r2, #0x2a
	ldrsh r0, [r7, r2]
	movs r4, #0x2c
	ldrsh r1, [r7, r4]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
	ldr r2, _0803C4C4 @ =Sprite_32x16
	adds r3, r7, #0
	adds r3, #0x32
	ldrb r3, [r3]
	lsls r3, r3, #2
	ldr r4, _0803C4C8 @ =0x00009340
	adds r3, r3, r4
	bl PutOamHiRam
	ldr r0, [r7, #0x3c]
	adds r0, #1
	str r0, [r7, #0x3c]
	cmp r0, #0x40
	bls _0803C4AA
	movs r0, #0
	str r0, [r7, #0x3c]
	adds r0, r7, #0
	bl Proc_Break
_0803C4AA:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803C4BC: .4byte gUnk_Sio_085CA72C
_0803C4C0: .4byte gUnk_Sio_085CA752
_0803C4C4: .4byte Sprite_32x16
_0803C4C8: .4byte 0x00009340

	thumb_func_start sub_803C4CC
sub_803C4CC: @ 0x0803C4CC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0x2a
	ldrsh r1, [r6, r0]
	movs r0, #0x2e
	ldrsh r2, [r6, r0]
	ldr r3, [r6, #0x3c]
	movs r4, #0x30
	str r4, [sp]
	movs r0, #5
	bl Interpolate
	adds r5, r0, #0
	movs r0, #0x2c
	ldrsh r1, [r6, r0]
	movs r0, #0x30
	ldrsh r2, [r6, r0]
	ldr r3, [r6, #0x3c]
	str r4, [sp]
	movs r0, #5
	bl Interpolate
	adds r1, r0, #0
	ldr r2, _0803C528 @ =Sprite_32x16
	adds r0, r6, #0
	adds r0, #0x32
	ldrb r0, [r0]
	lsls r3, r0, #2
	ldr r0, _0803C52C @ =0x00009340
	adds r3, r3, r0
	adds r0, r5, #0
	bl PutOamHiRam
	ldr r0, [r6, #0x3c]
	adds r0, #1
	str r0, [r6, #0x3c]
	cmp r0, #0x20
	bls _0803C520
	adds r0, r6, #0
	bl Proc_Break
_0803C520:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803C528: .4byte Sprite_32x16
_0803C52C: .4byte 0x00009340

	thumb_func_start sub_803C530
sub_803C530: @ 0x0803C530
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r5, r0, #0
	mov r8, r1
	adds r4, r2, #0
	adds r6, r3, #0
	bl ClearText
	adds r0, r5, #0
	movs r1, #0x18
	movs r2, #2
	adds r3, r6, #0
	bl Text_InsertDrawNumberOrBlank
	adds r4, #1
	lsls r4, r4, #5
	adds r4, #1
	add r4, r8
	lsls r4, r4, #1
	ldr r0, _0803C574 @ =gBg0Tm
	adds r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl PutText
	movs r0, #1
	bl EnableBgSync
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803C574: .4byte gBg0Tm

	thumb_func_start sub_803C578
sub_803C578: @ 0x0803C578
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _0803C5D8 @ =gUnk_Sio_0810F3A0
	adds r2, r6, #0
	adds r2, #0x32
	ldr r0, _0803C5DC @ =gUnk_Sio_085C98F4
	ldr r0, [r0]
	ldrb r0, [r0, #6]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	ldrb r2, [r2]
	adds r0, r2, r0
	adds r0, r0, r1
	ldr r2, _0803C5E0 @ =gUnk_Sio_0810F400
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r1, r0, r2
	ldrb r1, [r1]
	movs r5, #0
	strh r1, [r6, #0x2a]
	adds r0, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	strh r0, [r6, #0x2c]
	movs r0, #0
	bl SetTextFont
	adds r0, r6, #0
	adds r0, #0x48
	movs r2, #0x2a
	ldrsh r1, [r6, r2]
	movs r3, #0x2c
	ldrsh r2, [r6, r3]
	ldr r3, [r6, #0x38]
	ldr r4, [r6, #0x34]
	subs r3, r3, r4
	bl sub_803C530
	str r5, [r6, #0x3c]
	ldr r0, [r6, #0x38]
	ldr r1, [r6, #0x34]
	subs r0, r0, r1
	str r0, [r6, #0x44]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803C5D8: .4byte gUnk_Sio_0810F3A0
_0803C5DC: .4byte gUnk_Sio_085C98F4
_0803C5E0: .4byte gUnk_Sio_0810F400

	thumb_func_start sub_803C5E4
sub_803C5E4: @ 0x0803C5E4
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r2, [r4, #0x38]
	ldr r1, [r4, #0x34]
	subs r1, r2, r1
	ldr r3, [r4, #0x3c]
	movs r0, #0xa
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	adds r5, r0, #0
	movs r0, #0
	bl SetTextFont
	adds r0, r4, #0
	adds r0, #0x48
	movs r2, #0x2a
	ldrsh r1, [r4, r2]
	movs r3, #0x2c
	ldrsh r2, [r4, r3]
	adds r3, r5, #0
	bl sub_803C530
	ldr r0, [r4, #0x44]
	cmp r0, r5
	beq _0803C63C
	adds r1, r4, #0
	adds r1, #0x32
	ldr r0, _0803C66C @ =gUnk_Sio_085C98F4
	ldr r0, [r0]
	ldrb r1, [r1]
	ldrb r0, [r0, #6]
	cmp r1, r0
	bne _0803C63C
	ldr r0, _0803C670 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt _0803C63C
	movs r0, #0x80
	bl m4aSongNumStart
_0803C63C:
	str r5, [r4, #0x44]
	ldr r0, [r4, #0x3c]
	adds r0, #1
	str r0, [r4, #0x3c]
	cmp r0, #0xa
	bls _0803C664
	movs r0, #0
	str r0, [r4, #0x3c]
	ldr r0, _0803C674 @ =0x0203C984
	adds r1, r4, #0
	adds r1, #0x32
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r0, #0x14
	adds r1, r1, r0
	ldr r0, [r4, #0x38]
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
_0803C664:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803C66C: .4byte gUnk_Sio_085C98F4
_0803C670: .4byte gPlaySt
_0803C674: .4byte 0x0203C984

	thumb_func_start sub_803C678
sub_803C678: @ 0x0803C678
	push {lr}
	adds r1, r0, #0
	ldr r0, [r1, #0x3c]
	adds r0, #1
	str r0, [r1, #0x3c]
	cmp r0, #0x14
	bls _0803C68C
	adds r0, r1, #0
	bl Proc_Break
_0803C68C:
	pop {r0}
	bx r0

	thumb_func_start sub_803C690
sub_803C690: @ 0x0803C690
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0803C6B4 @ =gFont_Unk_Sio_02001000
	bl SetTextFont
	ldr r0, _0803C6B8 @ =gText_Unk_Sio_02001018
	ldr r3, [r4, #0x54]
	movs r1, #0x80
	movs r2, #0
	bl Text_InsertDrawString
	adds r4, #0x4c
	movs r0, #0
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803C6B4: .4byte gFont_Unk_Sio_02001000
_0803C6B8: .4byte gText_Unk_Sio_02001018

	thumb_func_start sub_803C6BC
sub_803C6BC: @ 0x0803C6BC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0x4c
	adds r0, r0, r7
	mov sb, r0
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x10
	bgt _0803C74E
	movs r2, #0x80
	lsls r2, r2, #1
	mov r8, r2
	mov r0, sb
	movs r1, #0
	ldrsh r3, [r0, r1]
	movs r0, #0x10
	str r0, [sp]
	movs r0, #1
	movs r1, #0x10
	bl Interpolate
	mov sl, r0
	ldr r4, _0803C7BC @ =gSinLut
	ldr r2, _0803C7C0 @ =gSinLut+0x80
	movs r1, #0
	ldrsh r0, [r2, r1]
	lsls r0, r0, #4
	mov r1, r8
	bl Div
	adds r6, r0, #0
	lsls r6, r6, #0x10
	asrs r6, r6, #0x10
	movs r2, #0
	ldrsh r0, [r4, r2]
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
	ldr r2, _0803C7C0 @ =gSinLut+0x80
	movs r1, #0
	ldrsh r0, [r2, r1]
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
_0803C74E:
	ldr r0, [r7, #0x2c]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r1, [r7, #0x30]
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r1, r4
	ldr r5, _0803C7C4 @ =Sprite_32x16
	ldr r3, _0803C7C8 @ =0x00009350
	adds r2, r5, #0
	bl PutOamHiRam
	ldr r0, [r7, #0x2c]
	movs r1, #0x88
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, [r7, #0x30]
	adds r1, r1, r4
	ldr r3, _0803C7CC @ =0x00009354
	adds r2, r5, #0
	bl PutOamHiRam
	ldr r0, [r7, #0x2c]
	movs r2, #0x90
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r1, [r7, #0x30]
	adds r1, r1, r4
	ldr r2, _0803C7D0 @ =Sprite_16x16
	ldr r3, _0803C7D4 @ =0x00009358
	bl PutOamHiRam
	mov r1, sb
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x40
	ble _0803C7AA
	movs r0, #0
	strh r0, [r1]
	adds r0, r7, #0
	bl Proc_Break
_0803C7AA:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803C7BC: .4byte gSinLut
_0803C7C0: .4byte gSinLut+0x80
_0803C7C4: .4byte Sprite_32x16
_0803C7C8: .4byte 0x00009350
_0803C7CC: .4byte 0x00009354
_0803C7D0: .4byte Sprite_16x16
_0803C7D4: .4byte 0x00009358

	thumb_func_start sub_803C7D8
sub_803C7D8: @ 0x0803C7D8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	adds r0, #0x4c
	str r0, [sp, #4]
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x10
	bgt _0803C86E
	movs r2, #0x80
	lsls r2, r2, #1
	mov r8, r2
	ldr r0, [sp, #4]
	movs r1, #0
	ldrsh r3, [r0, r1]
	movs r0, #0x10
	str r0, [sp]
	movs r0, #4
	mov r1, r8
	movs r2, #0x10
	bl Interpolate
	mov sl, r0
	ldr r4, _0803C8D8 @ =gSinLut
	movs r2, #0x80
	adds r2, r2, r4
	mov sb, r2
	movs r1, #0
	ldrsh r0, [r2, r1]
	lsls r0, r0, #4
	mov r1, r8
	bl Div
	adds r6, r0, #0
	lsls r6, r6, #0x10
	asrs r6, r6, #0x10
	movs r2, #0
	ldrsh r0, [r4, r2]
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
	movs r1, #0
	ldrsh r0, [r2, r1]
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
_0803C86E:
	ldr r0, [r7, #0x2c]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r1, [r7, #0x30]
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r1, r4
	ldr r5, _0803C8DC @ =Sprite_32x16
	ldr r3, _0803C8E0 @ =0x00009350
	adds r2, r5, #0
	bl PutOamHiRam
	ldr r0, [r7, #0x2c]
	movs r1, #0x88
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, [r7, #0x30]
	adds r1, r1, r4
	ldr r3, _0803C8E4 @ =0x00009354
	adds r2, r5, #0
	bl PutOamHiRam
	ldr r0, [r7, #0x2c]
	movs r2, #0x90
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r1, [r7, #0x30]
	adds r1, r1, r4
	ldr r2, _0803C8E8 @ =Sprite_16x16
	ldr r3, _0803C8EC @ =0x00009358
	bl PutOamHiRam
	ldr r1, [sp, #4]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x10
	ble _0803C8C6
	adds r0, r7, #0
	bl Proc_Break
_0803C8C6:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803C8D8: .4byte gSinLut
_0803C8DC: .4byte Sprite_32x16
_0803C8E0: .4byte 0x00009350
_0803C8E4: .4byte 0x00009354
_0803C8E8: .4byte Sprite_16x16
_0803C8EC: .4byte 0x00009358

	thumb_func_start sub_803C8F0
sub_803C8F0: @ 0x0803C8F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov sb, r3
	movs r0, #0
	mov sl, r0
	ldr r0, _0803C9C8 @ =Pal_SystemText
	movs r1, #0xc8
	lsls r1, r1, #2
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, _0803C9CC @ =gFont_Unk_Sio_02001000
	ldr r1, _0803C9D0 @ =0x06016800
	movs r2, #3
	bl InitSpriteTextFont
	movs r0, #0
	bl SetTextFontGlyphs
	bl ResetTextFont
	ldr r4, _0803C9D4 @ =gText_Unk_Sio_02001018
	adds r0, r4, #0
	bl InitSpriteText
	adds r0, r4, #0
	movs r1, #0
	bl SpriteText_DrawBackgroundExt
	movs r0, #0
	bl SetTextFont
	movs r1, #0
	mov r8, r1
_0803C946:
	ldr r0, _0803C9D8 @ =gUnk_Sio_085C98F4
	ldr r0, [r0]
	ldrb r0, [r0, #6]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	add r0, r8
	ldr r1, _0803C9DC @ =gUnk_Sio_0810F3A0
	adds r0, r0, r1
	ldrb r4, [r0]
	adds r0, r4, #0
	bl sub_8035CB0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803C9F4
	ldr r6, _0803C9E0 @ =0x0203C984
	lsls r5, r4, #3
	adds r0, r6, #0
	adds r0, #0x30
	adds r7, r5, r0
	ldr r0, [r7]
	cmp r0, #0
	beq _0803C9EC
	ldr r0, _0803C9E4 @ =gUnk_Sio_085CA778
	ldr r1, [sp, #0x34]
	bl SpawnProcLocking
	adds r2, r0, #0
	adds r0, #0x32
	strb r4, [r0]
	adds r0, r5, r6
	adds r0, #0x2c
	ldrb r0, [r0]
	adds r1, r2, #0
	adds r1, #0x33
	strb r0, [r1]
	lsls r1, r4, #2
	adds r0, r6, #0
	adds r0, #0x14
	adds r3, r1, r0
	ldr r1, [r3]
	ldr r0, [r7]
	adds r1, r1, r0
	str r1, [r2, #0x38]
	ldr r0, _0803C9E8 @ =9999
	cmp r1, r0
	bls _0803C9A8
	str r0, [r2, #0x38]
_0803C9A8:
	ldr r0, [r2, #0x38]
	ldr r1, [r3]
	subs r0, r0, r1
	str r0, [r2, #0x34]
	adds r0, r2, #0
	adds r0, #0x40
	mov r1, sb
	strb r1, [r0]
	adds r0, #8
	movs r1, #4
	bl InitTextDb
	movs r0, #1
	add sl, r0
	b _0803C9F4
	.align 2, 0
_0803C9C8: .4byte Pal_SystemText
_0803C9CC: .4byte gFont_Unk_Sio_02001000
_0803C9D0: .4byte 0x06016800
_0803C9D4: .4byte gText_Unk_Sio_02001018
_0803C9D8: .4byte gUnk_Sio_085C98F4
_0803C9DC: .4byte gUnk_Sio_0810F3A0
_0803C9E0: .4byte 0x0203C984
_0803C9E4: .4byte gUnk_Sio_085CA778
_0803C9E8: .4byte 9999
_0803C9EC:
	mov r0, sp
	movs r1, #4
	bl InitTextDb
_0803C9F4:
	movs r1, #1
	add r8, r1
	mov r0, r8
	cmp r0, #3
	ble _0803C946
	mov r1, sl
	cmp r1, #0
	beq _0803CA28
	mov r0, sb
	cmp r0, #0
	beq _0803CA1E
	ldr r0, _0803CA24 @ =gUnk_Sio_085CA7B8
	ldr r1, [sp, #0x34]
	bl SpawnProcLocking
	ldr r1, [sp, #8]
	str r1, [r0, #0x2c]
	ldr r1, [sp, #0xc]
	str r1, [r0, #0x30]
	ldr r1, [sp, #0x10]
	str r1, [r0, #0x54]
_0803CA1E:
	movs r0, #1
	b _0803CA2A
	.align 2, 0
_0803CA24: .4byte gUnk_Sio_085CA7B8
_0803CA28:
	movs r0, #0
_0803CA2A:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_803CA3C
sub_803CA3C: @ 0x0803CA3C
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	bl sub_803C288
	ldr r2, _0803CA68 @ =gUnk_Sio_0810F408
	str r4, [sp]
	movs r0, #0x58
	movs r1, #0x3c
	movs r3, #1
	bl sub_803C8F0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803CA5E
	bl sub_803C2B0
_0803CA5E:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803CA68: .4byte gUnk_Sio_0810F408

	thumb_func_start sub_803CA6C
sub_803CA6C: @ 0x0803CA6C
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	bl sub_803C288
	ldr r2, _0803CA8C @ =gUnk_Sio_0810F408
	str r4, [sp]
	movs r0, #0x58
	movs r1, #0x3c
	movs r3, #0
	bl sub_803C8F0
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803CA8C: .4byte gUnk_Sio_0810F408

	thumb_func_start sub_803CA90
sub_803CA90: @ 0x0803CA90
	adds r1, r0, #0
	adds r1, #0x1c
	ldr r3, _0803CAA8 @ =0x03001418
	movs r2, #4
_0803CA98:
	ldrh r0, [r1]
	strh r0, [r3]
	adds r1, #2
	adds r3, #2
	subs r2, #1
	cmp r2, #0
	bge _0803CA98
	bx lr
	.align 2, 0
_0803CAA8: .4byte 0x03001418

	thumb_func_start sub_803CAAC
sub_803CAAC: @ 0x0803CAAC
	ldr r3, _0803CAC4 @ =0x03001418
	adds r1, r0, #0
	adds r1, #0x1c
	movs r2, #4
_0803CAB4:
	ldrh r0, [r3]
	strh r0, [r1]
	adds r3, #2
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0803CAB4
	bx lr
	.align 2, 0
_0803CAC4: .4byte 0x03001418

	thumb_func_start sub_803CAC8
sub_803CAC8: @ 0x0803CAC8
	push {lr}
	bl sub_803CD74
	bl RefreshUnitSprites
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_803CAD8
sub_803CAD8: @ 0x0803CAD8
	movs r1, #0
	ldr r3, _0803CAF4 @ =0x0203C984
	adds r2, r3, #0
	adds r2, #0xa
_0803CAE0:
	cmp r0, #2
	beq _0803CB0A
	cmp r0, #2
	bgt _0803CAF8
	cmp r0, #0
	beq _0803CB02
	cmp r0, #1
	beq _0803CB06
	b _0803CB14
	.align 2, 0
_0803CAF4: .4byte 0x0203C984
_0803CAF8:
	cmp r0, #3
	beq _0803CB0E
	cmp r0, #0xff
	beq _0803CB12
	b _0803CB14
_0803CB02:
	movs r1, #2
	b _0803CB14
_0803CB06:
	movs r1, #3
	b _0803CB14
_0803CB0A:
	movs r1, #1
	b _0803CB14
_0803CB0E:
	movs r1, #0
	b _0803CB14
_0803CB12:
	movs r1, #0xff
_0803CB14:
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803CB24
	cmp r1, #0xff
	beq _0803CB24
	adds r0, r1, #0
	b _0803CAE0
_0803CB24:
	strb r1, [r3, #1]
	bx lr

	thumb_func_start sub_803CB28
sub_803CB28: @ 0x0803CB28
	ldr r1, _0803CB38 @ =0x0300140C
	movs r0, #0
	strb r0, [r1]
	strb r0, [r1, #1]
	strb r0, [r1, #3]
	strb r0, [r1, #2]
	bx lr
	.align 2, 0
_0803CB38: .4byte 0x0300140C

	thumb_func_start sub_803CB3C
sub_803CB3C: @ 0x0803CB3C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r0, r3, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	bl sub_803CB28
	ldr r1, _0803CB78 @ =0x0300140C
	strb r4, [r1]
	strb r5, [r1, #1]
	strb r6, [r1, #2]
	ldr r0, [sp]
	strb r0, [r1, #3]
	ldr r0, _0803CB7C @ =0x0203C618
	ldrb r0, [r0]
	cmp r0, #2
	beq _0803CB80
	movs r0, #0
	b _0803CB8C
	.align 2, 0
_0803CB78: .4byte 0x0300140C
_0803CB7C: .4byte 0x0203C618
_0803CB80:
	adds r0, r1, #0
	movs r1, #4
	bl sub_8036208
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
_0803CB8C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_803CB94
sub_803CB94: @ 0x0803CB94
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	movs r1, #0
	ldr r3, _0803CBA8 @ =0x030013F0
_0803CB9C:
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, r2
	bne _0803CBAC
	adds r0, r1, #0
	b _0803CBB2
	.align 2, 0
_0803CBA8: .4byte 0x030013F0
_0803CBAC:
	adds r1, #1
	cmp r1, #0x13
	ble _0803CB9C
_0803CBB2:
	bx lr

	thumb_func_start sub_803CBB4
sub_803CBB4: @ 0x0803CBB4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r4, r0, #0
	str r1, [sp, #0x10]
	adds r5, r2, #0
	mov r8, r3
	ldr r0, [sp, #0x34]
	mov sb, r0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r1, _0803CCAC @ =gUnk_Sio_0810F41B
	mov r0, sp
	movs r2, #8
	bl memcpy
	add r7, sp, #8
	ldr r1, _0803CCB0 @ =gUnk_Sio_0810F423
	adds r0, r7, #0
	movs r2, #8
	bl memcpy
	adds r0, r4, #0
	bl sub_803CB94
	adds r4, r0, #0
	movs r1, #5
	bl Div
	lsls r6, r0, #1
	strb r4, [r5]
	ldr r0, _0803CCB4 @ =0x030013F0
	adds r4, r4, r0
	ldrb r0, [r4]
	bl GetUnit
	adds r5, r0, #0
	movs r1, #0x80
	lsls r1, r1, #2
	mov sl, r1
	mov r0, sl
	ldrh r2, [r5, #0xc]
	ands r0, r2
	cmp r0, #0
	bne _0803CC32
	adds r0, r5, #0
	bl StartMu
	ldr r1, _0803CCB8 @ =0x03001410
	ldr r3, [sp, #0x10]
	lsls r4, r3, #2
	adds r4, r4, r1
	str r0, [r4]
	bl DisableMuCamera
	ldr r0, [r4]
	mov r2, sp
	adds r1, r2, r6
	bl SetMuMoveScript
_0803CC32:
	movs r0, #1
	ldrh r3, [r5, #0xc]
	orrs r0, r3
	strh r0, [r5, #0xc]
	bl RefreshUnitSprites
	movs r0, #0xe
	ldrsb r0, [r5, r0]
	adds r3, r7, r6
	movs r1, #0
	ldrsb r1, [r3, r1]
	adds r0, r0, r1
	mov r1, r8
	str r0, [r1]
	movs r1, #0xf
	ldrsb r1, [r5, r1]
	adds r0, r6, #1
	adds r2, r7, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r1, r1, r0
	mov r0, sb
	str r1, [r0]
	mov r0, sl
	ldrh r1, [r5, #0xc]
	ands r0, r1
	cmp r0, #0
	beq _0803CC9A
	mov r1, r8
	ldr r0, [r1]
	strb r0, [r5, #0xe]
	mov r1, sb
	ldr r0, [r1]
	strb r0, [r5, #0xf]
	movs r1, #0
	ldrsb r1, [r3, r1]
	mov r3, r8
	ldr r0, [r3]
	subs r0, r0, r1
	str r0, [r3]
	movs r1, #0
	ldrsb r1, [r2, r1]
	mov r2, sb
	ldr r0, [r2]
	subs r0, r0, r1
	str r0, [r2]
	ldr r1, _0803CCB8 @ =0x03001410
	ldr r3, [sp, #0x10]
	lsls r0, r3, #2
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
_0803CC9A:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803CCAC: .4byte gUnk_Sio_0810F41B
_0803CCB0: .4byte gUnk_Sio_0810F423
_0803CCB4: .4byte 0x030013F0
_0803CCB8: .4byte 0x03001410

	thumb_func_start sub_803CCBC
sub_803CCBC: @ 0x0803CCBC
	ldr r1, _0803CCD0 @ =0x030013F0
	movs r2, #0
	adds r0, r1, #0
	adds r0, #0x13
_0803CCC4:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _0803CCC4
	bx lr
	.align 2, 0
_0803CCD0: .4byte 0x030013F0

	thumb_func_start sub_803CCD4
sub_803CCD4: @ 0x0803CCD4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r7, #0
_0803CCE2:
	ldr r0, _0803CD60 @ =gUnk_Sio_085C98F4
	ldr r0, [r0]
	ldrb r0, [r0, #6]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r7, r0
	ldr r1, _0803CD64 @ =gUnk_Sio_0810F390
	adds r0, r0, r1
	ldrb r4, [r0]
	adds r0, r4, #0
	bl sub_8035CB0
	lsls r0, r0, #0x18
	adds r1, r7, #1
	mov sb, r1
	cmp r0, #0
	beq _0803CD4A
	lsls r0, r4, #6
	adds r0, #1
	mov r8, r0
	movs r6, #0
	lsls r3, r7, #2
	ldr r0, _0803CD68 @ =gUnk_Sio_0810F3B0
	mov sl, r0
_0803CD14:
	adds r0, r3, r7
	adds r5, r0, r6
	ldr r0, _0803CD6C @ =gUnk_Sio_0810F42B
	adds r0, r6, r0
	ldrb r4, [r0]
	add r4, r8
	adds r0, r4, #0
	str r3, [sp]
	bl GetUnit
	adds r2, r0, #0
	ldr r0, [r2]
	ldr r3, [sp]
	cmp r0, #0
	beq _0803CD44
	ldr r0, _0803CD70 @ =0x030013F0
	adds r0, r5, r0
	strb r4, [r0]
	lsls r1, r5, #2
	add r1, sl
	ldrh r0, [r1]
	strb r0, [r2, #0xe]
	ldrh r0, [r1, #2]
	strb r0, [r2, #0xf]
_0803CD44:
	adds r6, #1
	cmp r6, #4
	ble _0803CD14
_0803CD4A:
	mov r7, sb
	cmp r7, #3
	ble _0803CCE2
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803CD60: .4byte gUnk_Sio_085C98F4
_0803CD64: .4byte gUnk_Sio_0810F390
_0803CD68: .4byte gUnk_Sio_0810F3B0
_0803CD6C: .4byte gUnk_Sio_0810F42B
_0803CD70: .4byte 0x030013F0

	thumb_func_start sub_803CD74
sub_803CD74: @ 0x0803CD74
	push {r4, lr}
	ldr r0, _0803CDCC @ =gMapUnit
	ldr r0, [r0]
	movs r1, #0
	bl MapFill
	ldr r0, _0803CDD0 @ =gMapFog
	ldr r0, [r0]
	movs r1, #1
	bl MapFill
	movs r4, #1
_0803CD8C:
	adds r0, r4, #0
	bl GetUnit
	adds r2, r0, #0
	cmp r2, #0
	beq _0803CDC0
	ldr r0, [r2]
	cmp r0, #0
	beq _0803CDC0
	movs r0, #1
	ldrh r1, [r2, #0xc]
	ands r0, r1
	cmp r0, #0
	bne _0803CDC0
	movs r1, #0xf
	ldrsb r1, [r2, r1]
	ldr r0, _0803CDCC @ =gMapUnit
	ldr r0, [r0]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrb r2, [r2, #0xe]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	ldr r0, [r1]
	adds r0, r0, r2
	strb r4, [r0]
_0803CDC0:
	adds r4, #1
	cmp r4, #0xc5
	ble _0803CD8C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803CDCC: .4byte gMapUnit
_0803CDD0: .4byte gMapFog

	thumb_func_start sub_803CDD4
sub_803CDD4: @ 0x0803CDD4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	movs r2, #0
	ldr r0, _0803CE4C @ =gUnk_Sio_0810F390
	mov sl, r0
_0803CDE6:
	ldr r0, _0803CE50 @ =gUnk_Sio_085C98F4
	ldr r0, [r0]
	ldrb r0, [r0, #6]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r2, r0
	add r0, sl
	ldrb r4, [r0]
	adds r0, r4, #0
	str r2, [sp]
	bl sub_8035CB0
	lsls r0, r0, #0x18
	ldr r2, [sp]
	adds r1, r2, #1
	mov sb, r1
	cmp r0, #0
	beq _0803CE66
	lsls r0, r4, #6
	adds r0, #1
	mov r8, r0
	movs r6, #0
	lsls r3, r2, #2
	ldr r7, _0803CE54 @ =0x030013F0
_0803CE18:
	adds r0, r3, r2
	adds r5, r0, r6
	ldr r0, _0803CE58 @ =gUnk_Sio_0810F42B
	adds r0, r6, r0
	ldrb r4, [r0]
	add r4, r8
	adds r0, r4, #0
	str r2, [sp]
	str r3, [sp, #4]
	bl GetUnit
	adds r1, r0, #0
	ldr r0, [r1]
	ldr r2, [sp]
	ldr r3, [sp, #4]
	cmp r0, #0
	beq _0803CE44
	movs r0, #5
	ldrh r1, [r1, #0xc]
	ands r0, r1
	cmp r0, #0
	beq _0803CE5C
_0803CE44:
	adds r1, r5, r7
	movs r0, #0
	strb r0, [r1]
	b _0803CE60
	.align 2, 0
_0803CE4C: .4byte gUnk_Sio_0810F390
_0803CE50: .4byte gUnk_Sio_085C98F4
_0803CE54: .4byte 0x030013F0
_0803CE58: .4byte gUnk_Sio_0810F42B
_0803CE5C:
	adds r0, r5, r7
	strb r4, [r0]
_0803CE60:
	adds r6, #1
	cmp r6, #4
	ble _0803CE18
_0803CE66:
	mov r2, sb
	cmp r2, #3
	ble _0803CDE6
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_803CE7C
sub_803CE7C: @ 0x0803CE7C
	push {r4, r5, lr}
	sub sp, #4
	mov r1, sp
	movs r0, #0
	strh r0, [r1]
	ldr r4, _0803CED0 @ =gBmSt
	ldr r2, _0803CED4 @ =0x01000020
	mov r0, sp
	adds r1, r4, #0
	bl CpuSet
	movs r0, #0x40
	movs r5, #0
	ldrb r1, [r4, #4]
	orrs r0, r1
	strb r0, [r4, #4]
	bl InitTraps
	ldr r4, _0803CED8 @ =gPlaySt
	movs r0, #0x27
	strb r0, [r4, #0xe]
	strh r5, [r4, #0x10]
	bl GetChapterInfo
	ldrb r0, [r0, #0xc]
	strb r0, [r4, #0xd]
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	bl GetChapterInfo
	ldrb r0, [r0, #0x11]
	strb r0, [r4, #0x15]
	movs r0, #0x27
	bl InitMapForChapter
	bl GetGameTime
	str r0, [r4, #4]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803CED0: .4byte gBmSt
_0803CED4: .4byte 0x01000020
_0803CED8: .4byte gPlaySt

	thumb_func_start sub_803CEDC
sub_803CEDC: @ 0x0803CEDC
	push {lr}
	bl sub_803CE7C
	bl sub_803CCBC
	bl sub_803CCD4
	ldr r0, _0803CF0C @ =gMapFog
	ldr r2, [r0]
	movs r1, #0
	ldr r0, _0803CF10 @ =gPlaySt
	ldrb r0, [r0, #0xd]
	cmp r0, #0
	bne _0803CEFA
	movs r1, #1
_0803CEFA:
	adds r0, r2, #0
	bl MapFill
	bl sub_803CD74
	bl RenderMap
	pop {r0}
	bx r0
	.align 2, 0
_0803CF0C: .4byte gMapFog
_0803CF10: .4byte gPlaySt

	thumb_func_start sub_803CF14
sub_803CF14: @ 0x0803CF14
	push {r4, lr}
	ldr r0, _0803CF4C @ =0x0203C984
	movs r1, #0
	movs r2, #3
	adds r0, #0xd
_0803CF1E:
	strb r1, [r0]
	subs r0, #1
	subs r2, #1
	cmp r2, #0
	bge _0803CF1E
	movs r2, #0
	ldr r4, _0803CF50 @ =0x030013F0
	ldr r3, _0803CF54 @ =0x0203C98E
_0803CF2E:
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803CF40
	lsrs r0, r0, #6
	adds r0, r0, r3
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
_0803CF40:
	adds r2, #1
	cmp r2, #0x13
	ble _0803CF2E
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803CF4C: .4byte 0x0203C984
_0803CF50: .4byte 0x030013F0
_0803CF54: .4byte 0x0203C98E

	thumb_func_start sub_803CF58
sub_803CF58: @ 0x0803CF58
	push {lr}
	ldr r0, _0803CF68 @ =gUnk_08109854
	ldr r1, _0803CF6C @ =0x06014800
	bl Decompress
	pop {r0}
	bx r0
	.align 2, 0
_0803CF68: .4byte gUnk_08109854
_0803CF6C: .4byte 0x06014800

	thumb_func_start sub_803CF70
sub_803CF70: @ 0x0803CF70
	push {lr}
	movs r0, #0
	bl InitBgs
	bl ApplySystemGraphics
	bl ApplyUnitSpritePalettes
	bl ForceSyncUnitSpriteSheet
	bl sub_803CF58
	bl InitSystemTextFont
	ldr r1, _0803CF98 @ =0x0203C984
	movs r0, #0xff
	strb r0, [r1, #3]
	pop {r0}
	bx r0
	.align 2, 0
_0803CF98: .4byte 0x0203C984

	thumb_func_start sub_803CF9C
sub_803CF9C: @ 0x0803CF9C
	push {r4, lr}
	ldr r4, _0803CFE0 @ =gPlaySt
	movs r3, #4
	rsbs r3, r3, #0
	ldrb r0, [r4, #0x1e]
	ands r3, r0
	movs r2, #0x10
	ldrb r1, [r4, #0x1c]
	orrs r2, r1
	movs r0, #0x61
	rsbs r0, r0, #0
	ands r2, r0
	movs r0, #0x40
	orrs r2, r0
	movs r0, #0x7f
	ands r2, r0
	subs r0, #0x81
	ldrb r1, [r4, #0x1d]
	ands r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #0xa
	ands r0, r1
	strb r0, [r4, #0x1d]
	ands r3, r1
	strb r3, [r4, #0x1e]
	movs r0, #1
	orrs r2, r0
	strb r2, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803CFE0: .4byte gPlaySt

	thumb_func_start sub_803CFE4
sub_803CFE4: @ 0x0803CFE4
	push {r4, r5, lr}
	movs r0, #0
	bl InitBgs
	bl sub_8036B40
	bl sub_803CEDC
	bl sub_803CF14
	ldr r4, _0803D084 @ =0x0203C984
	movs r5, #0
	strb r5, [r4, #9]
	ldr r0, _0803D088 @ =0x0203C618
	strb r5, [r0, #0xb]
	ldr r0, _0803D08C @ =gUnk_Sio_085CA7E0
	ldrb r1, [r4]
	adds r0, r1, r0
	ldrb r0, [r0]
	bl sub_803CAD8
	movs r0, #1
	strb r0, [r4, #0xe]
	strb r5, [r4, #2]
	strb r0, [r4, #3]
	movs r1, #0
	movs r0, #3
	adds r4, #0x20
_0803D01C:
	str r1, [r4]
	subs r4, #4
	subs r0, #1
	cmp r0, #0
	bge _0803D01C
	movs r4, #0
	ldr r0, _0803D090 @ =0x030013F0
	ldrb r0, [r0, #3]
	bl GetUnit
	ldr r2, _0803D094 @ =0x03001404
	movs r1, #0xe
	ldrsb r1, [r0, r1]
	lsls r1, r1, #4
	strh r1, [r2]
	movs r1, #0xf
	ldrsb r1, [r0, r1]
	lsls r1, r1, #4
	strh r1, [r2, #2]
	movs r2, #0xe
	ldrsb r2, [r0, r2]
	movs r1, #0xf
	ldrsb r1, [r0, r1]
	adds r0, r2, #0
	bl SetMapCursorPosition
	ldr r0, _0803D098 @ =gBmSt
	strh r4, [r0, #0xc]
	strh r4, [r0, #0xe]
	bl ApplySystemGraphics
	bl ApplyUnitSpritePalettes
	bl ResetUnitSprites
	bl RefreshUnitSprites
	bl sub_803CF58
	bl sub_803EA30
	ldr r0, _0803D09C @ =ProcScr_MapTask
	movs r1, #4
	bl SpawnProc
	bl StartBmVSync
	bl sub_803CF9C
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803D084: .4byte 0x0203C984
_0803D088: .4byte 0x0203C618
_0803D08C: .4byte gUnk_Sio_085CA7E0
_0803D090: .4byte 0x030013F0
_0803D094: .4byte 0x03001404
_0803D098: .4byte gBmSt
_0803D09C: .4byte ProcScr_MapTask

	thumb_func_start sub_803D0A0
sub_803D0A0: @ 0x0803D0A0
	push {r4, r5, lr}
	ldr r0, _0803D0E0 @ =0x030013F0
	ldr r1, _0803D0E4 @ =0x0203C984
	ldrb r1, [r1, #4]
	adds r0, r1, r0
	ldrb r0, [r0]
	bl GetUnit
	adds r4, r0, #0
	bl StartMu
	ldr r5, _0803D0E8 @ =0x03001410
	str r0, [r5]
	movs r1, #0xe
	ldrsb r1, [r4, r1]
	lsls r1, r1, #4
	movs r2, #0xf
	ldrsb r2, [r4, r2]
	subs r2, #1
	lsls r2, r2, #4
	bl SetMuScreenPosition
	ldr r0, [r5]
	bl DisableMuCamera
	ldr r0, [r5]
	movs r1, #3
	bl SetMuFacing
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803D0E0: .4byte 0x030013F0
_0803D0E4: .4byte 0x0203C984
_0803D0E8: .4byte 0x03001410

	thumb_func_start sub_803D0EC
sub_803D0EC: @ 0x0803D0EC
	push {lr}
	adds r2, r0, #0
	ldr r0, _0803D10C @ =gKeySt
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _0803D106
	adds r0, r2, #0
	bl Proc_Break
_0803D106:
	pop {r0}
	bx r0
	.align 2, 0
_0803D10C: .4byte gKeySt

	thumb_func_start sub_803D110
sub_803D110: @ 0x0803D110
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0803D124 @ =0x0203C618
	ldrb r0, [r0]
	cmp r0, #1
	beq _0803D128
	cmp r0, #2
	beq _0803D13C
	b _0803D168
	.align 2, 0
_0803D124: .4byte 0x0203C618
_0803D128:
	ldr r0, _0803D134 @ =gPlaySt
	ldrb r0, [r0, #0xf]
	cmp r0, #0
	beq _0803D14A
	ldr r0, _0803D138 @ =gUnk_Sio_085CAC14
	b _0803D14C
	.align 2, 0
_0803D134: .4byte gPlaySt
_0803D138: .4byte gUnk_Sio_085CAC14
_0803D13C:
	ldr r0, _0803D154 @ =gPlaySt
	ldr r1, _0803D158 @ =gUnk_Sio_085C98F4
	ldr r1, [r1]
	ldrb r0, [r0, #0xf]
	ldrb r1, [r1, #6]
	cmp r0, r1
	bne _0803D160
_0803D14A:
	ldr r0, _0803D15C @ =gUnk_Sio_085CA974
_0803D14C:
	adds r1, r4, #0
	bl SpawnProcLocking
	b _0803D168
	.align 2, 0
_0803D154: .4byte gPlaySt
_0803D158: .4byte gUnk_Sio_085C98F4
_0803D15C: .4byte gUnk_Sio_085CA974
_0803D160:
	ldr r0, _0803D174 @ =gUnk_Sio_085CAB24
	adds r1, r4, #0
	bl SpawnProcLocking
_0803D168:
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803D174: .4byte gUnk_Sio_085CAB24

	thumb_func_start sub_803D178
sub_803D178: @ 0x0803D178
	push {r4, lr}
	adds r3, r0, #0
	movs r1, #0
	ldr r0, _0803D190 @ =0x0203C618
	ldrb r2, [r0]
	cmp r2, #1
	bne _0803D194
	ldrb r0, [r0, #0xb]
	cmp r0, #1
	bne _0803D1A4
	b _0803D19A
	.align 2, 0
_0803D190: .4byte 0x0203C618
_0803D194:
	ldrb r0, [r0, #0xb]
	cmp r0, #2
	bne _0803D1A4
_0803D19A:
	adds r0, r3, #0
	movs r1, #3
	bl Proc_Goto
	b _0803D1FE
_0803D1A4:
	ldr r0, _0803D1B8 @ =0x0203C984
	ldrb r2, [r0, #1]
	adds r0, r2, #0
	cmp r0, #0xff
	bne _0803D1BC
	adds r0, r3, #0
	movs r1, #2
	bl Proc_Goto
	b _0803D1FE
	.align 2, 0
_0803D1B8: .4byte 0x0203C984
_0803D1BC:
	ldr r0, _0803D1C4 @ =gPlaySt
	strb r2, [r0, #0xf]
	ldr r2, _0803D1C8 @ =0x030013F0
	b _0803D1CE
	.align 2, 0
_0803D1C4: .4byte gPlaySt
_0803D1C8: .4byte 0x030013F0
_0803D1CC:
	adds r1, #1
_0803D1CE:
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803D1CC
	ldr r4, _0803D204 @ =0x0203C984
	strb r1, [r4, #2]
	adds r0, r1, #1
	strb r0, [r4, #3]
	bl ApplySystemObjectsGraphics
	movs r0, #0
	adds r4, #0x2c
	movs r1, #3
_0803D1E8:
	str r0, [r4, #4]
	strb r0, [r4]
	adds r4, #8
	subs r1, #1
	cmp r1, #0
	bge _0803D1E8
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #9
	bl DebugInitObj
_0803D1FE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803D204: .4byte 0x0203C984

	thumb_func_start sub_803D208
sub_803D208: @ 0x0803D208
	push {r4, r5, r6, r7, lr}
	movs r5, #4
	ldr r3, _0803D260 @ =0x0203C984
	ldr r0, _0803D264 @ =gUnk_Sio_085C98F4
	ldr r0, [r0]
	ldrb r0, [r0, #6]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r2, r3, #0
	adds r2, #0x14
	adds r0, r0, r2
	ldr r7, [r0]
	ldr r1, _0803D268 @ =0x0203C618
	adds r1, #0xec
	movs r0, #2
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _0803D270
	movs r4, #0
	adds r5, r3, #0
	adds r5, #0xf
_0803D236:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl sub_8035CB0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803D254
	ldr r0, _0803D264 @ =gUnk_Sio_085C98F4
	ldr r0, [r0]
	movs r1, #6
	ldrsb r1, [r0, r1]
	adds r0, r4, r5
	ldrb r0, [r0]
	cmp r1, r0
	beq _0803D26C
_0803D254:
	adds r4, #1
	cmp r4, #3
	ble _0803D236
	movs r5, #3
	b _0803D2A0
	.align 2, 0
_0803D260: .4byte 0x0203C984
_0803D264: .4byte gUnk_Sio_085C98F4
_0803D268: .4byte 0x0203C618
_0803D26C:
	adds r0, r4, #0
	b _0803D2A2
_0803D270:
	movs r4, #0
	adds r6, r2, #0
_0803D274:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl sub_8035CB0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803D296
	ldr r0, _0803D2A8 @ =gUnk_Sio_085C98F4
	ldr r0, [r0]
	ldrb r0, [r0, #6]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r4
	beq _0803D296
	ldr r0, [r6]
	cmp r7, r0
	bls _0803D298
_0803D296:
	subs r5, #1
_0803D298:
	adds r6, #4
	adds r4, #1
	cmp r4, #3
	ble _0803D274
_0803D2A0:
	adds r0, r5, #0
_0803D2A2:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0803D2A8: .4byte gUnk_Sio_085C98F4

	thumb_func_start sub_803D2AC
sub_803D2AC: @ 0x0803D2AC
	push {lr}
	ldr r0, _0803D2C8 @ =ProcScr_MapTask
	bl Proc_EndEach
	bl sub_803EA44
	bl EndBmVSync
	movs r0, #1
	bl FadeBgmOut
	pop {r0}
	bx r0
	.align 2, 0
_0803D2C8: .4byte ProcScr_MapTask

	thumb_func_start sub_803D2CC
sub_803D2CC: @ 0x0803D2CC
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov ip, r1
	ldr r1, _0803D2FC @ =0x0203C984
	ldrb r2, [r1, #2]
	adds r5, r2, #0
	strb r2, [r1, #3]
	movs r0, #0xf0
	ands r0, r3
	adds r7, r1, #0
	cmp r0, #0
	beq _0803D3BA
	lsls r4, r2, #2
	movs r0, #0x40
	ands r0, r3
	cmp r0, #0
	beq _0803D304
	ldr r0, _0803D300 @ =gUnk_Sio_085CA7E4
	adds r0, r4, r0
	b _0803D33A
	.align 2, 0
_0803D2FC: .4byte 0x0203C984
_0803D300: .4byte gUnk_Sio_085CA7E4
_0803D304:
	movs r0, #0x80
	ands r0, r3
	cmp r0, #0
	beq _0803D318
	ldr r1, _0803D314 @ =gUnk_Sio_085CA7E4
	adds r0, r4, #1
	b _0803D338
	.align 2, 0
_0803D314: .4byte gUnk_Sio_085CA7E4
_0803D318:
	movs r0, #0x20
	ands r0, r3
	cmp r0, #0
	beq _0803D32C
	ldr r1, _0803D328 @ =gUnk_Sio_085CA7E4
	adds r0, r4, #2
	b _0803D338
	.align 2, 0
_0803D328: .4byte gUnk_Sio_085CA7E4
_0803D32C:
	movs r0, #0x10
	ands r0, r3
	cmp r0, #0
	beq _0803D33C
	ldr r1, _0803D398 @ =gUnk_Sio_085CA7E4
	adds r0, r4, #3
_0803D338:
	adds r0, r0, r1
_0803D33A:
	ldrb r2, [r0]
_0803D33C:
	subs r5, r2, r5
	ldrb r0, [r7, #3]
	cmp r0, #0
	bne _0803D350
	movs r0, #0x20
	ands r0, r3
	cmp r0, #0
	beq _0803D350
	movs r5, #1
	rsbs r5, r5, #0
_0803D350:
	ldrb r0, [r7, #3]
	cmp r0, #0x13
	bne _0803D360
	movs r0, #0x80
	ands r0, r3
	cmp r0, #0
	beq _0803D360
	movs r5, #1
_0803D360:
	ldr r6, _0803D39C @ =0x030013F0
	mov r0, ip
	lsls r4, r0, #0x18
_0803D366:
	adds r0, r2, r6
	ldrb r0, [r0]
	lsls r1, r0, #0x18
	cmp r1, #0
	beq _0803D384
	cmp r4, #0
	beq _0803D3B8
	lsrs r1, r1, #0x1e
	ldr r0, _0803D3A0 @ =gUnk_Sio_085C98F4
	ldr r0, [r0]
	ldrb r0, [r0, #6]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bne _0803D3B8
_0803D384:
	cmp r5, #0
	bge _0803D3A4
	subs r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xff
	bne _0803D366
	movs r2, #0x13
	b _0803D366
	.align 2, 0
_0803D398: .4byte gUnk_Sio_085CA7E4
_0803D39C: .4byte 0x030013F0
_0803D3A0: .4byte gUnk_Sio_085C98F4
_0803D3A4:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r0, r2, #0
	movs r1, #0x14
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	b _0803D366
_0803D3B8:
	strb r2, [r7, #2]
_0803D3BA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_803D3C0
sub_803D3C0: @ 0x0803D3C0
	push {r4, r5, r6, r7, lr}
	ldr r6, _0803D42C @ =0x0203C984
	ldrb r0, [r6, #2]
	ldrb r1, [r6, #3]
	cmp r0, r1
	beq _0803D426
	ldr r7, _0803D430 @ =0x030013F0
	adds r0, r1, r7
	ldrb r0, [r0]
	bl GetUnit
	adds r5, r0, #0
	ldrb r1, [r6, #2]
	adds r0, r1, r7
	ldrb r0, [r0]
	bl GetUnit
	adds r4, r0, #0
	cmp r5, #0
	beq _0803D3F2
	bl EndAllMus
	adds r0, r5, #0
	bl ShowUnitSprite
_0803D3F2:
	cmp r4, #0
	beq _0803D426
	movs r0, #2
	ldrh r1, [r4, #0xc]
	ands r0, r1
	cmp r0, #0
	bne _0803D426
	ldrb r6, [r6, #2]
	adds r0, r6, r7
	ldrb r0, [r0]
	lsrs r1, r0, #6
	ldr r0, _0803D434 @ =gUnk_Sio_085C98F4
	ldr r0, [r0]
	ldrb r0, [r0, #6]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bne _0803D426
	adds r0, r4, #0
	bl StartMu
	bl DisableMuCamera
	adds r0, r4, #0
	bl HideUnitSprite
_0803D426:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803D42C: .4byte 0x0203C984
_0803D430: .4byte 0x030013F0
_0803D434: .4byte gUnk_Sio_085C98F4

	thumb_func_start sub_803D438
sub_803D438: @ 0x0803D438
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
_0803D43E:
	lsls r1, r5, #1
	adds r0, r6, #0
	adds r0, #0x1c
	adds r0, r0, r1
	ldrh r4, [r0]
	adds r0, r4, #0
	bl GetItemAttributes
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _0803D46A
	adds r0, r6, #0
	adds r1, r4, #0
	bl CanUnitUseWeapon
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _0803D46A
	movs r0, #1
	b _0803D472
_0803D46A:
	adds r5, #1
	cmp r5, #4
	ble _0803D43E
	movs r0, #0
_0803D472:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start sub_803D478
sub_803D478: @ 0x0803D478
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, _0803D4AC @ =0x0203C984
	ldr r1, _0803D4B0 @ =0x0203C618
	adds r1, #0xa0
	ldrb r3, [r1]
	lsls r0, r3, #1
	adds r0, r0, r3
	ldrb r2, [r2, #9]
	cmp r2, r0
	blt _0803D4A0
	bl sub_803C2B0
	ldr r0, _0803D4B4 @ =gUnk_Sio_085CA958
	bl StartEvent
	adds r0, r4, #0
	movs r1, #3
	bl Proc_Goto
_0803D4A0:
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803D4AC: .4byte 0x0203C984
_0803D4B0: .4byte 0x0203C618
_0803D4B4: .4byte gUnk_Sio_085CA958

	thumb_func_start sub_803D4B8
sub_803D4B8: @ 0x0803D4B8
	push {r4, lr}
	adds r4, r0, #0
	bl sub_8035D4C
	cmp r0, #7
	bgt _0803D4CA
	adds r0, r4, #0
	bl Proc_Break
_0803D4CA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_803D4D0
sub_803D4D0: @ 0x0803D4D0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, _0803D5B0 @ =gUnk_Sio_0810F430
	mov r0, sp
	movs r2, #2
	bl memcpy
	ldr r0, _0803D5B4 @ =0x0203C984
	mov r8, r0
	ldrb r1, [r0, #2]
	mov sb, r1
	bl sub_803D3C0
	ldr r4, _0803D5B8 @ =gKeySt
	ldr r0, [r4]
	ldrh r0, [r0, #6]
	movs r1, #0
	bl sub_803D2CC
	ldr r7, _0803D5BC @ =gActiveUnitId
	ldr r0, _0803D5C0 @ =0x030013F0
	mov r2, r8
	ldrb r2, [r2, #2]
	adds r0, r2, r0
	ldrb r0, [r0]
	strb r0, [r7]
	ldrb r0, [r7]
	bl GetUnit
	adds r2, r0, #0
	ldr r6, _0803D5C4 @ =gActiveUnit
	str r2, [r6]
	ldr r1, [r4]
	movs r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _0803D5E4
	ldrb r0, [r7]
	lsrs r1, r0, #6
	ldr r0, _0803D5C8 @ =gUnk_Sio_085C98F4
	ldr r0, [r0]
	ldrb r0, [r0, #6]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bne _0803D5D4
	adds r0, r2, #0
	bl sub_803D438
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _0803D5D4
	ldr r0, _0803D5CC @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt _0803D554
	movs r0, #0x69
	bl m4aSongNumStart
_0803D554:
	bl EndAllMus
	ldr r0, [r6]
	bl StartMu
	ldr r4, _0803D5D0 @ =0x03001410
	str r0, [r4]
	bl DisableMuCamera
	ldr r0, [r4]
	mov r1, sp
	bl SetMuMoveScript
	ldr r1, [r6]
	movs r0, #0xe
	ldrsb r0, [r1, r0]
	str r0, [r5, #0x2c]
	movs r0, #0xf
	ldrsb r0, [r1, r0]
	subs r0, #1
	str r0, [r5, #0x30]
	movs r0, #1
	ldrh r2, [r1, #0xc]
	orrs r0, r2
	strh r0, [r1, #0xc]
	bl sub_803CAC8
	mov r1, r8
	ldrb r0, [r1, #2]
	strb r0, [r1, #4]
	movs r0, #0x40
	movs r1, #1
	bl sub_803D2CC
	ldrb r1, [r7]
	movs r0, #1
	movs r2, #0
	movs r3, #0
	bl sub_803CB3C
	adds r0, r5, #0
	movs r1, #5
	bl Proc_Goto
	b _0803D6BC
	.align 2, 0
_0803D5B0: .4byte gUnk_Sio_0810F430
_0803D5B4: .4byte 0x0203C984
_0803D5B8: .4byte gKeySt
_0803D5BC: .4byte gActiveUnitId
_0803D5C0: .4byte 0x030013F0
_0803D5C4: .4byte gActiveUnit
_0803D5C8: .4byte gUnk_Sio_085C98F4
_0803D5CC: .4byte gPlaySt
_0803D5D0: .4byte 0x03001410
_0803D5D4:
	ldr r0, _0803D614 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt _0803D5E4
	movs r0, #0x6c
	bl m4aSongNumStart
_0803D5E4:
	ldr r2, _0803D618 @ =gKeySt
	ldr r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _0803D620
	ldr r0, _0803D61C @ =gActiveUnit
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ldrh r1, [r1, #0xc]
	ands r0, r1
	cmp r0, #0
	bne _0803D620
	bl EndAllMus
	adds r0, r5, #0
	movs r1, #4
	bl Proc_Goto
	b _0803D6BC
	.align 2, 0
_0803D614: .4byte gPlaySt
_0803D618: .4byte gKeySt
_0803D61C: .4byte gActiveUnit
_0803D620:
	ldr r1, [r2]
	movs r0, #8
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _0803D658
	bl sub_803C2B0
	ldr r0, _0803D650 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt _0803D646
	movs r0, #0x68
	bl m4aSongNumStart
	ldr r0, _0803D654 @ =gUnk_Sio_085CA93C
	bl StartEvent
_0803D646:
	adds r0, r5, #0
	movs r1, #2
	bl Proc_Goto
	b _0803D6BC
	.align 2, 0
_0803D650: .4byte gPlaySt
_0803D654: .4byte gUnk_Sio_085CA93C
_0803D658:
	ldr r0, _0803D6CC @ =gActiveUnit
	ldr r1, [r0]
	movs r0, #0xe
	ldrsb r0, [r1, r0]
	lsls r5, r0, #4
	ldrb r1, [r1, #0xf]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	lsls r4, r1, #4
	bl SetMapCursorPosition
	bl GetGameTime
	subs r0, #1
	ldr r6, _0803D6D0 @ =0x03001408
	ldr r1, [r6]
	cmp r0, r1
	bne _0803D68E
	ldr r0, _0803D6D4 @ =0x03001404
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r1, r5, r1
	asrs r5, r1, #1
	movs r1, #2
	ldrsh r0, [r0, r1]
	adds r0, r4, r0
	asrs r4, r0, #1
_0803D68E:
	ldr r0, _0803D6D4 @ =0x03001404
	strh r5, [r0]
	strh r4, [r0, #2]
	bl GetGameTime
	str r0, [r6]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl PutMapCursor
	ldr r0, _0803D6D8 @ =0x0203C984
	ldrb r0, [r0, #2]
	cmp sb, r0
	beq _0803D6BC
	ldr r0, _0803D6DC @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt _0803D6BC
	movs r0, #0x65
	bl m4aSongNumStart
_0803D6BC:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803D6CC: .4byte gActiveUnit
_0803D6D0: .4byte 0x03001408
_0803D6D4: .4byte 0x03001404
_0803D6D8: .4byte 0x0203C984
_0803D6DC: .4byte gPlaySt

	thumb_func_start sub_803D6E0
sub_803D6E0: @ 0x0803D6E0
	push {lr}
	bl sub_803C288
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_803D6EC
sub_803D6EC: @ 0x0803D6EC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov r8, r0
	ldr r6, _0803D7C4 @ =0x0203C984
	ldrb r0, [r6, #2]
	str r0, [sp, #4]
	ldr r1, _0803D7C8 @ =gKeySt
	ldr r0, [r1]
	ldrh r0, [r0, #6]
	movs r1, #1
	bl sub_803D2CC
	ldr r2, _0803D7CC @ =gActiveUnitId
	mov sl, r2
	ldr r0, _0803D7D0 @ =0x030013F0
	mov sb, r0
	ldrb r0, [r6, #2]
	add r0, sb
	ldrb r0, [r0]
	strb r0, [r2]
	ldrb r0, [r2]
	bl GetUnit
	ldr r1, _0803D7D4 @ =gActiveUnit
	str r0, [r1]
	movs r2, #0xe
	ldrsb r2, [r0, r2]
	lsls r5, r2, #4
	movs r1, #0xf
	ldrsb r1, [r0, r1]
	lsls r4, r1, #4
	adds r0, r2, #0
	bl SetMapCursorPosition
	bl GetGameTime
	subs r0, #1
	ldr r7, _0803D7D8 @ =0x03001408
	ldr r1, [r7]
	cmp r0, r1
	bne _0803D758
	ldr r0, _0803D7DC @ =0x03001404
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r1, r5, r1
	asrs r5, r1, #1
	movs r1, #2
	ldrsh r0, [r0, r1]
	adds r0, r4, r0
	asrs r4, r0, #1
_0803D758:
	ldr r0, _0803D7DC @ =0x03001404
	strh r5, [r0]
	strh r4, [r0, #2]
	bl GetGameTime
	str r0, [r7]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl PutMapCursor
	ldr r2, _0803D7C8 @ =gKeySt
	ldr r0, [r2]
	ldrh r1, [r0, #8]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803D7E4
	ldr r0, _0803D7E0 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt _0803D78C
	movs r0, #0x69
	bl m4aSongNumStart
_0803D78C:
	ldrb r0, [r6, #2]
	add r0, sb
	ldrb r0, [r0]
	adds r2, r6, #5
	mov r3, r8
	adds r3, #0x34
	mov r1, r8
	adds r1, #0x38
	str r1, [sp]
	movs r1, #1
	bl sub_803CBB4
	ldrb r0, [r6, #5]
	add r0, sb
	ldrb r1, [r0]
	mov r0, sl
	ldrb r2, [r0]
	movs r0, #3
	movs r3, #0
	bl sub_803CB3C
	bl sub_803C2B0
	mov r0, r8
	movs r1, #7
	bl Proc_Goto
	b _0803D892
	.align 2, 0
_0803D7C4: .4byte 0x0203C984
_0803D7C8: .4byte gKeySt
_0803D7CC: .4byte gActiveUnitId
_0803D7D0: .4byte 0x030013F0
_0803D7D4: .4byte gActiveUnit
_0803D7D8: .4byte 0x03001408
_0803D7DC: .4byte 0x03001404
_0803D7E0: .4byte gPlaySt
_0803D7E4:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803D84C
	ldr r0, _0803D840 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt _0803D7FC
	movs r0, #0x6b
	bl m4aSongNumStart
_0803D7FC:
	ldr r0, _0803D844 @ =0x03001410
	ldr r0, [r0]
	bl EndMu
	ldrb r0, [r6, #4]
	add r0, sb
	ldrb r0, [r0]
	bl GetUnit
	ldr r1, _0803D848 @ =0x0000FFFE
	ldrh r2, [r0, #0xc]
	ands r1, r2
	strh r1, [r0, #0xc]
	bl sub_803CAC8
	ldrb r0, [r6, #4]
	strb r0, [r6, #2]
	adds r0, #1
	strb r0, [r6, #3]
	mov r0, sl
	ldrb r1, [r0]
	ldrb r0, [r6, #4]
	add r0, sb
	ldrb r2, [r0]
	movs r0, #2
	movs r3, #0
	bl sub_803CB3C
	mov r0, r8
	movs r1, #1
	bl Proc_Goto
	b _0803D892
	.align 2, 0
_0803D840: .4byte gPlaySt
_0803D844: .4byte 0x03001410
_0803D848: .4byte 0x0000FFFE
_0803D84C:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803D878
	ldr r2, _0803D874 @ =gActiveUnit
	ldr r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #2
	ldrh r1, [r1, #0xc]
	ands r0, r1
	cmp r0, #0
	bne _0803D878
	bl EndAllMus
	mov r0, r8
	movs r1, #6
	bl Proc_Goto
	b _0803D892
	.align 2, 0
_0803D874: .4byte gActiveUnit
_0803D878:
	ldr r0, _0803D8A4 @ =0x0203C984
	ldr r1, [sp, #4]
	ldrb r0, [r0, #2]
	cmp r1, r0
	beq _0803D892
	ldr r0, _0803D8A8 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt _0803D892
	movs r0, #0x65
	bl m4aSongNumStart
_0803D892:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803D8A4: .4byte 0x0203C984
_0803D8A8: .4byte gPlaySt

	thumb_func_start sub_803D8AC
sub_803D8AC: @ 0x0803D8AC
	push {r4, lr}
	adds r4, r0, #0
	bl ResetTextFont
	ldr r1, _0803D8EC @ =0x0203C984
	movs r0, #0xff
	strb r0, [r1, #6]
	ldr r0, _0803D8F0 @ =0x030013F0
	ldrb r1, [r1, #4]
	adds r0, r1, r0
	ldrb r0, [r0]
	bl GetUnit
	ldr r1, _0803D8F4 @ =gActiveUnit
	str r0, [r1]
	bl sub_803CA90
	bl GetGameLock
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, #0x64
	strh r0, [r4]
	movs r0, #4
	bl ApplyIconPalettes
	ldr r0, _0803D8F8 @ =gUnk_Sio_085CB384
	bl sub_8041834
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803D8EC: .4byte 0x0203C984
_0803D8F0: .4byte 0x030013F0
_0803D8F4: .4byte gActiveUnit
_0803D8F8: .4byte gUnk_Sio_085CB384

	thumb_func_start sub_803D8FC
sub_803D8FC: @ 0x0803D8FC
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, #0x64
	movs r1, #0
	ldrsh r4, [r0, r1]
	bl GetGameLock
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r4, r0
	bne _0803D92E
	ldr r0, _0803D934 @ =0x0203C984
	ldrb r0, [r0, #6]
	cmp r0, #0
	bne _0803D928
	ldr r0, _0803D938 @ =gActiveUnit
	ldr r0, [r0]
	bl sub_803CAAC
	adds r0, r5, #0
	bl Proc_End
_0803D928:
	adds r0, r5, #0
	bl Proc_Break
_0803D92E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803D934: .4byte 0x0203C984
_0803D938: .4byte gActiveUnit

	thumb_func_start sub_803D93C
sub_803D93C: @ 0x0803D93C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _0803D974 @ =gActiveUnit
	ldr r0, [r0]
	ldr r6, _0803D978 @ =0x0203C984
	ldrb r2, [r6, #7]
	lsls r1, r2, #1
	adds r0, #0x1c
	adds r0, r0, r1
	ldrh r5, [r0]
	bl GetGameLock
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, #0x64
	strh r0, [r4]
	adds r0, r5, #0
	bl GetItemMinRange
	cmp r0, #1
	bne _0803D97C
	adds r0, r5, #0
	bl GetItemMaxRange
	cmp r0, #1
	bne _0803D97C
	strb r0, [r6, #6]
	b _0803D9FE
	.align 2, 0
_0803D974: .4byte gActiveUnit
_0803D978: .4byte 0x0203C984
_0803D97C:
	adds r0, r5, #0
	bl GetItemMinRange
	cmp r0, #2
	bne _0803D99C
	adds r0, r5, #0
	bl GetItemMaxRange
	adds r1, r0, #0
	cmp r1, #2
	bne _0803D99C
	ldr r0, _0803D998 @ =0x0203C984
	strb r1, [r0, #6]
	b _0803D9FE
	.align 2, 0
_0803D998: .4byte 0x0203C984
_0803D99C:
	adds r0, r5, #0
	bl GetItemMinRange
	adds r4, r0, #0
	cmp r4, #2
	bne _0803D9BC
	adds r0, r5, #0
	bl GetItemMaxRange
	cmp r0, #3
	bne _0803D9BC
	ldr r0, _0803D9B8 @ =0x0203C984
	strb r4, [r0, #6]
	b _0803D9FE
	.align 2, 0
_0803D9B8: .4byte 0x0203C984
_0803D9BC:
	ldr r0, _0803D9DC @ =0x030013F0
	ldr r4, _0803D9E0 @ =0x0203C984
	ldrb r1, [r4, #5]
	adds r0, r1, r0
	ldrb r0, [r0]
	bl GetUnit
	bl GetUnitEquippedWeapon
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne _0803D9E4
	movs r0, #1
	strb r0, [r4, #6]
	b _0803D9FE
	.align 2, 0
_0803D9DC: .4byte 0x030013F0
_0803D9E0: .4byte 0x0203C984
_0803D9E4:
	adds r0, r5, #0
	bl GetItemMinRange
	cmp r0, #1
	ble _0803D9F4
	movs r0, #2
	strb r0, [r4, #6]
	b _0803D9FE
_0803D9F4:
	movs r0, #1
	strb r0, [r4, #6]
	movs r0, #4
	bl ApplyIconPalettes
_0803D9FE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_803DA04
sub_803DA04: @ 0x0803DA04
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0
	mov sl, r0
	ldr r4, _0803DA60 @ =0x030013F0
	ldr r7, _0803DA64 @ =0x0203C984
	ldrb r1, [r7, #4]
	adds r0, r1, r4
	ldrb r0, [r0]
	bl GetUnit
	mov sb, r0
	ldrb r0, [r7, #5]
	adds r4, r0, r4
	ldrb r0, [r4]
	bl GetUnit
	adds r5, r0, #0
	adds r0, r6, #0
	adds r0, #0x64
	movs r1, #0
	ldrsh r4, [r0, r1]
	bl GetGameLock
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r4, r0
	bne _0803DAD8
	ldrb r0, [r7, #6]
	cmp r0, #0
	bne _0803DA6C
	ldr r0, _0803DA68 @ =gActiveUnit
	ldr r0, [r0]
	bl sub_803CAAC
	adds r0, r6, #0
	movs r1, #0
	bl Proc_Goto
	b _0803DAD8
	.align 2, 0
_0803DA60: .4byte 0x030013F0
_0803DA64: .4byte 0x0203C984
_0803DA68: .4byte gActiveUnit
_0803DA6C:
	ldr r0, _0803DAC4 @ =gActiveUnit
	mov r8, r0
	ldr r0, [r0]
	ldrb r1, [r7, #7]
	bl UnitEquipItemSlot
	movs r0, #0x80
	lsls r0, r0, #2
	ldrh r1, [r5, #0xc]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _0803DAC8
	adds r0, r6, #0
	bl StartBattlePreview
	ldrb r7, [r7, #6]
	cmp r7, #2
	bne _0803DA98
	movs r0, #1
	mov sl, r0
_0803DA98:
	movs r2, #0xe
	ldrsb r2, [r5, r2]
	add r2, sl
	movs r3, #0xf
	ldrsb r3, [r5, r3]
	adds r3, #1
	str r4, [sp]
	mov r0, sb
	adds r1, r5, #0
	bl BattleGenerateSimulation
	bl UpdateBattlePreviewContents
	mov r1, r8
	ldr r0, [r1]
	bl sub_803CAAC
	adds r0, r6, #0
	bl Proc_Break
	b _0803DAD8
	.align 2, 0
_0803DAC4: .4byte gActiveUnit
_0803DAC8:
	mov r1, r8
	ldr r0, [r1]
	bl sub_803CAAC
	adds r0, r6, #0
	movs r1, #1
	bl Proc_Goto
_0803DAD8:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_803DAE8
sub_803DAE8: @ 0x0803DAE8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0803DB18 @ =gKeySt
	ldr r0, [r0]
	ldrh r1, [r0, #8]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803DB20
	ldr r0, _0803DB1C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt _0803DB0A
	movs r0, #0x6a
	bl m4aSongNumStart
_0803DB0A:
	bl CloseBattlePreview
	adds r0, r4, #0
	bl Proc_Break
	b _0803DB44
	.align 2, 0
_0803DB18: .4byte gKeySt
_0803DB1C: .4byte gPlaySt
_0803DB20:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0803DB44
	ldr r0, _0803DB4C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt _0803DB38
	movs r0, #0x6b
	bl m4aSongNumStart
_0803DB38:
	bl CloseBattlePreview
	adds r0, r4, #0
	movs r1, #0
	bl Proc_Goto
_0803DB44:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803DB4C: .4byte gPlaySt

	thumb_func_start sub_803DB50
sub_803DB50: @ 0x0803DB50
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0803DB68 @ =gUnk_Sio_085CA834
	adds r1, r4, #0
	bl SpawnProcLocking
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803DB68: .4byte gUnk_Sio_085CA834

	thumb_func_start sub_803DB6C
sub_803DB6C: @ 0x0803DB6C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _0803DBA0 @ =0x030013F0
	ldr r6, _0803DBA4 @ =0x0203C984
	ldrb r1, [r6, #5]
	adds r0, r1, r0
	ldrb r0, [r0]
	bl GetUnit
	adds r4, r0, #0
	bl ClearBg0Bg1
	ldrb r0, [r6, #6]
	cmp r0, #0
	bne _0803DBF8
	movs r0, #0x80
	lsls r0, r0, #2
	ldrh r1, [r4, #0xc]
	ands r0, r1
	cmp r0, #0
	bne _0803DBAC
	ldr r0, _0803DBA8 @ =0x03001410
	ldr r0, [r0, #4]
	bl EndMu
	b _0803DBB4
	.align 2, 0
_0803DBA0: .4byte 0x030013F0
_0803DBA4: .4byte 0x0203C984
_0803DBA8: .4byte 0x03001410
_0803DBAC:
	ldr r0, [r5, #0x34]
	strb r0, [r4, #0xe]
	ldr r0, [r5, #0x38]
	strb r0, [r4, #0xf]
_0803DBB4:
	ldr r0, _0803DBEC @ =0x0000FFFE
	ldrh r1, [r4, #0xc]
	ands r0, r1
	strh r0, [r4, #0xc]
	bl RefreshUnitSprites
	ldr r1, _0803DBF0 @ =0x0203C984
	ldrb r0, [r1, #5]
	strb r0, [r1, #2]
	adds r0, #1
	strb r0, [r1, #3]
	ldr r0, _0803DBF4 @ =0x030013F0
	ldrb r1, [r1, #5]
	adds r0, r1, r0
	ldrb r2, [r0]
	movs r0, #4
	movs r1, #0
	movs r3, #0
	bl sub_803CB3C
	adds r0, r5, #0
	bl sub_803D6E0
	adds r0, r5, #0
	movs r1, #5
	bl Proc_Goto
	b _0803DC2E
	.align 2, 0
_0803DBEC: .4byte 0x0000FFFE
_0803DBF0: .4byte 0x0203C984
_0803DBF4: .4byte 0x030013F0
_0803DBF8:
	movs r0, #0x80
	lsls r0, r0, #2
	ldrh r1, [r4, #0xc]
	ands r0, r1
	cmp r0, #0
	beq _0803DC22
	adds r0, r4, #0
	bl StartMu
	ldr r1, _0803DC34 @ =0x03001410
	str r0, [r1, #4]
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	str r0, [r5, #0x34]
	movs r0, #0xf
	ldrsb r0, [r4, r0]
	str r0, [r5, #0x38]
	ldr r0, _0803DC38 @ =0x0000FDFF
	ldrh r1, [r4, #0xc]
	ands r0, r1
	strh r0, [r4, #0xc]
_0803DC22:
	ldrb r2, [r6, #6]
	ldrb r3, [r6, #7]
	movs r0, #5
	movs r1, #0
	bl sub_803CB3C
_0803DC2E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803DC34: .4byte 0x03001410
_0803DC38: .4byte 0x0000FDFF

	thumb_func_start sub_803DC3C
sub_803DC3C: @ 0x0803DC3C
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0xc
	adds r6, r0, #0
	ldr r4, _0803DCB4 @ =0x030013F0
	ldr r5, _0803DCB8 @ =0x0203C984
	ldrb r1, [r5, #4]
	adds r0, r1, r4
	ldrb r0, [r0]
	bl GetUnit
	mov r8, r0
	ldrb r5, [r5, #5]
	adds r4, r5, r4
	ldrb r0, [r4]
	bl GetUnit
	adds r4, r0, #0
	ldr r0, [r6, #0x2c]
	movs r1, #0
	mov sb, r1
	mov r1, r8
	strb r0, [r1, #0xe]
	ldr r0, [r6, #0x30]
	strb r0, [r1, #0xf]
	ldr r0, [r6, #0x34]
	strb r0, [r4, #0xe]
	ldr r0, [r6, #0x38]
	strb r0, [r4, #0xf]
	ldr r5, _0803DCBC @ =0x03001410
	ldr r1, [r5]
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r2, #6
	movs r3, #5
	bl sub_803F8E0
	ldr r1, [r5, #4]
	mov r0, sb
	str r0, [sp]
	str r0, [sp, #4]
	str r6, [sp, #8]
	adds r0, r4, #0
	movs r2, #8
	movs r3, #5
	bl sub_803F8E0
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803DCB4: .4byte 0x030013F0
_0803DCB8: .4byte 0x0203C984
_0803DCBC: .4byte 0x03001410

	thumb_func_start sub_803DCC0
sub_803DCC0: @ 0x0803DCC0
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r4, _0803DD18 @ =0x030013F0
	ldr r5, _0803DD1C @ =0x0203C984
	ldrb r1, [r5, #4]
	adds r0, r1, r4
	ldrb r0, [r0]
	bl GetUnit
	adds r7, r0, #0
	ldr r1, _0803DD20 @ =gUnk_Sio_0810F432
	mov r0, sp
	movs r2, #2
	bl memcpy
	ldr r6, _0803DD24 @ =0x03001410
	ldr r0, [r6, #4]
	bl EndMu
	ldrb r5, [r5, #5]
	adds r4, r5, r4
	ldrb r0, [r4]
	bl GetUnit
	ldr r1, _0803DD28 @ =0x0000FFFE
	ldrh r2, [r0, #0xc]
	ands r1, r2
	strh r1, [r0, #0xc]
	ldr r0, _0803DD2C @ =0x0300140C
	ldrb r0, [r0, #2]
	cmp r0, #1
	bne _0803DD0C
	ldr r0, [r6]
	mov r1, sp
	bl SetMuMoveScript
	movs r0, #7
	strb r0, [r7, #0xe]
_0803DD0C:
	bl sub_803CAC8
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803DD18: .4byte 0x030013F0
_0803DD1C: .4byte 0x0203C984
_0803DD20: .4byte gUnk_Sio_0810F432
_0803DD24: .4byte 0x03001410
_0803DD28: .4byte 0x0000FFFE
_0803DD2C: .4byte 0x0300140C

	thumb_func_start sub_803DD30
sub_803DD30: @ 0x0803DD30
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	bl MuExistsActive
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _0803DD9E
	ldr r4, _0803DDA8 @ =0x030013F0
	ldr r5, _0803DDAC @ =0x0203C984
	ldrb r1, [r5, #4]
	adds r0, r1, r4
	ldrb r0, [r0]
	bl GetUnit
	adds r6, r0, #0
	ldrb r2, [r5, #5]
	adds r0, r2, r4
	ldrb r0, [r0]
	bl GetUnit
	mov r8, r0
	adds r0, r6, #0
	bl HideUnitSprite
	ldr r1, _0803DDB0 @ =gAction
	movs r0, #2
	strb r0, [r1, #0x11]
	ldrb r5, [r5, #5]
	adds r4, r5, r4
	ldrb r0, [r4]
	strb r0, [r1, #0xd]
	ldr r0, _0803DDB4 @ =0x0300140C
	ldrb r1, [r0, #3]
	adds r0, r6, #0
	bl UnitEquipItemSlot
	adds r0, r6, #0
	mov r1, r8
	bl BattleGenerateReal
	ldr r1, _0803DDB8 @ =gBmSt
	movs r0, #0x40
	ldrb r2, [r1, #4]
	orrs r0, r2
	strb r0, [r1, #4]
	ldr r0, _0803DDBC @ =gUnk_Sio_085CADA4
	adds r1, r7, #0
	bl SpawnProcLocking
	adds r0, r7, #0
	bl Proc_Break
_0803DD9E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803DDA8: .4byte 0x030013F0
_0803DDAC: .4byte 0x0203C984
_0803DDB0: .4byte gAction
_0803DDB4: .4byte 0x0300140C
_0803DDB8: .4byte gBmSt
_0803DDBC: .4byte gUnk_Sio_085CADA4

	thumb_func_start sub_803DDC0
sub_803DDC0: @ 0x0803DDC0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	ldr r0, _0803DEAC @ =0x030013F0
	ldr r1, _0803DEB0 @ =0x0203C984
	mov r8, r1
	ldrb r2, [r1, #4]
	adds r1, r2, r0
	ldrb r4, [r1]
	mov r3, r8
	ldrb r3, [r3, #5]
	adds r0, r3, r0
	ldrb r5, [r0]
	adds r0, r4, #0
	bl GetUnit
	adds r6, r0, #0
	adds r0, r5, #0
	bl GetUnit
	adds r7, r0, #0
	bl sub_803CF58
	lsrs r0, r4, #6
	lsls r0, r0, #3
	mov r2, r8
	adds r2, #0x30
	adds r3, r0, r2
	ldr r1, _0803DEB4 @ =gBattleUnitA
	mov sb, r1
	adds r1, #0x6a
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	str r1, [r3]
	add r0, r8
	adds r0, #0x2c
	movs r3, #0
	strb r4, [r0]
	strb r3, [r6, #9]
	lsrs r0, r5, #6
	lsls r0, r0, #3
	adds r2, r0, r2
	ldr r4, _0803DEB8 @ =gBattleUnitB
	adds r1, r4, #0
	adds r1, #0x6a
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	str r1, [r2]
	add r0, r8
	adds r0, #0x2c
	strb r5, [r0]
	strb r3, [r7, #9]
	adds r0, r6, #0
	bl sub_8040CA8
	adds r0, r7, #0
	bl sub_8040CA8
	adds r0, r6, #0
	movs r1, #0
	bl SetUnitStatus
	adds r0, r7, #0
	movs r1, #0
	bl SetUnitStatus
	bl EndAllMus
	adds r0, r6, #0
	bl GetUnitCurrentHp
	cmp r0, #0
	beq _0803DE6A
	adds r0, r6, #0
	bl ShowUnitSprite
	ldr r0, _0803DEBC @ =0x0000FFFE
	ldrh r2, [r6, #0xc]
	ands r0, r2
	strh r0, [r6, #0xc]
_0803DE6A:
	bl sub_803CAC8
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	adds r0, r6, #0
	bl GetUnitCurrentHp
	mov r1, sb
	adds r1, #0x6e
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r0, r1
	bne _0803DEC0
	adds r0, r7, #0
	bl GetUnitCurrentHp
	adds r1, r4, #0
	adds r1, #0x6e
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r0, r1
	bne _0803DEC0
	mov r3, r8
	ldrb r0, [r3, #9]
	adds r0, #1
	strb r0, [r3, #9]
	b _0803DEC6
	.align 2, 0
_0803DEAC: .4byte 0x030013F0
_0803DEB0: .4byte 0x0203C984
_0803DEB4: .4byte gBattleUnitA
_0803DEB8: .4byte gBattleUnitB
_0803DEBC: .4byte 0x0000FFFE
_0803DEC0:
	ldr r1, _0803DEDC @ =0x0203C984
	movs r0, #0
	strb r0, [r1, #9]
_0803DEC6:
	mov r0, sl
	bl Proc_Break
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803DEDC: .4byte 0x0203C984

	thumb_func_start sub_803DEE0
sub_803DEE0: @ 0x0803DEE0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	str r0, [sp, #0xc]
	ldr r1, _0803DF4C @ =0x030013F0
	ldr r0, _0803DF50 @ =0x0203C984
	mov sb, r0
	ldrb r2, [r0, #4]
	adds r0, r2, r1
	ldrb r0, [r0]
	adds r5, r0, #0
	mov r3, sb
	ldrb r3, [r3, #5]
	adds r1, r3, r1
	ldrb r1, [r1]
	mov sl, r1
	bl GetUnit
	adds r4, r0, #0
	mov r0, sl
	bl GetUnit
	mov r8, r0
	movs r7, #0
	adds r0, r5, #0
	bl sub_803CB94
	str r0, [sp, #0x10]
	mov r0, sl
	bl sub_803CB94
	str r0, [sp, #0x14]
	ldr r6, _0803DF54 @ =0x03001410
	str r7, [r6, #4]
	str r7, [r6]
	movs r0, #4
	ldrh r1, [r4, #0xc]
	ands r0, r1
	cmp r0, #0
	bne _0803DF3C
	ldr r0, [r4]
	cmp r0, #0
	bne _0803DF58
_0803DF3C:
	lsrs r0, r5, #6
	mov r1, sb
	adds r1, #0xa
	adds r0, r0, r1
	ldrb r1, [r0]
	subs r1, #1
	strb r1, [r0]
	b _0803DF90
	.align 2, 0
_0803DF4C: .4byte 0x030013F0
_0803DF50: .4byte 0x0203C984
_0803DF54: .4byte 0x03001410
_0803DF58:
	adds r0, r4, #0
	bl StartMu
	str r0, [r6]
	bl DisableMuCamera
	movs r0, #1
	ldrh r2, [r4, #0xc]
	orrs r0, r2
	strh r0, [r4, #0xc]
	movs r7, #1
	ldr r1, [r6]
	ldr r2, _0803DFB8 @ =gUnk_Sio_0810F3B0
	ldr r3, [sp, #0x10]
	lsls r0, r3, #2
	adds r0, r0, r2
	movs r5, #0
	ldrsh r2, [r0, r5]
	movs r5, #2
	ldrsh r3, [r0, r5]
	movs r0, #2
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0xc]
	str r0, [sp, #8]
	adds r0, r4, #0
	bl sub_803F8E0
_0803DF90:
	movs r0, #4
	mov r1, r8
	ldrh r1, [r1, #0xc]
	ands r0, r1
	cmp r0, #0
	bne _0803DFA4
	mov r2, r8
	ldr r0, [r2]
	cmp r0, #0
	bne _0803DFC0
_0803DFA4:
	ldr r0, _0803DFBC @ =0x0203C984
	mov r3, sl
	lsrs r1, r3, #6
	adds r0, #0xa
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	b _0803E006
	.align 2, 0
_0803DFB8: .4byte gUnk_Sio_0810F3B0
_0803DFBC: .4byte 0x0203C984
_0803DFC0:
	mov r0, r8
	bl StartMu
	ldr r4, _0803E020 @ =0x03001410
	str r0, [r4, #4]
	bl DisableMuCamera
	movs r0, #1
	mov r5, r8
	ldrh r5, [r5, #0xc]
	orrs r0, r5
	mov r1, r8
	strh r0, [r1, #0xc]
	adds r0, r7, #0
	movs r7, #0
	cmp r0, #0
	bne _0803DFE4
	movs r7, #1
_0803DFE4:
	ldr r1, [r4, #4]
	ldr r2, _0803E024 @ =gUnk_Sio_0810F3B0
	ldr r3, [sp, #0x14]
	lsls r0, r3, #2
	adds r0, r0, r2
	movs r4, #0
	ldrsh r2, [r0, r4]
	movs r5, #2
	ldrsh r3, [r0, r5]
	movs r0, #2
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0xc]
	str r0, [sp, #8]
	mov r0, r8
	bl sub_803F8E0
_0803E006:
	bl sub_803CAC8
	ldr r0, [sp, #0xc]
	bl Proc_Break
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803E020: .4byte 0x03001410
_0803E024: .4byte gUnk_Sio_0810F3B0

	thumb_func_start sub_803E028
sub_803E028: @ 0x0803E028
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	movs r2, #0
_0803E032:
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	str r2, [sp]
	bl sub_8035CB0
	lsls r0, r0, #0x18
	ldr r2, [sp]
	adds r1, r2, #1
	mov r8, r1
	cmp r0, #0
	beq _0803E098
	movs r6, #0
	movs r7, #0
	ldr r0, _0803E0AC @ =0x030013F0
	adds r4, r2, r0
	movs r5, #4
_0803E052:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0803E080
	adds r7, #1
	str r2, [sp]
	bl GetUnit
	adds r1, r0, #0
	movs r0, #4
	ldrh r3, [r1, #0xc]
	ands r0, r3
	ldr r2, [sp]
	cmp r0, #0
	bne _0803E080
	adds r0, r1, #0
	bl sub_803D438
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r2, [sp]
	cmp r0, #1
	bne _0803E080
	adds r6, #1
_0803E080:
	adds r4, #5
	subs r5, #1
	cmp r5, #0
	bge _0803E052
	cmp r6, #0
	bne _0803E098
	cmp r7, #0
	beq _0803E098
	ldr r0, _0803E0B0 @ =0x0203C984
	adds r0, #0xa
	adds r0, r2, r0
	strb r6, [r0]
_0803E098:
	mov r2, r8
	cmp r2, #3
	ble _0803E032
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803E0AC: .4byte 0x030013F0
_0803E0B0: .4byte 0x0203C984

	thumb_func_start sub_803E0B4
sub_803E0B4: @ 0x0803E0B4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	ldr r0, _0803E154 @ =0x030013F0
	ldr r5, _0803E158 @ =0x0203C984
	ldrb r2, [r5, #4]
	adds r1, r2, r0
	ldrb r7, [r1]
	ldrb r1, [r5, #5]
	adds r0, r1, r0
	ldrb r6, [r0]
	adds r0, r7, #0
	bl GetUnit
	adds r4, r0, #0
	adds r0, r6, #0
	bl GetUnit
	adds r2, r0, #0
	ldrh r1, [r4, #0xc]
	movs r3, #4
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _0803E0EE
	ldr r0, _0803E15C @ =0x0000FFFE
	ands r0, r1
	strh r0, [r4, #0xc]
_0803E0EE:
	ldrh r1, [r2, #0xc]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _0803E0FE
	ldr r0, _0803E15C @ =0x0000FFFE
	ands r0, r1
	strh r0, [r2, #0xc]
_0803E0FE:
	lsrs r0, r7, #6
	adds r1, r0, #0
	adds r2, r5, #0
	adds r2, #0xa
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r5, r1, #0
	cmp r0, #0
	beq _0803E11A
	lsrs r1, r6, #6
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803E176
_0803E11A:
	adds r4, r1, #0
	ldr r2, _0803E158 @ =0x0203C984
	ldr r3, _0803E160 @ =0x0203C618
	adds r3, #0xa0
	ldrb r7, [r3]
	ldrb r1, [r2, #0xe]
	subs r0, r7, r1
	adds r1, r2, #0
	adds r1, #0xf
	adds r0, r0, r1
	strb r4, [r0]
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r3, [r3]
	cmp r0, r3
	bne _0803E176
	adds r1, r5, #0
	adds r0, r2, #0
	adds r0, #0xa
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803E164
	adds r4, r1, #0
	b _0803E166
	.align 2, 0
_0803E154: .4byte 0x030013F0
_0803E158: .4byte 0x0203C984
_0803E15C: .4byte 0x0000FFFE
_0803E160: .4byte 0x0203C618
_0803E164:
	lsrs r4, r6, #6
_0803E166:
	strb r4, [r2, #0xf]
	movs r0, #0xff
	bl sub_803CAD8
	mov r0, r8
	bl Proc_Break
	b _0803E184
_0803E176:
	ldr r0, _0803E190 @ =gPlaySt
	ldrb r0, [r0, #0xf]
	bl sub_803CAD8
	mov r0, r8
	bl Proc_Break
_0803E184:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803E190: .4byte gPlaySt

	thumb_func_start sub_803E194
sub_803E194: @ 0x0803E194
	push {lr}
	bl EndAllMus
	bl EndAllMus
	bl sub_803CD74
	bl sub_803CDD4
	bl RefreshUnitSprites
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_803E1B0
sub_803E1B0: @ 0x0803E1B0
	push {lr}
	ldr r0, _0803E1DC @ =gKeySt
	ldr r1, [r0]
	movs r0, #2
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq _0803E1D8
	ldr r0, _0803E1E0 @ =0x0300456C
	movs r2, #0
	movs r1, #0x14
	strb r1, [r0]
	ldr r1, _0803E1E4 @ =gUnk_Sio_085C98F4
	ldr r1, [r1]
	ldrb r1, [r1, #6]
	strb r1, [r0, #1]
	strh r2, [r0, #2]
	movs r1, #4
	bl sub_8035DC8
_0803E1D8:
	pop {r0}
	bx r0
	.align 2, 0
_0803E1DC: .4byte gKeySt
_0803E1E0: .4byte 0x0300456C
_0803E1E4: .4byte gUnk_Sio_085C98F4

	thumb_func_start sub_803E1E8
sub_803E1E8: @ 0x0803E1E8
	ldrb r0, [r0]
	cmp r0, #1
	beq _0803E1FA
	cmp r0, #1
	blt _0803E1FE
	cmp r0, #7
	bgt _0803E1FE
	cmp r0, #6
	blt _0803E1FE
_0803E1FA:
	movs r0, #1
	b _0803E200
_0803E1FE:
	movs r0, #0
_0803E200:
	bx lr
	.align 2, 0

	thumb_func_start sub_803E204
sub_803E204: @ 0x0803E204
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r4, _0803E22C @ =0x0300140C
	ldr r2, _0803E230 @ =sub_803E1E8
	adds r0, r4, #0
	add r1, sp, #4
	bl sub_80362B0
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0803E2AC
	ldrb r0, [r4]
	cmp r0, #6
	beq _0803E25C
	cmp r0, #6
	bgt _0803E234
	cmp r0, #1
	beq _0803E23A
	b _0803E2AC
	.align 2, 0
_0803E22C: .4byte 0x0300140C
_0803E230: .4byte sub_803E1E8
_0803E234:
	cmp r0, #7
	beq _0803E294
	b _0803E2AC
_0803E23A:
	ldrb r0, [r4, #1]
	ldr r2, _0803E258 @ =0x0203C988
	adds r3, r5, #0
	adds r3, #0x2c
	adds r1, r5, #0
	adds r1, #0x30
	str r1, [sp]
	movs r1, #0
	bl sub_803CBB4
	adds r0, r5, #0
	movs r1, #1
	bl Proc_Goto
	b _0803E2AC
	.align 2, 0
_0803E258: .4byte 0x0203C988
_0803E25C:
	bl sub_803C2B0
	add r1, sp, #4
	ldrb r2, [r1]
	lsls r0, r2, #4
	subs r0, r0, r2
	ldr r1, _0803E288 @ =0x0203C6B9
	adds r0, r0, r1
	ldr r1, _0803E28C @ =0x03001428
	bl sub_80368DC
	ldr r0, _0803E290 @ =gUnk_Sio_085CA884
	movs r1, #0x60
	movs r2, #0
	movs r3, #0
	bl StartPopup
	adds r0, r5, #0
	movs r1, #3
	bl Proc_Goto
	b _0803E2AC
	.align 2, 0
_0803E288: .4byte 0x0203C6B9
_0803E28C: .4byte 0x03001428
_0803E290: .4byte gUnk_Sio_085CA884
_0803E294:
	bl sub_803C2B0
	ldr r0, _0803E2B8 @ =gUnk_Sio_085CA8A4
	movs r1, #0x60
	movs r2, #0
	movs r3, #0
	bl StartPopup
	adds r0, r5, #0
	movs r1, #4
	bl Proc_Goto
_0803E2AC:
	bl sub_803E1B0
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803E2B8: .4byte gUnk_Sio_085CA8A4

	thumb_func_start sub_803E2BC
sub_803E2BC: @ 0x0803E2BC
	ldrb r0, [r0]
	cmp r0, #3
	bgt _0803E2CA
	cmp r0, #2
	blt _0803E2CA
	movs r0, #1
	b _0803E2CC
_0803E2CA:
	movs r0, #0
_0803E2CC:
	bx lr
	.align 2, 0

	thumb_func_start sub_803E2D0
sub_803E2D0: @ 0x0803E2D0
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r4, _0803E2F4 @ =0x0300140C
	ldr r2, _0803E2F8 @ =sub_803E2BC
	adds r0, r4, #0
	add r1, sp, #4
	bl sub_80362B0
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0803E360
	ldrb r0, [r4]
	cmp r0, #2
	beq _0803E2FC
	cmp r0, #3
	beq _0803E344
	b _0803E360
	.align 2, 0
_0803E2F4: .4byte 0x0300140C
_0803E2F8: .4byte sub_803E2BC
_0803E2FC:
	ldrb r0, [r4, #2]
	bl GetUnit
	adds r4, r0, #0
	movs r0, #0x80
	lsls r0, r0, #2
	ldrh r1, [r4, #0xc]
	ands r0, r1
	cmp r0, #0
	bne _0803E320
	ldr r0, _0803E31C @ =0x03001410
	ldr r0, [r0]
	bl EndMu
	b _0803E328
	.align 2, 0
_0803E31C: .4byte 0x03001410
_0803E320:
	ldr r0, [r5, #0x2c]
	strb r0, [r4, #0xe]
	ldr r0, [r5, #0x30]
	strb r0, [r4, #0xf]
_0803E328:
	ldr r0, _0803E340 @ =0x0000FFFE
	ldrh r1, [r4, #0xc]
	ands r0, r1
	strh r0, [r4, #0xc]
	bl RefreshUnitSprites
	adds r0, r5, #0
	movs r1, #0
	bl Proc_Goto
	b _0803E360
	.align 2, 0
_0803E340: .4byte 0x0000FFFE
_0803E344:
	ldrb r0, [r4, #1]
	ldr r2, _0803E36C @ =0x0203C989
	adds r3, r5, #0
	adds r3, #0x34
	adds r1, r5, #0
	adds r1, #0x38
	str r1, [sp]
	movs r1, #1
	bl sub_803CBB4
	adds r0, r5, #0
	movs r1, #2
	bl Proc_Goto
_0803E360:
	bl sub_803E1B0
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803E36C: .4byte 0x0203C989

	thumb_func_start sub_803E370
sub_803E370: @ 0x0803E370
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	mov r8, r3
	bl StartMu
	ldr r1, _0803E3AC @ =0x03001410
	lsls r4, r4, #2
	adds r4, r4, r1
	str r0, [r4]
	movs r0, #0xe
	ldrsb r0, [r5, r0]
	str r0, [r6]
	movs r0, #0xf
	ldrsb r0, [r5, r0]
	mov r1, r8
	str r0, [r1]
	ldr r0, _0803E3B0 @ =0x0000FDFF
	ldrh r1, [r5, #0xc]
	ands r0, r1
	strh r0, [r5, #0xc]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803E3AC: .4byte 0x03001410
_0803E3B0: .4byte 0x0000FDFF

	thumb_func_start sub_803E3B4
sub_803E3B4: @ 0x0803E3B4
	ldrb r0, [r0]
	cmp r0, #5
	bgt _0803E3C2
	cmp r0, #4
	blt _0803E3C2
	movs r0, #1
	b _0803E3C4
_0803E3C2:
	movs r0, #0
_0803E3C4:
	bx lr
	.align 2, 0

	thumb_func_start sub_803E3C8
sub_803E3C8: @ 0x0803E3C8
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	ldr r4, _0803E3EC @ =0x0300140C
	ldr r2, _0803E3F0 @ =sub_803E3B4
	adds r0, r4, #0
	mov r1, sp
	bl sub_80362B0
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0803E496
	ldrb r0, [r4]
	cmp r0, #4
	beq _0803E3F4
	cmp r0, #5
	beq _0803E43C
	b _0803E496
	.align 2, 0
_0803E3EC: .4byte 0x0300140C
_0803E3F0: .4byte sub_803E3B4
_0803E3F4:
	ldrb r0, [r4, #2]
	bl GetUnit
	adds r6, r0, #0
	movs r0, #0x80
	lsls r0, r0, #2
	ldrh r1, [r6, #0xc]
	ands r0, r1
	cmp r0, #0
	bne _0803E418
	ldr r0, _0803E414 @ =0x03001410
	ldr r0, [r0, #4]
	bl EndMu
	b _0803E420
	.align 2, 0
_0803E414: .4byte 0x03001410
_0803E418:
	ldr r0, [r7, #0x34]
	strb r0, [r6, #0xe]
	ldr r0, [r7, #0x38]
	strb r0, [r6, #0xf]
_0803E420:
	ldr r0, _0803E438 @ =0x0000FFFE
	ldrh r1, [r6, #0xc]
	ands r0, r1
	strh r0, [r6, #0xc]
	bl RefreshUnitSprites
	adds r0, r7, #0
	movs r1, #1
	bl Proc_Goto
	b _0803E496
	.align 2, 0
_0803E438: .4byte 0x0000FFFE
_0803E43C:
	ldr r4, _0803E4A4 @ =0x030013F0
	ldr r5, _0803E4A8 @ =0x0203C984
	ldrb r1, [r5, #4]
	adds r0, r1, r4
	ldrb r0, [r0]
	bl GetUnit
	adds r6, r0, #0
	ldrb r5, [r5, #5]
	adds r4, r5, r4
	ldrb r0, [r4]
	bl GetUnit
	adds r4, r0, #0
	movs r5, #0x80
	lsls r5, r5, #2
	adds r0, r5, #0
	ldrh r1, [r6, #0xc]
	ands r0, r1
	cmp r0, #0
	beq _0803E476
	adds r2, r7, #0
	adds r2, #0x2c
	adds r3, r7, #0
	adds r3, #0x30
	adds r0, r6, #0
	movs r1, #0
	bl sub_803E370
_0803E476:
	adds r0, r5, #0
	ldrh r1, [r4, #0xc]
	ands r0, r1
	cmp r0, #0
	beq _0803E490
	adds r2, r7, #0
	adds r2, #0x34
	adds r3, r7, #0
	adds r3, #0x38
	adds r0, r4, #0
	movs r1, #1
	bl sub_803E370
_0803E490:
	adds r0, r7, #0
	bl Proc_Break
_0803E496:
	bl sub_803E1B0
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803E4A4: .4byte 0x030013F0
_0803E4A8: .4byte 0x0203C984

	thumb_func_start sub_803E4AC
sub_803E4AC: @ 0x0803E4AC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r7, #0
	movs r0, #0
	mov r8, r0
	movs r5, #0
	ldrh r4, [r6, #0x1c]
	cmp r4, #0
	beq _0803E4F8
_0803E4C2:
	adds r0, r6, #0
	adds r1, r4, #0
	bl CanUnitUseWeapon
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803E4E4
	adds r0, r4, #0
	bl GetItemMight
	cmp r0, r8
	bls _0803E4E4
	adds r7, r4, #0
	adds r0, r7, #0
	bl GetItemMight
	mov r8, r0
_0803E4E4:
	adds r5, #1
	cmp r5, #4
	bgt _0803E4F8
	lsls r1, r5, #1
	adds r0, r6, #0
	adds r0, #0x1c
	adds r0, r0, r1
	ldrh r4, [r0]
	cmp r4, #0
	bne _0803E4C2
_0803E4F8:
	cmp r7, #0
	beq _0803E506
	adds r0, r6, #0
	bl GetUnitPower
	add r0, r8
	b _0803E508
_0803E506:
	movs r0, #0
_0803E508:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_803E514
sub_803E514: @ 0x0803E514
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r0, #0
	mov r8, r0
	movs r6, #0
	adds r5, r7, #0
	adds r0, r7, #5
	cmp r7, r0
	bge _0803E55E
_0803E52A:
	adds r0, r5, #0
	bl GetUnit
	adds r4, r0, #0
	movs r0, #4
	ldrh r1, [r4, #0xc]
	ands r0, r1
	cmp r0, #0
	bne _0803E556
	ldr r0, [r4]
	cmp r0, #0
	beq _0803E556
	movs r0, #1
	add r8, r0
	adds r0, r4, #0
	bl sub_803E4AC
	adds r6, r6, r0
	adds r0, r4, #0
	bl GetUnitCurrentHp
	adds r6, r6, r0
_0803E556:
	adds r5, #1
	adds r0, r7, #5
	cmp r5, r0
	blt _0803E52A
_0803E55E:
	ldr r0, _0803E580 @ =0x0203C984
	asrs r1, r7, #6
	lsls r1, r1, #2
	adds r0, #0x14
	adds r1, r1, r0
	ldr r0, [r1]
	adds r6, r6, r0
	adds r0, r6, #0
	mov r1, r8
	bl Div
	adds r6, r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0803E580: .4byte 0x0203C984

	thumb_func_start sub_803E584
sub_803E584: @ 0x0803E584
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _0803E5C4 @ =gKeySt
	ldr r1, [r0]
	movs r0, #8
	ldrh r1, [r1, #4]
	ands r0, r1
	cmp r0, #0
	beq _0803E5BC
	bl sub_803C2B0
	str r4, [r5, #0x58]
	ldr r0, _0803E5C8 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt _0803E5B4
	movs r0, #0x68
	bl m4aSongNumStart
	ldr r0, _0803E5CC @ =gUnk_Sio_085CA93C
	bl StartEvent
_0803E5B4:
	adds r0, r5, #0
	movs r1, #3
	bl Proc_Goto
_0803E5BC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803E5C4: .4byte gKeySt
_0803E5C8: .4byte gPlaySt
_0803E5CC: .4byte gUnk_Sio_085CA93C

	thumb_func_start sub_803E5D0
sub_803E5D0: @ 0x0803E5D0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r6, #1
	rsbs r6, r6, #0
	movs r1, #0
	bl sub_803E584
	movs r4, #0
_0803E5E0:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl sub_8035CB0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803E614
	ldr r5, _0803E628 @ =0x0203C984
	adds r0, r5, #0
	adds r0, #0xa
	adds r0, r4, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803E614
	ldr r0, _0803E62C @ =gPlaySt
	ldrb r0, [r0, #0xf]
	cmp r0, r4
	beq _0803E614
	lsls r0, r4, #6
	adds r0, #1
	bl sub_803E514
	cmp r6, r0
	bls _0803E614
	adds r6, r0, #0
	strb r4, [r5, #2]
_0803E614:
	adds r4, #1
	cmp r4, #3
	ble _0803E5E0
	adds r0, r7, #0
	bl Proc_Break
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803E628: .4byte 0x0203C984
_0803E62C: .4byte gPlaySt

	thumb_func_start sub_803E630
sub_803E630: @ 0x0803E630
	push {r4, lr}
	adds r0, r1, #0
	bl GetUnitEquippedWeapon
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r4, r0, #0
	cmp r0, #0
	beq _0803E654
	bl GetItemMaxRange
	cmp r0, #1
	beq _0803E654
	adds r0, r4, #0
	bl GetItemMinRange
	cmp r0, #1
	bgt _0803E658
_0803E654:
	movs r0, #1
	b _0803E65A
_0803E658:
	movs r0, #2
_0803E65A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start sub_803E660
sub_803E660: @ 0x0803E660
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x18]
	movs r1, #0
	str r1, [sp, #0x1c]
	movs r2, #0
	str r2, [sp, #0x20]
	ldr r0, [sp, #0x10]
	movs r1, #1
	bl sub_803E584
	ldr r0, _0803E7B8 @ =gAiSt
	adds r0, #0x7d
	movs r1, #0xe
	strb r1, [r0]
	ldr r0, _0803E7BC @ =gPlaySt
	ldrb r0, [r0, #0xf]
	lsls r0, r0, #6
	str r0, [sp, #0x14]
	adds r4, r0, #0
	adds r4, #1
	adds r0, #6
	cmp r4, r0
	blt _0803E69E
	b _0803E844
_0803E69E:
	ldr r0, _0803E7C0 @ =gActiveUnitId
	strb r4, [r0]
	ldrb r0, [r0]
	bl GetUnit
	adds r1, r0, #0
	ldr r0, _0803E7C4 @ =gActiveUnit
	str r1, [r0]
	movs r0, #4
	ldrh r2, [r1, #0xc]
	ands r0, r2
	ldr r2, [sp, #0x14]
	adds r2, #6
	str r2, [sp, #0x28]
	adds r4, #1
	str r4, [sp, #0x2c]
	cmp r0, #0
	beq _0803E6C4
	b _0803E83A
_0803E6C4:
	ldr r0, [r1]
	cmp r0, #0
	bne _0803E6CC
	b _0803E83A
_0803E6CC:
	movs r5, #0
_0803E6CE:
	ldr r0, _0803E7C4 @ =gActiveUnit
	ldr r2, [r0]
	lsls r1, r5, #1
	adds r0, r2, #0
	adds r0, #0x1c
	adds r0, r0, r1
	ldrh r4, [r0]
	adds r6, r4, #0
	adds r0, r5, #1
	str r0, [sp, #0x30]
	cmp r4, #0
	bne _0803E6E8
	b _0803E832
_0803E6E8:
	adds r0, r2, #0
	adds r1, r4, #0
	bl CanUnitUseWeapon
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803E6F8
	b _0803E832
_0803E6F8:
	mov sl, r5
	movs r1, #0
	mov r8, r1
	adds r0, r4, #0
	bl GetItemMinRange
	cmp r0, #2
	ble _0803E70A
	b _0803E832
_0803E70A:
	adds r0, r4, #0
	bl GetItemAttributes
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0
	beq _0803E71A
	b _0803E832
_0803E71A:
	adds r0, r4, #0
	bl GetItemMinRange
	cmp r0, #1
	bne _0803E728
	movs r2, #2
	mov r8, r2
_0803E728:
	adds r0, r6, #0
	bl GetItemMaxRange
	cmp r0, #1
	ble _0803E73A
	movs r0, #1
	mov r1, r8
	orrs r1, r0
	mov r8, r1
_0803E73A:
	add r0, sp, #4
	strh r5, [r0, #4]
	ldr r0, _0803E7C8 @ =0x0203C984
	ldrb r0, [r0, #2]
	lsls r0, r0, #6
	mov sb, r0
	mov r5, sb
	adds r5, #1
	adds r0, #6
	cmp r5, r0
	bge _0803E832
	add r6, sp, #4
	ldr r7, _0803E7CC @ =0x0300140C
	mov r0, r8
	movs r2, #2
	ands r0, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x24]
_0803E760:
	adds r0, r5, #0
	bl GetUnit
	adds r4, r0, #0
	movs r0, #4
	ldrh r1, [r4, #0xc]
	ands r0, r1
	cmp r0, #0
	bne _0803E828
	ldr r0, [r4]
	cmp r0, #0
	beq _0803E828
	strb r5, [r6, #2]
	ldr r2, [sp, #0x24]
	cmp r2, #0
	beq _0803E7D8
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r6]
	ldrb r0, [r4, #0xf]
	strb r0, [r6, #1]
	add r0, sp, #4
	bl AiSimulateBattleAgainstTargetAtPosition
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x18]
	cmp r1, r0
	bhi _0803E7D8
	str r0, [sp, #0x18]
	ldr r0, _0803E7C0 @ =gActiveUnitId
	ldrb r0, [r0]
	str r0, [sp, #0x1c]
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x20]
	mov r2, r8
	cmp r2, #3
	bne _0803E7D0
	movs r0, #3
	adds r1, r4, #0
	bl sub_803E630
	b _0803E7D2
	.align 2, 0
_0803E7B8: .4byte gAiSt
_0803E7BC: .4byte gPlaySt
_0803E7C0: .4byte gActiveUnitId
_0803E7C4: .4byte gActiveUnit
_0803E7C8: .4byte 0x0203C984
_0803E7CC: .4byte 0x0300140C
_0803E7D0:
	movs r0, #1
_0803E7D2:
	strb r0, [r7, #2]
	mov r0, sl
	strb r0, [r7, #3]
_0803E7D8:
	movs r0, #1
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _0803E828
	ldrb r0, [r4, #0xe]
	adds r0, #1
	strb r0, [r6]
	ldrb r0, [r4, #0xf]
	subs r0, #1
	strb r0, [r6, #1]
	add r0, sp, #4
	bl AiSimulateBattleAgainstTargetAtPosition
	ldr r0, [sp, #0xc]
	ldr r2, [sp, #0x18]
	cmp r2, r0
	bhi _0803E828
	str r0, [sp, #0x18]
	ldr r0, _0803E81C @ =gActiveUnitId
	ldrb r0, [r0]
	str r0, [sp, #0x1c]
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x20]
	mov r0, r8
	cmp r0, #3
	bne _0803E820
	movs r0, #3
	adds r1, r4, #0
	bl sub_803E630
	strb r0, [r7, #2]
	b _0803E824
	.align 2, 0
_0803E81C: .4byte gActiveUnitId
_0803E820:
	movs r1, #2
	strb r1, [r7, #2]
_0803E824:
	mov r2, sl
	strb r2, [r7, #3]
_0803E828:
	adds r5, #1
	mov r0, sb
	adds r0, #6
	cmp r5, r0
	blt _0803E760
_0803E832:
	ldr r5, [sp, #0x30]
	cmp r5, #4
	bgt _0803E83A
	b _0803E6CE
_0803E83A:
	ldr r4, [sp, #0x2c]
	ldr r0, [sp, #0x28]
	cmp r4, r0
	bge _0803E844
	b _0803E69E
_0803E844:
	ldr r2, _0803E878 @ =0x0203C988
	ldr r3, [sp, #0x10]
	adds r3, #0x2c
	ldr r0, [sp, #0x10]
	adds r0, #0x30
	str r0, [sp]
	ldr r0, [sp, #0x1c]
	movs r1, #0
	bl sub_803CBB4
	ldr r0, _0803E87C @ =0x0300140C
	add r1, sp, #0x20
	ldrb r1, [r1]
	strb r1, [r0, #1]
	ldr r0, [sp, #0x10]
	bl Proc_Break
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803E878: .4byte 0x0203C988
_0803E87C: .4byte 0x0300140C

	thumb_func_start sub_803E880
sub_803E880: @ 0x0803E880
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0803E8AC @ =0x0300140C
	ldrb r0, [r0, #1]
	bl GetUnit
	adds r1, r0, #0
	movs r0, #0xe
	ldrsb r0, [r1, r0]
	lsls r0, r0, #4
	ldrb r1, [r1, #0xf]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	lsls r1, r1, #4
	movs r2, #2
	adds r3, r4, #0
	bl AiStartActionCursor
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803E8AC: .4byte 0x0300140C

	thumb_func_start sub_803E8B0
sub_803E8B0: @ 0x0803E8B0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _0803E938 @ =0x0300140C
	ldrb r0, [r0, #1]
	ldr r5, _0803E93C @ =0x0203C989
	movs r1, #0x34
	adds r1, r1, r6
	mov r8, r1
	movs r1, #0x38
	adds r1, r1, r6
	mov sb, r1
	str r1, [sp]
	movs r1, #1
	adds r2, r5, #0
	mov r3, r8
	bl sub_803CBB4
	ldr r4, _0803E940 @ =0x030013F0
	subs r5, #5
	ldrb r1, [r5, #4]
	adds r0, r1, r4
	ldrb r0, [r0]
	bl GetUnit
	adds r7, r0, #0
	ldrb r5, [r5, #5]
	adds r4, r5, r4
	ldrb r0, [r4]
	bl GetUnit
	adds r4, r0, #0
	movs r5, #0x80
	lsls r5, r5, #2
	adds r0, r5, #0
	ldrh r1, [r7, #0xc]
	ands r0, r1
	cmp r0, #0
	beq _0803E914
	adds r2, r6, #0
	adds r2, #0x2c
	adds r3, r6, #0
	adds r3, #0x30
	adds r0, r7, #0
	movs r1, #0
	bl sub_803E370
_0803E914:
	adds r0, r5, #0
	ldrh r1, [r4, #0xc]
	ands r0, r1
	cmp r0, #0
	beq _0803E92A
	adds r0, r4, #0
	movs r1, #1
	mov r2, r8
	mov r3, sb
	bl sub_803E370
_0803E92A:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803E938: .4byte 0x0300140C
_0803E93C: .4byte 0x0203C989
_0803E940: .4byte 0x030013F0

	thumb_func_start sub_803E944
sub_803E944: @ 0x0803E944
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #2
	bl sub_803E584
	bl MuExistsActive
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803E95E
	adds r0, r4, #0
	bl Proc_Break
_0803E95E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_803E964
sub_803E964: @ 0x0803E964
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	bl GetGameTime
	ldr r2, _0803EA1C @ =gUnk_Sio_085CA8B4
	movs r1, #0x1f
	ands r1, r0
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #4
	asrs r0, r0, #1
	mov sl, r0
	movs r7, #0
_0803E984:
	ldr r0, _0803EA20 @ =gUnk_Sio_085C98F4
	ldr r0, [r0]
	ldrb r0, [r0, #6]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #2
	adds r0, r7, r0
	ldr r1, _0803EA24 @ =gUnk_Sio_0810F390
	adds r0, r0, r1
	ldrb r0, [r0]
	bl sub_8035CB0
	lsls r0, r0, #0x18
	adds r2, r7, #1
	mov sb, r2
	cmp r0, #0
	beq _0803EA08
	movs r6, #0
	lsls r0, r7, #2
	mov r8, r0
_0803E9AC:
	mov r1, r8
	adds r0, r1, r7
	adds r0, r0, r6
	ldr r2, _0803EA28 @ =0x030013F0
	adds r0, r0, r2
	ldrb r0, [r0]
	bl GetUnit
	adds r1, r0, #0
	cmp r1, #0
	beq _0803EA02
	ldr r0, [r1]
	cmp r0, #0
	beq _0803EA02
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	ldrh r2, [r1, #0xc]
	ands r0, r2
	cmp r0, #0
	beq _0803EA02
	movs r5, #0xe
	ldrsb r5, [r1, r5]
	lsls r5, r5, #4
	movs r4, #0xf
	ldrsb r4, [r1, r4]
	lsls r4, r4, #4
	mov r0, sl
	subs r4, r4, r0
	adds r0, r1, #0
	bl GetUnitDisplayedSpritePalette
	movs r3, #0xf
	ands r3, r0
	lsls r3, r3, #0xc
	movs r1, #0xa4
	lsls r1, r1, #4
	adds r3, r3, r1
	adds r0, r5, #0
	adds r1, r4, #0
	ldr r2, _0803EA2C @ =Sprite_16x16
	bl PutOamHiRam
_0803EA02:
	adds r6, #1
	cmp r6, #4
	ble _0803E9AC
_0803EA08:
	mov r7, sb
	cmp r7, #3
	ble _0803E984
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803EA1C: .4byte gUnk_Sio_085CA8B4
_0803EA20: .4byte gUnk_Sio_085C98F4
_0803EA24: .4byte gUnk_Sio_0810F390
_0803EA28: .4byte 0x030013F0
_0803EA2C: .4byte Sprite_16x16

	thumb_func_start sub_803EA30
sub_803EA30: @ 0x0803EA30
	push {lr}
	ldr r0, _0803EA40 @ =gUnk_Sio_085CA8D4
	movs r1, #4
	bl SpawnProc
	pop {r0}
	bx r0
	.align 2, 0
_0803EA40: .4byte gUnk_Sio_085CA8D4

	thumb_func_start sub_803EA44
sub_803EA44: @ 0x0803EA44
	push {lr}
	ldr r0, _0803EA50 @ =gUnk_Sio_085CA8D4
	bl Proc_EndEach
	pop {r0}
	bx r0
	.align 2, 0
_0803EA50: .4byte gUnk_Sio_085CA8D4

	thumb_func_start sub_803EA54
sub_803EA54: @ 0x0803EA54
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xa3
	lsls r0, r0, #2
	bl sub_806EAE4
	ldr r0, _0803EA70 @ =gActiveUnit
	ldr r0, [r0]
	adds r1, r4, #0
	bl sub_80702BC
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803EA70: .4byte gActiveUnit

	thumb_func_start sub_803EA74
sub_803EA74: @ 0x0803EA74
	push {lr}
	adds r1, r0, #0
	ldr r0, _0803EA8C @ =0x0203C984
	ldrb r0, [r0, #8]
	cmp r0, #0
	bne _0803EA90
	adds r0, r1, #0
	movs r1, #0
	bl Proc_Goto
	b _0803EAA2
	.align 2, 0
_0803EA8C: .4byte 0x0203C984
_0803EA90:
	bl EndAllMus
	ldr r0, _0803EAA8 @ =gPlaySt
	ldrb r1, [r0, #0xf]
	movs r0, #6
	movs r2, #0
	movs r3, #0
	bl sub_803CB3C
_0803EAA2:
	pop {r0}
	bx r0
	.align 2, 0
_0803EAA8: .4byte gPlaySt

	thumb_func_start sub_803EAAC
sub_803EAAC: @ 0x0803EAAC
	push {lr}
	ldr r2, _0803EAC0 @ =0x0203C984
	ldrb r1, [r2, #8]
	cmp r1, #0
	bne _0803EAC4
	strb r1, [r2, #9]
	movs r1, #0
	bl Proc_Goto
	b _0803EAD6
	.align 2, 0
_0803EAC0: .4byte 0x0203C984
_0803EAC4:
	bl EndAllMus
	ldr r0, _0803EADC @ =gPlaySt
	ldrb r1, [r0, #0xf]
	movs r0, #7
	movs r2, #0
	movs r3, #0
	bl sub_803CB3C
_0803EAD6:
	pop {r0}
	bx r0
	.align 2, 0
_0803EADC: .4byte gPlaySt

	thumb_func_start sub_803EAE0
sub_803EAE0: @ 0x0803EAE0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0803EAF8 @ =0x0203C984
	ldrb r0, [r0, #8]
	cmp r0, #0
	bne _0803EAFC
	ldr r1, [r4, #0x58]
	adds r0, r4, #0
	bl Proc_Goto
	b _0803EB18
	.align 2, 0
_0803EAF8: .4byte 0x0203C984
_0803EAFC:
	bl EndAllMus
	bl EndAllMus
	ldr r1, _0803EB20 @ =0x0203C618
	movs r0, #1
	strb r0, [r1, #0xb]
	movs r0, #0xff
	bl sub_803CAD8
	adds r0, r4, #0
	movs r1, #5
	bl Proc_Goto
_0803EB18:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803EB20: .4byte 0x0203C618

	thumb_func_start sub_803EB24
sub_803EB24: @ 0x0803EB24
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0
	ldr r1, _0803EB38 @ =0x0203C618
	ldrb r0, [r1]
	cmp r0, #1
	bne _0803EB3C
	strb r0, [r1, #0xb]
	b _0803EB8E
	.align 2, 0
_0803EB38: .4byte 0x0203C618
_0803EB3C:
	ldr r2, _0803EBA0 @ =0x0203C984
	adds r4, r1, #0
	adds r4, #0xa0
	ldrb r0, [r4]
	ldrb r3, [r2, #0xe]
	subs r1, r0, r3
	adds r0, r2, #0
	adds r0, #0xf
	adds r1, r1, r0
	ldr r3, _0803EBA4 @ =gPlaySt
	ldrb r0, [r3, #0xf]
	strb r0, [r1]
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
	ldrb r1, [r3, #0xf]
	lsls r0, r1, #2
	adds r1, r2, #0
	adds r1, #0x14
	adds r0, r0, r1
	str r6, [r0]
	ldrb r0, [r2, #0xe]
	ldrb r1, [r4]
	cmp r0, r1
	bne _0803EBA8
	movs r1, #0
	ldrb r0, [r4]
	cmp r6, r0
	bge _0803EB8C
	adds r4, r2, #0
	adds r4, #0xa
	adds r3, r0, #0
_0803EB7C:
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803EB86
	adds r6, r1, #0
_0803EB86:
	adds r1, #1
	cmp r1, r3
	blt _0803EB7C
_0803EB8C:
	strb r6, [r2, #0xf]
_0803EB8E:
	movs r0, #0xff
	bl sub_803CAD8
	adds r0, r5, #0
	movs r1, #8
	bl Proc_Goto
	b _0803EBB6
	.align 2, 0
_0803EBA0: .4byte 0x0203C984
_0803EBA4: .4byte gPlaySt
_0803EBA8:
	ldrb r0, [r3, #0xf]
	bl sub_803CAD8
	adds r0, r5, #0
	movs r1, #8
	bl Proc_Goto
_0803EBB6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_803EBBC
sub_803EBBC: @ 0x0803EBBC
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0803EBDC @ =0x0203C618
	ldrb r0, [r1]
	cmp r0, #1
	bne _0803EBE0
	strb r0, [r1, #0xb]
	movs r0, #0xff
	bl sub_803CAD8
	adds r0, r4, #0
	movs r1, #8
	bl Proc_Goto
	b _0803EBF2
	.align 2, 0
_0803EBDC: .4byte 0x0203C618
_0803EBE0:
	movs r0, #2
	strb r0, [r1, #0xb]
	movs r0, #0xff
	bl sub_803CAD8
	adds r0, r4, #0
	movs r1, #8
	bl Proc_Goto
_0803EBF2:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_803EBF8
sub_803EBF8: @ 0x0803EBF8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	ldr r2, _0803EC64 @ =0x0203C984
	ldr r0, _0803EC68 @ =0x0203C618
	adds r4, r0, #0
	adds r4, #0xa0
	ldrb r0, [r4]
	ldrb r3, [r2, #0xe]
	subs r1, r0, r3
	adds r0, r2, #0
	adds r0, #0xf
	adds r1, r1, r0
	ldr r3, _0803EC6C @ =gPlaySt
	ldrb r0, [r3, #0xf]
	strb r0, [r1]
	ldrb r0, [r2, #0xe]
	adds r0, #1
	strb r0, [r2, #0xe]
	ldrb r1, [r3, #0xf]
	lsls r0, r1, #2
	adds r1, r2, #0
	adds r1, #0x14
	adds r0, r0, r1
	str r5, [r0]
	ldrb r0, [r2, #0xe]
	ldrb r1, [r4]
	cmp r0, r1
	bne _0803EC70
	movs r1, #0
	ldrb r0, [r4]
	cmp r5, r0
	bge _0803EC50
	adds r4, r2, #0
	adds r4, #0xa
	adds r3, r0, #0
_0803EC40:
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803EC4A
	adds r5, r1, #0
_0803EC4A:
	adds r1, #1
	cmp r1, r3
	blt _0803EC40
_0803EC50:
	strb r5, [r2, #0xf]
	movs r0, #0xff
	bl sub_803CAD8
	adds r0, r6, #0
	movs r1, #5
	bl Proc_Goto
	b _0803EC7E
	.align 2, 0
_0803EC64: .4byte 0x0203C984
_0803EC68: .4byte 0x0203C618
_0803EC6C: .4byte gPlaySt
_0803EC70:
	ldrb r0, [r3, #0xf]
	bl sub_803CAD8
	adds r0, r6, #0
	movs r1, #5
	bl Proc_Goto
_0803EC7E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_803EC84
sub_803EC84: @ 0x0803EC84
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0803ECA4 @ =0x0203C618
	movs r0, #2
	strb r0, [r1, #0xb]
	movs r0, #0xff
	bl sub_803CAD8
	adds r0, r4, #0
	movs r1, #5
	bl Proc_Goto
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803ECA4: .4byte 0x0203C618

	thumb_func_start sub_803ECA8
sub_803ECA8: @ 0x0803ECA8
	push {r4, lr}
	movs r3, #0
	str r3, [r0, #0x58]
	ldr r2, _0803ECC8 @ =gPlaySt
	ldrb r4, [r2, #0xf]
	lsls r1, r4, #6
	str r1, [r0, #0x5c]
	ldr r0, _0803ECCC @ =0x0203C984
	adds r0, #0xa
	ldrb r2, [r2, #0xf]
	adds r0, r2, r0
	strb r3, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803ECC8: .4byte gPlaySt
_0803ECCC: .4byte 0x0203C984

	thumb_func_start sub_803ECD0
sub_803ECD0: @ 0x0803ECD0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
_0803ECD4:
	ldr r1, [r5, #0x58]
	cmp r1, #5
	bne _0803ECE4
	adds r0, r5, #0
	movs r1, #1
	bl Proc_Goto
	b _0803ED44
_0803ECE4:
	ldr r0, [r5, #0x5c]
	adds r0, r0, r1
	adds r0, #1
	bl GetUnit
	adds r6, r0, #0
	movs r0, #4
	ldrh r1, [r6, #0xc]
	ands r0, r1
	cmp r0, #0
	bne _0803ED00
	ldr r0, [r6]
	cmp r0, #0
	bne _0803ED08
_0803ED00:
	ldr r0, [r5, #0x58]
	adds r0, #1
	str r0, [r5, #0x58]
	b _0803ECD4
_0803ED08:
	bl RefreshUnitSprites
	adds r0, r6, #0
	bl HideUnitSprite
	adds r0, r6, #0
	bl StartMu
	adds r4, r0, #0
	ldr r1, _0803ED4C @ =gWorkingMoveScr
	movs r0, #2
	strb r0, [r1]
	movs r0, #4
	strb r0, [r1, #1]
	adds r0, r4, #0
	bl SetMuMoveScript
	adds r0, r4, #0
	bl sub_803F5C8
	str r4, [r5, #0x54]
	ldr r0, [r5, #0x58]
	adds r0, #1
	str r0, [r5, #0x58]
	ldr r0, _0803ED50 @ =0x0000FDFF
	ldrh r1, [r6, #0xc]
	ands r0, r1
	movs r1, #5
	orrs r0, r1
	strh r0, [r6, #0xc]
_0803ED44:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803ED4C: .4byte gWorkingMoveScr
_0803ED50: .4byte 0x0000FDFF

	thumb_func_start sub_803ED54
sub_803ED54: @ 0x0803ED54
	push {lr}
	ldr r0, [r0, #0x54]
	bl EndMu
	pop {r0}
	bx r0

	thumb_func_start sub_803ED60
sub_803ED60: @ 0x0803ED60
	push {lr}
	bl sub_803CD74
	bl sub_803CDD4
	bl RefreshUnitSprites
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_803ED74
sub_803ED74: @ 0x0803ED74
	push {lr}
	bl GetTalkChoiceResult
	adds r1, r0, #0
	cmp r1, #1
	bne _0803ED8C
	ldr r0, _0803ED88 @ =0x0203C984
	strb r1, [r0, #8]
	b _0803ED92
	.align 2, 0
_0803ED88: .4byte 0x0203C984
_0803ED8C:
	ldr r1, _0803ED98 @ =0x0203C984
	movs r0, #0
	strb r0, [r1, #8]
_0803ED92:
	pop {r0}
	bx r0
	.align 2, 0
_0803ED98: .4byte 0x0203C984

	thumb_func_start sub_803ED9C
sub_803ED9C: @ 0x0803ED9C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _0803EDE0 @ =0x06015000
	movs r1, #6
	bl sub_8070E70
	ldr r2, _0803EDE4 @ =0x000006E5
	movs r0, #0x40
	movs r1, #0x38
	bl sub_8070804
	movs r4, #0
	ldr r6, _0803EDE8 @ =0x0203C98E
_0803EDB6:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl sub_8035CB0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803EDCE
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803EDCE
	str r4, [r5, #0x58]
_0803EDCE:
	adds r4, #1
	cmp r4, #3
	ble _0803EDB6
	movs r0, #0
	str r0, [r5, #0x5c]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803EDE0: .4byte 0x06015000
_0803EDE4: .4byte 0x000006E5
_0803EDE8: .4byte 0x0203C98E

	thumb_func_start sub_803EDEC
sub_803EDEC: @ 0x0803EDEC
	push {r4, lr}
	adds r4, r0, #0
_0803EDF0:
	ldr r1, [r4, #0x5c]
	cmp r1, #4
	ble _0803EE02
	bl sub_807089C
	adds r0, r4, #0
	bl Proc_Break
	b _0803EE56
_0803EE02:
	ldr r0, [r4, #0x58]
	lsls r0, r0, #6
	adds r0, r0, r1
	adds r0, #1
	bl GetUnit
	adds r1, r0, #0
	movs r0, #4
	ldrh r2, [r1, #0xc]
	ands r0, r2
	cmp r0, #0
	bne _0803EE20
	ldr r0, [r1]
	cmp r0, #0
	bne _0803EE28
_0803EE20:
	ldr r0, [r4, #0x5c]
	adds r0, #1
	str r0, [r4, #0x5c]
	b _0803EDF0
_0803EE28:
	ldr r3, _0803EE5C @ =0x0203C984
	ldr r0, [r4, #0x58]
	lsls r0, r0, #3
	adds r1, r3, #0
	adds r1, #0x30
	adds r0, r0, r1
	movs r1, #0x1e
	str r1, [r0]
	ldr r1, [r4, #0x58]
	lsls r2, r1, #3
	adds r2, r2, r3
	lsls r1, r1, #6
	ldr r0, [r4, #0x5c]
	adds r0, r0, r1
	adds r0, #1
	adds r2, #0x2c
	strb r0, [r2]
	adds r0, r4, #0
	bl sub_803CA6C
	ldr r0, [r4, #0x5c]
	adds r0, #1
	str r0, [r4, #0x5c]
_0803EE56:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803EE5C: .4byte 0x0203C984

	thumb_func_start sub_803EE60
sub_803EE60: @ 0x0803EE60
	push {lr}
	adds r1, r0, #0
	ldr r0, _0803EE78 @ =0x0203C618
	ldrb r0, [r0]
	cmp r0, #1
	bne _0803EE74
	adds r0, r1, #0
	movs r1, #1
	bl Proc_Goto
_0803EE74:
	pop {r0}
	bx r0
	.align 2, 0
_0803EE78: .4byte 0x0203C618

	thumb_func_start sub_803EE7C
sub_803EE7C: @ 0x0803EE7C
	push {lr}
	ldr r0, _0803EEA8 @ =gBg2Tm
	movs r1, #0
	bl TmFill
	movs r0, #4
	bl EnableBgSync
	bl RenderMap
	bl sub_8047CB8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803EEAC
	movs r0, #1
	bl sub_804256C
	bl sub_8047CC8
	b _0803EEC2
	.align 2, 0
_0803EEA8: .4byte gBg2Tm
_0803EEAC:
	bl EndAllMus
	bl RenderMap
	bl sub_80627D0
	ldr r0, _0803EEC8 @ =gBattleSt
	movs r1, #0x80
	ldrb r2, [r0, #1]
	orrs r1, r2
	strb r1, [r0, #1]
_0803EEC2:
	pop {r0}
	bx r0
	.align 2, 0
_0803EEC8: .4byte gBattleSt

	thumb_func_start sub_803EECC
sub_803EECC: @ 0x0803EECC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r6, _0803EF3C @ =gBattleUnitA
	movs r0, #0x11
	ldrsb r0, [r6, r0]
	cmp r0, #0
	bne _0803EEE8
	ldr r0, _0803EF40 @ =ProcScr_Mu
	bl Proc_Find
	adds r4, r0, #0
	bl sub_803F5C8
	str r4, [r7, #0x54]
_0803EEE8:
	ldr r5, _0803EF44 @ =gBattleUnitB
	movs r0, #0x11
	ldrsb r0, [r5, r0]
	cmp r0, #0
	bne _0803EF34
	bl RefreshUnitSprites
	movs r0, #0xb
	ldrsb r0, [r5, r0]
	bl GetUnit
	bl HideUnitSprite
	adds r0, r5, #0
	bl StartMu
	adds r4, r0, #0
	movs r0, #0xe
	ldrsb r0, [r6, r0]
	movs r1, #0xf
	ldrsb r1, [r6, r1]
	movs r2, #0xe
	ldrsb r2, [r5, r2]
	movs r3, #0xf
	ldrsb r3, [r5, r3]
	bl sub_80629FC
	ldr r1, _0803EF48 @ =gWorkingMoveScr
	strb r0, [r1]
	movs r0, #4
	strb r0, [r1, #1]
	adds r0, r4, #0
	bl SetMuMoveScript
	adds r0, r4, #0
	bl sub_803F5C8
	str r4, [r7, #0x54]
_0803EF34:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803EF3C: .4byte gBattleUnitA
_0803EF40: .4byte ProcScr_Mu
_0803EF44: .4byte gBattleUnitB
_0803EF48: .4byte gWorkingMoveScr

	thumb_func_start sub_803EF4C
sub_803EF4C: @ 0x0803EF4C
	push {r4, r5, lr}
	ldr r0, _0803EF94 @ =gBattleUnitA
	ldrb r0, [r0, #0xb]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl GetUnit
	adds r4, r0, #0
	ldr r0, _0803EF98 @ =gBattleUnitB
	ldrb r0, [r0, #0xb]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl GetUnit
	adds r5, r0, #0
	adds r0, r4, #0
	bl GetUnitCurrentHp
	cmp r0, #0
	bne _0803EF7C
	movs r0, #5
	ldrh r1, [r4, #0xc]
	orrs r0, r1
	strh r0, [r4, #0xc]
_0803EF7C:
	adds r0, r5, #0
	bl GetUnitCurrentHp
	cmp r0, #0
	bne _0803EF8E
	movs r0, #5
	ldrh r1, [r5, #0xc]
	orrs r0, r1
	strh r0, [r5, #0xc]
_0803EF8E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803EF94: .4byte gBattleUnitA
_0803EF98: .4byte gBattleUnitB

	thumb_func_start sub_803EF9C
sub_803EF9C: @ 0x0803EF9C
	ldr r1, _0803EFA4 @ =0x0203C9D0
	movs r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0
_0803EFA4: .4byte 0x0203C9D0

	thumb_func_start sub_803EFA8
sub_803EFA8: @ 0x0803EFA8
	ldr r1, _0803EFB0 @ =0x0203C9D0
	movs r0, #0
	strb r0, [r1]
	bx lr
	.align 2, 0
_0803EFB0: .4byte 0x0203C9D0

	thumb_func_start sub_803EFB4
sub_803EFB4: @ 0x0803EFB4
	ldr r2, _0803EFE8 @ =gDispIo
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
	adds r1, r2, #0
	adds r1, #0x3c
	movs r0, #0x3f
	ldrb r3, [r1]
	ands r0, r3
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x44
	movs r1, #0
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	bx lr
	.align 2, 0
_0803EFE8: .4byte gDispIo

	thumb_func_start sub_803EFEC
sub_803EFEC: @ 0x0803EFEC
	ldr r0, _0803F018 @ =0x04000006
	ldrh r0, [r0]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r3, _0803F01C @ =gUnk_Sio_02001528
	cmp r1, #0xa0
	bls _0803F004
	ldr r0, _0803F020 @ =gUnk_Sio_02001520
	ldr r0, [r0]
	str r0, [r3]
	movs r1, #0
_0803F004:
	ldr r2, _0803F024 @ =0x04000042
	ldr r0, [r3]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrh r3, [r1]
	lsls r0, r3, #8
	ldrh r1, [r1, #2]
	adds r0, r1, r0
	strh r0, [r2]
	bx lr
	.align 2, 0
_0803F018: .4byte 0x04000006
_0803F01C: .4byte gUnk_Sio_02001528
_0803F020: .4byte gUnk_Sio_02001520
_0803F024: .4byte 0x04000042

	thumb_func_start sub_803F028
sub_803F028: @ 0x0803F028
	ldr r2, _0803F038 @ =gUnk_Sio_02001520
	ldr r3, [r2]
	ldr r1, _0803F03C @ =gUnk_Sio_02001524
	ldr r0, [r1]
	str r0, [r2]
	str r3, [r1]
	bx lr
	.align 2, 0
_0803F038: .4byte gUnk_Sio_02001520
_0803F03C: .4byte gUnk_Sio_02001524

	thumb_func_start sub_803F040
sub_803F040: @ 0x0803F040
	push {lr}
	ldr r2, _0803F064 @ =gDispIo
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
	movs r0, #0
	bl SetOnHBlankA
	pop {r0}
	bx r0
	.align 2, 0
_0803F064: .4byte gDispIo

	thumb_func_start sub_803F068
sub_803F068: @ 0x0803F068
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	str r0, [sp, #4]
	ldr r7, [sp, #0x34]
	ldr r0, [sp, #0x48]
	ldr r6, [sp, #0x4c]
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	subs r1, #0x78
	subs r2, #0x50
	subs r3, #0x78
	subs r7, #0x50
	ldr r4, [sp, #0x38]
	subs r4, #0x78
	str r4, [sp, #0x38]
	ldr r4, [sp, #0x3c]
	subs r4, #0x50
	str r4, [sp, #0x3c]
	ldr r4, [sp, #0x40]
	subs r4, #0x78
	str r4, [sp, #0x40]
	ldr r4, [sp, #0x44]
	subs r4, #0x50
	str r4, [sp, #0x44]
	ldr r4, _0803F1D4 @ =gSinLut
	mov sb, r4
	lsls r0, r0, #0x10
	movs r4, #0xff
	lsls r4, r4, #0x10
	ands r4, r0
	asrs r4, r4, #0x10
	mov ip, r4
	lsls r0, r4, #1
	add r0, sb
	movs r4, #0
	ldrsh r5, [r0, r4]
	adds r0, r1, #0
	muls r0, r5, r0
	mov r8, r0
	mov r4, ip
	adds r4, #0x40
	lsls r4, r4, #1
	add r4, sb
	movs r0, #0
	ldrsh r4, [r4, r0]
	adds r0, r2, #0
	muls r0, r4, r0
	add r0, r8
	str r0, [sp, #8]
	muls r1, r4, r1
	adds r0, r2, #0
	muls r0, r5, r0
	subs r1, r1, r0
	str r1, [sp, #0xc]
	adds r1, r3, #0
	muls r1, r5, r1
	adds r0, r7, #0
	muls r0, r4, r0
	adds r1, r1, r0
	mov sb, r1
	adds r1, r3, #0
	muls r1, r4, r1
	adds r0, r7, #0
	muls r0, r5, r0
	subs r7, r1, r0
	ldr r2, [sp, #0x38]
	adds r1, r2, #0
	muls r1, r5, r1
	ldr r2, [sp, #0x3c]
	adds r0, r2, #0
	muls r0, r4, r0
	adds r1, r1, r0
	mov sl, r1
	ldr r0, [sp, #0x38]
	adds r1, r0, #0
	muls r1, r4, r1
	adds r0, r2, #0
	muls r0, r5, r0
	subs r1, r1, r0
	mov r8, r1
	ldr r2, [sp, #0x40]
	adds r1, r2, #0
	muls r1, r5, r1
	ldr r2, [sp, #0x44]
	adds r0, r2, #0
	muls r0, r4, r0
	adds r1, r1, r0
	str r1, [sp, #0x10]
	ldr r0, [sp, #0x40]
	adds r1, r0, #0
	muls r1, r4, r1
	adds r0, r2, #0
	muls r0, r5, r0
	subs r4, r1, r0
	ldr r1, [sp, #8]
	asrs r0, r1, #0xc
	muls r0, r6, r0
	asrs r0, r0, #8
	adds r0, #0x78
	str r0, [sp, #8]
	ldr r2, [sp, #0xc]
	asrs r0, r2, #0xc
	muls r0, r6, r0
	asrs r0, r0, #8
	adds r0, #0x50
	str r0, [sp, #0xc]
	mov r1, sb
	asrs r0, r1, #0xc
	muls r0, r6, r0
	asrs r0, r0, #8
	adds r0, #0x78
	mov sb, r0
	asrs r0, r7, #0xc
	muls r0, r6, r0
	asrs r0, r0, #8
	adds r7, r0, #0
	adds r7, #0x50
	mov r2, sl
	asrs r0, r2, #0xc
	muls r0, r6, r0
	asrs r0, r0, #8
	adds r0, #0x78
	mov sl, r0
	mov r1, r8
	asrs r0, r1, #0xc
	muls r0, r6, r0
	asrs r0, r0, #8
	adds r0, #0x50
	mov r8, r0
	ldr r2, [sp, #0x10]
	asrs r0, r2, #0xc
	muls r0, r6, r0
	asrs r0, r0, #8
	adds r0, #0x78
	str r0, [sp, #0x10]
	asrs r0, r4, #0xc
	muls r0, r6, r0
	asrs r0, r0, #8
	adds r4, r0, #0
	adds r4, #0x50
	str r7, [sp]
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	ldr r2, [sp, #0xc]
	mov r3, sb
	bl sub_8013F04
	mov r0, r8
	str r0, [sp]
	ldr r0, [sp, #4]
	mov r1, sb
	adds r2, r7, #0
	mov r3, sl
	bl sub_8013F04
	str r4, [sp]
	ldr r0, [sp, #4]
	mov r1, sl
	mov r2, r8
	ldr r3, [sp, #0x10]
	bl sub_8013F04
	ldr r1, [sp, #0xc]
	str r1, [sp]
	ldr r0, [sp, #4]
	ldr r1, [sp, #0x10]
	adds r2, r4, #0
	ldr r3, [sp, #8]
	bl sub_8013F04
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803F1D4: .4byte gSinLut

	thumb_func_start sub_803F1D8
sub_803F1D8: @ 0x0803F1D8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _0803F20C @ =gUnk_Sio_02001520
	ldr r0, _0803F210 @ =gUnk_Sio_020012A0
	str r0, [r1]
	ldr r5, _0803F214 @ =gUnk_Sio_02001524
	ldr r2, _0803F218 @ =0xFFFFFD80
	adds r1, r0, r2
	str r1, [r5]
	ldr r1, _0803F21C @ =gUnk_Sio_02001528
	str r0, [r1]
	bl sub_8013EE4
	ldr r0, [r5]
	bl sub_8013EE4
	adds r4, #0x4c
	movs r0, #0
	strh r0, [r4]
	ldr r0, _0803F220 @ =sub_803EFEC
	bl SetOnHBlankA
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803F20C: .4byte gUnk_Sio_02001520
_0803F210: .4byte gUnk_Sio_020012A0
_0803F214: .4byte gUnk_Sio_02001524
_0803F218: .4byte 0xFFFFFD80
_0803F21C: .4byte gUnk_Sio_02001528
_0803F220: .4byte sub_803EFEC

	thumb_func_start sub_803F224
sub_803F224: @ 0x0803F224
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r7, r4, #0
	adds r7, #0x4c
	adds r5, r4, #0
	adds r5, #0x64
	ldrh r0, [r7]
	ldrh r1, [r5]
	cmp r0, r1
	bne _0803F248
	movs r0, #0
	bl SetOnHBlankA
	adds r0, r4, #0
	bl Proc_Break
	b _0803F2AE
_0803F248:
	movs r0, #0
	ldrsh r3, [r7, r0]
	movs r1, #0
	ldrsh r0, [r5, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0xa0
	movs r2, #0xc0
	bl Interpolate
	adds r6, r0, #0
	movs r2, #0x88
	lsls r2, r2, #1
	movs r0, #0
	ldrsh r3, [r7, r0]
	movs r1, #0
	ldrsh r0, [r5, r1]
	str r0, [sp]
	movs r0, #1
	movs r1, #0x10
	bl Interpolate
	adds r5, r0, #0
	ldr r4, _0803F2B8 @ =gUnk_Sio_02001524
	ldr r0, [r4]
	bl sub_8013EE4
	ldr r0, [r4]
	movs r2, #0
	str r2, [sp]
	movs r1, #0xf0
	str r1, [sp, #4]
	movs r1, #0xa0
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	str r1, [sp, #0x10]
	lsls r6, r6, #0x10
	asrs r6, r6, #0x10
	str r6, [sp, #0x14]
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	str r5, [sp, #0x18]
	movs r1, #0
	movs r3, #0xf0
	bl sub_803F068
	bl sub_803F028
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
_0803F2AE:
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803F2B8: .4byte gUnk_Sio_02001524

	thumb_func_start sub_803F2BC
sub_803F2BC: @ 0x0803F2BC
	ldr r2, _0803F300 @ =gDispIo
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
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #0x20
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r2, #1]
	adds r1, r2, #0
	adds r1, #0x2f
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
	bx lr
	.align 2, 0
_0803F300: .4byte gDispIo

	thumb_func_start sub_803F304
sub_803F304: @ 0x0803F304
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, _0803F3A4 @ =gUnk_Sio_085CADFC
	bl SpawnProcLocking
	adds r0, #0x64
	movs r3, #0
	strh r4, [r0]
	ldr r0, _0803F3A8 @ =gDispIo
	mov ip, r0
	movs r2, #1
	ldrb r0, [r0, #1]
	orrs r0, r2
	movs r1, #2
	mov r8, r1
	mov r1, r8
	orrs r0, r1
	movs r6, #4
	orrs r0, r6
	movs r5, #8
	orrs r0, r5
	movs r4, #0x10
	orrs r0, r4
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	movs r1, #0x7f
	ands r0, r1
	mov r1, ip
	strb r0, [r1, #1]
	mov r0, ip
	adds r0, #0x2f
	strb r3, [r0]
	adds r0, #4
	strb r3, [r0]
	adds r1, #0x2e
	movs r0, #0xf0
	strb r0, [r1]
	adds r1, #4
	movs r0, #0xa0
	strb r0, [r1]
	mov r7, ip
	adds r7, #0x35
	ldrb r0, [r7]
	orrs r2, r0
	mov r1, r8
	orrs r2, r1
	orrs r2, r6
	orrs r2, r5
	orrs r2, r4
	mov r3, ip
	adds r3, #0x36
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r1, [r3]
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
	strb r0, [r3]
	movs r0, #0x20
	orrs r2, r0
	strb r2, [r7]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803F3A4: .4byte gUnk_Sio_085CADFC
_0803F3A8: .4byte gDispIo

	thumb_func_start sub_803F3AC
sub_803F3AC: @ 0x0803F3AC
	push {lr}
	adds r1, r0, #0
	movs r0, #0x40
	bl sub_803F304
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_803F3BC
sub_803F3BC: @ 0x0803F3BC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r7, r4, #0
	adds r7, #0x4c
	adds r5, r4, #0
	adds r5, #0x64
	ldrh r0, [r7]
	ldrh r1, [r5]
	cmp r0, r1
	bne _0803F3E0
	movs r0, #0
	bl SetOnHBlankA
	adds r0, r4, #0
	bl Proc_Break
	b _0803F446
_0803F3E0:
	movs r2, #0
	ldrsh r3, [r7, r2]
	movs r1, #0
	ldrsh r0, [r5, r1]
	str r0, [sp]
	movs r0, #4
	movs r1, #0xc0
	movs r2, #0xa0
	bl Interpolate
	adds r6, r0, #0
	movs r1, #0x88
	lsls r1, r1, #1
	movs r2, #0
	ldrsh r3, [r7, r2]
	movs r2, #0
	ldrsh r0, [r5, r2]
	str r0, [sp]
	movs r0, #5
	movs r2, #0x10
	bl Interpolate
	adds r5, r0, #0
	ldr r4, _0803F450 @ =gUnk_Sio_02001524
	ldr r0, [r4]
	bl sub_8013EE4
	ldr r0, [r4]
	movs r2, #0
	str r2, [sp]
	movs r1, #0xf0
	str r1, [sp, #4]
	movs r1, #0xa0
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	str r1, [sp, #0x10]
	lsls r6, r6, #0x10
	asrs r6, r6, #0x10
	str r6, [sp, #0x14]
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	str r5, [sp, #0x18]
	movs r1, #0
	movs r3, #0xf0
	bl sub_803F068
	bl sub_803F028
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
_0803F446:
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803F450: .4byte gUnk_Sio_02001524

	thumb_func_start sub_803F454
sub_803F454: @ 0x0803F454
	ldr r2, _0803F474 @ =gDispIo
	movs r0, #0
	strb r0, [r2, #1]
	adds r1, r2, #0
	adds r1, #0x2f
	strb r0, [r1]
	adds r1, #4
	strb r0, [r1]
	subs r1, #5
	movs r0, #0xf0
	strb r0, [r1]
	adds r1, #4
	movs r0, #0xa0
	strb r0, [r1]
	bx lr
	.align 2, 0
_0803F474: .4byte gDispIo

	thumb_func_start sub_803F478
sub_803F478: @ 0x0803F478
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, _0803F4FC @ =gUnk_Sio_085CAE34
	bl SpawnProcLocking
	adds r0, #0x64
	movs r2, #0
	strh r4, [r0]
	ldr r3, _0803F500 @ =gDispIo
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrb r1, [r3, #1]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r3, #1]
	adds r0, r3, #0
	adds r0, #0x2f
	strb r2, [r0]
	adds r0, #4
	strb r2, [r0]
	adds r1, r3, #0
	adds r1, #0x2e
	movs r0, #0xf0
	strb r0, [r1]
	adds r1, #4
	movs r0, #0xa0
	strb r0, [r1]
	adds r4, r3, #0
	adds r4, #0x35
	movs r2, #1
	ldrb r0, [r4]
	orrs r2, r0
	movs r0, #2
	orrs r2, r0
	movs r0, #4
	orrs r2, r0
	movs r0, #8
	orrs r2, r0
	movs r0, #0x10
	orrs r2, r0
	adds r3, #0x36
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r1, [r3]
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
	strb r0, [r3]
	movs r0, #0x20
	orrs r2, r0
	strb r2, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803F4FC: .4byte gUnk_Sio_085CAE34
_0803F500: .4byte gDispIo

	thumb_func_start sub_803F504
sub_803F504: @ 0x0803F504
	push {lr}
	adds r1, r0, #0
	movs r0, #0x40
	bl sub_803F478
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_803F514
sub_803F514: @ 0x0803F514
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0803F530 @ =gUnk_Sio_085CADFC
	bl Proc_Find
	cmp r0, #0
	bne _0803F528
	adds r0, r4, #0
	bl Proc_Break
_0803F528:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803F530: .4byte gUnk_Sio_085CADFC

	thumb_func_start sub_803F534
sub_803F534: @ 0x0803F534
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0803F550 @ =gUnk_Sio_085CAE34
	bl Proc_Find
	cmp r0, #0
	bne _0803F548
	adds r0, r4, #0
	bl Proc_Break
_0803F548:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803F550: .4byte gUnk_Sio_085CAE34

	thumb_func_start sub_803F554
sub_803F554: @ 0x0803F554
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0803F5A0 @ =gUnk_Sio_085CAE6C
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	movs r1, #0xb0
	lsls r1, r1, #2
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r1, [r4, #0x30]
	ldr r0, [r4, #0x34]
	ldrh r0, [r0, #2]
	movs r2, #0xd0
	lsls r2, r2, #7
	adds r0, r0, r2
	strh r0, [r1, #0x22]
	ldr r0, [r4, #0x34]
	ldrb r0, [r0, #1]
	adds r0, #0x10
	lsls r0, r0, #5
	ldr r1, _0803F5A4 @ =gPal
	adds r0, r0, r1
	movs r1, #0x16
	movs r2, #0x14
	adds r3, r4, #0
	bl StartPalFade
	ldr r0, _0803F5A8 @ =gUnk_Sio_085CAE84
	adds r1, r4, #0
	bl SpawnProc
	str r4, [r0, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803F5A0: .4byte gUnk_Sio_085CAE6C
_0803F5A4: .4byte gPal
_0803F5A8: .4byte gUnk_Sio_085CAE84

	thumb_func_start sub_803F5AC
sub_803F5AC: @ 0x0803F5AC
	ldr r0, [r0, #0x2c]
	ldr r2, [r0, #0x30]
	ldr r1, [r0, #0x34]
	movs r0, #0xf
	ldrb r3, [r1, #1]
	ands r0, r3
	lsls r0, r0, #0xc
	ldrh r1, [r1, #2]
	adds r0, r1, r0
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	strh r0, [r2, #0x22]
	bx lr

	thumb_func_start sub_803F5C8
sub_803F5C8: @ 0x0803F5C8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x39
	movs r5, #0
	movs r0, #7
	strb r0, [r1]
	ldr r0, _0803F63C @ =ProcScr_MuDeathFade
	adds r1, r4, #0
	bl SpawnProc
	str r4, [r0, #0x54]
	adds r0, #0x64
	movs r3, #0
	movs r1, #0x20
	strh r1, [r0]
	ldr r1, _0803F640 @ =gDispIo
	mov ip, r1
	mov r2, ip
	adds r2, #0x3c
	movs r1, #0x3f
	ldrb r6, [r2]
	ands r1, r6
	strb r1, [r2]
	ldrh r0, [r0]
	lsrs r1, r0, #1
	mov r0, ip
	adds r0, #0x44
	strb r1, [r0]
	mov r1, ip
	adds r1, #0x45
	movs r0, #0x10
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x46
	strb r3, [r0]
	ldr r0, [r4, #0x30]
	strh r5, [r0, #0x18]
	ldr r0, [r4, #0x30]
	strh r5, [r0, #0x1a]
	adds r0, r4, #0
	movs r1, #0
	bl sub_803F554
	ldr r1, [r4, #0x30]
	movs r0, #0xd
	strh r0, [r1, #0x1e]
	ldr r0, _0803F644 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt _0803F636
	movs r0, #0xd6
	bl m4aSongNumStart
_0803F636:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803F63C: .4byte ProcScr_MuDeathFade
_0803F640: .4byte gDispIo
_0803F644: .4byte gPlaySt

	thumb_func_start sub_803F648
sub_803F648: @ 0x0803F648
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r1, [r5, #0x30]
	ldr r0, [r5, #0x34]
	ldrh r0, [r0, #2]
	movs r2, #0xd0
	lsls r2, r2, #7
	adds r0, r0, r2
	strh r0, [r1, #0x22]
	ldr r0, [r5, #0x34]
	ldrb r0, [r0, #1]
	adds r0, #0x10
	lsls r0, r0, #5
	ldr r1, _0803F68C @ =gPal
	adds r0, r0, r1
	movs r1, #0xb0
	lsls r1, r1, #2
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, _0803F690 @ =gUnk_Sio_085CAE6C
	lsls r4, r4, #2
	adds r4, r4, r0
	ldr r0, [r4]
	movs r1, #0x16
	movs r2, #8
	adds r3, r5, #0
	bl StartPalFade
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803F68C: .4byte gPal
_0803F690: .4byte gUnk_Sio_085CAE6C

	thumb_func_start sub_803F694
sub_803F694: @ 0x0803F694
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x34]
	ldrb r0, [r0, #1]
	adds r0, #0x10
	lsls r0, r0, #5
	ldr r1, _0803F6C0 @ =gPal
	adds r0, r0, r1
	movs r1, #0x16
	movs r2, #8
	adds r3, r4, #0
	bl StartPalFade
	ldr r0, _0803F6C4 @ =ProcScr_MuRestorePalInfo
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x54]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803F6C0: .4byte gPal
_0803F6C4: .4byte ProcScr_MuRestorePalInfo

	thumb_func_start sub_803F6C8
sub_803F6C8: @ 0x0803F6C8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0803F708 @ =gUnk_082DD268
	ldr r1, _0803F70C @ =0x06004400
	bl Decompress
	ldr r0, _0803F710 @ =gUnk_082DD4C8
	movs r1, #0x60
	movs r2, #0x20
	bl ApplyPaletteExt
	adds r1, r4, #0
	adds r1, #0x40
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x41
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0803F700
	ldr r2, [r4, #0x34]
	lsls r2, r2, #3
	movs r0, #0x7f
	movs r1, #2
	bl StartPlayMuStepSe
_0803F700:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803F708: .4byte gUnk_082DD268
_0803F70C: .4byte 0x06004400
_0803F710: .4byte gUnk_082DD4C8

	thumb_func_start sub_803F714
sub_803F714: @ 0x0803F714
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r0, _0803F7C8 @ =gBg2Tm
	ldr r1, [r7, #0x34]
	subs r1, #1
	ldr r2, [r7, #0x38]
	subs r2, #3
	ldr r3, _0803F7CC @ =0x00003220
	movs r4, #4
	str r4, [sp]
	movs r4, #6
	str r4, [sp, #4]
	ldr r4, _0803F7D0 @ =gUnk_082DD4E8
	str r4, [sp, #8]
	ldr r6, _0803F7D4 @ =gUnk_Sio_085CAE9C
	adds r5, r7, #0
	adds r5, #0x40
	ldrb r4, [r5]
	adds r4, r4, r6
	ldrb r4, [r4]
	str r4, [sp, #0xc]
	bl sub_8014F70
	movs r0, #4
	bl EnableBgSync
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	adds r6, r0, r6
	ldrb r0, [r6]
	cmp r0, #0xff
	bne _0803F75E
	adds r0, r7, #0
	bl Proc_Break
_0803F75E:
	ldr r3, _0803F7D8 @ =gDispIo
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	ldrb r2, [r3, #0xc]
	ands r0, r2
	strb r0, [r3, #0xc]
	adds r0, r1, #0
	ldrb r4, [r3, #0x10]
	ands r0, r4
	strb r0, [r3, #0x10]
	ldrb r0, [r3, #0x14]
	ands r1, r0
	strb r1, [r3, #0x14]
	movs r0, #3
	ldrb r1, [r3, #0x18]
	orrs r0, r1
	strb r0, [r3, #0x18]
	adds r2, r3, #0
	adds r2, #0x3c
	ldr r0, _0803F7DC @ =0x0000FFE0
	ldrh r4, [r3, #0x3c]
	ands r0, r4
	movs r1, #4
	orrs r0, r1
	ldr r1, _0803F7E0 @ =0x0000E0FF
	ands r0, r1
	movs r4, #0xd8
	lsls r4, r4, #5
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r3, #0x3c]
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x44
	movs r1, #0xc
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r1, r3, #0
	adds r1, #0x46
	movs r0, #0
	strb r0, [r1]
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803F7C8: .4byte gBg2Tm
_0803F7CC: .4byte 0x00003220
_0803F7D0: .4byte gUnk_082DD4E8
_0803F7D4: .4byte gUnk_Sio_085CAE9C
_0803F7D8: .4byte gDispIo
_0803F7DC: .4byte 0x0000FFE0
_0803F7E0: .4byte 0x0000E0FF

	thumb_func_start sub_803F7E4
sub_803F7E4: @ 0x0803F7E4
	push {lr}
	ldr r0, _0803F818 @ =gBg2Tm
	movs r1, #0
	bl TmFill
	movs r0, #4
	bl EnableBgSync
	ldr r3, _0803F81C @ =gDispIo
	adds r1, r3, #0
	adds r1, #0x3c
	movs r0, #0x3f
	ldrb r2, [r1]
	ands r0, r2
	strb r0, [r1]
	adds r1, #8
	movs r2, #0
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x45
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0803F818: .4byte gBg2Tm
_0803F81C: .4byte gDispIo

	thumb_func_start sub_803F820
sub_803F820: @ 0x0803F820
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0803F84C @ =gUnk_Sio_085CAEB4
	movs r1, #2
	bl SpawnProc
	ldr r2, [r4, #0x2c]
	movs r1, #0xe
	ldrsb r1, [r2, r1]
	lsls r1, r1, #1
	str r1, [r0, #0x34]
	movs r1, #0xf
	ldrsb r1, [r2, r1]
	lsls r1, r1, #1
	str r1, [r0, #0x38]
	adds r4, #0x41
	ldrb r1, [r4]
	adds r0, #0x41
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803F84C: .4byte gUnk_Sio_085CAEB4

	thumb_func_start sub_803F850
sub_803F850: @ 0x0803F850
	push {lr}
	ldr r0, [r0, #0x30]
	movs r1, #0
	bl sub_803F648
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_803F860
sub_803F860: @ 0x0803F860
	push {lr}
	ldr r0, [r0, #0x30]
	bl HideMu
	pop {r0}
	bx r0

	thumb_func_start sub_803F86C
sub_803F86C: @ 0x0803F86C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x30]
	ldr r1, [r4, #0x34]
	lsls r1, r1, #4
	ldr r2, [r4, #0x38]
	lsls r2, r2, #4
	bl SetMuScreenPosition
	ldr r1, [r4, #0x2c]
	ldr r0, [r4, #0x34]
	strb r0, [r1, #0xe]
	ldr r1, [r4, #0x2c]
	ldr r0, [r4, #0x38]
	strb r0, [r1, #0xf]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_803F890
sub_803F890: @ 0x0803F890
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x3c]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0803F8A4
	ldr r0, [r4, #0x30]
	bl SetMuFacing
_0803F8A4:
	ldr r0, [r4, #0x30]
	bl ShowMu
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_803F8B0
sub_803F8B0: @ 0x0803F8B0
	push {lr}
	ldr r0, [r0, #0x30]
	bl sub_803F694
	pop {r0}
	bx r0

	thumb_func_start sub_803F8BC
sub_803F8BC: @ 0x0803F8BC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0803F8DC @ =gUnk_Sio_085CAEB4
	bl Proc_Find
	rsbs r1, r0, #0
	orrs r1, r0
	cmp r1, #0
	blt _0803F8D4
	adds r0, r4, #0
	bl Proc_Break
_0803F8D4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803F8DC: .4byte gUnk_Sio_085CAEB4

	thumb_func_start sub_803F8E0
sub_803F8E0: @ 0x0803F8E0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	mov r8, r3
	ldr r0, [sp, #0x1c]
	ldr r1, [sp, #0x20]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r1, #0
	beq _0803F908
	ldr r0, _0803F904 @ =gUnk_Sio_085CAEE4
	bl SpawnProcLocking
	b _0803F910
	.align 2, 0
_0803F904: .4byte gUnk_Sio_085CAEE4
_0803F908:
	ldr r0, _0803F934 @ =gUnk_Sio_085CAEE4
	movs r1, #2
	bl SpawnProc
_0803F910:
	adds r1, r0, #0
	str r5, [r1, #0x2c]
	str r6, [r1, #0x30]
	str r7, [r1, #0x34]
	mov r0, r8
	str r0, [r1, #0x38]
	ldr r0, [sp, #0x18]
	str r0, [r1, #0x3c]
	adds r0, r1, #0
	adds r0, #0x41
	strb r4, [r0]
	adds r0, r1, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0803F934: .4byte gUnk_Sio_085CAEE4

	thumb_func_start sub_803F938
sub_803F938: @ 0x0803F938
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	mov r8, r3
	ldr r0, [sp, #0x1c]
	ldr r1, [sp, #0x20]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r1, #0
	beq _0803F960
	ldr r0, _0803F95C @ =gUnk_Sio_085CAF5C
	bl SpawnProcLocking
	b _0803F968
	.align 2, 0
_0803F95C: .4byte gUnk_Sio_085CAF5C
_0803F960:
	ldr r0, _0803F98C @ =gUnk_Sio_085CAF5C
	movs r1, #2
	bl SpawnProc
_0803F968:
	adds r1, r0, #0
	str r5, [r1, #0x2c]
	str r6, [r1, #0x30]
	str r7, [r1, #0x34]
	mov r0, r8
	str r0, [r1, #0x38]
	ldr r0, [sp, #0x18]
	str r0, [r1, #0x3c]
	adds r0, r1, #0
	adds r0, #0x41
	strb r4, [r0]
	adds r0, r1, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0803F98C: .4byte gUnk_Sio_085CAF5C

	thumb_func_start sub_803F990
sub_803F990: @ 0x0803F990
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r2, r1, #0
	ldr r3, _0803F9B0 @ =gUnk_Sio_0810F434
	movs r0, #0
	str r0, [sp]
	movs r0, #4
	adds r1, r4, #0
	bl PutSprite
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803F9B0: .4byte gUnk_Sio_0810F434

	thumb_func_start sub_803F9B4
sub_803F9B4: @ 0x0803F9B4
	push {lr}
	ldr r2, [r0, #0x2c]
	ldr r1, [r0, #0x30]
	adds r0, r2, #0
	bl sub_803F990
	pop {r0}
	bx r0

	thumb_func_start sub_803F9C4
sub_803F9C4: @ 0x0803F9C4
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r6, r0, #0
	mov r8, r1
	adds r5, r2, #0
	ldr r4, _0803F9F0 @ =gUnk_Sio_085CAF9C
	adds r0, r4, #0
	bl Proc_EndEach
	adds r0, r4, #0
	adds r1, r5, #0
	bl SpawnProc
	str r6, [r0, #0x2c]
	mov r1, r8
	str r1, [r0, #0x30]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803F9F0: .4byte gUnk_Sio_085CAF9C

	thumb_func_start sub_803F9F4
sub_803F9F4: @ 0x0803F9F4
	push {r4, lr}
	ldr r4, _0803FA10 @ =gUnk_Sio_085CAF9C
	adds r0, r4, #0
	bl Proc_Find
	cmp r0, #0
	beq _0803FA08
	adds r0, r4, #0
	bl Proc_EndEach
_0803FA08:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803FA10: .4byte gUnk_Sio_085CAF9C

	thumb_func_start sub_803FA14
sub_803FA14: @ 0x0803FA14
	push {r4, lr}
	sub sp, #0x18
	ldr r1, _0803FA90 @ =gUnk_Sio_0810F442
	mov r0, sp
	movs r2, #0x18
	bl memcpy
	mov r0, sp
	bl InitBgs
	ldr r3, _0803FA94 @ =gDispIo
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
	bl ApplySystemGraphics
	ldr r0, _0803FA98 @ =gUnk_08109A80
	movs r1, #0xc0
	lsls r1, r1, #2
	movs r2, #0x40
	bl ApplyPaletteExt
	ldr r4, _0803FA9C @ =gUnk_08336D5C
	movs r0, #3
	bl GetBgChrOffset
	adds r1, r0, #0
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	adds r0, r4, #0
	bl Decompress
	ldr r0, _0803FAA0 @ =gUnk_08109C80
	movs r1, #0xe0
	lsls r1, r1, #1
	movs r2, #0x40
	bl ApplyPaletteExt
	add sp, #0x18
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803FA90: .4byte gUnk_Sio_0810F442
_0803FA94: .4byte gDispIo
_0803FA98: .4byte gUnk_08109A80
_0803FA9C: .4byte gUnk_08336D5C
_0803FAA0: .4byte gUnk_08109C80

	thumb_func_start sub_803FAA4
sub_803FAA4: @ 0x0803FAA4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	ldr r4, _0803FAF8 @ =gBg3Tm
	ldr r0, _0803FAFC @ =gUnk_086773D8
	bl Proc_EndEach
	movs r2, #0
	movs r0, #0x14
	subs r0, r0, r5
	lsls r0, r0, #5
	cmp r2, r0
	bge _0803FAD0
	ldr r1, _0803FB00 @ =0xFFFFE000
	adds r3, r1, #0
	adds r1, r0, #0
_0803FAC4:
	adds r0, r2, r3
	strh r0, [r4]
	adds r4, #2
	adds r2, #1
	cmp r2, r1
	blt _0803FAC4
_0803FAD0:
	movs r2, #0
	lsls r1, r5, #5
	ldr r5, _0803FAFC @ =gUnk_086773D8
	cmp r2, r1
	bge _0803FAEA
	ldr r0, _0803FB04 @ =0xFFFFF000
	adds r3, r0, #0
_0803FADE:
	adds r0, r2, r3
	strh r0, [r4]
	adds r4, #2
	adds r2, #1
	cmp r2, r1
	blt _0803FADE
_0803FAEA:
	adds r0, r5, #0
	adds r1, r6, #0
	bl SpawnProc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803FAF8: .4byte gBg3Tm
_0803FAFC: .4byte gUnk_086773D8
_0803FB00: .4byte 0xFFFFE000
_0803FB04: .4byte 0xFFFFF000

	thumb_func_start sub_803FB08
sub_803FB08: @ 0x0803FB08
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x28
	mov r8, r0
	ldr r1, _0803FB64 @ =gUnk_Sio_0810F45A
	mov r0, sp
	movs r2, #0x28
	bl memcpy
	ldr r4, _0803FB68 @ =gBg3Tm
	ldr r0, _0803FB6C @ =gUnk_086773D8
	bl Proc_EndEach
	movs r2, #0
	movs r6, #0xf
	ldr r5, _0803FB70 @ =0x0000027F
_0803FB2A:
	adds r0, r2, #0
	adds r3, r4, #0
	adds r4, r3, #2
	cmp r2, #0
	bge _0803FB36
	adds r0, #0x1f
_0803FB36:
	asrs r0, r0, #5
	lsls r0, r0, #1
	mov r7, sp
	adds r1, r7, r0
	adds r0, r6, #0
	ldrh r1, [r1]
	ands r0, r1
	lsls r0, r0, #0xc
	adds r0, r2, r0
	strh r0, [r3]
	adds r2, #1
	cmp r2, r5
	ble _0803FB2A
	ldr r0, _0803FB6C @ =gUnk_086773D8
	mov r1, r8
	bl SpawnProc
	add sp, #0x28
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803FB64: .4byte gUnk_Sio_0810F45A
_0803FB68: .4byte gBg3Tm
_0803FB6C: .4byte gUnk_086773D8
_0803FB70: .4byte 0x0000027F

	thumb_func_start sub_803FB74
sub_803FB74: @ 0x0803FB74
	push {lr}
	ldr r0, _0803FB80 @ =gUnk_086773D8
	bl Proc_EndEach
	pop {r0}
	bx r0
	.align 2, 0
_0803FB80: .4byte gUnk_086773D8

	thumb_func_start sub_803FB84
sub_803FB84: @ 0x0803FB84
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #5
	mov r8, r2
	cmp r3, #0
	ble _0803FBBA
	movs r7, #0x80
	lsls r7, r7, #3
	adds r4, r3, #0
_0803FB9C:
	mov r2, r8
	cmp r2, #0
	bge _0803FBA4
	adds r2, #3
_0803FBA4:
	lsls r2, r2, #9
	lsrs r2, r2, #0xb
	adds r0, r6, #0
	adds r1, r5, #0
	bl CpuFastSet
	adds r6, r6, r7
	adds r5, r5, r7
	subs r4, #1
	cmp r4, #0
	bne _0803FB9C
_0803FBBA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_803FBC4
sub_803FBC4: @ 0x0803FBC4
	push {r4, r5, r6, lr}
	ldr r0, [r0, #0x58]
	movs r6, #3
	ands r6, r0
	cmp r0, #0
	bge _0803FBD2
	adds r0, #3
_0803FBD2:
	asrs r4, r0, #2
	ldr r0, _0803FC08 @ =gUnk_08106784
	ldr r5, _0803FC0C @ =gBuf
	adds r1, r5, #0
	bl Decompress
	lsls r0, r6, #8
	lsls r4, r4, #0xb
	adds r0, r0, r4
	adds r0, r0, r5
	ldr r1, _0803FC10 @ =0x06014000
	movs r2, #8
	movs r3, #2
	bl sub_803FB84
	ldr r0, _0803FC14 @ =gBg2Tm
	ldr r1, _0803FC18 @ =gUnk_08109D78
	movs r2, #0x80
	lsls r2, r2, #5
	bl TmApplyTsa_t
	movs r0, #4
	bl EnableBgSync
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803FC08: .4byte gUnk_08106784
_0803FC0C: .4byte gBuf
_0803FC10: .4byte 0x06014000
_0803FC14: .4byte gBg2Tm
_0803FC18: .4byte gUnk_08109D78

	thumb_func_start sub_803FC1C
sub_803FC1C: @ 0x0803FC1C
	push {lr}
	sub sp, #4
	ldr r3, _0803FC38 @ =gUnk_Sio_085CAFB4
	movs r0, #0
	str r0, [sp]
	movs r0, #4
	movs r1, #0x28
	movs r2, #8
	bl PutSpriteExt
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_0803FC38: .4byte gUnk_Sio_085CAFB4

	thumb_func_start sub_803FC3C
sub_803FC3C: @ 0x0803FC3C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r4, _0803FC5C @ =gUnk_Sio_085CAFC4
	adds r0, r4, #0
	bl Proc_EndEach
	adds r0, r4, #0
	adds r1, r5, #0
	bl SpawnProc
	str r6, [r0, #0x58]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803FC5C: .4byte gUnk_Sio_085CAFC4

	thumb_func_start sub_803FC60
sub_803FC60: @ 0x0803FC60
	push {lr}
	ldr r0, _0803FC6C @ =gUnk_Sio_085CAFC4
	bl Proc_EndEach
	pop {r0}
	bx r0
	.align 2, 0
_0803FC6C: .4byte gUnk_Sio_085CAFC4

	thumb_func_start sub_803FC70
sub_803FC70: @ 0x0803FC70
	ldr r3, _0803FCB0 @ =gDispIo
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
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	adds r1, #1
	movs r0, #0xf
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x46
	strb r2, [r0]
	ldr r0, _0803FCB4 @ =0x0000FFE0
	ldrh r2, [r3, #0x3c]
	ands r0, r2
	ldr r1, _0803FCB8 @ =0x0000E0FF
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r3, #0x3c]
	bx lr
	.align 2, 0
_0803FCB0: .4byte gDispIo
_0803FCB4: .4byte 0x0000FFE0
_0803FCB8: .4byte 0x0000E0FF

	thumb_func_start sub_803FCBC
sub_803FCBC: @ 0x0803FCBC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _0803FD38 @ =0x00007E08
	mov sb, r0
	ldr r2, [r5, #0x2c]
	ldr r0, [r5, #0x34]
	adds r2, r2, r0
	asrs r2, r2, #1
	ldr r0, [r5, #0x30]
	ldr r1, [r5, #0x38]
	adds r0, r0, r1
	asrs r0, r0, #1
	mov r8, r0
	str r2, [r5, #0x34]
	str r0, [r5, #0x38]
	movs r7, #0
	adds r6, r2, #0
_0803FCE6:
	ldr r4, [r5, #0x40]
	adds r0, r4, #0
	cmp r4, #0
	bge _0803FCF0
	adds r0, r4, #7
_0803FCF0:
	asrs r0, r0, #3
	adds r0, r0, r7
	ldr r1, [r5, #0x3c]
	bl __modsi3
	movs r1, #7
	ands r4, r1
	subs r1, r6, r4
	add r0, sb
	str r0, [sp]
	movs r0, #0xc
	mov r2, r8
	ldr r3, _0803FD3C @ =gUnk_Sio_085CAFE4
	bl PutSprite
	adds r6, #8
	adds r7, #1
	cmp r7, #0x1f
	ble _0803FCE6
	ldr r1, [r5, #0x40]
	adds r1, #1
	str r1, [r5, #0x40]
	ldr r0, [r5, #0x3c]
	lsls r0, r0, #3
	cmp r1, r0
	bne _0803FD28
	movs r0, #0
	str r0, [r5, #0x40]
_0803FD28:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803FD38: .4byte 0x00007E08
_0803FD3C: .4byte gUnk_Sio_085CAFE4

	thumb_func_start sub_803FD40
sub_803FD40: @ 0x0803FD40
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	adds r6, r1, #0
	mov r8, r2
	mov sb, r3
	ldr r0, _0803FDC4 @ =gUnk_081065C8
	ldr r1, _0803FDC8 @ =gBuf
	bl Decompress
	movs r4, #0
	cmp r4, r6
	bge _0803FD84
	ldr r5, _0803FDCC @ =0x06014100
_0803FD60:
	adds r0, r4, #0
	adds r1, r6, #0
	bl __modsi3
	adds r0, r7, r0
	ldrb r0, [r0]
	lsls r0, r0, #5
	ldr r1, _0803FDC8 @ =gBuf
	adds r0, r0, r1
	adds r1, r5, #0
	movs r2, #1
	movs r3, #2
	bl sub_803FB84
	adds r5, #0x20
	adds r4, #1
	cmp r4, r6
	blt _0803FD60
_0803FD84:
	ldr r0, [sp, #0x1c]
	lsls r0, r0, #5
	ldr r1, _0803FDD0 @ =gUnk_08109B00
	adds r0, r0, r1
	movs r1, #0xb8
	lsls r1, r1, #2
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r4, _0803FDD4 @ =gUnk_Sio_085CAFEC
	adds r0, r4, #0
	bl Proc_EndEach
	adds r0, r4, #0
	ldr r1, [sp, #0x20]
	bl SpawnProc
	mov r1, r8
	str r1, [r0, #0x2c]
	str r1, [r0, #0x34]
	mov r1, sb
	str r1, [r0, #0x30]
	str r1, [r0, #0x38]
	str r6, [r0, #0x3c]
	movs r1, #0
	str r1, [r0, #0x40]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803FDC4: .4byte gUnk_081065C8
_0803FDC8: .4byte gBuf
_0803FDCC: .4byte 0x06014100
_0803FDD0: .4byte gUnk_08109B00
_0803FDD4: .4byte gUnk_Sio_085CAFEC

	thumb_func_start sub_803FDD8
sub_803FDD8: @ 0x0803FDD8
	push {lr}
	ldr r2, _0803FE04 @ =gDispIo
	adds r1, r2, #0
	adds r1, #0x3c
	movs r0, #0x3f
	ldrb r3, [r1]
	ands r0, r3
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x44
	movs r1, #0
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r0, _0803FE08 @ =gUnk_Sio_085CAFEC
	bl Proc_EndEach
	pop {r0}
	bx r0
	.align 2, 0
_0803FE04: .4byte gDispIo
_0803FE08: .4byte gUnk_Sio_085CAFEC

	thumb_func_start sub_803FE0C
sub_803FE0C: @ 0x0803FE0C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _0803FE24 @ =gUnk_Sio_085CAFEC
	bl Proc_Find
	str r4, [r0, #0x2c]
	str r5, [r0, #0x30]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803FE24: .4byte gUnk_Sio_085CAFEC

	thumb_func_start sub_803FE28
sub_803FE28: @ 0x0803FE28
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _0803FE44 @ =gUnk_Sio_085CAFEC
	bl Proc_Find
	str r4, [r0, #0x34]
	str r4, [r0, #0x2c]
	str r5, [r0, #0x38]
	str r5, [r0, #0x30]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803FE44: .4byte gUnk_Sio_085CAFEC

	thumb_func_start sub_803FE48
sub_803FE48: @ 0x0803FE48
	push {lr}
	lsls r0, r0, #5
	ldr r1, _0803FE60 @ =gUnk_08109B00
	adds r0, r0, r1
	movs r1, #0xb8
	lsls r1, r1, #2
	movs r2, #0x20
	bl ApplyPaletteExt
	pop {r0}
	bx r0
	.align 2, 0
_0803FE60: .4byte gUnk_08109B00

	thumb_func_start sub_803FE64
sub_803FE64: @ 0x0803FE64
	push {r4, lr}
	sub sp, #0x20
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r1, _0803FEA8 @ =gUnk_Sio_0810F50A
	mov r0, sp
	movs r2, #0x20
	bl memcpy
	ldr r0, _0803FEAC @ =0x0203C9D0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0803FEA0
	mov r1, sp
	adds r0, r1, r4
	ldrb r2, [r0]
	adds r2, #0x10
	ldr r3, _0803FEB0 @ =gPal
	lsls r0, r2, #0xa
	lsls r1, r2, #5
	adds r0, r0, r1
	adds r0, r0, r2
	movs r1, #0x9f
	lsls r1, r1, #2
	adds r3, r3, r1
	strh r0, [r3]
	bl EnablePalSync
_0803FEA0:
	add sp, #0x20
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803FEA8: .4byte gUnk_Sio_0810F50A
_0803FEAC: .4byte 0x0203C9D0
_0803FEB0: .4byte gPal

	thumb_func_start sub_803FEB4
sub_803FEB4: @ 0x0803FEB4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, _0803FFF8 @ =0x000082DA
	mov r8, r0
	movs r2, #0x2a
	ldrsh r1, [r7, r2]
	movs r3, #0x2c
	ldrsh r2, [r7, r3]
	ldr r3, _0803FFFC @ =gUnk_Sio_085CB00C
	adds r0, r7, #0
	adds r0, #0x2f
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r3, [r0]
	ldr r4, _08040000 @ =gUnk_Sio_0810F4C8
	adds r5, r7, #0
	adds r5, #0x2e
	ldrb r6, [r5]
	lsls r0, r6, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #4
	bl PutSprite
	ldrb r5, [r5]
	cmp r5, #2
	bne _0803FEFE
	adds r0, r7, #0
	adds r0, #0x30
	ldrb r0, [r0]
	bl sub_803FE64
_0803FEFE:
	adds r2, r7, #0
	adds r2, #0x30
	ldrb r0, [r2]
	adds r0, #1
	movs r1, #0x1f
	ands r0, r1
	strb r0, [r2]
	movs r0, #0x81
	lsls r0, r0, #1
	ldrh r1, [r7, #0x2e]
	cmp r1, r0
	bne _0803FFEC
	ldrh r1, [r7, #0x3a]
	ldrh r2, [r7, #0x36]
	adds r0, r1, r2
	strh r0, [r7, #0x36]
	ldrh r2, [r7, #0x3c]
	ldrh r3, [r7, #0x38]
	adds r0, r2, r3
	strh r0, [r7, #0x38]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble _0803FF32
	subs r0, r1, #1
	strh r0, [r7, #0x3a]
_0803FF32:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble _0803FF3E
	subs r0, r2, #1
	strh r0, [r7, #0x3c]
_0803FF3E:
	bl GetGameTime
	movs r1, #3
	ands r1, r0
	cmp r1, #0
	bne _0803FF66
	ldrh r1, [r7, #0x32]
	movs r6, #0x32
	ldrsh r0, [r7, r6]
	cmp r0, #0
	bge _0803FF58
	adds r0, r1, #1
	strh r0, [r7, #0x32]
_0803FF58:
	ldrh r1, [r7, #0x34]
	movs r2, #0x34
	ldrsh r0, [r7, r2]
	cmp r0, #0x34
	ble _0803FF66
	subs r0, r1, #1
	strh r0, [r7, #0x34]
_0803FF66:
	movs r3, #0x2a
	ldrsh r5, [r7, r3]
	movs r6, #0x32
	ldrsh r0, [r7, r6]
	adds r0, #0x3b
	adds r5, r5, r0
	movs r0, #0x2c
	ldrsh r4, [r7, r0]
	adds r4, #8
	ldr r6, _08040004 @ =Sprite_8x16
	ldrh r1, [r7, #0x36]
	lsrs r0, r1, #5
	movs r1, #6
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r0, r8
	str r0, [sp]
	movs r0, #4
	adds r1, r5, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl PutSprite
	movs r2, #0x2a
	ldrsh r5, [r7, r2]
	movs r3, #0x34
	ldrsh r0, [r7, r3]
	adds r0, #0x3b
	adds r5, r5, r0
	movs r6, #0x2c
	ldrsh r4, [r7, r6]
	adds r4, #8
	ldr r6, _08040008 @ =Sprite_8x16_HFlipped
	ldrh r1, [r7, #0x38]
	lsrs r0, r1, #5
	movs r1, #6
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r0, r8
	str r0, [sp]
	movs r0, #4
	adds r1, r5, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl PutSprite
	movs r2, #0x2a
	ldrsh r1, [r7, r2]
	adds r1, #0x40
	movs r3, #0x2c
	ldrsh r2, [r7, r3]
	adds r2, #8
	ldr r3, _0804000C @ =gUnk_Sio_085CB020
	ldr r0, _08040010 @ =0x0203C618
	ldrb r0, [r0, #5]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r3, [r0]
	movs r0, #0
	str r0, [sp]
	movs r0, #4
	bl PutSpriteExt
_0803FFEC:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803FFF8: .4byte 0x000082DA
_0803FFFC: .4byte gUnk_Sio_085CB00C
_08040000: .4byte gUnk_Sio_0810F4C8
_08040004: .4byte Sprite_8x16
_08040008: .4byte Sprite_8x16_HFlipped
_0804000C: .4byte gUnk_Sio_085CB020
_08040010: .4byte 0x0203C618

	thumb_func_start sub_8040014
sub_8040014: @ 0x08040014
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	mov r8, r0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r2, r3, #0
	ldr r6, [sp, #0x18]
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	ldr r0, _08040080 @ =gUnk_Sio_085CB02C
	mov r1, r8
	str r2, [sp]
	bl SpawnProc
	mov r8, r0
	movs r3, #0
	movs r1, #0
	strh r4, [r0, #0x2a]
	strh r5, [r0, #0x2c]
	adds r0, #0x2e
	strb r6, [r0]
	adds r0, #1
	ldr r2, [sp]
	strb r2, [r0]
	mov r0, r8
	strh r1, [r0, #0x32]
	movs r0, #0x34
	mov r2, r8
	strh r0, [r2, #0x34]
	strh r1, [r2, #0x38]
	strh r1, [r2, #0x36]
	movs r0, #4
	strh r0, [r2, #0x3c]
	strh r0, [r2, #0x3a]
	mov r0, r8
	adds r0, #0x3e
	strb r3, [r0]
	subs r0, #0xe
	strb r3, [r0]
	mov r0, r8
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08040080: .4byte gUnk_Sio_085CB02C

	thumb_func_start sub_8040084
sub_8040084: @ 0x08040084
	push {r4, lr}
	ldr r4, [sp, #8]
	strh r1, [r0, #0x32]
	strh r2, [r0, #0x34]
	strh r3, [r0, #0x3a]
	strh r4, [r0, #0x3c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8040098
sub_8040098: @ 0x08040098
	strh r1, [r0, #0x2a]
	strh r2, [r0, #0x2c]
	bx lr
	.align 2, 0

	thumb_func_start sub_80400A0
sub_80400A0: @ 0x080400A0
	push {r4, lr}
	sub sp, #0x20
	ldr r4, _080400E8 @ =gUnk_08109BC0
	ldr r1, _080400EC @ =gUnk_Sio_0810F50A
	mov r0, sp
	movs r2, #0x20
	bl memcpy
	ldr r0, _080400F0 @ =0x0203C9D0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _080400DE
	bl GetGameTime
	movs r1, #0x3f
	ands r1, r0
	asrs r1, r1, #1
	mov r2, sp
	adds r0, r2, r1
	ldr r1, _080400F4 @ =gPal
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	ldr r2, _080400F8 @ =0x0000033E
	adds r1, r1, r2
	strh r0, [r1]
	bl EnablePalSync
_080400DE:
	add sp, #0x20
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080400E8: .4byte gUnk_08109BC0
_080400EC: .4byte gUnk_Sio_0810F50A
_080400F0: .4byte 0x0203C9D0
_080400F4: .4byte gPal
_080400F8: .4byte 0x0000033E

	thumb_func_start sub_80400FC
sub_80400FC: @ 0x080400FC
	push {r4, lr}
	sub sp, #0x20
	ldr r4, _08040144 @ =gUnk_08109C20
	ldr r1, _08040148 @ =gUnk_Sio_0810F50A
	mov r0, sp
	movs r2, #0x20
	bl memcpy
	ldr r0, _0804014C @ =0x0203C9D0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0804013C
	bl GetGameTime
	movs r1, #0x3f
	ands r1, r0
	asrs r1, r1, #1
	mov r2, sp
	adds r0, r2, r1
	ldr r1, _08040150 @ =gPal
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r2, #0x9f
	lsls r2, r2, #2
	adds r1, r1, r2
	strh r0, [r1]
	bl EnablePalSync
_0804013C:
	add sp, #0x20
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08040144: .4byte gUnk_08109C20
_08040148: .4byte gUnk_Sio_0810F50A
_0804014C: .4byte 0x0203C9D0
_08040150: .4byte gPal

	thumb_func_start sub_8040154
sub_8040154: @ 0x08040154
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r0, _08040194 @ =0x0203C618
	ldrb r0, [r0]
	cmp r0, #1
	beq _0804016C
	b _080402DC
_0804016C:
	adds r0, r7, #0
	adds r0, #0x44
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r2, #0xc0
	lsls r2, r2, #4
	mov r8, r2
	str r0, [sp, #4]
	cmp r1, #0
	beq _08040186
	movs r0, #0x80
	lsls r0, r0, #3
	mov r8, r0
_08040186:
	ldr r3, _08040198 @ =gUnk_Sio_085CB044
	cmp r1, #0
	beq _0804019C
	movs r0, #0x80
	lsls r0, r0, #4
	b _080401A0
	.align 2, 0
_08040194: .4byte 0x0203C618
_08040198: .4byte gUnk_Sio_085CB044
_0804019C:
	movs r0, #0x80
	lsls r0, r0, #3
_080401A0:
	str r0, [sp]
	movs r0, #0xb
	movs r1, #0x50
	movs r2, #0x20
	bl PutSprite
	movs r6, #0
	ldr r0, [r7, #0x2c]
	cmp r6, r0
	bge _08040202
	movs r5, #0x20
_080401B6:
	lsls r1, r6, #1
	adds r0, r7, #0
	adds r0, #0x30
	adds r4, r0, r1
	movs r2, #0
	ldrsh r1, [r4, r2]
	adds r1, #8
	movs r0, #0xf
	ands r0, r6
	lsls r0, r0, #0xc
	add r0, r8
	str r0, [sp]
	movs r0, #4
	adds r2, r5, #0
	ldr r3, _080402BC @ =gUnk_Sio_0810F52A
	bl PutSprite
	adds r0, r7, #0
	adds r0, #0x3a
	adds r0, r0, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _080401F8
	movs r0, #0
	ldrsh r1, [r4, r0]
	adds r1, #8
	mov r2, r8
	str r2, [sp]
	movs r0, #4
	adds r2, r5, #0
	ldr r3, _080402C0 @ =gUnk_Sio_0810F544
	bl PutSprite
_080401F8:
	adds r5, #0x18
	adds r6, #1
	ldr r0, [r7, #0x2c]
	cmp r6, r0
	blt _080401B6
_08040202:
	ldr r0, [r7, #0x40]
	cmp r0, #0
	beq _080402B4
	ldr r0, _080402C4 @ =0x0203C9D0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08040232
	bl GetGameTime
	ldr r2, _080402C8 @ =gPal
	movs r1, #0x3f
	ands r1, r0
	lsrs r1, r1, #2
	lsls r1, r1, #1
	ldr r0, _080402CC @ =gUnk_0831AAFC
	adds r1, r1, r0
	ldrh r0, [r1]
	ldr r1, _080402D0 @ =0x0000031A
	adds r2, r2, r1
	strh r0, [r2]
	bl EnablePalSync
_08040232:
	ldr r0, [r7, #0x40]
	cmp r0, #0xff
	bgt _0804023C
	adds r0, #0x10
	str r0, [r7, #0x40]
_0804023C:
	ldr r4, _080402D4 @ =gSinLut
	movs r2, #0x80
	adds r2, r2, r4
	mov sb, r2
	movs r1, #0
	ldrsh r0, [r2, r1]
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
	ldr r1, [r7, #0x40]
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
	ldr r1, [r7, #0x40]
	bl Div
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	movs r0, #0
	adds r1, r6, #0
	adds r2, r5, #0
	adds r3, r4, #0
	bl SetObjAffine
	ldr r3, _080402D8 @ =gUnk_Sio_0810F55E
	movs r0, #0x80
	lsls r0, r0, #8
	str r0, [sp]
	movs r0, #4
	movs r1, #0x78
	movs r2, #0
	bl PutSprite
_080402B4:
	bl sub_80400FC
	b _0804036A
	.align 2, 0
_080402BC: .4byte gUnk_Sio_0810F52A
_080402C0: .4byte gUnk_Sio_0810F544
_080402C4: .4byte 0x0203C9D0
_080402C8: .4byte gPal
_080402CC: .4byte gUnk_0831AAFC
_080402D0: .4byte 0x0000031A
_080402D4: .4byte gSinLut
_080402D8: .4byte gUnk_Sio_0810F55E
_080402DC:
	ldr r3, _08040344 @ =gUnk_Sio_085CB044
	movs r0, #0
	str r0, [sp]
	movs r0, #0xb
	movs r1, #0x50
	movs r2, #0x20
	bl PutSprite
	movs r6, #0
	ldr r0, [r7, #0x2c]
	adds r1, r7, #0
	adds r1, #0x44
	str r1, [sp, #4]
	cmp r6, r0
	bge _08040366
	ldr r2, _08040348 @ =gUnk_Sio_085CB0B4
	mov sl, r2
	movs r0, #8
	rsbs r0, r0, #0
	mov sb, r0
	movs r1, #0x28
	mov r8, r1
_08040308:
	lsls r1, r6, #1
	adds r0, r7, #0
	adds r0, #0x30
	adds r5, r0, r1
	movs r2, #0
	ldrsh r1, [r5, r2]
	adds r4, r7, #0
	adds r4, #0x3a
	adds r4, r4, r6
	ldrb r2, [r4]
	lsls r0, r2, #2
	add r0, sl
	ldr r3, [r0]
	movs r0, #0
	str r0, [sp]
	movs r0, #2
	mov r2, r8
	bl PutSprite
	ldrb r0, [r4]
	cmp r0, #0
	beq _0804034C
	ldrh r1, [r5]
	movs r2, #0
	ldrsh r0, [r5, r2]
	cmp r0, #0
	bge _0804035A
	adds r0, r1, #1
	b _08040358
	.align 2, 0
_08040344: .4byte gUnk_Sio_085CB044
_08040348: .4byte gUnk_Sio_085CB0B4
_0804034C:
	ldrh r1, [r5]
	movs r2, #0
	ldrsh r0, [r5, r2]
	cmp r0, sb
	ble _0804035A
	subs r0, r1, #1
_08040358:
	strh r0, [r5]
_0804035A:
	movs r0, #0x10
	add r8, r0
	adds r6, #1
	ldr r0, [r7, #0x2c]
	cmp r6, r0
	blt _08040308
_08040366:
	bl sub_80400A0
_0804036A:
	ldr r0, _080403B8 @ =0x0203C618
	movs r1, #0x80
	lsls r1, r1, #4
	mov r8, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0804037E
	movs r2, #0x80
	lsls r2, r2, #3
	mov r8, r2
_0804037E:
	ldr r1, [sp, #4]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	beq _08040390
	movs r0, #0xc0
	movs r1, #0x10
	bl sub_803F990
_08040390:
	ldr r0, [r7, #0x48]
	cmp r0, #0
	blt _080403A8
	adds r2, r0, #0
	adds r2, #8
	ldr r3, _080403BC @ =gUnk_Sio_085CB07A
	mov r0, r8
	str r0, [sp]
	movs r0, #4
	movs r1, #0x50
	bl PutSprite
_080403A8:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080403B8: .4byte 0x0203C618
_080403BC: .4byte gUnk_Sio_085CB07A

	thumb_func_start sub_80403C0
sub_80403C0: @ 0x080403C0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	adds r5, r1, #0
	mov r8, r2
	ldr r4, _08040460 @ =gUnk_Sio_085CB0BC
	adds r0, r4, #0
	bl Proc_EndEach
	adds r0, r4, #0
	adds r1, r6, #0
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x2c]
	adds r1, r4, #0
	adds r1, #0x44
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	str r2, [r4, #0x40]
	subs r0, #2
	str r0, [r4, #0x48]
	movs r3, #0
	adds r5, r4, #0
	adds r5, #0x3a
	ldr r0, _08040464 @ =0x0000FFF8
	mov ip, r0
	adds r2, r4, #0
	adds r2, #0x30
_08040400:
	adds r0, r5, r3
	mov r7, r8
	adds r1, r7, r3
	ldrb r1, [r1]
	strb r1, [r0]
	mov r0, ip
	strh r0, [r2]
	adds r2, #2
	adds r3, #1
	cmp r3, #4
	ble _08040400
	ldr r2, [r6, #0x38]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r6, #0
	adds r0, #0x4a
	ldrb r0, [r0]
	adds r0, #0x28
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0xe0
	movs r1, #0x28
	movs r3, #6
	bl sub_8040A80
	adds r0, r6, #0
	adds r0, #0x48
	ldrb r0, [r0]
	lsls r0, r0, #4
	movs r1, #0x28
	subs r1, r1, r0
	ldr r0, [r6, #0x38]
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0x98
	movs r2, #0x88
	movs r3, #0x27
	bl sub_80404E8
	adds r0, r4, #0
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08040460: .4byte gUnk_Sio_085CB0BC
_08040464: .4byte 0x0000FFF8

	thumb_func_start sub_8040468
sub_8040468: @ 0x08040468
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0
	mov r8, r0
	b _080404D0
_0804047C:
	mov r1, r8
	lsls r0, r1, #4
	ldr r1, [r4, #0x30]
	adds r5, r1, r0
	ldr r0, [r4, #0x38]
	movs r1, #1
	add r1, r8
	mov sl, r1
	cmp r5, r0
	bge _080404CE
	ldr r0, [r4, #0x34]
	cmp r5, r0
	ble _080404CE
	movs r6, #0
	mov r0, r8
	lsls r0, r0, #2
	mov sb, r0
	movs r7, #0
_080404A0:
	mov r0, sb
	add r0, r8
	adds r0, r0, r6
	adds r0, #1
	bl GetUnit
	adds r2, r0, #0
	ldr r0, [r2]
	cmp r0, #0
	beq _080404C6
	ldr r1, [r4, #0x2c]
	adds r1, r1, r7
	str r2, [sp]
	movs r0, #4
	adds r2, r5, #0
	movs r3, #0x80
	lsls r3, r3, #3
	bl PutUnitSpriteExt
_080404C6:
	adds r7, #0xe
	adds r6, #1
	cmp r6, #4
	ble _080404A0
_080404CE:
	mov r8, sl
_080404D0:
	ldr r0, [r4, #0x3c]
	cmp r8, r0
	blt _0804047C
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_80404E8
sub_80404E8: @ 0x080404E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r0
	mov sl, r1
	adds r7, r2, #0
	mov r8, r3
	ldr r6, [sp, #0x20]
	ldr r5, [sp, #0x24]
	ldr r4, _0804052C @ =gUnk_Sio_085CB0D4
	adds r0, r4, #0
	bl Proc_EndEach
	adds r0, r4, #0
	adds r1, r5, #0
	bl SpawnProc
	str r6, [r0, #0x3c]
	mov r1, sb
	str r1, [r0, #0x2c]
	mov r1, sl
	str r1, [r0, #0x30]
	mov r1, r8
	str r1, [r0, #0x34]
	str r7, [r0, #0x38]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804052C: .4byte gUnk_Sio_085CB0D4

	thumb_func_start sub_8040530
sub_8040530: @ 0x08040530
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08040548 @ =gUnk_Sio_085CB0D4
	bl Proc_Find
	ldr r1, [r0, #0x30]
	adds r1, r1, r4
	str r1, [r0, #0x30]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08040548: .4byte gUnk_Sio_085CB0D4

	thumb_func_start sub_804054C
sub_804054C: @ 0x0804054C
	push {r4, r5, r6, lr}
	ldr r5, _08040590 @ =gUnk_08109C00
	ldr r0, _08040594 @ =0x0203C9D0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0804058A
	bl GetGameTime
	adds r2, r0, #0
	movs r0, #0x1f
	ands r2, r0
	asrs r2, r2, #1
	movs r1, #0
	ldr r0, _08040598 @ =gPal
	movs r4, #0xf
	ldr r6, _0804059C @ =0x00000336
	adds r3, r0, r6
_08040572:
	adds r0, r2, r1
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	strh r0, [r3]
	adds r3, #2
	adds r1, #1
	cmp r1, #4
	ble _08040572
	bl EnablePalSync
_0804058A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08040590: .4byte gUnk_08109C00
_08040594: .4byte 0x0203C9D0
_08040598: .4byte gPal
_0804059C: .4byte 0x00000336

	thumb_func_start sub_80405A0
sub_80405A0: @ 0x080405A0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, [r5, #0x14]
	mov r8, r0
	ldr r1, [r5, #0x34]
	ldr r0, [r5, #0x2c]
	adds r1, r1, r0
	asrs r1, r1, #1
	ldr r2, [r5, #0x38]
	ldr r0, [r5, #0x30]
	adds r2, r2, r0
	asrs r2, r2, #1
	str r1, [r5, #0x2c]
	str r2, [r5, #0x30]
	ldr r3, _08040628 @ =gUnk_Sio_085CB0EC
	ldr r0, [r5, #0x3c]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r3, [r0]
	movs r4, #0
	str r4, [sp]
	movs r0, #2
	bl PutSprite
	ldr r1, [r5, #0x40]
	adds r1, #0x60
	ldr r3, _0804062C @ =gUnk_Sio_0810F57C
	str r4, [sp]
	movs r0, #2
	movs r2, #0x30
	bl PutSprite
	ldr r3, _08040630 @ =gUnk_Sio_085CB044
	str r4, [sp]
	movs r0, #2
	movs r1, #0x60
	movs r2, #0x20
	bl PutSprite
	ldr r3, _08040634 @ =gUnk_Sio_0810F52A
	movs r0, #0x80
	lsls r0, r0, #4
	str r0, [sp]
	movs r0, #4
	movs r1, #0x50
	movs r2, #0x20
	bl PutSprite
	ldr r7, _08040638 @ =gUnk_Sio_085CB0F4
	movs r6, #0x48
_0804060A:
	ldr r0, [r5, #0x44]
	cmp r0, r4
	beq _08040614
	cmp r4, #2
	ble _0804063C
_08040614:
	ldr r3, [r7]
	movs r0, #0x80
	lsls r0, r0, #8
	str r0, [sp]
	movs r0, #4
	movs r1, #0xc4
	adds r2, r6, #0
	bl PutSprite
	b _0804064E
	.align 2, 0
_08040628: .4byte gUnk_Sio_085CB0EC
_0804062C: .4byte gUnk_Sio_0810F57C
_08040630: .4byte gUnk_Sio_085CB044
_08040634: .4byte gUnk_Sio_0810F52A
_08040638: .4byte gUnk_Sio_085CB0F4
_0804063C:
	ldr r3, [r7]
	movs r0, #0x80
	lsls r0, r0, #7
	str r0, [sp]
	movs r0, #4
	movs r1, #0xc4
	adds r2, r6, #0
	bl PutSprite
_0804064E:
	adds r7, #4
	adds r6, #0x10
	adds r4, #1
	cmp r4, #4
	ble _0804060A
	mov r0, r8
	adds r0, #0x36
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804066A
	movs r0, #0xc0
	movs r1, #0x10
	bl sub_803F990
_0804066A:
	bl sub_804054C
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_804067C
sub_804067C: @ 0x0804067C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r6, r0, #0
	adds r5, r1, #0
	mov r8, r2
	ldr r4, _080406B4 @ =gUnk_Sio_085CB108
	adds r0, r4, #0
	bl Proc_EndEach
	adds r0, r4, #0
	adds r1, r6, #0
	bl SpawnProc
	str r5, [r0, #0x34]
	str r5, [r0, #0x2c]
	mov r1, r8
	str r1, [r0, #0x38]
	str r1, [r0, #0x30]
	movs r1, #0
	str r1, [r0, #0x3c]
	str r1, [r0, #0x40]
	str r1, [r0, #0x44]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080406B4: .4byte gUnk_Sio_085CB108

	thumb_func_start sub_80406B8
sub_80406B8: @ 0x080406B8
	push {r4, r5, lr}
	ldr r4, [sp, #0xc]
	ldr r5, [sp, #0x10]
	str r1, [r0, #0x34]
	str r2, [r0, #0x38]
	str r4, [r0, #0x3c]
	str r3, [r0, #0x40]
	str r5, [r0, #0x44]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_80406D0
sub_80406D0: @ 0x080406D0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	movs r0, #0x2c
	ldrsh r1, [r5, r0]
	movs r2, #0x2a
	ldrsh r0, [r5, r2]
	adds r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r7, r0, #2
	ldrh r0, [r5, #0x2c]
	strh r0, [r5, #0x2a]
	ldr r0, _08040740 @ =gUnk_Sio_085CB120
	mov r8, r0
	movs r6, #0x30
	movs r4, #2
_080406F6:
	mov r1, r8
	adds r1, #4
	mov r8, r1
	subs r1, #4
	ldm r1!, {r3}
	movs r0, #0
	str r0, [sp]
	movs r0, #2
	movs r1, #0x20
	adds r2, r6, #0
	bl PutSprite
	adds r6, #0x18
	subs r4, #1
	cmp r4, #0
	bge _080406F6
	adds r1, r7, #0
	adds r1, #0x30
	movs r0, #0x20
	bl sub_804163C
	movs r2, #0x2e
	ldrsh r0, [r5, r2]
	movs r2, #0x30
	ldrsh r1, [r5, r2]
	bl sub_80415CC
	movs r0, #0xc0
	movs r1, #0x10
	bl sub_803F990
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08040740: .4byte gUnk_Sio_085CB120

	thumb_func_start sub_8040744
sub_8040744: @ 0x08040744
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, _08040764 @ =gUnk_Sio_085CB12C
	adds r0, r4, #0
	bl Proc_EndEach
	adds r0, r4, #0
	adds r1, r5, #0
	bl SpawnProc
	movs r1, #0
	strh r1, [r0, #0x2a]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08040764: .4byte gUnk_Sio_085CB12C

	thumb_func_start sub_8040768
sub_8040768: @ 0x08040768
	strh r1, [r0, #0x2c]
	strh r2, [r0, #0x2e]
	strh r3, [r0, #0x30]
	bx lr

	thumb_func_start sub_8040770
sub_8040770: @ 0x08040770
	push {lr}
	adds r1, r0, #0
	ldr r2, _0804079C @ =gUnk_08109C00
	ldr r0, _080407A0 @ =0x0203C9D0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08040796
	ldr r0, _080407A4 @ =gPal
	lsls r1, r1, #1
	adds r1, r1, r2
	ldrh r1, [r1]
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r0, r0, r2
	strh r1, [r0]
	bl EnablePalSync
_08040796:
	pop {r0}
	bx r0
	.align 2, 0
_0804079C: .4byte gUnk_08109C00
_080407A0: .4byte 0x0203C9D0
_080407A4: .4byte gPal

	thumb_func_start sub_80407A8
sub_80407A8: @ 0x080407A8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0x4c
	adds r0, r0, r7
	mov r8, r0
	movs r1, #0
	ldrsh r5, [r0, r1]
	lsls r4, r5, #1
	adds r0, r5, #0
	bl sub_8040770
	ldr r0, _08040848 @ =gUnk_Sio_0810F5FC
	adds r4, #1
	lsls r4, r4, #1
	adds r4, r4, r0
	movs r1, #0
	ldrsh r6, [r4, r1]
	ldr r1, [r7, #0x2c]
	subs r1, r1, r6
	lsls r5, r5, #2
	adds r5, r5, r0
	movs r0, #0
	ldrsh r5, [r5, r0]
	ldr r2, [r7, #0x30]
	subs r2, r2, r5
	ldr r3, _0804084C @ =gUnk_Sio_0810F5C4
	movs r4, #0
	str r4, [sp]
	movs r0, #2
	bl PutSprite
	ldr r1, [r7, #0x2c]
	adds r1, r1, r6
	adds r1, #0x10
	ldr r2, [r7, #0x30]
	subs r2, r2, r5
	ldr r3, _08040850 @ =gUnk_Sio_0810F5D2
	str r4, [sp]
	movs r0, #2
	bl PutSprite
	ldr r1, [r7, #0x2c]
	subs r1, r1, r6
	ldr r2, [r7, #0x30]
	adds r2, r2, r5
	ldr r3, _08040854 @ =gUnk_Sio_0810F5E0
	str r4, [sp]
	movs r0, #2
	bl PutSprite
	ldr r1, [r7, #0x2c]
	adds r1, r1, r6
	adds r1, #0x10
	ldr r2, [r7, #0x30]
	adds r2, r2, r5
	ldr r3, _08040858 @ =gUnk_Sio_0810F5EE
	str r4, [sp]
	movs r0, #2
	bl PutSprite
	mov r1, r8
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf
	bne _0804083C
	adds r0, r7, #0
	bl Proc_Break
_0804083C:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08040848: .4byte gUnk_Sio_0810F5FC
_0804084C: .4byte gUnk_Sio_0810F5C4
_08040850: .4byte gUnk_Sio_0810F5D2
_08040854: .4byte gUnk_Sio_0810F5E0
_08040858: .4byte gUnk_Sio_0810F5EE

	thumb_func_start sub_804085C
sub_804085C: @ 0x0804085C
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r0, _0804087C @ =gUnk_Sio_085CB144
	adds r1, r3, #0
	bl SpawnProc
	str r4, [r0, #0x2c]
	str r5, [r0, #0x30]
	adds r0, #0x4c
	movs r1, #0
	strh r1, [r0]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0804087C: .4byte gUnk_Sio_085CB144

	thumb_func_start sub_8040880
sub_8040880: @ 0x08040880
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r0, #0x45
	movs r1, #0
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	subs r0, #7
	ldr r4, [r6, #0x34]
	ldrb r0, [r0]
	muls r0, r4, r0
	lsls r0, r0, #3
	adds r5, r6, #0
	adds r5, #0x3c
	ldrb r1, [r5]
	bl __divsi3
	str r0, [r6, #0x38]
	lsls r4, r4, #0xb
	ldrb r5, [r5]
	lsls r1, r5, #4
	adds r0, r4, #0
	bl __divsi3
	adds r1, r6, #0
	adds r1, #0x42
	strh r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start sub_80408BC
sub_80408BC: @ 0x080408BC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	adds r7, r0, #0
	ldr r0, [r7, #0x2c]
	mov r8, r0
	ldr r1, [r7, #0x30]
	str r1, [sp, #0xc]
	adds r1, #8
	mov sl, r1
	ldr r0, [r7, #0x38]
	asrs r2, r0, #3
	str r2, [sp, #0x10]
	movs r1, #7
	ands r0, r1
	movs r1, #8
	subs r0, r1, r0
	str r0, [sp, #0x14]
	movs r3, #0x3e
	ldrsh r0, [r7, r3]
	adds r1, r7, #0
	adds r1, #0x42
	ldrh r1, [r1]
	muls r0, r1, r0
	asrs r0, r0, #8
	str r0, [sp, #0x18]
	movs r0, #0x3c
	adds r0, r0, r7
	mov ip, r0
	movs r1, #0x3d
	adds r1, r1, r7
	mov sb, r1
	ldrb r2, [r0]
	ldrb r3, [r1]
	cmp r2, r3
	bhi _0804090C
	b _08040A64
_0804090C:
	adds r5, r7, #0
	adds r5, #0x44
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	adds r4, r7, #0
	adds r4, #0x45
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r0, r7, #0
	adds r0, #0x40
	movs r1, #0x3e
	ldrsh r2, [r7, r1]
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r3, r5, #0
	str r0, [sp, #0x2c]
	cmp r2, r1
	bge _0804093A
	ldrb r0, [r3]
	adds r0, #2
	strb r0, [r3]
_0804093A:
	movs r0, #0x3e
	ldrsh r1, [r7, r0]
	ldr r2, [sp, #0x2c]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r1, r0
	ble _0804094E
	ldrb r0, [r4]
	adds r0, #2
	strb r0, [r4]
_0804094E:
	movs r6, #0
	mov r0, ip
	str r0, [sp, #0x28]
	ldr r1, [sp, #0x18]
	add r1, sl
	str r1, [sp, #0x1c]
	ldr r2, [sp, #0x10]
	lsls r2, r2, #3
	str r2, [sp, #0x24]
	ldr r3, [sp, #0xc]
	str r3, [sp, #0x20]
_08040964:
	ldrb r0, [r5]
	cmp r0, #0x30
	bls _0804096E
	movs r0, #0
	strb r0, [r5]
_0804096E:
	lsls r4, r6, #2
	add r4, sp
	adds r4, #4
	ldrb r1, [r5]
	lsrs r0, r1, #3
	movs r1, #6
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [r4]
	adds r5, #1
	adds r6, #1
	cmp r6, #1
	ble _08040964
	movs r2, #0x3e
	ldrsh r0, [r7, r2]
	cmp r0, #0
	beq _080409A6
	mov r2, sl
	subs r2, #9
	ldr r3, _08040A74 @ =gUnk_Sio_085CB164
	ldr r0, [sp, #4]
	str r0, [sp]
	movs r0, #3
	mov r1, r8
	bl PutSprite
_080409A6:
	movs r3, #0x3e
	ldrsh r0, [r7, r3]
	cmp r0, #0
	bge _080409B0
	adds r0, #0xf
_080409B0:
	asrs r0, r0, #4
	mov r1, sb
	ldrb r1, [r1]
	adds r0, r1, r0
	ldr r2, [sp, #0x28]
	ldrb r2, [r2]
	cmp r0, r2
	bge _080409D6
	ldr r2, [r7, #0x34]
	lsls r2, r2, #3
	add r2, sl
	adds r2, #1
	ldr r3, _08040A78 @ =gUnk_Sio_085CB15C
	ldr r0, [sp, #8]
	str r0, [sp]
	movs r0, #3
	mov r1, r8
	bl PutSprite
_080409D6:
	movs r6, #0
	ldr r0, [r7, #0x34]
	cmp r6, r0
	bge _080409FA
	mov r4, sl
	movs r5, #1
_080409E2:
	str r5, [sp]
	movs r0, #2
	mov r1, r8
	adds r2, r4, #0
	ldr r3, _08040A7C @ =gUnk_Sio_085CB16C
	bl PutSprite
	adds r4, #8
	adds r6, #1
	ldr r0, [r7, #0x34]
	cmp r6, r0
	blt _080409E2
_080409FA:
	ldr r3, [sp, #0x10]
	cmp r3, #0
	ble _08040A1C
	ldr r4, [sp, #0x1c]
	movs r5, #0
	adds r6, r3, #0
_08040A06:
	str r5, [sp]
	movs r0, #2
	mov r1, r8
	adds r2, r4, #0
	ldr r3, _08040A7C @ =gUnk_Sio_085CB16C
	bl PutSprite
	adds r4, #8
	subs r6, #1
	cmp r6, #0
	bne _08040A06
_08040A1C:
	ldr r0, [sp, #0x1c]
	ldr r1, [sp, #0x24]
	adds r2, r0, r1
	ldr r3, [sp, #0x14]
	subs r2, r2, r3
	ldr r4, _08040A7C @ =gUnk_Sio_085CB16C
	movs r0, #0
	str r0, [sp]
	movs r0, #2
	mov r1, r8
	adds r3, r4, #0
	bl PutSprite
	movs r5, #2
	str r5, [sp]
	movs r0, #2
	mov r1, r8
	ldr r2, [sp, #0x20]
	adds r3, r4, #0
	bl PutSprite
	movs r1, #0x80
	lsls r1, r1, #6
	add r1, r8
	ldr r2, [r7, #0x34]
	lsls r2, r2, #3
	add r2, sl
	subs r2, #7
	str r5, [sp]
	movs r0, #2
	adds r3, r4, #0
	bl PutSprite
	ldrh r0, [r7, #0x3e]
	ldr r1, [sp, #0x2c]
	strh r0, [r1]
_08040A64:
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08040A74: .4byte gUnk_Sio_085CB164
_08040A78: .4byte gUnk_Sio_085CB15C
_08040A7C: .4byte gUnk_Sio_085CB16C

	thumb_func_start sub_8040A80
sub_8040A80: @ 0x08040A80
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r0
	mov sl, r1
	mov r8, r2
	adds r5, r3, #0
	ldr r6, [sp, #0x20]
	ldr r7, [sp, #0x24]
	mov r0, r8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	ldr r4, _08040AE8 @ =gUnk_Sio_085CB174
	adds r0, r4, #0
	bl Proc_EndEach
	adds r0, r4, #0
	adds r1, r7, #0
	bl SpawnProc
	adds r1, r0, #0
	mov r2, sb
	str r2, [r1, #0x2c]
	mov r0, sl
	str r0, [r1, #0x30]
	lsls r0, r5, #1
	subs r0, #2
	str r0, [r1, #0x34]
	adds r0, r1, #0
	adds r0, #0x3c
	mov r2, r8
	strb r2, [r0]
	adds r0, #1
	strb r5, [r0]
	strh r6, [r1, #0x3e]
	adds r0, #3
	strh r6, [r0]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08040AE8: .4byte gUnk_Sio_085CB174

	thumb_func_start sub_8040AEC
sub_8040AEC: @ 0x08040AEC
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	ldr r0, _08040B40 @ =gUnk_Sio_085CB174
	bl Proc_Find
	adds r6, r0, #0
	cmp r6, #0
	beq _08040B38
	adds r5, r6, #0
	adds r5, #0x3c
	strb r7, [r5]
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r1, #0xff
	ands r0, r1
	strh r0, [r6, #0x3e]
	adds r0, r6, #0
	adds r0, #0x3d
	ldr r4, [r6, #0x34]
	ldrb r0, [r0]
	muls r0, r4, r0
	lsls r0, r0, #3
	ldrb r1, [r5]
	bl __divsi3
	str r0, [r6, #0x38]
	lsls r4, r4, #0xb
	ldrb r5, [r5]
	lsls r1, r5, #4
	adds r0, r4, #0
	bl __divsi3
	adds r1, r6, #0
	adds r1, #0x42
	strh r0, [r1]
_08040B38:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08040B40: .4byte gUnk_Sio_085CB174

	thumb_func_start sub_8040B44
sub_8040B44: @ 0x08040B44
	push {lr}
	ldr r0, _08040B60 @ =gUnk_0810B900
	ldr r1, _08040B64 @ =0x06002000
	bl Decompress
	ldr r0, _08040B68 @ =gPlaySt
	ldrb r0, [r0, #0xf]
	cmp r0, #1
	beq _08040B90
	cmp r0, #1
	bgt _08040B6C
	cmp r0, #0
	beq _08040B76
	b _08040BDA
	.align 2, 0
_08040B60: .4byte gUnk_0810B900
_08040B64: .4byte 0x06002000
_08040B68: .4byte gPlaySt
_08040B6C:
	cmp r0, #2
	beq _08040BA8
	cmp r0, #3
	beq _08040BC8
	b _08040BDA
_08040B76:
	ldr r0, _08040B84 @ =gUnk_0810A62C
	ldr r1, _08040B88 @ =0x06002800
	bl Decompress
	ldr r0, _08040B8C @ =gUnk_0810BA60
	b _08040BB2
	.align 2, 0
_08040B84: .4byte gUnk_0810A62C
_08040B88: .4byte 0x06002800
_08040B8C: .4byte gUnk_0810BA60
_08040B90:
	ldr r0, _08040B9C @ =gUnk_0810AADC
	ldr r1, _08040BA0 @ =0x06002800
	bl Decompress
	ldr r0, _08040BA4 @ =gUnk_0810BAA0
	b _08040BB2
	.align 2, 0
_08040B9C: .4byte gUnk_0810AADC
_08040BA0: .4byte 0x06002800
_08040BA4: .4byte gUnk_0810BAA0
_08040BA8:
	ldr r0, _08040BBC @ =gUnk_0810AF9C
	ldr r1, _08040BC0 @ =0x06002800
	bl Decompress
	ldr r0, _08040BC4 @ =gUnk_0810BA80
_08040BB2:
	movs r1, #0xa0
	movs r2, #0x20
	bl ApplyPaletteExt
	b _08040BDA
	.align 2, 0
_08040BBC: .4byte gUnk_0810AF9C
_08040BC0: .4byte 0x06002800
_08040BC4: .4byte gUnk_0810BA80
_08040BC8:
	ldr r0, _08040BEC @ =gUnk_0810B44C
	ldr r1, _08040BF0 @ =0x06002800
	bl Decompress
	ldr r0, _08040BF4 @ =gUnk_0810BAC0
	movs r1, #0xa0
	movs r2, #0x20
	bl ApplyPaletteExt
_08040BDA:
	ldr r2, _08040BF8 @ =0x03001438
	ldr r1, _08040BFC @ =gPlaySt
	ldrb r0, [r1, #0xf]
	str r0, [r2]
	movs r0, #0
	strb r0, [r1, #0xf]
	pop {r0}
	bx r0
	.align 2, 0
_08040BEC: .4byte gUnk_0810B44C
_08040BF0: .4byte 0x06002800
_08040BF4: .4byte gUnk_0810BAC0
_08040BF8: .4byte 0x03001438
_08040BFC: .4byte gPlaySt

	thumb_func_start sub_8040C00
sub_8040C00: @ 0x08040C00
	push {r4, lr}
	ldr r1, _08040C70 @ =gPlaySt
	ldr r0, _08040C74 @ =0x03001438
	ldr r0, [r0]
	movs r2, #0
	strb r0, [r1, #0xf]
	ldr r3, _08040C78 @ =gDispIo
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrb r1, [r3, #1]
	ands r0, r1
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r3, #1]
	adds r1, r3, #0
	adds r1, #0x3c
	movs r0, #0x3f
	ldrb r4, [r1]
	ands r0, r4
	strb r0, [r1]
	adds r1, #8
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x45
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	ldrb r2, [r3, #0xc]
	ands r0, r2
	strb r0, [r3, #0xc]
	adds r0, r1, #0
	ldrb r4, [r3, #0x10]
	ands r0, r4
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
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08040C70: .4byte gPlaySt
_08040C74: .4byte 0x03001438
_08040C78: .4byte gDispIo

	thumb_func_start sub_8040C7C
sub_8040C7C: @ 0x08040C7C
	push {lr}
	ldr r1, _08040C8C @ =gMpi_MainBgm
	movs r0, #0x22
	bl StartBgm
	pop {r0}
	bx r0
	.align 2, 0
_08040C8C: .4byte gMpi_MainBgm

	thumb_func_start sub_8040C90
sub_8040C90: @ 0x08040C90
	lsls r1, r1, #1
	adds r0, #0x1c
	adds r2, r0, r1
	ldrh r1, [r2]
	cmp r1, #0
	beq _08040CA6
	movs r3, #0xff
	lsls r3, r3, #8
	adds r0, r3, #0
	orrs r1, r0
	strh r1, [r2]
_08040CA6:
	bx lr

	thumb_func_start sub_8040CA8
sub_8040CA8: @ 0x08040CA8
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
_08040CAE:
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_8040C90
	adds r4, #1
	cmp r4, #4
	ble _08040CAE
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_8040CC4
sub_8040CC4: @ 0x08040CC4
	push {r4, r5, r6, lr}
	ldr r5, _08040D08 @ =gUnk_08109BE0
	ldr r0, _08040D0C @ =0x0203C9D0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08040D02
	bl GetGameTime
	adds r2, r0, #0
	movs r0, #0x1f
	ands r2, r0
	asrs r2, r2, #1
	movs r1, #0
	ldr r0, _08040D10 @ =gPal
	movs r4, #0xf
	ldr r6, _08040D14 @ =0x00000322
	adds r3, r0, r6
_08040CEA:
	adds r0, r2, r1
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	strh r0, [r3]
	adds r3, #2
	adds r1, #1
	cmp r1, #0xe
	ble _08040CEA
	bl EnablePalSync
_08040D02:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08040D08: .4byte gUnk_08109BE0
_08040D0C: .4byte 0x0203C9D0
_08040D10: .4byte gPal
_08040D14: .4byte 0x00000322

	thumb_func_start sub_8040D18
sub_8040D18: @ 0x08040D18
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	movs r0, #0
	mov sb, r0
	movs r1, #0
	str r1, [sp, #4]
	mov sl, r1
_08040D30:
	ldr r1, [r7, #0x2c]
	ldr r2, [r7, #0x30]
	ldr r3, [sp, #4]
	adds r2, r2, r3
	movs r0, #0xf
	mov r4, sb
	ands r0, r4
	lsls r0, r0, #0xc
	movs r3, #0x80
	lsls r3, r3, #4
	adds r0, r0, r3
	str r0, [sp]
	movs r0, #4
	ldr r3, _08040EE4 @ =gUnk_Sio_0810F52A
	bl PutSprite
	ldr r4, _08040EE8 @ =gSinLut+0x80
	movs r1, #0
	ldrsh r0, [r4, r1]
	lsls r0, r0, #4
	movs r1, #0x80
	lsls r1, r1, #1
	bl Div
	adds r6, r0, #0
	lsls r6, r6, #0x10
	asrs r6, r6, #0x10
	ldr r2, _08040EEC @ =gSinLut
	movs r3, #0
	ldrsh r0, [r2, r3]
	rsbs r0, r0, #0
	lsls r0, r0, #4
	movs r1, #0x80
	lsls r1, r1, #1
	bl Div
	adds r5, r0, #0
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	ldr r4, _08040EEC @ =gSinLut
	movs r1, #0
	ldrsh r0, [r4, r1]
	lsls r0, r0, #4
	movs r1, #0x80
	lsls r1, r1, #1
	bl Div
	adds r4, r0, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	ldr r2, _08040EE8 @ =gSinLut+0x80
	movs r3, #0
	ldrsh r0, [r2, r3]
	lsls r0, r0, #4
	movs r1, #0x80
	lsls r1, r1, #1
	bl Div
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sb
	adds r1, r6, #0
	adds r2, r5, #0
	adds r3, r4, #0
	bl SetObjAffine
	ldr r1, [r7, #0x38]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08040E5A
	adds r3, r7, #0
	adds r3, #0x3c
	cmp r1, sb
	beq _08040DE0
	mov r4, sl
	adds r1, r3, r4
	ldrh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #1
	cmp r0, r2
	bls _08040DDA
	subs r0, #8
	strh r0, [r1]
_08040DDA:
	ldr r0, [r7, #0x38]
	cmp r0, sb
	bne _08040DF2
_08040DE0:
	mov r4, sl
	adds r2, r3, r4
	ldrh r1, [r2]
	ldr r0, _08040EF0 @ =0x0000014F
	cmp r1, r0
	bhi _08040DF2
	adds r0, r1, #0
	adds r0, #8
	strh r0, [r2]
_08040DF2:
	ldr r1, _08040EE8 @ =gSinLut+0x80
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #4
	add r3, sl
	mov r8, r3
	ldrh r1, [r3]
	bl Div
	adds r6, r0, #0
	lsls r6, r6, #0x10
	asrs r6, r6, #0x10
	ldr r3, _08040EEC @ =gSinLut
	movs r4, #0
	ldrsh r0, [r3, r4]
	rsbs r0, r0, #0
	lsls r0, r0, #4
	mov r2, r8
	ldrh r1, [r2]
	bl Div
	adds r5, r0, #0
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	ldr r3, _08040EEC @ =gSinLut
	movs r4, #0
	ldrsh r0, [r3, r4]
	lsls r0, r0, #4
	mov r2, r8
	ldrh r1, [r2]
	bl Div
	adds r4, r0, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	ldr r3, _08040EE8 @ =gSinLut+0x80
	movs r1, #0
	ldrsh r0, [r3, r1]
	lsls r0, r0, #4
	mov r2, r8
	ldrh r1, [r2]
	bl Div
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	mov r0, sb
	adds r1, r6, #0
	adds r2, r5, #0
	adds r3, r4, #0
	bl SetObjAffine
_08040E5A:
	ldr r1, [r7, #0x2c]
	subs r1, #0x30
	ldr r2, [r7, #0x30]
	ldr r3, [sp, #4]
	adds r2, r2, r3
	ldr r3, _08040EF4 @ =gUnk_Sio_085CB1E4
	mov r4, sb
	lsls r0, r4, #2
	adds r0, r0, r3
	ldr r3, [r0]
	movs r4, #0
	str r4, [sp]
	movs r0, #4
	bl PutSprite
	ldr r0, [sp, #4]
	adds r0, #0x18
	str r0, [sp, #4]
	movs r1, #2
	add sl, r1
	movs r2, #1
	add sb, r2
	mov r3, sb
	cmp r3, #3
	bgt _08040E8E
	b _08040D30
_08040E8E:
	ldr r2, [r7, #0x34]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	beq _08040ED2
	ldr r1, [r7, #0x2c]
	subs r1, #0x40
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	ldr r2, [r7, #0x30]
	adds r2, r2, r0
	adds r2, #8
	ldr r3, _08040EF8 @ =gUnk_Sio_0810F65C
	str r4, [sp]
	movs r0, #4
	bl PutSprite
	ldr r1, [r7, #0x2c]
	subs r1, #0x40
	ldr r2, [r7, #0x34]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	ldr r2, [r7, #0x30]
	adds r2, r2, r0
	adds r2, #0x12
	ldr r3, _08040EFC @ =gUnk_Sio_0810F664
	str r4, [sp]
	movs r0, #4
	bl PutSprite
	bl sub_8040CC4
_08040ED2:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08040EE4: .4byte gUnk_Sio_0810F52A
_08040EE8: .4byte gSinLut+0x80
_08040EEC: .4byte gSinLut
_08040EF0: .4byte 0x0000014F
_08040EF4: .4byte gUnk_Sio_085CB1E4
_08040EF8: .4byte gUnk_Sio_0810F65C
_08040EFC: .4byte gUnk_Sio_0810F664

	thumb_func_start sub_8040F00
sub_8040F00: @ 0x08040F00
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r6, r0, #0
	mov r8, r1
	adds r5, r2, #0
	ldr r4, _08040F4C @ =gUnk_Sio_085CB1F4
	adds r0, r4, #0
	bl Proc_EndEach
	adds r0, r4, #0
	adds r1, r5, #0
	bl SpawnProc
	adds r1, r0, #0
	str r6, [r1, #0x2c]
	mov r0, r8
	str r0, [r1, #0x30]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r1, #0x34]
	str r0, [r1, #0x38]
	movs r3, #0x80
	lsls r3, r3, #1
	movs r2, #3
	adds r0, r1, #0
	adds r0, #0x42
_08040F36:
	strh r3, [r0]
	subs r0, #2
	subs r2, #1
	cmp r2, #0
	bge _08040F36
	adds r0, r1, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08040F4C: .4byte gUnk_Sio_085CB1F4

	thumb_func_start sub_8040F50
sub_8040F50: @ 0x08040F50
	push {lr}
	ldr r0, _08040F5C @ =gUnk_Sio_085CB1F4
	bl Proc_EndEach
	pop {r0}
	bx r0
	.align 2, 0
_08040F5C: .4byte gUnk_Sio_085CB1F4

	thumb_func_start sub_8040F60
sub_8040F60: @ 0x08040F60
	push {lr}
	ldr r0, _08040F6C @ =gUnk_Sio_085CB1F4
	bl Proc_Find
	pop {r1}
	bx r1
	.align 2, 0
_08040F6C: .4byte gUnk_Sio_085CB1F4

	thumb_func_start sub_8040F70
sub_8040F70: @ 0x08040F70
	push {r4, r5, lr}
	ldr r5, _08040FB4 @ =gUnk_08109BE0
	ldr r0, _08040FB8 @ =0x0203C9D0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08040FAE
	bl GetGameTime
	adds r2, r0, #0
	movs r0, #0x1f
	ands r2, r0
	asrs r2, r2, #1
	movs r1, #0
	ldr r0, _08040FBC @ =gPal
	movs r4, #0xf
	adds r3, r0, #0
	adds r3, #0x42
_08040F96:
	adds r0, r2, r1
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	strh r0, [r3]
	adds r3, #2
	adds r1, #1
	cmp r1, #0xe
	ble _08040F96
	bl EnablePalSync
_08040FAE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08040FB4: .4byte gUnk_08109BE0
_08040FB8: .4byte 0x0203C9D0
_08040FBC: .4byte gPal

	thumb_func_start sub_8040FC0
sub_8040FC0: @ 0x08040FC0
	push {r4, r5, r6, lr}
	ldr r5, _08041004 @ =gUnk_08109BE0
	ldr r0, _08041008 @ =0x0203C9D0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _08040FFE
	bl GetGameTime
	adds r2, r0, #0
	movs r0, #0x1f
	ands r2, r0
	asrs r2, r2, #1
	movs r1, #0
	ldr r0, _0804100C @ =gPal
	movs r4, #0xf
	ldr r6, _08041010 @ =0x00000262
	adds r3, r0, r6
_08040FE6:
	adds r0, r2, r1
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	strh r0, [r3]
	adds r3, #2
	adds r1, #1
	cmp r1, #0xe
	ble _08040FE6
	bl EnablePalSync
_08040FFE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08041004: .4byte gUnk_08109BE0
_08041008: .4byte 0x0203C9D0
_0804100C: .4byte gPal
_08041010: .4byte 0x00000262

	thumb_func_start sub_8041014
sub_8041014: @ 0x08041014
	ldr r3, _08041054 @ =gDispIo
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
	movs r2, #0
	movs r0, #8
	strb r0, [r1]
	adds r1, #1
	movs r0, #0xc
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x46
	strb r2, [r0]
	ldr r0, _08041058 @ =0x0000FFE0
	ldrh r2, [r3, #0x3c]
	ands r0, r2
	ldr r1, _0804105C @ =0x0000E0FF
	ands r0, r1
	movs r2, #0xe0
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r3, #0x3c]
	bx lr
	.align 2, 0
_08041054: .4byte gDispIo
_08041058: .4byte 0x0000FFE0
_0804105C: .4byte 0x0000E0FF

	thumb_func_start sub_8041060
sub_8041060: @ 0x08041060
	push {lr}
	sub sp, #4
	adds r1, r0, #0
	ldr r2, [r1, #0x30]
	adds r0, r2, #0
	subs r0, #0x1f
	cmp r0, #0x79
	bhi _08041082
	ldr r1, [r1, #0x2c]
	ldr r3, _08041088 @ =gUnk_Sio_0810F672
	movs r0, #0
	str r0, [sp]
	movs r0, #4
	bl PutSprite
	bl sub_8040FC0
_08041082:
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_08041088: .4byte gUnk_Sio_0810F672

	thumb_func_start sub_804108C
sub_804108C: @ 0x0804108C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r6, r0, #0
	mov r8, r1
	adds r5, r2, #0
	ldr r4, _080410B8 @ =gUnk_Sio_085CB204
	adds r0, r4, #0
	bl Proc_EndEach
	adds r0, r4, #0
	adds r1, r5, #0
	bl SpawnProc
	str r6, [r0, #0x2c]
	mov r1, r8
	str r1, [r0, #0x30]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080410B8: .4byte gUnk_Sio_085CB204

	thumb_func_start sub_80410BC
sub_80410BC: @ 0x080410BC
	push {r4, lr}
	ldr r0, _080410E8 @ =gUnk_0832A29C
	ldr r4, _080410EC @ =gUnk_Sio_0200152C
	adds r1, r4, #0
	bl Decompress
	ldr r1, _080410F0 @ =0x06016800
	adds r0, r4, #0
	movs r2, #6
	movs r3, #4
	bl sub_803FB84
	ldr r0, _080410F4 @ =gUnk_0832BDE8
	movs r1, #0x90
	lsls r1, r1, #2
	movs r2, #0x20
	bl ApplyPaletteExt
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080410E8: .4byte gUnk_0832A29C
_080410EC: .4byte gUnk_Sio_0200152C
_080410F0: .4byte 0x06016800
_080410F4: .4byte gUnk_0832BDE8

	thumb_func_start sub_80410F8
sub_80410F8: @ 0x080410F8
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r2, r1, #0
	ldr r3, _08041118 @ =gUnk_Sio_0810F6A4
	movs r0, #0
	str r0, [sp]
	movs r0, #1
	adds r1, r4, #0
	bl PutSprite
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08041118: .4byte gUnk_Sio_0810F6A4

	thumb_func_start sub_804111C
sub_804111C: @ 0x0804111C
	push {r4, r5, lr}
	ldr r5, _08041148 @ =gActiveUnit
	ldr r0, [r5]
	lsls r1, r1, #1
	adds r0, #0x1c
	adds r0, r0, r1
	ldrh r4, [r0]
	adds r0, r4, #0
	bl GetItemAttributes
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _0804115E
	adds r0, r4, #0
	bl GetItemMinRange
	cmp r0, #2
	ble _0804114C
	movs r0, #1
	b _08041160
	.align 2, 0
_08041148: .4byte gActiveUnit
_0804114C:
	ldr r0, [r5]
	adds r1, r4, #0
	bl CanUnitUseWeapon
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804115E
	movs r0, #0
	b _08041160
_0804115E:
	movs r0, #2
_08041160:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_8041168
sub_8041168: @ 0x08041168
	adds r0, r1, #0
	adds r0, #0x3d
	ldrb r0, [r0]
	cmp r0, #1
	beq _08041184
	ldr r0, _08041180 @ =0x0203C984
	adds r1, #0x3c
	ldrb r1, [r1]
	strb r1, [r0, #7]
	movs r0, #0x84
	b _08041186
	.align 2, 0
_08041180: .4byte 0x0203C984
_08041184:
	movs r0, #8
_08041186:
	bx lr

	thumb_func_start sub_8041188
sub_8041188: @ 0x08041188
	ldr r2, _08041198 @ =0x0203C984
	adds r1, #0x3c
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r2, #6]
	movs r0, #0x17
	bx lr
	.align 2, 0
_08041198: .4byte 0x0203C984

	thumb_func_start sub_804119C
sub_804119C: @ 0x0804119C
	push {r4, r5, r6, lr}
	adds r4, r1, #0
	ldr r0, _080411F8 @ =gActiveUnit
	ldr r0, [r0]
	adds r1, #0x3c
	movs r2, #0
	ldrsb r2, [r1, r2]
	lsls r2, r2, #1
	adds r1, r0, #0
	adds r1, #0x1c
	adds r1, r1, r2
	ldrh r6, [r1]
	adds r1, r6, #0
	bl CanUnitUseWeapon
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r0, r6, #0
	bl GetItemMinRange
	cmp r0, #2
	ble _080411CA
	movs r5, #0
_080411CA:
	adds r0, r4, #0
	adds r0, #0x34
	lsls r2, r5, #0x18
	asrs r2, r2, #0x18
	movs r1, #0x2c
	ldrsh r3, [r4, r1]
	lsls r3, r3, #5
	movs r5, #0x2a
	ldrsh r1, [r4, r5]
	adds r3, r3, r1
	lsls r3, r3, #1
	ldr r1, _080411FC @ =gBg0Tm
	adds r3, r3, r1
	adds r1, r6, #0
	bl sub_8016694
	movs r0, #1
	bl EnableBgSync
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080411F8: .4byte gActiveUnit
_080411FC: .4byte gBg0Tm

	thumb_func_start sub_8041200
sub_8041200: @ 0x08041200
	ldr r1, _0804120C @ =0x0203C984
	movs r0, #0
	strb r0, [r1, #6]
	movs r0, #0x1b
	bx lr
	.align 2, 0
_0804120C: .4byte 0x0203C984

	thumb_func_start sub_8041210
sub_8041210: @ 0x08041210
	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0
	ldr r1, _08041278 @ =0x0203C984
	movs r0, #0
	strb r0, [r1, #6]
	adds r7, r2, #0
	adds r7, #0x2d
	movs r0, #0
	ldrsb r0, [r7, r0]
	lsls r0, r0, #5
	adds r5, r2, #0
	adds r5, #0x2c
	movs r1, #0
	ldrsb r1, [r5, r1]
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _0804127C @ =gBg0Tm
	adds r0, r0, r1
	adds r6, r2, #0
	adds r6, #0x2e
	movs r1, #0
	ldrsb r1, [r6, r1]
	adds r4, r2, #0
	adds r4, #0x2f
	movs r2, #0
	ldrsb r2, [r4, r2]
	movs r3, #0
	bl TmFillRect_t
	movs r0, #0
	ldrsb r0, [r7, r0]
	lsls r0, r0, #5
	movs r1, #0
	ldrsb r1, [r5, r1]
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _08041280 @ =gBg1Tm
	adds r0, r0, r1
	movs r1, #0
	ldrsb r1, [r6, r1]
	movs r2, #0
	ldrsb r2, [r4, r2]
	movs r3, #0
	bl TmFillRect_t
	movs r0, #3
	bl EnableBgSync
	movs r0, #0xb
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08041278: .4byte 0x0203C984
_0804127C: .4byte gBg0Tm
_08041280: .4byte gBg1Tm
