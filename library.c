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
    // When i becomes 11, condition i <= 10 is false → loop ends

    // --- Example 2: for loop - even numbers from 2 to 20 ---
    printf("\nEven numbers from 2 to 20:\n");
    for (int c = 2;     // Start at 2
         c <= 20;       // Continue while i <= 20
         c += 2)        // Increase i by 2 each time (skip odd numbers)
    {
        printf(" Even: %d\n", i);
    }


    return 0;
