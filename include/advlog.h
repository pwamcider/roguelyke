#pragma once

#define NumEntries 10
#define EntryLength 64

// ------------------------------------------------------------

extern char AdvLog[NumEntries][EntryLength];

// Prototypes
// ------------------------------------------------------------

void ClearAdvLog(void);
void LogTest(void);
void ShiftEntriesDown(void);
void UpdateAdvLog(const char* entry);