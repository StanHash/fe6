
	.section .rodata

	BEGIN = 0x100130
	END   = 0x380F7C

	.incbin "fe6-base.gba", BEGIN, (END - BEGIN)
