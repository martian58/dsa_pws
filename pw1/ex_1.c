#include <stdio.h>

/*
1. Start
2. Input two numbers, a and b
3. If a > b, output a is greater
4. Else, output b is greater
5. End
*/

int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    
    if (a > b) {
        printf("%d is greater\n", a);
    } else {
        printf("%d is greater\n", b);
    }
    return 0;
}
