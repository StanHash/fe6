
#pragma once

#include "common.h"

#include "unit.h"

enum
{
    ARENA_RESULT_0,
    ARENA_RESULT_1,
    ARENA_RESULT_2,
};

struct ArenaSt
{
    /* 00 */ struct Unit* player;
    /* 04 */ struct Unit* opponent;
    /* 08 */ short matchupGoldValue;
    /* 0A */ u8 result;
    /* 0B */ u8 unk_0B;
    /* 0C */ u8 range;
    /* 0D */ u8 playerWeaponKind;
    /* 0E */ u8 opponentWeaponKind;
    /* 0F */ u8 playerJid;
    /* 10 */ u8 opponentJid;
    /* 11 */ u8 playerLevel;
    /* 12 */ u8 opponentLevel;
    /* 13 */ s8 playerIsMagic;
    /* 14 */ s8 opponentIsMagic;
    /* 16 */ u16 playerPowerRanking;
    /* 18 */ u16 opponentPowerRanking;
    /* 1A */ u16 playerWeapon;
    /* 1C */ u16 opponentWeapon;
};

void ArenaBegin(struct Unit* unit);
void ArenaResume(struct Unit* unit);
int ArenaGetMatchupGoldValue(void);
int ArenaGetResult(void);
void ArenaSetResult(int result);
void ArenaContinueBattle(void);
Bool ArenaIsUnitAllowed(struct Unit* unit);

extern struct ArenaSt gArenaSt;
