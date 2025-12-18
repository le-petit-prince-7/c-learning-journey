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

    
}