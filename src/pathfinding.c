#include "pathfinding.h"

// Support Functions
// ------------------------------------------------------------

bool AreLocsEqual(FieldLoc a, FieldLoc b) {
    return (a.x == b.x) && (a.y == b.y);
};

int GetLocIndex(FieldLoc loc, PathLoc* list, int listLength) {
    for (int index = 0; index < listLength; index++)
    {
        if (AreLocsEqual(loc, list[index].loc))
        {
            return index;
        }
    }
    return -1;
};

// Creature Pathfinding
// ------------------------------------------------------------

int FindPath(FieldLoc start, FieldLoc end, FieldLoc* out, size_t outCapacity) {
    // Setup
    int checkedCount = 0;
    PathLoc checkedList[fieldSizeX * fieldSizeY];

    int frontierCount = 0;
    PathLoc frontier[fieldSizeX * fieldSizeY];

    frontier[frontierCount] = (PathLoc) {.loc = start, .prev = start};
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

            checkedList[checkedCount] = target;
            checkedCount++;
            break;
        }

        checkedList[checkedCount] = target;
        checkedCount++;

        for (int x = (target.loc.x - 1); x <= (target.loc.x + 1); x++)
        {
            for (int y = (target.loc.y - 1); y <= (target.loc.y + 1); y++)
            {
                FieldLoc test = {
                    .x = x,
                    .y = y,
                };

                if ((IsTargetLegal(test)) && 
                    (!IsEntityPresent(test)) &&
                    (GetLocIndex(test, frontier, frontierCount) == -1) && // Checks if test is present in frontier
                    (GetLocIndex(test, checkedList, checkedCount) == -1)) // Checks if test is present in checked
                {
                    frontier[frontierCount] = (PathLoc) {.loc = test, .prev = target.loc};
                    frontierCount++;
                }
            }
        }
    } while (frontierCount > 0);
    

    printf("Size of checked list: %i\n", checkedCount);

    // TODO - the below code assumes a path was found; must account for no valid path.
    // Path Build
    int outIndex = 0;
    out[outIndex] = checkedList[checkedCount - 1].loc;
    outIndex++;

    FieldLoc next = checkedList[checkedCount -1].prev;

    do
    {
        // TODO - needs failsafe if below returns -1
        int nextIndex = GetLocIndex(next, checkedList, checkedCount);

        out[outIndex] = checkedList[nextIndex].loc;
        outIndex++;

        next = checkedList[nextIndex].prev;
    } while (!AreLocsEqual(start, next));

    for (int i = 0; i < outIndex; i++)
    {
        printf("Path step [%i] x%i, y%i\n", i, out[i].x, out[i].y);
    }
    
    return 4;
};