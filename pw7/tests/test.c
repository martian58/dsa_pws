/**
 * Filename:    test.c
 * Author:      Fuad Alizada
 * Purpose:     Test utility functions for PW 7 exercises.
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "stack.h"
#include "queue.h"
#include "utility.h"

int main() {
    printf("Running tests...\n");

    // Test 1: Stack Operations
    Stack stack = createStack(5);
    assert(push(&stack, 10) == true);
    assert(push(&stack, 20) == true);
    assert(push(&stack, 30) == true);
    int value;
    assert(pop(&stack, &value) == true && value == 30);
    assert(pop(&stack, &value) == true && value == 20);
    assert(pop(&stack, &value) == true && value == 10);
    assert(pop(&stack, &value) == false); // Stack underflow
    freeStack(&stack);
    printf("Test 1: Stack Operations passed ✅\n");

    // Test 2: Queue Operations
    Queue queue = createQueue(5);
    assert(enqueue(&queue, 10) == true);
    assert(enqueue(&queue, 20) == true);
    assert(enqueue(&queue, 30) == true);
    assert(dequeue(&queue, &value) == true && value == 10);
    assert(dequeue(&queue, &value) == true && value == 20);
    assert(dequeue(&queue, &value) == true && value == 30);
    assert(dequeue(&queue, &value) == false); // Queue underflow
    freeQueue(&queue);
    printf("Test 2: Queue Operations passed ✅\n");

    // Test 3: Balanced Parentheses
    assert(isBalanced("()") == true);
    assert(isBalanced("({[]})") == true);
    assert(isBalanced("({[)]}") == false);
    assert(isBalanced("(") == false);
    assert(isBalanced(")") == false);
    printf("Test 3: Balanced Parentheses passed ✅\n");

    // Test 4: Next Greater Element
    int arr[] = {4, 5, 2, 10, 8};
    int result[5];
    nextGreaterElement(arr, 5, result);
    assert(result[0] == 5);
    assert(result[1] == 10);
    assert(result[2] == 10);
    assert(result[3] == -1);
    assert(result[4] == -1);
    printf("Test 4: Next Greater Element passed ✅\n");

    printf("All tests passed successfully! 👍👍\n\n");
    printf("Type './main' to run the main program!\n");
    return 0;
}
