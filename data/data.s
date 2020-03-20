
	.data

	BEGIN = 0x58E58C
	END   = 0x800000

	.incbin "fe6-base.gba", BEGIN, (END - BEGIN)
