#include "library.h"

#include <stdio.h>

// Constant - number of fruits in our list
// Using #define makes it easy to change size in one place
#define SIZE 6 // Array size constant

// ========================================
// FUNCTION PROTOTYPES (declarations)
// These tell the compiler: "These functions exist somewhere below"
// So we can call them from main() before they are defined
// ========================================

// void = this function returns nothing
// const = promises we won't change the arrays inside the function
void print_fruit_list(const char names [][20], const int prices[], int size);

// int = this function returns an integer (the sum)
int calculate_sum(const int prices[], int size);

// float = this function returns a decimal number (average)
float calculate_average(int sum, int size);

// These two functions return the highest/lowest price
int find_max_price(const int prices[], int size);
int find_min_price(const int prices[], int size);


// ========================================
// MAIN FUNCTION - starting point of every C program
// ========================================
int main() {
    // 1D array: prices of 6 fruits in CZK
    int fruit_prices[SIZE] = {15, 20, 90, 30, 2, 22};
    // Index:                  0   1   2   3  4   5

    // 2D array: names of fruits
    // 6 rows (fruits), each row max 20 characters (including \0 at the end)
    char fruit_names[SIZE][20] = {
        "Apple",
        "Pear",
        "Banana",
        "Orange",
        "Strawberry",
        "Kiwi"
    };

    // Title of the program
    printf("=== FRUIT SHOP - FUNCSTIONS VERSION ===\n");

    // Call our custom functions
    // We pass arrays and size - functions will do the work
    print_fruit_list(fruit_names, fruit_prices, SIZE);

    // Get sum from function and store it in variable
    int total = calculate_sum(fruit_prices, SIZE);

    // Get average using the sum we already have
    float avg = calculate_average(total, SIZE);

    // Print summary
    printf("\n--- Summary ---\n");
    printf("Total sum: %d CZK\n",total);
    printf("Average price: %.2f CZK\n", avg);
    printf("Most expensive: %d CZK\n",find_max_price(fruit_prices, SIZE));
    printf("Cheapest: %d CZK\n", find_min_price(fruit_prices, SIZE));


    return 0;   // Tell operating system: program ended successfully
}

// ========================================
// FUNCTION DEFINITIONS (implementation)
// ========================================

// Function: prints a numbered list of fruits with their prices
// void = returns nothing (just prints)
// const char names[][20] = 2D array of characters (names), we won't modify it
// const int prices[] = 1D array of integers (prices), we won't modify it
// int size = how many fruits we have
void print_fruit_list(const char names[][20], const int prices[],int size) {
    printf("\nFruit List:\n");
    for (int i = 0; i < size; i++) {
        // i + 1 = show numbers starting from 1 (humans like 1,2,3... not 0,1,2...)
        // names[i] = whole name at position i
        // prices[i] = price at same position
        printf("%d. %s: %d CZK\n", i + 1, names[i],prices[i]);
    }
}

// Function: adds up all prices in the array
// Returns the total sum as integer
int calculate_sum(const int prices[], int size) {
    int sum = 0;    // Start with zero
    for (int i = 0; i < size; i++) {
        sum += prices[i];       // Add current price to running total
    }
    return sum;     // Give the result back to whoever called this function
}

// Function: calculates average price from sum and count
// We pass sum (already calculated) to avoid calculating it twice

float calculate_average(int sum, int size) {
    // (float)sum = convert integer to float so division gives decimal result
    // Without cast: 110 / 6 = 18 (integer division drops decimal part)
    // With cast:     110.0 / 6 = 18.333...
    return (float)sum/size;     // Cast to float for decimal result
}

// Function: finds highest price in array
// Returns: the maximum value

int find_max_price(const int prices[], int size) {
    int max = prices[0];        // Assume first price is the highest at the beginning
    for (int i = 1; i < size; i++) {    // Start from second element
        if (prices[i] > max) {          // If we find a higher price
            max = prices[i];            // Update if current is higher
        }
    }
    return max;     // Return the highest price found
}

// Function: finds lowest price in array
// Returns: the minimum value
int find_min_price(const int prices[], int size) {
    int min = prices[0];        // Assume first price is the lowest at the beginning
    for (int i = 1; i < size; i++) {
        if (prices[i] < min) {      // If we find a lower price
            min = prices[i];        // Update if current is lower
        }
    }
    return min;     // Return the lowest price found
}