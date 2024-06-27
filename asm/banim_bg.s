	.include "macro.inc"

	.syntax unified

	thumb_func_start func_fe6_0805F078
func_fe6_0805F078: @ 0x0805F078
	push {lr}
	lsls r1, r0, #1
	adds r1, r1, r0
	ldr r0, .L0805F090 @ =gUnk_08607504
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	ldr r1, .L0805F094 @ =0x06008000
	bl LZ77UnCompVram
	pop {r0}
	bx r0
	.align 2, 0
.L0805F090: .4byte gUnk_08607504
.L0805F094: .4byte 0x06008000

	thumb_func_start func_fe6_0805F098
func_fe6_0805F098: @ 0x0805F098
	push {r4, lr}
	sub sp, #8
	lsls r1, r0, #1
	adds r1, r1, r0
	adds r1, #1
	ldr r0, .L0805F0D0 @ =gUnk_08607504
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	ldr r4, .L0805F0D4 @ =gEkrTsaBuffer
	adds r1, r4, #0
	bl LZ77UnCompWram
	ldr r1, .L0805F0D8 @ =gBg3Tm
	movs r0, #6
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r2, #0x1e
	movs r3, #0x14
	bl EfxTmCpyBG
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
.L0805F0D0: .4byte gUnk_08607504
.L0805F0D4: .4byte gEkrTsaBuffer
.L0805F0D8: .4byte gBg3Tm

	thumb_func_start func_fe6_0805F0DC
func_fe6_0805F0DC: @ 0x0805F0DC
	push {lr}
	lsls r1, r0, #1
	adds r1, r1, r0
	adds r1, #2
	ldr r0, .L0805F0F8 @ =gUnk_08607504
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	ldr r1, .L0805F0FC @ =gPal+0xC0
	bl LZ77UnCompWram
	pop {r0}
	bx r0
	.align 2, 0
.L0805F0F8: .4byte gUnk_08607504
.L0805F0FC: .4byte gPal+0xC0

	thumb_func_start func_fe6_0805F100
func_fe6_0805F100: @ 0x0805F100
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	bl func_fe6_0805F078
	movs r5, #0
	str r5, [sp]
	ldr r1, .L0805F13C @ =0x0600FFE0
	ldr r2, .L0805F140 @ =0x01000008
	mov r0, sp
	bl CpuFastSet
	adds r0, r4, #0
	bl func_fe6_0805F098
	adds r0, r4, #0
	bl func_fe6_0805F0DC
	ldr r0, .L0805F144 @ =gPal
	strh r5, [r0]
	movs r0, #8
	bl EnableBgSync
	bl EnablePalSync
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
.L0805F13C: .4byte 0x0600FFE0
.L0805F140: .4byte 0x01000008
.L0805F144: .4byte gPal
