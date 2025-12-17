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