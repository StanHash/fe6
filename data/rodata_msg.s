
	.section .rodata

	.incbin "fe6-base.gba", 0x09FAC0, (0x0F635C - 0x09FAC0)

	.global gMsgTable
gMsgTable: @ 080F635C
	.incbin "fe6-base.gba", 0x0F635C, (0x0F9794 - 0x0F635C)
