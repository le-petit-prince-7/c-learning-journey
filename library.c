#include "library.h"

#include <stdio.h> // it is declaring functions as printf,scanf

// Optional function - we will call it from main
void print_greeting(void) {
    printf("Hello there! Welcome to the program. \n\n"); // Print greeting with newline
}

int main() {
    // === LOOPS AND ARRAYS - FINAL DEMO ===
    printf("\n=== LOOPS AND ARRAYS - FINAL DEMO ===\n");

    // 1D array: fruit prices in CZK
    int fruit_prices[6] = {15, 20, 12, 30, 9, 25};
    int size = 6;       // Array size

    // 2D array: fruit names (6 fruits, max 20 characters each)
    char fruit_names[6][20] = {
        "Apple",
        "Pear",
        "Banana",
        "Oranga",
        "Strawberry",
        "Kiwi"
    };


    // Print complete list with names and prices
    printf("\nComplete fruit list:\n");
    for (int i = 0; i < size; i++) {
        // i + 1 = human-readable position (1 to 6)
        // fruit_names[i] = name at index i
        // fruit_prices[i] = price at same index
        printf("%d. %s: %d CZK\n", i, fruit_names[i], fruit_prices[i]);
    }

    // Calculate total sum
    int total_sum = O;
    for (int i = 0; i < size; i++) {
        total_sum += fruit_prices[i];
    }

    // Calculate avarage price
    float avarage = (float)total_sum / size;

    
    return 0;
}