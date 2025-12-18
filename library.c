#include <stdio.h>     // For printf
#include <stdlib.h>    // For malloc and free
#include <string.h>    // For strcpy (safe string copying)

// ========================================
// STRUCTURE DEFINITION - blueprint for one fruit item
// ========================================
struct Fruit {
    char name[20];          // Name of the fruit (max 19 chars + '\0')
    int price;              // Price in CZK per piece
    int quantity;           // How many pieces we have
    struct Fruit* next;     // Pointer to the next fruit in the list
                            // NULL = this is the last fruit
};

// ========================================
// MAIN FUNCTION - program starts here
// ========================================
int main() {
    struct Fruit *head  = NULL;     //// Pointer to first fruit - list is empty at start

    // Create first fruit (Apple)
    struct Fruit *apple = malloc(sizeof(struct Fruit));
    if (apple == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    strcpy(apple->name, "Apple");       // Copy string safely
    apple->price = 15;
    apple->quantity = 5;
    apple->next = NULL;     // No next fruit yet
    head = apple;           // Head points to an apple

    // Create second fruit (Pear) and link it
    struct Fruit *pear = malloc(sizeof(struct Fruit));
    if (pear == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    strcpy(pear->name, "Pear");
    pear->price = 20;
    pear->quantity = 12
    pear->next = NULL
    apple->next = pear;     // Apple now points to pear

    // Create third fruit (Banana) and link it
    struct Fruit *banana = malloc(sizeof(struct Fruit));
    if (banana == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    strcpy(banana->name, "Banana");
    banana->price = 25;
    banana->quantity = 21;
    banana->next = NULL
    pear->next = banana;        // Pear now points to banana

    

}