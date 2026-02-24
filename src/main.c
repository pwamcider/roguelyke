#include "draw.h"
#include "generation.h"
#include "raylib.h"
#include "resources.h"
#include "setup.h"
#include "update.h"
#include "world.h"

// Possibly temp includes:
#include "inanimate.h"

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
		.x = 15,
		.y = 15,
	};

	World.cells[2][2].entity = &OakTree;

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