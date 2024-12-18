/**
 * Filename:    main.c
 * Author:      Fuad Alizada 
 * Purpose:     Main file for Practical Work 9.
 */


#include <stdio.h>
#include "../include/tasks.h"

int main() {
    // Exercise 1: DLListInt
    DLListInt intList = createDLListInt();
    addToDLListInt(&intList, 10);
    addToDLListInt(&intList, 20);
    addToDLListInt(&intList, 15);
    printDLListInt(intList);
    printf("Max: %d\n", findMaxDLListInt(intList));
    printf("Min: %d\n", findMinDLListInt(intList));

    // Exercise 2: DLListChar
    DLListChar charList = createDLListChar();
    addToDLListChar(&charList, 'r');
    addToDLListChar(&charList, 'a');
    addToDLListChar(&charList, 'c');
    addToDLListChar(&charList, 'e');
    addToDLListChar(&charList, 'c');
    addToDLListChar(&charList, 'a');
    addToDLListChar(&charList, 'r');
    printDLListChar(charList);
    printf("Is Palindrome: %s\n", isPalindromeDLListChar(charList) ? "Yes" : "No");

    // Exercise 3: CLList
    CLList circularList = createCLList();
    addToCLList(&circularList, 1);
    addToCLList(&circularList, 2);
    addToCLList(&circularList, 3);
    printCLList(circularList);
    reverseCLList(&circularList);
    printCLList(circularList);

    return 0;
}
