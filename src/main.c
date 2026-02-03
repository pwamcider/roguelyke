#include "draw.h"
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

	ClearField();

	World.cells[20][20].entity = &PlayerHero;

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

			DrawField();

			
		EndDrawing();
	}

	UnloadResources();

	ShutdownGame();
	
	return 0;
}