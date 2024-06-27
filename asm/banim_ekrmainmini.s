	.include "macro.inc"
	.syntax unified

	.section .data

	.global ProcScr_EfxAnimeDrv
ProcScr_EfxAnimeDrv: @ 085CBDF0
	.incbin "fe6-base.gba", 0x5CBDF0, (0x5CBE08 - 0x5CBDF0) @ length: 0018

	.global ProcScr_EkrUnitMainMini
ProcScr_EkrUnitMainMini: @ 085CBE08
	.incbin "fe6-base.gba", 0x5CBE08, (0x5CBE20 - 0x5CBE08) @ length: 0018

	.section .text
	thumb_func_start func_fe6_0804B930
func_fe6_0804B930: @ 0x0804B930
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	cmp r4, #0
	bne .L0804B93C
	b .L0804BAC2
.L0804B93C:
	movs r5, #0xf0
	lsls r5, r5, #8
	ldrh r0, [r4, #0xc]
	ands r5, r0
	cmp r5, #0
	bne .L0804B94A
	b .L0804BAC2
.L0804B94A:
	movs r0, #0x80
	lsls r0, r0, #5
	ands r0, r5
	cmp r0, #0
	bne .L0804B956
	b .L0804BA84
.L0804B956:
	ldrb r0, [r4, #0x14]
	cmp r0, #0
	bne .L0804B95E
	b .L0804BA7A
.L0804B95E:
	ldrb r1, [r4, #0x14]
	adds r0, r1, r4
	ldrb r0, [r0, #0x14]
	cmp r0, #0x32
	bls .L0804B96A
	b .L0804BA72
.L0804B96A:
	lsls r0, r0, #2
	ldr r1, .L0804B974 @ =.L0804B978
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0804B974: .4byte .L0804B978
.L0804B978: @ jump table
	.4byte .L0804BA72 @ case 0
	.4byte .L0804BA44 @ case 1
	.4byte .L0804BA44 @ case 2
	.4byte .L0804BA5C @ case 3
	.4byte .L0804BA5C @ case 4
	.4byte .L0804BA4C @ case 5
	.4byte .L0804BA72 @ case 6
	.4byte .L0804BA72 @ case 7
	.4byte .L0804BA72 @ case 8
	.4byte .L0804BA72 @ case 9
	.4byte .L0804BA72 @ case 10
	.4byte .L0804BA72 @ case 11
	.4byte .L0804BA72 @ case 12
	.4byte .L0804BA64 @ case 13
	.4byte .L0804BA72 @ case 14
	.4byte .L0804BA72 @ case 15
	.4byte .L0804BA72 @ case 16
	.4byte .L0804BA72 @ case 17
	.4byte .L0804BA72 @ case 18
	.4byte .L0804BA72 @ case 19
	.4byte .L0804BA72 @ case 20
	.4byte .L0804BA72 @ case 21
	.4byte .L0804BA72 @ case 22
	.4byte .L0804BA72 @ case 23
	.4byte .L0804BA6C @ case 24
	.4byte .L0804BA72 @ case 25
	.4byte .L0804BA72 @ case 26
	.4byte .L0804BA72 @ case 27
	.4byte .L0804BA72 @ case 28
	.4byte .L0804BA72 @ case 29
	.4byte .L0804BA72 @ case 30
	.4byte .L0804BA72 @ case 31
	.4byte .L0804BA72 @ case 32
	.4byte .L0804BA72 @ case 33
	.4byte .L0804BA72 @ case 34
	.4byte .L0804BA72 @ case 35
	.4byte .L0804BA72 @ case 36
	.4byte .L0804BA72 @ case 37
	.4byte .L0804BA72 @ case 38
	.4byte .L0804BA72 @ case 39
	.4byte .L0804BA72 @ case 40
	.4byte .L0804BA72 @ case 41
	.4byte .L0804BA72 @ case 42
	.4byte .L0804BA72 @ case 43
	.4byte .L0804BA72 @ case 44
	.4byte .L0804BA72 @ case 45
	.4byte .L0804BA72 @ case 46
	.4byte .L0804BA72 @ case 47
	.4byte .L0804BA72 @ case 48
	.4byte .L0804BA72 @ case 49
	.4byte .L0804BA72 @ case 50
.L0804BA44:
	adds r0, r4, #0
	bl func_fe6_0804BACC
	b .L0804BA72
.L0804BA4C:
	adds r0, r4, #0
	bl GetAnimLayer
	cmp r0, #0
	bne .L0804BA5C
	adds r0, r4, #0
	bl func_fe6_08058158
.L0804BA5C:
	ldr r0, [r4, #0x20]
	adds r0, #4
	str r0, [r4, #0x20]
	b .L0804BA72
.L0804BA64:
	adds r0, r4, #0
	bl func_fe6_0804BAF0
	b .L0804BA72
.L0804BA6C:
	adds r0, r4, #0
	bl func_fe6_0804BACC
.L0804BA72:
	ldrb r0, [r4, #0x14]
	subs r0, #1
	strb r0, [r4, #0x14]
	b .L0804B956
.L0804BA7A:
	movs r0, #0xe7
	lsls r0, r0, #8
	ldrh r1, [r4, #0xc]
	ands r0, r1
	strh r0, [r4, #0xc]
.L0804BA84:
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r5
	cmp r0, #0
	beq .L0804BAB4
	adds r0, r4, #0
	bl GetAnimLayer
	cmp r0, #0
	bne .L0804BAAA
	ldr r1, [r6, #0x28]
	ldr r0, [r4, #0x28]
	cmp r1, r0
	beq .L0804BAAA
	adds r0, r4, #0
	bl RegisterAISSheetGraphics
	ldr r0, [r4, #0x28]
	str r0, [r6, #0x28]
.L0804BAAA:
	movs r0, #0xd7
	lsls r0, r0, #8
	ldrh r1, [r4, #0xc]
	ands r0, r1
	strh r0, [r4, #0xc]
.L0804BAB4:
	movs r0, #0x80
	lsls r0, r0, #7
	ands r5, r0
	cmp r5, #0
	beq .L0804BAC2
	ldr r0, .L0804BAC8 @ =0x0000FFFF
	strh r0, [r4, #0xe]
.L0804BAC2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804BAC8: .4byte 0x0000FFFF

	thumb_func_start func_fe6_0804BACC
func_fe6_0804BACC: @ 0x0804BACC
	adds r1, r0, #0
	ldr r0, .L0804BAEC @ =0x0000FFFE
	strh r0, [r1, #0xe]
	movs r0, #8
	ldrh r2, [r1, #0x10]
	ands r0, r2
	cmp r0, #0
	beq .L0804BAE8
	strh r0, [r1, #0x10]
	movs r0, #0
	strh r0, [r1, #0xe]
	ldr r0, [r1, #0x20]
	adds r0, #4
	str r0, [r1, #0x20]
.L0804BAE8:
	bx lr
	.align 2, 0
.L0804BAEC: .4byte 0x0000FFFE

	thumb_func_start func_fe6_0804BAF0
func_fe6_0804BAF0: @ 0x0804BAF0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r6, [r7, #0x44]
	bl GetAnimLayer
	cmp r0, #0
	bne .L0804BB40
	ldr r3, .L0804BB48 @ =gUnk_08112298
	ldrh r1, [r6, #6]
	lsls r0, r1, #5
	ldr r1, .L0804BB4C @ =banim_data
	adds r0, r0, r1
	ldr r1, [r0, #0xc]
	ldr r2, [r6, #0x10]
	ldr r4, [r6, #0x14]
	ldr r5, [r6, #0x24]
	ldrb r3, [r3, #0x18]
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r5, r0
	ldr r0, [r1, #4]
	str r0, [r2, #0x28]
	ldr r5, [r2, #0x30]
	ldr r0, [r1, #8]
	adds r5, r5, r0
	str r5, [r2, #0x3c]
	ldr r5, [r4, #0x30]
	ldr r0, .L0804BB50 @ =0x000057F0
	adds r5, r5, r0
	str r5, [r4, #0x3c]
	ldr r1, [r6, #0x28]
	ldr r0, [r7, #0x28]
	cmp r1, r0
	beq .L0804BB40
	adds r0, r7, #0
	bl NewEkrChienCHR
	ldr r0, [r7, #0x28]
	str r0, [r6, #0x28]
.L0804BB40:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804BB48: .4byte gUnk_08112298
.L0804BB4C: .4byte banim_data
.L0804BB50: .4byte 0x000057F0

	thumb_func_start func_fe6_0804BB54
func_fe6_0804BB54: @ 0x0804BB54
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, .L0804BBD8 @ =banim_data
	mov sb, r0
	ldr r2, .L0804BBDC @ =gUnk_08112298
	ldrh r3, [r6, #8]
	lsls r1, r3, #2
	adds r0, r1, r2
	ldrb r4, [r0]
	adds r0, r1, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	mov r8, r0
	adds r0, r1, #2
	adds r0, r0, r2
	ldrb r5, [r0]
	adds r1, #3
	adds r1, r1, r2
	ldrb r1, [r1]
	str r1, [sp]
	ldrh r1, [r6, #6]
	lsls r0, r1, #5
	add r0, sb
	ldr r0, [r0, #0x10]
	ldr r1, [r6, #0x24]
	bl LZ77UnCompWram
	ldrh r2, [r6, #6]
	lsls r0, r2, #5
	mov r3, sb
	adds r1, r0, r3
	ldr r2, [r1, #0xc]
	ldr r3, [r6, #0x24]
	ldr r7, .L0804BBE0 @ =AnimScr_DefaultAnim
	cmp r4, #0xff
	beq .L0804BBAE
	lsls r0, r4, #2
	adds r0, r0, r2
	ldr r0, [r0]
	adds r7, r3, r0
.L0804BBAE:
	ldr r0, .L0804BBE0 @ =AnimScr_DefaultAnim
	mov sl, r0
	cmp r5, #0xff
	beq .L0804BBC0
	lsls r0, r5, #2
	adds r0, r0, r2
	ldr r0, [r0]
	adds r3, r3, r0
	mov sl, r3
.L0804BBC0:
	ldrh r0, [r6, #0xa]
	cmp r0, #0
	bne .L0804BBE8
	ldr r4, [r6, #0x20]
	ldr r0, [r1, #0x18]
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r2, .L0804BBE4 @ =0x000057F0
	adds r1, r4, r2
	b .L0804BBF6
	.align 2, 0
.L0804BBD8: .4byte banim_data
.L0804BBDC: .4byte gUnk_08112298
.L0804BBE0: .4byte AnimScr_DefaultAnim
.L0804BBE4: .4byte 0x000057F0
.L0804BBE8:
	ldr r4, [r6, #0x20]
	ldr r0, [r1, #0x14]
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r3, .L0804BCC0 @ =0x000057F0
	adds r1, r4, r3
.L0804BBF6:
	movs r0, #1
	str r0, [r1]
	mov r1, r8
	adds r0, r7, #0
	bl BasCreate
	adds r2, r0, #0
	ldr r0, [r6, #0x20]
	str r0, [r2, #0x30]
	ldrh r0, [r6, #2]
	movs r4, #0
	strh r0, [r2, #2]
	ldrh r0, [r6, #4]
	strh r0, [r2, #4]
	ldrh r1, [r6, #0xe]
	lsls r0, r1, #0xc
	movs r3, #0x80
	lsls r3, r3, #4
	adds r5, r3, #0
	orrs r0, r5
	ldrh r1, [r6, #0xc]
	orrs r0, r1
	strh r0, [r2, #8]
	ldrh r3, [r6, #0xa]
	lsls r0, r3, #9
	movs r3, #0x80
	lsls r3, r3, #3
	adds r1, r3, #0
	orrs r0, r1
	ldrh r1, [r2, #0xc]
	orrs r0, r1
	strh r0, [r2, #0xc]
	strh r4, [r2, #0xe]
	ldrh r0, [r6, #8]
	strb r0, [r2, #0x12]
	ldr r0, [r6, #0x18]
	str r0, [r2, #0x2c]
	str r2, [r6, #0x10]
	str r6, [r2, #0x44]
	ldr r1, [sp]
	mov r0, sl
	bl BasCreate
	adds r2, r0, #0
	ldr r0, [r6, #0x20]
	str r0, [r2, #0x30]
	ldrh r0, [r6, #2]
	strh r0, [r2, #2]
	ldrh r0, [r6, #4]
	strh r0, [r2, #4]
	ldrh r3, [r6, #0xe]
	lsls r0, r3, #0xc
	orrs r0, r5
	ldrh r1, [r6, #0xc]
	orrs r0, r1
	strh r0, [r2, #8]
	ldrh r3, [r6, #0xa]
	lsls r0, r3, #9
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r1, r3, #0
	orrs r0, r1
	ldrh r1, [r2, #0xc]
	orrs r0, r1
	strh r0, [r2, #0xc]
	strh r4, [r2, #0xe]
	ldrh r0, [r6, #8]
	strb r0, [r2, #0x12]
	ldr r0, [r6, #0x18]
	str r0, [r2, #0x2c]
	str r2, [r6, #0x14]
	str r6, [r2, #0x44]
	ldrh r2, [r6, #6]
	lsls r0, r2, #5
	add r0, sb
	ldr r0, [r0, #0x1c]
	ldr r1, [r6, #0x1c]
	bl LZ77UnCompWram
	ldrb r3, [r6, #1]
	lsls r1, r3, #5
	ldr r0, [r6, #0x1c]
	adds r0, r0, r1
	ldrh r2, [r6, #0xe]
	lsls r1, r2, #5
	ldr r2, .L0804BCC4 @ =gPal+0x200
	adds r1, r1, r2
	movs r2, #8
	bl CpuFastSet
	str r4, [r6, #0x28]
	bl EnablePalSync
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804BCC0: .4byte 0x000057F0
.L0804BCC4: .4byte gPal+0x200

	thumb_func_start func_fe6_0804BCC8
func_fe6_0804BCC8: @ 0x0804BCC8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	ldr r0, .L0804BD38 @ =banim_data
	mov sb, r0
	ldr r2, .L0804BD3C @ =gUnk_08112298
	ldrh r1, [r6, #8]
	lsls r0, r1, #2
	adds r1, r0, r2
	ldrb r4, [r1]
	adds r0, #2
	adds r0, r0, r2
	ldrb r5, [r0]
	ldrh r2, [r6, #6]
	lsls r0, r2, #5
	add r0, sb
	ldr r0, [r0, #0x10]
	ldr r1, [r6, #0x24]
	bl LZ77UnCompWram
	ldrh r3, [r6, #6]
	lsls r0, r3, #5
	mov r7, sb
	adds r1, r0, r7
	ldr r2, [r1, #0xc]
	ldr r3, [r6, #0x24]
	ldr r7, .L0804BD40 @ =AnimScr_DefaultAnim
	cmp r4, #0xff
	beq .L0804BD0E
	lsls r0, r4, #2
	adds r0, r0, r2
	ldr r0, [r0]
	adds r7, r3, r0
.L0804BD0E:
	ldr r0, .L0804BD40 @ =AnimScr_DefaultAnim
	mov r8, r0
	cmp r5, #0xff
	beq .L0804BD20
	lsls r0, r5, #2
	adds r0, r0, r2
	ldr r0, [r0]
	adds r3, r3, r0
	mov r8, r3
.L0804BD20:
	ldrh r0, [r6, #0xa]
	cmp r0, #0
	bne .L0804BD48
	ldr r4, [r6, #0x20]
	ldr r0, [r1, #0x18]
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r2, .L0804BD44 @ =0x000057F0
	adds r1, r4, r2
	b .L0804BD56
	.align 2, 0
.L0804BD38: .4byte banim_data
.L0804BD3C: .4byte gUnk_08112298
.L0804BD40: .4byte AnimScr_DefaultAnim
.L0804BD44: .4byte 0x000057F0
.L0804BD48:
	ldr r4, [r6, #0x20]
	ldr r0, [r1, #0x14]
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r3, .L0804BE0C @ =0x000057F0
	adds r1, r4, r3
.L0804BD56:
	movs r0, #1
	str r0, [r1]
	ldr r5, [r6, #0x10]
	str r7, [r5, #0x24]
	str r7, [r5, #0x20]
	ldr r0, [r6, #0x20]
	str r0, [r5, #0x30]
	ldrh r0, [r6, #2]
	movs r4, #0
	movs r2, #0
	strh r0, [r5, #2]
	ldrh r0, [r6, #4]
	strh r0, [r5, #4]
	ldrh r7, [r6, #0xe]
	lsls r0, r7, #0xc
	movs r1, #0x80
	lsls r1, r1, #4
	adds r3, r1, #0
	orrs r0, r3
	ldrh r7, [r6, #0xc]
	orrs r0, r7
	strh r0, [r5, #8]
	movs r1, #0xe0
	lsls r1, r1, #3
	adds r0, r1, #0
	ldrh r7, [r5, #0xc]
	ands r0, r7
	strh r0, [r5, #0xc]
	strh r2, [r5, #0x10]
	strh r2, [r5, #6]
	strh r2, [r5, #0xe]
	ldrh r0, [r6, #8]
	strb r0, [r5, #0x12]
	ldr r0, [r6, #0x18]
	str r0, [r5, #0x2c]
	strb r4, [r5, #0x14]
	str r5, [r6, #0x10]
	ldr r5, [r6, #0x14]
	mov r0, r8
	str r0, [r5, #0x24]
	str r0, [r5, #0x20]
	ldr r0, [r6, #0x20]
	str r0, [r5, #0x30]
	ldrh r0, [r6, #2]
	strh r0, [r5, #2]
	ldrh r0, [r6, #4]
	strh r0, [r5, #4]
	ldrh r7, [r6, #0xe]
	lsls r0, r7, #0xc
	orrs r0, r3
	ldrh r3, [r6, #0xc]
	orrs r0, r3
	strh r0, [r5, #8]
	ldrh r7, [r5, #0xc]
	ands r1, r7
	strh r1, [r5, #0xc]
	strh r2, [r5, #0x10]
	strh r2, [r5, #6]
	strh r2, [r5, #0xe]
	ldrh r0, [r6, #8]
	strb r0, [r5, #0x12]
	ldr r0, [r6, #0x18]
	str r0, [r5, #0x2c]
	strb r4, [r5, #0x14]
	str r5, [r6, #0x14]
	ldrh r1, [r6, #6]
	lsls r0, r1, #5
	add r0, sb
	ldr r0, [r0, #0x1c]
	ldr r1, [r6, #0x1c]
	bl LZ77UnCompWram
	ldrb r2, [r6, #1]
	lsls r1, r2, #5
	ldr r0, [r6, #0x1c]
	adds r0, r0, r1
	ldrh r6, [r6, #0xe]
	lsls r1, r6, #5
	ldr r2, .L0804BE10 @ =gPal+0x200
	adds r1, r1, r2
	movs r2, #8
	bl CpuFastSet
	bl EnablePalSync
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804BE0C: .4byte 0x000057F0
.L0804BE10: .4byte gPal+0x200

	thumb_func_start func_fe6_0804BE14
func_fe6_0804BE14: @ 0x0804BE14
	push {lr}
	strh r1, [r0, #6]
	bl func_fe6_0804BCC8
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0804BE20
func_fe6_0804BE20: @ 0x0804BE20
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	strh r1, [r0, #2]
	strh r2, [r0, #4]
	ldr r2, [r0, #0x10]
	strh r1, [r2, #2]
	ldrh r1, [r0, #4]
	strh r1, [r2, #4]
	ldr r2, [r0, #0x14]
	ldrh r1, [r0, #2]
	strh r1, [r2, #2]
	ldrh r0, [r0, #4]
	strh r0, [r2, #4]
	bx lr

	thumb_func_start func_fe6_0804BE3C
func_fe6_0804BE3C: @ 0x0804BE3C
	lsls r1, r1, #0x10
	ldr r2, [r0, #0x10]
	lsrs r1, r1, #6
	strh r1, [r2, #8]
	ldr r2, [r0, #0x14]
	strh r1, [r2, #8]
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0804BE4C
func_fe6_0804BE4C: @ 0x0804BE4C
	ldr r1, [r0, #0x10]
	ldr r2, [r0, #0x14]
	ldr r0, .L0804BE64 @ =0x0000FFFE
	ldrh r1, [r1, #0xe]
	cmp r1, r0
	beq .L0804BE68
	ldrh r2, [r2, #0xe]
	cmp r2, r0
	beq .L0804BE68
	movs r0, #0
	b .L0804BE6A
	.align 2, 0
.L0804BE64: .4byte 0x0000FFFE
.L0804BE68:
	movs r0, #1
.L0804BE6A:
	bx lr

	thumb_func_start func_fe6_0804BE6C
func_fe6_0804BE6C: @ 0x0804BE6C
	ldr r3, [r0, #0x10]
	movs r2, #8
	ldrh r1, [r3, #0x10]
	orrs r1, r2
	strh r1, [r3, #0x10]
	ldr r3, [r0, #0x14]
	ldrh r0, [r3, #0x10]
	orrs r0, r2
	strh r0, [r3, #0x10]
	bx lr

	thumb_func_start func_fe6_0804BE80
func_fe6_0804BE80: @ 0x0804BE80
	ldr r1, [r0, #0x10]
	ldr r0, .L0804BE90 @ =0x0000FFFF
	ldrh r1, [r1, #0xe]
	cmp r1, r0
	bne .L0804BE94
	movs r0, #1
	b .L0804BE96
	.align 2, 0
.L0804BE90: .4byte 0x0000FFFF
.L0804BE94:
	movs r0, #0
.L0804BE96:
	bx lr

	thumb_func_start NewEfxAnimeDrvProc
NewEfxAnimeDrvProc: @ 0x0804BE98
	push {r4, lr}
	ldr r4, .L0804BEB0 @ =gpProcEfxAnimeDrv
	ldr r0, .L0804BEB4 @ =ProcScr_EfxAnimeDrv
	movs r1, #4
	bl SpawnProc
	str r0, [r4]
	bl BasInit
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804BEB0: .4byte gpProcEfxAnimeDrv
.L0804BEB4: .4byte ProcScr_EfxAnimeDrv

	thumb_func_start EndEfxAnimeDrvProc
EndEfxAnimeDrvProc: @ 0x0804BEB8
	push {lr}
	ldr r0, .L0804BEC8 @ =gpProcEfxAnimeDrv
	ldr r0, [r0]
	bl Proc_End
	pop {r0}
	bx r0
	.align 2, 0
.L0804BEC8: .4byte gpProcEfxAnimeDrv

	thumb_func_start ExecAllBas
ExecAllBas: @ 0x0804BECC
	push {lr}
	bl BasUpdateAll
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start NewEkrUnitMainMini
NewEkrUnitMainMini: @ 0x0804BED8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, .L0804BEFC @ =ProcScr_EkrUnitMainMini
	movs r1, #4
	bl SpawnProc
	adds r5, r0, #0
	adds r0, r4, #0
	bl func_fe6_0804BB54
	str r4, [r5, #0x5c]
	str r5, [r4, #0x30]
	movs r0, #1
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0804BEFC: .4byte ProcScr_EkrUnitMainMini

	thumb_func_start func_fe6_0804BF00
func_fe6_0804BF00: @ 0x0804BF00
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x10]
	bl BasRemove
	ldr r0, [r4, #0x14]
	bl BasRemove
	movs r0, #0
	str r0, [r4, #0x10]
	str r0, [r4, #0x14]
	ldr r0, [r4, #0x30]
	bl Proc_End
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0804BF24
func_fe6_0804BF24: @ 0x0804BF24
	push {r4, lr}
	ldr r4, [r0, #0x5c]
	ldr r1, [r4, #0x10]
	adds r0, r4, #0
	bl func_fe6_0804B930
	ldr r1, [r4, #0x14]
	adds r0, r4, #0
	bl func_fe6_0804B930
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0804BF40
func_fe6_0804BF40: @ 0x0804BF40
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	movs r0, #0
	ldrsh r1, [r6, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldr r2, .L0804BFA8 @ =0x087EA008
	adds r0, r0, r2
	mov r8, r0
	movs r0, #6
	ldrsh r1, [r6, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r5, r0, r2
	movs r1, #0
	ldrsh r0, [r6, r1]
	movs r4, #1
	rsbs r4, r4, #0
	cmp r0, r4
	beq .L0804BF7E
	mov r2, r8
	ldr r0, [r2, #0xc]
	ldr r1, [r6, #0x20]
	bl LZ77UnCompWram
.L0804BF7E:
	movs r1, #6
	ldrsh r0, [r6, r1]
	cmp r0, r4
	beq .L0804BF94
	ldr r0, [r5, #0xc]
	ldr r1, [r6, #0x20]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r1, r2
	bl LZ77UnCompWram
.L0804BF94:
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	cmp r0, #3
	bgt .L0804BFAC
	cmp r0, #1
	bge .L0804BFBA
	cmp r0, #0
	beq .L0804BFB0
	b .L0804BFBA
	.align 2, 0
.L0804BFA8: .4byte 0x087EA008
.L0804BFAC:
	cmp r0, #4
	bne .L0804BFBA
.L0804BFB0:
	ldr r3, [r6, #0x20]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r7, r3, r2
	b .L0804BFC8
.L0804BFBA:
	ldr r0, [r6, #0x20]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r3, r0, r1
	movs r2, #0xc0
	lsls r2, r2, #5
	adds r7, r0, r2
.L0804BFC8:
	mov r0, r8
	ldr r0, [r0, #0x10]
	mov r8, r0
	ldr r5, [r5, #0x10]
	mov sb, r5
	movs r1, #0xe
	ldrsh r4, [r6, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r4, r0
	beq .L0804C04C
	cmp r4, r0
	blt .L0804C0AC
	cmp r4, #3
	bgt .L0804C0AC
	movs r2, #4
	ldrsh r0, [r6, r2]
	adds r0, #0x40
	lsls r0, r0, #5
	movs r4, #0xc0
	lsls r4, r4, #0x13
	adds r0, r0, r4
	ldr r1, [r6, #0x1c]
	adds r1, r1, r0
	movs r5, #0x80
	lsls r5, r5, #4
	adds r0, r3, #0
	adds r2, r5, #0
	bl RegisterDataMove
	movs r1, #0xa
	ldrsh r0, [r6, r1]
	lsls r0, r0, #5
	adds r0, r0, r4
	ldr r1, [r6, #0x1c]
	adds r1, r1, r0
	adds r0, r7, #0
	adds r2, r5, #0
	bl RegisterDataMove
	movs r2, #2
	ldrsh r1, [r6, r2]
	lsls r1, r1, #5
	ldr r4, .L0804C048 @ =gPal
	adds r1, r1, r4
	mov r0, r8
	movs r2, #8
	bl CpuFastSet
	movs r0, #8
	ldrsh r1, [r6, r0]
	lsls r1, r1, #5
	adds r1, r1, r4
	mov r0, sb
	movs r2, #8
	bl CpuFastSet
	bl EnablePalSync
	adds r0, r6, #0
	bl func_fe6_0804C330
	b .L0804C0AC
	.align 2, 0
.L0804C048: .4byte gPal
.L0804C04C:
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, r4
	beq .L0804C07A
	movs r2, #4
	ldrsh r0, [r6, r2]
	lsls r0, r0, #5
	ldr r1, [r6, #0x1c]
	adds r1, r1, r0
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r3, #0
	bl RegisterDataMove
	movs r0, #2
	ldrsh r1, [r6, r0]
	lsls r1, r1, #5
	ldr r0, .L0804C0C4 @ =gPal+0x200
	adds r1, r1, r0
	mov r0, r8
	movs r2, #8
	bl CpuFastSet
.L0804C07A:
	movs r1, #6
	ldrsh r0, [r6, r1]
	cmp r0, r4
	beq .L0804C0A8
	movs r2, #0xa
	ldrsh r0, [r6, r2]
	lsls r0, r0, #5
	ldr r1, [r6, #0x1c]
	adds r1, r1, r0
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r7, #0
	bl RegisterDataMove
	movs r0, #8
	ldrsh r1, [r6, r0]
	lsls r1, r1, #5
	ldr r0, .L0804C0C4 @ =gPal+0x200
	adds r1, r1, r0
	mov r0, sb
	movs r2, #8
	bl CpuFastSet
.L0804C0A8:
	bl EnablePalSync
.L0804C0AC:
	ldrh r0, [r6, #0xe]
	adds r0, #1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bls .L0804C0BA
	b .L0804C2DA
.L0804C0BA:
	lsls r0, r0, #2
	ldr r1, .L0804C0C8 @ =.L0804C0CC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0804C0C4: .4byte gPal+0x200
.L0804C0C8: .4byte .L0804C0CC
.L0804C0CC: @ jump table
	.4byte .L0804C100 @ case 0
	.4byte .L0804C0E0 @ case 1
	.4byte .L0804C0E8 @ case 2
	.4byte .L0804C0F0 @ case 3
	.4byte .L0804C0F8 @ case 4
.L0804C0E0:
	movs r0, #1
	bl EnableBgSync
	b .L0804C2DA
.L0804C0E8:
	movs r0, #2
	bl EnableBgSync
	b .L0804C2DA
.L0804C0F0:
	movs r0, #4
	bl EnableBgSync
	b .L0804C2DA
.L0804C0F8:
	movs r0, #8
	bl EnableBgSync
	b .L0804C2DA
.L0804C100:
	movs r0, #0
	str r0, [r6, #0x14]
	str r0, [r6, #0x18]
	movs r2, #0
	ldrsh r1, [r6, r2]
	subs r0, #1
	cmp r1, r0
	beq .L0804C1EE
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	cmp r0, #4
	bhi .L0804C1EE
	lsls r0, r0, #2
	ldr r1, .L0804C124 @ =.L0804C128
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0804C124: .4byte .L0804C128
.L0804C128: @ jump table
	.4byte .L0804C13C @ case 0
	.4byte .L0804C168 @ case 1
	.4byte .L0804C194 @ case 2
	.4byte .L0804C1C0 @ case 3
	.4byte .L0804C13C @ case 4
.L0804C13C:
	movs r2, #2
	ldrsh r0, [r6, r2]
	lsls r0, r0, #0xc
	ldrh r1, [r6, #4]
	orrs r0, r1
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, .L0804C164 @ =gUnk_085CCF38
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	movs r0, #0x48
	b .L0804C1E4
	.align 2, 0
.L0804C164: .4byte gUnk_085CCF38
.L0804C168:
	movs r1, #2
	ldrsh r0, [r6, r1]
	lsls r0, r0, #0xc
	ldrh r2, [r6, #4]
	orrs r0, r2
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, .L0804C190 @ =gUnk_085CCE38
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	movs r0, #0x20
	b .L0804C1E4
	.align 2, 0
.L0804C190: .4byte gUnk_085CCE38
.L0804C194:
	movs r1, #2
	ldrsh r0, [r6, r1]
	lsls r0, r0, #0xc
	ldrh r2, [r6, #4]
	orrs r0, r2
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, .L0804C1BC @ =gUnk_085CCE38
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	movs r0, #0x40
	b .L0804C1E4
	.align 2, 0
.L0804C1BC: .4byte gUnk_085CCE38
.L0804C1C0:
	movs r1, #2
	ldrsh r0, [r6, r1]
	lsls r0, r0, #0xc
	ldrh r2, [r6, #4]
	orrs r0, r2
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, .L0804C20C @ =gUnk_085CCF38
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	movs r0, #0x78
.L0804C1E4:
	movs r1, #0x68
	movs r3, #2
	bl NewEkrsubAnimeEmulator
	str r0, [r6, #0x14]
.L0804C1EE:
	movs r0, #6
	ldrsh r1, [r6, r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq .L0804C2DA
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	cmp r0, #4
	bhi .L0804C2DA
	lsls r0, r0, #2
	ldr r1, .L0804C210 @ =.L0804C214
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0804C20C: .4byte gUnk_085CCF38
.L0804C210: .4byte .L0804C214
.L0804C214: @ jump table
	.4byte .L0804C228 @ case 0
	.4byte .L0804C254 @ case 1
	.4byte .L0804C280 @ case 2
	.4byte .L0804C2AC @ case 3
	.4byte .L0804C228 @ case 4
.L0804C228:
	movs r2, #8
	ldrsh r0, [r6, r2]
	lsls r0, r0, #0xc
	ldrh r1, [r6, #0xa]
	orrs r0, r1
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, .L0804C250 @ =gUnk_085CCEB8
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	movs r0, #0xa8
	b .L0804C2D0
	.align 2, 0
.L0804C250: .4byte gUnk_085CCEB8
.L0804C254:
	movs r1, #8
	ldrsh r0, [r6, r1]
	lsls r0, r0, #0xc
	ldrh r2, [r6, #0xa]
	orrs r0, r2
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, .L0804C27C @ =gUnk_085CCDAC
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	movs r0, #0xb0
	b .L0804C2D0
	.align 2, 0
.L0804C27C: .4byte gUnk_085CCDAC
.L0804C280:
	movs r1, #8
	ldrsh r0, [r6, r1]
	lsls r0, r0, #0xc
	ldrh r2, [r6, #0xa]
	orrs r0, r2
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, .L0804C2A8 @ =gUnk_085CCDAC
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	movs r0, #0xb0
	b .L0804C2D0
	.align 2, 0
.L0804C2A8: .4byte gUnk_085CCDAC
.L0804C2AC:
	movs r1, #8
	ldrsh r0, [r6, r1]
	lsls r0, r0, #0xc
	ldrh r2, [r6, #0xa]
	orrs r0, r2
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, .L0804C2E8 @ =gUnk_085CCDAC
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	movs r0, #0x80
.L0804C2D0:
	movs r1, #0x68
	movs r3, #2
	bl NewEkrsubAnimeEmulator
	str r0, [r6, #0x18]
.L0804C2DA:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804C2E8: .4byte gUnk_085CCDAC

	thumb_func_start func_fe6_0804C2EC
func_fe6_0804C2EC: @ 0x0804C2EC
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xe
	ldrsh r1, [r4, r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L0804C310
	ldr r0, [r4, #0x14]
	cmp r0, #0
	beq .L0804C306
	bl Proc_End
.L0804C306:
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq .L0804C310
	bl Proc_End
.L0804C310:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0804C318
func_fe6_0804C318: @ 0x0804C318
	push {r4, r5, lr}
	ldr r4, [sp, #0xc]
	ldr r5, [r0, #0x14]
	strh r1, [r5, #0x32]
	strh r2, [r5, #0x3a]
	ldr r5, [r0, #0x18]
	strh r3, [r5, #0x32]
	strh r4, [r5, #0x3a]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0804C330
func_fe6_0804C330: @ 0x0804C330
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	movs r4, #0
	mov sl, r4
	ldr r0, .L0804C374 @ =gUnk_085CBDB0
	movs r2, #0xc
	ldrsh r1, [r7, r2]
	lsls r2, r1, #3
	adds r2, r2, r0
	ldr r2, [r2]
	str r2, [sp, #0x10]
	lsls r1, r1, #1
	adds r1, #1
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	str r1, [sp, #0x14]
	movs r0, #0
	bl func_fe6_08047C48
	movs r1, #0xc
	ldrsh r0, [r7, r1]
	cmp r0, #4
	bhi .L0804C3C4
	lsls r0, r0, #2
	ldr r1, .L0804C378 @ =.L0804C37C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0804C374: .4byte gUnk_085CBDB0
.L0804C378: .4byte .L0804C37C
.L0804C37C: @ jump table
	.4byte .L0804C390 @ case 0
	.4byte .L0804C398 @ case 1
	.4byte .L0804C3B0 @ case 2
	.4byte .L0804C3C4 @ case 3
	.4byte .L0804C390 @ case 4
.L0804C390:
	movs r4, #0x21
	movs r2, #0x30
	mov sl, r2
	b .L0804C3E4
.L0804C398:
	movs r4, #0x1d
	movs r0, #0x30
	mov sl, r0
	ldr r0, .L0804C3AC @ =gEkrInitPosReal
	ldr r0, [r0]
	movs r5, #4
	rsbs r5, r5, #0
.L0804C3A6:
	cmp r0, #1
	bne .L0804C3E6
	b .L0804C3E4
	.align 2, 0
.L0804C3AC: .4byte gEkrInitPosReal
.L0804C3B0:
	movs r4, #3
	movs r1, #0x30
	mov sl, r1
	ldr r0, .L0804C3C0 @ =gEkrInitPosReal
	ldr r0, [r0]
	movs r5, #0x1e
	rsbs r5, r5, #0
	b .L0804C3A6
	.align 2, 0
.L0804C3C0: .4byte gEkrInitPosReal
.L0804C3C4:
	movs r2, #0
	ldrsh r0, [r7, r2]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq .L0804C3D6
	movs r4, #0x27
	movs r0, #3
	mov sl, r0
.L0804C3D6:
	movs r2, #6
	ldrsh r0, [r7, r2]
	cmp r0, r1
	beq .L0804C3E4
	movs r4, #3
	movs r0, #0x2a
	mov sl, r0
.L0804C3E4:
	movs r5, #0
.L0804C3E6:
	movs r1, #1
	rsbs r1, r1, #0
	mov sb, r1
	lsls r2, r4, #1
	ldr r4, .L0804C46C @ =gTmA_Banim + 0x6B4
	adds r2, r2, r4
	movs r0, #0xf
	mov r8, r0
	str r0, [sp]
	movs r6, #5
	str r6, [sp, #4]
	movs r1, #2
	ldrsh r0, [r7, r1]
	str r0, [sp, #8]
	movs r1, #4
	ldrsh r0, [r7, r1]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	mov r1, sb
	movs r3, #0x42
	bl EfxTmCpyExt
	mov r0, sl
	lsls r2, r0, #1
	adds r2, r2, r4
	mov r1, r8
	str r1, [sp]
	str r6, [sp, #4]
	movs r1, #8
	ldrsh r0, [r7, r1]
	str r0, [sp, #8]
	movs r1, #0xa
	ldrsh r0, [r7, r1]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x14]
	mov r1, sb
	movs r3, #0x42
	bl EfxTmCpyExt
	lsls r0, r5, #1
	adds r4, r4, r0
	ldr r2, .L0804C470 @ =0xFFFFFA96
	adds r4, r4, r2
	ldr r2, .L0804C474 @ =gBg2Tm
	movs r0, #0x20
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	mov r0, sb
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x42
	movs r3, #0x20
	bl EfxTmCpyExt
	movs r0, #4
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
.L0804C46C: .4byte gTmA_Banim + 0x6B4
.L0804C470: .4byte 0xFFFFFA96
.L0804C474: .4byte gBg2Tm

	thumb_func_start func_fe6_0804C478
func_fe6_0804C478: @ 0x0804C478
	push {lr}
	sub sp, #0x10
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bhi .L0804C4C0
	lsls r0, r0, #2
	ldr r1, .L0804C494 @ =.L0804C498
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0804C494: .4byte .L0804C498
.L0804C498: @ jump table
	.4byte .L0804C4AC @ case 0
	.4byte .L0804C4B6 @ case 1
	.4byte .L0804C4C0 @ case 2
	.4byte .L0804C4C0 @ case 3
	.4byte .L0804C4AC @ case 4
.L0804C4AC:
	movs r2, #0x30
	cmp r3, #0
	bne .L0804C4C8
	movs r2, #0x21
	b .L0804C4C8
.L0804C4B6:
	movs r2, #0x30
	cmp r3, #0
	bne .L0804C4C8
	movs r2, #0x1d
	b .L0804C4C8
.L0804C4C0:
	movs r2, #0x30
	cmp r3, #0
	bne .L0804C4C8
	movs r2, #3
.L0804C4C8:
	ldr r0, .L0804C4EC @ =gUnk_081122DA
	movs r1, #1
	rsbs r1, r1, #0
	lsls r2, r2, #1
	ldr r3, .L0804C4F0 @ =gTmA_Banim + 0x6B4
	adds r2, r2, r3
	movs r3, #0xf
	str r3, [sp]
	movs r3, #5
	str r3, [sp, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	movs r3, #0x42
	bl EfxTmCpyExt
	add sp, #0x10
	pop {r0}
	bx r0
	.align 2, 0
.L0804C4EC: .4byte gUnk_081122DA
.L0804C4F0: .4byte gTmA_Banim + 0x6B4
