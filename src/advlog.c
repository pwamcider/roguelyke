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
        snprintf(AdvLog[entry], sizeof(AdvLog[entry]), AdvLog[entry - 1]);
    }
};

void LogTest(void) {
    ClearAdvLog();

    char entry[] = "HIT 1!";
    char entry2[] = "HIT 2!";
    char entry3[] = "HIT 3!";

    snprintf(AdvLog[0], sizeof(AdvLog[0]), entry);
    snprintf(AdvLog[1], sizeof(AdvLog[1]), entry2);
    snprintf(AdvLog[2], sizeof(AdvLog[2]), entry3);

    ShiftEntriesDown();

    char entry4[] = "HIT 4!";

    snprintf(AdvLog[0], sizeof(AdvLog[0]), entry4);

    printf(AdvLog[0]);
    printf("\n");
    printf(AdvLog[1]);
    printf("\n");
    printf(AdvLog[2]);
    printf("\n");
    printf(AdvLog[3]);
    printf("\n");
};

/*
void UpdateAdvLog(const char* entry) {
    ShiftAdvLogEntriesDown();

    AdvLog[0] = entry;
};

*/