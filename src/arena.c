
#include "arena.h"

#include "random.h"
#include "item.h"
#include "unit.h"
#include "faction.h"
#include "battle.h"

#include "constants/jids.h"
#include "constants/pids.h"
#include "constants/items.h"

static void ArenaBeginInternal(struct Unit* unit);
static int ArenaGetUnitWeaponKind(struct Unit* unit);
static int ArenaGetJobWeaponKind(struct JobInfo const* jinfo);
static int ArenaGenOpposingJid(int weaponKind);
static Bool ArenaIsMagicWeaponKind(int weaponKind);
static int ArenaGetOpposingLevel(int level);
static int ArenaGetPowerRanking(struct Unit* unit, Bool opponentIsMagic);
static void ArenaGenOpponentUnit(void);
static void ArenaGenBaseWeapons(void);
static u16 ArenaGetUpgradedWeapon(u16 item);
static Bool ArenaAdjustOpponentDamage(void);
static Bool ArenaAdjustOpponentPowerRanking(void);
static void ArenaGenMatchupGoldValue(void);

struct ArenaSt EWRAM_DATA gArenaSt = {};
struct Unit EWRAM_DATA gArenaOpponent = {};

u8 CONST_DATA JList_MeleeArena[] =
{
    JID_MERCENARY,
    JID_HERO,
    JID_MYRMIDON,
    JID_SWORDMASTER,
    JID_FIGHTER,
    JID_WARRIOR,
    JID_ARMOR,
    JID_GENERAL,
    JID_BISHOP,
    JID_MAGE,
    JID_SAGE,
    JID_SHAMAN,
    JID_DRUID,
    JID_CAVALIER,
    JID_PALADIN,
    JID_VALKYRIE,
    JID_PEGASUSKNIGHT,
    JID_FALCOKNIGHT,
    JID_WYVERNRIDER,
    JID_WYVERNLORD,
    JID_SOLDIER,
    JID_BRIGAND,
    JID_PIRATE,
    JID_BERSERKER,
    JID_MERCENARY,
    JID_MYRMIDON,
    JID_FIGHTER,
    JID_ARMOR,
    JID_MAGE,
    JID_SHAMAN,
    JID_CAVALIER,
    JID_PEGASUSKNIGHT,
    JID_WYVERNRIDER,
    JID_BRIGAND,
    JID_PIRATE,
    JID_SOLDIER,
    JID_SOLDIER,

    0 // end
};

u8 CONST_DATA JList_MagicArena[] =
{
    JID_MERCENARY,
    JID_HERO,
    JID_MYRMIDON,
    JID_SWORDMASTER,
    JID_FIGHTER,
    JID_WARRIOR,
    JID_ARMOR,
    JID_GENERAL,
    JID_ARCHER,
    JID_SNIPER,
    JID_BISHOP,
    JID_MAGE,
    JID_SAGE,
    JID_SHAMAN,
    JID_DRUID,
    JID_CAVALIER,
    JID_PALADIN,
    JID_VALKYRIE,
    JID_NOMAD,
    JID_NOMADTROOPER,
    JID_PEGASUSKNIGHT,
    JID_FALCOKNIGHT,
    JID_WYVERNRIDER,
    JID_WYVERNLORD,
    JID_SOLDIER,
    JID_BRIGAND,
    JID_PIRATE,
    JID_BERSERKER,
    JID_THIEF,
    JID_MERCENARY,
    JID_MYRMIDON,
    JID_FIGHTER,
    JID_ARMOR,
    JID_ARCHER,
    JID_MAGE,
    JID_SHAMAN,
    JID_CAVALIER,
    JID_NOMAD,
    JID_PEGASUSKNIGHT,
    JID_WYVERNRIDER,
    JID_SOLDIER,
    JID_SOLDIER,

    0 // end
};

u8 CONST_DATA JList_RangedArena[] =
{
    JID_ARCHER,
    JID_SNIPER,
    JID_BISHOP,
    JID_MAGE,
    JID_SAGE,
    JID_SHAMAN,
    JID_DRUID,
    JID_VALKYRIE,
    JID_NOMAD,
    JID_NOMADTROOPER,

    0 // end
};

u8 CONST_DATA JList_UnusedArena[] =
{
    JID_MERCENARY,
    JID_MYRMIDON,
    JID_SWORDMASTER,
    JID_FIGHTER,
    JID_WARRIOR,
    JID_BISHOP,
    JID_MAGE,
    JID_SAGE,
    JID_SHAMAN,
    JID_DRUID,
    JID_CAVALIER,
    JID_VALKYRIE,
    JID_PEGASUSKNIGHT,
    JID_WYVERNRIDER,
    JID_SOLDIER,
    JID_BRIGAND,
    JID_PIRATE,
    JID_BERSERKER,
    JID_THIEF,
    JID_FIGHTER,
    JID_FIGHTER,
    JID_THIEF,

    0 // end
};

static void ArenaBeginInternal(struct Unit* unit)
{
    int i;

    gArenaSt.player = unit;
    gArenaSt.opponent = &gArenaOpponent;

    gArenaSt.playerJid = unit->job->id;
    gArenaSt.playerWeaponKind = ArenaGetUnitWeaponKind(unit);

    gArenaSt.opponentJid = ArenaGenOpposingJid(gArenaSt.playerWeaponKind);
    gArenaSt.opponentWeaponKind = ArenaGetJobWeaponKind(GetJobInfo(gArenaSt.opponentJid));

    gArenaSt.playerIsMagic = ArenaIsMagicWeaponKind(gArenaSt.playerWeaponKind);
    gArenaSt.opponentIsMagic = ArenaIsMagicWeaponKind(gArenaSt.opponentWeaponKind);

    gArenaSt.playerLevel = unit->level;
    gArenaSt.opponentLevel = ArenaGetOpposingLevel(gArenaSt.playerLevel);

    ArenaGenOpponentUnit();
    ArenaGenBaseWeapons();

    for (i = 0; i < 10; ++i)
        if (!ArenaAdjustOpponentPowerRanking())
            break;

    for (i = 0; i < 5; ++i)
        if (!ArenaAdjustOpponentDamage())
            break;

    gArenaSt.playerPowerRanking = ArenaGetPowerRanking(gArenaSt.player, gArenaSt.opponentIsMagic);
    gArenaSt.opponentPowerRanking = ArenaGetPowerRanking(gArenaSt.opponent, gArenaSt.playerIsMagic);

    ArenaGenMatchupGoldValue();

    gArenaSt.unk_0B = 1;

    ArenaSetResult(ARENA_RESULT_0);
}

void ArenaBegin(struct Unit* unit)
{
    RandGetSt(gAction.arenaBeginRandSt);
    ArenaBeginInternal(unit);
}

void ArenaResume(struct Unit* unit)
{
    RandSetSt(gAction.arenaBeginRandSt);
    ArenaBeginInternal(unit);
    RandSetSt(gAction.actionRandSt);
}

static int ArenaGetUnitWeaponKind(struct Unit* unit)
{
    int i;

    int wexp = 0;
    int kind = -1;

    for (i = 0; i < UNIT_WEAPON_EXP_COUNT; ++i)
    {
        if (i == ITEM_KIND_STAFF)
            continue;

        if (wexp < unit->weaponExp[i])
        {
            wexp = unit->weaponExp[i];
            kind = i;
        }
    }

    return kind;
}

static int ArenaGetJobWeaponKind(struct JobInfo const* job)
{
    int i;

    int wexp = 0;
    int kind = -1;

    for (i = 0; i < UNIT_WEAPON_EXP_COUNT; ++i)
    {
        if (i == ITEM_KIND_STAFF)
            continue;

        if (wexp < job->weaponExp[i])
        {
            wexp = job->weaponExp[i];
            kind = i;
        }
    }

    return kind;
}

static int ArenaGenOpposingJid(int weaponKind)
{
    int promoteflag;
    int jobnum, i;

    int jobcount = 0;
    u8 const* joblist = NULL;

    switch (weaponKind)
    {

    case ITEM_KIND_SWORD:
    case ITEM_KIND_LANCE:
    case ITEM_KIND_AXE:
        joblist = JList_MeleeArena;
        break;

    case ITEM_KIND_BOW:
        joblist = JList_RangedArena;
        break;

    case ITEM_KIND_ANIMA:
    case ITEM_KIND_LIGHT:
    case ITEM_KIND_ELDER:
        joblist = JList_MagicArena;
        break;

    }

    promoteflag = UNIT_ATTRIBUTES(gArenaSt.player) & UNIT_ATTR_PROMOTED;

    // Iterating through the list is done by skipping jobs that aren't of the same tier as the player's job
    // Therefore we are working with a "sudo-list" that omits the skipped jobs

    // First, we iterate through this "sudo-list" once to count the number of jobs it contains.

    for (i = 0; joblist[i] != 0; ++i)
    {
        if ((GetJobInfo(joblist[i])->attributes & UNIT_ATTR_PROMOTED) != promoteflag)
            continue; // skip jobs that aren't of the same tier as player

        ++jobcount;
    }

    // We then choose one of the jobs in the "sudo-list" randomly

    jobnum = RandNext(jobcount);

    // Then, since we can't access elements of that "sudo-list" via indexes directly, we need to iterate again
    // This time, we count up to jobnum and when we reach that we have the job we want

    for (i = 0, jobcount = 0; TRUE; ++i)
    {
        if ((GetJobInfo(joblist[i])->attributes & UNIT_ATTR_PROMOTED) != promoteflag)
            continue; // skip jobs that aren't of the same tier as player

        if (jobcount == jobnum)
            break; // we reached the job we want

        ++jobcount;
    }

    return joblist[i];
}

static Bool ArenaIsMagicWeaponKind(int weaponKind)
{
    switch (weaponKind)
    {

    case ITEM_KIND_SWORD:
    case ITEM_KIND_LANCE:
    case ITEM_KIND_AXE:
    case ITEM_KIND_BOW:
        return FALSE;

    case ITEM_KIND_ANIMA:
    case ITEM_KIND_LIGHT:
    case ITEM_KIND_ELDER:
        return TRUE;

    }
}

static int ArenaGetOpposingLevel(int level)
{
    enum { LEVEL_VARIANCE = 4 };

    int result = level + RandNext(1 + 2*LEVEL_VARIANCE) - LEVEL_VARIANCE;

    if (result < 1)
        result = 1;

    return result;
}

static int ArenaGetPowerRanking(struct Unit* unit, Bool opponentIsMagic)
{
    int result = unit->hpMax;

    result += unit->hpMax;
    result += unit->pow*2;
    result += unit->skl*2;
    result += unit->spd*2;
    result += unit->lck;
    result += UNIT_CON_BASE(unit);

    if (opponentIsMagic)
        result += GetUnitResistance(unit)*2;
    else
        result += GetUnitDefense(unit)*2;

    if (UNIT_ATTRIBUTES(unit) & UNIT_ATTR_CRITBONUS)
        result += GetUnitPower(unit);

    return result;
}

static void ArenaGenOpponentUnit(void)
{
    struct UnitInfo info;

    int level, i;

    struct Unit* unit = &gArenaOpponent;

    info.pid = PID_ARENA_OPPONENT;
    info.jid = gArenaSt.opponentJid;
    info.factionId = 0;
    info.level = gArenaSt.opponentLevel;
    info.autolevel = TRUE;
    info.items[0] = 0;
    info.items[1] = 0;
    info.items[2] = 0;
    info.items[3] = 0;
    info.ai[0] = 0;
    info.ai[0] = 0;
    info.ai[1] = 0;
    info.ai[2] = 0;
    info.ai[3] = 0;

    ClearUnit(unit);
    unit->id = FACTION_RED+0;

    UnitInitFromInfo(unit, &info);
    UnitInitStats(unit, unit->person);

    level = unit->level;

    unit->level = ((gPlaySt.flags & PLAY_FLAG_HARD) ? level*18 : level*12) / 10;
    UnitAutolevel(unit);

    unit->level = level;

    if (unit->level < 1)
        unit->level = 1;

    if (unit->level > 20)
        unit->level = 20;

    UnitCheckStatOverflow(unit);
    SetUnitHp(unit, GetUnitMaxHp(unit));
}

static void ArenaGenBaseWeapons(void)
{
    u8 arenaWeapons[] =
    {
        [ITEM_KIND_SWORD] = IID_IRONSWORD,
        [ITEM_KIND_LANCE] = IID_IRONLANCE,
        [ITEM_KIND_AXE] = IID_IRONAXE,
        [ITEM_KIND_BOW] = IID_IRONBOW,
        [ITEM_KIND_ANIMA] = IID_FIRE,
        [ITEM_KIND_LIGHT] = IID_LIGHTNING,
        [ITEM_KIND_ELDER] = IID_FLUX,
    };

    gArenaSt.playerWeapon = CreateItem(arenaWeapons[gArenaSt.playerWeaponKind]);
    gArenaSt.opponentWeapon = CreateItem(arenaWeapons[gArenaSt.opponentWeaponKind]);

    gArenaSt.range = 1;

    if (gArenaSt.playerWeaponKind == ITEM_KIND_BOW)
        gArenaSt.range = 2;

    if (gArenaSt.opponentWeaponKind == ITEM_KIND_BOW)
        gArenaSt.range = 2;
}

static u16 ArenaGetUpgradedWeapon(u16 item)
{
    u8 arenaWeaponUpgrades[] =
    {
        IID_IRONSWORD, IID_STEELSWORD, IID_SILVERSWORD, 0,
        IID_IRONLANCE, IID_STEELLANCE, IID_SILVERLANCE, 0,
        IID_IRONAXE, IID_STEELAXE, IID_SILVERAXE, 0,
        IID_IRONBOW, IID_STEELBOW, IID_SILVERBOW, 0,
        IID_FIRE, IID_ELFIRE, IID_FIMBULVETR, 0,
        IID_LIGHTNING, IID_DIVINE, 0,
        IID_FLUX, 0,

        -1, // end
    };

    u8 const* it;

    for (it = arenaWeaponUpgrades; *it != (u8) -1; ++it)
    {
        if (GetItemIid(item) != *it)
            continue;

        if (*++it != 0)
            return CreateItem(*it);

        return item;
    }
}

static Bool ArenaAdjustOpponentDamage(void)
{
    Bool result = FALSE;

    // Update battle unit stats

    gBattleUnitA.battleAttack = GetUnitPower(gArenaSt.player) + 5;

    if (gArenaSt.opponentIsMagic)
        gBattleUnitA.battleDefense = GetUnitResistance(gArenaSt.player);
    else
        gBattleUnitA.battleDefense = GetUnitDefense(gArenaSt.player);

    gBattleUnitB.battleAttack = GetUnitPower(gArenaSt.opponent) + 5;

    if (gArenaSt.playerIsMagic)
        gBattleUnitB.battleDefense = GetUnitResistance(gArenaSt.opponent);
    else
        gBattleUnitB.battleDefense = GetUnitDefense(gArenaSt.opponent);

    if (gBattleUnitA.battleAttack - gBattleUnitB.battleDefense < GetUnitMaxHp(gArenaSt.opponent)/6)
    {
        // Player does too little damage
        // Nerfing opponent defenses

        result = TRUE;

        if (gArenaSt.playerIsMagic)
        {
            gArenaSt.opponent->res -= 4;

            if (gArenaSt.opponent->res < 0)
                gArenaSt.opponent->res = 0;
        }
        else
        {
            gArenaSt.opponent->def -= 4;

            if (gArenaSt.opponent->def < 0)
                gArenaSt.opponent->def = 0;
        }

        gArenaSt.opponent->spd += 1;
        gArenaSt.opponent->skl += 1;
    }

    if (gBattleUnitB.battleAttack - gBattleUnitA.battleDefense < GetUnitMaxHp(gArenaSt.player)/6)
    {
        // Opponent does too little damage
        // Buffing opponent offenses

        result = TRUE;

        gArenaSt.opponent->pow += 3;
        gArenaSt.opponent->spd += 2;
        gArenaSt.opponent->skl += 2;

        gArenaSt.opponentWeapon = ArenaGetUpgradedWeapon(gArenaSt.opponentWeapon);
    }

    return result;
}

static Bool ArenaAdjustOpponentPowerRanking(void)
{
    int max, diff;

    gArenaSt.playerPowerRanking = ArenaGetPowerRanking(gArenaSt.player, gArenaSt.opponentIsMagic);
    gArenaSt.opponentPowerRanking = ArenaGetPowerRanking(gArenaSt.opponent, gArenaSt.playerIsMagic);

    max = gArenaSt.playerPowerRanking > gArenaSt.opponentPowerRanking
        ? gArenaSt.playerPowerRanking : gArenaSt.opponentPowerRanking;

    diff = ABS(gArenaSt.playerPowerRanking - gArenaSt.opponentPowerRanking);

    if (diff*100/max <= 20)
        return FALSE;

    if (gArenaSt.playerPowerRanking < gArenaSt.opponentPowerRanking)
    {
        if (gArenaSt.opponent->hpMax != 0)
        {
            gArenaSt.opponent->hpMax -= 1;
            gArenaSt.opponent->hpCur -= 1;
        }

        if (gArenaSt.opponent->pow != 0)
            gArenaSt.opponent->pow -= 1;

        if (gArenaSt.opponent->skl != 0)
            gArenaSt.opponent->skl -= 1;

        if (gArenaSt.opponent->spd != 0)
            gArenaSt.opponent->spd -= 1;

        if (gArenaSt.opponent->def != 0)
            gArenaSt.opponent->def -= 1;

        if (gArenaSt.opponent->res != 0)
            gArenaSt.opponent->res -= 1;

        if (gArenaSt.opponent->lck != 0)
            gArenaSt.opponent->lck -= 1;

        return TRUE;
    }
    else
    {
        if (gArenaSt.opponent->hpMax < 80)
        {
            gArenaSt.opponent->hpMax += 2;
            gArenaSt.opponent->hpCur += 2;
        }

        if (gArenaSt.opponent->pow < 30)
            gArenaSt.opponent->pow += 1;

        if (gArenaSt.opponent->skl < 30)
            gArenaSt.opponent->skl += 1;

        if (gArenaSt.opponent->spd < 30)
            gArenaSt.opponent->spd += 1;

        if (gArenaSt.opponent->def < 30)
            gArenaSt.opponent->def += 1;

        if (gArenaSt.opponent->res < 30)
            gArenaSt.opponent->res += 1;

        if (gArenaSt.opponent->lck < 30)
            gArenaSt.opponent->lck += 1;

        return TRUE;
    }
}

static void ArenaGenMatchupGoldValue(void)
{
    int value = gArenaSt.opponentPowerRanking - gArenaSt.playerPowerRanking;

    value = 800 + 10*(value/2);

    if (value < 1)
        value = 1;

    gArenaSt.matchupGoldValue = value;
}

int ArenaGetMatchupGoldValue(void)
{
    return gArenaSt.matchupGoldValue;
}

int ArenaGetResult(void)
{
    return gArenaSt.result;
}

void ArenaSetResult(int result)
{
    gArenaSt.result = result;
}

void ArenaContinueBattle(void)
{
    int something = gBmSt.unk_3C;

    gAction.extra = gBattleUnitB.unit.hpCur;

    gAction.suspendPoint = SUSPEND_POINT_DURING_ARENA;
    sub_80857B0(SAVE_ID_SUSPEND0);

    BattleUnwind();

    if (gBattleUnitB.unit.hpCur == 0)
        BattleApplyExpGains();

    UpdateUnitDuringBattle(gArenaSt.player, &gBattleUnitA);

    if (!something || gBattleUnitB.unit.hpCur == 0)
        sub_8084D64();
}

Bool ArenaIsUnitAllowed(struct Unit* unit)
{
    if (unit->status == UNIT_STATUS_SILENCED)
        return FALSE;

    if (ArenaGetUnitWeaponKind(unit) < 0)
        return FALSE;

    return TRUE;
}
