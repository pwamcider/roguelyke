#include "generation.h"
#include "raylib.h"
#include "world.h"

// ------------------------------------------------------------

unsigned int GameSeed = 48;

LocRange ValidRange = {
    .min_x = 0,
    .max_x = (fieldSizeX - 1),
    .min_y = 0,
    .max_y = (fieldSizeY - 1),
};

int GetRandomX(void) {
    return GetRandomValue(ValidRange.min_x, ValidRange.max_x);
};

int GetRandomY(void) {
    return GetRandomValue(ValidRange.min_y, ValidRange.max_y);
};