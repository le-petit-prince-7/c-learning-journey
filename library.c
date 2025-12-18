#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ========================================
// STRUCTURE DEFINITION - one fruit item
// ========================================
int main() {
    struct Fruit *head = NULL;  // Pointer to first fruit - list starts empty

    // Create first fruit using malloc
    struct Fruit *apple = malloc(sizeof(struct Fruit));
    if (apple == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Fill the fields using -> operat (arrow)
    // -> "go to the address this pointer points to, then access the field"
    strcpy(apple->name, "Apple");
    apple->price = 15;
    apple->quantity = 5;
    apple->next = NULL;     // NO next fruit yet

    head = apple;           // Head now points to apple

    // Create second fruit and link it
    struct Fruit *banana = malloc(sizeof(struct Fruit));
    if (banana == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    strcpy(banana->name, "Banana");
    banana->price = 15;
    banana->quantity = 200;
    banana->next = NULL;

    apple->next = banana;       // apples next field now points to banana
    
}
