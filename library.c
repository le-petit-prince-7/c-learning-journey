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

    //

}