#pragma once

#include "common.h"

#include "proc.h"
#include "event.h"

// TODO: move (eventfunctions)
struct UnkTrapEnt
{
    int delay;
    int interval;
};

extern struct BattleTalkEnt CONST_DATA gBattleDefeatTalkList[];

extern u16 CONST_DATA ShopItems_Chapter2_Vendor[];
extern u16 CONST_DATA ShopItems_Chapter2_Armory[];
extern u16 CONST_DATA ShopItems_Chapter4_Vendor[];
extern u16 CONST_DATA ShopItems_Chapter4_Armory[];
extern u16 CONST_DATA ShopItems_Chapter5_Vendor[];
extern u16 CONST_DATA ShopItems_Unk_0866A84E[];
extern u16 CONST_DATA ShopItems_Unk_0866A85E[];
extern u16 CONST_DATA ShopItems_Unk_0866A86C[];
extern u16 CONST_DATA ShopItems_Unk_0866A87C[];
extern u16 CONST_DATA ShopItems_Unk_0866A890[];
extern u16 CONST_DATA ShopItems_Unk_0866A8A0[];
extern u16 CONST_DATA ShopItems_Unk_0866A8B8[];
extern u16 CONST_DATA ShopItems_Unk_0866A8CA[];
extern u16 CONST_DATA ShopItems_Unk_0866A8E0[];
extern u16 CONST_DATA ShopItems_Unk_0866A8F8[];
extern u16 CONST_DATA ShopItems_Unk_0866A904[];
extern u16 CONST_DATA ShopItems_Unk_0866A918[];
extern u16 CONST_DATA ShopItems_Unk_0866A92A[];
extern u16 CONST_DATA ShopItems_Unk_0866A93A[];
extern u16 CONST_DATA ShopItems_Unk_0866A956[];
extern u16 CONST_DATA ShopItems_Unk_0866A96A[];
extern u16 CONST_DATA ShopItems_Unk_0866A98A[];
extern u16 CONST_DATA ShopItems_Unk_0866A99E[];
extern u16 CONST_DATA ShopItems_Unk_0866A9B0[];
extern u16 CONST_DATA ShopItems_Unk_0866A9C8[];
extern u16 CONST_DATA ShopItems_Unk_0866A9EC[];
extern u16 CONST_DATA ShopItems_Unk_0866AA12[];
extern u16 CONST_DATA ShopItems_Unk_0866AA2A[];
extern u16 CONST_DATA ShopItems_Unk_0866AA3C[];
extern u16 CONST_DATA ShopItems_Chapter10B_Armory[];
extern u16 CONST_DATA ShopItems_Unk_0866AA64[];
extern u16 CONST_DATA ShopItems_Unk_0866AA76[];
extern u16 CONST_DATA ShopItems_Unk_0866AA98[];
extern u16 CONST_DATA ShopItems_Unk_0866AAB0[];
extern u16 CONST_DATA ShopItems_Unk_0866AAC4[];
extern u16 CONST_DATA ShopItems_Unk_0866AAE4[];

extern EventScr CONST_DATA EventScr_RoyDefeated[];
extern EventScr CONST_DATA EventScr_CathTalk[];
extern EventScr CONST_DATA EventScr_GameOver[];

extern u16 CONST_DATA Sprite_0866ACCC[];
extern struct ProcScr CONST_DATA ProcScr_Unk_0866ACE8[];
extern struct ProcScr CONST_DATA ProcScr_Unk_0866AD00[];
extern EventScr CONST_DATA EventScr_Unk_0866AD18[];
extern EventScr CONST_DATA EventScr_Unk_0866AD78[];
extern EventScr CONST_DATA EventScr_Unk_0866ADE4[];
extern EventScr CONST_DATA EventScr_Unk_0866AE10[];
extern EventScr CONST_DATA EventScr_Unk_0866AE60[];
extern EventScr CONST_DATA EventScr_Unk_0866AE78[];
extern EventScr CONST_DATA EventScr_Unk_0866AE90[];
extern EventScr CONST_DATA gUnk_0866AEA8[];
extern EventScr CONST_DATA gUnk_0866AEE0[];
extern EventScr CONST_DATA gUnk_0866AF28[];
extern EventScr CONST_DATA gUnk_0866AF5C[];
extern EventScr CONST_DATA gUnk_0866AFEC[];
extern EventScr CONST_DATA gUnk_0866B07C[];
extern EventScr CONST_DATA gUnk_0866B10C[];
extern EventScr CONST_DATA EventScr_Unk_0866B14C[];
extern EventScr CONST_DATA EventScr_Unk_0866B2E4[];
extern EventScr CONST_DATA EventScr_Unk_0866B2FC[];
extern EventScr CONST_DATA EventScr_Unk_0866B350[];
extern EventScr CONST_DATA EventScr_Unk_0866B5A0[];

extern EventScr CONST_DATA EventScr_Chapter1_Opening[];
extern EventScr CONST_DATA EventScr_Chapter1_FirstRedTurn[];
extern EventScr CONST_DATA EventScr_Chapter1_UnusedTalk[];
extern EventScr CONST_DATA EventScr_Chapter1_Village[];
extern EventScr CONST_DATA EventScr_Chapter1_TopVillageDummy[];
extern EventScr CONST_DATA EventScr_Chapter1_HouseA[];
extern EventScr CONST_DATA EventScr_Chapter1_HouseB[];
extern EventScr CONST_DATA EventScr_Chapter1_HouseC[];
extern EventScr CONST_DATA EventScr_Chapter1_HouseUnused[];
extern EventScr CONST_DATA EventScr_Chapter1_Victory[];

extern u8 CONST_DATA MoveScr_Chapter2_ElenA[];
extern u8 CONST_DATA MoveScr_Chapter2_ElenB[];
extern EventScr CONST_DATA EventScr_Chapter2_Opening[];
extern EventScr CONST_DATA EventScr_Chapter2_DieckComes[];
extern EventScr CONST_DATA EventScr_Chapter2_DieckTalk[];
extern EventScr CONST_DATA EventScr_Chapter2_VillageUnused[];
extern EventScr CONST_DATA EventScr_Chapter2_Village[];
extern EventScr CONST_DATA EventScr_Chapter2_HouseA[];
extern EventScr CONST_DATA EventScr_Chapter2_HouseB[];
extern EventScr CONST_DATA EventScr_Chapter2_HouseC[];
extern EventScr CONST_DATA EventScr_Chapter2_Victory[];

extern EventScr CONST_DATA EventScr_Chapter3_Opening[];
extern EventScr CONST_DATA EventScr_Chapter3_OrphanageCutscene[];
extern EventScr CONST_DATA EventScr_Chapter3_ZephielScene[];
extern EventScr CONST_DATA EventScr_Chapter3_ChadLughTalk[];
extern EventScr CONST_DATA EventScr_Chapter3_TopVillage[];
extern EventScr CONST_DATA EventScr_Chapter3_BottomVillage[];
extern EventScr CONST_DATA EventScr_Chapter3_Victory[];

extern EventScr CONST_DATA EventScr_Chapter4_Opening[];
extern EventScr CONST_DATA EventScr_Chapter4_IntroducePirates[];
extern EventScr CONST_DATA EventScr_Chapter4_ForeshadowClarine[];
extern EventScr CONST_DATA EventScr_Chapter4_ClarineComes[];
extern EventScr CONST_DATA EventScr_Chapter4_RutgerComes[];
extern EventScr CONST_DATA EventScr_Chapter4_ForeshadowRutger[];
extern EventScr CONST_DATA EventScr_Chapter4_UnusedCavalierReinforcements[];
extern EventScr CONST_DATA EventScr_Chapter4_RecruitClarine[];
extern EventScr CONST_DATA EventScr_Chapter4_RefreshClarine[];
extern EventScr CONST_DATA EventScr_Chapter4_RecruitRutger[];
extern EventScr CONST_DATA EventScr_Chapter4_TopRightVillage[];
extern EventScr CONST_DATA EventScr_Chapter4_NorthVillage[];
extern EventScr CONST_DATA EventScr_Chapter4_SouthVillage[];
extern EventScr CONST_DATA EventScr_Chapter4_HouseA[];
extern EventScr CONST_DATA EventScr_Chapter4_HouseB[];
extern EventScr CONST_DATA EventScr_Chapter4_HouseC[];
extern EventScr CONST_DATA EventScr_Chapter4_Victory[];

extern EventScr CONST_DATA EventScr_Chapter5_Opening[];
extern EventScr CONST_DATA EventScr_Chapter5_SaulDorothyScene[];
extern EventScr CONST_DATA EventScr_Chapter5_OpenBarrier[];
extern EventScr CONST_DATA EventScr_Chapter5_Village[];
extern EventScr CONST_DATA EventScr_Chapter5_HouseA[];
extern EventScr CONST_DATA EventScr_Chapter5_HouseB[];
extern EventScr CONST_DATA EventScr_Chapter5_HouseC[];
extern EventScr CONST_DATA EventScr_Chapter5_Victory[];

extern EventScr CONST_DATA EventScr_Unk_0866CB34[];
extern EventScr CONST_DATA EventScr_Unk_0866CC5C[];
extern EventScr CONST_DATA EventScr_Unk_0866CC9C[];
extern EventScr CONST_DATA EventScr_Unk_0866CCDC[];
extern EventScr CONST_DATA EventScr_Unk_0866CD08[];
extern EventScr CONST_DATA EventScr_Unk_0866CD4C[];
extern EventScr CONST_DATA EventScr_Unk_0866CD6C[];
extern EventScr CONST_DATA EventScr_Unk_0866CD98[];
extern EventScr CONST_DATA EventScr_Unk_0866CDB0[];
extern EventScr CONST_DATA EventScr_Unk_0866CDC8[];

extern u8 CONST_DATA MoveScr_Unk_0866CE60[];
extern EventScr CONST_DATA EventScr_Unk_0866CE68[];
extern EventScr CONST_DATA EventScr_Unk_0866CF6C[];
extern EventScr CONST_DATA EventScr_Unk_0866CF90[];
extern EventScr CONST_DATA EventScr_Unk_0866CFD4[];
extern EventScr CONST_DATA EventScr_Unk_0866D068[];
extern EventScr CONST_DATA EventScr_Unk_0866D0A8[];
extern EventScr CONST_DATA EventScr_Unk_0866D0D0[];
extern EventScr CONST_DATA EventScr_Unk_0866D0F8[];
extern EventScr CONST_DATA EventScr_Unk_0866D124[];
extern EventScr CONST_DATA EventScr_Unk_0866D150[];
extern EventScr CONST_DATA EventScr_Unk_0866D17C[];
extern EventScr CONST_DATA EventScr_Unk_0866D1A8[];
extern EventScr CONST_DATA EventScr_Unk_0866D1D4[];
extern EventScr CONST_DATA EventScr_Unk_0866D208[];
extern EventScr CONST_DATA EventScr_Unk_0866D23C[];
extern EventScr CONST_DATA EventScr_Unk_0866D258[];
extern EventScr CONST_DATA EventScr_Unk_0866D2A0[];
extern EventScr CONST_DATA EventScr_Unk_0866D2E8[];
extern EventScr CONST_DATA EventScr_Unk_0866D330[];
extern EventScr CONST_DATA EventScr_Unk_0866D378[];
extern EventScr CONST_DATA EventScr_Unk_0866D3C0[];
extern EventScr CONST_DATA EventScr_Unk_0866D408[];
extern EventScr CONST_DATA EventScr_Unk_0866D450[];
extern EventScr CONST_DATA EventScr_Unk_0866D498[];

extern u8 CONST_DATA MoveScr_Unk_0866D4FC[];
extern u8 CONST_DATA MoveScr_Unk_0866D50D[];
extern EventScr CONST_DATA EventScr_Unk_0866D528[];
extern EventScr CONST_DATA EventScr_Unk_0866D5E4[];
extern EventScr CONST_DATA EventScr_Unk_0866D62C[];
extern EventScr CONST_DATA EventScr_Unk_0866D658[];
extern EventScr CONST_DATA EventScr_Unk_0866D6AC[];
extern EventScr CONST_DATA EventScr_Unk_0866D6C0[];
extern EventScr CONST_DATA EventScr_Unk_0866D6EC[];
extern EventScr CONST_DATA EventScr_Unk_0866D700[];
extern EventScr CONST_DATA EventScr_Unk_0866D714[];
extern EventScr CONST_DATA EventScr_Unk_0866D728[];
extern EventScr CONST_DATA EventScr_Unk_0866D764[];
extern EventScr CONST_DATA EventScr_Unk_0866D7A0[];
extern EventScr CONST_DATA EventScr_Unk_0866D7DC[];
extern EventScr CONST_DATA EventScr_Unk_0866D818[];

extern EventScr CONST_DATA EventScr_Unk_0866DB60[];
extern EventScr CONST_DATA EventScr_Unk_0866DC2C[];
extern EventScr CONST_DATA EventScr_Unk_0866DCF0[];
extern EventScr CONST_DATA EventScr_Unk_0866DD04[];
extern EventScr CONST_DATA EventScr_Unk_0866DD30[];
extern EventScr CONST_DATA EventScr_Unk_0866DD5C[];
extern EventScr CONST_DATA EventScr_Unk_0866DDA4[];
extern EventScr CONST_DATA EventScr_Unk_0866DDF4[];
extern EventScr CONST_DATA EventScr_Unk_0866DE44[];
extern EventScr CONST_DATA EventScr_Unk_0866DE80[];
extern EventScr CONST_DATA EventScr_Unk_0866DEBC[];
extern EventScr CONST_DATA EventScr_Unk_0866DEF8[];
extern EventScr CONST_DATA EventScr_Unk_0866DF34[];

extern EventScr CONST_DATA EventScr_Unk_0866E00C[];
extern EventScr CONST_DATA EventScr_Unk_0866E0AC[];
extern EventScr CONST_DATA EventScr_Unk_0866E11C[];
extern EventScr CONST_DATA EventScr_Unk_0866E178[];
extern EventScr CONST_DATA EventScr_Unk_0866E1A4[];
extern EventScr CONST_DATA EventScr_Unk_0866E1D0[];
extern EventScr CONST_DATA EventScr_Unk_0866E1FC[];
extern EventScr CONST_DATA EventScr_Unk_0866E228[];
extern EventScr CONST_DATA EventScr_Unk_0866E270[];
extern EventScr CONST_DATA EventScr_Unk_0866E2AC[];

extern EventScr CONST_DATA EventScr_Unk_0866E314[];
extern EventScr CONST_DATA EventScr_Unk_0866E418[];
extern EventScr CONST_DATA EventScr_Unk_0866E488[];
extern EventScr CONST_DATA EventScr_Unk_0866E4D4[];
extern EventScr CONST_DATA EventScr_Unk_0866E544[];
extern EventScr CONST_DATA EventScr_Unk_0866E5A0[];
extern EventScr CONST_DATA EventScr_Unk_0866E5DC[];
extern EventScr CONST_DATA EventScr_Unk_0866E64C[];
extern EventScr CONST_DATA EventScr_Unk_0866E684[];
extern EventScr CONST_DATA EventScr_Unk_0866E6EC[];
extern EventScr CONST_DATA EventScr_Unk_0866E720[];
extern EventScr CONST_DATA EventScr_Unk_0866E788[];
extern EventScr CONST_DATA EventScr_Unk_0866E7BC[];
extern EventScr CONST_DATA EventScr_Unk_0866E808[];
extern EventScr CONST_DATA EventScr_Unk_0866E824[];
extern EventScr CONST_DATA EventScr_Unk_0866E870[];
extern EventScr CONST_DATA EventScr_Unk_0866E8B4[];
extern EventScr CONST_DATA EventScr_Unk_0866E900[];
extern EventScr CONST_DATA EventScr_Unk_0866E94C[];
extern EventScr CONST_DATA EventScr_Unk_0866E984[];
extern EventScr CONST_DATA EventScr_Unk_0866E9CC[];
extern EventScr CONST_DATA EventScr_Unk_0866EA14[];
extern EventScr CONST_DATA EventScr_Unk_0866EA5C[];
extern EventScr CONST_DATA EventScr_Unk_0866EAA4[];
extern EventScr CONST_DATA EventScr_Unk_0866EAEC[];
extern EventScr CONST_DATA EventScr_Unk_0866EB34[];
extern EventScr CONST_DATA EventScr_Unk_0866EB7C[];
extern EventScr CONST_DATA EventScr_Unk_0866EBC4[];

extern EventScr CONST_DATA EventScr_Unk_0866EDE8[];
extern EventScr CONST_DATA EventScr_Unk_0866EF30[];
extern EventScr CONST_DATA EventScr_Unk_0866EFF8[];
extern EventScr CONST_DATA EventScr_Unk_0866F044[];
extern EventScr CONST_DATA EventScr_Unk_0866F078[];
extern EventScr CONST_DATA EventScr_Unk_0866F0DC[];
extern EventScr CONST_DATA EventScr_Unk_0866F114[];
extern EventScr CONST_DATA EventScr_Unk_0866F148[];
extern EventScr CONST_DATA EventScr_Unk_0866F17C[];
extern EventScr CONST_DATA EventScr_Unk_0866F198[];
extern EventScr CONST_DATA EventScr_Unk_0866F1B4[];

extern EventScr CONST_DATA EventScr_Unk_0866F2C4[];
extern EventScr CONST_DATA EventScr_Unk_0866F3B0[];
extern EventScr CONST_DATA EventScr_Unk_0866F428[];
extern EventScr CONST_DATA EventScr_Unk_0866F454[];
extern EventScr CONST_DATA EventScr_Unk_0866F4A4[];
extern EventScr CONST_DATA EventScr_Unk_0866F5A8[];
extern EventScr CONST_DATA EventScr_Unk_0866F628[];
extern EventScr CONST_DATA EventScr_Unk_0866F6C4[];
extern EventScr CONST_DATA EventScr_Unk_0866F710[];
extern EventScr CONST_DATA EventScr_Unk_0866F7B0[];
extern EventScr CONST_DATA EventScr_Unk_0866F888[];
extern EventScr CONST_DATA EventScr_Unk_0866F8A8[];
extern EventScr CONST_DATA EventScr_Unk_0866F8C8[];
extern EventScr CONST_DATA EventScr_Unk_0866F944[];
extern EventScr CONST_DATA EventScr_Unk_0866F9C0[];
extern EventScr CONST_DATA EventScr_Unk_0866FA08[];
extern EventScr CONST_DATA EventScr_Unk_0866FA50[];
extern EventScr CONST_DATA EventScr_Unk_0866FA8C[];
extern EventScr CONST_DATA EventScr_Unk_0866FAC8[];
extern EventScr CONST_DATA EventScr_Unk_0866FB04[];

extern EventScr CONST_DATA EventScr_Unk_0866FC0C[];
extern EventScr CONST_DATA EventScr_Unk_0866FCD0[];
extern EventScr CONST_DATA EventScr_Unk_0866FD28[];
extern EventScr CONST_DATA EventScr_Unk_0866FDA4[];
extern EventScr CONST_DATA EventScr_Unk_0866FDE0[];
extern EventScr CONST_DATA EventScr_Unk_0866FE1C[];
extern EventScr CONST_DATA EventScr_Unk_0866FE5C[];
extern EventScr CONST_DATA EventScr_Unk_0866FE9C[];
extern EventScr CONST_DATA EventScr_Unk_0866FEDC[];
extern EventScr CONST_DATA EventScr_Unk_0866FF1C[];
extern EventScr CONST_DATA EventScr_Unk_0866FF5C[];
extern EventScr CONST_DATA EventScr_Unk_0866FF9C[];
extern EventScr CONST_DATA EventScr_Unk_0866FFDC[];
extern EventScr CONST_DATA EventScr_Unk_08670030[];

extern EventScr CONST_DATA EventScr_Unk_08670108[];
extern EventScr CONST_DATA EventScr_Unk_0867023C[];
extern EventScr CONST_DATA EventScr_Unk_0867026C[];
extern EventScr CONST_DATA EventScr_Unk_086702D4[];
extern EventScr CONST_DATA EventScr_Unk_086702FC[];
extern EventScr CONST_DATA EventScr_Unk_08670348[];
extern EventScr CONST_DATA EventScr_Unk_08670394[];
extern EventScr CONST_DATA EventScr_Unk_086703C0[];
extern EventScr CONST_DATA EventScr_Unk_086703DC[];
extern EventScr CONST_DATA EventScr_Unk_08670424[];
extern EventScr CONST_DATA EventScr_Unk_0867046C[];
extern EventScr CONST_DATA EventScr_Unk_086704A8[];
extern EventScr CONST_DATA EventScr_Unk_086704E4[];

extern EventScr CONST_DATA EventScr_Unk_086705D8[];
extern EventScr CONST_DATA EventScr_Unk_0867074C[];
extern EventScr CONST_DATA EventScr_Unk_08670800[];
extern EventScr CONST_DATA EventScr_Unk_0867083C[];
extern EventScr CONST_DATA EventScr_Unk_08670890[];
extern EventScr CONST_DATA EventScr_Unk_08670A28[];
extern EventScr CONST_DATA EventScr_Unk_08670A48[];
extern EventScr CONST_DATA EventScr_Unk_08670A68[];
extern EventScr CONST_DATA EventScr_Unk_08670A94[];
extern EventScr CONST_DATA EventScr_Unk_08670AB4[];
extern EventScr CONST_DATA EventScr_Unk_08670AD4[];
extern EventScr CONST_DATA EventScr_Unk_08670AF4[];

extern EventScr CONST_DATA EventScr_Unk_08670BF0[];
extern EventScr CONST_DATA EventScr_Unk_08670D34[];
extern EventScr CONST_DATA EventScr_Unk_08670D3C[];
extern EventScr CONST_DATA EventScr_Unk_08670D44[];
extern EventScr CONST_DATA EventScr_Unk_08670DB4[];
extern EventScr CONST_DATA EventScr_Unk_08670DFC[];
extern EventScr CONST_DATA EventScr_Unk_08670E38[];
extern EventScr CONST_DATA EventScr_Unk_08670E74[];

extern EventScr CONST_DATA EventScr_Unk_08670ECC[];
extern EventScr CONST_DATA EventScr_Unk_08670F64[];
extern EventScr CONST_DATA EventScr_Unk_08671114[];
extern EventScr CONST_DATA EventScr_Unk_0867115C[];
extern EventScr CONST_DATA EventScr_Unk_086711A4[];
extern EventScr CONST_DATA EventScr_Unk_086711EC[];
extern EventScr CONST_DATA EventScr_Unk_08671228[];
extern EventScr CONST_DATA EventScr_Unk_08671264[];
extern EventScr CONST_DATA EventScr_Unk_086712A0[];
extern EventScr CONST_DATA EventScr_Unk_086712DC[];

extern EventScr CONST_DATA EventScr_Unk_08671340[];
extern EventScr CONST_DATA EventScr_Unk_086713D4[];
extern EventScr CONST_DATA EventScr_Unk_08671434[];
extern EventScr CONST_DATA EventScr_Unk_08671460[];
extern EventScr CONST_DATA EventScr_Unk_086714A8[];
extern EventScr CONST_DATA EventScr_Unk_086714F0[];
extern EventScr CONST_DATA EventScr_Unk_0867152C[];
extern EventScr CONST_DATA EventScr_Unk_08671568[];
extern EventScr CONST_DATA EventScr_Unk_086715A4[];
extern EventScr CONST_DATA EventScr_Unk_086715E0[];

extern EventScr CONST_DATA EventScr_Unk_08671690[];
extern EventScr CONST_DATA EventScr_Unk_086717A0[];
extern EventScr CONST_DATA EventScr_Unk_08671800[];
extern EventScr CONST_DATA EventScr_Unk_08671834[];
extern EventScr CONST_DATA EventScr_Unk_086718B0[];
extern EventScr CONST_DATA EventScr_Unk_086718EC[];
extern EventScr CONST_DATA EventScr_Unk_08671928[];
extern EventScr CONST_DATA EventScr_Unk_08671964[];
extern EventScr CONST_DATA EventScr_Unk_08671980[];
extern EventScr CONST_DATA EventScr_Unk_0867199C[];
extern EventScr CONST_DATA EventScr_Unk_086719B8[];

extern EventScr CONST_DATA EventScr_Unk_08671B48[];
extern EventScr CONST_DATA EventScr_Unk_08671C4C[];
extern EventScr CONST_DATA EventScr_Unk_08671CA8[];
extern EventScr CONST_DATA EventScr_Unk_08671D34[];
extern EventScr CONST_DATA EventScr_Unk_08671DC0[];
extern EventScr CONST_DATA EventScr_Unk_08671DD4[];
extern EventScr CONST_DATA EventScr_Unk_08671E6C[];
extern EventScr CONST_DATA EventScr_Unk_08671EA0[];
extern EventScr CONST_DATA EventScr_Unk_08671EC0[];
extern EventScr CONST_DATA EventScr_Unk_08671EE0[];
extern EventScr CONST_DATA EventScr_Unk_08671EF4[];
extern EventScr CONST_DATA EventScr_Unk_08671F08[];
extern EventScr CONST_DATA EventScr_Unk_08671F50[];

extern EventScr CONST_DATA EventScr_Unk_086720EC[];
extern EventScr CONST_DATA EventScr_Unk_086721F4[];
extern EventScr CONST_DATA EventScr_Unk_08672260[];
extern EventScr CONST_DATA EventScr_Unk_086722EC[];
extern EventScr CONST_DATA EventScr_Unk_08672378[];
extern EventScr CONST_DATA EventScr_Unk_08672430[];
extern u8 CONST_DATA gUnk_08672458[];
extern EventScr CONST_DATA EventScr_Unk_08672464[];

extern EventScr CONST_DATA EventScr_Unk_08672560[];
extern EventScr CONST_DATA EventScr_Unk_08672638[];
extern EventScr CONST_DATA EventScr_Unk_08672684[];
extern EventScr CONST_DATA EventScr_Unk_0867276C[];
extern EventScr CONST_DATA EventScr_Unk_08672788[];
extern EventScr CONST_DATA EventScr_Unk_086727A4[];
extern EventScr CONST_DATA EventScr_Unk_086727C0[];

extern EventScr CONST_DATA EventScr_Unk_08672818[];
extern EventScr CONST_DATA EventScr_Unk_08672874[];
extern EventScr CONST_DATA EventScr_Unk_08672890[];
extern EventScr CONST_DATA EventScr_Unk_086728AC[];
extern EventScr CONST_DATA EventScr_Unk_086728C8[];
extern EventScr CONST_DATA EventScr_Unk_086728E4[];
extern EventScr CONST_DATA EventScr_Unk_08672900[];
extern EventScr CONST_DATA EventScr_Unk_0867291C[];
extern EventScr CONST_DATA EventScr_Unk_0867296C[];
extern EventScr CONST_DATA EventScr_Unk_086729BC[];
extern EventScr CONST_DATA EventScr_Unk_08672A0C[];
extern EventScr CONST_DATA EventScr_Unk_08672A5C[];
extern EventScr CONST_DATA EventScr_Unk_08672AAC[];
extern EventScr CONST_DATA EventScr_Unk_08672AFC[];
extern EventScr CONST_DATA EventScr_Unk_08672B28[];

extern EventScr CONST_DATA EventScr_Unk_08672BE4[];
extern EventScr CONST_DATA EventScr_Unk_08672D10[];
extern EventScr CONST_DATA EventScr_Unk_08672DB4[];
extern EventScr CONST_DATA EventScr_Unk_08672DE0[];
extern EventScr CONST_DATA EventScr_Unk_08672E0C[];

extern EventScr CONST_DATA EventScr_Unk_08672E40[];
extern EventScr CONST_DATA EventScr_Unk_08672ED8[];
extern EventScr CONST_DATA EventScr_Unk_08672F64[];
extern EventScr CONST_DATA EventScr_Unk_08672FB4[];
extern EventScr CONST_DATA EventScr_Unk_08673000[];
extern EventScr CONST_DATA EventScr_Chapter10B_KleinSquadArrives[];
extern EventScr CONST_DATA EventScr_Chapter10B_TheaSquadArrives[];
extern EventScr CONST_DATA EventScr_Unk_086730F4[];
extern EventScr CONST_DATA EventScr_Unk_0867315C[];
extern EventScr CONST_DATA EventScr_Unk_08673190[];
extern EventScr CONST_DATA EventScr_Unk_086731F8[];
extern EventScr CONST_DATA EventScr_Chapter10B_LilinaRecruitsGonzalez[];
extern EventScr CONST_DATA EventScr_Chapter10B_TalkTheaShanna[];
extern EventScr CONST_DATA EventScr_Chapter10B_RoyRecruitsKlein[];
extern EventScr CONST_DATA EventScr_Chapter10B_ClarineRecruitsKlein[];
extern EventScr CONST_DATA EventScr_Chapter10B_ShannaRecruitsThea[];
extern EventScr CONST_DATA EventScr_Chapter10B_KleinRecruitsThea[];
extern EventScr CONST_DATA EventScr_Chapter10B_TalkTheaShannaAfterKlein[];
extern EventScr CONST_DATA EventScr_TalkKleinClarine[];
extern EventScr CONST_DATA EventScr_Chapter10B_VillageA[];
extern EventScr CONST_DATA EventScr_Chapter10B_VillageB[];
extern EventScr CONST_DATA EventScr_Chapter10B_VillageC[];
extern EventScr CONST_DATA EventScr_Chapter10B_VillageD[];
extern EventScr CONST_DATA EventScr_Chapter10B_VillageE[];
extern EventScr CONST_DATA EventScr_Chapter10B_VillageF[];
extern EventScr CONST_DATA EventScr_Chapter10B_VillageG[];
extern EventScr CONST_DATA EventScr_Chapter10B_Victory[];

extern EventScr CONST_DATA EventScr_Unk_0867389C[];
extern EventScr CONST_DATA EventScr_Unk_08673998[];
extern EventScr CONST_DATA EventScr_Unk_086739C0[];
extern EventScr CONST_DATA EventScr_Unk_08673A24[];
extern EventScr CONST_DATA EventScr_Unk_08673A88[];
extern EventScr CONST_DATA EventScr_Unk_08673AB0[];
extern EventScr CONST_DATA EventScr_Unk_08673AD8[];
extern EventScr CONST_DATA EventScr_Unk_08673B00[];
extern EventScr CONST_DATA EventScr_Unk_08673B14[];
extern EventScr CONST_DATA EventScr_Unk_08673B48[];
extern EventScr CONST_DATA EventScr_Unk_08673B84[];
extern EventScr CONST_DATA EventScr_Unk_08673BB0[];
extern EventScr CONST_DATA EventScr_Unk_08673BF8[];

extern EventScr CONST_DATA EventScr_Unk_08673CE8[];
extern EventScr CONST_DATA EventScr_Unk_08673DBC[];
extern EventScr CONST_DATA EventScr_Unk_08673DC4[];
extern EventScr CONST_DATA EventScr_Unk_08673E0C[];
extern EventScr CONST_DATA EventScr_Unk_08673E54[];
extern EventScr CONST_DATA EventScr_Unk_08673E90[];
extern EventScr CONST_DATA EventScr_Unk_08673ECC[];

extern EventScr CONST_DATA EventScr_Unk_08673F24[];
extern EventScr CONST_DATA EventScr_Unk_08673FB0[];
extern EventScr CONST_DATA EventScr_Unk_08673FD4[];
extern EventScr CONST_DATA EventScr_Unk_086741D8[];
extern EventScr CONST_DATA EventScr_Unk_08674214[];
extern EventScr CONST_DATA EventScr_Unk_08674250[];
extern EventScr CONST_DATA EventScr_Unk_0867428C[];
extern EventScr CONST_DATA EventScr_Unk_086742C8[];

extern EventScr CONST_DATA EventScr_Unk_08674358[];
extern EventScr CONST_DATA EventScr_Unk_086743E4[];
extern EventScr CONST_DATA EventScr_Unk_08674430[];
extern EventScr CONST_DATA EventScr_Unk_08674458[];
extern EventScr CONST_DATA EventScr_Unk_086744C0[];
extern EventScr CONST_DATA EventScr_Unk_086744F4[];
extern EventScr CONST_DATA EventScr_Unk_08674564[];
extern EventScr CONST_DATA EventScr_Unk_086745CC[];
extern EventScr CONST_DATA EventScr_Unk_08674604[];
extern EventScr CONST_DATA EventScr_Unk_0867464C[];
extern EventScr CONST_DATA EventScr_Unk_08674694[];
extern EventScr CONST_DATA EventScr_Unk_086746DC[];
extern EventScr CONST_DATA EventScr_Unk_08674724[];
extern EventScr CONST_DATA EventScr_Unk_0867476C[];

extern EventScr CONST_DATA EventScr_Unk_086747D0[];
extern EventScr CONST_DATA EventScr_Unk_08674880[];
extern EventScr CONST_DATA EventScr_Unk_086748C8[];
extern EventScr CONST_DATA EventScr_Unk_086748E8[];
extern EventScr CONST_DATA EventScr_Unk_08674934[];
extern EventScr CONST_DATA EventScr_Unk_08674970[];
extern EventScr CONST_DATA EventScr_Unk_086749A4[];
extern EventScr CONST_DATA EventScr_Unk_086749D8[];
extern EventScr CONST_DATA EventScr_Unk_086749F4[];
extern EventScr CONST_DATA EventScr_Unk_08674A10[];

extern u8 CONST_DATA MoveScr_Unk_08674B10[];
extern u8 CONST_DATA MoveScr_Unk_08674B22[];
extern EventScr CONST_DATA EventScr_Unk_08674B2C[];
extern EventScr CONST_DATA EventScr_Unk_08674BB0[];

extern EventScr CONST_DATA EventScr_Unk_08674F00[];
extern EventScr CONST_DATA EventScr_Unk_08674F84[];

extern struct UnkTrapEnt CONST_DATA gUnk_0867507C[26];
extern EventScr CONST_DATA EventScr_Unk_0867514C[];
extern EventScr CONST_DATA EventScr_Unk_086751E8[];

extern EventScr CONST_DATA EventScr_Unk_08675324[];
extern EventScr CONST_DATA EventScr_Unk_086753E0[];
extern EventScr CONST_DATA EventScr_Unk_08675410[];

extern EventScr CONST_DATA EventScr_Unk_0867557C[];
extern EventScr CONST_DATA EventScr_Unk_086756A8[];

extern u32 CONST_DATA gUnk_08675750[6];
extern EventScr CONST_DATA EventScr_Unk_08675768[];
extern EventScr CONST_DATA EventScr_Unk_086758D4[];
extern EventScr CONST_DATA EventScr_Unk_0867592C[];
extern EventScr CONST_DATA EventScr_Unk_08675984[];
extern EventScr CONST_DATA EventScr_Unk_086759DC[];
extern EventScr CONST_DATA EventScr_Unk_08675A34[];
extern EventScr CONST_DATA EventScr_Unk_08675A8C[];
extern EventScr CONST_DATA EventScr_Unk_08675AE4[];

extern u32 CONST_DATA gUnk_08675B90[6];
extern EventScr CONST_DATA EventScr_Unk_08675BA8[];
extern EventScr CONST_DATA EventScr_Unk_08675CF4[];
extern EventScr CONST_DATA EventScr_Unk_08675D38[];
extern EventScr CONST_DATA EventScr_Unk_08675D7C[];
extern EventScr CONST_DATA EventScr_Unk_08675DC0[];
extern EventScr CONST_DATA EventScr_Unk_08675E04[];
extern EventScr CONST_DATA EventScr_Unk_08675E48[];
extern EventScr CONST_DATA EventScr_Unk_08675E8C[];

extern EventScr CONST_DATA EventScr_Unk_08675FF0[];
extern EventScr CONST_DATA EventScr_Unk_08675FF8[];
extern EventScr CONST_DATA EventScr_Unk_08676014[];

extern EventScr CONST_DATA EventScr_Unk_08676030[];
extern EventScr CONST_DATA EventScr_Unk_08676038[];
extern EventScr CONST_DATA EventScr_Unk_0867605C[];

extern EventScr CONST_DATA EventScr_Unk_08676080[];
extern EventScr CONST_DATA EventScr_Unk_08676088[];
extern EventScr CONST_DATA EventScr_Unk_086760AC[];

extern EventScr CONST_DATA EventScr_Unk_086760FC[];
extern EventScr CONST_DATA EventScr_Unk_08676104[];
extern EventScr CONST_DATA EventScr_Unk_08676128[];

extern EventScr CONST_DATA EventScr_TrialE_Opening[];
extern EventScr CONST_DATA EventScr_TrialE_Victory[];
extern EventScr CONST_DATA EventScr_TrialE_Failure[];
