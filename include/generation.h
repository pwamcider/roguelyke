#pragma once

// Declarations
// ------------------------------------------------------------

typedef struct LocRange {
	int min_x;
	int max_x;
	int min_y;
	int max_y;
} LocRange;

typedef struct GroundGenValues {
	int grassFreq;
} GroundGenValues;

extern GroundGenValues GroundGen;
extern LocRange ValidRange;
extern unsigned int GameSeed;

// Function Prototypes
// ------------------------------------------------------------

int GetRandomX(void);
int GetRandomY(void);
void PlacePlayerRandom(void);
void GenerateGrass(void);