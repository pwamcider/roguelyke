#pragma once

#include "world.h"

// ------------------------------------------------------------

// Prototypes
bool IsPlayerThere(FieldLoc loc);
int GetInput(void);
void ClearWorld(void);
void MovePlayer(int input, FieldLoc loc);
void UpdateGameState(void);
void UpdatePlayer(int input, FieldLoc loc);
void UpdateWorld(int input);