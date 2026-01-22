#include "raylib.h"
#include "resources.h"
#include "setup.h"

#define FieldSizeX 50
#define FieldSizeY 50

// ------------------------------------------------------------

typedef struct Field
{
	// Needs to be placed on the screen.
	// Needs container to hold values so draw function knows what to write
	char* cells[FieldSizeX][FieldSizeY];
	int cellBuffer;
	Vector2 fieldOrigin;
} Field;

Field GameField = {
	.cellBuffer = 20,
	.fieldOrigin = { 50, 50 }
};

void DrawToField(void)
{
	for (int i = 0; i < FieldSizeX; i++)
	{
		
	}
	
}

int main(void)
{
	InitGame();

	LoadResources();

	while (!WindowShouldClose())
	{
		BeginDrawing();

			ClearBackground(BLACK);

			DrawText("hello, world", 190, 200, 20, WHITE);

			for (int i = 0; i < 40; i++)
			{
				DrawText(".", (200 + (i*20)), 300, 20, WHITE);
			}

			DrawText("@", 500, 500, 20, WHITE);
			// DrawText(sampleBoard.cell[0][0].text, 550, 550, 20, WHITE);
			
		EndDrawing();
	}

	UnloadResources();

	ShutdownGame();
	
	return 0;
}