	.include "macro.inc"

	.syntax unified

	thumb_func_start CheckEkrTriangleInvalid
CheckEkrTriangleInvalid: @ 0x0805E560
	ldr r0, .L0805E56C @ =gEkrTriangleInvalid
	ldr r0, [r0]
	cmp r0, #1
	beq .L0805E570
	movs r0, #0
	b .L0805E572
	.align 2, 0
.L0805E56C: .4byte gEkrTriangleInvalid
.L0805E570:
	movs r0, #1
.L0805E572:
	bx lr

	thumb_func_start DebugEkrTriangleMsg
DebugEkrTriangleMsg: @ 0x0805E574
	bx lr
	.align 2, 0

	thumb_func_start NewEkrTriangle
NewEkrTriangle: @ 0x0805E578
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0805E594 @ =ProcScr_EkrTriangle
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	ldr r1, .L0805E598 @ =gEkrTriangleInvalid
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805E594: .4byte ProcScr_EkrTriangle
.L0805E598: .4byte gEkrTriangleInvalid

	thumb_func_start func_fe6_0805E59C
func_fe6_0805E59C: @ 0x0805E59C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0
	mov sb, r0
	mov sl, r0
	mov r8, r0
	movs r7, #0
	ldr r0, [r6, #0x5c]
	bl GetAnimPosition
	cmp r0, #0
	bne .L0805E5C8
	ldr r0, .L0805E5C4 @ =gpEkrBattleUnitLeft
	b .L0805E5CA
	.align 2, 0
.L0805E5C4: .4byte gpEkrBattleUnitLeft
.L0805E5C8:
	ldr r0, .L0805E618 @ =gpEkrBattleUnitRight
.L0805E5CA:
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrb r5, [r0, #4]
	cmp r5, #0xc
	bge .L0805E5D6
	b .L0805E6D8
.L0805E5D6:
	cmp r5, #0xf
	ble .L0805E5DC
	b .L0805E6D8
.L0805E5DC:
	ldr r0, .L0805E61C @ =gpEkrTriangleUnits
	ldr r1, [r0]
	ldr r0, [r1, #4]
	ldrb r0, [r0, #4]
	cmp r0, #0xc
	bne .L0805E5EC
	movs r2, #0
	mov sb, r2
.L0805E5EC:
	cmp r0, #0xd
	bne .L0805E5F4
	movs r2, #0
	mov sb, r2
.L0805E5F4:
	cmp r0, #0xe
	bne .L0805E5FC
	movs r2, #1
	mov sb, r2
.L0805E5FC:
	cmp r0, #0xf
	bne .L0805E604
	movs r0, #1
	mov sb, r0
.L0805E604:
	adds r0, r1, #0
	bl GetUnitEquippedWeapon
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne .L0805E620
	movs r0, #1
	b .L0805E626
	.align 2, 0
.L0805E618: .4byte gpEkrBattleUnitRight
.L0805E61C: .4byte gpEkrTriangleUnits
.L0805E620:
	adds r0, r4, #0
	bl GetItemKind
.L0805E626:
	cmp r0, #1
	beq .L0805E630
	cmp r0, #2
	beq .L0805E636
	b .L0805E648
.L0805E630:
	movs r1, #0
	mov r8, r1
	b .L0805E648
.L0805E636:
	adds r0, r4, #0
	bl GetItemIid
	movs r2, #1
	mov r8, r2
	cmp r0, #0x20
	bne .L0805E648
	movs r0, #2
	mov r8, r0
.L0805E648:
	ldr r0, .L0805E684 @ =gpEkrTriangleUnits
	ldr r1, [r0, #4]
	ldr r0, [r1, #4]
	ldrb r0, [r0, #4]
	cmp r0, #0xc
	bne .L0805E658
	movs r2, #0
	mov sl, r2
.L0805E658:
	cmp r0, #0xd
	bne .L0805E660
	movs r2, #0
	mov sl, r2
.L0805E660:
	cmp r0, #0xe
	bne .L0805E668
	movs r2, #1
	mov sl, r2
.L0805E668:
	cmp r0, #0xf
	bne .L0805E670
	movs r0, #1
	mov sl, r0
.L0805E670:
	adds r0, r1, #0
	bl GetUnitEquippedWeapon
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne .L0805E688
	movs r0, #1
	b .L0805E68E
	.align 2, 0
.L0805E684: .4byte gpEkrTriangleUnits
.L0805E688:
	adds r0, r4, #0
	bl GetItemKind
.L0805E68E:
	cmp r0, #1
	beq .L0805E698
	cmp r0, #2
	beq .L0805E69C
	b .L0805E6AA
.L0805E698:
	movs r7, #0
	b .L0805E6AA
.L0805E69C:
	adds r0, r4, #0
	bl GetItemIid
	movs r7, #1
	cmp r0, #0x20
	bne .L0805E6AA
	movs r7, #2
.L0805E6AA:
	ldr r0, [r6, #0x5c]
	str r7, [sp]
	mov r1, sb
	mov r2, sl
	mov r3, r8
	bl func_fe6_0805EA38
	ldr r0, .L0805E6D0 @ =gpEkrBattleUnitRight
	ldr r0, [r0]
	adds r0, #0x4a
	ldrh r0, [r0]
	bl GetItemIid
	cmp r0, #0x20
	bne .L0805E780
	ldr r1, .L0805E6D4 @ =gEkrTriangleInvalid
	movs r0, #0
	b .L0805E784
	.align 2, 0
.L0805E6D0: .4byte gpEkrBattleUnitRight
.L0805E6D4: .4byte gEkrTriangleInvalid
.L0805E6D8:
	ldr r0, .L0805E704 @ =gpEkrTriangleUnits
	ldr r1, [r0]
	ldr r0, [r1, #4]
	ldrb r0, [r0, #4]
	cmp r0, #0x2a
	bne .L0805E6E8
	movs r2, #0
	mov sb, r2
.L0805E6E8:
	cmp r0, #0x2b
	bne .L0805E6F0
	movs r0, #1
	mov sb, r0
.L0805E6F0:
	adds r0, r1, #0
	bl GetUnitEquippedWeapon
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne .L0805E708
	movs r0, #1
	b .L0805E712
	.align 2, 0
.L0805E704: .4byte gpEkrTriangleUnits
.L0805E708:
	adds r0, r4, #0
	bl GetItemKind
	cmp r0, #0
	beq .L0805E71C
.L0805E712:
	cmp r0, #1
	bne .L0805E720
	movs r1, #0
	mov r8, r1
	b .L0805E720
.L0805E71C:
	movs r2, #1
	mov r8, r2
.L0805E720:
	ldr r0, .L0805E74C @ =gpEkrTriangleUnits
	ldr r1, [r0, #4]
	ldr r0, [r1, #4]
	ldrb r0, [r0, #4]
	cmp r0, #0x2a
	bne .L0805E730
	movs r2, #0
	mov sl, r2
.L0805E730:
	cmp r0, #0x2b
	bne .L0805E738
	movs r0, #1
	mov sl, r0
.L0805E738:
	adds r0, r1, #0
	bl GetUnitEquippedWeapon
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne .L0805E750
	movs r0, #1
	b .L0805E75A
	.align 2, 0
.L0805E74C: .4byte gpEkrTriangleUnits
.L0805E750:
	adds r0, r4, #0
	bl GetItemKind
	cmp r0, #0
	beq .L0805E762
.L0805E75A:
	cmp r0, #1
	bne .L0805E764
	movs r7, #0
	b .L0805E764
.L0805E762:
	movs r7, #1
.L0805E764:
	ldr r0, [r6, #0x5c]
	str r7, [sp]
	mov r1, sb
	mov r2, sl
	mov r3, r8
	bl func_fe6_0805E7A0
	cmp r5, #0x2a
	bne .L0805E780
	ldr r1, .L0805E77C @ =gEkrTriangleInvalid
	movs r0, #0
	b .L0805E784
	.align 2, 0
.L0805E77C: .4byte gEkrTriangleInvalid
.L0805E780:
	ldr r1, .L0805E79C @ =gEkrTriangleInvalid
	movs r0, #1
.L0805E784:
	str r0, [r1]
	adds r0, r6, #0
	bl Proc_Break
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805E79C: .4byte gEkrTriangleInvalid

	thumb_func_start func_fe6_0805E7A0
func_fe6_0805E7A0: @ 0x0805E7A0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	mov r8, r3
	ldr r7, [sp, #0x18]
	ldr r0, .L0805E7D4 @ =gUnk_0860632C
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r5, [r0, #0x44]
	str r6, [r0, #0x48]
	mov r1, r8
	str r1, [r0, #0x4c]
	str r7, [r0, #0x50]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
.L0805E7D4: .4byte gUnk_0860632C

	thumb_func_start func_fe6_0805E7D8
func_fe6_0805E7D8: @ 0x0805E7D8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x5c]
	bl GetAnimAnotherSide
	adds r5, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xa
	bne .L0805E7FE
	ldr r0, [r4, #0x5c]
	ldr r2, [r4, #0x44]
	ldr r3, [r4, #0x4c]
	movs r1, #0
	bl func_fe6_0805E964
.L0805E7FE:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0x1c
	bne .L0805E80C
	adds r0, r5, #0
	movs r1, #6
	bl NewEfxFlashBgWhite
.L0805E80C:
	ldrh r3, [r4, #0x2c]
	cmp r3, #0x22
	bne .L0805E83E
	ldr r2, [r4, #0x44]
	ldr r3, [r4, #0x4c]
	adds r0, r5, #0
	movs r1, #0
	bl func_fe6_0805E890
	ldr r0, [r4, #0x5c]
	ldr r2, [r4, #0x48]
	ldr r3, [r4, #0x50]
	movs r1, #1
	bl func_fe6_0805E964
	movs r0, #0x9a
	lsls r0, r0, #2
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	movs r3, #1
	bl func_fe6_0805C804
.L0805E83E:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0x33
	bne .L0805E84C
	adds r0, r5, #0
	movs r1, #6
	bl NewEfxFlashBgWhite
.L0805E84C:
	ldrh r3, [r4, #0x2c]
	cmp r3, #0x39
	bne .L0805E872
	ldr r2, [r4, #0x48]
	ldr r3, [r4, #0x50]
	adds r0, r5, #0
	movs r1, #1
	bl func_fe6_0805E890
	movs r0, #0x9a
	lsls r0, r0, #2
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r2, [r4, #0x5c]
	movs r3, #2
	ldrsh r2, [r2, r3]
	movs r3, #1
	bl func_fe6_0805C804
.L0805E872:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0x43
	bne .L0805E884
	ldr r1, .L0805E88C @ =gEkrTriangleInvalid
	movs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
.L0805E884:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805E88C: .4byte gEkrTriangleInvalid

	thumb_func_start func_fe6_0805E890
func_fe6_0805E890: @ 0x0805E890
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r0, .L0805E8B8 @ =gUnk_08606344
	movs r1, #3
	bl SpawnProc
	adds r1, r0, #0
	str r4, [r1, #0x5c]
	movs r0, #0
	strh r0, [r1, #0x2c]
	str r0, [r1, #0x44]
	cmp r5, #0
	bne .L0805E8C4
	ldr r0, .L0805E8BC @ =0x0203CD90
	ldr r2, [r0]
	ldr r0, .L0805E8C0 @ =gUnk_081CA054
	b .L0805E8CA
	.align 2, 0
.L0805E8B8: .4byte gUnk_08606344
.L0805E8BC: .4byte 0x0203CD90
.L0805E8C0: .4byte gUnk_081CA054
.L0805E8C4:
	ldr r0, .L0805E900 @ =0x0203CD90
	ldr r2, [r0, #4]
	ldr r0, .L0805E904 @ =gUnk_081CA062
.L0805E8CA:
	str r0, [r1, #0x48]
	ldr r0, .L0805E908 @ =gUnk_0860635C
	str r0, [r1, #0x4c]
	str r0, [r1, #0x50]
	ldr r4, .L0805E90C @ =gSpellAnimBgfx
	adds r0, r2, #0
	adds r1, r4, #0
	bl LZ77UnCompWram
	adds r0, r4, #0
	movs r1, #0x20
	bl SpellFx_RegisterBgPal
	ldr r0, .L0805E910 @ =gUnk_081CA070
	cmp r6, #0
	beq .L0805E8F2
	ldr r0, .L0805E914 @ =gUnk_081CB404
	cmp r7, #0
	bne .L0805E8F2
	ldr r0, .L0805E918 @ =gUnk_081CAA14
.L0805E8F2:
	movs r1, #0x80
	lsls r1, r1, #6
	bl SpellFx_RegisterBgGfx
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805E900: .4byte 0x0203CD90
.L0805E904: .4byte gUnk_081CA062
.L0805E908: .4byte gUnk_0860635C
.L0805E90C: .4byte gSpellAnimBgfx
.L0805E910: .4byte gUnk_081CA070
.L0805E914: .4byte gUnk_081CB404
.L0805E918: .4byte gUnk_081CAA14

	thumb_func_start func_fe6_0805E91C
func_fe6_0805E91C: @ 0x0805E91C
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
	blt .L0805E94A
	ldr r1, [r4, #0x4c]
	ldr r3, [r4, #0x50]
	ldr r0, [r4, #0x5c]
	lsls r2, r2, #2
	adds r1, r2, r1
	ldr r1, [r1]
	adds r2, r2, r3
	ldr r2, [r2]
	bl SpellFx_WriteBgMap
	b .L0805E95C
.L0805E94A:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	bne .L0805E95C
	bl SpellFx_ClearBG1
	adds r0, r4, #0
	bl Proc_Break
.L0805E95C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0805E964
func_fe6_0805E964: @ 0x0805E964
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	adds r4, r1, #0
	mov r8, r2
	mov sb, r3
	ldr r0, .L0805E998 @ =gUnk_08606374
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r7, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	cmp r4, #0
	bne .L0805E9A4
	movs r0, #0x12
	strh r0, [r5, #0x2e]
	ldr r0, .L0805E99C @ =0x0203CD90
	ldr r6, [r0]
	ldr r3, .L0805E9A0 @ =gUnk_086068A4
	b .L0805E9AE
	.align 2, 0
.L0805E998: .4byte gUnk_08606374
.L0805E99C: .4byte 0x0203CD90
.L0805E9A0: .4byte gUnk_086068A4
.L0805E9A4:
	movs r0, #0x11
	strh r0, [r5, #0x2e]
	ldr r0, .L0805E9F8 @ =0x0203CD90
	ldr r6, [r0, #4]
	ldr r3, .L0805E9FC @ =gUnk_08606BD8
.L0805E9AE:
	str r3, [sp]
	adds r0, r7, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	str r0, [r5, #0x60]
	ldr r4, .L0805EA00 @ =gBuf_Banim
	adds r0, r6, #0
	adds r1, r4, #0
	bl LZ77UnCompWram
	adds r0, r4, #0
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	ldr r0, .L0805EA04 @ =gUnk_081CC428
	mov r1, r8
	cmp r1, #0
	beq .L0805E9E0
	ldr r0, .L0805EA08 @ =gUnk_081CD7AC
	mov r1, sb
	cmp r1, #0
	bne .L0805E9E0
	ldr r0, .L0805EA0C @ =gUnk_081CCDE0
.L0805E9E0:
	movs r1, #0x80
	lsls r1, r1, #5
	bl SpellFx_RegisterObjGfx
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805E9F8: .4byte 0x0203CD90
.L0805E9FC: .4byte gUnk_08606BD8
.L0805EA00: .4byte gBuf_Banim
.L0805EA04: .4byte gUnk_081CC428
.L0805EA08: .4byte gUnk_081CD7AC
.L0805EA0C: .4byte gUnk_081CCDE0

	thumb_func_start func_fe6_0805EA10
func_fe6_0805EA10: @ 0x0805EA10
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0805EA30
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L0805EA30:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0805EA38
func_fe6_0805EA38: @ 0x0805EA38
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	mov r8, r3
	ldr r7, [sp, #0x18]
	ldr r0, .L0805EA6C @ =gUnk_0860638C
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x5c]
	movs r1, #0
	strh r1, [r0, #0x2c]
	str r5, [r0, #0x44]
	str r6, [r0, #0x48]
	mov r1, r8
	str r1, [r0, #0x4c]
	str r7, [r0, #0x50]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
.L0805EA6C: .4byte gUnk_0860638C

	thumb_func_start func_fe6_0805EA70
func_fe6_0805EA70: @ 0x0805EA70
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne .L0805EAA6
	ldr r0, [r5, #0x5c]
	ldr r1, [r5, #0x44]
	ldr r2, [r5, #0x48]
	ldr r3, [r5, #0x4c]
	ldr r4, [r5, #0x50]
	str r4, [sp]
	bl func_fe6_0805EB40
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r5, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xe2
	movs r3, #1
	bl func_fe6_0805C804
.L0805EAA6:
	ldrh r0, [r5, #0x2c]
	cmp r0, #0x30
	bne .L0805EACA
	ldr r0, [r5, #0x5c]
	ldr r2, [r5, #0x44]
	ldr r3, [r5, #0x4c]
	movs r1, #0
	bl func_fe6_0805ED1C
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r5, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xe2
	movs r3, #1
	bl func_fe6_0805C804
.L0805EACA:
	ldrh r0, [r5, #0x2c]
	cmp r0, #0x3c
	bne .L0805EAE0
	ldr r0, [r5, #0x5c]
	movs r1, #4
	bl NewEfxFlashBgWhite
	ldr r0, [r5, #0x5c]
	movs r1, #0xa
	bl func_fe6_0805EE9C
.L0805EAE0:
	ldrh r3, [r5, #0x2c]
	cmp r3, #0x4f
	bne .L0805EB04
	ldr r0, [r5, #0x5c]
	ldr r2, [r5, #0x48]
	ldr r3, [r5, #0x50]
	movs r1, #1
	bl func_fe6_0805ED1C
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r5, #0x5c]
	movs r3, #2
	ldrsh r2, [r0, r3]
	movs r0, #0xe2
	movs r3, #1
	bl func_fe6_0805C804
.L0805EB04:
	ldrh r0, [r5, #0x2c]
	cmp r0, #0x5b
	bne .L0805EB10
	ldr r1, .L0805EB3C @ =gEkrTriangleInvalid
	movs r0, #1
	str r0, [r1]
.L0805EB10:
	ldrh r3, [r5, #0x2c]
	cmp r3, #0x60
	bne .L0805EB26
	ldr r0, [r5, #0x5c]
	movs r1, #4
	bl NewEfxFlashBgWhite
	ldr r0, [r5, #0x5c]
	movs r1, #0xa
	bl func_fe6_0805EE9C
.L0805EB26:
	ldrh r0, [r5, #0x2c]
	cmp r0, #0x78
	bne .L0805EB32
	adds r0, r5, #0
	bl Proc_Break
.L0805EB32:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805EB3C: .4byte gEkrTriangleInvalid

	thumb_func_start func_fe6_0805EB40
func_fe6_0805EB40: @ 0x0805EB40
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	mov r8, r0
	adds r4, r1, #0
	mov sb, r2
	adds r6, r3, #0
	ldr r0, .L0805EB78 @ =gUnk_086063A4
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	mov r0, r8
	str r0, [r5, #0x5c]
	movs r0, #0
	strh r0, [r5, #0x2c]
	movs r0, #0x14
	strh r0, [r5, #0x2e]
	ldr r0, .L0805EB7C @ =0x0203CD90
	ldr r7, [r0]
	cmp r4, #0
	bne .L0805EB88
	ldr r3, .L0805EB80 @ =gUnk_08606C70
	ldr r6, .L0805EB84 @ =gUnk_081CE154
	b .L0805EBB4
	.align 2, 0
.L0805EB78: .4byte gUnk_086063A4
.L0805EB7C: .4byte 0x0203CD90
.L0805EB80: .4byte gUnk_08606C70
.L0805EB84: .4byte gUnk_081CE154
.L0805EB88:
	cmp r6, #1
	beq .L0805EBA0
	cmp r6, #1
	bhs .L0805EBB0
	ldr r3, .L0805EB98 @ =gUnk_08606D00
	ldr r6, .L0805EB9C @ =gUnk_081CE474
	b .L0805EBB4
	.align 2, 0
.L0805EB98: .4byte gUnk_08606D00
.L0805EB9C: .4byte gUnk_081CE474
.L0805EBA0:
	ldr r3, .L0805EBA8 @ =gUnk_08606D90
	ldr r6, .L0805EBAC @ =gUnk_081CE848
	b .L0805EBB4
	.align 2, 0
.L0805EBA8: .4byte gUnk_08606D90
.L0805EBAC: .4byte gUnk_081CE848
.L0805EBB0:
	ldr r3, .L0805EBF4 @ =gUnk_08606E1C
	ldr r6, .L0805EBF8 @ =gUnk_081CEC7C
.L0805EBB4:
	str r3, [sp]
	mov r0, r8
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	adds r1, r0, #0
	str r1, [r5, #0x60]
	ldr r0, .L0805EBFC @ =0x00008840
	strh r0, [r1, #8]
	ldr r4, .L0805EC00 @ =gBuf_Banim
	adds r0, r7, #0
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L0805EC04 @ =gPal+0x300
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	adds r0, r6, #0
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r0, .L0805EC08 @ =0x0203CD90
	ldr r7, [r0, #4]
	mov r0, sb
	cmp r0, #0
	bne .L0805EC14
	ldr r3, .L0805EC0C @ =gUnk_08606C70
	ldr r6, .L0805EC10 @ =gUnk_081CE154
	b .L0805EC40
	.align 2, 0
.L0805EBF4: .4byte gUnk_08606E1C
.L0805EBF8: .4byte gUnk_081CEC7C
.L0805EBFC: .4byte 0x00008840
.L0805EC00: .4byte gBuf_Banim
.L0805EC04: .4byte gPal+0x300
.L0805EC08: .4byte 0x0203CD90
.L0805EC0C: .4byte gUnk_08606C70
.L0805EC10: .4byte gUnk_081CE154
.L0805EC14:
	ldr r0, [sp, #0x20]
	cmp r0, #1
	beq .L0805EC2C
	cmp r0, #1
	bhs .L0805EC3C
	ldr r3, .L0805EC24 @ =gUnk_08606D00
	ldr r6, .L0805EC28 @ =gUnk_081CE474
	b .L0805EC40
	.align 2, 0
.L0805EC24: .4byte gUnk_08606D00
.L0805EC28: .4byte gUnk_081CE474
.L0805EC2C:
	ldr r3, .L0805EC34 @ =gUnk_08606D90
	ldr r6, .L0805EC38 @ =gUnk_081CE848
	b .L0805EC40
	.align 2, 0
.L0805EC34: .4byte gUnk_08606D90
.L0805EC38: .4byte gUnk_081CE848
.L0805EC3C:
	ldr r3, .L0805ECA8 @ =gUnk_08606E1C
	ldr r6, .L0805ECAC @ =gUnk_081CEC7C
.L0805EC40:
	str r3, [sp]
	mov r0, r8
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	adds r1, r0, #0
	str r1, [r5, #0x64]
	ldr r0, .L0805ECB0 @ =0x0000A880
	strh r0, [r1, #8]
	ldr r4, .L0805ECB4 @ =gBuf_Banim + 0x800
	adds r0, r7, #0
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L0805ECB8 @ =gPal+0x340
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	adds r0, r6, #0
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L0805ECBC @ =0x06010800
	ldr r0, .L0805ECC0 @ =0xFFFFF800
	adds r4, r4, r0
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r4, #0
	bl RegisterDataMove
	bl EnablePalSync
	ldr r1, [r5, #0x60]
	ldr r0, [r5, #0x5c]
	ldrh r0, [r0, #2]
	adds r0, #0x20
	strh r0, [r1, #2]
	ldr r1, [r5, #0x64]
	ldr r0, [r5, #0x5c]
	ldrh r0, [r0, #2]
	subs r0, #0x20
	strh r0, [r1, #2]
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805ECA8: .4byte gUnk_08606E1C
.L0805ECAC: .4byte gUnk_081CEC7C
.L0805ECB0: .4byte 0x0000A880
.L0805ECB4: .4byte gBuf_Banim + 0x800
.L0805ECB8: .4byte gPal+0x340
.L0805ECBC: .4byte 0x06010800
.L0805ECC0: .4byte 0xFFFFF800

	thumb_func_start func_fe6_0805ECC4
func_fe6_0805ECC4: @ 0x0805ECC4
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0x20
	movs r2, #0
	bl Interpolate
	ldr r2, [r4, #0x60]
	ldr r1, [r4, #0x5c]
	ldrh r1, [r1, #2]
	adds r1, r1, r0
	strh r1, [r2, #2]
	ldr r2, [r4, #0x64]
	ldr r1, [r4, #0x5c]
	ldrh r1, [r1, #2]
	subs r0, r1, r0
	strh r0, [r2, #2]
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0805ED14
	ldr r0, [r4, #0x60]
	bl BasRemove
	ldr r0, [r4, #0x64]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L0805ED14:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805ED1C
func_fe6_0805ED1C: @ 0x0805ED1C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	mov r8, r0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	ldr r0, .L0805ED58 @ =gUnk_086063BC
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	mov r0, r8
	str r0, [r4, #0x5c]
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #5
	strh r0, [r4, #0x2e]
	adds r0, r4, #0
	adds r0, #0x29
	strb r5, [r0]
	adds r0, #1
	strb r6, [r0]
	cmp r5, #0
	bne .L0805ED60
	ldr r0, .L0805ED5C @ =0x0203CD90
	ldr r0, [r0]
	b .L0805ED64
	.align 2, 0
.L0805ED58: .4byte gUnk_086063BC
.L0805ED5C: .4byte 0x0203CD90
.L0805ED60:
	ldr r0, .L0805ED70 @ =0x0203CD90
	ldr r0, [r0, #4]
.L0805ED64:
	mov sb, r0
	cmp r6, #0
	bne .L0805ED7C
	ldr r3, .L0805ED74 @ =gUnk_08606F0C
	ldr r6, .L0805ED78 @ =gUnk_081CF03C
	b .L0805EDA8
	.align 2, 0
.L0805ED70: .4byte 0x0203CD90
.L0805ED74: .4byte gUnk_08606F0C
.L0805ED78: .4byte gUnk_081CF03C
.L0805ED7C:
	cmp r7, #1
	beq .L0805ED94
	cmp r7, #1
	bhs .L0805EDA4
	ldr r3, .L0805ED8C @ =gUnk_08607084
	ldr r6, .L0805ED90 @ =gUnk_081CF574
	b .L0805EDA8
	.align 2, 0
.L0805ED8C: .4byte gUnk_08607084
.L0805ED90: .4byte gUnk_081CF574
.L0805ED94:
	ldr r3, .L0805ED9C @ =gUnk_086071D8
	ldr r6, .L0805EDA0 @ =gUnk_081CFCB0
	b .L0805EDA8
	.align 2, 0
.L0805ED9C: .4byte gUnk_086071D8
.L0805EDA0: .4byte gUnk_081CFCB0
.L0805EDA4:
	ldr r3, .L0805EDD4 @ =gUnk_086074A0
	ldr r6, .L0805EDD8 @ =gUnk_081D043C
.L0805EDA8:
	str r3, [sp]
	mov r0, r8
	adds r1, r3, #0
	adds r2, r3, #0
	bl EfxCreateFrontAnim
	adds r1, r0, #0
	str r1, [r4, #0x60]
	cmp r5, #0
	bne .L0805EDDC
	ldrh r0, [r1, #4]
	adds r0, #0xa
	strh r0, [r1, #4]
	ldr r1, [r4, #0x60]
	movs r0, #0x78
	strh r0, [r1, #0xa]
	bl BasSort
	ldr r0, [r4, #0x5c]
	ldrh r1, [r0, #2]
	adds r1, #0x10
	b .L0805EDF2
	.align 2, 0
.L0805EDD4: .4byte gUnk_086074A0
.L0805EDD8: .4byte gUnk_081D043C
.L0805EDDC:
	ldrh r0, [r1, #4]
	adds r0, #2
	strh r0, [r1, #4]
	ldr r1, [r4, #0x60]
	movs r0, #0x14
	strh r0, [r1, #0xa]
	bl BasSort
	ldr r0, [r4, #0x5c]
	ldrh r1, [r0, #2]
	subs r1, #0xc
.L0805EDF2:
	strh r1, [r4, #0x32]
	ldrh r0, [r0, #2]
	subs r0, #0x10
	strh r0, [r4, #0x34]
	ldr r0, [r4, #0x60]
	strh r1, [r0, #2]
	ldr r4, .L0805EE28 @ =gBuf_Banim
	mov r0, sb
	adds r1, r4, #0
	bl LZ77UnCompWram
	adds r0, r4, #0
	movs r1, #0x20
	bl SpellFx_RegisterObjPal
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r6, #0
	bl SpellFx_RegisterObjGfx
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805EE28: .4byte gBuf_Banim

	thumb_func_start func_fe6_0805EE2C
func_fe6_0805EE2C: @ 0x0805EE2C
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r1, [r4, r0]
	movs r5, #0x34
	ldrsh r2, [r4, r5]
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r5, #0x2e
	ldrsh r0, [r4, r5]
	str r0, [sp]
	movs r0, #1
	bl Interpolate
	ldr r1, [r4, #0x60]
	strh r0, [r1, #2]
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0805EE6C
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x14
	strh r0, [r4, #0x2e]
	adds r0, r4, #0
	bl Proc_Break
.L0805EE6C:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_0805EE74
func_fe6_0805EE74: @ 0x0805EE74
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	ldrh r2, [r4, #0x2e]
	lsls r1, r2, #0x10
	cmp r0, r1
	ble .L0805EE94
	ldr r0, [r4, #0x60]
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
.L0805EE94:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_0805EE9C
func_fe6_0805EE9C: @ 0x0805EE9C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r1, .L0805EECC @ =gEfxBgSemaphore
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, .L0805EED0 @ =gUnk_086063DC
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x5c]
	movs r0, #0
	movs r1, #0
	bl NewEfxQuakePure
	str r0, [r4, #0x60]
	movs r0, #0
	strh r0, [r4, #0x2c]
	strh r6, [r4, #0x2e]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0805EECC: .4byte gEfxBgSemaphore
.L0805EED0: .4byte gUnk_086063DC

	thumb_func_start func_fe6_0805EED4
func_fe6_0805EED4: @ 0x0805EED4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldr r5, .L0805F060 @ =gEkrBg2QuakeVec
	ldrh r1, [r5]
	ldrh r2, [r5, #2]
	movs r0, #2
	bl SetBgOffset
	ldr r6, .L0805F064 @ =gEkrBg0QuakeVec
	ldrh r0, [r5]
	ldrh r2, [r6]
	adds r1, r0, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r3, [r5, #2]
	ldrh r0, [r6, #2]
	adds r2, r3, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0
	bl SetBgOffset
	ldrh r1, [r5]
	ldrh r2, [r6]
	adds r0, r1, r2
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r3, [r5, #2]
	ldrh r2, [r6, #2]
	adds r1, r3, r2
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl func_fe6_0804392C
	ldrh r3, [r5]
	ldrh r1, [r6]
	adds r0, r3, r1
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r2, [r5, #2]
	ldrh r3, [r6, #2]
	adds r1, r2, r3
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl func_fe6_08044230
	bl GetEkrDragonStateType
	cmp r0, #0
	beq .L0805EF58
	ldrh r1, [r5]
	ldrh r2, [r5, #2]
	adds r2, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #3
	bl SetBgOffset
.L0805EF58:
	ldr r0, .L0805F068 @ =gEkrXPosReal
	mov sb, r0
	ldrh r0, [r5]
	mov r2, sb
	ldrh r2, [r2]
	adds r1, r0, r2
	ldr r3, .L0805F06C @ =gEkrBgPosition
	mov sl, r3
	ldr r4, [r3]
	subs r1, r1, r4
	ldr r2, .L0805F070 @ =gEkrYPosReal
	mov r8, r2
	ldrh r3, [r5, #2]
	ldrh r5, [r2]
	subs r5, r5, r3
	mov ip, r5
	mov r2, sb
	ldrh r2, [r2, #2]
	adds r0, r0, r2
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	mov r0, r8
	ldrh r0, [r0, #2]
	subs r3, r0, r3
	lsls r3, r3, #0x10
	lsrs r4, r3, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	mov r3, ip
	lsls r2, r3, #0x10
	asrs r2, r2, #0x10
	movs r0, #0
	bl SetEkrFrontAnimPostion
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r2, r4, #0x10
	asrs r2, r2, #0x10
	movs r0, #1
	bl SetEkrFrontAnimPostion
	ldrh r0, [r7, #0x2c]
	adds r0, #1
	strh r0, [r7, #0x2c]
	lsls r0, r0, #0x10
	ldrh r5, [r7, #0x2e]
	lsls r1, r5, #0x10
	cmp r0, r1
	ble .L0805F052
	ldr r1, .L0805F074 @ =gEfxBgSemaphore
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	ldrh r1, [r6]
	ldrh r2, [r6, #2]
	movs r0, #0
	bl SetBgOffset
	ldrh r1, [r6]
	rsbs r0, r1, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r2, [r6, #2]
	rsbs r1, r2, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl func_fe6_0804392C
	ldrh r3, [r6]
	rsbs r0, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r6, [r6, #2]
	rsbs r1, r6, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl func_fe6_08044230
	bl GetEkrDragonStateType
	cmp r0, #0
	beq .L0805F012
	movs r0, #3
	movs r1, #0
	movs r2, #0x10
	bl SetBgOffset
.L0805F012:
	mov r5, sl
	ldr r0, [r5]
	mov r2, sb
	ldrh r2, [r2]
	subs r1, r2, r0
	mov r3, sb
	ldrh r3, [r3, #2]
	subs r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	mov r0, r8
	ldrh r4, [r0, #2]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r0, #0
	bl SetEkrFrontAnimPostion
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r2, r4, #0x10
	asrs r2, r2, #0x10
	movs r0, #1
	bl SetEkrFrontAnimPostion
	ldr r0, [r7, #0x60]
	bl Proc_End
	adds r0, r7, #0
	bl Proc_Break
.L0805F052:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0805F060: .4byte gEkrBg2QuakeVec
.L0805F064: .4byte gEkrBg0QuakeVec
.L0805F068: .4byte gEkrXPosReal
.L0805F06C: .4byte gEkrBgPosition
.L0805F070: .4byte gEkrYPosReal
.L0805F074: .4byte gEfxBgSemaphore
