#include "pathfinding.h"

// Support Functions
// ------------------------------------------------------------

bool AreLocsEqual(FieldLoc a, FieldLoc b) {
    return (a.x == b.x) && (a.y == b.y);
};

bool IsLocIncluded(FieldLoc loc, FieldLoc* list, int listLength) {
    for (int index = 0; index < listLength; index++)
    {
        if (AreLocsEqual(loc, list[index]))
        {
            return true;
        }
    }
    return false;
};

// Creature Pathfinding Logic
// ------------------------------------------------------------

int FindPath(FieldLoc start, FieldLoc end, FieldLoc* out, size_t outCapacity) {

    // Setup
    int checkedCount = 0;
    FieldLoc checkedList[fieldSizeX * fieldSizeY];

    int frontierCount = 0;
    FieldLoc frontier[fieldSizeX * fieldSizeY];

    frontier[frontierCount] = start;
    frontierCount++;

    FieldLoc target;

    // Main Loop

    do
    {
        target = frontier[(frontierCount - 1)];

        if (AreLocsEqual(target, end))
        {
            // TODO - need to build path here?
            break;
        }

        checkedList[checkedCount] = target;
        checkedCount++;
        frontierCount--;

        for (int x = (target.x - 1); x <= (target.x + 1); x++)
        {
            for (int y = (target.y - 1); y <= (target.y + 1); y++)
            {
                FieldLoc test = {
                    .x = x,
                    .y = y,
                };

                if ((IsTargetLegal(test)) && 
                    (!IsEntityPresent(test)) &&
                    (!IsLocIncluded(test, frontier, frontierCount)) &&
                    (!IsLocIncluded(test, checkedList, checkedCount)))
                {
                    frontier[frontierCount] = test;
                    frontierCount++;
                }
            }
        }
    // TODO - or does this while condition need to use !AreLocsEqual(test, end) ?
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

/*
Loop iteration:

- Grab a position from frontier (into a local variable)
- Check if that position is the destination (in which case, we win)
- Remove that position from the frontier
- Insert that position into the checkedList
- Consider the 3x3 grid around that position
  - Ignore cells that arent walkable
  - Ignore cells that are already in the frontier or the checked list
  - Cells that dont fail these criteria get added to the frontier
*/