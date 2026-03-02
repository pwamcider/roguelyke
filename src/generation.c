#include "generation.h"
#include "raylib.h"
#include "stdio.h"
#include "update.h"
#include "world.h"
#include "time.h"

// ------------------------------------------------------------

unsigned int GameSeed;

LocRange ValidRange = {
    .min_x = 0,
    .max_x = (fieldSizeX - 1),
    .min_y = 0,
    .max_y = (fieldSizeY - 1),
};

GroundGenValues GroundGen = {
    .grassFreq = 20,
};

void AssignGameSeed(void) {
    // Dynamic RNG
    GameSeed = time(NULL);

    // Manual Input:
    // GameSeed = 10;
};

int GetRandomX(void) {
    return GetRandomValue(ValidRange.min_x, ValidRange.max_x);
};

int GetRandomY(void) {
    return GetRandomValue(ValidRange.min_y, ValidRange.max_y);
};

// TODO - Consider updating this function to be PlaceEntityRandom so it can also place whatever?
void PlacePlayerRandom(void) {
    bool validTarget = false;
    
    FieldLoc target;

    do
    {
        target.x = GetRandomX();
        target.y = GetRandomY();

        validTarget = !IsEntityPresent(target);

    } while (!validTarget);

    World.cells[target.x][target.y].entity = &PlayerHero;
};

// TODO - refine this generation to favor "patches" of grass over truly random placement.
void GenerateGrass(void) {
    for (int i = 0; i < GroundGen.grassFreq; i++)
    {
        World.cells[GetRandomX()][GetRandomY()].groundType = GRASS;
    }
};