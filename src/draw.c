#include "draw.h"
#include "raylib.h"
#include "resources.h"
#include "stdio.h"
#include "ui.h"
#include "world.h"

// ------------------------------------------------------------

void DrawWorld(void) {
    float buffer = GameView.cellBuffer;
    Vector2 target;

    // TODO - Better organize icons for primary drawing function.
    const char* groundIcon = ".";
    const char* heroIcon = "@";

    for (int x = 0; x < fieldSizeX; x++)
    {
        for (int y = 0; y < fieldSizeY; y++)
        {
            target.x = ((float)x * buffer) + GameView.originPoint.x;
            target.y = ((float)y * buffer) + GameView.originPoint.y;

            if (World.cells[x][y].entity != NULL)
            {
                DrawTextEx(gameFont, heroIcon, target, GameText.size, GameText.spacing, WHITE);
            }
            else
            {
                DrawTextEx(gameFont, groundIcon, target, GameText.size, GameText.spacing, WHITE);
            }
        }
    }
};