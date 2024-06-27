	.include "macro.inc"
	.syntax unified

	thumb_func_start NewEfxDamageMojiEffect
NewEfxDamageMojiEffect: @ 0x08056A18
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, .L08056A38 @ =ProcScr_EfxDamageMojiEffect
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	adds r0, #0x29
	strb r5, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08056A38: .4byte ProcScr_EfxDamageMojiEffect

	thumb_func_start func_fe6_08056A3C
func_fe6_08056A3C: @ 0x08056A3C
	push {lr}
	adds r1, r0, #0
	ldrh r0, [r1, #0x2c]
	adds r0, #1
	strh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08056A5A
	ldr r0, [r1, #0x5c]
	adds r1, #0x29
	ldrb r1, [r1]
	bl func_fe6_08056A68
	b .L08056A64
.L08056A5A:
	cmp r0, #0xa
	bne .L08056A64
	adds r0, r1, #0
	bl Proc_Break
.L08056A64:
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08056A68
func_fe6_08056A68: @ 0x08056A68
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, .L08056A8C @ =gUnk_085D348C
	movs r1, #3
	bl SpawnProc
	adds r6, r0, #0
	str r5, [r6, #0x5c]
	movs r0, #0
	strh r0, [r6, #0x2c]
	cmp r4, #0
	bne .L08056A94
	movs r0, #0x32
	strh r0, [r6, #0x2e]
	ldr r4, .L08056A90 @ =gUnk_085CDCA4
	b .L08056A9A
	.align 2, 0
.L08056A8C: .4byte gUnk_085D348C
.L08056A90: .4byte gUnk_085CDCA4
.L08056A94:
	movs r0, #0x32
	strh r0, [r6, #0x2e]
	ldr r4, .L08056AD4 @ =gUnk_085CDD18
.L08056A9A:
	adds r0, r5, #0
	bl GetAnimPosition
	movs r2, #0xa2
	lsls r2, r2, #7
	cmp r0, #0
	bne .L08056AAC
	movs r2, #0xc2
	lsls r2, r2, #7
.L08056AAC:
	movs r1, #2
	ldrsh r0, [r5, r1]
	movs r3, #4
	ldrsh r1, [r5, r3]
	subs r1, #0x28
	str r2, [sp]
	movs r2, #0
	str r2, [sp, #4]
	movs r2, #3
	str r2, [sp, #8]
	adds r2, r4, #0
	movs r3, #2
	bl NewEkrsubAnimeEmulator
	str r0, [r6, #0x60]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08056AD4: .4byte gUnk_085CDD18

	thumb_func_start func_fe6_08056AD8
func_fe6_08056AD8: @ 0x08056AD8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x60]
	ldr r0, [r4, #0x5c]
	ldrh r0, [r0, #2]
	strh r0, [r1, #0x32]
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L08056B00
	ldr r0, [r4, #0x60]
	bl Proc_End
	adds r0, r4, #0
	bl Proc_Break
.L08056B00:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08056B08
func_fe6_08056B08: @ 0x08056B08
	push {r4, lr}
	adds r4, r0, #0
	bl SpellFx_SetBG1Position
	ldr r0, .L08056B24 @ =gUnk_085D34A4
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08056B24: .4byte gUnk_085D34A4

	thumb_func_start func_fe6_08056B28
func_fe6_08056B28: @ 0x08056B28
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08056B48
	ldr r0, [r4, #0x5c]
	bl func_fe6_08056B58
	ldr r0, [r4, #0x5c]
	bl func_fe6_08056BD0
	b .L08056B52
.L08056B48:
	cmp r0, #0x11
	bne .L08056B52
	adds r0, r4, #0
	bl Proc_Break
.L08056B52:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08056B58
func_fe6_08056B58: @ 0x08056B58
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, .L08056B94 @ =gUnk_085D34BC
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r0, .L08056B98 @ =gUnk_08122A3C
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	ldr r0, .L08056B9C @ =gUnk_08123B1C
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	ldr r0, [r4, #0x5c]
	ldr r1, .L08056BA0 @ =gUnk_08123D1C
	ldr r2, .L08056BA4 @ =gUnk_081241BC
	bl SpellFx_WriteBgMap
	bl SpellFx_SetSomeColorEffect
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08056B94: .4byte gUnk_085D34BC
.L08056B98: .4byte gUnk_08122A3C
.L08056B9C: .4byte gUnk_08123B1C
.L08056BA0: .4byte gUnk_08123D1C
.L08056BA4: .4byte gUnk_081241BC

	thumb_func_start func_fe6_08056BA8
func_fe6_08056BA8: @ 0x08056BA8
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x11
	bne .L08056BC8
	bl SpellFx_ClearBG1
	bl SpellFx_ClearColorEffects
	adds r0, r4, #0
	bl Proc_Break
.L08056BC8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08056BD0
func_fe6_08056BD0: @ 0x08056BD0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L08056BF4 @ =gUnk_085D34D4
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L08056BF8 @ =gUnk_0811AE34
	str r1, [r0, #0x48]
	ldr r1, .L08056BFC @ =gUnk_08123B1C
	str r1, [r0, #0x4c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08056BF4: .4byte gUnk_085D34D4
.L08056BF8: .4byte gUnk_0811AE34
.L08056BFC: .4byte gUnk_08123B1C

	thumb_func_start func_fe6_08056C00
func_fe6_08056C00: @ 0x08056C00
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	blt .L08056C26
	ldr r0, [r4, #0x4c]
	lsls r1, r1, #5
	adds r0, r0, r1
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	b .L08056C34
.L08056C26:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne .L08056C34
	adds r0, r4, #0
	bl Proc_Break
.L08056C34:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08056C3C
func_fe6_08056C3C: @ 0x08056C3C
	push {r4, lr}
	adds r4, r0, #0
	bl SpellFx_SetBG1Position
	ldr r0, .L08056C58 @ =gUnk_085D34F4
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08056C58: .4byte gUnk_085D34F4

	thumb_func_start func_fe6_08056C5C
func_fe6_08056C5C: @ 0x08056C5C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	adds r1, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L08056C80
	ldr r0, [r4, #0x5c]
	movs r1, #4
	bl NewEfxFlashBgWhite
	b .L08056C96
.L08056C80:
	cmp r0, #4
	bne .L08056C8C
	adds r0, r1, #0
	bl func_fe6_08056C9C
	b .L08056C96
.L08056C8C:
	cmp r0, #0x18
	bne .L08056C96
	adds r0, r4, #0
	bl Proc_Break
.L08056C96:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08056C9C
func_fe6_08056C9C: @ 0x08056C9C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, .L08056CFC @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L08056D00 @ =gUnk_085D350C
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	str r0, [r5, #0x44]
	ldr r0, .L08056D04 @ =gUnk_0811AE76
	str r0, [r5, #0x48]
	ldr r0, .L08056D08 @ =gUnk_085D3524
	str r0, [r5, #0x4c]
	str r0, [r5, #0x50]
	ldr r0, .L08056D0C @ =gUnk_08124B64
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	ldr r0, .L08056D10 @ =gUnk_0812479C
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	bl SpellFx_SetSomeColorEffect
	ldr r0, .L08056D14 @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L08056D22
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L08056D18
	movs r0, #1
	movs r1, #0x18
	movs r2, #0
	bl SetBgOffset
	b .L08056D22
	.align 2, 0
.L08056CFC: .4byte gEfxBgSemaphore
.L08056D00: .4byte gUnk_085D350C
.L08056D04: .4byte gUnk_0811AE76
.L08056D08: .4byte gUnk_085D3524
.L08056D0C: .4byte gUnk_08124B64
.L08056D10: .4byte gUnk_0812479C
.L08056D14: .4byte gEkrDistanceType
.L08056D18:
	movs r0, #1
	movs r1, #0xe8
	movs r2, #0
	bl SetBgOffset
.L08056D22:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08056D28
func_fe6_08056D28: @ 0x08056D28
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	blt .L08056D56
	ldr r1, [r4, #0x4c]
	ldr r3, [r4, #0x50]
	ldr r0, [r4, #0x5c]
	lsls r2, r2, #2
	adds r1, r2, r1
	ldr r1, [r1]
	adds r2, r2, r3
	ldr r2, [r2]
	bl SpellFx_WriteBgMap
	b .L08056D74
.L08056D56:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne .L08056D74
	bl SpellFx_ClearBG1
	ldr r1, .L08056D7C @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	bl SpellFx_ClearColorEffects
	adds r0, r4, #0
	bl Proc_Break
.L08056D74:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08056D7C: .4byte gEfxBgSemaphore
