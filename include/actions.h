#pragma once

#include "world.h"

// ------------------------------------------------------------

// Function Prototypes
// ------------------------------------------------------------

bool DidCreatureDie(Entity* entity);
bool RollForHit(Entity* entity);
int GetCreatureDodge(Entity* entity);
int GetCreatureHealth(Entity* entity);
int GetPlayerDex(void);
int GetPlayerStrength(void);
int RollD20(void);
void AdjustCreatureHealth(Entity* entity, int adjust);
void CalcHitDamage(Entity* entity);
void CreatureDies(FieldLoc target);
void RunAction(FieldLoc target);