#include "raylib.h"
#include "stdio.h"
#include "ui.h"
#include "update.h"
#include "world.h"

// ------------------------------------------------------------

void ClearWorld(void) {
    for (int x = 0; x < fieldSizeX; x++)
    {
        for (int y = 0; y < fieldSizeY; y++)
        {
            World.cells[x][y].cellType = GROUND;
            World.cells[x][y].entity = NULL;
        }
    }
};

int GetInput(void) {
    int input;

    if (IsKeyPressed(GameInputs.keyMoveNorth))
    {
        input = GameInputs.moveNorth;
    }
    else if (IsKeyPressed(GameInputs.keyMoveEast))
    {
        input = GameInputs.moveEast;
    }
    else if (IsKeyPressed(GameInputs.keyMoveSouth))
    {
        input = GameInputs.moveSouth;
    }
    else if (IsKeyPressed(GameInputs.keyMoveWest))
    {
        input = GameInputs.moveWest;
    }
    else if (IsKeyPressed(GameInputs.keyWait))
    {
        input = GameInputs.wait;
    }
    else
    {
        input = GameInputs.noInput;
    }
    
    return input;
};

bool IsPlayerThere(int x, int y) {
    return World.cells[x][y].entity == &PlayerHero;
};

void MovePlayer(int input, int x, int y) {
    if (input == GameInputs.moveNorth)
    {
        World.cells[x][y - 1].entity = &PlayerHero;
    }
    else if (input == GameInputs.moveEast)
    {
        World.cells[x + 1][y].entity = &PlayerHero;
    }
    else if (input == GameInputs.moveSouth)
    {
        World.cells[x][y + 1].entity = &PlayerHero;
    }
    else if (input == GameInputs.moveWest)
    {
        World.cells[x - 1][y].entity = &PlayerHero;
    }
    World.cells[x][y].entity = NULL;
};

void UpdatePlayer(int input, int x, int y) {
    // Movement
    if (input == GameInputs.moveNorth || input == GameInputs.moveEast ||
        input == GameInputs.moveSouth || input == GameInputs.moveWest)
    {
        MovePlayer(input, x, y);
    }
};

void UpdateWorld(int input) {
    for (int x = 0; x < fieldSizeX; x++)
    {
        for (int y = 0; y < fieldSizeY; y++)
        {
            if (IsPlayerThere(x, y))
            {
                UpdatePlayer(input, x, y);
                input = GameInputs.noInput;
            }
        }
    }
};

void UpdateGameState(void) {
    int input = GetInput();

    if (input > GameInputs.noInput)
    {
        UpdateWorld(input);
    }
};

// TODO - Add safeguards for preventing player movement (or any entity) off the screen!!