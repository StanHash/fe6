
	.section .rodata

	BEGIN = 0x1004A4
	END   = 0x105710

	.incbin "fe6-base.gba", BEGIN, (END - BEGIN)
