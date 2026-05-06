#include "pathfinding.h"

// Support Functions
// ------------------------------------------------------------

bool AreLocsEqual(FieldLoc a, FieldLoc b) {
    return (a.x == b.x) && (a.y == b.y);
};

// TODO - more efficient way to scan over the PathLoc list?
bool IsLocIncluded(FieldLoc loc, PathLoc* list, int listLength) {
    for (int index = 0; index < listLength; index++)
    {
        if (AreLocsEqual(loc, list[index].loc))
        {
            return true;
        }
    }
    return false;
};

// Creature Pathfinding
// ------------------------------------------------------------

int FindPath(FieldLoc start, FieldLoc end, FieldLoc* out, size_t outCapacity) {
    // Setup
    int checkedCount = 0;
    PathLoc checkedList[fieldSizeX * fieldSizeY];

    int frontierCount = 0;
    PathLoc frontier[fieldSizeX * fieldSizeY];

    frontier[frontierCount].loc = start;
    frontier[frontierCount].prev = start;
    frontierCount++;

    // Main Loop
    do
    {

        PathLoc target = frontier[frontierCount - 1];
        frontierCount--;

        printf("Checking: loc.x = %i loc.y = %i\n", target.loc.x, target.loc.y);

        if (AreLocsEqual(target.loc, end))
        {
            // TODO - need to build path here?
            break;
        }

        checkedList[checkedCount] = target;
        checkedCount++;

        for (int x = (target.loc.x - 1); x <= (target.loc.x + 1); x++)
        {
            for (int y = (target.loc.y - 1); y <= (target.loc.y + 1); y++)
            {
                // This is the place where the PathLoc is built;
                // We have access to both the previous (target) and the next thing to check (test)
                FieldLoc test = {
                    .x = x,
                    .y = y,
                };

                if ((IsTargetLegal(test)) && 
                    (!IsEntityPresent(test)) &&
                    (!IsLocIncluded(test, frontier, frontierCount)) &&
                    (!IsLocIncluded(test, checkedList, checkedCount)))
                {
                    // ANTOINE to check
                    frontier[frontierCount].loc = test;
                    frontier[frontierCount].prev = target.loc;
                    frontierCount++;
                }
            }
        }
    } while (frontierCount > 0);

    // ------------------------------------------------------------
    // Fake Nonsense below

    out[0].x = 0;
    out[0].y = 0;

    out[1].x = 1;
    out[1].y = 1;

    out[2].x = 2;
    out[2].y = 2; 

    out[3] = (FieldLoc) {.x = 3, .y = 3};

    return 4;
};