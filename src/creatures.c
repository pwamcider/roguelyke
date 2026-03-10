#include "creatures.h"

// ------------------------------------------------------------

// TODO - make the tree less dodgy.
Entity OakTree = {
    .type = CREATURE,
    .icon = "T",
    .color = GREEN,
    .data.creature = {
        .health = 30,
        .dodge = 15,
    }
};