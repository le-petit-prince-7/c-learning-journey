#include "library.h"
#include <stdio.h>

#define SIZE 6 // Array size constant

// Function prototypes (declarations) - tell compiler these functions exist
void print_fruit_list(const char names [][20], const int prices[], int size);
int calculate_sum(const int prices[], int size);
float calculate_avarage(int sum, int size);
int find_max_price(const int prices[], int size);
int find_min_price(conts int prices[], int size);

int main() {
    // Arrays with data
    int fruit_prices[SIZE] = {15, 20, 90, 30, 2, 22};

    char fruit_names[SIZE][20] = {
        "Apple","Pear", "Banana", "Orange", "Strawberry", "Kiwi"
    };

    printf("=== FRUIT SHOP - FUNCSTIONS VERSION ===\n");

    // Call functions - main only coordinates, doesnt do calculations itself
    print_fruit_list(fruit_names, fruit_prices, SIZE);

    int total = calculate_sum(fruit_prices, SIZE);
    float avg = calculate_avarage(total, SIZE);

    printf("\n--- Summary ---\n");
    printf("Total sum: %d CZK\n",total);
    printf("Avarage price: %.2f CZK\n", avg);
    printf("Most expensive: %d CZK\n",find_max_price(fruit_prices, SIZE));
    printf("Cheapest: %d CZK\n", find_min_price(fruit_prices, SIZE));


    return 0;
}

// Function: prints numbered list of fruits with prices
// Parameters: names and prices arrays, size of arrays
// Why const? Arrays are not modified inside this function
void print_fruit_list(const char[] [20], const int prices[],int size) {
    printf("\nFruit List:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s: %d CZK\n", i + 1, names[i],prices[i])
    }
}

// Function: calculates sum of all prices in array
// Returns: integer sum
int calculate_sum(const int prices[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += prices[i];       // Add each price to sum
    }
    return sum;     // Return the result to caller
}

// Function: calculates average from already calculated sum
// Why separate? Reusability and clarity

float calculate_avarage(int sum, int size) {
    return (float)sum/size;     // Cast to float for decimal result
}

// Function: finds highest price in array
// Returns: the maximum value

int find_max_price(const int prices[], int size) {
    int max = prices[0];        // Start with first element
    for (int i = 1; i < size; i++) {
        if (prices[i] > max) {
            max = prices[i];    // Update if current is higher
        }
    }
    return max;
}

// Function: finds lowest price in array
// Returns: the minimum value
int find_min_price(const int prices[], int size) {
    int min = prices[0];        // Start with first element
    for (int i = 1; i < size; i++) {
        if (prices[i] < min) {
            min = prices[i];        // Update if current is lower
        }
    }
    return min;
}