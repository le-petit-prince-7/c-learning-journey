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

    // Always close the file when done
    fclose(file);
    printf("Data successfully written to fruit_list.txt\n");

    // ========================================
    // 2. READING FROM A FILE
    // ========================================
    // "r" = read mode

    file = fopen("fruit_list.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file for reading!\n");
        return 1;
    }

    // Buffer for reading ne line at a time
    char line[100];     //Max 99 characters + \0

    printf("\nContents of fruit_list.txt\n");

    // fgets reads one line (up to newline or buffer size)
    // Returns NULL when end of file is reached
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);         // %s prints the string, no need for & because line is array
    }

    fclose(file);  // Close file again
    return 0;

}