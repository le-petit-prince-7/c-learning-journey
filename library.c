#include "library.h"

#include <stdio.h> // it is declaring functions as printf,scanf

// Optional function - we will call it from main
void print_greeting(void) {
    printf("Hello there! Welcome to the program. \n\n"); // Print greeting with newline
}

int main() {
    //Variables for personal data
    int age ;
    float height;
    char initial;

    // Variables for fruit shopping
    int apples;
    int pears;
    float price_per_apple; // Price per apple in CZK
    float price_per_pears; // Price per pear in CZK

    //Calculate total price for each fruit

    float total_apples = apples * price_per_apple;
    float total_pears = pears * price_per_pears;

    // Calculate overall total price
    float total_price = total_apples + total_pears;

    // Print results
    printf("Apples: %d pcs, price per apple: %.2f CZK\n", apples, price_per_apple);
    printf("Pears: %d pcs. price per pear: %.2f CZK\n", pears, price_per_pears);
    printf("Total price for apples %.2f CZK\n", total_apples);
    printf("Total price for pears: %.2f CZK\n", total_pears);
    printf("---------------------------------\n");
    printf("overall total: %.2f CZK\n", total_price);

    return 0;
}