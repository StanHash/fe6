#pragma once

#include "prelude.h"

// TODO: is this good name?
// what is this error screen actually?

void OnVBlank_SioError(void);
void OnMain_SioErrorWait(void);
void PutSioErrorMessage(void);
void OnMain_SioError(void);
void StartSioErrorScreen(void);
