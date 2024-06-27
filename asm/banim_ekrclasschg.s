	.include "macro.inc"

	.syntax unified

	.section .data
	.global ProcScr_EkrClasschg
ProcScr_EkrClasschg: @ 08605F88
	.incbin "fe6-base.gba", 0x605F88, (0x605FA8 - 0x605F88) @ length: 0020

	.global gUnk_08605FA8
gUnk_08605FA8: @ 08605FA8
	.incbin "fe6-base.gba", 0x605FA8, (0x605FC0 - 0x605FA8) @ length: 0018

	.global gUnk_08605FC0
gUnk_08605FC0: @ 08605FC0
	.incbin "fe6-base.gba", 0x605FC0, (0x60601C - 0x605FC0) @ length: 005C

	.global gUnk_0860601C
gUnk_0860601C: @ 0860601C
	.incbin "fe6-base.gba", 0x60601C, (0x606078 - 0x60601C) @ length: 005C

	.global gUnk_08606078
gUnk_08606078: @ 08606078
	.incbin "fe6-base.gba", 0x606078, (0x6060D4 - 0x606078) @ length: 005C

	.global gUnk_086060D4
gUnk_086060D4: @ 086060D4
	.incbin "fe6-base.gba", 0x6060D4, (0x6060EC - 0x6060D4) @ length: 0018

	.global gUnk_086060EC
gUnk_086060EC: @ 086060EC
	.incbin "fe6-base.gba", 0x6060EC, (0x606104 - 0x6060EC) @ length: 0018

	.global gUnk_08606104
gUnk_08606104: @ 08606104
	.incbin "fe6-base.gba", 0x606104, (0x606124 - 0x606104) @ length: 0020

	.global gUnk_08606124
gUnk_08606124: @ 08606124
	.incbin "fe6-base.gba", 0x606124, (0x60613C - 0x606124) @ length: 0018

	.global gUnk_0860613C
gUnk_0860613C: @ 0860613C
	.incbin "fe6-base.gba", 0x60613C, (0x60615C - 0x60613C) @ length: 0020

	.global gUnk_0860615C
gUnk_0860615C: @ 0860615C
	.incbin "fe6-base.gba", 0x60615C, (0x606174 - 0x60615C) @ length: 0018

	.global gUnk_08606174
gUnk_08606174: @ 08606174
	.incbin "fe6-base.gba", 0x606174, (0x60618C - 0x606174) @ length: 0018

	.section .text

	thumb_func_start EkrClasschgFinished
EkrClasschgFinished: @ 0x0805C840
	ldr r0, .L0805C850 @ =gpProcEkrClasschg
	ldr r0, [r0]
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #1
	beq .L0805C854
	movs r0, #0
	b .L0805C856
	.align 2, 0
.L0805C850: .4byte gpProcEkrClasschg
.L0805C854:
	movs r0, #1
.L0805C856:
	bx lr

	thumb_func_start EndEkrClasschg
EndEkrClasschg: @ 0x0805C858
	push {lr}
	ldr r0, .L0805C868 @ =gpProcEkrClasschg
	ldr r0, [r0]
	bl Proc_End
	pop {r0}
	bx r0
	.align 2, 0
.L0805C868: .4byte gpProcEkrClasschg

	thumb_func_start NewEkrClassChg
NewEkrClassChg: @ 0x0805C86C
	push {r4, r5, lr}
	adds r5, r0, #0
	bl func_fe6_08047300
	ldr r4, .L0805C894 @ =gpProcEkrClasschg
	ldr r0, .L0805C898 @ =ProcScr_EkrClasschg
	movs r1, #3
	bl SpawnProc
	str r0, [r4]
	str r5, [r0, #0x5c]
	movs r2, #0
	movs r1, #0
	strh r1, [r0, #0x2c]
	adds r0, #0x29
	strb r2, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805C894: .4byte gpProcEkrClasschg
.L0805C898: .4byte ProcScr_EkrClasschg

	thumb_func_start func_fe6_0805C89C
func_fe6_0805C89C: @ 0x0805C89C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	adds r5, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r7, #0
	movs r1, #0
	mov r8, r1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #1
	bne .L0805C8F8
	ldr r0, [r4, #0x5c]
	bl DisableEfxStatusUnits
	adds r0, r5, #0
	bl DisableEfxStatusUnits
	adds r0, r5, #0
	bl func_fe6_0805CB6C
	adds r0, r5, #0
	bl func_fe6_0805CC64
	ldr r2, .L0805C8F4 @ =gDispIo
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrb r3, [r2, #1]
	ands r0, r3
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r2, #1]
	b .L0805CB56
	.align 2, 0
.L0805C8F4: .4byte gDispIo
.L0805C8F8:
	cmp r1, #0x5f
	bne .L0805C928
	ldr r0, [r4, #0x5c]
	movs r1, #0xa
	bl NewEfxFlashBgWhite
	ldr r0, .L0805C924 @ =0x0000013B
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	movs r3, #1
	bl func_fe6_0805C804
	movs r0, #1
	movs r1, #0
	movs r2, #8
	bl SetBgOffset
	b .L0805CB56
	.align 2, 0
.L0805C924: .4byte 0x0000013B
.L0805C928:
	cmp r1, #0x6a
	bne .L0805C94C
	ldr r1, [r4, #0x5c]
	ldr r0, .L0805C948 @ =0x0000F3FF
	ldrh r2, [r1, #8]
	ands r0, r2
	strh r0, [r1, #8]
	ldr r1, [r4, #0x5c]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r3, #0
	ldrh r2, [r1, #8]
	orrs r0, r2
	strh r0, [r1, #8]
	b .L0805CB56
	.align 2, 0
.L0805C948: .4byte 0x0000F3FF
.L0805C94C:
	cmp r1, #0x74
	bne .L0805C95C
	ldr r0, [r4, #0x5c]
	movs r1, #0xc
	movs r2, #0
	bl func_fe6_0805CFC0
	b .L0805CB56
.L0805C95C:
	cmp r1, #0x78
	bne .L0805C968
	ldr r0, [r4, #0x5c]
	bl func_fe6_0805CD68
	b .L0805CB56
.L0805C968:
	cmp r1, #0x80
	bne .L0805C974
	movs r0, #1
	bl SetAnimStateHidden
	b .L0805CB56
.L0805C974:
	cmp r1, #0x7e
	bne .L0805C9BC
	ldr r0, [r4, #0x5c]
	movs r1, #2
	str r1, [sp]
	movs r1, #0x38
	movs r2, #7
	movs r3, #0
	bl func_fe6_0804C8D4
	adds r2, r0, #0
	ldr r0, [r4, #0x5c]
	movs r1, #0x40
	str r1, [sp]
	adds r1, r2, #0
	movs r2, #0x38
	movs r3, #0
	bl func_fe6_0805D09C
	ldr r0, [r4, #0x5c]
	ldr r2, .L0805C9B8 @ =func_fe6_0804CD4C
	movs r1, #0x38
	bl func_fe6_0804CC68
	ldr r0, [r4, #0x5c]
	mov r3, r8
	str r3, [sp]
	str r3, [sp, #4]
	movs r1, #0
	movs r2, #0x38
	movs r3, #0x10
	bl func_fe6_0804CD88
	b .L0805CB56
	.align 2, 0
.L0805C9B8: .4byte func_fe6_0804CD4C
.L0805C9BC:
	cmp r1, #0xf2
	bne .L0805CA58
	ldr r0, [r4, #0x5c]
	bl func_fe6_0805CBB0
	ldr r0, [r4, #0x5c]
	bl func_fe6_0805CCE8
	ldr r6, .L0805CA50 @ =gDispIo
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrb r1, [r6, #1]
	ands r0, r1
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r6, #1]
	ldr r0, [r4, #0x5c]
	movs r1, #2
	str r1, [sp]
	movs r1, #0x38
	movs r2, #7
	movs r3, #0x40
	bl func_fe6_0804C8D4
	adds r2, r0, #0
	ldr r0, [r4, #0x5c]
	mov r3, r8
	str r3, [sp]
	adds r1, r2, #0
	movs r2, #0x38
	movs r3, #0x40
	bl func_fe6_0805D09C
	ldr r0, [r4, #0x5c]
	ldr r2, .L0805CA54 @ =func_fe6_0804CD4C
	movs r1, #0x38
	bl func_fe6_0804CC68
	adds r2, r6, #0
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0x44
	strb r7, [r0]
	adds r0, #1
	movs r1, #0x10
	strb r1, [r0]
	adds r0, #1
	strb r7, [r0]
	ldr r0, [r4, #0x5c]
	str r1, [sp]
	mov r2, r8
	str r2, [sp, #4]
	movs r1, #0
	movs r2, #0x38
	movs r3, #0
	bl func_fe6_0804CD88
	movs r0, #0x9e
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #2
	ldrsh r2, [r5, r3]
	b .L0805CB36
	.align 2, 0
.L0805CA50: .4byte gDispIo
.L0805CA54: .4byte func_fe6_0804CD4C
.L0805CA58:
	movs r0, #0x9c
	lsls r0, r0, #1
	cmp r1, r0
	bne .L0805CA88
	movs r0, #0
	bl SetAnimStateUnHidden
	ldr r0, .L0805CA84 @ =0x0000F3FF
	ldrh r1, [r5, #8]
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5, #8]
	adds r0, r5, #0
	movs r1, #0xc
	movs r2, #1
	bl func_fe6_0805CFC0
	b .L0805CB56
	.align 2, 0
.L0805CA84: .4byte 0x0000F3FF
.L0805CA88:
	movs r0, #0x9f
	lsls r0, r0, #1
	cmp r1, r0
	bne .L0805CAAA
	adds r0, r5, #0
	bl func_fe6_0805CD68
	ldr r0, [r4, #0x5c]
	movs r1, #0xa
	bl NewEfxFlashBgWhite
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	b .L0805CB56
.L0805CAAA:
	movs r3, #0x2c
	ldrsh r1, [r4, r3]
	movs r0, #0xa5
	lsls r0, r0, #1
	cmp r1, r0
	bne .L0805CACC
	ldr r0, .L0805CAC8 @ =0x0000F3FF
	ldrh r1, [r5, #8]
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5, #8]
	b .L0805CB56
	.align 2, 0
.L0805CAC8: .4byte 0x0000F3FF
.L0805CACC:
	movs r0, #0xad
	lsls r0, r0, #1
	cmp r1, r0
	bne .L0805CAE4
	bl func_fe6_08047358
	adds r0, r5, #0
	movs r1, #0xa
	movs r2, #0x46
	bl NewEfxWhiteOUT
	b .L0805CB56
.L0805CAE4:
	movs r0, #0xb2
	lsls r0, r0, #1
	cmp r1, r0
	bne .L0805CB48
	adds r0, r5, #0
	movs r1, #0x82
	bl func_fe6_0805CDCC
	adds r0, r5, #0
	movs r1, #0x82
	bl func_fe6_0805CF38
	movs r0, #0
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x5a
	movs r2, #0x28
	movs r3, #0xe
	bl func_fe6_0804CD88
	movs r4, #0x80
	lsls r4, r4, #1
	movs r0, #1
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0x82
	movs r2, #0xa
	adds r3, r4, #0
	bl func_fe6_0804C8D4
	ldr r2, .L0805CB40 @ =func_fe6_0804CD4C
	adds r0, r5, #0
	movs r1, #0x82
	bl func_fe6_0804CC68
	ldr r0, .L0805CB44 @ =0x0000013D
	movs r3, #2
	ldrsh r2, [r5, r3]
	adds r1, r4, #0
.L0805CB36:
	movs r3, #1
	bl func_fe6_0805C804
	b .L0805CB56
	.align 2, 0
.L0805CB40: .4byte func_fe6_0804CD4C
.L0805CB44: .4byte 0x0000013D
.L0805CB48:
	movs r0, #0x94
	lsls r0, r0, #2
	cmp r1, r0
	bne .L0805CB56
	adds r0, r4, #0
	bl Proc_Break
.L0805CB56:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0805CB64
func_fe6_0805CB64: @ 0x0805CB64
	adds r0, #0x29
	movs r1, #1
	strb r1, [r0]
	bx lr

	thumb_func_start func_fe6_0805CB6C
func_fe6_0805CB6C: @ 0x0805CB6C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0805CB9C @ =gUnk_08605FA8
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L0805CBA0 @ =gUnk_081C9F34
	str r1, [r0, #0x48]
	ldr r1, .L0805CBA4 @ =gUnk_08605FC0
	str r1, [r0, #0x4c]
	str r1, [r0, #0x50]
	ldr r1, .L0805CBA8 @ =gUnk_0860601C
	str r1, [r0, #0x54]
	ldr r1, .L0805CBAC @ =gUnk_08606078
	str r1, [r0, #0x58]
	bl SpellFx_SetSomeColorEffect
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805CB9C: .4byte gUnk_08605FA8
.L0805CBA0: .4byte gUnk_081C9F34
.L0805CBA4: .4byte gUnk_08605FC0
.L0805CBA8: .4byte gUnk_0860601C
.L0805CBAC: .4byte gUnk_08606078

	thumb_func_start func_fe6_0805CBB0
func_fe6_0805CBB0: @ 0x0805CBB0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0805CBE0 @ =gUnk_08605FA8
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r1, [r0, #0x44]
	ldr r1, .L0805CBE4 @ =gUnk_081C9FA6
	str r1, [r0, #0x48]
	ldr r1, .L0805CBE8 @ =gUnk_08605FC0
	str r1, [r0, #0x4c]
	str r1, [r0, #0x50]
	ldr r1, .L0805CBEC @ =gUnk_0860601C
	str r1, [r0, #0x54]
	ldr r1, .L0805CBF0 @ =gUnk_08606078
	str r1, [r0, #0x58]
	bl SpellFx_SetSomeColorEffect
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805CBE0: .4byte gUnk_08605FA8
.L0805CBE4: .4byte gUnk_081C9FA6
.L0805CBE8: .4byte gUnk_08605FC0
.L0805CBEC: .4byte gUnk_0860601C
.L0805CBF0: .4byte gUnk_08606078

	thumb_func_start func_fe6_0805CBF4
func_fe6_0805CBF4: @ 0x0805CBF4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r0, #0x2c
	adds r1, r7, #0
	adds r1, #0x44
	ldr r2, [r7, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r5, r0, #0x10
	cmp r5, #0
	blt .L0805CC42
	ldr r6, [r7, #0x4c]
	ldr r0, [r7, #0x50]
	mov r8, r0
	ldr r0, [r7, #0x54]
	ldr r4, [r7, #0x58]
	lsls r5, r5, #2
	adds r0, r5, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	adds r4, r5, r4
	ldr r0, [r4]
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	ldr r0, [r7, #0x5c]
	adds r6, r5, r6
	ldr r1, [r6]
	add r5, r8
	ldr r2, [r5]
	bl SpellFx_WriteBgMap
	b .L0805CC58
.L0805CC42:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r5, r0
	bne .L0805CC58
	bl SpellFx_ClearBG1
	bl SpellFx_ClearColorEffects
	adds r0, r7, #0
	bl Proc_End
.L0805CC58:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0805CC64
func_fe6_0805CC64: @ 0x0805CC64
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0805CC7C @ =gUnk_086060D4
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805CC7C: .4byte gUnk_086060D4

	thumb_func_start func_fe6_0805CC80
func_fe6_0805CC80: @ 0x0805CC80
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x2c]
	adds r0, #1
	strh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	beq .L0805CCC2
	cmp r0, #0x11
	beq .L0805CCC2
	cmp r0, #0x22
	beq .L0805CCC2
	cmp r0, #0x28
	beq .L0805CCC2
	cmp r0, #0x2e
	beq .L0805CCC2
	cmp r0, #0x34
	beq .L0805CCC2
	cmp r0, #0x3a
	beq .L0805CCC2
	cmp r0, #0x3e
	beq .L0805CCC2
	cmp r0, #0x42
	beq .L0805CCC2
	cmp r0, #0x44
	beq .L0805CCC2
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	cmp r0, #0x46
	beq .L0805CCC2
	cmp r0, #0x48
	bne .L0805CCD8
.L0805CCC2:
	movs r0, #0x9f
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r2, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	movs r3, #1
	bl func_fe6_0805C804
	b .L0805CCE2
.L0805CCD8:
	cmp r0, #0x50
	bne .L0805CCE2
	adds r0, r2, #0
	bl Proc_Break
.L0805CCE2:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0805CCE8
func_fe6_0805CCE8: @ 0x0805CCE8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0805CD00 @ =gUnk_086060EC
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805CD00: .4byte gUnk_086060EC

	thumb_func_start func_fe6_0805CD04
func_fe6_0805CD04: @ 0x0805CD04
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x2c]
	adds r0, #1
	strh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x56
	beq .L0805CD42
	cmp r0, #0x58
	beq .L0805CD42
	cmp r0, #0x5a
	beq .L0805CD42
	cmp r0, #0x5c
	beq .L0805CD42
	cmp r0, #0x5e
	beq .L0805CD42
	cmp r0, #0x60
	beq .L0805CD42
	cmp r0, #0x62
	beq .L0805CD42
	cmp r0, #0x64
	beq .L0805CD42
	cmp r0, #0x66
	beq .L0805CD42
	cmp r0, #0x68
	beq .L0805CD42
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	cmp r0, #0x6a
	bne .L0805CD58
.L0805CD42:
	movs r0, #0x9f
	lsls r0, r0, #1
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r2, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	movs r3, #1
	bl func_fe6_0805C804
	b .L0805CD62
.L0805CD58:
	cmp r0, #0x6e
	bne .L0805CD62
	adds r0, r2, #0
	bl Proc_Break
.L0805CD62:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0805CD68
func_fe6_0805CD68: @ 0x0805CD68
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, .L0805CDA4 @ =gUnk_08606104
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r4, [r5, #0x5c]
	ldr r3, .L0805CDA8 @ =gUnk_085E5858
	str r3, [sp]
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	str r0, [r5, #0x60]
	ldr r0, .L0805CDAC @ =gUnk_0812D80C
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0805CDB0 @ =gUnk_0812D374
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805CDA4: .4byte gUnk_08606104
.L0805CDA8: .4byte gUnk_085E5858
.L0805CDAC: .4byte gUnk_0812D80C
.L0805CDB0: .4byte gUnk_0812D374

	thumb_func_start func_fe6_0805CDB4
func_fe6_0805CDB4: @ 0x0805CDB4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0805CDCC
func_fe6_0805CDCC: @ 0x0805CDCC
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, .L0805CEBC @ =gUnk_08606124
	movs r1, #3
	bl SpawnProc
	str r5, [r0, #0x5c]
	movs r6, #0
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r4, [r0, #0x2e]
	ldr r0, .L0805CEC0 @ =gUnk_08127778
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	ldr r0, .L0805CEC4 @ =gUnk_081B4E9C
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	ldr r0, .L0805CEC8 @ =gUnk_081B4F9C
	ldr r1, .L0805CECC @ =gBg1Tm
	movs r2, #1
	str r2, [sp]
	adds r2, #0xff
	str r2, [sp, #4]
	movs r2, #0x20
	movs r3, #0x20
	bl EfxTmCpyBG
	movs r0, #2
	bl EnableBgSync
	bl SpellFx_SetSomeColorEffect
	ldr r0, .L0805CED0 @ =gDispIo
	mov ip, r0
	mov r2, ip
	adds r2, #0x3c
	movs r0, #0x3f
	ldrb r1, [r2]
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	mov r1, ip
	adds r1, #0x44
	movs r0, #0xe
	strb r0, [r1]
	adds r1, #1
	movs r4, #8
	movs r0, #8
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x46
	strb r6, [r0]
	mov r6, ip
	adds r6, #0x37
	movs r3, #0x20
	ldrb r1, [r6]
	orrs r1, r3
	movs r0, #0x21
	rsbs r0, r0, #0
	mov r2, ip
	ldrb r2, [r2, #1]
	ands r0, r2
	movs r2, #0x41
	rsbs r2, r2, #0
	ands r0, r2
	movs r2, #0x80
	orrs r0, r2
	mov r7, ip
	strb r0, [r7, #1]
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	movs r0, #4
	orrs r1, r0
	orrs r1, r4
	movs r0, #0x10
	orrs r1, r0
	strb r1, [r6]
	ldr r0, .L0805CED4 @ =0x0000FFE0
	ldrh r1, [r7, #0x3c]
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	ldr r1, .L0805CED8 @ =0x0000E0FF
	ands r0, r1
	movs r2, #0xe0
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r7, #0x3c]
	mov r0, ip
	adds r0, #0x3d
	ldrb r7, [r0]
	orrs r3, r7
	strb r3, [r0]
	ldr r0, [r5, #0x1c]
	movs r1, #0x80
	lsls r1, r1, #4
	orrs r0, r1
	str r0, [r5, #0x1c]
	ldr r0, .L0805CEDC @ =0x0000F3FF
	ldrh r1, [r5, #8]
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5, #8]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805CEBC: .4byte gUnk_08606124
.L0805CEC0: .4byte gUnk_08127778
.L0805CEC4: .4byte gUnk_081B4E9C
.L0805CEC8: .4byte gUnk_081B4F9C
.L0805CECC: .4byte gBg1Tm
.L0805CED0: .4byte gDispIo
.L0805CED4: .4byte 0x0000FFE0
.L0805CED8: .4byte 0x0000E0FF
.L0805CEDC: .4byte 0x0000F3FF

	thumb_func_start func_fe6_0805CEE0
func_fe6_0805CEE0: @ 0x0805CEE0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, [r4, #0x5c]
	ldr r1, .L0805CF2C @ =gDispIo
	ldrh r0, [r1, #0x22]
	subs r0, #1
	strh r0, [r1, #0x22]
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L0805CF24
	bl SpellFx_ClearBG1
	bl SpellFx_ClearColorEffects
	ldr r0, [r5, #0x1c]
	ldr r1, .L0805CF30 @ =0xFFFFF7FF
	ands r0, r1
	str r0, [r5, #0x1c]
	ldr r0, .L0805CF34 @ =0x0000F3FF
	ldrh r1, [r5, #8]
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5, #8]
	adds r0, r4, #0
	bl Proc_Break
.L0805CF24:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805CF2C: .4byte gDispIo
.L0805CF30: .4byte 0xFFFFF7FF
.L0805CF34: .4byte 0x0000F3FF

	thumb_func_start func_fe6_0805CF38
func_fe6_0805CF38: @ 0x0805CF38
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, .L0805CF54 @ =gUnk_0860613C
	movs r1, #4
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805CF54: .4byte gUnk_0860613C

	thumb_func_start func_fe6_0805CF58
func_fe6_0805CF58: @ 0x0805CF58
	push {r4, lr}
	sub sp, #0x48
	adds r4, r0, #0
	ldr r2, [r4, #0x5c]
	mov r1, sp
	ldrh r0, [r2, #2]
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	strh r0, [r1, #4]
	ldr r0, [r2, #0x3c]
	str r0, [sp, #0x3c]
	ldr r0, [r2, #0x1c]
	ldr r1, .L0805CFB4 @ =0xFFFFF7FF
	ands r0, r1
	str r0, [sp, #0x1c]
	mov r0, sp
	ldrh r1, [r2, #8]
	strh r1, [r0, #8]
	mov r2, sp
	ldr r0, .L0805CFB8 @ =0x0000F3FF
	ands r0, r1
	strh r0, [r2, #8]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2, #8]
	mov r0, sp
	bl BasPutOam
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	bne .L0805CFAA
	adds r0, r4, #0
	bl Proc_Break
.L0805CFAA:
	add sp, #0x48
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805CFB4: .4byte 0xFFFFF7FF
.L0805CFB8: .4byte 0x0000F3FF

	thumb_func_start func_fe6_0805CFBC
func_fe6_0805CFBC: @ 0x0805CFBC
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_0805CFC0
func_fe6_0805CFC0: @ 0x0805CFC0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	ldr r0, .L0805CFE8 @ =gUnk_0860615C
	movs r1, #4
	bl SpawnProc
	adds r1, r0, #0
	str r4, [r1, #0x5c]
	movs r2, #0
	strh r2, [r1, #0x2c]
	strh r5, [r1, #0x2e]
	cmp r6, #0
	bne .L0805CFEC
	strh r2, [r1, #0x32]
	movs r0, #0x10
	strh r0, [r1, #0x34]
	b .L0805CFF2
	.align 2, 0
.L0805CFE8: .4byte gUnk_0860615C
.L0805CFEC:
	movs r0, #0x10
	strh r0, [r1, #0x32]
	strh r2, [r1, #0x34]
.L0805CFF2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805CFF8
func_fe6_0805CFF8: @ 0x0805CFF8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r0, #0x32
	ldrsh r1, [r5, r0]
	movs r4, #0x34
	ldrsh r2, [r5, r4]
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r4, #0x2e
	ldrsh r0, [r5, r4]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	adds r6, r0, #0
	ldr r0, [r5, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L0805D050
	ldr r0, .L0805D044 @ =gpEfxUnitPaletteBackup
	ldr r0, [r0]
	ldr r4, .L0805D048 @ =gPal+0x2E0
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, .L0805D04C @ =0xFFFFFD20
	adds r4, r4, r0
	adds r0, r4, #0
	movs r1, #0x17
	movs r2, #1
	adds r3, r6, #0
	bl EfxPalBlackInOut
	b .L0805D06E
	.align 2, 0
.L0805D044: .4byte gpEfxUnitPaletteBackup
.L0805D048: .4byte gPal+0x2E0
.L0805D04C: .4byte 0xFFFFFD20
.L0805D050:
	ldr r0, .L0805D090 @ =gpEfxUnitPaletteBackup
	ldr r0, [r0, #4]
	ldr r4, .L0805D094 @ =gPal+0x320
	adds r1, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r2, .L0805D098 @ =0xFFFFFCE0
	adds r4, r4, r2
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #1
	adds r3, r6, #0
	bl EfxPalBlackInOut
.L0805D06E:
	bl EnablePalSync
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	ldrh r4, [r5, #0x2e]
	lsls r1, r4, #0x10
	cmp r0, r1
	ble .L0805D088
	adds r0, r5, #0
	bl Proc_Break
.L0805D088:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805D090: .4byte gpEfxUnitPaletteBackup
.L0805D094: .4byte gPal+0x320
.L0805D098: .4byte 0xFFFFFCE0

	thumb_func_start func_fe6_0805D09C
func_fe6_0805D09C: @ 0x0805D09C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	mov r8, r1
	adds r5, r2, #0
	adds r6, r3, #0
	ldr r7, [sp, #0x18]
	ldr r1, .L0805D0D8 @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0805D0DC @ =gUnk_08606174
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	str r6, [r0, #0x44]
	str r7, [r0, #0x48]
	mov r1, r8
	str r1, [r0, #0x64]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805D0D8: .4byte gEfxBgSemaphore
.L0805D0DC: .4byte gUnk_08606174

	thumb_func_start func_fe6_0805D0E0
func_fe6_0805D0E0: @ 0x0805D0E0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r4, [r5, #0x64]
	ldr r1, [r5, #0x44]
	ldr r2, [r5, #0x48]
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r6, #0x2e
	ldrsh r0, [r5, r6]
	str r0, [sp]
	movs r0, #4
	bl Interpolate
	str r0, [r4, #0x4c]
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r5, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0805D11C
	ldr r1, .L0805D124 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	adds r0, r5, #0
	bl Proc_Break
.L0805D11C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805D124: .4byte gEfxBgSemaphore
