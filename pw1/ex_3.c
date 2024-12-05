#include <stdio.h>

/*
1. Start
2. Input number n
3. If n < 0, end the program
4. If 1 <= n <= 100, display n
5. If n > 100, prompt user to re-enter n
6. Repeat steps 4 and 5 until valid input is given
7. End
*/

int main() {
    int n;
    
    while (1) {
        printf("Enter a number: ");
        scanf("%d", &n);
        
        if (n < 0) {
            printf("Program discarded.\n");
            break;
        } else if (n >= 1 && n <= 100) {
            printf("Number is: %d\n", n);
            break;
        } else {
            printf("Please enter a number between 1 and 100.\n");
        }
    }
    
    return 0;
}
