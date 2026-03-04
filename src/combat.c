#include "combat.h"
#include "update.h"

// ------------------------------------------------------------

int GetPlayerDex(void) {
    return PlayerHero.data.hero.dex;
};

int GetCreatureDodge(FieldLoc target) {
    return World.cells[target.x][target.y].entity->data.creature.dodge;
};

int RollD20(void) {

};

bool RollForHit(void) {

};


void RunAction(FieldLoc target) {
    switch (CheckEntityType(target))
    {
    case CREATURE:
        /* code */
        break;
    
    default:
        break;
    }
};