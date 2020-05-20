
#pragma once

#include "common.h"

#include "bm.h"

enum { UNIT_ITEM_COUNT = 5 };
enum { UNIT_WEAPON_EXP_COUNT = 8 };
enum { UNIT_SUPPORT_COUNT = 10 };
enum { UNIT_LEVEL_MAX = 20 };

enum
{
    UNIT_AMOUNT_BLUE = 62,
    UNIT_AMOUNT_RED = 50,
    UNIT_AMOUNT_GREEN = 20,
    UNIT_AMOUNT_PURPLE = 5,
};

enum
{
    UNIT_ATTR_MOUNTED = (1 << 0),
    UNIT_ATTR_RE_MOVE = (1 << 1),
    UNIT_ATTR_STEAL = (1 << 2),
    UNIT_ATTR_THIEF = (1 << 3),
    UNIT_ATTR_DANCE = (1 << 4),
    UNIT_ATTR_PLAY = (1 << 5),

    UNIT_ATTR_BALLISTA = (1 << 7),
    UNIT_ATTR_PROMOTED = (1 << 8),

    UNIT_ATTR_MOUNT_ICON = (1 << 10),
    UNIT_ATTR_WYVERN_ICON = (1 << 11),
    UNIT_ATTR_PEGASUS_ICON = (1 << 12),

    UNIT_ATTR_FEMALE = (1 << 14),
    UNIT_ATTR_BOSS = (1 << 15),
    UNIT_ATTR_LOCK_1 = (1 << 16),
    UNIT_ATTR_LOCK_2 = (1 << 17),
    UNIT_ATTR_LOCK_DRAGON = (1 << 18),
    UNIT_ATTR_LOCK_3 = (1 << 19),

    UNIT_ATTR_BIT23 = (1 << 23),

    // Helpers
    UNIT_ATTR_REFRESHER = UNIT_ATTR_DANCE + UNIT_ATTR_PLAY,
};

enum
{
    US_HIDDEN       = (1 << 0),
    US_TURN_ENDED   = (1 << 1),
    US_DEAD         = (1 << 2),
    US_NOT_DEPLOYED = (1 << 3),
    US_RESCUING     = (1 << 4),
    US_RESCUED      = (1 << 5),
    US_HAS_MOVED    = (1 << 6), // Bad name?
    US_UNDER_A_ROOF = (1 << 7),
    US_BIT8         = (1 << 8), // has been seen?
    US_BIT9         = (1 << 9), // hidden by fog?
    US_HAS_MOVED_AI = (1 << 10),

    // Helpers
    US_UNAVAILABLE = (US_DEAD + US_NOT_DEPLOYED),
};

enum
{
    UNIT_STATUS_NONE,

    UNIT_STATUS_POISON,
    UNIT_STATUS_SLEEP,
    UNIT_STATUS_SILENCED,
    UNIT_STATUS_BERSERK,
};

enum
{
    UNIT_USEBIT_WEAPON = (1 << 0),
    UNIT_USEBIT_STAFF = (1 << 1),
};

struct PersonInfo
{
    /* 00 */ u16 msgName;
    /* 02 */ u16 msgDesc;
    /* 04 */ u8 id;
    /* 05 */ u8 jidDefault;
    /* 06 */ u16 fid;
    /* 08 */ u8 chibiId;
    /* 09 */ u8 affinity;
    /* 0A */ u8 unk0A;

    /* 0B */ s8 levelBase;
    /* 0C */ s8 hpBase;
    /* 0D */ s8 powBase;
    /* 0E */ s8 sklBase;
    /* 0F */ s8 spdBase;
    /* 10 */ s8 defBase;
    /* 11 */ s8 resBase;
    /* 12 */ s8 lckBase;
    /* 13 */ s8 conBonus;

    /* 14 */ u8 weaponExp[UNIT_WEAPON_EXP_COUNT];

    /* 1C */ u8 hpGrowth;
    /* 1D */ u8 powGrowth;
    /* 1E */ u8 sklGrowth;
    /* 1F */ u8 spdGrowth;
    /* 20 */ u8 defGrowth;
    /* 21 */ u8 resGrowth;
    /* 22 */ u8 lckGrowth;

    /* 23 */ u8 banimPalA;
    /* 24 */ u8 banimPalB;
    /* 25 */ // pad

    /* 28 */ u32 attributes;

    /* 2C */ void const* supportInfo;
};

struct JobInfo
{
    /* 00 */ u16 msgName;
    /* 02 */ u16 msgDesc;
    /* 04 */ u8 id;
    /* 05 */ u8 jidPromote;
    /* 06 */ u8 mapSprite;
    /* 07 */ u8 walkSpeed;
    /* 08 */ u16 fid;
    /* 0A */ u8 unk0A;

    /* 0B */ s8 hpBase;
    /* 0C */ s8 powBase;
    /* 0D */ s8 sklBase;
    /* 0E */ s8 spdBase;
    /* 0F */ s8 defBase;
    /* 10 */ s8 resBase;
    /* 11 */ s8 conBase;
    /* 12 */ s8 movBase;

    /* 13 */ s8 hpMax;
    /* 14 */ s8 powMax;
    /* 15 */ s8 sklMax;
    /* 16 */ s8 spdMax;
    /* 17 */ s8 defMax;
    /* 18 */ s8 resMax;
    /* 19 */ s8 conMax;

    /* 1A */ s8 powerLevel;

    /* 1B */ s8 hpGrowth;
    /* 1C */ s8 powGrowth;
    /* 1D */ s8 sklGrowth;
    /* 1E */ s8 spdGrowth;
    /* 1F */ s8 defGrowth;
    /* 20 */ s8 resGrowth;
    /* 21 */ s8 lckGrowth;
    /* 22 */ // pad

    /* 24 */ u32 attributes;

    /* 28 */ u8 weaponExp[UNIT_WEAPON_EXP_COUNT];

    /* 30 */ void const* banimInfo;

    /* 34 */ s8 const* movTerrainTable;
    /* 38 */ s8 const* avoTerrainTable;
    /* 3C */ s8 const* defTerrainTable;
    /* 40 */ s8 const* resTerrainTable;

    /* 44 */ void const* unk44;
};

struct Unit
{
    /* 00 */ struct PersonInfo const* person;
    /* 04 */ struct JobInfo const* job;
    /* 08 */ s8 level;
    /* 09 */ u8 exp;
    /* 0A */ u8 aiFlags;
    /* 0B */ s8 id;
    /* 0C */ u16 state;
    /* 0E */ s8 x;
    /* 0F */ s8 y;
    /* 10 */ s8 hpMax;
    /* 11 */ s8 hpCur;
    /* 12 */ s8 pow;
    /* 13 */ s8 skl;
    /* 14 */ s8 spd;
    /* 15 */ s8 def;
    /* 16 */ s8 res;
    /* 17 */ s8 lck;
    /* 18 */ s8 conBonus;
    /* 19 */ u8 rescue;
    /* 1A */ s8 movBonus;

    /* 1B */ // TODO: more
    /* -- */ u8 pad_1B[0x1C - 0x1B];

    /* 1C */ u16 items[UNIT_ITEM_COUNT];
    /* 26 */ u8 weaponExp[UNIT_WEAPON_EXP_COUNT];
    /* 2E */ u8 status : 4;
    /* 2E */ u8 statusDuration : 4;
    /* 2F */ u8 torch : 4;
    /* 2F */ u8 barrier : 4;

    /* 30 */ u8 supports[UNIT_SUPPORT_COUNT];

    /* 3A */ // TODO: more
    /* -- */ u8 pad_3A[0x40 - 0x3A];

    /* 40 */ u16 aiConfig;
    /* 42 */ u8 aiA;
    /* 43 */ u8 aiApc;
    /* 44 */ u8 aiB;
    /* 45 */ u8 aiBpc;
    /* 46 */ // pad?

    /* 48 */ // end
};

struct UnitInfo
{
    /* 00 */ u8 pid;
    /* 01 */ u8 jid;
    /* 02 */ u8 pidLead;
    /* 03 */ u8 autolevel : 1;
    /* 03 */ u8 factionId : 2;
    /* 03 */ u8 level : 5;
    /* 04 */ u8 xLoad, yLoad;
    /* 06 */ u8 xMove, yMove;
    /* 08 */ u8 items[4];
    /* 0C */ u8 ai[4];
};

// NOTE: this goes into battle.h, which doesn't exist yet so it's here for now

struct BattleUnit
{
    /* 00 */ struct Unit unit;

    // this may not be accurate yet

    /* 48 */ u16 weapon;
    /* 4A */ u16 weaponBefore;
    /* 4C */ u32 weaponAttributes;
    /* 50 */ u8 weaponType;
    /* 51 */ u8 weaponSlotIndex;

    /* 52 */ s8 canCounter;

    /* 53 */ s8 wTriangleHitBonus;
    /* 54 */ s8 wTriangleDmgBonus;

    /* 55 */ u8 pad55[0x6A - 0x55];
 
    /* 6A */ s8 expGain;
    /* 6B */ s8 statusOut;
    /* 6C */ u8 levelPrevious;
    /* 6D */ u8 expPrevious;

    /* 6E */ u8 hpInitial;

    /* 6F */ s8 changeHP;
    /* 70 */ s8 changePow;
    /* 71 */ s8 changeSkl;
    /* 72 */ s8 changeSpd;
    /* 73 */ s8 changeDef;
    /* 74 */ s8 changeRes;
    /* 75 */ s8 changeLck;
    /* 76 */ s8 changeCon;

    /* 77 */ s8 wexpMultiplier;
    /* 78 */ s8 nonZeroDamage;
    /* 79 */ s8 weaponBroke;

    /* 7A */ s8 hasItemEffectTarget;
    /* 7B */ /* pad */
};

void InitUnits(void);
void ClearUnit(struct Unit* unit);
void CopyUnit(struct Unit* src, struct Unit* dst);
struct Unit* GetFreeUnit(int faction);
int GetUnitCurrentHp(struct Unit* unit);
int GetUnitMaxHp(struct Unit* unit);
int GetUnitPower(struct Unit* unit);
int GetUnitSkill(struct Unit* unit);
int GetUnitSpeed(struct Unit* unit);
int GetUnitDefense(struct Unit* unit);
int GetUnitResistance(struct Unit* unit);
int GetUnitLuck(struct Unit* unit);
int GetUnitFid(struct Unit* unit);
int GetUnitChibiId(struct Unit* unit);
int GetUnitLeaderPid(struct Unit* unit);
void SetUnitLeaderPid(struct Unit* unit, int pid);
void SetUnitHp(struct Unit* unit, int hp);
void AddUnitHp(struct Unit* unit, int amount);
int GetUnitVision(struct Unit* unit);
char const* GetUnitRescueName(struct Unit* unit);
char const* GetUnitStatusName(struct Unit* unit);
void SetUnitStatus(struct Unit* unit, int status);
struct Unit* GetUnit(int uid);
struct JobInfo const* GetJobInfo(int jid);
struct PersonInfo const* GetPersonInfo(int pid);
int GetUnitMapSprite(struct Unit* unit);
Bool UnitAddItem(struct Unit* unit, int item);
void UnitRemoveItem(struct Unit* unit, int slot);
void UnitRemoveInvalidItems(struct Unit* unit);
int GetUnitItemCount(struct Unit* unit);
Bool UnitHasItem(struct Unit* unit, int item);
int BatchCreateUnits(struct UnitInfo const* info);
struct Unit* CreateUnit(struct UnitInfo const* info);
void UnitInitFromInfo(struct Unit* unit, struct UnitInfo const* info);
void UnitInitStats(struct Unit* unit, struct PersonInfo const* person);
void sub_8017764(struct Unit* unit);
void UnitInitSupports(struct Unit* unit);
void UnitAutolevelWeaponExp(struct Unit* unit, struct UnitInfo const* info);
void UnitAutolevelCore(struct Unit* unit, u8 jid, int levelCount);
void UnitApplyBonusLevels(struct Unit* unit, int levelCount);
void UnitAutolevel(struct Unit* unit);
void UnitAutolevelPlayer(struct Unit* unit);
void UnitCheckStatOverflow(struct Unit* unit);
struct Unit* GetUnitByPid(int pid);
Bool CanUnitCarry(struct Unit* unit, struct Unit* other);
void UnitRescue(struct Unit* unit, struct Unit* other);
void UnitDropRescue(struct Unit* unit, int x, int y);
Bool UnitGiveRescue(struct Unit* unit, struct Unit* other);
void KillUnit(struct Unit* unit);
void UnitChangeFaction(struct Unit* unit, int faction);
Bool CanUnitCrossTerrain(struct Unit* unit, int terrain);
void UnitSyncMovement(struct Unit* unit);
void UnitGetDropPositionOnDeath(struct Unit* unit, int* xOut, int* yOut);
void UnitBeginAction(struct Unit* unit);
void UnitBeginReMoveAction(struct Unit* unit);
void sub_8017EDC(int x, int y);
void ClearActiveFactionTurnEndedState(void);
void TickActiveFactionTurnAndListStatusHeals(void);
void sub_801809C(void);
void UnitUpdateUsedItem(struct Unit* unit, int itemSlot);
int GetUnitAid(struct Unit* unit);
int GetUnitMagRange(struct Unit* unit);
Bool UnitKnowsMagic(struct Unit* unit);
void sub_80181B0(struct Unit* unit, int x, int y);
int GetUnitKeyItemSlotForTerrain(struct Unit* unit, int terrain);
int GetAidIconFromAttributes(int attributes);
int sub_8018258(struct Unit* unit);
Bool sub_80182D0(void);

extern struct Unit* gActiveUnit;

extern u8 EWRAM_DATA gActiveUnitId;
extern struct Vec2 EWRAM_DATA gActiveUnitMoveOrigin;

extern struct Unit EWRAM_DATA gUnitArrayBlue[UNIT_AMOUNT_BLUE];
extern struct Unit EWRAM_DATA gUnitArrayRed[UNIT_AMOUNT_RED];
extern struct Unit EWRAM_DATA gUnitArrayGreen[UNIT_AMOUNT_GREEN];
extern struct Unit EWRAM_DATA gUnitArrayPurple[UNIT_AMOUNT_PURPLE];

#define UNIT_FACTION(unit) ((unit)->id & 0xC0)
#define UNIT_ATTRIBUTES(unit) (((unit)->person->attributes) | ((unit)->job->attributes))

#define UNIT_HP_CAP(unit)  (UNIT_FACTION(unit) == FACTION_RED ? 80 : 60)
#define UNIT_POW_CAP(unit) ((unit)->job->powMax)
#define UNIT_SKL_CAP(unit) ((unit)->job->sklMax)
#define UNIT_SPD_CAP(unit) ((unit)->job->spdMax)
#define UNIT_DEF_CAP(unit) ((unit)->job->defMax)
#define UNIT_RES_CAP(unit) ((unit)->job->resMax)
#define UNIT_LCK_CAP(unit) (30)
#define UNIT_CON_CAP(unit) ((unit)->job->conMax)
#define UNIT_MOV_CAP(unit) (15)

#define UNIT_CON_BASE(unit) ((unit)->job->conBase + (unit)->person->conBonus)
#define UNIT_MOV_BASE(unit) ((unit)->job->movBase)

#define UNIT_CON(unit) (UNIT_CON_BASE(unit) + (unit)->conBonus)
#define UNIT_MOV(unit) ((unit)->movBonus + UNIT_MOV_BASE(unit))

#define FOR_UNITS(begin, end, varName, body) \
{ \
    int _uid; \
    struct Unit* varName; \
    for (_uid = (begin); _uid < (end); ++_uid) \
    { \
        varName = GetUnit(_uid); \
        if (!varName) \
            continue; \
        if (!varName->person) \
            continue; \
        body \
    } \
}

#define FOR_UNITS_FACTION(faction, varName, body) \
    FOR_UNITS((faction) + 1, (faction) + 0x40, varName, body)

#define FOR_UNITS_ALL(varName, body) \
    FOR_UNITS(1, 0xC0, varName, body)
