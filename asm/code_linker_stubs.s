	.include "macro.inc"

	@ modern ld doesn't generate the same sequences
	@ so we can't use it to replace this file in matching builds

	thumb_func_start ClearOam_t
ClearOam_t: @ 0x0809FA90
	bx pc
	.align
	.arm
	b ClearOam

	thumb_func_start TmApplyTsa_t
TmApplyTsa_t: @ 0x0809FA98
	bx pc
	.align
	.arm
	b TmApplyTsa

	thumb_func_start TmFillRect_t
TmFillRect_t: @ 0x0809FAA0
	bx pc
	.align
	.arm
	b TmFillRect

	thumb_func_start func_fe6_08000234_t
func_fe6_08000234_t: @ 0x0809FAA8
	bx pc
	.align
	.arm
	b func_fe6_08000234

	thumb_func_start TmCopyRect_t
TmCopyRect_t: @ 0x0809FAB0
	bx pc
	.align
	.arm
	b TmCopyRect

	thumb_func_start Checksum32_t
Checksum32_t: @ 0x0809FAB8
	bx pc
	.align
	.arm
	b Checksum32
