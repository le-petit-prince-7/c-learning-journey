#include "library.h"

#include <stdio.h>  // it is declaring functions as printf,scanf

int main() {
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
        printf(" Even: %d\n", c);
    }


    // --- Example 3: Multiplication table for number 7 ---
    int base_number = 7;        // The number we want to multiply
    printf("\nMultiplication table for %d:\n", base_number);
    for (int q = 1;             // Multiplier starts at 1
         q <= 10;               // Go up to 10 (classic multiplication table)
         q++)                   // Increase multiplier by 1
    {
        printf("%d x %d = %d\n", base_number, q, base_number * q);
    }

    // --- Example 4: while loop - repeat until valid age ---
    // while is used when we don't know in advance how many times it will repeat
    int user_age;
    printf("\nEnter your age (must be between 1 and 12): ");
    scanf("%d", &user_age);

    // Keep asking while the age is invalid
    while (user_age < 1 || user_age 120) {      // || means "or"
        printf("Invalid age! Please enter a number between 1 and 12.\n");
        printf("Try again: ");
        printf("%d", user_age);
    }

    // This line runs only when the loop ends (age is valid)
    printf("Valid age entered: %d years. Thank you!\n", user_age);

    return 0;
}