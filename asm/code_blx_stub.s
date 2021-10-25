
	.include "macro.inc"

	thumb_func_start ClearOam_t
ClearOam_t: @ 0x0809FA90
	bx pc
	nop
.L0809FA94:
	.byte 0x1A, 0x82, 0xFD, 0xEA

	thumb_func_start TmApplyTsa_t
TmApplyTsa_t: @ 0x0809FA98
	bx pc
	nop
.L0809FA9C:
	.byte 0x66, 0x82, 0xFD, 0xEA

	thumb_func_start TmFillRect_t
TmFillRect_t: @ 0x0809FAA0
	bx pc
	nop
.L0809FAA4:
	.byte 0x3F, 0x82, 0xFD, 0xEA

	thumb_func_start sub_8000234_t
sub_8000234_t: @ 0x0809FAA8
	bx pc
	nop
.L0809FAAC:
	.byte 0xE0, 0x81, 0xFD, 0xEA

	thumb_func_start TmCopyRect_t
TmCopyRect_t: @ 0x0809FAB0
	bx pc
	nop
.L0809FAB4:
	.byte 0x49, 0x82, 0xFD, 0xEA

	thumb_func_start sub_8000360_t
sub_8000360_t: @ 0x0809FAB8
	bx pc
	nop

	.arm

	b sub_8000360
