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

    // Find maxium and minimum price
    int max_price = fruit_prices[0];
    int min_price = fruit_prices[0];
    for (int i = 1; i < size; i++) {
        if (fruit_prices[i] > max_price) {
            max_price = fruit_prices[i];
        }
        if (fruit_prices[i] < min_price) {
            min_price = fruit_prices[i];
        }
    }

    // Final summary
    printf("\n--- Summary ---\n");
    printf("Total sum of all fruits: %d CZK\n",total_sum);
    printf("Avarage price: %.2f CZK\n", avarage);
    printf("Most expensive fruit: %d CZK\n",max_price);
    printf("Cheapest fruit: %d CZK\n", min_price);

    // Bonus: count fruits more expensive than 20 CZK
    int expenive_count = 0;
    for (int i = 0; i < size; i++) {
        if (fruit_prices[i] > 20) {
            expenive_count++;
        }
    }

    printf("Number of fruits more expensive than 20 CZK: %d\n", expenive_count);
    return 0;
}