#include "creatures.h"
#include "generation.h"
#include "raylib.h"
#include "stdlib.h"
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

// Player Generation
// ------------------------------------------------------------

// TODO - Consider updating this function to be PlaceEntityRandom so it can also place whatever?

// TODO - Create a "find validloc" function based off the below that can run in a loop!!
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

// Environment Generation
// ------------------------------------------------------------

GroundGenValues GroundGen = {
    .grassFreq = 20,
};

EnvironGenValues EnvironGen = {
    .oakTreeFreq = 5,
};

// TODO - refine this generation to favor "patches" of grass over truly random placement.
void GenerateGrass(void) {
    for (int i = 0; i < GroundGen.grassFreq; i++)
    {
        World.cells[GetRandomX()][GetRandomY()].groundType = GRASS;
    }
};

Entity* GenOakTree(void) {
    Entity* newOakTree = malloc(sizeof(Entity));

    newOakTree->type = OakTree.type;
    newOakTree->icon = OakTree.icon;
    newOakTree->color = OakTree.color;
    newOakTree->data.creature.health = OakTree.data.creature.health;
    newOakTree->data.creature.dodge = OakTree.data.creature.dodge;

    return newOakTree;
};

// TODO - ensure gen does not generate on top of existing entity.
void PopOakTrees(void) {
    for (int i = 0; i < EnvironGen.oakTreeFreq; i++)
    {
        World.cells[GetRandomX()][GetRandomY()].entity = GenOakTree();
    }
};