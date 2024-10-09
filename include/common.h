/*
 * File:         common.h
 * Author:       Fuad Alizada
 * Date:         October 09, 2024
 * Description:  Constant variables and functions for the project. 
 */


#include <stdio.h>
#include <stdbool.h> 
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h> 


/*
    **Functions in this header**:

    1. show_main_menu();
    2. exit_program();
    3. clear_input_buffer();
    4. get_int_input();
    5. get_char_input();
    6. print_colored_line();
    7. print_padded_line();
    8. generate_random_char();
    9. intro();

    **Variables in this library**:

    1. RED
    2. GREEN
    3. YELLOW
    4. WHITE
    5. PINK
    6. BLUE
    7. RESET
    8. VERSION
*/

/**
 * @brief Detects the operating system at compile-time.
 *
 * This function determines the operating system by using preprocessor
 * directives to check for specific macros that correspond to different
 * operating systems. It returns a string representing the detected OS.
 *
 * Supported systems:
 * - Windows (32-bit or 64-bit)
 * - macOS
 * - Linux
 * - FreeBSD
 * - Unix (generic Unix systems)
 *
 * @return const char* A string literal representing the operating system.
 * Possible return values are:
 * - "Windows" for Windows operating systems (32-bit or 64-bit)
 * - "macOS" for Apple macOS systems
 * - "Linux" for Linux-based systems
 * - "FreeBSD" for FreeBSD systems
 * - "Unix" for generic Unix-like systems
 * - "Unknown" if the OS is not recognized or unsupported
 */
const char* get_operating_system() {
    #if defined(_WIN32) || defined(_WIN64)
        return "Windows";
    #elif defined(__APPLE__) || defined(__MACH__)
        return "macOS";
    #elif defined(__linux__)
        return "Linux";
    #elif defined(__FreeBSD__)
        return "FreeBSD";
    #elif defined(__unix__)
        return "Unix";
    #else
        return "Unknown";
    #endif
}


// Function to open an HTML file based on the operating system
void open_html_file(const char *filename) {
    const char *os = get_operating_system();
    char command[512];

    if (os == NULL) {
        printf("Operating System could not be detected.\n");
        return;
    }

    if (strcmp(os, "Windows") == 0) {
        // Windows command to open a file with the default application
        snprintf(command, sizeof(command), "cmd /c start %s", filename);
    }
    else if (strcmp(os, "Linux") == 0 || strcmp(os, "macOS") == 0 || strcmp(os, "Unix") == 0 || strcmp(os, "FreeBSD") == 0) {
        // Linux/macOS/Unix command to open a file with the default application
        snprintf(command, sizeof(command), "xdg-open %s", filename);
    }
    else {
        printf("Unsupported Operating System: %s\n", os);
        return;
    }

    // Execute the command to open the HTML file
    int result = system(command);
    if (result != 0) {
        printf("Failed to open the file: %s\n", filename);
    }
    else {
        printf("Successfully opened the file: %s\n", filename);
    }
}


// Function to clear the terminal screen
void clear_screen() {
#ifdef _WIN32
    system("cls");  // Clear screen for Windows
#else
    printf("\033c");  // Clear screen for Linux/macOS/Unix
#endif
}


// Ascii codes for colors as a string.
char *RED = "\033[1;31m"; 
char *GREEN = "\033[1;32m"; 
char *YELLOW = "\033[1;33m"; 
char *WHITE = "\033[1;37m"; 
char *PINK = "\033[1;35m"; 
char *BLUE = "\033[1;34m"; 
char *RESET = "\033[0m";


//Version information.
char *VERSION="1.0";

// Function to exit the program.
void exit_program(){
    printf("%sExiting....\n",YELLOW);
    usleep(1000000);
    printf("%sHave a good day!\n",GREEN);
    usleep(2000000);
    clear_screen();
    exit(0);
}

//Function to clear the buffer after invalid inputs.
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to get an integer input from the user.
int get_int_input() {
    printf("\n\n");
    int input;
    int success;  // Variable to hold the return value of scanf.

    do {
        printf("%sEnter the number of the option you choose.%s\n",GREEN,RESET);
        printf("%spw--> %s",PINK,RESET);
        success = scanf("%d", &input);

        // Clear the input buffer in case of invalid input.
        while (getchar() != '\n');

        if (success != 1) {
            printf("%sInvalid option!%s\n\n",RED,RESET);

        }
    } while (success != 1);

    return input;
}

// Function to get a character input from the user.
// Make sure there is space before '%c'.
char get_char_input() {
    printf("\n\n");
    char input;
    printf("%sEnter the number of the option you choose.%s\n",GREEN,RESET);
    printf("%spw--> %s",PINK,RESET);
    scanf(" %c", &input); //the space before %c to consume whitespace.
    return input;
}

// Function to print a line with color transitions.
void print_colored_line(const char *line, const char *foreground_color, const char *background_color) {
    printf("\033[%s;%sm%s\033[0m\n", foreground_color, background_color, line);
}


// Function to print a line with padding from top and left.
void print_padded_line(const char *text, int padding_top, int padding_left) {
    for (int i = 0; i < padding_top; i++) {
        printf("\n");
    }
    printf("%*s%s\n", padding_left, "", text);
}

// Function to generate a random character.
char generate_random_char() {
    const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    int len = strlen(chars);
    return chars[rand() % len];
}

// PW1 ASCII art with color transition and padding.
void intro() {
    // Clear the screen.
    printf("\033c");

    // Define color codes.
    const char *colors[] = {"34", "32", "33", "36", "35"};

    // ASCII art lines.
    const char *lines[] = {
        "      @@@@@@@@@   @@                    @@       @@  ",
        "      @@     @@    @@        @@        @@        @@  ",
        "      @@     @@     @@      @@@@      @@         @@   ",
        "      @@@@@@@@@      @@    @@  @@    @@          @@   ",
        "      @@              @@  @@    @@  @@           @@   ",
        "      @@               @@@@      @@@@                 ",
        "      @@                @@        @@             @@   "
    };

    // Print each line with color transition and a random character.
    printf("\n\n");
    for (int i = 0; i < 7; i++) {
        char line_copy[strlen(lines[i]) + 1];
        strcpy(line_copy, lines[i]);
        char rnd_char = generate_random_char();
        for (int j = 0; line_copy[j] != '\0'; j++) {
            if (line_copy[j] == '@') {
                line_copy[j] = rnd_char;
            }
        }
        print_colored_line(line_copy, colors[i % 5], colors[(i + 1) % 5]);
        usleep(200000); // Sleep for 0.2 seconds.
    }

    printf("\n\n");

    // Welcome message,Author and GitHub reference.
    printf("\033[1;36m");
    printf("Welcome to PW \n");
    printf("\033[0m");
    printf("%sVersion: %s\n",PINK,VERSION);
    printf("\033[1;33m");
    printf("Created by: Fuad Alizada\n");
    printf("GitHub: https://github.com/martian58\n");
    printf("\033[0m");
    printf("\033[1;33m");
    usleep(300000);
    printf("\033[0m");
    printf("\n");
    printf("%s", BLUE);
    printf("This program includes all the tasks of the Practical works.\n");
    printf("Continue to the pws menu to explore them. Source codes are in 'pw#' directories.\n");
    printf("\n\n");
    printf("1. Continue \n");
    printf("%s2. Exit%s \n",RED,RESET);
    printf("%s3. Visit my github :)%s \n",GREEN,RESET);
}



// Function to show the fancy main menu :).
void show_main_menu() {
    printf("\n\n");
    printf("%s************** PWS MENU ****************%s",GREEN,RESET);
    printf("\n\n");
    printf("%s1. PW_1 (New)%s\n",GREEN,RESET);
    printf("%s2. PW_2 (Coming soon)\n",BLUE);
    printf("3. PW_3 (Coming soon)\n");
    printf("4. PW_4 (Coming soon)\n");
    printf("5. PW_5 (Coming soon)\n");
    printf("6. PW_6 (Coming soon)\n%s",RESET);
    printf("%s8. Go back%s\n",YELLOW,RESET);
    printf("%s9. Exit%s\n",RED,RESET);
    printf("\n");
}

// Function to show some fancy menu :)
void show_pw1_menu() {
    printf("\n\n");
    printf("%s************** PW 1  MENU ****************%s",GREEN,RESET);
    printf("\n\n");
    printf("%s", WHITE);
    printf("1. Ex_1 (Comapre two numbers)\n");
    printf("2. Ex_2 (Quadratic eq. solver)\n");
    printf("3. Ex_3 (Number checker)\n");
    printf("4. Ex_4 (Average of grades)\n");
    printf("5. Ex_5 (Average of grades)\n");
    printf("%s89. Go back.%s\n",YELLOW, RESET);
    printf("%s90. Exit.\n",RED);
    printf("%s99. Clear screen%s",GREEN,RESET);
    printf("\n\n");
    printf("%sImportant*-> %sSource codes of these exercises are in 'pw1/' directory.%s",YELLOW,WHITE,RESET);
    printf("%s", RESET);
}
//*





