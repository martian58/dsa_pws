#include <stdio.h>
#include "gcd.h"
#include "factorial.h"


#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"


// Just a simple main function this time 🥲


int main() {
    int m, n, choice;

    printf(CYAN "Select an operation:\n" RESET);
    printf(YELLOW "1. GCD (Iterative)\n" RESET);
    printf(YELLOW "2. GCD (Recursive)\n" RESET);
    printf(YELLOW "3. Factorial (Iterative)\n" RESET);
    printf(YELLOW "4. Factorial (Recursive)\n" RESET);
    printf(CYAN "Enter choice (1-4): " RESET);
    scanf("%d", &choice);

    if (choice == 1 || choice == 2) {
        printf("Enter two integers: ");
        scanf("%d %d", &m, &n);

        if (choice == 1) {
            printf("GCD of %d and %d (Iterative): %d\n", m, n, gcd_iterative(m, n));
        } else {
            printf("GCD of %d and %d (Recursive): %d\n", m, n, gcd_recursive(m, n));
        }
    } else if (choice == 3 || choice == 4) {
        printf("Enter a number: ");
        scanf("%d", &n);

        if (choice == 3) {
            printf("Factorial of %d (Iterative): %d\n", n, factorial_iterative(n));
        } else {
            printf("Factorial of %d (Recursive): %d\n", n, factorial_recursive(n));
        }
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
