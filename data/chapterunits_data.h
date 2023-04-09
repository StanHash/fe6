#pragma once

// TODO: generate off tool

// UnitInfo @ 08679974
struct UnitInfo CONST_DATA UnitInfo_Unk_08679974[] =
{
    { PID_ROY, 0, 0, FALSE, FACTION_ID_BLUE, 1, 0, 0, 1, 0, { IID_RAPIER, IID_IRONSWORD }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 08679994
struct UnitInfo CONST_DATA UnitInfo_Unk_08679994[] =
{
    { PID_WOLT, 0, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 13, 0, 10, 0, { IID_IRONBOW }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 086799B4
struct UnitInfo CONST_DATA UnitInfo_Unk_086799B4[] =
{
    { PID_LILINA, 0, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 10, 9, 13, 9, { IID_FIRE }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 086799D4
struct UnitInfo CONST_DATA UnitInfo_Unk_086799D4[] =
{
    { 0 }, // end
};

// UnitInfo @ 086799E4
struct UnitInfo CONST_DATA UnitInfo_Unk_086799E4[] =
{
    { PID_BORS_TUTORIAL, 0, 0, FALSE, FACTION_ID_RED, 1, 22, 4, 22, 4, { IID_IRONLANCE }, { AI_A_03, AI_B_03 } },
    { PID_TUTORIAL_SOLDIER, 0, PID_BORS_TUTORIAL, FALSE, FACTION_ID_RED, 1, 14, 4, 9, 5, { IID_SLIMLANCE }, { 0 } },
    { PID_TUTORIAL_SOLDIER, 0, PID_BORS_TUTORIAL, FALSE, FACTION_ID_RED, 1, 19, 5, 19, 5, { IID_SLIMLANCE }, { 0 } },
    { PID_TUTORIAL_SOLDIER, 0, PID_BORS_TUTORIAL, FALSE, FACTION_ID_RED, 1, 17, 7, 17, 7, { IID_SLIMLANCE }, { AI_A_00, AI_B_03 } },
    { PID_TUTORIAL_ARCHER, 0, PID_BORS_TUTORIAL, FALSE, FACTION_ID_RED, 1, 18, 6, 18, 6, { IID_IRONBOW }, { AI_A_00, AI_B_03 } },
    { 0 }, // end
};

// UnitInfo @ 08679A44
struct UnitInfo CONST_DATA UnitInfo_Unk_08679A44[] =
{
    { 0 }, // end
};

// UnitInfo @ 08679A54
struct UnitInfo CONST_DATA UnitInfo_Unk_08679A54[] =
{
    { 0 }, // end
};

// UnitInfo @ 08679A64
struct UnitInfo CONST_DATA UnitInfo_Unk_08679A64[] =
{
    { 0 }, // end
};

// UnitInfo @ 08679A74
struct UnitInfo CONST_DATA UnitInfo_Unk_08679A74[] =
{
    { 0 }, // end
};

// EventScr @ 08679A84
EventScr CONST_DATA EventScr_LoadUnits_Unk_08679974[] =
{
    EvtLoadUnits(UnitInfo_Unk_08679974)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08679A98
EventScr CONST_DATA EventScr_LoadUnits_Unk_08679994[] =
{
    EvtLoadUnits(UnitInfo_Unk_08679994)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08679AAC
EventScr CONST_DATA EventScr_LoadUnits_Unk_086799B4[] =
{
    EvtLoadUnits(UnitInfo_Unk_086799B4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08679AC0
EventScr CONST_DATA EventScr_LoadUnits_Unk_086799D4[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_086799D4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08679ADC
EventScr CONST_DATA EventScr_LoadUnits_Unk_086799E4[] =
{
    EvtLoadUnits(UnitInfo_Unk_086799E4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08679AF0
EventScr CONST_DATA EventScr_LoadUnits_Unk_08679A44[] =
{
    EvtLoadUnits(UnitInfo_Unk_08679A44)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08679B04
EventScr CONST_DATA EventScr_LoadUnits_Unk_08679A54[] =
{
    EvtLoadUnits(UnitInfo_Unk_08679A54)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08679B18
EventScr CONST_DATA EventScr_LoadUnits_Unk_08679A64[] =
{
    EvtLoadUnits(UnitInfo_Unk_08679A64)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08679B2C
EventScr CONST_DATA EventScr_LoadUnits_Unk_08679A74[] =
{
    EvtLoadUnits(UnitInfo_Unk_08679A74)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 0 summary:
// Units UnitInfo_Unk_08679974 1
// Units UnitInfo_Unk_08679994 1
// Units UnitInfo_Unk_086799B4 1
// Units UnitInfo_Unk_086799D4 2
// Units UnitInfo_Unk_086799E4 1
// Units UnitInfo_Unk_08679A44 1
// Units UnitInfo_Unk_08679A54 1
// Units UnitInfo_Unk_08679A64 1
// Units UnitInfo_Unk_08679A74 1

// UnitInfo @ 08679B40
struct UnitInfo CONST_DATA UnitInfo_Chapter1_BlueA[] =
{
    { PID_ROY, 0, 0, FALSE, FACTION_ID_BLUE, 1, 1, 20, 2, 18, { IID_RAPIER, IID_VULNERARY }, { 0 } },
    { PID_MARCUS, 0, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 2, 20, 1, 17, { IID_IRONSWORD, IID_SILVERLANCE }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 08679B70
struct UnitInfo CONST_DATA UnitInfo_Chapter1_BlueB[] =
{
    { PID_ALEN, 0, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 0, 20, 3, 17, { IID_IRONSWORD, IID_IRONLANCE }, { 0 } },
    { PID_BORS, 0, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 1, 20, 3, 19, { IID_IRONLANCE, IID_VULNERARY }, { 0 } },
    { PID_WOLT, 0, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 2, 20, 2, 16, { IID_IRONBOW, IID_VULNERARY }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 08679BB0
struct UnitInfo CONST_DATA UnitInfo_Chapter1_Lance[] =
{
    { PID_LANCE, 0, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 10, 9, 2, 17, { IID_IRONSWORD, IID_JAVELIN, IID_VULNERARY }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 08679BD0
struct UnitInfo CONST_DATA UnitInfo_Chapter1_RedDummy[] =
{
    { 0 }, // end
};

// UnitInfo @ 08679BE0
struct UnitInfo CONST_DATA UnitInfo_Chapter1_RedA[] =
{
    { PID_CHAPTER1_ARCHER, JID_ARCHER, PID_CHAPTER1_4A, FALSE, FACTION_ID_RED, 1, 1, 0, 1, 2, { IID_IRONBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_CHAPTER1_4A, JID_FIGHTER, 0, FALSE, FACTION_ID_RED, 5, 5, 0, 5, 6, { IID_STEELAXE }, { AI_A_03, AI_B_03, 0x09, 0x20 } },
    { PID_CHAPTER1_BANDIT, JID_FIGHTER, PID_CHAPTER1_4A, FALSE, FACTION_ID_RED, 1, 2, 6, 1, 3, { IID_IRONAXE }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_CHAPTER1_BANDIT, JID_FIGHTER, PID_CHAPTER1_4A, FALSE, FACTION_ID_RED, 1, 3, 10, 4, 5, { IID_IRONAXE }, { AI_A_00, AI_B_03, 0x09, 0x00 } },
    { PID_CHAPTER1_BANDIT, JID_FIGHTER, PID_CHAPTER1_4A, FALSE, FACTION_ID_RED, 1, 12, 10, 6, 5, { IID_IRONAXE }, { AI_A_00, AI_B_03, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08679C40
struct UnitInfo CONST_DATA UnitInfo_Chapter1_RedB[] =
{
    { PID_CHAPTER1_BANDIT, JID_FIGHTER, PID_CHAPTER1_4A, FALSE, FACTION_ID_RED, 1, 8, 4, 8, 9, { IID_IRONAXE }, { AI_A_00, AI_B_03, 0x09, 0x00 } },
    { PID_CHAPTER1_BANDIT, JID_FIGHTER, PID_CHAPTER1_4A, FALSE, FACTION_ID_RED, 1, 9, 4, 9, 9, { IID_IRONAXE }, { AI_A_00, AI_B_03, 0x09, 0x00 } },
    { PID_CHAPTER1_BANDIT, JID_FIGHTER, PID_CHAPTER1_4A, FALSE, FACTION_ID_RED, 1, 7, 2, 11, 7, { IID_IRONAXE }, { AI_A_00, AI_B_03, 0x09, 0x00 } },
    { PID_CHAPTER1_ARCHER, JID_ARCHER, PID_CHAPTER1_4A, FALSE, FACTION_ID_RED, 1, 7, 3, 10, 10, { IID_IRONBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08679C90
struct UnitInfo CONST_DATA UnitInfo_Chapter1_RedC[] =
{
    { PID_CHAPTER1_BANDIT, JID_FIGHTER, PID_CHAPTER1_4A, FALSE, FACTION_ID_RED, 1, 12, 7, 7, 15, { IID_IRONAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_CHAPTER1_BANDIT, JID_FIGHTER, PID_CHAPTER1_4A, FALSE, FACTION_ID_RED, 1, 12, 8, 8, 14, { IID_IRONAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_CHAPTER1_BANDIT, JID_FIGHTER, PID_CHAPTER1_4A, FALSE, FACTION_ID_RED, 1, 3, 8, 12, 13, { IID_IRONAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_CHAPTER1_BANDIT, JID_FIGHTER, PID_CHAPTER1_4A, FALSE, FACTION_ID_RED, 1, 4, 8, 8, 18, { IID_IRONAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08679CE0
struct UnitInfo CONST_DATA UnitInfo_Chapter1_Pillager[] =
{
    { PID_CHAPTER1_PILLAGER, 0, PID_CHAPTER1_4A, FALSE, FACTION_ID_RED, 1, 7, 4, 7, 7, { IID_IRONAXE }, { AI_A_00, AI_B_04, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08679D00
struct UnitInfo CONST_DATA UnitInfo_Chapter1_BlueUnused[] =
{
    { PID_ROY, 0, 0, FALSE, FACTION_ID_BLUE, 1, 9, 7, 9, 7, { IID_RAPIER, IID_VULNERARY }, { 0 } },
    { PID_MARCUS, 0, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 6, 7, 6, 7, { IID_IRONLANCE }, { 0 } },
    { 0 }, // end
};

// EventScr @ 08679D30
EventScr CONST_DATA EventScr_LoadUnits_Chapter1_BlueA[] =
{
    EvtLoadUnits(UnitInfo_Chapter1_BlueA)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08679D44
EventScr CONST_DATA EventScr_LoadUnits_Chapter1_BlueB[] =
{
    EvtLoadUnits(UnitInfo_Chapter1_BlueB)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08679D58
EventScr CONST_DATA EventScr_LoadUnits_Chapter1_Lance[] =
{
    EvtLoadUnits(UnitInfo_Chapter1_Lance)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08679D6C
EventScr CONST_DATA EventScr_LoadUnits_Chapter1_RedDummy[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Chapter1_RedDummy)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08679D88
EventScr CONST_DATA EventScr_LoadUnits_Chapter1_RedA[] =
{
    EvtLoadUnits(UnitInfo_Chapter1_RedA)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08679D9C
EventScr CONST_DATA EventScr_LoadUnits_Chapter1_RedB[] =
{
    EvtLoadUnits(UnitInfo_Chapter1_RedB)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08679DB0
EventScr CONST_DATA EventScr_LoadUnits_Chapter1_RedC[] =
{
    EvtLoadUnits(UnitInfo_Chapter1_RedC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08679DC4
EventScr CONST_DATA EventScr_LoadUnits_Chapter1_Pillager[] =
{
    EvtLoadUnits(UnitInfo_Chapter1_Pillager)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08679DD8
EventScr CONST_DATA EventScr_LoadUnits_Chapter1_BlueUnused[] =
{
    EvtLoadUnits(UnitInfo_Chapter1_BlueUnused)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 1 summary:
// Units UnitInfo_Chapter1_BlueA 1
// Units UnitInfo_Chapter1_BlueB 1
// Units UnitInfo_Chapter1_Lance 1
// Units UnitInfo_Chapter1_RedDummy 2
// Units UnitInfo_Chapter1_RedA 1
// Units UnitInfo_Chapter1_RedB 1
// Units UnitInfo_Chapter1_RedC 1
// Units UnitInfo_Chapter1_Pillager 1
// Units UnitInfo_Chapter1_BlueUnused 1

// UnitInfo @ 08679DEC
struct UnitInfo CONST_DATA UnitInfo_Chapter2_Blue[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 2, 2, 10, 2, 10, { IID_IRONSWORD, IID_RAPIER }, { 0 } },
    { PID_MARCUS, JID_PALADIN, PID_ROY, TRUE, FACTION_ID_BLUE, 1, 2, 8, 2, 8, { IID_SILVERLANCE, IID_VULNERARY, IID_VULNERARY }, { 0 } },
    { PID_ALEN, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 3, 3, 9, 3, 9, { IID_IRONSWORD, IID_IRONLANCE }, { 0 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 2, 3, 11, 3, 11, { IID_IRONSWORD, IID_JAVELIN, IID_VULNERARY }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 2, 1, 11, 1, 11, { IID_IRONLANCE }, { 0 } },
    { PID_WOLT, JID_ARCHER, PID_ROY, TRUE, FACTION_ID_BLUE, 1, 0, 10, 0, 10, { IID_IRONBOW }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 08679E5C
struct UnitInfo CONST_DATA UnitInfo_Chapter2_Merlinus[] =
{
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 2, 9, 1, 9, { 0 }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 08679E7C
struct UnitInfo CONST_DATA UnitInfo_Chapter2_RedDummy[] =
{
    { 0 }, // end
};

// UnitInfo @ 08679E8C
struct UnitInfo CONST_DATA UnitInfo_Chapter2_RedA[] =
{
    { PID_CHAPTER2_GENERIC, JID_FIGHTER, PID_CHAPTER2_4B, TRUE, FACTION_ID_RED, 2, 17, 13, 15, 6, { IID_IRONAXE }, { AI_A_0C, AI_B_11, 0x09, 0x00 } },
    { PID_CHAPTER2_GENERIC, JID_ARCHER, PID_CHAPTER2_4B, TRUE, FACTION_ID_RED, 3, 18, 14, 17, 4, { IID_IRONBOW }, { AI_A_0C, AI_B_12, 0x29, 0x00 } },
    { PID_CHAPTER2_SOLDIER_JAVELIN, JID_SOLDIER, PID_CHAPTER2_4B, TRUE, FACTION_ID_RED, 3, 16, 15, 18, 6, { IID_JAVELIN }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_CHAPTER2_GENERIC, JID_FIGHTER, PID_CHAPTER2_4B, TRUE, FACTION_ID_RED, 1, 17, 12, 17, 11, { IID_IRONAXE }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_CHAPTER2_GENERIC, JID_FIGHTER, PID_CHAPTER2_4B, TRUE, FACTION_ID_RED, 2, 18, 12, 18, 10, { IID_IRONAXE }, { AI_A_00, AI_B_03, 0x09, 0x00 } },
    { PID_CHAPTER2_SOLDIER_JAVELIN, JID_SOLDIER, PID_CHAPTER2_4B, TRUE, FACTION_ID_RED, 3, 18, 12, 17, 9, { IID_JAVELIN }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_CHAPTER2_GENERIC, JID_SOLDIER, PID_CHAPTER2_4B, TRUE, FACTION_ID_RED, 2, 18, 12, 18, 11, { IID_IRONLANCE }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_CHAPTER2_GENERIC, JID_FIGHTER, PID_CHAPTER2_4B, TRUE, FACTION_ID_RED, 1, 18, 13, 18, 9, { IID_IRONAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_CHAPTER2_GENERIC, JID_SOLDIER, PID_CHAPTER2_4B, TRUE, FACTION_ID_RED, 1, 18, 15, 18, 8, { IID_JAVELIN }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_CHAPTER2_GENERIC, JID_ARCHER, PID_CHAPTER2_4B, TRUE, FACTION_ID_RED, 1, 16, 12, 16, 7, { IID_IRONBOW }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_CHAPTER2_GENERIC, JID_FIGHTER, PID_CHAPTER2_4B, TRUE, FACTION_ID_RED, 3, 16, 12, 16, 10, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_CHAPTER2_MERCENARY, JID_MERCENARY, PID_CHAPTER2_4B, TRUE, FACTION_ID_RED, 3, 17, 9, 17, 7, { IID_IRONBLADE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08679F5C
struct UnitInfo CONST_DATA UnitInfo_Chapter2_RedB[] =
{
    { PID_CHAPTER2_SOLDIER_JAVELIN, JID_SOLDIER, PID_CHAPTER2_4B, TRUE, FACTION_ID_RED, 3, 7, 17, 3, 14, { IID_IRONLANCE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08679F7C
struct UnitInfo CONST_DATA UnitInfo_Chapter2_RedC[] =
{
    { PID_CHAPTER2_SOLDIER_JAVELIN, JID_SOLDIER, PID_CHAPTER2_4B, TRUE, FACTION_ID_RED, 3, 8, 18, 5, 16, { IID_IRONLANCE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_CHAPTER2_SOLDIER_JAVELIN, JID_SOLDIER, PID_CHAPTER2_4B, TRUE, FACTION_ID_RED, 3, 8, 18, 1, 16, { IID_IRONLANCE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08679FAC
struct UnitInfo CONST_DATA UnitInfo_Chapter2_RedD[] =
{
    { PID_CHAPTER2_GENERIC, JID_FIGHTER, PID_CHAPTER2_4B, TRUE, FACTION_ID_RED, 1, 11, 18, 8, 17, { IID_IRONAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_CHAPTER2_GENERIC, JID_FIGHTER, PID_CHAPTER2_4B, TRUE, FACTION_ID_RED, 1, 11, 18, 6, 18, { IID_IRONAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_CHAPTER2_GENERIC, JID_FIGHTER, PID_CHAPTER2_4B, TRUE, FACTION_ID_RED, 2, 11, 18, 4, 18, { IID_HANDAXE }, { AI_A_00, AI_B_03, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08679FEC
struct UnitInfo CONST_DATA UnitInfo_Chapter2_WardLot[] =
{
    { PID_WARD, JID_FIGHTER, PID_DIECK, FALSE, FACTION_ID_BLUE, 2, 15, 18, 12, 16, { IID_IRONAXE, IID_HAMMER, IID_VULNERARY }, { 0 } },
    { PID_LOT, JID_FIGHTER, PID_DIECK, FALSE, FACTION_ID_BLUE, 3, 15, 18, 12, 18, { IID_IRONAXE, IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_03 } },
    { 0 }, // end
};

// UnitInfo @ 0867A01C
struct UnitInfo CONST_DATA UnitInfo_Chapter2_DieckShanna[] =
{
    { PID_DIECK, JID_MERCENARY, 0, FALSE, FACTION_ID_BLUE, 5, 15, 18, 13, 17, { IID_IRONBLADE, IID_IRONSWORD }, { AI_A_03, AI_B_03 } },
    { PID_SHANNA, JID_PEGASUSKNIGHT, PID_DIECK, FALSE, FACTION_ID_BLUE, 1, 16, 18, 14, 17, { IID_SLIMLANCE, IID_JAVELIN, IID_VULNERARY }, { AI_A_00, AI_B_03 } },
    { 0 }, // end
};

// UnitInfo @ 0867A04C
struct UnitInfo CONST_DATA UnitInfo_Chapter2_CutsceneMelady[] =
{
    { PID_MELADY, JID_WYVERNRIDER, 0, FALSE, FACTION_ID_RED, 5, 16, 3, 16, 3, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_03, AI_B_03, 0x01, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867A06C
struct UnitInfo CONST_DATA UnitInfo_Chapter2_Boss[] =
{
    { PID_CHAPTER2_4B, JID_ARMOR, 0, FALSE, FACTION_ID_RED, 5, 16, 3, 16, 4, { IID_JAVELIN }, { AI_A_03, AI_B_03, 0x01, 0x20 } },
    { 0 }, // end
};

// UnitInfo @ 0867A08C
struct UnitInfo CONST_DATA UnitInfo_Chapter2_OpeningSoldier[] =
{
    { PID_CHAPTER2_SOLDIER_JAVELIN, JID_SOLDIER, PID_CHAPTER2_4B, TRUE, FACTION_ID_RED, 3, 16, 3, 16, 3, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867A0AC
struct UnitInfo CONST_DATA UnitInfo_Chapter2_Elen[] =
{
    { PID_ELEN, JID_CLERIC, PID_ROY, FALSE, FACTION_ID_BLUE, 2, 4, 14, 4, 14, { IID_HEALSTAFF, IID_VULNERARY }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867A0CC
struct UnitInfo CONST_DATA UnitInfo_Chapter2_MixedUnused[] =
{
    { PID_ROY, JID_ROY, 0, FALSE, FACTION_ID_BLUE, 3, 6, 10, 6, 10, { IID_RAPIER }, { 0 } },
    { PID_ELEN, JID_CLERIC, PID_ROY, FALSE, FACTION_ID_BLUE, 3, 8, 10, 8, 10, { IID_HEALSTAFF }, { 0 } },
    { PID_WOLT, JID_ARCHER, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 12, 1, 12, 1, { 0 }, { 0 } },
    { PID_MARCUS, JID_PALADIN, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 1, 9, 1, 9, { 0 }, { 0 } },
    { PID_ALEN, JID_CAVALIER, PID_ROY, FALSE, FACTION_ID_BLUE, 3, 2, 10, 2, 10, { 0 }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, FALSE, FACTION_ID_BLUE, 2, 6, 12, 6, 12, { 0 }, { 0 } },
    { PID_CHAPTER2_GENERIC, JID_FIGHTER, 0, FALSE, FACTION_ID_RED, 1, 3, 6, 3, 6, { 0 }, { AI_A_00, AI_B_03 } },
    { PID_CHAPTER2_GENERIC, JID_ARCHER, 0, FALSE, FACTION_ID_RED, 1, 5, 5, 5, 5, { 0 }, { AI_A_00, AI_B_03 } },
    { PID_CHAPTER2_GENERIC, JID_SOLDIER, 0, FALSE, FACTION_ID_RED, 2, 3, 8, 3, 8, { 0 }, { AI_A_00, AI_B_03 } },
    { PID_CHAPTER2_GENERIC, JID_FIGHTER, 0, FALSE, FACTION_ID_RED, 1, 1, 13, 1, 13, { 0 }, { AI_A_00, AI_B_03 } },
    { PID_CHAPTER2_MERCENARY, JID_MERCENARY, 0, FALSE, FACTION_ID_RED, 3, 4, 14, 4, 14, { 0 }, { AI_A_00, AI_B_03 } },
    { 0 }, // end
};

// EventScr @ 0867A18C
EventScr CONST_DATA EventScr_LoadUnits_Chapter2_Blue[] =
{
    EvtLoadUnits(UnitInfo_Chapter2_Blue)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867A1A0
EventScr CONST_DATA EventScr_LoadUnits_Chapter2_Merlinus[] =
{
    EvtLoadUnits(UnitInfo_Chapter2_Merlinus)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867A1B4
EventScr CONST_DATA EventScr_LoadUnits_Chapter2_RedDummy[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Chapter2_RedDummy)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867A1D0
EventScr CONST_DATA EventScr_LoadUnits_Chapter2_RedA[] =
{
    EvtLoadUnits(UnitInfo_Chapter2_RedA)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867A1E4
EventScr CONST_DATA EventScr_LoadUnits_Chapter2_RedB[] =
{
    EvtLoadUnits(UnitInfo_Chapter2_RedB)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867A1F8
EventScr CONST_DATA EventScr_LoadUnits_Chapter2_RedC[] =
{
    EvtLoadUnits(UnitInfo_Chapter2_RedC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867A20C
EventScr CONST_DATA EventScr_LoadUnits_Chapter2_RedD[] =
{
    EvtLoadUnits(UnitInfo_Chapter2_RedD)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867A220
EventScr CONST_DATA EventScr_LoadUnits_Chapter2_WardLot[] =
{
    EvtLoadUnits(UnitInfo_Chapter2_WardLot)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867A234
EventScr CONST_DATA EventScr_LoadUnits_Chapter2_DieckShanna[] =
{
    EvtLoadUnits(UnitInfo_Chapter2_DieckShanna)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867A248
EventScr CONST_DATA EventScr_LoadUnits_Chapter2_CutsceneMelady[] =
{
    EvtLoadUnits(UnitInfo_Chapter2_CutsceneMelady)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867A25C
EventScr CONST_DATA EventScr_LoadUnits_Chapter2_Boss[] =
{
    EvtLoadUnits(UnitInfo_Chapter2_Boss)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867A270
EventScr CONST_DATA EventScr_LoadUnits_Chapter2_OpeningSoldier[] =
{
    EvtLoadUnits(UnitInfo_Chapter2_OpeningSoldier)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867A284
EventScr CONST_DATA EventScr_LoadUnits_Chapter2_Elen[] =
{
    EvtLoadUnits(UnitInfo_Chapter2_Elen)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867A298
EventScr CONST_DATA EventScr_LoadUnits_Chapter2_MixedUnused[] =
{
    EvtLoadUnits(UnitInfo_Chapter2_MixedUnused)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 2 summary:
// Units UnitInfo_Chapter2_Blue 1
// Units UnitInfo_Chapter2_Merlinus 1
// Units UnitInfo_Chapter2_RedDummy 2
// Units UnitInfo_Chapter2_RedA 1
// Units UnitInfo_Chapter2_RedB 1
// Units UnitInfo_Chapter2_RedC 1
// Units UnitInfo_Chapter2_RedD 1
// Units UnitInfo_Chapter2_WardLot 1
// Units UnitInfo_Chapter2_DieckShanna 1
// Units UnitInfo_Chapter2_CutsceneMelady 1
// Units UnitInfo_Chapter2_Boss 1
// Units UnitInfo_Chapter2_OpeningSoldier 1
// Units UnitInfo_Chapter2_Elen 1
// Units UnitInfo_Chapter2_MixedUnused 1

// UnitInfo @ 0867A2AC
struct UnitInfo CONST_DATA UnitInfo_Unk_0867A2AC[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 3, 3, 19, 3, 19, { IID_RAPIER, IID_IRONSWORD, IID_VULNERARY }, { 0 } },
    { PID_MARCUS, JID_PALADIN, PID_ROY, TRUE, FACTION_ID_BLUE, 1, 1, 19, 1, 19, { IID_IRONLANCE }, { 0 } },
    { PID_ALEN, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 3, 4, 18, 4, 18, { IID_IRONSWORD, IID_IRONLANCE, IID_VULNERARY }, { 0 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 3, 2, 18, 2, 18, { IID_IRONSWORD, IID_JAVELIN, IID_VULNERARY, IID_IRONLANCE }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 3, 5, 19, 5, 19, { IID_SILVERLANCE, IID_IRONLANCE, IID_IRONLANCE }, { 0 } },
    { PID_WOLT, JID_ARCHER, PID_ROY, TRUE, FACTION_ID_BLUE, 4, 2, 20, 2, 20, { IID_IRONBOW, IID_IRONBOW }, { 0 } },
    { PID_DIECK, JID_MERCENARY, PID_ROY, TRUE, FACTION_ID_BLUE, 5, 6, 20, 6, 20, { IID_IRONSWORD, IID_IRONBLADE, IID_ARMORSLAYER }, { 0 } },
    { PID_WARD, JID_FIGHTER, PID_ROY, TRUE, FACTION_ID_BLUE, 2, 4, 20, 4, 20, { IID_HANDAXE, IID_IRONAXE, IID_HAMMER, IID_VULNERARY }, { 0 } },
    { PID_LOT, JID_FIGHTER, PID_ROY, TRUE, FACTION_ID_BLUE, 3, 5, 21, 5, 21, { IID_IRONAXE, IID_STEELAXE }, { 0 } },
    { PID_SHANNA, JID_PEGASUSKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 1, 3, 21, 3, 21, { IID_JAVELIN, IID_SLIMLANCE, IID_IRONLANCE }, { 0 } },
    { PID_ELEN, JID_CLERIC, PID_ROY, TRUE, FACTION_ID_BLUE, 2, 1, 21, 1, 21, { IID_HEALSTAFF, IID_VULNERARY, IID_VULNERARY, IID_VULNERARY }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, TRUE, FACTION_ID_BLUE, 1, 0, 20, 0, 20, { 0 }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867A37C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867A37C[] =
{
    { PID_CHAD, JID_THIEF, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 3, 18, 3, 17, { IID_IRONSWORD, IID_LOCKPICK }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867A39C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867A39C[] =
{
    { PID_UNKNOWN_6F, JID_ARMOR, PID_UNKNOWN_4C, TRUE, FACTION_ID_RED, 2, 10, 7, 10, 7, { IID_IRONLANCE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_6F, JID_ARMOR, PID_UNKNOWN_4C, TRUE, FACTION_ID_RED, 3, 15, 12, 15, 12, { IID_IRONLANCE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_6F, JID_ARMOR, PID_UNKNOWN_4C, TRUE, FACTION_ID_RED, 3, 18, 12, 18, 12, { IID_IRONLANCE, IID_JAVELIN, IID_VULNERARY }, { AI_A_03, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_70, JID_SOLDIER, PID_UNKNOWN_4C, TRUE, FACTION_ID_RED, 5, 9, 17, 9, 17, { IID_JAVELIN }, { AI_A_00, AI_B_00, 0x11, 0x00 } },
    { PID_UNKNOWN_70, JID_SOLDIER, PID_UNKNOWN_4C, TRUE, FACTION_ID_RED, 5, 11, 17, 11, 17, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x11, 0x00 } },
    { PID_UNKNOWN_70, JID_SOLDIER, PID_UNKNOWN_4C, TRUE, FACTION_ID_RED, 5, 14, 11, 14, 11, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x11, 0x00 } },
    { PID_UNKNOWN_70, JID_SOLDIER, PID_UNKNOWN_4C, TRUE, FACTION_ID_RED, 5, 13, 4, 13, 4, { IID_JAVELIN }, { AI_A_00, AI_B_00, 0x11, 0x00 } },
    { PID_UNKNOWN_70, JID_SOLDIER, PID_UNKNOWN_4C, TRUE, FACTION_ID_RED, 5, 7, 9, 7, 9, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x11, 0x00 } },
    { PID_UNKNOWN_70, JID_SOLDIER, PID_UNKNOWN_4C, TRUE, FACTION_ID_RED, 5, 5, 11, 5, 11, { IID_IRONLANCE }, { AI_A_00, AI_B_03, 0x11, 0x00 } },
    { PID_UNKNOWN_70, JID_SOLDIER, PID_UNKNOWN_4C, TRUE, FACTION_ID_RED, 5, 14, 8, 14, 8, { IID_IRONLANCE }, { AI_A_00, AI_B_03, 0x11, 0x00 } },
    { PID_UNKNOWN_70, JID_SOLDIER, PID_UNKNOWN_4C, TRUE, FACTION_ID_RED, 5, 6, 13, 6, 13, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x11, 0x00 } },
    { PID_UNKNOWN_70, JID_SOLDIER, PID_UNKNOWN_4C, TRUE, FACTION_ID_RED, 5, 16, 19, 16, 19, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x11, 0x00 } },
    { PID_UNKNOWN_70, JID_SOLDIER, PID_UNKNOWN_4C, TRUE, FACTION_ID_RED, 5, 17, 21, 17, 21, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x11, 0x00 } },
    { PID_UNKNOWN_70, JID_SOLDIER, PID_UNKNOWN_4C, TRUE, FACTION_ID_RED, 5, 1, 5, 1, 5, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x51, 0x00 } },
    { PID_UNKNOWN_70, JID_SOLDIER, PID_UNKNOWN_4C, TRUE, FACTION_ID_RED, 5, 0, 6, 0, 6, { IID_JAVELIN }, { AI_A_00, AI_B_00, 0x51, 0x00 } },
    { PID_UNKNOWN_6F, JID_SOLDIER, PID_UNKNOWN_4C, TRUE, FACTION_ID_RED, 3, 17, 13, 17, 13, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x11, 0x00 } },
    { PID_UNKNOWN_6F, JID_ARCHER, PID_UNKNOWN_4C, TRUE, FACTION_ID_RED, 2, 2, 4, 2, 4, { IID_IRONBOW }, { AI_A_00, AI_B_03, 0x29, 0x00 } },
    { PID_UNKNOWN_6F, JID_ARCHER, PID_UNKNOWN_4C, TRUE, FACTION_ID_RED, 2, 9, 13, 9, 13, { IID_IRONBOW }, { AI_A_00, AI_B_03, 0x29, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867A4CC
struct UnitInfo CONST_DATA UnitInfo_Unk_0867A4CC[] =
{
    { PID_ZEPHIEL, JID_KING, 0, FALSE, FACTION_ID_RED, 8, 19, 4, 19, 4, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_03, AI_B_03, 0x01, 0x00 } },
    { PID_IDUNN, JID_SHAMAN_F, PID_UNKNOWN_4C, TRUE, FACTION_ID_RED, 4, 18, 5, 18, 5, { IID_HANDAXE }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_NARCIAN, JID_WYVERNLORD, PID_UNKNOWN_4C, TRUE, FACTION_ID_RED, 4, 20, 5, 20, 5, { IID_IRONAXE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_4C, JID_ARMOR, 0, FALSE, FACTION_ID_RED, 7, 21, 5, 21, 5, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_03, AI_B_03, 0x19, 0x20 } },
    { PID_UNKNOWN_6F, JID_FIGHTER, PID_UNKNOWN_4C, TRUE, FACTION_ID_RED, 4, 16, 5, 16, 5, { IID_HANDAXE }, { AI_A_00, AI_B_03, 0x19, 0x00 } },
    { PID_UNKNOWN_6F, JID_FIGHTER, PID_UNKNOWN_4C, TRUE, FACTION_ID_RED, 4, 22, 5, 22, 5, { IID_IRONAXE }, { AI_A_00, AI_B_03, 0x19, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867A53C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867A53C[] =
{
    { PID_UNKNOWN_6F, JID_SOLDIER, PID_UNKNOWN_4C, TRUE, FACTION_ID_RED, 5, 4, 9, 4, 9, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_6F, JID_ARCHER, PID_UNKNOWN_4C, TRUE, FACTION_ID_RED, 2, 4, 13, 4, 13, { IID_IRONBOW }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867A56C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867A56C[] =
{
    { PID_UNKNOWN_6F, JID_MERCENARY, PID_UNKNOWN_4C, TRUE, FACTION_ID_RED, 4, 15, 14, 15, 14, { IID_IRONSWORD }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867A58C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867A58C[] =
{
    { PID_UNKNOWN_6F, JID_CAVALIER, PID_UNKNOWN_4C, TRUE, FACTION_ID_RED, 1, 24, 8, 23, 8, { IID_IRONSWORD }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_6F, JID_CAVALIER, PID_UNKNOWN_4C, TRUE, FACTION_ID_RED, 1, 24, 9, 23, 9, { IID_JAVELIN }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867A5BC
struct UnitInfo CONST_DATA UnitInfo_Unk_0867A5BC[] =
{
    { PID_LUGH, JID_MAGE, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 3, 3, 3, 4, { IID_FIRE, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867A5DC
struct UnitInfo CONST_DATA UnitInfo_Unk_0867A5DC[] =
{
    { PID_UNKNOWN_56, JID_BISHOP, PID_ROY, FALSE, FACTION_ID_GREEN, 1, 3, 3, 5, 4, { 0 }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867A5FC
struct UnitInfo CONST_DATA UnitInfo_Unk_0867A5FC[] =
{
    { PID_CATH, JID_CHILD, PID_ROY, FALSE, FACTION_ID_GREEN, 1, 3, 3, 4, 4, { 0 }, { 0 } },
    { PID_RAIGH, JID_CHILD_F, PID_ROY, FALSE, FACTION_ID_GREEN, 1, 3, 3, 4, 5, { 0 }, { 0 } },
    { PID_LILINA, JID_CHILD_F, PID_ROY, FALSE, FACTION_ID_GREEN, 1, 3, 3, 3, 4, { 0 }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { 0 }, // end
};

// EventScr @ 0867A63C
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867A2AC[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867A2AC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867A650
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867A37C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867A37C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867A664
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867A39C[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_0867A39C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867A680
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867A4CC[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867A4CC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867A694
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867A53C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867A53C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867A6A8
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867A56C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867A56C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867A6BC
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867A58C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867A58C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867A6D0
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867A5BC[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867A5BC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867A6E4
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867A5DC[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867A5DC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867A6F8
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867A5FC[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867A5FC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 3 summary:
// Units UnitInfo_Unk_0867A2AC 1
// Units UnitInfo_Unk_0867A37C 1
// Units UnitInfo_Unk_0867A39C 2
// Units UnitInfo_Unk_0867A4CC 1
// Units UnitInfo_Unk_0867A53C 1
// Units UnitInfo_Unk_0867A56C 1
// Units UnitInfo_Unk_0867A58C 1
// Units UnitInfo_Unk_0867A5BC 1
// Units UnitInfo_Unk_0867A5DC 1
// Units UnitInfo_Unk_0867A5FC 1

// UnitInfo @ 0867A70C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867A70C[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 3, 23, 3, 23, 3, { IID_RAPIER, IID_IRONSWORD, IID_VULNERARY }, { 0 } },
    { PID_MARCUS, JID_PALADIN, PID_ROY, TRUE, FACTION_ID_BLUE, 2, 22, 3, 22, 3, { IID_SILVERLANCE, IID_IRONSWORD }, { 0 } },
    { PID_ALEN, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 5, 21, 2, 21, 2, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN }, { 0 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 3, 21, 4, 21, 4, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 4, 20, 3, 20, 3, { IID_IRONLANCE, IID_JAVELIN }, { 0 } },
    { PID_WOLT, JID_ARCHER, PID_ROY, TRUE, FACTION_ID_BLUE, 3, 23, 2, 23, 2, { IID_IRONBOW, IID_VULNERARY }, { 0 } },
    { PID_DIECK, JID_MERCENARY, PID_ROY, TRUE, FACTION_ID_BLUE, 6, 23, 7, 23, 7, { IID_IRONBLADE, IID_IRONSWORD, IID_ARMORSLAYER }, { 0 } },
    { PID_WARD, JID_FIGHTER, PID_ROY, TRUE, FACTION_ID_BLUE, 5, 24, 6, 24, 6, { IID_IRONAXE, IID_HAMMER }, { 0 } },
    { PID_LOT, JID_FIGHTER, PID_ROY, TRUE, FACTION_ID_BLUE, 3, 24, 8, 24, 8, { IID_STEELAXE, IID_HANDAXE }, { 0 } },
    { PID_SHANNA, JID_PEGASUSKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 2, 23, 9, 23, 9, { IID_SLIMLANCE, IID_VULNERARY }, { 0 } },
    { PID_ELEN, JID_CLERIC, PID_ROY, TRUE, FACTION_ID_BLUE, 3, 23, 4, 23, 4, { IID_HEALSTAFF, IID_VULNERARY }, { 0 } },
    { PID_CHAD, JID_THIEF, PID_ROY, TRUE, FACTION_ID_BLUE, 1, 24, 7, 24, 7, { IID_IRONSWORD, IID_LOCKPICK }, { 0 } },
    { PID_LUGH, JID_MAGE, PID_ROY, TRUE, FACTION_ID_BLUE, 2, 25, 7, 25, 7, { IID_FIRE, IID_VULNERARY }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, TRUE, FACTION_ID_BLUE, 1, 24, 3, 24, 3, { 0 }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867A7FC
struct UnitInfo CONST_DATA UnitInfo_Unk_0867A7FC[] =
{
    { PID_NARCIAN, JID_WYVERNLORD, 0, FALSE, FACTION_ID_RED, 1, 18, 10, 18, 10, { IID_SILVERLANCE, IID_JAVELIN }, { AI_A_03, AI_B_03 } },
    { 0 }, // end
};

// UnitInfo @ 0867A81C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867A81C[] =
{
    { PID_NARCIAN, JID_WYVERNLORD, 0, TRUE, FACTION_ID_RED, 1, 3, 8, 3, 8, { IID_SILVERLANCE, IID_JAVELIN }, { AI_A_03, AI_B_03 } },
    { PID_UNKNOWN_4D, JID_CAVALIER, 0, FALSE, FACTION_ID_RED, 10, 2, 9, 2, 9, { IID_STEELSWORD, IID_JAVELIN }, { AI_A_03, AI_B_03, 0x01, 0x20 } },
    { PID_UNKNOWN_71, JID_CAVALIER, PID_UNKNOWN_4D, TRUE, FACTION_ID_RED, 4, 1, 5, 1, 5, { IID_IRONSWORD }, { AI_A_07, AI_B_07, 0x01, 0x00 } },
    { PID_UNKNOWN_71, JID_ARCHER, PID_UNKNOWN_4D, TRUE, FACTION_ID_RED, 5, 0, 6, 0, 6, { IID_IRONBOW }, { AI_A_07, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_71, JID_CAVALIER, PID_UNKNOWN_4D, TRUE, FACTION_ID_RED, 3, 5, 10, 3, 10, { IID_IRONLANCE }, { AI_A_07, AI_B_01, 0x01, 0x00 } },
    { PID_UNKNOWN_71, JID_CAVALIER, PID_UNKNOWN_4D, TRUE, FACTION_ID_RED, 3, 5, 11, 3, 11, { IID_IRONLANCE }, { AI_A_07, AI_B_01, 0x01, 0x00 } },
    { PID_UNKNOWN_71, JID_CAVALIER, PID_UNKNOWN_4D, TRUE, FACTION_ID_RED, 3, 1, 10, 0, 10, { IID_IRONSWORD }, { AI_A_07, AI_B_01, 0x01, 0x00 } },
    { PID_UNKNOWN_71, JID_CAVALIER, PID_UNKNOWN_4D, TRUE, FACTION_ID_RED, 5, 1, 11, 0, 11, { IID_IRONLANCE }, { AI_A_07, AI_B_07, 0x01, 0x00 } },
    { PID_UNKNOWN_71, JID_CAVALIER, PID_UNKNOWN_4D, TRUE, FACTION_ID_RED, 3, 6, 10, 6, 10, { IID_IRONSWORD }, { AI_A_07, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_71, JID_CAVALIER, PID_UNKNOWN_4D, TRUE, FACTION_ID_RED, 3, 6, 11, 6, 11, { IID_IRONLANCE }, { AI_A_07, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_71, JID_CAVALIER, PID_UNKNOWN_4D, TRUE, FACTION_ID_RED, 2, 15, 7, 12, 8, { IID_IRONLANCE }, { AI_A_07, AI_B_01, 0x01, 0x00 } },
    { PID_UNKNOWN_71, JID_CAVALIER, PID_UNKNOWN_4D, TRUE, FACTION_ID_RED, 2, 17, 6, 14, 7, { IID_IRONLANCE }, { AI_A_07, AI_B_01, 0x01, 0x00 } },
    { PID_UNKNOWN_71, JID_CAVALIER, PID_UNKNOWN_4D, TRUE, FACTION_ID_RED, 2, 15, 4, 13, 2, { IID_IRONSWORD }, { AI_A_07, AI_B_01, 0x01, 0x00 } },
    { PID_UNKNOWN_71, JID_ARCHER, PID_UNKNOWN_4D, TRUE, FACTION_ID_RED, 5, 8, 12, 1, 12, { IID_IRONBOW }, { AI_A_07, AI_B_07, 0x01, 0x00 } },
    { PID_UNKNOWN_71, JID_ARCHER, PID_UNKNOWN_4D, TRUE, FACTION_ID_RED, 4, 5, 8, 4, 9, { IID_IRONBOW }, { AI_A_07, AI_B_07, 0x01, 0x00 } },
    { PID_UNKNOWN_71, JID_NOMAD, PID_UNKNOWN_4D, TRUE, FACTION_ID_RED, 1, 3, 10, 1, 9, { IID_IRONBOW }, { AI_A_07, AI_B_01, 0x01, 0x00 } },
    { PID_UNKNOWN_71, JID_NOMAD, PID_UNKNOWN_4D, TRUE, FACTION_ID_RED, 1, 16, 6, 13, 7, { IID_IRONBOW }, { AI_A_07, AI_B_03, 0x01, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867A93C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867A93C[] =
{
    { PID_UNKNOWN_72, JID_PIRATE, 0, TRUE, FACTION_ID_RED, 4, 29, 15, 29, 15, { IID_IRONAXE }, { AI_A_07, AI_B_04, 0x04, 0x00 } },
    { PID_UNKNOWN_72, JID_PIRATE, 0, TRUE, FACTION_ID_RED, 3, 23, 16, 23, 16, { IID_HANDAXE }, { AI_A_07, AI_B_04, 0x04, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867A96C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867A96C[] =
{
    { PID_UNKNOWN_71, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 4, 29, 5, 28, 5, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_71, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 4, 29, 6, 28, 6, { IID_IRONLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_71, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 4, 29, 7, 28, 7, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_71, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 4, 29, 8, 28, 8, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867A9BC
struct UnitInfo CONST_DATA UnitInfo_Unk_0867A9BC[] =
{
    { PID_CLARINE, JID_TROUBADOUR, 0, FALSE, FACTION_ID_GREEN, 1, 3, 6, 5, 5, { IID_HEALSTAFF, IID_VULNERARY }, { AI_A_06, AI_B_0B, 0x01, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867A9DC
struct UnitInfo CONST_DATA UnitInfo_Unk_0867A9DC[] =
{
    { PID_UNKNOWN_71, JID_FIGHTER, PID_UNKNOWN_4D, TRUE, FACTION_ID_RED, 3, 3, 9, 5, 7, { IID_IRONAXE, IID_VULNERARY }, { AI_A_07, AI_B_01, 0x04, 0x00 } },
    { PID_UNKNOWN_71, JID_FIGHTER, PID_UNKNOWN_4D, TRUE, FACTION_ID_RED, 2, 3, 9, 7, 7, { IID_IRONAXE, IID_VULNERARY }, { AI_A_07, AI_B_01, 0x04, 0x00 } },
    { PID_UNKNOWN_71, JID_ARCHER, PID_UNKNOWN_4D, TRUE, FACTION_ID_RED, 2, 3, 9, 6, 7, { IID_IRONBOW, IID_VULNERARY }, { AI_A_07, AI_B_01, 0x04, 0x00 } },
    { PID_RUTGER, JID_MYRMIDON, 0, FALSE, FACTION_ID_RED, 4, 3, 9, 6, 8, { IID_KILLINGEDGE }, { AI_A_07, AI_B_01, 0x01, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867AA2C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867AA2C[] =
{
    { PID_UNKNOWN_71, JID_CAVALIER, 0, FALSE, FACTION_ID_RED, 2, 21, 10, 21, 10, { 0 }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_71, JID_CAVALIER, 0, FALSE, FACTION_ID_RED, 2, 19, 11, 19, 11, { 0 }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867AA5C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867AA5C[] =
{
    { PID_UNKNOWN_71, JID_PEGASUSKNIGHT, 0, FALSE, FACTION_ID_RED, 5, 20, 9, 20, 9, { 0 }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_71, JID_PEGASUSKNIGHT, 0, FALSE, FACTION_ID_RED, 5, 21, 12, 21, 12, { 0 }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { 0 }, // end
};

// EventScr @ 0867AA8C
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867A70C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867A70C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867AAA0
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867A7FC[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_0867A7FC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867AABC
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867A81C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867A81C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867AAD0
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867A93C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867A93C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867AAE4
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867A96C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867A96C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867AAF8
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867A9BC[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867A9BC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867AB0C
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867A9DC[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867A9DC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867AB20
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867AA2C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867AA2C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867AB34
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867AA5C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867AA5C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 4 summary:
// Units UnitInfo_Unk_0867A70C 1
// Units UnitInfo_Unk_0867A7FC 2
// Units UnitInfo_Unk_0867A81C 1
// Units UnitInfo_Unk_0867A93C 1
// Units UnitInfo_Unk_0867A96C 1
// Units UnitInfo_Unk_0867A9BC 1
// Units UnitInfo_Unk_0867A9DC 1
// Units UnitInfo_Unk_0867AA2C 1
// Units UnitInfo_Unk_0867AA5C 1

// UnitInfo @ 0867AB48
struct UnitInfo CONST_DATA UnitInfo_Unk_0867AB48[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 4, 14, 14, 14, 14, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_MARCUS, JID_PALADIN, PID_ROY, TRUE, FACTION_ID_BLUE, 2, 14, 16, 14, 16, { IID_SILVERLANCE, IID_IRONSWORD, IID_IRONLANCE }, { 0 } },
    { PID_ALEN, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 4, 13, 13, 13, 13, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN }, { 0 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 4, 13, 15, 13, 15, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 3, 12, 14, 12, 14, { IID_IRONLANCE, IID_JAVELIN, IID_CHESTKEY }, { 0 } },
    { PID_WOLT, JID_ARCHER, PID_ROY, TRUE, FACTION_ID_BLUE, 3, 15, 16, 15, 16, { IID_IRONBOW, IID_VULNERARY, IID_VULNERARY }, { 0 } },
    { PID_DIECK, JID_MERCENARY, PID_ROY, TRUE, FACTION_ID_BLUE, 6, 16, 11, 16, 11, { IID_IRONBLADE, IID_IRONSWORD, IID_ARMORSLAYER }, { 0 } },
    { PID_WARD, JID_FIGHTER, PID_ROY, TRUE, FACTION_ID_BLUE, 4, 15, 12, 15, 12, { IID_IRONAXE, IID_HAMMER, IID_HANDAXE }, { 0 } },
    { PID_LOT, JID_FIGHTER, PID_ROY, TRUE, FACTION_ID_BLUE, 4, 17, 12, 17, 12, { IID_STEELAXE, IID_HANDAXE, IID_IRONAXE }, { 0 } },
    { PID_SHANNA, JID_PEGASUSKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 3, 16, 15, 16, 15, { IID_SLIMLANCE, IID_JAVELIN, IID_VULNERARY }, { 0 } },
    { PID_ELEN, JID_CLERIC, PID_ROY, TRUE, FACTION_ID_BLUE, 5, 14, 15, 14, 15, { IID_HEALSTAFF, IID_VULNERARY }, { 0 } },
    { PID_CHAD, JID_THIEF, PID_ROY, TRUE, FACTION_ID_BLUE, 2, 15, 14, 15, 14, { IID_IRONSWORD, IID_LOCKPICK }, { 0 } },
    { PID_LUGH, JID_MAGE, PID_ROY, TRUE, FACTION_ID_BLUE, 2, 17, 14, 17, 14, { IID_FIRE, IID_VULNERARY }, { 0 } },
    { PID_CLARINE, JID_TROUBADOUR, PID_ROY, TRUE, FACTION_ID_BLUE, 2, 14, 13, 14, 13, { IID_HEALSTAFF, IID_VULNERARY }, { 0 } },
    { PID_RUTGER, JID_MYRMIDON, PID_ROY, TRUE, FACTION_ID_BLUE, 4, 16, 13, 16, 13, { IID_KILLINGEDGE, IID_IRONSWORD, IID_VULNERARY }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 18, 15, 18, 15, { 0 }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867AC58
struct UnitInfo CONST_DATA UnitInfo_Unk_0867AC58[] =
{
    { PID_UNKNOWN_4E, JID_BRIGAND, 0, FALSE, FACTION_ID_RED, 11, 2, 14, 2, 14, { IID_KILLERAXE, IID_HANDAXE }, { AI_A_03, AI_B_03, 0x00, 0x20 } },
    { PID_UNKNOWN_73, JID_FIGHTER, PID_UNKNOWN_4E, TRUE, FACTION_ID_RED, 4, 14, 7, 14, 7, { IID_IRONAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_73, JID_FIGHTER, PID_UNKNOWN_4E, TRUE, FACTION_ID_RED, 4, 14, 5, 14, 5, { IID_HANDAXE }, { AI_A_00, AI_B_03, 0x04, 0x00 } },
    { PID_UNKNOWN_73, JID_FIGHTER, PID_UNKNOWN_4E, TRUE, FACTION_ID_RED, 5, 11, 5, 11, 5, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_73, JID_FIGHTER, PID_UNKNOWN_4E, TRUE, FACTION_ID_RED, 5, 9, 3, 9, 3, { IID_IRONAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_73, JID_FIGHTER, PID_UNKNOWN_4E, TRUE, FACTION_ID_RED, 5, 7, 4, 7, 4, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_73, JID_FIGHTER, PID_UNKNOWN_4E, TRUE, FACTION_ID_RED, 5, 5, 6, 5, 6, { IID_IRONAXE, IID_HANDAXE }, { AI_A_00, AI_B_03, 0x04, 0x00 } },
    { PID_UNKNOWN_73, JID_FIGHTER, PID_UNKNOWN_4E, TRUE, FACTION_ID_RED, 5, 4, 4, 4, 4, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_73, JID_FIGHTER, PID_UNKNOWN_4E, TRUE, FACTION_ID_RED, 5, 3, 5, 3, 5, { IID_IRONAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_73, JID_MERCENARY, PID_UNKNOWN_4E, TRUE, FACTION_ID_RED, 3, 1, 8, 1, 8, { IID_IRONSWORD }, { AI_A_00, AI_B_06, 0x02, 0x00 } },
    { PID_UNKNOWN_73, JID_MERCENARY, PID_UNKNOWN_4E, TRUE, FACTION_ID_RED, 3, 3, 9, 3, 9, { IID_IRONSWORD }, { AI_A_00, AI_B_06, 0x02, 0x00 } },
    { PID_UNKNOWN_73, JID_BRIGAND, PID_UNKNOWN_4E, TRUE, FACTION_ID_RED, 6, 1, 15, 1, 15, { IID_HANDAXE }, { AI_A_00, AI_B_03, 0x04, 0x00 } },
    { PID_UNKNOWN_73, JID_BRIGAND, PID_UNKNOWN_4E, TRUE, FACTION_ID_RED, 6, 2, 17, 2, 17, { IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_73, JID_BRIGAND, PID_UNKNOWN_4E, TRUE, FACTION_ID_RED, 6, 2, 16, 2, 16, { IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_73, JID_BRIGAND, PID_UNKNOWN_4E, TRUE, FACTION_ID_RED, 6, 3, 15, 3, 15, { IID_HANDAXE }, { AI_A_00, AI_B_03, 0x04, 0x00 } },
    { PID_UNKNOWN_73, JID_MERCENARY, PID_UNKNOWN_4E, TRUE, FACTION_ID_RED, 2, 12, 2, 12, 2, { IID_IRONSWORD }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_73, JID_MERCENARY, PID_UNKNOWN_4E, TRUE, FACTION_ID_RED, 4, 9, 6, 7, 6, { IID_STEELSWORD }, { AI_A_03, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_73, JID_MERCENARY, PID_UNKNOWN_4E, TRUE, FACTION_ID_RED, 4, 2, 10, 2, 10, { IID_STEELSWORD }, { AI_A_00, AI_B_06, 0x02, 0x00 } },
    { PID_UNKNOWN_73, JID_MERCENARY, PID_UNKNOWN_4E, TRUE, FACTION_ID_RED, 5, 3, 18, 3, 18, { IID_STEELBLADE }, { AI_A_00, AI_B_06, 0x0A, 0x00 } },
    { PID_UNKNOWN_73, JID_NOMAD, PID_UNKNOWN_4E, TRUE, FACTION_ID_RED, 3, 4, 11, 4, 11, { IID_IRONBOW }, { AI_A_00, AI_B_03, 0x2A, 0x00 } },
    { PID_UNKNOWN_73, JID_NOMAD, PID_UNKNOWN_4E, TRUE, FACTION_ID_RED, 4, 4, 13, 4, 13, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_73, JID_NOMAD, PID_UNKNOWN_4E, TRUE, FACTION_ID_RED, 3, 1, 11, 1, 11, { IID_IRONBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_73, JID_MAGE, PID_UNKNOWN_4E, TRUE, FACTION_ID_RED, 5, 1, 18, 1, 18, { IID_FIRE }, { AI_A_00, AI_B_06, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867ADD8
struct UnitInfo CONST_DATA UnitInfo_Unk_0867ADD8[] =
{
    { 0 }, // end
};

// UnitInfo @ 0867ADE8
struct UnitInfo CONST_DATA UnitInfo_Unk_0867ADE8[] =
{
    { PID_UNKNOWN_73, JID_BRIGAND, PID_UNKNOWN_4E, TRUE, FACTION_ID_RED, 5, 0, 4, 0, 4, { IID_IRONAXE, IID_HANDAXE }, { AI_A_00, AI_B_04, 0x21, 0x00 } },
    { PID_UNKNOWN_73, JID_BRIGAND, PID_UNKNOWN_4E, TRUE, FACTION_ID_RED, 6, 0, 17, 0, 17, { IID_STEELAXE }, { AI_A_00, AI_B_04, 0x21, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867AE18
struct UnitInfo CONST_DATA UnitInfo_Unk_0867AE18[] =
{
    { PID_UNKNOWN_73, JID_MERCENARY, PID_UNKNOWN_4E, TRUE, FACTION_ID_RED, 4, 2, 15, 5, 16, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_73, JID_MERCENARY, PID_UNKNOWN_4E, TRUE, FACTION_ID_RED, 4, 2, 15, 5, 17, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_73, JID_NOMAD, PID_UNKNOWN_4E, TRUE, FACTION_ID_RED, 3, 2, 15, 4, 17, { IID_IRONBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_73, JID_NOMAD, PID_UNKNOWN_4E, TRUE, FACTION_ID_RED, 4, 2, 15, 4, 16, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867AE68
struct UnitInfo CONST_DATA UnitInfo_Unk_0867AE68[] =
{
    { PID_UNKNOWN_73, JID_BRIGAND, PID_UNKNOWN_4E, TRUE, FACTION_ID_RED, 5, 18, 7, 18, 7, { IID_IRONAXE, IID_HANDAXE }, { AI_A_00, AI_B_04, 0x21, 0x00 } },
    { PID_UNKNOWN_73, JID_BRIGAND, PID_UNKNOWN_4E, TRUE, FACTION_ID_RED, 6, 17, 8, 17, 8, { IID_STEELAXE }, { AI_A_00, AI_B_04, 0x21, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867AE98
struct UnitInfo CONST_DATA UnitInfo_Unk_0867AE98[] =
{
    { PID_SAUL, JID_PRIEST, PID_UNKNOWN_4E, TRUE, FACTION_ID_GREEN, 5, 10, 3, 10, 4, { 0 }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_DOROTHY, JID_ARCHER_F, PID_UNKNOWN_4E, TRUE, FACTION_ID_GREEN, 6, 10, 2, 10, 3, { 0 }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867AEC8
struct UnitInfo CONST_DATA UnitInfo_Unk_0867AEC8[] =
{
    { PID_SAUL, JID_PRIEST, PID_UNKNOWN_4E, TRUE, FACTION_ID_GREEN, 5, 5, 5, 4, 5, { 0 }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_DOROTHY, JID_ARCHER_F, PID_UNKNOWN_4E, TRUE, FACTION_ID_GREEN, 6, 5, 6, 4, 6, { 0 }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { 0 }, // end
};

// EventScr @ 0867AEF8
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867AB48[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867AB48)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867AF0C
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867AC58[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_0867AC58)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867AF28
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867ADD8[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867ADD8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867AF3C
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867ADE8[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867ADE8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867AF50
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867AE18[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867AE18)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867AF64
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867AE68[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867AE68)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867AF78
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867AE98[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867AE98)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867AF8C
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867AEC8[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867AEC8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 5 summary:
// Units UnitInfo_Unk_0867AB48 1
// Units UnitInfo_Unk_0867AC58 2
// Units UnitInfo_Unk_0867ADD8 1
// Units UnitInfo_Unk_0867ADE8 1
// Units UnitInfo_Unk_0867AE18 1
// Units UnitInfo_Unk_0867AE68 1
// Units UnitInfo_Unk_0867AE98 1
// Units UnitInfo_Unk_0867AEC8 1

// UnitInfo @ 0867AFA0
struct UnitInfo CONST_DATA UnitInfo_Unk_0867AFA0[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 8, 12, 20, 12, 20, { IID_RAPIER, IID_IRONSWORD, IID_ARMORSLAYER }, { 0 } },
    { PID_CHAD, JID_THIEF, PID_ROY, TRUE, FACTION_ID_BLUE, 2, 11, 19, 12, 19, { IID_IRONSWORD, IID_SLIMSWORD, IID_LOCKPICK }, { 0 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 7, 13, 19, 13, 19, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 7, 14, 20, 14, 20, { IID_IRONLANCE, IID_JAVELIN, IID_CHESTKEY }, { 0 } },
    { PID_WOLT, JID_ARCHER, PID_ROY, TRUE, FACTION_ID_BLUE, 8, 13, 20, 13, 20, { IID_IRONBOW, IID_VULNERARY, IID_VULNERARY }, { 0 } },
    { PID_DIECK, JID_MERCENARY, PID_ROY, TRUE, FACTION_ID_BLUE, 7, 11, 20, 11, 20, { IID_IRONSWORD, IID_IRONBLADE, IID_VULNERARY }, { 0 } },
    { PID_RUTGER, JID_MYRMIDON, PID_ROY, TRUE, FACTION_ID_BLUE, 6, 14, 21, 14, 21, { IID_IRONSWORD, IID_KILLINGEDGE }, { 0 } },
    { PID_ALEN, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 6, 11, 21, 11, 21, { IID_IRONSWORD, IID_IRONLANCE, IID_VULNERARY }, { 0 } },
    { PID_CLARINE, JID_TROUBADOUR, PID_ROY, TRUE, FACTION_ID_BLUE, 2, 12, 22, 12, 22, { IID_HEALSTAFF, IID_VULNERARY }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 13, 22, 13, 22, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_FIRE }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867B050
struct UnitInfo CONST_DATA UnitInfo_Unk_0867B050[] =
{
    { PID_SAUL, JID_PRIEST, PID_ROY, FALSE, FACTION_ID_BLUE, 5, 11, 23, 11, 23, { IID_MENDSTAFF }, { 0 } },
    { PID_DOROTHY, JID_ARCHER_F, PID_ROY, FALSE, FACTION_ID_BLUE, 3, 14, 23, 14, 23, { IID_STEELBOW, IID_VULNERARY }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867B080
struct UnitInfo CONST_DATA UnitInfo_Unk_0867B080[] =
{
    { PID_UNKNOWN_4F, JID_SHAMAN, 0, FALSE, FACTION_ID_RED, 9, 5, 1, 12, 1, { IID_FLUX }, { AI_A_03, AI_B_03, 0x00, 0x20 } },
    { PID_UNKNOWN_74, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 8, 11, 1, 11, 1, { IID_IRONLANCE, IID_JAVELIN }, { AI_A_03, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_74, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 7, 13, 1, 13, 1, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_03, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_74, JID_MAGE, 0, TRUE, FACTION_ID_RED, 7, 12, 5, 12, 5, { IID_THUNDER }, { AI_A_03, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_74, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 7, 12, 7, 12, 7, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_74, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 10, 13, 7, 13, 7, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_74, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 10, 11, 8, 11, 8, { IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_74, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 9, 12, 8, 12, 8, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_74, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 10, 13, 8, 13, 8, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_74, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 9, 14, 8, 14, 8, { IID_JAVELIN }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_74, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 10, 6, 9, 6, 9, { IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_74, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 9, 19, 9, 19, 9, { IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_74, JID_MAGE, 0, TRUE, FACTION_ID_RED, 4, 12, 9, 12, 9, { IID_FIRE, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_74, JID_MAGE, 0, TRUE, FACTION_ID_RED, 3, 13, 9, 13, 9, { IID_THUNDER, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_74, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 8, 7, 8, 7, 8, { IID_STEELLANCE }, { AI_A_00, AI_B_06, 0x02, 0x00 } },
    { PID_UNKNOWN_74, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 5, 7, 14, 7, 14, { IID_IRONSWORD }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_74, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 7, 18, 8, 18, 8, { IID_JAVELIN }, { AI_A_00, AI_B_06, 0x02, 0x00 } },
    { PID_UNKNOWN_74, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 5, 18, 14, 18, 14, { IID_IRONSWORD }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_74, JID_MAGE, 0, TRUE, FACTION_ID_RED, 4, 10, 2, 10, 2, { IID_FIRE, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_74, JID_MAGE, 0, TRUE, FACTION_ID_RED, 4, 14, 2, 14, 2, { IID_THUNDER, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_74, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 5, 6, 3, 6, 3, { IID_IRONLANCE, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_74, JID_MAGE, 0, TRUE, FACTION_ID_RED, 4, 4, 3, 4, 3, { IID_THUNDER }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_74, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 9, 6, 5, 6, 5, { IID_JAVELIN }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_74, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 9, 4, 5, 4, 5, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_74, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 5, 18, 3, 18, 3, { IID_IRONLANCE, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_74, JID_MAGE, 0, TRUE, FACTION_ID_RED, 4, 20, 3, 20, 3, { IID_FIRE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_74, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 9, 18, 5, 18, 5, { IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_74, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 9, 20, 5, 20, 5, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_SUE, JID_NOMAD_F, 0, FALSE, FACTION_ID_GREEN, 1, 2, 9, 2, 9, { 0 }, { AI_A_00, AI_B_03 } },
    { 0 }, // end
};

// UnitInfo @ 0867B260
struct UnitInfo CONST_DATA UnitInfo_Unk_0867B260[] =
{
    { PID_UNKNOWN_74, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 6, 4, 21, 6, 18, { IID_STEELLANCE }, { AI_A_00, AI_B_03, 0x04, 0x00 } },
    { PID_UNKNOWN_74, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 5, 4, 21, 5, 18, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x2C, 0x00 } },
    { PID_UNKNOWN_74, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 9, 4, 21, 6, 20, { IID_JAVELIN }, { AI_A_00, AI_B_00, 0x04, 0x00 } },
    { PID_UNKNOWN_74, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 9, 4, 21, 5, 20, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x04, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867B2B0
struct UnitInfo CONST_DATA UnitInfo_Unk_0867B2B0[] =
{
    { PID_UNKNOWN_74, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 6, 21, 21, 19, 18, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x04, 0x00 } },
    { PID_UNKNOWN_74, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 5, 21, 21, 20, 18, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x2C, 0x00 } },
    { PID_UNKNOWN_74, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 9, 21, 21, 19, 20, { IID_JAVELIN }, { AI_A_00, AI_B_00, 0x04, 0x00 } },
    { PID_UNKNOWN_74, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 9, 21, 21, 20, 20, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x04, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867B300
struct UnitInfo CONST_DATA UnitInfo_Unk_0867B300[] =
{
    { PID_UNKNOWN_74, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 5, 6, 3, 6, 3, { IID_STEELLANCE }, { AI_A_00, AI_B_03, 0x04, 0x00 } },
    { PID_UNKNOWN_74, JID_MAGE, 0, TRUE, FACTION_ID_RED, 4, 4, 3, 4, 3, { IID_THUNDER }, { AI_A_00, AI_B_03, 0x1C, 0x00 } },
    { PID_UNKNOWN_74, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 9, 6, 5, 6, 5, { IID_JAVELIN }, { AI_A_00, AI_B_03, 0x04, 0x00 } },
    { PID_UNKNOWN_74, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 9, 4, 5, 4, 5, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x04, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867B350
struct UnitInfo CONST_DATA UnitInfo_Unk_0867B350[] =
{
    { PID_UNKNOWN_74, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 5, 18, 3, 18, 3, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x04, 0x00 } },
    { PID_UNKNOWN_74, JID_MAGE, 0, TRUE, FACTION_ID_RED, 4, 20, 3, 20, 3, { IID_FIRE }, { AI_A_00, AI_B_00, 0x1C, 0x00 } },
    { PID_UNKNOWN_74, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 9, 18, 5, 18, 5, { IID_JAVELIN }, { AI_A_00, AI_B_00, 0x04, 0x00 } },
    { PID_UNKNOWN_74, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 9, 20, 5, 20, 5, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x04, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867B3A0
struct UnitInfo CONST_DATA UnitInfo_Unk_0867B3A0[] =
{
    { PID_UNKNOWN_74, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 6, 8, 23, 8, 23, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_74, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 10, 18, 23, 18, 23, { IID_JAVELIN }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867B3D0
struct UnitInfo CONST_DATA UnitInfo_Unk_0867B3D0[] =
{
    { PID_CATH, JID_THIEF_F, 0, FALSE, FACTION_ID_RED, 5, 17, 23, 17, 23, { IID_IRONSWORD, IID_LOCKPICK, IID_VULNERARY }, { AI_A_06, AI_B_05, 0x13, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867B3F0
struct UnitInfo CONST_DATA UnitInfo_Unk_0867B3F0[] =
{
    { PID_UNKNOWN_74, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 5, 9, 0, 9, 1, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x04, 0x00 } },
    { PID_UNKNOWN_74, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 4, 10, 0, 10, 1, { IID_IRONBOW }, { AI_A_00, AI_B_00, 0x1C, 0x00 } },
    { PID_UNKNOWN_74, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 9, 14, 0, 14, 1, { IID_JAVELIN }, { AI_A_00, AI_B_00, 0x04, 0x00 } },
    { PID_UNKNOWN_74, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 9, 15, 0, 15, 1, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x04, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867B440
struct UnitInfo CONST_DATA UnitInfo_Unk_0867B440[] =
{
    { PID_UNKNOWN_74, JID_MAGE, 0, TRUE, FACTION_ID_RED, 5, 9, 0, 9, 1, { IID_FIRE }, { AI_A_00, AI_B_00, 0x04, 0x00 } },
    { PID_UNKNOWN_74, JID_MAGE, 0, TRUE, FACTION_ID_RED, 4, 10, 0, 10, 1, { IID_THUNDER }, { AI_A_00, AI_B_00, 0x1C, 0x00 } },
    { PID_UNKNOWN_74, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 9, 14, 0, 14, 1, { IID_JAVELIN }, { AI_A_00, AI_B_00, 0x04, 0x00 } },
    { PID_UNKNOWN_74, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 9, 15, 0, 15, 1, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x04, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867B490
struct UnitInfo CONST_DATA UnitInfo_Unk_0867B490[] =
{
    { PID_UNKNOWN_74, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 5, 9, 0, 9, 1, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x04, 0x00 } },
    { PID_UNKNOWN_74, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 4, 10, 0, 10, 1, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x1C, 0x00 } },
    { PID_UNKNOWN_74, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 9, 14, 0, 14, 1, { IID_JAVELIN }, { AI_A_00, AI_B_00, 0x04, 0x00 } },
    { PID_UNKNOWN_74, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 9, 15, 0, 15, 1, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x04, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867B4E0
struct UnitInfo CONST_DATA UnitInfo_Unk_0867B4E0[] =
{
    { PID_UNKNOWN_74, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 5, 13, 23, 13, 22, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x04, 0x00 } },
    { PID_UNKNOWN_74, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 4, 12, 23, 12, 22, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x2C, 0x00 } },
    { PID_UNKNOWN_74, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 8, 14, 23, 14, 22, { IID_JAVELIN }, { AI_A_00, AI_B_00, 0x04, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867B520
struct UnitInfo CONST_DATA UnitInfo_Unk_0867B520[] =
{
    { PID_UNKNOWN_74, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 8, 11, 23, 12, 22, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x04, 0x00 } },
    { PID_UNKNOWN_74, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 8, 15, 23, 14, 22, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x04, 0x00 } },
    { PID_UNKNOWN_74, JID_MAGE, 0, TRUE, FACTION_ID_RED, 3, 10, 23, 13, 22, { IID_FIRE }, { AI_A_00, AI_B_00, 0x1C, 0x00 } },
    { 0 }, // end
};

// EventScr @ 0867B560
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867AFA0[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867AFA0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867B574
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867B050[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867B050)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867B588
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867B080[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_0867B080)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867B5A4
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867B260[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867B260)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867B5B8
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867B2B0[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867B2B0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867B5CC
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867B300[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867B300)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867B5E0
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867B350[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867B350)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867B5F4
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867B3A0[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867B3A0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867B608
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867B3D0[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867B3D0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867B61C
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867B3F0[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867B3F0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867B630
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867B440[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867B440)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867B644
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867B490[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867B490)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867B658
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867B4E0[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867B4E0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867B66C
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867B520[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867B520)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 6 summary:
// Units UnitInfo_Unk_0867AFA0 1
// Units UnitInfo_Unk_0867B050 1
// Units UnitInfo_Unk_0867B080 2
// Units UnitInfo_Unk_0867B260 1
// Units UnitInfo_Unk_0867B2B0 1
// Units UnitInfo_Unk_0867B300 1
// Units UnitInfo_Unk_0867B350 1
// Units UnitInfo_Unk_0867B3A0 1
// Units UnitInfo_Unk_0867B3D0 1
// Units UnitInfo_Unk_0867B3F0 1
// Units UnitInfo_Unk_0867B440 1
// Units UnitInfo_Unk_0867B490 1
// Units UnitInfo_Unk_0867B4E0 1
// Units UnitInfo_Unk_0867B520 1

// UnitInfo @ 0867B680
struct UnitInfo CONST_DATA UnitInfo_Unk_0867B680[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 6, 6, 24, 6, 24, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_MARCUS, JID_PALADIN, PID_ROY, TRUE, FACTION_ID_BLUE, 3, 5, 22, 5, 22, { IID_SILVERLANCE, IID_IRONSWORD, IID_IRONLANCE, IID_HORSESLAYER }, { 0 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 6, 6, 22, 6, 22, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 4, 7, 22, 7, 22, { IID_IRONLANCE, IID_JAVELIN, IID_CHESTKEY }, { 0 } },
    { PID_WOLT, JID_ARCHER, PID_ROY, TRUE, FACTION_ID_BLUE, 5, 4, 23, 4, 23, { IID_IRONBOW, IID_SILVERBOW, IID_VULNERARY }, { 0 } },
    { PID_DIECK, JID_MERCENARY, PID_ROY, TRUE, FACTION_ID_BLUE, 8, 6, 23, 6, 23, { IID_IRONBLADE, IID_IRONSWORD, IID_ARMORSLAYER }, { 0 } },
    { PID_WARD, JID_FIGHTER, PID_ROY, TRUE, FACTION_ID_BLUE, 5, 8, 23, 8, 23, { IID_IRONAXE, IID_HAMMER, IID_HANDAXE }, { 0 } },
    { PID_SHANNA, JID_PEGASUSKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 5, 5, 24, 5, 24, { IID_SLIMLANCE, IID_JAVELIN, IID_VULNERARY }, { 0 } },
    { PID_ELEN, JID_CLERIC, PID_ROY, TRUE, FACTION_ID_BLUE, 7, 7, 24, 7, 24, { IID_HEALSTAFF, IID_UNLOCKSTAFF, IID_VULNERARY }, { 0 } },
    { PID_CHAD, JID_THIEF, PID_ROY, TRUE, FACTION_ID_BLUE, 3, 6, 27, 6, 27, { IID_IRONSWORD, IID_LOCKPICK }, { 0 } },
    { PID_LUGH, JID_MAGE, PID_ROY, TRUE, FACTION_ID_BLUE, 3, 5, 25, 5, 25, { IID_FIRE, IID_VULNERARY }, { 0 } },
    { PID_CLARINE, JID_TROUBADOUR, PID_ROY, TRUE, FACTION_ID_BLUE, 4, 7, 25, 7, 25, { IID_HEALSTAFF, IID_VULNERARY }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 6, 26, 6, 26, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_FIRE }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867B760
struct UnitInfo CONST_DATA UnitInfo_Unk_0867B760[] =
{
    { PID_UNKNOWN_50, JID_ARMOR, 0, FALSE, FACTION_ID_RED, 13, 5, 1, 5, 1, { IID_SPEAR }, { AI_A_03, AI_B_03, 0x00, 0x20 } },
    { PID_UNKNOWN_76, JID_WYVERNRIDER, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 9, 3, 6, 3, 6, { IID_STEELLANCE }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_UNKNOWN_76, JID_WYVERNRIDER, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 10, 9, 6, 9, 6, { IID_STEELLANCE, IID_REDGEM }, { AI_A_00, AI_B_03, 0x09, 0x00 } },
    { PID_UNKNOWN_75, JID_PRIEST, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 7, 8, 8, 8, 8, { IID_PHYSICSTAFF, IID_VULNERARY }, { AI_A_0E, AI_B_03, 0x10, 0x00 } },
    { PID_UNKNOWN_75, JID_PRIEST, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 7, 11, 8, 11, 8, { IID_PHYSICSTAFF, IID_VULNERARY }, { AI_A_0E, AI_B_03, 0x10, 0x00 } },
    { PID_UNKNOWN_75, JID_MERCENARY, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 6, 3, 14, 3, 14, { IID_IRONSWORD }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_75, JID_MERCENARY, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 6, 11, 14, 11, 14, { IID_IRONSWORD }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_75, JID_ARMOR, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 7, 3, 18, 3, 18, { IID_JAVELIN }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_75, JID_ARMOR, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 6, 11, 18, 11, 18, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_75, JID_ARMOR, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 6, 4, 11, 4, 11, { IID_JAVELIN, IID_VULNERARY }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_75, JID_ARMOR, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 6, 10, 11, 10, 11, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_75, JID_MAGE, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 6, 6, 5, 6, 5, { IID_ELFIRE }, { AI_A_00, AI_B_00, 0x19, 0x00 } },
    { PID_UNKNOWN_75, JID_MAGE, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 6, 15, 8, 15, 8, { IID_THUNDER }, { AI_A_00, AI_B_00, 0x19, 0x00 } },
    { PID_UNKNOWN_75, JID_CAVALIER, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 9, 5, 10, 5, 10, { IID_STEELSWORD, IID_JAVELIN }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_75, JID_CAVALIER, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 9, 8, 10, 8, 10, { IID_STEELSWORD, IID_JAVELIN }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_75, JID_CAVALIER, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 7, 0, 9, 0, 9, { IID_IRONSWORD, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_75, JID_SOLDIER, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 11, 17, 13, 17, 13, { IID_JAVELIN, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_75, JID_SOLDIER, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 11, 17, 19, 17, 19, { IID_JAVELIN, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_75, JID_ARCHER, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 7, 19, 16, 19, 16, { IID_STEELBOW }, { AI_A_00, AI_B_03, 0x28, 0x00 } },
    { PID_UNKNOWN_75, JID_ARCHER, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 8, 19, 22, 19, 22, { IID_STEELBOW }, { AI_A_00, AI_B_03, 0x28, 0x00 } },
    { PID_UNKNOWN_75, JID_ARCHER, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 10, 0, 13, 0, 13, { IID_IRONBOW }, { AI_A_00, AI_B_00, 0x28, 0x00 } },
    { PID_UNKNOWN_75, JID_ARCHER, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 9, 19, 13, 19, 13, { IID_IRONBOW }, { AI_A_00, AI_B_00, 0x28, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867B8D0
struct UnitInfo CONST_DATA UnitInfo_Unk_0867B8D0[] =
{
    { PID_UNKNOWN_76, JID_WYVERNRIDER, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 8, 13, 6, 13, 6, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_UNKNOWN_75, JID_CAVALIER, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 7, 6, 12, 6, 12, { IID_IRONSWORD, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_75, JID_CAVALIER, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 7, 6, 14, 6, 14, { IID_IRONSWORD, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_75, JID_ARMOR, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 7, 17, 16, 17, 16, { IID_JAVELIN }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_75, JID_ARMOR, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 7, 17, 22, 17, 22, { IID_JAVELIN }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867B930
struct UnitInfo CONST_DATA UnitInfo_Unk_0867B930[] =
{
    { PID_ZELOT, JID_PALADIN, PID_ROY, FALSE, FACTION_ID_GREEN, 1, 13, 15, 13, 16, { IID_STEELSWORD, IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x69, 0x00 } },
    { PID_TREC, JID_CAVALIER, PID_ROY, FALSE, FACTION_ID_GREEN, 4, 13, 15, 14, 16, { IID_IRONLANCE, IID_JAVELIN, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x68, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867B960
struct UnitInfo CONST_DATA UnitInfo_Unk_0867B960[] =
{
    { PID_NOAH, JID_CAVALIER, PID_ROY, FALSE, FACTION_ID_GREEN, 7, 6, 16, 6, 19, { IID_STEELSWORD, IID_IRONLANCE, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x68, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867B980
struct UnitInfo CONST_DATA UnitInfo_Unk_0867B980[] =
{
    { PID_UNKNOWN_75, JID_MAGE, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 7, 3, 0, 3, 0, { IID_ELFIRE }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_75, JID_ARCHER, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 9, 2, 0, 2, 0, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_75, JID_SOLDIER, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 11, 1, 0, 1, 0, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_75, JID_SOLDIER, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 11, 0, 0, 0, 0, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_75, JID_MAGE, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 7, 7, 0, 7, 0, { IID_THUNDER }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_75, JID_ARCHER, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 7, 8, 0, 8, 0, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_75, JID_SOLDIER, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 11, 9, 0, 9, 0, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_75, JID_SOLDIER, PID_UNKNOWN_50, TRUE, FACTION_ID_RED, 11, 10, 0, 10, 0, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867BA10
struct UnitInfo CONST_DATA UnitInfo_Unk_0867BA10[] =
{
    { PID_UNKNOWN_C9, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 15, 7, 27, 6, 26, { IID_SILVERLANCE }, { AI_A_00, AI_B_00, 0x08, 0x00 } },
    { PID_UNKNOWN_75, JID_CAVALIER, PID_UNKNOWN_C9, TRUE, FACTION_ID_RED, 7, 6, 27, 5, 26, { IID_IRONLANCE, IID_JAVELIN }, { AI_A_0D, AI_B_00, 0x08, 0x00 } },
    { PID_UNKNOWN_75, JID_CAVALIER, PID_UNKNOWN_C9, TRUE, FACTION_ID_RED, 5, 8, 27, 7, 26, { IID_STEELLANCE }, { AI_A_0D, AI_B_00, 0x08, 0x00 } },
    { PID_UNKNOWN_75, JID_CAVALIER, PID_UNKNOWN_C9, TRUE, FACTION_ID_RED, 5, 9, 27, 8, 26, { IID_STEELLANCE }, { AI_A_0D, AI_B_00, 0x08, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867BA60
struct UnitInfo CONST_DATA UnitInfo_Unk_0867BA60[] =
{
    { PID_UNKNOWN_51, JID_GENERAL, 0, FALSE, FACTION_ID_RED, 12, 11, 0, 5, 1, { IID_KILLERLANCE, IID_JAVELIN }, { AI_A_03, AI_B_03, 0x00, 0x20 } },
    { 0 }, // end
};

// UnitInfo @ 0867BA80
struct UnitInfo CONST_DATA UnitInfo_Unk_0867BA80[] =
{
    { PID_FIR, JID_MYRMIDON_F, 0, FALSE, FACTION_ID_GREEN, 12, 6, 16, 6, 17, { IID_KILLERLANCE, IID_JAVELIN }, { AI_A_03, AI_B_03, 0x00, 0x20 } },
    { 0 }, // end
};

// EventScr @ 0867BAA0
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867B680[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867B680)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867BAB4
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867B760[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_0867B760)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867BAD0
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867B8D0[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867B8D0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867BAE4
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867B930[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867B930)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867BAF8
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867B960[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867B960)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867BB0C
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867B980[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867B980)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867BB20
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867BA10[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867BA10)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867BB34
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867BA60[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867BA60)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867BB48
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867BA80[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867BA80)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 7 summary:
// Units UnitInfo_Unk_0867B680 1
// Units UnitInfo_Unk_0867B760 2
// Units UnitInfo_Unk_0867B8D0 1
// Units UnitInfo_Unk_0867B930 1
// Units UnitInfo_Unk_0867B960 1
// Units UnitInfo_Unk_0867B980 1
// Units UnitInfo_Unk_0867BA10 1
// Units UnitInfo_Unk_0867BA60 1
// Units UnitInfo_Unk_0867BA80 1

// UnitInfo @ 0867BB5C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867BB5C[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 7, 26, 19, 26, 19, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_MARCUS, JID_PALADIN, PID_ROY, TRUE, FACTION_ID_BLUE, 4, 28, 19, 26, 17, { IID_SILVERLANCE, IID_IRONSWORD, IID_IRONLANCE, IID_HORSESLAYER }, { 0 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 8, 24, 19, 26, 18, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 5, 26, 17, 27, 18, { IID_IRONLANCE, IID_JAVELIN, IID_CHESTKEY }, { 0 } },
    { PID_WOLT, JID_ARCHER, PID_ROY, TRUE, FACTION_ID_BLUE, 6, 26, 18, 24, 19, { IID_IRONBOW, IID_SILVERBOW, IID_VULNERARY, IID_STEELBOW }, { 0 } },
    { PID_DIECK, JID_MERCENARY, PID_ROY, TRUE, FACTION_ID_BLUE, 10, 27, 18, 28, 19, { IID_IRONBLADE, IID_IRONSWORD, IID_ARMORSLAYER, IID_STEELSWORD }, { 0 } },
    { PID_WARD, JID_FIGHTER, PID_ROY, TRUE, FACTION_ID_BLUE, 6, 27, 20, 24, 20, { IID_IRONAXE, IID_HAMMER, IID_HANDAXE, IID_STEELAXE }, { 0 } },
    { PID_SHANNA, JID_PEGASUSKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 7, 28, 20, 25, 20, { IID_SLIMLANCE, IID_JAVELIN, IID_VULNERARY }, { 0 } },
    { PID_ELEN, JID_CLERIC, PID_ROY, TRUE, FACTION_ID_BLUE, 9, 27, 21, 27, 20, { IID_HEALSTAFF, IID_UNLOCKSTAFF, IID_RESTORESTAFF, IID_VULNERARY }, { 0 } },
    { PID_CHAD, JID_THIEF, PID_ROY, TRUE, FACTION_ID_BLUE, 4, 24, 20, 28, 20, { IID_IRONSWORD, IID_LOCKPICK }, { 0 } },
    { PID_LUGH, JID_MAGE, PID_ROY, TRUE, FACTION_ID_BLUE, 4, 25, 20, 25, 21, { IID_FIRE, IID_THUNDER, IID_VULNERARY }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 27, 21, 27, 21, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_FIRE }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867BC2C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867BC2C[] =
{
    { PID_ASTOLFO, JID_THIEF, PID_ROY, FALSE, FACTION_ID_BLUE, 10, 25, 18, 25, 18, { IID_IRONSWORD, IID_LOCKPICK }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867BC4C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867BC4C[] =
{
    { PID_UNKNOWN_51, JID_GENERAL, 0, FALSE, FACTION_ID_RED, 1, 6, 17, 6, 17, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_03, AI_B_03, 0x01, 0x20 } },
    { PID_UNKNOWN_77, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 12, 26, 9, 26, 9, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_77, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 12, 28, 9, 28, 9, { IID_IRONLANCE, IID_JAVELIN }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_77, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 8, 27, 7, 27, 7, { IID_STEELBOW, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_77, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 7, 18, 5, 18, 5, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_77, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 11, 20, 2, 20, 2, { IID_IRONLANCE, IID_JAVELIN, IID_DOORKEY }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_77, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 12, 20, 3, 20, 3, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_77, JID_MAGE, 0, TRUE, FACTION_ID_RED, 7, 19, 5, 19, 5, { IID_FIRE, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_77, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 8, 12, 1, 12, 1, { IID_HORSESLAYER, IID_CHESTKEY, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x38, 0x00 } },
    { PID_UNKNOWN_77, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 12, 10, 3, 10, 3, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_77, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 11, 10, 5, 10, 5, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_77, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 10, 10, 0, 10, 0, { IID_STEELBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_77, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 11, 3, 11, 3, 11, { IID_STEELLANCE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_77, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 11, 5, 12, 5, 12, { IID_IRONLANCE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_77, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 10, 13, 14, 13, 14, { IID_STEELBOW, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_77, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 11, 11, 14, 11, 14, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_77, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 10, 3, 12, 3, 12, { IID_STEELBOW, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x29, 0x00 } },
    { PID_UNKNOWN_77, JID_SOLDIER, 0, TRUE, FACTION_ID_RED, 11, 4, 8, 4, 8, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_77, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 10, 4, 5, 4, 5, { IID_STEELBOW, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_77, JID_MAGE, 0, TRUE, FACTION_ID_RED, 8, 1, 7, 1, 7, { IID_ELFIRE, IID_DOORKEY }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_77, JID_MAGE, 0, TRUE, FACTION_ID_RED, 7, 7, 8, 7, 8, { IID_FIRE }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_77, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 8, 4, 14, 4, 14, { IID_STEELLANCE }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_77, JID_MAGE, 0, TRUE, FACTION_ID_RED, 8, 6, 14, 6, 14, { IID_THUNDER }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_77, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 8, 5, 11, 5, 11, { IID_STEELLANCE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_77, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 9, 20, 11, 20, 11, { IID_IRONBOW }, { AI_A_00, AI_B_0F, 0x51, 0x00 } },
    { PID_UNKNOWN_77, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 8, 17, 22, 17, 22, { IID_KILLERLANCE, IID_CHESTKEY }, { AI_A_00, AI_B_03, 0x09, 0x00 } },
    { PID_UNKNOWN_77, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 8, 6, 19, 6, 19, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_03, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_77, JID_MAGE, 0, TRUE, FACTION_ID_RED, 7, 8, 18, 8, 18, { IID_AIRCALIBUR }, { AI_A_00, AI_B_03, 0x09, 0x00 } },
    { PID_UNKNOWN_77, JID_MAGE, 0, TRUE, FACTION_ID_RED, 7, 4, 18, 4, 18, { IID_ELFIRE, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867BE2C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867BE2C[] =
{
    { PID_UNKNOWN_79, JID_THIEF, 0, TRUE, FACTION_ID_RED, 6, 15, 17, 15, 18, { IID_IRONSWORD, IID_LOCKPICK }, { AI_A_06, AI_B_05, 0x11, 0x00 } },
    { PID_CATH, JID_THIEF_F, 0, FALSE, FACTION_ID_RED, 5, 20, 17, 20, 18, { IID_IRONSWORD, IID_LOCKPICK, IID_VULNERARY }, { AI_A_06, AI_B_05, 0x13, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867BE5C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867BE5C[] =
{
    { PID_UNKNOWN_77, JID_ARCHER, PID_UNKNOWN_51, TRUE, FACTION_ID_RED, 8, 15, 17, 15, 17, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x51, 0x00 } },
    { PID_UNKNOWN_77, JID_MERCENARY, PID_UNKNOWN_51, TRUE, FACTION_ID_RED, 9, 20, 17, 20, 17, { IID_IRONSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_77, JID_SOLDIER, PID_UNKNOWN_51, TRUE, FACTION_ID_RED, 11, 0, 23, 0, 23, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_77, JID_SOLDIER, PID_UNKNOWN_51, TRUE, FACTION_ID_RED, 10, 0, 18, 0, 18, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867BEAC
struct UnitInfo CONST_DATA UnitInfo_Unk_0867BEAC[] =
{
    { PID_UNKNOWN_77, JID_ARCHER, PID_UNKNOWN_51, TRUE, FACTION_ID_RED, 8, 15, 17, 15, 17, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x51, 0x00 } },
    { PID_UNKNOWN_77, JID_MERCENARY, PID_UNKNOWN_51, TRUE, FACTION_ID_RED, 9, 20, 17, 20, 17, { IID_IRONSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_77, JID_ARMOR, PID_UNKNOWN_51, TRUE, FACTION_ID_RED, 11, 0, 23, 0, 23, { IID_STEELLANCE, IID_JAVELIN, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_77, JID_SOLDIER, PID_UNKNOWN_51, TRUE, FACTION_ID_RED, 10, 0, 18, 0, 18, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867BEFC
struct UnitInfo CONST_DATA UnitInfo_Unk_0867BEFC[] =
{
    { PID_UNKNOWN_77, JID_ARCHER, PID_UNKNOWN_51, TRUE, FACTION_ID_RED, 8, 0, 0, 1, 1, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x51, 0x00 } },
    { PID_UNKNOWN_77, JID_MERCENARY, PID_UNKNOWN_51, TRUE, FACTION_ID_RED, 10, 0, 1, 1, 2, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_77, JID_SOLDIER, PID_UNKNOWN_51, TRUE, FACTION_ID_RED, 11, 0, 1, 0, 2, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867BF3C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867BF3C[] =
{
    { PID_UNKNOWN_77, JID_ARCHER, PID_UNKNOWN_51, TRUE, FACTION_ID_RED, 8, 0, 0, 1, 1, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x51, 0x00 } },
    { PID_UNKNOWN_77, JID_MERCENARY, PID_UNKNOWN_51, TRUE, FACTION_ID_RED, 10, 0, 1, 1, 2, { IID_ARMORSLAYER }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_77, JID_SOLDIER, PID_UNKNOWN_51, TRUE, FACTION_ID_RED, 11, 0, 1, 0, 2, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867BF7C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867BF7C[] =
{
    { PID_LILINA, JID_MAGE_F, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 18, 10, 18, 10, { 0 }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867BF9C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867BF9C[] =
{
    { PID_GWENDOLYN, JID_ARMOR_F, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 1, 0, 4, 0, { IID_IRONLANCE, IID_JAVELIN, IID_VULNERARY }, { 0 } },
    { PID_BARTHE, JID_ARMOR, PID_ROY, FALSE, FACTION_ID_BLUE, 9, 0, 1, 4, 1, { IID_STEELLANCE }, { 0 } },
    { PID_OGIER, JID_MERCENARY, PID_ROY, FALSE, FACTION_ID_BLUE, 3, 2, 2, 5, 2, { IID_STEELSWORD, IID_ARMORSLAYER, IID_VULNERARY }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867BFDC
struct UnitInfo CONST_DATA UnitInfo_Unk_0867BFDC[] =
{
    { PID_ROY, JID_ROY, 0, FALSE, FACTION_ID_BLUE, 6, 6, 5, 6, 5, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867BFFC
struct UnitInfo CONST_DATA UnitInfo_Unk_0867BFFC[] =
{
    { PID_NARCIAN, JID_WYVERNLORD, PID_NARCIAN, FALSE, FACTION_ID_RED, 6, 6, 21, 6, 21, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x51, 0x00 } },
    { PID_UNKNOWN_77, JID_WYVERNRIDER, PID_NARCIAN, TRUE, FACTION_ID_RED, 9, 5, 19, 5, 19, { IID_IRONSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_77, JID_WYVERNRIDER, PID_NARCIAN, TRUE, FACTION_ID_RED, 10, 3, 19, 3, 19, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_77, JID_WYVERNRIDER, PID_NARCIAN, TRUE, FACTION_ID_RED, 6, 1, 19, 1, 19, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_UNKNOWN_77, JID_WYVERNRIDER, PID_NARCIAN, TRUE, FACTION_ID_RED, 6, 7, 19, 7, 19, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x51, 0x00 } },
    { PID_UNKNOWN_77, JID_WYVERNRIDER, PID_NARCIAN, TRUE, FACTION_ID_RED, 11, 9, 19, 9, 19, { IID_STEELLANCE, IID_JAVELIN, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_77, JID_WYVERNRIDER, PID_NARCIAN, TRUE, FACTION_ID_RED, 10, 11, 19, 11, 19, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867C07C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867C07C[] =
{
    { PID_PERCEVAL, JID_PALADIN, 0, FALSE, FACTION_ID_GREEN, 6, 6, 25, 6, 21, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867C09C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867C09C[] =
{
    { PID_CECILIA, JID_VALKYRIE, 0, FALSE, FACTION_ID_GREEN, 6, 7, 25, 7, 22, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867C0BC
struct UnitInfo CONST_DATA UnitInfo_Unk_0867C0BC[] =
{
    { PID_UNKNOWN_77, JID_CAVALIER, 0, FALSE, FACTION_ID_GREEN, 6, 5, 25, 5, 23, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_UNKNOWN_77, JID_CAVALIER, 0, FALSE, FACTION_ID_GREEN, 6, 8, 25, 7, 23, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_UNKNOWN_77, JID_MAGE, 0, FALSE, FACTION_ID_GREEN, 6, 15, 19, 14, 19, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_UNKNOWN_77, JID_MAGE, 0, FALSE, FACTION_ID_GREEN, 6, 0, 19, 2, 19, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867C10C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867C10C[] =
{
    { PID_UNKNOWN_77, JID_VALKYRIE, 0, FALSE, FACTION_ID_GREEN, 6, 5, 25, 3, 23, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_UNKNOWN_77, JID_VALKYRIE, 0, FALSE, FACTION_ID_GREEN, 6, 8, 25, 9, 23, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_UNKNOWN_77, JID_MAGE, 0, FALSE, FACTION_ID_GREEN, 6, 0, 22, 2, 22, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_UNKNOWN_77, JID_MAGE, 0, FALSE, FACTION_ID_GREEN, 6, 15, 22, 14, 22, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867C15C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867C15C[] =
{
    { PID_UNKNOWN_77, JID_CAVALIER, 0, FALSE, FACTION_ID_GREEN, 6, 5, 25, 4, 23, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_UNKNOWN_77, JID_CAVALIER, 0, FALSE, FACTION_ID_GREEN, 6, 8, 25, 8, 23, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_UNKNOWN_77, JID_MAGE, 0, FALSE, FACTION_ID_GREEN, 6, 0, 19, 1, 19, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_UNKNOWN_77, JID_MAGE, 0, FALSE, FACTION_ID_GREEN, 6, 0, 25, 2, 25, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867C1AC
struct UnitInfo CONST_DATA UnitInfo_Unk_0867C1AC[] =
{
    { PID_UNKNOWN_77, JID_VALKYRIE, 0, FALSE, FACTION_ID_GREEN, 6, 5, 25, 6, 23, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_UNKNOWN_77, JID_VALKYRIE, 0, FALSE, FACTION_ID_GREEN, 6, 8, 25, 10, 23, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_UNKNOWN_77, JID_MAGE, 0, FALSE, FACTION_ID_GREEN, 6, 0, 18, 1, 18, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867C1EC
struct UnitInfo CONST_DATA UnitInfo_Unk_0867C1EC[] =
{
    { 0 }, // end
};

// UnitInfo @ 0867C1FC
struct UnitInfo CONST_DATA UnitInfo_Unk_0867C1FC[] =
{
    { 0 }, // end
};

// EventScr @ 0867C20C
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867BB5C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867BB5C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867C220
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867BC2C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867BC2C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867C234
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867BC4C[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_0867BC4C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867C250
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867BE2C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867BE2C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867C264
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867BE5C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867BE5C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867C278
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867BEAC[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867BEAC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867C28C
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867BEFC[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867BEFC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867C2A0
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867BF3C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867BF3C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867C2B4
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867BF7C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867BF7C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867C2C8
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867BF9C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867BF9C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867C2DC
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867BFDC[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867BFDC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867C2F0
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867BFFC[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867BFFC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867C304
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867C07C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867C07C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867C318
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867C09C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867C09C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867C32C
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867C0BC[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867C0BC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867C340
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867C10C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867C10C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867C354
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867C15C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867C15C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867C368
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867C1AC[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867C1AC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867C37C
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867C1EC[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867C1EC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867C390
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867C1FC[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867C1FC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 8 summary:
// Units UnitInfo_Unk_0867BB5C 1
// Units UnitInfo_Unk_0867BC2C 1
// Units UnitInfo_Unk_0867BC4C 2
// Units UnitInfo_Unk_0867BE2C 1
// Units UnitInfo_Unk_0867BE5C 1
// Units UnitInfo_Unk_0867BEAC 1
// Units UnitInfo_Unk_0867BEFC 1
// Units UnitInfo_Unk_0867BF3C 1
// Units UnitInfo_Unk_0867BF7C 1
// Units UnitInfo_Unk_0867BF9C 1
// Units UnitInfo_Unk_0867BFDC 1
// Units UnitInfo_Unk_0867BFFC 1
// Units UnitInfo_Unk_0867C07C 1
// Units UnitInfo_Unk_0867C09C 1
// Units UnitInfo_Unk_0867C0BC 1
// Units UnitInfo_Unk_0867C10C 1
// Units UnitInfo_Unk_0867C15C 1
// Units UnitInfo_Unk_0867C1AC 1
// Units UnitInfo_Unk_0867C1EC 1
// Units UnitInfo_Unk_0867C1FC 1

// UnitInfo @ 0867C3A4
struct UnitInfo CONST_DATA UnitInfo_Unk_0867C3A4[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 8, 19, 13, 19, 13, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_MARCUS, JID_PALADIN, PID_ROY, TRUE, FACTION_ID_BLUE, 4, 18, 12, 18, 12, { IID_SILVERLANCE, IID_IRONSWORD, IID_IRONLANCE, IID_HORSESLAYER }, { 0 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 9, 20, 12, 20, 12, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 5, 17, 13, 17, 13, { IID_IRONLANCE, IID_JAVELIN, IID_CHESTKEY }, { 0 } },
    { PID_DOROTHY, JID_ARCHER_F, PID_ROY, TRUE, FACTION_ID_BLUE, 7, 18, 13, 18, 13, { IID_IRONBOW, IID_SILVERBOW, IID_VULNERARY, IID_STEELBOW }, { 0 } },
    { PID_DIECK, JID_MERCENARY, PID_ROY, TRUE, FACTION_ID_BLUE, 11, 20, 13, 20, 13, { IID_IRONBLADE, IID_IRONSWORD, IID_ARMORSLAYER, IID_STEELSWORD }, { 0 } },
    { PID_WARD, JID_FIGHTER, PID_ROY, TRUE, FACTION_ID_BLUE, 7, 21, 13, 21, 13, { IID_IRONAXE, IID_HAMMER, IID_HANDAXE, IID_STEELAXE }, { 0 } },
    { PID_SHANNA, JID_PEGASUSKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 8, 17, 14, 17, 14, { IID_SLIMLANCE, IID_JAVELIN, IID_VULNERARY }, { 0 } },
    { PID_ELEN, JID_CLERIC, PID_ROY, TRUE, FACTION_ID_BLUE, 10, 18, 14, 18, 14, { IID_HEALSTAFF, IID_UNLOCKSTAFF, IID_RESTORESTAFF, IID_VULNERARY }, { 0 } },
    { PID_NOAH, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 9, 18, 15, 18, 15, { IID_IRONSWORD, IID_STEELLANCE, IID_JAVELIN }, { 0 } },
    { PID_LUGH, JID_MAGE, PID_ROY, TRUE, FACTION_ID_BLUE, 5, 20, 14, 20, 14, { IID_FIRE, IID_THUNDER, IID_VULNERARY }, { 0 } },
    { PID_SUE, JID_NOMAD_F, PID_ROY, TRUE, FACTION_ID_BLUE, 6, 21, 14, 21, 14, { IID_IRONBOW, IID_TORCH, IID_LONGBOW, IID_ANTITOXIN }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 20, 15, 20, 15, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_RESTORESTAFF }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867C484
struct UnitInfo CONST_DATA UnitInfo_Unk_0867C484[] =
{
    { PID_UNKNOWN_52, JID_BERSERKER, 0, FALSE, FACTION_ID_RED, 3, 2, 3, 2, 3, { IID_KILLERAXE, IID_HANDAXE }, { AI_A_03, AI_B_03, 0x02, 0x20 } },
    { PID_UNKNOWN_7A, JID_PIRATE, PID_UNKNOWN_52, TRUE, FACTION_ID_RED, 8, 17, 20, 17, 20, { IID_STEELAXE, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_7A, JID_PIRATE, PID_UNKNOWN_52, TRUE, FACTION_ID_RED, 8, 15, 18, 15, 18, { IID_HANDAXE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_7A, JID_FIGHTER, PID_UNKNOWN_52, TRUE, FACTION_ID_RED, 9, 10, 7, 10, 7, { IID_HANDAXE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_7A, JID_FIGHTER, PID_UNKNOWN_52, TRUE, FACTION_ID_RED, 9, 9, 12, 9, 12, { IID_POISONAXE }, { AI_A_00, AI_B_03, 0x22, 0x00 } },
    { PID_UNKNOWN_7A, JID_FIGHTER, PID_UNKNOWN_52, TRUE, FACTION_ID_RED, 9, 10, 10, 10, 10, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_7A, JID_ARCHER, PID_UNKNOWN_52, TRUE, FACTION_ID_RED, 11, 11, 8, 11, 8, { IID_STEELBOW, IID_ANTITOXIN }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_7A, JID_MERCENARY, PID_UNKNOWN_52, TRUE, FACTION_ID_RED, 10, 8, 10, 8, 10, { IID_STEELSWORD }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_7A, JID_MERCENARY, PID_UNKNOWN_52, TRUE, FACTION_ID_RED, 8, 11, 7, 11, 7, { IID_IRONSWORD, IID_ANTITOXIN }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_7A, JID_FIGHTER, PID_UNKNOWN_52, TRUE, FACTION_ID_RED, 11, 9, 15, 9, 15, { IID_POISONAXE }, { AI_A_00, AI_B_03, 0x22, 0x00 } },
    { PID_UNKNOWN_7A, JID_ARCHER, PID_UNKNOWN_52, TRUE, FACTION_ID_RED, 9, 8, 16, 8, 16, { IID_STEELBOW }, { AI_A_00, AI_B_03, 0x2A, 0x00 } },
    { PID_UNKNOWN_7A, JID_PIRATE, PID_UNKNOWN_52, TRUE, FACTION_ID_RED, 10, 10, 20, 10, 20, { IID_HANDAXE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_7A, JID_PIRATE, PID_UNKNOWN_52, TRUE, FACTION_ID_RED, 10, 8, 20, 8, 20, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_7A, JID_MAGE, PID_UNKNOWN_52, TRUE, FACTION_ID_RED, 10, 9, 20, 9, 20, { IID_THUNDER }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_7A, JID_PIRATE, PID_UNKNOWN_52, TRUE, FACTION_ID_RED, 11, 4, 21, 4, 21, { IID_POISONAXE }, { AI_A_00, AI_B_06, 0x22, 0x00 } },
    { PID_UNKNOWN_7A, JID_PIRATE, PID_UNKNOWN_52, TRUE, FACTION_ID_RED, 11, 5, 23, 5, 23, { IID_STEELAXE }, { AI_A_00, AI_B_06, 0x02, 0x00 } },
    { PID_UNKNOWN_7A, JID_ARCHER, PID_UNKNOWN_52, TRUE, FACTION_ID_RED, 12, 4, 22, 4, 22, { IID_STEELBOW }, { AI_A_00, AI_B_06, 0x2A, 0x00 } },
    { PID_UNKNOWN_7A, JID_MERCENARY, PID_UNKNOWN_52, TRUE, FACTION_ID_RED, 12, 0, 2, 0, 2, { IID_STEELSWORD }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_7A, JID_MAGE, PID_UNKNOWN_52, TRUE, FACTION_ID_RED, 9, 2, 0, 2, 0, { IID_ELFIRE, IID_VULNERARY }, { AI_A_00, AI_B_06, 0x02, 0x00 } },
    { PID_UNKNOWN_7A, JID_ARCHER, PID_UNKNOWN_52, TRUE, FACTION_ID_RED, 12, 0, 13, 0, 11, { IID_STEELBOW }, { AI_A_00, AI_B_06, 0x2A, 0x00 } },
    { PID_UNKNOWN_7A, JID_MERCENARY, PID_UNKNOWN_52, TRUE, FACTION_ID_RED, 12, 0, 12, 0, 10, { IID_STEELSWORD }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_7A, JID_MAGE, PID_UNKNOWN_52, TRUE, FACTION_ID_RED, 9, 1, 13, 1, 11, { IID_ELFIRE, IID_VULNERARY }, { AI_A_00, AI_B_06, 0x02, 0x00 } },
    { PID_UNKNOWN_7A, JID_ARCHER, PID_UNKNOWN_52, TRUE, FACTION_ID_RED, 12, 14, 3, 14, 3, { IID_IRONBOW }, { AI_A_00, AI_B_03, 0x2A, 0x00 } },
    { PID_UNKNOWN_7A, JID_FIGHTER, PID_UNKNOWN_52, TRUE, FACTION_ID_RED, 12, 13, 2, 13, 2, { IID_STEELAXE }, { AI_A_00, AI_B_06, 0x3A, 0x00 } },
    { PID_UNKNOWN_7A, JID_FIGHTER, PID_UNKNOWN_52, TRUE, FACTION_ID_RED, 12, 17, 3, 17, 3, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_03, 0x22, 0x00 } },
    { PID_UNKNOWN_7A, JID_FIGHTER, PID_UNKNOWN_52, TRUE, FACTION_ID_RED, 12, 20, 3, 20, 3, { IID_POISONAXE, IID_ANTITOXIN }, { AI_A_00, AI_B_06, 0x3A, 0x00 } },
    { PID_UNKNOWN_7A, JID_FIGHTER, PID_UNKNOWN_52, TRUE, FACTION_ID_RED, 12, 14, 0, 14, 0, { IID_HALBERD }, { AI_A_00, AI_B_03, 0x2A, 0x00 } },
    { PID_UNKNOWN_7A, JID_ARCHER, PID_UNKNOWN_52, TRUE, FACTION_ID_RED, 11, 17, 5, 17, 5, { IID_IRONBOW }, { AI_A_00, AI_B_06, 0x2A, 0x00 } },
    { PID_UNKNOWN_7A, JID_ARCHER, PID_UNKNOWN_52, TRUE, FACTION_ID_RED, 11, 20, 5, 20, 5, { IID_IRONBOW }, { AI_A_00, AI_B_03 } },
    { 0 }, // end
};

// UnitInfo @ 0867C664
struct UnitInfo CONST_DATA UnitInfo_Unk_0867C664[] =
{
    { PID_UNKNOWN_7B, JID_PIRATE, 0, TRUE, FACTION_ID_RED, 10, 5, 15, 5, 15, { IID_STEELAXE }, { AI_A_00, AI_B_04, 0x22, 0x00 } },
    { PID_UNKNOWN_7B, JID_PIRATE, 0, TRUE, FACTION_ID_RED, 10, 5, 13, 5, 13, { IID_HANDAXE }, { AI_A_00, AI_B_04, 0x22, 0x00 } },
    { PID_UNKNOWN_7B, JID_PIRATE, 0, TRUE, FACTION_ID_RED, 11, 7, 5, 7, 5, { IID_POISONAXE, IID_ANTITOXIN }, { AI_A_00, AI_B_04, 0x22, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867C6A4
struct UnitInfo CONST_DATA UnitInfo_Unk_0867C6A4[] =
{
    { PID_UNKNOWN_7A, JID_FIGHTER, PID_UNKNOWN_52, TRUE, FACTION_ID_RED, 12, 3, 0, 3, 0, { IID_POISONAXE, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_7A, JID_FIGHTER, PID_UNKNOWN_52, TRUE, FACTION_ID_RED, 13, 5, 0, 5, 0, { IID_HANDAXE }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_7A, JID_ARCHER, PID_UNKNOWN_52, TRUE, FACTION_ID_RED, 11, 15, 0, 15, 0, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867C6E4
struct UnitInfo CONST_DATA UnitInfo_Unk_0867C6E4[] =
{
    { PID_FIR, JID_MYRMIDON_F, PID_UNKNOWN_52, FALSE, FACTION_ID_RED, 1, 0, 10, 1, 10, { IID_WODAO, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x20, 0x00 } },
    { PID_SIN, JID_NOMAD, PID_UNKNOWN_52, FALSE, FACTION_ID_RED, 5, 0, 5, 0, 7, { IID_SHORTBOW }, { AI_A_00, AI_B_03, 0x21, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867C714
struct UnitInfo CONST_DATA UnitInfo_Unk_0867C714[] =
{
    { PID_CECILIA, JID_VALKYRIE, PID_UNKNOWN_52, FALSE, FACTION_ID_GREEN, 1, 19, 16, 19, 16, { IID_WODAO, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x20, 0x00 } },
    { PID_GUINIVERE, JID_SAGE_F, PID_UNKNOWN_52, FALSE, FACTION_ID_GREEN, 1, 18, 16, 18, 16, { IID_WODAO, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x20, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867C744
struct UnitInfo CONST_DATA UnitInfo_Unk_0867C744[] =
{
    { PID_WOLT, JID_ARCHER, PID_ROY, FALSE, FACTION_ID_BLUE, 3, 17, 5, 17, 5, { IID_IRONBOW }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, FALSE, FACTION_ID_BLUE, 9, 14, 1, 14, 1, { 0 }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_SHANNA, JID_PEGASUSKNIGHT, PID_ROY, FALSE, FACTION_ID_BLUE, 8, 19, 6, 19, 6, { 0 }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_DIECK, JID_MERCENARY, PID_ROY, FALSE, FACTION_ID_BLUE, 11, 13, 5, 13, 5, { 0 }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_7B, JID_PIRATE, 0, FALSE, FACTION_ID_RED, 5, 7, 5, 7, 5, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_7B, JID_PIRATE, 0, FALSE, FACTION_ID_RED, 5, 10, 7, 10, 7, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_7A, JID_ARCHER, 0, FALSE, FACTION_ID_RED, 4, 8, 7, 8, 7, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_7B, JID_PIRATE, 0, FALSE, FACTION_ID_RED, 5, 12, 8, 12, 8, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_7B, JID_PIRATE, 0, FALSE, FACTION_ID_RED, 5, 13, 9, 13, 9, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_7B, JID_PIRATE, 0, FALSE, FACTION_ID_RED, 5, 6, 1, 6, 1, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_7B, JID_PIRATE, 0, FALSE, FACTION_ID_RED, 5, 8, 2, 8, 2, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { 0 }, // end
};

// EventScr @ 0867C804
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867C3A4[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867C3A4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867C818
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867C484[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_0867C484)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867C834
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867C664[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867C664)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867C848
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867C6A4[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867C6A4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867C85C
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867C6E4[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867C6E4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867C870
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867C714[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867C714)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867C884
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867C744[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867C744)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 9 summary:
// Units UnitInfo_Unk_0867C3A4 1
// Units UnitInfo_Unk_0867C484 2
// Units UnitInfo_Unk_0867C664 1
// Units UnitInfo_Unk_0867C6A4 1
// Units UnitInfo_Unk_0867C6E4 1
// Units UnitInfo_Unk_0867C714 1
// Units UnitInfo_Unk_0867C744 1

// UnitInfo @ 0867C898
struct UnitInfo CONST_DATA UnitInfo_Unk_0867C898[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 9, 12, 4, 12, 4, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 10, 9, 3, 9, 3, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 6, 11, 3, 11, 3, { IID_IRONLANCE, IID_JAVELIN, IID_CHESTKEY }, { 0 } },
    { PID_WOLT, JID_ARCHER, PID_ROY, TRUE, FACTION_ID_BLUE, 8, 9, 4, 9, 4, { IID_IRONBOW, IID_SILVERBOW, IID_VULNERARY, IID_STEELBOW }, { 0 } },
    { PID_DIECK, JID_MERCENARY, PID_ROY, TRUE, FACTION_ID_BLUE, 12, 10, 4, 10, 4, { IID_IRONBLADE, IID_IRONSWORD, IID_ARMORSLAYER, IID_STEELSWORD }, { 0 } },
    { PID_WARD, JID_FIGHTER, PID_ROY, TRUE, FACTION_ID_BLUE, 8, 8, 5, 8, 5, { IID_IRONAXE, IID_HAMMER, IID_HANDAXE, IID_STEELAXE }, { 0 } },
    { PID_SHANNA, JID_PEGASUSKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 9, 10, 5, 10, 5, { IID_SLIMLANCE, IID_JAVELIN, IID_VULNERARY }, { 0 } },
    { PID_ELEN, JID_CLERIC, PID_ROY, TRUE, FACTION_ID_BLUE, 11, 11, 5, 11, 5, { IID_HEALSTAFF, IID_UNLOCKSTAFF, IID_RESTORESTAFF, IID_VULNERARY }, { 0 } },
    { PID_LILINA, JID_MAGE_F, PID_ROY, TRUE, FACTION_ID_BLUE, 7, 5, 7, 5, 7, { IID_FIRE, IID_THUNDER, IID_VULNERARY }, { 0 } },
    { PID_SUE, JID_NOMAD_F, PID_ROY, TRUE, FACTION_ID_BLUE, 8, 6, 5, 6, 5, { IID_IRONBOW, IID_LONGBOW, IID_ANTITOXIN, IID_PUREWATER }, { 0 } },
    { PID_FIR, JID_MYRMIDON_F, PID_ROY, TRUE, FACTION_ID_BLUE, 2, 6, 6, 6, 6, { IID_WODAO, IID_IRONSWORD, 0, IID_STEELSWORD }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 7, 7, 7, 7, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_RESTORESTAFF }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867C968
struct UnitInfo CONST_DATA UnitInfo_Unk_0867C968[] =
{
    { PID_UNKNOWN_53, JID_DRUID, 0, FALSE, FACTION_ID_RED, 5, 18, 29, 18, 29, { IID_NOSFERATU }, { AI_A_03, AI_B_03, 0x00, 0x20 } },
    { PID_UNKNOWN_7C, JID_FIGHTER, PID_UNKNOWN_53, TRUE, FACTION_ID_RED, 10, 11, 10, 11, 10, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_7C, JID_FIGHTER, PID_UNKNOWN_53, TRUE, FACTION_ID_RED, 10, 13, 10, 13, 10, { IID_HANDAXE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_7C, JID_FIGHTER, PID_UNKNOWN_53, TRUE, FACTION_ID_RED, 11, 11, 11, 11, 11, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_7C, JID_FIGHTER, PID_UNKNOWN_53, TRUE, FACTION_ID_RED, 11, 13, 11, 13, 11, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_7C, JID_MERCENARY, PID_UNKNOWN_53, TRUE, FACTION_ID_RED, 11, 11, 12, 11, 12, { IID_STEELSWORD, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_7C, JID_MERCENARY, PID_UNKNOWN_53, TRUE, FACTION_ID_RED, 12, 13, 12, 13, 12, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_7C, JID_MERCENARY, PID_UNKNOWN_53, TRUE, FACTION_ID_RED, 11, 10, 13, 10, 13, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_7C, JID_FIGHTER, PID_UNKNOWN_53, TRUE, FACTION_ID_RED, 14, 12, 13, 12, 13, { IID_HALBERD, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_7C, JID_ARCHER, PID_UNKNOWN_53, TRUE, FACTION_ID_RED, 10, 14, 13, 14, 13, { IID_IRONBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_7C, JID_MERCENARY, PID_UNKNOWN_53, TRUE, FACTION_ID_RED, 10, 12, 18, 12, 18, { IID_KILLINGEDGE }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_7C, JID_FIGHTER, PID_UNKNOWN_53, TRUE, FACTION_ID_RED, 12, 11, 19, 11, 19, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_7C, JID_FIGHTER, PID_UNKNOWN_53, TRUE, FACTION_ID_RED, 11, 13, 19, 13, 19, { IID_IRONAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_7C, JID_FIGHTER, PID_UNKNOWN_53, TRUE, FACTION_ID_RED, 11, 11, 20, 11, 20, { IID_IRONAXE, IID_HANDAXE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_7C, JID_FIGHTER, PID_UNKNOWN_53, TRUE, FACTION_ID_RED, 11, 13, 20, 13, 20, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_7C, JID_MERCENARY, PID_UNKNOWN_53, TRUE, FACTION_ID_RED, 12, 10, 19, 10, 19, { IID_STEELSWORD }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_7C, JID_MERCENARY, PID_UNKNOWN_53, TRUE, FACTION_ID_RED, 11, 14, 19, 14, 19, { IID_STEELSWORD }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_7C, JID_MERCENARY, PID_UNKNOWN_53, TRUE, FACTION_ID_RED, 11, 14, 22, 14, 22, { IID_STEELSWORD }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_7C, JID_BERSERKER, PID_UNKNOWN_53, TRUE, FACTION_ID_RED, 1, 12, 21, 12, 21, { IID_STEELAXE, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_7C, JID_ARCHER, PID_UNKNOWN_53, TRUE, FACTION_ID_RED, 13, 10, 22, 10, 22, { IID_IRONBOW }, { AI_A_00, AI_B_06, 0x2A, 0x00 } },
    { PID_UNKNOWN_7C, JID_SHAMAN, PID_UNKNOWN_53, TRUE, FACTION_ID_RED, 12, 14, 30, 14, 30, { IID_FLUX }, { AI_A_00, AI_B_00, 0x08, 0x00 } },
    { PID_UNKNOWN_7C, JID_SHAMAN, PID_UNKNOWN_53, TRUE, FACTION_ID_RED, 12, 19, 30, 19, 30, { IID_NOSFERATU }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_7C, JID_ARCHER, PID_UNKNOWN_53, TRUE, FACTION_ID_RED, 10, 6, 19, 6, 19, { IID_IRONBOW }, { AI_A_03, AI_B_03, 0x29, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867CAE8
struct UnitInfo CONST_DATA UnitInfo_Unk_0867CAE8[] =
{
    { PID_UNKNOWN_7D, JID_PIRATE, 0, TRUE, FACTION_ID_RED, 11, 0, 16, 0, 16, { IID_POISONAXE, IID_ANTITOXIN }, { AI_A_00, AI_B_04, 0x02, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867CB08
struct UnitInfo CONST_DATA UnitInfo_Unk_0867CB08[] =
{
    { PID_UNKNOWN_7D, JID_PIRATE, 0, TRUE, FACTION_ID_RED, 13, 0, 16, 0, 16, { IID_HAMMER }, { AI_A_00, AI_B_04, 0x02, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867CB28
struct UnitInfo CONST_DATA UnitInfo_Unk_0867CB28[] =
{
    { PID_UNKNOWN_7D, JID_PIRATE, 0, TRUE, FACTION_ID_RED, 12, 0, 16, 0, 16, { IID_STEELAXE }, { AI_A_00, AI_B_04, 0x02, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867CB48
struct UnitInfo CONST_DATA UnitInfo_Unk_0867CB48[] =
{
    { PID_UNKNOWN_7C, JID_FIGHTER, PID_UNKNOWN_53, TRUE, FACTION_ID_RED, 12, 9, 31, 9, 31, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_7C, JID_FIGHTER, PID_UNKNOWN_53, TRUE, FACTION_ID_RED, 13, 11, 31, 11, 31, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867CB78
struct UnitInfo CONST_DATA UnitInfo_Unk_0867CB78[] =
{
    { PID_BARTRE, JID_WARRIOR, 0, FALSE, FACTION_ID_GREEN, 1, 9, 1, 9, 1, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x6A, 0x00 } },
    { PID_UNKNOWN_7E, JID_FIGHTER, 0, TRUE, FACTION_ID_GREEN, 12, 10, 1, 10, 1, { IID_IRONAXE }, { AI_A_00, AI_B_00, 0x6A, 0x00 } },
    { PID_UNKNOWN_7E, JID_FIGHTER, 0, TRUE, FACTION_ID_GREEN, 12, 11, 0, 11, 0, { IID_HANDAXE }, { AI_A_00, AI_B_00, 0x6A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867CBB8
struct UnitInfo CONST_DATA UnitInfo_Unk_0867CBB8[] =
{
    { PID_GONZALEZ, JID_BRIGAND, PID_UNKNOWN_53, FALSE, FACTION_ID_RED, 5, 18, 30, 18, 31, { IID_DEVILAXE, IID_VULNERARY }, { AI_A_00, AI_B_04, 0x23, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867CBD8
struct UnitInfo CONST_DATA UnitInfo_Unk_0867CBD8[] =
{
    { PID_GEESE, JID_PIRATE, PID_UNKNOWN_53, FALSE, FACTION_ID_GREEN, 10, 18, 15, 18, 12, { IID_BRAVEAXE }, { AI_A_00, AI_B_00, 0x69, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867CBF8
struct UnitInfo CONST_DATA UnitInfo_Unk_0867CBF8[] =
{
    { 0 }, // end
};

// UnitInfo @ 0867CC08
struct UnitInfo CONST_DATA UnitInfo_Unk_0867CC08[] =
{
    { PID_WOLT, JID_ARCHER, PID_ROY, FALSE, FACTION_ID_BLUE, 3, 8, 20, 8, 20, { IID_IRONBOW }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, FALSE, FACTION_ID_BLUE, 9, 12, 19, 12, 19, { 0 }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_SHANNA, JID_PEGASUSKNIGHT, PID_ROY, FALSE, FACTION_ID_BLUE, 8, 11, 16, 11, 16, { 0 }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_DIECK, JID_MERCENARY, PID_ROY, FALSE, FACTION_ID_BLUE, 11, 6, 17, 6, 17, { 0 }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_7B, JID_PIRATE, 0, FALSE, FACTION_ID_RED, 5, 2, 17, 2, 17, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_7B, JID_PIRATE, 0, FALSE, FACTION_ID_RED, 5, 3, 15, 3, 15, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_7A, JID_ARCHER, 0, FALSE, FACTION_ID_RED, 4, 10, 22, 10, 22, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_7B, JID_PIRATE, 0, FALSE, FACTION_ID_RED, 5, 9, 23, 9, 23, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_7B, JID_PIRATE, 0, FALSE, FACTION_ID_RED, 5, 12, 23, 12, 23, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_7B, JID_PIRATE, 0, FALSE, FACTION_ID_RED, 5, 14, 21, 14, 21, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_7B, JID_PIRATE, 0, FALSE, FACTION_ID_RED, 5, 9, 26, 9, 26, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { 0 }, // end
};

// EventScr @ 0867CCC8
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867C898[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867C898)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867CCDC
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867C968[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_0867C968)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867CCF8
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867CAE8[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867CAE8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867CD0C
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867CB08[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867CB08)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867CD20
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867CB28[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867CB28)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867CD34
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867CB48[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867CB48)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867CD48
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867CB78[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867CB78)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867CD5C
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867CBB8[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867CBB8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867CD70
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867CBD8[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867CBD8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867CD84
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867CBF8[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867CBF8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867CD98
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867CC08[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867CC08)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 10 summary:
// Units UnitInfo_Unk_0867C898 1
// Units UnitInfo_Unk_0867C968 2
// Units UnitInfo_Unk_0867CAE8 1
// Units UnitInfo_Unk_0867CB08 1
// Units UnitInfo_Unk_0867CB28 1
// Units UnitInfo_Unk_0867CB48 1
// Units UnitInfo_Unk_0867CB78 1
// Units UnitInfo_Unk_0867CBB8 1
// Units UnitInfo_Unk_0867CBD8 1
// Units UnitInfo_Unk_0867CBF8 1
// Units UnitInfo_Unk_0867CC08 1

// UnitInfo @ 0867CDAC
struct UnitInfo CONST_DATA UnitInfo_Unk_0867CDAC[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 12, 5, 5, 5, 5, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_CLARINE, JID_TROUBADOUR, PID_ROY, TRUE, FACTION_ID_BLUE, 13, 2, 3, 2, 3, { IID_HEALSTAFF, IID_UNLOCKSTAFF, IID_RESTORESTAFF, IID_VULNERARY }, { 0 } },
    { PID_ALEN, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 13, 4, 3, 4, 3, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 9, 5, 3, 5, 3, { IID_IRONLANCE, IID_JAVELIN, IID_CHESTKEY }, { 0 } },
    { PID_WOLT, JID_ARCHER, PID_ROY, TRUE, FACTION_ID_BLUE, 12, 7, 3, 7, 3, { IID_IRONBOW, IID_SILVERBOW, IID_VULNERARY, IID_STEELBOW }, { 0 } },
    { PID_DIECK, JID_MERCENARY, PID_ROY, TRUE, FACTION_ID_BLUE, 15, 3, 4, 3, 4, { IID_IRONBLADE, IID_IRONSWORD, IID_ARMORSLAYER, IID_STEELSWORD }, { 0 } },
    { PID_LOT, JID_FIGHTER, PID_ROY, TRUE, FACTION_ID_BLUE, 11, 6, 4, 6, 4, { IID_IRONAXE, IID_HAMMER, IID_HANDAXE, IID_STEELAXE }, { 0 } },
    { PID_SHANNA, JID_PEGASUSKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 13, 2, 5, 2, 5, { IID_SLIMLANCE, IID_JAVELIN, IID_VULNERARY }, { 0 } },
    { PID_CHAD, JID_THIEF, PID_ROY, TRUE, FACTION_ID_BLUE, 9, 4, 5, 4, 5, { IID_IRONSWORD, IID_LOCKPICK }, { 0 } },
    { PID_LUGH, JID_MAGE, PID_ROY, TRUE, FACTION_ID_BLUE, 11, 3, 6, 3, 6, { IID_FIRE, IID_THUNDER, IID_VULNERARY }, { 0 } },
    { PID_SUE, JID_NOMAD_F, PID_ROY, TRUE, FACTION_ID_BLUE, 11, 6, 6, 6, 6, { IID_IRONBOW, IID_LONGBOW, IID_ANTITOXIN, IID_PUREWATER }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 5, 7, 5, 7, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_RESTORESTAFF }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867CE7C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867CE7C[] =
{
    { PID_LARUM, JID_DANCER, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 2, 6, 2, 7, { IID_VULNERARY }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867CE9C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867CE9C[] =
{
    { PID_UNKNOWN_56, JID_BISHOP, 0, FALSE, FACTION_ID_RED, 8, 27, 2, 27, 2, { IID_DIVINE }, { AI_A_03, AI_B_03, 0x01, 0x20 } },
    { PID_UNKNOWN_7F, JID_FIGHTER, PID_UNKNOWN_56, TRUE, FACTION_ID_RED, 13, 3, 16, 3, 16, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_7F, JID_FIGHTER, PID_UNKNOWN_56, TRUE, FACTION_ID_RED, 14, 8, 16, 8, 16, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_7F, JID_FIGHTER, PID_UNKNOWN_56, TRUE, FACTION_ID_RED, 13, 8, 19, 8, 19, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_7F, JID_ARCHER, PID_UNKNOWN_56, TRUE, FACTION_ID_RED, 13, 13, 16, 13, 16, { IID_STEELBOW }, { AI_A_00, AI_B_03, 0x29, 0x00 } },
    { PID_UNKNOWN_7F, JID_SHAMAN, PID_UNKNOWN_56, TRUE, FACTION_ID_RED, 14, 15, 19, 15, 19, { IID_FLUX }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_7F, JID_FIGHTER, PID_UNKNOWN_56, TRUE, FACTION_ID_RED, 15, 20, 16, 20, 16, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_7F, JID_FIGHTER, PID_UNKNOWN_56, TRUE, FACTION_ID_RED, 15, 22, 16, 22, 16, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_7F, JID_FIGHTER, PID_UNKNOWN_56, TRUE, FACTION_ID_RED, 14, 21, 17, 21, 17, { IID_IRONAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_7F, JID_ARCHER, PID_UNKNOWN_56, TRUE, FACTION_ID_RED, 15, 21, 10, 21, 10, { IID_STEELBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_7F, JID_FIGHTER, PID_UNKNOWN_56, TRUE, FACTION_ID_RED, 15, 20, 7, 20, 7, { IID_STEELAXE }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_7F, JID_FIGHTER, PID_UNKNOWN_56, TRUE, FACTION_ID_RED, 14, 22, 7, 22, 7, { IID_HANDAXE }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_7F, JID_FIGHTER, PID_UNKNOWN_56, TRUE, FACTION_ID_RED, 14, 22, 9, 22, 9, { IID_HANDAXE }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_7F, JID_FIGHTER, PID_UNKNOWN_56, TRUE, FACTION_ID_RED, 14, 20, 9, 20, 9, { IID_STEELAXE }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_7F, JID_FIGHTER, PID_UNKNOWN_56, TRUE, FACTION_ID_RED, 15, 21, 8, 21, 8, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_7F, JID_ARCHER, PID_UNKNOWN_56, TRUE, FACTION_ID_RED, 14, 21, 6, 21, 6, { IID_KILLERBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_7F, JID_SHAMAN, PID_UNKNOWN_56, TRUE, FACTION_ID_RED, 16, 26, 3, 26, 3, { IID_FLUX }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_7F, JID_SHAMAN, PID_UNKNOWN_56, TRUE, FACTION_ID_RED, 16, 28, 3, 28, 3, { IID_FLUX }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_7F, JID_ARCHER, PID_UNKNOWN_56, TRUE, FACTION_ID_RED, 14, 14, 6, 14, 6, { IID_STEELBOW }, { AI_A_00, AI_B_03, 0x29, 0x00 } },
    { PID_UNKNOWN_7F, JID_ARCHER, PID_UNKNOWN_56, TRUE, FACTION_ID_RED, 14, 14, 11, 14, 11, { IID_LONGBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_7F, JID_ARCHER, PID_UNKNOWN_56, TRUE, FACTION_ID_RED, 14, 14, 23, 14, 23, { IID_LONGBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_7F, JID_FIGHTER, PID_UNKNOWN_56, TRUE, FACTION_ID_RED, 16, 8, 23, 8, 23, { IID_HALBERD }, { AI_A_00, AI_B_03, 0x39, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867D00C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867D00C[] =
{
    { PID_UNKNOWN_56, JID_BISHOP, 0, FALSE, FACTION_ID_RED, 8, 27, 2, 27, 2, { IID_DIVINE }, { AI_A_03, AI_B_03, 0x01, 0x20 } },
    { 0 }, // end
};

// UnitInfo @ 0867D02C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867D02C[] =
{
    { PID_UNKNOWN_7F, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 19, 3, 0, 3, 1, { IID_KILLERLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_7F, JID_CAVALIER, PID_UNKNOWN_57, TRUE, FACTION_ID_RED, 15, 1, 0, 1, 2, { IID_IRONLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_7F, JID_CAVALIER, PID_UNKNOWN_57, TRUE, FACTION_ID_RED, 15, 2, 0, 2, 2, { IID_IRONLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_7F, JID_CAVALIER, PID_UNKNOWN_57, TRUE, FACTION_ID_RED, 14, 4, 0, 3, 2, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867D07C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867D07C[] =
{
    { PID_UNKNOWN_7F, JID_CAVALIER, PID_UNKNOWN_57, TRUE, FACTION_ID_RED, 14, 4, 0, 4, 2, { IID_IRONLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_7F, JID_CAVALIER, PID_UNKNOWN_57, TRUE, FACTION_ID_RED, 15, 5, 0, 5, 2, { IID_IRONLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_7F, JID_CAVALIER, PID_UNKNOWN_57, TRUE, FACTION_ID_RED, 14, 3, 0, 3, 3, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867D0BC
struct UnitInfo CONST_DATA UnitInfo_Unk_0867D0BC[] =
{
    { PID_UNKNOWN_82, JID_BRIGAND, 0, TRUE, FACTION_ID_RED, 14, 26, 9, 26, 9, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_04, 0x0A, 0x00 } },
    { PID_UNKNOWN_82, JID_BRIGAND, 0, TRUE, FACTION_ID_RED, 15, 27, 15, 27, 15, { IID_STEELAXE }, { AI_A_00, AI_B_04, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867D0EC
struct UnitInfo CONST_DATA UnitInfo_Unk_0867D0EC[] =
{
    { PID_UNKNOWN_82, JID_BRIGAND, 0, TRUE, FACTION_ID_RED, 14, 26, 9, 26, 9, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_04, 0x0A, 0x00 } },
    { PID_UNKNOWN_82, JID_BRIGAND, 0, TRUE, FACTION_ID_RED, 15, 27, 15, 27, 15, { IID_STEELAXE }, { AI_A_00, AI_B_04, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867D11C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867D11C[] =
{
    { PID_ECHIDNA, JID_HERO_F, 0, FALSE, FACTION_ID_GREEN, 1, 18, 10, 18, 11, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x69, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867D13C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867D13C[] =
{
    { PID_UNKNOWN_7F, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 17, 16, 10, 16, 11, { IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_7F, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 15, 20, 12, 18, 12, { IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_7F, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 15, 20, 10, 20, 11, { IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867D17C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867D17C[] =
{
    { PID_UNKNOWN_57, JID_PALADIN, 0, TRUE, FACTION_ID_RED, 1, 20, 25, 20, 25, { IID_SILVERLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_7F, JID_CAVALIER, PID_UNKNOWN_57, TRUE, FACTION_ID_RED, 15, 18, 24, 18, 24, { IID_IRONLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_7F, JID_CAVALIER, PID_UNKNOWN_57, TRUE, FACTION_ID_RED, 15, 19, 24, 19, 24, { IID_IRONLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_7F, JID_CAVALIER, PID_UNKNOWN_57, TRUE, FACTION_ID_RED, 14, 20, 24, 20, 24, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867D1CC
struct UnitInfo CONST_DATA UnitInfo_Unk_0867D1CC[] =
{
    { PID_UNKNOWN_7F, JID_CAVALIER, PID_UNKNOWN_57, TRUE, FACTION_ID_RED, 14, 21, 24, 21, 24, { IID_IRONLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_7F, JID_CAVALIER, PID_UNKNOWN_57, TRUE, FACTION_ID_RED, 15, 22, 24, 22, 24, { IID_IRONLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_7F, JID_CAVALIER, PID_UNKNOWN_57, TRUE, FACTION_ID_RED, 14, 23, 24, 23, 24, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867D20C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867D20C[] =
{
    { PID_KLEIN, JID_SNIPER, 0, FALSE, FACTION_ID_RED, 1, 22, 25, 22, 24, { IID_SILVERBOW, IID_WHITEGEM }, { AI_A_01, AI_B_00, 0x29, 0x00 } },
    { PID_KLEIN_SQUAD, JID_ARCHER, PID_KLEIN, TRUE, FACTION_ID_RED, 14, 21, 24, 21, 23, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_KLEIN_SQUAD, JID_ARCHER, PID_KLEIN, TRUE, FACTION_ID_RED, 14, 23, 24, 23, 23, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867D24C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867D24C[] =
{
    { PID_KLEIN_SQUAD, JID_ARCHER, PID_KLEIN, TRUE, FACTION_ID_RED, 14, 20, 25, 21, 25, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_KLEIN_SQUAD, JID_ARCHER, PID_KLEIN, TRUE, FACTION_ID_RED, 15, 24, 25, 23, 25, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867D27C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867D27C[] =
{
    { PID_THEA, JID_PEGASUSKNIGHT, 0, FALSE, FACTION_ID_RED, 8, 2, 0, 2, 1, { IID_SLIMLANCE, IID_JAVELIN }, { AI_A_01, AI_B_00, 0x69, 0x00 } },
    { PID_THEA_SQUAD, JID_PEGASUSKNIGHT, PID_THEA, TRUE, FACTION_ID_RED, 6, 0, 0, 1, 0, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x69, 0x00 } },
    { PID_THEA_SQUAD, JID_PEGASUSKNIGHT, PID_THEA, TRUE, FACTION_ID_RED, 6, 4, 0, 3, 0, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x69, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867D2BC
struct UnitInfo CONST_DATA UnitInfo_Unk_0867D2BC[] =
{
    { PID_THEA_SQUAD, JID_PEGASUSKNIGHT, PID_THEA, TRUE, FACTION_ID_RED, 6, 1, 1, 2, 2, { IID_IRONLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x69, 0x00 } },
    { PID_THEA_SQUAD, JID_PEGASUSKNIGHT, PID_THEA, TRUE, FACTION_ID_RED, 6, 5, 1, 3, 2, { IID_IRONLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x69, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867D2EC
struct UnitInfo CONST_DATA UnitInfo_Unk_0867D2EC[] =
{
    { PID_MELADY, JID_WYVERNRIDER_F, 0, TRUE, FACTION_ID_RED, 8, 27, 2, 27, 2, { IID_DIVINE }, { AI_A_03, AI_B_03, 0x01, 0x20 } },
    { 0 }, // end
};

// UnitInfo @ 0867D30C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867D30C[] =
{
    { PID_GALLE, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 8, 29, 14, 27, 13, { IID_DIVINE }, { AI_A_03, AI_B_03, 0x01, 0x20 } },
    { 0 }, // end
};

// UnitInfo @ 0867D32C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867D32C[] =
{
    { PID_MELADY, JID_WYVERNRIDER_F, 0, TRUE, FACTION_ID_RED, 8, 29, 8, 27, 12, { IID_DIVINE }, { AI_A_03, AI_B_03, 0x01, 0x20 } },
    { 0 }, // end
};

// UnitInfo @ 0867D34C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867D34C[] =
{
    { PID_THEA, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 8, 18, 25, 21, 24, { IID_DIVINE }, { AI_A_03, AI_B_03, 0x01, 0x20 } },
    { 0 }, // end
};

// UnitInfo @ 0867D36C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867D36C[] =
{
    { PID_ELFFIN, JID_BARD, 0, TRUE, FACTION_ID_GREEN, 8, 29, 3, 27, 2, { IID_DIVINE }, { AI_A_03, AI_B_03, 0x01, 0x20 } },
    { 0 }, // end
};

// EventScr @ 0867D38C
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867CDAC[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867CDAC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867D3A0
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867CE7C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867CE7C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867D3B4
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867CE9C[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_0867CE9C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867D3D0
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867D00C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867D00C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867D3E4
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867D02C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867D02C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867D3F8
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867D07C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867D07C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867D40C
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867D0BC[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867D0BC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867D420
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867D0EC[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867D0EC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867D434
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867D11C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867D11C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867D448
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867D13C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867D13C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867D45C
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867D17C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867D17C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867D470
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867D1CC[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867D1CC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867D484
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867D20C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867D20C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867D498
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867D24C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867D24C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867D4AC
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867D27C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867D27C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867D4C0
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867D2BC[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867D2BC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867D4D4
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867D2EC[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867D2EC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867D4E8
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867D30C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867D30C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867D4FC
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867D32C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867D32C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867D510
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867D34C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867D34C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867D524
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867D36C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867D36C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 11 summary:
// Units UnitInfo_Unk_0867CDAC 1
// Units UnitInfo_Unk_0867CE7C 1
// Units UnitInfo_Unk_0867CE9C 2
// Units UnitInfo_Unk_0867D00C 1
// Units UnitInfo_Unk_0867D02C 1
// Units UnitInfo_Unk_0867D07C 1
// Units UnitInfo_Unk_0867D0BC 1
// Units UnitInfo_Unk_0867D0EC 1
// Units UnitInfo_Unk_0867D11C 1
// Units UnitInfo_Unk_0867D13C 1
// Units UnitInfo_Unk_0867D17C 1
// Units UnitInfo_Unk_0867D1CC 1
// Units UnitInfo_Unk_0867D20C 1
// Units UnitInfo_Unk_0867D24C 1
// Units UnitInfo_Unk_0867D27C 1
// Units UnitInfo_Unk_0867D2BC 1
// Units UnitInfo_Unk_0867D2EC 1
// Units UnitInfo_Unk_0867D30C 1
// Units UnitInfo_Unk_0867D32C 1
// Units UnitInfo_Unk_0867D34C 1
// Units UnitInfo_Unk_0867D36C 1

// UnitInfo @ 0867D538
struct UnitInfo CONST_DATA UnitInfo_Unk_0867D538[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 11, 12, 27, 12, 27, { IID_LIGHTBRAND, IID_STEELSWORD, IID_RAPIER, IID_VULNERARY }, { 0 } },
    { PID_ALEN, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 14, 11, 26, 11, 26, { IID_IRONLANCE, IID_IRONLANCE, IID_IRONSWORD, IID_JAVELIN }, { 0 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 11, 13, 26, 13, 26, { IID_HORSESLAYER, IID_IRONLANCE, IID_IRONSWORD, IID_STEELLANCE }, { 0 } },
    { PID_BORS, JID_GENERAL, PID_ROY, TRUE, FACTION_ID_BLUE, 4, 14, 27, 14, 27, { IID_KILLERLANCE, IID_STEELAXE, IID_STEELLANCE, IID_SILVERLANCE }, { 0 } },
    { PID_WOLT, JID_ARCHER, PID_ROY, TRUE, FACTION_ID_BLUE, 12, 11, 28, 11, 28, { IID_KILLERBOW, IID_LONGBOW, IID_IRONBOW, IID_VULNERARY }, { 0 } },
    { PID_DIECK, JID_HERO, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 13, 28, 13, 28, { IID_IRONBLADE, IID_IRONBLADE, IID_STEELSWORD, IID_ARMORSLAYER }, { 0 } },
    { PID_LARUM, JID_DANCER, PID_ROY, TRUE, FACTION_ID_BLUE, 1, 10, 27, 10, 27, { IID_CHESTKEY }, { 0 } },
    { PID_RUTGER, JID_MYRMIDON, PID_ROY, TRUE, FACTION_ID_BLUE, 13, 12, 29, 12, 29, { IID_IRONSWORD, IID_IRONBLADE, IID_KILLINGEDGE, IID_VULNERARY }, { 0 } },
    { PID_CLARINE, JID_TROUBADOUR, PID_ROY, TRUE, FACTION_ID_BLUE, 6, 25, 21, 25, 21, { IID_VULNERARY, IID_VULNERARY, IID_BARRIERSTAFF, IID_HEALSTAFF }, { 0 } },
    { PID_ASTOLFO, JID_THIEF, PID_ROY, TRUE, FACTION_ID_BLUE, 10, 27, 21, 27, 21, { IID_IRONSWORD, IID_LOCKPICK, IID_CHESTKEY, IID_SILVERAXE }, { 0 } },
    { PID_LUGH, JID_SAGE, PID_ROY, TRUE, FACTION_ID_BLUE, 1, 26, 22, 26, 22, { IID_ELFIRE, IID_THUNDER, IID_THUNDER, IID_FIRE }, { 0 } },
    { PID_SUE, JID_NOMAD_F, PID_ROY, TRUE, FACTION_ID_BLUE, 10, 27, 22, 27, 22, { IID_KILLERBOW, IID_STEELBOW, IID_IRONBOW, IID_SHORTBOW }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 26, 23, 26, 23, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_RESTORESTAFF }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867D618
struct UnitInfo CONST_DATA UnitInfo_Unk_0867D618[] =
{
    { PID_UNKNOWN_5E, JID_PALADIN, 0, FALSE, FACTION_ID_RED, 10, 9, 1, 9, 1, { IID_SILVERLANCE, IID_ELIXIR }, { AI_A_06, AI_B_05, 0x1B, 0x20 } },
    { PID_UNKNOWN_84, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 12, 10, 21, 10, 21, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_84, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 13, 13, 21, 13, 21, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_84, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 13, 9, 16, 9, 16, { IID_STEELLANCE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_84, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 12, 8, 10, 8, 10, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_84, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 13, 8, 12, 8, 12, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_84, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 12, 10, 10, 10, 10, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_84, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 14, 10, 12, 10, 12, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_84, JID_WARRIOR, 0, TRUE, FACTION_ID_RED, 5, 9, 11, 9, 11, { IID_HANDAXE }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_RAIGH, JID_SHAMAN, 0, FALSE, FACTION_ID_RED, 12, 3, 11, 3, 11, { IID_NOSFERATU }, { AI_A_03, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_84, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 15, 23, 17, 23, 17, { IID_KILLERAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_84, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 12, 23, 12, 23, 12, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_84, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 15, 23, 8, 23, 8, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_84, JID_PRIEST, 0, TRUE, FACTION_ID_RED, 14, 13, 8, 13, 8, { IID_MENDSTAFF }, { AI_A_0E, AI_B_03, 0x10, 0x00 } },
    { PID_UNKNOWN_84, JID_PRIEST, 0, TRUE, FACTION_ID_RED, 15, 20, 24, 20, 24, { IID_SLEEPSTAFF }, { AI_A_00, AI_B_00, 0x08, 0x00 } },
    { PID_UNKNOWN_84, JID_PRIEST, 0, TRUE, FACTION_ID_RED, 15, 20, 22, 20, 22, { IID_PHYSICSTAFF, IID_MENDSTAFF }, { AI_A_0E, AI_B_03, 0x10, 0x00 } },
    { PID_UNKNOWN_84, JID_PRIEST, 0, TRUE, FACTION_ID_RED, 15, 10, 2, 10, 2, { IID_PHYSICSTAFF, IID_SLEEPSTAFF }, { AI_A_0E, AI_B_03, 0x10, 0x20 } },
    { PID_UNKNOWN_84, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 11, 14, 18, 14, 18, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_84, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 12, 16, 18, 16, 18, { IID_LONGBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_84, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 13, 10, 14, 10, 14, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_84, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 13, 14, 14, 14, 14, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_84, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 13, 15, 10, 15, 10, { IID_LONGBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_84, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 13, 18, 10, 18, 10, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_84, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 13, 12, 14, 12, 14, { IID_FLUX }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_84, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 13, 16, 14, 16, 14, { IID_FLUX }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_84, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 14, 20, 21, 20, 21, { IID_FLUX }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_84, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 13, 4, 19, 4, 19, { IID_ECLIPSE }, { AI_A_03, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_84, JID_SNIPER, 0, TRUE, FACTION_ID_RED, 2, 21, 18, 21, 18, { IID_SILVERBOW, IID_VULNERARY }, { AI_A_03, AI_B_03, 0x29, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867D7E8
struct UnitInfo CONST_DATA UnitInfo_Unk_0867D7E8[] =
{
    { PID_UNKNOWN_83, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 15, 26, 0, 26, 0, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_83, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 12, 28, 0, 28, 0, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_83, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 13, 30, 0, 30, 0, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867D828
struct UnitInfo CONST_DATA UnitInfo_Unk_0867D828[] =
{
    { PID_UNKNOWN_85, JID_HERO, 0, TRUE, FACTION_ID_RED, 1, 12, 31, 12, 30, { IID_SILVERSWORD }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_85, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 13, 12, 31, 11, 28, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_85, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 16, 12, 31, 13, 28, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_85, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 16, 12, 31, 12, 28, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867D878
struct UnitInfo CONST_DATA UnitInfo_Unk_0867D878[] =
{
    { PID_UNKNOWN_85, JID_WARRIOR, 0, TRUE, FACTION_ID_RED, 15, 31, 23, 30, 22, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_85, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 15, 31, 23, 29, 22, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_85, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 14, 31, 23, 30, 23, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_85, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 13, 31, 23, 28, 23, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867D8C8
struct UnitInfo CONST_DATA UnitInfo_Unk_0867D8C8[] =
{
    { PID_CATH, JID_THIEF_F, 0, FALSE, FACTION_ID_RED, 5, 18, 0, 18, 1, { IID_IRONSWORD, IID_LOCKPICK, IID_VULNERARY }, { AI_A_06, AI_B_05, 0x1B, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867D8E8
struct UnitInfo CONST_DATA UnitInfo_Unk_0867D8E8[] =
{
    { PID_UNKNOWN_84, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 12, 6, 6, 6, 6, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_84, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 14, 12, 6, 12, 6, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867D918
struct UnitInfo CONST_DATA UnitInfo_Unk_0867D918[] =
{
    { PID_UNKNOWN_58, JID_MANAKETE, 0, FALSE, FACTION_ID_RED, 8, 6, 6, 6, 6, { IID_FIRESTONE }, { AI_A_03, AI_B_03, 0x02, 0x20 } },
    { 0 }, // end
};

// UnitInfo @ 0867D938
struct UnitInfo CONST_DATA UnitInfo_Unk_0867D938[] =
{
    { PID_UNKNOWN_55, JID_WYVERNLORD, 0, FALSE, FACTION_ID_RED, 1, 12, 6, 12, 6, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_06, AI_B_05, 0x1B, 0x00 } },
    { 0 }, // end
};

// EventScr @ 0867D958
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867D538[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867D538)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867D96C
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867D618[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_0867D618)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867D988
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867D7E8[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867D7E8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867D99C
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867D828[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867D828)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867D9B0
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867D878[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867D878)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867D9C4
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867D8C8[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867D8C8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867D9D8
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867D8E8[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867D8E8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867D9EC
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867D918[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867D918)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867DA00
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867D938[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867D938)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 12 summary:
// Units UnitInfo_Unk_0867D538 1
// Units UnitInfo_Unk_0867D618 2
// Units UnitInfo_Unk_0867D7E8 1
// Units UnitInfo_Unk_0867D828 1
// Units UnitInfo_Unk_0867D878 1
// Units UnitInfo_Unk_0867D8C8 1
// Units UnitInfo_Unk_0867D8E8 1
// Units UnitInfo_Unk_0867D918 1
// Units UnitInfo_Unk_0867D938 1

// UnitInfo @ 0867DA14
struct UnitInfo CONST_DATA UnitInfo_Unk_0867DA14[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 14, 2, 18, 2, 18, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_MARCUS, JID_PALADIN, PID_ROY, TRUE, FACTION_ID_BLUE, 8, 6, 18, 6, 18, { IID_SILVERLANCE, IID_IRONSWORD, IID_IRONLANCE, IID_HORSESLAYER }, { 0 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 16, 2, 16, 2, 16, { IID_STEELSWORD, IID_IRONLANCE, IID_JAVELIN, IID_SILVERLANCE }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 12, 4, 16, 4, 16, { IID_IRONLANCE, IID_JAVELIN, IID_SILVERLANCE, IID_CHESTKEY }, { 0 } },
    { PID_WOLT, JID_ARCHER, PID_ROY, TRUE, FACTION_ID_BLUE, 14, 1, 17, 1, 17, { IID_IRONBOW, IID_SILVERBOW, IID_STEELBOW, IID_KILLERBOW }, { 0 } },
    { PID_ECHIDNA, JID_HERO_F, PID_ROY, FALSE, FACTION_ID_BLUE, 3, 3, 17, 3, 17, { IID_BRAVEAXE, IID_IRONSWORD, IID_ARMORSLAYER, IID_STEELSWORD }, { 0 } },
    { PID_WARD, JID_FIGHTER, PID_ROY, TRUE, FACTION_ID_BLUE, 13, 5, 17, 5, 17, { IID_IRONAXE, IID_HAMMER, IID_HANDAXE, IID_KILLERAXE }, { 0 } },
    { PID_SHANNA, JID_PEGASUSKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 16, 4, 18, 4, 18, { IID_SLIMLANCE, IID_JAVELIN, IID_SILVERLANCE, IID_VULNERARY }, { 0 } },
    { PID_CLARINE, JID_TROUBADOUR, PID_ROY, TRUE, FACTION_ID_BLUE, 17, 1, 19, 1, 19, { IID_HEALSTAFF, IID_UNLOCKSTAFF, IID_RESTORESTAFF, IID_BARRIERSTAFF }, { 0 } },
    { PID_CHAD, JID_THIEF, PID_ROY, TRUE, FACTION_ID_BLUE, 11, 3, 19, 3, 19, { IID_IRONSWORD, IID_LOCKPICK }, { 0 } },
    { PID_LUGH, JID_MAGE, PID_ROY, TRUE, FACTION_ID_BLUE, 13, 5, 19, 5, 19, { IID_FIRE, IID_THUNDER, IID_ELFIRE, IID_AIRCALIBUR }, { 0 } },
    { PID_SUE, JID_NOMAD_F, PID_ROY, TRUE, FACTION_ID_BLUE, 13, 2, 20, 2, 20, { IID_IRONBOW, IID_LONGBOW, IID_STEELBOW, IID_BRAVEBOW }, { 0 } },
    { PID_RUTGER, JID_MYRMIDON, PID_ROY, TRUE, FACTION_ID_BLUE, 15, 4, 20, 4, 20, { IID_KILLINGEDGE, IID_IRONSWORD, IID_VULNERARY, IID_STEELSWORD }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 3, 21, 3, 21, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_RESTORESTAFF }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867DB04
struct UnitInfo CONST_DATA UnitInfo_Unk_0867DB04[] =
{
    { PID_CECILIA, JID_VALKYRIE, 0, FALSE, FACTION_ID_GREEN, 1, 43, 9, 43, 9, { IID_AIRCALIBUR, IID_MENDSTAFF }, { AI_A_03, AI_B_03 } },
    { PID_UNKNOWN_55, JID_WYVERNLORD, 0, FALSE, FACTION_ID_RED, 2, 44, 12, 44, 12, { IID_SPEAR }, { AI_A_00, AI_B_03, 0x39, 0x20 } },
    { PID_UNKNOWN_86, JID_WYVERNRIDER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 12, 43, 11, 43, 11, { IID_HORSESLAYER }, { AI_A_00, AI_B_06, 0x39, 0x00 } },
    { PID_UNKNOWN_86, JID_WYVERNRIDER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 13, 43, 13, 43, 13, { IID_STEELLANCE }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_86, JID_WYVERNRIDER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 14, 41, 11, 41, 11, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_86, JID_WYVERNRIDER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 13, 41, 13, 41, 13, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_86, JID_WYVERNRIDER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 12, 42, 14, 42, 14, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_87, JID_PALADIN, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 3, 36, 7, 36, 7, { IID_SILVERLANCE }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_87, JID_CAVALIER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 15, 34, 7, 34, 7, { IID_AXEREAVER }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_87, JID_CAVALIER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 15, 32, 7, 32, 7, { IID_STEELSWORD, IID_JAVELIN }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_87, JID_CAVALIER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 16, 33, 8, 33, 8, { IID_KILLINGEDGE }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_UNKNOWN_87, JID_CAVALIER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 16, 34, 9, 34, 9, { IID_STEELSWORD, IID_JAVELIN }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_87, JID_CAVALIER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 14, 32, 9, 32, 9, { IID_STEELSWORD, IID_VULNERARY }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_87, JID_TROUBADOUR, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 14, 38, 10, 38, 10, { IID_HEALSTAFF, IID_VULNERARY }, { AI_A_0E, AI_B_06, 0x11, 0x00 } },
    { PID_UNKNOWN_87, JID_SNIPER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 1, 20, 16, 20, 16, { IID_SILVERBOW }, { AI_A_00, AI_B_03, 0x29, 0x00 } },
    { PID_UNKNOWN_87, JID_ARCHER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 14, 19, 21, 19, 21, { IID_STEELBOW }, { AI_A_00, AI_B_03, 0x29, 0x00 } },
    { PID_UNKNOWN_87, JID_ARCHER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 15, 21, 17, 21, 17, { IID_LONGBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_87, JID_ARCHER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 14, 20, 22, 20, 22, { IID_LONGBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_87, JID_MAGE, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 15, 20, 19, 20, 19, { IID_THUNDER }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_87, JID_MAGE, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 14, 18, 17, 18, 17, { IID_ELFIRE }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_87, JID_PALADIN, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 3, 11, 4, 11, 4, { IID_SILVERLANCE }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_87, JID_CAVALIER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 14, 10, 3, 10, 3, { IID_AXEREAVER }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_87, JID_CAVALIER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 15, 10, 5, 10, 5, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_87, JID_CAVALIER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 14, 12, 3, 12, 3, { IID_KILLERLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_87, JID_CAVALIER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 14, 12, 5, 12, 5, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_87, JID_TROUBADOUR, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 14, 13, 4, 13, 4, { IID_HEALSTAFF, IID_VULNERARY }, { AI_A_0E, AI_B_06, 0x11, 0x00 } },
    { PID_UNKNOWN_87, JID_PALADIN, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 3, 32, 20, 32, 20, { IID_SILVERLANCE }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_87, JID_CAVALIER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 14, 33, 19, 33, 19, { IID_AXEREAVER }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_87, JID_CAVALIER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 15, 33, 21, 33, 21, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_87, JID_CAVALIER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 14, 31, 21, 31, 21, { IID_STEELLANCE }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_87, JID_CAVALIER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 14, 30, 20, 30, 20, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_87, JID_TROUBADOUR, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 15, 31, 18, 31, 18, { IID_HEALSTAFF, IID_VULNERARY }, { AI_A_0E, AI_B_00, 0x11, 0x00 } },
    { PID_PERCEVAL, JID_PALADIN, 0, FALSE, FACTION_ID_RED, 5, 34, 3, 34, 3, { IID_SILVERLANCE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_D5, JID_CAVALIER, PID_PERCEVAL, TRUE, FACTION_ID_RED, 14, 33, 4, 33, 4, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_0D, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_D6, JID_SNIPER, PID_PERCEVAL, TRUE, FACTION_ID_RED, 1, 35, 4, 35, 4, { IID_STEELBOW }, { AI_A_0D, AI_B_03, 0x29, 0x00 } },
    { PID_UNKNOWN_D7, JID_CAVALIER, PID_PERCEVAL, TRUE, FACTION_ID_RED, 14, 33, 2, 33, 2, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_0D, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_87, JID_HERO, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 2, 42, 22, 42, 22, { IID_STEELSWORD }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_87, JID_MERCENARY, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 15, 40, 21, 40, 21, { IID_STEELSWORD }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_87, JID_MERCENARY, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 14, 40, 23, 40, 23, { IID_STEELSWORD }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867DD84
struct UnitInfo CONST_DATA UnitInfo_Unk_0867DD84[] =
{
    { PID_ZEPHIEL, JID_KING, 0, FALSE, FACTION_ID_RED, 20, 45, 10, 43, 10, { IID_SLIMLANCE, IID_JAVELIN }, { AI_A_03, AI_B_03, 0x02, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867DDA4
struct UnitInfo CONST_DATA UnitInfo_Unk_0867DDA4[] =
{
    { PID_UNKNOWN_87, JID_PALADIN, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 5, 0, 0, 0, 1, { IID_SILVERLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_87, JID_CAVALIER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 14, 0, 0, 1, 0, { IID_AXEREAVER }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_87, JID_CAVALIER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 14, 0, 0, 1, 1, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_87, JID_CAVALIER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 16, 0, 0, 1, 2, { IID_KILLERLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867DDF4
struct UnitInfo CONST_DATA UnitInfo_Unk_0867DDF4[] =
{
    { PID_UNKNOWN_87, JID_CAVALIER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 15, 1, 2, 1, 3, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_87, JID_CAVALIER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 14, 0, 4, 1, 4, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_87, JID_TROUBADOUR, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 15, 1, 2, 0, 2, { IID_HEALSTAFF, IID_VULNERARY }, { AI_A_0E, AI_B_00, 0x11, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867DE34
struct UnitInfo CONST_DATA UnitInfo_Unk_0867DE34[] =
{
    { PID_UNKNOWN_87, JID_PALADIN, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 5, 0, 21, 0, 22, { IID_SILVERLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_87, JID_CAVALIER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 14, 0, 20, 1, 20, { IID_AXEREAVER }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_87, JID_CAVALIER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 14, 0, 22, 1, 21, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_87, JID_CAVALIER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 16, 0, 19, 1, 22, { IID_KILLERLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867DE84
struct UnitInfo CONST_DATA UnitInfo_Unk_0867DE84[] =
{
    { PID_UNKNOWN_87, JID_CAVALIER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 15, 0, 23, 1, 23, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_87, JID_CAVALIER, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 14, 0, 24, 1, 24, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_87, JID_TROUBADOUR, PID_UNKNOWN_55, TRUE, FACTION_ID_RED, 15, 1, 21, 0, 21, { IID_HEALSTAFF, IID_VULNERARY }, { AI_A_0E, AI_B_00, 0x11, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867DEC4
struct UnitInfo CONST_DATA UnitInfo_Unk_0867DEC4[] =
{
    { PID_MELADY, JID_WYVERNRIDER_F, 0, FALSE, FACTION_ID_RED, 10, 43, 10, 41, 7, { IID_STEELLANCE }, { AI_A_01, AI_B_0B } },
    { 0 }, // end
};

// UnitInfo @ 0867DEE4
struct UnitInfo CONST_DATA UnitInfo_Unk_0867DEE4[] =
{
    { PID_KLEIN, JID_SNIPER, 0, FALSE, FACTION_ID_BLUE, 1, 39, 18, 39, 18, { IID_SILVERBOW }, { AI_A_01, AI_B_00 } },
    { 0 }, // end
};

// UnitInfo @ 0867DF04
struct UnitInfo CONST_DATA UnitInfo_Unk_0867DF04[] =
{
    { PID_SIN, JID_NOMAD, 0, FALSE, FACTION_ID_BLUE, 8, 37, 18, 37, 18, { IID_SHORTBOW }, { AI_A_01, AI_B_00 } },
    { 0 }, // end
};

// UnitInfo @ 0867DF24
struct UnitInfo CONST_DATA UnitInfo_Unk_0867DF24[] =
{
    { PID_NARCIAN, JID_WYVERNLORD, 0, FALSE, FACTION_ID_RED, 8, 43, 9, 43, 9, { IID_SILVERLANCE }, { AI_A_03, AI_B_03 } },
    { 0 }, // end
};

// UnitInfo @ 0867DF44
struct UnitInfo CONST_DATA UnitInfo_Unk_0867DF44[] =
{
    { PID_ZEPHIEL, JID_KING, 0, FALSE, FACTION_ID_RED, 20, 42, 21, 42, 21, { IID_ECKESACHS }, { AI_A_03, AI_B_03 } },
    { PID_IDUNN, JID_SHAMAN_F, 0, FALSE, FACTION_ID_RED, 20, 42, 23, 42, 23, { 0 }, { AI_A_03, AI_B_03 } },
    { 0 }, // end
};

// UnitInfo @ 0867DF74
struct UnitInfo CONST_DATA UnitInfo_Unk_0867DF74[] =
{
    { PID_ZEPHIEL, JID_KING, 0, FALSE, FACTION_ID_RED, 20, 43, 9, 43, 10, { IID_ECKESACHS }, { AI_A_03, AI_B_03 } },
    { 0 }, // end
};

// UnitInfo @ 0867DF94
struct UnitInfo CONST_DATA UnitInfo_Unk_0867DF94[] =
{
    { PID_IDUNN, JID_SHAMAN_F, 0, FALSE, FACTION_ID_RED, 20, 43, 9, 43, 9, { 0 }, { AI_A_03, AI_B_03 } },
    { 0 }, // end
};

// UnitInfo @ 0867DFB4
struct UnitInfo CONST_DATA UnitInfo_Unk_0867DFB4[] =
{
    { PID_GUINIVERE, JID_SAGE_F, 0, FALSE, FACTION_ID_GREEN, 20, 44, 10, 43, 10, { 0 }, { AI_A_03, AI_B_03 } },
    { 0 }, // end
};

// UnitInfo @ 0867DFD4
struct UnitInfo CONST_DATA UnitInfo_Unk_0867DFD4[] =
{
    { PID_NARCIAN, JID_WYVERNLORD, 0, FALSE, FACTION_ID_RED, 8, 45, 23, 45, 12, { IID_RUNESWORD, IID_DELPHISHIELD }, { AI_A_03, AI_B_03 } },
    { 0 }, // end
};

// EventScr @ 0867DFF4
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867DA14[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867DA14)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867E008
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867DB04[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_0867DB04)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867E024
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867DD84[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867DD84)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867E038
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867DDA4[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867DDA4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867E04C
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867DDF4[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867DDF4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867E060
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867DE34[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867DE34)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867E074
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867DE84[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867DE84)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867E088
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867DEC4[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867DEC4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867E09C
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867DEE4[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867DEE4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867E0B0
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867DF04[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867DF04)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867E0C4
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867DF24[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867DF24)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867E0D8
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867DF44[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867DF44)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867E0EC
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867DF74[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867DF74)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867E100
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867DF94[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867DF94)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867E114
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867DFB4[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867DFB4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867E128
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867DFD4[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867DFD4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 13 summary:
// Units UnitInfo_Unk_0867DA14 1
// Units UnitInfo_Unk_0867DB04 2
// Units UnitInfo_Unk_0867DD84 1
// Units UnitInfo_Unk_0867DDA4 1
// Units UnitInfo_Unk_0867DDF4 1
// Units UnitInfo_Unk_0867DE34 1
// Units UnitInfo_Unk_0867DE84 1
// Units UnitInfo_Unk_0867DEC4 1
// Units UnitInfo_Unk_0867DEE4 1
// Units UnitInfo_Unk_0867DF04 1
// Units UnitInfo_Unk_0867DF24 1
// Units UnitInfo_Unk_0867DF44 1
// Units UnitInfo_Unk_0867DF74 1
// Units UnitInfo_Unk_0867DF94 1
// Units UnitInfo_Unk_0867DFB4 1
// Units UnitInfo_Unk_0867DFD4 1

// UnitInfo @ 0867E13C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867E13C[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 15, 8, 14, 8, 14, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY, IID_SILVERSWORD }, { 0 } },
    { PID_MARCUS, JID_PALADIN, PID_ROY, TRUE, FACTION_ID_BLUE, 9, 9, 13, 9, 13, { IID_SILVERLANCE, IID_IRONSWORD, IID_IRONLANCE, IID_HORSESLAYER }, { 0 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 17, 9, 15, 9, 15, { IID_STEELSWORD, IID_IRONLANCE, IID_JAVELIN, IID_SILVERLANCE }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 13, 7, 15, 7, 15, { IID_IRONLANCE, IID_JAVELIN, IID_SILVERLANCE, IID_CHESTKEY }, { 0 } },
    { PID_WOLT, JID_ARCHER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 7, 13, 7, 13, { IID_IRONBOW, IID_SILVERBOW, IID_STEELBOW, IID_KILLERBOW }, { 0 } },
    { PID_ECHIDNA, JID_HERO_F, PID_ROY, TRUE, FACTION_ID_BLUE, 4, 8, 12, 8, 12, { IID_BRAVEAXE, IID_IRONSWORD, IID_ARMORSLAYER, IID_STEELSWORD }, { 0 } },
    { PID_SHANNA, JID_PEGASUSKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 17, 10, 14, 10, 14, { IID_SLIMLANCE, IID_JAVELIN, IID_SILVERLANCE, IID_VULNERARY }, { 0 } },
    { PID_CLARINE, JID_TROUBADOUR, PID_ROY, TRUE, FACTION_ID_BLUE, 18, 8, 16, 8, 16, { IID_HEALSTAFF, IID_BERSERKSTAFF, IID_RESTORESTAFF, IID_TORCHSTAFF }, { 0 } },
    { PID_MELADY, JID_WYVERNRIDER_F, PID_ROY, TRUE, FACTION_ID_BLUE, 10, 6, 14, 6, 14, { IID_STEELLANCE, IID_JAVELIN, IID_IRONLANCE, IID_VULNERARY }, { 0 } },
    { PID_DOROTHY, JID_ARCHER_F, PID_ROY, TRUE, FACTION_ID_BLUE, 18, 6, 12, 6, 12, { IID_IRONBOW, IID_SILVERBOW, IID_STEELBOW, IID_TORCHSTAFF }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 6, 16, 6, 16, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_RESTORESTAFF }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867E1FC
struct UnitInfo CONST_DATA UnitInfo_Unk_0867E1FC[] =
{
    { PID_CECILIA, JID_VALKYRIE, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 10, 13, 10, 12, { IID_AIRCALIBUR, IID_MENDSTAFF }, { 0 } },
    { PID_SOPHIA, JID_SHAMAN_F, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 9, 16, 9, 17, { IID_FLUX }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867E22C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867E22C[] =
{
    { PID_UNKNOWN_5A, JID_HERO, 0, FALSE, FACTION_ID_RED, 10, 27, 3, 27, 3, { IID_LIGHTBRAND }, { AI_A_03, AI_B_03, 0x00, 0x20 } },
    { PID_UNKNOWN_88, JID_HERO, PID_UNKNOWN_5A, TRUE, FACTION_ID_RED, 3, 19, 9, 19, 9, { IID_KILLINGEDGE }, { AI_A_00, AI_B_06, 0x0A, 0x00 } },
    { PID_UNKNOWN_88, JID_MERCENARY, PID_UNKNOWN_5A, TRUE, FACTION_ID_RED, 17, 16, 7, 16, 7, { IID_STEELSWORD }, { AI_A_00, AI_B_06, 0x02, 0x00 } },
    { PID_UNKNOWN_88, JID_MERCENARY, PID_UNKNOWN_5A, TRUE, FACTION_ID_RED, 16, 15, 6, 15, 6, { IID_STEELSWORD }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_88, JID_MERCENARY, PID_UNKNOWN_5A, TRUE, FACTION_ID_RED, 15, 15, 8, 15, 8, { IID_STEELSWORD }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_88, JID_MERCENARY, PID_UNKNOWN_5A, TRUE, FACTION_ID_RED, 16, 17, 9, 17, 9, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x32, 0x00 } },
    { PID_UNKNOWN_88, JID_HERO, PID_UNKNOWN_5A, TRUE, FACTION_ID_RED, 5, 27, 10, 27, 10, { IID_STEELSWORD }, { AI_A_00, AI_B_06, 0x0A, 0x00 } },
    { PID_UNKNOWN_88, JID_MERCENARY, PID_UNKNOWN_5A, TRUE, FACTION_ID_RED, 15, 25, 9, 25, 9, { IID_STEELSWORD }, { AI_A_00, AI_B_06, 0x02, 0x00 } },
    { PID_UNKNOWN_88, JID_MERCENARY, PID_UNKNOWN_5A, TRUE, FACTION_ID_RED, 16, 23, 9, 23, 9, { IID_STEELSWORD }, { AI_A_00, AI_B_06, 0x0A, 0x00 } },
    { PID_UNKNOWN_88, JID_MERCENARY, PID_UNKNOWN_5A, TRUE, FACTION_ID_RED, 16, 25, 11, 25, 11, { IID_STEELSWORD }, { AI_A_00, AI_B_06, 0x02, 0x00 } },
    { PID_UNKNOWN_88, JID_MERCENARY, PID_UNKNOWN_5A, TRUE, FACTION_ID_RED, 14, 23, 11, 23, 11, { IID_ARMORSLAYER }, { AI_A_00, AI_B_06, 0x32, 0x00 } },
    { PID_UNKNOWN_88, JID_MAGE, PID_UNKNOWN_5A, TRUE, FACTION_ID_RED, 15, 28, 14, 28, 14, { IID_ELFIRE }, { AI_A_00, AI_B_06, 0x02, 0x00 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, PID_UNKNOWN_5A, TRUE, FACTION_ID_RED, 2, 29, 14, 29, 14, { IID_FIRESTONE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_88, JID_MAGE, PID_UNKNOWN_5A, TRUE, FACTION_ID_RED, 14, 29, 15, 29, 15, { IID_THUNDER }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_88, JID_MAGE, PID_UNKNOWN_5A, TRUE, FACTION_ID_RED, 14, 15, 1, 15, 1, { IID_AIRCALIBUR }, { AI_A_00, AI_B_06, 0x2A, 0x00 } },
    { PID_UNKNOWN_88, JID_MAGE, PID_UNKNOWN_5A, TRUE, FACTION_ID_RED, 15, 11, 3, 11, 3, { IID_THUNDER }, { AI_A_00, AI_B_06, 0x02, 0x00 } },
    { PID_UNKNOWN_88, JID_MAGE, PID_UNKNOWN_5A, TRUE, FACTION_ID_RED, 15, 23, 20, 23, 20, { IID_ELFIRE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, PID_UNKNOWN_5A, TRUE, FACTION_ID_RED, 3, 24, 20, 24, 20, { IID_FIRESTONE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, PID_UNKNOWN_5A, TRUE, FACTION_ID_RED, 1, 5, 7, 5, 7, { IID_FIRESTONE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_88, JID_MAGE, PID_UNKNOWN_5A, TRUE, FACTION_ID_RED, 15, 18, 16, 18, 16, { IID_THUNDER }, { AI_A_00, AI_B_06, 0x02, 0x00 } },
    { PID_UNKNOWN_88, JID_PRIEST, PID_UNKNOWN_5A, TRUE, FACTION_ID_RED, 17, 24, 10, 24, 10, { IID_MENDSTAFF, IID_SILENCESTAFF }, { AI_A_0E, AI_B_00, 0x11, 0x00 } },
    { PID_UNKNOWN_88, JID_PRIEST, PID_UNKNOWN_5A, TRUE, FACTION_ID_RED, 17, 16, 8, 16, 8, { IID_RECOVERSTAFF }, { AI_A_0E, AI_B_00, 0x11, 0x00 } },
    { PID_UNKNOWN_88, JID_BISHOP, PID_UNKNOWN_5A, TRUE, FACTION_ID_RED, 4, 28, 5, 28, 5, { IID_LIGHTNING, IID_MENDSTAFF, IID_SLEEPSTAFF }, { AI_A_00, AI_B_00, 0x12, 0x00 } },
    { PID_UNKNOWN_88, JID_WYVERNLORD, PID_UNKNOWN_5A, TRUE, FACTION_ID_RED, 3, 4, 2, 4, 2, { IID_STEELLANCE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_88, JID_WYVERNRIDER, PID_UNKNOWN_5A, TRUE, FACTION_ID_RED, 14, 3, 3, 3, 3, { IID_STEELLANCE }, { AI_A_00, AI_B_03, 0x11, 0x00 } },
    { PID_UNKNOWN_88, JID_WYVERNRIDER, PID_UNKNOWN_5A, TRUE, FACTION_ID_RED, 14, 5, 3, 5, 3, { IID_STEELLANCE }, { AI_A_00, AI_B_03, 0x11, 0x00 } },
    { PID_UNKNOWN_88, JID_WYVERNRIDER, PID_UNKNOWN_5A, TRUE, FACTION_ID_RED, 14, 4, 1, 4, 1, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_03, 0x12, 0x00 } },
    { PID_UNKNOWN_88, JID_WYVERNLORD, PID_UNKNOWN_5A, TRUE, FACTION_ID_RED, 3, 29, 18, 29, 18, { IID_SILVERLANCE }, { AI_A_00, AI_B_06, 0x02, 0x00 } },
    { PID_UNKNOWN_88, JID_WYVERNRIDER, PID_UNKNOWN_5A, TRUE, FACTION_ID_RED, 14, 28, 19, 28, 19, { IID_STEELLANCE }, { AI_A_00, AI_B_06, 0x11, 0x00 } },
    { PID_UNKNOWN_88, JID_WYVERNRIDER, PID_UNKNOWN_5A, TRUE, FACTION_ID_RED, 14, 28, 17, 28, 17, { IID_STEELLANCE }, { AI_A_00, AI_B_06, 0x11, 0x00 } },
    { PID_UNKNOWN_88, JID_WYVERNRIDER, PID_UNKNOWN_5A, TRUE, FACTION_ID_RED, 14, 30, 18, 30, 18, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_06, 0x12, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867E42C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867E42C[] =
{
    { PID_UNKNOWN_5B, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 6, 1, 16, 1, 18, { IID_DEVILAXE }, { AI_A_00, AI_B_00, 0x3A, 0x00 } },
    { PID_UNKNOWN_89, JID_BRIGAND, PID_UNKNOWN_5B, TRUE, FACTION_ID_RED, 16, 2, 14, 2, 16, { IID_KILLERAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_89, JID_BRIGAND, PID_UNKNOWN_5B, TRUE, FACTION_ID_RED, 17, 2, 15, 2, 17, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867E46C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867E46C[] =
{
    { PID_UNKNOWN_89, JID_BRIGAND, PID_UNKNOWN_5B, TRUE, FACTION_ID_RED, 16, 2, 16, 2, 18, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_89, JID_BRIGAND, PID_UNKNOWN_5B, TRUE, FACTION_ID_RED, 15, 2, 17, 2, 19, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867E49C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867E49C[] =
{
    { PID_UNKNOWN_5C, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 5, 7, 17, 7, 21, { IID_HALBERD }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_89, JID_BRIGAND, PID_UNKNOWN_5C, TRUE, FACTION_ID_RED, 16, 6, 18, 6, 20, { IID_KILLERAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_89, JID_BRIGAND, PID_UNKNOWN_5C, TRUE, FACTION_ID_RED, 16, 7, 18, 7, 20, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867E4DC
struct UnitInfo CONST_DATA UnitInfo_Unk_0867E4DC[] =
{
    { PID_UNKNOWN_89, JID_BRIGAND, PID_UNKNOWN_5C, TRUE, FACTION_ID_RED, 17, 8, 18, 8, 20, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_89, JID_BRIGAND, PID_UNKNOWN_5C, TRUE, FACTION_ID_RED, 14, 9, 18, 9, 20, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867E50C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867E50C[] =
{
    { PID_UNKNOWN_89, JID_BRIGAND, PID_UNKNOWN_5B, TRUE, FACTION_ID_RED, 16, 0, 15, 0, 16, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_89, JID_BRIGAND, PID_UNKNOWN_5B, TRUE, FACTION_ID_RED, 17, 0, 17, 0, 18, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_89, JID_BRIGAND, PID_UNKNOWN_5C, TRUE, FACTION_ID_RED, 17, 9, 20, 9, 21, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_89, JID_BRIGAND, PID_UNKNOWN_5C, TRUE, FACTION_ID_RED, 18, 11, 19, 11, 21, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867E55C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867E55C[] =
{
    { PID_UNKNOWN_89, JID_BRIGAND, PID_UNKNOWN_5B, TRUE, FACTION_ID_RED, 16, 31, 19, 30, 19, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_89, JID_BRIGAND, PID_UNKNOWN_5B, TRUE, FACTION_ID_RED, 17, 31, 20, 30, 20, { IID_POISONAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_89, JID_BRIGAND, PID_UNKNOWN_5C, TRUE, FACTION_ID_RED, 17, 31, 21, 30, 21, { IID_POISONAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_89, JID_BRIGAND, PID_UNKNOWN_5C, TRUE, FACTION_ID_RED, 18, 31, 17, 30, 17, { IID_POISONAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867E5AC
struct UnitInfo CONST_DATA UnitInfo_Unk_0867E5AC[] =
{
    { PID_UNKNOWN_89, JID_BRIGAND, PID_UNKNOWN_5B, TRUE, FACTION_ID_RED, 16, 7, 0, 7, 1, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_89, JID_BRIGAND, PID_UNKNOWN_5B, TRUE, FACTION_ID_RED, 17, 8, 0, 8, 1, { IID_POISONAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_89, JID_BRIGAND, PID_UNKNOWN_5C, TRUE, FACTION_ID_RED, 17, 9, 0, 9, 1, { IID_POISONAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_89, JID_BRIGAND, PID_UNKNOWN_5C, TRUE, FACTION_ID_RED, 18, 10, 0, 10, 1, { IID_POISONAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867E5FC
struct UnitInfo CONST_DATA UnitInfo_Unk_0867E5FC[] =
{
    { PID_FAE, JID_MANAKETE_F, 0, TRUE, FACTION_ID_BLUE, 10, 29, 8, 29, 8, { 0 }, { 0 } },
    { PID_IDUNN, JID_SHAMAN_F, 0, TRUE, FACTION_ID_GREEN, 4, 30, 8, 30, 8, { 0 }, { 0 } },
    { 0 }, // end
};

// EventScr @ 0867E62C
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867E13C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867E13C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867E640
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867E1FC[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867E1FC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867E654
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867E22C[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_0867E22C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867E670
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867E42C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867E42C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867E684
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867E46C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867E46C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867E698
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867E49C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867E49C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867E6AC
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867E4DC[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867E4DC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867E6C0
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867E50C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867E50C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867E6D4
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867E55C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867E55C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867E6E8
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867E5AC[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867E5AC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867E6FC
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867E5FC[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867E5FC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 14 summary:
// Units UnitInfo_Unk_0867E13C 1
// Units UnitInfo_Unk_0867E1FC 1
// Units UnitInfo_Unk_0867E22C 2
// Units UnitInfo_Unk_0867E42C 1
// Units UnitInfo_Unk_0867E46C 1
// Units UnitInfo_Unk_0867E49C 1
// Units UnitInfo_Unk_0867E4DC 1
// Units UnitInfo_Unk_0867E50C 1
// Units UnitInfo_Unk_0867E55C 1
// Units UnitInfo_Unk_0867E5AC 1
// Units UnitInfo_Unk_0867E5FC 1

// UnitInfo @ 0867E710
struct UnitInfo CONST_DATA UnitInfo_Unk_0867E710[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 16, 2, 19, 2, 19, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY, IID_SILVERSWORD }, { 0 } },
    { PID_BARTHE, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 18, 2, 17, 2, 17, { IID_KILLERLANCE, IID_IRONLANCE, IID_JAVELIN, IID_VULNERARY }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 15, 6, 18, 6, 18, { IID_SILVERLANCE, IID_IRONLANCE, IID_JAVELIN, IID_HORSESLAYER }, { 0 } },
    { PID_KLEIN, JID_SNIPER, PID_ROY, TRUE, FACTION_ID_BLUE, 10, 1, 18, 1, 18, { IID_IRONBOW, IID_SILVERBOW, IID_STEELBOW, IID_KILLERBOW }, { 0 } },
    { PID_FIR, JID_SWORDMASTER_F, PID_ROY, TRUE, FACTION_ID_BLUE, 5, 3, 18, 3, 18, { IID_WODAO, IID_IRONSWORD, IID_ARMORSLAYER, IID_STEELSWORD }, { 0 } },
    { PID_GWENDOLYN, JID_ARMOR_F, PID_ROY, TRUE, FACTION_ID_BLUE, 16, 4, 18, 4, 18, { IID_BRAVELANCE, IID_IRONLANCE, IID_JAVELIN, IID_VULNERARY }, { 0 } },
    { PID_CLARINE, JID_TROUBADOUR, PID_ROY, TRUE, FACTION_ID_BLUE, 19, 5, 19, 5, 19, { IID_HEALSTAFF, IID_UNLOCKSTAFF, IID_RESTORESTAFF, IID_BARRIERSTAFF }, { 0 } },
    { PID_SHANNA, JID_FALCONKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 15, 1, 20, 1, 20, { IID_STEELLANCE, IID_JAVELIN, IID_IRONLANCE, IID_SILVERLANCE }, { 0 } },
    { PID_LUGH, JID_SAGE, PID_ROY, TRUE, FACTION_ID_BLUE, 14, 3, 20, 3, 20, { IID_FIRE, IID_THUNDER, IID_ELFIRE, IID_AIRCALIBUR }, { 0 } },
    { PID_SUE, JID_NOMADTROOPER_F, PID_ROY, TRUE, FACTION_ID_BLUE, 12, 4, 20, 4, 20, { IID_IRONBOW, IID_LONGBOW, IID_STEELBOW, IID_BRAVEBOW }, { 0 } },
    { PID_ELFFIN, JID_BARD, PID_ROY, TRUE, FACTION_ID_BLUE, 14, 2, 21, 2, 21, { IID_VULNERARY, IID_CHESTKEY }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 5, 21, 5, 21, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_RESTORESTAFF }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867E7E0
struct UnitInfo CONST_DATA UnitInfo_Unk_0867E7E0[] =
{
    { PID_IGRENE, JID_SNIPER_F, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 3, 19, 4, 19, { IID_KILLERBOW }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867E800
struct UnitInfo CONST_DATA UnitInfo_Unk_0867E800[] =
{
    { PID_UNKNOWN_5D, JID_PALADIN, 0, FALSE, FACTION_ID_RED, 8, 16, 9, 16, 9, { IID_SPEAR }, { AI_A_03, AI_B_03, 0x00, 0x20 } },
    { PID_UNKNOWN_8B, JID_WYVERNRIDER, PID_UNKNOWN_5D, TRUE, FACTION_ID_RED, 18, 9, 8, 9, 8, { IID_SILVERLANCE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_8B, JID_WYVERNRIDER, PID_UNKNOWN_5D, TRUE, FACTION_ID_RED, 17, 24, 0, 24, 0, { IID_STEELLANCE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_8B, JID_WYVERNRIDER, PID_UNKNOWN_5D, TRUE, FACTION_ID_RED, 15, 26, 0, 26, 0, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_8A, JID_VALKYRIE, PID_UNKNOWN_5D, TRUE, FACTION_ID_RED, 1, 18, 1, 18, 1, { IID_ELFIRE, IID_PHYSICSTAFF }, { AI_A_00, AI_B_06, 0x11, 0x00 } },
    { PID_UNKNOWN_8A, JID_CAVALIER, PID_UNKNOWN_5D, TRUE, FACTION_ID_RED, 18, 17, 2, 17, 2, { IID_HORSESLAYER }, { AI_A_00, AI_B_06, 0x39, 0x00 } },
    { PID_UNKNOWN_8A, JID_CAVALIER, PID_UNKNOWN_5D, TRUE, FACTION_ID_RED, 18, 17, 3, 17, 3, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_8A, JID_CAVALIER, PID_UNKNOWN_5D, TRUE, FACTION_ID_RED, 17, 19, 2, 19, 2, { IID_STEELLANCE }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_8A, JID_CAVALIER, PID_UNKNOWN_5D, TRUE, FACTION_ID_RED, 15, 19, 3, 19, 3, { IID_STEELLANCE }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_8A, JID_VALKYRIE, PID_UNKNOWN_5D, TRUE, FACTION_ID_RED, 1, 26, 19, 26, 19, { IID_AIRCALIBUR, IID_MENDSTAFF }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_8A, JID_CAVALIER, PID_UNKNOWN_5D, TRUE, FACTION_ID_RED, 18, 25, 18, 25, 18, { IID_HORSESLAYER }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_8A, JID_CAVALIER, PID_UNKNOWN_5D, TRUE, FACTION_ID_RED, 18, 25, 20, 25, 20, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_8A, JID_CAVALIER, PID_UNKNOWN_5D, TRUE, FACTION_ID_RED, 17, 24, 17, 24, 17, { IID_STEELLANCE }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_8A, JID_CAVALIER, PID_UNKNOWN_5D, TRUE, FACTION_ID_RED, 15, 24, 21, 24, 21, { IID_STEELLANCE }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_8A, JID_SNIPER, PID_UNKNOWN_5D, TRUE, FACTION_ID_RED, 5, 25, 6, 25, 6, { IID_SILVERBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_8A, JID_MERCENARY, PID_UNKNOWN_5D, TRUE, FACTION_ID_RED, 18, 24, 5, 24, 5, { IID_KILLINGEDGE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_8A, JID_MERCENARY, PID_UNKNOWN_5D, TRUE, FACTION_ID_RED, 17, 24, 7, 24, 7, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_8A, JID_MERCENARY, PID_UNKNOWN_5D, TRUE, FACTION_ID_RED, 18, 26, 5, 26, 5, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_8A, JID_MERCENARY, PID_UNKNOWN_5D, TRUE, FACTION_ID_RED, 18, 26, 7, 26, 7, { IID_ARMORSLAYER }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_8A, JID_ARCHER, PID_UNKNOWN_5D, TRUE, FACTION_ID_RED, 17, 25, 4, 25, 4, { IID_LONGBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_8A, JID_ARCHER, PID_UNKNOWN_5D, TRUE, FACTION_ID_RED, 18, 25, 8, 25, 8, { IID_LONGBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_8A, JID_MERCENARY, PID_UNKNOWN_5D, TRUE, FACTION_ID_RED, 18, 12, 20, 12, 20, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_8A, JID_MERCENARY, PID_UNKNOWN_5D, TRUE, FACTION_ID_RED, 17, 16, 21, 16, 21, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_8A, JID_ARCHER, PID_UNKNOWN_5D, TRUE, FACTION_ID_RED, 15, 17, 24, 17, 24, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_8A, JID_MERCENARY, PID_UNKNOWN_5D, TRUE, FACTION_ID_RED, 17, 14, 8, 14, 8, { IID_STEELSWORD }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_8A, JID_MERCENARY, PID_UNKNOWN_5D, TRUE, FACTION_ID_RED, 18, 11, 8, 11, 8, { IID_ARMORSLAYER }, { AI_A_00, AI_B_06, 0x31, 0x00 } },
    { PID_UNKNOWN_8A, JID_CAVALIER, PID_PERCEVAL, TRUE, FACTION_ID_RED, 14, 14, 10, 14, 10, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_8A, JID_CAVALIER, PID_PERCEVAL, TRUE, FACTION_ID_RED, 14, 11, 10, 11, 10, { IID_STEELLANCE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_8A, JID_SNIPER, PID_UNKNOWN_5D, TRUE, FACTION_ID_RED, 5, 13, 9, 13, 9, { IID_SILVERBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_8A, JID_ARCHER, PID_UNKNOWN_5D, TRUE, FACTION_ID_RED, 17, 12, 9, 12, 9, { IID_LONGBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867E9F0
struct UnitInfo CONST_DATA UnitInfo_Unk_0867E9F0[] =
{
    { PID_PERCEVAL, JID_PALADIN, 0, FALSE, FACTION_ID_RED, 5, 2, 0, 2, 0, { IID_SILVERLANCE, IID_SILVERSWORD }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_DOUGLAS, JID_GENERAL, 0, TRUE, FACTION_ID_RED, 5, 0, 0, 0, 0, { IID_SILVERLANCE, IID_SILVERSWORD }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_D3, JID_CAVALIER, PID_PERCEVAL, TRUE, FACTION_ID_RED, 14, 1, 4, 1, 4, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_D3, JID_CAVALIER, PID_PERCEVAL, TRUE, FACTION_ID_RED, 15, 3, 4, 3, 4, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_D3, JID_CAVALIER, PID_PERCEVAL, TRUE, FACTION_ID_RED, 14, 1, 2, 1, 2, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_D3, JID_CAVALIER, PID_PERCEVAL, TRUE, FACTION_ID_RED, 14, 3, 2, 3, 2, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867EA60
struct UnitInfo CONST_DATA UnitInfo_Unk_0867EA60[] =
{
    { PID_UNKNOWN_8A, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 17, 16, 1, 16, 1, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_8A, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 16, 16, 3, 16, 3, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_8A, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 16, 16, 8, 15, 10, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_8A, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 16, 15, 9, 14, 9, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867EAB0
struct UnitInfo CONST_DATA UnitInfo_Unk_0867EAB0[] =
{
    { PID_GARRET, JID_BERSERKER, 0, FALSE, FACTION_ID_RED, 1, 20, 0, 22, 2, { IID_STEELAXE, IID_HANDAXE }, { AI_A_01, AI_B_04, 0x0A, 0x00 } },
    { PID_UNKNOWN_8D, JID_BRIGAND, 0, TRUE, FACTION_ID_RED, 18, 20, 0, 21, 3, { IID_POISONAXE, IID_HANDAXE }, { AI_A_01, AI_B_04, 0x0A, 0x00 } },
    { PID_UNKNOWN_8D, JID_BRIGAND, 0, TRUE, FACTION_ID_RED, 18, 20, 0, 21, 2, { IID_POISONAXE, IID_HANDAXE }, { AI_A_01, AI_B_04, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867EAF0
struct UnitInfo CONST_DATA UnitInfo_Unk_0867EAF0[] =
{
    { PID_FAE, JID_MANAKETE_F, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 0, 0, 0, 0, { IID_DIVINESTONE }, { 0 } },
    { 0 }, // end
};

// EventScr @ 0867EB10
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867E710[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867E710)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867EB24
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867E7E0[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867E7E0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867EB38
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867E800[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_0867E800)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867EB54
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867E9F0[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867E9F0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867EB68
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867EA60[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867EA60)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867EB7C
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867EAB0[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867EAB0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867EB90
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867EAF0[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867EAF0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 15 summary:
// Units UnitInfo_Unk_0867E710 1
// Units UnitInfo_Unk_0867E7E0 1
// Units UnitInfo_Unk_0867E800 2
// Units UnitInfo_Unk_0867E9F0 1
// Units UnitInfo_Unk_0867EA60 1
// Units UnitInfo_Unk_0867EAB0 1
// Units UnitInfo_Unk_0867EAF0 1

// UnitInfo @ 0867EBA4
struct UnitInfo CONST_DATA UnitInfo_Unk_0867EBA4[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 17, 10, 30, 10, 30, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY, IID_SILVERSWORD }, { 0 } },
    { PID_MARCUS, JID_PALADIN, PID_ROY, TRUE, FACTION_ID_BLUE, 12, 8, 29, 8, 29, { IID_SILVERLANCE, IID_IRONSWORD, IID_IRONLANCE, IID_HORSESLAYER }, { 0 } },
    { PID_ALEN, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 19, 9, 29, 9, 29, { IID_STEELSWORD, IID_IRONLANCE, IID_JAVELIN, IID_SILVERLANCE }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 16, 11, 29, 11, 29, { IID_IRONLANCE, IID_JAVELIN, IID_SILVERLANCE, IID_CHESTKEY }, { 0 } },
    { PID_KLEIN, JID_SNIPER, PID_ROY, TRUE, FACTION_ID_BLUE, 5, 12, 30, 12, 30, { IID_IRONBOW, IID_SILVERBOW, IID_STEELBOW, IID_KILLERBOW }, { 0 } },
    { PID_ECHIDNA, JID_HERO_F, PID_ROY, TRUE, FACTION_ID_BLUE, 6, 8, 31, 8, 31, { IID_BRAVEAXE, IID_IRONSWORD, IID_ARMORSLAYER, IID_STEELSWORD }, { 0 } },
    { PID_CECILIA, JID_VALKYRIE, PID_ROY, TRUE, FACTION_ID_BLUE, 1, 9, 31, 9, 31, { IID_ELFIRE, IID_THUNDER, IID_HEALSTAFF, IID_RESTORESTAFF }, { 0 } },
    { PID_BARTRE, JID_WARRIOR, PID_ROY, FALSE, FACTION_ID_BLUE, 2, 11, 31, 11, 31, { IID_KILLERAXE, IID_IRONAXE, IID_HANDAXE, IID_HALBERD }, { 0 } },
    { PID_LARUM, JID_DANCER, PID_ROY, TRUE, FACTION_ID_BLUE, 1, 22, 29, 22, 29, { IID_PUREWATER, IID_CHESTKEY, IID_VULNERARY }, { 0 } },
    { PID_MELADY, JID_WYVERNRIDER_F, PID_ROY, TRUE, FACTION_ID_BLUE, 12, 24, 29, 24, 29, { IID_STEELLANCE, IID_JAVELIN, IID_IRONLANCE, IID_SILVERLANCE }, { 0 } },
    { PID_LUGH, JID_MAGE, PID_ROY, TRUE, FACTION_ID_BLUE, 17, 21, 30, 21, 30, { IID_FIRE, IID_THUNDER, IID_ELFIRE, IID_AIRCALIBUR }, { 0 } },
    { PID_SIN, JID_NOMAD, PID_ROY, TRUE, FACTION_ID_BLUE, 17, 23, 30, 23, 30, { IID_IRONBOW, IID_LONGBOW, IID_STEELBOW, IID_BRAVEBOW }, { 0 } },
    { PID_CHAD, JID_THIEF, PID_ROY, TRUE, FACTION_ID_BLUE, 16, 22, 31, 22, 31, { IID_KILLINGEDGE, IID_LOCKPICK }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 24, 31, 24, 31, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_RESTORESTAFF }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867EC94
struct UnitInfo CONST_DATA UnitInfo_Unk_0867EC94[] =
{
    { PID_NARCIAN, JID_WYVERNLORD, 0, FALSE, FACTION_ID_RED, 10, 14, 3, 14, 3, { IID_RUNESWORD, IID_DELPHISHIELD, IID_BLUEGEM }, { AI_A_03, AI_B_03, 0x01, 0x20 } },
    { PID_UNKNOWN_8E, JID_MAGE, 0, TRUE, FACTION_ID_RED, 16, 15, 3, 15, 3, { IID_AIRCALIBUR }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_8E, JID_MAGE, 0, TRUE, FACTION_ID_RED, 17, 13, 3, 13, 3, { IID_AIRCALIBUR }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_8E, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 9, 27, 3, 27, 3, { IID_FIRESTONE }, { AI_A_03, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_8E, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 8, 7, 8, 7, 8, { IID_FIRESTONE, IID_REDGEM }, { AI_A_03, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_8E, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 17, 14, 10, 14, 10, { IID_HORSESLAYER }, { AI_A_00, AI_B_03, 0x39, 0x00 } },
    { PID_UNKNOWN_8E, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 18, 23, 3, 23, 3, { IID_HORSESLAYER }, { AI_A_00, AI_B_03, 0x39, 0x00 } },
    { PID_UNKNOWN_8E, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 17, 12, 5, 12, 5, { IID_JAVELIN, IID_STEELLANCE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_8E, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 18, 11, 14, 11, 14, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_8E, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 18, 12, 16, 12, 16, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_8E, JID_BISHOP, 0, TRUE, FACTION_ID_RED, 1, 8, 13, 8, 13, { IID_PURGE, IID_MENDSTAFF }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_8E, JID_BISHOP, 0, TRUE, FACTION_ID_RED, 1, 6, 6, 6, 6, { IID_LIGHTNING, IID_PHYSICSTAFF }, { AI_A_0E, AI_B_03, 0x09, 0x00 } },
    { PID_UNKNOWN_8F, JID_PALADIN, 0, TRUE, FACTION_ID_RED, 1, 8, 18, 8, 18, { IID_STEELSWORD, IID_JAVELIN }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_8F, JID_MAGE, 0, TRUE, FACTION_ID_RED, 17, 7, 19, 7, 19, { IID_ELFIRE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_8F, JID_MAGE, 0, TRUE, FACTION_ID_RED, 17, 9, 19, 9, 19, { IID_ELFIRE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_8F, JID_MAGE, 0, TRUE, FACTION_ID_RED, 16, 17, 13, 17, 13, { IID_ELFIRE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_8F, JID_MAGE, 0, TRUE, FACTION_ID_RED, 16, 20, 16, 20, 16, { IID_AIRCALIBUR, IID_REDGEM }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_8F, JID_MAGE, 0, TRUE, FACTION_ID_RED, 17, 29, 23, 29, 23, { IID_BOLTING, IID_VULNERARY }, { AI_A_03, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_8F, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 18, 27, 13, 27, 13, { IID_KILLINGEDGE }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_8F, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 18, 7, 17, 7, 17, { IID_ARMORSLAYER }, { AI_A_00, AI_B_00, 0x31, 0x00 } },
    { PID_UNKNOWN_8F, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 18, 9, 17, 9, 17, { IID_STEELSWORD }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_8F, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 18, 17, 24, 17, 24, { IID_STEELSWORD }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_8F, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 15, 16, 17, 16, 17, { IID_KILLERAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_8F, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 16, 25, 9, 25, 9, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_8F, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 16, 27, 9, 27, 9, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_8F, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 16, 27, 18, 27, 18, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_8F, JID_BISHOP, 0, TRUE, FACTION_ID_RED, 2, 28, 11, 28, 11, { IID_LIGHTNING, IID_MENDSTAFF, IID_SILENCESTAFF }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_8F, JID_BISHOP, 0, TRUE, FACTION_ID_RED, 1, 22, 6, 22, 6, { IID_LIGHTNING, IID_PHYSICSTAFF }, { AI_A_0E, AI_B_03, 0x09, 0x00 } },
    { PID_UNKNOWN_8F, JID_SNIPER, 0, TRUE, FACTION_ID_RED, 6, 5, 13, 5, 13, { IID_SILVERBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_8F, JID_SNIPER, 0, TRUE, FACTION_ID_RED, 5, 5, 14, 5, 14, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_DOUGLAS, JID_GENERAL, 0, FALSE, FACTION_ID_RED, 10, 3, 6, 3, 6, { IID_SILVERAXE }, { AI_A_08, AI_B_02, 0x09, 0x00 } },
    { PID_UNKNOWN_61, JID_GENERAL, 0, FALSE, FACTION_ID_RED, 6, 4, 7, 4, 7, { IID_SILVERLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_5E, JID_PALADIN, 0, FALSE, FACTION_ID_RED, 5, 3, 8, 3, 8, { IID_SILVERLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_HUGH, JID_MAGE, 0, FALSE, FACTION_ID_RED, 15, 22, 11, 22, 11, { IID_ELFIRE, IID_MEMBERCARD, IID_ELIXIR }, { AI_A_00, AI_B_0B, 0x0B, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867EEC4
struct UnitInfo CONST_DATA UnitInfo_Unk_0867EEC4[] =
{
    { PID_UNKNOWN_8F, JID_MAGE, 0, TRUE, FACTION_ID_RED, 16, 3, 11, 3, 11, { IID_ELFIRE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_8F, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 16, 21, 1, 21, 1, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_8F, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 14, 6, 22, 6, 22, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_8F, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 15, 13, 22, 13, 22, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867EF14
struct UnitInfo CONST_DATA UnitInfo_Unk_0867EF14[] =
{
    { PID_UNKNOWN_8F, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 16, 3, 11, 3, 11, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_8F, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 16, 21, 1, 21, 1, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_8F, JID_MAGE, 0, TRUE, FACTION_ID_RED, 14, 7, 1, 7, 1, { IID_ELFIRE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867EF54
struct UnitInfo CONST_DATA UnitInfo_Unk_0867EF54[] =
{
    { PID_UNKNOWN_8F, JID_MAGE, 0, TRUE, FACTION_ID_RED, 14, 30, 22, 30, 22, { IID_BOLTING }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867EF74
struct UnitInfo CONST_DATA UnitInfo_Unk_0867EF74[] =
{
    { PID_CATH, JID_THIEF_F, 0, FALSE, FACTION_ID_RED, 5, 13, 22, 12, 22, { IID_IRONSWORD, IID_LOCKPICK, IID_VULNERARY }, { AI_A_06, AI_B_05, 0x1B, 0x00 } },
    { PID_UNKNOWN_90, JID_THIEF, 0, TRUE, FACTION_ID_RED, 13, 21, 1, 21, 2, { IID_IRONSWORD, IID_LOCKPICK }, { AI_A_06, AI_B_05, 0x19, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867EFA4
struct UnitInfo CONST_DATA UnitInfo_Unk_0867EFA4[] =
{
    { PID_ZEISS, JID_WYVERNRIDER, 0, FALSE, FACTION_ID_RED, 7, 1, 0, 1, 1, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867EFC4
struct UnitInfo CONST_DATA UnitInfo_Unk_0867EFC4[] =
{
    { PID_GALLE, JID_WYVERNLORD, 0, FALSE, FACTION_ID_RED, 10, 1, 0, 1, 1, { IID_BRAVELANCE }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867EFE4
struct UnitInfo CONST_DATA UnitInfo_Unk_0867EFE4[] =
{
    { 0 }, // end
};

// UnitInfo @ 0867EFF4
struct UnitInfo CONST_DATA UnitInfo_Unk_0867EFF4[] =
{
    { PID_MURDOCK, JID_GENERAL, 0, FALSE, FACTION_ID_RED, 10, 14, 4, 14, 4, { IID_JAVELIN, IID_SILVERSWORD, IID_SPEEDWING, IID_BLUEGEM }, { AI_A_03, AI_B_03, 0x01, 0x20 } },
    { 0 }, // end
};

// EventScr @ 0867F014
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867EBA4[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867EBA4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867F028
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867EC94[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_0867EC94)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867F044
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867EEC4[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867EEC4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867F058
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867EF14[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867EF14)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867F06C
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867EF54[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867EF54)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867F080
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867EF74[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867EF74)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867F094
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867EFA4[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867EFA4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867F0A8
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867EFC4[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867EFC4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867F0BC
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867EFE4[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867EFE4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867F0D0
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867EFF4[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867EFF4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 16 summary:
// Units UnitInfo_Unk_0867EBA4 1
// Units UnitInfo_Unk_0867EC94 2
// Units UnitInfo_Unk_0867EEC4 1
// Units UnitInfo_Unk_0867EF14 1
// Units UnitInfo_Unk_0867EF54 1
// Units UnitInfo_Unk_0867EF74 1
// Units UnitInfo_Unk_0867EFA4 1
// Units UnitInfo_Unk_0867EFC4 1
// Units UnitInfo_Unk_0867EFE4 1
// Units UnitInfo_Unk_0867EFF4 1

// UnitInfo @ 0867F0E4
struct UnitInfo CONST_DATA UnitInfo_Unk_0867F0E4[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 18, 6, 21, 6, 21, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY, IID_SILVERSWORD }, { 0 } },
    { PID_MARCUS, JID_PALADIN, PID_ROY, TRUE, FACTION_ID_BLUE, 13, 4, 19, 4, 19, { IID_SILVERLANCE, IID_IRONSWORD, IID_IRONLANCE, IID_HORSESLAYER }, { 0 } },
    { PID_ALEN, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 7, 19, 7, 19, { IID_STEELSWORD, IID_IRONLANCE, IID_JAVELIN, IID_SILVERLANCE }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 15, 8, 20, 8, 20, { IID_IRONLANCE, IID_JAVELIN, IID_SILVERLANCE, IID_CHESTKEY }, { 0 } },
    { PID_KLEIN, JID_SNIPER, PID_ROY, TRUE, FACTION_ID_BLUE, 5, 5, 20, 5, 20, { IID_IRONBOW, IID_SILVERBOW, IID_STEELBOW, IID_KILLERBOW }, { 0 } },
    { PID_ECHIDNA, JID_HERO_F, PID_ROY, TRUE, FACTION_ID_BLUE, 5, 6, 20, 6, 20, { IID_BRAVEAXE, IID_IRONSWORD, IID_ARMORSLAYER, IID_STEELSWORD }, { 0 } },
    { PID_CECILIA, JID_VALKYRIE, PID_ROY, TRUE, FACTION_ID_BLUE, 3, 4, 21, 4, 21, { IID_ELFIRE, IID_THUNDER, IID_BOLTING, IID_HEALSTAFF }, { 0 } },
    { PID_BARTRE, JID_WARRIOR, PID_ROY, TRUE, FACTION_ID_BLUE, 2, 7, 21, 7, 21, { IID_KILLERAXE, IID_IRONAXE, IID_HANDAXE, IID_HALBERD }, { 0 } },
    { PID_LARUM, JID_DANCER, PID_ROY, TRUE, FACTION_ID_BLUE, 1, 9, 21, 9, 21, { IID_PUREWATER, IID_CHESTKEY, IID_VULNERARY }, { 0 } },
    { PID_RAIGH, JID_SHAMAN, PID_ROY, TRUE, FACTION_ID_BLUE, 16, 5, 22, 5, 22, { IID_NOSFERATU, IID_FLUX, IID_ECLIPSE, IID_VULNERARY }, { 0 } },
    { PID_SHANNA, JID_PEGASUSKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 6, 22, 6, 22, { IID_STEELLANCE, IID_JAVELIN, IID_SILVERLANCE, IID_HORSESLAYER }, { 0 } },
    { PID_SAUL, JID_PRIEST, PID_ROY, TRUE, FACTION_ID_BLUE, 18, 8, 22, 8, 22, { IID_MENDSTAFF, IID_RESTORESTAFF, IID_WARPSTAFF, IID_RECOVERSTAFF }, { 0 } },
    { PID_THEA, JID_PEGASUSKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 10, 22, 10, 22, { IID_STEELLANCE, IID_JAVELIN, IID_SILVERLANCE, IID_HORSESLAYER }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 9, 23, 9, 23, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_RESTORESTAFF }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867F1D4
struct UnitInfo CONST_DATA UnitInfo_Unk_0867F1D4[] =
{
    { PID_UNKNOWN_5E, JID_PALADIN, 0, FALSE, FACTION_ID_RED, 10, 29, 3, 29, 3, { IID_SILVERAXE, IID_JAVELIN }, { AI_A_03, AI_B_03, 0x00, 0x20 } },
    { PID_UNKNOWN_91, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 16, 28, 4, 28, 4, { IID_HORSESLAYER }, { AI_A_00, AI_B_03, 0x39, 0x00 } },
    { PID_UNKNOWN_91, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 16, 30, 4, 30, 4, { IID_AXEREAVER }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_91, JID_MAGE, 0, TRUE, FACTION_ID_RED, 17, 25, 3, 25, 3, { IID_ELFIRE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_91, JID_MAGE, 0, TRUE, FACTION_ID_RED, 17, 28, 9, 28, 9, { IID_FIMBULVETR }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_91, JID_MAGE, 0, TRUE, FACTION_ID_RED, 16, 28, 20, 28, 20, { IID_THUNDER }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_91, JID_MAGE, 0, TRUE, FACTION_ID_RED, 15, 6, 10, 6, 10, { IID_THUNDER }, { AI_A_03, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_91, JID_PALADIN, 0, TRUE, FACTION_ID_RED, 5, 28, 16, 28, 16, { IID_SILVERLANCE, IID_ELIXIR }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_91, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 17, 27, 15, 27, 15, { IID_KILLERLANCE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_91, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 17, 27, 17, 27, 17, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_91, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 16, 29, 15, 29, 15, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_91, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 16, 29, 17, 29, 17, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_91, JID_PALADIN, 0, TRUE, FACTION_ID_RED, 5, 6, 12, 6, 12, { IID_SILVERLANCE, IID_ELIXIR }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_91, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 17, 5, 13, 5, 13, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_91, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 15, 7, 13, 7, 13, { IID_KILLERLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_91, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 15, 20, 22, 20, 22, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_91, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 15, 23, 23, 23, 23, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_91, JID_PALADIN, 0, TRUE, FACTION_ID_RED, 5, 21, 5, 21, 5, { IID_SILVERLANCE, IID_ELIXIR }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_91, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 16, 20, 6, 20, 6, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_91, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 15, 22, 6, 22, 6, { IID_AXEREAVER }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_91, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 15, 20, 4, 20, 4, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_91, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 15, 22, 4, 22, 4, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_91, JID_BISHOP, 0, TRUE, FACTION_ID_RED, 6, 29, 12, 29, 12, { IID_PHYSICSTAFF, IID_PURGE }, { AI_A_00, AI_B_00, 0x11, 0x00 } },
    { PID_UNKNOWN_91, JID_BISHOP, 0, TRUE, FACTION_ID_RED, 5, 29, 5, 29, 5, { IID_PHYSICSTAFF, IID_DIVINE, IID_SLEEPSTAFF }, { AI_A_0E, AI_B_03, 0x11, 0x20 } },
    { PID_UNKNOWN_91, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 17, 17, 14, 17, 14, { IID_STEELBOW, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x29, 0x00 } },
    { PID_UNKNOWN_91, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 17, 18, 14, 18, 14, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_91, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 17, 21, 17, 21, 17, { IID_STEELBOW, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x29, 0x00 } },
    { PID_UNKNOWN_91, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 17, 27, 12, 27, 12, { IID_STEELBOW, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867F3A4
struct UnitInfo CONST_DATA UnitInfo_Unk_0867F3A4[] =
{
    { PID_UNKNOWN_91, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 16, 28, 6, 28, 6, { IID_STEELSWORD, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_91, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 15, 24, 3, 24, 3, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867F3D4
struct UnitInfo CONST_DATA UnitInfo_Unk_0867F3D4[] =
{
    { PID_UNKNOWN_91, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 13, 31, 23, 31, 23, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_91, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 13, 30, 23, 30, 23, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867F404
struct UnitInfo CONST_DATA UnitInfo_Unk_0867F404[] =
{
    { PID_UNKNOWN_91, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 17, 29, 7, 29, 7, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867F424
struct UnitInfo CONST_DATA UnitInfo_Unk_0867F424[] =
{
    { PID_GEESE, JID_PIRATE, 0, FALSE, FACTION_ID_GREEN, 18, 6, 2, 6, 2, { IID_KILLERAXE, IID_HANDAXE }, { AI_A_00, AI_B_0D } },
    { 0 }, // end
};

// UnitInfo @ 0867F444
struct UnitInfo CONST_DATA UnitInfo_Unk_0867F444[] =
{
    { PID_UNKNOWN_94, JID_PIRATE, 0, TRUE, FACTION_ID_GREEN, 18, 5, 1, 5, 1, { IID_STEELAXE }, { AI_A_03, AI_B_03 } },
    { PID_UNKNOWN_94, JID_PIRATE, 0, TRUE, FACTION_ID_GREEN, 18, 6, 1, 6, 1, { IID_STEELAXE, IID_VULNERARY }, { AI_A_03, AI_B_03 } },
    { PID_UNKNOWN_94, JID_PIRATE, 0, TRUE, FACTION_ID_GREEN, 18, 7, 1, 7, 1, { IID_STEELAXE, IID_VULNERARY }, { AI_A_03, AI_B_03 } },
    { PID_UNKNOWN_94, JID_PIRATE, 0, TRUE, FACTION_ID_GREEN, 18, 7, 0, 7, 0, { IID_STEELAXE, IID_VULNERARY }, { AI_A_03, AI_B_03 } },
    { PID_UNKNOWN_94, JID_PIRATE, 0, TRUE, FACTION_ID_GREEN, 18, 6, 0, 6, 0, { IID_STEELAXE }, { AI_A_03, AI_B_03 } },
    { 0 }, // end
};

// UnitInfo @ 0867F4A4
struct UnitInfo CONST_DATA UnitInfo_Unk_0867F4A4[] =
{
    { PID_DOUGLAS, JID_GENERAL, 0, FALSE, FACTION_ID_BLUE, 10, 0, 19, 0, 20, { IID_SILVERLANCE, IID_SILVERAXE }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867F4C4
struct UnitInfo CONST_DATA UnitInfo_Unk_0867F4C4[] =
{
    { PID_UNKNOWN_61, JID_GENERAL, 0, TRUE, FACTION_ID_RED, 18, 29, 3, 29, 3, { IID_STEELAXE }, { AI_A_03, AI_B_03 } },
    { 0 }, // end
};

// UnitInfo @ 0867F4E4
struct UnitInfo CONST_DATA UnitInfo_Unk_0867F4E4[] =
{
    { PID_YODER, JID_BISHOP, 0, TRUE, FACTION_ID_GREEN, 18, 3, 20, 3, 20, { IID_STEELAXE }, { AI_A_03, AI_B_03 } },
    { 0 }, // end
};

// UnitInfo @ 0867F504
struct UnitInfo CONST_DATA UnitInfo_Unk_0867F504[] =
{
    { PID_GALLE, JID_WYVERNLORD, 0, TRUE, FACTION_ID_RED, 18, 29, 3, 28, 7, { IID_STEELAXE, IID_VULNERARY }, { AI_A_03, AI_B_03 } },
    { PID_MURDOCK, JID_GENERAL, 0, TRUE, FACTION_ID_RED, 18, 29, 3, 29, 7, { IID_STEELAXE, IID_VULNERARY }, { AI_A_03, AI_B_03 } },
    { 0 }, // end
};

// UnitInfo @ 0867F534
struct UnitInfo CONST_DATA UnitInfo_Unk_0867F534[] =
{
    { PID_UNKNOWN_5E, JID_PALADIN, 0, FALSE, FACTION_ID_RED, 10, 29, 3, 29, 3, { IID_SILVERAXE, IID_JAVELIN }, { AI_A_03, AI_B_03, 0x00, 0x20 } },
    { 0 }, // end
};

// EventScr @ 0867F554
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867F0E4[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867F0E4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867F568
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867F1D4[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_0867F1D4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867F584
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867F3A4[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867F3A4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867F598
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867F3D4[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867F3D4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867F5AC
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867F404[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867F404)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867F5C0
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867F424[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867F424)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867F5D4
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867F444[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867F444)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867F5E8
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867F4A4[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867F4A4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867F5FC
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867F4C4[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867F4C4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867F610
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867F4E4[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867F4E4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867F624
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867F504[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867F504)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867F638
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867F534[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867F534)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 17 summary:
// Units UnitInfo_Unk_0867F0E4 1
// Units UnitInfo_Unk_0867F1D4 2
// Units UnitInfo_Unk_0867F3A4 1
// Units UnitInfo_Unk_0867F3D4 1
// Units UnitInfo_Unk_0867F404 1
// Units UnitInfo_Unk_0867F424 1
// Units UnitInfo_Unk_0867F444 1
// Units UnitInfo_Unk_0867F4A4 1
// Units UnitInfo_Unk_0867F4C4 1
// Units UnitInfo_Unk_0867F4E4 1
// Units UnitInfo_Unk_0867F504 1
// Units UnitInfo_Unk_0867F534 1

// UnitInfo @ 0867F64C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867F64C[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 19, 2, 29, 2, 29, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY, IID_SILVERSWORD }, { 0 } },
    { PID_MARCUS, JID_PALADIN, PID_ROY, TRUE, FACTION_ID_BLUE, 14, 2, 26, 2, 26, { IID_SILVERLANCE, IID_IRONSWORD, IID_IRONLANCE, IID_HORSESLAYER }, { 0 } },
    { PID_ALEN, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 1, 27, 1, 27, { IID_STEELSWORD, IID_IRONLANCE, IID_JAVELIN, IID_SILVERLANCE }, { 0 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 3, 27, 3, 27, { IID_STEELSWORD, IID_KILLERLANCE, IID_JAVELIN, IID_HORSESLAYER }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 16, 5, 27, 5, 27, { IID_IRONLANCE, IID_JAVELIN, IID_SILVERLANCE, IID_CHESTKEY }, { 0 } },
    { PID_KLEIN, JID_SNIPER, PID_ROY, TRUE, FACTION_ID_BLUE, 5, 0, 28, 0, 28, { IID_IRONBOW, IID_SILVERBOW, IID_STEELBOW, IID_KILLERBOW }, { 0 } },
    { PID_ECHIDNA, JID_HERO_F, PID_ROY, TRUE, FACTION_ID_BLUE, 6, 2, 28, 2, 28, { IID_BRAVEAXE, IID_IRONSWORD, IID_ARMORSLAYER, IID_STEELSWORD }, { 0 } },
    { PID_BARTRE, JID_WARRIOR, PID_ROY, TRUE, FACTION_ID_BLUE, 3, 4, 28, 4, 28, { IID_KILLERAXE, IID_IRONAXE, IID_HANDAXE, IID_HALBERD }, { 0 } },
    { PID_FIR, JID_MYRMIDON_F, PID_ROY, TRUE, FACTION_ID_BLUE, 18, 6, 28, 6, 28, { IID_KILLINGEDGE, IID_IRONSWORD, IID_VULNERARY, IID_STEELSWORD }, { 0 } },
    { PID_SHANNA, JID_PEGASUSKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 1, 29, 1, 29, { IID_STEELLANCE, IID_JAVELIN, IID_HORSESLAYER, IID_BRAVELANCE }, { 0 } },
    { PID_MELADY, JID_WYVERNRIDER_F, PID_ROY, TRUE, FACTION_ID_BLUE, 14, 0, 30, 0, 30, { IID_STEELLANCE, IID_JAVELIN, IID_SILVERLANCE, IID_HORSESLAYER }, { 0 } },
    { PID_ZEISS, JID_WYVERNRIDER, PID_ROY, TRUE, FACTION_ID_BLUE, 7, 3, 29, 3, 29, { IID_STEELLANCE, IID_JAVELIN, IID_SILVERLANCE, IID_HORSESLAYER }, { 0 } },
    { PID_CECILIA, JID_VALKYRIE, PID_ROY, TRUE, FACTION_ID_BLUE, 6, 2, 30, 2, 30, { IID_ELFIRE, IID_THUNDER, IID_BOLTING, IID_HEALSTAFF }, { 0 } },
    { PID_LARUM, JID_DANCER, PID_ROY, TRUE, FACTION_ID_BLUE, 3, 4, 30, 4, 30, { IID_PUREWATER, IID_CHESTKEY, IID_VULNERARY }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 5, 29, 5, 29, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_RESTORESTAFF }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867F74C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867F74C[] =
{
    { PID_UNKNOWN_5F, JID_BISHOP, 0, FALSE, FACTION_ID_RED, 10, 19, 3, 19, 3, { IID_PURGE, IID_DIVINE }, { AI_A_03, AI_B_03, 0x10, 0x20 } },
    { PID_UNKNOWN_95, JID_FALCONKNIGHT, 0, TRUE, FACTION_ID_RED, 6, 8, 4, 8, 4, { IID_SILVERLANCE }, { AI_A_00, AI_B_06 } },
    { PID_UNKNOWN_95, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 17, 7, 5, 7, 5, { IID_AXEREAVER }, { AI_A_00, AI_B_06 } },
    { PID_UNKNOWN_95, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 17, 8, 5, 8, 5, { IID_KILLERLANCE }, { AI_A_00, AI_B_06 } },
    { PID_UNKNOWN_95, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 17, 9, 5, 9, 5, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_06 } },
    { PID_UNKNOWN_95, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 17, 10, 5, 10, 5, { IID_STEELLANCE }, { AI_A_00, AI_B_06 } },
    { PID_UNKNOWN_95, JID_FALCONKNIGHT, 0, TRUE, FACTION_ID_RED, 6, 22, 13, 22, 13, { IID_SILVERLANCE }, { AI_A_00, AI_B_03 } },
    { PID_UNKNOWN_95, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 17, 21, 11, 21, 11, { IID_AXEREAVER }, { AI_A_00, AI_B_03 } },
    { PID_UNKNOWN_95, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 17, 21, 12, 21, 12, { IID_AXEREAVER }, { AI_A_00, AI_B_03 } },
    { PID_UNKNOWN_95, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 17, 21, 13, 21, 13, { IID_KILLERLANCE }, { AI_A_00, AI_B_03 } },
    { PID_UNKNOWN_95, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 16, 21, 14, 21, 14, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_03 } },
    { PID_UNKNOWN_96, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 17, 20, 27, 20, 27, { IID_HORSESLAYER }, { AI_A_00, AI_B_03, 0x3A, 0x00 } },
    { PID_UNKNOWN_96, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 17, 20, 28, 20, 28, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_96, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 16, 20, 29, 20, 29, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_96, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 17, 20, 30, 20, 30, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_97, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 17, 4, 15, 4, 15, { IID_ARMORSLAYER }, { AI_A_00, AI_B_00, 0x31, 0x00 } },
    { PID_UNKNOWN_97, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 16, 6, 15, 6, 15, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_97, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 16, 7, 18, 7, 18, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_97, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 16, 4, 21, 4, 21, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_97, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 17, 14, 10, 14, 10, { IID_LIGHTBRAND }, { AI_A_00, AI_B_06, 0x02, 0x00 } },
    { PID_UNKNOWN_97, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 17, 13, 11, 13, 11, { IID_STEELSWORD }, { AI_A_00, AI_B_06, 0x02, 0x00 } },
    { PID_UNKNOWN_97, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 17, 14, 12, 14, 12, { IID_STEELSWORD }, { AI_A_00, AI_B_06, 0x02, 0x00 } },
    { PID_UNKNOWN_97, JID_PRIEST, 0, TRUE, FACTION_ID_RED, 15, 6, 13, 6, 13, { IID_PHYSICSTAFF }, { AI_A_0E, AI_B_03, 0x10, 0x20 } },
    { PID_UNKNOWN_97, JID_PRIEST, 0, TRUE, FACTION_ID_RED, 15, 18, 15, 18, 15, { IID_MENDSTAFF, IID_SILENCESTAFF }, { AI_A_00, AI_B_00, 0x10, 0x00 } },
    { PID_UNKNOWN_97, JID_PRIEST, 0, TRUE, FACTION_ID_RED, 15, 15, 6, 15, 6, { IID_PHYSICSTAFF }, { AI_A_0E, AI_B_03, 0x10, 0x20 } },
    { PID_UNKNOWN_97, JID_PRIEST, 0, TRUE, FACTION_ID_RED, 15, 16, 6, 16, 6, { IID_MENDSTAFF, IID_BERSERKSTAFF }, { AI_A_00, AI_B_00, 0x10, 0x00 } },
    { PID_UNKNOWN_97, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 18, 17, 17, 17, 17, { IID_IRONBOW }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_97, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 18, 5, 14, 5, 14, { IID_IRONBOW }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_97, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 18, 18, 6, 18, 6, { IID_NOSFERATU }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_97, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 18, 20, 6, 20, 6, { IID_FLUX }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_97, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 18, 18, 16, 18, 16, { IID_FLUX }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_97, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 18, 18, 18, 18, 18, { IID_FLUX }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867F95C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867F95C[] =
{
    { PID_UNKNOWN_95, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 17, 10, 0, 10, 0, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_95, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 17, 12, 0, 12, 0, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867F98C
struct UnitInfo CONST_DATA UnitInfo_Unk_0867F98C[] =
{
    { PID_UNKNOWN_95, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 17, 22, 9, 22, 9, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_95, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 17, 22, 11, 22, 11, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867F9BC
struct UnitInfo CONST_DATA UnitInfo_Unk_0867F9BC[] =
{
    { PID_UNKNOWN_98, JID_BRIGAND, 0, TRUE, FACTION_ID_RED, 18, 15, 0, 15, 0, { IID_STEELAXE }, { AI_A_00, AI_B_04, 0x09, 0x00 } },
    { PID_UNKNOWN_98, JID_BRIGAND, 0, TRUE, FACTION_ID_RED, 18, 22, 15, 22, 15, { IID_HANDAXE }, { AI_A_00, AI_B_04, 0x09, 0x00 } },
    { 0 }, // end
};

// EventScr @ 0867F9EC
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867F64C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867F64C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867FA00
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867F74C[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_0867F74C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867FA1C
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867F95C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867F95C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867FA30
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867F98C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867F98C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867FA44
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867F9BC[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867F9BC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 18 summary:
// Units UnitInfo_Unk_0867F64C 1
// Units UnitInfo_Unk_0867F74C 2
// Units UnitInfo_Unk_0867F95C 1
// Units UnitInfo_Unk_0867F98C 1
// Units UnitInfo_Unk_0867F9BC 1

// UnitInfo @ 0867FA58
struct UnitInfo CONST_DATA UnitInfo_Unk_0867FA58[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 20, 2, 19, 2, 19, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY, IID_SILVERSWORD }, { 0 } },
    { PID_MARCUS, JID_PALADIN, PID_ROY, TRUE, FACTION_ID_BLUE, 15, 1, 21, 1, 21, { IID_SILVERLANCE, IID_IRONSWORD, IID_IRONLANCE, IID_HORSESLAYER }, { 0 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 3, 20, 3, 20, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 17, 1, 18, 1, 18, { IID_IRONLANCE, IID_JAVELIN, IID_SILVERLANCE, IID_CHESTKEY }, { 0 } },
    { PID_SHANNA, JID_PEGASUSKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 18, 0, 20, 0, 20, { IID_STEELLANCE, IID_JAVELIN, IID_SILVERLANCE, IID_HORSESLAYER }, { 0 } },
    { PID_ECHIDNA, JID_HERO_F, PID_ROY, TRUE, FACTION_ID_BLUE, 7, 2, 17, 2, 17, { IID_BRAVEAXE, IID_IRONSWORD, IID_ARMORSLAYER, IID_STEELSWORD }, { 0 } },
    { PID_BARTRE, JID_WARRIOR, PID_ROY, TRUE, FACTION_ID_BLUE, 4, 1, 16, 1, 16, { IID_KILLERAXE, IID_IRONAXE, IID_HANDAXE, IID_HALBERD }, { 0 } },
    { PID_FIR, JID_MYRMIDON_F, PID_ROY, TRUE, FACTION_ID_BLUE, 18, 0, 17, 0, 17, { IID_WODAO, IID_IRONSWORD, IID_HEROCREST, IID_STEELSWORD }, { 0 } },
    { PID_LUGH, JID_MAGE, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 3, 19, 3, 19, { IID_FIRE, IID_AIRCALIBUR, IID_ELFIRE, IID_THUNDER }, { 0 } },
    { PID_SIN, JID_NOMAD, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 2, 21, 2, 21, { IID_IRONBOW, IID_LONGBOW, IID_BRAVEBOW, IID_STEELBOW }, { 0 } },
    { PID_CHAD, JID_THIEF, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 3, 18, 3, 18, { IID_KILLINGEDGE, IID_LOCKPICK }, { 0 } },
    { PID_RAIGH, JID_SHAMAN, PID_ROY, TRUE, FACTION_ID_BLUE, 18, 4, 19, 4, 19, { IID_NOSFERATU, IID_FLUX, IID_ECLIPSE, IID_VULNERARY }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, TRUE, FACTION_ID_BLUE, 1, 0, 19, 0, 19, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_RESTORESTAFF }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867FB38
struct UnitInfo CONST_DATA UnitInfo_Unk_0867FB38[] =
{
    { PID_NIIME, JID_DRUID_F, PID_ROY, FALSE, FACTION_ID_BLUE, 18, 1, 20, 1, 20, { IID_FLUX, IID_ECLIPSE, IID_PHYSICSTAFF, IID_HEALSTAFF }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867FB58
struct UnitInfo CONST_DATA UnitInfo_Unk_0867FB58[] =
{
    { PID_UNKNOWN_60, JID_FALCONKNIGHT, 0, FALSE, FACTION_ID_RED, 9, 28, 3, 28, 3, { IID_SPEAR }, { AI_A_03, AI_B_03, 0x02, 0x20 } },
    { PID_UNKNOWN_99, JID_FALCONKNIGHT, 0, TRUE, FACTION_ID_RED, 7, 17, 5, 17, 5, { IID_SILVERLANCE, IID_ELIXIR }, { AI_A_00, AI_B_06, 0x02, 0x00 } },
    { PID_UNKNOWN_99, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 18, 16, 6, 16, 6, { IID_STEELLANCE }, { AI_A_00, AI_B_06, 0x02, 0x00 } },
    { PID_UNKNOWN_99, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 18, 17, 6, 17, 6, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_06, 0x02, 0x00 } },
    { PID_UNKNOWN_99, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 18, 18, 6, 18, 6, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_00, AI_B_06, 0x02, 0x00 } },
    { PID_UNKNOWN_99, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 18, 19, 6, 19, 6, { IID_STEELLANCE }, { AI_A_00, AI_B_09, 0x1A, 0x00 } },
    { PID_UNKNOWN_99, JID_FALCONKNIGHT, 0, TRUE, FACTION_ID_RED, 6, 4, 5, 4, 5, { IID_SILVERLANCE, IID_ELIXIR }, { AI_A_00, AI_B_06, 0x02, 0x00 } },
    { PID_UNKNOWN_99, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 18, 2, 6, 2, 6, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_09, 0x1A, 0x00 } },
    { PID_UNKNOWN_99, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 18, 3, 6, 3, 6, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_06, 0x02, 0x00 } },
    { PID_UNKNOWN_99, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 18, 4, 6, 4, 6, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_99, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 18, 5, 6, 5, 6, { IID_STEELLANCE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_99, JID_FALCONKNIGHT, 0, TRUE, FACTION_ID_RED, 8, 25, 18, 25, 18, { IID_SILVERLANCE, IID_ELIXIR }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_99, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 18, 24, 17, 24, 17, { IID_STEELLANCE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_99, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 18, 24, 18, 24, 18, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_99, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 16, 24, 19, 24, 19, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_99, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 16, 24, 20, 24, 20, { IID_STEELLANCE }, { AI_A_00, AI_B_09, 0x1A, 0x00 } },
    { PID_UNKNOWN_9A, JID_ARMOR_F, 0, TRUE, FACTION_ID_RED, 18, 27, 4, 27, 4, { IID_AXEREAVER, IID_JAVELIN }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_9A, JID_ARMOR_F, 0, TRUE, FACTION_ID_RED, 18, 29, 4, 29, 4, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_9A, JID_PALADIN, 0, TRUE, FACTION_ID_RED, 8, 19, 16, 19, 16, { IID_SILVERLANCE, IID_KNIGHTCREST }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9A, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 19, 18, 15, 18, 15, { IID_STEELSWORD, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9A, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 18, 19, 15, 19, 15, { IID_STEELSWORD, IID_JAVELIN }, { AI_A_00, AI_B_09, 0x1A, 0x00 } },
    { PID_UNKNOWN_9A, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 18, 18, 17, 18, 17, { IID_STEELSWORD, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9A, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 18, 19, 17, 19, 17, { IID_STEELSWORD }, { AI_A_00, AI_B_09, 0x18, 0x00 } },
    { PID_UNKNOWN_9A, JID_TROUBADOUR, 0, TRUE, FACTION_ID_RED, 19, 20, 16, 20, 16, { IID_MENDSTAFF, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x08, 0x00 } },
    { PID_UNKNOWN_9A, JID_PALADIN, 0, TRUE, FACTION_ID_RED, 7, 26, 9, 26, 9, { IID_SILVERLANCE, IID_ELIXIR }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_9A, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 19, 25, 8, 25, 8, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_9A, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 18, 25, 10, 25, 10, { IID_STEELSWORD, IID_JAVELIN }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_9A, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 18, 27, 8, 27, 8, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_9A, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 18, 27, 10, 27, 10, { IID_STEELSWORD }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_9A, JID_TROUBADOUR, 0, TRUE, FACTION_ID_RED, 19, 26, 7, 26, 7, { IID_MENDSTAFF, IID_VULNERARY }, { AI_A_00, AI_B_06 } },
    { PID_UNKNOWN_9A, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 18, 4, 2, 4, 2, { IID_IRONBOW, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x28, 0x00 } },
    { PID_UNKNOWN_9A, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 18, 13, 19, 13, 19, { IID_IRONBOW, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x28, 0x00 } },
    { PID_UNKNOWN_9A, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 18, 22, 13, 22, 13, { IID_IRONBOW, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x28, 0x00 } },
    { PID_UNKNOWN_9A, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 18, 23, 4, 23, 4, { IID_IRONBOW, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x28, 0x00 } },
    { PID_UNKNOWN_9A, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 18, 29, 17, 29, 17, { IID_IRONBOW, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x28, 0x00 } },
    { PID_UNKNOWN_9A, JID_DRUID, 0, TRUE, FACTION_ID_RED, 6, 22, 15, 22, 15, { IID_PHYSICSTAFF, IID_SILENCESTAFF }, { AI_A_0E, AI_B_03, 0x10, 0x20 } },
    { PID_UNKNOWN_9A, JID_DRUID, 0, TRUE, FACTION_ID_RED, 6, 11, 9, 11, 9, { IID_PHYSICSTAFF, IID_SLEEPSTAFF }, { AI_A_0E, AI_B_03, 0x10, 0x20 } },
    { 0 }, // end
};

// UnitInfo @ 0867FDB8
struct UnitInfo CONST_DATA UnitInfo_Unk_0867FDB8[] =
{
    { PID_UNKNOWN_9B, JID_BRIGAND, 0, TRUE, FACTION_ID_RED, 18, 13, 21, 13, 21, { IID_STEELAXE }, { AI_A_00, AI_B_04, 0x02, 0x00 } },
    { PID_UNKNOWN_9B, JID_BRIGAND, 0, TRUE, FACTION_ID_RED, 18, 17, 21, 17, 21, { IID_STEELAXE }, { AI_A_00, AI_B_04, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0867FDE8
struct UnitInfo CONST_DATA UnitInfo_Unk_0867FDE8[] =
{
    { PID_UNKNOWN_99, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 18, 1, 0, 1, 1, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_09, 0x0A, 0x00 } },
    { PID_UNKNOWN_99, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 18, 16, 20, 16, 21, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_00, AI_B_09, 0x0A, 0x00 } },
    { PID_UNKNOWN_99, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 18, 18, 0, 18, 1, { IID_STEELLANCE }, { AI_A_00, AI_B_09, 0x0A, 0x00 } },
    { 0 }, // end
};

// EventScr @ 0867FE28
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867FA58[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867FA58)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867FE3C
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867FB38[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867FB38)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867FE50
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867FB58[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_0867FB58)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867FE6C
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867FDB8[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867FDB8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0867FE80
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867FDE8[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867FDE8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 19 summary:
// Units UnitInfo_Unk_0867FA58 1
// Units UnitInfo_Unk_0867FB38 1
// Units UnitInfo_Unk_0867FB58 2
// Units UnitInfo_Unk_0867FDB8 1
// Units UnitInfo_Unk_0867FDE8 1

// UnitInfo @ 0867FE94
struct UnitInfo CONST_DATA UnitInfo_Unk_0867FE94[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 20, 19, 1, 19, 1, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY, IID_ARMORSLAYER }, { 0 } },
    { PID_MARCUS, JID_PALADIN, PID_ROY, TRUE, FACTION_ID_BLUE, 16, 16, 0, 16, 0, { IID_SILVERLANCE, IID_IRONSWORD, IID_IRONLANCE, IID_HORSESLAYER }, { 0 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 17, 1, 17, 1, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 18, 19, 3, 19, 3, { IID_IRONLANCE, IID_JAVELIN, IID_CHESTKEY }, { 0 } },
    { PID_MELADY, JID_WYVERNRIDER_F, PID_ROY, TRUE, FACTION_ID_BLUE, 15, 21, 3, 21, 3, { IID_STEELLANCE, IID_JAVELIN, IID_IRONLANCE, IID_VULNERARY }, { 0 } },
    { PID_ECHIDNA, JID_HERO_F, PID_ROY, TRUE, FACTION_ID_BLUE, 8, 16, 4, 16, 4, { IID_BRAVEAXE, IID_IRONSWORD, IID_IRONBLADE, IID_STEELSWORD }, { 0 } },
    { PID_BARTRE, JID_WARRIOR, PID_ROY, TRUE, FACTION_ID_BLUE, 5, 22, 4, 22, 4, { IID_STEELAXE, IID_IRONAXE, IID_HANDAXE }, { 0 } },
    { PID_HUGH, JID_MAGE, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 22, 0, 22, 0, { IID_FIRE, IID_AIRCALIBUR, IID_ELFIRE, IID_THUNDER }, { 0 } },
    { PID_CHAD, JID_THIEF, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 21, 1, 21, 1, { IID_IRONSWORD, IID_LOCKPICK }, { 0 } },
    { PID_IGRENE, JID_SNIPER_F, PID_ROY, TRUE, FACTION_ID_BLUE, 7, 20, 2, 20, 2, { IID_IRONBOW, IID_SILVERBOW, IID_VULNERARY, IID_STEELBOW }, { 0 } },
    { PID_CECILIA, JID_VALKYRIE, PID_ROY, TRUE, FACTION_ID_BLUE, 8, 18, 2, 18, 2, { IID_ELFIRE, IID_THUNDER, IID_HEALSTAFF, IID_VULNERARY }, { 0 } },
    { PID_THEA, JID_PEGASUSKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 17, 3, 17, 3, { IID_BRAVELANCE, IID_STEELLANCE, IID_JAVELIN, IID_IRONLANCE }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, TRUE, FACTION_ID_BLUE, 1, 19, 0, 19, 0, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_RESTORESTAFF }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0867FF74
struct UnitInfo CONST_DATA UnitInfo_Unk_0867FF74[] =
{
    { PID_UNKNOWN_61, JID_GENERAL, 0, FALSE, FACTION_ID_RED, 10, 3, 19, 3, 19, { IID_SPEAR, IID_REDGEM }, { AI_A_03, AI_B_03, 0x00, 0x20 } },
    { PID_UNKNOWN_9C, JID_ARMOR, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 20, 7, 18, 7, 18, { IID_HORSESLAYER }, { AI_A_03, AI_B_03, 0x38, 0x00 } },
    { PID_UNKNOWN_9C, JID_ARMOR, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 20, 15, 10, 15, 10, { IID_HORSESLAYER }, { AI_A_00, AI_B_03, 0x38, 0x00 } },
    { PID_UNKNOWN_9C, JID_ARMOR, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 19, 12, 21, 12, 21, { IID_AXEREAVER }, { AI_A_00, AI_B_03 } },
    { PID_UNKNOWN_9C, JID_ARMOR, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 19, 21, 15, 21, 15, { IID_AXEREAVER }, { AI_A_00, AI_B_03 } },
    { PID_UNKNOWN_9C, JID_MERCENARY, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 18, 14, 12, 14, 12, { IID_ARMORSLAYER }, { AI_A_00, AI_B_00, 0x30, 0x00 } },
    { PID_UNKNOWN_9C, JID_MERCENARY, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 18, 16, 12, 16, 12, { IID_ARMORSLAYER }, { AI_A_00, AI_B_00, 0x30, 0x00 } },
    { PID_UNKNOWN_9C, JID_MERCENARY, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 19, 9, 14, 9, 14, { IID_KILLINGEDGE }, { AI_A_00, AI_B_03 } },
    { PID_UNKNOWN_9C, JID_MERCENARY, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 18, 22, 12, 22, 12, { IID_LANCEREAVER }, { AI_A_00, AI_B_03 } },
    { PID_UNKNOWN_9C, JID_MERCENARY, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 19, 22, 14, 22, 14, { IID_KILLINGEDGE }, { AI_A_03, AI_B_03 } },
    { PID_UNKNOWN_9C, JID_MERCENARY, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 18, 9, 2, 9, 2, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x08, 0x00 } },
    { PID_UNKNOWN_9C, JID_MERCENARY, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 18, 7, 3, 7, 3, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x08, 0x00 } },
    { PID_UNKNOWN_9C, JID_MERCENARY, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 18, 28, 7, 28, 7, { IID_STEELSWORD }, { 0 } },
    { PID_UNKNOWN_9C, JID_HERO, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 7, 22, 16, 22, 16, { IID_IRONBLADE }, { AI_A_00, AI_B_03 } },
    { PID_UNKNOWN_9C, JID_HERO, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 7, 15, 13, 15, 13, { IID_LIGHTBRAND }, { AI_A_00, AI_B_00, 0x08, 0x00 } },
    { PID_UNKNOWN_9C, JID_SNIPER, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 8, 18, 11, 18, 11, { IID_LONGBOW }, { AI_A_00, AI_B_03, 0x28, 0x00 } },
    { PID_UNKNOWN_9C, JID_SNIPER, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 8, 22, 21, 22, 21, { IID_LONGBOW }, { AI_A_00, AI_B_06, 0x28, 0x00 } },
    { PID_UNKNOWN_9C, JID_SNIPER, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 8, 8, 20, 8, 20, { IID_KILLERBOW }, { AI_A_00, AI_B_03 } },
    { PID_UNKNOWN_9C, JID_DRUID, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 6, 14, 14, 14, 14, { IID_NOSFERATU }, { AI_A_00, AI_B_00, 0x08, 0x00 } },
    { PID_UNKNOWN_9C, JID_DRUID, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 6, 16, 14, 16, 14, { IID_FLUX, IID_SLEEPSTAFF, IID_REDGEM }, { AI_A_00, AI_B_00, 0x08, 0x00 } },
    { PID_UNKNOWN_9C, JID_DRUID, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 6, 23, 15, 23, 15, { IID_FLUX, IID_SLEEPSTAFF }, { AI_A_00, AI_B_03 } },
    { PID_UNKNOWN_9C, JID_DRUID, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 6, 1, 20, 1, 20, { IID_NOSFERATU, IID_BERSERKSTAFF }, { AI_A_03, AI_B_03 } },
    { PID_UNKNOWN_9C, JID_FIGHTER, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 20, 14, 9, 14, 9, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x08, 0x00 } },
    { PID_UNKNOWN_9C, JID_FIGHTER, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 20, 16, 9, 16, 9, { IID_SWORDREAVER, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x08, 0x00 } },
    { PID_UNKNOWN_9C, JID_FIGHTER, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 18, 20, 11, 20, 11, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_03 } },
    { PID_UNKNOWN_9C, JID_FIGHTER, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 19, 23, 11, 23, 11, { IID_SWORDREAVER, IID_VULNERARY }, { AI_A_00, AI_B_03 } },
    { PID_UNKNOWN_9C, JID_BISHOP, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 7, 15, 16, 15, 16, { IID_LIGHTNING, IID_PURGE, IID_PHYSICSTAFF }, { AI_A_0E, AI_B_03, 0x08, 0x20 } },
    { PID_UNKNOWN_9C, JID_BISHOP, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 7, 12, 14, 12, 14, { IID_LIGHTNING, IID_MENDSTAFF }, { AI_A_00, AI_B_03 } },
    { PID_UNKNOWN_9C, JID_BISHOP, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 7, 24, 19, 24, 19, { IID_LIGHTNING, IID_MENDSTAFF }, { AI_A_00, AI_B_06 } },
    { PID_UNKNOWN_AD, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 18, 3, 15, 3, 15, { IID_KILLERBOW, IID_ELYSIANWHIP }, { AI_A_03, AI_B_03, 0x28, 0x20 } },
    { PID_UNKNOWN_AD, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 18, 17, 25, 17, 25, { IID_STEELBOW }, { AI_A_03, AI_B_03, 0x28, 0x20 } },
    { PID_UNKNOWN_AD, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 18, 28, 12, 28, 12, { IID_STEELBOW }, { AI_A_03, AI_B_03, 0x28, 0x20 } },
    { PID_JUNO, JID_FALCONKNIGHT, PID_UNKNOWN_61, FALSE, FACTION_ID_GREEN, 9, 9, 7, 9, 7, { 0 }, { AI_A_03, AI_B_03, 0x10, 0x00 } },
    { PID_UNKNOWN_9D, JID_CIVILIAN_F, PID_UNKNOWN_61, FALSE, FACTION_ID_GREEN, 10, 7, 7, 7, 7, { 0 }, { AI_A_03, AI_B_0C, 0x10, 0x00 } },
    { PID_UNKNOWN_CE, JID_CIVILIAN_F, PID_UNKNOWN_61, FALSE, FACTION_ID_GREEN, 10, 6, 6, 6, 6, { 0 }, { AI_A_03, AI_B_0C, 0x10, 0x00 } },
    { PID_UNKNOWN_9D, JID_CIVILIAN_F, PID_UNKNOWN_61, FALSE, FACTION_ID_GREEN, 10, 10, 6, 10, 6, { 0 }, { AI_A_03, AI_B_0C, 0x10, 0x00 } },
    { PID_UNKNOWN_CE, JID_CIVILIAN_F, PID_UNKNOWN_61, FALSE, FACTION_ID_GREEN, 10, 8, 6, 8, 6, { 0 }, { AI_A_03, AI_B_0C, 0x10, 0x00 } },
    { PID_UNKNOWN_9D, JID_CIVILIAN_F, PID_UNKNOWN_61, FALSE, FACTION_ID_GREEN, 10, 9, 6, 9, 6, { 0 }, { AI_A_03, AI_B_0C, 0x10, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086801E4
struct UnitInfo CONST_DATA UnitInfo_Unk_086801E4[] =
{
    { PID_UNKNOWN_9C, JID_MERCENARY, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 18, 31, 19, 31, 19, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_9C, JID_MERCENARY, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 18, 31, 20, 31, 20, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08680214
struct UnitInfo CONST_DATA UnitInfo_Unk_08680214[] =
{
    { PID_UNKNOWN_9C, JID_FIGHTER, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 20, 29, 0, 29, 0, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_9C, JID_FIGHTER, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 20, 30, 0, 30, 0, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_9C, JID_FIGHTER, PID_UNKNOWN_61, TRUE, FACTION_ID_RED, 20, 31, 0, 31, 0, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08680254
struct UnitInfo CONST_DATA UnitInfo_Unk_08680254[] =
{
    { PID_CATH, JID_THIEF_F, 0, FALSE, FACTION_ID_RED, 5, 31, 20, 30, 20, { IID_IRONSWORD, IID_LOCKPICK, IID_VULNERARY }, { AI_A_06, AI_B_05, 0x1B, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08680274
struct UnitInfo CONST_DATA UnitInfo_Unk_08680274[] =
{
    { PID_UNKNOWN_9E, JID_THIEF, 0, TRUE, FACTION_ID_RED, 20, 13, 0, 13, 0, { IID_IRONSWORD, IID_LOCKPICK }, { AI_A_06, AI_B_05, 0x18, 0x00 } },
    { PID_UNKNOWN_9E, JID_THIEF, 0, TRUE, FACTION_ID_RED, 20, 14, 0, 14, 0, { IID_IRONSWORD, IID_LOCKPICK }, { AI_A_06, AI_B_05, 0x18, 0x00 } },
    { 0 }, // end
};

// EventScr @ 086802A4
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867FE94[] =
{
    EvtLoadUnits(UnitInfo_Unk_0867FE94)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086802B8
EventScr CONST_DATA EventScr_LoadUnits_Unk_0867FF74[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_0867FF74)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086802D4
EventScr CONST_DATA EventScr_LoadUnits_Unk_086801E4[] =
{
    EvtLoadUnits(UnitInfo_Unk_086801E4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086802E8
EventScr CONST_DATA EventScr_LoadUnits_Unk_08680214[] =
{
    EvtLoadUnits(UnitInfo_Unk_08680214)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086802FC
EventScr CONST_DATA EventScr_LoadUnits_Unk_08680254[] =
{
    EvtLoadUnits(UnitInfo_Unk_08680254)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08680310
EventScr CONST_DATA EventScr_LoadUnits_Unk_08680274[] =
{
    EvtLoadUnits(UnitInfo_Unk_08680274)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 20 summary:
// Units UnitInfo_Unk_0867FE94 1
// Units UnitInfo_Unk_0867FF74 2
// Units UnitInfo_Unk_086801E4 1
// Units UnitInfo_Unk_08680214 1
// Units UnitInfo_Unk_08680254 1
// Units UnitInfo_Unk_08680274 1

// UnitInfo @ 08680324
struct UnitInfo CONST_DATA UnitInfo_Unk_08680324[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 20, 2, 3, 2, 3, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY, IID_ARMORSLAYER }, { 0 } },
    { PID_ZEISS, JID_WYVERNRIDER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 3, 2, 3, 2, { IID_SILVERLANCE, IID_IRONLANCE, IID_HORSESLAYER }, { 0 } },
    { PID_ALEN, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 1, 4, 1, 4, { IID_IRONSWORD, IID_SILVERLANCE, IID_JAVELIN, IID_KNIGHTCREST }, { 0 } },
    { PID_WOLT, JID_ARCHER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 3, 4, 3, 4, { IID_LONGBOW, IID_STEELBOW, IID_IRONBOW, IID_ORIONSBOLT }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 19, 4, 1, 4, 1, { IID_IRONLANCE, IID_JAVELIN, IID_CHESTKEY }, { 0 } },
    { PID_HUGH, JID_MAGE, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 4, 3, 4, 3, { IID_FIRE, IID_AIRCALIBUR, IID_ELFIRE, IID_THUNDER }, { 0 } },
    { PID_FIR, JID_MYRMIDON_F, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 2, 5, 2, 5, { IID_WODAO, IID_IRONSWORD, IID_IRONBLADE, IID_STEELSWORD }, { 0 } },
    { PID_SUE, JID_NOMAD_F, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 5, 4, 5, 4, { IID_SHORTBOW, IID_STEELBOW, IID_IRONBOW, IID_ORIONSBOLT }, { 0 } },
    { PID_CHAD, JID_THIEF, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 3, 6, 3, 6, { IID_IRONSWORD, IID_LOCKPICK }, { 0 } },
    { PID_THEA, JID_PEGASUSKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 4, 5, 4, 5, { IID_BRAVELANCE, IID_STEELLANCE, IID_JAVELIN, IID_ELYSIANWHIP }, { 0 } },
    { PID_KLEIN, JID_SNIPER, PID_ROY, TRUE, FACTION_ID_BLUE, 10, 5, 2, 5, 2, { IID_IRONBOW, IID_SILVERBOW, IID_KILLERBOW, IID_STEELBOW }, { 0 } },
    { PID_CLARINE, JID_TROUBADOUR, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 1, 6, 1, 6, { IID_PHYSICSTAFF, IID_MENDSTAFF, IID_HEALSTAFF }, { 0 } },
    { PID_LILINA, JID_MAGE_F, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 6, 3, 6, 3, { IID_ELFIRE, IID_THUNDER, IID_GUIDINGRING }, { 0 } },
    { PID_DIECK, JID_MERCENARY, PID_ROY, TRUE, FACTION_ID_BLUE, 15, 2, 7, 2, 7, { IID_BRAVESWORD, IID_STEELAXE, IID_HEROCREST }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, TRUE, FACTION_ID_BLUE, 1, 2, 1, 2, 1, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_RESTORESTAFF }, { 0 } },
    { PID_WARD, JID_FIGHTER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 0, 3, 0, 3, { IID_STEELAXE }, { 0 } },
    { PID_JUNO, JID_FALCONKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 15, 0, 5, 0, 5, { IID_SILVERLANCE, IID_IRONSWORD, IID_IRONLANCE }, { 0 } },
    { PID_SHANNA, JID_PEGASUSKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 6, 1, 6, 1, { IID_BRAVELANCE, IID_STEELLANCE, IID_JAVELIN, IID_ELYSIANWHIP }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 08680454
struct UnitInfo CONST_DATA UnitInfo_Unk_08680454[] =
{
    { PID_MURDOCK, JID_GENERAL, 0, FALSE, FACTION_ID_RED, 20, 24, 27, 24, 27, { IID_TOMAHAWK, IID_KNIGHTCREST }, { AI_A_03, AI_B_03, 0x02, 0x20 } },
    { PID_UNKNOWN_9F, JID_WYVERNLORD, 0, TRUE, FACTION_ID_RED, 10, 29, 5, 29, 5, { IID_SILVERLANCE }, { AI_A_00, AI_B_06, 0x02, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 20, 28, 5, 28, 5, { IID_KILLERLANCE, IID_VULNERARY }, { AI_A_00, AI_B_06, 0x02, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 20, 28, 6, 28, 6, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_06, 0x02, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 20, 27, 3, 27, 3, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_06, 0x02, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 20, 27, 7, 27, 7, { IID_STEELLANCE }, { AI_A_00, AI_B_06, 0x02, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNLORD, 0, TRUE, FACTION_ID_RED, 10, 15, 20, 15, 20, { IID_SILVERLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 20, 15, 19, 15, 19, { IID_KILLERLANCE, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 20, 16, 19, 16, 19, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 20, 14, 18, 14, 18, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 20, 17, 18, 17, 18, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNLORD, 0, TRUE, FACTION_ID_RED, 10, 3, 27, 3, 27, { IID_SILVERLANCE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 20, 3, 26, 3, 26, { IID_KILLERLANCE, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 20, 4, 26, 4, 26, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 20, 2, 25, 2, 25, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 10, 5, 25, 5, 25, { IID_STEELLANCE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 10, 28, 21, 28, 21, { IID_FIRESTONE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 10, 17, 25, 17, 25, { IID_FIRESTONE }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_BISHOP, 0, TRUE, FACTION_ID_RED, 10, 12, 23, 12, 23, { IID_DIVINE, IID_PHYSICSTAFF }, { AI_A_00, AI_B_00, 0x08, 0x00 } },
    { PID_UNKNOWN_9F, JID_BISHOP, 0, TRUE, FACTION_ID_RED, 10, 26, 19, 26, 19, { IID_DIVINE, IID_PHYSICSTAFF }, { AI_A_00, AI_B_03 } },
    { PID_UNKNOWN_9F, JID_BISHOP, 0, TRUE, FACTION_ID_RED, 10, 14, 12, 14, 12, { IID_DIVINE, IID_PHYSICSTAFF }, { AI_A_00, AI_B_00, 0x08, 0x00 } },
    { PID_UNKNOWN_9F, JID_SAGE, 0, TRUE, FACTION_ID_RED, 12, 23, 4, 23, 4, { IID_ELFIRE, IID_MENDSTAFF }, { AI_A_00, AI_B_00, 0x08, 0x00 } },
    { PID_UNKNOWN_9F, JID_SAGE, 0, TRUE, FACTION_ID_RED, 12, 4, 16, 4, 16, { IID_AIRCALIBUR, IID_MENDSTAFF }, { AI_A_00, AI_B_00, 0x28, 0x00 } },
    { PID_UNKNOWN_9F, JID_SAGE, 0, TRUE, FACTION_ID_RED, 12, 24, 30, 24, 30, { IID_BOLTING, IID_FIRE, IID_PHYSICSTAFF }, { AI_A_03, AI_B_03 } },
    { PID_UNKNOWN_9F, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 20, 9, 17, 9, 17, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 20, 16, 13, 16, 13, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 20, 23, 15, 23, 15, { IID_STEELLANCE }, { AI_A_00, AI_B_06, 0x02, 0x00 } },
    { PID_UNKNOWN_9F, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 20, 22, 27, 22, 27, { IID_HORSESLAYER }, { AI_A_00, AI_B_03, 0x3A, 0x00 } },
    { PID_UNKNOWN_9F, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 20, 26, 27, 26, 27, { IID_HORSESLAYER }, { AI_A_00, AI_B_03, 0x3A, 0x00 } },
    { PID_UNKNOWN_9F, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 19, 9, 19, 9, 19, { IID_IRONBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_9F, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 19, 16, 15, 16, 15, { IID_IRONBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_9F, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 19, 24, 17, 24, 17, { IID_IRONBOW }, { AI_A_00, AI_B_06, 0x2A, 0x00 } },
    { PID_UNKNOWN_9F, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 20, 8, 18, 8, 18, { IID_LONGBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_9F, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 20, 17, 14, 17, 14, { IID_LONGBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_9F, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 20, 23, 16, 23, 16, { IID_LONGBOW }, { AI_A_00, AI_B_06, 0x2A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08680694
struct UnitInfo CONST_DATA UnitInfo_Unk_08680694[] =
{
    { PID_UNKNOWN_9F, JID_WYVERNLORD, 0, TRUE, FACTION_ID_RED, 10, 18, 6, 18, 6, { IID_SILVERLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 20, 17, 5, 17, 5, { IID_KILLERLANCE, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 20, 17, 7, 17, 7, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 20, 19, 7, 19, 7, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 20, 19, 5, 19, 5, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNLORD, 0, TRUE, FACTION_ID_RED, 10, 7, 34, 7, 34, { IID_SILVERLANCE }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 20, 6, 33, 6, 33, { IID_KILLERLANCE, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 20, 8, 33, 8, 33, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 20, 8, 35, 8, 35, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 10, 6, 35, 6, 35, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08680744
struct UnitInfo CONST_DATA UnitInfo_Unk_08680744[] =
{
    { PID_YODER, JID_BISHOP, 0, FALSE, FACTION_ID_BLUE, 20, 1, 2, 1, 2, { IID_RECOVERSTAFF, IID_LIGHTNING, IID_MALTET, IID_SAINTSSTAFF }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 08680764
struct UnitInfo CONST_DATA UnitInfo_Unk_08680764[] =
{
    { PID_YODER, JID_BISHOP, 0, FALSE, FACTION_ID_BLUE, 20, 1, 2, 1, 2, { IID_RECOVERSTAFF, IID_LIGHTNING, IID_MULAGIR, IID_SAINTSSTAFF }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 08680784
struct UnitInfo CONST_DATA UnitInfo_Unk_08680784[] =
{
    { PID_GALLE, JID_WYVERNLORD, PID_GALLE, FALSE, FACTION_ID_RED, 18, 10, 5, 10, 6, { IID_SPEAR }, { AI_A_0B, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086807A4
struct UnitInfo CONST_DATA UnitInfo_Unk_086807A4[] =
{
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, PID_GALLE, TRUE, FACTION_ID_RED, 20, 9, 4, 9, 5, { IID_HORSESLAYER }, { AI_A_0D, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, PID_GALLE, TRUE, FACTION_ID_RED, 20, 11, 4, 11, 5, { IID_AXEREAVER }, { AI_A_0D, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, PID_GALLE, TRUE, FACTION_ID_RED, 20, 9, 6, 9, 7, { IID_JAVELIN }, { AI_A_0D, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, PID_GALLE, TRUE, FACTION_ID_RED, 20, 11, 6, 11, 7, { IID_STEELLANCE }, { AI_A_0D, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086807F4
struct UnitInfo CONST_DATA UnitInfo_Unk_086807F4[] =
{
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, PID_UNKNOWN_CA, TRUE, FACTION_ID_RED, 20, 30, 12, 30, 11, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_0D, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_CA, JID_WYVERNLORD, PID_UNKNOWN_CA, TRUE, FACTION_ID_RED, 13, 31, 11, 31, 10, { IID_SILVERLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, PID_UNKNOWN_CA, TRUE, FACTION_ID_RED, 20, 30, 10, 30, 9, { IID_STEELLANCE }, { AI_A_0D, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, PID_UNKNOWN_CA, TRUE, FACTION_ID_RED, 20, 30, 11, 30, 10, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_0D, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08680844
struct UnitInfo CONST_DATA UnitInfo_Unk_08680844[] =
{
    { PID_UNKNOWN_CB, JID_WYVERNLORD, PID_UNKNOWN_CB, TRUE, FACTION_ID_RED, 13, 11, 34, 12, 34, { IID_SILVERLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, PID_UNKNOWN_CB, TRUE, FACTION_ID_RED, 20, 13, 34, 14, 34, { IID_JAVELIN }, { AI_A_0D, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, PID_UNKNOWN_CB, TRUE, FACTION_ID_RED, 20, 12, 35, 13, 35, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_0D, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, PID_UNKNOWN_CB, TRUE, FACTION_ID_RED, 20, 12, 34, 13, 34, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_0D, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08680894
struct UnitInfo CONST_DATA UnitInfo_Unk_08680894[] =
{
    { PID_UNKNOWN_CC, JID_WYVERNLORD, PID_UNKNOWN_CC, TRUE, FACTION_ID_RED, 13, 7, 35, 7, 34, { IID_SILVERLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, PID_UNKNOWN_CC, TRUE, FACTION_ID_RED, 20, 5, 35, 6, 35, { IID_STEELLANCE }, { AI_A_0D, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, PID_UNKNOWN_CC, TRUE, FACTION_ID_RED, 20, 9, 35, 8, 35, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_0D, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, PID_UNKNOWN_CC, TRUE, FACTION_ID_RED, 20, 9, 35, 7, 35, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_0D, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086808E4
struct UnitInfo CONST_DATA UnitInfo_Unk_086808E4[] =
{
    { PID_UNKNOWN_9F, JID_PALADIN, PID_UNKNOWN_CC, TRUE, FACTION_ID_RED, 13, 5, 27, 5, 27, { IID_SILVERLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_PALADIN, PID_UNKNOWN_CC, TRUE, FACTION_ID_RED, 5, 6, 27, 6, 27, { IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_PALADIN, PID_UNKNOWN_CC, TRUE, FACTION_ID_RED, 5, 7, 27, 7, 27, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_PALADIN, PID_UNKNOWN_CC, TRUE, FACTION_ID_RED, 5, 8, 27, 8, 27, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08680934
struct UnitInfo CONST_DATA UnitInfo_Unk_08680934[] =
{
    { PID_UNKNOWN_9F, JID_WYVERNLORD, PID_UNKNOWN_CC, TRUE, FACTION_ID_RED, 13, 0, 35, 1, 35, { IID_SILVERLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, PID_UNKNOWN_CC, TRUE, FACTION_ID_RED, 20, 2, 35, 0, 33, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, PID_UNKNOWN_CC, TRUE, FACTION_ID_RED, 20, 2, 35, 2, 33, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, PID_UNKNOWN_CC, TRUE, FACTION_ID_RED, 20, 2, 34, 1, 34, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08680984
struct UnitInfo CONST_DATA UnitInfo_Unk_08680984[] =
{
    { PID_UNKNOWN_9F, JID_WYVERNLORD, PID_UNKNOWN_CC, TRUE, FACTION_ID_RED, 13, 8, 35, 7, 35, { IID_SILVERLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, PID_UNKNOWN_CC, TRUE, FACTION_ID_RED, 20, 8, 35, 6, 33, { IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, PID_UNKNOWN_CC, TRUE, FACTION_ID_RED, 20, 8, 35, 8, 33, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, PID_UNKNOWN_CC, TRUE, FACTION_ID_RED, 20, 6, 35, 6, 33, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086809D4
struct UnitInfo CONST_DATA UnitInfo_Unk_086809D4[] =
{
    { PID_UNKNOWN_9F, JID_WYVERNLORD, PID_UNKNOWN_CC, TRUE, FACTION_ID_RED, 13, 28, 11, 27, 10, { IID_SILVERLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, PID_UNKNOWN_CC, TRUE, FACTION_ID_RED, 5, 28, 11, 27, 11, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, PID_UNKNOWN_CC, TRUE, FACTION_ID_RED, 5, 27, 10, 26, 11, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, PID_UNKNOWN_CC, TRUE, FACTION_ID_RED, 5, 27, 10, 26, 10, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08680A24
struct UnitInfo CONST_DATA UnitInfo_Unk_08680A24[] =
{
    { PID_UNKNOWN_9F, JID_WYVERNLORD, PID_UNKNOWN_CC, TRUE, FACTION_ID_RED, 13, 31, 15, 30, 15, { IID_SILVERLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, PID_UNKNOWN_CC, TRUE, FACTION_ID_RED, 20, 31, 16, 29, 15, { IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, PID_UNKNOWN_CC, TRUE, FACTION_ID_RED, 20, 31, 16, 29, 16, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, PID_UNKNOWN_CC, TRUE, FACTION_ID_RED, 20, 31, 17, 28, 14, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08680A74
struct UnitInfo CONST_DATA UnitInfo_Unk_08680A74[] =
{
    { PID_UNKNOWN_9F, JID_WYVERNLORD, PID_UNKNOWN_CC, TRUE, FACTION_ID_RED, 13, 13, 29, 14, 28, { IID_SILVERLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, PID_UNKNOWN_CC, TRUE, FACTION_ID_RED, 20, 13, 29, 14, 27, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, PID_UNKNOWN_CC, TRUE, FACTION_ID_RED, 20, 13, 30, 13, 26, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_9F, JID_WYVERNRIDER, PID_UNKNOWN_CC, TRUE, FACTION_ID_RED, 20, 13, 30, 15, 25, { IID_STEELLANCE, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08680AC4
struct UnitInfo CONST_DATA UnitInfo_Unk_08680AC4[] =
{
    { PID_UNKNOWN_C4, JID_DRUID, 0, FALSE, FACTION_ID_RED, 15, 24, 30, 24, 34, { IID_NOSFERATU }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_C5, JID_DRUID, 0, TRUE, FACTION_ID_RED, 10, 24, 30, 23, 35, { IID_FENRIR, IID_PHYSICSTAFF }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_C5, JID_DRUID, 0, TRUE, FACTION_ID_RED, 10, 24, 30, 25, 35, { IID_FENRIR, IID_PHYSICSTAFF }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { 0 }, // end
};

// EventScr @ 08680B04
EventScr CONST_DATA EventScr_LoadUnits_Unk_08680324[] =
{
    EvtLoadUnits(UnitInfo_Unk_08680324)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08680B18
EventScr CONST_DATA EventScr_LoadUnits_Unk_08680454[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_08680454)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08680B34
EventScr CONST_DATA EventScr_LoadUnits_Unk_08680694[] =
{
    EvtLoadUnits(UnitInfo_Unk_08680694)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08680B48
EventScr CONST_DATA EventScr_LoadUnits_Unk_08680744[] =
{
    EvtLoadUnits(UnitInfo_Unk_08680744)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08680B5C
EventScr CONST_DATA EventScr_LoadUnits_Unk_08680764[] =
{
    EvtLoadUnits(UnitInfo_Unk_08680764)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08680B70
EventScr CONST_DATA EventScr_LoadUnits_Unk_08680784[] =
{
    EvtLoadUnits(UnitInfo_Unk_08680784)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08680B84
EventScr CONST_DATA EventScr_LoadUnits_Unk_086807A4[] =
{
    EvtLoadUnits(UnitInfo_Unk_086807A4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08680B98
EventScr CONST_DATA EventScr_LoadUnits_Unk_086807F4[] =
{
    EvtLoadUnits(UnitInfo_Unk_086807F4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08680BAC
EventScr CONST_DATA EventScr_LoadUnits_Unk_08680844[] =
{
    EvtLoadUnits(UnitInfo_Unk_08680844)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08680BC0
EventScr CONST_DATA EventScr_LoadUnits_Unk_08680894[] =
{
    EvtLoadUnits(UnitInfo_Unk_08680894)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08680BD4
EventScr CONST_DATA EventScr_LoadUnits_Unk_086808E4[] =
{
    EvtLoadUnits(UnitInfo_Unk_086808E4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08680BE8
EventScr CONST_DATA EventScr_LoadUnits_Unk_08680934[] =
{
    EvtLoadUnits(UnitInfo_Unk_08680934)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08680BFC
EventScr CONST_DATA EventScr_LoadUnits_Unk_08680984[] =
{
    EvtLoadUnits(UnitInfo_Unk_08680984)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08680C10
EventScr CONST_DATA EventScr_LoadUnits_Unk_086809D4[] =
{
    EvtLoadUnits(UnitInfo_Unk_086809D4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08680C24
EventScr CONST_DATA EventScr_LoadUnits_Unk_08680A24[] =
{
    EvtLoadUnits(UnitInfo_Unk_08680A24)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08680C38
EventScr CONST_DATA EventScr_LoadUnits_Unk_08680A74[] =
{
    EvtLoadUnits(UnitInfo_Unk_08680A74)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08680C4C
EventScr CONST_DATA EventScr_LoadUnits_Unk_08680AC4[] =
{
    EvtLoadUnits(UnitInfo_Unk_08680AC4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 21 summary:
// Units UnitInfo_Unk_08680324 1
// Units UnitInfo_Unk_08680454 2
// Units UnitInfo_Unk_08680694 1
// Units UnitInfo_Unk_08680744 1
// Units UnitInfo_Unk_08680764 1
// Units UnitInfo_Unk_08680784 1
// Units UnitInfo_Unk_086807A4 1
// Units UnitInfo_Unk_086807F4 1
// Units UnitInfo_Unk_08680844 1
// Units UnitInfo_Unk_08680894 1
// Units UnitInfo_Unk_086808E4 1
// Units UnitInfo_Unk_08680934 1
// Units UnitInfo_Unk_08680984 1
// Units UnitInfo_Unk_086809D4 1
// Units UnitInfo_Unk_08680A24 1
// Units UnitInfo_Unk_08680A74 1
// Units UnitInfo_Unk_08680AC4 1

// UnitInfo @ 08680C60
struct UnitInfo CONST_DATA UnitInfo_Unk_08680C60[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 20, 28, 30, 28, 30, { IID_RAPIER, IID_IRONSWORD, IID_BINDINGBLADE, IID_ARMORSLAYER }, { 0 } },
    { PID_ZEISS, JID_WYVERNRIDER, PID_ROY, TRUE, FACTION_ID_BLUE, 19, 3, 30, 3, 30, { IID_MALTET, IID_IRONSWORD, IID_IRONLANCE, IID_HORSESLAYER }, { 0 } },
    { PID_WOLT, JID_ARCHER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 30, 30, 30, 30, { IID_MULAGIR, IID_SILVERBOW, IID_KILLERBOW, IID_STEELBOW }, { 0 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 1, 30, 1, 30, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_SILVERLANCE }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 28, 29, 28, 29, { IID_APOCALYPSE, IID_JAVELIN, IID_IRONLANCE, IID_KNIGHTCREST }, { 0 } },
    { PID_HUGH, JID_MAGE, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 2, 29, 2, 29, { IID_FORBLAZE, IID_ELFIRE, IID_SAINTSSTAFF, IID_BOLTING }, { 0 } },
    { PID_ECHIDNA, JID_HERO_F, PID_ROY, TRUE, FACTION_ID_BLUE, 11, 28, 31, 28, 31, { IID_ARMADS, IID_IRONSWORD, IID_IRONBLADE, IID_STEELSWORD }, { 0 } },
    { PID_LOT, JID_FIGHTER, PID_ROY, TRUE, FACTION_ID_BLUE, 10, 2, 31, 2, 31, { IID_SILVERAXE, IID_IRONAXE, IID_HANDAXE, IID_HEROCREST }, { 0 } },
    { PID_CHAD, JID_THIEF, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 27, 29, 27, 29, { IID_IRONSWORD, IID_LOCKPICK }, { 0 } },
    { PID_JUNO, JID_PEGASUSKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 4, 29, 4, 29, { IID_BRAVELANCE, IID_STEELLANCE, IID_JAVELIN, IID_IRONLANCE }, { 0 } },
    { PID_KLEIN, JID_SNIPER, PID_ROY, TRUE, FACTION_ID_BLUE, 14, 30, 29, 30, 29, { IID_IRONBOW, IID_SILVERBOW, IID_KILLERBOW, IID_STEELBOW }, { 0 } },
    { PID_CECILIA, JID_VALKYRIE, PID_ROY, TRUE, FACTION_ID_BLUE, 18, 4, 31, 4, 31, { IID_ELFIRE, IID_SAINTSSTAFF, IID_RECOVERSTAFF, IID_WARPSTAFF }, { 0 } },
    { PID_PERCEVAL, JID_PALADIN, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 27, 31, 27, 31, { IID_DURANDAL, IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN }, { 0 } },
    { PID_DIECK, JID_MERCENARY, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 30, 31, 30, 31, { IID_BRAVESWORD, IID_IRONBLADE, IID_HEROCREST, IID_IRONSWORD }, { 0 } },
    { PID_THEA, JID_PEGASUSKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 27, 28, 27, 28, { IID_SILVERLANCE, IID_IRONSWORD, IID_IRONLANCE, IID_AUREOLA }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, TRUE, FACTION_ID_BLUE, 1, 29, 30, 29, 30, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_RESTORESTAFF }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 08680D70
struct UnitInfo CONST_DATA UnitInfo_Unk_08680D70[] =
{
    { PID_UNKNOWN_A0, JID_ARMOR, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 20, 18, 22, 18, 22, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_A0, JID_HERO, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 12, 20, 22, 20, 22, { IID_STEELSWORD }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_A0, JID_BERSERKER, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 12, 22, 22, 22, 22, { IID_SILVERAXE }, { AI_A_00, AI_B_03, 0x21, 0x00 } },
    { PID_UNKNOWN_A0, JID_DRUID, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 13, 16, 22, 16, 22, { IID_FENRIR }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_A0, JID_ARMOR, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 20, 4, 17, 4, 17, { IID_STEELLANCE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_A0, JID_ARMOR, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 20, 30, 17, 30, 17, { IID_STEELLANCE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_A0, JID_HERO, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 15, 1, 0, 1, 0, { IID_BRAVESWORD }, { AI_A_00, AI_B_03, 0x0A, 0x20 } },
    { PID_UNKNOWN_A0, JID_HERO, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 15, 30, 0, 30, 0, { IID_BRAVEAXE }, { AI_A_00, AI_B_03, 0x0A, 0x20 } },
    { PID_UNKNOWN_A0, JID_GENERAL, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 14, 1, 4, 1, 4, { IID_SILVERLANCE, IID_JAVELIN }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_A0, JID_GENERAL, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 14, 30, 4, 30, 4, { IID_SILVERLANCE, IID_JAVELIN }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_A0, JID_BERSERKER, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 10, 6, 1, 6, 1, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_03, 0x21, 0x00 } },
    { PID_UNKNOWN_A0, JID_BERSERKER, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 10, 5, 6, 5, 6, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x21, 0x00 } },
    { PID_UNKNOWN_A0, JID_DRUID, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 12, 5, 10, 5, 10, { IID_FENRIR, IID_MENDSTAFF, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_A0, JID_BERSERKER, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 10, 26, 4, 26, 4, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_03, 0x21, 0x00 } },
    { PID_UNKNOWN_A0, JID_BERSERKER, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 10, 28, 10, 28, 10, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x21, 0x00 } },
    { PID_UNKNOWN_A0, JID_DRUID, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 12, 28, 12, 28, 12, { IID_FENRIR, IID_MENDSTAFF, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_A0, JID_MERCENARY, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 20, 8, 12, 8, 12, { IID_LANCEREAVER }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_A0, JID_SNIPER, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 9, 8, 14, 8, 14, { IID_STEELBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_A0, JID_MERCENARY, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 20, 8, 17, 8, 17, { IID_STEELSWORD }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_A0, JID_MERCENARY, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 20, 25, 12, 25, 12, { IID_LANCEREAVER }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_A0, JID_SNIPER, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 9, 25, 14, 25, 14, { IID_STEELBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_A0, JID_MERCENARY, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 20, 25, 17, 25, 17, { IID_STEELSWORD }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_A0, JID_HERO, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 11, 13, 2, 13, 2, { IID_SILVERSWORD }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_A0, JID_HERO, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 10, 17, 2, 17, 2, { IID_SILVERAXE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_A0, JID_BISHOP, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 16, 15, 31, 15, 31, { IID_SILENCESTAFF, IID_PHYSICSTAFF, IID_MENDSTAFF, IID_VULNERARY }, { AI_A_03, AI_B_03, 0x11, 0x00 } },
    { PID_UNKNOWN_A0, JID_BERSERKER, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 10, 10, 30, 10, 30, { IID_DEVILAXE, IID_HANDAXE }, { AI_A_00, AI_B_06, 0x21, 0x00 } },
    { PID_UNKNOWN_A0, JID_BERSERKER, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 10, 20, 30, 20, 30, { IID_DEVILAXE, IID_HANDAXE }, { AI_A_00, AI_B_06, 0x21, 0x00 } },
    { PID_UNKNOWN_A0, JID_DRUID, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 15, 16, 26, 16, 26, { IID_BERSERKSTAFF, IID_PHYSICSTAFF, IID_VULNERARY }, { AI_A_03, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_A0, JID_SNIPER, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 13, 13, 25, 13, 25, { IID_LONGBOW, IID_SILVERBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_A0, JID_SNIPER, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 13, 19, 25, 19, 25, { IID_LONGBOW, IID_SILVERBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_ZEPHIEL, JID_KING, 0, FALSE, FACTION_ID_RED, 20, 15, 8, 15, 8, { IID_ECKESACHS, IID_HEROCREST }, { AI_A_03, AI_B_03, 0x02, 0x20 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 10, 13, 12, 13, 12, { IID_FIRESTONE }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 10, 17, 12, 17, 12, { IID_FIRESTONE }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_A0, JID_DRUID, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 12, 11, 13, 11, 13, { IID_FENRIR }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_A0, JID_DRUID, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 12, 19, 13, 19, 13, { IID_FENRIR }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_A0, JID_HERO, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 9, 13, 16, 13, 16, { IID_SILVERSWORD }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_A0, JID_HERO, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 9, 17, 16, 17, 16, { IID_LANCEREAVER }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_A0, JID_BISHOP, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 12, 19, 10, 19, 10, { IID_DIVINE, IID_RECOVERSTAFF }, { AI_A_0E, AI_B_00, 0x11, 0x00 } },
    { PID_UNKNOWN_A0, JID_SNIPER, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 11, 11, 10, 11, 10, { IID_SILVERBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08680FF0
struct UnitInfo CONST_DATA UnitInfo_Unk_08680FF0[] =
{
    { PID_UNKNOWN_A0, JID_HERO, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 15, 22, 17, 22, 17, { IID_LIGHTBRAND }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_A0, JID_HERO, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 15, 22, 16, 22, 16, { IID_KILLINGEDGE }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_A0, JID_SNIPER, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 16, 22, 19, 22, 19, { IID_BRAVEBOW }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_A0, JID_DRUID, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 15, 7, 6, 7, 6, { IID_NOSFERATU, IID_RECOVERSTAFF }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_A0, JID_DRUID, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 15, 8, 6, 8, 6, { IID_NOSFERATU, IID_PHYSICSTAFF }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_A0, JID_DRUID, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 15, 22, 1, 22, 1, { IID_NOSFERATU, IID_RECOVERSTAFF }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_A0, JID_DRUID, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 15, 23, 1, 23, 1, { IID_NOSFERATU, IID_PHYSICSTAFF }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_A0, JID_HERO, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 15, 12, 30, 12, 30, { IID_LIGHTBRAND }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_A0, JID_HERO, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 15, 12, 31, 12, 31, { IID_KILLINGEDGE }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_A0, JID_SNIPER, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 16, 14, 30, 14, 30, { IID_BRAVEBOW }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086810A0
struct UnitInfo CONST_DATA UnitInfo_Unk_086810A0[] =
{
    { PID_UNKNOWN_A0, JID_BISHOP, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 9, 10, 0, 10, 0, { IID_SILENCESTAFF, IID_DIVINE, IID_PHYSICSTAFF }, { AI_A_0E, AI_B_00, 0x10, 0x00 } },
    { PID_UNKNOWN_A0, JID_BISHOP, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 10, 20, 0, 20, 0, { IID_SLEEPSTAFF, IID_DIVINE, IID_PHYSICSTAFF }, { AI_A_0E, AI_B_00, 0x10, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086810D0
struct UnitInfo CONST_DATA UnitInfo_Unk_086810D0[] =
{
    { PID_UNKNOWN_A0, JID_HERO, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 12, 12, 16, 12, 16, { IID_SILVERSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_A0, JID_BERSERKER, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 11, 18, 16, 18, 16, { IID_HAMMER }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_A0, JID_DRUID, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 15, 11, 8, 11, 8, { IID_FENRIR }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_A0, JID_SNIPER, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 12, 19, 8, 19, 8, { IID_SILVERBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08681120
struct UnitInfo CONST_DATA UnitInfo_Unk_08681120[] =
{
    { PID_UNKNOWN_A0, JID_HERO, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 12, 0, 31, 0, 29, { IID_SILVERSWORD }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_A0, JID_SNIPER, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 14, 1, 31, 0, 30, { IID_SILVERBOW }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_A0, JID_HERO, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 12, 2, 31, 2, 29, { IID_LANCEREAVER }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_A0, JID_DRUID, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 13, 4, 31, 2, 30, { IID_FENRIR, IID_MENDSTAFF }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08681170
struct UnitInfo CONST_DATA UnitInfo_Unk_08681170[] =
{
    { PID_UNKNOWN_A0, JID_HERO, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 12, 26, 31, 26, 29, { IID_SILVERSWORD }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_A0, JID_SNIPER, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 14, 27, 31, 26, 30, { IID_SILVERBOW }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_A0, JID_HERO, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 12, 28, 31, 28, 29, { IID_LANCEREAVER }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_A0, JID_DRUID, PID_ZEPHIEL, TRUE, FACTION_ID_RED, 13, 29, 31, 28, 30, { IID_FENRIR, IID_MENDSTAFF }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086811C0
struct UnitInfo CONST_DATA UnitInfo_Unk_086811C0[] =
{
    { PID_CATH, JID_THIEF_F, 0, FALSE, FACTION_ID_RED, 5, 30, 6, 30, 7, { IID_IRONSWORD, IID_LOCKPICK, IID_VULNERARY }, { AI_A_06, AI_B_05, 0x1B, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086811E0
struct UnitInfo CONST_DATA UnitInfo_Unk_086811E0[] =
{
    { PID_UNKNOWN_A2, JID_THIEF, 0, TRUE, FACTION_ID_RED, 20, 1, 6, 1, 6, { IID_IRONSWORD, IID_LOCKPICK }, { AI_A_06, AI_B_05, 0x18, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08681200
struct UnitInfo CONST_DATA UnitInfo_Unk_08681200[] =
{
    { PID_CATH, JID_THIEF_F, 0, FALSE, FACTION_ID_RED, 5, 1, 6, 1, 7, { IID_IRONSWORD, IID_LOCKPICK }, { AI_A_06, AI_B_05, 0x18, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08681220
struct UnitInfo CONST_DATA UnitInfo_Unk_08681220[] =
{
    { PID_UNKNOWN_A2, JID_THIEF, 0, TRUE, FACTION_ID_RED, 20, 30, 6, 30, 6, { IID_IRONSWORD, IID_LOCKPICK }, { AI_A_06, AI_B_05, 0x18, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08681240
struct UnitInfo CONST_DATA UnitInfo_Unk_08681240[] =
{
    { PID_ZEPHIEL, JID_KING, 0, FALSE, FACTION_ID_RED, 7, 15, 8, 15, 8, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_03, AI_B_03, 0x02, 0x00 } },
    { PID_IDUNN, JID_SHAMAN_F, 0, FALSE, FACTION_ID_RED, 4, 16, 9, 16, 9, { 0 }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_A0, JID_WYVERNRIDER, 0, FALSE, FACTION_ID_RED, 10, 13, 10, 13, 10, { IID_HORSESLAYER }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_A0, JID_WYVERNRIDER, 0, FALSE, FACTION_ID_RED, 10, 13, 12, 13, 12, { IID_STEELLANCE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_A0, JID_WYVERNRIDER, 0, FALSE, FACTION_ID_RED, 10, 13, 14, 13, 14, { IID_STEELLANCE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_A0, JID_WYVERNRIDER, 0, FALSE, FACTION_ID_RED, 10, 17, 10, 17, 10, { IID_STEELLANCE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_A0, JID_WYVERNRIDER, 0, FALSE, FACTION_ID_RED, 10, 17, 12, 17, 12, { IID_STEELLANCE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_A0, JID_WYVERNRIDER, 0, FALSE, FACTION_ID_RED, 10, 17, 14, 17, 14, { IID_STEELLANCE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_A0, JID_SOLDIER, 0, FALSE, FACTION_ID_RED, 8, 11, 9, 11, 9, { IID_IRONLANCE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_A0, JID_SOLDIER, 0, FALSE, FACTION_ID_RED, 8, 11, 11, 11, 11, { IID_IRONLANCE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_A0, JID_SOLDIER, 0, FALSE, FACTION_ID_RED, 8, 11, 13, 11, 13, { IID_IRONLANCE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_A0, JID_SOLDIER, 0, FALSE, FACTION_ID_RED, 8, 19, 9, 19, 9, { IID_IRONLANCE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_A0, JID_SOLDIER, 0, FALSE, FACTION_ID_RED, 8, 19, 11, 19, 11, { IID_IRONLANCE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_A0, JID_SOLDIER, 0, FALSE, FACTION_ID_RED, 8, 19, 13, 19, 13, { IID_IRONLANCE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08681330
struct UnitInfo CONST_DATA UnitInfo_Unk_08681330[] =
{
    { PID_UNKNOWN_A0, JID_SOLDIER, 0, FALSE, FACTION_ID_RED, 9, 15, 17, 15, 9, { IID_IRONLANCE }, { AI_A_00, AI_B_03 } },
    { 0 }, // end
};

// UnitInfo @ 08681350
struct UnitInfo CONST_DATA UnitInfo_Unk_08681350[] =
{
    { PID_ROY, JID_ROY, 0, FALSE, FACTION_ID_BLUE, 20, 16, 9, 16, 9, { 0 }, { 0 } },
    { PID_GUINIVERE, JID_SAGE_F, 0, FALSE, FACTION_ID_GREEN, 5, 15, 8, 15, 8, { 0 }, { 0 } },
    { PID_UNKNOWN_A0, JID_SOLDIER, 0, FALSE, FACTION_ID_GREEN, 5, 15, 9, 15, 17, { 0 }, { 0 } },
    { 0 }, // end
};

// EventScr @ 08681390
EventScr CONST_DATA EventScr_LoadUnits_Unk_08680C60[] =
{
    EvtLoadUnits(UnitInfo_Unk_08680C60)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086813A4
EventScr CONST_DATA EventScr_LoadUnits_Unk_08680D70[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_08680D70)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086813C0
EventScr CONST_DATA EventScr_LoadUnits_Unk_08680FF0[] =
{
    EvtLoadUnits(UnitInfo_Unk_08680FF0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086813D4
EventScr CONST_DATA EventScr_LoadUnits_Unk_086810A0[] =
{
    EvtLoadUnits(UnitInfo_Unk_086810A0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086813E8
EventScr CONST_DATA EventScr_LoadUnits_Unk_086810D0[] =
{
    EvtLoadUnits(UnitInfo_Unk_086810D0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086813FC
EventScr CONST_DATA EventScr_LoadUnits_Unk_08681120[] =
{
    EvtLoadUnits(UnitInfo_Unk_08681120)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08681410
EventScr CONST_DATA EventScr_LoadUnits_Unk_08681170[] =
{
    EvtLoadUnits(UnitInfo_Unk_08681170)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08681424
EventScr CONST_DATA EventScr_LoadUnits_Unk_086811C0[] =
{
    EvtLoadUnits(UnitInfo_Unk_086811C0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08681438
EventScr CONST_DATA EventScr_LoadUnits_Unk_086811E0[] =
{
    EvtLoadUnits(UnitInfo_Unk_086811E0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0868144C
EventScr CONST_DATA EventScr_LoadUnits_Unk_08681200[] =
{
    EvtLoadUnits(UnitInfo_Unk_08681200)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08681460
EventScr CONST_DATA EventScr_LoadUnits_Unk_08681220[] =
{
    EvtLoadUnits(UnitInfo_Unk_08681220)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08681474
EventScr CONST_DATA EventScr_LoadUnits_Unk_08681240[] =
{
    EvtLoadUnits(UnitInfo_Unk_08681240)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08681488
EventScr CONST_DATA EventScr_LoadUnits_Unk_08681330[] =
{
    EvtLoadUnits(UnitInfo_Unk_08681330)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0868149C
EventScr CONST_DATA EventScr_LoadUnits_Unk_08681350[] =
{
    EvtLoadUnits(UnitInfo_Unk_08681350)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 22 summary:
// Units UnitInfo_Unk_08680C60 1
// Units UnitInfo_Unk_08680D70 2
// Units UnitInfo_Unk_08680FF0 1
// Units UnitInfo_Unk_086810A0 1
// Units UnitInfo_Unk_086810D0 1
// Units UnitInfo_Unk_08681120 1
// Units UnitInfo_Unk_08681170 1
// Units UnitInfo_Unk_086811C0 1
// Units UnitInfo_Unk_086811E0 1
// Units UnitInfo_Unk_08681200 1
// Units UnitInfo_Unk_08681220 1
// Units UnitInfo_Unk_08681240 1
// Units UnitInfo_Unk_08681330 1
// Units UnitInfo_Unk_08681350 1

// UnitInfo @ 086814B0
struct UnitInfo CONST_DATA UnitInfo_Unk_086814B0[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 20, 16, 30, 16, 30, { IID_RAPIER, IID_IRONSWORD, IID_BINDINGBLADE, IID_ARMORSLAYER }, { 0 } },
    { PID_FAE, JID_MANAKETE_F, PID_ROY, TRUE, FACTION_ID_BLUE, 10, 15, 29, 15, 29, { IID_DIVINESTONE }, { 0 } },
    { PID_ALEN, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 15, 31, 15, 31, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_SILVERLANCE }, { 0 } },
    { PID_GWENDOLYN, JID_ARMOR_F, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 17, 29, 17, 29, { IID_SILVERLANCE, IID_IRONLANCE, IID_JAVELIN, IID_SILVERLANCE }, { 0 } },
    { PID_ELEN, JID_CLERIC, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 17, 31, 17, 31, { IID_LIGHTNING, IID_MENDSTAFF, IID_WARPSTAFF, IID_RESCUESTAFF }, { 0 } },
    { PID_RAIGH, JID_SHAMAN, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 18, 30, 18, 30, { IID_NOSFERATU, IID_FLUX, IID_FENRIR, IID_GUIDINGRING }, { 0 } },
    { PID_ECHIDNA, JID_HERO_F, PID_ROY, TRUE, FACTION_ID_BLUE, 14, 14, 30, 14, 30, { IID_BRAVEAXE, IID_IRONSWORD, IID_IRONBLADE, IID_STEELSWORD }, { 0 } },
    { PID_WARD, JID_FIGHTER, PID_ROY, TRUE, FACTION_ID_BLUE, 12, 13, 31, 13, 31, { IID_KILLERAXE, IID_IRONAXE, IID_HANDAXE, IID_SILVERAXE }, { 0 } },
    { PID_CHAD, JID_THIEF, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 19, 29, 19, 29, { IID_IRONSWORD, IID_LOCKPICK }, { 0 } },
    { PID_THEA, JID_PEGASUSKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 19, 31, 19, 31, { IID_BRAVELANCE, IID_STEELLANCE, IID_JAVELIN, IID_IRONLANCE }, { 0 } },
    { PID_DOROTHY, JID_ARCHER_F, PID_ROY, TRUE, FACTION_ID_BLUE, 16, 20, 28, 20, 28, { IID_IRONBOW, IID_SILVERBOW, IID_KILLERBOW, IID_STEELBOW }, { 0 } },
    { PID_CLARINE, JID_TROUBADOUR, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 20, 30, 20, 30, { IID_SILENCESTAFF, IID_RESCUESTAFF, IID_HEALSTAFF, IID_RESTORESTAFF }, { 0 } },
    { PID_MELADY, JID_WYVERNRIDER_F, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 12, 30, 12, 30, { IID_SILVERLANCE, IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN }, { 0 } },
    { PID_OGIER, JID_MERCENARY, PID_ROY, TRUE, FACTION_ID_BLUE, 18, 13, 29, 13, 29, { IID_BRAVESWORD, IID_STEELAXE, IID_IRONSWORD, IID_SILVERSWORD }, { 0 } },
    { PID_SIN, JID_NOMAD, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 21, 31, 21, 31, { IID_SILVERBOW, IID_IRONSWORD, IID_LONGBOW, IID_SHORTBOW }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, TRUE, FACTION_ID_BLUE, 1, 21, 29, 21, 29, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_RESTORESTAFF }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 086815C0
struct UnitInfo CONST_DATA UnitInfo_Unk_086815C0[] =
{
    { PID_BRUNNYA, JID_SAGE_F, 0, FALSE, FACTION_ID_RED, 20, 5, 1, 5, 1, { IID_FIMBULVETR, IID_BOLTING, IID_GUIDINGRING }, { AI_A_00, AI_B_03, 0x0A, 0x20 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 12, 5, 4, 5, 4, { IID_FIRESTONE }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 12, 15, 9, 15, 9, { IID_FIRESTONE, IID_REDGEM }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 12, 1, 15, 1, 15, { IID_FIRESTONE }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 12, 19, 17, 19, 17, { IID_FIRESTONE }, { AI_A_00, AI_B_06, 0x0A, 0x00 } },
    { PID_UNKNOWN_B1, JID_WYVERNLORD, PID_BRUNNYA, TRUE, FACTION_ID_RED, 14, 10, 2, 10, 2, { IID_KILLERLANCE }, { AI_A_00, AI_B_06, 0x0A, 0x00 } },
    { PID_UNKNOWN_B1, JID_WYVERNRIDER, PID_BRUNNYA, TRUE, FACTION_ID_RED, 20, 11, 3, 11, 3, { IID_AXEREAVER }, { AI_A_00, AI_B_06, 0x0A, 0x00 } },
    { PID_UNKNOWN_B1, JID_WYVERNRIDER, PID_BRUNNYA, TRUE, FACTION_ID_RED, 20, 13, 3, 13, 3, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_06, 0x0A, 0x00 } },
    { PID_UNKNOWN_B1, JID_WYVERNRIDER, PID_BRUNNYA, TRUE, FACTION_ID_RED, 20, 14, 2, 14, 2, { IID_STEELLANCE }, { AI_A_00, AI_B_06, 0x0A, 0x00 } },
    { PID_UNKNOWN_B1, JID_WYVERNLORD, PID_BRUNNYA, TRUE, FACTION_ID_RED, 14, 21, 10, 21, 10, { IID_SILVERLANCE, IID_SPEAR }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_B1, JID_WYVERNRIDER, PID_BRUNNYA, TRUE, FACTION_ID_RED, 20, 20, 11, 20, 11, { IID_AXEREAVER }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_B1, JID_WYVERNRIDER, PID_BRUNNYA, TRUE, FACTION_ID_RED, 20, 22, 11, 22, 11, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_B1, JID_WYVERNRIDER, PID_BRUNNYA, TRUE, FACTION_ID_RED, 20, 21, 12, 21, 12, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_B1, JID_WYVERNLORD, PID_BRUNNYA, TRUE, FACTION_ID_RED, 15, 8, 19, 8, 19, { IID_KILLERLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_B1, JID_WYVERNRIDER, PID_BRUNNYA, TRUE, FACTION_ID_RED, 20, 8, 20, 8, 20, { IID_AXEREAVER }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_B1, JID_WYVERNRIDER, PID_BRUNNYA, TRUE, FACTION_ID_RED, 20, 9, 18, 9, 18, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_B1, JID_WYVERNRIDER, PID_BRUNNYA, TRUE, FACTION_ID_RED, 20, 9, 19, 9, 19, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_B1, JID_WYVERNLORD, PID_BRUNNYA, TRUE, FACTION_ID_RED, 14, 20, 1, 20, 1, { IID_SILVERLANCE, IID_SPEAR }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_B1, JID_WYVERNRIDER, PID_BRUNNYA, TRUE, FACTION_ID_RED, 20, 19, 2, 19, 2, { IID_AXEREAVER }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_B1, JID_WYVERNRIDER, PID_BRUNNYA, TRUE, FACTION_ID_RED, 20, 21, 2, 21, 2, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_B1, JID_WYVERNRIDER, PID_BRUNNYA, TRUE, FACTION_ID_RED, 20, 20, 3, 20, 3, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_B1, JID_WYVERNLORD, PID_BRUNNYA, TRUE, FACTION_ID_RED, 14, 0, 29, 0, 29, { IID_HORSESLAYER }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_B1, JID_WYVERNRIDER, PID_BRUNNYA, TRUE, FACTION_ID_RED, 20, 1, 28, 1, 28, { IID_AXEREAVER }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_B1, JID_WYVERNRIDER, PID_BRUNNYA, TRUE, FACTION_ID_RED, 20, 1, 29, 1, 29, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_B1, JID_WYVERNRIDER, PID_BRUNNYA, TRUE, FACTION_ID_RED, 20, 1, 30, 1, 30, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_B1, JID_WYVERNLORD, PID_BRUNNYA, TRUE, FACTION_ID_RED, 14, 4, 7, 4, 7, { IID_KILLERLANCE }, { AI_A_00, AI_B_06, 0x0A, 0x00 } },
    { PID_UNKNOWN_B1, JID_WYVERNRIDER, PID_BRUNNYA, TRUE, FACTION_ID_RED, 20, 3, 8, 3, 8, { IID_AXEREAVER }, { AI_A_00, AI_B_06, 0x0A, 0x00 } },
    { PID_UNKNOWN_B1, JID_WYVERNRIDER, PID_BRUNNYA, TRUE, FACTION_ID_RED, 20, 5, 8, 5, 8, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_06, 0x0A, 0x00 } },
    { PID_UNKNOWN_B1, JID_WYVERNRIDER, PID_BRUNNYA, TRUE, FACTION_ID_RED, 20, 5, 6, 5, 6, { IID_STEELLANCE }, { AI_A_00, AI_B_06, 0x0A, 0x00 } },
    { PID_UNKNOWN_B1, JID_SNIPER, PID_BRUNNYA, TRUE, FACTION_ID_RED, 12, 6, 19, 6, 19, { IID_STEELBOW }, { AI_A_03, AI_B_03, 0x0A, 0x20 } },
    { PID_UNKNOWN_B1, JID_SNIPER, PID_BRUNNYA, TRUE, FACTION_ID_RED, 10, 7, 17, 7, 17, { IID_STEELBOW }, { AI_A_03, AI_B_03, 0x0A, 0x20 } },
    { PID_UNKNOWN_B1, JID_SNIPER, PID_BRUNNYA, TRUE, FACTION_ID_RED, 10, 13, 18, 13, 18, { IID_STEELBOW }, { AI_A_03, AI_B_03, 0x0A, 0x20 } },
    { PID_UNKNOWN_B1, JID_SNIPER, PID_BRUNNYA, TRUE, FACTION_ID_RED, 12, 6, 2, 6, 2, { IID_KILLERBOW }, { AI_A_0C, AI_B_14, 0x0A, 0x20 } },
    { PID_UNKNOWN_B1, JID_SNIPER, PID_BRUNNYA, TRUE, FACTION_ID_RED, 12, 4, 2, 4, 2, { IID_KILLERBOW }, { AI_A_0C, AI_B_13, 0x0A, 0x20 } },
    { PID_UNKNOWN_B1, JID_DRUID, PID_BRUNNYA, TRUE, FACTION_ID_RED, 10, 4, 3, 4, 3, { IID_FLUX, IID_PHYSICSTAFF, IID_BERSERKSTAFF }, { AI_A_0C, AI_B_15, 0x0A, 0x20 } },
    { PID_UNKNOWN_B1, JID_DRUID, PID_BRUNNYA, TRUE, FACTION_ID_RED, 10, 5, 3, 5, 3, { IID_NOSFERATU, IID_PHYSICSTAFF, IID_BLUEGEM }, { AI_A_0C, AI_B_16, 0x0A, 0x20 } },
    { PID_UNKNOWN_B1, JID_DRUID, PID_BRUNNYA, TRUE, FACTION_ID_RED, 10, 6, 3, 6, 3, { IID_FLUX, IID_PHYSICSTAFF, IID_SLEEPSTAFF }, { AI_A_0C, AI_B_17, 0x0A, 0x20 } },
    { PID_UNKNOWN_B1, JID_DRUID, PID_BRUNNYA, TRUE, FACTION_ID_RED, 10, 7, 2, 7, 2, { IID_FLUX, IID_PHYSICSTAFF, IID_SLEEPSTAFF }, { AI_A_03, AI_B_03, 0x0A, 0x20 } },
    { PID_UNKNOWN_B1, JID_DRUID, PID_BRUNNYA, TRUE, FACTION_ID_RED, 10, 13, 8, 13, 8, { IID_NOSFERATU, IID_PHYSICSTAFF }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_B1, JID_DRUID, PID_BRUNNYA, TRUE, FACTION_ID_RED, 9, 0, 18, 0, 18, { IID_FLUX, IID_MENDSTAFF }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_B1, JID_DRUID, PID_BRUNNYA, TRUE, FACTION_ID_RED, 9, 20, 18, 20, 18, { IID_FLUX, IID_MENDSTAFF }, { AI_A_00, AI_B_06, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08681860
struct UnitInfo CONST_DATA UnitInfo_Unk_08681860[] =
{
    { PID_GALLE, JID_WYVERNLORD_F, 0, TRUE, FACTION_ID_RED, 18, 12, 2, 12, 2, { IID_SILVERLANCE, IID_JAVELIN }, { AI_A_03, AI_B_03, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08681880
struct UnitInfo CONST_DATA UnitInfo_Unk_08681880[] =
{
    { PID_KAREL, 0, 0, FALSE, FACTION_ID_BLUE, 19, 22, 23, 22, 24, { IID_WODAO }, { AI_A_03, AI_B_03, 0x02, 0x00 } },
    { 0 }, // end
};

// EventScr @ 086818A0
EventScr CONST_DATA EventScr_LoadUnits_Unk_086814B0[] =
{
    EvtLoadUnits(UnitInfo_Unk_086814B0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086818B4
EventScr CONST_DATA EventScr_LoadUnits_Unk_086815C0[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_086815C0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086818D0
EventScr CONST_DATA EventScr_LoadUnits_Unk_08681860[] =
{
    EvtLoadUnits(UnitInfo_Unk_08681860)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086818E4
EventScr CONST_DATA EventScr_LoadUnits_Unk_08681880[] =
{
    EvtLoadUnits(UnitInfo_Unk_08681880)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 23 summary:
// Units UnitInfo_Unk_086814B0 1
// Units UnitInfo_Unk_086815C0 2
// Units UnitInfo_Unk_08681860 1
// Units UnitInfo_Unk_08681880 1

// UnitInfo @ 086818F8
struct UnitInfo CONST_DATA UnitInfo_Unk_086818F8[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 20, 27, 46, 27, 46, { IID_RAPIER, IID_IRONSWORD, IID_BINDINGBLADE, IID_ARMORSLAYER }, { 0 } },
    { PID_CHAD, JID_THIEF, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 26, 45, 26, 45, { IID_IRONSWORD, IID_VULNERARY, IID_LOCKPICK }, { 0 } },
    { PID_KLEIN, JID_SNIPER, PID_ROY, TRUE, FACTION_ID_BLUE, 16, 28, 45, 28, 45, { IID_IRONBOW, IID_SILVERBOW, IID_KILLERBOW, IID_STEELBOW }, { 0 } },
    { PID_BARTRE, JID_WARRIOR, PID_ROY, TRUE, FACTION_ID_BLUE, 12, 26, 47, 26, 47, { IID_STEELAXE, IID_IRONAXE, IID_HANDAXE, IID_SILVERAXE }, { 0 } },
    { PID_RAIGH, JID_DRUID, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 28, 47, 28, 47, { IID_NOSFERATU, IID_BERSERKSTAFF, IID_HAMMERNESTAFF, IID_PHYSICSTAFF }, { 0 } },
    { PID_ELEN, JID_BISHOP_F, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 25, 44, 25, 44, { IID_AUREOLA, IID_PURGE, IID_SILENCESTAFF, IID_RECOVERSTAFF }, { 0 } },
    { PID_JUNO, JID_PEGASUSKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 27, 44, 27, 44, { IID_BRAVELANCE, IID_STEELLANCE, IID_JAVELIN, IID_IRONLANCE }, { 0 } },
    { PID_PERCEVAL, JID_PALADIN, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 26, 43, 26, 43, { IID_SILVERLANCE, IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN }, { 0 } },
    { PID_KAREL, JID_SWORDMASTER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 28, 43, 28, 43, { IID_WODAO, IID_VULNERARY }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 29, 44, 29, 44, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_RESTORESTAFF }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 086819A8
struct UnitInfo CONST_DATA UnitInfo_Unk_086819A8[] =
{
    { PID_JAHN, JID_MANAKETE, 0, FALSE, FACTION_ID_RED, 18, 6, 3, 6, 3, { IID_FIRESTONE, IID_ELIXIR }, { AI_A_03, AI_B_03, 0x02, 0x20 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 15, 18, 6, 18, 6, { IID_FIRESTONE, IID_ELIXIR }, { AI_A_03, AI_B_03, 0x02, 0x20 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 15, 27, 14, 27, 14, { IID_FIRESTONE }, { AI_A_03, AI_B_03, 0x02, 0x20 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 14, 16, 21, 16, 21, { IID_FIRESTONE, IID_ELIXIR }, { AI_A_03, AI_B_03, 0x02, 0x20 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 14, 5, 23, 5, 23, { IID_FIRESTONE }, { AI_A_03, AI_B_03, 0x02, 0x20 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 13, 7, 35, 7, 35, { IID_FIRESTONE, IID_ELIXIR }, { AI_A_03, AI_B_03, 0x02, 0x20 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 13, 18, 36, 18, 36, { IID_FIRESTONE }, { AI_A_03, AI_B_03, 0x02, 0x20 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 8, 16, 36, 16, 36, { IID_FIRESTONE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 8, 20, 36, 20, 36, { IID_FIRESTONE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 8, 5, 35, 5, 35, { IID_FIRESTONE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 8, 9, 35, 9, 35, { IID_FIRESTONE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 8, 3, 23, 3, 23, { IID_FIRESTONE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 8, 7, 23, 7, 23, { IID_FIRESTONE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 8, 14, 21, 14, 21, { IID_FIRESTONE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 8, 18, 21, 18, 21, { IID_FIRESTONE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 8, 25, 14, 25, 14, { IID_FIRESTONE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 8, 29, 14, 29, 14, { IID_FIRESTONE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 8, 16, 6, 16, 6, { IID_FIRESTONE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 8, 20, 6, 20, 6, { IID_FIRESTONE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 8, 4, 3, 4, 3, { IID_FIRESTONE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 8, 8, 3, 8, 3, { IID_FIRESTONE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 8, 7, 40, 7, 40, { IID_FIRESTONE, IID_ELIXIR }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 8, 5, 28, 5, 28, { IID_FIRESTONE, IID_ELIXIR }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 8, 14, 25, 14, 25, { IID_FIRESTONE, IID_ELIXIR }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 8, 27, 19, 27, 19, { IID_FIRESTONE, IID_ELIXIR }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 8, 20, 10, 20, 10, { IID_FIRESTONE, IID_ELIXIR }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 8, 6, 8, 6, 8, { IID_FIRESTONE, IID_ELIXIR }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08681B68
struct UnitInfo CONST_DATA UnitInfo_Unk_08681B68[] =
{
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 12, 27, 47, 27, 45, { IID_FIRESTONE, IID_ELIXIR }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08681B88
struct UnitInfo CONST_DATA UnitInfo_Unk_08681B88[] =
{
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 12, 18, 36, 18, 38, { IID_FIRESTONE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08681BA8
struct UnitInfo CONST_DATA UnitInfo_Unk_08681BA8[] =
{
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 12, 7, 35, 7, 37, { IID_FIRESTONE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08681BC8
struct UnitInfo CONST_DATA UnitInfo_Unk_08681BC8[] =
{
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 12, 5, 23, 5, 25, { IID_FIRESTONE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08681BE8
struct UnitInfo CONST_DATA UnitInfo_Unk_08681BE8[] =
{
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 14, 16, 21, 16, 23, { IID_FIRESTONE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08681C08
struct UnitInfo CONST_DATA UnitInfo_Unk_08681C08[] =
{
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 14, 27, 14, 27, 16, { IID_FIRESTONE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08681C28
struct UnitInfo CONST_DATA UnitInfo_Unk_08681C28[] =
{
    { PID_FAE, JID_MANAKETE_F, PID_ROY, TRUE, FACTION_ID_BLUE, 14, 30, 44, 30, 44, { IID_DIVINESTONE }, { 0 } },
    { 0 }, // end
};

// EventScr @ 08681C48
EventScr CONST_DATA EventScr_LoadUnits_Unk_086818F8[] =
{
    EvtLoadUnits(UnitInfo_Unk_086818F8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08681C5C
EventScr CONST_DATA EventScr_LoadUnits_Unk_086819A8[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_086819A8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08681C78
EventScr CONST_DATA EventScr_LoadUnits_Unk_08681B68[] =
{
    EvtLoadUnits(UnitInfo_Unk_08681B68)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08681C8C
EventScr CONST_DATA EventScr_LoadUnits_Unk_08681B88[] =
{
    EvtLoadUnits(UnitInfo_Unk_08681B88)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08681CA0
EventScr CONST_DATA EventScr_LoadUnits_Unk_08681BA8[] =
{
    EvtLoadUnits(UnitInfo_Unk_08681BA8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08681CB4
EventScr CONST_DATA EventScr_LoadUnits_Unk_08681BC8[] =
{
    EvtLoadUnits(UnitInfo_Unk_08681BC8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08681CC8
EventScr CONST_DATA EventScr_LoadUnits_Unk_08681BE8[] =
{
    EvtLoadUnits(UnitInfo_Unk_08681BE8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08681CDC
EventScr CONST_DATA EventScr_LoadUnits_Unk_08681C08[] =
{
    EvtLoadUnits(UnitInfo_Unk_08681C08)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08681CF0
EventScr CONST_DATA EventScr_LoadUnits_Unk_08681C28[] =
{
    EvtLoadUnits(UnitInfo_Unk_08681C28)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 24 summary:
// Units UnitInfo_Unk_086818F8 1
// Units UnitInfo_Unk_086819A8 2
// Units UnitInfo_Unk_08681B68 1
// Units UnitInfo_Unk_08681B88 1
// Units UnitInfo_Unk_08681BA8 1
// Units UnitInfo_Unk_08681BC8 1
// Units UnitInfo_Unk_08681BE8 1
// Units UnitInfo_Unk_08681C08 1
// Units UnitInfo_Unk_08681C28 1

// UnitInfo @ 08681D04
struct UnitInfo CONST_DATA UnitInfo_Unk_08681D04[] =
{
    { PID_ROY, JID_ROY_PROMOTED, 0, TRUE, FACTION_ID_BLUE, 15, 8, 16, 8, 15, { IID_BINDINGBLADE, IID_RAPIER, IID_SILVERSWORD, IID_LIGHTBRAND }, { 0 } },
    { PID_FIR, JID_SWORDMASTER_F, PID_ROY, TRUE, FACTION_ID_BLUE, 18, 7, 15, 7, 15, { IID_WODAO }, { 0 } },
    { PID_NIIME, JID_DRUID_F, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 7, 17, 9, 15, { IID_NOSFERATU, IID_ECLIPSE, IID_NOSFERATU, IID_PHYSICSTAFF }, { 0 } },
    { PID_YODER, JID_BISHOP, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 9, 17, 10, 16, { IID_AUREOLA, IID_PURGE, IID_FORTIFYSTAFF, IID_RECOVERSTAFF }, { 0 } },
    { PID_FAE, JID_MANAKETE_F, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 6, 16, 6, 16, { IID_DIVINESTONE }, { 0 } },
    { PID_KLEIN, JID_SNIPER, PID_ROY, TRUE, FACTION_ID_BLUE, 18, 10, 16, 8, 14, { IID_MULAGIR, IID_SILVERBOW, IID_KILLERBOW, IID_BRAVEBOW }, { 0 } },
    { PID_DOUGLAS, JID_GENERAL, PID_ROY, TRUE, FACTION_ID_BLUE, 18, 8, 13, 8, 13, { IID_ARMADS, IID_SILVERAXE, IID_SILVERLANCE, IID_KILLERAXE }, { 0 } },
    { PID_ECHIDNA, JID_HERO_F, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 6, 13, 6, 13, { IID_DURANDAL, IID_BRAVEAXE, IID_SILVERSWORD, IID_SILVERAXE }, { 0x78, AI_B_00 } },
    { PID_KAREL, JID_SWORDMASTER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 10, 13, 10, 13, { IID_WYRMSLAYER, IID_KILLINGEDGE, IID_BRAVESWORD, IID_WODAO }, { 0 } },
    { PID_LILINA, JID_SAGE_F, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 8, 17, 8, 17, { IID_FORBLAZE, IID_BOLTING, IID_AIRCALIBUR, IID_PHYSICSTAFF }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 08681DB4
struct UnitInfo CONST_DATA UnitInfo_Unk_08681DB4[] =
{
    { PID_IDUNN, JID_SHAMAN_F, 0, FALSE, FACTION_ID_RED, 20, 8, 2, 8, 2, { IID_DARKBREATH }, { AI_A_00, AI_B_03 } },
    { PID_UNKNOWN_B2, JID_MANAKETE, PID_IDUNN_DRAGON, TRUE, FACTION_ID_RED, 19, 5, 7, 5, 7, { IID_FIRESTONE, IID_ELIXIR }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_B2, JID_MANAKETE, PID_IDUNN_DRAGON, TRUE, FACTION_ID_RED, 18, 11, 7, 11, 7, { IID_FIRESTONE, IID_ELIXIR }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08681DF4
struct UnitInfo CONST_DATA UnitInfo_Unk_08681DF4[] =
{
    { PID_IDUNN_DRAGON, JID_DEMONDRAGON, 0, FALSE, FACTION_ID_RED, 20, 8, 2, 8, 2, { IID_DARKBREATH }, { AI_A_00, AI_B_03 } },
    { 0 }, // end
};

// UnitInfo @ 08681E14
struct UnitInfo CONST_DATA UnitInfo_Unk_08681E14[] =
{
    { PID_UNKNOWN_B2, JID_MANAKETE, PID_IDUNN_DRAGON, TRUE, FACTION_ID_RED, 18, 2, 2, 2, 2, { IID_FIRESTONE, IID_ELIXIR }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08681E34
struct UnitInfo CONST_DATA UnitInfo_Unk_08681E34[] =
{
    { PID_UNKNOWN_B2, JID_MANAKETE, PID_IDUNN_DRAGON, TRUE, FACTION_ID_RED, 17, 14, 2, 14, 2, { IID_FIRESTONE, IID_ELIXIR }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08681E54
struct UnitInfo CONST_DATA UnitInfo_Unk_08681E54[] =
{
    { PID_UNKNOWN_B2, JID_MANAKETE, PID_IDUNN_DRAGON, TRUE, FACTION_ID_RED, 19, 2, 7, 2, 7, { IID_FIRESTONE, IID_ELIXIR }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08681E74
struct UnitInfo CONST_DATA UnitInfo_Unk_08681E74[] =
{
    { PID_UNKNOWN_B2, JID_MANAKETE, PID_IDUNN_DRAGON, TRUE, FACTION_ID_RED, 18, 14, 7, 14, 7, { IID_FIRESTONE, IID_ELIXIR }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08681E94
struct UnitInfo CONST_DATA UnitInfo_Unk_08681E94[] =
{
    { PID_IDUNN, JID_SHAMAN_F, 0, TRUE, FACTION_ID_GREEN, 4, 8, 2, 8, 2, { 0 }, { 0 } },
    { 0 }, // end
};

// EventScr @ 08681EB4
EventScr CONST_DATA EventScr_LoadUnits_Unk_08681D04[] =
{
    EvtLoadUnits(UnitInfo_Unk_08681D04)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08681EC8
EventScr CONST_DATA EventScr_LoadUnits_Unk_08681DB4[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_08681DB4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08681EE4
EventScr CONST_DATA EventScr_LoadUnits_Unk_08681DF4[] =
{
    EvtLoadUnits(UnitInfo_Unk_08681DF4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08681EF8
EventScr CONST_DATA EventScr_LoadUnits_Unk_08681E14[] =
{
    EvtLoadUnits(UnitInfo_Unk_08681E14)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08681F0C
EventScr CONST_DATA EventScr_LoadUnits_Unk_08681E34[] =
{
    EvtLoadUnits(UnitInfo_Unk_08681E34)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08681F20
EventScr CONST_DATA EventScr_LoadUnits_Unk_08681E54[] =
{
    EvtLoadUnits(UnitInfo_Unk_08681E54)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08681F34
EventScr CONST_DATA EventScr_LoadUnits_Unk_08681E74[] =
{
    EvtLoadUnits(UnitInfo_Unk_08681E74)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08681F48
EventScr CONST_DATA EventScr_LoadUnits_Unk_08681E94[] =
{
    EvtLoadUnits(UnitInfo_Unk_08681E94)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 25 summary:
// Units UnitInfo_Unk_08681D04 1
// Units UnitInfo_Unk_08681DB4 2
// Units UnitInfo_Unk_08681DF4 1
// Units UnitInfo_Unk_08681E14 1
// Units UnitInfo_Unk_08681E34 1
// Units UnitInfo_Unk_08681E54 1
// Units UnitInfo_Unk_08681E74 1
// Units UnitInfo_Unk_08681E94 1

// UnitInfo @ 08681F5C
struct UnitInfo CONST_DATA UnitInfo_Chapter10B_Deploy[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 9, 2, 30, 2, 30, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_LILINA, JID_MAGE_F, PID_ROY, TRUE, FACTION_ID_BLUE, 7, 2, 31, 2, 31, { IID_THUNDER, IID_FIRE, IID_VULNERARY }, { 0 } },
    { PID_ALEN, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 10, 1, 28, 1, 28, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_STEELLANCE }, { 0 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 10, 1, 30, 1, 30, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_STEELLANCE }, { 0 } },
    { PID_WARD, JID_FIGHTER, PID_ROY, TRUE, FACTION_ID_BLUE, 8, 5, 28, 5, 28, { IID_IRONAXE, IID_HAMMER, IID_HANDAXE, IID_STEELAXE }, { 0 } },
    { PID_LOT, JID_FIGHTER, PID_ROY, TRUE, FACTION_ID_BLUE, 9, 5, 30, 5, 30, { IID_IRONAXE, IID_HAMMER, IID_HANDAXE, IID_STEELAXE }, { 0 } },
    { PID_OGIER, JID_MERCENARY, PID_ROY, TRUE, FACTION_ID_BLUE, 9, 6, 29, 6, 29, { IID_IRONBLADE, IID_IRONSWORD, IID_ARMORSLAYER, IID_STEELSWORD }, { 0 } },
    { PID_LUGH, JID_MAGE, PID_ROY, TRUE, FACTION_ID_BLUE, 9, 3, 29, 3, 29, { IID_FIRE, IID_THUNDER, IID_VULNERARY }, { 0 } },
    { PID_CHAD, JID_THIEF, PID_ROY, TRUE, FACTION_ID_BLUE, 9, 3, 28, 3, 28, { IID_IRONSWORD, IID_LOCKPICK }, { 0 } },
    { PID_SHANNA, JID_PEGASUSKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 10, 4, 29, 4, 29, { IID_STEELLANCE, IID_JAVELIN }, { 0 } },
    { PID_CLARINE, JID_TROUBADOUR, PID_ROY, TRUE, FACTION_ID_BLUE, 11, 3, 30, 3, 30, { IID_HEALSTAFF, IID_UNLOCKSTAFF, IID_RESTORESTAFF, IID_VULNERARY }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, TRUE, FACTION_ID_BLUE, 1, 2, 29, 2, 29, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_RESTORESTAFF }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0868202C
struct UnitInfo CONST_DATA UnitInfo_Chapter10B_Red[] =
{
    { PID_UNKNOWN_68, JID_GENERAL, 0, FALSE, FACTION_ID_RED, 5, 20, 2, 20, 2, { IID_SILVERLANCE, IID_JAVELIN }, { AI_A_03, AI_B_03, 0x01, 0x20 } },
    { PID_UNKNOWN_81, JID_MERCENARY, PID_UNKNOWN_68, TRUE, FACTION_ID_RED, 12, 19, 4, 19, 4, { IID_STEELBLADE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_81, JID_PRIEST, PID_UNKNOWN_68, TRUE, FACTION_ID_RED, 12, 21, 4, 21, 4, { IID_PHYSICSTAFF }, { AI_A_0E, AI_B_03, 0x11, 0x20 } },
    { PID_UNKNOWN_81, JID_FIGHTER, PID_UNKNOWN_68, TRUE, FACTION_ID_RED, 10, 22, 9, 22, 9, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_81, JID_FIGHTER, PID_UNKNOWN_68, TRUE, FACTION_ID_RED, 10, 22, 19, 22, 19, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_81, JID_ARCHER, PID_UNKNOWN_68, TRUE, FACTION_ID_RED, 11, 18, 8, 18, 8, { IID_STEELBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_81, JID_FIGHTER, PID_UNKNOWN_68, TRUE, FACTION_ID_RED, 12, 19, 13, 19, 13, { IID_KILLERAXE }, { AI_A_00, AI_B_03, 0x09, 0x00 } },
    { PID_UNKNOWN_81, JID_SHAMAN, PID_UNKNOWN_68, TRUE, FACTION_ID_RED, 9, 17, 13, 17, 13, { IID_NOSFERATU }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_81, JID_ARCHER, PID_UNKNOWN_68, TRUE, FACTION_ID_RED, 12, 18, 19, 18, 19, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_81, JID_FIGHTER, PID_UNKNOWN_68, TRUE, FACTION_ID_RED, 10, 12, 28, 12, 28, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_81, JID_FIGHTER, PID_UNKNOWN_68, TRUE, FACTION_ID_RED, 10, 14, 28, 14, 28, { IID_HANDAXE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_81, JID_MERCENARY, PID_UNKNOWN_68, TRUE, FACTION_ID_RED, 9, 18, 27, 18, 27, { IID_STEELSWORD }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_81, JID_FIGHTER, PID_UNKNOWN_68, TRUE, FACTION_ID_RED, 10, 6, 6, 6, 6, { IID_HANDAXE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_81, JID_ARCHER, PID_UNKNOWN_68, TRUE, FACTION_ID_RED, 11, 12, 9, 12, 9, { IID_IRONBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_81, JID_ARCHER, PID_UNKNOWN_68, TRUE, FACTION_ID_RED, 12, 7, 11, 7, 11, { IID_IRONBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_81, JID_FIGHTER, PID_UNKNOWN_68, TRUE, FACTION_ID_RED, 10, 11, 11, 11, 11, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_81, JID_SHAMAN, PID_UNKNOWN_68, TRUE, FACTION_ID_RED, 10, 15, 17, 15, 17, { IID_FLUX }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_81, JID_SHAMAN, PID_UNKNOWN_68, TRUE, FACTION_ID_RED, 10, 17, 21, 17, 21, { IID_FLUX }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_81, JID_ARCHER, PID_UNKNOWN_68, TRUE, FACTION_ID_RED, 11, 16, 19, 16, 19, { IID_STEELBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_81, JID_ARCHER, PID_UNKNOWN_68, TRUE, FACTION_ID_RED, 12, 15, 24, 15, 24, { IID_STEELBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_81, JID_SHAMAN, PID_UNKNOWN_68, TRUE, FACTION_ID_RED, 12, 13, 15, 13, 15, { IID_FLUX }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_81, JID_FIGHTER, PID_UNKNOWN_68, TRUE, FACTION_ID_RED, 10, 13, 19, 13, 19, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_81, JID_SHAMAN, PID_UNKNOWN_68, TRUE, FACTION_ID_RED, 9, 13, 23, 13, 23, { IID_FLUX }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_81, JID_PRIEST, PID_UNKNOWN_68, TRUE, FACTION_ID_RED, 11, 18, 4, 18, 4, { IID_PHYSICSTAFF }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_81, JID_ARCHER, PID_UNKNOWN_68, TRUE, FACTION_ID_RED, 12, 8, 17, 8, 17, { IID_STEELBOW }, { AI_A_00, AI_B_03, 0x29, 0x00 } },
    { PID_UNKNOWN_81, JID_FIGHTER, PID_UNKNOWN_68, TRUE, FACTION_ID_RED, 10, 3, 16, 3, 16, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086821DC
struct UnitInfo CONST_DATA UnitInfo_Unk_086821DC[] =
{
    { PID_UNKNOWN_80, JID_BRIGAND, 0, TRUE, FACTION_ID_RED, 13, 2, 0, 1, 1, { IID_IRONAXE }, { AI_A_00, AI_B_04, 0x09, 0x00 } },
    { PID_UNKNOWN_80, JID_BRIGAND, 0, TRUE, FACTION_ID_RED, 13, 2, 0, 1, 0, { IID_HANDAXE }, { AI_A_00, AI_B_04, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0868220C
struct UnitInfo CONST_DATA UnitInfo_Unk_0868220C[] =
{
    { PID_UNKNOWN_B6, JID_BRIGAND, 0, FALSE, FACTION_ID_RED, 11, 2, 0, 0, 0, { IID_IRONAXE }, { AI_A_00, AI_B_04, 0x09, 0x00 } },
    { PID_GONZALEZ_ALT, JID_BRIGAND, 0, FALSE, FACTION_ID_RED, 11, 2, 0, 0, 1, { IID_DEVILAXE }, { AI_A_00, AI_B_04, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0868223C
struct UnitInfo CONST_DATA UnitInfo_Unk_0868223C[] =
{
    { PID_UNKNOWN_81, JID_PALADIN, 0, TRUE, FACTION_ID_RED, 5, 0, 31, 2, 30, { IID_SILVERLANCE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_81, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 13, 2, 31, 1, 29, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_81, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 13, 2, 29, 1, 31, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0868227C
struct UnitInfo CONST_DATA UnitInfo_Unk_0868227C[] =
{
    { PID_UNKNOWN_81, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 13, 1, 31, 3, 29, { IID_STEELLANCE, IID_IRONSWORD }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_81, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 12, 1, 29, 3, 31, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086822AC
struct UnitInfo CONST_DATA UnitInfo_Chapter10B_KleinSquadA[] =
{
    { PID_KLEIN, JID_SNIPER, 0, FALSE, FACTION_ID_RED, 1, 21, 31, 21, 30, { IID_SILVERBOW, IID_WHITEGEM }, { AI_A_01, AI_B_00, 0x29, 0x00 } },
    { PID_KLEIN_SQUAD, JID_ARCHER, PID_KLEIN, TRUE, FACTION_ID_RED, 14, 20, 28, 20, 29, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_KLEIN_SQUAD, JID_ARCHER, PID_KLEIN, TRUE, FACTION_ID_RED, 14, 22, 28, 22, 29, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086822EC
struct UnitInfo CONST_DATA UnitInfo_Chapter10B_KleinSquadB[] =
{
    { PID_KLEIN_SQUAD, JID_ARCHER, PID_KLEIN, TRUE, FACTION_ID_RED, 15, 20, 30, 20, 31, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_KLEIN_SQUAD, JID_ARCHER, PID_KLEIN, TRUE, FACTION_ID_RED, 15, 22, 30, 22, 31, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0868231C
struct UnitInfo CONST_DATA UnitInfo_Chapter10B_TheaSquadA[] =
{
    { PID_THEA, JID_PEGASUSKNIGHT, 0, FALSE, FACTION_ID_RED, 8, 12, 0, 12, 1, { IID_SLIMLANCE, IID_JAVELIN }, { AI_A_01, AI_B_00, 0x69, 0x00 } },
    { PID_THEA_SQUAD, JID_PEGASUSKNIGHT, PID_THEA, TRUE, FACTION_ID_RED, 6, 10, 0, 11, 0, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x69, 0x00 } },
    { PID_THEA_SQUAD, JID_PEGASUSKNIGHT, PID_THEA, TRUE, FACTION_ID_RED, 6, 14, 0, 13, 0, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x69, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0868235C
struct UnitInfo CONST_DATA UnitInfo_Chapter10B_TheaSquadB[] =
{
    { PID_THEA_SQUAD, JID_PEGASUSKNIGHT, PID_THEA, TRUE, FACTION_ID_RED, 6, 11, 1, 12, 2, { IID_IRONLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x69, 0x00 } },
    { PID_THEA_SQUAD, JID_PEGASUSKNIGHT, PID_THEA, TRUE, FACTION_ID_RED, 6, 15, 1, 14, 2, { IID_IRONLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x69, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0868238C
struct UnitInfo CONST_DATA UnitInfo_Unk_0868238C[] =
{
    { PID_UNKNOWN_81, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 18, 0, 31, 2, 30, { IID_STEELLANCE, IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_81, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 13, 2, 31, 1, 29, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_81, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 13, 2, 29, 1, 31, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086823CC
struct UnitInfo CONST_DATA UnitInfo_Unk_086823CC[] =
{
    { PID_UNKNOWN_81, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 13, 1, 31, 3, 29, { IID_STEELLANCE, IID_IRONSWORD }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_81, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 12, 1, 29, 3, 31, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086823FC
struct UnitInfo CONST_DATA UnitInfo_Chapter10B_CutsceneMelady[] =
{
    { PID_MELADY, JID_WYVERNRIDER_F, 0, TRUE, FACTION_ID_RED, 6, 20, 2, 6, 1, { IID_SILVERBOW, IID_WHITEGEM }, { AI_A_01, AI_B_00, 0x29, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0868241C
struct UnitInfo CONST_DATA UnitInfo_Chapter10B_CutsceneGalle[] =
{
    { PID_GALLE, JID_WYVERNLORD, 0, TRUE, FACTION_ID_RED, 6, 6, 0, 6, 0, { IID_SILVERBOW, IID_WHITEGEM }, { AI_A_01, AI_B_00, 0x29, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0868243C
struct UnitInfo CONST_DATA UnitInfo_Chapter10B_CutsceneThea[] =
{
    { PID_THEA, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 6, 17, 31, 20, 30, { IID_SILVERBOW, IID_WHITEGEM }, { AI_A_01, AI_B_00, 0x29, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0868245C
struct UnitInfo CONST_DATA UnitInfo_Unk_0868245C[] =
{
    { PID_ELFFIN, JID_BARD, 0, TRUE, FACTION_ID_GREEN, 6, 16, 7, 16, 7, { IID_SILVERBOW, IID_WHITEGEM }, { AI_A_01, AI_B_00, 0x29, 0x00 } },
    { 0 }, // end
};

// EventScr @ 0868247C
EventScr CONST_DATA EventScr_LoadUnits_Chapter10B_Deploy[] =
{
    EvtLoadUnits(UnitInfo_Chapter10B_Deploy)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08682490
EventScr CONST_DATA EventScr_LoadUnits_Chapter10B_Red[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Chapter10B_Red)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086824AC
EventScr CONST_DATA EventScr_LoadUnits_Unk_086821DC[] =
{
    EvtLoadUnits(UnitInfo_Unk_086821DC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086824C0
EventScr CONST_DATA EventScr_LoadUnits_Unk_0868220C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0868220C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086824D4
EventScr CONST_DATA EventScr_LoadUnits_Unk_0868223C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0868223C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086824E8
EventScr CONST_DATA EventScr_LoadUnits_Unk_0868227C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0868227C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086824FC
EventScr CONST_DATA EventScr_LoadUnits_Chapter10B_KleinSquadA[] =
{
    EvtLoadUnits(UnitInfo_Chapter10B_KleinSquadA)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08682510
EventScr CONST_DATA EventScr_LoadUnits_Chapter10B_KleinSquadB[] =
{
    EvtLoadUnits(UnitInfo_Chapter10B_KleinSquadB)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08682524
EventScr CONST_DATA EventScr_LoadUnits_Chapter10B_TheaSquadA[] =
{
    EvtLoadUnits(UnitInfo_Chapter10B_TheaSquadA)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08682538
EventScr CONST_DATA EventScr_LoadUnits_Chapter10B_TheaSquadB[] =
{
    EvtLoadUnits(UnitInfo_Chapter10B_TheaSquadB)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0868254C
EventScr CONST_DATA EventScr_LoadUnits_Unk_0868238C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0868238C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08682560
EventScr CONST_DATA EventScr_LoadUnits_Unk_086823CC[] =
{
    EvtLoadUnits(UnitInfo_Unk_086823CC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08682574
EventScr CONST_DATA EventScr_LoadUnits_Chapter10B_CutsceneMelady[] =
{
    EvtLoadUnits(UnitInfo_Chapter10B_CutsceneMelady)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08682588
EventScr CONST_DATA EventScr_LoadUnits_Chapter10B_CutsceneGalle[] =
{
    EvtLoadUnits(UnitInfo_Chapter10B_CutsceneGalle)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0868259C
EventScr CONST_DATA EventScr_LoadUnits_Chapter10B_CutsceneThea[] =
{
    EvtLoadUnits(UnitInfo_Chapter10B_CutsceneThea)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086825B0
EventScr CONST_DATA EventScr_LoadUnits_Unk_0868245C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0868245C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 26 summary:
// Units UnitInfo_Chapter10B_Deploy 1
// Units UnitInfo_Chapter10B_Red 2
// Units UnitInfo_Unk_086821DC 1
// Units UnitInfo_Unk_0868220C 1
// Units UnitInfo_Unk_0868223C 1
// Units UnitInfo_Unk_0868227C 1
// Units UnitInfo_Chapter10B_KleinSquadA 1
// Units UnitInfo_Chapter10B_KleinSquadB 1
// Units UnitInfo_Chapter10B_TheaSquadA 1
// Units UnitInfo_Chapter10B_TheaSquadB 1
// Units UnitInfo_Unk_0868238C 1
// Units UnitInfo_Unk_086823CC 1
// Units UnitInfo_Chapter10B_CutsceneMelady 1
// Units UnitInfo_Chapter10B_CutsceneGalle 1
// Units UnitInfo_Chapter10B_CutsceneThea 1
// Units UnitInfo_Unk_0868245C 1

// UnitInfo @ 086825C4
struct UnitInfo CONST_DATA UnitInfo_Unk_086825C4[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 6, 26, 2, 26, 2, { IID_IRONSWORD, IID_LIGHTBRAND, IID_RAPIER, IID_RAPIER }, { 0 } },
    { PID_LILINA, JID_MAGE, PID_ROY, TRUE, FACTION_ID_BLUE, 8, 25, 3, 25, 3, { IID_THUNDER, IID_FIRE, IID_VULNERARY }, { 0 } },
    { PID_ALEN, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 13, 27, 3, 27, 3, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_STEELLANCE }, { 0 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 13, 25, 1, 25, 1, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_STEELLANCE }, { 0 } },
    { PID_WARD, JID_FIGHTER, PID_ROY, TRUE, FACTION_ID_BLUE, 11, 27, 1, 27, 1, { IID_IRONAXE, IID_HAMMER, IID_HANDAXE, IID_STEELAXE }, { 0 } },
    { PID_DIECK, JID_MERCENARY, PID_ROY, TRUE, FACTION_ID_BLUE, 15, 24, 2, 24, 2, { IID_IRONSWORD, IID_STEELSWORD, IID_IRONBLADE }, { 0 } },
    { PID_LUGH, JID_MAGE, PID_ROY, TRUE, FACTION_ID_BLUE, 12, 28, 2, 28, 2, { IID_FIRE, IID_THUNDER, IID_VULNERARY }, { 0 } },
    { PID_CHAD, JID_THIEF, PID_ROY, TRUE, FACTION_ID_BLUE, 9, 26, 5, 26, 5, { IID_IRONSWORD, IID_LOCKPICK }, { 0 } },
    { PID_RUTGER, JID_MYRMIDON, PID_ROY, TRUE, FACTION_ID_BLUE, 16, 25, 6, 25, 6, { IID_IRONSWORD, IID_KILLINGEDGE, IID_ARMORSLAYER, IID_STEELSWORD }, { 0 } },
    { PID_ELEN, JID_CLERIC, PID_ROY, TRUE, FACTION_ID_BLUE, 10, 27, 6, 27, 6, { IID_HEALSTAFF, IID_UNLOCKSTAFF, IID_RESTORESTAFF, IID_VULNERARY }, { 0 } },
    { PID_WOLT, JID_ARCHER, PID_ROY, TRUE, FACTION_ID_BLUE, 15, 24, 4, 24, 4, { IID_IRONBOW, IID_KILLERBOW, IID_STEELBOW, IID_VULNERARY }, { 0 } },
    { PID_CLARINE, JID_TROUBADOUR, PID_ROY, TRUE, FACTION_ID_BLUE, 12, 26, 7, 26, 7, { IID_HEALSTAFF, IID_MENDSTAFF, IID_RESTORESTAFF, IID_VULNERARY }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, TRUE, FACTION_ID_BLUE, 1, 26, 4, 26, 4, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_RESTORESTAFF }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 086826A4
struct UnitInfo CONST_DATA UnitInfo_Unk_086826A4[] =
{
    { PID_ELFFIN, JID_BARD, 0, FALSE, FACTION_ID_BLUE, 1, 28, 4, 28, 4, { IID_VULNERARY, IID_SERAPHROBE, IID_BLUEGEM }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 086826C4
struct UnitInfo CONST_DATA UnitInfo_Unk_086826C4[] =
{
    { PID_UNKNOWN_C8, JID_GENERAL, 0, FALSE, FACTION_ID_RED, 8, 2, 25, 2, 25, { IID_SILVERAXE, IID_HORSESLAYER, IID_JAVELIN }, { AI_A_03, AI_B_03, 0x60, 0x20 } },
    { PID_UNKNOWN_A3, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 12, 12, 2, 12, 2, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x61, 0x00 } },
    { PID_UNKNOWN_A3, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 13, 9, 3, 9, 3, { IID_STEELBOW }, { AI_A_09, AI_B_03, 0x61, 0x00 } },
    { PID_UNKNOWN_A3, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 13, 12, 4, 12, 4, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x61, 0x00 } },
    { PID_UNKNOWN_A3, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 12, 21, 10, 21, 10, { IID_HANDAXE }, { AI_A_00, AI_B_00, 0x61, 0x00 } },
    { PID_UNKNOWN_A3, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 12, 23, 10, 23, 10, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x61, 0x00 } },
    { PID_UNKNOWN_A3, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 11, 22, 11, 22, 11, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x61, 0x00 } },
    { PID_UNKNOWN_A3, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 13, 9, 11, 9, 11, { IID_FLUX }, { AI_A_00, AI_B_00, 0x61, 0x00 } },
    { PID_UNKNOWN_A3, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 12, 10, 12, 10, 12, { IID_STEELBOW }, { AI_A_09, AI_B_03, 0x61, 0x00 } },
    { PID_UNKNOWN_A3, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 13, 16, 3, 16, 3, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x61, 0x00 } },
    { PID_UNKNOWN_A3, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 13, 16, 5, 16, 5, { IID_HANDAXE }, { AI_A_00, AI_B_00, 0x61, 0x00 } },
    { PID_UNKNOWN_A3, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 13, 16, 16, 16, 16, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x61, 0x00 } },
    { PID_UNKNOWN_A3, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 13, 18, 16, 18, 16, { IID_HANDAXE }, { AI_A_00, AI_B_00, 0x61, 0x00 } },
    { PID_UNKNOWN_A3, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 12, 17, 18, 17, 18, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x61, 0x00 } },
    { PID_UNKNOWN_A3, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 12, 15, 20, 15, 20, { IID_IRONBOW }, { AI_A_00, AI_B_00, 0x61, 0x00 } },
    { PID_UNKNOWN_A3, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 13, 22, 19, 22, 19, { IID_IRONBOW }, { AI_A_09, AI_B_03, 0x61, 0x00 } },
    { PID_UNKNOWN_A3, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 3, 11, 4, 11, 4, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x62, 0x00 } },
    { PID_UNKNOWN_A3, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 15, 12, 25, 12, 25, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x61, 0x00 } },
    { PID_UNKNOWN_A3, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 15, 14, 25, 14, 25, { IID_HANDAXE }, { AI_A_00, AI_B_03, 0x61, 0x00 } },
    { PID_UNKNOWN_A3, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 14, 13, 26, 13, 26, { IID_STEELSWORD }, { AI_A_00, AI_B_03, 0x61, 0x00 } },
    { PID_UNKNOWN_A3, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 14, 13, 27, 13, 27, { IID_STEELBOW }, { AI_A_00, AI_B_03, 0x61, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08682824
struct UnitInfo CONST_DATA UnitInfo_Unk_08682824[] =
{
    { PID_UNKNOWN_D4, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 11, 2, 26, 1, 26, { IID_ARMORSLAYER }, { AI_A_03, AI_B_03, 0x62, 0x00 } },
    { PID_UNKNOWN_D4, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 14, 2, 26, 2, 27, { IID_STEELSWORD }, { AI_A_03, AI_B_03, 0x62, 0x00 } },
    { PID_UNKNOWN_D4, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 11, 2, 26, 3, 26, { IID_LANCEREAVER }, { AI_A_03, AI_B_03, 0x62, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08682864
struct UnitInfo CONST_DATA UnitInfo_Unk_08682864[] =
{
    { PID_UNKNOWN_A3, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 2, 0, 26, 0, 26, { IID_DEVILAXE }, { AI_A_00, AI_B_00, 0x42, 0x00 } },
    { PID_UNKNOWN_A3, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 12, 0, 24, 0, 24, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x42, 0x00 } },
    { PID_UNKNOWN_A3, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 12, 0, 23, 0, 23, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x42, 0x00 } },
    { PID_UNKNOWN_A3, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 12, 0, 25, 0, 25, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x42, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086828B4
struct UnitInfo CONST_DATA UnitInfo_Unk_086828B4[] =
{
    { PID_BARTRE, JID_WARRIOR, 0, FALSE, FACTION_ID_GREEN, 2, 0, 11, 1, 11, { IID_BRAVEAXE }, { AI_A_00, AI_B_00, 0x69, 0x00 } },
    { PID_UNKNOWN_7E, JID_FIGHTER, PID_BARTRE, TRUE, FACTION_ID_GREEN, 12, 0, 10, 0, 11, { IID_IRONAXE }, { AI_A_0D, AI_B_00, 0x6A, 0x00 } },
    { PID_UNKNOWN_7E, JID_FIGHTER, PID_BARTRE, TRUE, FACTION_ID_GREEN, 12, 0, 13, 0, 12, { IID_HANDAXE }, { AI_A_0D, AI_B_00, 0x6A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086828F4
struct UnitInfo CONST_DATA UnitInfo_Unk_086828F4[] =
{
    { PID_UNKNOWN_A5, JID_PIRATE, 0, TRUE, FACTION_ID_RED, 7, 28, 19, 28, 19, { IID_STEELAXE }, { AI_A_00, AI_B_04, 0x0A, 0x00 } },
    { PID_UNKNOWN_A5, JID_PIRATE, 0, TRUE, FACTION_ID_RED, 7, 26, 24, 26, 24, { IID_IRONAXE }, { AI_A_00, AI_B_04, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08682924
struct UnitInfo CONST_DATA UnitInfo_Unk_08682924[] =
{
    { PID_UNKNOWN_A3, JID_DRUID, 0, TRUE, FACTION_ID_RED, 1, 2, 26, 4, 26, { IID_FLUX, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x42, 0x00 } },
    { PID_UNKNOWN_A3, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 14, 2, 25, 4, 25, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x42, 0x00 } },
    { PID_UNKNOWN_A3, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 12, 2, 24, 4, 24, { IID_FLUX }, { AI_A_00, AI_B_00, 0x42, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08682964
struct UnitInfo CONST_DATA UnitInfo_Unk_08682964[] =
{
    { PID_CITIZEN_A4, JID_CIVILIAN, 0, FALSE, FACTION_ID_GREEN, 1, 2, 26, 0, 20, { IID_VULNERARY }, { AI_A_06, AI_B_0C, 0x13, 0x00 } },
    { PID_CITIZEN_CD, JID_CIVILIAN, 0, FALSE, FACTION_ID_GREEN, 1, 2, 26, 0, 19, { IID_VULNERARY }, { AI_A_06, AI_B_0C, 0x13, 0x00 } },
    { PID_CITIZEN_A4, JID_CIVILIAN, 0, FALSE, FACTION_ID_GREEN, 1, 2, 26, 1, 19, { IID_VULNERARY }, { AI_A_06, AI_B_0C, 0x13, 0x00 } },
    { PID_CITIZEN_CD, JID_CIVILIAN, 0, FALSE, FACTION_ID_GREEN, 1, 2, 26, 1, 18, { IID_VULNERARY }, { AI_A_06, AI_B_0C, 0x13, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086829B4
struct UnitInfo CONST_DATA UnitInfo_Unk_086829B4[] =
{
    { PID_CITIZEN_A4, JID_CIVILIAN, 0, FALSE, FACTION_ID_GREEN, 1, 2, 26, 11, 27, { IID_VULNERARY }, { AI_A_06, AI_B_0C, 0x13, 0x00 } },
    { PID_CITIZEN_A4, JID_CIVILIAN, 0, FALSE, FACTION_ID_GREEN, 1, 2, 26, 9, 27, { IID_VULNERARY }, { AI_A_06, AI_B_0C, 0x13, 0x00 } },
    { PID_CITIZEN_CD, JID_CIVILIAN, 0, FALSE, FACTION_ID_GREEN, 1, 2, 26, 10, 27, { IID_VULNERARY }, { AI_A_06, AI_B_0C, 0x13, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086829F4
struct UnitInfo CONST_DATA UnitInfo_Unk_086829F4[] =
{
    { PID_GEESE, JID_PIRATE, PID_UNKNOWN_53, FALSE, FACTION_ID_GREEN, 10, 18, 21, 18, 22, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08682A14
struct UnitInfo CONST_DATA UnitInfo_Unk_08682A14[] =
{
    { PID_UNKNOWN_B6, JID_BRIGAND, 0, FALSE, FACTION_ID_RED, 13, 5, 27, 5, 26, { IID_IRONAXE }, { AI_A_00, AI_B_04 } },
    { PID_GONZALEZ_ALT, JID_BRIGAND, 0, FALSE, FACTION_ID_RED, 11, 6, 27, 6, 26, { IID_DEVILAXE }, { AI_A_00, AI_B_04 } },
    { 0 }, // end
};

// UnitInfo @ 08682A44
struct UnitInfo CONST_DATA UnitInfo_Unk_08682A44[] =
{
    { PID_UNKNOWN_A3, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 15, 2, 23, 4, 24, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x42, 0x00 } },
    { PID_UNKNOWN_A3, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 14, 2, 23, 1, 21, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x42, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08682A74
struct UnitInfo CONST_DATA UnitInfo_Unk_08682A74[] =
{
    { PID_UNKNOWN_A3, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 15, 2, 23, 4, 24, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x42, 0x00 } },
    { PID_UNKNOWN_A3, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 14, 2, 23, 1, 21, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x42, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08682AA4
struct UnitInfo CONST_DATA UnitInfo_Unk_08682AA4[] =
{
    { PID_UNKNOWN_A3, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 15, 2, 23, 4, 24, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x42, 0x00 } },
    { PID_UNKNOWN_A3, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 14, 2, 23, 1, 21, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x42, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08682AD4
struct UnitInfo CONST_DATA UnitInfo_Unk_08682AD4[] =
{
    { PID_UNKNOWN_C8, JID_GENERAL, 0, FALSE, FACTION_ID_RED, 6, 2, 25, 2, 25, { IID_SILVERAXE, IID_HORSESLAYER, IID_JAVELIN }, { AI_A_03, AI_B_03, 0x60, 0x20 } },
    { 0 }, // end
};

// UnitInfo @ 08682AF4
struct UnitInfo CONST_DATA UnitInfo_Unk_08682AF4[] =
{
    { PID_UNKNOWN_5E, JID_PALADIN, 0, FALSE, FACTION_ID_RED, 6, 2, 25, 2, 25, { IID_SILVERAXE, IID_HORSESLAYER, IID_JAVELIN }, { AI_A_03, AI_B_03, 0x60, 0x20 } },
    { 0 }, // end
};

// EventScr @ 08682B14
EventScr CONST_DATA EventScr_LoadUnits_Unk_086825C4[] =
{
    EvtLoadUnits(UnitInfo_Unk_086825C4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08682B28
EventScr CONST_DATA EventScr_LoadUnits_Unk_086826A4[] =
{
    EvtLoadUnits(UnitInfo_Unk_086826A4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08682B3C
EventScr CONST_DATA EventScr_LoadUnits_Unk_086826C4[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_086826C4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08682B58
EventScr CONST_DATA EventScr_LoadUnits_Unk_08682824[] =
{
    EvtLoadUnits(UnitInfo_Unk_08682824)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08682B6C
EventScr CONST_DATA EventScr_LoadUnits_Unk_08682864[] =
{
    EvtLoadUnits(UnitInfo_Unk_08682864)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08682B80
EventScr CONST_DATA EventScr_LoadUnits_Unk_086828B4[] =
{
    EvtLoadUnits(UnitInfo_Unk_086828B4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08682B94
EventScr CONST_DATA EventScr_LoadUnits_Unk_086828F4[] =
{
    EvtLoadUnits(UnitInfo_Unk_086828F4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08682BA8
EventScr CONST_DATA EventScr_LoadUnits_Unk_08682924[] =
{
    EvtLoadUnits(UnitInfo_Unk_08682924)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08682BBC
EventScr CONST_DATA EventScr_LoadUnits_Unk_08682964[] =
{
    EvtLoadUnits(UnitInfo_Unk_08682964)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08682BD0
EventScr CONST_DATA EventScr_LoadUnits_Unk_086829B4[] =
{
    EvtLoadUnits(UnitInfo_Unk_086829B4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08682BE4
EventScr CONST_DATA EventScr_LoadUnits_Unk_086829F4[] =
{
    EvtLoadUnits(UnitInfo_Unk_086829F4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08682BF8
EventScr CONST_DATA EventScr_LoadUnits_Unk_08682A14[] =
{
    EvtLoadUnits(UnitInfo_Unk_08682A14)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08682C0C
EventScr CONST_DATA EventScr_LoadUnits_Unk_08682A44[] =
{
    EvtLoadUnits(UnitInfo_Unk_08682A44)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08682C20
EventScr CONST_DATA EventScr_LoadUnits_Unk_08682A74[] =
{
    EvtLoadUnits(UnitInfo_Unk_08682A74)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08682C34
EventScr CONST_DATA EventScr_LoadUnits_Unk_08682AA4[] =
{
    EvtLoadUnits(UnitInfo_Unk_08682AA4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08682C48
EventScr CONST_DATA EventScr_LoadUnits_Unk_08682AD4[] =
{
    EvtLoadUnits(UnitInfo_Unk_08682AD4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08682C5C
EventScr CONST_DATA EventScr_LoadUnits_Unk_08682AF4[] =
{
    EvtLoadUnits(UnitInfo_Unk_08682AF4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 27 summary:
// Units UnitInfo_Unk_086825C4 1
// Units UnitInfo_Unk_086826A4 1
// Units UnitInfo_Unk_086826C4 2
// Units UnitInfo_Unk_08682824 1
// Units UnitInfo_Unk_08682864 1
// Units UnitInfo_Unk_086828B4 1
// Units UnitInfo_Unk_086828F4 1
// Units UnitInfo_Unk_08682924 1
// Units UnitInfo_Unk_08682964 1
// Units UnitInfo_Unk_086829B4 1
// Units UnitInfo_Unk_086829F4 1
// Units UnitInfo_Unk_08682A14 1
// Units UnitInfo_Unk_08682A44 1
// Units UnitInfo_Unk_08682A74 1
// Units UnitInfo_Unk_08682AA4 1
// Units UnitInfo_Unk_08682AD4 1
// Units UnitInfo_Unk_08682AF4 1

// UnitInfo @ 08682C70
struct UnitInfo CONST_DATA UnitInfo_Unk_08682C70[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 18, 2, 3, 2, 3, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY, IID_SILVERSWORD }, { 0 } },
    { PID_MARCUS, JID_PALADIN, PID_ROY, TRUE, FACTION_ID_BLUE, 13, 3, 3, 3, 3, { IID_SILVERLANCE, IID_IRONSWORD, IID_IRONLANCE, IID_HORSESLAYER }, { 0 } },
    { PID_ALEN, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 1, 4, 1, 4, { IID_STEELSWORD, IID_IRONLANCE, IID_JAVELIN, IID_SILVERLANCE }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 15, 1, 2, 1, 2, { IID_IRONLANCE, IID_JAVELIN, IID_SILVERLANCE, IID_CHESTKEY }, { 0 } },
    { PID_KLEIN, JID_SNIPER, PID_ROY, TRUE, FACTION_ID_BLUE, 5, 4, 5, 4, 5, { IID_IRONBOW, IID_SILVERBOW, IID_STEELBOW, IID_KILLERBOW }, { 0 } },
    { PID_ECHIDNA, JID_HERO_F, PID_ROY, TRUE, FACTION_ID_BLUE, 5, 2, 5, 2, 5, { IID_BRAVEAXE, IID_IRONSWORD, IID_ARMORSLAYER, IID_STEELSWORD }, { 0 } },
    { PID_CECILIA, JID_VALKYRIE, PID_ROY, TRUE, FACTION_ID_BLUE, 3, 4, 2, 4, 2, { IID_ELFIRE, IID_THUNDER, IID_BOLTING, IID_HEALSTAFF }, { 0 } },
    { PID_BARTRE, JID_WARRIOR, PID_ROY, TRUE, FACTION_ID_BLUE, 2, 3, 4, 3, 4, { IID_KILLERAXE, IID_IRONAXE, IID_HANDAXE, IID_HALBERD }, { 0 } },
    { PID_ELFFIN, JID_BARD, PID_ROY, TRUE, FACTION_ID_BLUE, 1, 5, 3, 5, 3, { IID_PUREWATER, IID_CHESTKEY, IID_VULNERARY }, { 0 } },
    { PID_RAIGH, JID_SHAMAN, PID_ROY, TRUE, FACTION_ID_BLUE, 16, 4, 4, 4, 4, { IID_NOSFERATU, IID_FLUX, IID_ECLIPSE, IID_VULNERARY }, { 0 } },
    { PID_SHANNA, JID_PEGASUSKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 5, 5, 5, 5, { IID_STEELLANCE, IID_JAVELIN, IID_SILVERLANCE, IID_HORSESLAYER }, { 0 } },
    { PID_SAUL, JID_PRIEST, PID_ROY, TRUE, FACTION_ID_BLUE, 18, 3, 6, 3, 6, { IID_MENDSTAFF, IID_RESTORESTAFF, IID_WARPSTAFF, IID_RECOVERSTAFF }, { 0 } },
    { PID_THEA, JID_PEGASUSKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 1, 6, 1, 6, { IID_STEELLANCE, IID_JAVELIN, IID_SILVERLANCE, IID_HORSESLAYER }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, TRUE, FACTION_ID_BLUE, 1, 0, 4, 0, 4, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_RESTORESTAFF }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 08682D60
struct UnitInfo CONST_DATA UnitInfo_Unk_08682D60[] =
{
    { PID_UNKNOWN_5E, JID_PALADIN, 0, FALSE, FACTION_ID_RED, 10, 29, 18, 29, 18, { IID_SILVERLANCE, IID_JAVELIN }, { AI_A_03, AI_B_03, 0x00, 0x20 } },
    { PID_UNKNOWN_A6, JID_MAGE, 0, TRUE, FACTION_ID_RED, 15, 12, 5, 12, 5, { IID_FIRE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_A6, JID_MAGE, 0, TRUE, FACTION_ID_RED, 14, 14, 3, 14, 3, { IID_THUNDER }, { AI_A_00, AI_B_00, 0x08, 0x00 } },
    { PID_UNKNOWN_A6, JID_MAGE, 0, TRUE, FACTION_ID_RED, 16, 15, 6, 15, 6, { IID_FIRE }, { AI_A_00, AI_B_00, 0x08, 0x00 } },
    { PID_UNKNOWN_A6, JID_MAGE, 0, TRUE, FACTION_ID_RED, 15, 16, 2, 16, 2, { IID_ELFIRE }, { AI_A_00, AI_B_00, 0x08, 0x00 } },
    { PID_UNKNOWN_A6, JID_MAGE, 0, TRUE, FACTION_ID_RED, 17, 18, 6, 18, 6, { IID_ELFIRE }, { AI_A_00, AI_B_00, 0x08, 0x00 } },
    { PID_UNKNOWN_A6, JID_SAGE, 0, TRUE, FACTION_ID_RED, 4, 17, 4, 17, 4, { IID_ELFIRE, IID_MENDSTAFF }, { AI_A_00, AI_B_00, 0x08, 0x00 } },
    { PID_UNKNOWN_A6, JID_SAGE, 0, TRUE, FACTION_ID_RED, 6, 20, 1, 20, 1, { IID_BOLTING, IID_PHYSICSTAFF }, { AI_A_0E, AI_B_03, 0x00, 0x20 } },
    { PID_UNKNOWN_A6, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 17, 21, 5, 21, 5, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_A6, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 17, 21, 18, 21, 18, { IID_STEELBOW }, { AI_A_03, AI_B_03, 0x29, 0x00 } },
    { PID_UNKNOWN_A6, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 17, 11, 14, 11, 14, { IID_IRONLANCE }, { AI_A_03, AI_B_03, 0x09, 0x00 } },
    { PID_UNKNOWN_A6, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 17, 11, 17, 11, 17, { IID_IRONLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_A6, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 17, 13, 14, 13, 14, { IID_JAVELIN }, { AI_A_00, AI_B_09, 0x01, 0x00 } },
    { PID_UNKNOWN_A6, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 16, 13, 16, 13, 16, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_A7, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 15, 16, 14, 16, 14, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_A7, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 16, 16, 16, 16, 16, { IID_SHORTBOW }, { AI_A_00, AI_B_09, 0x29, 0x00 } },
    { PID_UNKNOWN_A7, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 14, 18, 14, 18, 14, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_A7, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 16, 18, 16, 18, 16, { IID_SHORTBOW }, { AI_A_00, AI_B_03, 0x29, 0x00 } },
    { PID_UNKNOWN_A7, JID_NOMADTROOPER, 0, TRUE, FACTION_ID_RED, 4, 19, 15, 19, 15, { IID_SHORTBOW, IID_STEELSWORD }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_A7, JID_NOMADTROOPER, 0, TRUE, FACTION_ID_RED, 5, 21, 15, 21, 15, { IID_SHORTBOW, IID_STEELSWORD }, { AI_A_00, AI_B_09, 0x01, 0x00 } },
    { PID_UNKNOWN_A8, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 16, 27, 15, 27, 15, { IID_AXEREAVER }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_A8, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 16, 27, 19, 27, 19, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_A8, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 16, 25, 3, 25, 3, { IID_AXEREAVER }, { AI_A_00, AI_B_09, 0x01, 0x00 } },
    { PID_UNKNOWN_A8, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 16, 27, 3, 27, 3, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_A8, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 13, 21, 10, 21, 10, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_A8, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 13, 19, 10, 19, 10, { IID_AXEREAVER }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_A8, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 13, 20, 12, 20, 12, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_A7, JID_THIEF, 0, TRUE, FACTION_ID_RED, 17, 19, 17, 19, 17, { IID_IRONSWORD, IID_LOCKPICK }, { AI_A_06, AI_B_05, 0x01, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08682F30
struct UnitInfo CONST_DATA UnitInfo_Unk_08682F30[] =
{
    { PID_UNKNOWN_A7, JID_THIEF, 0, TRUE, FACTION_ID_RED, 17, 17, 3, 14, 5, { IID_POISONSWORD, IID_LOCKPICK }, { AI_A_06, AI_B_05 } },
    { 0 }, // end
};

// UnitInfo @ 08682F50
struct UnitInfo CONST_DATA UnitInfo_Unk_08682F50[] =
{
    { PID_UNKNOWN_A7, JID_THIEF, 0, TRUE, FACTION_ID_RED, 17, 17, 3, 17, 3, { IID_POISONSWORD, IID_LOCKPICK }, { AI_A_06, AI_B_05 } },
    { 0 }, // end
};

// UnitInfo @ 08682F70
struct UnitInfo CONST_DATA UnitInfo_Unk_08682F70[] =
{
    { PID_UNKNOWN_A6, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 16, 5, 1, 5, 1, { IID_STEELSWORD, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_A6, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 17, 29, 11, 29, 11, { IID_STEELSWORD, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08682FA0
struct UnitInfo CONST_DATA UnitInfo_Unk_08682FA0[] =
{
    { PID_UNKNOWN_A7, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 16, 16, 2, 16, 2, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_A7, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 15, 17, 3, 17, 3, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08682FD0
struct UnitInfo CONST_DATA UnitInfo_Unk_08682FD0[] =
{
    { PID_DOUGLAS, JID_GENERAL, 0, FALSE, FACTION_ID_BLUE, 10, 3, 6, 3, 6, { IID_SILVERLANCE, IID_SILVERAXE }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08682FF0
struct UnitInfo CONST_DATA UnitInfo_Unk_08682FF0[] =
{
    { PID_YODER, JID_BISHOP, 0, FALSE, FACTION_ID_GREEN, 10, 2, 1, 2, 1, { IID_SILVERLANCE, IID_JAVELIN }, { AI_A_03, AI_B_03, 0x00, 0x20 } },
    { 0 }, // end
};

// EventScr @ 08683010
EventScr CONST_DATA EventScr_LoadUnits_Unk_08682C70[] =
{
    EvtLoadUnits(UnitInfo_Unk_08682C70)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08683024
EventScr CONST_DATA EventScr_LoadUnits_Unk_08682D60[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_08682D60)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08683040
EventScr CONST_DATA EventScr_LoadUnits_Unk_08682F30[] =
{
    EvtLoadUnits(UnitInfo_Unk_08682F30)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08683054
EventScr CONST_DATA EventScr_LoadUnits_Unk_08682F50[] =
{
    EvtLoadUnits(UnitInfo_Unk_08682F50)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08683068
EventScr CONST_DATA EventScr_LoadUnits_Unk_08682F70[] =
{
    EvtLoadUnits(UnitInfo_Unk_08682F70)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0868307C
EventScr CONST_DATA EventScr_LoadUnits_Unk_08682FA0[] =
{
    EvtLoadUnits(UnitInfo_Unk_08682FA0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08683090
EventScr CONST_DATA EventScr_LoadUnits_Unk_08682FD0[] =
{
    EvtLoadUnits(UnitInfo_Unk_08682FD0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086830A4
EventScr CONST_DATA EventScr_LoadUnits_Unk_08682FF0[] =
{
    EvtLoadUnits(UnitInfo_Unk_08682FF0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 28 summary:
// Units UnitInfo_Unk_08682C70 1
// Units UnitInfo_Unk_08682D60 2
// Units UnitInfo_Unk_08682F30 1
// Units UnitInfo_Unk_08682F50 1
// Units UnitInfo_Unk_08682F70 1
// Units UnitInfo_Unk_08682FA0 1
// Units UnitInfo_Unk_08682FD0 1
// Units UnitInfo_Unk_08682FF0 1

// UnitInfo @ 086830B8
struct UnitInfo CONST_DATA UnitInfo_Unk_086830B8[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 19, 3, 7, 3, 7, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY, IID_SILVERSWORD }, { 0 } },
    { PID_MARCUS, JID_PALADIN, PID_ROY, TRUE, FACTION_ID_BLUE, 14, 2, 6, 2, 6, { IID_SILVERLANCE, IID_IRONSWORD, IID_IRONLANCE, IID_HORSESLAYER }, { 0 } },
    { PID_ALEN, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 1, 7, 1, 7, { IID_STEELSWORD, IID_IRONLANCE, IID_JAVELIN, IID_SILVERLANCE }, { 0 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 4, 8, 4, 8, { IID_STEELSWORD, IID_KILLERLANCE, IID_JAVELIN, IID_HORSESLAYER }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 16, 2, 10, 2, 10, { IID_IRONLANCE, IID_JAVELIN, IID_SILVERLANCE, IID_CHESTKEY }, { 0 } },
    { PID_KLEIN, JID_SNIPER, PID_ROY, TRUE, FACTION_ID_BLUE, 5, 3, 5, 3, 5, { IID_IRONBOW, IID_SILVERBOW, IID_STEELBOW, IID_KILLERBOW }, { 0 } },
    { PID_ECHIDNA, JID_HERO_F, PID_ROY, TRUE, FACTION_ID_BLUE, 6, 5, 5, 5, 5, { IID_BRAVEAXE, IID_IRONSWORD, IID_ARMORSLAYER, IID_STEELSWORD }, { 0 } },
    { PID_BARTRE, JID_WARRIOR, PID_ROY, TRUE, FACTION_ID_BLUE, 3, 0, 6, 0, 6, { IID_KILLERAXE, IID_IRONAXE, IID_HANDAXE, IID_HALBERD }, { 0 } },
    { PID_FIR, JID_MYRMIDON_F, PID_ROY, TRUE, FACTION_ID_BLUE, 18, 1, 9, 1, 9, { IID_KILLINGEDGE, IID_IRONSWORD, IID_VULNERARY, IID_STEELSWORD }, { 0 } },
    { PID_SHANNA, JID_PEGASUSKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 3, 11, 3, 11, { IID_STEELLANCE, IID_JAVELIN, IID_HORSESLAYER, IID_BRAVELANCE }, { 0 } },
    { PID_MELADY, JID_WYVERNRIDER_F, PID_ROY, TRUE, FACTION_ID_BLUE, 14, 4, 6, 4, 6, { IID_STEELLANCE, IID_JAVELIN, IID_SILVERLANCE, IID_HORSESLAYER }, { 0 } },
    { PID_ZEISS, JID_WYVERNRIDER, PID_ROY, TRUE, FACTION_ID_BLUE, 12, 1, 11, 1, 11, { IID_STEELLANCE, IID_JAVELIN, IID_SILVERLANCE, IID_HORSESLAYER }, { 0 } },
    { PID_CECILIA, JID_VALKYRIE, PID_ROY, TRUE, FACTION_ID_BLUE, 6, 5, 7, 5, 7, { IID_ELFIRE, IID_THUNDER, IID_BOLTING, IID_HEALSTAFF }, { 0 } },
    { PID_ELFFIN, JID_BARD, PID_ROY, TRUE, FACTION_ID_BLUE, 3, 1, 5, 1, 5, { IID_PUREWATER, IID_CHESTKEY, IID_VULNERARY }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, TRUE, FACTION_ID_BLUE, 1, 3, 9, 3, 9, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_RESTORESTAFF }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 086831B8
struct UnitInfo CONST_DATA UnitInfo_Unk_086831B8[] =
{
    { PID_UNKNOWN_69, JID_NOMADTROOPER, 0, FALSE, FACTION_ID_RED, 9, 17, 19, 17, 19, { IID_BRAVEBOW, IID_BRAVESWORD, IID_ELIXIR }, { AI_A_03, AI_B_03, 0x00, 0x20 } },
    { PID_UNKNOWN_A9, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 15, 13, 8, 13, 8, { IID_STEELSWORD }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_A9, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 15, 11, 10, 11, 10, { IID_STEELSWORD, IID_ELIXIR }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_A9, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 18, 13, 10, 13, 10, { IID_FLUX }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_A9, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 18, 13, 11, 13, 11, { IID_FLUX }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_A9, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 17, 16, 10, 16, 10, { IID_ARMORSLAYER, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x32, 0x00 } },
    { PID_UNKNOWN_A9, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 17, 13, 13, 13, 13, { IID_LANCEREAVER }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_A9, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 18, 26, 26, 26, 26, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_A9, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 18, 10, 15, 10, 15, { IID_SHORTBOW, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_A9, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 18, 8, 15, 8, 15, { IID_SHORTBOW, IID_ELIXIR }, { AI_A_03, AI_B_03, 0x2A, 0x00 } },
    { PID_UNKNOWN_A9, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 17, 24, 28, 24, 28, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_A9, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 18, 3, 15, 3, 15, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_A9, JID_NOMADTROOPER, 0, TRUE, FACTION_ID_RED, 6, 3, 18, 3, 18, { IID_SHORTBOW, IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_A9, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 18, 6, 19, 6, 19, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_A9, JID_NOMADTROOPER, 0, TRUE, FACTION_ID_RED, 6, 13, 19, 13, 19, { IID_SHORTBOW, IID_STEELSWORD }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_A9, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 18, 25, 12, 25, 12, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_A9, JID_NOMADTROOPER, 0, TRUE, FACTION_ID_RED, 6, 27, 14, 27, 14, { IID_SHORTBOW, IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_A9, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 18, 8, 23, 8, 23, { IID_SHORTBOW, IID_VULNERARY }, { AI_A_00, AI_B_06, 0x2A, 0x00 } },
    { PID_UNKNOWN_A9, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 18, 10, 23, 10, 23, { IID_SHORTBOW, IID_ELIXIR }, { AI_A_00, AI_B_06, 0x2A, 0x00 } },
    { PID_UNKNOWN_A9, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 17, 10, 25, 10, 25, { IID_SHORTBOW }, { AI_A_00, AI_B_06, 0x2A, 0x00 } },
    { PID_UNKNOWN_A9, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 18, 8, 25, 8, 25, { IID_SHORTBOW }, { AI_A_00, AI_B_06, 0x2A, 0x00 } },
    { PID_UNKNOWN_A9, JID_NOMADTROOPER, 0, TRUE, FACTION_ID_RED, 6, 9, 24, 9, 24, { IID_SHORTBOW, IID_STEELSWORD }, { AI_A_00, AI_B_06, 0x0A, 0x00 } },
    { PID_UNKNOWN_A9, JID_NOMADTROOPER, 0, TRUE, FACTION_ID_RED, 6, 2, 22, 2, 22, { IID_SHORTBOW, IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_A9, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 19, 2, 24, 2, 24, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_A9, JID_NOMADTROOPER, 0, TRUE, FACTION_ID_RED, 6, 2, 26, 2, 26, { IID_SHORTBOW, IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_A9, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 15, 17, 16, 17, 16, { IID_KILLINGEDGE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_A9, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 16, 21, 19, 21, 19, { IID_LANCEREAVER }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_A9, JID_DRUID, 0, TRUE, FACTION_ID_RED, 6, 17, 22, 17, 22, { IID_ECLIPSE, IID_PHYSICSTAFF }, { AI_A_0E, AI_B_03, 0x28, 0x00 } },
    { PID_UNKNOWN_AA, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 16, 25, 6, 25, 6, { IID_STEELLANCE }, { AI_A_00, AI_B_06, 0x0A, 0x00 } },
    { PID_UNKNOWN_AA, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 16, 25, 8, 25, 8, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_06, 0x0A, 0x00 } },
    { PID_UNKNOWN_AA, JID_WYVERNLORD, 0, TRUE, FACTION_ID_RED, 5, 26, 7, 26, 7, { IID_AXEREAVER, IID_ELIXIR }, { AI_A_00, AI_B_06, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086833B8
struct UnitInfo CONST_DATA UnitInfo_Unk_086833B8[] =
{
    { PID_UNKNOWN_A9, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 17, 2, 28, 2, 27, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_A9, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 17, 1, 28, 1, 27, { IID_SHORTBOW, 0, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_A9, JID_NOMADTROOPER, 0, TRUE, FACTION_ID_RED, 4, 0, 28, 0, 27, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086833F8
struct UnitInfo CONST_DATA UnitInfo_Unk_086833F8[] =
{
    { PID_UNKNOWN_A9, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 17, 27, 26, 26, 26, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_A9, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 17, 27, 27, 26, 27, { IID_SHORTBOW, 0, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_A9, JID_NOMADTROOPER, 0, TRUE, FACTION_ID_RED, 5, 27, 28, 15, 28, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08683438
struct UnitInfo CONST_DATA UnitInfo_Unk_08683438[] =
{
    { PID_UNKNOWN_A9, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 17, 15, 14, 15, 14, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08683458
struct UnitInfo CONST_DATA UnitInfo_Unk_08683458[] =
{
    { PID_UNKNOWN_A9, JID_NOMADTROOPER, 0, TRUE, FACTION_ID_RED, 6, 17, 14, 17, 14, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08683478
struct UnitInfo CONST_DATA UnitInfo_Unk_08683478[] =
{
    { PID_UNKNOWN_A9, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 17, 19, 14, 19, 14, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08683498
struct UnitInfo CONST_DATA UnitInfo_Unk_08683498[] =
{
    { PID_UNKNOWN_A9, JID_NOMADTROOPER, 0, TRUE, FACTION_ID_RED, 6, 13, 15, 13, 15, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086834B8
struct UnitInfo CONST_DATA UnitInfo_Unk_086834B8[] =
{
    { PID_UNKNOWN_A9, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 17, 21, 15, 21, 15, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086834D8
struct UnitInfo CONST_DATA UnitInfo_Unk_086834D8[] =
{
    { PID_UNKNOWN_A9, JID_NOMADTROOPER, 0, TRUE, FACTION_ID_RED, 6, 12, 17, 12, 17, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086834F8
struct UnitInfo CONST_DATA UnitInfo_Unk_086834F8[] =
{
    { PID_UNKNOWN_A9, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 17, 22, 17, 22, 17, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08683518
struct UnitInfo CONST_DATA UnitInfo_Unk_08683518[] =
{
    { PID_UNKNOWN_A9, JID_NOMADTROOPER, 0, TRUE, FACTION_ID_RED, 6, 12, 19, 12, 19, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08683538
struct UnitInfo CONST_DATA UnitInfo_Unk_08683538[] =
{
    { PID_UNKNOWN_A9, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 17, 22, 19, 22, 19, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08683558
struct UnitInfo CONST_DATA UnitInfo_Unk_08683558[] =
{
    { PID_UNKNOWN_A9, JID_NOMADTROOPER, 0, TRUE, FACTION_ID_RED, 6, 12, 21, 12, 21, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08683578
struct UnitInfo CONST_DATA UnitInfo_Unk_08683578[] =
{
    { PID_UNKNOWN_A9, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 17, 22, 21, 22, 21, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08683598
struct UnitInfo CONST_DATA UnitInfo_Unk_08683598[] =
{
    { PID_UNKNOWN_A9, JID_NOMADTROOPER, 0, TRUE, FACTION_ID_RED, 6, 13, 23, 13, 23, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086835B8
struct UnitInfo CONST_DATA UnitInfo_Unk_086835B8[] =
{
    { PID_UNKNOWN_A9, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 17, 21, 23, 21, 23, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086835D8
struct UnitInfo CONST_DATA UnitInfo_Unk_086835D8[] =
{
    { PID_UNKNOWN_A9, JID_NOMADTROOPER, 0, TRUE, FACTION_ID_RED, 6, 15, 24, 15, 24, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x28, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086835F8
struct UnitInfo CONST_DATA UnitInfo_Unk_086835F8[] =
{
    { PID_UNKNOWN_A9, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 17, 19, 24, 19, 24, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x28, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08683618
struct UnitInfo CONST_DATA UnitInfo_Unk_08683618[] =
{
    { PID_UNKNOWN_AA, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 14, 27, 0, 26, 0, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x08, 0x00 } },
    { PID_UNKNOWN_AA, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 14, 27, 1, 26, 1, { IID_AXEREAVER }, { AI_A_00, AI_B_00, 0x08, 0x00 } },
    { PID_UNKNOWN_AA, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 15, 27, 2, 26, 2, { IID_HORSESLAYER }, { AI_A_00, AI_B_00, 0x38, 0x00 } },
    { 0 }, // end
};

// EventScr @ 08683658
EventScr CONST_DATA EventScr_LoadUnits_Unk_086830B8[] =
{
    EvtLoadUnits(UnitInfo_Unk_086830B8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0868366C
EventScr CONST_DATA EventScr_LoadUnits_Unk_086831B8[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_086831B8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08683688
EventScr CONST_DATA EventScr_LoadUnits_Unk_086833B8[] =
{
    EvtLoadUnits(UnitInfo_Unk_086833B8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0868369C
EventScr CONST_DATA EventScr_LoadUnits_Unk_086833F8[] =
{
    EvtLoadUnits(UnitInfo_Unk_086833F8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086836B0
EventScr CONST_DATA EventScr_LoadUnits_Unk_08683438[] =
{
    EvtLoadUnits(UnitInfo_Unk_08683438)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086836C4
EventScr CONST_DATA EventScr_LoadUnits_Unk_08683458[] =
{
    EvtLoadUnits(UnitInfo_Unk_08683458)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086836D8
EventScr CONST_DATA EventScr_LoadUnits_Unk_08683478[] =
{
    EvtLoadUnits(UnitInfo_Unk_08683478)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086836EC
EventScr CONST_DATA EventScr_LoadUnits_Unk_08683498[] =
{
    EvtLoadUnits(UnitInfo_Unk_08683498)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08683700
EventScr CONST_DATA EventScr_LoadUnits_Unk_086834B8[] =
{
    EvtLoadUnits(UnitInfo_Unk_086834B8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08683714
EventScr CONST_DATA EventScr_LoadUnits_Unk_086834D8[] =
{
    EvtLoadUnits(UnitInfo_Unk_086834D8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08683728
EventScr CONST_DATA EventScr_LoadUnits_Unk_086834F8[] =
{
    EvtLoadUnits(UnitInfo_Unk_086834F8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0868373C
EventScr CONST_DATA EventScr_LoadUnits_Unk_08683518[] =
{
    EvtLoadUnits(UnitInfo_Unk_08683518)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08683750
EventScr CONST_DATA EventScr_LoadUnits_Unk_08683538[] =
{
    EvtLoadUnits(UnitInfo_Unk_08683538)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08683764
EventScr CONST_DATA EventScr_LoadUnits_Unk_08683558[] =
{
    EvtLoadUnits(UnitInfo_Unk_08683558)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08683778
EventScr CONST_DATA EventScr_LoadUnits_Unk_08683578[] =
{
    EvtLoadUnits(UnitInfo_Unk_08683578)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0868378C
EventScr CONST_DATA EventScr_LoadUnits_Unk_08683598[] =
{
    EvtLoadUnits(UnitInfo_Unk_08683598)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086837A0
EventScr CONST_DATA EventScr_LoadUnits_Unk_086835B8[] =
{
    EvtLoadUnits(UnitInfo_Unk_086835B8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086837B4
EventScr CONST_DATA EventScr_LoadUnits_Unk_086835D8[] =
{
    EvtLoadUnits(UnitInfo_Unk_086835D8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086837C8
EventScr CONST_DATA EventScr_LoadUnits_Unk_086835F8[] =
{
    EvtLoadUnits(UnitInfo_Unk_086835F8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086837DC
EventScr CONST_DATA EventScr_LoadUnits_Unk_08683618[] =
{
    EvtLoadUnits(UnitInfo_Unk_08683618)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 29 summary:
// Units UnitInfo_Unk_086830B8 1
// Units UnitInfo_Unk_086831B8 2
// Units UnitInfo_Unk_086833B8 1
// Units UnitInfo_Unk_086833F8 1
// Units UnitInfo_Unk_08683438 1
// Units UnitInfo_Unk_08683458 1
// Units UnitInfo_Unk_08683478 1
// Units UnitInfo_Unk_08683498 1
// Units UnitInfo_Unk_086834B8 1
// Units UnitInfo_Unk_086834D8 1
// Units UnitInfo_Unk_086834F8 1
// Units UnitInfo_Unk_08683518 1
// Units UnitInfo_Unk_08683538 1
// Units UnitInfo_Unk_08683558 1
// Units UnitInfo_Unk_08683578 1
// Units UnitInfo_Unk_08683598 1
// Units UnitInfo_Unk_086835B8 1
// Units UnitInfo_Unk_086835D8 1
// Units UnitInfo_Unk_086835F8 1
// Units UnitInfo_Unk_08683618 1

// UnitInfo @ 086837F0
struct UnitInfo CONST_DATA UnitInfo_Unk_086837F0[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 20, 20, 31, 20, 31, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY, IID_SILVERSWORD }, { 0 } },
    { PID_MARCUS, JID_PALADIN, PID_ROY, TRUE, FACTION_ID_BLUE, 15, 19, 30, 19, 30, { IID_SILVERLANCE, IID_IRONSWORD, IID_IRONLANCE, IID_HORSESLAYER }, { 0 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 21, 30, 21, 30, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN }, { 0 } },
    { PID_LUGH, JID_MAGE, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 18, 29, 18, 29, { IID_FIRE, IID_AIRCALIBUR, IID_ELFIRE, IID_THUNDER }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 17, 20, 29, 20, 29, { IID_IRONLANCE, IID_JAVELIN, IID_SILVERLANCE, IID_CHESTKEY }, { 0 } },
    { PID_IGRENE, JID_SNIPER_F, PID_ROY, TRUE, FACTION_ID_BLUE, 6, 22, 29, 22, 29, { IID_IRONBOW, IID_SILVERBOW, IID_STEELBOW, IID_KILLERBOW }, { 0 } },
    { PID_DIECK, JID_HERO, PID_ROY, TRUE, FACTION_ID_BLUE, 7, 11, 30, 11, 30, { IID_BRAVEAXE, IID_IRONSWORD, IID_ARMORSLAYER, IID_STEELSWORD }, { 0 } },
    { PID_WARD, JID_FIGHTER, PID_ROY, TRUE, FACTION_ID_BLUE, 18, 10, 29, 10, 29, { IID_IRONAXE, IID_HANDAXE, IID_SILVERAXE, IID_KILLERAXE }, { 0 } },
    { PID_CECILIA, JID_VALKYRIE, PID_ROY, TRUE, FACTION_ID_BLUE, 7, 10, 31, 10, 31, { IID_ELFIRE, IID_TORCHSTAFF, IID_BOLTING, IID_HEALSTAFF }, { 0 } },
    { PID_FIR, JID_MYRMIDON_F, PID_ROY, TRUE, FACTION_ID_BLUE, 18, 12, 29, 12, 29, { IID_WODAO, IID_IRONSWORD, IID_HEROCREST, IID_STEELSWORD }, { 0 } },
    { PID_SUE, JID_NOMAD_F, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 12, 31, 12, 31, { IID_SHORTBOW, IID_IRONBOW, IID_LONGBOW, IID_BRAVEBOW }, { 0 } },
    { PID_ZEISS, JID_WYVERNRIDER, PID_ROY, TRUE, FACTION_ID_BLUE, 15, 22, 31, 22, 31, { IID_STEELLANCE, IID_JAVELIN, IID_SILVERLANCE, IID_HORSESLAYER }, { 0 } },
    { PID_SIN, JID_NOMAD, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 9, 30, 9, 30, { IID_SHORTBOW, IID_IRONBOW, IID_LONGBOW, IID_BRAVEBOW }, { 0 } },
    { PID_MELADY, JID_WYVERNRIDER_F, PID_ROY, TRUE, FACTION_ID_BLUE, 15, 23, 30, 23, 30, { IID_STEELLANCE, IID_JAVELIN, IID_SILVERLANCE, IID_HORSESLAYER }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, TRUE, FACTION_ID_BLUE, 1, 18, 31, 18, 31, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_RESTORESTAFF }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 086838F0
struct UnitInfo CONST_DATA UnitInfo_Unk_086838F0[] =
{
    { PID_UNKNOWN_6A, JID_SWORDMASTER, 0, FALSE, FACTION_ID_RED, 10, 16, 1, 16, 1, { IID_LIGHTBRAND }, { AI_A_03, AI_B_03, 0x00, 0x20 } },
    { PID_UNKNOWN_AB, JID_SWORDMASTER, 0, TRUE, FACTION_ID_RED, 5, 13, 9, 13, 9, { IID_STEELSWORD }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_AB, JID_SWORDMASTER, 0, TRUE, FACTION_ID_RED, 5, 19, 9, 19, 9, { IID_KILLINGEDGE }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_AB, JID_SAGE, 0, TRUE, FACTION_ID_RED, 7, 14, 4, 14, 4, { IID_ELFIRE, IID_PHYSICSTAFF, IID_SILENCESTAFF }, { 0 } },
    { PID_UNKNOWN_AB, JID_SAGE, 0, TRUE, FACTION_ID_RED, 6, 18, 4, 18, 4, { IID_AIRCALIBUR, IID_MENDSTAFF, IID_SLEEPSTAFF }, { AI_A_00, AI_B_03, 0x28, 0x00 } },
    { PID_UNKNOWN_AB, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 18, 20, 5, 20, 5, { IID_LONGBOW }, { AI_A_00, AI_B_03, 0x2A, 0x00 } },
    { PID_UNKNOWN_AB, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 18, 19, 6, 19, 6, { IID_LONGBOW }, { AI_A_00, AI_B_03, 0x2A, 0x00 } },
    { PID_UNKNOWN_AB, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 18, 12, 6, 12, 6, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_AB, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 17, 8, 6, 8, 6, { IID_LANCEREAVER }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_AB, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 17, 24, 6, 24, 6, { IID_LANCEREAVER }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_AB, JID_MAGE, 0, TRUE, FACTION_ID_RED, 18, 6, 2, 6, 2, { IID_AIRCALIBUR }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_AB, JID_MAGE, 0, TRUE, FACTION_ID_RED, 18, 28, 2, 28, 2, { IID_ELFIRE }, { AI_A_03, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_AB, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 19, 9, 12, 9, 12, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_AB, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 19, 16, 13, 16, 13, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_AB, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 18, 12, 13, 12, 13, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_AB, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 18, 19, 13, 19, 13, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_AB, JID_MAGE, 0, TRUE, FACTION_ID_RED, 17, 8, 13, 8, 13, { IID_ELFIRE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_AB, JID_MAGE, 0, TRUE, FACTION_ID_RED, 17, 24, 13, 24, 13, { IID_AIRCALIBUR }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_AB, JID_NOMADTROOPER, 0, TRUE, FACTION_ID_RED, 8, 12, 3, 12, 3, { IID_SHORTBOW, IID_STEELSWORD }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_UNKNOWN_AB, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 19, 12, 4, 12, 4, { IID_SHORTBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_AB, JID_NOMADTROOPER, 0, TRUE, FACTION_ID_RED, 8, 20, 3, 20, 3, { IID_SHORTBOW, IID_STEELSWORD }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_AB, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 18, 20, 4, 20, 4, { IID_SHORTBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_AB, JID_NOMADTROOPER, 0, TRUE, FACTION_ID_RED, 8, 16, 6, 16, 6, { IID_SHORTBOW, IID_STEELSWORD, IID_ELIXIR }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_UNKNOWN_AB, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 19, 15, 7, 15, 7, { IID_SHORTBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_AB, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 18, 16, 7, 16, 7, { IID_SHORTBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_AB, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 18, 17, 7, 17, 7, { IID_SHORTBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_AB, JID_NOMADTROOPER, 0, TRUE, FACTION_ID_RED, 8, 16, 19, 16, 19, { IID_SHORTBOW, IID_STEELSWORD, IID_ELIXIR }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_UNKNOWN_AB, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 19, 13, 21, 13, 21, { IID_SHORTBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_AB, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 18, 16, 21, 16, 21, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_AB, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 18, 19, 21, 19, 21, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_AB, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 17, 3, 28, 3, 28, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_AB, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 16, 1, 30, 1, 30, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_AB, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 16, 28, 28, 28, 28, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_AB, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 17, 30, 30, 30, 30, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_AC, JID_WYVERNLORD, 0, TRUE, FACTION_ID_RED, 7, 29, 8, 29, 8, { IID_SILVERLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_AC, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 17, 28, 10, 28, 10, { IID_AXEREAVER }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_AC, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 18, 30, 10, 30, 10, { IID_KILLERLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_AC, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 19, 28, 12, 28, 12, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_AC, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 18, 30, 12, 30, 12, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_AC, JID_WYVERNLORD, 0, TRUE, FACTION_ID_RED, 7, 4, 9, 4, 9, { IID_SILVERLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_AC, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 17, 3, 10, 3, 10, { IID_AXEREAVER }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_AC, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 18, 6, 9, 6, 9, { IID_KILLERLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_AC, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 19, 5, 10, 5, 10, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_AC, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 18, 2, 9, 2, 9, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08683BC0
struct UnitInfo CONST_DATA UnitInfo_Unk_08683BC0[] =
{
    { PID_UNKNOWN_AB, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 18, 6, 4, 6, 4, { IID_ARMORSLAYER }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_AB, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 18, 27, 3, 27, 3, { IID_LANCEREAVER }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_AB, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 18, 12, 11, 12, 11, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_AB, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 18, 17, 11, 17, 11, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08683C10
struct UnitInfo CONST_DATA UnitInfo_Unk_08683C10[] =
{
    { PID_UNKNOWN_AC, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 17, 31, 20, 31, 20, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_AC, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 17, 31, 23, 31, 23, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08683C40
struct UnitInfo CONST_DATA UnitInfo_Unk_08683C40[] =
{
    { PID_UNKNOWN_AB, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 17, 2, 31, 2, 31, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_AB, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 17, 4, 31, 4, 31, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08683C70
struct UnitInfo CONST_DATA UnitInfo_Unk_08683C70[] =
{
    { PID_UNKNOWN_AC, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 17, 31, 20, 31, 20, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_AC, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 17, 31, 23, 31, 23, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_AC, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 17, 31, 22, 31, 22, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_AC, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 17, 31, 21, 31, 21, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08683CC0
struct UnitInfo CONST_DATA UnitInfo_Unk_08683CC0[] =
{
    { PID_UNKNOWN_AB, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 17, 2, 31, 2, 31, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_AB, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 17, 4, 31, 4, 31, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_AB, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 17, 3, 31, 3, 31, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_AB, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 17, 1, 31, 1, 31, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { 0 }, // end
};

// EventScr @ 08683D10
EventScr CONST_DATA EventScr_LoadUnits_Unk_086837F0[] =
{
    EvtLoadUnits(UnitInfo_Unk_086837F0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08683D24
EventScr CONST_DATA EventScr_LoadUnits_Unk_086838F0[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_086838F0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08683D40
EventScr CONST_DATA EventScr_LoadUnits_Unk_08683BC0[] =
{
    EvtLoadUnits(UnitInfo_Unk_08683BC0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08683D54
EventScr CONST_DATA EventScr_LoadUnits_Unk_08683C10[] =
{
    EvtLoadUnits(UnitInfo_Unk_08683C10)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08683D68
EventScr CONST_DATA EventScr_LoadUnits_Unk_08683C40[] =
{
    EvtLoadUnits(UnitInfo_Unk_08683C40)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08683D7C
EventScr CONST_DATA EventScr_LoadUnits_Unk_08683C70[] =
{
    EvtLoadUnits(UnitInfo_Unk_08683C70)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08683D90
EventScr CONST_DATA EventScr_LoadUnits_Unk_08683CC0[] =
{
    EvtLoadUnits(UnitInfo_Unk_08683CC0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 30 summary:
// Units UnitInfo_Unk_086837F0 1
// Units UnitInfo_Unk_086838F0 2
// Units UnitInfo_Unk_08683BC0 1
// Units UnitInfo_Unk_08683C10 1
// Units UnitInfo_Unk_08683C40 1
// Units UnitInfo_Unk_08683C70 1
// Units UnitInfo_Unk_08683CC0 1

// UnitInfo @ 08683DA4
struct UnitInfo CONST_DATA UnitInfo_Unk_08683DA4[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 20, 15, 24, 15, 24, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY, IID_ARMORSLAYER }, { 0 } },
    { PID_MARCUS, JID_PALADIN, PID_ROY, TRUE, FACTION_ID_BLUE, 16, 15, 23, 15, 23, { IID_SILVERLANCE, IID_IRONSWORD, IID_IRONLANCE, IID_HORSESLAYER }, { 0 } },
    { PID_ALEN, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 14, 24, 14, 24, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_KILLERLANCE }, { 0 } },
    { PID_CECILIA, JID_VALKYRIE, PID_ROY, TRUE, FACTION_ID_BLUE, 8, 15, 25, 15, 25, { IID_ELFIRE, IID_THUNDER, IID_HEALSTAFF, IID_VULNERARY }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 18, 13, 23, 13, 23, { IID_IRONLANCE, IID_JAVELIN, IID_CHESTKEY }, { 0 } },
    { PID_WOLT, JID_ARCHER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 16, 23, 16, 23, { IID_IRONBOW, IID_STEELBOW, IID_SILVERBOW, IID_LONGBOW }, { 0 } },
    { PID_DIECK, JID_HERO, PID_ROY, TRUE, FACTION_ID_BLUE, 8, 13, 22, 13, 22, { IID_BRAVEAXE, IID_IRONSWORD, IID_IRONBLADE, IID_STEELSWORD }, { 0 } },
    { PID_WARD, JID_FIGHTER, PID_ROY, TRUE, FACTION_ID_BLUE, 19, 16, 22, 16, 22, { IID_IRONAXE, IID_HANDAXE, IID_SILVERAXE, IID_KILLERAXE }, { 0 } },
    { PID_CHAD, JID_THIEF, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 14, 23, 14, 23, { IID_IRONSWORD, IID_LOCKPICK }, { 0 } },
    { PID_FIR, JID_MYRMIDON_F, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 16, 24, 16, 24, { IID_WODAO, IID_IRONSWORD, IID_LIGHTBRAND }, { 0 } },
    { PID_SUE, JID_NOMAD_F, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 13, 25, 13, 25, { IID_SHORTBOW, IID_IRONBOW, IID_SILVERBOW, IID_VULNERARY }, { 0 } },
    { PID_ZEISS, JID_WYVERNRIDER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 16, 25, 16, 25, { IID_BRAVELANCE, IID_STEELLANCE, IID_JAVELIN, IID_IRONLANCE }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, TRUE, FACTION_ID_BLUE, 1, 14, 25, 14, 25, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_RESTORESTAFF }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 08683E84
struct UnitInfo CONST_DATA UnitInfo_Unk_08683E84[] =
{
    { PID_NIIME, JID_DRUID_F, 0, FALSE, FACTION_ID_BLUE, 18, 13, 24, 13, 24, { IID_FLUX, IID_ECLIPSE, IID_PHYSICSTAFF, IID_HEALSTAFF }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 08683EA4
struct UnitInfo CONST_DATA UnitInfo_Unk_08683EA4[] =
{
    { PID_DAYAN_ALT, JID_NOMADTROOPER, 0, FALSE, FACTION_ID_GREEN, 12, 14, 25, 14, 22, { IID_SHORTBOW, IID_STEELSWORD }, { 0 } },
    { PID_DOUGLAS, JID_GENERAL, 0, FALSE, FACTION_ID_GREEN, 10, 15, 25, 15, 24, { IID_SILVERAXE }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 08683ED4
struct UnitInfo CONST_DATA UnitInfo_Unk_08683ED4[] =
{
    { PID_DAYAN_ALT, JID_NOMADTROOPER, 0, FALSE, FACTION_ID_GREEN, 12, 14, 25, 14, 22, { IID_SHORTBOW, IID_STEELSWORD }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 08683EF4
struct UnitInfo CONST_DATA UnitInfo_Unk_08683EF4[] =
{
    { PID_UNKNOWN_61, JID_GENERAL, 0, FALSE, FACTION_ID_RED, 10, 15, 2, 15, 2, { IID_SPEAR, IID_REDGEM }, { AI_A_03, AI_B_03, 0x00, 0x20 } },
    { PID_UNKNOWN_AD, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 20, 12, 5, 12, 5, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_UNKNOWN_AD, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 20, 15, 5, 15, 5, { IID_AXEREAVER }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_AD, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 20, 18, 5, 18, 5, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_AD, JID_SAGE, 0, TRUE, FACTION_ID_RED, 8, 8, 10, 8, 10, { IID_BOLTING }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_AD, JID_SAGE, 0, TRUE, FACTION_ID_RED, 8, 21, 10, 21, 10, { IID_BOLTING }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_AD, JID_SAGE, 0, TRUE, FACTION_ID_RED, 7, 4, 19, 4, 19, { IID_AIRCALIBUR, IID_PHYSICSTAFF, IID_REDGEM }, { AI_A_0E, AI_B_03, 0x29, 0x00 } },
    { PID_UNKNOWN_AD, JID_SAGE, 0, TRUE, FACTION_ID_RED, 5, 26, 19, 26, 19, { IID_ELFIRE, IID_PHYSICSTAFF, IID_BERSERKSTAFF }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_AD, JID_SAGE, 0, TRUE, FACTION_ID_RED, 4, 15, 7, 15, 7, { IID_AIRCALIBUR }, { AI_A_0E, AI_B_03, 0x29, 0x00 } },
    { PID_UNKNOWN_AD, JID_SAGE, 0, TRUE, FACTION_ID_RED, 2, 15, 9, 15, 9, { IID_ELFIRE }, { AI_A_00, AI_B_03, 0x09, 0x00 } },
    { PID_UNKNOWN_AD, JID_MAGE, 0, TRUE, FACTION_ID_RED, 18, 6, 9, 6, 9, { IID_ELFIRE }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_UNKNOWN_AD, JID_MAGE, 0, TRUE, FACTION_ID_RED, 18, 6, 13, 6, 13, { IID_AIRCALIBUR }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_UNKNOWN_AE, JID_SWORDMASTER, 0, TRUE, FACTION_ID_RED, 8, 7, 5, 7, 5, { IID_SILVERSWORD }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_UNKNOWN_AE, JID_SWORDMASTER, 0, TRUE, FACTION_ID_RED, 8, 21, 5, 21, 5, { IID_WODAO }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_AE, JID_SWORDMASTER, 0, TRUE, FACTION_ID_RED, 8, 4, 14, 4, 14, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_AE, JID_SWORDMASTER, 0, TRUE, FACTION_ID_RED, 8, 22, 15, 22, 15, { IID_STEELSWORD }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_AE, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 17, 20, 15, 20, 15, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_AE, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 17, 5, 7, 5, 7, { IID_LANCEREAVER }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_UNKNOWN_AE, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 17, 25, 7, 25, 7, { IID_KILLINGEDGE }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_UNKNOWN_AD, JID_WARRIOR, 0, TRUE, FACTION_ID_RED, 8, 5, 11, 5, 11, { IID_KILLERAXE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_AD, JID_WARRIOR, 0, TRUE, FACTION_ID_RED, 8, 26, 14, 26, 14, { IID_SILVERAXE }, { AI_A_00, AI_B_09, 0x01, 0x00 } },
    { PID_UNKNOWN_AE, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 16, 6, 15, 6, 15, { IID_STEELSWORD }, { AI_A_00, AI_B_03, 0x09, 0x00 } },
    { PID_UNKNOWN_AE, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 16, 25, 15, 25, 15, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_AD, JID_WARRIOR, 0, TRUE, FACTION_ID_RED, 3, 14, 16, 14, 16, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_AD, JID_WARRIOR, 0, TRUE, FACTION_ID_RED, 3, 15, 16, 15, 16, { IID_SWORDREAVER }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_AD, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 18, 11, 16, 11, 16, { IID_SWORDREAVER }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_AD, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 18, 18, 16, 18, 16, { IID_HALBERD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_AD, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 18, 13, 18, 13, 18, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_AD, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 18, 16, 18, 16, 18, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_AD, JID_SNIPER, 0, TRUE, FACTION_ID_RED, 8, 0, 12, 0, 12, { IID_STEELBOW, IID_ORIONSBOLT }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_AD, JID_SNIPER, 0, TRUE, FACTION_ID_RED, 8, 29, 12, 29, 12, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_AD, JID_SNIPER, 0, TRUE, FACTION_ID_RED, 8, 7, 0, 7, 0, { IID_LONGBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_AD, JID_SNIPER, 0, TRUE, FACTION_ID_RED, 8, 23, 0, 23, 0, { IID_LONGBOW }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08684114
struct UnitInfo CONST_DATA UnitInfo_Unk_08684114[] =
{
    { PID_CATH, JID_THIEF_F, 0, FALSE, FACTION_ID_RED, 5, 15, 8, 15, 9, { IID_IRONSWORD, IID_LOCKPICK, IID_VULNERARY }, { AI_A_06, AI_B_05, 0x1B, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08684134
struct UnitInfo CONST_DATA UnitInfo_Unk_08684134[] =
{
    { PID_UNKNOWN_AF, JID_THIEF, 0, TRUE, FACTION_ID_RED, 20, 15, 8, 15, 8, { IID_IRONSWORD, IID_LOCKPICK }, { AI_A_06, AI_B_05, 0x18, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08684154
struct UnitInfo CONST_DATA UnitInfo_Unk_08684154[] =
{
    { PID_UNKNOWN_BE, JID_NOMADTROOPER, 0, FALSE, FACTION_ID_RED, 8, 14, 25, 14, 23, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x02, 0x20 } },
    { PID_UNKNOWN_BF, JID_DRUID, 0, FALSE, FACTION_ID_RED, 7, 15, 25, 15, 23, { IID_FENRIR }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_C0, JID_NOMADTROOPER, 0, FALSE, FACTION_ID_RED, 8, 15, 25, 15, 24, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_C1, JID_DRUID, 0, FALSE, FACTION_ID_RED, 7, 14, 25, 14, 24, { IID_FENRIR }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// EventScr @ 086841A4
EventScr CONST_DATA EventScr_LoadUnits_Unk_08683DA4[] =
{
    EvtLoadUnits(UnitInfo_Unk_08683DA4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086841B8
EventScr CONST_DATA EventScr_LoadUnits_Unk_08683E84[] =
{
    EvtLoadUnits(UnitInfo_Unk_08683E84)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086841CC
EventScr CONST_DATA EventScr_LoadUnits_Unk_08683EA4[] =
{
    EvtLoadUnits(UnitInfo_Unk_08683EA4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086841E0
EventScr CONST_DATA EventScr_LoadUnits_Unk_08683ED4[] =
{
    EvtLoadUnits(UnitInfo_Unk_08683ED4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086841F4
EventScr CONST_DATA EventScr_LoadUnits_Unk_08683EF4[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_08683EF4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08684210
EventScr CONST_DATA EventScr_LoadUnits_Unk_08684114[] =
{
    EvtLoadUnits(UnitInfo_Unk_08684114)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08684224
EventScr CONST_DATA EventScr_LoadUnits_Unk_08684134[] =
{
    EvtLoadUnits(UnitInfo_Unk_08684134)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08684238
EventScr CONST_DATA EventScr_LoadUnits_Unk_08684154[] =
{
    EvtLoadUnits(UnitInfo_Unk_08684154)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 31 summary:
// Units UnitInfo_Unk_08683DA4 1
// Units UnitInfo_Unk_08683E84 1
// Units UnitInfo_Unk_08683EA4 1
// Units UnitInfo_Unk_08683ED4 1
// Units UnitInfo_Unk_08683EF4 2
// Units UnitInfo_Unk_08684114 1
// Units UnitInfo_Unk_08684134 1
// Units UnitInfo_Unk_08684154 1

// UnitInfo @ 0868424C
struct UnitInfo CONST_DATA UnitInfo_Unk_0868424C[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 5, 23, 23, 23, 23, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY, IID_ARMORSLAYER }, { 0 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 10, 24, 22, 24, 22, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_HORSESLAYER }, { 0 } },
    { PID_ALEN, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 10, 24, 24, 24, 24, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_STEELLANCE }, { 0 } },
    { PID_CLARINE, JID_TROUBADOUR, PID_ROY, TRUE, FACTION_ID_BLUE, 8, 22, 22, 22, 22, { IID_HEALSTAFF, IID_HEALSTAFF, IID_MENDSTAFF, IID_VULNERARY }, { 0 } },
    { PID_RUTGER, JID_MYRMIDON, PID_ROY, TRUE, FACTION_ID_BLUE, 12, 22, 24, 22, 24, { IID_IRONSWORD, IID_KILLINGEDGE, IID_CHESTKEY }, { 0 } },
    { PID_DIECK, JID_MERCENARY, PID_ROY, TRUE, FACTION_ID_BLUE, 11, 25, 23, 25, 23, { IID_IRONSWORD, IID_IRONBLADE }, { 0 } },
    { PID_LUGH, JID_MAGE, PID_ROY, TRUE, FACTION_ID_BLUE, 11, 23, 21, 23, 21, { IID_FIRE, IID_FIRE, IID_THUNDER }, { 0 } },
    { PID_SHANNA, JID_PEGASUSKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 10, 23, 25, 23, 25, { IID_IRONLANCE, IID_JAVELIN, IID_STEELLANCE, IID_SLIMLANCE }, { 0 } },
    { PID_ZELOT, JID_PALADIN, PID_ROY, TRUE, FACTION_ID_BLUE, 11, 21, 25, 21, 25, { IID_IRONLANCE, IID_JAVELIN, IID_STEELLANCE, IID_SLIMLANCE }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, FALSE, FACTION_ID_BLUE, 1, 21, 23, 21, 23, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_FIRE }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 086842FC
struct UnitInfo CONST_DATA UnitInfo_Unk_086842FC[] =
{
    { PID_UNKNOWN_B5, JID_HERO, 0, FALSE, FACTION_ID_RED, 1, 3, 2, 3, 2, { IID_STEELBLADE, IID_HANDAXE }, { AI_A_03, AI_B_03, 0x02, 0x20 } },
    { PID_UNKNOWN_B3, JID_FIGHTER, PID_UNKNOWN_B5, TRUE, FACTION_ID_RED, 10, 0, 2, 0, 2, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_B3, JID_FIGHTER, PID_UNKNOWN_B5, TRUE, FACTION_ID_RED, 10, 6, 2, 6, 2, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_B3, JID_MAGE, PID_UNKNOWN_B5, TRUE, FACTION_ID_RED, 12, 3, 4, 3, 4, { IID_AIRCALIBUR, IID_VULNERARY }, { AI_A_03, AI_B_03, 0x01, 0x20 } },
    { PID_UNKNOWN_B3, JID_FIGHTER, PID_UNKNOWN_B5, TRUE, FACTION_ID_RED, 7, 25, 13, 25, 13, { IID_STEELAXE, IID_HANDAXE, IID_DOORKEY }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_B3, JID_ARCHER, PID_UNKNOWN_B5, TRUE, FACTION_ID_RED, 8, 3, 12, 3, 12, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_B3, JID_MYRMIDON, PID_UNKNOWN_B5, TRUE, FACTION_ID_RED, 8, 6, 12, 6, 12, { IID_ARMORSLAYER }, { AI_A_00, AI_B_03, 0x32, 0x00 } },
    { PID_UNKNOWN_B3, JID_MAGE, PID_UNKNOWN_B5, TRUE, FACTION_ID_RED, 7, 8, 11, 8, 11, { IID_ELFIRE, IID_VULNERARY }, { AI_A_03, AI_B_03, 0x01, 0x20 } },
    { PID_UNKNOWN_B3, JID_ARCHER, PID_UNKNOWN_B5, TRUE, FACTION_ID_RED, 6, 8, 13, 8, 13, { IID_STEELBOW }, { AI_A_03, AI_B_03, 0x2A, 0x00 } },
    { PID_UNKNOWN_B3, JID_MERCENARY, PID_UNKNOWN_B5, TRUE, FACTION_ID_RED, 10, 10, 12, 10, 12, { IID_KILLINGEDGE, IID_VULNERARY }, { AI_A_03, AI_B_03, 0x01, 0x20 } },
    { PID_UNKNOWN_B3, JID_FIGHTER, PID_UNKNOWN_B5, TRUE, FACTION_ID_RED, 6, 13, 11, 13, 11, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_B3, JID_FIGHTER, PID_UNKNOWN_B5, TRUE, FACTION_ID_RED, 6, 15, 11, 15, 11, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_B4, JID_MERCENARY, PID_UNKNOWN_B5, TRUE, FACTION_ID_RED, 10, 14, 2, 14, 2, { IID_STEELSWORD, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x01, 0x20 } },
    { PID_UNKNOWN_B3, JID_FIGHTER, PID_UNKNOWN_B5, TRUE, FACTION_ID_RED, 6, 15, 1, 15, 1, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_B3, JID_FIGHTER, PID_UNKNOWN_B5, TRUE, FACTION_ID_RED, 6, 15, 3, 15, 3, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_B3, JID_MAGE, PID_UNKNOWN_B5, TRUE, FACTION_ID_RED, 8, 14, 9, 14, 9, { IID_ELFIRE, IID_VULNERARY }, { AI_A_03, AI_B_03, 0x01, 0x20 } },
    { PID_UNKNOWN_B4, JID_MERCENARY, PID_UNKNOWN_B5, TRUE, FACTION_ID_RED, 6, 24, 4, 24, 4, { IID_IRONSWORD, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x09, 0x00 } },
    { PID_UNKNOWN_B3, JID_FIGHTER, PID_UNKNOWN_B5, TRUE, FACTION_ID_RED, 5, 19, 1, 19, 1, { IID_IRONAXE, IID_HANDAXE }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_B3, JID_FIGHTER, PID_UNKNOWN_B5, TRUE, FACTION_ID_RED, 5, 20, 3, 20, 3, { IID_IRONAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_B3, JID_FIGHTER, PID_UNKNOWN_B5, TRUE, FACTION_ID_RED, 6, 25, 3, 25, 3, { IID_IRONAXE, IID_HANDAXE }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_B3, JID_MERCENARY, PID_UNKNOWN_B5, TRUE, FACTION_ID_RED, 7, 23, 3, 23, 3, { IID_STEELSWORD }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_B3, JID_MAGE, PID_UNKNOWN_B5, TRUE, FACTION_ID_RED, 6, 24, 8, 24, 8, { IID_THUNDER, IID_VULNERARY }, { AI_A_03, AI_B_03, 0x01, 0x20 } },
    { PID_UNKNOWN_B3, JID_ARCHER, PID_UNKNOWN_B5, TRUE, FACTION_ID_RED, 5, 24, 11, 24, 11, { IID_STEELBOW }, { AI_A_00, AI_B_03, 0x2A, 0x00 } },
    { PID_UNKNOWN_B3, JID_MYRMIDON, PID_UNKNOWN_B5, TRUE, FACTION_ID_RED, 6, 9, 22, 9, 22, { IID_STEELSWORD, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_B3, JID_FIGHTER, PID_UNKNOWN_B5, TRUE, FACTION_ID_RED, 6, 23, 13, 23, 13, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_B3, JID_FIGHTER, PID_UNKNOWN_B5, TRUE, FACTION_ID_RED, 10, 6, 22, 6, 22, { IID_HALBERD }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_B3, JID_FIGHTER, PID_UNKNOWN_B5, TRUE, FACTION_ID_RED, 5, 6, 24, 6, 24, { IID_IRONAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_B3, JID_FIGHTER, PID_UNKNOWN_B5, TRUE, FACTION_ID_RED, 5, 3, 23, 3, 23, { IID_IRONAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_B3, JID_MAGE, PID_UNKNOWN_B5, TRUE, FACTION_ID_RED, 5, 12, 22, 12, 22, { IID_FIRE }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_B4, JID_MERCENARY, PID_UNKNOWN_B5, TRUE, FACTION_ID_RED, 3, 16, 21, 16, 21, { IID_IRONSWORD }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { PID_UNKNOWN_B4, JID_MERCENARY, PID_UNKNOWN_B5, TRUE, FACTION_ID_RED, 3, 16, 23, 16, 23, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x02, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086844FC
struct UnitInfo CONST_DATA UnitInfo_Unk_086844FC[] =
{
    { PID_ROY, JID_ROY, 0, FALSE, FACTION_ID_BLUE, 6, 6, 5, 6, 5, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0868451C
struct UnitInfo CONST_DATA UnitInfo_Unk_0868451C[] =
{
    { PID_NARCIAN, JID_WYVERNLORD, PID_NARCIAN, FALSE, FACTION_ID_RED, 6, 6, 21, 6, 21, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x51, 0x00 } },
    { PID_UNKNOWN_77, JID_WYVERNRIDER, PID_NARCIAN, TRUE, FACTION_ID_RED, 9, 5, 19, 5, 19, { IID_IRONSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_77, JID_WYVERNRIDER, PID_NARCIAN, TRUE, FACTION_ID_RED, 10, 3, 19, 3, 19, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_77, JID_WYVERNRIDER, PID_NARCIAN, TRUE, FACTION_ID_RED, 6, 1, 19, 1, 19, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_UNKNOWN_77, JID_WYVERNRIDER, PID_NARCIAN, TRUE, FACTION_ID_RED, 6, 7, 19, 7, 19, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x51, 0x00 } },
    { PID_UNKNOWN_77, JID_WYVERNRIDER, PID_NARCIAN, TRUE, FACTION_ID_RED, 11, 9, 19, 9, 19, { IID_STEELLANCE, IID_JAVELIN, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_77, JID_WYVERNRIDER, PID_NARCIAN, TRUE, FACTION_ID_RED, 10, 11, 19, 11, 19, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 0868459C
struct UnitInfo CONST_DATA UnitInfo_Unk_0868459C[] =
{
    { PID_PERCEVAL, JID_PALADIN, 0, FALSE, FACTION_ID_GREEN, 6, 6, 25, 6, 21, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 086845BC
struct UnitInfo CONST_DATA UnitInfo_Unk_086845BC[] =
{
    { PID_CECILIA, JID_VALKYRIE, 0, FALSE, FACTION_ID_GREEN, 6, 7, 25, 7, 22, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 086845DC
struct UnitInfo CONST_DATA UnitInfo_Unk_086845DC[] =
{
    { PID_UNKNOWN_77, JID_CAVALIER, 0, FALSE, FACTION_ID_GREEN, 6, 5, 25, 5, 23, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_UNKNOWN_77, JID_CAVALIER, 0, FALSE, FACTION_ID_GREEN, 6, 8, 25, 7, 23, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_UNKNOWN_77, JID_MAGE, 0, FALSE, FACTION_ID_GREEN, 6, 15, 19, 14, 19, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_UNKNOWN_77, JID_MAGE, 0, FALSE, FACTION_ID_GREEN, 6, 0, 19, 2, 19, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0868462C
struct UnitInfo CONST_DATA UnitInfo_Unk_0868462C[] =
{
    { PID_UNKNOWN_77, JID_VALKYRIE, 0, FALSE, FACTION_ID_GREEN, 6, 5, 25, 3, 23, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_UNKNOWN_77, JID_VALKYRIE, 0, FALSE, FACTION_ID_GREEN, 6, 8, 25, 9, 23, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_UNKNOWN_77, JID_MAGE, 0, FALSE, FACTION_ID_GREEN, 6, 0, 22, 2, 22, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_UNKNOWN_77, JID_MAGE, 0, FALSE, FACTION_ID_GREEN, 6, 15, 22, 14, 22, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0868467C
struct UnitInfo CONST_DATA UnitInfo_Unk_0868467C[] =
{
    { PID_UNKNOWN_77, JID_CAVALIER, 0, FALSE, FACTION_ID_GREEN, 6, 5, 25, 4, 23, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_UNKNOWN_77, JID_CAVALIER, 0, FALSE, FACTION_ID_GREEN, 6, 8, 25, 8, 23, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_UNKNOWN_77, JID_MAGE, 0, FALSE, FACTION_ID_GREEN, 6, 0, 19, 1, 19, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_UNKNOWN_77, JID_MAGE, 0, FALSE, FACTION_ID_GREEN, 6, 0, 25, 2, 25, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 086846CC
struct UnitInfo CONST_DATA UnitInfo_Unk_086846CC[] =
{
    { PID_UNKNOWN_77, JID_VALKYRIE, 0, FALSE, FACTION_ID_GREEN, 6, 5, 25, 6, 23, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_UNKNOWN_77, JID_VALKYRIE, 0, FALSE, FACTION_ID_GREEN, 6, 8, 25, 10, 23, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { PID_UNKNOWN_77, JID_MAGE, 0, FALSE, FACTION_ID_GREEN, 6, 0, 18, 1, 18, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0868470C
struct UnitInfo CONST_DATA UnitInfo_Unk_0868470C[] =
{
    { 0 }, // end
};

// UnitInfo @ 0868471C
struct UnitInfo CONST_DATA UnitInfo_Unk_0868471C[] =
{
    { 0 }, // end
};

// EventScr @ 0868472C
EventScr CONST_DATA EventScr_LoadUnits_Unk_0868424C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0868424C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08684740
EventScr CONST_DATA EventScr_LoadUnits_Unk_086842FC[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_086842FC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0868475C
EventScr CONST_DATA EventScr_LoadUnits_Unk_086844FC[] =
{
    EvtLoadUnits(UnitInfo_Unk_086844FC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08684770
EventScr CONST_DATA EventScr_LoadUnits_Unk_0868451C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0868451C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08684784
EventScr CONST_DATA EventScr_LoadUnits_Unk_0868459C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0868459C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08684798
EventScr CONST_DATA EventScr_LoadUnits_Unk_086845BC[] =
{
    EvtLoadUnits(UnitInfo_Unk_086845BC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086847AC
EventScr CONST_DATA EventScr_LoadUnits_Unk_086845DC[] =
{
    EvtLoadUnits(UnitInfo_Unk_086845DC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086847C0
EventScr CONST_DATA EventScr_LoadUnits_Unk_0868462C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0868462C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086847D4
EventScr CONST_DATA EventScr_LoadUnits_Unk_0868467C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0868467C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086847E8
EventScr CONST_DATA EventScr_LoadUnits_Unk_086846CC[] =
{
    EvtLoadUnits(UnitInfo_Unk_086846CC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086847FC
EventScr CONST_DATA EventScr_LoadUnits_Unk_0868470C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0868470C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08684810
EventScr CONST_DATA EventScr_LoadUnits_Unk_0868471C[] =
{
    EvtLoadUnits(UnitInfo_Unk_0868471C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 32 summary:
// Units UnitInfo_Unk_0868424C 1
// Units UnitInfo_Unk_086842FC 2
// Units UnitInfo_Unk_086844FC 1
// Units UnitInfo_Unk_0868451C 1
// Units UnitInfo_Unk_0868459C 1
// Units UnitInfo_Unk_086845BC 1
// Units UnitInfo_Unk_086845DC 1
// Units UnitInfo_Unk_0868462C 1
// Units UnitInfo_Unk_0868467C 1
// Units UnitInfo_Unk_086846CC 1
// Units UnitInfo_Unk_0868470C 1
// Units UnitInfo_Unk_0868471C 1

// UnitInfo @ 08684824
struct UnitInfo CONST_DATA UnitInfo_Unk_08684824[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 6, 4, 24, 4, 24, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY, IID_ARMORSLAYER }, { 0 } },
    { PID_ALEN, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 13, 5, 24, 5, 24, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_SILVERLANCE }, { 0 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 13, 3, 23, 3, 23, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_SILVERLANCE }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 12, 6, 23, 6, 23, { IID_IRONLANCE, IID_JAVELIN, IID_CHESTKEY, IID_SILVERLANCE }, { 0 } },
    { PID_WOLT, JID_ARCHER, PID_ROY, TRUE, FACTION_ID_BLUE, 16, 3, 25, 3, 25, { IID_IRONBOW, IID_STEELBOW, IID_KILLERBOW, IID_LONGBOW }, { 0 } },
    { PID_CLARINE, JID_TROUBADOUR, PID_ROY, TRUE, FACTION_ID_BLUE, 12, 6, 25, 6, 25, { IID_HEALSTAFF, IID_HEALSTAFF, IID_MENDSTAFF, IID_VULNERARY }, { 0 } },
    { PID_CHAD, JID_THIEF, PID_ROY, TRUE, FACTION_ID_BLUE, 10, 4, 22, 4, 22, { IID_IRONSWORD, IID_LOCKPICK }, { 0 } },
    { PID_LUGH, JID_MAGE, PID_ROY, TRUE, FACTION_ID_BLUE, 15, 4, 26, 4, 26, { IID_FIRE, IID_FIRE, IID_THUNDER, IID_ELFIRE }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 086848B4
struct UnitInfo CONST_DATA UnitInfo_Unk_086848B4[] =
{
    { PID_UNKNOWN_B8, JID_BERSERKER, 0, FALSE, FACTION_ID_RED, 2, 25, 1, 25, 1, { IID_SILVERAXE, IID_HANDAXE }, { AI_A_03, AI_B_03, 0x02, 0x20 } },
    { PID_UNKNOWN_B7, JID_THIEF, 0, TRUE, FACTION_ID_RED, 14, 4, 15, 4, 15, { IID_IRONSWORD, IID_LOCKPICK }, { AI_A_06, AI_B_05, 0x1A, 0x00 } },
    { PID_UNKNOWN_B7, JID_THIEF, 0, TRUE, FACTION_ID_RED, 14, 18, 26, 18, 26, { IID_IRONSWORD, IID_LOCKPICK }, { AI_A_06, AI_B_05, 0x1A, 0x00 } },
    { PID_UNKNOWN_B7, JID_THIEF, 0, TRUE, FACTION_ID_RED, 15, 11, 14, 11, 14, { IID_IRONSWORD, IID_LOCKPICK }, { AI_A_06, AI_B_05, 0x1A, 0x00 } },
    { PID_UNKNOWN_B7, JID_DRUID, 0, TRUE, FACTION_ID_RED, 1, 21, 3, 21, 3, { IID_ECLIPSE, IID_PHYSICSTAFF, IID_NOSFERATU }, { AI_A_00, AI_B_03, 0x02, 0x00 } },
    { PID_UNKNOWN_B7, JID_BRIGAND, 0, TRUE, FACTION_ID_RED, 13, 6, 19, 6, 19, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_B7, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 13, 5, 17, 5, 17, { IID_STEELBOW }, { AI_A_00, AI_B_03, 0x2A, 0x00 } },
    { PID_UNKNOWN_B7, JID_BRIGAND, 0, TRUE, FACTION_ID_RED, 14, 3, 13, 3, 13, { IID_POISONAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_B7, JID_BRIGAND, 0, TRUE, FACTION_ID_RED, 14, 4, 8, 4, 8, { IID_POISONAXE, IID_HANDAXE }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_B7, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 13, 1, 4, 1, 4, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_B7, JID_BRIGAND, 0, TRUE, FACTION_ID_RED, 14, 8, 6, 8, 6, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_B7, JID_BRIGAND, 0, TRUE, FACTION_ID_RED, 14, 16, 5, 16, 5, { IID_POISONAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_B7, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 14, 18, 6, 18, 6, { IID_STEELBOW }, { AI_A_00, AI_B_03, 0x2A, 0x00 } },
    { PID_UNKNOWN_B7, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 14, 10, 13, 10, 13, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_B7, JID_BRIGAND, 0, TRUE, FACTION_ID_RED, 14, 12, 16, 12, 16, { IID_HALBERD }, { AI_A_00, AI_B_03, 0x3A, 0x00 } },
    { PID_UNKNOWN_B7, JID_BRIGAND, 0, TRUE, FACTION_ID_RED, 15, 25, 14, 25, 14, { IID_POISONAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_B7, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 15, 14, 21, 14, 21, { IID_FLUX }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_B7, JID_BRIGAND, 0, TRUE, FACTION_ID_RED, 15, 26, 18, 26, 18, { IID_POISONAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_B7, JID_BRIGAND, 0, TRUE, FACTION_ID_RED, 15, 18, 25, 18, 25, { IID_STEELAXE }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_B7, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 15, 24, 23, 24, 23, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_B7, JID_BRIGAND, 0, TRUE, FACTION_ID_RED, 14, 26, 26, 26, 26, { IID_POISONAXE, IID_HANDAXE }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_B7, JID_BRIGAND, 0, TRUE, FACTION_ID_RED, 14, 24, 25, 24, 25, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_B7, JID_BRIGAND, 0, TRUE, FACTION_ID_RED, 14, 13, 22, 13, 22, { IID_HALBERD }, { AI_A_00, AI_B_03, 0x3A, 0x00 } },
    { PID_UNKNOWN_B7, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 15, 17, 0, 17, 0, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_B7, JID_BRIGAND, 0, TRUE, FACTION_ID_RED, 14, 24, 2, 24, 2, { IID_DEVILAXE }, { AI_A_03, AI_B_03, 0x22, 0x00 } },
    { PID_UNKNOWN_B7, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 14, 26, 2, 26, 2, { IID_KILLINGEDGE }, { AI_A_03, AI_B_03, 0x0A, 0x00 } },
    { 0 }, // end
};

// EventScr @ 08684A64
EventScr CONST_DATA EventScr_LoadUnits_Unk_08684824[] =
{
    EvtLoadUnits(UnitInfo_Unk_08684824)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08684A78
EventScr CONST_DATA EventScr_LoadUnits_Unk_086848B4[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_086848B4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 33 summary:
// Units UnitInfo_Unk_08684824 1
// Units UnitInfo_Unk_086848B4 2

// UnitInfo @ 08684A94
struct UnitInfo CONST_DATA UnitInfo_Unk_08684A94[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 6, 4, 2, 4, 2, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY, IID_SILVERSWORD }, { 0 } },
    { PID_WOLT, JID_ARCHER, PID_ROY, TRUE, FACTION_ID_BLUE, 18, 3, 3, 3, 3, { IID_IRONBOW, IID_SHORTBOW, IID_LONGBOW, IID_SILVERBOW }, { 0 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 13, 5, 3, 5, 3, { IID_STEELSWORD, IID_IRONLANCE, IID_JAVELIN, IID_SILVERLANCE }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 13, 3, 1, 3, 1, { IID_IRONLANCE, IID_JAVELIN, IID_SILVERLANCE, IID_CHESTKEY }, { 0 } },
    { PID_GEESE, JID_PIRATE, PID_ROY, TRUE, FACTION_ID_BLUE, 14, 5, 1, 5, 1, { IID_IRONAXE, IID_HANDAXE, IID_SILVERAXE, IID_STEELAXE }, { 0 } },
    { PID_DIECK, JID_MERCENARY, PID_ROY, TRUE, FACTION_ID_BLUE, 19, 2, 2, 2, 2, { IID_IRONSWORD, IID_KILLINGEDGE, IID_IRONBLADE, IID_STEELSWORD }, { 0 } },
    { PID_SHANNA, JID_PEGASUSKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 13, 6, 2, 6, 2, { IID_SLIMLANCE, IID_JAVELIN, IID_SILVERLANCE, IID_VULNERARY }, { 0 } },
    { PID_CLARINE, JID_TROUBADOUR, PID_ROY, TRUE, FACTION_ID_BLUE, 14, 1, 3, 1, 3, { IID_HEALSTAFF, IID_BERSERKSTAFF, IID_RESTORESTAFF, IID_MENDSTAFF }, { 0 } },
    { PID_CHAD, JID_THIEF, PID_ROY, TRUE, FACTION_ID_BLUE, 13, 7, 3, 7, 3, { IID_IRONSWORD, IID_LOCKPICK, IID_VULNERARY }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, TRUE, FACTION_ID_BLUE, 1, 4, 4, 4, 4, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_RESTORESTAFF }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 08684B44
struct UnitInfo CONST_DATA UnitInfo_Unk_08684B44[] =
{
    { PID_UNKNOWN_B9, JID_SAGE, 0, FALSE, FACTION_ID_RED, 10, 13, 12, 13, 12, { IID_ELFIRE, IID_BOLTING }, { AI_A_03, AI_B_03, 0x01, 0x20 } },
    { PID_UNKNOWN_88, JID_BERSERKER, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 9, 9, 9, 9, 9, { IID_DEVILAXE }, { AI_A_00, AI_B_06, 0x21, 0x00 } },
    { PID_UNKNOWN_88, JID_DRUID, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 4, 12, 17, 12, 17, { IID_ECLIPSE, IID_PHYSICSTAFF }, { AI_A_0E, AI_B_06, 0x00, 0x20 } },
    { PID_UNKNOWN_88, JID_DRUID, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 5, 14, 17, 14, 17, { IID_NOSFERATU, IID_MENDSTAFF }, { AI_A_00, AI_B_06 } },
    { PID_UNKNOWN_88, JID_PIRATE, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 16, 2, 21, 2, 23, { IID_POISONAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_88, JID_PIRATE, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 16, 4, 21, 4, 23, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_88, JID_MERCENARY, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 16, 3, 22, 3, 24, { IID_STEELSWORD }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_88, JID_ARCHER, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 16, 3, 23, 3, 25, { IID_STEELBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_88, JID_PIRATE, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 16, 13, 23, 13, 23, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_88, JID_PIRATE, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 16, 13, 25, 13, 25, { IID_POISONAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_88, JID_MERCENARY, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 18, 14, 24, 14, 24, { IID_LANCEREAVER }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_88, JID_ARCHER, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 18, 15, 23, 15, 23, { IID_STEELBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_88, JID_ARCHER, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 18, 15, 25, 15, 25, { IID_LONGBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_88, JID_PIRATE, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 17, 23, 23, 23, 23, { IID_POISONAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_88, JID_PIRATE, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 17, 23, 25, 23, 25, { IID_POISONAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_88, JID_PIRATE, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 17, 25, 24, 25, 24, { IID_SWORDREAVER }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_88, JID_WYVERNRIDER, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 17, 27, 23, 27, 23, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_88, JID_WYVERNRIDER, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 18, 27, 25, 27, 25, { IID_AXEREAVER }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_88, JID_PIRATE, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 18, 21, 8, 21, 8, { IID_POISONAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_88, JID_MERCENARY, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 18, 23, 8, 23, 8, { IID_STEELSWORD }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_88, JID_PIRATE, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 18, 25, 8, 25, 8, { IID_POISONAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_88, JID_WYVERNRIDER, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 16, 22, 6, 22, 6, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_88, JID_WYVERNRIDER, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 16, 24, 6, 24, 6, { IID_AXEREAVER }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_88, JID_PIRATE, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 15, 9, 12, 9, 12, { IID_POISONAXE }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_88, JID_PIRATE, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 16, 8, 13, 8, 13, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_88, JID_MERCENARY, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 17, 9, 14, 9, 14, { IID_STEELSWORD }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_88, JID_ARCHER, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 16, 8, 15, 8, 15, { IID_STEELBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_88, JID_PIRATE, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 17, 11, 9, 11, 9, { IID_POISONAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_88, JID_PIRATE, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 16, 13, 8, 13, 8, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_88, JID_ARCHER, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 17, 15, 9, 15, 9, { IID_STEELBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_88, JID_PRIEST, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 16, 9, 11, 9, 11, { IID_PHYSICSTAFF }, { AI_A_00, AI_B_06, 0x11, 0x00 } },
    { PID_UNKNOWN_88, JID_SAGE, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 3, 13, 14, 13, 14, { IID_BOLTING, IID_ELFIRE, IID_PHYSICSTAFF }, { AI_A_00, AI_B_03, 0x01, 0x20 } },
    { 0 }, // end
};

// EventScr @ 08684D54
EventScr CONST_DATA EventScr_LoadUnits_Unk_08684A94[] =
{
    EvtLoadUnits(UnitInfo_Unk_08684A94)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08684D68
EventScr CONST_DATA EventScr_LoadUnits_Unk_08684B44[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_08684B44)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 34 summary:
// Units UnitInfo_Unk_08684A94 1
// Units UnitInfo_Unk_08684B44 2

// UnitInfo @ 08684D84
struct UnitInfo CONST_DATA UnitInfo_Unk_08684D84[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 15, 15, 29, 15, 29, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY, IID_SILVERSWORD }, { 0 } },
    { PID_MARCUS, JID_PALADIN, PID_ROY, TRUE, FACTION_ID_BLUE, 9, 14, 28, 14, 28, { IID_SILVERLANCE, IID_IRONSWORD, IID_IRONLANCE, IID_HORSESLAYER }, { 0 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 17, 16, 28, 16, 28, { IID_STEELSWORD, IID_IRONLANCE, IID_JAVELIN, IID_SILVERLANCE }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 13, 16, 30, 16, 30, { IID_IRONLANCE, IID_JAVELIN, IID_SILVERLANCE, IID_CHESTKEY }, { 0 } },
    { PID_KLEIN, JID_SNIPER, PID_ROY, TRUE, FACTION_ID_BLUE, 5, 14, 30, 14, 30, { IID_IRONBOW, IID_SILVERBOW, IID_STEELBOW, IID_KILLERBOW }, { 0 } },
    { PID_ECHIDNA, JID_HERO_F, PID_ROY, FALSE, FACTION_ID_BLUE, 4, 15, 27, 15, 27, { IID_BRAVEAXE, IID_IRONSWORD, IID_ARMORSLAYER, IID_STEELSWORD }, { 0 } },
    { PID_SHANNA, JID_PEGASUSKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 17, 15, 31, 15, 31, { IID_SLIMLANCE, IID_JAVELIN, IID_SILVERLANCE, IID_VULNERARY }, { 0 } },
    { PID_CLARINE, JID_TROUBADOUR, PID_ROY, TRUE, FACTION_ID_BLUE, 18, 13, 27, 13, 27, { IID_HEALSTAFF, IID_BERSERKSTAFF, IID_RESTORESTAFF, IID_TORCHSTAFF }, { 0 } },
    { PID_MELADY, JID_WYVERNRIDER_F, PID_ROY, FALSE, FACTION_ID_BLUE, 10, 17, 27, 17, 27, { IID_STEELLANCE, IID_JAVELIN, IID_IRONLANCE, IID_VULNERARY }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, TRUE, FACTION_ID_BLUE, 1, 15, 26, 15, 26, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_RESTORESTAFF }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 08684E34
struct UnitInfo CONST_DATA UnitInfo_Unk_08684E34[] =
{
    { PID_UNKNOWN_C6, JID_BISHOP, 0, FALSE, FACTION_ID_RED, 12, 15, 2, 15, 2, { IID_DIVINE, IID_BERSERKSTAFF }, { AI_A_03, AI_B_03, 0x11, 0x20 } },
    { PID_UNKNOWN_C7, JID_BISHOP, 0, TRUE, FACTION_ID_RED, 6, 5, 0, 5, 0, { IID_PURGE, IID_LIGHTNING, IID_PHYSICSTAFF }, { AI_A_0E, AI_B_03, 0x10, 0x00 } },
    { PID_UNKNOWN_C7, JID_BISHOP, 0, TRUE, FACTION_ID_RED, 6, 25, 0, 25, 0, { IID_PURGE, IID_DIVINE, IID_PHYSICSTAFF }, { AI_A_0E, AI_B_03, 0x10, 0x00 } },
    { PID_UNKNOWN_C7, JID_ARMOR, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 15, 11, 7, 11, 7, { IID_HORSESLAYER }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_C7, JID_ARMOR, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 15, 19, 7, 19, 7, { IID_SILVERLANCE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_C7, JID_SAGE, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 4, 15, 5, 15, 5, { IID_SILENCESTAFF, IID_AIRCALIBUR }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_C7, JID_SAGE, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 5, 15, 13, 15, 13, { IID_BOLTING }, { AI_A_03, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_C7, JID_MAGE, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 12, 5, 11, 5, 11, { IID_AIRCALIBUR }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_C7, JID_MAGE, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 13, 25, 11, 25, 11, { IID_AIRCALIBUR }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_C7, JID_MAGE, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 14, 12, 5, 12, 5, { IID_BOLTING, IID_FIRE }, { AI_A_03, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_C7, JID_MAGE, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 13, 18, 5, 18, 5, { IID_BOLTING, IID_THUNDER }, { AI_A_03, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_C7, JID_MAGE, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 13, 9, 17, 9, 17, { IID_ELFIRE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_C7, JID_MAGE, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 14, 21, 17, 21, 17, { IID_ELFIRE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_C7, JID_PALADIN, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 6, 25, 17, 25, 17, { IID_SILVERLANCE }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_C7, JID_CAVALIER, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 15, 27, 16, 27, 16, { IID_AXEREAVER, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_C7, JID_CAVALIER, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 13, 25, 20, 25, 20, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_C7, JID_CAVALIER, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 13, 27, 20, 27, 20, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_C7, JID_ARCHER, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 13, 3, 22, 3, 22, { IID_STEELBOW }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_C7, JID_ARCHER, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 12, 27, 22, 27, 22, { IID_STEELBOW }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_C7, JID_PALADIN, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 6, 3, 18, 3, 18, { IID_SILVERLANCE }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_C7, JID_CAVALIER, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 15, 5, 17, 5, 17, { IID_AXEREAVER, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_C7, JID_CAVALIER, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 14, 5, 20, 5, 20, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_C7, JID_CAVALIER, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 15, 3, 20, 3, 20, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_C7, JID_SNIPER, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 14, 9, 10, 9, 10, { IID_LONGBOW }, { AI_A_03, AI_B_03, 0x29, 0x00 } },
    { PID_UNKNOWN_C7, JID_SNIPER, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 14, 21, 10, 21, 10, { IID_LONGBOW }, { AI_A_03, AI_B_03, 0x29, 0x00 } },
    { PID_UNKNOWN_C7, JID_MERCENARY, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 12, 9, 23, 9, 23, { IID_STEELSWORD }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_C7, JID_MERCENARY, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 15, 21, 23, 21, 23, { IID_STEELSWORD }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_C7, JID_MERCENARY, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 14, 12, 17, 12, 17, { IID_STEELSWORD, IID_VULNERARY }, { AI_A_03, AI_B_03 } },
    { PID_UNKNOWN_C7, JID_MERCENARY, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 15, 18, 17, 18, 17, { IID_STEELSWORD, IID_VULNERARY }, { AI_A_03, AI_B_03 } },
    { PID_UNKNOWN_C7, JID_ARMOR, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 14, 11, 15, 11, 15, { IID_STEELLANCE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_C7, JID_ARMOR, PID_UNKNOWN_B9, TRUE, FACTION_ID_RED, 14, 19, 15, 19, 15, { IID_STEELLANCE }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08685034
struct UnitInfo CONST_DATA UnitInfo_Unk_08685034[] =
{
    { PID_UNKNOWN_C7, JID_BISHOP, 0, TRUE, FACTION_ID_RED, 8, 5, 0, 5, 0, { IID_LIGHTNING, IID_SILENCESTAFF, IID_PHYSICSTAFF }, { AI_A_0E, AI_B_03, 0x12, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08685054
struct UnitInfo CONST_DATA UnitInfo_Unk_08685054[] =
{
    { PID_UNKNOWN_C7, JID_BISHOP, 0, TRUE, FACTION_ID_RED, 8, 25, 0, 25, 0, { IID_DIVINE, IID_SILENCESTAFF, IID_PHYSICSTAFF }, { AI_A_0E, AI_B_03, 0x12, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08685074
struct UnitInfo CONST_DATA UnitInfo_Unk_08685074[] =
{
    { PID_DOUGLAS, JID_GENERAL, 0, FALSE, FACTION_ID_BLUE, 8, 15, 29, 15, 28, { IID_SILVERAXE, IID_SILVERLANCE }, { 0 } },
    { 0 }, // end
};

// EventScr @ 08685094
EventScr CONST_DATA EventScr_LoadUnits_Unk_08684D84[] =
{
    EvtLoadUnits(UnitInfo_Unk_08684D84)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086850A8
EventScr CONST_DATA EventScr_LoadUnits_Unk_08684E34[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_08684E34)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086850C4
EventScr CONST_DATA EventScr_LoadUnits_Unk_08685034[] =
{
    EvtLoadUnits(UnitInfo_Unk_08685034)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086850D8
EventScr CONST_DATA EventScr_LoadUnits_Unk_08685054[] =
{
    EvtLoadUnits(UnitInfo_Unk_08685054)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086850EC
EventScr CONST_DATA EventScr_LoadUnits_Unk_08685074[] =
{
    EvtLoadUnits(UnitInfo_Unk_08685074)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 35 summary:
// Units UnitInfo_Unk_08684D84 1
// Units UnitInfo_Unk_08684E34 2
// Units UnitInfo_Unk_08685034 1
// Units UnitInfo_Unk_08685054 1
// Units UnitInfo_Unk_08685074 1

// UnitInfo @ 08685100
struct UnitInfo CONST_DATA UnitInfo_Unk_08685100[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 7, 13, 31, 13, 31, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY, IID_ARMORSLAYER }, { 0 } },
    { PID_MARCUS, JID_PALADIN, PID_ROY, TRUE, FACTION_ID_BLUE, 6, 0, 1, 0, 1, { IID_SILVERLANCE, IID_IRONSWORD, IID_IRONLANCE, IID_HORSESLAYER }, { 0 } },
    { PID_ALEN, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 8, 30, 3, 30, 3, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_SILVERLANCE }, { 0 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 5, 15, 31, 15, 31, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_SILVERLANCE }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 10, 0, 3, 0, 3, { IID_IRONLANCE, IID_JAVELIN, IID_CHESTKEY }, { 0 } },
    { PID_RUTGER, JID_MYRMIDON, PID_ROY, TRUE, FACTION_ID_BLUE, 6, 30, 5, 30, 5, { IID_KILLINGEDGE }, { 0 } },
    { PID_ASTOLFO, JID_THIEF, PID_ROY, TRUE, FACTION_ID_BLUE, 10, 12, 30, 12, 30, { IID_LOCKPICK, IID_IRONSWORD }, { 0 } },
    { PID_BARTHE, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 10, 16, 30, 16, 30, { IID_STEELLANCE }, { 0 } },
    { PID_CHAD, JID_THIEF, PID_ROY, TRUE, FACTION_ID_BLUE, 10, 2, 1, 2, 1, { IID_LOCKPICK, IID_IRONSWORD }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, TRUE, FACTION_ID_BLUE, 1, 11, 31, 11, 31, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_RESTORESTAFF }, { 0 } },
    { PID_SHANNA, JID_PEGASUSKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 10, 14, 30, 14, 30, { IID_STEELLANCE, IID_JAVELIN }, { 0 } },
    { PID_JUNO, JID_FALCONKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 10, 30, 1, 30, 1, { IID_SILVERLANCE }, { 0 } },
    { PID_THEA, JID_PEGASUSKNIGHT, PID_ROY, TRUE, FACTION_ID_BLUE, 18, 17, 31, 17, 31, { IID_STEELLANCE, IID_JAVELIN }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 086851E0
struct UnitInfo CONST_DATA UnitInfo_Unk_086851E0[] =
{
    { PID_UNKNOWN_BA, JID_GENERAL, 0, FALSE, FACTION_ID_RED, 12, 16, 1, 16, 1, { IID_SILVERLANCE, IID_SPEAR }, { AI_A_03, AI_B_03, 0x01, 0x20 } },
    { PID_UNKNOWN_BB, JID_DRUID, 0, TRUE, FACTION_ID_RED, 5, 17, 13, 17, 13, { IID_SLEEPSTAFF, IID_PHYSICSTAFF, IID_NOSFERATU }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_BB, JID_DRUID, 0, TRUE, FACTION_ID_RED, 5, 15, 13, 15, 13, { IID_BERSERKSTAFF, IID_PHYSICSTAFF, IID_FLUX }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_BB, JID_SNIPER, 0, TRUE, FACTION_ID_RED, 7, 11, 6, 11, 6, { IID_LONGBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_BB, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 18, 11, 12, 11, 12, { IID_STEELSWORD }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_BB, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 18, 15, 9, 15, 9, { IID_FLUX }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_BB, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 18, 17, 9, 17, 9, { IID_FLUX }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_BB, JID_SNIPER, 0, TRUE, FACTION_ID_RED, 7, 12, 17, 12, 17, { IID_LONGBOW }, { AI_A_03, AI_B_03, 0x29, 0x00 } },
    { PID_UNKNOWN_BB, JID_SWORDMASTER, 0, TRUE, FACTION_ID_RED, 8, 16, 4, 16, 4, { IID_KILLINGEDGE }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_BB, JID_SNIPER, 0, TRUE, FACTION_ID_RED, 7, 21, 17, 21, 17, { IID_LONGBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_BB, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 18, 21, 3, 21, 3, { IID_STEELSWORD }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_BB, JID_SNIPER, 0, TRUE, FACTION_ID_RED, 7, 21, 8, 21, 8, { IID_LONGBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_BB, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 20, 24, 5, 24, 5, { IID_STEELBOW, IID_VULNERARY }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_BB, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 18, 24, 10, 23, 10, { IID_FLUX }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_BB, JID_WARRIOR, 0, TRUE, FACTION_ID_RED, 18, 23, 8, 23, 8, { IID_HAMMER }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_BB, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 19, 24, 21, 24, 21, { IID_STEELBOW, IID_VULNERARY }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_BB, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 18, 19, 22, 19, 22, { IID_FLUX }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_BB, JID_SWORDMASTER, 0, TRUE, FACTION_ID_RED, 7, 9, 17, 9, 17, { IID_BRAVESWORD }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_BB, JID_WARRIOR, 0, TRUE, FACTION_ID_RED, 7, 17, 21, 17, 21, { IID_BRAVEAXE }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_BB, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 19, 13, 22, 13, 22, { IID_STEELBOW, IID_VULNERARY }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_BB, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 16, 8, 19, 8, 19, { IID_FLUX }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_BB, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 19, 9, 14, 9, 14, { IID_STEELBOW, IID_VULNERARY }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_BB, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 16, 8, 4, 8, 4, { IID_FLUX }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_BB, JID_WARRIOR, 0, TRUE, FACTION_ID_RED, 18, 9, 2, 9, 2, { IID_HAMMER }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_BB, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 18, 5, 3, 5, 3, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_BB, JID_WARRIOR, 0, TRUE, FACTION_ID_RED, 6, 5, 9, 5, 9, { IID_SILVERAXE, IID_HANDAXE }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_BB, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 17, 6, 6, 6, 6, { IID_STEELBOW, IID_VULNERARY }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_BB, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 18, 5, 17, 5, 17, { IID_STEELAXE }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_BB, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 17, 6, 21, 6, 21, { IID_STEELBOW, IID_VULNERARY }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_BB, JID_DRUID, 0, TRUE, FACTION_ID_RED, 7, 5, 24, 5, 24, { IID_NOSFERATU, IID_MENDSTAFF }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_BB, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 18, 11, 26, 11, 26, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_BB, JID_WARRIOR, 0, TRUE, FACTION_ID_RED, 18, 10, 25, 10, 25, { IID_HAMMER }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_BB, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 18, 17, 26, 17, 26, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_BB, JID_WARRIOR, 0, TRUE, FACTION_ID_RED, 18, 18, 25, 18, 25, { IID_HAMMER }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_BB, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 19, 26, 26, 26, 26, { IID_POISONAXE, IID_HANDAXE }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_BB, JID_SWORDMASTER, 0, TRUE, FACTION_ID_RED, 7, 24, 24, 24, 25, { IID_LIGHTBRAND }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_BB, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 17, 27, 16, 27, 16, { IID_STEELBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_BB, JID_SNIPER, 0, TRUE, FACTION_ID_RED, 7, 26, 14, 26, 14, { IID_LONGBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_BB, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 18, 27, 12, 27, 12, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_BB, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 18, 27, 3, 27, 3, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { 0 }, // end
};

// EventScr @ 08685470
EventScr CONST_DATA EventScr_LoadUnits_Unk_08685100[] =
{
    EvtLoadUnits(UnitInfo_Unk_08685100)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08685484
EventScr CONST_DATA EventScr_LoadUnits_Unk_086851E0[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_086851E0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 36 summary:
// Units UnitInfo_Unk_08685100 1
// Units UnitInfo_Unk_086851E0 2

// UnitInfo @ 086854A0
struct UnitInfo CONST_DATA UnitInfo_Unk_086854A0[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 7, 25, 2, 25, 2, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY, IID_ARMORSLAYER }, { 0 } },
    { PID_MARCUS, JID_PALADIN, PID_ROY, TRUE, FACTION_ID_BLUE, 6, 0, 1, 0, 1, { IID_SILVERLANCE, IID_IRONSWORD, IID_IRONLANCE, IID_HORSESLAYER }, { 0 } },
    { PID_ALEN, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 8, 23, 26, 23, 26, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_SILVERLANCE }, { 0 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 5, 23, 2, 23, 2, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_SILVERLANCE }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 10, 0, 3, 0, 3, { IID_IRONLANCE, IID_JAVELIN, IID_CHESTKEY }, { 0 } },
    { PID_RUTGER, JID_MYRMIDON, PID_ROY, TRUE, FACTION_ID_BLUE, 6, 25, 4, 25, 4, { IID_KILLINGEDGE }, { 0 } },
    { PID_ASTOLFO, JID_THIEF, PID_ROY, TRUE, FACTION_ID_BLUE, 10, 22, 25, 22, 25, { IID_LOCKPICK, IID_IRONSWORD }, { 0 } },
    { PID_BARTHE, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 15, 1, 2, 1, 2, { IID_STEELLANCE }, { 0 } },
    { PID_CHAD, JID_THIEF, PID_ROY, TRUE, FACTION_ID_BLUE, 10, 25, 0, 25, 0, { IID_LOCKPICK, IID_IRONSWORD }, { 0 } },
    { PID_GWENDOLYN, JID_ARMOR_F, PID_ROY, TRUE, FACTION_ID_BLUE, 6, 22, 27, 22, 27, { IID_STEELLANCE }, { 0 } },
    { PID_CHAD, JID_THIEF, PID_ROY, TRUE, FACTION_ID_BLUE, 10, 1, 0, 1, 0, { IID_IRONSWORD, IID_LOCKPICK }, { 0 } },
    { PID_CECILIA, JID_VALKYRIE, PID_ROY, TRUE, FACTION_ID_BLUE, 6, 24, 27, 24, 27, { IID_MENDSTAFF, IID_ELFIRE }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, TRUE, FACTION_ID_BLUE, 1, 23, 4, 23, 4, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_RESTORESTAFF }, { 0 } },
    { PID_SUE, JID_NOMAD_F, PID_ROY, TRUE, FACTION_ID_BLUE, 6, 27, 0, 27, 0, { IID_SHORTBOW }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 08685590
struct UnitInfo CONST_DATA UnitInfo_Unk_08685590[] =
{
    { PID_UNKNOWN_BE, JID_NOMADTROOPER, 0, FALSE, FACTION_ID_RED, 8, 17, 8, 17, 8, { IID_SHORTBOW, IID_SILVERSWORD }, { AI_A_03, AI_B_03, 0x02, 0x20 } },
    { PID_UNKNOWN_BF, JID_DRUID, 0, FALSE, FACTION_ID_RED, 7, 21, 15, 21, 15, { IID_FENRIR, IID_BERSERKSTAFF }, { AI_A_03, AI_B_03, 0x0A, 0x20 } },
    { PID_UNKNOWN_C0, JID_NOMADTROOPER, 0, FALSE, FACTION_ID_RED, 8, 3, 10, 3, 10, { IID_SHORTBOW, IID_LANCEREAVER }, { AI_A_03, AI_B_03, 0x0A, 0x20 } },
    { PID_UNKNOWN_C1, JID_DRUID, 0, FALSE, FACTION_ID_RED, 7, 8, 14, 8, 14, { IID_FENRIR, IID_SLEEPSTAFF }, { AI_A_03, AI_B_03, 0x0A, 0x20 } },
    { PID_UNKNOWN_C2, JID_NOMADTROOPER, 0, FALSE, FACTION_ID_RED, 8, 3, 24, 3, 24, { IID_SHORTBOW, IID_KILLINGEDGE }, { AI_A_03, AI_B_03, 0x0A, 0x20 } },
    { PID_UNKNOWN_C3, JID_DRUID, 0, FALSE, FACTION_ID_RED, 7, 12, 26, 12, 26, { IID_NOSFERATU, IID_SILENCESTAFF }, { AI_A_03, AI_B_03, 0x0A, 0x20 } },
    { PID_UNKNOWN_BC, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 20, 14, 1, 14, 1, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_BC, JID_NOMADTROOPER, 0, TRUE, FACTION_ID_RED, 7, 11, 1, 11, 1, { IID_SHORTBOW, IID_STEELSWORD }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_BC, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 20, 9, 1, 9, 1, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_BC, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 19, 7, 1, 7, 1, { IID_FLUX, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_BC, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 20, 7, 9, 7, 9, { IID_SHORTBOW, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x2A, 0x00 } },
    { PID_UNKNOWN_BC, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 18, 9, 9, 9, 9, { IID_SHORTBOW }, { AI_A_00, AI_B_03, 0x2A, 0x00 } },
    { PID_UNKNOWN_BC, JID_NOMADTROOPER, 0, TRUE, FACTION_ID_RED, 6, 8, 10, 8, 10, { IID_SHORTBOW, IID_STEELSWORD }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_BC, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 19, 8, 11, 8, 11, { IID_SHORTBOW }, { AI_A_00, AI_B_03, 0x2A, 0x00 } },
    { PID_UNKNOWN_BC, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 20, 1, 13, 1, 13, { IID_SHORTBOW, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_BC, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 18, 3, 13, 3, 13, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_BC, JID_NOMADTROOPER, 0, TRUE, FACTION_ID_RED, 6, 2, 14, 2, 14, { IID_SHORTBOW, IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_BC, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 19, 2, 15, 2, 15, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_BC, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 19, 7, 25, 7, 25, { IID_SHORTBOW, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_BC, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 19, 9, 25, 9, 25, { IID_SHORTBOW }, { AI_A_00, AI_B_03, 0x2A, 0x00 } },
    { PID_UNKNOWN_BC, JID_NOMADTROOPER, 0, TRUE, FACTION_ID_RED, 6, 8, 26, 8, 26, { IID_SHORTBOW, IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_BC, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 19, 2, 19, 2, 19, { IID_SHORTBOW, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_BC, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 19, 4, 19, 4, 19, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x2A, 0x00 } },
    { PID_UNKNOWN_BC, JID_NOMADTROOPER, 0, TRUE, FACTION_ID_RED, 6, 3, 20, 3, 20, { IID_SHORTBOW, IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_BC, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 18, 16, 10, 16, 10, { IID_SHORTBOW, IID_VULNERARY }, { AI_A_00, AI_B_06, 0x2A, 0x00 } },
    { PID_UNKNOWN_BC, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 19, 17, 12, 17, 12, { IID_SHORTBOW }, { AI_A_00, AI_B_06, 0x2A, 0x00 } },
    { PID_UNKNOWN_BC, JID_NOMADTROOPER, 0, TRUE, FACTION_ID_RED, 6, 18, 11, 18, 11, { IID_SHORTBOW, IID_STEELSWORD }, { AI_A_00, AI_B_06, 0x0A, 0x00 } },
    { PID_UNKNOWN_BC, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 19, 19, 10, 19, 10, { IID_SHORTBOW, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x2A, 0x00 } },
    { PID_UNKNOWN_BC, JID_NOMADTROOPER, 0, TRUE, FACTION_ID_RED, 7, 20, 11, 20, 11, { IID_SHORTBOW, IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_BD, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 18, 13, 17, 13, 17, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_06, 0x0A, 0x00 } },
    { PID_UNKNOWN_BD, JID_WYVERNLORD, 0, TRUE, FACTION_ID_RED, 9, 14, 19, 14, 19, { IID_SILVERLANCE }, { AI_A_00, AI_B_06, 0x0A, 0x00 } },
    { PID_UNKNOWN_BD, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 18, 27, 17, 27, 17, { IID_AXEREAVER, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_BD, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 18, 27, 13, 27, 13, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { PID_UNKNOWN_BD, JID_WYVERNLORD, 0, TRUE, FACTION_ID_RED, 9, 27, 15, 27, 15, { IID_SILVERLANCE }, { AI_A_00, AI_B_00, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086857C0
struct UnitInfo CONST_DATA UnitInfo_Unk_086857C0[] =
{
    { PID_UNKNOWN_BC, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 19, 2, 10, 1, 8, { IID_STEELSWORD }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_BC, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 19, 2, 10, 1, 10, { IID_STEELSWORD, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_BC, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 18, 2, 10, 2, 12, { IID_FLUX }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08685800
struct UnitInfo CONST_DATA UnitInfo_Unk_08685800[] =
{
    { PID_UNKNOWN_BC, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 18, 4, 10, 5, 8, { IID_NOSFERATU }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_BC, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 19, 4, 10, 5, 10, { IID_SHORTBOW, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x2A, 0x00 } },
    { PID_UNKNOWN_BC, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 18, 4, 10, 4, 12, { IID_SHORTBOW }, { AI_A_00, AI_B_03, 0x2A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08685840
struct UnitInfo CONST_DATA UnitInfo_Unk_08685840[] =
{
    { PID_UNKNOWN_BC, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 19, 7, 14, 6, 12, { IID_STEELSWORD }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_BC, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 19, 7, 14, 6, 13, { IID_STEELSWORD, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_BC, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 18, 7, 14, 7, 15, { IID_FLUX }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08685880
struct UnitInfo CONST_DATA UnitInfo_Unk_08685880[] =
{
    { PID_UNKNOWN_BC, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 19, 9, 12, 10, 13, { IID_SHORTBOW, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x2A, 0x00 } },
    { PID_UNKNOWN_BC, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 18, 9, 12, 10, 11, { IID_SHORTBOW }, { AI_A_00, AI_B_03, 0x2A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086858B0
struct UnitInfo CONST_DATA UnitInfo_Unk_086858B0[] =
{
    { PID_UNKNOWN_BC, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 19, 2, 24, 1, 22, { IID_STEELSWORD }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_BC, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 19, 2, 24, 1, 24, { IID_STEELSWORD, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_BC, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 18, 2, 24, 2, 26, { IID_FLUX }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086858F0
struct UnitInfo CONST_DATA UnitInfo_Unk_086858F0[] =
{
    { PID_UNKNOWN_BC, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 18, 4, 24, 5, 22, { IID_NOSFERATU }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_BC, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 19, 4, 24, 5, 24, { IID_SHORTBOW, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x2A, 0x00 } },
    { PID_UNKNOWN_BC, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 19, 4, 24, 4, 26, { IID_SHORTBOW }, { AI_A_00, AI_B_03, 0x2A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08685930
struct UnitInfo CONST_DATA UnitInfo_Unk_08685930[] =
{
    { PID_UNKNOWN_BC, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 19, 11, 26, 10, 24, { IID_STEELSWORD }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_BC, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 19, 11, 26, 10, 26, { IID_STEELSWORD, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_BC, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 18, 11, 26, 11, 28, { IID_FLUX }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08685970
struct UnitInfo CONST_DATA UnitInfo_Unk_08685970[] =
{
    { PID_UNKNOWN_BC, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 18, 13, 26, 14, 24, { IID_NOSFERATU }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_BC, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 19, 13, 26, 14, 26, { IID_SHORTBOW, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x2A, 0x00 } },
    { PID_UNKNOWN_BC, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 19, 13, 26, 13, 28, { IID_SHORTBOW }, { AI_A_00, AI_B_03, 0x2A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086859B0
struct UnitInfo CONST_DATA UnitInfo_Unk_086859B0[] =
{
    { PID_UNKNOWN_BC, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 19, 16, 8, 15, 6, { IID_STEELSWORD }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_BC, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 19, 16, 8, 15, 8, { IID_STEELSWORD, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_BC, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 18, 16, 8, 16, 10, { IID_FLUX }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086859F0
struct UnitInfo CONST_DATA UnitInfo_Unk_086859F0[] =
{
    { PID_UNKNOWN_BC, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 18, 20, 8, 19, 6, { IID_NOSFERATU }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_BC, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 19, 18, 7, 19, 8, { IID_SHORTBOW, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x2A, 0x00 } },
    { PID_UNKNOWN_BC, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 19, 20, 7, 18, 10, { IID_SHORTBOW }, { AI_A_00, AI_B_03, 0x2A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08685A30
struct UnitInfo CONST_DATA UnitInfo_Unk_08685A30[] =
{
    { PID_UNKNOWN_BC, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 19, 20, 15, 19, 13, { IID_STEELSWORD }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_BC, JID_MYRMIDON, 0, TRUE, FACTION_ID_RED, 19, 20, 15, 19, 15, { IID_STEELSWORD, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { PID_UNKNOWN_BC, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 18, 20, 15, 20, 17, { IID_FLUX }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08685A70
struct UnitInfo CONST_DATA UnitInfo_Unk_08685A70[] =
{
    { PID_UNKNOWN_BC, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 18, 24, 15, 23, 14, { IID_NOSFERATU }, { AI_A_00, AI_B_03, 0x2A, 0x00 } },
    { PID_UNKNOWN_BC, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 19, 22, 15, 22, 17, { IID_SHORTBOW, IID_VULNERARY }, { AI_A_00, AI_B_03, 0x2A, 0x00 } },
    { 0 }, // end
};

// EventScr @ 08685AA0
EventScr CONST_DATA EventScr_LoadUnits_Unk_086854A0[] =
{
    EvtLoadUnits(UnitInfo_Unk_086854A0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08685AB4
EventScr CONST_DATA EventScr_LoadUnits_Unk_08685590[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_08685590)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08685AD0
EventScr CONST_DATA EventScr_LoadUnits_Unk_086857C0[] =
{
    EvtLoadUnits(UnitInfo_Unk_086857C0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08685AE4
EventScr CONST_DATA EventScr_LoadUnits_Unk_08685800[] =
{
    EvtLoadUnits(UnitInfo_Unk_08685800)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08685AF8
EventScr CONST_DATA EventScr_LoadUnits_Unk_08685840[] =
{
    EvtLoadUnits(UnitInfo_Unk_08685840)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08685B0C
EventScr CONST_DATA EventScr_LoadUnits_Unk_08685880[] =
{
    EvtLoadUnits(UnitInfo_Unk_08685880)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08685B20
EventScr CONST_DATA EventScr_LoadUnits_Unk_086858B0[] =
{
    EvtLoadUnits(UnitInfo_Unk_086858B0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08685B34
EventScr CONST_DATA EventScr_LoadUnits_Unk_086858F0[] =
{
    EvtLoadUnits(UnitInfo_Unk_086858F0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08685B48
EventScr CONST_DATA EventScr_LoadUnits_Unk_08685930[] =
{
    EvtLoadUnits(UnitInfo_Unk_08685930)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08685B5C
EventScr CONST_DATA EventScr_LoadUnits_Unk_08685970[] =
{
    EvtLoadUnits(UnitInfo_Unk_08685970)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08685B70
EventScr CONST_DATA EventScr_LoadUnits_Unk_086859B0[] =
{
    EvtLoadUnits(UnitInfo_Unk_086859B0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08685B84
EventScr CONST_DATA EventScr_LoadUnits_Unk_086859F0[] =
{
    EvtLoadUnits(UnitInfo_Unk_086859F0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08685B98
EventScr CONST_DATA EventScr_LoadUnits_Unk_08685A30[] =
{
    EvtLoadUnits(UnitInfo_Unk_08685A30)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08685BAC
EventScr CONST_DATA EventScr_LoadUnits_Unk_08685A70[] =
{
    EvtLoadUnits(UnitInfo_Unk_08685A70)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 37 summary:
// Units UnitInfo_Unk_086854A0 1
// Units UnitInfo_Unk_08685590 2
// Units UnitInfo_Unk_086857C0 1
// Units UnitInfo_Unk_08685800 1
// Units UnitInfo_Unk_08685840 1
// Units UnitInfo_Unk_08685880 1
// Units UnitInfo_Unk_086858B0 1
// Units UnitInfo_Unk_086858F0 1
// Units UnitInfo_Unk_08685930 1
// Units UnitInfo_Unk_08685970 1
// Units UnitInfo_Unk_086859B0 1
// Units UnitInfo_Unk_086859F0 1
// Units UnitInfo_Unk_08685A30 1
// Units UnitInfo_Unk_08685A70 1

// UnitInfo @ 08685BC0
struct UnitInfo CONST_DATA UnitInfo_Unk_08685BC0[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 7, 15, 27, 15, 27, { IID_RAPIER, IID_IRONSWORD, IID_DOORKEY, IID_ARMORSLAYER }, { 0 } },
    { PID_MARCUS, JID_PALADIN, PID_ROY, TRUE, FACTION_ID_BLUE, 6, 14, 26, 14, 26, { IID_SILVERLANCE, IID_IRONSWORD, IID_IRONLANCE, IID_HORSESLAYER }, { 0 } },
    { PID_ALEN, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 8, 16, 26, 16, 26, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_SILVERLANCE }, { 0 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 5, 14, 27, 14, 27, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_SILVERLANCE }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 10, 16, 27, 16, 27, { IID_IRONLANCE, IID_JAVELIN, IID_CHESTKEY }, { 0 } },
    { PID_RUTGER, JID_MYRMIDON, PID_ROY, TRUE, FACTION_ID_BLUE, 6, 13, 26, 13, 26, { IID_KILLINGEDGE }, { 0 } },
    { PID_ASTOLFO, JID_THIEF, PID_ROY, TRUE, FACTION_ID_BLUE, 10, 17, 26, 17, 26, { IID_LOCKPICK, IID_IRONSWORD }, { 0 } },
    { PID_BARTHE, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 9, 13, 25, 13, 25, { IID_STEELLANCE }, { 0 } },
    { PID_CHAD, JID_THIEF, PID_ROY, TRUE, FACTION_ID_BLUE, 10, 17, 25, 17, 25, { IID_LOCKPICK, IID_IRONSWORD }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, TRUE, FACTION_ID_BLUE, 1, 15, 28, 15, 28, { IID_IRONSWORD, IID_IRONLANCE, IID_JAVELIN, IID_RESTORESTAFF }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 08685C70
struct UnitInfo CONST_DATA UnitInfo_Unk_08685C70[] =
{
    { PID_UNKNOWN_C4, JID_DRUID, 0, FALSE, FACTION_ID_RED, 17, 15, 1, 15, 1, { IID_NOSFERATU }, { AI_A_03, AI_B_03, 0x01, 0x20 } },
    { PID_UNKNOWN_C5, JID_DRUID, 0, TRUE, FACTION_ID_RED, 10, 13, 2, 13, 2, { IID_FENRIR, IID_PHYSICSTAFF }, { AI_A_03, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_C5, JID_DRUID, 0, TRUE, FACTION_ID_RED, 10, 17, 2, 17, 2, { IID_FENRIR, IID_PHYSICSTAFF }, { AI_A_03, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_C5, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 20, 4, 28, 4, 28, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_C5, JID_HERO, 0, TRUE, FACTION_ID_RED, 10, 0, 27, 0, 27, { IID_BRAVESWORD, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_C5, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 20, 4, 26, 4, 26, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_C5, JID_SNIPER, 0, TRUE, FACTION_ID_RED, 8, 2, 27, 2, 27, { IID_SILVERBOW }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_C5, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 19, 0, 20, 0, 20, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_03, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_C5, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 19, 30, 20, 30, 20, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_C5, JID_HERO, 0, TRUE, FACTION_ID_RED, 10, 30, 13, 30, 13, { IID_SILVERSWORD }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_C5, JID_SNIPER, 0, TRUE, FACTION_ID_RED, 7, 29, 13, 29, 13, { IID_STEELBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_C5, JID_HERO, 0, TRUE, FACTION_ID_RED, 10, 0, 13, 0, 13, { IID_SILVERSWORD }, { AI_A_00, AI_B_06, 0x01, 0x00 } },
    { PID_UNKNOWN_C5, JID_SNIPER, 0, TRUE, FACTION_ID_RED, 7, 1, 13, 1, 13, { IID_STEELBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_C5, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 18, 27, 13, 27, 13, { IID_STEELSWORD }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_C5, JID_SNIPER, 0, TRUE, FACTION_ID_RED, 7, 27, 20, 27, 20, { IID_STEELBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_C5, JID_GENERAL, 0, TRUE, FACTION_ID_RED, 12, 26, 19, 26, 19, { IID_SILVERLANCE, IID_HANDAXE }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_C5, JID_SNIPER, 0, TRUE, FACTION_ID_RED, 7, 4, 19, 4, 19, { IID_STEELBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_C5, JID_GENERAL, 0, TRUE, FACTION_ID_RED, 12, 3, 20, 3, 20, { IID_SILVERLANCE, IID_HANDAXE }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_C5, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 19, 26, 26, 26, 26, { IID_LIGHTBRAND }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_C5, JID_HERO, 0, TRUE, FACTION_ID_RED, 10, 30, 27, 30, 27, { IID_SILVERSWORD, IID_VULNERARY }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_C5, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 20, 26, 28, 26, 28, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_C5, JID_SNIPER, 0, TRUE, FACTION_ID_RED, 8, 28, 27, 28, 27, { IID_SILVERBOW }, { AI_A_00, AI_B_00, 0x01, 0x00 } },
    { PID_UNKNOWN_C5, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 18, 3, 14, 3, 14, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_C5, JID_SNIPER, 0, TRUE, FACTION_ID_RED, 7, 3, 17, 3, 17, { IID_STEELBOW }, { AI_A_00, AI_B_03, 0x29, 0x00 } },
    { PID_UNKNOWN_C5, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 19, 24, 9, 24, 9, { IID_AXEREAVER, IID_JAVELIN }, { AI_A_00, AI_B_03, 0x09, 0x00 } },
    { PID_UNKNOWN_C5, JID_GENERAL, 0, TRUE, FACTION_ID_RED, 12, 29, 6, 29, 6, { IID_HORSESLAYER, IID_HANDAXE }, { AI_A_03, AI_B_03, 0x29, 0x00 } },
    { PID_UNKNOWN_C5, JID_ARMOR, 0, TRUE, FACTION_ID_RED, 19, 23, 9, 23, 9, { IID_AXEREAVER, IID_JAVELIN }, { AI_A_00, AI_B_03, 0x09, 0x00 } },
    { PID_UNKNOWN_C5, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 19, 6, 9, 6, 9, { IID_STEELSWORD }, { AI_A_00, AI_B_03, 0x09, 0x00 } },
    { PID_UNKNOWN_C5, JID_HERO, 0, TRUE, FACTION_ID_RED, 12, 2, 6, 2, 6, { IID_ARMORSLAYER }, { AI_A_03, AI_B_03, 0x29, 0x00 } },
    { PID_UNKNOWN_C5, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 18, 6, 19, 6, 19, { IID_NOSFERATU }, { AI_A_03, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_C5, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 19, 23, 19, 23, 19, { IID_FENRIR }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_C5, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 18, 5, 5, 5, 5, { IID_NOSFERATU }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_C5, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 19, 29, 5, 29, 5, { IID_FENRIR }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_C5, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 20, 27, 2, 27, 2, { IID_LANCEREAVER }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_C5, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 20, 7, 9, 7, 9, { IID_LANCEREAVER }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_C5, JID_DRUID, 0, TRUE, FACTION_ID_RED, 6, 11, 11, 11, 11, { IID_NOSFERATU }, { AI_A_00, AI_B_00, 0x29, 0x00 } },
    { PID_UNKNOWN_C5, JID_GENERAL, 0, TRUE, FACTION_ID_RED, 10, 20, 2, 20, 2, { IID_SILVERLANCE, IID_HANDAXE }, { AI_A_03, AI_B_03, 0x29, 0x00 } },
    { PID_UNKNOWN_C5, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 10, 10, 2, 10, 2, { IID_DEVILAXE, IID_HANDAXE }, { AI_A_03, AI_B_03, 0x29, 0x00 } },
    { PID_UNKNOWN_C5, JID_DRUID, 0, TRUE, FACTION_ID_RED, 10, 20, 9, 20, 9, { IID_FENRIR }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_C5, JID_SHAMAN, 0, TRUE, FACTION_ID_RED, 19, 19, 6, 19, 6, { IID_FLUX }, { AI_A_00, AI_B_03, 0x09, 0x00 } },
    { PID_UNKNOWN_C5, JID_SNIPER, 0, TRUE, FACTION_ID_RED, 10, 10, 9, 10, 9, { IID_KILLERBOW }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_C5, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 19, 11, 6, 11, 6, { IID_STEELBOW }, { AI_A_00, AI_B_03, 0x09, 0x00 } },
    { PID_UNKNOWN_C5, JID_SNIPER, 0, TRUE, FACTION_ID_RED, 6, 19, 11, 19, 11, { IID_STEELBOW }, { AI_A_00, AI_B_06, 0x29, 0x00 } },
    { PID_UNKNOWN_C5, JID_HERO, 0, TRUE, FACTION_ID_RED, 10, 15, 6, 15, 6, { IID_BRAVESWORD }, { AI_A_00, AI_B_03, 0x01, 0x00 } },
    { PID_UNKNOWN_C5, JID_DRUID, 0, TRUE, FACTION_ID_RED, 8, 15, 10, 15, 10, { IID_SILENCESTAFF, IID_FENRIR, IID_PHYSICSTAFF }, { AI_A_03, AI_B_03, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08685F50
struct UnitInfo CONST_DATA UnitInfo_Unk_08685F50[] =
{
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 12, 3, 1, 3, 0, { IID_FIRESTONE }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08685F70
struct UnitInfo CONST_DATA UnitInfo_Unk_08685F70[] =
{
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 12, 6, 1, 6, 0, { IID_FIRESTONE }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08685F90
struct UnitInfo CONST_DATA UnitInfo_Unk_08685F90[] =
{
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 12, 14, 12, 14, 11, { IID_FIRESTONE }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08685FB0
struct UnitInfo CONST_DATA UnitInfo_Unk_08685FB0[] =
{
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 12, 16, 12, 16, 11, { IID_FIRESTONE }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08685FD0
struct UnitInfo CONST_DATA UnitInfo_Unk_08685FD0[] =
{
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 12, 25, 1, 25, 0, { IID_FIRESTONE }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08685FF0
struct UnitInfo CONST_DATA UnitInfo_Unk_08685FF0[] =
{
    { PID_COMMON_MANAKETE, JID_MANAKETE, 0, TRUE, FACTION_ID_RED, 12, 29, 1, 29, 0, { IID_FIRESTONE }, { AI_A_00, AI_B_03, 0x0A, 0x00 } },
    { 0 }, // end
};

// EventScr @ 08686010
EventScr CONST_DATA EventScr_LoadUnits_Unk_08685BC0[] =
{
    EvtLoadUnits(UnitInfo_Unk_08685BC0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08686024
EventScr CONST_DATA EventScr_LoadUnits_Unk_08685C70[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_08685C70)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08686040
EventScr CONST_DATA EventScr_LoadUnits_Unk_08685F50[] =
{
    EvtLoadUnits(UnitInfo_Unk_08685F50)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08686054
EventScr CONST_DATA EventScr_LoadUnits_Unk_08685F70[] =
{
    EvtLoadUnits(UnitInfo_Unk_08685F70)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08686068
EventScr CONST_DATA EventScr_LoadUnits_Unk_08685F90[] =
{
    EvtLoadUnits(UnitInfo_Unk_08685F90)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0868607C
EventScr CONST_DATA EventScr_LoadUnits_Unk_08685FB0[] =
{
    EvtLoadUnits(UnitInfo_Unk_08685FB0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08686090
EventScr CONST_DATA EventScr_LoadUnits_Unk_08685FD0[] =
{
    EvtLoadUnits(UnitInfo_Unk_08685FD0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086860A4
EventScr CONST_DATA EventScr_LoadUnits_Unk_08685FF0[] =
{
    EvtLoadUnits(UnitInfo_Unk_08685FF0)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 38 summary:
// Units UnitInfo_Unk_08685BC0 1
// Units UnitInfo_Unk_08685C70 2
// Units UnitInfo_Unk_08685F50 1
// Units UnitInfo_Unk_08685F70 1
// Units UnitInfo_Unk_08685F90 1
// Units UnitInfo_Unk_08685FB0 1
// Units UnitInfo_Unk_08685FD0 1
// Units UnitInfo_Unk_08685FF0 1

// UnitInfo @ 086860B8
struct UnitInfo CONST_DATA UnitInfo_Unk_086860B8[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 20, 25, 4, 25, 4, { IID_RAPIER, IID_IRONSWORD, IID_VULNERARY }, { 0 } },
    { PID_MARCUS, JID_PALADIN, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 24, 5, 24, 5, { IID_IRONLANCE }, { 0 } },
    { PID_ALEN, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 26, 5, 26, 5, { IID_IRONSWORD, IID_IRONLANCE, IID_VULNERARY }, { 0 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 24, 3, 24, 3, { IID_IRONSWORD, IID_JAVELIN, IID_VULNERARY, IID_IRONLANCE }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 26, 3, 26, 3, { IID_SILVERLANCE, IID_IRONLANCE, IID_IRONLANCE }, { 0 } },
    { PID_WOLT, JID_ARCHER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 27, 4, 27, 4, { IID_IRONBOW, IID_IRONBOW }, { 0 } },
    { PID_DIECK, JID_MERCENARY, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 23, 4, 23, 4, { IID_IRONSWORD, IID_IRONBLADE, IID_ARMORSLAYER }, { 0 } },
    { PID_WARD, JID_FIGHTER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 23, 6, 23, 6, { IID_HANDAXE, IID_IRONAXE, IID_HAMMER, IID_VULNERARY }, { 0 } },
    { PID_LOT, JID_FIGHTER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 22, 5, 22, 5, { IID_IRONAXE, IID_STEELAXE }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 25, 6, 25, 6, { 0 }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 08686168
struct UnitInfo CONST_DATA UnitInfo_Unk_08686168[] =
{
    { PID_UNKNOWN_DB, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 15, 2, 3, 2, 3, { IID_KILLERAXE, IID_HANDAXE }, { AI_A_03, AI_B_03, 0x09, 0x20 } },
    { PID_UNKNOWN_73, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 10, 21, 14, 21, 14, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 10, 23, 14, 23, 14, { IID_STEELAXE }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 10, 22, 13, 22, 13, { IID_STEELAXE }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_SWORDMASTER, 0, TRUE, FACTION_ID_RED, 10, 12, 8, 12, 8, { IID_WODAO }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 12, 13, 6, 13, 6, { IID_SILVERAXE, IID_HANDAXE }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 12, 11, 6, 11, 6, { IID_SILVERAXE, IID_ELIXIR }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 12, 6, 7, 6, 7, { IID_SILVERAXE }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 12, 6, 9, 6, 9, { IID_SILVERAXE, IID_ELIXIR }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_SWORDMASTER, 0, TRUE, FACTION_ID_RED, 10, 7, 8, 7, 8, { IID_WODAO }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 12, 2, 12, 2, 12, { IID_SILVERAXE, IID_HANDAXE }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 12, 4, 12, 4, 12, { IID_SILVERAXE, IID_ELIXIR }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_SWORDMASTER, 0, TRUE, FACTION_ID_RED, 10, 3, 13, 3, 13, { IID_WODAO }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 12, 4, 14, 4, 14, { IID_SILVERAXE, IID_HANDAXE }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 12, 2, 14, 2, 14, { IID_SILVERAXE, IID_HANDAXE }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 12, 1, 5, 1, 5, { IID_SILVERAXE, IID_ELIXIR }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 12, 3, 5, 3, 5, { IID_SILVERAXE }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_SWORDMASTER, 0, TRUE, FACTION_ID_RED, 12, 2, 6, 2, 6, { IID_WODAO }, { AI_A_00, AI_B_06, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_SWORDMASTER, 0, TRUE, FACTION_ID_RED, 10, 0, 0, 0, 0, { IID_SILVERSWORD }, { AI_A_00, AI_B_03, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_SWORDMASTER, 0, TRUE, FACTION_ID_RED, 10, 4, 0, 4, 0, { IID_SILVERSWORD }, { AI_A_00, AI_B_03, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 10, 15, 4, 15, 4, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 10, 13, 9, 13, 9, { IID_STEELAXE, IID_ELIXIR }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 10, 8, 8, 8, 8, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 10, 8, 12, 8, 12, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 10, 0, 14, 0, 14, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 10, 1, 15, 1, 15, { IID_STEELAXE, IID_ELIXIR }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08686318
struct UnitInfo CONST_DATA UnitInfo_Unk_08686318[] =
{
    { PID_UNKNOWN_73, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 15, 0, 13, 1, 13, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 10, 0, 12, 1, 12, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 10, 0, 11, 1, 11, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08686358
struct UnitInfo CONST_DATA UnitInfo_Unk_08686358[] =
{
    { PID_UNKNOWN_73, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 15, 4, 0, 5, 2, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 10, 4, 0, 4, 2, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 10, 4, 0, 4, 1, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08686398
struct UnitInfo CONST_DATA UnitInfo_Unk_08686398[] =
{
    { PID_UNKNOWN_73, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 15, 27, 15, 26, 15, { IID_KILLERAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 10, 27, 14, 26, 14, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 10, 27, 13, 26, 13, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086863D8
struct UnitInfo CONST_DATA UnitInfo_Unk_086863D8[] =
{
    { PID_UNKNOWN_73, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 15, 27, 0, 26, 0, { IID_KILLERAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 10, 27, 1, 26, 1, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_73, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 10, 27, 2, 26, 2, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// EventScr @ 08686418
EventScr CONST_DATA EventScr_LoadUnits_Unk_086860B8[] =
{
    EvtLoadUnits(UnitInfo_Unk_086860B8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0868642C
EventScr CONST_DATA EventScr_LoadUnits_Unk_08686168[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_08686168)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08686448
EventScr CONST_DATA EventScr_LoadUnits_Unk_08686318[] =
{
    EvtLoadUnits(UnitInfo_Unk_08686318)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0868645C
EventScr CONST_DATA EventScr_LoadUnits_Unk_08686358[] =
{
    EvtLoadUnits(UnitInfo_Unk_08686358)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08686470
EventScr CONST_DATA EventScr_LoadUnits_Unk_08686398[] =
{
    EvtLoadUnits(UnitInfo_Unk_08686398)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08686484
EventScr CONST_DATA EventScr_LoadUnits_Unk_086863D8[] =
{
    EvtLoadUnits(UnitInfo_Unk_086863D8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 39 summary:
// Units UnitInfo_Unk_086860B8 1
// Units UnitInfo_Unk_08686168 2
// Units UnitInfo_Unk_08686318 1
// Units UnitInfo_Unk_08686358 1
// Units UnitInfo_Unk_08686398 1
// Units UnitInfo_Unk_086863D8 1

// UnitInfo @ 08686498
struct UnitInfo CONST_DATA UnitInfo_Unk_08686498[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 20, 12, 14, 12, 14, { IID_RAPIER, IID_IRONSWORD, IID_VULNERARY }, { 0 } },
    { PID_MARCUS, JID_PALADIN, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 14, 14, 14, 14, { IID_IRONLANCE }, { 0 } },
    { PID_ALEN, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 13, 15, 13, 15, { IID_IRONSWORD, IID_IRONLANCE, IID_VULNERARY }, { 0 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 11, 15, 11, 15, { IID_IRONSWORD, IID_JAVELIN, IID_VULNERARY, IID_IRONLANCE }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 12, 16, 12, 16, { IID_SILVERLANCE, IID_IRONLANCE, IID_IRONLANCE }, { 0 } },
    { PID_WOLT, JID_ARCHER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 11, 13, 11, 13, { IID_IRONBOW, IID_IRONBOW }, { 0 } },
    { PID_DIECK, JID_MERCENARY, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 14, 16, 14, 16, { IID_IRONSWORD, IID_IRONBLADE, IID_ARMORSLAYER }, { 0 } },
    { PID_WARD, JID_FIGHTER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 10, 14, 10, 14, { IID_HANDAXE, IID_IRONAXE, IID_HAMMER, IID_VULNERARY }, { 0 } },
    { PID_LOT, JID_FIGHTER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 13, 13, 13, 13, { IID_IRONAXE, IID_STEELAXE }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 12, 12, 12, 12, { 0 }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 08686548
struct UnitInfo CONST_DATA UnitInfo_Unk_08686548[] =
{
    { PID_UNKNOWN_7A, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 20, 20, 4, 20, 4, { IID_SILVERSWORD }, { AI_A_00, AI_B_00, 0x2C, 0x00 } },
    { PID_UNKNOWN_7A, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 20, 21, 8, 21, 8, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_7A, JID_MAGE, 0, TRUE, FACTION_ID_RED, 20, 23, 13, 23, 13, { IID_ELFIRE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_7A, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 20, 23, 18, 23, 18, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_7A, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 20, 20, 20, 20, 20, { IID_SILVERLANCE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_7A, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 20, 17, 10, 17, 10, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_7A, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 20, 16, 21, 16, 21, { IID_SILVERAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_7A, JID_MAGE, 0, TRUE, FACTION_ID_RED, 20, 13, 29, 13, 29, { IID_AIRCALIBUR }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_7A, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 20, 13, 5, 13, 5, { IID_SILVERBOW }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_7A, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 20, 11, 8, 11, 8, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_7A, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 20, 10, 19, 10, 19, { IID_LIGHTBRAND }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_7A, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 20, 8, 10, 8, 10, { IID_KILLERAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_7A, JID_MAGE, 0, TRUE, FACTION_ID_RED, 20, 7, 14, 7, 14, { IID_BOLTING, IID_FIRE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_7A, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 20, 6, 3, 6, 3, { IID_LONGBOW }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_7A, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 20, 3, 18, 3, 18, { IID_SPEAR }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_7A, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 20, 1, 26, 1, 26, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_7A, JID_HERO, 0, TRUE, FACTION_ID_RED, 10, 9, 23, 9, 23, { IID_LIGHTBRAND }, { AI_A_00, AI_B_00, 0x2C, 0x00 } },
    { PID_UNKNOWN_7A, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 10, 26, 16, 26, 16, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x2C, 0x00 } },
    { PID_UNKNOWN_7A, JID_SNIPER, 0, TRUE, FACTION_ID_RED, 10, 17, 1, 17, 1, { IID_SILVERBOW }, { AI_A_00, AI_B_00, 0x2C, 0x00 } },
    { PID_UNKNOWN_7A, JID_DRUID, 0, TRUE, FACTION_ID_RED, 10, 1, 14, 1, 14, { IID_FLUX, IID_SLEEPSTAFF }, { AI_A_00, AI_B_00, 0x2C, 0x00 } },
    { PID_UNKNOWN_7A, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 20, 27, 5, 27, 5, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086866A8
struct UnitInfo CONST_DATA UnitInfo_Unk_086866A8[] =
{
    { PID_UNKNOWN_7A, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 20, 20, 4, 20, 4, { IID_SILVERSWORD }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086866C8
struct UnitInfo CONST_DATA UnitInfo_Unk_086866C8[] =
{
    { PID_UNKNOWN_7A, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 20, 21, 8, 21, 8, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086866E8
struct UnitInfo CONST_DATA UnitInfo_Unk_086866E8[] =
{
    { PID_UNKNOWN_7A, JID_MAGE, 0, TRUE, FACTION_ID_RED, 20, 23, 13, 23, 13, { IID_ELFIRE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08686708
struct UnitInfo CONST_DATA UnitInfo_Unk_08686708[] =
{
    { PID_UNKNOWN_7A, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 20, 23, 18, 23, 18, { IID_STEELBOW }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08686728
struct UnitInfo CONST_DATA UnitInfo_Unk_08686728[] =
{
    { PID_UNKNOWN_7A, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 20, 20, 20, 20, 20, { IID_SILVERLANCE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08686748
struct UnitInfo CONST_DATA UnitInfo_Unk_08686748[] =
{
    { PID_UNKNOWN_7A, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 20, 17, 10, 17, 10, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08686768
struct UnitInfo CONST_DATA UnitInfo_Unk_08686768[] =
{
    { PID_UNKNOWN_7A, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 20, 16, 21, 16, 21, { IID_SILVERAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08686788
struct UnitInfo CONST_DATA UnitInfo_Unk_08686788[] =
{
    { PID_UNKNOWN_7A, JID_MAGE, 0, TRUE, FACTION_ID_RED, 20, 13, 29, 13, 29, { IID_AIRCALIBUR }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086867A8
struct UnitInfo CONST_DATA UnitInfo_Unk_086867A8[] =
{
    { PID_UNKNOWN_7A, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 20, 13, 5, 13, 5, { IID_SILVERBOW }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086867C8
struct UnitInfo CONST_DATA UnitInfo_Unk_086867C8[] =
{
    { PID_UNKNOWN_7A, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 20, 11, 8, 11, 8, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086867E8
struct UnitInfo CONST_DATA UnitInfo_Unk_086867E8[] =
{
    { PID_UNKNOWN_7A, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 20, 10, 19, 10, 19, { IID_LIGHTBRAND }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08686808
struct UnitInfo CONST_DATA UnitInfo_Unk_08686808[] =
{
    { PID_UNKNOWN_7A, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 20, 8, 10, 8, 10, { IID_KILLERAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08686828
struct UnitInfo CONST_DATA UnitInfo_Unk_08686828[] =
{
    { PID_UNKNOWN_7A, JID_MAGE, 0, TRUE, FACTION_ID_RED, 20, 7, 14, 7, 14, { IID_BOLTING }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08686848
struct UnitInfo CONST_DATA UnitInfo_Unk_08686848[] =
{
    { PID_UNKNOWN_7A, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 20, 6, 3, 6, 3, { IID_LONGBOW }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08686868
struct UnitInfo CONST_DATA UnitInfo_Unk_08686868[] =
{
    { PID_UNKNOWN_7A, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 20, 3, 18, 3, 18, { IID_SPEAR }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08686888
struct UnitInfo CONST_DATA UnitInfo_Unk_08686888[] =
{
    { PID_UNKNOWN_7A, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 20, 1, 25, 1, 25, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086868A8
struct UnitInfo CONST_DATA UnitInfo_Unk_086868A8[] =
{
    { PID_UNKNOWN_7A, JID_NOMAD, 0, TRUE, FACTION_ID_RED, 20, 27, 5, 27, 5, { IID_SHORTBOW }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { 0 }, // end
};

// EventScr @ 086868C8
EventScr CONST_DATA EventScr_LoadUnits_Unk_08686498[] =
{
    EvtLoadUnits(UnitInfo_Unk_08686498)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086868DC
EventScr CONST_DATA EventScr_LoadUnits_Unk_08686548[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_08686548)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086868F8
EventScr CONST_DATA EventScr_LoadUnits_Unk_086866A8[] =
{
    EvtLoadUnits(UnitInfo_Unk_086866A8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0868690C
EventScr CONST_DATA EventScr_LoadUnits_Unk_086866C8[] =
{
    EvtLoadUnits(UnitInfo_Unk_086866C8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08686920
EventScr CONST_DATA EventScr_LoadUnits_Unk_086866E8[] =
{
    EvtLoadUnits(UnitInfo_Unk_086866E8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08686934
EventScr CONST_DATA EventScr_LoadUnits_Unk_08686708[] =
{
    EvtLoadUnits(UnitInfo_Unk_08686708)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08686948
EventScr CONST_DATA EventScr_LoadUnits_Unk_08686728[] =
{
    EvtLoadUnits(UnitInfo_Unk_08686728)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0868695C
EventScr CONST_DATA EventScr_LoadUnits_Unk_08686748[] =
{
    EvtLoadUnits(UnitInfo_Unk_08686748)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08686970
EventScr CONST_DATA EventScr_LoadUnits_Unk_08686768[] =
{
    EvtLoadUnits(UnitInfo_Unk_08686768)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08686984
EventScr CONST_DATA EventScr_LoadUnits_Unk_08686788[] =
{
    EvtLoadUnits(UnitInfo_Unk_08686788)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08686998
EventScr CONST_DATA EventScr_LoadUnits_Unk_086867A8[] =
{
    EvtLoadUnits(UnitInfo_Unk_086867A8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086869AC
EventScr CONST_DATA EventScr_LoadUnits_Unk_086867C8[] =
{
    EvtLoadUnits(UnitInfo_Unk_086867C8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086869C0
EventScr CONST_DATA EventScr_LoadUnits_Unk_086867E8[] =
{
    EvtLoadUnits(UnitInfo_Unk_086867E8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086869D4
EventScr CONST_DATA EventScr_LoadUnits_Unk_08686808[] =
{
    EvtLoadUnits(UnitInfo_Unk_08686808)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086869E8
EventScr CONST_DATA EventScr_LoadUnits_Unk_08686828[] =
{
    EvtLoadUnits(UnitInfo_Unk_08686828)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086869FC
EventScr CONST_DATA EventScr_LoadUnits_Unk_08686848[] =
{
    EvtLoadUnits(UnitInfo_Unk_08686848)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08686A10
EventScr CONST_DATA EventScr_LoadUnits_Unk_08686868[] =
{
    EvtLoadUnits(UnitInfo_Unk_08686868)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08686A24
EventScr CONST_DATA EventScr_LoadUnits_Unk_08686888[] =
{
    EvtLoadUnits(UnitInfo_Unk_08686888)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08686A38
EventScr CONST_DATA EventScr_LoadUnits_Unk_086868A8[] =
{
    EvtLoadUnits(UnitInfo_Unk_086868A8)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 40 summary:
// Units UnitInfo_Unk_08686498 1
// Units UnitInfo_Unk_08686548 2
// Units UnitInfo_Unk_086866A8 1
// Units UnitInfo_Unk_086866C8 1
// Units UnitInfo_Unk_086866E8 1
// Units UnitInfo_Unk_08686708 1
// Units UnitInfo_Unk_08686728 1
// Units UnitInfo_Unk_08686748 1
// Units UnitInfo_Unk_08686768 1
// Units UnitInfo_Unk_08686788 1
// Units UnitInfo_Unk_086867A8 1
// Units UnitInfo_Unk_086867C8 1
// Units UnitInfo_Unk_086867E8 1
// Units UnitInfo_Unk_08686808 1
// Units UnitInfo_Unk_08686828 1
// Units UnitInfo_Unk_08686848 1
// Units UnitInfo_Unk_08686868 1
// Units UnitInfo_Unk_08686888 1
// Units UnitInfo_Unk_086868A8 1

// UnitInfo @ 08686A4C
struct UnitInfo CONST_DATA UnitInfo_Unk_08686A4C[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 20, 10, 14, 10, 14, { IID_RAPIER, IID_IRONSWORD, IID_VULNERARY }, { 0 } },
    { PID_MARCUS, JID_PALADIN, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 9, 15, 9, 15, { IID_IRONLANCE }, { 0 } },
    { PID_ALEN, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 11, 15, 11, 15, { IID_IRONSWORD, IID_IRONLANCE, IID_VULNERARY }, { 0 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 7, 13, 7, 13, { IID_IRONSWORD, IID_JAVELIN, IID_VULNERARY, IID_IRONLANCE }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 13, 13, 13, 13, { IID_SILVERLANCE, IID_IRONLANCE, IID_IRONLANCE }, { 0 } },
    { PID_WOLT, JID_ARCHER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 12, 12, 12, 12, { IID_IRONBOW, IID_IRONBOW }, { 0 } },
    { PID_DIECK, JID_MERCENARY, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 8, 12, 8, 12, { IID_IRONSWORD, IID_IRONBLADE, IID_ARMORSLAYER }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 10, 11, 10, 11, { IID_HANDAXE, IID_IRONAXE, IID_HAMMER, IID_VULNERARY }, { 0 } },
    { PID_WOLT, JID_ARCHER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 11, 8, 11, 8, { IID_STEELBOW }, { 0 } },
    { PID_IGRENE, JID_SNIPER_F, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 7, 18, 7, 18, { IID_SILVERBOW }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 08686AFC
struct UnitInfo CONST_DATA UnitInfo_Unk_08686AFC[] =
{
    { PID_UNKNOWN_9A, JID_SNIPER, 0, TRUE, FACTION_ID_RED, 10, 16, 15, 16, 15, { IID_STEELBOW }, { AI_A_00, AI_B_03, 0x2C, 0x20 } },
    { PID_UNKNOWN_9A, JID_SNIPER, 0, TRUE, FACTION_ID_RED, 10, 8, 22, 8, 22, { IID_STEELBOW }, { AI_A_00, AI_B_03, 0x2C, 0x20 } },
    { PID_UNKNOWN_9A, JID_SNIPER, 0, TRUE, FACTION_ID_RED, 10, 3, 23, 3, 23, { IID_STEELBOW }, { AI_A_00, AI_B_03, 0x2C, 0x20 } },
    { PID_UNKNOWN_9A, JID_PALADIN, 0, TRUE, FACTION_ID_RED, 12, 2, 4, 2, 4, { IID_SILVERLANCE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 17, 1, 6, 1, 6, { IID_KILLERLANCE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 17, 3, 6, 3, 6, { IID_AXEREAVER }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 17, 1, 5, 1, 5, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 17, 3, 5, 3, 5, { IID_SPEAR }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_TROUBADOUR, 0, TRUE, FACTION_ID_RED, 17, 2, 3, 2, 3, { IID_RECOVERSTAFF }, { AI_A_0E, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_PALADIN, 0, TRUE, FACTION_ID_RED, 12, 25, 13, 25, 13, { IID_SILVERLANCE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 17, 23, 12, 23, 12, { IID_HORSESLAYER }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 17, 23, 14, 23, 14, { IID_AXEREAVER }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 17, 24, 12, 24, 12, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 17, 24, 14, 24, 14, { IID_SPEAR }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_TROUBADOUR, 0, TRUE, FACTION_ID_RED, 17, 26, 13, 26, 13, { IID_RECOVERSTAFF }, { AI_A_0E, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_FALCONKNIGHT, 0, TRUE, FACTION_ID_RED, 12, 15, 30, 15, 30, { IID_SILVERLANCE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 17, 14, 29, 14, 29, { IID_STEELLANCE }, { AI_A_03, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 17, 16, 29, 16, 29, { IID_AXEREAVER }, { AI_A_00, AI_B_18, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 17, 16, 31, 16, 31, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_18, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 17, 14, 31, 14, 31, { IID_SPEAR }, { AI_A_00, AI_B_18, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_FALCONKNIGHT, 0, TRUE, FACTION_ID_RED, 12, 24, 2, 24, 2, { IID_SILVERLANCE }, { AI_A_00, AI_B_18, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 17, 23, 1, 23, 1, { IID_KILLERLANCE }, { AI_A_03, AI_B_18, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 17, 23, 3, 23, 3, { IID_AXEREAVER }, { AI_A_00, AI_B_18, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 17, 25, 1, 25, 1, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_18, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 17, 25, 3, 25, 3, { IID_SPEAR }, { AI_A_00, AI_B_18, 0x0C, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08686C9C
struct UnitInfo CONST_DATA UnitInfo_Unk_08686C9C[] =
{
    { PID_UNKNOWN_9A, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 20, 28, 26, 26, 26, { IID_AXEREAVER }, { AI_A_00, AI_B_18, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 20, 28, 26, 24, 26, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_18, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 20, 28, 29, 25, 27, { IID_SPEAR }, { AI_A_00, AI_B_18, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_PALADIN, 0, TRUE, FACTION_ID_RED, 15, 28, 29, 25, 28, { IID_SILVERLANCE }, { AI_A_00, AI_B_18, 0x0C, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08686CEC
struct UnitInfo CONST_DATA UnitInfo_Unk_08686CEC[] =
{
    { PID_UNKNOWN_9A, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 20, 17, 0, 15, 2, { IID_AXEREAVER }, { AI_A_00, AI_B_18, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 20, 17, 0, 17, 2, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_18, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_CAVALIER, 0, TRUE, FACTION_ID_RED, 20, 15, 0, 16, 1, { IID_SPEAR }, { AI_A_00, AI_B_18, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_PALADIN, 0, TRUE, FACTION_ID_RED, 15, 15, 0, 16, 0, { IID_SILVERLANCE }, { AI_A_00, AI_B_18, 0x0C, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08686D3C
struct UnitInfo CONST_DATA UnitInfo_Unk_08686D3C[] =
{
    { PID_UNKNOWN_9A, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 20, 4, 27, 4, 27, { IID_STEELAXE }, { AI_A_00, AI_B_18, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 20, 2, 28, 2, 28, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_18, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 20, 24, 30, 24, 30, { IID_KILLERAXE }, { AI_A_00, AI_B_18, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 20, 21, 30, 21, 30, { IID_SILVERAXE }, { AI_A_00, AI_B_18, 0x0C, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08686D8C
struct UnitInfo CONST_DATA UnitInfo_Unk_08686D8C[] =
{
    { PID_UNKNOWN_9A, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 20, 2, 3, 2, 3, { IID_STEELAXE }, { AI_A_00, AI_B_18, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 20, 4, 1, 4, 1, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_18, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 20, 26, 4, 26, 4, { IID_HALBERD }, { AI_A_00, AI_B_18, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 20, 19, 8, 19, 8, { IID_SILVERAXE }, { AI_A_00, AI_B_18, 0x0C, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08686DDC
struct UnitInfo CONST_DATA UnitInfo_Unk_08686DDC[] =
{
    { PID_UNKNOWN_9A, JID_FALCONKNIGHT, 0, TRUE, FACTION_ID_RED, 15, 31, 3, 27, 4, { IID_AXEREAVER }, { AI_A_00, AI_B_18, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 20, 31, 3, 25, 4, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_18, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 20, 31, 5, 24, 3, { IID_SPEAR }, { AI_A_00, AI_B_18, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 20, 31, 5, 24, 5, { IID_SILVERLANCE }, { AI_A_00, AI_B_18, 0x0C, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08686E2C
struct UnitInfo CONST_DATA UnitInfo_Unk_08686E2C[] =
{
    { PID_UNKNOWN_9A, JID_FALCONKNIGHT, 0, TRUE, FACTION_ID_RED, 15, 4, 31, 5, 31, { IID_AXEREAVER }, { AI_A_00, AI_B_18, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 20, 4, 31, 5, 30, { IID_STEELLANCE, IID_JAVELIN }, { AI_A_00, AI_B_18, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 20, 6, 31, 4, 29, { IID_SPEAR }, { AI_A_00, AI_B_18, 0x0C, 0x00 } },
    { PID_UNKNOWN_9A, JID_PEGASUSKNIGHT, 0, TRUE, FACTION_ID_RED, 20, 6, 31, 6, 29, { IID_SILVERLANCE }, { AI_A_00, AI_B_18, 0x0C, 0x00 } },
    { 0 }, // end
};

// EventScr @ 08686E7C
EventScr CONST_DATA EventScr_LoadUnits_Unk_08686A4C[] =
{
    EvtLoadUnits(UnitInfo_Unk_08686A4C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08686E90
EventScr CONST_DATA EventScr_LoadUnits_Unk_08686AFC[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_08686AFC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08686EAC
EventScr CONST_DATA EventScr_LoadUnits_Unk_08686C9C[] =
{
    EvtLoadUnits(UnitInfo_Unk_08686C9C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08686EC0
EventScr CONST_DATA EventScr_LoadUnits_Unk_08686CEC[] =
{
    EvtLoadUnits(UnitInfo_Unk_08686CEC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08686ED4
EventScr CONST_DATA EventScr_LoadUnits_Unk_08686D3C[] =
{
    EvtLoadUnits(UnitInfo_Unk_08686D3C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08686EE8
EventScr CONST_DATA EventScr_LoadUnits_Unk_08686D8C[] =
{
    EvtLoadUnits(UnitInfo_Unk_08686D8C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08686EFC
EventScr CONST_DATA EventScr_LoadUnits_Unk_08686DDC[] =
{
    EvtLoadUnits(UnitInfo_Unk_08686DDC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08686F10
EventScr CONST_DATA EventScr_LoadUnits_Unk_08686E2C[] =
{
    EvtLoadUnits(UnitInfo_Unk_08686E2C)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 41 summary:
// Units UnitInfo_Unk_08686A4C 1
// Units UnitInfo_Unk_08686AFC 2
// Units UnitInfo_Unk_08686C9C 1
// Units UnitInfo_Unk_08686CEC 1
// Units UnitInfo_Unk_08686D3C 1
// Units UnitInfo_Unk_08686D8C 1
// Units UnitInfo_Unk_08686DDC 1
// Units UnitInfo_Unk_08686E2C 1

// UnitInfo @ 08686F24
struct UnitInfo CONST_DATA UnitInfo_Unk_08686F24[] =
{
    { PID_ROY, JID_ROY, 0, TRUE, FACTION_ID_BLUE, 20, 17, 15, 17, 15, { IID_RAPIER, IID_IRONSWORD, IID_VULNERARY }, { 0 } },
    { PID_MARCUS, JID_PALADIN, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 16, 16, 16, 16, { IID_IRONLANCE }, { 0 } },
    { PID_ALEN, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 18, 16, 18, 16, { IID_IRONSWORD, IID_IRONLANCE, IID_VULNERARY }, { 0 } },
    { PID_LANCE, JID_CAVALIER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 18, 14, 18, 14, { IID_IRONSWORD, IID_JAVELIN, IID_VULNERARY, IID_IRONLANCE }, { 0 } },
    { PID_BORS, JID_ARMOR, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 14, 15, 14, 15, { IID_SILVERLANCE, IID_IRONLANCE, IID_IRONLANCE }, { 0 } },
    { PID_WOLT, JID_ARCHER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 14, 13, 14, 13, { IID_IRONBOW, IID_IRONBOW }, { 0 } },
    { PID_DIECK, JID_MERCENARY, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 17, 13, 17, 13, { IID_IRONSWORD, IID_IRONBLADE, IID_ARMORSLAYER }, { 0 } },
    { PID_WARD, JID_FIGHTER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 19, 13, 19, 13, { IID_HANDAXE, IID_IRONAXE, IID_HAMMER, IID_VULNERARY }, { 0 } },
    { PID_LOT, JID_FIGHTER, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 19, 15, 19, 15, { IID_IRONAXE, IID_STEELAXE }, { 0 } },
    { PID_MERLINUS, JID_SUPPLY, PID_ROY, TRUE, FACTION_ID_BLUE, 20, 17, 17, 17, 17, { 0 }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 08686FD4
struct UnitInfo CONST_DATA UnitInfo_Unk_08686FD4[] =
{
    { PID_UNKNOWN_A5, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 10, 7, 2, 7, 2, { IID_KILLERAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_PIRATE, 0, TRUE, FACTION_ID_RED, 15, 10, 6, 10, 6, { IID_POISONAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 18, 28, 2, 28, 2, { IID_SPEAR }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_PIRATE, 0, TRUE, FACTION_ID_RED, 16, 27, 21, 27, 21, { IID_POISONAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_PIRATE, 0, TRUE, FACTION_ID_RED, 15, 26, 23, 26, 23, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_SAGE, 0, TRUE, FACTION_ID_RED, 15, 22, 17, 22, 17, { IID_ELFIRE, IID_MENDSTAFF }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 10, 14, 2, 14, 2, { IID_SILVERAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_PIRATE, 0, TRUE, FACTION_ID_RED, 15, 17, 2, 17, 2, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 18, 28, 12, 28, 12, { IID_HORSESLAYER, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 18, 4, 6, 4, 6, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_PIRATE, 0, TRUE, FACTION_ID_RED, 16, 15, 26, 15, 26, { IID_POISONAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_PIRATE, 0, TRUE, FACTION_ID_RED, 17, 17, 26, 17, 26, { IID_POISONAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_DRUID, 0, TRUE, FACTION_ID_RED, 15, 10, 18, 10, 18, { IID_NOSFERATU, IID_PHYSICSTAFF }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_PIRATE, 0, TRUE, FACTION_ID_RED, 17, 23, 5, 23, 5, { IID_POISONAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_PIRATE, 0, TRUE, FACTION_ID_RED, 17, 23, 7, 23, 7, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_PIRATE, 0, TRUE, FACTION_ID_RED, 15, 22, 28, 22, 28, { IID_POISONAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 15, 6, 25, 6, 25, { IID_KILLERLANCE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_WYVERNLORD, 0, TRUE, FACTION_ID_RED, 7, 9, 28, 9, 28, { IID_SILVERLANCE, IID_SPEAR }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_SNIPER, 0, TRUE, FACTION_ID_RED, 15, 19, 20, 19, 20, { IID_LONGBOW }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 10, 14, 19, 14, 19, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 11, 19, 10, 19, 10, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 10, 20, 12, 20, 12, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 11, 12, 17, 12, 17, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 10, 14, 10, 14, 10, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 15, 15, 18, 15, 18, { IID_KILLERBOW }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_ARCHER, 0, TRUE, FACTION_ID_RED, 14, 21, 15, 21, 15, { IID_LONGBOW }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08687184
struct UnitInfo CONST_DATA UnitInfo_Unk_08687184[] =
{
    { PID_UNKNOWN_A5, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 10, 7, 2, 7, 2, { IID_KILLERAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_PIRATE, 0, TRUE, FACTION_ID_RED, 15, 10, 6, 10, 6, { IID_POISONAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 18, 28, 2, 28, 2, { IID_SPEAR }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_PIRATE, 0, TRUE, FACTION_ID_RED, 16, 27, 21, 27, 21, { IID_POISONAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_PIRATE, 0, TRUE, FACTION_ID_RED, 15, 26, 23, 26, 23, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_SAGE, 0, TRUE, FACTION_ID_RED, 15, 22, 17, 22, 17, { IID_ELFIRE, IID_MENDSTAFF }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 18, 4, 6, 4, 6, { IID_STEELLANCE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08687204
struct UnitInfo CONST_DATA UnitInfo_Unk_08687204[] =
{
    { PID_UNKNOWN_A5, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 10, 14, 2, 14, 2, { IID_SILVERAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_PIRATE, 0, TRUE, FACTION_ID_RED, 15, 17, 2, 17, 2, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 18, 28, 12, 28, 12, { IID_HORSESLAYER, IID_JAVELIN }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_PIRATE, 0, TRUE, FACTION_ID_RED, 16, 15, 26, 15, 26, { IID_POISONAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_PIRATE, 0, TRUE, FACTION_ID_RED, 17, 17, 26, 17, 26, { IID_POISONAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_DRUID, 0, TRUE, FACTION_ID_RED, 15, 10, 18, 10, 18, { IID_NOSFERATU, IID_PHYSICSTAFF }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08687274
struct UnitInfo CONST_DATA UnitInfo_Unk_08687274[] =
{
    { PID_UNKNOWN_A5, JID_PIRATE, 0, TRUE, FACTION_ID_RED, 17, 23, 5, 23, 5, { IID_POISONAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_PIRATE, 0, TRUE, FACTION_ID_RED, 17, 23, 7, 23, 7, { IID_STEELAXE, IID_HANDAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_PIRATE, 0, TRUE, FACTION_ID_RED, 15, 22, 28, 22, 28, { IID_POISONAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_WYVERNRIDER, 0, TRUE, FACTION_ID_RED, 15, 6, 25, 6, 25, { IID_KILLERLANCE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_WYVERNLORD, 0, TRUE, FACTION_ID_RED, 7, 9, 28, 9, 28, { IID_SILVERLANCE, IID_SPEAR }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { PID_UNKNOWN_A5, JID_SNIPER, 0, TRUE, FACTION_ID_RED, 15, 19, 20, 19, 20, { IID_LONGBOW }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086872E4
struct UnitInfo CONST_DATA UnitInfo_Unk_086872E4[] =
{
    { PID_UNKNOWN_DA, JID_BERSERKER, 0, TRUE, FACTION_ID_RED, 20, 1, 14, 3, 16, { IID_SILVERAXE }, { AI_A_00, AI_B_00, 0x0C, 0x00 } },
    { 0 }, // end
};

// EventScr @ 08687304
EventScr CONST_DATA EventScr_LoadUnits_Unk_08686F24[] =
{
    EvtLoadUnits(UnitInfo_Unk_08686F24)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08687318
EventScr CONST_DATA EventScr_LoadUnits_Unk_08686FD4[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_Unk_08686FD4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08687334
EventScr CONST_DATA EventScr_LoadUnits_Unk_08687184[] =
{
    EvtLoadUnits(UnitInfo_Unk_08687184)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08687348
EventScr CONST_DATA EventScr_LoadUnits_Unk_08687204[] =
{
    EvtLoadUnits(UnitInfo_Unk_08687204)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0868735C
EventScr CONST_DATA EventScr_LoadUnits_Unk_08687274[] =
{
    EvtLoadUnits(UnitInfo_Unk_08687274)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08687370
EventScr CONST_DATA EventScr_LoadUnits_Unk_086872E4[] =
{
    EvtLoadUnits(UnitInfo_Unk_086872E4)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 42 summary:
// Units UnitInfo_Unk_08686F24 1
// Units UnitInfo_Unk_08686FD4 2
// Units UnitInfo_Unk_08687184 1
// Units UnitInfo_Unk_08687204 1
// Units UnitInfo_Unk_08687274 1
// Units UnitInfo_Unk_086872E4 1

// UnitInfo @ 08687384
struct UnitInfo CONST_DATA UnitInfo_TrialE_Deploy[] =
{
    { PID_ROY, 0, 0, FALSE, FACTION_ID_BLUE, 1, 16, 14, 16, 14, { IID_RAPIER, IID_VULNERARY }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 086873A4
struct UnitInfo CONST_DATA UnitInfo_TrialE_Red[] =
{
    { PID_UNKNOWN_89, JID_WARRIOR, 0, TRUE, FACTION_ID_RED, 10, 13, 10, 13, 10, { IID_SILVERAXE, IID_STEELBOW }, { AI_A_03, AI_B_03, 0x09, 0x20 } },
    { PID_UNKNOWN_89, JID_WARRIOR, 0, TRUE, FACTION_ID_RED, 10, 20, 10, 20, 10, { IID_KILLERAXE, IID_STEELBOW }, { AI_A_03, AI_B_03, 0x09, 0x20 } },
    { PID_UNKNOWN_89, JID_WARRIOR, 0, TRUE, FACTION_ID_RED, 10, 21, 16, 21, 16, { IID_HALBERD, IID_STEELBOW }, { AI_A_03, AI_B_03, 0x09, 0x20 } },
    { PID_UNKNOWN_89, JID_WARRIOR, 0, TRUE, FACTION_ID_RED, 10, 17, 20, 17, 20, { IID_SILVERBOW, IID_STEELAXE }, { AI_A_03, AI_B_03, 0x09, 0x20 } },
    { PID_UNKNOWN_89, JID_WARRIOR, 0, TRUE, FACTION_ID_RED, 10, 12, 18, 12, 18, { IID_KILLERBOW, IID_STEELAXE }, { AI_A_03, AI_B_03, 0x09, 0x20 } },
    { PID_UNKNOWN_89, JID_WARRIOR, 0, TRUE, FACTION_ID_RED, 10, 10, 14, 10, 14, { IID_LONGBOW, IID_STEELAXE }, { AI_A_03, AI_B_03, 0x09, 0x20 } },
    { PID_UNKNOWN_89, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 18, 4, 1, 4, 1, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_89, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 18, 0, 5, 0, 5, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_89, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 18, 2, 21, 2, 21, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_89, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 18, 4, 26, 4, 26, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_89, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 18, 1, 30, 1, 30, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_89, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 18, 10, 30, 10, 30, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_89, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 18, 18, 25, 18, 25, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_89, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 18, 29, 26, 29, 26, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_89, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 18, 31, 13, 31, 13, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_89, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 18, 30, 5, 30, 5, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_89, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 18, 27, 1, 27, 1, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_89, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 18, 21, 1, 21, 1, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_89, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 18, 8, 0, 8, 0, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_89, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 18, 2, 16, 2, 16, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_89, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 18, 3, 10, 3, 10, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_89, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 12, 13, 13, 13, 13, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_89, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 12, 21, 13, 21, 13, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_89, JID_MERCENARY, 0, TRUE, FACTION_ID_RED, 12, 18, 11, 18, 11, { IID_STEELSWORD }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { PID_UNKNOWN_89, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 12, 15, 18, 15, 18, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08687544
struct UnitInfo CONST_DATA UnitInfo_TrialE_Turn10Extra[] =
{
    { PID_UNKNOWN_89, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 15, 13, 10, 13, 10, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08687564
struct UnitInfo CONST_DATA UnitInfo_TrialE_Turn12Extra[] =
{
    { PID_UNKNOWN_89, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 15, 20, 10, 20, 10, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 08687584
struct UnitInfo CONST_DATA UnitInfo_TrialE_Turn14Extra[] =
{
    { PID_UNKNOWN_89, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 15, 21, 16, 21, 16, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086875A4
struct UnitInfo CONST_DATA UnitInfo_TrialE_Turn16Extra[] =
{
    { PID_UNKNOWN_89, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 15, 17, 20, 17, 20, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086875C4
struct UnitInfo CONST_DATA UnitInfo_TrialE_Turn18Extra[] =
{
    { PID_UNKNOWN_89, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 15, 12, 18, 12, 18, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// UnitInfo @ 086875E4
struct UnitInfo CONST_DATA UnitInfo_TrialE_Turn20Extra[] =
{
    { PID_UNKNOWN_89, JID_FIGHTER, 0, TRUE, FACTION_ID_RED, 15, 10, 14, 10, 14, { IID_STEELAXE }, { AI_A_00, AI_B_00, 0x09, 0x00 } },
    { 0 }, // end
};

// EventScr @ 08687604
EventScr CONST_DATA EventScr_LoadUnits_TrialE_Deploy[] =
{
    EvtLoadUnits(UnitInfo_TrialE_Deploy)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08687618
EventScr CONST_DATA EventScr_LoadUnits_TrialE_Red[] =
{
    EvtUnitCameraOff
    EvtNoSkip
    EvtLoadUnits(UnitInfo_TrialE_Red)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08687634
EventScr CONST_DATA EventScr_LoadUnits_TrialE_Turn10Extra[] =
{
    EvtLoadUnits(UnitInfo_TrialE_Turn10Extra)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08687648
EventScr CONST_DATA EventScr_LoadUnits_TrialE_Turn12Extra[] =
{
    EvtLoadUnits(UnitInfo_TrialE_Turn12Extra)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 0868765C
EventScr CONST_DATA EventScr_LoadUnits_TrialE_Turn14Extra[] =
{
    EvtLoadUnits(UnitInfo_TrialE_Turn14Extra)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08687670
EventScr CONST_DATA EventScr_LoadUnits_TrialE_Turn16Extra[] =
{
    EvtLoadUnits(UnitInfo_TrialE_Turn16Extra)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08687684
EventScr CONST_DATA EventScr_LoadUnits_TrialE_Turn18Extra[] =
{
    EvtLoadUnits(UnitInfo_TrialE_Turn18Extra)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08687698
EventScr CONST_DATA EventScr_LoadUnits_TrialE_Turn20Extra[] =
{
    EvtLoadUnits(UnitInfo_TrialE_Turn20Extra)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 43 summary:
// Units UnitInfo_TrialE_Deploy 1
// Units UnitInfo_TrialE_Red 2
// Units UnitInfo_TrialE_Turn10Extra 1
// Units UnitInfo_TrialE_Turn12Extra 1
// Units UnitInfo_TrialE_Turn14Extra 1
// Units UnitInfo_TrialE_Turn16Extra 1
// Units UnitInfo_TrialE_Turn18Extra 1
// Units UnitInfo_TrialE_Turn20Extra 1

// UnitInfo @ 086876AC
struct UnitInfo CONST_DATA UnitInfo_TrialBonusUnitA[] =
{
    { PID_NARCIAN, 0, 0, FALSE, FACTION_ID_BLUE, 10, 0, 0, 0, 0, { IID_RUNESWORD, IID_DELPHISHIELD }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 086876CC
struct UnitInfo CONST_DATA UnitInfo_TrialBonusUnitB[] =
{
    { PID_GALLE, 0, 0, FALSE, FACTION_ID_BLUE, 18, 0, 0, 0, 0, { IID_KILLERLANCE, IID_LIGHTBRAND }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 086876EC
struct UnitInfo CONST_DATA UnitInfo_TrialBonusUnitC[] =
{
    { PID_HECTOR, 0, 0, FALSE, FACTION_ID_BLUE, 20, 0, 0, 0, 0, { IID_BRAVEAXE, IID_SILVERLANCE }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0868770C
struct UnitInfo CONST_DATA UnitInfo_TrialBonusUnitD[] =
{
    { PID_BRUNNYA, 0, 0, FALSE, FACTION_ID_BLUE, 20, 0, 0, 0, 0, { IID_FIMBULVETR, IID_BOLTING, IID_FORTIFYSTAFF }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0868772C
struct UnitInfo CONST_DATA UnitInfo_TrialBonusUnitE[] =
{
    { PID_ELIWOOD, 0, 0, FALSE, FACTION_ID_BLUE, 20, 0, 0, 0, 0, { IID_SILVERLANCE, IID_SILVERSWORD }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0868774C
struct UnitInfo CONST_DATA UnitInfo_TrialBonusUnitF[] =
{
    { PID_MURDOCK, 0, 0, FALSE, FACTION_ID_BLUE, 20, 0, 0, 0, 0, { IID_TOMAHAWK }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0868776C
struct UnitInfo CONST_DATA UnitInfo_TrialBonusUnitG[] =
{
    { PID_ZEPHIEL, 0, 0, FALSE, FACTION_ID_BLUE, 20, 0, 0, 0, 0, { IID_ECKESACHS }, { 0 } },
    { 0 }, // end
};

// UnitInfo @ 0868778C
struct UnitInfo CONST_DATA UnitInfo_TrialBonusUnitH[] =
{
    { PID_GUINIVERE, 0, 0, FALSE, FACTION_ID_BLUE, 20, 0, 0, 0, 0, { IID_DIVINE, IID_RECOVERSTAFF }, { 0 } },
    { 0 }, // end
};

// EventScr @ 086877AC
EventScr CONST_DATA EventScr_LoadUnits_TrialBonusUnitA[] =
{
    EvtLoadUnits(UnitInfo_TrialBonusUnitA)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086877C0
EventScr CONST_DATA EventScr_LoadUnits_TrialBonusUnitB[] =
{
    EvtLoadUnits(UnitInfo_TrialBonusUnitB)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086877D4
EventScr CONST_DATA EventScr_LoadUnits_TrialBonusUnitC[] =
{
    EvtLoadUnits(UnitInfo_TrialBonusUnitC)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086877E8
EventScr CONST_DATA EventScr_LoadUnits_TrialBonusUnitD[] =
{
    EvtLoadUnits(UnitInfo_TrialBonusUnitD)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 086877FC
EventScr CONST_DATA EventScr_LoadUnits_TrialBonusUnitE[] =
{
    EvtLoadUnits(UnitInfo_TrialBonusUnitE)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08687810
EventScr CONST_DATA EventScr_LoadUnits_TrialBonusUnitF[] =
{
    EvtLoadUnits(UnitInfo_TrialBonusUnitF)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08687824
EventScr CONST_DATA EventScr_LoadUnits_TrialBonusUnitG[] =
{
    EvtLoadUnits(UnitInfo_TrialBonusUnitG)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// EventScr @ 08687838
EventScr CONST_DATA EventScr_LoadUnits_TrialBonusUnitH[] =
{
    EvtLoadUnits(UnitInfo_TrialBonusUnitH)
    EvtMoveWait
    EvtClearSkip
    EvtEnd
};

// Group 44 summary:
// Units UnitInfo_TrialBonusUnitA 1
// Units UnitInfo_TrialBonusUnitB 1
// Units UnitInfo_TrialBonusUnitC 1
// Units UnitInfo_TrialBonusUnitD 1
// Units UnitInfo_TrialBonusUnitE 1
// Units UnitInfo_TrialBonusUnitF 1
// Units UnitInfo_TrialBonusUnitG 1
// Units UnitInfo_TrialBonusUnitH 1
