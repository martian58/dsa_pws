/**
 * Filename:    main.c
 * Author:      Fuad Alizada
 * Purpose:     Implements Mthe main fuanction for Practical work 8.
 */

#include <stdio.h>
#include <stdlib.h>
#include "tasks.h"

// ANSI codes for colorful prints
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"

int main() {
    Node* head = NULL;

    // Task 1: Append elements to the linked list
    printf(CYAN "Initializing the linked list and append elements...\n" RESET);
    append_linked_list(&head, 4);
    append_linked_list(&head, 1);
    append_linked_list(&head, 5);
    append_linked_list(&head, 3);
    append_linked_list(&head, 3);
    append_linked_list(&head, 8);
    append_linked_list(&head, 3);
    append_linked_list(&head, 4);
    append_linked_list(&head, 9);

    // Print the original list
    printf(YELLOW "\nOriginal List:\n" RESET);
    print_list(head);

    // Task 2: Merge Sort the list
    printf(GREEN "\nPerforming Merge Sort...\n" RESET);
    head = merge_sort(head);
    printf("Sorted List (after Merge Sort):\n");
    print_list(head);

    // Task 3: Remove duplicates in the sorted list
    printf(RED "\nRemoving duplicates from the sorted list...\n" RESET);
    remove_duplicates(head);
    printf("List after removing duplicates:\n");
    print_list(head);

    // Task 4: Reverse the list iteratively
    printf(BOLD "\nReversing the list iteratively...\n" RESET);
    head = reverse_list_iterative(head);
    printf("List after iterative reversal:\n");
    print_list(head);

    // Task 5: Reverse the list recursively
    printf(BOLD "\nReversing the list recursively...\n" RESET);
    head = reverse_list_recursive(head);
    printf("List after recursive reversal:\n");
    print_list(head);

    // Free memory
    free_list(head);

    printf(BOLD GREEN "\n\nProgram ran successfuly, 20 points pls :)\n" RESET);

    return 0;
}
