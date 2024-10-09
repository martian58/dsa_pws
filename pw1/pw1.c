#include<stdio.h>
#include<math.h>
#include "pw1.h"

/*

Exercise 1:

        Start
          |
        Input num1, num2
          |
   Is num1 > num2?
      /     \
    Yes      No
   /           \
 Output:     Output:
 num1         num2
   |           |
    \         /
      \      /
        End

*/

float compare_two_floats(float a, float b){

    return a ? a>b : b;
}

int compare_two_ints(int a, int b){

    return a ? a>b : b;
}


/****************************************************************************************************************************************************/

/* Exercise 2

        Start
          |
    Input a, b, c
          |
    Is a == 0?
      /    \
    Yes     No
   /         \
"Not a      Calculate discriminant
quadratic"     |
     |         |
    End    Is discriminant > 0?
               /    |    \
            Yes    No     Negative
           /        |        \
   Two distinct    One      Two complex
   real roots    real root    roots
       |           |           |
       |           |           |
       End        End         End

*/


/**
 * @brief Calculates the roots of a quadratic equation.
 *
 * This function takes the coefficients of a quadratic equation in the form 
 * `ax^2 + bx + c = 0` and computes its roots. It handles three cases based 
 * on the discriminant:
 * - If the discriminant is positive, the equation has two distinct real roots.
 * - If the discriminant is zero, the equation has one real root (a double root).
 * - If the discriminant is negative, the equation has two complex roots.
 *
 * The function will also check if the input is actually a quadratic equation 
 * (i.e., `a != 0`). If `a == 0`, it prints an error message since the equation 
 * is not quadratic.
 *
 * @param a Coefficient of the quadratic term (`x^2`).
 * @param b Coefficient of the linear term (`x`).
 * @param c Constant term.
 *
 * @return void
 *
 * @note This function prints the result directly to the console, including:
 * - Two distinct real roots if the discriminant is positive.
 * - One real root if the discriminant is zero.
 * - Two complex roots if the discriminant is negative.
 * - A message indicating it is not a quadratic equation if `a == 0`.
 */
void calculate_roots(double a, double b, double c) {
    if (a == 0) {
        printf("This is not a quadratic equation.\n");
        return;
    }

    double discriminant = b * b - 4 * a * c;
    double realPart, imaginaryPart;

    // Check the discriminant
    if (discriminant > 0) {
        // Two distinct real roots
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Two distinct real roots: x1 = %.2lf, x2 = %.2lf\n", x1, x2);
    } else if (discriminant == 0) {
        // One real root
        double x = -b / (2 * a);
        printf("One real root: x = %.2lf\n", x);
    } else {
        // Complex roots
        realPart = -b / (2 * a);
        imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("Two complex roots: x1 = %.2lf + %.2lfi, x2 = %.2lf - %.2lfi\n",
               realPart, imaginaryPart, realPart, imaginaryPart);
    }
}