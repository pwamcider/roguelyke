#include "advlog.h"
#include "stdio.h"
#include "string.h"

// ------------------------------------------------------------

char AdvLog[NumEntries][EntryLength];

void ClearAdvLog(void) {
    for (int entry = 0; entry < NumEntries; entry++)
    {
        for (int pos = 0; pos < EntryLength; pos++)
        {
            AdvLog[entry][pos] = 0;
        }   
    }
};

void ShiftEntriesDown(void) {
    for (int entry = (NumEntries - 1); entry > 0; entry--)
    {
        strncpy(AdvLog[entry], AdvLog[entry - 1], sizeof(AdvLog[entry]));
    }
};

void UpdateAdvLog(const char* entry) {
    ShiftEntriesDown();

    snprintf(AdvLog[0], sizeof(AdvLog[0]), entry);
};

void LogTest(void) {
    ClearAdvLog();

    UpdateAdvLog("Hit 1!");
    UpdateAdvLog("Hit 2!!");
    UpdateAdvLog("Hit 3!!!");
    UpdateAdvLog("CRITICAL HIT!!!!");

    char bonus[] = "You defeat the slime! Great job!";

    UpdateAdvLog(bonus);

    for (int entry = 0; entry < NumEntries; entry++)
    {
        printf("%s\n", AdvLog[entry]);
    }
};