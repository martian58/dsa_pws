#ifndef TASKS_H
#define TASKS_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Task Functions

/**
 * @brief Creates a new node with the given data.
 * @param data The data to store in the new node.
 * @return A pointer to the newly created node.
 */
Node* create_node(int data);

/**
 * @brief Appends a new node with the given data to the end of the linked list.
 * @param head A pointer to the head of the list.
 * @param data The data to append to the list.
 */
void append_linked_list(Node** head, int data);

/**
 * @brief Splits a linked list into two halves.
 * @param source The original list to split.
 * @param front A pointer to store the first half of the list.
 * @param back A pointer to store the second half of the list.
 */
void front_back_split(Node* source, Node** front, Node** back);

/**
 * @brief Merges two sorted linked lists into one sorted list.
 * @param a The first sorted list.
 * @param b The second sorted list.
 * @return The merged sorted list.
 */
Node* sorted_merge(Node* a, Node* b);

/**
 * @brief Sorts a linked list using the Merge Sort algorithm.
 * @param head The head of the list to sort.
 * @return The sorted linked list.
 */
Node* merge_sort(Node* head);

/**
 * @brief Removes duplicate nodes from a sorted linked list.
 * @param head The head of the sorted list.
 */
void remove_duplicates(Node* head);

/**
 * @brief Reverses a linked list iteratively.
 * @param head The head of the list to reverse.
 * @return The new head of the reversed list.
 */
Node* reverse_list_iterative(Node* head);

/**
 * @brief Reverses a linked list recursively.
 * @param head The head of the list to reverse.
 * @return The new head of the reversed list.
 */
Node* reverse_list_recursive(Node* head);


/**
 * @brief Prints the elements of the linked list.
 * @param head The head of the list to print.
 */
void print_list(Node* head);

/**
 * @brief Frees the memory allocated for the linked list.
 * @param head The head of the list to free.
 */
void free_list(Node* head);

#endif 
