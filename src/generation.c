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

// TODO - build in failsafe below in case every cell is occupied by an entity
FieldLoc FindValidLoc(void) {
    bool validLoc = false;
    int attempts = 0;

    FieldLoc loc;

    do
    {
        loc.x = GetRandomX();
        loc.y = GetRandomY();

        validLoc = !IsEntityPresent(loc);

        attempts++;

        if (attempts == ValidRange.maxCells)
        {
            break;
        }
        
    } while (!validLoc);

    if (attempts < ValidRange.maxCells)
    {
        return loc;
    }
    else
    {

        exit(1);
    }
};

// Player Generation
// ------------------------------------------------------------

void PlacePlayerRandom(void) {
    FieldLoc loc = FindValidLoc();

    World.cells[loc.x][loc.y].entity = &PlayerHero;
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

Entity* GenerateOakTree(void) {
    Entity* newOakTree = malloc(sizeof(Entity));

    newOakTree->type = OakTree.type;
    newOakTree->icon = OakTree.icon;
    newOakTree->color = OakTree.color;
    newOakTree->data.creature.health = OakTree.data.creature.health;
    newOakTree->data.creature.dodge = OakTree.data.creature.dodge;

    return newOakTree;
};

void PopOakTrees(void) {
    for (int i = 0; i < EnvironGen.oakTreeFreq; i++)
    {
        FieldLoc loc = FindValidLoc();

        World.cells[loc.x][loc.y].entity = GenerateOakTree();
    }
};