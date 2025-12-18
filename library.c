#include <stdio.h>     // For printf
#include <stdlib.h>    // For malloc and free

// ========================================
// STRUCTURE DEFINITION - blueprint for one node
// ========================================
struct Node {
    int data;               // The value we want to store (cargo in the wagon)
    struct Node *next;      // Pointer to the next node (coupler to next wagon)
    // NULL = no next wagon (end of list)
};

// ========================================
// MAIN FUNCTION
// ========================================

int main() {
    struct Node *head = NULL;    // Head pointer - points to first node
                                // NULL = list is empty at start
    // Create first node (wagon)
    struct Node *first = malloc(sizeof(struct Node));
    // Check if memory allocation succeeded
    if (first == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    first->data = 10;       // Put value 10 into the node
    first->next = NULL;     // No next node yet
    head = first;           // Head now points to this node

    // Create second node and link it
    struct Node *second = malloc(sizeof(struct Node));
    if (second == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    second->data = 20;
    second->next = NULL;
    first->next = second;       // First node now point to second

    // Create third node and link it
    struct Node *third = malloc(sizeof(struct Node));
    if (third == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    third->data = 30;
    third->next = NULL;
    second->next = third;       // Second node now points to third

    // Print te entire list
    printf("Linked list contents\n");
    struct Node *current = head;        // Start from the beginning
    while (current != NULL) {           // Continue until we reach the end (NULL)
        printf("%d -> ", current->data);
        current = current->next;        // Move to next node
    }
    printf("NULL\n");       // End of list

    // Free all allocated memory (very important!)
    // We must free each node to avoid memory leak

    current = head;
    while (current != NULL) {
        struct Node *temp = current;        // Remeber current node
        current = current -> next;          // Move to next
        free(temp);                         // Free the remembered node
    }

    return 0;

}

/*
 * LINKED LIST - COMPLETE BEGINNER EXPLANATION WITH TRAIN ANALOGY
 *
 * What is this code for?
 * This program creates a simple singly linked list with three nodes containing values 10, 20, and 30.
 * It demonstrates how to:
 *   - Define a node structure
 *   - Dynamically allocate memory for each node using malloc
 *   - Link nodes together
 *   - Traverse (walk through) the list to print values
 *   - Free all allocated memory to prevent memory leaks
 *
 * Train (wagon) analogy - easy way to understand linked list:
 * Imagine a train made of wagons:
 *   - Each wagon = one node in the list
 *   - Cargo inside the wagon = the data (here: integer values 10, 20, 30)
 *   - Coupler connecting wagons = the 'next' pointer
 *   - First wagon = pointed by 'head'
 *   - Last wagon has no coupler to anything = next = NULL (end of train)
 *
 * Why use linked list instead of array?
 *   - Size can grow/shrink at runtime (add/remove wagons easily)
 *   - No need to know final size in advance
 *   - Insertion/deletion in middle is fast (just change couplers/pointers)
 *   - Trade-off: slower random access than arrays
 *
 * Key concepts used:
 *   - struct Node = custom type combining data and pointer to next node
 *   - malloc = creates new wagon (node) on the heap
 *   - -> operator = access field of structure through pointer
 *   - head = pointer to first wagon (start of train)
 *   - current = temporary pointer we move along the train to print or free
 *   - free = destroy wagon and give memory back to system
 *
 * This is a fundamental data structure used in real programs for lists, queues, stacks, etc.
 * Mastering linked lists is a big step toward intermediate C programming!
 */