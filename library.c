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

    printf("=== CURRENT SHOPPING LIST===\n");
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
        printf("%s - %d = %d CZK total\n",
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
        print_list("Error opening file for reading(file may not exist).\n");
        return NULL;
    }

    struct Fruit* head = NULL;
    char line[100];
    char name[20];
    int price, quantity;

    while (fgets(line, sizeof(line), file));
        // Parse line: name, price, quantity
        if (sscanf(line, "%19[^,],%d,%d", name, &price, &quantity) == 3) {
            add_fruit(&head, name, price, quantity);
        }
    }

    fclose(file);
    return head;
 }

// Free al nodes to prevent memory leak
void free_list(struct Fruit *head) {
    struct Fruit* current = head;
    while (current != NULL) {
        struct Fruit *temp = current;
        current = current->next;
        free(temp);
    }
}