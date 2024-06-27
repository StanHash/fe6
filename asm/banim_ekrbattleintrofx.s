	.include "macro.inc"
	.syntax unified

	.section .data

	.global ProcScr_EkrBaseKaiten
ProcScr_EkrBaseKaiten: @ 085CBBB0
	.incbin "fe6-base.gba", 0x5CBBB0, (0x5CBBC8 - 0x5CBBB0) @ length: 0018

	.global Imgs_EkrBaseKaiten1
Imgs_EkrBaseKaiten1: @ 085CBBC8
	.incbin "fe6-base.gba", 0x5CBBC8, (0x5CBBE8 - 0x5CBBC8) @ length: 0020

	.global Imgs_EkrBaseKaiten2
Imgs_EkrBaseKaiten2: @ 085CBBE8
	.incbin "fe6-base.gba", 0x5CBBE8, (0x5CBC08 - 0x5CBBE8) @ length: 0020

	.global AnimScrs_EkrBaseKaiten1
AnimScrs_EkrBaseKaiten1: @ 085CBC08
	.incbin "fe6-base.gba", 0x5CBC08, (0x5CBC28 - 0x5CBC08) @ length: 0020

	.global AnimScrs_EkrBaseKaiten2
AnimScrs_EkrBaseKaiten2: @ 085CBC28
	.incbin "fe6-base.gba", 0x5CBC28, (0x5CBC48 - 0x5CBC28) @ length: 0020

	.global AnimScrs_EkrBaseKaiten3
AnimScrs_EkrBaseKaiten3: @ 085CBC48
	.incbin "fe6-base.gba", 0x5CBC48, (0x5CBC68 - 0x5CBC48) @ length: 0020

	.global AnimScrs_EkrBaseKaiten4
AnimScrs_EkrBaseKaiten4: @ 085CBC68
	.incbin "fe6-base.gba", 0x5CBC68, (0x5CBC88 - 0x5CBC68) @ length: 0020

	.global AnimScrs_EkrBaseKaiten5
AnimScrs_EkrBaseKaiten5: @ 085CBC88
	.incbin "fe6-base.gba", 0x5CBC88, (0x5CBCA8 - 0x5CBC88) @ length: 0020

	.global AnimScrs_EkrBaseKaiten6
AnimScrs_EkrBaseKaiten6: @ 085CBCA8
	.incbin "fe6-base.gba", 0x5CBCA8, (0x5CBCC8 - 0x5CBCA8) @ length: 0020

	.global gUnk_085CBCC8
gUnk_085CBCC8: @ 085CBCC8
	.incbin "fe6-base.gba", 0x5CBCC8, (0x5CBCE8 - 0x5CBCC8) @ length: 0020

	.global gUnk_085CBCE8
gUnk_085CBCE8: @ 085CBCE8
	.incbin "fe6-base.gba", 0x5CBCE8, (0x5CBD08 - 0x5CBCE8) @ length: 0020

	.global gUnk_085CBD08
gUnk_085CBD08: @ 085CBD08
	.incbin "fe6-base.gba", 0x5CBD08, (0x5CBD28 - 0x5CBD08) @ length: 0020

	.global ProcScr_EkrUnitKakudai
ProcScr_EkrUnitKakudai: @ 085CBD28
	.incbin "fe6-base.gba", 0x5CBD28, (0x5CBD50 - 0x5CBD28) @ length: 0028

	.global ProcScr_EkrWindowAppear
ProcScr_EkrWindowAppear: @ 085CBD50
	.incbin "fe6-base.gba", 0x5CBD50, (0x5CBD68 - 0x5CBD50) @ length: 0018

	.global ProcScr_EkrNamewinAppear
ProcScr_EkrNamewinAppear: @ 085CBD68
	.incbin "fe6-base.gba", 0x5CBD68, (0x5CBD88 - 0x5CBD68) @ length: 0020

	.global ProcScr_EkrBaseAppear
ProcScr_EkrBaseAppear: @ 085CBD88
	.incbin "fe6-base.gba", 0x5CBD88, (0x5CBDA0 - 0x5CBD88) @ length: 0018

	.section .text
	thumb_func_start NewEkrBaseKaiten
NewEkrBaseKaiten: @ 0x08048574
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r3, .L080485DC @ =gDispIo
	adds r1, r3, #0
	adds r1, #0x3c
	movs r0, #0x3f
	ldrb r2, [r1]
	ands r0, r2
	strb r0, [r1]
	adds r1, #8
	movs r2, #0
	movs r0, #0xa
	strb r0, [r1]
	adds r1, #1
	movs r0, #6
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x46
	strb r2, [r0]
	ldr r0, .L080485E0 @ =0x0000FFE0
	ldrh r4, [r3, #0x3c]
	ands r0, r4
	ldr r1, .L080485E4 @ =0x0000E0FF
	ands r0, r1
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r3, #0x3c]
	adds r1, r3, #0
	adds r1, #0x3d
	movs r0, #0x20
	ldrb r3, [r1]
	orrs r0, r3
	strb r0, [r1]
	ldr r0, .L080485E8 @ =gEkrBmLocation
	movs r4, #0
	ldrsh r3, [r0, r4]
	movs r1, #4
	ldrsh r2, [r0, r1]
	cmp r3, r2
	bne .L080485EC
	movs r2, #2
	ldrsh r1, [r0, r2]
	movs r3, #6
	ldrsh r0, [r0, r3]
	movs r4, #2
	cmp r1, r0
	blt .L08048618
	movs r4, #6
	b .L08048618
	.align 2, 0
.L080485DC: .4byte gDispIo
.L080485E0: .4byte 0x0000FFE0
.L080485E4: .4byte 0x0000E0FF
.L080485E8: .4byte gEkrBmLocation
.L080485EC:
	movs r4, #2
	ldrsh r1, [r0, r4]
	movs r4, #6
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bne .L08048602
	movs r4, #4
	cmp r3, r2
	bge .L08048618
	movs r4, #0
	b .L08048618
.L08048602:
	cmp r3, r2
	bge .L08048610
	movs r4, #1
	cmp r1, r0
	blt .L08048618
	movs r4, #7
	b .L08048618
.L08048610:
	movs r4, #3
	cmp r1, r0
	blt .L08048618
	movs r4, #5
.L08048618:
	ldr r0, .L0804862C @ =gEkrDistanceType
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #3
	bgt .L08048630
	cmp r0, #1
	bge .L0804863C
	cmp r0, #0
	beq .L08048634
	b .L0804863C
	.align 2, 0
.L0804862C: .4byte gEkrDistanceType
.L08048630:
	cmp r0, #4
	bne .L0804863C
.L08048634:
	ldr r0, .L08048638 @ =Imgs_EkrBaseKaiten1
	b .L0804863E
	.align 2, 0
.L08048638: .4byte Imgs_EkrBaseKaiten1
.L0804863C:
	ldr r0, .L08048670 @ =Imgs_EkrBaseKaiten2
.L0804863E:
	lsls r1, r4, #2
	adds r0, r1, r0
	ldr r0, [r0]
	adds r6, r1, #0
	ldr r1, .L08048674 @ =0x06010000
	bl LZ77UnCompVram
	ldr r0, .L08048678 @ =gUnk_08119CD8
	ldr r1, .L0804867C @ =gPal+0x280
	movs r2, #1
	bl CpuFastSet
	bl EnablePalSync
	ldr r0, .L08048680 @ =gEkrDistanceType
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #4
	bls .L08048666
	b .L08048942
.L08048666:
	lsls r0, r0, #2
	ldr r1, .L08048684 @ =.L08048688
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08048670: .4byte Imgs_EkrBaseKaiten2
.L08048674: .4byte 0x06010000
.L08048678: .4byte gUnk_08119CD8
.L0804867C: .4byte gPal+0x280
.L08048680: .4byte gEkrDistanceType
.L08048684: .4byte .L08048688
.L08048688: @ jump table
	.4byte .L0804869C @ case 0
	.4byte .L0804873C @ case 1
	.4byte .L0804873C @ case 2
	.4byte .L080488A8 @ case 3
	.4byte .L0804869C @ case 4
.L0804869C:
	ldr r0, .L080486EC @ =ProcScr_EkrBaseKaiten
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r7, [r5, #0x44]
	adds r1, r5, #0
	adds r1, #0x29
	movs r0, #0
	strb r0, [r1]
	strh r0, [r5, #0x2c]
	movs r0, #0xb
	strh r0, [r5, #0x2e]
	ldr r2, .L080486F0 @ =gEkrBmLocation
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r4, #4
	ldrsh r1, [r2, r4]
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #8
	strh r0, [r5, #0x32]
	movs r1, #2
	ldrsh r0, [r2, r1]
	movs r3, #6
	ldrsh r1, [r2, r3]
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #8
	strh r0, [r5, #0x3a]
	movs r0, #0x78
	strh r0, [r5, #0x34]
	movs r0, #0x68
	strh r0, [r5, #0x3c]
	ldr r0, [r5, #0x44]
	cmp r0, #0
	bne .L080486F8
	ldr r0, .L080486F4 @ =AnimScrs_EkrBaseKaiten1
	b .L080486FA
	.align 2, 0
.L080486EC: .4byte ProcScr_EkrBaseKaiten
.L080486F0: .4byte gEkrBmLocation
.L080486F4: .4byte AnimScrs_EkrBaseKaiten1
.L080486F8:
	ldr r0, .L08048728 @ =AnimScrs_EkrBaseKaiten4
.L080486FA:
	adds r0, r6, r0
	ldr r0, [r0]
	movs r1, #0x64
	bl BasCreate
	adds r2, r0, #0
	str r2, [r5, #0x5c]
	movs r0, #0x90
	lsls r0, r0, #7
	strh r0, [r2, #8]
	ldr r0, [r2, #0x1c]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r2, #0x1c]
	ldr r0, [r5, #0x44]
	cmp r0, #0
	bne .L0804872C
	ldrh r0, [r5, #0x32]
	strh r0, [r2, #2]
	ldrh r0, [r5, #0x3a]
	b .L08048732
	.align 2, 0
.L08048728: .4byte AnimScrs_EkrBaseKaiten4
.L0804872C:
	ldrh r0, [r5, #0x34]
	strh r0, [r2, #2]
	ldrh r0, [r5, #0x3c]
.L08048732:
	strh r0, [r2, #4]
	ldr r0, .L08048738 @ =gUnk_085CBCC8
	b .L08048936
	.align 2, 0
.L08048738: .4byte gUnk_085CBCC8
.L0804873C:
	ldr r0, .L08048798 @ =ProcScr_EkrBaseKaiten
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r7, [r5, #0x44]
	adds r1, r5, #0
	adds r1, #0x29
	movs r0, #0
	strb r0, [r1]
	strh r0, [r5, #0x2c]
	movs r0, #0xb
	strh r0, [r5, #0x2e]
	ldr r1, .L0804879C @ =gEkrBmLocation
	movs r4, #0
	ldrsh r0, [r1, r4]
	lsls r0, r0, #4
	adds r0, #8
	strh r0, [r5, #0x32]
	movs r2, #2
	ldrsh r0, [r1, r2]
	lsls r0, r0, #4
	adds r0, #8
	strh r0, [r5, #0x3a]
	movs r2, #0x48
	strh r2, [r5, #0x34]
	movs r0, #0x68
	strh r0, [r5, #0x3c]
	ldr r0, .L080487A0 @ =gEkrInitPosReal
	ldr r0, [r0]
	cmp r0, #1
	bne .L0804878E
	ldr r1, .L080487A4 @ =gUnk_081122D0
	ldr r0, .L080487A8 @ =gEkrDistanceType
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	subs r0, r2, r0
	strh r0, [r5, #0x34]
.L0804878E:
	ldr r0, [r5, #0x44]
	cmp r0, #0
	bne .L080487B0
	ldr r0, .L080487AC @ =AnimScrs_EkrBaseKaiten2
	b .L080487B2
	.align 2, 0
.L08048798: .4byte ProcScr_EkrBaseKaiten
.L0804879C: .4byte gEkrBmLocation
.L080487A0: .4byte gEkrInitPosReal
.L080487A4: .4byte gUnk_081122D0
.L080487A8: .4byte gEkrDistanceType
.L080487AC: .4byte AnimScrs_EkrBaseKaiten2
.L080487B0:
	ldr r0, .L080487E0 @ =AnimScrs_EkrBaseKaiten5
.L080487B2:
	adds r0, r6, r0
	ldr r0, [r0]
	movs r1, #0x64
	bl BasCreate
	adds r2, r0, #0
	str r2, [r5, #0x5c]
	movs r0, #0x90
	lsls r0, r0, #7
	strh r0, [r2, #8]
	ldr r0, [r2, #0x1c]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r2, #0x1c]
	ldr r0, [r5, #0x44]
	cmp r0, #0
	bne .L080487E4
	ldrh r0, [r5, #0x32]
	strh r0, [r2, #2]
	ldrh r0, [r5, #0x3a]
	b .L080487EA
	.align 2, 0
.L080487E0: .4byte AnimScrs_EkrBaseKaiten5
.L080487E4:
	ldrh r0, [r5, #0x34]
	strh r0, [r2, #2]
	ldrh r0, [r5, #0x3c]
.L080487EA:
	strh r0, [r2, #4]
	ldr r0, .L08048858 @ =gUnk_085CBCE8
	adds r0, r6, r0
	ldr r0, [r0]
	str r0, [r5, #0x60]
	movs r4, #0
	strh r4, [r5, #0x3e]
	strh r4, [r5, #0x36]
	ldr r0, .L0804885C @ =ProcScr_EkrBaseKaiten
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r7, [r5, #0x44]
	adds r1, r5, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	strh r4, [r5, #0x2c]
	movs r0, #0xb
	strh r0, [r5, #0x2e]
	ldr r1, .L08048860 @ =gEkrBmLocation
	movs r4, #4
	ldrsh r0, [r1, r4]
	lsls r0, r0, #4
	adds r0, #8
	strh r0, [r5, #0x32]
	movs r2, #6
	ldrsh r0, [r1, r2]
	lsls r0, r0, #4
	adds r0, #8
	strh r0, [r5, #0x3a]
	movs r0, #0xa8
	strh r0, [r5, #0x34]
	movs r0, #0x68
	strh r0, [r5, #0x3c]
	ldr r0, .L08048864 @ =gEkrInitPosReal
	ldr r0, [r0]
	cmp r0, #0
	bne .L0804884C
	ldr r1, .L08048868 @ =gUnk_081122D0
	ldr r0, .L0804886C @ =gEkrDistanceType
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, #0xa8
	strh r0, [r5, #0x34]
.L0804884C:
	ldr r0, [r5, #0x44]
	cmp r0, #0
	bne .L08048874
	ldr r0, .L08048870 @ =AnimScrs_EkrBaseKaiten3
	b .L08048876
	.align 2, 0
.L08048858: .4byte gUnk_085CBCE8
.L0804885C: .4byte ProcScr_EkrBaseKaiten
.L08048860: .4byte gEkrBmLocation
.L08048864: .4byte gEkrInitPosReal
.L08048868: .4byte gUnk_081122D0
.L0804886C: .4byte gEkrDistanceType
.L08048870: .4byte AnimScrs_EkrBaseKaiten3
.L08048874:
	ldr r0, .L080488A4 @ =AnimScrs_EkrBaseKaiten6
.L08048876:
	adds r0, r6, r0
	ldr r0, [r0]
	movs r1, #0x64
	bl BasCreate
	adds r2, r0, #0
	str r2, [r5, #0x5c]
	movs r0, #0x90
	lsls r0, r0, #7
	strh r0, [r2, #8]
	ldr r0, [r2, #0x1c]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r2, #0x1c]
	ldr r0, [r5, #0x44]
	cmp r0, #0
	bne .L0804892C
	ldrh r0, [r5, #0x32]
	strh r0, [r2, #2]
	ldrh r0, [r5, #0x3a]
	b .L08048932
	.align 2, 0
.L080488A4: .4byte AnimScrs_EkrBaseKaiten6
.L080488A8:
	ldr r0, .L080488EC @ =ProcScr_EkrBaseKaiten
	movs r1, #3
	bl SpawnProc
	adds r5, r0, #0
	str r7, [r5, #0x44]
	adds r1, r5, #0
	adds r1, #0x29
	movs r0, #0
	strb r0, [r1]
	strh r0, [r5, #0x2c]
	movs r0, #0xb
	strh r0, [r5, #0x2e]
	ldr r1, .L080488F0 @ =gEkrBmLocation
	movs r4, #4
	ldrsh r0, [r1, r4]
	lsls r0, r0, #4
	adds r0, #8
	strh r0, [r5, #0x32]
	movs r2, #6
	ldrsh r0, [r1, r2]
	lsls r0, r0, #4
	adds r0, #8
	strh r0, [r5, #0x3a]
	movs r0, #0x78
	strh r0, [r5, #0x34]
	movs r0, #0x68
	strh r0, [r5, #0x3c]
	ldr r0, [r5, #0x44]
	cmp r0, #0
	bne .L080488F8
	ldr r0, .L080488F4 @ =AnimScrs_EkrBaseKaiten3
	b .L080488FA
	.align 2, 0
.L080488EC: .4byte ProcScr_EkrBaseKaiten
.L080488F0: .4byte gEkrBmLocation
.L080488F4: .4byte AnimScrs_EkrBaseKaiten3
.L080488F8:
	ldr r0, .L08048928 @ =AnimScrs_EkrBaseKaiten6
.L080488FA:
	adds r0, r6, r0
	ldr r0, [r0]
	movs r1, #0x64
	bl BasCreate
	adds r2, r0, #0
	str r2, [r5, #0x5c]
	movs r0, #0x90
	lsls r0, r0, #7
	strh r0, [r2, #8]
	ldr r0, [r2, #0x1c]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r2, #0x1c]
	ldr r0, [r5, #0x44]
	cmp r0, #0
	bne .L0804892C
	ldrh r0, [r5, #0x32]
	strh r0, [r2, #2]
	ldrh r0, [r5, #0x3a]
	b .L08048932
	.align 2, 0
.L08048928: .4byte AnimScrs_EkrBaseKaiten6
.L0804892C:
	ldrh r0, [r5, #0x34]
	strh r0, [r2, #2]
	ldrh r0, [r5, #0x3c]
.L08048932:
	strh r0, [r2, #4]
	ldr r0, .L08048948 @ =gUnk_085CBD08
.L08048936:
	adds r0, r6, r0
	ldr r0, [r0]
	str r0, [r5, #0x60]
	movs r0, #0
	strh r0, [r5, #0x3e]
	strh r0, [r5, #0x36]
.L08048942:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08048948: .4byte gUnk_085CBD08

	thumb_func_start func_fe6_0804894C
func_fe6_0804894C: @ 0x0804894C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r5, [r4, #0x5c]
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	cmp r1, r0
	blt .L0804896E
	adds r0, r5, #0
	bl BasRemove
	adds r0, r4, #0
	bl Proc_Break
	b .L080489DE
.L0804896E:
	ldr r0, [r4, #0x44]
	cmp r0, #0
	bne .L08048998
	movs r3, #0x32
	ldrsh r1, [r4, r3]
	movs r6, #0x34
	ldrsh r2, [r4, r6]
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r6, #0x2e
	ldrsh r0, [r4, r6]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	strh r0, [r5, #2]
	movs r0, #0x3a
	ldrsh r1, [r4, r0]
	movs r3, #0x3c
	ldrsh r2, [r4, r3]
	b .L080489BA
.L08048998:
	movs r0, #0x34
	ldrsh r1, [r4, r0]
	movs r3, #0x32
	ldrsh r2, [r4, r3]
	movs r6, #0x2c
	ldrsh r3, [r4, r6]
	movs r6, #0x2e
	ldrsh r0, [r4, r6]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	strh r0, [r5, #2]
	movs r0, #0x3c
	ldrsh r1, [r4, r0]
	movs r3, #0x3a
	ldrsh r2, [r4, r3]
.L080489BA:
	movs r6, #0x2c
	ldrsh r3, [r4, r6]
	movs r6, #0x2e
	ldrsh r0, [r4, r6]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	strh r0, [r5, #4]
	ldrh r2, [r4, #0x2c]
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	movs r3, #0x2e
	ldrsh r0, [r4, r3]
	cmp r1, r0
	bgt .L080489DE
	adds r0, r2, #1
	strh r0, [r4, #0x2c]
.L080489DE:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start NewEkrUnitKakudai
NewEkrUnitKakudai: @ 0x080489E8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, .L08048A14 @ =ProcScr_EkrUnitKakudai
	movs r1, #3
	bl SpawnProc
	adds r4, r0, #0
	str r5, [r4, #0x44]
	movs r1, #0
	str r1, [r4, #0x50]
	str r1, [r4, #0x4c]
	ldr r0, .L08048A18 @ =gEkrDistanceType
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt .L08048A5E
	cmp r0, #3
	ble .L08048A1C
	cmp r0, #4
	beq .L08048A4C
	b .L08048A5E
	.align 2, 0
.L08048A14: .4byte ProcScr_EkrUnitKakudai
.L08048A18: .4byte gEkrDistanceType
.L08048A1C:
	ldr r0, .L08048A48 @ =gBanimValid
	movs r1, #0
	ldrsh r5, [r0, r1]
	cmp r5, #1
	bne .L08048A30
	bl GetDragonPosition
	cmp r0, #0
	beq .L08048A30
	str r5, [r4, #0x4c]
.L08048A30:
	ldr r0, .L08048A48 @ =gBanimValid
	movs r2, #2
	ldrsh r5, [r0, r2]
	cmp r5, #1
	bne .L08048A5E
	bl GetDragonPosition
	cmp r0, #1
	beq .L08048A5E
	str r5, [r4, #0x50]
	b .L08048A5E
	.align 2, 0
.L08048A48: .4byte gBanimValid
.L08048A4C:
	cmp r5, #0
	bne .L08048A58
	str r1, [r4, #0x4c]
	movs r0, #1
	str r0, [r4, #0x50]
	b .L08048A5E
.L08048A58:
	movs r0, #1
	str r0, [r4, #0x4c]
	str r1, [r4, #0x50]
.L08048A5E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08048A64
func_fe6_08048A64: @ 0x08048A64
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, .L08048B74 @ =gUnk_081122C0
	ldr r0, .L08048B78 @ =gEkrDistanceType
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r0, r0, r1
	ldr r1, .L08048B7C @ =gUnk_08112298
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r6, [r0]
	bl UpdateBanimFrame
	ldr r0, [r4, #0x44]
	cmp r0, #0
	bne .L08048A9C
	ldr r1, .L08048B80 @ =gBattleSt
	movs r0, #0x40
	ldrb r1, [r1, #1]
	ands r0, r1
	cmp r0, #0
	beq .L08048A9C
	ldr r0, .L08048B84 @ =gPal
	movs r1, #0x17
	movs r2, #1
	bl EfxPalModifyPetrifyEffect
.L08048A9C:
	ldr r5, .L08048B88 @ =gBanimValid
	ldrh r3, [r5]
	cmp r3, #1
	bne .L08048AC2
	ldr r0, .L08048B8C @ =gUnk_Banim_02000054
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, .L08048B90 @ =gUnk_Banim_0200F1C0
	adds r1, r1, r0
	ldr r0, [r1, #4]
	ldr r1, [r1, #8]
	ldr r2, .L08048B94 @ =gUnk_Banim_020041C0
	adds r1, r1, r2
	str r1, [r4, #0x54]
	ldr r1, .L08048B98 @ =gUnk_Banim_02000080
	bl LZ77UnCompWram
.L08048AC2:
	ldrh r5, [r5, #2]
	cmp r5, #1
	bne .L08048AE6
	ldr r0, .L08048B9C @ =gUnk_Banim_02000058
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, .L08048BA0 @ =gUnk_Banim_02011BC0
	adds r1, r1, r0
	ldr r0, [r1, #4]
	ldr r1, [r1, #8]
	ldr r2, .L08048BA4 @ =gUnk_Banim_020099C0
	adds r1, r1, r2
	str r1, [r4, #0x58]
	ldr r1, .L08048BA8 @ =gUnk_Banim_02002080
	bl LZ77UnCompWram
.L08048AE6:
	ldr r5, .L08048BAC @ =0x0203CD98
	ldr r0, [r5]
	cmp r0, #0
	beq .L08048AF4
	ldr r1, .L08048BB0 @ =gUnk_Banim_02001080
	bl LZ77UnCompWram
.L08048AF4:
	ldr r0, [r5, #4]
	cmp r0, #0
	beq .L08048B00
	ldr r1, .L08048BB4 @ =gUnk_Banim_02003080
	bl LZ77UnCompWram
.L08048B00:
	ldr r1, .L08048BB8 @ =0x06014000
	ldr r0, .L08048B98 @ =gUnk_Banim_02000080
	movs r2, #0x80
	lsls r2, r2, #7
	bl RegisterDataMove
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0xb
	strh r0, [r4, #0x2e]
	ldr r1, .L08048BBC @ =gEkrBmLocation
	movs r5, #0
	ldrsh r0, [r1, r5]
	lsls r0, r0, #4
	adds r0, #8
	strh r0, [r4, #0x32]
	movs r2, #2
	ldrsh r0, [r1, r2]
	lsls r0, r0, #4
	adds r0, #8
	strh r0, [r4, #0x3a]
	movs r3, #4
	ldrsh r0, [r1, r3]
	lsls r0, r0, #4
	adds r0, #8
	strh r0, [r4, #0x34]
	movs r5, #6
	ldrsh r0, [r1, r5]
	lsls r0, r0, #4
	adds r0, #8
	strh r0, [r4, #0x3c]
	ldr r1, .L08048BC0 @ =gUnk_081122C5
	ldr r2, .L08048B78 @ =gEkrDistanceType
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r0, r0, r1
	ldrb r5, [r0]
	strh r5, [r4, #0x36]
	ldr r1, .L08048BC4 @ =gUnk_081122CA
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r0, r0, r1
	ldrb r3, [r0]
	strh r3, [r4, #0x38]
	ldr r0, .L08048BC8 @ =gEkrInitPosReal
	ldr r0, [r0]
	cmp r0, #0
	bne .L08048BD0
	ldr r0, .L08048BCC @ =gUnk_081122D0
	movs r5, #0
	ldrsh r1, [r2, r5]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	adds r0, r1, r3
	strh r0, [r4, #0x38]
	b .L08048BE0
	.align 2, 0
.L08048B74: .4byte gUnk_081122C0
.L08048B78: .4byte gEkrDistanceType
.L08048B7C: .4byte gUnk_08112298
.L08048B80: .4byte gBattleSt
.L08048B84: .4byte gPal
.L08048B88: .4byte gBanimValid
.L08048B8C: .4byte gUnk_Banim_02000054
.L08048B90: .4byte gUnk_Banim_0200F1C0
.L08048B94: .4byte gUnk_Banim_020041C0
.L08048B98: .4byte gUnk_Banim_02000080
.L08048B9C: .4byte gUnk_Banim_02000058
.L08048BA0: .4byte gUnk_Banim_02011BC0
.L08048BA4: .4byte gUnk_Banim_020099C0
.L08048BA8: .4byte gUnk_Banim_02002080
.L08048BAC: .4byte 0x0203CD98
.L08048BB0: .4byte gUnk_Banim_02001080
.L08048BB4: .4byte gUnk_Banim_02003080
.L08048BB8: .4byte 0x06014000
.L08048BBC: .4byte gEkrBmLocation
.L08048BC0: .4byte gUnk_081122C5
.L08048BC4: .4byte gUnk_081122CA
.L08048BC8: .4byte gEkrInitPosReal
.L08048BCC: .4byte gUnk_081122D0
.L08048BD0:
	ldr r0, .L08048BEC @ =gUnk_081122D0
	movs r3, #0
	ldrsh r1, [r2, r3]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	subs r0, r5, r1
	strh r0, [r4, #0x36]
.L08048BE0:
	adds r0, r4, #0
	bl Proc_Break
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08048BEC: .4byte gUnk_081122D0

	thumb_func_start func_fe6_08048BF0
func_fe6_08048BF0: @ 0x08048BF0
	push {r4, r5, r6, r7, lr}
	ldr r4, .L08048C10 @ =0xFFFFFCB4
	add sp, r4
	adds r4, r0, #0
	add r5, sp, #0x304
	ldrh r2, [r4, #0x2c]
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	movs r3, #0x2e
	ldrsh r0, [r4, r3]
	cmp r1, r0
	blt .L08048C14
	adds r0, r4, #0
	bl Proc_Break
	b .L08048D8A
	.align 2, 0
.L08048C10: .4byte 0xFFFFFCB4
.L08048C14:
	adds r0, r2, #1
	strh r0, [r4, #0x2c]
	ldr r0, [r4, #0x44]
	cmp r0, #0
	bne .L08048C2C
	movs r1, #0x94
	lsls r1, r1, #2
	movs r2, #0x80
	lsls r2, r2, #1
	movs r6, #0x2c
	ldrsh r3, [r4, r6]
	b .L08048C38
.L08048C2C:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0x94
	lsls r2, r2, #2
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
.L08048C38:
	movs r6, #0x2e
	ldrsh r0, [r4, r6]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r0, [r4, #0x4c]
	cmp r0, #1
	bne .L08048CEA
	ldr r0, [r4, #0x54]
	lsls r3, r7, #0x10
	asrs r3, r3, #0x10
	movs r1, #0
	str r1, [sp]
	add r1, sp, #4
	adds r2, r3, #0
	bl BanimUpdateSpriteRotScale
	ldr r0, [r4, #0x44]
	cmp r0, #0
	bne .L08048C96
	movs r0, #0x32
	ldrsh r1, [r4, r0]
	movs r3, #0x36
	ldrsh r2, [r4, r3]
	movs r6, #0x2c
	ldrsh r3, [r4, r6]
	movs r6, #0x2e
	ldrsh r0, [r4, r6]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0x3a
	ldrsh r1, [r4, r0]
	movs r2, #0x2c
	ldrsh r3, [r4, r2]
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	str r0, [sp]
	movs r0, #0
	movs r2, #0x58
	b .L08048CC4
.L08048C96:
	movs r3, #0x36
	ldrsh r1, [r4, r3]
	movs r6, #0x32
	ldrsh r2, [r4, r6]
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r6, #0x2e
	ldrsh r0, [r4, r6]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0x3a
	ldrsh r2, [r4, r0]
	movs r1, #0x2c
	ldrsh r3, [r4, r1]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0x58
.L08048CC4:
	bl Interpolate
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	add r2, sp, #4
	str r2, [r5, #0x3c]
	movs r0, #0
	strh r6, [r5, #2]
	strh r1, [r5, #4]
	movs r1, #0x80
	lsls r1, r1, #3
	strh r1, [r5, #0xc]
	movs r1, #0xe4
	lsls r1, r1, #7
	strh r1, [r5, #8]
	str r0, [r5, #0x1c]
	adds r0, r5, #0
	bl BasPutOam
.L08048CEA:
	ldr r1, [r4, #0x50]
	cmp r1, #1
	bne .L08048D8A
	ldr r0, [r4, #0x58]
	lsls r3, r7, #0x10
	asrs r3, r3, #0x10
	str r1, [sp]
	add r1, sp, #4
	adds r2, r3, #0
	bl BanimUpdateSpriteRotScale
	ldr r0, [r4, #0x44]
	cmp r0, #0
	bne .L08048D36
	movs r3, #0x34
	ldrsh r1, [r4, r3]
	movs r6, #0x38
	ldrsh r2, [r4, r6]
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r6, #0x2e
	ldrsh r0, [r4, r6]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0x3c
	ldrsh r1, [r4, r0]
	movs r2, #0x2c
	ldrsh r3, [r4, r2]
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	str r0, [sp]
	movs r0, #0
	movs r2, #0x58
	b .L08048D64
.L08048D36:
	movs r3, #0x38
	ldrsh r1, [r4, r3]
	movs r6, #0x34
	ldrsh r2, [r4, r6]
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r6, #0x2e
	ldrsh r0, [r4, r6]
	str r0, [sp]
	movs r0, #0
	bl Interpolate
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0x3c
	ldrsh r2, [r4, r0]
	movs r1, #0x2c
	ldrsh r3, [r4, r1]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r0, #0
	movs r1, #0x58
.L08048D64:
	bl Interpolate
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	add r2, sp, #4
	str r2, [r5, #0x3c]
	movs r0, #0
	strh r6, [r5, #2]
	strh r1, [r5, #4]
	movs r1, #0x80
	lsls r1, r1, #3
	strh r1, [r5, #0xc]
	movs r1, #0x93
	lsls r1, r1, #8
	strh r1, [r5, #8]
	str r0, [r5, #0x1c]
	adds r0, r5, #0
	bl BasPutOam
.L08048D8A:
	movs r3, #0xd3
	lsls r3, r3, #2
	add sp, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08048D98
func_fe6_08048D98: @ 0x08048D98
	push {lr}
	bl Proc_Break
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start NewEkrWindowAppear
NewEkrWindowAppear: @ 0x08048DA4
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, .L08048DE8 @ =ProcScr_EkrWindowAppear
	movs r1, #3
	bl SpawnProc
	str r5, [r0, #0x44]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r4, [r0, #0x2e]
	movs r1, #0x39
	strh r1, [r0, #0x30]
	movs r2, #0
	cmp r5, #0
	bne .L08048DC6
	movs r2, #0x39
.L08048DC6:
	ldr r1, .L08048DEC @ =gEkrBg0QuakeVec
	movs r3, #0
	ldrsh r0, [r1, r3]
	ldrh r1, [r1, #2]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl func_fe6_08043918
	ldr r1, .L08048DF0 @ =gUnk_Banim_0201E0EC
	movs r0, #1
	str r0, [r1]
	bl func_fe6_08043950
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08048DE8: .4byte ProcScr_EkrWindowAppear
.L08048DEC: .4byte gEkrBg0QuakeVec
.L08048DF0: .4byte gUnk_Banim_0201E0EC

	thumb_func_start CheckEkrWindowAppearUnexist
CheckEkrWindowAppearUnexist: @ 0x08048DF4
	ldr r0, .L08048E00 @ =gUnk_Banim_0201E0EC
	ldr r0, [r0]
	cmp r0, #0
	beq .L08048E04
	movs r0, #0
	b .L08048E06
	.align 2, 0
.L08048E00: .4byte gUnk_Banim_0201E0EC
.L08048E04:
	movs r0, #1
.L08048E06:
	bx lr

	thumb_func_start func_fe6_08048E08
func_fe6_08048E08: @ 0x08048E08
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrh r2, [r4, #0x2c]
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	movs r3, #0x2e
	ldrsh r0, [r4, r3]
	cmp r1, r0
	blt .L08048E34
	ldr r1, .L08048E30 @ =gUnk_Banim_0201E0EC
	movs r0, #0
	str r0, [r1]
	bl func_fe6_08043940
	adds r0, r4, #0
	bl Proc_Break
	b .L08048E7C
	.align 2, 0
.L08048E30: .4byte gUnk_Banim_0201E0EC
.L08048E34:
	adds r0, r2, #1
	strh r0, [r4, #0x2c]
	ldr r0, [r4, #0x44]
	cmp r0, #0
	bne .L08048E52
	movs r0, #0x30
	ldrsh r1, [r4, r0]
	movs r2, #0x2c
	ldrsh r3, [r4, r2]
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	str r0, [sp]
	movs r0, #1
	movs r2, #0
	b .L08048E64
.L08048E52:
	movs r3, #0x30
	ldrsh r2, [r4, r3]
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r0, #4
	movs r1, #0
.L08048E64:
	bl Interpolate
	adds r2, r0, #0
	ldr r1, .L08048E84 @ =gEkrBg0QuakeVec
	movs r3, #0
	ldrsh r0, [r1, r3]
	ldrh r1, [r1, #2]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl func_fe6_08043918
.L08048E7C:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08048E84: .4byte gEkrBg0QuakeVec

	thumb_func_start NewEkrNamewinAppear
NewEkrNamewinAppear: @ 0x08048E88
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	ldr r0, .L08048EB8 @ =ProcScr_EkrNamewinAppear
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x44]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	strh r6, [r0, #0x30]
	subs r1, #0x31
	str r1, [r0, #0x48]
	cmp r4, #0
	bne .L08048EBC
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0
	bl func_fe6_0804421C
	b .L08048EC4
	.align 2, 0
.L08048EB8: .4byte ProcScr_EkrNamewinAppear
.L08048EBC:
	movs r0, #0
	movs r1, #0
	bl func_fe6_0804421C
.L08048EC4:
	ldr r1, .L08048ED4 @ =gUnk_Banim_0201E0F0
	movs r0, #1
	str r0, [r1]
	bl func_fe6_08044254
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08048ED4: .4byte gUnk_Banim_0201E0F0

	thumb_func_start CheckEkrNamewinAppearUnexist
CheckEkrNamewinAppearUnexist: @ 0x08048ED8
	ldr r0, .L08048EE4 @ =gUnk_Banim_0201E0F0
	ldr r0, [r0]
	cmp r0, #0
	beq .L08048EE8
	movs r0, #0
	b .L08048EEA
	.align 2, 0
.L08048EE4: .4byte gUnk_Banim_0201E0F0
.L08048EE8:
	movs r0, #1
.L08048EEA:
	bx lr

	thumb_func_start func_fe6_08048EEC
func_fe6_08048EEC: @ 0x08048EEC
	push {lr}
	adds r1, r0, #0
	ldrh r0, [r1, #0x2c]
	ldrh r2, [r1, #0x30]
	cmp r0, r2
	bne .L08048F04
	movs r0, #0
	strh r0, [r1, #0x2c]
	adds r0, r1, #0
	bl Proc_Break
	b .L08048F08
.L08048F04:
	adds r0, #1
	strh r0, [r1, #0x2c]
.L08048F08:
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08048F0C
func_fe6_08048F0C: @ 0x08048F0C
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrh r2, [r4, #0x2c]
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	movs r3, #0x2e
	ldrsh r0, [r4, r3]
	cmp r1, r0
	blt .L08048F40
	ldr r0, .L08048F3C @ =gUnk_Banim_0201E0F0
	movs r1, #0
	str r1, [r0]
	bl func_fe6_08044244
	ldr r0, [r4, #0x44]
	cmp r0, #2
	bne .L08048F34
	bl EndEkrDispUP
.L08048F34:
	adds r0, r4, #0
	bl Proc_Break
	b .L08048F7E
	.align 2, 0
.L08048F3C: .4byte gUnk_Banim_0201E0F0
.L08048F40:
	adds r0, r2, #1
	strh r0, [r4, #0x2c]
	ldr r0, [r4, #0x44]
	cmp r0, #0
	bne .L08048F60
	ldr r1, [r4, #0x48]
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	str r0, [sp]
	movs r0, #1
	movs r2, #0
	bl Interpolate
	b .L08048F74
.L08048F60:
	ldr r2, [r4, #0x48]
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r0, #4
	movs r1, #0
	bl Interpolate
.L08048F74:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0
	bl func_fe6_0804421C
.L08048F7E:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start NewEkrBaseAppear
NewEkrBaseAppear: @ 0x08048F88
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, .L08048FAC @ =ProcScr_EkrBaseAppear
	movs r1, #3
	bl SpawnProc
	str r4, [r0, #0x44]
	movs r1, #0
	strh r1, [r0, #0x2c]
	strh r5, [r0, #0x2e]
	cmp r4, #0
	bne .L08048FB4
	ldr r2, .L08048FB0 @ =0x0000FFA8
	movs r0, #2
	bl SetBgOffset
	b .L08048FBE
	.align 2, 0
.L08048FAC: .4byte ProcScr_EkrBaseAppear
.L08048FB0: .4byte 0x0000FFA8
.L08048FB4:
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl SetBgOffset
.L08048FBE:
	ldr r1, .L08048FCC @ =gProcEkrBaseAppearExist
	movs r0, #1
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08048FCC: .4byte gProcEkrBaseAppearExist

	thumb_func_start CheckEkrBaseAppearUnexist
CheckEkrBaseAppearUnexist: @ 0x08048FD0
	ldr r0, .L08048FDC @ =gProcEkrBaseAppearExist
	ldr r0, [r0]
	cmp r0, #0
	beq .L08048FE0
	movs r0, #0
	b .L08048FE2
	.align 2, 0
.L08048FDC: .4byte gProcEkrBaseAppearExist
.L08048FE0:
	movs r0, #1
.L08048FE2:
	bx lr

	thumb_func_start EkrBaseAppear_Loop
EkrBaseAppear_Loop: @ 0x08048FE4
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrh r2, [r4, #0x2c]
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	movs r3, #0x2e
	ldrsh r0, [r4, r3]
	cmp r1, r0
	blt .L0804900C
	ldr r1, .L08049008 @ =gProcEkrBaseAppearExist
	movs r0, #0
	str r0, [r1]
	adds r0, r4, #0
	bl Proc_Break
	b .L08049050
	.align 2, 0
.L08049008: .4byte gProcEkrBaseAppearExist
.L0804900C:
	adds r0, r2, #1
	strh r0, [r4, #0x2c]
	ldr r0, [r4, #0x44]
	cmp r0, #0
	bne .L0804902E
	movs r1, #0x50
	rsbs r1, r1, #0
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	str r0, [sp]
	movs r0, #1
	movs r2, #0
	bl Interpolate
	b .L08049044
.L0804902E:
	movs r2, #0x50
	rsbs r2, r2, #0
	movs r0, #0x2c
	ldrsh r3, [r4, r0]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	str r0, [sp]
	movs r0, #4
	movs r1, #0
	bl Interpolate
.L08049044:
	lsls r2, r0, #0x10
	lsrs r2, r2, #0x10
	movs r0, #2
	movs r1, #0
	bl SetBgOffset
.L08049050:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
