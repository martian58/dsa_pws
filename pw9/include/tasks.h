#ifndef TASKS_H
#define TASKS_H

// Node structure for Doubly Linked List with Integers
typedef struct NodeInt {
    int data;
    struct NodeInt* next;
    struct NodeInt* prev;
} NodeInt;

// Node structure for Doubly Linked List with Characters
typedef struct NodeChar {
    char data;
    struct NodeChar* next;
    struct NodeChar* prev;
} NodeChar;

// Doubly Linked List for Integers
typedef struct {
    NodeInt* head;
    NodeInt* tail;
} DLListInt;

// Doubly Linked List for Characters
typedef struct {
    NodeChar* head;
    NodeChar* tail;
} DLListChar;

// Node structure for Circular Singly Linked List
typedef struct CNode {
    int data;
    struct CNode* next;
} CNode;

// Circular Singly Linked List
typedef struct {
    CNode* head;
} CLList;

// Function prototypes for DLListInt

/**
 * @brief Creates an empty doubly linked list for integers.
 * @return An initialized DLListInt structure.
 */
DLListInt createDLListInt();


/**
 * @brief Adds a new integer value to the end of the doubly linked list.
 * @param list Pointer to the DLListInt where the value will be added.
 * @param value The integer value to add to the list.
 */
void addToDLListInt(DLListInt* list, int value);

/**
 * @brief Finds the maximum value in the doubly linked list.
 * @param list The DLListInt to search.
 * @return The maximum value, or -1 if the list is empty.
 */
int findMaxDLListInt(DLListInt list);


/**
 * @brief Finds the minimum value in the doubly linked list.
 * @param list The DLListInt to search.
 * @return The minimum value, or -1 if the list is empty.
 */
int findMinDLListInt(DLListInt list);

/**
 * @brief Prints all elements of the doubly linked list of integers.
 * @param list The DLListInt to print.
 */
void printDLListInt(DLListInt list);



// Function prototypes for DLListChar


// *** Doubly Linked List for Characters (DLListChar) ***

/**
 * @brief Creates an empty doubly linked list for characters.
 * @return An initialized DLListChar structure.
 */
DLListChar createDLListChar();


/**
 * @brief Adds a new character value to the end of the doubly linked list.
 * @param list Pointer to the DLListChar where the value will be added.
 * @param value The character value to add to the list.
 */
void addToDLListChar(DLListChar* list, char value);


/**
 * @brief Checks if the doubly linked list of characters is a palindrome.
 * @param list The DLListChar to check.
 * @return 1 if the list is a palindrome, 0 otherwise.
 */
int isPalindromeDLListChar(DLListChar list);


/**
 * @brief Prints all elements of the doubly linked list of characters.
 * @param list The DLListChar to print.
 */
void printDLListChar(DLListChar list);



// Function prototypes for CLList


/**
 * @brief Creates an empty circular singly linked list.
 * @return An initialized CLList structure.
 */
CLList createCLList();


/**
 * @brief Adds a new integer value to the circular singly linked list.
 * @param list Pointer to the CLList where the value will be added.
 * @param value The integer value to add to the list.
 */
void addToCLList(CLList* list, int value);


/**
 * @brief Reverses the circular singly linked list.
 * @param list Pointer to the CLList to reverse.
 */
void reverseCLList(CLList* list);


/**
 * @brief Prints all elements of the circular singly linked list.
 * @param list The CLList to print.
 */
void printCLList(CLList list);

#endif
