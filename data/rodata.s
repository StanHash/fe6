
	.section .rodata

	BEGIN = 0x10013C
	END   = 0x380F7C

	.incbin "fe6-base.gba", BEGIN, (END - BEGIN)
