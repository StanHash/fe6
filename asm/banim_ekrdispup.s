	.include "macro.inc"

	.syntax unified

	.section .data
	.global ProcScr_EkrDispUP
ProcScr_EkrDispUP: @ 085CB718
	.incbin "fe6-base.gba", 0x5CB718, (0x5CB730 - 0x5CB718) @ length: 0018

	.section .text
	thumb_func_start NewEkrDispUP
NewEkrDispUP: @ 0x08044198
	push {r4, lr}
	ldr r4, .L080441C0 @ =gpProcEkrDispUP
	ldr r0, .L080441C4 @ =ProcScr_EkrDispUP
	movs r1, #5
	bl SpawnProc
	str r0, [r4]
	movs r0, #0
	movs r1, #0
	bl func_fe6_0804421C
	bl func_fe6_080441DC
	bl UnAsyncEkrDispUP
	bl func_fe6_08044254
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080441C0: .4byte gpProcEkrDispUP
.L080441C4: .4byte ProcScr_EkrDispUP

	thumb_func_start EndEkrDispUP
EndEkrDispUP: @ 0x080441C8
	push {lr}
	ldr r0, .L080441D8 @ =gpProcEkrDispUP
	ldr r0, [r0]
	bl Proc_End
	pop {r0}
	bx r0
	.align 2, 0
.L080441D8: .4byte gpProcEkrDispUP

	thumb_func_start func_fe6_080441DC
func_fe6_080441DC: @ 0x080441DC
	ldr r0, .L080441E8 @ =gpProcEkrDispUP
	ldr r1, [r0]
	movs r0, #0
	str r0, [r1, #0x4c]
	str r0, [r1, #0x50]
	bx lr
	.align 2, 0
.L080441E8: .4byte gpProcEkrDispUP

	thumb_func_start func_fe6_080441EC
func_fe6_080441EC: @ 0x080441EC
	ldr r0, .L080441F8 @ =gpProcEkrDispUP
	ldr r1, [r0]
	movs r0, #1
	str r0, [r1, #0x4c]
	str r0, [r1, #0x50]
	bx lr
	.align 2, 0
.L080441F8: .4byte gpProcEkrDispUP

	thumb_func_start func_fe6_080441FC
func_fe6_080441FC: @ 0x080441FC
	ldr r0, .L08044208 @ =gpProcEkrDispUP
	ldr r1, [r0]
	movs r0, #1
	str r0, [r1, #0x4c]
	bx lr
	.align 2, 0
.L08044208: .4byte gpProcEkrDispUP

	thumb_func_start func_fe6_0804420C
func_fe6_0804420C: @ 0x0804420C
	ldr r0, .L08044218 @ =gpProcEkrDispUP
	ldr r1, [r0]
	movs r0, #1
	str r0, [r1, #0x50]
	bx lr
	.align 2, 0
.L08044218: .4byte gpProcEkrDispUP

	thumb_func_start func_fe6_0804421C
func_fe6_0804421C: @ 0x0804421C
	ldr r2, .L0804422C @ =gpProcEkrDispUP
	ldr r2, [r2]
	movs r3, #0
	strh r0, [r2, #0x32]
	strh r1, [r2, #0x3a]
	adds r2, #0x29
	strb r3, [r2]
	bx lr
	.align 2, 0
.L0804422C: .4byte gpProcEkrDispUP

	thumb_func_start func_fe6_08044230
func_fe6_08044230: @ 0x08044230
	ldr r2, .L08044240 @ =gpProcEkrDispUP
	ldr r2, [r2]
	strh r0, [r2, #0x32]
	strh r1, [r2, #0x3a]
	adds r2, #0x29
	movs r0, #1
	strb r0, [r2]
	bx lr
	.align 2, 0
.L08044240: .4byte gpProcEkrDispUP

	thumb_func_start func_fe6_08044244
func_fe6_08044244: @ 0x08044244
	ldr r0, .L08044250 @ =gpProcEkrDispUP
	ldr r0, [r0]
	adds r0, #0x29
	movs r1, #1
	strb r1, [r0]
	bx lr
	.align 2, 0
.L08044250: .4byte gpProcEkrDispUP

	thumb_func_start func_fe6_08044254
func_fe6_08044254: @ 0x08044254
	ldr r0, .L08044260 @ =gpProcEkrDispUP
	ldr r0, [r0]
	adds r0, #0x29
	movs r1, #0
	strb r1, [r0]
	bx lr
	.align 2, 0
.L08044260: .4byte gpProcEkrDispUP

	thumb_func_start EkrGauge_08044264
EkrGauge_08044264: @ 0x08044264
	ldr r0, .L08044270 @ =gpProcEkrDispUP
	ldr r0, [r0]
	adds r0, #0x2a
	movs r1, #1
	strb r1, [r0]
	bx lr
	.align 2, 0
.L08044270: .4byte gpProcEkrDispUP

	thumb_func_start UnAsyncEkrDispUP
UnAsyncEkrDispUP: @ 0x08044274
	ldr r0, .L08044280 @ =gpProcEkrDispUP
	ldr r0, [r0]
	adds r0, #0x2a
	movs r1, #0
	strb r1, [r0]
	bx lr
	.align 2, 0
.L08044280: .4byte gpProcEkrDispUP

	thumb_func_start EkrDispUP_Loop
EkrDispUP_Loop: @ 0x08044284
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #1
	beq .L08044374
	adds r0, r7, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08044374
	ldrh r1, [r7, #0x3a]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x13
	lsls r2, r0, #5
	mov r8, r2
	cmp r2, #0
	bge .L080442B6
	movs r1, #0
	mov r8, r1
.L080442B6:
	adds r6, r0, #7
	cmp r6, #6
	ble .L080442BE
	movs r6, #6
.L080442BE:
	movs r0, #6
	subs r0, r0, r6
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #1
	mov sl, r1
	ldr r0, .L080442DC @ =gEkrDistanceType
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt .L080442E0
	cmp r0, #2
	bgt .L080442E0
	movs r4, #0
	b .L080442E2
	.align 2, 0
.L080442DC: .4byte gEkrDistanceType
.L080442E0:
	movs r4, #0xf
.L080442E2:
	ldr r0, .L08044384 @ =gBg0Tm
	mov sb, r0
	movs r0, #0x9f
	str r0, [sp]
	mov r0, sb
	movs r1, #0x1e
	movs r2, #7
	movs r3, #0
	bl FillBGRect
	cmp r6, #0
	ble .L0804436E
	ldr r0, [r7, #0x4c]
	cmp r0, #0
	bne .L08044334
	ldr r0, .L08044388 @ =gUnk_08112968
	add r0, sl
	mov r1, r8
	lsls r5, r1, #1
	lsls r1, r4, #1
	add r1, sb
	adds r5, r5, r1
	lsls r4, r6, #0x10
	lsrs r4, r4, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	adds r1, r5, #0
	movs r2, #0xf
	adds r3, r4, #0
	bl EfxTmCpyBG
	movs r0, #0x80
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0xf
	adds r2, r4, #0
	movs r3, #2
	bl func_fe6_0805B01C
.L08044334:
	ldr r0, [r7, #0x50]
	cmp r0, #0
	bne .L0804436E
	ldr r0, .L0804438C @ =gUnk_08112A1C
	add r0, sl
	mov r2, r8
	lsls r5, r2, #1
	movs r2, #0xf
	lsls r1, r2, #1
	add r1, sb
	adds r5, r5, r1
	lsls r4, r6, #0x10
	lsrs r4, r4, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	adds r1, r5, #0
	adds r3, r4, #0
	bl EfxTmCpyBG
	movs r0, #0x80
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0xf
	adds r2, r4, #0
	movs r3, #3
	bl func_fe6_0805B01C
.L0804436E:
	movs r0, #1
	bl EnableBgSync
.L08044374:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08044384: .4byte gBg0Tm
.L08044388: .4byte gUnk_08112968
.L0804438C: .4byte gUnk_08112A1C

	thumb_func_start EfxClearScreenFx
EfxClearScreenFx: @ 0x08044390
	push {r4, r5, r6, lr}
	sub sp, #0x10
	ldr r4, .L08044484 @ =gDispIo
	movs r2, #8
	rsbs r2, r2, #0
	ldrb r0, [r4]
	ands r2, r0
	movs r5, #1
	ldrb r0, [r4, #1]
	orrs r0, r5
	movs r6, #2
	orrs r0, r6
	movs r1, #4
	orrs r0, r1
	movs r1, #8
	orrs r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #1]
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r2, r0
	strb r2, [r4]
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
	movs r0, #0
	movs r1, #0
	bl SetBgChrOffset
	movs r0, #1
	movs r1, #0
	bl SetBgChrOffset
	movs r0, #2
	movs r1, #0
	bl SetBgChrOffset
	movs r1, #0x80
	lsls r1, r1, #8
	movs r0, #3
	bl SetBgChrOffset
	movs r1, #0xc0
	lsls r1, r1, #7
	movs r0, #0
	bl SetBgTilemapOffset
	movs r1, #0xd0
	lsls r1, r1, #7
	movs r0, #1
	bl SetBgTilemapOffset
	movs r1, #0xe0
	lsls r1, r1, #7
	movs r0, #2
	bl SetBgTilemapOffset
	movs r1, #0xf0
	lsls r1, r1, #7
	movs r0, #3
	bl SetBgTilemapOffset
	movs r1, #4
	rsbs r1, r1, #0
	adds r0, r1, #0
	ldrb r2, [r4, #0xc]
	ands r0, r2
	strb r0, [r4, #0xc]
	adds r0, r1, #0
	ldrb r2, [r4, #0x10]
	ands r0, r2
	orrs r0, r5
	strb r0, [r4, #0x10]
	ldrb r0, [r4, #0x14]
	ands r1, r0
	orrs r1, r6
	strb r1, [r4, #0x14]
	movs r0, #3
	ldrb r1, [r4, #0x18]
	orrs r0, r1
	strb r0, [r4, #0x18]
	movs r4, #0
	str r4, [sp]
	ldr r1, .L08044488 @ =gBg0Tm
	ldr r5, .L0804448C @ =0x01000200
	mov r0, sp
	adds r2, r5, #0
	bl CpuFastSet
	str r4, [sp, #4]
	add r0, sp, #4
	ldr r1, .L08044490 @ =gBg1Tm
	adds r2, r5, #0
	bl CpuFastSet
	str r4, [sp, #8]
	add r0, sp, #8
	ldr r6, .L08044494 @ =gBg2Tm
	adds r1, r6, #0
	adds r2, r5, #0
	bl CpuFastSet
	bl GetBattleAnimArenaFlag
	cmp r0, #0
	bne .L08044498
	bl func_fe6_080444EC
	b .L080444A4
	.align 2, 0
.L08044484: .4byte gDispIo
.L08044488: .4byte gBg0Tm
.L0804448C: .4byte 0x01000200
.L08044490: .4byte gBg1Tm
.L08044494: .4byte gBg2Tm
.L08044498:
	str r4, [sp, #0xc]
	add r0, sp, #0xc
	adds r1, r6, #0
	adds r2, r5, #0
	bl CpuFastSet
.L080444A4:
	bl EfxPrepareScreenFx
	bl EnablePalSync
	movs r0, #1
	bl EnableBgSync
	movs r0, #2
	bl EnableBgSync
	movs r0, #4
	bl EnableBgSync
	ldr r3, .L080444E8 @ =gDispIo
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
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080444E8: .4byte gDispIo

	thumb_func_start func_fe6_080444EC
func_fe6_080444EC: @ 0x080444EC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, .L0804452C @ =gUnk_Banim_0201E0FC
	ldr r2, .L08044530 @ =gBanimFloorfx
	movs r0, #0
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldr r3, .L08044534 @ =0x087EA008
	adds r5, r0, r3
	movs r6, #2
	ldrsh r1, [r2, r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r3, r0, r3
	ldr r0, .L08044538 @ =gEkrDistanceType
	movs r7, #0
	ldrsh r1, [r0, r7]
	mov r8, r2
	adds r6, r0, #0
	cmp r1, #3
	bgt .L08044540
	cmp r1, #1
	bge .L08044564
	cmp r1, #0
	beq .L08044548
	ldr r0, .L0804453C @ =gUnk_Banim_020145C0
	b .L08044576
	.align 2, 0
.L0804452C: .4byte gUnk_Banim_0201E0FC
.L08044530: .4byte gBanimFloorfx
.L08044534: .4byte 0x087EA008
.L08044538: .4byte gEkrDistanceType
.L0804453C: .4byte gUnk_Banim_020145C0
.L08044540:
	ldr r7, .L0804455C @ =gUnk_Banim_020145C0
	mov ip, r7
	cmp r1, #4
	bne .L08044578
.L08044548:
	ldr r0, .L08044560 @ =gUnk_Banim_02000034
	ldr r1, .L0804455C @ =gUnk_Banim_020145C0
	str r1, [r0]
	movs r7, #0x80
	lsls r7, r7, #5
	adds r2, r1, r7
	str r2, [r0, #4]
	mov ip, r1
	b .L08044578
	.align 2, 0
.L0804455C: .4byte gUnk_Banim_020145C0
.L08044560: .4byte gUnk_Banim_02000034
.L08044564:
	ldr r0, .L080445E8 @ =gUnk_Banim_02000034
	ldr r1, .L080445EC @ =gUnk_Banim_02014DC0
	str r1, [r0]
	movs r7, #0x80
	lsls r7, r7, #5
	adds r2, r1, r7
	str r2, [r0, #4]
	ldr r0, .L080445F0 @ =0xFFFFF800
	adds r0, r0, r1
.L08044576:
	mov ip, r0
.L08044578:
	ldr r0, .L080445F4 @ =gPlaySt
	ldrb r0, [r0, #0x15]
	ldr r0, .L080445F8 @ =gUnk_Banim_02000044
	ldr r1, [r5, #0x10]
	str r1, [r0]
	ldr r1, [r3, #0x10]
	str r1, [r0, #4]
	ldr r2, .L080445FC @ =gUnk_Banim_0200003C
	ldr r1, .L08044600 @ =gUnk_085CBDB0
	movs r3, #0
	ldrsh r0, [r6, r3]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2]
	movs r7, #0
	ldrsh r0, [r6, r7]
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2, #4]
	mov r1, r8
	ldrh r0, [r1]
	movs r2, #0
	strh r0, [r4]
	movs r0, #4
	strh r0, [r4, #2]
	movs r1, #0xa0
	lsls r1, r1, #2
	strh r1, [r4, #4]
	mov r3, r8
	ldrh r0, [r3, #2]
	strh r0, [r4, #6]
	movs r0, #5
	strh r0, [r4, #8]
	strh r1, [r4, #0xa]
	ldrh r0, [r6]
	strh r0, [r4, #0xc]
	movs r0, #2
	strh r0, [r4, #0xe]
	str r2, [r4, #0x1c]
	mov r6, ip
	str r6, [r4, #0x20]
	ldr r0, .L08044604 @ =gEkrSnowWeather
	ldrh r0, [r0]
	strh r0, [r4, #0x10]
	adds r0, r4, #0
	bl func_fe6_0804BF40
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080445E8: .4byte gUnk_Banim_02000034
.L080445EC: .4byte gUnk_Banim_02014DC0
.L080445F0: .4byte 0xFFFFF800
.L080445F4: .4byte gPlaySt
.L080445F8: .4byte gUnk_Banim_02000044
.L080445FC: .4byte gUnk_Banim_0200003C
.L08044600: .4byte gUnk_085CBDB0
.L08044604: .4byte gEkrSnowWeather

	thumb_func_start EfxPrepareScreenFx
EfxPrepareScreenFx: @ 0x08044608
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r4, .L08044648 @ =Pal_Text
	adds r0, r4, #0
	movs r1, #0x40
	movs r2, #0x20
	bl ApplyPaletteExt
	adds r0, r4, #0
	movs r1, #0x60
	movs r2, #0x20
	bl ApplyPaletteExt
	ldr r0, .L0804464C @ =gUnk_Banim_02017640
	ldr r1, .L08044650 @ =0x06001400
	movs r2, #0xa0
	movs r3, #2
	bl InitTextFont
	bl SetTextDrawNoClear
	ldr r0, .L08044654 @ =gUnk_081125E0
	ldr r1, .L08044658 @ =0x06001000
	bl LZ77UnCompVram
	ldr r0, .L0804465C @ =gBanimValid
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L08044664
	ldr r5, .L08044660 @ =gNopStr
	b .L08044672
	.align 2, 0
.L08044648: .4byte Pal_Text
.L0804464C: .4byte gUnk_Banim_02017640
.L08044650: .4byte 0x06001400
.L08044654: .4byte gUnk_081125E0
.L08044658: .4byte 0x06001000
.L0804465C: .4byte gBanimValid
.L08044660: .4byte gNopStr
.L08044664:
	ldr r0, .L080446AC @ =gpEkrBattleUnitLeft
	ldr r0, [r0]
	ldr r0, [r0]
	ldrh r0, [r0]
	bl DecodeMsg
	adds r5, r0, #0
.L08044672:
	ldr r4, .L080446B0 @ =gUnk_Banim_02017658
	adds r0, r4, #0
	movs r1, #6
	bl InitText
	movs r0, #0x30
	adds r1, r5, #0
	bl GetStringTextCenteredPos
	adds r1, r0, #0
	adds r0, r4, #0
	bl Text_SetCursor
	ldr r0, .L080446B4 @ =gUnk_081127F0
	ldr r1, .L080446B8 @ =0x06001400
	bl LZ77UnCompVram
	adds r0, r4, #0
	adds r1, r5, #0
	bl Text_DrawString
	ldr r0, .L080446BC @ =gBanimValid
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L080446C4
	ldr r5, .L080446C0 @ =gNopStr
	b .L080446D2
	.align 2, 0
.L080446AC: .4byte gpEkrBattleUnitLeft
.L080446B0: .4byte gUnk_Banim_02017658
.L080446B4: .4byte gUnk_081127F0
.L080446B8: .4byte 0x06001400
.L080446BC: .4byte gBanimValid
.L080446C0: .4byte gNopStr
.L080446C4:
	ldr r0, .L0804470C @ =gpEkrBattleUnitLeft
	ldr r0, [r0]
	adds r0, #0x4a
	ldrh r0, [r0]
	bl GetItemName
	adds r5, r0, #0
.L080446D2:
	ldr r4, .L08044710 @ =gUnk_Banim_02017668
	adds r0, r4, #0
	movs r1, #7
	bl InitText
	movs r0, #0x38
	adds r1, r5, #0
	bl GetStringTextCenteredPos
	adds r1, r0, #0
	adds r0, r4, #0
	bl Text_SetCursor
	ldr r0, .L08044714 @ =gUnk_08112840
	ldr r1, .L08044718 @ =0x06001580
	bl LZ77UnCompVram
	adds r0, r4, #0
	adds r1, r5, #0
	bl Text_DrawString
	ldr r0, .L0804471C @ =gBanimValid
	movs r1, #2
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L08044724
	ldr r5, .L08044720 @ =gNopStr
	b .L08044732
	.align 2, 0
.L0804470C: .4byte gpEkrBattleUnitLeft
.L08044710: .4byte gUnk_Banim_02017668
.L08044714: .4byte gUnk_08112840
.L08044718: .4byte 0x06001580
.L0804471C: .4byte gBanimValid
.L08044720: .4byte gNopStr
.L08044724:
	ldr r0, .L0804476C @ =gpEkrBattleUnitRight
	ldr r0, [r0]
	ldr r0, [r0]
	ldrh r0, [r0]
	bl DecodeMsg
	adds r5, r0, #0
.L08044732:
	ldr r4, .L08044770 @ =gUnk_Banim_02017670
	adds r0, r4, #0
	movs r1, #6
	bl InitText
	movs r0, #0x30
	adds r1, r5, #0
	bl GetStringTextCenteredPos
	adds r1, r0, #0
	adds r0, r4, #0
	bl Text_SetCursor
	ldr r0, .L08044774 @ =gUnk_081128AC
	ldr r1, .L08044778 @ =0x06001740
	bl LZ77UnCompVram
	adds r0, r4, #0
	adds r1, r5, #0
	bl Text_DrawString
	ldr r0, .L0804477C @ =gBanimValid
	movs r1, #2
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne .L08044784
	ldr r5, .L08044780 @ =gNopStr
	b .L08044792
	.align 2, 0
.L0804476C: .4byte gpEkrBattleUnitRight
.L08044770: .4byte gUnk_Banim_02017670
.L08044774: .4byte gUnk_081128AC
.L08044778: .4byte 0x06001740
.L0804477C: .4byte gBanimValid
.L08044780: .4byte gNopStr
.L08044784:
	ldr r0, .L08044848 @ =gpEkrBattleUnitRight
	ldr r0, [r0]
	adds r0, #0x4a
	ldrh r0, [r0]
	bl GetItemName
	adds r5, r0, #0
.L08044792:
	ldr r4, .L0804484C @ =gUnk_Banim_02017660
	adds r0, r4, #0
	movs r1, #7
	bl InitText
	movs r0, #0x38
	adds r1, r5, #0
	bl GetStringTextCenteredPos
	adds r1, r0, #0
	adds r0, r4, #0
	bl Text_SetCursor
	ldr r0, .L08044850 @ =gUnk_081128FC
	ldr r1, .L08044854 @ =0x060018C0
	bl LZ77UnCompVram
	adds r0, r4, #0
	adds r1, r5, #0
	bl Text_DrawString
	ldr r4, .L08044858 @ =gBg0Tm
	adds r0, r4, #0
	movs r1, #0x9f
	bl TmFill
	ldr r0, .L0804485C @ =gUnk_08112C84
	adds r6, r4, #0
	adds r6, #0x3c
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	adds r1, r6, #0
	movs r2, #2
	movs r3, #0x14
	bl EfxTmCpyBG
	adds r4, #0x3e
	movs r5, #0x80
	str r5, [sp]
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0x14
	movs r3, #2
	bl func_fe6_0805B01C
	str r5, [sp]
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0x14
	movs r3, #3
	bl func_fe6_0805B01C
	movs r0, #1
	bl EnableBgSync
	ldr r6, .L08044860 @ =gBanimFactionPal
	movs r1, #0
	ldrsh r0, [r6, r1]
	lsls r0, r0, #5
	ldr r5, .L08044864 @ =gUnk_08112CD4
	adds r0, r0, r5
	ldr r4, .L08044868 @ =gPal+0x40
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	movs r1, #2
	ldrsh r0, [r6, r1]
	lsls r0, r0, #5
	adds r0, r0, r5
	adds r4, #0x20
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	bl EnablePalSync
	ldr r1, .L0804486C @ =gEkrBg0QuakeVec
	movs r0, #0
	strh r0, [r1]
	strh r0, [r1, #2]
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08044848: .4byte gpEkrBattleUnitRight
.L0804484C: .4byte gUnk_Banim_02017660
.L08044850: .4byte gUnk_081128FC
.L08044854: .4byte 0x060018C0
.L08044858: .4byte gBg0Tm
.L0804485C: .4byte gUnk_08112C84
.L08044860: .4byte gBanimFactionPal
.L08044864: .4byte gUnk_08112CD4
.L08044868: .4byte gPal+0x40
.L0804486C: .4byte gEkrBg0QuakeVec
