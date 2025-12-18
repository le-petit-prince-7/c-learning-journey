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
}