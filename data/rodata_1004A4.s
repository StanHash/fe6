
	.section .rodata

	.global Img_SystemObjects
Img_SystemObjects: @ 081004A4
	.incbin "fe6-base.gba", 0x1004A4, (0x100928 - 0x1004A4) @ length: 0484

	.global Pal_SystemObjects
Pal_SystemObjects: @ 08100928
	.incbin "fe6-base.gba", 0x100928, (0x100968 - 0x100928) @ length: 0040

	.global Pal_UnitSprites
Pal_UnitSprites: @ 08100968
	.incbin "fe6-base.gba", 0x100968, (0x1009E8 - 0x100968) @ length: 0080

	.global Pal_UnitSpritesPurple
Pal_UnitSpritesPurple: @ 081009E8
	.incbin "fe6-base.gba", 0x1009E8, (0x100A08 - 0x1009E8) @ length: 0020

	.global Pal_Text
Pal_Text: @ 08100A08
	.incbin "fe6-base.gba", 0x100A08, (0x100A48 - 0x100A08) @ length: 0040

	.global Pal_08100A48
Pal_08100A48: @ 08100A48
	.incbin "fe6-base.gba", 0x100A48, (0x100A68 - 0x100A48) @ length: 0020

	.global Pal_GreenTextColors
Pal_GreenTextColors: @ 08100A68
	.incbin "fe6-base.gba", 0x100A68, (0x100A88 - 0x100A68) @ length: 0020

	.global Img_PhaseChangePlayer
Img_PhaseChangePlayer: @ 08100A88
	.incbin "fe6-base.gba", 0x100A88, (0x100F04 - 0x100A88) @ length: 047C

	.global Pal_PhaseChangePlayer
Pal_PhaseChangePlayer: @ 08100F04
	.incbin "fe6-base.gba", 0x100F04, (0x100F24 - 0x100F04) @ length: 0020

	.global Img_PhaseChangeEnemy
Img_PhaseChangeEnemy: @ 08100F24
	.incbin "fe6-base.gba", 0x100F24, (0x10137C - 0x100F24) @ length: 0458

	.global Pal_PhaseChangeEnemy
Pal_PhaseChangeEnemy: @ 0810137C
	.incbin "fe6-base.gba", 0x10137C, (0x10139C - 0x10137C) @ length: 0020

	.global Img_PhaseChangeOther
Img_PhaseChangeOther: @ 0810139C
	.incbin "fe6-base.gba", 0x10139C, (0x1017F4 - 0x10139C) @ length: 0458

	.global Pal_PhaseChangeOther
Pal_PhaseChangeOther: @ 081017F4
	.incbin "fe6-base.gba", 0x1017F4, (0x101814 - 0x1017F4) @ length: 0020

	.global Img_PhaseChangeSquares
Img_PhaseChangeSquares: @ 08101814
	.incbin "fe6-base.gba", 0x101814, (0x101974 - 0x101814) @ length: 0160

	.global Tsa_Unk_08101974
Tsa_Unk_08101974: @ 08101974
	.incbin "fe6-base.gba", 0x101974, (0x101A2C - 0x101974) @ length: 00B8

	.global Tsa_Unk_08101A2C
Tsa_Unk_08101A2C: @ 08101A2C
	.incbin "fe6-base.gba", 0x101A2C, (0x101AE4 - 0x101A2C) @ length: 00B8

	.global Img_BattlePreviewFrame
Img_BattlePreviewFrame: @ 08101AE4
	.incbin "fe6-base.gba", 0x101AE4, (0x101DD4 - 0x101AE4) @ length: 02F0

	.global Pal_BattlePreviewFrame_Blue
Pal_BattlePreviewFrame_Blue: @ 08101DD4
	.incbin "fe6-base.gba", 0x101DD4, (0x101DF4 - 0x101DD4) @ length: 0020

	.global Pal_BattlePreviewFrame_Red
Pal_BattlePreviewFrame_Red: @ 08101DF4
	.incbin "fe6-base.gba", 0x101DF4, (0x101E14 - 0x101DF4) @ length: 0020

	.global Pal_BattlePreviewFrame_Green
Pal_BattlePreviewFrame_Green: @ 08101E14
	.incbin "fe6-base.gba", 0x101E14, (0x101E34 - 0x101E14) @ length: 0020

	.global Pal_BattlePreviewFrame_Purple
Pal_BattlePreviewFrame_Purple: @ 08101E34
	.incbin "fe6-base.gba", 0x101E34, (0x101E54 - 0x101E34) @ length: 0020

	.global Tsa_BattlePreviewFrame_Short
Tsa_BattlePreviewFrame_Short: @ 08101E54
	.incbin "fe6-base.gba", 0x101E54, (0x101F98 - 0x101E54) @ length: 0144

	.global Tsa_BattlePreviewFrame_Long
Tsa_BattlePreviewFrame_Long: @ 08101F98
	.incbin "fe6-base.gba", 0x101F98, (0x10212C - 0x101F98) @ length: 0194

	.global Img_BattlePreviewMultipliers
Img_BattlePreviewMultipliers: @ 0810212C
	.incbin "fe6-base.gba", 0x10212C, (0x1021D8 - 0x10212C) @ length: 00AC

	.global Pal_BattlePreviewMultipliers
Pal_BattlePreviewMultipliers: @ 081021D8
	.incbin "fe6-base.gba", 0x1021D8, (0x1022AC - 0x1021D8) @ length: 00D4

	.global Tsa_UnitPanelHeader
Tsa_UnitPanelHeader: @ 081022AC
	.incbin "fe6-base.gba", 0x1022AC, (0x1022FC - 0x1022AC) @ length: 0050

	.global Tsa_Unk_081022FC
Tsa_Unk_081022FC: @ 081022FC
	.incbin "fe6-base.gba", 0x1022FC, (0x102450 - 0x1022FC) @ length: 0154

	.global SpriteAnim_08102450
SpriteAnim_08102450: @ 08102450
	.incbin "fe6-base.gba", 0x102450, (0x1025A8 - 0x102450) @ length: 0158

	.global SpriteAnim_GasTrapVertical
SpriteAnim_GasTrapVertical: @ 081025A8
	.incbin "fe6-base.gba", 0x1025A8, (0x10284C - 0x1025A8) @ length: 02A4

	.global SpriteAnim_GasTrapHorizontal
SpriteAnim_GasTrapHorizontal: @ 0810284C
	.incbin "fe6-base.gba", 0x10284C, (0x102AC0 - 0x10284C) @ length: 0274

	.global Img_GasTrapVertical
Img_GasTrapVertical: @ 08102AC0
	.incbin "fe6-base.gba", 0x102AC0, (0x1030A8 - 0x102AC0) @ length: 05E8

	.global Img_GasTrapHorizontal
Img_GasTrapHorizontal: @ 081030A8
	.incbin "fe6-base.gba", 0x1030A8, (0x10361C - 0x1030A8) @ length: 0574

	.global Pal_GasTrap
Pal_GasTrap: @ 0810361C
	.incbin "fe6-base.gba", 0x10361C, (0x10363C - 0x10361C) @ length: 0020

	.global Pal_ArrowTrap
Pal_ArrowTrap: @ 0810363C
	.incbin "fe6-base.gba", 0x10363C, (0x10365C - 0x10363C) @ length: 0020

	.global Img_ArrowTrap
Img_ArrowTrap: @ 0810365C
	.incbin "fe6-base.gba", 0x10365C, (0x103934 - 0x10365C) @ length: 02D8

	.global SpriteAnim_ArrowTrap
SpriteAnim_ArrowTrap: @ 08103934
	.incbin "fe6-base.gba", 0x103934, (0x103EF0 - 0x103934) @ length: 05BC

	.global Img_FireTrap
Img_FireTrap: @ 08103EF0
	.incbin "fe6-base.gba", 0x103EF0, (0x104374 - 0x103EF0) @ length: 0484

	.global Pal_FireTrap
Pal_FireTrap: @ 08104374
	.incbin "fe6-base.gba", 0x104374, (0x104394 - 0x104374) @ length: 0020

	.global SpriteAnim_FireTrap
SpriteAnim_FireTrap: @ 08104394
	.incbin "fe6-base.gba", 0x104394, (0x104440 - 0x104394) @ length: 00AC

	.global Img_PikeTrap
Img_PikeTrap: @ 08104440
	.incbin "fe6-base.gba", 0x104440, (0x1046C0 - 0x104440) @ length: 0280

	.global SpriteAnim_PikeTrap
SpriteAnim_PikeTrap: @ 081046C0
	.incbin "fe6-base.gba", 0x1046C0, (0x1048D4 - 0x1046C0) @ length: 0214

	.global Pal_PikeTrap
Pal_PikeTrap: @ 081048D4
	.incbin "fe6-base.gba", 0x1048D4, (0x105034 - 0x1048D4) @ length: 0760

	.global Img_SandstormParticles
Img_SandstormParticles: @ 08105034
	.incbin "fe6-base.gba", 0x105034, (0x1050BC - 0x105034) @ length: 0088

	.global Img_SnowstormParticles
Img_SnowstormParticles: @ 081050BC
	.incbin "fe6-base.gba", 0x1050BC, (0x105154 - 0x1050BC) @ length: 0098

	.global Img_FlamesParticles
Img_FlamesParticles: @ 08105154
	.incbin "fe6-base.gba", 0x105154, (0x105194 - 0x105154) @ length: 0040

	.global Pal_FlamesParticles
Pal_FlamesParticles: @ 08105194
	.incbin "fe6-base.gba", 0x105194, (0x1051D4 - 0x105194) @ length: 0040

	.global Img_CloudWeather
Img_CloudWeather: @ 081051D4
	.incbin "fe6-base.gba", 0x1051D4, (0x1056F0 - 0x1051D4) @ length: 051C

	.global Pal_CloudWeather
Pal_CloudWeather: @ 081056F0
	.incbin "fe6-base.gba", 0x1056F0, (0x105710 - 0x1056F0) @ length: 0020
