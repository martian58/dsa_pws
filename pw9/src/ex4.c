/**
 * Filename:    ex4.c
 * Author:      Fuad Alizada 
 * Purpose:     Code for Practical Work 9 Exercise 4.
 */


#include <stdio.h>
#include <stdlib.h>


struct node {
    int num;               // Data stored in the node.
    struct node* next;     //Pointer to the next node in the list.
};

/**
 * @brief Creates a singly linked list by reading integers from the user.
 *        The user enters -1 to stop input.
 * 
 * @param head Pointer to the head pointer of the list.
 * @return The total number of nodes created (size of the list).
 */
int create(struct node** head) {
    int count = 0;         // Counter to track the number of nodes.
    int value;             /// Variable to store user input.
    struct node* temp = NULL; // Temporary pointer to traverse the list.

    printf("Enter integers to add to the list (-1 to stop):\n");
    while (1) {
        scanf("%d", &value);
        if (value == -1) break; //Stop input when the user enters -1.

        // Create a new node
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->num = value;
        newNode->next = NULL;

        if (*head == NULL) {
            // If the list is empty, new node iss the head.
            *head = newNode;
        } else {
            // Otherwise, link the new node to the end of the list.
            temp->next = newNode;
        }

        temp = newNode;   // Move the temporary pointer to the newly added node.
        count++;          /// Increment the count of nodes.
    }

    return count;
}

/**
 * @brief Checks if a singly linked list is a palindrome.
 * 
 * A palindrome is a sequence that reads the same forward and backward.
 * The function compares the data in the linked list by copying it into an array
 * and verifying if the array is symmetric.
 * 
 * @param head Pointer to the head of the list.
 * @param count The total number of nodes in the list.
 * @return 1 if the list is a palindrome, 0 otherwise.
 */
int palin_check(struct node* head, int count) {
    if (!head || count == 1) return 1; // An empty or single-node list is already a palindrome.

    // Allocate memory for an array to store list elements.
    int* arr = (int*)malloc(count * sizeof(int));
    struct node* temp = head;

    // Copy the linked list elements into the array.
    for (int i = 0; i < count; i++) {
        arr[i] = temp->num;
        temp = temp->next;
    }

    // Check if the array is palindrome
    for (int i = 0; i < count / 2; i++) {
        if (arr[i] != arr[count - i - 1]) {
            free(arr);     // Free allocated memory before returning.
            return 0;      // Not a palindrome.
        }
    }

    free(arr);             // Free allocated memory.
    return 1;              // The list is a palindrome.
}

/**
 * @brief The main function to demonstrate creating and checking a singly linked list for being a palindrome.
 * 
 * @return Returns 0 on successful execution.
 */
int main() {
    struct node* p = NULL; // Pointer to the head of the singly linked list.
    int result, count;

    printf("Enter data into the list:\n");
    count = create(&p);    //Create the list and get its size.

    result = palin_check(p, count); //Ccheck if the list is a palindrome.

    if (result == 1)
        printf("The linked list is a palindrome.\n");
    else
        printf("The linked list is not a palindrome.\n");

    return 0;
}
