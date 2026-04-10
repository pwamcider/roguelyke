#include "hero.h"
#include "stdlib.h"

// Hero Generation
// ------------------------------------------------------------

Entity* GenerateHero(void) {
    Entity* hero = malloc(sizeof(Entity));

    hero->type = HERO;

    // Visuals
    hero->icon = "@";
    hero->color = WHITE;
    
    // Starting Attributes
    hero->data.hero.health = 10;
    hero->data.hero.strength = 5;
    hero->data.hero.dex = 3;

    return hero;
};