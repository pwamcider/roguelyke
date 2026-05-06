#pragma once

#include "stdio.h"
#include "update.h"
// Included: world.h

// Structs
// ------------------------------------------------------------

typedef struct PathLoc {
    FieldLoc loc;
    FieldLoc prev;
} PathLoc;

// Prototypes
// ------------------------------------------------------------

bool AreLocsEqual(FieldLoc a, FieldLoc b);
bool IsLocIncluded(FieldLoc loc, PathLoc* list, int listLength);
int FindPath(FieldLoc start, FieldLoc end, FieldLoc* out, size_t outCapacity);

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