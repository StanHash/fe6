#ifndef RANDOM_H
#define RANDOM_H

#include "prelude.h"

void RandInit(int seed);

void RandSetSt(u16 const * st);
void RandGetSt(u16 * st);

int RandNext_100(void);
int RandNext(int max);
bool RandRoll(int threshold);
bool RandRoll2Rn(int threshold);

void RandInitB(int seed);
u32 RandNextB(void);

#endif // RANDOM_H
