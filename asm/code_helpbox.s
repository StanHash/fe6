	.include "macro.inc"

	.syntax unified

	thumb_func_start UpdateHelpBoxDisplay
UpdateHelpBoxDisplay: @ 0x0807054C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r5, r1, #0
	movs r0, #0x38
	ldrsh r1, [r6, r0]
	movs r3, #0x3c
	ldrsh r2, [r6, r3]
	adds r4, r6, #0
	adds r4, #0x48
	movs r3, #0
	ldrsh r0, [r4, r3]
	mov ip, r0
	adds r7, r6, #0
	adds r7, #0x4a
	movs r3, #0
	ldrsh r0, [r7, r3]
	str r0, [sp]
	adds r0, r5, #0
	mov r3, ip
	bl Interpolate
	strh r0, [r6, #0x30]
	movs r0, #0x3a
	ldrsh r1, [r6, r0]
	movs r3, #0x3e
	ldrsh r2, [r6, r3]
	movs r3, #0
	ldrsh r0, [r4, r3]
	mov ip, r0
	movs r3, #0
	ldrsh r0, [r7, r3]
	str r0, [sp]
	adds r0, r5, #0
	mov r3, ip
	bl Interpolate
	strh r0, [r6, #0x32]
	adds r0, r6, #0
	adds r0, #0x40
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, #4
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r3, #0
	ldrsh r0, [r4, r3]
	mov ip, r0
	movs r3, #0
	ldrsh r0, [r7, r3]
	str r0, [sp]
	adds r0, r5, #0
	mov r3, ip
	bl Interpolate
	strh r0, [r6, #0x34]
	adds r0, r6, #0
	adds r0, #0x42
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, #4
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r0, #0
	ldrsh r3, [r4, r0]
	movs r4, #0
	ldrsh r0, [r7, r4]
	str r0, [sp]
	adds r0, r5, #0
	bl Interpolate
	strh r0, [r6, #0x36]
	movs r1, #0x30
	ldrsh r0, [r6, r1]
	movs r2, #0x32
	ldrsh r1, [r6, r2]
	movs r3, #0x34
	ldrsh r2, [r6, r3]
	movs r4, #0x36
	ldrsh r3, [r6, r4]
	bl func_fe6_08070F64
	adds r0, r6, #0
	adds r0, #0x52
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08070610
	movs r0, #0x30
	ldrsh r1, [r6, r0]
	movs r3, #0x32
	ldrsh r2, [r6, r3]
	subs r2, #0xb
	ldr r3, .L08070618 @ =Sprite_32x16
	movs r0, #0xb
	str r0, [sp]
	movs r0, #0
	bl PutSprite
.L08070610:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08070618: .4byte Sprite_32x16

	thumb_func_start HelpBox_OnOpen
HelpBox_OnOpen: @ 0x0807061C
	push {lr}
	adds r0, #0x52
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08070636
	ldr r0, .L0807063C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08070636
	movs r0, #0x70
	bl m4aSongNumStart
.L08070636:
	pop {r0}
	bx r0
	.align 2, 0
.L0807063C: .4byte gPlaySt

	thumb_func_start HelpBox_OnLoop
HelpBox_OnLoop: @ 0x08070640
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #5
	bl UpdateHelpBoxDisplay
	adds r2, r4, #0
	adds r2, #0x48
	adds r4, #0x4a
	ldrh r3, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r5, #0
	ldrsh r0, [r4, r5]
	cmp r1, r0
	bge .L08070662
	adds r0, r3, #1
	strh r0, [r2]
.L08070662:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start HelpBox_OnClose
HelpBox_OnClose: @ 0x08070668
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x52
	ldrb r0, [r0]
	cmp r0, #0
	bne .L08070696
	ldr r0, .L0807069C @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L08070684
	movs r0, #0x71
	bl m4aSongNumStart
.L08070684:
	adds r0, r4, #0
	bl ResetHelpBoxInitSize
	ldr r0, [r4, #0x2c]
	ldrb r1, [r0, #0x10]
	ldrb r2, [r0, #0x11]
	adds r0, r4, #0
	bl SetHelpBoxInitPosition
.L08070696:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0807069C: .4byte gPlaySt

	thumb_func_start HelpBox_WaitClose
HelpBox_WaitClose: @ 0x080706A0
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0
	bl UpdateHelpBoxDisplay
	adds r1, r4, #0
	adds r1, #0x48
	ldrh r0, [r1]
	subs r0, #3
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge .L080706C0
	adds r0, r4, #0
	bl Proc_Break
.L080706C0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start StartHelpBox
StartHelpBox: @ 0x080706C8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080706F4 @ =0x0203D3E0
	movs r3, #0
	str r3, [r0]
	str r3, [r0, #4]
	str r3, [r0, #8]
	str r3, [r0, #0xc]
	strb r4, [r0, #0x10]
	strb r1, [r0, #0x11]
	strh r2, [r0, #0x12]
	str r3, [r0, #0x14]
	str r3, [r0, #0x18]
	ldr r1, .L080706F8 @ =0x0203D400
	strh r3, [r1]
	strh r3, [r1, #2]
	movs r1, #0
	bl StartHelpBoxExt
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080706F4: .4byte 0x0203D3E0
.L080706F8: .4byte 0x0203D400

	thumb_func_start StartItemHelpBox
StartItemHelpBox: @ 0x080706FC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0807072C @ =0x0203D3E0
	movs r3, #0
	str r3, [r0]
	str r3, [r0, #4]
	str r3, [r0, #8]
	str r3, [r0, #0xc]
	strb r4, [r0, #0x10]
	strb r1, [r0, #0x11]
	strh r2, [r0, #0x12]
	str r3, [r0, #0x14]
	ldr r1, .L08070730 @ =HbPopulate_AutoItem
	str r1, [r0, #0x18]
	ldr r1, .L08070734 @ =0x0203D400
	strh r3, [r1]
	strh r3, [r1, #2]
	movs r1, #0
	bl StartHelpBoxExt
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0807072C: .4byte 0x0203D3E0
.L08070730: .4byte HbPopulate_AutoItem
.L08070734: .4byte 0x0203D400

	thumb_func_start StartHelpBoxExt
StartHelpBoxExt: @ 0x08070738
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r7, r1, #0
	ldr r6, .L08070770 @ =ProcScr_HelpBox
	adds r0, r6, #0
	bl Proc_Find
	adds r4, r0, #0
	cmp r4, #0
	bne .L08070774
	adds r0, r6, #0
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	adds r0, #0x52
	strb r7, [r0]
	ldrb r1, [r5, #0x10]
	ldrb r2, [r5, #0x11]
	adds r0, r4, #0
	bl SetHelpBoxInitPosition
	adds r0, r4, #0
	bl ResetHelpBoxInitSize
	b .L0807078C
	.align 2, 0
.L08070770: .4byte ProcScr_HelpBox
.L08070774:
	ldrh r0, [r4, #0x30]
	strh r0, [r4, #0x38]
	ldrh r0, [r4, #0x32]
	strh r0, [r4, #0x3a]
	ldrh r1, [r4, #0x34]
	adds r0, r4, #0
	adds r0, #0x40
	strh r1, [r0]
	ldrh r0, [r4, #0x36]
	adds r1, r4, #0
	adds r1, #0x42
	strh r0, [r1]
.L0807078C:
	str r5, [r4, #0x2c]
	adds r0, r4, #0
	adds r0, #0x48
	movs r1, #0
	strh r1, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	movs r0, #0xc
	strh r0, [r2]
	adds r7, r4, #0
	adds r7, #0x4e
	strh r1, [r7]
	ldrh r0, [r5, #0x12]
	adds r6, r4, #0
	adds r6, #0x4c
	strh r0, [r6]
	ldr r0, [r4, #0x2c]
	ldr r1, [r0, #0x18]
	cmp r1, #0
	beq .L080707BA
	adds r0, r4, #0
	bl _call_via_r1
.L080707BA:
	movs r0, #1
	bl SetTextFontGlyphs
	ldrh r0, [r6]
	bl DecodeMsg
	add r2, sp, #4
	mov r1, sp
	bl GetStringTextBox
	movs r0, #0
	bl SetTextFontGlyphs
	ldr r1, [sp]
	ldr r2, [sp, #4]
	adds r0, r4, #0
	bl ApplyHelpBoxContentSize
	ldrb r1, [r5, #0x10]
	ldrb r2, [r5, #0x11]
	adds r0, r4, #0
	bl ApplyHelpBoxPosition
	bl func_fe6_08071514
	ldrh r0, [r7]
	ldrh r1, [r6]
	bl func_fe6_080714F8
	ldr r0, .L08070800 @ =0x0203D3FC
	str r5, [r0]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08070800: .4byte 0x0203D3FC

	thumb_func_start StartHelpBox_08070804
StartHelpBox_08070804: @ 0x08070804
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r2
	ldr r0, .L08070898 @ =ProcScr_HelpBox
	movs r1, #3
	bl SpawnProc
	adds r7, r0, #0
	adds r2, r7, #0
	adds r2, #0x52
	movs r1, #0
	movs r0, #1
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0x48
	strh r1, [r0]
	subs r2, #8
	movs r0, #0xc
	strh r0, [r2]
	movs r0, #0x4e
	adds r0, r0, r7
	mov sb, r0
	strh r1, [r0]
	adds r4, r7, #0
	adds r4, #0x4c
	mov r1, r8
	strh r1, [r4]
	movs r0, #1
	bl SetTextFontGlyphs
	ldrh r0, [r4]
	bl DecodeMsg
	add r2, sp, #4
	mov r1, sp
	bl GetStringTextBox
	movs r0, #0
	bl SetTextFontGlyphs
	adds r0, r7, #0
	bl ResetHelpBoxInitSize
	ldr r1, [sp]
	ldr r2, [sp, #4]
	adds r0, r7, #0
	bl ApplyHelpBoxContentSize
	adds r5, #8
	strh r5, [r7, #0x38]
	adds r6, #8
	strh r6, [r7, #0x3a]
	strh r5, [r7, #0x3c]
	strh r6, [r7, #0x3e]
	bl func_fe6_08071514
	mov r1, sb
	ldrh r0, [r1]
	ldrh r1, [r4]
	bl func_fe6_080714F8
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08070898: .4byte ProcScr_HelpBox

	thumb_func_start CloseHelpBox
CloseHelpBox: @ 0x0807089C
	push {r4, lr}
	ldr r0, .L080708BC @ =ProcScr_HelpBox
	bl Proc_Find
	adds r4, r0, #0
	cmp r4, #0
	beq .L080708B6
	bl func_fe6_08071514
	adds r0, r4, #0
	movs r1, #0x63
	bl Proc_Goto
.L080708B6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080708BC: .4byte ProcScr_HelpBox

	thumb_func_start KillHelpBox
KillHelpBox: @ 0x080708C0
	push {r4, lr}
	ldr r0, .L080708E0 @ =ProcScr_HelpBox
	bl Proc_Find
	adds r4, r0, #0
	cmp r4, #0
	beq .L080708D8
	bl func_fe6_08071514
	adds r0, r4, #0
	bl Proc_End
.L080708D8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080708E0: .4byte ProcScr_HelpBox

	thumb_func_start HelpBoxMoveControl_OnInitBox
HelpBoxMoveControl_OnInitBox: @ 0x080708E4
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x50
	movs r1, #0
	strh r1, [r0]
	ldr r0, [r4, #0x2c]
	ldr r1, [r0, #0x14]
	cmp r1, #0
	beq .L080708FC
	adds r0, r4, #0
	bl _call_via_r1
.L080708FC:
	ldr r0, [r4, #0x2c]
	movs r1, #0
	bl StartHelpBoxExt
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start HelpBoxMoveControl_OnIdle
HelpBoxMoveControl_OnIdle: @ 0x0807090C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r4, #0
	ldr r1, .L080709A4 @ =0x0203D400
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #3
	ldr r2, [r5, #0x2c]
	ldrb r3, [r2, #0x10]
	adds r0, r3, r0
	movs r3, #2
	ldrsh r1, [r1, r3]
	lsls r1, r1, #3
	ldrb r2, [r2, #0x11]
	adds r1, r2, r1
	bl PutUiHand
	ldr r6, .L080709A8 @ =gKeySt
	ldr r1, [r6]
	movs r0, #0x40
	ldrh r1, [r1, #6]
	ands r0, r1
	cmp r0, #0
	beq .L08070946
	adds r0, r5, #0
	bl func_fe6_08070B8C
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
.L08070946:
	ldr r1, [r6]
	movs r0, #0x80
	ldrh r1, [r1, #6]
	ands r0, r1
	cmp r0, #0
	beq .L0807095E
	adds r0, r5, #0
	bl func_fe6_08070BBC
	orrs r4, r0
	lsls r0, r4, #0x18
	lsrs r4, r0, #0x18
.L0807095E:
	ldr r1, [r6]
	movs r0, #0x20
	ldrh r1, [r1, #6]
	ands r0, r1
	cmp r0, #0
	beq .L08070976
	adds r0, r5, #0
	bl func_fe6_08070BEC
	orrs r4, r0
	lsls r0, r4, #0x18
	lsrs r4, r0, #0x18
.L08070976:
	ldr r1, [r6]
	movs r0, #0x10
	ldrh r1, [r1, #6]
	ands r0, r1
	cmp r0, #0
	beq .L0807098E
	adds r0, r5, #0
	bl func_fe6_08070C1C
	orrs r4, r0
	lsls r0, r4, #0x18
	lsrs r4, r0, #0x18
.L0807098E:
	ldr r1, [r6]
	movs r0, #0x81
	lsls r0, r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L080709AC
	adds r0, r5, #0
	bl Proc_Break
	b .L080709C8
	.align 2, 0
.L080709A4: .4byte 0x0203D400
.L080709A8: .4byte gKeySt
.L080709AC:
	cmp r4, #0
	beq .L080709C8
	ldr r0, .L080709D0 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L080709C0
	movs r0, #0x67
	bl m4aSongNumStart
.L080709C0:
	adds r0, r5, #0
	movs r1, #0
	bl Proc_Goto
.L080709C8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080709D0: .4byte gPlaySt

	thumb_func_start HelpBoxMoveControl_OnEnd
HelpBoxMoveControl_OnEnd: @ 0x080709D4
	push {r4, lr}
	adds r4, r0, #0
	bl CloseHelpBox
	adds r0, r4, #0
	bl Proc_End
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start StartMovingHelpBox
StartMovingHelpBox: @ 0x080709E8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L08070A04 @ =ProcScr_HelpBoxMoveControl
	bl SpawnProcLocking
	ldr r2, .L08070A08 @ =0x0203D400
	movs r1, #0
	strh r1, [r2]
	strh r1, [r2, #2]
	str r4, [r0, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08070A04: .4byte ProcScr_HelpBoxMoveControl
.L08070A08: .4byte 0x0203D400

	thumb_func_start StartMovingHelpBoxExt
StartMovingHelpBoxExt: @ 0x08070A0C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r2, #0
	adds r5, r3, #0
	ldr r0, .L08070A28 @ =ProcScr_HelpBoxMoveControl
	bl SpawnProcLocking
	ldr r1, .L08070A2C @ =0x0203D400
	strh r4, [r1]
	strh r5, [r1, #2]
	str r6, [r0, #0x2c]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08070A28: .4byte ProcScr_HelpBoxMoveControl
.L08070A2C: .4byte 0x0203D400

	thumb_func_start ApplyHelpBoxContentSize
ApplyHelpBoxContentSize: @ 0x08070A30
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r4, #0x1f
	movs r0, #0xe0
	ands r4, r0
	adds r0, r6, #0
	adds r0, #0x4e
	ldrh r0, [r0]
	bl func_fe6_08070B30
	cmp r0, #1
	beq .L08070A52
	cmp r0, #2
	beq .L08070A58
	b .L08070A60
.L08070A52:
	movs r4, #0xa0
	adds r5, #0x20
	b .L08070A60
.L08070A58:
	cmp r4, #0x5f
	bgt .L08070A5E
	movs r4, #0x60
.L08070A5E:
	adds r5, #0x10
.L08070A60:
	adds r0, r6, #0
	adds r0, #0x44
	strh r4, [r0]
	adds r0, #2
	strh r5, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start ApplyHelpBoxPosition
ApplyHelpBoxPosition: @ 0x08070A70
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r7, r2, #0
	adds r0, #0x44
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r6, r0, #0
	adds r6, #0x10
	adds r0, r5, #0
	adds r0, #0x46
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r0, #0x10
	mov r8, r0
	ldr r1, .L08070AF8 @ =0x0203D400
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #3
	adds r4, r4, r0
	movs r2, #2
	ldrsh r0, [r1, r2]
	lsls r0, r0, #3
	adds r7, r7, r0
	adds r0, r6, #0
	movs r1, #6
	bl __divsi3
	adds r0, #0x10
	subs r4, r4, r0
	strh r4, [r5, #0x3c]
	lsls r4, r4, #0x10
	cmp r4, #0
	bge .L08070ABC
	movs r0, #0
	strh r0, [r5, #0x3c]
.L08070ABC:
	movs r1, #0x3c
	ldrsh r0, [r5, r1]
	adds r0, r0, r6
	cmp r0, #0xf0
	ble .L08070ACC
	movs r0, #0xf0
	subs r0, r0, r6
	strh r0, [r5, #0x3c]
.L08070ACC:
	adds r0, r7, #0
	adds r0, #0x10
	strh r0, [r5, #0x3e]
	movs r2, #0x3e
	ldrsh r0, [r5, r2]
	add r0, r8
	cmp r0, #0xa0
	ble .L08070AE2
	mov r1, r8
	subs r0, r7, r1
	strh r0, [r5, #0x3e]
.L08070AE2:
	ldrh r0, [r5, #0x3c]
	adds r0, #8
	strh r0, [r5, #0x3c]
	ldrh r0, [r5, #0x3e]
	adds r0, #8
	strh r0, [r5, #0x3e]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08070AF8: .4byte 0x0203D400

	thumb_func_start SetHelpBoxInitPosition
SetHelpBoxInitPosition: @ 0x08070AFC
	push {r4, r5, lr}
	ldr r4, .L08070B1C @ =0x0203D400
	movs r5, #0
	ldrsh r3, [r4, r5]
	lsls r3, r3, #3
	adds r1, r1, r3
	movs r5, #2
	ldrsh r3, [r4, r5]
	lsls r3, r3, #3
	adds r2, r2, r3
	strh r1, [r0, #0x38]
	strh r2, [r0, #0x3a]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08070B1C: .4byte 0x0203D400

	thumb_func_start ResetHelpBoxInitSize
ResetHelpBoxInitSize: @ 0x08070B20
	adds r2, r0, #0
	adds r2, #0x40
	movs r1, #0x20
	strh r1, [r2]
	adds r0, #0x42
	movs r1, #0x10
	strh r1, [r0]
	bx lr

	thumb_func_start func_fe6_08070B30
func_fe6_08070B30: @ 0x08070B30
	push {r4, lr}
	adds r4, r0, #0
	bl GetItemAttributes
	movs r1, #0x80
	lsls r1, r1, #3
	ands r1, r0
	cmp r1, #0
	bne .L08070B62
	adds r0, r4, #0
	bl GetItemAttributes
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq .L08070B54
	movs r0, #1
	b .L08070B68
.L08070B54:
	adds r0, r4, #0
	bl GetItemAttributes
	movs r1, #4
	ands r1, r0
	cmp r1, #0
	bne .L08070B66
.L08070B62:
	movs r0, #0
	b .L08070B68
.L08070B66:
	movs r0, #2
.L08070B68:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start HbPopulate_AutoItem
HbPopulate_AutoItem: @ 0x08070B70
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x2c]
	ldrh r0, [r0, #0x12]
	adds r1, r4, #0
	adds r1, #0x4e
	strh r0, [r1]
	bl GetItemDescMsg
	adds r4, #0x4c
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08070B8C
func_fe6_08070B8C: @ 0x08070B8C
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x2c]
	ldr r0, [r0]
	cmp r0, #0
	bne .L08070B9C
	movs r0, #0
	b .L08070BB6
.L08070B9C:
	str r0, [r2, #0x2c]
	adds r0, r2, #0
	adds r0, #0x50
	movs r1, #0x40
	strh r1, [r0]
	ldr r0, [r2, #0x2c]
	ldr r1, [r0, #0x14]
	cmp r1, #0
	beq .L08070BB4
	adds r0, r2, #0
	bl _call_via_r1
.L08070BB4:
	movs r0, #1
.L08070BB6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08070BBC
func_fe6_08070BBC: @ 0x08070BBC
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x2c]
	ldr r0, [r0, #4]
	cmp r0, #0
	bne .L08070BCC
	movs r0, #0
	b .L08070BE6
.L08070BCC:
	str r0, [r2, #0x2c]
	adds r0, r2, #0
	adds r0, #0x50
	movs r1, #0x80
	strh r1, [r0]
	ldr r0, [r2, #0x2c]
	ldr r1, [r0, #0x14]
	cmp r1, #0
	beq .L08070BE4
	adds r0, r2, #0
	bl _call_via_r1
.L08070BE4:
	movs r0, #1
.L08070BE6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08070BEC
func_fe6_08070BEC: @ 0x08070BEC
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x2c]
	ldr r0, [r0, #8]
	cmp r0, #0
	bne .L08070BFC
	movs r0, #0
	b .L08070C16
.L08070BFC:
	str r0, [r2, #0x2c]
	adds r0, r2, #0
	adds r0, #0x50
	movs r1, #0x20
	strh r1, [r0]
	ldr r0, [r2, #0x2c]
	ldr r1, [r0, #0x14]
	cmp r1, #0
	beq .L08070C14
	adds r0, r2, #0
	bl _call_via_r1
.L08070C14:
	movs r0, #1
.L08070C16:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08070C1C
func_fe6_08070C1C: @ 0x08070C1C
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x2c]
	ldr r0, [r0, #0xc]
	cmp r0, #0
	bne .L08070C2C
	movs r0, #0
	b .L08070C46
.L08070C2C:
	str r0, [r2, #0x2c]
	adds r0, r2, #0
	adds r0, #0x50
	movs r1, #0x10
	strh r1, [r0]
	ldr r0, [r2, #0x2c]
	ldr r1, [r0, #0x14]
	cmp r1, #0
	beq .L08070C44
	adds r0, r2, #0
	bl _call_via_r1
.L08070C44:
	movs r0, #1
.L08070C46:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08070C4C
func_fe6_08070C4C: @ 0x08070C4C
	push {lr}
	adds r2, r0, #0
	ldr r0, .L08070C6C @ =gKeySt
	ldr r1, [r0]
	movs r0, #0x81
	lsls r0, r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L08070C66
	adds r0, r2, #0
	bl Proc_Break
.L08070C66:
	pop {r0}
	bx r0
	.align 2, 0
.L08070C6C: .4byte gKeySt

	thumb_func_start func_fe6_08070C70
func_fe6_08070C70: @ 0x08070C70
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0
	bl func_fe6_08070E70
	bl GetUiHandPrevX
	adds r4, r0, #0
	bl GetUiHandPrevY
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl StartHelpBox
	ldr r0, .L08070CA4 @ =gUnk_08677788
	adds r1, r6, #0
	bl SpawnProcLocking
	movs r0, #1
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
.L08070CA4: .4byte gUnk_08677788

	thumb_func_start func_fe6_08070CA8
func_fe6_08070CA8: @ 0x08070CA8
	ldr r0, .L08070CB0 @ =0x0203D3FC
	ldr r0, [r0]
	bx lr
	.align 2, 0
.L08070CB0: .4byte 0x0203D3FC

	thumb_func_start func_fe6_08070CB4
func_fe6_08070CB4: @ 0x08070CB4
	push {lr}
	adds r2, r0, #0
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq .L08070CD0
	ldr r0, .L08070CCC @ =gUnk_0830D5E4
	lsls r1, r1, #5
	movs r2, #0x20
	bl ApplyPaletteExt
	b .L08070CFA
	.align 2, 0
.L08070CCC: .4byte gUnk_0830D5E4
.L08070CD0:
	movs r0, #1
	ands r0, r2
	ldr r3, .L08070D00 @ =gUnk_083094F4
	cmp r0, #0
	beq .L08070CDC
	ldr r3, .L08070D04 @ =gUnk_08309474
.L08070CDC:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq .L08070CE6
	adds r3, #0x20
.L08070CE6:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq .L08070CF0
	adds r3, #0x40
.L08070CF0:
	lsls r1, r1, #5
	adds r0, r3, #0
	movs r2, #0x20
	bl ApplyPaletteExt
.L08070CFA:
	pop {r0}
	bx r0
	.align 2, 0
.L08070D00: .4byte gUnk_083094F4
.L08070D04: .4byte gUnk_08309474

	thumb_func_start func_fe6_08070D08
func_fe6_08070D08: @ 0x08070D08
	push {r4, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	cmp r3, #0x2c
	bls .L08070D14
	movs r3, #0x26
.L08070D14:
	ldr r2, .L08070D3C @ =0x0203D404
	ldr r0, .L08070D40 @ =0x000003FF
	adds r1, r0, #0
	adds r0, r4, #0
	ands r0, r1
	strh r0, [r2, #2]
	ldr r1, .L08070D44 @ =gUnk_08677F20
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r0, [r0]
	lsls r1, r4, #5
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	bl Decompress
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08070D3C: .4byte 0x0203D404
.L08070D40: .4byte 0x000003FF
.L08070D44: .4byte gUnk_08677F20

	thumb_func_start func_fe6_08070D48
func_fe6_08070D48: @ 0x08070D48
	push {lr}
	adds r1, r0, #0
	ldr r3, .L08070D6C @ =0x0203D404
	ldr r0, .L08070D70 @ =0x000003FF
	adds r2, r0, #0
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	ldr r0, .L08070D74 @ =gUnk_0830C804
	lsls r1, r1, #5
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	bl Decompress
	pop {r0}
	bx r0
	.align 2, 0
.L08070D6C: .4byte 0x0203D404
.L08070D70: .4byte 0x000003FF
.L08070D74: .4byte gUnk_0830C804

	thumb_func_start func_fe6_08070D78
func_fe6_08070D78: @ 0x08070D78
	push {lr}
	adds r1, r0, #0
	ldr r3, .L08070D9C @ =0x0203D404
	ldr r0, .L08070DA0 @ =0x000003FF
	adds r2, r0, #0
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	ldr r0, .L08070DA4 @ =gUnk_0830CFE0
	lsls r1, r1, #5
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	bl Decompress
	pop {r0}
	bx r0
	.align 2, 0
.L08070D9C: .4byte 0x0203D404
.L08070DA0: .4byte 0x000003FF
.L08070DA4: .4byte gUnk_0830CFE0

	thumb_func_start func_fe6_08070DA8
func_fe6_08070DA8: @ 0x08070DA8
	adds r2, r0, #0
	ldr r0, .L08070DC4 @ =0x0203D404
	lsls r1, r1, #0xc
	ldrh r0, [r0, #2]
	adds r0, r0, r1
	movs r1, #0x3f
.L08070DB4:
	strh r0, [r2]
	adds r0, #1
	adds r2, #2
	subs r1, #1
	cmp r1, #0
	bge .L08070DB4
	bx lr
	.align 2, 0
.L08070DC4: .4byte 0x0203D404

	thumb_func_start func_fe6_08070DC8
func_fe6_08070DC8: @ 0x08070DC8
	adds r2, r0, #0
	ldr r0, .L08070DE4 @ =0x0203D404
	lsls r1, r1, #0xc
	ldrh r0, [r0]
	adds r0, r0, r1
	movs r1, #0x7f
.L08070DD4:
	strh r0, [r2]
	adds r0, #1
	adds r2, #2
	subs r1, #1
	cmp r1, #0
	bge .L08070DD4
	bx lr
	.align 2, 0
.L08070DE4: .4byte 0x0203D404

	thumb_func_start func_fe6_08070DE8
func_fe6_08070DE8: @ 0x08070DE8
	push {lr}
	adds r2, r1, #0
	ldr r1, .L08070E04 @ =gUnk_0830D4F0
	ldr r3, .L08070E08 @ =0x0203D404
	lsls r2, r2, #0xc
	ldrh r3, [r3]
	adds r2, r3, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl TmApplyTsa_t
	pop {r0}
	bx r0
	.align 2, 0
.L08070E04: .4byte gUnk_0830D4F0
.L08070E08: .4byte 0x0203D404

	thumb_func_start func_fe6_08070E0C
func_fe6_08070E0C: @ 0x08070E0C
	push {lr}
	adds r1, r0, #0
	cmp r1, #0
	bne .L08070E18
	movs r0, #0x26
	b .L08070E6C
.L08070E18:
	movs r0, #1
	rsbs r0, r0, #0
	movs r2, #0xe
	ldrsb r2, [r1, r2]
	cmp r2, r0
	beq .L08070E30
	cmp r2, r0
	blt .L08070E34
	cmp r2, #0x2c
	bgt .L08070E34
	cmp r2, #0x28
	blt .L08070E34
.L08070E30:
	movs r0, #0x2b
	b .L08070E6C
.L08070E34:
	movs r0, #0x20
	ldrb r3, [r1, #0x14]
	ands r0, r3
	cmp r0, #0
	beq .L08070E64
	ldrb r1, [r1, #0x19]
	lsls r0, r1, #0x1c
	lsrs r0, r0, #0x1c
	cmp r0, #1
	beq .L08070E5C
	cmp r0, #1
	bgt .L08070E52
	cmp r0, #0
	beq .L08070E58
	b .L08070E64
.L08070E52:
	cmp r0, #2
	beq .L08070E60
	b .L08070E64
.L08070E58:
	movs r0, #0x2a
	b .L08070E6C
.L08070E5C:
	movs r0, #0x29
	b .L08070E6C
.L08070E60:
	movs r0, #0x28
	b .L08070E6C
.L08070E64:
	adds r0, r2, #0
	bl GetChapterInfo
	ldrb r0, [r0, #0xe]
.L08070E6C:
	pop {r1}
	bx r1

	thumb_func_start func_fe6_08070E70
func_fe6_08070E70: @ 0x08070E70
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	cmp r7, #0
	bne .L08070E7C
	ldr r7, .L08070EDC @ =0x06013000
.L08070E7C:
	cmp r5, #0
	bge .L08070E82
	movs r5, #5
.L08070E82:
	movs r4, #0xf
	adds r0, r4, #0
	ands r0, r5
	adds r5, r0, #0
	adds r5, #0x10
	ldr r0, .L08070EE0 @ =gUnk_08308A78
	adds r1, r7, #0
	bl Decompress
	ldr r6, .L08070EE4 @ =0x0203D40C
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl InitSpriteTextFont
	adds r0, r6, #0
	adds r0, #0x18
	bl InitSpriteText
	adds r0, r6, #0
	adds r0, #0x20
	bl InitSpriteText
	adds r0, r6, #0
	adds r0, #0x28
	bl InitSpriteText
	movs r0, #0
	bl SetTextFont
	ldr r0, .L08070EE8 @ =Pal_08100A48
	lsls r1, r5, #5
	movs r2, #0x20
	bl ApplyPaletteExt
	lsls r0, r7, #0x11
	lsrs r0, r0, #0x16
	ands r5, r4
	lsls r1, r5, #0xc
	adds r0, r0, r1
	strh r0, [r6, #0x30]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08070EDC: .4byte 0x06013000
.L08070EE0: .4byte gUnk_08308A78
.L08070EE4: .4byte 0x0203D40C
.L08070EE8: .4byte Pal_08100A48

	thumb_func_start func_fe6_08070EEC
func_fe6_08070EEC: @ 0x08070EEC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	cmp r7, #0
	bne .L08070EF8
	ldr r7, .L08070F54 @ =0x06013000
.L08070EF8:
	cmp r5, #0
	bge .L08070EFE
	movs r5, #5
.L08070EFE:
	movs r4, #0xf
	adds r0, r4, #0
	ands r0, r5
	adds r5, r0, #0
	adds r5, #0x10
	ldr r0, .L08070F58 @ =gUnk_08308A78
	adds r1, r7, #0
	bl Decompress
	ldr r6, .L08070F5C @ =0x0203D40C
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl InitSpriteTextFont
	adds r0, r6, #0
	adds r0, #0x18
	bl InitSpriteText
	adds r0, r6, #0
	adds r0, #0x20
	bl InitSpriteText
	adds r1, r6, #0
	adds r1, #0x2c
	movs r0, #0
	strb r0, [r1]
	bl SetTextFont
	ldr r0, .L08070F60 @ =Pal_08100A48
	lsls r1, r5, #5
	movs r2, #0x20
	bl ApplyPaletteExt
	lsls r0, r7, #0x11
	lsrs r0, r0, #0x16
	ands r5, r4
	lsls r1, r5, #0xc
	adds r0, r0, r1
	strh r0, [r6, #0x30]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08070F54: .4byte 0x06013000
.L08070F58: .4byte gUnk_08308A78
.L08070F5C: .4byte 0x0203D40C
.L08070F60: .4byte Pal_08100A48

	thumb_func_start func_fe6_08070F64
func_fe6_08070F64: @ 0x08070F64
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov sb, r0
	mov sl, r1
	adds r7, r2, #0
	mov r8, r3
	cmp r7, #0x1f
	bgt .L08070F7E
	movs r7, #0x20
.L08070F7E:
	cmp r7, #0xc0
	ble .L08070F84
	movs r7, #0xc0
.L08070F84:
	mov r0, r8
	cmp r0, #0xf
	bgt .L08070F8E
	movs r1, #0x10
	mov r8, r1
.L08070F8E:
	mov r3, r8
	cmp r3, #0x30
	ble .L08070F98
	movs r0, #0x30
	mov r8, r0
.L08070F98:
	adds r0, r7, #0
	adds r0, #0x1f
	cmp r0, #0
	bge .L08070FA2
	adds r0, #0x1f
.L08070FA2:
	asrs r0, r0, #5
	mov r1, r8
	adds r1, #0xf
	cmp r1, #0
	bge .L08070FAE
	adds r1, #0xf
.L08070FAE:
	asrs r1, r1, #4
	str r1, [sp, #4]
	subs r6, r0, #1
	str r6, [sp, #8]
	mov r1, sl
	subs r1, #8
	str r1, [sp, #0x18]
	mov r3, sl
	add r3, r8
	str r3, [sp, #0x10]
	mov r0, sb
	subs r0, #8
	str r0, [sp, #0x14]
	mov r1, sb
	adds r1, r1, r7
	str r1, [sp, #0xc]
	cmp r6, #0
	blt .L0807101A
.L08070FD2:
	ldr r5, [sp, #4]
	subs r4, r6, #1
	cmp r5, #0
	blt .L08071014
.L08070FDA:
	adds r0, r6, #1
	lsls r1, r0, #5
	cmp r1, r7
	ble .L08070FE4
	adds r1, r7, #0
.L08070FE4:
	subs r1, #0x20
	adds r0, r5, #1
	lsls r0, r0, #4
	cmp r0, r8
	ble .L08070FF0
	mov r0, r8
.L08070FF0:
	subs r0, #0x10
	add r1, sb
	mov r3, sl
	adds r2, r3, r0
	ldr r3, .L080710F8 @ =0x0203D40C
	lsls r0, r6, #2
	ldrh r3, [r3, #0x30]
	adds r0, r3, r0
	lsls r3, r5, #6
	adds r0, r0, r3
	str r0, [sp]
	movs r0, #0
	ldr r3, .L080710FC @ =Sprite_32x16
	bl PutSprite
	subs r5, #1
	cmp r5, #0
	bge .L08070FDA
.L08071014:
	adds r6, r4, #0
	cmp r6, #0
	bge .L08070FD2
.L0807101A:
	ldr r6, [sp, #8]
	cmp r6, #0
	blt .L0807105C
	ldr r5, .L080710F8 @ =0x0203D40C
.L08071022:
	adds r0, r6, #1
	lsls r1, r0, #5
	cmp r1, r7
	ble .L0807102C
	adds r1, r7, #0
.L0807102C:
	subs r1, #0x20
	mov r0, sb
	adds r4, r0, r1
	ldrh r0, [r5, #0x30]
	adds r0, #0x1b
	str r0, [sp]
	movs r0, #0
	adds r1, r4, #0
	ldr r2, [sp, #0x18]
	ldr r3, .L08071100 @ =Sprite_32x8
	bl PutSprite
	ldrh r0, [r5, #0x30]
	adds r0, #0x1b
	str r0, [sp]
	movs r0, #0
	adds r1, r4, #0
	ldr r2, [sp, #0x10]
	ldr r3, .L08071104 @ =Sprite_32x8_VFlipped
	bl PutSprite
	subs r6, #1
	cmp r6, #0
	bge .L08071022
.L0807105C:
	ldr r5, [sp, #4]
	cmp r5, #0
	blt .L0807109E
	ldr r6, .L080710F8 @ =0x0203D40C
.L08071064:
	adds r0, r5, #1
	lsls r0, r0, #4
	cmp r0, r8
	ble .L0807106E
	mov r0, r8
.L0807106E:
	subs r0, #0x10
	mov r1, sl
	adds r4, r1, r0
	ldrh r0, [r6, #0x30]
	adds r0, #0x1f
	str r0, [sp]
	movs r0, #0
	ldr r1, [sp, #0x14]
	adds r2, r4, #0
	ldr r3, .L08071108 @ =Sprite_8x16
	bl PutSprite
	ldrh r0, [r6, #0x30]
	adds r0, #0x1f
	str r0, [sp]
	movs r0, #0
	ldr r1, [sp, #0xc]
	adds r2, r4, #0
	ldr r3, .L0807110C @ =Sprite_8x16_HFlipped
	bl PutSprite
	subs r5, #1
	cmp r5, #0
	bge .L08071064
.L0807109E:
	ldr r3, .L08071110 @ =Sprite_8x8
	ldr r4, .L080710F8 @ =0x0203D40C
	ldrh r0, [r4, #0x30]
	adds r0, #0x3e
	str r0, [sp]
	movs r0, #0
	ldr r1, [sp, #0x14]
	ldr r2, [sp, #0x18]
	bl PutSprite
	ldr r3, .L08071114 @ =Sprite_8x8_HFlipped
	ldrh r0, [r4, #0x30]
	adds r0, #0x3e
	str r0, [sp]
	movs r0, #0
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #0x18]
	bl PutSprite
	ldr r3, .L08071118 @ =Sprite_8x8_VFlipped
	ldrh r0, [r4, #0x30]
	adds r0, #0x3e
	str r0, [sp]
	movs r0, #0
	ldr r1, [sp, #0x14]
	ldr r2, [sp, #0x10]
	bl PutSprite
	ldr r3, .L0807111C @ =Sprite_8x8_HFlipped_VFlipped
	ldrh r0, [r4, #0x30]
	adds r0, #0x3e
	str r0, [sp]
	movs r0, #0
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #0x10]
	bl PutSprite
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080710F8: .4byte 0x0203D40C
.L080710FC: .4byte Sprite_32x16
.L08071100: .4byte Sprite_32x8
.L08071104: .4byte Sprite_32x8_VFlipped
.L08071108: .4byte Sprite_8x16
.L0807110C: .4byte Sprite_8x16_HFlipped
.L08071110: .4byte Sprite_8x8
.L08071114: .4byte Sprite_8x8_HFlipped
.L08071118: .4byte Sprite_8x8_VFlipped
.L0807111C: .4byte Sprite_8x8_HFlipped_VFlipped

	thumb_func_start func_fe6_08071120
func_fe6_08071120: @ 0x08071120
	push {r4, lr}
	ldr r4, .L08071180 @ =0x0203D424
	bl GetItemKind
	bl GetItemKindString
	adds r3, r0, #0
	adds r0, r4, #0
	movs r1, #0
	movs r2, #8
	bl Text_InsertDrawString
	ldr r3, .L08071184 @ =gUnk_08319894
	adds r0, r4, #0
	movs r1, #0x24
	movs r2, #8
	bl Text_InsertDrawString
	ldr r3, .L08071188 @ =gUnk_0831989C
	adds r0, r4, #0
	movs r1, #0x60
	movs r2, #8
	bl Text_InsertDrawString
	adds r4, #8
	ldr r3, .L0807118C @ =gUnk_083198A4
	adds r0, r4, #0
	movs r1, #0
	movs r2, #8
	bl Text_InsertDrawString
	ldr r3, .L08071190 @ =gUnk_083198AC
	adds r0, r4, #0
	movs r1, #0x30
	movs r2, #8
	bl Text_InsertDrawString
	ldr r3, .L08071194 @ =gUnk_083198B4
	adds r0, r4, #0
	movs r1, #0x60
	movs r2, #8
	bl Text_InsertDrawString
	movs r0, #2
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L08071180: .4byte 0x0203D424
.L08071184: .4byte gUnk_08319894
.L08071188: .4byte gUnk_0831989C
.L0807118C: .4byte gUnk_083198A4
.L08071190: .4byte gUnk_083198AC
.L08071194: .4byte gUnk_083198B4

	thumb_func_start func_fe6_08071198
func_fe6_08071198: @ 0x08071198
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, .L08071214 @ =0x0203D424
	bl GetItemRequiredExp
	bl GetWeaponLevelStringFromExp
	adds r3, r0, #0
	adds r0, r4, #0
	movs r1, #0xc
	movs r2, #7
	bl Text_InsertDrawString
	adds r0, r5, #0
	bl GetItemRangeString
	adds r3, r0, #0
	adds r0, r4, #0
	movs r1, #0x38
	movs r2, #7
	bl Text_InsertDrawString
	adds r0, r5, #0
	bl GetItemWeight
	adds r3, r0, #0
	adds r0, r4, #0
	movs r1, #0x80
	movs r2, #7
	bl Text_InsertDrawNumberOrBlank
	adds r4, #8
	adds r0, r5, #0
	bl GetItemMight
	adds r3, r0, #0
	adds r0, r4, #0
	movs r1, #0x20
	movs r2, #7
	bl Text_InsertDrawNumberOrBlank
	adds r0, r5, #0
	bl GetItemHit
	adds r3, r0, #0
	adds r0, r4, #0
	movs r1, #0x50
	movs r2, #7
	bl Text_InsertDrawNumberOrBlank
	adds r0, r5, #0
	bl GetItemCrit
	adds r3, r0, #0
	adds r0, r4, #0
	movs r1, #0x80
	movs r2, #7
	bl Text_InsertDrawNumberOrBlank
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08071214: .4byte 0x0203D424

	thumb_func_start func_fe6_08071218
func_fe6_08071218: @ 0x08071218
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, .L08071268 @ =0x0203D424
	ldr r3, .L0807126C @ =gUnk_083198BC
	adds r0, r4, #0
	movs r1, #0
	movs r2, #8
	bl Text_InsertDrawString
	adds r0, r5, #0
	bl GetItemRequiredExp
	bl GetWeaponLevelStringFromExp
	adds r3, r0, #0
	adds r0, r4, #0
	movs r1, #0xc
	movs r2, #7
	bl Text_InsertDrawString
	ldr r3, .L08071270 @ =gUnk_08319894
	adds r0, r4, #0
	movs r1, #0x24
	movs r2, #8
	bl Text_InsertDrawString
	adds r0, r5, #0
	bl GetItemRangeString
	adds r3, r0, #0
	adds r0, r4, #0
	movs r1, #0x38
	movs r2, #7
	bl Text_InsertDrawString
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
.L08071268: .4byte 0x0203D424
.L0807126C: .4byte gUnk_083198BC
.L08071270: .4byte gUnk_08319894

	thumb_func_start func_fe6_08071274
func_fe6_08071274: @ 0x08071274
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x5e
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt .L08071302
	adds r0, r4, #0
	adds r0, #0x60
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r0, [r4, #0x30]
	bl SetTextFont
	movs r6, #0
	adds r0, r4, #0
	adds r0, #0x62
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r7, r0, #0
	cmp r6, r1
	bge .L080712FC
	adds r5, r4, #0
	adds r5, #0x5c
.L080712AA:
	ldr r0, [r4, #0x2c]
	ldrb r2, [r0]
	adds r3, r0, #0
	cmp r2, #1
	beq .L080712CC
	cmp r2, #1
	bgt .L080712BE
	cmp r2, #0
	beq .L080712C4
	b .L080712DC
.L080712BE:
	cmp r2, #4
	beq .L080712D8
	b .L080712DC
.L080712C4:
	adds r0, r4, #0
	bl Proc_Break
	b .L080712FC
.L080712CC:
	adds r0, r3, #1
	str r0, [r4, #0x2c]
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	b .L080712F2
.L080712D8:
	adds r0, r3, #1
	b .L080712F0
.L080712DC:
	movs r0, #0
	ldrsh r1, [r5, r0]
	lsls r1, r1, #2
	adds r0, r4, #0
	adds r0, #0x34
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r3, #0
	bl Text_DrawCharacter
.L080712F0:
	str r0, [r4, #0x2c]
.L080712F2:
	adds r6, #1
	movs r1, #0
	ldrsh r0, [r7, r1]
	cmp r6, r0
	blt .L080712AA
.L080712FC:
	movs r0, #0
	bl SetTextFont
.L08071302:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08071308
func_fe6_08071308: @ 0x08071308
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x30]
	bl SetTextFont
	movs r6, #0
.L08071314:
	lsls r1, r6, #2
	adds r0, r4, #0
	adds r0, #0x34
	adds r0, r0, r1
	ldr r5, [r0]
	ldrb r1, [r5, #4]
	lsls r0, r1, #3
	ldr r1, [r4, #0x2c]
	bl GetStringTextCenteredPos
	adds r1, r0, #0
	adds r0, r5, #0
	bl Text_SetCursor
.L08071330:
	ldr r0, [r4, #0x2c]
	ldrb r1, [r0]
	cmp r1, #1
	beq .L08071350
	cmp r1, #1
	bgt .L08071342
	cmp r1, #0
	beq .L08071368
	b .L0807135C
.L08071342:
	cmp r1, #5
	bgt .L0807135C
	cmp r1, #4
	blt .L0807135C
	adds r0, #1
	str r0, [r4, #0x2c]
	b .L08071330
.L08071350:
	adds r0, #1
	str r0, [r4, #0x2c]
	adds r6, #1
	cmp r6, #5
	ble .L08071314
	b .L08071368
.L0807135C:
	ldr r1, [r4, #0x2c]
	adds r0, r5, #0
	bl Text_DrawCharacter
	str r0, [r4, #0x2c]
	b .L08071330
.L08071368:
	ldr r0, [r4, #0x30]
	bl SetTextFont
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08071374
func_fe6_08071374: @ 0x08071374
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #0x58]
	ldr r0, .L0807139C @ =0x0203D40C
	bl SetTextFont
	movs r0, #0
	bl SetTextFontGlyphs
	adds r0, r4, #0
	bl func_fe6_08070B30
	adds r1, r0, #0
	cmp r1, #1
	beq .L080713AE
	cmp r1, #1
	bgt .L080713A0
	cmp r1, #0
	beq .L080713A6
	b .L080713CA
	.align 2, 0
.L0807139C: .4byte 0x0203D40C
.L080713A0:
	cmp r1, #2
	beq .L080713BC
	b .L080713CA
.L080713A6:
	adds r0, r5, #0
	adds r0, #0x64
	strh r1, [r0]
	b .L080713CA
.L080713AE:
	adds r0, r4, #0
	bl func_fe6_08071120
	adds r1, r5, #0
	adds r1, #0x64
	movs r0, #2
	b .L080713C8
.L080713BC:
	adds r0, r4, #0
	bl func_fe6_08071218
	adds r1, r5, #0
	adds r1, #0x64
	movs r0, #1
.L080713C8:
	strh r0, [r1]
.L080713CA:
	movs r0, #0
	bl SetTextFont
	adds r0, r5, #0
	bl Proc_Break
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080713DC
func_fe6_080713DC: @ 0x080713DC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #0x58]
	ldr r0, .L0807140C @ =0x0203D40C
	bl SetTextFont
	adds r0, r4, #0
	bl func_fe6_08070B30
	cmp r0, #1
	bne .L080713F8
	adds r0, r4, #0
	bl func_fe6_08071198
.L080713F8:
	movs r0, #0
	bl SetTextFont
	adds r0, r5, #0
	bl Proc_Break
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0807140C: .4byte 0x0203D40C

	thumb_func_start func_fe6_08071410
func_fe6_08071410: @ 0x08071410
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	mov sl, r0
	ldr r5, .L080714B0 @ =0x0203D40C
	adds r0, r5, #0
	bl SetTextFont
	movs r0, #1
	bl SetTextFontGlyphs
	movs r0, #0x18
	adds r0, r0, r5
	mov sb, r0
	movs r1, #6
	bl Text_SetColor
	movs r1, #0x20
	adds r1, r1, r5
	mov r8, r1
	mov r0, r8
	movs r1, #6
	bl Text_SetColor
	adds r6, r5, #0
	adds r6, #0x28
	adds r0, r6, #0
	movs r1, #6
	bl Text_SetColor
	movs r0, #0
	bl SetTextFont
	ldr r4, .L080714B4 @ =gUnk_08677FD0
	adds r0, r4, #0
	bl Proc_EndEach
	adds r0, r4, #0
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x30]
	mov r0, sb
	str r0, [r4, #0x34]
	mov r1, r8
	str r1, [r4, #0x38]
	str r6, [r4, #0x3c]
	mov r0, sl
	adds r0, #0x64
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x5c
	movs r5, #0
	strh r1, [r0]
	mov r1, sl
	ldr r0, [r1, #0x5c]
	bl DecodeMsg
	str r0, [r4, #0x2c]
	adds r1, r4, #0
	adds r1, #0x62
	movs r3, #1
	strh r3, [r1]
	adds r0, r4, #0
	adds r0, #0x5e
	strh r5, [r0]
	ldr r0, .L080714B8 @ =gPlaySt
	ldrb r0, [r0, #0x1c]
	lsls r0, r0, #0x19
	lsrs r2, r0, #0x1e
	cmp r2, #1
	beq .L080714CE
	cmp r2, #1
	bgt .L080714BC
	cmp r2, #0
	beq .L080714C6
	b .L080714EA
	.align 2, 0
.L080714B0: .4byte 0x0203D40C
.L080714B4: .4byte gUnk_08677FD0
.L080714B8: .4byte gPlaySt
.L080714BC:
	cmp r2, #2
	beq .L080714D6
	cmp r2, #3
	beq .L080714E0
	b .L080714EA
.L080714C6:
	adds r1, r4, #0
	adds r1, #0x60
	movs r0, #2
	b .L080714E8
.L080714CE:
	adds r0, r4, #0
	adds r0, #0x60
	strh r2, [r0]
	b .L080714EA
.L080714D6:
	adds r0, r4, #0
	adds r0, #0x60
	strh r3, [r0]
	strh r2, [r1]
	b .L080714EA
.L080714E0:
	adds r0, r4, #0
	adds r0, #0x60
	strh r5, [r0]
	movs r0, #0x7f
.L080714E8:
	strh r0, [r1]
.L080714EA:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080714F8
func_fe6_080714F8: @ 0x080714F8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, .L08071510 @ =gUnk_08677FF8
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x58]
	str r5, [r0, #0x5c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08071510: .4byte gUnk_08677FF8

	thumb_func_start func_fe6_08071514
func_fe6_08071514: @ 0x08071514
	push {r4, lr}
	ldr r4, .L08071550 @ =0x0203D40C
	adds r0, r4, #0
	bl SetTextFont
	adds r0, r4, #0
	adds r0, #0x18
	bl SpriteText_DrawBackground
	adds r0, r4, #0
	adds r0, #0x20
	bl SpriteText_DrawBackground
	adds r4, #0x28
	adds r0, r4, #0
	bl SpriteText_DrawBackground
	ldr r0, .L08071554 @ =gUnk_08677FD0
	bl Proc_EndEach
	ldr r0, .L08071558 @ =gUnk_08677FF8
	bl Proc_EndEach
	movs r0, #0
	bl SetTextFont
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08071550: .4byte 0x0203D40C
.L08071554: .4byte gUnk_08677FD0
.L08071558: .4byte gUnk_08677FF8

	thumb_func_start func_fe6_0807155C
func_fe6_0807155C: @ 0x0807155C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #5
	bl UpdateHelpBoxDisplay
	adds r2, r4, #0
	adds r2, #0x48
	adds r4, #0x4a
	ldrh r3, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r5, #0
	ldrsh r0, [r4, r5]
	cmp r1, r0
	bge .L0807157E
	adds r0, r3, #1
	strh r0, [r2]
.L0807157E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08071584
func_fe6_08071584: @ 0x08071584
	push {r4, r5, lr}
	adds r4, r0, #0
	bl func_fe6_08071838
	ldr r0, [r4, #0x2c]
	ldrb r1, [r0, #0x10]
	ldrb r2, [r0, #0x11]
	adds r0, r4, #0
	bl func_fe6_08071830
	adds r5, r4, #0
	adds r5, #0x4a
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #3
	bl __divsi3
	strh r0, [r5]
	adds r4, #0x48
	strh r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080715B4
func_fe6_080715B4: @ 0x080715B4
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0
	bl UpdateHelpBoxDisplay
	adds r1, r4, #0
	adds r1, #0x48
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge .L080715D4
	adds r0, r4, #0
	bl Proc_Break
.L080715D4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080715DC
func_fe6_080715DC: @ 0x080715DC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080715F8 @ =0x0203D440
	movs r3, #0
	strb r4, [r0, #0x10]
	strb r1, [r0, #0x11]
	strh r2, [r0, #0x12]
	str r3, [r0, #0x14]
	str r3, [r0, #0x18]
	bl func_fe6_08071748
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080715F8: .4byte 0x0203D440

	thumb_func_start func_fe6_080715FC
func_fe6_080715FC: @ 0x080715FC
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	ldr r4, .L0807163C @ =gUnk_08678020
	adds r0, r4, #0
	bl Proc_Find
	adds r5, r0, #0
	cmp r5, #0
	bne .L08071644
	adds r0, r4, #0
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	ldr r0, .L08071640 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L0807162A
	movs r0, #0x70
	bl m4aSongNumStart
.L0807162A:
	ldrb r1, [r6, #0x10]
	ldrb r2, [r6, #0x11]
	adds r0, r5, #0
	bl func_fe6_08071830
	adds r0, r5, #0
	bl func_fe6_08071838
	b .L08071660
	.align 2, 0
.L0807163C: .4byte gUnk_08678020
.L08071640: .4byte gPlaySt
.L08071644:
	ldrh r0, [r5, #0x30]
	strh r0, [r5, #0x38]
	ldrh r0, [r5, #0x32]
	strh r0, [r5, #0x3a]
	adds r0, r5, #0
	adds r0, #0x44
	ldrh r1, [r0]
	subs r0, #4
	strh r1, [r0]
	adds r0, #6
	ldrh r0, [r0]
	adds r1, r5, #0
	adds r1, #0x42
	strh r0, [r1]
.L08071660:
	str r6, [r5, #0x2c]
	adds r1, r5, #0
	adds r1, #0x48
	movs r0, #0
	strh r0, [r1]
	adds r1, #2
	movs r0, #0xc
	strh r0, [r1]
	ldrh r0, [r6, #0x12]
	adds r4, r5, #0
	adds r4, #0x4c
	strh r0, [r4]
	movs r0, #1
	bl SetTextFontGlyphs
	ldrh r0, [r4]
	bl DecodeMsg
	add r2, sp, #4
	mov r1, sp
	bl GetStringTextBox
	movs r0, #0
	bl SetTextFontGlyphs
	ldr r1, [sp]
	ldr r2, [sp, #4]
	adds r0, r5, #0
	bl func_fe6_08071778
	ldrb r1, [r6, #0x10]
	ldrb r2, [r6, #0x11]
	adds r0, r5, #0
	bl func_fe6_080717B8
	bl func_fe6_08071514
	adds r0, r5, #0
	adds r0, #0x4e
	ldrh r0, [r0]
	ldrh r1, [r4]
	bl func_fe6_080714F8
	ldr r0, .L080716C4 @ =0x0203D45C
	str r6, [r0]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080716C4: .4byte 0x0203D45C

	thumb_func_start func_fe6_080716C8
func_fe6_080716C8: @ 0x080716C8
	push {lr}
	ldr r0, .L080716E8 @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L080716DA
	movs r0, #0x71
	bl m4aSongNumStart
.L080716DA:
	bl func_fe6_08071514
	ldr r0, .L080716EC @ =gUnk_08678020
	bl Proc_BreakEach
	pop {r0}
	bx r0
	.align 2, 0
.L080716E8: .4byte gPlaySt
.L080716EC: .4byte gUnk_08678020

	thumb_func_start func_fe6_080716F0
func_fe6_080716F0: @ 0x080716F0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x50
	movs r1, #0
	strh r1, [r0]
	ldr r0, [r4, #0x2c]
	ldr r1, [r0, #0x14]
	cmp r1, #0
	beq .L08071708
	adds r0, r4, #0
	bl _call_via_r1
.L08071708:
	ldr r0, [r4, #0x2c]
	bl func_fe6_080715FC
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08071714
func_fe6_08071714: @ 0x08071714
	push {lr}
	adds r2, r0, #0
	ldr r0, .L08071730 @ =gKeySt
	ldr r1, [r0]
	movs r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L0807172C
	adds r0, r2, #0
	bl Proc_Break
.L0807172C:
	pop {r0}
	bx r0
	.align 2, 0
.L08071730: .4byte gKeySt

	thumb_func_start func_fe6_08071734
func_fe6_08071734: @ 0x08071734
	push {r4, lr}
	adds r4, r0, #0
	bl func_fe6_080716C8
	adds r0, r4, #0
	bl Proc_End
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08071748
func_fe6_08071748: @ 0x08071748
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0807175C @ =gUnk_08678040
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0807175C: .4byte gUnk_08678040

	thumb_func_start func_fe6_08071760
func_fe6_08071760: @ 0x08071760
	push {lr}
	ldr r0, .L08071774 @ =gUnk_08678040
	bl Proc_Find
	cmp r0, #0
	beq .L0807176E
	movs r0, #1
.L0807176E:
	pop {r1}
	bx r1
	.align 2, 0
.L08071774: .4byte gUnk_08678040

	thumb_func_start func_fe6_08071778
func_fe6_08071778: @ 0x08071778
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r4, #0x1f
	movs r0, #0xe0
	ands r4, r0
	adds r0, r6, #0
	adds r0, #0x4e
	ldrh r0, [r0]
	bl func_fe6_08071848
	cmp r0, #1
	beq .L0807179A
	cmp r0, #2
	beq .L080717A0
	b .L080717A8
.L0807179A:
	movs r4, #0xa0
	adds r5, #0x20
	b .L080717A8
.L080717A0:
	cmp r4, #0x5f
	bgt .L080717A6
	movs r4, #0x60
.L080717A6:
	adds r5, #0x10
.L080717A8:
	adds r0, r6, #0
	adds r0, #0x44
	strh r4, [r0]
	adds r0, #2
	strh r5, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080717B8
func_fe6_080717B8: @ 0x080717B8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r4, r1, #0
	mov r8, r2
	adds r0, #0x44
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r6, r0, #0
	adds r6, #0x10
	adds r0, r5, #0
	adds r0, #0x46
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r7, r0, #0
	adds r7, #0x10
	adds r0, r6, #0
	movs r1, #6
	bl __divsi3
	adds r0, #0x10
	subs r4, r4, r0
	strh r4, [r5, #0x3c]
	lsls r4, r4, #0x10
	cmp r4, #0
	bge .L080717F2
	movs r0, #0
	strh r0, [r5, #0x3c]
.L080717F2:
	movs r1, #0x3c
	ldrsh r0, [r5, r1]
	adds r0, r0, r6
	cmp r0, #0xf0
	ble .L08071802
	movs r0, #0xf0
	subs r0, r0, r6
	strh r0, [r5, #0x3c]
.L08071802:
	mov r0, r8
	adds r0, #0x10
	strh r0, [r5, #0x3e]
	movs r1, #0x3e
	ldrsh r0, [r5, r1]
	adds r0, r0, r7
	cmp r0, #0xa0
	ble .L08071818
	mov r1, r8
	subs r0, r1, r7
	strh r0, [r5, #0x3e]
.L08071818:
	ldrh r0, [r5, #0x3c]
	adds r0, #8
	strh r0, [r5, #0x3c]
	ldrh r0, [r5, #0x3e]
	adds r0, #8
	strh r0, [r5, #0x3e]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08071830
func_fe6_08071830: @ 0x08071830
	strh r1, [r0, #0x38]
	strh r2, [r0, #0x3a]
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_08071838
func_fe6_08071838: @ 0x08071838
	adds r2, r0, #0
	adds r2, #0x40
	movs r1, #0x20
	strh r1, [r2]
	adds r0, #0x42
	movs r1, #0x10
	strh r1, [r0]
	bx lr

	thumb_func_start func_fe6_08071848
func_fe6_08071848: @ 0x08071848
	push {r4, lr}
	adds r4, r0, #0
	bl GetItemAttributes
	movs r1, #0x80
	lsls r1, r1, #3
	ands r1, r0
	cmp r1, #0
	bne .L0807187A
	adds r0, r4, #0
	bl GetItemAttributes
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq .L0807186C
	movs r0, #1
	b .L08071880
.L0807186C:
	adds r0, r4, #0
	bl GetItemAttributes
	movs r1, #4
	ands r1, r0
	cmp r1, #0
	bne .L0807187E
.L0807187A:
	movs r0, #0
	b .L08071880
.L0807187E:
	movs r0, #2
.L08071880:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08071888
func_fe6_08071888: @ 0x08071888
	push {lr}
	adds r2, r0, #0
	ldr r0, .L080718A4 @ =gKeySt
	ldr r1, [r0]
	movs r0, #1
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L080718A0
	adds r0, r2, #0
	bl Proc_Break
.L080718A0:
	pop {r0}
	bx r0
	.align 2, 0
.L080718A4: .4byte gKeySt

	thumb_func_start func_fe6_080718A8
func_fe6_080718A8: @ 0x080718A8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0
	bl func_fe6_08070E70
	bl GetUiHandPrevX
	adds r4, r0, #0
	bl GetUiHandPrevY
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl func_fe6_080715DC
	ldr r0, .L080718DC @ =gUnk_08678070
	adds r1, r6, #0
	bl SpawnProcLocking
	movs r0, #1
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
.L080718DC: .4byte gUnk_08678070

	thumb_func_start func_fe6_080718E0
func_fe6_080718E0: @ 0x080718E0
	push {lr}
	ldr r0, .L080718F0 @ =gUnk_08678080
	bl Proc_Find
	cmp r0, #0
	bne .L080718F4
	movs r0, #0
	b .L080718F6
	.align 2, 0
.L080718F0: .4byte gUnk_08678080
.L080718F4:
	movs r0, #1
.L080718F6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_080718FC
func_fe6_080718FC: @ 0x080718FC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	cmp r7, #0
	bne .L08071908
	ldr r7, .L08071968 @ =0x06013000
.L08071908:
	cmp r5, #0
	bge .L0807190E
	movs r5, #5
.L0807190E:
	movs r4, #0xf
	adds r0, r4, #0
	ands r0, r5
	adds r5, r0, #0
	adds r5, #0x10
	ldr r0, .L0807196C @ =gUnk_08308A78
	adds r1, r7, #0
	bl Decompress
	ldr r6, .L08071970 @ =0x0203D460
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl InitSpriteTextFont
	adds r0, r6, #0
	adds r0, #0x18
	bl InitSpriteText
	adds r0, r6, #0
	adds r0, #0x20
	bl InitSpriteText
	adds r0, r6, #0
	adds r0, #0x28
	bl InitSpriteText
	movs r0, #0
	bl SetTextFont
	ldr r0, .L08071974 @ =Pal_08100A48
	lsls r1, r5, #5
	movs r2, #0x20
	bl ApplyPaletteExt
	lsls r0, r7, #0x11
	lsrs r0, r0, #0x16
	ands r5, r4
	lsls r1, r5, #0xc
	adds r0, r0, r1
	strh r0, [r6, #0x30]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08071968: .4byte 0x06013000
.L0807196C: .4byte gUnk_08308A78
.L08071970: .4byte 0x0203D460
.L08071974: .4byte Pal_08100A48

	thumb_func_start func_fe6_08071978
func_fe6_08071978: @ 0x08071978
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r0, #0x46
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r2, r0, #0
	adds r2, #0x10
	adds r1, r3, #0
	adds r1, #0x44
	movs r6, #0
	ldrsh r0, [r1, r6]
	cmp r0, #0xbf
	ble .L0807199A
	movs r0, #0xc0
	strh r0, [r1]
.L0807199A:
	movs r6, #0
	ldrsh r0, [r1, r6]
	adds r1, r0, #0
	adds r1, #0x10
	strh r4, [r3, #0x3c]
	movs r4, #0x3c
	ldrsh r0, [r3, r4]
	adds r0, r0, r1
	cmp r0, #0xf0
	ble .L080719B4
	movs r0, #0xf0
	subs r0, r0, r1
	strh r0, [r3, #0x3c]
.L080719B4:
	adds r0, r5, #0
	adds r0, #8
	strh r0, [r3, #0x3e]
	movs r6, #0x3e
	ldrsh r0, [r3, r6]
	adds r0, r0, r2
	cmp r0, #0xa0
	ble .L080719CA
	subs r0, r5, r2
	subs r0, #8
	strh r0, [r3, #0x3e]
.L080719CA:
	ldrh r0, [r3, #0x3c]
	adds r0, #8
	strh r0, [r3, #0x3c]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080719D8
func_fe6_080719D8: @ 0x080719D8
	adds r1, #0x27
	movs r3, #0xe0
	ands r1, r3
	adds r3, r0, #0
	adds r3, #0x44
	strh r1, [r3]
	adds r0, #0x46
	strh r2, [r0]
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_080719EC
func_fe6_080719EC: @ 0x080719EC
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x38
	ldrb r0, [r1]
	cmp r0, #0xff
	bne .L08071A06
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0
	bl func_fe6_080718FC
	b .L08071A0E
.L08071A06:
	ldrb r1, [r1]
	movs r0, #0
	bl func_fe6_080718FC
.L08071A0E:
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	ldr r2, [r4, #0x34]
	bl func_fe6_08071D04
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08071A20
func_fe6_08071A20: @ 0x08071A20
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_08071A24
func_fe6_08071A24: @ 0x08071A24
	push {lr}
	movs r0, #0
	bl SetTextFontGlyphs
	bl func_fe6_08071B6C
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08071A34
func_fe6_08071A34: @ 0x08071A34
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	adds r5, r1, #0
	movs r0, #0x38
	ldrsh r1, [r7, r0]
	movs r3, #0x3c
	ldrsh r2, [r7, r3]
	adds r4, r7, #0
	adds r4, #0x48
	movs r0, #0
	ldrsh r6, [r4, r0]
	mov r8, r6
	movs r3, #0x4a
	adds r3, r3, r7
	mov sl, r3
	movs r6, #0
	ldrsh r0, [r3, r6]
	str r0, [sp]
	adds r0, r5, #0
	mov r3, r8
	bl Interpolate
	mov sb, r0
	movs r0, #0x3a
	ldrsh r1, [r7, r0]
	movs r3, #0x3e
	ldrsh r2, [r7, r3]
	movs r0, #0
	ldrsh r6, [r4, r0]
	mov r8, r6
	mov r3, sl
	movs r6, #0
	ldrsh r0, [r3, r6]
	str r0, [sp]
	adds r0, r5, #0
	mov r3, r8
	bl Interpolate
	mov r8, r0
	adds r0, r7, #0
	adds r0, #0x40
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, #4
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r0, #0
	ldrsh r6, [r4, r0]
	mov ip, r6
	mov r3, sl
	movs r6, #0
	ldrsh r0, [r3, r6]
	str r0, [sp]
	adds r0, r5, #0
	mov r3, ip
	bl Interpolate
	str r0, [sp, #4]
	adds r0, r7, #0
	adds r0, #0x42
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, #4
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r6, #0
	ldrsh r3, [r4, r6]
	mov r4, sl
	movs r6, #0
	ldrsh r0, [r4, r6]
	str r0, [sp]
	adds r0, r5, #0
	bl Interpolate
	adds r3, r0, #0
	mov r0, sb
	strh r0, [r7, #0x30]
	mov r2, r8
	strh r2, [r7, #0x32]
	mov r0, sb
	mov r1, r8
	ldr r2, [sp, #4]
	bl func_fe6_08071D94
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08071AF8
func_fe6_08071AF8: @ 0x08071AF8
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #5
	bl func_fe6_08071A34
	adds r2, r4, #0
	adds r2, #0x48
	adds r4, #0x4a
	ldrh r3, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r5, #0
	ldrsh r0, [r4, r5]
	cmp r1, r0
	bge .L08071B1A
	adds r0, r3, #1
	strh r0, [r2]
.L08071B1A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08071B20
func_fe6_08071B20: @ 0x08071B20
	push {r4, r5, lr}
	adds r4, r0, #0
	bl ResetHelpBoxInitSize
	adds r5, r4, #0
	adds r5, #0x4a
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #3
	bl __divsi3
	strh r0, [r5]
	adds r4, #0x48
	strh r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08071B44
func_fe6_08071B44: @ 0x08071B44
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0
	bl func_fe6_08071A34
	adds r1, r4, #0
	adds r1, #0x48
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge .L08071B64
	adds r0, r4, #0
	bl Proc_Break
.L08071B64:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08071B6C
func_fe6_08071B6C: @ 0x08071B6C
	push {lr}
	bl func_fe6_080721D0
	ldr r0, .L08071B7C @ =gUnk_086780C8
	bl Proc_BreakEach
	pop {r0}
	bx r0
	.align 2, 0
.L08071B7C: .4byte gUnk_086780C8

	thumb_func_start func_fe6_08071B80
func_fe6_08071B80: @ 0x08071B80
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	cmp r3, #0
	bne .L08071B9C
	ldr r0, .L08071B98 @ =gUnk_08678080
	movs r1, #3
	bl SpawnProc
	b .L08071BA4
	.align 2, 0
.L08071B98: .4byte gUnk_08678080
.L08071B9C:
	ldr r0, .L08071BBC @ =gUnk_08678080
	adds r1, r3, #0
	bl SpawnProcLocking
.L08071BA4:
	adds r3, r0, #0
	str r4, [r3, #0x2c]
	str r5, [r3, #0x30]
	str r6, [r3, #0x34]
	adds r1, r3, #0
	adds r1, #0x38
	movs r0, #0xff
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08071BBC: .4byte gUnk_08678080

	thumb_func_start func_fe6_08071BC0
func_fe6_08071BC0: @ 0x08071BC0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	ldr r0, [sp, #0x14]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r3, #0
	bne .L08071BE0
	ldr r0, .L08071BDC @ =gUnk_08678080
	movs r1, #3
	bl SpawnProc
	b .L08071BE8
	.align 2, 0
.L08071BDC: .4byte gUnk_08678080
.L08071BE0:
	ldr r0, .L08071BFC @ =gUnk_08678080
	adds r1, r3, #0
	bl SpawnProcLocking
.L08071BE8:
	adds r3, r0, #0
	str r5, [r3, #0x2c]
	str r6, [r3, #0x30]
	str r7, [r3, #0x34]
	adds r0, r3, #0
	adds r0, #0x38
	strb r4, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08071BFC: .4byte gUnk_08678080

	thumb_func_start func_fe6_08071C00
func_fe6_08071C00: @ 0x08071C00
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r3, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	movs r7, #0
	movs r6, #0x10
	str r7, [r4]
	str r7, [r5]
.L08071C12:
	ldrb r0, [r3]
	cmp r0, #4
	bhi .L08071C74
	lsls r0, r0, #2
	ldr r1, .L08071C24 @ =.L08071C28
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08071C24: .4byte .L08071C28
.L08071C28: @ jump table
	.4byte .L08071C62 @ case 0
	.4byte .L08071C3C @ case 1
	.4byte .L08071C4C @ case 2
	.4byte .L08071C4C @ case 3
	.4byte .L08071C48 @ case 4
.L08071C3C:
	adds r6, #0x10
	ldr r0, [r4]
	cmp r0, r7
	bge .L08071C46
	str r7, [r4]
.L08071C46:
	movs r7, #0
.L08071C48:
	adds r3, #1
	b .L08071C12
.L08071C4C:
	ldr r0, [r4]
	cmp r0, r7
	bge .L08071C54
	str r7, [r4]
.L08071C54:
	movs r7, #0
	ldr r0, [r5]
	cmp r0, r6
	bge .L08071C5E
	str r6, [r5]
.L08071C5E:
	movs r6, #0
	b .L08071C48
.L08071C62:
	ldr r0, [r4]
	cmp r0, r7
	bge .L08071C6A
	str r7, [r4]
.L08071C6A:
	ldr r0, [r5]
	cmp r0, r6
	bge .L08071C84
	str r6, [r5]
	b .L08071C84
.L08071C74:
	adds r0, r3, #0
	mov r1, sp
	bl GetCharTextLen
	adds r3, r0, #0
	ldr r0, [sp]
	adds r7, r7, r0
	b .L08071C12
.L08071C84:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08071C8C
func_fe6_08071C8C: @ 0x08071C8C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r1, #0
	mov r8, r2
	movs r6, #0
	movs r5, #0
	adds r4, r0, #0
	strb r5, [r7]
	strb r5, [r2]
	movs r0, #1
	bl SetTextFontGlyphs
.L08071CA8:
	ldrb r0, [r4]
	cmp r0, #4
	bhi .L08071CDC
	lsls r0, r0, #2
	ldr r1, .L08071CB8 @ =.L08071CBC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08071CB8: .4byte .L08071CBC
.L08071CBC: @ jump table
	.4byte .L08071CEC @ case 0
	.4byte .L08071CD4 @ case 1
	.4byte .L08071CEC @ case 2
	.4byte .L08071CEC @ case 3
	.4byte .L08071CD0 @ case 4
.L08071CD0:
	adds r4, #1
	b .L08071CA8
.L08071CD4:
	adds r4, #1
	adds r5, #0x10
	movs r6, #0
	b .L08071CA8
.L08071CDC:
	adds r0, r4, #0
	mov r1, sp
	bl GetCharTextLen
	adds r4, r0, #0
	ldr r0, [sp]
	adds r6, r6, r0
	b .L08071CA8
.L08071CEC:
	adds r0, r6, #2
	strb r0, [r7]
	adds r0, r5, #0
	adds r0, #8
	mov r1, r8
	strb r0, [r1]
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08071D04
func_fe6_08071D04: @ 0x08071D04
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #8
	mov r8, r0
	mov sb, r1
	adds r6, r2, #0
	ldr r0, .L08071D90 @ =gUnk_086780C8
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	mov r1, r8
	mov r2, sb
	bl SetHelpBoxInitPosition
	adds r0, r4, #0
	bl ResetHelpBoxInitSize
	movs r1, #0
	str r1, [r4, #0x2c]
	adds r0, r4, #0
	adds r0, #0x48
	strh r1, [r0]
	adds r2, r4, #0
	adds r2, #0x4a
	movs r0, #0xc
	strh r0, [r2]
	adds r0, r4, #0
	adds r0, #0x4e
	strh r1, [r0]
	adds r5, r4, #0
	adds r5, #0x4c
	strh r6, [r5]
	movs r0, #1
	bl SetTextFontGlyphs
	ldrh r0, [r5]
	bl DecodeMsg
	add r2, sp, #4
	mov r1, sp
	bl func_fe6_08071C00
	movs r0, #0
	bl SetTextFontGlyphs
	ldr r1, [sp]
	ldr r2, [sp, #4]
	adds r0, r4, #0
	bl func_fe6_080719D8
	adds r0, r4, #0
	mov r1, r8
	mov r2, sb
	bl func_fe6_08071978
	bl func_fe6_080721D0
	ldrh r0, [r5]
	bl func_fe6_080721B8
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08071D90: .4byte gUnk_086780C8

	thumb_func_start func_fe6_08071D94
func_fe6_08071D94: @ 0x08071D94
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov sb, r0
	mov sl, r1
	adds r7, r2, #0
	mov r8, r3
	cmp r7, #0x1f
	bgt .L08071DAE
	movs r7, #0x20
.L08071DAE:
	cmp r7, #0xc0
	ble .L08071DB4
	movs r7, #0xc0
.L08071DB4:
	mov r0, r8
	cmp r0, #0xf
	bgt .L08071DBE
	movs r1, #0x10
	mov r8, r1
.L08071DBE:
	mov r3, r8
	cmp r3, #0x30
	ble .L08071DC8
	movs r0, #0x30
	mov r8, r0
.L08071DC8:
	adds r0, r7, #0
	adds r0, #0x1f
	cmp r0, #0
	bge .L08071DD2
	adds r0, #0x1f
.L08071DD2:
	asrs r0, r0, #5
	mov r1, r8
	adds r1, #0xf
	cmp r1, #0
	bge .L08071DDE
	adds r1, #0xf
.L08071DDE:
	asrs r1, r1, #4
	str r1, [sp, #4]
	subs r6, r0, #1
	str r6, [sp, #8]
	mov r1, sl
	subs r1, #8
	str r1, [sp, #0x18]
	mov r3, sl
	add r3, r8
	str r3, [sp, #0x10]
	mov r0, sb
	subs r0, #8
	str r0, [sp, #0x14]
	mov r1, sb
	adds r1, r1, r7
	str r1, [sp, #0xc]
	cmp r6, #0
	blt .L08071E4A
.L08071E02:
	ldr r5, [sp, #4]
	subs r4, r6, #1
	cmp r5, #0
	blt .L08071E44
.L08071E0A:
	adds r0, r6, #1
	lsls r1, r0, #5
	cmp r1, r7
	ble .L08071E14
	adds r1, r7, #0
.L08071E14:
	subs r1, #0x20
	adds r0, r5, #1
	lsls r0, r0, #4
	cmp r0, r8
	ble .L08071E20
	mov r0, r8
.L08071E20:
	subs r0, #0x10
	add r1, sb
	mov r3, sl
	adds r2, r3, r0
	ldr r3, .L08071F28 @ =0x0203D460
	lsls r0, r6, #2
	ldrh r3, [r3, #0x30]
	adds r0, r3, r0
	lsls r3, r5, #6
	adds r0, r0, r3
	str r0, [sp]
	movs r0, #2
	ldr r3, .L08071F2C @ =Sprite_32x16
	bl PutSprite
	subs r5, #1
	cmp r5, #0
	bge .L08071E0A
.L08071E44:
	adds r6, r4, #0
	cmp r6, #0
	bge .L08071E02
.L08071E4A:
	ldr r6, [sp, #8]
	cmp r6, #0
	blt .L08071E8C
	ldr r5, .L08071F28 @ =0x0203D460
.L08071E52:
	adds r0, r6, #1
	lsls r1, r0, #5
	cmp r1, r7
	ble .L08071E5C
	adds r1, r7, #0
.L08071E5C:
	subs r1, #0x20
	mov r0, sb
	adds r4, r0, r1
	ldrh r0, [r5, #0x30]
	adds r0, #0x1b
	str r0, [sp]
	movs r0, #2
	adds r1, r4, #0
	ldr r2, [sp, #0x18]
	ldr r3, .L08071F30 @ =Sprite_32x8
	bl PutSprite
	ldrh r0, [r5, #0x30]
	adds r0, #0x1b
	str r0, [sp]
	movs r0, #2
	adds r1, r4, #0
	ldr r2, [sp, #0x10]
	ldr r3, .L08071F34 @ =Sprite_32x8_VFlipped
	bl PutSprite
	subs r6, #1
	cmp r6, #0
	bge .L08071E52
.L08071E8C:
	ldr r5, [sp, #4]
	cmp r5, #0
	blt .L08071ECE
	ldr r6, .L08071F28 @ =0x0203D460
.L08071E94:
	adds r0, r5, #1
	lsls r0, r0, #4
	cmp r0, r8
	ble .L08071E9E
	mov r0, r8
.L08071E9E:
	subs r0, #0x10
	mov r1, sl
	adds r4, r1, r0
	ldrh r0, [r6, #0x30]
	adds r0, #0x1f
	str r0, [sp]
	movs r0, #2
	ldr r1, [sp, #0x14]
	adds r2, r4, #0
	ldr r3, .L08071F38 @ =Sprite_8x16
	bl PutSprite
	ldrh r0, [r6, #0x30]
	adds r0, #0x1f
	str r0, [sp]
	movs r0, #2
	ldr r1, [sp, #0xc]
	adds r2, r4, #0
	ldr r3, .L08071F3C @ =Sprite_8x16_HFlipped
	bl PutSprite
	subs r5, #1
	cmp r5, #0
	bge .L08071E94
.L08071ECE:
	ldr r3, .L08071F40 @ =Sprite_8x8
	ldr r4, .L08071F28 @ =0x0203D460
	ldrh r0, [r4, #0x30]
	adds r0, #0x3e
	str r0, [sp]
	movs r0, #2
	ldr r1, [sp, #0x14]
	ldr r2, [sp, #0x18]
	bl PutSprite
	ldr r3, .L08071F44 @ =Sprite_8x8_HFlipped
	ldrh r0, [r4, #0x30]
	adds r0, #0x3e
	str r0, [sp]
	movs r0, #2
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #0x18]
	bl PutSprite
	ldr r3, .L08071F48 @ =Sprite_8x8_VFlipped
	ldrh r0, [r4, #0x30]
	adds r0, #0x3e
	str r0, [sp]
	movs r0, #2
	ldr r1, [sp, #0x14]
	ldr r2, [sp, #0x10]
	bl PutSprite
	ldr r3, .L08071F4C @ =Sprite_8x8_HFlipped_VFlipped
	ldrh r0, [r4, #0x30]
	adds r0, #0x3e
	str r0, [sp]
	movs r0, #2
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #0x10]
	bl PutSprite
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08071F28: .4byte 0x0203D460
.L08071F2C: .4byte Sprite_32x16
.L08071F30: .4byte Sprite_32x8
.L08071F34: .4byte Sprite_32x8_VFlipped
.L08071F38: .4byte Sprite_8x16
.L08071F3C: .4byte Sprite_8x16_HFlipped
.L08071F40: .4byte Sprite_8x8
.L08071F44: .4byte Sprite_8x8_HFlipped
.L08071F48: .4byte Sprite_8x8_VFlipped
.L08071F4C: .4byte Sprite_8x8_HFlipped_VFlipped

	thumb_func_start func_fe6_08071F50
func_fe6_08071F50: @ 0x08071F50
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x2c]
	adds r1, r2, #0
	adds r1, #0x56
	adds r2, #0x57
	bl func_fe6_08071C8C
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08071F64
func_fe6_08071F64: @ 0x08071F64
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x58
	ldrb r0, [r5]
	cmp r0, #1
	bne .L08071FA4
	ldr r4, .L08071FA0 @ =0x0203D460
	adds r0, r4, #0
	bl SetTextFont
	adds r0, r4, #0
	adds r0, #0x18
	bl SpriteText_DrawBackground
	adds r0, r4, #0
	adds r0, #0x20
	bl SpriteText_DrawBackground
	adds r4, #0x28
	adds r0, r4, #0
	bl SpriteText_DrawBackground
	movs r0, #0
	bl SetTextFont
	movs r0, #0
	strb r0, [r5]
	b .L080720D4
	.align 2, 0
.L08071FA0: .4byte 0x0203D460
.L08071FA4:
	adds r0, r6, #0
	adds r0, #0x52
	movs r1, #0
	ldrsh r7, [r0, r1]
	ldr r0, .L08071FC0 @ =gKeySt
	ldr r1, [r0]
	movs r0, #0xf3
	ldrh r1, [r1, #8]
	ands r0, r1
	cmp r0, #0
	beq .L08071FC4
	movs r7, #0x80
	b .L08071FDE
	.align 2, 0
.L08071FC0: .4byte gKeySt
.L08071FC4:
	adds r1, r6, #0
	adds r1, #0x4e
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble .L08071FD6
	b .L080720D4
.L08071FD6:
	adds r0, r6, #0
	adds r0, #0x50
	ldrh r0, [r0]
	strh r0, [r1]
.L08071FDE:
	ldr r0, [r6, #0x30]
	bl SetTextFont
	movs r5, #0
	cmp r5, r7
	bge .L080720CE
.L08071FEA:
	ldr r2, [r6, #0x2c]
	ldrb r0, [r2]
	adds r3, r2, #0
	cmp r0, #4
	bhi .L0807208C
	lsls r0, r0, #2
	ldr r1, .L08072000 @ =.L08072004
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08072000: .4byte .L08072004
.L08072004: @ jump table
	.4byte .L08072018 @ case 0
	.4byte .L08072020 @ case 1
	.4byte .L08072036 @ case 2
	.4byte .L08072036 @ case 3
	.4byte .L08072030 @ case 4
.L08072018:
	adds r0, r6, #0
	bl Proc_Break
	b .L080720CE
.L08072020:
	adds r0, r3, #1
	str r0, [r6, #0x2c]
	adds r1, r6, #0
	adds r1, #0x4c
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b .L080720C8
.L08072030:
	adds r0, r3, #1
	str r0, [r6, #0x2c]
	b .L080720C8
.L08072036:
	adds r1, r6, #0
	adds r1, #0x4c
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r6, #0x2c]
	adds r0, #1
	str r0, [r6, #0x2c]
	adds r1, #0xc
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r6, #0x2c]
	ldrb r2, [r0]
	cmp r2, #1
	bne .L08072056
	adds r0, #1
	str r0, [r6, #0x2c]
.L08072056:
	ldr r0, .L08072088 @ =gUnk_086780C8
	bl Proc_Find
	movs r3, #0x3c
	ldrsh r1, [r0, r3]
	adds r5, r6, #0
	adds r5, #0x56
	ldrb r2, [r5]
	adds r1, r2, r1
	movs r3, #0x3e
	ldrsh r2, [r0, r3]
	adds r4, r6, #0
	adds r4, #0x57
	ldrb r0, [r4]
	adds r2, r0, r2
	adds r0, r6, #0
	bl StartTalkWaitForInput
	ldr r0, [r6, #0x2c]
	adds r1, r5, #0
	adds r2, r4, #0
	bl func_fe6_08071C8C
	b .L080720CE
	.align 2, 0
.L08072088: .4byte gUnk_086780C8
.L0807208C:
	adds r0, r6, #0
	adds r0, #0x4c
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r1, r1, #2
	subs r0, #0x18
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r2, #0
	bl Text_DrawCharacter
	str r0, [r6, #0x2c]
	bl GetTextPrintDelay
	adds r4, r0, #0
	cmp r4, #1
	bne .L080720B8
	bl GetGameTime
	ands r0, r4
	cmp r0, #0
	beq .L080720C8
.L080720B8:
	ldr r0, .L080720DC @ =gPlaySt
	ldrb r0, [r0, #0x1d]
	lsls r0, r0, #0x1e
	cmp r0, #0
	blt .L080720C8
	movs r0, #0x6e
	bl m4aSongNumStart
.L080720C8:
	adds r5, #1
	cmp r5, r7
	blt .L08071FEA
.L080720CE:
	movs r0, #0
	bl SetTextFont
.L080720D4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080720DC: .4byte gPlaySt

	thumb_func_start func_fe6_080720E0
func_fe6_080720E0: @ 0x080720E0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080720FC @ =gUnk_08678080
	bl Proc_Find
	movs r1, #0
	bl Proc_Goto
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080720FC: .4byte gUnk_08678080

	thumb_func_start func_fe6_08072100
func_fe6_08072100: @ 0x08072100
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	mov sl, r0
	ldr r5, .L080721B0 @ =0x0203D460
	adds r0, r5, #0
	bl SetTextFont
	movs r0, #0
	bl SetTextFontGlyphs
	movs r0, #1
	bl SetTextFontGlyphs
	movs r0, #0x18
	adds r0, r0, r5
	mov sb, r0
	movs r1, #6
	bl Text_SetColor
	movs r1, #0x20
	adds r1, r1, r5
	mov r8, r1
	mov r0, r8
	movs r1, #6
	bl Text_SetColor
	adds r6, r5, #0
	adds r6, #0x28
	adds r0, r6, #0
	movs r1, #6
	bl Text_SetColor
	movs r0, #0
	bl SetTextFont
	ldr r4, .L080721B4 @ =gUnk_086780E8
	adds r0, r4, #0
	bl Proc_EndEach
	adds r0, r4, #0
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x30]
	mov r0, sb
	str r0, [r4, #0x34]
	mov r1, r8
	str r1, [r4, #0x38]
	str r6, [r4, #0x3c]
	adds r0, r4, #0
	adds r0, #0x4c
	movs r5, #0
	strh r5, [r0]
	mov r1, sl
	ldr r0, [r1, #0x5c]
	bl DecodeMsg
	str r0, [r4, #0x2c]
	bl GetTextPrintDelay
	adds r1, r4, #0
	adds r1, #0x50
	strh r0, [r1]
	lsls r0, r0, #0x10
	movs r1, #0x80
	cmp r0, #0
	beq .L08072190
	movs r1, #1
.L08072190:
	adds r0, r4, #0
	adds r0, #0x52
	strh r1, [r0]
	subs r0, #4
	strh r5, [r0]
	adds r1, r4, #0
	adds r1, #0x58
	movs r0, #0
	strb r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080721B0: .4byte 0x0203D460
.L080721B4: .4byte gUnk_086780E8

	thumb_func_start func_fe6_080721B8
func_fe6_080721B8: @ 0x080721B8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080721CC @ =gUnk_08678110
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080721CC: .4byte gUnk_08678110

	thumb_func_start func_fe6_080721D0
func_fe6_080721D0: @ 0x080721D0
	push {r4, lr}
	ldr r4, .L0807220C @ =0x0203D460
	adds r0, r4, #0
	bl SetTextFont
	adds r0, r4, #0
	adds r0, #0x18
	bl SpriteText_DrawBackground
	adds r0, r4, #0
	adds r0, #0x20
	bl SpriteText_DrawBackground
	adds r4, #0x28
	adds r0, r4, #0
	bl SpriteText_DrawBackground
	ldr r0, .L08072210 @ =gUnk_086780E8
	bl Proc_EndEach
	ldr r0, .L08072214 @ =gUnk_08678110
	bl Proc_EndEach
	movs r0, #0
	bl SetTextFont
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0807220C: .4byte 0x0203D460
.L08072210: .4byte gUnk_086780E8
.L08072214: .4byte gUnk_08678110
