#include <stdio.h>
#include "pw2.h"

int main() {
    char user_input;

    printf(COLOR_PROMPT "Enter a character (1, 2, or 3): " COLOR_RESET);
    user_input = getchar(); 

    while (getchar() != '\n'); 
   
    const char* result = switch_character(user_input);
    printf(COLOR_RESULT "%s\n" COLOR_RESET, result);

    return 0;
}
