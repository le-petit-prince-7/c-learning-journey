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