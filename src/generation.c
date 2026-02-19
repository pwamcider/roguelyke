#include "generation.h"
#include "raylib.h"
#include "world.h"

// ------------------------------------------------------------

unsigned int GameSeed = 21323;

LocRange ValidRange = {
    .min_x = 0,
    .max_x = (fieldSizeX - 1),
    .min_y = 0,
    .max_y = (fieldSizeY - 1),
};

GroundGenValues GroundGen = {
    .grassFreq = 15,
};

int GetRandomX(void) {
    return GetRandomValue(ValidRange.min_x, ValidRange.max_x);
};

int GetRandomY(void) {
    return GetRandomValue(ValidRange.min_y, ValidRange.max_y);
};

// TODO - ensure this function does not place player on top of other entity.
void PlacePlayerRandom(void) {
    World.cells[GetRandomX()][GetRandomY()].entity = &PlayerHero;
};

// TODO - refine this generation to favor "patches" of grass over truly random placement.
void GenerateGrass(void) {
    for (int i = 0; i < GroundGen.grassFreq; i++)
    {
        World.cells[GetRandomX()][GetRandomY()].groundType = GRASS;
    }
};