	.include "macro.inc"

	.syntax unified

	.section .data
	.global ProcScr_EfxWeaponIcon
ProcScr_EfxWeaponIcon: @ 085CBAC0
	.incbin "fe6-base.gba", 0x5CBAC0, (0x5CBAE8 - 0x5CBAC0) @ length: 0028

	.global gUnk_085CBAE8
gUnk_085CBAE8: @ 085CBAE8
	.incbin "fe6-base.gba", 0x5CBAE8, (0x5CBB18 - 0x5CBAE8) @ length: 0030

	.section .text
	thumb_func_start NewEfxWeaponIcon
NewEfxWeaponIcon: @ 0x080471E4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r0, .L08047220 @ =ProcScr_EfxWeaponIcon
	movs r1, #3
	bl SpawnProc
	movs r2, #0
	strh r2, [r0, #0x2c]
	str r2, [r0, #0x44]
	ldr r1, .L08047224 @ =gUnk_08112144
	str r1, [r0, #0x48]
	str r2, [r0, #0x4c]
	str r2, [r0, #0x50]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	str r4, [r0, #0x54]
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	str r5, [r0, #0x58]
	ldr r1, .L08047228 @ =gUnk_Banim_0201776C
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08047220: .4byte ProcScr_EfxWeaponIcon
.L08047224: .4byte gUnk_08112144
.L08047228: .4byte gUnk_Banim_0201776C

	thumb_func_start EndProcEfxWeaponIcon
EndProcEfxWeaponIcon: @ 0x0804722C
	push {r4, lr}
	ldr r4, .L08047244 @ =gUnk_Banim_0201776C
	ldr r0, [r4]
	cmp r0, #0
	beq .L0804723E
	bl Proc_End
	movs r0, #0
	str r0, [r4]
.L0804723E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08047244: .4byte gUnk_Banim_0201776C

	thumb_func_start func_fe6_08047248
func_fe6_08047248: @ 0x08047248
	ldr r0, .L08047254 @ =gUnk_Banim_0201776C
	ldr r1, [r0]
	movs r0, #1
	str r0, [r1, #0x50]
	bx lr
	.align 2, 0
.L08047254: .4byte gUnk_Banim_0201776C

	thumb_func_start func_fe6_08047258
func_fe6_08047258: @ 0x08047258
	ldr r0, .L08047264 @ =gUnk_Banim_0201776C
	ldr r1, [r0]
	movs r0, #0
	str r0, [r1, #0x50]
	bx lr
	.align 2, 0
.L08047264: .4byte gUnk_Banim_0201776C

	thumb_func_start func_fe6_08047268
func_fe6_08047268: @ 0x08047268
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x50]
	cmp r0, #1
	beq .L080472C6
	bl InitIcons
	adds r0, r4, #0
	adds r0, #0x2c
	adds r1, r4, #0
	adds r1, #0x44
	ldr r2, [r4, #0x48]
	bl EfxAdvanceFrameLut
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt .L0804728E
	str r0, [r4, #0x4c]
.L0804728E:
	ldr r0, [r4, #0x54]
	cmp r0, #0
	beq .L080472A8
	movs r0, #0
	movs r1, #0x1d
	bl ApplyIconPalette
	ldr r0, .L080472CC @ =gPal
	ldr r3, [r4, #0x4c]
	movs r1, #0x1d
	movs r2, #1
	bl EfxPalWhiteInOut
.L080472A8:
	ldr r0, [r4, #0x58]
	cmp r0, #0
	beq .L080472C2
	movs r0, #0
	movs r1, #0x1e
	bl ApplyIconPalette
	ldr r0, .L080472CC @ =gPal
	ldr r3, [r4, #0x4c]
	movs r1, #0x1e
	movs r2, #1
	bl EfxPalWhiteInOut
.L080472C2:
	bl EnablePalSync
.L080472C6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080472CC: .4byte gPal

	thumb_func_start func_fe6_080472D0
func_fe6_080472D0: @ 0x080472D0
	push {r4, lr}
	adds r4, r0, #0
	bl InitIcons
	ldr r0, [r4, #0x54]
	cmp r0, #0
	beq .L080472E6
	movs r0, #0
	movs r1, #0x1d
	bl ApplyIconPalette
.L080472E6:
	ldr r0, [r4, #0x58]
	cmp r0, #0
	beq .L080472F4
	movs r0, #0
	movs r1, #0x1e
	bl ApplyIconPalette
.L080472F4:
	bl EnablePalSync
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08047300
func_fe6_08047300: @ 0x08047300
	push {r4, r5, lr}
	bl GetEkrDragonStateType
	adds r4, r0, #0
	cmp r4, #0
	bne .L0804734C
	ldr r0, .L08047334 @ =gUnk_085CBAE8
	movs r1, #4
	bl SpawnProc
	adds r5, r0, #0
	adds r0, #0x29
	strb r4, [r0]
	strh r4, [r5, #0x2c]
	movs r0, #4
	strh r0, [r5, #0x2e]
	ldr r0, .L08047338 @ =gUnk_Banim_02017770
	ldr r0, [r0]
	cmp r0, #0
	bne .L08047344
	ldr r0, .L0804733C @ =gPal+0xC0
	ldr r1, .L08047340 @ =gPal_Banim
	movs r2, #0x50
	bl CpuFastSet
	b .L08047348
	.align 2, 0
.L08047334: .4byte gUnk_085CBAE8
.L08047338: .4byte gUnk_Banim_02017770
.L0804733C: .4byte gPal+0xC0
.L08047340: .4byte gPal_Banim
.L08047344:
	bl Proc_End
.L08047348:
	ldr r0, .L08047354 @ =gUnk_Banim_02017770
	str r5, [r0]
.L0804734C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08047354: .4byte gUnk_Banim_02017770

	thumb_func_start func_fe6_08047358
func_fe6_08047358: @ 0x08047358
	ldr r0, .L0804736C @ =gUnk_Banim_02017770
	ldr r0, [r0]
	cmp r0, #0
	beq .L08047368
	adds r1, r0, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
.L08047368:
	bx lr
	.align 2, 0
.L0804736C: .4byte gUnk_Banim_02017770

	thumb_func_start func_fe6_08047370
func_fe6_08047370: @ 0x08047370
	push {lr}
	ldr r1, .L08047388 @ =gUnk_Banim_02017770
	ldr r0, [r1]
	cmp r0, #0
	beq .L08047382
	movs r0, #0
	str r0, [r1]
	bl Proc_End
.L08047382:
	pop {r0}
	bx r0
	.align 2, 0
.L08047388: .4byte gUnk_Banim_02017770

	thumb_func_start func_fe6_0804738C
func_fe6_0804738C: @ 0x0804738C
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
	movs r2, #8
	bl Interpolate
	adds r5, r0, #0
	ldr r0, .L080473E8 @ =gPal_Banim
	ldr r4, .L080473EC @ =gPal+0xC0
	adds r1, r4, #0
	movs r2, #0x50
	bl CpuFastSet
	subs r4, #0xc0
	adds r0, r4, #0
	movs r1, #6
	movs r2, #0xa
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
	bne .L080473E0
	adds r0, r6, #0
	bl Proc_Break
.L080473E0:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080473E8: .4byte gPal_Banim
.L080473EC: .4byte gPal+0xC0

	thumb_func_start func_fe6_080473F0
func_fe6_080473F0: @ 0x080473F0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, .L08047428 @ =gPal_Banim
	ldr r4, .L0804742C @ =gPal+0xC0
	adds r1, r4, #0
	movs r2, #0x50
	bl CpuFastSet
	subs r4, #0xc0
	adds r0, r4, #0
	movs r1, #6
	movs r2, #0xa
	movs r3, #8
	bl EfxPalBlackInOut
	adds r0, r5, #0
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #1
	bne .L08047422
	movs r0, #0
	strh r0, [r5, #0x2c]
	adds r0, r5, #0
	bl Proc_Break
.L08047422:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08047428: .4byte gPal_Banim
.L0804742C: .4byte gPal+0xC0

	thumb_func_start func_fe6_08047430
func_fe6_08047430: @ 0x08047430
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r1, #0x2e
	ldrsh r0, [r5, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #8
	movs r2, #0
	bl Interpolate
	adds r4, r0, #0
	ldr r7, .L080474A4 @ =gPal_Banim
	ldr r6, .L080474A8 @ =gPal+0xC0
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #0x50
	bl CpuFastSet
	adds r0, r6, #0
	subs r0, #0xc0
	movs r1, #6
	movs r2, #0xa
	adds r3, r4, #0
	bl EfxPalBlackInOut
	bl EnablePalSync
	ldrh r1, [r5, #0x2c]
	adds r1, #1
	strh r1, [r5, #0x2c]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r2, #0x2e
	ldrsh r0, [r5, r2]
	adds r0, #1
	cmp r1, r0
	bne .L0804749A
	ldr r1, .L080474AC @ =gUnk_Banim_02017770
	movs r0, #0
	str r0, [r1]
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #0x50
	bl CpuFastSet
	bl EnablePalSync
	adds r0, r5, #0
	bl Proc_Break
.L0804749A:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080474A4: .4byte gPal_Banim
.L080474A8: .4byte gPal+0xC0
.L080474AC: .4byte gUnk_Banim_02017770
