
	.section .rodata

	BEGIN = 0x105DD0
	END   = 0x10D668

	.incbin "fe6-base.gba", BEGIN, (END - BEGIN)
