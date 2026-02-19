#include "draw.h"
#include "generation.h"
#include "raylib.h"
#include "resources.h"
#include "setup.h"
#include "update.h"
#include "world.h"

// ------------------------------------------------------------

int main(void)
{
	InitGame();

	LoadResources();

	SetRandomSeed(GameSeed);

	ClearWorld();

	GenerateGrass();

	PlacePlayerRandom();

	FieldLoc testingLoc = {
		.x = 29,
		.y = 29,
	};

	CheckNearbyCells(testingLoc);

	while (!WindowShouldClose())
	{
		BeginDrawing();

			ClearBackground(BLACK);

			UpdateGameState();
			
			DrawWorld();

		EndDrawing();
	}

	UnloadResources();

	ShutdownGame();
	
	return 0;
}