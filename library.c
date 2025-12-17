#include "library.h"

#include <stdio.h> // it is declaring functions as printf,scanf

// --- Loops demonstration ---
    printf("\n=== LOOPS DEMONSTRATION ===\n");

    // --- Example 1: for loop - counting from 1 to 10 ---
    // for (initialization; condition; increment)
    printf("\nCounting from 1 to 10:\n");
    for (int i = 1;     // 1. Start: create variable i and set it to 1 (runs only once)
         i <=10;        // 2. Condition: continue as long as i is less than or equal to 10
         i++)           // 3. After each loop: increase i by 1 (i++ means i = i + 1)
        {
            printf(" Number: %d\n", i);  // Body of the loop - this runs 10 times
    }

    return 0;
