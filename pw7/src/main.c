#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/stack.h"
#include "../include/queue.h"
#include "../include/utility.h"

// ANSI codes for colorful prints
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"

void display_menu() {
    printf(BOLD CYAN "\n==================== MENU ====================\n" RESET);
    printf("1. " YELLOW "Exercise 1: Stack Operations (LIFO)\n");
    printf("2. " YELLOW "Exercise 2: Queue Operations (FIFO)\n");
    printf("3. " YELLOW "Exercise 3: Balanced Parentheses Check\n");
    printf("4. " YELLOW "Exercise 4: Next Greater Element using Stack\n");
    printf("0. " RED "Exit\n");
    printf(CYAN "=============================================\n" RESET);
}

int main() {
    int choice;

    while (1) {
        display_menu();

        printf(YELLOW "Enter your choice: " RESET);
        scanf("%d", &choice);

        switch (choice) {
            // Exercise 1
            case 1: {
                printf(GREEN "\n--- Exercise 1: Stack Operations (LIFO) ---\n" RESET);
                Stack my_stack = createStack(10); // Example stack with capacity 10
                
                push(&my_stack, 10);
                push(&my_stack, 20);
                push(&my_stack, 30);

                printf(GREEN "Stack after pushing 10, 20, 30:\n" RESET);
                printStack(&my_stack);

                int value;
                pop(&my_stack, &value);
                printf(GREEN "Popped value: " RESET "%d\n", value);

                freeStack(&my_stack);
                break;
            }

            // Exercise 2
            case 2: {
                printf(GREEN "\n--- Exercise 2: Queue Operations (FIFO) ---\n" RESET);
                Queue my_queue = createQueue(10); // Example queue with capacity 10
                
                enqueue(&my_queue, 5);
                enqueue(&my_queue, 15);
                enqueue(&my_queue, 25);

                printf(GREEN "Queue after enqueuing 5, 15, 25:\n" RESET);
                printQueue(&my_queue);

                int value;
                dequeue(&my_queue, &value);
                printf(GREEN "Dequeued value: " RESET "%d\n", value);

                freeQueue(&my_queue);
                break;
            }

            // Exercise 3
            case 3: {
                printf(GREEN "\n--- Exercise 3: Balanced Parentheses Check ---\n" RESET);
                char expression[100];
                printf("Enter an expression: ");
                scanf(" %[^\n]s", expression);

                if (isBalanced(expression)) {
                    printf(GREEN "The expression is balanced.\n" RESET);
                } else {
                    printf(RED "The expression is not balanced.\n" RESET);
                }
                break;
            }

            // Exercise 4
            case 4: {
                printf(GREEN "\n--- Exercise 4: Next Greater Element ---\n" RESET);
                int size;
                printf("Enter the number of elements: ");
                scanf("%d", &size);

                int arr[size];
                printf("Enter the elements: ");
                for (int i = 0; i < size; i++) {
                    scanf("%d", &arr[i]);
                }

                int result[size];
                nextGreaterElement(arr, size, result);

                printf(GREEN "Next Greater Elements:\n" RESET);
                for (int i = 0; i < size; i++) {
                    printf("%d ", result[i]);
                }
                printf("\n");
                break;
            }

            case 0:
                printf(BOLD GREEN "Exiting... Thank you!\n" RESET);
                return 0;

            default:
                printf(RED "Invalid choice! Please try again.\n" RESET);
                break;
        }
    }

    return 0;
}
