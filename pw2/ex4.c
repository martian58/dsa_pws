#include <stdio.h>
#include "pw2.h"


int main() {
    char user_input;


    // Get user input
    printf(COLOR_PROMPT "Enter a character: " COLOR_RESET);
    scanf(" %c", &user_input); 

    // Determine the character type
    const char* result = check_character_type(user_input);

    printf(COLOR_RESULT "The character '%s%c' is: %s\n" COLOR_RESET, COLOR_INPUT, user_input, result);

    return 0;
}
