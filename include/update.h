#pragma once

#include "world.h"

// ------------------------------------------------------------

// Prototypes
bool IsEntityPresent(FieldLoc loc);
EntityType CheckEntityType(FieldLoc loc);
int GetInput(void);
void ClearWorld(void);
void MovePlayer(int input, FieldLoc loc);
void UpdateGameState(void);
void UpdatePlayer(int input, FieldLoc loc);
void UpdateWorld(int input);