
	.section .rodata

	BEGIN = 0x10DBCC
	END   = 0x380F7C

	.incbin "fe6-base.gba", BEGIN, (0x2563F4 - BEGIN)

	@ tileset animations

	.global Img_TilesetAnim_085C788C_0
Img_TilesetAnim_085C788C_0: @ 082563F4
	.incbin "fe6-base.gba", 0x2563F4, (0x2573F4 - 0x2563F4)

	.global Img_TilesetAnim_085C788C_1
Img_TilesetAnim_085C788C_1: @ 082573F4
	.incbin "fe6-base.gba", 0x2573F4, (0x2583F4 - 0x2573F4)

	.global Img_TilesetAnim_085C788C_2
Img_TilesetAnim_085C788C_2: @ 082583F4
	.incbin "fe6-base.gba", 0x2583F4, (0x2593F4 - 0x2583F4)

	.global Img_TilesetAnim_085C788C_3
Img_TilesetAnim_085C788C_3: @ 082593F4
	.incbin "fe6-base.gba", 0x2593F4, (0x25A3F4 - 0x2593F4)

	.global Img_TilesetAnim_085C788C_4
Img_TilesetAnim_085C788C_4: @ 0825A3F4
	.incbin "fe6-base.gba", 0x25A3F4, (0x25B3F4 - 0x25A3F4)

	.global Img_TilesetAnim_085C788C_5
Img_TilesetAnim_085C788C_5: @ 0825B3F4
	.incbin "fe6-base.gba", 0x25B3F4, (0x25C3F4 - 0x25B3F4)

	.global Img_TilesetAnim_085C788C_6
Img_TilesetAnim_085C788C_6: @ 0825C3F4
	.incbin "fe6-base.gba", 0x25C3F4, (0x25D3F4 - 0x25C3F4)

	.global Img_TilesetAnim_085C788C_7
Img_TilesetAnim_085C788C_7: @ 0825D3F4
	.incbin "fe6-base.gba", 0x25D3F4, (0x25E3F4 - 0x25D3F4)

	.global Img_TilesetAnim_085C788C_8
Img_TilesetAnim_085C788C_8: @ 0825E3F4
	.incbin "fe6-base.gba", 0x25E3F4, (0x25F3F4 - 0x25E3F4)

	.global Img_TilesetAnim_085C788C_9
Img_TilesetAnim_085C788C_9: @ 0825F3F4
	.incbin "fe6-base.gba", 0x25F3F4, (0x2603F4 - 0x25F3F4)

	.global Img_TilesetAnim_085C788C_10
Img_TilesetAnim_085C788C_10: @ 082603F4
	.incbin "fe6-base.gba", 0x2603F4, (0x2613F4 - 0x2603F4)

	.global Img_TilesetAnim_085C788C_11
Img_TilesetAnim_085C788C_11: @ 082613F4
	.incbin "fe6-base.gba", 0x2613F4, (0x2623F4 - 0x2613F4)

	.global Img_TilesetAnim_085C788C_12
Img_TilesetAnim_085C788C_12: @ 082623F4
	.incbin "fe6-base.gba", 0x2623F4, (0x2633F4 - 0x2623F4)

	.global Img_TilesetAnim_085C788C_13
Img_TilesetAnim_085C788C_13: @ 082633F4
	.incbin "fe6-base.gba", 0x2633F4, (0x2643F4 - 0x2633F4)

	.global Img_TilesetAnim_085C788C_14
Img_TilesetAnim_085C788C_14: @ 082643F4
	.incbin "fe6-base.gba", 0x2643F4, (0x2653F4 - 0x2643F4)

	.global Img_TilesetAnim_085C788C_15
Img_TilesetAnim_085C788C_15: @ 082653F4
	.incbin "fe6-base.gba", 0x2653F4, (0x2663F4 - 0x2653F4)

	.global Img_TilesetAnim_085C7914_0
Img_TilesetAnim_085C7914_0: @ 082663F4
	.incbin "fe6-base.gba", 0x2663F4, (0x2673F4 - 0x2663F4)

	.global Img_TilesetAnim_085C7914_1
Img_TilesetAnim_085C7914_1: @ 082673F4
	.incbin "fe6-base.gba", 0x2673F4, (0x2683F4 - 0x2673F4)

	.global Img_TilesetAnim_085C7914_2
Img_TilesetAnim_085C7914_2: @ 082683F4
	.incbin "fe6-base.gba", 0x2683F4, (0x2693F4 - 0x2683F4)

	.global Img_TilesetAnim_085C7914_3
Img_TilesetAnim_085C7914_3: @ 082693F4
	.incbin "fe6-base.gba", 0x2693F4, (0x26A3F4 - 0x2693F4)

	.global Img_TilesetAnim_085C7914_4
Img_TilesetAnim_085C7914_4: @ 0826A3F4
	.incbin "fe6-base.gba", 0x26A3F4, (0x26B3F4 - 0x26A3F4)

	.global Img_TilesetAnim_085C7914_5
Img_TilesetAnim_085C7914_5: @ 0826B3F4
	.incbin "fe6-base.gba", 0x26B3F4, (0x26C3F4 - 0x26B3F4)

	.global Img_TilesetAnim_085C7914_6
Img_TilesetAnim_085C7914_6: @ 0826C3F4
	.incbin "fe6-base.gba", 0x26C3F4, (0x26D3F4 - 0x26C3F4)

	.global Img_TilesetAnim_085C7914_7
Img_TilesetAnim_085C7914_7: @ 0826D3F4
	.incbin "fe6-base.gba", 0x26D3F4, (0x26E3F4 - 0x26D3F4)

	.global Img_TilesetAnim_085C7914_8
Img_TilesetAnim_085C7914_8: @ 0826E3F4
	.incbin "fe6-base.gba", 0x26E3F4, (0x26F3F4 - 0x26E3F4)

	.global Img_TilesetAnim_085C7914_9
Img_TilesetAnim_085C7914_9: @ 0826F3F4
	.incbin "fe6-base.gba", 0x26F3F4, (0x2703F4 - 0x26F3F4)

	.global Img_TilesetAnim_085C7914_10
Img_TilesetAnim_085C7914_10: @ 082703F4
	.incbin "fe6-base.gba", 0x2703F4, (0x2713F4 - 0x2703F4)

	.global Img_TilesetAnim_085C7914_11
Img_TilesetAnim_085C7914_11: @ 082713F4
	.incbin "fe6-base.gba", 0x2713F4, (0x2723F4 - 0x2713F4)

	.global Img_TilesetAnim_085C7914_12
Img_TilesetAnim_085C7914_12: @ 082723F4
	.incbin "fe6-base.gba", 0x2723F4, (0x2733F4 - 0x2723F4)

	.global Img_TilesetAnim_085C7914_13
Img_TilesetAnim_085C7914_13: @ 082733F4
	.incbin "fe6-base.gba", 0x2733F4, (0x2743F4 - 0x2733F4)

	.global Img_TilesetAnim_085C7914_14
Img_TilesetAnim_085C7914_14: @ 082743F4
	.incbin "fe6-base.gba", 0x2743F4, (0x2753F4 - 0x2743F4)

	.global Img_TilesetAnim_085C7914_15
Img_TilesetAnim_085C7914_15: @ 082753F4
	.incbin "fe6-base.gba", 0x2753F4, (0x2763F4 - 0x2753F4)

	.global Img_TilesetAnim_085C799C_0
Img_TilesetAnim_085C799C_0: @ 082763F4
	.incbin "fe6-base.gba", 0x2763F4, (0x2767F4 - 0x2763F4)

	.global Img_TilesetAnim_085C799C_1
Img_TilesetAnim_085C799C_1: @ 082767F4
	.incbin "fe6-base.gba", 0x2767F4, (0x276BF4 - 0x2767F4)

	.global Img_TilesetAnim_085C799C_2
Img_TilesetAnim_085C799C_2: @ 08276BF4
	.incbin "fe6-base.gba", 0x276BF4, (0x276FF4 - 0x276BF4)

	.global Img_TilesetAnim_085C799C_3
Img_TilesetAnim_085C799C_3: @ 08276FF4
	.incbin "fe6-base.gba", 0x276FF4, (0x2773F4 - 0x276FF4)

	.global Img_TilesetAnim_085C799C_4
Img_TilesetAnim_085C799C_4: @ 082773F4
	.incbin "fe6-base.gba", 0x2773F4, (0x2777F4 - 0x2773F4)

	.global Img_TilesetAnim_085C799C_5
Img_TilesetAnim_085C799C_5: @ 082777F4
	.incbin "fe6-base.gba", 0x2777F4, (0x277BF4 - 0x2777F4)

	.global Img_TilesetAnim_085C79D4_0
Img_TilesetAnim_085C79D4_0: @ 08277BF4
	.incbin "fe6-base.gba", 0x277BF4, (0x277FF4 - 0x277BF4)

	.global Img_TilesetAnim_085C79D4_1
Img_TilesetAnim_085C79D4_1: @ 08277FF4
	.incbin "fe6-base.gba", 0x277FF4, (0x2783F4 - 0x277FF4)

	.global Img_TilesetAnim_085C79D4_2
Img_TilesetAnim_085C79D4_2: @ 082783F4
	.incbin "fe6-base.gba", 0x2783F4, (0x2787F4 - 0x2783F4)

	.global Img_TilesetAnim_085C79D4_3
Img_TilesetAnim_085C79D4_3: @ 082787F4
	.incbin "fe6-base.gba", 0x2787F4, (0x278BF4 - 0x2787F4)

	.global Img_TilesetAnim_085C79D4_4
Img_TilesetAnim_085C79D4_4: @ 08278BF4
	.incbin "fe6-base.gba", 0x278BF4, (0x278FF4 - 0x278BF4)

	.global Img_TilesetAnim_085C79D4_5
Img_TilesetAnim_085C79D4_5: @ 08278FF4
	.incbin "fe6-base.gba", 0x278FF4, (0x2793F4 - 0x278FF4)

	.global Img_TilesetAnim_085C79D4_6
Img_TilesetAnim_085C79D4_6: @ 082793F4
	.incbin "fe6-base.gba", 0x2793F4, (0x2797F4 - 0x2793F4)

	.global Img_TilesetAnim_085C79D4_7
Img_TilesetAnim_085C79D4_7: @ 082797F4
	.incbin "fe6-base.gba", 0x2797F4, (0x279BF4 - 0x2797F4)

	.global Pal_TilesetAnim_085C7A1C_0
Pal_TilesetAnim_085C7A1C_0: @ 08279BF4
	.incbin "fe6-base.gba", 0x279BF4, (0x279BFC - 0x279BF4)

	.global Pal_TilesetAnim_085C7A1C_2
Pal_TilesetAnim_085C7A1C_2: @ 08279BFC
	.incbin "fe6-base.gba", 0x279BFC, (0x279C04 - 0x279BFC)

	.global Pal_TilesetAnim_085C7A1C_3
Pal_TilesetAnim_085C7A1C_3: @ 08279C04
	.incbin "fe6-base.gba", 0x279C04, (0x279C0C - 0x279C04)

	.global Pal_TilesetAnim_085C7A1C_4
Pal_TilesetAnim_085C7A1C_4: @ 08279C0C
	.incbin "fe6-base.gba", 0x279C0C, (0x279C14 - 0x279C0C)

	.global Pal_TilesetAnim_085C7A1C_5
Pal_TilesetAnim_085C7A1C_5: @ 08279C14
	.incbin "fe6-base.gba", 0x279C14, (0x279C1C - 0x279C14)

	.global Pal_TilesetAnim_085C7A1C_6
Pal_TilesetAnim_085C7A1C_6: @ 08279C1C
	.incbin "fe6-base.gba", 0x279C1C, (0x279C24 - 0x279C1C)

	.global Pal_TilesetAnim_085C7A1C_7
Pal_TilesetAnim_085C7A1C_7: @ 08279C24
	.incbin "fe6-base.gba", 0x279C24, (0x279C2E - 0x279C24)

	.global Pal_TilesetAnim_085C7A64_0
Pal_TilesetAnim_085C7A64_0: @ 08279C2E
	.incbin "fe6-base.gba", 0x279C2E, (0x279C34 - 0x279C2E)

	.global Pal_TilesetAnim_085C7A64_1
Pal_TilesetAnim_085C7A64_1: @ 08279C34
	.incbin "fe6-base.gba", 0x279C34, (0x279C3A - 0x279C34)

	.global Pal_TilesetAnim_085C7A64_2
Pal_TilesetAnim_085C7A64_2: @ 08279C3A
	.incbin "fe6-base.gba", 0x279C3A, (0x279C40 - 0x279C3A)

	.global Pal_TilesetAnim_085C7A64_3
Pal_TilesetAnim_085C7A64_3: @ 08279C40
	.incbin "fe6-base.gba", 0x279C40, (0x279C46 - 0x279C40)

	.global Pal_TilesetAnim_085C7A64_4
Pal_TilesetAnim_085C7A64_4: @ 08279C46
	.incbin "fe6-base.gba", 0x279C46, (0x279C4E - 0x279C46)

	.global Pal_TilesetAnim_085C7A64_5
Pal_TilesetAnim_085C7A64_5: @ 08279C4E
	.incbin "fe6-base.gba", 0x279C4E, (0x279C54 - 0x279C4E)

	.global Pal_TilesetAnim_085C7A64_6
Pal_TilesetAnim_085C7A64_6: @ 08279C54
	.incbin "fe6-base.gba", 0x279C54, (0x279C5A - 0x279C54)

	.global Pal_TilesetAnim_085C7A64_7
Pal_TilesetAnim_085C7A64_7: @ 08279C5A
	.incbin "fe6-base.gba", 0x279C5A, (0x279C60 - 0x279C5A)

	.global Pal_TilesetAnim_085C7A64_8
Pal_TilesetAnim_085C7A64_8: @ 08279C60
	.incbin "fe6-base.gba", 0x279C60, (0x279C66 - 0x279C60)

	.global Pal_TilesetAnim_085C7A64_9
Pal_TilesetAnim_085C7A64_9: @ 08279C66
	.incbin "fe6-base.gba", 0x279C66, (0x279C6E - 0x279C66)

	.global Pal_TilesetAnim_085C7A64_10
Pal_TilesetAnim_085C7A64_10: @ 08279C6E
	.incbin "fe6-base.gba", 0x279C6E, (0x279C74 - 0x279C6E)

	.global Pal_TilesetAnim_085C7A64_11
Pal_TilesetAnim_085C7A64_11: @ 08279C74
	.incbin "fe6-base.gba", 0x279C74, (0x279C7C - 0x279C74)

	.global Pal_TilesetAnim_085C7ADC_0
Pal_TilesetAnim_085C7ADC_0: @ 08279C7C
	.incbin "fe6-base.gba", 0x279C7C, (0x279C84 - 0x279C7C)

	.global Pal_TilesetAnim_085C7ADC_1
Pal_TilesetAnim_085C7ADC_1: @ 08279C84
	.incbin "fe6-base.gba", 0x279C84, (0x279C8C - 0x279C84)

	.global Pal_TilesetAnim_085C7ADC_2
Pal_TilesetAnim_085C7ADC_2: @ 08279C8C
	.incbin "fe6-base.gba", 0x279C8C, (0x279C94 - 0x279C8C)

	.global Pal_TilesetAnim_085C7ADC_3
Pal_TilesetAnim_085C7ADC_3: @ 08279C94
	.incbin "fe6-base.gba", 0x279C94, (0x279C9C - 0x279C94)

	.global Pal_TilesetAnim_085C7ADC_4
Pal_TilesetAnim_085C7ADC_4: @ 08279C9C
	.incbin "fe6-base.gba", 0x279C9C, (0x279CA4 - 0x279C9C)

	.global Pal_TilesetAnim_085C7ADC_5
Pal_TilesetAnim_085C7ADC_5: @ 08279CA4
	.incbin "fe6-base.gba", 0x279CA4, (0x279CAC - 0x279CA4)

	.global Pal_TilesetAnim_085C7ADC_6
Pal_TilesetAnim_085C7ADC_6: @ 08279CAC
	.incbin "fe6-base.gba", 0x279CAC, (0x279CB4 - 0x279CAC)

	.global Pal_TilesetAnim_085C7ADC_7
Pal_TilesetAnim_085C7ADC_7: @ 08279CB4
	.incbin "fe6-base.gba", 0x279CB4, (0x279CBC - 0x279CB4)

	.global Pal_TilesetAnim_085C7ADC_8
Pal_TilesetAnim_085C7ADC_8: @ 08279CBC
	.incbin "fe6-base.gba", 0x279CBC, (0x279CC4 - 0x279CBC)

	.global Pal_TilesetAnim_085C7ADC_9
Pal_TilesetAnim_085C7ADC_9: @ 08279CC4
	.incbin "fe6-base.gba", 0x279CC4, (0x279CCC - 0x279CC4)

	.global Pal_TilesetAnim_085C7ADC_10
Pal_TilesetAnim_085C7ADC_10: @ 08279CCC
	.incbin "fe6-base.gba", 0x279CCC, (0x279CD4 - 0x279CCC)

	.global Pal_TilesetAnim_085C7ADC_11
Pal_TilesetAnim_085C7ADC_11: @ 08279CD4
	.incbin "fe6-base.gba", 0x279CD4, (0x279CDC - 0x279CD4)

	.global Pal_TilesetAnim_085C7ADC_12
Pal_TilesetAnim_085C7ADC_12: @ 08279CDC
	.incbin "fe6-base.gba", 0x279CDC, (0x279CE4 - 0x279CDC)

	.global Pal_TilesetAnim_085C7ADC_13
Pal_TilesetAnim_085C7ADC_13: @ 08279CE4
	.incbin "fe6-base.gba", 0x279CE4, (0x279CEC - 0x279CE4)

	.global Pal_TilesetAnim_085C7ADC_14
Pal_TilesetAnim_085C7ADC_14: @ 08279CEC
	.incbin "fe6-base.gba", 0x279CEC, (0x279CF4 - 0x279CEC)

	.global Pal_TilesetAnim_085C7B5C_0
Pal_TilesetAnim_085C7B5C_0: @ 08279CF4
	.incbin "fe6-base.gba", 0x279CF4, (0x279CFC - 0x279CF4)

	.global Pal_TilesetAnim_085C7B5C_1
Pal_TilesetAnim_085C7B5C_1: @ 08279CFC
	.incbin "fe6-base.gba", 0x279CFC, (0x279D04 - 0x279CFC)

	.global Pal_TilesetAnim_085C7B5C_2
Pal_TilesetAnim_085C7B5C_2: @ 08279D04
	.incbin "fe6-base.gba", 0x279D04, (0x279D0C - 0x279D04)

	.global Pal_TilesetAnim_085C7B5C_3
Pal_TilesetAnim_085C7B5C_3: @ 08279D0C
	.incbin "fe6-base.gba", 0x279D0C, (0x279D14 - 0x279D0C)

	.global Pal_TilesetAnim_085C7B5C_4
Pal_TilesetAnim_085C7B5C_4: @ 08279D14
	.incbin "fe6-base.gba", 0x279D14, (0x279D1C - 0x279D14)

	.global Pal_TilesetAnim_085C7B5C_5
Pal_TilesetAnim_085C7B5C_5: @ 08279D1C
	.incbin "fe6-base.gba", 0x279D1C, (0x2D80B0 - 0x279D1C)

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
