#include <stdio.h>
#include <string.h>

/*
 * BUFFER OVERFLOW - COMPLETE BEGINNER EXPLANATION
 *
 * What is a buffer overflow?
 * A buffer overflow happens when a program writes more data to a buffer
 * (a fixed-size block of memory) than it can hold.
 * The extra data "overflows" and overwrites adjacent memory.
 * This can corrupt data, crash the program, or allow an attacker to execute malicious code.
 *
 * Why is it dangerous?
 * In memory, important things are stored right next to buffers:
 *   - return addresses (where the program should continue after a function)
 *   - saved variables
 *   - security checks
 * If an attacker overflows a buffer, they can overwrite the return address
 * and make the program jump to their own code (shellcode) → full control of the system.
 *
 * Classic vulnerable functions in C (NEVER use these in real code):
 *   - gets()           → reads input with NO size check (very dangerous)
 *   - strcpy()         → copies string with NO size check
 *   - strcat()         → concatenates strings with NO size check
 *   - sprintf()        → formats string with NO size check
 *
 * These functions are the main reason buffer overflows were so common in the past.
 *
 * Safe alternatives (ALWAYS use these):
 *   - fgets(buffer, sizeof(buffer), stdin) → limits input to buffer size
 *   - strncpy(dest, src, sizeof(dest))     → copies only up to size
 *   - strncat(dest, src, sizeof(dest)-strlen(dest)-1) → safe concatenation
 *   - snprintf(dest, sizeof(dest), "...", ...) → safe formatting
 *
 * Modern defenses (enabled by compiler):
 *   - Stack canaries   → secret value placed between buffer and return address
 *                      → if overflow happens, canary is corrupted → program crashes safely
 *   - ASLR             → random memory layout → hard to guess addresses for exploit
 *   - DEP/NX           → data memory cannot be executed as code
 *
 * In this code:
 *   - The commented part uses gets() → VULNERABLE to buffer overflow
 *   - The active part uses fgets() → SAFE, prevents overflow
 */

// Vulnerable version - DO NOT USE IN REAL CODE (commented out for safety)
/*
int main() {
    char buffer[10];  // Buffer can hold only 10 bytes (9 chars + '\0')

    printf("Put your name: ");
    gets(buffer);     // DANGEROUS! No length check → buffer overflow possible

    printf("Hello %s!\n", buffer);

    return 0;
}
*/


// Safe version - correct way to read user input
int main() {
    char buffer[10];        // Buffer for 10 characters

    printf("Fill in your name: ");
    fgets(buffer, sizeof(buffer), stdin);  // Safe - reads max 9 chars + \0

    printf("Hello %s!\n", buffer);

    return 0;

}