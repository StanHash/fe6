	.include "macro.inc"
	.syntax unified

	.section .data

	.global ProcScr_EkrTogiInitPROC
ProcScr_EkrTogiInitPROC: @ 085CBE20
	.incbin "fe6-base.gba", 0x5CBE20, (0x5CBE50 - 0x5CBE20) @ length: 0030

	.global gUnk_085CBE50
gUnk_085CBE50: @ 085CBE50
	.incbin "fe6-base.gba", 0x5CBE50, (0x5CBE78 - 0x5CBE50) @ length: 0028

	.global gUnk_085CBE78
gUnk_085CBE78: @ 085CBE78
	.incbin "fe6-base.gba", 0x5CBE78, (0x5CBE90 - 0x5CBE78) @ length: 0018

	.global Pals_ArenaBattleBg
Pals_ArenaBattleBg: @ 085CBE90
	.incbin "fe6-base.gba", 0x5CBE90, (0x5CCC40 - 0x5CBE90) @ length: 0DB0

	.section .text
	thumb_func_start SetBanimArenaFlag
SetBanimArenaFlag: @ 0x0804C4F4
	ldr r1, .L0804C4FC @ =0x0203CDD4
	str r0, [r1]
	bx lr
	.align 2, 0
.L0804C4FC: .4byte 0x0203CDD4

	thumb_func_start GetBattleAnimArenaFlag
GetBattleAnimArenaFlag: @ 0x0804C500
	ldr r0, .L0804C508 @ =0x0203CDD4
	ldr r0, [r0]
	bx lr
	.align 2, 0
.L0804C508: .4byte 0x0203CDD4

	thumb_func_start func_fe6_0804C50C
func_fe6_0804C50C: @ 0x0804C50C
	push {r4, lr}
	sub sp, #0x10
	asrs r4, r0, #3
	movs r1, #7
	ands r1, r0
	movs r0, #3
	movs r2, #0
	bl SetBgOffset
	lsls r4, r4, #1
	ldr r0, .L0804C54C @ =gUnk_Banim_0201D424
	adds r4, r4, r0
	ldr r2, .L0804C550 @ =gBg3Tm
	movs r0, #0x20
	str r0, [sp]
	movs r0, #0x16
	str r0, [sp, #4]
	subs r0, #0x17
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x42
	movs r3, #0x20
	bl EfxTmCpyExt
	movs r0, #8
	bl EnableBgSync
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804C54C: .4byte gUnk_Banim_0201D424
.L0804C550: .4byte gBg3Tm

	thumb_func_start PlayDeathSoundForArena
PlayDeathSoundForArena: @ 0x0804C554
	push {lr}
	bl GetBattleAnimArenaFlag
	cmp r0, #0
	beq .L0804C568
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x8f
	bl EfxPlaySE
.L0804C568:
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0804C56C
func_fe6_0804C56C: @ 0x0804C56C
	push {lr}
	bl GetBattleAnimArenaFlag
	cmp r0, #0
	beq .L0804C57C
	movs r0, #0x8e
	bl DoM4aSongNumStop
.L0804C57C:
	pop {r0}
	bx r0

	thumb_func_start BeginAnimsOnBattle_Arena
BeginAnimsOnBattle_Arena: @ 0x0804C580
	push {lr}
	bl NewEkrBattleDeamon
	bl BasInit
	bl GetBanimInitPosReal
	ldr r1, .L0804C5A0 @ =gEkrInitPosReal
	str r0, [r1]
	bl NewEkrTogiInitPROC
	movs r0, #0
	bl SetOnHBlankA
	pop {r0}
	bx r0
	.align 2, 0
.L0804C5A0: .4byte gEkrInitPosReal

	thumb_func_start ExecBattleAnimArenaExit
ExecBattleAnimArenaExit: @ 0x0804C5A4
	push {lr}
	bl BasInit
	bl func_fe6_0804C744
	ldr r0, .L0804C5B8 @ =OnMainBas
	bl SetMainFunc
	pop {r0}
	bx r0
	.align 2, 0
.L0804C5B8: .4byte OnMainBas

	thumb_func_start NewEkrTogiInitPROC
NewEkrTogiInitPROC: @ 0x0804C5BC
	push {lr}
	ldr r0, .L0804C5CC @ =ProcScr_EkrTogiInitPROC
	movs r1, #3
	bl SpawnProc
	pop {r0}
	bx r0
	.align 2, 0
.L0804C5CC: .4byte ProcScr_EkrTogiInitPROC

	thumb_func_start func_fe6_0804C5D0
func_fe6_0804C5D0: @ 0x0804C5D0
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	mov r8, r0
	movs r0, #0
	bl InitOam
	ldr r1, .L0804C644 @ =gEkrInitPosReal
	ldr r0, .L0804C648 @ =gEkrInitialHitSide
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [r1]
	bl EfxClearScreenFx
	bl UpdateBanimFrame
	bl NewEkrGauge
	bl NewEkrDispUP
	bl NewEkrBattle
	ldr r0, .L0804C64C @ =gUnk_08118330
	ldr r4, .L0804C650 @ =gPal+0xC0
	adds r1, r4, #0
	movs r2, #0x20
	bl CpuFastSet
	subs r4, #0xc0
	ldr r5, .L0804C654 @ =gEfxPal
	movs r6, #0x80
	lsls r6, r6, #1
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl CpuFastSet
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl CpuFastSet
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x20
	movs r3, #0x10
	bl EfxPalBlackInOut
	bl EnablePalSync
	mov r0, r8
	bl Proc_Break
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804C644: .4byte gEkrInitPosReal
.L0804C648: .4byte gEkrInitialHitSide
.L0804C64C: .4byte gUnk_08118330
.L0804C650: .4byte gPal+0xC0
.L0804C654: .4byte gEfxPal

	thumb_func_start func_fe6_0804C658
func_fe6_0804C658: @ 0x0804C658
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, .L0804C6B8 @ =gUnk_08115524
	ldr r1, .L0804C6BC @ =0x06008000
	bl LZ77UnCompVram
	ldr r0, .L0804C6C0 @ =gUnk_08117B90
	ldr r6, .L0804C6C4 @ =gEkrTsaBuffer
	adds r1, r6, #0
	bl LZ77UnCompWram
	movs r1, #1
	rsbs r1, r1, #0
	ldr r2, .L0804C6C8 @ =gTmB_Banim
	movs r0, #0x2e
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	movs r0, #6
	str r0, [sp, #8]
	movs r4, #0
	str r4, [sp, #0xc]
	adds r0, r6, #0
	movs r3, #0x42
	bl EfxTmCpyExt
	movs r0, #0
	bl func_fe6_0804C50C
	movs r0, #8
	bl EnableBgSync
	strh r4, [r5, #0x2c]
	movs r0, #0x10
	strh r0, [r5, #0x2e]
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0x8e
	bl EfxPlaySE
	adds r0, r5, #0
	bl Proc_Break
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804C6B8: .4byte gUnk_08115524
.L0804C6BC: .4byte 0x06008000
.L0804C6C0: .4byte gUnk_08117B90
.L0804C6C4: .4byte gEkrTsaBuffer
.L0804C6C8: .4byte gTmB_Banim

	thumb_func_start func_fe6_0804C6CC
func_fe6_0804C6CC: @ 0x0804C6CC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r6, r0]
	movs r1, #0x2e
	ldrsh r0, [r6, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0
	bl Interpolate
	adds r5, r0, #0
	ldr r0, .L0804C728 @ =gEfxPal
	ldr r4, .L0804C72C @ =gPal
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r4, #0
	bl CpuFastSet
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x20
	adds r3, r5, #0
	bl EfxPalBlackInOut
	bl EnablePalSync
	ldrh r1, [r6, #0x2c]
	adds r1, #1
	strh r1, [r6, #0x2c]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r2, #0x2e
	ldrsh r0, [r6, r2]
	adds r0, #1
	cmp r1, r0
	bne .L0804C720
	adds r0, r6, #0
	bl Proc_Break
.L0804C720:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804C728: .4byte gEfxPal
.L0804C72C: .4byte gPal

	thumb_func_start func_fe6_0804C730
func_fe6_0804C730: @ 0x0804C730
	push {r4, lr}
	adds r4, r0, #0
	bl func_fe6_0804C818
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0804C744
func_fe6_0804C744: @ 0x0804C744
	push {lr}
	ldr r0, .L0804C758 @ =gUnk_085CBE50
	movs r1, #3
	bl SpawnProc
	bl func_fe6_0804C84C
	pop {r0}
	bx r0
	.align 2, 0
.L0804C758: .4byte gUnk_085CBE50

	thumb_func_start func_fe6_0804C75C
func_fe6_0804C75C: @ 0x0804C75C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0804C780 @ =gPal
	ldr r1, .L0804C784 @ =gEfxPal
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuFastSet
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x10
	strh r0, [r4, #0x2e]
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804C780: .4byte gPal
.L0804C784: .4byte gEfxPal

	thumb_func_start func_fe6_0804C788
func_fe6_0804C788: @ 0x0804C788
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r6, r0]
	movs r1, #0x2e
	ldrsh r0, [r6, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0x10
	bl Interpolate
	adds r5, r0, #0
	ldr r0, .L0804C7E4 @ =gEfxPal
	ldr r4, .L0804C7E8 @ =gPal
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r4, #0
	bl CpuFastSet
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x20
	adds r3, r5, #0
	bl EfxPalBlackInOut
	bl EnablePalSync
	ldrh r1, [r6, #0x2c]
	adds r1, #1
	strh r1, [r6, #0x2c]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r2, #0x2e
	ldrsh r0, [r6, r2]
	adds r0, #1
	cmp r1, r0
	bne .L0804C7DC
	adds r0, r6, #0
	bl Proc_Break
.L0804C7DC:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804C7E4: .4byte gEfxPal
.L0804C7E8: .4byte gPal

	thumb_func_start func_fe6_0804C7EC
func_fe6_0804C7EC: @ 0x0804C7EC
	push {r4, lr}
	adds r4, r0, #0
	bl EndEkrBattleDeamon
	bl EndEkrGauge
	ldr r0, .L0804C810 @ =OnMain
	bl SetMainFunc
	ldr r0, .L0804C814 @ =OnVBlank
	bl SetOnVBlank
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804C810: .4byte OnMain
.L0804C814: .4byte OnVBlank

	thumb_func_start func_fe6_0804C818
func_fe6_0804C818: @ 0x0804C818
	push {r4, lr}
	ldr r4, .L0804C83C @ =gUnk_Banim_0201E144
	ldr r0, .L0804C840 @ =gUnk_085CBE78
	movs r1, #3
	bl SpawnProc
	str r0, [r4]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L0804C844 @ =gUnk_08112370
	str r1, [r0, #0x48]
	ldr r1, .L0804C848 @ =Pals_ArenaBattleBg
	str r1, [r0, #0x4c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804C83C: .4byte gUnk_Banim_0201E144
.L0804C840: .4byte gUnk_085CBE78
.L0804C844: .4byte gUnk_08112370
.L0804C848: .4byte Pals_ArenaBattleBg

	thumb_func_start func_fe6_0804C84C
func_fe6_0804C84C: @ 0x0804C84C
	push {lr}
	ldr r0, .L0804C85C @ =gUnk_Banim_0201E144
	ldr r0, [r0]
	bl Proc_End
	pop {r0}
	bx r0
	.align 2, 0
.L0804C85C: .4byte gUnk_Banim_0201E144

	thumb_func_start func_fe6_0804C860
func_fe6_0804C860: @ 0x0804C860
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt .L0804C88C
	ldr r1, [r4, #0x4c]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, .L0804C894 @ =gPal+0xC0
	movs r2, #0x20
	bl CpuFastSet
	bl EnablePalSync
.L0804C88C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0804C894: .4byte gPal+0xC0
