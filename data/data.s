
	.data

	BEGIN = 0x58EE2C
	END   = 0x800000

	.incbin "fe6-base.gba", BEGIN, (END - BEGIN)
