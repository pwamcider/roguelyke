#include "actions.h"
#include "update.h"

// TODO Can remove stdio after testing
#include "stdio.h"

// Player Attribute Fetching
// ------------------------------------------------------------

int GetPlayerStrength(void) {
    return PlayerHero.data.hero.strength;
};

int GetPlayerDex(void) {
    return PlayerHero.data.hero.dex;
};

// Creature Attribute Fetching
// ------------------------------------------------------------

int GetCreatureHealth(Entity* entity) {
    return entity->data.creature.health;
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

void AdjustCreatureHealth(Entity* entity, int adjust) {
    entity->data.creature.health = GetCreatureHealth(entity) - adjust;
};

void CalcHitDamage(Entity* entity) {
    // TODO - adjust calculation below to incorporate item values.
    int hit = GetPlayerStrength();

    AdjustCreatureHealth(entity, hit);

    // TODO - TEMP
    int newhealth = GetCreatureHealth(entity);
    printf("New creature health: %i\n", newhealth);
};

// Combat Results
// ------------------------------------------------------------

bool DidCreatureDie(Entity* entity) {
    return entity->data.creature.health <= 0;
};

void CreatureDies(FieldLoc target) {
    // TODO - must eventually adjust for Malloc and free
    World.cells[target.x][target.y].entity = NULL;
};

// Action Path
// ------------------------------------------------------------

void RunAction(FieldLoc target) {
    switch (CheckEntityType(target))
    {
    case CREATURE:
        Entity* entity = GetEntity(target);
        
        // Physical Hits
        // ------------------------------------------------------------

        if (RollForHit(entity))
        {
            printf("Hit!\n");
            CalcHitDamage(entity);
        }
        else
        {
            printf("Miss!\n");
        }

        // Combat Results
        // ------------------------------------------------------------

        if (DidCreatureDie(entity))
        {
            CreatureDies(target);
        }
        break;
    
    default:
        break;
    }
};