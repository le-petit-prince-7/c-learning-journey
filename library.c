#include <stdio.h>

/*
 * BITWISE OPERATIONS - FULL EXPLANATION FOR COMPLETE BEGINNERS
 *
 * What are bits?
 * Every number in computer is stored as bits (0 or 1).
 * Example: decimal 5 in binary = 00000101 (8 bits)
 * Bit positions from right: 0,1,2,3,4,5,6,7 (value 1,2,4,8,16,32,64,128)
 *
 * Bitwise operators work on individual bits:
 *   &  AND    → 1 only if both bits are 1
 *   |  OR     → 1 if at least one bit is 1
 *   ^  XOR    → 1 if bits are different
 *   ~  NOT    → flips all bits (0→1, 1→0)
 *   << Left shift  → move bits left (multiply by 2 each time)
 *   >> Right shift → move bits right (divide by 2 each time)
 *
 * Real-world uses:
 *   - Flags/settings: pack many yes/no options into one integer
 *   - Hardware control: turn on/off LEDs, motors, sensors
 *   - Network protocols: packet headers (TCP flags)
 *   - Graphics/games: color masks, bitmaps
 *   - Cryptography: encryption algorithms
 *   - Optimization: faster than if/else for some checks
 *   - Cybersecurity: analyzing binary files, exploits, reverse engineering
 */

int main() {
    // Lets use 8-bit examples for clarity
    unsigned char a = 5;        // Binary: 00000101
    unsigned char b = 3;        // Binary: 00000011

    printf("=== BITWISE OPERATIONS DEMO ===\n");
    printf("a = %d (binary: 00000101)\n",a);
    printf("b = %d (binary: 00000011)\n",b);

    // 1. AND (&) - both bits must be 1
    unsigned char and_result = a & b;           //00000101 & 00000011 = 00000001 = 1
    printf("\na & b = %d (binary: 00000001)\n", and_result);
    printf("Use: check if certain bits are set (e.g. permission checks)\n");

    // 2. OR (|) - at least one bit must be 1
    unsigned char or_result = a | b;        // 00000101 | 00000011 = 00000111 = 7
    printf("\na | b = %d (binary: 00000111)\n", or_result);
    printf("Use: set multiple flags at once\n");

    // 3. XOR (^) - bits different → 1
    unsigned char xor_result = a ^ b;       // 00000101 ^ 00000011 = 00000110 = 6
    printf("\na ^ b = %d (binary: 00000110)\n", xor_result);
    printf("Use: simple encryption, toggling bits\n");

    // 4. NOT (~) - flip all bits
    unsigned char not_a = ~a;           //// ~00000101 = 11111010 = 250 (in 8-bit)
    printf("\n~a       = %d (binary: 11111010)\n", not_a);
    printf("Use: bit masks, inverting flags\n");

    // 5. Left shift (<<) - multiply by powers of 2
    unsigned char left_shift = a << 2;       // 00000101 << 2 = 00010100 = 20
    printf("\na << 2 = %d (binary: 00010100)\n", left_shift);
    printf(" Use: fast multiplication by 2^n, setting high bits\n");

    // 6. Right shift (>>) - divide by powers of 2
    unsigned char right_shift = a >> 1;     //00000101 >> 1 = 00000010 = 2
    printf("\na >> 1 = %d (binary: 00000010)\n", right_shift);
    printf("Use: fast division by 2^n, extracting bits\n");

    // ========================================
    // PRACTICAL EXAMPLE: FLAGS (very common in real code)
    // ========================================
    printf("\n=== PRACTICAL EXAMPLE: BIT FLAGS ===\n");

    // Define flags as powers of 2 (each bit represents one option)
    #define FLAG_READ    1       // binary 00000001
    #define FLAG_WRITE   2       // binary 00000010
    #define FLAG_EXECUTE 4       // binary 00000100

    unsigned char permissions = 0;   // Start with no permissions

    // Grant read and execute permissions
    permissions = FLAG_READ | FLAG_EXECUTE;     // 00000001 | 00000100 = 00000101 = 5

    printf("Permissions value: %d\n", permissions);

    // Check if read permission is set
    if (permissions == FLAG_READ) {
        printf("Read permission: YES\n");
    }

    // Add write permission
    permissions |= FLAG_WRITE;      // OR with write flag
    printf("After adding write: %d\n", permissions);


}