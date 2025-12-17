// ========================================
// POINTER BASICS DEMO - for complete beginners
// ========================================

printf("\n=== POINTERS DEMO ===\N");

// Normal integer variable
// a is stored somewhere in memory and holds the value 100
int a = 100;

// Pointer declaration
// int *ptr = pointer to an integer
// &a = "address of" variable a (where in memory a is stored)
// So ptr now holds the memory address of a
int *ptr = &a;

// Print the actual value stored in variable a
printf("Value of a: %d\n", a);      // Output: 100

// Print the memory address where a is stored
// %p = format for printing pointers (addresses)
// &a = address operator - gives the address of a
printf("Adress of a: %p\n", &a);    // Output: some hex number like 0x7fff...

// Dereference the pointer
// *ptr = "value at the address pointed by ptr"
// Since ptr points to a, *ptr gives us the value of a
printf("Value pointed by ptr: %d\n", &ptr);     // Output 100 - same as a.auto

// Change the value THROUGH the pointer
// *ptr = 200 means: put 200 into the memory location that ptr points to
// Since ptr points to a, this changes the value of a
*ptr = 200;     // Change value through pointer

// Now a has been changed, even though we didn't write a = 200 directly
printf("New value of a: %d\n", a);         // Output: 200


// ========================================
// ARRAY AND POINTER RELATIONSHIP
// In C, array name is automatically a pointer to its first element
// ========================================
int numbers[4] = {10, 20, 30, 40};
// numbers = pointer to the first element (numbers[0])
// numbers is the same as &numbers[0]

// Create a pointer that points to the beginning of the array
// No & needed - array name already acts as a pointer
int *arr_ptr = numbers;

printf("\nArray through pointer:\n");

// Loop through the array using pointer arithmetic
