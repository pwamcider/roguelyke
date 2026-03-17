#include "creatures.h"
#include "generation.h"
#include "hero.h"
#include "raylib.h"
#include "time.h"
#include "update.h"

// Global Generation Settings
// ------------------------------------------------------------

unsigned int GameSeed;

LocRange ValidRange = {
    .min_x = 0,
    .max_x = (fieldSizeX - 1),
    .min_y = 0,
    .max_y = (fieldSizeY - 1),
    .maxCells = (fieldSizeX * fieldSizeY) - 1,
};

// Generation Support Functions
// ------------------------------------------------------------

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

// TODO - Consider adding a full-scan of the field if there's only one free cell left
// and the maxCells value isn't adequate number of attempts.
bool FindValidLoc(FieldLoc* loc) {
    for (int attempts = 0; attempts < ValidRange.maxCells; attempts++)
    {
        loc->x = GetRandomX();
        loc->y = GetRandomY();

        if (!IsEntityPresent(*loc))
        {
            return true;
        }
        
    }
    return false;
};

// Hero Placement
// ------------------------------------------------------------

void PopHeroRandom(void) {
    FieldLoc loc;

    if (FindValidLoc(&loc))
    {
        World.cells[loc.x][loc.y].entity = GenerateHero();
    }
};

// Environment Generation
// ------------------------------------------------------------

GroundGenValues GroundGen = {
    .grassFreq = 20,
};

EnvironGenValues EnvironGen = {
    .oakTreeFreq = 4,
};

// TODO - refine this generation to favor "patches" of grass over truly random placement.
void GenerateGrass(void) {
    for (int i = 0; i < GroundGen.grassFreq; i++)
    {
        World.cells[GetRandomX()][GetRandomY()].groundType = GRASS;
    }
};

void PopOakTrees(void) {
    for (int i = 0; i < EnvironGen.oakTreeFreq; i++)
    {
        FieldLoc loc;

        if (FindValidLoc(&loc))
        {
            World.cells[loc.x][loc.y].entity = GenerateOakTree();
        }
    }
};