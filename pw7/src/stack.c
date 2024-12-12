#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

Stack createStack(int capacity) {
    Stack stack;
    stack.data = (int *)malloc(sizeof(int) * capacity); // Allocate memory
    stack.top = -1; // Initialize the top to -1
    stack.capacity = capacity; 
    return stack; 
}

bool push(Stack *stack, int value) {
    if (stack->top == stack->capacity - 1) { // Check if the stack is full.
        printf("Stack Overflow\n"); 
        return false; 
    }
    stack->data[++stack->top] = value; // Increment the top index and store the value.
    return true; 
}

bool pop(Stack *stack, int *value) {
    if (stack->top == -1) { // Check if the stack is empty.
        printf("Stack Underflow\n"); 
        return false; 
    }
    *value = stack->data[stack->top--]; 
    return true; 
}

void freeStack(Stack *stack) {
    free(stack->data); // Free the memory 
    stack->data = NULL; 
    stack->top = -1; 
    stack->capacity = 0; 
}

void printStack(const Stack *stack) {
    if (stack->top == -1) { // Check if the stack is empty.
        printf("Stack is empty.\n");
        return; 
    }

    printf("Stack (top to bottom): "); 
    for (int i = stack->top; i >= 0; i--) { // Iterate from the top to the bottom of the stack.
        printf("%d ", stack->data[i]); // Print each element.
    }
    printf("\n");
}
