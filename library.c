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

    // Add some fruits manually
    add_fruit(&shopping_list, "Apple", 15, 5);
    add_fruit(&shopping_list, "Banana", 12, 10);
    add_fruit(&shopping_list, "Orange", 30, 3);

    printf("=== CURRENT SHOPPING LIST ===\n");
    print_list(shopping_list);

    // Save to file
    save_to_file(shopping_list, "my_fruit_list.txt");
    printf("\nList saved to 'my_fruit_list.txt'\n");

    // Free current list
    free_list(shopping_list);
    shopping_list = NULL;

    // Load from file
    printf("\n=== LOADING FROM FILE ===\n");
    shopping_list = load_from_file("my_fruit_list.txt");

    if (shopping_list == NULL) {
        printf(" No data loaded (file empty or error)\n");
    } else {
        print_list(shopping_list);
    }

    // Clean up
    free_list(shopping_list);

    return 0;
}

// ========================================
// FUNCTIONS IMPLEMENTATION
// ========================================

// Add new fruit to the beginning of the list
void add_fruit(struct Fruit **head, const char *name, int price, int quantity) {
    struct Fruit *new_fruit = malloc(sizeof(struct Fruit));
    if (new_fruit == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(new_fruit->name, name);
    new_fruit->price = price;
    new_fruit->quantity = quantity;
    new_fruit->next = *head;            // New fruit points to old head
    *head = new_fruit;                  // Head now points to new fruit
}

// Print all fruits in the list
void print_list(struct Fruit *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Fruit* current = head;
    while (current != NULL) {
        printf("%s - %d CZK x %d = %d CZK total\n",
            current->name, current->price, current->quantity,
            current->price *current->quantity);
        current = current->next;
    }
}

// Save entire list to text file (one fruit per line: name,price,quantity)
void save_to_file(struct Fruit *head, const char *filename) {
    FILE *file = fopen(filename, "w");      // "w" = write mode (overwrite)
    if (file == NULL) {
        printf("Error opening file for writing\n");
        return;
    }

    struct Fruit* current = head;
    while (current != NULL) {
        fprintf(file, "%s,%d,%d\n", current->name, current->price, current->quantity);
        current = current->next;
    }
    fclose(file);
}

// Load list from file and rebuild linked list
struct Fruit* load_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");      // "r" = read mode
    if (file == NULL) {
        printf("Error opening file for reading(file may not exist).\n");
        return NULL;
    }

    struct Fruit* head = NULL;
    char line[100];
    char name[20];
    int price, quantity;

    while (fgets(line, sizeof(line), file)) {
        // Parse line: name, price, quantity
        if (sscanf(line, "%19[^,],%d,%d", name, &price, &quantity) == 3) {
            add_fruit(&head, name, price, quantity);
        }
    }

    fclose(file);
    return head;
 }

// Free all nodes to prevent memory leak
void free_list(struct Fruit *head) {
    struct Fruit* current = head;
    while (current != NULL) {
        struct Fruit *temp = current;
        current = current->next;
        free(temp);
    }
}

/*
* FULL PROGRAM EXPLANATION - LIKE A TEXTBOOK FOR COMPLETE BEGINNERS
*
* This comment explains EVERYTHING in the code in detail – what it does, how it works, why it's there, and the output.
* Read it like a textbook: from top to bottom. It's written so even if you open this file in 14 days (or a year), or if you're a total beginner, you'll understand every word, line, and concept.
* We'll use simple words, analogies (like a shopping list or chain of friends), and step-by-step breakdowns.
*
* ========================================
* WHAT IS THE PROGRAM'S PURPOSE?
* ========================================
* This program creates a dynamic shopping list of fruits using a linked list (a chain of items).
* Each fruit is a "struct" (custom data type) with name, price, quantity.
* It does 4 main things:
*   1. Add fruits to the list (manually in code)
*   2. Print the list with total values
*   3. Save the list to a text file (persistent storage – data survives program end)
*   4. Load the list back from the file and print it again
*
* Why is this useful?
*   - Real programs need to save/load data (e.g., shopping app, game save, database)
*   - Linked list allows unlimited items (add as many as you want at runtime)
*   - Struct groups related info (name + price + quantity = one "fruit object")
*
 * ========================================
 * EXPECTED OUTPUT (what you see when running the program)
 * ========================================
 * The output changes based on your fruits, but here's what happens for the code's default fruits (Apple 15/5, Banana 12/10, Orange 30/3):
 *
 * === CURRENT SHOPPING LIST ===
 * Apple - 15 CZK x 5 = 75 CZK total
 * Banana - 12 CZK x 10 = 120 CZK total
 * Orange - 30 CZK x 3 = 90 CZK total
 *
 * List saved to 'my_fruit_list.txt'
 *
 * === LOADING FROM FILE ===
 * Apple - 15 CZK x 5 = 75 CZK total
 * Banana - 12 CZK x 10 = 120 CZK total
 * Orange - 30 CZK x 3 = 90 CZK total
 *
 * Explanation of output:
 *   - First part: prints the list we created in memory
 *   - Saves to file (creates "my_fruit_list.txt" on your disk with "Apple,15,5\nBanana,12,10\nOrange,30,3\n")
 *   - Frees memory and loads back from file
 *   - Prints the loaded list (same as first, proving it saved/loaded correctly)
 *   - If file empty or missing: "No data loaded"
 *
 * ========================================
 * NEW CONCEPTS EXPLAINED LIKE A TEXTBOOK FOR ABSOLUTE BEGINNERS
 * ========================================
 * We'll explain EVERY new thing, word by word, with analogies.
 * Assume you're new to programming – we'll start from zero.
 *
 * 1. struct Fruit { ... }
 *    - "struct" = structure = custom data type you create
 *    - Like a box that holds multiple things together
 *    - Analogy: A fruit basket with slots for name, price, quantity, and a chain to next basket
 *    - char name[20] = slot for text (name), max 19 letters + special end mark '\0'
 *    - int price = slot for whole number (price)
 *    - int quantity = slot for another whole number (how many)
 *    - struct Fruit *next = slot for address (pointer) to another fruit basket
 *      * = this is a pointer (arrow to memory location)
 *      next = name of the field
 *      Why? To connect fruits into a chain (linked list)
 *
 * 2. Function prototypes (e.g. void add_fruit(struct Fruit **head, ...))
 *    - Prototypes = "preview" or "menu" of functions
 *    - Tell compiler: "These functions exist below, so let me call them now"
 *    - Without prototypes, compiler complains if you call function before defining it
 *    - void = function returns nothing (no value back)
 *    - struct Fruit **head = pointer to pointer (double *) – allows changing the head inside function
 *      ** = pointer to pointer (like arrow to arrow – needed to modify original head)
 *    - const char *name = pointer to string (name won't be changed inside function)
 *    - int price, int quantity = normal integer parameters
 *
 * 3. add_fruit function
 *    - Adds new fruit to the start of the list
 *    - malloc(sizeof(struct Fruit)) = ask system for memory to hold one fruit
 *      malloc = memory allocate = "give me a block of memory"
 *      sizeof = calculate how many bytes the struct needs
 *    - strcpy = safe copy string from name to new_fruit->name
 *      Why strcpy? You can't do new_fruit->name = name (arrays need copying)
 *    - new_fruit->next = *head = link new fruit to old first fruit
 *    - *head = new_fruit = update head to point to new fruit (now first in list)
 *
 * 4. print_list function
 *    - Walks through the list and prints each fruit
 *    - if (head == NULL) = check if list is empty
 *    - while (current != NULL) = loop until end of list
 *    - printf with calculation = show name, price x quantity = total
 *    - current = current->next = move to next fruit
 *
 * 5. save_to_file function
 *    - Opens file in "w" mode (write/overwrite)
 *    - Loops through list
 *    - fprintf = like printf, but writes to file instead of screen
 *    - "%s,%d,%d\n" = format: name,comma,price,comma,quantity,newline
 *    - fclose = close file (important – frees resources)
 *
 * 6. load_from_file function
 *    - Opens file in "r" mode (read)
 *    - fgets = read one line from file into buffer line
 *    - sscanf = parse (extract) from line: name up to comma, then int, then int
 *      %19[^,] = read max 19 chars until comma
 *      == 3 = check if parsed exactly 3 items
 *    - add_fruit = add parsed fruit to list
 *
 * 7. free_list function
 *    - Frees all memory allocated by malloc
 *    - Loop through list
 *    - temp = remember current
 *    - Move to next
 *    - free(temp) = return memory to system
 *    - Why? Prevent memory leak (program using more and more memory over time)
 *
 * This program combines structs, linked lists, pointers, malloc/free, and file I/O
 * – all core C concepts for real-world apps like shopping carts, databases, games.
 */