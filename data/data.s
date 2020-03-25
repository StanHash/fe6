
	.data

	BEGIN = 0x5C3CE8
	END   = 0x800000

	.incbin "fe6-base.gba", BEGIN, (END - BEGIN)
