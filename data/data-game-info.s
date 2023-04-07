    .data

    .global MoveTable_BigFootie
MoveTable_BigFootie: @ 0860C648
    .incbin "fe6-base.gba", 0x60C648, (0x60C67B - 0x60C648) @ length: 0033

    .global MoveTable_Footie
MoveTable_Footie: @ 0860C67B
    .incbin "fe6-base.gba", 0x60C67B, (0x60C6AE - 0x60C67B) @ length: 0033

    .global MoveTable_Armor
MoveTable_Armor: @ 0860C6AE
    .incbin "fe6-base.gba", 0x60C6AE, (0x60C6E1 - 0x60C6AE) @ length: 0033

    .global MoveTable_Fighter
MoveTable_Fighter: @ 0860C6E1
    .incbin "fe6-base.gba", 0x60C6E1, (0x60C714 - 0x60C6E1) @ length: 0033

    .global MoveTable_Berserker
MoveTable_Berserker: @ 0860C714
    .incbin "fe6-base.gba", 0x60C714, (0x60C747 - 0x60C714) @ length: 0033

    .global MoveTable_Brigand
MoveTable_Brigand: @ 0860C747
    .incbin "fe6-base.gba", 0x60C747, (0x60C77A - 0x60C747) @ length: 0033

    .global MoveTable_Pirate
MoveTable_Pirate: @ 0860C77A
    .incbin "fe6-base.gba", 0x60C77A, (0x60C7AD - 0x60C77A) @ length: 0033

    .global MoveTable_Thief
MoveTable_Thief: @ 0860C7AD
    .incbin "fe6-base.gba", 0x60C7AD, (0x60C7E0 - 0x60C7AD) @ length: 0033

    .global MoveTable_Mages
MoveTable_Mages: @ 0860C7E0
    .incbin "fe6-base.gba", 0x60C7E0, (0x60C813 - 0x60C7E0) @ length: 0033

    .global MoveTable_Civilian
MoveTable_Civilian: @ 0860C813
    .incbin "fe6-base.gba", 0x60C813, (0x60C846 - 0x60C813) @ length: 0033

    .global MoveTable_Horsie
MoveTable_Horsie: @ 0860C846
    .incbin "fe6-base.gba", 0x60C846, (0x60C879 - 0x60C846) @ length: 0033

    .global MoveTable_BigHorsie
MoveTable_BigHorsie: @ 0860C879
    .incbin "fe6-base.gba", 0x60C879, (0x60C8AC - 0x60C879) @ length: 0033

    .global MoveTable_Nomad
MoveTable_Nomad: @ 0860C8AC
    .incbin "fe6-base.gba", 0x60C8AC, (0x60C8DF - 0x60C8AC) @ length: 0033

    .global MoveTable_NomadTrooper
MoveTable_NomadTrooper: @ 0860C8DF
    .incbin "fe6-base.gba", 0x60C8DF, (0x60C912 - 0x60C8DF) @ length: 0033

    .global MoveTable_Flying
MoveTable_Flying: @ 0860C912
    .incbin "fe6-base.gba", 0x60C912, (0x60C945 - 0x60C912) @ length: 0033

    .global MoveTable_Dragon
MoveTable_Dragon: @ 0860C945
    .incbin "fe6-base.gba", 0x60C945, (0x60C978 - 0x60C945) @ length: 0033

    .global TerrainAvoTable_Default
TerrainAvoTable_Default: @ 0860C978
    .incbin "fe6-base.gba", 0x60C978, (0x60C9AB - 0x60C978) @ length: 0033

    .global TerrainDefTable_Default
TerrainDefTable_Default: @ 0860C9AB
    .incbin "fe6-base.gba", 0x60C9AB, (0x60C9DE - 0x60C9AB) @ length: 0033

    .global TerrainResTable_Default
TerrainResTable_Default: @ 0860C9DE
    .incbin "fe6-base.gba", 0x60C9DE, (0x60CA11 - 0x60C9DE) @ length: 0033

    .global TerrainAvoTable_Flying
TerrainAvoTable_Flying: @ 0860CA11
    .incbin "fe6-base.gba", 0x60CA11, (0x60CA44 - 0x60CA11) @ length: 0033

    .global TerrainDefTable_Flying
TerrainDefTable_Flying: @ 0860CA44
    .incbin "fe6-base.gba", 0x60CA44, (0x60CA77 - 0x60CA44) @ length: 0033

    .global TerrainResTable_Flying
TerrainResTable_Flying: @ 0860CA77
    .incbin "fe6-base.gba", 0x60CA77, (0x60CAAA - 0x60CA77) @ length: 0033

    .global gUnk_Jinfo44_Brigand
gUnk_Jinfo44_Brigand: @ 0860CAAA
    .incbin "fe6-base.gba", 0x60CAAA, (0x60CADD - 0x60CAAA) @ length: 0033

    .global gUnk_Jinfo44_Pirate
gUnk_Jinfo44_Pirate: @ 0860CADD
    .incbin "fe6-base.gba", 0x60CADD, (0x60CB10 - 0x60CADD) @ length: 0033

    .global gUnk_Jinfo44_Berserker
gUnk_Jinfo44_Berserker: @ 0860CB10
    .incbin "fe6-base.gba", 0x60CB10, (0x60CB43 - 0x60CB10) @ length: 0033

    .global gUnk_Jinfo44_Priests
gUnk_Jinfo44_Priests: @ 0860CB43
    .incbin "fe6-base.gba", 0x60CB43, (0x60CB76 - 0x60CB43) @ length: 0033

    .global gUnk_Jinfo44_King
gUnk_Jinfo44_King: @ 0860CB76
    .incbin "fe6-base.gba", 0x60CB76, (0x60CBA9 - 0x60CB76) @ length: 0033

    .global TerrainHealAmountTable
TerrainHealAmountTable: @ 0860CBA9
    .incbin "fe6-base.gba", 0x60CBA9, (0x60CBDC - 0x60CBA9) @ length: 0033

    .global TerrainHealsStatusTable
TerrainHealsStatusTable: @ 0860CBDC
    .incbin "fe6-base.gba", 0x60CBDC, (0x60CC0F - 0x60CBDC) @ length: 0033

    .global gUnk_0860CC0F
gUnk_0860CC0F: @ 0860CC0F
    .incbin "fe6-base.gba", 0x60CC0F, (0x60CC42 - 0x60CC0F) @ length: 0033

    .global gUnk_0860CC42
gUnk_0860CC42: @ 0860CC42
    .incbin "fe6-base.gba", 0x60CC42, (0x60CC75 - 0x60CC42) @ length: 0033

    .global gUnk_0860CC75
gUnk_0860CC75: @ 0860CC75
    .incbin "fe6-base.gba", 0x60CC75, (0x60CCA8 - 0x60CC75) @ length: 0033

    .global gUnk_0860CCA8
gUnk_0860CCA8: @ 0860CCA8
    .incbin "fe6-base.gba", 0x60CCA8, (0x60CCDB - 0x60CCA8) @ length: 0033

    .global gUnk_0860CCDB
gUnk_0860CCDB: @ 0860CCDB
    .incbin "fe6-base.gba", 0x60CCDB, (0x60CD0E - 0x60CCDB) @ length: 0033

    .global gUnk_0860CD0E
gUnk_0860CD0E: @ 0860CD0E
    .incbin "fe6-base.gba", 0x60CD0E, (0x60CD41 - 0x60CD0E) @ length: 0033

    .global gUnk_0860CD41
gUnk_0860CD41: @ 0860CD41
    .incbin "fe6-base.gba", 0x60CD41, (0x60CD74 - 0x60CD41) @ length: 0033

    .global gUnk_0860CD74
gUnk_0860CD74: @ 0860CD74
    .incbin "fe6-base.gba", 0x60CD74, (0x60CDA7 - 0x60CD74) @ length: 0033

    .global gUnk_0860CDA7
gUnk_0860CDA7: @ 0860CDA7
    .incbin "fe6-base.gba", 0x60CDA7, (0x60CDDA - 0x60CDA7) @ length: 0033

    .global gUnk_0860CDDA
gUnk_0860CDDA: @ 0860CDDA
    .incbin "fe6-base.gba", 0x60CDDA, (0x60CE0D - 0x60CDDA) @ length: 0033

    .global gUnk_0860CE0D
gUnk_0860CE0D: @ 0860CE0D
    .incbin "fe6-base.gba", 0x60CE0D, (0x60CE40 - 0x60CE0D) @ length: 0033

    .global gUnk_0860CE40
gUnk_0860CE40: @ 0860CE40
    .incbin "fe6-base.gba", 0x60CE40, (0x60CE73 - 0x60CE40) @ length: 0033

    .global gUnk_0860CE73
gUnk_0860CE73: @ 0860CE73
    .incbin "fe6-base.gba", 0x60CE73, (0x60CEA6 - 0x60CE73) @ length: 0033

    .global gUnk_0860CEA6
gUnk_0860CEA6: @ 0860CEA6
    .incbin "fe6-base.gba", 0x60CEA6, (0x60CED9 - 0x60CEA6) @ length: 0033

    .global gUnk_0860CED9
gUnk_0860CED9: @ 0860CED9
    .incbin "fe6-base.gba", 0x60CED9, (0x60CF0C - 0x60CED9) @ length: 0033

    .global gUnk_0860CF0C
gUnk_0860CF0C: @ 0860CF0C
    .incbin "fe6-base.gba", 0x60CF0C, (0x60CF3F - 0x60CF0C) @ length: 0033

    .global gUnk_0860CF3F
gUnk_0860CF3F: @ 0860CF3F
    .incbin "fe6-base.gba", 0x60CF3F, (0x60CF72 - 0x60CF3F) @ length: 0033

    .global gUnk_0860CF72
gUnk_0860CF72: @ 0860CF72
    .incbin "fe6-base.gba", 0x60CF72, (0x60CFA5 - 0x60CF72) @ length: 0033

    .global gUnk_0860CFA5
gUnk_0860CFA5: @ 0860CFA5
    .incbin "fe6-base.gba", 0x60CFA5, (0x60CFD8 - 0x60CFA5) @ length: 0033

    .global gUnk_0860CFD8
gUnk_0860CFD8: @ 0860CFD8
    .incbin "fe6-base.gba", 0x60CFD8, (0x60D00C - 0x60CFD8) @ length: 0034

    .global TerrainNameStringTable
TerrainNameStringTable: @ 0860D00C
    .incbin "fe6-base.gba", 0x60D00C, (0x66074C - 0x60D00C) @ length: 53740

    .global FaceInfoTable
FaceInfoTable: @ 0866074C
    .incbin "fe6-base.gba", 0x66074C, (0x6615BC - 0x66074C) @ length: 0E70

    .global JList_HorseEffectiveness
JList_HorseEffectiveness: @ 086615BC
    .incbin "fe6-base.gba", 0x6615BC, (0x6615C1 - 0x6615BC) @ length: 0005

    .global JList_ArmorEffectiveness
JList_ArmorEffectiveness: @ 086615C1
    .incbin "fe6-base.gba", 0x6615C1, (0x6615C6 - 0x6615C1) @ length: 0005

    .global JList_RapierEffectiveness
JList_RapierEffectiveness: @ 086615C6
    .incbin "fe6-base.gba", 0x6615C6, (0x6615CF - 0x6615C6) @ length: 0009

    .global JList_DragonEffectiveness
JList_DragonEffectiveness: @ 086615CF
    .incbin "fe6-base.gba", 0x6615CF, (0x6615D4 - 0x6615CF) @ length: 0005

    .global JList_WyrmEffectiveness
JList_WyrmEffectiveness: @ 086615D4
    .incbin "fe6-base.gba", 0x6615D4, (0x6615DB - 0x6615D4) @ length: 0007

    .global JList_BowEffectiveness
JList_BowEffectiveness: @ 086615DB
    .incbin "fe6-base.gba", 0x6615DB, (0x6615E2 - 0x6615DB) @ length: 0007

    .global JList_HeroCrestPromotes
JList_HeroCrestPromotes: @ 086615E2
    .incbin "fe6-base.gba", 0x6615E2, (0x6615EA - 0x6615E2) @ length: 0008

    .global JList_KnightCrestPromotes
JList_KnightCrestPromotes: @ 086615EA
    .incbin "fe6-base.gba", 0x6615EA, (0x6615EF - 0x6615EA) @ length: 0005

    .global JList_OrionBoltPromotes
JList_OrionBoltPromotes: @ 086615EF
    .incbin "fe6-base.gba", 0x6615EF, (0x6615F4 - 0x6615EF) @ length: 0005

    .global JList_ElysianWhipPromotes
JList_ElysianWhipPromotes: @ 086615F4
    .incbin "fe6-base.gba", 0x6615F4, (0x6615F8 - 0x6615F4) @ length: 0004

    .global JList_GuidingRingPromotes
JList_GuidingRingPromotes: @ 086615F8
    .incbin "fe6-base.gba", 0x6615F8, (0x661600 - 0x6615F8) @ length: 0008

    .global gPidDebugTable
gPidDebugTable: @ 08661600
    .incbin "fe6-base.gba", 0x661600, (0x662098 - 0x661600) @ length: 0A98

    .global SupportInfo_Roy
SupportInfo_Roy: @ 08662098
    .incbin "fe6-base.gba", 0x662098, (0x6620B8 - 0x662098) @ length: 0020

    .global SupportInfo_Clarine
SupportInfo_Clarine: @ 086620B8
    .incbin "fe6-base.gba", 0x6620B8, (0x6620D8 - 0x6620B8) @ length: 0020

    .global SupportInfo_Fae
SupportInfo_Fae: @ 086620D8
    .incbin "fe6-base.gba", 0x6620D8, (0x6620F8 - 0x6620D8) @ length: 0020

    .global SupportInfo_Sin
SupportInfo_Sin: @ 086620F8
    .incbin "fe6-base.gba", 0x6620F8, (0x662118 - 0x6620F8) @ length: 0020

    .global SupportInfo_Sue
SupportInfo_Sue: @ 08662118
    .incbin "fe6-base.gba", 0x662118, (0x662138 - 0x662118) @ length: 0020

    .global SupportInfo_Dayan
SupportInfo_Dayan: @ 08662138
    .incbin "fe6-base.gba", 0x662138, (0x662158 - 0x662138) @ length: 0020

    .global SupportInfo_Barthe
SupportInfo_Barthe: @ 08662158
    .incbin "fe6-base.gba", 0x662158, (0x662178 - 0x662158) @ length: 0020

    .global SupportInfo_Bors
SupportInfo_Bors: @ 08662178
    .incbin "fe6-base.gba", 0x662178, (0x662198 - 0x662178) @ length: 0020

    .global SupportInfo_Gwendolyn
SupportInfo_Gwendolyn: @ 08662198
    .incbin "fe6-base.gba", 0x662198, (0x6621B8 - 0x662198) @ length: 0020

    .global SupportInfo_Douglas
SupportInfo_Douglas: @ 086621B8
    .incbin "fe6-base.gba", 0x6621B8, (0x6621D8 - 0x6621B8) @ length: 0020

    .global SupportInfo_Wolt
SupportInfo_Wolt: @ 086621D8
    .incbin "fe6-base.gba", 0x6621D8, (0x6621F8 - 0x6621D8) @ length: 0020

    .global SupportInfo_Dorothy
SupportInfo_Dorothy: @ 086621F8
    .incbin "fe6-base.gba", 0x6621F8, (0x662218 - 0x6621F8) @ length: 0020

    .global SupportInfo_Klein
SupportInfo_Klein: @ 08662218
    .incbin "fe6-base.gba", 0x662218, (0x662238 - 0x662218) @ length: 0020

    .global SupportInfo_Saul
SupportInfo_Saul: @ 08662238
    .incbin "fe6-base.gba", 0x662238, (0x662258 - 0x662238) @ length: 0020

    .global SupportInfo_Elen
SupportInfo_Elen: @ 08662258
    .incbin "fe6-base.gba", 0x662258, (0x662278 - 0x662258) @ length: 0020

    .global SupportInfo_Yoder
SupportInfo_Yoder: @ 08662278
    .incbin "fe6-base.gba", 0x662278, (0x662298 - 0x662278) @ length: 0020

    .global SupportInfo_Chad
SupportInfo_Chad: @ 08662298
    .incbin "fe6-base.gba", 0x662298, (0x6622B8 - 0x662298) @ length: 0020

    .global SupportInfo_Karel
SupportInfo_Karel: @ 086622B8
    .incbin "fe6-base.gba", 0x6622B8, (0x6622D8 - 0x6622B8) @ length: 0020

    .global SupportInfo_Fir
SupportInfo_Fir: @ 086622D8
    .incbin "fe6-base.gba", 0x6622D8, (0x6622F8 - 0x6622D8) @ length: 0020

    .global SupportInfo_Rutger
SupportInfo_Rutger: @ 086622F8
    .incbin "fe6-base.gba", 0x6622F8, (0x662318 - 0x6622F8) @ length: 0020

    .global SupportInfo_Dieck
SupportInfo_Dieck: @ 08662318
    .incbin "fe6-base.gba", 0x662318, (0x662338 - 0x662318) @ length: 0020

    .global SupportInfo_Ogier
SupportInfo_Ogier: @ 08662338
    .incbin "fe6-base.gba", 0x662338, (0x662358 - 0x662338) @ length: 0020

    .global SupportInfo_Garret
SupportInfo_Garret: @ 08662358
    .incbin "fe6-base.gba", 0x662358, (0x662378 - 0x662358) @ length: 0020

    .global SupportInfo_Alen
SupportInfo_Alen: @ 08662378
    .incbin "fe6-base.gba", 0x662378, (0x662398 - 0x662378) @ length: 0020

    .global SupportInfo_Lance
SupportInfo_Lance: @ 08662398
    .incbin "fe6-base.gba", 0x662398, (0x6623B8 - 0x662398) @ length: 0020

    .global SupportInfo_Perceval
SupportInfo_Perceval: @ 086623B8
    .incbin "fe6-base.gba", 0x6623B8, (0x6623D8 - 0x6623B8) @ length: 0020

    .global SupportInfo_Igrene
SupportInfo_Igrene: @ 086623D8
    .incbin "fe6-base.gba", 0x6623D8, (0x6623F8 - 0x6623D8) @ length: 0020

    .global SupportInfo_Marcus
SupportInfo_Marcus: @ 086623F8
    .incbin "fe6-base.gba", 0x6623F8, (0x662418 - 0x6623F8) @ length: 0020

    .global SupportInfo_Astolfo
SupportInfo_Astolfo: @ 08662418
    .incbin "fe6-base.gba", 0x662418, (0x662438 - 0x662418) @ length: 0020

    .global SupportInfo_Ward
SupportInfo_Ward: @ 08662438
    .incbin "fe6-base.gba", 0x662438, (0x662458 - 0x662438) @ length: 0020

    .global SupportInfo_Lot
SupportInfo_Lot: @ 08662458
    .incbin "fe6-base.gba", 0x662458, (0x662478 - 0x662458) @ length: 0020

    .global SupportInfo_Bartre
SupportInfo_Bartre: @ 08662478
    .incbin "fe6-base.gba", 0x662478, (0x662498 - 0x662478) @ length: 0020

    .global SupportInfo_Lugh
SupportInfo_Lugh: @ 08662498
    .incbin "fe6-base.gba", 0x662498, (0x6624B8 - 0x662498) @ length: 0020

    .global SupportInfo_Lilina
SupportInfo_Lilina: @ 086624B8
    .incbin "fe6-base.gba", 0x6624B8, (0x6624D8 - 0x6624B8) @ length: 0020

    .global SupportInfo_Hugh
SupportInfo_Hugh: @ 086624D8
    .incbin "fe6-base.gba", 0x6624D8, (0x6624F8 - 0x6624D8) @ length: 0020

    .global SupportInfo_Niime
SupportInfo_Niime: @ 086624F8
    .incbin "fe6-base.gba", 0x6624F8, (0x662518 - 0x6624F8) @ length: 0020

    .global SupportInfo_Raigh
SupportInfo_Raigh: @ 08662518
    .incbin "fe6-base.gba", 0x662518, (0x662538 - 0x662518) @ length: 0020

    .global SupportInfo_Larum
SupportInfo_Larum: @ 08662538
    .incbin "fe6-base.gba", 0x662538, (0x662558 - 0x662538) @ length: 0020

    .global SupportInfo_Juno
SupportInfo_Juno: @ 08662558
    .incbin "fe6-base.gba", 0x662558, (0x662578 - 0x662558) @ length: 0020

    .global SupportInfo_Thea
SupportInfo_Thea: @ 08662578
    .incbin "fe6-base.gba", 0x662578, (0x662598 - 0x662578) @ length: 0020

    .global SupportInfo_Shanna
SupportInfo_Shanna: @ 08662598
    .incbin "fe6-base.gba", 0x662598, (0x6625B8 - 0x662598) @ length: 0020

    .global SupportInfo_Zeiss
SupportInfo_Zeiss: @ 086625B8
    .incbin "fe6-base.gba", 0x6625B8, (0x6625D8 - 0x6625B8) @ length: 0020

    .global SupportInfo_Elffin
SupportInfo_Elffin: @ 086625D8
    .incbin "fe6-base.gba", 0x6625D8, (0x6625F8 - 0x6625D8) @ length: 0020

    .global SupportInfo_Cath
SupportInfo_Cath: @ 086625F8
    .incbin "fe6-base.gba", 0x6625F8, (0x662618 - 0x6625F8) @ length: 0020

    .global SupportInfo_Sophia
SupportInfo_Sophia: @ 08662618
    .incbin "fe6-base.gba", 0x662618, (0x662638 - 0x662618) @ length: 0020

    .global SupportInfo_Melady
SupportInfo_Melady: @ 08662638
    .incbin "fe6-base.gba", 0x662638, (0x662658 - 0x662638) @ length: 0020

    .global SupportInfo_Gonzalez
SupportInfo_Gonzalez: @ 08662658
    .incbin "fe6-base.gba", 0x662658, (0x662678 - 0x662658) @ length: 0020

    .global SupportInfo_Noah
SupportInfo_Noah: @ 08662678
    .incbin "fe6-base.gba", 0x662678, (0x662698 - 0x662678) @ length: 0020

    .global SupportInfo_Trec
SupportInfo_Trec: @ 08662698
    .incbin "fe6-base.gba", 0x662698, (0x6626B8 - 0x662698) @ length: 0020

    .global SupportInfo_Zelot
SupportInfo_Zelot: @ 086626B8
    .incbin "fe6-base.gba", 0x6626B8, (0x6626D8 - 0x6626B8) @ length: 0020

    .global SupportInfo_Echidna
SupportInfo_Echidna: @ 086626D8
    .incbin "fe6-base.gba", 0x6626D8, (0x6626F8 - 0x6626D8) @ length: 0020

    .global SupportInfo_Cecilia
SupportInfo_Cecilia: @ 086626F8
    .incbin "fe6-base.gba", 0x6626F8, (0x662718 - 0x6626F8) @ length: 0020

    .global SupportInfo_Geese
SupportInfo_Geese: @ 08662718
    .incbin "fe6-base.gba", 0x662718, (0x662738 - 0x662718) @ length: 0020

    .global ItemBonuses_Durandal
ItemBonuses_Durandal: @ 08662738
    .incbin "fe6-base.gba", 0x662738, (0x662744 - 0x662738) @ length: 000C

    .global ItemBonuses_BindingBlade
ItemBonuses_BindingBlade: @ 08662744
    .incbin "fe6-base.gba", 0x662744, (0x662750 - 0x662744) @ length: 000C

    .global ItemBonuses_Maltet
ItemBonuses_Maltet: @ 08662750
    .incbin "fe6-base.gba", 0x662750, (0x66275C - 0x662750) @ length: 000C

    .global ItemBonuses_Armads
ItemBonuses_Armads: @ 0866275C
    .incbin "fe6-base.gba", 0x66275C, (0x662768 - 0x66275C) @ length: 000C

    .global ItemBonuses_Mulagir
ItemBonuses_Mulagir: @ 08662768
    .incbin "fe6-base.gba", 0x662768, (0x662774 - 0x662768) @ length: 000C

    .global ItemBonuses_Forblaze
ItemBonuses_Forblaze: @ 08662774
    .incbin "fe6-base.gba", 0x662774, (0x662780 - 0x662774) @ length: 000C

    .global ItemBonuses_Aureola
ItemBonuses_Aureola: @ 08662780
    .incbin "fe6-base.gba", 0x662780, (0x66278C - 0x662780) @ length: 000C

    .global ItemBonuses_Apocalypse
ItemBonuses_Apocalypse: @ 0866278C
    .incbin "fe6-base.gba", 0x66278C, (0x662798 - 0x66278C) @ length: 000C

    .global ItemBonuses_Firestone
ItemBonuses_Firestone: @ 08662798
    .incbin "fe6-base.gba", 0x662798, (0x6627A4 - 0x662798) @ length: 000C

    .global ItemBonuses_Divinestone
ItemBonuses_Divinestone: @ 086627A4
    .incbin "fe6-base.gba", 0x6627A4, (0x6627B0 - 0x6627A4) @ length: 000C

    .global ItemBonuses_Demonstone
ItemBonuses_Demonstone: @ 086627B0
    .incbin "fe6-base.gba", 0x6627B0, (0x6627BC - 0x6627B0) @ length: 000C

    .global ItemBonuses_SecretBook
ItemBonuses_SecretBook: @ 086627BC
    .incbin "fe6-base.gba", 0x6627BC, (0x6627C8 - 0x6627BC) @ length: 000C

    .global ItemBonuses_GoddessIcon
ItemBonuses_GoddessIcon: @ 086627C8
    .incbin "fe6-base.gba", 0x6627C8, (0x6627D4 - 0x6627C8) @ length: 000C

    .global ItemBonuses_SeraphRobe
ItemBonuses_SeraphRobe: @ 086627D4
    .incbin "fe6-base.gba", 0x6627D4, (0x6627E0 - 0x6627D4) @ length: 000C

    .global ItemBonuses_Dracoshield
ItemBonuses_Dracoshield: @ 086627E0
    .incbin "fe6-base.gba", 0x6627E0, (0x6627EC - 0x6627E0) @ length: 000C

    .global ItemBonuses_EnergyRing
ItemBonuses_EnergyRing: @ 086627EC
    .incbin "fe6-base.gba", 0x6627EC, (0x6627F8 - 0x6627EC) @ length: 000C

    .global ItemBonuses_Speedwing
ItemBonuses_Speedwing: @ 086627F8
    .incbin "fe6-base.gba", 0x6627F8, (0x662804 - 0x6627F8) @ length: 000C

    .global ItemBonuses_Talisman
ItemBonuses_Talisman: @ 08662804
    .incbin "fe6-base.gba", 0x662804, (0x662810 - 0x662804) @ length: 000C

    .global ItemBonuses_Boots
ItemBonuses_Boots: @ 08662810
    .incbin "fe6-base.gba", 0x662810, (0x66281C - 0x662810) @ length: 000C

    .global ItemBonuses_BodyRing
ItemBonuses_BodyRing: @ 0866281C
    .incbin "fe6-base.gba", 0x66281C, (0x662828 - 0x66281C) @ length: 000C

    .global BanimInfo_Roy
BanimInfo_Roy: @ 08662828
    .incbin "fe6-base.gba", 0x662828, (0x662838 - 0x662828) @ length: 0010

    .global BanimInfo_Mercenary
BanimInfo_Mercenary: @ 08662838
    .incbin "fe6-base.gba", 0x662838, (0x662844 - 0x662838) @ length: 000C

    .global BanimInfo_Hero
BanimInfo_Hero: @ 08662844
    .incbin "fe6-base.gba", 0x662844, (0x66285C - 0x662844) @ length: 0018

    .global BanimInfo_Hero_F
BanimInfo_Hero_F: @ 0866285C
    .incbin "fe6-base.gba", 0x66285C, (0x662874 - 0x66285C) @ length: 0018

    .global BanimInfo_Myrmidon
BanimInfo_Myrmidon: @ 08662874
    .incbin "fe6-base.gba", 0x662874, (0x662880 - 0x662874) @ length: 000C

    .global BanimInfo_Myrmidon_F
BanimInfo_Myrmidon_F: @ 08662880
    .incbin "fe6-base.gba", 0x662880, (0x66288C - 0x662880) @ length: 000C

    .global BanimInfo_Swordmaster
BanimInfo_Swordmaster: @ 0866288C
    .incbin "fe6-base.gba", 0x66288C, (0x662898 - 0x66288C) @ length: 000C

    .global BanimInfo_Swordmaster_F
BanimInfo_Swordmaster_F: @ 08662898
    .incbin "fe6-base.gba", 0x662898, (0x6628A4 - 0x662898) @ length: 000C

    .global BanimInfo_Fighter
BanimInfo_Fighter: @ 086628A4
    .incbin "fe6-base.gba", 0x6628A4, (0x6628B8 - 0x6628A4) @ length: 0014

    .global BanimInfo_Warrior
BanimInfo_Warrior: @ 086628B8
    .incbin "fe6-base.gba", 0x6628B8, (0x6628D0 - 0x6628B8) @ length: 0018

    .global BanimInfo_Armor
BanimInfo_Armor: @ 086628D0
    .incbin "fe6-base.gba", 0x6628D0, (0x6628DC - 0x6628D0) @ length: 000C

    .global BanimInfo_Armor_F
BanimInfo_Armor_F: @ 086628DC
    .incbin "fe6-base.gba", 0x6628DC, (0x6628E8 - 0x6628DC) @ length: 000C

    .global BanimInfo_General
BanimInfo_General: @ 086628E8
    .incbin "fe6-base.gba", 0x6628E8, (0x662900 - 0x6628E8) @ length: 0018

    .global BanimInfo_General_F
BanimInfo_General_F: @ 08662900
    .incbin "fe6-base.gba", 0x662900, (0x662918 - 0x662900) @ length: 0018

    .global BanimInfo_Archer
BanimInfo_Archer: @ 08662918
    .incbin "fe6-base.gba", 0x662918, (0x662930 - 0x662918) @ length: 0018

    .global BanimInfo_Archer_F
BanimInfo_Archer_F: @ 08662930
    .incbin "fe6-base.gba", 0x662930, (0x662948 - 0x662930) @ length: 0018

    .global BanimInfo_Sniper
BanimInfo_Sniper: @ 08662948
    .incbin "fe6-base.gba", 0x662948, (0x662960 - 0x662948) @ length: 0018

    .global BanimInfo_Sniper_F
BanimInfo_Sniper_F: @ 08662960
    .incbin "fe6-base.gba", 0x662960, (0x662978 - 0x662960) @ length: 0018

    .global BanimInfo_Priest
BanimInfo_Priest: @ 08662978
    .incbin "fe6-base.gba", 0x662978, (0x662984 - 0x662978) @ length: 000C

    .global BanimInfo_Cleric
BanimInfo_Cleric: @ 08662984
    .incbin "fe6-base.gba", 0x662984, (0x662990 - 0x662984) @ length: 000C

    .global BanimInfo_Bishop
BanimInfo_Bishop: @ 08662990
    .incbin "fe6-base.gba", 0x662990, (0x6629A8 - 0x662990) @ length: 0018

    .global BanimInfo_Bishop_F
BanimInfo_Bishop_F: @ 086629A8
    .incbin "fe6-base.gba", 0x6629A8, (0x6629C0 - 0x6629A8) @ length: 0018

    .global BanimInfo_Mage
BanimInfo_Mage: @ 086629C0
    .incbin "fe6-base.gba", 0x6629C0, (0x6629D4 - 0x6629C0) @ length: 0014

    .global BanimInfo_Mage_F
BanimInfo_Mage_F: @ 086629D4
    .incbin "fe6-base.gba", 0x6629D4, (0x6629E8 - 0x6629D4) @ length: 0014

    .global BanimInfo_Sage
BanimInfo_Sage: @ 086629E8
    .incbin "fe6-base.gba", 0x6629E8, (0x662A00 - 0x6629E8) @ length: 0018

    .global BanimInfo_Sage_F
BanimInfo_Sage_F: @ 08662A00
    .incbin "fe6-base.gba", 0x662A00, (0x662A18 - 0x662A00) @ length: 0018

    .global BanimInfo_Shaman
BanimInfo_Shaman: @ 08662A18
    .incbin "fe6-base.gba", 0x662A18, (0x662A2C - 0x662A18) @ length: 0014

    .global BanimInfo_Shaman_F
BanimInfo_Shaman_F: @ 08662A2C
    .incbin "fe6-base.gba", 0x662A2C, (0x662A40 - 0x662A2C) @ length: 0014

    .global BanimInfo_Druid
BanimInfo_Druid: @ 08662A40
    .incbin "fe6-base.gba", 0x662A40, (0x662A58 - 0x662A40) @ length: 0018

    .global BanimInfo_Druid_F
BanimInfo_Druid_F: @ 08662A58
    .incbin "fe6-base.gba", 0x662A58, (0x662A70 - 0x662A58) @ length: 0018

    .global BanimInfo_Cavalier
BanimInfo_Cavalier: @ 08662A70
    .incbin "fe6-base.gba", 0x662A70, (0x662A80 - 0x662A70) @ length: 0010

    .global BanimInfo_Paladin
BanimInfo_Paladin: @ 08662A80
    .incbin "fe6-base.gba", 0x662A80, (0x662A94 - 0x662A80) @ length: 0014

    .global BanimInfo_Troubadour
BanimInfo_Troubadour: @ 08662A94
    .incbin "fe6-base.gba", 0x662A94, (0x662AA0 - 0x662A94) @ length: 000C

    .global BanimInfo_Valkyrie
BanimInfo_Valkyrie: @ 08662AA0
    .incbin "fe6-base.gba", 0x662AA0, (0x662AB8 - 0x662AA0) @ length: 0018

    .global BanimInfo_Nomad
BanimInfo_Nomad: @ 08662AB8
    .incbin "fe6-base.gba", 0x662AB8, (0x662AC4 - 0x662AB8) @ length: 000C

    .global BanimInfo_Nomad_F
BanimInfo_Nomad_F: @ 08662AC4
    .incbin "fe6-base.gba", 0x662AC4, (0x662AD0 - 0x662AC4) @ length: 000C

    .global BanimInfo_Nomadtrooper
BanimInfo_Nomadtrooper: @ 08662AD0
    .incbin "fe6-base.gba", 0x662AD0, (0x662AE0 - 0x662AD0) @ length: 0010

    .global BanimInfo_Nomadtrooper_F
BanimInfo_Nomadtrooper_F: @ 08662AE0
    .incbin "fe6-base.gba", 0x662AE0, (0x662AF0 - 0x662AE0) @ length: 0010

    .global BanimInfo_Pegasusknight
BanimInfo_Pegasusknight: @ 08662AF0
    .incbin "fe6-base.gba", 0x662AF0, (0x662AFC - 0x662AF0) @ length: 000C

    .global BanimInfo_Falconknight
BanimInfo_Falconknight: @ 08662AFC
    .incbin "fe6-base.gba", 0x662AFC, (0x662B0C - 0x662AFC) @ length: 0010

    .global BanimInfo_Wyvernrider
BanimInfo_Wyvernrider: @ 08662B0C
    .incbin "fe6-base.gba", 0x662B0C, (0x662B18 - 0x662B0C) @ length: 000C

    .global BanimInfo_Wyvernrider_F
BanimInfo_Wyvernrider_F: @ 08662B18
    .incbin "fe6-base.gba", 0x662B18, (0x662B24 - 0x662B18) @ length: 000C

    .global BanimInfo_Wyvernlord
BanimInfo_Wyvernlord: @ 08662B24
    .incbin "fe6-base.gba", 0x662B24, (0x662B34 - 0x662B24) @ length: 0010

    .global BanimInfo_Wyvernlord_F
BanimInfo_Wyvernlord_F: @ 08662B34
    .incbin "fe6-base.gba", 0x662B34, (0x662B44 - 0x662B34) @ length: 0010

    .global BanimInfo_Soldier
BanimInfo_Soldier: @ 08662B44
    .incbin "fe6-base.gba", 0x662B44, (0x662B50 - 0x662B44) @ length: 000C

    .global BanimInfo_Brigand
BanimInfo_Brigand: @ 08662B50
    .incbin "fe6-base.gba", 0x662B50, (0x662B64 - 0x662B50) @ length: 0014

    .global BanimInfo_Pirate
BanimInfo_Pirate: @ 08662B64
    .incbin "fe6-base.gba", 0x662B64, (0x662B78 - 0x662B64) @ length: 0014

    .global BanimInfo_Berserker
BanimInfo_Berserker: @ 08662B78
    .incbin "fe6-base.gba", 0x662B78, (0x662B8C - 0x662B78) @ length: 0014

    .global BanimInfo_Thief
BanimInfo_Thief: @ 08662B8C
    .incbin "fe6-base.gba", 0x662B8C, (0x662B98 - 0x662B8C) @ length: 000C

    .global BanimInfo_Thief_F
BanimInfo_Thief_F: @ 08662B98
    .incbin "fe6-base.gba", 0x662B98, (0x662BA4 - 0x662B98) @ length: 000C

    .global BanimInfo_Bard
BanimInfo_Bard: @ 08662BA4
    .incbin "fe6-base.gba", 0x662BA4, (0x662BAC - 0x662BA4) @ length: 0008

    .global BanimInfo_Dancer
BanimInfo_Dancer: @ 08662BAC
    .incbin "fe6-base.gba", 0x662BAC, (0x662BB4 - 0x662BAC) @ length: 0008

    .global BanimInfo_Manakete
BanimInfo_Manakete: @ 08662BB4
    .incbin "fe6-base.gba", 0x662BB4, (0x662BC0 - 0x662BB4) @ length: 000C

    .global BanimInfo_Manakete_F
BanimInfo_Manakete_F: @ 08662BC0
    .incbin "fe6-base.gba", 0x662BC0, (0x662BCC - 0x662BC0) @ length: 000C

    .global BanimInfo_Firedragon
BanimInfo_Firedragon: @ 08662BCC
    .incbin "fe6-base.gba", 0x662BCC, (0x662BDC - 0x662BCC) @ length: 0010

    .global BanimInfo_Divinedragon
BanimInfo_Divinedragon: @ 08662BDC
    .incbin "fe6-base.gba", 0x662BDC, (0x662BEC - 0x662BDC) @ length: 0010

    .global BanimInfo_Demondragon
BanimInfo_Demondragon: @ 08662BEC
    .incbin "fe6-base.gba", 0x662BEC, (0x662BF8 - 0x662BEC) @ length: 000C

    .global BanimInfo_King
BanimInfo_King: @ 08662BF8
    .incbin "fe6-base.gba", 0x662BF8, (0x662C04 - 0x662BF8) @ length: 000C

    .global BanimInfo_Roy_Promoted
BanimInfo_Roy_Promoted: @ 08662C04
    .incbin "fe6-base.gba", 0x662C04, (0x662C14 - 0x662C04) @ length: 0010

    .global UnitSpriteTable
UnitSpriteTable: @ 08662C14
    .incbin "fe6-base.gba", 0x662C14, (0x662E4C - 0x662C14) @ length: 0238

    .global gUnk_08662E4C
gUnk_08662E4C: @ 08662E4C
    .incbin "fe6-base.gba", 0x662E4C, (0x66350C - 0x662E4C) @ length: 06C0

    .global AffinityBonuses
AffinityBonuses: @ 0866350C
    .incbin "fe6-base.gba", 0x66350C, (0x66354C - 0x66350C) @ length: 0040

    .global gUnk_0866354C
gUnk_0866354C: @ 0866354C
    .incbin "fe6-base.gba", 0x66354C, (0x6637A4 - 0x66354C) @ length: 0258

    .global ChapterInfoTable
ChapterInfoTable: @ 086637A4
    .incbin "fe6-base.gba", 0x6637A4, (0x664398 - 0x6637A4) @ length: 0BF4

    .global ChapterAssets
ChapterAssets: @ 08664398
    .incbin "fe6-base.gba", 0x664398, (0x66472C - 0x664398) @ length: 0394
