/**
 * Filename:    tasks.c
 * Author:      Fuad Alizada 
 * Purpose:     Functions for Practical Work 9.
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/tasks.h"


// Hover over the functions to see their docstrings



// *** Doubly Linked List for Integers (DLListInt) ***

DLListInt createDLListInt() {
    DLListInt list = {NULL, NULL};
    return list;
}


void addToDLListInt(DLListInt* list, int value) {
    NodeInt* newNode = (NodeInt*)malloc(sizeof(NodeInt)); // Allocate memory for the new node
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = list->tail;

    if (list->tail) // If the list is not empty adjust the pointers
        list->tail->next = newNode;
    else // If the list is empty, set the head to the new node
        list->head = newNode;

    list->tail = newNode; // Update the tail to the new node
}


int findMaxDLListInt(DLListInt list) {
    if (!list.head) return -1; // Case empty list

    int max = list.head->data; // Initialize max with the first node's data
    for (NodeInt* curr = list.head; curr; curr = curr->next) {
        if (curr->data > max) // Update max if the current node's data is larger
            max = curr->data;
    }
    return max;
}


int findMinDLListInt(DLListInt list) {
    if (!list.head) return -1; // empty list case

    int min = list.head->data; // Initialize min with the first node's data
    for (NodeInt* curr = list.head; curr; curr = curr->next) {
        if (curr->data < min) // Update min if the current node's data is smaller
            min = curr->data;
    }
    return min;
}


void printDLListInt(DLListInt list) {
    NodeInt* current = list.head;
    printf("Doubly Linked List (Int): ");
    while (current) {
        printf("%d <-> ", current->data); // Print current node's data
        current = current->next; // Move to the next node
    }
    printf("NULL\n");
}


DLListChar createDLListChar() {
    DLListChar list = {NULL, NULL};
    return list;
}


void addToDLListChar(DLListChar* list, char value) {
    NodeChar* newNode = (NodeChar*)malloc(sizeof(NodeChar)); //Allocate memory for the new node
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = list->tail;

    if (list->tail) // If the list is not empty, adjust the pointers
        list->tail->next = newNode;
    else // If the list is empty, set the head to the new node
        list->head = newNode;

    list->tail = newNode; // Update the tail to the new node
}


int isPalindromeDLListChar(DLListChar list) {
    NodeChar* left = list.head;
    NodeChar* right = list.tail;

    // Compare characters from both ends of the list
    while (left && right && left != right && left->prev != right) {
        if (left->data != right->data) // If mis-match is found, its not a palindrome
            return 0;
        left = left->next; // Move left pointer forward
        right = right->prev; // Move right pointer backward
    }
    return 1; // the list is a palindrome
}


void printDLListChar(DLListChar list) {
    NodeChar* current = list.head;
    printf("Doubly Linked List (Char): ");
    while (current) {
        printf("%c <-> ", current->data); // Print current node's data
        current = current->next; // Move to the next node
    }
    printf("NULL\n");
}

// *** Circular Singly Linked List (CLList) ***


CLList createCLList() {
    CLList list = {NULL};
    return list;
}


void addToCLList(CLList* list, int value) {
    CNode* newNode = (CNode*)malloc(sizeof(CNode)); // Allocate memory for the new node....
    newNode->data = value;
    if (!list->head) { // If the list is empty, initialize it
        list->head = newNode;
        newNode->next = newNode; // Point to itself to make it circular
    } else {
        CNode* temp = list->head;
        while (temp->next != list->head) // Traverse to the last node
            temp = temp->next;

        temp->next = newNode; // Add the new node to the end
        newNode->next = list->head; // Maintain circular property
    }
}


void reverseCLList(CLList* list) {
    if (!list->head) return; // empty list 

    CNode* prev = NULL;
    CNode* current = list->head;
    CNode* next = NULL;
    CNode* tail = list->head;

    do {
        next = current->next; // Save the next node
        current->next = prev; // Reverse the current node's pointer
        prev = current; // Move prev forward
        current = next; // Move current forward
    } while (current != list->head);

    tail->next = prev; // Update the last node's pointer to the new head
    list->head = prev; // Update the head to the last node
}


void printCLList(CLList list) {
    if (!list.head) {
        printf("Circular Linked List: Empty\n");
        return;
    }

    CNode* current = list.head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", current->data); // Print current node's data
        current = current->next; // Move to the next node
    } while (current != list.head); // Stop when we reach the head again
    printf("(Head)\n");
}
