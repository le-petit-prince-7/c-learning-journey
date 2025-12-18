#include <stdio.h>     // For printf and scanf
#include <stdlib.h>    // For malloc and free

int main() {
    int n; // Variable to store the size (user will enter it)

    // Ask user to store the size (user will enter it)
    printf("Enter the number of elements");
    scanf("%d", &n);

    // Allocate dynamic array using malloc
    // int *dyn_array = pointer to int (will point to the array)
    // malloc(n * sizeof(int)) = allocate memory for n integers
    // sizeof(int) = size of one int in bytes (usually 4)
    // malloc returns pointer to the memory, or NULL if failed
    int *dyn_array = malloc(n * sizeof(int));

    // Always check if malloc succeeded
    if (dyn_array == NULL) {
        printf("Memory allocation failed\n");
        return 1;       // Exit program with error
    }

    // Fill the array with values from user
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &dyn_array[i]);     // Use like normal array
    }

    // Print the array
    printf("You entered:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", dyn_array[i]);
    }
    printf("\n");

    // Always free the memory when done
    // free(dyn_array) = release the allocated memory back to the system
    // After free, don't use dyn_array anymore!
    free(dyn_array);
    return 0;
}

/*
 * DYNAMIC ARRAY WITH MALLOC - COMPLETE BEGINNER EXPLANATION
 *
 * What is this code for?
 * This program demonstrates how to create an array whose size is decided at runtime
 * (when the program is running), not at compile time.
 *
 * Why is this useful?
 * In real programs, you often don't know in advance how many items the user will enter
 * (e.g., reading numbers from a file, processing user input, etc.).
 * Normal arrays like int arr[10]; have fixed size – you must know the size when writing the code.
 * With malloc, you can ask the user for the size and create exactly the right amount of space.
 *
 * Key concepts used:
 * - malloc()   → asks the operating system for memory on the heap
 * - sizeof()   → calculates how many bytes one int needs
 * - Pointer    → dyn_array is a pointer that points to the first element of the allocated memory
 * - free()     → returns the memory back to the system (very important to avoid memory leaks!)
 * - NULL check → safety: if malloc fails (no memory left), we handle the error
 *
 * Step-by-step what happens:
 * 1. Ask user how many numbers they want to enter
 * 2. Use malloc to allocate exactly n * sizeof(int) bytes of memory
 * 3. Fill the allocated memory with numbers from user (using dyn_array[i] like normal array)
 * 4. Print all entered numbers
 * 5. Free the memory – give it back to the system
 *
 * This is a fundamental technique in C for working with flexible-size data.
 * Almost every non-trivial C program uses malloc/free somewhere.
 */