#include "advlog.h"
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

    for (int x = 0; x < fieldSizeX; x++)
    {
        for (int y = 0; y < fieldSizeY; y++)
        {
            target.x = ((float)x * buffer) + GameView.originPoint.x;
            target.y = ((float)y * buffer) + GameView.originPoint.y;

            Color localColor = WHITE;
            const char* localIcon = " ";

            if (World.cells[x][y].entity != NULL)
            {
                
                localIcon = World.cells[x][y].entity->icon;
                localColor = World.cells[x][y].entity->color;
            }

            else
            {
                switch (World.cells[x][y].groundType)
                {
                case SOIL:
                    localColor = Ground.soilColor;
                    localIcon = Ground.soilIcon;
                    break;

                case GRASS:
                    localColor = Ground.grassColor;
                    localIcon = Ground.grassIcon;
                    break;
                
                default:
                    break;
                }
            }

            DrawTextEx(gameFont, localIcon, target,
                       GameText.size, GameText.spacing, localColor);
        }
    }
};

void DrawAdvLog(void) {
    Vector2 target = {
        .x = AdvLogUI.originPoint.x,
    };

    for (int entry = 0; entry < NumEntries; entry++)
    {
        target.y = ((float)entry * AdvLogUI.entryHeight) + AdvLogUI.originPoint.y;

        DrawTextEx(gameFont, AdvLog[entry], target,
                   GameText.size, GameText.spacing, WHITE);
    }
};

void DrawGame(void) {
    DrawWorld();
    DrawAdvLog();
};