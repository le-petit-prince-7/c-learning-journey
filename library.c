#include <stdio.h>      // For FILE, fopen, fprintf, fscanf, fgets, fclose

// ========================================
// FILE I/O DEMO - FOR COMPLETE BEGINNERS
// ========================================

int main() {
    // ========================================
    // 1. WRITING TO A FILE
    // ========================================
    // fopen(filename, mode)
    // "w" = write mode (creates file if not exists, overwrites if exists)

    FILE *file = fopen("fruit_list.txt", "w");

    if (file == NULL) {     // Always check if file opened successfully
        printf("Error: Could not open file for writing!\n");
        return 1;
    }

    // Write lines to file - fprint is like printf, but to file
    fprintf(file, "Apple - 15 CZK\n");
    fprintf(file, "Pear - 20 CZK\n");
    fprintf(file, "Banana - 90 CZK\n");
    fprintf(file, "Orange - 30 CZK\n");

    
}