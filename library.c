#include "library.h"
#include <stdio.h>

#define SIZE 6 // Array size constant

// Function prototypes (declarations) - tell compiler these functions exist
void print_fruit_list(const char names [][20], const int prices[], int size);
int calculate_sum(const int prices[], int size);
float calculate_avarage(int sum, int size);
int find_max_price(const int prices[], int size);
int fin_min_price(conts int prices[], int size);

int main() {
    // Arrays with data
    int fruit_prices[SIZE] = {15, 20, 90, 30, 2, 22};

    char fruit_names[SIZE][20] = {
        "Apple","Pear", "Banana", "Orange", "Strawberry", "Kiwi"
    };

    return 0;
}