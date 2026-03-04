#include "world.h"

// ------------------------------------------------------------

Entity PlayerHero = {
    .type = HERO,
    .icon = "@",
    .color = WHITE,
    .data.hero = {
        // Attributes
        .health = 10,
        .dex = 10,
    }
};

GroundVisuals Ground = {
    .grassColor = GREEN,
    .grassIcon = ",,",
    .soilColor = BROWN,
    .soilIcon = ".",
};

Field World;