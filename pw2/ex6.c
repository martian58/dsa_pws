#include <stdio.h>
#include "pw2.h"


int main() {
    int num1, num2, num3;
    
    // Ask the user to enter three numbers
    printf(COLOR_PROMPT "Enter three numbers: " COLOR_RESET);
    if (scanf("%d %d %d", &num1, &num2, &num3) != 3) {
        printf(COLOR_ERROR "Invalid input. Please enter three integers.\n" COLOR_RESET);
        return 1; 
    }

    // analyze the numbers
    int* results = analyze_three_numbers(num1, num2, num3);
    
    // Display the results
    printf(COLOR_RESULT "Smallest number: %d\n" COLOR_RESET, results[0]);
    printf(COLOR_RESULT "Largest number: %d\n" COLOR_RESET, results[1]);
    printf(COLOR_RESULT "Sum of the numbers: %d\n" COLOR_RESET, results[2]);

    return 0;
}
