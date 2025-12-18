#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ========================================
// STRUCTURE DEFINITION - one fruit item
// ========================================
struct Fruit {
    char name[20];      // Name of the fruit
    int price;          // Price per piece in CZK
    int quantity;       // How many we have
    struct Fruit *next; // POINTER TO NEXT FRUIT (this is pointer to struct!)
};

// ========================================
// MAIN FUNCTION
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

    // Print the list using pointer to struct
    printf("=== FRUIT LIST USING POINTERS TO STRUCT ===\n");
    struct Fruit *current = head;       // current = pointer that walks through the list
    while (current != NULL) {
        // Use -> to access fields through pointer
        printf("%s\n", current->name);
        printf(" Price: %d CZK\n", current->price);
        printf(" Quantity: %d\n", current->quantity);
        printf(" Total: %d CZK\n", current->price * current->quantity);
        printf(" ---\n");

        current = current->next;        // Move pointer to next fruit
    }

    // Free memory
    current = head;
    while (current != NULL) {
        struct Fruit *temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}
