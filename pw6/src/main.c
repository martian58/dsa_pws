#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/sort_utils.h"

#define MAX_SIZE 300

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
    printf(BLUE "1. " YELLOW "Exercise 1:  Sorting methods\n");
    printf(BLUE "2. " YELLOW "Exercise 2:  QuickSort (Descending)\n");
    printf(BLUE "3. " YELLOW "Exercise 3:  Left Rotate Array\n");
    printf(BLUE "4. " YELLOW "Exercise 4a: Sort String Alphabetically\n");
    printf(BLUE "5. " YELLOW "Exercise 4b: Character Frequencies\n");
    printf(BLUE "0. " RED "Exit\n");
    printf(CYAN "=============================================\n" RESET);
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    int arr[MAX_SIZE], size;
    char str[MAX_SIZE];

    while (1) {
        display_menu();

        printf(YELLOW "Enter your choice: " RESET);
        scanf("%d", &choice);

        switch (choice) {

            // Case 1 is for the Exercise 1
            case 1:
                printf(GREEN "\n--- Exercise 1: Sorting Methods ---\n" RESET);
                printf("Enter the number of elements: ");
                scanf("%d", &size);
                printf("Enter the elements: ");
                for (int i = 0; i < size; i++) scanf("%d", &arr[i]);

                clock_t start, end;
                double time_taken;

                // Selection Sort
                start = clock();
                selection_sort(arr, size);
                end = clock();
                time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf(GREEN "Selection Sort Result: " RESET);
                print_array(arr, size);
                printf("Time taken: %.8f seconds\n", time_taken);

                // Bubble Sort
                randomize_array(arr, size);
                start = clock();
                bubble_sort(arr, size);
                end = clock();
                time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf(GREEN "Bubble Sort Result: " RESET);
                print_array(arr, size);
                printf("Time taken: %.8f seconds\n", time_taken);

                // Insertion Sort
                randomize_array(arr, size);
                start = clock();
                insertion_sort(arr, size);
                end = clock();
                time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf(GREEN "Insertion Sort Result: " RESET);
                print_array(arr, size);
                printf("Time taken: %.8f seconds\n", time_taken);

                // Merge Sort
                randomize_array(arr, size);
                start = clock();
                merge_sort(arr, 0, size - 1); // Pass size - 1 as the right index
                end = clock();
                time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf(GREEN "Merge Sort Result: " RESET);
                print_array(arr, size);
                printf("Time taken: %.8f seconds\n", time_taken);

                break;

            // Case 2 is for Exercise 2
            case 2:
                printf(GREEN "\n--- Exercise 2: QuickSort (Descending) ---\n" RESET);
                printf("Enter the number of elements: ");
                scanf("%d", &size);
                printf("Enter the elements: ");
                for (int i = 0; i < size; i++) scanf("%d", &arr[i]);

                quick_sort_descending(arr, 0, size - 1);
                printf(GREEN "QuickSort Result: " RESET);
                print_array(arr, size);
                break;

            case 3:
                printf(GREEN "\n--- Exercise 3: Left Rotate Array ---\n" RESET);
                printf("Enter the number of elements: ");
                scanf("%d", &size);
                printf("Enter the elements: ");
                for (int i = 0; i < size; i++) scanf("%d", &arr[i]);
                int n;
                printf("Enter the number of positions to rotate: ");
                scanf("%d", &n);

                left_rotate(arr, size, n);
                printf(GREEN "Left Rotated Array: " RESET);
                print_array(arr, size);
                break;


            // Case 4 is for Exercise 4 a. 
            case 4:
                printf(GREEN "\n--- Exercise 4a: Sort String Alphabeticaly ---\n" RESET);
                printf("Enter a string: ");
                scanf(" %[^\n]s", str); // Scan the string until a new-line character.

                sort_string(str);
                printf(GREEN "Sorted String: " RESET "%s\n", str);
                break;

            // Case 5 is for Exercise 4 b. 
            case 5:
                printf(GREEN "\n--- Exercise 4b: Character Frequencies ---\n" RESET);
                printf("Enter a string: ");
                scanf(" %[^\n]s", str);

                printf(GREEN "Character Frequencies:\n" RESET);
                character_frequency(str);
                break;

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
