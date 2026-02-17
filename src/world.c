#include "world.h"

// ------------------------------------------------------------

Entity PlayerHero = {
    .type = HERO,
    .data.hero = {
        .icon = "@",
        .color = WHITE,
    },
};

GroundVisuals Ground = {
    .grassColor = GREEN,
    .grassIcon = ",,",
    .soilColor = BROWN,
    .soilIcon = ".",
};

Field World;

FieldRange WorldRange = {
    .min_x = 0,
    .max_x = (fieldSizeX - 1),
    .min_y = 0,
    .max_y = (fieldSizeY - 1),
};