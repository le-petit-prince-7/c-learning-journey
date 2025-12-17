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
    char fruit_names[6][20] = {     // 6 fruits, each name max 19 chars
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
    int total_sum = 0;
    for (int i = 0; i < size; i++) {
        total_sum += fruit_prices[i];
    }

    // Calculate avarage price
    float avarage = (float)total_sum / size;
    // Cast total_sum to float to get decimal result in division
    // Without cast: 110 / 6 = 18 (integer division, decimal part lost)
    // With cast:     110.0 / 6 = 18.333...


    // Find maxium and minimum price
    int max_price = fruit_prices[0];        // Start assuming first price is highest
    int min_price = fruit_prices[0];        // Start assuming first price is lowest
    for (int i = 1; i < size; i++) {        // Loop through remaining elements
        if (fruit_prices[i] > max_price) {      // If current price is higher than current max
            max_price = fruit_prices[i];    // Found a new higher price → update
        }
        if (fruit_prices[i] < min_price) {      // If current price is lower than current min
            min_price = fruit_prices[i];        // Found a new lower price → update
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