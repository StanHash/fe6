	.include "macro.inc"

	.syntax unified

	thumb_func_start func_fe6_0808439C
func_fe6_0808439C: @ 0x0808439C
	push {lr}
	sub sp, #0x20
	bl EraseSaveData
	ldr r1, .L08084408 @ =gUnk_08327314
	mov r0, sp
	bl StringCopy
	ldr r0, .L0808440C @ =0x00011217
	str r0, [sp, #8]
	mov r1, sp
	movs r3, #0
	ldr r0, .L08084410 @ =0x0000200A
	strh r0, [r1, #0xc]
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r2, [r1, #0xe]
	ands r0, r2
	strb r0, [r1, #0xe]
	mov r2, sp
	movs r1, #5
	rsbs r1, r1, #0
	ands r1, r0
	strb r1, [r2, #0xe]
	mov r0, sp
	movs r2, #3
	rsbs r2, r2, #0
	ands r2, r1
	strb r2, [r0, #0xe]
	mov r1, sp
	movs r0, #9
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1, #0xe]
	movs r0, #0xf
	ldrh r2, [r1, #0xe]
	ands r0, r2
	strh r0, [r1, #0xe]
	mov r0, sp
	strb r3, [r0, #0x1f]
	strb r3, [r0, #0x1e]
	add r1, sp, #0x10
	movs r2, #0
	adds r0, #0x1b
.L080843F4:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge .L080843F4
	mov r0, sp
	bl SaveGlobalSaveInfo
	add sp, #0x20
	pop {r0}
	bx r0
	.align 2, 0
.L08084408: .4byte gUnk_08327314
.L0808440C: .4byte 0x00011217
.L08084410: .4byte 0x0000200A

	thumb_func_start func_fe6_08084414
func_fe6_08084414: @ 0x08084414
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, .L08084424 @ =gUnk_08689DD8
	ldr r1, [r1]
	adds r1, r1, r0
	adds r0, r1, #0
	bx lr
	.align 2, 0
.L08084424: .4byte gUnk_08689DD8

	thumb_func_start func_fe6_08084428
func_fe6_08084428: @ 0x08084428
	ldr r1, .L08084434 @ =gUnk_08689DD8
	ldr r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bx lr
	.align 2, 0
.L08084434: .4byte gUnk_08689DD8

	thumb_func_start func_fe6_08084438
func_fe6_08084438: @ 0x08084438
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r5, r1, #0
	cmp r4, #0
	bne .L08084446
	mov r4, sp
.L08084446:
	ldr r2, .L08084474 @ =ReadSramFast
	ldr r0, .L08084478 @ =gUnk_08689DD8
	lsls r1, r5, #4
	adds r1, #0x20
	ldr r0, [r0]
	adds r0, r0, r1
	ldr r3, [r2]
	adds r1, r4, #0
	movs r2, #0x10
	bl _call_via_r3
	ldr r0, .L0808447C @ =0x0000200A
	ldrh r1, [r4, #4]
	cmp r1, r0
	bne .L080844C8
	cmp r5, #6
	bhi .L080844C8
	lsls r0, r5, #2
	ldr r1, .L08084480 @ =.L08084484
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08084474: .4byte ReadSramFast
.L08084478: .4byte gUnk_08689DD8
.L0808447C: .4byte 0x0000200A
.L08084480: .4byte .L08084484
.L08084484: @ jump table
	.4byte .L080844A0 @ case 0
	.4byte .L080844A0 @ case 1
	.4byte .L080844A0 @ case 2
	.4byte .L080844A0 @ case 3
	.4byte .L080844A0 @ case 4
	.4byte .L080844A8 @ case 5
	.4byte .L080844B0 @ case 6
.L080844A0:
	ldr r1, .L080844A4 @ =0x00011217
	b .L080844B2
	.align 2, 0
.L080844A4: .4byte 0x00011217
.L080844A8:
	ldr r1, .L080844AC @ =0x00020112
	b .L080844B2
	.align 2, 0
.L080844AC: .4byte 0x00020112
.L080844B0:
	ldr r1, .L080844C4 @ =0x00020223
.L080844B2:
	ldr r0, [r4]
	cmp r0, r1
	bne .L080844C8
	adds r0, r4, #0
	bl func_fe6_08085F74
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b .L080844CA
	.align 2, 0
.L080844C4: .4byte 0x00020223
.L080844C8:
	movs r0, #0
.L080844CA:
	add sp, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_080844D4
func_fe6_080844D4: @ 0x080844D4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	movs r7, #0
	movs r5, #0
	ldr r0, .L08084504 @ =0x0000200A
	strh r0, [r4, #4]
	adds r0, r6, #0
	bl func_fe6_08084560
	strh r0, [r4, #8]
	cmp r6, #6
	bgt .L08084556
	ldrb r0, [r4, #6]
	cmp r0, #2
	beq .L08084524
	cmp r0, #2
	bgt .L08084508
	cmp r0, #0
	beq .L08084512
	cmp r0, #1
	beq .L0808451A
	b .L08084556
	.align 2, 0
.L08084504: .4byte 0x0000200A
.L08084508:
	cmp r0, #3
	beq .L08084530
	cmp r0, #0xff
	beq .L08084538
	b .L08084556
.L08084512:
	movs r0, #0xdf
	lsls r0, r0, #4
	strh r0, [r4, #0xa]
	b .L0808453E
.L0808451A:
	ldr r0, .L08084520 @ =0x00001DAC
	strh r0, [r4, #0xa]
	b .L0808453E
	.align 2, 0
.L08084520: .4byte 0x00001DAC
.L08084524:
	ldr r0, .L0808452C @ =0x0000093C
	strh r0, [r4, #0xa]
	b .L0808453E
	.align 2, 0
.L0808452C: .4byte 0x0000093C
.L08084530:
	movs r0, #0x80
	lsls r0, r0, #5
	strh r0, [r4, #0xa]
	b .L0808453E
.L08084538:
	strh r5, [r4, #0xa]
	strh r5, [r4, #8]
	strh r5, [r4, #4]
.L0808453E:
	adds r0, r4, #0
	bl func_fe6_08085F98
	ldr r0, .L0808455C @ =gUnk_08689DD8
	lsls r2, r6, #4
	adds r2, #0x20
	ldr r1, [r0]
	adds r1, r1, r2
	adds r0, r4, #0
	movs r2, #0x10
	bl WriteAndVerifySramFast
.L08084556:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0808455C: .4byte gUnk_08689DD8

	thumb_func_start func_fe6_08084560
func_fe6_08084560: @ 0x08084560
	cmp r0, #6
	bhi .L08084608
	lsls r0, r0, #2
	ldr r1, .L08084570 @ =.L08084574
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08084570: .4byte .L08084574
.L08084574: @ jump table
	.4byte .L08084590 @ case 0
	.4byte .L080845A4 @ case 1
	.4byte .L080845B8 @ case 2
	.4byte .L080845CC @ case 3
	.4byte .L080845D8 @ case 4
	.4byte .L080845EC @ case 5
	.4byte .L08084600 @ case 6
.L08084590:
	ldr r0, .L0808459C @ =gUnk_08689DD8
	ldr r0, [r0]
	ldr r1, .L080845A0 @ =0x00003BE8
	adds r0, r0, r1
	b .L0808460A
	.align 2, 0
.L0808459C: .4byte gUnk_08689DD8
.L080845A0: .4byte 0x00003BE8
.L080845A4:
	ldr r0, .L080845B0 @ =gUnk_08689DD8
	ldr r0, [r0]
	ldr r1, .L080845B4 @ =0x000049D8
	adds r0, r0, r1
	b .L0808460A
	.align 2, 0
.L080845B0: .4byte gUnk_08689DD8
.L080845B4: .4byte 0x000049D8
.L080845B8:
	ldr r0, .L080845C4 @ =gUnk_08689DD8
	ldr r0, [r0]
	ldr r1, .L080845C8 @ =0x000057C8
	adds r0, r0, r1
	b .L0808460A
	.align 2, 0
.L080845C4: .4byte gUnk_08689DD8
.L080845C8: .4byte 0x000057C8
.L080845CC:
	ldr r0, .L080845D4 @ =gUnk_08689DD8
	ldr r0, [r0]
	adds r0, #0x90
	b .L0808460A
	.align 2, 0
.L080845D4: .4byte gUnk_08689DD8
.L080845D8:
	ldr r0, .L080845E4 @ =gUnk_08689DD8
	ldr r0, [r0]
	ldr r1, .L080845E8 @ =0x00001E3C
	adds r0, r0, r1
	b .L0808460A
	.align 2, 0
.L080845E4: .4byte gUnk_08689DD8
.L080845E8: .4byte 0x00001E3C
.L080845EC:
	ldr r0, .L080845F8 @ =gUnk_08689DD8
	ldr r0, [r0]
	ldr r1, .L080845FC @ =0x000065B8
	adds r0, r0, r1
	b .L0808460A
	.align 2, 0
.L080845F8: .4byte gUnk_08689DD8
.L080845FC: .4byte 0x000065B8
.L08084600:
	ldr r0, .L08084604 @ =0x0E007000
	b .L0808460A
	.align 2, 0
.L08084604: .4byte 0x0E007000
.L08084608:
	movs r0, #0
.L0808460A:
	bx lr

	thumb_func_start func_fe6_0808460C
func_fe6_0808460C: @ 0x0808460C
	push {lr}
	sub sp, #0x10
	adds r1, r0, #0
	mov r0, sp
	bl func_fe6_08084438
	mov r0, sp
	ldrh r0, [r0, #8]
	bl func_fe6_08084414
	add sp, #0x10
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08084628
func_fe6_08084628: @ 0x08084628
	push {r4, r5, lr}
	adds r4, r0, #0
	bl GetChapterFlagBits
	adds r5, r0, #0
	bl GetChapterFlagBitsSize
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl WriteAndVerifySramFast
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08084648
func_fe6_08084648: @ 0x08084648
	push {r4, r5, lr}
	adds r4, r0, #0
	bl GetPermanentFlagBits
	adds r5, r0, #0
	bl GetPermanentFlagBitsSize
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl WriteAndVerifySramFast
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08084668
func_fe6_08084668: @ 0x08084668
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r4, .L0808468C @ =ReadSramFast
	bl GetChapterFlagBits
	adds r5, r0, #0
	bl GetChapterFlagBitsSize
	adds r2, r0, #0
	ldr r3, [r4]
	adds r0, r6, #0
	adds r1, r5, #0
	bl _call_via_r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L0808468C: .4byte ReadSramFast

	thumb_func_start func_fe6_08084690
func_fe6_08084690: @ 0x08084690
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r4, .L080846B4 @ =ReadSramFast
	bl GetPermanentFlagBits
	adds r5, r0, #0
	bl GetPermanentFlagBitsSize
	adds r2, r0, #0
	ldr r3, [r4]
	adds r0, r6, #0
	adds r1, r5, #0
	bl _call_via_r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080846B4: .4byte ReadSramFast

	thumb_func_start func_fe6_080846B8
func_fe6_080846B8: @ 0x080846B8
	push {r4, lr}
	adds r4, r0, #0
	bl GetSupplyItems
	adds r1, r4, #0
	movs r2, #0xc8
	bl WriteAndVerifySramFast
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_080846D0
func_fe6_080846D0: @ 0x080846D0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, .L080846EC @ =ReadSramFast
	bl GetSupplyItems
	adds r1, r0, #0
	ldr r3, [r4]
	adds r0, r5, #0
	movs r2, #0xc8
	bl _call_via_r3
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L080846EC: .4byte ReadSramFast

	thumb_func_start func_fe6_080846F0
func_fe6_080846F0: @ 0x080846F0
	push {lr}
	sub sp, #0x20
	mov r0, sp
	bl LoadGlobalSaveInfo
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08084704
	movs r0, #0
	b .L0808470C
.L08084704:
	mov r0, sp
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x1f
	lsrs r0, r0, #0x1f
.L0808470C:
	add sp, #0x20
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08084714
func_fe6_08084714: @ 0x08084714
	movs r0, #1
	bx lr

	thumb_func_start func_fe6_08084718
func_fe6_08084718: @ 0x08084718
	push {r4, lr}
	bl IsSramWorking
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08084744
	movs r4, #0
.L08084726:
	adds r0, r4, #0
	bl func_fe6_08085290
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08084736
	movs r0, #1
	b .L08084744
.L08084736:
	adds r4, #1
	cmp r4, #2
	ble .L08084726
	bl func_fe6_08086558
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
.L08084744:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0808474C
func_fe6_0808474C: @ 0x0808474C
	push {lr}
	bl func_fe6_080846F0
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_0808475C
func_fe6_0808475C: @ 0x0808475C
	push {r4, lr}
	sub sp, #0x20
	movs r4, #0
.L08084762:
	adds r0, r4, #0
	bl func_fe6_0808525C
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08084786
	adds r0, r4, #0
	mov r1, sp
	bl func_fe6_08085270
	mov r1, sp
	movs r0, #0x20
	ldrb r1, [r1, #0x14]
	ands r0, r1
	cmp r0, #0
	beq .L08084786
	movs r0, #1
	b .L0808478E
.L08084786:
	adds r4, #1
	cmp r4, #2
	ble .L08084762
	movs r0, #0
.L0808478E:
	add sp, #0x20
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08084798
func_fe6_08084798: @ 0x08084798
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	mov r0, sp
	movs r4, #0
	strh r4, [r0]
	ldr r1, .L080847FC @ =0x0203D534
	ldr r2, .L08084800 @ =0x01000230
	bl CpuSet
	mov r0, sp
	adds r0, #2
	strh r4, [r0]
	ldr r1, .L08084804 @ =0x0203D994
	ldr r2, .L08084808 @ =0x01000040
	bl CpuSet
	ldr r0, .L0808480C @ =0x00000908
	adds r4, r6, r0
	movs r5, #0x45
.L080847C0:
	ldr r0, .L080847FC @ =0x0203D534
	adds r1, r4, #0
	movs r2, #0x10
	bl WriteAndVerifySramFast
	adds r4, #0x10
	subs r5, #1
	cmp r5, #0
	bge .L080847C0
	ldr r2, .L08084810 @ =0x00000D68
	adds r4, r6, r2
	movs r5, #0x1f
.L080847D8:
	ldr r0, .L08084804 @ =0x0203D994
	adds r1, r4, #0
	movs r2, #4
	bl WriteAndVerifySramFast
	adds r4, #4
	subs r5, #1
	cmp r5, #0
	bge .L080847D8
	ldr r1, .L08084814 @ =0x0203D530
	ldr r2, .L0808480C @ =0x00000908
	adds r0, r6, r2
	str r0, [r1]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080847FC: .4byte 0x0203D534
.L08084800: .4byte 0x01000230
.L08084804: .4byte 0x0203D994
.L08084808: .4byte 0x01000040
.L0808480C: .4byte 0x00000908
.L08084810: .4byte 0x00000D68
.L08084814: .4byte 0x0203D530

	thumb_func_start func_fe6_08084818
func_fe6_08084818: @ 0x08084818
	push {lr}
	sub sp, #4
	mov r1, sp
	movs r0, #0
	strh r0, [r1]
	ldr r1, .L08084834 @ =0x0203D534
	ldr r2, .L08084838 @ =0x01000230
	mov r0, sp
	bl CpuSet
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
.L08084834: .4byte 0x0203D534
.L08084838: .4byte 0x01000230

	thumb_func_start func_fe6_0808483C
func_fe6_0808483C: @ 0x0808483C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L0808485C @ =ReadSramFast
	ldr r1, .L08084860 @ =0x0203D534
	movs r2, #0x8c
	lsls r2, r2, #3
	ldr r3, [r0]
	adds r0, r4, #0
	bl _call_via_r3
	ldr r0, .L08084864 @ =0x0203D530
	str r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0808485C: .4byte ReadSramFast
.L08084860: .4byte 0x0203D534
.L08084864: .4byte 0x0203D530

	thumb_func_start func_fe6_08084868
func_fe6_08084868: @ 0x08084868
	push {lr}
	ldr r2, .L0808487C @ =ReadSramFast
	ldr r1, .L08084880 @ =0x0203D994
	ldr r3, [r2]
	movs r2, #0x80
	bl _call_via_r3
	pop {r0}
	bx r0
	.align 2, 0
.L0808487C: .4byte ReadSramFast
.L08084880: .4byte 0x0203D994

	thumb_func_start func_fe6_08084884
func_fe6_08084884: @ 0x08084884
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, .L080848A0 @ =0x0203D534
	movs r2, #0x8c
	lsls r2, r2, #3
	adds r1, r4, #0
	bl WriteAndVerifySramFast
	ldr r0, .L080848A4 @ =0x0203D530
	str r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080848A0: .4byte 0x0203D534
.L080848A4: .4byte 0x0203D530

	thumb_func_start func_fe6_080848A8
func_fe6_080848A8: @ 0x080848A8
	push {lr}
	adds r1, r0, #0
	ldr r0, .L080848B8 @ =0x0203D994
	movs r2, #0x80
	bl WriteAndVerifySramFast
	pop {r0}
	bx r0
	.align 2, 0
.L080848B8: .4byte 0x0203D994

	thumb_func_start func_fe6_080848BC
func_fe6_080848BC: @ 0x080848BC
	lsls r0, r0, #2
	ldr r1, .L080848C4 @ =0x0203D994
	adds r0, r0, r1
	bx lr
	.align 2, 0
.L080848C4: .4byte 0x0203D994

	thumb_func_start func_fe6_080848C8
func_fe6_080848C8: @ 0x080848C8
	ldr r1, .L080848D8 @ =0x0000FFC0
	ldrh r0, [r0]
	ands r1, r0
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
	bx lr
	.align 2, 0
.L080848D8: .4byte 0x0000FFC0

	thumb_func_start func_fe6_080848DC
func_fe6_080848DC: @ 0x080848DC
	push {r4, lr}
	movs r0, #0
	bl func_fe6_080848BC
	adds r1, r0, #0
	movs r2, #0
	ldr r3, .L080848EC @ =0x0000FFC0
	b .L080848F4
	.align 2, 0
.L080848EC: .4byte 0x0000FFC0
.L080848F0:
	adds r2, #1
	adds r1, #4
.L080848F4:
	adds r0, r3, #0
	ldrh r4, [r1]
	ands r0, r4
	cmp r0, #0
	bne .L080848F0
	adds r0, r2, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08084908
func_fe6_08084908: @ 0x08084908
	push {r4, r5, lr}
	adds r5, r0, #0
	bl func_fe6_080848DC
	bl func_fe6_080848BC
	adds r4, r0, #0
	bl GetGameTime
	ldr r1, [r5, #4]
	subs r0, r0, r1
	movs r1, #0xb4
	bl __udivsi3
	adds r2, r0, #0
	ldr r0, .L08084958 @ =0x0000EA60
	cmp r2, r0
	ble .L0808492E
	adds r2, r0, #0
.L0808492E:
	movs r1, #0x3f
	ldrb r0, [r5, #0xe]
	ands r1, r0
	movs r0, #0x40
	rsbs r0, r0, #0
	ldrb r3, [r4]
	ands r0, r3
	orrs r0, r1
	strb r0, [r4]
	ldrh r5, [r5, #0x10]
	lsls r1, r5, #6
	movs r0, #0x3f
	ldrh r3, [r4]
	ands r0, r3
	orrs r0, r1
	strh r0, [r4]
	strh r2, [r4, #2]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08084958: .4byte 0x0000EA60

	thumb_func_start func_fe6_0808495C
func_fe6_0808495C: @ 0x0808495C
	push {r4, lr}
	adds r1, r0, #0
	movs r0, #0xc0
	ldrb r2, [r1, #0xb]
	ands r0, r2
	cmp r0, #0
	bne .L080849A6
	ldr r0, [r1]
	ldrb r0, [r0, #4]
	adds r4, r0, #0
	cmp r0, #0x45
	bhi .L080849A6
	bl GetPInfo
	ldrb r0, [r0, #9]
	cmp r0, #0
	beq .L080849A6
	lsls r1, r4, #4
	ldr r0, .L080849AC @ =0x0203D524
	adds r2, r1, r0
	cmp r2, #0
	beq .L080849A6
	ldrh r3, [r2, #0xa]
	lsls r0, r3, #0x12
	lsrs r1, r0, #0x14
	ldr r0, .L080849B0 @ =0x00000F9F
	cmp r1, r0
	bgt .L080849A6
	adds r0, r1, #1
	ldr r4, .L080849B4 @ =0x00000FFF
	adds r1, r4, #0
	ands r0, r1
	lsls r0, r0, #2
	ldr r1, .L080849B8 @ =0xFFFFC003
	ands r1, r3
	orrs r1, r0
	strh r1, [r2, #0xa]
.L080849A6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080849AC: .4byte 0x0203D524
.L080849B0: .4byte 0x00000F9F
.L080849B4: .4byte 0x00000FFF
.L080849B8: .4byte 0xFFFFC003

	thumb_func_start func_fe6_080849BC
func_fe6_080849BC: @ 0x080849BC
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r0, #0
	cmp r0, #0x45
	bhi .L080849F8
	bl GetPInfo
	ldrb r0, [r0, #9]
	cmp r0, #0
	beq .L080849F8
	lsls r1, r4, #4
	ldr r0, .L08084A00 @ =0x0203D524
	adds r2, r1, r0
	cmp r2, #0
	beq .L080849F8
	ldr r3, [r2, #8]
	lsls r0, r3, #0xe
	lsrs r1, r0, #0x16
	ldr r0, .L08084A04 @ =0x000003E7
	cmp r1, r0
	bgt .L080849F8
	adds r0, r1, #1
	ldr r1, .L08084A08 @ =0x000003FF
	ands r0, r1
	lsls r0, r0, #8
	ldr r1, .L08084A0C @ =0xFFFC00FF
	ands r1, r3
	orrs r1, r0
	str r1, [r2, #8]
.L080849F8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08084A00: .4byte 0x0203D524
.L08084A04: .4byte 0x000003E7
.L08084A08: .4byte 0x000003FF
.L08084A0C: .4byte 0xFFFC00FF

	thumb_func_start func_fe6_08084A10
func_fe6_08084A10: @ 0x08084A10
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r5, r4, #0
	bl IsSramWorking
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08084AD0
	cmp r4, #0x45
	bhi .L08084AD0
	adds r0, r4, #0
	bl GetPInfo
	ldrb r0, [r0, #9]
	cmp r0, #0
	beq .L08084AD0
	lsls r6, r5, #4
	ldr r0, .L08084AD8 @ =0x0203D524
	adds r5, r6, r0
	cmp r5, #0
	beq .L08084AD0
	ldr r1, .L08084ADC @ =gBmSt
	adds r0, r1, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #1
	beq .L08084AD0
	ldr r7, .L08084AE0 @ =gPlaySt
	ldrb r3, [r7, #0x14]
	movs r0, #8
	ands r0, r3
	cmp r0, #0
	bne .L08084AD0
	ldrb r1, [r1, #4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	bne .L08084AD0
	movs r2, #0x20
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne .L08084AD0
	adds r0, r2, #0
	ands r0, r3
	cmp r0, #0
	bne .L08084AD0
	ldrb r0, [r5]
	cmp r0, #0xc7
	bhi .L08084AD0
	adds r0, #1
	strb r0, [r5]
	bl func_fe6_08085EF4
	adds r4, r0, #0
	adds r4, #3
	adds r0, r4, #0
	bl func_fe6_08084560
	adds r1, r0, #0
	ldr r2, .L08084AE4 @ =0x000018B0
	adds r0, r6, r2
	adds r1, r1, r0
	adds r0, r5, #0
	movs r2, #1
	bl WriteAndVerifySramFast
	mov r0, sp
	adds r1, r4, #0
	bl func_fe6_08084438
	mov r0, sp
	adds r1, r4, #0
	bl func_fe6_080844D4
	ldrb r0, [r7, #0xc]
	bl func_fe6_08084560
	adds r1, r0, #0
	ldr r2, .L08084AE8 @ =0x000008F8
	adds r0, r6, r2
	adds r1, r1, r0
	adds r0, r5, #0
	movs r2, #1
	bl WriteAndVerifySramFast
	ldrb r1, [r7, #0xc]
	mov r0, sp
	bl func_fe6_08084438
	ldrb r1, [r7, #0xc]
	mov r0, sp
	bl func_fe6_080844D4
.L08084AD0:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08084AD8: .4byte 0x0203D524
.L08084ADC: .4byte gBmSt
.L08084AE0: .4byte gPlaySt
.L08084AE4: .4byte 0x000018B0
.L08084AE8: .4byte 0x000008F8

	thumb_func_start func_fe6_08084AEC
func_fe6_08084AEC: @ 0x08084AEC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r2, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r0, #0
	lsls r1, r1, #0x18
	mov r8, r1
	lsrs r6, r1, #0x18
	cmp r0, #0x45
	bhi .L08084B70
	bl GetPInfo
	ldrb r0, [r0, #9]
	cmp r0, #0
	beq .L08084B70
	lsls r1, r4, #4
	ldr r0, .L08084B7C @ =0x0203D524
	adds r5, r1, r0
	cmp r5, #0
	beq .L08084B70
	ldr r2, .L08084B80 @ =gPlaySt
	movs r1, #0xe
	ldrsb r1, [r2, r1]
	movs r0, #0x3f
	ands r1, r0
	movs r0, #0x40
	rsbs r0, r0, #0
	ldrb r3, [r5, #3]
	ands r0, r3
	orrs r0, r1
	strb r0, [r5, #3]
	ldrh r3, [r2, #0x10]
	movs r4, #3
	adds r2, r3, #0
	ands r2, r4
	lsls r2, r2, #6
	movs r1, #0x3f
	ands r0, r1
	orrs r0, r2
	strb r0, [r5, #3]
	lsrs r3, r3, #2
	strb r3, [r5, #4]
	ands r6, r4
	lsls r0, r6, #6
	ldrb r2, [r5, #0xb]
	ands r1, r2
	orrs r1, r0
	strb r1, [r5, #0xb]
	mov r3, r8
	lsrs r1, r3, #0x1a
	movs r0, #0x80
	rsbs r0, r0, #0
	ldrb r2, [r5, #0xc]
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, #0xc]
	movs r0, #0xf
	ands r7, r0
	movs r0, #0x10
	rsbs r0, r0, #0
	ldrb r3, [r5, #7]
	ands r0, r3
	orrs r0, r7
	strb r0, [r5, #7]
.L08084B70:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08084B7C: .4byte 0x0203D524
.L08084B80: .4byte gPlaySt

	thumb_func_start func_fe6_08084B84
func_fe6_08084B84: @ 0x08084B84
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r0, #0
	cmp r0, #0x45
	bhi .L08084BAE
	bl GetPInfo
	ldrb r0, [r0, #9]
	cmp r0, #0
	beq .L08084BAE
	lsls r1, r4, #4
	ldr r0, .L08084BB4 @ =0x0203D524
	adds r1, r1, r0
	cmp r1, #0
	beq .L08084BAE
	ldrb r0, [r1, #1]
	cmp r0, #0xc7
	bhi .L08084BAE
	adds r0, #1
	strb r0, [r1, #1]
.L08084BAE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08084BB4: .4byte 0x0203D524

	thumb_func_start func_fe6_08084BB8
func_fe6_08084BB8: @ 0x08084BB8
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r0, #0
	cmp r0, #0x45
	bhi .L08084BE2
	bl GetPInfo
	ldrb r0, [r0, #9]
	cmp r0, #0
	beq .L08084BE2
	lsls r1, r4, #4
	ldr r0, .L08084BE8 @ =0x0203D524
	adds r1, r1, r0
	cmp r1, #0
	beq .L08084BE2
	ldrb r0, [r1, #2]
	cmp r0, #0xc7
	bhi .L08084BE2
	adds r0, #1
	strb r0, [r1, #2]
.L08084BE2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08084BE8: .4byte 0x0203D524

	thumb_func_start func_fe6_08084BEC
func_fe6_08084BEC: @ 0x08084BEC
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r0, #0
	cmp r0, #0x45
	bhi .L08084C26
	bl GetPInfo
	ldrb r0, [r0, #9]
	cmp r0, #0
	beq .L08084C26
	lsls r1, r4, #4
	ldr r0, .L08084C2C @ =0x0203D524
	adds r2, r1, r0
	cmp r2, #0
	beq .L08084C26
	ldrb r3, [r2, #5]
	lsls r0, r3, #0x1a
	lsrs r0, r0, #0x1a
	cmp r0, #0x31
	bgt .L08084C26
	adds r1, r0, #1
	movs r0, #0x3f
	ands r1, r0
	movs r0, #0x40
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, #5]
.L08084C26:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08084C2C: .4byte 0x0203D524

	thumb_func_start PidStatsAddSquaresMoved
PidStatsAddSquaresMoved: @ 0x08084C30
	push {r4, r5, lr}
	adds r5, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r0, #0
	cmp r0, #0x45
	bhi .L08084C72
	bl GetPInfo
	ldrb r0, [r0, #9]
	cmp r0, #0
	beq .L08084C72
	lsls r1, r4, #4
	ldr r0, .L08084C78 @ =0x0203D524
	adds r2, r1, r0
	cmp r2, #0
	beq .L08084C72
	ldr r3, [r2, #4]
	lsls r0, r3, #8
	lsrs r0, r0, #0x16
	adds r0, r0, r5
	movs r1, #0xfa
	lsls r1, r1, #2
	cmp r0, r1
	ble .L08084C64
	adds r0, r1, #0
.L08084C64:
	ldr r1, .L08084C7C @ =0x000003FF
	ands r1, r0
	lsls r1, r1, #0xe
	ldr r0, .L08084C80 @ =0xFF003FFF
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #4]
.L08084C72:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08084C78: .4byte 0x0203D524
.L08084C7C: .4byte 0x000003FF
.L08084C80: .4byte 0xFF003FFF

	thumb_func_start PidStatsAddExpGained
PidStatsAddExpGained: @ 0x08084C84
	push {r4, r5, lr}
	adds r5, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r0, #0
	cmp r0, #0x45
	bhi .L08084CCE
	bl GetPInfo
	ldrb r0, [r0, #9]
	cmp r0, #0
	beq .L08084CCE
	lsls r1, r4, #4
	ldr r0, .L08084CD4 @ =0x0203D524
	adds r3, r1, r0
	cmp r3, #0
	beq .L08084CCE
	ldrb r4, [r3, #7]
	lsrs r1, r4, #4
	ldrb r2, [r3, #8]
	lsls r0, r2, #4
	orrs r0, r1
	adds r2, r0, r5
	movs r0, #0xfa
	lsls r0, r0, #4
	cmp r2, r0
	ble .L08084CBC
	adds r2, r0, #0
.L08084CBC:
	movs r0, #0xf
	adds r1, r2, #0
	ands r1, r0
	lsls r1, r1, #4
	ands r0, r4
	orrs r0, r1
	strb r0, [r3, #7]
	lsrs r0, r2, #4
	strb r0, [r3, #8]
.L08084CCE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08084CD4: .4byte 0x0203D524

	thumb_func_start func_fe6_08084CD8
func_fe6_08084CD8: @ 0x08084CD8
	push {r4, lr}
	movs r3, #0
	ldr r2, .L08084CF8 @ =0x0203D534
	movs r1, #0x45
.L08084CE0:
	ldrh r4, [r2, #0xa]
	lsls r0, r4, #0x12
	lsrs r0, r0, #0x14
	adds r3, r3, r0
	adds r2, #0x10
	subs r1, #1
	cmp r1, #0
	bge .L08084CE0
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
.L08084CF8: .4byte 0x0203D534

	thumb_func_start func_fe6_08084CFC
func_fe6_08084CFC: @ 0x08084CFC
	movs r3, #0
	ldr r2, .L08084D18 @ =0x0203D534
	movs r1, #0x45
.L08084D02:
	ldr r0, [r2, #8]
	lsls r0, r0, #0xe
	lsrs r0, r0, #0x16
	adds r3, r3, r0
	adds r2, #0x10
	subs r1, #1
	cmp r1, #0
	bge .L08084D02
	adds r0, r3, #0
	bx lr
	.align 2, 0
.L08084D18: .4byte 0x0203D534

	thumb_func_start func_fe6_08084D1C
func_fe6_08084D1C: @ 0x08084D1C
	movs r0, #0
	ldr r2, .L08084D30 @ =0x0203D534
	movs r1, #0x45
.L08084D22:
	ldrb r3, [r2]
	adds r0, r3, r0
	adds r2, #0x10
	subs r1, #1
	cmp r1, #0
	bge .L08084D22
	bx lr
	.align 2, 0
.L08084D30: .4byte 0x0203D534

	thumb_func_start func_fe6_08084D34
func_fe6_08084D34: @ 0x08084D34
	push {r4, r5, r6, lr}
	movs r6, #0
	ldr r0, .L08084D60 @ =0x0203D534
	adds r4, r0, #7
	movs r5, #0x45
.L08084D3E:
	ldrb r0, [r4]
	lsrs r1, r0, #4
	ldrb r2, [r4, #1]
	lsls r0, r2, #4
	orrs r0, r1
	movs r1, #0x64
	bl __divsi3
	adds r6, r6, r0
	adds r4, #0x10
	subs r5, #1
	cmp r5, #0
	bge .L08084D3E
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
.L08084D60: .4byte 0x0203D534

	thumb_func_start func_fe6_08084D64
func_fe6_08084D64: @ 0x08084D64
	push {r4, r5, r6, r7, lr}
	movs r7, #0
	movs r5, #0
	ldr r4, .L08084DC0 @ =gBattleUnitA
	adds r0, r4, #0
	bl GetUnitCurrentHp
	cmp r0, #0
	bne .L08084D7A
	adds r7, r4, #0
	ldr r5, .L08084DC4 @ =gBattleUnitB
.L08084D7A:
	ldr r6, .L08084DC4 @ =gBattleUnitB
	adds r0, r6, #0
	bl GetUnitCurrentHp
	cmp r0, #0
	bne .L08084D8A
	adds r7, r6, #0
	adds r5, r4, #0
.L08084D8A:
	cmp r7, #0
	beq .L08084DBA
	cmp r5, #0
	beq .L08084DA4
	movs r0, #0xc0
	ldrb r1, [r5, #0xb]
	ands r0, r1
	cmp r0, #0
	bne .L08084DA4
	ldr r0, [r5]
	ldrb r0, [r0, #4]
	bl func_fe6_080849BC
.L08084DA4:
	cmp r7, #0
	beq .L08084DBA
	movs r0, #0xc0
	ldrb r1, [r7, #0xb]
	ands r0, r1
	cmp r0, #0
	bne .L08084DBA
	ldr r0, [r7]
	ldrb r0, [r0, #4]
	bl func_fe6_08084A10
.L08084DBA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08084DC0: .4byte gBattleUnitA
.L08084DC4: .4byte gBattleUnitB

	thumb_func_start func_fe6_08084DC8
func_fe6_08084DC8: @ 0x08084DC8
	push {r4, r5, r6, lr}
	sub sp, #0x40
	adds r6, r0, #0
	mov r0, sp
	bl LoadGlobalSaveInfo
	movs r4, #0
	add r1, sp, #0x10
.L08084DD8:
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, r6
	beq .L08084E04
	adds r4, #1
	cmp r4, #0xb
	ble .L08084DD8
	movs r4, #0
	add r5, sp, #0x20
.L08084DEA:
	adds r0, r4, #0
	bl func_fe6_0808525C
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08084E08
	adds r0, r4, #0
	adds r1, r5, #0
	bl func_fe6_08085270
	ldrb r0, [r5, #0x18]
	cmp r0, r6
	bne .L08084E08
.L08084E04:
	movs r0, #0
	b .L08084E10
.L08084E08:
	adds r4, #1
	cmp r4, #2
	ble .L08084DEA
	movs r0, #1
.L08084E10:
	add sp, #0x40
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_08084E18
func_fe6_08084E18: @ 0x08084E18
	push {r4, lr}
	movs r4, #1
.L08084E1C:
	adds r0, r4, #0
	bl func_fe6_08084DC8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08084E2C
	adds r0, r4, #0
	b .L08084E32
.L08084E2C:
	adds r4, #1
	cmp r4, #0xff
	ble .L08084E1C
.L08084E32:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start GetGlobalCompletedPlaythroughCount
GetGlobalCompletedPlaythroughCount: @ 0x08084E38
	push {r4, lr}
	sub sp, #0x20
	movs r4, #0
	mov r0, sp
	bl LoadGlobalSaveInfo
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08084E4E
	movs r0, #0
	b .L08084E64
.L08084E4E:
	movs r1, #0
	add r2, sp, #0x10
.L08084E52:
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq .L08084E5C
	adds r4, #1
.L08084E5C:
	adds r1, #1
	cmp r1, #0xb
	ble .L08084E52
	adds r0, r4, #0
.L08084E64:
	add sp, #0x20
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start RegisterCompletedPlaythrough
RegisterCompletedPlaythrough: @ 0x08084E6C
	push {r4, lr}
	movs r3, #0
	adds r4, r0, #0
	adds r4, #0x10
	adds r2, r4, #0
.L08084E76:
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, r1
	beq .L08084E9A
	adds r3, #1
	cmp r3, #0xb
	ble .L08084E76
	movs r3, #0
.L08084E86:
	adds r2, r4, r3
	ldrb r0, [r2]
	cmp r0, #0
	bne .L08084E94
	strb r1, [r2]
	movs r0, #1
	b .L08084E9C
.L08084E94:
	adds r3, #1
	cmp r3, #0xb
	ble .L08084E86
.L08084E9A:
	movs r0, #0
.L08084E9C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08084EA4
func_fe6_08084EA4: @ 0x08084EA4
	push {r4, lr}
	sub sp, #0x20
	mov r0, sp
	bl LoadGlobalSaveInfo
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08084EBE
	bl func_fe6_0808439C
	mov r0, sp
	bl LoadGlobalSaveInfo
.L08084EBE:
	ldr r4, .L08084EFC @ =gPlaySt
	ldrb r1, [r4, #0x18]
	mov r0, sp
	bl RegisterCompletedPlaythrough
	mov r1, sp
	movs r0, #1
	ldrb r2, [r1, #0xe]
	orrs r2, r0
	strb r2, [r1, #0xe]
	movs r0, #0x40
	ldrb r1, [r4, #0x14]
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	rsbs r0, r0, #0
	asrs r1, r0, #0x1f
	movs r0, #2
	ands r1, r0
	ldrb r4, [r4, #0xe]
	cmp r4, #0x19
	bne .L08084EEC
	adds r1, #1
.L08084EEC:
	cmp r1, #2
	beq .L08084F0C
	cmp r1, #2
	bgt .L08084F00
	cmp r1, #1
	beq .L08084F06
	b .L08084F2C
	.align 2, 0
.L08084EFC: .4byte gPlaySt
.L08084F00:
	cmp r1, #3
	beq .L08084F16
	b .L08084F2C
.L08084F06:
	mov r1, sp
	movs r0, #4
	b .L08084F10
.L08084F0C:
	mov r1, sp
	movs r0, #2
.L08084F10:
	orrs r2, r0
	strb r2, [r1, #0xe]
	b .L08084F2C
.L08084F16:
	mov r1, sp
	movs r0, #8
	orrs r0, r2
	strb r0, [r1, #0xe]
	mov r2, sp
	movs r1, #2
	orrs r0, r1
	strb r0, [r2, #0xe]
	movs r1, #4
	orrs r0, r1
	strb r0, [r2, #0xe]
.L08084F2C:
	mov r0, sp
	bl SaveGlobalSaveInfo
	ldr r0, .L08084F44 @ =gPlaySt
	movs r1, #0x20
	ldrb r2, [r0, #0x14]
	orrs r1, r2
	strb r1, [r0, #0x14]
	add sp, #0x20
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08084F44: .4byte gPlaySt

	thumb_func_start func_fe6_08084F48
func_fe6_08084F48: @ 0x08084F48
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_08084F4C
func_fe6_08084F4C: @ 0x08084F4C
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r0, #0
	cmp r4, #0x45
	bhi .L08084F70
	adds r0, r4, #0
	bl GetPInfo
	ldrb r0, [r0, #9]
	cmp r0, #0
	beq .L08084F70
	lsls r0, r4, #4
	ldr r1, .L08084F6C @ =0x0203D524
	adds r0, r0, r1
	b .L08084F72
	.align 2, 0
.L08084F6C: .4byte 0x0203D524
.L08084F70:
	movs r0, #0
.L08084F72:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_08084F78
func_fe6_08084F78: @ 0x08084F78
	push {r4, lr}
	sub sp, #0x20
	adds r4, r0, #0
	mov r0, sp
	bl LoadGlobalSaveInfo
	mov r0, sp
	strb r4, [r0, #0x1e]
	bl SaveGlobalSaveInfoNoChecksum
	add sp, #0x20
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_08084F94
func_fe6_08084F94: @ 0x08084F94
	push {lr}
	sub sp, #0x20
	mov r0, sp
	bl LoadGlobalSaveInfo
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08084FB0
	mov r0, sp
	ldrb r0, [r0, #0x1e]
	cmp r0, #2
	bgt .L08084FB0
	cmp r0, #0
	bge .L08084FB2
.L08084FB0:
	movs r0, #0
.L08084FB2:
	add sp, #0x20
	pop {r1}
	bx r1

	thumb_func_start func_fe6_08084FB8
func_fe6_08084FB8: @ 0x08084FB8
	push {r4, r5, lr}
	sub sp, #0x30
	adds r5, r0, #0
	movs r0, #3
	bl func_fe6_080859E0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08084FE0
	add r4, sp, #0x10
	movs r0, #3
	adds r1, r4, #0
	bl func_fe6_08085A34
	ldrb r0, [r4, #0xc]
	cmp r0, r5
	bne .L08084FE0
	movs r0, #3
	bl func_fe6_08085788
.L08084FE0:
	mov r1, sp
	movs r0, #0xff
	strb r0, [r1, #6]
	mov r0, sp
	adds r1, r5, #0
	bl func_fe6_080844D4
	add sp, #0x30
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08084FF8
func_fe6_08084FF8: @ 0x08084FF8
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x10
	mov sb, r1
	bl func_fe6_0808460C
	adds r6, r0, #0
	mov r0, sb
	bl func_fe6_08084560
	mov r8, r0
	ldr r0, .L08085050 @ =ReadSramFast
	ldr r4, .L08085054 @ =gBuf
	movs r5, #0xdf
	lsls r5, r5, #4
	ldr r3, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl _call_via_r3
	adds r0, r4, #0
	mov r1, r8
	adds r2, r5, #0
	bl WriteAndVerifySramFast
	ldr r0, .L08085058 @ =0x00011217
	str r0, [sp]
	mov r1, sp
	movs r0, #0
	strb r0, [r1, #6]
	mov r0, sp
	mov r1, sb
	bl func_fe6_080844D4
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08085050: .4byte ReadSramFast
.L08085054: .4byte gBuf
.L08085058: .4byte 0x00011217

	thumb_func_start func_fe6_0808505C
func_fe6_0808505C: @ 0x0808505C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x3c
	adds r7, r0, #0
	adds r4, r1, #0
	bl func_fe6_08084560
	adds r6, r0, #0
	adds r0, r4, #0
	bl InitPlayConfig
	bl InitUnits
	bl ClearSupplyItems
	bl ResetPermanentFlags
	movs r0, #3
	bl func_fe6_08085788
	bl func_fe6_08084E18
	adds r1, r0, #0
	ldr r0, .L08085100 @ =gPlaySt
	movs r4, #0
	strb r1, [r0, #0x18]
	strb r7, [r0, #0xc]
	adds r1, r6, #0
	movs r2, #0x20
	bl WriteAndVerifySramFast
	add r0, sp, #0x38
	strh r4, [r0]
	add r4, sp, #0x10
	ldr r2, .L08085104 @ =0x01000014
	adds r1, r4, #0
	bl CpuSet
	mov r8, r4
	adds r4, r6, #0
	adds r4, #0x20
	movs r5, #0x33
.L080850B2:
	mov r0, r8
	adds r1, r4, #0
	movs r2, #0x28
	bl WriteAndVerifySramFast
	adds r4, #0x28
	subs r5, #1
	cmp r5, #0
	bge .L080850B2
	movs r4, #0
	movs r1, #0x84
	lsls r1, r1, #4
	adds r0, r6, r1
	bl func_fe6_080846B8
	adds r0, r6, #0
	bl func_fe6_08084798
	ldr r1, .L08085108 @ =0x00000DE8
	adds r0, r6, r1
	bl func_fe6_08084648
	ldr r0, .L0808510C @ =0x00011217
	str r0, [sp]
	mov r0, sp
	strb r4, [r0, #6]
	adds r1, r7, #0
	bl func_fe6_080844D4
	adds r0, r7, #0
	bl func_fe6_08084F78
	add sp, #0x3c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08085100: .4byte gPlaySt
.L08085104: .4byte 0x01000014
.L08085108: .4byte 0x00000DE8
.L0808510C: .4byte 0x00011217

	thumb_func_start func_fe6_08085110
func_fe6_08085110: @ 0x08085110
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	mov r8, r0
	bl func_fe6_08084560
	adds r7, r0, #0
	movs r0, #3
	bl func_fe6_08085788
	ldr r4, .L0808519C @ =gPlaySt
	mov r0, r8
	strb r0, [r4, #0xc]
	bl GetGameTime
	str r0, [r4]
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0x20
	bl WriteAndVerifySramFast
	adds r4, r7, #0
	adds r4, #0x20
	movs r6, #0
	movs r5, #0x33
.L08085144:
	ldr r0, .L080851A0 @ =gUnitArrayBlue
	adds r0, r6, r0
	adds r1, r4, #0
	bl func_fe6_080852C4
	adds r4, #0x28
	adds r6, #0x48
	subs r5, #1
	cmp r5, #0
	bge .L08085144
	movs r4, #0
	movs r1, #0x84
	lsls r1, r1, #4
	adds r0, r7, r1
	bl func_fe6_080846B8
	ldr r1, .L080851A4 @ =0x00000908
	adds r0, r7, r1
	bl func_fe6_08084884
	ldr r1, .L080851A8 @ =0x00000D68
	adds r0, r7, r1
	bl func_fe6_080848A8
	ldr r1, .L080851AC @ =0x00000DE8
	adds r0, r7, r1
	bl func_fe6_08084648
	ldr r0, .L080851B0 @ =0x00011217
	str r0, [sp]
	mov r0, sp
	strb r4, [r0, #6]
	mov r1, r8
	bl func_fe6_080844D4
	mov r0, r8
	bl func_fe6_08084F78
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L0808519C: .4byte gPlaySt
.L080851A0: .4byte gUnitArrayBlue
.L080851A4: .4byte 0x00000908
.L080851A8: .4byte 0x00000D68
.L080851AC: .4byte 0x00000DE8
.L080851B0: .4byte 0x00011217

	thumb_func_start func_fe6_080851B4
func_fe6_080851B4: @ 0x080851B4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	bl func_fe6_0808460C
	adds r7, r0, #0
	ldr r1, .L08085240 @ =gBmSt
	movs r0, #0x40
	ldrb r1, [r1, #4]
	ands r0, r1
	cmp r0, #0
	bne .L080851D4
	movs r0, #3
	bl func_fe6_08085788
.L080851D4:
	ldr r0, .L08085244 @ =ReadSramFast
	ldr r4, .L08085248 @ =gPlaySt
	ldr r3, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0x20
	bl _call_via_r3
	ldr r0, [r4]
	bl SetGameTime
	mov r0, r8
	strb r0, [r4, #0xc]
	bl InitUnits
	movs r6, #0
	adds r4, r7, #0
	adds r4, #0x20
	movs r5, #0x33
.L080851FA:
	ldr r1, .L0808524C @ =gUnitArrayBlue
	adds r1, r6, r1
	adds r0, r4, #0
	bl func_fe6_080855C4
	adds r6, #0x48
	adds r4, #0x28
	subs r5, #1
	cmp r5, #0
	bge .L080851FA
	movs r1, #0x84
	lsls r1, r1, #4
	adds r0, r7, r1
	bl func_fe6_080846D0
	ldr r1, .L08085250 @ =0x00000DE8
	adds r0, r7, r1
	bl func_fe6_08084690
	ldr r1, .L08085254 @ =0x00000908
	adds r0, r7, r1
	bl func_fe6_0808483C
	ldr r1, .L08085258 @ =0x00000D68
	adds r0, r7, r1
	bl func_fe6_08084868
	mov r0, r8
	bl func_fe6_08084F78
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08085240: .4byte gBmSt
.L08085244: .4byte ReadSramFast
.L08085248: .4byte gPlaySt
.L0808524C: .4byte gUnitArrayBlue
.L08085250: .4byte 0x00000DE8
.L08085254: .4byte 0x00000908
.L08085258: .4byte 0x00000D68

	thumb_func_start func_fe6_0808525C
func_fe6_0808525C: @ 0x0808525C
	push {lr}
	adds r1, r0, #0
	movs r0, #0
	bl func_fe6_08084438
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08085270
func_fe6_08085270: @ 0x08085270
	push {r4, lr}
	adds r4, r1, #0
	bl func_fe6_0808460C
	ldr r1, .L0808528C @ =ReadSramFast
	ldr r3, [r1]
	adds r1, r4, #0
	movs r2, #0x20
	bl _call_via_r3
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0808528C: .4byte ReadSramFast

	thumb_func_start func_fe6_08085290
func_fe6_08085290: @ 0x08085290
	push {r4, lr}
	sub sp, #0x20
	adds r4, r0, #0
	bl func_fe6_0808525C
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080852B8
	adds r0, r4, #0
	mov r1, sp
	bl func_fe6_08085270
	mov r0, sp
	ldrb r0, [r0, #0xe]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	ble .L080852B8
	movs r0, #1
	b .L080852BA
.L080852B8:
	movs r0, #0
.L080852BA:
	add sp, #0x20
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_080852C4
func_fe6_080852C4: @ 0x080852C4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x74
	adds r7, r0, #0
	mov sl, r1
	mov r2, sp
	ldr r0, [r7]
	movs r1, #0x7f
	ldrb r0, [r0, #4]
	ands r1, r0
	movs r5, #0x80
	rsbs r5, r5, #0
	adds r0, r5, #0
	ldrb r3, [r2]
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	ldr r0, [r7, #4]
	movs r1, #0x7f
	ldrb r0, [r0, #4]
	ands r1, r0
	lsls r1, r1, #7
	ldr r4, .L08085594 @ =0xFFFFC07F
	adds r0, r4, #0
	ldrh r6, [r2]
	ands r0, r6
	orrs r0, r1
	strh r0, [r2]
	ldr r0, [r7]
	cmp r0, #0
	bne .L08085322
	add r7, sp, #0x28
	adds r0, r7, #0
	bl ClearUnit
	mov r1, sp
	adds r0, r5, #0
	ldrb r2, [r1]
	ands r0, r2
	strb r0, [r1]
	adds r0, r4, #0
	ldrh r3, [r1]
	ands r0, r3
	strh r0, [r1]
.L08085322:
	movs r1, #0x1f
	ldrb r5, [r7, #8]
	ands r1, r5
	lsls r1, r1, #0xe
	ldr r0, [sp]
	ldr r2, .L08085598 @ =0xFFF83FFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	mov r2, sp
	ldrb r6, [r7, #9]
	lsls r3, r6, #1
	ldrb r1, [r2, #3]
	movs r0, #1
	mov sb, r0
	ands r0, r1
	orrs r0, r3
	strb r0, [r2, #3]
	movs r1, #0xe
	ldrsb r1, [r7, r1]
	movs r0, #0x3f
	ands r1, r0
	movs r0, #0x40
	rsbs r0, r0, #0
	ldrb r3, [r2, #4]
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, #4]
	movs r1, #0xf
	ldrsb r1, [r7, r1]
	movs r5, #0x3f
	mov ip, r5
	mov r6, ip
	ands r1, r6
	lsls r1, r1, #6
	ldr r0, .L0808559C @ =0xFFFFF03F
	ldrh r3, [r2, #4]
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #4]
	movs r2, #0x10
	ldrsb r2, [r7, r2]
	movs r5, #0x3f
	ands r2, r5
	lsls r2, r2, #0xc
	ldr r0, [sp, #4]
	ldr r1, .L080855A0 @ =0xFFFC0FFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #4]
	mov r2, sp
	movs r1, #0x12
	ldrsb r1, [r7, r1]
	movs r6, #0x1f
	ands r1, r6
	lsls r1, r1, #2
	movs r0, #0x7d
	rsbs r0, r0, #0
	ldrb r3, [r2, #6]
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, #6]
	movs r1, #0x13
	ldrsb r1, [r7, r1]
	movs r4, #0x1f
	ands r1, r4
	lsls r1, r1, #7
	ldr r0, .L080855A4 @ =0xFFFFF07F
	ldrh r3, [r2, #6]
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #6]
	mov r3, sp
	movs r2, #0x14
	ldrsb r2, [r7, r2]
	movs r0, #0xf
	mov r8, r0
	adds r1, r2, #0
	ands r1, r0
	lsls r1, r1, #4
	str r1, [sp, #0x70]
	ldrb r1, [r3, #7]
	ands r0, r1
	ldr r1, [sp, #0x70]
	orrs r0, r1
	strb r0, [r3, #7]
	lsrs r2, r2, #4
	mov r0, sb
	ands r2, r0
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r1, [r3, #8]
	ands r0, r1
	orrs r0, r2
	strb r0, [r3, #8]
	movs r1, #0x15
	ldrsb r1, [r7, r1]
	ands r1, r6
	lsls r1, r1, #1
	movs r2, #0x3f
	rsbs r2, r2, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, #8]
	mov r2, sp
	movs r1, #0x16
	ldrsb r1, [r7, r1]
	ands r1, r4
	lsls r1, r1, #6
	ldr r0, .L080855A8 @ =0xFFFFF83F
	ldrh r3, [r2, #8]
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #8]
	movs r1, #0x17
	ldrsb r1, [r7, r1]
	lsls r1, r1, #3
	movs r0, #7
	ldrb r3, [r2, #9]
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, #9]
	movs r1, #0x18
	ldrsb r1, [r7, r1]
	ands r1, r6
	movs r0, #0x20
	rsbs r0, r0, #0
	ldrb r6, [r2, #0xa]
	ands r0, r6
	orrs r0, r1
	strb r0, [r2, #0xa]
	movs r1, #0x1a
	ldrsb r1, [r7, r1]
	ands r1, r4
	lsls r1, r1, #5
	ldr r0, .L080855AC @ =0xFFFFFC1F
	ldrh r3, [r2, #0xa]
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #0xa]
	mov r3, sp
	ldrh r2, [r7, #0x1c]
	adds r1, r2, #0
	ands r1, r5
	lsls r1, r1, #2
	movs r4, #3
	adds r0, r4, #0
	ldrb r6, [r3, #0xb]
	ands r0, r6
	orrs r0, r1
	strb r0, [r3, #0xb]
	lsrs r2, r2, #6
	strb r2, [r3, #0xc]
	ldr r3, .L080855B0 @ =0x00003FFF
	adds r1, r3, #0
	ldrh r0, [r7, #0x1e]
	ands r1, r0
	lsls r1, r1, #8
	ldr r0, [sp, #0xc]
	ldr r2, .L080855B4 @ =0xFFC000FF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	mov r2, sp
	ldrh r1, [r7, #0x20]
	ldr r0, .L080855B8 @ =0x000003FF
	ands r0, r1
	lsls r0, r0, #6
	ldrh r6, [r2, #0xe]
	ands r5, r6
	orrs r5, r0
	strh r5, [r2, #0xe]
	lsrs r1, r1, #0xa
	mov r0, r8
	ands r1, r0
	movs r0, #0x10
	rsbs r0, r0, #0
	ldrb r5, [r2, #0x10]
	ands r0, r5
	orrs r0, r1
	strb r0, [r2, #0x10]
	ldrh r6, [r7, #0x22]
	ands r3, r6
	lsls r3, r3, #4
	ldr r0, [sp, #0x10]
	ldr r1, .L080855BC @ =0xFFFC000F
	ands r0, r1
	orrs r0, r3
	str r0, [sp, #0x10]
	mov r1, sp
	ldrh r2, [r7, #0x24]
	lsls r0, r2, #2
	ldrh r3, [r1, #0x12]
	ands r4, r3
	orrs r4, r0
	strh r4, [r1, #0x12]
	ldrh r0, [r1, #2]
	ldr r4, .L080855C0 @ =0xFFFFFE07
	adds r3, r4, #0
	ands r3, r0
	strh r3, [r1, #2]
	movs r5, #4
	adds r0, r5, #0
	ldrh r6, [r7, #0xc]
	ands r0, r6
	cmp r0, #0
	beq .L080854D2
	mov r2, sp
	mov r1, sb
	mov r0, ip
	ands r1, r0
	lsls r1, r1, #3
	adds r0, r3, #0
	ands r0, r4
	orrs r0, r1
	strh r0, [r2, #2]
.L080854D2:
	movs r6, #8
	adds r0, r6, #0
	ldrh r1, [r7, #0xc]
	ands r0, r1
	cmp r0, #0
	beq .L080854FA
	mov r3, sp
	mov r0, sp
	ldrh r2, [r0, #2]
	lsls r1, r2, #0x17
	lsrs r1, r1, #0x1a
	movs r0, #2
	orrs r1, r0
	mov r0, ip
	ands r1, r0
	lsls r1, r1, #3
	adds r0, r4, #0
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, #2]
.L080854FA:
	movs r0, #0x80
	lsls r0, r0, #7
	ldrh r1, [r7, #0xc]
	ands r0, r1
	cmp r0, #0
	beq .L08085520
	mov r3, sp
	mov r0, sp
	ldrh r2, [r0, #2]
	lsls r0, r2, #0x17
	lsrs r0, r0, #0x1a
	orrs r0, r5
	mov r5, ip
	ands r0, r5
	lsls r0, r0, #3
	adds r1, r4, #0
	ands r1, r2
	orrs r1, r0
	strh r1, [r3, #2]
.L08085520:
	movs r0, #0x80
	lsls r0, r0, #8
	ldrh r1, [r7, #0xc]
	ands r0, r1
	cmp r0, #0
	beq .L08085546
	mov r3, sp
	mov r0, sp
	ldrh r2, [r0, #2]
	lsls r0, r2, #0x17
	lsrs r0, r0, #0x1a
	orrs r0, r6
	mov r5, ip
	ands r0, r5
	lsls r0, r0, #3
	adds r1, r4, #0
	ands r1, r2
	orrs r1, r0
	strh r1, [r3, #2]
.L08085546:
	movs r2, #0
	mov r5, sp
	adds r5, #0x1e
	adds r6, r7, #0
	adds r6, #0x30
	mov r4, sp
	adds r4, #0x16
	adds r3, r7, #0
	adds r3, #0x26
.L08085558:
	adds r0, r4, r2
	adds r1, r3, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #7
	ble .L08085558
	movs r2, #0
	adds r4, r5, #0
	adds r3, r6, #0
.L0808556C:
	adds r0, r4, r2
	adds r1, r3, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #9
	ble .L0808556C
	mov r0, sp
	mov r1, sl
	movs r2, #0x28
	bl WriteAndVerifySramFast
	add sp, #0x74
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08085594: .4byte 0xFFFFC07F
.L08085598: .4byte 0xFFF83FFF
.L0808559C: .4byte 0xFFFFF03F
.L080855A0: .4byte 0xFFFC0FFF
.L080855A4: .4byte 0xFFFFF07F
.L080855A8: .4byte 0xFFFFF83F
.L080855AC: .4byte 0xFFFFFC1F
.L080855B0: .4byte 0x00003FFF
.L080855B4: .4byte 0xFFC000FF
.L080855B8: .4byte 0x000003FF
.L080855BC: .4byte 0xFFFC000F
.L080855C0: .4byte 0xFFFFFE07

	thumb_func_start func_fe6_080855C4
func_fe6_080855C4: @ 0x080855C4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x28
	adds r4, r1, #0
	ldr r1, .L08085784 @ =ReadSramFast
	ldr r3, [r1]
	mov r1, sp
	movs r2, #0x28
	bl _call_via_r3
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, r0, #0x19
	lsrs r0, r0, #0x19
	bl GetPInfo
	str r0, [r4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x12
	lsrs r0, r0, #0x19
	bl GetJInfo
	str r0, [r4, #4]
	ldr r0, [sp]
	lsls r0, r0, #0xd
	lsrs r0, r0, #0x1b
	strb r0, [r4, #8]
	mov r0, sp
	ldrb r0, [r0, #3]
	lsrs r3, r0, #1
	strb r3, [r4, #9]
	mov r0, sp
	ldrb r0, [r0, #4]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1a
	strb r0, [r4, #0xe]
	mov r0, sp
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x14
	lsrs r0, r0, #0x1a
	strb r0, [r4, #0xf]
	ldr r0, [sp, #4]
	lsls r0, r0, #0xe
	lsrs r0, r0, #0x1a
	strb r0, [r4, #0x10]
	mov r0, sp
	ldrb r0, [r0, #6]
	lsls r0, r0, #0x19
	lsrs r0, r0, #0x1b
	strb r0, [r4, #0x12]
	mov r0, sp
	ldrh r0, [r0, #6]
	lsls r0, r0, #0x14
	lsrs r0, r0, #0x1b
	strb r0, [r4, #0x13]
	mov r1, sp
	ldrb r0, [r1, #7]
	lsrs r2, r0, #4
	movs r5, #1
	adds r0, r5, #0
	ldrb r1, [r1, #8]
	ands r0, r1
	lsls r0, r0, #4
	orrs r0, r2
	strb r0, [r4, #0x14]
	mov r0, sp
	ldrb r0, [r0, #8]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1b
	strb r0, [r4, #0x15]
	mov r0, sp
	ldrh r0, [r0, #8]
	lsls r0, r0, #0x15
	lsrs r0, r0, #0x1b
	strb r0, [r4, #0x16]
	mov r0, sp
	ldrb r0, [r0, #9]
	lsrs r0, r0, #3
	strb r0, [r4, #0x17]
	mov r0, sp
	ldrb r0, [r0, #0xa]
	lsls r0, r0, #0x1b
	lsrs r0, r0, #0x1b
	strb r0, [r4, #0x18]
	mov r0, sp
	ldrh r0, [r0, #0xa]
	lsls r0, r0, #0x16
	lsrs r0, r0, #0x1b
	strb r0, [r4, #0x1a]
	mov r0, sp
	ldrb r2, [r0, #0xb]
	lsrs r1, r2, #2
	ldrb r0, [r0, #0xc]
	lsls r0, r0, #6
	orrs r0, r1
	strh r0, [r4, #0x1c]
	ldr r0, [sp, #0xc]
	lsls r0, r0, #0xa
	lsrs r0, r0, #0x12
	strh r0, [r4, #0x1e]
	mov r1, sp
	ldrh r0, [r1, #0xe]
	lsrs r2, r0, #6
	movs r0, #0xf
	ldrb r1, [r1, #0x10]
	ands r0, r1
	lsls r0, r0, #0xa
	orrs r0, r2
	strh r0, [r4, #0x20]
	ldr r0, [sp, #0x10]
	lsls r0, r0, #0xe
	lsrs r0, r0, #0x12
	strh r0, [r4, #0x22]
	mov r0, sp
	ldrh r0, [r0, #0x12]
	lsrs r0, r0, #2
	strh r0, [r4, #0x24]
	cmp r3, #0x63
	bls .L080856B6
	movs r0, #0xff
	strb r0, [r4, #9]
.L080856B6:
	movs r0, #0
	strh r0, [r4, #0xc]
	mov r0, sp
	ldrh r0, [r0, #2]
	lsls r0, r0, #0x17
	lsrs r0, r0, #0x1a
	ands r0, r5
	cmp r0, #0
	beq .L080856CC
	movs r0, #5
	strh r0, [r4, #0xc]
.L080856CC:
	mov r0, sp
	ldrh r0, [r0, #2]
	lsls r0, r0, #0x17
	lsrs r0, r0, #0x1a
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq .L080856E4
	movs r0, #9
	ldrh r1, [r4, #0xc]
	orrs r0, r1
	strh r0, [r4, #0xc]
.L080856E4:
	mov r0, sp
	ldrh r0, [r0, #2]
	lsls r0, r0, #0x17
	lsrs r0, r0, #0x1a
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq .L08085700
	movs r2, #0x80
	lsls r2, r2, #7
	adds r0, r2, #0
	ldrh r1, [r4, #0xc]
	orrs r0, r1
	strh r0, [r4, #0xc]
.L08085700:
	mov r0, sp
	ldrh r0, [r0, #2]
	lsls r0, r0, #0x17
	lsrs r0, r0, #0x1a
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq .L0808571C
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r2, #0
	ldrh r1, [r4, #0xc]
	orrs r0, r1
	strh r0, [r4, #0xc]
.L0808571C:
	movs r2, #0
	adds r7, r4, #0
	adds r7, #0x30
	mov r6, sp
	adds r6, #0x1e
	adds r5, r4, #0
	adds r5, #0x26
	mov r3, sp
	adds r3, #0x16
.L0808572E:
	adds r0, r5, r2
	adds r1, r3, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #7
	ble .L0808572E
	movs r2, #0
	adds r5, r7, #0
	adds r3, r6, #0
.L08085742:
	adds r0, r5, r2
	adds r1, r3, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #9
	ble .L08085742
	adds r0, r4, #0
	bl GetUnitMaxHp
	adds r1, r0, #0
	adds r0, r4, #0
	bl SetUnitHp
	ldrb r0, [r4, #9]
	cmp r0, #0x7f
	bne .L08085768
	movs r0, #0xff
	strb r0, [r4, #9]
.L08085768:
	ldrb r0, [r4, #0xe]
	cmp r0, #0x3f
	bne .L08085772
	movs r0, #0xff
	strb r0, [r4, #0xe]
.L08085772:
	ldrb r0, [r4, #0xf]
	cmp r0, #0x3f
	bne .L0808577C
	movs r0, #0xff
	strb r0, [r4, #0xf]
.L0808577C:
	add sp, #0x28
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08085784: .4byte ReadSramFast

	thumb_func_start func_fe6_08085788
func_fe6_08085788: @ 0x08085788
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	mov r1, sp
	movs r0, #0xff
	strb r0, [r1, #6]
	mov r0, sp
	adds r1, r4, #0
	bl func_fe6_080844D4
	cmp r4, #3
	bne .L080857A8
	mov r0, sp
	movs r1, #4
	bl func_fe6_080844D4
.L080857A8:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start func_fe6_080857B0
func_fe6_080857B0: @ 0x080857B0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	mov r8, r0
	ldr r4, .L080858B8 @ =gPlaySt
	movs r0, #8
	ldrb r1, [r4, #0x14]
	ands r0, r1
	cmp r0, #0
	bne .L080858AA
	bl IsSramWorking
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080858AA
	bl func_fe6_08085F14
	add r8, r0
	mov r0, r8
	bl func_fe6_08084560
	adds r7, r0, #0
	bl GetGameTime
	str r0, [r4]
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0x20
	bl WriteAndVerifySramFast
	bl SaveActionRand
	ldr r0, .L080858BC @ =gAction
	adds r1, r7, #0
	adds r1, #0x20
	movs r2, #0x18
	bl WriteAndVerifySramFast
	ldr r5, .L080858C0 @ =gBuf
	ldr r6, .L080858C4 @ =gUnitArrayBlue
	movs r4, #0x33
.L08085806:
	adds r1, r5, #0
	adds r5, #0x34
	adds r0, r6, #0
	bl func_fe6_08085A48
	adds r6, #0x48
	subs r4, #1
	cmp r4, #0
	bge .L08085806
	movs r0, #0x38
	adds r0, r0, r7
	mov sb, r0
	ldr r6, .L080858C8 @ =gUnitArrayRed
	movs r4, #0x31
.L08085822:
	adds r1, r5, #0
	adds r5, #0x34
	adds r0, r6, #0
	bl func_fe6_08085A48
	adds r6, #0x48
	subs r4, #1
	cmp r4, #0
	bge .L08085822
	ldr r6, .L080858CC @ =gUnitArrayGreen
	movs r4, #9
.L08085838:
	adds r1, r5, #0
	adds r5, #0x34
	adds r0, r6, #0
	bl func_fe6_08085A48
	adds r6, #0x48
	subs r4, #1
	cmp r4, #0
	bge .L08085838
	movs r4, #0
	ldr r0, .L080858C0 @ =gBuf
	movs r2, #0xb6
	lsls r2, r2, #5
	mov r1, sb
	bl WriteSramFast
	movs r1, #0xed
	lsls r1, r1, #5
	adds r0, r7, r1
	bl func_fe6_08084648
	ldr r1, .L080858D0 @ =0x00001DA5
	adds r0, r7, r1
	bl func_fe6_08084628
	ldr r1, .L080858D4 @ =0x000017F8
	adds r0, r7, r1
	bl func_fe6_080846B8
	movs r1, #0xc6
	lsls r1, r1, #5
	adds r0, r7, r1
	bl func_fe6_08084884
	movs r1, #0xe9
	lsls r1, r1, #5
	adds r0, r7, r1
	bl func_fe6_080848A8
	ldr r1, .L080858D8 @ =0x000016F8
	adds r0, r7, r1
	bl func_fe6_08085EB4
	ldr r0, .L080858DC @ =0x00011217
	str r0, [sp]
	mov r1, sp
	movs r0, #1
	strb r0, [r1, #6]
	mov r0, sp
	mov r1, r8
	bl func_fe6_080844D4
	ldr r0, .L080858E0 @ =gBmSt
	adds r0, #0x3c
	strb r4, [r0]
	bl func_fe6_08085F24
.L080858AA:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080858B8: .4byte gPlaySt
.L080858BC: .4byte gAction
.L080858C0: .4byte gBuf
.L080858C4: .4byte gUnitArrayBlue
.L080858C8: .4byte gUnitArrayRed
.L080858CC: .4byte gUnitArrayGreen
.L080858D0: .4byte 0x00001DA5
.L080858D4: .4byte 0x000017F8
.L080858D8: .4byte 0x000016F8
.L080858DC: .4byte 0x00011217
.L080858E0: .4byte gBmSt

	thumb_func_start func_fe6_080858E4
func_fe6_080858E4: @ 0x080858E4
	push {r4, r5, r6, lr}
	ldr r1, .L080859B0 @ =0x0203DA14
	ldrb r1, [r1]
	adds r0, r1, r0
	bl func_fe6_0808460C
	adds r6, r0, #0
	ldr r5, .L080859B4 @ =ReadSramFast
	ldr r4, .L080859B8 @ =gPlaySt
	ldr r3, [r5]
	adds r1, r4, #0
	movs r2, #0x20
	bl _call_via_r3
	ldr r0, [r4]
	bl SetGameTime
	adds r0, r6, #0
	adds r0, #0x20
	ldr r1, .L080859BC @ =gAction
	ldr r3, [r5]
	movs r2, #0x18
	bl _call_via_r3
	bl RestoreActionRand
	bl InitUnits
	movs r4, #0
	movs r5, #0
.L08085920:
	movs r0, #0x34
	muls r0, r4, r0
	adds r0, #0x38
	adds r0, r6, r0
	ldr r1, .L080859C0 @ =gUnitArrayBlue
	adds r1, r5, r1
	bl func_fe6_08085CE0
	adds r5, #0x48
	adds r4, #1
	cmp r4, #0x33
	ble .L08085920
	movs r4, #0
	movs r5, #0
.L0808593C:
	movs r0, #0x34
	muls r0, r4, r0
	ldr r1, .L080859C4 @ =0x00000AC8
	adds r0, r0, r1
	adds r0, r6, r0
	ldr r1, .L080859C8 @ =gUnitArrayRed
	adds r1, r5, r1
	bl func_fe6_08085CE0
	adds r5, #0x48
	adds r4, #1
	cmp r4, #0x31
	ble .L0808593C
	movs r4, #0
	movs r5, #0
.L0808595A:
	movs r0, #0x34
	muls r0, r4, r0
	ldr r1, .L080859CC @ =0x000014F0
	adds r0, r0, r1
	adds r0, r6, r0
	ldr r1, .L080859D0 @ =gUnitArrayGreen
	adds r1, r5, r1
	bl func_fe6_08085CE0
	adds r5, #0x48
	adds r4, #1
	cmp r4, #9
	ble .L0808595A
	movs r1, #0xc6
	lsls r1, r1, #5
	adds r0, r6, r1
	bl func_fe6_0808483C
	movs r1, #0xe9
	lsls r1, r1, #5
	adds r0, r6, r1
	bl func_fe6_08084868
	ldr r1, .L080859D4 @ =0x000017F8
	adds r0, r6, r1
	bl func_fe6_080846D0
	movs r1, #0xed
	lsls r1, r1, #5
	adds r0, r6, r1
	bl func_fe6_08084690
	ldr r1, .L080859D8 @ =0x00001DA5
	adds r0, r6, r1
	bl func_fe6_08084668
	ldr r1, .L080859DC @ =0x000016F8
	adds r0, r6, r1
	bl func_fe6_08085ED0
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080859B0: .4byte 0x0203DA14
.L080859B4: .4byte ReadSramFast
.L080859B8: .4byte gPlaySt
.L080859BC: .4byte gAction
.L080859C0: .4byte gUnitArrayBlue
.L080859C4: .4byte 0x00000AC8
.L080859C8: .4byte gUnitArrayRed
.L080859CC: .4byte 0x000014F0
.L080859D0: .4byte gUnitArrayGreen
.L080859D4: .4byte 0x000017F8
.L080859D8: .4byte 0x00001DA5
.L080859DC: .4byte 0x000016F8

	thumb_func_start func_fe6_080859E0
func_fe6_080859E0: @ 0x080859E0
	push {r4, lr}
	adds r4, r0, #0
	bl IsSramWorking
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L08085A24
	cmp r4, #3
	bne .L08085A24
	ldr r4, .L08085A28 @ =0x0203DA14
	bl func_fe6_08085EF4
	strb r0, [r4]
	adds r1, r0, #0
	adds r1, #3
	movs r0, #0
	bl func_fe6_08084438
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08085A2C
	bl func_fe6_08085F14
	strb r0, [r4]
	adds r1, r0, #0
	adds r1, #3
	movs r0, #0
	bl func_fe6_08084438
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L08085A2C
	movs r0, #0x7f
	strb r0, [r4]
.L08085A24:
	movs r0, #0
	b .L08085A2E
	.align 2, 0
.L08085A28: .4byte 0x0203DA14
.L08085A2C:
	movs r0, #1
.L08085A2E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_08085A34
func_fe6_08085A34: @ 0x08085A34
	push {lr}
	ldr r2, .L08085A44 @ =0x0203DA14
	ldrb r2, [r2]
	adds r0, r2, r0
	bl func_fe6_08085270
	pop {r0}
	bx r0
	.align 2, 0
.L08085A44: .4byte 0x0203DA14

	thumb_func_start func_fe6_08085A48
func_fe6_08085A48: @ 0x08085A48
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r6, r0, #0
	mov ip, r1
	ldr r0, [r6]
	cmp r0, #0
	bne .L08085A62
	strb r0, [r1]
	b .L08085CAE
.L08085A62:
	ldrb r0, [r0, #4]
	mov r1, ip
	strb r0, [r1]
	ldr r0, [r6, #4]
	ldrb r0, [r0, #4]
	strb r0, [r1, #1]
	movs r1, #8
	ldrsb r1, [r6, r1]
	mov r2, ip
	adds r2, #0x28
	movs r4, #0x1f
	ands r1, r4
	movs r3, #0x20
	rsbs r3, r3, #0
	adds r0, r3, #0
	ldrb r5, [r2]
	ands r0, r5
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r6, #9]
	mov r7, ip
	strb r0, [r7, #0xe]
	ldrh r0, [r6, #0xc]
	strh r0, [r7, #4]
	movs r1, #0xe
	ldrsb r1, [r6, r1]
	movs r0, #0x3f
	ands r1, r0
	lsls r1, r1, #5
	ldr r0, .L08085CC0 @ =0xFFFFF81F
	ldrh r2, [r7, #0x28]
	ands r0, r2
	orrs r0, r1
	strh r0, [r7, #0x28]
	movs r1, #0x3f
	ldrb r5, [r6, #0xf]
	ands r1, r5
	lsls r1, r1, #0xb
	ldr r0, [r7, #0x28]
	ldr r2, .L08085CC4 @ =0xFFFE07FF
	ands r0, r2
	orrs r0, r1
	str r0, [r7, #0x28]
	ldrb r0, [r6, #0x10]
	strb r0, [r7, #0xc]
	ldrb r0, [r6, #0x11]
	strb r0, [r7, #0xd]
	movs r1, #0x12
	ldrsb r1, [r6, r1]
	mov r2, ip
	adds r2, #0x2a
	ands r1, r4
	lsls r1, r1, #1
	movs r0, #0x3f
	rsbs r0, r0, #0
	ldrb r7, [r2]
	ands r0, r7
	orrs r0, r1
	strb r0, [r2]
	movs r1, #0x13
	ldrsb r1, [r6, r1]
	movs r2, #0x1f
	ands r1, r2
	lsls r1, r1, #6
	ldr r0, .L08085CC8 @ =0xFFFFF83F
	mov r5, ip
	ldrh r5, [r5, #0x2a]
	ands r0, r5
	orrs r0, r1
	mov r7, ip
	strh r0, [r7, #0x2a]
	movs r1, #0x14
	ldrsb r1, [r6, r1]
	movs r0, #0x2b
	add r0, ip
	mov r8, r0
	lsls r1, r1, #3
	movs r5, #7
	mov sb, r5
	movs r0, #7
	mov r7, r8
	ldrb r7, [r7]
	ands r0, r7
	orrs r0, r1
	mov r1, r8
	strb r0, [r1]
	movs r0, #0x15
	ldrsb r0, [r6, r0]
	mov r1, ip
	adds r1, #0x2c
	ands r0, r4
	ldrb r5, [r1]
	ands r3, r5
	orrs r3, r0
	strb r3, [r1]
	movs r1, #0x16
	ldrsb r1, [r6, r1]
	ands r1, r2
	lsls r1, r1, #5
	ldr r0, .L08085CCC @ =0xFFFFFC1F
	mov r7, ip
	ldrh r7, [r7, #0x2c]
	ands r0, r7
	orrs r0, r1
	mov r1, ip
	strh r0, [r1, #0x2c]
	movs r1, #0x17
	ldrsb r1, [r6, r1]
	mov r2, ip
	adds r2, #0x2d
	ands r1, r4
	lsls r1, r1, #2
	movs r0, #0x7d
	rsbs r0, r0, #0
	ldrb r3, [r2]
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	movs r2, #0x18
	ldrsb r2, [r6, r2]
	movs r3, #0x1f
	ands r2, r3
	lsls r2, r2, #0xf
	mov r4, ip
	ldr r0, [r4, #0x2c]
	ldr r1, .L08085CD0 @ =0xFFF07FFF
	ands r0, r1
	orrs r0, r2
	str r0, [r4, #0x2c]
	adds r0, r6, #0
	adds r0, #0x2e
	ldrb r2, [r0]
	lsls r1, r2, #0x1c
	lsrs r1, r1, #0x1c
	adds r4, #0x2e
	mov r5, sb
	ands r1, r5
	lsls r1, r1, #4
	movs r0, #0x71
	rsbs r0, r0, #0
	ldrb r7, [r4]
	ands r0, r7
	orrs r0, r1
	strb r0, [r4]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x1c
	movs r0, #7
	ands r2, r0
	lsls r2, r2, #7
	ldr r0, .L08085CD4 @ =0xFFFFFC7F
	mov r1, ip
	ldrh r1, [r1, #0x2e]
	ands r0, r1
	orrs r0, r2
	mov r2, ip
	strh r0, [r2, #0x2e]
	adds r0, r6, #0
	adds r0, #0x2f
	ldrb r2, [r0]
	lsls r1, r2, #0x1c
	lsrs r1, r1, #0x1c
	adds r4, #1
	ands r1, r5
	lsls r1, r1, #2
	movs r0, #0x1d
	rsbs r0, r0, #0
	ldrb r5, [r4]
	ands r0, r5
	orrs r0, r1
	lsrs r2, r2, #4
	lsls r2, r2, #5
	ands r0, r3
	orrs r0, r2
	strb r0, [r4]
	ldrb r0, [r6, #0x19]
	mov r7, ip
	strb r0, [r7, #3]
	movs r1, #0x1a
	ldrsb r1, [r6, r1]
	mov r2, ip
	adds r2, #0x30
	movs r0, #0xf
	ands r1, r0
	movs r0, #0x10
	rsbs r0, r0, #0
	ldrb r3, [r2]
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	ldrh r0, [r6, #0x1c]
	strh r0, [r7, #6]
	ldrh r0, [r6, #0x1e]
	strh r0, [r7, #8]
	ldrh r0, [r6, #0x20]
	strh r0, [r7, #0xa]
	ldr r1, .L08085CD8 @ =0x00003FFF
	ldrh r4, [r6, #0x22]
	ands r1, r4
	lsls r1, r1, #4
	ldr r0, [r7, #0x30]
	ldr r2, .L08085CDC @ =0xFFFC000F
	ands r0, r2
	orrs r0, r1
	str r0, [r7, #0x30]
	ldrh r5, [r6, #0x24]
	lsls r1, r5, #2
	movs r0, #3
	ldrh r7, [r7, #0x32]
	ands r0, r7
	orrs r0, r1
	mov r1, ip
	strh r0, [r1, #0x32]
	movs r2, #0
	mov r5, ip
	adds r5, #0x18
	adds r7, r6, #0
	adds r7, #0x30
	movs r3, #0x42
	adds r3, r3, r6
	mov r8, r3
	adds r4, r6, #0
	adds r4, #0x43
	str r4, [sp, #0xc]
	movs r0, #0x22
	add r0, ip
	mov sb, r0
	adds r1, r6, #0
	adds r1, #0x44
	str r1, [sp, #0x10]
	movs r3, #0x23
	add r3, ip
	mov sl, r3
	adds r4, #2
	str r4, [sp, #0x14]
	mov r0, ip
	adds r0, #0x26
	str r0, [sp]
	subs r1, #4
	str r1, [sp, #8]
	adds r3, r6, #0
	adds r3, #0x46
	str r3, [sp, #0x18]
	mov r4, ip
	adds r4, #0x27
	str r4, [sp, #4]
	ldrb r1, [r6, #0xa]
	mov r0, sp
	strb r1, [r0, #0x1c]
	subs r4, #0x17
	subs r3, #0x20
.L08085C56:
	adds r0, r4, r2
	adds r1, r3, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #7
	ble .L08085C56
	movs r2, #0
	adds r4, r5, #0
	adds r3, r7, #0
.L08085C6A:
	adds r0, r4, r2
	adds r1, r3, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #9
	ble .L08085C6A
	mov r2, r8
	ldrb r0, [r2]
	mov r3, ip
	strb r0, [r3, #2]
	ldr r4, [sp, #0xc]
	ldrb r0, [r4]
	mov r5, sb
	strb r0, [r5]
	ldr r7, [sp, #0x10]
	ldrb r0, [r7]
	mov r1, sl
	strb r0, [r1]
	ldr r2, [sp, #0x14]
	ldrb r0, [r2]
	ldr r3, [sp]
	strb r0, [r3]
	ldr r4, [sp, #8]
	ldrh r0, [r4]
	mov r5, ip
	strh r0, [r5, #0x24]
	ldr r7, [sp, #0x18]
	ldrb r0, [r7]
	ldr r1, [sp, #4]
	strb r0, [r1]
	mov r2, sp
	ldrb r2, [r2, #0x1c]
	strb r2, [r5, #0xf]
.L08085CAE:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08085CC0: .4byte 0xFFFFF81F
.L08085CC4: .4byte 0xFFFE07FF
.L08085CC8: .4byte 0xFFFFF83F
.L08085CCC: .4byte 0xFFFFFC1F
.L08085CD0: .4byte 0xFFF07FFF
.L08085CD4: .4byte 0xFFFFFC7F
.L08085CD8: .4byte 0x00003FFF
.L08085CDC: .4byte 0xFFFC000F

	thumb_func_start func_fe6_08085CE0
func_fe6_08085CE0: @ 0x08085CE0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x48
	adds r4, r1, #0
	ldr r1, .L08085EB0 @ =ReadSramFast
	ldr r3, [r1]
	mov r1, sp
	movs r2, #0x34
	bl _call_via_r3
	mov r0, sp
	ldrb r0, [r0]
	bl GetPInfo
	str r0, [r4]
	mov r0, sp
	ldrb r0, [r0, #1]
	bl GetJInfo
	str r0, [r4, #4]
	add r0, sp, #0x28
	ldrb r0, [r0]
	lsls r0, r0, #0x1b
	lsrs r0, r0, #0x1b
	strb r0, [r4, #8]
	mov r0, sp
	ldrb r0, [r0, #0xe]
	strb r0, [r4, #9]
	mov r0, sp
	ldrh r0, [r0, #4]
	strh r0, [r4, #0xc]
	mov r0, sp
	ldrh r0, [r0, #0x28]
	lsls r0, r0, #0x15
	lsrs r0, r0, #0x1a
	strb r0, [r4, #0xe]
	ldr r0, [sp, #0x28]
	lsls r0, r0, #0xf
	lsrs r0, r0, #0x1a
	strb r0, [r4, #0xf]
	mov r0, sp
	ldrb r0, [r0, #0xc]
	strb r0, [r4, #0x10]
	mov r0, sp
	ldrb r0, [r0, #0xd]
	strb r0, [r4, #0x11]
	mov r0, sp
	adds r0, #0x2a
	ldrb r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1b
	strb r0, [r4, #0x12]
	mov r0, sp
	ldrh r0, [r0, #0x2a]
	lsls r0, r0, #0x15
	lsrs r0, r0, #0x1b
	strb r0, [r4, #0x13]
	mov r0, sp
	adds r0, #0x2b
	ldrb r0, [r0]
	lsrs r0, r0, #3
	strb r0, [r4, #0x14]
	add r0, sp, #0x2c
	ldrb r0, [r0]
	lsls r0, r0, #0x1b
	lsrs r0, r0, #0x1b
	strb r0, [r4, #0x15]
	mov r0, sp
	ldrh r0, [r0, #0x2c]
	lsls r0, r0, #0x16
	lsrs r0, r0, #0x1b
	strb r0, [r4, #0x16]
	mov r0, sp
	adds r0, #0x2d
	ldrb r0, [r0]
	lsls r0, r0, #0x19
	lsrs r0, r0, #0x1b
	strb r0, [r4, #0x17]
	ldr r0, [sp, #0x2c]
	lsls r0, r0, #0xc
	lsrs r0, r0, #0x1b
	strb r0, [r4, #0x18]
	mov r0, sp
	adds r0, #0x2e
	ldrb r0, [r0]
	lsls r1, r0, #0x19
	adds r2, r4, #0
	adds r2, #0x2e
	mov r0, sp
	ldrh r0, [r0, #0x2e]
	lsls r0, r0, #0x16
	lsrs r0, r0, #0x1d
	lsls r0, r0, #4
	lsrs r1, r1, #0x1d
	orrs r1, r0
	strb r1, [r2]
	mov r0, sp
	adds r0, #0x2f
	ldrb r0, [r0]
	lsls r1, r0, #0x1b
	adds r2, #1
	lsrs r0, r0, #5
	lsls r0, r0, #4
	lsrs r1, r1, #0x1d
	orrs r1, r0
	strb r1, [r2]
	mov r0, sp
	ldrb r0, [r0, #3]
	strb r0, [r4, #0x19]
	add r0, sp, #0x30
	ldrb r0, [r0]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	strb r0, [r4, #0x1a]
	mov r0, sp
	ldrh r0, [r0, #6]
	strh r0, [r4, #0x1c]
	mov r0, sp
	ldrh r0, [r0, #8]
	strh r0, [r4, #0x1e]
	mov r0, sp
	ldrh r0, [r0, #0xa]
	strh r0, [r4, #0x20]
	ldr r0, [sp, #0x30]
	lsls r0, r0, #0xe
	lsrs r0, r0, #0x12
	strh r0, [r4, #0x22]
	mov r0, sp
	ldrh r1, [r0, #0x32]
	lsrs r0, r1, #2
	strh r0, [r4, #0x24]
	movs r2, #0
	add r0, sp, #0x18
	mov sl, r0
	mov r1, sp
	adds r1, #0x22
	str r1, [sp, #0x34]
	mov r0, sp
	adds r0, #0x23
	str r0, [sp, #0x38]
	adds r1, #4
	str r1, [sp, #0x3c]
	adds r0, #4
	str r0, [sp, #0x40]
	adds r5, r4, #0
	adds r5, #0x26
	add r3, sp, #0x10
.L08085E0C:
	adds r0, r5, r2
	adds r1, r3, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #7
	ble .L08085E0C
	movs r2, #0
	movs r1, #0x42
	adds r1, r1, r4
	mov ip, r1
	adds r6, r4, #0
	adds r6, #0x43
	adds r7, r4, #0
	adds r7, #0x44
	movs r0, #0x45
	adds r0, r0, r4
	mov r8, r0
	movs r1, #0x40
	adds r1, r1, r4
	mov sb, r1
	adds r0, r4, #0
	adds r0, #0x46
	str r0, [sp, #0x44]
	adds r5, r4, #0
	adds r5, #0x30
	mov r3, sl
.L08085E42:
	adds r0, r5, r2
	adds r1, r3, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #9
	ble .L08085E42
	mov r0, sp
	ldrb r0, [r0, #2]
	mov r1, ip
	strb r0, [r1]
	ldr r1, [sp, #0x34]
	ldrb r0, [r1]
	strb r0, [r6]
	ldr r1, [sp, #0x38]
	ldrb r0, [r1]
	strb r0, [r7]
	ldr r1, [sp, #0x3c]
	ldrb r0, [r1]
	mov r1, r8
	strb r0, [r1]
	mov r0, sp
	ldrh r0, [r0, #0x24]
	mov r1, sb
	strh r0, [r1]
	ldr r1, [sp, #0x40]
	ldrb r0, [r1]
	ldr r1, [sp, #0x44]
	strb r0, [r1]
	mov r0, sp
	ldrb r0, [r0, #0xf]
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #9]
	cmp r0, #0x7f
	bne .L08085E8C
	movs r0, #0xff
	strb r0, [r4, #9]
.L08085E8C:
	ldrb r0, [r4, #0xe]
	cmp r0, #0x3f
	bne .L08085E96
	movs r0, #0xff
	strb r0, [r4, #0xe]
.L08085E96:
	ldrb r0, [r4, #0xf]
	cmp r0, #0x3f
	bne .L08085EA0
	movs r0, #0xff
	strb r0, [r4, #0xf]
.L08085EA0:
	add sp, #0x48
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L08085EB0: .4byte ReadSramFast

	thumb_func_start func_fe6_08085EB4
func_fe6_08085EB4: @ 0x08085EB4
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	bl GetTrap
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r4, #0
	bl WriteAndVerifySramFast
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08085ED0
func_fe6_08085ED0: @ 0x08085ED0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, .L08085EF0 @ =ReadSramFast
	movs r0, #0
	bl GetTrap
	adds r1, r0, #0
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r3, [r4]
	adds r0, r5, #0
	bl _call_via_r3
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L08085EF0: .4byte ReadSramFast

	thumb_func_start func_fe6_08085EF4
func_fe6_08085EF4: @ 0x08085EF4
	push {lr}
	sub sp, #0x20
	mov r0, sp
	bl LoadGlobalSaveInfo
	mov r0, sp
	ldrb r0, [r0, #0x1f]
	cmp r0, #1
	beq .L08085F0A
	movs r0, #0
	b .L08085F0C
.L08085F0A:
	movs r0, #1
.L08085F0C:
	add sp, #0x20
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08085F14
func_fe6_08085F14: @ 0x08085F14
	push {lr}
	bl func_fe6_08085EF4
	adds r1, r0, #0
	movs r0, #1
	subs r0, r0, r1
	pop {r1}
	bx r1

	thumb_func_start func_fe6_08085F24
func_fe6_08085F24: @ 0x08085F24
	push {lr}
	sub sp, #0x20
	mov r0, sp
	bl LoadGlobalSaveInfo
	mov r1, sp
	movs r2, #0
	mov r0, sp
	ldrb r0, [r0, #0x1f]
	cmp r0, #0
	bne .L08085F3C
	movs r2, #1
.L08085F3C:
	strb r2, [r1, #0x1f]
	mov r0, sp
	bl SaveGlobalSaveInfoNoChecksum
	add sp, #0x20
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08085F4C
func_fe6_08085F4C: @ 0x08085F4C
	push {r4, r5, lr}
	adds r5, r1, #0
	ldr r1, .L08085F6C @ =ReadSramFast
	ldr r4, .L08085F70 @ =gBuf
	ldr r3, [r1]
	adds r1, r4, #0
	adds r2, r5, #0
	bl _call_via_r3
	adds r0, r4, #0
	adds r1, r5, #0
	bl Checksum32_t
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
.L08085F6C: .4byte ReadSramFast
.L08085F70: .4byte gBuf

	thumb_func_start func_fe6_08085F74
func_fe6_08085F74: @ 0x08085F74
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r5, [r4, #0xa]
	ldrh r0, [r4, #8]
	bl func_fe6_08084414
	adds r1, r5, #0
	bl func_fe6_08085F4C
	ldr r1, [r4, #0xc]
	cmp r1, r0
	bne .L08085F90
	movs r0, #1
	b .L08085F92
.L08085F90:
	movs r0, #0
.L08085F92:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_08085F98
func_fe6_08085F98: @ 0x08085F98
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r5, [r4, #0xa]
	ldrh r0, [r4, #8]
	bl func_fe6_08084414
	adds r1, r5, #0
	bl func_fe6_08085F4C
	str r0, [r4, #0xc]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start func_fe6_08085FB4
func_fe6_08085FB4: @ 0x08085FB4
	push {r4, r5, r6, lr}
	movs r6, #0
	ldr r4, .L0808607C @ =gUnitArrayBlue
	movs r5, #0x33
.L08085FBC:
	ldr r0, [r4]
	cmp r0, #0
	beq .L08085FD4
	movs r0, #0
	str r0, [r4, #0x3c]
	adds r0, r4, #0
	movs r1, #0x24
	bl func_fe6_08085F4C
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L08085FD4:
	adds r4, #0x48
	subs r5, #1
	cmp r5, #0
	bge .L08085FBC
	ldr r4, .L08086080 @ =gUnitArrayRed
	movs r5, #0x31
.L08085FE0:
	ldr r0, [r4]
	cmp r0, #0
	beq .L08085FF8
	movs r0, #0
	str r0, [r4, #0x3c]
	adds r0, r4, #0
	movs r1, #0x24
	bl func_fe6_08085F4C
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L08085FF8:
	adds r4, #0x48
	subs r5, #1
	cmp r5, #0
	bge .L08085FE0
	ldr r4, .L08086084 @ =gUnitArrayGreen
	movs r5, #9
.L08086004:
	ldr r0, [r4]
	cmp r0, #0
	beq .L0808601C
	movs r0, #0
	str r0, [r4, #0x3c]
	adds r0, r4, #0
	movs r1, #0x24
	bl func_fe6_08085F4C
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
.L0808601C:
	adds r4, #0x48
	subs r5, #1
	cmp r5, #0
	bge .L08086004
	bl GetPermanentFlagBits
	adds r4, r0, #0
	bl GetPermanentFlagBitsSize
	adds r1, r0, #0
	lsrs r0, r1, #0x1f
	adds r1, r1, r0
	asrs r1, r1, #1
	adds r0, r4, #0
	bl func_fe6_08085F4C
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	bl GetChapterFlagBits
	adds r4, r0, #0
	bl GetChapterFlagBitsSize
	adds r1, r0, #0
	lsrs r0, r1, #0x1f
	adds r1, r1, r0
	asrs r1, r1, #1
	adds r0, r4, #0
	bl func_fe6_08085F4C
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0
	bl GetTrap
	movs r1, #0x80
	bl func_fe6_08085F4C
	adds r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
.L0808607C: .4byte gUnitArrayBlue
.L08086080: .4byte gUnitArrayRed
.L08086084: .4byte gUnitArrayGreen

	thumb_func_start func_fe6_08086088
func_fe6_08086088: @ 0x08086088
	sub sp, #8
	add sp, #8
	bx lr
	.align 2, 0

	thumb_func_start func_fe6_08086090
func_fe6_08086090: @ 0x08086090
	push {lr}
	adds r1, r0, #0
	movs r0, #0
	bl func_fe6_08084438
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_080860A4
func_fe6_080860A4: @ 0x080860A4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x6c
	movs r0, #5
	bl func_fe6_08084560
	mov r8, r0
	add r0, sp, #0x5c
	movs r4, #0
	strh r4, [r0]
	add r5, sp, #0x10
	ldr r2, .L080861D8 @ =0x01000014
	adds r1, r5, #0
	bl CpuSet
	mov r0, sp
	adds r0, #0x5e
	strh r4, [r0]
	add r4, sp, #0x38
	ldr r2, .L080861DC @ =0x01000007
	adds r1, r4, #0
	bl CpuSet
	movs r7, #0
	mov sb, r5
	add r0, sp, #0x60
	mov sl, r0
	mov r1, sp
	adds r1, #0x48
	str r1, [sp, #0x64]
	mov r3, sp
	adds r3, #0x4c
	str r3, [sp, #0x68]
	mov r6, r8
.L080860EE:
	movs r0, #0xd8
	muls r0, r7, r0
	adds r0, #0x10
	mov r1, r8
	adds r4, r1, r0
	movs r5, #4
.L080860FA:
	mov r0, sb
	adds r1, r4, #0
	movs r2, #0x28
	bl WriteAndVerifySramFast
	adds r4, #0x28
	subs r5, #1
	cmp r5, #0
	bge .L080860FA
	add r0, sp, #0x38
	adds r1, r6, #0
	movs r2, #0xf
	bl WriteAndVerifySramFast
	adds r6, #0xd8
	adds r7, #1
	cmp r7, #9
	ble .L080860EE
	movs r0, #7
	mov r3, sl
	strh r0, [r3]
	movs r1, #0x87
	lsls r1, r1, #4
	add r1, r8
	mov r0, sl
	movs r2, #2
	bl WriteAndVerifySramFast
	ldr r6, [sp, #0x64]
	mov sl, r6
	ldr r0, .L080861E0 @ =gUnk_0832731C
	movs r1, #3
	mov sb, r1
	ldr r5, .L080861E4 @ =0x00000874
	add r5, r8
	adds r3, r0, #4
	mov r8, r3
	adds r4, r0, #0
	movs r7, #9
.L08086148:
	ldrb r3, [r4]
	lsls r0, r3, #0x1e
	lsrs r0, r0, #0x1e
	mov r6, sb
	ands r0, r6
	movs r1, #4
	rsbs r1, r1, #0
	adds r2, r1, #0
	mov r6, sl
	ldrb r6, [r6]
	ands r2, r6
	orrs r2, r0
	lsls r0, r3, #0x1c
	lsrs r0, r0, #0x1e
	mov r1, sb
	ands r0, r1
	lsls r0, r0, #2
	movs r6, #0xd
	rsbs r6, r6, #0
	adds r1, r6, #0
	ands r2, r1
	orrs r2, r0
	movs r1, #0x10
	ands r1, r3
	movs r3, #0x11
	rsbs r3, r3, #0
	adds r0, r3, #0
	ands r2, r0
	orrs r2, r1
	mov r6, sl
	strb r2, [r6]
	ldr r2, [r4]
	lsrs r2, r2, #5
	lsls r2, r2, #5
	ldr r0, [sp, #0x48]
	movs r1, #0x1f
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x48]
	mov r0, r8
	ldr r1, [sp, #0x68]
	bl func_fe6_080368DC
	mov r0, sl
	adds r1, r5, #0
	movs r2, #0x14
	bl WriteAndVerifySramFast
	adds r5, #0x14
	movs r0, #0x14
	add r8, r0
	adds r4, #0x14
	subs r7, #1
	cmp r7, #0
	bge .L08086148
	ldr r0, .L080861E8 @ =0x00020112
	str r0, [sp]
	mov r1, sp
	movs r0, #2
	strb r0, [r1, #6]
	mov r0, sp
	movs r1, #5
	bl func_fe6_080844D4
	add sp, #0x6c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080861D8: .4byte 0x01000014
.L080861DC: .4byte 0x01000007
.L080861E0: .4byte gUnk_0832731C
.L080861E4: .4byte 0x00000874
.L080861E8: .4byte 0x00020112

	thumb_func_start func_fe6_080861EC
func_fe6_080861EC: @ 0x080861EC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #5
	bl func_fe6_0808460C
	ldr r2, .L08086214 @ =ReadSramFast
	movs r1, #0xd8
	muls r1, r4, r1
	adds r0, r0, r1
	ldr r3, [r2]
	adds r1, r5, #0
	movs r2, #0xd8
	bl _call_via_r3
	ldrb r0, [r5]
	cmp r0, #0
	beq .L08086218
	movs r0, #1
	b .L0808621A
	.align 2, 0
.L08086214: .4byte ReadSramFast
.L08086218:
	movs r0, #0
.L0808621A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_08086220
func_fe6_08086220: @ 0x08086220
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #5
	bl func_fe6_0808460C
	ldr r2, .L08086254 @ =ReadSramFast
	movs r1, #0xd8
	muls r1, r4, r1
	adds r0, r0, r1
	ldr r4, .L08086258 @ =0x0203DA18
	ldr r3, [r2]
	adds r1, r4, #0
	movs r2, #0xd8
	bl _call_via_r3
	ldrb r0, [r4]
	cmp r0, #0
	beq .L0808625C
	adds r0, r4, #0
	adds r1, r5, #0
	bl func_fe6_080368DC
	movs r0, #1
	b .L0808625E
	.align 2, 0
.L08086254: .4byte ReadSramFast
.L08086258: .4byte 0x0203DA18
.L0808625C:
	movs r0, #0
.L0808625E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_08086264
func_fe6_08086264: @ 0x08086264
	push {r4, r5, r6, lr}
	sub sp, #0x14
	adds r6, r0, #0
	movs r0, #5
	bl func_fe6_08084560
	adds r4, r0, #0
	add r0, sp, #0x10
	movs r1, #0
	strh r1, [r0]
	ldr r5, .L080862AC @ =0x0203DA18
	ldr r2, .L080862B0 @ =0x0100006C
	adds r1, r5, #0
	bl CpuSet
	movs r0, #0xd8
	muls r0, r6, r0
	adds r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0xd8
	bl WriteAndVerifySramFast
	ldr r0, .L080862B4 @ =0x00020112
	str r0, [sp]
	mov r1, sp
	movs r0, #2
	strb r0, [r1, #6]
	mov r0, sp
	movs r1, #5
	bl func_fe6_080844D4
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L080862AC: .4byte 0x0203DA18
.L080862B0: .4byte 0x0100006C
.L080862B4: .4byte 0x00020112

	thumb_func_start func_fe6_080862B8
func_fe6_080862B8: @ 0x080862B8
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x10
	adds r6, r0, #0
	mov sb, r1
	movs r0, #5
	bl func_fe6_0808460C
	adds r4, r0, #0
	movs r0, #5
	bl func_fe6_08084560
	adds r5, r0, #0
	ldr r1, .L08086324 @ =ReadSramFast
	movs r0, #0xd8
	mov r8, r0
	mov r0, r8
	muls r0, r6, r0
	adds r4, r4, r0
	ldr r6, .L08086328 @ =0x0203DA18
	ldr r3, [r1]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0xd8
	bl _call_via_r3
	mov r1, r8
	mov r0, sb
	muls r0, r1, r0
	adds r5, r5, r0
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0xd8
	bl WriteAndVerifySramFast
	ldr r0, .L0808632C @ =0x00020112
	str r0, [sp]
	mov r1, sp
	movs r0, #2
	strb r0, [r1, #6]
	mov r0, sp
	movs r1, #5
	bl func_fe6_080844D4
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08086324: .4byte ReadSramFast
.L08086328: .4byte 0x0203DA18
.L0808632C: .4byte 0x00020112

	thumb_func_start func_fe6_08086330
func_fe6_08086330: @ 0x08086330
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov r8, r0
	mov sl, r1
	movs r0, #5
	bl func_fe6_0808460C
	adds r5, r0, #0
	movs r0, #5
	bl func_fe6_08084560
	adds r6, r0, #0
	ldr r0, .L080863BC @ =ReadSramFast
	mov sb, r0
	movs r4, #0xd8
	mov r7, r8
	muls r7, r4, r7
	adds r0, r5, r7
	mov r1, sb
	ldr r3, [r1]
	ldr r1, .L080863C0 @ =0x0203DA18
	movs r2, #0xd8
	bl _call_via_r3
	mov r0, sl
	muls r0, r4, r0
	adds r4, r0, #0
	adds r5, r5, r4
	ldr r1, .L080863C4 @ =0x0203DAF0
	mov r8, r1
	mov r0, sb
	ldr r3, [r0]
	adds r0, r5, #0
	movs r2, #0xd8
	bl _call_via_r3
	adds r4, r6, r4
	ldr r0, .L080863C0 @ =0x0203DA18
	adds r1, r4, #0
	movs r2, #0xd8
	bl WriteAndVerifySramFast
	adds r6, r6, r7
	mov r0, r8
	adds r1, r6, #0
	movs r2, #0xd8
	bl WriteAndVerifySramFast
	ldr r0, .L080863C8 @ =0x00020112
	str r0, [sp]
	mov r1, sp
	movs r0, #2
	strb r0, [r1, #6]
	mov r0, sp
	movs r1, #5
	bl func_fe6_080844D4
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080863BC: .4byte ReadSramFast
.L080863C0: .4byte 0x0203DA18
.L080863C4: .4byte 0x0203DAF0
.L080863C8: .4byte 0x00020112

	thumb_func_start func_fe6_080863CC
func_fe6_080863CC: @ 0x080863CC
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x10
	adds r4, r0, #0
	mov r8, r1
	adds r6, r2, #0
	movs r0, #5
	bl func_fe6_08084560
	adds r5, r0, #0
	movs r0, #0xd8
	muls r4, r0, r4
	adds r1, r5, r4
	adds r0, r6, #0
	movs r2, #0xf
	bl WriteAndVerifySramFast
	adds r4, #0x10
	adds r5, r5, r4
	mov r4, r8
	movs r6, #4
.L080863F8:
	adds r0, r4, #0
	adds r1, r5, #0
	bl func_fe6_080852C4
	adds r5, #0x28
	adds r4, #0x48
	subs r6, #1
	cmp r6, #0
	bge .L080863F8
	ldr r0, .L08086428 @ =0x00020112
	str r0, [sp]
	mov r1, sp
	movs r0, #2
	strb r0, [r1, #6]
	mov r0, sp
	movs r1, #5
	bl func_fe6_080844D4
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08086428: .4byte 0x00020112

	thumb_func_start func_fe6_0808642C
func_fe6_0808642C: @ 0x0808642C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r6, r1, #0
	adds r5, r2, #0
	movs r0, #5
	bl func_fe6_0808460C
	adds r7, r0, #0
	ldr r1, .L08086480 @ =ReadSramFast
	movs r0, #0xd8
	mov r4, r8
	muls r4, r0, r4
	adds r0, r7, r4
	ldr r3, [r1]
	adds r1, r5, #0
	movs r2, #0xf
	bl _call_via_r3
	adds r4, #0x10
	adds r4, r7, r4
	movs r5, #4
.L0808645A:
	adds r0, r4, #0
	adds r1, r6, #0
	bl func_fe6_080855C4
	adds r6, #0x48
	adds r4, #0x28
	subs r5, #1
	cmp r5, #0
	bge .L0808645A
	movs r0, #0xd8
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, r7, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq .L08086484
	movs r0, #1
	b .L08086486
	.align 2, 0
.L08086480: .4byte ReadSramFast
.L08086484:
	movs r0, #0
.L08086486:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_08086490
func_fe6_08086490: @ 0x08086490
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	movs r0, #5
	bl func_fe6_08084560
	adds r1, r0, #0
	ldr r0, .L080864C4 @ =0x00000874
	adds r1, r1, r0
	adds r0, r4, #0
	movs r2, #0xc8
	bl WriteAndVerifySramFast
	ldr r0, .L080864C8 @ =0x00020112
	str r0, [sp]
	mov r1, sp
	movs r0, #2
	strb r0, [r1, #6]
	mov r0, sp
	movs r1, #5
	bl func_fe6_080844D4
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080864C4: .4byte 0x00000874
.L080864C8: .4byte 0x00020112

	thumb_func_start func_fe6_080864CC
func_fe6_080864CC: @ 0x080864CC
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #5
	bl func_fe6_0808460C
	ldr r1, .L080864EC @ =ReadSramFast
	ldr r2, .L080864F0 @ =0x00000874
	adds r0, r0, r2
	ldr r3, [r1]
	adds r1, r4, #0
	movs r2, #0xc8
	bl _call_via_r3
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L080864EC: .4byte ReadSramFast
.L080864F0: .4byte 0x00000874

	thumb_func_start func_fe6_080864F4
func_fe6_080864F4: @ 0x080864F4
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	movs r0, #5
	bl func_fe6_08084560
	adds r1, r0, #0
	movs r0, #0x87
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r4, #0
	movs r2, #2
	bl WriteAndVerifySramFast
	ldr r0, .L0808652C @ =0x00020112
	str r0, [sp]
	mov r1, sp
	movs r0, #2
	strb r0, [r1, #6]
	mov r0, sp
	movs r1, #5
	bl func_fe6_080844D4
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0808652C: .4byte 0x00020112

	thumb_func_start func_fe6_08086530
func_fe6_08086530: @ 0x08086530
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #5
	bl func_fe6_0808460C
	ldr r1, .L08086554 @ =ReadSramFast
	movs r2, #0x87
	lsls r2, r2, #4
	adds r0, r0, r2
	ldr r3, [r1]
	adds r1, r4, #0
	movs r2, #2
	bl _call_via_r3
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08086554: .4byte ReadSramFast

	thumb_func_start func_fe6_08086558
func_fe6_08086558: @ 0x08086558
	push {r4, lr}
	sub sp, #0x10
	movs r0, #5
	bl func_fe6_08086090
	lsls r0, r0, #0x18
	cmp r0, #0
	bne .L0808656E
	b .L08086586
.L0808656A:
	movs r0, #1
	b .L08086588
.L0808656E:
	movs r4, #0
.L08086570:
	adds r0, r4, #0
	mov r1, sp
	bl func_fe6_08086220
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq .L0808656A
	adds r4, #1
	cmp r4, #9
	ble .L08086570
.L08086586:
	movs r0, #0
.L08086588:
	add sp, #0x10
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_08086590
func_fe6_08086590: @ 0x08086590
	push {r4, r5, lr}
	ldr r1, .L080865D0 @ =ReadSramFast
	ldr r5, .L080865D4 @ =gUnk_08689DDC
	ldr r0, [r5]
	ldr r4, .L080865D8 @ =0x0203DBC8
	ldr r3, [r1]
	adds r1, r4, #0
	movs r2, #0x1c
	bl _call_via_r3
	ldr r1, [r4]
	ldr r0, .L080865DC @ =0x50414D58
	cmp r1, r0
	bne .L080865E4
	bl GetLang
	lsls r0, r0, #0x18
	ldr r1, .L080865E0 @ =0x00020223
	adds r0, r0, r1
	ldr r1, [r4, #8]
	cmp r1, r0
	bne .L080865E4
	ldr r0, [r4, #0x10]
	ldr r1, [r5]
	adds r0, r0, r1
	str r0, [r4, #0x10]
	ldr r0, [r4, #0x18]
	adds r0, r0, r1
	str r0, [r4, #0x18]
	movs r0, #1
	b .L080865E6
	.align 2, 0
.L080865D0: .4byte ReadSramFast
.L080865D4: .4byte gUnk_08689DDC
.L080865D8: .4byte 0x0203DBC8
.L080865DC: .4byte 0x50414D58
.L080865E0: .4byte 0x00020223
.L080865E4:
	movs r0, #0
.L080865E6:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_080865EC
func_fe6_080865EC: @ 0x080865EC
	ldr r2, .L080865FC @ =0x0203DBC8
	ldr r1, [r2]
	ldr r0, .L08086600 @ =0x50414D58
	cmp r1, r0
	bne .L08086604
	ldr r0, [r2, #0x10]
	b .L08086606
	.align 2, 0
.L080865FC: .4byte 0x0203DBC8
.L08086600: .4byte 0x50414D58
.L08086604:
	movs r0, #0
.L08086606:
	bx lr

	thumb_func_start func_fe6_08086608
func_fe6_08086608: @ 0x08086608
	ldr r2, .L08086618 @ =0x0203DBC8
	ldr r1, [r2]
	ldr r0, .L0808661C @ =0x50414D58
	cmp r1, r0
	bne .L08086620
	movs r1, #0x14
	ldrsh r0, [r2, r1]
	b .L08086622
	.align 2, 0
.L08086618: .4byte 0x0203DBC8
.L0808661C: .4byte 0x50414D58
.L08086620:
	movs r0, #0
.L08086622:
	bx lr

	thumb_func_start func_fe6_08086624
func_fe6_08086624: @ 0x08086624
	ldr r2, .L08086634 @ =0x0203DBC8
	ldr r1, [r2]
	ldr r0, .L08086638 @ =0x50414D58
	cmp r1, r0
	bne .L0808663C
	ldr r0, [r2, #0x18]
	b .L0808663E
	.align 2, 0
.L08086634: .4byte 0x0203DBC8
.L08086638: .4byte 0x50414D58
.L0808663C:
	movs r0, #0
.L0808663E:
	bx lr

	thumb_func_start func_fe6_08086640
func_fe6_08086640: @ 0x08086640
	ldr r2, .L08086650 @ =0x0203DBC8
	ldr r1, [r2]
	ldr r0, .L08086654 @ =0x50414D58
	cmp r1, r0
	bne .L08086658
	movs r1, #0x16
	ldrsh r0, [r2, r1]
	b .L0808665A
	.align 2, 0
.L08086650: .4byte 0x0203DBC8
.L08086654: .4byte 0x50414D58
.L08086658:
	movs r0, #0
.L0808665A:
	bx lr

	thumb_func_start func_fe6_0808665C
func_fe6_0808665C: @ 0x0808665C
	adds r2, r0, #0
	movs r3, #0
	lsrs r0, r1, #0x1f
	adds r1, r1, r0
	asrs r1, r1, #1
	cmp r3, r1
	bge .L08086676
.L0808666A:
	ldrh r0, [r2]
	adds r3, r0, r3
	adds r2, #2
	subs r1, #1
	cmp r1, #0
	bne .L0808666A
.L08086676:
	lsls r0, r3, #0x10
	lsrs r0, r0, #0x10
	bx lr

	thumb_func_start func_fe6_0808667C
func_fe6_0808667C: @ 0x0808667C
	push {r4, lr}
	ldr r4, .L080866D0 @ =gBuf
	bl IsSramWorking
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080866E4
	ldr r1, .L080866D4 @ =ReadSramFast
	ldr r0, .L080866D8 @ =0x0E007000
	movs r2, #0x80
	lsls r2, r2, #5
	ldr r3, [r1]
	adds r1, r4, #0
	bl _call_via_r3
	ldr r1, [r4]
	ldr r0, .L080866DC @ =0x50414D58
	cmp r1, r0
	bne .L080866E4
	bl GetLang
	lsls r0, r0, #0x18
	ldr r1, .L080866E0 @ =0x00020223
	adds r0, r0, r1
	ldr r1, [r4, #8]
	cmp r1, r0
	bne .L080866E4
	ldrh r0, [r4, #4]
	cmp r0, #0
	beq .L080866E4
	adds r0, r4, #0
	adds r0, #8
	ldrh r1, [r4, #4]
	bl func_fe6_0808665C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r4, [r4, #6]
	cmp r4, r0
	bne .L080866E4
	movs r0, #1
	b .L080866E6
	.align 2, 0
.L080866D0: .4byte gBuf
.L080866D4: .4byte ReadSramFast
.L080866D8: .4byte 0x0E007000
.L080866DC: .4byte 0x50414D58
.L080866E0: .4byte 0x00020223
.L080866E4:
	movs r0, #0
.L080866E6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_080866EC
func_fe6_080866EC: @ 0x080866EC
	push {r4, r5, r6, lr}
	bl func_fe6_08086590
	ldr r5, .L08086754 @ =ReadSramFast
	bl func_fe6_08086624
	adds r4, r0, #0
	ldr r6, .L08086758 @ =gBuf
	bl func_fe6_08086640
	adds r2, r0, #0
	ldr r3, [r5]
	adds r0, r4, #0
	adds r1, r6, #0
	bl _call_via_r3
	ldr r4, .L0808675C @ =gTrialLoadInfo
	ldr r1, [r4]
	adds r0, r6, #0
	bl Decompress
	ldr r1, [r4]
	ldr r0, .L08086760 @ =gPlaySt
	str r0, [r1, #0x18]
	ldr r0, .L08086764 @ =gBmSt
	str r0, [r1, #0x1c]
	ldr r0, .L08086768 @ =gActiveUnit
	str r0, [r1, #0x20]
	ldr r0, .L0808676C @ =gUnitLut
	str r0, [r1, #0x24]
	ldr r0, .L08086770 @ =gBattleUnitA
	str r0, [r1, #0x28]
	ldr r0, .L08086774 @ =gBattleUnitB
	str r0, [r1, #0x2c]
	ldr r0, .L08086778 @ =gBattleHits
	str r0, [r1, #0x30]
	movs r0, #0
	bl GetTrap
	ldr r1, [r4]
	str r0, [r1, #0x34]
	bl GetPermanentFlagBits
	ldr r1, [r4]
	str r0, [r1, #0x38]
	bl GetChapterFlagBits
	ldr r1, [r4]
	str r0, [r1, #0x3c]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
.L08086754: .4byte ReadSramFast
.L08086758: .4byte gBuf
.L0808675C: .4byte gTrialLoadInfo
.L08086760: .4byte gPlaySt
.L08086764: .4byte gBmSt
.L08086768: .4byte gActiveUnit
.L0808676C: .4byte gUnitLut
.L08086770: .4byte gBattleUnitA
.L08086774: .4byte gBattleUnitB
.L08086778: .4byte gBattleHits

	thumb_func_start func_fe6_0808677C
func_fe6_0808677C: @ 0x0808677C
	push {r4, lr}
	sub sp, #0x20
	adds r4, r0, #0
	mov r0, sp
	bl LoadGlobalSaveInfo
	movs r0, #0x28
	strb r0, [r4]
	adds r4, #1
	movs r0, #0x29
	strb r0, [r4]
	adds r4, #1
	mov r1, sp
	movs r0, #4
	ldrb r1, [r1, #0xe]
	ands r0, r1
	cmp r0, #0
	beq .L080867A6
	movs r0, #0x2a
	strb r0, [r4]
	adds r4, #1
.L080867A6:
	mov r1, sp
	movs r0, #2
	ldrb r1, [r1, #0xe]
	ands r0, r1
	cmp r0, #0
	beq .L080867B8
	movs r0, #0x2b
	strb r0, [r4]
	adds r4, #1
.L080867B8:
	mov r1, sp
	movs r0, #8
	ldrb r1, [r1, #0xe]
	ands r0, r1
	cmp r0, #0
	beq .L080867CA
	movs r0, #0x2c
	strb r0, [r4]
	adds r4, #1
.L080867CA:
	bl func_fe6_0808667C
	lsls r0, r0, #0x18
	cmp r0, #0
	beq .L080867E2
	bl func_fe6_080866EC
	movs r1, #1
	rsbs r1, r1, #0
	adds r0, r1, #0
	strb r0, [r4]
	adds r4, #1
.L080867E2:
	movs r0, #0
	strb r0, [r4]
	movs r0, #1
	add sp, #0x20
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start func_fe6_080867F0
func_fe6_080867F0: @ 0x080867F0
	push {lr}
	bl GetChapterUnk_0802BBD0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_080867FC
func_fe6_080867FC: @ 0x080867FC
	push {lr}
	movs r2, #0
	adds r0, #1
	cmp r0, #0x2d
	bls .L08086808
	b .L08086904
.L08086808:
	lsls r0, r0, #2
	ldr r1, .L08086814 @ =.L08086818
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08086814: .4byte .L08086818
.L08086818: @ jump table
	.4byte .L080868F8 @ case 0
	.4byte .L08086904 @ case 1
	.4byte .L08086904 @ case 2
	.4byte .L08086904 @ case 3
	.4byte .L08086904 @ case 4
	.4byte .L08086904 @ case 5
	.4byte .L08086904 @ case 6
	.4byte .L08086904 @ case 7
	.4byte .L08086904 @ case 8
	.4byte .L08086904 @ case 9
	.4byte .L08086904 @ case 10
	.4byte .L08086904 @ case 11
	.4byte .L08086904 @ case 12
	.4byte .L08086904 @ case 13
	.4byte .L08086904 @ case 14
	.4byte .L08086904 @ case 15
	.4byte .L08086904 @ case 16
	.4byte .L08086904 @ case 17
	.4byte .L08086904 @ case 18
	.4byte .L08086904 @ case 19
	.4byte .L08086904 @ case 20
	.4byte .L08086904 @ case 21
	.4byte .L08086904 @ case 22
	.4byte .L08086904 @ case 23
	.4byte .L08086904 @ case 24
	.4byte .L08086904 @ case 25
	.4byte .L08086904 @ case 26
	.4byte .L08086904 @ case 27
	.4byte .L08086904 @ case 28
	.4byte .L08086904 @ case 29
	.4byte .L08086904 @ case 30
	.4byte .L08086904 @ case 31
	.4byte .L08086904 @ case 32
	.4byte .L08086904 @ case 33
	.4byte .L08086904 @ case 34
	.4byte .L08086904 @ case 35
	.4byte .L08086904 @ case 36
	.4byte .L08086904 @ case 37
	.4byte .L08086904 @ case 38
	.4byte .L08086904 @ case 39
	.4byte .L08086904 @ case 40
	.4byte .L080868D0 @ case 41
	.4byte .L080868D8 @ case 42
	.4byte .L080868E0 @ case 43
	.4byte .L080868E8 @ case 44
	.4byte .L080868F0 @ case 45
.L080868D0:
	ldr r2, .L080868D4 @ =0x00000C7C
	b .L08086904
	.align 2, 0
.L080868D4: .4byte 0x00000C7C
.L080868D8:
	ldr r2, .L080868DC @ =0x00000C7F
	b .L08086904
	.align 2, 0
.L080868DC: .4byte 0x00000C7F
.L080868E0:
	ldr r2, .L080868E4 @ =0x00000C82
	b .L08086904
	.align 2, 0
.L080868E4: .4byte 0x00000C82
.L080868E8:
	ldr r2, .L080868EC @ =0x00000C85
	b .L08086904
	.align 2, 0
.L080868EC: .4byte 0x00000C85
.L080868F0:
	ldr r2, .L080868F4 @ =0x00000C88
	b .L08086904
	.align 2, 0
.L080868F4: .4byte 0x00000C88
.L080868F8:
	ldr r0, .L08086900 @ =gTrialLoadInfo
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	b .L0808690A
	.align 2, 0
.L08086900: .4byte gTrialLoadInfo
.L08086904:
	adds r0, r2, #0
	bl DecodeMsg
.L0808690A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start func_fe6_08086910
func_fe6_08086910: @ 0x08086910
	push {lr}
	movs r2, #0
	adds r0, #1
	cmp r0, #0x2d
	bls .L0808691C
	b .L08086A18
.L0808691C:
	lsls r0, r0, #2
	ldr r1, .L08086928 @ =.L0808692C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
.L08086928: .4byte .L0808692C
.L0808692C: @ jump table
	.4byte .L08086A0C @ case 0
	.4byte .L08086A18 @ case 1
	.4byte .L08086A18 @ case 2
	.4byte .L08086A18 @ case 3
	.4byte .L08086A18 @ case 4
	.4byte .L08086A18 @ case 5
	.4byte .L08086A18 @ case 6
	.4byte .L08086A18 @ case 7
	.4byte .L08086A18 @ case 8
	.4byte .L08086A18 @ case 9
	.4byte .L08086A18 @ case 10
	.4byte .L08086A18 @ case 11
	.4byte .L08086A18 @ case 12
	.4byte .L08086A18 @ case 13
	.4byte .L08086A18 @ case 14
	.4byte .L08086A18 @ case 15
	.4byte .L08086A18 @ case 16
	.4byte .L08086A18 @ case 17
	.4byte .L08086A18 @ case 18
	.4byte .L08086A18 @ case 19
	.4byte .L08086A18 @ case 20
	.4byte .L08086A18 @ case 21
	.4byte .L08086A18 @ case 22
	.4byte .L08086A18 @ case 23
	.4byte .L08086A18 @ case 24
	.4byte .L08086A18 @ case 25
	.4byte .L08086A18 @ case 26
	.4byte .L08086A18 @ case 27
	.4byte .L08086A18 @ case 28
	.4byte .L08086A18 @ case 29
	.4byte .L08086A18 @ case 30
	.4byte .L08086A18 @ case 31
	.4byte .L08086A18 @ case 32
	.4byte .L08086A18 @ case 33
	.4byte .L08086A18 @ case 34
	.4byte .L08086A18 @ case 35
	.4byte .L08086A18 @ case 36
	.4byte .L08086A18 @ case 37
	.4byte .L08086A18 @ case 38
	.4byte .L08086A18 @ case 39
	.4byte .L08086A18 @ case 40
	.4byte .L080869E4 @ case 41
	.4byte .L080869EC @ case 42
	.4byte .L080869F2 @ case 43
	.4byte .L080869FC @ case 44
	.4byte .L08086A04 @ case 45
.L080869E4:
	ldr r2, .L080869E8 @ =0x00000C7D
	b .L08086A18
	.align 2, 0
.L080869E8: .4byte 0x00000C7D
.L080869EC:
	movs r2, #0xc8
	lsls r2, r2, #4
	b .L08086A18
.L080869F2:
	ldr r2, .L080869F8 @ =0x00000C83
	b .L08086A18
	.align 2, 0
.L080869F8: .4byte 0x00000C83
.L080869FC:
	ldr r2, .L08086A00 @ =0x00000C86
	b .L08086A18
	.align 2, 0
.L08086A00: .4byte 0x00000C86
.L08086A04:
	ldr r2, .L08086A08 @ =0x00000C89
	b .L08086A18
	.align 2, 0
.L08086A08: .4byte 0x00000C89
.L08086A0C:
	ldr r0, .L08086A14 @ =gTrialLoadInfo
	ldr r0, [r0]
	ldr r0, [r0, #0x14]
	b .L08086A1E
	.align 2, 0
.L08086A14: .4byte gTrialLoadInfo
.L08086A18:
	adds r0, r2, #0
	bl DecodeMsg
.L08086A1E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start LoadTrialMapBonusUnits
LoadTrialMapBonusUnits: @ 0x08086A24
	push {r4, lr}
	bl GetGlobalCompletedPlaythroughCount
	adds r4, r0, #1
	ldr r1, .L08086A88 @ =gMapHidden
	movs r0, #0
	str r0, [r1]
	cmp r4, #1
	ble .L08086A3C
	ldr r0, .L08086A8C @ =gUnk_086876AC
	bl BatchCreateUnits
.L08086A3C:
	cmp r4, #2
	ble .L08086A46
	ldr r0, .L08086A90 @ =gUnk_086876CC
	bl BatchCreateUnits
.L08086A46:
	cmp r4, #3
	ble .L08086A50
	ldr r0, .L08086A94 @ =gUnk_086876EC
	bl BatchCreateUnits
.L08086A50:
	cmp r4, #4
	ble .L08086A5A
	ldr r0, .L08086A98 @ =gUnk_0868770C
	bl BatchCreateUnits
.L08086A5A:
	cmp r4, #5
	ble .L08086A64
	ldr r0, .L08086A9C @ =gUnk_0868772C
	bl BatchCreateUnits
.L08086A64:
	cmp r4, #6
	ble .L08086A6E
	ldr r0, .L08086AA0 @ =gUnk_0868774C
	bl BatchCreateUnits
.L08086A6E:
	cmp r4, #7
	ble .L08086A78
	ldr r0, .L08086AA4 @ =gUnk_0868776C
	bl BatchCreateUnits
.L08086A78:
	cmp r4, #9
	ble .L08086A82
	ldr r0, .L08086AA8 @ =gUnk_0868778C
	bl BatchCreateUnits
.L08086A82:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L08086A88: .4byte gMapHidden
.L08086A8C: .4byte gUnk_086876AC
.L08086A90: .4byte gUnk_086876CC
.L08086A94: .4byte gUnk_086876EC
.L08086A98: .4byte gUnk_0868770C
.L08086A9C: .4byte gUnk_0868772C
.L08086AA0: .4byte gUnk_0868774C
.L08086AA4: .4byte gUnk_0868776C
.L08086AA8: .4byte gUnk_0868778C

	thumb_func_start func_fe6_08086AAC
func_fe6_08086AAC: @ 0x08086AAC
	push {r4, r5, lr}
	bl GetGameTime
	ldr r4, .L08086AF4 @ =gPlaySt
	ldr r1, [r4, #4]
	subs r0, r0, r1
	movs r1, #0xb4
	bl __udivsi3
	adds r3, r0, #0
	ldr r0, .L08086AF8 @ =0x0000EA60
	cmp r3, r0
	ble .L08086AC8
	adds r3, r0, #0
.L08086AC8:
	ldr r0, .L08086AFC @ =0x0203DBE4
	movs r2, #0x3f
	ldrb r1, [r4, #0xe]
	ands r2, r1
	movs r1, #0x40
	rsbs r1, r1, #0
	ldrb r5, [r0]
	ands r1, r5
	orrs r1, r2
	strb r1, [r0]
	ldrh r4, [r4, #0x10]
	lsls r2, r4, #6
	movs r1, #0x3f
	ldrh r4, [r0]
	ands r1, r4
	orrs r1, r2
	strh r1, [r0]
	strh r3, [r0, #2]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
.L08086AF4: .4byte gPlaySt
.L08086AF8: .4byte 0x0000EA60
.L08086AFC: .4byte 0x0203DBE4
