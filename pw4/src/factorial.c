#include <stdio.h>
#include "factorial.h"

/**
 * @brief This function computes the factorial of a number iteratively.
 * 
 * The factorial of a number n is defined as the product of all positive integers 
 * less than or equal to n. For example:
 *  0! = 1
 *  1! = 1
 *  2! = 2*1 = 2
 *  3! = 3*2*1 = 6
 *  4! = 4*3*2*1 = 24
 *  n!=n*(n-1)*(n-2)…*2*1
 * 
 * @param n A non-negative integer.
 * @return The factorial of the input integer.
 */
int factorial_iterative(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

/**
 * @brief This function computes the factorial of a number recursively.
 * 
 * The factorial of a number n is computed as:
 * - Recursive case: n! = n * (n-1)!
 * 
 * @param n A non-negative integer.
 * @return The factorial of the input integer.
 */
int factorial_recursive(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial_recursive(n - 1);
}

