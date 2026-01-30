#include "draw.h"
#include "raylib.h"
#include "resources.h"
#include "stdio.h"
#include "ui.h"
#include "world.h"

// ------------------------------------------------------------

void DrawField(void) {
    const char* icon = ".";
    float buffer = GameView.cellBuffer;
    Vector2 target;

    for (int x = 0; x < fieldSizeX; x++)
    {
        for (int y = 0; y < fieldSizeY; y++)
        {
            target.x = ((float)x * buffer) + GameView.originPoint.x;
            target.y = ((float)y * buffer) + GameView.originPoint.y;

            if (World.cells[x][y].entity != NULL)
            {
                // TODO - Draw 
                DrawText("1", 20, 20, 10, WHITE);
            }
            else
            {
                DrawText("2", 20, 20, 10, WHITE);
                DrawTextEx(gameFont, icon, target, GameText.size, GameText.spacing, WHITE);
            }
        }
    }
};