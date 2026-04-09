#include "draw.h"
#include "raylib.h"
#include "resources.h"
#include "setup.h"
#include "update.h"

// ------------------------------------------------------------

int main(void)
{
	InitGame();

	LoadResources();

	SetupGameState();

	while (!WindowShouldClose())
	{
		BeginDrawing();

			ClearBackground(BLACK);

			UpdateGameState();
			
			DrawGame();

		EndDrawing();
	}

	UnloadResources();

	ShutdownGame();
	
	return 0;
}