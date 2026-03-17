#include "creatures.h"
#include "stdlib.h"

// Plantlife
// ------------------------------------------------------------

// TODO - make the tree less dodgy.
Entity* GenerateOakTree(void) {
    Entity* oakTree = malloc(sizeof(Entity));

    oakTree->type = CREATURE;
    // Visuals
    oakTree->icon = "T";
    oakTree->color = GREEN;
    // Starting Attributes
    oakTree->data.creature.health = 30;
    oakTree->data.creature.dodge = 15;

    return oakTree;
};