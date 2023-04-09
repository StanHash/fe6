#pragma once

#include "gba/gba.h"
#include "types.h"

#include "proc.h"
#include "text.h"
#include "face.h"
#include "menu.h"
#include "mapselect.h"

// some or those are not so much "unknown" as much as they just don't have a home yet

extern struct Font gFont_Unk_02002770;
extern u16 gUnk_Tm_02003238[];
extern u16 gUnk_Tm_02003738[];
extern u16 gUnk_Tm_02003C38[];

extern struct Glyph const * CONST_DATA TextGlyphs_Special[];
extern struct Glyph const * CONST_DATA TextGlyphs_System[];
extern struct Glyph const * CONST_DATA TextGlyphs_Talk[];
extern u16 CONST_DATA Pal_SystemText[];
extern u16 CONST_DATA Pal_TalkText[];
extern u16 CONST_DATA Pal_GreenTextColors[];
extern u8 const Img_FactionMiniCard[];
extern u16 const Pal_FactionMiniCard[];
extern u8 const Img_TalkBubble[];
extern u16 const Pal_TalkBubble[];
extern u8 const Img_TalkBubbleOpeningA[];
extern u8 const Img_TalkBubbleOpeningB[];
extern u8 const Img_TalkBubbleOpeningC[];
extern u8 const Img_TalkBubbleOpeningD[];
extern u8 const Img_TalkBubbleOpeningE[];
extern u8 const Tsa_Unk_08101974[];
extern u8 const Tsa_Unk_08101A2C[];
extern u8 const Img_SystemObjects[];
extern u16 const Pal_SystemObjects[];
extern u8 const Img_LimitViewSquares[];
extern u16 const Pal_LimitViewBlue[];
extern u16 const Pal_LimitViewRed[];
extern u16 const Pal_LimitViewGreen[];
extern u8 const Img_PhaseChangeSquares[];
extern u8 const Img_PhaseChangePlayer[];
extern u16 const Pal_PhaseChangePlayer[];
extern u8 const Img_PhaseChangeEnemy[];
extern u16 const Pal_PhaseChangeEnemy[];
extern u8 const Img_PhaseChangeOther[];
extern u16 const Pal_PhaseChangeOther[];
extern u16 const SpriteAnim_08102450[];
extern u16 const SpriteAnim_GasTrapVertical[];
extern u16 const SpriteAnim_GasTrapHorizontal[];
extern u8 const Img_GasTrapVertical[];
extern u8 const Img_GasTrapHorizontal[];
extern u16 const Pal_GasTrap[];
extern u8 const Img_ArrowTrap[];
extern u16 const Pal_ArrowTrap[];
extern u16 const SpriteAnim_ArrowTrap[];
extern u8 const Img_FireTrap[];
extern u16 const Pal_FireTrap[];
extern u16 const SpriteAnim_FireTrap[];
extern u8 const Img_PikeTrap[];
extern u16 const SpriteAnim_PikeTrap[];
extern u16 const Pal_PikeTrap[];
extern u8 const Img_ChapterIntroFog[];
extern u16 const Pal_ChapterIntroFog[];
extern u8 const Img_ChapterIntroMotif[];
extern u16 const Pal_ChapterIntroMotif[];
extern u8 const Tm_ChapterIntroMotif[];
extern u8 const Img_GameOverText[];
extern u16 const Pal_GameOverText[];
extern u16 const Pal_Unk_0830D95C[];
extern u8 const Tsa_Unk_0830D97C[];
extern u8 const Tsa_Unk_081022FC[];
extern u16 const Pal_UnitSprites[];
extern u16 const Pal_UnitSpritesPurple[];
extern u8 const Img_SandstormParticles[];
extern u8 const Img_SnowstormParticles[];
extern u8 const Img_FlamesParticles[];
extern u16 const Pal_FlamesParticles[];
extern u8 const Img_CloudWeather[];
extern u16 const Pal_CloudWeather[];
extern u8 const Img_MovePath[];
extern u16 const Pal_MovePath[];
extern u8 const Tsa_UnitPanelHeader[];
extern u8 const Img_StatusHealEffect[];
extern u16 const Pal_StatusHealEffect[];
extern u8 const Tsa_StatusHealEffect[];
extern u8 const Tsa_BattlePreviewFrame_Short[];
extern u8 const Tsa_BattlePreviewFrame_Long[];
extern u16 const Pal_BattlePreviewFrame_Blue[];
extern u16 const Pal_BattlePreviewFrame_Red[];
extern u16 const Pal_BattlePreviewFrame_Green[];
extern u16 const Pal_BattlePreviewFrame_Purple[];
extern u8 const Img_BattlePreviewFrame[];
extern u8 const Img_BattlePreviewMultipliers[];
extern u16 const Pal_BattlePreviewMultipliers[];
extern u8 const Img_MuFogBump[];
extern u16 const SpriteAnim_MuFogBump[];
extern u8 const Img_ManimInfoWindowDigits[];
extern u16 const Pal_ManimWindowHpBar[];
extern u8 const Img_ManimInfoFrame[];
extern u8 const Img_ManimHpBar[];
extern u16 const Pal_UiWindowFrame_ThemeBlue[];
extern u16 const Pal_UiWindowFrame_ThemeRed[];
extern u16 const Pal_UiWindowFrame_ThemeGray[];
extern u16 const Pal_UiWindowFrame_ThemeGreen[];
extern u8 const Img_UiWindowFrame_ThemeBlue[];
extern u8 const Img_UiWindowFrame_ThemeRed[];
extern u8 const Img_UiWindowFrame_ThemeGray[];
extern u8 const Img_UiWindowFrame_ThemeGreen[];
extern u16 const Pal_UiStatBar_ThemeBlue[];
extern u16 const Pal_UiStatBar_ThemeRed[];
extern u16 const Pal_UiStatBar_ThemeGray[];
extern u16 const Pal_UiStatBar_ThemeGreen[];
extern u8 const Img_UiUnitNameFrame[];
extern u16 const Pal_UiUnitNameFrame[];

extern u16 const Pal_Unk_081B1710[]; // manim

extern struct FaceInfo CONST_DATA FaceInfoTable[];
extern struct ProcScr CONST_DATA ProcScr_OpeningSequence[];
extern struct ProcScr CONST_DATA ProcScr_Unk_08691480[];
extern struct ProcScr CONST_DATA ProcScr_Unk_0868C304[];
extern struct ProcScr CONST_DATA ProcScr_Unk_0868B010[];
extern struct ProcScr CONST_DATA ProcScr_Unk_0868AE04[];
extern u16 CONST_DATA Pal_ManimFireDragonMu[];
extern u16 CONST_DATA Pal_ManimDivineDragonMu[];

extern i8 CONST_DATA TerrainHealAmountTable[];
extern bool CONST_DATA TerrainHealsStatusTable[];
extern char const * CONST_DATA TerrainNameStringTable[];

extern u8 CONST_DATA JList_BowEffectiveness[];
extern u8 CONST_DATA JList_HeroCrestPromotes[];
extern u8 CONST_DATA JList_KnightCrestPromotes[];
extern u8 CONST_DATA JList_OrionBoltPromotes[];
extern u8 CONST_DATA JList_ElysianWhipPromotes[];
extern u8 CONST_DATA JList_GuidingRingPromotes[];

extern i8 CONST_DATA MoveTable_Flying[];

extern struct ChapterInfo CONST_DATA ChapterInfoTable[];

extern void const * CONST_DATA ChapterAssets[];

extern u16 const Pal_LinkArenaMuralBackground[];
extern u16 const Pal_MuralBackground[];
extern u8 const Img_MuralBackground[];
extern u16 const Pal_Unk_083087C8[][0x20];

extern u8 const gUnk_083080D0[]; // compressed img (statscreen misc sprite sheet)
extern u8 const gUnk_08307CEC[]; // compressed tsa (statscreen main window frame)
extern u16 const gUnk_08308050[]; // pal (statscreen equip stats frame)
extern u8 const gUnk_08307ED4[]; // compressed img (statscreen equip stats frame)
extern u8 const gUnk_08308920[]; // compressed img (equipment label)

extern u8 const gUnk_08307D58[]; // tsa (compressed): statscreen page A frame
extern u8 const gUnk_08307DD4[]; // tsa (compressed): statscreen page B frame
extern u8 const gUnk_08307E50[]; // tsa (compressed): statscreen page C frame
extern u8 const gUnk_08308070[]; // tsa (compressed): statscreen page B battle stat box
extern u8 const gUnk_083080AC[]; // tsa: statscreen page B equipped weapon background

extern u8 const Img_Background_082D80B0[];
extern u8 const Tsa_Background_082DAC8C[];
extern u16 const Pal_Background_082DB140[];
extern u8 const Img_Background_082E28F8[];
extern u8 const Tsa_Background_082E35DC[];
extern u16 const Pal_Background_082E3A90[];
extern u8 const Img_Background_082E3B10[];
extern u8 const Tsa_Background_082E3EC0[];
extern u16 const Pal_Background_082E4374[];
extern u8 const Img_Background_082E4650[];
extern u8 const Tsa_Background_082E6EB4[];
extern u16 const Pal_Background_082E7368[];
extern u8 const Img_Background_082E73E8[];
extern u8 const Tsa_Background_082EADF0[];
extern u16 const Pal_Background_082EB2A4[];
extern u8 const Img_Background_082EB324[];
extern u8 const Tsa_Background_082EDB7C[];
extern u16 const Pal_Background_082EE030[];
extern u8 const Img_Background_082EE0B0[];
extern u8 const Tsa_Background_082EF97C[];
extern u16 const Pal_Background_082EFE30[];
extern u16 const Pal_Background_082EFEB0[];
extern u8 const Img_Background_082EFF30[];
extern u8 const Tsa_Background_082F1490[];
extern u16 const Pal_Background_082F1944[];
extern u8 const Img_Background_082F19C4[];
extern u8 const Tsa_Background_082F3494[];
extern u16 const Pal_Background_082F3948[];
extern u8 const Img_Background_082F39C8[];
extern u8 const Tsa_Background_082F62E0[];
extern u16 const Pal_Background_082F6794[];
extern u16 const Pal_Background_082F6814[];
extern u8 const Img_Background_082F6894[];
extern u8 const Tsa_Background_082F85E8[];
extern u16 const Pal_Background_082F8A9C[];
extern u8 const Img_Background_082F8B1C[];
extern u8 const Tsa_Background_082FBE6C[];
extern u16 const Pal_Background_082FC320[];
extern u8 const Img_Background_082FC3A0[];
extern u8 const Tsa_Background_082FECE0[];
extern u16 const Pal_Background_082FF194[];
extern u8 const Img_Background_082FF214[];
extern u8 const Tsa_Background_08301244[];
extern u16 const Pal_Background_083016F8[];
extern u16 const Pal_Background_08301778[];
extern u16 const Pal_Background_083017F8[];
extern u8 const Img_Background_08301878[];
extern u8 const Tsa_Background_0830491C[];
extern u16 const Pal_Background_08304DD0[];
extern u8 const Img_Background_08304E50[];
extern u8 const Tsa_Background_08306F24[];
extern u16 const Pal_Background_083073D8[];

extern u16 const Pal_Unk_08309474[];
extern u16 const Pal_Unk_083094F4[];
extern u16 const Pal_Unk_0830D5E4[];
