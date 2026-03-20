#include "advlog.h"

// TODO - temp
#include "stdio.h"

// ------------------------------------------------------------

const char* AdvLog[10];

void LogTest(void) {
    AdvLog[0] = "Test0";

    printf(AdvLog[0]);
};