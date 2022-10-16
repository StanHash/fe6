	.include "macro.inc"

	.syntax unified

	thumb_func_start func_fe6_0806E83C
func_fe6_0806E83C: @ 0x0806E83C
	push {r4, r5, lr}
	adds r3, r1, r2
	adds r3, r0, r3
	movs r4, #4
	strb r4, [r3]
	lsls r4, r1, #1
	adds r3, r4, r2
	adds r3, r0, r3
	movs r5, #0xe
	strb r5, [r3]
	adds r4, r4, r1
	adds r4, r4, r2
	adds r0, r0, r4
	movs r1, #3
	strb r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806E860
func_fe6_0806E860: @ 0x0806E860
	push {r4, r5, lr}
	adds r4, r0, r2
	movs r3, #4
	strb r3, [r4]
	adds r3, r1, r2
	adds r3, r0, r3
	movs r5, #0xe
	strb r5, [r3]
	lsls r4, r1, #1
	adds r3, r4, r2
	adds r3, r0, r3
	strb r5, [r3]
	adds r4, r4, r1
	adds r4, r4, r2
	adds r4, r0, r4
	strb r5, [r4]
	lsls r1, r1, #2
	adds r1, r1, r2
	adds r0, r0, r1
	movs r1, #3
	strb r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806E890
func_fe6_0806E890: @ 0x0806E890
	push {r4, lr}
	adds r3, r1, r2
	adds r3, r0, r3
	movs r4, #1
	strb r4, [r3]
	lsls r1, r1, #1
	adds r1, r1, r2
	adds r0, r0, r1
	movs r1, #5
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806E8AC
func_fe6_0806E8AC: @ 0x0806E8AC
	push {r4, lr}
	adds r3, r1, r2
	adds r3, r0, r3
	movs r4, #0xd
	strb r4, [r3]
	lsls r1, r1, #1
	adds r1, r1, r2
	adds r0, r0, r1
	movs r1, #0xc
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806E8C8
func_fe6_0806E8C8: @ 0x0806E8C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp, #4]
	mov sb, r1
	adds r6, r2, #0
	adds r5, r3, #0
	ldr r0, [sp, #0x28]
	mov sl, r0
	ldr r1, .L0806E990 @ =gBuf
	mov r8, r1
	movs r0, #0
	str r0, [sp]
	lsls r2, r6, #4
	ldr r0, .L0806E994 @ =0x001FFFFF
	ands r2, r0
	movs r0, #0x80
	lsls r0, r0, #0x11
	orrs r2, r0
	mov r0, sp
	bl CpuFastSet
	lsls r4, r6, #3
	mov r0, r8
	adds r1, r4, #0
	mov r2, sb
	bl func_fe6_0806E83C
	mov r0, sb
	adds r2, r0, r5
	adds r2, #3
	mov r0, r8
	adds r1, r4, #0
	bl func_fe6_0806E83C
	movs r4, #0
	adds r5, #2
	cmp r4, r5
	bge .L0806E930
	mov r7, sb
	adds r7, #1
.L0806E920:
	adds r2, r4, r7
	mov r0, r8
	lsls r1, r6, #3
	bl func_fe6_0806E860
	adds r4, #1
	cmp r4, r5
	blt .L0806E920
.L0806E930:
	movs r4, #0
	ldr r1, [sp, #4]
	lsls r7, r1, #5
	cmp r4, sl
	bge .L0806E94E
	mov r5, sb
	adds r5, #2
.L0806E93E:
	adds r2, r4, r5
	mov r0, r8
	lsls r1, r6, #3
	bl func_fe6_0806E890
	adds r4, #1
	cmp r4, sl
	blt .L0806E93E
.L0806E94E:
	ldr r0, [sp, #0x2c]
	cmp r0, #0
	ble .L0806E970
	mov r0, sb
	adds r0, #2
	mov r1, sl
	adds r5, r1, r0
	ldr r4, [sp, #0x2c]
.L0806E95E:
	mov r0, r8
	lsls r1, r6, #3
	adds r2, r5, #0
	bl func_fe6_0806E8AC
	adds r5, #1
	subs r4, #1
	cmp r4, #0
	bne .L0806E95E
.L0806E970:
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r1, r7, r0
	mov r0, r8
	adds r2, r6, #0
	movs r3, #1
	bl func_fe6_08013DAC
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0806E990: .4byte gBuf
.L0806E994: .4byte 0x001FFFFF

	thumb_func_start func_fe6_0806E998
func_fe6_0806E998: @ 0x0806E998
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #8
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r2
	adds r4, r3, #0
	ldr r3, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x24]
	str r0, [sp]
	str r1, [sp, #4]
	adds r0, r5, #0
	movs r1, #2
	adds r2, r6, #0
	bl func_fe6_0806E8C8
	ldr r0, .L0806E9DC @ =0x000003FF
	ands r0, r5
	adds r4, r4, r0
	mov r0, r8
	adds r1, r4, #0
	adds r2, r6, #0
	movs r3, #1
	bl PutIncrTileref
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0806E9DC: .4byte 0x000003FF

	thumb_func_start func_fe6_0806E9E0
func_fe6_0806E9E0: @ 0x0806E9E0
	adds r0, #0x4c
	movs r1, #0
	strh r1, [r0]
	bx lr

	thumb_func_start func_fe6_0806E9E8
func_fe6_0806E9E8: @ 0x0806E9E8
	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0x4c
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	movs r0, #0
	ldrsh r1, [r4, r0]
	cmp r1, #0
	bge .L0806E9FE
	adds r1, #3
.L0806E9FE:
	lsls r1, r1, #0xe
	lsrs r1, r1, #0x10
	movs r0, #3
	movs r2, #0
	bl SetBgOffset
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bge .L0806EA14
	adds r0, #3
.L0806EA14:
	asrs r1, r0, #2
	ldr r0, .L0806EA20 @ =0x0400001C
	strh r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0806EA20: .4byte 0x0400001C

	thumb_func_start func_fe6_0806EA24
func_fe6_0806EA24: @ 0x0806EA24
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r6, .L0806EA5C @ =gBg3Tm
	cmp r4, #0
	bne .L0806EA3E
	movs r0, #3
	bl GetBgChrOffset
	movs r1, #0xc0
	lsls r1, r1, #0x13
	adds r4, r0, r1
.L0806EA3E:
	cmp r5, #0
	bge .L0806EA44
	movs r5, #0xe
.L0806EA44:
	ldr r1, .L0806EA60 @ =gBmSt
	movs r0, #0x40
	ldrb r1, [r1, #4]
	ands r0, r1
	cmp r0, #0
	beq .L0806EA68
	ldr r0, .L0806EA64 @ =gUnk_08109C80
	lsls r1, r5, #5
	movs r2, #0x40
	bl ApplyPaletteExt
	b .L0806EA72
	.align 2, 0
.L0806EA5C: .4byte gBg3Tm
.L0806EA60: .4byte gBmSt
.L0806EA64: .4byte gUnk_08109C80
.L0806EA68:
	ldr r0, .L0806EAAC @ =gUnk_0833BFDC
	lsls r1, r5, #5
	movs r2, #0x40
	bl ApplyPaletteExt
.L0806EA72:
	ldr r0, .L0806EAB0 @ =gUnk_08336D5C
	adds r1, r4, #0
	bl Decompress
	movs r0, #3
	bl GetBgChrOffset
	subs r0, r4, r0
	lsls r0, r0, #0xf
	lsrs r0, r0, #0x14
	movs r1, #0xf
	ands r1, r5
	lsls r1, r1, #0xc
	adds r1, r0, r1
	movs r2, #0
	ldr r3, .L0806EAB4 @ =0x0000027F
.L0806EA92:
	adds r0, r2, r1
	strh r0, [r6]
	adds r6, #2
	adds r2, #1
	cmp r2, r3
	ble .L0806EA92
	ldr r0, .L0806EAB8 @ =ProcScr_Unk_086773D8
	adds r1, r7, #0
	bl SpawnProc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
.L0806EAAC: .4byte gUnk_0833BFDC
.L0806EAB0: .4byte gUnk_08336D5C
.L0806EAB4: .4byte 0x0000027F
.L0806EAB8: .4byte ProcScr_Unk_086773D8

	thumb_func_start func_fe6_0806EABC
func_fe6_0806EABC: @ 0x0806EABC
	push {lr}
	ldr r0, .L0806EAC8 @ =ProcScr_Unk_086773D8
	bl Proc_EndEach
	pop {r0}
	bx r0
	.align 2, 0
.L0806EAC8: .4byte ProcScr_Unk_086773D8

	thumb_func_start func_fe6_0806EACC
func_fe6_0806EACC: @ 0x0806EACC
	ldr r0, .L0806EAD4 @ =0x0203D3DC
	ldrb r0, [r0, #1]
	bx lr
	.align 2, 0
.L0806EAD4: .4byte 0x0203D3DC

	thumb_func_start func_fe6_0806EAD8
func_fe6_0806EAD8: @ 0x0806EAD8
	ldr r1, .L0806EAE0 @ =0x0203D3DC
	strb r0, [r1, #1]
	bx lr
	.align 2, 0
.L0806EAE0: .4byte 0x0203D3DC

	thumb_func_start func_fe6_0806EAE4
func_fe6_0806EAE4: @ 0x0806EAE4
	ldr r1, .L0806EAEC @ =0x0203D3DC
	strh r0, [r1, #2]
	bx lr
	.align 2, 0
.L0806EAEC: .4byte 0x0203D3DC

	thumb_func_start func_fe6_0806EAF0
func_fe6_0806EAF0: @ 0x0806EAF0
	push {lr}
	ldr r0, .L0806EAFC @ =gUnk_086773F0
	bl InitTextList
	pop {r0}
	bx r0
	.align 2, 0
.L0806EAFC: .4byte gUnk_086773F0

	thumb_func_start func_fe6_0806EB00
func_fe6_0806EB00: @ 0x0806EB00
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	b .L0806EB3A
.L0806EB08:
	ldr r0, [r6, #0xc]
	cmp r0, #0
	beq .L0806EB30
	bl GetLang
	ldr r1, [r6, #0xc]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r6]
	ldr r1, [r6, #4]
	ldrb r2, [r6, #8]
	ldrb r3, [r6, #9]
	movs r4, #0
	str r4, [sp]
	ldr r0, [r0]
	str r0, [sp, #4]
	adds r0, r5, #0
	bl PutDrawText
	b .L0806EB38
.L0806EB30:
	ldr r0, [r6]
	ldr r1, [r6, #4]
	bl PutText
.L0806EB38:
	adds r6, #0x10
.L0806EB3A:
	ldr r0, [r6]
	cmp r0, #0
	bne .L0806EB08
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806EB48
func_fe6_0806EB48: @ 0x0806EB48
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	ldr r7, .L0806EC48 @ =0x02003108
	ldr r0, [r7, #0xc]
	ldr r0, [r0]
	ldrh r0, [r0]
	bl DecodeMsg
	adds r6, r0, #0
	movs r0, #0x38
	adds r1, r6, #0
	bl GetStringTextCenteredPos
	mov r8, r0
	ldr r5, .L0806EC4C @ =gBg0Tm
	adds r0, r5, #0
	movs r1, #0
	bl TmFill
	ldr r4, [r7, #0xc]
	adds r0, r4, #0
	bl GetUnitEquippedWeaponSlot
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r0, r4, #0
	bl BattleGenerateDisplayStats
	adds r0, r7, #0
	adds r0, #0x18
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r4, #0
	str r4, [sp]
	str r6, [sp, #4]
	movs r2, #0
	mov r3, r8
	bl PutDrawText
	ldr r0, [r7, #0xc]
	ldr r0, [r0, #4]
	ldrh r0, [r0]
	bl DecodeMsg
	adds r2, r7, #0
	adds r2, #0x20
	ldr r3, .L0806EC50 @ =0x00000342
	adds r1, r5, r3
	str r4, [sp]
	str r0, [sp, #4]
	adds r0, r2, #0
	movs r2, #0
	movs r3, #0
	bl PutDrawText
	ldr r1, .L0806EC54 @ =0x000003C2
	adds r0, r5, r1
	movs r1, #3
	movs r2, #0x24
	movs r3, #0x25
	bl PutTwoSpecialChar
	ldr r2, .L0806EC58 @ =0x000003CA
	adds r0, r5, r2
	movs r1, #3
	movs r2, #0x1f
	bl PutSpecialChar
	ldr r3, .L0806EC5C @ =0x00000442
	adds r0, r5, r3
	movs r1, #3
	movs r2, #0x22
	movs r3, #0x23
	bl PutTwoSpecialChar
	ldr r1, .L0806EC60 @ =0x0000044A
	adds r0, r5, r1
	movs r1, #3
	movs r2, #0x16
	bl PutSpecialChar
	movs r2, #0xf2
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r1, [r7, #0xc]
	movs r2, #8
	ldrsb r2, [r1, r2]
	movs r1, #2
	bl PutNumberOrBlank
	ldr r3, .L0806EC64 @ =0x000003CE
	adds r0, r5, r3
	ldr r1, [r7, #0xc]
	ldrb r2, [r1, #9]
	movs r1, #2
	bl PutNumberOrBlank
	movs r0, #0x89
	lsls r0, r0, #3
	adds r4, r5, r0
	ldr r0, [r7, #0xc]
	bl GetUnitCurrentHp
	adds r2, r0, #0
	adds r0, r4, #0
	movs r1, #2
	bl PutNumberOrBlank
	ldr r1, .L0806EC68 @ =0x0000044E
	adds r5, r5, r1
	ldr r0, [r7, #0xc]
	bl GetUnitMaxHp
	adds r2, r0, #0
	adds r0, r5, #0
	movs r1, #2
	bl PutNumberOrBlank
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0806EC48: .4byte 0x02003108
.L0806EC4C: .4byte gBg0Tm
.L0806EC50: .4byte 0x00000342
.L0806EC54: .4byte 0x000003C2
.L0806EC58: .4byte 0x000003CA
.L0806EC5C: .4byte 0x00000442
.L0806EC60: .4byte 0x0000044A
.L0806EC64: .4byte 0x000003CE
.L0806EC68: .4byte 0x0000044E

	thumb_func_start func_fe6_0806EC6C
func_fe6_0806EC6C: @ 0x0806EC6C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov sl, r0
	mov r8, r1
	str r2, [sp, #0xc]
	adds r7, r3, #0
	ldr r5, [sp, #0x30]
	subs r0, r5, r7
	mov sb, r0
	lsls r6, r2, #5
	adds r0, r6, r1
	lsls r0, r0, #1
	ldr r4, .L0806ED28 @ =0x02003238
	adds r0, r0, r4
	movs r1, #2
	ldr r2, [sp, #0x34]
	cmp r7, r2
	bne .L0806EC9A
	movs r1, #4
.L0806EC9A:
	adds r2, r7, #0
	bl PutNumberOrBlank
	adds r1, r6, #1
	add r1, r8
	lsls r1, r1, #1
	adds r1, r1, r4
	mov r0, sb
	bl PutNumberBonus
	cmp r5, #0x1e
	ble .L0806ECB8
	movs r5, #0x1e
	subs r5, r5, r7
	mov sb, r5
.L0806ECB8:
	mov r0, sl
	lsls r5, r0, #1
	add r5, sl
	lsls r5, r5, #1
	ldr r1, .L0806ED2C @ =0x00000401
	adds r5, r5, r1
	ldr r4, [sp, #0xc]
	adds r4, #1
	lsls r4, r4, #5
	subs r4, #2
	add r4, r8
	lsls r4, r4, #1
	ldr r0, .L0806ED30 @ =0x02003C38
	adds r4, r4, r0
	movs r6, #0xc0
	lsls r6, r6, #7
	ldr r2, [sp, #0x34]
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r0, r0, r2
	movs r1, #0x1e
	bl __divsi3
	str r0, [sp]
	lsls r0, r7, #2
	adds r0, r0, r7
	lsls r0, r0, #3
	adds r0, r0, r7
	movs r1, #0x1e
	bl __divsi3
	str r0, [sp, #4]
	mov r1, sb
	lsls r0, r1, #2
	add r0, sb
	lsls r0, r0, #3
	add r0, sb
	movs r1, #0x1e
	bl __divsi3
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r1, #6
	adds r2, r4, #0
	adds r3, r6, #0
	bl func_fe6_0806E998
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0806ED28: .4byte 0x02003238
.L0806ED2C: .4byte 0x00000401
.L0806ED30: .4byte 0x02003C38

	thumb_func_start func_fe6_0806ED34
func_fe6_0806ED34: @ 0x0806ED34
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	ldr r0, .L0806ED80 @ =gUnk_08307D58
	ldr r4, .L0806ED84 @ =gBuf
	adds r1, r4, #0
	bl Decompress
	ldr r0, .L0806ED88 @ =0x02003738
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r4, #0
	bl TmApplyTsa_t
	ldr r0, .L0806ED8C @ =gUnk_083193EC
	bl func_fe6_0806EB00
	ldr r4, .L0806ED90 @ =0x02003108
	ldr r0, [r4, #0xc]
	bl UnitKnowsMagic
	lsls r0, r0, #0x18
	asrs r2, r0, #0x18
	cmp r2, #0
	beq .L0806ED9C
	adds r0, r4, #0
	adds r0, #0x30
	ldr r1, .L0806ED94 @ =0x0200327A
	movs r2, #0
	str r2, [sp]
	ldr r2, .L0806ED98 @ =gUnk_083195AC
	str r2, [sp, #4]
	movs r2, #3
	movs r3, #0
	bl PutDrawText
	b .L0806EDB0
	.align 2, 0
.L0806ED80: .4byte gUnk_08307D58
.L0806ED84: .4byte gBuf
.L0806ED88: .4byte 0x02003738
.L0806ED8C: .4byte gUnk_083193EC
.L0806ED90: .4byte 0x02003108
.L0806ED94: .4byte 0x0200327A
.L0806ED98: .4byte gUnk_083195AC
.L0806ED9C:
	adds r0, r4, #0
	adds r0, #0x30
	ldr r1, .L0806EFD0 @ =0x0200327A
	str r2, [sp]
	ldr r2, .L0806EFD4 @ =gUnk_083195B4
	str r2, [sp, #4]
	movs r2, #3
	movs r3, #4
	bl PutDrawText
.L0806EDB0:
	ldr r6, .L0806EFD8 @ =0x02003108
	ldr r0, [r6, #0xc]
	bl GetUnitPower
	ldr r1, [r6, #0xc]
	movs r3, #0x12
	ldrsb r3, [r1, r3]
	str r0, [sp]
	ldr r0, [r1, #4]
	ldrb r0, [r0, #0x14]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #5
	movs r2, #1
	bl func_fe6_0806EC6C
	ldr r0, [r6, #0xc]
	bl GetUnitSkill
	adds r4, r0, #0
	ldr r2, [r6, #0xc]
	ldrb r1, [r2, #0x13]
	movs r5, #0x10
	adds r0, r5, #0
	ldrh r3, [r2, #0xc]
	ands r0, r3
	cmp r0, #0
	beq .L0806EDF6
	lsls r0, r1, #0x18
	asrs r1, r0, #0x18
	lsrs r0, r0, #0x1f
	adds r1, r1, r0
	lsrs r1, r1, #1
.L0806EDF6:
	lsls r0, r1, #0x18
	asrs r3, r0, #0x18
	str r4, [sp]
	ldr r0, [r2, #4]
	ldrb r1, [r0, #0x15]
	adds r0, r5, #0
	ldrh r2, [r2, #0xc]
	ands r0, r2
	cmp r0, #0
	beq .L0806EE14
	lsls r0, r1, #0x18
	asrs r1, r0, #0x18
	lsrs r0, r0, #0x1f
	adds r1, r1, r0
	lsrs r1, r1, #1
.L0806EE14:
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #5
	movs r2, #3
	bl func_fe6_0806EC6C
	ldr r0, [r6, #0xc]
	bl GetUnitSpeed
	adds r4, r0, #0
	ldr r2, [r6, #0xc]
	ldrb r1, [r2, #0x14]
	adds r0, r5, #0
	ldrh r3, [r2, #0xc]
	ands r0, r3
	cmp r0, #0
	beq .L0806EE44
	lsls r0, r1, #0x18
	asrs r1, r0, #0x18
	lsrs r0, r0, #0x1f
	adds r1, r1, r0
	lsrs r1, r1, #1
.L0806EE44:
	lsls r0, r1, #0x18
	asrs r3, r0, #0x18
	str r4, [sp]
	ldr r0, [r2, #4]
	ldrb r1, [r0, #0x16]
	adds r0, r5, #0
	ldrh r2, [r2, #0xc]
	ands r0, r2
	cmp r0, #0
	beq .L0806EE62
	lsls r0, r1, #0x18
	asrs r1, r0, #0x18
	lsrs r0, r0, #0x1f
	adds r1, r1, r0
	lsrs r1, r1, #1
.L0806EE62:
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #5
	movs r2, #5
	bl func_fe6_0806EC6C
	ldr r0, [r6, #0xc]
	bl GetUnitLuck
	ldr r1, [r6, #0xc]
	movs r3, #0x17
	ldrsb r3, [r1, r3]
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	movs r0, #3
	movs r1, #5
	movs r2, #7
	bl func_fe6_0806EC6C
	ldr r0, [r6, #0xc]
	bl GetUnitDefense
	ldr r1, [r6, #0xc]
	movs r3, #0x15
	ldrsb r3, [r1, r3]
	str r0, [sp]
	ldr r0, [r1, #4]
	ldrb r0, [r0, #0x17]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	str r0, [sp, #4]
	movs r0, #4
	movs r1, #5
	movs r2, #9
	bl func_fe6_0806EC6C
	ldr r0, [r6, #0xc]
	bl GetUnitResistance
	ldr r1, [r6, #0xc]
	movs r3, #0x16
	ldrsb r3, [r1, r3]
	str r0, [sp]
	ldr r0, [r1, #4]
	ldrb r0, [r0, #0x18]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	str r0, [sp, #4]
	movs r0, #5
	movs r1, #5
	movs r2, #0xb
	bl func_fe6_0806EC6C
	ldr r1, [r6, #0xc]
	ldr r0, [r1, #4]
	movs r3, #0x12
	ldrsb r3, [r0, r3]
	movs r0, #0x1a
	ldrsb r0, [r1, r0]
	adds r0, r0, r3
	str r0, [sp]
	movs r5, #0xf
	str r5, [sp, #4]
	movs r0, #6
	movs r1, #0xd
	movs r2, #1
	bl func_fe6_0806EC6C
	ldr r1, [r6, #0xc]
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
	adds r0, r3, r0
	str r0, [sp]
	ldr r0, [r1, #4]
	ldrb r0, [r0, #0x19]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	str r0, [sp, #4]
	movs r0, #7
	movs r1, #0xd
	movs r2, #3
	bl func_fe6_0806EC6C
	ldr r7, .L0806EFDC @ =0x02003392
	ldr r0, [r6, #0xc]
	bl GetUnitAid
	adds r2, r0, #0
	adds r0, r7, #0
	movs r1, #2
	bl PutNumber
	adds r4, r7, #2
	ldr r0, [r6, #0xc]
	ldr r1, [r0]
	ldr r2, [r0, #4]
	ldr r0, [r1, #0x28]
	ldr r1, [r2, #0x24]
	orrs r0, r1
	bl GetAidIconFromAttributes
	adds r1, r0, #0
	movs r0, #0xa0
	lsls r0, r0, #7
	mov r8, r0
	adds r0, r4, #0
	mov r2, r8
	bl PutIcon
	adds r4, r6, #0
	adds r4, #0x78
	ldr r0, [r6, #0xc]
	bl GetUnitRescueName
	adds r3, r0, #0
	adds r0, r4, #0
	movs r1, #0x18
	movs r2, #2
	bl Text_InsertDrawString
	adds r4, #0x10
	ldr r0, [r6, #0xc]
	bl GetUnitStatusName
	adds r3, r0, #0
	adds r0, r4, #0
	movs r1, #0x18
	movs r2, #2
	bl Text_InsertDrawString
	ldr r0, [r6, #0xc]
	adds r0, #0x2e
	ldrb r2, [r0]
	ands r5, r2
	cmp r5, #0
	beq .L0806EF96
	movs r1, #0xc3
	lsls r1, r1, #1
	adds r0, r7, r1
	lsrs r2, r2, #4
	movs r1, #0
	bl PutNumberSmall
.L0806EF96:
	adds r4, r7, #0
	adds r4, #0xfe
	ldr r0, [r6, #0xc]
	bl GetUnitAffinityIcon
	adds r1, r0, #0
	adds r0, r4, #0
	mov r2, r8
	bl PutIcon
	adds r4, r6, #0
	adds r4, #0x80
	ldr r0, [r6, #0xc]
	ldr r0, [r0]
	ldrb r0, [r0, #9]
	bl GetAffinityName
	adds r3, r0, #0
	adds r0, r4, #0
	movs r1, #0x28
	movs r2, #2
	bl Text_InsertDrawString
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0806EFD0: .4byte 0x0200327A
.L0806EFD4: .4byte gUnk_083195B4
.L0806EFD8: .4byte 0x02003108
.L0806EFDC: .4byte 0x02003392

	thumb_func_start func_fe6_0806EFE0
func_fe6_0806EFE0: @ 0x0806EFE0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, .L0806F130 @ =gUnk_08307DD4
	ldr r4, .L0806F134 @ =gBuf
	adds r1, r4, #0
	bl Decompress
	ldr r0, .L0806F138 @ =0x02003738
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r4, #0
	bl TmApplyTsa_t
	ldr r0, .L0806F13C @ =gUnk_08308070
	adds r1, r4, #0
	bl Decompress
	ldr r0, .L0806F140 @ =0x02003EFA
	ldr r2, .L0806F144 @ =0x00007060
	adds r1, r4, #0
	bl TmApplyTsa_t
	ldr r0, .L0806F148 @ =gUnk_083194AC
	bl func_fe6_0806EB00
	movs r4, #0
	ldr r1, .L0806F14C @ =0x02003108
	ldr r0, [r1, #0xc]
	ldrh r5, [r0, #0x1c]
	cmp r5, #0
	beq .L0806F064
	mov sb, r1
	mov r8, r4
	movs r7, #0x40
	mov r6, sb
	adds r6, #0x90
.L0806F02C:
	mov r1, sb
	ldr r0, [r1, #0xc]
	adds r1, r5, #0
	bl IsItemDisplayUseable
	adds r2, r0, #0
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	ldr r3, .L0806F150 @ =0x0200323A
	adds r3, r7, r3
	adds r0, r6, #0
	adds r1, r5, #0
	bl func_fe6_08016860
	movs r3, #2
	add r8, r3
	adds r7, #0x80
	adds r6, #8
	adds r4, #1
	cmp r4, #4
	bgt .L0806F064
	mov r1, sb
	ldr r0, [r1, #0xc]
	adds r0, #0x1c
	add r0, r8
	ldrh r5, [r0]
	cmp r5, #0
	bne .L0806F02C
.L0806F064:
	ldr r7, .L0806F14C @ =0x02003108
	ldr r0, [r7, #0xc]
	bl GetUnitEquippedWeaponSlot
	adds r4, r0, #0
	movs r5, #0
	cmp r4, #0
	blt .L0806F09E
	lsls r4, r4, #1
	adds r0, r4, #1
	lsls r0, r0, #6
	ldr r1, .L0806F154 @ =0x02003258
	adds r0, r0, r1
	movs r1, #0
	movs r2, #0x1f
	bl PutSpecialChar
	adds r0, r4, #2
	lsls r0, r0, #6
	ldr r1, .L0806F158 @ =0x02003C3A
	adds r0, r0, r1
	ldr r1, .L0806F15C @ =gUnk_083080AC
	ldr r2, .L0806F144 @ =0x00007060
	bl TmApplyTsa_t
	ldr r0, [r7, #0xc]
	adds r0, #0x1c
	adds r0, r0, r4
	ldrh r5, [r0]
.L0806F09E:
	ldr r6, .L0806F160 @ =0x02003588
	ldr r4, .L0806F164 @ =gBattleUnitA
	adds r0, r4, #0
	adds r0, #0x58
	movs r3, #0
	ldrsh r2, [r0, r3]
	adds r0, r6, #0
	movs r1, #2
	bl PutNumberOrBlank
	adds r0, r6, #0
	adds r0, #0x80
	adds r1, r4, #0
	adds r1, #0x5e
	movs r3, #0
	ldrsh r2, [r1, r3]
	movs r1, #2
	bl PutNumberOrBlank
	adds r0, r6, #0
	adds r0, #0xe
	adds r1, r4, #0
	adds r1, #0x64
	movs r3, #0
	ldrsh r2, [r1, r3]
	movs r1, #2
	bl PutNumberOrBlank
	adds r0, r6, #0
	adds r0, #0x8e
	adds r1, r4, #0
	adds r1, #0x60
	movs r3, #0
	ldrsh r2, [r1, r3]
	movs r1, #2
	bl PutNumberOrBlank
	adds r4, r7, #0
	adds r4, #0xb8
	adds r0, r5, #0
	bl GetItemRangeString
	adds r3, r0, #0
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #2
	bl Text_InsertDrawString
	movs r4, #0
	ldr r0, .L0806F168 @ =0x00005278
	adds r5, r0, #0
	adds r2, r6, #0
	subs r2, #0x8c
	ldr r1, .L0806F16C @ =0x00005270
	adds r3, r1, #0
	adds r1, r6, #0
	subs r1, #0x4c
.L0806F110:
	adds r0, r4, r5
	strh r0, [r2]
	adds r0, r4, r3
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	adds r4, #1
	cmp r4, #7
	ble .L0806F110
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0806F130: .4byte gUnk_08307DD4
.L0806F134: .4byte gBuf
.L0806F138: .4byte 0x02003738
.L0806F13C: .4byte gUnk_08308070
.L0806F140: .4byte 0x02003EFA
.L0806F144: .4byte 0x00007060
.L0806F148: .4byte gUnk_083194AC
.L0806F14C: .4byte 0x02003108
.L0806F150: .4byte 0x0200323A
.L0806F154: .4byte 0x02003258
.L0806F158: .4byte 0x02003C3A
.L0806F15C: .4byte gUnk_083080AC
.L0806F160: .4byte 0x02003588
.L0806F164: .4byte gBattleUnitA
.L0806F168: .4byte 0x00005278
.L0806F16C: .4byte 0x00005270

	thumb_func_start func_fe6_0806F170
func_fe6_0806F170: @ 0x0806F170
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	movs r0, #6
	str r0, [sp, #8]
	ldr r4, .L0806F258 @ =0x02003108
	ldr r0, [r4, #0xc]
	bl GetUnitTotalSupportLevel
	movs r1, #0
	str r1, [sp, #0xc]
	cmp r0, #5
	bne .L0806F194
	movs r0, #4
	str r0, [sp, #0xc]
.L0806F194:
	ldr r0, [r4, #0xc]
	bl GetUnitSupportCount
	mov sl, r0
	movs r1, #0
	mov sb, r1
	movs r0, #0
	cmp r0, sl
	bge .L0806F248
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, .L0806F258 @ =0x02003108
	adds r1, r0, r1
	str r1, [sp, #0x10]
.L0806F1B0:
	ldr r1, .L0806F258 @ =0x02003108
	ldr r0, [r1, #0xc]
	mov r1, sb
	bl GetUnitSupportLevel
	adds r7, r0, #0
	cmp r7, #0
	beq .L0806F240
	ldr r1, .L0806F258 @ =0x02003108
	ldr r0, [r1, #0xc]
	mov r1, sb
	bl GetUnitSupportPid
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r0, [sp, #8]
	lsls r6, r0, #6
	ldr r1, .L0806F25C @ =0x02003240
	mov r8, r1
	adds r5, r6, r1
	adds r0, r4, #0
	bl GetAffinityIconByPid
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0xa0
	lsls r2, r2, #7
	bl PutIcon
	adds r0, r4, #0
	bl GetPInfo
	ldrh r0, [r0]
	bl DecodeMsg
	mov r1, r8
	adds r1, #6
	adds r1, r6, r1
	movs r2, #0
	str r2, [sp]
	str r0, [sp, #4]
	ldr r0, [sp, #0x10]
	ldr r2, [sp, #0xc]
	movs r3, #0
	bl PutDrawText
	movs r5, #2
	cmp r7, #3
	bne .L0806F216
	movs r5, #4
.L0806F216:
	ldr r0, [sp, #0xc]
	cmp r0, #4
	bne .L0806F21E
	movs r5, #4
.L0806F21E:
	mov r4, r8
	adds r4, #0x12
	adds r4, r6, r4
	adds r0, r7, #0
	bl GetSupportLevelSpecialChar
	adds r2, r0, #0
	adds r0, r4, #0
	adds r1, r5, #0
	bl PutSpecialChar
	ldr r1, [sp, #8]
	adds r1, #2
	str r1, [sp, #8]
	ldr r0, [sp, #0x10]
	adds r0, #8
	str r0, [sp, #0x10]
.L0806F240:
	movs r1, #1
	add sb, r1
	cmp sb, sl
	blt .L0806F1B0
.L0806F248:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0806F258: .4byte 0x02003108
.L0806F25C: .4byte 0x02003240

	thumb_func_start func_fe6_0806F260
func_fe6_0806F260: @ 0x0806F260
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sb, r0
	adds r6, r1, #0
	mov sl, r2
	adds r1, r3, #0
	ldr r0, .L0806F314 @ =0x02003108
	ldr r0, [r0, #0xc]
	adds r0, #0x26
	adds r0, r0, r1
	ldrb r7, [r0]
	lsls r4, r2, #5
	adds r0, r4, r6
	lsls r0, r0, #1
	ldr r2, .L0806F318 @ =0x02003238
	mov r8, r2
	add r0, r8
	adds r1, #0x70
	movs r2, #0xa0
	lsls r2, r2, #7
	bl PutIcon
	movs r5, #2
	cmp r7, #0xfa
	ble .L0806F29C
	movs r5, #4
.L0806F29C:
	adds r4, #5
	adds r4, r4, r6
	lsls r4, r4, #1
	add r4, r8
	adds r0, r7, #0
	bl GetWeaponLevelSpecialCharFromExp
	adds r2, r0, #0
	adds r0, r4, #0
	adds r1, r5, #0
	bl PutSpecialChar
	cmp r7, #0
	beq .L0806F2BA
	subs r7, #1
.L0806F2BA:
	mov r0, sb
	lsls r5, r0, #1
	add r5, sb
	lsls r5, r5, #1
	ldr r2, .L0806F31C @ =0x00000401
	adds r5, r5, r2
	mov r4, sl
	adds r4, #1
	lsls r4, r4, #5
	adds r4, #3
	adds r4, r4, r6
	lsls r4, r4, #1
	ldr r0, .L0806F320 @ =0x02003C38
	adds r4, r4, r0
	movs r6, #0xc0
	lsls r6, r6, #7
	movs r0, #0x22
	str r0, [sp]
	adds r0, r7, #0
	movs r1, #0x32
	bl __modsi3
	adds r1, r0, #0
	lsls r0, r1, #5
	adds r0, r0, r1
	movs r1, #0x30
	bl __divsi3
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r1, #5
	adds r2, r4, #0
	adds r3, r6, #0
	bl func_fe6_0806E998
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0806F314: .4byte 0x02003108
.L0806F318: .4byte 0x02003238
.L0806F31C: .4byte 0x00000401
.L0806F320: .4byte 0x02003C38

	thumb_func_start func_fe6_0806F324
func_fe6_0806F324: @ 0x0806F324
	push {r4, lr}
	ldr r0, .L0806F384 @ =gUnk_08307E50
	ldr r4, .L0806F388 @ =gBuf
	adds r1, r4, #0
	bl Decompress
	ldr r0, .L0806F38C @ =0x02003738
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r4, #0
	bl TmApplyTsa_t
	ldr r0, .L0806F390 @ =0x02003108
	ldr r0, [r0, #0xc]
	bl UnitKnowsMagic
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L0806F398
	ldr r0, .L0806F394 @ =gUnk_0831955C
	bl func_fe6_0806EB00
	movs r0, #0
	movs r1, #1
	movs r2, #1
	movs r3, #5
	bl func_fe6_0806F260
	movs r0, #1
	movs r1, #1
	movs r2, #3
	movs r3, #6
	bl func_fe6_0806F260
	movs r0, #2
	movs r1, #9
	movs r2, #1
	movs r3, #7
	bl func_fe6_0806F260
	movs r0, #3
	movs r1, #9
	movs r2, #3
	movs r3, #4
	bl func_fe6_0806F260
	b .L0806F3CE
	.align 2, 0
.L0806F384: .4byte gUnk_08307E50
.L0806F388: .4byte gBuf
.L0806F38C: .4byte 0x02003738
.L0806F390: .4byte 0x02003108
.L0806F394: .4byte gUnk_0831955C
.L0806F398:
	ldr r0, .L0806F3D8 @ =gUnk_0831950C
	bl func_fe6_0806EB00
	movs r0, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0
	bl func_fe6_0806F260
	movs r0, #1
	movs r1, #1
	movs r2, #3
	movs r3, #1
	bl func_fe6_0806F260
	movs r0, #2
	movs r1, #9
	movs r2, #1
	movs r3, #2
	bl func_fe6_0806F260
	movs r0, #3
	movs r1, #9
	movs r2, #3
	movs r3, #3
	bl func_fe6_0806F260
.L0806F3CE:
	bl func_fe6_0806F170
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0806F3D8: .4byte gUnk_0831950C

	thumb_func_start func_fe6_0806F3DC
func_fe6_0806F3DC: @ 0x0806F3DC
	push {r4, r5, lr}
	sub sp, #0x18
	adds r4, r0, #0
	mov r1, sp
	ldr r0, .L0806F41C @ =gUnk_083195B8
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldr r0, [r0]
	str r0, [r1]
	movs r5, #0
	str r5, [sp, #0x10]
	add r0, sp, #0x10
	ldr r1, .L0806F420 @ =0x02003238
	ldr r2, .L0806F424 @ =0x01000140
	bl CpuFastSet
	str r5, [sp, #0x14]
	add r0, sp, #0x14
	ldr r1, .L0806F428 @ =0x02003C38
	ldr r2, .L0806F42C @ =0x01000120
	bl CpuFastSet
	lsls r4, r4, #2
	mov r1, sp
	adds r0, r1, r4
	ldr r0, [r0]
	bl _call_via_r0
	add sp, #0x18
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0806F41C: .4byte gUnk_083195B8
.L0806F420: .4byte 0x02003238
.L0806F424: .4byte 0x01000140
.L0806F428: .4byte 0x02003C38
.L0806F42C: .4byte 0x01000120

	thumb_func_start func_fe6_0806F430
func_fe6_0806F430: @ 0x0806F430
	push {r4, r5, r6, r7, lr}
	adds r6, r1, #0
	ldrb r0, [r0, #0xb]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r5, #0xc0
	ands r5, r0
	adds r4, r0, #0
	ldr r7, .L0806F46C @ =0x0203D3DC
.L0806F442:
	adds r4, r4, r6
	movs r0, #0x3f
	ands r4, r0
	adds r0, r5, r4
	bl GetUnit
	adds r1, r0, #0
	cmp r1, #0
	beq .L0806F442
	ldr r0, [r1]
	cmp r0, #0
	beq .L0806F442
	ldrh r0, [r1, #0xc]
	ldrh r2, [r7, #2]
	ands r0, r2
	cmp r0, #0
	bne .L0806F442
	adds r0, r1, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
.L0806F46C: .4byte 0x0203D3DC

	thumb_func_start func_fe6_0806F470
func_fe6_0806F470: @ 0x0806F470
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r0, .L0806F4F0 @ =gBg0Tm+0x98
	movs r1, #0x12
	movs r2, #0x12
	movs r3, #0
	bl TmFillRect_t
	ldr r0, .L0806F4F4 @ =gBg1Tm+0x98
	movs r1, #0x12
	movs r2, #0x12
	movs r3, #0
	bl TmFillRect_t
	ldr r0, .L0806F4F8 @ =gBg2Tm+0x98
	movs r1, #0x12
	movs r2, #0x12
	movs r3, #0
	bl TmFillRect_t
	ldr r6, .L0806F4FC @ =gUnk_08677510
	adds r4, r7, #0
	adds r4, #0x4c
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r0, r0, r6
	movs r5, #0
	ldrsb r5, [r0, r5]
	cmp r5, #0x7f
	bne .L0806F4C8
	adds r0, r7, #0
	adds r0, #0x4a
	movs r2, #0
	ldrsh r0, [r0, r2]
	bl func_fe6_0806F3DC
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r0, r0, r6
	movs r5, #0
	ldrsb r5, [r0, r5]
.L0806F4C8:
	adds r1, r7, #0
	adds r1, #0x52
	movs r0, #0x20
	ldrh r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq .L0806F4D8
	rsbs r5, r5, #0
.L0806F4D8:
	adds r2, r5, #0
	cmp r5, #0
	bge .L0806F4E0
	rsbs r2, r5, #0
.L0806F4E0:
	movs r0, #0x12
	subs r6, r0, r2
	cmp r5, #0
	bge .L0806F500
	movs r4, #0
	rsbs r5, r5, #0
	b .L0806F504
	.align 2, 0
.L0806F4F0: .4byte gBg0Tm+0x98
.L0806F4F4: .4byte gBg1Tm+0x98
.L0806F4F8: .4byte gBg2Tm+0x98
.L0806F4FC: .4byte gUnk_08677510
.L0806F500:
	adds r4, r5, #0
	movs r5, #0
.L0806F504:
	lsls r5, r5, #1
	ldr r0, .L0806F56C @ =0x02003238
	adds r0, r5, r0
	lsls r4, r4, #1
	ldr r1, .L0806F570 @ =gBg0Tm+0x98
	adds r1, r4, r1
	adds r2, r6, #0
	movs r3, #0x12
	bl TmCopyRect_t
	ldr r0, .L0806F574 @ =0x02003738
	adds r0, r5, r0
	ldr r1, .L0806F578 @ =gBg1Tm+0x98
	adds r1, r4, r1
	adds r2, r6, #0
	movs r3, #0x12
	bl TmCopyRect_t
	ldr r0, .L0806F57C @ =0x02003C38
	adds r5, r5, r0
	ldr r0, .L0806F580 @ =gBg2Tm+0x98
	adds r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	movs r3, #0x12
	bl TmCopyRect_t
	movs r0, #7
	bl EnableBgSync
	adds r0, r7, #0
	adds r0, #0x4c
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	ldr r1, .L0806F584 @ =gUnk_08677510
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r0, r0, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r5, r0
	bne .L0806F566
	adds r0, r7, #0
	bl Proc_Break
.L0806F566:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0806F56C: .4byte 0x02003238
.L0806F570: .4byte gBg0Tm+0x98
.L0806F574: .4byte 0x02003738
.L0806F578: .4byte gBg1Tm+0x98
.L0806F57C: .4byte 0x02003C38
.L0806F580: .4byte gBg2Tm+0x98
.L0806F584: .4byte gUnk_08677510

	thumb_func_start func_fe6_0806F588
func_fe6_0806F588: @ 0x0806F588
	ldr r1, .L0806F590 @ =0x02003108
	movs r0, #0
	strb r0, [r1, #8]
	bx lr
	.align 2, 0
.L0806F590: .4byte 0x02003108

	thumb_func_start func_fe6_0806F594
func_fe6_0806F594: @ 0x0806F594
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r1
	adds r6, r2, #0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r7, .L0806F5EC @ =gUnk_08677520
	adds r0, r7, #0
	bl Proc_Find
	adds r4, r0, #0
	cmp r4, #0
	bne .L0806F5E2
	ldr r0, .L0806F5F0 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0806F5C0
	movs r0, #0x6f
	bl m4aSongNumStart
.L0806F5C0:
	adds r0, r7, #0
	adds r1, r6, #0
	bl SpawnProcLocking
	adds r1, r0, #0
	adds r0, #0x4c
	strh r4, [r0]
	subs r0, #2
	mov r2, r8
	strh r2, [r0]
	adds r0, #8
	strh r5, [r0]
	ldr r0, .L0806F5F4 @ =0x02003108
	strh r5, [r0, #2]
	str r4, [r0, #0x14]
	movs r1, #1
	strb r1, [r0, #8]
.L0806F5E2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0806F5EC: .4byte gUnk_08677520
.L0806F5F0: .4byte gPlaySt
.L0806F5F4: .4byte 0x02003108

	thumb_func_start func_fe6_0806F5F8
func_fe6_0806F5F8: @ 0x0806F5F8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, .L0806F66C @ =0x02003108
	movs r6, #0
	movs r4, #1
	movs r0, #1
	strb r0, [r1, #8]
	adds r1, r5, #0
	adds r1, #0x4c
	movs r0, #4
	strh r0, [r1]
	ldr r3, .L0806F670 @ =gDispIo
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r2, #0
	ldrb r1, [r3, #0xc]
	ands r0, r1
	orrs r0, r4
	strb r0, [r3, #0xc]
	movs r0, #3
	ldrb r1, [r3, #0x10]
	orrs r0, r1
	strb r0, [r3, #0x10]
	adds r0, r2, #0
	ldrb r1, [r3, #0x14]
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r3, #0x14]
	ldrb r0, [r3, #0x18]
	ands r2, r0
	strb r2, [r3, #0x18]
	ldr r0, .L0806F674 @ =0x0000FFE0
	ldrh r1, [r3, #0x3c]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	ldr r1, .L0806F678 @ =0x0000E0FF
	ands r0, r1
	movs r2, #0xb8
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r3, #0x3c]
	adds r3, #0x3d
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrb r1, [r3]
	ands r0, r1
	strb r0, [r3]
	ldr r0, [r5, #0x38]
	cmp r0, #0
	ble .L0806F67C
	str r6, [r5, #0x3c]
	movs r0, #0x3c
	rsbs r0, r0, #0
	b .L0806F680
	.align 2, 0
.L0806F66C: .4byte 0x02003108
.L0806F670: .4byte gDispIo
.L0806F674: .4byte 0x0000FFE0
.L0806F678: .4byte 0x0000E0FF
.L0806F67C:
	str r6, [r5, #0x3c]
	movs r0, #0x3c
.L0806F680:
	str r0, [r5, #0x40]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0806F688
func_fe6_0806F688: @ 0x0806F688
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r3, .L0806F700 @ =gDispIo
	adds r2, r3, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r5, r6, #0
	adds r5, #0x4c
	ldrh r1, [r5]
	adds r0, r3, #0
	adds r0, #0x44
	movs r2, #0
	strb r1, [r0]
	movs r0, #0x10
	subs r0, r0, r1
	adds r1, r3, #0
	adds r1, #0x45
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x46
	strb r2, [r0]
	ldr r4, .L0806F704 @ =0x02003108
	ldr r0, [r4, #0x10]
	movs r1, #6
	ldrsh r2, [r4, r1]
	adds r2, #0x8a
	movs r1, #0x50
	bl SetMuScreenPosition
	ldr r1, [r6, #0x3c]
	ldr r2, [r6, #0x40]
	movs r0, #0
	ldrsh r3, [r5, r0]
	movs r0, #0x10
	str r0, [sp]
	movs r0, #2
	bl Interpolate
	strh r0, [r4, #6]
	ldrh r0, [r5]
	adds r0, #3
	strh r0, [r5]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x10
	ble .L0806F6F6
	adds r0, r6, #0
	bl Proc_Break
.L0806F6F6:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0806F700: .4byte gDispIo
.L0806F704: .4byte 0x02003108

	thumb_func_start func_fe6_0806F708
func_fe6_0806F708: @ 0x0806F708
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x4c
	movs r5, #0
	movs r0, #1
	strh r0, [r1]
	ldr r3, .L0806F764 @ =gDispIo
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r2, #0
	ldrb r1, [r3, #0xc]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r3, #0xc]
	movs r0, #3
	ldrb r1, [r3, #0x10]
	orrs r0, r1
	strb r0, [r3, #0x10]
	adds r0, r2, #0
	ldrb r1, [r3, #0x14]
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r3, #0x14]
	ldrb r0, [r3, #0x18]
	ands r2, r0
	strb r2, [r3, #0x18]
	ldr r0, .L0806F768 @ =0x0000FFE0
	ldrh r1, [r3, #0x3c]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	ldr r1, .L0806F76C @ =0x0000E0FF
	ands r0, r1
	movs r2, #0xb8
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r3, #0x3c]
	ldr r0, [r4, #0x38]
	cmp r0, #0
	ble .L0806F770
	movs r0, #0x3c
	b .L0806F774
	.align 2, 0
.L0806F764: .4byte gDispIo
.L0806F768: .4byte 0x0000FFE0
.L0806F76C: .4byte 0x0000E0FF
.L0806F770:
	movs r0, #0x3c
	rsbs r0, r0, #0
.L0806F774:
	str r0, [r4, #0x3c]
	str r5, [r4, #0x40]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806F780
func_fe6_0806F780: @ 0x0806F780
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r4, .L0806F7F4 @ =gDispIo
	adds r2, r4, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r5, r6, #0
	adds r5, #0x4c
	ldrh r2, [r5]
	movs r0, #0x10
	subs r0, r0, r2
	adds r1, r4, #0
	adds r1, #0x44
	movs r3, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x45
	strb r2, [r0]
	adds r0, #1
	strb r3, [r0]
	ldr r4, .L0806F7F8 @ =0x02003108
	ldr r0, [r4, #0x10]
	movs r1, #6
	ldrsh r2, [r4, r1]
	adds r2, #0x8a
	movs r1, #0x50
	bl SetMuScreenPosition
	ldr r1, [r6, #0x3c]
	ldr r2, [r6, #0x40]
	movs r0, #0
	ldrsh r3, [r5, r0]
	movs r0, #0x10
	str r0, [sp]
	movs r0, #5
	bl Interpolate
	strh r0, [r4, #6]
	ldrh r0, [r5]
	adds r0, #3
	strh r0, [r5]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf
	ble .L0806F7EC
	adds r0, r6, #0
	bl Proc_Break
.L0806F7EC:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0806F7F4: .4byte gDispIo
.L0806F7F8: .4byte 0x02003108

	thumb_func_start func_fe6_0806F7FC
func_fe6_0806F7FC: @ 0x0806F7FC
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x4a
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl GetUnit
	ldr r1, .L0806F820 @ =0x02003108
	str r0, [r1, #0xc]
	movs r0, #0
	bl func_fe6_0806FFDC
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0806F820: .4byte 0x02003108

	thumb_func_start func_fe6_0806F824
func_fe6_0806F824: @ 0x0806F824
	push {r4, r5, lr}
	ldr r4, .L0806F8A8 @ =0x02003108
	ldr r0, [r4, #0x10]
	cmp r0, #0
	beq .L0806F836
	movs r1, #0x50
	movs r2, #0x8a
	bl SetMuScreenPosition
.L0806F836:
	ldr r3, .L0806F8AC @ =gDispIo
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	ldrb r2, [r3, #0xc]
	ands r0, r2
	movs r2, #1
	orrs r0, r2
	strb r0, [r3, #0xc]
	movs r2, #3
	ldrb r0, [r3, #0x10]
	orrs r0, r2
	strb r0, [r3, #0x10]
	ldrb r5, [r3, #0x14]
	ands r1, r5
	movs r0, #2
	orrs r1, r0
	strb r1, [r3, #0x14]
	ldrb r0, [r3, #0x18]
	orrs r2, r0
	strb r2, [r3, #0x18]
	adds r2, r3, #0
	adds r2, #0x3c
	ldr r0, .L0806F8B0 @ =0x0000FFE0
	ldrh r1, [r3, #0x3c]
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	ldr r1, .L0806F8B4 @ =0x0000E0FF
	ands r0, r1
	movs r5, #0x80
	lsls r5, r5, #4
	adds r1, r5, #0
	orrs r0, r1
	strh r0, [r3, #0x3c]
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r1, r3, #0
	adds r1, #0x44
	movs r2, #0
	movs r0, #6
	strb r0, [r1]
	adds r1, #1
	movs r0, #8
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x46
	strb r2, [r0]
	strb r2, [r4, #8]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0806F8A8: .4byte 0x02003108
.L0806F8AC: .4byte gDispIo
.L0806F8B0: .4byte 0x0000FFE0
.L0806F8B4: .4byte 0x0000E0FF

	thumb_func_start func_fe6_0806F8B8
func_fe6_0806F8B8: @ 0x0806F8B8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r1, r2, #0
	ldr r0, .L0806F8E8 @ =gUnk_08677538
	bl SpawnProcLocking
	movs r1, #0xb
	ldrsb r1, [r4, r1]
	adds r2, r0, #0
	adds r2, #0x4a
	strh r1, [r2]
	str r5, [r0, #0x38]
	ldr r0, .L0806F8EC @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0806F8E2
	movs r0, #0xc8
	bl m4aSongNumStart
.L0806F8E2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0806F8E8: .4byte gUnk_08677538
.L0806F8EC: .4byte gPlaySt

	thumb_func_start func_fe6_0806F8F0
func_fe6_0806F8F0: @ 0x0806F8F0
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, .L0806F948 @ =0x02003108
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r1, #0x69
	movs r3, #6
	ldrsh r2, [r0, r3]
	adds r2, #5
	ldr r3, .L0806F94C @ =gUnk_08677578
	ldr r4, .L0806F950 @ =gUnk_0867758C
	lsls r0, r5, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r4, #0xf9
	lsls r4, r4, #6
	adds r0, r0, r4
	str r0, [sp]
	movs r0, #4
	bl PutSprite
	bl GetGameTime
	lsrs r0, r0, #2
	movs r1, #0xf
	ands r0, r1
	lsls r5, r5, #6
	lsls r0, r0, #1
	ldr r1, .L0806F954 @ =gUnk_083087C8
	adds r0, r0, r1
	adds r5, r5, r0
	ldr r1, .L0806F958 @ =gPal+0x268
	adds r0, r5, #0
	movs r2, #0xb
	bl CpuSet
	bl EnablePalSync
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0806F948: .4byte 0x02003108
.L0806F94C: .4byte gUnk_08677578
.L0806F950: .4byte gUnk_0867758C
.L0806F954: .4byte gUnk_083087C8
.L0806F958: .4byte gPal+0x268

	thumb_func_start func_fe6_0806F95C
func_fe6_0806F95C: @ 0x0806F95C
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #4
	mov sb, r0
	ldr r4, .L0806F9EC @ =gSinLut
	movs r0, #0x80
	adds r0, r0, r4
	mov sl, r0
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
	mov r1, r8
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
	mov r1, sl
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #4
	mov r1, r8
	bl Div
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	movs r0, #8
	adds r1, r6, #0
	adds r2, r5, #0
	adds r3, r4, #0
	bl SetObjAffine
	ldr r0, .L0806F9F0 @ =0x02003108
	ldrb r0, [r0]
	movs r1, #0x36
	add sb, r1
	mov r2, sb
	strb r0, [r2]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0806F9EC: .4byte gSinLut
.L0806F9F0: .4byte 0x02003108

	thumb_func_start func_fe6_0806F9F4
func_fe6_0806F9F4: @ 0x0806F9F4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x36
	ldrb r0, [r5]
	bl func_fe6_0806F8F0
	ldr r1, .L0806FA18 @ =0x02003108
	ldrh r0, [r1, #2]
	cmp r0, #0
	beq .L0806FA1C
	movs r0, #5
	strh r0, [r4, #0x38]
	adds r0, r4, #0
	bl Proc_Break
	b .L0806FA20
	.align 2, 0
.L0806FA18: .4byte 0x02003108
.L0806FA1C:
	ldrb r0, [r1]
	strb r0, [r5]
.L0806FA20:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0806FA28
func_fe6_0806FA28: @ 0x0806FA28
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r5, .L0806FAEC @ =gSinLut
	movs r0, #0x80
	adds r0, r0, r5
	mov sl, r0
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #4
	movs r2, #0x80
	lsls r2, r2, #1
	mov sb, r2
	mov r1, sb
	bl Div
	mov r8, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	movs r1, #0
	ldrsh r4, [r5, r1]
	rsbs r4, r4, #0
	lsls r4, r4, #4
	movs r2, #0x38
	ldrsh r0, [r7, r2]
	lsls r0, r0, #8
	movs r1, #6
	bl __divsi3
	adds r1, r0, #0
	adds r0, r4, #0
	bl Div
	adds r6, r0, #0
	lsls r6, r6, #0x10
	asrs r6, r6, #0x10
	movs r1, #0
	ldrsh r0, [r5, r1]
	lsls r0, r0, #4
	mov r1, sb
	bl Div
	adds r5, r0, #0
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	mov r2, sl
	movs r0, #0
	ldrsh r4, [r2, r0]
	lsls r4, r4, #4
	movs r1, #0x38
	ldrsh r0, [r7, r1]
	lsls r0, r0, #8
	movs r1, #6
	bl __divsi3
	adds r1, r0, #0
	adds r0, r4, #0
	bl Div
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	movs r0, #8
	mov r1, r8
	adds r2, r6, #0
	adds r3, r5, #0
	bl SetObjAffine
	adds r0, r7, #0
	adds r0, #0x36
	ldrb r0, [r0]
	bl func_fe6_0806F8F0
	ldrh r0, [r7, #0x38]
	subs r0, #1
	strh r0, [r7, #0x38]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne .L0806FADA
	movs r0, #1
	strh r0, [r7, #0x38]
	adds r0, r7, #0
	bl Proc_Break
.L0806FADA:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0806FAEC: .4byte gSinLut

	thumb_func_start func_fe6_0806FAF0
func_fe6_0806FAF0: @ 0x0806FAF0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r5, .L0806FBB8 @ =gSinLut
	movs r0, #0x80
	adds r0, r0, r5
	mov sl, r0
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #4
	movs r2, #0x80
	lsls r2, r2, #1
	mov sb, r2
	mov r1, sb
	bl Div
	mov r8, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	movs r1, #0
	ldrsh r4, [r5, r1]
	rsbs r4, r4, #0
	lsls r4, r4, #4
	movs r2, #0x38
	ldrsh r0, [r7, r2]
	lsls r0, r0, #8
	movs r1, #6
	bl __divsi3
	adds r1, r0, #0
	adds r0, r4, #0
	bl Div
	adds r6, r0, #0
	lsls r6, r6, #0x10
	asrs r6, r6, #0x10
	movs r1, #0
	ldrsh r0, [r5, r1]
	lsls r0, r0, #4
	mov r1, sb
	bl Div
	adds r5, r0, #0
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	mov r2, sl
	movs r0, #0
	ldrsh r4, [r2, r0]
	lsls r4, r4, #4
	movs r1, #0x38
	ldrsh r0, [r7, r1]
	lsls r0, r0, #8
	movs r1, #6
	bl __divsi3
	adds r1, r0, #0
	adds r0, r4, #0
	bl Div
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp]
	movs r0, #8
	mov r1, r8
	adds r2, r6, #0
	adds r3, r5, #0
	bl SetObjAffine
	ldr r4, .L0806FBBC @ =0x02003108
	ldrb r0, [r4]
	bl func_fe6_0806F8F0
	ldrh r0, [r7, #0x38]
	adds r0, #1
	strh r0, [r7, #0x38]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #6
	ble .L0806FBA6
	ldrb r0, [r4]
	adds r1, r7, #0
	adds r1, #0x36
	strb r0, [r1]
	adds r0, r7, #0
	bl Proc_Break
.L0806FBA6:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0806FBB8: .4byte gSinLut
.L0806FBBC: .4byte 0x02003108

	thumb_func_start func_fe6_0806FBC0
func_fe6_0806FBC0: @ 0x0806FBC0
	movs r2, #0
	movs r1, #0x65
	strh r1, [r0, #0x2a]
	movs r1, #0xc6
	strh r1, [r0, #0x2c]
	strh r2, [r0, #0x30]
	strh r2, [r0, #0x2e]
	movs r1, #4
	strh r1, [r0, #0x34]
	strh r1, [r0, #0x32]
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0806FBD8
func_fe6_0806FBD8: @ 0x0806FBD8
	adds r1, r0, #0
	ldr r2, .L0806FC08 @ =0x02003108
	movs r0, #0x20
	ldrh r3, [r2, #2]
	ands r0, r3
	cmp r0, #0
	beq .L0806FBEE
	movs r0, #0x1f
	strh r0, [r1, #0x32]
	movs r0, #0x5f
	strh r0, [r1, #0x2a]
.L0806FBEE:
	movs r0, #0x10
	ldrh r3, [r2, #2]
	ands r0, r3
	cmp r0, #0
	beq .L0806FC00
	movs r0, #0x1f
	strh r0, [r1, #0x34]
	movs r0, #0xcc
	strh r0, [r1, #0x2c]
.L0806FC00:
	movs r0, #0
	strh r0, [r2, #2]
	bx lr
	.align 2, 0
.L0806FC08: .4byte 0x02003108

	thumb_func_start func_fe6_0806FC0C
func_fe6_0806FC0C: @ 0x0806FC0C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, .L0806FCE4 @ =0x00004E40
	mov sb, r0
	ldrh r1, [r7, #0x32]
	ldrh r2, [r7, #0x2e]
	adds r0, r1, r2
	strh r0, [r7, #0x2e]
	ldrh r3, [r7, #0x30]
	ldrh r2, [r7, #0x34]
	adds r0, r3, r2
	strh r0, [r7, #0x30]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble .L0806FC38
	subs r0, r1, #1
	strh r0, [r7, #0x32]
.L0806FC38:
	ldrh r1, [r7, #0x34]
	movs r3, #0x34
	ldrsh r0, [r7, r3]
	cmp r0, #4
	ble .L0806FC46
	subs r0, r1, #1
	strh r0, [r7, #0x34]
.L0806FC46:
	bl GetGameTime
	movs r1, #3
	ands r1, r0
	cmp r1, #0
	bne .L0806FC6E
	ldrh r1, [r7, #0x2a]
	movs r2, #0x2a
	ldrsh r0, [r7, r2]
	cmp r0, #0x64
	bgt .L0806FC60
	adds r0, r1, #1
	strh r0, [r7, #0x2a]
.L0806FC60:
	ldrh r1, [r7, #0x2c]
	movs r3, #0x2c
	ldrsh r0, [r7, r3]
	cmp r0, #0xc6
	ble .L0806FC6E
	subs r0, r1, #1
	strh r0, [r7, #0x2c]
.L0806FC6E:
	ldr r6, .L0806FCE8 @ =0x02003108
	movs r0, #4
	ldrsh r5, [r6, r0]
	movs r1, #0x2a
	ldrsh r0, [r7, r1]
	adds r5, r5, r0
	movs r2, #6
	ldrsh r4, [r6, r2]
	adds r4, #6
	ldr r3, .L0806FCEC @ =Sprite_8x16
	mov r8, r3
	ldrh r1, [r7, #0x2e]
	lsrs r0, r1, #5
	movs r1, #6
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x4a
	add r0, sb
	str r0, [sp]
	movs r0, #4
	adds r1, r5, #0
	adds r2, r4, #0
	mov r3, r8
	bl PutSprite
	movs r2, #4
	ldrsh r5, [r6, r2]
	movs r3, #0x2c
	ldrsh r0, [r7, r3]
	adds r5, r5, r0
	movs r0, #6
	ldrsh r4, [r6, r0]
	adds r4, #6
	ldr r6, .L0806FCF0 @ =Sprite_8x16_HFlipped
	ldrh r7, [r7, #0x30]
	lsrs r0, r7, #5
	movs r1, #6
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x4a
	add r0, sb
	str r0, [sp]
	movs r0, #4
	adds r1, r5, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl PutSprite
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0806FCE4: .4byte 0x00004E40
.L0806FCE8: .4byte 0x02003108
.L0806FCEC: .4byte Sprite_8x16
.L0806FCF0: .4byte Sprite_8x16_HFlipped

	thumb_func_start func_fe6_0806FCF4
func_fe6_0806FCF4: @ 0x0806FCF4
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r4, .L0806FD54 @ =0x02003108
	movs r0, #4
	ldrsh r1, [r4, r0]
	adds r1, #0xe3
	movs r3, #6
	ldrsh r2, [r4, r3]
	adds r2, #0xc
	ldr r5, .L0806FD58 @ =Sprite_8x8
	ldrb r6, [r4, #1]
	ldr r3, .L0806FD5C @ =0x00004EA4
	adds r0, r6, r3
	str r0, [sp]
	movs r0, #2
	adds r3, r5, #0
	bl PutSprite
	movs r6, #4
	ldrsh r1, [r4, r6]
	adds r1, #0xdd
	movs r0, #6
	ldrsh r2, [r4, r0]
	adds r2, #0xc
	ldr r0, .L0806FD60 @ =0x00004E45
	str r0, [sp]
	movs r0, #2
	adds r3, r5, #0
	bl PutSprite
	movs r3, #4
	ldrsh r1, [r4, r3]
	adds r1, #0xd6
	movs r6, #6
	ldrsh r2, [r4, r6]
	adds r2, #0xc
	ldrb r4, [r4]
	ldr r3, .L0806FD64 @ =0x00004EA5
	adds r0, r4, r3
	str r0, [sp]
	movs r0, #2
	adds r3, r5, #0
	bl PutSprite
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0806FD54: .4byte 0x02003108
.L0806FD58: .4byte Sprite_8x8
.L0806FD5C: .4byte 0x00004EA4
.L0806FD60: .4byte 0x00004E45
.L0806FD64: .4byte 0x00004EA5

	thumb_func_start func_fe6_0806FD68
func_fe6_0806FD68: @ 0x0806FD68
	push {r4, lr}
	sub sp, #4
	ldr r4, .L0806FDA4 @ =0x02003108
	movs r0, #4
	ldrsh r1, [r4, r0]
	movs r0, #6
	ldrsh r2, [r4, r0]
	ldr r3, .L0806FDA8 @ =gUnk_086775D4
	movs r0, #0xb9
	lsls r0, r0, #6
	str r0, [sp]
	movs r0, #0xc
	bl PutSprite
	movs r0, #4
	ldrsh r1, [r4, r0]
	adds r1, #0x40
	movs r0, #6
	ldrsh r2, [r4, r0]
	adds r2, #0x83
	ldr r3, .L0806FDAC @ =Sprite_32x16
	ldr r0, .L0806FDB0 @ =0x00004E90
	str r0, [sp]
	movs r0, #0xb
	bl PutSprite
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0806FDA4: .4byte 0x02003108
.L0806FDA8: .4byte gUnk_086775D4
.L0806FDAC: .4byte Sprite_32x16
.L0806FDB0: .4byte 0x00004E90

	thumb_func_start func_fe6_0806FDB4
func_fe6_0806FDB4: @ 0x0806FDB4
	push {r4, r5, lr}
	sub sp, #0xc
	bl GetGameTime
	movs r2, #0
	movs r1, #0x1f
	ands r1, r0
	cmp r1, #0x13
	bhi .L0806FDC8
	movs r2, #1
.L0806FDC8:
	adds r5, r2, #0
	ldr r1, .L0806FE70 @ =gUnk_083195C8
	add r0, sp, #4
	movs r2, #6
	bl memcpy
	ldr r4, .L0806FE74 @ =0x02003108
	movs r0, #8
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bne .L0806FE68
	ldrb r0, [r4]
	cmp r0, #0
	bne .L0806FE30
	ldr r1, [r4, #0xc]
	movs r0, #0x10
	ldrh r1, [r1, #0xc]
	ands r0, r1
	cmp r0, #0
	beq .L0806FE30
	movs r0, #0x78
	movs r1, #0x28
	movs r2, #1
	bl PutSysArrow
	movs r0, #0x78
	movs r1, #0x38
	movs r2, #1
	bl PutSysArrow
	cmp r5, #0
	beq .L0806FE30
	ldr r3, .L0806FE78 @ =Sprite_8x8
	ldr r0, [r4, #0xc]
	ldrb r0, [r0, #0x19]
	lsrs r0, r0, #6
	lsls r0, r0, #1
	mov r1, sp
	adds r1, r1, r0
	adds r1, #4
	movs r0, #0xf
	ldrh r1, [r1]
	ands r0, r1
	lsls r0, r0, #0xc
	ldr r1, .L0806FE7C @ =0x00000803
	adds r0, r0, r1
	str r0, [sp]
	movs r0, #4
	movs r1, #0xb8
	movs r2, #0x4e
	bl PutSprite
.L0806FE30:
	ldr r0, .L0806FE74 @ =0x02003108
	ldr r1, [r0, #0xc]
	movs r0, #0x20
	ldrh r2, [r1, #0xc]
	ands r0, r2
	cmp r0, #0
	beq .L0806FE68
	cmp r5, #0
	beq .L0806FE68
	ldr r3, .L0806FE78 @ =Sprite_8x8
	ldrb r1, [r1, #0x19]
	lsrs r0, r1, #6
	lsls r0, r0, #1
	mov r1, sp
	adds r1, r1, r0
	adds r1, #4
	movs r0, #0xf
	ldrh r1, [r1]
	ands r0, r1
	lsls r0, r0, #0xc
	ldr r1, .L0806FE7C @ =0x00000803
	adds r0, r0, r1
	str r0, [sp]
	movs r0, #4
	movs r1, #0x20
	movs r2, #0x56
	bl PutSprite
.L0806FE68:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0806FE70: .4byte gUnk_083195C8
.L0806FE74: .4byte 0x02003108
.L0806FE78: .4byte Sprite_8x8
.L0806FE7C: .4byte 0x00000803

	thumb_func_start func_fe6_0806FE80
func_fe6_0806FE80: @ 0x0806FE80
	push {r4, lr}
	ldr r3, .L0806FEDC @ =gDispIo
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r1, [r3, #1]
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
	strb r0, [r3, #1]
	adds r1, r3, #0
	adds r1, #0x3c
	movs r0, #0xc0
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x44
	movs r2, #0
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	movs r4, #0x46
	movs r0, #0x10
	strb r0, [r4, r3]
	ldr r0, .L0806FEE0 @ =0x0000FFE0
	ldrh r4, [r3, #0x3c]
	ands r0, r4
	strh r0, [r3, #0x3c]
	movs r0, #0x20
	ldrb r3, [r1]
	orrs r0, r3
	strb r0, [r1]
	ldr r0, .L0806FEE4 @ =gPal
	strh r2, [r0]
	bl EnablePalSync
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0806FEDC: .4byte gDispIo
.L0806FEE0: .4byte 0x0000FFE0
.L0806FEE4: .4byte gPal

	thumb_func_start func_fe6_0806FEE8
func_fe6_0806FEE8: @ 0x0806FEE8
	push {r4, r5, lr}
	sub sp, #0x18
	adds r5, r0, #0
	ldr r1, .L0806FFA0 @ =gUnk_083195CE
	mov r0, sp
	movs r2, #0x18
	bl memcpy
	mov r0, sp
	bl InitBgs
	movs r0, #0x80
	lsls r0, r0, #3
	bl SetBlankChr
	ldr r0, .L0806FFA4 @ =gBg2Tm
	movs r1, #0
	bl TmFill
	movs r0, #4
	bl EnableBgSync
	bl ApplySystemGraphics
	bl ApplyUnitSpritePalettes
	ldr r1, .L0806FFA8 @ =0x0600B000
	movs r2, #1
	rsbs r2, r2, #0
	movs r0, #0
	bl func_fe6_0806EA24
	ldr r0, .L0806FFAC @ =gUnk_083080D0
	ldr r1, .L0806FFB0 @ =0x06014800
	bl Decompress
	movs r0, #4
	bl ApplyIconPalettes
	movs r0, #6
	bl ApplyUiStatBarPal
	movs r0, #1
	movs r1, #0x13
	bl ApplyIconPalette
	ldr r0, .L0806FFB4 @ =gUnk_08307CEC
	ldr r4, .L0806FFB8 @ =gBuf
	adds r1, r4, #0
	bl Decompress
	ldr r0, .L0806FFBC @ =gBg1Tm
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r4, #0
	bl TmApplyTsa_t
	ldr r0, .L0806FFC0 @ =gUnk_08307ED4
	ldr r1, .L0806FFC4 @ =0x06008C00
	bl Decompress
	ldr r0, .L0806FFC8 @ =gUnk_08308050
	movs r1, #0xe0
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, .L0806FFCC @ =gPal+0x20
	movs r2, #0x88
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r2, #8
	bl CpuFastSet
	movs r0, #1
	movs r1, #0x14
	bl ApplyIconPalette
	ldr r0, .L0806FFD0 @ =gUnk_08308920
	ldr r1, .L0806FFD4 @ =0x06004E00
	bl Decompress
	ldr r1, .L0806FFD8 @ =0x02003108
	movs r0, #0
	str r0, [r1, #0x10]
	adds r0, r5, #0
	bl func_fe6_0806F824
	add sp, #0x18
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0806FFA0: .4byte gUnk_083195CE
.L0806FFA4: .4byte gBg2Tm
.L0806FFA8: .4byte 0x0600B000
.L0806FFAC: .4byte gUnk_083080D0
.L0806FFB0: .4byte 0x06014800
.L0806FFB4: .4byte gUnk_08307CEC
.L0806FFB8: .4byte gBuf
.L0806FFBC: .4byte gBg1Tm
.L0806FFC0: .4byte gUnk_08307ED4
.L0806FFC4: .4byte 0x06008C00
.L0806FFC8: .4byte gUnk_08308050
.L0806FFCC: .4byte gPal+0x20
.L0806FFD0: .4byte gUnk_08308920
.L0806FFD4: .4byte 0x06004E00
.L0806FFD8: .4byte 0x02003108

	thumb_func_start func_fe6_0806FFDC
func_fe6_0806FFDC: @ 0x0806FFDC
	push {r4, r5, lr}
	ldr r2, .L08070000 @ =0x02003108
	ldr r1, [r2, #0xc]
	movs r0, #0xc0
	ldrb r1, [r1, #0xb]
	ands r0, r1
	cmp r0, #0
	beq .L0806FFF8
	ldr r1, .L08070004 @ =gBmSt
	movs r0, #0x40
	ldrb r1, [r1, #4]
	ands r0, r1
	cmp r0, #0
	beq .L08070008
.L0806FFF8:
	movs r0, #3
	strb r0, [r2, #1]
	b .L08070016
	.align 2, 0
.L08070000: .4byte 0x02003108
.L08070004: .4byte gBmSt
.L08070008:
	movs r0, #2
	strb r0, [r2, #1]
	ldrb r0, [r2]
	cmp r0, #2
	bne .L08070016
	movs r0, #1
	strb r0, [r2]
.L08070016:
	bl ResetText
	bl InitIcons
	bl func_fe6_0806EAF0
	ldr r5, .L08070088 @ =gBg2Tm+0x42
	ldr r4, .L0807008C @ =0x02003108
	ldr r0, [r4, #0xc]
	bl GetUnitFid
	adds r1, r0, #0
	movs r2, #0x9c
	lsls r2, r2, #3
	adds r0, r5, #0
	movs r3, #0xd
	bl PutFace80x72
	bl EndAllMus
	ldr r0, [r4, #0xc]
	movs r1, #0x50
	movs r2, #0x8a
	bl StartUiMu
	str r0, [r4, #0x10]
	bl func_fe6_0806EB48
	ldrb r0, [r4]
	bl func_fe6_0806F3DC
	ldr r0, .L08070090 @ =0x02003238
	ldr r1, .L08070094 @ =gBg0Tm+0x98
	movs r2, #0x12
	movs r3, #0x12
	bl TmCopyRect_t
	ldr r0, .L08070098 @ =0x02003738
	ldr r1, .L0807009C @ =gBg1Tm+0x98
	movs r2, #0x12
	movs r3, #0x12
	bl TmCopyRect_t
	ldr r0, .L080700A0 @ =0x02003C38
	adds r5, #0x56
	adds r1, r5, #0
	movs r2, #0x12
	movs r3, #0x12
	bl TmCopyRect_t
	movs r0, #7
	bl EnableBgSync
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08070088: .4byte gBg2Tm+0x42
.L0807008C: .4byte 0x02003108
.L08070090: .4byte 0x02003238
.L08070094: .4byte gBg0Tm+0x98
.L08070098: .4byte 0x02003738
.L0807009C: .4byte gBg1Tm+0x98
.L080700A0: .4byte 0x02003C38

	thumb_func_start func_fe6_080700A4
func_fe6_080700A4: @ 0x080700A4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, .L08070128 @ =gKeySt
	ldr r2, [r1]
	movs r0, #2
	ldrh r3, [r2, #8]
	ands r0, r3
	adds r3, r1, #0
	cmp r0, #0
	beq .L0807013C
	ldr r3, .L0807012C @ =gDispIo
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r4, [r3, #1]
	ands r0, r4
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #2
	ands r0, r1
	subs r1, #4
	ands r0, r1
	subs r1, #8
	ands r0, r1
	strb r0, [r3, #1]
	adds r1, r3, #0
	adds r1, #0x3c
	movs r0, #0xc0
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x44
	movs r2, #0
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r4, r3, #0
	adds r4, #0x46
	movs r0, #0x10
	strb r0, [r4]
	ldr r0, .L08070130 @ =0x0000FFE0
	ldrh r4, [r3, #0x3c]
	ands r0, r4
	strh r0, [r3, #0x3c]
	movs r0, #0x20
	ldrb r3, [r1]
	orrs r0, r3
	strb r0, [r1]
	ldr r0, .L08070134 @ =gPal
	strh r2, [r0]
	bl EnablePalSync
	adds r0, r5, #0
	bl Proc_Break
	ldr r0, .L08070138 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	bge .L08070120
	b .L08070220
.L08070120:
	movs r0, #0x6b
	bl m4aSongNumStart
	b .L08070220
	.align 2, 0
.L08070128: .4byte gKeySt
.L0807012C: .4byte gDispIo
.L08070130: .4byte 0x0000FFE0
.L08070134: .4byte gPal
.L08070138: .4byte gPlaySt
.L0807013C:
	ldrh r1, [r2, #6]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq .L08070160
	ldr r4, .L0807015C @ =0x02003108
	ldrb r1, [r4, #1]
	ldrb r2, [r4]
	adds r0, r2, r1
	subs r0, #1
	bl __modsi3
	strb r0, [r4]
	ldrb r1, [r4]
	movs r0, #0x20
	b .L0807017E
	.align 2, 0
.L0807015C: .4byte 0x02003108
.L08070160:
	movs r6, #0x10
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq .L0807018C
	ldr r4, .L08070188 @ =0x02003108
	ldrb r1, [r4, #1]
	ldrb r3, [r4]
	adds r0, r3, r1
	adds r0, #1
	bl __modsi3
	strb r0, [r4]
	ldrb r1, [r4]
	movs r0, #0x10
.L0807017E:
	adds r2, r5, #0
	bl func_fe6_0806F594
	b .L08070220
	.align 2, 0
.L08070188: .4byte 0x02003108
.L0807018C:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq .L080701AC
	ldr r0, .L080701A8 @ =0x02003108
	ldr r0, [r0, #0xc]
	movs r4, #1
	rsbs r4, r4, #0
	adds r1, r4, #0
	bl func_fe6_0806F430
	adds r2, r0, #0
	adds r1, r4, #0
	b .L080701F4
	.align 2, 0
.L080701A8: .4byte 0x02003108
.L080701AC:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq .L080701C8
	ldr r0, .L080701C4 @ =0x02003108
	ldr r0, [r0, #0xc]
	movs r1, #1
	bl func_fe6_0806F430
	adds r2, r0, #0
	movs r1, #1
	b .L080701F4
	.align 2, 0
.L080701C4: .4byte 0x02003108
.L080701C8:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq .L08070200
	ldr r4, .L080701FC @ =0x02003108
	ldr r2, [r4, #0xc]
	ldrb r0, [r2, #0x19]
	cmp r0, #0
	beq .L08070200
	bl GetUnit
	adds r2, r0, #0
	ldr r1, [r4, #0xc]
	adds r0, r6, #0
	ldrh r1, [r1, #0xc]
	ands r0, r1
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, #0
	beq .L080701F2
	movs r1, #1
.L080701F2:
	adds r0, r2, #0
.L080701F4:
	adds r2, r5, #0
	bl func_fe6_0806F8B8
	b .L08070220
	.align 2, 0
.L080701FC: .4byte 0x02003108
.L08070200:
	ldr r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L08070220
	adds r0, r5, #0
	movs r1, #0
	bl Proc_Goto
	ldr r0, .L08070228 @ =0x02003108
	ldrb r0, [r0]
	adds r1, r5, #0
	bl func_fe6_0807030C
.L08070220:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08070228: .4byte 0x02003108

	thumb_func_start func_fe6_0807022C
func_fe6_0807022C: @ 0x0807022C
	push {r4, lr}
	ldr r3, .L08070258 @ =gPlaySt
	movs r1, #0xfc
	ldrb r0, [r3, #0x14]
	ands r1, r0
	ldr r2, .L0807025C @ =0x02003108
	movs r0, #3
	ldrb r4, [r2]
	ands r0, r4
	orrs r1, r0
	strb r1, [r3, #0x14]
	ldr r1, .L08070260 @ =0x0203D3DC
	ldr r0, [r2, #0xc]
	ldrb r0, [r0, #0xb]
	strb r0, [r1, #1]
	movs r0, #0
	bl SetOnVMatch
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08070258: .4byte gPlaySt
.L0807025C: .4byte 0x02003108
.L08070260: .4byte 0x0203D3DC

	thumb_func_start func_fe6_08070264
func_fe6_08070264: @ 0x08070264
	push {lr}
	bl func_fe6_08070CA8
	ldr r1, .L08070274 @ =0x02003108
	str r0, [r1, #0x14]
	pop {r0}
	bx r0
	.align 2, 0
.L08070274: .4byte 0x02003108

	thumb_func_start func_fe6_08070278
func_fe6_08070278: @ 0x08070278
	push {r4, lr}
	ldr r0, .L080702AC @ =0x02003108
	movs r1, #6
	ldrsh r4, [r0, r1]
	rsbs r4, r4, #0
	movs r0, #0xff
	ands r4, r0
	movs r0, #0
	movs r1, #0
	adds r2, r4, #0
	bl SetBgOffset
	movs r0, #1
	movs r1, #0
	adds r2, r4, #0
	bl SetBgOffset
	movs r0, #2
	movs r1, #0
	adds r2, r4, #0
	bl SetBgOffset
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080702AC: .4byte 0x02003108

	thumb_func_start func_fe6_080702B0
func_fe6_080702B0: @ 0x080702B0
	push {lr}
	bl func_fe6_0806EABC
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start StartStatScreen
StartStatScreen: @ 0x080702BC
	push {r4, r5, r6, r7, lr}
	adds r6, r1, #0
	ldr r2, .L08070300 @ =0x02003108
	movs r5, #0
	movs r3, #0
	strh r3, [r2, #4]
	strh r3, [r2, #6]
	ldr r4, .L08070304 @ =gPlaySt
	movs r1, #3
	ldrb r7, [r4, #0x14]
	ands r1, r7
	strb r1, [r2]
	str r0, [r2, #0xc]
	str r3, [r2, #0x14]
	strh r3, [r2, #2]
	strb r5, [r2, #8]
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	bl func_fe6_08084BB8
	ldrb r4, [r4, #0x1d]
	lsls r0, r4, #0x1e
	cmp r0, #0
	blt .L080702F2
	movs r0, #0x6a
	bl m4aSongNumStart
.L080702F2:
	ldr r0, .L08070308 @ =gUnk_08677680
	adds r1, r6, #0
	bl SpawnProcLocking
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08070300: .4byte 0x02003108
.L08070304: .4byte gPlaySt
.L08070308: .4byte gUnk_08677680

	thumb_func_start func_fe6_0807030C
func_fe6_0807030C: @ 0x0807030C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0
	bl func_fe6_08070E70
	ldr r1, .L08070334 @ =0x02003108
	ldr r0, [r1, #0x14]
	cmp r0, #0
	bne .L08070354
	cmp r4, #1
	beq .L08070348
	cmp r4, #1
	bgt .L08070338
	cmp r4, #0
	beq .L0807033E
	b .L08070354
	.align 2, 0
.L08070334: .4byte 0x02003108
.L08070338:
	cmp r4, #2
	beq .L08070350
	b .L08070354
.L0807033E:
	ldr r0, .L08070344 @ =gUnk_08677824
	b .L08070352
	.align 2, 0
.L08070344: .4byte gUnk_08677824
.L08070348:
	ldr r0, .L0807034C @ =gUnk_08677A00
	b .L08070352
	.align 2, 0
.L0807034C: .4byte gUnk_08677A00
.L08070350:
	ldr r0, .L08070364 @ =gUnk_08677BA4
.L08070352:
	str r0, [r1, #0x14]
.L08070354:
	ldr r0, .L08070368 @ =0x02003108
	ldr r0, [r0, #0x14]
	adds r1, r5, #0
	bl StartMovingHelpBox
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08070364: .4byte gUnk_08677BA4
.L08070368: .4byte 0x02003108

	thumb_func_start func_fe6_0807036C
func_fe6_0807036C: @ 0x0807036C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L08070394 @ =0x02003108
	ldr r0, [r0, #0xc]
	ldr r1, [r4, #0x2c]
	ldrh r1, [r1, #0x12]
	lsls r1, r1, #1
	adds r0, #0x1c
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0x4e
	strh r0, [r1]
	bl GetItemDescMsg
	adds r4, #0x4c
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08070394: .4byte 0x02003108

	thumb_func_start func_fe6_08070398
func_fe6_08070398: @ 0x08070398
	adds r2, r0, #0
	ldr r0, .L080703B4 @ =0x02003108
	ldr r0, [r0, #0xc]
	adds r0, #0x2e
	ldrb r0, [r0]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	cmp r0, #4
	bhi .L08070408
	lsls r0, r0, #2
	ldr r1, .L080703B8 @ =.L080703BC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L080703B4: .4byte 0x02003108
.L080703B8: .4byte .L080703BC
.L080703BC: @ jump table
	.4byte .L080703D0 @ case 0
	.4byte .L080703DA @ case 1
	.4byte .L080703E8 @ case 2
	.4byte .L080703F4 @ case 3
	.4byte .L08070400 @ case 4
.L080703D0:
	adds r1, r2, #0
	adds r1, #0x4c
	movs r0, #0xb5
	lsls r0, r0, #3
	b .L08070406
.L080703DA:
	adds r1, r2, #0
	adds r1, #0x4c
	ldr r0, .L080703E4 @ =0x000005A9
	b .L08070406
	.align 2, 0
.L080703E4: .4byte 0x000005A9
.L080703E8:
	adds r1, r2, #0
	adds r1, #0x4c
	ldr r0, .L080703F0 @ =0x000005AA
	b .L08070406
	.align 2, 0
.L080703F0: .4byte 0x000005AA
.L080703F4:
	adds r1, r2, #0
	adds r1, #0x4c
	ldr r0, .L080703FC @ =0x000005AC
	b .L08070406
	.align 2, 0
.L080703FC: .4byte 0x000005AC
.L08070400:
	adds r1, r2, #0
	adds r1, #0x4c
	ldr r0, .L0807040C @ =0x000005AB
.L08070406:
	strh r0, [r1]
.L08070408:
	bx lr
	.align 2, 0
.L0807040C: .4byte 0x000005AB

	thumb_func_start func_fe6_08070410
func_fe6_08070410: @ 0x08070410
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0807042C @ =0x02003108
	ldr r0, [r0, #0xc]
	bl UnitKnowsMagic
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08070434
	adds r1, r4, #0
	adds r1, #0x4c
	ldr r0, .L08070430 @ =0x0000059D
	b .L0807043A
	.align 2, 0
.L0807042C: .4byte 0x02003108
.L08070430: .4byte 0x0000059D
.L08070434:
	adds r1, r4, #0
	adds r1, #0x4c
	ldr r0, .L08070444 @ =0x0000059C
.L0807043A:
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08070444: .4byte 0x0000059C

	thumb_func_start func_fe6_08070448
func_fe6_08070448: @ 0x08070448
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, .L08070488 @ =0x02003108
	ldr r0, [r5, #0xc]
	ldrh r0, [r0, #0x1c]
	cmp r0, #0
	bne .L0807045C
	adds r0, r4, #0
	bl func_fe6_08070BEC
.L0807045C:
	ldr r0, [r5, #0xc]
	ldr r1, [r4, #0x2c]
	ldrh r1, [r1, #0x12]
	lsls r1, r1, #1
	adds r0, #0x1c
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne .L08070496
	adds r0, r4, #0
	adds r0, #0x50
	ldrh r0, [r0]
	cmp r0, #0
	beq .L08070480
	cmp r0, #0x10
	beq .L08070480
	cmp r0, #0x40
	bne .L0807048C
.L08070480:
	adds r0, r4, #0
	bl func_fe6_08070B8C
	b .L08070496
	.align 2, 0
.L08070488: .4byte 0x02003108
.L0807048C:
	cmp r0, #0x80
	bne .L08070496
	adds r0, r4, #0
	bl func_fe6_08070BBC
.L08070496:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0807049C
func_fe6_0807049C: @ 0x0807049C
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r1, .L080704D4 @ =gUnk_083195E6
	mov r0, sp
	movs r2, #0x10
	bl memcpy
	ldr r0, [r5, #0x2c]
	ldrh r4, [r0, #0x12]
	ldr r0, .L080704D8 @ =0x02003108
	ldr r0, [r0, #0xc]
	bl UnitKnowsMagic
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080704C0
	adds r4, #4
.L080704C0:
	lsls r0, r4, #1
	add r0, sp
	ldrh r1, [r0]
	adds r0, r5, #0
	adds r0, #0x4c
	strh r1, [r0]
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080704D4: .4byte gUnk_083195E6
.L080704D8: .4byte 0x02003108

	thumb_func_start func_fe6_080704DC
func_fe6_080704DC: @ 0x080704DC
	adds r1, r0, #0
	ldr r0, .L080704F4 @ =0x02003108
	ldr r0, [r0, #0xc]
	ldr r0, [r0]
	ldrh r2, [r0, #2]
	cmp r2, #0
	beq .L080704F8
	adds r0, r1, #0
	adds r0, #0x4c
	strh r2, [r0]
	b .L080704FE
	.align 2, 0
.L080704F4: .4byte 0x02003108
.L080704F8:
	adds r1, #0x4c
	ldr r0, .L08070500 @ =0x0000066D
	strh r0, [r1]
.L080704FE:
	bx lr
	.align 2, 0
.L08070500: .4byte 0x0000066D

	thumb_func_start func_fe6_08070504
func_fe6_08070504: @ 0x08070504
	ldr r1, .L08070514 @ =0x02003108
	ldr r1, [r1, #0xc]
	ldr r1, [r1, #4]
	ldrh r1, [r1, #2]
	adds r0, #0x4c
	strh r1, [r0]
	bx lr
	.align 2, 0
.L08070514: .4byte 0x02003108

	thumb_func_start func_fe6_08070518
func_fe6_08070518: @ 0x08070518
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0807053C @ =0x02003108
	ldr r0, [r0, #0xc]
	bl GetUnitTotalSupportLevel
	cmp r0, #0
	bne .L08070546
	adds r0, r4, #0
	adds r0, #0x50
	ldrh r0, [r0]
	cmp r0, #0x80
	bne .L08070540
	adds r0, r4, #0
	bl func_fe6_08070BBC
	b .L08070546
	.align 2, 0
.L0807053C: .4byte 0x02003108
.L08070540:
	adds r0, r4, #0
	bl func_fe6_08070B8C
.L08070546:
	pop {r4}
	pop {r0}
	bx r0
