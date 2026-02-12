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

            if (World.cells[x][y].entity != NULL)
            {
                switch (World.cells[x][y].entity->type)
                {
                case HERO:
                    DrawTextEx(gameFont, PlayerHero.data.hero.icon,
                               target, GameText.size,
                               GameText.spacing, PlayerHero.data.hero.color);
                    break;
                
                default:
                    break;
                }
            }
            else
            {
                switch (World.cells[x][y].groundType)
                {
                case SOIL:
                    DrawTextEx(gameFont, Ground.soilIcon, target,
                               GameText.size, GameText.spacing, Ground.soilColor);
                    break;

                case GRASS:
                    DrawTextEx(gameFont, Ground.grassIcon, target,
                               GameText.size, GameText.spacing, Ground.grassColor);
                    break;
                
                default:
                    break;
                }
            }
        }
    }
};