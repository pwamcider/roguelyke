#include "actions.h"
#include "raylib.h"
#include "stdio.h"
#include "ui.h"
#include "update.h"

// ------------------------------------------------------------

// Player Control
// ------------------------------------------------------------

int GetInput(void) {
    int input;

    // Direction Keys ------------------------------------------------------------
    if (IsKeyPressed(GameInputs.keyMoveNorth))
    {
        input = GameInputs.moveNorth;
    }
    else if (IsKeyPressed(GameInputs.keyMoveNorthEast))
    {
        input = GameInputs.moveNorthEast;
    }
    else if (IsKeyPressed(GameInputs.keyMoveEast))
    {
        input = GameInputs.moveEast;
    }
    else if (IsKeyPressed(GameInputs.keyMoveSouthEast))
    {
        input = GameInputs.moveSouthEast;
    }
    else if (IsKeyPressed(GameInputs.keyMoveSouth))
    {
        input = GameInputs.moveSouth;
    }
    else if (IsKeyPressed(GameInputs.keyMoveSouthWest))
    {
        input = GameInputs.moveSouthWest;
    }
    else if (IsKeyPressed(GameInputs.keyMoveWest))
    {
        input = GameInputs.moveWest;
    }
    else if (IsKeyPressed(GameInputs.keyMoveNorthWest))
    {
        input = GameInputs.moveNorthWest;
    }
    else if (IsKeyPressed(GameInputs.keyWait))
    {
        input = GameInputs.wait;
    }
    // No Input ------------------------------------------------------------
    else
    {
        input = GameInputs.noInput;
    }
    
    return input;
};

FieldLoc FindActionTarget(int input, FieldLoc origin) {
    FieldLoc target;
    
    if (input == GameInputs.moveNorth)
    {
        target.x = origin.x;
        target.y = origin.y - 1;
    }
    else if (input == GameInputs.moveNorthEast)
    {
        target.x = origin.x + 1;
        target.y = origin.y - 1;
    }
    else if (input == GameInputs.moveEast)
    {
        target.x = origin.x + 1;
        target.y = origin.y;
    }
    else if (input == GameInputs.moveSouthEast)
    {
        target.x = origin.x + 1;
        target.y = origin.y + 1;
    }
    else if (input == GameInputs.moveSouth)
    {
        target.x = origin.x;
        target.y = origin.y + 1;
    }
    else if (input == GameInputs.moveSouthWest)
    {
        target.x = origin.x - 1;
        target.y = origin.y + 1;
    }
    else if (input == GameInputs.moveWest)
    {
        target.x = origin.x - 1;
        target.y = origin.y;
    }
    else if (input == GameInputs.moveNorthWest)
    {
        target.x = origin.x - 1;
        target.y = origin.y - 1;
    }
    else
    {
        target.x = origin.x;
        target.y = origin.y;
    }

    return target;
};

// Support Functions
// ------------------------------------------------------------

bool IsEntityPresent(FieldLoc target) {
    return World.cells[target.x][target.y].entity;
};

EntityType CheckEntityType(FieldLoc target) {
    return World.cells[target.x][target.y].entity->type;
};

Entity* GetEntity(FieldLoc target) {
    return World.cells[target.x][target.y].entity;
};

bool IsTargetLegal(FieldLoc target) {
    return (target.x > -1 && target.x < fieldSizeX)
        && (target.y > -1 && target.y < fieldSizeY);
};

// TODO - current function also checks the origin
void CheckNearbyCells(FieldLoc origin) {    
    int i = 0;

    for (int x = (origin.x - 1); x <= (origin.x + 1); x++)
    {
        for (int y = (origin.y - 1); y <= (origin.y + 1); y++)
        {
            FieldLoc targetCell = {
                .x = x,
                .y = y,
            };

            if (IsTargetLegal(targetCell))
            {
                i++;
            }
        }
    }

    printf("Legal cells: %i\n", i);
};

// Player Actions
// ------------------------------------------------------------

void MovePlayer(FieldLoc origin, FieldLoc target) {
    World.cells[target.x][target.y].entity = &PlayerHero;
    World.cells[origin.x][origin.y].entity = NULL;
};

void UpdatePlayer(int input, FieldLoc origin) {
    // Directional Inputs
    if (input == GameInputs.moveNorth || input == GameInputs.moveEast ||
        input == GameInputs.moveSouth || input == GameInputs.moveWest ||
        input == GameInputs.moveNorthEast || input == GameInputs.moveSouthEast ||
        input == GameInputs.moveSouthWest || input == GameInputs.moveNorthWest)
    {
        FieldLoc target = FindActionTarget(input, origin);

        // Move Player
        if (IsTargetLegal(target) && !IsEntityPresent(target))
        {
            MovePlayer(origin, target);
        }
        // Action
        else if (IsTargetLegal(target) && IsEntityPresent(target))
        {
            RunAction(target);
        }
    }
};

// World Updates
// ------------------------------------------------------------

void UpdateWorld(int input) {
    for (int x = 0; x < fieldSizeX; x++)
    {
        for (int y = 0; y < fieldSizeY; y++)
        {
            FieldLoc origin = {
                .x = x,
                .y = y,
            };

            if (IsEntityPresent(origin))
            {
                switch (CheckEntityType(origin))
                {
                case HERO:
                    UpdatePlayer(input, origin);
                    input = GameInputs.noInput;
                    break;
                case CREATURE:
                    // TODO - creature AI here lol
                    break;
                default:
                    break;
                }
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

void ClearWorld(void) {
    for (int x = 0; x < fieldSizeX; x++)
    {
        for (int y = 0; y < fieldSizeY; y++)
        {
            World.cells[x][y].groundType = SOIL;
            World.cells[x][y].entity = NULL;
        }
    }
};