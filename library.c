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


    printf("Age: %d years\n", age); // \n new line, %d is used for int
    printf("Height: %.2f m\n", height); // %2.f = 2 decimal number
    printf("Letter: %c\n", letter); // %c is used for char
    printf("pi number: %.11f\n", pi);

   // Second part: fruit price calculation

    int apples = 5; //Number of apples
    int pears = 3; //Number of pears
    float price_per_apple = 15.50; // Price per apple in CZK
    float price_per_pears = 20.00; // Price per pears in CZK

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