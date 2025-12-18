#include <stdio.h>

// ========================================
// RECURSIVE FIBONACCI - FOR COMPLETE BEGINNERS
// ========================================

// Recursive function to calculate nth Fibonacci number
// Parameter: n = which position in the sequence we want
// Returns: the Fibonacci number at position n

unsigned long long fibonacci(int n) {
    // Base cases - these stop the recursion
    // Without base cases, the function would call itself forever!
    if (n == 0) {
        return 0;       // F(0) = 0
    }
    if (n == 1) {
        return 1;       // F(1) = 1
    }

    // Recursive case
    // F(n) = F(n-1) + F(n-2)
    // The function calls itself twice with smaller numbers
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int position;

    printf("Which Fibonacci number do you want? (0-40 recommended): ");
    scanf("%d", &position);

    // Safety check - recursion gets very slow for large n
    if (position < 0) {
        printf("Please enter a non-negative number!\n");
        return 1;
    }
    if (position > 40) {
        printf("Warning: Numbers above 40 are very slow with recursion!\n");
    }

    // Call the recursive function
    unsigned long long result = fibonacci(position);

    // Print the result
    printf("Fibonacci (%d) = %llu\n", position, result);
    return 0;
}

/*
 * RECURSION: FIBONACCI SEQUENCE - FULL EXPLANATION FOR BEGINNERS
 *
 * What is recursion?
 * Recursion is a programming technique where a function calls itself
 * to solve a problem by breaking it down into smaller, identical sub-problems.
 * It's like Russian nesting dolls: each doll contains a smaller version of itself,
 * until you reach the smallest one that has no doll inside.
 *
 * How does recursion work?
 * A recursive function must have:
 *   1. Base case(s) – simple condition(s) that stop the recursion
 *      (without this, the function would call itself forever → stack overflow/crash)
 *   2. Recursive case – the function calls itself with a smaller/simpler input
 *
 * Why use recursion?
 * Recursion is great when a problem can be naturally divided into smaller versions of itself:
 *   - Tree traversals (file system directories, HTML DOM, decision trees)
 *   - Searching/sorting in recursive data structures (binary trees, graphs)
 *   - Mathematical problems like factorial, Fibonacci, Towers of Hanoi
 *   - Parsing expressions (math formulas, JSON, programming languages)
 *   - Backtracking algorithms (mazes, Sudoku solvers, chess AI)
 *
 * Advantages:
 *   - Often leads to very clean, elegant and easy-to-read code
 *   - Naturally matches the structure of many problems
 *
 * Disadvantages:
 *   - Can be slower and use more memory than iterative (loop-based) solutions
 *   - Too deep recursion → stack overflow (limited call stack size)
 *   - Pure recursion on Fibonacci is inefficient (recalculates same values many times)
 *
 * Real-world uses of recursion:
 *   - File system operations (recursive delete/copy of folders)
 *   - JSON/XML/HTML parsers
 *   - Graphics: fractal drawing, ray tracing
 *   - Compilers and interpreters
 *   - Algorithms: quicksort, depth-first search (DFS)
 *
 * In this example:
 * We calculate the nth Fibonacci number recursively.
 * F(n) = F(n-1) + F(n-2), with base cases F(0)=0 and F(1)=1.
 * The function calls itself until it reaches the base cases, then returns upward.
 *
 * Note: For large n (>40), this pure recursive version is very slow.
 * Better solutions: iterative loop or memoization (caching results).
 */