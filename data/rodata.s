
	.section .rodata

	BEGIN = 0x0FFDF8
	END   = 0x380F7C

	.incbin "fe6-base.gba", BEGIN, (END - BEGIN)
