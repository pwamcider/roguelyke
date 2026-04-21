#pragma once

#include "stdio.h"
#include "update.h"
// Included: world.h

// ------------------------------------------------------------

bool AreLocsEqual(FieldLoc a, FieldLoc b);
bool IsLocIncluded(FieldLoc loc, FieldLoc* list, int listLength);
int FindPath(FieldLoc start, FieldLoc end, FieldLoc* out, size_t outCapacity);