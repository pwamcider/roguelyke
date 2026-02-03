#include "stdio.h"
#include "update.h"
#include "world.h"

// ------------------------------------------------------------

void ClearField(void) {
    for (int x = 0; x < fieldSizeX; x++)
    {
        for (int y = 0; y < fieldSizeY; y++)
        {
            World.cells[x][y].cellType = GROUND;
            World.cells[x][y].entity = NULL;
        }
    }
};