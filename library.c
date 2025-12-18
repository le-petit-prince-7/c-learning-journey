#include <stdio.h>     // For printf
#include <stdlib.h>    // For malloc and free

// ========================================
// STRUCTURE DEFINITION - blueprint for one node
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

    

}