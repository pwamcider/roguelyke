#pragma once

#include "stdlib.h"
#include "world.h"

// Declarations
// ------------------------------------------------------------

typedef struct LocRange {
	int min_x;
	int max_x;
	int min_y;
	int max_y;
	int maxCells;
} LocRange;

typedef struct GroundGenValues {
	int grassFreq;
} GroundGenValues;

typedef struct EnvironGenValues {
	int oakTreeFreq;
} EnvironGenValues;

extern EnvironGenValues EnvironGen;
extern GroundGenValues GroundGen;
extern LocRange ValidRange;
extern unsigned int GameSeed;

// Function Prototypes
// ------------------------------------------------------------

bool FindValidLoc(FieldLoc* loc);
int GetRandomX(void);
int GetRandomY(void);
void AssignGameSeed(void);
void GenerateGrass(void);
void PopHeroRandom(void);
void PopOakTrees(void);