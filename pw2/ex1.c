#include <stdio.h>

int main() {
    int count = 0;
    char ch;

    printf("Enter characters (press Enter to finish): ");

    while (1) {
        ch = getchar(); 

        // Check if the character is a digit
        if (ch >= '0' && ch <= '9') {
            count++; 
        } 
        // Check if the character is a newline
        else if (ch == '\n') {
            printf("Count of digits: %d\n", count);
            break; 
        }
    }

    return 0;
}
