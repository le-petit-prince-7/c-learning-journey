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

