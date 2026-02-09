#include "raylib.h"
#include "stdio.h"
#include "ui.h"
#include "update.h"

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

bool IsPlayerThere(FieldLoc loc) {
    return World.cells[loc.x][loc.y].entity == &PlayerHero;
};

void MovePlayer(int input, FieldLoc loc) {
    if (input == GameInputs.moveNorth)
    {
        World.cells[loc.x][loc.y - 1].entity = &PlayerHero;
    }
    else if (input == GameInputs.moveEast)
    {
        World.cells[loc.x + 1][loc.y].entity = &PlayerHero;
    }
    else if (input == GameInputs.moveSouth)
    {
        World.cells[loc.x][loc.y + 1].entity = &PlayerHero;
    }
    else if (input == GameInputs.moveWest)
    {
        World.cells[loc.x - 1][loc.y].entity = &PlayerHero;
    }
    World.cells[loc.x][loc.y].entity = NULL;
};

void UpdatePlayer(int input, FieldLoc loc) {
    // Movement
    if (input == GameInputs.moveNorth || input == GameInputs.moveEast ||
        input == GameInputs.moveSouth || input == GameInputs.moveWest)
    {
        MovePlayer(input, loc);
    }
};

void UpdateWorld(int input) {
    for (int x = 0; x < fieldSizeX; x++)
    {
        for (int y = 0; y < fieldSizeY; y++)
        {
            FieldLoc origin = {
                .x = x,
                .y = y,
            };

            if (IsPlayerThere(origin))
            {
                UpdatePlayer(input, origin);
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