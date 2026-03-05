#include "world.h"

// ------------------------------------------------------------

Entity PlayerHero = {
    .type = HERO,
    .icon = "@",
    .color = WHITE,
    .data.hero = {
        // Attributes
        .health = 10,
        .dex = 4,
    }
};

GroundVisuals Ground = {
    .grassColor = GREEN,
    .grassIcon = ",,",
    .soilColor = BROWN,
    .soilIcon = ".",
};

Field World;