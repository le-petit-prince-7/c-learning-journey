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

/*
 * POINTERS TO STRUCTURES - FULL EXPLANATION FOR COMPLETE BEGINNERS
 * (So you understand everything even if you open this file in 14 days or later)
 *
 * What does this program do?
 * This program creates a simple linked list of fruits using structures and pointers to structures.
 * It shows how to:
 *   - Define a struct with a pointer to the same type (self-referential struct)
 *   - Use malloc to create nodes dynamically
 *   - Access struct fields through pointers using the -> operator
 *   - Link nodes together to form a chain
 *   - Traverse the chain and print data
 *   - Free all allocated memory
 *
 * Why is this important in real programming?
 * Pointers to structures are the foundation of dynamic data structures in C.
 * Almost every non-trivial C program uses them.
 *
 * Real-world uses:
 *   - Game development: linked list of game objects (enemies, bullets, items)
 *   - Operating systems: process list, file descriptors, memory management
 *   - Databases: in-memory indexes, B-trees
 *   - Network programming: packet queues
 *   - Embedded systems: device lists, sensor data chains
 *   - Any program that needs flexible, growable lists of complex objects
 *
 * Key concepts explained:
 *   - struct Fruit *next = pointer to another Fruit struct
 *     → this is what makes the "link" in linked list
 *   - -> operator = "arrow" = shortcut for (*pointer).field
 *     → used when you have a pointer to a struct
 *     Example: current->name is same as (*current).name
 *   - head = pointer to first fruit (entrance to the whole list)
 *   - current = temporary pointer we move along the list to visit each fruit
 *
 * Analogy for beginners:
 *   - Each fruit = a box with name, price, quantity, and a sticky note saying "next box is..."
 *   - head = the address of the first box
 *   - current = your hand pointing to the current box while you walk through the row
 *   - When you reach a box with "next box = none" (NULL) → end of list
 *
 * This pattern (struct with data + pointer to same struct) is used in millions of real programs.
 * Mastering it means you can build complex, dynamic data structures like trees, graphs, queues.
 */