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

// ========================================
// FUNCTION PROTOTYPES
// ========================================
void add_fruit(struct Fruit** head, const char *name, int price, int quantity);
void print_list(struct Fruit* head);
void save_to_file(struct Fruit* head, const char *filename);
struct Fruit* load_from_file(const char *filename);
void free_list(struct Fruit* head);

int main() {
    struct Fruit* shopping_list = NULL;     // Start with empty list
}