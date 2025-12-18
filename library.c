#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ========================================
// STRUCTURE FOR ONE FRUIT ITEM
// ========================================
struct Fruit {
    char name [20];     // Fruit name
    int price;          // Price per piece in CZK
    int quantity;       // How many we have
    struct Fruit* next;     // Pointer to next fruit in list
};