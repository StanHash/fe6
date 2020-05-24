
	.data

	BEGIN = 0x5C5DE8
	END   = 0x800000

	.incbin "fe6-base.gba", BEGIN, (END - BEGIN)
