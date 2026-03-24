#pragma once

#define AdvLogSize 10

// ------------------------------------------------------------

extern const char* AdvLog[AdvLogSize];

// Prototypes
// ------------------------------------------------------------

void LogTest(void);
void PopAdvLog(void);
void ShiftAdvLogEntriesDown(void);
void UpdateAdvLog(const char* entry);