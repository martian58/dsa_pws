/**
 * File:          main.c
 * Author:        Fuad Alizada
 * Date:          27 Nov 2024
 * Description:   This is the main file for PW5.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/array_u.h"

#define MAX_SIZE 100

// ANSI codes for colorful prints
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"


void display_menu() {
    printf(BOLD CYAN "\n==================== MENU ====================\n" RESET);
    printf(BLUE "1. " YELLOW "Sum of elements\n");
    printf(BLUE "2. " YELLOW "Separate Odd and Even\n");
    printf(BLUE "3. " YELLOW "Search an element\n");
    printf(BLUE "4. " YELLOW "Reverse an integer array\n");
    printf(BLUE "5. " YELLOW "Find the maximum element\n");
    printf(BLUE "6. " YELLOW "Reverse a string\n");
    printf(BLUE "0. " RED "Exit\n");
    printf(CYAN "=============================================\n" RESET);
}

int main() {
    int choice;
    int arr[MAX_SIZE], size;

    printf(BOLD GREEN "Welcome to PW 5\n" RESET);
    printf(GREEN "Enter number of elements in the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size > MAX_SIZE || size <= 0) {
        printf(RED "Size is invalid! Please restart the program.\n" RESET);
        return 1;
    }

    read_array(arr, size);

    while (1) {
        display_menu();

        printf(YELLOW "Enter your choice: " RESET);
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf(GREEN "Sum of elements: %d\n" RESET, sum_elements(arr, size));
                break;

            case 2: {
                int odds[MAX_SIZE], evens[MAX_SIZE], odd_count, even_count;
                separate_odd_even(arr, size, odds, evens, &odd_count, &even_count);
                printf(GREEN "Odd elements: " RESET);
                for (int i = 0; i < odd_count; i++) printf("%d ", odds[i]);
                printf("\n" GREEN "Even elements: " RESET);
                for (int i = 0; i < even_count; i++) printf("%d ", evens[i]);
                printf("\n");
                break;
            }

            case 3: {
                int elem;
                printf(YELLOW "Enter the element to search: " RESET);
                scanf("%d", &elem);
                int pos = search(size, arr, elem);
                if (pos == -1) {
                    printf(RED "Element not found!\n" RESET);
                } else {
                    printf(GREEN "Element found at position: %d\n" RESET, pos + 1);
                }
                break;
            }

            case 4:
                reverse_array(arr, size);
                printf(GREEN "Reversed array: " RESET);
                for (int i = 0; i < size; i++) printf("%d ", arr[i]);
                printf("\n");
                break;

            case 5:
                printf(GREEN "Maximum element: %d\n" RESET, find_max(arr, size));
                break;

            case 6: {
                char str[MAX_SIZE];
                printf(YELLOW "Enter the string to reverse: " RESET);
                scanf(" %[^\n]s", str); 
                reverse_string(str);
                printf(GREEN "Reversed string: %s\n" RESET, str);
                break;
            }

            case 0:
                printf(BOLD GREEN "Exiting... Thank you for using!\n" RESET);
                return 0;

            default:
                printf(RED "Invalid choice! Please try again.\n" RESET);
                break;
        }
    }

    return 0;
}
