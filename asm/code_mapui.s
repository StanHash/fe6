	.include "macro.inc"

	.syntax unified

	thumb_func_start func_fe6_080727A8
func_fe6_080727A8: @ 0x080727A8
	push {r4, lr}
	ldr r1, .L080727E8 @ =gBmSt
	movs r0, #0x14
	ldrsh r2, [r1, r0]
	movs r3, #0xc
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bge .L080727BA
	adds r0, #0xf
.L080727BA:
	asrs r0, r0, #4
	subs r2, r2, r0
	movs r4, #0x16
	ldrsh r3, [r1, r4]
	movs r4, #0xe
	ldrsh r0, [r1, r4]
	cmp r0, #0
	bge .L080727CC
	adds r0, #0xf
.L080727CC:
	asrs r0, r0, #4
	subs r0, r3, r0
	movs r1, #9
	subs r1, r1, r0
	adds r0, r2, #0
	muls r0, r2, r0
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	cmp r0, #0x30
	bgt .L080727EC
	movs r0, #1
	b .L08072804
	.align 2, 0
.L080727E8: .4byte gBmSt
.L080727EC:
	movs r0, #0xe
	subs r0, r0, r2
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r0, r0, r1
	cmp r0, #0x30
	ble .L08072800
	movs r0, #0
	b .L08072804
.L08072800:
	movs r0, #1
	rsbs r0, r0, #0
.L08072804:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0807280C
func_fe6_0807280C: @ 0x0807280C
	movs r2, #0x90
	lsls r2, r2, #1
	adds r1, r2, #0
	strh r1, [r0]
	ldr r3, .L08072830 @ =0x00000121
	adds r1, r3, #0
	strh r1, [r0, #2]
	movs r2, #0
	strh r2, [r0, #4]
	adds r3, #0x1d
	adds r1, r3, #0
	strh r1, [r0, #6]
	adds r3, #1
	adds r1, r3, #0
	strh r1, [r0, #8]
	strh r2, [r0, #0xa]
	bx lr
	.align 2, 0
.L08072830: .4byte 0x00000121

	thumb_func_start func_fe6_08072834
func_fe6_08072834: @ 0x08072834
	push {r4, lr}
	adds r3, r0, #0
	movs r2, #0x80
	lsls r2, r2, #1
	cmp r1, #0
	beq .L0807289C
	adds r1, #0x2e
	ldrb r4, [r1]
	lsls r0, r4, #0x1c
	lsrs r0, r0, #0x1c
	adds r4, r1, #0
	cmp r0, #4
	bhi .L0807287E
	lsls r0, r0, #2
	ldr r1, .L08072858 @ =.L0807285C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08072858: .4byte .L0807285C
.L0807285C: @ jump table
	.4byte .L0807289C @ case 0
	.4byte .L08072874 @ case 1
	.4byte .L08072870 @ case 2
	.4byte .L0807287C @ case 3
	.4byte .L08072878 @ case 4
.L08072870:
	adds r2, #0x60
	b .L0807287E
.L08072874:
	adds r2, #0x64
	b .L0807287E
.L08072878:
	adds r2, #0x68
	b .L0807287E
.L0807287C:
	adds r2, #0x6c
.L0807287E:
	strh r2, [r3]
	adds r2, #1
	strh r2, [r3, #2]
	adds r2, #1
	strh r2, [r3, #4]
	adds r2, #1
	strh r2, [r3, #6]
	movs r0, #0
	strh r0, [r3, #8]
	ldrb r4, [r4]
	lsrs r0, r4, #4
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r0, r1
	strh r0, [r3, #0xa]
.L0807289C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080728A4
func_fe6_080728A4: @ 0x080728A4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r5, r1, #0
	ldrh r1, [r6, #0x3c]
	movs r0, #0x3f
	ands r0, r1
	cmp r0, #0
	bne .L0807291A
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L080728D0
	ldr r0, [r6, #0x38]
	adds r1, r5, #0
	bl func_fe6_08072834
	movs r0, #1
	bl EnableBgSync
	b .L0807291A
.L080728D0:
	ldr r0, [r6, #0x38]
	adds r1, r5, #0
	bl func_fe6_0807280C
	movs r0, #1
	bl EnableBgSync
	adds r0, r5, #0
	bl GetUnitCurrentHp
	bl GenNumberStr
	ldr r4, .L080729BC @ =gNumberStr
	ldrb r0, [r4, #6]
	subs r0, #0x30
	adds r1, r6, #0
	adds r1, #0x49
	strb r0, [r1]
	ldrb r0, [r4, #7]
	subs r0, #0x30
	adds r1, #1
	strb r0, [r1]
	adds r0, r5, #0
	bl GetUnitMaxHp
	bl GenNumberStr
	ldrb r0, [r4, #6]
	subs r0, #0x30
	adds r1, r6, #0
	adds r1, #0x4b
	strb r0, [r1]
	ldrb r1, [r4, #7]
	subs r1, #0x30
	adds r0, r6, #0
	adds r0, #0x4c
	strb r1, [r0]
.L0807291A:
	adds r0, r6, #0
	adds r0, #0x4d
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne .L080729B2
	movs r0, #0x40
	ldrh r1, [r6, #0x3c]
	ands r0, r1
	cmp r0, #0
	beq .L08072940
	adds r1, r5, #0
	adds r1, #0x2e
	movs r0, #0xf
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne .L080729B2
.L08072940:
	movs r2, #0x3e
	ldrsh r0, [r6, r2]
	lsls r7, r0, #3
	adds r1, r7, #0
	adds r1, #0x10
	adds r0, r6, #0
	adds r0, #0x40
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r5, r0, #3
	adds r0, r6, #0
	adds r0, #0x49
	ldrb r2, [r0]
	cmp r2, #0xf0
	beq .L0807296E
	ldr r2, .L080729C0 @ =Sprite_8x8
	ldrb r0, [r0]
	ldr r4, .L080729C4 @ =0x000082E0
	adds r3, r0, r4
	adds r0, r1, #0
	adds r1, r5, #0
	bl PutOamHiRam
.L0807296E:
	adds r0, r7, #0
	adds r0, #0x17
	ldr r1, .L080729C0 @ =Sprite_8x8
	mov r8, r1
	adds r1, r6, #0
	adds r1, #0x4a
	ldr r4, .L080729C4 @ =0x000082E0
	ldrb r1, [r1]
	adds r3, r1, r4
	adds r1, r5, #0
	mov r2, r8
	bl PutOamHiRam
	adds r0, r7, #0
	adds r0, #0x22
	adds r1, r6, #0
	adds r1, #0x4b
	ldrb r1, [r1]
	adds r3, r1, r4
	adds r1, r5, #0
	mov r2, r8
	bl PutOamHiRam
	adds r0, r7, #0
	adds r0, #0x29
	adds r1, r6, #0
	adds r1, #0x4c
	ldrb r1, [r1]
	adds r4, r1, r4
	adds r1, r5, #0
	mov r2, r8
	adds r3, r4, #0
	bl PutOamHiRam
.L080729B2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080729BC: .4byte gNumberStr
.L080729C0: .4byte Sprite_8x8
.L080729C4: .4byte 0x000082E0

	thumb_func_start func_fe6_080729C8
func_fe6_080729C8: @ 0x080729C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	mov sl, r1
	movs r0, #0
	mov sb, r0
	str r0, [sp, #4]
	ldr r6, .L08072A58 @ =gUnk_Tm_02003238
	ldr r2, .L08072A5C @ =0x01000060
	add r0, sp, #4
	adds r1, r6, #0
	bl CpuFastSet
	mov r1, sl
	ldr r0, [r1]
	ldrh r0, [r0]
	bl DecodeMsg
	mov r8, r0
	movs r0, #0x30
	mov r1, r8
	bl GetStringTextCenteredPos
	adds r5, r0, #0
	adds r4, r7, #0
	adds r4, #0x2c
	adds r0, r4, #0
	bl ClearText
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #5
	bl Text_SetParams
	adds r0, r4, #0
	mov r1, r8
	bl Text_DrawString
	adds r1, r6, #0
	adds r1, #0x4a
	adds r0, r4, #0
	bl PutText
	mov r0, sl
	bl GetUnitChibiId
	adds r1, r6, #0
	adds r1, #0x42
	mov r2, sb
	str r2, [sp]
	movs r2, #0xf0
	movs r3, #4
	bl PutFaceChibi
	adds r6, #0xca
	str r6, [r7, #0x38]
	mov r0, sb
	strh r0, [r7, #0x3c]
	adds r0, r7, #0
	adds r0, #0x48
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge .L08072A60
	movs r0, #5
	b .L08072A62
	.align 2, 0
.L08072A58: .4byte gUnk_Tm_02003238
.L08072A5C: .4byte 0x01000060
.L08072A60:
	movs r0, #0x17
.L08072A62:
	strh r0, [r7, #0x3e]
	adds r1, r7, #0
	adds r1, #0x40
	movs r0, #3
	strh r0, [r1]
	adds r0, r7, #0
	mov r1, sl
	bl func_fe6_080728A4
	ldr r0, .L08072AAC @ =0x02003342
	movs r2, #0xc5
	lsls r2, r2, #6
	mov r1, sl
	bl func_fe6_08072298
	ldr r0, .L08072AB0 @ =gUnk_Tm_02003738
	ldr r1, .L08072AB4 @ =gUnk_08319124
	movs r2, #0xc4
	lsls r2, r2, #6
	bl TmApplyTsa_t
	movs r0, #0xc0
	mov r1, sl
	ldrb r1, [r1, #0xb]
	ands r0, r1
	movs r1, #3
	bl func_fe6_08072734
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08072AAC: .4byte 0x02003342
.L08072AB0: .4byte gUnk_Tm_02003738
.L08072AB4: .4byte gUnk_08319124

	thumb_func_start func_fe6_08072AB8
func_fe6_08072AB8: @ 0x08072AB8
	adds r2, r0, #0
	movs r0, #1
	cmp r1, #5
	bgt .L08072AC2
	movs r0, #4
.L08072AC2:
	cmp r2, #1
	bgt .L08072AC8
	subs r0, #1
.L08072AC8:
	cmp r2, #0x16
	ble .L08072ACE
	adds r0, #1
.L08072ACE:
	bx lr

	thumb_func_start func_fe6_08072AD0
func_fe6_08072AD0: @ 0x08072AD0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	str r1, [sp]
	movs r0, #0xe
	ldrsb r0, [r1, r0]
	lsls r0, r0, #4
	ldr r2, .L08072C10 @ =gBmSt
	movs r3, #0xc
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	cmp r0, #0
	bge .L08072AF4
	adds r0, #7
.L08072AF4:
	asrs r0, r0, #3
	mov sl, r0
	ldr r1, [sp]
	movs r0, #0xf
	ldrsb r0, [r1, r0]
	lsls r0, r0, #4
	movs r3, #0xe
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	cmp r0, #0
	bge .L08072B0C
	adds r0, #7
.L08072B0C:
	asrs r4, r0, #3
	mov r0, sl
	adds r1, r4, #0
	bl func_fe6_08072AB8
	mov r8, r0
	ldr r0, .L08072C14 @ =gUnk_08678140
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	add sl, r0
	ldr r0, .L08072C18 @ =gUnk_08678146
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r4, r4, r0
	adds r0, r7, #0
	adds r0, #0x34
	mov r1, sl
	strb r1, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r1, r7, #0
	adds r1, #0x36
	movs r0, #8
	strb r0, [r1]
	adds r1, #1
	movs r0, #5
	strb r0, [r1]
	ldr r2, [sp]
	ldr r0, [r2]
	ldrh r0, [r0]
	bl DecodeMsg
	mov sb, r0
	movs r0, #0x30
	mov r1, sb
	bl GetStringTextCenteredPos
	adds r6, r0, #0
	adds r5, r7, #0
	adds r5, #0x2c
	adds r0, r5, #0
	bl ClearText
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #5
	bl Text_SetParams
	adds r0, r5, #0
	mov r1, sb
	bl Text_DrawString
	ldr r0, .L08072C1C @ =gUnk_0867812E
	add r0, r8
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r1, r4, r1
	lsls r1, r1, #5
	ldr r0, .L08072C20 @ =gUnk_08678128
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	add r0, sl
	adds r1, r1, r0
	lsls r1, r1, #1
	ldr r6, .L08072C24 @ =gBg0Tm
	adds r1, r1, r6
	adds r0, r5, #0
	bl PutText
	adds r1, r4, #3
	lsls r0, r1, #5
	adds r0, #1
	add r0, sl
	lsls r0, r0, #1
	adds r0, r0, r6
	str r0, [r7, #0x38]
	movs r3, #0
	strh r3, [r7, #0x3c]
	mov r0, sl
	adds r0, #1
	strh r0, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x40
	strh r1, [r0]
	adds r0, r7, #0
	ldr r1, [sp]
	bl func_fe6_080728A4
	lsls r4, r4, #5
	add r4, sl
	lsls r4, r4, #1
	ldr r0, .L08072C28 @ =gBg1Tm
	adds r4, r4, r0
	ldr r0, .L08072C2C @ =gUnk_0867814C
	mov r1, r8
	lsls r1, r1, #2
	mov r8, r1
	add r8, r0
	mov r2, r8
	ldr r1, [r2]
	movs r2, #0xc4
	lsls r2, r2, #6
	adds r0, r4, #0
	bl TmApplyTsa_t
	movs r0, #3
	bl EnableBgSync
	movs r0, #0xc0
	ldr r3, [sp]
	ldrb r3, [r3, #0xb]
	ands r0, r3
	movs r1, #3
	bl func_fe6_08072734
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08072C10: .4byte gBmSt
.L08072C14: .4byte gUnk_08678140
.L08072C18: .4byte gUnk_08678146
.L08072C1C: .4byte gUnk_0867812E
.L08072C20: .4byte gUnk_08678128
.L08072C24: .4byte gBg0Tm
.L08072C28: .4byte gBg1Tm
.L08072C2C: .4byte gUnk_0867814C

	thumb_func_start func_fe6_08072C30
func_fe6_08072C30: @ 0x08072C30
	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0
	movs r0, #0xa1
	lsls r0, r0, #3
	ldrh r1, [r2, #0x36]
	cmp r1, r0
	bne .L08072C9A
	adds r7, r2, #0
	adds r7, #0x35
	movs r0, #0
	ldrsb r0, [r7, r0]
	lsls r0, r0, #5
	adds r5, r2, #0
	adds r5, #0x34
	movs r1, #0
	ldrsb r1, [r5, r1]
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, .L08072CA0 @ =gBg0Tm
	adds r0, r0, r1
	adds r6, r2, #0
	adds r6, #0x36
	movs r1, #0
	ldrsb r1, [r6, r1]
	adds r4, r2, #0
	adds r4, #0x37
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
	ldr r1, .L08072CA4 @ =gBg1Tm
	adds r0, r0, r1
	movs r1, #0
	ldrsb r1, [r6, r1]
	movs r2, #0
	ldrsb r2, [r4, r2]
	movs r3, #0
	bl TmFillRect_t
	movs r0, #3
	bl EnableBgSync
	movs r0, #0
	strb r0, [r6]
	strb r0, [r4]
.L08072C9A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08072CA0: .4byte gBg0Tm
.L08072CA4: .4byte gBg1Tm

	thumb_func_start func_fe6_08072CA8
func_fe6_08072CA8: @ 0x08072CA8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, .L08072DB0 @ =gBmSt
	mov sb, r0
	movs r1, #0x16
	ldrsh r0, [r0, r1]
	ldr r1, .L08072DB4 @ =gMapTerrain
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	mov r2, sb
	movs r3, #0x14
	ldrsh r1, [r2, r3]
	ldr r0, [r0]
	adds r0, r0, r1
	ldrb r7, [r0]
	movs r0, #0
	str r0, [sp]
	ldr r0, .L08072DB8 @ =gUnk_Tm_02003238+0x280
	mov r8, r0
	ldr r2, .L08072DBC @ =0x01000070
	mov r0, sp
	mov r1, r8
	bl CpuFastSet
	adds r0, r7, #0
	bl GetTerrainName
	adds r5, r0, #0
	movs r0, #0x20
	adds r1, r5, #0
	bl GetStringTextCenteredPos
	adds r6, r0, #0
	adds r4, #0x2c
	adds r0, r4, #0
	bl ClearText
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl Text_SetParams
	adds r0, r4, #0
	adds r1, r5, #0
	bl Text_DrawString
	mov r1, r8
	adds r1, #0x82
	adds r0, r4, #0
	bl PutText
	movs r6, #0x81
	lsls r6, r6, #1
	add r6, r8
	ldr r1, .L08072DC0 @ =gUnk_083193B0
	movs r2, #0x80
	lsls r2, r2, #1
	mov sl, r2
	adds r0, r6, #0
	bl TmApplyTsa_t
	ldr r0, .L08072DC4 @ =MoveTable_Berserker
	adds r0, r7, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	ble .L08072D7E
	ldr r0, .L08072DC8 @ =TerrainDefTable_Default
	adds r0, r7, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl GenNumberStr
	movs r0, #0x84
	lsls r0, r0, #1
	add r0, r8
	ldr r4, .L08072DCC @ =gNumberStr+0x7
	movs r5, #0x94
	lsls r5, r5, #1
	adds r1, r4, #0
	adds r2, r5, #0
	movs r3, #2
	bl PutDigits
	ldr r0, .L08072DD0 @ =TerrainAvoTable_Default
	adds r0, r7, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl GenNumberStr
	movs r0, #0xa4
	lsls r0, r0, #1
	add r0, r8
	adds r1, r4, #0
	adds r2, r5, #0
	movs r3, #2
	bl PutDigits
.L08072D7E:
	cmp r7, #0x1b
	beq .L08072DD8
	cmp r7, #0x1b
	blt .L08072E28
	cmp r7, #0x29
	bgt .L08072E28
	cmp r7, #0x27
	blt .L08072E28
	ldr r1, .L08072DD4 @ =gUnk_083193BC
	adds r0, r6, #0
	mov r2, sl
	bl TmApplyTsa_t
	mov r3, sb
	movs r1, #0x14
	ldrsh r0, [r3, r1]
	movs r2, #0x16
	ldrsh r1, [r3, r2]
	bl GetObstacleHpAt
	bl GenNumberStr
	movs r0, #0x84
	lsls r0, r0, #1
	b .L08072E1A
	.align 2, 0
.L08072DB0: .4byte gBmSt
.L08072DB4: .4byte gMapTerrain
.L08072DB8: .4byte gUnk_Tm_02003238+0x280
.L08072DBC: .4byte 0x01000070
.L08072DC0: .4byte gUnk_083193B0
.L08072DC4: .4byte MoveTable_Berserker
.L08072DC8: .4byte TerrainDefTable_Default
.L08072DCC: .4byte gNumberStr+0x7
.L08072DD0: .4byte TerrainAvoTable_Default
.L08072DD4: .4byte gUnk_083193BC
.L08072DD8:
	ldr r1, .L08072E08 @ =gUnk_083193C4
	movs r2, #0x84
	lsls r2, r2, #6
	adds r0, r6, #0
	bl TmApplyTsa_t
	mov r3, sb
	movs r1, #0x14
	ldrsh r0, [r3, r1]
	movs r2, #0x16
	ldrsh r1, [r3, r2]
	bl GetObstacleHpAt
	adds r6, r0, #0
	cmp r6, #0x64
	bne .L08072E10
	movs r0, #0xa3
	lsls r0, r0, #1
	add r0, r8
	ldr r1, .L08072E0C @ =gUnk_083193D0
	mov r2, sl
	bl TmApplyTsa_t
	b .L08072E28
	.align 2, 0
.L08072E08: .4byte gUnk_083193C4
.L08072E0C: .4byte gUnk_083193D0
.L08072E10:
	adds r0, r6, #0
	bl GenNumberStr
	movs r0, #0xa4
	lsls r0, r0, #1
.L08072E1A:
	add r0, r8
	ldr r1, .L08072E44 @ =gNumberStr+0x7
	movs r2, #0x94
	lsls r2, r2, #1
	movs r3, #2
	bl PutDigits
.L08072E28:
	ldr r0, .L08072E48 @ =gUnk_Tm_02003738+0x280
	ldr r1, .L08072E4C @ =gUnk_083190CC
	movs r2, #0x88
	lsls r2, r2, #5
	bl TmApplyTsa_t
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08072E44: .4byte gNumberStr+0x7
.L08072E48: .4byte gUnk_Tm_02003738+0x280
.L08072E4C: .4byte gUnk_083190CC

	thumb_func_start func_fe6_08072E50
func_fe6_08072E50: @ 0x08072E50
	push {lr}
	movs r1, #0
	str r1, [r0, #0x50]
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #1
	strb r1, [r2]
	adds r0, #0x2c
	movs r1, #4
	bl InitTextDb
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08072E6C
func_fe6_08072E6C: @ 0x08072E6C
	push {r4, lr}
	adds r4, r0, #0
	bl func_fe6_080727A8
	adds r1, r0, #0
	adds r2, r4, #0
	adds r2, #0x48
	strb r1, [r2]
	lsls r0, r1, #0x18
	cmp r0, #0
	bne .L08072E88
	movs r0, #0xff
	orrs r1, r0
	strb r1, [r2]
.L08072E88:
	adds r0, r4, #0
	bl func_fe6_08072CA8
	ldr r1, .L08072EA8 @ =gBmSt
	ldrh r0, [r1, #0x14]
	adds r2, r4, #0
	adds r2, #0x46
	strb r0, [r2]
	ldrh r1, [r1, #0x16]
	adds r0, r4, #0
	adds r0, #0x47
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08072EA8: .4byte gBmSt

	thumb_func_start func_fe6_08072EAC
func_fe6_08072EAC: @ 0x08072EAC
	push {r4, lr}
	adds r4, r0, #0
	adds r3, r4, #0
	adds r3, #0x46
	ldrb r0, [r3]
	adds r2, r4, #0
	adds r2, #0x44
	strb r0, [r2]
	movs r0, #0x47
	adds r0, r0, r4
	mov ip, r0
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x45
	strb r0, [r1]
	ldr r1, .L08072F18 @ =gBmSt
	ldrh r0, [r1, #0x14]
	strb r0, [r3]
	ldrh r0, [r1, #0x16]
	mov r1, ip
	strb r0, [r1]
	ldr r0, .L08072F1C @ =0x0000FFFF
	adds r1, r0, #0
	ldrh r3, [r3]
	ands r1, r3
	ldrh r2, [r2]
	ands r0, r2
	cmp r1, r0
	beq .L08072F2A
	ldr r0, .L08072F20 @ =ProcScr_CamMove
	bl FindProc
	cmp r0, #0
	bne .L08072F24
	bl func_fe6_080727A8
	adds r1, r0, #0
	adds r0, r4, #0
	adds r0, #0x48
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r1
	beq .L08072F08
	cmp r1, #0
	bne .L08072F24
.L08072F08:
	adds r0, r4, #0
	bl func_fe6_08072CA8
	adds r0, r4, #0
	bl func_fe6_08072700
	b .L08072F2A
	.align 2, 0
.L08072F18: .4byte gBmSt
.L08072F1C: .4byte 0x0000FFFF
.L08072F20: .4byte ProcScr_CamMove
.L08072F24:
	adds r0, r4, #0
	bl Proc_Break
.L08072F2A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08072F30
func_fe6_08072F30: @ 0x08072F30
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	movs r1, #6
	bl InitTextDb
	movs r0, #0
	str r0, [r4, #0x50]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08072F48
func_fe6_08072F48: @ 0x08072F48
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r0, #0x4d
	movs r7, #1
	strb r7, [r0]
	ldr r5, .L08072FB4 @ =gBmSt
	movs r1, #0x16
	ldrsh r0, [r5, r1]
	ldr r1, .L08072FB8 @ =gMapUnit
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r2, #0x14
	ldrsh r1, [r5, r2]
	ldr r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	bl GetUnit
	adds r6, r0, #0
	cmp r6, #0
	beq .L08072FAC
	ldr r0, .L08072FBC @ =ProcScr_CamMove
	bl FindProc
	cmp r0, #0
	bne .L08072FAC
	bl func_fe6_0807277C
	adds r1, r4, #0
	adds r1, #0x48
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08072F90
	strb r7, [r1]
.L08072F90:
	ldrh r0, [r5, #0x14]
	adds r1, r4, #0
	adds r1, #0x46
	strb r0, [r1]
	ldrh r0, [r5, #0x16]
	adds r1, #1
	strb r0, [r1]
	adds r0, r4, #0
	adds r1, r6, #0
	bl func_fe6_080729C8
	adds r0, r4, #0
	bl Proc_Break
.L08072FAC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08072FB4: .4byte gBmSt
.L08072FB8: .4byte gMapUnit
.L08072FBC: .4byte ProcScr_CamMove

	thumb_func_start func_fe6_08072FC0
func_fe6_08072FC0: @ 0x08072FC0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r5, .L08073064 @ =gBmSt
	movs r1, #0x16
	ldrsh r0, [r5, r1]
	ldr r1, .L08073068 @ =gMapUnit
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r2, #0x14
	ldrsh r1, [r5, r2]
	ldr r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	bl GetUnit
	adds r6, r0, #0
	ldrh r0, [r4, #0x3c]
	adds r0, #1
	strh r0, [r4, #0x3c]
	adds r0, r4, #0
	adds r1, r6, #0
	bl func_fe6_080728A4
	movs r0, #0x3f
	ldrh r1, [r4, #0x3c]
	ands r0, r1
	cmp r0, #0
	bne .L08073000
	adds r0, r4, #0
	bl func_fe6_080726CC
.L08073000:
	adds r3, r4, #0
	adds r3, #0x46
	ldrb r0, [r3]
	adds r2, r4, #0
	adds r2, #0x44
	strb r0, [r2]
	movs r0, #0x47
	adds r0, r0, r4
	mov ip, r0
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x45
	strb r0, [r1]
	ldrh r0, [r5, #0x14]
	strb r0, [r3]
	ldrh r0, [r5, #0x16]
	mov r1, ip
	strb r0, [r1]
	ldr r0, .L0807306C @ =0x0000FFFF
	adds r1, r0, #0
	ldrh r3, [r3]
	ands r1, r3
	ldrh r2, [r2]
	ands r0, r2
	cmp r1, r0
	beq .L0807307A
	cmp r6, #0
	beq .L08073074
	ldr r0, .L08073070 @ =ProcScr_CamMove
	bl FindProc
	cmp r0, #0
	bne .L08073074
	bl func_fe6_0807277C
	adds r1, r0, #0
	adds r0, r4, #0
	adds r0, #0x48
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r1
	beq .L0807305A
	cmp r1, #0
	bne .L08073074
.L0807305A:
	adds r0, r4, #0
	movs r1, #1
	bl Proc_Goto
	b .L0807307A
	.align 2, 0
.L08073064: .4byte gBmSt
.L08073068: .4byte gMapUnit
.L0807306C: .4byte 0x0000FFFF
.L08073070: .4byte ProcScr_CamMove
.L08073074:
	adds r0, r4, #0
	bl Proc_Break
.L0807307A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08073080
func_fe6_08073080: @ 0x08073080
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, .L080730B0 @ =gBmSt
	movs r1, #0x16
	ldrsh r0, [r2, r1]
	ldr r1, .L080730B4 @ =gMapUnit
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r3, #0x14
	ldrsh r1, [r2, r3]
	ldr r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	bl GetUnit
	adds r1, r0, #0
	cmp r1, #0
	bne .L080730B8
	adds r0, r4, #0
	movs r1, #3
	bl Proc_Goto
	b .L080730C4
	.align 2, 0
.L080730B0: .4byte gBmSt
.L080730B4: .4byte gMapUnit
.L080730B8:
	adds r0, r4, #0
	bl func_fe6_080729C8
	adds r0, r4, #0
	bl func_fe6_080726CC
.L080730C4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080730CC
func_fe6_080730CC: @ 0x080730CC
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	movs r1, #6
	bl InitTextDb
	adds r0, r4, #0
	adds r0, #0x43
	movs r1, #0
	strb r1, [r0]
	adds r0, #0xa
	strb r1, [r0]
	str r1, [r4, #0x50]
	subs r0, #0x17
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080730F4
func_fe6_080730F4: @ 0x080730F4
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x43
	adds r0, r0, r4
	mov ip, r0
	ldrb r0, [r0]
	adds r3, r4, #0
	adds r3, #0x42
	strb r0, [r3]
	ldr r2, .L0807313C @ =gBmSt
	movs r1, #0x16
	ldrsh r0, [r2, r1]
	ldr r1, .L08073140 @ =gMapUnit
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r5, #0x14
	ldrsh r1, [r2, r5]
	ldr r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r1, ip
	strb r0, [r1]
	ldrb r1, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r1, r0
	beq .L08073144
	cmp r1, #0
	beq .L08073144
	adds r0, r4, #0
	bl func_fe6_08072C30
	movs r0, #0
	str r0, [r4, #0x50]
	b .L080731D2
	.align 2, 0
.L0807313C: .4byte gBmSt
.L08073140: .4byte gMapUnit
.L08073144:
	adds r0, r4, #0
	adds r0, #0x43
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	beq .L080731D2
	ldr r0, .L08073180 @ =ProcScr_CamMove
	bl FindProc
	cmp r0, #0
	bne .L080731D2
	ldr r0, .L08073184 @ =gUnk_08678174
	bl FindProc
	adds r1, r0, #0
	cmp r1, #0
	beq .L08073188
	adds r0, #0x4d
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq .L08073188
	ldr r0, [r4, #0x50]
	cmp r0, #3
	bgt .L080731D2
	adds r0, #1
	str r0, [r4, #0x50]
	b .L080731D2
	.align 2, 0
.L08073180: .4byte ProcScr_CamMove
.L08073184: .4byte gUnk_08678174
.L08073188:
	ldr r0, [r4, #0x50]
	adds r0, #1
	str r0, [r4, #0x50]
	cmp r0, #4
	ble .L080731D2
	cmp r0, #5
	bne .L080731A6
	ldrb r0, [r5]
	bl GetUnit
	adds r1, r0, #0
	adds r0, r4, #0
	bl func_fe6_08072AD0
	b .L080731D2
.L080731A6:
	ldrh r0, [r4, #0x3c]
	adds r0, #1
	strh r0, [r4, #0x3c]
	cmp r1, #0
	beq .L080731BC
	adds r0, r1, #0
	adds r0, #0x4d
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x4d
	b .L080731C2
.L080731BC:
	adds r1, r4, #0
	adds r1, #0x4d
	movs r0, #0
.L080731C2:
	strb r0, [r1]
	ldrb r0, [r5]
	bl GetUnit
	adds r1, r0, #0
	adds r0, r4, #0
	bl func_fe6_080728A4
.L080731D2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080731D8
func_fe6_080731D8: @ 0x080731D8
	push {r4, r5, lr}
	ldr r5, .L080732E0 @ =gDispIo
	movs r4, #0x21
	rsbs r4, r4, #0
	adds r0, r4, #0
	ldrb r1, [r5, #1]
	ands r0, r1
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r5, #1]
	adds r2, r5, #0
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
	movs r1, #0x20
	orrs r0, r1
	strb r0, [r2]
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
	adds r2, r5, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r1, r5, #0
	adds r1, #0x44
	movs r3, #0
	movs r0, #0xf
	strb r0, [r1]
	adds r1, #1
	movs r0, #4
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x46
	strb r3, [r0]
	ldr r0, .L080732E4 @ =0x0000FFE0
	ldrh r1, [r5, #0x3c]
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strh r0, [r5, #0x3c]
	ldrb r0, [r2]
	ands r4, r0
	strb r4, [r2]
	ldr r0, .L080732E8 @ =0x0000E0FF
	ldrh r1, [r5, #0x3c]
	ands r0, r1
	movs r2, #0xe0
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5, #0x3c]
	ldr r0, .L080732EC @ =gUnk_083189B4
	ldr r1, .L080732F0 @ =0x06002000
	bl Decompress
	ldr r0, .L080732F4 @ =0x06002500
	ldr r1, .L080732F8 @ =0x06015C00
	movs r2, #0x50
	bl CpuFastSet
	ldr r0, .L080732FC @ =gPal
	movs r1, #0xc0
	lsls r1, r1, #2
	movs r2, #0x20
	bl ApplyPaletteExt
	movs r0, #1
	movs r1, #2
	bl ApplyIconPalette
	bl ResetTextFont
	ldr r4, .L08073300 @ =gPlaySt
	ldrb r1, [r4, #0x1c]
	lsls r0, r1, #0x1e
	cmp r0, #0
	blt .L080732B4
	ldr r0, .L08073304 @ =gUnk_08678174
	movs r1, #3
	bl SpawnProc
.L080732B4:
	ldrb r2, [r4, #0x1c]
	lsls r0, r2, #0x1c
	lsrs r0, r0, #0x1e
	cmp r0, #0
	bne .L080732C6
	ldr r0, .L08073308 @ =gUnk_086781D4
	movs r1, #3
	bl SpawnProc
.L080732C6:
	ldrb r4, [r4, #0x1c]
	lsls r0, r4, #0x1c
	lsrs r0, r0, #0x1e
	cmp r0, #1
	bne .L080732D8
	ldr r0, .L0807330C @ =gUnk_08678254
	movs r1, #3
	bl SpawnProc
.L080732D8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080732E0: .4byte gDispIo
.L080732E4: .4byte 0x0000FFE0
.L080732E8: .4byte 0x0000E0FF
.L080732EC: .4byte gUnk_083189B4
.L080732F0: .4byte 0x06002000
.L080732F4: .4byte 0x06002500
.L080732F8: .4byte 0x06015C00
.L080732FC: .4byte gPal
.L08073300: .4byte gPlaySt
.L08073304: .4byte gUnk_08678174
.L08073308: .4byte gUnk_086781D4
.L0807330C: .4byte gUnk_08678254

	thumb_func_start func_fe6_08073310
func_fe6_08073310: @ 0x08073310
	push {lr}
	ldr r0, .L08073320 @ =gUnk_08678284
	movs r1, #3
	bl SpawnProc
	pop {r0}
	bx r0
	.align 2, 0
.L08073320: .4byte gUnk_08678284

	thumb_func_start func_fe6_08073324
func_fe6_08073324: @ 0x08073324
	push {lr}
	ldr r0, .L08073360 @ =gUnk_086781D4
	bl Proc_EndEach
	ldr r0, .L08073364 @ =gUnk_08678254
	bl Proc_EndEach
	ldr r0, .L08073368 @ =gUnk_08678174
	bl Proc_EndEach
	ldr r3, .L0807336C @ =gDispIo
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
	bl ClearUi
	pop {r0}
	bx r0
	.align 2, 0
.L08073360: .4byte gUnk_086781D4
.L08073364: .4byte gUnk_08678254
.L08073368: .4byte gUnk_08678174
.L0807336C: .4byte gDispIo
