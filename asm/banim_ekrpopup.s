	.include "macro.inc"

	.syntax unified

	thumb_func_start CheckEkrPopupDone
CheckEkrPopupDone: @ 0x0805F148
	ldr r0, .L0805F154 @ =gUnk_Banim_0201F0E4
	ldr r0, [r0]
	cmp r0, #1
	beq .L0805F158
	movs r0, #0
	b .L0805F15A
	.align 2, 0
.L0805F154: .4byte gUnk_Banim_0201F0E4
.L0805F158:
	movs r0, #1
.L0805F15A:
	bx lr

	thumb_func_start EndEkrPopup
EndEkrPopup: @ 0x0805F15C
	push {r4, lr}
	ldr r4, .L0805F174 @ =gUnk_Banim_0201F0E0
	ldr r0, [r4]
	cmp r0, #0
	beq .L0805F16E
	bl Proc_End
	movs r0, #0
	str r0, [r4]
.L0805F16E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805F174: .4byte gUnk_Banim_0201F0E0

	thumb_func_start func_fe6_0805F178
func_fe6_0805F178: @ 0x0805F178
	push {lr}
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x5a
	bl EfxPlaySE
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805F188
func_fe6_0805F188: @ 0x0805F188
	push {lr}
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x5c
	bl EfxPlaySE
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805F198
func_fe6_0805F198: @ 0x0805F198
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov ip, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	ldr r6, .L0805F278 @ =gEkrTsaBuffer
	ldrh r1, [r6]
	movs r2, #0x88
	lsls r2, r2, #5
	adds r0, r1, r2
	mov r3, ip
	strh r0, [r3]
	mov r1, ip
	adds r1, #0x40
	ldrh r7, [r6, #0x30]
	adds r0, r7, r2
	strh r0, [r1]
	adds r1, #0x40
	adds r0, r6, #0
	adds r0, #0x60
	ldrh r0, [r0]
	adds r0, r0, r2
	strh r0, [r1]
	adds r1, #0x40
	adds r0, r6, #0
	adds r0, #0x90
	ldrh r0, [r0]
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0
	mov r8, r0
	cmp r8, sb
	bhs .L0805F22C
	adds r3, #0xc2
	str r3, [sp]
	mov r5, ip
	adds r5, #0x82
	adds r4, r6, #0
	adds r4, #0x62
	subs r3, #0x80
	mov r2, ip
	adds r2, #2
	adds r1, r6, #2
.L0805F1F8:
	ldrh r7, [r1]
	movs r0, #0x88
	lsls r0, r0, #5
	adds r7, r7, r0
	strh r7, [r2]
	ldrh r7, [r1, #0x30]
	adds r7, r7, r0
	strh r7, [r3]
	ldrh r7, [r4]
	adds r7, r7, r0
	strh r7, [r5]
	ldrh r7, [r4, #0x30]
	adds r7, r7, r0
	ldr r0, [sp]
	strh r7, [r0]
	adds r0, #2
	str r0, [sp]
	adds r5, #2
	adds r4, #2
	adds r3, #2
	adds r2, #2
	adds r1, #2
	movs r7, #1
	add r8, r7
	cmp r8, sb
	blo .L0805F1F8
.L0805F22C:
	mov r1, r8
	lsls r0, r1, #1
	mov r2, ip
	adds r1, r0, r2
	ldrh r3, [r6, #0x2e]
	movs r7, #0x88
	lsls r7, r7, #5
	adds r0, r3, r7
	strh r0, [r1, #2]
	adds r2, r1, #0
	adds r2, #0x42
	adds r0, r6, #0
	adds r0, #0x5e
	ldrh r0, [r0]
	adds r3, r7, #0
	adds r0, r0, r3
	strh r0, [r2]
	adds r2, #0x40
	adds r0, r6, #0
	adds r0, #0x8e
	ldrh r0, [r0]
	adds r0, r0, r3
	strh r0, [r2]
	adds r1, #0xc2
	adds r0, r6, #0
	adds r0, #0xbe
	ldrh r0, [r0]
	adds r0, r0, r3
	strh r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805F278: .4byte gEkrTsaBuffer

	thumb_func_start func_fe6_0805F27C
func_fe6_0805F27C: @ 0x0805F27C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	str r0, [sp]
	mov sb, r1
	adds r7, r2, #0
	ldr r0, .L0805F2D8 @ =gUnk_0811531C
	ldr r1, .L0805F2DC @ =0x06002000
	bl LZ77UnCompVram
	ldr r0, .L0805F2E0 @ =gUnk_08115498
	ldr r1, .L0805F2E4 @ =gEkrTsaBuffer
	bl LZ77UnCompWram
	ldr r0, .L0805F2E8 @ =gUnk_Banim_02017640
	ldr r1, .L0805F2EC @ =0x060020C0
	movs r2, #0x83
	lsls r2, r2, #1
	movs r3, #1
	bl InitTextFont
	bl SetTextDrawNoClear
	ldr r0, .L0805F2F0 @ =gUnk_08115478
	ldr r1, .L0805F2F4 @ =gPal+0x20
	movs r2, #8
	bl CpuFastSet
	mov r0, sb
	cmp r0, #0
	bne .L0805F2FC
	movs r0, #0xc7
	lsls r0, r0, #4
	bl DecodeMsg
	adds r4, r0, #0
	bl GetStringTextLen
	mov r8, r0
	mov r5, r8
	adds r5, #0x10
	ldr r0, .L0805F2F8 @ =0x00000C71
	b .L0805F312
	.align 2, 0
.L0805F2D8: .4byte gUnk_0811531C
.L0805F2DC: .4byte 0x06002000
.L0805F2E0: .4byte gUnk_08115498
.L0805F2E4: .4byte gEkrTsaBuffer
.L0805F2E8: .4byte gUnk_Banim_02017640
.L0805F2EC: .4byte 0x060020C0
.L0805F2F0: .4byte gUnk_08115478
.L0805F2F4: .4byte gPal+0x20
.L0805F2F8: .4byte 0x00000C71
.L0805F2FC:
	movs r1, #0
	mov r8, r1
	adds r0, r7, #0
	bl GetItemName
	adds r4, r0, #0
	bl GetStringTextLen
	adds r5, r0, #0
	adds r5, #0x10
	ldr r0, .L0805F390 @ =0x00000C72
.L0805F312:
	bl DecodeMsg
	adds r4, r0, #0
	bl GetStringTextLen
	adds r4, r0, r5
	adds r0, r4, #7
	asrs r6, r0, #3
	ldr r0, .L0805F394 @ =gBg1Tm
	lsls r1, r6, #0x10
	lsrs r1, r1, #0x10
	bl func_fe6_0805F198
	ldr r5, .L0805F398 @ =gUnk_Banim_02017658
	adds r0, r5, #0
	adds r1, r6, #0
	bl InitText
	lsls r0, r6, #3
	subs r0, r0, r4
	asrs r0, r0, #1
	mov sl, r0
	adds r0, r5, #0
	mov r1, sl
	bl Text_SetCursor
	ldr r0, .L0805F39C @ =gUnk_08115378
	ldr r1, .L0805F3A0 @ =0x060020C0
	bl LZ77UnCompVram
	mov r3, sb
	cmp r3, #0
	bne .L0805F3A8
	movs r0, #0xc7
	lsls r0, r0, #4
	bl DecodeMsg
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #0
	bl Text_SetColor
	adds r0, r5, #0
	adds r1, r4, #0
	bl Text_DrawString
	adds r0, r5, #0
	movs r1, #0x10
	bl Text_Skip
	ldr r0, .L0805F3A4 @ =0x00000C71
	bl DecodeMsg
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #0
	bl Text_SetColor
	adds r0, r5, #0
	adds r1, r4, #0
	bl Text_DrawString
	b .L0805F3E0
	.align 2, 0
.L0805F390: .4byte 0x00000C72
.L0805F394: .4byte gBg1Tm
.L0805F398: .4byte gUnk_Banim_02017658
.L0805F39C: .4byte gUnk_08115378
.L0805F3A0: .4byte 0x060020C0
.L0805F3A4: .4byte 0x00000C71
.L0805F3A8:
	adds r0, r5, #0
	movs r1, #0x10
	bl Text_Skip
	adds r0, r7, #0
	bl GetItemName
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #1
	bl Text_SetColor
	adds r0, r5, #0
	adds r1, r4, #0
	bl Text_DrawString
	ldr r0, .L0805F420 @ =0x00000C72
	bl DecodeMsg
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #0
	bl Text_SetColor
	adds r0, r5, #0
	adds r1, r4, #0
	bl Text_DrawString
.L0805F3E0:
	adds r1, r6, #2
	lsls r1, r1, #3
	movs r0, #0xf0
	subs r0, r0, r1
	asrs r5, r0, #1
	rsbs r1, r5, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, .L0805F424 @ =0x0000FFD0
	movs r0, #1
	bl SetBgOffset
	movs r0, #2
	bl EnableBgSync
	bl InitIcons
	mov r0, sb
	cmp r0, #0
	bne .L0805F428
	movs r0, #1
	movs r1, #0x12
	bl ApplyIconPalette
	adds r0, r7, #0
	bl GetItemKind
	adds r0, #0x70
	movs r1, #0x40
	bl PutIconObjImg
	b .L0805F43C
	.align 2, 0
.L0805F420: .4byte 0x00000C72
.L0805F424: .4byte 0x0000FFD0
.L0805F428:
	movs r0, #0
	movs r1, #0x12
	bl ApplyIconPalette
	adds r0, r7, #0
	bl GetItemIcon
	movs r1, #0x40
	bl PutIconObjImg
.L0805F43C:
	ldr r0, .L0805F490 @ =gUnk_08607660
	movs r1, #0x96
	bl BasCreate
	ldr r1, [sp]
	str r0, [r1, #0x60]
	movs r4, #0
	movs r1, #0x91
	lsls r1, r1, #6
	strh r1, [r0, #8]
	mov r1, sl
	adds r1, #8
	adds r1, r5, r1
	add r1, r8
	strh r1, [r0, #2]
	movs r1, #0x38
	strh r1, [r0, #4]
	bl EnablePalSync
	ldr r2, .L0805F494 @ =gDispIo
	adds r1, r2, #0
	adds r1, #0x3c
	movs r0, #0x3f
	ldrb r3, [r1]
	ands r0, r3
	strb r0, [r1]
	adds r1, #8
	movs r0, #0x10
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x45
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805F490: .4byte gUnk_08607660
.L0805F494: .4byte gDispIo

	thumb_func_start NewEkrPopup
NewEkrPopup: @ 0x0805F498
	push {r4, r5, lr}
	ldr r4, .L0805F554 @ =gUnk_Banim_0201F0E0
	ldr r0, .L0805F558 @ =gUnk_08607668
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r5, [r4]
	ldr r1, .L0805F55C @ =gUnk_Banim_0201F0E4
	movs r0, #0
	str r0, [r1]
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x48]
	str r0, [r5, #0x44]
	str r0, [r5, #0x50]
	str r0, [r5, #0x4c]
	bl func_fe6_08058F38
	cmp r0, #0
	bne .L0805F576
	ldr r0, .L0805F560 @ =gEkrDistanceType
	ldrh r0, [r0]
	cmp r0, #4
	beq .L0805F576
	ldr r0, .L0805F564 @ =gBanimFactionPal
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L0805F500
	ldr r4, .L0805F568 @ =gpEkrBattleUnitLeft
	ldr r0, [r4]
	bl HasBattleUnitGainedWeaponLevel
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L0805F4EA
	ldr r0, [r4]
	adds r0, #0x4a
	ldrh r0, [r0]
	str r0, [r5, #0x44]
.L0805F4EA:
	ldr r0, [r4]
	bl DidBattleUnitBreakWeapon
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L0805F500
	ldr r0, [r4]
	adds r0, #0x4a
	ldrh r0, [r0]
	str r0, [r5, #0x48]
.L0805F500:
	ldr r0, .L0805F564 @ =gBanimFactionPal
	movs r1, #2
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L0805F538
	ldr r4, .L0805F56C @ =gpEkrBattleUnitRight
	ldr r0, [r4]
	bl HasBattleUnitGainedWeaponLevel
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L0805F522
	ldr r0, [r4]
	adds r0, #0x4a
	ldrh r0, [r0]
	str r0, [r5, #0x4c]
.L0805F522:
	ldr r0, [r4]
	bl DidBattleUnitBreakWeapon
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L0805F538
	ldr r0, [r4]
	adds r0, #0x4a
	ldrh r0, [r0]
	str r0, [r5, #0x50]
.L0805F538:
	ldr r0, [r5, #0x44]
	ldr r1, [r5, #0x48]
	adds r0, r0, r1
	ldr r1, [r5, #0x4c]
	adds r0, r0, r1
	ldr r1, [r5, #0x50]
	cmn r0, r1
	bne .L0805F570
	ldr r1, .L0805F55C @ =gUnk_Banim_0201F0E4
	movs r0, #1
	str r0, [r1]
	bl EndEkrPopup
	b .L0805F576
	.align 2, 0
.L0805F554: .4byte gUnk_Banim_0201F0E0
.L0805F558: .4byte gUnk_08607668
.L0805F55C: .4byte gUnk_Banim_0201F0E4
.L0805F560: .4byte gEkrDistanceType
.L0805F564: .4byte gBanimFactionPal
.L0805F568: .4byte gpEkrBattleUnitLeft
.L0805F56C: .4byte gpEkrBattleUnitRight
.L0805F570:
	movs r0, #0x80
	bl SetBgmVolume
.L0805F576:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805F57C
func_fe6_0805F57C: @ 0x0805F57C
	push {lr}
	adds r1, r0, #0
	ldrh r0, [r1, #0x2c]
	adds r0, #1
	strh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x10
	ble .L0805F594
	adds r0, r1, #0
	bl Proc_Break
.L0805F594:
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805F598
func_fe6_0805F598: @ 0x0805F598
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0x44]
	cmp r2, #0
	beq .L0805F5B4
	movs r1, #0
	bl func_fe6_0805F27C
	bl func_fe6_0805F178
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x60
	strh r0, [r4, #0x2e]
.L0805F5B4:
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805F5C0
func_fe6_0805F5C0: @ 0x0805F5C0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x44]
	cmp r0, #0
	bne .L0805F5D2
	adds r0, r4, #0
	bl Proc_Break
	b .L0805F5F2
.L0805F5D2:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0805F5F2
	ldr r0, [r4, #0x60]
	bl BasRemove
	bl SpellFx_ClearBG1
	adds r0, r4, #0
	bl Proc_Break
.L0805F5F2:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805F5F8
func_fe6_0805F5F8: @ 0x0805F5F8
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0x4c]
	cmp r2, #0
	beq .L0805F614
	movs r1, #0
	bl func_fe6_0805F27C
	bl func_fe6_0805F178
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x60
	strh r0, [r4, #0x2e]
.L0805F614:
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805F620
func_fe6_0805F620: @ 0x0805F620
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x4c]
	cmp r0, #0
	bne .L0805F632
	adds r0, r4, #0
	bl Proc_Break
	b .L0805F652
.L0805F632:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0805F652
	ldr r0, [r4, #0x60]
	bl BasRemove
	bl SpellFx_ClearBG1
	adds r0, r4, #0
	bl Proc_Break
.L0805F652:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805F658
func_fe6_0805F658: @ 0x0805F658
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0x48]
	cmp r2, #0
	beq .L0805F674
	movs r1, #1
	bl func_fe6_0805F27C
	bl func_fe6_0805F188
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x6c
	strh r0, [r4, #0x2e]
.L0805F674:
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805F680
func_fe6_0805F680: @ 0x0805F680
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x48]
	cmp r0, #0
	bne .L0805F692
	adds r0, r4, #0
	bl Proc_Break
	b .L0805F6B2
.L0805F692:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0805F6B2
	ldr r0, [r4, #0x60]
	bl BasRemove
	bl SpellFx_ClearBG1
	adds r0, r4, #0
	bl Proc_Break
.L0805F6B2:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805F6B8
func_fe6_0805F6B8: @ 0x0805F6B8
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0x50]
	cmp r2, #0
	beq .L0805F6D4
	movs r1, #1
	bl func_fe6_0805F27C
	bl func_fe6_0805F188
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x6c
	strh r0, [r4, #0x2e]
.L0805F6D4:
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805F6E0
func_fe6_0805F6E0: @ 0x0805F6E0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x50]
	cmp r0, #0
	bne .L0805F6F2
	adds r0, r4, #0
	bl Proc_Break
	b .L0805F716
.L0805F6F2:
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0805F716
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r0, [r4, #0x60]
	bl BasRemove
	bl SpellFx_ClearBG1
	adds r0, r4, #0
	bl Proc_Break
.L0805F716:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805F71C
func_fe6_0805F71C: @ 0x0805F71C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x10
	ble .L0805F742
	ldr r0, .L0805F748 @ =gUnk_Banim_0201F0E4
	movs r1, #1
	str r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	bl SetBgmVolume
	adds r0, r4, #0
	bl Proc_Break
.L0805F742:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805F748: .4byte gUnk_Banim_0201F0E4

	thumb_func_start func_fe6_0805F74C
func_fe6_0805F74C: @ 0x0805F74C
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0805F750
func_fe6_0805F750: @ 0x0805F750
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, .L0805F77C @ =gUnk_08662E4C
	bl GetItemIid
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r4]
	ldr r2, .L0805F780 @ =0x0000FFFF
	cmp r1, r2
	beq .L0805F774
.L0805F768:
	cmp r1, r0
	beq .L0805F774
	adds r4, #0x10
	ldrh r1, [r4]
	cmp r1, r2
	bne .L0805F768
.L0805F774:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L0805F77C: .4byte gUnk_08662E4C
.L0805F780: .4byte 0x0000FFFF

	thumb_func_start GetWeaponAnimActorCount
GetWeaponAnimActorCount: @ 0x0805F784
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl func_fe6_0805F750
	ldrb r0, [r0, #2]
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0805F794
func_fe6_0805F794: @ 0x0805F794
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl func_fe6_0805F750
	ldrh r0, [r0, #4]
	pop {r1}
	bx r1

	thumb_func_start GetWeaponAnimManimSpecialScr
GetWeaponAnimManimSpecialScr: @ 0x0805F7A4
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl func_fe6_0805F750
	ldr r0, [r0, #8]
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0805F7B4
func_fe6_0805F7B4: @ 0x0805F7B4
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl func_fe6_0805F750
	ldrb r0, [r0, #0xc]
	pop {r1}
	bx r1

	thumb_func_start GetItemMaFacing
GetItemMaFacing: @ 0x0805F7C4
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl func_fe6_0805F750
	ldrb r0, [r0, #0xd]
	pop {r1}
	bx r1

	thumb_func_start func_fe6_0805F7D4
func_fe6_0805F7D4: @ 0x0805F7D4
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl func_fe6_0805F750
	ldrb r0, [r0, #0xe]
	pop {r1}
	bx r1
