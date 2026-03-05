#pragma once

#include "world.h"

// ------------------------------------------------------------

// Function Prototypes
// ------------------------------------------------------------

bool RollForHit(Entity* entity);
Entity* GetEntity(FieldLoc target);
int GetCreatureDodge(Entity* entity);
int GetPlayerDex(void);
int RollD20(void);
void RunAction(FieldLoc target);