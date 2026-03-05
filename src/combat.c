#include "combat.h"
#include "update.h"

// TODO Can remove stdio after testing
#include "stdio.h"

// Player Attribute Fetching
// ------------------------------------------------------------

int GetPlayerDex(void) {
    return PlayerHero.data.hero.dex;
};

// Creature Attribute Fetching
// ------------------------------------------------------------

Entity* GetEntity(FieldLoc target) {
    return World.cells[target.x][target.y].entity;
};

int GetCreatureDodge(Entity* entity) {
    return entity->data.creature.dodge;
};

// Dice Rolls
// ------------------------------------------------------------

int RollD20(void) {
    return GetRandomValue(1, 20);
};

// Actions
// ------------------------------------------------------------

bool RollForHit(Entity* entity) {
    int roll = RollD20() + GetPlayerDex();

    return roll >= GetCreatureDodge(entity);
};

// Action Path
// ------------------------------------------------------------

void RunAction(FieldLoc target) {
    switch (CheckEntityType(target))
    {
    case CREATURE:
        Entity* entity = GetEntity(target);
        
        if (RollForHit(entity))
        {
            printf("Hit!\n");
        }
        else
        {
            printf("Miss!\n");
        }
        break;
    
    default:
        break;
    }
};