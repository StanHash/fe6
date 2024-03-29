#include "ai_data.h"

#include "ai_script.h"
#include "ai_unk.h"

#include "constants/iids.h"
#include "constants/jids.h"
#include "constants/pids.h"
#include "constants/chapters.h"
#include "constants/terrains.h"

u8 CONST_DATA gAiPillageTerrainsNoLoot[] =
{
    TERRAIN_VILLAGE,
    TERRAIN_CHURCH,
    0,
};

u8 CONST_DATA gAiPillageTerrainsWithLoot[] =
{
    TERRAIN_VILLAGE,
    TERRAIN_CHURCH,
    TERRAIN_CHEST,
    0,
};

struct AiScr CONST_DATA AiScr_FallbackA[] =
{
    AI_ACTION(100),
};

struct AiScr CONST_DATA AiScr_FallbackB[] =
{
    AI_MOVE_TO_ENEMY,
};

static u8 const JList_AiJobRankRoy[] = { JID_ROY, 0 };
static u8 const JList_AiJobRankSupport[] = { JID_THIEF, JID_THIEF_F, JID_BARD, JID_DANCER, 0 };
static u8 const JList_AiJobRankHealers[] = { JID_PRIEST, JID_CLERIC, JID_TROUBADOUR, 0 };
static u8 const JList_AiJobRankCivilians[] = { JID_CIVILIAN, JID_CIVILIAN_F, JID_CHILD, JID_CHILD_F, 0 };
static u8 const JList_AiJobRankMages[] = { JID_BISHOP, JID_BISHOP_F, JID_MAGE, JID_MAGE_F, JID_SAGE, JID_SAGE_F, JID_SHAMAN, JID_SHAMAN_F, JID_DRUID, JID_DRUID_F, JID_VALKYRIE, 0 };
static u8 const JList_AiJobRankFlyers[] = { JID_PEGASUSKNIGHT, JID_FALCONKNIGHT, JID_WYVERNRIDER, JID_WYVERNRIDER_F, JID_WYVERNLORD, JID_WYVERNLORD_F, 0 };
static u8 const JList_AiJobRankArmors[] = { JID_ARMOR, JID_GENERAL, 0 };
static u8 const JList_AiJobRankCavaliers[] = { JID_CAVALIER, JID_CAVALIER_F, JID_PALADIN, JID_PALADIN_F, 0 };
static u8 const JList_AiJobRankArchers[] = { JID_ARCHER, JID_ARCHER_F, JID_SNIPER, JID_SNIPER_F, 0 };

u8 const * CONST_DATA gAiJobRankLists[] =
{
    JList_AiJobRankRoy,
    JList_AiJobRankSupport,
    JList_AiJobRankHealers,
    JList_AiJobRankCivilians,
    JList_AiJobRankMages,
    JList_AiJobRankFlyers,
    JList_AiJobRankArmors,
    JList_AiJobRankCavaliers,
    JList_AiJobRankArchers,
    NULL,
};

struct AiCombatScoreCoefficients const gAiCombatScoreCoefficientTable[] =
{
    [0] =
    {
        .coef_damage_dealt = 2,
        .coef_low_hp_opponent = 1,
        .coef_friend_zone = 1,
        .coef_job_rank_bonus = 1,
        .coef_turn_number = 1,
        .coef_damage_taken = 1,
        .coef_danger = 1,
        .coef_low_hp_self = 1,
        .job_rank_bonuses =
        {
            [AI_JOBRANK_ROY] = 10,
            [AI_JOBRANK_SUPPORTERS] = 15,
            [AI_JOBRANK_MAGES] = 5,
        }
    },

    [1] =
    {
        .coef_damage_dealt = 1,
        .coef_low_hp_opponent = 2,
        .coef_friend_zone = 2,
        .coef_job_rank_bonus = 2,
        .coef_turn_number = 0,
        .coef_damage_taken = 0,
        .coef_danger = 0,
        .coef_low_hp_self = 0,
        .job_rank_bonuses =
        {
            [AI_JOBRANK_ROY] = 10,
            [AI_JOBRANK_SUPPORTERS] = 15,
            [AI_JOBRANK_MAGES] = 5,
        }
    },

    [2] =
    {
        .coef_damage_dealt = 1,
        .coef_low_hp_opponent = 2,
        .coef_friend_zone = 2,
        .coef_job_rank_bonus = 2,
        .coef_turn_number = 2,
        .coef_damage_taken = 2,
        .coef_danger = 1,
        .coef_low_hp_self = 2,
        .job_rank_bonuses =
        {
            [AI_JOBRANK_ROY] = 10,
            [AI_JOBRANK_SUPPORTERS] = 15,
            [AI_JOBRANK_MAGES] = 5,
        }
    },

    [3] =
    {
        .coef_damage_dealt = 2,
        .coef_low_hp_opponent = 2,
        .coef_friend_zone = 2,
        .coef_job_rank_bonus = 2,
        .coef_turn_number = 0,
        .coef_damage_taken = 1,
        .coef_danger = 1,
        .coef_low_hp_self = 1,
        .job_rank_bonuses =
        {
            [AI_JOBRANK_ROY] = 10,
            [AI_JOBRANK_SUPPORTERS] = 15,
            [AI_JOBRANK_MAGES] = 5,
        }
    },

    [4] =
    {
        .coef_damage_dealt = 1,
        .coef_low_hp_opponent = 0,
        .coef_friend_zone = 0,
        .coef_job_rank_bonus = 0,
        .coef_turn_number = 2,
        .coef_damage_taken = 0,
        .coef_danger = 0,
        .coef_low_hp_self = 0,
        .job_rank_bonuses =
        {
            [AI_JOBRANK_ROY] = 10,
            [AI_JOBRANK_SUPPORTERS] = 15,
            [AI_JOBRANK_MAGES] = 5,
        }
    },

    [5] =
    {
        .coef_damage_dealt = 2,
        .coef_low_hp_opponent = 1,
        .coef_friend_zone = 1,
        .coef_job_rank_bonus = 1,
        .coef_turn_number = 1,
        .coef_damage_taken = 0,
        .coef_danger = 0,
        .coef_low_hp_self = 0,
        .job_rank_bonuses =
        {
            [AI_JOBRANK_ROY] = 10,
            [AI_JOBRANK_SUPPORTERS] = 15,
            [AI_JOBRANK_MAGES] = 5,
            [AI_JOBRANK_FLYERS] = 40,
        }
    },

    [6] =
    {
        .coef_damage_dealt = 2,
        .coef_low_hp_opponent = 2,
        .coef_friend_zone = 2,
        .coef_job_rank_bonus = 2,
        .coef_turn_number = 0,
        .coef_damage_taken = 1,
        .coef_danger = 1,
        .coef_low_hp_self = 1,
        .job_rank_bonuses =
        {
            [AI_JOBRANK_ROY] = 10,
            [AI_JOBRANK_SUPPORTERS] = 5,
            [AI_JOBRANK_MAGES] = 5,
            [AI_JOBRANK_FLYERS] = 5,
            [AI_JOBRANK_ARMORS] = 40,
        }
    },

    [7] =
    {
        .coef_damage_dealt = 2,
        .coef_low_hp_opponent = 2,
        .coef_friend_zone = 2,
        .coef_job_rank_bonus = 2,
        .coef_turn_number = 0,
        .coef_damage_taken = 1,
        .coef_danger = 1,
        .coef_low_hp_self = 1,
        .job_rank_bonuses =
        {
            [AI_JOBRANK_ROY] = 10,
            [AI_JOBRANK_SUPPORTERS] = 5,
            [AI_JOBRANK_MAGES] = 5,
            [AI_JOBRANK_FLYERS] = 5,
            [AI_JOBRANK_CAVALIERS] = 40,
        }
    },

    [8] =
    {
        .coef_damage_dealt = 2,
        .coef_low_hp_opponent = 1,
        .coef_friend_zone = 1,
        .coef_job_rank_bonus = 2,
        .coef_turn_number = 0,
        .coef_damage_taken = 1,
        .coef_danger = 1,
        .coef_low_hp_self = 1,
        .job_rank_bonuses =
        {
            [AI_JOBRANK_ROY] = 5,
            [AI_JOBRANK_CIVILIANS] = 40,
        }
    },

    [9] =
    {
        .coef_damage_dealt = 2,
        .coef_low_hp_opponent = 1,
        .coef_friend_zone = 1,
        .coef_job_rank_bonus = 1,
        .coef_turn_number = 1,
        .coef_damage_taken = 1,
        .coef_danger = 1,
        .coef_low_hp_self = 1,
        .job_rank_bonuses = {}
    },

    [10] =
    {
        .coef_damage_dealt = 2,
        .coef_low_hp_opponent = 1,
        .coef_friend_zone = 1,
        .coef_job_rank_bonus = 1,
        .coef_turn_number = 1,
        .coef_damage_taken = 1,
        .coef_danger = 1,
        .coef_low_hp_self = 1,
        .job_rank_bonuses =
        {
            [AI_JOBRANK_ROY] = 10,
            [AI_JOBRANK_HEALERS] = 40,
            [AI_JOBRANK_MAGES] = 40,
        }
    },

    [11] =
    {
        .coef_damage_dealt = 2,
        .coef_low_hp_opponent = 1,
        .coef_friend_zone = 1,
        .coef_job_rank_bonus = 1,
        .coef_turn_number = 1,
        .coef_damage_taken = 1,
        .coef_danger = 1,
        .coef_low_hp_self = 2,
        .job_rank_bonuses =
        {
            [AI_JOBRANK_ROY] = 10,
            [AI_JOBRANK_SUPPORTERS] = 15,
            [AI_JOBRANK_MAGES] = 5,
            [AI_JOBRANK_ARCHERS] = 40,
        }
    },

    [12] =
    {
        .coef_damage_dealt = 2,
        .coef_low_hp_opponent = 1,
        .coef_friend_zone = 1,
        .coef_job_rank_bonus = 2,
        .coef_turn_number = 1,
        .coef_damage_taken = 1,
        .coef_danger = 1,
        .coef_low_hp_self = 1,
        .job_rank_bonuses =
        {
            [AI_JOBRANK_ROY] = 20,
            [AI_JOBRANK_SUPPORTERS] = 20,
            [AI_JOBRANK_HEALERS] = 20,
            [AI_JOBRANK_MAGES] = 20,
            [AI_JOBRANK_FLYERS] = 20,
            [AI_JOBRANK_ARMORS] = 20,
            [AI_JOBRANK_CAVALIERS] = 20,
            [AI_JOBRANK_ARCHERS] = 20,
        }
    },

    [13] =
    {
        .coef_damage_dealt = 1,
        .coef_low_hp_opponent = 2,
        .coef_friend_zone = 1,
        .coef_job_rank_bonus = 2,
        .coef_turn_number = 1,
        .coef_damage_taken = 2,
        .coef_danger = 2,
        .coef_low_hp_self = 2,
        .job_rank_bonuses =
        {
            [AI_JOBRANK_ROY] = 20,
            [AI_JOBRANK_SUPPORTERS] = 25,
            [AI_JOBRANK_CIVILIANS] = 20,
            [AI_JOBRANK_MAGES] = 25,
            [AI_JOBRANK_FLYERS] = 20,
            [AI_JOBRANK_ARMORS] = 20,
            [AI_JOBRANK_CAVALIERS] = 20,
            [AI_JOBRANK_ARCHERS] = 20,
        }
    },

    [14] =
    {
        .coef_damage_dealt = 2,
        .coef_low_hp_opponent = 1,
        .coef_friend_zone = 0,
        .coef_job_rank_bonus = 0,
        .coef_turn_number = 0,
        .coef_damage_taken = 2,
        .coef_danger = 0,
        .coef_low_hp_self = 1,
        .job_rank_bonuses =
        {
            [AI_JOBRANK_ROY] = 10,
            [AI_JOBRANK_SUPPORTERS] = 15,
            [AI_JOBRANK_MAGES] = 5,
        }
    },

    [15] =
    {
        .coef_damage_dealt = 1,
        .coef_low_hp_opponent = 1,
        .coef_friend_zone = 0,
        .coef_job_rank_bonus = 0,
        .coef_turn_number = 0,
        .coef_damage_taken = 1,
        .coef_danger = 0,
        .coef_low_hp_self = 1,
        .job_rank_bonuses =
        {
            [AI_JOBRANK_ROY] = 10,
            [AI_JOBRANK_SUPPORTERS] = 15,
            [AI_JOBRANK_MAGES] = 5,
        }
    },

    [16] =
    {
        .coef_damage_dealt = 2,
        .coef_low_hp_opponent = 2,
        .coef_friend_zone = 2,
        .coef_job_rank_bonus = 2,
        .coef_turn_number = 0,
        .coef_damage_taken = 1,
        .coef_danger = 1,
        .coef_low_hp_self = 1,
        .job_rank_bonuses =
        {
            [AI_JOBRANK_ROY] = 10,
            [AI_JOBRANK_SUPPORTERS] = 5,
            [AI_JOBRANK_MAGES] = 5,
        }
    },

    [17] =
    {
        .coef_damage_dealt = 2,
        .coef_low_hp_opponent = 1,
        .coef_friend_zone = 1,
        .coef_job_rank_bonus = 1,
        .coef_turn_number = 1,
        .coef_damage_taken = 0,
        .coef_danger = 0,
        .coef_low_hp_self = 0,
        .job_rank_bonuses =
        {
            [AI_JOBRANK_ROY] = 10,
            [AI_JOBRANK_SUPPORTERS] = 15,
            [AI_JOBRANK_MAGES] = 5,
        }
    },

    [18] =
    {
        .coef_damage_dealt = 2,
        .coef_low_hp_opponent = 1,
        .coef_friend_zone = 1,
        .coef_job_rank_bonus = 1,
        .coef_turn_number = 1,
        .coef_damage_taken = 1,
        .coef_danger = 1,
        .coef_low_hp_self = 0,
        .job_rank_bonuses =
        {
            [AI_JOBRANK_ROY] = 10,
            [AI_JOBRANK_SUPPORTERS] = 15,
            [AI_JOBRANK_MAGES] = 5,
        }
    },

    [19] =
    {
        .coef_damage_dealt = 2,
        .coef_low_hp_opponent = 2,
        .coef_friend_zone = 2,
        .coef_job_rank_bonus = 2,
        .coef_turn_number = 0,
        .coef_damage_taken = 1,
        .coef_danger = 1,
        .coef_low_hp_self = 1,
        .job_rank_bonuses =
        {
            [AI_JOBRANK_ROY] = 10,
            [AI_JOBRANK_SUPPORTERS] = 15,
            [AI_JOBRANK_MAGES] = 5,
        }
    },

    [20] =
    {
        .coef_damage_dealt = 1,
        .coef_low_hp_opponent = 0,
        .coef_friend_zone = 0,
        .coef_job_rank_bonus = 0,
        .coef_turn_number = 2,
        .coef_damage_taken = 0,
        .coef_danger = 0,
        .coef_low_hp_self = 0,
        .job_rank_bonuses =
        {
            [AI_JOBRANK_ROY] = 10,
            [AI_JOBRANK_SUPPORTERS] = 15,
            [AI_JOBRANK_MAGES] = 5,
        }
    },

    [21] =
    {
        .coef_damage_dealt = 2,
        .coef_low_hp_opponent = 1,
        .coef_friend_zone = 1,
        .coef_job_rank_bonus = 1,
        .coef_turn_number = 1,
        .coef_damage_taken = 0,
        .coef_danger = 0,
        .coef_low_hp_self = 0,
        .job_rank_bonuses =
        {
            [AI_JOBRANK_ROY] = 10,
            [AI_JOBRANK_SUPPORTERS] = 15,
            [AI_JOBRANK_MAGES] = 5,
        }
    },

    [22] =
    {
        .coef_damage_dealt = 2,
        .coef_low_hp_opponent = 1,
        .coef_friend_zone = 1,
        .coef_job_rank_bonus = 2,
        .coef_turn_number = 1,
        .coef_damage_taken = 1,
        .coef_danger = 1,
        .coef_low_hp_self = 1,
        .job_rank_bonuses =
        {
            [AI_JOBRANK_ROY] = 10,
            [AI_JOBRANK_SUPPORTERS] = 5,
            [AI_JOBRANK_MAGES] = 5,
            [AI_JOBRANK_FLYERS] = 5,
            [AI_JOBRANK_ARMORS] = 50,
        }
    },

    [23] =
    {
        .coef_damage_dealt = 2,
        .coef_low_hp_opponent = 1,
        .coef_friend_zone = 1,
        .coef_job_rank_bonus = 2,
        .coef_turn_number = 1,
        .coef_damage_taken = 1,
        .coef_danger = 1,
        .coef_low_hp_self = 1,
        .job_rank_bonuses =
        {
            [AI_JOBRANK_ROY] = 10,
            [AI_JOBRANK_SUPPORTERS] = 5,
            [AI_JOBRANK_MAGES] = 5,
            [AI_JOBRANK_FLYERS] = 5,
            [AI_JOBRANK_CAVALIERS] = 50,
        }
    },

    [24] =
    {
        .coef_damage_dealt = 2,
        .coef_low_hp_opponent = 1,
        .coef_friend_zone = 1,
        .coef_job_rank_bonus = 2,
        .coef_turn_number = 0,
        .coef_damage_taken = 1,
        .coef_danger = 1,
        .coef_low_hp_self = 1,
        .job_rank_bonuses =
        {
            [AI_JOBRANK_ROY] = 5,
            [AI_JOBRANK_CIVILIANS] = 80,
        }
    },

    [25] =
    {
        .coef_damage_dealt = 2,
        .coef_low_hp_opponent = 1,
        .coef_friend_zone = 1,
        .coef_job_rank_bonus = 1,
        .coef_turn_number = 1,
        .coef_damage_taken = 1,
        .coef_danger = 1,
        .coef_low_hp_self = 1,
        .job_rank_bonuses = {}
    },

    [26] =
    {
        .coef_damage_dealt = 2,
        .coef_low_hp_opponent = 1,
        .coef_friend_zone = 1,
        .coef_job_rank_bonus = 1,
        .coef_turn_number = 1,
        .coef_damage_taken = 1,
        .coef_danger = 1,
        .coef_low_hp_self = 1,
        .job_rank_bonuses =
        {
            [AI_JOBRANK_ROY] = 10,
            [AI_JOBRANK_SUPPORTERS] = 25,
            [AI_JOBRANK_HEALERS] = 40,
        }
    },

    [27] =
    {
        .coef_damage_dealt = 2,
        .coef_low_hp_opponent = 1,
        .coef_friend_zone = 1,
        .coef_job_rank_bonus = 1,
        .coef_turn_number = 1,
        .coef_damage_taken = 1,
        .coef_danger = 1,
        .coef_low_hp_self = 2,
        .job_rank_bonuses =
        {
            [AI_JOBRANK_ROY] = 10,
            [AI_JOBRANK_SUPPORTERS] = 15,
            [AI_JOBRANK_MAGES] = 5,
            [AI_JOBRANK_ARCHERS] = 40,
        }
    },

    [28] =
    {
        .coef_damage_dealt = 2,
        .coef_low_hp_opponent = 1,
        .coef_friend_zone = 1,
        .coef_job_rank_bonus = 2,
        .coef_turn_number = 1,
        .coef_damage_taken = 1,
        .coef_danger = 1,
        .coef_low_hp_self = 1,
        .job_rank_bonuses =
        {
            [AI_JOBRANK_ROY] = 20,
            [AI_JOBRANK_SUPPORTERS] = 20,
            [AI_JOBRANK_HEALERS] = 20,
            [AI_JOBRANK_MAGES] = 20,
            [AI_JOBRANK_FLYERS] = 20,
            [AI_JOBRANK_ARMORS] = 20,
            [AI_JOBRANK_CAVALIERS] = 20,
            [AI_JOBRANK_ARCHERS] = 20,
        }
    },

    [29] =
    {
        .coef_damage_dealt = 1,
        .coef_low_hp_opponent = 2,
        .coef_friend_zone = 1,
        .coef_job_rank_bonus = 1,
        .coef_turn_number = 1,
        .coef_damage_taken = 2,
        .coef_danger = 1,
        .coef_low_hp_self = 2,
        .job_rank_bonuses =
        {
            [AI_JOBRANK_ROY] = 20,
            [AI_JOBRANK_SUPPORTERS] = 25,
            [AI_JOBRANK_CIVILIANS] = 20,
            [AI_JOBRANK_MAGES] = 25,
            [AI_JOBRANK_FLYERS] = 20,
            [AI_JOBRANK_ARMORS] = 20,
            [AI_JOBRANK_CAVALIERS] = 20,
            [AI_JOBRANK_ARCHERS] = 20,
        }
    },

    [30] =
    {
        .coef_damage_dealt = 2,
        .coef_low_hp_opponent = 1,
        .coef_friend_zone = 0,
        .coef_job_rank_bonus = 0,
        .coef_turn_number = 0,
        .coef_damage_taken = 2,
        .coef_danger = 0,
        .coef_low_hp_self = 1,
        .job_rank_bonuses =
        {
            [AI_JOBRANK_ROY] = 10,
            [AI_JOBRANK_SUPPORTERS] = 15,
            [AI_JOBRANK_MAGES] = 5,
        }
    },

    [31] =
    {
        .coef_damage_dealt = 1,
        .coef_low_hp_opponent = 1,
        .coef_friend_zone = 0,
        .coef_job_rank_bonus = 0,
        .coef_turn_number = 0,
        .coef_damage_taken = 1,
        .coef_danger = 0,
        .coef_low_hp_self = 1,
        .job_rank_bonuses =
        {
            [AI_JOBRANK_ROY] = 10,
            [AI_JOBRANK_SUPPORTERS] = 15,
            [AI_JOBRANK_MAGES] = 5,
        }
    },
};

// unused
u16 CONST_DATA PList_AiRoy[] =
{
    PID_ROY, 0,
};

u16 CONST_DATA PList_AiClarine[] =
{
    PID_CLARINE, 0,
};

u16 CONST_DATA PList_AiLalumAndElfin[] =
{
    PID_LARUM, PID_ELFFIN, 0,
};

u16 CONST_DATA PList_Ai_085C86AA[] =
{
    PID_CITIZEN_A4, PID_CITIZEN_CD, 0,
};

u8 CONST_DATA TerrainList_AiArmory[] =
{
    TERRAIN_ARMORY, 0,
};

u8 CONST_DATA TerrainList_AiSeizePoint[] =
{
    TERRAIN_GATE_0B, TERRAIN_THRONE, 0,
};

struct AiEscapePt const AiEscapePts_1[] =
{
    { 0, 4, FACING_LEFT },
    { -1 },
};

struct AiEscapePt const AiEscapePts_2[] =
{
    { -1 },
};

struct AiEscapePt const AiEscapePts_6[] =
{
    { 14, 0, FACING_UP },
    { -1 },
};

struct AiEscapePt const AiEscapePts_8[] =
{
    { 0, 4, FACING_LEFT },
    { -1 },
};

struct AiEscapePt const AiEscapePts_26[] =
{
    { 16, 0, FACING_UP },
    { -1 },
};

struct AiEscapePt const AiEscapePts_11[] =
{
    { 23, 0, FACING_UP },
    { -1 },
};

struct AiEscapePt const AiEscapePts_27[] =
{
    { 28, 0, FACING_UP },
    { -1 },
};

struct AiEscapePt const AiEscapePts_12[] =
{
    { 12, 31, FACING_DOWN },
    { -1 },
};

struct AiEscapePt const AiEscapePts_13[] =
{
    { 45, 6, FACING_RIGHT },
    { -1 },
};

struct AiEscapePt const AiEscapePts_15[] =
{
    { 27, 23, FACING_RIGHT },
    { -1 },
};

struct AiEscapePt const AiEscapePts_16[] =
{
    { 6, 22, 5 },
    { -1 },
};

struct AiEscapePt const AiEscapePts_20[] =
{
    { 13, 0, FACING_UP },
    { -1 },
};

struct AiEscapePt const AiEscapePts_22[] =
{
    { 1, 31, FACING_DOWN },
    { -1 },
};

struct AiEscapePt const AiEscapePts_31[] =
{
    { 15, 25, FACING_DOWN },
    { -1 },
};

struct AiEscapePt const AiEscapePts_33[] =
{
    { 2, 26, FACING_DOWN },
    { -1 },
};

struct AiEscapePt const AiEscapePts_None[] =
{
    { -1 },
};

struct AiEscapePt const * CONST_DATA gAiRedEscapePoints[CHAPTER_COUNT] =
{
    AiEscapePts_None,
    AiEscapePts_1,
    AiEscapePts_2,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_6,
    AiEscapePts_None,
    AiEscapePts_8,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_12,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_16,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_20,
    AiEscapePts_None,
    AiEscapePts_22,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_31,
    AiEscapePts_None,
    AiEscapePts_33,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
};

struct AiEscapePt const * CONST_DATA gAiGreenEscapePoints[CHAPTER_COUNT] =
{
    AiEscapePts_None,
    AiEscapePts_1,
    AiEscapePts_2,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_6,
    AiEscapePts_None,
    AiEscapePts_8,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_11,
    AiEscapePts_12,
    AiEscapePts_13,
    AiEscapePts_None,
    AiEscapePts_15,
    AiEscapePts_16,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_20,
    AiEscapePts_None,
    AiEscapePts_22,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_26,
    AiEscapePts_27,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_31,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
    AiEscapePts_None,
};

struct AiHealThreshold CONST_DATA gAiHealThresholds[] =
{
    { 100,  50 },
    {  80,  30 },
    {  50,  10 },
    { 100,  80 },
    {   0,   0 },
};

u16 CONST_DATA gUnk_085C8834[] =
{
    IID_FIRESTONE,
    IID_DIVINESTONE,
    IID_DEMONSTONE,
    IID_HEROCREST,
    IID_KNIGHTCREST,
    IID_ORIONSBOLT,
    IID_ELYSIANWHIP,
    IID_GUIDINGRING,
    IID_SECRETBOOK,
    IID_GODDESSICON,
    IID_SERAPHROBE,
    IID_DRACOSHIELD,
    IID_ENERGYRING,
    IID_SPEEDWING,
    IID_TALISMAN,
    IID_BOOTS,
    IID_BODYRING,
    IID_MEMBERCARD,
    IID_SILVERCARD,
    IID_ELIXIR,
    IID_CHESTKEY,
    IID_DOORKEY,
    IID_BRIDGEKEY,
    IID_LOCKPICK,
    IID_VULNERARY,
    IID_PUREWATER,
    IID_TORCH,
    IID_ANTITOXIN,
    -1,
};

// TODO: constants + finish chapter map
u32 const AiItemConfigTable[] =
{
    [CHAPTER_TUTORIAL] = 0x7,
    [CHAPTER_1] = 0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
    0x7,
};

// ===============
// = ??? ??? ??? =
// ===============

struct Vec2i const gUnk_0810DADC[] =
{
    {  3,  1 },
    {  3,  5 },
    {  7,  5 },
    {  7,  1 },

    { -1, -1 },
};

struct Vec2i const gUnk_0810DAF0[] =
{
    {  9,  9 },
    { 13, 15 },
    {  3, 18 },

    { -1, -1 },
};

struct Vec2i const * CONST_DATA gUnk_085C8870[] =
{
    gUnk_0810DADC,
    gUnk_0810DAF0,
};

struct Vec2i const * const * CONST_DATA gUnk_085C8878 = gUnk_085C8870;

char CONST_DATA gUnk_085C887C[] = "CALL TEST\n";
char CONST_DATA gUnk_085C8887   = 3;

// ==============
// = AI SCRIPTS =
// ==============

struct AiScr CONST_DATA AiScr_AiB_MoveToEnemy[] =
{
    AI_MOVE_TO_ENEMY,
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_AiB_MoveToEnemy_IgnoreClarine[] =
{
    AI_MOVE_TO_ENEMY_IGNORING(PList_AiClarine),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_AiB_MoveToEnemy_IgnoreRefreshers[] =
{
    AI_MOVE_TO_ENEMY_IGNORING(PList_AiLalumAndElfin),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_AiB_Nop[] =
{
    AI_NOP_0E,
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_AiB_PillageThenPursue[] =
{
    AI_PILLAGE,
    AI_SET_AI(AI_A_00, AI_B_00),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_AiB_PillageThenStop[] =
{
    AI_PILLAGE,
    AI_SET_AI(AI_A_06, AI_B_0C),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_AiB_Escape[] =
{
    AI_ESCAPE,
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_AiB_MoveTo_21_17[] =
{
    AI_MOVE_TOWARDS(21, 17),

AI_LABEL(1),
    AI_NOP,
    AI_GOTO(1),
};

// FIXME: use func_fe6_080336CC input struct
u8 const gUnk_0810DB00[] = { -1, +1, 0, 0 };

struct AiScr CONST_DATA AiScr_Unk_085C89C8[] =
{
    AI_CALL_FUNC(func_fe6_080337B4, NULL),
    AI_GOTO_IFGT(1, gAiSt.cmd_result+0, 0),

    AI_GOTO_START,

AI_LABEL(1),
    AI_CALL_FUNC(func_fe6_080336CC, gUnk_0810DB00),
};

struct AiCountEnemiesInRangeArg const gUnk_0810DB04 =
{
    .move_coeff_q4 = 0x20, // 2.0
    .attack_range = TRUE,
    .result_slot = 0,
};

struct AiScr CONST_DATA AiScr_Unk_085C8A18[] =
{
    AI_CALL_FUNC(AiFunc_CountEnemiesInRange, &gUnk_0810DB04),
    AI_GOTO_IFGT(1, gAiSt.cmd_result+0, 0),

    AI_NOP_0E,
    AI_GOTO_START,

AI_LABEL(1),
    AI_SET_AI_B(AI_B_00),
    AI_GOTO(1),
};

struct AiScr CONST_DATA AiScr_Unk_085C8A88[] =
{
    AI_CALL_FUNC(AiFunc_CountEnemiesInRange, &gUnk_0810DB04),
    AI_GOTO_IFGT(1, gAiSt.cmd_result+0, 0),

    AI_NOP_0E,
    AI_GOTO_START,

AI_LABEL(1),
    AI_SET_AI_B(AI_B_01),
    AI_GOTO(1),
};

// unused
struct AiScr CONST_DATA AiScr_Unk_085C8AF8[] =
{
    AI_CALL_FUNC(AiFunc_CountEnemiesInRange, &gUnk_0810DB04),
    AI_GOTO_IFGT(1, gAiSt.cmd_result+0, 0),

    AI_NOP_0E,
    AI_GOTO_START,

AI_LABEL(1),
    AI_SET_AI_B(AI_B_00),
    AI_GOTO(1),
};

// unused
struct AiScr CONST_DATA AiScr_Unk_085C8B68[] =
{
    AI_MOVE_TO_ENEMY,
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C8B88[] =
{
    AI_MOVE_RANDOM,
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C8BA8[] =
{
    AI_MOVE_TO_LISTED_TERRAIN(TerrainList_AiArmory),
    AI_GOTO_IFEQ(1, gAiSt.cmd_result+0, 4),
    AI_GOTO_START,

AI_BAD_LABEL(1),
    AI_MOVE_TO_ENEMY,
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C8C08[] =
{
    AI_MOVE_TO_LISTED_TERRAIN(TerrainList_AiSeizePoint),
    AI_GOTO_IFEQ(1, gAiSt.cmd_result+0, 4),
    AI_GOTO_START,

AI_BAD_LABEL(1),
    AI_MOVE_TO_ENEMY,
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_AiA_Action[] =
{
    AI_ACTION(100),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_AiA_Action80[] =
{
    AI_ACTION(80),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_AiA_Action50[] =
{
    AI_ACTION(50),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_AiA_ActionInPlace[] =
{
    AI_ACTION_IN_PLACE(100),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_AiA_ActionInPlace80[] =
{
    AI_ACTION_IN_PLACE(80),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_AiA_ActionInPlace50[] =
{
    AI_ACTION_IN_PLACE(50),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_AiA_Nop[] =
{
    AI_NOP,
    AI_GOTO_START,
};

// unused
struct AiScr CONST_DATA AiScr_Unk_085C8D48[] =
{
    AI_ACTION(100),

    AI_CALL_FUNC(AiFunc_GetCounter, NULL),
    AI_GOTO_IFGT(1, gAiSt.cmd_result+0, 0),

    AI_GOTO_START,

AI_LABEL(1),
    AI_ACTION_IN_PLACE(100),
    AI_GOTO(1),
};

// unused
struct AiScr CONST_DATA AiScr_Unk_085C8DB8[] =
{
    AI_ACTION(100),
    AI_GOTO_START,
};

// unused
struct AiScr CONST_DATA AiScr_Unk_085C8DD8[] =
{
    AI_ACTION(100),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C8DF8[] =
{
    AI_ACTION_IGNORING(100, PList_AiClarine),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C8E18[] =
{
    AI_ACTION_IGNORING(100, PList_AiLalumAndElfin),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C8E38[] =
{
    AI_ACTION_IGNORING(100, PList_Ai_085C86AA),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C8E58[] =
{
    AI_ACTION_ON_PID(100, PID_LILINA),

    AI_GOTO_IFEQ(1, gAiSt.cmd_result+0, 3),
    AI_GOTO_IFNE(0, gAiSt.cmd_result+0, 1),

AI_LABEL(1),
    AI_ACTION(100),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C8EB8[] =
{
    AI_ACTION_ON_PID(100, PID_ROY),

    AI_GOTO_IFNE(0, gAiSt.cmd_result+0, 3),

    AI_ACTION(100),
    AI_GOTO_START,
};

struct AiCountEnemiesInRangeArg const gUnk_0810DB08 =
{
    .move_coeff_q4 = 0x08, // 0.5
    .attack_range = TRUE,
    .result_slot = 0,
};

struct AiScr CONST_DATA AiScr_Unk_085C8EF8[] =
{
    AI_CALL_FUNC(AiFunc_CountEnemiesInRange, &gUnk_0810DB08),

    AI_GOTO_IFGT(1, gAiSt.cmd_result+0, 0),

    AI_ACTION_IN_PLACE(100),
    AI_GOTO_START,

AI_LABEL(1),
    AI_ACTION(100),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C8F68[] =
{
    AI_CALL_FUNC(func_fe6_08033898, NULL),

    AI_GOTO_IFEQ(1, gAiSt.cmd_result+1, 1),

    AI_CALL_FUNC(AiFunc_AttackCmdResult, NULL),
    AI_GOTO_START,

AI_LABEL(1),
    AI_SET_AI(AI_A_00, AI_B_00),
    AI_GOTO_START,
};

// FIXME: use func_fe6_08033998 input struct
struct { u8 unk_00; } const gUnk_0810DB0C = { 1 };

// unused
struct AiScr CONST_DATA AiScr_Unk_085C8FD8[] =
{
    AI_CALL_FUNC(func_fe6_08033998, &gUnk_0810DB0C),

    AI_GOTO_IFEQ(1, gAiSt.cmd_result+1, 1),

    AI_CALL_FUNC(AiFunc_AttackCmdResult, NULL),
    AI_GOTO_START,

AI_LABEL(1),
    AI_SET_AI(AI_A_00, AI_B_00),
    AI_GOTO_START,
};

struct AiCountEnemiesInRangeArg const gUnk_0810DB10 =
{
    .move_coeff_q4 = 0x08, // 0.5
    .attack_range = TRUE,
    .result_slot = 0,
};

struct AiScr CONST_DATA AiScr_Unk_085C9048[] =
{
    AI_CALL_FUNC(AiFunc_CountEnemiesInRange, &gUnk_0810DB10),

    AI_GOTO_IFGT(1, gAiSt.cmd_result+0, 0),

    AI_MOVE_TOWARDS(5, 7),
    AI_ACTION_IN_PLACE(100),
    AI_GOTO_START,

AI_LABEL(1),
    AI_MOVE_TO_ENEMY,
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C90C8[] =
{
    AI_CALL_FUNC(AiFunc_CountEnemiesInRange, &gUnk_0810DB10),

    AI_GOTO_IFGT(1, gAiSt.cmd_result+0, 0),

    AI_MOVE_TOWARDS(17, 6),
    AI_ACTION_IN_PLACE(100),
    AI_GOTO_START,

AI_LABEL(1),
    AI_MOVE_TO_ENEMY,
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C9148[] =
{
    AI_CALL_FUNC(AiFunc_CountEnemiesInRange, &gUnk_0810DB10),

    AI_GOTO_IFGT(1, gAiSt.cmd_result+0, 0),

    AI_MOVE_TOWARDS(19, 4),
    AI_ACTION_IN_PLACE(100),
    AI_GOTO_START,

AI_LABEL(1),
    AI_MOVE_TO_ENEMY,
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C91C8[] =
{
    AI_CALL_FUNC(AiFunc_CountEnemiesInRange, &gUnk_0810DB10),

    AI_GOTO_IFGT(1, gAiSt.cmd_result+0, 0),

    AI_MOVE_TOWARDS(4, 2),
    AI_ACTION_IN_PLACE(100),
    AI_GOTO_START,

AI_LABEL(1),
    AI_MOVE_TO_ENEMY,
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C9248[] =
{
    AI_CALL_FUNC(AiFunc_CountEnemiesInRange, &gUnk_0810DB10),

    AI_GOTO_IFGT(1, gAiSt.cmd_result+0, 0),

    AI_MOVE_TOWARDS(6, 2),
    AI_ACTION_IN_PLACE(100),
    AI_GOTO_START,

AI_LABEL(1),
    AI_MOVE_TO_ENEMY,
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C92C8[] =
{
    AI_CALL_FUNC(AiFunc_CountEnemiesInRange, &gUnk_0810DB10),

    AI_GOTO_IFGT(1, gAiSt.cmd_result+0, 0),

    AI_MOVE_TOWARDS(4, 3),
    AI_ACTION_IN_PLACE(100),
    AI_GOTO_START,

AI_LABEL(1),
    AI_MOVE_TO_ENEMY,
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C9348[] =
{
    AI_CALL_FUNC(AiFunc_CountEnemiesInRange, &gUnk_0810DB10),

    AI_GOTO_IFGT(1, gAiSt.cmd_result+0, 0),

    AI_MOVE_TOWARDS(5, 3),
    AI_ACTION_IN_PLACE(100),
    AI_GOTO_START,

AI_LABEL(1),
    AI_MOVE_TO_ENEMY,
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C93C8[] =
{
    AI_CALL_FUNC(AiFunc_CountEnemiesInRange, &gUnk_0810DB10),

    AI_GOTO_IFGT(1, gAiSt.cmd_result+0, 0),

    AI_MOVE_TOWARDS(6, 3),
    AI_ACTION_IN_PLACE(100),
    AI_GOTO_START,

AI_LABEL(1),
    AI_MOVE_TO_ENEMY,
    AI_GOTO_START,
};

struct AiDecideTalkArg const AiDecideTalkArg_LanceAlen = { PID_LANCE, PID_ALEN };

struct AiScr CONST_DATA AiScr_Unk_085C9448[] =
{
    AI_MOVE_TOWARDS_PID(PID_ALEN),
    AI_GOTO_IFNE(0, gAiSt.cmd_result+0, 2),

    AI_CALL_FUNC(AiFunc_DecideTalk, &AiDecideTalkArg_LanceAlen),
    AI_SET_AI(AI_A_00, AI_B_00),
};

struct AiDecideTalkArg const AiDecideTalkArg_ClarineRoy = { PID_CLARINE, PID_ROY };

struct AiScr CONST_DATA AiScr_AiB_Clarine[] =
{
    AI_MOVE_TOWARDS_PID(PID_ROY),

    AI_GOTO_IFEQ(1, gAiSt.cmd_result+0, 4),
    AI_GOTO_IFEQ(0, gAiSt.cmd_result+0, 3),
    AI_GOTO_IFNE(0, gAiSt.cmd_result+0, 2),

    AI_CALL_FUNC(AiFunc_DecideTalk, &AiDecideTalkArg_ClarineRoy),
    AI_SET_AI(AI_A_00, AI_B_00),
    AI_GOTO_START,

AI_LABEL(1),
    AI_NOP_0E,
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_AiB_MoveToRoy[] =
{
    AI_MOVE_TOWARDS_PID(PID_ROY),

    AI_GOTO_IFEQ(1, gAiSt.cmd_result+0, 4),
    AI_GOTO_IFEQ(2, gAiSt.cmd_result+0, 1),

    AI_GOTO_START,

AI_LABEL(1),
    AI_MOVE_TO_ENEMY,
    AI_GOTO_START,

AI_LABEL(2),
    AI_MOVE_TO_ENEMY,
    AI_GOTO(2),
};

struct AiScr CONST_DATA AiScr_AiB_MoveToLilina[] =
{
    AI_MOVE_TOWARDS_PID(PID_LILINA),

    AI_GOTO_IFEQ(1, gAiSt.cmd_result+0, 4),
    AI_GOTO_IFEQ(2, gAiSt.cmd_result+0, 1),

    AI_GOTO_START,

AI_LABEL(1),
    AI_MOVE_TO_ENEMY,
    AI_GOTO_START,

AI_LABEL(2),
    AI_MOVE_TO_ENEMY,
    AI_GOTO(2),
};

// unused
struct AiScr CONST_DATA AiScr_Unk_085C9568[] =
{
    AI_CALL_FUNC(func_fe6_08033898, NULL),
    AI_CALL_FUNC(AiFunc_AttackCmdResult, NULL),
    AI_GOTO_START,
};

struct UnkAiFuncArg_08033B04 const gUnk_0810DB1C =
{
    .action_random_threshold = 100,
    .maximum_heal_percent = 50,
};

struct AiScr CONST_DATA AiScr_Unk_085C9698[] =
{
    AI_CALL_FUNC(AiFunc_08033B04, &gUnk_0810DB1C),
    AI_GOTO_START,
};

struct AiScr CONST_DATA AiScr_Unk_085C96B8[] =
{
    AI_CALL_FUNC(AiFunc_08033B04, &gUnk_0810DB1C),
    AI_ACTION_IN_PLACE(100),
    AI_GOTO_START,
};

struct UnkAiFuncArg_08033B50 const gUnk_0810DB20 =
{
    .do_anything_threshold = 100,
    .do_offensive_threshold = 0,
};

struct AiScr CONST_DATA AiScr_Unk_085C96E8[] =
{
    AI_CALL_FUNC(AiFunc_08033B50, &gUnk_0810DB20),
    AI_GOTO_IFEQ(1, gAiSt.cmd_result+0, 5),

    AI_GOTO_START,

AI_LABEL(1),
    AI_SET_AI(AI_A_06, AI_B_0C),
    AI_GOTO_START,
};

static struct AiScr const * CONST_DATA sAiScriptLutB[] =
{
    [AI_B_00] = AiScr_AiB_MoveToEnemy,
    [AI_B_01] = AiScr_AiB_MoveToEnemy_IgnoreClarine,
    [AI_B_02] = AiScr_AiB_MoveToEnemy_IgnoreRefreshers,
    [AI_B_03] = AiScr_AiB_Nop,
    [AI_B_04] = AiScr_AiB_PillageThenPursue,
    [AI_B_05] = AiScr_AiB_PillageThenStop,
    [AI_B_06] = AiScr_Unk_085C8A18,
    [AI_B_07] = AiScr_Unk_085C8A88,
    [AI_B_08] = AiScr_Unk_085C89C8,
    [AI_B_09] = AiScr_Unk_085C8B88,
    [AI_B_0A] = AiScr_Unk_085C9448,
    [AI_B_0B] = AiScr_AiB_Clarine,
    [AI_B_0C] = AiScr_AiB_Escape,
    [AI_B_0D] = AiScr_AiB_MoveTo_21_17,
    [AI_B_0E] = AiScr_AiB_MoveToRoy,
    [AI_B_0F] = AiScr_AiB_MoveToLilina,
    [AI_B_10] = AiScr_Unk_085C9048,
    [AI_B_11] = AiScr_Unk_085C90C8,
    [AI_B_12] = AiScr_Unk_085C9148,
    [AI_B_13] = AiScr_Unk_085C91C8,
    [AI_B_14] = AiScr_Unk_085C9248,
    [AI_B_15] = AiScr_Unk_085C92C8,
    [AI_B_16] = AiScr_Unk_085C9348,
    [AI_B_17] = AiScr_Unk_085C93C8,
    [AI_B_18] = AiScr_Unk_085C8C08,
};

static struct AiScr const * CONST_DATA sAiScriptLutA[] =
{
    [AI_A_00] = AiScr_AiA_Action,
    [AI_A_01] = AiScr_AiA_Action80,
    [AI_A_02] = AiScr_AiA_Action50,
    [AI_A_03] = AiScr_AiA_ActionInPlace,
    [AI_A_04] = AiScr_AiA_ActionInPlace80,
    [AI_A_05] = AiScr_AiA_ActionInPlace50,
    [AI_A_06] = AiScr_AiA_Nop,
    [AI_A_07] = AiScr_Unk_085C8DF8,
    [AI_A_08] = AiScr_Unk_085C8E18,
    [AI_A_09] = AiScr_Unk_085C8E38,
    [AI_A_0A] = AiScr_Unk_085C8E58,
    [AI_A_0B] = AiScr_Unk_085C8EB8,
    [AI_A_0C] = AiScr_Unk_085C8EF8,
    [AI_A_0D] = AiScr_Unk_085C8F68,
    [AI_A_0E] = AiScr_Unk_085C9698,
    [AI_A_0F] = AiScr_Unk_085C96B8,
};

struct AiScr const * const * CONST_DATA gAiScriptLutB[] =
{
    sAiScriptLutB,
    sAiScriptLutB,
    sAiScriptLutB,
};

struct AiScr const * const * CONST_DATA gAiScriptLutA[] =
{
    sAiScriptLutA,
    sAiScriptLutA,
    sAiScriptLutA,
};
