#pragma once

#include "world.h"

// ------------------------------------------------------------

// Prototypes
bool IsEntityPresent(FieldLoc loc);
bool IsMoveLegal(FieldLoc target);
EntityType CheckEntityType(FieldLoc loc);
FieldLoc FindMoveTarget(int input, FieldLoc origin);
int GetInput(void);
void ClearWorld(void);
void MovePlayer(FieldLoc origin, FieldLoc target);
void UpdateGameState(void);
void UpdatePlayer(int input, FieldLoc origin);
void UpdateWorld(int input);