    .include "asm_macros.inc"

    .text

    .global ArmCodeStart
    .type ArmCodeStart, object
ArmCodeStart:

    .syntax unified
    .arm

.LPal: .4byte gPal
.LFadeComponents: .4byte gFadeComponents
.LFadeComponentStep: .4byte gFadeComponentStep

    function ColorFadeTick
ColorFadeTick:
    push {r4-r7}

    @ r7 = start offset of next palette
    @ we start from the end, so palette 0x1F
    mov  r7, 0x20 * 0x1F

.Lpal_loop:
    @ r0 = gFadeComponentStep + pal_idx
    ldr  r0, .LFadeComponentStep
    add  r0, r0, r7, lsr 5

    @ r5 = component step for this palette
    ldsb r5, [r0]

    @ skip if step is 0
    tst  r5, r5
    beq  .Lpal_loop_continue

    ldr  r4, .LFadeComponents

    @ r4 = r4 + 0x30 + r7 * 1.5
    lsr  r0, r7, 1
    add  r0, r0, r0, lsl 1
    add  r0, 0x30
    add  r4, r0

    @ r6 = start offset of next color
    @ starting from the end again
    mov  r6, 0x1E

.Lcolor_loop:
    sub  r4, 3

    @ the clamp compares could be made branchless with some conditional operations
    @ eg: subs r0, 0x20 ; movlo r0, 0 ; cmp r0, 0x20 ; movhs r0, 0x1F

    @ get, update and clamp red component (r0)
    ldrb r0, [r4, 0]
    add  r0, r5
    strb r0, [r4, 0]
    subs r0, 0x20
    bpl  1f
    mov  r0, 0
1:  cmp  r0, 0x20
    blo  1f
    mov  r0, 0x1F
1:

    @ get, update and clamp green component (r1)
    ldrb r1, [r4, 1]
    add  r1, r5
    strb r1, [r4, 1]
    subs r1, 0x20
    bpl  1f
    mov  r1, 0
1:  cmp  r1, 0x20
    blo  1f
    mov  r1, 0x1F
1:

    @ get, update and clamp blue component (r2)
    ldrb r2, [r4, 2]
    add  r2, r5
    strb r2, [r4, 2]
    subs r2, 0x20
    bpl  1f
    mov  r2, 0
1:  cmp  r2, 0x20
    blo  1f
    mov  r2, 0x1F
1:

    @ get combined RGB5 color value
    add  r0, r0, r1, lsl 5
    add  r0, r0, r2, lsl 10

    @ store updated color to pal buffer
    ldr  r1, .LPal
    add  r1, r6
    strh r0, [r1, r7]

    subs r6, 2
    bpl  .Lcolor_loop

.Lpal_loop_continue:
    subs r7, 0x20
    bpl  .Lpal_loop

    @ end
    pop  {r4-r7}
    bx   lr

    endfunction ColorFadeTick

    function ClearOam
ClearOam:
    lsr  r1, 4
    sub  r1, 1

    mov  r2, 0xA0

.Loam_loop:
    str  r2, [r0, 0x00]
    str  r2, [r0, 0x08]
    str  r2, [r0, 0x10]
    str  r2, [r0, 0x18]
    str  r2, [r0, 0x20]
    str  r2, [r0, 0x28]
    str  r2, [r0, 0x30]
    str  r2, [r0, 0x38]
    str  r2, [r0, 0x40]
    str  r2, [r0, 0x48]
    str  r2, [r0, 0x50]
    str  r2, [r0, 0x58]
    str  r2, [r0, 0x60]
    str  r2, [r0, 0x68]
    str  r2, [r0, 0x70]
    str  r2, [r0, 0x78]

    add  r0, 0x80

    subs r1, 1
    bpl  .Loam_loop

    @ end
    bx   lr

    endfunction ClearOam
