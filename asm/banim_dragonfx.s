	.include "macro.inc"

	.syntax unified

	thumb_func_start func_fe6_0805A2BC
func_fe6_0805A2BC: @ 0x0805A2BC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, [r5, #0x64]
	ldr r4, .L0805A2E0 @ =gEkrDragonFastenConf
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #1
	bne .L0805A2E4
	ldr r0, [r5, #0x5c]
	bl func_fe6_0805A4C8
	str r0, [r5, #0x64]
	b .L0805A30E
	.align 2, 0
.L0805A2E0: .4byte gEkrDragonFastenConf
.L0805A2E4:
	ldr r0, [r5, #0x5c]
	bl CheckSkipDragonTransfer
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne .L0805A316
	adds r1, r6, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #1
	bne .L0805A352
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r5, #0x5c]
	bl func_fe6_0805A4C8
	str r0, [r5, #0x64]
	movs r0, #0x10
	bl EfxChapterMapFadeOUT
.L0805A30E:
	adds r0, r5, #0
	bl Proc_Break
	b .L0805A352
.L0805A316:
	adds r1, r6, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #1
	bne .L0805A352
	movs r4, #0
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r5, #0x5c]
	bl func_fe6_0805A4C8
	str r0, [r5, #0x64]
	movs r0, #0x10
	bl EfxChapterMapFadeOUT
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	ldr r1, .L0805A358 @ =gBanimValid
	lsls r0, r0, #1
	adds r0, r0, r1
	strh r4, [r0]
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	bl SetAnimStateHidden
	adds r0, r5, #0
	bl Proc_Break
.L0805A352:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805A358: .4byte gBanimValid

	thumb_func_start func_fe6_0805A35C
func_fe6_0805A35C: @ 0x0805A35C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x64]
	adds r1, r0, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #1
	bne .L0805A38A
	movs r4, #0
	movs r0, #2
	strb r0, [r1]
	ldr r0, .L0805A390 @ =gBg3Tm
	movs r1, #0xf0
	lsls r1, r1, #8
	bl TmFill
	movs r0, #8
	bl EnableBgSync
	strh r4, [r5, #0x2c]
	adds r0, r5, #0
	bl Proc_Break
.L0805A38A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805A390: .4byte gBg3Tm

	thumb_func_start func_fe6_0805A394
func_fe6_0805A394: @ 0x0805A394
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0x2c
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne .L0805A3B2
	ldr r0, .L0805A3E8 @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl ApplyChapterMapGraphics
	bl RenderMap
.L0805A3B2:
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r0, #8
	str r0, [sp]
	movs r0, #4
	movs r1, #0x10
	movs r2, #4
	bl Interpolate
	bl EfxChapterMapFadeOUT
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	bne .L0805A3E0
	movs r0, #0
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl Proc_Break
.L0805A3E0:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805A3E8: .4byte gPlaySt

	thumb_func_start func_fe6_0805A3EC
func_fe6_0805A3EC: @ 0x0805A3EC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimPosition
	ldr r1, .L0805A40C @ =gEkrDragonIntroDone
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #2
	strh r1, [r0]
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805A40C: .4byte gEkrDragonIntroDone

	thumb_func_start NewEfxIdunnIntro
NewEfxIdunnIntro: @ 0x0805A410
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0805A430 @ =gUnk_08604948
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	adds r2, r0, #0
	adds r2, #0x29
	movs r1, #0
	strb r1, [r2]
	strh r1, [r0, #0x2c]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L0805A430: .4byte gUnk_08604948

	thumb_func_start func_fe6_0805A434
func_fe6_0805A434: @ 0x0805A434
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r6, r0]
	movs r0, #8
	str r0, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0x10
	bl Interpolate
	adds r5, r0, #0
	ldr r0, .L0805A4A8 @ =gEkrBgPaletteBackup3
	ldr r4, .L0805A4AC @ =gPal+0x80
	adds r1, r4, #0
	movs r2, #0x10
	bl CpuFastSet
	subs r4, #0x80
	adds r0, r4, #0
	movs r1, #4
	movs r2, #2
	adds r3, r5, #0
	bl EfxPalBlackInOut
	bl EnablePalSync
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	movs r2, #0
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	bne .L0805A4A0
	strh r2, [r6, #0x2c]
	adds r1, r6, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	ldr r0, .L0805A4B0 @ =gBg2Tm+0x2C0
	str r2, [sp]
	movs r1, #0x1e
	movs r2, #5
	movs r3, #0
	bl FillBGRect
	movs r0, #4
	bl EnableBgSync
	adds r0, r6, #0
	bl Proc_Break
.L0805A4A0:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805A4A8: .4byte gEkrBgPaletteBackup3
.L0805A4AC: .4byte gPal+0x80
.L0805A4B0: .4byte gBg2Tm+0x2C0

	thumb_func_start func_fe6_0805A4B4
func_fe6_0805A4B4: @ 0x0805A4B4
	push {lr}
	adds r1, r0, #0
	adds r1, #0x29
	ldrb r1, [r1]
	cmp r1, #2
	bne .L0805A4C4
	bl Proc_Break
.L0805A4C4:
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805A4C8
func_fe6_0805A4C8: @ 0x0805A4C8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, .L0805A50C @ =gUnk_08604968
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	adds r1, r5, #0
	adds r1, #0x29
	movs r0, #0
	strb r0, [r1]
	strh r0, [r5, #0x2c]
	ldr r0, .L0805A510 @ =gUnk_Banim_0201E0FC
	bl func_fe6_0804BF40
	ldr r4, .L0805A514 @ =gPal+0x80
	ldr r1, .L0805A518 @ =gEkrBgPaletteBackup3
	adds r0, r4, #0
	movs r2, #0x10
	bl CpuFastSet
	subs r4, #0x80
	adds r0, r4, #0
	movs r1, #4
	movs r2, #2
	movs r3, #0x10
	bl EfxPalBlackInOut
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
.L0805A50C: .4byte gUnk_08604968
.L0805A510: .4byte gUnk_Banim_0201E0FC
.L0805A514: .4byte gPal+0x80
.L0805A518: .4byte gEkrBgPaletteBackup3

	thumb_func_start func_fe6_0805A51C
func_fe6_0805A51C: @ 0x0805A51C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r6, r0]
	movs r0, #8
	str r0, [sp]
	movs r0, #1
	movs r1, #0x10
	movs r2, #0
	bl Interpolate
	adds r5, r0, #0
	ldr r0, .L0805A57C @ =gEkrBgPaletteBackup3
	ldr r4, .L0805A580 @ =gPal+0x80
	adds r1, r4, #0
	movs r2, #0x10
	bl CpuFastSet
	subs r4, #0x80
	adds r0, r4, #0
	movs r1, #4
	movs r2, #2
	adds r3, r5, #0
	bl EfxPalBlackInOut
	bl EnablePalSync
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	bne .L0805A574
	movs r0, #0
	strh r0, [r6, #0x2c]
	adds r1, r6, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	adds r0, r6, #0
	bl Proc_Break
.L0805A574:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805A57C: .4byte gEkrBgPaletteBackup3
.L0805A580: .4byte gPal+0x80

	thumb_func_start func_fe6_0805A584
func_fe6_0805A584: @ 0x0805A584
	push {lr}
	adds r1, r0, #0
	adds r1, #0x29
	ldrb r1, [r1]
	cmp r1, #2
	bne .L0805A594
	bl Proc_Break
.L0805A594:
	pop {r0}
	bx r0

	thumb_func_start NewEfxIdunnMain
NewEfxIdunnMain: @ 0x0805A598
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0805A5C0 @ =gUnk_08604988
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r3, #0
	movs r2, #0
	strh r2, [r0, #0x32]
	strh r2, [r0, #0x3a]
	movs r1, #9
	strh r1, [r0, #0x2c]
	strh r2, [r0, #0x2e]
	adds r1, r0, #0
	adds r1, #0x29
	strb r3, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L0805A5C0: .4byte gUnk_08604988

	thumb_func_start func_fe6_0805A5C4
func_fe6_0805A5C4: @ 0x0805A5C4
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xa
	bne .L0805A616
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne .L0805A5EC
	ldr r0, .L0805A5E8 @ =Tsa_EkrIdunn_081C4E28
	bl func_fe6_08058FA8
	b .L0805A602
	.align 2, 0
.L0805A5E8: .4byte Tsa_EkrIdunn_081C4E28
.L0805A5EC:
	cmp r0, #1
	bne .L0805A5FC
	ldr r0, .L0805A5F8 @ =gUnk_081C5264
	bl func_fe6_08058FA8
	b .L0805A602
	.align 2, 0
.L0805A5F8: .4byte gUnk_081C5264
.L0805A5FC:
	ldr r0, .L0805A638 @ =gUnk_081C5688
	bl func_fe6_08058FA8
.L0805A602:
	movs r1, #0
	strh r1, [r4, #0x2c]
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	bne .L0805A616
	strh r1, [r4, #0x2e]
.L0805A616:
	ldrh r1, [r4, #0x32]
	ldrh r2, [r4, #0x3a]
	movs r0, #3
	bl SetBgOffset
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #1
	bne .L0805A630
	adds r0, r4, #0
	bl Proc_Break
.L0805A630:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805A638: .4byte gUnk_081C5688

	thumb_func_start func_fe6_0805A63C
func_fe6_0805A63C: @ 0x0805A63C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r1, [r4, #0x32]
	ldrh r2, [r4, #0x3a]
	movs r0, #3
	bl SetBgOffset
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start NewEkrIdunnExitAnim2
NewEkrIdunnExitAnim2: @ 0x0805A658
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0
	mov r8, r1
	adds r6, r2, #0
	ldr r0, .L0805A6A8 @ =gUnk_086049A8
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	adds r1, r5, #0
	adds r1, #0x29
	movs r0, #0
	strb r0, [r1]
	strh r0, [r5, #0x2c]
	strh r6, [r5, #0x2e]
	mov r0, r8
	strh r0, [r5, #0x30]
	ldr r4, .L0805A6AC @ =gPal+0xC0
	ldr r1, .L0805A6B0 @ =gEkrBgPaletteBackup1
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	movs r0, #0x88
	lsls r0, r0, #2
	adds r4, r4, r0
	ldr r1, .L0805A6B4 @ =gEkrBgPaletteBackup2
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	adds r0, r5, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
.L0805A6A8: .4byte gUnk_086049A8
.L0805A6AC: .4byte gPal+0xC0
.L0805A6B0: .4byte gEkrBgPaletteBackup1
.L0805A6B4: .4byte gEkrBgPaletteBackup2

	thumb_func_start func_fe6_0805A6B8
func_fe6_0805A6B8: @ 0x0805A6B8
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x2c]
	adds r0, #1
	strh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	ldrh r3, [r2, #0x30]
	lsls r1, r3, #0x10
	cmp r0, r1
	bne .L0805A6D6
	movs r0, #0
	strh r0, [r2, #0x2c]
	adds r0, r2, #0
	bl Proc_Break
.L0805A6D6:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0805A6DC
func_fe6_0805A6DC: @ 0x0805A6DC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r6, r0]
	movs r1, #0x2e
	ldrsh r0, [r6, r1]
	str r0, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0x10
	bl Interpolate
	adds r5, r0, #0
	ldr r0, .L0805A75C @ =gEkrBgPaletteBackup1
	ldr r4, .L0805A760 @ =gPal+0xC0
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, .L0805A764 @ =gEkrBgPaletteBackup2
	movs r2, #0x88
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r2, #8
	bl CpuFastSet
	subs r4, #0xc0
	adds r0, r4, #0
	movs r1, #6
	movs r2, #1
	adds r3, r5, #0
	bl EfxPalBlackInOut
	adds r0, r4, #0
	movs r1, #0x17
	movs r2, #1
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
	bne .L0805A752
	adds r1, r6, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	adds r0, r6, #0
	bl Proc_Break
.L0805A752:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805A75C: .4byte gEkrBgPaletteBackup1
.L0805A760: .4byte gPal+0xC0
.L0805A764: .4byte gEkrBgPaletteBackup2

	thumb_func_start func_fe6_0805A768
func_fe6_0805A768: @ 0x0805A768
	push {lr}
	adds r1, r0, #0
	adds r1, #0x29
	ldrb r1, [r1]
	cmp r1, #2
	bne .L0805A778
	bl Proc_Break
.L0805A778:
	pop {r0}
	bx r0

	thumb_func_start NewEkrIdunnIntroDeamon1
NewEkrIdunnIntroDeamon1: @ 0x0805A77C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, .L0805A7B8 @ =ProcScr_EkrIdunnDeamon
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	ldr r0, .L0805A7BC @ =AnimScr_EkrIdunnDeamon
	movs r1, #0x78
	bl BasCreate
	movs r2, #0
	movs r1, #0xf4
	lsls r1, r1, #7
	strh r1, [r0, #8]
	movs r1, #0xc0
	lsls r1, r1, #1
	strh r1, [r4, #0x32]
	strh r1, [r0, #2]
	strh r1, [r4, #0x3a]
	strh r1, [r0, #4]
	str r0, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x29
	strb r2, [r0]
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
.L0805A7B8: .4byte ProcScr_EkrIdunnDeamon
.L0805A7BC: .4byte AnimScr_EkrIdunnDeamon

	thumb_func_start func_fe6_0805A7C0
func_fe6_0805A7C0: @ 0x0805A7C0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x60]
	ldrh r1, [r4, #0x32]
	strh r1, [r0, #2]
	ldrh r1, [r4, #0x3a]
	strh r1, [r0, #4]
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #1
	bne .L0805A7E4
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L0805A7E4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start NewEkrIdunnIntroDeamon2
NewEkrIdunnIntroDeamon2: @ 0x0805A7EC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, .L0805A824 @ =gUnk_086049E8
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	ldr r0, .L0805A828 @ =gUnk_08605A70
	movs r1, #0x78
	bl BasCreate
	movs r2, #0
	movs r1, #0xf4
	lsls r1, r1, #7
	strh r1, [r0, #8]
	movs r1, #0xc0
	lsls r1, r1, #1
	strh r1, [r0, #2]
	strh r1, [r0, #4]
	str r0, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x29
	strb r2, [r0]
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
.L0805A824: .4byte gUnk_086049E8
.L0805A828: .4byte gUnk_08605A70

	thumb_func_start func_fe6_0805A82C
func_fe6_0805A82C: @ 0x0805A82C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x60]
	ldrh r1, [r4, #0x32]
	strh r1, [r0, #2]
	ldrh r1, [r4, #0x3a]
	strh r1, [r0, #4]
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #1
	bne .L0805A850
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L0805A850:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start NewEkrIdunnBodyFlashing
NewEkrIdunnBodyFlashing: @ 0x0805A858
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0805A884 @ =ProcScr_EkrIdunnBodyFlashing
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r1, [r0, #0x2e]
	str r1, [r0, #0x44]
	ldr r1, .L0805A888 @ =gUnk_081BC132
	str r1, [r0, #0x48]
	ldr r1, .L0805A88C @ =gUnk_08604A18
	str r1, [r0, #0x4c]
	ldrb r1, [r4, #0x12]
	str r1, [r0, #0x54]
	ldr r1, .L0805A890 @ =gpProcEkrIdunnBodyFlashing
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L0805A884: .4byte ProcScr_EkrIdunnBodyFlashing
.L0805A888: .4byte gUnk_081BC132
.L0805A88C: .4byte gUnk_08604A18
.L0805A890: .4byte gpProcEkrIdunnBodyFlashing

	thumb_func_start EndEkrIdunnBodyFlashing
EndEkrIdunnBodyFlashing: @ 0x0805A894
	push {r4, lr}
	ldr r4, .L0805A8AC @ =gpProcEkrIdunnBodyFlashing
	ldr r0, [r4]
	cmp r0, #0
	beq .L0805A8A6
	bl Proc_End
	movs r0, #0
	str r0, [r4]
.L0805A8A6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805A8AC: .4byte gpProcEkrIdunnBodyFlashing

	thumb_func_start func_fe6_0805A8B0
func_fe6_0805A8B0: @ 0x0805A8B0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	ldrb r1, [r0, #0x12]
	ldr r0, [r4, #0x54]
	cmp r0, r1
	beq .L0805A930
	str r1, [r4, #0x54]
	movs r0, #0
	strh r0, [r4, #0x2c]
	strh r0, [r4, #0x2e]
	str r0, [r4, #0x44]
	cmp r1, #9
	bhi .L0805A930
	lsls r0, r1, #2
	ldr r1, .L0805A8D8 @ =.L0805A8DC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L0805A8D8: .4byte .L0805A8DC
.L0805A8DC: @ jump table
	.4byte .L0805A904 @ case 0
	.4byte .L0805A91C @ case 1
	.4byte .L0805A90C @ case 2
	.4byte .L0805A914 @ case 3
	.4byte .L0805A92C @ case 4
	.4byte .L0805A92C @ case 5
	.4byte .L0805A92C @ case 6
	.4byte .L0805A92C @ case 7
	.4byte .L0805A92C @ case 8
	.4byte .L0805A904 @ case 9
.L0805A904:
	ldr r0, .L0805A908 @ =gUnk_081BC140
	b .L0805A92E
	.align 2, 0
.L0805A908: .4byte gUnk_081BC140
.L0805A90C:
	ldr r0, .L0805A910 @ =gUnk_081BC15E
	b .L0805A92E
	.align 2, 0
.L0805A910: .4byte gUnk_081BC15E
.L0805A914:
	ldr r0, .L0805A918 @ =gUnk_081BC17C
	b .L0805A92E
	.align 2, 0
.L0805A918: .4byte gUnk_081BC17C
.L0805A91C:
	ldr r0, .L0805A928 @ =gUnk_081BC19A
	str r0, [r4, #0x48]
	ldr r0, [r4, #0x5c]
	bl func_fe6_08057B90
	b .L0805A930
	.align 2, 0
.L0805A928: .4byte gUnk_081BC19A
.L0805A92C:
	ldr r0, .L0805A954 @ =gUnk_081BC132
.L0805A92E:
	str r0, [r4, #0x48]
.L0805A930:
	adds r0, r4, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L0805A958
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bl func_fe6_08059018
	b .L0805A992
	.align 2, 0
.L0805A954: .4byte gUnk_081BC132
.L0805A958:
	movs r0, #4
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L0805A992
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne .L0805A97E
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	movs r1, #8
	ldrh r0, [r0, #0x10]
	ands r1, r0
	cmp r1, #0
	beq .L0805A992
	movs r0, #1
	strh r0, [r4, #0x2e]
	b .L0805A992
.L0805A97E:
	bl CheckEkrHitDone
	cmp r0, #1
	bne .L0805A992
	movs r0, #0
	strh r0, [r4, #0x2c]
	strh r0, [r4, #0x2e]
	ldr r0, [r4, #0x44]
	adds r0, #1
	str r0, [r4, #0x44]
.L0805A992:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start NewEfxAvoidForIdunn
NewEfxAvoidForIdunn: @ 0x0805A998
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, .L0805A9E4 @ =gUnk_08604A3C
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	adds r1, r5, #0
	adds r1, #0x29
	movs r0, #0
	strb r0, [r1]
	strh r0, [r5, #0x2c]
	movs r0, #0x10
	strh r0, [r5, #0x2e]
	ldr r4, .L0805A9E8 @ =gPal+0xC0
	ldr r1, .L0805A9EC @ =gEkrBgPaletteBackup1
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	movs r0, #0x88
	lsls r0, r0, #2
	adds r4, r4, r0
	ldr r1, .L0805A9F0 @ =gEkrBgPaletteBackup2
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, .L0805A9F4 @ =0x00000143
	movs r1, #0x80
	lsls r1, r1, #1
	bl EfxPlaySE
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
.L0805A9E4: .4byte gUnk_08604A3C
.L0805A9E8: .4byte gPal+0xC0
.L0805A9EC: .4byte gEkrBgPaletteBackup1
.L0805A9F0: .4byte gEkrBgPaletteBackup2
.L0805A9F4: .4byte 0x00000143

	thumb_func_start func_fe6_0805A9F8
func_fe6_0805A9F8: @ 0x0805A9F8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r7, r0]
	movs r1, #0x2e
	ldrsh r0, [r7, r1]
	str r0, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0x10
	bl Interpolate
	mov r8, r0
	ldr r0, .L0805AA90 @ =gEkrBgPaletteBackup1
	ldr r4, .L0805AA94 @ =gPal+0xC0
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r6, .L0805AA98 @ =gEkrBgPaletteBackup2
	movs r2, #0x88
	lsls r2, r2, #2
	adds r1, r4, r2
	adds r0, r6, #0
	movs r2, #8
	bl CpuFastSet
	adds r5, r4, #0
	subs r5, #0xc0
	adds r0, r5, #0
	movs r1, #6
	movs r2, #1
	mov r3, r8
	bl EfxPalBlackInOut
	adds r0, r5, #0
	movs r1, #0x17
	movs r2, #1
	mov r3, r8
	bl EfxPalBlackInOut
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r6, #0x1c]
	strh r0, [r1]
	ldr r1, .L0805AA9C @ =0x0000023E
	adds r4, r4, r1
	ldrh r0, [r6, #0x1e]
	strh r0, [r4]
	bl EnablePalSync
	ldrh r1, [r7, #0x2c]
	adds r1, #1
	strh r1, [r7, #0x2c]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r2, #0x2e
	ldrsh r0, [r7, r2]
	adds r0, #1
	cmp r1, r0
	bne .L0805AA84
	movs r0, #0
	strh r0, [r7, #0x2c]
	adds r0, r7, #0
	bl Proc_Break
.L0805AA84:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805AA90: .4byte gEkrBgPaletteBackup1
.L0805AA94: .4byte gPal+0xC0
.L0805AA98: .4byte gEkrBgPaletteBackup2
.L0805AA9C: .4byte 0x0000023E

	thumb_func_start func_fe6_0805AAA0
func_fe6_0805AAA0: @ 0x0805AAA0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r7, r0]
	movs r1, #0x2e
	ldrsh r0, [r7, r1]
	str r0, [sp]
	movs r0, #1
	movs r1, #0x10
	movs r2, #0
	bl Interpolate
	mov r8, r0
	ldr r0, .L0805AB40 @ =gEkrBgPaletteBackup1
	ldr r4, .L0805AB44 @ =gPal+0xC0
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r6, .L0805AB48 @ =gEkrBgPaletteBackup2
	movs r2, #0x88
	lsls r2, r2, #2
	adds r1, r4, r2
	adds r0, r6, #0
	movs r2, #8
	bl CpuFastSet
	adds r5, r4, #0
	subs r5, #0xc0
	adds r0, r5, #0
	movs r1, #6
	movs r2, #1
	mov r3, r8
	bl EfxPalBlackInOut
	adds r0, r5, #0
	movs r1, #0x17
	movs r2, #1
	mov r3, r8
	bl EfxPalBlackInOut
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r6, #0x1c]
	strh r0, [r1]
	ldr r1, .L0805AB4C @ =0x0000023E
	adds r4, r4, r1
	ldrh r0, [r6, #0x1e]
	strh r0, [r4]
	bl EnablePalSync
	ldrh r1, [r7, #0x2c]
	adds r1, #1
	strh r1, [r7, #0x2c]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r2, #0x2e
	ldrsh r0, [r7, r2]
	adds r0, #1
	cmp r1, r0
	bne .L0805AB34
	movs r0, #0
	strh r0, [r7, #0x2c]
	adds r1, r7, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	bl Proc_Break
.L0805AB34:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805AB40: .4byte gEkrBgPaletteBackup1
.L0805AB44: .4byte gPal+0xC0
.L0805AB48: .4byte gEkrBgPaletteBackup2
.L0805AB4C: .4byte 0x0000023E

	thumb_func_start func_fe6_0805AB50
func_fe6_0805AB50: @ 0x0805AB50
	push {lr}
	bl Proc_Break
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start NewEkrIdunnExitAnim1
NewEkrIdunnExitAnim1: @ 0x0805AB5C
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, .L0805ABB0 @ =gUnk_08604A6C
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	adds r0, #0x29
	movs r4, #0
	strb r4, [r0]
	strh r4, [r5, #0x2c]
	ldr r0, .L0805ABB4 @ =Tsa_EkrIdunn_081C4E28
	ldr r6, .L0805ABB8 @ =gEkrTsaBuffer
	adds r1, r6, #0
	bl LZ77UnCompWram
	movs r1, #1
	rsbs r1, r1, #0
	ldr r2, .L0805ABBC @ =gBg3Tm
	movs r0, #0x1e
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #6
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r6, #0
	movs r3, #0x20
	bl EfxTmCpyExt
	ldr r0, [r5, #0x5c]
	movs r1, #0x64
	movs r2, #0xc8
	bl NewEkrIdunnExitAnim2
	str r0, [r5, #0x60]
	adds r0, r5, #0
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
.L0805ABB0: .4byte gUnk_08604A6C
.L0805ABB4: .4byte Tsa_EkrIdunn_081C4E28
.L0805ABB8: .4byte gEkrTsaBuffer
.L0805ABBC: .4byte gBg3Tm

	thumb_func_start func_fe6_0805ABC0
func_fe6_0805ABC0: @ 0x0805ABC0
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0805ABE8
	ldr r0, [r4, #0x5c]
	movs r1, #3
	movs r2, #2
	movs r3, #3
	bl func_fe6_0805AE1C
	ldr r0, .L0805AC50 @ =0x00000147
	movs r1, #0x80
	lsls r1, r1, #1
	bl EfxPlaySE
.L0805ABE8:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0x23
	bne .L0805AC04
	ldr r0, [r4, #0x5c]
	movs r1, #3
	movs r2, #2
	movs r3, #3
	bl func_fe6_0805AE1C
	ldr r0, .L0805AC50 @ =0x00000147
	movs r1, #0x80
	lsls r1, r1, #1
	bl EfxPlaySE
.L0805AC04:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0x32
	bne .L0805AC20
	ldr r0, [r4, #0x5c]
	movs r1, #3
	movs r2, #2
	movs r3, #3
	bl func_fe6_0805AE1C
	ldr r0, .L0805AC50 @ =0x00000147
	movs r1, #0x80
	lsls r1, r1, #1
	bl EfxPlaySE
.L0805AC20:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0x64
	bne .L0805AC48
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r4, #0x2e]
	adds r0, #0x19
	bl DoM4aSongNumStop
	movs r0, #0xa3
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	bl EfxPlaySE
	adds r0, r4, #0
	bl Proc_Break
.L0805AC48:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805AC50: .4byte 0x00000147

	thumb_func_start func_fe6_0805AC54
func_fe6_0805AC54: @ 0x0805AC54
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r7, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r7, r0]
	movs r1, #0x2e
	ldrsh r0, [r7, r1]
	str r0, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0xa0
	bl Interpolate
	adds r6, r0, #0
	rsbs r4, r6, #0
	adds r4, #0xf0
	movs r0, #0xff
	ands r4, r0
	asrs r4, r4, #3
	movs r2, #0x20
	subs r2, r2, r6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #3
	movs r1, #0
	bl SetBgOffset
	add r1, sp, #4
	movs r0, #0x1f
	strh r0, [r1]
	lsls r4, r4, #6
	ldr r0, .L0805ADBC @ =gBg3Tm
	adds r4, r4, r0
	ldr r2, .L0805ADC0 @ =0x01000020
	adds r0, r1, #0
	adds r1, r4, #0
	bl CpuSet
	movs r0, #8
	bl EnableBgSync
	ldr r0, .L0805ADC4 @ =gAnims
	ldr r4, [r0]
	ldr r5, [r0, #4]
	ldr r3, .L0805ADC8 @ =gEkrXPosReal
	ldr r0, .L0805ADCC @ =gEkrBgPosition
	ldr r1, [r0]
	ldrh r2, [r3]
	subs r0, r2, r1
	movs r2, #0
	mov r8, r2
	strh r0, [r4, #2]
	ldr r2, .L0805ADD0 @ =gEkrYPosReal
	ldrh r0, [r2]
	adds r0, r0, r6
	strh r0, [r4, #4]
	ldrh r3, [r3]
	subs r1, r3, r1
	strh r1, [r5, #2]
	ldrh r2, [r2]
	adds r6, r2, r6
	strh r6, [r5, #4]
	ldr r1, .L0805ADD4 @ =gDispIo
	ldr r3, .L0805ADD8 @ =gEkrBg2QuakeVec
	ldrh r2, [r3]
	ldrh r6, [r1, #0x28]
	adds r0, r2, r6
	strh r0, [r1, #0x28]
	ldrh r0, [r1, #0x2a]
	ldrh r6, [r3, #2]
	adds r0, r0, r6
	strh r0, [r1, #0x2a]
	ldrh r0, [r4, #2]
	subs r2, r0, r2
	strh r2, [r4, #2]
	ldrh r1, [r4, #4]
	ldrh r2, [r3, #2]
	subs r0, r1, r2
	strh r0, [r4, #4]
	ldrh r6, [r5, #2]
	ldrh r1, [r3]
	subs r0, r6, r1
	strh r0, [r5, #2]
	ldrh r2, [r5, #4]
	ldrh r3, [r3, #2]
	subs r0, r2, r3
	strh r0, [r5, #4]
	ldrh r0, [r7, #0x2c]
	adds r0, #1
	strh r0, [r7, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0805AD1E
	movs r0, #8
	movs r1, #0
	bl NewEfxQuakePure
	str r0, [r7, #0x5c]
.L0805AD1E:
	ldrh r6, [r7, #0x2c]
	cmp r6, #0x3c
	bne .L0805AD34
	ldr r0, [r7, #0x5c]
	bl Proc_End
	movs r0, #9
	movs r1, #0
	bl NewEfxQuakePure
	str r0, [r7, #0x5c]
.L0805AD34:
	ldrh r0, [r7, #0x2c]
	cmp r0, #0x5a
	bne .L0805AD4A
	ldr r0, [r7, #0x5c]
	bl Proc_End
	movs r0, #0xa
	movs r1, #0
	bl NewEfxQuakePure
	str r0, [r7, #0x5c]
.L0805AD4A:
	ldrh r1, [r7, #0x2c]
	cmp r1, #0x87
	bne .L0805AD5C
	ldr r0, [r7, #0x5c]
	movs r1, #0x3c
	movs r2, #0x1e
	movs r3, #0x78
	bl func_fe6_0805AE1C
.L0805AD5C:
	ldrh r2, [r7, #0x2c]
	cmp r2, #0xc8
	bne .L0805AD92
	mov r0, sp
	adds r0, #6
	mov r6, r8
	strh r6, [r0]
	ldr r4, .L0805ADDC @ =gPal+0xC0
	ldr r5, .L0805ADE0 @ =0x01000010
	adds r1, r4, #0
	adds r2, r5, #0
	bl CpuSet
	add r0, sp, #8
	strh r6, [r0]
	movs r1, #0x88
	lsls r1, r1, #2
	adds r4, r4, r1
	adds r1, r4, #0
	adds r2, r5, #0
	bl CpuSet
	bl EnablePalSync
	ldr r0, [r7, #0x60]
	bl Proc_End
.L0805AD92:
	movs r2, #0x2c
	ldrsh r1, [r7, r2]
	movs r6, #0x2e
	ldrsh r0, [r7, r6]
	adds r0, #1
	cmp r1, r0
	bne .L0805ADB0
	mov r0, r8
	strh r0, [r7, #0x2c]
	ldr r0, [r7, #0x5c]
	bl Proc_End
	adds r0, r7, #0
	bl Proc_Break
.L0805ADB0:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805ADBC: .4byte gBg3Tm
.L0805ADC0: .4byte 0x01000020
.L0805ADC4: .4byte gAnims
.L0805ADC8: .4byte gEkrXPosReal
.L0805ADCC: .4byte gEkrBgPosition
.L0805ADD0: .4byte gEkrYPosReal
.L0805ADD4: .4byte gDispIo
.L0805ADD8: .4byte gEkrBg2QuakeVec
.L0805ADDC: .4byte gPal+0xC0
.L0805ADE0: .4byte 0x01000010

	thumb_func_start func_fe6_0805ADE4
func_fe6_0805ADE4: @ 0x0805ADE4
	push {lr}
	adds r1, r0, #0
	ldrh r0, [r1, #0x2c]
	adds r0, #1
	strh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc8
	bne .L0805AE04
	adds r2, r1, #0
	adds r2, #0x29
	movs r0, #1
	strb r0, [r2]
	adds r0, r1, #0
	bl Proc_Break
.L0805AE04:
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805AE08
func_fe6_0805AE08: @ 0x0805AE08
	push {lr}
	adds r1, r0, #0
	adds r1, #0x29
	ldrb r1, [r1]
	cmp r1, #2
	bne .L0805AE18
	bl Proc_Break
.L0805AE18:
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805AE1C
func_fe6_0805AE1C: @ 0x0805AE1C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	mov r8, r3
	ldr r0, .L0805AE64 @ =gUnk_08604A9C
	movs r1, #0
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r5, [r0, #0x44]
	str r6, [r0, #0x48]
	mov r1, r8
	str r1, [r0, #0x4c]
	ldr r2, .L0805AE68 @ =gDispIo
	adds r3, r2, #0
	adds r3, #0x3c
	movs r1, #0x21
	rsbs r1, r1, #0
	adds r0, r1, #0
	ldrb r4, [r3]
	ands r0, r4
	strb r0, [r3]
	adds r2, #0x3d
	ldrb r0, [r2]
	ands r1, r0
	strb r1, [r2]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805AE64: .4byte gUnk_08604A9C
.L0805AE68: .4byte gDispIo

	thumb_func_start func_fe6_0805AE6C
func_fe6_0805AE6C: @ 0x0805AE6C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r7, r0]
	ldr r0, [r7, #0x44]
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0x10
	bl Interpolate
	adds r6, r0, #0
	ldr r0, .L0805AED4 @ =gPal
	ldr r4, .L0805AED8 @ =gEfxPal
	movs r5, #0x80
	lsls r5, r5, #1
	adds r1, r4, #0
	adds r2, r5, #0
	bl CpuFastSet
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x20
	adds r3, r6, #0
	bl EfxPalWhiteInOut
	movs r1, #0xa0
	lsls r1, r1, #0x13
	adds r0, r4, #0
	adds r2, r5, #0
	bl CpuFastSet
	bl DisablePalSync
	ldrh r0, [r7, #0x2c]
	adds r0, #1
	strh r0, [r7, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r7, #0x44]
	cmp r0, r1
	ble .L0805AECC
	movs r0, #0
	strh r0, [r7, #0x2c]
	adds r0, r7, #0
	bl Proc_Break
.L0805AECC:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805AED4: .4byte gPal
.L0805AED8: .4byte gEfxPal

	thumb_func_start func_fe6_0805AEDC
func_fe6_0805AEDC: @ 0x0805AEDC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, .L0805AF2C @ =gPal
	ldr r4, .L0805AF30 @ =gEfxPal
	movs r5, #0x80
	lsls r5, r5, #1
	adds r1, r4, #0
	adds r2, r5, #0
	bl CpuFastSet
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x20
	movs r3, #0x10
	bl EfxPalWhiteInOut
	movs r1, #0xa0
	lsls r1, r1, #0x13
	adds r0, r4, #0
	adds r2, r5, #0
	bl CpuFastSet
	bl DisablePalSync
	ldrh r0, [r6, #0x2c]
	adds r0, #1
	strh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r6, #0x48]
	cmp r0, r1
	ble .L0805AF26
	movs r0, #0
	strh r0, [r6, #0x2c]
	adds r0, r6, #0
	bl Proc_Break
.L0805AF26:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805AF2C: .4byte gPal
.L0805AF30: .4byte gEfxPal

	thumb_func_start func_fe6_0805AF34
func_fe6_0805AF34: @ 0x0805AF34
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r7, r0]
	ldr r0, [r7, #0x4c]
	str r0, [sp]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0
	bl Interpolate
	adds r6, r0, #0
	ldr r0, .L0805AF9C @ =gPal
	ldr r4, .L0805AFA0 @ =gEfxPal
	movs r5, #0x80
	lsls r5, r5, #1
	adds r1, r4, #0
	adds r2, r5, #0
	bl CpuFastSet
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x20
	adds r3, r6, #0
	bl EfxPalWhiteInOut
	movs r1, #0xa0
	lsls r1, r1, #0x13
	adds r0, r4, #0
	adds r2, r5, #0
	bl CpuFastSet
	bl DisablePalSync
	ldrh r0, [r7, #0x2c]
	adds r0, #1
	strh r0, [r7, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r7, #0x4c]
	cmp r0, r1
	ble .L0805AF94
	movs r0, #0
	strh r0, [r7, #0x2c]
	adds r0, r7, #0
	bl Proc_Break
.L0805AF94:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805AF9C: .4byte gPal
.L0805AFA0: .4byte gEfxPal

	thumb_func_start func_fe6_0805AFA4
func_fe6_0805AFA4: @ 0x0805AFA4
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, .L0805AFD0 @ =gDispIo
	adds r3, r2, #0
	adds r3, #0x3c
	movs r0, #0x20
	ldrb r1, [r3]
	orrs r1, r0
	strb r1, [r3]
	adds r2, #0x3d
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	bl EnablePalSync
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805AFD0: .4byte gDispIo

	thumb_func_start func_fe6_0805AFD4
func_fe6_0805AFD4: @ 0x0805AFD4
	push {lr}
	ldr r0, .L0805AFE8 @ =gUnk_08604ACC
	movs r1, #3
	bl SpawnProc
	movs r1, #0
	strh r1, [r0, #0x2c]
	pop {r0}
	bx r0
	.align 2, 0
.L0805AFE8: .4byte gUnk_08604ACC

	thumb_func_start func_fe6_0805AFEC
func_fe6_0805AFEC: @ 0x0805AFEC
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x14
	bne .L0805B012
	ldr r0, .L0805B018 @ =0x00000145
	movs r1, #0x80
	lsls r1, r1, #1
	bl EfxPlaySE
	bl func_fe6_0805BD8C
	adds r0, r4, #0
	bl Proc_Break
.L0805B012:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805B018: .4byte 0x00000145
