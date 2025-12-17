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

    // Greetign

    print_greeting();

    // --- Input personal data from user ----
    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter you height: ");
    scanf("%f", &height);

    printf("Enter your first initial: ");
    scanf("%c", &initial); // Space before %c skips leftover newline

    // --- Input fruit quantities ---
    printf("\nNow lets calculate fruit price.\n");
    printf("How many apples did you buy? ");
    scanf("%d", &apples);

    printf("How many pear did you buy? ");
    scanf("%d", &pears);

    // --- Calculations ---
    float total_apples = apples * price_per_apple;
    float total_pears = pears * price_per_pears;
    float total_price = total_apples + total_pears;




  

    return 0;
}