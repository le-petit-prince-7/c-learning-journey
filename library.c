#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ========================================
// STRUCTURE DEFINITION - one fruit item
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
}
