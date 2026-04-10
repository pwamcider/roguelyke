#include "creatures.h"
#include "stdlib.h"

// Plantlife
// ------------------------------------------------------------

// TODO - make the tree less dodgy.
// Consider making tree an inanimate object once monsters are in.

Entity* GenerateOakTree(void) {
    Entity* oakTree = malloc(sizeof(Entity));
    oakTree->type = CREATURE;

    // Player-facing Name
    oakTree->logName = "oak tree";

    // Visuals
    oakTree->icon = "T";
    oakTree->color = GREEN;

    // Starting Attributes
    oakTree->data.creature.health = 30;
    oakTree->data.creature.dodge = 5;

    return oakTree;
};