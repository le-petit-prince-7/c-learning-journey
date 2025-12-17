#include <stdio.h> // it is declaring functions as printf,scanf

// ========================================
// WHY POINTERS ARE NEEDED IN FUNCTIONS
// Explanation for complete beginners
// ========================================

// Function: doubles the value of a number
// Parameter: int *p = pointer to an integer
// Why pointer? Because in C, function parameters are passed by value (copy)
// Without pointer, the function would only change its own local copy
// With pointer, we get the memory address → we can change the original variable

void double_value(int *p) {     // p is a pointer - it holds a memory address
    *p = *p * 2;                // *p = dereference = "value at the address p points to"
                                // This line changes the original variable in main()
    printf("Inside function: value at p = %d\n", *p);
    // Note: we could also write printf("Doubled value: %d\n", *p);
}

int main() {
    int number = 10;        // Normal variable - stored somewhere in memory

    printf("Before function: number = %d\n", number);       // Output: 10

    // Call the function and pass the ADDRESS of number
    // &number = "address of" number
    // Without &, we would pass only a copy (value 10) → original wouldn't change
    double_value(&number);

    // Now the original variable has been changed through the pointer
    printf("After function: number = %d\n", number);       // Output: 20!

    return 0;       // Program ended successfully
}