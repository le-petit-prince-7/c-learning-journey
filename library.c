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
    pear->quantity = 12;
    pear->next = NULL;
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
    banana->next = NULL;
    pear->next = banana;        // Pear now points to banana

    // Print the entire shopping list
    printf("=== MY FRUIT SHOPPING LIST ===\n");
    struct Fruit *current = head;       // Start from first fruit
    while (current != NULL) {           // Continue until end of the list
        printf("%s\n", current->name);
        printf(" Price per piece: %d CZK\n", current->price);
        printf(" Quantity: %d\n", current->quantity);
        printf(" total value: %d CZK\n", current->price *current->quantity);
        printf(" ---\n");

        current = current->next;        // Move to next fruit
    }

    // Calculate total value of all fruits
    int grand_total = 0;
    current = head;
    while (current != NULL) {
        grand_total += current->price * current->quantity;
        current = current->next;
    }
    printf("Grand total for all fruits: %d CZK\n", grand_total);

    // Free all allocated memory - prevent memory leak
    current = head;
    while (current != NULL) {
        struct Fruit *temp = current;       // Remember current node
        current = current->next;            // Move to next
        free(temp);                         // Free the remembered node
    }
    return 0;
}

/*
 * FULL EXPLANATION OF KEY CONCEPTS IN THIS CODE
 * (Written for complete beginners – so you understand everything even if you open this file in 14 days or later)
 *
 * 1. What is "head"?
 *    - "head" is just a variable name (we could call it "start" or "first_fruit")
 *    - It is a pointer that always points to the first fruit in our shopping list
 *    - Think of it as the "entrance door" to the entire linked list
 *    - Without head, we would lose access to the whole list
 *    - head = NULL at the beginning means "the list is empty"
 *
 * 2. What does "return 0" and "return 1" mean?
 *    - return is how a function (including main) gives back a result to the caller
 *    - In main(), the return value is sent to the operating system
 *    - return 0 = "program finished successfully, everything was OK"
 *    - return 1 = "program finished with an error" (we use it when malloc fails)
 *    - By convention, 0 = success, any other number = some kind of error
 *
 * 3. What is strcpy and why do we use it?
 *    - strcpy = "string copy"
 *    - It safely copies text from one place to another
 *    - You cannot do pear->name = "Pear"; directly because "Pear" is a string literal
 *      and name is a char array inside the struct
 *    - strcpy(destination, source) copies the source string (including the ending '\0')
 *      into the destination array
 *    - It's necessary here because struct fields are arrays, not strings
 *
 * 4. What is a "node"?
 *    - A node is one "item" or "element" in a linked list
 *    - Imagine a train wagon again:
 *        → Each wagon = one node
 *        → Cargo inside = our data (name, price, quantity)
 *        → Coupler to next wagon = the "next" pointer
 *    - In our code, struct Fruit is exactly one node
 *    - Every time we call malloc, we create a new wagon/node
 *
 * 5. Detailed explanation of this line (for someone who has never seen programming before):
 *    struct Fruit *pear = malloc(sizeof(struct Fruit));
 *
 *    Let's break it down word by word:
 *
 *    - struct Fruit      → this is our custom type (blueprint) for one fruit
 *                          It contains name, price, quantity, and pointer to next fruit
 *
 *    - *pear             → pear is a pointer (an arrow/address)
 *                          It will point to the memory location where our new fruit is stored
 *
 *    - =                 → assignment – we are giving pear a value
 *
 *    - malloc(...)       → "memory allocate" – a function that asks the operating system
 *                          for a block of free memory on the heap (dynamic memory area)
 *
 *    - sizeof(struct Fruit) → calculates how many bytes one complete Fruit needs in memory
 *                             (20 bytes for name + 4 for price + 4 for quantity + 8 for pointer = usually 36 bytes)
 *
 *    So the whole line means:
 *    "Ask the system for enough memory to store one complete Fruit.
 *     Give me the address of that memory and store it in the pointer called pear."
 *
 *    After this line, pear points to a brand new, empty fruit in memory,
 *    ready to be filled with name, price, quantity, and linked to others.
 *
 * These concepts (head, return codes, strcpy, nodes, malloc) are the foundation
 * of dynamic data structures in C. Understanding them makes you a real C programmer!
 */