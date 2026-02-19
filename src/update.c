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
            World.cells[x][y].groundType = SOIL;
            World.cells[x][y].entity = NULL;
        }
    }
};

bool IsEntityPresent(FieldLoc loc) {
    return World.cells[loc.x][loc.y].entity;
};

EntityType CheckEntityType(FieldLoc loc) {
    return World.cells[loc.x][loc.y].entity->type;
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

FieldLoc FindMoveTarget(int input, FieldLoc origin) {
    FieldLoc target;
    
    if (input == GameInputs.moveNorth)
    {
        target.x = origin.x;
        target.y = origin.y - 1;
        
    }
    else if (input == GameInputs.moveEast)
    {
        target.x = origin.x + 1;
        target.y = origin.y;
    }
    else if (input == GameInputs.moveSouth)
    {
        target.x = origin.x;
        target.y = origin.y + 1;
    }
    else if (input == GameInputs.moveWest)
    {
        target.x = origin.x - 1;
        target.y = origin.y;
    }
    else
    {
        target.x = origin.x;
        target.y = origin.y;
    }

    return target;
};

bool IsTargetLegal(FieldLoc target) {
    return (target.x > -1 && target.x < fieldSizeX)
        && (target.y > -1 && target.y < fieldSizeY);
};

void MovePlayer(FieldLoc origin, FieldLoc target) {
    World.cells[target.x][target.y].entity = &PlayerHero;
    World.cells[origin.x][origin.y].entity = NULL;
};

void UpdatePlayer(int input, FieldLoc origin) {
    // Movement
    if (input == GameInputs.moveNorth || input == GameInputs.moveEast ||
        input == GameInputs.moveSouth || input == GameInputs.moveWest)
    {
        FieldLoc target = FindMoveTarget(input, origin);

        if (IsTargetLegal(target))
        {
            MovePlayer(origin, target);
        }
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

            if (IsEntityPresent(origin))
            {
                switch (CheckEntityType(origin))
                {
                case HERO:
                    UpdatePlayer(input, origin);
                    input = GameInputs.noInput;
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

    printf("Legal cells: %i", i);
};