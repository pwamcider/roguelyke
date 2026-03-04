#include "creatures.h"

// ------------------------------------------------------------

Entity OakTree = {
    .type = CREATURE,
    .icon = "T",
    .color = GREEN,
    .data.creature = {
        .health = 30,
        .dodge = 1,
    }
};