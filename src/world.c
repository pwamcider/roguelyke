#include "world.h"

// ------------------------------------------------------------

Entity PlayerHero = {
    .type = HERO,
    .icon = "@",
    .color = WHITE,
};

GroundVisuals Ground = {
    .grassColor = GREEN,
    .grassIcon = ",,",
    .soilColor = BROWN,
    .soilIcon = ".",
};

Field World;