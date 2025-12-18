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
}