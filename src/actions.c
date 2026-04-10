#include "actions.h"
#include "advlog.h"
#include "stdlib.h"
#include "update.h"

// TODO Can remove stdio after testing
#include "stdio.h"

// Hero Attribute Fetching
// ------------------------------------------------------------

int GetHeroStrength(Entity* entity) {
    return entity->data.hero.strength;
};

int GetHeroDex(Entity* entity) {
    return entity->data.hero.dex;
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

bool RollForHit(Entity* attacker, Entity* defender) {
    int roll = RollD20() + GetHeroDex(attacker);

    return roll >= GetCreatureDodge(defender);
};

void AdjustCreatureHealth(Entity* entity, int adjust) {
    entity->data.creature.health = GetCreatureHealth(entity) - adjust;
};

void CalcHitDamage(Entity* attacker, Entity* defender) {
    // TODO - adjust calculation below to incorporate item values.
    int hit = GetHeroStrength(attacker);

    AdjustCreatureHealth(defender, hit);

    // TODO - TEMP
    int newhealth = GetCreatureHealth(defender);
    printf("New creature health: %i\n", newhealth);

    // Log Update for Successful Hit
    char entry[EntryLength];
    snprintf(entry, sizeof(entry), "You hit the %s for %i damage!", defender->logName, hit);
    UpdateAdvLog(entry);
};

// Combat Results
// ------------------------------------------------------------

bool DidCreatureDie(Entity* entity) {
    return entity->data.creature.health <= 0;
};

void CreatureDies(FieldLoc target) {
    free(World.cells[target.x][target.y].entity);
    World.cells[target.x][target.y].entity = NULL;
};

// Action Path
// ------------------------------------------------------------

void RunAction(FieldLoc origin, FieldLoc target) {
    switch (CheckEntityType(target))
    {
    case CREATURE:
        Entity* hero = GetEntity(origin);
        Entity* creature = GetEntity(target);
        
        // Physical Hits
        // ------------------------------------------------------------

        if (RollForHit(hero, creature))
        {
            printf("Hit!\n");
            CalcHitDamage(hero, creature);
        }
        else
        {
            // Log Update for Missed Hit
            char entry[EntryLength];
            snprintf(entry, sizeof(entry), "You missed the %s!", creature->logName);
            UpdateAdvLog(entry);
        }

        // Combat Results
        // ------------------------------------------------------------

        if (DidCreatureDie(creature))
        {
            // Log Update for Creature Dying
            char entry[EntryLength];
            snprintf(entry, sizeof(entry), "You defeated the %s!", creature->logName);
            UpdateAdvLog(entry);

            // Nullify Step
            CreatureDies(target);
        }
        break;
    
    default:
        break;
    }
};