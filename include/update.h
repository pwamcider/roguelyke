#pragma once

#include "world.h"

// ------------------------------------------------------------

// Function Prototypes
bool IsEntityPresent(FieldLoc loc);
bool IsTargetLegal(FieldLoc target);
EntityType CheckEntityType(FieldLoc loc);
FieldLoc FindMoveTarget(int input, FieldLoc origin);
int GetInput(void);
void CheckNearbyCells(FieldLoc origin);
void ClearWorld(void);
void MovePlayer(FieldLoc origin, FieldLoc target);
void UpdateGameState(void);
void UpdatePlayer(int input, FieldLoc origin);
void UpdateWorld(int input);


// TODO - write a general "CheckNearbyCells" function that can be re-used for a variety of generation.
// Can use IsTargetLegal() function to help with the above.

