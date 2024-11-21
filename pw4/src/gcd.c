#include <stdio.h>
#include "gcd.h"

/**
 * @brief This function computes the greatest common divisor (GCD) of two integers iteratively.
 * 
 * This function uses a loop to check all integers from 1 up to the smaller of the 
 * two numbers and identifies the largest common factor.
 * 
 * @param m The first integer(non-negative).
 * @param n The second integer(non-negative). 
 * @return The GCD of the two integers.
 */
int gcd_iterative(int m, int n) {
    int gcd, i;
    for (i = 1; i <= m && i <= n; i++) {
        if (m % i == 0 && n % i == 0) {
            gcd = i;
        }
    }
    return gcd;
}

/**
 * @brief Computes the greatest common divisor (GCD) of two integers recursively.
 * 
 * The GCD of two integers is calculated using the Euclidean algorithm:
 *  GCD(m, n) = GCD(n, m % n)
 * 
 * @param m The first integer(non-negative).
 * @param n The second integer(non-negative).
 * @return GCD of the two integers.
 */
int gcd_recursive(int m, int n) {
    if (n == 0)
        return m;
    return gcd_recursive(n, m % n);
}
