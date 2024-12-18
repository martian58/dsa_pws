/**
 * Filename:    tasks.c
 * Author:      Fuad Alizada
 * Purpose:     Functions for Practical Work 8 Tasks are implmented herer.
 */

#include <stdio.h>
#include <stdlib.h>
#include "tasks.h"


// Hover over the functions to see their docstrings


Node* create_node(int data) {
    // Allocate memory for the new node
    Node* new_node = (Node*)malloc(sizeof(Node));
    // Set the data and initialize the next pointer to NULL
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}


void append_linked_list(Node** head, int data) {
    // Create the new node to be appended
    Node* new_node = create_node(data);
    
    // If the list is empty, new node is the head
    if (!(*head)) {
        *head = new_node;
        return;
    }

    // Traverse the list to find the last node
    Node* temp = *head;
    while (temp->next) {
        temp = temp->next;
    }

    // Link the last node to the new node
    temp->next = new_node;
}


void front_back_split(Node* source, Node** front, Node** back) {
    // If the list is empty or has only one node, assign it to the front
    if (!source || !source->next) {
        *front = source;
        *back = NULL;
        return;
    }

    // Uuse two pointers to find the midpoint of the list
    Node *slow = source, *fast = source->next;
    while (fast && fast->next) {
        slow = slow->next; // Slow pointer moves one step per iteration
        fast = fast->next->next; // Fast pointer moves two steps per iter..
    }

    // Split the list into two halves
    *front = source;
    *back = slow->next;
    slow->next = NULL;
}


Node* sorted_merge(Node* a, Node* b) {
    // if one list is empty, return the other
    if (!a) return b;
    if (!b) return a;

    Node* result;

    // Compare the data in the nodes and merge accoridngly
    if (a->data <= b->data) {
        result = a;
        result->next = sorted_merge(a->next, b);
    } else {
        result = b;
        result->next = sorted_merge(a, b->next);
    }

    return result;
}


Node* merge_sort(Node* head) {
    // if the list is empty or has one node, it is sorted
    if (!head || !head->next) return head;

    Node *front, *back;

    // Split the list into two halves
    front_back_split(head, &front, &back);

    // Recursively sort each half
    front = merge_sort(front);
    back = merge_sort(back);

    // Merge the two sorted halves
    return sorted_merge(front, back);
}


void remove_duplicates(Node* head) {
    Node* current = head;

    // Traverse the list
    while (current && current->next) {
        // If the current node and the next node have the same data
        if (current->data == current->next->data) {
            // Remove the duplicate node
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            // Move to the next node
            current = current->next;
        }
    }
}


Node* reverse_list_iterative(Node* head) {
    Node *prev = NULL, *current = head, *next = NULL;

    // Iterate thrugh the list
    while (current) {
        // Save the next node
        next = current->next;
        
        // Reverse the current node's pointer
        current->next = prev;
        
        // Move the pointers one step forward
        prev = current;
        current = next;
    }

    // Return the new head (previous node)
    return prev;
}


Node* reverse_list_recursive(Node* head) {
    // if the list is empty or has one node, return it
    if (!head || !head->next) return head;

    // Reverse the rest of the list
    Node* new_head = reverse_list_recursive(head->next);

    // Adjust the pointers
    head->next->next = head;
    head->next = NULL;

    return new_head;
}


void print_list(Node* head) {
    // Traverse the list and print each node's data
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


void free_list(Node* head) {
    // Traverse the list and free each node
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}
