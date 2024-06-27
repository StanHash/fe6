	.include "macro.inc"

	.syntax unified

	.section .data

	.global ProcScr_EfxFlashBG
ProcScr_EfxFlashBG: @ 085CB9D0
	.incbin "fe6-base.gba", 0x5CB9D0, (0x5CB9F8 - 0x5CB9D0) @ length: 0028

	.global ProcScr_EfxWhiteOUT
ProcScr_EfxWhiteOUT: @ 085CB9F8
	.incbin "fe6-base.gba", 0x5CB9F8, (0x5CBA20 - 0x5CB9F8) @ length: 0028

	.global gUnk_085CBA20
gUnk_085CBA20: @ 085CBA20
	.incbin "fe6-base.gba", 0x5CBA20, (0x5CBA50 - 0x5CBA20) @ length: 0030

	.global ProcScr_EfxHpBarColorChange
ProcScr_EfxHpBarColorChange: @ 085CBA50
	.incbin "fe6-base.gba", 0x5CBA50, (0x5CBA70 - 0x5CBA50) @ length: 0020

	.section .text
	thumb_func_start NewEfxFlashBgWhite
NewEfxFlashBgWhite: @ 0x08046794
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, .L080467C4 @ =ProcScr_EfxFlashBG
	movs r1, #0
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp]
	ldr r1, .L080467C8 @ =gEfxPal
	ldr r2, .L080467CC @ =0x01000100
	mov r0, sp
	bl CpuFastSet
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080467C4: .4byte ProcScr_EfxFlashBG
.L080467C8: .4byte gEfxPal
.L080467CC: .4byte 0x01000100

	thumb_func_start NewEfxFlashBgRed
NewEfxFlashBgRed: @ 0x080467D0
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, .L08046800 @ =ProcScr_EfxFlashBG
	movs r1, #0
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	ldr r0, .L08046804 @ =0x001F001F
	str r0, [sp]
	ldr r1, .L08046808 @ =gEfxPal
	ldr r2, .L0804680C @ =0x01000100
	mov r0, sp
	bl CpuFastSet
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08046800: .4byte ProcScr_EfxFlashBG
.L08046804: .4byte 0x001F001F
.L08046808: .4byte gEfxPal
.L0804680C: .4byte 0x01000100

	thumb_func_start NewEfxFlashBgBlack
NewEfxFlashBgBlack: @ 0x08046810
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L08046844 @ =gEfxPal
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuFastSet
	bl DisablePalSync
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	blt .L0804683C
	adds r0, r4, #0
	bl Proc_Break
.L0804683C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08046844: .4byte gEfxPal

	thumb_func_start EfxFlashRestorePalSync
EfxFlashRestorePalSync: @ 0x08046848
	push {r4, lr}
	adds r4, r0, #0
	bl EnablePalSync
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start NewEfxWhiteOUT
NewEfxWhiteOUT: @ 0x0804685C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	ldr r0, .L0804687C @ =ProcScr_EfxWhiteOUT
	movs r1, #0
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	strh r6, [r0, #0x30]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0804687C: .4byte ProcScr_EfxWhiteOUT

	thumb_func_start func_fe6_08046880
func_fe6_08046880: @ 0x08046880
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, .L080468D0 @ =gPal
	ldr r4, .L080468D4 @ =gEfxPal
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
	ldrh r2, [r6, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L080468CA
	movs r0, #0
	strh r0, [r6, #0x2c]
	adds r0, r6, #0
	bl Proc_Break
.L080468CA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080468D0: .4byte gPal
.L080468D4: .4byte gEfxPal

	thumb_func_start func_fe6_080468D8
func_fe6_080468D8: @ 0x080468D8
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r7, r0]
	movs r1, #0x30
	ldrsh r0, [r7, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0
	bl Interpolate
	adds r6, r0, #0
	ldr r0, .L08046940 @ =gPal
	ldr r4, .L08046944 @ =gEfxPal
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
	ldrh r2, [r7, #0x30]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08046936
	adds r0, r7, #0
	bl Proc_Break
.L08046936:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08046940: .4byte gPal
.L08046944: .4byte gEfxPal

	thumb_func_start EfxBlackInRestorePalSync
EfxBlackInRestorePalSync: @ 0x08046948
	push {r4, lr}
	adds r4, r0, #0
	bl EnablePalSync
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start NewEfxFlashHPBar
NewEfxFlashHPBar: @ 0x0804695C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r0, .L08046990 @ =gUnk_085CBA20
	movs r1, #4
	bl SpawnProc
	adds r1, r0, #0
	str r6, [r1, #0x5c]
	movs r0, #0
	strh r0, [r1, #0x2c]
	strh r4, [r1, #0x2e]
	strh r5, [r1, #0x30]
	cmp r4, #0
	bne .L0804698A
	adds r0, r1, #0
	bl Proc_Break
.L0804698A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08046990: .4byte gUnk_085CBA20

	thumb_func_start func_fe6_08046994
func_fe6_08046994: @ 0x08046994
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x2c]
	adds r0, #1
	strh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	ldrh r3, [r2, #0x2e]
	lsls r1, r3, #0x10
	cmp r0, r1
	blt .L080469AE
	adds r0, r2, #0
	bl Proc_Break
.L080469AE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080469B4
func_fe6_080469B4: @ 0x080469B4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L080469D8
	ldr r0, .L080469D0 @ =gUnk_081134A4
	ldr r1, .L080469D4 @ =gPal+0x360
	movs r2, #0x10
	bl CpuSet
	b .L080469E2
	.align 2, 0
.L080469D0: .4byte gUnk_081134A4
.L080469D4: .4byte gPal+0x360
.L080469D8:
	ldr r0, .L08046A04 @ =gUnk_081134A4
	ldr r1, .L08046A08 @ =gPal+0x380
	movs r2, #0x10
	bl CpuSet
.L080469E2:
	bl EnablePalSync
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x30]
	lsls r1, r2, #0x10
	cmp r0, r1
	blt .L080469FC
	adds r0, r4, #0
	bl Proc_Break
.L080469FC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08046A04: .4byte gUnk_081134A4
.L08046A08: .4byte gPal+0x380

	thumb_func_start func_fe6_08046A0C
func_fe6_08046A0C: @ 0x08046A0C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L08046A3C
	ldr r0, .L08046A30 @ =gBanimFactionPal
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	ldr r1, .L08046A34 @ =gUnk_08113424
	adds r0, r0, r1
	ldr r1, .L08046A38 @ =gPal+0x360
	movs r2, #0x10
	bl CpuSet
	b .L08046A50
	.align 2, 0
.L08046A30: .4byte gBanimFactionPal
.L08046A34: .4byte gUnk_08113424
.L08046A38: .4byte gPal+0x360
.L08046A3C:
	ldr r0, .L08046A60 @ =gBanimFactionPal
	movs r1, #2
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	ldr r1, .L08046A64 @ =gUnk_08113424
	adds r0, r0, r1
	ldr r1, .L08046A68 @ =gPal+0x380
	movs r2, #0x10
	bl CpuSet
.L08046A50:
	bl EnablePalSync
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08046A60: .4byte gBanimFactionPal
.L08046A64: .4byte gUnk_08113424
.L08046A68: .4byte gPal+0x380

	thumb_func_start NewEfxHpBarColorChange
NewEfxHpBarColorChange: @ 0x08046A6C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r4, .L08046B24 @ =gUnk_Banim_02017774
	ldr r0, .L08046B28 @ =ProcScr_EfxHpBarColorChange
	movs r1, #3
	bl SpawnProc
	str r0, [r4]
	str r5, [r0, #0x5c]
	movs r2, #0
	strh r2, [r0, #0x2c]
	str r2, [r0, #0x44]
	ldr r1, .L08046B2C @ =gUnk_081120F8
	str r1, [r0, #0x48]
	str r2, [r0, #0x4c]
	str r2, [r0, #0x50]
	ldr r0, .L08046B30 @ =gBanimFactionPal
	mov r8, r0
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	ldr r7, .L08046B34 @ =gUnk_08113424
	adds r0, r0, r7
	ldr r6, .L08046B38 @ =gUnk_Banim_0201DF6C
	adds r1, r6, #0
	movs r2, #0x10
	bl EfxSplitColor
	mov r2, r8
	movs r1, #0
	ldrsh r0, [r2, r1]
	lsls r0, r0, #5
	ldr r2, .L08046B3C @ =gUnk_081134C4
	mov sl, r2
	add r0, sl
	ldr r4, .L08046B40 @ =gUnk_Banim_0201DFCC
	adds r1, r4, #0
	movs r2, #0x10
	bl EfxSplitColor
	ldr r5, .L08046B44 @ =gUnk_Banim_0201E02C
	movs r0, #5
	mov sb, r0
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	movs r3, #0x10
	bl func_fe6_0805B88C
	mov r1, r8
	movs r2, #2
	ldrsh r0, [r1, r2]
	lsls r0, r0, #5
	adds r0, r0, r7
	adds r6, #0x30
	adds r1, r6, #0
	movs r2, #0x10
	bl EfxSplitColor
	mov r1, r8
	movs r2, #2
	ldrsh r0, [r1, r2]
	lsls r0, r0, #5
	add r0, sl
	adds r4, #0x30
	adds r1, r4, #0
	movs r2, #0x10
	bl EfxSplitColor
	adds r5, #0x60
	mov r0, sb
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	movs r3, #0x10
	bl func_fe6_0805B88C
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08046B24: .4byte gUnk_Banim_02017774
.L08046B28: .4byte ProcScr_EfxHpBarColorChange
.L08046B2C: .4byte gUnk_081120F8
.L08046B30: .4byte gBanimFactionPal
.L08046B34: .4byte gUnk_08113424
.L08046B38: .4byte gUnk_Banim_0201DF6C
.L08046B3C: .4byte gUnk_081134C4
.L08046B40: .4byte gUnk_Banim_0201DFCC
.L08046B44: .4byte gUnk_Banim_0201E02C

	thumb_func_start EndEfxHPBarColorChange
EndEfxHPBarColorChange: @ 0x08046B48
	push {lr}
	ldr r0, .L08046B58 @ =gUnk_Banim_02017774
	ldr r0, [r0]
	bl Proc_End
	pop {r0}
	bx r0
	.align 2, 0
.L08046B58: .4byte gUnk_Banim_02017774

	thumb_func_start func_fe6_08046B5C
func_fe6_08046B5C: @ 0x08046B5C
	ldr r0, .L08046B68 @ =gUnk_Banim_02017774
	ldr r1, [r0]
	movs r0, #1
	str r0, [r1, #0x50]
	bx lr
	.align 2, 0
.L08046B68: .4byte gUnk_Banim_02017774

	thumb_func_start func_fe6_08046B6C
func_fe6_08046B6C: @ 0x08046B6C
	ldr r0, .L08046B78 @ =gUnk_Banim_02017774
	ldr r1, [r0]
	movs r0, #0
	str r0, [r1, #0x50]
	bx lr
	.align 2, 0
.L08046B78: .4byte gUnk_Banim_02017774

	thumb_func_start EfxHpBarColorChange_Loop
EfxHpBarColorChange_Loop: @ 0x08046B7C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldr r0, [r7, #0x50]
	cmp r0, #1
	beq .L08046BF4
	adds r0, r7, #0
	adds r0, #0x2c
	adds r1, r7, #0
	adds r1, #0x44
	ldr r2, [r7, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt .L08046BA8
	str r0, [r7, #0x4c]
.L08046BA8:
	ldr r4, .L08046C04 @ =gPal+0x360
	ldr r5, .L08046C08 @ =gUnk_Banim_0201DF6C
	ldr r6, .L08046C0C @ =gUnk_Banim_0201DFCC
	ldr r0, .L08046C10 @ =gUnk_Banim_0201E02C
	mov r8, r0
	movs r0, #0x10
	mov sl, r0
	str r0, [sp]
	ldr r0, [r7, #0x4c]
	str r0, [sp, #4]
	movs r0, #5
	mov sb, r0
	str r0, [sp, #8]
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	mov r3, r8
	bl EfxDecodeSplitedPalette
	adds r4, #0x20
	adds r5, #0x30
	adds r6, #0x30
	movs r0, #0x60
	add r8, r0
	mov r0, sl
	str r0, [sp]
	ldr r0, [r7, #0x4c]
	str r0, [sp, #4]
	mov r0, sb
	str r0, [sp, #8]
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	mov r3, r8
	bl EfxDecodeSplitedPalette
	bl EnablePalSync
.L08046BF4:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08046C04: .4byte gPal+0x360
.L08046C08: .4byte gUnk_Banim_0201DF6C
.L08046C0C: .4byte gUnk_Banim_0201DFCC
.L08046C10: .4byte gUnk_Banim_0201E02C
