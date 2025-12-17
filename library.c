#include "library.h"

#include <stdio.h> // it is declaring functions as printf,scanf

void hello(void) {
    printf("Hello there! \n"); //printf is used for printing the text
}

int main() {
    int age = 25;
    float height = 1.75;
    char letter = 'J';
    double pi = 3.14159265;

    printf("Age: %d years\n", age); // \n new line, %d is used for int
    printf("Height: %.2f m\n", height); // %2.f = 2 decimal number
    printf("Letter: %c\n", letter); // %c is used for char
    printf("pi number: %.11f\n", pi);

    return 0;

}