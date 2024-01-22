#ifndef BMIO_H
#define BMIO_H

#include "prelude.h"

void StartBmVSync(void);
void EndBmVSync(void);
void LockBmDisplay(void);
void UnlockBmDisplay(void);
void AllocWeatherParticles(int weather);
void ApplyFlamesWeatherGradient(void);
void WeatherInit(void);
void WeatherVBlank(void);
void WeatherUpdate(void);
void DisableTilesetPalAnim(void);
void EnableTilesetPalAnim(void);
void SetWeather(int weather);

extern struct ProcScr CONST_DATA ProcScr_BmVSync[];
extern struct ProcScr CONST_DATA ProcScr_MapTask[];

#endif // BMIO_H
