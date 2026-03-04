#pragma once

#include "world.h"

// ------------------------------------------------------------

// Function Prototypes
// ------------------------------------------------------------

void RunAction(FieldLoc target);
int GetPlayerDex(void);
int GetCreatureDodge(FieldLoc target);
bool RollForHit(void);
int RollD20(void);