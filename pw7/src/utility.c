#include "utility.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isOpeningBracket(char ch) {
// Check if the character is an opening bracket: (, {, or [
    return ch == '(' || ch == '{' || ch == '['; 
}

bool isClosingBracket(char ch) {
// Check if the character is a closing bracket: ), }, or ]
    return ch == ')' || ch == '}' || ch == ']';
}

bool isMatchingPair(char opening, char closing) {
// Verify if the opening and closing brackets are a matching pair
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

bool isBalanced(const char *expression) {
// Check if the brackets in the given expression are balanced
    int length = strlen(expression); // Get the length of the expression
    Stack stack = createStack(length); // Create a stack with a size equal to the expression length

    for (int i = 0; i < length; i++) { 
        char ch = expression[i];

        if (isOpeningBracket(ch)) { 
            push(&stack, ch); // Push opening brackets into the stack
        } else if (isClosingBracket(ch)) { 
            int top;
            // Pop the stack and check if the pair is not matching or the stack is empty
            if (!pop(&stack, &top) || !isMatchingPair(top, ch)) { 
                freeStack(&stack); 
                return false; // Unbalanced brackets found
            }
        }
    }

    // If the stack is empty, the brackets are balanced
    bool balanced = stack.top == -1; 
    freeStack(&stack); // Free the stack
    return balanced;
}

void nextGreaterElement(int *arr, int size, int *result) {
// Find the next greater element for each element in the array
    Stack stack = createStack(size); 

    // Traverse the array from `right `to `left`
    for (int i = size - 1; i >= 0; i--) {
        // Remove elements from the stack that are less than or equal to the current element
        while (stack.top != -1 && stack.data[stack.top] <= arr[i]) {
            int discarded;
            pop(&stack, &discarded); // Pop the smaller elements
        }

        // If the stack is empty, there's no greater element
        if (stack.top == -1) {
            result[i] = -1; 
        } else {
            result[i] = stack.data[stack.top]; // The top of the stack is the next greater element
        }

        push(&stack, arr[i]); // Push the current element nito the stack
    }

    freeStack(&stack); // Free the stack
}
