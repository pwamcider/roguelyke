#include "raylib.h"
#include "setup.h"

int main(void)
{
	InitGame();

	while (!WindowShouldClose())
	{
		BeginDrawing();

			ClearBackground(RAYWHITE);

			DrawText("hello, world", 190, 200, 20, LIGHTGRAY);

		EndDrawing();
	}

	ShutdownGame();
	
	return 0;
}