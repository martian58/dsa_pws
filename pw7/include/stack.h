#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;

/**
 * @brief Creates a new stack with a given capacity.
 * 
 * @param capacity The maximum number of elements the stack can hold.
 * @return A Stack object initialized with the specified capacity.
 */
Stack createStack(int capacity);

/**
 * @brief Pushes an element onto the stack.
 * 
 * @param stack Pointer to the Stack object.
 * @param value The value to push onto the stack.
 * @return true if the value was successfully pushed, false if the stack is full.
 */
bool push(Stack *stack, int value);

/**
 * @brief Pops an element from the stack.
 * 
 * @param stack Pointer to the Stack object.
 * @param value Pointer to store the popped value.
 * @return true if a value was successfully popped, false if the stack is empty.
 */
bool pop(Stack *stack, int *value);

/**
 * @brief Frees the resources used by the stack.
 * 
 * @param stack Pointer to the Stack object.
 */
void freeStack(Stack *stack);


/**
 * @brief Prints the elements in the stack from top to bottom.
 * 
 * @param stack Pointer to the Stack object.
 */
void printStack(const Stack *stack);

#endif // STACK_H
