#pragma once

#include "common.h"
#include "banim_sprite.h"

enum ekr_dragon_status_type_bitfile {
    EDRAGON_TYPE_0 = 1 << 0,
    EDRAGON_TYPE_1 = 1 << 1,
    EDRAGON_TYPE_2 = 1 << 2,
    EDRAGON_TYPE_3 = 1 << 3,
    EDRAGON_TYPE_4 = 1 << 4,
};

u32 GetEkrDragonStatusType(void); /* Different form FE8, this is a bitfile rather than enum */

void func_fe6_0805884C(void);
bool EkrDragonIntroDone(struct BaSprite * anim);
// func_fe6_080588A4
// func_fe6_080588BC

u32 GetBanimDragonStatusType(void);
int CheckEkrDragonDead1(void);
// func_fe6_080589C4
// func_fe6_080589FC
u16 * GetEkrDragonStatusIdx(struct BaSprite * anim);
// func_fe6_08058A1C
// func_fe6_08058A34
// func_fe6_08058A50
// func_fe6_08058A80
// func_fe6_08058ACC
// func_fe6_08058B84
// func_fe6_08058C3C
// func_fe6_08058CEC
// func_fe6_08058D08
// func_fe6_08058D34
// func_fe6_08058E24
// func_fe6_08058E58
// func_fe6_08058E90
// func_fe6_08058EC8
// func_fe6_08058F00
void InitEkrDragonStatus(void);
// func_fe6_08058F38
// func_fe6_08058F60
// func_fe6_08058FA8
// func_fe6_08059018
// func_fe6_08059078
// func_fe6_08059090
void func_fe6_080590B8(struct BaSprite * anim);
// func_fe6_080590FC
// func_fe6_08059144
// func_fe6_080591AC
// func_fe6_080591CC
// func_fe6_080592D0
// func_fe6_08059328
// func_fe6_080593D4
// func_fe6_08059400
// func_fe6_08059418
// func_fe6_0805946C
// func_fe6_080594CC
// func_fe6_08059578
// func_fe6_080595EC
// func_fe6_08059614
// func_fe6_0805966C
// func_fe6_08059690
// func_fe6_08059730
// func_fe6_08059758
// func_fe6_0805979C
// func_fe6_080597E0
// func_fe6_08059824
// func_fe6_08059868
// func_fe6_080598AC
// func_fe6_080598F0
// func_fe6_08059928
void func_fe6_080599D0(struct BaSprite * anim);
// func_fe6_08059A28
// func_fe6_08059A44
// func_fe6_08059AD0
// func_fe6_08059B78
// func_fe6_08059BE4
// func_fe6_08059C38
// func_fe6_08059C54
// func_fe6_08059C78
// func_fe6_08059D34
void func_fe6_08059D8C(struct BaSprite * anim);
