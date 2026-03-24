#include "advlog.h"

// TODO - temp
#include "stdio.h"

// ------------------------------------------------------------

const char* AdvLog[AdvLogSize];

void PopAdvLog(void) {
    for (int entry = 0; entry < AdvLogSize; entry++)
    {
        AdvLog[entry] = " ";
    }
};

void ShiftAdvLogEntriesDown(void) {
    for (int entry = (AdvLogSize - 1); entry > 0; entry--)
    {
        AdvLog[entry] = AdvLog[entry - 1];
    }
};

void UpdateAdvLog(const char* entry) {
    ShiftAdvLogEntriesDown();

    AdvLog[0] = entry;
};

void LogTest(void) {
    PopAdvLog();

    UpdateAdvLog("Test 01");
    UpdateAdvLog("Test 02");

    printf(AdvLog[0]);
    printf("\n");
    printf(AdvLog[1]);
    printf("\n");
};