
	.include "macro.inc"

	.syntax unified

	.section .data

	.global ProcScr_EfxStatusUnit
ProcScr_EfxStatusUnit: @ 085CBA98
	.incbin "fe6-base.gba", 0x5CBA98, (0x5CBAC0 - 0x5CBA98) @ length: 0028

	.section .text
	thumb_func_start NewEfxStatusUnit
NewEfxStatusUnit: @ 0x08046DA0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L08046DB8
	ldr r0, .L08046DB4 @ =gpEkrBattleUnitLeft
	b .L08046DBA
	.align 2, 0
.L08046DB4: .4byte gpEkrBattleUnitLeft
.L08046DB8:
	ldr r0, .L08046E40 @ =gpEkrBattleUnitRight
.L08046DBA:
	ldr r6, [r0]
	ldr r0, .L08046E44 @ =ProcScr_EfxStatusUnit
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	adds r0, #0x29
	movs r1, #0
	strb r1, [r0]
	str r5, [r4, #0x5c]
	strh r1, [r4, #0x2c]
	str r1, [r4, #0x44]
	ldr r0, .L08046E48 @ =gUnk_08112122
	str r0, [r4, #0x48]
	adds r0, r6, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	str r0, [r4, #0x4c]
	ldr r0, .L08046E4C @ =gEkrDebugModeMaybe
	ldrh r0, [r0]
	cmp r0, #1
	bne .L08046DEC
	str r1, [r4, #0x4c]
.L08046DEC:
	str r1, [r4, #0x50]
	strh r1, [r4, #0x36]
	strh r1, [r4, #0x34]
	strh r1, [r4, #0x32]
	adds r0, r5, #0
	bl GetAnimPosition
	ldr r1, .L08046E50 @ =gUnk_Banim_02017764
	lsls r0, r0, #2
	adds r0, r0, r1
	str r4, [r0]
	adds r0, r5, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L08046E5C
	ldr r5, .L08046E54 @ =gpEfxUnitPaletteBackup
	ldr r0, [r5]
	ldr r4, .L08046E58 @ =gFadeComponents
	adds r1, r4, #0
	movs r2, #0x10
	bl EfxSplitColor
	ldr r0, [r5]
	adds r5, r4, #0
	adds r5, #0x30
	adds r1, r5, #0
	movs r2, #0x10
	bl EfxSplitColorPetrify
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r4, r0
	movs r0, #0x10
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #0x10
	bl func_fe6_0805B88C
	b .L08046E8C
	.align 2, 0
.L08046E40: .4byte gpEkrBattleUnitRight
.L08046E44: .4byte ProcScr_EfxStatusUnit
.L08046E48: .4byte gUnk_08112122
.L08046E4C: .4byte gEkrDebugModeMaybe
.L08046E50: .4byte gUnk_Banim_02017764
.L08046E54: .4byte gpEfxUnitPaletteBackup
.L08046E58: .4byte gFadeComponents
.L08046E5C:
	ldr r5, .L08046E94 @ =gpEfxUnitPaletteBackup
	ldr r0, [r5, #4]
	ldr r4, .L08046E98 @ =gFadeComponents+0x60
	adds r1, r4, #0
	movs r2, #0x10
	bl EfxSplitColor
	ldr r0, [r5, #4]
	adds r5, r4, #0
	adds r5, #0x30
	adds r1, r5, #0
	movs r2, #0x10
	bl EfxSplitColorPetrify
	movs r0, #0xa8
	lsls r0, r0, #2
	adds r2, r4, r0
	movs r0, #0x10
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #0x10
	bl func_fe6_0805B88C
.L08046E8C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08046E94: .4byte gpEfxUnitPaletteBackup
.L08046E98: .4byte gFadeComponents+0x60

	thumb_func_start EndEfxStatusUnits
EndEfxStatusUnits: @ 0x08046E9C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, .L08046ED4 @ =gUnk_Banim_02017764
	bl GetAnimPosition
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r0, [r0]
	cmp r0, #0
	beq .L08046ECE
	adds r0, r4, #0
	bl GetAnimPosition
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r0, [r0]
	bl Proc_End
	adds r0, r4, #0
	bl GetAnimPosition
	lsls r0, r0, #2
	adds r0, r0, r5
	movs r1, #0
	str r1, [r0]
.L08046ECE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08046ED4: .4byte gUnk_Banim_02017764

	thumb_func_start DisableEfxStatusUnits
DisableEfxStatusUnits: @ 0x08046ED8
	push {r4, lr}
	ldr r4, .L08046EF4 @ =gUnk_Banim_02017764
	bl GetAnimPosition
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	adds r0, #0x29
	movs r1, #1
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08046EF4: .4byte gUnk_Banim_02017764

	thumb_func_start EnableEfxStatusUnits
EnableEfxStatusUnits: @ 0x08046EF8
	push {r4, lr}
	ldr r4, .L08046F14 @ =gUnk_Banim_02017764
	bl GetAnimPosition
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	adds r0, #0x29
	movs r1, #0
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08046F14: .4byte gUnk_Banim_02017764

	thumb_func_start SetUnitEfxDebuff
SetUnitEfxDebuff: @ 0x08046F18
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	ldr r4, .L08046F44 @ =gUnk_Banim_02017764
	bl GetAnimPosition
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	str r5, [r0, #0x4c]
	cmp r5, #0
	bne .L08046F3C
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl func_fe6_08046F64
.L08046F3C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08046F44: .4byte gUnk_Banim_02017764

	thumb_func_start GetUnitEfxDebuff
GetUnitEfxDebuff: @ 0x08046F48
	push {r4, lr}
	ldr r4, .L08046F60 @ =gUnk_Banim_02017764
	bl GetAnimPosition
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r0, [r0, #0x4c]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L08046F60: .4byte gUnk_Banim_02017764

	thumb_func_start func_fe6_08046F64
func_fe6_08046F64: @ 0x08046F64
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	mov r8, r1
	adds r6, r2, #0
	adds r7, r3, #0
	bl GetEkrDragonStateType
	adds r5, r0, #0
	adds r0, r4, #0
	bl GetAnimPosition
	cmp r0, #0
	bne .L08046FE8
	ldr r0, .L08046FDC @ =gpEfxUnitPaletteBackup
	ldr r0, [r0]
	ldr r4, .L08046FE0 @ =gPal+0x2E0
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, .L08046FE4 @ =0xFFFFFD20
	adds r4, r4, r0
	str r6, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	movs r1, #0x17
	movs r2, #1
	mov r3, r8
	bl EfxPalFlashingInOut
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq .L08046FB4
	movs r0, #0
	bl RestoreBodyFlashingPalForManakete
.L08046FB4:
	movs r0, #0x10
	ands r0, r5
	cmp r0, #0
	beq .L08046FC2
	movs r0, #0
	bl RestoreBodyFlashingPalForIdunn
.L08046FC2:
	movs r0, #0x11
	ands r0, r5
	cmp r0, #0
	beq .L0804703E
	str r6, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	movs r1, #6
	movs r2, #1
	mov r3, r8
	bl EfxPalFlashingInOut
	b .L0804703E
	.align 2, 0
.L08046FDC: .4byte gpEfxUnitPaletteBackup
.L08046FE0: .4byte gPal+0x2E0
.L08046FE4: .4byte 0xFFFFFD20
.L08046FE8:
	ldr r0, .L0804704C @ =gpEfxUnitPaletteBackup
	ldr r0, [r0, #4]
	ldr r4, .L08047050 @ =gPal+0x320
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, .L08047054 @ =0xFFFFFCE0
	adds r4, r4, r0
	str r6, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #1
	mov r3, r8
	bl EfxPalFlashingInOut
	movs r0, #2
	ands r0, r5
	cmp r0, #0
	beq .L08047018
	movs r0, #1
	bl RestoreBodyFlashingPalForManakete
.L08047018:
	movs r0, #0x20
	ands r0, r5
	cmp r0, #0
	beq .L08047026
	movs r0, #1
	bl RestoreBodyFlashingPalForIdunn
.L08047026:
	movs r0, #0x22
	ands r0, r5
	cmp r0, #0
	beq .L0804703E
	str r6, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	movs r1, #7
	movs r2, #1
	mov r3, r8
	bl EfxPalFlashingInOut
.L0804703E:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0804704C: .4byte gpEfxUnitPaletteBackup
.L08047050: .4byte gPal+0x320
.L08047054: .4byte 0xFFFFFCE0

	thumb_func_start func_fe6_08047058
func_fe6_08047058: @ 0x08047058
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetUnitEfxDebuff
	cmp r0, #0
	beq .L0804714E
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #1
	beq .L0804714E
	ldr r1, [r4, #0x4c]
	ldr r0, [r4, #0x50]
	cmp r1, r0
	beq .L08047082
	movs r0, #0
	strh r0, [r4, #0x2c]
	str r0, [r4, #0x44]
	str r1, [r4, #0x50]
.L08047082:
	adds r0, r4, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L080470D2
	ldr r0, [r4, #0x4c]
	cmp r0, #2
	beq .L080470BA
	cmp r0, #2
	bgt .L080470A8
	cmp r0, #1
	beq .L080470B2
	b .L080470CC
.L080470A8:
	cmp r0, #3
	beq .L080470CC
	cmp r0, #4
	beq .L080470C2
	b .L080470CC
.L080470B2:
	movs r0, #0
	strh r1, [r4, #0x32]
	strh r0, [r4, #0x34]
	b .L080470D0
.L080470BA:
	movs r0, #0
	strh r0, [r4, #0x32]
	strh r0, [r4, #0x34]
	b .L080470D0
.L080470C2:
	movs r0, #0
	strh r1, [r4, #0x32]
	strh r0, [r4, #0x34]
	strh r0, [r4, #0x36]
	b .L080470D2
.L080470CC:
	strh r1, [r4, #0x32]
	strh r1, [r4, #0x34]
.L080470D0:
	strh r1, [r4, #0x36]
.L080470D2:
	ldr r0, [r4, #0x4c]
	cmp r0, #3
	beq .L080470FA
	cmp r0, #3
	bgt .L080470E2
	cmp r0, #1
	blt .L0804714A
	b .L080470E6
.L080470E2:
	cmp r0, #4
	bne .L0804714A
.L080470E6:
	ldr r0, [r4, #0x5c]
	movs r2, #0x32
	ldrsh r1, [r4, r2]
	movs r3, #0x34
	ldrsh r2, [r4, r3]
	movs r5, #0x36
	ldrsh r3, [r4, r5]
	bl func_fe6_08046F64
	b .L0804714A
.L080470FA:
	ldr r0, [r4, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L0804712C
	ldr r0, .L08047124 @ =gPal+0x2E0
	ldr r1, .L08047128 @ =gFadeComponents
	adds r2, r1, #0
	adds r2, #0x30
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r3, r1, r6
	movs r5, #0x10
	str r5, [sp]
	movs r6, #0x32
	ldrsh r4, [r4, r6]
	str r4, [sp, #4]
	str r5, [sp, #8]
	bl EfxDecodeSplitedPalette
	b .L0804714A
	.align 2, 0
.L08047124: .4byte gPal+0x2E0
.L08047128: .4byte gFadeComponents
.L0804712C:
	ldr r0, .L08047158 @ =gPal+0x320
	ldr r1, .L0804715C @ =gFadeComponents+0x60
	adds r2, r1, #0
	adds r2, #0x30
	movs r5, #0xa8
	lsls r5, r5, #2
	adds r3, r1, r5
	movs r5, #0x10
	str r5, [sp]
	movs r6, #0x32
	ldrsh r4, [r4, r6]
	str r4, [sp, #4]
	str r5, [sp, #8]
	bl EfxDecodeSplitedPalette
.L0804714A:
	bl EnablePalSync
.L0804714E:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08047158: .4byte gPal+0x320
.L0804715C: .4byte gFadeComponents+0x60

	thumb_func_start func_fe6_08047160
func_fe6_08047160: @ 0x08047160
	push {r4, r5, lr}
	adds r4, r0, #0
	bl GetEkrDragonStateType
	adds r5, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L080471A8
	ldr r0, .L080471A0 @ =gpEfxUnitPaletteBackup
	ldr r0, [r0]
	ldr r1, .L080471A4 @ =gPal+0x2E0
	movs r2, #8
	bl CpuFastSet
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq .L0804718E
	movs r0, #0
	bl RestoreBodyFlashingPalForManakete
.L0804718E:
	movs r0, #0x10
	ands r0, r5
	cmp r0, #0
	beq .L080471D0
	movs r0, #0
	bl RestoreBodyFlashingPalForIdunn
	b .L080471D0
	.align 2, 0
.L080471A0: .4byte gpEfxUnitPaletteBackup
.L080471A4: .4byte gPal+0x2E0
.L080471A8:
	ldr r0, .L080471DC @ =gpEfxUnitPaletteBackup
	ldr r0, [r0, #4]
	ldr r1, .L080471E0 @ =gPal+0x320
	movs r2, #8
	bl CpuFastSet
	movs r0, #2
	ands r0, r5
	cmp r0, #0
	beq .L080471C2
	movs r0, #1
	bl RestoreBodyFlashingPalForManakete
.L080471C2:
	movs r0, #0x20
	ands r0, r5
	cmp r0, #0
	beq .L080471D0
	movs r0, #1
	bl RestoreBodyFlashingPalForIdunn
.L080471D0:
	bl EnablePalSync
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080471DC: .4byte gpEfxUnitPaletteBackup
.L080471E0: .4byte gPal+0x320
