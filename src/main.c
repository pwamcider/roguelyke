#include "draw.h"
#include "randomization.h"
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

	ClearWorld();

	SetRandomSeed(GameSeed);

	World.cells[GetRandomX()][GetRandomY()].entity = &PlayerHero;

	World.cells[5][5].groundType = GRASS;
	World.cells[12][11].groundType = GRASS;

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