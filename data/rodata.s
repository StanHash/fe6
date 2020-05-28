
	.section .rodata

	BEGIN = 0x105A18
	END   = 0x380F7C

	.incbin "fe6-base.gba", BEGIN, (0x2D80B0 - BEGIN)

	@ scene background data

	.global Img_Background_082D80B0
Img_Background_082D80B0: @ 082D80B0
	.incbin "fe6-base.gba", 0x2D80B0, (0x2DAC8C - 0x2D80B0)

	.global Tsa_Background_082DAC8C
Tsa_Background_082DAC8C: @ 082DAC8C
	.incbin "fe6-base.gba", 0x2DAC8C, (0x2DB140 - 0x2DAC8C)

	.global Pal_Background_082DB140
Pal_Background_082DB140: @ 082DB140
	.incbin "fe6-base.gba", 0x2DB140, (0x2E28F8 - 0x2DB140)

	.global Img_Background_082E28F8
Img_Background_082E28F8: @ 082E28F8
	.incbin "fe6-base.gba", 0x2E28F8, (0x2E35DC - 0x2E28F8)

	.global Tsa_Background_082E35DC
Tsa_Background_082E35DC: @ 082E35DC
	.incbin "fe6-base.gba", 0x2E35DC, (0x2E3A90 - 0x2E35DC)

	.global Pal_Background_082E3A90
Pal_Background_082E3A90: @ 082E3A90
	.incbin "fe6-base.gba", 0x2E3A90, (0x2E3B10 - 0x2E3A90)

	.global Img_Background_082E3B10
Img_Background_082E3B10: @ 082E3B10
	.incbin "fe6-base.gba", 0x2E3B10, (0x2E3EC0 - 0x2E3B10)

	.global Tsa_Background_082E3EC0
Tsa_Background_082E3EC0: @ 082E3EC0
	.incbin "fe6-base.gba", 0x2E3EC0, (0x2E4374 - 0x2E3EC0)

	.global Pal_Background_082E4374
Pal_Background_082E4374: @ 082E4374
	.incbin "fe6-base.gba", 0x2E4374, (0x2E4650 - 0x2E4374)

	.global Img_Background_082E4650
Img_Background_082E4650: @ 082E4650
	.incbin "fe6-base.gba", 0x2E4650, (0x2E6EB4 - 0x2E4650)

	.global Tsa_Background_082E6EB4
Tsa_Background_082E6EB4: @ 082E6EB4
	.incbin "fe6-base.gba", 0x2E6EB4, (0x2E7368 - 0x2E6EB4)

	.global Pal_Background_082E7368
Pal_Background_082E7368: @ 082E7368
	.incbin "fe6-base.gba", 0x2E7368, (0x2E73E8 - 0x2E7368)

	.global Img_Background_082E73E8
Img_Background_082E73E8: @ 082E73E8
	.incbin "fe6-base.gba", 0x2E73E8, (0x2EADF0 - 0x2E73E8)

	.global Tsa_Background_082EADF0
Tsa_Background_082EADF0: @ 082EADF0
	.incbin "fe6-base.gba", 0x2EADF0, (0x2EB2A4 - 0x2EADF0)

	.global Pal_Background_082EB2A4
Pal_Background_082EB2A4: @ 082EB2A4
	.incbin "fe6-base.gba", 0x2EB2A4, (0x2EB324 - 0x2EB2A4)

	.global Img_Background_082EB324
Img_Background_082EB324: @ 082EB324
	.incbin "fe6-base.gba", 0x2EB324, (0x2EDB7C - 0x2EB324)

	.global Tsa_Background_082EDB7C
Tsa_Background_082EDB7C: @ 082EDB7C
	.incbin "fe6-base.gba", 0x2EDB7C, (0x2EE030 - 0x2EDB7C)

	.global Pal_Background_082EE030
Pal_Background_082EE030: @ 082EE030
	.incbin "fe6-base.gba", 0x2EE030, (0x2EE0B0 - 0x2EE030)

	.global Img_Background_082EE0B0
Img_Background_082EE0B0: @ 082EE0B0
	.incbin "fe6-base.gba", 0x2EE0B0, (0x2EF97C - 0x2EE0B0)

	.global Tsa_Background_082EF97C
Tsa_Background_082EF97C: @ 082EF97C
	.incbin "fe6-base.gba", 0x2EF97C, (0x2EFE30 - 0x2EF97C)

	.global Pal_Background_082EFE30
Pal_Background_082EFE30: @ 082EFE30
	.incbin "fe6-base.gba", 0x2EFE30, (0x2EFEB0 - 0x2EFE30)

	.global Pal_Background_082EFEB0
Pal_Background_082EFEB0: @ 082EFEB0
	.incbin "fe6-base.gba", 0x2EFEB0, (0x2EFF30 - 0x2EFEB0)

	.global Img_Background_082EFF30
Img_Background_082EFF30: @ 082EFF30
	.incbin "fe6-base.gba", 0x2EFF30, (0x2F1490 - 0x2EFF30)

	.global Tsa_Background_082F1490
Tsa_Background_082F1490: @ 082F1490
	.incbin "fe6-base.gba", 0x2F1490, (0x2F1944 - 0x2F1490)

	.global Pal_Background_082F1944
Pal_Background_082F1944: @ 082F1944
	.incbin "fe6-base.gba", 0x2F1944, (0x2F19C4 - 0x2F1944)

	.global Img_Background_082F19C4
Img_Background_082F19C4: @ 082F19C4
	.incbin "fe6-base.gba", 0x2F19C4, (0x2F3494 - 0x2F19C4)

	.global Tsa_Background_082F3494
Tsa_Background_082F3494: @ 082F3494
	.incbin "fe6-base.gba", 0x2F3494, (0x2F3948 - 0x2F3494)

	.global Pal_Background_082F3948
Pal_Background_082F3948: @ 082F3948
	.incbin "fe6-base.gba", 0x2F3948, (0x2F39C8 - 0x2F3948)

	.global Img_Background_082F39C8
Img_Background_082F39C8: @ 082F39C8
	.incbin "fe6-base.gba", 0x2F39C8, (0x2F62E0 - 0x2F39C8)

	.global Tsa_Background_082F62E0
Tsa_Background_082F62E0: @ 082F62E0
	.incbin "fe6-base.gba", 0x2F62E0, (0x2F6794 - 0x2F62E0)

	.global Pal_Background_082F6794
Pal_Background_082F6794: @ 082F6794
	.incbin "fe6-base.gba", 0x2F6794, (0x2F6814 - 0x2F6794)

	.global Pal_Background_082F6814
Pal_Background_082F6814: @ 082F6814
	.incbin "fe6-base.gba", 0x2F6814, (0x2F6894 - 0x2F6814)

	.global Img_Background_082F6894
Img_Background_082F6894: @ 082F6894
	.incbin "fe6-base.gba", 0x2F6894, (0x2F85E8 - 0x2F6894)

	.global Tsa_Background_082F85E8
Tsa_Background_082F85E8: @ 082F85E8
	.incbin "fe6-base.gba", 0x2F85E8, (0x2F8A9C - 0x2F85E8)

	.global Pal_Background_082F8A9C
Pal_Background_082F8A9C: @ 082F8A9C
	.incbin "fe6-base.gba", 0x2F8A9C, (0x2F8B1C - 0x2F8A9C)

	.global Img_Background_082F8B1C
Img_Background_082F8B1C: @ 082F8B1C
	.incbin "fe6-base.gba", 0x2F8B1C, (0x2FBE6C - 0x2F8B1C)

	.global Tsa_Background_082FBE6C
Tsa_Background_082FBE6C: @ 082FBE6C
	.incbin "fe6-base.gba", 0x2FBE6C, (0x2FC320 - 0x2FBE6C)

	.global Pal_Background_082FC320
Pal_Background_082FC320: @ 082FC320
	.incbin "fe6-base.gba", 0x2FC320, (0x2FC3A0 - 0x2FC320)

	.global Img_Background_082FC3A0
Img_Background_082FC3A0: @ 082FC3A0
	.incbin "fe6-base.gba", 0x2FC3A0, (0x2FECE0 - 0x2FC3A0)

	.global Tsa_Background_082FECE0
Tsa_Background_082FECE0: @ 082FECE0
	.incbin "fe6-base.gba", 0x2FECE0, (0x2FF194 - 0x2FECE0)

	.global Pal_Background_082FF194
Pal_Background_082FF194: @ 082FF194
	.incbin "fe6-base.gba", 0x2FF194, (0x2FF214 - 0x2FF194)

	.global Img_Background_082FF214
Img_Background_082FF214: @ 082FF214
	.incbin "fe6-base.gba", 0x2FF214, (0x301244 - 0x2FF214)

	.global Tsa_Background_08301244
Tsa_Background_08301244: @ 08301244
	.incbin "fe6-base.gba", 0x301244, (0x3016F8 - 0x301244)

	.global Pal_Background_083016F8
Pal_Background_083016F8: @ 083016F8
	.incbin "fe6-base.gba", 0x3016F8, (0x301778 - 0x3016F8)

	.global Pal_Background_08301778
Pal_Background_08301778: @ 08301778
	.incbin "fe6-base.gba", 0x301778, (0x3017F8 - 0x301778)

	.global Pal_Background_083017F8
Pal_Background_083017F8: @ 083017F8
	.incbin "fe6-base.gba", 0x3017F8, (0x301878 - 0x3017F8)

	.global Img_Background_08301878
Img_Background_08301878: @ 08301878
	.incbin "fe6-base.gba", 0x301878, (0x30491C - 0x301878)

	.global Tsa_Background_0830491C
Tsa_Background_0830491C: @ 0830491C
	.incbin "fe6-base.gba", 0x30491C, (0x304DD0 - 0x30491C)

	.global Pal_Background_08304DD0
Pal_Background_08304DD0: @ 08304DD0
	.incbin "fe6-base.gba", 0x304DD0, (0x304E50 - 0x304DD0)

	.global Img_Background_08304E50
Img_Background_08304E50: @ 08304E50
	.incbin "fe6-base.gba", 0x304E50, (0x306F24 - 0x304E50)

	.global Tsa_Background_08306F24
Tsa_Background_08306F24: @ 08306F24
	.incbin "fe6-base.gba", 0x306F24, (0x3073D8 - 0x306F24)

	.global Pal_Background_083073D8
Pal_Background_083073D8: @ 083073D8
	.incbin "fe6-base.gba", 0x3073D8, (END - 0x3073D8)
