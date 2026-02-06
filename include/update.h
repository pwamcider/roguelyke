#pragma once

// ------------------------------------------------------------

// Prototypes
bool IsPlayerThere(int x, int y);
int GetInput(void);
void ClearWorld(void);
void MovePlayer(int input, int x, int y);
void UpdateGameState(void);
void UpdatePlayer(int input, int x, int y);
void UpdateWorld(int input);