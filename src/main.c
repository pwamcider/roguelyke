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

	World.cells[GetRandomValue(WorldRange.min_x, WorldRange.max_x)]
			   [GetRandomValue(WorldRange.min_y, WorldRange.max_y)].entity = &PlayerHero;

	World.cells[5][5].groundType = GRASS;
	World.cells[12][11].groundType = GRASS;

	while (!WindowShouldClose())
	{
		BeginDrawing();

			ClearBackground(BLACK);

			/*
			DrawText("hello, world", 190, 200, 20, WHITE);

			for (int i = 0; i < 40; i++)
			{
				DrawText(".", (200 + (i*20)), 300, 20, WHITE);
			}

			DrawText("@", 500, 500, 20, WHITE);
			DrawText(GameField.cells[0][0].entity->icon, 600, 600, 20, WHITE);
			*/

			UpdateGameState();
			
			DrawWorld();

		EndDrawing();
	}

	UnloadResources();

	ShutdownGame();
	
	return 0;
}