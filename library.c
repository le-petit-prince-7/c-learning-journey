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

    
}