#pragma once

#include "world.h"

// ------------------------------------------------------------

// Function Prototypes
bool IsEntityPresent(FieldLoc target);
bool IsTargetLegal(FieldLoc target);
Entity* GetEntity(FieldLoc target);
EntityType CheckEntityType(FieldLoc target);
FieldLoc FindActionTarget(int input, FieldLoc origin);
int GetInput(void);
void CheckNearbyCells(FieldLoc origin);
void ClearWorld(void);
void MovePlayer(FieldLoc origin, FieldLoc target);
void UpdateGameState(void);
void UpdatePlayer(int input, FieldLoc origin);
void UpdateWorld(int input);