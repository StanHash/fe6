	.include "macro.inc"

	.syntax unified

	.section .data
	.global ProcScr_Ekrbattleending
ProcScr_Ekrbattleending: @ 085CBB60
	.incbin "fe6-base.gba", 0x5CBB60, (0x5CBBB0 - 0x5CBB60) @ length: 0050

	.section .text
	thumb_func_start NewEkrbattleending
NewEkrbattleending: @ 0x080481B4
	push {lr}
	ldr r0, .L080481C8 @ =ProcScr_Ekrbattleending
	movs r1, #3
	bl SpawnProc
	movs r1, #0
	strh r1, [r0, #0x2c]
	pop {r0}
	bx r0
	.align 2, 0
.L080481C8: .4byte ProcScr_Ekrbattleending

	thumb_func_start func_fe6_080481CC
func_fe6_080481CC: @ 0x080481CC
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r7, .L080481F0 @ =gBanimBackgroundIndex
	movs r1, #0
	ldrsh r0, [r7, r1]
	cmp r0, #0
	beq .L080481E6
	bl GetEkrDragonStateType
	adds r6, r0, #0
	cmp r6, #0
	beq .L080481F4
.L080481E6:
	adds r0, r5, #0
	bl Proc_Break
	b .L08048238
	.align 2, 0
.L080481F0: .4byte gBanimBackgroundIndex
.L080481F4:
	movs r0, #0x2c
	ldrsh r3, [r5, r0]
	movs r0, #8
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0x10
	bl Interpolate
	adds r4, r0, #0
	movs r1, #0
	ldrsh r0, [r7, r1]
	subs r0, #1
	bl func_fe6_0805F0DC
	ldr r0, .L08048240 @ =gPal
	movs r1, #6
	movs r2, #0xa
	adds r3, r4, #0
	bl EfxPalBlackInOut
	bl EnablePalSync
	ldrh r0, [r5, #0x2c]
	adds r0, #1
	strh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	bne .L08048238
	strh r6, [r5, #0x2c]
	adds r0, r5, #0
	bl Proc_Break
.L08048238:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08048240: .4byte gPal

	thumb_func_start func_fe6_08048244
func_fe6_08048244: @ 0x08048244
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L08048264 @ =gBanimBackgroundIndex
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L0804825A
	bl GetEkrDragonStateType
	cmp r0, #0
	beq .L08048268
.L0804825A:
	adds r0, r4, #0
	bl Proc_Break
	b .L0804828E
	.align 2, 0
.L08048264: .4byte gBanimBackgroundIndex
.L08048268:
	ldr r0, .L08048294 @ =gPlaySt
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl ApplyChapterMapGraphics
	movs r0, #0x10
	bl EfxChapterMapFadeOUT
	bl RenderMap
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
	adds r0, r4, #0
	bl Proc_Break
.L0804828E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08048294: .4byte gPlaySt

	thumb_func_start func_fe6_08048298
func_fe6_08048298: @ 0x08048298
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, .L080482BC @ =gBanimBackgroundIndex
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq .L080482B2
	bl GetEkrDragonStateType
	adds r5, r0, #0
	cmp r5, #0
	beq .L080482C0
.L080482B2:
	adds r0, r4, #0
	bl Proc_Break
	b .L080482EC
	.align 2, 0
.L080482BC: .4byte gBanimBackgroundIndex
.L080482C0:
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r0, #8
	str r0, [sp]
	movs r0, #0
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
	bne .L080482EC
	strh r5, [r4, #0x2c]
	adds r0, r4, #0
	bl Proc_Break
.L080482EC:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080482F4
func_fe6_080482F4: @ 0x080482F4
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r2, .L08048350 @ =gEkrBmLocation
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #8
	strh r0, [r4, #0x34]
	strh r0, [r4, #0x32]
	movs r1, #2
	ldrsh r0, [r2, r1]
	movs r3, #6
	ldrsh r1, [r2, r3]
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #8
	strh r0, [r4, #0x3c]
	strh r0, [r4, #0x3a]
	bl BasInit
	movs r0, #1
	bl NewEkrUnitKakudai
	movs r0, #1
	bl NewEkrBaseKaiten
	movs r0, #1
	movs r1, #0xb
	bl NewEkrWindowAppear
	movs r0, #1
	movs r1, #0xb
	bl NewEkrBaseAppear
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08048350: .4byte gEkrBmLocation

	thumb_func_start func_fe6_08048354
func_fe6_08048354: @ 0x08048354
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	adds r0, #1
	movs r5, #0
	strh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc
	ble .L080483D4
	bl EndEkrGauge
	adds r0, r4, #0
	bl Proc_Break
	bl InitBmBgLayers
	ldr r0, .L080483DC @ =gDispIo
	mov ip, r0
	movs r0, #0x20
	mov r1, ip
	ldrb r1, [r1, #1]
	orrs r0, r1
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x7f
	ands r0, r1
	mov r2, ip
	strb r0, [r2, #1]
	mov r0, ip
	adds r0, #0x2d
	strb r5, [r0]
	adds r0, #4
	strb r5, [r0]
	subs r0, #5
	strb r5, [r0]
	adds r0, #4
	strb r5, [r0]
	mov r5, ip
	adds r5, #0x34
	movs r1, #1
	ldrb r0, [r5]
	orrs r0, r1
	movs r6, #2
	orrs r0, r6
	movs r4, #4
	orrs r0, r4
	movs r3, #8
	orrs r0, r3
	movs r2, #0x10
	orrs r0, r2
	strb r0, [r5]
	mov r2, ip
	adds r2, #0x36
	ldrb r0, [r2]
	orrs r1, r0
	orrs r1, r6
	orrs r1, r4
	orrs r1, r3
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r1, r0
	strb r1, [r2]
.L080483D4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080483DC: .4byte gDispIo

	thumb_func_start func_fe6_080483E0
func_fe6_080483E0: @ 0x080483E0
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
	movs r0, #0
	strh r0, [r5, #0x2c]
	movs r0, #0xf
	strh r0, [r5, #0x2e]
	bl ResetUnitSprites
	bl func_fe6_080292B8
	bl RefreshUnitSprites
	bl ForceSyncUnitSpriteSheet
	bl ApplyUnitSpritePalettes
	ldr r2, .L08048468 @ =gDispIo
	adds r1, r2, #0
	adds r1, #0x3c
	movs r0, #0xc0
	ldrb r3, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x44
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r1, #0xa
	movs r0, #4
	strb r0, [r1]
	ldr r0, .L0804846C @ =0x0000FFE0
	ldrh r1, [r2, #0x3c]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strh r0, [r2, #0x3c]
	adds r1, r2, #0
	adds r1, #0x34
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrb r3, [r1]
	ands r0, r3
	strb r0, [r1]
	adds r1, #2
	movs r0, #0x20
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
	bl GetBattleAnimArenaFlag
	cmp r0, #1
	beq .L08048450
	bl ApplyChapterMapPalettes
.L08048450:
	bl GetBanimLinkArenaFlag
	cmp r0, #1
	bne .L0804845C
	bl func_fe6_0803CF58
.L0804845C:
	adds r0, r5, #0
	bl Proc_Break
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08048468: .4byte gDispIo
.L0804846C: .4byte 0x0000FFE0

	thumb_func_start func_fe6_08048470
func_fe6_08048470: @ 0x08048470
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldrh r0, [r7, #0x2c]
	ldrh r1, [r7, #0x2e]
	cmp r0, r1
	beq .L08048488
	adds r0, #1
	strh r0, [r7, #0x2c]
.L08048488:
	movs r2, #0x32
	ldrsh r1, [r7, r2]
	movs r0, #0x2c
	ldrsh r3, [r7, r0]
	movs r2, #0x2e
	ldrsh r0, [r7, r2]
	str r0, [sp]
	movs r0, #0
	movs r2, #0
	bl Interpolate
	adds r6, r0, #0
	movs r0, #0x3a
	ldrsh r1, [r7, r0]
	movs r2, #0x2c
	ldrsh r3, [r7, r2]
	movs r2, #0x2e
	ldrsh r0, [r7, r2]
	str r0, [sp]
	movs r0, #0
	movs r2, #0
	bl Interpolate
	adds r5, r0, #0
	movs r0, #0x34
	ldrsh r1, [r7, r0]
	movs r2, #0x2c
	ldrsh r3, [r7, r2]
	movs r2, #0x2e
	ldrsh r0, [r7, r2]
	str r0, [sp]
	movs r0, #0
	movs r2, #0xf0
	bl Interpolate
	adds r4, r0, #0
	movs r0, #0x3c
	ldrsh r1, [r7, r0]
	movs r2, #0x2c
	ldrsh r3, [r7, r2]
	movs r2, #0x2e
	ldrsh r0, [r7, r2]
	str r0, [sp]
	movs r0, #0
	movs r2, #0xa0
	bl Interpolate
	ldr r1, .L08048550 @ =gDispIo
	movs r2, #0x2d
	adds r2, r2, r1
	mov sb, r2
	movs r2, #0
	mov r8, r2
	mov r2, sb
	strb r6, [r2]
	adds r6, r1, #0
	adds r6, #0x31
	strb r5, [r6]
	adds r5, r1, #0
	adds r5, #0x2c
	strb r4, [r5]
	adds r4, r1, #0
	adds r4, #0x30
	strb r0, [r4]
	mov r0, r8
	str r0, [sp, #4]
	ldr r1, .L08048554 @ =gBg2Tm
	ldr r2, .L08048558 @ =0x01000200
	add r0, sp, #4
	bl CpuFastSet
	movs r0, #4
	bl EnableBgSync
	ldrh r1, [r7, #0x2c]
	ldrh r2, [r7, #0x2e]
	cmp r1, r2
	bne .L08048542
	movs r0, #0
	mov r1, r8
	strh r1, [r7, #0x2c]
	mov r2, sb
	strb r0, [r2]
	strb r0, [r6]
	movs r0, #0xf0
	strb r0, [r5]
	movs r0, #0xa0
	strb r0, [r4]
	bl EnablePalSync
	adds r0, r7, #0
	bl Proc_Break
.L08048542:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08048550: .4byte gDispIo
.L08048554: .4byte gBg2Tm
.L08048558: .4byte 0x01000200

	thumb_func_start func_fe6_0804855C
func_fe6_0804855C: @ 0x0804855C
	push {r4, lr}
	adds r4, r0, #0
	bl EndEkrBattleDeamon
	bl func_fe6_08029240
	adds r0, r4, #0
	bl Proc_Break
	pop {r4}
	pop {r0}
	bx r0
