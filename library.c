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
    

    return 0;
}