#include <stdio.h>
#include <assert.h>
#include "../include/gcd.h"
#include "../include/factorial.h"

int main() {
    printf("Running tests...\n");

    assert(gcd_iterative(12, 18) == 6);
    printf("Test 1: GCD (Iterative) passed ✅\n");
    assert(gcd_iterative(17, 13) == 1);
    printf("Test 2: GCD (Iterative) passed ✅\n");
    
    assert(gcd_recursive(12, 18) == 6);
    printf("Test 3: GCD (Recursive) passed ✅\n");
    assert(gcd_recursive(17, 13) == 1);
    printf("Test 4: GCD (Recursive) passed ✅\n");
    
    assert(factorial_iterative(5) == 120);
    printf("Test 5: Factorial (Iterative) passed ✅\n");
    assert(factorial_iterative(0) == 1);
    printf("Test 6: Factorial (Iterative) passed ✅\n");
    
    assert(factorial_recursive(5) == 120);
    printf("Test 7: Factorial (Recursive) passed ✅\n");
    assert(factorial_recursive(0) == 1);
    printf("Test 8: Factorial (Recursive) passed ✅\n");

    printf("All tests passed successfully!👍👍\n\n");
    printf("Type './main' to run the main program!\n");
    return 0;
}
