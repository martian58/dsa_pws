#include <stdio.h>
#include <math.h>

/*
1. Start
2. Input coefficients a, b, c
3. Calculate discriminant D = b² - 4ac
4. If D > 0, calculate two real roots:
  root1 = (-b + sqrt(D)) / (2a)
  root2 = (-b - sqrt(D)) / (2a)
5. If D = 0, calculate one real root:
   root = -b / (2a)
6. If D < 0, output "No real roots"
7. End
*/

int main() {
    float a, b, c, discriminant, root1, root2;
    printf("Enter coefficients a, b and c: ");
    scanf("%f %f %f", &a, &b, &c);
    
    discriminant = b * b - 4 * a * c;
    
    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Two real roots: %.2f and %.2f\n", root1, root2);
    } else if (discriminant == 0) {
        root1 = -b / (2 * a);
        printf("One real root: %.2f\n", root1);
    } else {
        printf("No real roots\n");
    }
    
    return 0;
}
