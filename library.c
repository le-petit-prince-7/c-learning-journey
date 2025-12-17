#include "library.h"

#include <stdio.h> // it is declaring functions as printf,scanf

void hello(void) {
    printf("Hello there!\n"); //printf is used for printing the text
}

int main() {
    int age =25;
    float height =1.75;
    char letter = 'J';
    double pi = 3.14159265;

    printf("Age: %d\n let\n", age);
    printf("Height: %.2f m\n", height);
    printf("Letter: %c\n", letter);
    printf("pi number: %.11f\n", pi);

    return 0;

}