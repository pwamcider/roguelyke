#pragma once

#include "world.h"

// Function Prototypes
// ------------------------------------------------------------

bool DidCreatureDie(Entity* entity);
bool RollForHit(Entity* attacker, Entity* defender);
int GetCreatureDodge(Entity* entity);
int GetCreatureHealth(Entity* entity);
int GetHeroDex(Entity* entity);
int GetHeroStrength(Entity* entity);
int RollD20(void);
void AdjustCreatureHealth(Entity* entity, int adjust);
void CalcHitDamage(Entity* attacker, Entity* defender);
void CreatureDies(FieldLoc target);
void RunAction(FieldLoc origin, FieldLoc target);