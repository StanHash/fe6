#ifndef GAMEDATA_H
#define GAMEDATA_H

#include "prelude.h"

#include "face.h"
#include "item.h"
#include "unit.h"
#include "support.h"

extern struct PInfo CONST_DATA PInfoTable[];
extern struct JInfo CONST_DATA JInfoTable[];
extern struct IInfo CONST_DATA IInfoTable[];

extern i8 CONST_DATA MoveTable_BigFootie[];
extern i8 CONST_DATA MoveTable_Footie[];
extern i8 CONST_DATA MoveTable_Armor[];
extern i8 CONST_DATA MoveTable_Fighter[];
extern i8 CONST_DATA MoveTable_Berserker[];
extern i8 CONST_DATA MoveTable_Brigand[];
extern i8 CONST_DATA MoveTable_Pirate[];
extern i8 CONST_DATA MoveTable_Thief[];
extern i8 CONST_DATA MoveTable_Mages[];
extern i8 CONST_DATA MoveTable_Civilian[];
extern i8 CONST_DATA MoveTable_Horsie[];
extern i8 CONST_DATA MoveTable_BigHorsie[];
extern i8 CONST_DATA MoveTable_Nomad[];
extern i8 CONST_DATA MoveTable_NomadTrooper[];
extern i8 CONST_DATA MoveTable_Flying[];
extern i8 CONST_DATA MoveTable_Dragon[];

extern i8 CONST_DATA TerrainAvoTable_Default[];
extern i8 CONST_DATA TerrainDefTable_Default[];
extern i8 CONST_DATA TerrainResTable_Default[];
extern i8 CONST_DATA TerrainAvoTable_Flying[];
extern i8 CONST_DATA TerrainDefTable_Flying[];
extern i8 CONST_DATA TerrainResTable_Flying[];

extern i8 CONST_DATA gUnk_Jinfo44_Brigand[];
extern i8 CONST_DATA gUnk_Jinfo44_Pirate[];
extern i8 CONST_DATA gUnk_Jinfo44_Berserker[];
extern i8 CONST_DATA gUnk_Jinfo44_Priests[];
extern i8 CONST_DATA gUnk_Jinfo44_King[];

extern i8 CONST_DATA TerrainHealAmountTable[];
extern i8 CONST_DATA TerrainHealsStatusTable[];

extern i8 CONST_DATA Terrain_BanimUnk_0860CC0F[];
extern i8 CONST_DATA Terrain_BanimUnk_0860CC42[];
extern i8 CONST_DATA Terrain_BanimUnk_0860CC75[];
extern i8 CONST_DATA Terrain_BanimUnk_0860CCA8[];
extern i8 CONST_DATA Terrain_BanimUnk_0860CCDB[];
extern i8 CONST_DATA Terrain_BanimUnk_0860CD0E[];
extern i8 CONST_DATA Terrain_BanimUnk_0860CD41[];
extern i8 CONST_DATA Terrain_BanimUnk_0860CD74[];
extern i8 CONST_DATA Terrain_BanimUnk_0860CDA7[];
extern i8 CONST_DATA Terrain_BanimUnk_0860CDDA[];
extern i8 CONST_DATA Terrain_BanimUnk_0860CE0D[];
extern i8 CONST_DATA Terrain_BanimUnk_0860CE40[];
extern i8 CONST_DATA Terrain_BanimUnk_0860CE73[];
extern i8 CONST_DATA Terrain_BanimUnk_0860CEA6[];
extern i8 CONST_DATA Terrain_BanimUnk_0860CED9[];
extern i8 CONST_DATA Terrain_BanimUnk_0860CF0C[];
extern i8 CONST_DATA Terrain_BanimUnk_0860CF3F[];
extern i8 CONST_DATA Terrain_BanimUnk_0860CF72[];
extern i8 CONST_DATA Terrain_BanimUnk_0860CFA5[];
extern i8 CONST_DATA Terrain_BanimUnk_0860CFD8[];

extern char const * CONST_DATA TerrainNameStringTable[];

extern struct FaceInfo CONST_DATA FaceInfoTable[];

extern u8 CONST_DATA JList_HorseEffectiveness[];
extern u8 CONST_DATA JList_ArmorEffectiveness[];
extern u8 CONST_DATA JList_RapierEffectiveness[];
extern u8 CONST_DATA JList_DragonEffectiveness[];
extern u8 CONST_DATA JList_WyrmEffectiveness[];
extern u8 CONST_DATA JList_BowEffectiveness[];
extern u8 CONST_DATA JList_HeroCrestPromotes[];
extern u8 CONST_DATA JList_KnightCrestPromotes[];
extern u8 CONST_DATA JList_OrionBoltPromotes[];
extern u8 CONST_DATA JList_ElysianWhipPromotes[];
extern u8 CONST_DATA JList_GuidingRingPromotes[];

extern struct SupportInfo CONST_DATA SupportInfo_Roy;
extern struct SupportInfo CONST_DATA SupportInfo_Clarine;
extern struct SupportInfo CONST_DATA SupportInfo_Fae;
extern struct SupportInfo CONST_DATA SupportInfo_Sin;
extern struct SupportInfo CONST_DATA SupportInfo_Sue;
extern struct SupportInfo CONST_DATA SupportInfo_Dayan;
extern struct SupportInfo CONST_DATA SupportInfo_Barthe;
extern struct SupportInfo CONST_DATA SupportInfo_Bors;
extern struct SupportInfo CONST_DATA SupportInfo_Gwendolyn;
extern struct SupportInfo CONST_DATA SupportInfo_Douglas;
extern struct SupportInfo CONST_DATA SupportInfo_Wolt;
extern struct SupportInfo CONST_DATA SupportInfo_Dorothy;
extern struct SupportInfo CONST_DATA SupportInfo_Klein;
extern struct SupportInfo CONST_DATA SupportInfo_Saul;
extern struct SupportInfo CONST_DATA SupportInfo_Elen;
extern struct SupportInfo CONST_DATA SupportInfo_Yoder;
extern struct SupportInfo CONST_DATA SupportInfo_Chad;
extern struct SupportInfo CONST_DATA SupportInfo_Karel;
extern struct SupportInfo CONST_DATA SupportInfo_Fir;
extern struct SupportInfo CONST_DATA SupportInfo_Rutger;
extern struct SupportInfo CONST_DATA SupportInfo_Dieck;
extern struct SupportInfo CONST_DATA SupportInfo_Ogier;
extern struct SupportInfo CONST_DATA SupportInfo_Garret;
extern struct SupportInfo CONST_DATA SupportInfo_Alen;
extern struct SupportInfo CONST_DATA SupportInfo_Lance;
extern struct SupportInfo CONST_DATA SupportInfo_Perceval;
extern struct SupportInfo CONST_DATA SupportInfo_Igrene;
extern struct SupportInfo CONST_DATA SupportInfo_Marcus;
extern struct SupportInfo CONST_DATA SupportInfo_Astolfo;
extern struct SupportInfo CONST_DATA SupportInfo_Ward;
extern struct SupportInfo CONST_DATA SupportInfo_Lot;
extern struct SupportInfo CONST_DATA SupportInfo_Bartre;
extern struct SupportInfo CONST_DATA SupportInfo_Lugh;
extern struct SupportInfo CONST_DATA SupportInfo_Lilina;
extern struct SupportInfo CONST_DATA SupportInfo_Hugh;
extern struct SupportInfo CONST_DATA SupportInfo_Niime;
extern struct SupportInfo CONST_DATA SupportInfo_Raigh;
extern struct SupportInfo CONST_DATA SupportInfo_Larum;
extern struct SupportInfo CONST_DATA SupportInfo_Juno;
extern struct SupportInfo CONST_DATA SupportInfo_Thea;
extern struct SupportInfo CONST_DATA SupportInfo_Shanna;
extern struct SupportInfo CONST_DATA SupportInfo_Zeiss;
extern struct SupportInfo CONST_DATA SupportInfo_Elffin;
extern struct SupportInfo CONST_DATA SupportInfo_Cath;
extern struct SupportInfo CONST_DATA SupportInfo_Sophia;
extern struct SupportInfo CONST_DATA SupportInfo_Melady;
extern struct SupportInfo CONST_DATA SupportInfo_Gonzalez;
extern struct SupportInfo CONST_DATA SupportInfo_Noah;
extern struct SupportInfo CONST_DATA SupportInfo_Trec;
extern struct SupportInfo CONST_DATA SupportInfo_Zelot;
extern struct SupportInfo CONST_DATA SupportInfo_Echidna;
extern struct SupportInfo CONST_DATA SupportInfo_Cecilia;
extern struct SupportInfo CONST_DATA SupportInfo_Geese;

extern struct ItemBonuses CONST_DATA ItemBonuses_Durandal;
extern struct ItemBonuses CONST_DATA ItemBonuses_BindingBlade;
extern struct ItemBonuses CONST_DATA ItemBonuses_Maltet;
extern struct ItemBonuses CONST_DATA ItemBonuses_Armads;
extern struct ItemBonuses CONST_DATA ItemBonuses_Mulagir;
extern struct ItemBonuses CONST_DATA ItemBonuses_Forblaze;
extern struct ItemBonuses CONST_DATA ItemBonuses_Aureola;
extern struct ItemBonuses CONST_DATA ItemBonuses_Apocalypse;
extern struct ItemBonuses CONST_DATA ItemBonuses_Firestone;
extern struct ItemBonuses CONST_DATA ItemBonuses_Divinestone;
extern struct ItemBonuses CONST_DATA ItemBonuses_Demonstone;
extern struct ItemBonuses CONST_DATA ItemBonuses_SecretBook;
extern struct ItemBonuses CONST_DATA ItemBonuses_GoddessIcon;
extern struct ItemBonuses CONST_DATA ItemBonuses_SeraphRobe;
extern struct ItemBonuses CONST_DATA ItemBonuses_Dracoshield;
extern struct ItemBonuses CONST_DATA ItemBonuses_EnergyRing;
extern struct ItemBonuses CONST_DATA ItemBonuses_Speedwing;
extern struct ItemBonuses CONST_DATA ItemBonuses_Talisman;
extern struct ItemBonuses CONST_DATA ItemBonuses_Boots;
extern struct ItemBonuses CONST_DATA ItemBonuses_BodyRing;

extern struct BanimInfoEnt CONST_DATA BanimInfo_Roy[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Mercenary[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Hero[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Hero_F[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Myrmidon[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Myrmidon_F[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Swordmaster[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Swordmaster_F[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Fighter[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Warrior[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Armor[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Armor_F[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_General[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_General_F[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Archer[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Archer_F[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Sniper[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Sniper_F[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Priest[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Cleric[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Bishop[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Bishop_F[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Mage[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Mage_F[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Sage[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Sage_F[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Shaman[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Shaman_F[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Druid[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Druid_F[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Cavalier[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Paladin[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Troubadour[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Valkyrie[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Nomad[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Nomad_F[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Nomadtrooper[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Nomadtrooper_F[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Pegasusknight[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Falconknight[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Wyvernrider[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Wyvernrider_F[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Wyvernlord[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Wyvernlord_F[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Soldier[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Brigand[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Pirate[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Berserker[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Thief[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Thief_F[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Bard[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Dancer[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Manakete[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Manakete_F[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Firedragon[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Divinedragon[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Demondragon[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_King[];
extern struct BanimInfoEnt CONST_DATA BanimInfo_Roy_Promoted[];

#endif // GAMEDATA_H
