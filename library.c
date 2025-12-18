#include <stdio.h>     // For printf and scanf
#include <stdlib.h>    // For malloc and free

int main() {
    int n; // Variable to store the size (user will enter it)

    // Ask user to store the size (user will enter it)
    printf("Enter the number of elements");
    scanf("%d", &n);

    // Allocate dynamic array using malloc
    // int *dyn_array = pointer to int (will point to the array)
    // malloc(n * sizeof(int)) = allocate memory for n integers
    // sizeof(int) = size of one int in bytes (usually 4)
    // malloc returns pointer to the memory, or NULL if failed
}