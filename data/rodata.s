
	.section .rodata

	BEGIN = 0x0F97BC
	END   = 0x380F7C

	.incbin "fe6-base.gba", BEGIN, (END - BEGIN)
